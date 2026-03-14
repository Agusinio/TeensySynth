if (millis() - prevTimer > timer) {

  mainVol = (float)analogRead(A11) / 1024;
  preset = analogRead(A24) / 190;

  bend = 1 + ((float)analogRead(A0) / 1023 / 4.3) - 0.12;
  if (abs(bend - oldBend) > 0.005) {
    parameterChanged = true;
    oldBend = bend;
  }

  // main currentPatch.octave
  if (digitalRead(6) == 1) {
    currentPatch.octave = 0.5;
  } else if (digitalRead(6) == 0 && digitalRead(7) == 0) {
    currentPatch.octave = 1;
  } else if (digitalRead(7) == 1) {
    currentPatch.octave = 2;
  }

  ///////////////  EDIT MODE EDIT
  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (preset == 0) {

    if (digitalRead(8) == 1) {
      currentPatch.octaveB = 0.5;
    } else if (digitalRead(8) == 0 && digitalRead(12) == 0) {
      currentPatch.octaveB = 1;
    } else if (digitalRead(12) == 1) {
      currentPatch.octaveB = 2;
    }

    if (digitalRead(10) == 1) {
      currentPatch.octaveC = 0.5;
    } else if (digitalRead(10) == 0 && digitalRead(11) == 0) {
      currentPatch.octaveC = 1;
    } else if (digitalRead(11) == 1) {
      currentPatch.octaveC = 2;
    }

    if (digitalRead(2) == 1) {
      currentPatch.shapeA = 0;
    } else if (digitalRead(2) == 0 && digitalRead(3) == 0) {
      currentPatch.shapeA = 1;
    } else if (digitalRead(3) == 1) {
      currentPatch.shapeA = 2;
    }

    if (digitalRead(4) == 1) {
      currentPatch.shapeB = 0;
    } else if (digitalRead(4) == 0 && digitalRead(5) == 0) {
      currentPatch.shapeB = 1;
    } else if (digitalRead(5) == 1) {
      currentPatch.shapeB = 2;
    }

    currentPatch.shapeC = analogRead(A4);

    if (analogRead(A2) < 512) {
      currentPatch.tuneB = ((float)analogRead(A2) / 1023) + 0.5;
    } else {
      currentPatch.tuneB = ((float)analogRead(A2) / 510);
    }

    if (analogRead(A3) < 512) {
      currentPatch.tuneC = ((float)analogRead(A3) / 1023) + 0.5;
    } else {
      currentPatch.tuneC = ((float)analogRead(A3) / 510);
    }

    currentPatch.crossMod = (float)analogRead(A1) / 512;

    currentPatch.vcoAvol = (float)analogRead(A5) / 1023;
    currentPatch.vcoBvol = (float)analogRead(A6) / 1023;
    currentPatch.vcoCvol = (float)analogRead(A7) / 1023;
    currentPatch.Subvol = (float)analogRead(A21) / 1023;

    cutpot = analogRead(A13);
    if (smoothedCutpot < 0) {
      smoothedCutpot = cutpot;
    }
    smoothedCutpot += 0.05 * (cutpot - smoothedCutpot);
    currentPatch.cut = 15.0 * pow(1000.0, smoothedCutpot / 1023.0);

    currentPatch.res = 4.5 * (float)analogRead(A12) / 1023 + 1.1;
    currentPatch.filtAtt = (3000 * (float)mux0 / 1023);
    currentPatch.filtDec = (3000 * (float)mux1 / 1023);
    currentPatch.filtAmt = (float)mux2 / 512 - 1;
    if (digitalRead(13) == 1) {
      currentPatch.filterMode = 1;
    } else if (digitalRead(13) == 0) {
      currentPatch.filterMode = 0;
    }

    currentPatch.envAtt = 3000 * (float)analogRead(A25) / 1023;
    currentPatch.envDec = 5000 * (float)analogRead(A26) / 1023;
    currentPatch.envRel = 5000 * (float)analogRead(A26) / 1023;
    currentPatch.envSus = (float)analogRead(A10) / 100;

    if (currentPatch.lfoAdest == 0 && currentPatch.lfoAshape != 2) {
      currentPatch.lfoAamp = (float)mux3 / 1024 / 10;
    } else {
      currentPatch.lfoAamp = (float)mux3 / 1024 / 3;
    }
    currentPatch.lfoAfreq = 20 * (float)mux4 / 1024 + 0.1;
    currentPatch.lfoAdel = 2000 * (float)mux5 / 1024;
    currentPatch.lfoAatt = 3000 * (float)mux5 / 1024;
    currentPatch.lfoAdec = 4000 * (float)mux6 / 1024;
    currentPatch.lfoArel = 4000 * (float)mux6 / 1024;
    currentPatch.lfoAsus = (float)mux7 / 1024;

    if (digitalRead(24) == 1) { // lfo - pitch
      currentPatch.lfoAdest = 0;
    } else if (digitalRead(24) == 0 && digitalRead(25) == 0) { // lfo - filter
      currentPatch.lfoAdest = 1;
    } else if (digitalRead(25) == 1) { // lfo - amp
      currentPatch.lfoAdest = 2;
    }

    if (digitalRead(26) == 1) {
      currentPatch.lfoAshape = 0;
    } else if (digitalRead(26) == 0 && digitalRead(27) == 0) {
      currentPatch.lfoAshape = 1;
    } else if (digitalRead(27) == 1) {
      currentPatch.lfoAshape = 2;
    }

    currentPatch.lfoBamp = (float)analogRead(A14) / 1023;
    currentPatch.lfoBfreq = 5 * (float)analogRead(A22) / 1023 + 0.1;

    currentPatch.dlyAmt = (float)analogRead(A16) / 1100 - 0.1;
    currentPatch.dlyTimeL = analogRead(A17) / 2.5;
    currentPatch.dlyTimeR = analogRead(A17) / 1.25;
    currentPatch.revMix = ((float)analogRead(A19) / 1024 / 1.5);
    currentPatch.revSize = ((float)analogRead(A18) / 1024 - 0.01);

    if (currentPatch.dlyAmt < 0) {
      currentPatch.dlyAmt = 0;
    }

  } else {

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // PRESET MODE ///////// PRESET MODE //////// PRESET MODE ////////////
    // PRESET MODE /////// PRESET MODE //// PRESET MODE ///////// PRESET MODE
    // //////// PRESET MODE //////////// PRESET MODE /////// PRESET MODE ////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////  OCTAVES OCTAVES
    ////////////////////////////////////////////////////////////////7////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    // currentPatch.octave vco B
    if (digitalRead(8) == 1) {
      octBsw = 0;
    } else if (digitalRead(8) == 0 && digitalRead(12) == 0) {
      octBsw = 1;
    } else if (digitalRead(12) == 1) {
      octBsw = 2;
    }
    if (oldOctBsw < octBsw || oldOctBsw > octBsw) {
      if (digitalRead(8) == 1) {
        currentPatch.octaveB = 0.5;
      } else if (digitalRead(8) == 0 && digitalRead(12) == 0) {
        currentPatch.octaveB = 1;
      } else if (digitalRead(12) == 1) {
        currentPatch.octaveB = 2;
      }
      oldOctBsw = octBsw;
      parameterChanged = true;
      Serial.println("currentPatch.octave B switch");
    }

    // currentPatch.octave vco C
    if (digitalRead(10) == 1) {
      octCsw = 0;
    } else if (digitalRead(10) == 0 && digitalRead(11) == 0) {
      octCsw = 1;
    } else if (digitalRead(11) == 1) {
      octCsw = 2;
    }
    if (oldOctCsw < octCsw || oldOctCsw > octCsw) {
      if (digitalRead(10) == 1) {
        currentPatch.octaveC = 0.5;
      } else if (digitalRead(10) == 0 && digitalRead(11) == 0) {
        currentPatch.octaveC = 1;
      } else if (digitalRead(11) == 1) {
        currentPatch.octaveC = 2;
      }
      oldOctCsw = octCsw;
      parameterChanged = true;
      Serial.println("currentPatch.octave C switch");
    }

    //////////// SHAPES SHAPES
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Shape A
    if (digitalRead(2) == 1) {
      shapeAsw = 0;
    } else if (digitalRead(2) == 0 && digitalRead(3) == 0) {
      shapeAsw = 1;
    } else if (digitalRead(3) == 1) {
      shapeAsw = 2;
    }
    if (oldShapeAsw < shapeAsw || oldShapeAsw > shapeAsw) {
      if (digitalRead(2) == 1) {
        currentPatch.shapeA = 0;
      } else if (digitalRead(2) == 0 && digitalRead(3) == 0) {
        currentPatch.shapeA = 1;
      } else if (digitalRead(3) == 1) {
        currentPatch.shapeA = 2;
      }
      oldShapeAsw = shapeAsw;
      parameterChanged = true;
      Serial.println("shape A switch");
    }

    // Shape B
    if (digitalRead(4) == 1) {
      shapeBsw = 0;
    } else if (digitalRead(4) == 0 && digitalRead(5) == 0) {
      shapeBsw = 1;
    } else if (digitalRead(5) == 1) {
      shapeBsw = 2;
    }
    if (oldShapeBsw < shapeBsw || oldShapeBsw > shapeBsw) {
      if (digitalRead(4) == 1) {
        currentPatch.shapeB = 0;
      } else if (digitalRead(4) == 0 && digitalRead(5) == 0) {
        currentPatch.shapeB = 1;
      } else if (digitalRead(5) == 1) {
        currentPatch.shapeB = 2;
      }
      oldShapeBsw = shapeBsw;
      parameterChanged = true;
      Serial.println("shape B switch");
    }

    // Vco C shape
    shapeCpot = analogRead(A4);
    if (oldShapeCpot + tresh2 < shapeCpot ||
        oldShapeCpot - tresh2 > shapeCpot) {
      currentPatch.shapeC = analogRead(A4);
      oldShapeCpot = shapeCpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("shape C turn");
    }

    /////////// TUNINGS TUNINGS
    /////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    // currentPatch.tuneB
    tuneBpot = analogRead(A2);
    if (oldTuneBpot + tresh < tuneBpot || oldTuneBpot - tresh > tuneBpot) {
      if (analogRead(A2) < 512) {
        currentPatch.tuneB = ((float)analogRead(A2) / 1023) + 0.5;
      } else {
        currentPatch.tuneB = ((float)analogRead(A2) / 510);
      }
      oldTuneBpot = tuneBpot + tresh / 2;
      parameterChanged = true;
      Serial.println("currentPatch.tuneB turn");
    }

    // currentPatch.tuneC
    tuneCpot = analogRead(A3);
    if (oldTuneCpot + tresh < tuneCpot || oldTuneCpot - tresh > tuneCpot) {
      if (analogRead(A3) < 512) {
        currentPatch.tuneC = ((float)analogRead(A3) / 1023) + 0.5;
      } else {
        currentPatch.tuneC = ((float)analogRead(A3) / 510);
      }
      oldTuneCpot = tuneCpot + tresh / 2;
      parameterChanged = true;
      Serial.println("currentPatch.tuneC turn");
    }

    // Cross mod
    crossModpot = analogRead(A1);
    if (oldCrossModpot + tresh < crossModpot ||
        oldCrossModpot - tresh > crossModpot) {
      currentPatch.crossMod = (float)analogRead(A1) / 512;
      oldCrossModpot = crossModpot + tresh / 2;
      parameterChanged = true;
      Serial.println("crossmod turn");
    }

    ///////////// VOLUMES VOLUMES
    ////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    volApot = analogRead(A5);
    if (oldVolApot + tresh2 < volApot || oldVolApot - tresh2 > volApot) {
      currentPatch.vcoAvol = (float)analogRead(A5) / 1023;
      oldVolApot = volApot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("volA turn");
    }

    volBpot = analogRead(A6);
    if (oldVolBpot + tresh2 < volBpot || oldVolBpot - tresh2 > volBpot) {
      currentPatch.vcoBvol = (float)analogRead(A6) / 1023;
      oldVolBpot = volBpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("volB turn");
    }

    volCpot = analogRead(A7);
    if (oldVolCpot + tresh2 < volCpot || oldVolCpot - tresh2 > volCpot) {
      currentPatch.vcoCvol = (float)analogRead(A7) / 1023;
      oldVolCpot = volCpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("volC turn");
    }

    volSubpot = analogRead(A21);
    if (oldVolSubpot + tresh2 < volSubpot ||
        oldVolSubpot - tresh2 > volSubpot) {
      currentPatch.Subvol = (float)analogRead(A21) / 1023;
      oldVolSubpot = volSubpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("vol sub turn");
    }

    //////////// FILTER FILTER
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Filter
    cutpot = analogRead(A13);
    
    if (smoothedCutpot < 0) {
      smoothedCutpot = cutpot;
      targetCutpot = cutpot;
    }

    if (oldCutpot + tresh < cutpot || oldCutpot - tresh > cutpot) {
      targetCutpot = cutpot;
      oldCutpot = cutpot + tresh / 2;
      Serial.println("currentPatch.cut turn");
    }

    if (abs(smoothedCutpot - targetCutpot) > 0.5) {
      smoothedCutpot += 0.05 * (targetCutpot - smoothedCutpot);
      currentPatch.cut = 15.0 * pow(1000.0, smoothedCutpot / 1023.0);
      parameterChanged = true;
    } else if (smoothedCutpot != targetCutpot) {
      smoothedCutpot = targetCutpot;
      currentPatch.cut = 15.0 * pow(1000.0, smoothedCutpot / 1023.0);
      parameterChanged = true;
    }

    respot = analogRead(A12);
    if (oldRespot + tresh2 < respot || oldRespot - tresh2 > respot) {
      currentPatch.res = 4.5 * (float)analogRead(A12) / 1023 + 1.1;
      oldRespot = respot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("currentPatch.res turn");
    }

    // Filter Env

    fAttpot = mux0;
    if (oldFAttpot + tresh2 < fAttpot || oldFAttpot - tresh2 > fAttpot) {
      currentPatch.filtAtt = (3000 * (float)mux0 / 1023);
      oldFAttpot = fAttpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("filter attack turn");
    }

    fDecpot = mux1;
    if (oldFDecpot + tresh2 < fDecpot || oldFDecpot - tresh2 > fDecpot) {
      currentPatch.filtDec = (3000 * (float)mux1 / 1023);
      oldFDecpot = fDecpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("filter decay turn");
    }

    fAmtpot = mux2;
    if (oldFAmtpot + tresh2 < fAmtpot || oldFAmtpot - tresh2 > fAmtpot) {
      currentPatch.filtAmt = (float)mux2 / 512 - 1;
      oldFAmtpot = fAmtpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("filter Amt turn");
    }

    // FilterMode
    if (digitalRead(13) == 1) {
      filtModesw = 1;
    } else if (digitalRead(13) == 0) {
      filtModesw = 0;
    }
    if (oldFiltModesw < filtModesw || oldFiltModesw > filtModesw) {
      if (digitalRead(13) == 1) {
        currentPatch.filterMode = 1;
      } else if (digitalRead(13) == 0) {
        currentPatch.filterMode = 0;
      }
      oldFiltModesw = filtModesw;
      parameterChanged = true;
      Serial.println("filter mode switch");
    }

    /////////////// MAIN ENVELOPE ENVELOPE
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    attpot = analogRead(A25);
    if (oldAttpot + tresh2 < attpot || oldAttpot - tresh2 > attpot) {
      currentPatch.envAtt = 3000 * (float)analogRead(A25) / 1023;
      oldAttpot = attpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Attack turn");
    }

    decpot = analogRead(A26);
    if (oldDecpot + tresh2 < decpot || oldDecpot - tresh2 > decpot) {
      currentPatch.envDec = 5000 * (float)analogRead(A26) / 1023;
      currentPatch.envRel = 5000 * (float)analogRead(A26) / 1023;
      oldDecpot = decpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Decay turn");
    }

    suspot = analogRead(A10);
    if (oldSuspot + tresh2 < suspot || oldSuspot - tresh2 > suspot) {
      currentPatch.envSus = (float)analogRead(A10) / 100;
      oldSuspot = suspot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Sustain turn");
    }

    ////////////// LFO A   LFO A
    ////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    lfoAmppot = mux3;
    if (oldLfoAmppot + tresh2 < lfoAmppot ||
        oldLfoAmppot - tresh2 > lfoAmppot) {
      if (currentPatch.lfoAdest == 0 && currentPatch.lfoAshape != 2) {
        currentPatch.lfoAamp = (float)mux3 / 1024 / 10;
      } else {
        currentPatch.lfoAamp = (float)mux3 / 1024 / 3;
      }
      oldLfoAmppot = lfoAmppot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Lfo A amp turn");
    }

    lfoFreqpot = mux4;
    if (oldLfoFreqpot + tresh2 < lfoFreqpot ||
        oldLfoFreqpot - tresh2 > lfoFreqpot) {
      currentPatch.lfoAfreq = 20 * (float)mux4 / 1024 + 0.1;
      oldLfoFreqpot = lfoFreqpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Lfo A Freq turn");
    }

    lfoAttpot = mux5;
    if (oldLfoAttpot + tresh2 < lfoAttpot ||
        oldLfoAttpot - tresh2 > lfoAttpot) {
      currentPatch.lfoAdel = 2000 * (float)mux5 / 1024;
      currentPatch.lfoAatt = 3000 * (float)mux5 / 1024;
      oldLfoAttpot = lfoAttpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Lfo A Att turn");
    }

    lfoDecpot = mux6;
    if (oldLfoDecpot + tresh2 < lfoDecpot ||
        oldLfoDecpot - tresh2 > lfoDecpot) {
      currentPatch.lfoAdec = 4000 * (float)mux6 / 1024;
      currentPatch.lfoArel = 4000 * (float)mux6 / 1024;
      oldLfoDecpot = lfoDecpot + (tresh2 / 2);
      parameterChanged = true;
      Serial.println("Lfo A Dec turn");
    }

    lfoSuspot = mux7;
    if (oldLfoSuspot + tresh2 * 2 < lfoSuspot ||
        oldLfoSuspot - tresh2 * 2 > lfoSuspot) {
      currentPatch.lfoAsus = (float)mux7 / 1024;
      oldLfoSuspot = lfoSuspot + ((tresh2 * 2) / 2);
      parameterChanged = true;
      Serial.println("Lfo A Sus turn");
    }

    // lfoA destination
    if (digitalRead(24) == 1) { // lfo - pitch
      lfoDestsw = 0;
    } else if (digitalRead(24) == 0 && digitalRead(25) == 0) { // lfo - filter
      lfoDestsw = 1;
    } else if (digitalRead(25) == 1) { // lfo - amp
      lfoDestsw = 2;
    }
    if (oldLfoDestsw < lfoDestsw || oldLfoDestsw > lfoDestsw) {
      if (digitalRead(24) == 1) { // lfo - pitch
        currentPatch.lfoAdest = 0;
      } else if (digitalRead(24) == 0 && digitalRead(25) == 0) { // lfo - filter
        currentPatch.lfoAdest = 1;
      } else if (digitalRead(25) == 1) { // lfo - amp
        currentPatch.lfoAdest = 2;
      }
      oldLfoDestsw = lfoDestsw;
      parameterChanged = true;
      Serial.println("Lfo dest switch");
    }

    // lfoA shape
    if (digitalRead(26) == 1) {
      lfoShapesw = 0;
    } else if (digitalRead(26) == 0 && digitalRead(27) == 0) {
      lfoShapesw = 1;
    } else if (digitalRead(27) == 1) {
      lfoShapesw = 2;
    }

    if (oldLfoShapesw < lfoShapesw || oldLfoShapesw > lfoShapesw) {
      if (digitalRead(26) == 1) {
        currentPatch.lfoAshape = 0;
      } else if (digitalRead(26) == 0 && digitalRead(27) == 0) {
        currentPatch.lfoAshape = 1;
      } else if (digitalRead(27) == 1) {
        currentPatch.lfoAshape = 2;
      }
      oldLfoShapesw = lfoShapesw;
      parameterChanged = true;
      Serial.println("Lfo shape switch");
    }

    ///////////// LFO B    LFO B
    /////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    lfoBAmppot = analogRead(A14);
    if (oldLfoBAmppot + tresh2 < lfoBAmppot ||
        oldLfoBAmppot - tresh2 > lfoBAmppot) {
      currentPatch.lfoBamp = (float)analogRead(A14) / 1023;
      oldLfoBAmppot = lfoBAmppot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Lfo B amp turn");
    }

    lfoBFreqpot = analogRead(A22);
    if (oldLfoBFreqpot + tresh2 < lfoBFreqpot ||
        oldLfoBFreqpot - tresh2 > lfoBFreqpot) {
      currentPatch.lfoBfreq = 5 * (float)analogRead(A22) / 1023 + 0.1;
      oldLfoBFreqpot = lfoBFreqpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Lfo B freq turn");
    }

    //////////////// FX FX FX FX
    /////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Delay
    dlyAmtpot = analogRead(A16);
    if (oldDlyAmtpot + tresh2 < dlyAmtpot ||
        oldDlyAmtpot - tresh2 > dlyAmtpot) {
      currentPatch.dlyAmt = (float)analogRead(A16) / 1100 - 0.1;
      if (currentPatch.dlyAmt < 0) {
        currentPatch.dlyAmt = 0;
      }
      oldDlyAmtpot = dlyAmtpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Dly amt turn");
    }

    dlyTimepot = analogRead(A17);
    if (oldDlyTimepot + tresh2 < dlyTimepot ||
        oldDlyTimepot - tresh2 > dlyTimepot) {
      currentPatch.dlyTimeL = analogRead(A17) / 2.5;
      currentPatch.dlyTimeR = analogRead(A17) / 1.25;
      oldDlyTimepot = dlyTimepot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Dly time turn");
    }

    // Reverb
    revMixpot = analogRead(A19);
    if (oldRevMixpot + tresh2 < revMixpot ||
        oldRevMixpot - tresh2 > revMixpot) {
      currentPatch.revMix = ((float)analogRead(A19) / 1024 / 1.2);
      oldRevMixpot = revMixpot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Rev mix turn");
    }

    revSizepot = analogRead(A18);
    if (oldRevSizepot + tresh2 < revSizepot ||
        oldRevSizepot - tresh2 > revSizepot) {
      currentPatch.revSize = ((float)analogRead(A18) / 1024 - 0.01);
      oldRevSizepot = revSizepot + tresh2 / 2;
      parameterChanged = true;
      Serial.println("Rev size turn");
    }
  }
}
