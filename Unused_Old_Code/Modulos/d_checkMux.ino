void checkVolOctPres() {
  digitalWrite(28, 0); // A
  digitalWrite(29, 0); // B
  digitalWrite(30, 0); // C
  digitalWrite(31, 0); // D
  mainVol = (int)analogRead(muxAPots) / 1024;
  octavesw = (int)analogRead(muxBPots) / 175; //* ( 6 / 1024 );
  presetsw = (int)analogRead(muxCPots) / 205; //* ( 5 / 1024);
  delay(wait);
}

void checkVcosVol() {
  digitalWrite(28, 1);
  digitalWrite(29, 0);
  digitalWrite(30, 0);
  digitalWrite(31, 0); // D
  vcoAVol = (int)analogRead(muxAPots) / 1024;
  vcoBVol = (int)analogRead(muxBPots) / 1024;
  vcoCVol = (int)analogRead(muxCPots) / 1024;
  delay(wait);
}

void checkShapes() {
  digitalWrite(28, 0);
  digitalWrite(29, 1);
  digitalWrite(30, 0);
  digitalWrite(31, 0);                        // D
  shapeAsw = (int)analogRead(muxAPots) / 205; //* ( 5 / 1024 );
  shapeBsw = (int)analogRead(muxBPots) / 205; //* ( 5 / 1024 );
  shapeCsw = (int)analogRead(muxCPots) / 37;  //* ( 28 / 1024 );
  delay(wait);
}

void checkDetAAdj() {
  digitalWrite(28, 1);
  digitalWrite(29, 1);
  digitalWrite(30, 0);
  digitalWrite(31, 0);                         // D
  detuneBsw = (int)analogRead(muxAPots) / 205; //* ( 5 / 1024 );
  detuneCsw = (int)analogRead(muxBPots) / 205; //* ( 5 / 1024 );
  shapeAAdj = (int)analogRead(muxCPots) / 1024;
  delay(wait);
}

void checkBAdjFineD() {
  digitalWrite(28, 0);
  digitalWrite(29, 0);
  digitalWrite(30, 1);
  digitalWrite(31, 0);                          // D
  shapeBAdj = (int)analogRead(muxAPots) / 1024; // / 1024;
  (int)fineDetuneBpot = (int)analogRead(muxBPots);
  if (fineDetuneBpot < 512) {
    fineDetuneB = fineDetuneBpot / 1023) + 0.5;
  } else {
    fineDetuneB = fineDetuneBpot / 510);
  }
  (int)fineDetuneCpot = (int)analogRead(muxCPots);
  if (fineDetuneCpot < 512) {
    fineDetuneC = (fineDetuneCpot / 1023) + 0.5;
  } else {
    fineDetuneC = (fineDetuneCpot / 510);
  }
  delay(wait);
}

void checkModSubVCFCut() {
  digitalWrite(28, 1);
  digitalWrite(29, 0);
  digitalWrite(30, 1);
  digitalWrite(31, 0); // D
  crossMod = (int)analogRead(muxAPots) / 1024;
  subVol = (int)analogRead(muxBPots) / 1024;
  VCFCut = 15 * (int)analogRead(muxCPots); //   15000/ 1024 APROX 15
  delay(wait);
}

void checkVCFResAmtAtt() {
  digitalWrite(28, 0);
  digitalWrite(29, 1);
  digitalWrite(30, 1);
  digitalWrite(31, 0); // D
  VCFRes = 4.5 * (int)analogRead(muxAPots) / 1024 + 1.1;
  VCFAmt = (int)analogRead(muxBPots) / 1024;
  VCFAtt = 2 * (int)analogRead(muxCPots); /// 1024
  delay(wait);
}

void checkVCFDecSustRel() {
  digitalWrite(28, 1);
  digitalWrite(29, 1);
  digitalWrite(30, 1);
  digitalWrite(31, 0); // D
  VCFDec = (int)analogRead(muxAPots) / 1024;
  VCFSust = (int)analogRead(muxBPots) / 1024;
  VCFRel = 5 * (int)analogRead(muxCPots);
  delay(wait);
}

void checkEnvAttDecSust() {
  digitalWrite(28, 0); // A
  digitalWrite(29, 0); // B
  digitalWrite(30, 0); // C
  digitalWrite(31, 1); // D
  envAtt =
      2 * (int)analogRead(muxAPots); // * ( 2 / 1024);    pasando de fModepot
  envDec = (int)analogRead(muxBPots) / 1024;
  envSust = (int)analogRead(muxCPots) / 1024;
  delay(wait);
}

void checkEnvRelLfoFVCFMode() {
  digitalWrite(28, 1);
  digitalWrite(29, 0);
  digitalWrite(30, 0);
  digitalWrite(31, 1); // D
  envRel = 5 * (int)analogRead(muxAPots);
  lfoFreq = 20 * (int)analogRead(muxBPots) / 1024 + 0.1;
  VCFModesw = (int)analogRead(muxCPots) / 512;
  delay(wait);
}

void checkLfoDestAmpDel() {
  digitalWrite(28, 0);
  digitalWrite(29, 1);
  digitalWrite(30, 0);
  digitalWrite(31, 1);                         // D
  lfoDestsw = (int)analogRead(muxAPots) / 342; //* ( 3 / 1024);
  lfoAmp = (int)analogRead(muxBPots) / 1024;   /// 1024;
  lfoDel = 2 * (int)analogRead(muxCPots);      // 2 *
  delay(wait);
}

void checkLfoAttDecSust() {
  digitalWrite(28, 1);
  digitalWrite(29, 1);
  digitalWrite(30, 0);
  digitalWrite(31, 1); // D
  lfoAtt = 2 * (int)analogRead(muxAPots);
  lfoDec = (int)analogRead(muxBPots) / 1024;
  lfoSust = (int)analogRead(muxCPots) / 1024;
  delay(wait);
}

void checkLfoRelShapPWMFreq() {
  digitalWrite(28, 0);
  digitalWrite(29, 0);
  digitalWrite(30, 1);
  digitalWrite(31, 1); // D
  lfoRel = 3 * (int)analogRead(muxAPots);
  lfoShapesw = (int)analogRead(muxBPots) / 175; //* ( 6 / 1024 );
  PWMFreq = 20 * ((int)analogRead(muxCPots) / 1024 + 0.1);
  delay(wait);
}

void checkPWMAmpRevMixSize() {
  digitalWrite(28, 1);
  digitalWrite(29, 0);
  digitalWrite(30, 1);
  digitalWrite(31, 1); // D
  PWMAmp = (int)analogRead(muxAPots) / 1024;
  revMix = (int)analogRead(muxBPots) / 1700; // / 1024 / 1.5;
  revSize = (int)analogRead(muxCPots) / 1024 - 0.01;
  delay(wait);
}

void checkRevHumDlyAmtTime() {
  digitalWrite(28, 0);
  digitalWrite(29, 1);
  digitalWrite(30, 1);
  digitalWrite(31, 1); // D
  revHum = (int)analogRead(muxAPots) / 1024;
  dlyAmt = (int)analogRead(muxBPots);
  dlyTime = 2 * (int)analogRead(muxCPots);
  delay(wait);
}

void checkSynthMode() {
  digitalWrite(28, 1);
  digitalWrite(29, 1);
  digitalWrite(30, 1);
  digitalWrite(31, 1);                           // D
  synthModesw = (int)analogRead(muxAPots) / 512; //* ( 2 / 1024 );
  delay(wait);
}