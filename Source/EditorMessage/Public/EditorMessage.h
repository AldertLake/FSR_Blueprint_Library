// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Support:  https://ko-fi.com/aldertlake
// ---------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class EditorMessage : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
    static void ShowRatingDialogIfNeeded();
};