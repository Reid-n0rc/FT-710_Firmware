// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201530e4 @ 201530e4 (24 bytes)

undefined4 FUN_201530e4(undefined4 *param_1,uint param_2)

{
  param_1[1] = param_2 & 0xfffffff8;
  *param_1 = 0;
  return 0;
}


// ===== FUN_201530fc @ 201530fc (1208 bytes)

/* WARNING: Removing unreachable block (ram,0x20153124) */
/* WARNING: Removing unreachable block (ram,0x20153188) */
/* WARNING: Removing unreachable block (ram,0x201531b0) */

undefined4 FUN_201530fc(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  bool bVar5;
  
  software_interrupt(0);
  puVar3 = (undefined1 *)(param_2 + -0x400);
  iVar2 = 0x400;
  bVar5 = true;
  DAT_208003f0 = puVar3;
  while (bVar5) {
    iVar2 = iVar2 + -1;
    bVar5 = iVar2 != 0;
    puVar3 = puVar3 + -1;
    *puVar3 = 0;
  }
  DAT_208003fc = param_1;
  param_1[1] = (int)puVar3 - (int)param_1 & 0xfffffff8;
  *param_1 = 0;
  DAT_208003f8 = 0;
  DAT_208003f4 = 0;
  DAT_208003c4 = 0;
  DAT_208003bc = 0;
  DAT_208003c8 = 0;
  DAT_208003c0 = 0;
  DAT_208003d0 = 0;
  DAT_208003d8 = 0;
  DAT_208003d4 = 0;
  DAT_208003d9 = 0;
  DAT_208003da = 0;
  DAT_208003dc = 0;
  DAT_208003dd = 0;
  DAT_208003de = 0;
  DAT_208003df = 9;
  DAT_208003b8 = 0;
  DAT_208003b0 = 0;
  DAT_208dc174 = 0;
  iVar2 = 1;
  iVar4 = DAT_201659d0 + 1;
  if (0 < iVar4) {
    do {
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(&DAT_208dbba0 + iVar1) = 0;
    } while (iVar2 <= iVar4);
  }
  iVar2 = 1;
  do {
    iVar4 = iVar2 + 1;
    (&DAT_208dbca4)[iVar2] = 0;
    iVar2 = iVar4;
  } while (iVar4 < 0x41);
  iVar2 = 1;
  do {
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_208dbda4 + iVar4) = 0;
  } while (iVar2 < 0x41);
  iVar2 = 1;
  do {
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_208dbea4 + iVar4) = 0;
  } while (iVar2 < 9);
  iVar2 = 1;
  do {
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_208dbec4 + iVar4) = 0;
  } while (iVar2 < 9);
  iVar2 = 1;
  do {
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(iVar4 + 0x208dbee4) = 0;
  } while (iVar2 < 9);
  iVar2 = 1;
  do {
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_208dbf04 + iVar4) = 0;
  } while (iVar2 < 9);
  iVar2 = 1;
  do {
    iVar4 = iVar2 + 1;
    (&DAT_208dbf24)[iVar2] = 0;
    iVar2 = iVar4;
  } while (iVar4 < 0x11);
  iVar2 = 1;
  do {
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_208dbfa4 + iVar4) = 0;
  } while (iVar2 < 9);
  iVar2 = 1;
  do {
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_208dbf64 + iVar4) = 0;
  } while (iVar2 < 9);
  iVar2 = 1;
  do {
    iVar4 = iVar2 + 1;
    (&DAT_208dbf84)[iVar2] = 0;
    iVar2 = iVar4;
  } while (iVar4 < 9);
  iVar2 = 1;
  do {
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_208dbfc4 + iVar4) = 0;
  } while (iVar2 < 0x21);
  iVar2 = 1;
  do {
    iVar4 = iVar2 + 1;
    (&DAT_208dc044)[iVar2] = 0;
    iVar2 = iVar4;
  } while (iVar4 < 0x41);
  iVar2 = 1;
  do {
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(iVar4 + 0x208dc144) = 0;
  } while (iVar2 < 9);
  iVar2 = 1;
  do {
    (&DAT_208dc18c)[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  iVar2 = 0;
  do {
    (&DAT_20800400)[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  iVar2 = 0;
  do {
    (&DAT_20800401)[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  iVar2 = 0;
  do {
    (&DAT_20800402)[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  DAT_208003db = 1;
  DAT_208003e0 = 0;
  DAT_208003e1 = 0;
  DAT_208003e2 = 0;
  iVar2 = DAT_201659d0 + 1;
  DAT_208003b4 = 8;
  *(undefined **)(&DAT_208dbba0 + iVar2 * 4) = &DAT_208dc178;
  DAT_208dc195 = (undefined1)iVar2;
  DAT_208dc18c = DAT_208dc195;
  return 0;
}


// ===== FUN_201535b4 @ 201535b4 (108 bytes)

void FUN_201535b4(undefined *param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  
  if (param_1 == &DAT_208dbf64) {
    pbVar3 = &DAT_208003e1;
  }
  else {
    pbVar3 = &DAT_208003e2;
  }
  if (param_1 == &DAT_208dbf64) {
    puVar4 = &DAT_20800401;
  }
  else {
    puVar4 = &DAT_20800402;
  }
  pbVar3 = puVar4 + (*(uint *)(param_2 + 4) & (uint)*pbVar3);
  bVar1 = *(byte *)(param_2 + 9);
  if (bVar1 == param_3) {
    *pbVar3 = 0;
  }
  else {
    bVar2 = *(byte *)(param_2 + 8);
    if ((uint)*pbVar3 == (param_3 & 0xff)) {
      *pbVar3 = bVar2;
    }
    *(byte *)(*(int *)(param_1 + (uint)bVar2 * 4) + 9) = bVar1;
    *(byte *)(*(int *)(param_1 + (uint)bVar1 * 4) + 8) = bVar2;
  }
  return;
}


// ===== FUN_20153620 @ 20153620 (256 bytes)

/* WARNING: Removing unreachable block (ram,0x20153688) */
/* WARNING: Removing unreachable block (ram,0x2015369c) */

void FUN_20153620(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  short *psVar8;
  uint uVar9;
  bool bVar10;
  
  uVar3 = DAT_208003c8;
  uVar9 = (uint)DAT_208003c4;
  uVar4 = DAT_208003e2 & DAT_208003c8;
  bVar1 = (&DAT_20800402)[uVar4];
  do {
    uVar5 = (uint)bVar1;
    if (uVar5 == 0) {
      return;
    }
    psVar8 = (short *)(&DAT_208dbf84)[uVar5];
    pbVar6 = (byte *)((int)psVar8 + 9);
    while( true ) {
      uVar7 = *(uint *)(psVar8 + 2);
      bVar10 = uVar7 == uVar3;
      if (bVar10) {
        uVar7 = (uint)*psVar8;
      }
      if (bVar10 && uVar7 == uVar9) break;
      if (uVar5 == *pbVar6) {
        return;
      }
      uVar5 = (uint)*(byte *)(psVar8 + 4);
      psVar8 = (short *)(&DAT_208dbf84)[uVar5];
    }
    bVar1 = *(byte *)((int)psVar8 + 9);
    pbVar6 = &DAT_20800402 + (*(uint *)(psVar8 + 2) & (uint)DAT_208003e2);
    if (bVar1 == uVar5) {
      *pbVar6 = 0;
    }
    else {
      bVar2 = *(byte *)(psVar8 + 4);
      if (*pbVar6 == uVar5) {
        *pbVar6 = bVar2;
      }
      *(byte *)((&DAT_208dbf84)[bVar2] + 9) = bVar1;
      *(byte *)((&DAT_208dbf84)[bVar1] + 8) = bVar2;
    }
    *(undefined1 *)(psVar8 + 4) = 0;
    *(undefined1 *)((int)psVar8 + 9) = 0;
    software_interrupt(0);
    (**(code **)(psVar8 + 8))(*(undefined4 *)(psVar8 + 6));
    software_interrupt(0);
    bVar1 = (&DAT_20800402)[uVar4];
  } while( true );
}


// ===== FUN_20153720 @ 20153720 (104 bytes)

void FUN_20153720(undefined *param_1,int param_2,byte param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  
  if (param_1 == &DAT_208dbf64) {
    pbVar3 = &DAT_208003e1;
  }
  else {
    pbVar3 = &DAT_208003e2;
  }
  if (param_1 == &DAT_208dbf64) {
    puVar4 = &DAT_20800401;
  }
  else {
    puVar4 = &DAT_20800402;
  }
  bVar1 = puVar4[*(uint *)(param_2 + 4) & (uint)*pbVar3];
  if (bVar1 == 0) {
    puVar4[*(uint *)(param_2 + 4) & (uint)*pbVar3] = param_3;
    *(byte *)(param_2 + 8) = param_3;
    *(byte *)(param_2 + 9) = param_3;
    return;
  }
  *(byte *)(param_2 + 8) = bVar1;
  bVar2 = *(byte *)(*(int *)(param_1 + (uint)bVar1 * 4) + 9);
  *(byte *)(*(int *)(param_1 + (uint)bVar1 * 4) + 9) = param_3;
  *(byte *)(param_2 + 9) = bVar2;
  *(byte *)(*(int *)(param_1 + (uint)bVar2 * 4) + 8) = param_3;
  return;
}


// ===== FUN_20153788 @ 20153788 (332 bytes)

void FUN_20153788(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  short *psVar10;
  uint uVar11;
  bool bVar12;
  
  uVar5 = DAT_208003c8;
  sVar4 = DAT_208003c4;
  uVar11 = (uint)DAT_208003c4;
  uVar6 = DAT_208003e1 & DAT_208003c8;
  do {
    uVar7 = (uint)(byte)(&DAT_20800401)[uVar6];
    if (uVar7 == 0) {
      return;
    }
    psVar10 = *(short **)(&DAT_208dbf64 + uVar7 * 4);
    pbVar9 = (byte *)((int)psVar10 + 9);
    while( true ) {
      uVar8 = *(uint *)(psVar10 + 2);
      bVar12 = uVar8 == uVar5;
      if (bVar12) {
        uVar8 = (uint)*psVar10;
      }
      if (bVar12 && uVar8 == uVar11) break;
      if (uVar7 == *pbVar9) {
        return;
      }
      uVar7 = (uint)*(byte *)(psVar10 + 4);
      psVar10 = *(short **)(&DAT_208dbf64 + uVar7 * 4);
    }
    bVar1 = *(byte *)((int)psVar10 + 9);
    pbVar9 = &DAT_20800401 + (*(uint *)(psVar10 + 2) & (uint)DAT_208003e1);
    if (bVar1 == uVar7) {
      *pbVar9 = 0;
    }
    else {
      bVar2 = *(byte *)(psVar10 + 4);
      if (*pbVar9 == uVar7) {
        *pbVar9 = bVar2;
      }
      *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar2 * 4) + 9) = bVar1;
      *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar1 * 4) + 8) = bVar2;
    }
    uVar8 = *(uint *)(psVar10 + 10) + uVar5;
    *(uint *)(psVar10 + 2) = uVar8;
    *psVar10 = psVar10[8] + sVar4;
    if (uVar8 < *(uint *)(psVar10 + 10)) {
      *psVar10 = psVar10[8] + sVar4 + 1;
    }
    bVar1 = (&DAT_20800401)[DAT_208003e1 & uVar8];
    bVar2 = (byte)uVar7;
    if (bVar1 == 0) {
      (&DAT_20800401)[DAT_208003e1 & uVar8] = bVar2;
      *(byte *)(psVar10 + 4) = bVar2;
      *(byte *)((int)psVar10 + 9) = bVar2;
    }
    else {
      *(byte *)(psVar10 + 4) = bVar1;
      bVar3 = *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar1 * 4) + 9);
      *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar1 * 4) + 9) = bVar2;
      *(byte *)((int)psVar10 + 9) = bVar3;
      *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar3 * 4) + 8) = bVar2;
    }
    software_interrupt(0);
    if ((*(byte *)(psVar10 + 6) & 1) != 0) {
      (**(code **)(psVar10 + 0xe))(*(undefined4 *)(psVar10 + 0xc));
    }
    software_interrupt(0);
  } while( true );
}


// ===== FUN_201538d4 @ 201538d4 (80 bytes)

void FUN_201538d4(byte *param_1,int param_2,byte param_3)

{
  byte bVar1;
  byte bVar2;
  
  *(byte **)(param_2 + 0x10) = param_1;
  bVar1 = *param_1;
  if (bVar1 != 0) {
    *(byte *)(param_2 + 6) = bVar1;
    bVar2 = *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 7);
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 7) = param_3;
    *(byte *)(param_2 + 7) = bVar2;
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar2 * 4) + 6) = param_3;
    return;
  }
  *param_1 = param_3;
  *(byte *)(param_2 + 6) = param_3;
  *(byte *)(param_2 + 7) = param_3;
  return;
}


// ===== FUN_201539ec @ 201539ec (76 bytes)

void FUN_201539ec(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  bVar1 = *(byte *)(param_1 + 7);
  pbVar3 = *(byte **)(param_1 + 0x10);
  if (bVar1 == param_2) {
    *pbVar3 = 0;
  }
  else {
    bVar2 = *(byte *)(param_1 + 6);
    if ((uint)*pbVar3 == (param_2 & 0xff)) {
      *pbVar3 = bVar2;
    }
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar2 * 4) + 7) = bVar1;
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 6) = bVar2;
  }
  return;
}


// ===== FUN_20153a38 @ 20153a38 (156 bytes)

void FUN_20153a38(byte *param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  bVar1 = *(byte *)(param_2 + 7);
  pbVar4 = *(byte **)(param_2 + 0x10);
  if (bVar1 == param_3) {
    *pbVar4 = 0;
  }
  else {
    bVar2 = *(byte *)(param_2 + 6);
    if (*pbVar4 == param_3) {
      *pbVar4 = bVar2;
    }
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar2 * 4) + 7) = bVar1;
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 6) = bVar2;
  }
  bVar2 = (byte)param_3;
  *(byte **)(param_2 + 0x10) = param_1;
  bVar1 = *param_1;
  if (bVar1 == 0) {
    *param_1 = bVar2;
    *(byte *)(param_2 + 6) = bVar2;
    *(byte *)(param_2 + 7) = bVar2;
    return;
  }
  *(byte *)(param_2 + 6) = bVar1;
  bVar3 = *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 7);
  *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 7) = bVar2;
  *(byte *)(param_2 + 7) = bVar3;
  *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar3 * 4) + 6) = bVar2;
  return;
}


// ===== knl_timeout_remove @ 20153ad4 (96 bytes)

/* (tcb, tskid): unlinks the TCB from its timer-wheel slot [fact] */

void knl_timeout_remove(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  pbVar3 = &DAT_20800400 + (*(uint *)(param_1 + 0xc) & (uint)DAT_208003e0);
  bVar1 = *(byte *)(param_1 + 0xb);
  if (bVar1 == param_2) {
    *pbVar3 = 0;
  }
  else {
    bVar2 = *(byte *)(param_1 + 10);
    if ((uint)*pbVar3 == (param_2 & 0xff)) {
      *pbVar3 = bVar2;
    }
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar2 * 4) + 0xb) = bVar1;
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 10) = bVar2;
  }
  return;
}


// ===== FUN_20153b34 @ 20153b34 (88 bytes)

void FUN_20153b34(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_2 + 7U & 0xfffffff8;
  if (uVar3 != 0) {
    puVar1 = (undefined4 *)*param_1;
    do {
      puVar2 = param_1;
      param_1 = puVar1;
      if (param_1 == (undefined4 *)0x0) {
        return;
      }
      puVar1 = (undefined4 *)*param_1;
    } while ((uint)param_1[1] < uVar3);
    iVar4 = param_1[1] - uVar3;
    if (iVar4 == 0) {
      *puVar2 = puVar1;
    }
    else {
      param_1 = (undefined4 *)(uVar3 + (int)param_1);
      *puVar2 = param_1;
      *param_1 = puVar1;
      param_1[1] = iVar4;
    }
  }
  return;
}


// ===== FUN_20153b8c @ 20153b8c (328 bytes)

byte FUN_20153b8c(int param_1)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  byte *pbVar4;
  int *piVar5;
  uint uVar6;
  byte *pbVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  
  bVar8 = 0;
  iVar10 = *(int *)(&DAT_208dbf04 + param_1 * 4);
  pbVar7 = (byte *)(iVar10 + 0x10);
  bVar1 = *(byte *)(iVar10 + 0x10);
  do {
    uVar6 = (uint)bVar1;
    if (0xfd < uVar6) {
      return bVar8;
    }
    while (uVar6 != 0) {
      piVar5 = *(int **)(&DAT_208dbba0 + uVar6 * 4);
      iVar9 = *(int *)(*piVar5 + 8) + 8;
      piVar3 = (int *)FUN_20153b34(iVar10 + 4,iVar9);
      if (piVar3 == (int *)0x0) {
        return bVar8;
      }
      *piVar3 = iVar9;
      **(int **)(*piVar5 + 0xc) = (int)(piVar3 + 2);
      if ((*(byte *)((int)piVar5 + 5) & 2) != 0) {
        pbVar4 = &DAT_20800400 + (piVar5[3] & (uint)DAT_208003e0);
        bVar1 = *(byte *)((int)piVar5 + 0xb);
        if (bVar1 == uVar6) {
          *pbVar4 = 0;
        }
        else {
          bVar2 = *(byte *)((int)piVar5 + 10);
          if (*pbVar4 == uVar6) {
            *pbVar4 = bVar2;
          }
          *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar2 * 4) + 0xb) = bVar1;
          *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 10) = bVar2;
        }
      }
      *(undefined1 *)((int)piVar5 + 5) = 0x10;
      if (*(char *)((int)piVar5 + 9) == '\0') {
        iVar9 = (int)(char)piVar5[1];
        if (iVar9 < DAT_208003df) {
          bVar8 = bVar8 | iVar9 < DAT_208003df;
        }
        FUN_20153a38(&DAT_208dc18c + iVar9,piVar5,uVar6);
      }
      else {
        FUN_201539ec(piVar5,uVar6);
      }
      uVar6 = (uint)*pbVar7;
    }
    pbVar7 = pbVar7 + 1;
    bVar1 = *pbVar7;
  } while( true );
}


// ===== FUN_20153cd4 @ 20153cd4 (280 bytes)

undefined4 FUN_20153cd4(int param_1,undefined1 *param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = *(ushort *)(param_1 + 0xe);
  if (*(short *)(param_1 + 0x10) == 1) {
    if (uVar1 != 0) {
      *(ushort *)(param_1 + 0xe) = uVar1 - 1;
      uVar1 = *(ushort *)(param_1 + 8);
      *(undefined1 *)(*(int *)(param_1 + 4) + (uint)uVar1) = *param_2;
      uVar6 = uVar1 + 1;
      if (uVar6 == *(ushort *)(param_1 + 0xc)) {
        uVar6 = 0;
      }
      *(short *)(param_1 + 8) = (short)uVar6;
      return 1;
    }
  }
  else if (param_3 + 2 <= (uint)uVar1) {
    uVar6 = param_3 & 0xffff;
    uVar2 = *(ushort *)(param_1 + 8);
    *(ushort *)(param_1 + 0xe) = (uVar1 - (short)param_3) + -2;
    *(char *)(*(int *)(param_1 + 4) + (uint)uVar2) = (char)uVar6;
    uVar4 = uVar2 + 1;
    if (*(ushort *)(param_1 + 0xc) == uVar4) {
      uVar4 = 0;
    }
    *(char *)(*(int *)(param_1 + 4) + uVar4) = (char)(uVar6 >> 8);
    uVar4 = uVar4 + 1;
    uVar7 = (uint)*(ushort *)(param_1 + 0xc);
    if (uVar7 == uVar4) {
      uVar4 = 0;
    }
    if (uVar7 <= uVar6 + uVar4) {
      iVar5 = uVar7 - uVar4;
      uVar6 = uVar6 - iVar5 & 0xffff;
      puVar3 = (undefined1 *)(*(int *)(param_1 + 4) + uVar4);
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar3 = *param_2;
        puVar3 = puVar3 + 1;
        param_2 = param_2 + 1;
      }
      uVar4 = 0;
    }
    *(short *)(param_1 + 8) = (short)uVar4 + (short)uVar6;
    puVar3 = (undefined1 *)(*(int *)(param_1 + 4) + uVar4);
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar3 = *param_2;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
    return 1;
  }
  return 0;
}


// ===== FUN_20153dec @ 20153dec (316 bytes)

byte FUN_20153dec(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  uint uVar7;
  byte *pbVar8;
  byte bVar9;
  
  bVar9 = 0;
  iVar3 = *(int *)(&DAT_208dbec4 + param_1 * 4);
  pbVar8 = (byte *)(iVar3 + 0x13);
  do {
    uVar7 = (uint)*pbVar8;
    if (uVar7 != 0) {
      if (0xfd < uVar7) {
        return bVar9;
      }
      do {
        piVar6 = *(int **)(&DAT_208dbba0 + uVar7 * 4);
        if (*(int *)(*piVar6 + 8) == 0) {
          return bVar9;
        }
        iVar4 = FUN_20153cd4(iVar3,*(undefined4 *)(*piVar6 + 0xc));
        if (iVar4 == 0) {
          return bVar9;
        }
        if ((*(byte *)((int)piVar6 + 5) & 2) != 0) {
          bVar1 = *(byte *)((int)piVar6 + 0xb);
          pbVar5 = &DAT_20800400 + (piVar6[3] & (uint)DAT_208003e0);
          if (bVar1 == uVar7) {
            *pbVar5 = 0;
          }
          else {
            bVar2 = *(byte *)((int)piVar6 + 10);
            if (*pbVar5 == uVar7) {
              *pbVar5 = bVar2;
            }
            *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar2 * 4) + 0xb) = bVar1;
            *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 10) = bVar2;
          }
        }
        *(undefined1 *)((int)piVar6 + 5) = 0x10;
        if (*(char *)((int)piVar6 + 9) == '\0') {
          iVar4 = (int)(char)piVar6[1];
          if (iVar4 < DAT_208003df) {
            bVar9 = bVar9 | iVar4 < DAT_208003df;
          }
          FUN_20153a38(&DAT_208dc18c + iVar4,piVar6,uVar7);
        }
        else {
          FUN_201539ec(piVar6,uVar7);
        }
        uVar7 = (uint)*pbVar8;
      } while (uVar7 != 0);
    }
    pbVar8 = pbVar8 + 1;
  } while( true );
}


// ===== FUN_20153f28 @ 20153f28 (412 bytes)

void FUN_20153f28(uint param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)(&DAT_208dbba0 + param_1 * 4);
  while( true ) {
    iVar1 = (int)(short)piVar5[9];
    iVar3 = (int)*(char *)((int)piVar5 + 0x27);
    do {
      iVar1 = *(int *)(&DAT_208dbfc4 + iVar1 * 4);
      if (*(int *)(iVar1 + 4) == 2) {
        iVar4 = 1;
        for (pcVar2 = (char *)(iVar1 + 0xc); *pcVar2 == '\0'; pcVar2 = pcVar2 + 1) {
          iVar4 = iVar4 + 1;
        }
        if (iVar4 < iVar3) {
          iVar3 = iVar4;
        }
        *(char *)(iVar1 + 0xb) = (char)iVar4;
      }
      else if ((*(int *)(iVar1 + 4) == 3) && (*(char *)(iVar1 + 0xb) < iVar3)) {
        iVar3 = (int)*(char *)(iVar1 + 0xb);
      }
      iVar1 = (int)*(short *)(iVar1 + 8);
    } while (iVar1 != 0);
    iVar1 = piVar5[1];
    if ((char)iVar1 == iVar3) {
      return;
    }
    *(char *)(piVar5 + 1) = (char)iVar3;
    if (*(char *)((int)piVar5 + 5) == '\x10') {
      if (*(char *)((int)piVar5 + 9) != '\0') {
        return;
      }
      FUN_20153a38(&DAT_208dc18c + iVar3,piVar5,param_1);
    }
    if (*(byte *)((int)piVar5 + 5) < 0x50) {
      return;
    }
    if (*(char *)(piVar5[4] + 1) != -2) {
      FUN_20153a38(piVar5[4] - ((int)(char)iVar1 - (int)(char)iVar3),piVar5,param_1);
    }
    if ((*(byte *)((int)piVar5 + 5) & 0xfc) != 0x94) {
      if ((*(byte *)((int)piVar5 + 5) & 0xfc) == 0x60) {
        FUN_20153dec(*(undefined4 *)(*piVar5 + 4));
        return;
      }
      if ((*(byte *)((int)piVar5 + 5) & 0xf0) != 0xc0) {
        return;
      }
      FUN_20153b8c(*(undefined4 *)(*piVar5 + 4));
      return;
    }
    iVar3 = *(int *)(&DAT_208dbfc4 + *(int *)(*piVar5 + 4) * 4);
    if (*(int *)(iVar3 + 4) != 2) {
      return;
    }
    iVar1 = 1;
    for (pcVar2 = (char *)(iVar3 + 0xc); *pcVar2 == '\0'; pcVar2 = pcVar2 + 1) {
      iVar1 = iVar1 + 1;
    }
    if (*(char *)(iVar3 + 0xb) == iVar1) break;
    param_1 = (uint)*(byte *)(iVar3 + 10);
    *(char *)(iVar3 + 0xb) = (char)iVar1;
    piVar5 = *(int **)(&DAT_208dbba0 + param_1 * 4);
  }
  return;
}


// ===== FUN_201540c4 @ 201540c4 (492 bytes)

code * FUN_201540c4(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  int *piVar9;
  code *pcVar10;
  
  uVar4 = DAT_208003c8;
  pcVar5 = (code *)&DAT_208003e0;
  uVar7 = DAT_208003c8 & DAT_208003e0;
  do {
    pcVar10 = (code *)(uint)(byte)(&DAT_20800400)[uVar7];
    if (pcVar10 == (code *)0x0) {
      return pcVar5;
    }
    piVar9 = *(int **)(&DAT_208dbba0 + (int)pcVar10 * 4);
    pbVar8 = (byte *)((int)piVar9 + 0xb);
    while (piVar9[3] != uVar4) {
      if (pcVar10 == (code *)(uint)*pbVar8) {
        return (code *)(uint)*pbVar8;
      }
      pcVar10 = (code *)(uint)*(byte *)((int)piVar9 + 10);
      piVar9 = *(int **)(&DAT_208dbba0 + (int)pcVar10 * 4);
    }
    pbVar8 = &DAT_20800400 + (piVar9[3] & (uint)DAT_208003e0);
    bVar1 = *(byte *)((int)piVar9 + 0xb);
    if ((code *)(uint)bVar1 == pcVar10) {
      *pbVar8 = 0;
    }
    else {
      bVar2 = *(byte *)((int)piVar9 + 10);
      if ((code *)(uint)*pbVar8 == pcVar10) {
        *pbVar8 = bVar2;
      }
      *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar2 * 4) + 0xb) = bVar1;
      *(byte *)(*(int *)(&DAT_208dbba0 + (int)(uint)bVar1 * 4) + 10) = bVar2;
    }
    bVar1 = *(byte *)((int)piVar9 + 5);
    *(undefined1 *)((int)piVar9 + 5) = 0x10;
    if ((bVar1 & 0xf0) == 0x30) {
      *(undefined4 *)*piVar9 = 0;
    }
    else {
      *(undefined4 *)*piVar9 = 0xffffffce;
      if (0x4f < bVar1) {
        FUN_201539ec(piVar9,pcVar10);
        if ((bVar1 & 0xfc) == 0x94) {
          iVar6 = *(int *)(&DAT_208dbfc4 + *(int *)(*piVar9 + 4) * 4);
          if ((*(int *)(iVar6 + 4) == 2) && ((char)piVar9[1] <= *(char *)(iVar6 + 0xb))) {
            FUN_20153f28(*(undefined1 *)(iVar6 + 10));
          }
        }
        else if ((bVar1 & 0xfc) == 0x60) {
          FUN_20153dec(*(undefined4 *)(*piVar9 + 4));
        }
        else if ((bVar1 & 0xf0) == 0xc0) {
          FUN_20153b8c(*(undefined4 *)(*piVar9 + 4));
        }
      }
    }
    if (*(char *)((int)piVar9 + 9) == '\0') {
      if ((int)(char)piVar9[1] < (int)DAT_208003df) {
        DAT_208003d9 = 1;
      }
      pbVar8 = &DAT_208dc18c + (char)piVar9[1];
      piVar9[4] = (int)pbVar8;
      bVar1 = *pbVar8;
      bVar2 = (byte)pcVar10;
      if (bVar1 == 0) {
        *pbVar8 = bVar2;
        *(byte *)((int)piVar9 + 6) = bVar2;
        *(byte *)((int)piVar9 + 7) = bVar2;
      }
      else {
        *(byte *)((int)piVar9 + 6) = bVar1;
        bVar3 = *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 7);
        *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 7) = bVar2;
        *(byte *)((int)piVar9 + 7) = bVar3;
        *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar3 * 4) + 6) = bVar2;
      }
    }
    pcVar5 = FUN_20156830;
    software_interrupt(0);
  } while( true );
}


// ===== FUN_201543e4 @ 201543e4 (56 bytes)

void FUN_201543e4(short *param_1,short *param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 2);
  iVar4 = *(int *)(param_2 + 2);
  *(int *)(param_3 + 2) = iVar3 + iVar4;
  sVar1 = *param_1;
  sVar2 = *param_2;
  *param_3 = sVar2 + sVar1;
  if ((uint)(iVar3 + iVar4) < *(uint *)(param_1 + 2)) {
    *param_3 = sVar2 + sVar1 + 1;
  }
  return;
}


// ===== FUN_2015441c @ 2015441c (124 bytes)

void FUN_2015441c(short *param_1,short *param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  
  sVar1 = *param_2;
  sVar2 = *param_1;
  if (sVar1 <= sVar2) {
    *param_3 = 0;
  }
  if (sVar1 < sVar2) {
    param_3[2] = 0;
    param_3[3] = 0;
  }
  if (sVar2 < sVar1) {
    *param_3 = sVar1 - sVar2;
    if (*(uint *)(param_2 + 2) < *(uint *)(param_1 + 2)) {
      *param_3 = (sVar1 - sVar2) + -1;
    }
    *(int *)(param_3 + 2) = *(int *)(param_2 + 2) - *(int *)(param_1 + 2);
  }
  else if (sVar1 == sVar2) {
    if (*(uint *)(param_2 + 2) < *(uint *)(param_1 + 2)) {
      param_3[2] = 0;
      param_3[3] = 0;
    }
    else {
      *(uint *)(param_3 + 2) = *(uint *)(param_2 + 2) - *(uint *)(param_1 + 2);
    }
    return;
  }
  return;
}


// ===== knl_timeout_add @ 20154498 (112 bytes)

/* (tmout, tcb, tskid): due time = tmout + system time 0x208003C8, links the TCB into the timer
   wheel 0x20800400 (mask 0x208003E0) [fact] */

void knl_timeout_add(int param_1,int param_2,byte param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = param_1 + DAT_208003c8;
  *(uint *)(param_2 + 0xc) = uVar3;
  bVar1 = (&DAT_20800400)[uVar3 & DAT_208003e0];
  if (bVar1 != 0) {
    *(byte *)(param_2 + 10) = bVar1;
    bVar2 = *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 0xb);
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar1 * 4) + 0xb) = param_3;
    *(byte *)(param_2 + 0xb) = bVar2;
    *(byte *)(*(int *)(&DAT_208dbba0 + (uint)bVar2 * 4) + 10) = param_3;
    return;
  }
  (&DAT_20800400)[uVar3 & DAT_208003e0] = param_3;
  *(byte *)(param_2 + 10) = param_3;
  *(byte *)(param_2 + 0xb) = param_3;
  return;
}


// ===== FUN_20154508 @ 20154508 (28 bytes)

void FUN_20154508(int param_1,undefined4 param_2)

{
  FUN_20153a38(&DAT_208dc18c + *(char *)(param_1 + 4),param_1,param_2);
  return;
}


// ===== FUN_20154524 @ 20154524 (20 bytes)

code * FUN_20154524(void)

{
  FUN_201539ec();
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== FUN_20154538 @ 20154538 (72 bytes)

code * FUN_20154538(int param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 4);
  FUN_201538d4(&DAT_208dc18c + cVar1,param_1,param_2);
  if ((int)cVar1 < (int)DAT_208003df) {
    software_interrupt(0);
    return FUN_2015655c;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== FUN_20154580 @ 20154580 (72 bytes)

code * FUN_20154580(int param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 4);
  FUN_20153a38(&DAT_208dc18c + cVar1,param_1,param_2);
  if ((int)cVar1 < (int)DAT_208003df) {
    software_interrupt(0);
    return FUN_2015655c;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== FUN_201545c8 @ 201545c8 (20 bytes)

code * FUN_201545c8(void)

{
  FUN_201539ec();
  software_interrupt(0);
  return FUN_201566f0;
}


// ===== FUN_201545dc @ 201545dc (20 bytes)

code * FUN_201545dc(void)

{
  FUN_20153a38();
  software_interrupt(0);
  return FUN_201566f0;
}


// ===== knl_memcpy @ 201545f0 (28 bytes)

/* Byte copy used by the acre_* calls to copy the creation packet [fact] */

void knl_memcpy(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_2015460c @ 2015460c (176 bytes)

undefined4 FUN_2015460c(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = param_3 + 7U & 0xfffffff8;
  iVar2 = 0;
  puVar3 = (undefined4 *)*param_1;
  do {
    if (puVar3 == (undefined4 *)0x0) {
LAB_2015463c:
      if ((undefined4 *)((int)param_1 + iVar2) == param_2) {
        uVar4 = uVar4 + iVar2;
        param_2 = param_1;
      }
      else {
        *param_1 = param_2;
      }
      if (puVar3 == (undefined4 *)0x0) {
        *param_2 = 0;
      }
      else {
        if ((undefined4 *)((int)param_2 + uVar4) == puVar3) {
          *param_2 = *puVar3;
          param_2[1] = puVar3[1] + uVar4;
          return 0;
        }
        *param_2 = puVar3;
      }
      param_2[1] = uVar4;
      return 0;
    }
    if (param_2 < puVar3) {
      if (puVar3 < (undefined4 *)((int)param_2 + uVar4)) {
        return 0xffffffef;
      }
      goto LAB_2015463c;
    }
    iVar2 = puVar3[1];
    puVar1 = (undefined4 *)((int)puVar3 + iVar2);
    param_1 = puVar3;
    puVar3 = (undefined4 *)*puVar3;
    if (param_2 < puVar1) {
      return 0xffffffef;
    }
  } while( true );
}


// ===== FUN_201546bc @ 201546bc (72 bytes)

uint FUN_201546bc(uint *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  for (; param_1 != (uint *)0x0; param_1 = (uint *)(*param_1 & 0xfffffffe)) {
    if ((*param_1 & 1) == 0) {
      uVar1 = param_1[1];
    }
    else {
      uVar1 = 8;
    }
    iVar2 = iVar2 + uVar1;
    if (uVar3 < uVar1) {
      uVar3 = uVar1;
    }
  }
  *param_2 = iVar2;
  return uVar3;
}


// ===== FUN_20154704 @ 20154704 (12 bytes)

void FUN_20154704(undefined4 param_1)

{
  FUN_20153b34(&DAT_208003fc,param_1);
  return;
}


// ===== FUN_20154710 @ 20154710 (16 bytes)

void FUN_20154710(undefined4 param_1,undefined4 param_2)

{
  FUN_2015460c(&DAT_208003fc,param_1,param_2);
  return;
}


// ===== FUN_20154720 @ 20154720 (36 bytes)

/* WARNING: Removing unreachable block (ram,0x20154734) */

void FUN_20154720(undefined4 param_1)

{
  FUN_20153b34(&DAT_208003fc,param_1);
  return;
}


// ===== FUN_20154744 @ 20154744 (40 bytes)

/* WARNING: Removing unreachable block (ram,0x2015475c) */

void FUN_20154744(undefined4 param_1,undefined4 param_2)

{
  FUN_2015460c(&DAT_208003fc,param_1,param_2);
  return;
}


// ===== FUN_2015476c @ 2015476c (36 bytes)

/* WARNING: Removing unreachable block (ram,0x20154780) */

void FUN_2015476c(undefined4 param_1)

{
  FUN_20153b34(&DAT_208003fc,param_1);
  return;
}


// ===== FUN_20154790 @ 20154790 (40 bytes)

/* WARNING: Removing unreachable block (ram,0x201547a8) */

void FUN_20154790(undefined4 param_1,undefined4 param_2)

{
  FUN_2015460c(&DAT_208003fc,param_1,param_2);
  return;
}


// ===== FUN_201547d0 @ 201547d0 (352 bytes)

byte FUN_201547d0(int param_1,undefined2 param_2)

{
  undefined2 uVar1;
  char cVar2;
  undefined4 extraout_r3;
  undefined4 *puVar3;
  uint uVar4;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  
  bVar6 = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  iVar7 = *(int *)(param_1 + 4);
  pbVar5 = (byte *)(param_1 + 0xc);
  cVar2 = *(char *)(param_1 + 0xb);
  iVar8 = param_1;
  do {
    uVar4 = (uint)*pbVar5;
    if (0xfd < uVar4) {
      return bVar6;
    }
    while (uVar4 != 0) {
      puVar3 = *(undefined4 **)(&DAT_208dbba0 + uVar4 * 4);
      if ((*(byte *)((int)puVar3 + 5) & 2) != 0) {
        knl_timeout_remove(puVar3,uVar4);
      }
      FUN_201539ec(puVar3,uVar4);
      *(undefined1 *)((int)puVar3 + 5) = 0x10;
      if (iVar7 != 3) {
LAB_201548b0:
        if (cVar2 != '\0') {
          *(undefined1 *)(param_1 + 0xb) = *(undefined1 *)(puVar3 + 1);
        }
LAB_201548bc:
        *(char *)(param_1 + 10) = (char)uVar4;
        uVar1 = *(undefined2 *)(puVar3 + 9);
        *(undefined2 *)(puVar3 + 9) = param_2;
        *(undefined2 *)(param_1 + 8) = uVar1;
        if (*(char *)((int)puVar3 + 9) == '\0') {
          FUN_201538d4(&DAT_208dc18c + *(char *)(puVar3 + 1),puVar3,uVar4,extraout_r3,iVar8);
        }
        if ((bVar6 == 0) && (DAT_208003df <= *(char *)(puVar3 + 1))) {
          bVar6 = 0;
        }
        else {
          bVar6 = 1;
        }
        return bVar6;
      }
      if (cVar2 <= *(char *)((int)puVar3 + 0x27)) {
        if (cVar2 <= *(char *)(puVar3 + 1)) {
          *(char *)(puVar3 + 1) = cVar2;
          goto LAB_201548bc;
        }
        goto LAB_201548b0;
      }
      *(undefined4 *)*puVar3 = 0xffffffe4;
      if (*(char *)((int)puVar3 + 9) == '\0') {
        FUN_201538d4(&DAT_208dc18c + *(char *)(puVar3 + 1),puVar3,uVar4,extraout_r3,iVar8);
      }
      bVar6 = bVar6 | *(char *)(puVar3 + 1) < DAT_208003df;
      uVar4 = (uint)*pbVar5;
    }
    pbVar5 = pbVar5 + 1;
  } while( true );
}


// ===== FUN_20154930 @ 20154930 (52 bytes)

void FUN_20154930(int param_1)

{
  short sVar1;
  int iVar2;
  
  do {
    iVar2 = *(int *)(&DAT_208dbfc4 + param_1 * 4);
    sVar1 = *(short *)(iVar2 + 8);
    *(undefined2 *)(iVar2 + 8) = 0;
    FUN_201547d0(iVar2,param_1);
    param_1 = (int)sVar1;
  } while (sVar1 != 0);
  return;
}


// ===== __rt_ctype_table @ 20154974 (10 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.850): returns __rt_locale()+4; tolower indexes
   the table it points to [inference] */

int __rt_ctype_table(void)

{
  int iVar1;
  
  iVar1 = __rt_locale();
  return iVar1 + 4;
}


// ===== __aeabi_ldivmod @ 20154984 (96 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.950): A32: takes signs of r1/r3, negates 64-bit
   pairs (rsbs/rsc), bl __aeabi_uldivmod, fixes quotient and remainder signs [inference] */

int __aeabi_ldivmod(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  uVar2 = param_2 >> 1;
  uVar1 = param_4 >> 1;
  if ((int)uVar2 < 0) {
    bVar4 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -param_2;
    if (bVar4) {
      param_2 = param_2 + -1;
    }
  }
  if ((int)param_4 < 0) {
    bVar4 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -param_4;
    if (bVar4) {
      param_4 = param_4 - 1;
    }
  }
  iVar3 = __aeabi_uldivmod(param_1,param_2,param_3,param_4);
  if (((uVar2 ^ uVar1) & 0x40000000) != 0) {
    iVar3 = -iVar3;
  }
  return iVar3;
}


// ===== tolower @ 201549e4 (26 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.900): ctype bit 0x10 (upper) -> c+32
   [inference] */

int tolower(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)__rt_ctype_table();
  if ((int)((uint)*(byte *)(*piVar1 + param_1) << 0x1b) < 0) {
    return param_1 + 0x20;
  }
  return param_1;
}


// ===== sprintf_veneer @ 20154a00 (8 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (veneer_pattern 1.000): A32 add ip,pc,#1; bx ip -> Thumb
   sprintf 0x20154A08 [fact] */

void sprintf_veneer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_20 = param_1;
  uStack_1c = param_4;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_20155f72(param_2,&uStack_20,&uStack_8,0x20155f99);
  _sputc(0,&uStack_20);
  return;
}


// ===== sprintf @ 20154a08 (34 bytes)

void sprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_20 = param_1;
  uStack_1c = param_4;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_20155f72(param_2,&local_20,&uStack_8,0x20155f99);
  _sputc(0,&local_20);
  return;
}


// ===== snprintf @ 20154a30 (48 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.900): (buf, n, fmt, ...): end = buf+n-1, output
   fn _snputc 0x20155FA3, NUL-terminates when n != 0 [inference] */

void snprintf(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int local_20;
  int local_1c;
  undefined4 uStack_4;
  
  local_1c = param_1;
  if (param_2 != 0) {
    local_1c = param_1 + param_2 + -1;
  }
  local_20 = param_1;
  uStack_4 = param_4;
  FUN_20155f72(param_3,&local_20,&uStack_4,0x20155fa3);
  if (param_2 != 0) {
    _sputc(0,&local_20);
  }
  return;
}


// ===== _printf_pre_padding @ 20154a64 (44 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.800): emits width-1.. pad chars (0x30 if the 0
   flag, else 0x20) unless the - flag (bit 0), counts in +0x20 [inference] */

void _printf_pre_padding(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[6];
  if ((int)(*param_1 << 0x1b) < 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0x20;
  }
  if ((*param_1 & 1) != 0) {
    return;
  }
  while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
    (*(code *)param_1[1])(uVar2,param_1[2]);
    param_1[8] = param_1[8] + 1;
  }
  return;
}


// ===== _printf_post_padding @ 20154a90 (34 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.800): emits trailing spaces when the - flag
   (bit 0) is set [inference] */

void _printf_post_padding(byte *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((*param_1 & 1) == 0) {
    return;
  }
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    (**(code **)(param_1 + 4))(0x20,*(undefined4 *)(param_1 + 8));
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  return;
}


// ===== FUN_20154ab2 @ 20154ab2 (82 bytes)

void FUN_20154ab2(byte *param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  
  if (param_3 == 1) {
    uVar1 = 1;
  }
  else {
    if ((int)((uint)*param_1 << 0x1a) < 0) {
      param_3 = *(uint *)(param_1 + 0x1c);
    }
    for (uVar1 = 0; (uVar1 < param_3 && (param_2[uVar1] != '\0')); uVar1 = uVar1 + 1) {
    }
  }
  puVar2 = param_2 + uVar1;
  *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - uVar1;
  *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + uVar1;
  _printf_pre_padding(param_1);
  for (; param_2 < puVar2; param_2 = param_2 + 1) {
    (**(code **)(param_1 + 4))(*param_2,*(undefined4 *)(param_1 + 8));
  }
  _printf_post_padding(param_1);
  return;
}


// ===== FUN_20154c48 @ 20154c48 (388 bytes)

uint FUN_20154c48(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  
  param_1[8] = 0;
  while (uVar1 = (*(code *)param_1[3])(param_1), uVar1 != 0) {
    if (uVar1 == 0x25) {
      uVar4 = 0;
      while (((uVar1 = (*(code *)param_1[3])(param_1), 0x1f < (int)uVar1 && (uVar1 < 0x31)) &&
             ((byte)"0123456789ABCDEF@0X"[uVar1 + 8] != 0))) {
        uVar4 = uVar4 | (byte)"0123456789ABCDEF@0X"[uVar1 + 8];
      }
      if ((int)(uVar4 << 0x1e) < 0) {
        uVar4 = uVar4 & 0xfffffffb;
      }
      param_1[7] = 0;
      iVar5 = 0;
      param_1[6] = 0;
      puVar6 = param_2;
      do {
        if (uVar1 == 0x2a) {
          param_2 = puVar6 + 1;
          param_1[iVar5 + 6] = *puVar6;
          uVar1 = (*(code *)param_1[3])(param_1);
          if (iVar5 == 1) {
            if ((int)param_1[7] < 0) {
              uVar4 = uVar4 & 0xffffffdf;
            }
            break;
          }
        }
        else {
          iVar2 = FUN_20163864(uVar1);
          if (iVar2 != 0) {
            param_1[iVar5 + 6] = uVar1 - 0x30;
            while( true ) {
              uVar1 = (*(code *)param_1[3])(param_1);
              iVar2 = FUN_20163864();
              if (iVar2 == 0) break;
              param_1[iVar5 + 6] = (uVar1 + param_1[iVar5 + 6] * 10) - 0x30;
            }
          }
          param_2 = puVar6;
          if (iVar5 == 1) break;
        }
        if (uVar1 != 0x2e) break;
        uVar1 = (*(code *)param_1[3])(param_1);
        iVar5 = iVar5 + 1;
        uVar4 = uVar4 | 0x20;
        puVar6 = param_2;
      } while (iVar5 < 2);
      if ((int)param_1[6] < 0) {
        uVar4 = uVar4 | 1;
        param_1[6] = -param_1[6];
      }
      if ((uVar4 & 1) != 0) {
        uVar4 = uVar4 & 0xffffffef;
      }
      if ((uVar1 == 0x6c) || (uVar1 == 0x68)) {
        uVar3 = (*(code *)param_1[3])(param_1);
        if (uVar3 == uVar1) {
          if (uVar1 == 0x6c) goto LAB_20154db4;
          uVar1 = 0x400;
          goto LAB_20154d6a;
        }
        if (uVar1 == 0x6c) {
          uVar1 = 0x40;
        }
        else {
          uVar1 = 0x100;
        }
        uVar4 = uVar4 | uVar1;
        uVar1 = uVar3;
      }
      else {
        if (uVar1 != 0x4c) {
          if (uVar1 == 0x6a) {
LAB_20154db4:
            uVar1 = 0x80;
            goto LAB_20154d6a;
          }
          if ((uVar1 != 0x74) && (uVar1 != 0x7a)) goto LAB_20154d80;
        }
        uVar1 = 0;
LAB_20154d6a:
        uVar4 = uVar4 | uVar1;
        uVar1 = (*(code *)param_1[3])(param_1);
      }
LAB_20154d80:
      if (uVar1 == 0) break;
      if (uVar1 - 0x41 < 0x1a) {
        uVar1 = uVar1 + 0x20;
        uVar4 = uVar4 | 0x800;
      }
      *param_1 = uVar4;
      iVar5 = FUN_20100c7c(param_1,uVar1,param_2);
      if (iVar5 == 0) goto LAB_20154c6c;
      if (iVar5 == 1) {
        param_2 = param_2 + 1;
      }
      else {
        param_2 = (uint *)(((int)param_2 + 7U & 0xfffffff8) + 8);
      }
    }
    else {
LAB_20154c6c:
      (*(code *)param_1[1])(uVar1,param_1[2]);
      param_1[8] = param_1[8] + 1;
    }
  }
  return param_1[8];
}


// ===== FUN_20154dd0 @ 20154dd0 (26 bytes)

void FUN_20154dd0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_201556d8();
  uVar2 = *puVar1;
  FUN_2014e3c4(param_1,0,10);
  *puVar1 = uVar2;
  return;
}


// ===== FUN_20154dea @ 20154dea (480 bytes)

void FUN_20154dea(undefined4 param_1,uint param_2,uint param_3,code *param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 local_128 [32];
  uint local_a8 [33];
  
  iVar12 = 1;
  local_a8[0] = param_2;
  local_128[0] = param_1;
  do {
    iVar12 = iVar12 + -1;
    puVar8 = (undefined4 *)local_128[iVar12];
    uVar5 = local_a8[iVar12];
    do {
      while( true ) {
        while( true ) {
          iVar2 = param_3 * ((int)uVar5 >> 1);
          puVar6 = (undefined4 *)((int)puVar8 + iVar2);
          if ((uVar5 & 1) == 0) {
            iVar2 = iVar2 - param_3;
          }
          puVar10 = (undefined4 *)((int)puVar6 + iVar2);
          iVar2 = (*param_4)(puVar8,puVar6);
          puVar9 = puVar8;
          if (0 < iVar2) {
            uVar3 = param_3;
            puVar9 = puVar6;
            puVar7 = puVar8;
            if (((param_3 | (uint)puVar8) & 3) == 0) {
              do {
                uVar4 = *puVar8;
                uVar3 = uVar3 - 4;
                *puVar8 = *puVar6;
                puVar8 = puVar8 + 1;
                *puVar6 = uVar4;
                puVar6 = puVar6 + 1;
              } while (uVar3 != 0);
            }
            else {
              do {
                uVar1 = *(undefined1 *)puVar7;
                uVar3 = uVar3 - 1;
                puVar8 = (undefined4 *)((int)puVar7 + 1);
                *(undefined1 *)puVar7 = *(undefined1 *)puVar9;
                puVar6 = (undefined4 *)((int)puVar9 + 1);
                *(undefined1 *)puVar9 = uVar1;
                puVar9 = puVar6;
                puVar7 = puVar8;
              } while (uVar3 != 0);
            }
            puVar9 = (undefined4 *)((int)puVar8 - param_3);
            puVar6 = (undefined4 *)((int)puVar6 - param_3);
          }
          iVar2 = (*param_4)(puVar6,puVar10);
          if (0 < iVar2) {
            iVar2 = (*param_4)(puVar9,puVar10);
            if (0 < iVar2) {
              uVar3 = param_3;
              puVar8 = puVar9;
              puVar7 = puVar10;
              if (((param_3 | (uint)puVar9) & 3) == 0) {
                do {
                  uVar4 = *puVar9;
                  uVar3 = uVar3 - 4;
                  *puVar9 = *puVar10;
                  puVar9 = puVar9 + 1;
                  *puVar10 = uVar4;
                  puVar10 = puVar10 + 1;
                } while (uVar3 != 0);
              }
              else {
                do {
                  uVar1 = *(undefined1 *)puVar8;
                  uVar3 = uVar3 - 1;
                  puVar9 = (undefined4 *)((int)puVar8 + 1);
                  *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
                  puVar10 = (undefined4 *)((int)puVar7 + 1);
                  *(undefined1 *)puVar7 = uVar1;
                  puVar8 = puVar9;
                  puVar7 = puVar10;
                } while (uVar3 != 0);
              }
              puVar9 = (undefined4 *)((int)puVar9 - param_3);
              puVar10 = (undefined4 *)((int)puVar10 - param_3);
            }
            uVar3 = param_3;
            puVar8 = puVar6;
            puVar7 = puVar10;
            if (((param_3 | (uint)puVar6) & 3) == 0) {
              do {
                uVar4 = *puVar6;
                uVar3 = uVar3 - 4;
                *puVar6 = *puVar10;
                puVar6 = puVar6 + 1;
                *puVar10 = uVar4;
                puVar10 = puVar10 + 1;
              } while (uVar3 != 0);
            }
            else {
              do {
                uVar1 = *(undefined1 *)puVar8;
                uVar3 = uVar3 - 1;
                puVar6 = (undefined4 *)((int)puVar8 + 1);
                *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
                puVar10 = (undefined4 *)((int)puVar7 + 1);
                *(undefined1 *)puVar7 = uVar1;
                puVar8 = puVar6;
                puVar7 = puVar10;
              } while (uVar3 != 0);
            }
            puVar6 = (undefined4 *)((int)puVar6 - param_3);
            puVar10 = (undefined4 *)((int)puVar10 - param_3);
          }
          puVar10 = (undefined4 *)((int)puVar10 - param_3);
          puVar8 = puVar10;
          uVar3 = param_3;
          if (((param_3 | (uint)puVar6) & 3) == 0) {
            do {
              uVar4 = *puVar6;
              uVar3 = uVar3 - 4;
              *puVar6 = *puVar10;
              puVar6 = puVar6 + 1;
              *puVar10 = uVar4;
              puVar10 = puVar10 + 1;
            } while (uVar3 != 0);
          }
          else {
            do {
              uVar1 = *(undefined1 *)puVar6;
              uVar3 = uVar3 - 1;
              *(undefined1 *)puVar6 = *(undefined1 *)puVar8;
              puVar10 = (undefined4 *)((int)puVar8 + 1);
              *(undefined1 *)puVar8 = uVar1;
              puVar8 = puVar10;
              puVar6 = (undefined4 *)((int)puVar6 + 1);
            } while (uVar3 != 0);
          }
          puVar10 = (undefined4 *)((int)puVar10 - param_3);
          puVar8 = puVar9;
          puVar6 = puVar10;
          while( true ) {
            do {
              puVar8 = (undefined4 *)((int)puVar8 + param_3);
              iVar2 = (*param_4)(puVar8,puVar10);
            } while (iVar2 < 0);
            do {
              puVar6 = (undefined4 *)((int)puVar6 - param_3);
              iVar2 = (*param_4)(puVar6,puVar10);
            } while (0 < iVar2);
            iVar2 = (param_3 | (uint)puVar8) << 0x1e;
            if (puVar6 <= puVar8) break;
            uVar3 = param_3;
            puVar7 = puVar8;
            puVar11 = puVar6;
            if (iVar2 == 0) {
              do {
                uVar4 = *puVar8;
                uVar3 = uVar3 - 4;
                *puVar8 = *puVar6;
                puVar8 = puVar8 + 1;
                *puVar6 = uVar4;
                puVar6 = puVar6 + 1;
              } while (uVar3 != 0);
            }
            else {
              do {
                uVar1 = *(undefined1 *)puVar7;
                uVar3 = uVar3 - 1;
                puVar8 = (undefined4 *)((int)puVar7 + 1);
                *(undefined1 *)puVar7 = *(undefined1 *)puVar11;
                puVar6 = (undefined4 *)((int)puVar11 + 1);
                *(undefined1 *)puVar11 = uVar1;
                puVar7 = puVar8;
                puVar11 = puVar6;
              } while (uVar3 != 0);
            }
            puVar8 = (undefined4 *)((int)puVar8 - param_3);
            puVar6 = (undefined4 *)((int)puVar6 - param_3);
          }
          uVar3 = param_3;
          puVar6 = puVar8;
          if (iVar2 == 0) {
            do {
              uVar4 = *puVar8;
              uVar3 = uVar3 - 4;
              *puVar8 = *puVar10;
              puVar8 = puVar8 + 1;
              *puVar10 = uVar4;
              puVar10 = puVar10 + 1;
            } while (uVar3 != 0);
          }
          else {
            do {
              uVar1 = *(undefined1 *)puVar6;
              uVar3 = uVar3 - 1;
              puVar8 = (undefined4 *)((int)puVar6 + 1);
              *(undefined1 *)puVar6 = *(undefined1 *)puVar10;
              *(undefined1 *)puVar10 = uVar1;
              puVar6 = puVar8;
              puVar10 = (undefined4 *)((int)puVar10 + 1);
            } while (uVar3 != 0);
          }
          puVar8 = (undefined4 *)((int)puVar8 - param_3);
          iVar2 = __aeabi_uidivmod((int)puVar8 - (int)puVar9,param_3);
          uVar3 = iVar2 - 1;
          uVar5 = (uVar5 - uVar3) - 1;
          if ((int)uVar3 <= (int)uVar5) break;
          if ((int)uVar5 < 0xb) {
            puVar8 = puVar9;
            uVar5 = uVar3;
            if ((int)uVar3 < 0xb) goto LAB_20154fbc;
          }
          else {
            local_128[iVar12] = puVar9;
            local_a8[iVar12] = uVar3;
            iVar12 = iVar12 + 1;
          }
        }
        if ((int)uVar3 < 0xb) break;
        local_128[iVar12] = puVar8;
        local_a8[iVar12] = uVar5;
        iVar12 = iVar12 + 1;
        puVar8 = puVar9;
        uVar5 = uVar3;
      }
    } while (10 < (int)uVar5);
LAB_20154fbc:
    if (iVar12 == 0) {
      return;
    }
  } while( true );
}


// ===== FUN_20154fca @ 20154fca (134 bytes)

void FUN_20154fca(uint param_1,uint param_2,uint param_3,code *param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  if ((param_3 != 0) && (param_2 != 0)) {
    if (10 < param_2) {
      FUN_20154dea();
    }
    uVar7 = param_1;
    while (uVar7 < (param_2 - 1) * param_3 + param_1) {
      uVar6 = uVar7 + param_3;
      while ((param_1 <= uVar7 && (iVar2 = (*param_4)(uVar7,uVar6), 0 < iVar2))) {
        uVar7 = uVar7 - param_3;
      }
      puVar5 = (undefined4 *)(uVar7 + param_3);
      uVar4 = 0;
      uVar7 = uVar6;
      if (((param_3 | uVar6) & 3) == 0) {
        for (; uVar4 < param_3; uVar4 = uVar4 + 4) {
          uVar8 = *(undefined4 *)(uVar6 + uVar4);
          for (puVar3 = (undefined4 *)((int)(uVar6 + uVar4) - param_3); puVar5 <= puVar3;
              puVar3 = (undefined4 *)((int)puVar3 - param_3)) {
            *(undefined4 *)((int)puVar3 + param_3) = *puVar3;
          }
          *(undefined4 *)((int)puVar3 + param_3) = uVar8;
        }
      }
      else {
        for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1) {
          puVar3 = (undefined4 *)(uVar6 + uVar4);
          uVar1 = *(undefined1 *)puVar3;
          while (puVar3 = (undefined4 *)((int)puVar3 - param_3), puVar5 <= puVar3) {
            *(undefined1 *)((int)puVar3 + param_3) = *(undefined1 *)puVar3;
          }
          *(undefined1 *)((int)puVar3 + param_3) = uVar1;
        }
      }
    }
  }
  return;
}


// ===== strstr @ 20155058 (36 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.850): restarting byte compare of needle against
   haystack, returns start or 0 [inference] */

char * strstr(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = param_2;
  pcVar4 = param_1;
LAB_20155060:
  cVar1 = *pcVar3;
  cVar2 = *param_1;
  if (cVar2 != '\0') goto code_r0x2015506a;
  goto LAB_2015506e;
code_r0x2015506a:
  param_1 = param_1 + 1;
  pcVar3 = pcVar3 + 1;
  if (cVar2 != cVar1) {
LAB_2015506e:
    pcVar3 = pcVar4;
    if ((cVar1 == '\0') || (pcVar3 = (char *)0x0, cVar2 == '\0')) {
      return pcVar3;
    }
    param_1 = pcVar4 + 1;
    pcVar3 = param_2;
    pcVar4 = param_1;
  }
  goto LAB_20155060;
}

