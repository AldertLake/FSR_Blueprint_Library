// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "FSRDataTypes.generated.h"

UENUM(BlueprintType)
enum class EFSRQualityMode : uint8
{
	NativeAA = 0        UMETA(DisplayName = "Native AA"),
	Quality = 1         UMETA(DisplayName = "Quality"),
	Balanced = 2        UMETA(DisplayName = "Balanced"),
	Performance = 3     UMETA(DisplayName = "Performance"),
	UltraPerformance = 4 UMETA(DisplayName = "Ultra Performance")
};

UENUM(BlueprintType)
enum class EFSRSwapChainMode : uint8
{
	DefaultRHI = 0   UMETA(DisplayName = "Default RHI (Fallback)"),
	OverrideDX12 = 1 UMETA(DisplayName = "Override DX12 (Async/Better Pacing)")
};

UENUM(BlueprintType)
enum class EFSRDeditherMode : uint8
{
	Off = 0       UMETA(DisplayName = "Off"),
	Full = 1      UMETA(DisplayName = "Full"),
	HairOnly = 2  UMETA(DisplayName = "Hair Only")
};

UENUM(BlueprintType)
enum class EFSRFrameGenerationMode : uint8
{
	Disabled = 0  UMETA(DisplayName = "Disabled"),
	Enabled = 1   UMETA(DisplayName = "Enabled")
};

UENUM(BlueprintType)
enum class EFSRHistoryFormat : uint8
{
	FloatRGBA = 0       UMETA(DisplayName = "PF_FloatRGBA (High Quality)"),
	FloatR11G11B10 = 1  UMETA(DisplayName = "PF_FloatR11G11B10 (Reduced Bandwidth)")
};

UENUM(BlueprintType)
enum class EFSRUIMode : uint8
{
	SlateRedraw = 0  UMETA(DisplayName = "Slate Redraw (NativeTick twice)"),
	UIExtraction = 1 UMETA(DisplayName = "UI Extraction (Decoupled)")
};

UENUM(BlueprintType)
enum class EFSRLandscapeHISMMobility : uint8
{
	Off = 0  UMETA(DisplayName = "Off"),
	CPU = 1  UMETA(DisplayName = "Force CPU (Faster CPU)"),
	GPU = 2  UMETA(DisplayName = "Force GPU (Faster GPU)")
};

UENUM(BlueprintType)
enum class EFSRActiveRHI : uint8
{
	Unknown = 0   UMETA(DisplayName = "Unknown"),
	DirectX11 = 1 UMETA(DisplayName = "DirectX 11"),
	DirectX12 = 2 UMETA(DisplayName = "DirectX 12"),
	Vulkan = 3    UMETA(DisplayName = "Vulkan"),
	OpenGL = 4    UMETA(DisplayName = "OpenGL")
};