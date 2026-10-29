// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc9cee @ fffc9cee (151 bytes)

void FUN_fffc9cee(byte *param_1,byte param_2,byte param_3)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = (ushort)param_2;
  if (uVar2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (uVar2 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  bVar1 = FUN_fff9c843(uVar2 * 0x32 + 0x32,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== menu_ex010108_draw @ fffc9d85 (21 bytes)

/* Menu item ex010108 LCUT SLOPE: on_draw (#74) */

void menu_ex010108_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9d9a(param_1,DAT_00009a31,0,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffc9d9a @ fffc9d9a (119 bytes)

void FUN_fffc9d9a(byte *param_1,byte param_2,byte param_3)

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
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x1d7);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010109_draw @ fffc9e11 (22 bytes)

/* Menu item ex010109 HCUT FREQ: on_draw (#74) */

void menu_ex010109_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9e27(param_1,DAT_00009a32,0x2f,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffc9e27 @ fffc9e27 (152 bytes)

void FUN_fffc9e27(byte *param_1,byte param_2,byte param_3)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = (ushort)param_2;
  if (uVar2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (uVar2 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  bVar1 = FUN_fff9c843(uVar2 * 0x32 + 0x28a,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== menu_ex010110_draw @ fffc9ebf (21 bytes)

/* Menu item ex010110 HCUT SLOPE: on_draw (#74) */

void menu_ex010110_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9ed4(param_1,DAT_00009a33,0,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffc9ed4 @ fffc9ed4 (119 bytes)

void FUN_fffc9ed4(byte *param_1,byte param_2,byte param_3)

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
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x1d7);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010111_draw @ fffc9f4b (22 bytes)

/* Menu item ex010111 USB OUT LEVEL: on_draw (#74) */

void menu_ex010111_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a34,0x32,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffc9f61 @ fffc9f61 (98 bytes)

void FUN_fffc9f61(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c6f0(param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex010112_draw @ fffc9fc3 (22 bytes)

/* Menu item ex010112 REAR OUT LEVEL: on_draw (#74) */

void menu_ex010112_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a35,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010113_draw @ fffc9fd9 (148 bytes)

/* Menu item ex010113 TX BPF SEL: on_draw (#74) */

void menu_ex010113_draw(undefined4 param_1)

{
  bool bVar1;
  ushort uVar2;
  char cStack_5;
  
  cStack_5 = DAT_00009a36;
  if (DAT_00009a36 == '\x06') {
    uVar2 = dest_code_get();
    if ((uVar2 == 0x315b) || (uVar2 == 0x50e2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (uVar2 == 0x1cb9)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_00004760 == '\0') {
        DAT_00009a36 = '\x01';
        cStack_5 = '\x01';
      }
      else {
        cStack_5 = '\x05';
      }
    }
    else {
      DAT_00009a36 = '\x01';
      cStack_5 = '\x01';
    }
  }
  FUN_fffca06d(param_1,cStack_5,1);
  return;
}


// ===== FUN_fffca06d @ fffca06d (163 bytes)

void FUN_fffca06d(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 10;
  param_1[2] = 0;
  local_5 = param_2;
  if (DAT_00012272 == '\0') {
    if (5 < param_2) {
      local_5 = 0;
    }
    pbVar1 = (byte *)(
                     "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                     + (uint)local_5 * 0x15 + 0x201);
    param_1 = param_1 + 0x18;
    for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *pbVar1;
      param_1 = param_1 + 1;
      pbVar1 = pbVar1 + 1;
    }
    return;
  }
  if (4 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x27f);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010114_draw @ fffca110 (21 bytes)

/* Menu item ex010114 MOD SOURCE: on_draw (#74) */

void menu_ex010114_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca125(param_1,DAT_00009a37,3,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffca125 @ fffca125 (119 bytes)

void FUN_fffca125(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 4;
  param_1[2] = 0;
  local_5 = param_2;
  if (3 < param_2) {
    local_5 = 3;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x2e8);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010115_draw @ fffca19c (22 bytes)

/* Menu item ex010115 USB MOD GAIN: on_draw (#74) */

void menu_ex010115_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca1b2(param_1,DAT_00009a38,0x32,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffca1b2 @ fffca1b2 (98 bytes)

void FUN_fffca1b2(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c6f0(param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex010116_draw @ fffca214 (22 bytes)

/* Menu item ex010116 REAR MOD GAIN: on_draw (#74) */

void menu_ex010116_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca22a(param_1,DAT_00009a39,0x32,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffca22a @ fffca22a (98 bytes)

void FUN_fffca22a(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c6f0(param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex010117_draw @ fffca28c (21 bytes)

/* Menu item ex010117 RPTT SELECT: on_draw (#74) */

void menu_ex010117_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca2a1(param_1,DAT_00009a3a,0,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffca2a1 @ fffca2a1 (119 bytes)

void FUN_fffca2a1(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 4;
  param_1[2] = 0;
  local_5 = param_2;
  if (3 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x33c);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010118_draw @ fffca318 (126 bytes)

/* Menu item ex010118 NAR WIDTH: on_draw (#74) */

void menu_ex010118_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bStack_5;
  
  bVar1 = DAT_00009a3b;
  bStack_5 = DAT_00009a3b;
  if (DAT_00009a3b == 6) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (0x16 < bVar1) {
    bStack_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_5 * 0x15 + 0x390);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex010119_draw @ fffca396 (21 bytes)

/* Menu item ex010119 CW AUTO MODE: on_draw (#74) */

void menu_ex010119_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca3ab(param_1,DAT_00009a3c,0,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffca3ab @ fffca3ab (119 bytes)

void FUN_fffca3ab(byte *param_1,byte param_2,byte param_3)

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
  if (2 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x72c);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010201_draw @ fffca422 (24 bytes)

/* Menu item ex010201 AF TREBLE GAIN: on_draw (#74) */

void menu_ex010201_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a3f);
  return;
}


// ===== menu_ex010202_draw @ fffca43a (24 bytes)

/* Menu item ex010202 AF MIDDLE TONE GAIN: on_draw (#74) */

void menu_ex010202_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a40);
  return;
}


// ===== menu_ex010203_draw @ fffca452 (24 bytes)

/* Menu item ex010203 AF BASS GAIN: on_draw (#74) */

void menu_ex010203_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a41);
  return;
}


// ===== menu_ex010204_draw @ fffca46a (23 bytes)

/* Menu item ex010204 AGC FAST DELAY: on_draw (#74) */

void menu_ex010204_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a42,1000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010205_draw @ fffca481 (23 bytes)

/* Menu item ex010205 AGC MID DELAY: on_draw (#74) */

void menu_ex010205_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a43,2000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010206_draw @ fffca498 (23 bytes)

/* Menu item ex010206 AGC SLOW DELAY: on_draw (#74) */

void menu_ex010206_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a44,4000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010207_draw @ fffca4af (21 bytes)

/* Menu item ex010207 LCUT FREQ: on_draw (#74) */

void menu_ex010207_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9cee(param_1,DAT_00009a45,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010208_draw @ fffca4c4 (21 bytes)

/* Menu item ex010208 LCUT SLOPE: on_draw (#74) */

void menu_ex010208_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9d9a(param_1,DAT_00009a46,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010209_draw @ fffca4d9 (21 bytes)

/* Menu item ex010209 HCUT FREQ: on_draw (#74) */

void menu_ex010209_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9e27(param_1,DAT_00009a47,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010210_draw @ fffca4ee (21 bytes)

/* Menu item ex010210 HCUT SLOPE: on_draw (#74) */

void menu_ex010210_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9ed4(param_1,DAT_00009a48,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010211_draw @ fffca503 (22 bytes)

/* Menu item ex010211 USB OUT LEVEL: on_draw (#74) */

void menu_ex010211_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a49,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010212_draw @ fffca519 (22 bytes)

/* Menu item ex010212 REAR OUT LEVEL: on_draw (#74) */

void menu_ex010212_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9f61(param_1,DAT_00009a4a,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010213_draw @ fffca52f (21 bytes)

/* Menu item ex010213 TX BPF SEL: on_draw (#74) */

void menu_ex010213_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca06d(param_1,DAT_00009a4b,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010214_draw @ fffca544 (21 bytes)

/* Menu item ex010214 MOD SOURCE: on_draw (#74) */

void menu_ex010214_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca125(param_1,DAT_00009a4c,3,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010215_draw @ fffca559 (22 bytes)

/* Menu item ex010215 USB MOD GAIN: on_draw (#74) */

void menu_ex010215_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca1b2(param_1,DAT_00009a4d,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010216_draw @ fffca56f (22 bytes)

/* Menu item ex010216 REAR MOD GAIN: on_draw (#74) */

void menu_ex010216_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca22a(param_1,DAT_00009a4e,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010217_draw @ fffca585 (21 bytes)

/* Menu item ex010217 RPTT SELECT: on_draw (#74) */

void menu_ex010217_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffca2a1(param_1,DAT_00009a4f,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010301_draw @ fffca59a (24 bytes)

/* Menu item ex010301 AF TREBLE GAIN: on_draw (#74) */

void menu_ex010301_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a52);
  return;
}


// ===== menu_ex010302_draw @ fffca5b2 (24 bytes)

/* Menu item ex010302 AF MIDDLE TONE GAIN: on_draw (#74) */

void menu_ex010302_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a53);
  return;
}


// ===== menu_ex010303_draw @ fffca5ca (24 bytes)

/* Menu item ex010303 AF BASS GAIN: on_draw (#74) */

void menu_ex010303_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a54);
  return;
}


// ===== menu_ex010304_draw @ fffca5e2 (22 bytes)

/* Menu item ex010304 AGC FAST DELAY: on_draw (#74) */

void menu_ex010304_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a55,0xa0,param_4,param_5,param_1);
  return;
}


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

