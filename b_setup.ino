void setup() {
  Serial.begin(9600);
  AudioMemory(20);
  AudioMemory_F32(300);

  // Midi setup
  usbMIDI.begin();
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);
  MIDI.setHandleNoteOn(myNoteOn);
  MIDI.setHandleNoteOff(myNoteOff);
  MIDI.begin(MIDI_CHANNEL_OMNI);

  // Switches
  pinMode(1, INPUT_PULLDOWN);  // poly
  pinMode(2, INPUT_PULLDOWN);  // shape A Pasar a MUX
  pinMode(3, INPUT_PULLDOWN);  // shape A Este sobra
  pinMode(4, INPUT_PULLDOWN);  // shabe B Pasar a MUX
  pinMode(5, INPUT_PULLDOWN);  // shape B Este sobra
  pinMode(6, INPUT_PULLDOWN);  // main oct Pasar a MUX
  pinMode(7, INPUT_PULLDOWN);  // main oct Este sobra
  pinMode(8, INPUT_PULLDOWN);  // oct B  Pasar a MUX
  pinMode(10, INPUT_PULLDOWN); // oct C Pasar a MUX
  pinMode(11, INPUT_PULLDOWN); // oct C Sobra
  pinMode(12, INPUT_PULLDOWN); // oct B Sobra
  pinMode(13, INPUT_PULLDOWN); // filt Mode

  pinMode(24, INPUT_PULLDOWN); // lfo dest Pasar a MUX?
  pinMode(25, INPUT_PULLDOWN); // lfo dest Sobra?
  pinMode(26, INPUT_PULLDOWN); // lfo shape Pasar a MUX
  pinMode(27, INPUT_PULLDOWN); // lfo shape obra?

  pinMode(44, INPUT_PULLDOWN); //
  pinMode(45, INPUT_PULLDOWN); //
  pinMode(46, INPUT_PULLDOWN); //
  pinMode(48, INPUT_PULLDOWN); //
  pinMode(49, INPUT_PULLDOWN); //

  // Mux setup
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);

  digitalWrite(28, 0);
  digitalWrite(29, 0);
  digitalWrite(30, 0);

  // Initialize dynamic per-voice connections and start objects
  for (int i=0; i < NUM_VOICES; i++) {
      // Patch LFOs & Envelopes
      voices[i].patch_lfoA_lfoAenv      = new AudioConnection_F32(voices[i].lfoA, voices[i].lfoAenv);
      
      // MAP SOURCES TO MOD MIXERS (Ch 0: LFO A, Ch 1: LFO B, Ch 2: Env, Ch 3: Vel/DC)
      voices[i].patch_lfoA_modCutoff    = new AudioConnection_F32(voices[i].lfoA, 0, voices[i].modMixCutoff, 0);
      voices[i].patch_lfoA_modRes       = new AudioConnection_F32(voices[i].lfoA, 0, voices[i].modMixRes, 0);
      voices[i].patch_lfoA_modCross     = new AudioConnection_F32(voices[i].lfoA, 0, voices[i].modMixCross, 0);
      voices[i].patch_lfoA_modPitch     = new AudioConnection_F32(voices[i].lfoA, 0, voices[i].modMixPitch, 0);

      voices[i].patch_lfoB_modCutoff    = new AudioConnection_F32(voices[i].lfoB, 0, voices[i].modMixCutoff, 1);
      voices[i].patch_lfoB_modRes       = new AudioConnection_F32(voices[i].lfoB, 0, voices[i].modMixRes, 1);
      voices[i].patch_lfoB_modCross     = new AudioConnection_F32(voices[i].lfoB, 0, voices[i].modMixCross, 1);
      voices[i].patch_lfoB_modPitch     = new AudioConnection_F32(voices[i].lfoB, 0, voices[i].modMixPitch, 1);

      voices[i].patch_filterEnv_modCutoff = new AudioConnection_F32(voices[i].filterEnv, 0, voices[i].modMixCutoff, 2);
      voices[i].patch_filterEnv_modRes    = new AudioConnection_F32(voices[i].filterEnv, 0, voices[i].modMixRes, 2);
      voices[i].patch_filterEnv_modCross  = new AudioConnection_F32(voices[i].filterEnv, 0, voices[i].modMixCross, 2);
      voices[i].patch_filterEnv_modPitch  = new AudioConnection_F32(voices[i].filterEnv, 0, voices[i].modMixPitch, 2);

      voices[i].patch_vel_modCutoff     = new AudioConnection_F32(voices[i].dc, 0, voices[i].modMixCutoff, 3);
      voices[i].patch_vel_modRes        = new AudioConnection_F32(voices[i].dc, 0, voices[i].modMixRes, 3);
      voices[i].patch_vel_modCross      = new AudioConnection_F32(voices[i].dc, 0, voices[i].modMixCross, 3);
      voices[i].patch_vel_modPitch      = new AudioConnection_F32(voices[i].dc, 0, voices[i].modMixPitch, 3);

      // MAP MOD MIXERS TO DESTINATIONS
      voices[i].patch_modPitch_vcoA     = new AudioConnection_F32(voices[i].modMixPitch, 0, voices[i].vcoA, 0);
      voices[i].patch_modPitch_vcoB     = new AudioConnection_F32(voices[i].modMixPitch, 0, voices[i].vcoB, 0);
      voices[i].patch_modPitch_vcoC     = new AudioConnection_F32(voices[i].modMixPitch, 0, voices[i].vcoC, 0);
      
      voices[i].patch_modCross_vcoB     = new AudioConnection_F32(voices[i].modMixCross, 0, voices[i].vcoB, 1); // Assuming 1 is phase/freq mod input for vcoB
      
      voices[i].patch_modCutoff_filterFreq = new AudioConnection_F32(voices[i].modMixCutoff, 0, voices[i].filter, 1);
      voices[i].patch_modRes_filterRes  = new AudioConnection_F32(voices[i].modMixRes, 0, voices[i].filter, 2); // Check if filter supports F32 resonance cv

      // VCOs to Voice Mix
      voices[i].patch_sub_voiceMix      = new AudioConnection_F32(voices[i].sub, 0, voices[i].voiceMix, 3);
      voices[i].patch_vcoA_voiceMix     = new AudioConnection_F32(voices[i].vcoA, 0, voices[i].voiceMix, 0);
      voices[i].patch_vcoB_voiceMix     = new AudioConnection_F32(voices[i].vcoB, 0, voices[i].voiceMix, 1);
      voices[i].patch_vcoC_voiceMix     = new AudioConnection_F32(voices[i].vcoC, 0, voices[i].voiceMix, 2);

      // Voice mix to filter
      voices[i].patch_voiceMix_filter   = new AudioConnection_F32(voices[i].voiceMix, 0, voices[i].filter, 0);

      // Filter modulation
      voices[i].patch_dc_filterEnv        = new AudioConnection_F32(voices[i].dc, voices[i].filterEnv);
      voices[i].patch_filterEnv_filterMix = new AudioConnection_F32(voices[i].filterEnv, 0, voices[i].filterMix, 0);
      voices[i].patch_filterMix_filter    = new AudioConnection_F32(voices[i].filterMix, 0, voices[i].filter, 1);

      // Filters to envs
      voices[i].patch_filter_filterMode0  = new AudioConnection_F32(voices[i].filter, 0, voices[i].filterMode, 0);
      voices[i].patch_filter_filterMode1  = new AudioConnection_F32(voices[i].filter, 1, voices[i].filterMode, 1);
      voices[i].patch_filterMode_env      = new AudioConnection_F32(voices[i].filterMode, voices[i].env);
      
      // Env to output mix
      int mixIndex = i / 4;  // 0-3 go to mix[0], 4-7 go to mix[1], 8-9 go to mix[2]
      int channelIndex = i % 4;
      voices[i].patch_env_mix = new AudioConnection_F32(voices[i].env, 0, mix[mixIndex], channelIndex);
      
      // Start VCOs
      voices[i].vcoA.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
      voices[i].vcoB.begin(vcoVol, 150, WAVEFORM_SQUARE);
      voices[i].vcoC.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
      voices[i].sub.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

      voices[i].filter.octaveControl(7);
      voices[i].filterEnv.sustain(0);

      voices[i].lfoA.begin(WAVEFORM_SINE);
      voices[i].lfoB.begin(0.5, 1, WAVEFORM_TRIANGLE);

      // Apply initial 0 gain to all modulation matrix connections
      for(int channel = 0; channel < 4; ++channel) {
          voices[i].modMixCutoff.gain(channel, 0.0f);
          voices[i].modMixRes.gain(channel, 0.0f);
          voices[i].modMixCross.gain(channel, 0.0f);
          voices[i].modMixPitch.gain(channel, 0.0f);
      }
      
  }

  // dly
  dlyFiltL.frequency(4000);
  dlyFiltR.frequency(3000);

  dlyMixL.gain(0, 0.75);
  dlyMixL.gain(0, 0.75);

  dlyL.disable(1);
  dlyL.disable(2);
  dlyL.disable(3);
  dlyL.disable(4);
  dlyL.disable(5);
  dlyL.disable(6);
  dlyL.disable(7);

  dlyR.disable(1);
  dlyR.disable(2);
  dlyR.disable(3);
  dlyR.disable(4);
  dlyR.disable(5);
  dlyR.disable(6);
  dlyR.disable(7);

  // reverb
  reverb.roomsize(0.9);
  reverb.damping(0.8);
}
