// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#include "FSRHelpers.h"
#include "HAL/IConsoleManager.h"
#include "Misc/ConfigCacheIni.h"
#include "Runtime/Launch/Resources/Version.h"

//For priority of cvar, it's recommanded to use ECVF_SetByGameSetting but i found issues with it since ECVF_SetByConsole
//Has higher priority & will override it... some retardded people use the console wich use ECVF_SetByConsole to set values 
//And then complain about the node not working, this is why now the node use ECVF_SetByConsole, if you are an advanced user
//then use ECVF_SetByGameSetting cause it's better & ECVF_SetByConsole is not made for such usage !

void UFSRHelpers::SetAndSaveCVarInt(const FString& CVarName, int32 Value, const FString& Section)
{
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(*CVarName))
	{
		CVar->Set(Value, ECVF_SetByConsole);
	}

	GConfig->SetInt(*Section, *CVarName, Value, GEngineIni);
	GConfig->Flush(false, GEngineIni);
}

void UFSRHelpers::SetAndSaveCVarFloat(const FString& CVarName, float Value, const FString& Section)
{
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(*CVarName))
	{
		CVar->Set(Value, ECVF_SetByConsole);
	}

	GConfig->SetFloat(*Section, *CVarName, Value, GEngineIni);
	GConfig->Flush(false, GEngineIni);
}

int32 UFSRHelpers::GetCVarInt(const FString& CVarName)
{
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(*CVarName))
	{
		return CVar->GetInt();
	}
	return 0;
}

float UFSRHelpers::GetCVarFloat(const FString& CVarName)
{
	if (IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(*CVarName))
	{
		return CVar->GetFloat();
	}
	return 0.0f;
}

void UFSRHelpers::RemoveSavedCVar(const FString& CVarName, const FString& Section)
{
#if (ENGINE_MAJOR_VERSION > 5) || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 4)
	GConfig->RemoveKeyFromSection(*Section, FName(*CVarName), GEngineIni);
#else
	if (FConfigFile* ConfigFile = GConfig->FindConfigFile(GEngineIni))
	{
		if (FConfigSection* ConfigSection = ConfigFile->Find(*Section))
		{
			ConfigSection->Remove(FName(*CVarName));
		}
	}
#endif

	GConfig->Flush(false, GEngineIni);
}