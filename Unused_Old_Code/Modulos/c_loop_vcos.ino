void loop() {
  usbMIDI.read();
  MIDI.read();

  if (voices < 0) {
    voices = 0;
  }

  Serial.println(AudioMemoryUsageMax());

  /*setCrossMod;

  setVcos;

  setVolumes;

  setWaveforms;

  setVCF;

  setLfos;

  setPWM;

  setMainEnv;

  setFX;

  setOutputGain;*/

  checkVolOctPres;
  if (mainVol != oldMainVol) { //
    setVcoAVol;
    setSubVol setVcoBVol;
    setVcoCVol;
    oldMainVol = mainVol;
  }
  if (octavesw != octavesw) {
    setOctaveValue;
    setVcoAFreq; //
    oldOctavesw = octavesw;
  }
  if (presetsw != oldPresetsw) {
    setPreset; // Funcion creada pero hay que rehacerla
    oldPresetsw = presetsw;
  }

  checkVcosVol;
  if (vcoVolA != oldVcoVolA) {
    setVcoAVol; //
    oldVcoVolA = vcoVolA;
  }
  if (vcoVolB != oldVcoVolB) {
    setVcoBVol; //
    oldVcoVolB = vcoVolB;
  }
  if (vcoVolC != oldVcoVolC) {
    setVcoCVol; //
    oldVcoVolC = vcoVolC;
  }

  checkShapes;
  if (shapeAsw != oldShapeAsw) {
    setShapeA; //
    oldShapeAsw != shapeAsw;
  }
  if (shapeBsw != oldShapeBsw) {
    setShapeB; //
    oldShapeBsw != shapeBsw;
  }
  if (shapeCsw != oldShapeCsw) {
    setShapeC; //
    oldShapeCsw != shapeCsw;
  }

  checkDetAAdj;
  if (detuneBsw != oldDetuneBsw) {
    setDetuneBValue;
    setVcoBFreq; //
    detuneBsw = oldDetuneBsw;
  }
  if (detuneCsw != oldDetuneCsw) {
    setDetuneCValue;
    setVcoCFreq; //
    detuneCsw = oldDetuneCsw;
  }
  if (shapeAAdj != oldShapeAAdj) {
    setShapeAAdj; //
    shapeAAdj = oldShapeAAdj;
  }

  checkBAdjFineD;
  if (shapeBAdj != oldShapeBAdj) {
    setShapeBAdj; //
    oldShapeBAdj = shapeBAdj;
  }
  if (fineDetuneB != oldFineDetuneB) {
    setVcoBFreq; //
    FineDetuneB = oldFineDetuneB;
  }
  if (fineDetuneC != oldFineDetuneC) {
    setVcoCFreq; //
    FineDetuneC = oldFineDetuneC;
  }

  checkModSubVCFCut;
  if (crossMod != oldCrossMod) {
    setCrossMod; //
    oldCrossMod = crossMod;
  }
  if (subVol != oldSubVol) {
    setSubVol; //
    oldSubVol = subVol;
  }
  if (VCFCut != oldVCFCut) {
    setVCFCut; //
    oldVCFCut = VCFCut;
  }

  checkVCFResAmtAtt;
  if (VCFRes != oldVCFRes) {
    setVCFRes; //
    oldVCFRes = VCFRes;
  }
  if (VCFAmt != oldVCFAmt) {
    setVCFAmp; //
    oldVCFAmt = VCFAmt;
  }
  if (VCFAtt != oldVCFAtt) {
    setVCFAtt; //
    oldVCFAtt = VCFAtt;
  }

  checkVCFDecSustRel;
  if (VCFDec != oldVCFDec) {
    setVCFDec; //
    oldVCFDec = VCFDec;
  }
  if (VCFSust != oldVCFSust) {
    setVCFSust; //
    oldVCFSust = VCFSust;
  }
  if (VCFRel != oldVCFRel) {
    setVCFRel; //
    oldVCFRel = VCFRel;
  }

  checkEnvAttDecSust;
  if (envAtt != oldEnvAtt) {
    setEnvAtt; //
    oldEnvAtt = envAtt;
  }
  if (envDec != oldEnvDec) {
    setEnvDec; //
    oldEnvDec = envDec;
  }
  if (envSust != oldEnvSust) {
    setEnvSust; //
    oldEnvSust = envSust;
  }

  checkEnvRelLfoFVCFMode;
  if (envRel != oldEnvRel) {
    setEnvRel; //
    oldEnvRel = envRel;
  }
  if (lfoFreq != oldLfoFreq) {
    setLfoFreq; //
    oldLfoFreq = lfoFreq;
  }
  if (VCFModesw != oldVCFModesw) {
    setVCFMode; //
    oldVCFModesw = VCFModesw;
  }

  checkLfoDestAmpDel;
  if (lfoDestsw != oldLfoDestsw) {
    setLfoDest; //
    oldLfoDestsw = lfoDestsw;
  }
  if (lfoAmp != oldLfoAmp) {
    setLfoAmp; //
    oldLfoAmp = lfoAmp;
  }
  if (lfoDel != oldLfoDel) {
    setLfoDel; //
    oldLfoDel = lfoDel;
  }

  checkLfoAttDecSust;
  if (lfoAtt != oldLfoAtt) {
    setLfoAtt; //
    oldLfoAtt = lfoAtt;
  }
  if (lfoDec != oldLfoDec) {
    setLfoDec; //
    oldLfoDec = lfoDec;
  }
  if (lfoSust != oldLfoSust) {
    setLfoSust; //
    oldLfoSust = lfoSust;
  }

  checkLfoRelShapPWMFreq;
  if (lfoRel != oldLfoRel) {
    setLfoRel; //
    oldLfoRel = lfoRel;
  }
  if (lfoShapesw != oldLfoShapesw) {
    setLfoShape; //
    oldLfoShapesw = lfoShapesw;
  }
  if (PWMFreq != oldPWMFreq) {
    setPWMFreq;
    oldPWMFreq = lfoPWMFreq;
  }

  checkPWMAmpRevMixSize;
  if (PWMAmp != oldPWMAmp) {
    setPWMAmp;
    oldPWMAmp = lfoPWMAmp;
  }
  if (revMix != oldRevMix) {
    setOutputGain; /*
     fxL.gain(1, revMixpot);
     fxR.gain(1, revMixpot);*/
    oldRevMix = revMix;
  }
  if (revSize != oldRevSize) {
    reverb.roomsize(revSize);
    oldRevSize = revSize;
  }

  checkRevHumDlyAmtTime;
  if (revHum != oldRevHum) {
    reverb.damping(revHum);
    oldRevHum = revHum;
  }
  if (dlyAmt != oldDlyAmt) {
    dlyMixL.gain(1, dlyAmt /** 0.9*/);
    dlyMixR.gain(1, dlyAmt /** 0.9*/);
    oldDlyAmt = dlyAmt;
  }
  if (dlyTime != oldDlyTime) {
    dlyL.delay(0, dlyTimeL);
    dlyR.delay(0, dlyTimeR);
    oldDlyTime = dlyTime;
  }

  checkSynthMode;
  /*if (synthModesw != oldSynthModesw) {
    setSynthMode;
    oldSynthModesw = synthModesw;*/
}
}
