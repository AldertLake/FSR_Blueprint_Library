// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

using UnrealBuildTool;

public class FSRDesktop : ModuleRules
{
    public FSRDesktop(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "FSRGlobal" });

        PrivateDependencyModuleNames.AddRange(new string[] { "FSRGlobal" });
    }
}