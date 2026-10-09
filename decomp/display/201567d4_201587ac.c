// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201567d4 @ 201567d4 (32 bytes)

uint FUN_201567d4(void)

{
  uint in_stack_00000004;
  
  DAT_208003cc = in_stack_00000004 & 0xc0;
  return in_stack_00000004 & 0xffffff3f | 0x80;
}


// ===== FUN_201567f4 @ 201567f4 (32 bytes)

longlong FUN_201567f4(void)

{
  uint in_stack_00000004;
  
  return (ulonglong)(DAT_208003cc | in_stack_00000004 & 0xffffff3f) << 0x20;
}


// ===== FUN_20156814 @ 20156814 (28 bytes)

void FUN_20156814(void)

{
  return;
}


// ===== FUN_20156830 @ 20156830 (48 bytes)

undefined8 FUN_20156830(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  undefined4 in_stack_00000004;
  
  return CONCAT44(in_stack_00000004,
                  (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b);
}


// ===== FUN_20156860 @ 20156860 (12 bytes)

undefined * FUN_20156860(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  uint uVar2;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  
  param_1[-1] = FUN_201509f4;
  param_1[-2] = unaff_r8;
  param_1[-3] = unaff_r7;
  param_1[-4] = unaff_r6;
  param_1[-5] = unaff_r5;
  param_1[-6] = unaff_r4;
  uVar2 = *(uint *)(param_3[6] + 8);
  param_1[0xc] = param_1 + 0x12;
  *param_1 = param_2;
  uVar1 = DAT_208003ac;
  if ((uVar2 & 1) != 0) {
    uVar1 = DAT_208003ac | 0x20;
  }
  param_1[0xf] = uVar1;
  uVar1 = FUN_201568b8();
  param_1[0xf] = uVar1 | param_1[0xf];
  param_1[0xd] = FUN_201508ec;
  param_1[0x11] = uVar2;
  *param_3 = (int)param_1;
  *(undefined1 *)(param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 9) = 0;
  param_3[8] = 0;
  *(undefined1 *)((int)param_3 + 5) = 0x10;
  FUN_201538d4(&DAT_208dc18c + *(char *)((int)param_3 + 0x27),param_3,param_4);
  software_interrupt(0);
  return &DAT_2015677c;
}


// ===== FUN_2015686c @ 2015686c (12 bytes)

code * FUN_2015686c(void)

{
  software_interrupt(0);
  return FUN_20156878;
}


// ===== FUN_20156878 @ 20156878 (20 bytes)

ulonglong FUN_20156878(void)

{
  undefined4 in_stack_00000004;
  
  return CONCAT44(in_stack_00000004,in_stack_00000004) & 0xffffffff000000c0 | 0x8000000000;
}


// ===== FUN_2015688c @ 2015688c (16 bytes)

undefined8 FUN_2015688c(undefined4 param_1)

{
  software_interrupt(0);
  return CONCAT44(param_1,FUN_2015689c);
}


// ===== FUN_2015689c @ 2015689c (20 bytes)

uint FUN_2015689c(void)

{
  uint in_stack_00000004;
  
  return in_stack_00000004 & 0xffffff3f;
}


// ===== FUN_201568b8 @ 201568b8 (12 bytes)

code * FUN_201568b8(void)

{
  software_interrupt(0);
  return FUN_201568c4;
}


// ===== FUN_201568c4 @ 201568c4 (28 bytes)

undefined8 FUN_201568c4(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 in_stack_00000004;
  
  uVar1 = coproc_movefrom_Control();
  if ((uVar1 & 0x2000000) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x200;
  }
  return CONCAT44(in_stack_00000004,uVar2);
}


// ===== FUN_201568e0 @ 201568e0 (76 bytes)

/* WARNING: Removing unreachable block (ram,0x20156900) */
/* WARNING: Removing unreachable block (ram,0x201568ec) */
/* WARNING: Removing unreachable block (ram,0x20156924) */

undefined8 FUN_201568e0(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}


// ===== FUN_201569c0 @ 201569c0 (228 bytes)

undefined8 FUN_201569c0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = param_1 << 1;
  uVar4 = param_2 << 0xb;
  uVar2 = param_1 << 0xb | param_2 >> 0x15;
  uVar1 = (param_1 & 0x7fffffff) >> 0x13;
  if (iVar5 != 0 || param_2 != 0) {
    uVar1 = uVar1 + 0x7800;
  }
  uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0x1f | uVar1 >> 1;
  if (iVar5 != 0 || param_2 != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if (iVar5 >> 0x15 != 0) {
    if (iVar5 >> 0x15 == -1) {
      uVar1 = uVar1 | 0x40000000;
    }
    return CONCAT44(uVar2,uVar1);
  }
  if ((uVar2 & 0x80000000) == 0) {
    return CONCAT44(uVar2,uVar1);
  }
  uVar3 = uVar2 & 0x7fffffff;
  if (uVar3 == 0) {
    if ((param_2 & 0x1fffff) >> 5 == 0) {
      uVar4 = param_2 << 0x1b;
      iVar5 = 0x10;
    }
    else {
      iVar5 = 0;
    }
    if (uVar4 >> 0x18 == 0) {
      uVar4 = uVar4 << 8;
      iVar5 = iVar5 + 8;
    }
    if (uVar4 >> 0x1c == 0) {
      uVar4 = uVar4 << 4;
      iVar5 = iVar5 + 4;
    }
    if (uVar4 >> 0x1e == 0) {
      uVar4 = uVar4 << 2;
      iVar5 = iVar5 + 2;
    }
    if (-1 < (int)uVar4) {
      uVar4 = uVar4 << 1;
      iVar5 = iVar5 + 1;
    }
    return CONCAT44(uVar4,(uVar1 - 0x1f) - iVar5);
  }
  if (uVar3 >> 0x10 == 0) {
    uVar3 = uVar2 << 0x10;
    iVar5 = 0x10;
  }
  else {
    iVar5 = 0;
  }
  if (uVar3 >> 0x18 == 0) {
    uVar3 = uVar3 << 8;
    iVar5 = iVar5 + 8;
  }
  if (uVar3 >> 0x1c == 0) {
    uVar3 = uVar3 << 4;
    iVar5 = iVar5 + 4;
  }
  if (uVar3 >> 0x1e == 0) {
    uVar3 = uVar3 << 2;
    iVar5 = iVar5 + 2;
  }
  if (-1 < (int)uVar3) {
    uVar3 = uVar3 << 1;
    iVar5 = iVar5 + 1;
  }
  return CONCAT44(uVar3 | uVar4 >> (0x20U - iVar5 & 0xff),(uVar1 - iVar5) + 1);
}


// ===== FUN_20156aa4 @ 20156aa4 (696 bytes)

ulonglong FUN_20156aa4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_r4;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  
  param_1 = param_1 ^ param_4;
  uVar2 = param_1 & 0x80000000;
  uVar17 = unaff_r5 >> 0x10;
  uVar8 = unaff_r4 >> 0x10;
  uVar22 = unaff_r5 & ~(uVar17 << 0x10);
  uVar16 = unaff_r4 & ~(uVar8 << 0x10);
  uVar10 = (uint)*(byte *)((unaff_r4 >> 0x18) + 0x20156cdc);
  uVar3 = (uint)((param_2 & 1) != 0) << 0x1f | param_3 >> 1;
  iVar11 = ((0x800000 - (uVar8 * uVar10 + uVar10)) * uVar10 >> 0x13) + 2;
  uVar18 = 0x20000000 - ((unaff_r4 >> 0xd) * iVar11 + iVar11);
  uVar10 = uVar18 >> 0x10;
  uVar10 = uVar10 * iVar11 + ((uVar18 & ~(uVar10 << 0x10)) * iVar11 >> 0x10) >> 6;
  if ((param_3 & 1) == 0) {
    uVar2 = 0;
  }
  if ((param_3 & 1) != 0) {
    uVar2 = 0x80000000;
  }
  uVar19 = uVar10 * (param_2 >> 0x10) >> 0x10;
  uVar4 = uVar3 - uVar19 * uVar17;
  uVar18 = uVar19 * uVar22;
  bVar23 = uVar18 * 0x10000 <= uVar2;
  uVar2 = uVar2 + uVar18 * -0x10000;
  uVar18 = uVar18 >> 0x10;
  bVar1 = uVar4 - uVar18 < (uint)bVar23;
  bVar24 = uVar18 < uVar4 || bVar1;
  uVar5 = (uVar4 - uVar18) - (uint)!bVar23;
  uVar12 = uVar19 * uVar16;
  if (uVar18 < uVar4 || bVar1) {
    bVar24 = uVar12 * 0x10000 <= uVar5;
  }
  uVar5 = uVar5 + uVar12 * -0x10000;
  uVar18 = ((((param_2 >> 1) - uVar8 * uVar19) - (uint)(uVar3 < uVar19 * uVar17)) - (uVar12 >> 0x10)
           ) - (uint)!bVar24;
  uVar20 = uVar10 * (uVar18 >> 2) >> 0x10;
  uVar3 = uVar20 * uVar17;
  bVar23 = uVar3 * 0x80000 <= uVar2;
  uVar2 = uVar2 + uVar3 * -0x80000;
  uVar3 = uVar3 >> 0xd;
  bVar1 = uVar5 - uVar3 < (uint)bVar23;
  bVar24 = uVar3 < uVar5 || bVar1;
  uVar4 = (uVar5 - uVar3) - (uint)!bVar23;
  uVar12 = uVar8 * uVar20;
  if (uVar3 < uVar5 || bVar1) {
    bVar24 = uVar12 * 0x80000 <= uVar4;
  }
  uVar4 = uVar4 + uVar12 * -0x80000;
  uVar5 = uVar20 * uVar22;
  bVar25 = uVar5 * 8 <= uVar2;
  uVar3 = uVar5 >> 0x1d;
  bVar1 = uVar4 - uVar3 < (uint)bVar25;
  bVar23 = uVar3 < uVar4 || bVar1;
  uVar6 = (uVar4 - uVar3) - (uint)!bVar25;
  uVar13 = uVar20 * uVar16;
  if (uVar3 < uVar4 || bVar1) {
    bVar23 = uVar13 * 8 <= uVar6;
  }
  uVar6 = uVar6 + uVar13 * -8;
  uVar3 = ((((uVar18 - (uVar12 >> 0xd)) - (uint)!bVar24) - (uVar13 >> 0x1d)) - (uint)!bVar23) *
          0x4000000 | uVar6 >> 6;
  uVar13 = uVar10 * (uVar3 >> 0xf);
  uVar18 = uVar6 * 0x4000000 | uVar2 + uVar5 * -8 >> 6;
  uVar5 = uVar5 * -0x20000000;
  uVar21 = uVar13 >> 0x10;
  uVar4 = uVar18 - uVar21 * uVar17;
  uVar2 = uVar21 * uVar22;
  bVar23 = uVar2 * 0x10000 <= uVar5;
  uVar5 = uVar5 + uVar2 * -0x10000;
  uVar2 = uVar2 >> 0x10;
  bVar1 = uVar4 - uVar2 < (uint)bVar23;
  bVar24 = uVar2 < uVar4 || bVar1;
  uVar12 = (uVar4 - uVar2) - (uint)!bVar23;
  uVar6 = uVar21 * uVar16;
  if (uVar2 < uVar4 || bVar1) {
    bVar24 = uVar6 * 0x10000 <= uVar12;
  }
  uVar12 = uVar12 + uVar6 * -0x10000;
  uVar3 = (((uVar3 - uVar8 * uVar21) - (uint)(uVar18 < uVar21 * uVar17)) - (uVar6 >> 0x10)) -
          (uint)!bVar24;
  uVar6 = uVar10 * (uVar3 >> 2) >> 0x10;
  uVar2 = uVar6 * uVar17;
  bVar23 = uVar2 * 0x80000 <= uVar5;
  uVar5 = uVar5 + uVar2 * -0x80000;
  uVar2 = uVar2 >> 0xd;
  bVar1 = uVar12 - uVar2 < (uint)bVar23;
  bVar24 = uVar2 < uVar12 || bVar1;
  uVar18 = (uVar12 - uVar2) - (uint)!bVar23;
  uVar4 = uVar8 * uVar6;
  if (uVar2 < uVar12 || bVar1) {
    bVar24 = uVar4 * 0x80000 <= uVar18;
  }
  uVar18 = uVar18 + uVar4 * -0x80000;
  uVar12 = uVar6 * uVar22;
  bVar25 = uVar12 * 8 <= uVar5;
  uVar2 = uVar12 >> 0x1d;
  bVar1 = uVar18 - uVar2 < (uint)bVar25;
  bVar23 = uVar2 < uVar18 || bVar1;
  uVar7 = (uVar18 - uVar2) - (uint)!bVar25;
  uVar14 = uVar6 * uVar16;
  if (uVar2 < uVar18 || bVar1) {
    bVar23 = uVar14 * 8 <= uVar7;
  }
  uVar7 = uVar7 + uVar14 * -8;
  uVar9 = uVar21 * 0x400000 + uVar6 * 0x200;
  uVar18 = ((((uVar3 - (uVar4 >> 0xd)) - (uint)!bVar24) - (uVar14 >> 0x1d)) - (uint)!bVar23) *
           0x4000000 | uVar7 >> 6;
  uVar4 = uVar7 * 0x4000000 | uVar5 + uVar12 * -8 >> 6;
  uVar10 = uVar10 * (uVar18 >> 0xf);
  uVar12 = uVar12 * -0x20000000;
  uVar14 = uVar10 >> 0x10;
  uVar5 = uVar4 - uVar14 * uVar17;
  uVar3 = uVar14 * uVar22;
  bVar23 = uVar3 * 0x10000 <= uVar12;
  uVar2 = uVar3 >> 0x10;
  bVar1 = uVar5 - uVar2 < (uint)bVar23;
  bVar24 = uVar2 < uVar5 || bVar1;
  uVar7 = (uVar5 - uVar2) - (uint)!bVar23;
  uVar15 = uVar14 * uVar16;
  if (uVar2 < uVar5 || bVar1) {
    bVar24 = uVar15 * 0x10000 <= uVar7;
  }
  uVar7 = uVar7 + uVar15 * -0x10000;
  uVar10 = uVar10 >> 0x14;
  uVar5 = uVar9 + uVar10;
  uVar4 = ((((uVar18 - uVar8 * uVar14) - (uint)(uVar4 < uVar14 * uVar17)) - (uVar15 >> 0x10)) -
          (uint)!bVar24) * 0x4000 | uVar7 >> 0x12;
  uVar2 = uVar7 * 0x4000 | uVar12 + uVar3 * -0x10000 >> 0x12;
  uVar18 = uVar3 * -0x40000000;
  uVar14 = uVar14 << 0x1c;
  uVar16 = uVar16 | uVar8 << 0x10;
  uVar22 = uVar22 | uVar17 << 0x10;
  bVar1 = uVar4 - uVar16 < (uint)(uVar22 <= uVar2);
  uVar8 = uVar4;
  if (uVar16 < uVar4 || bVar1) {
    uVar8 = (uVar4 - uVar16) - (uint)(uVar22 > uVar2);
    uVar2 = uVar2 - uVar22;
  }
  uVar3 = uVar3 * -0x80000000;
  bVar23 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)CARRY4(uVar18,uVar18));
  uVar2 = uVar2 * 2 + (uint)CARRY4(uVar18,uVar18);
  bVar24 = CARRY4(uVar8 * 2,(uint)bVar23);
  bVar25 = CARRY4(uVar8,uVar8) || bVar24;
  uVar17 = uVar8 * 2 + (uint)bVar23;
  bVar23 = bVar25 < (uVar16 < uVar17 || uVar17 - uVar16 < (uint)(uVar22 <= uVar2));
  if ((CARRY4(uVar8,uVar8) || bVar24) || bVar23) {
    uVar17 = (uVar17 - uVar16) - (uint)(uVar22 > uVar2);
    uVar2 = uVar2 - uVar22;
  }
  bVar26 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)CARRY4(uVar3,uVar3));
  uVar2 = uVar2 * 2 + (uint)CARRY4(uVar3,uVar3);
  bVar24 = CARRY4(uVar17 * 2,(uint)bVar26);
  bVar27 = CARRY4(uVar17,uVar17) || bVar24;
  uVar3 = uVar17 * 2 + (uint)bVar26;
  bVar26 = bVar27 < (uVar16 < uVar3 || uVar3 - uVar16 < (uint)(uVar22 <= uVar2));
  if ((CARRY4(uVar17,uVar17) || bVar24) || bVar26) {
    uVar3 = (uVar3 - uVar16) - (uint)(uVar22 > uVar2);
    uVar2 = uVar2 - uVar22;
  }
  if (uVar3 != 0 || uVar2 != 0) {
    uVar14 = uVar14 | 1;
  }
  uVar2 = (((uint)(uVar16 < uVar4 || bVar1) * 2 + (uint)(bVar25 || bVar23)) * 2 +
          (uint)(bVar27 || bVar26)) * 0x10000000;
  uVar3 = uVar5 + CARRY4(uVar14,uVar2);
  iVar11 = uVar19 * 0x10000 + uVar20 * 8 + (uVar13 >> 0x1a) +
           (uint)CARRY4(uVar21 * 0x400000,uVar6 * 0x200) + (uint)CARRY4(uVar9,uVar10) +
           (uint)CARRY4(uVar5,(uint)CARRY4(uVar14,uVar2));
  if (-1 < iVar11) {
    return CONCAT44(iVar11 * 2 +
                    (uint)(CARRY4(uVar3,uVar3) ||
                          CARRY4(uVar3 * 2,(uint)CARRY4(uVar14 + uVar2,uVar14 + uVar2))),param_1) &
           0xffffffff80000000;
  }
  return CONCAT44(iVar11,param_1) & 0xffffffff80000000;
}


// ===== FUN_20156ddc @ 20156ddc (198 bytes)

undefined8 FUN_20156ddc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint unaff_r6;
  int unaff_r11;
  bool bVar3;
  
  if ((int)param_4 < 0) {
    unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10;
    if ((int)param_4 < -0x3f) {
      unaff_r6 = (unaff_r6 | param_3 | (unaff_r6 | param_3) << 0x10) >> 0x10 | param_2;
      if ((int)param_4 < -0x40) {
        unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10;
      }
      param_4 = 0;
      param_3 = 0;
      param_2 = 0;
    }
    else {
      uVar2 = param_4;
      if ((int)param_4 < -0x1f) {
        unaff_r6 = unaff_r6 | param_3;
        uVar2 = param_4 + 0x20;
        param_2 = 0;
        param_3 = param_2;
      }
      uVar1 = -uVar2;
      param_4 = 0;
      if (uVar1 != 0) {
        unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10 | param_3 << (uVar2 + 0x20 & 0xff);
        uVar2 = param_2 << (uVar2 + 0x20 & 0xff);
        param_2 = param_2 >> (uVar1 & 0xff);
        param_4 = 0;
        param_3 = param_3 >> (uVar1 & 0xff) | uVar2;
      }
    }
  }
  if (((unaff_r6 & 0x7fffffff) != 0) || ((unaff_r6 & 0x80000000) != 0)) {
    bVar3 = unaff_r11 != -1 && 0xfffffffe < param_3;
    if (unaff_r11 != -1 && 0xfffffffe < param_3) {
      bVar3 = 0xfffffffe < param_2;
      param_2 = param_2 + 1;
    }
    if (bVar3 != false) {
      param_2 = 0x80000000;
    }
    param_4 = param_4 + bVar3;
  }
  return CONCAT44(param_2,param_4 | param_1 & 0x80000000);
}


// ===== FUN_20156ea2 @ 20156ea2 (40 bytes)

void FUN_20156ea2(int *param_1,int *param_2)

{
  if ((param_1[1] & ~(*param_1 << 1)) < 0 && (param_2[1] & ~(*param_2 << 1)) < 0) {
    FUN_20156aa4(*param_1,param_1[1],param_1[2]);
    FUN_20156ddc();
  }
  return;
}


// ===== FUN_20156eca @ 20156eca (40 bytes)

void FUN_20156eca(uint *param_1,uint *param_2)

{
  if ((*param_1 & 0x40000000) == 0 && (*param_2 & 0x40000000) == 0) {
    FUN_20156ef2(*param_1,param_1[1],param_1[2]);
    FUN_20156ddc();
  }
  return;
}


// ===== FUN_20156ef2 @ 20156ef2 (580 bytes)

ulonglong FUN_20156ef2(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r4;
  uint unaff_r5;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  bool bVar19;
  
  param_1 = param_1 ^ param_4;
  if (param_3 == 0) {
    if (unaff_r5 == 0) {
      uVar5 = unaff_r4 >> 0x10;
      uVar6 = param_2 >> 0x10;
      uVar14 = unaff_r4 & ~(uVar5 << 0x10);
      param_2 = param_2 & ~(uVar6 << 0x10);
      uVar7 = uVar14 * uVar6;
      uVar14 = param_2 * uVar14;
      param_2 = uVar5 * param_2;
      uVar3 = uVar7 * 0x10000;
      uVar1 = uVar14 + uVar3;
      uVar2 = param_2 * 0x10000;
      uVar4 = uVar1 + uVar2;
      iVar8 = uVar5 * uVar6 + (uVar7 >> 0x10) + (uint)CARRY4(uVar14,uVar3) +
              (param_2 >> 0x10) + (uint)CARRY4(uVar1,uVar2);
      if (-1 < iVar8) {
        return CONCAT44(iVar8 * 2 + (uint)CARRY4(uVar4,uVar4),param_1) & 0xffffffff80000000;
      }
      return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
    }
    uVar4 = param_2 >> 0x10;
    uVar12 = unaff_r4 >> 0x10;
    param_2 = param_2 & ~(uVar4 << 0x10);
    uVar15 = unaff_r4 & ~(uVar12 << 0x10);
    uVar5 = uVar15 * param_2;
    uVar15 = uVar4 * uVar15;
    uVar3 = param_2 * uVar12 * 0x10000;
    uVar6 = uVar5 + uVar3;
    uVar13 = unaff_r5 >> 0x10;
    uVar2 = uVar15 * 0x10000;
    uVar7 = uVar6 + uVar2;
    uVar16 = unaff_r5 & ~(uVar13 << 0x10);
    uVar9 = uVar16 * param_2;
    uVar16 = uVar4 * uVar16;
    uVar14 = param_2 * uVar13 * 0x10000;
    uVar10 = uVar9 + uVar14;
    uVar1 = uVar16 * 0x10000;
    uVar11 = uVar10 + uVar1;
    uVar14 = uVar4 * uVar13 + (param_2 * uVar13 >> 0x10) + (uint)CARRY4(uVar9,uVar14) +
             (uVar16 >> 0x10) + (uint)CARRY4(uVar10,uVar1);
    uVar1 = uVar14 + uVar7;
    iVar8 = uVar4 * uVar12 + (param_2 * uVar12 >> 0x10) + (uint)CARRY4(uVar5,uVar3) +
            (uVar15 >> 0x10) + (uint)CARRY4(uVar6,uVar2) + (uint)CARRY4(uVar14,uVar7);
    if (-1 < iVar8) {
      return CONCAT44(iVar8 * 2 +
                      (uint)(CARRY4(uVar1,uVar1) || CARRY4(uVar1 * 2,(uint)CARRY4(uVar11,uVar11))),
                      param_1) & 0xffffffff80000000;
    }
    return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
  }
  if (unaff_r5 == 0) {
    uVar7 = unaff_r4 >> 0x10;
    uVar13 = param_2 >> 0x10;
    uVar9 = unaff_r4 & ~(uVar7 << 0x10);
    param_2 = param_2 & ~(uVar13 << 0x10);
    uVar4 = param_2 * uVar9;
    param_2 = uVar7 * param_2;
    uVar3 = uVar9 * uVar13 * 0x10000;
    uVar5 = uVar4 + uVar3;
    uVar15 = param_3 >> 0x10;
    uVar2 = param_2 * 0x10000;
    uVar6 = uVar5 + uVar2;
    param_3 = param_3 & ~(uVar15 << 0x10);
    uVar10 = param_3 * uVar9;
    param_3 = uVar7 * param_3;
    uVar14 = uVar9 * uVar15 * 0x10000;
    uVar11 = uVar10 + uVar14;
    uVar1 = param_3 * 0x10000;
    uVar12 = uVar11 + uVar1;
    uVar1 = uVar7 * uVar15 + (uVar9 * uVar15 >> 0x10) + (uint)CARRY4(uVar10,uVar14) +
            (param_3 >> 0x10) + (uint)CARRY4(uVar11,uVar1);
    uVar14 = uVar1 + uVar6;
    iVar8 = uVar7 * uVar13 + (uVar9 * uVar13 >> 0x10) + (uint)CARRY4(uVar4,uVar3) +
            (param_2 >> 0x10) + (uint)CARRY4(uVar5,uVar2) + (uint)CARRY4(uVar1,uVar6);
    if (-1 < iVar8) {
      return CONCAT44(iVar8 * 2 +
                      (uint)(CARRY4(uVar14,uVar14) || CARRY4(uVar14 * 2,(uint)CARRY4(uVar12,uVar12))
                            ),param_1) & 0xffffffff80000000;
    }
    return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
  }
  uVar1 = param_2 >> 0x10;
  uVar4 = unaff_r4 >> 0x10;
  uVar11 = param_2 & ~(uVar1 << 0x10);
  uVar9 = unaff_r4 & ~(uVar4 << 0x10);
  uVar5 = uVar11 * uVar4;
  uVar11 = uVar9 * uVar11;
  uVar9 = uVar1 * uVar9;
  uVar3 = uVar5 * 0x10000;
  uVar12 = uVar11 + uVar3;
  uVar15 = param_3 >> 0x10;
  uVar2 = uVar9 * 0x10000;
  uVar13 = uVar12 + uVar2;
  uVar6 = unaff_r5 >> 0x10;
  uVar16 = param_3 & ~(uVar15 << 0x10);
  uVar10 = unaff_r5 & ~(uVar6 << 0x10);
  uVar7 = uVar16 * uVar6;
  uVar16 = uVar10 * uVar16;
  uVar10 = uVar15 * uVar10;
  uVar14 = uVar7 * 0x10000;
  uVar17 = uVar16 + uVar14;
  uVar7 = uVar15 * uVar6 + (uVar7 >> 0x10) + (uint)CARRY4(uVar16,uVar14);
  iVar8 = 0;
  uVar14 = uVar10 * 0x10000;
  uVar15 = uVar17 + uVar14;
  uVar6 = uVar7 + (uVar10 >> 0x10) + (uint)CARRY4(uVar17,uVar14);
  uVar14 = uVar13 + uVar6;
  uVar2 = uVar1 * uVar4 + (uVar5 >> 0x10) + (uint)CARRY4(uVar11,uVar3) +
          (uVar9 >> 0x10) + (uint)CARRY4(uVar12,uVar2) + (uint)CARRY4(uVar13,uVar6);
  uVar4 = uVar14 + uVar15;
  uVar1 = uVar14 + uVar2 + CARRY4(uVar14,uVar15);
  bVar19 = param_3 <= param_2;
  param_2 = param_2 - param_3;
  bVar18 = param_2 == 0;
  uVar3 = 0;
  if (!bVar19) {
    uVar3 = 0xffffffff;
    iVar8 = unaff_r4 - unaff_r5;
  }
  if (!bVar18) {
    bVar19 = unaff_r4 <= unaff_r5;
    uVar7 = unaff_r5 - unaff_r4;
    bVar18 = uVar7 == 0;
  }
  if (bVar18) {
    uVar3 = 0;
  }
  if (!bVar19) {
    uVar3 = ~uVar3;
    iVar8 = iVar8 - param_2;
  }
  uVar9 = param_2 >> 0x10;
  param_2 = param_2 & ~(uVar9 << 0x10);
  uVar12 = uVar7 >> 0x10;
  uVar7 = uVar7 & ~(uVar12 << 0x10);
  uVar13 = param_2 * uVar12;
  param_2 = uVar7 * param_2;
  uVar7 = uVar9 * uVar7;
  uVar5 = uVar13 * 0x10000;
  uVar10 = param_2 + uVar5;
  uVar6 = uVar7 * 0x10000;
  uVar11 = uVar10 + uVar6;
  uVar5 = uVar9 * uVar12 + iVar8 + (uVar13 >> 0x10) + (uint)CARRY4(param_2,uVar5) +
          (uVar7 >> 0x10) + (uint)CARRY4(uVar10,uVar6);
  uVar6 = uVar1 + uVar5 + CARRY4(uVar4,uVar11);
  iVar8 = uVar3 + uVar2 + (CARRY4(uVar14,uVar2) ||
                          CARRY4(uVar14 + uVar2,(uint)CARRY4(uVar14,uVar15))) +
          (uint)(CARRY4(uVar1,uVar5) || CARRY4(uVar1 + uVar5,(uint)CARRY4(uVar4,uVar11)));
  uVar3 = uVar4 + uVar11 | (uVar15 | uVar15 * 4) >> 2;
  if (-1 < iVar8) {
    return CONCAT44(iVar8 * 2 +
                    (uint)(CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)CARRY4(uVar3,uVar3))),
                    param_1) & 0xffffffff80000000;
  }
  return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
}


// ===== FUN_20157138 @ 20157138 (20 bytes)

void FUN_20157138(byte *param_1,int param_2,uint param_3,byte param_4)

{
  *param_1 = *param_1 & ~param_4 | (byte)(param_2 << (param_3 & 0xff));
  return;
}


// ===== FUN_2015714c @ 2015714c (20 bytes)

void FUN_2015714c(ushort *param_1,int param_2,uint param_3,ushort param_4)

{
  *param_1 = *param_1 & ~param_4 | (ushort)(param_2 << (param_3 & 0xff));
  return;
}


// ===== FUN_20157160 @ 20157160 (20 bytes)

void FUN_20157160(uint *param_1,int param_2,uint param_3,uint param_4)

{
  *param_1 = *param_1 & ~param_4 | param_2 << (param_3 & 0xff);
  return;
}


// ===== FUN_20157174 @ 20157174 (16 bytes)

uint FUN_20157174(byte *param_1,uint param_2,uint param_3)

{
  return (*param_1 & param_3) >> (param_2 & 0xff);
}


// ===== FUN_20157184 @ 20157184 (16 bytes)

uint FUN_20157184(ushort *param_1,uint param_2,uint param_3)

{
  return (*param_1 & param_3) >> (param_2 & 0xff);
}


// ===== FUN_201571a4 @ 201571a4 (12 bytes)

void FUN_201571a4(undefined4 *param_1)

{
  FUN_20151c3c(*param_1,0xffffffff);
  return;
}


// ===== FUN_201571b0 @ 201571b0 (8 bytes)

void FUN_201571b0(undefined4 *param_1)

{
  FUN_20152df4(*param_1);
  return;
}


// ===== FUN_201571b8 @ 201571b8 (28 bytes)

undefined4 * FUN_201571b8(undefined4 *param_1,undefined4 param_2,int param_3)

{
  *param_1 = param_2;
  if (param_3 != 0) {
    FUN_201571a4();
  }
  return param_1;
}


// ===== FUN_201571d4 @ 201571d4 (20 bytes)

undefined4 FUN_201571d4(undefined4 param_1)

{
  FUN_201571b0();
  return param_1;
}


// ===== FUN_20157214 @ 20157214 (36 bytes)

void FUN_20157214(undefined4 param_1,uint *param_2,uint *param_3,uint param_4)

{
  for (param_4 = param_4 >> 2; param_4 != 0; param_4 = param_4 - 1) {
    *param_2 = ~*param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== FUN_201572f8 @ 201572f8 (12 bytes)

void FUN_201572f8(int param_1)

{
  *(undefined1 *)(param_1 + 0xb59) = 0;
  memclr(param_1 + 0xb60,0x13178);
  *(undefined4 *)(param_1 + 0x13cd8) = 0;
  return;
}


// ===== FUN_201574e8 @ 201574e8 (92 bytes)

undefined4 FUN_201574e8(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_1a0 [200];
  byte local_d8 [204];
  
  FUN_20157214(param_1,auStack_1a0,param_1 + 0x900,200);
  FUN_20134084(local_d8,auStack_1a0);
  iVar1 = 0;
  do {
    *(undefined1 *)(param_4 + iVar1) = *(undefined1 *)((uint)local_d8[iVar1] + param_1 + 0x400);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 200);
  return 0x2c;
}


// ===== FUN_201575f8 @ 201575f8 (24 bytes)

void FUN_201575f8(int param_1)

{
  *(undefined1 *)(param_1 + 0xb59) = 0;
  memclr(param_1 + 0xb60,0x13178);
  *(undefined4 *)(param_1 + 0x13cd8) = 0;
  return;
}


// ===== FUN_2015760c @ 2015760c (32 bytes)

void FUN_2015760c(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + param_3);
  *puVar1 = param_2;
  puVar1[-0x4c5f] = puVar1 + -0x4cf6;
  return;
}


// ===== FUN_20157634 @ 20157634 (188 bytes)

void FUN_20157634(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  do {
    *(undefined1 *)(param_1 + iVar3) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  uVar4 = (uint)*param_3;
  param_2 = param_2 * 10000;
  uVar2 = (uint)param_3[1];
  if (uVar4 <= uVar2) {
    do {
      bVar1 = *param_3;
      iVar3 = __aeabi_uidivmod(param_2,(uVar2 - bVar1) + 1);
      iVar3 = iVar3 * ((uVar4 - bVar1) + 1) + 0x26ac;
      *(char *)(param_1 + uVar4) =
           ((char)(iVar3 / 10000) + (char)(iVar3 >> 0x1f)) -
           (char)((longlong)iVar3 * 0x68db8bad >> 0x3f);
      uVar4 = uVar4 + 1;
      uVar2 = (uint)param_3[1];
    } while ((int)uVar4 <= (int)uVar2);
  }
  uVar2 = uVar2 + 1;
  if (uVar2 < 0x100) {
    do {
      *(char *)(param_1 + uVar2) =
           ((char)(param_2 / 10000) + (char)(param_2 >> 0x1f)) -
           (char)((longlong)param_2 * 0x68db8bad >> 0x3f);
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x100);
  }
  return;
}


// ===== FUN_201576f4 @ 201576f4 (108 bytes)

void FUN_201576f4(int param_1,int param_2)

{
  if (param_2 == 0) {
    memclr(param_1 + 0x1b130,0x33f40);
    FUN_201643a4(param_1 + 0x82fb4);
    DAT_20450280 = 0;
  }
  else {
    if (param_2 != 1) {
      memclr(param_1 + 0x1b130,0x67e80);
      FUN_201643a4(param_1 + 0x82fb4);
      FUN_201643a4(param_1 + 0x82fb0);
      return;
    }
    DAT_20450280 = 1;
  }
  return;
}


// ===== FUN_20157778 @ 20157778 (116 bytes)

/* WARNING: Removing unreachable block (ram,0x201552fe) */
/* WARNING: Removing unreachable block (ram,0x201552f4) */
/* WARNING: Removing unreachable block (ram,0x201552fc) */
/* WARNING: Removing unreachable block (ram,0x20155302) */
/* WARNING: Removing unreachable block (ram,0x20155308) */
/* WARNING: Removing unreachable block (ram,0x2015530c) */

undefined4 * FUN_20157778(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  
  FUN_2015525c(param_1 + 0x9c7f,0x352,0xff);
  FUN_2015525c(param_1 + 0x9fd1,0x352,0xff);
  memclr(param_1 + 0x10abc,0x6798);
  FUN_20155274(param_1 + 0xa323,24000);
  memclr(param_1 + 0x17258,0x3ed4);
  puVar1 = (undefined4 *)(param_1 + 0x100e4);
  bVar3 = true;
  uVar2 = 0x9b8;
  do {
    if (bVar3) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1 = puVar1 + 8;
      bVar3 = 0x1f < uVar2;
      uVar2 = uVar2 - 0x20;
    }
  } while (bVar3);
  if ((uVar2 & 0x10) != 0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1 = puVar1 + 4;
  }
  if ((int)(uVar2 << 0x1c) < 0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
  }
  return puVar1;
}


// ===== FUN_201577f8 @ 201577f8 (36 bytes)

void FUN_201577f8(undefined4 param_1,uint *param_2,uint *param_3,uint param_4)

{
  for (param_4 = param_4 >> 2; param_4 != 0; param_4 = param_4 - 1) {
    *param_2 = ~*param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== FUN_201578c8 @ 201578c8 (40 bytes)

void FUN_201578c8(int param_1)

{
  *(undefined1 *)(param_1 + 0x9c7e) = 0;
  FUN_20157778();
  FUN_201576f4(param_1,0);
  return;
}


// ===== FUN_20157c50 @ 20157c50 (232 bytes)

undefined4 FUN_20157c50(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = param_1 + 0x9c98;
  if (DAT_20800498 == '\0') {
    memcpy(param_1 + 0x9fd1,param_1 + 0x9c7f,0x352,param_4,param_4);
  }
  else {
    if (param_2 != 8 && param_2 != 9) goto LAB_20157cc4;
    iVar1 = param_1 + 0x9fea;
  }
  if (param_2 == 8) {
    FUN_201633a0(param_1,param_3,iVar1,param_4,0xff);
    return DAT_20473b78;
  }
  if (param_2 == 9) {
    FUN_201633a0(param_1 + 0x1e00,param_3,iVar1,param_4,0xff);
    return DAT_20474c64;
  }
LAB_20157cc4:
  FUN_201633a0(param_1 + 0x2d00,param_3,iVar1,param_4,0xff);
  return DAT_2047032c;
}


// ===== FUN_20157f8c @ 20157f8c (124 bytes)

void FUN_20157f8c(int param_1)

{
  int iVar1;
  
  if (((*(char *)(param_1 + 0x9c7c) == '\0') && (*(char *)(param_1 + 0x9c7d) == '\0')) &&
     (*(char *)(param_1 + 0x9c7e) == '\0')) {
    FUN_201643b0();
    iVar1 = FUN_201647e4(param_1 + 0x1b12c,0);
    FUN_201577f8(param_1,param_1 + iVar1 * 800 + 0x17258,param_1 + 0x9c98,800);
    return;
  }
  return;
}


// ===== FUN_201584f8 @ 201584f8 (88 bytes)

void FUN_201584f8(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined2 *)(param_1 + 0x2e00) = 0xff38;
    *(undefined2 *)(param_1 + 0x3006) = 0xff38;
    *(undefined2 *)(param_1 + 0x3208) = 0xff38;
  }
  else {
    *(undefined2 *)(param_1 + 0x2e00) = 0xaf4c;
    *(undefined2 *)(param_1 + 0x3006) = 0xaf4c;
    *(undefined2 *)(param_1 + 0x3208) = 0xaf4c;
  }
  FUN_20157634(param_1 + 0x2d00,*(undefined1 *)(param_1 + 0x2e04),param_1 + 0x2e00);
  return;
}


// ===== FUN_20158544 @ 20158544 (136 bytes)

void FUN_20158544(int param_1,int param_2)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (param_2 == 0) {
    puVar1 = &DAT_204282a0;
  }
  else {
    puVar1 = &DAT_2042829c;
  }
  *(undefined2 *)(param_1 + 0x2e02) = *puVar1;
  iVar2 = 0;
  do {
    FUN_20157634(param_1 + iVar2 * 0x100,*(undefined2 *)(DAT_20450278 + iVar2 * 2),param_1 + 0x2e02)
    ;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1e);
  iVar2 = 0;
  do {
    FUN_20157634(param_1 + iVar2 * 0x100 + 0x1e00,*(undefined2 *)(DAT_2045027c + iVar2 * 2),
                 param_1 + 0x2e02);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xf);
  return;
}


// ===== FUN_20158568 @ 20158568 (40 bytes)

void FUN_20158568(int param_1)

{
  *(undefined1 *)(param_1 + 0x9c7e) = 0;
  FUN_20157778();
  FUN_201576f4(param_1,1);
  return;
}


// ===== FUN_20158598 @ 20158598 (96 bytes)

undefined4 * FUN_20158598(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + param_3);
  *puVar1 = param_2;
  puVar1[0xfb6] = 0;
  puVar1[0x1af57] = 0;
  puVar1[0x1af58] = 0;
  return puVar1 + -0x5c95;
}


// ===== FUN_20158618 @ 20158618 (24 bytes)

/* WARNING: Removing unreachable block (ram,0x201552fe) */
/* WARNING: Removing unreachable block (ram,0x201552f4) */
/* WARNING: Removing unreachable block (ram,0x201552e4) */
/* WARNING: Removing unreachable block (ram,0x201552ea) */
/* WARNING: Removing unreachable block (ram,0x201552fc) */
/* WARNING: Removing unreachable block (ram,0x20155302) */
/* WARNING: Removing unreachable block (ram,0x20155308) */
/* WARNING: Removing unreachable block (ram,0x2015530c) */

undefined4 * FUN_20158618(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  puVar1 = (undefined4 *)(param_1 + 8);
  bVar3 = true;
  uVar2 = 0x60;
  do {
    if (bVar3) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1 = puVar1 + 8;
      bVar3 = 0x1f < uVar2;
      uVar2 = uVar2 - 0x20;
    }
  } while (bVar3);
  return puVar1;
}


// ===== FUN_20158630 @ 20158630 (12 bytes)

undefined4 FUN_20158630(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,*(undefined4 *)(param_1 + 0x81a0),1);
  iVar1 = FUN_201643f0(param_1 + 0x811c);
  uVar2 = *(undefined4 *)(param_1 + 0x811c + iVar1 * 4 + 4);
  FUN_201571d4(&uStack_10);
  return uVar2;
}


// ===== FUN_2015863c @ 2015863c (96 bytes)

void FUN_2015863c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x18) = param_2;
  FUN_20164460();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x408;
    FUN_20158618(iVar3 + 0x1c);
    FUN_201644a0(param_1 + 0x811c,uVar2 & 0xffff,iVar3 + 0x1c);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
  uVar1 = FUN_20162d10(param_1);
  *(undefined4 *)(param_1 + 0x81a4) = uVar1;
  return;
}


// ===== FUN_2015869c @ 2015869c (16 bytes)

void FUN_2015869c(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ===== FUN_201586ac @ 201586ac (152 bytes)

void FUN_201586ac(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  FUN_2015869c();
  do {
    do {
      FUN_20152434(*(undefined4 *)(param_1 + 0x81a4),local_8,0xffffffff);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))();
    } while (iVar1 == 0);
    while( true ) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x24))
                        (*(int **)(param_1 + 0x18),local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
      if (iVar1 != 0) break;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      itron_dly_tsk(1);
    }
    FUN_20111480(local_8[0] + 8,*(undefined2 *)(local_8[0] + 6));
  } while( true );
}


// ===== FUN_20158744 @ 20158744 (100 bytes)

void FUN_20158744(int param_1,undefined4 param_2)

{
  while (DAT_20450050 != 0) {
    itron_dly_tsk(1);
  }
  FUN_20162d3c(param_1,*(undefined4 *)(param_1 + 0x81a4),param_2);
  FUN_20152bb0(DAT_20450054,0xffffffff);
  DAT_20450050 = 3;
  FUN_201511e8(DAT_20450054);
  return;
}


// ===== FUN_201587ac @ 201587ac (32 bytes)

int FUN_201587ac(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20427fac;
  iVar1 = FUN_20162c18(param_1 + 0x2047);
  return iVar1 + -0x811c;
}

