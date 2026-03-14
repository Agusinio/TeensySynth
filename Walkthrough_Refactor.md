# F32 Audio Migration Walkthrough

The project has now been migrated from the standard 16-bit integer `Teensy Audio Library` to the high-resolution `OpenAudio_ArduinoLibrary`. This prevents any internal digital clipping or quantization noise buildup when blending multiple voices or using highly resonant filters.

## Changes Completed

1. **Library Inclusion:**
   Added the required header for 32-bit F32 Audio.
   `#include <OpenAudio_ArduinoLibrary.h>`

2. **Declaration Refactoring (`a_globals.ino`):**
   *   All generators (`AudioSynthWaveform` -> `AudioSynthWaveform_F32`)
   *   Envelopes (`AudioEffectEnvelope_F32`)
   *   Filtros (`AudioFilterStateVariable_F32`)
   *   Efectos y Mixers (`AudioEffectDelay_F32`, `AudioMixer4_F32`)
   *   Internal patchcords (`AudioConnection_F32`)

3. **Bridging Floating Point to Final Output:**
   Because the real-world DAC codec (I2S connection) natively speaks 16-bit integer format, two fast converters were placed right before outputting the final mix:
   ```cpp
   AudioConvert_F32toI16 convL;
   AudioConvert_F32toI16 convR;
   ```
   The final L/R 32-bit mixing lines were connected to these blocks, which then feed the `i2s1` output via a standard 16-bit `AudioConnection`.

4. **Memory Allocation (`b_setup.ino`):**
   The F32 objects use their own specialized memory blocks. Configured it to set aside enough memory blocks to smoothly execute up to 300 concurrent floating-point Audio operations.
   ```cpp
   AudioMemory(20);         // Minimum needed for I2S handling
   AudioMemory_F32(300);    // Core F32 Engine memory allowance
   ```

## Array-Based 10-Voice Polyphony
The project now completely supports a dynamic, expandable **10-voice polyphony** utilizing arrays instead of discrete variable instances. 
- Code bloat was stripped out: Variables like `vcoA1` to `vcoA6` were consolidated into elegant C++ Object Arrays `vcoA[10]`, saving hundreds of lines of code.
- **Round-Robin & Voice Stealing**: The system automatically distributes fresh MIDI notes uniformly to free voices. If all `10` voices are sounding simultaneously, the system seamlessly steals the oldest sounding voice to play the new note, preventing ignored keystrokes.
- **Dynamic Pointers**: Internally, `AudioConnection_F32` patches use memory pointers instantiated at setup dynamically, keeping CPU demands structured.

## Final Steps for the User
For the code to compile successfully in your IDE, please verify that you have downloaded and installed the `OpenAudio_ArduinoLibrary` (either manually from GitHub or via Library Manager in Arduino IDE).
Since we have scaled the application memory needs, ensure `Tools -> Optimize -> Faster` is selected when compiling for the Teensy 4.2 to guarantee maximum code performance footprint.
