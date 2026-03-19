// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSRDataTypes.h"
#include "FSRExtra.generated.h"

UCLASS()
class FSRDESKTOP_API UFSRExtra : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/* Restart your game by creating new process and then closing the existing one.
	   Note : Work only outisde editor & in descktop platform - used for testing & debug. */
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Extra")
	static void RestartGameWithCommandLine(const FString& ExtraCommandLine, bool bOverrideExistingLaunchArgs);

	/** Retrieves the currently active Rendering Hardware Interface (RHI) API used by the engine. */
	UFUNCTION(BlueprintPure, Category = "AMD FidelityFX™ Extra", meta = (DisplayName = "Get Current Active RHI"))
	static EFSRActiveRHI GetCurrentActiveRHI();
};
