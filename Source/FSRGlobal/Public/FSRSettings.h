// -----------------------------------------------------
// Copyright   (c) 2025 AldertLake. All Rights Reserved.
// GitHub:     https://github.com/AldertLake/
// Discord:    https://discord.gg/QpPPfh6WVn
// -----------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "FSRDataTypes.h"
#include "FSRSettings.generated.h"

/**
 * Settings for the FSR Blueprint Library plugin.
 */
UCLASS(Config = Engine, defaultconfig, meta = (DisplayName = "AMD FSR BP Library"))
class FSRGLOBAL_API UFSRSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UFSRSettings();

	/** 
	 * Target FSR version compatibility. 
	 * Depending on this value, Blueprint nodes will dispatch commands to different engine variables. 
	 */
	UPROPERTY(EditAnywhere, Config, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "FSR Compatibility"))
	EFSRVersionCompatibility FSRCompatibility;

	/** 
	 * If true, any FSR setting changed via Blueprint will immediately be saved to disk (Engine.ini). 
	 * Warning: If false, you must manually call 'Save FSR Settings To Disk' to persist changes. 
	 */
	UPROPERTY(EditAnywhere, Config, Category = "AMD FidelityFX™ Super Resolution", meta = (DisplayName = "Automatically Save Settings"))
	bool bAutomaticallySaveSettings;

	//~ Begin UDeveloperSettings Interface
	virtual FName GetCategoryName() const override;
#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;
#endif
	//~ End UDeveloperSettings Interface
};
