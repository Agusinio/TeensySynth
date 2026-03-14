void loop() {
  usbMIDI.read();
  MIDI.read();

  if (activeVoices < 0) {
    activeVoices = 0;
  }

  for (int i=0; i<NUM_VOICES; i++) {
    // cross mod
    voices[i].modMix.gain(0, crossMod);

    // frequencies
    voices[i].vcoA.frequency(noteFreqs[voiceNote[i]] * octave * bend);
    voices[i].vcoB.frequency(noteFreqs[voiceNote[i]] * octave * octaveB * tuneB * bend);
    voices[i].vcoC.frequency(noteFreqs[voiceNote[i]] * octave * octaveC * tuneC * bend);
    voices[i].sub.frequency(noteFreqs[voiceNote[i]] / 2 * octave * bend);

    // vco Mixer
    voices[i].voiceMix.gain(0, vcoAvol * mainVol);
    voices[i].voiceMix.gain(1, vcoBvol * mainVol);
    voices[i].voiceMix.gain(2, vcoCvol * mainVol);
    voices[i].voiceMix.gain(3, Subvol * mainVol);

    // vco A shape
    if (shapeA == 0) {
      voices[i].vcoA.begin(WAVEFORM_PULSE);
    } else if (shapeA == 1) {
      voices[i].vcoA.begin(WAVEFORM_SAWTOOTH);
      voices[i].vcoA.amplitude(vcoVol);
    } else if (shapeA == 2) {
      voices[i].vcoA.begin(WAVEFORM_TRIANGLE_VARIABLE);
      voices[i].vcoA.amplitude(vcoVol * 1.5);
    }

    // vco B shape
    if (shapeB == 0) {
      voices[i].vcoB.begin(WAVEFORM_PULSE);
    } else if (shapeB == 1) {
      voices[i].vcoB.begin(WAVEFORM_SAWTOOTH);
      voices[i].vcoB.amplitude(vcoVol);
    } else if (shapeB == 2) {
      voices[i].vcoB.begin(WAVEFORM_TRIANGLE_VARIABLE);
      voices[i].vcoB.amplitude(vcoVol * 1.5);
    }
    
    // Vco C shapes
    switch(shapeC) {
      case 1 ... 32: voices[i].vcoC.arbitraryWaveform(wave1, 2000); break;
      case 37 ... 69: voices[i].vcoC.arbitraryWaveform(wave2, 2000); break;
      case 73 ... 105: voices[i].vcoC.arbitraryWaveform(wave3, 2000); break;
      case 109 ... 141: voices[i].vcoC.arbitraryWaveform(wave4, 2000); break;
      case 145 ... 177: voices[i].vcoC.arbitraryWaveform(wave5, 2000); break;
      case 181 ... 212: voices[i].vcoC.arbitraryWaveform(wave6, 2000); break;
      case 217 ... 248: voices[i].vcoC.arbitraryWaveform(wave7, 2000); break;
      case 253 ... 285: voices[i].vcoC.arbitraryWaveform(wave8, 2000); break;
      case 289 ... 320: voices[i].vcoC.arbitraryWaveform(wave9, 2000); break;
      case 325 ... 357: voices[i].vcoC.arbitraryWaveform(wave10, 2000); break;
      case 361 ... 393: voices[i].vcoC.arbitraryWaveform(wave11, 2000); break;
      case 397 ... 429: voices[i].vcoC.arbitraryWaveform(wave12, 2000); break;
      case 433 ... 465: voices[i].vcoC.arbitraryWaveform(wave13, 2000); break;
      case 469 ... 500: voices[i].vcoC.arbitraryWaveform(wave14, 2000); break;
      case 505 ... 537: voices[i].vcoC.arbitraryWaveform(wave15, 2000); break;
      case 541 ... 573: voices[i].vcoC.arbitraryWaveform(wave16, 2000); break;
      case 577 ... 609: voices[i].vcoC.arbitraryWaveform(wave17, 2000); break;
      case 613 ... 645: voices[i].vcoC.arbitraryWaveform(wave18, 2000); break;
      case 649 ... 680: voices[i].vcoC.arbitraryWaveform(wave19, 2000); break;
      case 685 ... 717: voices[i].vcoC.arbitraryWaveform(wave20, 2000); break;
      case 721 ... 752: voices[i].vcoC.arbitraryWaveform(wave21, 2000); break;
      case 757 ... 789: voices[i].vcoC.arbitraryWaveform(wave22, 2000); break;
      case 793 ... 825: voices[i].vcoC.arbitraryWaveform(wave23, 2000); break;
      case 829 ... 860: voices[i].vcoC.arbitraryWaveform(wave24, 2000); break;
      case 865 ... 896: voices[i].vcoC.arbitraryWaveform(wave25, 2000); break;
      case 901 ... 933: voices[i].vcoC.arbitraryWaveform(wave26, 2000); break;
      case 937 ... 966: voices[i].vcoC.arbitraryWaveform(wave27, 2000); break;
      case 970 ... 1024: voices[i].vcoC.arbitraryWaveform(wave28, 2000); break;
    }
  }
