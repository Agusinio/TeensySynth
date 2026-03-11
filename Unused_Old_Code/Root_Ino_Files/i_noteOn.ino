void myNoteOn(byte channel, byte note, byte velocity) {

  if (synthModesw == 1) { // POLYPHONIC mode
    switch (voices) {
    case 0 ... 8:
      if (env1on == false) {
        note1freq = note;
        env1.noteOn();
        filterEnv1.noteOn();
        lfoAenv1.noteOn();
        env1on = true;

      } else if (env2on == false) {
        note2freq = note;
        env2.noteOn();
        filterEnv2.noteOn();
        lfoAenv2.noteOn();
        env2on = true;

      } else if (env3on == false) {
        note3freq = note;
        env3.noteOn();
        filterEnv3.noteOn();
        lfoAenv3.noteOn();
        env3on = true;

      } else if (env4on == false) {
        note4freq = note;
        env4.noteOn();
        filterEnv4.noteOn();
        lfoAenv4.noteOn();
        env4on = true;

      } else if (env5on == false) {
        note5freq = note;
        env5.noteOn();
        filterEnv5.noteOn();
        lfoAenv5.noteOn();
        env5on = true;

      } else if (env6on == false) {
        note6freq = note;
        env6.noteOn();
        filterEnv6.noteOn();
        lfoAenv6.noteOn();
        env6on = true;

      } else if (env7on == false) {
        note7freq = note;
        env7.noteOn();
        filterEnv7.noteOn();
        lfoAenv7.noteOn();
        env7on = true;

      } else if (env9on == false) {
        note9freq = note;
        env9.noteOn();
        filterEnv9.noteOn();
        lfoAenv9.noteOn();
        env9on = true;
      }
      voices++;
      break;
    }

  } else if (synthModesw == 0) { // MONOPHONIC mode
    note1freq = note;
    env1.noteOn();
    filterEnv1.noteOn();
    lfoAenv1.noteOn();
    voices++;
  }
}

void myNoteOff(byte channel, byte note, byte velocity) {
  if (synthModesw == 1) { // POLYPHONIC mode
    switch (voices) {
    case 0 ... 8: ////<<<---- ALTAN VOCES ABAJO
      if (note1freq == note) {
        env1.noteOff();
        filterEnv1.noteOff();
        lfoAenv1.noteOff();
        env1on = false;
      } else if (note2freq == note) {
        env2.noteOff();
        filterEnv2.noteOff();
        lfoAenv2.noteOff();
        env2on = false;
      } else if (note3freq == note) {
        env3.noteOff();
        filterEnv3.noteOff();
        lfoAenv3.noteOff();
        env3on = false;
      } else if (note4freq == note) {
        env4.noteOff();
        filterEnv4.noteOff();
        lfoAenv4.noteOff();
        env4on = false;
      } else if (note5freq == note) {
        env5.noteOff();
        filterEnv5.noteOff();
        lfoAenv5.noteOff();
        env5on = false;
      } else if (note6freq == note) {
        env6.noteOff();
        filterEnv6.noteOff();
        lfoAenv6.noteOff();
        env6on = false;
      } else if (note7freq == note) {
        env7.noteOff();
        filterEnv7.noteOff();
        lfoAenv7.noteOff();
        env7on = false;
      } else if (note9freq == note) {
        env9.noteOff();
        filterEnv9.noteOff();
        lfoAenv9.noteOff();
        env9on = false;
      }
      voices--;
      break;
    }

  } else if (synthModesw == 0) { // MONOPHONIC mode
    if (note1freq == note) {
      env1.noteOff();
      filterEnv1.noteOff();
      lfoAenv1.noteOff();
      voices--;
    }
  }
}
