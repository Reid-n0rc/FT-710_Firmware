// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex060505_draw @ fffd20fb (13 bytes)

/* Menu item ex060505 AGC FAST DELAY: on_draw (#74) */

void menu_ex060505_draw(void)

{
  FUN_fffd2108(5);
  return;
}


// ===== FUN_fffd2108 @ fffd2108 (240 bytes)

void FUN_fffd2108(byte param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = DAT_00009bb9;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b5c;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b7b;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009b9a;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b3d;
  }
  if (local_b == 7) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xe;
  param_2[2] = 0;
  bVar2 = FUN_fff9c843((ushort)local_b * 0x14 + 0x14,param_2 + 0x18);
  param_2 = param_2 + bVar2 + 0x18;
  param_2[0] = 0x6d;
  param_2[1] = 0x73;
  param_2[2] = 0x65;
  param_2[3] = 99;
  return;
}


// ===== menu_ex060106_draw @ fffd21f8 (13 bytes)

/* Menu item ex060106 AGC MID DELAY: on_draw (#74) */

void menu_ex060106_draw(void)

{
  FUN_fffd2239(1);
  return;
}


// ===== menu_ex060206_draw @ fffd2205 (13 bytes)

/* Menu item ex060206 AGC MID DELAY: on_draw (#74) */

void menu_ex060206_draw(void)

{
  FUN_fffd2239(2);
  return;
}


// ===== menu_ex060306_draw @ fffd2212 (13 bytes)

/* Menu item ex060306 AGC MID DELAY: on_draw (#74) */

void menu_ex060306_draw(void)

{
  FUN_fffd2239(3);
  return;
}


// ===== menu_ex060406_draw @ fffd221f (13 bytes)

/* Menu item ex060406 AGC MID DELAY: on_draw (#74) */

void menu_ex060406_draw(void)

{
  FUN_fffd2239(4);
  return;
}


// ===== menu_ex060506_draw @ fffd222c (13 bytes)

/* Menu item ex060506 AGC MID DELAY: on_draw (#74) */

void menu_ex060506_draw(void)

{
  FUN_fffd2239(5);
  return;
}


// ===== FUN_fffd2239 @ fffd2239 (241 bytes)

void FUN_fffd2239(byte param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = DAT_00009bba;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b5d;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b7c;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009b9b;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b3e;
  }
  if (local_b == 0x18) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xd;
  param_2[2] = 0;
  bVar2 = FUN_fff9c843((ushort)local_b * 0x14 + 0x14,param_2 + 0x18);
  param_2 = param_2 + bVar2 + 0x18;
  param_2[0] = 0x6d;
  param_2[1] = 0x73;
  param_2[2] = 0x65;
  param_2[3] = 99;
  return;
}


// ===== menu_ex060107_draw @ fffd232a (13 bytes)

/* Menu item ex060107 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060107_draw(void)

{
  FUN_fffd236b(1);
  return;
}


// ===== menu_ex060207_draw @ fffd2337 (13 bytes)

/* Menu item ex060207 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060207_draw(void)

{
  FUN_fffd236b(2);
  return;
}


// ===== menu_ex060307_draw @ fffd2344 (13 bytes)

/* Menu item ex060307 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060307_draw(void)

{
  FUN_fffd236b(3);
  return;
}


// ===== menu_ex060407_draw @ fffd2351 (13 bytes)

/* Menu item ex060407 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060407_draw(void)

{
  FUN_fffd236b(4);
  return;
}


// ===== menu_ex060507_draw @ fffd235e (13 bytes)

/* Menu item ex060507 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060507_draw(void)

{
  FUN_fffd236b(5);
  return;
}


// ===== FUN_fffd236b @ fffd236b (241 bytes)

void FUN_fffd236b(byte param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = DAT_00009bbb;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b5e;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b7d;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009b9c;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b3f;
  }
  if (local_b == 0x4a) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xe;
  param_2[2] = 0;
  bVar2 = FUN_fff9c843((ushort)local_b * 0x14 + 0x14,param_2 + 0x18);
  param_2 = param_2 + bVar2 + 0x18;
  param_2[0] = 0x6d;
  param_2[1] = 0x73;
  param_2[2] = 0x65;
  param_2[3] = 99;
  return;
}


// ===== menu_ex060108_draw @ fffd245c (13 bytes)

/* Menu item ex060108 LCUT FREQ: on_draw (#74) */

void menu_ex060108_draw(void)

{
  FUN_fffd249d(1);
  return;
}


// ===== menu_ex060208_draw @ fffd2469 (13 bytes)

/* Menu item ex060208 LCUT FREQ: on_draw (#74) */

void menu_ex060208_draw(void)

{
  FUN_fffd249d(2);
  return;
}


// ===== menu_ex060308_draw @ fffd2476 (13 bytes)

/* Menu item ex060308 LCUT FREQ: on_draw (#74) */

void menu_ex060308_draw(void)

{
  FUN_fffd249d(3);
  return;
}


// ===== menu_ex060408_draw @ fffd2483 (13 bytes)

/* Menu item ex060408 LCUT FREQ: on_draw (#74) */

void menu_ex060408_draw(void)

{
  FUN_fffd249d(4);
  return;
}


// ===== menu_ex060508_draw @ fffd2490 (13 bytes)

/* Menu item ex060508 LCUT FREQ: on_draw (#74) */

void menu_ex060508_draw(void)

{
  FUN_fffd249d(5);
  return;
}


// ===== FUN_fffd249d @ fffd249d (235 bytes)

void FUN_fffd249d(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = DAT_00009bbc;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b5f;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b7e;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009b9d;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b40;
  }
  if (local_b == 1) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 9;
  param_2[2] = 0;
  if (0x13 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x1b87);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060109_draw @ fffd2588 (13 bytes)

/* Menu item ex060109 LCUT SLOPE: on_draw (#74) */

void menu_ex060109_draw(void)

{
  FUN_fffd25c9(1);
  return;
}


// ===== menu_ex060209_draw @ fffd2595 (13 bytes)

/* Menu item ex060209 LCUT SLOPE: on_draw (#74) */

void menu_ex060209_draw(void)

{
  FUN_fffd25c9(2);
  return;
}


// ===== menu_ex060309_draw @ fffd25a2 (13 bytes)

/* Menu item ex060309 LCUT SLOPE: on_draw (#74) */

void menu_ex060309_draw(void)

{
  FUN_fffd25c9(3);
  return;
}


// ===== menu_ex060409_draw @ fffd25af (13 bytes)

/* Menu item ex060409 LCUT SLOPE: on_draw (#74) */

void menu_ex060409_draw(void)

{
  FUN_fffd25c9(4);
  return;
}


// ===== menu_ex060509_draw @ fffd25bc (13 bytes)

/* Menu item ex060509 LCUT SLOPE: on_draw (#74) */

void menu_ex060509_draw(void)

{
  FUN_fffd25c9(5);
  return;
}


// ===== FUN_fffd25c9 @ fffd25c9 (234 bytes)

void FUN_fffd25c9(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = DAT_00009bbd;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b60;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b7f;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009b9e;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b41;
  }
  if (local_b == 1) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 10;
  param_2[2] = 0;
  if (1 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x1d7);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060110_draw @ fffd26b3 (13 bytes)

/* Menu item ex060110 HCUT FREQ: on_draw (#74) */

void menu_ex060110_draw(void)

{
  FUN_fffd26f4(1);
  return;
}


// ===== menu_ex060210_draw @ fffd26c0 (13 bytes)

/* Menu item ex060210 HCUT FREQ: on_draw (#74) */

void menu_ex060210_draw(void)

{
  FUN_fffd26f4(2);
  return;
}


// ===== menu_ex060310_draw @ fffd26cd (13 bytes)

/* Menu item ex060310 HCUT FREQ: on_draw (#74) */

void menu_ex060310_draw(void)

{
  FUN_fffd26f4(3);
  return;
}


// ===== menu_ex060410_draw @ fffd26da (13 bytes)

/* Menu item ex060410 HCUT FREQ: on_draw (#74) */

void menu_ex060410_draw(void)

{
  FUN_fffd26f4(4);
  return;
}


// ===== menu_ex060510_draw @ fffd26e7 (13 bytes)

/* Menu item ex060510 HCUT FREQ: on_draw (#74) */

void menu_ex060510_draw(void)

{
  FUN_fffd26f4(5);
  return;
}


// ===== FUN_fffd26f4 @ fffd26f4 (236 bytes)

void FUN_fffd26f4(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = DAT_00009bbe;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b61;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b80;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009b9f;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b42;
  }
  if (local_b == 0x33) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 9;
  param_2[2] = 0;
  if (0x43 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x1d2b);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060111_draw @ fffd27e0 (13 bytes)

/* Menu item ex060111 HCUT SLOPE: on_draw (#74) */

void menu_ex060111_draw(void)

{
  FUN_fffd2821(1);
  return;
}


// ===== menu_ex060211_draw @ fffd27ed (13 bytes)

/* Menu item ex060211 HCUT SLOPE: on_draw (#74) */

void menu_ex060211_draw(void)

{
  FUN_fffd2821(2);
  return;
}


// ===== menu_ex060311_draw @ fffd27fa (13 bytes)

/* Menu item ex060311 HCUT SLOPE: on_draw (#74) */

void menu_ex060311_draw(void)

{
  FUN_fffd2821(3);
  return;
}


// ===== menu_ex060411_draw @ fffd2807 (13 bytes)

/* Menu item ex060411 HCUT SLOPE: on_draw (#74) */

void menu_ex060411_draw(void)

{
  FUN_fffd2821(4);
  return;
}


// ===== menu_ex060511_draw @ fffd2814 (13 bytes)

/* Menu item ex060511 HCUT SLOPE: on_draw (#74) */

void menu_ex060511_draw(void)

{
  FUN_fffd2821(5);
  return;
}


// ===== FUN_fffd2821 @ fffd2821 (234 bytes)

void FUN_fffd2821(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = DAT_00009bbf;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b62;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b81;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba0;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b43;
  }
  if (local_b == 1) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 10;
  param_2[2] = 0;
  if (1 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x1d7);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060112_draw @ fffd290b (13 bytes)

/* Menu item ex060112 USB OUT LEVEL: on_draw (#74) */

void menu_ex060112_draw(void)

{
  FUN_fffd294c(1);
  return;
}


// ===== menu_ex060212_draw @ fffd2918 (13 bytes)

/* Menu item ex060212 USB OUT LEVEL: on_draw (#74) */

void menu_ex060212_draw(void)

{
  FUN_fffd294c(2);
  return;
}


// ===== menu_ex060312_draw @ fffd2925 (13 bytes)

/* Menu item ex060312 USB OUT LEVEL: on_draw (#74) */

void menu_ex060312_draw(void)

{
  FUN_fffd294c(3);
  return;
}


// ===== menu_ex060412_draw @ fffd2932 (13 bytes)

/* Menu item ex060412 USB OUT LEVEL: on_draw (#74) */

void menu_ex060412_draw(void)

{
  FUN_fffd294c(4);
  return;
}


// ===== menu_ex060512_draw @ fffd293f (13 bytes)

/* Menu item ex060512 USB OUT LEVEL: on_draw (#74) */

void menu_ex060512_draw(void)

{
  FUN_fffd294c(5);
  return;
}


// ===== FUN_fffd294c @ fffd294c (214 bytes)

void FUN_fffd294c(byte param_1,byte *param_2)

{
  bool bVar1;
  char local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = DAT_00009bc0;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b63;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b82;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba1;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b44;
  }
  if (local_b == '2') {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xd;
  param_2[2] = 0;
  FUN_fff9c6f0(local_b,param_2 + 0x18);
  return;
}


// ===== menu_ex060113_draw @ fffd2a22 (13 bytes)

/* Menu item ex060113 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060113_draw(void)

{
  FUN_fffd2a63(1);
  return;
}


// ===== menu_ex060213_draw @ fffd2a2f (13 bytes)

/* Menu item ex060213 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060213_draw(void)

{
  FUN_fffd2a63(2);
  return;
}


// ===== menu_ex060313_draw @ fffd2a3c (13 bytes)

/* Menu item ex060313 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060313_draw(void)

{
  FUN_fffd2a63(3);
  return;
}


// ===== menu_ex060413_draw @ fffd2a49 (13 bytes)

/* Menu item ex060413 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060413_draw(void)

{
  FUN_fffd2a63(4);
  return;
}


// ===== menu_ex060513_draw @ fffd2a56 (13 bytes)

/* Menu item ex060513 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060513_draw(void)

{
  FUN_fffd2a63(5);
  return;
}


// ===== FUN_fffd2a63 @ fffd2a63 (214 bytes)

void FUN_fffd2a63(byte param_1,byte *param_2)

{
  bool bVar1;
  char local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = DAT_00009bc1;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b64;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b83;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba2;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b45;
  }
  if (local_b == '2') {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xe;
  param_2[2] = 0;
  FUN_fff9c6f0(local_b,param_2 + 0x18);
  return;
}

