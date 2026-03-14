#include <Audio.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Wire.h>

// GUItool: begin automatically generated code
AudioSynthWaveform W_Wave4AM_R;       // xy=103.04759979248047,856.1428461074829
AudioSynthWaveformSine W_Sine4FM_L;   // xy=107.76187133789062,652.7142839431763
AudioSynthWaveformSine W_Sine4FM_R;   // xy=107.6190185546875,988.9999895095825
AudioSynthWaveform W_Wave4AM_L;       // xy=116.04759216308594,495.2856683731079
AudioSynthWaveformModulated W_Osc1_R; // xy=318.1904716491699,990.4285840988159
AudioSynthNoisePink W_Pink_L;         // xy=316.4761848449707,1437.1427354812622
AudioSynthWaveformModulated W_Osc2_R; // xy=323.4761962890625,1239.5716247558594
AudioSynthWaveformModulated W_Osc2_L; // xy=324.9047546386719,1108.5714902877808
AudioSynthNoisePink W_Pink_R;         // xy=323.1904067993164,1613.1432476043701
AudioSynthWaveformModulated W_Osc1_L; // xy=327.1904716491699,636.42857837677
AudioEffectEnvelope AMEnvelope1_L;    // xy=470.28572845458984,493.8857259750366
AudioEffectEnvelope AMEnvelope1_R;    // xy=487.8571472167969,857.7428636550903
AudioEffectMultiply MOD_AM_L;         // xy=645.1904220581055,545.2856979370117
AudioEffectMultiply MOD_AM_R;         // xy=657.3333129882812,924.4285411834717
AudioSynthNoisePink W_NoiseOsc1_L;    // xy=798.4760894775391,651.2857093811035
AudioSynthNoisePink W_NoiseOsc1_R;    // xy=810.0475845336914,1001.1428623199463
AudioSynthNoisePink W_NoiseOsc2_R;    // xy=820.0476837158203,1285.7144680023193
AudioSynthNoisePink W_NoiseOsc2_L;    // xy=822.7620315551758,1163.142921447754
AudioMixer4 MIX_Osc1Noise_L;          // xy=1000.904670715332,569.7142753601074
AudioMixer4 MIX_Osc1Noise_R;          // xy=1017.904670715332,942.7142753601074
AudioMixer4 MIX_Osc2Noise_L;         // xy=1023.0476531982422,1121.1428718566895
AudioMixer4 MIX_Osc2Noise_R;         // xy=1028.476203918457,1246.9999656677246
AudioEffectEnvelope ENV_Osc1_L;      // xy=1268.1901779174805,570.2858028411865
AudioEffectEnvelope ENV_Osc1_R;      // xy=1278.1902694702148,941.4286289215088
AudioEffectEnvelope ENV_Pink_L;      // xy=1277.6189727783203,1424.0001525878906
AudioEffectEnvelope ENV_Osc2_R;      // xy=1278.9046325683594,1242.7143077850342
AudioEffectEnvelope ENV_Osc2_L;      // xy=1282.4760055541992,1119.7143774032593
AudioEffectEnvelope ENV_Pink_R;      // xy=1280.619026184082,1613.0001487731934
AudioFilterStateVariable FIL_Osc1_R; // xy=1578.33349609375,1029.571455001831
AudioFilterStateVariable FIL_Osc2_R; // xy=1578.33349609375,1158.571455001831
AudioFilterStateVariable FIL_Osc1_L; // xy=1585.33349609375,675.571455001831
AudioFilterStateVariable FIL_Osc2_L; // xy=1585.33349609375,785.571455001831
AudioFilterStateVariable FIL_Pink_L; // xy=1583.9047546386719,1430.4287490844727
AudioFilterStateVariable FIL_Pink_R; // xy=1586.9047546386719,1618.4289474487305
AudioMixer4 MIX_HL;                  // xy=1874.476188659668,611.0000457763672
AudioMixer4 MIX_ML;                  // xy=1877.476188659668,706.0000457763672
AudioMixer4 MIX_LL;                  // xy=1877.476188659668,819.0000457763672
AudioMixer4 MIX_HR;                  // xy=1886.476188659668,1011.0000457763672
AudioMixer4 MIX_LR;                  // xy=1886.476188659668,1209.0000457763672
AudioMixer4 MIX_MR;                  // xy=1888.476188659668,1116.0000457763672
AudioEffectChorus CHOR_HR;           // xy=2074.476188659668,1052.0000457763672
AudioEffectChorus CHOR_ML;           // xy=2077.476188659668,706.0000457763672
AudioEffectChorus CHOR_HL;           // xy=2078.476188659668,642.0000457763672
AudioEffectChorus CHOR_MR;           // xy=2080.476188659668,1109.0000457763672
AudioEffectChorus CHOR_LL;           // xy=2083.476188659668,792.0000457763672
AudioEffectChorus CHOR_LR;           // xy=2086.476188659668,1162.0000457763672
AudioMixer4 MIX_2Reverb_L;           // xy=2298.476188659668,700.0000457763672
AudioMixer4 MIX_2Reverb_R;           // xy=2314.476188659668,1111.0000457763672
AudioFilterLadder FILMoog_L;         // xy=2469.476188659668,585.0000457763672
AudioFilterLadder FILMoog_R;         // xy=2468.476188659668,1235.0000457763672
AudioEffectEnvelope ENV_Final_L;     // xy=2597.476188659668,744.0000457763672
AudioEffectEnvelope ENV_Final_R;     // xy=2628.476188659668,1090.0000457763672
AudioEffectFreeverbStereo RVR_Final_L; // xy=2638.476188659668,859.0000457763672
AudioEffectFreeverbStereo RVR_Final_R; // xy=2646.476188659668,992.0000457763672
AudioMixer4 MIX_Final_L;               // xy=2869.476188659668,798.0000457763672
AudioMixer4 MIX_Final_R; // xy=2887.476188659668,1103.0000457763672
AudioOutputI2S2 i2s2_1;  // xy=2919.476188659668,919.0000457763672
AudioOutputUSB usb1;     // xy=2919.476188659668,980.0000457763672
AudioConnection patchCord1(W_Wave4AM_R, AMEnvelope1_R);
AudioConnection patchCord2(W_Sine4FM_L, 0, W_Osc1_L, 0);
AudioConnection patchCord3(W_Sine4FM_R, 0, W_Osc1_R, 0);
AudioConnection patchCord4(W_Wave4AM_L, AMEnvelope1_L);
AudioConnection patchCord5(W_Osc1_R, 0, MOD_AM_R, 1);
AudioConnection patchCord6(W_Pink_L, ENV_Pink_L);
AudioConnection patchCord7(W_Osc2_R, 0, MIX_Osc2Noise_R, 0);
AudioConnection patchCord8(W_Osc2_L, 0, MIX_Osc2Noise_L, 0);
AudioConnection patchCord9(W_Pink_R, ENV_Pink_R);
AudioConnection patchCord10(W_Osc1_L, 0, MOD_AM_L, 1);
AudioConnection patchCord11(AMEnvelope1_L, 0, MOD_AM_L, 0);
AudioConnection patchCord12(AMEnvelope1_R, 0, MOD_AM_R, 0);
AudioConnection patchCord13(MOD_AM_L, 0, MIX_Osc1Noise_L, 0);
AudioConnection patchCord14(MOD_AM_R, 0, MIX_Osc1Noise_R, 0);
AudioConnection patchCord15(W_NoiseOsc1_L, 0, MIX_Osc1Noise_L, 1);
AudioConnection patchCord16(W_NoiseOsc1_R, 0, MIX_Osc1Noise_R, 1);
AudioConnection patchCord17(W_NoiseOsc2_R, 0, MIX_Osc2Noise_R, 1);
AudioConnection patchCord18(W_NoiseOsc2_L, 0, MIX_Osc2Noise_L, 1);
AudioConnection patchCord19(MIX_Osc1Noise_L, ENV_Osc1_L);
AudioConnection patchCord20(MIX_Osc1Noise_R, ENV_Osc1_R);
AudioConnection patchCord21(MIX_Osc2Noise_L, ENV_Osc2_L);
AudioConnection patchCord22(MIX_Osc2Noise_R, ENV_Osc2_R);
AudioConnection patchCord23(ENV_Osc1_L, 0, FIL_Osc1_L, 0);
AudioConnection patchCord24(ENV_Osc1_R, 0, FIL_Osc1_R, 0);
AudioConnection patchCord25(ENV_Pink_L, 0, FIL_Pink_L, 0);
AudioConnection patchCord26(ENV_Osc2_R, 0, FIL_Osc2_R, 0);
AudioConnection patchCord27(ENV_Osc2_L, 0, FIL_Osc2_L, 0);
AudioConnection patchCord28(ENV_Pink_R, 0, FIL_Pink_R, 0);
AudioConnection patchCord29(FIL_Osc1_R, 0, MIX_HR, 0);
AudioConnection patchCord30(FIL_Osc1_R, 1, MIX_ML, 1);
AudioConnection patchCord31(FIL_Osc1_R, 2, MIX_LR, 0);
AudioConnection patchCord32(FIL_Osc2_R, 0, MIX_HR, 1);
AudioConnection patchCord33(FIL_Osc2_R, 1, MIX_ML, 2);
AudioConnection patchCord34(FIL_Osc2_R, 2, MIX_LR, 1);
AudioConnection patchCord35(FIL_Osc1_L, 0, MIX_HL, 0);
AudioConnection patchCord36(FIL_Osc1_L, 1, MIX_MR, 1);
AudioConnection patchCord37(FIL_Osc1_L, 2, MIX_LL, 0);
AudioConnection patchCord38(FIL_Osc2_L, 0, MIX_HL, 1);
AudioConnection patchCord39(FIL_Osc2_L, 1, MIX_MR, 2);
AudioConnection patchCord40(FIL_Osc2_L, 2, MIX_LL, 1);
AudioConnection patchCord41(FIL_Pink_L, 1, MIX_2Reverb_L, 3);
AudioConnection patchCord42(FIL_Pink_R, 1, MIX_2Reverb_R, 3);
AudioConnection patchCord43(MIX_HL, CHOR_HL);
AudioConnection patchCord44(MIX_ML, CHOR_ML);
AudioConnection patchCord45(MIX_LL, CHOR_LL);
AudioConnection patchCord46(MIX_HR, CHOR_HR);
AudioConnection patchCord47(MIX_LR, CHOR_LR);
AudioConnection patchCord48(MIX_MR, CHOR_MR);
AudioConnection patchCord49(CHOR_HR, 0, MIX_2Reverb_R, 0);
AudioConnection patchCord50(CHOR_ML, 0, MIX_2Reverb_L, 1);
AudioConnection patchCord51(CHOR_HL, 0, MIX_2Reverb_L, 0);
AudioConnection patchCord52(CHOR_MR, 0, MIX_2Reverb_R, 1);
AudioConnection patchCord53(CHOR_LL, 0, MIX_2Reverb_L, 2);
AudioConnection patchCord54(CHOR_LR, 0, MIX_2Reverb_R, 2);
AudioConnection patchCord55(MIX_2Reverb_L, 0, FILMoog_L, 0);
AudioConnection patchCord56(MIX_2Reverb_R, 0, FILMoog_R, 0);
AudioConnection patchCord57(FILMoog_L, ENV_Final_L);
AudioConnection patchCord58(FILMoog_R, ENV_Final_R);
AudioConnection patchCord59(ENV_Final_L, RVR_Final_L);
AudioConnection patchCord60(ENV_Final_R, RVR_Final_R);
AudioConnection patchCord61(RVR_Final_L, 0, MIX_Final_L, 0);
AudioConnection patchCord62(RVR_Final_L, 1, MIX_Final_R, 0);
AudioConnection patchCord63(RVR_Final_R, 0, MIX_Final_L, 1);
AudioConnection patchCord64(RVR_Final_R, 1, MIX_Final_R, 1);
AudioConnection patchCord65(MIX_Final_L, 0, usb1, 0);
AudioConnection patchCord66(MIX_Final_L, 0, i2s2_1, 0);
AudioConnection patchCord67(MIX_Final_R, 0, usb1, 1);
AudioConnection patchCord68(MIX_Final_R, 0, i2s2_1, 1);
AudioControlSGTL5000 sgtl5000_1; // xy=2826.476188659668,1579.0000457763672
// GUItool: end automatically generated code
