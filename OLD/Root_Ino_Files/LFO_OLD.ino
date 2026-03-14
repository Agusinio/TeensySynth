/*Crear dos variables adicionales para almacenar el estado de cada LFO: una para
el LFO de amplitud (por ejemplo, "LFOamplitude") y otra para el LFO de
frecuencia (por ejemplo, "LFOfrequency"). Estas variables deberían ser
inicializadas en 0 al principio de la función.

Modificar las líneas de código que actualizan el filtro y la frecuencia de la
señal de audio para que utilicen las variables "LFOamplitude" y "LFOfrequency"
en lugar de la variable "LFO". Esto permitirá controlar los efectos de cada LFO
independientemente.

Crear un nuevo switch case para manejar los modos de cada LFO de manera
independiente. Esto podría incluir cases para cambiar el modo de "LFOamplitude"
y "LFOfrequency", así como para controlar la velocidad, la profundidad y otras
características de cada LFO.

Modificar el código en el case "CClfomode" del control change para que maneje
los modos de ambos LFOs de manera independiente. Esto podría ser una forma de
asignar un valor específico para cada modo de LFO (por ejemplo, el valor 0 para
apagar el LFO de amplitud, el valor 1 para ponerlo en modo libre, etc.).

Modificar cualquier otro código relevante para que utilice las nuevas variables
y modos de LFO.

*/
// PRIMER INTENTO

void LFOAMupdate(bool retrig) {
  static float LFOAM = 0;
  static unsigned long LFOAMtime = 0;
  static bool LFOAMdirection = false;
  unsigned long currentMicros = micros();
  static bool LFOAMstop = false;
  static float LFOAMrange = 0;
  static byte oldAMMode = 0;
  static bool retriggered = false;

  if (retrig == true)
    retriggered = true;

  if (currentMicros - LFOAMtime >= LFOAMspeed) {
    LFOAMtime = currentMicros;

    if (AMMode != oldAMMode) {
      oldAMMode = AMMode;
    }

    LFOAMrange = FILtop - FILbottom;
    if (LFOAMrange < 0)
      LFOAMrange = 0;

    // LFO AM Modes
    switch (AMMode) {
    case 0: // AM OFF
      return;
      break;
    case 1: // AM FREE
      LFOAMpitch = (LFOAM * LFOAMdepth) + 1;
      oscSet();
      break;
    case 2: // AM DOWN
      if (retriggered == true) {
        LFOAMdirection = true;
        LFOAM = 1.0;
      }
      LFOAMpitch = (LFOAM * LFOAMdepth) + 1;
      oscSet();
      break;
      // ...
    }
    // ...
  }

  void LFOFMupdate(bool retrig) {
    static float LFOFM = 0;
    static unsigned long LFOFMtime = 0;
    static bool LFOFMdirection = false;
    unsigned long currentMicros = micros();
    static bool LFOFMstop = false;
    static float LFOFMrange = 0;
    static byte oldFMMode = 0;
    static bool retriggered = false;

    if (retrig == true)
      retriggered = true;

    if (currentMicros - LFOFMtime >= LFOFMspeed) {
      LFOFMtime = currentMicros;

      if (FMMode != oldFMMode) {
        oldFMMode = FMMode;
      }

      LFOFMrange = FILtop - FILbottom;
      if (LFOFMrange < 0)
        LFOFMrange = 0;

      // LFO FM Modes
      switch (FMMode) {
      case 0: // FM OFF
        return;
        break;
      case 1: // FM FREE
        filter1.frequency(10000 * ((LFOFMrange * LFOFM) + LFOFMdepth));
        break;
      case 2: // FM DOWN
        if (retriggered == true) {
          LFOFMdirection = true;

          // SEGUNDO INTENTO

          void LFOupdateAM(bool retrig, byte mode, float AMtop,
                           float AMbottom) {
            static float LFOam = 0;
            static unsigned long LFOtime = 0;
            static bool LFOdirection = false;
            unsigned long currentMicros = micros();
            static bool LFOstop = false;
            static float AMrange = 0;
            static byte oldMode = 0;
            static bool retriggered = false;

            if (retrig == true)
              retriggered = true;

            if (currentMicros - LFOtime >= LFOspeed) {
              LFOtime = currentMicros;

              if (mode != oldMode) {
                oldMode = mode;
              }

              AMrange = AMtop - AMbottom;
              if (AMrange < 0)
                AMrange = 0;

              // LFO Modes
              switch (mode) {
              case 0: // AM OFF
                return;
                break;
              case 1: // AM FREE
                LFOam = (AMrange * LFOam) + LFOdepth;
                // apply LFOam to the amplitude
                break;
              case 2: // AM DOWN
                if (retriggered == true) {
                  LFOdirection = true;
                  LFOam = 1.0;
                }
                LFOam = (AMrange * LFOam) + LFOdepth;
                // apply LFOam to the amplitude
                break;
              case 3: // AM UP
                if (retriggered == true) {
                  LFOdirection = false;
                  LFOam = 0;
                }
                LFOam = (AMrange * LFOam) + LFOdepth;
                // apply LFOam to the amplitude
                break;
              case 4: // AM 1-DN
                if (retriggered == true) {
                  LFOstop = false;
                  LFOdirection = true;
                  LFOam = 1.0;
                }
                if (LFOstop == false) {
                  LFOam = (AMrange * LFOam) + LFOdepth;
                  // apply LFOam to the amplitude
                }
                break;
              case 5: // AM 1-UP
                if (retriggered == true) {
                  LFOstop = false;
                  LFOdirection = false;
                  LFOam = 0;
                }
                if (LFOstop == false) {
                  LFOam = (AMrange * LFOam) + LFOdepth;
                  // apply LFOam to the amplitude
                }
                break;
                //... add other cases as needed
              }
            }
          }

          void LFOupdateFM(bool retrig, byte mode, float FMtop,
                           float FMbottom) {
            static float LFOfm = 0;
            static unsigned long LFOtime = 0;
            static bool LFOdirection = false;
            unsigned long currentMicros = micros();
            static bool LFO

                // TERCER INTENTO

                void
                LFOupdateAM(bool retrig, byte mode, float AMtop,
                            float AMbottom) {
              static float LFOam = 0;
              static unsigned long LFOtime = 0;
              static bool LFOdirection = false;
              unsigned long currentMicros = micros();
              static bool LFOstop = false;
              static float AMrange = 0;
              static byte oldMode = 0;
              static bool retriggered = false;

              if (retrig == true)
                retriggered = true;

              if (currentMicros - LFOtime >= LFOspeed) {
                LFOtime = currentMicros;

                if (mode != oldMode) {
                  oldMode = mode;
                }

                AMrange = AMtop - AMbottom;
                if (AMrange < 0)
                  AMrange = 0;

                // LFO Modes
                switch (mode) {
                case 0: // AM OFF
                  return;
                  break;
                case 1: // AM FREE
                  LFOam = (AMrange * LFOam) + LFOdepth;
                  // apply LFOam to the amplitude
                  break;
                case 2: // AM DOWN
                  if (retriggered == true) {
                    LFOdirection = true;
                    LFOam = 1.0;
                  }
                  LFOam = (AMrange * LFOam) + LFOdepth;
                  // apply LFOam to the amplitude
                  break;
                case 3: // AM UP
                  if (retriggered == true) {
                    LFOdirection = false;
                    LFOam = 0;
                  }
                  LFOam = (AMrange * LFOam) + LFOdepth;
                  // apply LFOam to the amplitude
                  break;
                case 4: // AM 1-DN
                  if (retriggered == true) {
                    LFOstop = false;
                    LFOdirection = true;
                    LFOam = 1.0;
                  }
                  if (LFOstop == false) {
                    LFOam = (AMrange * LFOam) + LFOdepth;
                    // apply LFOam to the amplitude
                  }
                  break;
                case 5: // AM 1-UP
                  if (retriggered == true) {
                    LFOstop = false;
                    LFOdirection = false;
                    LFOam = 0;
                  }
                  if (LFOstop == false) {
                    LFOam = (AMrange * LFOam) + LFOdepth;
                    // apply LFOam to the amplitude
                  }
                  break;
                  //... add other cases as needed
                }
              }
            }

            void LFOupdateFM(bool retrig, byte mode, float FMtop,
                             float FMbottom) {
              static float LFOfm = 0;
              static unsigned long LFOtime = 0;
              static bool LFOdirection = false;
              unsigned long currentMicros = micros();
              static bool LFO

                  // CUARTO INTENTO

                  void
                  LFOupdateAM(bool retrig, byte mode, float FILtop,
                              float FILbottom) {
                static float LFOAM = 0;
                static unsigned long LFOAMtime = 0;
                static bool LFOAMdirection = false;
                unsigned long currentMicros = micros();
                static bool LFOAMstop = false;
                static float LFOAMRange = 0;
                static byte oldMode = 0;
                static bool retriggered = false;

                if (retrig == true)
                  retriggered = true;

                if (currentMicros - LFOAMtime >= LFOAMspeed) {
                  LFOAMtime = currentMicros;

                  if (mode != oldMode) {
                    if (mode == 0 || mode == 8) {
                      LFOpitch = 1;
                      oscSet();
                      filter1.frequency(FILfreq);
                    } else if (mode >= 1 || mode <= 7) {
                      LFOpitch = 1;
                      oscSet();
                    }
                    oldMode = mode;
                  }

                  LFOAMRange = FILtop - FILbottom;
                  if (LFOAMRange < 0)
                    LFOAMRange = 0;

                  // LFO AM Modes
                  switch (mode) {

                  case 0: // AM OFF
                    return;
                    break;
                  case 1: // AM FREE
                    osc1.amplitude(LFOAMRange * LFOAM + LFOAMdepth);
                    break;
                  case 2: // AM DOWN
                    if (retriggered == true) {
                      LFOAMdirection = true;
                      LFOAM = 1.0;
                    }
                    osc1.amplitude(LFOAMRange * LFOAM + LFOAMdepth);
                    break;
                  case 3: // AM UP
                    if (retriggered == true) {
                      LFOAMdirection = false;
                      LFOAM = 0;
                    }
                    osc1.amplitude(LFOAMRange * LFOAM + LFOAMdepth);
                    break;
                  case 4: // AM 1-DN
                    if (retriggered == true) {
                      LFOAMstop = false;
                      LFOAMdirection = true;
                      LFOAM = 1.0;
                    }
                    if (LFOAMstop == false)
                      osc1.amplitude(LFOAMRange * LFOAM + LFOAMdepth);
                    break;
                  case 5: // AM 1-UP
                    if (retriggered == true) {
                      LFOAMstop = false;
                      LFOAMdirection = false;
                      LFOAM = 0;
                    }
                    if (LFOAMstop == false)
                      osc1.ampl

                          // QUINTO INTENTO

                          void
                          LFOupdateFM(bool retrig, byte mode, float FILtop,
                                      float FILbottom) {
                        static float LFO_FM = 0;
                        static unsigned long LFOtime_FM = 0;
                        static bool LFOdirection_FM = false;
                        unsigned long currentMicros = micros();
                        static bool LFOstop_FM = false;
                        static float LFOrange_FM = 0;
                        static byte oldMode_FM = 0;
                        static bool retriggered_FM = false;

                        if (retrig == true)
                          retriggered_FM = true;

                        if (currentMicros - LFOtime_FM >= LFOspeed_FM) {
                          LFOtime_FM = currentMicros;

                          if (mode != oldMode_FM) {
                            oldMode_FM = mode;
                          }

                          LFOrange_FM = FILtop - FILbottom;
                          if (LFOrange_FM < 0)
                            LFOrange_FM = 0;

                          // LFO Modes
                          switch (mode) {
                          case 0: // FM OFF
                            return;
                            break;
                          case 9: // FM FREE
                            // Aqui modifica la frecuencia base de la señal
                            LFOpitch_FM = (LFO_FM * LFOdepth_FM) + 1;
                            oscSet();
                            break;
                          case 10: // FM DOWN
                            if (retriggered_FM == true) {
                              LFOdirection_FM = true;
                              LFO_FM = 1.0;
                            }
                            // Aqui modifica la frecuencia base de la señal
                            LFOpitch_FM = (LFO_FM * LFOdepth_FM) + 1;
                            oscSet();
                            break;
                          case 11: // FM UP
                            if (retriggered_FM == true) {
                              LFOdirection_FM = false;
                              LFO_FM = 0;
                            }
                            // Aqui modifica la frecuencia base de la señal
                            LFOpitch_FM = (LFO_FM * LFOdepth_FM) + 1;
                            oscSet();
                            break;
                            // Aqui se podrian poner mas casos, como el caso 12
                            // y 13
                            //...
                          }
                        }
                        // Actualizar el valor de LFO_FM segun el modo y
                        // direccion
                        if (LFOdirection_FM == false)
                          LFO_FM += (1.0 / LFOspeed_FM);
                        else
                          LFO_FM -= (1.0 / LFOspeed_FM);
                        if (LFO_FM > 1.0)
                          LFO_FM = 1.

                              // SEXTO INTENTO

                              void
                              LFOupdateFM(bool retrig, byte mode, float FILtop,
                                          float FILbottom) {
                            static float LFO_FM = 0;
                            static unsigned long LFOtime = 0;
                            static bool LFOdirection = false;
                            unsigned long currentMicros = micros();
                            static bool LFOstop = false;
                            static float LFOrange = 0;
                            static byte oldMode = 0;
                            static bool retriggered = false;

                            if (retrig == true)
                              retriggered = true;

                            if (currentMicros - LFOtime >= LFOspeed) {
                              LFOtime = currentMicros;

                              if (mode != oldMode) {
                                // si el modo cambió, actualizar las
                                // configuraciones
                                oldMode = mode;
                              }

                              LFOrange = FILtop - FILbottom;
                              if (LFOrange < 0)
                                LFOrange = 0;

                              // Actualizar el valor de LFO_FM segun el modo y
                              // direccion
                              switch (mode) {
                              case 0: // FM OFF
                                return;
                                break;
                              case 1: // FM FREE
                                // Aquí se actualiza el valor de la frecuencia
                                // modulada usando el valor actual de LFO_FM
                                break;
                              case 2: // FM DOWN
                                if (retriggered == true) {
                                  LFOdirection = true;
                                  LFO_FM = 1.0;
                                }
                                // Aquí se actualiza el valor de la frecuencia
                                // modulada usando el valor actual de LFO_FM
                                break;
                              case 3: // FM UP
                                if (retriggered == true) {
                                  LFOdirection = false;
                                  LFO_FM = 0;
                                }
                                // Aquí se actualiza el valor de la frecuencia
                                // modulada usando el valor actual de LFO_FM
                                break;
                                // ... y así sucesivamente para los demás modos
                              }

                              if (LFOdirection == true) {
                                LFO_FM = LFO_FM - (1 / (LFOspeed / 2));
                                if (LFO_FM <= 0) {
                                  LFO_FM = 0;
                                  LFOdirection = false;
                                }
                              } else {
                                LFO_FM = LFO_FM + (1 / (LFOspeed / 2));
                                if (LFO_FM >= 1) {
                                  LFO_FM = 1;
                                  LFOdirection = true;
                                }
                              }
                              retriggered = false;
                            }
                          }
