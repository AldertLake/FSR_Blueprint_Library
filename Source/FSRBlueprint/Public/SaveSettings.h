// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Support:  https://ko-fi.com/aldertlake
// ---------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SaveSettings.generated.h"

UCLASS()
class FSRBLUEPRINT_API USaveSettings : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    //Call this to save an console variable for next startup
    UFUNCTION(BlueprintCallable, Category = "AMD FSR Save")
    static void SaveEngineConfigSetting(const FString& Section, const FString& Key, int32 Value);

    // Existing float function 
    UFUNCTION(BlueprintCallable, Category = "AMD FSR Save")
    static void SaveEngineConfigFloatSetting(const FString& Section, const FString& Key, float Value);

    // Saves a string value to the specified section and key in the engine's config file
    UFUNCTION(BlueprintCallable, Category = "AMD FSR Save")
    static void SaveEngineConfigSettingString(const FString& Section, const FString& Key, const FString& Value);

    //I Use this to remove specific key from the engine.ini config file
    UFUNCTION(BlueprintCallable, Category = "AMD FSR Save")
    static void RemoveEngineConfigKey(const FString& Section, const FString& Key);

};


