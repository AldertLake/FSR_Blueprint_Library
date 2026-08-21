// -----------------------------------------------------
// Copyright   (c) 2025 AldertLake. All Rights Reserved.
// GitHub:     https://github.com/AldertLake/
// Discord:    https://discord.gg/QpPPfh6WVn
// -----------------------------------------------------

#include "FSRSettings.h"

UFSRSettings::UFSRSettings()
{
	FSRCompatibility = EFSRVersionCompatibility::FSR4;
	bAutomaticallySaveSettings = true;
}

FName UFSRSettings::GetCategoryName() const
{
	return FName("Plugins");
}

#if WITH_EDITOR
FText UFSRSettings::GetSectionText() const
{
	return NSLOCTEXT("FSRBlueprintLibrary", "FSRSettingsSection", "AMD FSR BP Library");
}

FText UFSRSettings::GetSectionDescription() const
{
	return NSLOCTEXT("FSRBlueprintLibrary", "FSRSettingsDescription", "Configure settings for the FSR Blueprint Library plugin.");
}
#endif
