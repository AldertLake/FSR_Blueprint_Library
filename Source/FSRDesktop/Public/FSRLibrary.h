// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "FSRDataTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSRLibrary.generated.h"

UCLASS()
class FSRDESKTOP_API UFSRLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static const FString FSR4Section;

	/** Enables or disables AMD FSR upscaling. */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Enable FSR"))
	static void EnableFSR(bool bEnable);

	/** Checks if FSR upscaling is currently active. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Is FSR Enabled"))
	static bool IsFSREnabled();

	/** Sets the FSR upscaling quality mode (e.g., Quality, Balanced, Performance). */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Set FSR Quality Mode"))
	static void SetFSRQualityMode(EFSRQualityMode Mode);

	/** Retrieves the current FSR upscaling quality mode. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Get FSR Quality Mode"))
	static EFSRQualityMode GetFSRQualityMode();

	/** Adjusts the Robust Contrast Adaptive Sharpening (RCAS) intensity (0.0 to 1.0). */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Set FSR Sharpness"))
	static void SetFSRSharpness(float Sharpness);

	/** Retrieves the current FSR sharpness value. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Get FSR Sharpness"))
	static float GetFSRSharpness();

	/** Configures the dedithering mode for improved image stability. */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Set FSR Dedither"))
	static void SetFSRDedither(EFSRDeditherMode Mode);

	/** Retrieves the current FSR dedithering mode. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Get FSR Dedither"))
	static EFSRDeditherMode GetFSRDedither();

	/** Sets the precision format for the history texture to optimize performance or quality. */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Set FSR History Format"))
	static void SetFSRHistoryFormat(EFSRHistoryFormat Format);

	/** Retrieves the current history texture format. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Get FSR History Format"))
	static EFSRHistoryFormat GetFSRHistoryFormat();

	/** Adjusts the reactive mask scale to reduce ghosting on moving objects. */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Set FSR Reactiveness Scale"))
	static void SetFSRReactivenessScale(float Scale);

	/** Retrieves the current FSR reactiveness scale. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Get FSR Reactiveness Scale"))
	static float GetFSRReactivenessScale();

	/** Toggles FSR's internal auto-exposure computation. */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Enable Auto Exposure"))
	static void EnableAutoExposure(bool bEnable);

	/** Checks if FSR's internal auto-exposure is enabled. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Is Auto Exposure Enabled"))
	static bool IsAutoExposureEnabled();

	/** Forces mobility on Landscape HISM components to fix velocity rendering with World Position Offset materials. */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Set FSR Landscape HISM Mobility"))
	static void SetFSRLandscapeHISMMobility(EFSRLandscapeHISMMobility Mobility);

	/** Retrieves the current Landscape HISM mobility setting. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Get FSR Landscape HISM Mobility"))
	static EFSRLandscapeHISMMobility GetFSRLandscapeHISMMobility();
};