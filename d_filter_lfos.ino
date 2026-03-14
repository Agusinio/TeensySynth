
  for (int i=0; i<NUM_VOICES; i++) {
    // filter
    voices[i].filter.frequency(cut);
    voices[i].filter.resonance(res);

    // filter env
    voices[i].filterEnv.attack(filtAtt);
    voices[i].filterEnv.decay(filtDec);
    voices[i].filterEnv.release(filtDec);
    voices[i].dc.amplitude(filtAmt);

    // filter mode
    if (filterMode == 1) { // Highpass
      voices[i].filterMode.gain(0, 1);
      voices[i].filterMode.gain(1, 0);
    } else if (filterMode == 0) { // Lowpass
      voices[i].filterMode.gain(0, 0);
      voices[i].filterMode.gain(1, 1);
    }

    // lfo A params
    voices[i].lfoA.amplitude(lfoAamp);
    voices[i].lfoA.frequency(lfoAfreq);
    voices[i].lfoAenv.delay(lfoAdel);
    voices[i].lfoAenv.attack(lfoAatt);
    voices[i].lfoAenv.decay(lfoAdec);
    voices[i].lfoAenv.release(lfoArel);
    voices[i].lfoAenv.sustain(lfoAsus);

    // lfo shape switch
    if (lfoAshape == 0) voices[i].lfoA.begin(WAVEFORM_SINE);
    else if (lfoAshape == 1) voices[i].lfoA.begin(WAVEFORM_SAWTOOTH_REVERSE);
    else if (lfoAshape == 2) voices[i].lfoA.begin(WAVEFORM_SAMPLE_HOLD);

    // lfo B params
    voices[i].lfoB.amplitude(lfoBamp);
    voices[i].lfoB.frequency(lfoBfreq);

    // LFO A DESTINATION
    if (lfoAdest == 0) { // lfo - pitch
      voices[i].patch_lfoAenv_modMix->connect();
      voices[i].patch_lfoAenv_vcoB->connect();
      voices[i].patch_lfoAenv_vcoC->connect();
      voices[i].patch_lfoAenv_sub->connect();
      voices[i].patch_lfoAenv_filterMix->disconnect();
    } else if (lfoAdest == 1) { // lfo - filter
      voices[i].patch_lfoAenv_modMix->disconnect();
      voices[i].patch_lfoAenv_vcoB->disconnect();
      voices[i].patch_lfoAenv_vcoC->disconnect();
      voices[i].patch_lfoAenv_sub->disconnect();
      voices[i].patch_lfoAenv_filterMix->connect();
    } else if (lfoAdest == 2) { // lfo - amp
      voices[i].patch_lfoAenv_modMix->disconnect();
      voices[i].patch_lfoAenv_vcoB->disconnect();
      voices[i].patch_lfoAenv_vcoC->disconnect();
      voices[i].patch_lfoAenv_sub->disconnect();
      voices[i].patch_lfoAenv_filterMix->disconnect();
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
