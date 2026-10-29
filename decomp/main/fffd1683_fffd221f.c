// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd1683 @ fffd1683 (116 bytes)

void FUN_fffd1683(void)

{
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e4] = 0x48;
  PTR_DAT_00025d60[0x1e5] = 0x10;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== FUN_fffd16f7 @ fffd16f7 (27 bytes)

void FUN_fffd16f7(void)

{
  PTR_DAT_00025d60[0x3f7] = 3;
  PTR_DAT_00025d60[0x406] = 1;
  return;
}


// ===== FUN_fffd1712 @ fffd1712 (126 bytes)

void FUN_fffd1712(void)

{
  PTR_DAT_00025d60[0x95] = 0;
  PTR_DAT_00025d60[0x90] = 0;
  PTR_DAT_00025d60[0x88] = 0;
  PTR_DAT_00025d60[0x86] = 0;
  PTR_DAT_00025d60[0x96] = 1;
  PTR_DAT_00025d60[0x1c5] = 0;
  if (PTR_DAT_00025d60[0x41f] != '\x05') {
    return;
  }
  PTR_DAT_00025d60[0x96] = 0;
  PTR_DAT_00025d60[0x1c2] = 5;
  FUN_fffc8cbb(5);
  FUN_fffc8d8c();
  return;
}


// ===== FUN_fffd1790 @ fffd1790 (94 bytes)

void FUN_fffd1790(char param_1)

{
  char cVar1;
  
  if (PTR_DAT_00025d60[0x88] == '\x01') {
    FUN_fffd17ee((int)param_1);
    return;
  }
  cVar1 = PTR_DAT_00025d60[0x3ff];
  if (cVar1 == '\x04') {
    FUN_fffd1a46((int)param_1);
    return;
  }
  if (cVar1 == '\x01') {
    FUN_fffd1943((int)param_1);
    return;
  }
  if (cVar1 == '\x02') {
    FUN_fffd199a((int)param_1);
    return;
  }
  if (cVar1 == '\x03') {
    FUN_fffd1a24((int)param_1);
    return;
  }
  if (cVar1 != '\0') {
    return;
  }
  FUN_fffd18a5((int)param_1);
  return;
}


// ===== FUN_fffd17ee @ fffd17ee (47 bytes)

void FUN_fffd17ee(char param_1)

{
  if (DAT_00015de3 == '\x04') {
    FUN_fffd1871((int)param_1);
    return;
  }
  if (DAT_00015de3 == '\x02') {
    FUN_fffd1847((int)param_1);
    return;
  }
  if (DAT_00015de3 != '\x01') {
    return;
  }
  FUN_fffd181d((int)param_1);
  return;
}


// ===== FUN_fffd181d @ fffd181d (42 bytes)

void FUN_fffd181d(char param_1)

{
  if (PTR_DAT_00025d60[0x3f7] != '\x02') {
    return;
  }
  if (param_1 < '\x01') {
    FUN_fffcfc50(1);
    return;
  }
  FUN_fffcfc50(0);
  return;
}


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
  byte bVar1;
  byte *pbVar2;
  
  bVar1 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pbVar2 = (byte *)menu_cursor_of(bVar1);
  if (pbVar2 != (byte *)0x0) {
    bVar1 = menu_count_items(bVar1);
    if ('\0' < param_1) {
      if ((int)(bVar1 - 1) <= (int)(uint)(byte)(*pbVar2 + pbVar2[1])) {
        PTR_DAT_00025d60[0x3ff] = 4;
        return;
      }
      if (*pbVar2 < 4) {
        *pbVar2 = *pbVar2 + 1;
        return;
      }
      pbVar2[1] = pbVar2[1] + 1;
      return;
    }
    if ((byte)(*pbVar2 + pbVar2[1]) != 0) {
      if (*pbVar2 != 0) {
        *pbVar2 = *pbVar2 - 1;
        return;
      }
      pbVar2[1] = pbVar2[1] - 1;
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
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  
  cVar1 = menu_count_items(PTR_DAT_00025d60[0x420]);
  if ((cVar1 != '\0') && (param_1 < '\0')) {
    bVar2 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
    bVar3 = menu_count_items(bVar2);
    pcVar4 = (char *)menu_cursor_of(bVar2);
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


// ===== menu_ex060101_draw @ fffd1be4 (13 bytes)

/* Menu item ex060101 PRESET NAME: on_draw (#74) */

void menu_ex060101_draw(void)

{
  FUN_fffd1c25(1);
  return;
}


// ===== menu_ex060201_draw @ fffd1bf1 (13 bytes)

/* Menu item ex060201 PRESET NAME: on_draw (#74) */

void menu_ex060201_draw(void)

{
  FUN_fffd1c25(2);
  return;
}


// ===== menu_ex060301_draw @ fffd1bfe (13 bytes)

/* Menu item ex060301 PRESET NAME: on_draw (#74) */

void menu_ex060301_draw(void)

{
  FUN_fffd1c25(3);
  return;
}


// ===== menu_ex060401_draw @ fffd1c0b (13 bytes)

/* Menu item ex060401 PRESET NAME: on_draw (#74) */

void menu_ex060401_draw(void)

{
  FUN_fffd1c25(4);
  return;
}


// ===== menu_ex060501_draw @ fffd1c18 (13 bytes)

/* Menu item ex060501 PRESET NAME: on_draw (#74) */

void menu_ex060501_draw(void)

{
  FUN_fffd1c25(5);
  return;
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


// ===== menu_ex060102_draw @ fffd1d45 (13 bytes)

/* Menu item ex060102 CAT-1 RATE: on_draw (#74) */

void menu_ex060102_draw(void)

{
  FUN_fffd1d86(1);
  return;
}


// ===== menu_ex060202_draw @ fffd1d52 (13 bytes)

/* Menu item ex060202 CAT-1 RATE: on_draw (#74) */

void menu_ex060202_draw(void)

{
  FUN_fffd1d86(2);
  return;
}


// ===== menu_ex060302_draw @ fffd1d5f (13 bytes)

/* Menu item ex060302 CAT-1 RATE: on_draw (#74) */

void menu_ex060302_draw(void)

{
  FUN_fffd1d86(3);
  return;
}


// ===== menu_ex060402_draw @ fffd1d6c (13 bytes)

/* Menu item ex060402 CAT-1 RATE: on_draw (#74) */

void menu_ex060402_draw(void)

{
  FUN_fffd1d86(4);
  return;
}


// ===== menu_ex060502_draw @ fffd1d79 (13 bytes)

/* Menu item ex060502 CAT-1 RATE: on_draw (#74) */

void menu_ex060502_draw(void)

{
  FUN_fffd1d86(5);
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


// ===== menu_ex060103_draw @ fffd1e70 (13 bytes)

/* Menu item ex060103 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060103_draw(void)

{
  FUN_fffd1eb1(1);
  return;
}


// ===== menu_ex060203_draw @ fffd1e7d (13 bytes)

/* Menu item ex060203 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060203_draw(void)

{
  FUN_fffd1eb1(2);
  return;
}


// ===== menu_ex060303_draw @ fffd1e8a (13 bytes)

/* Menu item ex060303 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060303_draw(void)

{
  FUN_fffd1eb1(3);
  return;
}


// ===== menu_ex060403_draw @ fffd1e97 (13 bytes)

/* Menu item ex060403 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060403_draw(void)

{
  FUN_fffd1eb1(4);
  return;
}


// ===== menu_ex060503_draw @ fffd1ea4 (13 bytes)

/* Menu item ex060503 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060503_draw(void)

{
  FUN_fffd1eb1(5);
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


// ===== menu_ex060104_draw @ fffd1f9c (13 bytes)

/* Menu item ex060104 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060104_draw(void)

{
  FUN_fffd1fdd(1);
  return;
}


// ===== menu_ex060204_draw @ fffd1fa9 (13 bytes)

/* Menu item ex060204 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060204_draw(void)

{
  FUN_fffd1fdd(2);
  return;
}


// ===== menu_ex060304_draw @ fffd1fb6 (13 bytes)

/* Menu item ex060304 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060304_draw(void)

{
  FUN_fffd1fdd(3);
  return;
}


// ===== menu_ex060404_draw @ fffd1fc3 (13 bytes)

/* Menu item ex060404 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060404_draw(void)

{
  FUN_fffd1fdd(4);
  return;
}


// ===== menu_ex060504_draw @ fffd1fd0 (13 bytes)

/* Menu item ex060504 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060504_draw(void)

{
  FUN_fffd1fdd(5);
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


// ===== menu_ex060105_draw @ fffd20c7 (13 bytes)

/* Menu item ex060105 AGC FAST DELAY: on_draw (#74) */

void menu_ex060105_draw(void)

{
  FUN_fffd2108(1);
  return;
}


// ===== menu_ex060205_draw @ fffd20d4 (13 bytes)

/* Menu item ex060205 AGC FAST DELAY: on_draw (#74) */

void menu_ex060205_draw(void)

{
  FUN_fffd2108(2);
  return;
}


// ===== menu_ex060305_draw @ fffd20e1 (13 bytes)

/* Menu item ex060305 AGC FAST DELAY: on_draw (#74) */

void menu_ex060305_draw(void)

{
  FUN_fffd2108(3);
  return;
}


// ===== menu_ex060405_draw @ fffd20ee (13 bytes)

/* Menu item ex060405 AGC FAST DELAY: on_draw (#74) */

void menu_ex060405_draw(void)

{
  FUN_fffd2108(4);
  return;
}


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

