// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Support:  https://ko-fi.com/aldertlake
// ---------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RestartGame.generated.h"

UCLASS()
class FSRBLUEPRINT_API URestartGame : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	//Restart Game To Apply Advanced FSR Settings In Case Of Multiple Uspcallers
	UFUNCTION(BlueprintCallable, Category = "FSR Helper")
	static void RestartGameWithCommandLine(const FString& ExtraCommandLine);

	//Use This To Get Current RHI 
	UFUNCTION(BlueprintPure, Category = "FSR Helper")
	static FString GetRHIName();
};
