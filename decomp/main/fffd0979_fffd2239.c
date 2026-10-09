// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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

void FUN_fffd0a16(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  if (DAT_00015de5 != '\0') {
    puVar1 = &DAT_00012e98 + _DAT_0001ff02;
    puVar2 = PTR_DAT_00025d60 + 0x2f2;
    for (uVar3 = (uint)_DAT_0001ff04; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    return;
  }
  puVar1 = &DAT_00012273 + _DAT_0001ff02;
  puVar2 = PTR_DAT_00025d60 + 0x2f2;
  for (uVar3 = (uint)_DAT_0001ff04; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
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
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  cVar1 = PTR_DAT_00025d60[0x2ed];
  cVar2 = FUN_fffd04c1();
  if (cVar1 == cVar2) {
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

undefined1 * FUN_fffd0d0e(undefined1 *param_1)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  cVar1 = PTR_DAT_00025d60[0x2ed];
  cVar3 = FUN_fffd04c1();
  if ((cVar1 == cVar3) && (PTR_DAT_00025d60[0x1e5] == '\x02')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    if (PTR_DAT_00025d60[0x2ef] == '\0') {
      puVar6 = PTR_DAT_00025d60 + 0x2f0;
      puVar4 = &DAT_00015dea;
      for (iVar7 = 0xf; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      if (DAT_00015df9 != '\0') {
        PTR_DAT_00025d60[0x90] = 1;
        PTR_DAT_00025d60[0xbe] = 5;
        PTR_DAT_00025d60[0xc1] = 0;
        puVar5 = (undefined4 *)(PTR_DAT_00025d60 + 0xc2);
        for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar5 = 0x20;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
        puVar6 = PTR_DAT_00025d60 + 0xc2;
        puVar4 = &DAT_00015dea;
        for (iVar7 = 0xf; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar6 = *puVar4;
          puVar6 = puVar6 + 1;
          puVar4 = puVar4 + 1;
        }
        PTR_DAT_00025d60[0x3f7] = 5;
        return puVar6;
      }
      puVar6 = (undefined1 *)FUN_fffd0e26();
      return puVar6;
    }
    if (PTR_DAT_00025d60[0x2ef] == '\x01') {
      puVar6 = (undefined1 *)FUN_fffd0e18();
      return puVar6;
    }
    if (PTR_DAT_00025d60[0x2ef] == '\x02') {
      puVar6 = (undefined1 *)FUN_fffd0e1f();
      return puVar6;
    }
  }
  puVar6 = (undefined1 *)FUN_fffd0979();
  return puVar6;
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
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = PTR_DAT_00025d60 + 0xc2;
  puVar1 = &DAT_00015dea;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  PTR_DAT_00025d60[0x90] = 0;
  FUN_fffd0e6a();
  PTR_DAT_00025d60[0x3f7] = 6;
  return;
}


// ===== FUN_fffd0e6a @ fffd0e6a (105 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd0ed0) */

undefined1 * FUN_fffd0e6a(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  int iVar4;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar3 = PTR_DAT_00025d60;
  uVar1 = FUN_fffd04c1();
  puVar3[0x1e4] = uVar1;
  PTR_DAT_00025d60[0x1e5] = 3;
  puVar2 = PTR_DAT_00025d60 + 0x1e6;
  puVar3 = &DAT_00015dea;
  for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
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
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  cVar1 = PTR_DAT_00025d60[0x2ed];
  cVar2 = FUN_fffd04c1();
  if (cVar1 != cVar2) {
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
  char cVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  cVar1 = PTR_DAT_00025d60[0x2ed];
  cVar3 = FUN_fffd04c1();
  if ((cVar1 == cVar3) && (PTR_DAT_00025d60[0x2ee] == '\x03')) {
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

void FUN_fffd1078(void)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  
  uVar1 = FUN_fffb3b33();
  if (_DAT_0001ff02 == 0) {
    DAT_00012273 = (undefined1)uVar1;
    DAT_00012274 = (undefined1)((ushort)uVar1 >> 8);
    puVar3 = &DAT_00009012;
    puVar2 = &DAT_00012275;
    DAT_00012e98 = DAT_00012273;
    DAT_00012e99 = DAT_00012274;
    for (iVar4 = 0xc23; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar3 = &DAT_000060c9;
    puVar2 = &DAT_00012e9a;
    for (puVar5 = &DAT_00002f49; puVar5 != (undefined *)0x0; puVar5 = puVar5 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  puVar2 = PTR_DAT_00025d60 + 0x1e9;
  if (DAT_00015de5 == '\0') {
    puVar3 = &DAT_00012273 + _DAT_0001ff02;
    for (uVar6 = (uint)_DAT_0001ff04; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  puVar3 = &DAT_00012e98 + _DAT_0001ff02;
  for (uVar6 = (uint)_DAT_0001ff04; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
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
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  cVar1 = PTR_DAT_00025d60[0x2ed];
  cVar2 = FUN_fffd04c1();
  if (cVar1 != cVar2) {
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
        _DAT_0001ff04 = 0xc25 - (_DAT_0001ff02 & 0xff);
      }
      else {
        _DAT_0001ff04 = 0x2f4b - (_DAT_0001ff02 & 0xff);
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

undefined1 * FUN_fffd1252(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  int iVar4;
  
  PTR_DAT_00025d60[0x87] = 1;
  puVar3 = PTR_DAT_00025d60;
  uVar1 = FUN_fffd04c1();
  puVar3[0x1e4] = uVar1;
  PTR_DAT_00025d60[0x1e5] = 0x10;
  PTR_DAT_00025d60[0x1e6] = 0x50;
  PTR_DAT_00025d60[0x1e7] = (char)((ushort)_DAT_0001ff04 >> 8);
  PTR_DAT_00025d60[0x1e8] = DAT_0001ff04;
  puVar2 = PTR_DAT_00025d60 + 0x1e9;
  puVar3 = &DAT_00015dea;
  for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
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
  char cVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  
  if (PTR_DAT_00025d60[0x3f6] != '\x01') {
    return param_1;
  }
  PTR_DAT_00025d60[0x3f6] = 0;
  cVar1 = PTR_DAT_00025d60[0x2ed];
  cVar3 = FUN_fffd04c1();
  if ((cVar1 == cVar3) && (PTR_DAT_00025d60[0x2ee] == '\x10')) {
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
  
  bVar2 = FUN_fffd48d1(PTR_DAT_00025d60[0x41f]);
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
  
  cVar1 = FUN_fffd48d1(PTR_DAT_00025d60[0x41f]);
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
  
  uVar1 = FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pbVar3 = (byte *)FUN_fffd4ada(uVar1);
  if (pbVar3 != (byte *)0x0) {
    cVar2 = FUN_fffd4841(uVar1);
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
  FUN_fffcdd7e();
  return;
}


// ===== FUN_fffd1a46 @ fffd1a46 (119 bytes)

void FUN_fffd1a46(char param_1)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  char *pcVar4;
  
  cVar1 = FUN_fffd4841(PTR_DAT_00025d60[0x420]);
  if ((cVar1 != '\0') && (param_1 < '\0')) {
    uVar2 = FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
    bVar3 = FUN_fffd4841(uVar2);
    pcVar4 = (char *)FUN_fffd4ada(uVar2);
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
    FUN_fffb2da6(1);
    FUN_fffc23a4();
    return;
  }
  if (cVar1 == '\x02') {
    FUN_fffcdc1f();
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

