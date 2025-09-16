// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Support:  https://ko-fi.com/aldertlake
// ---------------------------------------------------

#include "RestartGame.h"
#include "Misc/CommandLine.h"
#include "HardwareInfo.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "Misc/CoreDelegates.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/ScopeLock.h"
#include "Logging/LogMacros.h"

FString URestartGame::GetRHIName()
{
    FString RHI_Info = FHardwareInfo::GetHardwareInfo(NAME_RHI);
    int32 SpacePos = RHI_Info.Find(TEXT(" "));
    if (SpacePos != INDEX_NONE)
    {
        return RHI_Info.Left(SpacePos);
    }
    return RHI_Info.IsEmpty() ? FString(TEXT("Unknown")) : RHI_Info;
}


void URestartGame::RestartGameWithCommandLine(const FString& ExtraCommandLine)
{
    const FString RestartSentinel = TEXT("--restarted");

    if (ExtraCommandLine.Contains(RestartSentinel, ESearchCase::IgnoreCase) ||
        FString(FCommandLine::Get()).Contains(RestartSentinel, ESearchCase::IgnoreCase))
    {
        UE_LOG(LogTemp, Warning, TEXT("Restart aborted: restart sentinel already present."));
        return;
    }

    FString Sanitized;
    Sanitized.Reserve(ExtraCommandLine.Len());
    for (TCHAR C : ExtraCommandLine)
    {
        if (FChar::IsAlpha(C) || FChar::IsDigit(C) ||
            C == TEXT(' ') || C == TEXT('-') || C == TEXT('_') ||
            C == TEXT('=') || C == TEXT(':') || C == TEXT('/') ||
            C == TEXT('\\') || C == TEXT('.') || C == TEXT(','))
        {
            Sanitized.AppendChar(C);
        }
        else
        {
            Sanitized.AppendChar(TEXT(' '));
        }
    }

    FString CmdLine = Sanitized;
    if (!CmdLine.IsEmpty())
    {
        CmdLine.TrimEndInline();
        CmdLine += TEXT(" ");
    }
    CmdLine += RestartSentinel;

    FCoreDelegates::OnPreExit.Broadcast();
    if (GConfig)
    {
        GConfig->Flush(false, GEngineIni);
    }

    const FString ExePath = FPlatformProcess::ExecutablePath();
    if (ExePath.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("Restart aborted: cannot determine executable path."));
        return;
    }

    FProcHandle ProcHandle = FPlatformProcess::CreateProc(
        *ExePath,
        *CmdLine,
        true,
        false,
        false,
        nullptr,
        0,
        nullptr,
        nullptr
    );

    if (!ProcHandle.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("Restart failed: CreateProc returned invalid handle."));
        return;
    }

    const double StartTime = FPlatformTime::Seconds();
    const double TimeoutSeconds = 5.0;
    bool bChildRunning = false;

    while ((FPlatformTime::Seconds() - StartTime) < TimeoutSeconds)
    {
        if (FPlatformProcess::IsProcRunning(ProcHandle))
        {
            bChildRunning = true;
            break;
        }
        FPlatformProcess::Sleep(0.05f);
    }

    if (bChildRunning)
    {
        UE_LOG(LogTemp, Log, TEXT("Restart successful: spawned child process, exiting gracefully."));
        FPlatformProcess::CloseProc(ProcHandle);
        FPlatformMisc::RequestExit(true);
        return;
    }

    int32 ReturnCode = 0;
    bool bHasReturn = FPlatformProcess::GetProcReturnCode(ProcHandle, &ReturnCode);
    if (bHasReturn)
    {
        UE_LOG(LogTemp, Error, TEXT("Restart failed: child exited immediately with code %d."), ReturnCode);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Restart failed: child not running after %.1f seconds (timeout)."), TimeoutSeconds);
    }
    FPlatformProcess::CloseProc(ProcHandle);
}