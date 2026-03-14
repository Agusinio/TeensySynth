import os

repo = '/Volumes/PYTHON/AAA_C_Projects/TeensySynth/a_globals/'

# 1. Re-write c_loop_vcos.ino
c_loop_vcos = """void loop() {
  usbMIDI.read();
  MIDI.read();

  if (voices < 0) {
    voices = 0;
  }

  for (int i=0; i<NUM_VOICES; i++) {
    // cross mod
    modMix[i].gain(0, crossMod);

    // frequencies
    vcoA[i].frequency(noteFreqs[voiceNote[i]] * octave * bend);
    vcoB[i].frequency(noteFreqs[voiceNote[i]] * octave * octaveB * tuneB * bend);
    vcoC[i].frequency(noteFreqs[voiceNote[i]] * octave * octaveC * tuneC * bend);
    sub[i].frequency(noteFreqs[voiceNote[i]] / 2 * octave * bend);

    // vco Mixer
    voiceMix[i].gain(0, vcoAvol * mainVol);
    voiceMix[i].gain(1, vcoBvol * mainVol);
    voiceMix[i].gain(2, vcoCvol * mainVol);
    voiceMix[i].gain(3, Subvol * mainVol);

    // vco A shape
    if (shapeA == 0) {
      vcoA[i].begin(WAVEFORM_PULSE);
    } else if (shapeA == 1) {
      vcoA[i].begin(WAVEFORM_SAWTOOTH);
      vcoA[i].amplitude(vcoVol);
    } else if (shapeA == 2) {
      vcoA[i].begin(WAVEFORM_TRIANGLE_VARIABLE);
      vcoA[i].amplitude(vcoVol * 1.5);
    }

    // vco B shape
    if (shapeB == 0) {
      vcoB[i].begin(WAVEFORM_PULSE);
    } else if (shapeB == 1) {
      vcoB[i].begin(WAVEFORM_SAWTOOTH);
      vcoB[i].amplitude(vcoVol);
    } else if (shapeB == 2) {
      vcoB[i].begin(WAVEFORM_TRIANGLE_VARIABLE);
      vcoB[i].amplitude(vcoVol * 1.5);
    }
    
    // Vco C shapes
    switch(shapeC) {
      case 1 ... 32: vcoC[i].arbitraryWaveform(wave1, 2000); break;
      case 37 ... 69: vcoC[i].arbitraryWaveform(wave2, 2000); break;
      case 73 ... 105: vcoC[i].arbitraryWaveform(wave3, 2000); break;
      case 109 ... 141: vcoC[i].arbitraryWaveform(wave4, 2000); break;
      case 145 ... 177: vcoC[i].arbitraryWaveform(wave5, 2000); break;
      case 181 ... 212: vcoC[i].arbitraryWaveform(wave6, 2000); break;
      case 217 ... 248: vcoC[i].arbitraryWaveform(wave7, 2000); break;
      case 253 ... 285: vcoC[i].arbitraryWaveform(wave8, 2000); break;
      case 289 ... 320: vcoC[i].arbitraryWaveform(wave9, 2000); break;
      case 325 ... 357: vcoC[i].arbitraryWaveform(wave10, 2000); break;
      case 361 ... 393: vcoC[i].arbitraryWaveform(wave11, 2000); break;
      case 397 ... 429: vcoC[i].arbitraryWaveform(wave12, 2000); break;
      case 433 ... 465: vcoC[i].arbitraryWaveform(wave13, 2000); break;
      case 469 ... 500: vcoC[i].arbitraryWaveform(wave14, 2000); break;
      case 505 ... 537: vcoC[i].arbitraryWaveform(wave15, 2000); break;
      case 541 ... 573: vcoC[i].arbitraryWaveform(wave16, 2000); break;
      case 577 ... 609: vcoC[i].arbitraryWaveform(wave17, 2000); break;
      case 613 ... 645: vcoC[i].arbitraryWaveform(wave18, 2000); break;
      case 649 ... 680: vcoC[i].arbitraryWaveform(wave19, 2000); break;
      case 685 ... 717: vcoC[i].arbitraryWaveform(wave20, 2000); break;
      case 721 ... 752: vcoC[i].arbitraryWaveform(wave21, 2000); break;
      case 757 ... 789: vcoC[i].arbitraryWaveform(wave22, 2000); break;
      case 793 ... 825: vcoC[i].arbitraryWaveform(wave23, 2000); break;
      case 829 ... 860: vcoC[i].arbitraryWaveform(wave24, 2000); break;
      case 865 ... 896: vcoC[i].arbitraryWaveform(wave25, 2000); break;
      case 901 ... 933: vcoC[i].arbitraryWaveform(wave26, 2000); break;
      case 937 ... 966: vcoC[i].arbitraryWaveform(wave27, 2000); break;
      case 970 ... 1024: vcoC[i].arbitraryWaveform(wave28, 2000); break;
    }
  }
"""
with open(os.path.join(repo, 'c_loop_vcos.ino'), 'w') as f:
    f.write(c_loop_vcos)

# 2. Re-write d_filter_lfos.ino
d_filter = """
  for (int i=0; i<NUM_VOICES; i++) {
    // filter
    filter[i].frequency(cut);
    filter[i].resonance(res);

    // filter env
    filterEnv[i].attack(filtAtt);
    filterEnv[i].decay(filtDec);
    filterEnv[i].release(filtDec);
    dc[i].amplitude(filtAmt);

    // filter mode
    if (filterMode == 1) { // Highpass
      filterMode[i].gain(0, 1);
      filterMode[i].gain(1, 0);
    } else if (filterMode == 0) { // Lowpass
      filterMode[i].gain(0, 0);
      filterMode[i].gain(1, 1);
    }

    // lfo A params
    lfoA[i].amplitude(lfoAamp);
    lfoA[i].frequency(lfoAfreq);
    lfoAenv[i].delay(lfoAdel);
    lfoAenv[i].attack(lfoAatt);
    lfoAenv[i].decay(lfoAdec);
    lfoAenv[i].release(lfoArel);
    lfoAenv[i].sustain(lfoAsus);

    // lfo shape switch
    if (lfoAshape == 0) lfoA[i].begin(WAVEFORM_SINE);
    else if (lfoAshape == 1) lfoA[i].begin(WAVEFORM_SAWTOOTH_REVERSE);
    else if (lfoAshape == 2) lfoA[i].begin(WAVEFORM_SAMPLE_HOLD);

    // lfo B params
    lfoB[i].amplitude(lfoBamp);
    lfoB[i].frequency(lfoBfreq);

    // LFO A DESTINATION
    if (lfoAdest == 0) { // lfo - pitch
      patch_lfoAenv_modMix[i]->connect();
      patch_lfoAenv_vcoB[i]->connect();
      patch_lfoAenv_vcoC[i]->connect();
      patch_lfoAenv_sub[i]->connect();
      patch_lfoAenv_filterMix[i]->disconnect();
    } else if (lfoAdest == 1) { // lfo - filter
      patch_lfoAenv_modMix[i]->disconnect();
      patch_lfoAenv_vcoB[i]->disconnect();
      patch_lfoAenv_vcoC[i]->disconnect();
      patch_lfoAenv_sub[i]->disconnect();
      patch_lfoAenv_filterMix[i]->connect();
    } else if (lfoAdest == 2) { // lfo - amp
      patch_lfoAenv_modMix[i]->disconnect();
      patch_lfoAenv_vcoB[i]->disconnect();
      patch_lfoAenv_vcoC[i]->disconnect();
      patch_lfoAenv_sub[i]->disconnect();
      patch_lfoAenv_filterMix[i]->disconnect();
    }
  }

  // lfo A read (global amp mod)
  unsigned long currTime = millis();
  if (currTime - prevTime >= readInt) {
    ampMod = lfoAread1.read();
    prevTime = currTime;
  }
  
  if (lfoAdest == 2) {
    patchGlobal_lfoAenv_read.connect();
    finalMix.gain(0, (1 - (ampMod * 3.2)));
    finalMix.gain(1, (1 - (ampMod * 3.2)));
  } else {
    patchGlobal_lfoAenv_read.disconnect();
    finalMix.gain(0, 1.0);
    finalMix.gain(1, 1.0);
  }
"""
with open(os.path.join(repo, 'd_filter_lfos.ino'), 'w') as f:
    f.write(d_filter)
