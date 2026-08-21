// -----------------------------------------------------
// Copyright   (c) 2025 AldertLake. All Rights Reserved.
// GitHub:     https://github.com/AldertLake/
// Discord:    https://discord.gg/QpPPfh6WVn
// -----------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSRHelpers.generated.h"

UCLASS()
class FSRGLOBAL_API UFSRHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Save FSR Settings To Disk"))
	static void SaveFSRSettings();

	static void SetAndSaveCVarInt(const FString& CVarName, int32 Value, const FString& Section = TEXT("SystemSettings"));
	static void SetAndSaveCVarFloat(const FString& CVarName, float Value, const FString& Section = TEXT("SystemSettings"));

	static int32 GetCVarInt(const FString& CVarName);
	static float GetCVarFloat(const FString& CVarName);

	static void RemoveSavedCVar(const FString& CVarName, const FString& Section);
};