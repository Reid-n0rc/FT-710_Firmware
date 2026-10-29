// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex030503_draw @ fffccb66 (128 bytes)

/* Menu item ex030503 CH STEP: on_draw (#74) */

void menu_ex030503_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009afb;
  bStack_7 = DAT_00009afb;
  if (DAT_00009afb == 2) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (3 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x15c6);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030504_draw @ fffccbe6 (128 bytes)

/* Menu item ex030504 AM CH STEP: on_draw (#74) */

void menu_ex030504_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009afc;
  bStack_7 = DAT_00009afc;
  if (DAT_00009afc == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (5 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x161a);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030505_draw @ fffccc66 (128 bytes)

/* Menu item ex030505 FM CH STEP: on_draw (#74) */

void menu_ex030505_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009afd;
  bStack_7 = DAT_00009afd;
  if (DAT_00009afd == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (5 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1698);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030506_draw @ fffccce6 (128 bytes)

/* Menu item ex030506 MAIN STEPS PER REV.: on_draw (#74) */

void menu_ex030506_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009afe;
  bStack_7 = DAT_00009afe;
  if (DAT_00009afe == 2) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1716);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040101_draw @ fffccd66 (103 bytes)

/* Menu item ex040101 MY CALL: on_draw (#74) */

void menu_ex040101_draw(byte *param_1)

{
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 0xc;
  param_1[2] = 0;
  *(undefined4 *)(param_1 + 0x20) = DAT_00009b09;
  *(undefined4 *)(param_1 + 0x1c) = DAT_00009b05;
  *(undefined4 *)(param_1 + 0x18) = DAT_00009b01;
  return;
}


// ===== menu_ex040102_draw @ fffccdcd (128 bytes)

/* Menu item ex040102 MY CALL TIME: on_draw (#74) */

void menu_ex040102_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b0d;
  bStack_7 = DAT_00009b0d;
  if (DAT_00009b0d == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (5 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1755);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040103_draw @ fffcce4d (128 bytes)

/* Menu item ex040103 POP-UP TIME: on_draw (#74) */

void menu_ex040103_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b0e;
  bStack_7 = DAT_00009b0e;
  if (DAT_00009b0e == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x17d3);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040104_draw @ fffccecd (128 bytes)

/* Menu item ex040104 SCREEN SAVER: on_draw (#74) */

void menu_ex040104_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b0f;
  bStack_7 = DAT_00009b0f;
  if (DAT_00009b0f == 3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (3 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (int)(&DAT_00001812 + (uint)bStack_7 * 0x15));
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040105_draw @ fffccf4d (129 bytes)

/* Menu item ex040105 LED DIMMER: on_draw (#74) */

void menu_ex040105_draw(byte *param_1)

{
  char cVar1;
  
  cVar1 = DAT_00009b10;
  if (DAT_00009b10 == '\x14') {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (cVar1 == '\0') {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  FUN_fff9c6f0(cVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex040106_draw @ fffccfce (107 bytes)

/* Menu item ex040106 MOUSE POINTER SPEED: on_draw (#74) */

void menu_ex040106_draw(byte *param_1)

{
  char cVar1;
  
  cVar1 = DAT_00009b11;
  if (DAT_00009b11 == '\n') {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  FUN_fff9c6f0(cVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex040201_draw @ fffcd039 (128 bytes)

/* Menu item ex040201 RBW: on_draw (#74) */

void menu_ex040201_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b14;
  bStack_7 = DAT_00009b14;
  if (DAT_00009b14 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1866);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040202_draw @ fffcd0b9 (128 bytes)

/* Menu item ex040202 SCOPE CTR: on_draw (#74) */

void menu_ex040202_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b15;
  bStack_7 = DAT_00009b15;
  if (DAT_00009b15 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (1 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x18a5);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040203_draw @ fffcd139 (128 bytes)

/* Menu item ex040203 2D DISP SENSITIVITY: on_draw (#74) */

void menu_ex040203_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b16;
  bStack_7 = DAT_00009b16;
  if (DAT_00009b16 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (1 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x18cf);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040204_draw @ fffcd1b9 (128 bytes)

/* Menu item ex040204 3DSS DISP SENSITIVITY: on_draw (#74) */

void menu_ex040204_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b17;
  bStack_7 = DAT_00009b17;
  if (DAT_00009b17 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (1 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x18cf);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040301_draw @ fffcd239 (128 bytes)

/* Menu item ex040301 VMI COLOR VFO-A: on_draw (#74) */

void menu_ex040301_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b1a;
  bStack_7 = DAT_00009b1a;
  if (DAT_00009b1a == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (3 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1ab5);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040302_draw @ fffcd2b9 (128 bytes)

/* Menu item ex040302 VMI COLOR VFO-B: on_draw (#74) */

void menu_ex040302_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b1b;
  bStack_7 = DAT_00009b1b;
  if (DAT_00009b1b == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (3 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1ab5);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040303_draw @ fffcd339 (128 bytes)

/* Menu item ex040303 VMI COLOR MEMORY: on_draw (#74) */

void menu_ex040303_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b1c;
  bStack_7 = DAT_00009b1c;
  if (DAT_00009b1c == 2) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (3 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1b33);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040304_draw @ fffcd3b9 (128 bytes)

/* Menu item ex040304 VMI COLOR CLAR: on_draw (#74) */

void menu_ex040304_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b1d;
  bStack_7 = DAT_00009b1d;
  if (DAT_00009b1d == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (1 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1b09);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040401_draw @ fffcd439 (21 bytes)

/* Menu item ex040401 EXT DISPLAY: on_draw (#74) */

void menu_ex040401_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb34b(param_1,DAT_00009b20,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex040402_draw @ fffcd44e (128 bytes)

/* Menu item ex040402 PIXEL: on_draw (#74) */

void menu_ex040402_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009b21;
  bStack_7 = DAT_00009b21;
  if (DAT_00009b21 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (1 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x18f9);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_m4_16_0_draw @ fffcd4ce (127 bytes)

/* Menu item m4_16_0 DAY: on_draw (#74) */

void menu_m4_16_0_draw(byte *param_1)

{
  FUN_fffcd54d();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  param_1[0x18] = (byte)PTR_DAT_00025d60[0xb4] >> 4 | 0x30;
  param_1[0x19] = PTR_DAT_00025d60[0xb4] & 0x3f | 0x30;
  return;
}


// ===== FUN_fffcd54d @ fffcd54d (136 bytes)

void FUN_fffcd54d(void)

{
  if (PTR_DAT_00025d60[0x3ff] == '\x03') {
    PTR_DAT_00025d60[0x40a] = 1;
    return;
  }
  PTR_DAT_00025d60[0xb3] = PTR_DAT_00025d60[0xae];
  if (PTR_DAT_00025d60[0xae] == '\0') {
    PTR_DAT_00025d60[0xb3] = 1;
  }
  PTR_DAT_00025d60[0xb4] = PTR_DAT_00025d60[0xaf];
  if (PTR_DAT_00025d60[0xaf] == '\0') {
    PTR_DAT_00025d60[0xb4] = 1;
  }
  PTR_DAT_00025d60[0xb2] = PTR_DAT_00025d60[0xad];
  PTR_DAT_00025d60[0xb5] = PTR_DAT_00025d60[0xb0];
  PTR_DAT_00025d60[0xb6] = PTR_DAT_00025d60[0xb1];
  return;
}


// ===== menu_m4_16_1_draw @ fffcd5d5 (136 bytes)

/* Menu item m4_16_1 MONTH: on_draw (#74) */

void menu_m4_16_1_draw(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bStack_7;
  
  FUN_fffcd54d();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  bStack_7 = (((byte)PTR_DAT_00025d60[0xb3] >> 4) * '\n' + (PTR_DAT_00025d60[0xb3] & 0xf)) - 1;
  if (0xb < bStack_7) {
    bStack_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1923);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_m4_16_2_draw @ fffcd65d (159 bytes)

/* Menu item m4_16_2 YEAR: on_draw (#74) */

void menu_m4_16_2_draw(byte *param_1)

{
  FUN_fffcd54d();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  param_1[0x18] = 0x32;
  param_1[0x19] = 0x30;
  param_1[0x1a] = (byte)PTR_DAT_00025d60[0xb2] >> 4 | 0x30;
  param_1[0x1b] = PTR_DAT_00025d60[0xb2] & 0x3f | 0x30;
  return;
}


// ===== menu_m4_16_3_draw @ fffcd6fc (127 bytes)

/* Menu item m4_16_3 HOUR: on_draw (#74) */

void menu_m4_16_3_draw(byte *param_1)

{
  FUN_fffcd54d();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  param_1[0x18] = (byte)PTR_DAT_00025d60[0xb5] >> 4 | 0x30;
  param_1[0x19] = PTR_DAT_00025d60[0xb5] & 0x3f | 0x30;
  return;
}


// ===== menu_m4_16_4_draw @ fffcd77b (127 bytes)

/* Menu item m4_16_4 MINUTE: on_draw (#74) */

void menu_m4_16_4_draw(byte *param_1)

{
  FUN_fffcd54d();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  param_1[0x18] = (byte)PTR_DAT_00025d60[0xb6] >> 4 | 0x30;
  param_1[0x19] = PTR_DAT_00025d60[0xb6] & 0x3f | 0x30;
  return;
}


// ===== menu_m4_17_0_draw @ fffcd7fa (9 bytes)

/* Menu item m4_17_0 MEM LIST LOAD: on_draw (#74) */

void menu_m4_17_0_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== FUN_fffcd803 @ fffcd803 (98 bytes)

void FUN_fffcd803(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 4;
  param_1[2] = 0;
  *(undefined4 *)(param_1 + 0x28) = 0x20202020;
  *(undefined4 *)(param_1 + 0x24) = 0x20202020;
  *(undefined4 *)(param_1 + 0x20) = 0x20202020;
  *(undefined4 *)(param_1 + 0x1c) = 0x20202020;
  *(undefined4 *)(param_1 + 0x18) = 0x20202020;
  param_1[0x2c] = 0x20;
  *(undefined4 *)(param_1 + 0x18) = 0x454e4f44;
  return;
}


// ===== menu_m4_17_1_draw @ fffcd865 (9 bytes)

/* Menu item m4_17_1 MEM LIST SAVE: on_draw (#74) */

void menu_m4_17_1_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_17_2_draw @ fffcd86e (9 bytes)

/* Menu item m4_17_2 MENU LOAD: on_draw (#74) */

void menu_m4_17_2_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_17_3_draw @ fffcd877 (9 bytes)

/* Menu item m4_17_3 MENU SAVE: on_draw (#74) */

void menu_m4_17_3_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_17_4_draw @ fffcd880 (9 bytes)

/* Menu item m4_17_4 INFORMATIONS: on_draw (#74) */

void menu_m4_17_4_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_17_5_draw @ fffcd889 (9 bytes)

/* Menu item m4_17_5 FIRMWARE UPDATE: on_draw (#74) */

void menu_m4_17_5_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_17_6_draw @ fffcd892 (9 bytes)

/* Menu item m4_17_6 FORMAT: on_draw (#74) */

void menu_m4_17_6_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_18_0_draw @ fffcd89b (209 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcd969) */
/* Menu item m4_18_0 SOFTVERSION: on_draw (#74) */

char * menu_m4_18_0_draw(char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  
  cVar1 = DAT_00004660;
  pcVar4 = 
  "MAIN    : V00-00              DISPLAY : V00-00              DSP     : V00-00              SDR     : V00-00              DST     :                     BLUE                 GREEN                RED                  NONE                 RED                  NONE                 BLUE                 GREEN                WHITE                NONE                 OFF                  100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                550Hz                600Hz                650Hz                700Hz                750Hz                800Hz                850Hz                900Hz                950Hz                1000Hz               OFF                  700Hz                750Hz                800Hz                850Hz                900Hz                950Hz                1000Hz               1050Hz               1100Hz               1150Hz               1200Hz               1250Hz               1300Hz               1350Hz               1400Hz               1450Hz               1500Hz               1550Hz               1600Hz               1650Hz               1700Hz               1750Hz               1800Hz               1850Hz               1900Hz               1950Hz               2000Hz               2050Hz               2100Hz               2150Hz               2200Hz               2250Hz               2300Hz               2350Hz               2400Hz               2450Hz               2500Hz               2550Hz               2600Hz               2650Hz               2700Hz               2750Hz               2800Hz               2850Hz               2900Hz               2950Hz               3000Hz               3050Hz               3100Hz               3150Hz               3200Hz               3250Hz               3300Hz               3350Hz               3400Hz               3450Hz               3500Hz               3550Hz               3600Hz               3650Hz  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar2 = param_1;
  for (iVar5 = 0x96; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar2 = *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  }
  puVar3 = (undefined4 *)ver_main();
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(puVar3 + 1);
  *(undefined4 *)(param_1 + 10) = *puVar3;
  if (cVar1 != '\0') {
    param_1[0x10] = '-';
    puVar3 = (undefined4 *)FUN_fff94bd9();
    *(undefined4 *)(param_1 + 0x11) = *puVar3;
    puVar3 = (undefined4 *)FUN_fff94be5();
    *(undefined4 *)(param_1 + 0x1a) = puVar3[1];
    *(undefined4 *)(param_1 + 0x16) = *puVar3;
  }
  puVar3 = (undefined4 *)ver_display();
  *(undefined2 *)(param_1 + 0x2c) = *(undefined2 *)(puVar3 + 1);
  *(undefined4 *)(param_1 + 0x28) = *puVar3;
  if (cVar1 != '\0') {
    puVar3 = (undefined4 *)FUN_fff94c0f();
    *(undefined4 *)(param_1 + 0x38) = puVar3[1];
    *(undefined4 *)(param_1 + 0x34) = *puVar3;
  }
  puVar3 = (undefined4 *)ver_dsp();
  *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(puVar3 + 1);
  *(undefined4 *)(param_1 + 0x46) = *puVar3;
  puVar3 = (undefined4 *)ver_sdr();
  *(undefined2 *)(param_1 + 0x68) = *(undefined2 *)(puVar3 + 1);
  *(undefined4 *)(param_1 + 100) = *puVar3;
  param_1 = param_1 + 0x82;
  pcVar2 = (char *)FUN_fffb3fa7();
  for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
    *param_1 = *pcVar2;
    param_1 = param_1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return param_1;
}


// ===== menu_m4_19_0_draw @ fffcd96c (9 bytes)

/* Menu item m4_19_0 CALIBRATION: on_draw (#74) */

void menu_m4_19_0_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_20_0_draw @ fffcd975 (9 bytes)

/* Menu item m4_20_0 MEMORY CLEAR: on_draw (#74) */

void menu_m4_20_0_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_20_1_draw @ fffcd97e (9 bytes)

/* Menu item m4_20_1 MENU CLEAR: on_draw (#74) */

void menu_m4_20_1_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_20_2_draw @ fffcd987 (9 bytes)

/* Menu item m4_20_2 ALL RESET: on_draw (#74) */

void menu_m4_20_2_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== menu_m4_21_0_draw @ fffcd990 (9 bytes)

/* Menu item m4_21_0 CERTIFICATION: on_draw (#74) */

void menu_m4_21_0_draw(void)

{
  FUN_fffcd803();
  return;
}


// ===== FUN_fffcd999 @ fffcd999 (184 bytes)

undefined1 FUN_fffcd999(char param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uStack_4;
  
  bVar2 = param_1 - 1;
  bVar3 = menu_count_groups(PTR_DAT_00025d60[0x41f]);
  if (bVar2 < bVar3) {
    (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]] = bVar2;
    PTR_DAT_00025d60[0x420] = bVar2;
    if ((PTR_DAT_00025d60[0x41f] == '\x04') && (bVar2 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (PTR_DAT_00025d60[0x3ff] == '\x02') {
        PTR_DAT_00025d60[0x3ff] = 0;
      }
      uStack_4 = 1;
    }
    else {
      if (PTR_DAT_00025d60[0x41f] != '\x05') {
        bVar2 = DAT_00009bc9;
      }
      DAT_00009bc9 = bVar2;
      PTR_DAT_00025d60[0x3ff] = 2;
      uStack_4 = 1;
    }
  }
  else {
    uStack_4 = 0;
  }
  return uStack_4;
}


// ===== FUN_fffcda51 @ fffcda51 (213 bytes)

undefined1 FUN_fffcda51(char param_1)

{
  bool bVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  undefined1 uStack_9;
  
  bVar2 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  if (bVar2 == 0x12) {
    uStack_9 = 0;
  }
  else {
    pcVar3 = (char *)menu_cursor_of(bVar2);
    *pcVar3 = param_1;
    if (DAT_0001b4fc == '\0') {
      DAT_00015dfd = PTR_DAT_00025d60[0x41f];
      DAT_00015dff = *pcVar3 + pcVar3[1];
      if ((DAT_00015dfd == '\x04') && (bVar2 == 0x11)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) && (DAT_00015dff == '\x05')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        PTR_s_V01_12_0001b4fd._0_1_ = 1;
      }
      DAT_00015dfe = bVar2;
      iVar4 = FUN_fffcdb6b(&DAT_00015dfd);
      if (iVar4 == 1) {
        DAT_0001b4fc = '\x01';
      }
      else {
        menu_ui_enter();
      }
    }
    uStack_9 = 1;
  }
  return uStack_9;
}


// ===== FUN_fffcdb26 @ fffcdb26 (69 bytes)

void FUN_fffcdb26(void)

{
  byte bVar1;
  
  if (DAT_0001b4fc == '\x01') {
    DAT_0001b4fc = 2;
    swtimer_start(0x31,200);
    return;
  }
  if ((DAT_0001b4fc == '\x02') && (bVar1 = swtimer_expired(0x31), bVar1 == 1)) {
    DAT_0001b4fc = 0;
    menu_ui_enter();
    return;
  }
  return;
}


// ===== FUN_fffcdb6b @ fffcdb6b (77 bytes)

undefined1 FUN_fffcdb6b(int param_1)

{
  bool bVar1;
  undefined1 local_6;
  
  if ((*(char *)(param_1 + 1) == '\x14') || (*(char *)(param_1 + 1) == '\x11')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = 1;
  }
  else {
    if ((*(char *)(param_1 + 1) == '\f') && (*(char *)(param_1 + 2) == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_6 = 1;
    }
    else {
      local_6 = 0;
    }
  }
  return local_6;
}


// ===== FUN_fffcdbb8 @ fffcdbb8 (103 bytes)

void FUN_fffcdbb8(void)

{
  if (PTR_DAT_00025d60[0x40a] != '\x01') {
    return;
  }
  PTR_DAT_00025d60[0x40a] = 0;
  PTR_DAT_00025d60[0xae] = PTR_DAT_00025d60[0xb3];
  PTR_DAT_00025d60[0xaf] = PTR_DAT_00025d60[0xb4];
  PTR_DAT_00025d60[0xad] = PTR_DAT_00025d60[0xb2];
  PTR_DAT_00025d60[0xb0] = PTR_DAT_00025d60[0xb5];
  PTR_DAT_00025d60[0xb1] = PTR_DAT_00025d60[0xb6];
  PTR_DAT_00025d60[0x8d] = 1;
  return;
}


// ===== menu_ui_enter @ fffcdc1f (89 bytes)

/* Front panel: run the selected row's on_enter [inference] */

void menu_ui_enter(void)

{
  char *pcVar1;
  undefined1 uStack_5;
  byte bStack_4;
  char cStack_3;
  char cStack_2;
  byte bStack_1;
  
  PTR_DAT_00025d60[0x3ff] = 3;
  bStack_1 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pcVar1 = (char *)menu_cursor_of(bStack_1);
  cStack_3 = *pcVar1 + pcVar1[1];
  uStack_5 = PTR_DAT_00025d60[0x41f];
  bStack_4 = bStack_1;
  cStack_2 = cStack_3;
  menu_call_enter((uint)&uStack_5);
  FUN_fffc8f30(3000);
  return;
}


// ===== menu_enter_nop @ fffcdc78 (1 bytes)

/* Empty menu on_enter (RTS), shared by 296 items (#74) */

void menu_enter_nop(void)

{
  return;
}


// ===== FUN_fffcdc79 @ fffcdc79 (106 bytes)

undefined1 FUN_fffcdc79(void)

{
  byte bVar1;
  char *pcVar2;
  undefined1 uStack_9;
  
  bVar1 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pcVar2 = (char *)menu_cursor_of(bVar1);
  if (pcVar2 == (char *)0x0) {
    uStack_9 = 0;
  }
  else {
    bVar1 = menu_count_items(bVar1);
    if (bVar1 < 5) {
      uStack_9 = 0;
    }
    else if (pcVar2[1] == '\0') {
      uStack_9 = 0;
    }
    else {
      pcVar2[1] = pcVar2[1] + -1;
      if (*pcVar2 != '\x04') {
        *pcVar2 = *pcVar2 + '\x01';
      }
      uStack_9 = FUN_fffcdce3();
    }
  }
  return uStack_9;
}


// ===== FUN_fffcdce3 @ fffcdce3 (27 bytes)

undefined1 FUN_fffcdce3(void)

{
  if (PTR_DAT_00025d60[0x3ff] == '\x03') {
    FUN_fffcdcfe();
  }
  return 1;
}


// ===== FUN_fffcdcfe @ fffcdcfe (17 bytes)

void FUN_fffcdcfe(void)

{
  FUN_fffcdbb8();
  PTR_DAT_00025d60[0x3ff] = 2;
  return;
}

