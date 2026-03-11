// Falta: Toogles para selector de Ondas y sus leds correspondientes
//        SetUp filtros primarios
//        SetUp Mixers Primarios
//        SetUp Reverb?
//        Comprovar y arreglar MUXES con los nuevos mandos

// Requires 'MIDI Library by Forty Seven Effects'
// Install in Arduino IDE using 'Sketch/Include Library/Manage Libraries'

#include <Audio.h>
#include <SPI.h>
#include <Wire.h>
// #include <SD.h>
#include <MIDI.h>
#include <SerialFlash.h>

// Mux Pins
#define MS0 A2 // Pin 17//
#define MS1 A3 // Pin 20//
#define MS2 A6 // Pin 8//
#define MS3 A7 // Pin 21//
#define MZ 8   // Pin 16//
// Quedan libres, creo,los pines:24,25,26,27 (28 RX7) y 38,39,40,41 (34 RX8)
// #define MS0_2 A10
// #define MS1_2 A11
// #define MS2_2 A12
// #define MS3_2 A13
#define MZ_2 28

// #define MS0_3 A14
// #define MS1_3 A15
// #define MS2_3 A16
// #define MS3_3 A17
#define MZ_3 34

#define MnumControls 45

#define MUX_Osc1Lvl 0
#define MUX_Osc1Shape 1
#define MUX_Osc1ShapeAdj 2
#define MUX_Octave 3
#define MUX_AddNoise1Lvl 4
#define MUX_Attack1 5
#define MUX_Decay1 6
#define MUX_Sustain1 7
#define MUX_Release1 8
#define MUX_FilterHF1 9
#define MUX_FilterHRes1 10

#define MUX_Osc2Lvl 11
#define MUX_Osc2Shape 12
#define MUX_Osc2ShapeAdj 13
#define MUX_Detune 14
#define MUX_DetuneFine 15

#define MUX_AddNoise2Lvl 16
#define MUX_Attack2 17
#define MUX_Decay2 18
#define MUX_Sustain2 19
#define MUX_Release2 20
#define MUX_FilterHF2 21
#define MUX_FilterHRes2 22

#define MUX_NoiseLvl 21
#define MUX_NoiseAttack 22
#define MUX_NoiseDecay 23
#define MUX_NoiseSustain 24
#define MUX_NoiseRelease 25
#define MUX_NoiseFilterQ 26
#define MUX_NoiseFilterHFreq 27
#define MUX_NoiseFilterLFreq 28

#define MUX_AMShape 29
#define MUX_AMDepth 30
#define MUX_AMSpeed 31
#define MUX_AMENV_delay 32

#define MUX_AMENV_attack 33
#define MUX_AMENV_release 34
#define MUX_FMShape 35
#define MUX_FMDepth 36
#define MUX_FMSpeed 37
#define MUX_FMENV_delay 38
#define MUX_FMENV_attack 39
#define MUX_FMENV_release 40
#define MUX_LFOShape 41
// #define MUXChorVoices 42
#define MUX_RevLvl 41
#define MUX_RevRoom 42
#define MUX_RevHum 43

// Switch pin numbers
// #define numSwitch 3
// #define SWosc1 2
// #define SWosc2 3
#define SW_LFO 45

// MIDI CC control numbers
#define CCOsc1Lvl 100
#define CCOsc1Shape 101
#define CCOsc1ShapeAdj 102
#define CCOsc1Octave 103
#define CCOsc1AddNoise 104
#define CCOsc1Att 105
#define CCOsc1Dec 106
#define CCOsc1Sust 107
#define CCOsc1Rel 108
#define CCOscHF 109
#define CCOscHRes 110

#define CCOsc2Lvl 111
#define CCOsc2Shape 112
#define CCOsc2ShapeAdj 113
#define CCOsc2Detune 114
#define CCOsc2DetFine 115
#define CCOsc2AddNoise 116
#define CCOsc2Att 117
#define CCOsc2Dec 118
#define CCOsc2Sust 119
#define CCOsc2Rel 120
#define CCOsc2HF 121
#define CCOsc2HRes 122

#define CCNoiseLvl 123
#define CCNoiseAtt 124
#define CCNoiseDec 125
#define CCNoiseSust 126
#define CCNoiseRel 127
#define CCNoiseFilterQ 128
#define CCNoiseHFreq 129
#define CCNoiseLFreq 130
#define CC_AMShape 131
#define CC_AMDepth 132
#define CC_AMSpeed 133
#define CC_AMENV_delay 134
#define CC_AMENV_attack 135
#define CC_AMENV_release 136
#define CC_FMShape 137
#define CC_FMDepth 138
#define CC_FMSpeed 139
#define CC_FMENV_delay 140
#define CC_FMENV_attack 141
#define CC_FMENV_release 142

#define CC_LFOShape 141
// #define CCChorVoic 142
#define CCRevLvl 143
#define CCRevRoom 144
#define CCRevHum 145

// Number of samples in each delay line
// #define CHORUS_DELAY_LENGTH (16*AUDIO_BLOCK_SAMPLES)

// GUItool: begin automatically generated code
AudioSynthWaveform W_4AM_R;        // xy=101,352
AudioSynthWaveform W_4FM_L;        // xy=103,244
AudioSynthWaveform W_4AM_L;        // xy=105,160
AudioSynthWaveform W_4FM_R;        // xy=104,434
AudioEffectEnvelope ENV_FM_R;      // xy=286,434
AudioEffectEnvelope ENV_AM_R;      // xy=290,352
AudioEffectEnvelope ENV_FM_L;      // xy=307.28570556640625,247.42857551574707
AudioEffectEnvelope ENV_AM_L;      // xy=327.42855072021484,145.99999809265137
AudioSynthWaveform W_Osc2_L;       // xy=437,539
AudioSynthNoisePink W_NoiseOsc2_L; // xy=442,615
AudioSynthWaveform W_Osc2_R;       // xy=447,700
AudioSynthNoisePink W_NoiseOsc2_R; // xy=451,790
AudioSynthNoisePink W_Noise_L;     // xy=460,926
AudioSynthNoisePink W_Noise_R;     // xy=461,1022
AudioSynthWaveformModulated W_Osc1_R; // xy=524,444
AudioSynthWaveformModulated W_Osc1_L; // xy=577.7142562866211,280.5714159011841
AudioEffectMultiply MOD_AM_R;         // xy=680,366
AudioEffectMultiply MOD_AM_L;         // xy=735.7142944335938,146.9999942779541
AudioFilterStateVariable FIL_NoiseEQH_L; // xy=747,923
AudioFilterStateVariable FIL_NoiseEQH_R; // xy=751,1075
AudioSynthNoisePink W_NoiseOsc1_R;       // xy=802,447
AudioSynthNoisePink W_NoiseOsc1_L;       // xy=814,250
AudioFilterStateVariable
    FIL_NoiseEQL_L; // xy=1017.0000152587891,914.2500190734863
AudioFilterStateVariable
    FIL_NoiseEQL_R;              // xy=1024.750015258789,1063.750015258789
AudioMixer4 MIX_Osc1AddNoise_L;  // xy=1055,157
AudioMixer4 MIX_Osc1AddNoise_R;  // xy=1057,380
AudioMixer4 MIX_Osc2AddNoise_L;  // xy=1063,559
AudioMixer4 MIX_Osc2AddNoise_R;  // xy=1068,684
AudioEffectEnvelope ENV_Osc1_L;  // xy=1343,158
AudioEffectEnvelope ENV_Osc1_R;  // xy=1363,377
AudioEffectEnvelope ENV_Osc2_L;  // xy=1366,553
AudioEffectEnvelope ENV_Noise_L; // xy=1367.2500228881836,892.5000133514404
AudioEffectEnvelope ENV_Osc2_R;  // xy=1370,688
AudioEffectEnvelope ENV_Noise_R; // xy=1369,1069
AudioMixer4 MIX_Osc_R;           // xy=1674,797
AudioMixer4 MIX_Osc_L;           // xy=1675,690
AudioMixer4 MIX_2Reverb_L;       // xy=2063,383
AudioMixer4 MIX_2Reverb_R;       // xy=2079,794
AudioFilterLadder FILMoog_L;     // xy=2234,268
AudioFilterLadder FILMoog_R;     // xy=2233,918
AudioEffectEnvelope ENV_Final_L; // xy=2362,427
AudioEffectEnvelope ENV_Final_R; // xy=2393,773
AudioEffectFreeverbStereo RVR_Final_L; // xy=2403,542
AudioEffectFreeverbStereo RVR_Final_R; // xy=2411,675
AudioMixer4 MIX_Final_L;               // xy=2634,481
AudioMixer4 MIX_Final_R;               // xy=2652,786
AudioOutputI2S2 i2s2_1;                // xy=2684,602
AudioConnection patchCord1(W_4AM_R, ENV_AM_R);
AudioConnection patchCord2(W_4FM_L, ENV_FM_L);
AudioConnection patchCord3(W_4AM_L, ENV_AM_L);
AudioConnection patchCord4(W_4FM_R, ENV_FM_R);
AudioConnection patchCord5(ENV_FM_R, 0, W_Osc1_R, 0);
AudioConnection patchCord6(ENV_AM_R, 0, MOD_AM_R, 0);
AudioConnection patchCord7(ENV_FM_L, 0, W_Osc1_L, 0);
AudioConnection patchCord8(ENV_AM_L, 0, MOD_AM_L, 0);
AudioConnection patchCord9(W_Osc2_L, 0, MIX_Osc2AddNoise_L, 0);
AudioConnection patchCord10(W_NoiseOsc2_L, 0, MIX_Osc2AddNoise_L, 1);
AudioConnection patchCord11(W_Osc2_R, 0, MIX_Osc2AddNoise_R, 0);
AudioConnection patchCord12(W_NoiseOsc2_R, 0, MIX_Osc2AddNoise_R, 1);
AudioConnection patchCord13(W_Noise_L, 0, FIL_NoiseEQH_L, 0);
AudioConnection patchCord14(W_Noise_R, 0, FIL_NoiseEQH_R, 0);
AudioConnection patchCord15(W_Osc1_R, 0, MOD_AM_R, 1);
AudioConnection patchCord16(W_Osc1_L, 0, MOD_AM_L, 1);
AudioConnection patchCord17(MOD_AM_R, 0, MIX_Osc1AddNoise_R, 0);
AudioConnection patchCord18(MOD_AM_L, 0, MIX_Osc1AddNoise_L, 0);
AudioConnection patchCord19(FIL_NoiseEQH_L, 2, FIL_NoiseEQL_L, 0);
AudioConnection patchCord20(FIL_NoiseEQH_R, 2, FIL_NoiseEQL_R, 0);
AudioConnection patchCord21(W_NoiseOsc1_R, 0, MIX_Osc1AddNoise_R, 1);
AudioConnection patchCord22(W_NoiseOsc1_L, 0, MIX_Osc1AddNoise_L, 1);
AudioConnection patchCord23(FIL_NoiseEQL_L, 2, ENV_Noise_L, 2);
AudioConnection patchCord24(FIL_NoiseEQL_R, 0, ENV_Noise_R, 0);
AudioConnection patchCord25(MIX_Osc1AddNoise_L, ENV_Osc1_L);
AudioConnection patchCord26(MIX_Osc1AddNoise_R, ENV_Osc1_R);
AudioConnection patchCord27(MIX_Osc2AddNoise_L, ENV_Osc2_L);
AudioConnection patchCord28(MIX_Osc2AddNoise_R, ENV_Osc2_R);
AudioConnection patchCord29(ENV_Osc1_L, 0, MIX_Osc_L, 0);
AudioConnection patchCord30(ENV_Osc1_R, 0, MIX_Osc_R, 0);
AudioConnection patchCord31(ENV_Osc2_L, 0, MIX_Osc_L, 1);
AudioConnection patchCord32(ENV_Noise_L, 0, MIX_2Reverb_L, 1);
AudioConnection patchCord33(ENV_Osc2_R, 0, MIX_Osc_L, 1);
AudioConnection patchCord34(ENV_Noise_R, 0, MIX_2Reverb_R, 1);
AudioConnection patchCord35(MIX_Osc_R, 0, MIX_2Reverb_R, 0);
AudioConnection patchCord36(MIX_Osc_L, 0, MIX_2Reverb_L, 0);
AudioConnection patchCord37(MIX_2Reverb_L, 0, FILMoog_L, 0);
AudioConnection patchCord38(MIX_2Reverb_R, 0, FILMoog_R, 0);
AudioConnection patchCord39(FILMoog_L, ENV_Final_L);
AudioConnection patchCord40(FILMoog_R, ENV_Final_R);
AudioConnection patchCord41(ENV_Final_L, 0, MIX_Final_L, 0);
AudioConnection patchCord42(ENV_Final_L, RVR_Final_L);
AudioConnection patchCord43(ENV_Final_R, 0, MIX_Final_R, 0);
AudioConnection patchCord44(ENV_Final_R, RVR_Final_R);
AudioConnection patchCord45(RVR_Final_L, 0, MIX_Final_L, 1);
AudioConnection patchCord46(RVR_Final_L, 1, MIX_Final_R, 2);
AudioConnection patchCord47(RVR_Final_R, 0, MIX_Final_L, 2);
AudioConnection patchCord48(RVR_Final_R, 1, MIX_Final_R, 1);
AudioConnection patchCord49(MIX_Final_L, 0, i2s2_1, 0);
AudioConnection patchCord50(MIX_Final_R, 0, i2s2_1, 1);
AudioControlSGTL5000 sgtl5000_1; // xy=2086,1057
// GUItool: end automatically generated code

// GLOBAL VARIABLES
const byte BUFFER = 8; // Size of keyboard buffer
const float noteFreqs[128] = {
    8.176,    8.662,    9.177,    9.723,    10.301,   10.913,   11.562,
    12.25,    12.978,   13.75,    14.568,   15.434,   16.352,   17.324,
    18.354,   19.445,   20.602,   21.827,   23.125,   24.5,     25.957,
    27.5,     29.135,   30.868,   32.703,   34.648,   36.708,   38.891,
    41.203,   43.654,   46.249,   48.999,   51.913,   55,       58.27,
    61.735,   65.406,   69.296,   73.416,   77.782,   82.407,   87.307,
    92.499,   97.999,   103.826,  110,      116.541,  123.471,  130.813,
    138.591,  146.832,  155.563,  164.814,  174.614,  184.997,  195.998,
    207.652,  220,      233.082,  246.942,  261.626,  277.183,  293.665,
    311.127,  329.628,  349.228,  369.994,  391.995,  415.305,  440,
    466.164,  493.883,  523.251,  554.365,  587.33,   622.254,  659.255,
    698.456,  739.989,  783.991,  830.609,  880,      932.328,  987.767,
    1046.502, 1108.731, 1174.659, 1244.508, 1318.51,  1396.913, 1479.978,
    1567.982, 1661.219, 1760,     1864.655, 1975.533, 2093.005, 2217.461,
    2349.318, 2489.016, 2637.02,  2793.826, 2959.955, 3135.963, 3322.438,
    3520,     3729.31,  3951.066, 4186.009, 4434.922, 4698.636, 4978.032,
    5274.041, 5587.652, 5919.911, 6271.927, 6644.875, 7040,     7458.62,
    7902.133, 8372.018, 8869.844, 9397.273, 9956.063, 10548.08, 11175.3,
    11839.82, 12543.85};
byte globalNote = 0;
byte globalVelocity = 0;
int octave = 0;
// int octave2 = 0;
const float DIV127 = (1.0 / 127.0);
int detune = 0;
float detuneFactor = 1;
// float bendFactor = 1;
// int bendRange = 12;

unsigned int LFOspeed = 2000;
float LFOpitch = 1;
float LFOdepth = 0;
byte LFOmodeSelect = 0;

int FILfreq = 10000;
float FILfactor = 1;

byte Osc1Mode = 255; // 255 = Nonsense value to force startup read
byte Osc2Mode = 255;
/*
short HL_delayline = CHORUS_DELAY_LENGTH;
short ML_delayline = CHORUS_DELAY_LENGTH;
short LL_delayline = CHORUS_DELAY_LENGTH;
short HR_delayline = CHORUS_DELAY_LENGTH;
short MR_delayline = CHORUS_DELAY_LENGTH;
short LR_delayline = CHORUS_DELAY_LENGTH;
int voices = 3;
*/
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
// USBMIDI_CREATE_DEFAULT_INSTANCE();
// MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {

  Serial.begin(9600);
  AudioMemory(40);

  /*pinMode(SWosc1, INPUT_PULLUP);
    pinMode(SWosc2, INPUT_PULLUP);
    pinMode(SWlfo, INPUT_PULLUP);
  */
  pinMode(MS0, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);
  // pinMode(MS0_2, OUTPUT);
  // pinMode(MS1_2, OUTPUT);
  // pinMode(MS2_2, OUTPUT);
  // pinMode(MS3_2, OUTPUT);
  // pinMode(MS0_3, OUTPUT);
  // pinMode(MS1_3, OUTPUT);
  // pinMode(MS2_3, OUTPUT);
  // pinMode(MS3_3, OUTPUT);

  MIDI.begin();

  MIDI.setHandleNoteOn(myNoteOn);
  MIDI.setHandleNoteOff(myNoteOff);
  // MIDI.setHandlePitchBend(myPitchBend);
  MIDI.setHandleControlChange(myControlChange);

  // usbMIDI.setHandleControlChange(myControlChange);
  // usbMIDI.setHandleNoteOff(myNoteOff);
  // usbMIDI.setHandleNoteOn(myNoteOn);
  // usbMIDI.setHandlePitchChange(myPitchBend);

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);

  // SetUp AM Waves & ENV
  W_4AM_L.begin(WAVEFORM_SINE);
  W_4AM_L.amplitude(0.1);
  W_4AM_L.frequency(0.5);
  // W_4AM_L.pulseWidth(0.5);
  W_4AM_R.begin(WAVEFORM_SINE);
  W_4AM_R.amplitude(0.1);
  W_4AM_R.frequency(0.5);
  // W_4AM_R.pulseWidth(0.5);
  W_4AM_R.phase(90);

  ENV_AM_L.delay(0);
  ENV_AM_L.attack(0.15);
  ENV_AM_L.release(500);
  ENV_AM_R.delay(0);
  ENV_AM_R.attack(0.15);
  ENV_AM_R.release(500);

  // SetUp FM Waves&Env
  W_4FM_L.begin(WAVEFORM_SINE);
  W_4FM_L.amplitude(0.1);
  W_4FM_L.frequency(0.5);
  W_4FM_R.begin(WAVEFORM_SINE);
  W_4FM_R.amplitude(0.1);
  W_4FM_R.frequency(0.5);
  W_4FM_R.phase(90);

  ENV_FM_L.delay(0);
  ENV_FM_L.attack(0.15);
  ENV_FM_L.release(500);
  ENV_FM_R.delay(0);
  ENV_FM_R.attack(0.15);
  ENV_FM_R.release(500);

  // SetUp Osc's & Noise Waves
  W_Osc1_L.begin(WAVEFORM_SAWTOOTH);
  W_Osc1_L.amplitude(1);
  W_Osc1_L.frequency(0);
  // W_Osc1_L.pulseWidth(0.5);
  // W_Osc1_L.phaseModulation(90);
  W_Osc1_R.begin(WAVEFORM_SAWTOOTH);
  W_Osc1_R.amplitude(1);
  W_Osc1_R.frequency(0);
  // W_Osc1_R.pulseWidth(0.5);
  // W_Osc1_R.phase(90);

  W_Osc2_L.begin(WAVEFORM_SINE);
  W_Osc2_L.amplitude(1);
  W_Osc2_L.frequency(0);
  // W_Osc2_L.pulseWidth(0.5);
  W_Osc2_R.begin(WAVEFORM_SINE);
  W_Osc2_R.amplitude(1);
  W_Osc2_R.frequency(0);
  // W_Osc2_R.pulseWidth(0.5);
  // W_Osc2_R.phase(90);

  W_NoiseOsc1_L.amplitude(1);
  W_NoiseOsc1_R.amplitude(1);

  W_NoiseOsc2_L.amplitude(1);
  W_NoiseOsc2_R.amplitude(1);

  W_Noise_L.amplitude(1);
  W_Noise_R.amplitude(1);

  // SetUp Osc's & Noise MIX

  MIX_Osc1AddNoise_L.gain(0, 1);
  MIX_Osc1AddNoise_L.gain(1, 0);
  MIX_Osc1AddNoise_R.gain(0, 1);
  MIX_Osc1AddNoise_R.gain(1, 0);
  MIX_Osc2AddNoise_L.gain(0, 1);
  MIX_Osc2AddNoise_L.gain(1, 0);
  MIX_Osc2AddNoise_R.gain(0, 1);
  MIX_Osc2AddNoise_R.gain(1, 0);

  // SetUp NoiseEQ Filter

  FIL_NoiseEQH_L.frequency(8000);
  FIL_NoiseEQH_L.octaveControl(1);
  FIL_NoiseEQH_L.resonance(0);
  FIL_NoiseEQH_R.frequency(8000);
  FIL_NoiseEQH_R.octaveControl(1);
  FIL_NoiseEQH_R.resonance(0);
  FIL_NoiseEQL_L.frequency(8000);
  FIL_NoiseEQL_L.octaveControl(1);
  FIL_NoiseEQL_L.resonance(0);
  FIL_NoiseEQL_R.frequency(8000);
  FIL_NoiseEQL_R.octaveControl(1);
  FIL_NoiseEQL_R.resonance(0);

  // SetUp Osc's & Noise ENV
  ENV_Osc1_L.attack(0);
  ENV_Osc1_L.decay(0);
  ENV_Osc1_L.sustain(1);
  ENV_Osc1_L.release(500);
  ENV_Osc1_R.attack(0);
  ENV_Osc1_R.decay(0);
  ENV_Osc1_R.sustain(1);
  ENV_Osc1_R.release(500);

  ENV_Osc2_L.attack(0);
  ENV_Osc2_L.decay(0);
  ENV_Osc2_L.sustain(1);
  ENV_Osc2_L.release(500);
  ENV_Osc2_R.attack(0);
  ENV_Osc2_R.decay(0);
  ENV_Osc2_R.sustain(1);
  ENV_Osc2_R.release(500);

  ENV_Noise_L.attack(0);
  ENV_Noise_L.decay(0);
  ENV_Noise_L.sustain(1);
  ENV_Noise_L.release(500);
  ENV_Noise_R.attack(0);
  ENV_Noise_R.decay(0);
  ENV_Noise_R.sustain(1);
  ENV_Noise_R.release(500);

  // SetUp Final Processing
  MIX_Osc_L.gain(0, 0.5);
  MIX_Osc_L.gain(1, 0.5);
  MIX_Osc_R.gain(0, 0.5);
  MIX_Osc_R.gain(1, 0.5);

  MIX_2Reverb_L.gain(0, 1);
  MIX_2Reverb_L.gain(1, 0);
  MIX_2Reverb_R.gain(0, 1);
  MIX_2Reverb_R.gain(1, 0);

  FILMoog_L.frequency(8000);
  FILMoog_L.octaveControl(7);
  FILMoog_L.resonance(0);
  FILMoog_R.frequency(8000);
  FILMoog_R.octaveControl(7);
  FILMoog_R.resonance(0);

  ENV_Final_L.attack(0.15);
  ENV_Final_L.decay(0);
  ENV_Final_L.sustain(1);
  ENV_Final_L.release(500);
  ENV_Final_R.attack(0.15);
  ENV_Final_R.decay(0);
  ENV_Final_R.sustain(1);
  ENV_Final_R.release(500);

  RVR_Final_L.roomsize(0);
  RVR_Final_L.damping(0);
  RVR_Final_R.roomsize(0);
  RVR_Final_R.damping(0);

  MIX_Final_L.gain(0, 1.0);
  MIX_Final_L.gain(1, 0);
  MIX_Final_L.gain(2, 0);
  MIX_Final_R.gain(0, 1.0);
  MIX_Final_R.gain(1, 0);
  MIX_Final_R.gain(2, 0);
}

void loop() {
  // usbMIDI.read();
  MIDI.read();
  LFOupdate(false, LFOmodeSelect, FILfactor, LFOdepth);
  checkMux();
}

void myNoteOn(byte channel, byte note, byte velocity) {
  if (note > 23 && note < 108) {
    globalNote = note;
    globalVelocity = velocity;
    keyBuff(note, true);
    //    LFOupdate(true, LFOmodeSelect, FILfactor, LFOdepth);
  }
}

void myNoteOff(byte channel, byte note, byte velocity) {
  if (note > 23 && note < 108) {
    keyBuff(note, false);
  }
}
/*
  void myPitchBend(byte channel, int bend) {
  float bendF = bend;
  bendF = bendF / 8192;
  bendF = bendF * bendRange;
  bendF = bendF / 12;
  bendFactor = pow(2, bendF);
  oscSet();
  }
*/
void keyBuff(byte note, bool playNote) {
  static byte buff[BUFFER];
  static byte buffSize = 0;

  // Add Note
  if (playNote == true && (buffSize < BUFFER)) {
    oscPlay(note);
    buff[buffSize] = note;
    buffSize++;
    return;
  }

  // Remove Note
  else if (playNote == false && buffSize != 0) {
    for (byte found = 0; found < buffSize; found++) {
      if (buff[found] == note) {
        for (byte gap = found; gap < (buffSize - 1); gap++) {
          buff[gap] = buff[gap + 1];
        }
        buffSize--;
        buff[buffSize] = 255;
        if (buffSize != 0) {
          oscPlay(buff[buffSize - 1]);
          return;
        } else {
          osc1Stop();
          osc2Stop();
          // PinkStop();
          // EnvFinalStop();
          return;
        }
      }
    }
  }
}

void oscPlay(byte note) {
  // Cambiar esto para que el calculo sea solo una vez
  float Osc1Freq = (noteFreqs[note + octave] * LFOpitch); /** bendFactor */
  float Osc2Freq = (noteFreqs[note + octave + detune] * detuneFactor *
                    LFOpitch); /* bendFactor*/
  W_Osc1_L.frequency(Osc1Freq);
  W_Osc1_R.frequency(Osc1Freq);
  W_Osc2_L.frequency(Osc2Freq);
  W_Osc2_R.frequency(Osc2Freq);
  float velo = (0.75 * (globalVelocity * DIV127)); // TEST velocity limit to
                                                   // 0.75
  W_Osc1_L.amplitude(velo);
  W_Osc1_R.amplitude(velo);
  W_Osc2_L.amplitude(velo);
  W_Osc2_R.amplitude(velo);
  W_NoiseOsc1_L.amplitude(velo);
  W_NoiseOsc1_R.amplitude(velo);
  W_NoiseOsc2_L.amplitude(velo);
  W_NoiseOsc2_R.amplitude(velo);
  W_Noise_L.amplitude(velo);
  W_Noise_R.amplitude(velo);
  // ENVFinal_L.releaseNoteOn(5);//TEST
  ENV_AM_L.noteOn();
  ENV_AM_R.noteOn();
  ENV_FM_L.noteOn();
  ENV_FM_R.noteOn();
  ENV_Osc1_L.noteOn();
  ENV_Osc1_R.noteOn();
  ENV_Osc2_L.noteOn();
  ENV_Osc2_R.noteOn();
  ENV_Noise_L.noteOn();
  ENV_Noise_R.noteOn();
  ENV_Final_L.noteOn();
  ENV_Final_R.noteOn();
}

void osc1Stop() {
  ENV_Osc1_L.noteOff();
  ENV_Osc1_R.noteOff();
  // ENV_Osc2_L.noteOff();
  // ENV_Osc2_R.noteOff();
  // ENV_Noise_L.noteOff();
  // ENV_Noise_R.noteOff();
}

void osc2Stop() {
  // ENV_Osc1_L.noteOff();
  // ENV_Osc1_R.noteOff();
  ENV_Osc2_L.noteOff();
  ENV_Osc2_R.noteOff();
  // ENV_Noise_L.noteOff();
  // ENV_Noise_R.noteOff();
}
/*
void EnvFinalStop() {
  ENV_Final_L.noteOff();
  ENV_Final_R.noteOff();
}

*/
void oscSet(byte note) {
  // Cambiar esto para que el calculo sea solo una vez
  float Osc1Freq = (noteFreqs[note + octave] * LFOpitch); /** bendFactor * */
  float Osc2Freq = (noteFreqs[note + octave + detune] * detuneFactor *
                    LFOpitch); /** bendFactor*/
  W_Osc1_L.frequency(Osc1Freq);
  W_Osc1_R.frequency(Osc1Freq);
  W_Osc2_L.frequency(Osc2Freq);
  W_Osc2_R.frequency(Osc2Freq);
}

void myControlChange(byte channel, byte control, byte value) {
  switch (control) {

  case CCOsc1Lvl: { // Varia Gain a
    float Osc1GainValue = (value * DIV127);
    W_Osc1_L.amplitude(Osc1GainValue); // TEST gain limit to 0.3
    W_Osc1_R.amplitude(Osc1GainValue);
  } break;

  case CCOsc1Shape:
    switch (value) {

    case 0:
      osc1Stop();
      break;
    case 1:
      // oscPlay(note);
      W_Osc1_L.begin(WAVEFORM_SINE);
      W_Osc1_R.begin(WAVEFORM_SINE);
      Osc1Mode = 0;
      break;
    case 2:
      // oscPlay(note);
      W_Osc1_L.begin(WAVEFORM_TRIANGLE);
      W_Osc1_R.begin(WAVEFORM_TRIANGLE);
      Osc1Mode = 1;
      break;
    case 3:
      W_Osc1_L.begin(WAVEFORM_PULSE);
      W_Osc1_R.begin(WAVEFORM_PULSE);
      Osc1Mode = 2;
      break;
    case 4:
      W_Osc1_L.begin(WAVEFORM_ARBITRARY);
      W_Osc1_R.begin(WAVEFORM_ARBITRARY);
      Osc1Mode = 3;
      break;
    }
    break;

  case CCOsc1ShapeAdj: {
    float Osc1ShapeAdjValue = (1 - (0.85 * (value * DIV127)));
    // W_Osc1_L.pulseWidth(Osc1ShapeAdjValue); //TEST gain limit to 0.3
    // W_Osc1_R.pulseWidth(Osc1ShapeAdjValue);
  } break;

  case CCOsc1Octave:
    switch (value) {
    case 0:
      octave = 24;
      break;
    case 1:
      octave = 12;
      break;
    case 2:
      octave = 0;
      break;
    case 3:
      octave = -12;
      break;
    case 4:
      octave = -24;
      break;
    }
    oscSet(octave);
    break;

  case CCOsc1AddNoise: { // CCmixer3:
    float Osc1NoiseGainValue = (0.33 * (value * DIV127));
    MIX_Osc1AddNoise_L.gain(1, Osc1NoiseGainValue); // TEST gain limit to 0.3
    MIX_Osc1AddNoise_R.gain(1, Osc1NoiseGainValue);
  } break;

  case CCOsc1Att: {
    float attackValue = ((3000 * (value * DIV127)) + 10.5);
    ENV_Osc1_L.attack(attackValue); // TEST Attack min limit to 10.5ms
    ENV_Osc1_R.attack(attackValue);
  } break;

  case CCOsc1Dec: {
    float decayValue = (3000 * (value * DIV127));
    ENV_Osc1_L.decay(decayValue);
    ENV_Osc1_R.decay(decayValue);
  } break;

  case CCOsc1Sust: {
    float sustainValue = (value * DIV127);
    ENV_Osc1_L.sustain(sustainValue);
    ENV_Osc1_R.sustain(sustainValue);
  } break;

  case CCOsc1Rel: {
    float releaseValue = (3000 * (value * DIV127));
    ENV_Osc1_L.release(releaseValue);
    ENV_Osc1_R.release(releaseValue);
  } break;

  case CCOscHF: {
    FILfactor = value * DIV127;
    FILfreq = 10000 * (value * DIV127);
    if (LFOmodeSelect < 1 || LFOmodeSelect > 5)
      FILMoog_L.frequency(FILfreq), FILMoog_R.frequency(FILfreq);
  } break;

  case CCOscHRes: {
    float resonanceValue = ((4.3 * (value * DIV127)) + 0.7);
    FILMoog_L.resonance(resonanceValue);
    FILMoog_R.resonance(resonanceValue);
  } break;
    //
  case CCOsc2Lvl: {
    float Osc2GainValue = (0.3 * (value * DIV127));
    W_Osc2_L.amplitude(Osc2GainValue); // TEST gain limit to 0.3
    W_Osc2_R.amplitude(Osc2GainValue);
  } break;

  case CCOsc2Shape:
    switch (value) {
    case 0:
      osc2Stop();
      break;
    case 1:
      // oscPlay(note);
      W_Osc2_L.begin(WAVEFORM_SINE);
      W_Osc2_R.begin(WAVEFORM_SINE);
      Osc2Mode = 0;
      break;
    case 2:
      // oscPlay(note);
      W_Osc2_L.begin(WAVEFORM_TRIANGLE);
      W_Osc2_R.begin(WAVEFORM_TRIANGLE);
      Osc2Mode = 1;
      break;
    case 3:
      W_Osc2_L.begin(WAVEFORM_PULSE);
      W_Osc2_R.begin(WAVEFORM_PULSE);
      Osc2Mode = 2;
      break;
    case 4:
      W_Osc2_L.begin(WAVEFORM_ARBITRARY);
      W_Osc2_R.begin(WAVEFORM_ARBITRARY);
      Osc2Mode = 3;
      break;
    }
    break;

  case CCOsc2ShapeAdj: {
    float Osc2ShapeAdjValue = (1 - (0.85 * (value * DIV127)));
    // W_Osc2_L.pulseWidth(Osc2ShapeAdjValue); //TEST gain limit to 0.3
    // W_Osc2_R.pulseWidth(Osc2ShapeAdjValue);
  } break;

  case CCOsc2Detune:
    switch (value) {
    case 0:
      detune = -12;
      break;
    case 1:
      detune = -4;
      break;
    case 2:
      detune = 0;
      break;
    case 3:
      detune = 4;
      break;
    case 4:
      detune = 12;
      break;
    case 5:
      detune = 20;
      break;
    case 6:
      detune = 24;
      break;
    }
    oscSet(detune);
    break;

  case CCOsc2DetFine: {
    detuneFactor = (1 - (0.05 * (value * DIV127)));
    oscSet(detuneFactor);
  } break;

  case CCOsc2AddNoise: {
    float Osc2NoiseGainValue = (0.33 * (value * DIV127));
    MIX_Osc2AddNoise_L.gain(1, Osc2NoiseGainValue); // TEST gain limit to 0.3
    MIX_Osc2AddNoise_R.gain(1, Osc2NoiseGainValue);
  } break;

  case CCOsc2Att: {
    float attack2Value = ((3000 * (value * DIV127)) + 10.5);
    ENV_Osc2_L.attack(attack2Value); // TEST Attack min limit to 10.5ms
    ENV_Osc2_R.attack(attack2Value);
  } break;

  case CCOsc2Dec: {
    float decay2Value = (3000 * (value * DIV127));
    ENV_Osc2_L.decay(decay2Value);
    ENV_Osc2_R.decay(decay2Value);
  } break;

  case CCOsc2Sust: {
    float sustain2Value = (value * DIV127);
    ENV_Osc2_L.sustain(sustain2Value);
    ENV_Osc2_R.sustain(sustain2Value);
  } break;

  case CCOsc2Rel: {
    float release2Value = (3000 * (value * DIV127));
    ENV_Osc2_L.release(release2Value);
    ENV_Osc2_R.release(release2Value);
  } break;

  case CCNoiseLvl: {
    float NOISEGainValue = value * DIV127;
    MIX_2Reverb_L.gain(2, NOISEGainValue);
    MIX_2Reverb_L.gain(2, NOISEGainValue);
  } break;

  case CCNoiseFilterQ: { //
    float NOISEFilterQValue = ((6.5 * (value * DIV127)) + 0.5);
    FIL_NoiseEQH_L.octaveControl(NOISEFilterQValue);
    FIL_NoiseEQH_L.octaveControl(NOISEFilterQValue);
    FIL_NoiseEQH_R.octaveControl(NOISEFilterQValue);
    FIL_NoiseEQH_R.octaveControl(NOISEFilterQValue);
  } break;

  case CCNoiseHFreq: {
    float NOISEFilterHFreqValue = (15000 * (value * DIV127) + 50);
    FIL_NoiseEQH_L.frequency(NOISEFilterHFreqValue);
    FIL_NoiseEQH_R.frequency(NOISEFilterHFreqValue);
  } break;

  case CCNoiseLFreq: {
    float NOISEFilterLFreqValue = (15000 * (value * DIV127) + 50);
    FIL_NoiseEQL_L.frequency(NOISEFilterLFreqValue);
    FIL_NoiseEQL_R.frequency(NOISEFilterLFreqValue);
  } break;

  case CCNoiseAtt: {
    float NOISEAttackValue = ((3000 * (value * DIV127)) + 10.5);
    ENV_Noise_L.attack(NOISEAttackValue); // TEST Attack min limit to 10.5ms
    ENV_Noise_R.attack(NOISEAttackValue);
  } break;

  case CCNoiseDec: {
    float NOISEdecayValue = (3000 * (value * DIV127));
    ENV_Noise_L.decay(NOISEdecayValue);
    ENV_Noise_R.decay(NOISEdecayValue);
  } break;

  case CCNoiseSust: {
    float NOISEsustainValue = (value * DIV127);
    ENV_Noise_L.sustain(NOISEsustainValue);
    ENV_Noise_R.sustain(NOISEsustainValue);
  } break;

  case CCNoiseRel: {
    float NOISEreleaseValue = (3000 * (value * DIV127));
    ENV_Noise_L.release(NOISEreleaseValue);
    ENV_Noise_R.release(NOISEreleaseValue);
  } break;

  case CC_AMShape: //
    switch (value) {

    case 0:
      ENV_AM_L.noteOff();
      ENV_AM_R.noteOff();
      break;
    case 1:
      W_4AM_L.begin(WAVEFORM_SINE);
      W_4AM_R.begin(WAVEFORM_SINE);
      // int AMMode = 0;
      break;
    case 2:
      // oscPlay(note);
      W_4AM_L.begin(WAVEFORM_TRIANGLE);
      W_4AM_R.begin(WAVEFORM_TRIANGLE);
      // AMMode = 1;
      break;
    case 3:
      W_4AM_L.begin(WAVEFORM_PULSE);
      W_4AM_R.begin(WAVEFORM_PULSE);
      // AMMode = 2;
      break;
    case 4:
      W_4AM_L.begin(WAVEFORM_ARBITRARY);
      W_4AM_R.begin(WAVEFORM_ARBITRARY);
      // AMMode = 3;
      break;
    }
    break;

  case CC_AMDepth: { //
    float W_4AMGainValue = value * DIV127;
    W_4AM_L.amplitude(W_4AMGainValue);
    W_4AM_R.amplitude(W_4AMGainValue);
  } break;

  case CC_AMSpeed: { //
    float W_4AMFreqValue = (200 * (value * DIV127));
    W_4AM_L.frequency(W_4AMFreqValue);
    W_4AM_R.frequency(W_4AMFreqValue);
  } break;

  case CC_AMENV_delay: {
    float AMdelayValue = (3000 * (value * DIV127));
    ENV_AM_L.delay(AMdelayValue);
    ENV_AM_R.delay(AMdelayValue);
  } break;

  case CC_AMENV_attack: {
    float AMattackValue = (3000 * (value * DIV127));
    ENV_AM_L.attack(AMattackValue);
    ENV_AM_R.attack(AMattackValue);
  } break;

  case CC_AMENV_release: {
    float AMreleaseValue = (3000 * (value * DIV127));
    ENV_AM_L.release(AMreleaseValue);
    ENV_AM_R.release(AMreleaseValue);
  } break;

  case CC_FMShape:
    switch (value) {

    case 0:
      ENV_FM_L.noteOff();
      ENV_FM_R.noteOff();
      break;
    case 1:
      W_4FM_L.begin(WAVEFORM_SINE);
      W_4FM_R.begin(WAVEFORM_SINE);
      // int FMMode = 0;
      break;
    case 2:
      // oscPlay(note);
      W_4FM_L.begin(WAVEFORM_TRIANGLE);
      W_4FM_R.begin(WAVEFORM_TRIANGLE);
      // FMMode = 1;
      break;
    case 3:
      W_4FM_L.begin(WAVEFORM_PULSE);
      W_4FM_R.begin(WAVEFORM_PULSE);
      // FMMode = 2;
      break;
    case 4:
      W_4FM_L.begin(WAVEFORM_ARBITRARY);
      W_4FM_R.begin(WAVEFORM_ARBITRARY);
      // FMMode = 3;
      break;
    }
    break;

  case CC_FMDepth: { //
    float W_4FMGainValue = value * DIV127;
    W_4FM_L.amplitude(W_4FMGainValue);
    W_4FM_R.amplitude(W_4FMGainValue);
  } break;

  case CC_FMSpeed: { //
    float W_4FMFreqValue = (200 * (value * DIV127));
    W_4FM_L.frequency(W_4FMFreqValue);
    W_4FM_R.frequency(W_4FMFreqValue);
  } break;

  case CC_FMENV_delay: {
    float FMdelayValue = (3000 * (value * DIV127));
    ENV_FM_L.delay(FMdelayValue);
    ENV_FM_R.delay(FMdelayValue);
  } break;

  case CC_FMENV_attack: {
    float FMattackValue = (3000 * (value * DIV127));
    ENV_FM_L.attack(FMattackValue);
    ENV_FM_R.attack(FMattackValue);
  } break;

  case CC_FMENV_release: {
    float FMreleaseValue = (3000 * (value * DIV127));
    ENV_FM_L.release(FMreleaseValue);
    ENV_FM_R.release(FMreleaseValue);
  } break;

  case CCRevLvl: {
    float RevLvlValue = (value * DIV127);
    MIX_Final_L.gain(0, RevLvlValue);
    MIX_Final_L.gain(1, 1 - (0.5 * RevLvlValue));
    MIX_Final_L.gain(2, 1 - (0.5 * RevLvlValue));
    MIX_Final_R.gain(0, RevLvlValue);
    MIX_Final_R.gain(1, 1 - (0.5 * RevLvlValue));
    MIX_Final_R.gain(2, 1 - (0.5 * RevLvlValue));
  } break;

  case CCRevRoom: {
    float RevRoomValue = value * DIV127;
    RVR_Final_L.roomsize(RevRoomValue);
    RVR_Final_R.roomsize(RevRoomValue);
  } break;

  case CCRevHum: {
    float RevHumValue = value * DIV127;
    RVR_Final_L.damping(RevHumValue);
    RVR_Final_R.damping(RevHumValue);
  } break;
  }
}

void LFOupdate(bool retrig, byte mode, float FILtop, float FILbottom) {
  static float LFO = 0;
  static unsigned long LFOtime = 0;
  static bool LFOdirection = false;
  unsigned long currentMicros = micros();
  static bool LFOstop = false;
  static float LFOrange = 0;
  static byte oldMode = 0;
  static bool retriggered = false;

  if (retrig == true)
    retriggered = true;

  if (currentMicros - LFOtime >= LFOspeed) {
    LFOtime = currentMicros;

    if (mode != oldMode) {
      if (mode == 0 || mode == 8) {
        LFOpitch = 1;
        oscSet(LFOpitch);
        FILMoog_L.frequency(FILfreq);
        FILMoog_R.frequency(FILfreq);
      } else if (mode >= 1 || mode <= 7) {
        LFOpitch = 1;
        oscSet(LFOpitch);
      } else if (mode >= 9 || mode <= 13) {
        FILMoog_L.frequency(FILfreq);
        FILMoog_R.frequency(FILfreq);
      }
      oldMode = mode;
    }

    LFOrange = FILtop - FILbottom;
    if (LFOrange < 0)
      LFOrange = 0;

    // LFO Modes
    switch (mode) {

    case 0: // Filter OFF
      return;
      break;
    case 1: // Filter FREE
      FILMoog_L.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      FILMoog_R.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      break;
    case 2: // Filter DOWN
      if (retriggered == true) {
        LFOdirection = true;
        LFO = 1.0;
      }
      FILMoog_L.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      FILMoog_R.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      break;
    case 3: // Filter UP
      if (retriggered == true) {
        LFOdirection = false;
        LFO = 0;
      }
      FILMoog_L.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      FILMoog_R.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      break;
    case 4: // Filter 1-DN
      if (retriggered == true) {
        LFOstop = false;
        LFOdirection = true;
        LFO = 1.0;
      }
      if (LFOstop == false)
        FILMoog_L.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      FILMoog_R.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      break;
    case 5: // Filter 1-UP
      if (retriggered == true) {
        LFOstop = false;
        LFOdirection = false;
        LFO = 0;
      }
      if (LFOstop == false)
        FILMoog_L.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      FILMoog_R.frequency(10000 * ((LFOrange * LFO) + LFOdepth));
      break;
    case 8: // Pitch OFF
      return;
      break;
    case 9: // Pitch FREE
      LFOpitch = (LFO * LFOdepth) + 1;
      oscSet(LFOpitch);
      break;
    case 10: // Pitch DOWN
      if (retriggered == true) {
        LFOdirection = true;
        LFO = 1.0;
      }
      LFOpitch = (LFO * LFOdepth) + 1;
      oscSet(LFOpitch);
      break;
    case 11: // Pitch UP
      if (retriggered == true) {
        LFOdirection = false;
        LFO = 0;
      }
      LFOpitch = (LFO * LFOdepth) + 1;
      oscSet(LFOpitch);
      break;
    case 12: // Pitch 1-DN
      if (retriggered == true) {
        LFOstop = false;
        LFOdirection = true;
        LFO = 1.0;
      }
      if (LFOstop == false) {
        LFOpitch = (LFO * LFOdepth) + 1;
        oscSet(LFOpitch);
      }
      break;
    case 13: // Pitch 1-UP
      if (retriggered == true) {
        LFOstop = false;
        LFOdirection = false;
        LFO = 0;
      }
      if (LFOstop == false) {
        LFOpitch = (LFO * LFOdepth) + 1;
        oscSet(LFOpitch);
      }
      break;
    }

    retriggered = false;

    // Update LFO
    if (LFOdirection == false) { // UP
      LFO = (LFO + 0.01);
      if (LFO >= 1) {
        LFOdirection = true;
        LFOstop = true;
      }
    }

    if (LFOdirection == true) { // Down
      LFO = (LFO - 0.01);
      if (LFO <= 0) {
        LFOdirection = false;
        LFOstop = true;
      }
    }
  }
}

/*    case CCdetune:
      detuneFactor = 1 - (0.05 * (value * DIV127));
      oscSet();
      break;

    case CCfilterfreq:
      FILfactor = value * DIV127;
      FILfreq = 10000 * (value * DIV127);
      if (LFOmodeSelect < 1 || LFOmodeSelect >
  5)FilterMoog_L.frequency(FILfreq),FilterMoog_R.frequency(FILfreq); break;

    case CCfilterres:
      float resonanceValue=(4.3 * (value * DIV127)) + 0.7;
      FilterMoog_L.resonance(resonanceValue);
      FilterMoog_R.resonance(resonanceValue);
      break;

  case CCbendrange:
      if (value <= 12 && value > 0) {
        bendRange = value;
      }
      break;
    }
    }

  */
void checkMux() {
  static byte mux1Input = 0;
  static byte mux2Input = 0;
  static byte mux3Input = 0;
  static int muxValues[MnumControls] = {};
  unsigned long currentMicros = micros();
  static unsigned long LFOtime =
      currentMicros; // static unsigned long LFOtime = 0;

  if (currentMicros - LFOtime >= 1000) {
    LFOtime = currentMicros;

    int muxRead = analogRead(MZ);
    if (muxRead > (muxValues[mux1Input] + 7) ||
        muxRead < (muxValues[mux1Input] - 7)) {
      muxValues[mux1Input] = muxRead;
      muxRead = (muxRead >> 3); // Change range to 0-127
      switch (mux1Input) {
      case MUX_Osc1Lvl:
        myControlChange(0, CCOsc1Lvl, muxRead);
        break;
      case MUX_Osc1Shape:
        muxRead = muxRead / 25;
        if (muxRead != CCOsc1Shape)
          myControlChange(0, CCOsc1Shape, muxRead);
        break;
      case MUX_Osc1ShapeAdj:
        myControlChange(0, CCOsc1ShapeAdj, muxRead);
        break;
      case MUX_Octave:
        muxRead = muxRead / 32;
        if (muxRead != octave)
          myControlChange(0, CCOsc1Octave, muxRead);
        break;
      case MUX_AddNoise1Lvl:
        myControlChange(0, CCOsc1AddNoise, muxRead);
        break;
      case MUX_Attack1:
        myControlChange(0, CCOsc1Att, muxRead);
        break;
      case MUX_Decay1:
        myControlChange(0, CCOsc1Dec, muxRead);
        break;
      case MUX_Sustain1:
        myControlChange(0, CCOsc1Sust, muxRead);
        break;
      case MUX_Release1:
        myControlChange(0, CCOsc1Rel, muxRead);
        break;
      case MUX_FilterHF1:
        myControlChange(0, CCOscHF, muxRead);
        break;
      case MUX_FilterHRes1:
        myControlChange(0, CCOscHRes, muxRead);
        break;
      case MUX_Osc2Lvl:
        myControlChange(0, CCOsc1Lvl, muxRead);
        break;
      case MUX_Osc2Shape:
        muxRead = muxRead / 25;
        if (muxRead != CCOsc2Shape)
          myControlChange(0, CCOsc2Shape, muxRead);
        break;
      case MUX_Osc2ShapeAdj:
        myControlChange(0, CCOsc2ShapeAdj, muxRead);
        break;
      case MUX_Detune:
        muxRead = muxRead / 21;
        if (muxRead != detune)
          myControlChange(0, CCOsc2Detune, muxRead);
        break;
      case MUX_DetuneFine:
        myControlChange(0, CCOsc2DetFine, muxRead);
        break;
      }
    }
    mux1Input++;
    if (mux1Input >= MnumControls)
      mux1Input = 0;
    digitalWrite(MS0, mux1Input & B0001);
    digitalWrite(MS1, mux1Input & B0010);
    digitalWrite(MS2, mux1Input & B0100);
    digitalWrite(MS3, mux1Input & B1000);
    //}
    muxRead = analogRead(MZ_2);
    if (muxRead > (muxValues[mux2Input] + 7) ||
        muxRead < (muxValues[mux2Input] - 7)) {
      muxValues[mux2Input] = muxRead;
      muxRead = (muxRead >> 3); // Change range to 0-127
      switch (mux2Input) {
      case MUX_AddNoise2Lvl:
        myControlChange(0, CCOsc2AddNoise, muxRead);
        break;
      case MUX_Attack2:
        myControlChange(0, CCOsc2Att, muxRead);
        break;
      case MUX_Decay2:
        myControlChange(0, CCOsc2Dec, muxRead);
        break;
      case MUX_Sustain2:
        myControlChange(0, CCOsc2Sust, muxRead);
        break;
      case MUX_Release2:
        myControlChange(0, CCOsc2Rel, muxRead);
        break;
      case MUX_NoiseLvl:
        myControlChange(0, CCNoiseLvl, muxRead);
        break;
      case MUX_NoiseAttack:
        myControlChange(0, CCNoiseAtt, muxRead);
        break;
      case MUX_NoiseDecay:
        myControlChange(0, CCNoiseDec, muxRead);
        break;
      case MUX_NoiseSustain:
        myControlChange(0, CCNoiseSust, muxRead);
        break;
      case MUX_NoiseRelease:
        myControlChange(0, CCNoiseRel, muxRead);
        break;
      case MUX_NoiseFilterQ:
        myControlChange(0, CCNoiseFilterQ, muxRead);
        break;
      case MUX_NoiseFilterHFreq:
        myControlChange(0, CCNoiseHFreq, muxRead);
        break;
      case MUX_NoiseFilterLFreq:
        myControlChange(0, CCNoiseLFreq, muxRead);
        break;
      case MUX_AMShape:
        muxRead = muxRead / 32;
        if (muxRead != CC_AMShape)
          myControlChange(0, CC_AMShape, muxRead);
        break;
      case MUX_AMDepth:
        myControlChange(0, CC_AMDepth, muxRead);
        break;
      case MUX_AMSpeed:
        myControlChange(0, CC_AMSpeed, muxRead);
        break;
      }
    }
    mux2Input++;
    if (mux2Input >= MnumControls)
      mux2Input = 0;
    digitalWrite(MS0_2, mux2Input & B0001);
    digitalWrite(MS1_2, mux2Input & B0010);
    digitalWrite(MS2_2, mux2Input & B0100);
    digitalWrite(MS3_2, mux2Input & B1000);

    muxRead = analogRead(MZ_3);
    if (muxRead > (muxValues[mux3Input] + 7) ||
        muxRead < (muxValues[mux3Input] - 7)) {
      muxValues[mux3Input] = muxRead;
      muxRead = (muxRead >> 3); // Change range to 0-127
      switch (mux3Input) {
      case MUX_AMENV_delay:
        myControlChange(0, CC_AMENV_delay, muxRead);
        break;
      case MUX_AMENV_attack:
        myControlChange(0, CC_AMENV_attack, muxRead);
        break;
      case MUX_AMENV_release:
        myControlChange(0, CC_AMENV_release, muxRead);
        break;
      case MUX_FMShape:
        muxRead = muxRead / 32;
        if (muxRead != CC_FMShape)
          myControlChange(0, CC_FMShape, muxRead);
        break;
      case MUX_FMDepth:
        myControlChange(0, CC_FMDepth, muxRead);
        break;
      case MUX_FMSpeed:
        myControlChange(0, CC_FMSpeed, muxRead);
        break;
      case MUX_FMENV_delay:
        myControlChange(0, CC_AMENV_delay, muxRead);
        break;
      case MUX_FMENV_attack:
        myControlChange(0, CC_AMENV_attack, muxRead);
        break;
      case MUX_FMENV_release:
        myControlChange(0, CC_AMENV_release, muxRead);
        break;
      case MUX_RevLvl:
        myControlChange(0, CCRevLvl, muxRead);
        break;
      case MUX_RevRoom:
        myControlChange(0, CCRevRoom, muxRead);
        break;
      case MUX_RevHum:
        myControlChange(0, CCRevHum, muxRead);
        break;
      }
    }
    mux3Input++;
    if (mux3Input >= MnumControls)
      mux3Input = 0;
    digitalWrite(MS0_3, mux3Input & B0001);
    digitalWrite(MS1_3, mux3Input & B0010);
    digitalWrite(MS2_3, mux3Input & B0100);
    digitalWrite(MS3_3, mux3Input & B1000);

    checkSwitch();
  }
}
void checkSwitch() {

  /*if (digitalRead(SWosc1)) {
    octave1 = 12;
  } else {
    octave1 = 0;
  }

  if (digitalRead(SWosc2)) {
    octave2 = -12;
  } else {
    octave2 = 0;
  }
*/
  if (digitalRead(SW_LFO)) {
    if (LFOmodeSelect < 8)
      LFOmodeSelect = LFOmodeSelect + 8;
  } else {
    if (LFOmodeSelect >= 8)
      LFOmodeSelect = LFOmodeSelect - 8;
  }
}
