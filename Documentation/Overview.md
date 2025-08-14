# FSR3 + FSR-Mobile Blueprint Control – Documentation

## Overview
The **FSR3 + FSR-Mobile Blueprint Control** plugin allows you to fully control AMD FidelityFX™ Super Resolution 3 (FSR3) and FSR-Mobile directly from Blueprints.  
This enables runtime adjustments, in-game settings menus, dynamic performance scaling, and debugging without touching console commands or config files.

> **Note:** Saving and loading settings is supported **only for Windows FSR3**.

---

## Features

### FSR3 – Super Resolution (Windows)
- Enable/Disable FSR3 Upscaling
- Switch between quality modes (Native, Quality, Balanced, Performance, Ultra Performance)
- Adjust Sharpness
- Enable/Disable DeDither for hair/dither smoothing
- Modify History Format
- Control Reactiveness Scale for ghosting reduction
- Enable/Disable Auto Exposure
- Check/Set Rendering Backend

**Blueprint Functions:**
![b201b804-24a4-4d17-8df6-d7262801d4ea](https://github.com/user-attachments/assets/31310925-b7d6-4d5f-88bd-3aa59e424619)


---

### FSR3 – Frame Generation (Windows)
- Enable/Disable Frame Generation
- Switch FG Mode at runtime
- Control UI Render Mode
- Enable Async Present for improved frame pacing
- Show Debug View and Tear Lines
- Capture Debug UI in runtime

**Blueprint Functions:**
![5a451b12-1f43-4506-80be-fdc6f6a2292e](https://github.com/user-attachments/assets/380b62ae-0440-4a6f-a49d-09a33751ffb8)

![f4b9c082-96f0-4e9e-817b-a4ca92d5a5dc](https://github.com/user-attachments/assets/2daa00b7-bf21-4cb6-b917-2e3ac3a00fad)



---

### FSR-Mobile (Mobile Platforms)
- Enable/Disable FSR-Mobile Upscaling
- Adjust Sharpness
- Enable/Disable Denoise
- Enable/Disable Compute Mode for optimization
- Toggle and check Upsampling state

**Blueprint Functions:**
![61451420-1af9-4d9d-a1b0-c053ebc5c47a](https://github.com/user-attachments/assets/bda8386c-a01e-4e21-9fae-6dd158a1b7e5)


---

## Installation
1. Copy the plugin to your project's `Plugins` folder.
2. Enable it from **Edit → Plugins**.
3. Restart Unreal Engine.
4. All FSR3 and FSR-Mobile Blueprint nodes will be available under **AMD FidelityFX™** categories.

---

## Notes
- **Windows:** Supports both FSR3 Upscaling and Frame Generation.
- **Mobile:** Supports FSR-Mobile upscaling and optimizations.
- **SaveGame Support:** Only available for Windows builds with FSR3.

---
