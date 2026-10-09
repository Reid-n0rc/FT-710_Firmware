// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
  FUN_fffb3196(1);
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
  
  uVar1 = FUN_fffb324c(1);
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


// ===== FUN_fff9a06e @ fff9a06e (94 bytes)

void FUN_fff9a06e(undefined1 param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  FUN_fff9c655(0x98,&DAT_000016a0);
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


// ===== FUN_fff9a0cc @ fff9a0cc (52 bytes)

void FUN_fff9a0cc(void)

{
  int iVar1;
  
  PTR_DAT_00025d38[0x8d] = 0;
  FUN_fff9a100();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,8);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 9;
  FUN_fff9c5b2(9);
  return;
}


// ===== FUN_fff9a100 @ fff9a100 (125 bytes)

void FUN_fff9a100(void)

{
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
  DAT_00001741 = 0x65;
  DAT_00001742 = PTR_DAT_00025d38[0xb2];
  DAT_00001743 = PTR_DAT_00025d38[0xb3];
  DAT_00001744 = PTR_DAT_00025d38[0xb4];
  DAT_00001745 = PTR_DAT_00025d38[0xb5];
  DAT_00001746 = PTR_DAT_00025d38[0xb6];
  return;
}


// ===== FUN_fff9a17d @ fff9a17d (42 bytes)

void FUN_fff9a17d(void)

{
  int iVar1;
  
  FUN_fff9a1a7();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0x9e);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x9f;
  FUN_fff9c5b2(0x9f);
  return;
}


// ===== FUN_fff9a1a7 @ fff9a1a7 (298 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9a1d6) */
/* WARNING: Removing unreachable block (ram,0xfff9a1dc) */

void FUN_fff9a1a7(void)

{
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
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


// ===== FUN_fff9a2d1 @ fff9a2d1 (42 bytes)

void FUN_fff9a2d1(void)

{
  int iVar1;
  
  FUN_fff9a2fb();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0xf4);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xf5;
  FUN_fff9c5b2(0xf5);
  return;
}


// ===== FUN_fff9a2fb @ fff9a2fb (105 bytes)

void FUN_fff9a2fb(void)

{
  char cVar1;
  
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
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
    if (uVar4 == 0) break;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
  } while (cVar1 != '\0');
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
    if (uVar4 == 0) break;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
  } while (cVar1 != '\0');
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


// ===== FUN_fff9a55e @ fff9a55e (106 bytes)

void FUN_fff9a55e(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  if (PTR_DAT_00025d38[0xc0] == '\0') {
    DAT_000017d9 = 0x30;
  }
  else {
    DAT_000017d9 = 0x32;
  }
  DAT_000017da = PTR_DAT_00025d38[0xc1];
  FUN_fff9a83b();
  uVar4 = 0xffffffff;
  pcVar2 = "RTTY TEXT";
  do {
    if (uVar4 == 0) break;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
  } while (cVar1 != '\0');
  pcVar2 = &DAT_000017e5;
  pcVar3 = "RTTY TEXT";
  for (iVar5 = -2 - (uVar4 & 0xff); iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  FUN_fff9a869();
  return;
}


// ===== FUN_fff9a5c8 @ fff9a5c8 (135 bytes)

void FUN_fff9a5c8(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  if (PTR_DAT_00025d38[0xc0] == '\0') {
    DAT_000017d9 = 0x20;
  }
  else if (PTR_DAT_00025d38[0xc0] == '\x01') {
    DAT_000017d9 = 0x21;
  }
  else {
    DAT_000017d9 = 0x22;
  }
  DAT_000017da = PTR_DAT_00025d38[0xc1];
  FUN_fff9a83b();
  uVar4 = 0xffffffff;
  pcVar2 = "PSK TEXT";
  do {
    if (uVar4 == 0) break;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
  } while (cVar1 != '\0');
  pcVar2 = &DAT_000017e5;
  pcVar3 = "PSK TEXT";
  for (iVar5 = -2 - (uVar4 & 0xff); iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  FUN_fff9a869();
  return;
}


// ===== FUN_fff9a64f @ fff9a64f (170 bytes)

void FUN_fff9a64f(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  if (PTR_DAT_00025d38[0xc0] == '\0') {
    DAT_000017d9 = 0x40;
  }
  else if (PTR_DAT_00025d38[0xc0] == '\x01') {
    DAT_000017d9 = 0x41;
  }
  else {
    DAT_000017d9 = 0x42;
  }
  DAT_000017da = PTR_DAT_00025d38[0xc1];
  uVar4 = 0xffffffff;
  pcVar2 = "FILE NAME";
  do {
    if (uVar4 == 0) break;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
  } while (cVar1 != '\0');
  pcVar2 = &DAT_000017e5;
  pcVar3 = "FILE NAME";
  for (iVar5 = -2 - (uVar4 & 0xff); iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  FUN_fff9a7a2(&DAT_000017f9);
  FUN_fff9a804(PTR_DAT_00025d38 + 0xc2,0x1803,0x14);
  return;
}


// ===== FUN_fff9a6f9 @ fff9a6f9 (169 bytes)

void FUN_fff9a6f9(void)

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
  uVar4 = 0xffffffff;
  pcVar2 = "PRESET NAME";
  do {
    if (uVar4 == 0) break;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
  } while (cVar1 != '\0');
  pcVar2 = &DAT_000017e5;
  pcVar3 = "PRESET NAME";
  for (iVar5 = -2 - (uVar4 & 0xff); iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  FUN_fff9a7a2(&DAT_000017f9);
  FUN_fff9a804(PTR_DAT_00025d38 + 0xc2,0x1803,0xc);
  return;
}


// ===== FUN_fff9a7a2 @ fff9a7a2 (98 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9a7b3) */
/* WARNING: Removing unreachable block (ram,0xfff9a7c8) */

void FUN_fff9a7a2(undefined1 *param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = PTR_DAT_00025d38[0xc1];
  bVar2 = PTR_DAT_00025d38[0xc1];
  *param_1 = 0x43;
  param_1[1] = 0x68;
  param_1[2] = 0x61;
  param_1[3] = 0x72;
  param_1[4] = 0x20;
  param_1[5] = 0x23;
  param_1[6] = (byte)((bVar1 + 1) / 10) | 0x30;
  param_1[7] = (char)(bVar2 + 1) + (char)((bVar2 + 1) / 10) * -10 | 0x30;
  return;
}


// ===== FUN_fff9a804 @ fff9a804 (55 bytes)

void FUN_fff9a804(undefined1 *param_1,undefined1 *param_2,byte param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = param_2;
  for (uVar2 = (uint)param_3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  if (PTR_DAT_00025d38[0x1bc] != '\0') {
    return;
  }
  param_2[(byte)PTR_DAT_00025d38[0xc1]] = 0xff;
  return;
}


// ===== FUN_fff9a83b @ fff9a83b (46 bytes)

void FUN_fff9a83b(void)

{
  DAT_000017db = 99;
  DAT_000017dc = 0x68;
  DAT_000017dd = PTR_DAT_00025d38[0xbf] + 1 | 0x30;
  return;
}


// ===== FUN_fff9a869 @ fff9a869 (50 bytes)

void FUN_fff9a869(void)

{
  FUN_fff9a7a2(&DAT_000017f9);
  FUN_fff9a804(PTR_DAT_00025d38 + (uint)(byte)PTR_DAT_00025d38[0xbf] * 0x32 + 0xc2,0x1803,0x32);
  return;
}


// ===== FUN_fff9a89b @ fff9a89b (72 bytes)

void FUN_fff9a89b(void)

{
  PTR_DAT_00025d38[0x91] = 0;
  DAT_00001456 = 0x3f;
  DAT_00001457 = PTR_DAT_00025d38[0x92];
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  FUN_fff9c5b2(5);
  return;
}


// ===== FUN_fff9a8e3 @ fff9a8e3 (66 bytes)

void FUN_fff9a8e3(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (PTR_DAT_00025d38[0x3f8] == '\0') {
    return;
  }
  PTR_DAT_00025d38[0x3f8] = 0;
  FUN_fff9a925();
  puVar2 = &DAT_00001741;
  puVar1 = &DAT_00001456;
  for (iVar3 = 0xa1; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  DAT_0001b628 = 0xa2;
  FUN_fff9c5b2(0xa2);
  return;
}


// ===== FUN_fff9a925 @ fff9a925 (392 bytes)

void FUN_fff9a925(void)

{
  char cVar1;
  
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
  DAT_00001741 = 0x3a;
  FUN_fff98cd3();
  DAT_000017d9 = PTR_DAT_00025d38[0x3f9];
  DAT_000017da = 0;
  DAT_000017db = 0;
  cVar1 = PTR_DAT_00025d38[0x3f9];
  if (cVar1 == '\x04') {
    DAT_000017dc = PTR_DAT_00025d38[0x3fe] & 1;
    DAT_000017dd = DAT_00009dc1;
    return;
  }
  if (cVar1 == '\x01') {
    DAT_000017dc = (char)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x3fa) >> 8);
    DAT_000017dd = (char)*(undefined2 *)(PTR_DAT_00025d38 + 0x3fa);
    DAT_000017de = PTR_DAT_00025d38[0x3fc];
    DAT_000017df = 0;
    return;
  }
  if (cVar1 == '\x02') {
    DAT_000017dc = (char)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x3fa) >> 8);
    DAT_000017dd = (char)*(undefined2 *)(PTR_DAT_00025d38 + 0x3fa);
    DAT_000017de = PTR_DAT_00025d38[0x3fc];
    DAT_000017df = PTR_DAT_00025d38[0x3fd];
    return;
  }
  if (cVar1 == '\x03') {
    DAT_000017dc = (char)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x3fa) >> 8);
    DAT_000017dd = (char)*(undefined2 *)(PTR_DAT_00025d38 + 0x3fa);
    DAT_000017de = PTR_DAT_00025d38[0x3fc];
    return;
  }
  if (cVar1 != '\0') {
    return;
  }
  DAT_000017dc = DAT_00009dc1;
  return;
}


// ===== FUN_fff9aaad @ fff9aaad (74 bytes)

void FUN_fff9aaad(void)

{
  int iVar1;
  
  FUN_fff9aaf7();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0x1fa);
  if (iVar1 == 0) {
    if (PTR_DAT_00025d38[0x47b] == '\0') {
      return;
    }
    PTR_DAT_00025d38[0x47b] = 0;
  }
  DAT_0001b628 = 0x1fb;
  FUN_fff9c5b2(0x1fb);
  return;
}

