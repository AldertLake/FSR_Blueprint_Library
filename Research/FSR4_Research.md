# AMD FSR Upscaling (FSR 4) - Research Data

## Overview
The AMD FSR Upscaling plugin for Unreal Engine (FSR 4) provides a cutting-edge Machine Learning (ML) upscaler combined with new ML-powered Frame Generation. Trained on AMD Instinct GPUs, it uses hardware-accelerated features of the AMD RDNA 4 architecture to maximize upscaling quality and performance.

### Key Differences from FSR 3
- **ML-Powered:** Both Upscaling and Frame Generation are ML-accelerated on supported hardware (AMD Radeon RX 9000 series or better).
- **Fallback Support:** Automatically falls back to analytical FSR 3 and FSR 2 upscaling/frame generation on unsupported or older hardware (e.g., RDNA 3.5 and older).
- **Independent Frame Gen:** FSR Frame Generation can now be enabled independently of FSR Upscaling.
- **RHI Backend Removed:** The RHI backend has been removed; relies heavily on Direct3D 12 and IDXGISwapChain implementation.
- **CVar Naming:** Console variables have shifted from `r.FidelityFX.FSR3.*` to `r.FidelityFX.FSR.*`.

## Core Setup & Quality Modes
FSR 4 requires **Temporal Upsampling** (`r.TemporalAA.Upsampling = 1`) and the Anti-Aliasing Method set to Temporal Super-Resolution (TSR) (`r.AntiAliasingMethod = 4`).

### Quality Modes
The plugin controls the quality mode using `r.FidelityFX.FSR.QualityMode`, which overrides `r.ScreenPercentage`.
* **Native AA (1.0x):** `r.FidelityFX.FSR.QualityMode 0` (Superior image quality to native with modest performance cost)
* **Quality (1.5x):** `r.FidelityFX.FSR.QualityMode 1` (Significant performance gain, quality equal/superior to native)
* **Balanced (1.7x):** `r.FidelityFX.FSR.QualityMode 2` (Ideal compromise between quality and performance)
* **Performance (2.0x):** `r.FidelityFX.FSR.QualityMode 3` (Major performance gain, quality similar to native)
* **Ultra Performance (3.0x):** `r.FidelityFX.FSR.QualityMode 4` (Highest performance gain, quality representative of native)

## Console Variables (CVars)

### General FSR 4 Upscaling CVars
| Console Variable | Default | Range | Details |
|---|---|---|---|
| `r.FidelityFX.FSR.Enabled` | - | 0, 1 | Enable or disable FSR 4 upscaling. |
| `r.FidelityFX.FSR.QualityMode` | 1 | 0-4 | Sets the scaling ratio (0: Native AA, 1: Quality, 2: Balanced, 3: Performance, 4: Ultra Performance). |
| `r.FidelityFX.FSR.RequestProvider` | 0 | 0, 2, 3, 4 | Assigns the Upscaler provider to a specific implementation of FSR. (0 selects the highest supported version, e.g., 4). |
| `r.FidelityFX.FSR.AdjustMipBias` | 1 | 0, 1 | Applies negative MipBias to material textures, improving results. |
| `r.FidelityFX.FSR.Sharpness` | 0 | 0.0 - 1.0 | When > 0.0, enables Robust Contrast Adaptive Sharpening (RCAS) Filter to sharpen the output image. |
| `r.FidelityFX.FSR.AutoExposure` | 0 | 0, 1 | Set to 1 to use FSR’s own auto-exposure. |
| `r.FidelityFX.FSR.HistoryFormat` | 0 | 0, 1 | Bit-depth for history texture. `0` = PF_FloatRGBA, `1` = PF_FloatR11G11B10. |
| `r.FidelityFX.FSR.UseSSRExperimentalDenoiser` | 0 | 0, 1 | Uses `r.SSR.ExperimentalDenoiser` when FSR is enabled (required when `CreateReactiveMask` is enabled). |
| `r.FidelityFX.FSR.QuantizeInternalTextures` | 0 | 0, 1 | Rounds up the size of some internal texture to ensure specific divisibility. |
| `r.FidelityFX.FSR.EnabledInEditorViewport` | 0 | 0, 1 | Enables FSR Temporal Upscale in the Editor viewport by default. |
| `r.FidelityFX.FSR.DeDither` | 2 | 0, 1, 2 | Enables an extra pass to de-dither rendering before FSR 4. (0: Off, 1: Full, 2: Hair Only). |

### Reactive Mask & Fallback CVars (Used heavily for FSR 3 Analytical Fallback)
*Note: FSR 4 still processes these to assist the analytical FSR 3 fallback on unsupported GPUs.*

| Console Variable | Default | Range | Details |
|---|---|---|---|
| `r.FidelityFX.FSR.CreateReactiveMask` | 1 | 0, 1 | Generates a mask determining pixel reactivity. |
| `r.FidelityFX.FSR.ReactiveMaskReflectionScale` | 0.4 | 0.0 - 1.0 | Scales reflection contribution to the reactive mask. |
| `r.FidelityFX.FSR.ReactiveMaskReflectionLumaBias` | 0 | 0.0 - 1.0 | Biases the reactive mask by the luminance of the reflection. |
| `r.FidelityFX.FSR.ReactiveMaskRoughnessScale` | 0.15 | 0.0 - 1.0 | Scales the GBuffer roughness as a fallback value for the reactive mask. |
| `r.FidelityFX.FSR.ReactiveMaskRoughnessBias` | 0.25 | 0.0 - 1.0 | Biases the reactive mask value when screenspace/planar reflections are weak. |
| `r.FidelityFX.FSR.ReactiveMaskRoughnessMaxDistance` | 6000 | 0.0 - INF | Max distance (world units) for using material roughness to contribute to the reactive mask. |
| `r.FidelityFX.FSR.ReactiveMaskRoughnessForceMaxDistance` | 0 | 0, 1 | Enable to force the max distance for material roughness. |
| `r.FidelityFX.FSR.ReactiveMaskTranslucencyBias` | 1.0 | 0.0 - 1.0 | Scales how much contribution translucency makes to the reactive mask. |
| `r.FidelityFX.FSR.ReactiveMaskTranslucencyLumaBias` | 0.0 | 0.0 - 1.0 | Biases translucency contribution by the luminance of the transparency. |
| `r.FidelityFX.FSR.ReactiveHistoryTranslucencyBias` | 0.5 | 0.0 - 1.0 | Scales how much translucency suppresses history via the reactive mask. |
| `r.FidelityFX.FSR.ReactiveHistoryTranslucencyLumaBias` | 0.0 | 0.0 - 1.0 | Biases how much translucency suppresses history via the reactive mask by transparency luminance. |
| `r.FidelityFX.FSR.ReactiveMaskPreDOFTranslucencyScale` | 1.0 | 0.0 - 1.0 | Scales contribution pre-Depth-of-Field translucency color makes to the reactive mask. |
| `r.FidelityFX.FSR.ReactiveMaskPreDOFTranslucencyMax` | 0 | 0, 1 | Toggle logic for pre-Depth-of-Field translucency contribution. |
| `r.FidelityFX.FSR.ReactiveMaskTranslucencyMaxDistance` | 500000 | 0.0 - INF | Max distance for using translucency in the reactive mask. |
| `r.FidelityFX.FSR.ReactiveMaskReactiveShadingModelID` | MSM_NUM | 0 - MAX | Treat the specified shading model as reactive. |
| `r.FidelityFX.FSR.ReactiveMaskForceReactiveMaterialValue`| 0.0 | 0.0 - 1.0 | Forces the reactive mask value for Reactive Shading Model materials. |
| `r.FidelityFX.FSR.ReactiveMaskDeferredDecalScale` | 0 | 0.0 - 1.0 | Scales how much deferred decal values contribute to the reactive mask. |
| `r.FidelityFX.FSR.ReactiveHistoryDeferredDecalScale` | 0 | 0.0 - 1.0 | Scales how much deferred decal values contribute to supressing history. |
| `r.FidelityFX.FSR.ReactiveMaskTAAResponsiveValue` | 0 | 0.0 - 1.0 | Value to write to reactive mask when pixels are marked in the stencil buffer as TAA Responsive. |
| `r.FidelityFX.FSR.ReactiveHistoryTAAResponsiveValue` | 0 | 0.0 - 1.0 | Value to write to reactive history when pixels are marked in the stencil buffer as TAA Responsive. |
| `r.FidelityFX.FSR.ReactiveMaskCustomStencilScale` | 0 | 0.0 - 1.0 | Scales how much custom stencil values contribute to the reactive mask. |
| `r.FidelityFX.FSR.ReactiveHistoryCustomStencilScale` | 0 | 0.0 - 1.0 | Scales how much custom stencil values contribute to supressing history. |
| `r.FidelityFX.FSR.CustomStencilMask` | 0 | 0 - 255 | Bitmask used when accessing the custom stencil to read reactive mask values. |
| `r.FidelityFX.FSR.CustomStencilShift` | 0 | 0 - 31 | Bitshift applied to the value read from the custom stencil. |
| `r.FidelityFX.FSR.VelocityFactor` | 1 | 0.0 - 1.0 | Value of 0.0f can improve temporal stability of bright pixels. |
| `r.FidelityFX.FSR.ReactivenessScale` | 1 | 0.0 - INF | Testing CVar to check if larger reactive mask values reduce ghosting. |
| `r.FidelityFX.FSR.ShadingChangeScale` | 1 | 0.0 - INF | Scales computed shading change value at read to have higher reactiveness. |
| `r.FidelityFX.FSR.AccumulationAddedPerFrame` | 0.333 | 0.0 - 1.0 | Amount of accumulation added per frame where disocclusion occurred or reactive mask > 0.0f. |
| `r.FidelityFX.FSR.MinDisocclutionAccumulation` | -0.333 | -1.0 - 1.0 | Increasing this value may reduce white pixel temporal flickering around swaying thin objects. |
| `r.FidelityFX.FSR.ForceVertexDeformationOutputsVelocity` | 1 | 0, 1 | Forces materials with World Position Offset/Displacement to output velocities even when not moved. |
| `r.FidelityFX.FSR.ForceLandscapeHISMMobility` | 0 | 0, 1, 2 | Forces the mobility of Landscape HISM components that use WPO materials to render valid velocities (1: Faster CPU, 2: Faster GPU). |

### Frame Generation CVars (FSR 4)
| Console Variable | Default | Range | Details |
|---|---|---|---|
| `r.FidelityFX.FI.Enabled` | 1 | 0, 1 | Enable FSR Frame Generation. Does NOT require Upscaling to be enabled. |
| `r.FidelityFX.FI.OverrideSwapChainDX12` | 1 | 0, 1 | Uses FSR’s D3D12 swap-chain override that improves frame pacing. (RHI fallback is removed, DX12 is heavily preferred). |
| `r.FidelityFX.FI.AllowAsyncWorkloads` | 1 | 0, 1 | Uses async execution of Frame Generation (concurrent with next frame). |
| `r.FidelityFX.FI.UIMode` | 0 | 0, 1 | Render method for UI. `0` = Slate Redraw. `1` = UI Extraction (decoupled via pre/post frame comparison). |
| `r.FidelityFX.FI.ModifySlateDeltaTime` | 1 | 0, 1 | Sets FSlateApplication delta time to 0.0 when redrawing UI to prevent widgets updating twice incorrectly. |
| `r.FidelityFX.FI.UseDistortionTexture` | 0 | 0, 1 | Enable distortion texture input using Unreal Engine’s distortion texture frame. |
| `r.FidelityFX.FI.CaptureDebugUI` | 1 | 0, 1 | Force detecting and copying debug UI. Disabled in Shipping. |
| `r.FidelityFX.FI.UpdateGlobalFrameTime` | 0 | 0, 1 | Updates GAverageMs/GAverageFPS globals with average frame time/FPS calculated by generation code. |
| `r.FidelityFX.FI.ShowDebugTearLines` | 1 | 0, 1 | Show debug tear lines when running Frame Generation (Not available in Test/Shipping). |
| `r.FidelityFX.FI.ShowDebugView` | 0 | 0, 1 | Show debug view when running Frame Generation (Not available in Test/Shipping). |

## Key Technical Notes for Implementation
- **Provider Override:** A new CVar `r.FidelityFX.FSR.RequestProvider` is available to explicitly force an FSR version (e.g. forcing FSR 3 analytical on an FSR 4 ML hardware capable system).
- **Independent Frame Generation:** FSR Frame Generation is now decoupled from upscaling, meaning players can use FSR Frame Gen alongside Native AA or potentially other upscalers.
- **RHI Backend Removed:** Direct3D 12 proxy swapchain is exclusively used for robust frame pacing and async workloads.
- **Unified Namespacing:** Note that `r.FidelityFX.FSR3...` is now generalized to `r.FidelityFX.FSR...` allowing seamless transition between ML and Analytical models under the hood.
