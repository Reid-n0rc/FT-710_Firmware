// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffcfc16 @ fffcfc16 (58 bytes)

void FUN_fffcfc16(undefined1 param_1)

{
  DAT_00015dfa = 1;
  if (DAT_00015de3 == '\x01') {
    FUN_fffcfc50(param_1);
  }
  else if (DAT_00015de3 == '\x02') {
    FUN_fffcfe83(param_1);
  }
  DAT_00015dfa = 0;
  return;
}


// ===== FUN_fffcfc50 @ fffcfc50 (174 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcfcc7) */
/* WARNING: Removing unreachable block (ram,0xfffcfc76) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffcfc50(char param_1)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = _DAT_00015de8;
  cVar1 = DAT_00015de8;
  if (DAT_00015de8 != -1) {
    _DAT_00015de8 = 1;
  }
  if (param_1 == '\0') {
    if (3 < (uVar2 & 0xff)) {
      if ((uint)DAT_00015de7 + (uVar2 & 0xff) + 1 < (uint)DAT_00015de6) {
        FUN_fffcfcfe(*(undefined1 *)(DAT_00015de7 + 1),uVar2 & 0xff);
        return;
      }
      FUN_fffcfd1b();
      return;
    }
    bVar3 = cVar1 + 1;
    if (bVar3 < DAT_00015de6) {
      FUN_fffcfcfe(DAT_00015de7,bVar3);
      return;
    }
    FUN_fffcfd1b();
    return;
  }
  if (cVar1 != '\0') {
    FUN_fffcfcfe(DAT_00015de7,*(undefined1 *)((uVar2 & 0xff) - 1));
    return;
  }
  if (DAT_00015de7 == 0) {
    return;
  }
  FUN_fffcfcfe(*(undefined1 *)(DAT_00015de7 - 1),uVar2 & 0xff);
  return;
}


// ===== FUN_fffcfcfe @ fffcfcfe (29 bytes)

void FUN_fffcfcfe(undefined1 param_1,undefined1 param_2)

{
  DAT_00015de7 = param_1;
  DAT_00015de8 = param_2;
  FUN_fffd0902();
  return;
}


// ===== FUN_fffcfd1b @ fffcfd1b (42 bytes)

void FUN_fffcfd1b(undefined1 param_1)

{
  if (DAT_00015dfa != '\0') {
    return;
  }
  DAT_00015de9 = DAT_00015de8;
  FUN_fffcfcfe(param_1,0xff);
  return;
}


// ===== FUN_fffcfd45 @ fffcfd45 (133 bytes)

undefined1 FUN_fffcfd45(ushort param_1)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  
  if ((param_1 < 0x140) || (0x149 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return 0;
  }
  bVar2 = (char)param_1 - 0x40;
  if (5 < bVar2) {
    if (bVar2 == 6) {
      uVar3 = FUN_fffcfe4f();
      return uVar3;
    }
    if (bVar2 == 7) {
      uVar3 = FUN_fffcfe63();
      return uVar3;
    }
    if (bVar2 == 8) {
      DAT_00015de8 = 0xfe;
      bVar2 = DAT_00015de8;
    }
    else {
      if (bVar2 != 9) {
        return 0;
      }
      DAT_00015de8 = 0xff;
      bVar2 = DAT_00015de8;
    }
  }
  DAT_00015de8 = bVar2;
  uVar3 = FUN_fffcfdca();
  return uVar3;
}


// ===== FUN_fffcfdca @ fffcfdca (99 bytes)

undefined1 FUN_fffcfdca(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d60[0x3f7] == '\x02') {
    if (DAT_00015de8 == -1) {
      local_2 = FUN_fffcfe77();
    }
    else if (DAT_00015de8 == -2) {
      local_2 = FUN_fffcfe2d();
    }
    else if (DAT_00015de6 < (byte)(DAT_00015de8 + 1U)) {
      local_2 = 0;
    }
    else {
      local_2 = FUN_fffcfe2d();
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffcfe2d @ fffcfe2d (34 bytes)

undefined1 FUN_fffcfe2d(void)

{
  FUN_fffd0bb0();
  PTR_DAT_00025d60[0x3f7] = 99;
  DAT_00015dfb = 0;
  return 1;
}


// ===== FUN_fffcfe4f @ fffcfe4f (20 bytes)

undefined1 FUN_fffcfe4f(void)

{
  FUN_fffcfc16(1);
  FUN_fffb2da6(1);
  return 2;
}


// ===== FUN_fffcfe63 @ fffcfe63 (20 bytes)

undefined1 FUN_fffcfe63(void)

{
  FUN_fffcfc16(0);
  FUN_fffb2da6(1);
  return 2;
}


// ===== FUN_fffcfe77 @ fffcfe77 (12 bytes)

undefined1 FUN_fffcfe77(void)

{
  FUN_fffd0149();
  return 1;
}


// ===== FUN_fffcfe83 @ fffcfe83 (209 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcff0c) */
/* WARNING: Removing unreachable block (ram,0xfffcfea9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffcfe83(char param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = _DAT_00015de8;
  cVar1 = DAT_00015de8;
  if (DAT_00015de8 != -1) {
    _DAT_00015de8 = 1;
  }
  if (param_1 == '\0') {
    if (cVar1 == -2) {
      FUN_fffcff54(DAT_00015de7,0xff);
      return;
    }
    if (3 < (uVar2 & 0xff)) {
      if ((uint)DAT_00015de7 + (uVar2 & 0xff) + 1 < (uint)DAT_00015de6) {
        FUN_fffcff54(*(undefined1 *)(DAT_00015de7 + 1),uVar2 & 0xff);
        return;
      }
      FUN_fffcff71();
      return;
    }
    if ((byte)(cVar1 + 1U) < DAT_00015de6) {
      FUN_fffcff54(DAT_00015de7,cVar1 + 1U);
      return;
    }
    FUN_fffcff71();
    return;
  }
  if (cVar1 == -2) {
    FUN_fffcff54(DAT_00015de7,DAT_00015de9);
    return;
  }
  if (cVar1 == '\0') {
    if (DAT_00015de7 == 0) {
      return;
    }
    FUN_fffcff54(*(undefined1 *)(DAT_00015de7 - 1),uVar2 & 0xff);
    return;
  }
  FUN_fffcff54(DAT_00015de7,*(undefined1 *)((uVar2 & 0xff) - 1));
  return;
}


// ===== FUN_fffcff54 @ fffcff54 (29 bytes)

void FUN_fffcff54(undefined1 param_1,undefined1 param_2)

{
  DAT_00015de7 = param_1;
  DAT_00015de8 = param_2;
  FUN_fffd0bb0();
  return;
}


// ===== FUN_fffcff71 @ fffcff71 (42 bytes)

void FUN_fffcff71(undefined1 param_1)

{
  if (DAT_00015dfa != '\0') {
    return;
  }
  DAT_00015de9 = DAT_00015de8;
  FUN_fffcff54(param_1,0xfe);
  return;
}


// ===== FUN_fffcff9b @ fffcff9b (25 bytes)

undefined1 FUN_fffcff9b(int param_1)

{
  undefined1 local_4;
  
  if (param_1 == 0x170) {
    local_4 = FUN_fffcffb4();
  }
  else {
    local_4 = 0;
  }
  return local_4;
}


// ===== FUN_fffcffb4 @ fffcffb4 (34 bytes)

undefined1 FUN_fffcffb4(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d60[0x3f7] == '\x02') {
    local_2 = FUN_fffcfe77();
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffcffd6 @ fffcffd6 (55 bytes)

undefined1 FUN_fffcffd6(uint param_1)

{
  undefined1 uVar1;
  
  if (param_1 == 0x181) {
    DAT_00015de8 = 0xff;
  }
  else {
    if ((param_1 & 0xffff) != 0x180) {
      return 0;
    }
    DAT_00015de8 = 0xfe;
  }
  uVar1 = FUN_fffd000d();
  return uVar1;
}


// ===== FUN_fffd000d @ fffd000d (57 bytes)

undefined1 FUN_fffd000d(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d60[0x3f7] == '\x02') {
    if (DAT_00015de8 == -1) {
      local_2 = FUN_fffcfe77();
    }
    else {
      FUN_fffd1683();
      FUN_fffd16f7();
      local_2 = 1;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffd0046 @ fffd0046 (102 bytes)

void FUN_fffd0046(short param_1)

{
  undefined1 local_4;
  
  param_1 = param_1 + -0xfe;
  if (PTR_DAT_00025d60[0x88] == '\x01') {
    local_4 = (undefined1)param_1;
    FUN_fffd00fa(local_4);
    return;
  }
  if (PTR_DAT_00025d60[0x93] != '\x01') {
    if (param_1 != 1) {
      FUN_fffd0234();
      return;
    }
    FUN_fffd038d();
    return;
  }
  if (param_1 != 0) {
    PTR_DAT_00025d60[0x3f8] = 1;
    PTR_DAT_00025d60[0x3f9] = 1;
    FUN_fffd038d();
    return;
  }
  FUN_fffd0234();
  return;
}


// ===== FUN_fffd00ac @ fffd00ac (78 bytes)

void FUN_fffd00ac(void)

{
  if (PTR_DAT_00025d60[0x88] == '\x01') {
    FUN_fffd00fa();
    return;
  }
  if (PTR_DAT_00025d60[0xbd] != '\x01') {
    FUN_fffd0234();
    return;
  }
  if (PTR_DAT_00025d60[0x93] != '\x01') {
    FUN_fffd038d();
    return;
  }
  PTR_DAT_00025d60[0x3f8] = 1;
  PTR_DAT_00025d60[0x3f9] = 1;
  FUN_fffd038d();
  return;
}


// ===== FUN_fffd00fa @ fffd00fa (79 bytes)

void FUN_fffd00fa(undefined1 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)PTR_DAT_00025d60[0xbb];
  if (uVar1 == 0xf) {
    FUN_fffd01f3();
    return;
  }
  if (uVar1 == 7) {
    FUN_fffd016f(param_1);
    return;
  }
  if (uVar1 != 8) {
    if (uVar1 == 9) {
      FUN_fffd0194(param_1);
      return;
    }
    if (uVar1 == 10) {
      FUN_fffd01cd();
      return;
    }
    if ((3 < uVar1 - 0xb) && (3 < uVar1 - 3)) {
      return;
    }
  }
  FUN_fffd0149();
  return;
}


// ===== FUN_fffd0149 @ fffd0149 (38 bytes)

void FUN_fffd0149(void)

{
  PTR_DAT_00025d60[0x88] = 0;
  PTR_DAT_00025d60[0x86] = 0;
  PTR_DAT_00025d60[0x3ff] = 2;
  return;
}


// ===== FUN_fffd016f @ fffd016f (37 bytes)

void FUN_fffd016f(char param_1)

{
  PTR_DAT_00025d60[0x86] = 0;
  if (param_1 != '\x01') {
    FUN_fffd03ac();
    FUN_fffd041e();
    FUN_fffd04a6();
    return;
  }
  FUN_fffd0149();
  return;
}


// ===== FUN_fffd0194 @ fffd0194 (57 bytes)

void FUN_fffd0194(char param_1)

{
  PTR_DAT_00025d60[0x86] = 0;
  if (param_1 != '\x01') {
    FUN_fffd04dd();
    PTR_DAT_00025d60[0x3f7] = 5;
    PTR_DAT_00025d60[0x406] = 1;
    return;
  }
  FUN_fffd0149();
  return;
}


// ===== FUN_fffd01cd @ fffd01cd (38 bytes)

void FUN_fffd01cd(void)

{
  PTR_DAT_00025d60[0x86] = 0;
  PTR_DAT_00025d60[0x447] = 1;
  PTR_DAT_00025d60[0x35] = 0x11;
  return;
}


// ===== FUN_fffd01f3 @ fffd01f3 (65 bytes)

void FUN_fffd01f3(void)

{
  if (PTR_DAT_00025d60[0x3f7] != '\a') {
    PTR_DAT_00025d60[0x86] = 0;
    PTR_DAT_00025d60[0x447] = 1;
    PTR_DAT_00025d60[0x35] = 0x11;
    return;
  }
  FUN_fffbc638();
  FUN_fffc4c8b(4);
  return;
}


// ===== FUN_fffd0234 @ fffd0234 (69 bytes)

void FUN_fffd0234(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)PTR_DAT_00025d60[0xbb];
  if (uVar1 == 1) {
    FUN_fffd0300();
    return;
  }
  if (0xb < uVar1 - 2) {
    if (uVar1 - 0xe < 2) {
LAB_fffd0268:
      FUN_fffd0279();
      return;
    }
    if (6 < uVar1 - 0x10) {
      if (uVar1 == 0x17) {
        FUN_fffd0366();
        return;
      }
      if (1 < uVar1 - 0x18) {
        if (uVar1 != 0) {
          return;
        }
        goto LAB_fffd0268;
      }
    }
  }
  FUN_fffd038d();
  return;
}


// ===== FUN_fffd0279 @ fffd0279 (15 bytes)

void FUN_fffd0279(void)

{
  FUN_fffd0288(PTR_DAT_00025d60[0xbc]);
  return;
}


// ===== FUN_fffd0288 @ fffd0288 (103 bytes)

void FUN_fffd0288(char param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (param_1 == '\x02') {
    FUN_fffd02f9();
  }
  else if (param_1 == '\x01') {
    FUN_fffd02f4();
  }
  else if (param_1 == '\0') {
    FUN_fffd02ef();
    if (DAT_00009dbd == '\0') {
      puVar2 = &DAT_00006150;
      puVar1 = &DAT_00009d09;
      for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar1 = *puVar2;
        puVar1 = puVar1 + 1;
        puVar2 = puVar2 + 1;
      }
    }
    else {
      puVar2 = &DAT_00006150;
      puVar1 = &DAT_00009d63;
      for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar1 = *puVar2;
        puVar1 = puVar1 + 1;
        puVar2 = puVar2 + 1;
      }
    }
  }
  FUN_fffb2da6(8);
  PTR_DAT_00025d60[0x35] = 0x11;
  return;
}


// ===== FUN_fffd02ef @ fffd02ef (5 bytes)

void FUN_fffd02ef(void)

{
  FUN_fffb0636();
  return;
}


// ===== FUN_fffd02f4 @ fffd02f4 (5 bytes)

void FUN_fffd02f4(void)

{
  FUN_fffb063a();
  return;
}


// ===== FUN_fffd02f9 @ fffd02f9 (7 bytes)

void FUN_fffd02f9(void)

{
  settings_defaults(0);
  return;
}


// ===== FUN_fffd0300 @ fffd0300 (102 bytes)

void FUN_fffd0300(void)

{
  PTR_DAT_00025d60[0x86] = 0;
  FUN_fffd03a7();
  PTR_DAT_00025d60[0x95] = 1;
  PTR_DAT_00025d60[0x41f] = 4;
  (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]] = 1;
  PTR_DAT_00025d60[0x3ff] = 2;
  PTR_DAT_00025d60[0x94] = 0;
  PTR_DAT_00025d60[0x40d] = 0;
  return;
}


// ===== FUN_fffd0366 @ fffd0366 (39 bytes)

void FUN_fffd0366(void)

{
  PTR_DAT_00025d60[0x86] = 0;
  PTR_DAT_00025d60[0x3f8] = 1;
  PTR_DAT_00025d60[0x3f9] = 3;
  return;
}


// ===== FUN_fffd038d @ fffd038d (26 bytes)

void FUN_fffd038d(void)

{
  PTR_DAT_00025d60[0x86] = 0;
  PTR_DAT_00025d60[0x3ff] = 2;
  return;
}


// ===== FUN_fffd03a7 @ fffd03a7 (5 bytes)

void FUN_fffd03a7(void)

{
  FUN_fffc8beb();
  return;
}


// ===== FUN_fffd03ac @ fffd03ac (114 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffd03ac(void)

{
  if (DAT_00015de5 == '\0') {
    DAT_00015de4 = 0xc;
    if (DAT_00000c25 != '\0') {
      DAT_00015de4 = 0xd;
    }
  }
  else {
    DAT_00015de4 = 0x2f;
    if (DAT_00002f4b != '\0') {
      DAT_00015de4 = 0x30;
    }
  }
  _DAT_0001ff04 = 0x100;
  _DAT_0001ff02 = 0;
  return;
}


// ===== FUN_fffd041e @ fffd041e (136 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd04a3) */

ushort FUN_fffd041e(void)

{
  undefined *puVar1;
  undefined1 uVar2;
  ushort uStack_6;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar1 = PTR_DAT_00025d60;
  uVar2 = FUN_fffd04c1();
  puVar1[0x1e4] = uVar2;
  PTR_DAT_00025d60[0x1e5] = 4;
  if (DAT_00015de5 == '\0') {
    uStack_6 = 0xc25;
  }
  else {
    uStack_6 = 0x2f4b;
  }
  PTR_DAT_00025d60[0x1e6] = (char)(uStack_6 >> 8);
  PTR_DAT_00025d60[0x1e7] = (undefined1)uStack_6;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return uStack_6 >> 8;
}


// ===== FUN_fffd04a6 @ fffd04a6 (27 bytes)

void FUN_fffd04a6(void)

{
  PTR_DAT_00025d60[0x3f7] = 8;
  PTR_DAT_00025d60[0x406] = 1;
  return;
}


// ===== FUN_fffd04c1 @ fffd04c1 (28 bytes)

undefined1 FUN_fffd04c1(void)

{
  undefined1 local_2;
  
  if (DAT_00015de5 == '\0') {
    local_2 = 0x44;
  }
  else {
    local_2 = 0x42;
  }
  return local_2;
}


// ===== FUN_fffd04dd @ fffd04dd (137 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0563) */

undefined4 FUN_fffd04dd(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar1 = PTR_DAT_00025d60;
  uVar2 = FUN_fffd0566();
  puVar1[0x1e4] = (char)uVar2;
  PTR_DAT_00025d60[0x1e5] = 0x10;
  PTR_DAT_00025d60[0x1e6] = DAT_00015de7 + DAT_00015de8;
  PTR_DAT_00025d60[0x1e7] = 0x50;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return uVar2;
}


// ===== FUN_fffd0566 @ fffd0566 (28 bytes)

undefined1 FUN_fffd0566(void)

{
  undefined1 local_2;
  
  if (DAT_00015de5 == '\0') {
    local_2 = 0x43;
  }
  else {
    local_2 = 0x41;
  }
  return local_2;
}


// ===== FUN_fffd0582 @ fffd0582 (77 bytes)

void FUN_fffd0582(void)

{
  if (PTR_DAT_00025d60[0x88] != '\0') {
    if (PTR_DAT_00025d60[0xa6] == '\0') {
      FUN_fffcf4f2();
      FUN_fffd05cf();
      return;
    }
    if (DAT_00015de3 == '\x04') {
      FUN_fffd14b9();
      return;
    }
    if (DAT_00015de3 == '\x02') {
      FUN_fffd0a68();
      return;
    }
    if (DAT_00015de3 == '\x03') {
      FUN_fffd1394();
      return;
    }
    if (DAT_00015de3 == '\x01') {
      FUN_fffd05ea();
      return;
    }
  }
  return;
}


// ===== FUN_fffd05cf @ fffd05cf (27 bytes)

void FUN_fffd05cf(void)

{
  PTR_DAT_00025d60[0x3f7] = 0;
  PTR_DAT_00025d60[0x406] = 0;
  return;
}


// ===== FUN_fffd05ea @ fffd05ea (45 bytes)

void FUN_fffd05ea(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d60[0x3f7];
  if (cVar1 == '\x06') {
    FUN_fffd077e();
    return;
  }
  if (cVar1 == '\x03') {
    FUN_fffd06e2();
    return;
  }
  if (cVar1 == '\x05') {
    FUN_fffd0703();
    return;
  }
  if (cVar1 != '\x01') {
    return;
  }
  FUN_fffd0617();
  return;
}


// ===== FUN_fffd0617 @ fffd0617 (189 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd06bf) */
/* WARNING: Removing unreachable block (ram,0xfffd06d1) */
/* WARNING: Removing unreachable block (ram,0xfffd06ce) */
/* WARNING: Removing unreachable block (ram,0xfffd06c5) */
/* WARNING: Removing unreachable block (ram,0xfffd06b0) */

undefined4 FUN_fffd0617(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  cVar1 = PTR_DAT_00025d60[0x2ed];
  cVar2 = FUN_fffd0566();
  if (cVar1 == cVar2) {
    if (PTR_DAT_00025d60[0x2ee] != '\0') {
      uVar3 = FUN_fffd0979();
      return uVar3;
    }
    if (PTR_DAT_00025d60[0x2ef] == '\0') {
      DAT_00015de6 = PTR_DAT_00025d60[0x2f0];
      if (DAT_00015de6 == '\0') {
        DAT_00015de8 = 0xff;
      }
      else {
        DAT_00015de8 = 0;
      }
      DAT_00015de7 = 0;
      uVar3 = FUN_fffd0902();
      PTR_DAT_00025d60[0x3f7] = 2;
      return uVar3;
    }
    if (PTR_DAT_00025d60[0x2ef] == '\x04') {
      FUN_fffcf583();
      uVar3 = FUN_fffd05cf();
      return uVar3;
    }
  }
  FUN_fffcf4f2();
  uVar3 = FUN_fffd05cf();
  return uVar3;
}


// ===== FUN_fffd06d4 @ fffd06d4 (14 bytes)

void FUN_fffd06d4(void)

{
  PTR_DAT_00025d60[0x3f7] = 3;
  return;
}


// ===== FUN_fffd06e2 @ fffd06e2 (33 bytes)

void FUN_fffd06e2(void)

{
  if (PTR_DAT_00025d60[0x87] != '\0') {
    return;
  }
  FUN_fffcf5a0();
  PTR_DAT_00025d60[0x3f7] = 4;
  return;
}


// ===== FUN_fffd0703 @ fffd0703 (123 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0769) */
/* WARNING: Removing unreachable block (ram,0xfffd077b) */
/* WARNING: Removing unreachable block (ram,0xfffd0778) */
/* WARNING: Removing unreachable block (ram,0xfffd076f) */

undefined4 FUN_fffd0703(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  cVar1 = PTR_DAT_00025d60[0x2ed];
  cVar2 = FUN_fffd0566();
  if (cVar1 != cVar2) {
    FUN_fffcf4f2();
    uVar3 = FUN_fffd05cf();
    return uVar3;
  }
  if ((PTR_DAT_00025d60[0x2ee] == '\x10') && (PTR_DAT_00025d60[0x2ef] == '\0')) {
    FUN_fffd03ac();
    uVar3 = FUN_fffd0980();
    PTR_DAT_00025d60[0x3f7] = 6;
    return uVar3;
  }
  uVar3 = FUN_fffd0979();
  return uVar3;
}


// ===== FUN_fffd077e @ fffd077e (388 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd08e9) */
/* WARNING: Removing unreachable block (ram,0xfffd08ff) */
/* WARNING: Removing unreachable block (ram,0xfffd08fc) */
/* WARNING: Removing unreachable block (ram,0xfffd07b0) */
/* WARNING: Removing unreachable block (ram,0xfffd07de) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_fffd077e(uint param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined *puVar7;
  
  if (PTR_DAT_00025d60[0x3f6] == '\x01') {
    PTR_DAT_00025d60[0x3f6] = 0;
    param_1 = (uint)CONCAT11(PTR_DAT_00025d60[0x2ee],PTR_DAT_00025d60[0x2ef]);
    if ((param_1 == _DAT_0001ff02) &&
       (param_1 = (uint)CONCAT11(PTR_DAT_00025d60[0x2f0],PTR_DAT_00025d60[0x2f1]),
       param_1 == _DAT_0001ff04)) {
      FUN_fffd0a16();
      _DAT_0001ff02 = _DAT_0001ff02 + _DAT_0001ff04;
      DAT_00015de4 = DAT_00015de4 + -1;
      if (DAT_00015de4 == '\x01') {
        if (DAT_00015de5 == '\0') {
          _DAT_0001ff04 = 0xc25 - (_DAT_0001ff02 & 0xff);
        }
        else {
          _DAT_0001ff04 = 0x2f4b - (_DAT_0001ff02 & 0xff);
        }
      }
      if (DAT_00015de4 != '\0') {
        uVar4 = FUN_fffd0980();
        PTR_DAT_00025d60[0x3f7] = 6;
        return uVar4;
      }
      uVar1 = dest_code_get();
      if (DAT_00015de5 == '\0') {
        uVar2 = FUN_fffcf5bd();
        if (uVar1 == (uVar2 & 0xff)) {
          puVar5 = &DAT_00012275;
          puVar3 = &DAT_00009012;
          for (iVar6 = 0xc23; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar3 = *puVar5;
            puVar3 = puVar3 + 1;
            puVar5 = puVar5 + 1;
          }
        }
        else {
          FUN_fffb2da6(3);
        }
      }
      else {
        uVar2 = FUN_fffcf5bd();
        if (uVar1 == (uVar2 & 0xff)) {
          puVar5 = &DAT_00012e9a;
          puVar3 = &DAT_000060c9;
          for (puVar7 = &DAT_00002f49; puVar7 != (undefined *)0x0; puVar7 = puVar7 + -1) {
            *puVar3 = *puVar5;
            puVar3 = puVar3 + 1;
            puVar5 = puVar5 + 1;
          }
        }
        else {
          FUN_fffb2da6(3);
        }
      }
      uVar4 = FUN_fffcf5f9();
      PTR_DAT_00025d60[0x3f7] = 7;
      PTR_DAT_00025d60[0x406] = 0;
      return uVar4;
    }
  }
  return param_1;
}


// ===== FUN_fffd0902 @ fffd0902 (119 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0976) */

undefined4 FUN_fffd0902(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar1 = PTR_DAT_00025d60;
  uVar2 = FUN_fffd0566();
  puVar1[0x1e4] = (char)uVar2;
  PTR_DAT_00025d60[0x1e5] = 1;
  PTR_DAT_00025d60[0x1e6] = DAT_00015de7;
  PTR_DAT_00025d60[0x1e7] = DAT_00015de8;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return uVar2;
}

