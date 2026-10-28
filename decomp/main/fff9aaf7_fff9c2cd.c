// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff9aaf7 @ fff9aaf7 (51 bytes)

void FUN_fff9aaf7(void)

{
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
  DAT_00001741 = 0x40;
  FUN_fff98cd3();
  FUN_fffc98f9(&DAT_00001741,0x98);
  return;
}


// ===== FUN_fff9ab2a @ fff9ab2a (45 bytes)

void FUN_fff9ab2a(void)

{
  int iVar1;
  
  FUN_fff9ab57();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0x23f);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x240;
  FUN_fff9c5b2(0x240);
  return;
}


// ===== FUN_fff9ab57 @ fff9ab57 (413 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9aba2) */
/* WARNING: Removing unreachable block (ram,0xfff9aba8) */
/* WARNING: Removing unreachable block (ram,0xfff9abb0) */

void FUN_fff9ab57(void)

{
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
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
  
  uVar1 = FUN_fffb324c(1);
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
  
  uVar2 = FUN_fffb324c(1);
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
  
  pbVar1 = (byte *)FUN_fffb324c(1);
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


// ===== FUN_fff9b69e @ fff9b69e (42 bytes)

void FUN_fff9b69e(void)

{
  int iVar1;
  
  FUN_fff9b6c8();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0xe8);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xe9;
  FUN_fff9c5b2(0xe9);
  return;
}


// ===== FUN_fff9b6c8 @ fff9b6c8 (848 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fff9b6c8(void)

{
  char cVar1;
  bool bVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined1 uStack_4;
  byte bStack_1;
  
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
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


// ===== FUN_fff9ba18 @ fff9ba18 (136 bytes)

void FUN_fff9ba18(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_000096a0;
  puVar1 = PTR_DAT_00025d38 + 0xc2;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_000096d3;
  puVar1 = PTR_DAT_00025d38 + 0xf4;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00009706;
  puVar1 = PTR_DAT_00025d38 + 0x126;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00009739;
  puVar1 = PTR_DAT_00025d38 + 0x158;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_0000976c;
  puVar1 = PTR_DAT_00025d38 + 0x18a;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== FUN_fff9baa0 @ fff9baa0 (131 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fff9baa0(void)

{
  ram0x00001805 = DAT_000097a2;
  ram0x00001801 = DAT_0000979e;
  ram0x0000180d = DAT_000097d4;
  ram0x00001809 = DAT_000097d0;
  DAT_00001815 = DAT_00009806;
  ram0x00001811 = DAT_00009802;
  DAT_0000181d = DAT_00009838;
  DAT_00001819 = DAT_00009834;
  DAT_00001825 = DAT_0000986a;
  DAT_00001821 = DAT_00009866;
  return;
}


// ===== FUN_fff9bb23 @ fff9bb23 (45 bytes)

void FUN_fff9bb23(void)

{
  int iVar1;
  
  FUN_fff9bb50();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0x145);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x146;
  FUN_fff9c5b2(0x146);
  return;
}


// ===== FUN_fff9bb50 @ fff9bb50 (1128 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9bc1f) */
/* WARNING: Removing unreachable block (ram,0xfff9bbf2) */
/* WARNING: Removing unreachable block (ram,0xfff9bbf8) */
/* WARNING: Removing unreachable block (ram,0xfff9be3f) */

void FUN_fff9bb50(void)

{
  uint uVar1;
  bool bVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  ushort uVar9;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  byte bStack_3;
  byte bStack_1;
  
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
  DAT_00001741 = 0x41;
  FUN_fff98cd3();
  bVar4 = FUN_fffc2b2e(PTR_DAT_00025d38[0x439],PTR_DAT_00025d38[0x1db]);
  bVar5 = FUN_fff9c04a();
  if ((bVar5 == 0) || (bVar4 < bVar5)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    PTR_DAT_00025d38[0x1d8] = 0;
  }
  else {
    iVar6 = FUN_fffc2e01(bVar4,&DAT_00020880);
    if (iVar6 == 1) {
      PTR_DAT_00025d38[0x1d8] = 0;
    }
    else {
      PTR_DAT_00025d38[0x1d8] = 1;
    }
  }
  DAT_000017d9 = PTR_DAT_00025d38[0x1d8] << 7 | PTR_DAT_00025d38[0x1d9] << 6;
  DAT_000017da = PTR_DAT_00025d38[0x1da] << 4 | PTR_DAT_00025d38[0x1db];
  DAT_0001b632 = 0x9c;
  puVar7 = &DAT_000017dd;
  puVar8 = &DAT_fff804c4;
  for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = *puVar8;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  uVar9 = DAT_0001b632 + 0xf;
  DAT_0001b632 = uVar9;
  if (DAT_00009ac2 == '\x01') {
    bVar4 = FUN_fff9bfe1(bVar4);
    uVar1 = (uint)DAT_0001b632;
    *(undefined2 *)(&DAT_00001745 + uVar1) = 0x2050;
    *(undefined4 *)(&DAT_00001741 + uVar1) = 0x554f5247;
    DAT_0001b632 = DAT_0001b632 + 6;
    if (bVar4 < 6) {
      (&DAT_00001741)[DAT_0001b632] = 0x20;
      DAT_0001b632 = DAT_0001b632 + 1;
      (&DAT_00001741)[DAT_0001b632] = 0x20;
      DAT_0001b632 = DAT_0001b632 + 1;
      (&DAT_00001741)[DAT_0001b632] = bVar4 + 0x30;
      DAT_0001b632 = DAT_0001b632 + 1;
      (&DAT_00001741)[DAT_0001b632] = 0x20;
      DAT_0001b632 = DAT_0001b632 + 1;
    }
    else {
      *(undefined4 *)(&DAT_00001741 + DAT_0001b632) =
           *(undefined4 *)(&DAT_fff80370 + (uint)(byte)(bVar4 - 6) * 4);
      DAT_0001b632 = DAT_0001b632 + 4;
    }
  }
  else {
    *(undefined4 *)(&DAT_00001745 + uVar9) = 0x20202020;
    *(undefined4 *)(&DAT_00001741 + uVar9) = 0x20202020;
    *(undefined2 *)(&DAT_00001749 + uVar9) = 0x2020;
    DAT_0001b632 = DAT_0001b632 + 10;
  }
  bStack_4 = PTR_DAT_00025d38[0x439];
  for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
    DAT_00020884 = &DAT_00006150 + (uint)bStack_4 * 0x5a;
    iVar6 = FUN_fffc2e01(bStack_4,&DAT_00020880);
    if (iVar6 == 1) {
      (&DAT_00001741)[DAT_0001b632] = DAT_00020884[5] >> 7 | DAT_00020884[1] >> 6 & 2;
      DAT_0001b632 = DAT_0001b632 + 1;
      FUN_fff9c089(&DAT_00001741 + DAT_0001b632,bStack_4);
      DAT_0001b632 = DAT_0001b632 + 5;
      FUN_fff9c2f9(&DAT_00001741 + DAT_0001b632,bStack_4);
      DAT_0001b632 = DAT_0001b632 + 10;
      bStack_1 = *DAT_00020884 & 0xf;
      if (0xd < bStack_1) {
        bStack_1 = 0xe;
      }
      uVar1 = (uint)DAT_0001b632;
      *(undefined4 *)(&DAT_00001745 + DAT_0001b632) =
           *(undefined4 *)(&DAT_fff80380 + (uint)bStack_1 * 8);
      *(undefined4 *)(&DAT_00001741 + uVar1) = *(undefined4 *)(&DAT_fff8037c + (uint)bStack_1 * 8);
      pbVar3 = DAT_00020884;
      uVar9 = DAT_0001b632 + 8;
      DAT_0001b632 = uVar9;
      *(undefined4 *)(&DAT_00001749 + uVar9) = *(undefined4 *)(DAT_00020884 + 0x56);
      *(undefined4 *)(&DAT_00001745 + uVar9) = *(undefined4 *)(pbVar3 + 0x52);
      *(undefined4 *)(&DAT_00001741 + uVar9) = *(undefined4 *)(pbVar3 + 0x4e);
    }
    else {
      (&DAT_00001741)[DAT_0001b632] = 0;
      DAT_0001b632 = DAT_0001b632 + 1;
      FUN_fff9c089(&DAT_00001741 + DAT_0001b632,bStack_4);
      uVar9 = DAT_0001b632 + 5;
      DAT_0001b632 = uVar9;
      *(undefined4 *)(&DAT_00001745 + uVar9) = 0x2d2e2d2d;
      *(undefined4 *)(&DAT_00001741 + uVar9) = 0x2d2e2d2d;
      *(undefined2 *)(&DAT_00001749 + uVar9) = 0x2d2d;
      DAT_0001b632 = DAT_0001b632 + 10;
      uVar1 = (uint)DAT_0001b632;
      *(undefined4 *)(&DAT_00001745 + DAT_0001b632) = 0x2d2d2d2d;
      *(undefined4 *)(&DAT_00001741 + uVar1) = 0x2d2d2d2d;
      uVar9 = DAT_0001b632 + 8;
      DAT_0001b632 = uVar9;
      *(undefined4 *)(&DAT_00001749 + uVar9) = 0x2d2d2d2d;
      *(undefined4 *)(&DAT_00001745 + uVar9) = 0x2d2d2d2d;
      *(undefined4 *)(&DAT_00001741 + uVar9) = 0x2d2d2d2d;
    }
    DAT_0001b632 = DAT_0001b632 + 0xc;
    FUN_fff9c1a1();
    if (bStack_6 != bStack_5) {
      bStack_6 = bStack_6 + 1;
      do {
        bStack_4 = bStack_4 + 1;
        if (bStack_6 <= bStack_4) {
          bStack_4 = bStack_5;
        }
        if ((bStack_4 < 0x84) && (0x74 < bStack_4)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
      } while ((bVar2) &&
              ((iVar6 = FUN_fff9c2cd(), iVar6 != 1 || (iVar6 = FUN_fffc2e8d(bStack_4), iVar6 != 0)))
              );
    }
  }
  return;
}


// ===== FUN_fff9bfb8 @ fff9bfb8 (41 bytes)

undefined1 FUN_fff9bfb8(void)

{
  undefined1 uVar1;
  
  uVar1 = FUN_fffc2e65(DAT_00009dbd != '\0');
  uVar1 = FUN_fff9bfe1(uVar1);
  return uVar1;
}


// ===== FUN_fff9bfe1 @ fff9bfe1 (105 bytes)

char FUN_fff9bfe1(byte param_1)

{
  byte local_5;
  byte local_4;
  char local_3;
  
  if (param_1 < 0x84) {
    if (param_1 < 0x75) {
      if (param_1 < 99) {
        local_5 = 0;
        local_4 = 0;
        while ((local_4 < 5 && (local_5 = (&DAT_fff804d3)[local_4] + local_5, local_5 <= param_1)))
        {
          local_4 = local_4 + 1;
        }
        if (local_4 == 5) {
          local_4 = 0;
        }
        local_3 = local_4 + 1;
      }
      else {
        local_3 = '\x06';
      }
    }
    else {
      local_3 = '\a';
    }
  }
  else {
    local_3 = '\b';
  }
  return local_3;
}


// ===== FUN_fff9c04a @ fff9c04a (63 bytes)

undefined1 FUN_fff9c04a(void)

{
  short sVar1;
  
  sVar1 = dest_code_get();
  if ((sVar1 != 0x20b) && (sVar1 != 0x1cb9)) {
    if (sVar1 == 0x315b) {
      return 0x84;
    }
    if (sVar1 != 0x4380) {
      if (sVar1 == 0x50e2) {
        return 0x84;
      }
      if (sVar1 != 0x60e6) {
        return 0;
      }
    }
  }
  return 0x75;
}


// ===== FUN_fff9c089 @ fff9c089 (217 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9c0ec) */
/* WARNING: Removing unreachable block (ram,0xfff9c0a3) */
/* WARNING: Removing unreachable block (ram,0xfff9c0f7) */
/* WARNING: Removing unreachable block (ram,0xfff9c0cf) */
/* WARNING: Removing unreachable block (ram,0xfff9c12f) */
/* WARNING: Removing unreachable block (ram,0xfff9c15f) */

undefined4 * FUN_fff9c089(undefined4 *param_1,byte param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  
  if (0x83 < param_2) {
    *(undefined1 *)(param_1 + 1) = 0x20;
    *param_1 = 0x20474d45;
    return param_1;
  }
  if (param_2 < 0x75) {
    if (0x62 < param_2) {
      *(undefined1 *)((int)param_1 + 2) = 0x50;
      *(undefined2 *)param_1 = 0x2d4d;
      if ((param_2 + 0x9d & 1) == 0) {
        *(undefined1 *)(param_1 + 1) = 0x4c;
      }
      else {
        *(undefined1 *)(param_1 + 1) = 0x55;
      }
      puVar2 = (undefined4 *)((byte)(((byte)(param_2 + 0x9d) >> 1) + 1) + 0x30);
      *(char *)((int)param_1 + 3) = (char)puVar2;
      return puVar2;
    }
    *(undefined2 *)param_1 = 0x2d4d;
    if ((byte)(param_2 + 1) < 10) {
      *(undefined1 *)((int)param_1 + 2) = 0x30;
      *(byte *)((int)param_1 + 3) = param_2 + 0x31;
    }
    else {
      FUN_fff9c6f0(param_2 + 1,(undefined2 *)((int)param_1 + 2));
    }
    *(undefined1 *)(param_1 + 1) = 0x20;
    return param_1;
  }
  *(undefined2 *)param_1 = 0x2d35;
  bVar1 = FUN_fff9c162(param_2);
  if (bVar1 < 10) {
    *(undefined1 *)((int)param_1 + 2) = 0x30;
    puVar2 = (undefined4 *)nib2hex(bVar1);
    *(char *)((int)param_1 + 3) = (char)puVar2;
    return puVar2;
  }
  if (bVar1 < 0x14) {
    *(undefined1 *)((int)param_1 + 2) = 0x31;
    puVar2 = (undefined4 *)nib2hex(*(undefined1 *)(bVar1 - 10));
    *(char *)((int)param_1 + 3) = (char)puVar2;
    return puVar2;
  }
  *(undefined1 *)((int)param_1 + 2) = 0x2a;
  *(undefined1 *)((int)param_1 + 3) = 0x2a;
  return param_1;
}


// ===== FUN_fff9c162 @ fff9c162 (63 bytes)

char FUN_fff9c162(char param_1)

{
  int iVar1;
  byte local_4;
  char local_3;
  
  local_3 = '\0';
  local_4 = 0;
  while( true ) {
    if (0xe < local_4) {
      return local_3;
    }
    iVar1 = FUN_fffc2e8d(*(undefined1 *)(local_4 + 0x75));
    if (iVar1 == 0) {
      local_3 = local_3 + '\x01';
    }
    if (param_1 == (byte)(local_4 + 0x75)) break;
    local_4 = local_4 + 1;
  }
  return local_3;
}


// ===== FUN_fff9c1a1 @ fff9c1a1 (241 bytes)

void FUN_fff9c1a1(char *param_1,char *param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte bStack_a;
  
  if ((DAT_00009ac2 == '\x01') && (PTR_DAT_00025d38[0x97] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    *param_1 = '\0';
    iVar3 = FUN_fff9c292();
    if ((iVar3 == 1) && (DAT_00009af4 == '\x01')) {
      *param_2 = -0x7c;
      return;
    }
    iVar3 = FUN_fff9c2cd();
    if (iVar3 == 1) {
      *param_2 = -0x7d;
      return;
    }
    *param_2 = 't';
    return;
  }
  bVar2 = FUN_fff9bfb8();
  if (bVar2 == 6) {
    *param_1 = 'c';
    *param_2 = 't';
    return;
  }
  if (bVar2 < 8) {
    if (bVar2 < 7) {
      *param_1 = '\0';
      *param_2 = '\x12';
      for (bStack_a = 0; (bStack_a < 5 && (bVar2 != (byte)(bStack_a + 1))); bStack_a = bStack_a + 1)
      {
        *param_1 = (&DAT_fff804d3)[bStack_a] + *param_1;
        *param_2 = *param_2 + (&DAT_fff804d4)[bStack_a];
      }
      return;
    }
    *param_1 = 'u';
    *param_2 = -0x7d;
    return;
  }
  *param_1 = -0x7c;
  *param_2 = -0x7c;
  return;
}


// ===== FUN_fff9c292 @ fff9c292 (59 bytes)

undefined1 FUN_fff9c292(void)

{
  undefined *puVar1;
  undefined1 local_2;
  
  local_2 = 1;
  puVar1 = (undefined *)dest_code_get();
  if ((((puVar1 == &DAT_0000306f) || (puVar1 == &DAT_0000a4c5)) || (puVar1 == &DAT_0000a983)) ||
     (((puVar1 == &DAT_0000b5a7 || (puVar1 == &DAT_0000d32d)) || (puVar1 == &DAT_0000d950)))) {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fff9c2cd @ fff9c2cd (44 bytes)

undefined1 FUN_fff9c2cd(void)

{
  undefined *puVar1;
  undefined1 local_2;
  
  local_2 = 0;
  puVar1 = (undefined *)dest_code_get();
  if ((((puVar1 == &DAT_0000315b) || (puVar1 == &DAT_000050e2)) || (puVar1 == &DAT_0000a4c5)) ||
     (puVar1 == &DAT_0000d950)) {
    local_2 = 1;
  }
  return local_2;
}

