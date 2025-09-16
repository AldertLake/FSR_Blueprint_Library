// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Support:  https://ko-fi.com/aldertlake
// ---------------------------------------------------

#include "SaveSettings.h"
#include "Misc/ConfigCacheIni.h"
#include "Engine/Engine.h"

//Used To Save Many Settings Variables
void USaveSettings::SaveEngineConfigSetting(const FString& Section, const FString& Key, int32 Value)
{
    if (GConfig)
    {
        GConfig->SetInt(*Section, *Key, Value, GEngineIni);
        GConfig->Flush(false, GEngineIni);
        if (GEngine)
        {
            FString Command = FString::Printf(TEXT("%s %d"), *Key, Value);
            GEngine->Exec(nullptr, *Command);
        }
    }
}

void USaveSettings::SaveEngineConfigSettingString(const FString& Section, const FString& Key, const FString& Value)
{
    if (GConfig)
    {
        GConfig->SetString(*Section, *Key, *Value, GEngineIni);
        GConfig->Flush(false, GEngineIni);
        if (GEngine)
        {
            FString Command = FString::Printf(TEXT("%s %s"), *Key, *Value);
            GEngine->Exec(nullptr, *Command);
        }
    }
}

void USaveSettings::RemoveEngineConfigKey(const FString& Section, const FString& Key)
{
    if (GConfig)
    {
        GConfig->RemoveKey(*Section, *Key, GEngineIni);
        GConfig->Flush(false, GEngineIni);
    }
}

void USaveSettings::SaveEngineConfigFloatSetting(const FString& Section, const FString& Key, float Value)
{
    if (GConfig)
    {
        GConfig->SetFloat(*Section, *Key, Value, GEngineIni);
        // Flush to disk
        GConfig->Flush(false, GEngineIni);
        if (GEngine)
        {
            FString Command = FString::Printf(TEXT("%s %f"), *Key, Value);
            GEngine->Exec(nullptr, *Command);
        }
    }
}

