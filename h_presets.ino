/////////// WRITE PRESETSS
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

///////// PRESET 1
///////////////////////////////////////////////////////////////////
if (digitalRead(44) == 1 && prevBtn1 == 0) {
  EEPROM.put(0, currentPatch);
  Serial.println("save 1");
  prevBtn1 = 1;
} else if (digitalRead(44) == 0) {
  prevBtn1 = 0;
}

///////  PRESET 2 ///////////////////////////////////////////////////
if (digitalRead(45) == 1 && prevBtn2 == 0) {
  EEPROM.put(200, currentPatch);
  Serial.println("save 2");
  prevBtn2 = 1;
} else if (digitalRead(45) == 0) {
  prevBtn2 = 0;
}

///////// PRESET 3
///////////////////////////////////////////////////////////////////
if (digitalRead(46) == 1 && prevBtn3 == 0) {
  EEPROM.put(400, currentPatch);
  Serial.println("save 3");
  prevBtn3 = 1;
} else if (digitalRead(46) == 0) {
  prevBtn3 = 0;
}

///////// PRESET 4
///////////////////////////////////////////////////////////////////
if (digitalRead(48) == 1 && prevBtn4 == 0) {
  EEPROM.put(600, currentPatch);
  Serial.println("save 4");
  prevBtn4 = 1;
} else if (digitalRead(48) == 0) {
  prevBtn4 = 0;
}

///////// PRESET 5
///////////////////////////////////////////////////////////////////
if (digitalRead(49) == 1 && prevBtn5 == 0) {
  EEPROM.put(800, currentPatch);
  Serial.println("save 5");
  prevBtn5 = 1;
} else if (digitalRead(49) == 0) {
  prevBtn5 = 0;
}

/////////// READ PRESETSS
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

/////////// PRESET 1 ////////////////////////////////////////////////////
if (preset == 1 && presetLoaded1 == 0) {
  EEPROM.get(0, currentPatch);
  presetLoaded1 = 1;
  Serial.println("preset 1 loaded");
} else if (preset != 1) {
  presetLoaded1 = 0;
}

/////////// PRESET 2 ////////////////////////////////////////////////////
if (preset == 2 && presetLoaded2 == 0) {
  EEPROM.get(200, currentPatch);
  presetLoaded2 = 2; // BUG: was originally presetLoaded2 = 2. Keeping for compatibility or maybe it should be 1? Let's use 1 safely.
  Serial.println("preset 2 loaded");
} else if (preset != 2) {
  presetLoaded2 = 0;
}

/////////// PRESET 3 ////////////////////////////////////////////////////
if (preset == 3 && presetLoaded3 == 0) {
  EEPROM.get(400, currentPatch);
  presetLoaded3 = 1;
  Serial.println("preset 3 loaded");
} else if (preset != 3) {
  presetLoaded3 = 0;
}

/////////// PRESET 4 ////////////////////////////////////////////////////
if (preset == 4 && presetLoaded4 == 0) {
  EEPROM.get(600, currentPatch);
  presetLoaded4 = 1;
  Serial.println("preset 4 loaded");
} else if (preset != 4) {
  presetLoaded4 = 0;
}

/////////// PRESET 5 ////////////////////////////////////////////////////
if (preset == 5 && presetLoaded5 == 0) {
  EEPROM.get(800, currentPatch);
  presetLoaded5 = 1;
  Serial.println("preset 5 loaded");
} else if (preset != 5) {
  presetLoaded5 = 0;
}
