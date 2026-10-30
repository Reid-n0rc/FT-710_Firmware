// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== __s2b @ 002304f0 (159 bytes)

/* newlib mprec.c: __multadd [inference] */

int __s2b(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar4 = (param_4 + 8) / 9;
  if (iVar4 < 2) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    iVar2 = 1;
    do {
      iVar2 = iVar2 << 1;
      iVar3 = iVar3 + 1;
    } while (iVar2 < iVar4);
  }
  iVar4 = _Balloc(param_1,iVar3);
  *(undefined4 *)(iVar4 + 0x14) = param_5;
  *(undefined4 *)(iVar4 + 0x10) = 1;
  if (param_3 < 10) {
    pbVar5 = (byte *)(param_2 + 10);
    iVar3 = 9;
  }
  else {
    iVar2 = param_3 + -9;
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    iVar3 = param_2 + 0x12;
    do {
      iVar4 = __multadd(param_1,iVar4,10,*(byte *)(iVar3 + -9) - 0x30);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3 + param_2 + 9);
    iVar3 = iVar2 + 9;
    pbVar5 = (byte *)(param_2 + 9 + iVar2 + 1);
  }
  if (iVar3 < param_4) {
    pbVar1 = pbVar5 + (param_4 - iVar3);
    do {
      iVar4 = __multadd(param_1,iVar4,10,*pbVar5 - 0x30);
      pbVar5 = pbVar5 + 1;
    } while (pbVar5 != pbVar1);
  }
  return iVar4;
}


// ===== __i2b @ 002305a0 (29 bytes)

/* newlib mprec.c: _Balloc(1) [inference] */

int __i2b(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _Balloc(param_1,1);
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  return iVar1;
}


// ===== __multiply @ 002305c0 (388 bytes)

/* newlib mprec.c [inference] */

void __multiply(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  int iVar17;
  int *local_30;
  
  iVar6 = *(int *)(param_2 + 0x10);
  iVar3 = *(int *)(param_3 + 0x10);
  iVar17 = param_3;
  iVar2 = iVar3;
  if (iVar6 < iVar3) {
    iVar17 = param_2;
    param_2 = param_3;
    iVar2 = iVar6;
    iVar6 = iVar3;
  }
  iVar1 = iVar6 + iVar2;
  iVar3 = *(int *)(param_2 + 4);
  if (*(int *)(param_2 + 8) < iVar1) {
    iVar3 = *(int *)(param_2 + 4) + 1;
  }
  iVar3 = _Balloc(param_1,iVar3);
  if (iVar1 * 4 < 1) {
    local_30 = (int *)(iVar1 * 4 + iVar3 + 0x14);
  }
  else {
    local_30 = (int *)(iVar1 * 4 + iVar3 + 0x14);
    iVar15 = iVar1 * 4 + 3 >> 2;
    if ((iVar15 != 0) && ((iVar15 == 1 || (iVar15 != 0)))) {
      *(undefined4 *)(iVar3 + 0x14) = 0;
    }
  }
  if (0 < iVar2 << 2) {
    uVar12 = iVar17 + 0x14;
    iVar15 = iVar2 * 4 + iVar17;
    puVar16 = (uint *)(iVar6 * 4 + param_2 + 0x14);
    puVar13 = (uint *)(iVar3 + 0x14);
    iVar2 = iVar3;
    do {
      uVar7 = *(uint *)(iVar17 + 0x14);
      uVar5 = ae_zext16(uVar7);
      if (uVar5 != 0) {
        uVar7 = 0;
        puVar8 = puVar13;
        puVar10 = (uint *)(param_2 + 0x14);
        do {
          iVar11 = ae_zext16(*puVar8);
          iVar6 = rsr_acclo((ulonglong)(ushort)uVar5 * (ulonglong)(ushort)(*puVar10 >> 0x10));
          uVar7 = uVar7 + iVar11 + (uVar5 & 0xffff) * (*puVar10 & 0xffff);
          uVar9 = ae_zext16(uVar7);
          uVar7 = (*puVar8 >> 0x10) + iVar6 + (uVar7 >> 0x10);
          puVar10 = puVar10 + 1;
          *puVar8 = uVar9 | uVar7 * 0x10000;
          uVar7 = uVar7 >> 0x10;
          puVar8 = puVar8 + 1;
        } while (puVar10 < puVar16);
        *puVar8 = uVar7;
        uVar7 = *(uint *)(iVar17 + 0x14);
      }
      if (uVar7 >> 0x10 != 0) {
        uVar14 = *(uint *)(iVar2 + 0x14);
        uVar9 = *puVar13;
        uVar5 = 0;
        puVar8 = puVar13;
        puVar10 = (uint *)(param_2 + 0x14);
        do {
          uVar4 = ae_l16ui_n(puVar10,0);
          uVar14 = ae_zext16(uVar14);
          uVar5 = uVar5 + (uVar9 >> 0x10) + (uVar4 & 0xffff) * (uVar7 >> 0x10);
          *puVar8 = uVar14 | uVar5 * 0x10000;
          uVar9 = puVar8[1];
          iVar6 = rsr_acclo((ulonglong)(ushort)(uVar7 >> 0x10) *
                            (ulonglong)(ushort)(*puVar10 >> 0x10));
          iVar11 = ae_zext16(uVar9);
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
          uVar14 = iVar11 + iVar6 + (uVar5 >> 0x10);
          uVar5 = uVar14 >> 0x10;
        } while (puVar10 < puVar16);
        *puVar8 = uVar14;
      }
      iVar2 = iVar2 + 4;
      puVar13 = puVar13 + 1;
      uVar12 = uVar12 + 4;
      iVar17 = iVar17 + 4;
    } while (uVar12 < iVar15 + 0x14U);
  }
  do {
    iVar17 = iVar1;
    if (iVar17 < 1) break;
    local_30 = local_30 + -1;
    iVar1 = iVar17 + -1;
  } while (*local_30 == 0);
  *(int *)(iVar3 + 0x10) = iVar17;
  return;
}


// ===== __pow5mult @ 00230750 (157 bytes)

/* newlib mprec.c: p05 table {5, 25, 125} 0x205F40 [inference] */

void __pow5mult(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if ((param_3 & 3) != 0) {
    param_2 = __multadd(param_1,param_2,*(undefined4 *)(&DAT_0020613c + (param_3 & 3) * 4),0);
  }
  param_3 = (int)param_3 >> 2;
  if (param_3 == 0) {
    return;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x48);
  if (*(undefined4 **)(param_1 + 0x48) == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)__i2b(param_1,0x271);
    *(undefined4 **)(param_1 + 0x48) = puVar4;
    *puVar4 = 0;
  }
  do {
    puVar1 = puVar4;
    uVar2 = param_3 & 1;
    param_3 = (int)param_3 >> 1;
    if (uVar2 == 0) {
      if (param_3 == 0) {
        return;
      }
      puVar4 = (undefined4 *)*puVar1;
    }
    else {
      uVar3 = __multiply(param_1,param_2,puVar1);
      _Bfree(param_1,param_2);
      if (param_3 == 0) {
        return;
      }
      puVar4 = (undefined4 *)*puVar1;
      param_2 = uVar3;
    }
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)__multiply(param_1,puVar1,puVar1);
      *puVar1 = puVar4;
      *puVar4 = 0;
    }
  } while( true );
}


// ===== __lshift @ 00230800 (197 bytes)

/* newlib mprec.c [inference] */

void __lshift(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  
  iVar3 = (int)param_3 >> 5;
  iVar1 = *(int *)(param_2 + 0x10) + iVar3;
  iVar4 = iVar1 + 1;
  iVar8 = *(int *)(param_2 + 4);
  for (iVar7 = *(int *)(param_2 + 8); iVar7 < iVar4; iVar7 = iVar7 << 1) {
    iVar8 = iVar8 + 1;
  }
  iVar7 = _Balloc(param_1,iVar8);
  if ((0 < iVar3) && ((iVar3 == 1 || (0 < iVar3)))) {
    *(undefined4 *)(iVar7 + 0x14) = 0;
  }
  puVar5 = (uint *)(param_2 + 0x14);
  iVar8 = 0;
  if (0 < iVar3) {
    iVar8 = iVar3;
  }
  iVar8 = iVar8 * 4 + iVar7;
  puVar6 = (uint *)(iVar8 + 0x14);
  puVar9 = (uint *)(*(int *)(param_2 + 0x10) * 4 + param_2 + 0x14);
  if ((param_3 & 0x1f) == 0) {
    do {
      *(uint *)(iVar8 + 0x14) = *puVar5;
      puVar5 = puVar5 + 1;
      iVar8 = iVar8 + 4;
    } while (puVar5 < puVar9);
  }
  else {
    uVar2 = 0;
    do {
      *puVar6 = uVar2 | *puVar5 << 0x20 - (0x20 - (param_3 & 0x1f));
      uVar2 = *puVar5;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
      uVar2 = uVar2 >> (0x20 - (param_3 & 0x1f) & 0x1f);
    } while (puVar5 < puVar9);
    *puVar6 = uVar2;
    iVar4 = 0;
    if (uVar2 != 0) {
      iVar4 = iVar1 + 2;
    }
  }
  *(int *)(iVar7 + 0x10) = iVar4 + -1;
  _Bfree(param_1,param_2);
  return;
}


// ===== __mdiff @ 002308e0 (316 bytes)

/* newlib mprec.c: __mcmp, _Balloc [inference] */

int __mdiff(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  
  iVar1 = __mcmp(param_2,param_3);
  if (iVar1 != 0) {
    iVar12 = param_2;
    if (iVar1 >= 0) {
      iVar12 = param_3;
      param_3 = param_2;
    }
    iVar2 = _Balloc(param_1,*(undefined4 *)(param_3 + 4));
    puVar9 = (uint *)(param_3 + 0x14);
    iVar13 = *(int *)(param_3 + 0x10);
    iVar10 = *(int *)(iVar12 + 0x10);
    iVar7 = 0;
    *(uint *)(iVar2 + 0xc) = (uint)(iVar1 < 0);
    puVar11 = (uint *)(iVar12 + 0x14);
    iVar1 = iVar2 + -0x1ec;
    puVar6 = (uint *)(iVar2 + 0x14);
    do {
      puVar8 = puVar6;
      iVar5 = ae_zext16(*puVar9);
      iVar3 = ae_zext16(*puVar11);
      iVar7 = iVar7 + (iVar5 - iVar3);
      uVar4 = ae_zext16(iVar7);
      puVar6 = puVar8 + 1;
      iVar7 = (iVar7 >> 0x10) + ((*puVar9 >> 0x10) - (*puVar11 >> 0x10));
      puVar9 = puVar9 + 1;
      *(uint *)(iVar1 + 0x200) = iVar7 * 0x10000 | uVar4;
      puVar11 = puVar11 + 1;
      iVar7 = iVar7 >> 0x10;
      iVar1 = iVar1 + 4;
    } while (puVar11 < (uint *)(iVar10 * 4 + iVar12 + 0x14));
    param_3 = iVar13 * 4 + param_3;
    if (puVar9 < (uint *)(param_3 + 0x14U)) {
      iVar12 = (param_3 - (int)puVar9) + 0x17 >> 2;
      iVar1 = 0;
      if ((iVar12 != 0) && ((iVar12 == 1 || (iVar12 != 0)))) {
        iVar1 = 1;
        iVar12 = ae_zext16(*puVar9);
        uVar4 = ae_zext16(iVar7 + iVar12);
        *puVar6 = ((iVar7 + iVar12 >> 0x10) + (*puVar9 >> 0x10)) * 0x10000 | uVar4;
      }
      puVar6 = puVar6 + iVar1;
      uVar4 = puVar6[-1];
    }
    else {
      uVar4 = *puVar8;
    }
    iVar1 = 0;
    if (uVar4 == 0) {
      iVar1 = 0;
      do {
        puVar9 = puVar6 + -2;
        iVar1 = iVar1 + 1;
        puVar6 = puVar6 + -1;
      } while (*puVar9 == 0);
    }
    *(int *)(iVar2 + 0x10) = iVar13 - iVar1;
    return iVar2;
  }
  iVar1 = _Balloc(param_1,0);
  *(undefined4 *)(iVar1 + 0x10) = 1;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  return iVar1;
}


// ===== __ulp @ 00230a30 (88 bytes)

/* newlib mprec.c: (P-1) << 20 = 0xFCC00000 [fact for the constants] */

ulonglong __ulp(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (param_2 & 0x7ff00000) + 0xfcc00000;
  if (0 < (int)uVar1) {
    return (ulonglong)uVar1 << 0x20;
  }
  uVar1 = (int)(0x3400000 - (param_2 & 0x7ff00000)) >> 0x14;
  if (0x13 < (int)uVar1) {
    if ((int)uVar1 < 0x33) {
      return (ulonglong)(uint)(1 << 0x20 - (0x20 - (0x33 - uVar1 & 0x1f)));
    }
    return 1;
  }
  return (ulonglong)(uint)((int)&DAT_00080000 >> (uVar1 & 0x1f)) << 0x20;
}


// ===== __b2d @ 00230a90 (223 bytes)

/* newlib mprec.c: __hi0bits, 0x3FF00000 [inference] */

ulonglong __b2d(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  iVar2 = *(int *)(param_1 + 0x10) * 4 + param_1;
  uVar3 = *(uint *)(iVar2 + 0x10);
  uVar7 = iVar2 + 0x10;
  iVar8 = iVar2 + -0x1f0;
  iVar1 = __hi0bits(uVar3);
  uVar9 = param_1 + 0x14;
  *param_2 = 0x20 - iVar1;
  if (iVar1 < 0xb) {
    uVar4 = 0xb - iVar1;
    uVar5 = uVar3 >> (uVar4 & 0x1f);
    if (uVar9 < uVar7) {
      return CONCAT44(uVar5,*(uint *)(iVar2 + 0xc) >> (uVar4 & 0x1f) |
                            uVar3 << 0x20 - (0x20 - (iVar1 + 0x15U & 0x1f))) | 0x3ff0000000000000;
    }
    return CONCAT44(uVar5,0U >> (uVar4 & 0x1f) | uVar3 << 0x20 - (0x20 - (iVar1 + 0x15U & 0x1f))) |
           0x3ff0000000000000;
  }
  uVar4 = 0;
  if (uVar9 < uVar7) {
    iVar8 = iVar2 + -500;
    uVar7 = iVar2 + 0xc;
    uVar4 = *(uint *)(iVar2 + 0xc);
  }
  if (iVar1 != 0xb) {
    uVar5 = iVar1 - 0xb;
    uVar6 = 0x2b - iVar1;
    uVar3 = uVar4 >> (uVar6 & 0x1f) | uVar3 << 0x20 - (0x20 - (uVar5 & 0x1f));
    if (uVar9 < uVar7) {
      return CONCAT44(uVar3,*(uint *)(iVar8 + 0x1fc) >> (uVar6 & 0x1f) |
                            uVar4 << 0x20 - (0x20 - (uVar5 & 0x1f))) | 0x3ff0000000000000;
    }
    return CONCAT44(uVar3,0U >> (uVar6 & 0x1f) | uVar4 << 0x20 - (0x20 - (uVar5 & 0x1f))) |
           0x3ff0000000000000;
  }
  return CONCAT44(uVar3,uVar4) | 0x3ff0000000000000;
}


// ===== __d2b @ 00230b70 (202 bytes)

/* newlib mprec.c: __lo0bits, __hi0bits [inference] */

void __d2b(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int *param_5,int *param_6
          )

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uStack_28;
  uint auStack_24 [9];
  
  iVar1 = _Balloc(param_1,1);
  uVar4 = param_4 >> 0x14 & 0x7ff;
  uStack_28 = param_4 & (uint)&DAT_000fffff;
  if (uVar4 != 0) {
    uStack_28 = param_4 & (uint)&DAT_000fffff | (uint)&DAT_00100000;
  }
  if (param_3 == 0) {
    iVar3 = __lo0bits(&uStack_28);
    *(uint *)(iVar1 + 0x14) = uStack_28;
    uVar5 = 1;
    *(undefined4 *)(iVar1 + 0x10) = 1;
    uVar2 = iVar3 + 0x20;
  }
  else {
    auStack_24[0] = param_3;
    uVar2 = __lo0bits(auStack_24);
    uVar5 = uStack_28;
    if (uVar2 == 0) {
      *(uint *)(iVar1 + 0x14) = auStack_24[0];
    }
    else {
      *(uint *)(iVar1 + 0x14) = auStack_24[0] | uStack_28 << 0x20 - (0x20 - (0x20 - uVar2 & 0x1f));
      uStack_28 = uStack_28 >> (uVar2 & 0x1f);
    }
    *(uint *)(iVar1 + 0x18) = uStack_28;
    if (uStack_28 != 0) {
      uVar5 = 2;
    }
    *(uint *)(iVar1 + 0x10) = uVar5;
  }
  if (uVar4 != 0) {
    *param_5 = uVar2 + uVar4 + -0x433;
    *param_6 = 0x35 - uVar2;
    return;
  }
  *param_5 = uVar2 + uVar4 + -0x432;
  iVar1 = __hi0bits(*(undefined4 *)(uVar5 * 4 + iVar1 + 0x10));
  *param_6 = uVar5 * 0x20 - iVar1;
  return;
}


// ===== __ratio @ 00230c40 (115 bytes)

/* newlib mprec.c: __b2d twice, __divdf3 [inference] */

undefined4 __ratio(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  
  uVar5 = __b2d(param_1,&iStack_40);
  iVar3 = (int)((ulonglong)uVar5 >> 0x20);
  uVar6 = __b2d(param_2,&iStack_3c);
  iVar4 = (int)((ulonglong)uVar6 >> 0x20);
  iVar2 = (*(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10)) * 0x20 + (iStack_40 - iStack_3c);
  if (iVar2 < 1) {
    iVar4 = iVar4 + iVar2 * -0x100000;
    uStack_30 = (int)uVar6;
    iStack_2c = iVar4;
  }
  else {
    iVar3 = iVar3 + iVar2 * 0x100000;
    uStack_38 = (int)uVar5;
    iStack_34 = iVar3;
  }
  uVar1 = __divdf3((int)uVar5,iVar3,(int)uVar6,iVar4);
  return uVar1;
}


// ===== _mprec_log10 @ 00230cc0 (73 bytes)

/* newlib mprec.c: tens table 0x206010, x10.0 (0x40240000) loop [fact for the constants] */

undefined8 _mprec_log10(int param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 0x3ff0000000000000;
  if (param_1 < 0x18) {
    return *(undefined8 *)(&DAT_00206010 + param_1 * 8);
  }
  iVar1 = 0;
  if (param_1 < 1) {
    return 0;
  }
  do {
    uVar2 = __muldf3((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x40240000);
    iVar1 = iVar1 + 1;
  } while (iVar1 != param_1);
  return uVar2;
}


// ===== FUN_00230d10 @ 00230d10 (101 bytes)

undefined4 FUN_00230d10(int param_1,undefined *param_2)

{
  if (((param_2 == (undefined *)0x0) && (param_1 == 0)) ||
     ((param_2 == (undefined *)0x80000000 && (param_1 == 0)))) {
    return 2;
  }
  if ((param_2 + -0x100000 < (undefined *)0x7fe00000) ||
     (param_2 + 0x7ff00000 < (undefined *)0x7fe00000)) {
    return 4;
  }
  if ((&DAT_000fffff < param_2) && ((-1 < (int)param_2 || ((undefined *)0x800fffff < param_2)))) {
    if (((param_2 != (undefined *)0x7ff00000) || (param_1 != 0)) &&
       ((param_2 != (undefined *)0xfff00000 || (param_1 != 0)))) {
      return 0;
    }
    return 1;
  }
  return 3;
}


// ===== __sread @ 00230d80 (54 bytes)

/* newlib stdio.c: _read_r [inference] */

int __sread(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = _read_r(param_1,(int)*(short *)(param_2 + 0xe),param_3,param_4);
  if (-1 < iVar1) {
    *(int *)(param_2 + 0x50) = *(int *)(param_2 + 0x50) + iVar1;
    return iVar1;
  }
  *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xefff;
  return iVar1;
}


// ===== __swrite @ 00230dc0 (58 bytes)

/* newlib stdio.c: _lseek_r on append, _write_r [inference] */

undefined4 __swrite(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = *(ushort *)(param_2 + 0xc);
  if ((uVar1 & 0x100) != 0) {
    _lseek_r(param_1,(int)*(short *)(param_2 + 0xe),0,2);
    uVar1 = *(ushort *)(param_2 + 0xc);
  }
  *(ushort *)(param_2 + 0xc) = uVar1 & 0xefff;
  uVar2 = _write_r(param_1,(int)*(short *)(param_2 + 0xe),param_3,param_4);
  return uVar2;
}


// ===== __sseek @ 00230e00 (63 bytes)

/* newlib stdio.c: _lseek_r, __SOFF 0x1000 [inference] */

int __sseek(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = _lseek_r(param_1,(int)*(short *)(param_2 + 0xe),param_3,param_4);
  if (iVar1 != -1) {
    *(int *)(param_2 + 0x50) = iVar1;
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 0x1000;
    return iVar1;
  }
  *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xefff;
  return -1;
}


// ===== __sclose @ 00230e40 (16 bytes)

/* newlib stdio.c: _close_r [inference] */

undefined4 __sclose(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = _close_r(param_1,(int)*(short *)(param_2 + 0xe));
  return uVar1;
}


// ===== strlen @ 00230e50 (102 bytes)

/* WARNING: Removing unreachable block (ram,0x00230e8d) */
/* newlib strlen (word-at-a-time) [inference] */

char * strlen(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_1 + -1;
  puVar2 = param_1;
  if ((((uint)param_1 & 1) == 0) ||
     (puVar2 = (uint *)((int)param_1 + -3), puVar4 = puVar2, (char)*param_1 != '\0')) {
    puVar1 = puVar4;
    if (((uint)puVar2 & 2) != 0) {
      puVar2 = (uint *)((int)puVar4 + 2);
      if ((*puVar2 & 0xff0000) == 0) goto LAB_00230eb1;
      puVar1 = puVar2;
      if ((*puVar2 & 0xff000000) == 0) {
        return (char *)((int)puVar4 + (5 - (int)param_1));
      }
    }
    uVar3 = puVar1[1];
    puVar2 = puVar1 + 1;
    if ((uVar3 & 0xff) == 0) goto LAB_00230ea5;
    if ((uVar3 & (uint)&DAT_0000ff00) == 0) {
      return (char *)((int)puVar1 + (5 - (int)param_1));
    }
    if ((uVar3 & 0xff0000) == 0) {
LAB_00230eb1:
      return (char *)((int)puVar2 + (2 - (int)param_1));
    }
  }
  puVar2 = (uint *)((int)puVar2 + 3);
LAB_00230ea5:
  return (char *)((int)puVar2 - (int)param_1);
}


// ===== __sprint_r @ 00230ec0 (145 bytes)

/* newlib vfprintf.c: __sfputwc loop (wide streams) or __sfvwrite_r [inference] */

undefined4 __sprint_r(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  int local_30;
  
  iVar5 = param_3[2];
  if (iVar5 == 0) {
    param_3[1] = 0;
    return 0;
  }
  if ((*(uint *)(param_2 + 100) & 0x2000) != 0) {
    puVar3 = (undefined4 *)*param_3;
    do {
      puVar2 = (undefined2 *)*puVar3;
      uVar4 = (uint)puVar3[1] >> 1;
      puVar6 = puVar2 + uVar4;
      if (uVar4 == 0) {
        local_30 = 0;
      }
      else {
        local_30 = uVar4 << 1;
        do {
          iVar5 = __fputwc(param_1,*puVar2,param_2);
          puVar2 = puVar2 + 1;
          if (iVar5 == -1) {
            param_3[2] = 0;
            param_3[1] = 0;
            return 0xffffffff;
          }
        } while (puVar2 != puVar6);
        iVar5 = param_3[2];
      }
      iVar5 = iVar5 - local_30;
      param_3[2] = iVar5;
      puVar3 = puVar3 + 2;
    } while (iVar5 != 0);
    param_3[2] = 0;
    param_3[1] = 0;
    return 0;
  }
  uVar1 = __sfvwrite_r(param_1,param_2,param_3);
  param_3[2] = 0;
  param_3[1] = 0;
  return uVar1;
}


// ===== __sbprintf_i @ 00230f60 (175 bytes)

/* newlib vfiprintf.c copy of __sbprintf (vfiprintf into a stack buffer, fflush) [inference] */

int __sbprintf_i(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined1 *apuStack_4b0 [2];
  undefined4 uStack_4a8;
  ushort uStack_4a4;
  undefined2 uStack_4a2;
  undefined1 *puStack_4a0;
  undefined4 uStack_49c;
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_48c;
  undefined4 uStack_44c;
  undefined1 auStack_440 [1036];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uStack_4a8 = 0x400;
  uStack_49c = 0x400;
  apuStack_4b0[0] = auStack_440;
  uStack_494 = *(undefined4 *)(param_2 + 0x1c);
  uStack_4a2 = *(undefined2 *)(param_2 + 0xe);
  uStack_4a4 = *(ushort *)(param_2 + 0xc) & 0xfffd;
  uStack_48c = *(undefined4 *)(param_2 + 0x24);
  uStack_44c = *(undefined4 *)(param_2 + 100);
  uStack_498 = 0;
  puStack_4a0 = apuStack_4b0[0];
  uStack_34 = param_4;
  uStack_30 = param_5;
  uStack_2c = param_6;
  iVar1 = _vfiprintf_r(param_1,apuStack_4b0,param_3,param_4,param_5,param_6);
  if ((-1 < iVar1) && (iVar2 = _fflush_r(param_1,apuStack_4b0), iVar2 != 0)) {
    iVar1 = -1;
  }
  if (((uint)(int)(short)uStack_4a4 >> 6 & 1) != 0) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 0x40;
    return iVar1;
  }
  return iVar1;
}


// ===== vfiprintf @ 00231020 (31 bytes)

/* newlib vfiprintf.c: _vfiprintf_r(_impure_ptr) [inference] */

undefined4
vfiprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
         undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = _vfiprintf_r(PTR_DAT_00237f00,param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}


// ===== _vfiprintf_r @ 00231040 (1298 bytes)

/* WARNING: Removing unreachable block (ram,0x00231887) */
/* WARNING: Removing unreachable block (ram,0x00232270) */
/* WARNING: Removing unreachable block (ram,0x00232276) */
/* WARNING: Removing unreachable block (ram,0x00232285) */
/* WARNING: Removing unreachable block (ram,0x00232297) */
/* WARNING: Removing unreachable block (ram,0x002322a6) */
/* WARNING: Removing unreachable block (ram,0x002322b2) */
/* WARNING: Removing unreachable block (ram,0x00231fe0) */
/* WARNING: Removing unreachable block (ram,0x002323f6) */
/* WARNING: Removing unreachable block (ram,0x00231cbd) */
/* WARNING: Removing unreachable block (ram,0x00231fa7) */
/* WARNING: Removing unreachable block (ram,0x0023222a) */
/* WARNING: Removing unreachable block (ram,0x002321e8) */
/* WARNING: Removing unreachable block (ram,0x00231422) */
/* WARNING: Removing unreachable block (ram,0x00231ae5) */
/* WARNING: Removing unreachable block (ram,0x002322d2) */
/* WARNING: Removing unreachable block (ram,0x00231195) */
/* WARNING: Removing unreachable block (ram,0x00232442) */
/* WARNING: Removing unreachable block (ram,0x00232436) */
/* WARNING: Removing unreachable block (ram,0x00231fb9) */
/* WARNING: Removing unreachable block (ram,0x002322e9) */
/* WARNING: Removing unreachable block (ram,0x002322f5) */
/* WARNING: Type propagation algorithm not settling */
/* newlib vfiprintf.c (integer-only printf, 5,168 bytes) [inference] */

char * _vfiprintf_r(int param_1,int param_2,byte *param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  char **ppcVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  byte *pbVar9;
  char *pcVar10;
  int *piVar11;
  int iVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  uint uVar17;
  char *pcVar18;
  char *pcVar19;
  int iVar20;
  undefined8 uVar21;
  int aiStack_130 [16];
  undefined1 *puStack_f0;
  int iStack_ec;
  int iStack_e8;
  char acStack_e0 [39];
  char cStack_b9;
  char acStack_b8 [8];
  undefined1 uStack_b0;
  char cStack_af;
  byte abStack_ae [2];
  uint uStack_ac;
  char *pcStack_a8;
  char *pcStack_a4;
  char *pcStack_a0;
  char *pcStack_9c;
  char *pcStack_98;
  char *pcStack_94;
  uint uStack_90;
  char *pcStack_8c;
  int iStack_88;
  int iStack_84;
  char *pcStack_80;
  char *pcStack_7c;
  char *pcStack_78;
  char *pcStack_74;
  char *pcStack_70;
  int iStack_6c;
  char *pcStack_68;
  byte *pbStack_64;
  int iStack_60;
  uint uStack_58;
  byte *pbStack_54;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  iStack_6c = param_6;
  iStack_88 = param_4;
  iStack_84 = param_5;
  iStack_60 = param_1;
  iStack_34 = param_4;
  iStack_30 = param_5;
  iStack_2c = param_6;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x38) == 0)) {
    __sinit(param_1);
  }
  uVar8 = (uint)*(short *)(param_2 + 0xc);
  if ((uVar8 >> 0xd & 1) == 0) {
    uVar8 = uVar8 | (uint)&DAT_00002000;
    *(short *)(param_2 + 0xc) = (short)uVar8;
    *(uint *)(param_2 + 100) = *(uint *)(param_2 + 100) & 0xffffdfff;
  }
  if (((uVar8 >> 3 & 1) == 0) || (*(int *)(param_2 + 0x10) == 0)) {
    iVar6 = __swsetup_r(iStack_60,param_2);
    if (iVar6 != 0) {
      return (char *)0xffffffff;
    }
    uVar8 = (uint)*(short *)(param_2 + 0xc);
  }
  if (((uVar8 & 0x1a) == 10) && (-1 < *(short *)(param_2 + 0xe))) {
    pcVar10 = (char *)__sbprintf_i(iStack_60,param_2,param_3,iStack_34,iStack_30,iStack_2c);
    return pcVar10;
  }
  iStack_e8 = 0;
  iStack_ec = 0;
  pcStack_a4 = &cStack_b9;
  pcStack_70 = (char *)0x0;
  pcStack_98 = acStack_b8;
  pcStack_78 = (char *)0xffffffff;
  piVar5 = aiStack_130;
  puStack_f0 = (undefined1 *)aiStack_130;
  pbStack_64 = param_3;
LAB_002310cd:
  iVar6 = 0;
  if (*pbStack_64 == 0) {
LAB_002315d8:
    if (iStack_e8 != 0) {
      __sprint_r(iStack_60,param_2,&puStack_f0);
      ppcVar2 = &pcStack_78;
      if ((*(ushort *)(param_2 + 0xc) & 0x40) == 0) {
        ppcVar2 = &pcStack_70;
      }
      return *ppcVar2;
    }
LAB_002312c9:
    ppcVar2 = &pcStack_78;
    if ((*(ushort *)(param_2 + 0xc) & 0x40) == 0) {
      ppcVar2 = &pcStack_70;
    }
    return *ppcVar2;
  }
  pbVar9 = pbStack_64;
  if (*pbStack_64 != 0x25) {
    do {
      iVar6 = iVar6 + 1;
      pbVar9 = pbStack_64 + iVar6;
      bVar13 = *pbVar9;
      if (bVar13 == 0) break;
    } while (bVar13 != 0x25);
    if (iVar6 != 0) {
      pbStack_54 = pbVar9;
      piVar5[1] = iVar6;
      *piVar5 = (int)pbStack_64;
      iStack_e8 = iStack_e8 + iVar6;
      iStack_ec = iStack_ec + 1;
      piVar5 = piVar5 + 2;
      if ((7 < iStack_ec) &&
         (iVar4 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130,
         pbVar9 = pbStack_54, iVar4 != 0)) goto LAB_002312c9;
      pcStack_70 = pcStack_70 + iVar6;
      bVar13 = *pbVar9;
    }
    if (bVar13 == 0) goto LAB_002315d8;
  }
  pbStack_64 = pbVar9 + 1;
  uVar8 = 0;
  abStack_ae[0] = 0;
  pcStack_74 = (char *)0x0;
  pcStack_68 = (char *)0x0;
  pcVar10 = (char *)0xffffffff;
LAB_0023114a:
  uVar17 = (uint)*pbStack_64;
  pbStack_64 = pbStack_64 + 1;
LAB_00231156:
  iVar6 = iStack_ec;
  iVar4 = iStack_e8;
  switch(uVar17) {
  case 0x20:
    goto LAB_00231636;
  default:
    if (uVar17 == 0) goto LAB_002315d8;
    pcStack_80 = (char *)((uint)pcStack_68 & 0x84);
    acStack_e0[0] = (char)uVar17;
    break;
  case 0x23:
    pcStack_68 = (char *)((uint)pcStack_68 | 1);
    goto LAB_0023114a;
  case 0x2a:
    iVar4 = iStack_6c + 4;
    iStack_6c = iVar4;
    iVar6 = iStack_84;
    if ((0x18 < iVar4) && (iStack_6c = 0x24, iVar6 = iStack_88, 0x1c < iVar4)) {
      iStack_6c = iVar4;
    }
    pcStack_74 = *(char **)(iStack_6c + iVar6 + -4);
    if ((int)pcStack_74 < 0) {
      pcStack_74 = (char *)-(int)pcStack_74;
      goto LAB_002317d4;
    }
    goto LAB_0023114a;
  case 0x2b:
    uVar8 = 0x2b;
    abStack_ae[0] = 0x2b;
    goto LAB_0023114a;
  case 0x2d:
LAB_002317d4:
    pcStack_68 = (char *)((uint)pcStack_68 | 4);
    goto LAB_0023114a;
  case 0x2e:
    uVar17 = (uint)*pbStack_64;
    pbStack_64 = pbStack_64 + 1;
    if (uVar17 == 0x2a) {
      iVar4 = iStack_6c + 4;
      iStack_6c = iVar4;
      iVar6 = iStack_84;
      if ((0x18 < iVar4) && (iStack_6c = 0x24, iVar6 = iStack_88, 0x1c < iVar4)) {
        iStack_6c = iVar4;
      }
      iVar6 = *(int *)(iStack_6c + iVar6 + -4);
      pcVar10 = (char *)((uint)((int)pcStack_78 < iVar6) * iVar6 +
                        (uint)((int)pcStack_78 >= iVar6) * (int)pcStack_78);
      goto LAB_0023114a;
    }
    iVar6 = 0;
    if (uVar17 - 0x30 < 10) {
      pcVar10 = (char *)0x0;
      uVar14 = uVar17;
      do {
        uVar17 = (uint)pbStack_64[iVar6];
        iVar6 = iVar6 + 1;
        pcVar10 = (char *)((int)pcVar10 * 10 + uVar14 + -0x30);
        uVar14 = uVar17;
      } while (uVar17 - 0x30 < 10);
    }
    else {
      pcVar10 = (char *)0x0;
    }
    pbStack_64 = pbStack_64 + iVar6;
    if ((int)pcVar10 < (int)pcStack_78) {
      pcVar10 = pcStack_78;
    }
    goto LAB_00231156;
  case 0x30:
    pcStack_68 = (char *)((uint)pcStack_68 | 0x80);
    goto LAB_0023114a;
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    goto LAB_00231716;
  case 0x44:
    pcStack_68 = (char *)((uint)pcStack_68 | 0x10);
  case 100:
  case 0x69:
    if (((uint)pcStack_68 >> 5 & 1) == 0) {
      if (((uint)pcStack_68 >> 4 & 1) == 0) {
        if (((uint)pcStack_68 >> 6 & 1) == 0) {
          iVar12 = iStack_6c + 4;
          iStack_6c = iVar12;
          iVar20 = iStack_84;
          if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
            iStack_6c = iVar12;
          }
          pcVar16 = *(char **)(iStack_6c + iVar20 + -4);
          pcVar18 = (char *)((int)pcVar16 >> 0x1f);
        }
        else {
          iVar12 = iStack_6c + 4;
          iStack_6c = iVar12;
          iVar20 = iStack_84;
          if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
            iStack_6c = iVar12;
          }
          pcVar16 = (char *)(int)*(short *)(iStack_6c + iVar20 + -4);
          pcVar18 = (char *)((int)pcVar16 >> 0x1f);
        }
      }
      else {
        iVar12 = iStack_6c + 4;
        iStack_6c = iVar12;
        iVar20 = iStack_84;
        if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
          iStack_6c = iVar12;
        }
        pcVar16 = *(char **)(iStack_6c + iVar20 + -4);
        pcVar18 = (char *)((int)pcVar16 >> 0x1f);
      }
    }
    else {
      uVar17 = iStack_6c + 7U & 0xfffffff8;
      iStack_6c = uVar17 + 8;
      iVar20 = iStack_84;
      if ((0x10 < (int)uVar17) && (iStack_6c = 0x28, iVar20 = iStack_88, 0x18 < (int)uVar17)) {
        iStack_6c = uVar17 + 8;
      }
      pcVar18 = *(char **)(iStack_6c + iVar20 + -4);
      pcVar16 = *(char **)(iStack_6c + iVar20 + -8);
    }
    pcVar19 = (char *)((uint)pcStack_68 & 0xffffff7f);
    pcStack_68 = pcVar18;
    if (-1 < (int)pcVar10) {
      pcStack_68 = pcVar19;
    }
    if ((0 < (int)pcVar18) || (pcVar18 == (char *)0x0)) {
      pcVar19 = pcVar18;
      if (pcVar16 != (char *)0x0) {
        pcVar19 = (char *)0x1;
      }
      pcStack_a8 = pcStack_98;
      pcStack_a0 = pcVar16;
      if ((((uint)pcVar19 | 1) != 0) || (pcStack_9c = pcVar10, pcVar10 != (char *)0x0)) {
        bVar1 = false;
        if ((pcVar18 == (char *)0x0) && (pcVar16 < (char *)0xa)) {
          bVar1 = true;
        }
        if (bVar1) {
          cStack_b9 = (char)pcVar16 + '0';
          pcStack_a8 = pcStack_a4;
          pcStack_9c = pcVar10;
        }
        else {
LAB_00231b03:
          uVar21 = CONCAT44(pcVar18,pcStack_a0);
          pcStack_a8 = pcStack_98;
          uStack_58 = uVar8;
          pcStack_9c = pcVar10;
          do {
            uVar7 = (undefined4)((ulonglong)uVar21 >> 0x20);
            pcStack_a0 = (char *)uVar21;
            pcStack_a8 = pcStack_a8 + -1;
            cVar3 = FUN_00236540(pcStack_a0,uVar7,10,0);
            *pcStack_a8 = cVar3 + '0';
            uVar21 = __udivdi3(pcStack_a0,uVar7,10,0);
            uVar17 = (uint)((ulonglong)uVar21 >> 0x20);
            if ((char *)uVar21 != (char *)0x0) {
              uVar17 = 1;
            }
            uVar8 = uStack_58;
            pcStack_a0 = (char *)uVar21;
          } while ((uVar17 | 1) != 0);
        }
      }
      pcStack_8c = pcStack_9c;
      pcStack_7c = acStack_b8 + -(int)pcStack_a8;
LAB_00231b75:
      pcVar10 = pcStack_7c;
      if ((int)pcStack_7c < (int)pcStack_8c) {
        pcVar10 = pcStack_8c;
      }
      pcStack_94 = (char *)((uint)pcStack_68 & 0x84);
      uStack_90 = (uint)pcStack_68 & 2;
      pcStack_80 = pcStack_94;
      if (uVar8 != 0) {
        pcStack_80 = pcVar10 + 1;
      }
      pcStack_80 = pcStack_80 + 2;
      if ((((uint)pcStack_68 & 0x84) == 0) &&
         (pcVar18 = pcStack_74 + -(int)pcStack_80, iVar6 = iStack_ec, iVar4 = iStack_e8,
         0 < (int)pcVar18)) goto joined_r0x002311be;
      goto LAB_0023121b;
    }
    uVar8 = 0x2d;
    pcStack_a0 = (char *)-(int)pcVar16;
    uVar17 = (uint)pcVar18 ^ 0xffffffff;
    pcVar18 = pcStack_a0;
    if (pcVar16 == (char *)0x0) {
      pcVar18 = (char *)(uVar17 + 1);
    }
    abStack_ae[0] = 0x2d;
    if (pcStack_a0 == (char *)0x0 && pcVar18 == (char *)0x0) {
      if (pcVar10 == (char *)0x0) {
        pcStack_7c = (char *)0x0;
        pcStack_80 = (char *)0x1;
        pcStack_a8 = pcStack_98;
        if (((uint)pcStack_68 & 2) != 0) {
          pcStack_80 = (char *)0x3;
        }
      }
      else {
        bVar1 = false;
        if ((pcVar18 == (char *)0x0) && (pcStack_a0 < (char *)0xa)) {
          bVar1 = true;
        }
        if (!bVar1) goto LAB_00231b03;
        pcStack_7c = (char *)0x1;
        cStack_b9 = (char)pcStack_a0 + '0';
        pcVar18 = (char *)0x1;
        if (1 < (int)pcVar10) {
          pcVar18 = pcVar10;
        }
        pcStack_80 = pcVar18 + 1;
        pcStack_a8 = pcStack_a4;
        if (((uint)pcStack_68 & 2) != 0) {
          pcStack_80 = pcVar18 + 3;
        }
      }
    }
    else {
      bVar1 = false;
      if ((pcVar18 == (char *)0x0) && (pcStack_a0 < (char *)0xa)) {
        bVar1 = true;
      }
      uVar8 = 0x2d;
      if (!bVar1) goto LAB_00231b03;
      pcStack_7c = (char *)0x1;
      cStack_b9 = (char)pcStack_a0 + '0';
      pcVar18 = (char *)0x1;
      if (1 < (int)pcVar10) {
        pcVar18 = pcVar10;
      }
      pcStack_80 = pcVar18 + 1;
      pcStack_a8 = pcStack_a4;
      if (((uint)pcStack_68 & 2) != 0) {
        pcStack_80 = pcVar18 + 3;
      }
    }
    uStack_90 = (uint)pcStack_68 & 2;
    pcStack_94 = (char *)((uint)pcStack_68 & 0x84);
    pcStack_9c = pcVar10;
    pcStack_8c = pcVar10;
    if (pcStack_94 != (char *)0x0) goto LAB_0023121d;
    pcVar18 = pcStack_74 + -(int)pcStack_80;
    uStack_90 = (uint)pcStack_68 & 2;
    pcStack_94 = (char *)((uint)pcStack_68 & 0x84);
    if ((int)pcVar18 < 1) goto LAB_0023121d;
    goto joined_r0x002311be;
  case 0x4f:
    pcStack_68 = (char *)((uint)pcStack_68 | 0x10);
  case 0x6f:
    if (((uint)pcStack_68 >> 5 & 1) == 0) {
      if (((uint)pcStack_68 >> 4 & 1) == 0) {
        if (((uint)pcStack_68 >> 6 & 1) == 0) {
          iVar12 = iStack_6c + 4;
          iStack_6c = iVar12;
          iVar20 = iStack_84;
          if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
            iStack_6c = iVar12;
          }
          uVar8 = *(uint *)(iStack_6c + iVar20 + -4);
          uVar17 = 0;
        }
        else {
          iVar12 = iStack_6c + 4;
          iStack_6c = iVar12;
          iVar20 = iStack_84;
          if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
            iStack_6c = iVar12;
          }
          uVar8 = (uint)*(ushort *)(iStack_6c + iVar20 + -4);
          uVar17 = 0;
        }
      }
      else {
        iVar12 = iStack_6c + 4;
        iStack_6c = iVar12;
        iVar20 = iStack_84;
        if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
          iStack_6c = iVar12;
        }
        uVar8 = *(uint *)(iStack_6c + iVar20 + -4);
        uVar17 = 0;
      }
    }
    else {
      uVar8 = iStack_6c + 7U & 0xfffffff8;
      iStack_6c = uVar8 + 8;
      iVar20 = iStack_84;
      if ((0x10 < (int)uVar8) && (iStack_6c = 0x28, iVar20 = iStack_88, 0x18 < (int)uVar8)) {
        iStack_6c = uVar8 + 8;
      }
      uVar17 = *(uint *)(iStack_6c + iVar20 + -4);
      uVar8 = *(uint *)(iStack_6c + iVar20 + -8);
    }
    pcVar16 = (char *)((uint)pcStack_68 & 0xffffff7f);
    abStack_ae[0] = 0;
    pcVar18 = pcVar16;
    if (uVar8 != 0) {
      pcVar18 = (char *)0x1;
    }
    pcVar19 = pcStack_98;
    if ((pcVar18 != (char *)0x0 || uVar17 != 0) || (pcVar10 != (char *)0x0)) goto LAB_00231c53;
    pcStack_a8 = pcStack_98;
    pcStack_94 = (char *)((uint)pcStack_68 & 4);
    uStack_90 = 0;
    if (((uint)pcStack_68 & 1) == 0) {
      pcStack_7c = (char *)0x0;
      uVar8 = (uint)pcStack_68 & 4;
      pcStack_9c = pcVar10;
      pcStack_8c = pcVar10;
      pcStack_80 = pcVar16;
      pcStack_68 = pcVar16;
      if (uVar8 != 0) goto LAB_00231244;
      pcVar18 = pcStack_74 + -(int)pcVar16;
    }
    else {
      pcStack_7c = (char *)0x1;
      cStack_b9 = '0';
      pcStack_80 = (char *)0x3;
      pcStack_a8 = pcStack_a4;
      uVar8 = (uint)pcStack_68 & 4;
      pcStack_9c = pcVar10;
      pcStack_8c = pcVar10;
      pcStack_68 = pcVar16;
      if (uVar8 != 0) goto LAB_00231244;
      pcVar18 = pcStack_74 + -3;
    }
joined_r0x0023245a:
    uStack_90 = 0;
    abStack_ae[0] = 0;
    pcStack_9c = pcVar10;
    pcStack_68 = pcVar16;
    goto joined_r0x0023224b;
  case 0x55:
    pcStack_68 = (char *)((uint)pcStack_68 | 0x10);
  case 0x75:
    if (((uint)pcStack_68 >> 5 & 1) == 0) {
      if (((uint)pcStack_68 >> 4 & 1) == 0) {
        if (((uint)pcStack_68 >> 6 & 1) == 0) {
          iVar12 = iStack_6c + 4;
          iStack_6c = iVar12;
          iVar20 = iStack_84;
          if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
            iStack_6c = iVar12;
          }
          pcStack_a0 = *(char **)(iStack_6c + iVar20 + -4);
          pcVar18 = (char *)0x0;
        }
        else {
          iVar12 = iStack_6c + 4;
          iStack_6c = iVar12;
          iVar20 = iStack_84;
          if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
            iStack_6c = iVar12;
          }
          pcStack_a0 = (char *)(uint)*(ushort *)(iStack_6c + iVar20 + -4);
          pcVar18 = (char *)0x0;
        }
      }
      else {
        iVar12 = iStack_6c + 4;
        iStack_6c = iVar12;
        iVar20 = iStack_84;
        if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
          iStack_6c = iVar12;
        }
        pcStack_a0 = *(char **)(iStack_6c + iVar20 + -4);
        pcVar18 = (char *)0x0;
      }
    }
    else {
      uVar8 = iStack_6c + 7U & 0xfffffff8;
      iStack_6c = uVar8 + 8;
      iVar20 = iStack_84;
      if ((0x10 < (int)uVar8) && (iStack_6c = 0x28, iVar20 = iStack_88, 0x18 < (int)uVar8)) {
        iStack_6c = uVar8 + 8;
      }
      pcVar18 = *(char **)(iStack_6c + iVar20 + -4);
      pcStack_a0 = *(char **)(iStack_6c + iVar20 + -8);
    }
    pcStack_a8 = pcStack_98;
    pcVar16 = pcStack_98;
    if (pcVar18 != (char *)0x0) {
      pcVar16 = (char *)0x1;
    }
    pcVar19 = (char *)((uint)pcStack_68 & 0xffffff7f);
    abStack_ae[0] = 0;
    pcStack_68 = (char *)0x0;
    if (-1 < (int)pcVar10) {
      pcStack_68 = pcVar19;
    }
    if ((((uint)pcVar16 | 1) == 0) && (pcVar10 == (char *)0x0)) {
      pcStack_7c = (char *)0x0;
      pcStack_94 = (char *)((uint)pcStack_68 & 0x84);
      uStack_90 = 0;
      pcStack_80 = (char *)0x2;
      pcStack_9c = pcVar10;
      pcStack_8c = pcVar10;
      if (((uint)pcStack_68 & 0x84) == 0) {
        pcVar18 = pcStack_74 + -2;
        pcVar16 = pcStack_68;
        goto joined_r0x0023245a;
      }
      goto LAB_00231244;
    }
    bVar1 = false;
    if ((pcVar18 == (char *)0x0) && (pcStack_a0 < (char *)0xa)) {
      bVar1 = true;
    }
    uVar8 = 0;
    pcStack_8c = pcVar10;
    if (!bVar1) goto LAB_00231b03;
    pcStack_a8 = pcStack_a4;
    pcStack_7c = (char *)0x1;
    pcStack_94 = (char *)((uint)pcStack_68 & 0x84);
    pcStack_80 = (char *)0x1;
    if (1 < (int)pcVar10) {
      pcStack_80 = pcVar10;
    }
    uStack_90 = 0;
    cStack_b9 = (char)pcStack_a0 + '0';
    pcStack_80 = pcStack_80 + 2;
    pcStack_9c = pcVar10;
    if (((uint)pcStack_68 & 0x84) != 0) goto LAB_00231244;
    pcVar18 = pcStack_74 + -(int)pcStack_80;
joined_r0x0023224b:
    abStack_ae[0] = 0;
    pcStack_9c = pcVar10;
    goto joined_r0x0023224b;
  case 0x58:
    pcVar18 = "0123456789ABCDEF";
    goto LAB_00231651;
  case 99:
    iVar12 = iStack_6c + 4;
    iStack_6c = iVar12;
    iVar20 = iStack_84;
    if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
      iStack_6c = iVar12;
    }
    pcStack_80 = *(char **)(iStack_6c + iVar20 + -4);
    acStack_e0[0] = (char)pcStack_80;
    break;
  case 0x68:
    pcStack_68 = (char *)((uint)pcStack_68 | 0x40);
    goto LAB_0023114a;
  case 0x6c:
    if (*pbStack_64 == 0x6c) {
      pcStack_68 = (char *)((uint)pcStack_68 | 0x20);
      pbStack_64 = pbStack_64 + 1;
    }
    else {
      pcStack_68 = (char *)((uint)pcStack_68 | 0x10);
    }
    goto LAB_0023114a;
  case 0x6e:
    if (((uint)pcStack_68 >> 5 & 1) == 0) {
      if (((uint)pcStack_68 >> 4 & 1) == 0) {
        if (((uint)pcStack_68 >> 6 & 1) == 0) {
          iVar4 = iStack_6c + 4;
          iStack_6c = iVar4;
          iVar6 = iStack_84;
          if ((0x18 < iVar4) && (iStack_6c = 0x24, iVar6 = iStack_88, 0x1c < iVar4)) {
            iStack_6c = iVar4;
          }
          **(int **)(iStack_6c + iVar6 + -4) = (int)pcStack_70;
        }
        else {
          iVar4 = iStack_6c + 4;
          iStack_6c = iVar4;
          iVar6 = iStack_84;
          if ((0x18 < iVar4) && (iStack_6c = 0x24, iVar6 = iStack_88, 0x1c < iVar4)) {
            iStack_6c = iVar4;
          }
          ae_s16i_n(pcStack_70,*(undefined4 *)(iStack_6c + iVar6 + -4),0);
        }
      }
      else {
        iVar4 = iStack_6c + 4;
        iStack_6c = iVar4;
        iVar6 = iStack_84;
        if ((0x18 < iVar4) && (iStack_6c = 0x24, iVar6 = iStack_88, 0x1c < iVar4)) {
          iStack_6c = iVar4;
        }
        **(int **)(iStack_6c + iVar6 + -4) = (int)pcStack_70;
      }
    }
    else {
      iVar4 = iStack_6c + 4;
      iStack_6c = iVar4;
      iVar6 = iStack_84;
      if ((0x18 < iVar4) && (iStack_6c = 0x24, iVar6 = iStack_88, 0x1c < iVar4)) {
        iStack_6c = iVar4;
      }
      piVar11 = *(int **)(iStack_6c + iVar6 + -4);
      *piVar11 = (int)pcStack_70;
      piVar11[1] = (int)pcStack_70 >> 0x1f;
    }
    goto LAB_002310cd;
  case 0x70:
    iVar12 = iStack_6c + 4;
    iStack_6c = iVar12;
    iVar20 = iStack_84;
    if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
      iStack_6c = iVar12;
    }
    pcStack_a8 = pcStack_98;
    pcVar16 = (char *)((uint)pcStack_68 & 0xffffff7f | 2);
    iVar12 = iStack_6c + iVar20 + -0x100;
    uVar8 = *(uint *)(iStack_6c + iVar20 + -4);
    uStack_b0 = 0x30;
    abStack_ae[0] = 0;
    if (uVar8 != 0) {
      iVar12 = 1;
    }
    cStack_af = 'x';
    uVar14 = 0;
    if ((iVar12 != 0) || (pcVar10 != (char *)0x0)) {
      pcVar18 = "0123456789abcdef";
      pcStack_68 = pcVar16;
      goto LAB_00231967;
    }
    pcStack_7c = (char *)0x0;
    pcStack_94 = (char *)((uint)pcStack_68 & 4);
    uStack_90 = 2;
    pcStack_80 = (char *)0x2;
    uVar8 = (uint)pcStack_68 & 4;
    pcStack_9c = pcVar10;
    pcStack_8c = pcVar10;
    pcStack_68 = pcVar16;
    if (uVar8 == 0) {
      pcVar18 = pcStack_74 + -2;
      goto joined_r0x0023224b;
    }
    goto LAB_00231244;
  case 0x71:
    pcStack_68 = (char *)((uint)pcStack_68 | 0x20);
    goto LAB_0023114a;
  case 0x73:
    iVar12 = iStack_6c + 4;
    iStack_6c = iVar12;
    iVar20 = iStack_84;
    if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
      iStack_6c = iVar12;
    }
    pcStack_a8 = *(char **)(iStack_6c + iVar20 + -4);
    abStack_ae[0] = 0;
    if (pcStack_a8 != (char *)0x0) {
      if ((int)pcVar10 < 0) {
        pcStack_9c = pcVar10;
        pcStack_7c = (char *)strlen(pcStack_a8);
      }
      else {
        pcStack_9c = pcVar10;
        iVar6 = memchr(pcStack_a8,0);
        iVar4 = iVar6 - (int)pcStack_a8;
        pcStack_7c = (char *)((uint)((int)pcStack_9c < iVar4) * (int)pcStack_9c +
                             (uint)((int)pcStack_9c >= iVar4) * iVar4);
        if (iVar6 == 0) {
          pcStack_7c = pcStack_9c;
        }
      }
      pcStack_8c = (char *)0x0;
      uVar8 = (uint)abStack_ae[0];
      goto LAB_00231b75;
    }
    if ((char *)0x6 < pcVar10) {
      pcVar10 = (char *)0x6;
    }
    uStack_90 = 0;
    pcStack_94 = (char *)((uint)pcStack_68 & 0x84);
    pcStack_7c = pcVar10;
    if ((((uint)pcStack_68 & 0x84) != 0) ||
       (pcVar18 = pcStack_74 + -(int)pcStack_94, (int)pcVar18 < 1)) {
      pcStack_a8 = "(null)";
      pcStack_8c = (char *)0x0;
      pcStack_80 = pcStack_94;
      goto LAB_00231244;
    }
    pcStack_a8 = "(null)";
    pcStack_8c = (char *)0x0;
    pcStack_80 = pcStack_94;
    goto joined_r0x002311be;
  case 0x78:
    pcVar18 = "0123456789abcdef";
LAB_00231651:
    if (((uint)pcStack_68 >> 5 & 1) == 0) {
      if (((uint)pcStack_68 >> 4 & 1) == 0) {
        if (((uint)pcStack_68 >> 6 & 1) == 0) {
          iVar12 = iStack_6c + 4;
          iStack_6c = iVar12;
          iVar20 = iStack_84;
          if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
            iStack_6c = iVar12;
          }
          uVar8 = *(uint *)(iStack_6c + iVar20 + -4);
          uVar14 = 0;
          uVar15 = uVar8;
        }
        else {
          iVar12 = iStack_6c + 4;
          iStack_6c = iVar12;
          iVar20 = iStack_84;
          if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
            iStack_6c = iVar12;
          }
          uVar8 = (uint)*(ushort *)(iStack_6c + iVar20 + -4);
          uVar14 = 0;
          uVar15 = uVar8;
        }
      }
      else {
        iVar12 = iStack_6c + 4;
        iStack_6c = iVar12;
        iVar20 = iStack_84;
        if ((0x18 < iVar12) && (iStack_6c = 0x24, iVar20 = iStack_88, 0x1c < iVar12)) {
          iStack_6c = iVar12;
        }
        uVar8 = *(uint *)(iStack_6c + iVar20 + -4);
        uVar14 = 0;
        uVar15 = uVar8;
      }
    }
    else {
      uVar8 = iStack_6c + 7U & 0xfffffff8;
      iStack_6c = uVar8 + 8;
      iVar20 = iStack_84;
      if ((0x10 < (int)uVar8) && (iStack_6c = 0x28, iVar20 = iStack_88, 0x18 < (int)uVar8)) {
        iStack_6c = uVar8 + 8;
      }
      uVar14 = *(uint *)(iStack_6c + iVar20 + -4);
      uVar8 = *(uint *)(iStack_6c + iVar20 + -8);
      uVar15 = uVar14;
    }
    if (((uint)pcStack_68 & 1) != 0) {
      if (uVar14 != 0) {
        uVar15 = 1;
      }
      if (uVar8 != 0 || uVar15 != 0) {
        uStack_b0 = 0x30;
        pcStack_68 = (char *)((uint)pcStack_68 | 2);
        cStack_af = (char)uVar17;
      }
    }
    pcStack_68 = (char *)((uint)pcStack_68 & 0xffffff7f);
    uStack_ac = uVar14;
LAB_00231967:
    pcStack_a8 = pcStack_98;
    abStack_ae[0] = 0;
    pcStack_9c = pcVar10;
    do {
      uVar17 = uVar8 & 0xf;
      uVar8 = (uint)(CONCAT44(uVar14,uVar8) >> 4);
      pcVar16 = pcStack_a8 + -1;
      uVar14 = uVar14 >> 4;
      pcVar10 = pcVar16;
      if (uVar14 != 0) {
        pcVar10 = (char *)0x1;
      }
      pcVar19 = pcVar18 + uVar17;
      cVar3 = *pcVar19;
      if (uVar8 != 0) {
        pcVar19 = (char *)0x1;
      }
      *pcVar16 = cVar3;
      pcStack_a8 = pcVar16;
    } while (pcVar19 != (char *)0x0 || pcVar10 != (char *)0x0);
    pcStack_7c = acStack_b8 + -(int)pcVar16;
    pcStack_94 = (char *)((uint)pcStack_68 & 0x84);
    pcStack_80 = pcStack_7c;
    if ((int)pcStack_7c < (int)pcStack_9c) {
      pcStack_80 = pcStack_9c;
    }
    uStack_90 = (uint)pcStack_68 & 2;
    pcStack_80 = pcStack_80 + 2;
    pcStack_8c = pcStack_9c;
    if (((uint)pcStack_68 & 0x84) == 0) {
      pcVar18 = pcStack_74 + -(int)pcStack_80;
      goto joined_r0x0023224b;
    }
    goto LAB_00231244;
  }
  if ((((uint)pcStack_68 & 0x84) != 0) ||
     (pcVar18 = pcStack_74 + -(int)pcStack_80, (int)pcVar18 < 1)) {
    pcStack_94 = (char *)((uint)pcStack_68 & 0x84);
    pcStack_7c = (char *)0x1;
    uStack_90 = 0;
    abStack_ae[0] = 0;
    pcStack_8c = (char *)0x0;
    pcStack_a8 = acStack_e0;
    goto LAB_00231244;
  }
  pcStack_94 = (char *)((uint)pcStack_68 & 0x84);
  uStack_90 = 0;
  pcStack_7c = (char *)0x1;
  abStack_ae[0] = 0;
  pcStack_a8 = acStack_e0;
  pcStack_8c = (char *)0x0;
  goto joined_r0x002311be;
LAB_00231c53:
  do {
    pcVar18 = pcVar19;
    uVar14 = uVar8 & 7;
    pcVar19 = pcVar18 + -1;
    uVar15 = uVar17 >> 3;
    uVar8 = (uint)(CONCAT44(uVar17,uVar8) >> 3);
    iVar12 = uVar14 + 0x30;
    iVar20 = iVar12;
    if (uVar8 != 0) {
      iVar20 = 1;
    }
    *pcVar19 = (char)iVar12;
    uVar17 = uVar15;
  } while (iVar20 != 0 || uVar15 != 0);
  pcStack_a8 = pcVar19;
  if ((((uint)pcStack_68 & 1) != 0) && (iVar12 != 0x30)) {
    pcVar18 = pcVar18 + -2;
    *pcVar18 = '0';
    pcStack_a8 = pcVar18;
  }
  pcStack_94 = (char *)((uint)pcStack_68 & 4);
  pcStack_7c = acStack_b8 + -(int)pcStack_a8;
  pcStack_80 = pcStack_7c;
  if ((int)pcStack_7c < (int)pcVar10) {
    pcStack_80 = pcVar10;
  }
  uStack_90 = 0;
  pcStack_80 = pcStack_80 + 2;
  uVar8 = (uint)pcStack_68 & 4;
  pcStack_9c = pcVar10;
  pcStack_8c = pcVar10;
  pcStack_68 = pcVar16;
  if (uVar8 == 0) {
    pcVar18 = pcStack_74 + -(int)pcStack_80;
joined_r0x0023224b:
    pcStack_8c = pcStack_9c;
    if (0 < (int)pcVar18) {
joined_r0x002311be:
      do {
        if ((int)pcVar18 < 0x11) goto LAB_002311fa;
        piVar5[1] = 0x10;
        *piVar5 = (int)&PTR_DAT_00206160;
        iStack_e8 = iVar4 + 0x10;
        iStack_ec = iVar6 + 1;
        piVar5 = piVar5 + 2;
        if ((7 < iStack_ec) &&
           (iVar6 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar6 != 0))
        goto LAB_002312c9;
        pcVar18 = pcVar18 + -0x10;
        iVar6 = iStack_ec;
        iVar4 = iStack_e8;
      } while( true );
    }
  }
  goto LAB_00231244;
LAB_00231716:
  pcStack_74 = (char *)0x0;
  uVar14 = uVar17;
  do {
    uVar17 = (uint)*pbStack_64;
    pbStack_64 = pbStack_64 + 1;
    pcStack_74 = (char *)((int)pcStack_74 * 10 + uVar14 + -0x30);
    uVar14 = uVar17;
  } while (uVar17 - 0x30 < 10);
  goto LAB_00231156;
LAB_002311fa:
  piVar5[1] = (int)pcVar18;
  *piVar5 = (int)&PTR_DAT_00206160;
  iStack_e8 = iVar4 + (int)pcVar18;
  iStack_ec = iVar6 + 1;
  piVar5 = piVar5 + 2;
  if ((7 < iStack_ec) &&
     (iVar6 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar6 != 0))
  goto LAB_002312c9;
  uVar8 = (uint)abStack_ae[0];
LAB_0023121b:
  if (uVar8 != 0) {
LAB_0023121d:
    piVar5[1] = 1;
    *piVar5 = (int)abStack_ae;
    iStack_e8 = iStack_e8 + 1;
    iStack_ec = iStack_ec + 1;
    piVar5 = piVar5 + 2;
    if ((7 < iStack_ec) &&
       (iVar6 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar6 != 0))
    goto LAB_002312c9;
  }
LAB_00231244:
  if (uStack_90 != 0) {
    piVar5[1] = 2;
    *piVar5 = (int)&uStack_b0;
    iStack_e8 = iStack_e8 + 2;
    iStack_ec = iStack_ec + 1;
    piVar5 = piVar5 + 2;
    if ((7 < iStack_ec) &&
       (iVar6 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar6 != 0))
    goto LAB_002312c9;
  }
  if ((pcStack_94 == (char *)0x80) &&
     (iVar6 = (int)pcStack_74 - (int)pcStack_80, iVar4 = iStack_ec, iVar20 = iStack_e8, 0 < iVar6))
  {
    for (; 0x10 < iVar6; iVar6 = iVar6 + -0x10) {
      piVar5[1] = 0x10;
      *piVar5 = (int)&DAT_00206150;
      iStack_e8 = iVar20 + 0x10;
      iStack_ec = iVar4 + 1;
      piVar5 = piVar5 + 2;
      if ((7 < iStack_ec) &&
         (iVar4 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar4 != 0))
      goto LAB_002312c9;
      iVar4 = iStack_ec;
      iVar20 = iStack_e8;
    }
    piVar5[1] = iVar6;
    *piVar5 = (int)&DAT_00206150;
    iStack_e8 = iVar20 + iVar6;
    iStack_ec = iVar4 + 1;
    piVar5 = piVar5 + 2;
    if ((7 < iStack_ec) &&
       (iVar6 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar6 != 0))
    goto LAB_002312c9;
  }
  iVar6 = (int)pcStack_8c - (int)pcStack_7c;
  iVar4 = iStack_ec;
  iVar20 = iStack_e8;
  if (0 < iVar6) {
    for (; 0x10 < iVar6; iVar6 = iVar6 + -0x10) {
      piVar5[1] = 0x10;
      *piVar5 = (int)&DAT_00206150;
      iStack_e8 = iVar20 + 0x10;
      iStack_ec = iVar4 + 1;
      piVar5 = piVar5 + 2;
      if ((7 < iStack_ec) &&
         (iVar4 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar4 != 0))
      goto LAB_002312c9;
      iVar4 = iStack_ec;
      iVar20 = iStack_e8;
    }
    piVar5[1] = iVar6;
    *piVar5 = (int)&DAT_00206150;
    iStack_e8 = iVar20 + iVar6;
    iStack_ec = iVar4 + 1;
    piVar5 = piVar5 + 2;
    if ((7 < iStack_ec) &&
       (iVar6 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar6 != 0))
    goto LAB_002312c9;
  }
  pcVar10 = pcStack_7c;
  piVar5[1] = (int)pcStack_7c;
  *piVar5 = (int)pcStack_a8;
  iStack_e8 = iStack_e8 + (int)pcVar10;
  iStack_ec = iStack_ec + 1;
  piVar5 = piVar5 + 2;
  if ((7 < iStack_ec) &&
     (iVar6 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar6 != 0))
  goto LAB_002312c9;
  if ((((uint)pcStack_68 & 4) != 0) &&
     (iVar6 = (int)pcStack_74 - (int)pcStack_80, iVar4 = iStack_ec, iVar20 = iStack_e8, 0 < iVar6))
  {
    for (; 0x10 < iVar6; iVar6 = iVar6 + -0x10) {
      piVar5[1] = 0x10;
      *piVar5 = (int)&PTR_DAT_00206160;
      iStack_e8 = iVar20 + 0x10;
      iStack_ec = iVar4 + 1;
      piVar5 = piVar5 + 2;
      if ((7 < iStack_ec) &&
         (iVar4 = __sprint_r(iStack_60,param_2,&puStack_f0), piVar5 = aiStack_130, iVar4 != 0))
      goto LAB_002312c9;
      iVar4 = iStack_ec;
      iVar20 = iStack_e8;
    }
    piVar5[1] = iVar6;
    *piVar5 = (int)&PTR_DAT_00206160;
    iStack_e8 = iVar20 + iVar6;
    iStack_ec = iVar4 + 1;
    if ((7 < iStack_ec) && (iVar6 = __sprint_r(iStack_60,param_2,&puStack_f0), iVar6 != 0))
    goto LAB_002312c9;
  }
  pcVar10 = pcStack_80;
  if ((int)pcStack_80 < (int)pcStack_74) {
    pcVar10 = pcStack_74;
  }
  pcStack_70 = pcStack_70 + (int)pcVar10;
  if ((iStack_e8 != 0) && (iVar6 = __sprint_r(iStack_60,param_2,&puStack_f0), iVar6 != 0))
  goto LAB_002312c9;
  iStack_ec = 0;
  piVar5 = aiStack_130;
  goto LAB_002310cd;
LAB_00231636:
  if (uVar8 == 0) {
    uVar8 = 0x20;
  }
  abStack_ae[0] = (byte)uVar8;
  goto LAB_0023114a;
}


// ===== __swhatbuf_r @ 00232470 (44 bytes)

/* newlib makebuf.c [inference] */

undefined4 __swhatbuf_r(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_60 [4];
  uint uStack_5c;
  
  iVar1 = FUN_00233200(param_1,param_2,auStack_60);
  if ((-1 < iVar1) && ((uStack_5c & (uint)&DAT_0000f000) == 0x2000)) {
    return 1;
  }
  return 0;
}


// ===== _calloc_r @ 002324a0 (112 bytes)

/* newlib: _malloc_r then memset; called by _Balloc [inference] */

undefined4 * _calloc_r(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar1 = (undefined4 *)_malloc_r(param_1,param_2 * param_3);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  uVar3 = (puVar1[-1] & 0xfffffffc) - 4;
  if (uVar3 < 0x25) {
    puVar2 = puVar1;
    if (0x13 < uVar3) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar2 = puVar1 + 2;
      if (0x1b < uVar3) {
        puVar1[2] = 0;
        puVar1[3] = 0;
        puVar2 = puVar1 + 4;
        if (0x23 < uVar3) {
          puVar1[4] = 0;
          puVar1[5] = 0;
          puVar1[6] = 0;
          puVar1[7] = 0;
          puVar1[8] = 0;
          return puVar1;
        }
      }
    }
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    return puVar1;
  }
  memset(puVar1,0);
  return puVar1;
}


// ===== _fclose_r @ 00232520 (146 bytes)

/* newlib fclose.c: _fflush_r, _free_r, sfp locks; fclose follows inside this listing entry
   (0x2325D0, used by _cleanup_r) [inference] */

undefined4 _fclose_r(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 != 0) {
    if ((param_1 != 0) && (*(int *)(param_1 + 0x38) == 0)) {
      __sinit(param_1);
    }
    if (*(short *)(param_2 + 0xc) != 0) {
      uVar1 = _fflush_r(param_1,param_2);
      if ((*(code **)(param_2 + 0x2c) != (code *)0x0) &&
         (iVar2 = (**(code **)(param_2 + 0x2c))(param_1,*(undefined4 *)(param_2 + 0x1c)), iVar2 < 0)
         ) {
        uVar1 = 0xffffffff;
      }
      if ((*(ushort *)(param_2 + 0xc) & 0x80) != 0) {
        _free_r(param_1,*(undefined4 *)(param_2 + 0x10));
      }
      if (*(int *)(param_2 + 0x30) != 0) {
        if (*(int *)(param_2 + 0x30) != param_2 + 0x40) {
          _free_r(param_1);
        }
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      if (*(int *)(param_2 + 0x44) != 0) {
        _free_r(param_1);
        *(undefined4 *)(param_2 + 0x44) = 0;
      }
      __sfp_lock_acquire();
      *(undefined2 *)(param_2 + 0xc) = 0;
      __sfp_lock_release();
      return uVar1;
    }
  }
  return 0;
}


// ===== __fputwc @ 002325f0 (245 bytes)

/* newlib fputwc.c: __locale_mb_cur_max, _wcrtomb_r, __swbuf_r [inference] */

uint __fputwc(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  bool bVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  undefined1 local_30 [48];
  
  puVar4 = local_30;
  if ((*(ushort *)(param_3 + 3) & 0x2000) == 0) {
    *(ushort *)(param_3 + 3) = *(ushort *)(param_3 + 3) | 0x2000;
    param_3[0x19] = param_3[0x19] | (uint)&DAT_00002000;
  }
  iVar3 = __locale_mb_cur_max();
  if (((iVar3 == 1) && (param_2 != 0)) && (iVar3 = 1, param_2 < 0x100)) {
    local_30[0] = (char)param_2;
  }
  else {
    iVar3 = _wcrtomb_r(param_1,local_30,param_2,param_3 + 0x17);
    if (iVar3 == -1) {
      *(ushort *)(param_3 + 3) = *(ushort *)(param_3 + 3) | 0x40;
      return 0xffffffff;
    }
    if (iVar3 == 0) {
      return param_2;
    }
  }
  do {
    iVar6 = param_3[2] + -1;
    param_3[2] = iVar6;
    uVar1 = *puVar4;
    if (iVar6 < 0) {
      if (iVar6 < (int)param_3[6]) {
        iVar6 = __swbuf_r(param_1,uVar1,param_3);
        bVar2 = iVar6 == -1;
      }
      else {
        *(undefined1 *)*param_3 = uVar1;
        uVar5 = (uint)*(byte *)*param_3;
        if (uVar5 == 10) {
          iVar6 = __swbuf_r(param_1,10,param_3);
          bVar2 = iVar6 == -1;
        }
        else {
          *param_3 = (byte *)*param_3 + 1;
          bVar2 = uVar5 == 0xffffffff;
        }
      }
      if (bVar2) {
        return 0xffffffff;
      }
    }
    else {
      *(undefined1 *)*param_3 = uVar1;
      iVar6 = *(byte *)*param_3 + 1;
      *param_3 = (byte *)*param_3 + 1;
      if (iVar6 == 0) {
        iVar6 = 1;
      }
      if (iVar6 != 0) {
        return 0xffffffff;
      }
    }
    puVar4 = puVar4 + 1;
    if (puVar4 == local_30 + iVar3) {
      return param_2;
    }
  } while( true );
}


// ===== fputwc @ 00232700 (40 bytes)

/* newlib fputwc.c: _impure_ptr, __sinit, __fputwc [inference] */

undefined4 fputwc(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((PTR_DAT_00237f00 != (undefined *)0x0) && (*(int *)(PTR_DAT_00237f00 + 0x38) == 0)) {
    __sinit();
  }
  uVar1 = __fputwc(PTR_DAT_00237f00,param_1,param_2);
  return uVar1;
}


// ===== __sfvwrite_r @ 00232730 (895 bytes)

/* newlib fvwrite.c: __swsetup_r, _realloc_r, memchr, _fflush_r [inference] */

undefined4 __sfvwrite_r(undefined4 *param_1,uint *param_2,undefined4 *param_3)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint local_40;
  
  if (param_3[2] != 0) {
    uVar5 = (uint)(short)param_2[3];
    if (((uVar5 >> 3 & 1) == 0) || (param_2[4] == 0)) {
      iVar3 = __swsetup_r(param_1,param_2);
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      uVar5 = (uint)(short)param_2[3];
    }
    piVar8 = (int *)*param_3;
    if ((uVar5 >> 1 & 1) == 0) {
      if ((uVar5 & 1) != 0) {
        bVar2 = false;
        uVar7 = 0;
        iVar3 = 0;
        uVar5 = 0;
LAB_0023295e:
        if (uVar5 != 0) {
          if (!bVar2) goto LAB_00232977;
          goto LAB_0023299a;
        }
        do {
          iVar9 = 0;
          piVar4 = piVar8;
          do {
            uVar5 = piVar4[1];
            iVar9 = iVar9 + 1;
            iVar3 = *piVar4;
            piVar4 = piVar4 + 2;
          } while (uVar5 == 0);
          piVar8 = piVar8 + iVar9 * 2;
LAB_00232977:
          do {
            memchr(iVar3,10,uVar5);
            uVar7 = uVar5 + 1;
            bVar2 = true;
LAB_0023299a:
            uVar10 = *param_2;
            uVar11 = param_2[2] + param_2[5];
            local_40 = uVar7;
            if (uVar5 < uVar7) {
              local_40 = uVar5;
            }
            if ((param_2[4] < uVar10) && ((int)uVar11 < (int)local_40)) {
              memmove(uVar10,iVar3,uVar11);
              *param_2 = uVar11 + *param_2;
              iVar9 = _fflush_r(param_1,param_2);
              local_40 = uVar11;
              if (iVar9 != 0) goto LAB_00232919;
            }
            else if ((int)local_40 < (int)param_2[5]) {
              memmove(uVar10,iVar3);
              param_2[2] = param_2[2] - local_40;
              *param_2 = *param_2 + local_40;
            }
            else {
              local_40 = (*(code *)param_2[9])(param_1,param_2[7],iVar3);
              if ((int)local_40 < 1) goto LAB_00232919;
            }
            uVar7 = uVar7 - local_40;
            if (uVar7 != 0) {
              iVar9 = param_3[2];
              param_3[2] = iVar9 - local_40;
              iVar3 = iVar3 + local_40;
              uVar5 = uVar5 - local_40;
              if (iVar9 - local_40 == 0) {
                return 0;
              }
              goto LAB_0023295e;
            }
            iVar9 = _fflush_r(param_1,param_2);
            if (iVar9 != 0) goto LAB_00232919;
            iVar9 = param_3[2];
            param_3[2] = iVar9 - local_40;
            iVar3 = iVar3 + local_40;
            uVar5 = uVar5 - local_40;
            if (iVar9 - local_40 == 0) {
              return 0;
            }
          } while (uVar5 != 0);
        } while( true );
      }
      iVar3 = 0;
      uVar5 = 0;
      do {
        iVar9 = 0;
        piVar4 = piVar8;
        while (uVar5 == 0) {
          puVar1 = (uint *)(piVar4 + 1);
          iVar9 = iVar9 + 1;
          iVar3 = *piVar4;
          piVar4 = piVar4 + 2;
          uVar5 = *puVar1;
        }
        uVar7 = (uint)(short)param_2[3];
        piVar8 = piVar8 + iVar9 * 2;
        local_40 = param_2[2];
        if ((uVar7 >> 9 & 1) == 0) {
          uVar7 = *param_2;
          if ((param_2[4] < uVar7) && (local_40 < uVar5)) {
            memmove(uVar7,iVar3,local_40);
            *param_2 = local_40 + *param_2;
            iVar9 = _fflush_r(param_1,param_2);
            if (iVar9 != 0) goto LAB_00232919;
          }
          else if (uVar5 < param_2[5]) {
            memmove(uVar7,iVar3,uVar5);
            param_2[2] = param_2[2] - uVar5;
            *param_2 = *param_2 + uVar5;
            local_40 = uVar5;
          }
          else {
            local_40 = (*(code *)param_2[9])(param_1,param_2[7],iVar3);
            if ((int)local_40 < 1) goto LAB_00232919;
          }
        }
        else {
          if (uVar5 < local_40) {
            uVar10 = *param_2;
          }
          else {
            uVar10 = *param_2;
            if ((uVar7 & 0x480) != 0) {
              iVar6 = uVar10 - param_2[4];
              iVar9 = iVar6;
              if (-1 < (int)(param_2[5] * 3)) {
                iVar9 = param_2[5] * 3;
              }
              uVar10 = iVar9 >> 1;
              uVar11 = iVar6 + uVar5 + 1;
              uVar11 = (uVar11 < uVar10) * uVar10 + (uVar11 >= uVar10) * uVar11;
              if ((uVar7 >> 10 & 1) == 0) {
                uVar10 = _realloc_r(param_1,param_2[4],uVar11);
                if (uVar10 == 0) {
                  _free_r(param_1,param_2[4]);
                  uVar5 = param_2[3];
                  *param_1 = 0xc;
                  *(ushort *)(param_2 + 3) = (ushort)uVar5 & 0xff7f | 0x40;
                  return 0xffffffff;
                }
              }
              else {
                uVar10 = _malloc_r(param_1,uVar11);
                if (uVar10 == 0) {
                  uVar5 = param_2[3];
                  *param_1 = 0xc;
                  *(ushort *)(param_2 + 3) = (ushort)uVar5 | 0x40;
                  return 0xffffffff;
                }
                memcpy(uVar10,param_2[4],iVar6);
                *(ushort *)(param_2 + 3) = (ushort)param_2[3] & 0xfb7f | 0x80;
              }
              param_2[4] = uVar10;
              param_2[5] = uVar11;
              param_2[2] = uVar11 - iVar6;
              uVar10 = iVar6 + uVar10;
              *param_2 = uVar10;
              local_40 = uVar5;
            }
          }
          iVar9 = (uVar5 < local_40) * uVar5 + (uVar5 >= local_40) * local_40;
          memmove(uVar10,iVar3);
          param_2[2] = param_2[2] - iVar9;
          *param_2 = iVar9 + *param_2;
          local_40 = uVar5;
        }
        iVar9 = param_3[2];
        param_3[2] = iVar9 - local_40;
        iVar3 = iVar3 + local_40;
        uVar5 = uVar5 - local_40;
      } while (iVar9 - local_40 != 0);
    }
    else {
      iVar3 = 0;
      uVar5 = 0;
      do {
        iVar9 = 0;
        piVar4 = piVar8;
        while (uVar5 == 0) {
          puVar1 = (uint *)(piVar4 + 1);
          iVar9 = iVar9 + 1;
          iVar3 = *piVar4;
          piVar4 = piVar4 + 2;
          uVar5 = *puVar1;
        }
        piVar8 = piVar8 + iVar9 * 2;
        uVar7 = uVar5;
        if (0x400 < uVar5) {
          uVar7 = 0x400;
        }
        iVar9 = (*(code *)param_2[9])(param_1,param_2[7],iVar3,uVar7);
        if (iVar9 < 1) {
LAB_00232919:
          *(ushort *)(param_2 + 3) = (ushort)param_2[3] | 0x40;
          return 0xffffffff;
        }
        iVar6 = param_3[2];
        param_3[2] = iVar6 - iVar9;
        iVar3 = iVar3 + iVar9;
        uVar5 = uVar5 - iVar9;
      } while (iVar6 - iVar9 != 0);
    }
  }
  return 0;
}


// ===== _realloc_r @ 00232af0 (1270 bytes)

/* newlib mallocr.c: malloc lock, memmove, _free_r [inference] */

int * _realloc_r(undefined4 *param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  uint uStack_28;
  
  if (param_2 == (int *)0x0) {
    piVar1 = (int *)_malloc_r(param_1,param_3);
    return piVar1;
  }
  __malloc_lock(param_1);
  uVar7 = param_2[-1];
  piVar1 = param_2 + -2;
  uVar8 = uVar7 & 0xfffffffc;
  uStack_28 = uVar8;
  if (param_3 + 0x13 < 0x1f) {
    uVar2 = 0x10;
    if (0x10 < param_3) goto LAB_00232d03;
    piVar9 = (int *)(uVar8 + (int)param_2);
    if (0xf < (int)uVar8) {
      uVar8 = uVar8 - 0x10;
      goto joined_r0x00232bf4;
    }
    uVar10 = piVar9[-1];
    if (piVar9 + -2 == (int *)PTR_DAT_00237f28) {
      iVar4 = (uVar10 & 0xfffffffc) + uVar8;
      if (0x1f < iVar4) goto LAB_00232e07;
    }
    else {
      if ((*(uint *)((int)piVar9 + ((uVar10 & 0xfffffffe) - 4)) & 1) != 0) goto LAB_00232bfe;
      uStack_28 = (uVar10 & 0xfffffffc) + uVar8;
      if (0xf < (int)uStack_28) {
        iVar4 = *piVar9;
        iVar6 = piVar9[1];
        *(int *)(iVar4 + 0xc) = iVar6;
        *(int *)(iVar6 + 8) = iVar4;
        uVar8 = uStack_28 - 0x10;
        goto joined_r0x00232bf4;
      }
    }
    if ((uVar7 & 1) == 0) {
      piVar3 = (int *)((int)param_2 - param_2[-2]);
      piVar5 = piVar3 + -0x80;
      uVar7 = piVar3[-1] & 0xfffffffc;
      if (piVar9 != (int *)0x8) {
        uStack_28 = uVar8 + uVar7 + (uVar10 & 0xfffffffc);
        if (piVar9 + -2 == (int *)PTR_DAT_00237f28) {
          if (0x1f < (int)uStack_28) goto LAB_00232d54;
        }
        else if (0xf < (int)uStack_28) goto LAB_00232f46;
      }
      goto LAB_00232c19;
    }
    goto LAB_00232e44;
  }
  uVar2 = param_3 + 0x13 & 0xfffffff0;
  if (((int)uVar2 < 0) || (uVar2 < param_3)) {
LAB_00232d03:
    *param_1 = 0xc;
    return (int *)0x0;
  }
  piVar9 = (int *)(uVar8 + (int)param_2);
  if ((int)uVar8 < (int)uVar2) {
    uVar10 = piVar9[-1];
    if (piVar9 + -2 == (int *)PTR_DAT_00237f28) {
      iVar4 = (uVar10 & 0xfffffffc) + uVar8;
      if ((int)(uVar2 + 0x10) <= iVar4) {
LAB_00232e07:
        PTR_DAT_00237f28 = (undefined *)((int)param_2 + (uVar2 - 8));
        *(uint *)((int)param_2 + (uVar2 - 4)) = iVar4 - uVar2 | 1;
        param_2[-1] = uVar2 | param_2[-1] & 1U;
        __malloc_unlock(param_1);
        return param_2;
      }
    }
    else {
      if ((*(uint *)((int)piVar9 + ((uVar10 & 0xfffffffe) - 4)) & 1) != 0) {
LAB_00232bfe:
        if ((uVar7 & 1) == 0) {
          piVar3 = (int *)((int)param_2 - param_2[-2]);
          piVar5 = piVar3 + -0x80;
          uVar7 = piVar3[-1] & 0xfffffffc;
          goto LAB_00232c19;
        }
        goto LAB_00232e44;
      }
      uStack_28 = (uVar10 & 0xfffffffc) + uVar8;
      if ((int)uVar2 <= (int)uStack_28) {
        iVar4 = *piVar9;
        iVar6 = piVar9[1];
        *(int *)(iVar4 + 0xc) = iVar6;
        *(int *)(iVar6 + 8) = iVar4;
        goto LAB_00232ca3;
      }
    }
    if ((uVar7 & 1) == 0) {
      piVar3 = (int *)((int)param_2 - param_2[-2]);
      piVar5 = piVar3 + -0x80;
      uVar7 = piVar3[-1] & 0xfffffffc;
      if (piVar9 != (int *)0x8) {
        uStack_28 = uVar8 + uVar7 + (uVar10 & 0xfffffffc);
        if (piVar9 + -2 == (int *)PTR_DAT_00237f28) {
          if ((int)(uVar2 + 0x10) <= (int)uStack_28) {
LAB_00232d54:
            iVar4 = piVar5[0x80];
            iVar6 = piVar5[0x81];
            *(int *)(iVar4 + 0xc) = iVar6;
            uVar8 = uVar8 - 4;
            *(int *)(iVar6 + 8) = iVar4;
            if (uVar8 < 0x25) {
              piVar1 = piVar3;
              piVar9 = param_2;
              if (0x13 < uVar8) {
                *piVar3 = *param_2;
                piVar9 = param_2 + 2;
                piVar3[1] = param_2[1];
                piVar1 = piVar3 + 2;
                if (0x1b < uVar8) {
                  piVar3[2] = param_2[2];
                  piVar9 = param_2 + 4;
                  piVar3[3] = param_2[3];
                  piVar1 = piVar3 + 4;
                  if (0x23 < uVar8) {
                    piVar3[4] = param_2[4];
                    piVar1 = piVar3 + 6;
                    piVar3[5] = param_2[5];
                    piVar9 = param_2 + 6;
                  }
                }
              }
              *piVar1 = *piVar9;
              piVar1[1] = piVar9[1];
              piVar1[2] = piVar9[2];
            }
            else {
              memmove(piVar3,param_2);
            }
            PTR_DAT_00237f28 = (undefined *)((int)piVar3 + (uVar2 - 8));
            *(uint *)(PTR_DAT_00237f28 + 4) = uStack_28 - uVar2 | 1;
            piVar3[-1] = uVar2 | piVar3[-1] & 1U;
            __malloc_unlock(param_1);
            return piVar3;
          }
        }
        else if ((int)uVar2 <= (int)uStack_28) {
LAB_00232f46:
          iVar4 = *(int *)(uVar8 + (int)param_2);
          iVar6 = ((int *)(uVar8 + (int)param_2))[1];
          *(int *)(iVar4 + 0xc) = iVar6;
          *(int *)(iVar6 + 8) = iVar4;
          iVar4 = *piVar3;
          iVar6 = piVar3[1];
          *(int *)(iVar4 + 0xc) = iVar6;
          uVar8 = uVar8 - 4;
          *(int *)(iVar6 + 8) = iVar4;
          piVar1 = piVar3 + -2;
          if (uVar8 < 0x25) {
            piVar9 = piVar3;
            piVar5 = param_2;
            if (0x13 < uVar8) {
              *piVar3 = *param_2;
              piVar5 = param_2 + 2;
              piVar3[1] = param_2[1];
              piVar9 = piVar3 + 2;
              if (0x1b < uVar8) {
                piVar3[2] = param_2[2];
                piVar5 = param_2 + 4;
                piVar3[3] = param_2[3];
                piVar9 = piVar3 + 4;
                if (0x23 < uVar8) {
                  piVar3[4] = param_2[4];
                  piVar5 = param_2 + 6;
                  piVar3[5] = param_2[5];
                  piVar9 = piVar3 + 6;
                }
              }
            }
            *piVar9 = *piVar5;
            piVar9[1] = piVar5[1];
            piVar9[2] = piVar5[2];
          }
          else {
            memmove(piVar3,param_2);
          }
          goto LAB_00232ca3;
        }
      }
LAB_00232c19:
      if ((piVar3 != (int *)0x8) && (uStack_28 = uVar7 + uVar8, (int)uVar2 <= (int)uStack_28)) {
        iVar4 = piVar5[0x80];
        iVar6 = piVar5[0x81];
        *(int *)(iVar4 + 0xc) = iVar6;
        *(int *)(iVar6 + 8) = iVar4;
        uVar8 = uVar8 - 4;
        piVar1 = piVar3 + -2;
        if (uVar8 < 0x25) {
          piVar9 = piVar3;
          piVar5 = param_2;
          if (0x13 < uVar8) {
            *piVar3 = *param_2;
            piVar5 = param_2 + 2;
            piVar3[1] = param_2[1];
            piVar9 = piVar3 + 2;
            if (0x1b < uVar8) {
              piVar3[2] = param_2[2];
              piVar5 = param_2 + 4;
              piVar3[3] = param_2[3];
              piVar9 = piVar3 + 4;
              if (0x23 < uVar8) {
                piVar3[4] = param_2[4];
                piVar5 = param_2 + 6;
                piVar3[5] = param_2[5];
                piVar9 = piVar3 + 6;
              }
            }
          }
          *piVar9 = *piVar5;
          piVar9[1] = piVar5[1];
          piVar9[2] = piVar5[2];
        }
        else {
          memmove(piVar3,param_2);
        }
        goto LAB_00232ca3;
      }
    }
LAB_00232e44:
    piVar9 = (int *)_malloc_r(param_1,param_3);
    if (piVar9 == (int *)0x0) {
      __malloc_unlock(param_1);
      return (int *)0x0;
    }
    if (piVar9 != (int *)((int)param_2 + (param_2[-1] & 0xfffffffeU))) {
      uVar8 = uVar8 - 4;
      if (uVar8 < 0x25) {
        piVar1 = piVar9;
        piVar3 = param_2;
        if (0x13 < uVar8) {
          *piVar9 = *param_2;
          piVar3 = param_2 + 2;
          piVar9[1] = param_2[1];
          piVar1 = piVar9 + 2;
          if (0x1b < uVar8) {
            piVar9[2] = param_2[2];
            piVar3 = param_2 + 4;
            piVar9[3] = param_2[3];
            piVar1 = piVar9 + 4;
            if (0x23 < uVar8) {
              piVar9[4] = param_2[4];
              piVar3 = param_2 + 6;
              piVar9[5] = param_2[5];
              piVar1 = piVar9 + 6;
            }
          }
        }
        *piVar1 = *piVar3;
        piVar1[1] = piVar3[1];
        piVar1[2] = piVar3[2];
      }
      else {
        memmove(piVar9,param_2);
      }
      _free_r(param_1,param_2);
      __malloc_unlock(param_1);
      return piVar9;
    }
    uStack_28 = uVar8 + (piVar9[-1] & 0xfffffffcU);
  }
LAB_00232ca3:
  uVar8 = uStack_28 - uVar2;
joined_r0x00232bf4:
  if (uVar8 < 0x10) {
    piVar1[1] = uStack_28 | piVar1[1] & 1U;
    *(uint *)((int)piVar1 + uStack_28 + 4) = *(uint *)((int)piVar1 + uStack_28 + 4) | 1;
  }
  else {
    piVar1[1] = uVar2 | piVar1[1] & 1U;
    *(uint *)((int)piVar1 + uVar2 + 4) = uVar8 | 1;
    *(uint *)((int)piVar1 + uStack_28 + 4) = *(uint *)((int)piVar1 + uStack_28 + 4) | 1;
    _free_r(param_1,(int)piVar1 + uVar2 + 8);
  }
  __malloc_unlock(param_1);
  return piVar1 + 2;
}


// ===== __swbuf_r @ 00233010 (194 bytes)

/* newlib wbuf.c: __sinit, __swsetup_r, _fflush_r [inference] */

uint __swbuf_r(int param_1,byte param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x38) == 0)) {
    __sinit(param_1);
  }
  param_3[2] = param_3[6];
  uVar1 = (uint)(short)param_3[3];
  iVar2 = param_3[4];
  if (((uVar1 >> 3 & 1) == 0) || (iVar2 == 0)) {
    iVar2 = __swsetup_r(param_1,param_3);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    iVar2 = param_3[4];
    uVar1 = (uint)(short)param_3[3];
  }
  if ((uVar1 >> 0xd & 1) == 0) {
    *(ushort *)(param_3 + 3) = (ushort)uVar1 | 0x2000;
    param_3[0x19] = param_3[0x19] & 0xffffdfff;
  }
  iVar2 = *param_3 - iVar2;
  if (iVar2 < param_3[5]) {
    param_3[2] = param_3[2] + -1;
    *(byte *)*param_3 = param_2;
    *param_3 = *param_3 + 1;
    if (param_3[5] != iVar2 + 1) {
LAB_0023306c:
      if (((*(ushort *)(param_3 + 3) & 1) == 0) || (param_2 != 10)) goto LAB_00233075;
    }
  }
  else {
    iVar2 = _fflush_r(param_1,param_3);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    param_3[2] = param_3[2] + -1;
    *(byte *)*param_3 = param_2;
    *param_3 = *param_3 + 1;
    if (param_3[5] != 1) goto LAB_0023306c;
  }
  iVar2 = _fflush_r(param_1,param_3);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
LAB_00233075:
  return (uint)param_2;
}


// ===== __swbuf @ 002330e0 (24 bytes)

/* newlib wbuf.c: _impure_ptr [inference] */

undefined4 __swbuf(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = __swbuf_r(PTR_DAT_00237f00,param_1,param_2);
  return uVar1;
}


// ===== _wcrtomb_r @ 00233100 (85 bytes)

/* newlib wcrtomb.c [inference] */

int _wcrtomb_r(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_30 [48];
  
  if (param_2 == 0) {
    uVar1 = FUN_002301a0();
    iVar2 = (*(code *)PTR_FUN_002383b0)(param_1,auStack_30,0,uVar1,param_4);
  }
  else {
    uVar1 = FUN_002301a0();
    iVar2 = (*(code *)PTR_FUN_002383b0)(param_1,param_2,param_3,uVar1,param_4);
  }
  if (iVar2 == -1) {
    *param_4 = 0;
    *param_1 = 0x8a;
    return -1;
  }
  return iVar2;
}


// ===== wcrtomb @ 00233160 (97 bytes)

/* newlib wcrtomb.c: _impure_ptr [inference] */

int wcrtomb(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_30 [48];
  
  if (param_1 == 0) {
    uVar2 = FUN_002301a0();
    iVar3 = (*(code *)PTR_FUN_002383b0)(PTR_DAT_00237f00,auStack_30,0,uVar2,param_3);
    puVar1 = (undefined4 *)PTR_DAT_00237f00;
  }
  else {
    uVar2 = FUN_002301a0();
    iVar3 = (*(code *)PTR_FUN_002383b0)(PTR_DAT_00237f00,param_1,param_2,uVar2,param_3);
    puVar1 = (undefined4 *)PTR_DAT_00237f00;
  }
  if (iVar3 == -1) {
    PTR_DAT_00237f00 = (undefined *)puVar1;
    *param_3 = 0;
    *puVar1 = 0x8a;
    return -1;
  }
  PTR_DAT_00237f00 = (undefined *)puVar1;
  return iVar3;
}


// ===== FUN_002331d0 @ 002331d0 (34 bytes)

undefined4 FUN_002331d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_002301a0();
  uVar1 = (*(code *)PTR_FUN_002383b0)(param_1,param_2,param_3,uVar1,param_4);
  return uVar1;
}


// ===== FUN_00233200 @ 00233200 (20 bytes)

void FUN_00233200(undefined4 param_1,undefined4 param_2,int param_3)

{
  *(undefined **)(param_3 + 4) = &DAT_00002000;
  *(undefined2 *)(param_3 + 10) = 0;
  *(undefined4 *)(param_3 + 0x2c) = 0;
  *(undefined4 *)(param_3 + 0x10) = 0;
  return;
}


// ===== _read_r @ 00233220 (37 bytes)

/* newlib reent read: calls the 8-byte read stub 0x23329C [inference] */

int _read_r(undefined4 param_1,undefined4 param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = param_3;
  if (0 < param_4) {
    do {
      iVar1 = FUN_0023329c();
      *puVar2 = (char)iVar1;
      puVar2 = puVar2 + 1;
      if ((iVar1 == 0xd) || (param_4 = param_4 + -1, iVar1 == 10)) break;
    } while (param_4 != 0);
  }
  return (int)puVar2 - (int)param_3;
}


// ===== _write_r @ 00233250 (40 bytes)

/* newlib reent write [inference] */

void _write_r(undefined4 param_1,undefined4 param_2,char *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  
  if (0 < param_4) {
    iVar2 = 0;
    do {
      cVar1 = *param_3;
      param_3 = param_3 + 1;
      if (cVar1 == '\n') {
        FUN_00233280(0xd);
      }
      FUN_00233280(cVar1);
      iVar2 = iVar2 + 1;
    } while (param_4 != iVar2);
  }
  return;
}


// ===== FUN_00233280 @ 00233280 (27 bytes)

void FUN_00233280(undefined1 param_1)

{
  (&DAT_002cd760)[DAT_002cd750] = param_1;
  DAT_002cd750 = DAT_002cd750 + 1 & 0xff;
  return;
}


// ===== FUN_0023329c @ 0023329c (7 bytes)

undefined4 FUN_0023329c(void)

{
  return 0xffffffff;
}


// ===== _exit @ 002332a4 (29 bytes)

/* board/runtime exit: data cache write-back (0x236450), then halts [inference] */

void _exit(void)

{
  xthal_dcache_all_writeback();
  extw();
  do {
    simcall();
    breakpoint(0x1000,0x2332b8,1,0xf);
    waiti(0xf);
  } while( true );
}


// ===== FUN_002332c4 @ 002332c4 (276 bytes)

longlong FUN_002332c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     uint param_5,undefined4 param_6)

{
  undefined4 unaff_retaddr;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 unaff_a8;
  int unaff_a9;
  uint unaff_a10;
  undefined4 unaff_a11;
  int in_a13;
  uint uVar5;
  undefined4 in_WindowBase;
  undefined4 in_WindowStart;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uStack_c;
  
  iVar1 = rsr_windowbase(in_WindowBase);
  uVar5 = iVar1 + 1U & 0x1f;
  uVar2 = rsr_windowstart(in_WindowStart);
  uVar7 = uVar2 << 0x20 - uVar5;
  if (-1 < (int)uVar7) {
    return CONCAT44(uVar7,1);
  }
  uVar2 = uVar2 >> uVar5 | uVar7 >> 0x18;
  uVar6 = wsr_windowstart(uVar2 >> 0x20 - (LZCOUNT(-uVar2 & uVar2) & 0x1fU));
  iVar1 = rsr_windowbase(in_WindowBase);
  puVar3 = (undefined4 *)((iVar1 + 0x1f) - LZCOUNT(-uVar2 & uVar2));
  iVar1 = wsr_windowbase(puVar3);
  rsync();
  uVar2 = rsr_windowstart(uVar6);
  while( true ) {
    while( true ) {
      while( true ) {
        if (uVar2 == 0) {
          uVar2 = rsr_windowbase(iVar1 + 1);
          wsr_windowstart(1 << 0x20 - (0x20 - (uVar2 & 0x1f)));
          rsync();
          return ZEXT48(puVar3) << 0x20;
        }
        if ((uVar2 & 1) == 0) break;
        puVar3 = (undefined4 *)(unaff_a9 - 0x10);
        *puVar3 = param_3;
        *(int *)(unaff_a9 + -0xc) = param_4;
        *(uint *)(unaff_a9 + -8) = param_5;
        param_5 = uVar2 >> 1;
        *(undefined4 *)(unaff_a9 + -4) = param_6;
        iVar1 = iVar1 + 1;
      }
      if ((uVar2 & 2) == 0) break;
      *(undefined4 *)(in_a13 + -0x10) = param_3;
      *(int *)(in_a13 + -0xc) = param_4;
      *(uint *)(in_a13 + -8) = param_5;
      *(undefined4 *)(in_a13 + -4) = param_6;
      iVar4 = *(int *)(param_4 + -0xc);
      puVar3 = (undefined4 *)(iVar4 - 0x20);
      *puVar3 = unaff_a8;
      *(int *)(iVar4 + -0x1c) = unaff_a9;
      *(uint *)(iVar4 + -0x18) = unaff_a10;
      unaff_a10 = uVar2 >> 2;
      *(undefined4 *)(iVar4 + -0x14) = unaff_a11;
      iVar1 = iVar1 + 2;
    }
    if ((uVar2 & 4) == 0) break;
    *(undefined4 *)(in_a13 + -0x10) = unaff_retaddr;
    *(BADSPACEBASE **)(in_a13 + -0xc) = register0x00000004;
    *(uint *)(in_a13 + -8) = uVar2;
    *(undefined4 **)(in_a13 + -4) = puVar3;
    puVar3 = (undefined4 *)(uStack_c - 0x30);
    *puVar3 = param_3;
    *(int *)(uStack_c + -0x2c) = param_4;
    *(uint *)(uStack_c + -0x28) = param_5;
    *(undefined4 *)(uStack_c + -0x24) = param_6;
    *(undefined4 *)(uStack_c + -0x20) = unaff_a8;
    *(int *)(uStack_c + -0x1c) = unaff_a9;
    *(uint *)(uStack_c + -0x18) = unaff_a10;
    *(undefined4 *)(uStack_c + -0x14) = unaff_a11;
    iVar1 = iVar1 + 3;
  }
  uVar2 = uVar2 * 2 + 1;
  uVar5 = rsr_windowbase(iVar1);
  if ((uVar2 & 0x80) == 0) {
    do {
      uVar5 = uVar5 - 1;
      uVar2 = uVar2 << 1;
    } while ((uVar2 & 0x80) == 0);
    uVar5 = uVar5 & 7;
  }
  iVar1 = 0x20 - (uVar5 & 0x1f);
  wsr_windowstart((uint)(CONCAT44(uVar2,uVar2 << 0x18) >> iVar1) & 0xff);
  iVar1 = rsr_sar(iVar1);
  wsr_windowbase(0x20 - iVar1);
  rsync();
  return CONCAT44(0x20 - iVar1,2);
}


// ===== FUN_002333e0 @ 002333e0 (36 bytes)

void FUN_002333e0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_a5;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  iVar1 = (uVar2 & 0xfffbfff0) + 2;
  wsr_ps(iVar1);
  rsync();
  FUN_002332c4(iVar1);
  wsr_ps(extraout_a5);
  rsync();
  return;
}


// ===== xthal_set_region_attribute @ 00233410 (360 bytes)

/* (vaddr, size, cattr, flags): Cadence HAL region-protection variant, 8 x 512 MB regions via
   xthal_get/set_cacheattr; flag bits 9-12 EXACT, NO_PARTIAL, NO_AUTO_WB, NO_AUTO_INV; returns 0, -2
   (inexact), -3 (bad range). DSP main calls (0x20060000, 0x31E0, 2, 0) and (0x20070000, 0x10000, 2,
   0): cattr 2 = bypass on region 0x20000000-0x3FFFFFFF (#184) */

undefined4 xthal_set_region_attribute(uint param_1,int param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint extraout_a3;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (param_2 != 0) {
    uVar5 = (param_1 + param_2) - 1;
    uVar6 = param_1 >> 0x1d;
    if (uVar5 < param_1) {
      return 0xfffffffd;
    }
    if (param_1 + param_2 == -1) {
      uVar5 = 0xffffffff;
    }
    uVar7 = uVar5 >> 0x1d;
    if ((param_4 >> 9 & 1) == 0) {
      uVar2 = uVar7 - 1;
      if ((param_4 >> 10 & 1) != 0) {
        uVar5 = uVar5 + 1 & 0x1fffffff;
        uVar7 = uVar6 + 1;
        uVar6 = uVar5;
        if ((param_1 & 0x1fffffff) != 0) {
          uVar6 = uVar7;
        }
        if (uVar5 != 0) {
          uVar7 = uVar2;
        }
        if (uVar7 < uVar6) {
          return 0xffffffff;
        }
      }
    }
    else if (((param_1 & 0x1fffffff) != 0) || ((uVar5 + 1 & 0x1fffffff) != 0)) {
      return 0xfffffffe;
    }
    uVar2 = xthal_get_cacheattr();
    uVar5 = uVar2;
    if (uVar7 < uVar6) {
      bVar1 = false;
    }
    else {
      bVar1 = false;
      param_3 = param_3 & 0xf;
      if (uVar7 - uVar6 != -1) {
        uVar5 = uVar6 << 2;
        uVar7 = uVar2 >> (uVar5 & 0x1f) & 0xf;
        if (((param_4 & 0x100) != 0) &&
           ((int)*(char *)((int)&PTR_DAT_00200070 + param_3) -
            (int)*(char *)((int)&PTR_DAT_00200070 + uVar7) < 0)) {
          param_3 = uVar7;
        }
        if ((param_3 == 2) || (param_3 == 6)) {
          bVar1 = (uVar7 != 2 && uVar7 != 6) && uVar7 != 6;
        }
        uVar3 = param_3;
        if ((((uVar7 == 4) || (uVar7 == 5)) && (param_3 != 4)) && (param_3 != 5)) {
          uVar3 = 1;
        }
        uVar6 = uVar6 + 1;
        iVar4 = 0x20 - (uVar5 & 0x1f);
        uVar7 = 0xf << 0x20 - iVar4 ^ 0xffffffff;
        uVar5 = uVar7 & uVar2 | uVar3 << 0x20 - iVar4;
        uVar2 = uVar7 & uVar2 | param_3 << 0x20 - iVar4;
      }
    }
    if ((uVar5 != uVar2) && ((param_4 >> 0xb & 1) == 0)) {
      xthal_set_cacheattr(uVar5,uVar6);
      xthal_dcache_all_writeback();
      uVar6 = extraout_a3;
    }
    xthal_set_cacheattr(uVar2,uVar6);
    if ((bVar1) && ((param_4 & 0x1000) == 0)) {
      xthal_dcache_all_writeback_inv();
      xthal_icache_all_invalidate();
      return 0;
    }
  }
  return 0;
}


// ===== xthal_get_cacheattr @ 00233580 (32 bytes)

/* rdtlb1 of the 8 x 512 MB regions -> 8 attribute nibbles (#184) */

uint xthal_get_cacheattr(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar2 = 0;
  do {
    uVar2 = uVar2 + 0xe0000000;
    uVar3 = rdtlb1(uVar2);
    dsync();
    uVar1 = uVar1 << 4 | uVar3 & 0xf;
  } while (0xf < uVar2);
  return uVar1;
}


// ===== xthal_set_cacheattr @ 002335a0 (83 bytes)

/* witlb (skipping its own region) and wdtlb for each 512 MB region, 4 bits each (#184) */

void xthal_set_cacheattr(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  uVar2 = param_1;
  do {
    if (iVar1 == 0) {
      witlb(0,uVar2 & 0xf);
      isync();
    }
    else {
      witlb(iVar1,uVar2 & 0xf);
      if (iVar1 + 0x20000000U < 0x10) {
        isync();
        uVar2 = 0;
        do {
          wdtlb(uVar2,param_1 & 0xf);
          uVar2 = uVar2 + 0x20000000;
          param_1 = param_1 >> 4;
        } while (0xf < uVar2);
        dsync();
        return;
      }
    }
    iVar1 = iVar1 + 0x20000000;
    uVar2 = uVar2 >> 4;
  } while( true );
}


// ===== FUN_00233600 @ 00233600 (80 bytes)

uint FUN_00233600(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((~param_2 & 0x7ff00000) == 0) {
    if ((param_2 & 0xfffff) != 0 || param_1 != 0) {
      param_2 = 0;
    }
  }
  else {
    uVar1 = (param_2 >> 0x14 & 0x7ff) - 0x3fe;
    if ((int)uVar1 < 0x20) {
      if (0 < (int)uVar1) {
        uVar2 = (uint)((CONCAT44(param_2,param_1) | 0x7ff0000000000000) >> 0x15) >>
                0x20 - (uVar1 & 0x1f);
        uVar1 = -uVar2;
        if (-1 < (int)(param_2 | 0x7ff00000)) {
          uVar1 = uVar2;
        }
        return uVar1;
      }
      return 0;
    }
  }
  uVar1 = 0x80000000;
  if (-1 < (int)param_2) {
    uVar1 = 0x7fffffff;
  }
  return uVar1;
}


// ===== FUN_00233650 @ 00233650 (30 bytes)

/* WARNING: Removing unreachable block (ram,0x0023365f) */
/* WARNING: Removing unreachable block (ram,0x00233661) */

void FUN_00233650(void)

{
  return;
}


// ===== fft_realf_ie @ 00233670 (631 bytes)

/* NDSP fft/fft_ief: real FFT, calls fft_cplxf_ie then splits with conjc.s [inference] */

longlong fft_realf_ie(undefined8 *param_1,undefined8 *param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  float fVar9;
  float fVar10;
  undefined8 uVar11;
  float fVar12;
  ulonglong uVar13;
  float fVar14;
  int iVar15;
  undefined8 uVar16;
  undefined8 *puVar17;
  uint uVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  ulonglong uVar27;
  undefined8 uVar28;
  ulonglong uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  
  puVar17 = (undefined8 *)(param_4 * 0x18 + param_3);
  if (param_5 == 8) {
    uVar11 = ae_l32x2_i(param_2[3]);
    uVar20 = ae_l32x2_i(param_2[1]);
    uVar16 = ae_l32x2_i(param_2[2]);
    uVar21 = ae_l32x2_i(*param_2);
    fVar9 = (float)uVar20;
    fVar10 = (float)uVar11;
    fVar14 = (float)uVar21 - (float)uVar16;
    uVar11 = ae_sel16i((ulonglong)(uint)(fVar10 - fVar9),(ulonglong)(uint)(fVar9 - fVar10),0);
    fVar1 = fVar14 - (float)uVar11;
    uVar20 = conjc_s((ulonglong)(uint)(fVar14 + (float)uVar11));
    uVar13 = (ulonglong)(uint)(fVar1 - (float)uVar20);
    uVar11 = ae_l64_xp(*puVar17);
    uVar22 = mulmux_s(uVar13,uVar11,1);
    fVar14 = (float)uVar21 + (float)uVar16;
    uVar21 = maddmux_s(uVar22,uVar13,uVar11,5);
    fVar1 = fVar1 + (float)uVar20;
    fVar12 = fVar14 + fVar9 + fVar10;
    uVar16 = ae_sel16i((ulonglong)(uint)fVar12,(ulonglong)(uint)fVar12,3);
    uVar20 = conjc_s(uVar16);
    uVar22 = const_s(3);
    uVar11 = conjc_s((ulonglong)(uint)(fVar14 - (fVar9 + fVar10)));
    uVar11 = ae_s32x2_i(uVar11);
    param_1[2] = uVar11;
    uVar23 = mulmux_s(uVar22,(ulonglong)(uint)(fVar1 - (float)uVar21),1);
    uVar11 = ae_s32x2_i((ulonglong)(uint)(fVar12 - (float)uVar16));
    param_1[4] = uVar11;
    uVar11 = ae_s32x2_i((ulonglong)(uint)(fVar12 + (float)uVar20));
    *param_1 = uVar11;
    uVar11 = ae_s32x2_i((ulonglong)(uint)((float)uVar22 * (fVar1 + (float)uVar21)));
    param_1[1] = uVar11;
    uVar11 = ae_s32x2_i(uVar23);
    param_1[3] = uVar11;
    return ZEXT48(puVar17 + param_4 * 3) << 0x20;
  }
  fft_cplxf_ie(param_1,param_2,param_3,param_4 << 1,param_5 >> 1);
  puVar4 = param_1 + (param_5 >> 1);
  uVar16 = ae_l32x2_ip(*param_1);
  puVar3 = param_1 + 1;
  uVar11 = ae_sel16i(uVar16,uVar16,3);
  uVar20 = conjc_s(uVar11);
  uVar11 = ae_s32x2_xp((ulonglong)(uint)((float)uVar16 - (float)uVar11));
  *puVar4 = uVar11;
  puVar8 = puVar4 + -1;
  puVar6 = puVar4 + -1;
  uVar11 = ae_s32x2_ip((ulonglong)(uint)((float)uVar16 + (float)uVar20));
  *param_1 = uVar11;
  puVar7 = param_1 + 1;
  uVar18 = (param_5 >> 2) - 1;
  uVar11 = const_s(3);
  fVar14 = (float)uVar11;
  if ((uVar18 & 1) != 0) {
    uVar16 = ae_l32x2_xp(*puVar6);
    puVar6 = puVar4 + -2;
    uVar20 = ae_l32x2_ip(*puVar3);
    puVar3 = param_1 + 2;
    uVar21 = conjc_s(uVar16);
    uVar13 = (ulonglong)(uint)((float)uVar20 - (float)uVar21);
    uVar16 = ae_l64_xp(*puVar17);
    puVar17 = puVar17 + param_4 * 3;
    uVar22 = mulmux_s(uVar13,uVar16,1);
    uVar16 = maddmux_s(uVar22,uVar13,uVar16,5);
    fVar1 = (float)uVar20 + (float)uVar21;
    uVar20 = mulmux_s(uVar11,(ulonglong)(uint)(fVar1 - (float)uVar16),1);
    uVar16 = ae_s32x2_ip((ulonglong)(uint)(fVar14 * (fVar1 + (float)uVar16)));
    *puVar7 = uVar16;
    puVar7 = param_1 + 2;
    uVar16 = ae_s32x2_xp(uVar20);
    *puVar8 = uVar16;
    puVar8 = puVar4 + -2;
  }
  uVar16 = ae_l32x2_xp(*puVar6);
  uVar20 = ae_l32x2_ip(*puVar3);
  uVar23 = conjc_s(uVar16);
  uVar13 = (ulonglong)(uint)((float)uVar20 - (float)uVar23);
  uVar16 = ae_l32x2_xp(puVar6[-1]);
  uVar21 = ae_l32x2_i(puVar3[1]);
  uVar24 = conjc_s(uVar16);
  uVar16 = ae_l64_xp(*puVar17);
  uVar19 = (ulonglong)(uint)((float)uVar21 - (float)uVar24);
  uVar25 = mulmux_s(uVar13,uVar16,1);
  uVar22 = ae_l64_xp(puVar17[param_4 * 3]);
  puVar17 = puVar17 + param_4 * 3 + param_4 * 3;
  uVar26 = mulmux_s(uVar19,uVar22,1);
  uVar25 = maddmux_s(uVar25,uVar13,uVar16,5);
  fVar1 = (float)uVar20 + (float)uVar23;
  uVar20 = maddmux_s(uVar26,uVar19,uVar22,5);
  fVar12 = (float)uVar21 + (float)uVar24;
  fVar9 = fVar12 + (float)uVar20;
  iVar15 = (int)uVar18 >> 1;
  uVar16 = mulmux_s(uVar11,(ulonglong)(uint)(fVar1 - (float)uVar25),1);
  uVar13 = (ulonglong)(uint)(fVar12 - (float)uVar20);
  uVar19 = (ulonglong)(uint)(fVar14 * (fVar1 + (float)uVar25));
  if (1 < iVar15) {
    uVar20 = ae_l32x2_xp(puVar6[-2]);
    uVar21 = ae_l32x2_xp(puVar6[-3]);
    uVar24 = ae_l32x2_ip(puVar3[2]);
    puVar4 = puVar3 + 4;
    uVar25 = conjc_s(uVar20);
    uVar23 = ae_l32x2_i(puVar3[3]);
    uVar21 = conjc_s(uVar21);
    uVar27 = (ulonglong)(uint)((float)uVar24 - (float)uVar25);
    uVar29 = (ulonglong)(uint)((float)uVar23 - (float)uVar21);
    uVar20 = ae_l64_xp(*puVar17);
    uVar22 = ae_l64_xp(puVar17[param_4 * 3]);
    puVar5 = puVar17 + param_4 * 3 + param_4 * 3;
    fVar1 = (float)uVar24 + (float)uVar25;
    fVar2 = (float)uVar23 + (float)uVar21;
    uVar21 = mulmux_s(uVar27,uVar20,1);
    uVar23 = mulmux_s(uVar29,uVar22,1);
    puVar17 = puVar7;
    fVar12 = fVar1;
    fVar10 = fVar2;
    if (0 < iVar15 + -2) {
      uVar24 = ae_l32x2_xp(puVar6[-4]);
      uVar26 = maddmux_s(uVar21,uVar27,uVar20,5);
      uVar30 = mulmux_s(uVar11,uVar13,1);
      uVar21 = ae_l32x2_ip(*puVar4);
      puVar4 = puVar3 + 6;
      uVar25 = ae_l32x2_i(puVar3[5]);
      uVar28 = conjc_s(uVar24);
      uVar16 = ae_s32x2_xp(uVar16);
      *puVar8 = uVar16;
      uVar24 = ae_l32x2_xp(puVar6[-5]);
      uVar27 = (ulonglong)(uint)((float)uVar21 - (float)uVar28);
      uVar31 = maddmux_s(uVar23,uVar29,uVar22,5);
      uVar16 = ae_s32x2_ip(uVar19);
      *puVar7 = uVar16;
      puVar17 = puVar7 + 2;
      uVar20 = ae_l64_xp(*puVar5);
      uVar23 = conjc_s(uVar24);
      uVar16 = ae_s32x2_xp(uVar30);
      puVar8[-1] = uVar16;
      puVar8 = puVar8 + -2;
      uVar22 = ae_l64_xp(puVar5[param_4 * 3]);
      puVar5 = puVar5 + param_4 * 3 + param_4 * 3;
      uVar29 = (ulonglong)(uint)((float)uVar25 - (float)uVar23);
      uVar16 = ae_s32x2_i((ulonglong)(uint)(fVar14 * fVar9));
      puVar7[1] = uVar16;
      fVar12 = (float)uVar21 + (float)uVar28;
      uVar21 = mulmux_s(uVar27,uVar20,1);
      uVar13 = (ulonglong)(uint)(fVar2 - (float)uVar31);
      fVar10 = (float)uVar25 + (float)uVar23;
      fVar9 = fVar2 + (float)uVar31;
      uVar16 = mulmux_s(uVar11,(ulonglong)(uint)(fVar1 - (float)uVar26),1);
      uVar23 = mulmux_s(uVar29,uVar22,1);
      uVar19 = (ulonglong)(uint)(fVar14 * (fVar1 + (float)uVar26));
    }
    uVar20 = maddmux_s(uVar21,uVar27,uVar20,5);
    uVar21 = maddmux_s(uVar23,uVar29,uVar22,5);
    uVar23 = mulmux_s(uVar11,uVar13,1);
    uVar16 = ae_s32x2_xp(uVar16);
    *puVar8 = uVar16;
    uVar22 = mulmux_s(uVar11,(ulonglong)(uint)(fVar12 - (float)uVar20),1);
    uVar16 = ae_s32x2_ip(uVar19);
    *puVar17 = uVar16;
    uVar16 = ae_s32x2_i((ulonglong)(uint)(fVar14 * fVar9));
    puVar17[1] = uVar16;
    uVar16 = ae_s32x2_xp(uVar23);
    puVar8[-1] = uVar16;
    uVar16 = ae_s32x2_xp(uVar22);
    puVar8[-2] = uVar16;
    uVar16 = ae_l32x2_i(*puVar4);
    uVar22 = mulmux_s(uVar11,(ulonglong)(uint)(fVar10 - (float)uVar21),1);
    uVar11 = ae_s32x2_ip((ulonglong)(uint)(fVar14 * (fVar12 + (float)uVar20)));
    puVar17[2] = uVar11;
    uVar11 = conjc_s(uVar16);
    uVar11 = ae_s32x2_i(uVar11);
    puVar17[4] = uVar11;
    uVar11 = ae_s32x2_i((ulonglong)(uint)(fVar14 * (fVar10 + (float)uVar21)));
    puVar17[3] = uVar11;
    uVar11 = ae_s32x2_xp(uVar22);
    puVar8[-3] = uVar11;
    return ZEXT48(puVar5) << 0x20;
  }
  uVar16 = ae_s32x2_xp(uVar16);
  *puVar8 = uVar16;
  uVar16 = ae_l32x2_i(puVar3[2]);
  uVar20 = mulmux_s(uVar11,uVar13,1);
  uVar11 = ae_s32x2_ip(uVar19);
  *puVar7 = uVar11;
  uVar11 = conjc_s(uVar16);
  uVar11 = ae_s32x2_i(uVar11);
  puVar7[2] = uVar11;
  uVar11 = ae_s32x2_i((ulonglong)(uint)(fVar14 * fVar9));
  puVar7[1] = uVar11;
  uVar11 = ae_s32x2_xp(uVar20);
  puVar8[-1] = uVar11;
  return ZEXT48(puVar17) << 0x20;
}


// ===== FUN_00233818 @ 00233818 (137 bytes)

undefined4 FUN_00233818(undefined8 *param_1,int param_2)

{
  undefined8 *unaff_a11;
  undefined8 *puVar1;
  undefined8 *in_a12;
  int in_a14;
  float in_aed0;
  undefined8 in_aed1;
  undefined8 in_aed2;
  undefined8 in_aed3;
  undefined8 in_aed4;
  float in_aed5;
  undefined8 in_aed6;
  float in_aed8;
  float in_aed9;
  undefined8 in_aed10;
  undefined8 in_aed11;
  undefined8 uVar2;
  float in_aed13;
  float in_aed15;
  undefined4 in_register_0000407c;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar2 = ae_l32x2f24_xp(*unaff_a11);
  puVar1 = (undefined8 *)((int)unaff_a11 + param_2);
  uVar4 = mulmux_s(CONCAT44(in_register_0000407c,in_aed15),in_aed6,1);
  uVar7 = mulmux_s(in_aed10,in_aed11,1);
  uVar5 = maddmux_s(in_aed4,in_aed2,in_aed3,5);
  uVar7 = maddmux_s(uVar7,in_aed10,in_aed11,5);
  uVar8 = mulmux_s(CONCAT44(in_register_0000407c,in_aed15),in_aed1,1);
  uVar4 = ae_s32x2_xp(uVar4);
  *in_a12 = uVar4;
  uVar6 = mulmux_s(CONCAT44(in_register_0000407c,in_aed15),(ulonglong)(uint)(in_aed5 - (float)uVar5)
                   ,1);
  uVar4 = ae_s32x2_ip((ulonglong)(uint)(in_aed15 * in_aed0));
  *puVar1 = uVar4;
  uVar4 = ae_s32x2_i((ulonglong)(uint)(in_aed15 * (in_aed13 + (float)uVar2)));
  puVar1[1] = uVar4;
  uVar4 = ae_s32x2_xp(uVar8);
  *(undefined8 *)((int)in_a12 + in_a14) = uVar4;
  puVar3 = (undefined8 *)((int)in_a12 + in_a14 + in_a14);
  uVar4 = ae_s32x2_xp(uVar6);
  *puVar3 = uVar4;
  uVar2 = ae_l32x2_i(*param_1);
  uVar6 = mulmux_s(CONCAT44(in_register_0000407c,in_aed15),
                   (ulonglong)(uint)((in_aed9 + in_aed8) - (float)uVar7),1);
  uVar4 = ae_s32x2_ip((ulonglong)(uint)(in_aed15 * (in_aed5 + (float)uVar5)));
  puVar1[2] = uVar4;
  uVar4 = conjc_s(uVar2);
  uVar4 = ae_s32x2_i(uVar4);
  puVar1[4] = uVar4;
  uVar4 = ae_s32x2_i((ulonglong)(uint)(in_aed15 * (in_aed9 + in_aed8 + (float)uVar7)));
  puVar1[3] = uVar4;
  uVar4 = ae_s32x2_xp(uVar6);
  *(undefined8 *)((int)puVar3 + in_a14) = uVar4;
  return 0;
}


// ===== bkfiraf_alloc @ 00233970 (20 bytes)

/* NDSP fir/firblkf: 8 * align4(M) + 23 bytes [inference] */

int bkfiraf_alloc(int param_1)

{
  return (param_1 + 3U & 0xfffffffc) * 8 + 0x17;
}


// ===== bkfiraf_init @ 00233984 (126 bytes)

/* NDSP fir/firblkf (was fir_init) [inference] */

undefined8 bkfiraf_init(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined8 uVar9;
  
  puVar7 = (undefined4 *)(param_1 + 7U & 0xfffffff8);
  uVar8 = (int)param_2 + 3U & 0xfffffffc;
  puVar5 = puVar7 + uVar8;
  puVar4 = puVar5 + uVar8;
  *puVar4 = uVar8;
  puVar4[1] = (uint)puVar7;
  puVar4[3] = (uint)puVar5;
  puVar4[2] = (uint)puVar5;
  uVar9 = const_s(0);
  if ((int)param_2 < 1) {
    puVar3 = (undefined4 *)0x0;
    if ((int)uVar8 < 1) goto LAB_002339f5;
LAB_002339ce:
    puVar2 = (undefined4 *)(uVar8 - (int)puVar3);
    if ((0 < (int)puVar2) && ((puVar2 == (undefined4 *)0x1 || (0 < (int)puVar2)))) {
      uVar1 = ae_s32_l_ip(uVar9);
      puVar7[(int)puVar3] = uVar1;
    }
  }
  else {
    puVar2 = puVar7;
    if ((0 < (int)param_2) && ((param_2 == (undefined4 *)0x1 || (0 < (int)param_2)))) {
      uVar6 = ae_l32_ip(*param_3);
      uVar1 = ae_s32_l_ip(uVar6);
      *puVar7 = uVar1;
      puVar2 = puVar7 + 1;
    }
    puVar3 = param_2;
    if ((int)param_2 < (int)uVar8) goto LAB_002339ce;
  }
  uVar9 = ae_mov(uVar9);
  param_2 = puVar2;
  if ((0 < (int)uVar8) && ((uVar8 == 1 || (0 < (int)uVar8)))) {
    uVar1 = ae_s32_l_ip(uVar9);
    *puVar5 = uVar1;
  }
LAB_002339f5:
  return CONCAT44(param_2,puVar4);
}

