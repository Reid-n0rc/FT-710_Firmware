// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex030117_draw @ fffcbe6b (128 bytes)

/* Menu item ex030117 MIC SCAN RESUME: on_draw (#74) */

void menu_ex030117_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009ac5;
  bStack_7 = DAT_00009ac5;
  if (DAT_00009ac5 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (1 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x112e);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030118_draw @ fffcbeeb (107 bytes)

/* Menu item ex030118 REF FREQ FINE ADJ: on_draw (#74) */

void menu_ex030118_draw(byte *param_1)

{
  char cVar1;
  
  cVar1 = DAT_00009ac6;
  if (DAT_00009ac6 == '\0') {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c787((int)cVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex030119_draw @ fffcbf56 (223 bytes)

/* Menu item ex030119 KEYBOARD LANGUAGE: on_draw (#74) */

void menu_ex030119_draw(byte *param_1)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  int iVar4;
  byte bStack_8;
  byte bStack_7;
  
  bVar1 = DAT_00009ac7;
  bStack_7 = DAT_00009ac7;
  uVar2 = dest_code_get();
  if (uVar2 == 0xd950) {
LAB_fffcbfc4:
    bStack_8 = 2;
    goto LAB_fffcbfc7;
  }
  if (((uVar2 != 0x1cb9) && (uVar2 != 0x306f)) && (uVar2 != 0x315b)) {
    if (uVar2 == 0x4380) {
LAB_fffcbfb7:
      bStack_8 = 0;
      goto LAB_fffcbfc7;
    }
    if (uVar2 != 0x50e2) {
      if (uVar2 == 0x60e6) goto LAB_fffcbfb7;
      if ((uVar2 != 0x7753) && (uVar2 != 0x9cf7)) {
        if (uVar2 == 0xa4c5) goto LAB_fffcbfc4;
        if (uVar2 != 0xd32d) {
          if (uVar2 != 0x20b) {
            bStack_8 = 5;
            goto LAB_fffcbfc7;
          }
          goto LAB_fffcbfb7;
        }
      }
    }
  }
  bStack_8 = 1;
LAB_fffcbfc7:
  if (bVar1 == bStack_8) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 0xe;
  param_1[2] = 0;
  if (10 < bVar1) {
    bStack_7 = 0;
  }
  pbVar3 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1158);
  param_1 = param_1 + 0x18;
  for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
    *param_1 = *pbVar3;
    param_1 = param_1 + 1;
    pbVar3 = pbVar3 + 1;
  }
  return;
}


// ===== menu_ex030120_draw @ fffcc035 (21 bytes)

/* Menu item ex030120 MIC P1: on_draw (#74) */

void menu_ex030120_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc04a(param_1,DAT_00009ac8,0,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcc04a @ fffcc04a (120 bytes)

void FUN_fffcc04a(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 9;
  param_1[2] = 0;
  local_5 = param_2;
  if (0x14 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x123f);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030121_draw @ fffcc0c2 (21 bytes)

/* Menu item ex030121 MIC P2: on_draw (#74) */

void menu_ex030121_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc04a(param_1,DAT_00009ac9,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030122_draw @ fffcc0d7 (21 bytes)

/* Menu item ex030122 MIC P3: on_draw (#74) */

void menu_ex030122_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc04a(param_1,DAT_00009aca,2,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030123_draw @ fffcc0ec (21 bytes)

/* Menu item ex030123 MIC P4: on_draw (#74) */

void menu_ex030123_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc04a(param_1,DAT_00009acb,3,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030124_draw @ fffcc101 (21 bytes)

/* Menu item ex030124 MIC UP: on_draw (#74) */

void menu_ex030124_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc04a(param_1,DAT_00009acc,0xd,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030125_draw @ fffcc116 (21 bytes)

/* Menu item ex030125 MIC DOWN: on_draw (#74) */

void menu_ex030125_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc04a(param_1,DAT_00009acd,0xe,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030126_draw @ fffcc12b (21 bytes)

/* Menu item ex030126 SCU-LAN10: on_draw (#74) */

void menu_ex030126_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb34b(param_1,DAT_00009ace,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030201_draw @ fffcc140 (128 bytes)

/* Menu item ex030201 IF NOTCH WIDTH: on_draw (#74) */

void menu_ex030201_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009ad1;
  bStack_7 = DAT_00009ad1;
  if (DAT_00009ad1 == 1) {
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
                   + (uint)bStack_7 * 0x15 + 0x13f8);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030202_draw @ fffcc1c0 (128 bytes)

/* Menu item ex030202 NB REJECTION: on_draw (#74) */

void menu_ex030202_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009ad2;
  bStack_7 = DAT_00009ad2;
  if (DAT_00009ad2 == 1) {
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
                   + (uint)bStack_7 * 0x15 + 0x1422);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030203_draw @ fffcc240 (128 bytes)

/* Menu item ex030203 NB WIDTH: on_draw (#74) */

void menu_ex030203_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009ad3;
  bStack_7 = DAT_00009ad3;
  if (DAT_00009ad3 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (2 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (int)(&DAT_00001461 + (uint)bStack_7 * 0x15));
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030204_draw @ fffcc2c0 (128 bytes)

/* Menu item ex030204 APF WIDTH: on_draw (#74) */

void menu_ex030204_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009ad4;
  bStack_7 = DAT_00009ad4;
  if (DAT_00009ad4 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (2 < bVar1) {
    bStack_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x14a0);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030205_draw @ fffcc340 (108 bytes)

/* Menu item ex030205 CONTOUR LEVEL: on_draw (#74) */

void menu_ex030205_draw(byte *param_1)

{
  char cVar1;
  
  cVar1 = DAT_00009ad5;
  if (DAT_00009ad5 == -0xf) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c787((int)cVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex030206_draw @ fffcc3ac (107 bytes)

/* Menu item ex030206 CONTOUR WIDTH: on_draw (#74) */

void menu_ex030206_draw(byte *param_1)

{
  char cVar1;
  
  cVar1 = DAT_00009ad6;
  if (DAT_00009ad6 == '\n') {
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


// ===== menu_ex030301_draw @ fffcc417 (128 bytes)

/* Menu item ex030301 AMC RELEASE TIME: on_draw (#74) */

void menu_ex030301_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009ad9;
  bStack_7 = DAT_00009ad9;
  if (DAT_00009ad9 == 1) {
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
                   + (uint)bStack_7 * 0x15 + 0x14df);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030302_draw @ fffcc497 (24 bytes)

/* Menu item ex030302 PRMTRC EQ1 FREQ: on_draw (#74) */

void menu_ex030302_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
  FUN_fffcc4af(param_1,100,DAT_00009ada,0,in_R15,param_1);
  return;
}


// ===== FUN_fffcc4af @ fffcc4af (167 bytes)

void FUN_fffcc4af(byte *param_1,short param_2,byte param_3,byte param_4)

{
  byte bVar1;
  ushort local_c;
  
  if (param_3 == param_4) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (param_3 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  local_c = ((ushort)param_3 * 100 + param_2) - 100;
  if (0xc80 < local_c) {
    local_c = 0xc80;
  }
  bVar1 = FUN_fff9c843(local_c,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== menu_ex030303_draw @ fffcc556 (21 bytes)

/* Menu item ex030303 PRMTRC EQ1 LEVEL: on_draw (#74) */

void menu_ex030303_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc56b(param_1,(int)DAT_00009adb,5,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcc56b @ fffcc56b (99 bytes)

void FUN_fffcc56b(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c787((int)param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex030304_draw @ fffcc5ce (21 bytes)

/* Menu item ex030304 PRMTRC EQ1 BWTH: on_draw (#74) */

void menu_ex030304_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc5e3(param_1,DAT_00009adc,10,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcc5e3 @ fffcc5e3 (98 bytes)

void FUN_fffcc5e3(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  FUN_fff9c6f0(param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex030305_draw @ fffcc645 (25 bytes)

/* Menu item ex030305 PRMTRC EQ2 FREQ: on_draw (#74) */

void menu_ex030305_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
  FUN_fffcc4af(param_1,700,DAT_00009add,0,in_R15,param_1);
  return;
}


// ===== menu_ex030306_draw @ fffcc65e (21 bytes)

/* Menu item ex030306 PRMTRC EQ2 LEVEL: on_draw (#74) */

void menu_ex030306_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc56b(param_1,(int)DAT_00009ade,5,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030307_draw @ fffcc673 (21 bytes)

/* Menu item ex030307 PRMTRC EQ2 BWTH: on_draw (#74) */

void menu_ex030307_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc5e3(param_1,DAT_00009adf,10,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030308_draw @ fffcc688 (25 bytes)

/* Menu item ex030308 PRMTRC EQ3 FREQ: on_draw (#74) */

void menu_ex030308_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
  FUN_fffcc4af(param_1,0x5dc,DAT_00009ae0,0,in_R15,param_1);
  return;
}


// ===== menu_ex030309_draw @ fffcc6a1 (21 bytes)

/* Menu item ex030309 PRMTRC EQ3 LEVEL: on_draw (#74) */

void menu_ex030309_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc56b(param_1,(int)DAT_00009ae1,5,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030310_draw @ fffcc6b6 (21 bytes)

/* Menu item ex030310 PRMTRC EQ3 BWTH: on_draw (#74) */

void menu_ex030310_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc5e3(param_1,DAT_00009ae2,10,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030311_draw @ fffcc6cb (24 bytes)

/* Menu item ex030311 P PRMTRC EQ1 FREQ: on_draw (#74) */

void menu_ex030311_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
  FUN_fffcc4af(param_1,100,DAT_00009ae3,0,in_R15,param_1);
  return;
}


// ===== menu_ex030312_draw @ fffcc6e3 (21 bytes)

/* Menu item ex030312 P PRMTRC EQ1 LEVEL: on_draw (#74) */

void menu_ex030312_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc56b(param_1,(int)DAT_00009ae4,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030313_draw @ fffcc6f8 (21 bytes)

/* Menu item ex030313 P PRMTRC EQ1 BWTH: on_draw (#74) */

void menu_ex030313_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc5e3(param_1,DAT_00009ae5,2,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030314_draw @ fffcc70d (25 bytes)

/* Menu item ex030314 P PRMTRC EQ2 FREQ: on_draw (#74) */

void menu_ex030314_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
  FUN_fffcc4af(param_1,700,DAT_00009ae6,0,in_R15,param_1);
  return;
}


// ===== menu_ex030315_draw @ fffcc726 (21 bytes)

/* Menu item ex030315 P PRMTRC EQ2 LEVEL: on_draw (#74) */

void menu_ex030315_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc56b(param_1,(int)DAT_00009ae7,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030316_draw @ fffcc73b (21 bytes)

/* Menu item ex030316 P PRMTRC EQ2 BWTH: on_draw (#74) */

void menu_ex030316_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc5e3(param_1,DAT_00009ae8,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030317_draw @ fffcc750 (25 bytes)

/* Menu item ex030317 P PRMTRC EQ3 FREQ: on_draw (#74) */

void menu_ex030317_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
  FUN_fffcc4af(param_1,0x5dc,DAT_00009ae9,0,in_R15,param_1);
  return;
}


// ===== menu_ex030318_draw @ fffcc769 (21 bytes)

/* Menu item ex030318 P PRMTRC EQ3 LEVEL: on_draw (#74) */

void menu_ex030318_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc56b(param_1,(int)DAT_00009aea,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030319_draw @ fffcc77e (21 bytes)

/* Menu item ex030319 P PRMTRC EQ3 BWTH: on_draw (#74) */

void menu_ex030319_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcc5e3(param_1,DAT_00009aeb,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030401_draw @ fffcc793 (73 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcc793) */
/* WARNING: Removing unreachable block (ram,0xfffcc7d9) */
/* WARNING: Removing unreachable block (ram,0xfffcc7d6) */
/* Menu item ex030401 HF MAX POWER: on_draw (#74) */

undefined1 * menu_ex030401_draw(undefined4 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = DAT_00009aee;
  uVar2 = FUN_fffb3e6f(0);
  FUN_fffcc7dc(param_1,bVar1,uVar2);
  if (DAT_00009bf8 <= DAT_00009aee) {
    return &DAT_00009aee;
  }
  DAT_00009bf8 = DAT_00009aee;
  return &DAT_00009aee;
}


// ===== FUN_fffcc7dc @ fffcc7dc (116 bytes)

void FUN_fffcc7dc(byte *param_1,char param_2,char param_3)

{
  byte bVar1;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  bVar1 = FUN_fff9c6f0(param_2,param_1 + 0x18);
  param_1[bVar1 + 0x18] = 0x57;
  return;
}


// ===== menu_ex030402_draw @ fffcc850 (73 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcc850) */
/* WARNING: Removing unreachable block (ram,0xfffcc896) */
/* WARNING: Removing unreachable block (ram,0xfffcc893) */
/* Menu item ex030402 50M MAX POWER: on_draw (#74) */

undefined1 * menu_ex030402_draw(undefined4 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = DAT_00009aef;
  uVar2 = FUN_fffb3e6f(1);
  FUN_fffcc7dc(param_1,bVar1,uVar2);
  if (DAT_00009bf9 <= DAT_00009aef) {
    return &DAT_00009aef;
  }
  DAT_00009bf9 = DAT_00009aef;
  return &DAT_00009aef;
}


// ===== menu_ex030403_draw @ fffcc899 (73 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcc899) */
/* WARNING: Removing unreachable block (ram,0xfffcc8df) */
/* WARNING: Removing unreachable block (ram,0xfffcc8dc) */
/* Menu item ex030403 70M MAX POWER: on_draw (#74) */

undefined1 * menu_ex030403_draw(undefined4 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = DAT_00009af0;
  uVar2 = FUN_fffb3e6f(2);
  FUN_fffcc7dc(param_1,bVar1,uVar2);
  if (DAT_00009bfa <= DAT_00009af0) {
    return &DAT_00009af0;
  }
  DAT_00009bfa = DAT_00009af0;
  return &DAT_00009af0;
}


// ===== menu_ex030404_draw @ fffcc8e2 (90 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcc8e2) */
/* WARNING: Removing unreachable block (ram,0xfffcc939) */
/* WARNING: Removing unreachable block (ram,0xfffcc936) */
/* Menu item ex030404 AM MAX POWER: on_draw (#74) */

undefined1 * menu_ex030404_draw(undefined4 param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined1 uStack_11;
  
  uVar2 = dest_code_get();
  bVar1 = DAT_00009af1;
  if (uVar2 == 0x60e6) {
    uStack_11 = 4;
  }
  else {
    uStack_11 = 3;
  }
  uVar3 = FUN_fffb3e6f(uStack_11);
  FUN_fffcc7dc(param_1,bVar1,uVar3);
  if (DAT_00009bfb <= DAT_00009af1) {
    return &DAT_00009af1;
  }
  DAT_00009bfb = DAT_00009af1;
  return &DAT_00009af1;
}


// ===== menu_ex030405_draw @ fffcc93c (128 bytes)

/* Menu item ex030405 VOX SELECT: on_draw (#74) */

void menu_ex030405_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009af3;
  bStack_7 = DAT_00009af3;
  if (DAT_00009af3 == 0) {
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
                   + (uint)bStack_7 * 0x15 + 0x151e);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030406_draw @ fffcc9bc (21 bytes)

/* Menu item ex030406 EMERGENCY FREQ TX: on_draw (#74) */

void menu_ex030406_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb34b(param_1,DAT_00009af4,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030407_draw @ fffcc9d1 (21 bytes)

/* Menu item ex030407 TX INHITBIT: on_draw (#74) */

void menu_ex030407_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb34b(param_1,DAT_00009af5,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030408_draw @ fffcc9e6 (128 bytes)

/* Menu item ex030408 METER DETECTOR: on_draw (#74) */

void menu_ex030408_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009af6;
  bStack_7 = DAT_00009af6;
  if (DAT_00009af6 == 0) {
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
                   + (uint)bStack_7 * 0x15 + 0x155d);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030501_draw @ fffcca66 (128 bytes)

/* Menu item ex030501 SSB/CW DIAL STEP: on_draw (#74) */

void menu_ex030501_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009af9;
  bStack_7 = DAT_00009af9;
  if (DAT_00009af9 == 2) {
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
                   + (uint)bStack_7 * 0x15 + 0x1587);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030502_draw @ fffccae6 (128 bytes)

/* Menu item ex030502 RTTY/PSK DIAL STEP: on_draw (#74) */

void menu_ex030502_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_7;
  
  bVar1 = DAT_00009afa;
  bStack_7 = DAT_00009afa;
  if (DAT_00009afa == 1) {
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
                   + (uint)bStack_7 * 0x15 + 0x1587);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}

