// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex010513_draw @ fffcae56 (21 bytes)

/* Menu item ex010513 RPTT SELECT: on_draw (#74) */

void menu_ex010513_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca2a1(param_1,DAT_00009a8a,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010514_draw @ fffcae6b (21 bytes)

/* Menu item ex010514 NAR WIDTH: on_draw (#74) */

void menu_ex010514_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcabc2(param_1,DAT_00009a8b,5,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010515_draw @ fffcae80 (125 bytes)

/* Menu item ex010515 MARK FREQUENCY: on_draw (#74) */

void menu_ex010515_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009a8c;
  local_5 = DAT_00009a8c;
  if (DAT_00009a8c == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xc42);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex010516_draw @ fffcaefd (125 bytes)

/* Menu item ex010516 SHIFT FREQUENCY: on_draw (#74) */

void menu_ex010516_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009a8d;
  local_5 = DAT_00009a8d;
  if (DAT_00009a8d == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xc6c);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex010517_draw @ fffcaf7a (125 bytes)

/* Menu item ex010517 POLARITY TX: on_draw (#74) */

void menu_ex010517_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009a8e;
  local_5 = DAT_00009a8e;
  if (DAT_00009a8e == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xcc0);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020101_draw @ fffcaff7 (24 bytes)

/* Menu item ex020101 AF TREBLE GAIN: on_draw (#74) */

void menu_ex020101_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a91);
  return;
}


// ===== menu_ex020102_draw @ fffcb00f (24 bytes)

/* Menu item ex020102 AF MIDDLE TONE GAIN: on_draw (#74) */

void menu_ex020102_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a92);
  return;
}


// ===== menu_ex020103_draw @ fffcb027 (24 bytes)

/* Menu item ex020103 AF BASS GAIN: on_draw (#74) */

void menu_ex020103_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a93);
  return;
}


// ===== menu_ex020104_draw @ fffcb03f (22 bytes)

/* Menu item ex020104 AGC FAST DELAY: on_draw (#74) */

void menu_ex020104_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a94,0xa0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020105_draw @ fffcb055 (23 bytes)

/* Menu item ex020105 AGC MID DELAY: on_draw (#74) */

void menu_ex020105_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a95,500,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020106_draw @ fffcb06c (23 bytes)

/* Menu item ex020106 AGC SLOW DELAY: on_draw (#74) */

void menu_ex020106_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a96,0x5dc,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020107_draw @ fffcb083 (21 bytes)

/* Menu item ex020107 LCUT FREQ: on_draw (#74) */

void menu_ex020107_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9cee(param_1,DAT_00009a97,4,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020108_draw @ fffcb098 (21 bytes)

/* Menu item ex020108 LCUT SLOPE: on_draw (#74) */

void menu_ex020108_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9d9a(param_1,DAT_00009a98,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020109_draw @ fffcb0ad (21 bytes)

/* Menu item ex020109 HCUT FREQ: on_draw (#74) */

void menu_ex020109_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9e27(param_1,DAT_00009a99,0xb,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020110_draw @ fffcb0c2 (21 bytes)

/* Menu item ex020110 HCUT SLOPE: on_draw (#74) */

void menu_ex020110_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9ed4(param_1,DAT_00009a9a,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020111_draw @ fffcb0d7 (22 bytes)

/* Menu item ex020111 USB OUT LEVEL: on_draw (#74) */

void menu_ex020111_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a9b,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020112_draw @ fffcb0ed (22 bytes)

/* Menu item ex020112 REAR OUT LEVEL: on_draw (#74) */

void menu_ex020112_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a9c,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020113_draw @ fffcb103 (21 bytes)

/* Menu item ex020113 RPTT SELECT: on_draw (#74) */

void menu_ex020113_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca2a1(param_1,DAT_00009a9d,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020114_draw @ fffcb118 (21 bytes)

/* Menu item ex020114 NAR WIDTH: on_draw (#74) */

void menu_ex020114_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcabc2(param_1,DAT_00009a9e,4,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020115_draw @ fffcb12d (21 bytes)

/* Menu item ex020115 PC KEYING: on_draw (#74) */

void menu_ex020115_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca2a1(param_1,DAT_00009a9f,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020116_draw @ fffcb142 (125 bytes)

/* Menu item ex020116 CW BK-IN TYPE: on_draw (#74) */

void menu_ex020116_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009aa0;
  local_5 = DAT_00009aa0;
  if (DAT_00009aa0 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xcea);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020117_draw @ fffcb1bf (125 bytes)

/* Menu item ex020117 CW WAVE SHAPE: on_draw (#74) */

void menu_ex020117_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009aa1;
  local_5 = DAT_00009aa1;
  if (DAT_00009aa1 == 2) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xd14);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020118_draw @ fffcb23c (125 bytes)

/* Menu item ex020118 CW FREQ DISPLAY: on_draw (#74) */

void menu_ex020118_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009aa2;
  local_5 = DAT_00009aa2;
  if (DAT_00009aa2 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 0xc;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xd53);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020119_draw @ fffcb2b9 (125 bytes)

/* Menu item ex020119 QSK DELAY TIME: on_draw (#74) */

void menu_ex020119_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009aa3;
  local_5 = DAT_00009aa3;
  if (DAT_00009aa3 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xd7d);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020120_draw @ fffcb336 (21 bytes)

/* Menu item ex020120 CW INDICATOR: on_draw (#74) */

void menu_ex020120_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb34b(param_1,DAT_00009aa4,1,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcb34b @ fffcb34b (119 bytes)

void FUN_fffcb34b(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 3;
  param_1[2] = 0;
  local_5 = param_2;
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xdd1);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex020201_draw @ fffcb3c2 (125 bytes)

/* Menu item ex020201 KEYER TYPE: on_draw (#74) */

void menu_ex020201_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009aa7;
  local_5 = DAT_00009aa7;
  if (DAT_00009aa7 == 3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 8;
  param_1[2] = 0;
  if (5 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xdfb);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020202_draw @ fffcb43f (125 bytes)

/* Menu item ex020202 KEYER DOT/DASH: on_draw (#74) */

void menu_ex020202_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009aa8;
  local_5 = DAT_00009aa8;
  if (DAT_00009aa8 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xe79);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020203_draw @ fffcb4bc (190 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcb538) */
/* WARNING: Removing unreachable block (ram,0xfffcb560) */
/* Menu item ex020203 CW WEIGHT: on_draw (#74) */

void menu_ex020203_draw(byte *param_1)

{
  char cVar1;
  
  cVar1 = DAT_00009aa9;
  if (DAT_00009aa9 == '\x05') {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  param_1[0x28] = 0x20;
  param_1[0x29] = 0x20;
  param_1[0x2a] = 0x20;
  param_1[0x2b] = 0x20;
  param_1[0x24] = 0x20;
  param_1[0x25] = 0x20;
  param_1[0x26] = 0x20;
  param_1[0x27] = 0x20;
  param_1[0x20] = 0x20;
  param_1[0x21] = 0x20;
  param_1[0x22] = 0x20;
  param_1[0x23] = 0x20;
  param_1[0x1c] = 0x20;
  param_1[0x1d] = 0x20;
  param_1[0x1e] = 0x20;
  param_1[0x1f] = 0x20;
  param_1[0x18] = 0x20;
  param_1[0x19] = 0x20;
  param_1[0x1a] = 0x20;
  param_1[0x1b] = 0x20;
  param_1[0x2c] = 0x20;
  param_1[0x18] = (byte)(cVar1 + 0x19U) / 10 | 0x30;
  param_1[0x19] = 0x2e;
  param_1[0x1a] = (byte)(cVar1 + 0x19U) % 10 | 0x30;
  return;
}


// ===== menu_ex020204_draw @ fffcb57a (125 bytes)

/* Menu item ex020204 NUMBER STYLE: on_draw (#74) */

void menu_ex020204_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009aaa;
  local_5 = DAT_00009aaa;
  if (DAT_00009aaa == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (6 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xea3);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020205_draw @ fffcb5f7 (102 bytes)

/* Menu item ex020205 CONTEST NUMBER: on_draw (#74) */

void menu_ex020205_draw(byte *param_1)

{
  short sVar1;
  
  sVar1 = FUN_fffba30c();
  if (sVar1 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  FUN_fff9c843(sVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex020206_draw @ fffcb65d (21 bytes)

/* Menu item ex020206 CW MEMORY 1: on_draw (#74) */

void menu_ex020206_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb672(param_1,DAT_00009aad,0,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcb672 @ fffcb672 (119 bytes)

void FUN_fffcb672(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 7;
  param_1[2] = 0;
  local_5 = param_2;
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xf36);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex020207_draw @ fffcb6e9 (21 bytes)

/* Menu item ex020207 CW MEMORY 2: on_draw (#74) */

void menu_ex020207_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb672(param_1,DAT_00009aae,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020208_draw @ fffcb6fe (21 bytes)

/* Menu item ex020208 CW MEMORY 3: on_draw (#74) */

void menu_ex020208_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb672(param_1,DAT_00009aaf,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020209_draw @ fffcb713 (21 bytes)

/* Menu item ex020209 CW MEMORY 4: on_draw (#74) */

void menu_ex020209_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb672(param_1,DAT_00009ab0,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020210_draw @ fffcb728 (21 bytes)

/* Menu item ex020210 CW MEMORY 5: on_draw (#74) */

void menu_ex020210_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb672(param_1,DAT_00009ab1,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020211_draw @ fffcb73d (124 bytes)

/* Menu item ex020211 REPEAT INTERVAL: on_draw (#74) */

void menu_ex020211_draw(byte *param_1)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = DAT_00009ab2;
  if (DAT_00009ab2 == '\x05') {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  bVar2 = FUN_fff9c6f0(cVar1,param_1 + 0x18);
  param_1 = param_1 + bVar2 + 0x18;
  param_1[2] = 99;
  param_1[0] = 0x73;
  param_1[1] = 0x65;
  return;
}


// ===== menu_ex030101_draw @ fffcb7b9 (108 bytes)

/* Menu item ex030101 BEEP LEVEL: on_draw (#74) */

void menu_ex030101_draw(byte *param_1)

{
  char cVar1;
  
  cVar1 = DAT_00009ab5;
  if (DAT_00009ab5 == '\x14') {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c6f0(cVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex030102_draw @ fffcb825 (128 bytes)

/* Menu item ex030102 RF/SQL VR: on_draw (#74) */

void menu_ex030102_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = DAT_00009ab6;
  local_7 = DAT_00009ab6;
  if (DAT_00009ab6 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 0xc;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0xf60);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030103_draw @ fffcb8a5 (128 bytes)

/* Menu item ex030103 TUN/LIN PORT SELECT: on_draw (#74) */

void menu_ex030103_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = DAT_00009ab7;
  local_7 = DAT_00009ab7;
  if (DAT_00009ab7 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 9;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 3999);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030104_draw @ fffcb925 (128 bytes)

/* Menu item ex030104 TUNER TYPE SELECT: on_draw (#74) */

void menu_ex030104_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = DAT_00009ab8;
  local_7 = DAT_00009ab8;
  if (DAT_00009ab8 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 9;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0xff3);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030105_draw @ fffcb9a5 (21 bytes)

/* Menu item ex030105 CAT-1 RATE: on_draw (#74) */

void menu_ex030105_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb9ba(param_1,DAT_00009ab9,3,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcb9ba @ fffcb9ba (119 bytes)

void FUN_fffcb9ba(byte *param_1,byte param_2,byte param_3)

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
  if (4 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x1047);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030106_draw @ fffcba31 (21 bytes)

/* Menu item ex030106 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex030106_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcba46(param_1,DAT_00009aba,0,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcba46 @ fffcba46 (119 bytes)

void FUN_fffcba46(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 8;
  param_1[2] = 0;
  local_5 = param_2;
  if (3 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x10b0);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030107_draw @ fffcbabd (128 bytes)

/* Menu item ex030107 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex030107_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = DAT_00009abb;
  local_7 = DAT_00009abb;
  if (DAT_00009abb == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (int)(&DAT_00002328 + (uint)local_7 * 0x15));
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030108_draw @ fffcbb3d (21 bytes)

/* Menu item ex030108 CAT-2 RATE: on_draw (#74) */

void menu_ex030108_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb9ba(param_1,DAT_00009abc,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030109_draw @ fffcbb52 (21 bytes)

/* Menu item ex030109 CAT-2 TIME OUT TIMER: on_draw (#74) */

void menu_ex030109_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcba46(param_1,DAT_00009abd,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030110_draw @ fffcbb67 (21 bytes)

/* Menu item ex030110 CAT-3 RATE: on_draw (#74) */

void menu_ex030110_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb9ba(param_1,DAT_00009abe,3,param_4,param_5,param_1);
  return;
}

