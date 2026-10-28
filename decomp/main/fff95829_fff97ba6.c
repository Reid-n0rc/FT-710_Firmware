// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff95829 @ fff95829 (98 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9582f) */

void FUN_fff95829(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3));
  bVar1 = *(byte *)(param_1 + 1);
  DAT_0001b3cc = 1;
  iVar2 = key_event_filter(uVar3,bVar1);
  if (iVar2 != 0) {
    PTR_DAT_00025d38[0x9c] = bVar1 >> 4;
    PTR_DAT_00025d38[0x9d] = bVar1 & 0xf;
    *(undefined2 *)(PTR_DAT_00025d38 + 0x9e) = uVar3;
    PTR_DAT_00025d38[0xa0] = 1;
    return;
  }
  return;
}


// ===== FUN_fff9588b @ fff9588b (473 bytes)

void FUN_fff9588b(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  if (PTR_DAT_00025d38[0x80] == '\x01') {
    DAT_0001b3cc = 1;
    return;
  }
  PTR_DAT_00025d38[0xa1] = *(undefined1 *)(param_1 + 1);
  if ((PTR_DAT_00025d38[0xa1] == '\x06') && (PTR_DAT_00025d38[0x70] == '\x01')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (PTR_DAT_00025d38[0xa1] = 3, PTR_DAT_00025d38[0x74] == '\0')) {
    *(byte *)(param_1 + 2) = ~*(byte *)(param_1 + 2) + 1;
  }
  cVar1 = PTR_DAT_00025d38[0xa1];
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      iVar3 = key_event_filter(0xff1,0);
      if (iVar3 == 0) {
        DAT_0001b3cc = 1;
        return;
      }
      FUN_fffc64c0((int)*(char *)(param_1 + 2));
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 == '\x03') {
      iVar3 = key_event_filter(0xff2,0);
      if (iVar3 == 0) {
        DAT_0001b3cc = 1;
        return;
      }
      FUN_fffc7daf((int)*(char *)(param_1 + 2));
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 == '\x04') {
      if (PTR_DAT_00025d38[0x93] == '\x01') {
        if ((PTR_DAT_00025d38[0x3fd] == '\x01') || (PTR_DAT_00025d38[0x3fd] == '\x02')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if ((bVar2) || (PTR_DAT_00025d38[0x3fd] == '\x03')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          DAT_0001b3cc = 1;
          return;
        }
      }
      if (PTR_DAT_00025d38[0x437] != '\0') {
        FUN_fffc89ef(*(undefined1 *)(param_1 + 2));
        DAT_0001b3cc = 1;
        return;
      }
      FUN_fffc523a(0,0);
      iVar3 = FUN_fffc519d(0,1);
      if (iVar3 != 1) {
        DAT_0001b3cc = 1;
        return;
      }
      PTR_DAT_00025d38[0xa3] = *(undefined1 *)(param_1 + 2);
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 == '\x05') {
      if (PTR_DAT_00025d38[0x437] != '\0') {
        FUN_fffc8a90(*(undefined1 *)(param_1 + 2));
        DAT_0001b3cc = 1;
        return;
      }
      PTR_DAT_00025d38[0xa4] = *(undefined1 *)(param_1 + 2);
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 != '\x06') {
      DAT_0001b3cc = 1;
      return;
    }
  }
  iVar3 = key_event_filter(0xff0,0);
  if (iVar3 != 0) {
    PTR_DAT_00025d38[0xa2] = *(undefined1 *)(param_1 + 2);
    if (PTR_DAT_00025d38[0x437] == '\0') {
      FUN_fffc52d7(PTR_DAT_00025d38[0xa2]);
    }
    else {
      FUN_fff95a64();
    }
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== FUN_fff95a64 @ fff95a64 (106 bytes)

void FUN_fff95a64(byte param_1)

{
  if (0x80 < param_1) {
    if ((byte)(~param_1 + 1) < DAT_00025d3c) {
      DAT_00025d3c = DAT_00025d3c - (byte)(~param_1 + 1);
      return;
    }
    DAT_00025d3c = 0;
    return;
  }
  if (DAT_00025d3c + param_1 < 99999999) {
    DAT_00025d3c = DAT_00025d3c + param_1;
    return;
  }
  DAT_00025d3c = 99999999;
  return;
}


// ===== FUN_fff95ace @ fff95ace (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfff95b7f) */
/* WARNING: Removing unreachable block (ram,0xfff95b76) */
/* WARNING: Removing unreachable block (ram,0xfff95b50) */
/* WARNING: Removing unreachable block (ram,0xfff95ae5) */
/* WARNING: Removing unreachable block (ram,0xfff95ada) */
/* WARNING: Removing unreachable block (ram,0xfff95b02) */
/* WARNING: Removing unreachable block (ram,0xfff95b2a) */
/* WARNING: Removing unreachable block (ram,0xfff95b34) */
/* WARNING: Removing unreachable block (ram,0xfff95b9a) */
/* WARNING: Removing unreachable block (ram,0xfff95bbe) */
/* WARNING: Removing unreachable block (ram,0xfff95bc6) */

void FUN_fff95ace(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = DAT_00025d3c;
  cVar1 = (char)(DAT_00025d3c / 10000000);
  PTR_DAT_00025d38[0x7c] = cVar1 << 4;
  uVar3 = uVar3 - (byte)(cVar1 * -0x80);
  bVar2 = (byte)(uVar3 / 1000000);
  PTR_DAT_00025d38[0x7c] = PTR_DAT_00025d38[0x7c] | bVar2;
  uVar3 = uVar3 - (byte)(bVar2 * '@');
  cVar1 = (char)(uVar3 / 100000);
  PTR_DAT_00025d38[0x7d] = cVar1 << 4;
  uVar3 = uVar3 - (byte)(cVar1 * -0x60);
  bVar2 = (byte)(uVar3 / 10000);
  PTR_DAT_00025d38[0x7d] = PTR_DAT_00025d38[0x7d] | bVar2;
  uVar3 = uVar3 - (byte)(bVar2 * '\x10');
  cVar1 = (char)(uVar3 / 1000);
  PTR_DAT_00025d38[0x7e] = cVar1 << 4;
  uVar3 = uVar3 - (byte)(cVar1 * -0x18);
  bVar2 = (byte)(uVar3 / 100);
  PTR_DAT_00025d38[0x7e] = PTR_DAT_00025d38[0x7e] | bVar2;
  uVar3 = uVar3 - (byte)(bVar2 * 'd');
  cVar1 = (char)(uVar3 / 10);
  PTR_DAT_00025d38[0x7f] = cVar1 << 4;
  PTR_DAT_00025d38[0x7f] = PTR_DAT_00025d38[0x7f] | (char)uVar3 + cVar1 * -10;
  return;
}


// ===== FUN_fff95bf4 @ fff95bf4 (118 bytes)

void FUN_fff95bf4(int param_1)

{
  if (PTR_DAT_00025d38[0xa5] == '\0') {
    PTR_DAT_00025d38[0xa5] = 1;
    if (*(char *)(param_1 + 1) == '\0') {
      PTR_DAT_00025d38[0xa6] = 0;
      PTR_DAT_00025d38[0xa7] = 0;
    }
    else {
      PTR_DAT_00025d38[0xa6] = 1;
      PTR_DAT_00025d38[0xa7] = 1;
    }
  }
  else if (*(char *)(param_1 + 1) == '\0') {
    PTR_DAT_00025d38[0xa6] = 0;
  }
  else {
    PTR_DAT_00025d38[0xa6] = 1;
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== FUN_fff95c6a @ fff95c6a (10 bytes)

void FUN_fff95c6a(void)

{
  DAT_0001b3cc = 1;
  return;
}


// ===== FUN_fff95c74 @ fff95c74 (22 bytes)

void FUN_fff95c74(void)

{
  PTR_DAT_00025d38[0x80] = 0;
  DAT_0001b3cc = 1;
  return;
}


// ===== FUN_fff95c8a @ fff95c8a (50 bytes)

void FUN_fff95c8a(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == '\x02') {
    FUN_fffb2da6(3);
  }
  else if (cVar1 == '\x01') {
    FUN_fffb2da6(2);
  }
  else if (cVar1 == '\0') {
    FUN_fffb2da6(1);
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== FUN_fff95cbc @ fff95cbc (241 bytes)

void FUN_fff95cbc(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == -1) {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xac] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 5;
    FUN_fffb2df4();
    return;
  }
  if (cVar1 == '\x01') {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xab] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    if (*(char *)(param_1 + 5) == '\0') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 2;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x01') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 3;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x02') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 4;
      return;
    }
  }
  else if (cVar1 == '\0') {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xaa] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 1;
    return;
  }
  return;
}


// ===== FUN_fff95dad @ fff95dad (184 bytes)

void FUN_fff95dad(int param_1)

{
  if (*(char *)(param_1 + 1) == -1) {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xac] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 5;
    FUN_fffb2df4();
    return;
  }
  if (*(char *)(param_1 + 1) == '\x01') {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xab] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    if (*(char *)(param_1 + 5) == '\0') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 2;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x01') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 3;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x02') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 4;
      return;
    }
  }
  return;
}


// ===== FUN_fff95e65 @ fff95e65 (50 bytes)

void FUN_fff95e65(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_0001b3cc = 1;
  PTR_DAT_00025d38[0x3f6] = 1;
  puVar1 = PTR_DAT_00025d38 + 0x2ed;
  for (iVar2 = 0x109; param_1 = param_1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
  }
  return;
}


// ===== FUN_fff95e97 @ fff95e97 (50 bytes)

void FUN_fff95e97(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_0001b3cc = 1;
  PTR_DAT_00025d38[0x3f6] = 1;
  puVar1 = PTR_DAT_00025d38 + 0x2ed;
  for (iVar2 = 0x109; param_1 = param_1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
  }
  return;
}


// ===== FUN_fff95ec9 @ fff95ec9 (10 bytes)

void FUN_fff95ec9(void)

{
  DAT_0001b3cc = 1;
  return;
}


// ===== FUN_fff95ed3 @ fff95ed3 (83 bytes)

void FUN_fff95ed3(int param_1)

{
  PTR_DAT_00025d38[0xad] = *(undefined1 *)(param_1 + 1);
  PTR_DAT_00025d38[0xae] = *(undefined1 *)(param_1 + 2);
  PTR_DAT_00025d38[0xaf] = *(undefined1 *)(param_1 + 3);
  PTR_DAT_00025d38[0xb0] = *(undefined1 *)(param_1 + 4);
  PTR_DAT_00025d38[0xb1] = *(undefined1 *)(param_1 + 5);
  DAT_0001b3cc = 1;
  return;
}


// ===== FUN_fff95f26 @ fff95f26 (25 bytes)

void FUN_fff95f26(void)

{
  undefined1 local_1;
  
  local_1 = 6;
  FUN_fffb175b(&local_1,1);
  DAT_0001b3d2 = 1;
  return;
}


// ===== FUN_fff95f3f @ fff95f3f (25 bytes)

void FUN_fff95f3f(void)

{
  undefined1 local_1;
  
  local_1 = 0x15;
  FUN_fffb175b(&local_1,1);
  DAT_0001b3d2 = 1;
  return;
}


// ===== FUN_fff95f58 @ fff95f58 (689 bytes)

void FUN_fff95f58(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_0001b3d0 == '\x01') {
    FUN_fff96225();
    return;
  }
  if (PTR_DAT_00025d38[0xb7] == '\x01') {
    FUN_fff986e0();
    return;
  }
  if ((PTR_DAT_00025d38[0x400] == '\x01') && (PTR_DAT_00025d38[0x93] != '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d38[0x400] = 0;
    FUN_fff9a17d();
    return;
  }
  if (PTR_DAT_00025d38[0x447] == '\x01') {
    FUN_fff98797();
    return;
  }
  if (PTR_DAT_00025d38[0xba] != '\0') {
    if ((PTR_DAT_00025d38[0x1c0] == '\x01') || (PTR_DAT_00025d38[0x1c1] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      FUN_fff9c46d();
      return;
    }
    FUN_fff98ecb();
    return;
  }
  if (PTR_DAT_00025d38[0x81] == '\x01') {
    PTR_DAT_00025d38[0x81] = 0;
    FUN_fff98869();
    return;
  }
  if (PTR_DAT_00025d38[0x80] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x83] == '\x01') {
    PTR_DAT_00025d38[0x83] = 0;
    FUN_fff9889c();
    return;
  }
  if (PTR_DAT_00025d38[0x82] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x85] == '\x01') {
    PTR_DAT_00025d38[0x85] = 0;
    FUN_fff988f2();
    return;
  }
  if (PTR_DAT_00025d38[0x84] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x86] == '\x01') {
    FUN_fff98925();
    return;
  }
  if (PTR_DAT_00025d38[0x87] == '\x01') {
    FUN_fff98bcd();
    return;
  }
  if (PTR_DAT_00025d38[0x88] != '\0') {
    if (PTR_DAT_00025d38[0x90] != '\x01') {
      return;
    }
    FUN_fff9a2d1();
    return;
  }
  if (PTR_DAT_00025d38[0x89] == '\x01') {
    FUN_fff98e39();
    return;
  }
  if (PTR_DAT_00025d38[0x8a] == '\x01') {
    FUN_fff98e58();
    return;
  }
  if (PTR_DAT_00025d38[0x8b] == '\x01') {
    FUN_fff98e77();
    return;
  }
  if (PTR_DAT_00025d38[0x8c] == '\x01') {
    FUN_fff98ecb();
    return;
  }
  if (PTR_DAT_00025d38[0x8d] == '\x01') {
    FUN_fff9a0cc();
    return;
  }
  if (PTR_DAT_00025d38[0x99] == '\x01') {
    FUN_fff98f7c();
    return;
  }
  if (PTR_DAT_00025d38[0x9a] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x8f] == '\0') {
    if ((PTR_DAT_00025d38[0x1c0] == '\x01') || (PTR_DAT_00025d38[0x1c1] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fff96124;
    }
  }
  bVar1 = false;
LAB_fff96124:
  if (bVar1) {
    FUN_fff98ecb();
    return;
  }
  if (PTR_DAT_00025d38[0x90] == '\x01') {
    FUN_fff9a2d1();
    return;
  }
  if (PTR_DAT_00025d38[0x93] == '\x01') {
    FUN_fff9a8e3();
    return;
  }
  if (PTR_DAT_00025d38[0x94] == '\x01') {
    FUN_fff9b69e();
    return;
  }
  if (PTR_DAT_00025d38[0x91] == '\x01') {
    FUN_fff9a89b();
    return;
  }
  if (PTR_DAT_00025d38[0x95] == '\x01') {
    iVar2 = FUN_fffb23f3(0x29);
    if (iVar2 != 1) {
      return;
    }
    FUN_fffb237a(0x29,100);
    FUN_fff9aaad();
    return;
  }
  if (PTR_DAT_00025d38[0x96] == '\x01') {
    FUN_fff9ab2a();
    return;
  }
  if (PTR_DAT_00025d38[0x97] != '\x01') {
    FUN_fff9c42a();
    return;
  }
  FUN_fff9bb23();
  return;
}


// ===== FUN_fff96209 @ fff96209 (28 bytes)

void FUN_fff96209(void)

{
  FUN_fffb175b(&DAT_00001456,DAT_0001b628);
  DAT_0001b3d2 = 1;
  return;
}


// ===== FUN_fff96225 @ fff96225 (28 bytes)

void FUN_fff96225(void)

{
  DAT_0001b3d1 = 1;
  FUN_fff96241();
  DAT_0001b628 = 0xb6;
  FUN_fff9c5b2(0xb6);
  return;
}


// ===== FUN_fff96241 @ fff96241 (532 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfff96241) */
/* WARNING: Removing unreachable block (ram,0xfff96452) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_fff96241(void)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  
  FUN_fff9c655(0xb5,&DAT_00001456);
  DAT_00001456 = 0x60;
  puVar4 = (undefined4 *)ver_main();
  _DAT_000019c3 = *(undefined2 *)(puVar4 + 1);
  DAT_000019bf._1_1_ = (undefined1)((uint)*puVar4 >> 8);
  uVar1 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar4;
  cVar2 = hex2nib(uVar1);
  bVar3 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001457 = cVar2 << 4 | bVar3;
  cVar2 = hex2nib(DAT_000019c3);
  bVar3 = hex2nib(DAT_000019c4);
  DAT_00001458 = cVar2 << 4 | bVar3;
  puVar4 = (undefined4 *)ver_display();
  _DAT_000019c3 = *(undefined2 *)(puVar4 + 1);
  DAT_000019bf._1_1_ = (undefined1)((uint)*puVar4 >> 8);
  uVar1 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar4;
  cVar2 = hex2nib(uVar1);
  bVar3 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001459 = cVar2 << 4 | bVar3;
  cVar2 = hex2nib(DAT_000019c3);
  bVar3 = hex2nib(DAT_000019c4);
  DAT_0000145a = cVar2 << 4 | bVar3;
  puVar4 = (undefined4 *)ver_dsp();
  _DAT_000019c3 = *(undefined2 *)(puVar4 + 1);
  DAT_000019bf._1_1_ = (undefined1)((uint)*puVar4 >> 8);
  uVar1 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar4;
  cVar2 = hex2nib(uVar1);
  bVar3 = hex2nib(DAT_000019bf._2_1_);
  DAT_0000145b = cVar2 << 4 | bVar3;
  cVar2 = hex2nib(DAT_000019c3);
  bVar3 = hex2nib(DAT_000019c4);
  DAT_0000145c = cVar2 << 4 | bVar3;
  puVar4 = (undefined4 *)ver_sdr();
  _DAT_000019c3 = *(undefined2 *)(puVar4 + 1);
  DAT_000019bf._1_1_ = (undefined1)((uint)*puVar4 >> 8);
  uVar1 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar4;
  cVar2 = hex2nib(uVar1);
  bVar3 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001461 = cVar2 << 4 | bVar3;
  cVar2 = hex2nib(DAT_000019c3);
  bVar3 = hex2nib(DAT_000019c4);
  DAT_00001462 = cVar2 << 4 | bVar3;
  if ((*(short *)(PTR_DAT_00025d38 + 0x32) == 0) && (DAT_00004660 != '\0')) {
    *(undefined2 *)(PTR_DAT_00025d38 + 0x32) = 0xdb;
  }
  DAT_00001463 = (undefined1)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x32) >> 8);
  DAT_00001464 = (undefined1)*(undefined2 *)(PTR_DAT_00025d38 + 0x32);
  *(undefined2 *)(PTR_DAT_00025d38 + 0x32) = 0;
  FUN_fff96455();
  puVar6 = &DAT_000016a1;
  puVar5 = &DAT_00001465;
  for (iVar7 = 0x97; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = *puVar6;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  DAT_000014fc = DAT_00009b0d;
  DAT_00001505 = DAT_00009b09;
  DAT_00001501 = DAT_00009b05;
  DAT_000014fd = DAT_00009b01;
  DAT_00001509 = DAT_00009dc5;
  return puVar5;
}


// ===== FUN_fff96455 @ fff96455 (2367 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96d91) */
/* WARNING: Removing unreachable block (ram,0xfff96bd9) */
/* WARNING: Removing unreachable block (ram,0xfff96645) */
/* WARNING: Removing unreachable block (ram,0xfff96c0b) */
/* WARNING: Removing unreachable block (ram,0xfff96cbc) */
/* WARNING: Removing unreachable block (ram,0xfff96d02) */

undefined4 FUN_fff96455(void)

{
  undefined1 uVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  bool local_a;
  byte local_9;
  short sStack_8;
  
  local_a = DAT_00009dbd == '\0';
  if (local_a) {
    DAT_00020874 = &DAT_00009d09;
    PTR_DAT_00025d38[0x40e] = 0;
  }
  else {
    DAT_00020874 = &DAT_00009d63;
    PTR_DAT_00025d38[0x40e] = 1;
  }
  local_a = !local_a;
  DAT_000016a1 = DAT_00009c37;
  DAT_000016a2 = FUN_fff96dde();
  uRam000016a3 = FUN_fff96f3e();
  DAT_000016a4 = FUN_fff96fb7();
  uRam000016a5 = FUN_fff9700b();
  uRam000016a6 = FUN_fff97049();
  uRam000016a7 = FUN_fff97075();
  DAT_000016a8 = FUN_fff970b8();
  uRam000016a9 = FUN_fff97105();
  uRam000016aa = FUN_fff9716f(DAT_00020874);
  bRam000016ab = DAT_00009c5b & 7;
  uRam000016ac = FUN_fff971fc(DAT_00020874);
  uRam000016ad = FUN_fff9728c(DAT_00020874);
  uRam000016ae = FUN_fff97430();
  uRam000016af = FUN_fff97567();
  uRam000016b0 = FUN_fff976d2();
  uRam000016b1 = FUN_fff9770b(local_a);
  iVar4 = FUN_fffc4f8f();
  if (iVar4 == 0) {
    bRam000016b2 = DAT_00009c5a << 4 | DAT_00009be8 & 0xf;
  }
  else {
    bRam000016b2 = DAT_00009be8 & 0x5f | 0x50;
  }
  FUN_fff977b3(0x16b3,DAT_00020874);
  local_9 = *DAT_00020874 & 0xf;
  if ((local_9 == 3) || (local_9 == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff9782b();
  }
  FUN_fff978eb(0x16b9,DAT_00020874);
  if (DAT_00009ad5 < '\0') {
    bRam000016b9 = bRam000016b9 | 0x80;
  }
  FUN_fff9795f(0x16bb,DAT_00020874);
  FUN_fff979d3(0x16bd,DAT_00020874);
  FUN_fff97a44(0x16bf,DAT_00020874);
  uRam000016c1 = DAT_00009c5f;
  cRam000016c2 = DAT_00009c04 + '\x1e';
  uRam000016c3 = FUN_fff97abc(DAT_00020874);
  uRam000016c4 = FUN_fff97b7b();
  FUN_fff97ba6();
  uRam000016cb = 0xff;
  if (PTR_DAT_00025d38[0x483] == '\x01') {
    uRam000016cc = 0x2d;
  }
  else {
    uRam000016cc = FUN_fff97c74();
  }
  DAT_0001b62a = 0x2d;
  bRam000016cd = DAT_00009d09 & 0xf;
  DAT_0001b62e = 0x2e;
  uRam000016ce = FUN_fff97cf7(0);
  bRam000016cf = local_9;
  uRam000016d0 = FUN_fff97e1d(0);
  if (PTR_DAT_00025d38[0x437] == '\0') {
    DAT_000019c9 = 0;
    DAT_000019c5 = 0;
    FUN_fff982aa(0,&DAT_000019c5);
    uRam000016d5 = DAT_000019c9;
    uRam000016d1 = DAT_000019c5;
  }
  else {
    FUN_fff95ace();
    local_9 = 5;
    puVar6 = PTR_DAT_00025d38 + 0x7b;
    puVar5 = (undefined1 *)0x16d1;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar6;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  uRam000016de = DAT_00009d5f;
  uRam000016da = DAT_00009d5b;
  uRam000016d6 = DAT_00009d57;
  uRam000016e2 = PTR_DAT_00025d38[0x425];
  uRam000016e3 = DAT_00009d51;
  uRam000016e4 = DAT_00009d52;
  DAT_0001b62c = 0x46;
  bRam000016e6 = DAT_00009d63 & 0xf;
  DAT_0001b630 = 0x47;
  uRam000016e7 = FUN_fff97cf7(1);
  bRam000016e8 = local_9;
  uRam000016e9 = FUN_fff97e1d(1);
  DAT_000019c9 = 0;
  DAT_000019c5 = 0;
  FUN_fff982aa(1,&DAT_000019c5);
  uRam000016ee = DAT_000019c9;
  uRam000016ea = DAT_000019c5;
  uRam000016f7 = DAT_00009db9;
  uRam000016f3 = DAT_00009db5;
  uRam000016ef = DAT_00009db1;
  uRam000016fb = PTR_DAT_00025d38[0x426];
  uRam000016fc = DAT_00009dab;
  uRam000016fd = DAT_00009dac;
  if (DAT_00009dbd == '\x01') {
    DAT_00020878 = &DAT_000016a0 + DAT_0001b62a;
    DAT_0002087c = &DAT_000016a0 + DAT_0001b62c;
    for (sStack_8 = DAT_0001b62c - DAT_0001b62a; sStack_8 != 0; sStack_8 = sStack_8 + -1) {
      uVar1 = *DAT_00020878;
      *DAT_00020878 = *DAT_0002087c;
      *DAT_0002087c = uVar1;
      DAT_00020878 = DAT_00020878 + 1;
      DAT_0002087c = DAT_0002087c + 1;
    }
  }
  if (DAT_00009c5e == '\x01') {
    (&DAT_000016a0)[DAT_0001b62e] = 9;
    (&DAT_000016a0)[DAT_0001b630] = 10;
  }
  uRam000016ff = FUN_fff9849e();
  uRam00001700 = FUN_fff98526(DAT_00020874);
  uRam00001707 = 0;
  bRam00001708 = DAT_00009a8d & 3 | DAT_00009a8c << 7;
  cRam00001709 = (DAT_00009a79 & 3) << 4;
  uRam0000170a = DAT_00009c03;
  uRam0000170b = 0;
  uRam0000170c = 0;
  uRam0000170d = 0;
  uRam0000170e = 0;
  uRam0000170f = 0;
  uRam00001710 = 0;
  bRam00001711 = DAT_00009c3c & 7 | (DAT_00009c39 & 3) << 5 | 0x18;
  sVar3 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10;
  uRam00001713 = (undefined1)((ushort)sVar3 >> 8);
  uRam00001714 = (undefined1)sVar3;
  FUN_fff98566(0x1715);
  FUN_fff985c5(0x1719);
  FUN_fff985f5(0x171d);
  FUN_fff98691(0x1721);
  return 0x98;
}


// ===== FUN_fff96d94 @ fff96d94 (74 bytes)

char FUN_fff96d94(byte param_1)

{
  byte bVar1;
  byte local_3;
  
  local_3 = DAT_00009014;
  if ((DAT_00009ac0 == '\0') && (4 < DAT_00009014)) {
    local_3 = 5;
  }
  bVar1 = param_1;
  if (param_1 < local_3) {
    bVar1 = local_3;
  }
  local_3 = bVar1;
  local_3 = local_3 - param_1;
  if (local_3 == '\0') {
    local_3 = '\x01';
  }
  return local_3;
}


// ===== FUN_fff96dde @ fff96dde (352 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96f1f) */
/* WARNING: Removing unreachable block (ram,0xfff96f22) */
/* WARNING: Removing unreachable block (ram,0xfff96f21) */
/* WARNING: Removing unreachable block (ram,0xfff96e46) */
/* WARNING: Removing unreachable block (ram,0xfff96e4a) */
/* WARNING: Removing unreachable block (ram,0xfff96e57) */
/* WARNING: Removing unreachable block (ram,0xfff96e56) */
/* WARNING: Removing unreachable block (ram,0xfff96e6a) */
/* WARNING: Removing unreachable block (ram,0xfff96e69) */
/* WARNING: Removing unreachable block (ram,0xfff96e48) */
/* WARNING: Removing unreachable block (ram,0xfff96e83) */
/* WARNING: Removing unreachable block (ram,0xfff96e82) */
/* WARNING: Removing unreachable block (ram,0xfff96e96) */
/* WARNING: Removing unreachable block (ram,0xfff96e95) */

undefined1 FUN_fff96dde(void)

{
  undefined1 local_2;
  
  if (DAT_00009c35 == '\0') {
    uRam00000000 = 1;
  }
  if (DAT_00009c36 == '\0') {
    if (DAT_00009c35 == '\0') {
      if (PTR_DAT_00025d38[0x67] == '\0') {
        uRam00000000 = 1;
        if (DAT_00009c38 == '\0') {
          local_2 = 3;
        }
        else if (DAT_00009c38 == '\x01') {
          local_2 = 4;
        }
        else {
          local_2 = 5;
        }
      }
      else if (DAT_00009c38 == '\0') {
        local_2 = 9;
      }
      else if (DAT_00009c38 == '\x01') {
        local_2 = 10;
      }
      else {
        local_2 = 0xb;
      }
    }
    else if (DAT_00009c38 == '\0') {
      local_2 = 3;
    }
    else if (DAT_00009c38 == '\x01') {
      local_2 = 4;
    }
    else {
      local_2 = 5;
    }
  }
  else if (DAT_00009c35 == '\0') {
    if (PTR_DAT_00025d38[0x67] == '\0') {
      uRam00000000 = 1;
      local_2 = 0;
    }
    else {
      local_2 = 2;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fff96f3e @ fff96f3e (121 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96f69) */

byte FUN_fff96f3e(void)

{
  char local_3;
  byte local_2;
  
  local_2 = DAT_00009dbd;
  if (PTR_DAT_00025d38[0x405] == '\x01') {
    if (DAT_00009dbd == '\0') {
      local_2 = '\x01';
    }
    else {
      local_2 = '\0';
    }
  }
  local_2 = local_2 << 7;
  if (DAT_00009dbd == '\0') {
    local_3 = PTR_DAT_00025d38[0x425];
  }
  else {
    local_3 = PTR_DAT_00025d38[0x426];
  }
  if (DAT_00009c5e == '\x01') {
    local_2 = local_2 | 0x20;
  }
  else if (local_3 == '\0') {
    local_2 = local_2 | 0x10;
  }
  else {
    local_2 = local_2 | 0x40;
  }
  return local_2;
}


// ===== FUN_fff96fb7 @ fff96fb7 (84 bytes)

undefined1 FUN_fff96fb7(void)

{
  bool bVar1;
  undefined1 local_2;
  
  local_2 = 0;
  if ((PTR_DAT_00025d38[0x96] == '\x01') || (PTR_DAT_00025d38[0x97] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d38[0x95] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_2 = 0x20;
  }
  return local_2;
}


// ===== FUN_fff9700b @ fff9700b (62 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97017) */
/* WARNING: Removing unreachable block (ram,0xfff97028) */

byte FUN_fff9700b(void)

{
  return DAT_00009c5e | (DAT_00009c3d & 1) << 5 | (DAT_00009dc6 & 1) << 6;
}


// ===== FUN_fff97049 @ fff97049 (44 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97055) */
/* WARNING: Removing unreachable block (ram,0xfff97063) */

byte FUN_fff97049(void)

{
  return (DAT_00009b17 & 1) << 6 | DAT_00009b16 << 7;
}


// ===== FUN_fff97075 @ fff97075 (67 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97082) */
/* WARNING: Removing unreachable block (ram,0xfff97091) */
/* WARNING: Removing unreachable block (ram,0xfff970a6) */

byte FUN_fff97075(void)

{
  return (PTR_DAT_00025d38[0x69] & 3) << 4 |
         (PTR_DAT_00025d38[0x68] & 1) << 6 | PTR_DAT_00025d38[0x67] << 7;
}


// ===== FUN_fff970b8 @ fff970b8 (77 bytes)

byte FUN_fff970b8(void)

{
  byte local_3;
  char local_2;
  
  local_3 = PTR_DAT_00025d38[0x34];
  if (PTR_DAT_00025d38[0x437] == '\0') {
    local_2 = DAT_00009b10;
  }
  else {
    local_2 = PTR_DAT_00025d38[0x480];
  }
  if (local_2 == '\0') {
    local_3 = local_3 & 0xf0;
  }
  return local_3;
}


// ===== FUN_fff97105 @ fff97105 (106 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97135) */
/* WARNING: Removing unreachable block (ram,0xfff97111) */
/* WARNING: Removing unreachable block (ram,0xfff97120) */
/* WARNING: Removing unreachable block (ram,0xfff9714a) */
/* WARNING: Removing unreachable block (ram,0xfff9715e) */

byte FUN_fff97105(void)

{
  return (DAT_00009c5c & 1) << 3 |
         (PTR_DAT_00025d38[0x6c] & 1) << 4 |
         (PTR_DAT_00025d38[0x6b] & 1) << 5 | (PTR_DAT_00025d38[0x6a] & 1) << 6 | DAT_00009be7 << 7;
}


// ===== FUN_fff9716f @ fff9716f (141 bytes)

byte FUN_fff9716f(byte *param_1)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 4 < 2) {
      local_6 = DAT_00009a4b | 0x80;
      goto LAB_fff971e9;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 < 2) {
        local_6 = DAT_00009a36 | 0x80;
      }
      else {
        local_6 = 0;
      }
      goto LAB_fff971e9;
    }
  }
  local_6 = DAT_00009a73 | 0x80;
LAB_fff971e9:
  if ((local_6 & 0x7f) == 6) {
    local_6 = local_6 & 0x7f;
  }
  return local_6;
}


// ===== FUN_fff971fc @ fff971fc (144 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97257) */
/* WARNING: Removing unreachable block (ram,0xfff97270) */

byte FUN_fff971fc(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bStack_7;
  char cStack_6;
  
  bVar2 = FUN_fff9921f();
  bVar3 = *param_1 & 0xf;
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cStack_6 = '\x02';
  }
  else if ((bVar2 & 0x80) == 0) {
    cStack_6 = '\0';
  }
  else {
    cStack_6 = '\x01';
  }
  if ((param_1[5] & 3) == 0) {
    bStack_7 = 0;
  }
  else {
    bStack_7 = (param_1[5] & 3) - 1;
  }
  return param_1[3] & 3 | (bStack_7 & 3) << 2 | cStack_6 << 4;
}


// ===== FUN_fff9728c @ fff9728c (304 bytes)

byte FUN_fff9728c(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bStack_9;
  byte local_6;
  
  local_6 = 0;
  bVar3 = *param_1 & 0xf;
  if (DAT_00009aa4 == '\x01') {
    if ((bVar3 == 3) || (bVar3 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fff972c7;
    }
  }
  bVar1 = false;
LAB_fff972c7:
  if (bVar1) {
    local_6 = 0x80;
  }
  if ((bVar3 == 3) || (bVar3 == 2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && ((param_1[0x14] & 0x20) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | 0x40;
  }
  bVar2 = FUN_fff973bc(param_1);
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (bVar3 != 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar3 != 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | (byte)((bVar2 & 0x40) >> 1);
  }
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (bVar3 != 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar3 != 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | (byte)((bVar2 & 0x80) >> 3);
  }
  bVar3 = FUN_fff9921f(param_1);
  if ((bVar3 & 0x40) == 0) {
    bStack_9 = 0;
  }
  else {
    bStack_9 = (bVar3 >> 4 & 3) + 1;
  }
  return local_6 | bStack_9;
}


// ===== FUN_fff973bc @ fff973bc (116 bytes)

byte FUN_fff973bc(byte *param_1)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = *param_1 & 0xf;
  if (uVar1 == 0xe) {
LAB_fff97422:
    local_6 = param_1[0x28];
  }
  else {
    if (uVar1 - 2 < 2) {
      return param_1[0x14];
    }
    if (uVar1 - 4 < 2) {
      return param_1[0x32];
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97422;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return param_1[0x1e];
        }
        if ((*param_1 & 0xf) != 0 && uVar1 != 1) {
          return 0;
        }
        return param_1[10];
      }
    }
    local_6 = param_1[0x3c];
  }
  return local_6;
}


// ===== FUN_fff97430 @ fff97430 (251 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97487) */
/* WARNING: Removing unreachable block (ram,0xfff97454) */
/* WARNING: Removing unreachable block (ram,0xfff974b0) */
/* WARNING: Removing unreachable block (ram,0xfff974ce) */

byte FUN_fff97430(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  byte bStack_a;
  char cStack_9;
  
  pbVar5 = (byte *)FUN_fffb324c(1);
  bVar3 = *pbVar5 & 0xf;
  iVar6 = FUN_fff9752b(pbVar5);
  iVar7 = FUN_fffc3e3c(pbVar5);
  if ((iVar7 == 0) || (DAT_00009c02 != '\x01')) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  pcVar8 = (char *)FUN_fff99669();
  if (pcVar8 == (char *)0x0) {
    cStack_9 = '\0';
  }
  else if (*pcVar8 == '\0') {
    cStack_9 = '\0';
  }
  else {
    cStack_9 = '\x01';
  }
  bVar4 = FUN_fff973bc(pbVar5);
  bStack_a = ((bVar4 & 2) != 0) << 2 | cStack_9 << 4 | cVar2 << 5 | (iVar6 != 0) << 6;
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_a = bStack_a | (pbVar5[2] >> 2 & 3) + 1;
  }
  return bStack_a;
}


// ===== FUN_fff9752b @ fff9752b (60 bytes)

undefined1 FUN_fff9752b(byte *param_1)

{
  bool bVar1;
  undefined1 local_7;
  
  local_7 = 0;
  if (((*param_1 & 0xf) == 0) || ((*param_1 & 0xf) == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_00009bf1 != '\0')) {
    local_7 = 1;
  }
  return local_7;
}


// ===== FUN_fff97567 @ fff97567 (363 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9769f) */
/* WARNING: Removing unreachable block (ram,0xfff976ae) */

byte FUN_fff97567(void)

{
  bool bVar1;
  char local_3;
  
  if ((PTR_DAT_00025d38[0x1c9] == '\x01') || (PTR_DAT_00025d38[0x78] == '\x02')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_3 = '\x01';
  }
  else {
    if ((PTR_DAT_00025d38[0x417] == '\x01') && (PTR_DAT_00025d38[0x1bc] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_3 = '\x01';
    }
    else {
      if ((PTR_DAT_00025d38[0x417] == '\x01') && (PTR_DAT_00025d38[0x1bc] == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        local_3 = '\0';
      }
      else {
        if ((PTR_DAT_00025d38[0x1cc] == '\x01') || (PTR_DAT_00025d38[0x1cd] == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if ((bVar1) || (PTR_DAT_00025d38[0x78] == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          local_3 = '\x02';
        }
        else {
          if ((PTR_DAT_00025d38[0x92] == '\x01') && (PTR_DAT_00025d38[0x1bc] == '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            local_3 = '\x03';
          }
          else {
            local_3 = '\0';
          }
        }
      }
    }
  }
  return PTR_DAT_00025d38[0x6e] & 3 | (PTR_DAT_00025d38[0x6d] & 3) << 3 | local_3 << 6;
}


// ===== FUN_fff976d2 @ fff976d2 (57 bytes)

/* WARNING: Removing unreachable block (ram,0xfff976ee) */

byte FUN_fff976d2(void)

{
  int iVar1;
  byte bStack_2;
  
  iVar1 = FUN_fffb23f3(0x2a);
  if (iVar1 == 0) {
    bStack_2 = 0x40;
  }
  else {
    bStack_2 = PTR_DAT_00025d38[0x6f] << 4;
  }
  return DAT_00009be6 & 7 | bStack_2;
}


// ===== FUN_fff9770b @ fff9770b (36 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97719) */

byte FUN_fff9770b(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = DAT_00009c35 << 6;
  bVar2 = FUN_fff9772f(param_1);
  return bVar2 | bVar1;
}


// ===== FUN_fff9772f @ fff9772f (85 bytes)

undefined1 FUN_fff9772f(undefined1 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 uStack_9;
  
  uVar2 = FUN_fffb35d7(0,param_1);
  bVar1 = FUN_fffb3480(uVar2);
  if (bVar1 == 0xff) {
    uStack_9 = 0;
  }
  else if (DAT_00009c35 == '\x02') {
    uStack_9 = (&DAT_00009c4c)[bVar1];
  }
  else {
    uStack_9 = (&DAT_00009c3e)[bVar1];
  }
  return uStack_9;
}


// ===== FUN_fff97784 @ fff97784 (47 bytes)

undefined1 FUN_fff97784(uint *param_1,uint *param_2)

{
  undefined1 local_a;
  
  if (*param_1 < *param_2) {
    local_a = 0;
  }
  else if (param_2[1] < *param_1) {
    local_a = 1;
  }
  else {
    local_a = 2;
  }
  return local_a;
}


// ===== FUN_fff977b3 @ fff977b3 (120 bytes)

void FUN_fff977b3(undefined1 *param_1,byte *param_2)

{
  uint uVar1;
  undefined2 local_a;
  
  local_a = 0;
  uVar1 = *param_2 & 0xf;
  if (uVar1 == 0xe) {
LAB_fff97816:
    local_a = 0xc80;
  }
  else {
    if (uVar1 - 2 < 2) {
      local_a = 500;
      goto LAB_fff9781b;
    }
    if (uVar1 - 4 < 2) {
      local_a = 9000;
      goto LAB_fff9781b;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97816;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          local_a = 500;
        }
        else if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          local_a = 3000;
        }
        goto LAB_fff9781b;
      }
    }
    local_a = 16000;
  }
LAB_fff9781b:
  *param_1 = (char)((ushort)local_a >> 8);
  param_1[1] = (char)local_a;
  return;
}


// ===== FUN_fff9782b @ fff9782b (192 bytes)

void FUN_fff9782b(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_fffb23f3(0x28);
  if (iVar1 == 1) {
    FUN_fffb237a(0x28,100);
    if (PTR_DAT_00025d38[0x67] == '\x01') {
      DAT_0001ff1a = 0;
    }
    else {
      DAT_0001ff1a = FUN_fff9d895();
    }
    if (DAT_0001ff1a < -99) {
      DAT_0001ff1a = -99;
    }
    else if (99 < DAT_0001ff1a) {
      DAT_0001ff1a = 99;
    }
    DAT_0001ff1a = DAT_0001ff1a + 0xc;
    if (DAT_0001ff1a < 0x19) {
      if (DAT_0001ff1a < 0) {
        DAT_0001ff1a = 0;
      }
    }
    else {
      DAT_0001ff1a = 0;
    }
  }
  *param_1 = (&DAT_fff804de)[DAT_0001ff1a];
  return;
}


// ===== FUN_fff978eb @ fff978eb (116 bytes)

void FUN_fff978eb(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2 & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x16);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x34);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97954;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x20);
          return;
        }
        if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          *param_1 = *(undefined2 *)(param_2 + 0xc);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x3e);
    return;
  }
LAB_fff97954:
  *param_1 = *(undefined2 *)(param_2 + 0x2a);
  return;
}


// ===== FUN_fff9795f @ fff9795f (116 bytes)

void FUN_fff9795f(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2 & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x18);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x36);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff979c8;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x22);
          return;
        }
        if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          *param_1 = *(undefined2 *)(param_2 + 0xe);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x40);
    return;
  }
LAB_fff979c8:
  *param_1 = *(undefined2 *)(param_2 + 0x2c);
  return;
}


// ===== FUN_fff979d3 @ fff979d3 (113 bytes)

void FUN_fff979d3(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  undefined2 uStack_a;
  byte *local_8;
  undefined2 *local_4;
  
  uVar1 = (uint)(*param_2 & 0xf);
  if (3 < uVar1) {
    if (uVar1 == 4) {
      *param_1 = *(undefined2 *)(param_2 + 0x38);
      return;
    }
    if (uVar1 == 5) {
      *(undefined1 *)param_1 = 0x17;
      *(undefined1 *)((int)param_1 + 1) = 0x70;
      return;
    }
    if (uVar1 == 6) {
LAB_fff97a2d:
      *param_1 = *(undefined2 *)(param_2 + 0x42);
      return;
    }
    if (uVar1 == 7) {
LAB_fff97a36:
      *(undefined1 *)param_1 = 0x3e;
      *(undefined1 *)((int)param_1 + 1) = 0x80;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 == 10) goto LAB_fff97a2d;
      if (uVar1 == 0xb) goto LAB_fff97a36;
      if (2 < uVar1 - 0xc) {
        return;
      }
    }
  }
  local_8 = param_2;
  local_4 = param_1;
  FUN_fffc4e4f(&uStack_a);
  *local_4 = uStack_a;
  return;
}


// ===== FUN_fff97a44 @ fff97a44 (120 bytes)

void FUN_fff97a44(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(*param_2 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x1c);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x3a);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97ab1;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x26);
          return;
        }
        if (uVar1 < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x12);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x44);
    return;
  }
LAB_fff97ab1:
  *param_1 = *(undefined2 *)(param_2 + 0x30);
  return;
}


// ===== FUN_fff97abc @ fff97abc (191 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97af2) */
/* WARNING: Removing unreachable block (ram,0xfff97b1d) */

byte FUN_fff97abc(undefined4 param_1)

{
  int iVar1;
  undefined2 uStack_a;
  undefined1 auStack_8 [2];
  byte local_6;
  undefined4 local_4;
  
  if (PTR_DAT_00025d38[0x70] == '\0') {
    PTR_DAT_00025d38[0x71] = 1;
    PTR_DAT_00025d38[0x72] = 0;
  }
  local_6 = PTR_DAT_00025d38[0x70] << 7;
  if (PTR_DAT_00025d38[0x71] != '\0') {
    local_6 = local_6 | 0x40;
  }
  local_6 = PTR_DAT_00025d38[0x73] | PTR_DAT_00025d38[0x47a] << 2 | local_6;
  local_4 = param_1;
  FUN_fff979d3(auStack_8,param_1);
  FUN_fff977b3(&uStack_a,local_4);
  iVar1 = FUN_fffede1d(auStack_8,&uStack_a,2);
  if (iVar1 != 0) {
    local_6 = local_6 | 0x10;
  }
  FUN_fff97a44(auStack_8,local_4);
  uStack_a = 0;
  iVar1 = FUN_fffede1d(auStack_8,&uStack_a,2);
  if (iVar1 != 0) {
    local_6 = local_6 | 0x20;
  }
  return local_6;
}


// ===== FUN_fff97b7b @ fff97b7b (43 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97b88) */

byte FUN_fff97b7b(void)

{
  return PTR_DAT_00025d38[0x79] & 0xf | PTR_DAT_00025d38[0x78] << 4;
}


// ===== FUN_fff97ba6 @ fff97ba6 (206 bytes)

void FUN_fff97ba6(undefined4 *param_1)

{
  if (PTR_DAT_00025d38[0x41a] != '\x01') {
    if (PTR_DAT_00025d38[0x67] == '\x01') {
      *(undefined1 *)param_1 = 0;
    }
    else if (DAT_00009c35 == '\0') {
      *(undefined1 *)param_1 = 0;
    }
    else if (DAT_00009c35 == '\x01') {
      *(undefined1 *)param_1 = 1;
    }
    else {
      *(undefined1 *)param_1 = 2;
    }
    if (DAT_00009c36 == '\x01') {
      *(undefined1 *)((int)param_1 + 1) = 0x84;
    }
    else {
      *(undefined1 *)((int)param_1 + 1) = 3;
    }
    if (DAT_00009c37 == '\x01') {
      *(undefined1 *)((int)param_1 + 2) = 0x86;
    }
    else {
      *(undefined1 *)((int)param_1 + 2) = 5;
    }
    if (DAT_00009c3d == '\x01') {
      *(undefined1 *)((int)param_1 + 3) = 0x88;
    }
    else {
      *(undefined1 *)((int)param_1 + 3) = 7;
    }
    *(undefined1 *)(param_1 + 1) = 9;
    *(undefined1 *)((int)param_1 + 5) = 10;
    return;
  }
  *(undefined2 *)(param_1 + 1) = 0x7f7f;
  *param_1 = 0x7f7f0c0b;
  return;
}

