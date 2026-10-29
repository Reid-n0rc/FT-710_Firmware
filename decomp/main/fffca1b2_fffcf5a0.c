// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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


// ===== FUN_fffcdd0f @ fffcdd0f (111 bytes)

undefined1 FUN_fffcdd0f(void)

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
    else if ((int)(uint)(byte)pcVar2[1] < (int)(bVar1 - 5)) {
      pcVar2[1] = pcVar2[1] + '\x01';
      if (*pcVar2 != '\0') {
        *pcVar2 = *pcVar2 + -1;
      }
      uStack_9 = FUN_fffcdce3();
    }
    else {
      uStack_9 = 0;
    }
  }
  return uStack_9;
}


// ===== menu_ui_step @ fffcdd7e (93 bytes)

/* Front panel: dial step on the selected row (timer 3000, sets 0x20F0F, menu_call_step) */

void menu_ui_step(void)

{
  char *pcVar1;
  undefined1 uStack_4;
  byte bStack_3;
  char cStack_2;
  byte bStack_1;
  
  FUN_fffc8f30(3000);
  PTR_DAT_00025d60[0x40b] = 1;
  bStack_1 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pcVar1 = (char *)menu_cursor_of(bStack_1);
  if (pcVar1 == (char *)0x0) {
    return;
  }
  uStack_4 = PTR_DAT_00025d60[0x41f];
  bStack_3 = bStack_1;
  cStack_2 = *pcVar1 + pcVar1[1];
  menu_call_step((uint)&uStack_4);
  return;
}


// ===== menu_apply_from_cat @ fffcdddb (42 bytes)

/* Set 0x15DFC=1, menu_call_step(key), clear, set state+0x40B (0x20F0F) refresh flag */

void menu_apply_from_cat(uint param_1)

{
  DAT_00015dfc = 1;
  menu_call_step(param_1);
  DAT_00015dfc = 0;
  PTR_DAT_00025d60[0x40b] = 1;
  return;
}


// ===== menu_step_s8 @ fffcde18 (74 bytes)

/* Generic signed stepper (min, max, ptr); no-op when 0x15DFC=1 (CAT apply); direction state+0x421
    */

void menu_step_s8(char param_1,char param_2,char *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + '\x01';
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 + -1;
      return;
    }
  }
  return;
}


// ===== FUN_fffcdecf @ fffcdecf (72 bytes)

void FUN_fffcdecf(byte *param_1)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      *param_1 = *param_1 + 1;
      if (0x13 < *param_1) {
        *param_1 = 0x13;
        return;
      }
    }
    else if (*param_1 != 0) {
      *param_1 = *param_1 - 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffcdf37 @ fffcdf37 (92 bytes)

void FUN_fffcdf37(byte *param_1)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if ((*param_1 != 0) && (*param_1 = *param_1 + 1, 0x43 < *param_1)) {
        *param_1 = 0;
        return;
      }
    }
    else {
      if (*param_1 == 0) {
        *param_1 = 0x43;
        return;
      }
      if (*param_1 != 1) {
        *param_1 = *param_1 - 1;
        return;
      }
    }
  }
  return;
}


// ===== menu_step_u8 @ fffcdfb8 (72 bytes)

/* Generic unsigned stepper (min, max, ptr) [inference: unsigned twin of menu_step_s8] */

void menu_step_u8(byte param_1,byte param_2,byte *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + 1;
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 - 1;
      return;
    }
  }
  return;
}


// ===== menu_fm_rptshift_get @ fffce3eb (38 bytes)

/* EX010317 accessor: (VFO byte+2 >> 2) & 3 */

byte menu_fm_rptshift_get(void)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  return pbVar1[2] >> 2 & 3;
}


// ===== menu_fm_rptshift_set @ fffce411 (37 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce42c) */
/* EX010317 accessor (set) */

void menu_fm_rptshift_set(byte param_1)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  pbVar1[2] = pbVar1[2] & 0xf3 | (param_1 & 3) << 2;
  return;
}


// ===== FUN_fffce495 @ fffce495 (74 bytes)

void FUN_fffce495(ushort param_1,ushort param_2,ushort *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + 1;
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 - 1;
      return;
    }
  }
  return;
}


// ===== menu_fm_encdec_get @ fffce53c (38 bytes)

/* EX010320 accessor */

byte menu_fm_encdec_get(void)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  return pbVar1[3] >> 3 & 7;
}


// ===== menu_fm_encdec_set @ fffce562 (38 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce57d) */
/* EX010320 accessor (set) */

void menu_fm_encdec_set(byte param_1)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  pbVar1[3] = pbVar1[3] & 199 | (param_1 & 7) << 3;
  return;
}


// ===== menu_fm_tone_get @ fffce5be (55 bytes)

/* EX010321 accessor */

byte menu_fm_tone_get(void)

{
  byte *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d4f;
  }
  else {
    local_8 = &DAT_00009da9;
  }
  return *local_8;
}


// ===== menu_fm_tone_set @ fffce5f5 (52 bytes)

/* EX010321 accessor (set) */

void menu_fm_tone_set(byte param_1)

{
  byte *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d4f;
  }
  else {
    local_8 = &DAT_00009da9;
  }
  *local_8 = param_1;
  return;
}


// ===== FUN_fffcf38f @ fffcf38f (108 bytes)

void FUN_fffcf38f(byte param_1,byte param_2,byte *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if ((*param_3 < param_2) && (*param_3 = *param_3 + 1, 9 < (*param_3 & 0xf))) {
        *param_3 = *param_3 + 6;
        return;
      }
    }
    else if ((param_1 < *param_3) && (*param_3 = *param_3 - 1, 9 < (*param_3 & 0xf))) {
      *param_3 = *param_3 - 6;
      return;
    }
  }
  return;
}


// ===== FUN_fffcf45c @ fffcf45c (92 bytes)

void FUN_fffcf45c(void)

{
  if ((((PTR_DAT_00025d60[0xa5] == '\x01') && (PTR_DAT_00025d60[0xa7] != PTR_DAT_00025d60[0xa6])) &&
      (PTR_DAT_00025d60[0xa7] = PTR_DAT_00025d60[0xa6], PTR_DAT_00025d60[0xa6] == '\x01')) &&
     ((PTR_DAT_00025d60[0xba] == '\0' && (PTR_DAT_00025d60[0x95] == '\0')))) {
    FUN_fffcf4b8();
    return;
  }
  return;
}


// ===== FUN_fffcf4b8 @ fffcf4b8 (29 bytes)

void FUN_fffcf4b8(void)

{
  PTR_DAT_00025d60[0xbb] = 1;
  PTR_DAT_00025d60[0x448] = 1;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf4d5 @ fffcf4d5 (29 bytes)

void FUN_fffcf4d5(void)

{
  PTR_DAT_00025d60[0xbb] = 2;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf4f2 @ fffcf4f2 (29 bytes)

void FUN_fffcf4f2(void)

{
  PTR_DAT_00025d60[0xbb] = 3;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf50f @ fffcf50f (29 bytes)

void FUN_fffcf50f(void)

{
  PTR_DAT_00025d60[0xbb] = 5;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf52c @ fffcf52c (29 bytes)

void FUN_fffcf52c(void)

{
  PTR_DAT_00025d60[0xbb] = 6;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf549 @ fffcf549 (29 bytes)

void FUN_fffcf549(void)

{
  PTR_DAT_00025d60[0xbb] = 7;
  PTR_DAT_00025d60[0x448] = 1;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf566 @ fffcf566 (29 bytes)

void FUN_fffcf566(void)

{
  PTR_DAT_00025d60[0xbb] = 8;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf583 @ fffcf583 (29 bytes)

void FUN_fffcf583(void)

{
  PTR_DAT_00025d60[0xbb] = 0xd;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf5a0 @ fffcf5a0 (29 bytes)

void FUN_fffcf5a0(void)

{
  PTR_DAT_00025d60[0xbb] = 9;
  PTR_DAT_00025d60[0x448] = 1;
  FUN_fffcf6ac();
  return;
}

