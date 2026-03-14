void setup() {
  Serial.begin(9600);
  AudioMemory(470);

  // Midi setup
  usbMIDI.begin();
  MIDI.begin(MIDI_CHANNEL_OMNI);
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);
  // usbMIDI.setHandleControlChange(myControlChange);
  MIDI.setHandleNoteOn(myNoteOn);
  MIDI.setHandleNoteOff(myNoteOff);
  // MIDI.setHandleControlChange(myControlChange);

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);

  // Mux setup
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);

  digitalWrite(28, 0);
  digitalWrite(29, 0);
  digitalWrite(30, 0);
  digitalWrite(31, 0);

  // vco setup
  vcoA1.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB1.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC1.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub1.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA2.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB2.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC2.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub2.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA3.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB3.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC3.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub3.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA4.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB4.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC4.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub4.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA5.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB5.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC5.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub5.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA6.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB6.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC6.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub6.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA7.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB7.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC7.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub7.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  vcoA9.begin(vcoVol, 150, WAVEFORM_SAWTOOTH);
  vcoB9.begin(vcoVol, 150, WAVEFORM_SQUARE);
  vcoC9.begin(vcoVol * 1.5, 150, WAVEFORM_ARBITRARY);
  sub9.begin(vcoVol * 1.5, 150, WAVEFORM_TRIANGLE);

  // filter
  filter1.octaveControl(7);
  filterEnv1.sustain(0);

  filter2.octaveControl(7);
  filterEnv2.sustain(0);

  filter3.octaveControl(7);
  filterEnv3.sustain(0);

  filter4.octaveControl(7);
  filterEnv4.sustain(0);

  filter5.octaveControl(7);
  filterEnv5.sustain(0);

  filter6.octaveControl(7);
  filterEnv6.sustain(0);

  filter7.octaveControl(7);
  filterEnv7.sustain(0);

  filter9.octaveControl(7);
  filterEnv9.sustain(0);

  // lfo A
  lfoA1.begin(WAVEFORM_SINE);
  lfoA2.begin(WAVEFORM_SINE);
  lfoA3.begin(WAVEFORM_SINE);
  lfoA4.begin(WAVEFORM_SINE);
  lfoA5.begin(WAVEFORM_SINE);
  lfoA6.begin(WAVEFORM_SINE);
  lfoA7.begin(WAVEFORM_SINE);
  lfoA9.begin(WAVEFORM_SINE);

  // lfo B
  lfoB1.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB2.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB3.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB4.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB5.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB6.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB7.begin(0.5, 1, WAVEFORM_TRIANGLE);
  lfoB9.begin(0.5, 1, WAVEFORM_TRIANGLE);

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

  // LFO DESTINATION DISCONNECT
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

  patchCord13.disconnect(); // filter
  patchCord8.disconnect();  // filter
  patchCord28.disconnect(); // filter
  patchCord62.disconnect(); // filter
  patchCord41.disconnect(); // filter
  patchCord46.disconnect(); // filter
  patchCord36.disconnect(); // filter
  patchCord55.disconnect(); // filter
};