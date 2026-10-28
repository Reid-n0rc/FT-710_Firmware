// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2013a394 @ 2013a394 (176 bytes)

undefined4 FUN_2013a394(int param_1)

{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  do {
    bVar2 = false;
    uVar1 = *(ushort *)(*(int *)(param_1 + 8) + 0x46);
    uVar6 = (uint)uVar1;
    *(ushort *)(*(int *)(param_1 + 8) + 0x46) = ~uVar1;
    iVar5 = 0;
    do {
      if ((uVar6 & 1) != 0) {
        iVar4 = param_1 + iVar5 * 0x70;
        if (*(int *)(iVar4 + 0x58) != 0) {
          bVar2 = true;
          if (*(int *)(iVar4 + 0x94) == 0) {
            *(undefined4 *)(iVar4 + 0x84) = 0;
            FUN_20139f6c(param_1,iVar5);
          }
          else {
            FUN_2013a198(param_1,iVar5);
          }
        }
      }
      iVar5 = iVar5 + 1;
      uVar6 = uVar6 >> 1;
    } while (iVar5 < 10);
  } while (bVar2);
  uVar3 = FUN_2013b524();
  *(ushort *)(*(int *)(param_1 + 8) + 0x30) = *(ushort *)(*(int *)(param_1 + 8) + 0x30) | 0x100;
  thunk_FUN_20152d28(uVar3);
  return 0;
}


// ===== FUN_2013a444 @ 2013a444 (120 bytes)

void FUN_2013a444(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint local_4;
  
  if (param_1 < 0) {
    do {
      FUN_201525f8(0xffffffff);
    } while( true );
  }
  uVar2 = *(undefined4 *)(&DAT_2090b680 + param_1 * 0x4d8);
  do {
    while( true ) {
      iVar1 = itron_twai_flg(uVar2,0xffff,1,&local_4,0xffffffff);
      if (iVar1 == 0) break;
      itron_dly_tsk(200);
    }
    if ((local_4 & 1) != 0) {
      FUN_2013a394(&DAT_2090b660 + param_1 * 0x4d8);
    }
  } while( true );
}


// ===== FUN_2013a4bc @ 2013a4bc (384 bytes)

/* WARNING: Removing unreachable block (ram,0x2013a564) */
/* WARNING: Removing unreachable block (ram,0x2013a604) */

undefined4 FUN_2013a4bc(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  param_1 = param_1 * 0x4d8;
  iVar6 = (&DAT_204201b0)[param_2 * 7];
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) & 0xffef;
  itron_dly_tsk(10);
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) | 0x40;
  itron_dly_tsk(10);
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) & 0xffbf | 0x10;
  itron_dly_tsk(2);
  uVar2 = FUN_2014e1ec();
  uVar3 = uVar2;
  do {
    while( true ) {
      iVar4 = FUN_2014e1ec(uVar3);
      if (9 < iVar4 - uVar2) {
        FUN_2013b524();
        *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) =
             *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6) & 0xffef;
        *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[param_2 * 7]) =
             *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[param_2 * 7]) | 0x800;
        thunk_FUN_20152d28();
        return 7;
      }
      uVar1 = *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + iVar6);
      uVar3 = (uint)uVar1;
      if (((uVar1 & 4) == 0) && (uVar5 = uVar3 & 7, (uVar1 & 7) != 0)) break;
      uVar3 = itron_dly_tsk();
    }
    if (uVar5 == 1) {
      uVar7 = 2;
      goto LAB_2013a5c8;
    }
    if (uVar5 == 2) {
      uVar7 = 1;
      goto LAB_2013a5c8;
    }
  } while (uVar5 != 3);
  uVar7 = 0;
LAB_2013a5c8:
  FUN_2013b524();
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a8)[param_2 * 7]) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a8)[param_2 * 7]) & 0xefff;
  *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[param_2 * 7]) =
       *(ushort *)(*(int *)(&DAT_2090b668 + param_1) + (&DAT_204201a4)[param_2 * 7]) | 0x1000;
  thunk_FUN_20152d28();
  return uVar7;
}


// ===== FUN_2013a63c @ 2013a63c (84 bytes)

void FUN_2013a63c(int param_1,byte *param_2,uint *param_3,byte *param_4,ushort *param_5,
                 undefined1 *param_6)

{
  *param_3 = *(byte *)(param_1 + 2) & 0x80;
  *param_4 = *(byte *)(param_1 + 2) & 0x1f;
  *param_2 = *(byte *)(param_1 + 3) & 3;
  *param_5 = (ushort)*(byte *)(param_1 + 4) + (ushort)*(byte *)(param_1 + 5) * 0x100 & 0x7ff;
  *param_6 = *(undefined1 *)(param_1 + 6);
  return;
}


// ===== FUN_2013a690 @ 2013a690 (264 bytes)

undefined4 FUN_2013a690(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  ushort uVar9;
  
  if (param_1 != 0) {
    iVar7 = *(int *)(param_1 + 8);
    if (iVar7 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      iVar3 = *(int *)(param_1 + 0xc);
      iVar2 = *(int *)(iVar7 + 8);
      uVar1 = *(undefined4 *)(param_1 + 0x14);
      iVar4 = *(int *)(&DAT_20420118 + iVar3 * 4);
      *(short *)(*(int *)(iVar2 + 8) + 100) = (short)iVar3;
      iVar6 = *(int *)(param_1 + 0x1c);
      if (iVar6 == 0) {
        uVar8 = 0x4000;
      }
      else {
        uVar8 = 0x8000;
      }
      if (*(int *)(param_1 + 0x18) == 0) {
        uVar9 = 0x10;
      }
      else {
        uVar9 = 0;
      }
      if (iVar6 != 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0x180;
      }
      if ((iVar6 == 0) && (*(int *)(param_1 + 0x18) != 0)) {
        *(ushort *)(*(int *)(iVar2 + 8) + iVar4) = *(ushort *)(*(int *)(iVar2 + 8) + iVar4) | 0x200;
      }
      *(ushort *)(*(int *)(iVar2 + 8) + 0x68) = uVar8 | uVar9 | (ushort)uVar1 | uVar5;
      if (*(int *)(param_1 + 0x1c) != 0) {
        *(ushort *)(*(int *)(iVar2 + 8) + 0x6e) = (ushort)*(byte *)(param_1 + 0x20);
      }
      *(ushort *)(*(int *)(iVar2 + 8) + 0x6c) =
           *(ushort *)(param_1 + 0x2c) | (ushort)*(byte *)(iVar7 + 0xc) << 0xc;
      *(undefined2 *)(*(int *)(iVar2 + 8) + (&DAT_20420144)[iVar3]) = 0x100;
      FUN_2014eb94(*(undefined4 *)(param_1 + 0x24),0);
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(iVar7 + 0xc);
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0xffffffff;
}


// ===== FUN_2013a798 @ 2013a798 (300 bytes)

int FUN_2013a798(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort local_30 [2];
  char local_2c [4];
  undefined4 local_28;
  byte local_24 [4];
  byte local_20 [8];
  
  if (param_1 == 0) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 8);
  FUN_2013a63c(param_2,local_2c,&local_28,local_24,local_30,local_20);
  if (param_3 <= param_4) {
    do {
      iVar2 = iVar4 + param_3 * 0x70;
      if ((*(int *)(iVar2 + 0x50) == 0) && ((int)(uint)local_30[0] <= *(int *)(iVar2 + 0x68))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        *(int *)(iVar2 + 0x48) = param_1;
        *(undefined4 *)(iVar2 + 0x50) = 1;
        *(uint *)(iVar2 + 0x54) = (uint)local_24[0];
        *(undefined4 *)(iVar2 + 0x58) = local_28;
        *(uint *)(iVar2 + 0x6c) = (uint)local_30[0];
        if (local_2c[0] == '\x03') {
          iVar4 = 2;
          iVar3 = 0;
          goto LAB_2013a8a0;
        }
        *(undefined1 *)(iVar2 + 0x60) = 0;
        *(undefined4 *)(iVar2 + 0x5c) = 0;
        goto LAB_2013a85c;
      }
      param_3 = param_3 + 1;
    } while (param_3 <= param_4);
  }
  return 0;
  while( true ) {
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 << 1;
    if (6 < iVar3) break;
LAB_2013a8a0:
    if ((int)(uint)local_20[0] <= iVar4) break;
  }
  *(char *)(iVar2 + 0x60) = (char)iVar3;
  *(undefined4 *)(iVar2 + 0x5c) = 1;
LAB_2013a85c:
  *(undefined4 *)(iVar2 + 0x8c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(iVar2 + 0x90) = 0;
  FUN_20138c84(param_1);
  return iVar2 + 0x40;
}


// ===== FUN_2013a90c @ 2013a90c (120 bytes)

int FUN_2013a90c(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  if (param_1 != 0) {
    bVar2 = *(byte *)(param_2 + 3) & 3;
    if (bVar2 == 2) {
      iVar1 = FUN_2013a798(param_1,param_2,1,4);
      if (iVar1 != 0) {
        FUN_2013a690();
      }
      return iVar1;
    }
    if (bVar2 == 3) {
      iVar1 = FUN_2013a798(param_1,param_2,6,9);
      if (iVar1 != 0) {
        FUN_2013a690();
      }
      return iVar1;
    }
  }
  return 0;
}


// ===== FUN_2013a93c @ 2013a93c (152 bytes)

undefined4 FUN_2013a93c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 8;
  iVar5 = *(int *)(param_1 + 0x4d4);
  iVar1 = 0;
  do {
    *(short *)(*(int *)(param_1 + 8) + 100) = (short)(iVar1 + 1);
    iVar2 = *(int *)(iVar5 + iVar1 * 4);
    *(int *)(param_1 + (iVar1 + 1) * 0x70 + 0x68) = iVar2;
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = ((int)(iVar2 + 0x3f + ((uint)(iVar2 + 0x3f >> 0x1f) >> 0x1a)) >> 6) + -1;
    }
    *(ushort *)(*(int *)(param_1 + 8) + 0x6a) = (ushort)iVar4 | (ushort)(iVar3 << 10);
    if (iVar2 != 0) {
      iVar4 = iVar3 + iVar4 + 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  iVar1 = 6;
  do {
    iVar4 = iVar1 + 1;
    *(undefined4 *)(param_1 + iVar1 * 0x70 + 0x68) = 0x40;
    iVar1 = iVar4;
  } while (iVar4 < 10);
  return 0;
}


// ===== FUN_2013a9d4 @ 2013a9d4 (20 bytes)

undefined * FUN_2013a9d4(int param_1)

{
  return &DAT_2090b660 + param_1 * 0x4d8;
}


// ===== FUN_2013a9e8 @ 2013a9e8 (116 bytes)

undefined4 FUN_2013a9e8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_2013b524();
  *(ushort *)(*(int *)(param_1 + 8) + 0x36) = *(ushort *)(*(int *)(param_1 + 8) + 0x36) | 0x3ff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x38) = *(ushort *)(*(int *)(param_1 + 8) + 0x38) | 0x3ff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x3a) = *(ushort *)(*(int *)(param_1 + 8) + 0x3a) | 0x3ff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x30) = *(ushort *)(*(int *)(param_1 + 8) + 0x30) | 0x700;
  *(ushort *)(*(int *)(param_1 + 8) + 0x32) = *(ushort *)(*(int *)(param_1 + 8) + 0x32) | 0x830;
  thunk_FUN_20152d28(uVar1);
  return 0;
}


// ===== FUN_2013aa5c @ 2013aa5c (68 bytes)

void FUN_2013aa5c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  *(undefined2 *)(iVar1 + 0x10) = *(undefined2 *)(iVar1 + 0x10);
  *(undefined2 *)(iVar1 + 0x12) = *(undefined2 *)(iVar1 + 0x12);
  *(ushort *)(iVar1 + 0x20) = *(ushort *)(iVar1 + 0x20) & 0xfeff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x28) = *(ushort *)(*(int *)(param_1 + 8) + 0x28) & 0xfeff;
  *(ushort *)(*(int *)(param_1 + 8) + 0x2c) = *(ushort *)(*(int *)(param_1 + 8) + 0x2c) & 0xfeff;
  return;
}


// ===== FUN_2013aaa4 @ 2013aaa4 (16 bytes)

void FUN_2013aaa4(int param_1)

{
  *(undefined2 *)(*(int *)(param_1 + 8) + 2) = 3;
  return;
}


// ===== FUN_2013aab4 @ 2013aab4 (200 bytes)

undefined4 FUN_2013aab4(undefined4 *param_1)

{
  ushort uVar1;
  
  uVar1 = DAT_e8010000;
  if ((uVar1 & 2) == 0) {
    uVar1 = DAT_e8010000;
    DAT_e8010000 = uVar1 | 2;
    itron_dly_tsk(2);
  }
  *(undefined2 *)(param_1[2] + 0x102) = 0x4000;
  FUN_2013aaa4(param_1);
  *(ushort *)param_1[2] = *(ushort *)param_1[2] & 0xfffe;
  *(ushort *)param_1[2] = *(ushort *)param_1[2] | 1;
  *(ushort *)param_1[2] = *(ushort *)param_1[2] | 0x40;
  *(ushort *)param_1[2] = *(ushort *)param_1[2] | 0x80;
  FUN_2013aa5c(param_1);
  *(ushort *)param_1[2] = *(ushort *)param_1[2] | 0x20;
  FUN_2013b538(*param_1,0);
  FUN_2013a93c(param_1);
  FUN_2013a9e8(param_1);
  return 0;
}


// ===== FUN_2013ab7c @ 2013ab7c (32 bytes)

undefined4 FUN_2013ab7c(int param_1,uint param_2)

{
  if ((1 < param_2) && (param_2 != 2)) {
    param_2 = 2;
  }
  *(uint *)(param_1 + 0x3c) = param_2;
  return 0;
}


// ===== FUN_2013ab9c @ 2013ab9c (104 bytes)

undefined4 FUN_2013ab9c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  if (param_1 < 2) {
    iVar1 = param_1 * 0x4d8;
    puVar3 = (uint *)(&DAT_2090b660 + iVar1);
    if (*(int *)(&DAT_2090b664 + iVar1) == 0) {
      *(undefined4 *)(&DAT_2090b668 + iVar1) = param_2;
      *puVar3 = param_1;
      FUN_2013ab7c(puVar3,param_3);
      *(undefined4 *)(&DAT_2090b664 + iVar1) = 1;
      *(undefined4 *)(iVar1 + 0x2090bb34) = param_4;
      FUN_2013aab4(puVar3);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== FUN_2013ad24 @ 2013ad24 (44 bytes)

void FUN_2013ad24(int param_1)

{
  if (param_1 != 0) {
    itron_set_flg(*(undefined4 *)(param_1 + 0x24),8);
    *(undefined4 *)(param_1 + 0x10) = 0;
    return;
  }
  return;
}


// ===== FUN_2013ad94 @ 2013ad94 (88 bytes)

undefined4 FUN_2013ad94(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 == 0) {
    uVar1 = 7;
  }
  else {
    uVar1 = 6;
  }
  FUN_2013ae40(&DAT_2090b660 + *(int *)(param_1 + 8) * 0x4d8,0,0,param_2,param_3,
               *(undefined1 *)(*(int *)(param_1 + 0x8d8) + 0x19),uVar1);
  return 0;
}


// ===== FUN_2013adec @ 2013adec (84 bytes)

undefined4 FUN_2013adec(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_2013ae40(&DAT_2090b660 + *(int *)(param_1 + 8) * 0x4d8,0,0,param_2,param_3,
               *(undefined1 *)(*(int *)(param_1 + 0x8d8) + 0x19),8);
  return 0;
}


// ===== FUN_2013ae40 @ 2013ae40 (100 bytes)

undefined4
FUN_2013ae40(int *param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            uint param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_20151308(*(undefined4 *)(&DAT_2091c214 + *param_1 * 8),
                       *param_1 << 0x18 | (param_2 & 0xf) << 0x14 | (param_3 & 0xf) << 0x10 |
                       (param_4 & 0xf) << 0xc | (param_5 & 0xf) << 8 | (param_6 & 0xf) << 4 |
                       param_7 & 0xf,0);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== FUN_2013aea4 @ 2013aea4 (140 bytes)

undefined4 FUN_2013aea4(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while (((iVar2 = *param_1 * 0x34 + 0x2091c220 + iVar1 * 0x34, *(byte *)(iVar2 + 0x16) != param_2
          || (*(byte *)(iVar2 + 0x17) != param_3)) || (*(int *)(iVar2 + 4) == 0))) {
    iVar1 = iVar1 + 1;
    if (0 < iVar1) {
      return 0xffffffff;
    }
  }
  if (*(code **)(iVar2 + 0x28) != (code *)0x0) {
    (**(code **)(iVar2 + 0x28))(**(undefined4 **)(iVar2 + 8),*(undefined4 *)(iVar2 + 0xc),iVar2);
  }
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 0x28) = 0;
  return 0;
}


// ===== FUN_2013af30 @ 2013af30 (116 bytes)

int FUN_2013af30(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = *param_1 * 0x34 + 0x2091c220 + iVar2 * 0x34;
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = 1;
      *(int **)(iVar1 + 8) = param_1;
      *(undefined4 *)(iVar1 + 0x2c) = param_2;
      *(undefined4 *)(iVar1 + 0x28) = 0;
      *(undefined4 *)(iVar1 + 0x30) = 0;
      return iVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  return 0;
}


// ===== FUN_2013afa4 @ 2013afa4 (660 bytes)

undefined4 FUN_2013afa4(undefined4 param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte local_130 [2];
  byte local_12e;
  byte local_12d;
  undefined1 local_12c;
  undefined1 local_12b;
  undefined1 local_12a;
  byte local_129;
  byte local_128;
  byte local_127;
  byte local_126;
  byte local_125;
  byte local_124;
  byte local_123;
  uint local_30;
  uint local_2c;
  
  local_30 = param_2 >> 0x18;
  pbVar6 = local_130;
  uVar12 = (param_2 & 0xffff) >> 0xc;
  uVar11 = (param_2 & 0xfff) >> 8;
  uVar9 = (param_2 & 0xff) >> 4;
  uVar4 = FUN_2013a9d4();
  iVar7 = 0;
  do {
    iVar8 = local_30 * 0x34 + 0x2091c220 + iVar7 * 0x34;
    if (((*(int *)(iVar8 + 4) != 0) && (*(byte *)(iVar8 + 0x16) == uVar12)) &&
       (*(byte *)(iVar8 + 0x17) == uVar11)) {
      FUN_2013aea4(uVar4,uVar12,uVar11);
      break;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 1);
  iVar7 = FUN_2013af30(uVar4,uVar9);
  if (iVar7 != 0) {
    iVar8 = 0;
    local_2c = uVar9;
LAB_2013b058:
    iVar10 = iVar8 + 1;
    if (iVar8 < 4) {
      itron_dly_tsk(10);
      uVar9 = FUN_2013a4bc(local_30,uVar11);
      iVar8 = iVar10;
      if (uVar9 < 3) {
        *(char *)(iVar7 + 0x19) = (char)local_2c;
        uVar4 = *(undefined4 *)(iVar7 + 0xc);
        *(undefined4 *)(iVar7 + 0xc) = 0;
        *(byte *)(iVar7 + 0x14) = (byte)(param_2 >> 0x10) >> 4;
        *(byte *)(iVar7 + 0x15) = (byte)((param_2 << 0xc) >> 0x1c);
        *(byte *)(iVar7 + 0x16) = (byte)(param_2 >> 8) >> 4;
        *(byte *)(iVar7 + 0x17) = (byte)((param_2 << 0x14) >> 0x1c);
        *(char *)(iVar7 + 0x18) = (char)uVar9;
        *(undefined4 *)(iVar7 + 0x10) = 8;
        iVar10 = FUN_2013b35c(iVar7,local_130,8);
        if (iVar10 < 0) {
LAB_2013b114:
          *(undefined4 *)(iVar7 + 0xc) = uVar4;
        }
        else {
          *(uint *)(iVar7 + 0x10) = (uint)local_129;
          iVar10 = FUN_2013b3f4(iVar7,uVar4);
          if (iVar10 < 0) goto LAB_2013b114;
          *(undefined4 *)(iVar7 + 0xc) = uVar4;
          itron_dly_tsk(10);
          iVar10 = 0;
          while (iVar5 = FUN_2013b35c(iVar7,local_130,0x12), iVar5 < 0) {
            iVar10 = iVar10 + 1;
            if (3 < iVar10) goto LAB_2013b058;
          }
          iVar10 = 0;
          *(undefined1 *)(iVar7 + 0x1a) = local_12c;
          *(undefined1 *)(iVar7 + 0x1b) = local_12b;
          *(undefined1 *)(iVar7 + 0x1c) = local_12a;
          *(ushort *)(iVar7 + 0x1e) = (ushort)local_128 + (ushort)local_127 * 0x100;
          *(ushort *)(iVar7 + 0x20) = (ushort)local_126 + (ushort)local_125 * 0x100;
          *(ushort *)(iVar7 + 0x22) = (ushort)local_124 + (ushort)local_123 * 0x100;
          do {
            iVar5 = FUN_2013b3a8(iVar7,local_130,0xff);
            if (-1 < iVar5) {
              iVar8 = (uint)local_12e + (uint)local_12d * 0x100;
              do {
                bVar1 = *pbVar6;
                if (pbVar6[1] == 4) {
                  bVar2 = pbVar6[6];
                  bVar3 = pbVar6[7];
                  *(byte *)(iVar7 + 0x24) = pbVar6[5];
                  *(byte *)(iVar7 + 0x25) = bVar2;
                  *(byte *)(iVar7 + 0x26) = bVar3;
                }
                iVar8 = iVar8 - (uint)bVar1;
                pbVar6 = pbVar6 + bVar1;
              } while (0 < iVar8);
              iVar8 = FUN_20137fac(local_30,uVar4,iVar7);
              if (iVar8 == 0) {
                *(undefined **)(iVar7 + 0x28) = &DAT_20138410;
              }
              return 0;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < 4);
        }
      }
      else if (uVar9 == 7) {
        iVar8 = 4;
      }
      goto LAB_2013b058;
    }
    *(undefined4 *)(iVar7 + 4) = 0;
    *(undefined4 *)(iVar7 + 0x28) = 0;
  }
  return 0xffffffff;
}


// ===== FUN_2013b23c @ 2013b23c (120 bytes)

void FUN_2013b23c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint local_8 [2];
  
  param_2 = param_2 + param_1 * 8;
  uVar7 = *(undefined4 *)(param_2 + 4);
  do {
    while (iVar4 = FUN_20151e68(uVar7,local_8,0xffffffff), uVar3 = local_8[0], iVar4 != 0) {
      itron_dly_tsk(500);
    }
    uVar1 = local_8[0] & 0xffff;
    uVar2 = local_8[0] & 0xfff;
    uVar6 = local_8[0] & 0xf;
    uVar5 = FUN_2013a9d4(local_8[0] >> 0x18);
    if (uVar6 == 6) {
      FUN_2013afa4(param_2,uVar3);
    }
    else if (uVar6 == 7) {
      FUN_2013aea4(uVar5,uVar1 >> 0xc,uVar2 >> 8);
    }
  } while( true );
}


// ===== FUN_2013b2b4 @ 2013b2b4 (68 bytes)

undefined4 FUN_2013b2b4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 1;
    iVar1 = param_1 * 0x34 + 0x2091c220 + iVar2 * 0x34;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(int *)(iVar1 + 0xc) = iVar2 + 1;
    iVar2 = iVar3;
  } while (iVar3 < 1);
  return 0;
}


// ===== FUN_2013b2f8 @ 2013b2f8 (84 bytes)

void FUN_2013b2f8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = param_1 * 0x34 + 0x2091c220 + iVar2 * 0x34;
    if ((*(int *)(iVar1 + 4) != 0) && (*(int *)(iVar1 + 0x2c) == param_2)) {
      *(undefined4 *)(iVar1 + 0x30) = 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  return;
}


// ===== FUN_2013b35c @ 2013b35c (76 bytes)

void FUN_2013b35c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0x80;
  local_f = 6;
  local_e = 0x100;
  local_c = 0;
  local_a = (undefined2)param_3;
  FUN_20138f00(0,param_1,&local_10,param_2,param_3);
  return;
}


// ===== FUN_2013b3a8 @ 2013b3a8 (76 bytes)

void FUN_2013b3a8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0x80;
  local_f = 6;
  local_e = 0x200;
  local_c = 0;
  local_a = (undefined2)param_3;
  FUN_20138f00(0,param_1,&local_10,param_2,param_3);
  return;
}


// ===== FUN_2013b3f4 @ 2013b3f4 (72 bytes)

void FUN_2013b3f4(undefined4 param_1,undefined2 param_2)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0;
  local_f = 5;
  local_c = 0;
  local_a = 0;
  local_e = param_2;
  FUN_20138f00(0,param_1,&local_10,0,0);
  return;
}


// ===== FUN_2013b43c @ 2013b43c (72 bytes)

void FUN_2013b43c(undefined4 param_1,undefined2 param_2)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0;
  local_f = 9;
  local_c = 0;
  local_a = 0;
  local_e = param_2;
  FUN_20138f00(0,param_1,&local_10,0,0);
  return;
}


// ===== FUN_2013b484 @ 2013b484 (72 bytes)

void FUN_2013b484(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = 0xa0;
  local_f = 6;
  local_c = 0;
  local_e = 0;
  local_a = (undefined2)param_3;
  FUN_20138f00(0,param_1,&local_10,param_2,param_3);
  return;
}


// ===== FUN_2013b4cc @ 2013b4cc (88 bytes)

void FUN_2013b4cc(void)

{
  FUN_2011762c(0x49,&DAT_204201b8);
  FUN_2011775c(0x49);
  FUN_2013ab9c(0,&DAT_e8010000,2,&DAT_20808ac0);
  FUN_2011762c(0x4a,&DAT_204201c4);
  FUN_2011775c(0x4a);
  FUN_2013ab9c(1,&DAT_e8207000,2,&DAT_20808ac0);
  return;
}


// ===== FUN_2013b524 @ 2013b524 (16 bytes)

undefined4 FUN_2013b524(void)

{
  FUN_20150c3c();
  return 0;
}


// ===== FUN_2013b538 @ 2013b538 (40 bytes)

/* WARNING: Removing unreachable block (ram,0x20101db4) */

void FUN_2013b538(int param_1)

{
  if (param_1 == 0) {
    DAT_fcfe3120 = 0x4000400;
  }
  return;
}


// ===== FUN_2013b54c @ 2013b54c (64 bytes)

void FUN_2013b54c(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  do {
    iVar2 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  } while ((uint)(iVar2 - iVar1) < 4);
  DAT_20808abc = iVar2 - iVar1;
  return;
}


// ===== usbh_create_objects @ 2013b5bc (696 bytes)

/* m596* / udevtsk%d names */

undefined4 usbh_create_objects(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1 * 0x10 + 0x2091c368;
  sprintf(iVar1,"m596i%d",param_1);
  iVar1 = FUN_2014e5e4(&DAT_204201d0,iVar1);
  if (-1 < iVar1) {
    *(int *)(param_2 + 0x14) = iVar1;
    iVar1 = param_1 * 0x10 + 0x2091c388;
    sprintf(iVar1,"m596r%d",param_1);
    iVar1 = FUN_2014e5e4(&DAT_204201d0,iVar1);
    if (-1 < iVar1) {
      *(int *)(param_2 + 0x20) = iVar1;
      iVar1 = param_1 * 0x10 + 0x2091c3a8;
      sprintf(iVar1,"m596su%d",param_1);
      iVar1 = FUN_2014e5e4(&DAT_204201d0,iVar1);
      if (-1 < iVar1) {
        *(int *)(param_2 + 0x1c) = iVar1;
        iVar1 = param_1 * 0x10 + 0x2091c508;
        sprintf(iVar1,"m596a%d",param_1);
        iVar1 = FUN_2014e5e4(&DAT_204201d0,iVar1);
        if (-1 < iVar1) {
          *(int *)(param_2 + 0x18) = iVar1;
          iVar1 = param_1 * 0x10 + 0x2091c528;
          sprintf(iVar1,"m596a%d",param_1);
          iVar1 = os_create_sem_named(&DAT_204201ec,iVar1);
          if (-1 < iVar1) {
            *(int *)(param_2 + 0x4a0) = iVar1;
            iVar1 = param_1 * 0x10 + 0x2091c548;
            sprintf(iVar1,"m596c%d",param_1);
            iVar1 = os_create_sem_named(&DAT_204201ec,iVar1);
            if (-1 < iVar1) {
              *(int *)(param_2 + 0x4a8) = iVar1;
              iVar1 = 0;
              do {
                iVar2 = param_1 * 0x30 + 0x2091c308 + iVar1 * 0x10;
                sprintf(iVar2,"m596fi%d%d",param_1,iVar1);
                iVar2 = os_create_sem_named(&DAT_204201ec,iVar2);
                if (iVar2 < 0) {
                  return 0xffffffff;
                }
                iVar3 = iVar1 * 4;
                iVar1 = iVar1 + 1;
                *(int *)(param_2 + iVar3 + 0x30) = iVar2;
              } while (iVar1 < 3);
              iVar1 = 0;
              do {
                iVar3 = param_2 + iVar1 * 0x70;
                iVar2 = param_1 * 0xa0 + 0x2091c3c8 + iVar1 * 0x10;
                *(int *)(iVar3 + 0x4c) = iVar1;
                *(int *)(iVar3 + 0x44) = param_2;
                sprintf(iVar2,"m596d%dt%d",param_1,iVar1);
                iVar2 = FUN_2014e5e4(&DAT_204201d0,iVar2);
                if (iVar2 < 0) {
                  return 0xffffffff;
                }
                iVar1 = iVar1 + 1;
                *(int *)(iVar3 + 100) = iVar2;
              } while (iVar1 < 10);
              iVar1 = param_1 * 0x10 + 0x2091c288;
              sprintf(iVar1,"m596m%d",param_1);
              DAT_20808ad8 = param_1;
              iVar1 = FUN_2014e5b0(&DAT_20808ad4,iVar1);
              if (-1 < iVar1) {
                *(int *)(param_2 + 0x24) = iVar1;
                iVar1 = param_1 * 0x10 + 0x2091c2a8;
                sprintf(iVar1,"m596r%d",param_1);
                DAT_20808af4 = param_1;
                iVar1 = FUN_2014e5b0(&DAT_20808af0,iVar1);
                if (-1 < iVar1) {
                  *(int *)(param_2 + 0x28) = iVar1;
                  iVar1 = param_1 * 0x10 + 0x2091c2e8;
                  sprintf(iVar1,"udevtsk%d",param_1);
                  iVar1 = FUN_2014e6e4(&DAT_204201dc,iVar1);
                  if (-1 < iVar1) {
                    *(int *)(&DAT_2091c214 + param_1 * 8) = iVar1;
                    iVar1 = param_1 * 0x10 + 0x2091c2c8;
                    sprintf(iVar1,"udev%d",param_1);
                    DAT_20808b10 = param_1;
                    iVar1 = FUN_2014e5b0(&DAT_20808b0c,iVar1);
                    if (-1 < iVar1) {
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== usbh_hid_init @ 2013b928 (72 bytes)

/* UHHID */

undefined4 usbh_hid_init(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    DAT_20808b2c = iVar2;
    iVar1 = FUN_2014e5b0(&DAT_20808b28,"UHHID");
    if (iVar1 < 1) {
      return 0xffffffff;
    }
    iVar2 = iVar2 + 1;
    *param_1 = iVar1;
    param_1 = param_1 + 0xc2;
  } while (iVar2 < 2);
  return 0;
}


// ===== FUN_2013b97c @ 2013b97c (56 bytes)

undefined4 FUN_2013b97c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  memclr(&DAT_2091c568,0x610);
  iVar1 = usbh_hid_init(&DAT_2091c568);
  if ((iVar1 < 0) || (iVar1 = FUN_2013c6bc(), iVar1 < 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_2013ba44 @ 2013ba44 (104 bytes)

undefined4 FUN_2013ba44(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  param_1 = param_1 * 0x308;
  if (*(int *)(&DAT_2091c584 + param_1) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(&DAT_2091c57c + param_1) = 0;
    FUN_2013c798(*(undefined4 *)(&DAT_2091c56c + param_1),*(undefined4 *)(&DAT_2091c574 + param_1));
    iVar2 = 0;
    do {
      if (*(int *)(&DAT_2091c580 + param_1) == 0) break;
      itron_dly_tsk(5);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 200);
    uVar1 = 0;
    *(undefined4 *)(&DAT_2091c584 + param_1) = 0;
  }
  return uVar1;
}


// ===== FUN_2013baac @ 2013baac (264 bytes)

undefined4 FUN_2013baac(int param_1,int param_2,byte *param_3)

{
  uint uVar1;
  int iVar2;
  byte local_14 [4];
  
  param_1 = param_1 * 0x308;
  if (((*(int *)(&DAT_2091c57c + param_1) != 0) && (param_2 == 0)) &&
     (*(int *)(&DAT_2091c588 + param_1) == 6)) {
    uVar1 = 0;
    local_14[0] = 0;
    if (0 < *(int *)(&DAT_2091c660 + param_1)) {
      do {
        iVar2 = uVar1 + param_1;
        if ((&DAT_2091c568)[iVar2 + 0xfc] == '\x01') {
          if ((*param_3 & 1) != 0) {
            local_14[0] = local_14[0] | (byte)(1 << (uVar1 & 0xff));
            goto LAB_2013bb24;
          }
        }
        else {
LAB_2013bb24:
          if ((&DAT_2091c568)[iVar2 + 0xfc] == '\x02') {
            if ((*param_3 & 2) == 0) goto LAB_2013bb6c;
            local_14[0] = local_14[0] | (byte)(1 << (uVar1 & 0xff));
          }
          if (((&DAT_2091c568)[iVar2 + 0xfc] == '\x03') && ((*param_3 & 4) != 0)) {
            local_14[0] = local_14[0] | (byte)(1 << (uVar1 & 0xff));
          }
        }
LAB_2013bb6c:
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < *(int *)(&DAT_2091c660 + param_1));
    }
    iVar2 = FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x21,9,0x200,
                         (&DAT_2091c570)[param_1],local_14,1);
    if (iVar2 == 1) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== FUN_2013bbb4 @ 2013bbb4 (124 bytes)

uint FUN_2013bbb4(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = param_2 & 7;
  uVar5 = 0;
  uVar3 = param_3;
  uVar4 = param_2;
  if (uVar2 != 0) {
    uVar4 = param_2 + 7 & 0xfffffff8;
    uVar3 = param_3 - (uVar4 - param_2);
  }
  uVar1 = 0;
  if (0 < (int)uVar3) {
    do {
      uVar5 = uVar5 | (uint)*(byte *)(param_1 + ((int)(uVar4 + uVar1) >> 3)) << (uVar1 & 0xff);
      uVar1 = uVar1 + 8;
    } while ((int)uVar1 < (int)uVar3);
  }
  if (uVar2 != 0) {
    uVar5 = uVar5 << (8 - uVar2 & 0xff) | (uint)(*(byte *)(param_1 + ((int)param_2 >> 3)) >> uVar2);
  }
  return (1 << (param_3 & 0xff)) - 1U & uVar5;
}


// ===== FUN_2013bc30 @ 2013bc30 (240 bytes)

void FUN_2013bc30(int *param_1,uint *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  ushort *puVar4;
  byte bVar5;
  
  pbVar3 = (byte *)*param_1;
  puVar4 = (ushort *)(pbVar3 + 1);
  bVar5 = *pbVar3 & 3;
  if ((*pbVar3 & 3) == 0) {
    *param_2 = 0;
    iVar2 = *param_1 + 1;
  }
  else if (bVar5 == 1) {
    uVar1 = *puVar4;
    *param_2 = (uint)(byte)uVar1;
    if ((param_3 != 0) && ((*puVar4 & 0x80) != 0)) {
      *param_2 = (byte)uVar1 | 0xffffff00;
    }
    iVar2 = *param_1 + 2;
  }
  else if (bVar5 == 2) {
    uVar1 = *puVar4;
    *param_2 = (uint)uVar1;
    if ((param_3 != 0) && ((pbVar3[2] & 0x80) != 0)) {
      *param_2 = uVar1 | 0xffff0000;
    }
    iVar2 = *param_1 + 3;
  }
  else {
    if (bVar5 != 3) {
      return;
    }
    uVar1 = *puVar4;
    *param_2 = (uint)uVar1;
    if ((param_3 != 0) && ((pbVar3[2] & 0x80) != 0)) {
      *param_2 = uVar1 | 0xffff0000;
    }
    iVar2 = *param_1 + 5;
  }
  *param_1 = iVar2;
  return;
}


// ===== FUN_2013bd20 @ 2013bd20 (1540 bytes)

undefined4 FUN_2013bd20(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  int local_44;
  byte *local_40;
  uint local_3c;
  uint local_38;
  int iStack_30;
  byte *local_2c;
  int local_28;
  
  iVar7 = 0;
  local_38 = 0;
  iVar4 = param_1 + 0x205;
  local_44 = 0;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xdc) = 0xffffffff;
  do {
    iVar6 = iVar2 * 0x10;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(param_1 + iVar6 + 0x24) = 0xffffffff;
  } while (iVar2 < 10);
  *(undefined4 *)(param_1 + 0xf4) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x104) = 0;
  iVar2 = 0;
  local_54 = 0;
  iVar6 = 0;
  uVar5 = 0;
  local_50 = 0;
  iVar8 = 0;
  local_48 = 0;
  local_60 = -1;
  local_58 = 0;
  local_5c = -1;
  local_4c = 0;
  local_40 = param_2;
  iStack_30 = param_1;
  local_2c = param_2;
  local_28 = param_3;
  if (0 < param_3) {
    do {
      bVar1 = *local_40 & 0xfc;
      if (bVar1 == 0x80) {
        FUN_2013bc30(&local_40,&local_3c,0);
        if ((*(int *)(param_1 + 0x20) < 0) || (local_44 != iVar6)) goto LAB_2013c034;
        if (local_48 == 1) {
          if (local_3c == 2 || local_3c == 6) {
            if (local_54 != iVar2) {
              return 0xffffffff;
            }
            iVar2 = 0;
            if (0 < local_54) {
              do {
                if ((*(byte *)(iVar4 + iVar2) - 0x30 < 10) &&
                   (iVar3 = param_1 + (*(byte *)(iVar4 + iVar2) - 0x30) * 0x10,
                   *(int *)(iVar3 + 0x24) < 0)) {
                  *(uint *)(iVar3 + 0x24) = local_58 * iVar2 + uVar5;
                  *(int *)(iVar3 + 0x28) = local_58;
                  *(undefined4 *)(iVar3 + 0x2c) = local_4c;
                  *(undefined4 *)(iVar3 + 0x30) = local_50;
                }
                iVar2 = iVar2 + 1;
              } while (iVar2 < local_54);
            }
          }
        }
        else {
          if (local_48 == 7) {
            if (local_3c == 2) {
              if (((local_54 != iVar2) || (8 < local_54)) || (local_58 != 1)) {
                return 0xffffffff;
              }
              if (*(int *)(param_1 + 0xc4) < 0) {
                *(int *)(param_1 + 200) = local_54;
                iVar3 = param_1 + 0xcc;
                *(uint *)(param_1 + 0xc4) = uVar5;
                iVar2 = local_54;
                goto LAB_2013c1cc;
              }
            }
            else {
              if (local_3c != 0) goto LAB_2013c1d4;
              bVar9 = local_54 == 8;
              if (local_54 < 9) {
                bVar9 = (uVar5 & 7) == 0;
              }
              if (!bVar9) {
                return 0xffffffff;
              }
              if (local_58 != 8) {
                return 0xffffffff;
              }
              if (*(int *)(param_1 + 0xd4) < 0) {
                *(int *)(param_1 + 0xd8) = local_54;
                *(int *)(param_1 + 0xd4) = (int)(uVar5 + ((uint)((int)uVar5 >> 0x1f) >> 0x1d)) >> 3;
              }
            }
          }
          else {
            if ((local_48 != 9) || (local_3c != 2)) goto LAB_2013c1d4;
            if (local_54 < iVar2) {
              iVar2 = local_54;
            }
            if (0x10 < local_54) {
              return 0xffffffff;
            }
            if (local_58 != 1) {
              return 0xffffffff;
            }
            if (*(int *)(param_1 + 0xdc) < 0) {
              *(int *)(param_1 + 0xe0) = iVar2;
              iVar3 = param_1 + 0xe4;
              *(uint *)(param_1 + 0xdc) = uVar5;
LAB_2013c1cc:
              memcpy(iVar3,iVar4,iVar2);
            }
          }
          *(char *)(param_1 + 0x104) = (char)iVar6;
        }
LAB_2013c1d4:
        uVar5 = local_58 * local_54 + uVar5;
LAB_2013c034:
        iVar2 = 0;
        local_60 = -1;
        local_5c = -1;
      }
      else if (bVar1 < 0x80) {
        if (bVar1 == 0x18) {
          FUN_2013bc30(&local_40,&local_60,0);
          if ((-1 < local_60) && (iVar3 = local_60, -1 < local_5c)) {
            for (; iVar3 <= local_5c; iVar3 = iVar3 + 1) {
              if (iVar2 < 0x100) {
                if (iVar3 < 0x100) {
                  *(char *)(iVar4 + iVar2) = (char)iVar3;
                }
                else {
                  *(undefined1 *)(iVar4 + iVar2) = 0;
                }
                iVar2 = iVar2 + 1;
              }
            }
          }
        }
        else if (bVar1 < 0x18) {
          if (bVar1 == 4) {
            FUN_2013bc30(&local_40,&local_48,0);
          }
          else if (bVar1 == 8) {
            FUN_2013bc30(&local_40,&local_3c,0);
            local_38 = local_3c;
            if (iVar7 == 0) {
              if (((local_48 & 0xff00) == 0) && (*(int *)(param_1 + 0x20) < 0)) {
                *(uint *)(param_1 + 0x20) = local_3c;
              }
            }
            else if (iVar2 < 0x100) {
              if (local_3c < 0x100) {
                *(char *)(iVar4 + iVar2) = (char)local_3c;
                iVar2 = iVar2 + 1;
              }
              else {
                *(undefined1 *)(iVar4 + iVar2) = 0;
                iVar2 = iVar2 + 1;
              }
            }
          }
          else {
            if (bVar1 != 0x14) goto LAB_2013be4c;
            FUN_2013bc30(&local_40,&local_50,1);
          }
        }
        else if (bVar1 == 0x24) {
          FUN_2013bc30(&local_40,&local_4c,1);
        }
        else if (bVar1 == 0x28) {
          FUN_2013bc30(&local_40,&local_5c,0);
          if ((-1 < local_60) && (iVar3 = local_60, -1 < local_5c)) {
            for (; iVar3 <= local_5c; iVar3 = iVar3 + 1) {
              if (iVar2 < 0x100) {
                if (iVar3 < 0x100) {
                  *(char *)(iVar4 + iVar2) = (char)iVar3;
                }
                else {
                  *(undefined1 *)(iVar4 + iVar2) = 0;
                }
                iVar2 = iVar2 + 1;
              }
            }
          }
        }
        else {
          if (bVar1 != 0x74) goto LAB_2013be4c;
          FUN_2013bc30(&local_40,&local_58,0);
        }
      }
      else if (bVar1 == 0xa0) {
        FUN_2013bc30(&local_40,&local_3c,0);
        if ((iVar7 == 0) && (local_38 == 6)) {
          local_48 = 7;
        }
        iVar2 = 0;
        iVar7 = iVar7 + 1;
        local_60 = -1;
        local_5c = -1;
      }
      else if (bVar1 < 0xa1) {
        if (bVar1 == 0x84) {
          FUN_2013bc30(&local_40,&local_44,0);
          iVar3 = *(int *)(param_1 + 0x20);
          if (-1 < *(int *)(param_1 + 0x20)) {
            iVar3 = iVar6;
          }
          if (iVar3 == 0) {
            uVar5 = 8;
            iVar8 = 0;
            iVar6 = local_44;
          }
        }
        else {
          if (bVar1 == 0x90) {
            FUN_2013bc30(&local_40,&local_3c,0);
            if ((-1 < *(int *)(param_1 + 0x20)) && (local_44 == iVar6)) {
              if ((local_48 == 8) && (local_3c == 2)) {
                if (local_54 < iVar2) {
                  iVar2 = local_54;
                }
                if (8 < local_54) {
                  return 0xffffffff;
                }
                if (local_58 != 1) {
                  return 0xffffffff;
                }
                if (*(int *)(param_1 + 0xf4) < 0) {
                  *(int *)(param_1 + 0xf8) = iVar2;
                  *(int *)(param_1 + 0xf4) = iVar8;
                  memcpy(param_1 + 0xfc,iVar4,iVar2);
                }
              }
              iVar8 = local_58 * local_54 + iVar8;
            }
            goto LAB_2013c034;
          }
          if (bVar1 != 0x94) goto LAB_2013be4c;
          FUN_2013bc30(&local_40,&local_54,0);
        }
      }
      else {
        if (bVar1 == 0xb0) {
          FUN_2013bc30(&local_40,&local_3c,0);
          goto LAB_2013c034;
        }
        if (bVar1 == 0xc0) {
          FUN_2013bc30(&local_40,&local_3c,0);
          iVar2 = 0;
          iVar7 = iVar7 + -1;
          local_60 = -1;
          local_5c = -1;
        }
        else {
LAB_2013be4c:
          FUN_2013bc30(&local_40,&local_3c,0);
        }
      }
    } while ((int)local_40 - (int)local_2c < local_28);
  }
  return 0;
}


// ===== FUN_2013c32c @ 2013c32c (912 bytes)

void FUN_2013c32c(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;
  ushort uVar7;
  uint uVar8;
  byte *pbVar9;
  bool bVar10;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  param_1 = param_1 * 0x308;
  puVar6 = &DAT_2091c568 + param_1;
  pbVar9 = &DAT_2091c66d + param_1;
  *(undefined4 *)(&DAT_2091c580 + param_1) = 1;
  iVar3 = FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x80,6,0x200,0,pbVar9,9);
  if (((iVar3 == 9) && (uVar8 = (uint)*(ushort *)(&DAT_2091c66f + param_1), uVar8 < 0x100)) &&
     (uVar4 = FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x80,6,0x200,0,pbVar9,uVar8),
     uVar4 == uVar8)) {
    uVar7 = 0;
    pbVar9[uVar4] = 0;
    bVar10 = false;
    for (pbVar5 = pbVar9;
        ((0 < (int)uVar4 && (uVar8 = (uint)*pbVar5, uVar8 != 0)) && ((int)uVar8 <= (int)uVar4));
        pbVar5 = pbVar5 + uVar8) {
      if (pbVar5[1] == 4) {
        bVar10 = (uint)pbVar5[2] == *(uint *)(&DAT_2091c570 + param_1);
      }
      else if (((pbVar5[1] == 0x21) && (bVar10)) && (pbVar5[6] == 0x22)) {
        uVar7 = *(ushort *)(pbVar5 + 7);
      }
      uVar4 = uVar4 - uVar8;
    }
    if ((uVar7 != 0) && (uVar7 < 0x100)) {
      FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x21,0xb,1,(&DAT_2091c570)[param_1],0,0)
      ;
      iVar3 = FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x81,6,0x2200,
                           (&DAT_2091c570)[param_1],pbVar9,uVar7);
      if (((-1 < iVar3) && (iVar3 = FUN_2013bd20(puVar6,pbVar9), -1 < iVar3)) &&
         ((iVar3 = *(int *)(&DAT_2091c588 + param_1), iVar3 == 2 || iVar3 == 4 ||
          (iVar3 == 5 || iVar3 == 6)))) {
        FUN_2013c710(*(undefined4 *)(&DAT_2091c56c + param_1),0x21,10,0,(&DAT_2091c570)[param_1],0,0
                    );
        thunk_FUN_201166cc(*(undefined4 *)(&DAT_2091c56c + param_1),
                           *(undefined4 *)(&DAT_2091c588 + param_1));
        while ((*(int *)(&DAT_2091c57c + param_1) != 0 &&
               (iVar3 = FUN_2013c76c(*(undefined4 *)(&DAT_2091c56c + param_1),
                                     *(undefined4 *)(&DAT_2091c574 + param_1),pbVar9,
                                     *(undefined4 *)(&DAT_2091c578 + param_1)), -1 < iVar3))) {
          if (((&DAT_2091c66c)[param_1] == 0) || ((&DAT_2091c66c)[param_1] == *pbVar9)) {
            local_44 = 0;
            local_40 = 0;
            local_3c = 0;
            local_38 = 0;
            local_34 = 0;
            local_30 = 0;
            local_2c = 0;
            local_48 = *(int *)(&DAT_2091c588 + param_1);
            if ((local_48 == 2 || local_48 == 4) || local_48 == 5) {
              if (-1 < *(int *)(&DAT_2091c644 + param_1)) {
                local_44 = (uint)(byte)(&DAT_2091c64c)[param_1];
                uVar2 = FUN_2013bbb4(pbVar9,*(undefined4 *)(&DAT_2091c644 + param_1),
                                     *(undefined4 *)(&DAT_2091c648 + param_1));
                local_44 = CONCAT22(uVar2,(undefined2)local_44);
              }
              uVar8 = 0;
              do {
                if (-1 < *(int *)(puVar6 + uVar8 * 0x10 + 0x24)) {
                  local_40 = CONCAT22(local_40._2_2_,
                                      (ushort)local_40 | (ushort)(1 << (uVar8 & 0xff)));
                  uVar4 = FUN_2013bbb4(pbVar9,*(undefined4 *)(puVar6 + uVar8 * 0x10 + 0x24),
                                       *(undefined4 *)(puVar6 + uVar8 * 0x10 + 0x28));
                  if ((*(int *)(puVar6 + uVar8 * 0x10 + 0x30) < 0) &&
                     ((uVar4 & 1 << (*(uint *)(puVar6 + uVar8 * 0x10 + 0x28) - 1 & 0xff)) != 0)) {
                    *(ushort *)((int)&local_40 + uVar8 * 2 + 2) =
                         (ushort)uVar4 |
                         ~((short)(1 << (*(uint *)(puVar6 + uVar8 * 0x10 + 0x28) & 0xff)) - 1U);
                  }
                  else {
                    *(ushort *)((int)&local_40 + uVar8 * 2 + 2) = (ushort)uVar4;
                  }
                }
                uVar8 = uVar8 + 1;
              } while ((int)uVar8 < 10);
            }
            else if (local_48 == 6) {
              if (-1 < *(int *)(&DAT_2091c62c + param_1)) {
                local_44 = (uint)(byte)(&DAT_2091c634)[param_1];
                uVar1 = FUN_2013bbb4(pbVar9,*(undefined4 *)(&DAT_2091c62c + param_1),
                                     *(undefined4 *)(&DAT_2091c630 + param_1));
                local_44._0_2_ = CONCAT11(uVar1,(undefined1)local_44);
              }
              if (-1 < *(int *)(&DAT_2091c63c + param_1)) {
                local_40 = *(undefined4 *)(&DAT_2091c640 + param_1);
                memcpy(&local_3c,pbVar9 + *(int *)(&DAT_2091c63c + param_1),
                       *(undefined4 *)(&DAT_2091c640 + param_1));
              }
            }
            thunk_FUN_20116728(*(undefined4 *)(&DAT_2091c56c + param_1),&local_48);
          }
        }
        thunk_FUN_201166cc(*(undefined4 *)(&DAT_2091c56c + param_1),0xffffffff);
      }
    }
  }
  *(undefined4 *)(&DAT_2091c580 + param_1) = 0;
  *(undefined4 *)(&DAT_2091c588 + param_1) = 0xffffffff;
  FUN_201508ec();
  return;
}


// ===== FUN_2013c6bc @ 2013c6bc (84 bytes)

undefined4 FUN_2013c6bc(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_2091cb78 = 0;
  DAT_2091cb7c = 0;
  DAT_2091cb80 = 0;
  DAT_2091cb84 = 0;
  DAT_2091cb88 = 0;
  DAT_2091cb8c = 0;
  DAT_2091cb90 = 0;
  DAT_2091cb94 = 0;
  DAT_2091cb98 = 0;
  DAT_2091cb9c = 0;
  DAT_2091cba0 = 0;
  DAT_2091cba4 = 0;
  iVar1 = thunk_FUN_201384d4(&DAT_204201fc);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_2013c710 @ 2013c710 (92 bytes)

void FUN_2013c710(int param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  iVar1 = (&DAT_2091cb78)[param_1 * 6];
  if (iVar1 != 0) {
    local_14 = param_5;
    local_12 = (undefined2)param_7;
    local_18 = param_2;
    local_17 = param_3;
    local_16 = param_4;
    FUN_20138f00(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x8d8),&local_18,param_6,param_7
                );
  }
  return;
}


// ===== FUN_2013c76c @ 2013c76c (92 bytes)

void FUN_2013c76c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((&DAT_2091cb78)[param_1 * 6] == 0) {
    return;
  }
  iVar1 = *(int *)((&DAT_2091cb78)[param_1 * 6] + param_2 * 4 + 0x8d8);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x18) == 0) {
      FUN_20139344(iVar1,param_3,param_4);
      return;
    }
    FUN_20139590();
    return;
  }
  return;
}


// ===== FUN_2013c798 @ 2013c798 (316 bytes)

undefined4 FUN_2013c798(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  if ((&DAT_2091cb78)[param_1 * 6] == 0) {
    return 0xffffffff;
  }
  iVar3 = *(int *)((&DAT_2091cb78)[param_1 * 6] + param_2 * 4 + 0x8d8);
  if (iVar3 != 0) {
    iVar5 = *(int *)(iVar3 + 4);
    uVar9 = *(undefined4 *)(iVar3 + 0x24);
    if (*(int *)(iVar3 + 0xc) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = *(int *)(iVar5 + 0x3c);
    }
    iVar6 = (&DAT_20420144)[*(int *)(iVar3 + 0xc)];
    iVar7 = *(int *)(&DAT_2042016c + iVar4 * 4);
    uVar8 = *(undefined4 *)(iVar5 + iVar4 * 4 + 0x30);
    uVar2 = FUN_2013b524();
    *(ushort *)(*(int *)(iVar5 + 8) + iVar6) = *(ushort *)(*(int *)(iVar5 + 8) + iVar6) & 0xfffc;
    thunk_FUN_20152d28(uVar2);
    iVar3 = FUN_2014e1ec();
    while ((iVar4 = FUN_2014e1ec(), (uint)(iVar4 - iVar3) < 0x33 &&
           ((*(ushort *)(*(int *)(iVar5 + 8) + iVar6) & 0x1020) != 0))) {
      itron_dly_tsk(2);
    }
    FUN_20152bb0(uVar8,0xffffffff);
    *(ushort *)(*(int *)(iVar5 + 8) + iVar7) = *(ushort *)(*(int *)(iVar5 + 8) + iVar7) & 0x100;
    FUN_20138740(iVar5,iVar7,0);
    uVar2 = FUN_2013b524();
    uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + iVar6);
    *(ushort *)(*(int *)(iVar5 + 8) + iVar6) = uVar1 | 0x200;
    FUN_2013b54c();
    *(ushort *)(*(int *)(iVar5 + 8) + iVar6) = uVar1 & 0xfdff;
    thunk_FUN_20152d28(uVar2);
    itron_set_flg(uVar9,8);
    FUN_201511e8(uVar8);
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_2013c7c4 @ 2013c7c4 (156 bytes)

undefined4 FUN_2013c7c4(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  *param_1 = *(undefined4 *)(param_2 + 0x850);
  iVar1 = 1;
  if (1 < *(int *)(param_2 + 0x1c)) {
    do {
      iVar2 = param_2 + iVar1 * 0xc;
      if (((*(char *)(iVar2 + 0x861) == '\x03') && ((*(byte *)(iVar2 + 0x860) & 0x80) != 0)) &&
         ((int)param_1[1] < 0)) {
        param_1[1] = iVar1;
        param_1[2] = *(undefined4 *)(iVar2 + 0x864);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_2 + 0x1c));
    if (((-1 < (int)param_1[1]) && (0 < (int)param_1[2])) && ((int)param_1[2] < 0x101)) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== FUN_2013c860 @ 2013c860 (336 bytes)

int FUN_2013c860(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 == 0) {
    iVar4 = 0;
    while( true ) {
      if ((((&DAT_2091cb7c)[iVar4 * 6] == param_1) && ((&DAT_2091cb80)[iVar4 * 6] == param_2)) &&
         ((&DAT_2091cb78)[iVar4 * 6] != 0)) break;
      iVar4 = iVar4 + 1;
      if (1 < iVar4) {
        return iVar4;
      }
    }
    FUN_2013ba44();
    (&DAT_2091cb78)[iVar4 * 6] = 0;
    return 0;
  }
  iVar4 = 0;
  while( true ) {
    iVar1 = (&DAT_2091cb78)[iVar4 * 6];
    if (iVar1 == 0) break;
    iVar4 = iVar4 + 1;
    if (1 < iVar4) {
      return iVar1;
    }
  }
  iVar1 = FUN_2013c7c4(&DAT_2091cb84 + iVar4 * 6,param_3);
  if (iVar1 < 0) {
    return iVar1;
  }
  (&DAT_2091cb80)[iVar4 * 6] = param_2;
  (&DAT_2091cb7c)[iVar4 * 6] = param_1;
  (&DAT_2091cb78)[iVar4 * 6] = param_3;
  if (0x100 < (int)(&DAT_2091cb8c)[iVar4 * 6]) {
    return -1;
  }
  iVar1 = iVar4 * 0x308;
  if (*(int *)(&DAT_2091c584 + iVar1) != 0) {
    return -1;
  }
  *(int *)(&DAT_2091c56c + iVar1) = iVar4;
  uVar3 = (&DAT_2091cb88)[iVar4 * 6];
  uVar2 = (&DAT_2091cb8c)[iVar4 * 6];
  *(undefined4 *)(&DAT_2091c570 + iVar1) = (&DAT_2091cb84)[iVar4 * 6];
  *(undefined4 *)(&DAT_2091c574 + iVar1) = uVar3;
  *(undefined4 *)(&DAT_2091c578 + iVar1) = uVar2;
  *(undefined4 *)(&DAT_2091c57c + iVar1) = 1;
  FUN_2014e73c(*(undefined4 *)(&DAT_2091c568 + iVar1));
  iVar4 = 0;
  do {
    if (*(int *)(&DAT_2091c580 + iVar1) != 0) break;
    itron_dly_tsk(5);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 200);
  *(undefined4 *)(&DAT_2091c584 + iVar1) = 1;
  return 0;
}


// ===== FUN_2013c928 @ 2013c928 (56 bytes)

undefined4 FUN_2013c928(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 1) {
    (*(code *)((undefined4 *)param_2[1])[1])();
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x2013c95c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)param_2[1])((int)*(short *)(*param_2 + 0x2c4));
  return uVar1;
}

