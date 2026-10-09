// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc506b @ fffc506b (53 bytes)

void FUN_fffc506b(byte param_1)

{
  int iVar1;
  undefined1 uStack_2;
  
  iVar1 = FUN_fffc4fce();
  if (iVar1 == 0) {
    return;
  }
  *(byte *)(iVar1 + 3) = *(byte *)(iVar1 + 3) & 0xfc;
  *(byte *)(iVar1 + 3) = *(byte *)(iVar1 + 3) | param_1 & 3;
  FUN_fffb03e1(uStack_2);
  return;
}


// ===== FUN_fffc50a0 @ fffc50a0 (53 bytes)

void FUN_fffc50a0(byte param_1)

{
  int iVar1;
  undefined1 uStack_2;
  
  iVar1 = FUN_fffc4fce();
  if (iVar1 == 0) {
    return;
  }
  *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xfc;
  *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | param_1 & 3;
  FUN_fffb03e1(uStack_2);
  return;
}


// ===== FUN_fffc50d5 @ fffc50d5 (41 bytes)

void FUN_fffc50d5(byte param_1)

{
  int iVar1;
  undefined1 uStack_2;
  
  iVar1 = FUN_fffc4fce();
  if ((iVar1 != 0) && (param_1 < 2)) {
    FUN_fffc0948(iVar1,param_1);
    FUN_fffb03e1(uStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc50fe @ fffc50fe (41 bytes)

void FUN_fffc50fe(byte param_1)

{
  int iVar1;
  undefined1 uStack_2;
  
  iVar1 = FUN_fffc4fce();
  if ((iVar1 != 0) && (param_1 < 5)) {
    FUN_fffc0a49(iVar1,param_1);
    FUN_fffb03e1(uStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc5127 @ fffc5127 (54 bytes)

void FUN_fffc5127(byte param_1)

{
  int iVar1;
  undefined1 uStack_2;
  
  iVar1 = FUN_fffc4fce();
  if ((iVar1 != 0) && (param_1 < 2)) {
    if (param_1 == 0) {
      *(byte *)(iVar1 + 6) = *(byte *)(iVar1 + 6) & 0xef;
    }
    else {
      *(byte *)(iVar1 + 6) = *(byte *)(iVar1 + 6) | 0x10;
    }
    FUN_fffb03e1(uStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc515d @ fffc515d (64 bytes)

void FUN_fffc515d(byte param_1)

{
  int iVar1;
  undefined1 uStack_2;
  byte local_1;
  
  iVar1 = FUN_fffc4fce();
  if (iVar1 != 0) {
    local_1 = param_1;
    if (0xf < param_1) {
      local_1 = 0xf;
    }
    if (local_1 == 0) {
      local_1 = 1;
    }
    *(byte *)(iVar1 + 6) = *(byte *)(iVar1 + 6) & 0xf0;
    *(byte *)(iVar1 + 6) = *(byte *)(iVar1 + 6) | local_1;
    FUN_fffb03e1(uStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc519d @ fffc519d (157 bytes)

bool FUN_fffc519d(ushort param_1,char param_2)

{
  bool bVar1;
  short sVar2;
  bool bStack_7;
  
  sVar2 = FUN_fffb3b33();
  if ((sVar2 == 0x315b) || (sVar2 == 0x50e2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return true;
  }
  if (PTR_DAT_00025d54[0x9a] == '\0') {
    return true;
  }
  if (param_2 != '\0') {
    return false;
  }
  if ((param_1 < 0x300) || (0x30e < param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if ((param_1 < 0x310) || (0x312 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      bStack_7 = false;
      goto LAB_fffc521d;
    }
  }
  bStack_7 = true;
LAB_fffc521d:
  bStack_7 = !bStack_7;
  return bStack_7;
}


// ===== FUN_fffc523a @ fffc523a (86 bytes)

undefined1 FUN_fffc523a(char param_1,char param_2,undefined1 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 *in_R14;
  undefined1 local_5;
  
  if (param_2 == '\0') {
    *in_R14 = 1;
  }
  uVar1 = DAT_0001b4e3;
  uVar2 = DAT_0001b4e4;
  local_5 = param_3;
  if (param_1 == '\0') {
    uVar1 = param_3;
    if (in_R14 == (undefined4 *)0x0) {
      local_5 = DAT_0001b4e3;
      uVar1 = DAT_0001b4e3;
    }
  }
  else {
    uVar2 = param_3;
    if (in_R14 == (undefined4 *)0x0) {
      local_5 = DAT_0001b4e4;
      uVar2 = DAT_0001b4e4;
    }
  }
  DAT_0001b4e4 = uVar2;
  DAT_0001b4e3 = uVar1;
  return local_5;
}


// ===== FUN_fffc5290 @ fffc5290 (71 bytes)

void FUN_fffc5290(void)

{
  if (DAT_00009dbd == '\0') {
    if (DAT_00009dbe == '\x01') {
      PTR_DAT_00025d54[0x443] = 1;
      return;
    }
  }
  else if (DAT_00009dbf == '\x01') {
    PTR_DAT_00025d54[0x445] = 1;
    return;
  }
  return;
}


// ===== FUN_fffc52d7 @ fffc52d7 (180 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc531a) */

void FUN_fffc52d7(byte param_1)

{
  int iVar1;
  byte local_6;
  ushort local_4;
  byte local_1;
  
  if ((DAT_00020b8a == '\x01') || (PTR_DAT_00025d58[0x95] == '\x01')) {
    return;
  }
  local_1 = param_1;
  if (PTR_DAT_00025d58[0xa1] == '\x06') {
    if (PTR_DAT_00025d58[0x415] != '\x01') {
      return;
    }
    local_1 = param_1 << 2;
  }
  if ((char)local_1 < '\0') {
    PTR_DAT_00025d58[0x47c] = 1;
    local_6 = ~local_1 + 1;
  }
  else {
    PTR_DAT_00025d58[0x47c] = 0;
    local_6 = local_1;
  }
  DAT_0001ff6a = DAT_0001ff6a + (short)(char)local_1;
  local_4 = DAT_0001ff6a;
  if ((short)DAT_0001ff6a < 0) {
    local_4 = ~DAT_0001ff6a + 1;
  }
  iVar1 = FUN_fffc538b();
  if (iVar1 == 1) {
    FUN_fffc53dc(local_6,(int)(short)local_4);
    return;
  }
  FUN_fffc5a84(local_6,(int)(short)local_4);
  return;
}


// ===== FUN_fffc538b @ fffc538b (81 bytes)

undefined1 FUN_fffc538b(void)

{
  undefined1 local_2;
  
  if (DAT_00009c5e == '\x01') {
    local_2 = 1;
  }
  else if (DAT_00009dbd == '\0') {
    if (PTR_DAT_00025d58[0x425] == '\0') {
      local_2 = 0;
    }
    else {
      local_2 = 1;
    }
  }
  else if (PTR_DAT_00025d58[0x426] == '\0') {
    local_2 = 0;
  }
  else {
    local_2 = 1;
  }
  return local_2;
}


// ===== FUN_fffc53dc @ fffc53dc (240 bytes)

void FUN_fffc53dc(byte param_1,ushort param_2)

{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  bool local_5;
  byte local_1;
  
  bVar1 = DAT_00009dbd == '\0';
  local_5 = !bVar1;
  if (DAT_00009afe == '\0') {
    if ((param_2 & 0xfffc) == 0) {
      return;
    }
    uVar4 = (uint)(int)(short)(param_2 & 0xfffc) >> 2;
    uVar2 = uVar4 & 3;
    local_1 = (byte)uVar4 & 3;
  }
  else {
    local_1 = param_1;
    if (DAT_00009afe != '\x01') goto LAB_fffc5452;
    if ((param_2 & 0xfffe) == 0) {
      return;
    }
    uVar4 = (uint)(int)(short)(param_2 & 0xfffe) >> 1;
    uVar2 = uVar4 & 1;
    local_1 = (byte)uVar4 & 1;
  }
  if (uVar2 == 0) {
    return;
  }
LAB_fffc5452:
  FUN_fffc4caa();
  if (((PTR_DAT_00025d58[0x405] == '\x01') && (iVar5 = FUN_fffc2d93(bVar1), iVar5 == 1)) &&
     (iVar5 = FUN_fffc2ecb(bVar1), iVar5 == 1)) {
    return;
  }
  if (DAT_00009c5e != '\x01') {
    FUN_fffc5767(local_5);
    return;
  }
  iVar5 = FUN_fffc2d93(bVar1);
  if ((iVar5 == 1) || (iVar5 = FUN_fffc2f1d(bVar1), iVar5 == 1)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar3) {
    FUN_fffc28fb(bVar1);
    FUN_fffc2937(bVar1);
    FUN_fffc54cc(local_1,bVar1);
    return;
  }
  FUN_fffc56cd(local_1);
  return;
}


// ===== FUN_fffc54cc @ fffc54cc (117 bytes)

void FUN_fffc54cc(byte param_1,undefined1 param_2)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  byte local_3;
  
  local_3 = 0;
  if (PTR_DAT_00025d58[0x47c] == '\0') {
    for (; local_3 < param_1; local_3 = local_3 + 1) {
      FUN_fffc5541(param_2);
    }
  }
  else {
    for (; local_3 < param_1; local_3 = local_3 + 1) {
      FUN_fffc55d7(param_2);
    }
  }
  if ((DAT_00020f1c == '\x01') && (iVar3 = FUN_fffe5e1b(), iVar3 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    uVar2 = FUN_fffc2e65(param_2);
    FUN_fffb0376(uVar2);
    return;
  }
  return;
}


// ===== FUN_fffc5541 @ fffc5541 (150 bytes)

void FUN_fffc5541(undefined1 param_1)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  byte bStack_5;
  byte bStack_3;
  byte bStack_2;
  
  FUN_fff9c1a1();
  if (bStack_2 == bStack_3) {
    return;
  }
  uVar2 = FUN_fffc2e65(param_1);
  while( true ) {
    bStack_5 = FUN_fffc2e65(param_1);
    do {
      if (bStack_5 < bStack_3) {
        bStack_5 = bStack_5 + 1;
      }
      else {
        bStack_5 = bStack_2;
      }
      if ((bStack_5 < 0x84) && (0x74 < bStack_5)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    } while ((bVar1) &&
            ((iVar3 = FUN_fff9c2cd(), iVar3 == 0 || (iVar3 = FUN_fffc2e8d(bStack_5), iVar3 == 1))));
    FUN_fffc2cdf(param_1,bStack_5);
    if (0x74 < bStack_5) break;
    iVar3 = FUN_fffc2de9();
    if (iVar3 == 1) {
      FUN_fffc566d(param_1,uVar2);
      return;
    }
  }
  FUN_fffc566d(param_1,uVar2);
  return;
}


// ===== FUN_fffc55d7 @ fffc55d7 (150 bytes)

void FUN_fffc55d7(undefined1 param_1)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  byte bStack_5;
  byte bStack_3;
  byte bStack_2;
  
  FUN_fff9c1a1();
  if (bStack_2 == bStack_3) {
    return;
  }
  uVar2 = FUN_fffc2e65(param_1);
  while( true ) {
    bStack_5 = FUN_fffc2e65(param_1);
    do {
      if (bStack_2 < bStack_5) {
        bStack_5 = bStack_5 - 1;
      }
      else {
        bStack_5 = bStack_3;
      }
      if ((bStack_5 < 0x84) && (0x74 < bStack_5)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    } while ((bVar1) &&
            ((iVar3 = FUN_fff9c2cd(), iVar3 == 0 || (iVar3 = FUN_fffc2e8d(bStack_5), iVar3 == 1))));
    FUN_fffc2cdf(param_1,bStack_5);
    if (0x74 < bStack_5) break;
    iVar3 = FUN_fffc2de9();
    if (iVar3 == 1) {
      FUN_fffc566d(param_1,uVar2);
      return;
    }
  }
  FUN_fffc566d(param_1,uVar2);
  return;
}


// ===== FUN_fffc566d @ fffc566d (29 bytes)

void FUN_fffc566d(undefined1 param_1,char param_2)

{
  char cVar1;
  
  cVar1 = FUN_fffc2e65(param_1);
  if (cVar1 == param_2) {
    return;
  }
  FUN_fffc568a(param_1);
  return;
}


// ===== FUN_fffc568a @ fffc568a (67 bytes)

void FUN_fffc568a(char param_1)

{
  FUN_fffc16f6(param_1);
  if (param_1 == '\0') {
    FUN_fffc1c04();
    PTR_DAT_00025d58[0x444] = 1;
  }
  else {
    FUN_fffc1c04();
    PTR_DAT_00025d58[0x444] = 1;
  }
  PTR_DAT_00025d58[0x40b] = 1;
  return;
}


// ===== FUN_fffc56cd @ fffc56cd (154 bytes)

void FUN_fffc56cd(undefined1 param_1)

{
  char cVar1;
  bool bVar2;
  char local_2;
  
  cVar1 = PTR_DAT_00025d58[0x405];
  if (cVar1 == '\0') {
    uRam00000000 = 1;
  }
  if (DAT_00009dbd == '\0') {
    if (cVar1 == '\0') {
      local_2 = '\0';
    }
    else {
      local_2 = '\x01';
    }
  }
  else if (cVar1 == '\0') {
    local_2 = '\x01';
  }
  else {
    local_2 = '\0';
  }
  if ((PTR_DAT_00025d58[0x482] == '\x01') && (PTR_DAT_00025d58[0x405] == '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    if (local_2 == '\0') {
      local_2 = '\x01';
    }
    else {
      local_2 = '\0';
    }
  }
  if (PTR_DAT_00025d58[0x3e] != '\0') {
    FUN_fffc5e0a(0,param_1);
    FUN_fffc5e0a(1,param_1);
    return;
  }
  FUN_fffc5e0a(local_2,param_1);
  return;
}


// ===== FUN_fffc5767 @ fffc5767 (49 bytes)

void FUN_fffc5767(undefined1 param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffc2d93(param_1);
  if ((iVar2 == 1) && (iVar2 = FUN_fffc2ecb(param_1), iVar2 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((!bVar1) && (iVar2 = FUN_fffc59de(), iVar2 != 0)) {
    FUN_fffc5798();
    return;
  }
  return;
}


// ===== FUN_fffc5798 @ fffc5798 (184 bytes)

void FUN_fffc5798(void)

{
  undefined2 uVar1;
  bool local_f;
  bool local_d;
  byte *local_c;
  byte *local_8;
  byte local_3;
  
  local_f = DAT_00009dbd == '\0';
  if (local_f) {
    local_8 = &DAT_00009d09;
    local_c = &DAT_00009d63;
  }
  else {
    local_8 = &DAT_00009d63;
    local_c = &DAT_00009d09;
  }
  local_d = !local_f;
  if (PTR_DAT_00025d58[0x67] == '\0') {
    local_f = local_d;
    local_3 = *local_8 & 0xf;
  }
  else if (DAT_00009c5e == '\x01') {
    local_3 = *local_c & 0xf;
  }
  else {
    local_f = local_d;
    local_3 = *local_8 & 0xf;
  }
  uVar1 = FUN_fffc5850(local_3);
  if (PTR_DAT_00025d58[0x47c] != '\0') {
    FUN_fffc5955();
    return;
  }
  FUN_fffc58e1(uVar1,local_f);
  return;
}


// ===== FUN_fffc5850 @ fffc5850 (145 bytes)

undefined2 FUN_fffc5850(byte param_1)

{
  uint uVar1;
  undefined2 local_6;
  
  uVar1 = (uint)param_1;
  if (uVar1 - 0xc < 3) {
LAB_fffc58b3:
    if (DAT_00009afa == '\0') {
      local_6 = 5;
    }
    else if (DAT_00009afa == '\x01') {
      local_6 = 10;
    }
    else {
      local_6 = 0x14;
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      return 100;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc58b3;
      if (1 < uVar1 - 10) {
        if (3 < uVar1) {
          return 0;
        }
        if (DAT_00009af9 != '\0') {
          if (DAT_00009af9 != '\x01') {
            return 0x14;
          }
          return 10;
        }
        return 5;
      }
    }
    local_6 = 100;
  }
  return local_6;
}


// ===== FUN_fffc58e1 @ fffc58e1 (116 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc590a) */

void FUN_fffc58e1(short param_1,uint param_2)

{
  uint uVar1;
  short sVar2;
  undefined1 *local_c;
  undefined1 local_6;
  
  if (param_2 == 0) {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  sVar2 = CONCAT11(local_c[0x48],local_c[0x49]);
  uVar1 = (int)param_1 & 0xff;
  if (uVar1 != 0 && (uVar1 != 0x80000000 || sVar2 != -1)) {
    sVar2 = (short)((int)sVar2 / (int)uVar1);
  }
  param_1 = sVar2 * param_1 + param_1;
  if (0x270e < param_1) {
    return;
  }
  local_c[0x48] = (char)((ushort)param_1 >> 8);
  local_6 = (undefined1)param_1;
  local_c[0x49] = local_6;
  FUN_fffc2fde(param_2 & 0xff);
  PTR_DAT_00025d58[0x40c] = 1;
  return;
}


// ===== FUN_fffc5955 @ fffc5955 (137 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc597e) */

void FUN_fffc5955(short param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  undefined1 *local_c;
  short local_6;
  
  if (param_2 == 0) {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  sVar3 = CONCAT11(local_c[0x48],local_c[0x49]);
  uVar1 = (int)param_1 & 0xff;
  local_6 = sVar3;
  if (uVar1 != 0 && (uVar1 != 0x80000000 || sVar3 != -1)) {
    local_6 = (short)((int)sVar3 / (int)uVar1);
  }
  local_6 = local_6 * param_1;
  uVar2 = (uint)sVar3;
  uVar1 = (int)param_1 & 0xff;
  uVar4 = uVar2;
  if (uVar1 != 0 && (uVar1 != 0x80000000 || uVar2 != 0xffffffff)) {
    uVar4 = (int)uVar2 / (int)uVar1;
  }
  if ((uVar2 == (uVar4 * (int)param_1 & 0xff)) && (local_6 = local_6 - param_1, local_6 < -9999)) {
    return;
  }
  local_c[0x48] = (char)((ushort)local_6 >> 8);
  local_c[0x49] = (undefined1)local_6;
  FUN_fffc2fde(param_2 & 0xff);
  PTR_DAT_00025d58[0x40c] = 1;
  return;
}


// ===== FUN_fffc59de @ fffc59de (166 bytes)

undefined1 FUN_fffc59de(void)

{
  undefined1 local_9;
  undefined2 local_8;
  undefined1 local_5;
  undefined2 local_4;
  
  if (DAT_00009afe == '\0') {
    local_5 = 4;
    local_8 = 0xfff0;
  }
  else if (DAT_00009afe == '\x01') {
    local_5 = 3;
    local_8 = 0xfff8;
  }
  else {
    local_5 = 2;
    local_8 = 0xfffc;
  }
  local_4 = DAT_0001ff6a;
  if ((short)DAT_0001ff6a < 0) {
    local_4 = ~DAT_0001ff6a;
  }
  if ((local_4 & local_8) == 0) {
    local_9 = 0;
  }
  else if (((int)(short)(local_4 & local_8) >> local_5 & 1U) == 0) {
    local_9 = 0;
  }
  else {
    if ((short)DAT_0001ff6a < 0) {
      DAT_0001ff6a = local_8 | DAT_0001ff6a;
    }
    else {
      DAT_0001ff6a = ~local_8 & DAT_0001ff6a;
    }
    local_9 = 1;
  }
  return local_9;
}


// ===== FUN_fffc5a84 @ fffc5a84 (309 bytes)

void FUN_fffc5a84(undefined1 param_1,ushort param_2)

{
  undefined1 local_1;
  
  if (PTR_DAT_00025d58[0x415] == '\x01') {
    FUN_fffc8ebc();
    if ((param_2 & 0xfffc) != 0) {
      local_1 = (undefined1)((uint)(int)(short)(param_2 & 0xfffc) >> 2);
      if ((short)DAT_0001ff6a < 0) {
        DAT_0001ff6a = ~(~DAT_0001ff6a + 1 & 3) + 1;
      }
      else {
        DAT_0001ff6a = DAT_0001ff6a & 3;
      }
      goto LAB_fffc5bb0;
    }
  }
  else if (DAT_00009afe == '\0') {
    if ((param_2 & 0xfffc) != 0) {
      local_1 = (undefined1)((uint)(int)(short)(param_2 & 0xfffc) >> 2);
      if ((short)DAT_0001ff6a < 0) {
        DAT_0001ff6a = ~(~DAT_0001ff6a + 1 & 3) + 1;
      }
      else {
        DAT_0001ff6a = DAT_0001ff6a & 3;
      }
      goto LAB_fffc5bb0;
    }
  }
  else if (DAT_00009afe == '\x01') {
    if ((param_2 & 0xfffe) != 0) {
      local_1 = (undefined1)((uint)(int)(short)(param_2 & 0xfffe) >> 1);
      if ((short)DAT_0001ff6a < 0) {
        DAT_0001ff6a = ~(~DAT_0001ff6a + 1 & 1) + 1;
      }
      else {
        DAT_0001ff6a = DAT_0001ff6a & 1;
      }
      goto LAB_fffc5bb0;
    }
  }
  else if (param_2 != 0) {
    DAT_0001ff6a = 0;
    local_1 = param_1;
LAB_fffc5bb0:
    FUN_fffc5bb9(local_1);
    return;
  }
  return;
}


// ===== FUN_fffc5bb9 @ fffc5bb9 (214 bytes)

void FUN_fffc5bb9(undefined1 param_1)

{
  bool bVar1;
  int iVar2;
  char local_3;
  bool local_2;
  
  local_2 = DAT_00009dbd != '\0';
  if (PTR_DAT_00025d58[0x418] == '\x01') {
    FUN_fffe5d2a();
    return;
  }
  if (PTR_DAT_00025d58[0x46b] != '\x01') {
    if ((PTR_DAT_00025d58[0x67] == '\x01') && (DAT_00009c5e == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if (PTR_DAT_00025d58[0x405] == '\x01') {
        if (local_2) {
          local_2 = false;
        }
        else {
          local_2 = true;
        }
      }
      if (local_2 == false) {
        local_3 = DAT_00009dbe;
      }
      else {
        local_3 = DAT_00009dbf;
      }
      if (local_3 == '\x02') {
        iVar2 = FUN_fffc2ecb(local_2);
        if (iVar2 == 1) {
          return;
        }
        FUN_fffc5ce0(local_2);
        PTR_DAT_00025d58[0x40b] = 1;
      }
      FUN_fffc5e0a(local_2,param_1);
      return;
    }
    FUN_fffc5c8f(local_2,param_1);
    return;
  }
  return;
}


// ===== FUN_fffc5c8f @ fffc5c8f (81 bytes)

void FUN_fffc5c8f(char param_1,undefined1 param_2)

{
  int iVar1;
  char local_3;
  
  if (param_1 == '\0') {
    local_3 = DAT_00009dbe;
  }
  else {
    local_3 = DAT_00009dbf;
  }
  if (local_3 == '\x02') {
    iVar1 = FUN_fffc2ecb(param_1);
    if (iVar1 == 1) {
      return;
    }
    FUN_fffc5ce0(param_1);
    PTR_DAT_00025d58[0x40b] = 1;
  }
  FUN_fffc5e0a(param_1,param_2);
  return;
}


// ===== FUN_fffc5ce0 @ fffc5ce0 (51 bytes)

void FUN_fffc5ce0(char param_1)

{
  int iVar1;
  undefined1 uStack_2;
  
  iVar1 = FUN_fffc5d13(param_1);
  if (iVar1 == 1) {
    uStack_2 = 4;
  }
  else {
    uStack_2 = 3;
  }
  if (param_1 != '\0') {
    DAT_00009dbf = uStack_2;
    return;
  }
  DAT_00009dbe = uStack_2;
  return;
}


// ===== FUN_fffc5d13 @ fffc5d13 (247 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc5d92) */
/* WARNING: Removing unreachable block (ram,0xfffc5d8c) */
/* WARNING: Removing unreachable block (ram,0xfffc5db6) */
/* WARNING: Removing unreachable block (ram,0xfffc5dbc) */

undefined1 FUN_fffc5d13(undefined1 param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bStack_3;
  
  bStack_3 = FUN_fffc2e65(param_1);
  if ((bStack_3 < 99) || (0x74 < bStack_3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if ((bStack_3 & 1) == 0) {
      bStack_3 = bStack_3 - 1;
    }
    iVar2 = FUN_fffc2e01(bStack_3);
    if ((iVar2 == 1) && (iVar2 = FUN_fffc2e01(*(undefined1 *)(bStack_3 + 1)), iVar2 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uVar3 = (uint)(byte)(&DAT_0000619a)[(uint)bStack_3 * 0x5a] << 0x18 |
              (uint)(byte)(&DAT_0000619d)[(uint)bStack_3 * 0x5a];
      uVar4 = (uint)(byte)(&DAT_000061f4)[(uint)bStack_3 * 0x5a] << 0x18 |
              (uint)(byte)(&DAT_000061f7)[(uint)bStack_3 * 0x5a];
      if (uVar4 < uVar3) {
        *(uint *)(PTR_DAT_00025d58 + 0x470) = uVar4;
        *(uint *)(PTR_DAT_00025d58 + 0x474) = uVar3;
      }
      else {
        *(uint *)(PTR_DAT_00025d58 + 0x470) = uVar3;
        *(uint *)(PTR_DAT_00025d58 + 0x474) = uVar4;
      }
      return 1;
    }
  }
  return 0;
}


// ===== FUN_fffc5e0a @ fffc5e0a (186 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc5e38) */
/* WARNING: Removing unreachable block (ram,0xfffc5e3e) */

void FUN_fffc5e0a(char param_1,byte param_2)

{
  uint local_c;
  byte *local_8;
  byte local_3;
  
  if (param_1 == '\0') {
    local_8 = (byte *)&DAT_00009d53;
  }
  else {
    local_8 = (byte *)&DAT_00009dad;
  }
  local_c = (uint)*local_8 << 0x18 | (uint)local_8[3];
  PTR_DAT_00025d58[0x46d] = 1;
  local_3 = 0;
  if (PTR_DAT_00025d58[0x47c] == '\0') {
    for (; local_3 < param_2; local_3 = local_3 + 1) {
      local_c = FUN_fffc5ec4(param_1,local_c);
    }
  }
  else {
    for (; local_3 < param_2; local_3 = local_3 + 1) {
      local_c = FUN_fffc6073(param_1,local_c);
    }
  }
  *local_8 = (byte)(local_c >> 0x18);
  local_8[1] = (byte)(local_c >> 0x10);
  local_8[2] = (byte)(local_c >> 8);
  local_8[3] = (byte)local_c;
  PTR_DAT_00025d58[0x46d] = 0;
  return;
}


// ===== FUN_fffc5ec4 @ fffc5ec4 (104 bytes)

void FUN_fffc5ec4(undefined1 param_1)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d58[0x415] == '\0') && (PTR_DAT_00025d58[0x46a] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc6103(param_1);
  }
  FUN_fffc616e(param_1);
  FUN_fffc5f2c(param_1);
  return;
}


// ===== FUN_fffc5f2c @ fffc5f2c (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc5f9a) */

undefined1 FUN_fffc5f2c(undefined1 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (PTR_DAT_00025d58[0x67] == '\0') {
    uVar1 = FUN_fffc10c3(param_1,*param_2);
    *param_2 = uVar1;
  }
  else if (DAT_00009c5e == '\x01') {
    uVar1 = FUN_fffc10c3(param_1,*param_2);
    *param_2 = uVar1;
  }
  else {
    iVar2 = FUN_fffc5f9d(param_1,*param_2);
    if (iVar2 == 0) {
      return 0;
    }
  }
  FUN_fffc125a(param_1);
  PTR_DAT_00025d58[0x40c] = 1;
  return 1;
}


// ===== FUN_fffc5f9d @ fffc5f9d (214 bytes)

undefined1 FUN_fffc5f9d(char param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined1 uStack_11;
  char local_a;
  
  if (param_1 == '\0') {
    local_a = DAT_00009dbe;
  }
  else {
    local_a = DAT_00009dbf;
  }
  if ((local_a == '\x02') || (local_a == '\a')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (local_a != '\b')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if ((local_a == '\x04') && (iVar2 = FUN_fff97784(), iVar2 != 2)) {
      return 0;
    }
  }
  else {
    iVar2 = FUN_fffc2ecb(param_1);
    if (iVar2 == 1) {
      return 0;
    }
  }
  if (PTR_DAT_00025d58[0xba] == '\x01') {
    if ((param_2 < 1800000) || (74999999 < param_2)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uStack_11 = 1;
    }
    else {
      uStack_11 = 0;
    }
  }
  else {
    FUN_fffb4f52(param_2);
    uStack_11 = FUN_fffb37fe();
  }
  return uStack_11;
}


// ===== FUN_fffc6073 @ fffc6073 (144 bytes)

void FUN_fffc6073(undefined1 param_1)

{
  bool bVar1;
  int iVar2;
  
  if ((PTR_DAT_00025d58[0x415] == '\0') && (PTR_DAT_00025d58[0x46a] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar2 = FUN_fffc6103(param_1), iVar2 == 0)) {
    FUN_fffc5f2c(param_1);
  }
  else {
    FUN_fffc616e(param_1);
    FUN_fffc5f2c(param_1);
  }
  return;
}


// ===== FUN_fffc6103 @ fffc6103 (107 bytes)

bool FUN_fffc6103(undefined1 param_1,uint *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uStack_14;
  
  DAT_0001b4e5 = 1;
  DAT_0001b4e6 = '\0';
  uStack_14 = FUN_fffc616e(param_1);
  DAT_0001b4e5 = 0;
  if (DAT_0001b4e6 == '\x01') {
    uStack_14 = uStack_14 * 10;
  }
  uVar1 = *param_2;
  uVar3 = uVar1;
  if ((uStack_14 & 0xff) != 0) {
    uVar3 = uVar1 / (uStack_14 & 0xff);
  }
  uVar2 = *param_2;
  if ((uStack_14 & 0xff) != 0) {
    uVar2 = uVar2 / (uStack_14 & 0xff);
  }
  *param_3 = uVar2 * uStack_14;
  return uVar1 == (uVar3 * uStack_14 & 0xff);
}


// ===== FUN_fffc616e @ fffc616e (320 bytes)

void FUN_fffc616e(int param_1)

{
  bool bVar1;
  byte local_d;
  
  local_d = DAT_00009d09;
  if (param_1 != 0) {
    local_d = DAT_00009d63;
  }
  local_d = local_d & 0xf;
  if ((PTR_DAT_00025d58[0x415] != '\x01') && (PTR_DAT_00025d58[0x46a] != '\x01')) {
    if ((PTR_DAT_00025d58[0x418] == '\x01') || (PTR_DAT_00025d58[0x46b] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if ((local_d == 6) || (local_d == 7)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 10)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 0xb)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 4)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 5)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_fffc63e6(local_d);
      }
      else {
        FUN_fffc62ae();
      }
    }
    else if (PTR_DAT_00025d58[0x46d] == '\x01') {
      FUN_fffc62ae(local_d);
    }
    else if (PTR_DAT_00025d58[0x478] == '\x01') {
      FUN_fffc63e6(local_d);
    }
    else {
      FUN_fffc62ae();
    }
  }
  return;
}


// ===== FUN_fffc62ae @ fffc62ae (312 bytes)

short FUN_fffc62ae(byte param_1)

{
  uint uVar1;
  short local_6;
  
  uVar1 = (uint)param_1;
  if (uVar1 - 0xc < 3) {
LAB_fffc6393:
    if (DAT_00009c61 == '\x01') {
      local_6 = 1;
    }
    else {
      if (DAT_00009afa == '\0') {
        local_6 = 5;
      }
      else if (DAT_00009afa == '\x01') {
        local_6 = 10;
      }
      else {
        local_6 = 0x14;
      }
      if (DAT_00009c61 == '\x02') {
        local_6 = local_6 * 10;
      }
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (DAT_00009c61 == '\x01') {
        return 10;
      }
      if (DAT_00009c61 != '\x02') {
        return 100;
      }
      return 1000;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc6393;
      if (1 < uVar1 - 10) {
        if (3 < uVar1) {
          return local_6;
        }
        if (DAT_00009c61 != '\x01') {
          if (DAT_00009af9 == '\0') {
            local_6 = 5;
          }
          else if (DAT_00009af9 == '\x01') {
            local_6 = 10;
          }
          else {
            local_6 = 0x14;
          }
          if (DAT_00009c61 != '\x02') {
            return local_6;
          }
          return local_6 * 10;
        }
        return 1;
      }
    }
    if (DAT_00009c61 == '\x01') {
      local_6 = 10;
    }
    else {
      local_6 = 100;
      if (DAT_00009c61 == '\x02') {
        local_6 = 1000;
      }
    }
  }
  return local_6;
}


// ===== FUN_fffc63e6 @ fffc63e6 (166 bytes)

void FUN_fffc63e6(byte param_1)

{
  uint uVar1;
  byte local_d;
  
  uVar1 = (uint)param_1;
  if (3 < uVar1) {
    if (uVar1 - 4 < 2) {
      local_d = DAT_00009afc;
      if (5 < DAT_00009afc) {
        local_d = 0;
      }
      FUN_fffc648c(*(undefined2 *)(&DAT_fff8851c + (uint)local_d * 2));
      return;
    }
    if (uVar1 - 6 < 2) {
LAB_fffc6462:
      local_d = DAT_00009afd;
      if (5 < DAT_00009afd) {
        local_d = 0;
      }
      FUN_fffc648c(*(undefined2 *)(&DAT_fff88528 + (uint)local_d * 2));
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 10 < 2) goto LAB_fffc6462;
      if (2 < uVar1 - 0xc) {
        return;
      }
    }
  }
  local_d = DAT_00009afb;
  if (3 < DAT_00009afb) {
    local_d = 0;
  }
  FUN_fffc648c(*(undefined2 *)(&DAT_fff88514 + (uint)local_d * 2));
  return;
}


// ===== FUN_fffc648c @ fffc648c (52 bytes)

void FUN_fffc648c(void)

{
  if ((DAT_00009c61 == '\x02') && (DAT_0001b4e5 == '\x01')) {
    DAT_0001b4e6 = 1;
  }
  return;
}


// ===== FUN_fffc64c0 @ fffc64c0 (213 bytes)

void FUN_fffc64c0(char param_1)

{
  bool bVar1;
  
  if (PTR_DAT_00025d58[0x437] == '\x01') {
    FUN_fffc670d((int)param_1);
    return;
  }
  FUN_fffc4caa();
  if (PTR_DAT_00025d58[0x9a] != '\x01') {
    if (PTR_DAT_00025d58[0x86] != '\x01') {
      if (PTR_DAT_00025d58[0x95] == '\x01') {
        FUN_fffd1790((int)param_1);
        return;
      }
      if (PTR_DAT_00025d58[0xba] != '\x01') {
        if ((PTR_DAT_00025d58[0x93] == '\x01') || (PTR_DAT_00025d58[0x94] == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (!bVar1) {
          if (PTR_DAT_00025d58[0x96] == '\x01') {
            FUN_fffc7c55((int)param_1);
            return;
          }
          FUN_fffc6c20((int)param_1);
          return;
        }
        FUN_fffc6595((int)param_1);
        return;
      }
      FUN_fffbb963((int)param_1);
      return;
    }
    if (PTR_DAT_00025d58[0x448] == '\x01') {
      if ('\0' < param_1) {
        PTR_DAT_00025d58[0xbd] = 1;
        return;
      }
      PTR_DAT_00025d58[0xbd] = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffc6595 @ fffc6595 (376 bytes)

void FUN_fffc6595(char param_1)

{
  if (PTR_DAT_00025d58[0x93] == '\x01') {
    if (PTR_DAT_00025d58[0x3fe] == '\x01') {
      PTR_DAT_00025d58[0x3f8] = 1;
      PTR_DAT_00025d58[0x3f9] = 4;
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (DAT_00009dc1 != 0)) {
          DAT_00009dc1 = DAT_00009dc1 - 1;
          return;
        }
      }
      else if (DAT_00009dc1 < 100) {
        DAT_00009dc1 = DAT_00009dc1 + 1;
        return;
      }
    }
    else {
      if (param_1 < '\0') {
        FUN_fffe3121();
        return;
      }
      if ('\0' < param_1) {
        FUN_fffe32fd();
        return;
      }
    }
  }
  else if (PTR_DAT_00025d58[0x94] == '\x01') {
    if (PTR_DAT_00025d58[0x1cf] == '\x01') {
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (DAT_00009dc1 != 0)) {
          DAT_00009dc1 = DAT_00009dc1 - 1;
          return;
        }
      }
      else if (DAT_00009dc1 < 100) {
        DAT_00009dc1 = DAT_00009dc1 + 1;
        return;
      }
    }
    else if (PTR_DAT_00025d58[0x1d0] == '\x01') {
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (DAT_00009dc2 != 0)) {
          DAT_00009dc2 = DAT_00009dc2 - 1;
          return;
        }
      }
      else if (DAT_00009dc2 < 100) {
        DAT_00009dc2 = DAT_00009dc2 + 1;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffc670d @ fffc670d (243 bytes)

void FUN_fffc670d(char param_1)

{
  int iVar1;
  
  if (DAT_0001b4eb == '\x01') {
    iVar1 = FUN_fffb23f3(0x47);
    if (iVar1 == 0) {
      return;
    }
    DAT_0001b4eb = '\0';
  }
  if (DAT_0001b4ea == '\0') {
    DAT_0001b4ea = 1;
    FUN_fff98727(DAT_0001b4e9,1);
    FUN_fffb237a(0x47,100);
    DAT_0001b4eb = 1;
    return;
  }
  DAT_0001b4ea = 0;
  FUN_fff98727(DAT_0001b4e9,0);
  FUN_fffb237a(0x47,100);
  DAT_0001b4eb = 1;
  if ('\0' < param_1) {
    if (DAT_0001b4e9 < DAT_0001b4e7) {
      DAT_0001b4e9 = DAT_0001b4e9 + 1;
      return;
    }
    DAT_0001b4e9 = DAT_0001b4e8;
    return;
  }
  if (DAT_0001b4e8 < DAT_0001b4e9) {
    DAT_0001b4e9 = DAT_0001b4e9 - 1;
    return;
  }
  DAT_0001b4e9 = DAT_0001b4e7;
  return;
}


// ===== FUN_fffc6800 @ fffc6800 (111 bytes)

void FUN_fffc6800(char param_1)

{
  char cVar1;
  
  if (PTR_DAT_00025d58[0x43c] == '\0') {
    if (PTR_DAT_00025d58[0x1d9] == '\0') {
      FUN_fffc686f((int)param_1);
      return;
    }
    if (PTR_DAT_00025d58[0x43b] == '\0') {
      FUN_fffc6bd8((int)param_1);
      return;
    }
  }
  cVar1 = PTR_DAT_00025d58[0x1da];
  if (cVar1 == '\x03') {
    FUN_fffc6b86((int)param_1);
    return;
  }
  if (cVar1 != '\x02') {
    if (cVar1 == '\x01') {
      FUN_fffc6ac4((int)param_1);
      return;
    }
    return;
  }
  FUN_fffc6b34((int)param_1);
  return;
}


// ===== FUN_fffc686f @ fffc686f (83 bytes)

void FUN_fffc686f(char param_1)

{
  if (param_1 < '\x01') {
    if (PTR_DAT_00025d58[0x1db] == 0) {
      FUN_fffc6a0a();
    }
    else {
      PTR_DAT_00025d58[0x1db] = PTR_DAT_00025d58[0x1db] + -1;
    }
  }
  else if ((byte)PTR_DAT_00025d58[0x1db] < 3) {
    PTR_DAT_00025d58[0x1db] = PTR_DAT_00025d58[0x1db] + '\x01';
  }
  else {
    FUN_fffc68c2();
  }
  FUN_fffc2b12();
  return;
}


// ===== FUN_fffc68c2 @ fffc68c2 (328 bytes)

void FUN_fffc68c2(void)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  
  if (PTR_DAT_00025d58[0x1db] != '\x03') {
    PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + '\x01';
    return;
  }
  bVar2 = PTR_DAT_00025d58[0x439] + PTR_DAT_00025d58[0x1db];
  if (bVar2 < 0x84) {
    bVar2 = bVar2 + 1;
    if (bVar2 < 0x75) {
      PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + '\x01';
      return;
    }
    sVar3 = FUN_fffb3b33();
    if ((sVar3 == 0x4380) || (sVar3 == 0x20b)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (sVar3 == 0x60e6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (sVar3 == 0x1cb9)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_00009af4 == '\x01') {
        PTR_DAT_00025d58[0x439] = 0x72;
        return;
      }
    }
    else {
      if ((sVar3 == 0x315b) || (sVar3 == 0x50e2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (bVar2 < 0x84) {
          PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + '\x01';
          return;
        }
        if (DAT_00009af4 == '\x01') {
          PTR_DAT_00025d58[0x439] = 0x81;
          return;
        }
      }
      else {
        if ((sVar3 == -0x26b0) || (sVar3 == -0x5b3b)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if ((bVar1) && (bVar2 < 0x7c)) {
          PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + '\x01';
          return;
        }
      }
    }
  }
  return;
}


// ===== FUN_fffc6a0a @ fffc6a0a (186 bytes)

void FUN_fffc6a0a(void)

{
  bool bVar1;
  short sVar2;
  
  if ((byte)PTR_DAT_00025d58[0x439] < 0x84) {
    if (PTR_DAT_00025d58[0x439] != '\0') {
      PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + -1;
      return;
    }
  }
  else {
    sVar2 = FUN_fffb3b33();
    if ((sVar2 == 0x315b) || (sVar2 == 0x50e2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d58[0x439] = 0x83;
      return;
    }
    if ((sVar2 == 0x4380) || (sVar2 == 0x20b)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (sVar2 == 0x60e6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (sVar2 == 0x1cb9)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d58[0x439] = 0x74;
      return;
    }
  }
  return;
}


// ===== FUN_fffc6ac4 @ fffc6ac4 (112 bytes)

void FUN_fffc6ac4(char param_1)

{
  byte *pbVar1;
  byte bStack_9;
  
  FUN_fffc8cbb(0x55);
  FUN_fffc8d8c();
  pbVar1 = &DAT_00006150 + (uint)(byte)PTR_DAT_00025d58[0x43a] * 0x5a;
  bStack_9 = *pbVar1 & 0xf;
  if (param_1 < '\x01') {
    if (bStack_9 != 0) {
      bStack_9 = bStack_9 - 1;
    }
  }
  else if (bStack_9 < 0xe) {
    bStack_9 = bStack_9 + 1;
  }
  *pbVar1 = *pbVar1 & 0xf0 | bStack_9;
  FUN_fffb0376(PTR_DAT_00025d58[0x43a]);
  return;
}


// ===== FUN_fffc6b34 @ fffc6b34 (82 bytes)

void FUN_fffc6b34(char param_1)

{
  byte *pbVar1;
  
  FUN_fffc8cbb(0x56);
  FUN_fffc8d8c();
  pbVar1 = &DAT_00006151 + (uint)(byte)PTR_DAT_00025d58[0x43a] * 0x5a;
  if (param_1 < '\x01') {
    *pbVar1 = *pbVar1 & 0x7f;
  }
  else {
    *pbVar1 = *pbVar1 | 0x80;
  }
  FUN_fffb0376(PTR_DAT_00025d58[0x43a]);
  return;
}


// ===== FUN_fffc6b86 @ fffc6b86 (82 bytes)

void FUN_fffc6b86(char param_1)

{
  byte *pbVar1;
  
  FUN_fffc8cbb(0x57);
  FUN_fffc8d8c();
  pbVar1 = &DAT_00006155 + (uint)(byte)PTR_DAT_00025d58[0x43a] * 0x5a;
  if (param_1 < '\x01') {
    *pbVar1 = *pbVar1 & 0x7f;
  }
  else {
    *pbVar1 = *pbVar1 | 0x80;
  }
  FUN_fffb0376(PTR_DAT_00025d58[0x43a]);
  return;
}


// ===== FUN_fffc6bd8 @ fffc6bd8 (72 bytes)

void FUN_fffc6bd8(char param_1)

{
  if (param_1 < '\x01') {
    if (PTR_DAT_00025d58[0x1da] != 0) {
      PTR_DAT_00025d58[0x1da] = PTR_DAT_00025d58[0x1da] + -1;
      return;
    }
  }
  else if ((byte)PTR_DAT_00025d58[0x1da] < 5) {
    PTR_DAT_00025d58[0x1da] = PTR_DAT_00025d58[0x1da] + '\x01';
    return;
  }
  return;
}

