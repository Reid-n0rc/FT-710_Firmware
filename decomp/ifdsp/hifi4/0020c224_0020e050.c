// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0020c224 @ 0020c224 (128 bytes)

undefined4 * FUN_0020c224(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  
  memw();
  if ((*(uint *)(param_1 + 0xe0) & 2) == 0) goto LAB_0020c244;
  memw();
  uVar1 = *(uint *)(param_1 + 0xe0);
  while ((uVar1 & 1) == 0) {
LAB_0020c244:
    do {
      memw();
    } while ((*(uint *)(param_1 + 0xe0) & 2) == 0);
    memw();
    uVar1 = *(uint *)(param_1 + 0xe0);
  }
  memw();
  *(undefined4 *)(param_1 + 0x18) = 0x5af05af0;
  memw();
  *(undefined4 *)(param_1 + 0x1c) = 2;
  if ((param_4 != 0) && ((param_4 == 1 || (param_4 != 0)))) {
    memw();
    *(undefined4 *)(param_2 * 4 + param_1 + 0x200) = *param_3;
    param_3 = param_3 + 1;
  }
  memw();
  *(undefined4 *)(param_1 + 0x18) = 0x5af05af0;
  memw();
  *(undefined4 *)(param_1 + 0x1c) = 1;
  return param_3;
}


// ===== FUN_0020c2a8 @ 0020c2a8 (118 bytes)

void FUN_0020c2a8(uint *param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  if ((param_1[0x38] & 2) == 0) goto LAB_0020c2bc;
  memw();
  uVar1 = param_1[0x38];
  while ((uVar1 & 1) == 0) {
LAB_0020c2bc:
    do {
      memw();
    } while ((param_1[0x38] & 2) == 0);
    memw();
    uVar1 = param_1[0x38];
  }
  memw();
  memw();
  *param_1 = *param_1 & 0xffffffcf | (param_2 & 3) << 4;
  memw();
  memw();
  *param_1 = *param_1 | 1;
  memw();
  uVar1 = *param_1;
  while ((uVar1 & 1) != 0) {
    memw();
    uVar1 = *param_1;
  }
  return;
}


// ===== FUN_0020c320 @ 0020c320 (171 bytes)

int FUN_0020c320(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  memw();
  iVar3 = ((*(uint *)(param_1 + 0xbc) & 0x1fc) >> 2) + 1;
  if (param_3 == 0) {
    return 0;
  }
  do {
    memw();
    uVar2 = *(uint *)(param_1 + 0x14);
    while ((uVar2 & 0x40) == 0) {
      memw();
      uVar2 = *(uint *)(param_1 + 0x14);
    }
    iVar1 = FUN_0020bb14(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (param_3 < (uint)(iVar3 * 8)) {
      uVar2 = param_3 + 3 >> 2;
      if ((uVar2 != 0) && ((uVar2 == 1 || (uVar2 != 0)))) {
        memw();
        *(undefined4 *)(param_1 + 0x180) = *param_2;
        param_2 = param_2 + 1;
      }
      param_3 = 0;
    }
    else {
      if ((iVar3 != 0) && ((iVar3 * 2 == 1 || (iVar3 != 0)))) {
        memw();
        *(undefined4 *)(param_1 + 0x180) = *param_2;
        param_2 = param_2 + 1;
      }
      param_3 = param_3 + iVar3 * -8;
    }
    memw();
    memw();
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40;
  } while (param_3 != 0);
  return 0;
}


// ===== FUN_0020c3cc @ 0020c3cc (252 bytes)

int FUN_0020c3cc(int param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  memw();
  iVar4 = ((*(uint *)(param_1 + 0xb8) & 0xfc) >> 2) + 1;
  if (param_3 == 0) {
    return 0;
  }
  bVar1 = false;
  do {
    iVar2 = 0;
    if (param_3 < (uint)(iVar4 * 8)) {
      memw();
      uVar3 = *(uint *)(param_1 + 0xf0);
      while ((uVar3 & 0xff) << 3 < param_3) {
        memw();
        iVar2 = FUN_0020bb14(param_1,*(undefined4 *)(param_1 + 0x14));
        if (iVar2 != 0) {
          bVar1 = true;
          break;
        }
        memw();
        uVar3 = *(uint *)(param_1 + 0xf0);
      }
    }
    else {
      memw();
      uVar3 = *(uint *)(param_1 + 0x14);
      while (iVar2 = 0, (uVar3 & 0x20) == 0) {
        iVar2 = FUN_0020bb14(param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        memw();
        uVar3 = *(uint *)(param_1 + 0x14);
      }
    }
    if (bVar1) {
      return iVar2;
    }
    memw();
    iVar2 = FUN_0020bb14(param_1,*(undefined4 *)(param_1 + 0x14));
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_3 < (uint)(iVar4 * 8)) {
      uVar3 = param_3 + 3 >> 2;
      if ((uVar3 != 0) && ((uVar3 == 1 || (uVar3 != 0)))) {
        memw();
        *param_2 = *(undefined4 *)(param_1 + 0x100);
        param_2 = param_2 + 1;
      }
      param_3 = 0;
    }
    else {
      if ((iVar4 != 0) && ((iVar4 * 2 == 1 || (iVar4 != 0)))) {
        memw();
        *param_2 = *(undefined4 *)(param_1 + 0x100);
        param_2 = param_2 + 1;
      }
      param_3 = param_3 + iVar4 * -8;
    }
    memw();
    memw();
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x20;
    if (param_3 == 0) {
      return 0;
    }
  } while( true );
}


// ===== FUN_0020c4d0 @ 0020c4d0 (273 bytes)

undefined4 FUN_0020c4d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_2[1] * 4 + param_1;
  memw();
  memw();
  *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) | 0x80000000;
  memw();
  memw();
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x1e;
  memw();
  *(undefined4 *)(param_1 + 0xa0) = *param_2;
  memw();
  memw();
  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
  memw();
  memw();
  iVar3 = param_2[2];
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  if (((iVar3 == 2) || (iVar3 == 3)) || (iVar3 == 1)) {
    uVar2 = (uint)*(ushort *)(param_2 + 5);
  }
  else {
    uVar2 = 0;
  }
  memw();
  *(uint *)(param_1 + 0xa4) =
       uVar2 | (*(byte *)(param_2 + 3) & 0x1f) << 0x10 |
               (*(byte *)((int)param_2 + 0xd) - 1) * 0x1000000 & 0x7000000;
  memw();
  memw();
  *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 1;
  if ((iVar3 == 3) || (iVar3 == 1)) {
    uVar1 = FUN_0020c320(param_1,param_2[4],param_2[5]);
    iVar3 = param_2[2];
  }
  else if (iVar3 == 2) {
    uVar1 = FUN_0020c3cc(param_1,param_2[4],param_2[5]);
    iVar3 = param_2[2];
  }
  else {
    uVar1 = 0;
  }
  memw();
  if ((*(uint *)(param_1 + 0xe0) & 2) == 0) goto LAB_0020c580;
  memw();
  uVar2 = *(uint *)(param_1 + 0xe0);
  while ((uVar2 & 1) == 0) {
LAB_0020c580:
    do {
      memw();
    } while ((*(uint *)(param_1 + 0xe0) & 2) == 0);
    memw();
    uVar2 = *(uint *)(param_1 + 0xe0);
  }
  if (iVar3 != 0) {
    return uVar1;
  }
  memw();
  uVar1 = FUN_0020bb14(param_1,*(undefined4 *)(param_1 + 0x14));
  return uVar1;
}


// ===== FUN_0020c5e4 @ 0020c5e4 (43 bytes)

void FUN_0020c5e4(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0020bb00(param_1);
  param_2[4] = param_3;
  param_2[5] = param_4;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  (&DAT_002385dc)[iVar1] = param_2;
  DAT_002385d8 = FUN_0020c728;
  return;
}


// ===== FUN_0020c610 @ 0020c610 (229 bytes)

undefined * FUN_0020c610(int param_1,int *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*param_2 != 0) {
    return &DAT_00001b58;
  }
  iVar2 = param_3[2];
  iVar3 = param_3[5];
  param_2[3] = iVar3;
  param_2[1] = param_3[4];
  iVar4 = 1;
  param_2[2] = iVar3;
  if (iVar2 == 2) {
    iVar4 = 2;
  }
  *param_2 = iVar4;
  iVar2 = param_3[1] * 4 + param_1;
  memw();
  memw();
  *(uint *)(iVar2 + 0x80) = *(uint *)(iVar2 + 0x80) | 0x80000000;
  memw();
  memw();
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x1e;
  memw();
  *(undefined4 *)(param_1 + 0xa0) = *param_3;
  memw();
  memw();
  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
  memw();
  memw();
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  if ((param_3[2] == 2) || (param_3[2] == 3)) {
    uVar1 = (uint)*(ushort *)(param_3 + 5);
  }
  else {
    uVar1 = 0;
  }
  memw();
  *(uint *)(param_1 + 0xa4) =
       uVar1 | (*(byte *)(param_3 + 3) & 0x1f) << 0x10 |
               (*(byte *)((int)param_3 + 0xd) - 1) * 0x1000000 & 0x7000000;
  memw();
  memw();
  iVar2 = *param_2;
  *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 1;
  if (iVar2 == 2) {
    FUN_0020bac0(param_1,0x82b);
    return (undefined *)0x0;
  }
  FUN_0020bac0(param_1,0x84b);
  return (undefined *)0x0;
}


// ===== FUN_0020c6f8 @ 0020c6f8 (28 bytes)

undefined4 FUN_0020c6f8(undefined4 param_1,int *param_2,int *param_3)

{
  if (*param_2 != 0) {
    *param_3 = param_2[3] - param_2[2];
    return 0;
  }
  return 6;
}


// ===== FUN_0020c714 @ 0020c714 (18 bytes)

void FUN_0020c714(undefined4 param_1,undefined4 *param_2)

{
  FUN_0020bad4(param_1,0x86b);
  *param_2 = 0;
  return;
}


// ===== FUN_0020c728 @ 0020c728 (506 bytes)

void FUN_0020c728(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  
  memw();
  uVar2 = *(uint *)(param_1 + 0x14);
  memw();
  if ((*(uint *)(param_1 + 0x10) & uVar2) != 0) {
    iVar1 = FUN_0020bb14(param_1,uVar2);
    if ((iVar1 == 0) || (param_2[4] == 0)) {
      if (((uVar2 >> 5 & 1) != 0) && (*param_2 == 2)) {
        memw();
        uVar6 = param_2[2];
        iVar1 = ((*(uint *)(param_1 + 0xb8) & 0xfc) >> 2) + 1;
        if (uVar6 < (uint)(iVar1 * 8)) {
          if (uVar6 + 3 >> 2 != 0) {
            puVar4 = (undefined4 *)param_2[1];
            uVar6 = 0;
            do {
              memw();
              *puVar4 = *(undefined4 *)(uVar6 * 4 + param_1 + 0x100);
              uVar6 = uVar6 + 1 & 0xff;
              puVar4 = (undefined4 *)(param_2[1] + 4);
              param_2[1] = (int)puVar4;
            } while (uVar6 < param_2[2] + 3U >> 2);
          }
          param_2[2] = 0;
        }
        else {
          if (iVar1 != 0) {
            if ((iVar1 != 0) && ((iVar1 * 2 == 1 || (iVar1 != 0)))) {
              memw();
              iVar3 = param_2[1];
              *(undefined4 *)param_2[1] = *(undefined4 *)(param_1 + 0x100);
              param_2[1] = iVar3 + 4;
            }
            uVar6 = param_2[2];
          }
          param_2[2] = uVar6 + iVar1 * -8;
        }
        memw();
        memw();
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x20;
      }
      if ((uVar2 & 1) != 0) {
        memw();
        memw();
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 1;
        FUN_0020c714(param_1,param_2);
        if ((code *)param_2[4] != (code *)0x0) {
          (*(code *)param_2[4])(param_1,param_2,0,param_2[5]);
        }
      }
      if ((((uVar2 >> 6 & 1) != 0) && (*param_2 == 1)) && (uVar2 = param_2[2], uVar2 != 0)) {
        memw();
        iVar1 = ((*(uint *)(param_1 + 0xbc) & 0x1fc) >> 2) + 1;
        if (uVar2 < (uint)(iVar1 * 8)) {
          if (uVar2 + 3 >> 2 != 0) {
            uVar2 = 0;
            do {
              puVar4 = (undefined4 *)param_2[1];
              param_2[1] = (int)(puVar4 + 1);
              memw();
              *(undefined4 *)(uVar2 * 4 + param_1 + 0x180) = *puVar4;
              uVar2 = uVar2 + 1 & 0xff;
            } while (uVar2 < param_2[2] + 3U >> 2);
          }
          param_2[2] = 0;
          memw();
          memw();
          *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40;
          return;
        }
        if (iVar1 == 0) {
          param_2[2] = uVar2;
          memw();
          memw();
          *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40;
          return;
        }
        puVar4 = (undefined4 *)param_2[1];
        param_2[1] = (int)(puVar4 + 1);
        uVar5 = *puVar4;
        memw();
        iVar3 = param_1;
        if ((iVar1 * 2 != 1) && ((iVar1 == 1 || (iVar1 * 2 != 1)))) {
          puVar4 = (undefined4 *)param_2[1];
          *(undefined4 *)(param_1 + 0x180) = uVar5;
          iVar3 = param_1 + 4;
          uVar5 = *puVar4;
          param_2[1] = (int)(puVar4 + 1);
          memw();
        }
        *(undefined4 *)(iVar3 + 0x180) = uVar5;
        param_2[2] = param_2[2] + iVar1 * -8;
        memw();
        memw();
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40;
        return;
      }
    }
    else {
      FUN_0020c714(param_1,param_2);
      if ((code *)param_2[4] != (code *)0x0) {
        (*(code *)param_2[4])(param_1,param_2,iVar1,param_2[5]);
        return;
      }
    }
  }
  return;
}


// ===== FUN_0020c92c @ 0020c92c (18 bytes)

void FUN_0020c92c(void)

{
  (*DAT_002385d8)(&FLEXSPI_MCR0,DAT_002385dc);
  return;
}


// ===== FUN_0020c940 @ 0020c940 (78 bytes)

void FUN_0020c940(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    iVar1 = *param_2;
    memw();
    if ((*(uint *)(iVar1 + 0xe0) & 2) == 0) goto LAB_0020c954;
    memw();
    uVar2 = *(uint *)(iVar1 + 0xe0);
    while ((uVar2 & 1) == 0) {
LAB_0020c954:
      do {
        memw();
      } while ((*(uint *)(iVar1 + 0xe0) & 2) == 0);
      memw();
      uVar2 = *(uint *)(iVar1 + 0xe0);
    }
    FUN_0020d01c(iVar1,param_2[1]);
    iVar1 = param_2[1];
    if (*(code **)(iVar1 + 0x18) != (code *)0x0) {
      (**(code **)(iVar1 + 0x18))(*param_2,iVar1,0,*(undefined4 *)(iVar1 + 0x1c));
    }
  }
  return;
}


// ===== FUN_0020c990 @ 0020c990 (54 bytes)

void FUN_0020c990(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = FUN_0020bb00(param_1);
  *(undefined4 *)(&DAT_00238c00 + iVar1 * 8) = param_1;
  *(undefined4 **)(&DAT_00238c04 + iVar1 * 8) = param_2;
  memset(param_2,0,0x20);
  *param_2 = param_5;
  param_2[1] = param_6;
  param_2[6] = param_3;
  param_2[7] = param_4;
  param_2[5] = 0;
  param_2[3] = 4;
  return;
}


// ===== FUN_0020c9c8 @ 0020c9c8 (7 bytes)

void FUN_0020c9c8(undefined4 param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0xc) = param_3;
  return;
}


// ===== FUN_0020c9d0 @ 0020c9d0 (1594 bytes)

undefined * FUN_0020c9d0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uStack_b0;
  uint uStack_ac;
  undefined *puStack_a8;
  byte bStack_a4;
  undefined1 auStack_a0 [24];
  undefined4 uStack_88;
  uint uStack_84;
  undefined *puStack_80;
  byte bStack_7c;
  undefined1 auStack_78 [24];
  uint uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  uint uStack_4c;
  int iStack_48;
  uint uStack_44;
  int iStack_40;
  uint uStack_3c;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  int iStack_28;
  
  if (param_2[5] != 0) {
    return &DAT_00001b58;
  }
  param_2[2] = param_3[5];
  iVar5 = param_3[1] * 4 + param_1;
  memw();
  memw();
  *(uint *)(iVar5 + 0x80) = *(uint *)(iVar5 + 0x80) | 0x80000000;
  memw();
  memw();
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x1e;
  memw();
  *(undefined4 *)(param_1 + 0xa0) = *param_3;
  memw();
  memw();
  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
  memw();
  memw();
  iVar5 = param_3[2];
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  if ((iVar5 == 2) || (iVar5 == 3)) {
    uVar4 = (uint)*(ushort *)(param_3 + 5);
  }
  else {
    uVar4 = 0;
  }
  memw();
  *(uint *)(param_1 + 0xa4) =
       uVar4 | (*(byte *)(param_3 + 3) & 0x1f) << 0x10 |
               (*(byte *)((int)param_3 + 0xd) - 1) * 0x1000000 & 0x7000000;
  if ((iVar5 != 3) && (iVar5 != 1)) {
    if (iVar5 != 2) {
      memw();
      memw();
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 1;
      memw();
      if ((*(uint *)(param_1 + 0xe0) & 2) == 0) goto LAB_0020caa0;
      memw();
      uVar4 = *(uint *)(param_1 + 0xe0);
      while ((uVar4 & 1) == 0) {
LAB_0020caa0:
        do {
          memw();
        } while ((*(uint *)(param_1 + 0xe0) & 2) == 0);
        memw();
        uVar4 = *(uint *)(param_1 + 0xe0);
      }
      memw();
      puVar1 = (undefined *)FUN_0020bb14(param_1,*(undefined4 *)(param_1 + 0x14));
      param_2[5] = 0;
      if ((code *)param_2[6] == (code *)0x0) {
        return puVar1;
      }
      (*(code *)param_2[6])(param_1,param_2,puVar1,param_2[7]);
      return puVar1;
    }
    param_2[5] = 1;
    iStack_40 = param_3[4];
    uVar6 = param_3[5];
    memw();
    uVar4 = (((*(uint *)(param_1 + 0xb8) & 0xfc) >> 2) + 1) * 8;
    uVar3 = uVar4 & 0xff;
    *(char *)((int)param_2 + 0x11) = (char)uVar4;
    if ((uVar3 - 1 & uVar3) != 0) {
      return (undefined *)0x4;
    }
    uStack_b0 = 0x12;
    uStack_3c = uVar6;
    if (uVar6 < uVar3) {
      param_2[3] = 1;
      uVar3 = uVar6 & 0xff;
      *(char *)(param_2 + 4) = (char)uVar6;
      uVar4 = 1;
      puStack_a8 = (undefined *)0x0;
      if ((uVar3 & uVar3 - 1) != 0) {
        uVar6 = (uVar3 & uVar3 - 1) << 1;
        uVar3 = uVar6 & 0xff;
        *(char *)(param_2 + 4) = (char)uVar6;
      }
      iVar5 = 1;
    }
    else {
      uStack_30 = uVar6 % uVar3;
      puStack_a8 = &DAT_00004000;
      if (uStack_30 == 0) {
        iVar5 = 1;
        uVar4 = param_2[3];
      }
      else {
        if ((uStack_30 & 3) == 0) {
          param_2[3] = 4;
          uVar4 = 4;
        }
        else {
          uVar4 = 1;
          if ((uStack_30 & 1) == 0) {
            uVar4 = 2;
          }
          param_2[3] = uVar4;
        }
        iVar5 = 2;
        uStack_3c = uVar6 - uStack_30;
      }
      uVar3 = uVar3 / (uVar4 & 0xff);
      *(char *)(param_2 + 4) = (char)uVar3;
      if (0x400 < ((uVar6 - *(byte *)((int)param_2 + 0x11)) + 1) / uVar4) {
        return (undefined *)0x4;
      }
      bStack_a4 = (byte)uStack_30;
    }
    uVar3 = uVar3 >> 1;
    if (uVar3 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0;
      do {
        uVar3 = uVar3 >> 1;
        uVar6 = uVar6 + 1;
      } while (uVar3 != 0);
    }
    uStack_ac = (uVar6 & 0xf) << 8 | 0x40;
    uVar3 = iVar5 + 0xffU & 0xff;
    if (uVar3 == 0) {
      iStack_38 = param_1 + 0x100;
      iVar5 = 0;
    }
    else {
      iStack_38 = param_1 + 0x100;
      uStack_30 = (uint)bStack_a4;
      uVar6 = 1;
      uVar4 = 9;
      do {
        uVar2 = param_2[3];
        if (uVar2 == 4) {
          uVar7 = 0x200;
        }
        else {
          uVar7 = (uVar2 - 1) * 0x100 & 0x300;
        }
        iStack_2c = uVar3 * 0x10 + 0x2387f0;
        uStack_60 = uVar3;
        FUN_0020a78c(iStack_2c,
                     (uStack_30 / uVar2 - 1) * 0x10000 & 0x3ff0000 | uVar7 | uVar4 | uVar6 << 4 |
                     (uint)&DAT_00005000,iStack_38,iStack_40 + uVar3 * uStack_3c);
        uVar6 = (uint)(iStack_2c == 0);
        uVar3 = uStack_60 - 1 & 0xff;
        uVar4 = uVar3;
        if (uVar6 != 0) {
          uVar4 = 9;
        }
      } while (uVar3 != 0);
      uVar4 = param_2[3];
      iVar5 = iStack_2c;
    }
    uStack_54 = 9;
    if (uVar4 == 4) {
      uStack_50 = 0x200;
    }
    else {
      uStack_50 = (uVar4 - 1) * 0x100 & 0x300;
    }
    FUN_0020ac54(auStack_a0,iStack_38,iStack_40,
                 (uStack_3c / uVar4 - 1) * 0x10000 & 0x3ff0000 | uStack_50 | 0x19 |
                 (uint)&DAT_00005000,0,&uStack_b0,iVar5);
    FUN_0020ad78(param_2[1],auStack_a0);
    iVar5 = FUN_0020bb00(param_1);
    FUN_0020ab28(param_2[1],FUN_0020c940,&DAT_00238c00 + iVar5 * 8);
    FUN_0020aed8(param_2[1]);
    memw();
    memw();
    *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 2;
    memw();
    memw();
    *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 1;
    return (undefined *)0x0;
  }
  uVar4 = param_2[3];
  uStack_4c = param_3[4];
  param_2[5] = 1;
  uVar3 = param_3[5];
  if ((uVar4 - 1 & uStack_4c) == 0) {
    memw();
    uVar6 = (((*(uint *)(param_1 + 0xbc) & 0x1fc) >> 2) + 1) * 8;
    uVar2 = uVar6 & 0xff;
    *(char *)((int)param_2 + 0x11) = (char)uVar6;
    if ((uVar2 - 1 & uVar2) == 0) {
      uStack_88 = 0x12;
      uStack_34 = uVar3;
      if (uVar3 < uVar2) {
        param_2[3] = 1;
        uVar2 = uVar3 & 0xff;
        *(char *)(param_2 + 4) = (char)uVar3;
        uVar4 = 1;
        puStack_80 = (undefined *)0x0;
        if ((uVar2 & uVar2 - 1) != 0) {
          uVar6 = (uVar2 & uVar2 - 1) << 1;
          uVar2 = uVar6 & 0xff;
          *(char *)(param_2 + 4) = (char)uVar6;
        }
        iVar5 = 1;
        uVar6 = 1;
      }
      else {
        uStack_44 = uVar3 % uVar2;
        puStack_80 = &DAT_00008000;
        if (uStack_44 == 0) {
          iVar5 = 1;
        }
        else {
          if ((uStack_44 & 3) == 0) {
            param_2[3] = 4;
            uVar4 = 4;
          }
          else {
            uVar4 = 1;
            if ((uStack_44 & 1) == 0) {
              uVar4 = 2;
            }
            param_2[3] = uVar4;
          }
          iVar5 = 2;
          uStack_34 = uVar3 - uStack_44;
        }
        uVar6 = uVar4 & 0xff;
        uVar2 = uVar2 / uVar6;
        *(char *)(param_2 + 4) = (char)uVar2;
        if (0x400 < ((uVar3 - *(byte *)((int)param_2 + 0x11)) + 1) / uVar4) {
          return (undefined *)0x4;
        }
        bStack_7c = (byte)uStack_44;
      }
      if (uVar3 / uVar6 != 1) {
        uVar2 = uVar2 >> 1;
        if (uVar2 == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = 0;
          do {
            uVar2 = uVar2 >> 1;
            uVar6 = uVar6 + 1;
          } while (uVar2 != 0);
        }
        uStack_84 = (uVar6 & 0xf) << 8 | 0x40;
        param_2[2] = uVar3;
        uVar3 = iVar5 + 0xffU & 0xff;
        if (uVar3 == 0) {
          iStack_48 = param_1 + 0x180;
          iVar5 = 0;
        }
        else {
          uStack_44 = (uint)bStack_7c;
          iStack_48 = param_1 + 0x180;
          uVar6 = 1;
          uVar4 = 9;
          do {
            uVar2 = param_2[3];
            if (uVar2 == 4) {
              uVar7 = 0x200;
            }
            else {
              uVar7 = (uVar2 - 1) * 0x100 & 0x300;
            }
            iStack_28 = uVar3 * 0x10 + 0x2387f0;
            uStack_5c = uVar3;
            FUN_0020a78c(iStack_28,
                         (uStack_44 / uVar2 - 1) * 0x10000 & 0x3ff0000 | uVar7 | uVar4 | uVar6 << 4
                         | (uint)&DAT_00005000,uStack_4c + uVar3 * uStack_34,iStack_48);
            uVar3 = uStack_5c - 1 & 0xff;
            uVar6 = (uint)(iStack_28 == 0);
            uVar4 = 0;
            if (uVar6 != 0) {
              uVar4 = 9;
            }
          } while (uVar3 != 0);
          uVar4 = param_2[3];
          iVar5 = iStack_28;
        }
        uStack_58 = 9;
        if (uVar4 == 4) {
          uVar3 = 0x200;
        }
        else {
          uVar3 = (uVar4 - 1) * 0x100 & 0x300;
        }
        FUN_0020ac54(auStack_78,uStack_4c,iStack_48,
                     (uStack_34 / uVar4 - 1) * 0x10000 & 0x3ff0000 | uVar3 | 0x19 |
                     (uint)&DAT_00005000,0,&uStack_88,iVar5);
        FUN_0020ad78(*param_2,auStack_78);
        iVar5 = FUN_0020bb00(param_1);
        FUN_0020ab28(*param_2,FUN_0020c940,&DAT_00238c00 + iVar5 * 8);
        FUN_0020aed8(*param_2);
        memw();
        memw();
        *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 2;
        memw();
        memw();
        *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 1;
        return (undefined *)0x0;
      }
    }
  }
  return (undefined *)0x4;
}


// ===== FUN_0020d01c @ 0020d01c (81 bytes)

void FUN_0020d01c(int param_1,undefined4 *param_2)

{
  memw();
  if ((*(uint *)(param_1 + 0xbc) & 2) != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffd;
    FUN_0020aa20(*param_2);
  }
  memw();
  if ((*(uint *)(param_1 + 0xb8) >> 1 & 1) == 0) {
    param_2[5] = 0;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffd;
  FUN_0020aa20(param_2[1]);
  param_2[5] = 0;
  return;
}


// ===== FUN_0020d070 @ 0020d070 (83 bytes)

undefined4 FUN_0020d070(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (param_2[5] != 1) {
    return 6;
  }
  memw();
  if ((*(uint *)(param_1 + 0xb8) & 2) == 0) {
    memw();
    if ((*(uint *)(param_1 + 0xbc) >> 1 & 1) != 0) {
      iVar1 = FUN_0020a73c(*(undefined4 *)(*param_2 + 8),*(undefined1 *)(*param_2 + 0xc));
      *param_3 = param_2[2] - iVar1;
      return 0;
    }
    return 0;
  }
  iVar1 = FUN_0020a73c(*(undefined4 *)(param_2[1] + 8),*(undefined1 *)(param_2[1] + 0xc));
  *param_3 = param_2[2] - iVar1;
  return 0;
}


// ===== FUN_0020d0d0 @ 0020d0d0 (44 bytes)

undefined4 FUN_0020d0d0(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  memw();
  uVar2 = (*param_1 & 0x7fffffff) - 2;
  if (0 < (int)uVar2) {
    uVar1 = __udivdi3(param_2 * uVar2,(int)((ulonglong)param_2 * (ulonglong)uVar2 >> 0x20),
                      &DAT_00100000,0);
    return uVar1;
  }
  return 0;
}


// ===== FUN_0020d100 @ 0020d100 (163 bytes)

void FUN_0020d100(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = (&PTR_DAT_002002a0)[param_2];
  uVar2 = (uint)puVar1 >> 8 & 0xff;
  if (uVar2 == 0) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 1) {
    memw();
    CLKCTL0_PSCCTL1_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 2) {
    memw();
    CLKCTL0_PSCCTL2_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 3) {
    memw();
    CLKCTL1_PSCCTL0_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 4) {
    memw();
    CLKCTL1_PSCCTL1_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 5) {
    memw();
    CLKCTL1_PSCCTL2_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  FUN_00213910((&PTR_DAT_002002c0)[param_2]);
  return;
}


// ===== FUN_0020d1a4 @ 0020d1a4 (267 bytes)

void FUN_0020d1a4(int param_1,int param_2,uint param_3,int *param_4)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = (&PTR_DAT_002002a0)[param_2];
  uVar2 = (uint)puVar1 >> 8 & 0xff;
  if (uVar2 == 0) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 1) {
    memw();
    CLKCTL0_PSCCTL1_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 2) {
    memw();
    CLKCTL0_PSCCTL2_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 3) {
    memw();
    CLKCTL1_PSCCTL0_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 4) {
    memw();
    CLKCTL1_PSCCTL1_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  else if (uVar2 == 5) {
    memw();
    CLKCTL1_PSCCTL2_SET = 1 << 0x20 - (0x20 - ((uint)puVar1 & 0x1f));
  }
  param_1 = param_2 * 4 + param_1;
  uVar2 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
  if (*param_4 != 0) {
    if ((char)param_4[1] != '\0') {
      memw();
      *(uint *)(&DAT_00002200 + param_1) = uVar2;
      memw();
      memw();
      *(uint *)(param_1 + 0x2000) = *(uint *)(param_1 + 0x2000) | uVar2;
      return;
    }
    memw();
    *(uint *)(&DAT_00002280 + param_1) = uVar2;
    memw();
    memw();
    *(uint *)(param_1 + 0x2000) = *(uint *)(param_1 + 0x2000) | uVar2;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x2000) = *(uint *)(param_1 + 0x2000) & (uVar2 ^ 0xffffffff);
  return;
}


// ===== FUN_0020d2b0 @ 0020d2b0 (80 bytes)

void FUN_0020d2b0(int param_1,int param_2,uint param_3,byte *param_4)

{
  int iVar1;
  uint uVar2;
  
  param_1 = param_2 * 4 + param_1;
  iVar1 = 0x20 - (param_3 & 0x1f);
  uVar2 = 1 << 0x20 - iVar1 ^ 0xffffffff;
  memw();
  memw();
  *(uint *)(&DAT_00002680 + param_1) =
       *(uint *)(&DAT_00002680 + param_1) & uVar2 | (uint)*param_4 << 0x20 - iVar1;
  memw();
  memw();
  *(uint *)(&DAT_00002600 + param_1) =
       *(uint *)(&DAT_00002600 + param_1) & uVar2 |
       (uint)param_4[1] << 0x20 - (0x20 - (param_3 & 0x1f));
  return;
}


// ===== FUN_0020d300 @ 0020d300 (62 bytes)

void FUN_0020d300(int param_1,int param_2,int param_3,uint param_4)

{
  if (param_3 == 0) {
    param_1 = param_2 * 4 + param_1;
    memw();
    memw();
    *(uint *)(&DAT_00002500 + param_1) = *(uint *)(&DAT_00002500 + param_1) | param_4;
    return;
  }
  if (param_3 != 1) {
    return;
  }
  param_1 = param_2 * 4 + param_1;
  memw();
  memw();
  *(uint *)(&DAT_00002580 + param_1) = *(uint *)(&DAT_00002580 + param_1) | param_4;
  return;
}


// ===== FUN_0020d340 @ 0020d340 (72 bytes)

void FUN_0020d340(int param_1,int param_2,int param_3,uint param_4)

{
  if (param_3 == 0) {
    param_1 = param_2 * 4 + param_1;
    memw();
    memw();
    *(uint *)(&DAT_00002500 + param_1) = *(uint *)(&DAT_00002500 + param_1) & (param_4 ^ 0xffffffff)
    ;
    return;
  }
  if (param_3 != 1) {
    return;
  }
  param_1 = param_2 * 4 + param_1;
  memw();
  memw();
  *(uint *)(&DAT_00002580 + param_1) = *(uint *)(&DAT_00002580 + param_1) & (param_4 ^ 0xffffffff);
  return;
}


// ===== FUN_0020d38c @ 0020d38c (43 bytes)

void FUN_0020d38c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    memw();
    *(undefined4 *)(&DAT_00002700 + param_2 * 4 + param_1) = param_4;
    return;
  }
  if (param_3 != 1) {
    return;
  }
  memw();
  *(undefined4 *)(&DAT_00002780 + param_2 * 4 + param_1) = param_4;
  return;
}


// ===== FUN_0020d3b8 @ 0020d3b8 (45 bytes)

undefined4 FUN_0020d3b8(int param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    memw();
    return *(undefined4 *)(&DAT_00002700 + param_2 * 4 + param_1);
  }
  if (param_3 != 1) {
    return 0;
  }
  memw();
  return *(undefined4 *)(&DAT_00002780 + param_2 * 4 + param_1);
}


// ===== FUN_0020d3e8 @ 0020d3e8 (78 bytes)

void FUN_0020d3e8(int param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0) {
    param_1 = param_2 * 4 + param_1;
    memw();
    memw();
    *(uint *)(&DAT_00002500 + param_1) =
         *(uint *)(&DAT_00002500 + param_1) | 1 << 0x20 - (0x20 - (param_3 & 0x1f));
    return;
  }
  if (param_4 != 1) {
    return;
  }
  param_1 = param_2 * 4 + param_1;
  memw();
  memw();
  *(uint *)(&DAT_00002580 + param_1) =
       *(uint *)(&DAT_00002580 + param_1) | 1 << 0x20 - (0x20 - (param_3 & 0x1f));
  return;
}


// ===== FUN_0020d438 @ 0020d438 (86 bytes)

void FUN_0020d438(int param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0) {
    param_1 = param_2 * 4 + param_1;
    memw();
    memw();
    *(uint *)(&DAT_00002500 + param_1) =
         *(uint *)(&DAT_00002500 + param_1) & (1 << 0x20 - (0x20 - (param_3 & 0x1f)) ^ 0xffffffffU);
    return;
  }
  if (param_4 != 1) {
    return;
  }
  param_1 = param_2 * 4 + param_1;
  memw();
  memw();
  *(uint *)(&DAT_00002580 + param_1) =
       *(uint *)(&DAT_00002580 + param_1) & (1 << 0x20 - (0x20 - (param_3 & 0x1f)) ^ 0xffffffffU);
  return;
}


// ===== FUN_0020d494 @ 0020d494 (59 bytes)

void FUN_0020d494(int param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0) {
    memw();
    *(int *)(&DAT_00002700 + param_2 * 4 + param_1) = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
    return;
  }
  if (param_4 != 1) {
    return;
  }
  memw();
  *(int *)(&DAT_00002780 + param_2 * 4 + param_1) = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
  return;
}


// ===== FUN_0020d4d0 @ 0020d4d0 (13 bytes)

void FUN_0020d4d0(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x808) = param_2;
  return;
}


// ===== FUN_0020d4e0 @ 0020d4e0 (13 bytes)

void FUN_0020d4e0(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x80c) = param_2;
  return;
}


// ===== FUN_0020d4f0 @ 0020d4f0 (30 bytes)

bool FUN_0020d4f0(dword *param_1)

{
  return param_1 != &USART0_CFG;
}


// ===== FUN_0020d510 @ 0020d510 (32 bytes)

void FUN_0020d510(undefined4 *param_1)

{
  param_1[1] = &DAT_000186a0;
  *param_1 = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((int)param_1 + 9) = 0x23;
  return;
}


// ===== FUN_0020d584 @ 0020d584 (28 bytes)

void FUN_0020d584(int param_1)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x800) = *(uint *)(param_1 + 0x800) & 0x1e;
  return;
}


// ===== FUN_0020d5a0 @ 0020d5a0 (100 bytes)

uint FUN_0020d5a0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  uVar2 = *(uint *)(param_1 + 0x804) & 0xe;
  if (uVar2 == 0) {
    uVar2 = *(uint *)(param_1 + 0x804) | 0x20;
  }
  uVar1 = uVar2 & 0xffffff71 | 0x500080;
  if ((uVar2 & 0x3000) == 0x3000) {
    uVar1 = uVar2 & 0xffdfcf71 | 0x700080;
  }
  return uVar1;
}


// ===== FUN_0020d604 @ 0020d604 (203 bytes)

void FUN_0020d604(int param_1,uint param_2,uint param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = (undefined *)(((param_3 * 10) / (uint)&DAT_001e8480 + 5) / 10);
  if ((param_3 / (uint)puVar1) / param_2 < 4) {
    puVar1 = (undefined *)((param_3 >> 2) / param_2);
  }
  if (&DAT_00010000 < puVar1) {
    uVar3 = 0;
    puVar4 = (undefined *)0x0;
  }
  else {
    uVar3 = 0;
    if (puVar1 == &DAT_00010000) {
      isync();
    }
    puVar4 = (undefined *)0x0;
    if (puVar1 != &DAT_00010001) {
      uVar3 = ((param_3 * 10) / (param_2 * (int)puVar1) + 5) / 10;
      uVar3 = (uVar3 < 0x12) * uVar3 + (uint)(uVar3 >= 0x12) * 0x12;
      puVar4 = puVar1;
    }
  }
  uVar2 = ae_zext16(puVar4 + -1);
  memw();
  *(undefined4 *)(param_1 + 0x814) = uVar2;
  uVar5 = (uVar3 >> 1) - 2;
  uVar6 = uVar5 * 0x10 & 0x70;
  if ((uVar3 & 1) != 0) {
    memw();
    *(uint *)(param_1 + 0x824) = uVar6 | (uVar3 >> 1) - 1 & 7;
    return;
  }
  memw();
  *(uint *)(param_1 + 0x824) = uVar6 | uVar5 & 7;
  return;
}


// ===== FUN_0020d6d0 @ 0020d6d0 (48 bytes)

void FUN_0020d6d0(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(((uint)(param_2 * param_3) / 0x640 + 5) / 10);
  memw();
  *(uint *)(param_1 + 0x810) =
       ((uint)(&DAT_00001000 < puVar1) * (int)&DAT_00001000 +
        (uint)(&DAT_00001000 >= puVar1) * (int)puVar1 + -1) * 0x10 | 0xf;
  return;
}


// ===== FUN_0020d700 @ 0020d700 (71 bytes)

undefined1  [12] FUN_0020d700(int param_1)

{
  uint uVar1;
  undefined1 auVar2 [12];
  undefined4 uVar3;
  
  do {
    uVar1 = FUN_0020d5a0(param_1);
  } while ((uVar1 & 1) == 0);
  uVar3 = 0;
  if ((uVar1 >> 6 & 1) != 0) {
    uVar3 = 0xa30;
  }
  memw();
  *(undefined4 *)(param_1 + 0x804) = 0x3000050;
  auVar2._4_4_ = 0xa35;
  auVar2._0_4_ = uVar3;
  auVar2._8_4_ = 0xa34;
  return auVar2;
}


// ===== FUN_0020d748 @ 0020d748 (107 bytes)

int FUN_0020d748(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  do {
    uVar1 = FUN_0020d5a0(param_1);
  } while ((uVar1 & 1) == 0);
  iVar2 = 0;
  if ((uVar1 >> 6 & 1) != 0) {
    iVar2 = 0xa30;
  }
  memw();
  *(undefined4 *)(param_1 + 0x804) = 0x3000050;
  if (iVar2 != 0) {
    return iVar2;
  }
  memw();
  *(uint *)(param_1 + 0x828) = param_3 & 1 | param_2 << 1;
  memw();
  *(undefined4 *)(param_1 + 0x820) = 2;
  return 0;
}


// ===== FUN_0020d7b4 @ 0020d7b4 (90 bytes)

undefined1  [12] FUN_0020d7b4(int param_1)

{
  uint uVar1;
  undefined1 auVar2 [12];
  int iVar3;
  
  do {
    uVar1 = FUN_0020d5a0(param_1);
  } while ((uVar1 & 1) == 0);
  iVar3 = 0;
  if ((uVar1 >> 6 & 1) != 0) {
    iVar3 = 0xa30;
  }
  memw();
  *(undefined4 *)(param_1 + 0x804) = 0x3000050;
  if (iVar3 != 0) {
    auVar2._4_4_ = 0xa35;
    auVar2._0_4_ = iVar3;
    auVar2._8_4_ = 0xa34;
    return auVar2;
  }
  memw();
  *(undefined4 *)(param_1 + 0x820) = 4;
  return ZEXT812(0xa3400000a35) << 0x20;
}


// ===== FUN_0020d814 @ 0020d814 (223 bytes)

/* WARNING: Removing unreachable block (ram,0x0020d8c3) */

int FUN_0020d814(int param_1,byte *param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 != 0) {
    do {
      do {
        uVar1 = FUN_0020d5a0(param_1);
        iVar2 = 0;
        if ((uVar1 >> 0x19 & 1) != 0) {
          iVar2 = 0xa35;
        }
      } while ((uVar1 & 1) == 0);
      if ((uVar1 >> 4 & 1) != 0) {
        iVar2 = 0xa2d;
      }
      if ((uVar1 >> 6 & 1) != 0) {
        iVar2 = 0xa30;
      }
      memw();
      *(undefined4 *)(param_1 + 0x804) = 0x3000050;
      if (iVar2 != 0) {
        return iVar2;
      }
      memw();
      uVar1 = (*(uint *)(param_1 + 0x804) & 0xe) >> 1;
      if (uVar1 != 2) {
        if ((uVar1 != 3) && (uVar1 != 4)) {
          return 0xa31;
        }
        FUN_0020d7b4(param_1);
        return 0xa2a;
      }
      memw();
      *(uint *)(param_1 + 0x828) = (uint)*param_2;
      memw();
      *(undefined4 *)(param_1 + 0x820) = 1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  iVar2 = FUN_0020d700(param_1);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((param_4 >> 2 & 1) == 0) {
    memw();
    *(undefined4 *)(param_1 + 0x820) = 4;
    iVar2 = FUN_0020d700(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  return 0;
}


// ===== FUN_0020d8f4 @ 0020d8f4 (268 bytes)

int FUN_0020d8f4(int param_1,undefined1 *param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *local_30;
  
  if (param_3 != 0) {
    iVar3 = param_1 + 0x608;
    local_30 = param_2;
    do {
      do {
        uVar1 = FUN_0020d5a0(param_1);
        if ((uVar1 >> 0x18 & 1) != 0) {
          iVar3 = 0xa34;
        }
      } while ((uVar1 & 1) == 0);
      if ((uVar1 >> 4 & 1) != 0) {
        iVar3 = 0xa2d;
      }
      iVar2 = iVar3;
      if ((uVar1 >> 6 & 1) != 0) {
        iVar2 = 0xa30;
      }
      memw();
      *(undefined4 *)(param_1 + 0x804) = 0x3000050;
      if (iVar2 != 0) {
        return iVar2;
      }
      memw();
      uVar1 = (*(uint *)(param_1 + 0x804) & 0xe) >> 1;
      if (uVar1 != 1) {
        if ((uVar1 != 3) && (uVar1 != 4)) {
          return 0xa31;
        }
        return 0xa2a;
      }
      memw();
      *local_30 = (char)*(undefined4 *)(param_1 + 0x828);
      local_30 = local_30 + 1;
      param_3 = param_3 + -1;
      if (param_3 == 0) {
        iVar2 = 0;
        if ((param_4 & 4) == 0) {
          memw();
          *(undefined4 *)(param_1 + 0x820) = 4;
          do {
            uVar1 = FUN_0020d5a0(param_1);
            iVar3 = 0;
            if ((uVar1 >> 0x19 & 1) != 0) {
              iVar3 = 0xa35;
            }
          } while ((uVar1 & 1) == 0);
          if ((uVar1 >> 4 & 1) != 0) {
            iVar3 = 0xa2d;
          }
          iVar2 = iVar3;
          if ((uVar1 >> 6 & 1) != 0) {
            iVar2 = 0xa30;
          }
          memw();
          *(undefined4 *)(param_1 + 0x804) = 0x3000050;
        }
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      else {
        memw();
        *(undefined4 *)(param_1 + 0x820) = 1;
      }
    } while (param_3 != 0);
  }
  return 0;
}


// ===== FUN_0020da04 @ 0020da04 (109 bytes)

undefined1  [12] FUN_0020da04(int param_1)

{
  uint uVar1;
  undefined1 auVar2 [12];
  undefined1 auVar3 [12];
  int iVar4;
  
  do {
    uVar1 = FUN_0020d5a0(param_1);
  } while ((uVar1 & 1) == 0);
  iVar4 = param_1 + 0x600;
  if ((uVar1 >> 6 & 1) != 0) {
    iVar4 = 0xa30;
  }
  memw();
  *(undefined4 *)(param_1 + 0x804) = 0x3000050;
  if (iVar4 != 0) {
    auVar2._4_4_ = 0xa35;
    auVar2._0_4_ = iVar4;
    auVar2._8_4_ = 0xa34;
    return auVar2;
  }
  memw();
  if ((*(uint *)(param_1 + 0x804) & 0xe) != 6) {
    return ZEXT812(0xa3400000a35) << 0x20;
  }
  FUN_0020d7b4(param_1);
  auVar3._8_4_ = 0xa34;
  auVar3._0_8_ = 0xa3500000a33;
  return auVar3;
}


// ===== FUN_0020da74 @ 0020da74 (271 bytes)

int FUN_0020da74(undefined4 param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_32 [50];
  
  iVar2 = 0;
  if ((*param_2 & 1) == 0) {
    uVar4 = 0;
    if (param_2[4] == 0) {
      uVar4 = param_2[2];
    }
    iVar2 = FUN_0020d748(param_1,(char)param_2[1],uVar4);
    if (iVar2 != 0) goto LAB_0020daa0;
    iVar2 = FUN_0020da04(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar4 = param_2[4];
    iVar2 = 0;
    if (uVar4 != 0) {
      uVar5 = param_2[3];
      if (-1 < (int)(uVar4 - 1)) {
        puVar3 = auStack_32 + uVar4 + 1;
        if ((uVar4 & 1) != 0) {
          puVar3 = auStack_32 + uVar4;
          auStack_32[uVar4 + 1] = (char)uVar5;
          uVar5 = uVar5 >> 8;
        }
        uVar4 = uVar4 >> 1;
        if ((uVar4 != 0) && ((uVar4 == 1 || (uVar4 != 0)))) {
          *puVar3 = (char)uVar5;
          puVar3[-1] = (char)(uVar5 >> 8);
        }
        uVar4 = param_2[4];
      }
      iVar2 = FUN_0020d814(param_1,auStack_32 + 2,uVar4,4);
      if (iVar2 == 0) {
        if (param_2[2] == 1) {
          iVar2 = FUN_0020d748(param_1,(char)param_2[1]);
          if (iVar2 != 0) goto LAB_0020daa0;
          iVar1 = FUN_0020da04(param_1);
          iVar2 = 0;
          if (iVar1 != 0) {
            return iVar1;
          }
        }
      }
      else if (iVar2 == 0xa2a) {
        FUN_0020d7b4(param_1);
        return 0xa33;
      }
    }
    if (iVar2 != 0) goto LAB_0020daa0;
  }
  if ((param_2[2] == 0) && (param_2[6] != 0)) {
    iVar2 = FUN_0020d814(param_1,param_2[5],param_2[6],*param_2);
  }
  else if ((param_2[2] == 1) && (param_2[6] != 0)) {
    iVar2 = FUN_0020d8f4(param_1,param_2[5],param_2[6],*param_2);
  }
LAB_0020daa0:
  if (iVar2 == 0xa2a) {
    FUN_0020d7b4(param_1);
    return 0xa2a;
  }
  return iVar2;
}


// ===== FUN_0020db88 @ 0020db88 (47 bytes)

void FUN_0020db88(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  memset(param_2,0,0x40);
  FUN_0020d4f0(param_1);
  *(undefined4 *)(param_2 + 0x38) = param_3;
  *(undefined4 *)(param_2 + 0x3c) = param_4;
  FUN_0020b8e4(param_1,FUN_0020dd40,param_2);
  FUN_0020d4e0(param_1,0x3000051);
  return;
}


// ===== FUN_0020dbb8 @ 0020dbb8 (245 bytes)

undefined4 FUN_0020dbb8(int param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  
  if (*param_2 != '\0') {
    return 0xa28;
  }
  FUN_0020d4e0(param_1,0x3000051);
  memcpy(param_2 + 0x1c,param_3,0x1c);
  param_2[4] = '\0';
  param_2[5] = '\0';
  param_2[6] = '\0';
  param_2[7] = '\0';
  param_2[0x10] = '\0';
  param_2[0x11] = '\0';
  param_2[0x12] = '\0';
  param_2[0x13] = '\0';
  param_2[0x18] = '\0';
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_2 + 0x30);
  *(int *)(param_2 + 8) = *(int *)(param_2 + 0x34);
  if ((*(uint *)(param_2 + 0x1c) & 1) == 0) {
    uVar2 = *(uint *)(param_2 + 0x2c);
    if (uVar2 != 0) {
      if (4 < uVar2) {
LAB_0020dc07:
        uVar1 = 0xa2b;
        goto LAB_0020dc80;
      }
      uVar4 = *(uint *)(param_3 + 0x10);
      uVar5 = *(uint *)(param_3 + 0xc);
      if (-1 < (int)(uVar4 - 1)) {
        pcVar3 = param_2 + (uVar4 - 1);
        if ((uVar4 & 7) != 0) {
          pcVar3[0x14] = (char)uVar5;
          pcVar3 = pcVar3 + -1;
          uVar5 = uVar5 >> 8;
        }
        if (0 < (int)uVar4 >> 3) {
          pcVar3[0x14] = (char)uVar5;
          pcVar3[0x13] = (char)(uVar5 >> 8);
          pcVar3[0x12] = (char)(uVar5 >> 0x10);
          pcVar3[0x11] = (char)(uVar5 >> 0x18);
          pcVar3[0x10] = '\0';
          pcVar3[0xf] = '\0';
          pcVar3[0xe] = '\0';
          pcVar3[0xd] = '\0';
        }
        uVar2 = *(uint *)(param_2 + 0x2c);
      }
      *(uint *)(param_2 + 0x10) = uVar2;
    }
    param_2[0x18] = '\x01';
    *param_2 = '\x06';
  }
  else if (*(int *)(param_2 + 0x34) == 0) {
    *param_2 = '\a';
  }
  else if (*(int *)(param_2 + 0x24) == 0) {
    *param_2 = '\x02';
  }
  else {
    if (*(int *)(param_2 + 0x24) != 1) goto LAB_0020dc07;
    *param_2 = '\x03';
  }
  uVar1 = 0;
LAB_0020dc80:
  memw();
  *(undefined4 *)(param_1 + 0x804) = 0x50;
  FUN_0020d4d0(param_1,0x3000051);
  return uVar1;
}


// ===== FUN_0020dcb0 @ 0020dcb0 (34 bytes)

undefined4 FUN_0020dcb0(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 4;
  }
  if (*param_2 != '\0') {
    *param_3 = *(undefined4 *)(param_2 + 4);
    return 0;
  }
  *param_3 = 0;
  return 6;
}


// ===== FUN_0020dcd4 @ 0020dcd4 (105 bytes)

int FUN_0020dcd4(int param_1,char *param_2)

{
  int iVar1;
  
  if (*param_2 == '\0') {
    return 0;
  }
  FUN_0020d4e0(param_1,0x3000051);
  iVar1 = FUN_0020d700(param_1);
  if (iVar1 != 0) {
    *param_2 = '\0';
    return iVar1;
  }
  memw();
  if ((*(uint *)(param_1 + 0x804) & 0xe) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x820) = 4;
    iVar1 = FUN_0020d700(param_1);
    if (iVar1 != 0) {
      *param_2 = '\0';
      return iVar1;
    }
  }
  *param_2 = '\0';
  param_2[0x18] = '\0';
  return 0;
}


// ===== FUN_0020dd40 @ 0020dd40 (673 bytes)

void FUN_0020dd40(int param_1,char *param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  char cVar7;
  
  bVar2 = true;
  if (param_2 == (char *)0x0) {
    return;
  }
  if (((*param_2 != '\b') || (*(int *)(param_2 + 8) != 0)) &&
     ((*param_2 != '\a' || (*(int *)(param_2 + 8) != 0)))) {
    bVar2 = false;
  }
  uVar3 = FUN_0020d5a0(param_1);
  if ((uVar3 >> 4 & 1) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x804) = 0x10;
    uVar4 = 0xa2d;
    goto LAB_0020dd77;
  }
  if ((uVar3 >> 6 & 1) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x804) = 0x40;
    uVar4 = 0xa30;
    goto LAB_0020dd77;
  }
  if ((uVar3 & 0x1000000) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x804) = 0x1000000;
    uVar4 = 0xa34;
    goto LAB_0020dd77;
  }
  if ((uVar3 >> 0x19 & 1) != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x804) = 0x2000000;
    uVar4 = 0xa35;
    goto LAB_0020dd77;
  }
  if ((uVar3 & 1) == 0) {
    uVar4 = 0xa28;
    goto LAB_0020dd77;
  }
  memw();
  uVar3 = (*(uint *)(param_1 + 0x804) & 0xe) >> 1;
  if (((uVar3 == 3) || (uVar3 == 4)) && (!bVar2)) {
    memw();
    *(undefined4 *)(param_1 + 0x820) = 4;
    *param_2 = '\b';
    if ((uVar3 == 3) || (param_2[0x18] != '\0')) {
      uVar4 = 0xa33;
    }
    else {
      uVar4 = 0xa2a;
    }
    goto LAB_0020dd77;
  }
  cVar7 = *param_2;
  cVar5 = '\x02';
  if (cVar7 == '\x06') {
    uVar3 = (uint)(byte)param_2[0x20] << 1;
    if (*(int *)(param_2 + 0x10) != 0) {
      memw();
      *(uint *)(param_1 + 0x828) = uVar3;
      *param_2 = '\x01';
      memw();
      *(undefined4 *)(param_1 + 0x820) = 2;
      return;
    }
    iVar6 = *(int *)(param_2 + 8);
    if (*(int *)(param_2 + 0x24) == 0) {
      memw();
      *(uint *)(param_1 + 0x828) = uVar3;
      cVar7 = '\0';
      if (iVar6 != 0) {
        cVar7 = '\x02';
      }
      *param_2 = cVar7;
      memw();
      *(undefined4 *)(param_1 + 0x820) = 2;
      return;
    }
    memw();
    *(uint *)(param_1 + 0x828) = uVar3 | 1;
    cVar7 = '\0';
    if (iVar6 != 0) {
      cVar7 = '\x04';
    }
    *param_2 = cVar7;
    memw();
    *(undefined4 *)(param_1 + 0x820) = 2;
    return;
  }
  if (cVar7 == '\x01') {
    if (uVar3 == 2) {
      iVar6 = *(int *)(param_2 + 0x10);
      memw();
      *(uint *)(param_1 + 0x828) = (uint)(byte)param_2[(*(int *)(param_2 + 0x2c) - iVar6) + 0x14];
      memw();
      *(undefined4 *)(param_1 + 0x820) = 1;
      iVar6 = iVar6 + -1;
      *(int *)(param_2 + 0x10) = iVar6;
      if (iVar6 != 0) {
        return;
      }
      if (*(int *)(param_2 + 8) == 0) {
        *param_2 = '\a';
        return;
      }
      if (*(int *)(param_2 + 0x24) == 1) {
        cVar5 = '\x06';
      }
      *param_2 = cVar5;
      return;
    }
  }
  else if (cVar7 == '\x02') {
    param_2[0x18] = '\0';
    if (uVar3 == 2) {
      bVar1 = **(byte **)(param_2 + 0xc);
      *(byte **)(param_2 + 0xc) = *(byte **)(param_2 + 0xc) + 1;
      memw();
      *(uint *)(param_1 + 0x828) = (uint)bVar1;
      memw();
      iVar6 = *(int *)(param_2 + 8);
      *(undefined4 *)(param_1 + 0x820) = 1;
      *(int *)(param_2 + 8) = iVar6 + -1;
      if (iVar6 + -1 == 0) {
        *param_2 = '\a';
        *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
        return;
      }
      *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
      return;
    }
  }
  else if (cVar7 == '\x03') {
    param_2[0x18] = '\0';
    if (uVar3 == 1) {
      memw();
      memw();
      *(undefined4 *)(param_1 + 0x820) = 1;
      *param_2 = '\x04';
      return;
    }
  }
  else {
    if (cVar7 != '\x04') {
      if (cVar7 == '\a') {
        param_2[0x18] = '\0';
        if ((*(uint *)(param_2 + 0x1c) >> 2 & 1) == 0) {
          memw();
          *(undefined4 *)(param_1 + 0x820) = 4;
          *param_2 = '\b';
          return;
        }
      }
      else if (cVar7 != '\b') goto LAB_0020de4c;
      *param_2 = '\0';
      uVar4 = 0;
      goto LAB_0020dd77;
    }
    param_2[0x18] = '\0';
    if (uVar3 == 1) {
      memw();
      **(undefined1 **)(param_2 + 0xc) = (char)*(undefined4 *)(param_1 + 0x828);
      iVar6 = *(int *)(param_2 + 8);
      *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
      *(int *)(param_2 + 8) = iVar6 + -1;
      if (iVar6 + -1 != 0) {
        memw();
        *(undefined4 *)(param_1 + 0x820) = 1;
        *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
        return;
      }
      if ((*(uint *)(param_2 + 0x1c) & 4) != 0) {
        *param_2 = '\b';
        *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
        return;
      }
      memw();
      *(undefined4 *)(param_1 + 0x820) = 4;
      *param_2 = '\b';
      *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 1;
      return;
    }
  }
LAB_0020de4c:
  uVar4 = 0xa31;
LAB_0020dd77:
  *param_2 = '\0';
  FUN_0020d4e0(param_1,0x3000051);
  if (*(code **)(param_2 + 0x38) == (code *)0x0) {
    return;
  }
  (**(code **)(param_2 + 0x38))(param_1,param_2,uVar4,*(undefined4 *)(param_2 + 0x3c));
  return;
}


// ===== FUN_0020dfe8 @ 0020dfe8 (102 bytes)

void FUN_0020dfe8(undefined4 param_1,int param_2,uint param_3)

{
  memw();
  memw();
  *(uint *)(param_2 + 4) = param_3;
  if ((*(int *)(param_2 + 0x30) != 0) && ((*(uint *)(param_2 + 0xc) & param_3) != 0)) {
    (**(code **)(param_2 + 0x30))(param_1,param_2,*(undefined4 *)(param_2 + 0x34));
    memw();
    memw();
    memw();
    if ((*(char *)(param_2 + 0x28) == '\0') &&
       (((memw(), *(int *)(param_2 + 0x14) != 0 && (*(int *)(param_2 + 0x18) != 0)) ||
        ((memw(), *(int *)(param_2 + 0x10) != 0 && (*(int *)(param_2 + 0x1c) != 0)))))) {
      memw();
      *(undefined1 *)(param_2 + 0x28) = 1;
    }
    if ((param_3 == 4) || (param_3 == 2)) {
      memw();
      *(undefined4 *)(param_2 + 0x20) = 0;
      return;
    }
  }
  return;
}


// ===== FUN_0020e050 @ 0020e050 (119 bytes)

undefined4 FUN_0020e050(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  memw();
  iVar2 = *param_2;
  FUN_0020d4e0(param_1,&DAT_00008100);
  uVar1 = 0;
  memw();
  if (*(char *)(iVar2 + 0x28) != '\0') {
    uVar1 = 0xa28;
  }
  memw();
  *(undefined4 *)(iVar2 + 0x14) = param_3;
  memw();
  *(undefined4 *)(iVar2 + 0x18) = param_4;
  memw();
  *(undefined4 *)(iVar2 + 0x10) = 0;
  memw();
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  memw();
  *(undefined4 *)(iVar2 + 0x20) = 0;
  memw();
  *(uint *)(iVar2 + 0xc) = param_5 | 6;
  memw();
  *(undefined1 *)(iVar2 + 0x28) = 1;
  memw();
  *(undefined4 *)(param_1 + 0x800) = 2;
  memw();
  memw();
  *(undefined4 *)(param_1 + 0x804) = *(undefined4 *)(param_1 + 0x804);
  FUN_0020d4d0(param_1,&DAT_00008100);
  return uVar1;
}

