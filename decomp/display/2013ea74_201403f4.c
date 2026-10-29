// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2013ea74 @ 2013ea74 (332 bytes)

void FUN_2013ea74(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  fs_memset(iVar1 + 1,0,0x200);
  fs_memcpy(*param_1 + 1,DAT_20808b4c,4);
  fs_memcpy(*param_1 + 0x1e5,DAT_20808b50,4);
  FUN_2014d918(*param_1 + 0x1e9,0xffffffff);
  FUN_2014d918(*param_1 + 0x1ed,0xffffffff);
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
  iVar2 = *(int *)(iVar1 + 0x2d0);
  iVar3 = sd_write_sectors(iVar2 + 1,*param_1 + 1,1,param_1);
  if ((iVar3 == 0) && (iVar2 = sd_write_sectors(iVar2 + 7,*param_1 + 1,1,param_1), iVar2 == 0)) {
    fs_memset(*param_1 + 1,0,0x200);
    *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
    *(undefined1 *)(*param_1 + 0x200) = 0xaa;
    iVar1 = *(int *)(iVar1 + 0x2d0);
    iVar2 = sd_write_sectors(iVar1 + 2,*param_1 + 1,1,param_1);
    if (iVar2 == 0) {
      sd_write_sectors(iVar1 + 8,*param_1 + 1,1,param_1);
      return;
    }
  }
  return;
}


// ===== FUN_2013ebc0 @ 2013ebc0 (112 bytes)

uint FUN_2013ebc0(void)

{
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  
  FUN_2014e1dc(&local_28);
  return local_14 + 0x76cU & 0xffff | local_24 & 0xffff | (local_20 & 0xff) << 8 |
         ((local_28 & 0xff) * 0x100 + (local_1c | (local_18 + 1) * 0x100 & 0xff00U)) * 0x10000;
}


// ===== FUN_2013ec30 @ 2013ec30 (564 bytes)

void FUN_2013ec30(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *param_1;
  fs_memset(iVar1 + 1,0,0x200);
  if (*(char *)(iVar1 + 0x2dc) != ' ') {
    fs_memcpy(*param_1 + 1,&DAT_2042025b,0x3e);
    FUN_2014d8ec(*param_1 + 0xc,*(undefined2 *)(iVar1 + 0x2da));
    *(undefined1 *)(*param_1 + 0xe) = *(undefined1 *)(iVar1 + 0x2d8);
    FUN_2014d8ec(*param_1 + 0xf,*(undefined2 *)(iVar1 + 0x2e4));
    FUN_2014d8ec(*param_1 + 0x17,*(undefined2 *)(iVar1 + 0x2e0));
    FUN_2014d8ec(*param_1 + 0x19,*(undefined2 *)(iVar1 + 0x2c8));
    FUN_2014d8ec(*param_1 + 0x1b,*(undefined2 *)(iVar1 + 0x2ca));
    FUN_2014d918(*param_1 + 0x1d,*(undefined4 *)(iVar1 + 0x2d0));
    if (*(uint *)(iVar1 + 0x2d4) < 0x10000) {
      FUN_2014d8ec(*param_1 + 0x14,*(uint *)(iVar1 + 0x2d4) & 0xffff);
    }
    else {
      FUN_2014d918(*param_1 + 0x21);
    }
    uVar2 = FUN_2013ebc0();
    FUN_2014d918(*param_1 + 0x28,uVar2);
    if (*(char *)(iVar1 + 0x2dc) == '\f') {
      *(undefined1 *)(*param_1 + 0x3b) = 0x32;
    }
    *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
    *(undefined1 *)(*param_1 + 0x200) = 0xaa;
    sd_write_sectors(*(int *)(iVar1 + 0x2d0),*param_1 + 1,1,param_1);
    return;
  }
  fs_memcpy(*param_1 + 1,&DAT_20420299,0x5a);
  FUN_2014d8ec(*param_1 + 0xc,*(undefined2 *)(iVar1 + 0x2da));
  *(undefined1 *)(*param_1 + 0xe) = *(undefined1 *)(iVar1 + 0x2d8);
  FUN_2014d8ec(*param_1 + 0xf,*(undefined2 *)(iVar1 + 0x2e4));
  FUN_2014d8ec(*param_1 + 0x19,*(undefined2 *)(iVar1 + 0x2c8));
  FUN_2014d8ec(*param_1 + 0x1b,*(undefined2 *)(iVar1 + 0x2ca));
  FUN_2014d918(*param_1 + 0x1d,*(undefined4 *)(iVar1 + 0x2d0));
  FUN_2014d918(*param_1 + 0x21,*(undefined4 *)(iVar1 + 0x2d4));
  FUN_2014d918(*param_1 + 0x25,*(undefined4 *)(iVar1 + 0x2e0));
  uVar2 = FUN_2013ebc0();
  FUN_2014d918(*param_1 + 0x44,uVar2);
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
  iVar3 = *(int *)(iVar1 + 0x2d0);
  iVar1 = sd_write_sectors(iVar3,*param_1 + 1,1,param_1);
  if (iVar1 == 0) {
    sd_write_sectors(iVar3 + 6,*param_1 + 1,1,param_1);
    return;
  }
  return;
}


// ===== FUN_2013ee64 @ 2013ee64 (88 bytes)

void FUN_2013ee64(ushort *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 extraout_r1;
  uint uVar2;
  
  *param_2 = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (param_1[1] != 0)) {
    if (*(uint *)(param_1 + 4) < 0xfb0400) {
      __aeabi_uidivmod(*(uint *)(param_1 + 4),param_1[1] * uVar2);
      uVar1 = __aeabi_uidivmod(extraout_r1,uVar2);
    }
    else {
      uVar1 = 0xfe;
    }
    *param_2 = uVar1;
  }
  return;
}


// ===== FUN_2013eebc @ 2013eebc (128 bytes)

void FUN_2013eebc(ushort *param_1,byte *param_2)

{
  ushort uVar1;
  char extraout_r1;
  uint uVar2;
  uint uVar3;
  
  *param_2 = 0;
  param_2[1] = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (uVar1 = param_1[1], uVar1 != 0)) {
    uVar3 = *(uint *)(param_1 + 4);
    if (uVar3 < 0xfb0400) {
      __aeabi_uidivmod(uVar3,uVar2);
      uVar2 = __aeabi_uidivmod(uVar3,uVar1 * uVar2);
      *param_2 = (byte)((uVar2 >> 8) << 6) | extraout_r1 + 1U;
    }
    else {
      uVar2 = 0xff;
      *param_2 = 0xff;
    }
    param_2[1] = (byte)uVar2;
  }
  return;
}


// ===== FUN_2013ef3c @ 2013ef3c (96 bytes)

void FUN_2013ef3c(int param_1,undefined1 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 == '\f' || cVar1 == '\x10') {
    if (*(uint *)(param_1 + 0xc) < 0x7fa8) {
      uVar2 = 1;
    }
    else if (*(uint *)(param_1 + 0xc) < 0x10000) {
      uVar2 = 4;
    }
    else {
      uVar2 = 6;
    }
  }
  else {
    if (cVar1 != ' ') {
      return;
    }
    if (*(uint *)(param_1 + 0xc) < 0xfb0400) {
      *param_2 = 0xb;
      return;
    }
    uVar2 = 0xc;
  }
  *param_2 = uVar2;
  return;
}


// ===== FUN_2013ef9c @ 2013ef9c (100 bytes)

void FUN_2013ef9c(ushort *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 extraout_r1;
  uint uVar2;
  
  *param_2 = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (param_1[1] != 0)) {
    if (*(uint *)(param_1 + 6) < 0xfb0400) {
      __aeabi_uidivmod(*(int *)(param_1 + 4) + *(uint *)(param_1 + 6) + -1,param_1[1] * uVar2);
      uVar1 = __aeabi_uidivmod(extraout_r1,uVar2);
    }
    else {
      uVar1 = 0xfe;
    }
    *param_2 = uVar1;
  }
  return;
}


// ===== FUN_2013f000 @ 2013f000 (136 bytes)

void FUN_2013f000(ushort *param_1,byte *param_2)

{
  ushort uVar1;
  char extraout_r1;
  uint uVar2;
  int iVar3;
  
  *param_2 = 0;
  param_2[1] = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (uVar1 = param_1[1], uVar1 != 0)) {
    if (*(uint *)(param_1 + 6) < 0xfb0400) {
      iVar3 = *(int *)(param_1 + 4) + *(uint *)(param_1 + 6);
      __aeabi_uidivmod(iVar3 + -1,uVar2);
      uVar2 = __aeabi_uidivmod(iVar3 + -1,uVar1 * uVar2);
      *param_2 = (byte)((uVar2 >> 8) << 6) | extraout_r1 + 1U;
    }
    else {
      uVar2 = 0xff;
      *param_2 = 0xff;
    }
    param_2[1] = (byte)uVar2;
  }
  return;
}


// ===== FUN_2013f088 @ 2013f088 (184 bytes)

void FUN_2013f088(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar3 = iVar1 + 0x2c8;
  fs_memset(iVar1 + 1,0,0x200);
  iVar2 = *param_1;
  FUN_2013ee64(iVar3,iVar2 + 0x1c0);
  FUN_2013eebc(iVar3,iVar2 + 0x1c1);
  FUN_2013ef3c(iVar3,iVar2 + 0x1c3);
  FUN_2013ef9c(iVar3,iVar2 + 0x1c4);
  FUN_2013f000(iVar3,iVar2 + 0x1c5);
  FUN_2014d918(iVar2 + 0x1c7,*(undefined4 *)(iVar1 + 0x2d0));
  FUN_2014d918(iVar2 + 0x1cb,*(undefined4 *)(iVar1 + 0x2d4));
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
  sd_write_sectors(0,*param_1 + 1,1,param_1);
  return;
}


// ===== FUN_2013f15c @ 2013f15c (36 bytes)

undefined4 FUN_2013f15c(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(param_1 + 5) & 0xf;
  if (bVar1 == 10) {
    uVar2 = 0x400;
  }
  else if (bVar1 == 0xb) {
    uVar2 = 0x800;
  }
  else {
    uVar2 = 0x200;
  }
  return uVar2;
}


// ===== FUN_2013f180 @ 2013f180 (36 bytes)

uint FUN_2013f180(int param_1)

{
  return (*(byte *)(param_1 + 8) & 0xc0 |
         ((uint)*(byte *)(param_1 + 7) | (*(byte *)(param_1 + 6) & 3) << 8) << 8) >> 6;
}


// ===== FUN_2013f1a4 @ 2013f1a4 (108 bytes)

undefined4 FUN_2013f1a4(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(byte *)(param_1 + 10) & 0x80 | (*(byte *)(param_1 + 9) & 3) << 8) >> 7;
  if (uVar1 == 0) {
    uVar2 = 4;
  }
  else if (uVar1 == 1) {
    uVar2 = 8;
  }
  else if (uVar1 == 2) {
    uVar2 = 0x10;
  }
  else if (uVar1 == 3) {
    uVar2 = 0x20;
  }
  else if (uVar1 == 4) {
    uVar2 = 0x40;
  }
  else if (uVar1 == 5) {
    uVar2 = 0x80;
  }
  else if (uVar1 == 6) {
    uVar2 = 0x100;
  }
  else {
    uVar2 = 0x200;
  }
  return uVar2;
}


// ===== FUN_2013f210 @ 2013f210 (40 bytes)

void FUN_2013f210(uint param_1,undefined4 param_2)

{
  if (param_1 < 0x7e0000) {
    fs_memcpy(param_2,&DAT_20420300,0x2c);
    return;
  }
  fs_memcpy(param_2,&DAT_2042032c,0x2c);
  return;
}


// ===== FUN_2013f238 @ 2013f238 (264 bytes)

void FUN_2013f238(uint param_1,undefined4 param_2)

{
  param_1 = param_1 >> 9;
  if (param_1 < 0x1000) {
    fs_memcpy(param_2,&DAT_20420358,0x2c);
    return;
  }
  if (param_1 < 0x4000) {
    fs_memcpy(param_2,&DAT_20420384,0x2c);
    return;
  }
  if (param_1 < 0x8000) {
    fs_memcpy(param_2,&DAT_204203b0,0x2c);
    return;
  }
  if (param_1 < 0x10000) {
    fs_memcpy(param_2,&DAT_204203dc,0x2c);
    return;
  }
  if (param_1 < 0x20000) {
    fs_memcpy(param_2,&DAT_20420408,0x2c);
    return;
  }
  if (param_1 < 0x40000) {
    fs_memcpy(param_2,&DAT_20420434,0x2c);
    return;
  }
  if (param_1 < 0x80000) {
    fs_memcpy(param_2,&DAT_20420460,0x2c);
    return;
  }
  if (param_1 < 0xfc000) {
    fs_memcpy(param_2,&DAT_2042048c,0x2c);
    return;
  }
  if (param_1 < 0x1f8000) {
    fs_memcpy(param_2,&DAT_204204b8,0x2c);
    return;
  }
  if (param_1 < 0x3f0000) {
    fs_memcpy(param_2,&DAT_204204e4,0x2c);
    return;
  }
  fs_memcpy(param_2,&DAT_20420510,0x2c);
  return;
}


// ===== FUN_2013f340 @ 2013f340 (1116 bytes)

undefined4 FUN_2013f340(int *param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined4 local_28;
  
  local_28 = 0;
  iVar3 = *param_1;
  pbVar9 = (byte *)(iVar3 + 0x201);
  if (*pbVar9 >> 6 == 1) {
    uVar10 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 0x208),*(undefined1 *)(iVar3 + 0x209)),
                            *(undefined1 *)(iVar3 + 0x20a)) * 0x400 + 0x400;
    FUN_2013f210(uVar10,iVar3 + 0x2c8);
    if (uVar10 < 0x4000000) {
      *(uint *)(iVar3 + 0x2d4) = uVar10;
      iVar4 = (int)*(char *)(iVar3 + 0x2dc);
      if (iVar4 != 0x40) {
        uVar11 = (uint)*(ushort *)(iVar3 + 0x2d8);
        iVar6 = __aeabi_uidivmod(uVar10,uVar11);
        iVar5 = (uint)*(ushort *)(iVar3 + 0x2da) << 3;
        uVar15 = __aeabi_uidivmod(iVar6 * iVar4,iVar5);
        *(int *)(iVar3 + 0x2e0) = (int)uVar15;
        iVar13 = (uint)((int)((ulonglong)uVar15 >> 0x20) != 0) + (int)uVar15;
        iVar6 = 1;
        *(int *)(iVar3 + 0x2e0) = iVar13;
        uVar7 = *(uint *)(iVar3 + 0x2cc);
        if (uVar7 <= (uint)(iVar13 * 2)) {
          do {
            iVar6 = iVar6 + 1;
          } while (uVar7 * iVar6 < (uint)(iVar13 * 2) || uVar7 * iVar6 + iVar13 * -2 == 0);
        }
        uVar14 = uVar7 * iVar6 + iVar13 * -2;
        uVar8 = uVar14 & 0xffff;
        *(short *)(iVar3 + 0x2e4) = (short)uVar14;
        if (uVar8 < 9) {
          uVar8 = uVar8 + uVar7;
          *(short *)(iVar3 + 0x2e4) = (short)uVar8;
        }
        iVar6 = (uVar8 & 0xffff) + iVar13 * 2;
        *(int *)(iVar3 + 0x2e8) = iVar6;
        iVar12 = uVar10 - *(int *)(iVar3 + 0x2d0);
        iVar6 = __aeabi_uidivmod(iVar12 - iVar6,uVar11);
        *(int *)(iVar3 + 0x2ec) = iVar6 + 1;
        uVar15 = __aeabi_uidivmod((iVar6 + 2) * iVar4,iVar5);
        *(int *)(iVar3 + 0x2f0) = (int)uVar15;
        iVar6 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
        *(int *)(iVar3 + 0x2f0) = iVar6;
        if (iVar13 != iVar6) {
          do {
            if (*(uint *)(iVar3 + 0x2e0) < *(uint *)(iVar3 + 0x2f0)) {
              *(uint *)(iVar3 + 0x2e8) = *(int *)(iVar3 + 0x2e8) + uVar7;
              *(short *)(iVar3 + 0x2e4) = *(short *)(iVar3 + 0x2e4) + (short)uVar7;
              iVar6 = *(int *)(iVar3 + 0x2e8);
            }
            else {
              iVar6 = *(uint *)(iVar3 + 0x2e0) - 1;
              iVar13 = 1;
              *(int *)(iVar3 + 0x2e0) = iVar6;
              if (uVar7 <= (uint)(iVar6 * 2)) {
                do {
                  iVar13 = iVar13 + 1;
                } while (uVar7 * iVar13 < (uint)(iVar6 * 2) || uVar7 * iVar13 + iVar6 * -2 == 0);
              }
              uVar10 = uVar7 * iVar13 + iVar6 * -2;
              uVar14 = uVar10 & 0xffff;
              *(short *)(iVar3 + 0x2e4) = (short)uVar10;
              if (uVar14 < 9) {
                uVar14 = uVar14 + uVar7;
                *(short *)(iVar3 + 0x2e4) = (short)uVar14;
              }
              iVar6 = (uVar14 & 0xffff) + iVar6 * 2;
              *(int *)(iVar3 + 0x2e8) = iVar6;
            }
            iVar6 = __aeabi_uidivmod(iVar12 - iVar6,uVar11);
            *(int *)(iVar3 + 0x2ec) = iVar6 + 1;
            uVar15 = __aeabi_uidivmod((iVar6 + 2) * iVar4,iVar5);
            *(int *)(iVar3 + 0x2f0) = (int)uVar15;
            iVar6 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
            *(int *)(iVar3 + 0x2f0) = iVar6;
          } while (*(int *)(iVar3 + 0x2e0) != iVar6);
        }
        FUN_2013e800(*(int *)(iVar3 + 0x2e0) + uVar11,*param_1);
      }
      *(int *)(iVar3 + 0x2d4) = *(int *)(iVar3 + 0x2d4) - *(int *)(iVar3 + 0x2cc);
    }
    else {
      local_28 = 0xfffffffb;
    }
  }
  else if (*pbVar9 >> 6 == 0) {
    iVar4 = FUN_2013f15c(pbVar9);
    iVar5 = FUN_2013f180(pbVar9);
    iVar6 = FUN_2013f1a4(pbVar9);
    uVar10 = (iVar5 + 1) * iVar6 * iVar4;
    FUN_2013f238(uVar10,iVar3 + 0x2c8);
    uVar10 = uVar10 >> 9;
    *(uint *)(iVar3 + 0x2d4) = uVar10;
    uVar1 = *(undefined2 *)(iVar3 + 0x2d8);
    iVar5 = __aeabi_uidivmod(uVar10);
    iVar6 = (int)*(char *)(iVar3 + 0x2dc);
    iVar4 = (uint)*(ushort *)(iVar3 + 0x2da) << 3;
    uVar15 = __aeabi_uidivmod(iVar5 * iVar6);
    uVar7 = (uint)uVar15 & 0xffff;
    uVar14 = ((int)((ulonglong)uVar15 >> 0x20) != 0) + uVar7;
    *(uint *)(iVar3 + 0x2e0) = uVar7;
    *(uint *)(iVar3 + 0x2e0) = uVar14;
    uVar2 = *(ushort *)(iVar3 + 0x2e4);
    uVar11 = (uint)uVar2 + uVar14 * 2 + 0x20;
    *(uint *)(iVar3 + 0x2e8) = uVar11;
    uVar7 = *(uint *)(iVar3 + 0x2cc);
    if (uVar7 < uVar11) {
      uVar15 = __aeabi_uidivmod(uVar11,uVar7);
      uVar8 = uVar7 * ((uint)((int)((ulonglong)uVar15 >> 0x20) != 0) + (int)uVar15) - uVar11;
    }
    else {
      uVar8 = uVar7 - uVar11;
    }
    *(uint *)(iVar3 + 0x2d0) = uVar8;
    if (uVar8 != uVar7) {
      uVar8 = uVar8 + uVar7;
      *(uint *)(iVar3 + 0x2d0) = uVar8;
    }
    iVar5 = __aeabi_uidivmod((uVar10 - uVar8) - uVar11,uVar1);
    *(int *)(iVar3 + 0x2ec) = iVar5 + 1;
    uVar15 = __aeabi_uidivmod((iVar5 + 2) * iVar6,iVar4);
    *(int *)(iVar3 + 0x2f0) = (int)uVar15;
    uVar11 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
    *(uint *)(iVar3 + 0x2f0) = uVar11;
    if (uVar14 != uVar11) {
      do {
        if (*(uint *)(iVar3 + 0x2e0) < uVar11) {
          uVar11 = *(int *)(iVar3 + 0x2d0) + uVar7;
          *(uint *)(iVar3 + 0x2d0) = uVar11;
        }
        else {
          *(uint *)(iVar3 + 0x2e0) = uVar11;
          uVar11 = (uint)uVar2 + uVar11 * 2 + 0x20;
          *(uint *)(iVar3 + 0x2e8) = uVar11;
          if (uVar7 < uVar11) {
            uVar15 = __aeabi_uidivmod(uVar11,uVar7);
            uVar11 = uVar7 * ((uint)((int)((ulonglong)uVar15 >> 0x20) != 0) + (int)uVar15) - uVar11;
          }
          else {
            uVar11 = uVar7 - uVar11;
          }
          *(uint *)(iVar3 + 0x2d0) = uVar11;
          if (uVar11 != uVar7) {
            uVar11 = uVar11 + uVar7;
            *(uint *)(iVar3 + 0x2d0) = uVar11;
          }
        }
        iVar5 = __aeabi_uidivmod((uVar10 - uVar11) - *(int *)(iVar3 + 0x2e8),uVar1);
        *(int *)(iVar3 + 0x2ec) = iVar5 + 1;
        uVar15 = __aeabi_uidivmod((iVar5 + 2) * iVar6,iVar4);
        *(int *)(iVar3 + 0x2f0) = (int)uVar15;
        uVar11 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
        *(uint *)(iVar3 + 0x2f0) = uVar11;
      } while (*(uint *)(iVar3 + 0x2e0) != uVar11);
    }
    FUN_2013e800(*(int *)(iVar3 + 0x2e0) + 0x20,*param_1);
    *(int *)(iVar3 + 0x2d4) = *(int *)(iVar3 + 0x2d4) - *(int *)(iVar3 + 0x2d0);
  }
  else {
    local_28 = 0xffffffff;
  }
  return local_28;
}


// ===== fat_clear_root_dir @ 2013f79c (356 bytes)

/* zero the root-directory sectors (FAT12/16: 32, FAT32: 1 cluster) */

int fat_clear_root_dir(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_r4;
  uint uVar5;
  
  fs_memset(*param_1 + 0x2c8,0,0x2c);
  iVar3 = FUN_2013f340(param_1);
  if ((((iVar3 == 0) && (iVar3 = FUN_2013f088(param_1), iVar3 == 0)) &&
      ((*(char *)(*param_1 + 0x2dc) == '@' ||
       ((iVar3 = FUN_2013ec30(param_1), iVar3 == 0 &&
        ((*(char *)(*param_1 + 0x2dc) != ' ' || (iVar3 = FUN_2013ea74(param_1), iVar3 == 0))))))))
     && (iVar3 = FUN_2013e8d0(param_1), iVar3 == 0)) {
    iVar3 = *param_1;
    fs_memset(iVar3 + 1,0,0x200,0,unaff_r4);
    cVar1 = *(char *)(iVar3 + 0x2dc);
    if (cVar1 == '\f' || cVar1 == '\x10') {
      uVar5 = 0x20;
      iVar3 = *(int *)(iVar3 + 0x2d0) + (uint)*(ushort *)(iVar3 + 0x2e4) +
              *(int *)(iVar3 + 0x2e0) * 2;
    }
    else {
      if (cVar1 != ' ') {
        return -2;
      }
      uVar5 = (uint)*(ushort *)(iVar3 + 0x2d8);
      iVar3 = *(int *)(iVar3 + 0x2d0) + (uint)*(ushort *)(iVar3 + 0x2e4) +
              *(int *)(iVar3 + 0x2e0) * 2;
    }
    uVar4 = 0;
    if (uVar5 != 0) {
      do {
        iVar2 = sd_write_sectors(iVar3,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        FUN_2013e7e8(*param_1);
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 1;
      } while (uVar4 < uVar5);
    }
    return 0;
  }
  return iVar3;
}


// ===== sd_fat_format @ 2013f83c (328 bytes)

/* card init (3 tries), then fat_clear_root_dir */

int sd_fat_format(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(param_1[1] + 0x24))();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = 0;
  do {
    iVar2 = (**(code **)(param_1[1] + 0x20))(2);
    if ((iVar2 == 0) && (iVar2 = sd_card_identify(param_1), iVar2 == 0)) {
      if (*(short *)(*param_1 + 0x2c6) == 1) {
        return -5;
      }
      iVar2 = FUN_2013e124(param_1);
      if ((((((iVar2 == 0) &&
             (iVar2 = FUN_2013e190(*(undefined2 *)(*param_1 + 0x2aa),0x200,1,param_1), iVar2 == 0))
            && (iVar2 = FUN_2013d434(*(undefined2 *)(*param_1 + 0x2aa),param_1), iVar2 == 0)) &&
           ((iVar2 = FUN_2013e1e4(param_1), iVar2 == 0 &&
            (iVar2 = FUN_2013d744(param_1), iVar2 == 0)))) &&
          ((iVar2 = FUN_2013df88(param_1), iVar2 == 0 &&
           (iVar2 = FUN_2013c928(1,param_1), iVar2 == 0)))) &&
         (((*(short *)(*param_1 + 0x2c2) != 2 && *(short *)(*param_1 + 0x2c2) != 3 ||
           (iVar2 = (**(code **)(param_1[1] + 0x40))(), iVar2 == 0)) &&
          (iVar2 = fat_clear_root_dir(param_1), iVar2 == 0)))) {
        return 0;
      }
    }
    iVar1 = iVar1 + 1;
    if (2 < iVar1) {
      return iVar2;
    }
  } while( true );
}


// ===== sd_format @ 2013f984 (96 bytes)

/* drive letter; -> sd_fat_format (inference: format, #83) */

uint sd_format(char param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int local_10;
  
  local_10 = DAT_20808ba0;
  iVar2 = fs_check_ready();
  if (iVar2 != 0) {
    return 0xfffffff8;
  }
  uVar1 = fs_toupper((int)param_1);
  iVar2 = fs_find_drive(uVar1,&local_10);
  if (iVar2 == 0) {
    if (*(int *)(local_10 + 0x24) == 0) {
      return 0xfffffff8;
    }
    uVar3 = sd_fat_format();
  }
  else {
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}


// ===== FUN_2013f9fc @ 2013f9fc (80 bytes)

undefined4 FUN_2013f9fc(undefined4 param_1,int param_2)

{
  int iVar1;
  
  (&DAT_20808b60)[param_2] = param_1;
  *(undefined4 *)(&DAT_20808b5c + param_2 * 4) = 0;
  if (DAT_20808b58 == 0) {
    iVar1 = os_create_tsk_named(&DAT_2042053c,"SDInsCheck");
    if (iVar1 < 1) {
      return 0xffffffff;
    }
    DAT_20808b58 = iVar1;
    itron_act_tsk();
  }
  return 0;
}


// ===== FUN_2013fa60 @ 2013fa60 (148 bytes)

void FUN_2013fa60(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  do {
    itron_dly_tsk(0x32);
    iVar3 = 0;
    do {
      if (*(int *)((&DAT_20808b60)[iVar3] + 0x24) != 0) {
        iVar1 = (**(code **)(*(int *)(*(int *)((&DAT_20808b60)[iVar3] + 0x24) + 4) + 8))();
        if (iVar1 == 0) {
          if (*(int *)(&DAT_20808b5c + iVar3 * 4) != 1) {
            *(undefined4 *)(&DAT_20808b5c + iVar3 * 4) = 1;
            iVar1 = (&DAT_20808b60)[iVar3];
            bVar2 = *(byte *)(iVar1 + 0x68) | 0x40;
            goto LAB_2013fadc;
          }
        }
        else if (*(int *)(&DAT_20808b5c + iVar3 * 4) == 1) {
          *(undefined4 *)(&DAT_20808b5c + iVar3 * 4) = 0;
          iVar1 = (&DAT_20808b60)[iVar3];
          bVar2 = *(byte *)(iVar1 + 0x68) & 0xbf;
LAB_2013fadc:
          *(byte *)(iVar1 + 0x68) = bVar2;
        }
      }
      iVar3 = (int)(char)((char)iVar3 + '\x01');
    } while (iVar3 < 1);
  } while( true );
}


// ===== FUN_2013faf4 @ 2013faf4 (152 bytes)

int FUN_2013faf4(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*(int *)((&DAT_20808b60)[param_1] + 0x24) == 0) {
    return -1;
  }
  iVar1 = (**(code **)(*(int *)(*(int *)((&DAT_20808b60)[param_1] + 0x24) + 4) + 8))();
  if (iVar1 == 0) {
    uVar2 = (uint)*(char *)((&DAT_20808b60)[param_1] + 0x68);
    if ((uVar2 & 0x40) != 0) {
      iVar1 = 1;
      if ((uVar2 & 0x80) != 0) {
        return 1;
      }
      FUN_201446d0((&DAT_20808b60)[param_1]);
      iVar3 = FUN_2014a9d4((&DAT_20808b60)[param_1]);
      goto joined_r0x2013fb7c;
    }
  }
  iVar1 = 0;
  if ((*(byte *)((&DAT_20808b60)[param_1] + 0x68) & 0x80) == 0) {
    return 0;
  }
  iVar3 = FUN_2014aaf0();
joined_r0x2013fb7c:
  if (iVar3 != 0) {
    iVar1 = iVar3;
  }
  return iVar1;
}


// ===== FUN_2013fb8c @ 2013fb8c (20 bytes)

void FUN_2013fb8c(undefined4 param_1)

{
  DAT_20808b64 = param_1;
  DAT_20808b68 = 0;
  return;
}


// ===== FUN_2013fba0 @ 2013fba0 (112 bytes)

int FUN_2013fba0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((DAT_20808b64 != 0) && (DAT_20808b68 == 0)) {
    itron_chg_pri(0,6);
    uVar1 = FUN_20132f6c();
    iVar2 = FUN_2014a304(0x49,uVar1,0x20000);
    itron_chg_pri(0);
    if (iVar2 == 0) {
      DAT_20808b68 = 1;
    }
    return iVar2;
  }
  return 0;
}


// ===== FUN_2013fc10 @ 2013fc10 (60 bytes)

void FUN_2013fc10(void)

{
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_10 = 2;
  uStack_c = 0;
  uStack_8 = 0;
  DAT_20808b6c = itron_acre_mtx(0,&uStack_10);
  return;
}


// ===== FUN_2013fc4c @ 2013fc4c (28 bytes)

void FUN_2013fc4c(int param_1)

{
  if (param_1 != 0) {
    itron_tloc_mtx(DAT_20808b6c,0xffffffff);
    return;
  }
  itron_unl_mtx(DAT_20808b6c);
  return;
}


// ===== FUN_2013fc68 @ 2013fc68 (212 bytes)

uint FUN_2013fc68(int param_1,uint param_2)

{
  int iVar1;
  
  if (*(int *)((&DAT_20808b60)[param_1] + 0x24) == 0) {
    param_2 = 0xffffffff;
  }
  else {
    iVar1 = (**(code **)(*(int *)(*(int *)((&DAT_20808b60)[param_1] + 0x24) + 4) + 8))();
    if ((iVar1 == 0) && (((int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0x40U) != 0)) {
      if ((param_2 & 0x40) == 0) {
        if (((int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0x80U) == 0) {
          itron_tloc_mtx(DAT_20808b6c,0xffffffff);
          FUN_201446d0((&DAT_20808b60)[param_1]);
          iVar1 = FUN_2014a9d4((&DAT_20808b60)[param_1]);
          itron_unl_mtx(DAT_20808b6c);
          if (iVar1 != 0) {
            return 0x40;
          }
          FUN_2013fb8c(1);
        }
        param_2 = 0xc0;
      }
    }
    else {
      param_2 = (int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0xffffff3f;
      if (((int)*(char *)((&DAT_20808b60)[param_1] + 0x68) & 0x80U) != 0) {
        FUN_2013fb8c(0);
        iVar1 = FUN_2014aaf0((&DAT_20808b60)[param_1]);
        if (iVar1 == 0) {
          param_2 = 0;
        }
      }
    }
  }
  return param_2;
}


// ===== FUN_2013fd3c @ 2013fd3c (20 bytes)

void FUN_2013fd3c(int param_1)

{
  itron_dly_tsk(param_1 / 10);
  return;
}


// ===== FUN_2013fd50 @ 2013fd50 (32 bytes)

void FUN_2013fd50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&DAT_20808b60)[param_1];
  if (*(int *)(iVar1 + 0x24) == 0) {
    return;
  }
  iVar2 = fs_check_ready();
  if (iVar2 != 0) {
    fs_set_error(iVar2,0);
    return;
  }
  if ((*(byte *)(iVar1 + 0x68) & 1) == 0) {
    fs_set_error(0xfffffff0,0);
    return;
  }
  iVar2 = (**(code **)(iVar1 + 0x18))(iVar1,8,0);
  if (iVar2 == 0) {
    *(byte *)(iVar1 + 0x68) = *(byte *)(iVar1 + 0x68) & 0x7f;
    fs_set_error(0,0);
    return;
  }
  FUN_20144834();
  return;
}


// ===== FUN_2013fd98 @ 2013fd98 (60 bytes)

void FUN_2013fd98(void)

{
  DAT_2091cba8 = 0;
  DAT_20808b44 = &DAT_2091cba8;
  DAT_20808b48 = &PTR_FUN_20420564;
  FUN_2013e71c();
  return;
}


// ===== FUN_2013fde4 @ 2013fde4 (4 bytes)

void FUN_2013fde4(void)

{
  return;
}


// ===== FUN_2013fde8 @ 2013fde8 (104 bytes)

undefined4 FUN_2013fde8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = INTC_ICDIPR75;
  if (DAT_20808b70 == -1) {
    uVar2 = gic_def_inh(0x12f,0x204205cc);
    if ((int)uVar2 < 0) {
      return 0xffffffff;
    }
    DAT_20808b70 = 1;
  }
  INTC_ICDIPR75 = uVar1 & 0xffffff | 0x38000000;
  FUN_2015686c();
  INTC_ICDISER9 = 0x8000;
  FUN_2015688c();
  return 0;
}


// ===== sdhi0_clock_on @ 2013fe50 (20 bytes)

/* STBCR12 &= 0xF3 */

void sdhi0_clock_on(void)

{
  byte bVar1;
  
  bVar1 = CPG_STBCR12;
  CPG_STBCR12 = bVar1 & 0xf3;
  return;
}


// ===== FUN_2013ffdc @ 2013ffdc (4 bytes)

void FUN_2013ffdc(void)

{
  return;
}


// ===== FUN_2013ffec @ 2013ffec (68 bytes)

void FUN_2013ffec(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  DMAC_N0SA_0 = param_2;
  DMAC_N0DA_0 = param_1;
  DMAC_N0TB_0 = 0x200;
  DMAC_CHCFG_0 = 0x126260;
  DMAC_CHITVL_0 = 0;
  DMAC_CHEXT_0 = 0;
  uVar1 = DMAC_CHCTRL_0;
  DMAC_CHCTRL_0 = uVar1 | 8;
  uVar1 = DMAC_CHCTRL_0;
  DMAC_CHCTRL_0 = uVar1 | 1;
  return;
}


// ===== FUN_20140030 @ 20140030 (48 bytes)

void FUN_20140030(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = DMAC_CHSTAT_0;
    if ((uVar1 & 5) == 0) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x900000);
  uVar2 = DMAC_CHCTRL_0;
  DMAC_CHCTRL_0 = uVar2 | 8;
  return;
}


// ===== FUN_20140060 @ 20140060 (68 bytes)

void FUN_20140060(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  DMAC_N0SA_1 = param_2;
  DMAC_N0DA_1 = param_1;
  DMAC_N0TB_1 = 0x200;
  DMAC_CHCFG_1 = 0x262269;
  DMAC_CHITVL_1 = 0;
  DMAC_CHEXT_1 = 0;
  uVar1 = DMAC_CHCTRL_1;
  DMAC_CHCTRL_1 = uVar1 | 8;
  uVar1 = DMAC_CHCTRL_1;
  DMAC_CHCTRL_1 = uVar1 | 1;
  return;
}


// ===== FUN_201400a4 @ 201400a4 (48 bytes)

void FUN_201400a4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = DMAC_CHSTAT_1;
    if ((uVar1 & 5) == 0) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x900000);
  uVar2 = DMAC_CHCTRL_1;
  DMAC_CHCTRL_1 = uVar2 | 8;
  return;
}


// ===== sdhi_init @ 201400d4 (60 bytes)

/* SDINT_INI */

uint sdhi_init(void)

{
  int iVar1;
  
  iVar1 = DAT_20808b74;
  if ((DAT_20808b74 == 0) && (iVar1 = os_create_flg_named(&DAT_204205d8,"SDINT_INI"), iVar1 < 1)) {
    return 0xffffffff;
  }
  DAT_20808b74 = iVar1;
  return 0;
}


// ===== FUN_20140148 @ 20140148 (16 bytes)

void FUN_20140148(undefined4 param_1)

{
  itron_set_flg(DAT_20808b74,param_1);
  return;
}


// ===== FUN_20140158 @ 20140158 (84 bytes)

void * FUN_20140158(uint param_1,int param_2)

{
  void *pvVar1;
  uint uStack_14;
  
  pvVar1 = itron_twai_flg(DAT_20808b74,param_1,0,&uStack_14,param_2 / 10);
  itron_clr_flg(DAT_20808b74,~param_1);
  return pvVar1;
}


// ===== FUN_201401ac @ 201401ac (48 bytes)

bool FUN_201401ac(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = 0;
  do {
    uVar2 = sd_card_detect();
    uVar3 = uVar3 + 1;
    uVar1 = uVar2 | uVar1 << 1;
  } while (uVar3 < 0x20);
  return uVar1 != 0;
}


// ===== FUN_201401dc @ 201401dc (44 bytes)

bool FUN_201401dc(void)

{
  ushort uVar1;
  
  uVar1 = SDHI_SD_INFO1_0;
  return (uVar1 & 0x80) == 0;
}


// ===== FUN_20140210 @ 20140210 (136 bytes)

undefined4 FUN_20140210(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  bool bVar4;
  
  SDHI_EXT_SWAP_0 = 0x100;
  puVar3 = param_1;
  if (((uint)param_1 & 0x1f) != 0) {
    puVar3 = &DAT_2091cec0;
  }
  thunk_FUN_20101088(puVar3,0x200);
  FUN_2013ffec(puVar3,&SDHI_SD_CMD_0);
  iVar1 = FUN_20140158(4,500);
  FUN_20140030();
  thunk_FUN_20101088(puVar3,0x200);
  if (iVar1 == 0) {
    if (((uint)param_1 & 0x1f) != 0) {
      iVar1 = 0x1ff;
      do {
        bVar4 = iVar1 != 0;
        iVar1 = iVar1 + -1;
        *param_1 = *puVar3;
        param_1 = param_1 + 1;
        puVar3 = puVar3 + 1;
      } while (bVar4);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff1;
  }
  return uVar2;
}


// ===== FUN_20140298 @ 20140298 (116 bytes)

undefined4 FUN_20140298(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  SDHI_EXT_SWAP_0 = 0x100;
  if (((uint)param_1 & 0x1f) != 0) {
    iVar2 = 0x1ff;
    puVar1 = &DAT_2091cec0;
    do {
      bVar4 = iVar2 != 0;
      iVar2 = iVar2 + -1;
      *puVar1 = *param_1;
      param_1 = param_1 + 1;
      puVar1 = puVar1 + 1;
    } while (bVar4);
    param_1 = &DAT_2091cec0;
  }
  dcache_clean_range(param_1,0x200);
  FUN_20140060(&SDHI_SD_CMD_0,param_1);
  iVar2 = FUN_20140158(4,500);
  FUN_201400a4();
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = 0xfffffff0;
  }
  return uVar3;
}


// ===== FUN_2014030c @ 2014030c (20 bytes)

void FUN_2014030c(void)

{
  FUN_20140148(4);
  return;
}


// ===== FUN_20140320 @ 20140320 (20 bytes)

undefined4 FUN_20140320(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_201401ac();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xfffffffa;
  }
  return uVar2;
}


// ===== FUN_20140334 @ 20140334 (164 bytes)

int FUN_20140334(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  while ((uVar1 = SDHI_SD_INFO2_0, (uVar1 & 0x4000) != 0 || ((uVar1 & 0x2000) == 0))) {
    if ((uVar1 & 0x807f) != 0) {
      return -9;
    }
    iVar3 = FUN_20140320();
    if (iVar3 != 0) {
      return iVar3;
    }
    uVar4 = uVar4 + 1;
    if (0x8fffff < uVar4) {
      return -1;
    }
  }
  if (0x8fffff < uVar4) {
    return -1;
  }
  if (param_1 != -1) {
    if (param_1 == 0) {
      uVar2 = 0x140;
      goto LAB_201403cc;
    }
    if (param_1 != 1) {
      if (param_1 != 2) {
        return -8;
      }
      uVar2 = 0x100;
      goto LAB_201403cc;
    }
  }
  uVar2 = 0x101;
LAB_201403cc:
  SDHI_SD_CLK_CTRL_0 = uVar2;
  return 0;
}


// ===== FUN_201403d8 @ 201403d8 (16 bytes)

void FUN_201403d8(void)

{
  SDHI_SD_CLK_CTRL_0 = 0x200;
  return;
}


// ===== FUN_201403e8 @ 201403e8 (12 bytes)

void FUN_201403e8(undefined2 param_1)

{
  SDHI_SD_SIZE_0 = param_1;
  return;
}


// ===== FUN_201403f4 @ 201403f4 (12 bytes)

void FUN_201403f4(undefined2 param_1)

{
  SDHI_SD_SECCNT_0 = param_1;
  return;
}

