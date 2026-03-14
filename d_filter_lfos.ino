
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
