// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#include "FSRFGLibrary.h"
#include "FSRHelpers.h"

const FString UFSRFGLibrary::FSR4Section = TEXT("SystemSettings");

void UFSRFGLibrary::SetFSRFGMode(EFSRFrameGenerationMode Mode)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FI.Enabled"), (int32)Mode, FSR4Section);
}

EFSRFrameGenerationMode UFSRFGLibrary::GetFSRFGCurrentMode()
{
	return (EFSRFrameGenerationMode)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FI.Enabled"));
}

void UFSRFGLibrary::SetFSRFGUIRenderMode(EFSRUIMode Mode)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FI.UIMode"), (int32)Mode, FSR4Section);
}

EFSRUIMode UFSRFGLibrary::GetFSRFGUIRenderMode()
{
	return (EFSRUIMode)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FI.UIMode"));
}

void UFSRFGLibrary::ShowFSRFGDebugView(bool bShow)
{
#if WITH_EDITOR
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.FidelityFX.FI.ShowDebugView")))
	{
		CVar->Set(bShow ? 1 : 0, ECVF_SetByGameSetting);
	}
#endif
}

void UFSRFGLibrary::ShowFSRFGDebugTearLines(bool bShow)
{
#if WITH_EDITOR
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.FidelityFX.FI.ShowDebugTearLines")))
	{
		CVar->Set(bShow ? 1 : 0, ECVF_SetByGameSetting);
	}
#endif
}

void UFSRFGLibrary::ShowFSRFGCaptureDebugUI(bool bCapture)
{
#if WITH_EDITOR
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.FidelityFX.FI.CaptureDebugUI")))
	{
		CVar->Set(bCapture ? 1 : 0, ECVF_SetByGameSetting);
	}
#endif
}

void UFSRFGLibrary::SetFSRFGAsyncPresent(EFSRSwapChainMode Mode)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FI.OverrideSwapChainDX12"), (int32)Mode, FSR4Section);
}

EFSRSwapChainMode UFSRFGLibrary::GetFSRFGAsyncPresent()
{
	return (EFSRSwapChainMode)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FI.OverrideSwapChainDX12"));
}