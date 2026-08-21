# AMD FidelityFX™ Super Resolution 2 (FSR 2) - Research Data

## Overview
AMD FidelityFX™ Super Resolution 2 (FSR 2) is an open-source temporal upscaling solution. It uses temporal algorithms to reconstruct fine geometric and texture detail to produce anti-aliased output from aliased input.

## Core Setup & Quality Modes
FSR 2 requires **Temporal Upsampling** to be enabled in Unreal Engine (`r.TemporalAA.Upsampling = 1`). FSR 2 itself can be controlled with its own console variables.

### Quality Modes
The plugin controls the quality mode using `r.FidelityFX.FSR2.QualityMode`, which overrides `r.ScreenPercentage`.
* **Quality (1.5x):** `r.FidelityFX.FSR2.QualityMode 1` (Significant performance gain, quality equal/superior to native)
* **Balanced (1.7x):** `r.FidelityFX.FSR2.QualityMode 2` (Ideal compromise between quality and performance)
* **Performance (2.0x):** `r.FidelityFX.FSR2.QualityMode 3` (Major performance gain, quality similar to native)
* **Ultra Performance (3.0x):** `r.FidelityFX.FSR2.QualityMode 4` (Highest performance gain, quality representative of native)

## Console Variables (CVars)

| Console Variable | Default | Range | Details |
|---|---|---|---|
| `r.FidelityFX.FSR2.Enabled` | - | 0, 1 | Enable or disable FSR 2 temporal upscaling. |
| `r.FidelityFX.FSR2.QualityMode` | - | 1-4 | Sets the scaling ratio (1: Quality, 2: Balanced, 3: Performance, 4: Ultra Performance). |
| `r.FidelityFX.FSR2.AdjustMipBias` | 1 | 0, 1 | Applies negative MipBias to material textures, improving results. |
| `r.FidelityFX.FSR2.Sharpness` | 0 | 0.0 - 1.0 | When > 0.0, enables Robust Contrast Adaptive Sharpening (RCAS) Filter to sharpen the output image. Disable external FidelityFX-CAS to avoid over-sharpening. |
| `r.FidelityFX.FSR2.AutoExposure` | 0 | 0, 1 | Set to 1 to use FSR 2’s own auto-exposure, otherwise the engine’s auto-exposure is used. |
| `r.FidelityFX.FSR2.HistoryFormat` | 0 | 0, 1 | Bit-depth for history texture. `0` = PF_FloatRGBA (High Quality), `1` = PF_FloatR11G11B10 (Reduced bandwidth). |
| `r.FidelityFX.FSR2.CreateReactiveMask` | 1 | 0, 1 | Generates a mask from SceneColor, GBuffer, SeparateTranslucency & ScreenspaceReflections determining pixel reactivity. |
| `r.FidelityFX.FSR2.ReactiveMaskReflectionScale` | 0.4 | 0.0 - 1.0 | Scales reflection contribution to the reactive mask (controls aliasing on reflective surfaces). |
| `r.FidelityFX.FSR2.ReactiveMaskReflectionLumaBias` | 0 | 0.0 - 1.0 | Biases the reactive mask by the luminance of the reflection. |
| `r.FidelityFX.FSR2.ReactiveMaskRoughnessScale` | 0.15 | 0.0 - 1.0 | Scales the GBuffer roughness as a fallback value for the reactive mask when reflections don't affect a pixel. |
| `r.FidelityFX.FSR2.ReactiveMaskRoughnessBias` | 0.25 | 0.0 - 1.0 | Biases the reactive mask value when screenspace/planar reflections are weak. |
| `r.FidelityFX.FSR2.ReactiveMaskRoughnessMaxDistance` | 6000 | 0.0 - INF | Max distance (world units) for using material roughness to contribute to the reactive mask. |
| `r.FidelityFX.FSR2.ReactiveMaskRoughnessForceMaxDistance` | 0 | 0, 1 | Enable to force the max distance for material roughness instead of using View.FurthestReflectionCaptureDistance. |
| `r.FidelityFX.FSR2.ReactiveMaskTranslucencyBias` | 1 | 0.0 - 1.0 | Scales how much contribution translucency makes to the reactive mask (higher = less reactive = less smearing). |
| `r.FidelityFX.FSR2.ReactiveMaskTranslucencyLumaBias` | 0.8 | 0.0 - 1.0 | Biases translucency contribution by the luminance of the transparency. |
| `r.FidelityFX.FSR2.ReactiveHistoryTranslucencyBias` | 0.5 | 0.0 - 1.0 | Scales how much translucency suppresses history via the reactive mask (higher = more reactive). |
| `r.FidelityFX.FSR2.ReactiveHistoryTranslucencyLumaBias` | 0.0 | 0.0 - 1.0 | Biases how much translucency suppresses history via the reactive mask by transparency luminance. |
| `r.FidelityFX.FSR2.ReactiveMaskPreDOFTranslucencyScale` | 1 | 0.0 - 1.0 | Scales contribution pre-Depth-of-Field translucency color makes to the reactive mask (Removed for UE 5.3). |
| `r.FidelityFX.FSR2.ReactiveMaskPreDOFTranslucencyMax` | 0 | 0, 1 | Toggle to determine logic for pre-Depth-of-Field translucency contribution (Removed for UE 5.3). |
| `r.FidelityFX.FSR2.ReactiveMaskTranslucencyMaxDistance` | 500000 | 0.0 - INF | Max distance for using translucency in the reactive mask (useful to exclude sky-boxes). |
| `r.FidelityFX.FSR2.ReactiveMaskReactiveShadingModelID` | MSM_NUM | 0 - MAX | Treat the specified shading model as reactive, taking the CustomData0.x value as the reactive value. |
| `r.FidelityFX.FSR2.ReactiveMaskForceReactiveMaterialValue`| 0 | 0.0 - 1.0 | Forces the reactive mask value for Reactive Shading Model materials (overrides Material Graph when > 0). |
| `r.FidelityFX.FSR2.ForceVertexDeformationOutputsVelocity` | 1 | 0, 1 | Forces materials with World Position Offset/Displacement to output velocities even when not moved. |
| `r.FidelityFX.FSR2.ForceLandscapeHISMMobility` | 0 | 0, 1, 2 | Forces the mobility of Landscape HISM components that use WPO materials to render valid velocities (1: Faster CPU, 2: Faster GPU). |
| `r.FidelityFX.FSR2.UseSSRExperimentalDenoiser` | 0 | 0, 1 | Uses `r.SSR.ExperimentalDenoiser` when FSR 2 is enabled (required when `CreateReactiveMask` is enabled). |
| `r.FidelityFX.FSR2.UseNativeDX12` | 1 | 0, 1 | Uses FSR 2’s native optimized D3D12 backend (0 to use Unreal's RHI fallback). |
| `r.FidelityFX.FSR2.UseNativeVulkan` | 1 | 0, 1 | Uses FSR 2’s native optimized Vulkan backend (0 to use Unreal's RHI fallback). |
| `r.FidelityFX.FSR2.QuantizeInternalTextures` | 0 | 0, 1 | Rounds up the size of some internal texture to ensure specific divisibility (compatibility only). |
| `r.FidelityFX.FSR2.EnabledInEditorViewport` | 0 | 0, 1 | Enables FSR 2 Temporal Upscale in the Editor viewport by default. |
| `r.FidelityFX.FSR2.DeDither` | 2 | 0, 1, 2 | Enables an extra pass to de-dither rendering before FSR 2 to avoid over-thinning. (0: Off, 1: Full, 2: Hair Only). |

## Key Technical Notes for Implementation
- **World Position Offset:** Materials with WPO need to output velocity. FSR 2 handles this via `r.FidelityFX.FSR2.ForceVertexDeformationOutputsVelocity`. For Landscape Grass/HISM, use `r.FidelityFX.FSR2.ForceLandscapeHISMMobility`.
- **Reactive Mask:** FSR 2 relies heavily on a reactive mask to avoid ghosting (especially for transparent objects and UI). Translucency distances (`r.FidelityFX.FSR2.ReactiveMaskTranslucencyMaxDistance`) should be carefully tweaked so skyboxes don't cause smearing artifacts.
- **De-Dithering:** FSR 2 doesn't naturally smooth dithering like TAA does. Enabling `r.FidelityFX.FSR2.DeDither` (often to `2` for Hair Only) is necessary for high-quality hair rendering.
- **Auto-Exposure:** Use the built-in FSR2 auto-exposure for best results if the engine's auto-exposure is unstable (`r.FidelityFX.FSR2.AutoExposure`).
