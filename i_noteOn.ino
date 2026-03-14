bool voiceIsOn[NUM_VOICES] = {false};
int voiceNote[NUM_VOICES] = {0};
unsigned long voiceStartedAt[NUM_VOICES] = {0};

byte monoNoteStack[16];
int monoNoteCount = 0;

void myNoteOn(byte channel, byte note, byte velocity) {
  if (digitalRead(1) == 1) { // POLYPHONIC mode
    int foundVoice = -1;
    unsigned long oldestTime = 0xFFFFFFFF; // Max value
    int oldestVoice = 0;

    // 1. Try to find a completely free voice (key released AND envelope finished)
    for (int i = 0; i < NUM_VOICES; i++) {
      if (!voiceIsOn[i] && !voices[i].env.isActive()) {
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
      voices[foundVoice].env.noteOff();
      voices[foundVoice].filterEnv.noteOff();
      voices[foundVoice].lfoAenv.noteOff();
    }

    // 3. Play the note on the selected voice
    voiceNote[foundVoice] = note;
    voiceStartedAt[foundVoice] = millis();
    voiceIsOn[foundVoice] = true;
    
    // We update frequency of the stolen component so it changes pitch immediately
    // Frequency updating logic usually happens in c_loop_vcos.ino, but to be clean, 
    // it will pick up the new note frequencies array there.

    voices[foundVoice].env.noteOn();
    voices[foundVoice].filterEnv.noteOn();
    voices[foundVoice].lfoAenv.noteOn();
    
    parameterChanged = true;
    
    // Global tracking for other functions that might still use `voices` int count
    if (activeVoices < NUM_VOICES) {
      activeVoices++;
    }

  } else if (digitalRead(1) == 0) { // MONOPHONIC mode
    // Note Priority (Stack) and Legato
    if (monoNoteCount < 16) {
      monoNoteStack[monoNoteCount] = note;
      monoNoteCount++;
    } else {
      for (int i = 0; i < 15; i++) {
        monoNoteStack[i] = monoNoteStack[i+1];
      }
      monoNoteStack[15] = note;
    }

    voiceNote[0] = monoNoteStack[monoNoteCount - 1];

    if (activeVoices == 0) {
      voices[0].env.noteOn();
      voices[0].filterEnv.noteOn();
      voices[0].lfoAenv.noteOn();
      activeVoices = 1;
    }
    parameterChanged = true;
  }
}

void myNoteOff(byte channel, byte note, byte velocity) {
  if (digitalRead(1) == 1) { // POLYPHONIC mode
    for (int i = 0; i < NUM_VOICES; i++) {
      if (voiceIsOn[i] && voiceNote[i] == note) {
        voices[i].env.noteOff();
        voices[i].filterEnv.noteOff();
        voices[i].lfoAenv.noteOff();
        voiceIsOn[i] = false;
        if (activeVoices > 0) activeVoices--;
        // Don't break here, in case the same note is playing on multiple voices (glitch protection)
      }
    }
  } else if (digitalRead(1) == 0) { // MONOPHONIC mode
    int removeIdx = -1;
    for (int i = 0; i < monoNoteCount; i++) {
      if (monoNoteStack[i] == note) {
        removeIdx = i;
        break;
      }
    }
    
    if (removeIdx != -1) {
      for (int i = removeIdx; i < monoNoteCount - 1; i++) {
        monoNoteStack[i] = monoNoteStack[i+1];
      }
      monoNoteCount--;
    }

    if (monoNoteCount > 0) {
      // Revert to the previous note in the stack (Note Priority)
      voiceNote[0] = monoNoteStack[monoNoteCount - 1];
      parameterChanged = true;
    } else {
      // No notes left, release envelopes
      voices[0].env.noteOff();
      voices[0].filterEnv.noteOff();
      voices[0].lfoAenv.noteOff();
      activeVoices = 0;
    }
  }
}
