// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd1847 @ fffd1847 (42 bytes)

void FUN_fffd1847(char param_1)

{
  if (PTR_DAT_00025d60[0x3f7] != '\x02') {
    return;
  }
  if (param_1 < '\x01') {
    FUN_fffcfe83(1);
    return;
  }
  FUN_fffcfe83(0);
  return;
}


// ===== FUN_fffd1871 @ fffd1871 (52 bytes)

void FUN_fffd1871(char param_1)

{
  if (PTR_DAT_00025d60[0x3f7] != '\x02') {
    return;
  }
  if (param_1 < '\x01') {
    DAT_00015de8 = 0xfe;
  }
  else {
    DAT_00015de8 = 0xff;
  }
  FUN_fffd15fd();
  return;
}


// ===== FUN_fffd18a5 @ fffd18a5 (158 bytes)

void FUN_fffd18a5(char param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  
  bVar2 = menu_count_groups(PTR_DAT_00025d60[0x41f]);
  cVar1 = (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]];
  if ('\0' < param_1) {
    bVar3 = cVar1 + 1;
    if (bVar3 < bVar2) {
      (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]] = bVar3;
      PTR_DAT_00025d60[0x420] = bVar3;
      return;
    }
    PTR_DAT_00025d60[0x3ff] = 1;
    return;
  }
  if (cVar1 == '\0') {
    return;
  }
  (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]] = cVar1 + -1;
  PTR_DAT_00025d60[0x420] = cVar1 + -1;
  return;
}


// ===== FUN_fffd1943 @ fffd1943 (87 bytes)

void FUN_fffd1943(char param_1)

{
  char cVar1;
  
  cVar1 = menu_count_groups(PTR_DAT_00025d60[0x41f]);
  if (-1 < param_1) {
    return;
  }
  (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]] = cVar1 + -1;
  PTR_DAT_00025d60[0x420] = cVar1 + -1;
  PTR_DAT_00025d60[0x3ff] = 0;
  return;
}


// ===== FUN_fffd199a @ fffd199a (138 bytes)

void FUN_fffd199a(char param_1)

{
  undefined1 uVar1;
  char cVar2;
  byte *pbVar3;
  
  uVar1 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pbVar3 = (byte *)menu_cursor_of(uVar1);
  if (pbVar3 != (byte *)0x0) {
    cVar2 = menu_count_items(uVar1);
    if ('\0' < param_1) {
      if ((byte)(cVar2 - 1U) <= (byte)(*pbVar3 + pbVar3[1])) {
        PTR_DAT_00025d60[0x3ff] = 4;
        return;
      }
      if (*pbVar3 < 4) {
        *pbVar3 = *pbVar3 + 1;
        return;
      }
      pbVar3[1] = pbVar3[1] + 1;
      return;
    }
    if ((byte)(*pbVar3 + pbVar3[1]) != 0) {
      if (*pbVar3 != 0) {
        *pbVar3 = *pbVar3 - 1;
        return;
      }
      pbVar3[1] = pbVar3[1] - 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffd1a24 @ fffd1a24 (34 bytes)

void FUN_fffd1a24(char param_1)

{
  if (param_1 < '\x01') {
    PTR_DAT_00025d60[0x421] = 1;
  }
  else {
    PTR_DAT_00025d60[0x421] = 0;
  }
  menu_ui_step();
  return;
}


// ===== FUN_fffd1a46 @ fffd1a46 (119 bytes)

void FUN_fffd1a46(char param_1)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  char *pcVar4;
  
  cVar1 = menu_count_items(PTR_DAT_00025d60[0x420]);
  if ((cVar1 != '\0') && (param_1 < '\0')) {
    uVar2 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
    bVar3 = menu_count_items(uVar2);
    pcVar4 = (char *)menu_cursor_of(uVar2);
    if (bVar3 < 6) {
      pcVar4[1] = '\0';
      *pcVar4 = bVar3 - 1;
    }
    else {
      pcVar4[1] = bVar3 - 5;
      *pcVar4 = '\x04';
    }
    PTR_DAT_00025d60[0x3ff] = 2;
    return;
  }
  return;
}


// ===== FUN_fffd1abd @ fffd1abd (27 bytes)

bool FUN_fffd1abd(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc98c1();
  if (iVar1 != 1) {
    FUN_fffd1ad8();
  }
  return iVar1 != 1;
}


// ===== FUN_fffd1ad8 @ fffd1ad8 (206 bytes)

void FUN_fffd1ad8(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d60[0x3ff];
  if (cVar1 == '\x04') {
    PTR_DAT_00025d60[0x3ff] = 0;
    return;
  }
  if (cVar1 == '\x01') {
    beep_request(1);
    FUN_fffc23a4();
    return;
  }
  if (cVar1 == '\x02') {
    menu_ui_enter();
    return;
  }
  if (cVar1 == '\x03') {
    FUN_fffcdcfe();
    return;
  }
  if (cVar1 == '\0') {
    PTR_DAT_00025d60[0x3ff] = 2;
    PTR_DAT_00025d60[0x420] = DAT_0001226e;
    if (PTR_DAT_00025d60[0x41f] == '\x05') {
      if (DAT_0001226e == '\x04') {
        DAT_00009bc9 = 4;
        return;
      }
      if (DAT_0001226e == '\x01') {
        DAT_00009bc9 = 1;
        return;
      }
      if (DAT_0001226e == '\x02') {
        DAT_00009bc9 = 2;
        return;
      }
      if (DAT_0001226e == '\x03') {
        DAT_00009bc9 = 3;
        return;
      }
      if (DAT_0001226e == '\0') {
        DAT_00009bc9 = 0;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffd1ba6 @ fffd1ba6 (62 bytes)

undefined1 FUN_fffd1ba6(void)

{
  undefined1 local_2;
  
  local_2 = 0;
  if (DAT_00015de3 == '\x04') {
    local_2 = FUN_fffd000d();
  }
  else if (DAT_00015de3 == '\x02') {
    local_2 = FUN_fffcfdca();
  }
  else if (DAT_00015de3 == '\x03') {
    local_2 = FUN_fffcffb4();
  }
  else if (DAT_00015de3 == '\x01') {
    local_2 = FUN_fffcfb9a();
  }
  return local_2;
}


// ===== FUN_fffd1c25 @ fffd1c25 (288 bytes)

void FUN_fffd1c25(byte param_1,byte *param_2)

{
  bool bVar1;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00012271 == '\x01') {
      *param_2 = *param_2 | 0x40;
    }
    param_2[1] = 0xc;
    param_2[2] = 0;
    if (param_1 == 5) {
      *(undefined4 *)(param_2 + 0x20) = DAT_00009bb2;
      *(undefined4 *)(param_2 + 0x1c) = DAT_00009bae;
      *(undefined4 *)(param_2 + 0x18) = DAT_00009baa;
      return;
    }
    if (param_1 == 2) {
      *(undefined4 *)(param_2 + 0x20) = DAT_00009b55;
      *(undefined4 *)(param_2 + 0x1c) = DAT_00009b51;
      *(undefined4 *)(param_2 + 0x18) = DAT_00009b4d;
      return;
    }
    if (param_1 == 3) {
      *(undefined4 *)(param_2 + 0x20) = DAT_00009b74;
      *(undefined4 *)(param_2 + 0x1c) = DAT_00009b70;
      *(undefined4 *)(param_2 + 0x18) = DAT_00009b6c;
      return;
    }
    if (param_1 == 4) {
      *(undefined4 *)(param_2 + 0x20) = DAT_00009b93;
      *(undefined4 *)(param_2 + 0x1c) = DAT_00009b8f;
      *(undefined4 *)(param_2 + 0x18) = DAT_00009b8b;
      return;
    }
    if (param_1 == 1) {
      *(undefined4 *)(param_2 + 0x20) = DAT_00009b36;
      *(undefined4 *)(param_2 + 0x1c) = DAT_00009b32;
      *(undefined4 *)(param_2 + 0x18) = DAT_00009b2e;
      return;
    }
  }
  return;
}


// ===== FUN_fffd1d86 @ fffd1d86 (234 bytes)

void FUN_fffd1d86(byte param_1,byte *param_2)

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
    local_b = DAT_00009bb6;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b59;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b78;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009b97;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b3a;
  }
  if (local_b == 3) {
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
                   + (uint)local_b * 0x15 + 0x1047);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== FUN_fffd1eb1 @ fffd1eb1 (235 bytes)

void FUN_fffd1eb1(byte param_1,byte *param_2)

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
    local_b = DAT_00009bb7;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b5a;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b79;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009b98;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b3b;
  }
  if (local_b == 0) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0x14;
  param_2[2] = 0;
  if (3 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x10b0);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== FUN_fffd1fdd @ fffd1fdd (234 bytes)

void FUN_fffd1fdd(byte param_1,byte *param_2)

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
    local_b = DAT_00009bb8;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b5b;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b7a;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009b99;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b3c;
  }
  if (local_b == 0) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 4;
  param_2[2] = 0;
  if (1 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (int)(&DAT_00002328 + (uint)local_b * 0x15));
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
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
  menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
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
  menu_step_u8(0,4,local_8);
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
  menu_step_u8(0,3,local_8);
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
  menu_step_u8(0,1,local_8);
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
  menu_step_u8(0,199,local_8);
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
  menu_step_u8(0,199,local_8);
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
  menu_step_u8(0,199,local_8);
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
  menu_step_u8(0,0x13,local_8);
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
  menu_step_u8(0,1,local_8);
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
  menu_step_u8(0,0x43,local_8);
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
  menu_step_u8(0,1,local_8);
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
  menu_step_u8(0,100,local_8);
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
  menu_step_u8(0,100,local_8);
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
  menu_step_u8(0,4,local_8);
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
  menu_step_u8(0,3,local_8);
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
  menu_step_u8(0,100,local_8);
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
  menu_step_u8(0,100,local_8);
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
  menu_step_u8(0,3,local_8);
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
    beep_request(3);
    FUN_fffc8f30(0);
  }
  return local_3;
}

