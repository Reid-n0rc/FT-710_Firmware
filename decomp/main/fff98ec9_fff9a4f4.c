// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff98ec9 @ fff98ec9 (1 bytes)

void FUN_fff98ec9(void)

{
  return;
}


// ===== FUN_fff98eca @ fff98eca (1 bytes)

void FUN_fff98eca(void)

{
  return;
}


// ===== displink_tx_30_31 @ fff98ecb (177 bytes)

/* 0x30 (0xA0) or 0x31 (0xA3) by +0x1C2 */

void displink_tx_30_31(void)

{
  bool bVar1;
  int iVar2;
  
  PTR_DAT_00025d38[0x8c] = 0;
  PTR_DAT_00025d38[0x1c0] = 0;
  if ((PTR_DAT_00025d38[0x1c2] == -1) || ((byte)PTR_DAT_00025d38[0x1c2] < 0x1e)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    displink_build_30();
    iVar2 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0x9f);
    if (iVar2 == 1) {
      DAT_0001b628 = 0xa0;
      displink_tx_start(0xa0);
      return;
    }
  }
  else if ((byte)PTR_DAT_00025d38[0x1c2] < 0x5f) {
    displink_build_31();
    iVar2 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0xa2);
    if (iVar2 == 1) {
      DAT_0001b628 = 0xa3;
      displink_tx_start(0xa3);
      return;
    }
  }
  return;
}


// ===== displink_tx_34 @ fff98f7c (53 bytes)

/* 0x34 (0xA3 bytes) */

void displink_tx_34(void)

{
  displink_build_34(1,DAT_0001b3d6);
  DAT_0001b628 = 0xa3;
  displink_tx_start(0xa3);
  PTR_DAT_00025d38[0x99] = 0;
  PTR_DAT_00025d38[0x9a] = 1;
  return;
}


// ===== displink_build_30 @ fff98fb1 (622 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99181) */
/* WARNING: Removing unreachable block (ram,0xfff9917b) */

void displink_build_30(void)

{
  byte bVar1;
  int iVar2;
  bool bStack_9;
  byte *pbStack_8;
  char cStack_1;
  
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
  DAT_00001741 = 0x30;
  FUN_fff98cd3();
  DAT_000017d9 = PTR_DAT_00025d38[0x1c2];
  if (PTR_DAT_00025d38[0x1c2] != -1) {
    if (DAT_00009dbd == '\0') {
      pbStack_8 = &DAT_00009d09;
    }
    else {
      pbStack_8 = &DAT_00009d63;
    }
    bStack_9 = DAT_00009dbd != '\0';
    switch(PTR_DAT_00025d38[0x1c2]) {
    case 0:
      DAT_000017da = DAT_00009c5b;
      return;
    case 1:
      DAT_000017da = pbStack_8[3] & 3;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 2:
      if ((pbStack_8[5] & 3) == 0) {
        cStack_1 = '\0';
      }
      else {
        cStack_1 = (pbStack_8[5] & 3) - 1;
      }
      DAT_000017da = cStack_1;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 3:
      bVar1 = FUN_fff9921f(pbStack_8);
      DAT_000017da = bVar1 >> 7;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 4:
      bVar1 = FUN_fff9921f(pbStack_8);
      if ((bVar1 & 0x40) == 0) {
        cStack_1 = '\0';
      }
      else {
        cStack_1 = (bVar1 >> 4 & 3) + 1;
      }
      DAT_000017da = cStack_1;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 5:
      DAT_000017da = *pbStack_8 & 0xf;
      DAT_000017db = 0;
      DAT_000017dc = PTR_DAT_00025d38[0x424];
      return;
    case 6:
      DAT_000017da = scope_span_index(bStack_9);
      return;
    case 7:
    case 8:
      DAT_000017da = 0;
      return;
    case 9:
      DAT_000017da = DAT_00009c39;
      return;
    case 10:
      DAT_000017da = DAT_00009c3a << 6 | DAT_00009c3b << 4 | DAT_00009c3c;
      return;
    case 0xb:
      DAT_000017da = DAT_00009be8;
      DAT_000017db = 0;
      DAT_000017dc = PTR_DAT_00025d38[0x424];
      return;
    case 0xc:
      DAT_000017da = PTR_DAT_00025d38[0x1dc];
      DAT_000017db = 0;
      DAT_000017dc = PTR_DAT_00025d38[0x424];
      return;
    case 0xd:
      iVar2 = FUN_fffc4f8f();
      if (iVar2 == 0) {
        DAT_000017da = DAT_00009c5a;
        return;
      }
      DAT_000017da = 5;
      return;
    }
  }
  return;
}


// ===== FUN_fff9921f @ fff9921f (120 bytes)

byte FUN_fff9921f(byte *param_1)

{
  uint uVar1;
  byte local_7;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 == 0xe) {
LAB_fff99289:
    local_7 = param_1[0x29];
  }
  else {
    if (uVar1 - 2 < 2) {
      return param_1[0x15];
    }
    if (uVar1 - 4 < 2) {
      return param_1[0x33];
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff99289;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return param_1[0x1f];
        }
        if (1 < uVar1) {
          return 0;
        }
        return param_1[0xb];
      }
    }
    local_7 = param_1[0x3d];
  }
  return local_7;
}


// ===== displink_build_31 @ fff99297 (478 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void displink_build_31(void)

{
  char cVar1;
  
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
  DAT_00001741 = 0x31;
  FUN_fff98cd3();
  DAT_000017d9 = PTR_DAT_00025d38[0x1c2] + -0x1e;
  DAT_000017e2 = 0x20;
  _DAT_000017de = 0x20202020;
  _DAT_000017da = 0x20202020;
  cVar1 = PTR_DAT_00025d38[0x1c2];
  if (cVar1 == '^') {
    FUN_fff9a044(0x99);
    return;
  }
  if (cVar1 == '\x1f') {
    FUN_fff9959f(0x99);
    return;
  }
  if (cVar1 == '\"') {
    FUN_fff99e15(0x99);
    return;
  }
  if (cVar1 == '#') {
    FUN_fff9a00f(0x99);
    return;
  }
  if (cVar1 == '$') {
    FUN_fff99abf(0x99);
    return;
  }
  if (cVar1 == '%') {
    FUN_fff99837(0x99);
    return;
  }
  if (cVar1 == '&') {
    FUN_fff99ddb(0x99);
    return;
  }
  if (cVar1 == '\'') {
    FUN_fff997df(0x99);
    return;
  }
  if (cVar1 == '(') {
    FUN_fff99a8a(0x99);
    return;
  }
  if (cVar1 == ')') {
    FUN_fff996e2(0x99);
    return;
  }
  if (cVar1 == '*') {
    FUN_fff99717(0x99);
    return;
  }
  if (cVar1 == '+') {
    FUN_fff9978c(0x99);
    return;
  }
  if (cVar1 == ',') {
    FUN_fff995cc(0x99);
    return;
  }
  if (cVar1 == '-') {
    FUN_fff9960e(0x99);
    return;
  }
  if (cVar1 == '/') {
    FUN_fff99d82(0x99);
    return;
  }
  if (cVar1 == '0') {
    FUN_fff998e2(0x99);
    return;
  }
  if (cVar1 == '1') {
    FUN_fff9992a(0x99);
    return;
  }
  if (cVar1 == '2') {
    FUN_fff99989(0x99);
    return;
  }
  if (cVar1 == '3') {
    FUN_fff999e3(0x99);
    return;
  }
  if (cVar1 == '8') {
    FUN_fff99b70(0x99);
    return;
  }
  if (cVar1 == '9') {
    FUN_fff99ba5(0x99);
    return;
  }
  if (cVar1 == ':') {
    FUN_fff99d42(0x99);
    return;
  }
  if (cVar1 == 'C') {
    FUN_fff99bfe(0x99);
    return;
  }
  if (cVar1 == 'D') {
    FUN_fff99ca2(0x99);
    return;
  }
  if (cVar1 == 'E') {
    FUN_fff99cf2(0x99);
    return;
  }
  if (cVar1 == 'F') {
    FUN_fff99d48(0x99);
    return;
  }
  if (cVar1 == 'U') {
    FUN_fff99c58(0x99);
    return;
  }
  if (cVar1 == 'X') {
    FUN_fff99a29(0x99);
    return;
  }
  if (cVar1 != '\x1e') {
    return;
  }
  FUN_fff99475(0x99);
  return;
}


// ===== FUN_fff99475 @ fff99475 (298 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99588) */
/* WARNING: Removing unreachable block (ram,0xfff994d7) */
/* WARNING: Removing unreachable block (ram,0xfff99568) */
/* WARNING: Removing unreachable block (ram,0xfff9953b) */

void FUN_fff99475(ushort param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  ushort uStack_6;
  undefined1 uStack_4;
  
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x4264302e;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  pbVar3 = (byte *)FUN_fff9c6ab();
  bVar1 = *pbVar3;
  if (bVar1 == 0x3c) {
    (&DAT_00001744)[param_1] = 0x30;
    return;
  }
  if (bVar1 < 0x3d) {
    uStack_4 = 0x2d;
  }
  else {
    uStack_4 = 0x2b;
  }
  uStack_6 = (ushort)bVar1 * 5 - 300;
  if (bVar1 < 0x3c) {
    uStack_6 = ~uStack_6 + 1;
  }
  if ((uint)uStack_6 == ((uStack_6 / 10) * 10 & 0xff)) {
    (&DAT_00001746)[param_1] = 0x30;
  }
  else {
    (&DAT_00001746)[param_1] = 0x35;
  }
  if (uStack_6 < 10) {
    (&DAT_00001743)[param_1] = uStack_4;
    (&DAT_00001744)[param_1] = 0x30;
    return;
  }
  if (uStack_6 < 100) {
    (&DAT_00001743)[param_1] = uStack_4;
    (&DAT_00001744)[param_1] = (char)(uStack_6 / 10) + '0';
    return;
  }
  if (999 < uStack_6) {
    return;
  }
  (&DAT_00001742)[param_1] = uStack_4;
  cVar2 = (char)(uStack_6 / 100);
  (&DAT_00001743)[param_1] = cVar2 + '0';
  (&DAT_00001744)[param_1] = (char)((int)((uint)uStack_6 - (uint)(byte)(cVar2 * 'd')) / 10) + '0';
  return;
}


// ===== FUN_fff9959f @ fff9959f (45 bytes)

/* WARNING: Removing unreachable block (ram,0xfff995b0) */

void FUN_fff9959f(ushort param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_00009be6;
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(&DAT_fff80328 + uVar1 * 8);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(&DAT_fff80324 + uVar1 * 8);
  return;
}


// ===== FUN_fff995cc @ fff995cc (66 bytes)

void FUN_fff995cc(ushort param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  uVar1 = FUN_fffb4062();
  bVar2 = FUN_fff99e4a(uVar1,3,&DAT_000019ca);
  (&DAT_00001748)[param_1] = 0x57;
  uVar5 = (uint)bVar2;
  puVar3 = &DAT_00001748 + (param_1 - uVar5);
  puVar4 = &DAT_000019ca;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ===== FUN_fff9960e @ fff9960e (91 bytes)

void FUN_fff9960e(ushort param_1)

{
  byte bVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  char cStack_3;
  
  pcVar2 = (char *)FUN_fff99669();
  if (pcVar2 == (char *)0x0) {
    cStack_3 = '\0';
  }
  else {
    cStack_3 = *pcVar2;
  }
  if (cStack_3 != '\0') {
    bVar1 = FUN_fff99e4a(cStack_3,3,&DAT_000019d2);
    uVar5 = (uint)bVar1;
    puVar3 = &DAT_00001749 + (param_1 - uVar5);
    puVar4 = &DAT_000019d2;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    return;
  }
  (&DAT_00001748)[param_1] = 0x46;
  *(undefined2 *)(&DAT_00001746 + param_1) = 17999;
  return;
}


// ===== FUN_fff99669 @ fff99669 (121 bytes)

void FUN_fff99669(void)

{
  vfo_mode(1);
  return;
}


// ===== FUN_fff996e2 @ fff996e2 (53 bytes)

void FUN_fff996e2(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = FUN_fff99e4a(DAT_00009bf3,3,&DAT_000019da);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_000019da;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff99717 @ fff99717 (117 bytes)

void FUN_fff99717(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte local_3;
  
  *(undefined2 *)(&DAT_00001747 + param_1) = 0x736d;
  if (DAT_00009af3 == '\0') {
    local_3 = DAT_00009bf4;
  }
  else {
    local_3 = DAT_00009bf5;
  }
  if (0x21 < local_3) {
    local_3 = 0;
  }
  bVar1 = FUN_fff99e4a(*(undefined2 *)(&DAT_fff87ed6 + (uint)local_3 * 2),4,&DAT_000019e2);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001747 + (param_1 - uVar4);
  puVar3 = &DAT_000019e2;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff9978c @ fff9978c (83 bytes)

void FUN_fff9978c(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 local_3;
  
  if (DAT_00009af3 == '\0') {
    local_3 = DAT_00009bf6;
  }
  else {
    local_3 = DAT_00009bf7;
  }
  bVar1 = FUN_fff99e4a(local_3,3,&DAT_000019ea);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_000019ea;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff997df @ fff997df (88 bytes)

void FUN_fff997df(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  if (DAT_00009bf1 != '\0') {
    bVar1 = FUN_fff99e4a(DAT_00009bf1,3,&DAT_000019f2);
    uVar4 = (uint)bVar1;
    puVar2 = &DAT_00001749 + (param_1 - uVar4);
    puVar3 = &DAT_000019f2;
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  (&DAT_00001748)[param_1] = 0x46;
  *(undefined2 *)(&DAT_00001746 + param_1) = 17999;
  return;
}


// ===== FUN_fff99837 @ fff99837 (64 bytes)

void FUN_fff99837(ushort param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined1 uStack_3;
  
  puVar2 = (undefined1 *)FUN_fff99877();
  if (puVar2 == (undefined1 *)0x0) {
    uStack_3 = 0;
  }
  else {
    uStack_3 = *puVar2;
  }
  bVar1 = FUN_fff99e4a(uStack_3,3,&DAT_000019fa);
  uVar4 = (uint)bVar1;
  puVar3 = &DAT_00001749 + (param_1 - uVar4);
  puVar2 = &DAT_000019fa;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar3 = *puVar2;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== FUN_fff99877 @ fff99877 (107 bytes)

void FUN_fff99877(void)

{
  vfo_mode(1);
  return;
}


// ===== FUN_fff998e2 @ fff998e2 (72 bytes)

void FUN_fff998e2(ushort param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  (&DAT_00001748)[param_1] = 0x6d;
  *(undefined2 *)(&DAT_00001746 + param_1) = 0x7077;
  bVar1 = FUN_fff99e4a(DAT_00009c03,2,&DAT_00001a02);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001746 + (param_1 - uVar4);
  puVar3 = &DAT_00001a02;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff9992a @ fff9992a (95 bytes)

void FUN_fff9992a(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = FUN_fff99e4a((ushort)DAT_00009c04 * 10 + 300,4,&DAT_00001a0a);
  (&DAT_00001747)[param_1] = 0x48;
  (&DAT_00001748)[param_1] = 0x7a;
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001747 + (param_1 - uVar4);
  puVar3 = &DAT_00001a0a;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff99989 @ fff99989 (90 bytes)

void FUN_fff99989(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte local_3;
  
  *(undefined2 *)(&DAT_00001747 + param_1) = 0x736d;
  local_3 = DAT_00009c05;
  if (0x21 < DAT_00009c05) {
    local_3 = 0;
  }
  bVar1 = FUN_fff99e4a(*(undefined2 *)(&DAT_fff87ed6 + (uint)local_3 * 2),4,&DAT_00001a12);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001747 + (param_1 - uVar4);
  puVar3 = &DAT_00001a12;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff999e3 @ fff999e3 (70 bytes)

void FUN_fff999e3(ushort param_1)

{
  byte bVar1;
  byte *pbVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  pbVar2 = (byte *)FUN_fffb54a0();
  bVar1 = FUN_fff99e4a((uint)*pbVar2 * 5,3,&DAT_00001a1a);
  (&DAT_00001748)[param_1] = 0x25;
  uVar5 = (uint)bVar1;
  puVar3 = &DAT_00001748 + (param_1 - uVar5);
  puVar4 = &DAT_00001a1a;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ===== FUN_fff99a29 @ fff99a29 (97 bytes)

void FUN_fff99a29(ushort param_1)

{
  byte bVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined2 uStack_4;
  
  pcVar2 = (char *)FUN_fffb552c();
  if (*pcVar2 == '\0') {
    uStack_4 = 700;
  }
  else {
    uStack_4 = 1000;
  }
  bVar1 = FUN_fff99e4a(uStack_4,4,&DAT_00001a22);
  (&DAT_00001747)[param_1] = 0x48;
  (&DAT_00001748)[param_1] = 0x7a;
  uVar5 = (uint)bVar1;
  puVar3 = &DAT_00001747 + (param_1 - uVar5);
  puVar4 = &DAT_00001a22;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ===== FUN_fff99a8a @ fff99a8a (53 bytes)

void FUN_fff99a8a(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = FUN_fff99e4a(DAT_00009bf2,3,&DAT_00001a2a);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a2a;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff99abf @ fff99abf (177 bytes)

void FUN_fff99abf(ushort param_1)

{
  byte bVar1;
  
  bVar1 = FUN_fff9bfb8();
  (&DAT_00001741)[param_1] = 0x20;
  (&DAT_00001742)[param_1] = 0x20;
  (&DAT_00001743)[param_1] = 0x20;
  (&DAT_00001744)[param_1] = 0x20;
  (&DAT_00001745)[param_1] = 0x20;
  (&DAT_00001746)[param_1] = 0x20;
  if (5 < bVar1) {
    (&DAT_00001749)[param_1] = *(undefined1 *)((int)&DAT_fff80355 + (uint)bVar1 * 3 + 2);
    *(undefined2 *)(&DAT_00001747 + param_1) = *(undefined2 *)((int)&DAT_fff80355 + (uint)bVar1 * 3)
    ;
    return;
  }
  (&DAT_00001747)[param_1] = 0x20;
  (&DAT_00001748)[param_1] = 0x20;
  (&DAT_00001749)[param_1] = bVar1 | 0x30;
  return;
}


// ===== FUN_fff99b70 @ fff99b70 (53 bytes)

void FUN_fff99b70(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = FUN_fff99e4a(DAT_00009dc0,2,&DAT_00001a32);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a32;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff99ba5 @ fff99ba5 (89 bytes)

void FUN_fff99ba5(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  byte local_4;
  
  local_4 = DAT_00009d0f;
  if (DAT_00009dbd != '\0') {
    local_4 = DAT_00009d69;
  }
  local_4 = local_4 & 0xf;
  bVar1 = FUN_fff99e4a(local_4,2,&DAT_00001a3a);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a3a;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff99bfe @ fff99bfe (90 bytes)

void FUN_fff99bfe(ushort param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 local_3;
  
  if (DAT_00009dbd == '\0') {
    local_3 = DAT_0000901f;
  }
  else {
    local_3 = DAT_00009021;
  }
  uVar1 = FUN_fff96d94(local_3);
  bVar2 = FUN_fff99e4a(uVar1,2,&DAT_00001a42);
  uVar5 = (uint)bVar2;
  puVar3 = &DAT_00001749 + (param_1 - uVar5);
  puVar4 = &DAT_00001a42;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ===== FUN_fff99c58 @ fff99c58 (74 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99c86) */

void FUN_fff99c58(ushort param_1)

{
  byte local_3;
  
  local_3 = (&DAT_00006150)[(uint)(byte)PTR_DAT_00025d38[0x43a] * 0x5a] & 0xf;
  if (0xd < local_3) {
    local_3 = 0xe;
  }
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(&DAT_fff803f8 + (uint)local_3 * 8);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(&DAT_fff803f4 + (uint)local_3 * 8);
  return;
}


// ===== FUN_fff99ca2 @ fff99ca2 (80 bytes)

void FUN_fff99ca2(ushort param_1)

{
  if (((&DAT_00006151)[(uint)(byte)PTR_DAT_00025d38[0x43a] * 0x5a] & 0x80) != 0) {
    *(undefined4 *)(&DAT_00001745 + param_1) = 0x50494b53;
    *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
    return;
  }
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x4e414353;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  return;
}


// ===== FUN_fff99cf2 @ fff99cf2 (80 bytes)

void FUN_fff99cf2(ushort param_1)

{
  if (((&DAT_00006155)[(uint)(byte)PTR_DAT_00025d38[0x43a] * 0x5a] & 0x80) != 0) {
    *(undefined4 *)(&DAT_00001745 + param_1) = 0x454d414e;
    *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
    return;
  }
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x51455246;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  return;
}


// ===== FUN_fff99d42 @ fff99d42 (6 bytes)

void FUN_fff99d42(void)

{
  return;
}


// ===== FUN_fff99d48 @ fff99d48 (58 bytes)

void FUN_fff99d48(ushort param_1)

{
  int iVar1;
  
  iVar1 = (uint)(DAT_00009c02 != '\0') * 9;
  (&DAT_00001749)[param_1] = (&DAT_fff80354)[iVar1];
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(&DAT_fff80350 + iVar1);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(&DAT_fff8034c + iVar1);
  return;
}


// ===== FUN_fff99d82 @ fff99d82 (61 bytes)

void FUN_fff99d82(ushort param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = vfo_rec_ptr(1);
  iVar2 = FUN_fff99dbf(uVar1);
  iVar2 = (uint)(iVar2 != 0) * 9;
  (&DAT_00001749)[param_1] = (&DAT_fff80354)[iVar2];
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(&DAT_fff80350 + iVar2);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(&DAT_fff8034c + iVar2);
  return;
}


// ===== FUN_fff99dbf @ fff99dbf (28 bytes)

bool FUN_fff99dbf(void)

{
  byte bVar1;
  
  bVar1 = FUN_fff973bc();
  return (bVar1 & 2) != 0;
}


// ===== FUN_fff99ddb @ fff99ddb (58 bytes)

void FUN_fff99ddb(ushort param_1)

{
  int iVar1;
  
  iVar1 = (uint)(DAT_00009bf0 != '\0') * 9;
  (&DAT_00001749)[param_1] = (&DAT_fff80354)[iVar1];
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(&DAT_fff80350 + iVar1);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(&DAT_fff8034c + iVar1);
  return;
}


// ===== FUN_fff99e15 @ fff99e15 (53 bytes)

void FUN_fff99e15(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = FUN_fff99e4a(DAT_00009be9,2,&DAT_00001a4a);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a4a;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff99e4a @ fff99e4a (453 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99f5b) */
/* WARNING: Removing unreachable block (ram,0xfff99f32) */
/* WARNING: Removing unreachable block (ram,0xfff99fa4) */
/* WARNING: Removing unreachable block (ram,0xfff99ecb) */
/* WARNING: Removing unreachable block (ram,0xfff99ea4) */
/* WARNING: Removing unreachable block (ram,0xfff99e5e) */

char FUN_fff99e4a(ushort param_1,char param_2,char *param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  ushort uVar6;
  int iVar7;
  byte local_a;
  
  local_a = '\0';
  cVar5 = (char)param_1;
  if (param_2 == '\x02') {
    bVar1 = param_1 / 10 != 0;
    cVar2 = (char)(param_1 / 10);
    if (bVar1) {
      *param_3 = cVar2 + '0';
    }
    param_3[bVar1] = cVar5 + cVar2 * -10 + '0';
    local_a = bVar1 + '\x01';
  }
  else if (param_2 == '\x03') {
    uVar6 = param_1 / 100;
    cVar2 = (char)uVar6;
    if (uVar6 != 0) {
      *param_3 = cVar2 + '0';
    }
    iVar7 = (int)((uint)param_1 - (uint)(byte)(cVar2 * 'd')) / 10;
    cVar3 = (char)iVar7;
    if (uVar6 != 0) {
      param_3[1] = cVar3 + '0';
      local_a = 2;
    }
    else if ((short)iVar7 == 0) {
      local_a = 0;
    }
    else {
      *param_3 = cVar3 + '0';
      local_a = 1;
    }
    param_3[local_a] = cVar5 + cVar2 * -100 + cVar3 * -10 + '0';
    local_a = local_a + 1;
  }
  else if (param_2 == '\x04') {
    uVar6 = param_1 / 1000;
    cVar2 = (char)uVar6;
    if (uVar6 != 0) {
      *param_3 = cVar2 + '0';
    }
    iVar7 = (int)((uint)param_1 - (uint)(byte)(cVar2 * -0x18)) / 100;
    cVar3 = (char)iVar7;
    if (uVar6 != 0) {
      param_3[1] = cVar3 + '0';
      local_a = 2;
    }
    else if ((short)iVar7 == 0) {
      local_a = 0;
    }
    else {
      *param_3 = cVar3 + '0';
      local_a = 1;
    }
    iVar7 = (int)(((uint)param_1 - (uint)(byte)(cVar2 * -0x18)) - (uint)(byte)(cVar3 * 'd')) / 10;
    cVar4 = (char)iVar7;
    if (local_a == 0) {
      if ((short)iVar7 != 0) {
        *param_3 = cVar4 + '0';
        local_a = 1;
      }
    }
    else {
      param_3[local_a] = cVar4 + '0';
      local_a = local_a + 1;
    }
    param_3[local_a] = cVar5 + cVar2 * '\x18' + cVar3 * -100 + cVar4 * -10 + '0';
    local_a = local_a + 1;
  }
  return local_a;
}


// ===== FUN_fff9a00f @ fff9a00f (53 bytes)

void FUN_fff9a00f(ushort param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar1 = FUN_fff99e4a(DAT_00009bea,2,&DAT_00001a52);
  uVar4 = (uint)bVar1;
  puVar2 = &DAT_00001749 + (param_1 - uVar4);
  puVar3 = &DAT_00001a52;
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== FUN_fff9a044 @ fff9a044 (42 bytes)

void FUN_fff9a044(ushort param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_00025d38;
  (&DAT_00001749)[param_1] = PTR_DAT_00025d38[0x42f];
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(puVar1 + 0x42b);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(puVar1 + 0x427);
  return;
}


// ===== displink_build_34 @ fff9a06e (94 bytes)

void displink_build_34(undefined1 param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  mem_zero(0x98,&DAT_000016a0);
  puVar1 = (undefined4 *)&DAT_00001741;
  for (iVar4 = 0x24a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  DAT_00001741 = 0x34;
  FUN_fff98cd3();
  DAT_000017db = 0;
  puVar3 = &DAT_00001741;
  puVar2 = &DAT_00001456;
  DAT_000017d9 = param_1;
  DAT_000017da = param_2;
  for (iVar4 = 0x24a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ===== displink_tx_65_clock @ fff9a0cc (52 bytes)

/* 0x65 (9 bytes): +0xB2..+0xB6 (clock set [inference]) */

void displink_tx_65_clock(void)

{
  int iVar1;
  
  PTR_DAT_00025d38[0x8d] = 0;
  displink_build_65();
  iVar1 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,8);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 9;
  displink_tx_start(9);
  return;
}


// ===== displink_build_65 @ fff9a100 (125 bytes)

void displink_build_65(void)

{
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
  DAT_00001741 = 0x65;
  DAT_00001742 = PTR_DAT_00025d38[0xb2];
  DAT_00001743 = PTR_DAT_00025d38[0xb3];
  DAT_00001744 = PTR_DAT_00025d38[0xb4];
  DAT_00001745 = PTR_DAT_00025d38[0xb5];
  DAT_00001746 = PTR_DAT_00025d38[0xb6];
  return;
}


// ===== displink_tx_24 @ fff9a17d (42 bytes)

/* 0x24 (0x9F bytes) settings */

void displink_tx_24(void)

{
  int iVar1;
  
  displink_build_24();
  iVar1 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0x9e);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x9f;
  displink_tx_start(0x9f);
  return;
}


// ===== displink_build_24 @ fff9a1a7 (298 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9a1d6) */
/* WARNING: Removing unreachable block (ram,0xfff9a1dc) */

void displink_build_24(void)

{
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
  DAT_00001741 = 0x24;
  FUN_fff98cd3();
  DAT_000017d9 = DAT_00009ace << 2 | DAT_00009b21 << 1 | DAT_00009b20;
  if (PTR_DAT_00025d38[0x437] == '\x01') {
    DAT_000017d9 = DAT_000017d9 | 4;
  }
  DAT_000017da = DAT_00009ac7;
  DAT_000017db = DAT_00009b11;
  if (PTR_DAT_00025d38[0x437] != '\0') {
    DAT_000017dc = (&DAT_fff80557)[(byte)PTR_DAT_00025d38[0x480]];
    DAT_000017dd = (&DAT_fff80542)[(byte)PTR_DAT_00025d38[0x480]];
    DAT_000017de = PTR_DAT_00025d38[0x481];
    return;
  }
  DAT_000017dc = (&DAT_fff80557)[DAT_00009bea];
  DAT_000017dd = (&DAT_fff80542)[DAT_00009b10];
  DAT_000017de = DAT_00009be9;
  return;
}


// ===== displink_tx_50 @ fff9a2d1 (42 bytes)

/* 0x50 (0xF5 bytes) */

void displink_tx_50(void)

{
  int iVar1;
  
  displink_build_50();
  iVar1 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0xf4);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xf5;
  displink_tx_start(0xf5);
  return;
}


// ===== displink_build_50 @ fff9a2fb (105 bytes)

void displink_build_50(void)

{
  char cVar1;
  
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
  DAT_00001741 = 0x50;
  FUN_fff98cd3();
  cVar1 = PTR_DAT_00025d38[0xbe];
  if (cVar1 == '\x06') {
    FUN_fff9a6f9();
    return;
  }
  if (cVar1 == '\x01') {
    FUN_fff9a42f();
    return;
  }
  if (cVar1 == '\x02') {
    FUN_fff9a4f4();
    return;
  }
  if (cVar1 == '\x03') {
    FUN_fff9a55e();
    return;
  }
  if (cVar1 == '\x04') {
    FUN_fff9a5c8();
    return;
  }
  if (cVar1 == '\x05') {
    FUN_fff9a64f();
    return;
  }
  if (cVar1 != '\0') {
    return;
  }
  FUN_fff9a364();
  return;
}


// ===== FUN_fff9a364 @ fff9a364 (203 bytes)

void FUN_fff9a364(void)

{
  if (PTR_DAT_00025d38[0xc0] == '\0') {
    DAT_000017d9 = 0;
  }
  else if (PTR_DAT_00025d38[0xc0] == '\x01') {
    DAT_000017d9 = 1;
  }
  else {
    DAT_000017d9 = 2;
  }
  DAT_000017da = PTR_DAT_00025d38[0xc1];
  DAT_000017e5 = 0x4d;
  DAT_000017e6 = 0x59;
  DAT_000017e7 = 0x20;
  DAT_000017e8 = 0x43;
  DAT_000017e9 = 0x41;
  DAT_000017ea = 0x4c;
  DAT_000017eb = 0x4c;
  FUN_fff9a7a2(&DAT_000017f9);
  FUN_fff9a804(PTR_DAT_00025d38 + 0xc2,0x1803,0xc);
  return;
}


// ===== FUN_fff9a42f @ fff9a42f (197 bytes)

void FUN_fff9a42f(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  if (PTR_DAT_00025d38[0xc0] == '\0') {
    DAT_000017d9 = 0;
  }
  else if (PTR_DAT_00025d38[0xc0] == '\x01') {
    DAT_000017d9 = 1;
  }
  else {
    DAT_000017d9 = 2;
  }
  DAT_000017da = PTR_DAT_00025d38[0xc1];
  FUN_fff9c089(&DAT_000017db,PTR_DAT_00025d38[0x43a]);
  uVar4 = 0xffffffff;
  pcVar2 = "MEMORY NAME";
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
    if (cVar1 == '\0') break;
  } while (uVar4 != 0);
  pcVar2 = &DAT_000017e5;
  pcVar3 = "MEMORY NAME";
  for (iVar5 = -2 - (uVar4 & 0xff); iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  FUN_fff9a7a2(&DAT_000017f9);
  FUN_fff9a804(PTR_DAT_00025d38 + 0xc2,0x1803,0xc);
  return;
}


// ===== FUN_fff9a4f4 @ fff9a4f4 (106 bytes)

void FUN_fff9a4f4(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  if (PTR_DAT_00025d38[0xc0] == '\0') {
    DAT_000017d9 = 0x10;
  }
  else {
    DAT_000017d9 = 0x12;
  }
  DAT_000017da = PTR_DAT_00025d38[0xc1];
  FUN_fff9a83b();
  uVar4 = 0xffffffff;
  pcVar2 = "CW TEXT";
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
    if (cVar1 == '\0') break;
  } while (uVar4 != 0);
  pcVar2 = &DAT_000017e5;
  pcVar3 = "CW TEXT";
  for (iVar5 = -2 - (uVar4 & 0xff); iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  FUN_fff9a869();
  return;
}

