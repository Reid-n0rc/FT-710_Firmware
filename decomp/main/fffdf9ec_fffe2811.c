// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffdf9ec @ fffdf9ec (248 bytes)

ushort FUN_fffdf9ec(char param_1)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  ushort local_e;
  char local_b [4];
  char local_7;
  byte local_6;
  char local_5;
  char local_1;
  
  local_1 = param_1;
  local_b[0] = 'M';
  local_b[1] = 'D';
  local_b[2] = '0';
  local_7 = ';';
  local_e = 0;
  if (param_1 == '\0') {
    if (DAT_00009dbd == '\0') {
      local_6 = DAT_00009d09 & 0xf;
    }
    else {
      local_6 = DAT_00009d63 & 0xf;
    }
    if (DAT_000187e5 == local_6) {
      return 0;
    }
    DAT_000187e5 = local_6;
    local_e = 5;
    local_b[2] = 0x30;
  }
  else if (param_1 == '\x01') {
    if (DAT_00009dbd == '\0') {
      local_6 = DAT_00009d63 & 0xf;
    }
    else {
      local_6 = DAT_00009d09 & 0xf;
    }
    if (DAT_000187e6 == local_6) {
      return 0;
    }
    DAT_000187e6 = local_6;
    local_e = 5;
    local_b[2] = 0x31;
  }
  local_5 = "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
            [local_6 + 0x3d14];
  local_b[3] = "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
               [local_6 + 0x3d14];
  if (local_e != 0) {
    pcVar2 = local_b;
    pcVar1 = &DAT_00015e06;
    for (uVar3 = (uint)local_e; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  return local_e;
}


// ===== FUN_fffdfae4 @ fffdfae4 (256 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdfbe1) */
/* WARNING: Removing unreachable block (ram,0xfffdfba4) */
/* WARNING: Removing unreachable block (ram,0xfffdfbc8) */

undefined2 FUN_fffdfae4(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  char local_c [8];
  
  builtin_strncpy(local_c,"MG000;",6);
  bVar2 = FUN_fffb3196(0);
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fffdfb48:
    bStack_15 = DAT_00009bed;
  }
  else {
    if (uVar1 - 4 < 2) {
      bStack_15 = DAT_00009bee;
      goto LAB_fffdfb64;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffdfb48;
      if (1 < uVar1 - 10) {
        if (1 < uVar1) {
          return 0;
        }
        bStack_15 = DAT_00009bec;
        goto LAB_fffdfb64;
      }
    }
    bStack_15 = DAT_00009bef;
  }
LAB_fffdfb64:
  if (DAT_000187e7 == bStack_15) {
    uStack_1a = uStack_18;
  }
  else {
    DAT_000187e7 = bStack_15;
    bStack_14 = 100;
    for (bStack_13 = 0; bStack_13 < 3; bStack_13 = bStack_13 + 1) {
      bVar2 = bStack_15;
      if (bStack_14 != 0) {
        bVar2 = bStack_15 / bStack_14;
      }
      bStack_15 = bStack_15 - bVar2 * bStack_14;
      bStack_14 = bStack_14 / 10;
      cVar3 = nib2hex(bVar2);
      local_c[bStack_13 + 2] = cVar3;
    }
    pcVar5 = local_c;
    pcVar4 = &DAT_00015e06;
    for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pcVar4 = *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    uStack_1a = 6;
  }
  return uStack_1a;
}


// ===== FUN_fffdfbe4 @ fffdfbe4 (338 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdfd33) */
/* WARNING: Removing unreachable block (ram,0xfffdfcef) */
/* WARNING: Removing unreachable block (ram,0xfffdfd1c) */

undefined2 FUN_fffdfbe4(void)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char acStack_18 [11];
  byte bStack_d;
  undefined1 *local_c;
  
  local_c = &DAT_00009bca;
  bStack_d = FUN_fffb3196(0);
  acStack_18[0] = 'M';
  acStack_18[1] = 'L';
  builtin_strncpy(acStack_18 + 3,"000;",4);
  uVar2 = (uint)bStack_d;
  if (uVar2 == 0xe) {
LAB_fffdfc6d:
    acStack_18[10] = local_c[0x35];
  }
  else {
    if (uVar2 - 2 < 2) {
      acStack_18[10] = local_c[0x33];
      goto LAB_fffdfc82;
    }
    if (uVar2 - 4 < 2) {
      acStack_18[10] = local_c[0x36];
      goto LAB_fffdfc82;
    }
    if (1 < uVar2 - 6) {
      if (uVar2 - 8 < 2) goto LAB_fffdfc6d;
      if (1 < uVar2 - 10) {
        if (uVar2 - 0xc < 2) {
          acStack_18[10] = local_c[0x34];
        }
        else if (uVar2 < 2) {
          acStack_18[10] = local_c[0x32];
        }
        goto LAB_fffdfc82;
      }
    }
    acStack_18[10] = local_c[0x37];
  }
LAB_fffdfc82:
  bVar1 = acStack_18[10] != 0;
  if (bVar1) {
    acStack_18[7] = 1;
  }
  else {
    acStack_18[7] = 0;
  }
  if ((bool)DAT_000187e8 == bVar1) {
    if (DAT_000187e9 == acStack_18[10]) {
      return 0;
    }
    DAT_000187e9 = acStack_18[10];
    acStack_18[2] = 0x31;
    acStack_18[9] = 100;
    for (acStack_18[8] = 0; (byte)acStack_18[8] < 3; acStack_18[8] = acStack_18[8] + 1) {
      acStack_18[7] = acStack_18[10];
      if (acStack_18[9] != 0) {
        acStack_18[7] = (byte)acStack_18[10] / (byte)acStack_18[9];
      }
      acStack_18[10] = acStack_18[10] - acStack_18[7] * acStack_18[9];
      acStack_18[9] = (byte)acStack_18[9] / 10;
      uVar2 = (uint)(byte)acStack_18[8];
      cVar3 = nib2hex(acStack_18[7]);
      acStack_18[uVar2 + 3] = cVar3;
    }
  }
  else {
    acStack_18[2] = 0x30;
    DAT_000187e8 = bVar1;
    acStack_18[7] = bVar1;
    acStack_18[5] = nib2hex(bVar1);
  }
  pcVar5 = acStack_18;
  pcVar4 = &DAT_00015e06;
  for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pcVar4 = *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return 7;
}


// ===== FUN_fffdfd36 @ fffdfd36 (110 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdfd86) */

undefined2 FUN_fffdfd36(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 local_c;
  char local_8 [8];
  
  builtin_strncpy(local_8,"MS00;",5);
  local_8[5] = DAT_00009c5b;
  if (DAT_000187ea == DAT_00009c5b) {
    local_c = 0;
  }
  else {
    DAT_000187ea = DAT_00009c5b;
    local_8[2] = nib2hex(DAT_00009c5b);
    pcVar2 = local_8;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    local_c = 5;
  }
  return local_c;
}


// ===== FUN_fffdfda4 @ fffdfda4 (102 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdfdec) */

undefined2 FUN_fffdfda4(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 local_c;
  undefined2 local_a;
  char local_7 [7];
  
  builtin_strncpy(local_7,"MX0;",4);
  local_7[4] = DAT_00020b2c;
  if (DAT_000187eb == DAT_00020b2c) {
    local_c = local_a;
  }
  else {
    DAT_000187eb = DAT_00020b2c;
    local_7[2] = nib2hex(DAT_00020b2c);
    pcVar2 = local_7;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    local_c = 4;
  }
  return local_c;
}


// ===== FUN_fffdfe0a @ fffdfe0a (112 bytes)

ushort FUN_fffdfe0a(void)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  ushort local_a;
  char local_7 [7];
  
  builtin_strncpy(local_7,"NA00;",5);
  local_a = 0;
  if (DAT_0001b51d != DAT_00009c65._3_1_) {
    DAT_0001b51d = DAT_00009c65._3_1_;
    local_7[3] = nib2hex(DAT_00009c65._3_1_);
    local_a = 5;
  }
  if (local_a != 0) {
    pcVar2 = local_7;
    pcVar1 = &DAT_00015e06;
    for (uVar3 = (uint)local_a; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  return local_a;
}


// ===== FUN_fffdfe7a @ fffdfe7a (108 bytes)

ushort FUN_fffdfe7a(void)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  ushort uStack_10;
  char acStack_e [6];
  int iStack_8;
  
  iStack_8 = FUN_fffb324c(0);
  builtin_strncpy(acStack_e,"NB00;",5);
  uStack_10 = 0;
  uVar1 = (*(byte *)(iStack_8 + 2) & 2) >> 1;
  acStack_e[5] = (char)uVar1;
  if (DAT_000187ec != acStack_e[5]) {
    DAT_000187ec = acStack_e[5];
    acStack_e[3] = nib2hex(uVar1);
    uStack_10 = 5;
  }
  if (uStack_10 != 0) {
    pcVar3 = acStack_e;
    pcVar2 = &DAT_00015e06;
    for (uVar1 = (uint)uStack_10; uVar1 != 0; uVar1 = uVar1 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return uStack_10;
}


// ===== FUN_fffdfee6 @ fffdfee6 (182 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdff99) */
/* WARNING: Removing unreachable block (ram,0xfffdff51) */
/* WARNING: Removing unreachable block (ram,0xfffdff7a) */

undefined2 FUN_fffdfee6(void)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined2 local_16;
  char local_11 [8];
  byte local_9;
  byte local_8;
  byte local_7;
  
  builtin_strncpy(local_11,"NL0000;",7);
  local_11[7] = DAT_00009dc0;
  if (DAT_000187ed == DAT_00009dc0) {
    local_16 = 0;
  }
  else {
    DAT_000187ed = DAT_00009dc0;
    local_8 = 10;
    for (local_9 = 0; local_9 < 2; local_9 = local_9 + 1) {
      local_7 = local_11[7];
      if (local_8 != 0) {
        local_7 = (byte)local_11[7] / local_8;
      }
      local_11[7] = local_11[7] - local_7 * local_8;
      local_8 = local_8 / 10;
      uVar1 = (uint)local_9;
      cVar2 = nib2hex(local_7);
      local_11[uVar1 + 4] = cVar2;
    }
    pcVar4 = local_11;
    pcVar3 = &DAT_00015e06;
    for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pcVar3 = *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    }
    local_16 = 7;
  }
  return local_16;
}


// ===== FUN_fffdff9c @ fffdff9c (122 bytes)

/* WARNING: Removing unreachable block (ram,0xfffdfff5) */

undefined2 FUN_fffdff9c(void)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined2 uStack_12;
  char acStack_e [6];
  int iStack_8;
  
  iStack_8 = FUN_fffb324c(0);
  uVar1 = (*(byte *)(iStack_8 + 6) & 0x10) >> 4;
  acStack_e[5] = (char)uVar1;
  builtin_strncpy(acStack_e,"NR00;",5);
  if (DAT_000187ee == acStack_e[5]) {
    uStack_12 = 0;
  }
  else {
    DAT_000187ee = acStack_e[5];
    acStack_e[3] = nib2hex(uVar1);
    pcVar3 = acStack_e;
    pcVar2 = &DAT_00015e06;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    uStack_12 = 5;
  }
  return uStack_12;
}


// ===== FUN_fffe0016 @ fffe0016 (168 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe009d) */

undefined2 FUN_fffe0016(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 local_e;
  char local_9 [6];
  char local_3;
  
  local_9[0] = 'O';
  local_9[1] = 'S';
  local_9[2] = '0';
  local_9[4] = ';';
  local_9[5] = DAT_00009dbd;
  if (DAT_00009dbd == '\0') {
    local_3 = (char)((DAT_00009d0b & 0xc) >> 2);
  }
  else {
    local_3 = (char)((DAT_00009d65 & 0xc) >> 2);
  }
  if (DAT_000187ef == local_3) {
    local_e = 0;
  }
  else {
    DAT_000187ef = local_3;
    if (local_3 == '\0') {
      local_9[3] = 0x32;
    }
    else if (local_3 == '\x02') {
      local_9[3] = 0x31;
    }
    else {
      local_9[3] = 0x30;
    }
    pcVar2 = local_9;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    local_e = 5;
  }
  return local_e;
}


// ===== FUN_fffe00be @ fffe00be (133 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe0122) */

undefined2 FUN_fffe00be(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uStack_12;
  char acStack_e [6];
  int iStack_8;
  
  iStack_8 = FUN_fffb324c(0);
  acStack_e[0] = 'P';
  acStack_e[1] = 'A';
  acStack_e[2] = '0';
  acStack_e[4] = ';';
  acStack_e[5] = *(byte *)(iStack_8 + 5) & 3;
  if (DAT_000187f0 == acStack_e[5]) {
    uStack_12 = 0;
  }
  else {
    if (acStack_e[5] == 2) {
      acStack_e[3] = 0x31;
    }
    else if (acStack_e[5] == 3) {
      acStack_e[3] = 0x32;
    }
    else {
      acStack_e[3] = 0x30;
    }
    pcVar2 = acStack_e;
    pcVar1 = &DAT_00015e06;
    DAT_000187f0 = acStack_e[5];
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    uStack_12 = 5;
  }
  return uStack_12;
}


// ===== FUN_fffe0143 @ fffe0143 (264 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe0248) */
/* WARNING: Removing unreachable block (ram,0xfffe0200) */
/* WARNING: Removing unreachable block (ram,0xfffe0229) */

undefined2 FUN_fffe0143(void)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  undefined2 uStack_20;
  char acStack_1c [7];
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  char cStack_12;
  char cStack_11;
  undefined4 uStack_10;
  undefined1 *local_c;
  
  local_c = &DAT_00009bca;
  uStack_10 = FUN_fffb357c(0,2);
  cStack_11 = FUN_fffb3196(0);
  builtin_strncpy(acStack_1c,"PC000;",6);
  cStack_12 = FUN_fffb3371(uStack_10);
  if ((cStack_11 == '\x04') || (cStack_11 == '\x05')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    acStack_1c[6] = local_c[0x31];
  }
  else if (cStack_12 == '\t') {
    acStack_1c[6] = local_c[0x2f];
  }
  else if (cStack_12 == '\n') {
    acStack_1c[6] = local_c[0x30];
  }
  else {
    acStack_1c[6] = local_c[0x2e];
  }
  if (DAT_000187f1 == acStack_1c[6]) {
    uStack_20 = 0;
  }
  else {
    DAT_000187f1 = acStack_1c[6];
    bStack_15 = 100;
    for (bStack_14 = 0; bStack_14 < 3; bStack_14 = bStack_14 + 1) {
      bStack_13 = acStack_1c[6];
      if (bStack_15 != 0) {
        bStack_13 = (byte)acStack_1c[6] / bStack_15;
      }
      acStack_1c[6] = acStack_1c[6] - bStack_13 * bStack_15;
      bStack_15 = bStack_15 / 10;
      uVar1 = (uint)bStack_14;
      cVar3 = nib2hex(bStack_13);
      acStack_1c[uVar1 + 2] = cVar3;
    }
    pcVar5 = acStack_1c;
    pcVar4 = &DAT_00015e06;
    for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pcVar4 = *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    }
    uStack_20 = 6;
  }
  return uStack_20;
}


// ===== FUN_fffe024b @ fffe024b (169 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe02f1) */
/* WARNING: Removing unreachable block (ram,0xfffe02b2) */

ushort FUN_fffe024b(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  byte bVar5;
  ushort local_12;
  byte local_10;
  byte local_f;
  byte local_e;
  char local_c [8];
  
  builtin_strncpy(local_c,"PL000;",6);
  local_12 = 0;
  local_10 = DAT_00009bf1;
  if (DAT_000187f2 != DAT_00009bf1) {
    DAT_000187f2 = DAT_00009bf1;
    local_e = 100;
    for (local_f = 0; local_f < 3; local_f = local_f + 1) {
      bVar5 = local_10;
      if (local_e != 0) {
        bVar5 = local_10 / local_e;
      }
      local_10 = local_10 - bVar5 * local_e;
      local_e = local_e / 10;
      cVar1 = nib2hex(bVar5);
      local_c[local_f + 2] = cVar1;
    }
    local_c[5] = 0x3b;
    local_12 = 6;
  }
  if (local_12 != 0) {
    pcVar3 = local_c;
    pcVar2 = &DAT_00015e06;
    for (uVar4 = (uint)local_12; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return local_12;
}


// ===== FUN_fffe02f4 @ fffe02f4 (160 bytes)

ushort FUN_fffe02f4(void)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  ushort local_a;
  char local_8 [8];
  
  builtin_strncpy(local_8,"PR00;",5);
  local_a = 0;
  local_8[5] = DAT_00009bf1;
  if (DAT_00009bf1 != '\0') {
    local_8[5] = '\x01';
  }
  if (DAT_000187f3 != local_8[5]) {
    DAT_000187f3 = local_8[5];
    local_8[2] = 0x30;
    local_8[3] = nib2hex(local_8[5]);
    local_a = 5;
  }
  local_8[5] = DAT_00009bf0;
  if (DAT_000187f4 != DAT_00009bf0) {
    DAT_000187f4 = DAT_00009bf0;
    local_8[2] = 0x31;
    local_8[3] = nib2hex(DAT_00009bf0);
    local_a = 5;
  }
  if (local_a != 0) {
    pcVar2 = local_8;
    pcVar1 = &DAT_00015e06;
    for (uVar3 = (uint)local_a; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  return local_a;
}


// ===== FUN_fffe0394 @ fffe0394 (119 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe03ea) */

undefined2 FUN_fffe0394(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uStack_12;
  char acStack_e [6];
  int iStack_8;
  
  iStack_8 = FUN_fffb324c(0);
  builtin_strncpy(acStack_e,"RA00;",5);
  acStack_e[5] = *(byte *)(iStack_8 + 3) & 3;
  if (DAT_000187f5 == acStack_e[5]) {
    uStack_12 = 0;
  }
  else {
    DAT_000187f5 = acStack_e[5];
    acStack_e[3] = nib2hex(acStack_e[5]);
    pcVar2 = acStack_e;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    uStack_12 = 5;
  }
  return uStack_12;
}


// ===== FUN_fffe040b @ fffe040b (368 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe0578) */
/* WARNING: Removing unreachable block (ram,0xfffe0531) */
/* WARNING: Removing unreachable block (ram,0xfffe055a) */

undefined2 FUN_fffe040b(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  undefined2 local_18;
  char local_12 [8];
  byte local_a;
  byte local_9;
  byte local_8;
  byte local_7;
  
  bVar3 = DAT_00020ba7;
  builtin_strncpy(local_12,"RG0000;",7);
  if (DAT_00009ab6 == '\0') {
    local_12[7] = DAT_00020ba7;
    if (DAT_000187f6 == DAT_00020ba7) {
      local_18 = 0;
    }
    else {
      DAT_000187f6 = DAT_00020ba7;
      DAT_0001b51e = DAT_0001b51e + 1;
      if (3 < DAT_0001b51e) {
        DAT_0001b51e = 0;
      }
      (&DAT_0001b542)[DAT_0001b51e] = DAT_00020ba7;
      if ((bVar3 < 3) || (0xfc < bVar3)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        if ((DAT_0001b542 == DAT_0001b544) || (DAT_0001b543 == DAT_0001b545)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          return 0;
        }
        bVar3 = FUN_fffe1805(&DAT_0001b542);
        bVar4 = FUN_fffe1839(&DAT_0001b542);
        if ((int)((uint)bVar3 - (uint)bVar4) < 3) {
          return 0;
        }
      }
      local_a = DAT_000187f6;
      local_8 = 100;
      for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
        local_7 = local_a;
        if (local_8 != 0) {
          local_7 = local_a / local_8;
        }
        local_a = local_a - local_7 * local_8;
        local_8 = local_8 / 10;
        uVar1 = (uint)local_9;
        cVar5 = nib2hex(local_7);
        local_12[uVar1 + 3] = cVar5;
      }
      pcVar7 = local_12;
      pcVar6 = &DAT_00015e06;
      for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
        *pcVar6 = *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      local_18 = 7;
    }
  }
  else {
    local_18 = 0;
  }
  return local_18;
}


// ===== FUN_fffe057b @ fffe057b (474 bytes)

ushort FUN_fffe057b(void)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  ushort local_12;
  char cStack_e;
  char acStack_d [4];
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_6;
  char cStack_5;
  undefined1 uStack_4;
  
  pcVar4 = 
  "RI00000000;RL000;RM0000000;SC0;SD00;SF00;SH0000;SQ0000;SS0000000;ST0;TS0;TX0;VD00;VG000;VS0;VX0;     RM 1"
  ;
  pcVar3 = acStack_d;
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar3 = *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  }
  local_12 = 0;
  bVar1 = DAT_00020b6d != '\0';
  if ((bool)s_RI00000000__0001b51f[0xb] != bVar1) {
    local_12 = 0xb;
    s_RI00000000__0001b51f[0xb] = bVar1;
  }
  acStack_d[3] = nib2hex(bVar1);
  cVar2 = FUN_fffe0755();
  if (DAT_0001b52b != cVar2) {
    local_12 = 0xb;
    DAT_0001b52b = cVar2;
  }
  uStack_9 = nib2hex(cVar2);
  if (DAT_0001b52c != DAT_00020b3d) {
    DAT_0001b52c = DAT_00020b3d;
    local_12 = 0xb;
  }
  uStack_8 = nib2hex(DAT_00020b3d);
  if ((DAT_00020b40 == '\x02') || (DAT_00020b41 == '\x02')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    cVar2 = '\x01';
  }
  else {
    cVar2 = '\0';
  }
  if (DAT_0001b52d != cVar2) {
    local_12 = 0xb;
    DAT_0001b52d = cVar2;
  }
  uStack_6 = nib2hex(cVar2);
  if (DAT_00020f1c == '\0') {
    cStack_e = '0';
  }
  else {
    if ((DAT_00020f1d == '\x01') && (iVar5 = FUN_fffb722b(), iVar5 != 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      cStack_e = '2';
    }
    else {
      cStack_e = '1';
    }
  }
  if (DAT_0001b52f != cStack_e) {
    DAT_0001b52f = cStack_e;
    local_12 = 0xb;
  }
  cStack_5 = cStack_e;
  if (DAT_0001b52e != (DAT_00020b38 & 0x10)) {
    local_12 = 0xb;
    DAT_0001b52e = DAT_00020b38 & 0x10;
  }
  if ((DAT_00020b38 & 0x10) == 0) {
    uStack_4 = 0x30;
  }
  else {
    uStack_4 = 0x31;
  }
  if (local_12 != 0) {
    pcVar4 = acStack_d;
    pcVar3 = &DAT_00015e06;
    for (uVar6 = (uint)local_12; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar3 = *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    }
    iVar5 = FUN_fffede1d(s_RI00000000__0001b51f,acStack_d,0xb);
    if (iVar5 == 0) {
      return 0;
    }
    pcVar4 = acStack_d;
    pcVar3 = s_RI00000000__0001b51f;
    for (uVar6 = (uint)local_12; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar3 = *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    }
  }
  return local_12;
}


// ===== FUN_fffe0755 @ fffe0755 (228 bytes)

undefined1 FUN_fffe0755(void)

{
  bool bVar1;
  undefined1 local_2;
  
  if ((DAT_00020ccd == '\x01') || (DAT_00020b7c == '\x02')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b96 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_2 = 1;
  }
  else {
    if ((DAT_00020cd0 == '\x01') || (DAT_00020cd1 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020f01 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020f01 == '\x02')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020f01 == '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b7c == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_2 = 2;
    }
    else {
      local_2 = 0;
    }
  }
  return local_2;
}


// ===== FUN_fffe0839 @ fffe0839 (142 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe0884) */
/* WARNING: Removing unreachable block (ram,0xfffe0892) */
/* WARNING: Removing unreachable block (ram,0xfffe08a9) */

undefined2 FUN_fffe0839(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uStack_14;
  char acStack_f [7];
  int iStack_8;
  
  iStack_8 = FUN_fffb324c(0);
  builtin_strncpy(acStack_f,"RL000;",6);
  acStack_f[6] = *(byte *)(iStack_8 + 6) & 0xf;
  if (DAT_000187f7 == acStack_f[6]) {
    uStack_14 = 0;
  }
  else {
    DAT_000187f7 = acStack_f[6];
    acStack_f[3] = nib2hex((byte)acStack_f[6] / 10);
    acStack_f[4] = nib2hex();
    pcVar2 = acStack_f;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    uStack_14 = 6;
  }
  return uStack_14;
}


// ===== FUN_fffe08c7 @ fffe08c7 (409 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe0a5d) */
/* WARNING: Removing unreachable block (ram,0xfffe0a1d) */

ushort FUN_fffe08c7(void)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  byte bVar6;
  char local_18;
  byte bStack_16;
  byte bStack_15;
  ushort local_14;
  undefined4 local_11;
  undefined4 local_d;
  undefined2 local_9;
  byte local_7;
  
  local_9 = 0x3b30;
  local_d = 0x30303030;
  local_11 = 0x30304d52;
  local_14 = 0;
  if (DAT_00009c5b == '\x01') {
    local_18 = '\x03';
  }
  else if (DAT_00009c5b == '\x02') {
    local_18 = '\x04';
  }
  else if (DAT_00009c5b == '\x03') {
    local_18 = '\b';
  }
  else if (DAT_00009c5b == '\x04') {
    local_18 = '\a';
  }
  else if (DAT_00009c5b == '\x05') {
    local_18 = '\x06';
  }
  else {
    local_18 = '\x05';
  }
  if (DAT_00020b3d != '\x01') {
    local_18 = '\x01';
  }
  if (local_18 == '\b') {
    local_7 = FUN_fffb6e03();
  }
  else if (local_18 == '\x03') {
    local_7 = FUN_fffb6e98();
  }
  else if (local_18 == '\x04') {
    local_7 = FUN_fffb6e21();
  }
  else if (local_18 == '\x05') {
    local_7 = FUN_fffb6e6a();
  }
  else if (local_18 == '\x06') {
    local_7 = FUN_fffb6e30();
  }
  else if (local_18 == '\a') {
    local_7 = FUN_fffb6e12();
  }
  else if (local_18 == '\x01') {
    local_7 = FUN_fffb6ea7();
  }
  else {
    local_7 = 0;
  }
  if (DAT_000187f8 != local_7) {
    DAT_000187f8 = local_7;
    DAT_0001b530 = DAT_0001b530 + 1;
    if (3 < DAT_0001b530) {
      DAT_0001b530 = 0;
    }
    (&DAT_0001b546)[DAT_0001b530] = local_7;
    if ((DAT_0001b546 == DAT_0001b548) && (DAT_0001b547 == DAT_0001b549)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return 0;
    }
    bStack_15 = 100;
    for (bStack_16 = 0; bStack_16 < 3; bStack_16 = bStack_16 + 1) {
      bVar6 = local_7;
      if (bStack_15 != 0) {
        bVar6 = local_7 / bStack_15;
      }
      local_7 = local_7 - bVar6 * bStack_15;
      bStack_15 = bStack_15 / 10;
      uVar2 = nib2hex(bVar6);
      *(undefined1 *)((int)&local_11 + bStack_16 + 3) = uVar2;
    }
    local_14 = 10;
  }
  if (local_14 != 0) {
    puVar4 = &local_11;
    puVar3 = &DAT_00015e06;
    for (uVar5 = (uint)local_14; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar3 = *(undefined1 *)puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  return local_14;
}


// ===== FUN_fffe0a60 @ fffe0a60 (159 bytes)

ushort FUN_fffe0a60(void)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  ushort uStack_10;
  char acStack_e [5];
  char cStack_9;
  undefined4 uStack_8;
  
  uStack_8 = FUN_fffb324c(0);
  builtin_strncpy(acStack_e,"SC0;",4);
  uStack_10 = 0;
  cStack_9 = DAT_00020f1c;
  acStack_e[4] = FUN_fffe5d0e();
  if ((DAT_000187f9 == cStack_9) && (acStack_e[4] == DAT_000187fa)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_000187f9 = cStack_9;
    if (cStack_9 == '\x01') {
      if (acStack_e[4] == '\0') {
        acStack_e[2] = 0x31;
      }
      else {
        acStack_e[2] = 0x32;
      }
    }
    else {
      acStack_e[2] = 0x30;
    }
    uStack_10 = 4;
    DAT_000187fa = acStack_e[4];
  }
  if (uStack_10 != 0) {
    pcVar3 = acStack_e;
    pcVar2 = &DAT_00015e06;
    for (uVar4 = (uint)uStack_10; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return uStack_10;
}


// ===== FUN_fffe0aff @ fffe0aff (162 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe0b9e) */
/* WARNING: Removing unreachable block (ram,0xfffe0b62) */

ushort FUN_fffe0aff(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  ushort local_12;
  char local_f [6];
  byte local_9;
  byte local_8;
  byte local_7;
  
  builtin_strncpy(local_f,"SD00;",5);
  local_12 = 0;
  local_f[5] = DAT_00009c05;
  if (DAT_000187fb != DAT_00009c05) {
    DAT_000187fb = DAT_00009c05;
    local_8 = 10;
    for (local_9 = 0; local_9 < 2; local_9 = local_9 + 1) {
      local_7 = local_f[5];
      if (local_8 != 0) {
        local_7 = (byte)local_f[5] / local_8;
      }
      local_f[5] = local_f[5] - local_7 * local_8;
      local_8 = local_8 / 10;
      uVar4 = (uint)local_9;
      cVar1 = nib2hex(local_7);
      local_f[uVar4 + 2] = cVar1;
    }
    local_12 = 5;
  }
  if (local_12 != 0) {
    pcVar3 = local_f;
    pcVar2 = &DAT_00015e06;
    for (uVar4 = (uint)local_12; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return local_12;
}


// ===== FUN_fffe0ba1 @ fffe0ba1 (357 bytes)

ushort FUN_fffe0ba1(char param_1)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  ushort local_c;
  char local_9 [8];
  char local_1;
  
  local_1 = param_1;
  builtin_strncpy(local_9,"SF00;",5);
  if (param_1 == '\0') {
    if (DAT_000187fc == DAT_00009dc9) {
      return 0;
    }
    DAT_000187fc = DAT_00009dc9;
    local_c = 5;
    switch(DAT_00009dc9) {
    case '\0':
      local_9[3] = 0x31;
      break;
    case '\x01':
      local_9[3] = 0x32;
      break;
    default:
      local_9[3] = 0x30;
      break;
    case '\x03':
      local_9[3] = 0x33;
      break;
    case '\x04':
      local_9[3] = 0x34;
      break;
    case '\x05':
      local_9[3] = 0x35;
      break;
    case '\x06':
      local_9[3] = 0x36;
      break;
    case '\a':
      local_9[3] = 0x37;
      break;
    case '\t':
      local_9[3] = 0x38;
      break;
    case '\n':
      local_9[3] = 0x39;
      break;
    case '\v':
      local_9[3] = 0x41;
      break;
    case '\f':
      local_9[3] = 0x42;
      break;
    case '\r':
      local_9[3] = 0x43;
      break;
    case '\x0e':
      local_9[3] = 0x44;
      break;
    case '\x0f':
      local_9[3] = 0x45;
      break;
    case '\x12':
      local_9[3] = 0x46;
      break;
    case '\x13':
      local_9[3] = 0x47;
      break;
    case '\x14':
      local_9[3] = 0x48;
    }
  }
  else if (param_1 == '\x01') {
    if (DAT_000187fd == DAT_00020b7e) {
      return 0;
    }
    DAT_000187fd = DAT_00020b7e;
    local_c = 5;
    local_9[2] = 0x31;
    if (DAT_00020b7e == '\x1d') {
      local_9[3] = 0x31;
    }
    else if (DAT_00020b7e == '\x1e') {
      local_9[3] = 0x32;
    }
    else if (DAT_00020b7e == '\x1f') {
      local_9[3] = 0x33;
    }
    else if (DAT_00020b7e == ' ') {
      local_9[3] = 0x34;
    }
    else if (DAT_00020b7e == '!') {
      local_9[3] = 0x35;
    }
    else {
      local_9[3] = 0x30;
    }
  }
  if (local_c != 0) {
    pcVar2 = local_9;
    pcVar1 = &DAT_00015e06;
    for (uVar3 = (uint)local_c; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  return local_c;
}


// ===== FUN_fffe0d06 @ fffe0d06 (403 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe0e96) */
/* WARNING: Removing unreachable block (ram,0xfffe0e5b) */
/* WARNING: Removing unreachable block (ram,0xfffe0d93) */
/* WARNING: Removing unreachable block (ram,0xfffe0df2) */
/* WARNING: Removing unreachable block (ram,0xfffe0d61) */
/* WARNING: Removing unreachable block (ram,0xfffe0dc2) */

ushort FUN_fffe0d06(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  ushort uStack_1c;
  char acStack_1a [11];
  undefined1 uStack_f;
  undefined2 uStack_e;
  int iStack_c;
  
  iStack_c = FUN_fffb324c(0);
  uStack_f = FUN_fffb3196(0);
  builtin_strncpy(acStack_1a,"SH0000;",7);
  uStack_1c = 0;
  uStack_e = 0;
  switch(uStack_f) {
  case 0:
  case 1:
    uStack_e = CONCAT11(*(undefined1 *)(iStack_c + 0x10),*(undefined1 *)(iStack_c + 0x11));
    cVar1 = FUN_fffb36ff(uStack_f,uStack_e);
    acStack_1a[7] = cVar1 + 1U;
    if (0x17 < (byte)(cVar1 + 1U)) {
      acStack_1a[7] = 0;
    }
    break;
  case 2:
  case 3:
    uStack_e = CONCAT11(*(undefined1 *)(iStack_c + 0x1a),*(undefined1 *)(iStack_c + 0x1b));
    cVar1 = FUN_fffb36ff(uStack_f,uStack_e);
    acStack_1a[7] = cVar1 + 1U;
    if (0x15 < (byte)(cVar1 + 1U)) {
      acStack_1a[7] = 0;
    }
    break;
  case 4:
  case 7:
  case 0xb:
    acStack_1a[7] = 2;
    break;
  case 5:
    acStack_1a[7] = 1;
    break;
  case 6:
  case 10:
    acStack_1a[7] = 3;
    break;
  case 8:
  case 9:
  case 0xe:
    uStack_e = CONCAT11(*(undefined1 *)(iStack_c + 0x2e),*(undefined1 *)(iStack_c + 0x2f));
    cVar1 = FUN_fffb36ff(uStack_f,uStack_e);
    acStack_1a[7] = cVar1 + 1U;
    if (0x15 < (byte)(cVar1 + 1U)) {
      acStack_1a[7] = 0;
    }
    break;
  case 0xc:
  case 0xd:
    uStack_e = CONCAT11(*(undefined1 *)(iStack_c + 0x24),*(undefined1 *)(iStack_c + 0x25));
    cVar1 = FUN_fffb36ff(uStack_f,uStack_e);
    acStack_1a[7] = cVar1 + 1U;
    if (0x15 < (byte)(cVar1 + 1U)) {
      acStack_1a[7] = 0;
    }
  }
  if (DAT_000187fe != acStack_1a[7]) {
    DAT_000187fe = acStack_1a[7];
    acStack_1a[9] = 10;
    for (acStack_1a[8] = 0; (byte)acStack_1a[8] < 2; acStack_1a[8] = acStack_1a[8] + 1) {
      acStack_1a[10] = acStack_1a[7];
      if (acStack_1a[9] != 0) {
        acStack_1a[10] = (byte)acStack_1a[7] / (byte)acStack_1a[9];
      }
      acStack_1a[7] = acStack_1a[7] - acStack_1a[10] * acStack_1a[9];
      acStack_1a[9] = (byte)acStack_1a[9] / 10;
      uVar4 = (uint)(byte)acStack_1a[8];
      cVar1 = nib2hex(acStack_1a[10]);
      acStack_1a[uVar4 + 4] = cVar1;
    }
    uStack_1c = 7;
  }
  if (uStack_1c != 0) {
    pcVar3 = acStack_1a;
    pcVar2 = &DAT_00015e06;
    for (uVar4 = (uint)uStack_1c; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return uStack_1c;
}


// ===== FUN_fffe0e99 @ fffe0e99 (333 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe0fe3) */
/* WARNING: Removing unreachable block (ram,0xfffe0fa4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_fffe0e99(void)

{
  uint uVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined2 local_1c;
  undefined4 local_17;
  undefined2 local_13;
  char local_11;
  float local_10;
  byte local_b;
  byte local_a;
  byte local_9;
  byte local_8;
  byte local_7;
  
  local_17 = 0x30305153;
  local_13 = 0x3030;
  local_11 = ';';
  if (DAT_00009ab6 == '\0') {
    local_1c = 0;
  }
  else {
    local_b = DAT_00020ba7;
    local_10 = ((float)DAT_00020ba7 * 100.0) / 255.0;
    local_a = SUB41(ROUND(local_10 + 0.5),0);
    if (DAT_000187ff == local_a) {
      local_1c = 0;
    }
    else {
      DAT_0001b531 = DAT_0001b531 + 1;
      if (3 < DAT_0001b531) {
        DAT_0001b531 = 0;
      }
      DAT_000187ff = local_a;
      (&DAT_0001b54a)[DAT_0001b531] = local_a;
      if ((DAT_0001b54a == DAT_0001b54c) && (DAT_0001b54b == DAT_0001b54d)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        local_1c = 0;
      }
      else {
        local_8 = 100;
        for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
          local_7 = local_a;
          if (local_8 != 0) {
            local_7 = local_a / local_8;
          }
          local_a = local_a - local_7 * local_8;
          local_8 = local_8 / 10;
          uVar1 = (uint)local_9;
          uVar3 = nib2hex(local_7);
          *(undefined1 *)((int)&local_17 + uVar1 + 3) = uVar3;
        }
        DAT_00015e0c = local_11;
        DAT_00015e0a = local_13;
        _DAT_00015e06 = local_17;
        local_1c = 7;
      }
    }
  }
  return local_1c;
}


// ===== FUN_fffe0fe6 @ fffe0fe6 (1121 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1444) */
/* WARNING: Removing unreachable block (ram,0xfffe12f3) */
/* WARNING: Removing unreachable block (ram,0xfffe12fe) */
/* WARNING: Removing unreachable block (ram,0xfffe12fd) */
/* WARNING: Removing unreachable block (ram,0xfffe11d5) */
/* WARNING: Removing unreachable block (ram,0xfffe127e) */
/* WARNING: Removing unreachable block (ram,0xfffe12ba) */
/* WARNING: Removing unreachable block (ram,0xfffe12bd) */
/* WARNING: Removing unreachable block (ram,0xfffe12c1) */
/* WARNING: Removing unreachable block (ram,0xfffe12c4) */
/* WARNING: Removing unreachable block (ram,0xfffe12c3) */
/* WARNING: Removing unreachable block (ram,0xfffe12cf) */
/* WARNING: Removing unreachable block (ram,0xfffe12ce) */
/* WARNING: Removing unreachable block (ram,0xfffe12bf) */
/* WARNING: Removing unreachable block (ram,0xfffe12dc) */
/* WARNING: Removing unreachable block (ram,0xfffe12db) */
/* WARNING: Removing unreachable block (ram,0xfffe12e7) */
/* WARNING: Removing unreachable block (ram,0xfffe12e6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_fffe0fe6(char param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  ushort local_22;
  undefined4 local_1f;
  undefined4 local_1b;
  undefined2 local_17;
  byte bStack_15;
  byte *pbStack_14;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  byte local_d;
  undefined4 uStack_c;
  char local_5;
  
  local_5 = param_1;
  local_17 = 0x3b30;
  local_1b = 0x30303030;
  local_1f = 0x30305353;
  local_22 = 0;
  if (param_1 == '\0') {
    iVar2 = FUN_fffc4f8f();
    if (iVar2 == 1) {
      local_d = '\x05';
    }
    else {
      local_d = DAT_00009c5a;
    }
    if (DAT_0001b532 == local_d) {
      return 0;
    }
    DAT_0001b532 = local_d;
    local_22 = 10;
    local_1f = CONCAT13(0x30,(undefined3)local_1f);
    uVar1 = nib2hex(local_d);
    local_1b = CONCAT31(local_1b._1_3_,uVar1);
  }
  else if (param_1 == '\x01') {
    local_d = DAT_00009be6;
    if (DAT_0001b533 == DAT_00009be6) {
      return 0;
    }
    DAT_0001b533 = DAT_00009be6;
    local_22 = 10;
    local_1f = 0x31305353;
    uVar1 = nib2hex(DAT_00009be6);
    local_1b = CONCAT31(local_1b._1_3_,uVar1);
  }
  else if (param_1 == '\x02') {
    local_d = DAT_00009be7;
    if (DAT_0001b534 == DAT_00009be7) {
      return 0;
    }
    DAT_0001b534 = DAT_00009be7;
    local_22 = 10;
    local_1f = 0x32305353;
    uVar1 = nib2hex(DAT_00009be7);
    local_1b = CONCAT31(local_1b._1_3_,uVar1);
  }
  else if (param_1 == '\x03') {
    local_d = DAT_00009be8;
    if (DAT_0001b535 == DAT_00009be8) {
      return 0;
    }
    DAT_0001b535 = DAT_00009be8;
    local_22 = 10;
    local_1f = 0x33305353;
    uVar1 = nib2hex(DAT_00009be8);
    local_1b = CONCAT31(local_1b._1_3_,uVar1);
  }
  else if (param_1 == '\x04') {
    uStack_c = FUN_fffb357c(DAT_00020b6b,2);
    pbStack_14 = (byte *)FUN_fffa150c(uStack_c,DAT_00020b6b);
    local_1f = CONCAT13(0x34,(undefined3)local_1f);
    if (DAT_00020b6b == '\0') {
      if (DAT_0001b536 == *pbStack_14) {
        return 0;
      }
      DAT_0001b536 = *pbStack_14;
    }
    else {
      if (DAT_0001b537 == *pbStack_14) {
        return 0;
      }
      DAT_0001b537 = *pbStack_14;
    }
    local_22 = 10;
    if (*pbStack_14 < 0x3c) {
      local_1b = CONCAT31(local_1b._1_3_,0x2d);
      local_d = 0x3c - *pbStack_14;
    }
    else {
      local_1b = CONCAT31(local_1b._1_3_,0x2b);
      local_d = *pbStack_14 - 0x3c;
    }
    bStack_10 = local_d >> 1;
    bStack_e = 10;
    for (bStack_f = 0; bStack_f < 2; bStack_f = bStack_f + 1) {
      bStack_15 = bStack_10;
      if (bStack_e != 0) {
        bStack_15 = bStack_10 / bStack_e;
      }
      bStack_10 = bStack_10 - bStack_15 * bStack_e;
      bStack_e = bStack_e / 10;
      uVar5 = (uint)bStack_f;
      uVar1 = nib2hex(bStack_15);
      *(undefined1 *)((int)&local_1b + uVar5 + 1) = uVar1;
    }
    local_1b = CONCAT13(0x2e,(undefined3)local_1b);
    if ((local_d & 1) == 0) {
      local_17 = CONCAT11(local_17._1_1_,0x30);
    }
    else {
      local_17 = CONCAT11(local_17._1_1_,0x35);
    }
  }
  else if (param_1 == '\x05') {
    uStack_c = FUN_fffb357c(0,2);
    pbStack_14 = (byte *)FUN_fffa1541(uStack_c);
    if (DAT_0001b538 == *pbStack_14) {
      return 0;
    }
    DAT_0001b538 = *pbStack_14;
    local_22 = 10;
    local_1f = CONCAT13(0x35,(undefined3)local_1f);
    uVar1 = nib2hex(*pbStack_14);
    local_1b = CONCAT31(local_1b._1_3_,uVar1);
  }
  else if (param_1 == '\x06') {
    if (DAT_00009c35 == '\0') {
      _DAT_0000464f = 1;
    }
    if (DAT_00009c36 == '\0') {
      if (DAT_00009c38 == '\0') {
        local_d = '\x03';
      }
      else if (DAT_00009c38 == '\x01') {
        local_d = '\x04';
      }
      else {
        local_d = '\x05';
      }
    }
    else {
      local_d = '\0';
    }
    if (DAT_0001b539 == local_d) {
      return 0;
    }
    DAT_0001b539 = local_d;
    local_22 = 10;
    local_1f = 0x36305353;
    uVar1 = nib2hex(local_d);
    local_1b = CONCAT31(local_1b._1_3_,uVar1);
  }
  else if (param_1 == '\a') {
    local_1f = 0x37305353;
    local_d = DAT_00009c39;
    if (DAT_0001b53a != DAT_00009c39) {
      DAT_0001b53a = DAT_00009c39;
      local_22 = 10;
    }
    uVar1 = nib2hex(DAT_00009c39);
    local_1b = CONCAT31(local_1b._1_3_,uVar1);
    local_d = DAT_00009c3b;
    if (DAT_00018800 != DAT_00009c3b) {
      DAT_00018800 = DAT_00009c3b;
      local_22 = 10;
    }
    uVar1 = nib2hex(DAT_00009c3b);
    local_1b._0_2_ = CONCAT11(uVar1,(undefined1)local_1b);
    local_d = DAT_00009c3c;
    if (DAT_0001b53b != DAT_00009c3c) {
      DAT_0001b53b = DAT_00009c3c;
      local_22 = 10;
    }
    uVar1 = nib2hex(DAT_00009c3c);
    local_1b._0_3_ = CONCAT12(uVar1,(undefined2)local_1b);
    local_d = DAT_00009c3a;
    if (DAT_00018801 != DAT_00009c3a) {
      DAT_00018801 = DAT_00009c3a;
      local_22 = 10;
    }
    uVar1 = nib2hex(DAT_00009c3a);
    local_1b = CONCAT13(uVar1,(undefined3)local_1b);
  }
  else if (param_1 == '\b') {
    local_d = DAT_00020f1f;
    if (DAT_0001b53c == DAT_00020f1f) {
      return 0;
    }
    DAT_0001b53c = DAT_00020f1f;
    local_22 = 10;
    local_1f = 0x38305353;
    uVar1 = nib2hex(DAT_00020f1f);
    local_1b = CONCAT31(local_1b._1_3_,uVar1);
  }
  if (local_22 != 0) {
    puVar4 = &local_1f;
    puVar3 = &DAT_00015e06;
    for (uVar5 = (uint)local_22; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar3 = *(undefined1 *)puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  return local_22;
}


// ===== FUN_fffe1447 @ fffe1447 (109 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe149b) */

undefined2 FUN_fffe1447(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 local_c;
  char local_a [7];
  char local_3;
  
  local_3 = DAT_00009c5e;
  local_a[0] = 'S';
  local_a[1] = 'T';
  local_a[3] = ';';
  if (DAT_00018802 == DAT_00009c5e) {
    local_c = 0;
  }
  else {
    DAT_00018802 = DAT_00009c5e;
    local_a[4] = '\x04';
    local_a[5] = '\0';
    if (DAT_00009c5e == '\0') {
      local_a[2] = 0x30;
    }
    else {
      local_a[2] = 0x31;
    }
    pcVar2 = local_a;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    local_c = 4;
  }
  return local_c;
}


// ===== FUN_fffe14b4 @ fffe14b4 (111 bytes)

ushort FUN_fffe14b4(void)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  ushort local_8;
  char local_6 [6];
  
  builtin_strncpy(local_6,"TS0;",4);
  local_8 = 0;
  if (DAT_0001b53d != DAT_00020f09) {
    DAT_0001b53d = DAT_00020f09;
    if (DAT_00020f09 == '\x01') {
      local_6[2] = 0x31;
    }
    else {
      local_6[2] = 0x30;
    }
    local_8 = 4;
  }
  if (local_8 != 0) {
    pcVar2 = local_6;
    pcVar1 = &DAT_00015e06;
    for (uVar3 = (uint)local_8; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  return local_8;
}


// ===== FUN_fffe1523 @ fffe1523 (115 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe157d) */

undefined2 FUN_fffe1523(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uStack_c;
  char acStack_7 [7];
  
  acStack_7[4] = FUN_fffb6ec5();
  acStack_7[0] = 'T';
  acStack_7[1] = 'X';
  acStack_7[3] = ';';
  if (DAT_00018803 == acStack_7[4]) {
    uStack_c = 0;
  }
  else {
    if (acStack_7[4] == '\0') {
      acStack_7[2] = 0x30;
    }
    else if (acStack_7[4] == '\x05') {
      acStack_7[2] = 0x31;
    }
    else {
      acStack_7[2] = 0x32;
    }
    pcVar2 = acStack_7;
    pcVar1 = &DAT_00015e06;
    DAT_00018803 = acStack_7[4];
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    uStack_c = 4;
  }
  return uStack_c;
}


// ===== FUN_fffe1596 @ fffe1596 (199 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe165a) */
/* WARNING: Removing unreachable block (ram,0xfffe161f) */
/* WARNING: Removing unreachable block (ram,0xfffe1643) */

undefined2 FUN_fffe1596(void)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined2 local_14;
  char local_10 [6];
  byte local_a;
  byte local_9;
  byte local_8;
  byte local_7;
  
  local_10[5] = DAT_00009af3;
  builtin_strncpy(local_10,"VD00;",5);
  if (DAT_00009af3 == '\0') {
    local_a = DAT_00009bf4;
  }
  else {
    local_a = DAT_00009bf5;
  }
  if (DAT_00018804 == local_a) {
    local_14 = 0;
  }
  else {
    DAT_00018804 = local_a;
    local_8 = 10;
    for (local_9 = 0; local_9 < 2; local_9 = local_9 + 1) {
      local_7 = local_a;
      if (local_8 != 0) {
        local_7 = local_a / local_8;
      }
      local_a = local_a - local_7 * local_8;
      local_8 = local_8 / 10;
      uVar1 = (uint)local_9;
      cVar2 = nib2hex(local_7);
      local_10[uVar1 + 2] = cVar2;
    }
    pcVar4 = local_10;
    pcVar3 = &DAT_00015e06;
    for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pcVar3 = *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    }
    local_14 = 5;
  }
  return local_14;
}


// ===== FUN_fffe165d @ fffe165d (173 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1707) */
/* WARNING: Removing unreachable block (ram,0xfffe16cc) */
/* WARNING: Removing unreachable block (ram,0xfffe16f0) */

undefined2 FUN_fffe165d(void)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined2 local_14;
  char local_10 [7];
  byte local_9;
  byte local_8;
  byte local_7;
  
  builtin_strncpy(local_10,"VG000;",6);
  local_10[6] = DAT_00009bf3;
  if (DAT_00018805 == DAT_00009bf3) {
    local_14 = 0;
  }
  else {
    DAT_00018805 = DAT_00009bf3;
    local_8 = 100;
    for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
      local_7 = local_10[6];
      if (local_8 != 0) {
        local_7 = (byte)local_10[6] / local_8;
      }
      local_10[6] = local_10[6] - local_7 * local_8;
      local_8 = local_8 / 10;
      uVar1 = (uint)local_9;
      cVar2 = nib2hex(local_7);
      local_10[uVar1 + 2] = cVar2;
    }
    pcVar4 = local_10;
    pcVar3 = &DAT_00015e06;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pcVar3 = *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    }
    local_14 = 6;
  }
  return local_14;
}


// ===== FUN_fffe170a @ fffe170a (106 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1756) */

undefined2 FUN_fffe170a(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 local_c;
  char local_7 [7];
  
  builtin_strncpy(local_7,"VS0;",4);
  local_7[4] = DAT_00009dbd;
  if (DAT_00018806 == DAT_00009dbd) {
    local_c = 0;
  }
  else {
    DAT_00018806 = DAT_00009dbd;
    local_7[2] = nib2hex(DAT_00009dbd);
    pcVar2 = local_7;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    local_c = 4;
  }
  return local_c;
}


// ===== FUN_fffe1774 @ fffe1774 (145 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe17e5) */

undefined2 FUN_fffe1774(void)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined2 uStack_12;
  char acStack_e [6];
  undefined4 uStack_8;
  
  uStack_8 = FUN_fffb324c(0);
  acStack_e[5] = FUN_fffb3196(1);
  builtin_strncpy(acStack_e,"VX0;",4);
  uVar1 = (uint)(byte)acStack_e[5];
  if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
    acStack_e[4] = '\0';
  }
  else {
    acStack_e[4] = DAT_00009c5d;
  }
  if (DAT_00018807 == acStack_e[4]) {
    uStack_12 = 0;
  }
  else {
    DAT_00018807 = acStack_e[4];
    acStack_e[2] = nib2hex(acStack_e[4]);
    pcVar3 = acStack_e;
    pcVar2 = &DAT_00015e06;
    for (iVar4 = 4; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    uStack_12 = 4;
  }
  return uStack_12;
}


// ===== FUN_fffe1805 @ fffe1805 (52 bytes)

byte FUN_fffe1805(byte *param_1)

{
  byte local_7;
  byte local_6;
  
  local_6 = *param_1;
  for (local_7 = 0; local_7 < 4; local_7 = local_7 + 1) {
    if (local_6 < param_1[local_7]) {
      local_6 = param_1[local_7];
    }
  }
  return local_6;
}


// ===== FUN_fffe1839 @ fffe1839 (52 bytes)

byte FUN_fffe1839(byte *param_1)

{
  byte local_7;
  byte local_6;
  
  local_6 = *param_1;
  for (local_7 = 0; local_7 < 4; local_7 = local_7 + 1) {
    if (param_1[local_7] < local_6) {
      local_6 = param_1[local_7];
    }
  }
  return local_6;
}


// ===== FUN_fffe1a00 @ fffe1a00 (904 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1d52) */

void FUN_fffe1a00(char param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte local_9;
  byte local_1;
  
  if (DAT_0001b54e == '\x01') {
    DAT_00018809 = DAT_00009dbe;
    DAT_0001880a = DAT_00009dbf;
    DAT_0001b54e = '\0';
  }
  if ((byte)PTR_DAT_00025d6c[0x468] < 2) {
    PTR_DAT_00025d6c[0x468] = 2;
  }
  if (param_1 == '\n') {
    FUN_fffe1e85();
    FUN_fffb2da6(1);
    return;
  }
  if (param_1 == '\v') {
    if (PTR_DAT_00025d6c[0x468] == '\x03') {
      PTR_DAT_00025d6c[0x410] = (byte)PTR_DAT_00025d6c[0x410] >> 4;
      PTR_DAT_00025d6c[0x468] = 4;
      FUN_fffe1e70();
      FUN_fffb2da6(1);
      return;
    }
    if (PTR_DAT_00025d6c[0x468] != '\x02') {
      FUN_fffe1e70();
      FUN_fffb2da6(1);
      return;
    }
    PTR_DAT_00025d6c[0x410] = 0;
    PTR_DAT_00025d6c[0x468] = 4;
    FUN_fffe1e70();
    FUN_fffb2da6(1);
    return;
  }
  if (param_1 != '\f') {
    if (param_1 != '\r') {
      if (param_1 != '\x0e') {
        local_1 = param_1 + 1;
        if (local_1 == 10) {
          local_1 = 0;
        }
        uVar7 = (uint)((byte)PTR_DAT_00025d6c[0x468] >> 1);
        if ((PTR_DAT_00025d6c[0x468] & 1) == 0) {
          PTR_DAT_00025d6c[uVar7 + 0x40f] = PTR_DAT_00025d6c[uVar7 + 0x40f] & 0xf | local_1 << 4;
        }
        else {
          PTR_DAT_00025d6c[uVar7 + 0x40f] = PTR_DAT_00025d6c[uVar7 + 0x40f] & 0xf0 | local_1;
        }
        if ((byte)PTR_DAT_00025d6c[0x468] < 9) {
          PTR_DAT_00025d6c[0x468] = PTR_DAT_00025d6c[0x468] + '\x01';
        }
        FUN_fffe1e70();
        FUN_fffb2da6(1);
        return;
      }
      DAT_00009dbe = DAT_00018809;
      DAT_00009dbf = DAT_0001880a;
      DAT_0001b54e = 1;
      FUN_fffc23b6();
      FUN_fffe1e70();
      FUN_fffb2da6(1);
      return;
    }
    for (local_9 = 1; local_9 < 5; local_9 = local_9 + 1) {
      if (0x90 < (PTR_DAT_00025d6c[local_9 + 0x40f] & 0xf0)) {
        PTR_DAT_00025d6c[local_9 + 0x40f] = PTR_DAT_00025d6c[local_9 + 0x40f] & 0xf;
      }
      if (9 < (PTR_DAT_00025d6c[local_9 + 0x40f] & 0xf)) {
        PTR_DAT_00025d6c[local_9 + 0x40f] = PTR_DAT_00025d6c[local_9 + 0x40f] & 0xf0;
      }
    }
    iVar3 = FUN_fffb2fc0(PTR_DAT_00025d6c[0x410]);
    iVar4 = FUN_fffb2fc0(PTR_DAT_00025d6c[0x411]);
    iVar5 = FUN_fffb2fc0(PTR_DAT_00025d6c[0x412]);
    iVar6 = FUN_fffb2fc0(PTR_DAT_00025d6c[0x413]);
    iVar3 = FUN_fffe1dd7(iVar6 + iVar5 * 100 + iVar4 * 10000 + iVar3 * 1000000);
    if (iVar3 != 0) {
      uVar1 = *(undefined4 *)(PTR_DAT_00025d6c + 0x464);
      FUN_fffe1da4(uVar1);
      if (PTR_DAT_00025d6c[0x414] == '\x01') {
        FUN_fffe1d96(uVar1);
      }
      PTR_DAT_00025d6c[0x40c] = 1;
      FUN_fffe1d88(uVar1);
      FUN_fffc23b6();
      FUN_fffc2fde(DAT_00009dbd);
      FUN_fffc16f6(DAT_00009dbd);
      FUN_fffe1e70();
      DAT_0001b54e = 1;
      FUN_fffb2da6(1);
      return;
    }
    FUN_fffe1e85();
    FUN_fffb2da6(3);
    return;
  }
  if (PTR_DAT_00025d6c[0x468] == '\x02') {
    FUN_fffe1e70();
    FUN_fffb2da6(3);
    return;
  }
  if ((PTR_DAT_00025d6c[0x468] == '\t') && ((PTR_DAT_00025d6c[0x413] & 0xf) != 0xf)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    uVar7 = (uint)((byte)PTR_DAT_00025d6c[0x468] >> 1);
    if ((PTR_DAT_00025d6c[0x468] & 1) == 0) {
      PTR_DAT_00025d6c[uVar7 + 0x40e] = PTR_DAT_00025d6c[uVar7 + 0x40e] | 0xf;
    }
    else {
      PTR_DAT_00025d6c[uVar7 + 0x40f] = 0xff;
    }
    PTR_DAT_00025d6c[0x468] = PTR_DAT_00025d6c[0x468] + -1;
    FUN_fffe1e70();
    FUN_fffb2da6(1);
    return;
  }
  PTR_DAT_00025d6c[0x413] = PTR_DAT_00025d6c[0x413] | 0xf;
  FUN_fffe1e70();
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffe1d88 @ fffe1d88 (14 bytes)

void FUN_fffe1d88(void)

{
  FUN_fffb4e18(1);
  return;
}


// ===== FUN_fffe1d96 @ fffe1d96 (14 bytes)

void FUN_fffe1d96(void)

{
  FUN_fffb4e18(2);
  return;
}


// ===== FUN_fffe1da4 @ fffe1da4 (51 bytes)

void FUN_fffe1da4(uint param_1)

{
  int iVar1;
  byte bStack_9;
  
  iVar1 = FUN_fffb324c(0);
  for (bStack_9 = 0; bStack_9 < 4; bStack_9 = bStack_9 + 1) {
    *(char *)((uint)bStack_9 + iVar1 + 0x4a) = (char)(param_1 >> ((3 - bStack_9 & 3) << 3));
  }
  return;
}


// ===== FUN_fffe1dd7 @ fffe1dd7 (153 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1e6d) */

bool FUN_fffe1dd7(undefined4 param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(PTR_DAT_00025d6c + 0x464) = param_1;
  cVar1 = DAT_00009dbd;
  if (DAT_00009dbd == '\0') {
    if (DAT_00009dbe == '\x02') {
      FUN_fffc5ce0(0);
    }
  }
  else if (DAT_00009dbf == '\x02') {
    FUN_fffc5ce0(DAT_00009dbd);
  }
  PTR_DAT_00025d6c[0x460] = 1;
  puVar2 = PTR_DAT_00025d6c;
  uVar3 = FUN_fffc10c3(cVar1,param_1);
  *(undefined4 *)(puVar2 + 0x464) = uVar3;
  PTR_DAT_00025d6c[0x460] = 0;
  return PTR_DAT_00025d6c[0x469] != '\x01';
}


// ===== FUN_fffe1e70 @ fffe1e70 (21 bytes)

void FUN_fffe1e70(void)

{
  DAT_00018808 = 1;
  FUN_fffb237a(0x46,&DAT_00002710);
  return;
}


// ===== FUN_fffe1e85 @ fffe1e85 (95 bytes)

void FUN_fffe1e85(void)

{
  PTR_DAT_00025d6c[0x40f] = 0xff;
  PTR_DAT_00025d6c[0x410] = 0xff;
  PTR_DAT_00025d6c[0x411] = 0xff;
  PTR_DAT_00025d6c[0x412] = 0xff;
  PTR_DAT_00025d6c[0x413] = 0xff;
  PTR_DAT_00025d6c[0x40d] = 1;
  FUN_fffe1e70();
  PTR_DAT_00025d6c[0x468] = 0;
  return;
}


// ===== FUN_fffe1ee4 @ fffe1ee4 (89 bytes)

void FUN_fffe1ee4(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_00018808 != '\0') {
    if ((PTR_DAT_00025d6c[0x40d] == '\x01') || (PTR_DAT_00025d6c[0x41d] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (iVar2 = FUN_fffb23f3(0x46), iVar2 == 1)) {
      DAT_00018808 = 0;
      FUN_fffc23b6();
      FUN_fffe1f3d();
      return;
    }
  }
  return;
}


// ===== FUN_fffe1f3d @ fffe1f3d (35 bytes)

void FUN_fffe1f3d(void)

{
  if (PTR_DAT_00025d6c[0x41d] != '\x01') {
    return;
  }
  PTR_DAT_00025d6c[0x41d] = 0;
  FUN_fffc8beb();
  return;
}


// ===== FUN_fffe207f @ fffe207f (538 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe20c9) */
/* WARNING: Removing unreachable block (ram,0xfffe20f0) */
/* WARNING: Removing unreachable block (ram,0xfffe225e) */

void FUN_fffe207f(char param_1)

{
  bool bVar1;
  byte bVar2;
  byte local_1;
  
  FUN_fffb2da6(1);
  if (param_1 == '\n') {
    PTR_DAT_00025d6c[0x411] = 0xff;
    PTR_DAT_00025d6c[0x412] = 0xff;
    PTR_DAT_00025d6c[0x468] = 0;
    FUN_fffe1e70();
    return;
  }
  if (param_1 == '\v') {
    if ((PTR_DAT_00025d6c[0x411] & 0xf0) == 0xa0) {
      PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] | 0xf0;
    }
    else {
      PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] & 0xaf | 0xa0;
    }
    FUN_fffe1e70();
    return;
  }
  if (param_1 != '\f') {
    if (param_1 != '\r') {
      if (param_1 == '\x0e') {
        FUN_fffc23b6();
        FUN_fffe1f3d();
        return;
      }
      local_1 = param_1 + 1;
      if (local_1 == 10) {
        local_1 = 0;
      }
      if (PTR_DAT_00025d6c[0x468] == '\0') {
        PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] & 0xf0 | local_1;
      }
      else {
        PTR_DAT_00025d6c[0x412] = PTR_DAT_00025d6c[0x412] & 0xf | local_1 << 4;
      }
      if (PTR_DAT_00025d6c[0x468] != '\x01') {
        PTR_DAT_00025d6c[0x468] = PTR_DAT_00025d6c[0x468] + '\x01';
      }
      FUN_fffe1e70();
      return;
    }
    if (PTR_DAT_00025d6c[0x412] == -1) {
      PTR_DAT_00025d6c[0x412] = PTR_DAT_00025d6c[0x411] << 4 | 0xf;
      PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] & 0xf0;
    }
    bVar2 = PTR_DAT_00025d6c[0x411] << 4 | (byte)PTR_DAT_00025d6c[0x412] >> 4;
    if (0x20 < bVar2) {
      FUN_fffe2299();
      FUN_fffe1e70();
      return;
    }
    FUN_fffb2fc0(bVar2);
    FUN_fffc23b6();
    FUN_fffe1f3d();
    return;
  }
  if (PTR_DAT_00025d6c[0x468] == '\0') {
    FUN_fffe1e70();
    return;
  }
  if ((PTR_DAT_00025d6c[0x468] == '\x01') && ((PTR_DAT_00025d6c[0x412] & 0xf0) != 0xf0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d6c[0x412] = PTR_DAT_00025d6c[0x412] | 0xf0;
    FUN_fffe1e70();
    return;
  }
  PTR_DAT_00025d6c[0x468] = 0;
  PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] | 0xf;
  PTR_DAT_00025d6c[0x412] = 0xff;
  FUN_fffe1e70();
  return;
}


// ===== FUN_fffe2299 @ fffe2299 (40 bytes)

void FUN_fffe2299(void)

{
  PTR_DAT_00025d6c[0x411] = 0xff;
  PTR_DAT_00025d6c[0x412] = 0xff;
  PTR_DAT_00025d6c[0x468] = 0;
  return;
}


// ===== FUN_fffe2622 @ fffe2622 (94 bytes)

void FUN_fffe2622(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d6c[0xbe];
  if (cVar1 == '\x06') {
    FUN_fffe2c33(param_1);
    return;
  }
  if (cVar1 == '\x01') {
    FUN_fffe273a(param_1);
    return;
  }
  if (cVar1 == '\x02') {
    FUN_fffe2811(param_1);
    return;
  }
  if (cVar1 == '\x03') {
    FUN_fffe2912(param_1);
    return;
  }
  if (cVar1 == '\x04') {
    FUN_fffe2918(param_1);
    return;
  }
  if (cVar1 == '\x05') {
    FUN_fffe291e(param_1);
    return;
  }
  if (cVar1 != '\0') {
    return;
  }
  FUN_fffe2680(param_1);
  return;
}


// ===== FUN_fffe2680 @ fffe2680 (186 bytes)

void FUN_fffe2680(char param_1)

{
  if (DAT_0001b54f == '\x01') {
    DAT_00018813 = DAT_00009b09;
    DAT_0001880f = DAT_00009b05;
    DAT_0001880b = DAT_00009b01;
    DAT_0001b54f = '\0';
  }
  FUN_fffe29b7(PTR_DAT_00025d6c + 0xc2,param_1);
  if (param_1 == -0x7c) {
    DAT_00009b09 = DAT_00018813;
    DAT_00009b05 = DAT_0001880f;
    DAT_00009b01 = DAT_0001880b;
    DAT_0001b54f = 1;
    return;
  }
  if (param_1 == -0x7b) {
    DAT_00009b09 = DAT_00020bce;
    DAT_00009b05 = DAT_00020bca;
    DAT_00009b01 = DAT_00020bc6;
    DAT_0001b54f = 1;
    return;
  }
  return;
}


// ===== FUN_fffe273a @ fffe273a (215 bytes)

void FUN_fffe273a(char param_1)

{
  int iVar1;
  
  if (DAT_0001b550 == '\x01') {
    DAT_0001881f = DAT_00020bce;
    DAT_0001881b = DAT_00020bca;
    DAT_00018817 = DAT_00020bc6;
    DAT_0001b550 = '\0';
  }
  FUN_fffe29b7(&DAT_00020bc6,param_1);
  if (param_1 == -0x7c) {
    DAT_00020bce = DAT_0001881f;
    DAT_00020bca = DAT_0001881b;
    DAT_00020bc6 = DAT_00018817;
    DAT_0001b550 = 1;
    return;
  }
  if (param_1 == -0x7b) {
    DAT_0001b550 = 1;
    iVar1 = (uint)(byte)PTR_DAT_00025d6c[0x43a] * 0x5a;
    *(undefined4 *)(&DAT_000061a6 + iVar1) = DAT_00020bce;
    *(undefined4 *)(&DAT_000061a2 + iVar1) = DAT_00020bca;
    *(undefined4 *)(&DAT_0000619e + iVar1) = DAT_00020bc6;
    eeprom_save_memch(PTR_DAT_00025d6c[0x43a]);
    return;
  }
  return;
}


// ===== FUN_fffe2811 @ fffe2811 (257 bytes)

void FUN_fffe2811(char param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puStack_c;
  
  puVar1 = (undefined1 *)((int)&DAT_00020bc6 + (uint)(byte)PTR_DAT_00025d6c[0xbf] * 0x32);
  if (DAT_0001b551 == '\x01') {
    puVar2 = &DAT_00018823;
    puVar3 = puVar1;
    for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    DAT_0001b551 = '\0';
  }
  FUN_fffe29b7(puVar1,param_1);
  if (param_1 == -0x7c) {
    if (PTR_DAT_00025d6c[0xbf] == '\0') {
      puStack_c = &DAT_000096a0;
    }
    else if (PTR_DAT_00025d6c[0xbf] == '\x01') {
      puStack_c = &DAT_000096d3;
    }
    else if (PTR_DAT_00025d6c[0xbf] == '\x02') {
      puStack_c = &DAT_00009706;
    }
    else if (PTR_DAT_00025d6c[0xbf] == '\x03') {
      puStack_c = &DAT_00009739;
    }
    else {
      puStack_c = &DAT_0000976c;
    }
    puVar1 = &DAT_00018823;
    for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puStack_c = *puVar1;
      puStack_c = puStack_c + 1;
      puVar1 = puVar1 + 1;
    }
    DAT_0001b551 = 1;
    return;
  }
  if (param_1 == -0x7b) {
    DAT_0001b551 = 1;
    FUN_fffe481d();
    return;
  }
  return;
}

