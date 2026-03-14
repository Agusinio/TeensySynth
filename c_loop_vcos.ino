void loop() {
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
