// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe5a47 @ fffe5a47 (107 bytes)

void FUN_fffe5a47(void)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  
  uVar2 = DAT_00009dbd;
  PTR_DAT_00025d7c[0x419] = 1;
  iVar3 = FUN_fffe5f82();
  if ((iVar3 == 0) || (iVar3 = FUN_fffc2d93(uVar2), iVar3 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffb2da6(6);
    if (DAT_00009ac5 == '\x01') {
      FUN_fffe5ece();
      DAT_00018877 = 6;
      return;
    }
    DAT_00018877 = 4;
    return;
  }
  FUN_fffe5d7c();
  FUN_fffe5eba();
  return;
}


// ===== FUN_fffe5ab2 @ fffe5ab2 (29 bytes)

bool FUN_fffe5ab2(void)

{
  return DAT_00020b48 == '\x01';
}


// ===== FUN_fffe5acf @ fffe5acf (24 bytes)

bool FUN_fffe5acf(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb722b();
  return iVar1 == 1;
}


// ===== FUN_fffe5ae7 @ fffe5ae7 (24 bytes)

bool FUN_fffe5ae7(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb722b();
  return iVar1 == 1;
}


// ===== FUN_fffe5aff @ fffe5aff (82 bytes)

undefined1 FUN_fffe5aff(void)

{
  undefined1 local_4;
  undefined1 local_3;
  
  if (DAT_00009ac4 == '\0') {
    local_4 = 0;
  }
  else {
    if (DAT_00009dbd == '\0') {
      local_3 = DAT_00009dbe;
    }
    else {
      local_3 = DAT_00009dbf;
    }
    if (local_3 == '\x02') {
      local_4 = FUN_fffe5b51();
    }
    else {
      local_4 = 1;
    }
  }
  return local_4;
}


// ===== FUN_fffe5b51 @ fffe5b51 (213 bytes)

undefined1 FUN_fffe5b51(void)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  undefined1 uStack_7;
  
  if (DAT_00009ac2 == '\0') {
    uStack_7 = FUN_fffe5c26(0,99);
  }
  else {
    bVar2 = FUN_fff9bfb8();
    if (bVar2 < 8) {
      if (bVar2 == 7) {
        sVar3 = FUN_fffb3b33();
        if ((sVar3 == -0x26b0) || (sVar3 == -0x5b3b)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_7 = FUN_fffe5c26(0x75,7);
        }
        else {
          if ((sVar3 == 0x315b) || (sVar3 == 0x50e2)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            uStack_7 = FUN_fffe5c26(0x75,0xf);
          }
          else {
            uStack_7 = 0;
          }
        }
      }
      else if (bVar2 == 6) {
        uStack_7 = FUN_fffe5c26(99,0x12);
      }
      else {
        uStack_7 = FUN_fffe5c26("RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                                [bVar2 + 0x3d92],(&UNK_fff872ab)[bVar2]);
      }
    }
    else {
      uStack_7 = 0;
    }
  }
  return uStack_7;
}


// ===== FUN_fffe5c26 @ fffe5c26 (88 bytes)

undefined1 FUN_fffe5c26(byte param_1,byte param_2)

{
  int iVar1;
  byte local_5;
  byte local_4;
  
  local_5 = 0;
  local_4 = 0;
  while( true ) {
    if (param_2 <= local_4) {
      return 0;
    }
    iVar1 = FUN_fffc2e01(*(undefined1 *)((uint)param_1 + (uint)local_4));
    if (((iVar1 == 1) &&
        (iVar1 = FUN_fffe5e3b(*(undefined1 *)((uint)param_1 + (uint)local_4)), iVar1 == 0)) &&
       (local_5 = local_5 + 1, 1 < local_5)) break;
    local_4 = local_4 + 1;
  }
  return 1;
}


// ===== FUN_fffe5c7e @ fffe5c7e (49 bytes)

void FUN_fffe5c7e(void)

{
  DAT_00018876 = 0;
  DAT_00018877 = 0;
  if (PTR_DAT_00025d7c[0x418] != '\0') {
    return;
  }
  PTR_DAT_00025d7c[0x418] = 1;
  return;
}


// ===== FUN_fffe5caf @ fffe5caf (49 bytes)

void FUN_fffe5caf(void)

{
  DAT_00018876 = 1;
  DAT_00018877 = 0;
  if (PTR_DAT_00025d7c[0x418] != '\0') {
    return;
  }
  PTR_DAT_00025d7c[0x418] = 1;
  return;
}


// ===== FUN_fffe5ce0 @ fffe5ce0 (46 bytes)

void FUN_fffe5ce0(void)

{
  PTR_DAT_00025d7c[0x418] = 0;
  PTR_DAT_00025d7c[0x419] = 0;
  FUN_fffb2da6(6);
  PTR_DAT_00025d7c[0x40c] = 1;
  return;
}


// ===== FUN_fffe5d0e @ fffe5d0e (28 bytes)

bool FUN_fffe5d0e(void)

{
  return DAT_00018876 != '\0';
}


// ===== FUN_fffe5d2a @ fffe5d2a (37 bytes)

void FUN_fffe5d2a(void)

{
  if (DAT_00020f80 == '\0') {
    if (DAT_00018876 == '\x01') {
      FUN_fffe5c7e();
      return;
    }
  }
  else if (DAT_00018876 == '\0') {
    FUN_fffe5caf();
    return;
  }
  return;
}


// ===== FUN_fffe5d4f @ fffe5d4f (45 bytes)

undefined1 FUN_fffe5d4f(void)

{
  undefined1 local_2;
  
  if (DAT_00018877 == 4) {
    local_2 = 1;
  }
  else if (DAT_00018877 < 5) {
    local_2 = 0;
  }
  else {
    local_2 = 1;
  }
  return local_2;
}


// ===== FUN_fffe5d7c @ fffe5d7c (19 bytes)

void FUN_fffe5d7c(void)

{
  if (DAT_00018876 != '\0') {
    FUN_fffe5dd5();
    return;
  }
  FUN_fffe5d8f();
  return;
}


// ===== FUN_fffe5d8f @ fffe5d8f (70 bytes)

void FUN_fffe5d8f(void)

{
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = DAT_00009dbd;
  iVar2 = FUN_fffc2d93(DAT_00009dbd);
  if (iVar2 == 1) {
    do {
      PTR_DAT_00025d7c[0x47c] = 0;
      FUN_fffc54cc(1,DAT_00009dbd);
      iVar2 = FUN_fffe5e1b();
    } while (iVar2 == 1);
    return;
  }
  FUN_fffc809d(uVar1);
  return;
}


// ===== FUN_fffe5dd5 @ fffe5dd5 (70 bytes)

void FUN_fffe5dd5(void)

{
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = DAT_00009dbd;
  iVar2 = FUN_fffc2d93(DAT_00009dbd);
  if (iVar2 == 1) {
    do {
      PTR_DAT_00025d7c[0x47c] = 1;
      FUN_fffc54cc(1,DAT_00009dbd);
      iVar2 = FUN_fffe5e1b();
    } while (iVar2 == 1);
    return;
  }
  FUN_fffc8141(uVar1);
  return;
}


// ===== FUN_fffe5e1b @ fffe5e1b (32 bytes)

undefined1 FUN_fffe5e1b(void)

{
  undefined1 uVar1;
  
  uVar1 = FUN_fffc2e65(DAT_00009dbd);
  uVar1 = FUN_fffe5e3b(uVar1);
  return uVar1;
}


// ===== FUN_fffe5e3b @ fffe5e3b (44 bytes)

bool FUN_fffe5e3b(byte param_1)

{
  return ((&DAT_00006151)[(uint)param_1 * 0x5a] & 0x80) != 0;
}


// ===== FUN_fffe5e67 @ fffe5e67 (83 bytes)

void FUN_fffe5e67(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc2d93(DAT_00009dbd);
  if (iVar1 == 1) {
    DAT_00018873 = 1;
    FUN_fffb237a(0x33,0xfa);
    return;
  }
  iVar1 = FUN_fffe5fab();
  DAT_00018873 = 1;
  if (iVar1 != 1) {
    FUN_fffb237a(0x33,5);
    return;
  }
  FUN_fffb237a(0x33,0x32);
  return;
}


// ===== FUN_fffe5eba @ fffe5eba (20 bytes)

void FUN_fffe5eba(void)

{
  DAT_00018873 = 1;
  FUN_fffb237a(0x33,0x19);
  return;
}


// ===== FUN_fffe5ece @ fffe5ece (21 bytes)

void FUN_fffe5ece(void)

{
  DAT_00018875 = 1;
  FUN_fffb237a(0x35,&DAT_00001388);
  return;
}


// ===== FUN_fffe5ee3 @ fffe5ee3 (53 bytes)

undefined1 FUN_fffe5ee3(void)

{
  int iVar1;
  undefined1 local_2;
  
  if (DAT_00018873 == '\x01') {
    iVar1 = FUN_fffb23f3(0x33);
    if (iVar1 == 1) {
      DAT_00018873 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe5f18 @ fffe5f18 (53 bytes)

undefined1 FUN_fffe5f18(void)

{
  int iVar1;
  undefined1 local_2;
  
  if (DAT_00018874 == '\x01') {
    iVar1 = FUN_fffb23f3(0x34);
    if (iVar1 == 1) {
      DAT_00018874 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe5f4d @ fffe5f4d (53 bytes)

undefined1 FUN_fffe5f4d(void)

{
  int iVar1;
  undefined1 local_2;
  
  if (DAT_00018875 == '\x01') {
    iVar1 = FUN_fffb23f3(0x35);
    if (iVar1 == 1) {
      DAT_00018875 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe5f82 @ fffe5f82 (41 bytes)

bool FUN_fffe5f82(void)

{
  byte bVar1;
  
  bVar1 = FUN_fffb3196(DAT_00009dbd);
  return bVar1 < 4;
}


// ===== FUN_fffe5fab @ fffe5fab (50 bytes)

undefined1 FUN_fffe5fab(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uStack_4;
  
  bVar2 = FUN_fffb3196(DAT_00009dbd);
  uVar1 = (uint)bVar2;
  if ((uVar1 - 4 < 4) || (uVar1 == 10 || uVar1 == 0xb)) {
    uStack_4 = 1;
  }
  else {
    uStack_4 = 0;
  }
  return uStack_4;
}


// ===== FUN_fffe5fdd @ fffe5fdd (50 bytes)

undefined1 FUN_fffe5fdd(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uStack_4;
  
  bVar2 = FUN_fffb3196(DAT_00009dbd);
  uVar1 = (uint)bVar2;
  if ((uVar1 - 6 < 2) || (uVar1 == 10 || uVar1 == 0xb)) {
    uStack_4 = 1;
  }
  else {
    uStack_4 = 0;
  }
  return uStack_4;
}


// ===== FUN_fffe600f @ fffe600f (31 bytes)

bool FUN_fffe600f(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb324c(0);
  return (*(byte *)(iVar1 + 3) & 8) != 0;
}


// ===== FUN_fffe602e @ fffe602e (120 bytes)

void FUN_fffe602e(void)

{
  uint uVar1;
  undefined1 uVar2;
  byte bVar3;
  int iVar4;
  
  uVar2 = DAT_00009dbd;
  bVar3 = FUN_fffb3196(0);
  iVar4 = FUN_fffc2d93(uVar2);
  if (iVar4 == 1) {
    PTR_DAT_00025d7c[0x46c] = 1;
    FUN_fffb237a(0x40,200);
    return;
  }
  uVar1 = (uint)bVar3;
  if ((3 < uVar1 - 4) && (uVar1 != 10 && uVar1 != 0xb)) {
    PTR_DAT_00025d7c[0x46c] = 1;
    FUN_fffb237a(0x40,10);
    return;
  }
  PTR_DAT_00025d7c[0x46c] = 1;
  FUN_fffb237a(0x40,100);
  return;
}


// ===== FUN_fffe60a6 @ fffe60a6 (146 bytes)

void FUN_fffe60a6(void)

{
  bool bVar1;
  int iVar2;
  
  if ((PTR_DAT_00025d7c[0x40d] == '\x01') || (PTR_DAT_00025d7c[0x86] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d7c[0x39] != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (PTR_DAT_00025d7c[0x418] == '\0') {
    PTR_DAT_00025d7c[0x46b] = 1;
    FUN_fffc809d(DAT_00009dbd);
    return;
  }
  iVar2 = FUN_fffe5d4f();
  if (iVar2 != 1) {
    iVar2 = FUN_fffe5d0e();
    if (iVar2 == 1) {
      FUN_fffe5c7e();
      return;
    }
    FUN_fffe5ce0();
    return;
  }
  FUN_fffe5c7e();
  return;
}


// ===== FUN_fffe6138 @ fffe6138 (146 bytes)

void FUN_fffe6138(void)

{
  bool bVar1;
  int iVar2;
  
  if ((PTR_DAT_00025d7c[0x40d] == '\x01') || (PTR_DAT_00025d7c[0x86] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d7c[0x39] != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (PTR_DAT_00025d7c[0x418] == '\0') {
    PTR_DAT_00025d7c[0x46b] = 1;
    FUN_fffc8141(DAT_00009dbd);
    return;
  }
  iVar2 = FUN_fffe5d4f();
  if (iVar2 != 1) {
    iVar2 = FUN_fffe5d0e();
    if (iVar2 == 0) {
      FUN_fffe5caf();
      return;
    }
    FUN_fffe5ce0();
    return;
  }
  FUN_fffe5caf();
  return;
}


// ===== FUN_fffe61ca @ fffe61ca (29 bytes)

void FUN_fffe61ca(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb2406(0);
  if (iVar1 == 0) {
    PTR_DAT_00025d7c[0x1bc] = 0;
    return;
  }
  PTR_DAT_00025d7c[0x1bc] = 1;
  return;
}


// ===== FUN_fffe61e7 @ fffe61e7 (178 bytes)

undefined1
FUN_fffe61e7(int param_1,char param_2,undefined2 param_3,undefined1 *param_4,undefined4 param_5,
            ushort *param_6)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 uStack_1c;
  undefined1 auStack_1b [3];
  char cStack_18;
  undefined4 local_17;
  undefined2 local_13;
  ushort *local_10;
  undefined1 *local_c;
  undefined2 local_8;
  char local_5;
  int local_4;
  
  local_10 = param_6;
  DAT_0001ff10 = 0;
  DAT_0001b234 = 0;
  local_13 = *(undefined2 *)(param_1 + 6);
  local_17 = *(undefined4 *)(param_1 + 2);
  local_c = param_4;
  local_8 = param_3;
  local_5 = param_2;
  local_4 = param_1;
  cStack_18 = FUN_fffe6c27();
  if (cStack_18 == '\0') {
    uStack_1c = 1;
  }
  else {
    cStack_18 = FUN_fffe6299(auStack_1b,local_4,local_5,local_8);
    if (cStack_18 == '\0') {
      uStack_1c = 1;
    }
    else {
      if (local_5 == '\x01') {
        FUN_fffcdddb(auStack_1b);
      }
      puVar1 = &DAT_00018878;
      for (uVar2 = (uint)DAT_0001ff10; uVar2 != 0; uVar2 = uVar2 - 1) {
        *local_c = *puVar1;
        local_c = local_c + 1;
        puVar1 = puVar1 + 1;
      }
      *local_10 = DAT_0001ff10;
      uStack_1c = DAT_0001b234;
    }
  }
  DAT_0001b234 = uStack_1c;
  return uStack_1c;
}


// ===== FUN_fffe6299 @ fffe6299 (156 bytes)

bool FUN_fffe6299(undefined4 param_1,undefined4 param_2,char param_3,undefined2 param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char extraout_R1;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 auStack_34 [12];
  undefined4 uStack_28;
  undefined1 auStack_20 [8];
  char cStack_18;
  char cStack_e;
  undefined2 local_c;
  char local_9;
  undefined4 local_8;
  undefined4 local_4;
  
  uStack_28 = 0xfffe62ad;
  local_c = param_4;
  local_9 = param_3;
  local_8 = param_2;
  local_4 = param_1;
  puVar7 = (undefined4 *)FUN_fffd4ffe(param_1);
  uVar3 = local_4;
  uVar2 = local_8;
  uVar1 = local_c;
  cStack_e = extraout_R1;
  if (extraout_R1 == '\x01') {
    if (local_9 == '\0') {
      *puVar7 = 1;
    }
    if (cStack_18 == '\0') {
      if (puVar7 == (undefined4 *)0x0) {
        puVar4 = auStack_34;
        puVar5 = auStack_20;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar4 = *puVar5;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        cStack_e = FUN_fffe6550(uVar3,uVar2,uVar1);
      }
      else {
        puVar4 = auStack_34;
        puVar5 = auStack_20;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar4 = *puVar5;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        cStack_e = FUN_fffe646c(uVar3,uVar2);
      }
    }
    else if (puVar7 == (undefined4 *)0x0) {
      uStack_28 = 0xfffe631f;
      cStack_e = FUN_fffe63fb(local_4,local_8);
    }
    else {
      uStack_28 = 0xfffe6315;
      cStack_e = FUN_fffe6335(local_4,local_8);
    }
  }
  return cStack_e != '\0';
}


// ===== FUN_fffe6335 @ fffe6335 (198 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_fffe6335(int param_1,undefined4 *param_2)

{
  bool bVar1;
  char cVar2;
  undefined1 local_18;
  undefined4 local_17;
  undefined4 local_13;
  undefined4 local_f;
  byte bStack_b;
  undefined4 *local_8;
  int local_4;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_18 = 0;
  }
  else {
    local_f = 0;
    local_13 = 0;
    local_17 = 0;
    local_8 = param_2;
    local_4 = param_1;
    cVar2 = FUN_fffd528d(param_1,&local_17,0xc);
    if (cVar2 == '\0') {
      local_18 = 0;
    }
    else {
      DAT_0001887c = local_8[1];
      _DAT_00018878 = *local_8;
      DAT_00018888 = local_f;
      DAT_00018884 = local_13;
      DAT_00018880 = local_17;
      for (bStack_b = 0; bStack_b < 0xc; bStack_b = bStack_b + 1) {
        if (*(char *)((int)&DAT_00018880 + (uint)bStack_b) == '\0') {
          *(undefined1 *)((int)&DAT_00018880 + (uint)bStack_b) = 0x3b;
          break;
        }
      }
      if (bStack_b == 0xc) {
        uRam0001888c = 0x3b;
      }
      DAT_0001ff10 = bStack_b + 9;
      local_18 = 1;
    }
  }
  return local_18;
}


// ===== FUN_fffe63fb @ fffe63fb (113 bytes)

bool FUN_fffe63fb(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  byte local_c;
  char local_b;
  int local_8;
  undefined4 local_4;
  
  local_b = '\0';
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_c = 0;
  local_8 = param_2;
  local_4 = param_1;
  do {
    if (0xc < local_c) {
LAB_fffe6458:
      return local_b == '\x01';
    }
    if (*(char *)((uint)local_c + local_8 + 8) == ';') {
      cVar1 = FUN_fffd52b6(local_4,&local_18,local_c);
      if (cVar1 == '\0') {
        return false;
      }
      local_b = '\x01';
      goto LAB_fffe6458;
    }
    *(undefined1 *)((int)&local_18 + (uint)local_c) = *(undefined1 *)((uint)local_c + local_8 + 8);
    local_c = local_c + 1;
  } while( true );
}


// ===== FUN_fffe646c @ fffe646c (228 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe654d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_fffe646c(undefined4 param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 in_stack_0000000c;
  char in_stack_00000010;
  undefined1 uStack_15;
  bool bStack_12;
  short sStack_10;
  
  DAT_0001887c = param_2[1];
  _DAT_00018878 = *param_2;
  cVar1 = FUN_fffd51a3(param_1);
  if (cVar1 == '\0') {
    uStack_15 = 0;
  }
  else if (in_stack_00000010 == '\x02') {
    DAT_0001ff10 = FUN_fffe67f5(sStack_10 * 0x14 + 0x14);
    uStack_15 = 1;
  }
  else if (in_stack_00000010 == '\x01') {
    DAT_0001ff10 = FUN_fffe67f5(sStack_10 * 10);
    uStack_15 = 1;
  }
  else {
    if (in_stack_0000000c._1_1_ == '\0') {
      if (in_stack_0000000c._3_1_ == 1) {
        DAT_00018880._0_1_ = FUN_fffb2e9c((undefined1)sStack_10);
        DAT_00018880._1_1_ = 0x3b;
        DAT_0001ff10 = 10;
      }
      else {
        bStack_12 = 2 < in_stack_0000000c._3_1_;
        DAT_0001ff10 = FUN_fffe66e2((undefined1)sStack_10,bStack_12,in_stack_0000000c._2_1_ != '\0')
        ;
      }
    }
    else {
      DAT_0001ff10 = FUN_fffe67f5(sStack_10);
    }
    uStack_15 = 1;
  }
  return uStack_15;
}


// ===== FUN_fffe6550 @ fffe6550 (314 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6687) */
/* WARNING: Removing unreachable block (ram,0xfffe6664) */
/* WARNING: Removing unreachable block (ram,0xfffe6659) */

undefined1
FUN_fffe6550(undefined4 param_1,int param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,char param_9)

{
  bool bVar1;
  char cVar2;
  undefined2 in_stack_ffffffd8;
  ushort uStack_1e;
  char local_1c;
  short local_1a;
  short local_18;
  undefined1 auStack_16 [3];
  byte bStack_13;
  byte bStack_12;
  undefined1 local_11;
  char cStack_10;
  undefined2 local_e;
  int local_c;
  undefined4 local_8;
  
  local_1c = param_8._3_1_ + 9;
  if (param_9 == '\x01') {
    local_18 = param_6._2_2_ * 10;
    local_1a = (short)param_6 * 10;
  }
  else if (param_9 == '\x02') {
    local_18 = param_6._2_2_ * 0x14 + 0x14;
    local_1a = (short)param_6 * 0x14 + 0x14;
  }
  else {
    local_18 = param_6._2_2_;
    local_1a = (short)param_6;
  }
  if ((param_8._1_1_ == '\0') && (param_8._3_1_ < 4)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  local_e = param_3;
  local_c = param_2;
  local_8 = param_1;
  if (bVar1) {
    local_11 = param_8._2_1_ != '\0';
    cStack_10 = FUN_fffe693b(param_2 + 8,&bStack_12,param_8._3_1_,local_11,(undefined1)local_1a,
                             CONCAT31(CONCAT21(param_3,(undefined1)local_18),(undefined1)local_1a));
    if (cStack_10 == '\0') {
      return 0;
    }
    if (param_8._2_1_ == '\0') {
      uStack_1e = (ushort)bStack_12;
    }
    else {
      bStack_13 = bStack_12;
      uStack_1e = (ushort)(char)bStack_12;
    }
    cStack_10 = FUN_fffe668a(local_8,(int)(short)uStack_1e);
    if (cStack_10 == '\0') {
      return 0;
    }
    cVar2 = FUN_fffd51ca(local_8);
    if (cVar2 == '\0') {
      return 0;
    }
  }
  else {
    cStack_10 = FUN_fffe6869(param_2 + 8,auStack_16,local_1a,local_18,param_5,
                             CONCAT31((int3)(CONCAT22(param_3,in_stack_ffffffd8) >> 8),local_1c));
    if (cStack_10 == '\0') {
      return 0;
    }
    cVar2 = FUN_fffd51ca(local_8);
    if (cVar2 == '\0') {
      return 0;
    }
  }
  return 1;
}


// ===== FUN_fffe668a @ fffe668a (88 bytes)

undefined1 FUN_fffe668a(char *param_1,short param_2)

{
  bool bVar1;
  undefined1 local_8;
  
  if (param_1 == (char *)0x0) {
    local_8 = 0;
  }
  else {
    if ((*param_1 == '\0') && (param_1[1] == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (param_1[2] == '\f')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (param_2 == 5) {
        local_8 = 0;
      }
      else {
        local_8 = 1;
      }
    }
    else {
      local_8 = 1;
    }
  }
  return local_8;
}


// ===== FUN_fffe66e2 @ fffe66e2 (275 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe67f2) */
/* WARNING: Removing unreachable block (ram,0xfffe67ac) */
/* WARNING: Removing unreachable block (ram,0xfffe6726) */

short FUN_fffe66e2(byte param_1,char param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  short sStack_10;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_5;
  
  local_5 = param_1;
  if (param_3 == 0) {
    if (param_2 == '\0') {
      local_d = 10;
      local_e = 2;
    }
    else if (param_2 == '\x01') {
      local_d = 100;
      local_e = 3;
    }
    for (local_c = 0; local_c < local_e; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      uVar1 = FUN_fffb2e9c(bVar2);
      *(undefined1 *)((int)&DAT_00018880 + (uint)local_c) = uVar1;
    }
    *(undefined1 *)((int)&DAT_00018880 + (uint)local_c) = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 8;
  }
  else {
    if ((param_1 & 0x80) == 0) {
      DAT_00018880._0_1_ = 0x2b;
    }
    else {
      DAT_00018880._0_1_ = 0x2d;
      local_5 = ~param_1 + 1;
    }
    local_d = 10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      uVar1 = FUN_fffb2e9c(bVar2);
      *(undefined1 *)((int)&DAT_00018880 + local_c + 1) = uVar1;
    }
    *(undefined1 *)((int)&DAT_00018880 + local_c + 1) = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 9;
  }
  return sStack_10;
}


// ===== FUN_fffe67f5 @ fffe67f5 (116 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6866) */
/* WARNING: Removing unreachable block (ram,0xfffe681f) */

short FUN_fffe67f5(ushort param_1)

{
  undefined1 uVar1;
  uint uVar2;
  ushort uVar3;
  ushort local_c;
  byte local_a;
  ushort local_6;
  
  local_c = 1000;
  local_6 = param_1;
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    uVar2 = (uint)local_6;
    if (local_c != 0) {
      uVar2 = uVar2 / local_c;
    }
    uVar3 = local_6;
    if ((local_c & 0xff) != 0) {
      uVar3 = (ushort)((uint)local_6 / (local_c & 0xff));
    }
    local_6 = local_6 - (uVar3 * local_c & 0xff);
    local_c = local_c / 10;
    uVar1 = FUN_fffb2e9c(uVar2 & 0xff);
    *(undefined1 *)((int)&DAT_00018880 + (uint)local_a) = uVar1;
  }
  *(undefined1 *)((int)&DAT_00018880 + (uint)local_a) = 0x3b;
  return (byte)(local_a + 1) + 8;
}


// ===== FUN_fffe6869 @ fffe6869 (210 bytes)

bool FUN_fffe6869(undefined1 *param_1,ushort *param_2,ushort param_3,ushort param_4,
                 undefined4 param_5,undefined4 param_6)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  bool local_17;
  byte local_16;
  
  if ((byte)param_6 == param_6._2_2_) {
    for (local_16 = 0; local_16 < 4; local_16 = local_16 + 1) {
      if (((byte)param_1[local_16] < 0x30) || (0x39 < (byte)param_1[local_16])) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return false;
      }
    }
    sVar2 = FUN_fffb2f07(*param_1);
    sVar3 = FUN_fffb2f07(param_1[1]);
    sVar4 = FUN_fffb2f07(param_1[2]);
    sVar5 = FUN_fffb2f07(param_1[3]);
    uVar6 = sVar5 + sVar4 * 10 + sVar3 * 100 + sVar2 * 1000;
    if ((uVar6 < param_3) || (param_4 < uVar6)) {
      local_17 = false;
    }
    else {
      local_17 = true;
    }
    if (local_17) {
      *param_2 = uVar6;
    }
  }
  else {
    local_17 = false;
  }
  return local_17;
}


// ===== FUN_fffe693b @ fffe693b (748 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6ab4) */
/* WARNING: Removing unreachable block (ram,0xfffe6b97) */
/* WARNING: Removing unreachable block (ram,0xfffe6a5c) */
/* WARNING: Removing unreachable block (ram,0xfffe6b40) */

undefined1
FUN_fffe693b(byte *param_1,byte *param_2,char param_3,char param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,char param_8)

{
  bool bVar1;
  char cVar2;
  undefined1 local_14;
  byte local_13;
  byte local_11;
  byte local_10;
  
  local_10 = 0;
  local_14 = 0;
  if (param_4 == '\x01') {
    local_11 = param_3 + 10;
  }
  else {
    local_11 = param_3 + 9;
  }
  if (local_11 != param_6._2_2_) {
    return 0;
  }
  if (param_3 == '\x01') {
    if (param_4 == '\0') {
      if ((*param_1 < 0x30) || (0x39 < *param_1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return 0;
      }
      local_10 = FUN_fffb2f07(*param_1);
    }
    else {
      if ((param_1[1] < 0x30) || (0x39 < param_1[1])) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return 0;
      }
      local_10 = FUN_fffb2f07(param_1[1]);
      if (*param_1 == 0x2d) {
        local_10 = ~local_10 + 1;
      }
      else if (*param_1 != 0x2b) {
        return 0;
      }
    }
  }
  else if (param_3 == '\x02') {
    if (param_4 == '\0') {
      for (local_13 = 0; local_13 < 2; local_13 = local_13 + 1) {
        if ((param_1[local_13] < 0x30) || (0x39 < param_1[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = FUN_fffb2f07(param_1[local_13]);
        local_10 = cVar2 * param_8 + local_10;
      }
    }
    else {
      for (local_13 = 1; local_13 < 3; local_13 = local_13 + 1) {
        if ((param_1[local_13] < 0x30) || (0x39 < param_1[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = FUN_fffb2f07(param_1[local_13]);
        local_10 = cVar2 * param_8 + local_10;
      }
      if (*param_1 == 0x2d) {
        local_10 = ~local_10 + 1;
      }
      else if (*param_1 != 0x2b) {
        return 0;
      }
    }
  }
  else if (param_3 == '\x03') {
    if (param_4 == '\0') {
      for (local_13 = 0; local_13 < 3; local_13 = local_13 + 1) {
        if ((param_1[local_13] < 0x30) || (0x39 < param_1[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = FUN_fffb2f07(param_1[local_13]);
        local_10 = cVar2 * param_8 + local_10;
      }
    }
    else {
      for (local_13 = 1; local_13 < 4; local_13 = local_13 + 1) {
        if ((param_1[local_13] < 0x30) || (0x39 < param_1[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = FUN_fffb2f07(param_1[local_13]);
        local_10 = cVar2 * param_8 + local_10;
      }
      if (*param_1 == 0x2d) {
        local_10 = ~local_10 + 1;
      }
      else if (*param_1 != 0x2b) {
        return 0;
      }
    }
  }
  if (param_4 == '\0') {
    if ((local_10 < (byte)param_6) || (param_6._1_1_ < local_10)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *param_2 = local_10;
      local_14 = 1;
    }
  }
  else {
    if (((char)local_10 < (char)(byte)param_6) || ((char)param_6._1_1_ < (char)local_10)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *param_2 = local_10;
      local_14 = 1;
    }
  }
  return local_14;
}


// ===== FUN_fffe6c27 @ fffe6c27 (339 bytes)

undefined1 FUN_fffe6c27(char *param_1,byte *param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined1 local_15;
  byte *local_14;
  byte local_10;
  char cStack_e;
  
  local_10 = 0;
  local_14 = param_2;
  while( true ) {
    if (5 < local_10) {
      cVar2 = FUN_fffb2f07(*param_2);
      if (cVar2 == -1) {
        local_15 = 0;
      }
      else {
        cVar3 = FUN_fffb2f07(param_2[1]);
        if (cVar3 == -1) {
          local_15 = 0;
        }
        else {
          cVar5 = cVar2 * '\n' + cVar3;
          cVar4 = FUN_fffb2f07(param_2[2]);
          if (cVar4 == -1) {
            local_15 = 0;
          }
          else {
            cStack_e = FUN_fffb2f07(param_2[3]);
            if (cStack_e == -1) {
              local_15 = 0;
            }
            else {
              cStack_e = cVar4 * '\n' + cStack_e;
              if (cVar5 == '\x06') {
                cStack_e = cStack_e + '\x15';
              }
              else if (cVar5 == '\x02') {
                cStack_e = cStack_e + '\x04';
              }
              else if (cVar5 == '\x03') {
                cStack_e = cStack_e + '\x06';
              }
              else if (cVar5 == '\x04') {
                cStack_e = cStack_e + '\v';
              }
              else {
                if (cVar5 != '\x01') {
                  return 0;
                }
                cStack_e = cStack_e + -1;
              }
              cVar5 = FUN_fffb2f07(param_2[4]);
              if (cVar5 == -1) {
                local_15 = 0;
              }
              else {
                cVar4 = FUN_fffb2f07(param_2[5]);
                if (cVar4 == -1) {
                  local_15 = 0;
                }
                else {
                  *param_1 = cVar2 * '\n' + cVar3 + -1;
                  param_1[1] = cStack_e;
                  param_1[2] = cVar5 * '\n' + cVar4 + -1;
                  local_15 = 1;
                }
              }
            }
          }
        }
      }
      return local_15;
    }
    if ((*local_14 < 0x30) || (0x39 < *local_14)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) break;
    local_14 = local_14 + 1;
    local_10 = local_10 + 1;
  }
  return 0;
}


// ===== FUN_fffe6d7a @ fffe6d7a (172 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6da5) */
/* WARNING: Removing unreachable block (ram,0xfffe6dac) */
/* WARNING: Removing unreachable block (ram,0xfffe6dae) */
/* WARNING: Removing unreachable block (ram,0xfffe6dca) */
/* WARNING: Removing unreachable block (ram,0xfffe6daa) */
/* WARNING: Removing unreachable block (ram,0xfffe6dd0) */
/* WARNING: Removing unreachable block (ram,0xfffe6de0) */
/* WARNING: Removing unreachable block (ram,0xfffe6de2) */
/* WARNING: Removing unreachable block (ram,0xfffe6df2) */
/* WARNING: Removing unreachable block (ram,0xfffe6dfe) */
/* WARNING: Removing unreachable block (ram,0xfffe6e07) */
/* WARNING: Removing unreachable block (ram,0xfffe6e09) */
/* WARNING: Removing unreachable block (ram,0xfffe6dfc) */
/* WARNING: Removing unreachable block (ram,0xfffe6e17) */
/* WARNING: Removing unreachable block (ram,0xfffe6e1f) */

void FUN_fffe6d7a(void)

{
  do {
  } while( true );
}


// ===== FUN_fffe6e26 @ fffe6e26 (20 bytes)

void FUN_fffe6e26(void)

{
  FUN_fffb237a(0x32,200);
  DAT_0001b299 = 1;
  return;
}


// ===== FUN_fffea63a @ fffea63a (594 bytes)

void FUN_fffea63a(char param_1)

{
  int iVar1;
  undefined4 uStack_e;
  undefined4 uStack_a;
  undefined4 uStack_6;
  byte bStack_2;
  char local_1;
  
  local_1 = param_1;
  if (param_1 == '\x05') {
    iVar1 = FUN_fffede1d(&DAT_0001b3a0,&DAT_00009baa,0xc);
    if (iVar1 != 0) {
      DAT_0001b3a8 = DAT_00009bb2;
      DAT_0001b3a4 = DAT_00009bae;
      DAT_0001b3a0 = DAT_00009baa;
      uStack_6 = DAT_00009bb2;
      uStack_a = DAT_00009bae;
      uStack_e = DAT_00009baa;
      DAT_0001ff12 = 0x15;
    }
  }
  else if (param_1 == '\x02') {
    iVar1 = FUN_fffede1d(&DAT_0001b37c,&DAT_00009b4d,0xc);
    if (iVar1 != 0) {
      DAT_0001b384 = DAT_00009b55;
      DAT_0001b380 = DAT_00009b51;
      DAT_0001b37c = DAT_00009b4d;
      uStack_6 = DAT_00009b55;
      uStack_a = DAT_00009b51;
      uStack_e = DAT_00009b4d;
      DAT_0001ff12 = 0x15;
    }
  }
  else if (param_1 == '\x03') {
    iVar1 = FUN_fffede1d(&DAT_0001b388,&DAT_00009b6c,0xc);
    if (iVar1 != 0) {
      DAT_0001b390 = DAT_00009b74;
      DAT_0001b38c = DAT_00009b70;
      DAT_0001b388 = DAT_00009b6c;
      uStack_6 = DAT_00009b74;
      uStack_a = DAT_00009b70;
      uStack_e = DAT_00009b6c;
      DAT_0001ff12 = 0x15;
    }
  }
  else if (param_1 == '\x04') {
    iVar1 = FUN_fffede1d(&DAT_0001b394,&DAT_00009b8b,0xc);
    if (iVar1 != 0) {
      DAT_0001b39c = DAT_00009b93;
      DAT_0001b398 = DAT_00009b8f;
      DAT_0001b394 = DAT_00009b8b;
      uStack_6 = DAT_00009b93;
      uStack_a = DAT_00009b8f;
      uStack_e = DAT_00009b8b;
      DAT_0001ff12 = 0x15;
    }
  }
  else if ((param_1 == '\x01') &&
          (iVar1 = FUN_fffede1d(&DAT_0001b370,&DAT_00009b2e,0xc), iVar1 != 0)) {
    DAT_0001b378 = DAT_00009b36;
    DAT_0001b374 = DAT_00009b32;
    DAT_0001b370 = DAT_00009b2e;
    uStack_6 = DAT_00009b36;
    uStack_a = DAT_00009b32;
    uStack_e = DAT_00009b2e;
    DAT_0001ff12 = 0x15;
  }
  if (DAT_0001ff12 != 0) {
    for (bStack_2 = 0; bStack_2 < 0xc; bStack_2 = bStack_2 + 1) {
      (&DAT_0001b23d)[bStack_2] = *(undefined1 *)((int)&uStack_e + (uint)bStack_2);
    }
    DAT_0001b249 = 0x3b;
    return;
  }
  return;
}


// ===== FUN_fffea88c @ fffea88c (380 bytes)

void FUN_fffea88c(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b559 != DAT_00009bb6) {
      DAT_0001b559 = DAT_00009bb6;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009bb6);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b556 != DAT_00009b59) {
      DAT_0001b556 = DAT_00009b59;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009b59);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b557 != DAT_00009b78) {
      DAT_0001b557 = DAT_00009b78;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009b78);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b558 != DAT_00009b97) {
      DAT_0001b558 = DAT_00009b97;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009b97);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b555 != DAT_00009b3a)) {
    DAT_0001b555 = DAT_00009b3a;
    DAT_0001b23d = FUN_fffb2e9c(DAT_00009b3a);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeaa08 @ fffeaa08 (380 bytes)

void FUN_fffeaa08(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b55e != DAT_00009bb7) {
      DAT_0001b55e = DAT_00009bb7;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009bb7);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b55b != DAT_00009b5a) {
      DAT_0001b55b = DAT_00009b5a;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009b5a);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b55c != DAT_00009b79) {
      DAT_0001b55c = DAT_00009b79;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009b79);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b55d != DAT_00009b98) {
      DAT_0001b55d = DAT_00009b98;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009b98);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b55a != DAT_00009b3b)) {
    DAT_0001b55a = DAT_00009b3b;
    DAT_0001b23d = FUN_fffb2e9c(DAT_00009b3b);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeab84 @ fffeab84 (380 bytes)

void FUN_fffeab84(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b563 != DAT_00009bb8) {
      DAT_0001b563 = DAT_00009bb8;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009bb8);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b560 != DAT_00009b5b) {
      DAT_0001b560 = DAT_00009b5b;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009b5b);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b561 != DAT_00009b7a) {
      DAT_0001b561 = DAT_00009b7a;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009b7a);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b562 != DAT_00009b99) {
      DAT_0001b562 = DAT_00009b99;
      DAT_0001b23d = FUN_fffb2e9c(DAT_00009b99);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b55f != DAT_00009b3c)) {
    DAT_0001b55f = DAT_00009b3c;
    DAT_0001b23d = FUN_fffb2e9c(DAT_00009b3c);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}

