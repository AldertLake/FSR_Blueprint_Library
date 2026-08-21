// -----------------------------------------------------
// Copyright   (c) 2025 AldertLake. All Rights Reserved.
// GitHub:     https://github.com/AldertLake/
// Discord:    https://discord.gg/QpPPfh6WVn
// -----------------------------------------------------

#include "FSRFGLibrary.h"
#include "FSRHelpers.h"
#include "FSRSettings.h"

const FString UFSRFGLibrary::FSR4Section = TEXT("SystemSettings");

bool IsFSRFGSupported()
{
	if (const UFSRSettings* Settings = GetDefault<UFSRSettings>())
	{
		return Settings->FSRCompatibility != EFSRVersionCompatibility::FSR2;
	}
	return true;
}

void UFSRFGLibrary::SetFSRFGMode(EFSRFrameGenerationMode Mode)
{
	if (!IsFSRFGSupported()) return;

	if (Mode == EFSRFrameGenerationMode::Enabled)
	{
		if (const UFSRSettings* Settings = GetDefault<UFSRSettings>())
		{
			if (Settings->FSRCompatibility == EFSRVersionCompatibility::FSR3)
			{
				// FSR 3 Frame Generation requires Upscaling. Force enable it.
				UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FSR3.Enabled"), 1, FSR4Section);
			}
		}
	}

	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FI.Enabled"), (int32)Mode, FSR4Section);
}

EFSRFrameGenerationMode UFSRFGLibrary::GetFSRFGCurrentMode()
{
	if (!IsFSRFGSupported()) return EFSRFrameGenerationMode::Disabled;
	return (EFSRFrameGenerationMode)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FI.Enabled"));
}

void UFSRFGLibrary::SetFSRFGUIRenderMode(EFSRUIMode Mode)
{
	if (!IsFSRFGSupported()) return;
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FI.UIMode"), (int32)Mode, FSR4Section);
}

EFSRUIMode UFSRFGLibrary::GetFSRFGUIRenderMode()
{
	if (!IsFSRFGSupported()) return (EFSRUIMode)0;
	return (EFSRUIMode)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FI.UIMode"));
}

void UFSRFGLibrary::ShowFSRFGDebugView(bool bShow)
{
#if WITH_EDITOR
	if (!IsFSRFGSupported()) return;
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.FidelityFX.FI.ShowDebugView")))
	{
		CVar->Set(bShow ? 1 : 0, ECVF_SetByGameSetting);
	}
#endif
}

void UFSRFGLibrary::ShowFSRFGDebugTearLines(bool bShow)
{
#if WITH_EDITOR
	if (!IsFSRFGSupported()) return;
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.FidelityFX.FI.ShowDebugTearLines")))
	{
		CVar->Set(bShow ? 1 : 0, ECVF_SetByGameSetting);
	}
#endif
}

void UFSRFGLibrary::ShowFSRFGCaptureDebugUI(bool bCapture)
{
#if WITH_EDITOR
	if (!IsFSRFGSupported()) return;
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.FidelityFX.FI.CaptureDebugUI")))
	{
		CVar->Set(bCapture ? 1 : 0, ECVF_SetByGameSetting);
	}
#endif
}

void UFSRFGLibrary::SetFSRFGAsyncPresent(EFSRSwapChainMode Mode)
{
	if (!IsFSRFGSupported()) return;
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FI.OverrideSwapChainDX12"), (int32)Mode, FSR4Section);
}

EFSRSwapChainMode UFSRFGLibrary::GetFSRFGAsyncPresent()
{
	if (!IsFSRFGSupported()) return (EFSRSwapChainMode)0;
	return (EFSRSwapChainMode)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FI.OverrideSwapChainDX12"));
}