// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
    if (cVar1 == '\0') break;
  } while (uVar4 != 0);
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
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
    if (cVar1 == '\0') break;
  } while (uVar4 != 0);
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
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
    if (cVar1 == '\0') break;
  } while (uVar4 != 0);
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
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    uVar4 = uVar4 - 1;
    if (cVar1 == '\0') break;
  } while (uVar4 != 0);
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


// ===== displink_tx_3F @ fff9a89b (72 bytes)

/* 0x3F (5 bytes): +0x92 */

void displink_tx_3F(void)

{
  PTR_DAT_00025d38[0x91] = 0;
  DAT_00001456 = 0x3f;
  DAT_00001457 = PTR_DAT_00025d38[0x92];
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_3A @ fff9a8e3 (66 bytes)

/* 0x3A (0xA2 bytes) */

void displink_tx_3A(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (PTR_DAT_00025d38[0x3f8] == '\0') {
    return;
  }
  PTR_DAT_00025d38[0x3f8] = 0;
  displink_build_3A();
  puVar2 = &DAT_00001741;
  puVar1 = &DAT_00001456;
  for (iVar3 = 0xa1; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  DAT_0001b628 = 0xa2;
  displink_tx_start(0xa2);
  return;
}


// ===== displink_build_3A @ fff9a925 (392 bytes)

void displink_build_3A(void)

{
  char cVar1;
  
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
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


// ===== displink_tx_40 @ fff9aaad (74 bytes)

/* 0x40 (0x1FB bytes), rate-limited 100 units (timer 0x29) */

void displink_tx_40(void)

{
  int iVar1;
  
  displink_build_40();
  iVar1 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0x1fa);
  if (iVar1 == 0) {
    if (PTR_DAT_00025d38[0x47b] == '\0') {
      return;
    }
    PTR_DAT_00025d38[0x47b] = 0;
  }
  DAT_0001b628 = 0x1fb;
  displink_tx_start(0x1fb);
  return;
}


// ===== displink_build_40 @ fff9aaf7 (51 bytes)

void displink_build_40(void)

{
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
  DAT_00001741 = 0x40;
  FUN_fff98cd3();
  menu_page_serialize(&DAT_00001741,0x98);
  return;
}


// ===== displink_tx_37 @ fff9ab2a (45 bytes)

/* 0x37 (0x240 bytes) */

void displink_tx_37(void)

{
  int iVar1;
  
  displink_build_37();
  iVar1 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0x23f);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x240;
  displink_tx_start(0x240);
  return;
}


// ===== displink_build_37 @ fff9ab57 (413 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9aba2) */
/* WARNING: Removing unreachable block (ram,0xfff9aba8) */
/* WARNING: Removing unreachable block (ram,0xfff9abb0) */

void displink_build_37(void)

{
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
  DAT_00001741 = 0x37;
  FUN_fff98cd3();
  PTR_DAT_00025d38[0x1c4] = 1;
  PTR_DAT_00025d38[0x1c6] = 0;
  DAT_000017d9 = PTR_DAT_00025d38[0x1c4] << 7 | PTR_DAT_00025d38[0x1c5] << 6 |
                 PTR_DAT_00025d38[0x1c6] << 5;
  DAT_000017da = DAT_00009c08;
  DAT_000017db = 0;
  FUN_fff9acf4(0x9b);
  FUN_fff9ad39(0xa5);
  FUN_fff9ad7e(0xaf);
  FUN_fff9adde(0xb9);
  FUN_fff9ae31(0xc3);
  FUN_fff9ae76(0xcd);
  FUN_fff9aebb(0xd7);
  FUN_fff9aefb(0xe1);
  FUN_fff9af40(0xeb);
  FUN_fff9afb2(0xf5);
  FUN_fff9aff7(0xff);
  FUN_fff9b03c(0x109);
  FUN_fff9b081(0x113);
  FUN_fff9b0c6(0x11d);
  FUN_fff9b10b(0x127);
  FUN_fff9b150(0x131);
  FUN_fff9b195(0x13b);
  FUN_fff9b212(0x145);
  FUN_fff9b2a1(0x14f);
  FUN_fff9b2e7(0x159);
  FUN_fff9b32d(0x163);
  FUN_fff9b373(0x16d);
  FUN_fff9b3ce(0x177);
  FUN_fff9b41e(0x181);
  FUN_fff9b45f(0x18b);
  FUN_fff9b65d(0x195);
  FUN_fff9b48c(0x19f);
  FUN_fff9b4d2(0x1a9);
  FUN_fff9b518(0x1b3);
  FUN_fff9b559(0x1bd);
  FUN_fff9b59a(0x1c7);
  FUN_fff9b5db(0x1d1);
  FUN_fff9b61c(0x1db);
  FUN_fff9b65d(0x1e5);
  FUN_fff9b65d(0x1ef);
  FUN_fff9b65d(0x1f9);
  FUN_fff9b65d(0x203);
  FUN_fff9b65d(0x20d);
  FUN_fff9b65d(0x217);
  FUN_fff9b65d(0x221);
  FUN_fff9b65d(0x22b);
  FUN_fff9b65d(0x235);
  return;
}


// ===== FUN_fff9acf4 @ fff9acf4 (69 bytes)

void FUN_fff9acf4(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99475(param_1);
  return;
}


// ===== FUN_fff9ad39 @ fff9ad39 (69 bytes)

void FUN_fff9ad39(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 1;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff9959f(param_1);
  return;
}


// ===== FUN_fff9ad7e @ fff9ad7e (96 bytes)

void FUN_fff9ad7e(ushort param_1)

{
  int iVar1;
  
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 2;
  iVar1 = (uint)(DAT_00009be7 == '\x01') * 9;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = *(undefined4 *)(&DAT_fff80351 + iVar1);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = *(undefined4 *)(&DAT_fff8034d + iVar1);
  return;
}


// ===== FUN_fff9adde @ fff9adde (83 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9ae15) */

void FUN_fff9adde(ushort param_1)

{
  uint uVar1;
  
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 3;
  uVar1 = (uint)DAT_00009be8;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(&DAT_fff80470 + uVar1 * 8);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(&DAT_fff8046c + uVar1 * 8);
  return;
}


// ===== FUN_fff9ae31 @ fff9ae31 (69 bytes)

void FUN_fff9ae31(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 4;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99e15(param_1);
  return;
}


// ===== FUN_fff9ae76 @ fff9ae76 (69 bytes)

void FUN_fff9ae76(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 5;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff9a00f(param_1);
  return;
}


// ===== FUN_fff9aebb @ fff9aebb (64 bytes)

void FUN_fff9aebb(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 6;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9aefb @ fff9aefb (69 bytes)

void FUN_fff9aefb(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 7;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99837(param_1);
  return;
}


// ===== FUN_fff9af40 @ fff9af40 (114 bytes)

void FUN_fff9af40(ushort param_1)

{
  int iVar1;
  byte bStack_4;
  undefined1 uStack_3;
  
  iVar1 = FUN_fffc3d75();
  if (iVar1 == 0) {
    uStack_3 = 0x80;
    bStack_4 = 0;
  }
  else {
    uStack_3 = 0;
    if (DAT_00009bf0 == '\0') {
      bStack_4 = 0;
    }
    else {
      bStack_4 = 1;
    }
  }
  (&DAT_00001741)[param_1] = uStack_3;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 8;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(&DAT_fff80351 + (uint)bStack_4 * 9);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(&DAT_fff8034d + (uint)bStack_4 * 9);
  return;
}


// ===== FUN_fff9afb2 @ fff9afb2 (69 bytes)

void FUN_fff9afb2(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 9;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff997df(param_1);
  return;
}


// ===== FUN_fff9aff7 @ fff9aff7 (69 bytes)

void FUN_fff9aff7(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 10;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99a8a(param_1);
  return;
}


// ===== FUN_fff9b03c @ fff9b03c (69 bytes)

void FUN_fff9b03c(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xb;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff996e2(param_1);
  return;
}


// ===== FUN_fff9b081 @ fff9b081 (69 bytes)

void FUN_fff9b081(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xc;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99717(param_1);
  return;
}


// ===== FUN_fff9b0c6 @ fff9b0c6 (69 bytes)

void FUN_fff9b0c6(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xd;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff9978c(param_1);
  return;
}


// ===== FUN_fff9b10b @ fff9b10b (69 bytes)

void FUN_fff9b10b(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xe;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff995cc(param_1);
  return;
}


// ===== FUN_fff9b150 @ fff9b150 (69 bytes)

void FUN_fff9b150(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xf;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff9960e(param_1);
  return;
}


// ===== FUN_fff9b195 @ fff9b195 (125 bytes)

void FUN_fff9b195(ushort param_1)

{
  undefined4 uVar1;
  int iVar2;
  byte bStack_a;
  undefined1 uStack_9;
  
  uVar1 = vfo_rec_ptr(1);
  iVar2 = FUN_fffc3e3c(uVar1);
  if (iVar2 == 0) {
    uStack_9 = 0x80;
    bStack_a = 0;
  }
  else {
    uStack_9 = 0;
    if (DAT_00009c02 == '\0') {
      bStack_a = 0;
    }
    else {
      bStack_a = 1;
    }
  }
  (&DAT_00001741)[param_1] = uStack_9;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x10;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(&DAT_fff80351 + (uint)bStack_a * 9);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(&DAT_fff8034d + (uint)bStack_a * 9);
  return;
}


// ===== FUN_fff9b212 @ fff9b212 (143 bytes)

void FUN_fff9b212(ushort param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  byte bStack_a;
  undefined1 uStack_9;
  
  uVar2 = vfo_rec_ptr(1);
  iVar3 = FUN_fffc3f1b(uVar2);
  if ((iVar3 == 1) || (iVar3 = FUN_fffc3e3c(uVar2), iVar3 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uStack_9 = 0;
    iVar3 = FUN_fff99dbf(uVar2);
    if (iVar3 == 0) {
      bStack_a = 0;
    }
    else {
      bStack_a = 1;
    }
  }
  else {
    uStack_9 = 0x80;
    bStack_a = 0;
  }
  (&DAT_00001741)[param_1] = uStack_9;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x11;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(&DAT_fff80351 + (uint)bStack_a * 9);
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) =
       *(undefined4 *)(&DAT_fff8034d + (uint)bStack_a * 9);
  return;
}


// ===== FUN_fff9b2a1 @ fff9b2a1 (70 bytes)

void FUN_fff9b2a1(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x12;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff998e2(param_1);
  return;
}


// ===== FUN_fff9b2e7 @ fff9b2e7 (70 bytes)

void FUN_fff9b2e7(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x13;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff9992a(param_1);
  return;
}


// ===== FUN_fff9b32d @ fff9b32d (70 bytes)

void FUN_fff9b32d(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x14;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99989(param_1);
  return;
}


// ===== FUN_fff9b373 @ fff9b373 (91 bytes)

void FUN_fff9b373(ushort param_1)

{
  byte *pbVar1;
  ushort local_2;
  
  pbVar1 = (byte *)vfo_rec_ptr(1);
  if ((*pbVar1 & 0xf) - 8 < 7) {
    (&DAT_00001741)[param_1] = 0x80;
  }
  else {
    (&DAT_00001741)[param_1] = 0;
  }
  local_2 = param_1 + 1;
  (&DAT_00001741)[local_2] = 0x16;
  return;
}


// ===== FUN_fff9b3ce @ fff9b3ce (80 bytes)

void FUN_fff9b3ce(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  if (PTR_DAT_00025d38[0x92] != '\0') {
    (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x35;
    return;
  }
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x17;
  return;
}


// ===== FUN_fff9b41e @ fff9b41e (65 bytes)

void FUN_fff9b41e(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x18;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b45f @ fff9b45f (45 bytes)

void FUN_fff9b45f(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x2d;
  return;
}


// ===== FUN_fff9b48c @ fff9b48c (70 bytes)

void FUN_fff9b48c(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x15;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff999e3(param_1);
  return;
}


// ===== FUN_fff9b4d2 @ fff9b4d2 (70 bytes)

void FUN_fff9b4d2(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x3a;
  param_1 = param_1 + 2;
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  FUN_fff99a29(param_1);
  return;
}


// ===== FUN_fff9b518 @ fff9b518 (65 bytes)

void FUN_fff9b518(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x30;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b559 @ fff9b559 (65 bytes)

void FUN_fff9b559(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x31;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b59a @ fff9b59a (65 bytes)

void FUN_fff9b59a(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x32;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b5db @ fff9b5db (65 bytes)

void FUN_fff9b5db(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x33;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b61c @ fff9b61c (65 bytes)

void FUN_fff9b61c(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0x34;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== FUN_fff9b65d @ fff9b65d (65 bytes)

void FUN_fff9b65d(ushort param_1)

{
  (&DAT_00001741)[param_1] = 0;
  (&DAT_00001741)[(ushort)(param_1 + 1)] = 0xff;
  *(undefined4 *)(&DAT_00001745 + (ushort)(param_1 + 2)) = 0x20202020;
  *(undefined4 *)(&DAT_00001741 + (ushort)(param_1 + 2)) = 0x20202020;
  return;
}


// ===== displink_tx_39 @ fff9b69e (42 bytes)

/* 0x39 (0xE9 bytes) */

void displink_tx_39(void)

{
  int iVar1;
  
  displink_build_39();
  iVar1 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0xe8);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xe9;
  displink_tx_start(0xe9);
  return;
}


// ===== displink_build_39 @ fff9b6c8 (848 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void displink_build_39(void)

{
  char cVar1;
  bool bVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined1 uStack_4;
  byte bStack_1;
  
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
  DAT_00001741 = 0x39;
  FUN_fff98cd3();
  bStack_1 = PTR_DAT_00025d38[0x1c7];
  puVar4 = &DAT_fff802c0 + (uint)bStack_1 * 0x19;
  puVar3 = &DAT_000017d9;
  for (iVar5 = 0x19; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  if (PTR_DAT_00025d38[0x1d0] == '\x01') {
    bStack_1 = bStack_1 | 8;
  }
  if (PTR_DAT_00025d38[0x1cf] == '\x01') {
    bStack_1 = bStack_1 | 4;
  }
  if (PTR_DAT_00025d38[0x78] == '\x01') {
    bStack_1 = bStack_1 | 0x10;
  }
  else if (PTR_DAT_00025d38[0x78] == '\x02') {
    bStack_1 = bStack_1 | 0x20;
  }
  DAT_000017f2 = bStack_1;
  DAT_000017f3 = FUN_fffe5783();
  bStack_1 = 0;
  if ((PTR_DAT_00025d38[0x1d1] == '\x01') && ((byte)PTR_DAT_00025d38[0x1ce] < 8)) {
    bStack_1 = (byte)(1 << ((byte)PTR_DAT_00025d38[0x1ce] & 0x1f));
  }
  DAT_000017f4 = bStack_1;
  bStack_1 = 0;
  if (PTR_DAT_00025d38[0x417] == '\0') {
    if ((PTR_DAT_00025d38[0x78] == '\x01') || (PTR_DAT_00025d38[0x78] == '\x02')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_DAT_00025d38[0x1c9] == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_DAT_00025d38[0x1cc] == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_DAT_00025d38[0x1cd] == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_DAT_00025d38[0x1d0] == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_DAT_00025d38[0x1cf] == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bStack_1 = PTR_DAT_00025d38[0x1c8];
    }
  }
  DAT_000017f5 = bStack_1;
  DAT_000017f6 = 0;
  bStack_1 = DAT_00009aad == '\x01';
  if (DAT_00009aae == '\x01') {
    bStack_1 = bStack_1 | 2;
  }
  if (DAT_00009aaf == '\x01') {
    bStack_1 = bStack_1 | 4;
  }
  if (DAT_00009ab0 == '\x01') {
    bStack_1 = bStack_1 | 8;
  }
  if (DAT_00009ab1 == '\x01') {
    bStack_1 = bStack_1 | 0x10;
  }
  DAT_000017f7 = bStack_1;
  DAT_000017f8 = DAT_00009dc1;
  DAT_000017f9 = DAT_00009dc2;
  DAT_000017fa = 0;
  DAT_000017fb = (undefined1)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x1d6) >> 8);
  uStack_4 = (undefined1)*(undefined2 *)(PTR_DAT_00025d38 + 0x1d6);
  DAT_000017fc._0_1_ = uStack_4;
  DAT_000017fc._1_1_ = 0;
  DAT_000017fc._2_1_ = 0;
  DAT_000017fc._3_1_ = 0;
  DAT_00001800._0_1_ = 0;
  cVar1 = PTR_DAT_00025d38[0x1c7];
  if (cVar1 != '\0') {
    if (cVar1 == '\x02') {
      FUN_fff9baa0();
    }
    else if (cVar1 == '\x01') {
      FUN_fff9ba18();
    }
    ram0x00001805 = *(undefined4 *)(PTR_DAT_00025d38 + 0xc6);
    ram0x00001801 = *(undefined4 *)(PTR_DAT_00025d38 + 0xc2);
    ram0x0000180d = *(undefined4 *)(PTR_DAT_00025d38 + 0xf8);
    ram0x00001809 = *(undefined4 *)(PTR_DAT_00025d38 + 0xf4);
    DAT_00001815 = *(undefined4 *)(PTR_DAT_00025d38 + 0x12a);
    ram0x00001811 = *(undefined4 *)(PTR_DAT_00025d38 + 0x126);
    DAT_0000181d = *(undefined4 *)(PTR_DAT_00025d38 + 0x15c);
    DAT_00001819 = *(undefined4 *)(PTR_DAT_00025d38 + 0x158);
    DAT_00001825 = *(undefined4 *)(PTR_DAT_00025d38 + 0x18e);
    DAT_00001821 = *(undefined4 *)(PTR_DAT_00025d38 + 0x18a);
    return;
  }
  return;
}

