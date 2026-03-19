// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FFSREditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void ShowRatingPrompt();
};