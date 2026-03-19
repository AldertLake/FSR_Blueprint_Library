// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSRDataTypes.h"
#include "FSRFGLibrary.generated.h"


UCLASS()
class FSRDESKTOP_API UFSRFGLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static const FString FSR4Section;

	/** Enables or disables AMD FSR Frame Generation. */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Frame Generation", meta = (DisplayName = "Set FSR-FG Mode"))
	static void SetFSRFGMode(EFSRFrameGenerationMode Mode);

	/** Retrieves the current Frame Generation state. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Frame Generation", meta = (DisplayName = "Get FSR-FG Current Mode"))
	static EFSRFrameGenerationMode GetFSRFGCurrentMode();

	/** Sets the UI rendering method during Frame Generation (e.g., Slate Redraw or UI Extraction). */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Frame Generation", meta = (DisplayName = "Set FSR-FG UI Render Mode"))
	static void SetFSRFGUIRenderMode(EFSRUIMode Mode);

	/** Retrieves the active UI rendering method for Frame Generation. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Frame Generation", meta = (DisplayName = "Get FSR-FG UI Render Mode"))
	static EFSRUIMode GetFSRFGUIRenderMode();

	/** Toggles the Frame Generation debug view (Development/Editor only). */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Frame Generation", meta = (DisplayName = "Show FSR-FG Debug View"))
	static void ShowFSRFGDebugView(bool bShow);

	/** Toggles the display of tear lines for debugging frame pacing (Development/Editor only). */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Frame Generation", meta = (DisplayName = "Show FSR-FG Debug Tear Lines"))
	static void ShowFSRFGDebugTearLines(bool bShow);

	/** Ensures debug UI elements (like the console) are captured and displayed correctly during Frame Gen. */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Frame Generation", meta = (DisplayName = "Show FSR-FG Capture Debug UI"))
	static void ShowFSRFGCaptureDebugUI(bool bCapture);

	/** Enables or disables the customized D3D12 swap-chain for superior asynchronous frame pacing (requires restart). */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Frame Generation", meta = (DisplayName = "Set FSR-FG Async Present"))
	static void SetFSRFGAsyncPresent(EFSRSwapChainMode Mode);

	/** Retrieves the current swap-chain override mode. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Frame Generation", meta = (DisplayName = "Get FSR-FG Async Present"))
	static EFSRSwapChainMode GetFSRFGAsyncPresent();
};