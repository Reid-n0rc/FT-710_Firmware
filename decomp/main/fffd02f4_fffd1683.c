// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd02f4 @ fffd02f4 (5 bytes)

void FUN_fffd02f4(void)

{
  reset_menu();
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

/* WARNING: Removing unreachable block (ram,0xfffd03f4) */
/* WARNING: Removing unreachable block (ram,0xfffd03c7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffd03ac(void)

{
  if (DAT_00015de5 == '\0') {
    DAT_00015de4 = 0xd;
  }
  else {
    DAT_00015de4 = 0x30;
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
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  bVar1 = PTR_DAT_00025d60[0x2ed];
  uVar2 = FUN_fffd0566();
  if (bVar1 == uVar2) {
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
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  bVar1 = PTR_DAT_00025d60[0x2ed];
  uVar2 = FUN_fffd0566();
  if (bVar1 != uVar2) {
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
  uint uVar2;
  
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
          _DAT_0001ff04 = 0xc25 - _DAT_0001ff02;
        }
        else {
          _DAT_0001ff04 = 0x2f4b - _DAT_0001ff02;
        }
      }
      if (DAT_00015de4 != '\0') {
        uVar2 = FUN_fffd0980();
        PTR_DAT_00025d60[0x3f7] = 6;
        return uVar2;
      }
      uVar1 = dest_code_get();
      if (DAT_00015de5 == '\0') {
        uVar2 = FUN_fffcf5bd();
        if (uVar1 == uVar2) {
          smovf(0x9012,0x12275,0xc23);
        }
        else {
          beep_request(3);
        }
      }
      else {
        uVar2 = FUN_fffcf5bd();
        if (uVar1 == uVar2) {
          smovf(0x60c9,0x12e9a,0x2f49);
        }
        else {
          beep_request(3);
        }
      }
      uVar2 = FUN_fffcf5f9();
      PTR_DAT_00025d60[0x3f7] = 7;
      PTR_DAT_00025d60[0x406] = 0;
      return uVar2;
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


// ===== FUN_fffd0979 @ fffd0979 (7 bytes)

void FUN_fffd0979(void)

{
  FUN_fffcf4f2();
  FUN_fffd05cf();
  return;
}


// ===== FUN_fffd0980 @ fffd0980 (150 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0a13) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_fffd0980(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar1 = PTR_DAT_00025d60;
  uVar2 = FUN_fffd0566();
  puVar1[0x1e4] = (char)uVar2;
  PTR_DAT_00025d60[0x1e5] = (char)((ushort)_DAT_0001ff02 >> 8);
  PTR_DAT_00025d60[0x1e6] = DAT_0001ff02;
  PTR_DAT_00025d60[0x1e7] = (char)((ushort)_DAT_0001ff04 >> 8);
  PTR_DAT_00025d60[0x1e8] = DAT_0001ff04;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 7;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x1e0] = 0x44;
  return uVar2;
}


// ===== FUN_fffd0a16 @ fffd0a16 (82 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_fffd0a16(void)

{
  if (DAT_00015de5 != '\0') {
    smovf(&DAT_00012e98 + _DAT_0001ff02,PTR_DAT_00025d60 + 0x2f2,(uint)_DAT_0001ff04);
    return &DAT_00012e98 + _DAT_0001ff02 + _DAT_0001ff04;
  }
  smovf(&DAT_00012273 + _DAT_0001ff02,PTR_DAT_00025d60 + 0x2f2,(uint)_DAT_0001ff04);
  return &DAT_00012273 + _DAT_0001ff02 + _DAT_0001ff04;
}


// ===== FUN_fffd0a68 @ fffd0a68 (138 bytes)

void FUN_fffd0a68(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d60[0x3f7];
  if (cVar1 == 'c') {
    if (0x14 < DAT_00015dfb) {
      DAT_00015dfb = 0;
      PTR_DAT_00025d60[0x87] = 1;
      FUN_fffd0c59();
      PTR_DAT_00025d60[0x3f7] = 4;
      return;
    }
    DAT_00015dfb = DAT_00015dfb + 1;
    return;
  }
  if (cVar1 == '\x03') {
    FUN_fffd0c38();
    return;
  }
  if (cVar1 == '\x04') {
    FUN_fffd0d0e();
    return;
  }
  if (cVar1 == '\x06') {
    FUN_fffd0ed3();
    return;
  }
  if (cVar1 == '\b') {
    FUN_fffd0f6f();
    return;
  }
  if (cVar1 == '\t') {
    FUN_fffd1130();
    return;
  }
  if (cVar1 == '\n') {
    FUN_fffd12fd();
    return;
  }
  if (cVar1 != '\x01') {
    return;
  }
  FUN_fffd0af2();
  return;
}


// ===== FUN_fffd0af2 @ fffd0af2 (190 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0ba1) */
/* WARNING: Removing unreachable block (ram,0xfffd0bad) */
/* WARNING: Removing unreachable block (ram,0xfffd0baa) */
/* WARNING: Removing unreachable block (ram,0xfffd0b7b) */
/* WARNING: Removing unreachable block (ram,0xfffd0b89) */

undefined4 FUN_fffd0af2(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  bVar1 = PTR_DAT_00025d60[0x2ed];
  uVar2 = FUN_fffd04c1();
  if (bVar1 == uVar2) {
    if (PTR_DAT_00025d60[0x2ef] == '\0') {
      DAT_00015de6 = PTR_DAT_00025d60[0x2f0];
      if (DAT_00015de6 == '\0') {
        DAT_00015de8 = 0xfe;
      }
      else {
        DAT_00015de8 = 0;
      }
      DAT_00015de7 = 0;
      uVar3 = FUN_fffd0bb0();
      PTR_DAT_00025d60[0x3f7] = 2;
      return uVar3;
    }
    if (PTR_DAT_00025d60[0x2ef] == '\x01') {
      FUN_fffcf68f();
      uVar3 = FUN_fffd05cf();
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


// ===== FUN_fffd0bb0 @ fffd0bb0 (119 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0c24) */

undefined4 FUN_fffd0bb0(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar1 = PTR_DAT_00025d60;
  uVar2 = FUN_fffd04c1();
  puVar1[0x1e4] = (char)uVar2;
  PTR_DAT_00025d60[0x1e5] = 1;
  PTR_DAT_00025d60[0x1e6] = DAT_00015de7;
  PTR_DAT_00025d60[0x1e7] = DAT_00015de8;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return uVar2;
}


// ===== FUN_fffd0c27 @ fffd0c27 (17 bytes)

void FUN_fffd0c27(void)

{
  FUN_fffd0bb0();
  PTR_DAT_00025d60[0x3f7] = 2;
  return;
}


// ===== FUN_fffd0c38 @ fffd0c38 (33 bytes)

void FUN_fffd0c38(void)

{
  if (PTR_DAT_00025d60[0x87] != '\x01') {
    return;
  }
  FUN_fffd0c59();
  PTR_DAT_00025d60[0x3f7] = 4;
  return;
}


// ===== FUN_fffd0c59 @ fffd0c59 (181 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0d0b) */

undefined4 FUN_fffd0c59(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar1 = PTR_DAT_00025d60;
  uVar2 = FUN_fffd04c1();
  puVar1[0x1e4] = (char)uVar2;
  PTR_DAT_00025d60[0x1e5] = 2;
  PTR_DAT_00025d60[0x1e6] = 0xff;
  DAT_00015df9 = 1;
  if (DAT_00015de8 != -2) {
    DAT_00015df9 = 0;
    PTR_DAT_00025d60[0x1e6] = DAT_00015de7 + DAT_00015de8;
  }
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return uVar2;
}


// ===== FUN_fffd0d0e @ fffd0d0e (266 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0d8e) */
/* WARNING: Removing unreachable block (ram,0xfffd0e15) */
/* WARNING: Removing unreachable block (ram,0xfffd0e12) */
/* WARNING: Removing unreachable block (ram,0xfffd0df7) */
/* WARNING: Removing unreachable block (ram,0xfffd0e0c) */
/* WARNING: Removing unreachable block (ram,0xfffd0dec) */

undefined * FUN_fffd0d0e(undefined *param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined *puVar4;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  bVar1 = PTR_DAT_00025d60[0x2ed];
  uVar3 = FUN_fffd04c1();
  if ((bVar1 == uVar3) && (PTR_DAT_00025d60[0x1e5] == '\x02')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    if (PTR_DAT_00025d60[0x2ef] == '\0') {
      smovf(0x15dea,PTR_DAT_00025d60 + 0x2f0,0xf);
      if (DAT_00015df9 != '\0') {
        PTR_DAT_00025d60[0x90] = 1;
        PTR_DAT_00025d60[0xbe] = 5;
        PTR_DAT_00025d60[0xc1] = 0;
        sstr(PTR_DAT_00025d60 + 0xc2,0x20,0x32);
        smovf(PTR_DAT_00025d60 + 0xc2,0x15dea,0xf);
        puVar4 = PTR_DAT_00025d60 + 0xd1;
        PTR_DAT_00025d60[0x3f7] = 5;
        return puVar4;
      }
      puVar4 = (undefined *)FUN_fffd0e26(&DAT_00015df9,PTR_DAT_00025d60 + 0x2ff,0);
      return puVar4;
    }
    if (PTR_DAT_00025d60[0x2ef] == '\x01') {
      puVar4 = (undefined *)FUN_fffd0e18();
      return puVar4;
    }
    if (PTR_DAT_00025d60[0x2ef] == '\x02') {
      puVar4 = (undefined *)FUN_fffd0e1f();
      return puVar4;
    }
  }
  puVar4 = (undefined *)FUN_fffd0979();
  return puVar4;
}


// ===== FUN_fffd0e18 @ fffd0e18 (7 bytes)

void FUN_fffd0e18(void)

{
  FUN_fffcf50f();
  FUN_fffd05cf();
  return;
}


// ===== FUN_fffd0e1f @ fffd0e1f (7 bytes)

void FUN_fffd0e1f(void)

{
  FUN_fffcf52c();
  FUN_fffd05cf();
  return;
}


// ===== FUN_fffd0e26 @ fffd0e26 (17 bytes)

void FUN_fffd0e26(void)

{
  FUN_fffcf549();
  PTR_DAT_00025d60[0x3f7] = 7;
  return;
}


// ===== FUN_fffd0e37 @ fffd0e37 (51 bytes)

void FUN_fffd0e37(void)

{
  undefined *puVar1;
  
  smovf(0x15dea,PTR_DAT_00025d60 + 0xc2,0xf);
  puVar1 = PTR_DAT_00025d60 + 0xd1;
  PTR_DAT_00025d60[0x90] = 0;
  FUN_fffd0e6a(&DAT_00015df9,puVar1,0);
  PTR_DAT_00025d60[0x3f7] = 6;
  return;
}


// ===== FUN_fffd0e6a @ fffd0e6a (105 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0ed0) */

undefined * FUN_fffd0e6a(void)

{
  undefined1 uVar1;
  undefined *puVar2;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar2 = PTR_DAT_00025d60;
  uVar1 = FUN_fffd04c1();
  puVar2[0x1e4] = uVar1;
  PTR_DAT_00025d60[0x1e5] = 3;
  smovf(PTR_DAT_00025d60 + 0x1e6,0x15dea,0xf);
  puVar2 = PTR_DAT_00025d60 + 0x1f5;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return puVar2;
}


// ===== FUN_fffd0ed3 @ fffd0ed3 (156 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0f63) */
/* WARNING: Removing unreachable block (ram,0xfffd0f6c) */
/* WARNING: Removing unreachable block (ram,0xfffd0f08) */
/* WARNING: Removing unreachable block (ram,0xfffd0f69) */
/* WARNING: Removing unreachable block (ram,0xfffd0f4e) */
/* WARNING: Removing unreachable block (ram,0xfffd0f39) */
/* WARNING: Removing unreachable block (ram,0xfffd0f1d) */

undefined4 FUN_fffd0ed3(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  bVar1 = PTR_DAT_00025d60[0x2ed];
  uVar2 = FUN_fffd04c1();
  if (bVar1 != uVar2) {
    uVar3 = FUN_fffd0979();
    return uVar3;
  }
  if (PTR_DAT_00025d60[0x2ee] != '\x02') {
    uVar3 = FUN_fffd0979();
    return uVar3;
  }
  if (PTR_DAT_00025d60[0x2ef] == '\0') {
    FUN_fffd03ac();
    FUN_fffd041e();
    uVar3 = FUN_fffd04a6();
    return uVar3;
  }
  if (PTR_DAT_00025d60[0x2ef] == '\x01') {
    uVar3 = FUN_fffd0e26();
    return uVar3;
  }
  if (PTR_DAT_00025d60[0x2ef] != '\x02') {
    uVar3 = FUN_fffd0979();
    return uVar3;
  }
  uVar3 = FUN_fffd0e1f();
  return uVar3;
}


// ===== FUN_fffd0f6f @ fffd0f6f (94 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0fc1) */
/* WARNING: Removing unreachable block (ram,0xfffd0fca) */
/* WARNING: Removing unreachable block (ram,0xfffd0fc7) */

undefined4 FUN_fffd0f6f(undefined4 param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  bVar1 = PTR_DAT_00025d60[0x2ed];
  uVar3 = FUN_fffd04c1();
  if ((bVar1 == uVar3) && (PTR_DAT_00025d60[0x2ee] == '\x03')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    uVar4 = FUN_fffd0fcd();
    return uVar4;
  }
  uVar4 = FUN_fffd0979();
  return uVar4;
}


// ===== FUN_fffd0fcd @ fffd0fcd (17 bytes)

void FUN_fffd0fcd(void)

{
  FUN_fffd0fde();
  PTR_DAT_00025d60[0x3f7] = 9;
  return;
}


// ===== FUN_fffd0fde @ fffd0fde (154 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd1075) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_fffd0fde(void)

{
  undefined *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar1 = PTR_DAT_00025d60;
  uVar2 = FUN_fffd04c1();
  puVar1[0x1e4] = uVar2;
  PTR_DAT_00025d60[0x1e5] = (char)((ushort)_DAT_0001ff02 >> 8);
  PTR_DAT_00025d60[0x1e6] = DAT_0001ff02;
  PTR_DAT_00025d60[0x1e7] = (char)((ushort)_DAT_0001ff04 >> 8);
  PTR_DAT_00025d60[0x1e8] = DAT_0001ff04;
  uVar3 = FUN_fffd1078();
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x107;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x1e0] = 0x45;
  return uVar3;
}


// ===== FUN_fffd1078 @ fffd1078 (184 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_fffd1078(void)

{
  ushort uVar1;
  undefined *puVar2;
  
  uVar1 = dest_code_get();
  if (_DAT_0001ff02 == 0) {
    DAT_00012273 = (undefined1)uVar1;
    DAT_00012274 = (undefined1)(uVar1 >> 8);
    smovf(0x12275,0x9012,0xc23);
    smovf(0x12e9a,0x60c9,0x2f49);
    DAT_00012e98 = DAT_00012273;
    DAT_00012e99 = DAT_00012274;
  }
  puVar2 = PTR_DAT_00025d60 + 0x1e9;
  if (DAT_00015de5 == '\0') {
    smovf(puVar2,&DAT_00012273 + _DAT_0001ff02,(uint)_DAT_0001ff04);
    return puVar2 + _DAT_0001ff04;
  }
  smovf(puVar2,&DAT_00012e98 + _DAT_0001ff02,(uint)_DAT_0001ff04);
  return puVar2 + _DAT_0001ff04;
}


// ===== FUN_fffd1130 @ fffd1130 (290 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd1239) */
/* WARNING: Removing unreachable block (ram,0xfffd124f) */
/* WARNING: Removing unreachable block (ram,0xfffd1167) */
/* WARNING: Removing unreachable block (ram,0xfffd124c) */
/* WARNING: Removing unreachable block (ram,0xfffd11cb) */
/* WARNING: Removing unreachable block (ram,0xfffd1199) */
/* WARNING: Removing unreachable block (ram,0xfffd117a) */
/* WARNING: Removing unreachable block (ram,0xfffd11ac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_fffd1130(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  bVar1 = PTR_DAT_00025d60[0x2ed];
  uVar2 = FUN_fffd04c1();
  if (bVar1 != uVar2) {
    uVar3 = FUN_fffd0979();
    return uVar3;
  }
  if (CONCAT11(PTR_DAT_00025d60[0x2ee],PTR_DAT_00025d60[0x2ef]) != _DAT_0001ff02) {
    uVar3 = FUN_fffd0979();
    return uVar3;
  }
  if (CONCAT11(PTR_DAT_00025d60[0x2f0],PTR_DAT_00025d60[0x2f1]) == _DAT_0001ff04) {
    _DAT_0001ff02 = _DAT_0001ff02 + _DAT_0001ff04;
    DAT_00015de4 = DAT_00015de4 + -1;
    if (DAT_00015de4 == '\x01') {
      if (DAT_00015de5 == '\0') {
        _DAT_0001ff04 = 0xc25 - _DAT_0001ff02;
      }
      else {
        _DAT_0001ff04 = 0x2f4b - _DAT_0001ff02;
      }
    }
    if (DAT_00015de4 != '\0') {
      uVar3 = FUN_fffd0fcd();
      return uVar3;
    }
    uVar3 = FUN_fffd1252();
    PTR_DAT_00025d60[0x3f7] = 10;
    return uVar3;
  }
  uVar3 = FUN_fffd0979();
  return uVar3;
}


// ===== FUN_fffd1252 @ fffd1252 (171 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd12fa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_fffd1252(void)

{
  undefined1 uVar1;
  undefined *puVar2;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar2 = PTR_DAT_00025d60;
  uVar1 = FUN_fffd04c1();
  puVar2[0x1e4] = uVar1;
  PTR_DAT_00025d60[0x1e5] = 0x10;
  PTR_DAT_00025d60[0x1e6] = 0x50;
  PTR_DAT_00025d60[0x1e7] = (char)((ushort)_DAT_0001ff04 >> 8);
  PTR_DAT_00025d60[0x1e8] = DAT_0001ff04;
  smovf(PTR_DAT_00025d60 + 0x1e9,0x15dea,0xf);
  puVar2 = PTR_DAT_00025d60 + 0x1f8;
  PTR_DAT_00025d60[0x1f8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return puVar2;
}


// ===== FUN_fffd12fd @ fffd12fd (151 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd1388) */
/* WARNING: Removing unreachable block (ram,0xfffd1391) */
/* WARNING: Removing unreachable block (ram,0xfffd138e) */

undefined4 FUN_fffd12fd(undefined4 param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  bVar1 = PTR_DAT_00025d60[0x2ed];
  uVar3 = FUN_fffd04c1();
  if ((bVar1 == uVar3) && (PTR_DAT_00025d60[0x2ee] == '\x10')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (PTR_DAT_00025d60[0x2ef] == '\0')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    uVar4 = FUN_fffcf566();
    PTR_DAT_00025d60[0x3f7] = 0xb;
    PTR_DAT_00025d60[0x406] = 0;
    return uVar4;
  }
  uVar4 = FUN_fffd0979();
  return uVar4;
}


// ===== FUN_fffd1394 @ fffd1394 (20 bytes)

void FUN_fffd1394(void)

{
  if (PTR_DAT_00025d60[0x3f7] != '\x01') {
    return;
  }
  FUN_fffd13a8();
  return;
}


// ===== FUN_fffd13a8 @ fffd13a8 (144 bytes)

void FUN_fffd13a8(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  if ((PTR_DAT_00025d60[0x2ed] == 'E') && (PTR_DAT_00025d60[0x2ee] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (PTR_DAT_00025d60[0x2ef] == '\0') {
      FUN_fffd1438();
      PTR_DAT_00025d60[0x3f7] = 2;
      return;
    }
    if (PTR_DAT_00025d60[0x2ef] == '\x04') {
      FUN_fffcf583();
      FUN_fffd05cf();
      return;
    }
  }
  FUN_fffcf4f2();
  FUN_fffd05cf();
  return;
}


// ===== FUN_fffd1438 @ fffd1438 (129 bytes)

void FUN_fffd1438(void)

{
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e4] = 0x45;
  PTR_DAT_00025d60[0x1e5] = 1;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0xff;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 2;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== FUN_fffd14b9 @ fffd14b9 (324 bytes)

void FUN_fffd14b9(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d60[0x3f7] == '\x03') {
    if (PTR_DAT_00025d60[0x3f6] == '\x01') {
      PTR_DAT_00025d60[0x3f6] = 0;
      PTR_DAT_00025d60[0x406] = 0;
      if ((PTR_DAT_00025d60[0x2ed] == 'H') && (PTR_DAT_00025d60[0x2ee] == '\x10')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (PTR_DAT_00025d60[0x2ef] == '\0') {
          FUN_fffcf655();
          PTR_DAT_00025d60[0x3f7] = 4;
          return;
        }
        FUN_fffcf672();
        PTR_DAT_00025d60[0x3f7] = 4;
        return;
      }
      FUN_fffcf4f2();
      FUN_fffd05cf();
      return;
    }
  }
  else if ((PTR_DAT_00025d60[0x3f7] == '\x01') && (PTR_DAT_00025d60[0x3f6] == '\x01')) {
    PTR_DAT_00025d60[0x3f6] = 0;
    if ((PTR_DAT_00025d60[0x2ed] == 'H') && (PTR_DAT_00025d60[0x2ee] == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (PTR_DAT_00025d60[0x2ef] == '\0') {
        DAT_00015de8 = 0xfe;
        FUN_fffd15fd();
        PTR_DAT_00025d60[0x3f7] = 2;
        return;
      }
      if (PTR_DAT_00025d60[0x2ef] == '\x01') {
        FUN_fffcf68f();
        FUN_fffd05cf();
        return;
      }
    }
    FUN_fffcf4f2();
    FUN_fffd05cf();
    return;
  }
  return;
}


// ===== FUN_fffd15fd @ fffd15fd (134 bytes)

void FUN_fffd15fd(void)

{
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e4] = 0x48;
  PTR_DAT_00025d60[0x1e5] = 1;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = DAT_00015de8;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 2;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


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

