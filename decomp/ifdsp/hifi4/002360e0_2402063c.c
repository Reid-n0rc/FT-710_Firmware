// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 33 functions

// ===== FUN_002360e0 @ 002360e0 (131 bytes)

int FUN_002360e0(uint *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *param_1;
  if ((uVar2 & 7) == 0) {
    iVar3 = ae_zext16(uVar2);
    iVar1 = 0;
    if (iVar3 == 0) {
      iVar1 = 0x10;
      uVar2 = uVar2 >> 0x10;
    }
    if ((uVar2 & 0xff) == 0) {
      iVar1 = iVar1 + 8;
      uVar2 = uVar2 >> 8;
    }
    if ((uVar2 & 0xf) == 0) {
      iVar1 = iVar1 + 4;
      uVar2 = uVar2 >> 4;
    }
    if ((uVar2 & 3) == 0) {
      iVar1 = iVar1 + 2;
      uVar2 = uVar2 >> 2;
    }
    if ((uVar2 & 1) == 0) {
      uVar2 = uVar2 >> 1;
      iVar1 = iVar1 + 1;
      if (uVar2 == 0) {
        return 0x20;
      }
    }
    *param_1 = uVar2;
    return iVar1;
  }
  if ((uVar2 & 1) == 0) {
    if ((uVar2 >> 1 & 1) != 0) {
      *param_1 = uVar2 >> 1;
      return 1;
    }
    *param_1 = uVar2 >> 2;
    return 2;
  }
  return 0;
}


// ===== FUN_00236170 @ 00236170 (74 bytes)

int FUN_00236170(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  iVar3 = *(int *)(param_2 + 0x10);
  iVar2 = *(int *)(param_1 + 0x10) - iVar3;
  if (iVar2 != 0) {
    return iVar2;
  }
  param_2 = iVar3 * 4 + param_2;
  puVar4 = (uint *)(iVar3 * 4 + param_1 + 0x14);
  do {
    puVar4 = puVar4 + -1;
    puVar1 = (uint *)(param_2 + 0x10);
    param_2 = param_2 + -4;
    if (*puVar4 != *puVar1) {
      if (*puVar4 < *puVar1) {
        return -1;
      }
      return 1;
    }
  } while ((uint *)(param_1 + 0x14) < puVar4);
  return 0;
}


// ===== FUN_002361d0 @ 002361d0 (157 bytes)

void FUN_002361d0(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  iVar2 = *(int *)(param_3 + 0x10) * 4;
  puVar3 = param_1 + (param_2 + -1 >> 5) + 1;
  if (iVar2 < 1) {
    if (puVar3 <= param_1) {
      return;
    }
    iVar2 = 0;
    puVar1 = param_1;
  }
  else {
    uVar4 = iVar2 + 3;
    bVar6 = (uVar4 >> 2 & 1) != 0;
    puVar1 = param_1;
    if (bVar6) {
      puVar1 = param_1 + 1;
      *param_1 = *(undefined4 *)(param_3 + 0x14);
      param_3 = param_3 + 4;
    }
    uVar5 = (uint)bVar6;
    uVar4 = (uint)((int)uVar4 >> 2) >> 1;
    if ((uVar4 != 0) && ((uVar4 == 1 || (uVar4 != 0)))) {
      uVar5 = uVar5 + 2;
      *puVar1 = *(undefined4 *)(param_3 + 0x14);
      puVar1[1] = *(undefined4 *)(param_3 + 0x18);
    }
    iVar2 = uVar5 << 2;
    puVar1 = param_1 + uVar5;
    if (puVar3 <= param_1 + uVar5) {
      return;
    }
  }
  param_1 = (undefined4 *)(iVar2 + (int)param_1);
  do {
    *param_1 = 0;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  } while (puVar1 < puVar3);
  return;
}


// ===== FUN_00236270 @ 00236270 (110 bytes)

undefined4 FUN_00236270(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar2 = (int)param_2 >> 5;
  if (iVar3 < iVar2) {
    param_1 = iVar3 * 4 + param_1;
    iVar3 = iVar3 << 2;
  }
  else if (iVar2 < iVar3) {
    param_1 = iVar2 * 4 + param_1;
    iVar3 = iVar2 << 2;
    if (((param_2 & 0x1f) != 0) &&
       (*(uint *)(param_1 + 0x14) !=
        (*(uint *)(param_1 + 0x14) >> (param_2 & 0x1f)) << 0x20 - (0x20 - (param_2 & 0x1f)))) {
      return 1;
    }
  }
  else {
    param_1 = iVar2 * 4 + param_1;
    iVar3 = iVar2 << 2;
  }
  if (0 < iVar3) {
    uVar1 = iVar3 + 3U >> 2;
    if (uVar1 == 1) {
      isync();
    }
    if ((uVar1 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
      return 1;
    }
  }
  return 0;
}


// ===== FUN_002362f0 @ 002362f0 (7 bytes)

undefined4 FUN_002362f0(void)

{
  return 0;
}


// ===== FUN_00236300 @ 00236300 (222 bytes)

undefined1  [12] FUN_00236300(byte *param_1,byte *param_2,uint param_3)

{
  int iVar1;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 auVar2 [12];
  undefined1 auVar3 [12];
  int iVar6;
  byte *pbVar7;
  
  pbVar4 = param_2;
  if ((param_2 < param_1) && (pbVar4 = param_2 + param_3, param_1 < pbVar4)) {
    pbVar5 = pbVar4 + -0x80;
    pbVar7 = param_1;
    if ((param_3 != 0) && ((param_3 == 1 || (param_3 != 0)))) {
      pbVar7 = (byte *)(uint)pbVar4[-1];
      param_1[param_3 - 1] = pbVar4[-1];
      pbVar5 = pbVar4 + -0x81;
    }
    auVar2._4_4_ = pbVar5;
    auVar2._0_4_ = param_1;
    auVar2._8_4_ = pbVar7;
    return auVar2;
  }
  pbVar7 = param_1;
  if ((0xf < param_3) && ((((uint)param_2 | (uint)param_1) & 3) == 0)) {
    iVar6 = 0;
    pbVar4 = (byte *)(param_3 >> 4);
    if ((pbVar4 != (byte *)0x0) && ((pbVar4 == (byte *)0x1 || (pbVar4 != (byte *)0x0)))) {
      iVar6 = 1;
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
      pbVar4 = *(byte **)(param_2 + 0xc);
      *(byte **)(param_1 + 0xc) = pbVar4;
    }
    iVar1 = iVar6 * 0x10;
    param_3 = param_3 + iVar6 * -0x10;
    if (param_3 < 4) {
      iVar6 = 0;
    }
    else {
      pbVar5 = param_2 + iVar1;
      iVar6 = 0;
      pbVar7 = param_1 + iVar1;
      do {
        iVar6 = iVar6 + 4;
        param_3 = param_3 - 4;
        *(undefined4 *)pbVar7 = *(undefined4 *)pbVar5;
        pbVar5 = pbVar5 + 4;
        pbVar7 = pbVar7 + 4;
      } while (3 < param_3);
    }
    pbVar7 = param_1 + iVar6 + iVar1;
    param_2 = param_2 + iVar6 + iVar1;
  }
  if ((param_3 != 0) && ((param_3 == 1 || (param_3 != 0)))) {
    pbVar4 = (byte *)(uint)*param_2;
    *pbVar7 = *param_2;
    pbVar7 = pbVar7 + 1;
  }
  auVar3._4_4_ = pbVar4;
  auVar3._0_4_ = param_1;
  auVar3._8_4_ = pbVar7;
  return auVar3;
}


// ===== FUN_002363f0 @ 002363f0 (36 bytes)

undefined4 FUN_002363f0(undefined4 *param_1,undefined1 *param_2,uint param_3)

{
  if (param_2 == (undefined1 *)0x0) {
    return 0;
  }
  if (0xff < param_3) {
    *param_1 = 0x8a;
    return 0xffffffff;
  }
  *param_2 = (char)param_3;
  return 1;
}


// ===== FUN_00236420 @ 00236420 (7 bytes)

undefined4 FUN_00236420(void)

{
  return 0;
}


// ===== FUN_00236430 @ 00236430 (13 bytes)

undefined4 FUN_00236430(undefined4 *param_1)

{
  *param_1 = 0x1d;
  return 0xffffffff;
}


// ===== FUN_00236440 @ 00236440 (5 bytes)

void FUN_00236440(void)

{
  return;
}


// ===== FUN_00236450 @ 00236450 (25 bytes)

/* WARNING: Removing unreachable block (ram,0x0023645b) */

void FUN_00236450(void)

{
  diwb(0);
  return;
}


// ===== FUN_00236470 @ 00236470 (8 bytes)

undefined4 FUN_00236470(void)

{
  undefined4 uVar1;
  undefined4 in_CCOUNT;
  
  uVar1 = rsr_ccount(in_CCOUNT);
  return uVar1;
}


// ===== FUN_00236478 @ 00236478 (26 bytes)

void FUN_00236478(int param_1,undefined4 param_2)

{
  undefined4 in_INTERRUPT;
  
  if (param_1 == 0) {
    wsr_ccompare0(param_2,in_INTERRUPT);
    rsync();
    return;
  }
  if (param_1 == 1) {
    wsr_ccompare1(param_2,in_INTERRUPT);
    rsync();
    return;
  }
  return;
}


// ===== FUN_00236494 @ 00236494 (22 bytes)

undefined4 FUN_00236494(int param_1)

{
  undefined4 uVar1;
  undefined4 in_CCOMPARE0;
  undefined4 in_CCOMPARE1;
  
  if (param_1 == 0) {
    uVar1 = rsr_ccompare0(in_CCOMPARE0);
    return uVar1;
  }
  if (param_1 == 1) {
    uVar1 = rsr_ccompare1(in_CCOMPARE1);
    return uVar1;
  }
  return 0;
}


// ===== FUN_002364b0 @ 002364b0 (25 bytes)

/* WARNING: Removing unreachable block (ram,0x002364bb) */

void FUN_002364b0(void)

{
  diwbi(0);
  return;
}


// ===== FUN_002364d0 @ 002364d0 (36 bytes)

/* WARNING: Removing unreachable block (ram,0x002364da) */

void FUN_002364d0(void)

{
  iii(0);
  iii(0x100);
  iii(0x200);
  iii(0x300);
  isync();
  return;
}


// ===== FUN_002364f4 @ 002364f4 (10 bytes)

undefined8 FUN_002364f4(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = param_1 << 0x20 - (0x20 - (LZCOUNT(param_1) & 0x1fU));
    return CONCAT44((uVar1 >> 0xb) + (0x41d - LZCOUNT(param_1)) * 0x100000,uVar1 << 0x15);
  }
  return 0;
}


// ===== FUN_00236500 @ 00236500 (49 bytes)

undefined8 FUN_00236500(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
    uVar1 = LZCOUNT(iVar3);
    uVar2 = iVar3 << 0x20 - (0x20 - (uVar1 & 0x1f));
    return CONCAT44((uVar2 >> 0xb) + (0x41d - uVar1) * 0x100000 | param_1 & 0x80000000,uVar2 << 0x15
                   );
  }
  return 0;
}


// ===== FUN_00236540 @ 00236540 (669 bytes)

ulonglong FUN_00236540(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_4 == 0) {
    if (param_2 < param_3) {
      uVar10 = LZCOUNT(param_3);
      uVar2 = param_1;
      if (uVar10 != 0) {
        iVar7 = 0x20 - (uVar10 & 0x1f);
        param_3 = param_3 << 0x20 - iVar7;
        uVar2 = param_1 << 0x20 - iVar7;
        param_2 = (uint)(CONCAT44(param_2,param_1) >> iVar7);
      }
      iVar7 = ae_zext16(param_3);
      uVar9 = param_3 >> 0x10;
      uVar8 = iVar7 * (param_2 / uVar9);
      uVar12 = (uint)(CONCAT44(param_2 % uVar9,uVar2) >> 0x10);
      if (((uVar12 < uVar8) && (uVar12 = uVar12 + param_3, param_3 <= uVar12)) && (uVar12 < uVar8))
      {
        uVar12 = param_3 + uVar12;
      }
      uVar11 = iVar7 * ((uVar12 - uVar8) / uVar9);
      uVar2 = ae_zext16(uVar2);
      uVar2 = uVar2 | (uVar12 - uVar8) % uVar9 << 0x10;
      if (((uVar2 < uVar11) && (uVar2 = uVar2 + param_3, param_3 <= uVar2)) && (uVar2 < uVar11)) {
        return (ulonglong)((param_3 + uVar2) - uVar11 >> (uVar10 & 0x1f));
      }
      return (ulonglong)(uVar2 - uVar11 >> (uVar10 & 0x1f));
    }
    if (param_3 == 0) {
      param_3 = 1 / param_3;
    }
    uVar2 = LZCOUNT(param_3);
    if (uVar2 == 0) {
      uVar10 = param_3 >> 0x10;
      param_2 = param_2 - param_3;
      iVar7 = ae_zext16(param_3);
    }
    else {
      param_3 = param_3 << 0x20 - (0x20 - (uVar2 & 0x1f));
      uVar9 = param_2 >> (0x20 - uVar2 & 0x1f);
      uVar10 = param_3 >> 0x10;
      iVar7 = 0x20 - (uVar2 & 0x1f);
      uVar1 = CONCAT44(param_2,param_1) >> iVar7;
      param_1 = param_1 << 0x20 - iVar7;
      iVar7 = ae_zext16(param_3);
      uVar12 = iVar7 * (uVar9 / uVar10);
      uVar9 = (uint)(((ulonglong)(uVar9 % uVar10) << 0x20) >> 0x10) | (uint)(uVar1 >> 0x10) & 0xffff
      ;
      if (((uVar9 < uVar12) && (uVar9 = uVar9 + param_3, param_3 <= uVar9)) && (uVar9 < uVar12)) {
        uVar9 = param_3 + uVar9;
      }
      param_2 = ae_zext16((int)uVar1);
      uVar8 = iVar7 * ((uVar9 - uVar12) / uVar10);
      param_2 = param_2 | (uVar9 - uVar12) % uVar10 << 0x10;
      if (((param_2 < uVar8) && (param_2 = param_2 + param_3, param_3 <= param_2)) &&
         (param_2 < uVar8)) {
        param_2 = param_3 + param_2;
      }
      param_2 = param_2 - uVar8;
    }
    uVar12 = iVar7 * (param_2 / uVar10);
    uVar9 = (uint)(CONCAT44(param_2 % uVar10,param_1) >> 0x10);
    if (((uVar9 < uVar12) && (uVar9 = uVar9 + param_3, param_3 <= uVar9)) && (uVar9 < uVar12)) {
      uVar9 = param_3 + uVar9;
    }
    uVar11 = iVar7 * ((uVar9 - uVar12) / uVar10);
    uVar8 = ae_zext16(param_1);
    uVar8 = uVar8 | (uVar9 - uVar12) % uVar10 << 0x10;
    if (((uVar8 < uVar11) && (uVar8 = uVar8 + param_3, param_3 <= uVar8)) && (uVar8 < uVar11)) {
      return (ulonglong)((param_3 + uVar8) - uVar11 >> (uVar2 & 0x1f));
    }
    return (ulonglong)(uVar8 - uVar11 >> (uVar2 & 0x1f));
  }
  if (param_2 < param_4) {
    return CONCAT44(param_2,param_1);
  }
  uVar2 = LZCOUNT(param_4);
  uVar10 = 0x20 - uVar2;
  if (uVar2 == 0) {
    uVar2 = param_1 - param_3;
    if ((param_2 <= param_4) && (param_1 < param_3)) {
      return CONCAT44(param_2,param_1);
    }
    if (uVar2 <= param_1) {
      return CONCAT44(param_2 - param_4,uVar2);
    }
    return CONCAT44((param_2 - param_4) + -1,uVar2);
  }
  uVar8 = param_2 >> (uVar10 & 0x1f);
  iVar7 = 0x20 - (uVar2 & 0x1f);
  uVar1 = CONCAT44(param_2,param_1) >> iVar7;
  uVar9 = (uint)(CONCAT44(param_4,param_3) >> iVar7);
  iVar7 = ae_zext16(uVar9);
  uVar12 = uVar9 >> 0x10;
  uVar5 = uVar8 / uVar12;
  uVar3 = iVar7 * uVar5;
  uVar8 = (uint)(((ulonglong)(uVar8 % uVar12) << 0x20) >> 0x10) | (uint)(uVar1 >> 0x10) & 0xffff;
  uVar4 = ae_zext16((int)uVar1);
  uVar11 = uVar5;
  if (uVar8 < uVar3) {
    uVar8 = uVar9 + uVar8;
    uVar11 = uVar5 - 1;
    if ((uVar9 <= uVar8) && (uVar8 < uVar3)) {
      uVar11 = uVar5 - 2;
      uVar8 = uVar9 + uVar8;
    }
  }
  uVar6 = (uVar8 - uVar3) / uVar12;
  uVar5 = iVar7 * uVar6;
  iVar7 = 0x20 - (uVar2 & 0x1f);
  uVar4 = uVar4 | (uVar8 - uVar3) % uVar12 << 0x10;
  uVar12 = uVar6;
  if (uVar4 < uVar5) {
    uVar4 = uVar9 + uVar4;
    uVar12 = uVar6 - 1;
    if ((uVar9 <= uVar4) && (uVar4 < uVar5)) {
      uVar12 = uVar6 - 2;
      uVar4 = uVar9 + uVar4;
    }
  }
  param_3 = param_3 << 0x20 - iVar7;
  uVar12 = uVar12 | uVar11 << 0x10;
  uVar8 = uVar12 * param_3;
  uVar12 = (uint)((ulonglong)uVar12 * (ulonglong)param_3 >> 0x20);
  uVar4 = uVar4 - uVar5;
  if (uVar4 < uVar12) {
    param_1 = param_1 << 0x20 - iVar7;
  }
  else {
    param_1 = param_1 << 0x20 - iVar7;
    if ((uVar4 != uVar12) || (uVar8 <= param_1)) goto LAB_0023661b;
  }
  uVar12 = (uVar12 - uVar9) - (uint)(uVar8 < uVar8 - param_3);
  uVar8 = uVar8 - param_3;
LAB_0023661b:
  uVar8 = param_1 - uVar8;
  if (uVar8 <= param_1) {
    return CONCAT44(uVar4 - uVar12 >> (uVar2 & 0x1f),
                    uVar8 >> (uVar2 & 0x1f) | uVar4 - uVar12 << 0x20 - (0x20 - (uVar10 & 0x1f)));
  }
  uVar9 = (uVar4 - uVar12) - 1;
  return CONCAT44(uVar9 >> (uVar2 & 0x1f),
                  uVar8 >> (uVar2 & 0x1f) | uVar9 << 0x20 - (0x20 - (uVar10 & 0x1f)));
}


// ===== FUN_24020044 @ 24020044 (250 bytes)

/* WARNING: This function may have set the stack pointer */

void FUN_24020044(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 in_MEMCTL;
  
  wsr_intenable(0);
  wsr_vecbase(PTR__WindowOverflow4_24020004);
  wsr_atomctl(0x15);
  rsil(1);
  puVar1 = (undefined *)0x0;
  do {
    iiu(puVar1);
    puVar1 = puVar1 + 0x100;
  } while (puVar1 < PTR_DAT_24020008);
  isync();
  puVar1 = (undefined *)0x0;
  do {
    iii(puVar1);
    iii(puVar1 + 0x100);
    iii(puVar1 + 0x200);
    iii(puVar1 + 0x300);
    puVar1 = puVar1 + 0x400;
  } while (puVar1 < PTR_DAT_2402000c);
  isync();
  puVar1 = (undefined *)0x0;
  do {
    diu(puVar1);
    puVar1 = puVar1 + 0x100;
  } while (puVar1 < PTR_DAT_24020010);
  puVar1 = (undefined *)0x0;
  do {
    dii(puVar1);
    dii(puVar1 + 0x100);
    dii(puVar1 + 0x200);
    dii(puVar1 + 0x300);
    puVar1 = puVar1 + 0x400;
  } while (puVar1 < PTR_DAT_24020014);
  wsr_prefctl(PTR_DAT_24020018);
  uVar2 = 0;
  uVar4 = DAT_2402001c;
  do {
    if (uVar2 == (DAT_24020024 & DAT_24020020)) {
      witlb(uVar2,uVar4 & 0xf);
      isync();
      uVar2 = uVar2 - DAT_24020020;
      if (uVar2 < 0x10) goto LAB_240200e5;
    }
    else {
      witlb(uVar2,uVar4 & 0xf);
      uVar2 = uVar2 - DAT_24020020;
      if (uVar2 < 0x10) {
        isync();
LAB_240200e5:
        uVar2 = 0;
        uVar4 = DAT_2402001c;
        do {
          uVar3 = uVar4 & 0xf;
          wdtlb(uVar2,uVar3);
          uVar2 = uVar2 - DAT_24020020;
          uVar4 = uVar4 >> 4;
        } while (0xf < uVar2);
        dsync();
        uVar4 = rsr_memctl(in_MEMCTL);
        wsr_memctl(uVar4 | DAT_24020028);
        if (DAT_2402002c != (code *)0x0) {
          (*DAT_2402002c)(DAT_2402002c,DAT_24020028,uVar3);
        }
        wsr_windowstart(1);
        wsr_windowbase(0);
        rsync();
        wsr_excsave2(DAT_24020030);
        wsr_excsave3(DAT_24020034);
        *(undefined4 *)PTR_DAT_24020038 = DAT_24020034;
        (*(code *)PTR_SUB_2402003c)();
        do {
          ill();
        } while( true );
      }
    }
    uVar4 = uVar4 >> 4;
  } while( true );
}


// ===== _WindowOverflow4 @ 24020400 (15 bytes)

void _WindowOverflow4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 unaff_retaddr;
  
  *(undefined4 *)(param_4 + -0x10) = unaff_retaddr;
  *(BADSPACEBASE **)(param_4 + -0xc) = register0x00000004;
  *(undefined4 *)(param_4 + -8) = param_1;
  *(undefined4 *)(param_4 + -4) = param_2;
  rfwo();
  return;
}


// ===== _WindowUnderflow4 @ 24020440 (15 bytes)

undefined8 _WindowUnderflow4(void)

{
  int in_a5;
  
  rfwu();
  return *(undefined8 *)(in_a5 + -8);
}


// ===== FUN_24020450 @ 24020450 (45 bytes)

undefined4 FUN_24020450(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,uint param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint unaff_a8;
  int unaff_a9;
  undefined4 in_WindowBase;
  
  rsr_windowbase(in_WindowBase);
  uVar1 = rsil(0xf);
  uVar1 = uVar1 ^ (uVar1 >> 8 & 0xf ^ param_5) << 8;
  wsr_ps(uVar1);
  rsync();
  if ((param_3 & 0x80000000) == 0) {
    rfwu();
    return *(undefined4 *)(param_4 + -8);
  }
  if ((unaff_a8 & 0x40000000) != 0) {
    uVar2 = _WindowUnderflow12(uVar1);
    return uVar2;
  }
  rfwu();
  return *(undefined4 *)(unaff_a9 + -8);
}


// ===== _WindowOverflow8 @ 24020480 (30 bytes)

void _WindowOverflow8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_retaddr;
  int unaff_a9;
  undefined4 local_c;
  
  *(undefined4 *)(unaff_a9 + -0x10) = unaff_retaddr;
  *(BADSPACEBASE **)(unaff_a9 + -0xc) = register0x00000004;
  *(undefined4 *)(unaff_a9 + -8) = param_1;
  *(undefined4 *)(unaff_a9 + -4) = param_2;
  *(undefined4 *)(local_c + -0x20) = param_3;
  *(undefined4 *)(local_c + -0x1c) = param_4;
  *(undefined4 *)(local_c + -0x18) = param_5;
  *(undefined4 *)(local_c + -0x14) = param_6;
  rfwo();
  return;
}


// ===== _WindowUnderflow8 @ 240204c0 (30 bytes)

undefined1  [16] _WindowUnderflow8(void)

{
  undefined1 auVar1 [16];
  int iVar2;
  int unaff_a9;
  
  iVar2 = *(int *)(*(int *)(unaff_a9 + -0xc) + -0xc);
  auVar1._8_4_ = *(undefined4 *)(iVar2 + -0x20);
  auVar1._12_4_ = *(undefined4 *)(iVar2 + -0x1c);
  rfwu();
  auVar1._0_8_ = *(undefined8 *)(unaff_a9 + -8);
  return auVar1;
}


// ===== _WindowOverflow12 @ 24020500 (42 bytes)

void _WindowOverflow12(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_retaddr;
  undefined4 unaff_a8;
  undefined4 unaff_a9;
  undefined4 unaff_a10;
  undefined4 unaff_a11;
  int in_a13;
  undefined4 local_c;
  
  *(undefined4 *)(in_a13 + -0x10) = unaff_retaddr;
  *(BADSPACEBASE **)(in_a13 + -0xc) = register0x00000004;
  *(undefined4 *)(in_a13 + -8) = param_1;
  *(undefined4 *)(in_a13 + -4) = param_2;
  *(undefined4 *)(local_c + -0x30) = param_3;
  *(undefined4 *)(local_c + -0x2c) = param_4;
  *(undefined4 *)(local_c + -0x28) = param_5;
  *(undefined4 *)(local_c + -0x24) = param_6;
  *(undefined4 *)(local_c + -0x20) = unaff_a8;
  *(undefined4 *)(local_c + -0x1c) = unaff_a9;
  *(undefined4 *)(local_c + -0x18) = unaff_a10;
  *(undefined4 *)(local_c + -0x14) = unaff_a11;
  rfwo();
  return;
}


// ===== _WindowUnderflow12 @ 24020540 (42 bytes)

undefined1  [16] _WindowUnderflow12(void)

{
  undefined1 auVar1 [16];
  int iVar2;
  int in_a13;
  
  iVar2 = *(int *)(*(int *)(in_a13 + -0xc) + -0xc);
  auVar1._8_4_ = *(undefined4 *)(iVar2 + -0x30);
  auVar1._12_4_ = *(undefined4 *)(iVar2 + -0x2c);
  rfwu();
  auVar1._0_8_ = *(undefined8 *)(in_a13 + -8);
  return auVar1;
}


// ===== _Vector_57c @ 2402057c (26 bytes)

void _Vector_57c(void)

{
  code *pcVar1;
  undefined4 unaff_retaddr;
  undefined4 in_EPC2;
  undefined4 in_EPS2;
  undefined4 in_EXCSAVE1;
  
  wsr_exccause(4);
  pcVar1 = (code *)xsr_excsave1(unaff_retaddr,in_EXCSAVE1);
  xsr_excsave1_1(unaff_retaddr,in_EXCSAVE1);
  rsr_eps2(in_EPS2);
  rsr_epc2(in_EPC2);
                    /* WARNING: Does not return */
  (*pcVar1)();
}


// ===== _Vector_59c @ 2402059c (12 bytes)

void _Vector_59c(void)

{
  undefined4 unaff_retaddr;
  
  wsr_excsave3(unaff_retaddr);
  (*(code *)dsp_dtcm_base)();
  do {
    ill();
  } while( true );
}


// ===== _Vector_5bc @ 240205bc (12 bytes)

void _Vector_5bc(void)

{
  undefined4 unaff_retaddr;
  
  wsr_excsave4(unaff_retaddr);
  (*(code *)PTR_FUN_24000004)();
  do {
    ill();
  } while( true );
}


// ===== _Vector_5dc @ 240205dc (12 bytes)

void _Vector_5dc(void)

{
  undefined4 unaff_retaddr;
  
  wsr_excsave5(unaff_retaddr);
  (*(code *)PTR_SUB_24000008)();
  do {
    ill();
  } while( true );
}


// ===== _Vector_61c @ 2402061c (24 bytes)

void _Vector_61c(void)

{
  code *pcVar1;
  undefined4 unaff_retaddr;
  undefined4 in_EPC1;
  undefined4 in_EXCSAVE1;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  pcVar1 = (code *)xsr_excsave1(unaff_retaddr,in_EXCSAVE1);
  xsr_excsave1_1(unaff_retaddr,in_EXCSAVE1);
  rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  rsr_epc1(in_EPC1);
                    /* WARNING: Does not return */
  (*pcVar1)();
}


// ===== _Vector_63c @ 2402063c (6 bytes)

void _Vector_63c(void)

{
  do {
    breakpoint(0x1000,0x2402063c,1,0xf);
  } while( true );
}

