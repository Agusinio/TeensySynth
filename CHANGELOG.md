# Changelog

## [Unreleased]
### Changed
- **Architecture Refactoring for Polyphony:**
  - Encapsulated all per-voice audio components and patch cords into a new `Voice` struct.
  - Replaced individual global array declarations (e.g., `AudioSynthWaveform_F32 lfoA[NUM_VOICES];`) with a unified array: `Voice voices[NUM_VOICES];`.
  - Refactored all component array accesses across `.ino` files (from `vcoA[i]` to `voices[i].vcoA`).
  - Renamed the global integer counter from `int voices` to `int activeVoices` to resolve naming conflicts with the newly created `voices` array.
  - Ensure correct array boundary and instantiation within `setup()`.
