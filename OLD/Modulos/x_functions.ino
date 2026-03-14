void setOctaveValue() {
  if (octavesw == 0) {
    octave = -24;
  } else if (octavesw == 1) {
    octave = -12;
  } else if (octavesw == 2) {
    octave = 0;
  } else if (octavesw == 3) {
    octave = 12;
  } else if (octavesw == 4) {
    octave = 24;
  }
}

void setDetuneBValue() {
  if (detuneBsw == 0) { /// MODIFICAR CON NOTAS QUE VARIAN
    detuneB = -12;
  } else if (detuneBsw == 1) {
    detuneB = -4;
  } else if (detuneBsw == 2) { // selector 3 pos octaveB abajo
    detuneB = 0;
  } else if (detuneBsw == 3) {
    detuneB = 4;
  } else if (detuneBsw == 4) {
    detuneB = 12;
  } else if (detuneBsw == 5) {
    detuneB = 16;
  } else if (detuneBsw == 6) {
    detuneB = 24;
  }
}

void setDetuneCValue() {
  if (detuneCsw == 0) {
    detuneC = -12;
  } else if (detuneCsw == 1) {
    detuneC = -4;
  } else if (detuneCsw == 2) { // selector 3 pos octaveB abajo
    detuneC = 0;
  } else if (detuneCsw == 3) {
    detuneC = 4;
  } else if (detuneCsw == 4) {
    detuneC = 12;
  } else if (detuneCsw == 5) {
    detuneC = 16;
  } else if (detuneCsw == 6) {
    detuneC = 24;
  }
}

void setVcoAFreq() {
  vcoA1.frequency(noteArray[note1freq + octave]); /** bend*/
  vcoA2.frequency(noteArray[note2freq + octave] /** bend*/);
  vcoA3.frequency(noteArray[note3freq + octave] /** bend*/);
  vcoA4.frequency(noteArray[note4freq + octave] /** bend*/);
  vcoA5.frequency(noteArray[note5freq + octave] /** bend*/);
  vcoA6.frequency(noteArray[note6freq + octave] /** bend*/);
  vcoA7.frequency(noteArray[note7freq + octave] /** bend*/);
  vcoA9.frequency(noteArray[note9freq + octave] /** bend*/);
  sub1.frequency(noteArray[note1freq + octave] / 6 /** bend*/);
  sub2.frequency(noteArray[note2freq + octave] / 6 /** bend*/);
  sub3.frequency(noteArray[note3freq + octave] / 6 /** bend*/);
  sub4.frequency(noteArray[note5freq + octave] / 6 /** bend*/);
  sub5.frequency(noteArray[note5freq + octave] / 6 /** bend*/);
  sub6.frequency(noteArray[note6freq + octave] / 6 /** bend*/);
  sub7.frequency(noteArray[note7freq + octave] / 6 /** bend*/);
  sub9.frequency(noteArray[note9freq + octave] / 6 /** bend*/);
}

void setVcoBFreq() {
  vcoB1.frequency(noteArray[note1freq + octave + detuneB] *
                  (1 + fineDetuneB)); /** bend*/
  vcoB2.frequency(noteArray[note2freq + octave + detuneB] *
                  (1 + fineDetuneB)); /** bend*/
  vcoB3.frequency(noteArray[note3freq + octave + detuneB] *
                  (1 + fineDetuneB)); /** bend*/
  vcoB4.frequency(noteArray[note4freq + octave + detuneB] *
                  (1 + fineDetuneB)); /** bend*/
  vcoB5.frequency(noteArray[note5freq + octave + detuneB] *
                  (1 + fineDetuneB)); /** bend*/
  vcoB6.frequency(noteArray[note6freq + octave + detuneB] *
                  (1 + fineDetuneB)); /** bend*/
  vcoB7.frequency(noteArray[note7freq + octave + detuneB] *
                  (1 + fineDetuneB)); /** bend*/
  vcoB9.frequency(noteArray[note9freq + octave + detuneB] *
                  (1 + fineDetuneB)); /** bend*/
}

void setVcoCFreq() {
  vcoC1.frequency(noteArray[note1freq + octave + detuneC] *
                  (1 + fineDetuneC)); /** bend*/
  vcoC2.frequency(noteArray[note2freq + octave + detuneC] *
                  (1 + fineDetuneC)); /** bend*/
  vcoC3.frequency(noteArray[note3freq + octave + detuneC] *
                  (1 + fineDetuneC)); /** bend*/
  vcoC4.frequency(noteArray[note4freq + octave + detuneC] *
                  (1 + fineDetuneC)); /** bend*/
  vcoC5.frequency(noteArray[note5freq + octave + detuneC] *
                  (1 + fineDetuneC)); /** bend*/
  vcoC6.frequency(noteArray[note6freq + octave + detuneC] *
                  (1 + fineDetuneC)); /** bend*/
  vcoC7.frequency(noteArray[note7freq + octave + detuneC] *
                  (1 + fineDetuneC)); /** bend*/
  vcoC9.frequency(noteArray[note9freq + octave + detuneC] *
                  (1 + fineDetuneC)); /** bend*/
}

void setVcoAVol() {
  voiceMix1.gain(0, vcoAvol * mainVol);
  voiceMix2.gain(0, vcoAvol * mainVol);
  voiceMix3.gain(0, vcoAvol * mainVol);
  voiceMix4.gain(0, vcoAvol * mainVol);
  voiceMix5.gain(0, vcoAvol * mainVol);
  voiceMix6.gain(0, vcoAvol * mainVol);
  voiceMix7.gain(0, vcoAvol * mainVol);
  voiceMix9.gain(0, vcoAvol * mainVol);
}

void setSubVol {
  voiceMix1.gain(3, subVol * mainVol);
  voiceMix2.gain(3, subVol * mainVol);
  voiceMix3.gain(3, subVol * mainVol);
  voiceMix4.gain(3, subVol * mainVol);
  voiceMix5.gain(3, subVol * mainVol);
  voiceMix6.gain(3, subVol * mainVol);
  voiceMix7.gain(3, subVol * mainVol);
  voiceMix9.gain(3, subVol * mainVol);
}

void setVcoBVol() {
  voiceMix1.gain(1, vcoBvol * mainVol);
  voiceMix2.gain(1, vcoBvol * mainVol);
  voiceMix3.gain(1, vcoBvol * mainVol);
  voiceMix4.gain(1, vcoBvol * mainVol);
  voiceMix5.gain(1, vcoBvol * mainVol);
  voiceMix6.gain(1, vcoBvol * mainVol);
  voiceMix7.gain(1, vcoBvol * mainVol);
  voiceMix9.gain(1, vcoBvol * mainVol);
}

void setVcoCVol() {
  voiceMix1.gain(2, vcoCvol * mainVol);
  voiceMix2.gain(2, vcoCvol * mainVol);
  voiceMix3.gain(2, vcoCvol * mainVol);
  voiceMix4.gain(2, vcoCvol * mainVol);
  voiceMix5.gain(2, vcoCvol * mainVol);
  voiceMix6.gain(2, vcoCvol * mainVol);
  voiceMix7.gain(2, vcoCvol * mainVol);
  voiceMix9.gain(2, vcoCvol * mainVol);
}

void setShapeA() {
  switch (shapeAsw) {
  case 0:
    vcoA1.begin(WAVEFORM_SINE);
    // vcoA1.amplitude(vcoVol);
    vcoA2.begin(WAVEFORM_SINE);
    // vcoA2.amplitude(vcoVol);
    vcoA3.begin(WAVEFORM_SINE);
    // vcoA3.amplitude(vcoVol);
    vcoA4.begin(WAVEFORM_SINE);
    // vcoA4.amplitude(vcoVol);
    vcoA5.begin(WAVEFORM_SINE);
    // vcoA5.amplitude(vcoVol);
    vcoA6.begin(WAVEFORM_SINE);
    // vcoA6.amplitude(vcoVol);
    vcoA7.begin(WAVEFORM_SINE);
    // vcoA7.amplitude(vcoVol);
    vcoA9.begin(WAVEFORM_SINE);
    // vcoA9.amplitude(vcoVol);
    break;
  case 1:
    vcoA1.begin(WAVEFORM_SAWTOOTH);
    // vcoA1.amplitude(vcoVol);
    vcoA2.begin(WAVEFORM_SAWTOOTH);
    // vcoA2.amplitude(vcoVol);
    vcoA3.begin(WAVEFORM_SAWTOOTH);
    // vcoA3.amplitude(vcoVol);
    vcoA4.begin(WAVEFORM_SAWTOOTH);
    // vcoA4.amplitude(vcoVol);
    vcoA5.begin(WAVEFORM_SAWTOOTH);
    // vcoA5.amplitude(vcoVol);
    vcoA6.begin(WAVEFORM_SAWTOOTH);
    // vcoA6.amplitude(vcoVol);
    vcoA7.begin(WAVEFORM_SAWTOOTH);
    // vcoA7.amplitude(vcoVol);
    vcoA6.begin(WAVEFORM_SAWTOOTH);
    // vcoA9.amplitude(vcoVol);
    break;
  case 2:
    vcoA1.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoA1.amplitude(vcoVol);
    vcoA2.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoA2.amplitude(vcoVol);
    vcoA3.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoA3.amplitude(vcoVol);
    vcoA4.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoA4.amplitude(vcoVol);
    vcoA5.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoA5.amplitude(vcoVol);
    vcoA6.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoA6.amplitude(vcoVol);
    vcoA7.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoA7.amplitude(vcoVol);
    vcoA6.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoA9.amplitude(vcoVol);
    break;
  case 3:
    vcoA1.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoA1.amplitude(vcoVol * 1.5);
    vcoA2.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoA2.amplitude(vcoVol * 1.5);
    vcoA3.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoA3.amplitude(vcoVol * 1.5);
    vcoA4.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoA4.amplitude(vcoVol * 1.5);
    vcoA5.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoA5.amplitude(vcoVol * 1.5);
    vcoA6.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoA6.amplitude(vcoVol * 1.5);
    vcoA7.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoA7.amplitude(vcoVol * 1.5);
    vcoA9.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoA9.amplitude(vcoVol * 1.5);
    break;
  case 4:
    vcoA1.begin(WAVEFORM_PULSE);
    vcoA2.begin(WAVEFORM_PULSE);
    vcoA3.begin(WAVEFORM_PULSE);
    vcoA4.begin(WAVEFORM_PULSE);
    vcoA5.begin(WAVEFORM_PULSE);
    vcoA6.begin(WAVEFORM_PULSE);
    vcoA7.begin(WAVEFORM_PULSE);
    vcoA9.begin(WAVEFORM_PULSE);
    break;
  }
}
void setShapeB() {
  switch (shapeBsw) {
  case 0:
    vcoB1.begin(WAVEFORM_SINE);
    // vcoB1.amplitude(vcoVol);
    vcoB2.begin(WAVEFORM_SINE);
    // vcoB2.amplitude(vcoVol);
    vcoB3.begin(WAVEFORM_SINE);
    // vcoB3.amplitude(vcoVol);
    vcoB4.begin(WAVEFORM_SINE);
    // vcoB4.amplitude(vcoVol);
    vcoB5.begin(WAVEFORM_SINE);
    // vcoA5.amplitude(vcoVol);
    vcoB6.begin(WAVEFORM_SINE);
    // vcoB6.amplitude(vcoVol);
    vcoB7.begin(WAVEFORM_SINE);
    // vcoB7.amplitude(vcoVol);
    vcoB9.begin(WAVEFORM_SINE);
    // vcoB9.amplitude(vcoVol);
    break;
  case 1:
    vcoB1.begin(WAVEFORM_SAWTOOTH);
    // vcoB1.amplitude(vcoVol);
    vcoB2.begin(WAVEFORM_SAWTOOTH);
    // vcoB2.amplitude(vcoVol);
    vcoB3.begin(WAVEFORM_SAWTOOTH);
    // vcoB3.amplitude(vcoVol);
    vcoA4.begin(WAVEFORM_SAWTOOTH);
    // vcoB4.amplitude(vcoVol);
    vcoB5.begin(WAVEFORM_SAWTOOTH);
    // vcoB5.amplitude(vcoVol);
    vcoB6.begin(WAVEFORM_SAWTOOTH);
    // vcoB6.amplitude(vcoVol);
    vcoB7.begin(WAVEFORM_SAWTOOTH);
    // vvcoB7.amplitude(vcoVol);
    vcoB6.begin(WAVEFORM_SAWTOOTH);
    // vcoB9.amplitude(vcoVol);
    break;
  case 2:
    vcoB1.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoB1.amplitude(vcoVol);
    vcoB2.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoB2.amplitude(vcoVol);
    vcoB3.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoB3.amplitude(vcoVol);
    vcoB4.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoB4.amplitude(vcoVol);
    vcoB5.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoB5.amplitude(vcoVol);
    vcoB6.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoB6.amplitude(vcoVol);
    vcoB7.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoB7.amplitude(vcoVol);
    vcoB6.begin(WAVEFORM_SAWTOOTH_REVERSE);
    // vcoB9.amplitude(vcoVol);
    break;
  case 3:
    vcoB1.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoB1.amplitude(vcoVol * 1.5);
    vcoB2.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoB2.amplitude(vcoVol * 1.5);
    vcoB3.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoB3.amplitude(vcoVol * 1.5);
    vcoB4.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoB4.amplitude(vcoVol * 1.5);
    vcoB5.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoB5.amplitude(vcoVol * 1.5);
    vcoB6.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoB6.amplitude(vcoVol * 1.5);
    vcoB7.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoB7.amplitude(vcoVol * 1.5);
    vcoB9.begin(WAVEFORM_TRIANGLE_VARIABLE);
    // vcoB9.amplitude(vcoVol * 1.5);
    break;
  case 4:
    vcoB1.begin(WAVEFORM_PULSE);
    vcoB2.begin(WAVEFORM_PULSE);
    vcoB3.begin(WAVEFORM_PULSE);
    vcoB4.begin(WAVEFORM_PULSE);
    vcoB5.begin(WAVEFORM_PULSE);
    vcoB6.begin(WAVEFORM_PULSE);
    vcoB7.begin(WAVEFORM_PULSE);
    vcoB9.begin(WAVEFORM_PULSE);
    break;
  }
}

void setShapeC() {
  switch (shapeCsw) {
  case 0:
    vcoC1.arbitraryWaveform(wave1, 2000);
    vcoC2.arbitraryWaveform(wave1, 2000);
    vcoC3.arbitraryWaveform(wave1, 2000);
    vcoC4.arbitraryWaveform(wave1, 2000);
    vcoC5.arbitraryWaveform(wave1, 2000);
    vcoC6.arbitraryWaveform(wave1, 2000);
    vcoC7.arbitraryWaveform(wave1, 2000);
    vcoC9.arbitraryWaveform(wave1, 2000);
    break;
  case 1:
    vcoC1.arbitraryWaveform(wave2, 2000);
    vcoC2.arbitraryWaveform(wave2, 2000);
    vcoC3.arbitraryWaveform(wave2, 2000);
    vcoC4.arbitraryWaveform(wave2, 2000);
    vcoC5.arbitraryWaveform(wave2, 2000);
    vcoC6.arbitraryWaveform(wave2, 2000);
    vcoC7.arbitraryWaveform(wave2, 2000);
    vcoC9.arbitraryWaveform(wave2, 2000);
    break;
  case 2:
    vcoC1.arbitraryWaveform(wave3, 2000);
    vcoC2.arbitraryWaveform(wave3, 2000);
    vcoC3.arbitraryWaveform(wave3, 2000);
    vcoC4.arbitraryWaveform(wave3, 2000);
    vcoC5.arbitraryWaveform(wave3, 2000);
    vcoC6.arbitraryWaveform(wave3, 2000);
    vcoC7.arbitraryWaveform(wave3, 2000);
    vcoC9.arbitraryWaveform(wave3, 2000);
    break;
  case 3:
    vcoC1.arbitraryWaveform(wave4, 2000);
    vcoC2.arbitraryWaveform(wave4, 2000);
    vcoC3.arbitraryWaveform(wave4, 2000);
    vcoC4.arbitraryWaveform(wave4, 2000);
    vcoC5.arbitraryWaveform(wave4, 2000);
    vcoC6.arbitraryWaveform(wave4, 2000);
    vcoC7.arbitraryWaveform(wave4, 2000);
    vcoC9.arbitraryWaveform(wave4, 2000);
    break;
  case 4:
    vcoC1.arbitraryWaveform(wave5, 2000);
    vcoC2.arbitraryWaveform(wave5, 2000);
    vcoC3.arbitraryWaveform(wave5, 2000);
    vcoC4.arbitraryWaveform(wave5, 2000);
    vcoC5.arbitraryWaveform(wave5, 2000);
    vcoC6.arbitraryWaveform(wave5, 2000);
    vcoC7.arbitraryWaveform(wave5, 2000);
    vcoC9.arbitraryWaveform(wave5, 2000);
    break;
  case 5:
    vcoC1.arbitraryWaveform(wave6, 2000);
    vcoC2.arbitraryWaveform(wave6, 2000);
    vcoC3.arbitraryWaveform(wave6, 2000);
    vcoC4.arbitraryWaveform(wave6, 2000);
    vcoC5.arbitraryWaveform(wave6, 2000);
    vcoC6.arbitraryWaveform(wave6, 2000);
    vcoC7.arbitraryWaveform(wave6, 2000);
    vcoC9.arbitraryWaveform(wave6, 2000);
    break;
  case 6:
    vcoC1.arbitraryWaveform(wave7, 2000);
    vcoC2.arbitraryWaveform(wave7, 2000);
    vcoC3.arbitraryWaveform(wave7, 2000);
    vcoC4.arbitraryWaveform(wave7, 2000);
    vcoC5.arbitraryWaveform(wave7, 2000);
    vcoC6.arbitraryWaveform(wave7, 2000);
    vcoC7.arbitraryWaveform(wave7, 2000);
    vcoC9.arbitraryWaveform(wave7, 2000);
    break;
  case 7:
    vcoC1.arbitraryWaveform(wave8, 2000);
    vcoC2.arbitraryWaveform(wave8, 2000);
    vcoC3.arbitraryWaveform(wave8, 2000);
    vcoC4.arbitraryWaveform(wave8, 2000);
    vcoC5.arbitraryWaveform(wave8, 2000);
    vcoC6.arbitraryWaveform(wave8, 2000);
    vcoC7.arbitraryWaveform(wave8, 2000);
    vcoC9.arbitraryWaveform(wave8, 2000);
    break;
  case 8:
    vcoC1.arbitraryWaveform(wave9, 2000);
    vcoC2.arbitraryWaveform(wave9, 2000);
    vcoC3.arbitraryWaveform(wave9, 2000);
    vcoC4.arbitraryWaveform(wave9, 2000);
    vcoC5.arbitraryWaveform(wave9, 2000);
    vcoC6.arbitraryWaveform(wave9, 2000);
    vcoC7.arbitraryWaveform(wave9, 2000);
    vcoC9.arbitraryWaveform(wave9, 2000);
    break;
  case 9:
    vcoC1.arbitraryWaveform(wave10, 2000);
    vcoC2.arbitraryWaveform(wave10, 2000);
    vcoC3.arbitraryWaveform(wave10, 2000);
    vcoC4.arbitraryWaveform(wave10, 2000);
    vcoC5.arbitraryWaveform(wave10, 2000);
    vcoC6.arbitraryWaveform(wave10, 2000);
    vcoC7.arbitraryWaveform(wave10, 2000);
    vcoC9.arbitraryWaveform(wave10, 2000);
    break;
  case 10:
    vcoC1.arbitraryWaveform(wave11, 2000);
    vcoC2.arbitraryWaveform(wave11, 2000);
    vcoC3.arbitraryWaveform(wave11, 2000);
    vcoC4.arbitraryWaveform(wave11, 2000);
    vcoC5.arbitraryWaveform(wave11, 2000);
    vcoC6.arbitraryWaveform(wave11, 2000);
    vcoC7.arbitraryWaveform(wave11, 2000);
    vcoC9.arbitraryWaveform(wave11, 2000);
    break;
  case 11:
    vcoC1.arbitraryWaveform(wave12, 2000);
    vcoC2.arbitraryWaveform(wave12, 2000);
    vcoC3.arbitraryWaveform(wave12, 2000);
    vcoC4.arbitraryWaveform(wave12, 2000);
    vcoC5.arbitraryWaveform(wave12, 2000);
    vcoC6.arbitraryWaveform(wave12, 2000);
    vcoC7.arbitraryWaveform(wave12, 2000);
    vcoC9.arbitraryWaveform(wave12, 2000);
    break;
  case 12:
    vcoC1.arbitraryWaveform(wave13, 2000);
    vcoC2.arbitraryWaveform(wave13, 2000);
    vcoC3.arbitraryWaveform(wave13, 2000);
    vcoC4.arbitraryWaveform(wave13, 2000);
    vcoC5.arbitraryWaveform(wave13, 2000);
    vcoC6.arbitraryWaveform(wave13, 2000);
    vcoC7.arbitraryWaveform(wave13, 2000);
    vcoC9.arbitraryWaveform(wave13, 2000);
    break;
  case 13:
    vcoC1.arbitraryWaveform(wave14, 2000);
    vcoC2.arbitraryWaveform(wave14, 2000);
    vcoC3.arbitraryWaveform(wave14, 2000);
    vcoC4.arbitraryWaveform(wave14, 2000);
    vcoC5.arbitraryWaveform(wave14, 2000);
    vcoC6.arbitraryWaveform(wave14, 2000);
    vcoC7.arbitraryWaveform(wave14, 2000);
    vcoC9.arbitraryWaveform(wave14, 2000);
    break;
  case 14:
    vcoC1.arbitraryWaveform(wave15, 2000);
    vcoC2.arbitraryWaveform(wave15, 2000);
    vcoC3.arbitraryWaveform(wave15, 2000);
    vcoC4.arbitraryWaveform(wave15, 2000);
    vcoC5.arbitraryWaveform(wave15, 2000);
    vcoC6.arbitraryWaveform(wave15, 2000);
    vcoC7.arbitraryWaveform(wave15, 2000);
    vcoC9.arbitraryWaveform(wave15, 2000);
    break;
  case 15:
    vcoC1.arbitraryWaveform(wave16, 2000);
    vcoC2.arbitraryWaveform(wave16, 2000);
    vcoC3.arbitraryWaveform(wave16, 2000);
    vcoC4.arbitraryWaveform(wave16, 2000);
    vcoC5.arbitraryWaveform(wave16, 2000);
    vcoC6.arbitraryWaveform(wave16, 2000);
    vcoC7.arbitraryWaveform(wave16, 2000);
    vcoC9.arbitraryWaveform(wave16, 2000);
    break;
  case 16:
    vcoC1.arbitraryWaveform(wave17, 2000);
    vcoC2.arbitraryWaveform(wave17, 2000);
    vcoC3.arbitraryWaveform(wave17, 2000);
    vcoC4.arbitraryWaveform(wave17, 2000);
    vcoC5.arbitraryWaveform(wave17, 2000);
    vcoC6.arbitraryWaveform(wave17, 2000);
    vcoC7.arbitraryWaveform(wave17, 2000);
    vcoC9.arbitraryWaveform(wave17, 2000);
    break;
  case 17:
    vcoC1.arbitraryWaveform(wave18, 2000);
    vcoC2.arbitraryWaveform(wave18, 2000);
    vcoC3.arbitraryWaveform(wave18, 2000);
    vcoC4.arbitraryWaveform(wave18, 2000);
    vcoC5.arbitraryWaveform(wave18, 2000);
    vcoC6.arbitraryWaveform(wave18, 2000);
    vcoC7.arbitraryWaveform(wave18, 2000);
    vcoC9.arbitraryWaveform(wave18, 2000);
    break;
  case 18:
    vcoC1.arbitraryWaveform(wave19, 2000);
    vcoC2.arbitraryWaveform(wave19, 2000);
    vcoC3.arbitraryWaveform(wave19, 2000);
    vcoC4.arbitraryWaveform(wave19, 2000);
    vcoC5.arbitraryWaveform(wave19, 2000);
    vcoC6.arbitraryWaveform(wave19, 2000);
    vcoC7.arbitraryWaveform(wave19, 2000);
    vcoC9.arbitraryWaveform(wave19, 2000);
    break;
  case 19:
    vcoC1.arbitraryWaveform(wave20, 2000);
    vcoC2.arbitraryWaveform(wave20, 2000);
    vcoC3.arbitraryWaveform(wave20, 2000);
    vcoC4.arbitraryWaveform(wave20, 2000);
    vcoC5.arbitraryWaveform(wave20, 2000);
    vcoC6.arbitraryWaveform(wave20, 2000);
    vcoC7.arbitraryWaveform(wave20, 2000);
    vcoC9.arbitraryWaveform(wave20, 2000);
    break;
  case 20:
    vcoC1.arbitraryWaveform(wave21, 2000);
    vcoC2.arbitraryWaveform(wave21, 2000);
    vcoC3.arbitraryWaveform(wave21, 2000);
    vcoC4.arbitraryWaveform(wave21, 2000);
    vcoC5.arbitraryWaveform(wave21, 2000);
    vcoC6.arbitraryWaveform(wave21, 2000);
    vcoC7.arbitraryWaveform(wave21, 2000);
    vcoC9.arbitraryWaveform(wave21, 2000);
    break;
  case 21:
    vcoC1.arbitraryWaveform(wave22, 2000);
    vcoC2.arbitraryWaveform(wave22, 2000);
    vcoC3.arbitraryWaveform(wave22, 2000);
    vcoC4.arbitraryWaveform(wave22, 2000);
    vcoC5.arbitraryWaveform(wave22, 2000);
    vcoC6.arbitraryWaveform(wave22, 2000);
    vcoC7.arbitraryWaveform(wave22, 2000);
    vcoC9.arbitraryWaveform(wave22, 2000);
    break;
  case 22:
    vcoC1.arbitraryWaveform(wave23, 2000);
    vcoC2.arbitraryWaveform(wave23, 2000);
    vcoC3.arbitraryWaveform(wave23, 2000);
    vcoC4.arbitraryWaveform(wave23, 2000);
    vcoC5.arbitraryWaveform(wave23, 2000);
    vcoC6.arbitraryWaveform(wave23, 2000);
    vcoC7.arbitraryWaveform(wave23, 2000);
    vcoC9.arbitraryWaveform(wave23, 2000);
    break;
  case 23:
    vcoC1.arbitraryWaveform(wave24, 2000);
    vcoC2.arbitraryWaveform(wave24, 2000);
    vcoC3.arbitraryWaveform(wave24, 2000);
    vcoC4.arbitraryWaveform(wave24, 2000);
    vcoC5.arbitraryWaveform(wave24, 2000);
    vcoC6.arbitraryWaveform(wave24, 2000);
    vcoC7.arbitraryWaveform(wave24, 2000);
    vcoC9.arbitraryWaveform(wave24, 2000);
    break;
  case 24:
    vcoC1.arbitraryWaveform(wave25, 2000);
    vcoC2.arbitraryWaveform(wave25, 2000);
    vcoC3.arbitraryWaveform(wave25, 2000);
    vcoC4.arbitraryWaveform(wave25, 2000);
    vcoC5.arbitraryWaveform(wave25, 2000);
    vcoC6.arbitraryWaveform(wave25, 2000);
    vcoC7.arbitraryWaveform(wave25, 2000);
    vcoC9.arbitraryWaveform(wave25, 2000);
    break;
  case 25:
    vcoC1.arbitraryWaveform(wave26, 2000);
    vcoC2.arbitraryWaveform(wave26, 2000);
    vcoC3.arbitraryWaveform(wave26, 2000);
    vcoC4.arbitraryWaveform(wave26, 2000);
    vcoC5.arbitraryWaveform(wave26, 2000);
    vcoC6.arbitraryWaveform(wave26, 2000);
    vcoC7.arbitraryWaveform(wave26, 2000);
    vcoC9.arbitraryWaveform(wave26, 2000);
    break;
  case 26:
    vcoC1.arbitraryWaveform(wave27, 2000);
    vcoC2.arbitraryWaveform(wave27, 2000);
    vcoC3.arbitraryWaveform(wave27, 2000);
    vcoC4.arbitraryWaveform(wave27, 2000);
    vcoC5.arbitraryWaveform(wave27, 2000);
    vcoC6.arbitraryWaveform(wave27, 2000);
    vcoC7.arbitraryWaveform(wave27, 2000);
    vcoC9.arbitraryWaveform(wave27, 2000);
    break;
  case 27:
    vcoC1.arbitraryWaveform(wave28, 2000);
    vcoC2.arbitraryWaveform(wave28, 2000);
    vcoC3.arbitraryWaveform(wave28, 2000);
    vcoC4.arbitraryWaveform(wave28, 2000);
    vcoC5.arbitraryWaveform(wave28, 2000);
    vcoC6.arbitraryWaveform(wave28, 2000);
    vcoC7.arbitraryWaveform(wave28, 2000);
    vcoC9.arbitraryWaveform(wave28, 2000);
    break;
  }
}

void setShapeAAdj() {
  // float Osc2FormValue = (1-(0.85 * (value * DIV127)));
  VcoA1.pulseWidth(ShapeAAdj);
  VcoA2.pulseWidth(ShapeAAdj);
  VcoA3.pulseWidth(ShapeAAdj);
  VcoA4.pulseWidth(ShapeAAdj);
  VcoA5.pulseWidth(ShapeAAdj);
  VcoA6.pulseWidth(ShapeAAdj);
  VcoA7.pulseWidth(ShapeAAdj);
  VcoA9.pulseWidth(ShapeAAdj);
}

void setShapeBAdj() {
  // float Osc2FormValue = (1-(0.85 * (value * DIV127)));
  VcoB1.pulseWidth(ShapeAAdj);
  VcoB2.pulseWidth(ShapeAAdj);
  VcoB3.pulseWidth(ShapeAAdj);
  VcoB4.pulseWidth(ShapeAAdj);
  VcoB5.pulseWidth(ShapeAAdj);
  VcoB6.pulseWidth(ShapeAAdj);
  VcoB7.pulseWidth(ShapeAAdj);
  VcoB9.pulseWidth(ShapeAAdj);
}

void setCrossMod() {
  modMix1.gain(0, crossMod);
  modMix2.gain(0, crossMod);
  modMix3.gain(0, crossMod);
  modMix4.gain(0, crossMod);
  modMix5.gain(0, crossMod);
  modMix6.gain(0, crossMod);
  modMix7.gain(0, crossMod);
  modMix9.gain(0, crossMod);
}

void setVCFCut {
  filter1.frequency(VCFCut);
  filter2.frequency(VCFCut);
  filter3.frequency(VCFCut);
  filter4.frequency(VCFCut);
  filter5.frequency(VCFCut);
  filter6.frequency(VCFCut);
  filter7.frequency(VCFCut);
  filter9.frequency(VCFCut);
}

void setVCFRes {
  filter1.resonance(VCFRes);
  filter2.resonance(VCFRes);
  filter3.resonance(VCFRes);
  filter4.resonance(VCFRes);
  filter5.resonance(VCFRes);
  filter6.resonance(VCFRes);
  filter7.resonance(VCFRes);
  filter9.resonance(VCFRes);
}

void setVCFAmt {
  dc1.amplitude(VCFAmt);
  dc2.amplitude(VCFAmt);
  dc3.amplitude(VCFAmt);
  dc4.amplitude(VCFAmt);
  dc5.amplitude(VCFAmt);
  dc6.amplitude(VCFAmt);
  dc7.amplitude(VCFAmt);
  dc9.amplitude(VCFAmt);
}

void setVCFAtt {
  filterEnv1.attack(VCFAtt);
  filterEnv2.attack(VCFAtt);
  filterEnv3.attack(VCFAtt);
  filterEnv4.attack(VCFAtt);
  filterEnv5.attack(VCFAtt);
  filterEnv6.attack(VCFAtt);
  filterEnv7.attack(VCFAtt);
  filterEnv9.attack(VCFAtt);
}

void setVCFDec {
  filterEnv1.decay(VCFDec);
  filterEnv2.decay(VCFDec);
  filterEnv3.decay(VCFDec);
  filterEnv4.decay(VCFDec);
  filterEnv5.decay(VCFDec);
  filterEnv6.decay(VCFDec);
  filterEnv7.decay(VCFDec);
  filterEnv9.decay(VCFDec);
}

void setVCFSust {
  filterEnv1.sustain(VCFSust);
  filterEnv2.sustain(VCFSust);
  filterEnv3.sustain(VCFSust);
  filterEnv4.sustain(VCFSust);
  filterEnv5.sustain(VCFSust);
  filterEnv6.sustain(VCFSust);
  filterEnv7.sustain(VCFSust);
  filterEnv9.sustain(VCFSust);
}

void setVCFRel {
  filterEnv1.release(VCFRel);
  filterEnv2.release(VCFRel);
  filterEnv3.release(VCFRel);
  filterEnv4.release(VCFRel);
  filterEnv5.release(VCFRel);
  filterEnv6.release(VCFRel);
  filterEnv7.release(VCFRel);
  filterEnv9.release(VCFRel);
}

void setEnvAtt() {
  env1.attack(envAttpot);
  env2.attack(envAttpot);
  env3.attack(envAttpot);
  env4.attack(envAttpot);
  env5.attack(envAttpot);
  env6.attack(envAttpot);
  env7.attack(envAttpot);
  env9.attack(envAttpot);
}

void setEnvDec() {
  env1.decay(envDecpot);
  env2.decay(envDecpot);
  env3.decay(envDecpot);
  env4.decay(envDecpot);
  env5.decay(envDecpot);
  env6.decay(envDecpot);
  env7.decay(envDecpot);
  env9.decay(envDecpot);
}

void setEnvSust() {
  env1.sustain(envSustpot);
  env2.sustain(envSustpot);
  env3.sustain(envSustpot);
  env4.sustain(envSustpot);
  env5.sustain(envSustpot);
  env6.sustain(envSustpot);
  env7.sustain(envSustpot);
  env9.sustain(envSustpot);
}

void setEnvRel() {
  env1.release(envRelpot);
  env2.release(envRelpot);
  env3.release(envRelpot);
  env4.release(envRelpot);
  env5.release(envRelpot);
  env6.release(envRelpot);
  env7.release(envRelpot);
  env9.release(envRelpot);
}

void setLfoFreq() {
  lfoA1.frequency(lfoFreq);
  lfoA2.frequency(lfoFreq);
  lfoA3.frequency(lfoFreq);
  lfoA4.frequency(lfoFreq);
  lfoA5.frequency(lfoFreq);
  lfoA6.frequency(lfoFreq);
  lfoA7.frequency(lfoFreq);
  lfoA9.frequency(lfoFreq);
}

void setVCFMode() {
  // filter mode  ESTO es VCF  ---> LP/BP
  switch (VCFModesw) {
  case 0:
    filterMode1.gain(0, 0);
    filterMode1.gain(1, 1);
    filterMode2.gain(0, 0);
    filterMode2.gain(1, 1);
    filterMode3.gain(0, 0);
    filterMode3.gain(1, 1);
    filterMode4.gain(0, 0);
    filterMode4.gain(1, 1);
    filterMode5.gain(0, 0);
    filterMode5.gain(1, 1);
    filterMode6.gain(0, 0);
    filterMode6.gain(1, 1);
    filterMode7.gain(0, 0);
    filterMode7.gain(1, 1);
    filterMode9.gain(0, 0);
    filterMode9.gain(1, 1);
    break;
  case 1:
    filterMode1.gain(0, 1);
    filterMode1.gain(1, 0);
    filterMode2.gain(0, 1);
    filterMode2.gain(1, 0);
    filterMode3.gain(0, 1);
    filterMode3.gain(1, 0);
    filterMode4.gain(0, 1);
    filterMode4.gain(1, 0);
    filterMode5.gain(0, 1);
    filterMode5.gain(1, 0);
    filterMode6.gain(0, 1);
    filterMode6.gain(1, 0);
    filterMode7.gain(0, 1);
    filterMode7.gain(1, 0);
    filterMode9.gain(0, 1);
    filterMode9.gain(1, 0);
    break;
  }
}

void setLfoDest() { // LFO A DESTINATION                     ES LFO!!!!!
  switch (lfoDestsw) {
  case 0: // lfo - pitch
    // 1
    patchCord9.connect();  // vcoA
    patchCord10.connect(); // vcoB
    patchCord11.connect(); // vcoC
    patchCord12.connect(); // sub
    // 2
    patchCord4.connect(); // vcoA
    patchCord5.connect(); // vcoB
    patchCord6.connect(); // vcoC
    patchCord7.connect(); // sub
    // 3
    patchCord24.connect(); // vcoA
    patchCord25.connect(); // vcoB
    patchCord22.connect(); // vcoC
    patchCord27.connect(); // sub
    // 4
    patchCord58.connect(); // vcoA
    patchCord59.connect(); // vcoB
    patchCord60.connect(); // vcoC
    patchCord61.connect(); // sub
    // 5
    patchCord37.connect(); // vcoA
    patchCord38.connect(); // vcoB
    patchCord39.connect(); // vcoC
    patchCord40.connect(); // sub
    // 6
    patchCord42.connect(); // vcoA
    patchCord43.connect(); // vcoB
    patchCord44.connect(); // vcoC
    patchCord45.connect(); // sub
    // 7
    patchCord32.connect(); // vcoA
    patchCord33.connect(); // vcoB
    patchCord34.connect(); // vcoC
    patchCord35.connect(); // sub
    // 9
    patchCord51.connect(); // vcoA
    patchCord52.connect(); // vcoB
    patchCord53.connect(); // vcoC
    patchCord54.connect(); // sub

    patchCord13.disconnect(); // filter
    patchCord8.disconnect();  // filter
    patchCord28.disconnect(); // filter
    patchCord62.disconnect(); // filter
    patchCord41.disconnect(); // filter
    patchCord46.disconnect(); // filter
    patchCord36.disconnect(); // filter
    patchCord55.disconnect(); // filter

    patchCord14.disconnect(); // lfoAread.
    break;

  case 1: // lfo - filter
    // 1
    patchCord9.disconnect();  // vcoA
    patchCord10.disconnect(); // vcoB
    patchCord11.disconnect(); // vcoC
    patchCord12.disconnect(); // sub
    // 2
    patchCord4.disconnect(); // vcoA
    patchCord5.disconnect(); // vcoB
    patchCord6.disconnect(); // vcoC
    patchCord7.disconnect(); // sub
    // 3
    patchCord24.disconnect(); // vcoA
    patchCord25.disconnect(); // vcoB
    patchCord22.disconnect(); // vcoC
    patchCord27.disconnect(); // sub
    // 4
    patchCord58.disconnect(); // vcoA
    patchCord59.disconnect(); // vcoB
    patchCord60.disconnect(); // vcoC
    patchCord61.disconnect(); // sub
    // 5
    patchCord37.disconnect(); // vcoA
    patchCord38.disconnect(); // vcoB
    patchCord39.disconnect(); // vcoC
    patchCord40.disconnect(); // sub
    // 6
    patchCord42.disconnect(); // vcoA
    patchCord43.disconnect(); // vcoB
    patchCord44.disconnect(); // vcoC
    patchCord45.disconnect(); // sub
    // 7
    patchCord32.disconnect(); // vcoA
    patchCord33.disconnect(); // vcoB
    patchCord34.disconnect(); // vcoC
    patchCord35.disconnect(); // sub
    // 9
    patchCord51.disconnect(); // vcoA
    patchCord52.disconnect(); // vcoB
    patchCord53.disconnect(); // vcoC
    patchCord54.disconnect(); // sub

    patchCord11.connect(); // filter
    patchCord19.connect(); // filter
    patchCord24.connect(); // filter
    patchCord29.connect(); // filter
    patchCord40.connect(); // filter
    patchCord45.connect(); // filter

    patchCord14.disconnect(); // lfoAread.
    break;

  case 2: // lfo - amp
    // 1
    patchCord9.disconnect();  // vcoA
    patchCord10.disconnect(); // vcoB
    patchCord11.disconnect(); // vcoC
    patchCord12.disconnect(); // sub
    // 2
    patchCord4.disconnect(); // vcoA
    patchCord5.disconnect(); // vcoB
    patchCord6.disconnect(); // vcoC
    patchCord7.disconnect(); // sub
    // 3
    patchCord24.disconnect(); // vcoA
    patchCord25.disconnect(); // vcoB
    patchCord22.disconnect(); // vcoC
    patchCord27.disconnect(); // sub
    // 4
    patchCord58.disconnect(); // vcoA
    patchCord59.disconnect(); // vcoB
    patchCord60.disconnect(); // vcoC
    patchCord61.disconnect(); // sub
    // 5
    patchCord37.disconnect(); // vcoA
    patchCord38.disconnect(); // vcoB
    patchCord39.disconnect(); // vcoC
    patchCord40.disconnect(); // sub
    // 6
    patchCord42.disconnect(); // vcoA
    patchCord43.disconnect(); // vcoB
    patchCord44.disconnect(); // vcoC
    patchCord45.disconnect(); // sub
    // 7
    patchCord32.disconnect(); // vcoA
    patchCord33.disconnect(); // vcoB
    patchCord34.disconnect(); // vcoC
    patchCord35.disconnect(); // sub
    // 9
    patchCord51.disconnect(); // vcoA
    patchCord52.disconnect(); // vcoB
    patchCord53.disconnect(); // vcoC
    patchCord54.disconnect(); // sub

    patchCord11.disconnect(); // filter
    patchCord19.disconnect(); // filter
    patchCord24.disconnect(); // filter
    patchCord29.disconnect(); // filter
    patchCord40.disconnect(); // filter
    patchCord45.disconnect(); // filter

    patchCord14.connect(); // lfoAread.
    break;
  }
}

void setLfoAmp() {
  lfoA1.amplitude(lfoAmp);
  lfoA2.amplitude(lfoAmp);
  lfoA3.amplitude(lfoAmp);
  lfoA4.amplitude(lfoAmp);
  lfoA5.amplitude(lfoAmp);
  lfoA6.amplitude(lfoAmp);
  lfoA7.amplitude(lfoAmp);
  lfoA9.amplitude(lfoAmp);
}

void setLfoDel() {
  lfoAenv1.delay(lfoDel);
  lfoAenv2.delay(lfoDel);
  lfoAenv3.delay(lfoDel);
  lfoAenv4.delay(lfoDel);
  lfoAenv5.delay(lfoDel);
  lfoAenv5.delay(lfoDel);
  lfoAenv6.delay(lfoDel);
  lfoAenv7.delay(lfoDel);
  lfoAenv9.delay(lfoDel);
}

void setLfoAtt() {
  lfoAenv1.attack(lfoAtt);
  lfoAenv2.attack(lfoAtt);
  lfoAenv3.attack(lfoAtt);
  lfoAenv4.attack(lfoAtt);
  lfoAenv5.attack(lfoAtt);
  lfoAenv6.attack(lfoAtt);
  lfoAenv7.attack(lfoAtt);
  lfoAenv9.attack(lfoAtt);
}

void setLfoDec() {
  lfoAenv1.decay(lfoDec);
  lfoAenv2.decay(lfoDec);
  lfoAenv3.decay(lfoDec);
  lfoAenv4.decay(lfoDec);
  lfoAenv5.decay(lfoDec);
  lfoAenv6.decay(lfoDec);
  lfoAenv7.decay(lfoDec);
  lfoAenv9.decay(lfoDec);
}

void setLfoSust() {
  lfoAenv1.sustain(lfoSust);
  lfoAenv2.sustain(lfoSust);
  lfoAenv3.sustain(lfoSust);
  lfoAenv4.sustain(lfoSust);
  lfoAenv5.sustain(lfoSust);
  lfoAenv6.sustain(lfoSust);
  lfoAenv7.sustain(lfosust);
  lfoAenv9.sustain(lfoSust);
}

void setLfoRel() {
  lfoAenv1.release(lfoRel);
  lfoAenv2.release(lfoRel);
  lfoAenv3.release(lfoRel);
  lfoAenv4.release(lfoRel);
  lfoAenv5.release(lfoRel);
  lfoAenv6.release(lfoRel);
  lfoAenv7.release(lforel);
  lfoAenv9.release(lfoRel);
}

void setLfoShape() { // LFO shape switch
  switch (lfoShapesw) {
  case 0:
    lfoA1.begin(WAVEFORM_SINE);
    lfoA2.begin(WAVEFORM_SINE);
    lfoA3.begin(WAVEFORM_SINE);
    lfoA4.begin(WAVEFORM_SINE);
    lfoA5.begin(WAVEFORM_SINE);
    lfoA6.begin(WAVEFORM_SINE);
    lfoA7.begin(WAVEFORM_SINE);
    lfoA9.begin(WAVEFORM_SINE);
    break;
  case 1:
    lfoA1.begin(WAVEFORM_SAWTOOTH);
    lfoA2.begin(WAVEFORM_SAWTOOTH);
    lfoA3.begin(WAVEFORM_SAWTOOTH);
    lfoA4.begin(WAVEFORM_SAWTOOTH);
    lfoA5.begin(WAVEFORM_SAWTOOTH);
    lfoA6.begin(WAVEFORM_SAWTOOTH);
    lfoA7.begin(WAVEFORM_SAWTOOTH);
    lfoA9.begin(WAVEFORM_SAWTOOTH);
    break;
  case 2:
    lfoA1.begin(WAVEFORM_SAWTOOTH_REVERSE);
    lfoA2.begin(WAVEFORM_SAWTOOTH_REVERSE);
    lfoA3.begin(WAVEFORM_SAWTOOTH_REVERSE);
    lfoA4.begin(WAVEFORM_SAWTOOTH_REVERSE);
    lfoA5.begin(WAVEFORM_SAWTOOTH_REVERSE);
    lfoA6.begin(WAVEFORM_SAWTOOTH_REVERSE);
    lfoA7.begin(WAVEFORM_SAWTOOTH_REVERSE);
    lfoA9.begin(WAVEFORM_SAWTOOTH_REVERSE);
    break;
  case 3:
    lfoA1.begin(WAVEFORM_TRIANGLE_VARIABLE);
    lfoA2.begin(WAVEFORM_TRIANGLE_VARIABLE);
    lfoA3.begin(WAVEFORM_TRIANGLE_VARIABLE);
    lfoA4.begin(WAVEFORM_TRIANGLE_VARIABLE);
    lfoA5.begin(WAVEFORM_TRIANGLE_VARIABLE);
    lfoA6.begin(WAVEFORM_TRIANGLE_VARIABLE);
    lfoA7.begin(WAVEFORM_TRIANGLE_VARIABLE);
    lfoA9.begin(WAVEFORM_TRIANGLE_VARIABLE);
    break;
  case 4:
    lfoA1.begin(WAVEFORM_PULSE);
    lfoA2.begin(WAVEFORM_PULSE);
    lfoA3.begin(WAVEFORM_PULSE);
    lfoA4.begin(WAVEFORM_PULSE);
    lfoA5.begin(WAVEFORM_PULSE);
    lfoA6.begin(WAVEFORM_PULSE);
    lfoA7.begin(WAVEFORM_PULSE);
    lfoA9.begin(WAVEFORM_PULSE);
    break;
  case 5:
    lfoA1.begin(WAVEFORM_SAMPLE_HOLD);
    lfoA2.begin(WAVEFORM_SAMPLE_HOLD);
    lfoA3.begin(WAVEFORM_SAMPLE_HOLD);
    lfoA4.begin(WAVEFORM_SAMPLE_HOLD);
    lfoA5.begin(WAVEFORM_SAMPLE_HOLD);
    lfoA6.begin(WAVEFORM_SAMPLE_HOLD);
    lfoA7.begin(WAVEFORM_SAMPLE_HOLD);
    lfoA9.begin(WAVEFORM_SAMPLE_HOLD);
    break;
  }
}

/*//lfo A read ESTO A VER PARA QUE SIRVE
  unsigned long currTime = millis();
  if (currTime - prevTime >= readInt) {
  ampMod = lfoAread1.read();
  prevTime = currTime;
  }
  finalMix.gain(0, (1 - (ampMod * 3.2)));
  finalMix.gain(1, (1 - (ampMod * 3.2)));*/

void setPWMAmp() {
  lfoB1.amplitude(PWMAmp);
  lfoB2.amplitude(PWMamp);
  lfoB3.amplitude(PWMAmp);
  lfoB4.amplitude(PWMAmp);
  lfoB5.amplitude(PWMAmp);
  lfoB6.amplitude(PWMAmp);
  lfoB7.amplitude(PWMAmp);
  lfoB9.amplitude(PWMAmp);
}

void setPWMFreq() {
  lfoB1.frequency(PWMFreq);
  lfoB2.frequency(PWMFreq);
  lfoB3.frequency(PWMFreq);
  lfoB4.frequency(PWMFreq);
  lfoB5.frequency(PWMFreq);
  lfoB6.frequency(PWMFreq);
  lfoB7.frequency(PWMFreq);
  lfoB9.frequency(PWMFreq);
}

/*void setFX () {
  dlyL.delay(0, dlyTimeL);
  dlyMixL.gain(1, dlyAmt * 0.9);

  dlyR.delay(0, dlyTimeR);
  dlyMixR.gain(1, (dlyAmt / 1.4 ) * 0.9);

*/
// reverb
}

void setOutputGain() {
  fxL.gain(0, outGain - revMix / 1.6);
  fxL.gain(2, outGain - revMix / 1.6);

  fxR.gain(0, outGain - revMix / 1.6);
  fxR.gain(2, outGain - revMix / 1.6);
}