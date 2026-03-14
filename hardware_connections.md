# TeensySynth - Conexiones de Hardware

Este documento detalla el conexionado físico de los componentes del sintetizador basado en Teensy. El objetivo de este archivo es servir como base para el diseño del esquema electrónico y la posterior creación de la placa de circuito impreso (PCB).

## 1. Microcontrolador
- **Placa:** Teensy 4.x (Confirmar versión exacta 4.0 / 4.1 / 4.2)

## 2. Entradas Digitales (Pulsadores / Interruptores)

Los siguientes pines están configurados como `INPUT_PULLDOWN` en el código actual (`b_setup.ino`). Algunos están marcados para ser movidos a un Multiplexor (MUX) o como sobrantes.

| Pin Teensy | Función Actual | Estado / Notas |
| :--- | :--- | :--- |
| **1** | Poly (Polifonía) | Activo |
| **2** | Shape A | *Pasar a MUX* |
| **3** | Shape A | *Sobra* |
| **4** | Shape B | *Pasar a MUX* |
| **5** | Shape B | *Sobra* |
| **6** | Main Octave | *Pasar a MUX* |
| **7** | Main Octave | *Sobra* |
| **8** | Octave B | *Pasar a MUX* |
| **10** | Octave C | *Pasar a MUX* |
| **11** | Octave C | *Sobra* |
| **12** | Octave B | *Sobra* |
| **13** | Filter Mode | Activo |
| **24** | LFO Dest | *Pasar a MUX?* |
| **25** | LFO Dest | *Sobra?* |
| **26** | LFO Shape | *Pasar a MUX* |
| **27** | LFO Shape | *Sobra?* |
| **44, 45, 46, 48, 49** | Entradas sin asignar | Reservados / Uso futuro |

## 3. Multiplexores (MUX) para Potenciómetros / Entradas

El sistema utiliza uno o varios multiplexores (ej. CD74HC4067 o 74HC4051) para leer múltiples potenciómetros o interruptores usando pocos pines.

### Pines de Control del MUX
Estos pines están configurados como salidas (`OUTPUT`) para seleccionar el canal del MUX:
- **Pin 28:** Control S0 (A)
- **Pin 29:** Control S1 (B)
- **Pin 30:** Control S2 (C)
*(Si se usa un MUX de 16 canales, faltaría el control S3)*

### Entrada Analógica del MUX
- **Pin A15:** `muxPots` - Entrada analógica donde se lee la señal de los potenciómetros conectados al multiplexor.

## 4. Audio (Audio Shield u otros DAC)
*(Si se utiliza la placa de audio de Teensy u otro DAC I2S, documentar aquí los pines ocupados. Normalmente I2S ocupa pines como 7, 8, 20, 21, 23. Verificar conflictos con las entradas digitales configuradas arriba).*

## 5. Alimentación y GND
- **VIN:** Entrada de alimentación (5V normalmente por USB o fuente externa).
- **3.3V:** Salida para alimentar potenciómetros y lógica de los MUX.
- **GND:** Tierra común para todos los componentes (Potenciómetros, MUX, Audio, Switches).

---
## 6. Referencia Histórica (Código Antiguo)

En las versiones antiguas del código (ahora en la carpeta `OLD`), se encontraba la siguiente asignación de canales para el Multiplexor. Esto puede servir de referencia sobre cómo se planeó el cableado originalmente:

| Función MUX | Canal |
| :--- | :--- |
| **LFO Speed** | 0 |
| **Release** | 1 |
| **Sustain** | 2 |
| **Attack** | 3 |
| **Decay** | 4 |
| **Osc 1** | 5 |
| **Osc 2** | 6 |
| **Detune** | 7 |
| **LFO Mode** | 8 |
| **Mix 1** | 9 |
| **Mix 2** | 10 |
| **Mix 3** | 11 |
| **Filter Res** | 12 |
| **Filter Freq** | 13 |
| **LFO Depth** | 14 |

---
> **Nota para el diseño del PCB:** 
> - Todos los potenciómetros deben estar conectados entre `3.3V` y `GND`, con el pin central (wiper) yendo a las entradas del Multiplexor.
> - Los interruptores conectados a pines configurados como `INPUT_PULLDOWN` deben conectar el pin a `3.3V` al cerrarse (ya que la resistencia de pulldown interna atrae el pin a GND cuando está abierto).
> - Revisar los pines marcados como "Pasar a MUX" en el código actual para consolidarlos y liberar pines directos del Teensy.
