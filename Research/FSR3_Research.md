# AMD FidelityFX™ Super Resolution 3 (FSR 3) - Research Data

## Overview
AMD FidelityFX™ Super Resolution 3 (FSR 3) provides an open-source, high-quality solution for producing high-resolution frames from lower-resolution inputs. Additionally, it introduces **Frame Interpolation (Frame Generation)**, which can increase the frame rate up to twice the input rate to improve the smoothness of animations and frame pacing.

## Core Setup & Quality Modes
FSR 3 requires **Temporal Upsampling** to be enabled (`r.TemporalAA.Upsampling = 1`) and the Anti-Aliasing Method must be set to Temporal Super-Resolution (TSR) (`r.AntiAliasingMethod = 4`).

### Quality Modes
The plugin controls the quality mode using `r.FidelityFX.FSR3.QualityMode`, which overrides `r.ScreenPercentage`.
* **Native AA (1.0x):** `r.FidelityFX.FSR3.QualityMode 0` (Superior image quality to native with modest performance cost)
* **Quality (1.5x):** `r.FidelityFX.FSR3.QualityMode 1` (Significant performance gain, quality equal/superior to native)
* **Balanced (1.7x):** `r.FidelityFX.FSR3.QualityMode 2` (Ideal compromise between quality and performance)
* **Performance (2.0x):** `r.FidelityFX.FSR3.QualityMode 3` (Major performance gain, quality similar to native)
* **Ultra Performance (3.0x):** `r.FidelityFX.FSR3.QualityMode 4` (Highest performance gain, quality representative of native)

## Console Variables (CVars)

### General FSR 3 Upscaling CVars
| Console Variable | Default | Range | Details |
|---|---|---|---|
| `r.FidelityFX.FSR3.Enabled` | - | 0, 1 | Enable or disable FSR 3 temporal upscaling. |
| `r.FidelityFX.FSR3.QualityMode` | 1 | 0-4 | Sets the scaling ratio (0: Native AA, 1: Quality, 2: Balanced, 3: Performance, 4: Ultra Performance). |
| `r.FidelityFX.FSR3.AdjustMipBias` | 1 | 0, 1 | Applies negative MipBias to material textures, improving results. |
| `r.FidelityFX.FSR3.Sharpness` | 0 | 0.0 - 1.0 | When > 0.0, enables Robust Contrast Adaptive Sharpening (RCAS) Filter to sharpen the output image. |
| `r.FidelityFX.FSR3.AutoExposure` | 0 | 0, 1 | Set to 1 to use FSR 3’s own auto-exposure, otherwise the engine’s auto-exposure is used. |
| `r.FidelityFX.FSR3.HistoryFormat` | 0 | 0, 1 | Bit-depth for history texture. `0` = PF_FloatRGBA, `1` = PF_FloatR11G11B10. |
| `r.FidelityFX.FSR3.UseSSRExperimentalDenoiser` | 0 | 0, 1 | Uses `r.SSR.ExperimentalDenoiser` when FSR 3 is enabled (required when `CreateReactiveMask` is enabled). |
| `r.FidelityFX.FSR3.UseNativeDX12` | 1 | 0, 1 | Uses FSR 3’s native optimized D3D12 backend. |
| `r.FidelityFX.FSR3.UseRHI` | 0 | 0, 1 | Enable FSR 3’s default RHI backend (fallback if native backend is disabled). |
| `r.FidelityFX.FSR3.QuantizeInternalTextures` | 0 | 0, 1 | Rounds up the size of some internal texture to ensure specific divisibility. |
| `r.FidelityFX.FSR3.EnabledInEditorViewport` | 0 | 0, 1 | Enables FSR 3 Temporal Upscale in the Editor viewport by default. |
| `r.FidelityFX.FSR3.DeDither` | 2 | 0, 1, 2 | Enables an extra pass to de-dither rendering before FSR 3. (0: Off, 1: Full, 2: Hair Only). |

### Reactive Mask CVars
| Console Variable | Default | Range | Details |
|---|---|---|---|
| `r.FidelityFX.FSR3.CreateReactiveMask` | 1 | 0, 1 | Generates a mask from SceneColor, GBuffer, SeparateTranslucency & ScreenspaceReflections determining pixel reactivity. |
| `r.FidelityFX.FSR3.ReactiveMaskReflectionScale` | 0.4 | 0.0 - 1.0 | Scales reflection contribution to the reactive mask. |
| `r.FidelityFX.FSR3.ReactiveMaskReflectionLumaBias` | 0 | 0.0 - 1.0 | Biases the reactive mask by the luminance of the reflection. |
| `r.FidelityFX.FSR3.ReactiveMaskRoughnessScale` | 0.15 | 0.0 - 1.0 | Scales the GBuffer roughness as a fallback value for the reactive mask. |
| `r.FidelityFX.FSR3.ReactiveMaskRoughnessBias` | 0.25 | 0.0 - 1.0 | Biases the reactive mask value when screenspace/planar reflections are weak. |
| `r.FidelityFX.FSR3.ReactiveMaskRoughnessMaxDistance` | 6000 | 0.0 - INF | Max distance (world units) for using material roughness to contribute to the reactive mask. |
| `r.FidelityFX.FSR3.ReactiveMaskRoughnessForceMaxDistance` | 0 | 0, 1 | Enable to force the max distance for material roughness. |
| `r.FidelityFX.FSR3.ReactiveMaskTranslucencyBias` | 1.0 | 0.0 - 1.0 | Scales how much contribution translucency makes to the reactive mask. |
| `r.FidelityFX.FSR3.ReactiveMaskTranslucencyLumaBias` | 0.0 | 0.0 - 1.0 | Biases translucency contribution by the luminance of the transparency. |
| `r.FidelityFX.FSR3.ReactiveHistoryTranslucencyBias` | 0.5 | 0.0 - 1.0 | Scales how much translucency suppresses history via the reactive mask. |
| `r.FidelityFX.FSR3.ReactiveHistoryTranslucencyLumaBias` | 0.0 | 0.0 - 1.0 | Biases how much translucency suppresses history via the reactive mask by transparency luminance. |
| `r.FidelityFX.FSR3.ReactiveMaskPreDOFTranslucencyScale` | 1.0 | 0.0 - 1.0 | Scales contribution pre-Depth-of-Field translucency color makes to the reactive mask. |
| `r.FidelityFX.FSR3.ReactiveMaskPreDOFTranslucencyMax` | 0 | 0, 1 | Toggle logic for pre-Depth-of-Field translucency contribution. |
| `r.FidelityFX.FSR3.ReactiveMaskTranslucencyMaxDistance` | 500000 | 0.0 - INF | Max distance for using translucency in the reactive mask (useful to exclude sky-boxes). |
| `r.FidelityFX.FSR3.ReactiveMaskReactiveShadingModelID` | MSM_NUM | 0 - MAX | Treat the specified shading model as reactive, using CustomData0.x as the value. |
| `r.FidelityFX.FSR3.ReactiveMaskForceReactiveMaterialValue`| 0.0 | 0.0 - 1.0 | Forces the reactive mask value for Reactive Shading Model materials. |
| `r.FidelityFX.FSR3.ReactiveMaskDeferredDecalScale` | 0 | 0.0 - 1.0 | Scales how much deferred decal values contribute to the reactive mask. |
| `r.FidelityFX.FSR3.ReactiveHistoryDeferredDecalScale` | 0 | 0.0 - 1.0 | Scales how much deferred decal values contribute to supressing history. |
| `r.FidelityFX.FSR3.ReactiveMaskTAAResponsiveValue` | 0 | 0.0 - 1.0 | Value to write to reactive mask when pixels are marked in the stencil buffer as TAA Responsive. |
| `r.FidelityFX.FSR3.ReactiveHistoryTAAResponsiveValue` | 0 | 0.0 - 1.0 | Value to write to reactive history when pixels are marked in the stencil buffer as TAA Responsive. |
| `r.FidelityFX.FSR3.ReactiveMaskCustomStencilScale` | 0 | 0.0 - 1.0 | Scales how much custom stencil values contribute to the reactive mask. |
| `r.FidelityFX.FSR3.ReactiveHistoryCustomStencilScale` | 0 | 0.0 - 1.0 | Scales how much custom stencil values contribute to supressing history. |
| `r.FidelityFX.FSR3.CustomStencilMask` | 0 | 0 - 255 | Bitmask used when accessing the custom stencil to read reactive mask values. |
| `r.FidelityFX.FSR3.CustomStencilShift` | 0 | 0 - 31 | Bitshift applied to the value read from the custom stencil. |

### FSR 3 Tuning & Ghosting Mitigation CVars
| Console Variable | Default | Range | Details |
|---|---|---|---|
| `r.FidelityFX.FSR3.VelocityFactor` | 1 | 0.0 - 1.0 | Value of 0.0f can improve temporal stability of bright pixels. |
| `r.FidelityFX.FSR3.ReactivenessScale` | 1 | 0.0 - INF | Testing CVar to check if larger reactive mask values reduce ghosting. |
| `r.FidelityFX.FSR3.ShadingChangeScale` | 1 | 0.0 - INF | Scales FSR3 computed shading change value at read to have higher reactiveness. |
| `r.FidelityFX.FSR3.AccumulationAddedPerFrame` | 0.333 | 0.0 - 1.0 | Amount of accumulation added per frame where disocclusion occurred or reactive mask > 0.0f. |
| `r.FidelityFX.FSR3.MinDisocclutionAccumulation` | -0.333 | -1.0 - 1.0 | Increasing this value may reduce white pixel temporal flickering around swaying thin objects. |
| `r.FidelityFX.FSR3.ForceVertexDeformationOutputsVelocity` | 1 | 0, 1 | Forces materials with World Position Offset/Displacement to output velocities even when not moved. |
| `r.FidelityFX.FSR3.ForceLandscapeHISMMobility` | 0 | 0, 1, 2 | Forces the mobility of Landscape HISM components that use WPO materials to render valid velocities (1: Faster CPU, 2: Faster GPU). |

### Frame Generation CVars (FSR 3.x Exclusive)
| Console Variable | Default | Range | Details |
|---|---|---|---|
| `r.FidelityFX.FI.Enabled` | 1 | 0, 1 | Enable FidelityFX Frame Interpolation. Requires FSR3 Upscaling to be enabled. |
| `r.FidelityFX.FI.OverrideSwapChainDX12` | 1 | 0, 1 | (D3D12 Async Present) Uses FSR3’s D3D12 swap-chain override that improves frame pacing. Fallback is RHI. |
| `r.FidelityFX.FI.AllowAsyncWorkloads` | 1 | 0, 1 | (D3D12 Async Interpolation) Uses async execution of Frame Interpolation (concurrent with next frame). |
| `r.FidelityFX.FI.UIMode` | 0 | 0, 1 | Render method for UI. `0` = Slate Redraw (NativeTick twice). `1` = UI Extraction (decoupled via pre/post frame comparison). |
| `r.FidelityFX.FI.ModifySlateDeltaTime` | 1 | 0, 1 | Sets FSlateApplication delta time to 0.0 when redrawing UI to prevent widgets updating twice incorrectly. |
| `r.FidelityFX.FI.RHIPacingMode` | 0 | 0, 1 | Enable pacing frames for RHI backend. `0` = None, `1` = Custom Present VSync (VSync for second presented frame). |
| `r.FidelityFX.FI.UseDistortionTexture` | 0 | 0, 1 | Enable distortion texture input using Unreal Engine’s distortion texture frame. |
| `r.FidelityFX.FI.CaptureDebugUI` | 1 | 0, 1 | Force detecting and copying debug UI (like Unreal Console) on first invocation of DrawWindow. Disabled in Shipping. |
| `r.FidelityFX.FI.UpdateGlobalFrameTime` | 0 | 0, 1 | Updates GAverageMs/GAverageFPS globals with average frame time/FPS calculated by interpolation code. |
| `r.FidelityFX.FI.ShowDebugTearLines` | 1 | 0, 1 | Show debug tear lines when running Frame Interpolation (Not available in Test/Shipping). |
| `r.FidelityFX.FI.ShowDebugView` | 0 | 0, 1 | Show debug view when running Frame Interpolation (Not available in Test/Shipping). |

## Key Technical Notes for Implementation
- **Custom Stencil for Reactive Mask:** FSR 3 introduced the ability to use Custom Depth/Stencil to mask specific reactive objects (`r.FidelityFX.FSR3.CustomStencilMask`).
- **Frame Generation & UI:** `r.FidelityFX.FI.UIMode` is highly important. When set to **Slate Redraw (0)**, it will invoke `NativeTick` twice. If UI Extraction (1) is used (which is automatically on when Async Workloads is on), it decouples the UI from the generated frame but may have issues with translucent UI.
- **Async DX12 Swapchain:** `r.FidelityFX.FI.OverrideSwapChainDX12` is the golden path for frame pacing and async workloads. RHI backend only provides basic serial interpolation.
- **Upscaling Dependency:** Frame Generation CANNOT run without FSR 3 Upscaling enabled (unlike FSR 4 / FSR Upscaling plugin where they are independent).
- **Anti-Lag 2:** Built-in support was added in version 3.1.1.
