# Agent Instructions for FSR Blueprint Library

This file contains instructions, architectural overview, and guidelines for AI agents working on the **FSR Blueprint Library** Unreal Engine plugin.

## Overview
The FSR Blueprint Library is a runtime plugin for Unreal Engine 5.4+ that exposes AMD FidelityFX Super Resolution 4 (FSR 4) features directly to Blueprints. It enables developers to easily tweak upscaling quality, frame generation, and other FidelityFX Super Resolution settings without custom C++ code. FSR 3 is deprecated in this version.

## Module Architecture
The plugin is structured into four main modules to ensure proper platform-specific compilation and deployment:

1. **FSRGlobal**
   - **Target:** All Platforms (Win64, Mac, Linux, Android, IOS)
   - **Type:** Runtime
   - **Loading Phase:** PreLoadingScreen
   - **Role:** Contains shared definitions, enums (`FSRDataTypes.h`), and global utility nodes (e.g., CVar getters/setters in `FSRHelpers.h`).

2. **FSRDesktop**
   - **Target:** Desktop Platforms (Win64, Mac, Linux)
   - **Type:** Runtime
   - **Loading Phase:** PreLoadingScreen
   - **Role:** Implements the core FSR functionality for desktop. Contains:
     - `UFSRLibrary`: Functions to control FSR upscaling, quality mode, sharpness, dedithering, history format, auto-exposure, and HISM mobility.
     - `UFSRFGLibrary`: Functions to manage Frame Generation (enabling, UI render mode, async present, and debug views).
     - `UFSRExtra`: Utilities like checking the active RHI and restarting the game with command-line arguments.

3. **FSRMobile**
   - **Target:** Mobile Platforms (Android, IOS)
   - **Type:** Runtime
   - **Loading Phase:** PreLoadingScreen
   - **Role:** Handles mobile-specific FSR features (handled in `FSRMobileLibrary.h`).

4. **FSREditor**
   - **Target:** Editor Platforms (Win64, Mac, Linux)
   - **Type:** Editor
   - **Loading Phase:** Default
   - **Role:** Handles editor-specific integrations and UI logic. It is only loaded within the UE editor.

## Key Blueprint Nodes & Enums
When extending or debugging the plugin, refer to `FSRDataTypes.h` for core enums:
- `EFSRQualityMode`: (Native AA, Quality, Balanced, Performance, Ultra Performance)
- `EFSRFrameGenerationMode`: (Disabled, Enabled)
- `EFSRSwapChainMode`: (Default RHI, Override DX12)
- `EFSRUIMode`: (Slate Redraw, UI Extraction)
- `EFSRActiveRHI`: (DirectX 11, DirectX 12, Vulkan, OpenGL)

## Guidelines for Future Work
- **Platform Separation:** When adding new FSR features, ensure they are placed in the correct module. For example, Frame Generation is currently primarily a desktop feature; new FG nodes should go in `FSRDesktop` unless AMD explicitly supports mobile FG in the future.
- **Engine Variables:** Use `UFSRHelpers::SetAndSaveCVarInt` (and related methods) to persist CVar changes to `SystemSettings` (or Engine.ini) so users don't lose settings on restart.
- **Documentation & UI:** If adding new Blueprint nodes, ensure tooltips and meta display names (`meta = (DisplayName = "...")`) are clearly defined for the end-user. Match existing formatting and descriptions.
- **C++ Best Practices:** Maintain the existing coding style. Use `UFUNCTION(BlueprintCallable)` or `UFUNCTION(BlueprintPure)` with appropriate `Category` headers (e.g., `"AMD FidelityFX™ Super Resolution"`, `"AMD FidelityFX™ Frame Generation"`, `"AMD FidelityFX™ Extra"`). Prefix classes with the module API macro (e.g., `FSRDESKTOP_API`, `FSRGLOBAL_API`).
- **Dependencies:** The plugin heavily interacts with UE's renderer and RHI. Any low-level changes must consider rendering thread safety, UE's CVar system, and cross-platform compatibility.

## Important Links
- **GitHub:** https://github.com/AldertLake/FSR_Blueprint_Library
- **Issues:** https://github.com/AldertLake/FSR_Blueprint_Library/issues
- **Documentation:** https://aldertlake.gitbook.io/amd-fsr-blueprint-control/
- **Marketplace (Fab):** https://www.fab.com/listings/9a896205-c4a5-4ce4-ba96-15d3162bc7bb
