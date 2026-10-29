// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex010305_draw @ fffca5f8 (23 bytes)

/* Menu item ex010305 AGC MID DELAY: on_draw (#74) */

void menu_ex010305_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a56,500,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010306_draw @ fffca60f (23 bytes)

/* Menu item ex010306 AGC SLOW DELAY: on_draw (#74) */

void menu_ex010306_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a57,0x5dc,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010307_draw @ fffca626 (21 bytes)

/* Menu item ex010307 LCUT FREQ: on_draw (#74) */

void menu_ex010307_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9cee(param_1,DAT_00009a58,5,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010308_draw @ fffca63b (21 bytes)

/* Menu item ex010308 LCUT SLOPE: on_draw (#74) */

void menu_ex010308_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9d9a(param_1,DAT_00009a59,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010309_draw @ fffca650 (22 bytes)

/* Menu item ex010309 HCUT FREQ: on_draw (#74) */

void menu_ex010309_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9e27(param_1,DAT_00009a5a,0x2f,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010310_draw @ fffca666 (21 bytes)

/* Menu item ex010310 HCUT SLOPE: on_draw (#74) */

void menu_ex010310_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9ed4(param_1,DAT_00009a5b,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010311_draw @ fffca67b (22 bytes)

/* Menu item ex010311 USB OUT LEVEL: on_draw (#74) */

void menu_ex010311_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a5c,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010312_draw @ fffca691 (22 bytes)

/* Menu item ex010312 REAR OUT LEVEL: on_draw (#74) */

void menu_ex010312_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a5d,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010313_draw @ fffca6a7 (21 bytes)

/* Menu item ex010313 MOD SOURCE: on_draw (#74) */

void menu_ex010313_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca125(param_1,DAT_00009a5e,3,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010314_draw @ fffca6bc (22 bytes)

/* Menu item ex010314 USB MOD GAIN: on_draw (#74) */

void menu_ex010314_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca1b2(param_1,DAT_00009a5f,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010315_draw @ fffca6d2 (22 bytes)

/* Menu item ex010315 REAR MOD GAIN: on_draw (#74) */

void menu_ex010315_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca22a(param_1,DAT_00009a60,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010316_draw @ fffca6e8 (21 bytes)

/* Menu item ex010316 RPTT SELECT: on_draw (#74) */

void menu_ex010316_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca2a1(param_1,DAT_00009a61,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010317_draw @ fffca6fd (160 bytes)

/* Menu item ex010317 RPT SHIFT: on_draw (#74) */

void menu_ex010317_draw(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (DAT_00009dbd == '\0') {
    local_5 = DAT_00009d0b;
  }
  else {
    local_5 = DAT_00009d65;
  }
  local_5 = local_5 >> 2 & 3;
  if (local_5 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < local_5) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x76b);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010318_draw @ fffca79d (132 bytes)

/* Menu item ex010318 RPT SHIFT(28MHz): on_draw (#74) */

void menu_ex010318_draw(byte *param_1)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = (ushort)DAT_00009a62;
  if (uVar2 == 10) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  bVar1 = FUN_fff9c843(uVar2 * 10,param_1 + 0x18);
  param_1 = param_1 + bVar1 + 0x18;
  param_1[2] = 0x7a;
  param_1[0] = 0x6b;
  param_1[1] = 0x48;
  return;
}


// ===== menu_ex010319_draw @ fffca821 (149 bytes)

/* WARNING: Removing unreachable block (ram,0xfffca836) */
/* Menu item ex010319 RPT SHIFT(50MHz): on_draw (#74) */

void menu_ex010319_draw(byte *param_1)

{
  byte bVar1;
  short sVar2;
  
  sVar2 = CONCAT11(DAT_00009a63,DAT_00009a64);
  if (sVar2 == 0x32) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  bVar1 = FUN_fff9c843(sVar2 * 10,param_1 + 0x18);
  param_1 = param_1 + bVar1 + 0x18;
  param_1[2] = 0x7a;
  param_1[0] = 0x6b;
  param_1[1] = 0x48;
  return;
}


// ===== menu_ex010320_draw @ fffca8b6 (160 bytes)

/* Menu item ex010320 ENC/DEC: on_draw (#74) */

void menu_ex010320_draw(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (DAT_00009dbd == '\0') {
    local_5 = DAT_00009d0c;
  }
  else {
    local_5 = DAT_00009d66;
  }
  local_5 = local_5 >> 3 & 7;
  if (local_5 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (2 < local_5) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x7aa);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010321_draw @ fffca956 (223 bytes)

/* Menu item ex010321 TONE FREQ: on_draw (#74) */

void menu_ex010321_draw(byte *param_1)

{
  bool bVar1;
  ushort uVar2;
  byte *pbVar3;
  int iVar4;
  byte local_5;
  
  if (DAT_00009dbd == '\0') {
    local_5 = DAT_00009d4f;
  }
  else {
    local_5 = DAT_00009da9;
  }
  uVar2 = dest_code_get();
  if ((uVar2 == 0x4380) || (uVar2 == 0x20b)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (uVar2 == 0x60e6)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (local_5 == 8) {
      *param_1 = *param_1 | 0x80;
    }
  }
  else if (local_5 == 0xc) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (0x31 < local_5) {
    local_5 = 0;
  }
  pbVar3 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x7e9);
  param_1 = param_1 + 0x18;
  for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
    *param_1 = *pbVar3;
    param_1 = param_1 + 1;
    pbVar3 = pbVar3 + 1;
  }
  return;
}


// ===== menu_ex010401_draw @ fffcaa35 (24 bytes)

/* Menu item ex010401 AF TREBLE GAIN: on_draw (#74) */

void menu_ex010401_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a67);
  return;
}


// ===== menu_ex010402_draw @ fffcaa4d (24 bytes)

/* Menu item ex010402 AF MIDDLE TONE GAIN: on_draw (#74) */

void menu_ex010402_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a68);
  return;
}


// ===== menu_ex010403_draw @ fffcaa65 (24 bytes)

/* Menu item ex010403 AF BASS GAIN: on_draw (#74) */

void menu_ex010403_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a69);
  return;
}


// ===== menu_ex010404_draw @ fffcaa7d (22 bytes)

/* Menu item ex010404 AGC FAST DELAY: on_draw (#74) */

void menu_ex010404_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a6a,0xa0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010405_draw @ fffcaa93 (23 bytes)

/* Menu item ex010405 AGC MID DELAY: on_draw (#74) */

void menu_ex010405_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a6b,500,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010406_draw @ fffcaaaa (23 bytes)

/* Menu item ex010406 AGC SLOW DELAY: on_draw (#74) */

void menu_ex010406_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a6c,0x5dc,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010407_draw @ fffcaac1 (21 bytes)

/* Menu item ex010407 LCUT FREQ: on_draw (#74) */

void menu_ex010407_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9cee(param_1,DAT_00009a6d,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010408_draw @ fffcaad6 (21 bytes)

/* Menu item ex010408 LCUT SLOPE: on_draw (#74) */

void menu_ex010408_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9d9a(param_1,DAT_00009a6e,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010409_draw @ fffcaaeb (22 bytes)

/* Menu item ex010409 HCUT FREQ: on_draw (#74) */

void menu_ex010409_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9e27(param_1,DAT_00009a6f,0x33,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010410_draw @ fffcab01 (21 bytes)

/* Menu item ex010410 HCUT SLOPE: on_draw (#74) */

void menu_ex010410_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9ed4(param_1,DAT_00009a70,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010411_draw @ fffcab16 (22 bytes)

/* Menu item ex010411 USB OUT LEVEL: on_draw (#74) */

void menu_ex010411_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a71,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010412_draw @ fffcab2c (22 bytes)

/* Menu item ex010412 REAR OUT LEVEL: on_draw (#74) */

void menu_ex010412_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a72,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010413_draw @ fffcab42 (21 bytes)

/* Menu item ex010413 TX BPF SEL: on_draw (#74) */

void menu_ex010413_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca06d(param_1,DAT_00009a73,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010414_draw @ fffcab57 (21 bytes)

/* Menu item ex010414 MOD SOURCE: on_draw (#74) */

void menu_ex010414_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca125(param_1,DAT_00009a74,3,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010415_draw @ fffcab6c (22 bytes)

/* Menu item ex010415 USB MOD GAIN: on_draw (#74) */

void menu_ex010415_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca1b2(param_1,DAT_00009a75,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010416_draw @ fffcab82 (22 bytes)

/* Menu item ex010416 REAR MOD GAIN: on_draw (#74) */

void menu_ex010416_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca22a(param_1,DAT_00009a76,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010417_draw @ fffcab98 (21 bytes)

/* Menu item ex010417 RPTT SELECT: on_draw (#74) */

void menu_ex010417_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca2a1(param_1,DAT_00009a77,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010418_draw @ fffcabad (21 bytes)

/* Menu item ex010418 NAR WIDTH: on_draw (#74) */

void menu_ex010418_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcabc2(param_1,DAT_00009a78,5,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcabc2 @ fffcabc2 (120 bytes)

void FUN_fffcabc2(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 6;
  param_1[2] = 0;
  local_5 = param_2;
  if (0x14 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x573);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010419_draw @ fffcac3a (125 bytes)

/* Menu item ex010419 PSK TONE: on_draw (#74) */

void menu_ex010419_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = DAT_00009a79;
  local_5 = DAT_00009a79;
  if (DAT_00009a79 == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xc03);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex010420_draw @ fffcacb7 (146 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcaccc) */
/* Menu item ex010420 DATA SHIFT (SSB): on_draw (#74) */

void menu_ex010420_draw(byte *param_1)

{
  byte bVar1;
  short sVar2;
  
  sVar2 = CONCAT11(DAT_00009a7a,DAT_00009a7b);
  if (sVar2 == 0x96) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  bVar1 = FUN_fff9c843(sVar2 * 10,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== menu_ex010501_draw @ fffcad49 (24 bytes)

/* Menu item ex010501 AF TREBLE GAIN: on_draw (#74) */

void menu_ex010501_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a7e);
  return;
}


// ===== menu_ex010502_draw @ fffcad61 (24 bytes)

/* Menu item ex010502 AF MIDDLE TONE GAIN: on_draw (#74) */

void menu_ex010502_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a7f);
  return;
}


// ===== menu_ex010503_draw @ fffcad79 (24 bytes)

/* Menu item ex010503 AF BASS GAIN: on_draw (#74) */

void menu_ex010503_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a80);
  return;
}


// ===== menu_ex010504_draw @ fffcad91 (22 bytes)

/* Menu item ex010504 AGC FAST DELAY: on_draw (#74) */

void menu_ex010504_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a81,0xa0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010505_draw @ fffcada7 (23 bytes)

/* Menu item ex010505 AGC MID DELAY: on_draw (#74) */

void menu_ex010505_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a82,500,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010506_draw @ fffcadbe (23 bytes)

/* Menu item ex010506 AGC SLOW DELAY: on_draw (#74) */

void menu_ex010506_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a83,0x5dc,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010507_draw @ fffcadd5 (21 bytes)

/* Menu item ex010507 LCUT FREQ: on_draw (#74) */

void menu_ex010507_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9cee(param_1,DAT_00009a84,5,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010508_draw @ fffcadea (21 bytes)

/* Menu item ex010508 LCUT SLOPE: on_draw (#74) */

void menu_ex010508_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9d9a(param_1,DAT_00009a85,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010509_draw @ fffcadff (22 bytes)

/* Menu item ex010509 HCUT FREQ: on_draw (#74) */

void menu_ex010509_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9e27(param_1,DAT_00009a86,0x2f,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010510_draw @ fffcae15 (21 bytes)

/* Menu item ex010510 HCUT SLOPE: on_draw (#74) */

void menu_ex010510_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9ed4(param_1,DAT_00009a87,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010511_draw @ fffcae2a (22 bytes)

/* Menu item ex010511 USB OUT LEVEL: on_draw (#74) */

void menu_ex010511_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a88,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010512_draw @ fffcae40 (22 bytes)

/* Menu item ex010512 REAR OUT LEVEL: on_draw (#74) */

void menu_ex010512_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a89,0x32,param_4,param_5,param_1);
  return;
}

