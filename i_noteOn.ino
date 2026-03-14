bool voiceIsOn[NUM_VOICES] = {false};
int voiceNote[NUM_VOICES] = {0};
unsigned long voiceStartedAt[NUM_VOICES] = {0};

void myNoteOn(byte channel, byte note, byte velocity) {
  if (digitalRead(1) == 1) { // POLYPHONIC mode
    int foundVoice = -1;
    unsigned long oldestTime = 0xFFFFFFFF; // Max value
    int oldestVoice = 0;

    // 1. Try to find a free voice
    for (int i = 0; i < NUM_VOICES; i++) {
      if (!voiceIsOn[i]) {
        foundVoice = i;
        break;
      }
      // Keep track of the oldest voice just in case we need to steal
      if (voiceStartedAt[i] < oldestTime) {
        oldestTime = voiceStartedAt[i];
        oldestVoice = i;
      }
    }

    // 2. If no free voice (all NUM_VOICES are playing), STEAL the oldest
    if (foundVoice == -1) {
      foundVoice = oldestVoice;
      
      // Quickly shut off previous envelopes for stolen voice
      env[foundVoice].noteOff();
      filterEnv[foundVoice].noteOff();
      lfoAenv[foundVoice].noteOff();
    }

    // 3. Play the note on the selected voice
    voiceNote[foundVoice] = note;
    voiceStartedAt[foundVoice] = millis();
    voiceIsOn[foundVoice] = true;
    
    // We update frequency of the stolen component so it changes pitch immediately
    // Frequency updating logic usually happens in c_loop_vcos.ino, but to be clean, 
    // it will pick up the new note frequencies array there.

    env[foundVoice].noteOn();
    filterEnv[foundVoice].noteOn();
    lfoAenv[foundVoice].noteOn();
    
    // Global tracking for other functions that might still use `voices` int count
    if (voices < NUM_VOICES) {
      voices++;
    }

  } else if (digitalRead(1) == 0) { // MONOPHONIC mode
    // All voices play the same note (Unison or just Voice 0)
    // To keep it simple, we just re-trigger voice 0.
    voiceNote[0] = note;
    env[0].noteOn();
    filterEnv[0].noteOn();
    lfoAenv[0].noteOn();
    voices = 1;
  }
}

void myNoteOff(byte channel, byte note, byte velocity) {
  if (digitalRead(1) == 1) { // POLYPHONIC mode
    for (int i = 0; i < NUM_VOICES; i++) {
      if (voiceIsOn[i] && voiceNote[i] == note) {
        env[i].noteOff();
        filterEnv[i].noteOff();
        lfoAenv[i].noteOff();
        voiceIsOn[i] = false;
        if (voices > 0) voices--;
        // Don't break here, in case the same note is playing on multiple voices (glitch protection)
      }
    }
  } else if (digitalRead(1) == 0) { // MONOPHONIC mode
    if (voiceNote[0] == note) {
      env[0].noteOff();
      filterEnv[0].noteOff();
      lfoAenv[0].noteOff();
      voices = 0;
    }
  }
}
