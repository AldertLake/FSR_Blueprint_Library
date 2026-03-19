// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#include "FSRLibrary.h"
#include "FSRHelpers.h"

const FString UFSRLibrary::FSR4Section = TEXT("SystemSettings");

void UFSRLibrary::EnableFSR(bool bEnable)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FSR.Enabled"), bEnable ? 1 : 0, FSR4Section);
}

bool UFSRLibrary::IsFSREnabled()
{
	return UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FSR.Enabled")) != 0;
}

void UFSRLibrary::SetFSRQualityMode(EFSRQualityMode Mode)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FSR.QualityMode"), (int32)Mode, FSR4Section);
}

EFSRQualityMode UFSRLibrary::GetFSRQualityMode()
{
	return (EFSRQualityMode)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FSR.QualityMode"));
}

void UFSRLibrary::SetFSRSharpness(float Sharpness)
{
	UFSRHelpers::SetAndSaveCVarFloat(TEXT("r.FidelityFX.FSR.Sharpness"), Sharpness, FSR4Section);
}

float UFSRLibrary::GetFSRSharpness()
{
	return UFSRHelpers::GetCVarFloat(TEXT("r.FidelityFX.FSR.Sharpness"));
}

void UFSRLibrary::SetFSRDedither(EFSRDeditherMode Mode)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FSR.DeDither"), (int32)Mode, FSR4Section);
}

EFSRDeditherMode UFSRLibrary::GetFSRDedither()
{
	return (EFSRDeditherMode)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FSR.DeDither"));
}

void UFSRLibrary::SetFSRHistoryFormat(EFSRHistoryFormat Format)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FSR.HistoryFormat"), (int32)Format, FSR4Section);
}

EFSRHistoryFormat UFSRLibrary::GetFSRHistoryFormat()
{
	return (EFSRHistoryFormat)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FSR.HistoryFormat"));
}

void UFSRLibrary::SetFSRReactivenessScale(float Scale)
{
	UFSRHelpers::SetAndSaveCVarFloat(TEXT("r.FidelityFX.FSR.ReactivenessScale"), Scale, FSR4Section);
}

float UFSRLibrary::GetFSRReactivenessScale()
{
	return UFSRHelpers::GetCVarFloat(TEXT("r.FidelityFX.FSR.ReactivenessScale"));
}

void UFSRLibrary::EnableAutoExposure(bool bEnable)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FSR.AutoExposure"), bEnable ? 1 : 0, FSR4Section);
}

bool UFSRLibrary::IsAutoExposureEnabled()
{
	return UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FSR.AutoExposure")) != 0;
}

void UFSRLibrary::SetFSRLandscapeHISMMobility(EFSRLandscapeHISMMobility Mobility)
{
	UFSRHelpers::SetAndSaveCVarInt(TEXT("r.FidelityFX.FSR.ForceLandscapeHISMMobility"), (int32)Mobility, FSR4Section);
}

EFSRLandscapeHISMMobility UFSRLibrary::GetFSRLandscapeHISMMobility()
{
	return (EFSRLandscapeHISMMobility)UFSRHelpers::GetCVarInt(TEXT("r.FidelityFX.FSR.ForceLandscapeHISMMobility"));
}