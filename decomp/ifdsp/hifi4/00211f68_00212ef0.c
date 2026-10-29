// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00211f68 @ 00211f68 (135 bytes)

int FUN_00211f68(int param_1,byte *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  param_3 = param_3 + -1;
  if (param_3 == -1) {
    return 0;
  }
  do {
    memw();
    uVar4 = *(uint *)(param_1 + 0x60);
    do {
      memw();
      uVar3 = *(uint *)(param_1 + 0x2c);
      uVar1 = FUN_0021055c(param_1);
      iVar2 = FUN_002106ec(param_1,uVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
    } while (2 << 0x20 - (0x20 - ((uVar4 & 0xc000000) >> 0x1a)) ==
             (uVar3 & (uint)&DAT_001f0000) >> 0x10);
    if (param_3 == 0) {
      memw();
      *(uint *)(param_1 + 0x34) = (uint)*param_2;
    }
    else {
      memw();
      *(uint *)(param_1 + 0x30) = (uint)*param_2;
    }
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  } while (param_3 != -1);
  return 0;
}


// ===== FUN_00211ff0 @ 00211ff0 (59 bytes)

int FUN_00211ff0(int param_1,undefined1 *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    return 0;
  }
  do {
    uVar1 = FUN_0021055c(param_1);
    iVar2 = FUN_002106ec(param_1,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    memw();
    if ((*(uint *)(param_1 + 0x2c) & 0x1f000000) != 0) {
      memw();
      param_3 = param_3 + -1;
      *param_2 = (char)*(undefined4 *)(param_1 + 0x40);
      param_2 = param_2 + 1;
    }
  } while (param_3 != 0);
  return 0;
}


// ===== FUN_0021202c @ 0021202c (52 bytes)

void FUN_0021202c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  memset(param_2,0,0x38);
  iVar1 = FUN_002105ac(param_1);
  *(undefined4 *)(param_2 + 0x2c) = param_4;
  *(undefined4 *)(param_2 + 0x28) = param_3;
  DAT_00238e34 = FUN_002120f4;
  (&DAT_00238f10)[iVar1] = param_2;
  FUN_00210588(param_1,&DAT_0007ef00);
  return;
}


// ===== FUN_00212060 @ 00212060 (69 bytes)

undefined * FUN_00212060(int param_1,undefined4 *param_2,uint param_3)

{
  if (*(char *)(param_2 + 7) != '\0') {
    return &DAT_00001edc;
  }
  FUN_00210588(param_1,&DAT_0007ef00);
  param_2[6] = 0;
  param_2[5] = 0;
  param_2[4] = 0;
  param_2[3] = 0;
  param_2[2] = 0;
  param_2[1] = 0;
  *param_2 = 0;
  param_2[8] = param_3 | 6;
  memw();
  *(undefined4 *)(param_1 + 8) = 0x700;
  FUN_00210574(param_1,&DAT_0007ef00);
  return (undefined *)0x0;
}


// ===== FUN_002120a8 @ 002120a8 (34 bytes)

undefined4 FUN_002120a8(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    return 4;
  }
  if (*(char *)(param_2 + 0x1c) != '\0') {
    *param_3 = *(undefined4 *)(param_2 + 0x24);
    return 0;
  }
  *param_3 = 0;
  return 6;
}


// ===== FUN_002120cc @ 002120cc (40 bytes)

void FUN_002120cc(undefined4 param_1,undefined4 *param_2)

{
  if (*(char *)(param_2 + 7) != '\0') {
    FUN_00210588(param_1,&DAT_0007ef00);
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    *(undefined1 *)(param_2 + 7) = 0;
    return;
  }
  return;
}


// ===== FUN_002120f4 @ 002120f4 (745 bytes)

void FUN_002120f4(int param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  uint uStack_24;
  
  memw();
  uVar5 = *(uint *)(param_1 + 0x60);
  if (param_2 == (undefined4 *)0x0) {
    return;
  }
  memw();
  uVar8 = *(uint *)(param_1 + 8) & 0xfcfffff;
  uVar2 = FUN_0021055c(param_1);
  uStack_24 = FUN_002105a0(param_1);
  uVar3 = FUN_00210594(param_1);
  if ((uVar2 & (uint)&DAT_00030f1f) != 0) {
    *param_2 = 0x40;
    uVar4 = FUN_002106ec(param_1,uVar2);
    param_2[5] = uVar4;
    if ((param_2[8] & 0x40) == 0) {
      return;
    }
    if ((code *)param_2[10] == (code *)0x0) {
      return;
    }
    (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    return;
  }
  memw();
  *(uint *)(param_1 + 8) = uVar8;
  if ((uVar8 >> 8 & 1) != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 3;
    param_2[2] = 0;
    FUN_00210574(param_1,&DAT_00001000);
    uStack_24 = uStack_24 | (uint)&DAT_00001000;
    memw();
    uVar8 = *(uint *)(param_1 + 8) & 0xfcfffff;
  }
  if ((uVar8 >> 0x12 & 1) != 0) {
    *param_2 = 0x80;
    iVar9 = param_2[0xd];
    if ((((byte *)param_2[0xc] != (byte *)0x0) && (iVar9 != 0)) && ((iVar9 == 1 || (iVar9 != 0)))) {
      memw();
      memw();
      *(uint *)(param_1 + 0xc) =
           *(uint *)(param_1 + 0xc) & 0xffff00ff | (uint)*(byte *)param_2[0xc] << 8 | 1;
    }
    param_2[0xc] = 0;
    if (((param_2[8] & 0x80) != 0) && ((code *)param_2[10] != (code *)0x0)) {
      (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    }
  }
  if ((uVar8 >> 0xe & 1) != 0) {
    *param_2 = 0x100;
    *(undefined1 *)(param_2 + 7) = 1;
    if (((param_2[8] & 0x100) != 0) && ((code *)param_2[10] != (code *)0x0)) {
      (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    }
  }
  if ((uVar8 >> 10 & 1) != 0) {
    FUN_00210588(param_1,&DAT_00001000);
    memw();
    memw();
    cVar1 = *(char *)(param_2 + 7);
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 3;
    if (cVar1 == '\0') {
      return;
    }
    param_2[5] = 0;
    *param_2 = 0x40;
    *(undefined1 *)(param_2 + 7) = 0;
    param_2[6] = param_2[9];
    if (*(char *)((int)param_2 + 0x1d) != '\0') {
      *(undefined1 *)((int)param_2 + 0x1d) = 0;
      param_2[6] = param_2[9] + -1;
    }
    if (((param_2[8] & 0x40) != 0) && ((code *)param_2[10] != (code *)0x0)) {
      (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    }
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
  }
  if ((uVar8 >> 9 & 1) != 0) {
    *param_2 = 1;
    *(undefined1 *)(param_2 + 7) = 1;
    if (((param_2[8] & 1) != 0) && ((code *)param_2[10] != (code *)0x0)) {
      (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
    }
  }
  memw();
  memw();
  iVar9 = (2 << 0x20 - (0x20 - ((uVar5 & 0xc000000) >> 0x1a))) -
          ((*(uint *)(param_1 + 0x2c) & (uint)&DAT_001f0000) >> 0x10);
  uVar5 = (*(uint *)(param_1 + 0x2c) & 0x1f000000) >> 0x18;
  if (((uVar8 >> 0xc & 1) != 0) && ((uStack_24 & 0x1000) != 0)) {
    *(undefined1 *)((int)param_2 + 0x1d) = 1;
    if ((param_2[1] == 0) || (uVar2 = param_2[2], uVar2 == 0)) {
      *param_2 = 2;
      if ((uVar8 & 0x40) != 0) {
        *param_2 = 0x22;
      }
      if ((code *)param_2[10] != (code *)0x0) {
        (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
      }
      uVar2 = param_2[2];
      param_2[9] = 0;
      if (uVar2 == 0) goto LAB_00212243;
    }
    do {
      if (iVar9 == 0) break;
      uVar7 = (uint)*(byte *)param_2[1];
      pbVar10 = (byte *)param_2[1] + 1;
      if (uVar2 < 2) {
        param_2[1] = pbVar10;
        memw();
        *(uint *)(param_1 + 0x34) = uVar7;
        FUN_00210588(param_1,&DAT_00001000);
        uVar2 = param_2[2];
      }
      else {
        param_2[1] = pbVar10;
        memw();
        *(uint *)(param_1 + 0x30) = uVar7;
      }
      uVar2 = uVar2 - 1;
      param_2[2] = uVar2;
      iVar9 = iVar9 + -1;
      param_2[9] = param_2[9] + 1;
    } while (uVar2 != 0);
  }
LAB_00212243:
  if (((uVar8 & 0x800) != 0) && ((uVar3 & 0x800) != 0)) {
    if ((param_2[3] == 0) || (param_2[4] == 0)) {
      *param_2 = 4;
      if ((uVar8 & 0x40) != 0) {
        *param_2 = 0x24;
      }
      if ((code *)param_2[10] != (code *)0x0) {
        (*(code *)param_2[10])(param_1,param_2,param_2[0xb]);
      }
      param_2[9] = 0;
    }
    uVar2 = FUN_00210594(param_1);
    if ((((uVar2 & 0x800) != 0) && (uVar5 != 0)) &&
       (puVar6 = (undefined1 *)param_2[3], puVar6 != (undefined1 *)0x0)) {
      iVar9 = param_2[4];
      while (iVar9 != 0) {
        memw();
        *puVar6 = (char)*(undefined4 *)(param_1 + 0x40);
        param_2[9] = param_2[9] + 1;
        puVar6 = (undefined1 *)(param_2[3] + 1);
        param_2[3] = puVar6;
        iVar9 = param_2[4] + -1;
        param_2[4] = iVar9;
        uVar5 = uVar5 - 1;
        if (uVar5 == 0) {
          return;
        }
        if (puVar6 == (undefined1 *)0x0) {
          return;
        }
      }
    }
  }
  return;
}


// ===== FUN_002123e0 @ 002123e0 (67 bytes)

void FUN_002123e0(void)

{
  uint uVar1;
  
  memw();
  uVar1 = I3C_MCONFIG;
  if (((uVar1 & 3) == 1) && (DAT_00238e30 != (code *)0x0)) {
    (*DAT_00238e30)(&I3C_MCONFIG,DAT_00238e38);
  }
  memw();
  uVar1 = I3C_SCONFIG;
  if (((uVar1 & 1) != 0) && (DAT_00238e34 != (code *)0x0)) {
    (*DAT_00238e34)(&I3C_MCONFIG,DAT_00238f10);
  }
  return;
}


// ===== FUN_00212430 @ 00212430 (16 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212430(undefined4 param_1)

{
  (*_DAT_1303f000)(param_1);
  return;
}


// ===== FUN_00212440 @ 00212440 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212440(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 4))(param_1,param_2);
  return uVar1;
}


// ===== FUN_00212458 @ 00212458 (30 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212458(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 8))(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ===== FUN_00212478 @ 00212478 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212478(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0xc))(param_1,param_2);
  return uVar1;
}


// ===== FUN_00212490 @ 00212490 (30 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212490(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x10))(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ===== FUN_002124b0 @ 002124b0 (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_002124b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x14))(param_1,param_2,param_3);
  return uVar1;
}


// ===== FUN_002124cc @ 002124cc (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_002124cc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x18))(param_1,param_2,param_3);
  return uVar1;
}


// ===== FUN_002124e8 @ 002124e8 (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_002124e8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x1c))(param_1,param_2,param_3);
  return uVar1;
}


// ===== FUN_00212504 @ 00212504 (34 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00212504(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x20))(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}


// ===== FUN_00212528 @ 00212528 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212528(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x24))(param_1,param_2);
  return uVar1;
}


// ===== FUN_00212540 @ 00212540 (30 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212540(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x28))(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ===== FUN_00212560 @ 00212560 (20 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212560(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x2c))(param_1);
  return uVar1;
}


// ===== FUN_00212574 @ 00212574 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212574(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(_DAT_1303f01c + 0x30))(param_1,param_2,param_3);
  return;
}


// ===== FUN_0021258c @ 0021258c (46 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0021258c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(_DAT_1303f01c + 0x1c))(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = (**(code **)(_DAT_1303f01c + 4))(param_1,param_2);
  return iVar1;
}


// ===== FUN_002125bc @ 002125bc (20 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_002125bc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)*_DAT_1303f020)(param_1);
  return uVar1;
}


// ===== FUN_002125d0 @ 002125d0 (18 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_002125d0(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 4))();
  return uVar1;
}


// ===== FUN_002125e4 @ 002125e4 (24 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_002125e4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 8))(param_1,param_2);
  return uVar1;
}


// ===== FUN_002125fc @ 002125fc (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_002125fc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 0xc))(param_1,param_2,param_3);
  return uVar1;
}


// ===== FUN_00212618 @ 00212618 (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212618(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 0x10))(param_1,param_2,param_3);
  return uVar1;
}


// ===== FUN_00212634 @ 00212634 (18 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212634(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 0x14))();
  return uVar1;
}


// ===== FUN_00212648 @ 00212648 (26 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212648(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 0x18))(param_1,param_2,param_3);
  return uVar1;
}


// ===== FUN_00212670 @ 00212670 (17 bytes)

void FUN_00212670(void)

{
  memw();
  CLKCTL1_PSCCTL2_SET = 0x80000000;
  return;
}


// ===== INPUTMUX_AttachSignal @ 00212684 (25 bytes)

void INPUTMUX_AttachSignal(int param_1,int param_2,uint param_3)

{
  memw();
  *(uint *)(param_2 * 4 + param_1 + (param_3 >> 0x14)) = param_3 & (uint)&DAT_000fffff;
  return;
}


// ===== FUN_002126a0 @ 002126a0 (63 bytes)

void FUN_002126a0(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)(param_1 + (param_2 >> 8));
  uVar2 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  if (param_3 != 0) {
    memw();
    memw();
    *puVar1 = *puVar1 | uVar2;
    return;
  }
  memw();
  memw();
  *puVar1 = *puVar1 & (uVar2 ^ 0xffffffff);
  return;
}


// ===== FUN_002126e0 @ 002126e0 (17 bytes)

void FUN_002126e0(void)

{
  memw();
  CLKCTL1_PSCCTL2_CLR = 0x80000000;
  return;
}


// ===== FUN_00212700 @ 00212700 (437 bytes)

/* WARNING: Removing unreachable block (ram,0x002128a4) */
/* WARNING: Removing unreachable block (ram,0x00212880) */
/* WARNING: Removing unreachable block (ram,0x00212868) */
/* WARNING: Removing unreachable block (ram,0x00212892) */
/* WARNING: Removing unreachable block (ram,0x0021273b) */
/* WARNING: Removing unreachable block (ram,0x0021286d) */

void FUN_00212700(dword *param_1,char *param_2)

{
  char cVar1;
  dword dVar2;
  uint uVar3;
  
  if (param_1 == &ADC0_VERID) {
    memw();
    CLKCTL0_PSCCTL1_SET = 0x10000;
  }
  memw();
  memw();
  param_1[4] = param_1[4] | 2;
  memw();
  memw();
  param_1[4] = param_1[4] & 0xfffffffd;
  memw();
  memw();
  param_1[4] = param_1[4] | 0x100;
  memw();
  memw();
  cVar1 = *param_2;
  param_1[4] = param_1[4] & 0xfffffffe;
  if (cVar1 == '\0') {
    memw();
    dVar2 = param_1[4] | 4;
  }
  else {
    memw();
    dVar2 = param_1[4] & 0xfffffffb;
  }
  memw();
  param_1[4] = dVar2;
  memw();
  uVar3 = *(uint *)(param_2 + 0x18);
  cVar1 = param_2[0x14];
  param_1[8] = *(uint *)(param_2 + 0x10) & 1 | (uint)(byte)param_2[1] << 0x1c |
               (*(uint *)(param_2 + 0xc) & 3) << 4 |
               (*(uint *)(param_2 + 4) & 0xff) << 0x10 | (*(uint *)(param_2 + 8) & 3) << 6;
  if (cVar1 != '\0') {
    memw();
    param_1[9] = uVar3 & 0x1ff | 0x80000000;
    memw();
    param_1[0xc] = (*(uint *)(param_2 + 0x1c) & 0xf) << 0x10;
    memw();
    memw();
    param_1[4] = param_1[4] | 1;
    return;
  }
  memw();
  param_1[9] = 0;
  memw();
  param_1[0xc] = (*(uint *)(param_2 + 0x1c) & 0xf) << 0x10;
  memw();
  memw();
  param_1[4] = param_1[4] | 1;
  return;
}


// ===== FUN_002128b8 @ 002128b8 (48 bytes)

void FUN_002128b8(undefined1 *param_1)

{
  memset(param_1,0,0x20);
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  param_1[0x14] = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *param_1 = 1;
  *(undefined4 *)(param_1 + 4) = 0x80;
  return;
}


// ===== FUN_002128e8 @ 002128e8 (188 bytes)

/* WARNING: Removing unreachable block (ram,0x00212995) */
/* WARNING: Removing unreachable block (ram,0x00212973) */
/* WARNING: Removing unreachable block (ram,0x00212951) */
/* WARNING: Removing unreachable block (ram,0x00212984) */
/* WARNING: Removing unreachable block (ram,0x00212940) */
/* WARNING: Removing unreachable block (ram,0x00212962) */

void FUN_002128e8(dword *param_1)

{
  memw();
  memw();
  param_1[4] = param_1[4] & 0xfffffffe;
  if (param_1 != &ADC0_VERID) {
    return;
  }
  memw();
  CLKCTL0_PSCCTL1_CLR = 0x10000;
  return;
}


// ===== FUN_002129a8 @ 002129a8 (42 bytes)

undefined4 FUN_002129a8(int param_1,uint *param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x300);
  if (-1 < (int)uVar1) {
    return 0;
  }
  *(short *)(param_2 + 3) = (short)uVar1;
  *param_2 = uVar1 >> 0x18 & 0xf;
  param_2[1] = uVar1 >> 0x14 & 0xf;
  param_2[2] = uVar1 >> 0x10 & 0xf;
  return 1;
}


// ===== FUN_002129d4 @ 002129d4 (67 bytes)

void FUN_002129d4(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = 1;
  if ((char)param_3[3] != '\0') {
    uVar1 = (param_3[2] & 0xf) << 8 | (*param_3 & 0xf) << 0x18 | (param_3[1] & 0xf) << 0x10 | 1;
  }
  memw();
  *(uint *)(param_2 * 4 + param_1 + 0xc0) = uVar1;
  return;
}


// ===== FUN_00212a18 @ 00212a18 (18 bytes)

void FUN_00212a18(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  return;
}


// ===== FUN_00212a2c @ 00212a2c (200 bytes)

void FUN_00212a2c(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_3[1];
  iVar2 = param_2 * 8 + param_1;
  uVar3 = param_3[2] & 0x1f | (*param_3 & 1) << 0xd;
  if (uVar1 == 1) {
    uVar3 = uVar3 | 0x20;
  }
  else if (uVar1 == 2) {
    uVar3 = uVar3 | 0x40;
  }
  else if (uVar1 == 3) {
    uVar3 = uVar3 | 0x60;
  }
  memw();
  *(uint *)(iVar2 + 0xf8) = uVar3;
  uVar1 = param_3[8];
  uVar3 = uVar1 & 3 | (param_3[7] & 7) << 8 |
          (param_3[6] & 7) << 0xc | (param_3[3] & 0xf) << 0x18 | (param_3[5] & 0xf) << 0x10;
  if ((char)param_3[4] != '\0') {
    uVar3 = uVar3 | 0x80;
  }
  memw();
  *(uint *)(iVar2 + 0xfc) = uVar3;
  if (uVar1 != 0) {
    memw();
    *(uint *)(param_2 * 4 + param_1 + 0x1fc) = (uint)(ushort)param_3[10] | param_3[9] << 0x10;
    return;
  }
  return;
}


// ===== FUN_00212af4 @ 00212af4 (45 bytes)

void FUN_00212af4(undefined4 *param_1)

{
  memset(param_1,0,0x2c);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *param_1 = 1;
  return;
}


// ===== FUN_00212b30 @ 00212b30 (209 bytes)

/* WARNING: Removing unreachable block (ram,0x00212bf2) */
/* WARNING: Removing unreachable block (ram,0x00212bcc) */
/* WARNING: Removing unreachable block (ram,0x00212bba) */
/* WARNING: Removing unreachable block (ram,0x00212be0) */
/* WARNING: Removing unreachable block (ram,0x00212ba8) */

void FUN_00212b30(dword *param_1,byte *param_2)

{
  memw();
  CLKCTL1_PSCCTL2_SET =
       1 << 0x20 - (0x20 - ((byte)(&DAT_0020046c)[(uint)(param_1 != &MRT0_CHANNEL0_INTVAL) * 4] &
                           0x1f));
  FUN_00213910(*(undefined4 *)(&DAT_00200470 + (uint)(param_1 != &MRT0_CHANNEL0_INTVAL) * 4));
  memw();
  param_1[0x3c] = (uint)*param_2 << 0x1f;
  return;
}


// ===== FUN_00212c04 @ 00212c04 (196 bytes)

/* WARNING: Removing unreachable block (ram,0x00212cb7) */
/* WARNING: Removing unreachable block (ram,0x00212c95) */
/* WARNING: Removing unreachable block (ram,0x00212c84) */
/* WARNING: Removing unreachable block (ram,0x00212ca6) */
/* WARNING: Removing unreachable block (ram,0x00212c49) */
/* WARNING: Removing unreachable block (ram,0x00212c73) */

void FUN_00212c04(dword *param_1)

{
  memw();
  *param_1 = 0x80000000;
  memw();
  param_1[4] = 0x80000000;
  memw();
  param_1[8] = 0x80000000;
  memw();
  param_1[0xc] = 0x80000000;
  if (param_1 != &MRT0_CHANNEL0_INTVAL) {
    memw();
    CLKCTL1_PSCCTL2_CLR = 0x100;
    return;
  }
  memw();
  CLKCTL1_PSCCTL2_CLR = 0x100;
  return;
}


// ===== FUN_00212cc8 @ 00212cc8 (50 bytes)

void FUN_00212cc8(int param_1,int param_2,uint param_3,int param_4)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + param_2 * 0x10);
  memw();
  if (((puVar1[2] & 6) != 2) && (param_4 == 0)) {
    memw();
    *puVar1 = param_3;
    return;
  }
  memw();
  *puVar1 = param_3 | 0x80000000;
  return;
}


// ===== MU_Init @ 00212d00 (172 bytes)

/* WARNING: Removing unreachable block (ram,0x00212d9b) */
/* WARNING: Removing unreachable block (ram,0x00212d46) */
/* WARNING: Removing unreachable block (ram,0x00212d1c) */
/* WARNING: Removing unreachable block (ram,0x00212d1f) */
/* WARNING: Removing unreachable block (ram,0x00212d22) */
/* WARNING: Removing unreachable block (ram,0x00212d25) */
/* WARNING: Removing unreachable block (ram,0x00212d28) */
/* WARNING: Removing unreachable block (ram,0x00212d2b) */
/* WARNING: Removing unreachable block (ram,0x00212d68) */
/* WARNING: Removing unreachable block (ram,0x00212d8a) */
/* WARNING: Removing unreachable block (ram,0x00212d79) */
/* clock enable for MU (base 0x40111000 MU-B passed by Thread_Ipc) */

void MU_Init(dword *param_1)

{
  if (param_1 != &MUB_VER) {
    memw();
    CLKCTL0_PSCCTL0_SET = 1;
    return;
  }
  memw();
  CLKCTL1_PSCCTL1_SET = 0x10000000;
  return;
}


// ===== FUN_00212dac @ 00212dac (172 bytes)

/* WARNING: Removing unreachable block (ram,0x00212e47) */
/* WARNING: Removing unreachable block (ram,0x00212df2) */
/* WARNING: Removing unreachable block (ram,0x00212dc8) */
/* WARNING: Removing unreachable block (ram,0x00212dcb) */
/* WARNING: Removing unreachable block (ram,0x00212dce) */
/* WARNING: Removing unreachable block (ram,0x00212dd1) */
/* WARNING: Removing unreachable block (ram,0x00212dd4) */
/* WARNING: Removing unreachable block (ram,0x00212dd7) */
/* WARNING: Removing unreachable block (ram,0x00212e14) */
/* WARNING: Removing unreachable block (ram,0x00212e36) */
/* WARNING: Removing unreachable block (ram,0x00212e25) */

void FUN_00212dac(dword *param_1)

{
  if (param_1 != &MUB_VER) {
    memw();
    CLKCTL0_PSCCTL0_CLR = 1;
    return;
  }
  memw();
  CLKCTL1_PSCCTL1_CLR = 0x10000000;
  return;
}


// ===== MU_SendMsg @ 00212e58 (46 bytes)

/* wait SR TEn, TR[reg] (+0x20) */

void MU_SendMsg(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x60);
  while ((uVar1 & 0x800000U >> (param_2 & 0x1f)) == 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x60);
  }
  memw();
  *(undefined4 *)(param_2 * 4 + param_1 + 0x20) = param_3;
  return;
}


// ===== MU_ReceiveMsg @ 00212e88 (47 bytes)

/* wait SR RFn, RR[reg] (+0x40) */

undefined4 MU_ReceiveMsg(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x60);
  while ((uVar1 & 0x8000000U >> (param_2 & 0x1f)) == 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x60);
  }
  memw();
  return *(undefined4 *)(param_2 * 4 + param_1 + 0x40);
}


// ===== MU_SetFlags @ 00212eb8 (55 bytes)

/* wait SR FUP (bit 8) clear, CR Fn = flags */

void MU_SetFlags(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x60);
  while ((uVar1 & 0x100) != 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x60);
  }
  memw();
  memw();
  *(uint *)(param_1 + 100) = param_2 & 7 | *(uint *)(param_1 + 100) & 0xfff0fff8;
  return;
}


// ===== FUN_00212ef0 @ 00212ef0 (36 bytes)

undefined4 FUN_00212ef0(int param_1,uint param_2)

{
  memw();
  if ((param_2 & *(uint *)(param_1 + 100)) != 0) {
    return 1;
  }
  memw();
  *(uint *)(param_1 + 100) = param_2 | *(uint *)(param_1 + 100) & 0xfff0ffff;
  return 0;
}

