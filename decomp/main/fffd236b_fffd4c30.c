// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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


// ===== FUN_fffd2b7a @ fffd2b7a (234 bytes)

void FUN_fffd2b7a(byte param_1,byte *param_2)

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
    local_b = DAT_00009bc2;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b65;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b84;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba3;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b46;
  }
  if (local_b == 0) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 10;
  param_2[2] = 0;
  if (4 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x22bf);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== FUN_fffd2ca5 @ fffd2ca5 (234 bytes)

void FUN_fffd2ca5(byte param_1,byte *param_2)

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
    local_b = DAT_00009bc3;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b66;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b85;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba4;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b47;
  }
  if (local_b == 3) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 10;
  param_2[2] = 0;
  if (3 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x2e8);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== FUN_fffd2dd0 @ fffd2dd0 (214 bytes)

void FUN_fffd2dd0(byte param_1,byte *param_2)

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
    local_b = DAT_00009bc4;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b67;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b86;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba5;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b48;
  }
  if (local_b == '2') {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xc;
  param_2[2] = 0;
  FUN_fff9c6f0(local_b,param_2 + 0x18);
  return;
}


// ===== FUN_fffd2ee7 @ fffd2ee7 (214 bytes)

void FUN_fffd2ee7(byte param_1,byte *param_2)

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
    local_b = DAT_00009bc5;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b68;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b87;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba6;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b49;
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


// ===== FUN_fffd2ffe @ fffd2ffe (234 bytes)

void FUN_fffd2ffe(byte param_1,byte *param_2)

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
    local_b = DAT_00009bc6;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b69;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b88;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba7;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b4a;
  }
  if (local_b == 1) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xb;
  param_2[2] = 0;
  if (3 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x33c);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== FUN_fffd30e8 @ fffd30e8 (138 bytes)

void FUN_fffd30e8(void)

{
  FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  return;
}


// ===== FUN_fffd3202 @ fffd3202 (132 bytes)

void FUN_fffd3202(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bb6;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b59;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b78;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b97;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b3a;
  }
  FUN_fffcdfb8(0,4,local_8);
  return;
}


// ===== FUN_fffd32a4 @ fffd32a4 (132 bytes)

void FUN_fffd32a4(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bb7;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b5a;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b79;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b98;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b3b;
  }
  FUN_fffcdfb8(0,3,local_8);
  return;
}


// ===== FUN_fffd3346 @ fffd3346 (132 bytes)

void FUN_fffd3346(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bb8;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b5b;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b7a;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b99;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b3c;
  }
  FUN_fffcdfb8(0,1,local_8);
  return;
}


// ===== FUN_fffd33e8 @ fffd33e8 (133 bytes)

void FUN_fffd33e8(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bb9;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b5c;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b7b;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b9a;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b3d;
  }
  FUN_fffcdfb8(0,199,local_8);
  return;
}


// ===== FUN_fffd348b @ fffd348b (133 bytes)

void FUN_fffd348b(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bba;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b5d;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b7c;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b9b;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b3e;
  }
  FUN_fffcdfb8(0,199,local_8);
  return;
}


// ===== FUN_fffd352e @ fffd352e (133 bytes)

void FUN_fffd352e(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bbb;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b5e;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b7d;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b9c;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b3f;
  }
  FUN_fffcdfb8(0,199,local_8);
  return;
}


// ===== FUN_fffd35d1 @ fffd35d1 (133 bytes)

void FUN_fffd35d1(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bbc;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b5f;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b7e;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b9d;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b40;
  }
  FUN_fffcdfb8(0,0x13,local_8);
  return;
}


// ===== FUN_fffd3674 @ fffd3674 (132 bytes)

void FUN_fffd3674(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bbd;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b60;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b7f;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b9e;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b41;
  }
  FUN_fffcdfb8(0,1,local_8);
  return;
}


// ===== FUN_fffd3716 @ fffd3716 (133 bytes)

void FUN_fffd3716(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bbe;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b61;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b80;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b9f;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b42;
  }
  FUN_fffcdfb8(0,0x43,local_8);
  return;
}


// ===== FUN_fffd37b9 @ fffd37b9 (132 bytes)

void FUN_fffd37b9(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bbf;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b62;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b81;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009ba0;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b43;
  }
  FUN_fffcdfb8(0,1,local_8);
  return;
}


// ===== FUN_fffd385b @ fffd385b (133 bytes)

void FUN_fffd385b(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bc0;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b63;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b82;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009ba1;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b44;
  }
  FUN_fffcdfb8(0,100,local_8);
  return;
}


// ===== FUN_fffd38fe @ fffd38fe (133 bytes)

void FUN_fffd38fe(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bc1;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b64;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b83;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009ba2;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b45;
  }
  FUN_fffcdfb8(0,100,local_8);
  return;
}


// ===== FUN_fffd39a1 @ fffd39a1 (132 bytes)

void FUN_fffd39a1(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bc2;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b65;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b84;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009ba3;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b46;
  }
  FUN_fffcdfb8(0,4,local_8);
  return;
}


// ===== FUN_fffd3a43 @ fffd3a43 (132 bytes)

void FUN_fffd3a43(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bc3;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b66;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b85;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009ba4;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b47;
  }
  FUN_fffcdfb8(0,3,local_8);
  return;
}


// ===== FUN_fffd3ae5 @ fffd3ae5 (133 bytes)

void FUN_fffd3ae5(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bc4;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b67;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b86;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009ba5;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b48;
  }
  FUN_fffcdfb8(0,100,local_8);
  return;
}


// ===== FUN_fffd3b88 @ fffd3b88 (133 bytes)

void FUN_fffd3b88(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bc5;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b68;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b87;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009ba6;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b49;
  }
  FUN_fffcdfb8(0,100,local_8);
  return;
}


// ===== FUN_fffd3c2b @ fffd3c2b (132 bytes)

void FUN_fffd3c2b(byte param_1)

{
  bool bVar1;
  undefined1 *local_8;
  
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
    local_8 = &DAT_00009bc6;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b69;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b88;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009ba7;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b4a;
  }
  FUN_fffcdfb8(0,3,local_8);
  return;
}


// ===== FUN_fffd3caf @ fffd3caf (38 bytes)

void FUN_fffd3caf(void)

{
  DAT_00015e05 = DAT_00009bc9;
  PTR_DAT_00025d60[0x420] = DAT_00009bc9;
  return;
}


// ===== FUN_fffd3d03 @ fffd3d03 (859 bytes)

void FUN_fffd3d03(void)

{
  DAT_00009a3d = DAT_00012238;
  DAT_00009a3e = DAT_00012239;
  DAT_00009a50 = DAT_0001223a;
  DAT_00009a51 = DAT_0001223b;
  DAT_00009a65 = DAT_0001223c;
  DAT_00009a66 = DAT_0001223d;
  DAT_00009a7c = DAT_0001223e;
  DAT_00009a7d = DAT_0001223f;
  DAT_00009a8f = DAT_00012240;
  DAT_00009a90 = DAT_00012241;
  DAT_00009aa5 = DAT_00012242;
  DAT_00009aa6 = DAT_00012243;
  DAT_00009ab3 = DAT_00012244;
  DAT_00009ab4 = DAT_00012245;
  DAT_00009acf = DAT_00012246;
  DAT_00009ad0 = DAT_00012247;
  DAT_00009ad7 = DAT_00012248;
  DAT_00009ad8 = DAT_00012249;
  DAT_00009aec = DAT_0001224a;
  DAT_00009aed = DAT_0001224b;
  DAT_00009af7 = DAT_0001224c;
  DAT_00009af8 = DAT_0001224d;
  DAT_00009aff = DAT_0001224e;
  DAT_00009b00 = DAT_0001224f;
  DAT_00009b12 = DAT_00012250;
  DAT_00009b13 = DAT_00012251;
  DAT_00009b18 = DAT_00012252;
  DAT_00009b19 = DAT_00012253;
  DAT_00009b1e = DAT_00012254;
  DAT_00009b1f = DAT_00012255;
  DAT_00009b22 = DAT_00012256;
  DAT_00009b23 = DAT_00012257;
  DAT_00009b24 = DAT_00012258;
  DAT_00009b25 = DAT_00012259;
  DAT_00009b26 = DAT_0001225a;
  DAT_00009b27 = DAT_0001225b;
  DAT_00009b28 = DAT_0001225e;
  DAT_00009b29 = DAT_0001225f;
  DAT_00009b2a = DAT_00012260;
  DAT_00009b2b = DAT_00012261;
  DAT_00009b2c = DAT_00012262;
  DAT_00009b2d = DAT_00012263;
  DAT_00009b4b = DAT_00012264;
  DAT_00009b4c = DAT_00012265;
  DAT_00009b6a = DAT_00012266;
  DAT_00009b6b = DAT_00012267;
  DAT_00009b89 = DAT_00012268;
  DAT_00009b8a = DAT_00012269;
  DAT_00009ba8 = DAT_0001226a;
  DAT_00009ba9 = DAT_0001226b;
  DAT_00009bc7 = DAT_0001226c;
  DAT_00009bc8 = DAT_0001226d;
  return;
}


// ===== FUN_fffd405e @ fffd405e (859 bytes)

void FUN_fffd405e(void)

{
  DAT_00012238 = DAT_00009a3d;
  DAT_00012239 = DAT_00009a3e;
  DAT_0001223a = DAT_00009a50;
  DAT_0001223b = DAT_00009a51;
  DAT_0001223c = DAT_00009a65;
  DAT_0001223d = DAT_00009a66;
  DAT_0001223e = DAT_00009a7c;
  DAT_0001223f = DAT_00009a7d;
  DAT_00012240 = DAT_00009a8f;
  DAT_00012241 = DAT_00009a90;
  DAT_00012242 = DAT_00009aa5;
  DAT_00012243 = DAT_00009aa6;
  DAT_00012244 = DAT_00009ab3;
  DAT_00012245 = DAT_00009ab4;
  DAT_00012246 = DAT_00009acf;
  DAT_00012247 = DAT_00009ad0;
  DAT_00012248 = DAT_00009ad7;
  DAT_00012249 = DAT_00009ad8;
  DAT_0001224a = DAT_00009aec;
  DAT_0001224b = DAT_00009aed;
  DAT_0001224c = DAT_00009af7;
  DAT_0001224d = DAT_00009af8;
  DAT_0001224e = DAT_00009aff;
  DAT_0001224f = DAT_00009b00;
  DAT_00012250 = DAT_00009b12;
  DAT_00012251 = DAT_00009b13;
  DAT_00012252 = DAT_00009b18;
  DAT_00012253 = DAT_00009b19;
  DAT_00012254 = DAT_00009b1e;
  DAT_00012255 = DAT_00009b1f;
  DAT_00012256 = DAT_00009b22;
  DAT_00012257 = DAT_00009b23;
  DAT_00012258 = DAT_00009b24;
  DAT_00012259 = DAT_00009b25;
  DAT_0001225a = DAT_00009b26;
  DAT_0001225b = DAT_00009b27;
  DAT_0001225e = DAT_00009b28;
  DAT_0001225f = DAT_00009b29;
  DAT_00012260 = DAT_00009b2a;
  DAT_00012261 = DAT_00009b2b;
  DAT_00012262 = DAT_00009b2c;
  DAT_00012263 = DAT_00009b2d;
  DAT_00012264 = DAT_00009b4b;
  DAT_00012265 = DAT_00009b4c;
  DAT_00012266 = DAT_00009b6a;
  DAT_00012267 = DAT_00009b6b;
  DAT_00012268 = DAT_00009b89;
  DAT_00012269 = DAT_00009b8a;
  DAT_0001226a = DAT_00009ba8;
  DAT_0001226b = DAT_00009ba9;
  DAT_0001226c = DAT_00009bc7;
  DAT_0001226d = DAT_00009bc8;
  return;
}


// ===== FUN_fffd43b9 @ fffd43b9 (118 bytes)

char FUN_fffd43b9(char param_1)

{
  bool bVar1;
  char local_3;
  
  local_3 = '\x01';
  if (DAT_00020b97 == '\0') {
    if (DAT_00020b96 != '\0') {
      local_3 = '\0';
    }
  }
  else {
    local_3 = '\0';
  }
  if ((local_3 == '\0') || (param_1 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (PTR_DAT_00025d60[0xa6] != '\x01')) {
    local_3 = '\0';
    if (param_1 == '\x01') {
      FUN_fffcf4d5();
    }
    else {
      FUN_fffcf4f2();
    }
  }
  if (local_3 == '\0') {
    FUN_fffb2da6(3);
    FUN_fffc8f30(0);
  }
  return local_3;
}


// ===== FUN_fffd442f @ fffd442f (377 bytes)

undefined1 FUN_fffd442f(undefined1 *param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 local_6;
  
  if (param_1 == (undefined1 *)0x0) {
    local_6 = 0;
  }
  else if (DAT_0001fa4e == 0x15e) {
    local_6 = 0;
  }
  else {
    puVar2 = &DAT_0002105c + (uint)DAT_0001fa4e * 0x38;
    puVar3 = param_1;
    for (iVar4 = 0x38; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    cVar1 = param_1[3];
    if (cVar1 == '\x05') {
      *(ushort *)(&DAT_0001fe38 + (uint)DAT_0001b4fb * 2) = DAT_0001fa4e;
      DAT_0001b4fb = DAT_0001b4fb + 1;
    }
    else if (cVar1 == '\x01') {
      *(ushort *)(&DAT_0001fb18 + (uint)DAT_0001b4f7 * 2) = DAT_0001fa4e;
      DAT_0001b4f7 = DAT_0001b4f7 + 1;
    }
    else if (cVar1 == '\x02') {
      *(ushort *)(&DAT_0001fbe0 + (uint)DAT_0001b4f8 * 2) = DAT_0001fa4e;
      DAT_0001b4f8 = DAT_0001b4f8 + 1;
    }
    else if (cVar1 == '\x03') {
      *(ushort *)(&DAT_0001fca8 + (uint)DAT_0001b4f9 * 2) = DAT_0001fa4e;
      DAT_0001b4f9 = DAT_0001b4f9 + 1;
    }
    else if (cVar1 == '\x04') {
      *(ushort *)(&DAT_0001fd70 + (uint)DAT_0001b4fa * 2) = DAT_0001fa4e;
      DAT_0001b4fa = DAT_0001b4fa + 1;
    }
    else {
      if (cVar1 != '\0') {
        return 0;
      }
      *(ushort *)(&DAT_0001fa50 + (uint)DAT_0001b4f6 * 2) = DAT_0001fa4e;
      DAT_0001b4f6 = DAT_0001b4f6 + 1;
    }
    DAT_0001fa4e = DAT_0001fa4e + 1;
    if (0x15e < DAT_0001fa4e) {
      DAT_0001fa4e = 0x15f;
    }
    local_6 = 1;
  }
  return local_6;
}


// ===== FUN_fffd45a8 @ fffd45a8 (169 bytes)

undefined1 FUN_fffd45a8(char param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  ushort uStack_6;
  
  bVar2 = FUN_fffd4a4f();
  uStack_6 = 0;
  do {
    if (0x15d < uStack_6) {
      return 0;
    }
    if ((&DAT_0002105c)[(uint)uStack_6 * 0x38] == '\x01') {
      if (((&DAT_0002105f)[(uint)uStack_6 * 0x38] == param_1) &&
         ((&DAT_00021060)[(uint)uStack_6 * 0x38] == param_2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if ((&DAT_0002105d)[(uint)uStack_6 * 0x38] == '\0') {
          return 1;
        }
        if (((&DAT_0002105d)[(uint)uStack_6 * 0x38] & bVar2) != 0) {
          return 1;
        }
      }
    }
    uStack_6 = uStack_6 + 1;
  } while( true );
}


// ===== FUN_fffd4651 @ fffd4651 (324 bytes)

ushort FUN_fffd4651(char *param_1)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  byte bVar4;
  undefined *puStack_10;
  ushort uStack_8;
  
  if (param_1 != (char *)0x0) {
    bVar4 = FUN_fffd4a4f();
    cVar1 = *param_1;
    if (cVar1 == '\x05') {
      puStack_10 = &DAT_0001fe38;
    }
    else if (cVar1 == '\x01') {
      puStack_10 = &DAT_0001fb18;
    }
    else if (cVar1 == '\x02') {
      puStack_10 = &DAT_0001fbe0;
    }
    else if (cVar1 == '\x03') {
      puStack_10 = &DAT_0001fca8;
    }
    else if (cVar1 == '\x04') {
      puStack_10 = &DAT_0001fd70;
    }
    else {
      if (cVar1 != '\0') {
        return 0xffff;
      }
      puStack_10 = &DAT_0001fa50;
    }
    for (uStack_8 = 0; uStack_8 < 100; uStack_8 = uStack_8 + 1) {
      uVar2 = *(ushort *)(puStack_10 + (uint)uStack_8 * 2);
      if ((&DAT_0002105c)[(uint)uVar2 * 0x38] == '\x01') {
        if ((*param_1 == (&DAT_0002105f)[(uint)uVar2 * 0x38]) &&
           (param_1[1] == (&DAT_00021060)[(uint)uVar2 * 0x38])) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if ((bVar3) && (param_1[2] == (&DAT_00021061)[(uint)uVar2 * 0x38])) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          if ((&DAT_0002105d)[(uint)uVar2 * 0x38] == '\0') {
            return uVar2;
          }
          if (((&DAT_0002105d)[(uint)uVar2 * 0x38] & bVar4) != 0) {
            return uVar2;
          }
        }
      }
    }
  }
  return 0xffff;
}


// ===== FUN_fffd4795 @ fffd4795 (85 bytes)

undefined1 FUN_fffd4795(int param_1,undefined1 *param_2)

{
  bool bVar1;
  ushort uVar2;
  undefined *puVar3;
  int iVar4;
  undefined1 local_d;
  
  if ((param_1 == 0) || (param_2 == (undefined1 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_d = 0;
  }
  else {
    uVar2 = FUN_fffd4651(param_1);
    if (uVar2 == 0xffff) {
      local_d = 0;
    }
    else {
      puVar3 = &DAT_0002105c + (uint)uVar2 * 0x38;
      for (iVar4 = 0x38; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_2 = *puVar3;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      local_d = 1;
    }
  }
  return local_d;
}


// ===== FUN_fffd47ea @ fffd47ea (87 bytes)

undefined1 FUN_fffd47ea(int param_1,undefined1 *param_2)

{
  bool bVar1;
  ushort uVar2;
  undefined *puVar3;
  int iVar4;
  undefined1 local_d;
  
  if ((param_1 == 0) || (param_2 == (undefined1 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_d = 0;
  }
  else {
    uVar2 = FUN_fffd4651(param_1);
    if (uVar2 == 0xffff) {
      local_d = 0;
    }
    else {
      puVar3 = &DAT_00021062 + (uint)uVar2 * 0x38;
      for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_2 = *puVar3;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      local_d = 1;
    }
  }
  return local_d;
}


// ===== FUN_fffd4841 @ fffd4841 (144 bytes)

char FUN_fffd4841(char param_1)

{
  bool bVar1;
  byte bVar2;
  ushort local_6;
  char local_3;
  
  local_3 = '\0';
  for (local_6 = 0; local_6 < 0x15e; local_6 = local_6 + 1) {
    if (((&DAT_0002105c)[(uint)local_6 * 0x38] == '\x01') &&
       (param_1 == (&DAT_00021060)[(uint)local_6 * 0x38])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if ((&DAT_0002105d)[(uint)local_6 * 0x38] == '\0') {
        local_3 = local_3 + '\x01';
      }
      else {
        bVar2 = FUN_fffd4a4f();
        if (*(char *)(uint)((&DAT_0002105d)[(uint)local_6 * 0x38] & bVar2) != '\0') {
          local_3 = local_3 + '\x01';
        }
      }
    }
  }
  return local_3;
}


// ===== FUN_fffd48d1 @ fffd48d1 (207 bytes)

char FUN_fffd48d1(char param_1)

{
  bool bVar1;
  byte bVar2;
  ushort local_8;
  char local_5;
  char local_3;
  
  local_3 = '\0';
  local_5 = -1;
  for (local_8 = 0; local_8 < 0x15e; local_8 = local_8 + 1) {
    if (((&DAT_0002105c)[(uint)local_8 * 0x38] == '\x01') &&
       (param_1 == (&DAT_0002105f)[(uint)local_8 * 0x38])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (local_5 != (&DAT_00021060)[(uint)local_8 * 0x38])) {
      if ((&DAT_0002105d)[(uint)local_8 * 0x38] == '\0') {
        local_3 = local_3 + '\x01';
        local_5 = (&DAT_00021060)[(uint)local_8 * 0x38];
      }
      else {
        bVar2 = FUN_fffd4a4f();
        if (*(char *)(uint)((&DAT_0002105d)[(uint)local_8 * 0x38] & bVar2) != '\0') {
          local_3 = local_3 + '\x01';
          local_5 = (&DAT_00021060)[(uint)local_8 * 0x38];
        }
      }
    }
  }
  return local_3;
}


// ===== FUN_fffd49a0 @ fffd49a0 (32 bytes)

uint FUN_fffd49a0(undefined4 param_1,uint param_2)

{
  byte bVar1;
  
  bVar1 = FUN_fffd4795(param_1);
  if (bVar1 != 1) {
    return (uint)bVar1;
  }
  return param_2;
}


// ===== FUN_fffd49c0 @ fffd49c0 (26 bytes)

uint FUN_fffd49c0(void)

{
  byte bVar1;
  undefined4 uStack_1c;
  
  bVar1 = FUN_fffd4795();
  if (bVar1 != 1) {
    return (uint)bVar1;
  }
  return uStack_1c;
}


// ===== FUN_fffd49da @ fffd49da (26 bytes)

uint FUN_fffd49da(void)

{
  byte bVar1;
  undefined4 uStack_18;
  
  bVar1 = FUN_fffd4795();
  if (bVar1 != 1) {
    return (uint)bVar1;
  }
  return uStack_18;
}


// ===== FUN_fffd49f4 @ fffd49f4 (91 bytes)

char FUN_fffd49f4(char param_1,char param_2)

{
  char local_4;
  
  local_4 = param_2;
  if (param_1 != '\0') {
    if (param_1 == '\x01') {
      local_4 = param_2 + '\x05';
    }
    else if (param_1 == '\x02') {
      local_4 = param_2 + '\a';
    }
    else if (param_1 == '\x03') {
      local_4 = param_2 + '\f';
    }
    else if (param_1 == '\x04') {
      local_4 = param_2 + '\x10';
    }
    else if (param_1 == '\x05') {
      local_4 = param_2 + '\x16';
    }
  }
  return local_4;
}


// ===== FUN_fffd4a4f @ fffd4a4f (139 bytes)

undefined1 FUN_fffd4a4f(void)

{
  short sVar1;
  undefined1 uStack_5;
  
  sVar1 = dest_code_get();
  if (sVar1 == -0x26b0) {
    return 0x10;
  }
  if (sVar1 == 0x1cb9) {
    return 0x20;
  }
  if (sVar1 == 0x306f) {
    return 8;
  }
  if (sVar1 == 0x315b) {
LAB_fffd4ab8:
    uStack_5 = 2;
  }
  else {
    if (sVar1 != 0x4380) {
      if (sVar1 == 0x50e2) goto LAB_fffd4ab8;
      if (sVar1 != 0x60e6) {
        if ((sVar1 == 0x7753) || (sVar1 == -0x6309)) {
          return 8;
        }
        if (sVar1 == -0x5b3b) {
          return 0x10;
        }
        if ((sVar1 == -0x567d) || (sVar1 == -0x4a59)) {
          return 4;
        }
        if (sVar1 == -0x2cd3) {
          return 8;
        }
        if (sVar1 != 0x20b) {
          return 1;
        }
      }
    }
    uStack_5 = 1;
  }
  return uStack_5;
}


// ===== FUN_fffd4ada @ fffd4ada (317 bytes)

void FUN_fffd4ada(undefined1 param_1)

{
  switch(param_1) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
    break;
  case 0x17:
    break;
  case 0x18:
    break;
  case 0x19:
    break;
  case 0x1a:
  }
  return;
}


// ===== FUN_fffd4c17 @ fffd4c17 (15 bytes)

undefined1 FUN_fffd4c17(void)

{
  return PTR_s_V01_12_0001b4fd._0_1_;
}


// ===== FUN_fffd4c26 @ fffd4c26 (10 bytes)

void FUN_fffd4c26(void)

{
  PTR_s_V01_12_0001b4fd._0_1_ = 0;
  return;
}


// ===== FUN_fffd4c30 @ fffd4c30 (961 bytes)

void FUN_fffd4c30(void)

{
  FUN_fffd5373();
  FUN_fffd53e1();
  FUN_fffd544f();
  FUN_fffd54bd();
  FUN_fffd5529();
  FUN_fffd5595();
  FUN_fffd5601();
  FUN_fffd566d();
  FUN_fffd56d9();
  FUN_fffd5745();
  FUN_fffd57b1();
  FUN_fffd581d();
  FUN_fffd5889();
  FUN_fffd58f5();
  FUN_fffd5961();
  FUN_fffd59cd();
  FUN_fffd5a39();
  FUN_fffd5aa5();
  FUN_fffd5b11();
  FUN_fffd5b7d();
  FUN_fffd5beb();
  FUN_fffd5c59();
  FUN_fffd5cc7();
  FUN_fffd5d33();
  FUN_fffd5d9f();
  FUN_fffd5e0b();
  FUN_fffd5e77();
  FUN_fffd5ee3();
  FUN_fffd5f4f();
  FUN_fffd5fbb();
  FUN_fffd6027();
  FUN_fffd6093();
  FUN_fffd60ff();
  FUN_fffd616b();
  FUN_fffd61d7();
  FUN_fffd6243();
  FUN_fffd62af();
  FUN_fffd631d();
  FUN_fffd638b();
  FUN_fffd63f9();
  FUN_fffd6465();
  FUN_fffd64d1();
  FUN_fffd653d();
  FUN_fffd65a9();
  FUN_fffd6615();
  FUN_fffd6681();
  FUN_fffd66ed();
  FUN_fffd6759();
  FUN_fffd67c5();
  FUN_fffd6831();
  FUN_fffd689d();
  FUN_fffd6909();
  FUN_fffd6975();
  FUN_fffd69d8();
  FUN_fffd6a44();
  FUN_fffd6ab2();
  FUN_fffd6b15();
  FUN_fffd6b78();
  FUN_fffd6be6();
  FUN_fffd6c54();
  FUN_fffd6cc2();
  FUN_fffd6d2e();
  FUN_fffd6d9a();
  FUN_fffd6e06();
  FUN_fffd6e72();
  FUN_fffd6ede();
  FUN_fffd6f4a();
  FUN_fffd6fb6();
  FUN_fffd7022();
  FUN_fffd708e();
  FUN_fffd70fa();
  FUN_fffd7166();
  FUN_fffd71d2();
  FUN_fffd723e();
  FUN_fffd72aa();
  FUN_fffd7316();
  FUN_fffd7382();
  FUN_fffd73f0();
  FUN_fffd745e();
  FUN_fffd74cc();
  FUN_fffd753a();
  FUN_fffd75a6();
  FUN_fffd7612();
  FUN_fffd767e();
  FUN_fffd76ea();
  FUN_fffd7756();
  FUN_fffd77c2();
  FUN_fffd782e();
  FUN_fffd789a();
  FUN_fffd7906();
  FUN_fffd7972();
  FUN_fffd79de();
  FUN_fffd7a4a();
  FUN_fffd7ab6();
  FUN_fffd7b22();
  FUN_fffd7b90();
  FUN_fffd7bfe();
  FUN_fffd7c6c();
  FUN_fffd7cd8();
  FUN_fffd7d44();
  FUN_fffd7db0();
  FUN_fffd7e1c();
  FUN_fffd7e88();
  FUN_fffd7ef4();
  FUN_fffd7f60();
  FUN_fffd7fcc();
  FUN_fffd8038();
  FUN_fffd80a4();
  FUN_fffd8110();
  FUN_fffd817c();
  FUN_fffd81e8();
  FUN_fffd8254();
  FUN_fffd82c0();
  FUN_fffd832c();
  FUN_fffd8398();
  FUN_fffd8404();
  FUN_fffd8470();
  FUN_fffd84dc();
  FUN_fffd8548();
  FUN_fffd85b6();
  FUN_fffd8622();
  FUN_fffd868e();
  FUN_fffd86fa();
  FUN_fffd8766();
  FUN_fffd87d2();
  FUN_fffd883e();
  FUN_fffd88aa();
  FUN_fffd8916();
  FUN_fffd8982();
  FUN_fffd89ee();
  FUN_fffd8a5a();
  FUN_fffd8ac6();
  FUN_fffd8b32();
  FUN_fffd8b9e();
  FUN_fffd8c0a();
  FUN_fffd8c76();
  FUN_fffd8ce2();
  FUN_fffd8d4e();
  FUN_fffd8dba();
  FUN_fffd8e26();
  FUN_fffd8e92();
  FUN_fffd8efe();
  FUN_fffd8f6a();
  FUN_fffd8fd8();
  FUN_fffd9044();
  FUN_fffd90b0();
  FUN_fffd911c();
  FUN_fffd9188();
  FUN_fffd91f4();
  FUN_fffd9260();
  FUN_fffd92cc();
  FUN_fffd9338();
  FUN_fffd93a4();
  FUN_fffd9410();
  FUN_fffd947c();
  FUN_fffd94e8();
  FUN_fffd9556();
  FUN_fffd95c2();
  FUN_fffd962e();
  FUN_fffd969a();
  FUN_fffd9708();
  FUN_fffd9774();
  FUN_fffd97e0();
  FUN_fffd984e();
  FUN_fffd98ba();
  FUN_fffd9926();
  FUN_fffd9994();
  FUN_fffd9a00();
  FUN_fffd9a6c();
  FUN_fffd9ada();
  FUN_fffd9b46();
  FUN_fffd9bb2();
  FUN_fffd9c20();
  FUN_fffd9c8c();
  FUN_fffd9cf8();
  FUN_fffd9d66();
  FUN_fffd9dd2();
  FUN_fffd9e3e();
  FUN_fffd9eaa();
  FUN_fffd9f16();
  FUN_fffd9f82();
  FUN_fffd9fee();
  FUN_fffda05a();
  FUN_fffda0c6();
  FUN_fffda132();
  FUN_fffda19e();
  FUN_fffda20a();
  FUN_fffda276();
  FUN_fffda2e2();
  FUN_fffda34e();
  FUN_fffda3ba();
  FUN_fffda426();
  FUN_fffda492();
  FUN_fffda4fe();
  FUN_fffda56a();
  FUN_fffda5d6();
  FUN_fffda642();
  FUN_fffda6ae();
  FUN_fffda71a();
  FUN_fffda786();
  FUN_fffda7f2();
  FUN_fffda85e();
  FUN_fffda8ca();
  FUN_fffda936();
  FUN_fffda9a2();
  FUN_fffdaa0e();
  FUN_fffdaa7a();
  FUN_fffdaadd();
  FUN_fffdab40();
  FUN_fffdaba3();
  FUN_fffdac06();
  FUN_fffdac69();
  FUN_fffdaccc();
  FUN_fffdad2f();
  FUN_fffdad92();
  FUN_fffdadf5();
  FUN_fffdae58();
  FUN_fffdaebb();
  FUN_fffdaf1e();
  FUN_fffdaf81();
  FUN_fffdafe4();
  FUN_fffdb047();
  FUN_fffdb0aa();
  FUN_fffdb10d();
  FUN_fffdb170();
  FUN_fffdb1dc();
  FUN_fffdb248();
  FUN_fffdb2b4();
  FUN_fffdb320();
  FUN_fffdb38c();
  FUN_fffdb3f8();
  FUN_fffdb464();
  FUN_fffdb4d0();
  FUN_fffdb53c();
  FUN_fffdb5a8();
  FUN_fffdb614();
  FUN_fffdb680();
  FUN_fffdb6ec();
  FUN_fffdb758();
  FUN_fffdb7c4();
  FUN_fffdb830();
  FUN_fffdb89c();
  FUN_fffdb908();
  FUN_fffdb974();
  FUN_fffdb9e0();
  FUN_fffdba4c();
  FUN_fffdbab8();
  FUN_fffdbb24();
  FUN_fffdbb90();
  FUN_fffdbbfc();
  FUN_fffdbc68();
  FUN_fffdbcd4();
  FUN_fffdbd40();
  FUN_fffdbdac();
  FUN_fffdbe18();
  FUN_fffdbe84();
  FUN_fffdbef0();
  FUN_fffdbf5c();
  FUN_fffdbfc8();
  FUN_fffdc034();
  FUN_fffdc0a0();
  FUN_fffdc10c();
  FUN_fffdc178();
  FUN_fffdc1e4();
  FUN_fffdc250();
  FUN_fffdc2bc();
  FUN_fffdc328();
  FUN_fffdc394();
  FUN_fffdc401();
  FUN_fffdc46e();
  FUN_fffdc4db();
  FUN_fffdc548();
  FUN_fffdc5b5();
  FUN_fffdc622();
  FUN_fffdc68f();
  FUN_fffdc6fc();
  FUN_fffdc769();
  FUN_fffdc7d6();
  FUN_fffdc843();
  FUN_fffdc8b0();
  FUN_fffdc91d();
  FUN_fffdc98a();
  FUN_fffdc9f7();
  FUN_fffdca64();
  FUN_fffdcad1();
  FUN_fffdcb3e();
  FUN_fffdcbab();
  FUN_fffdcc18();
  FUN_fffdcc85();
  FUN_fffdccf2();
  FUN_fffdcd5f();
  FUN_fffdcdcc();
  FUN_fffdce39();
  FUN_fffdcea6();
  FUN_fffdcf13();
  FUN_fffdcf80();
  FUN_fffdcfed();
  FUN_fffdd05a();
  FUN_fffdd0c7();
  FUN_fffdd134();
  FUN_fffdd1a1();
  FUN_fffdd20e();
  FUN_fffdd27b();
  FUN_fffdd2e8();
  FUN_fffdd355();
  FUN_fffdd3c2();
  FUN_fffdd42f();
  FUN_fffdd49c();
  FUN_fffdd509();
  FUN_fffdd576();
  FUN_fffdd5e3();
  FUN_fffdd650();
  FUN_fffdd6bd();
  FUN_fffdd72a();
  return;
}

