// -----------------------------------------------------
// Copyright   (c) 2025 AldertLake. All Rights Reserved.
// GitHub:     https://github.com/AldertLake/
// Discord:    https://discord.gg/QpPPfh6WVn
// -----------------------------------------------------

#include "FSRLibrary.h"
#include "FSRHelpers.h"
#include "FSRSettings.h"

const FString UFSRLibrary::FSR4Section = TEXT("SystemSettings");

FString GetFSRBaseString()
{
	if (const UFSRSettings* Settings = GetDefault<UFSRSettings>())
	{
		if (Settings->FSRCompatibility == EFSRVersionCompatibility::FSR2)
		{
			return TEXT("r.FidelityFX.FSR2.");
		}
		else if (Settings->FSRCompatibility == EFSRVersionCompatibility::FSR3)
		{
			return TEXT("r.FidelityFX.FSR3.");
		}
	}
	return TEXT("r.FidelityFX.FSR.");
}

void UFSRLibrary::EnableFSR(bool bEnable)
{
	if (!bEnable)
	{
		if (const UFSRSettings* Settings = GetDefault<UFSRSettings>())
		{
			if (Settings->FSRCompatibility == EFSRVersionCompatibility::FSR3)
			{
				// FSR 3 Frame Generation cannot run without Upscaling. Force disable it.
				UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FI.Enabled"), 0, FSR4Section);
			}
		}
	}
	UFSRHelpers::SetAndSaveCVarInt(GetFSRBaseString() + TEXT("Enabled"), bEnable ? 1 : 0, FSR4Section);
}

bool UFSRLibrary::IsFSREnabled()
{
	return UFSRHelpers::GetCVarInt(GetFSRBaseString() + TEXT("Enabled")) != 0;
}

void UFSRLibrary::SetFSRQualityMode(EFSRQualityMode Mode)
{
	if (const UFSRSettings* Settings = GetDefault<UFSRSettings>())
	{
		if (Settings->FSRCompatibility == EFSRVersionCompatibility::FSR2 && Mode == EFSRQualityMode::NativeAA)
		{
			Mode = EFSRQualityMode::Quality;
		}
	}
	UFSRHelpers::SetAndSaveCVarInt(GetFSRBaseString() + TEXT("QualityMode"), (int32)Mode, FSR4Section);
}

EFSRQualityMode UFSRLibrary::GetFSRQualityMode()
{
	return (EFSRQualityMode)UFSRHelpers::GetCVarInt(GetFSRBaseString() + TEXT("QualityMode"));
}

void UFSRLibrary::SetFSRSharpness(float Sharpness)
{
	UFSRHelpers::SetAndSaveCVarFloat(GetFSRBaseString() + TEXT("Sharpness"), Sharpness, FSR4Section);
}

float UFSRLibrary::GetFSRSharpness()
{
	return UFSRHelpers::GetCVarFloat(GetFSRBaseString() + TEXT("Sharpness"));
}

void UFSRLibrary::SetFSRDedither(EFSRDeditherMode Mode)
{
	UFSRHelpers::SetAndSaveCVarInt(GetFSRBaseString() + TEXT("DeDither"), (int32)Mode, FSR4Section);
}

EFSRDeditherMode UFSRLibrary::GetFSRDedither()
{
	return (EFSRDeditherMode)UFSRHelpers::GetCVarInt(GetFSRBaseString() + TEXT("DeDither"));
}

void UFSRLibrary::SetFSRHistoryFormat(EFSRHistoryFormat Format)
{
	UFSRHelpers::SetAndSaveCVarInt(GetFSRBaseString() + TEXT("HistoryFormat"), (int32)Format, FSR4Section);
}

EFSRHistoryFormat UFSRLibrary::GetFSRHistoryFormat()
{
	return (EFSRHistoryFormat)UFSRHelpers::GetCVarInt(GetFSRBaseString() + TEXT("HistoryFormat"));
}

void UFSRLibrary::SetFSRReactivenessScale(float Scale)
{
	if (const UFSRSettings* Settings = GetDefault<UFSRSettings>())
	{
		if (Settings->FSRCompatibility == EFSRVersionCompatibility::FSR2)
		{
			return;
		}
	}
	UFSRHelpers::SetAndSaveCVarFloat(GetFSRBaseString() + TEXT("ReactivenessScale"), Scale, FSR4Section);
}

float UFSRLibrary::GetFSRReactivenessScale()
{
	if (const UFSRSettings* Settings = GetDefault<UFSRSettings>())
	{
		if (Settings->FSRCompatibility == EFSRVersionCompatibility::FSR2)
		{
			return 0.0f;
		}
	}
	return UFSRHelpers::GetCVarFloat(GetFSRBaseString() + TEXT("ReactivenessScale"));
}

void UFSRLibrary::EnableAutoExposure(bool bEnable)
{
	UFSRHelpers::SetAndSaveCVarInt(GetFSRBaseString() + TEXT("AutoExposure"), bEnable ? 1 : 0, FSR4Section);
}

bool UFSRLibrary::IsAutoExposureEnabled()
{
	return UFSRHelpers::GetCVarInt(GetFSRBaseString() + TEXT("AutoExposure")) != 0;
}

void UFSRLibrary::SetFSRLandscapeHISMMobility(EFSRLandscapeHISMMobility Mobility)
{
	UFSRHelpers::SetAndSaveCVarInt(GetFSRBaseString() + TEXT("ForceLandscapeHISMMobility"), (int32)Mobility, FSR4Section);
}

EFSRLandscapeHISMMobility UFSRLibrary::GetFSRLandscapeHISMMobility()
{
	return (EFSRLandscapeHISMMobility)UFSRHelpers::GetCVarInt(GetFSRBaseString() + TEXT("ForceLandscapeHISMMobility"));
}