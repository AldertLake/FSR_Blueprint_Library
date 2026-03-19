// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#include "FSRExtra.h"
#include "Misc/CommandLine.h"
#include "Misc/App.h"
#include "HAL/PlatformProcess.h"
#include "Misc/CoreDelegates.h"
#include "Misc/ConfigCacheIni.h"
#include "Logging/LogMacros.h"

EFSRActiveRHI UFSRExtra::GetCurrentActiveRHI()
{
    FString RHIName = FApp::GetGraphicsRHI();

    if (RHIName.Contains(TEXT("DirectX 12")) || RHIName.Contains(TEXT("D3D12")))
    {
        return EFSRActiveRHI::DirectX12;
    }
    else if (RHIName.Contains(TEXT("DirectX 11")) || RHIName.Contains(TEXT("D3D11")))
    {
        return EFSRActiveRHI::DirectX11;
    }
    else if (RHIName.Contains(TEXT("Vulkan")))
    {
        return EFSRActiveRHI::Vulkan;
    }
    else if (RHIName.Contains(TEXT("OpenGL")))
    {
        return EFSRActiveRHI::OpenGL;
    }

    return EFSRActiveRHI::Unknown;
}

void UFSRExtra::RestartGameWithCommandLine(const FString& ExtraCommandLine, bool bOverrideExistingLaunchArgs)
{
#if !WITH_EDITOR && PLATFORM_DESKTOP

	const FString RestartSentinel = TEXT("--restarted");

	FString FinalCommandLine = bOverrideExistingLaunchArgs
		? ExtraCommandLine
		: FString(FCommandLine::Get());

	FinalCommandLine.ReplaceInline(*RestartSentinel, TEXT(""), ESearchCase::IgnoreCase);

	if (!bOverrideExistingLaunchArgs && !ExtraCommandLine.IsEmpty())
	{
		if (!FinalCommandLine.IsEmpty() && !FinalCommandLine.EndsWith(TEXT(" ")))
		{
			FinalCommandLine += TEXT(" ");
		}
		FinalCommandLine += ExtraCommandLine;
	}

	FinalCommandLine.ReplaceInline(TEXT("\r"), TEXT(" "));
	FinalCommandLine.ReplaceInline(TEXT("\n"), TEXT(" "));
	FinalCommandLine.ReplaceInline(TEXT("\t"), TEXT(" "));
	FinalCommandLine.TrimStartAndEndInline();

	if (FinalCommandLine.Contains(RestartSentinel, ESearchCase::IgnoreCase))
	{
		UE_LOG(LogTemp, Warning, TEXT("Restart aborted: restart sentinel already present."));
		return;
	}

	if (!FinalCommandLine.IsEmpty())
	{
		FinalCommandLine += TEXT(" ");
	}
	FinalCommandLine += RestartSentinel;

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
		*FinalCommandLine,
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

	UE_LOG(LogTemp, Log, TEXT("Restart spawned successfully: %s %s"), *ExePath, *FinalCommandLine);

	FPlatformProcess::CloseProc(ProcHandle);

	if (FCoreDelegates::OnPreExit.IsBound())
	{
		FCoreDelegates::OnPreExit.Broadcast();
	}

	FPlatformMisc::RequestExit(false);

#else
	UE_LOG(LogTemp, Warning, TEXT("RestartGameWithCommandLine is disabled in editor or non-desktop builds."));
#endif
}