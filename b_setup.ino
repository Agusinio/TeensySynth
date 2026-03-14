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
      patch_lfoA_lfoAenv[i]      = new AudioConnection_F32(lfoA[i], lfoAenv[i]);
      patch_lfoAenv_modMix[i]    = new AudioConnection_F32(lfoAenv[i], 0, modMix[i], 1);
      patch_lfoAenv_vcoB[i]      = new AudioConnection_F32(lfoAenv[i], 0, vcoB[i], 0);
      patch_lfoAenv_vcoC[i]      = new AudioConnection_F32(lfoAenv[i], 0, vcoC[i], 0);
      patch_lfoAenv_sub[i]       = new AudioConnection_F32(lfoAenv[i], 0, sub[i], 0);
      patch_lfoAenv_filterMix[i] = new AudioConnection_F32(lfoAenv[i], 0, filterMix[i], 1);
      
      patch_lfoB_vcoA[i]         = new AudioConnection_F32(lfoB[i], 0, vcoA[i], 1);
      patch_lfoB_vcoB[i]         = new AudioConnection_F32(lfoB[i], 0, vcoB[i], 1);

      // Mod mix
      patch_modMix_vcoA[i]       = new AudioConnection_F32(modMix[i], 0, vcoA[i], 0);

      // VCOs to Voice Mix
      patch_sub_voiceMix[i]      = new AudioConnection_F32(sub[i], 0, voiceMix[i], 3);
      patch_vcoA_voiceMix[i]     = new AudioConnection_F32(vcoA[i], 0, voiceMix[i], 0);
      patch_vcoB_voiceMix[i]     = new AudioConnection_F32(vcoB[i], 0, voiceMix[i], 1);
      patch_vcoC_voiceMix[i]     = new AudioConnection_F32(vcoC[i], 0, voiceMix[i], 2);
      patch_vcoB_modMix[i]       = new AudioConnection_F32(vcoB[i], 0, modMix[i], 0);

      // Voice mix to filter
      patch_voiceMix_filter[i]   = new AudioConnection_F32(voiceMix[i], 0, filter[i], 0);

      // Filter modulation
      patch_dc_filterEnv[i]        = new AudioConnection_F32(dc[i], filterEnv[i]);
      patch_filterEnv_filterMix[i] = new AudioConnection_F32(filterEnv[i], 0, filterMix[i], 0);
      patch_filterMix_filter[i]    = new AudioConnection_F32(filterMix[i], 0, filter[i], 1);

      // Filters to envs
      patch_filter_filterMode0[i]  = new AudioConnection_F32(filter[i], 0, filterMode[i], 0);
      patch_filter_filterMode1[i]  = new AudioConnection_F32(filter[i], 1, filterMode[i], 1);
      patch_filterMode_env[i]      = new AudioConnection_F32(filterMode[i], env[i]);
      
      // Env to output mix
      int mixIndex = i / 4;  // 0-3 go to mix[0], 4-7 go to mix[1], 8-9 go to mix[2]
      int channelIndex = i % 4;
      patch_env_mix[i] = new AudioConnection_F32(env[i], 0, mix[mixIndex], channelIndex);
      
      // Start VCOs
      vcoA[i].begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
      vcoB[i].begin(vcoVol, 150, WAVEFORM_SQUARE);
      vcoC[i].begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
      sub[i].begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

      filter[i].octaveControl(7);
      filterEnv[i].sustain(0);

      lfoA[i].begin(WAVEFORM_SINE);
      lfoB[i].begin(0.5, 1, WAVEFORM_TRIANGLE);

      // Apply LFO DESTINATION DISCONNECT Defaults
      patch_lfoAenv_modMix[i]->disconnect();
      patch_lfoAenv_vcoB[i]->disconnect();
      patch_lfoAenv_vcoC[i]->disconnect();
      patch_lfoAenv_sub[i]->disconnect();
      patch_lfoAenv_filterMix[i]->disconnect();
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
