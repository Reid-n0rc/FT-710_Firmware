// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff9ff30 @ fff9ff30 (129 bytes)

void FUN_fff9ff30(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sStack_a;
  
  iVar3 = FUN_fffb324c(param_1);
  bVar1 = *(byte *)(iVar3 + 6);
  bVar2 = FUN_fffb3196(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(&DAT_fff87f9a + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b6da == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x4025;
  DAT_0001b6e0 = sStack_a;
  FUN_fffa0b4c(0x77);
  return;
}


// ===== FUN_fff9ffb1 @ fff9ffb1 (129 bytes)

void FUN_fff9ffb1(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  short sStack_a;
  
  iVar3 = FUN_fffb324c(param_1);
  bVar1 = *(byte *)(iVar3 + 6);
  bVar2 = FUN_fffb3196(param_1);
  sStack_a = 0;
  if ((((bVar1 & 0x10) != 0) && (1 < bVar2 - 6)) && (1 < bVar2 - 10)) {
    sStack_a = *(short *)(&DAT_fff87fda + (uint)(bVar1 & 0xf) * 2);
  }
  if (DAT_0001b6dc == sStack_a) {
    return;
  }
  DAT_0001b6de = 0x4026;
  DAT_0001b6e0 = sStack_a;
  FUN_fffa0b4c(0x77);
  return;
}


// ===== FUN_fffa0032 @ fffa0032 (270 bytes)

void FUN_fffa0032(void)

{
  ushort uVar1;
  char local_6;
  byte local_5;
  ushort local_4;
  
  uVar1 = DAT_0001b636;
  if (DAT_00020b18 == '\b') {
    (&DAT_00001c64)[DAT_00001c66] = (char)(DAT_0001b636 >> 8);
    DAT_00001c66 = DAT_00001c66 + 1;
    if (1 < DAT_00001c66) {
      DAT_00001c66 = 0;
    }
    local_4 = 0;
    for (local_5 = 0; local_5 < 2; local_5 = local_5 + 1) {
      local_4 = (byte)(&DAT_00001c64)[local_5] + local_4;
    }
    DAT_00001c60 = (undefined1)(local_4 >> 1);
  }
  if ((uVar1 & 0x40) == 0) {
    (&DAT_00001c67)[DAT_00001c6c] = 0;
  }
  else {
    (&DAT_00001c67)[DAT_00001c6c] = 1;
  }
  DAT_00001c6c = DAT_00001c6c + 1;
  if (4 < DAT_00001c6c) {
    DAT_00001c6c = 0;
  }
  local_6 = '\0';
  for (local_5 = 0; local_5 < 5; local_5 = local_5 + 1) {
    local_6 = (&DAT_00001c67)[local_5] + local_6;
  }
  if (local_6 == '\x05') {
    DAT_00001c61 = 1;
    return;
  }
  if (local_6 == '\0') {
    DAT_00001c61 = 0;
    return;
  }
  return;
}


// ===== FUN_fffa0140 @ fffa0140 (178 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa01bf) */
/* WARNING: Removing unreachable block (ram,0xfffa019f) */
/* WARNING: Removing unreachable block (ram,0xfffa01c7) */
/* WARNING: Removing unreachable block (ram,0xfffa01de) */

void FUN_fffa0140(void)

{
  byte local_5;
  ushort local_4;
  ushort local_2;
  
  *(undefined2 *)(&DAT_0001b6e6 + (uint)DAT_00001c6d * 2) = DAT_0001b638;
  DAT_00001c6d = DAT_00001c6d + 1;
  if (0x1f < DAT_00001c6d) {
    DAT_00001c6d = 0;
  }
  local_4 = 0;
  local_2 = 0;
  for (local_5 = 0; local_5 < 0x20; local_5 = local_5 + 1) {
    local_2 = (*(ushort *)(&DAT_0001b6e6 + (uint)local_5 * 2) >> 8) + local_2;
    local_4 = (byte)(&DAT_0001b6e6)[(uint)local_5 * 2] + local_4;
  }
  DAT_0001b6e2 = local_2 / 0x20 << 8 | local_4 / 0x20;
  return;
}


// ===== FUN_fffa01f2 @ fffa01f2 (115 bytes)

void FUN_fffa01f2(void)

{
  byte local_3;
  ushort local_2;
  
  (&DAT_00001c6e)[DAT_00001c7e] = (char)DAT_0001b63a;
  DAT_00001c7e = DAT_00001c7e + 1;
  if (0xf < DAT_00001c7e) {
    DAT_00001c7e = 0;
  }
  local_2 = 0;
  for (local_3 = 0; local_3 < 0x10; local_3 = local_3 + 1) {
    local_2 = (byte)(&DAT_00001c6e)[local_3] + local_2;
  }
  DAT_00001c62 = (char)(local_2 >> 4);
  return;
}


// ===== FUN_fffa0265 @ fffa0265 (277 bytes)

void FUN_fffa0265(void)

{
  byte local_f [9];
  byte local_6;
  byte local_5;
  byte local_4;
  byte local_3;
  ushort local_2;
  
  local_3 = 8;
  local_f[1] = 0;
  local_f[2] = 0;
  local_f[3] = 0;
  local_f[4] = 0;
  local_f[5] = 0;
  local_f[6] = 0;
  local_f[7] = 0;
  local_f[0] = 0;
  *(undefined2 *)(&DAT_0001b726 + (uint)DAT_0001b3db * 2) = DAT_0001b63c;
  DAT_0001b3db = DAT_0001b3db + 1;
  if (7 < DAT_0001b3db) {
    DAT_0001b3db = 0;
  }
  for (local_4 = 0; local_4 < local_3; local_4 = local_4 + 1) {
    local_2 = *(ushort *)(&DAT_0001b726 + (uint)local_4 * 2);
    local_6 = 0;
    if (local_2 != 0x7fff) {
      for (local_5 = 0; local_5 < local_3; local_5 = local_5 + 1) {
        if (local_2 == (*(ushort *)(&DAT_0001b726 + (uint)local_5 * 2) & 0xff)) {
          local_6 = local_6 + 1;
        }
      }
    }
    local_f[local_4] = local_6;
  }
  local_6 = 0;
  for (local_4 = 0; local_4 < local_3; local_4 = local_4 + 1) {
    for (local_5 = 0; local_5 < local_3; local_5 = local_5 + 1) {
      if (local_6 < local_f[local_5]) {
        local_6 = local_f[local_5];
        local_f[8] = local_5;
      }
    }
  }
  if (local_6 < 2) {
    local_2 = 100;
  }
  else {
    local_2 = *(ushort *)(&DAT_0001b726 + (uint)local_f[8] * 2);
  }
  DAT_0001b6e4 = local_2;
  return;
}


// ===== FUN_fffa037a @ fffa037a (1884 bytes)

void FUN_fffa037a(void)

{
  if (DAT_0001b6de == 0) {
    DAT_0001b634 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 1) {
    DAT_0001b636 = DAT_0001b6e0;
    FUN_fffa0032();
    return;
  }
  if (DAT_0001b6de == 2) {
    DAT_0001b638 = DAT_0001b6e0;
    FUN_fffa0140();
    return;
  }
  if (DAT_0001b6de == 3) {
    DAT_0001b63a = DAT_0001b6e0;
    FUN_fffa01f2();
    return;
  }
  if (DAT_0001b6de == 4) {
    DAT_0001b63c = DAT_0001b6e0;
    FUN_fffa0265();
    return;
  }
  if (DAT_0001b6de == 0x4026) {
    DAT_0001b6dc = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 8) {
    DAT_0001b640 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 9) {
    DAT_0001b642 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 10) {
    DAT_0001b644 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xc) {
    DAT_0001b646 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xd) {
    DAT_0001b648 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xe) {
    DAT_0001b64a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xf) {
    DAT_0001b64c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x10) {
    DAT_0001b64e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x11) {
    DAT_0001b650 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x12) {
    DAT_0001b652 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x13) {
    DAT_0001b654 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x20) {
    DAT_0001b656 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x21) {
    DAT_0001b658 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x22) {
    DAT_0001b65a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x25) {
    DAT_0001b65c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x26) {
    DAT_0001b662 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x27) {
    DAT_0001b668 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x28) {
    DAT_0001b65e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x29) {
    DAT_0001b664 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2a) {
    DAT_0001b66a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2b) {
    DAT_0001b660 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2c) {
    DAT_0001b666 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2d) {
    DAT_0001b66c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2e) {
    DAT_0001b66e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2f) {
    DAT_0001b670 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x30) {
    DAT_0001b672 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x31) {
    DAT_0001b674 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x32) {
    DAT_0001b676 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x33) {
    DAT_0001b678 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x34) {
    DAT_0001b67a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x35) {
    DAT_0001b67c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x36) {
    DAT_0001b67e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x37) {
    DAT_0001b680 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x38) {
    DAT_0001b682 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x3a) {
    DAT_0001b684 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x3b) {
    DAT_0001b686 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x40) {
    DAT_0001b688 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x41) {
    DAT_0001b68a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x42) {
    DAT_0001b68c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x43) {
    DAT_0001b68e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x44) {
    DAT_0001b690 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x45) {
    DAT_0001b692 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x46) {
    DAT_0001b694 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x47) {
    DAT_0001b696 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x48) {
    DAT_0001b698 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x49) {
    DAT_0001b69e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4a) {
    DAT_0001b6a4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4b) {
    DAT_0001b69a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4c) {
    DAT_0001b6a0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4d) {
    DAT_0001b6a6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4e) {
    DAT_0001b69c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4f) {
    DAT_0001b6a2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x50) {
    DAT_0001b6a8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x51) {
    DAT_0001b6aa = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x52) {
    DAT_0001b6ac = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x53) {
    DAT_0001b6ae = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x54) {
    DAT_0001b6b0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x55) {
    DAT_0001b6b2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x56) {
    DAT_0001b6b4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x57) {
    DAT_0001b6b6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x58) {
    DAT_0001b6b8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x5c) {
    DAT_0001b6ba = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x5d) {
    DAT_0001b6bc = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x60) {
    DAT_0001b6be = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x61) {
    DAT_0001b6c0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x62) {
    DAT_0001b6c2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 99) {
    DAT_0001b6c4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 100) {
    DAT_0001b6c6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x65) {
    DAT_0001b6c8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x66) {
    DAT_0001b6ca = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x67) {
    DAT_0001b6cc = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x68) {
    DAT_0001b6ce = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x400b) {
    DAT_0001b6d0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x400d) {
    DAT_0001b6d2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4020) {
    DAT_0001b6d4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4022) {
    DAT_0001b6d6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4023) {
    DAT_0001b6d8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4025) {
    DAT_0001b6da = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de != 6) {
    return;
  }
  DAT_0001b63e = DAT_0001b6e0;
  return;
}


// ===== FUN_fffa0ad6 @ fffa0ad6 (118 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa0b49) */

undefined1 FUN_fffa0ad6(char param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_e;
  
  local_e = 0;
  iVar1 = FUN_fffb1a8f();
  if (iVar1 == 1) {
    uVar2 = FUN_fffb1aa8();
    *param_2 = uVar2;
    DAT_00001c5e = 0;
    DAT_00001c5f = 0;
    if (param_1 == 'r') {
      iVar1 = FUN_fffa0c2e((char *)*param_2,5);
      if (iVar1 == 1) {
        local_e = 1;
      }
    }
    else if (*(char *)*param_2 == '\x06') {
      local_e = 1;
    }
  }
  else {
    iVar1 = FUN_fffb23f3(3);
    if (iVar1 == 1) {
      DAT_00001c5e = 0;
      DAT_00001c5f = 0;
    }
  }
  return local_e;
}


// ===== FUN_fffa0b4c @ fffa0b4c (181 bytes)

void FUN_fffa0b4c(char param_1)

{
  undefined1 uVar1;
  byte local_2;
  
  DAT_00001a5e = param_1;
  word2hex(&DAT_00001a5f,DAT_0001b6de);
  local_2 = 5;
  if (param_1 == 'w') {
    word2hex(0x1a63,DAT_0001b6e0);
    local_2 = 9;
    DAT_00001c5e = 1;
  }
  else {
    DAT_00001c5f = 1;
  }
  uVar1 = FUN_fffa0c01(&DAT_00001a5e,local_2);
  byte2hex(&DAT_00001a5e + local_2,uVar1);
  (&DAT_00001a5e)[(byte)(local_2 + 2)] = 0xd;
  FUN_fffb1ab4(&DAT_00001a5e,local_2 + 3);
  FUN_fffb237a(3,6);
  return;
}


// ===== FUN_fffa0c01 @ fffa0c01 (45 bytes)

char FUN_fffa0c01(int param_1,byte param_2)

{
  undefined1 local_8;
  undefined1 local_7;
  
  local_8 = '\0';
  for (local_7 = 0; local_7 < param_2; local_7 = local_7 + 1) {
    local_8 = *(char *)((uint)local_7 + param_1) + local_8;
  }
  return local_8;
}


// ===== FUN_fffa0c2e @ fffa0c2e (75 bytes)

undefined1 FUN_fffa0c2e(int param_1,byte param_2)

{
  undefined1 uVar1;
  char cStack_8;
  char cStack_7;
  byte local_5;
  int local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uVar1 = FUN_fffa0c01(param_1,param_2);
  byte2hex(&cStack_8,uVar1);
  if ((cStack_8 == *(char *)((uint)local_5 + local_4)) &&
     (cStack_7 == *(char *)(local_4 + (uint)local_5 + 1))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_fffa0c79 @ fffa0c79 (449 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa0c79) */
/* WARNING: Removing unreachable block (ram,0xfffa0d7d) */
/* WARNING: Removing unreachable block (ram,0xfffa0da3) */

undefined4 FUN_fffa0c79(void)

{
  bool bVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined1 auStack_40c [516];
  char acStack_208 [516];
  
  FUN_fffb1ab4(&DAT_00001a5e,0);
  DAT_00001c63 = 0;
  FUN_fffb7080(0);
  FUN_fffb7098(1);
  FUN_fffb237a(0x1e,100);
  do {
    iVar4 = FUN_fffb23f3(0x1e);
  } while (iVar4 != 1);
  FUN_fffb7080(1);
  FUN_fffb237a(0x1e,100);
  do {
    iVar4 = FUN_fffb23f3(0x1e);
  } while (iVar4 != 1);
  DAT_00001a5e = 0x5a;
  DAT_00001a5f = 0xa6;
  FUN_fffb1ab4(&DAT_00001a5e,2);
  FUN_fffb237a(0x1e,0x32);
  do {
    iVar4 = FUN_fffb23f3(0x1e);
  } while (iVar4 != 1);
  FUN_fffb1ab4(&DAT_00001a5e,0);
  do {
    iVar4 = sci1_tx_end();
  } while (iVar4 == 0);
  auStack_40c[0] = 6;
  FUN_fffb175b(auStack_40c,1);
  do {
    FUN_fffb3e6a();
    iVar4 = FUN_fffb171e();
    if (iVar4 == 1) {
      pcVar5 = (char *)FUN_fffb174f();
      pcVar6 = acStack_208;
      for (iVar4 = 0x204; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pcVar6 = *pcVar5;
        pcVar6 = pcVar6 + 1;
        pcVar5 = pcVar5 + 1;
      }
      FUN_fffb172d();
      if (acStack_208[0] != '\x06') {
        if ((acStack_208[0] == -0xf) && (acStack_208[1] == -0x7e)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          do {
            iVar4 = sci1_tx_end();
          } while (iVar4 == 0);
          auStack_40c[0] = 6;
          uVar7 = FUN_fffb175b(auStack_40c,1);
          return uVar7;
        }
        if (acStack_208[0] == 'Z') {
          do {
            iVar4 = sci1_tx_end();
          } while (iVar4 == 0);
          auStack_40c[0] = 6;
          FUN_fffb175b(auStack_40c,1);
          pcVar6 = acStack_208 + 3;
          pcVar5 = &DAT_00001a5e;
          for (uVar10 = (uint)CONCAT11(acStack_208[2],acStack_208[1]); uVar10 != 0;
              uVar10 = uVar10 - 1) {
            *pcVar5 = *pcVar6;
            pcVar5 = pcVar5 + 1;
            pcVar6 = pcVar6 + 1;
          }
          FUN_fffb1ab4(&DAT_00001a5e,CONCAT11(acStack_208[2],acStack_208[1]));
        }
      }
    }
    iVar4 = FUN_fffb1a8f();
    if (iVar4 == 1) {
      puVar8 = (undefined1 *)FUN_fffb1aa8();
      uVar3 = FUN_fffb1ae9();
      do {
        iVar4 = sci1_tx_end();
      } while (iVar4 == 0);
      auStack_40c[0] = 0x5a;
      auStack_40c[1] = (undefined1)uVar3;
      auStack_40c[2] = (undefined1)(uVar3 >> 8);
      puVar9 = auStack_40c + 3;
      for (uVar10 = (uint)uVar3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar9 = *puVar8;
        puVar9 = puVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      uVar2 = FUN_fffa0c01(auStack_40c,*(undefined1 *)(uint)(ushort)(uVar3 + 3));
      ((undefined1 *)(uint)(ushort)(uVar3 + 3))[(int)auStack_40c] = uVar2;
      FUN_fffb175b(auStack_40c,uVar3 + 4);
      FUN_fffb1ab4(&DAT_00001a5e,0);
    }
  } while( true );
}


// ===== FUN_fffa0e3a @ fffa0e3a (760 bytes)

undefined2 FUN_fffa0e3a(ushort param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uStack_a;
  
  iVar2 = FUN_fffb4219();
  uStack_a = 0;
  switch(iVar2) {
  case 0:
    if (param_1 == 0x20) {
      uStack_a = 0xffff;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x52;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 1:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x50;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 2:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x52;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 3:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 2;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 4:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 2;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 5:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 3;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 6:
    uVar1 = (uint)param_1;
    if (uVar1 == 0x20) {
      uStack_a = 0;
    }
    else if (uVar1 == 9) {
      uStack_a = 0;
    }
    else if (uVar1 == 10) {
      uStack_a = 0x22;
    }
    else if (uVar1 - 0xd < 2) {
      uStack_a = 0xf000;
    }
    else if (uVar1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 7:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x22;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 8:
    if (param_1 == 0x20) {
      uStack_a = 0xffff;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x52;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 9:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x50;
    }
    else if (param_1 == 8) {
      uStack_a = DAT_00020b34;
    }
    break;
  case 10:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x22;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 0xb:
  case 0xc:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 3;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 0xd:
    if (param_1 == 0x20) {
      uStack_a = 0xffff;
    }
    else if (param_1 == 9) {
      uStack_a = 2;
    }
    else if (param_1 == 10) {
      uStack_a = 0x22;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2222;
    }
    break;
  case 0xe:
    if (param_1 == 0x20) {
      uStack_a = 0xfffe;
    }
    else if (param_1 == 9) {
      uStack_a = 2;
    }
    else if (param_1 == 10) {
      uStack_a = 3;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2222;
    }
  }
  if (((param_1 == 0x25) || (param_1 == 0x28)) || (param_1 == 0x2b)) {
    if (iVar2 < 8) {
      uStack_a = 0;
    }
    else {
      uStack_a = 0xffff;
    }
  }
  if (param_1 == 0x20) {
    DAT_00020b49 = 1;
  }
  return uStack_a;
}


// ===== FUN_fffa1132 @ fffa1132 (187 bytes)

void FUN_fffa1132(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  local_7 = 0x56;
  local_6 = 0x2a;
  local_5 = 0x2a;
  local_4 = 0x2d;
  local_3 = 0x2a;
  local_2 = 0x2a;
  local_1 = 0;
  FUN_fffb7051(1);
  FUN_fffb237a(0x1f,1000);
  do {
    iVar1 = FUN_fffb23f3(0x1f);
  } while (iVar1 != 1);
  puVar2 = (undefined4 *)&DAT_0001b736;
  for (iVar1 = 0x4e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xff;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  DAT_00001c8b = 0;
  DAT_00001c8d = 0;
  FUN_fffa1580();
  iVar1 = FUN_fffa2ff7(0x72,0);
  if (iVar1 != 1) {
    DAT_00020b36 = 3;
    return;
  }
  FUN_fffa1590();
  iVar1 = FUN_fffa2ff7(0x72,0);
  if (iVar1 != 1) {
    DAT_00020b36 = 3;
    return;
  }
  word2hex(&uStack_b,DAT_0001b736);
  local_6 = uStack_b;
  local_5 = uStack_a;
  local_3 = uStack_9;
  local_2 = uStack_8;
  FUN_fff94c57(&local_7);
  return;
}


// ===== FUN_fffa11ed @ fffa11ed (664 bytes)

void FUN_fffa11ed(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = DAT_00020b6b;
  cVar2 = DAT_00020b18;
  if (DAT_00001c8b == '\x01') {
    iVar4 = FUN_fffa3083(0x77);
    if (iVar4 != 1) {
      return;
    }
    FUN_fffa2c9f();
  }
  if (DAT_00001c8d == '\x01') {
    sdr_bridge_mode();
  }
  if (DAT_0001b3dd != cVar3) {
    if ((cVar3 == '\x01') && (iVar4 = FUN_fffb721a(), iVar4 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    if ((cVar3 == '\0') && (iVar4 = FUN_fffb6fac(), iVar4 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    DAT_0001b3dd = cVar3;
  }
  FUN_fffa1738(cVar3);
  if (((((((((DAT_00001c8b == '\0') && (FUN_fffa17dc(cVar3), DAT_00001c8b == '\0')) &&
           (FUN_fffa183d(), DAT_00001c8b == '\0')) &&
          ((FUN_fffa18ae(), DAT_00001c8b == '\0' && (FUN_fffa1929(cVar3), DAT_00001c8b == '\0'))))
         && (FUN_fffa2758(cVar3), DAT_00001c8b == '\0')) &&
        (((FUN_fffa28ea(cVar3), DAT_00001c8b == '\0' && (FUN_fffa2992(), DAT_00001c8b == '\0')) &&
         ((FUN_fffa2a16(cVar3), DAT_00001c8b == '\0' &&
          (((FUN_fffa2b8f(cVar3), DAT_00001c8b == '\0' &&
            (FUN_fffa2c03(cVar3), DAT_00001c8b == '\0')) && (FUN_fffa15a0(), DAT_00001c8b == '\0')))
          ))))) &&
       ((FUN_fffa162c(), DAT_00001c8b == '\0' && (FUN_fffa18f8(), DAT_00001c8b == '\0')))) &&
      (FUN_fffa1a0e(), DAT_00001c8b == '\0')) &&
     ((cVar3 != '\0' ||
      ((((FUN_fffa15f3(), DAT_00001c8b == '\0' && (FUN_fffa19ac(), DAT_00001c8b == '\0')) &&
        ((FUN_fffa19dd(), DAT_00001c8b == '\0' &&
         (((FUN_fffa1abb(), DAT_00001c8b == '\0' && (FUN_fffa1c69(), DAT_00001c8b == '\0')) &&
          (FUN_fffa1fd1(), DAT_00001c8b == '\0')))))) &&
       (((FUN_fffa2049(), DAT_00001c8b == '\0' && (FUN_fffa20af(), DAT_00001c8b == '\0')) &&
        ((FUN_fffa20f7(), DAT_00001c8b == '\0' &&
         ((FUN_fffa2478(), DAT_00001c8b == '\0' && (FUN_fffa26cf(), DAT_00001c8b == '\0'))))))))))))
  {
    if (DAT_0001b3dc == '\0') {
      FUN_fffa1a8a();
      if (DAT_00001c8b != '\0') {
        return;
      }
      FUN_fffa29e5();
      if (DAT_00001c8b != '\0') {
        return;
      }
      DAT_0001b3dc = '\x01';
    }
    if ((cVar2 == '\x01') || (cVar2 == '\a')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00020b19 = 1;
      return;
    }
  }
  return;
}


// ===== sdr_reg_access @ fffa1485 (135 bytes)

/* SDR register r/w over SCI5 ('r'/'w' + hex addr [+ value] + sum + CR, waits for reply) */

undefined1 sdr_reg_access(undefined2 param_1,undefined2 *param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 local_b;
  
  local_b = 0;
  while( true ) {
    if ((DAT_00001c8b == '\x01') || (DAT_00001c8c == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) break;
    FUN_fffa11ed();
  }
  DAT_0001b784 = param_1;
  if (param_3 == '\0') {
    FUN_fffa30f9(0x72);
    iVar2 = FUN_fffa2ff7(0x72,1);
    if (iVar2 == 1) {
      *param_2 = DAT_0001b782;
      local_b = 1;
    }
  }
  else {
    DAT_0001b786 = *param_2;
    FUN_fffa30f9(0x77);
    local_b = FUN_fffa2ff7(0x77,1);
  }
  return local_b;
}


// ===== FUN_fffa150c @ fffa150c (53 bytes)

void FUN_fffa150c(undefined4 param_1)

{
  FUN_fffb3480(param_1);
  return;
}


// ===== FUN_fffa1541 @ fffa1541 (53 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa155b) */

void FUN_fffa1541(undefined4 param_1)

{
  FUN_fffb3480(param_1);
  return;
}


// ===== FUN_fffa1576 @ fffa1576 (10 bytes)

void FUN_fffa1576(void)

{
  DAT_00001c8d = 1;
  return;
}


// ===== FUN_fffa1580 @ fffa1580 (16 bytes)

void FUN_fffa1580(void)

{
  DAT_0001b784 = 0;
  FUN_fffa30f9(0x72);
  return;
}


// ===== FUN_fffa1590 @ fffa1590 (16 bytes)

void FUN_fffa1590(void)

{
  DAT_0001b784 = 1;
  FUN_fffa30f9(0x72);
  return;
}


// ===== FUN_fffa15a0 @ fffa15a0 (83 bytes)

void FUN_fffa15a0(void)

{
  uint uVar1;
  undefined2 uStack_6;
  
  uVar1 = FUN_fffb357c(1,2);
  if (uVar1 < 0x3b9aca1) {
    uStack_6 = -0x19c3;
  }
  else {
    uStack_6 = -0x19e3;
  }
  if (DAT_0001b73a == uStack_6) {
    return;
  }
  DAT_0001b784 = 3;
  DAT_0001b786 = uStack_6;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa15f3 @ fffa15f3 (57 bytes)

void FUN_fffa15f3(void)

{
  FUN_fffb324c(0);
  if (DAT_0001b73c == -0x1ae7) {
    return;
  }
  DAT_0001b784 = 4;
  DAT_0001b786 = 0xe519;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa162c @ fffa162c (268 bytes)

void FUN_fffa162c(void)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  ushort uStack_6;
  undefined4 uStack_4;
  
  cVar1 = FUN_fffb3196(1);
  uStack_4 = DAT_00020f50;
  if (cVar1 == '\x0e') {
    if (DAT_00009a79 == '\x01') {
      uStack_6 = 0x5dc;
    }
    else if (DAT_00009a79 == '\x02') {
      uStack_6 = 2000;
    }
    else {
      uStack_6 = 1000;
    }
    uStack_4 = DAT_00020f50 - uStack_6;
  }
  else {
    iVar3 = FUN_fffba192();
    if (iVar3 == 3) {
      uVar2 = (ushort)DAT_00009c04 * 10 + 300;
      if (cVar1 == '\0') {
        uStack_4 = uStack_4 - uVar2;
      }
      else if (cVar1 == '\x01') {
        uStack_4 = uStack_4 + uVar2;
      }
      DAT_0001b3de = '\x01';
    }
    else if (DAT_0001b3de == '\x01') {
      iVar3 = FUN_fffb6fac();
      if (iVar3 == 1) {
        return;
      }
      DAT_0001b3de = '\0';
    }
  }
  if (uStack_4._2_2_ == DAT_0001b73e) {
    if ((uStack_4 & 0xffff) == (uint)DAT_0001b740) {
      return;
    }
    DAT_0001b784 = 9;
    DAT_0001b786 = (undefined2)uStack_4;
    FUN_fffa30f9(0x77);
    return;
  }
  DAT_0001b784 = 8;
  DAT_0001b786 = uStack_4._2_2_;
  FUN_fffa30f9(0x77);
  DAT_0001b740 = 0xffff;
  return;
}


// ===== FUN_fffa1738 @ fffa1738 (164 bytes)

void FUN_fffa1738(undefined1 param_1)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  short sStack_4;
  
  bVar2 = FUN_fffb3196(param_1);
  cVar3 = FUN_fffb6ec5();
  if (cVar3 == '\0') {
    return;
  }
  uVar1 = (uint)bVar2;
  if (uVar1 == 0) {
LAB_fffa1791:
    sStack_4 = 3;
    iVar4 = FUN_fffba192();
    if (iVar4 == 3) {
      sStack_4 = 0;
    }
  }
  else {
    if ((uVar1 == 1) || (uVar1 == 0xe)) {
LAB_fffa17a1:
      sStack_4 = 4;
      iVar4 = FUN_fffba192();
      if (iVar4 == 3) {
        sStack_4 = 0;
      }
      goto LAB_fffa17b2;
    }
    if (uVar1 - 4 < 2) {
      sStack_4 = 1;
      goto LAB_fffa17b2;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 == 8) goto LAB_fffa1791;
      if (uVar1 == 9) goto LAB_fffa17a1;
      if (1 < uVar1 - 10) {
        if (uVar1 == 2 || uVar1 == 3) {
          sStack_4 = 0;
        }
        else {
          sStack_4 = 5;
        }
        goto LAB_fffa17b2;
      }
    }
    sStack_4 = 2;
  }
LAB_fffa17b2:
  if (DAT_0001b742 == sStack_4) {
    return;
  }
  DAT_0001b784 = 10;
  DAT_0001b786 = sStack_4;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa17dc @ fffa17dc (97 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa17fc) */

void FUN_fffa17dc(char param_1)

{
  byte bVar1;
  undefined4 uVar2;
  short sStack_a;
  
  FUN_fffb3196(param_1);
  uVar2 = FUN_fffb357c(param_1,2);
  bVar1 = FUN_fffb3445(uVar2);
  if (param_1 == '\0') {
    sStack_a = *(short *)(&DAT_fff87ffa + (uint)bVar1 * 8);
  }
  else {
    sStack_a = *(short *)(&DAT_fff87ffe + (uint)bVar1 * 8);
  }
  if (DAT_0001b744 != sStack_a) {
    DAT_0001b784 = 0xb;
    DAT_0001b786 = sStack_a;
    FUN_fffa30f9(0x77);
    return;
  }
  return;
}


// ===== FUN_fffa183d @ fffa183d (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa1872) */
/* WARNING: Removing unreachable block (ram,0xfffa187a) */

void FUN_fffa183d(void)

{
  ushort uVar1;
  undefined2 local_2;
  
  if (DAT_00009a8d == '\x01') {
    local_2 = 200;
  }
  else if (DAT_00009a8d == '\x02') {
    local_2 = 0x1a9;
  }
  else if (DAT_00009a8d == '\x03') {
    local_2 = 0x352;
  }
  else {
    local_2 = 0xaa;
  }
  uVar1 = local_2 / 5 << 8 | 3;
  if (DAT_0001b746 == uVar1) {
    return;
  }
  DAT_0001b784 = 0xc;
  DAT_0001b786 = uVar1;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa18ae @ fffa18ae (74 bytes)

void FUN_fffa18ae(void)

{
  undefined2 local_2;
  
  if (DAT_00009aa1 == '\x01') {
    local_2 = 0xe;
  }
  else if (DAT_00009aa1 == '\0') {
    local_2 = 9;
  }
  else {
    local_2 = 0x13;
  }
  if (DAT_0001b748 == local_2) {
    return;
  }
  DAT_0001b784 = 0xd;
  DAT_0001b786 = local_2;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa18f8 @ fffa18f8 (49 bytes)

void FUN_fffa18f8(void)

{
  if (DAT_0001b74a == 0x1200) {
    return;
  }
  DAT_0001b784 = 0xe;
  DAT_0001b786 = 0x1200;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa1929 @ fffa1929 (131 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa196a) */

void FUN_fffa1929(char param_1)

{
  byte bVar1;
  undefined4 uVar2;
  short sStack_a;
  
  FUN_fffb3196(param_1);
  if (DAT_00020b14 < 0xe8b) {
    if (0x9b2 < DAT_00020b14) {
      return;
    }
    uVar2 = FUN_fffb357c(param_1,2);
    bVar1 = FUN_fffb3445(uVar2);
    if (param_1 == '\0') {
      sStack_a = *(short *)(&DAT_fff87ffc + (uint)bVar1 * 8);
    }
    else {
      sStack_a = *(short *)(&DAT_fff88000 + (uint)bVar1 * 8);
    }
  }
  else {
    sStack_a = 0;
  }
  if (DAT_0001b74c == sStack_a) {
    return;
  }
  DAT_0001b784 = 0xf;
  DAT_0001b786 = sStack_a;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa19ac @ fffa19ac (49 bytes)

void FUN_fffa19ac(void)

{
  if (DAT_0001b74e == -0x8000) {
    return;
  }
  DAT_0001b784 = 0x12;
  DAT_0001b786 = 0x8000;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa19dd @ fffa19dd (49 bytes)

void FUN_fffa19dd(void)

{
  if (DAT_0001b750 == -0x8000) {
    return;
  }
  DAT_0001b784 = 0x13;
  DAT_0001b786 = 0x8000;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa1a0e @ fffa1a0e (124 bytes)

void FUN_fffa1a0e(void)

{
  undefined1 uVar1;
  short sStack_2;
  
  uVar1 = FUN_fffb3196(1);
  switch(uVar1) {
  case 2:
  case 3:
    sStack_2 = 0x2000;
    break;
  case 4:
  case 5:
    sStack_2 = 0x3200;
    break;
  case 6:
  case 10:
    sStack_2 = 0x7800;
    break;
  case 7:
  case 0xb:
    sStack_2 = 0x3c00;
    break;
  case 8:
  case 9:
    sStack_2 = 0x2000;
    break;
  case 0xc:
  case 0xd:
    sStack_2 = 0x2000;
    break;
  case 0xe:
    sStack_2 = 0x2000;
    break;
  default:
    sStack_2 = 0x2000;
  }
  if (DAT_0001b752 != sStack_2) {
    DAT_0001b784 = 0x14;
    DAT_0001b786 = sStack_2;
    FUN_fffa30f9(0x77);
    return;
  }
  return;
}


// ===== FUN_fffa1a8a @ fffa1a8a (49 bytes)

void FUN_fffa1a8a(void)

{
  if (DAT_0001b754 == 0x2000) {
    return;
  }
  DAT_0001b784 = 0x15;
  DAT_0001b786 = 0x2000;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa1abb @ fffa1abb (430 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa1ae7) */

void FUN_fffa1abb(void)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  char *pcVar5;
  undefined1 uStack_7;
  undefined1 uStack_6;
  short sStack_2;
  
  bVar3 = FUN_fffb3196(0);
  pcVar5 = (char *)FUN_fffb54a0();
  bVar1 = *pcVar5 == '\0';
  FUN_fffc4e4f();
  uVar4 = CONCAT11(uStack_7,uStack_6);
  uVar2 = (uint)bVar3;
  if (1 < uVar2 - 10) {
    if (uVar2 == 4) {
      sStack_2 = 0x21;
      DAT_00020b4a = 0x1e;
      goto LAB_fffa1c3f;
    }
    if (uVar2 == 5) {
      sStack_2 = 0x20;
      DAT_00020b4a = 0x1e;
      goto LAB_fffa1c3f;
    }
    if (uVar2 != 6) {
      if (uVar2 == 7) {
        sStack_2 = 0x30;
        DAT_00020b4a = 0x1e;
      }
      else if (uVar2 == 2 || uVar2 == 3) {
        if (uVar4 < 0xfb) {
          sStack_2 = 0;
          if (bVar1) {
            DAT_00020b4a = 0x4a;
          }
          else {
            DAT_00020b4a = 0x54;
          }
        }
        else if (uVar4 < 800) {
          sStack_2 = 1;
          if (bVar1) {
            DAT_00020b4a = 0x27;
          }
          else {
            DAT_00020b4a = 0x31;
          }
        }
        else {
          sStack_2 = 2;
          if (bVar1) {
            DAT_00020b4a = 0x17;
          }
          else {
            DAT_00020b4a = 0x21;
          }
        }
      }
      else if (uVar4 < 0x44d) {
        sStack_2 = 0x10;
        if (bVar1) {
          DAT_00020b4a = 0x1f;
        }
        else {
          DAT_00020b4a = 0x29;
        }
      }
      else if (uVar4 < 2000) {
        sStack_2 = 0x11;
        if (bVar1) {
          DAT_00020b4a = 0x17;
        }
        else {
          DAT_00020b4a = 0x21;
        }
      }
      else {
        sStack_2 = 0x12;
        if (bVar1) {
          DAT_00020b4a = 0x15;
        }
        else {
          DAT_00020b4a = 0x1f;
        }
      }
      goto LAB_fffa1c3f;
    }
  }
  sStack_2 = 0x31;
  DAT_00020b4a = 0x1e;
LAB_fffa1c3f:
  if (DAT_0001b756 == sStack_2) {
    return;
  }
  DAT_0001b784 = 0x16;
  DAT_0001b786 = sStack_2;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa1c69 @ fffa1c69 (872 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa1e44) */
/* WARNING: Removing unreachable block (ram,0xfffa1eab) */
/* WARNING: Removing unreachable block (ram,0xfffa1e6a) */
/* WARNING: Removing unreachable block (ram,0xfffa1e83) */
/* WARNING: Removing unreachable block (ram,0xfffa1e1c) */
/* WARNING: Removing unreachable block (ram,0xfffa1d55) */
/* WARNING: Removing unreachable block (ram,0xfffa1cdf) */
/* WARNING: Removing unreachable block (ram,0xfffa1c97) */
/* WARNING: Removing unreachable block (ram,0xfffa1f47) */
/* WARNING: Removing unreachable block (ram,0xfffa1d04) */
/* WARNING: Removing unreachable block (ram,0xfffa1d7f) */
/* WARNING: Removing unreachable block (ram,0xfffa1dcd) */
/* WARNING: Removing unreachable block (ram,0xfffa1de8) */
/* WARNING: Removing unreachable block (ram,0xfffa1ed4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffa1c69(void)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined1 uStack_16;
  undefined1 uStack_15;
  short sStack_12;
  ushort uStack_a;
  undefined4 uStack_8;
  
  iVar7 = FUN_fffb324c(0);
  bVar3 = FUN_fffb3196(0);
  uStack_8 = FUN_fffb35d7(0,2);
  uVar2 = (uint)bVar3;
  if (uVar2 == 0xe) {
    uVar4 = CONCAT11(*(byte *)(iVar7 + 0x30),*(undefined1 *)(iVar7 + 0x31));
    if ((*(byte *)(iVar7 + 0x30) & 0x80) == 0) {
      uStack_8 = uVar4 + uStack_8;
    }
    else {
      uStack_8 = uStack_8 - (ushort)(~uVar4 + 1);
    }
  }
  else if (uVar2 - 2 < 2) {
    bVar1 = *(byte *)(iVar7 + 0x1c);
    uVar5 = CONCAT11(bVar1,*(undefined1 *)(iVar7 + 0x1d));
    FUN_fffc4e4f();
    uVar4 = (ushort)DAT_00009c04 * 10 + 300;
    if (CONCAT11(uStack_16,uStack_15) < uVar4) {
      if ((bVar1 & 0x80) != 0) {
        _DAT_0000464f = 1;
      }
      if (bVar3 == 2) {
        uStack_8 = uStack_8 + (ushort)(~uVar5 + 1);
      }
      else {
        uStack_8 = uStack_8 - (ushort)(~uVar5 + 1);
      }
    }
    else {
      uVar5 = (short)((int)((uint)CONCAT11(uStack_16,uStack_15) - (uint)uVar4) / 2) + uVar5;
      if ((uVar5 & 0x8000) != 0) {
        _DAT_0000464f = 1;
      }
      if (bVar3 == 2) {
        uStack_8 = uStack_8 + (ushort)(~uVar5 + 1);
      }
      else {
        uStack_8 = uStack_8 - (ushort)(~uVar5 + 1);
      }
    }
  }
  else {
    puVar8 = (undefined4 *)(uVar2 - 8);
    if (puVar8 < (undefined4 *)0x2) {
      uVar4 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 +
              CONCAT11(*(undefined1 *)(iVar7 + 0x30),*(undefined1 *)(iVar7 + 0x31));
      if ((uVar4 & 0x8000) != 0) {
        *puVar8 = 1;
      }
      if (bVar3 == 8) {
        uStack_8 = uStack_8 - uVar4;
      }
      else if (puVar8 == (undefined4 *)0x0) {
        uStack_8 = uStack_8 + uVar4;
      }
      else {
        uStack_8 = uStack_8 - (ushort)(~uVar4 + 1);
      }
    }
    else {
      puVar8 = (undefined4 *)(uVar2 - 0xc);
      if (puVar8 < (undefined4 *)0x2) {
        sVar6 = CONCAT11(*(undefined1 *)(iVar7 + 0x26),*(byte *)(iVar7 + 0x27));
        if (DAT_00009a8d == '\x01') {
          sStack_12 = 0x69;
        }
        else if (DAT_00009a8d == '\x02') {
          sStack_12 = 0xd7;
        }
        else if (DAT_00009a8d == '\x03') {
          sStack_12 = 0x1a9;
        }
        else {
          sStack_12 = 0x55;
        }
        if (bVar3 != 0xc) {
          sVar6 = -(ushort)*(byte *)(iVar7 + 0x27);
        }
        uStack_a = sStack_12 + sVar6;
        if ((uStack_a & 0x8000) == 0) {
          uStack_8 = uStack_8 - (uStack_a & 0xff);
        }
        else {
          uStack_8 = uStack_8 + (ushort)(~uStack_a + 1);
        }
      }
      else if (uVar2 < 2) {
        uVar4 = CONCAT11(*(undefined1 *)(iVar7 + 0x12),*(undefined1 *)(iVar7 + 0x13)) + 0x5dc;
        if ((uVar4 & 0x8000) != 0) {
          *puVar8 = 1;
        }
        if (bVar3 == 0) {
          uStack_8 = uStack_8 + (ushort)(~uVar4 + 1);
        }
        else if (puVar8 == (undefined4 *)0x0) {
          uStack_8 = uStack_8 + uVar4;
        }
        else {
          uStack_8 = uStack_8 - (ushort)(~uVar4 + 1);
        }
      }
    }
  }
  if (uStack_8._2_2_ == DAT_0001b758) {
    if ((uStack_8 & 0xffff) == (uint)DAT_0001b75a) {
      return;
    }
    DAT_0001b784 = 0x19;
    DAT_0001b786 = (undefined2)uStack_8;
    FUN_fffa30f9(0x77);
    return;
  }
  DAT_0001b784 = 0x18;
  DAT_0001b786 = uStack_8._2_2_;
  FUN_fffa30f9(0x77);
  DAT_0001b75a = 0xffff;
  return;
}


// ===== FUN_fffa1fd1 @ fffa1fd1 (120 bytes)

void FUN_fffa1fd1(void)

{
  byte bVar1;
  int iVar2;
  short sStack_6;
  
  iVar2 = FUN_fffb324c(0);
  bVar1 = DAT_00009dc0;
  if ((*(byte *)(iVar2 + 2) & 2) == 0) {
    sStack_6 = 0;
  }
  else {
    iVar2 = FUN_fffb3196(0);
    if (iVar2 == 4 || iVar2 == 5) {
      sStack_6 = *(short *)(&DAT_fff8808a + (uint)bVar1 * 2);
    }
    else {
      sStack_6 = *(short *)(&DAT_fff880a0 + (uint)bVar1 * 2);
    }
  }
  if (DAT_0001b75c == sStack_6) {
    return;
  }
  DAT_0001b784 = 0x1a;
  DAT_0001b786 = sStack_6;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa2049 @ fffa2049 (102 bytes)

void FUN_fffa2049(void)

{
  byte bVar1;
  int iVar2;
  short sStack_2;
  
  FUN_fffb3196(0);
  bVar1 = DAT_00009ad3;
  iVar2 = FUN_fffb3196(0);
  if (iVar2 == 4 || iVar2 == 5) {
    sStack_2 = *(short *)(&DAT_fff880b6 + (uint)bVar1 * 2);
  }
  else {
    sStack_2 = *(short *)((int)&PTR_DAT_fff880bc + (uint)bVar1 * 2);
  }
  if (DAT_0001b75e == sStack_2) {
    return;
  }
  DAT_0001b784 = 0x1b;
  DAT_0001b786 = sStack_2;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa20af @ fffa20af (72 bytes)

void FUN_fffa20af(void)

{
  undefined2 local_2;
  
  if (DAT_00009ad2 == '\x02') {
    local_2 = 10;
  }
  else if (DAT_00009ad2 == '\0') {
    local_2 = 2;
  }
  else {
    local_2 = 5;
  }
  if (DAT_0001b760 == local_2) {
    return;
  }
  DAT_0001b784 = 0x1c;
  DAT_0001b786 = local_2;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa20f7 @ fffa20f7 (897 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa2407) */
/* WARNING: Removing unreachable block (ram,0xfffa2239) */
/* WARNING: Removing unreachable block (ram,0xfffa23f8) */
/* WARNING: Removing unreachable block (ram,0xfffa225d) */
/* WARNING: Removing unreachable block (ram,0xfffa217d) */
/* WARNING: Removing unreachable block (ram,0xfffa21ff) */
/* WARNING: Removing unreachable block (ram,0xfffa21e4) */
/* WARNING: Removing unreachable block (ram,0xfffa2123) */
/* WARNING: Removing unreachable block (ram,0xfffa21c8) */
/* WARNING: Removing unreachable block (ram,0xfffa2199) */
/* WARNING: Removing unreachable block (ram,0xfffa227b) */
/* WARNING: Removing unreachable block (ram,0xfffa234b) */
/* WARNING: Removing unreachable block (ram,0xfffa2369) */
/* WARNING: Removing unreachable block (ram,0xfffa239f) */

void FUN_fffa20f7(void)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  int iVar7;
  undefined1 uStack_17;
  undefined1 uStack_16;
  byte bStack_11;
  short sStack_a;
  ushort uStack_6;
  
  iVar7 = FUN_fffb324c(0);
  bVar3 = FUN_fffb3196(0);
  cVar2 = DAT_00009ad1;
  uStack_6 = 0;
  bStack_11 = 0;
  uVar1 = (uint)bVar3;
  if (uVar1 == 0xe) {
    bStack_11 = *(byte *)(iVar7 + 0x28) & 0x80;
    if (DAT_00009a79 == '\x01') {
      sStack_a = 0x5dc;
    }
    else if (DAT_00009a79 == '\x02') {
      sStack_a = 2000;
    }
    else {
      sStack_a = 1000;
    }
    uStack_6 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 + sStack_a +
               CONCAT11(*(undefined1 *)(iVar7 + 0x2c),*(undefined1 *)(iVar7 + 0x2d)) * -10;
  }
  else if (uVar1 - 2 < 2) {
    bStack_11 = *(byte *)(iVar7 + 0x14) & 0x80;
    sVar4 = CONCAT11(*(undefined1 *)(iVar7 + 0x18),*(undefined1 *)(iVar7 + 0x19));
    sVar5 = CONCAT11(*(undefined1 *)(iVar7 + 0x1c),*(undefined1 *)(iVar7 + 0x1d));
    FUN_fffc4e4f();
    uVar6 = (ushort)DAT_00009c04 * 10 + 300;
    if (CONCAT11(uStack_17,uStack_16) < uVar6) {
      uStack_6 = uVar6 + sVar5 + sVar4 * -10;
    }
    else {
      uStack_6 = (short)(((uint)CONCAT11(uStack_17,uStack_16) + (uint)uVar6) / 2) + sVar5 +
                 sVar4 * -10;
    }
  }
  else if (uVar1 - 8 < 2) {
    bStack_11 = *(byte *)(iVar7 + 0x28) & 0x80;
    uStack_6 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 +
               CONCAT11(*(undefined1 *)(iVar7 + 0x30),*(undefined1 *)(iVar7 + 0x31)) +
               CONCAT11(*(undefined1 *)(iVar7 + 0x2c),*(undefined1 *)(iVar7 + 0x2d)) * -10;
  }
  else if (uVar1 - 0xc < 2) {
    bStack_11 = *(byte *)(iVar7 + 0x1e) & 0x80;
    sVar4 = CONCAT11(*(undefined1 *)(iVar7 + 0x22),*(undefined1 *)(iVar7 + 0x23));
    sVar5 = CONCAT11(*(undefined1 *)(iVar7 + 0x26),*(undefined1 *)(iVar7 + 0x27));
    if (DAT_00009a8c == '\0') {
      if (DAT_00009a8d == '\x01') {
        uStack_6 = sVar5 + 0x564 + sVar4 * -10;
      }
      else if (DAT_00009a8d == '\x02') {
        uStack_6 = sVar5 + 0x5d2 + sVar4 * -10;
      }
      else if (DAT_00009a8d == '\x03') {
        uStack_6 = sVar5 + 0x6a4 + sVar4 * -10;
      }
      else {
        uStack_6 = sVar5 + 0x550 + sVar4 * -10;
      }
    }
    else if (DAT_00009a8d == '\x01') {
      uStack_6 = sVar5 + 0x8b6 + sVar4 * -10;
    }
    else if (DAT_00009a8d == '\x02') {
      uStack_6 = sVar5 + 0x924 + sVar4 * -10;
    }
    else if (DAT_00009a8d == '\x03') {
      uStack_6 = sVar5 + 0x9f6 + sVar4 * -10;
    }
    else {
      uStack_6 = sVar5 + 0x8a2 + sVar4 * -10;
    }
  }
  else if (uVar1 < 2) {
    bStack_11 = *(byte *)(iVar7 + 10) & 0x80;
    uStack_6 = CONCAT11(*(undefined1 *)(iVar7 + 0x12),*(undefined1 *)(iVar7 + 0x13)) + 0x5dc +
               CONCAT11(*(undefined1 *)(iVar7 + 0xe),*(undefined1 *)(iVar7 + 0xf)) * -10;
  }
  if ((uStack_6 & 0x8000) == 0) {
    uStack_6 = uStack_6 / 5;
  }
  else {
    uStack_6 = ~((ushort)(~uStack_6 + 1) / 5) + 1;
  }
  if ((((bVar3 == 1) || (bVar3 == 3)) || (bVar3 == 9)) || (bVar3 == 0xd || bVar3 == 0xe)) {
    uStack_6 = ~uStack_6 + 1;
  }
  if ((uStack_6 & 0x8000) != 0) {
    uStack_6 = uStack_6 & 0xfff;
  }
  if (bStack_11 == 0) {
    uStack_6 = 0;
  }
  else if (cVar2 == '\0') {
    uStack_6 = uStack_6 | 0x2000;
  }
  else {
    uStack_6 = uStack_6 | 0x1000;
  }
  if (DAT_0001b762 == uStack_6) {
    return;
  }
  DAT_0001b784 = 0x1d;
  DAT_0001b786 = uStack_6;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa2478 @ fffa2478 (599 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa2685) */
/* WARNING: Removing unreachable block (ram,0xfffa2575) */
/* WARNING: Removing unreachable block (ram,0xfffa2676) */
/* WARNING: Removing unreachable block (ram,0xfffa2500) */
/* WARNING: Removing unreachable block (ram,0xfffa253f) */
/* WARNING: Removing unreachable block (ram,0xfffa2499) */
/* WARNING: Removing unreachable block (ram,0xfffa2524) */
/* WARNING: Removing unreachable block (ram,0xfffa24de) */
/* WARNING: Removing unreachable block (ram,0xfffa258b) */
/* WARNING: Removing unreachable block (ram,0xfffa262c) */

void FUN_fffa2478(void)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  undefined1 uStack_11;
  undefined1 uStack_10;
  ushort uStack_6;
  
  iVar4 = FUN_fffb324c(0);
  bVar2 = FUN_fffb3196(0);
  uStack_6 = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
    sVar3 = CONCAT11(*(undefined1 *)(iVar4 + 0x30),*(undefined1 *)(iVar4 + 0x31));
    if (DAT_00009a79 == '\x01') {
      uStack_6 = sVar3 + 0x5dc;
    }
    else if (DAT_00009a79 == '\x02') {
      uStack_6 = sVar3 + 2000;
    }
    else {
      uStack_6 = sVar3 + 1000;
    }
  }
  else if (uVar1 - 2 < 2) {
    sVar3 = CONCAT11(*(undefined1 *)(iVar4 + 0x1c),*(undefined1 *)(iVar4 + 0x1d));
    FUN_fffc4e4f();
    uStack_6 = (ushort)DAT_00009c04 * 10 + 300;
    if (CONCAT11(uStack_11,uStack_10) < uStack_6) {
      uStack_6 = sVar3 + uStack_6;
    }
    else {
      uStack_6 = (short)(((uint)CONCAT11(uStack_11,uStack_10) + (uint)uStack_6) / 2) + sVar3;
    }
  }
  else if (uVar1 - 8 < 2) {
    uStack_6 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10 +
               CONCAT11(*(undefined1 *)(iVar4 + 0x30),*(undefined1 *)(iVar4 + 0x31));
  }
  else if (uVar1 - 0xc < 2) {
    sVar3 = CONCAT11(*(undefined1 *)(iVar4 + 0x26),*(undefined1 *)(iVar4 + 0x27));
    if (DAT_00009a8c == '\0') {
      if (DAT_00009a8d == '\x01') {
        uStack_6 = sVar3 + 0x564;
      }
      else if (DAT_00009a8d == '\x02') {
        uStack_6 = sVar3 + 0x5d2;
      }
      else if (DAT_00009a8d == '\x03') {
        uStack_6 = sVar3 + 0x6a4;
      }
      else {
        uStack_6 = sVar3 + 0x550;
      }
    }
    else if (DAT_00009a8d == '\x01') {
      uStack_6 = sVar3 + 0x8b6;
    }
    else if (DAT_00009a8d == '\x02') {
      uStack_6 = sVar3 + 0x924;
    }
    else if (DAT_00009a8d == '\x03') {
      uStack_6 = sVar3 + 0x9f6;
    }
    else {
      uStack_6 = sVar3 + 0x8a2;
    }
  }
  else if (uVar1 < 2) {
    uStack_6 = CONCAT11(*(undefined1 *)(iVar4 + 0x12),*(undefined1 *)(iVar4 + 0x13)) + 0x5dc;
  }
  if ((uStack_6 & 0x8000) == 0) {
    uStack_6 = uStack_6 / 5;
  }
  else {
    uStack_6 = ~((ushort)(~uStack_6 + 1) / 5) + 1;
  }
  if ((((bVar2 == 1) || (bVar2 == 3)) || (bVar2 == 9)) || (bVar2 == 0xd || bVar2 == 0xe)) {
    uStack_6 = ~uStack_6 + 1;
  }
  if (DAT_0001b764 == uStack_6) {
    return;
  }
  DAT_0001b784 = 0x1e;
  DAT_0001b786 = uStack_6;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa26cf @ fffa26cf (137 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa270f) */

void FUN_fffa26cf(void)

{
  uint uVar1;
  undefined1 uStack_4;
  undefined1 uStack_3;
  short local_2;
  
  local_2 = 0;
  uVar1 = FUN_fffb3196(0);
  if (uVar1 < 4) goto LAB_fffa2703;
  if (uVar1 != 4) {
    if (uVar1 == 5) {
      local_2 = 6000;
      goto LAB_fffa272e;
    }
    if (uVar1 == 6) {
LAB_fffa2729:
      local_2 = 16000;
      goto LAB_fffa272e;
    }
    if (uVar1 != 7) {
      if (1 < uVar1 - 8) {
        if (uVar1 == 10) goto LAB_fffa2729;
        if (uVar1 == 0xb) goto LAB_fffa271c;
        if (2 < uVar1 - 0xc) goto LAB_fffa272e;
      }
LAB_fffa2703:
      FUN_fffc4e4f(&uStack_4);
      local_2 = CONCAT11(uStack_4,uStack_3);
      goto LAB_fffa272e;
    }
  }
LAB_fffa271c:
  local_2 = 9000;
LAB_fffa272e:
  if (DAT_0001b766 != local_2) {
    DAT_0001b784 = 0x1f;
    DAT_0001b786 = local_2;
    FUN_fffa30f9(0x77);
    return;
  }
  return;
}


// ===== FUN_fffa2758 @ fffa2758 (402 bytes)

void FUN_fffa2758(char param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 uStack_10;
  undefined *puStack_c;
  
  iVar3 = FUN_fffb357c(param_1,2);
  cVar1 = DAT_00009c35;
  puVar4 = (undefined1 *)FUN_fffa1541(iVar3);
  if (param_1 == '\0') {
    uVar2 = FUN_fffb4c45();
    if (cVar1 == '\0') {
      if ((uVar2 & 0x8000) == 0) {
        uStack_10 = (undefined *)(iVar3 + (uint)uVar2);
      }
      else {
        uStack_10 = (undefined *)(iVar3 - (uint)(ushort)(~uVar2 + 1));
      }
    }
    else {
      if (cVar1 == '\x02') {
        puStack_c = (undefined *)FUN_fffb4ebe(2);
      }
      else {
        puStack_c = (undefined *)DAT_00020f60;
      }
      switch(*puVar4) {
      case 0:
        puStack_c = (undefined *)((int)puStack_c + 500);
        break;
      case 1:
        puStack_c = (undefined *)((int)puStack_c + 1000);
        break;
      case 2:
        puStack_c = (undefined *)((int)puStack_c + 0x9c4);
        break;
      case 3:
        puStack_c = &DAT_00001388 + (int)puStack_c;
        break;
      case 4:
        puStack_c = &DAT_00002710 + (int)puStack_c;
        break;
      case 5:
        puStack_c = &DAT_000061a8 + (int)puStack_c;
        break;
      case 6:
        puStack_c = &DAT_0000c350 + (int)puStack_c;
        break;
      case 7:
        puStack_c = &DAT_000186a0 + (int)puStack_c;
        break;
      case 8:
        puStack_c = &DAT_0003d090 + (int)puStack_c;
        break;
      default:
        puStack_c = (undefined *)((int)puStack_c + 500000);
      }
      if ((uVar2 & 0x8000) == 0) {
        uStack_10 = puStack_c + uVar2;
      }
      else {
        uStack_10 = puStack_c + -(uint)(ushort)(~uVar2 + 1);
      }
    }
  }
  else {
    uVar5 = FUN_fffb4f52(iVar3);
    if (uVar5 < 0x3b9aca1) {
      uStack_10 = (undefined *)(62500000 - (uVar5 & 0xff));
    }
    else {
      uStack_10 = (undefined *)(uVar5 + 0xfc465360);
    }
  }
  if (uStack_10._2_2_ != DAT_0001b768) {
    DAT_0001b784 = 0x20;
    DAT_0001b786 = uStack_10._2_2_;
    FUN_fffa30f9(0x77);
    DAT_0001b76a = 0xffff;
    return;
  }
  if (((uint)uStack_10 & 0xffff) != (uint)DAT_0001b76a) {
    DAT_0001b784 = 0x21;
    DAT_0001b786 = (undefined2)uStack_10;
    FUN_fffa30f9(0x77);
    return;
  }
  return;
}


// ===== FUN_fffa28ea @ fffa28ea (168 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa2913) */

void FUN_fffa28ea(undefined1 param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined1 *puStack_10;
  short sStack_a;
  
  cVar1 = DAT_00009c35;
  uVar3 = FUN_fffb357c(param_1,2);
  bVar2 = FUN_fffb3480(uVar3);
  sStack_a = 1000;
  if (cVar1 == '\x02') {
    puStack_10 = (&PTR_DAT_fff885b0)[(uint)bVar2 * 2];
  }
  else {
    puStack_10 = (&PTR_DAT_fff885ac)[(uint)bVar2 * 2];
  }
  switch(*puStack_10) {
  case 0:
    sStack_a = 1;
    break;
  case 1:
    sStack_a = 2;
    break;
  case 2:
    sStack_a = 5;
    break;
  case 3:
    sStack_a = 10;
    break;
  case 4:
    sStack_a = 0x14;
    break;
  case 5:
    sStack_a = 0x32;
    break;
  case 6:
    sStack_a = 100;
    break;
  case 7:
    sStack_a = 200;
    break;
  case 8:
    sStack_a = 500;
  }
  if (DAT_0001b76c == sStack_a) {
    return;
  }
  DAT_0001b784 = 0x22;
  DAT_0001b786 = sStack_a;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa2992 @ fffa2992 (83 bytes)

void FUN_fffa2992(void)

{
  undefined2 local_2;
  
  if (DAT_00009b14 == '\x01') {
    local_2 = 0x7000;
  }
  else if (DAT_00009b14 == '\x02') {
    local_2 = 0x5000;
  }
  else {
    local_2 = -0x8000;
  }
  if (DAT_0001b76e == local_2) {
    return;
  }
  DAT_0001b784 = 0x23;
  DAT_0001b786 = local_2;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa29e5 @ fffa29e5 (49 bytes)

void FUN_fffa29e5(void)

{
  if (DAT_0001b770 == 0x317) {
    return;
  }
  DAT_0001b784 = 0x24;
  DAT_0001b786 = 0x317;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa2a16 @ fffa2a16 (377 bytes)

void FUN_fffa2a16(void)

{
  undefined *puVar1;
  byte bVar2;
  short sVar3;
  float fVar4;
  uint uVar5;
  float fStack_28;
  float fStack_24;
  float fStack_1c;
  float fStack_18;
  
  uVar5 = (uint)SCARRY4((int)&stack0x00000000,-0x28) << 3;
  bVar2 = FUN_fffb4062();
  fVar4 = (float)bVar2;
  bVar2 = FUN_fffb3371(DAT_00020f50);
  puVar1 = (&PTR_DAT_fff8861c)[bVar2];
  if (fVar4 - 100.0 == 0.0) {
    if (bVar2 < 10) {
      fStack_1c = (float)(byte)puVar1[2];
      fStack_24 = 100.0;
      fStack_28 = 101.0;
      fStack_18 = fStack_1c;
    }
    else {
      fStack_1c = (float)(byte)puVar1[5];
      fStack_24 = 50.0;
      fStack_28 = 51.0;
      fStack_18 = fStack_1c;
    }
  }
  else if (fVar4 - 50.0 < 0.0 == (bool)((byte)(uVar5 >> 3) & 1)) {
    fStack_18 = (float)(byte)puVar1[5];
    if (bVar2 < 10) {
      fStack_1c = (float)(byte)puVar1[2];
      fStack_24 = 50.0;
      fStack_28 = 100.0;
    }
    else {
      fStack_24 = 50.0;
      fStack_28 = 51.0;
      fStack_1c = fStack_18;
    }
  }
  else if (fVar4 - 20.0 < 0.0 == (bool)((byte)(uVar5 >> 3) & 1)) {
    fStack_18 = (float)(byte)puVar1[8];
    fStack_24 = 20.0;
    fStack_28 = 50.0;
    fStack_1c = (float)(byte)puVar1[5];
  }
  else if (fVar4 - 10.0 < 0.0 == (bool)((byte)(uVar5 >> 3) & 1)) {
    fStack_18 = (float)(byte)puVar1[0xb];
    fStack_24 = 10.0;
    fStack_28 = 20.0;
    fStack_1c = (float)(byte)puVar1[8];
  }
  else {
    fStack_18 = (float)(byte)puVar1[0xe];
    fStack_24 = 5.0;
    fStack_28 = 10.0;
    fStack_1c = (float)(byte)puVar1[0xb];
  }
  sVar3 = SUB42(ROUND(((fVar4 - fStack_24) * (fStack_1c - fStack_18)) / (fStack_28 - fStack_24) +
                      fStack_18),0) << 4;
  if (DAT_0001b772 == sVar3) {
    return;
  }
  DAT_0001b784 = 0x25;
  DAT_0001b786 = sVar3;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa2b8f @ fffa2b8f (116 bytes)

void FUN_fffa2b8f(char param_1)

{
  undefined2 local_4;
  
  if (param_1 == '\0') {
    local_4 = 0x610;
  }
  else if (DAT_00009c36 == '\0') {
    if (DAT_00009b16 == '\0') {
      local_4 = 0x610;
    }
    else {
      local_4 = 0x140;
    }
  }
  else if (DAT_00009b17 == '\0') {
    local_4 = 0x200;
  }
  else {
    local_4 = -0x100;
  }
  if (DAT_0001b774 == local_4) {
    return;
  }
  DAT_0001b784 = 0x26;
  DAT_0001b786 = local_4;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa2c03 @ fffa2c03 (156 bytes)

void FUN_fffa2c03(char param_1)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  cVar2 = DAT_00009b14;
  cVar1 = DAT_00004689;
  uVar4 = FUN_fffb357c(param_1,2);
  pcVar5 = (char *)FUN_fffa150c(uVar4,param_1);
  if (cVar2 == '\x01') {
    uStack_14 = '\x02';
  }
  else if (cVar2 == '\x02') {
    uStack_14 = '\x04';
  }
  else {
    uStack_14 = '\0';
  }
  if (param_1 == '\0') {
    uStack_13 = *pcVar5 + cVar1 + 0x44;
  }
  else {
    uStack_13 = *pcVar5 - 0x37;
  }
  uVar3 = (byte)(~uStack_13 + 1 + uStack_14) | 0x8000;
  if (DAT_0001b776 == uVar3) {
    return;
  }
  DAT_0001b784 = 0x27;
  DAT_0001b786 = uVar3;
  FUN_fffa30f9(0x77);
  return;
}


// ===== FUN_fffa2c9f @ fffa2c9f (856 bytes)

void FUN_fffa2c9f(void)

{
  if (DAT_0001b784 == -1) {
    DAT_0001b782 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 1) {
    DAT_0001b738 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 3) {
    DAT_0001b73a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 4) {
    DAT_0001b73c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 8) {
    DAT_0001b73e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 9) {
    DAT_0001b740 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 10) {
    DAT_0001b742 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xb) {
    DAT_0001b744 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xc) {
    DAT_0001b746 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xd) {
    DAT_0001b748 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xe) {
    DAT_0001b74a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xf) {
    DAT_0001b74c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x12) {
    DAT_0001b74e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x13) {
    DAT_0001b750 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x14) {
    DAT_0001b752 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x15) {
    DAT_0001b754 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x16) {
    DAT_0001b756 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x18) {
    DAT_0001b758 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x19) {
    DAT_0001b75a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1a) {
    DAT_0001b75c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1b) {
    DAT_0001b75e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1c) {
    DAT_0001b760 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1d) {
    DAT_0001b762 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1e) {
    DAT_0001b764 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1f) {
    DAT_0001b766 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x20) {
    DAT_0001b768 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x21) {
    DAT_0001b76a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x22) {
    DAT_0001b76c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x23) {
    DAT_0001b76e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x24) {
    DAT_0001b770 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x25) {
    DAT_0001b772 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x26) {
    DAT_0001b774 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x27) {
    DAT_0001b776 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x30) {
    DAT_0001b778 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x31) {
    DAT_0001b77a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x32) {
    DAT_0001b77c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x33) {
    DAT_0001b77e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x37) {
    DAT_0001b780 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 != 0) {
    return;
  }
  DAT_0001b736 = DAT_0001b786;
  return;
}

