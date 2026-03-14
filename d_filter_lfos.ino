  if (parameterChanged || preset == 0) {
    for (int i=0; i<NUM_VOICES; i++) {
    // filter
    voices[i].filter.frequency(currentPatch.cut);
    voices[i].filter.resonance(currentPatch.res);

    // filter env
    voices[i].filterEnv.attack(currentPatch.filtAtt);
    voices[i].filterEnv.decay(currentPatch.filtDec);
    voices[i].filterEnv.release(currentPatch.filtDec);
    voices[i].dc.amplitude(currentPatch.filtAmt);

    // main env
    voices[i].env.attack(currentPatch.envAtt);
    voices[i].env.decay(currentPatch.envDec);
    voices[i].env.release(currentPatch.envRel);
    voices[i].env.sustain(currentPatch.envSus);

    // filter mode
    if (currentPatch.filterMode == 1) { // Highpass
      voices[i].filterMode.gain(0, 1);
      voices[i].filterMode.gain(1, 0);
    } else if (currentPatch.filterMode == 0) { // Lowpass
      voices[i].filterMode.gain(0, 0);
      voices[i].filterMode.gain(1, 1);
    }

    // lfo A params
    voices[i].lfoA.amplitude(currentPatch.lfoAamp);
    voices[i].lfoA.frequency(currentPatch.lfoAfreq);
    voices[i].lfoAenv.delay(currentPatch.lfoAdel);
    voices[i].lfoAenv.attack(currentPatch.lfoAatt);
    voices[i].lfoAenv.decay(currentPatch.lfoAdec);
    voices[i].lfoAenv.release(currentPatch.lfoArel);
    voices[i].lfoAenv.sustain(currentPatch.lfoAsus);

    // lfo shape switch
    if (currentPatch.lfoAshape == 0) voices[i].lfoA.begin(WAVEFORM_SINE);
    else if (currentPatch.lfoAshape == 1) voices[i].lfoA.begin(WAVEFORM_SAWTOOTH_REVERSE);
    else if (currentPatch.lfoAshape == 2) voices[i].lfoA.begin(WAVEFORM_SAMPLE_HOLD);

    // lfo B params
    voices[i].lfoB.amplitude(currentPatch.lfoBamp);
    voices[i].lfoB.frequency(currentPatch.lfoBfreq);

    // LFO A DESTINATION
    if (currentPatch.lfoAdest == 0) { // lfo - pitch
      voices[i].patch_lfoAenv_modMix->connect();
      voices[i].patch_lfoAenv_vcoB->connect();
      voices[i].patch_lfoAenv_vcoC->connect();
      voices[i].patch_lfoAenv_sub->connect();
      voices[i].patch_lfoAenv_filterMix->disconnect();
    } else if (currentPatch.lfoAdest == 1) { // lfo - filter
      voices[i].patch_lfoAenv_modMix->disconnect();
      voices[i].patch_lfoAenv_vcoB->disconnect();
      voices[i].patch_lfoAenv_vcoC->disconnect();
      voices[i].patch_lfoAenv_sub->disconnect();
      voices[i].patch_lfoAenv_filterMix->connect();
    } else if (currentPatch.lfoAdest == 2) { // lfo - amp
      voices[i].patch_lfoAenv_modMix->disconnect();
      voices[i].patch_lfoAenv_vcoB->disconnect();
      voices[i].patch_lfoAenv_vcoC->disconnect();
      voices[i].patch_lfoAenv_sub->disconnect();
      voices[i].patch_lfoAenv_filterMix->disconnect();
    }
  }
  
  if (parameterChanged) {
      parameterChanged = false; // Reset the flag after updating all voices
  }

  // Global FX parameters
  dlyMixL.gain(1, currentPatch.dlyAmt);
  dlyMixR.gain(1, currentPatch.dlyAmt);
  dlyL.delay(0, currentPatch.dlyTimeL);
  dlyR.delay(0, currentPatch.dlyTimeR);

  reverb.roomsize(currentPatch.revSize);
  reverb.damping(currentPatch.revSize * 0.8);
  fxL.gain(1, currentPatch.revMix);
  fxR.gain(1, currentPatch.revMix);

} // End of if (parameterChanged || preset == 0)

  // lfo A read (global amp mod)
  unsigned long currTime = millis();
  if (currTime - prevTime >= readInt) {
    ampMod = lfoAread1.read();
    prevTime = currTime;
  }
  
  if (currentPatch.lfoAdest == 2) {
    patchGlobal_lfoAenv_read.connect();
    finalMix.gain(0, (1 - (ampMod * 3.2)));
    finalMix.gain(1, (1 - (ampMod * 3.2)));
  } else {
    patchGlobal_lfoAenv_read.disconnect();
    finalMix.gain(0, 1.0);
    finalMix.gain(1, 1.0);
  }
