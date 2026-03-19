// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#include "FSRMobileLibrary.h"
#include "FSRHelpers.h"

const FString UFSRMobileLibrary::MobileSection = TEXT("SystemSettings");

void UFSRMobileLibrary::EnableFSRMobile(bool bEnable)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.Mobile.FSR.Enabled"), bEnable ? 1 : 0, MobileSection);
}

bool UFSRMobileLibrary::IsFSRMobileEnabled()
{
	return UFSRHelpers::GetCVarInt(TEXT("r.Mobile.FSR.Enabled")) != 0;
}

void UFSRMobileLibrary::SetFSRMobileSharpness(float Sharpness)
{
	const int32 bEnable = (Sharpness > 0.0f) ? 1 : 0;

	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.Mobile.FSR.RCAS.enabled"), bEnable, MobileSection);
	UFSRHelpers::SetAndSaveCVarFloat(TEXT("r.Mobile.FSR.RCAS.Sharpness"), Sharpness, MobileSection);
}

float UFSRMobileLibrary::GetFSRMobileSharpness()
{
	return UFSRHelpers::GetCVarFloat(TEXT("r.Mobile.FSR.RCAS.enabled"));
}

void UFSRMobileLibrary::EnableFSRMobileDenoise(bool bEnable)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.Mobile.FSR.RCAS.Denoise"), bEnable ? 1 : 0, MobileSection);
}

bool UFSRMobileLibrary::IsFSRMobileDenoiseEnabled()
{
	return UFSRHelpers::GetCVarInt(TEXT("r.Mobile.FSR.RCAS.Denoise")) != 0;
}

void UFSRMobileLibrary::DisableFSRMobileCompute(bool bDisable)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.Mobile.FSR.DisableCompute"), bDisable ? 1 : 0, MobileSection);
}

bool UFSRMobileLibrary::IsFSRMobileComputeModeDisabled()
{
	return UFSRHelpers::GetCVarInt(TEXT("r.Mobile.FSR.DisableCompute")) != 0;
}

void UFSRMobileLibrary::EnableUpsamplingForFSRMobile(bool bEnable)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.Mobile.FSR.Upsampling.enabled"), bEnable ? 1 : 0, MobileSection);
}

bool UFSRMobileLibrary::CheckFSRMobileUpsampling()
{
	return UFSRHelpers::GetCVarInt(TEXT("r.Mobile.FSR.Upsampling.enabled")) != 0;
}