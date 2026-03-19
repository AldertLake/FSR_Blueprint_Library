// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSRMobileLibrary.generated.h"

UCLASS()
class FSRMOBILE_API UFSRMobileLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static const FString MobileSection;

	/** Enables or disables AMD FSR upscaling on mobile platforms. */
	UFUNCTION(BlueprintCallable, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Enable FSR-Mobile"))
	static void EnableFSRMobile(bool bEnable);

	/** Checks if FSR upscaling for mobile is currently active. */
	UFUNCTION(BlueprintPure, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Is FSR-Mobile Enabled"))
	static bool IsFSRMobileEnabled();

	/** Adjusts the post-upscaling sharpness level for mobile FSR. */
	UFUNCTION(BlueprintCallable, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Set FSR-Mobile Sharpness"))
	static void SetFSRMobileSharpness(float Sharpness);

	/** Retrieves the current FSR mobile sharpness value. */
	UFUNCTION(BlueprintPure, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Get FSR-Mobile Sharpness"))
	static float GetFSRMobileSharpness();

	/** Toggles the experimental denoising pass for mobile FSR. */
	UFUNCTION(BlueprintCallable, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Enable FSR-Mobile Denoise"))
	static void EnableFSRMobileDenoise(bool bEnable);

	/** Checks if FSR mobile denoising is currently enabled. */
	UFUNCTION(BlueprintPure, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Is FSR-Mobile Denoise Enabled"))
	static bool IsFSRMobileDenoiseEnabled();

	/** Disables the compute shader path for FSR Mobile (forces pixel shader fallback). */
	UFUNCTION(BlueprintCallable, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Disable FSR-Mobile Compute"))
	static void DisableFSRMobileCompute(bool bDisable);

	/** Checks if the compute shader path for FSR mobile is disabled. */
	UFUNCTION(BlueprintPure, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Is FSR-Mobile Compute Mode Disabled"))
	static bool IsFSRMobileComputeModeDisabled();

	/** Explicitly toggles the upsampling phase of the FSR mobile pipeline. */
	UFUNCTION(BlueprintCallable, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Enable Upsampling For FSR-Mobile"))
	static void EnableUpsamplingForFSRMobile(bool bEnable);

	/** Checks if the upsampling phase for FSR mobile is active. */
	UFUNCTION(BlueprintPure, Category = "AMD Fidelity FX Mobile", meta = (DisplayName = "Check FSR-Mobile Upsampling"))
	static bool CheckFSRMobileUpsampling();
};