// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20156860 @ 20156860 (12 bytes)

code * FUN_20156860(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

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
  param_1[0xd] = itron_ext_tsk;
  param_1[0x11] = uVar2;
  *param_3 = (int)param_1;
  *(undefined1 *)(param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 9) = 0;
  param_3[8] = 0;
  *(undefined1 *)((int)param_3 + 5) = 0x10;
  FUN_201538d4(&DAT_208dc18c + *(char *)((int)param_3 + 0x27),param_3,param_4);
  software_interrupt(0);
  return FUN_2015677c;
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


// ===== FUN_201568b0 @ 201568b0 (4 bytes)

void FUN_201568b0(void)

{
  return;
}


// ===== FUN_201568b4 @ 201568b4 (4 bytes)

void FUN_201568b4(void)

{
  return;
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


// ===== gic_default_handler @ 201568e0 (76 bytes)

/* WARNING: Removing unreachable block (ram,0x20156900) */
/* WARNING: Removing unreachable block (ram,0x201568ec) */
/* WARNING: Removing unreachable block (ram,0x20156924) */
/* unregistered interrupt IDs */

undefined8 gic_default_handler(undefined4 param_1,undefined4 param_2)

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


// ===== reg_rmw8 @ 20157138 (20 bytes)

/* (reg, val, shift, mask): *reg = *reg & ~mask | val << shift, 8-bit [fact] */

void reg_rmw8(byte *param_1,int param_2,uint param_3,byte param_4)

{
  *param_1 = *param_1 & ~param_4 | (byte)(param_2 << (param_3 & 0xff));
  return;
}


// ===== reg_rmw16 @ 2015714c (20 bytes)

/* 16-bit read-modify-write, same arguments (spi-links.md) [fact] */

void reg_rmw16(ushort *param_1,int param_2,uint param_3,ushort param_4)

{
  *param_1 = *param_1 & ~param_4 | (ushort)(param_2 << (param_3 & 0xff));
  return;
}


// ===== reg_rmw32 @ 20157160 (20 bytes)

/* 32-bit read-modify-write, same arguments [fact] */

void reg_rmw32(uint *param_1,int param_2,uint param_3,uint param_4)

{
  *param_1 = *param_1 & ~param_4 | param_2 << (param_3 & 0xff);
  return;
}


// ===== reg_read8 @ 20157174 (16 bytes)

/* (reg, shift, mask): (*reg & mask) >> shift, 8-bit [fact] */

byte reg_read8(byte *param_1,uint param_2,uint param_3)

{
  return (byte)((*param_1 & param_3) >> (param_2 & 0xff));
}


// ===== reg_read16 @ 20157184 (16 bytes)

/* 16-bit field read (spi-links.md) [fact] */

uint reg_read16(ushort *param_1,uint param_2,uint param_3)

{
  return (*param_1 & param_3) >> (param_2 & 0xff);
}


// ===== FUN_20157194 @ 20157194 (16 bytes)

uint FUN_20157194(uint *param_1,uint param_2,uint param_3)

{
  return (*param_1 & param_3) >> (param_2 & 0xff);
}


// ===== FUN_201571a4 @ 201571a4 (12 bytes)

void FUN_201571a4(undefined4 *param_1)

{
  itron_tloc_mtx(*param_1,0xffffffff);
  return;
}


// ===== FUN_201571b0 @ 201571b0 (8 bytes)

void FUN_201571b0(undefined4 *param_1)

{
  itron_unl_mtx(*param_1);
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


// ===== FUN_201571e8 @ 201571e8 (36 bytes)

void FUN_201571e8(int param_1)

{
  __aeabi_memclr4(param_1 + 0xb60,0x13178);
  FUN_2016437c(param_1 + 0x13cd8);
  return;
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
  FUN_201571e8();
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


// ===== FUN_201575f8 @ 201575f8 (12 bytes)

void FUN_201575f8(int param_1)

{
  *(undefined1 *)(param_1 + 0xb59) = 0;
  FUN_201571e8();
  return;
}


// ===== FUN_20157604 @ 20157604 (40 bytes)

void FUN_20157604(int param_1)

{
  *(undefined4 *)(param_1 + 0x13cd8) = 0;
  *(int *)(param_1 + 0xb5c) = param_1 + 0x900;
  return;
}


// ===== FUN_20157634 @ 20157634 (188 bytes)

void FUN_20157634(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint n;
  ulonglong uVar5;
  
  iVar3 = 0;
  do {
    *(undefined1 *)(param_1 + iVar3) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  uVar4 = (uint)*param_3;
  n = param_2 * 10000;
  uVar2 = (uint)param_3[1];
  if (uVar4 <= uVar2) {
    do {
      bVar1 = *param_3;
      uVar5 = __aeabi_idivmod(n,(uVar2 - bVar1) + 1);
      iVar3 = (int)uVar5 * ((uVar4 - bVar1) + 1) + 0x26ac;
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
           ((char)((int)n / 10000) + (char)((int)n >> 0x1f)) -
           (char)((longlong)(int)n * 0x68db8bad >> 0x3f);
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x100);
  }
  return;
}


// ===== FUN_201576f4 @ 201576f4 (108 bytes)

void FUN_201576f4(int param_1,int param_2)

{
  if (param_2 == 0) {
    __aeabi_memclr4(param_1 + 0x1b130,0x33f40);
    FUN_201643a4(param_1 + 0x82fb4);
    DAT_20450280 = 0;
  }
  else {
    if (param_2 != 1) {
      __aeabi_memclr4(param_1 + 0x1b130,0x67e80);
      FUN_201643a4(param_1 + 0x82fb4);
      FUN_201643a4(param_1 + 0x82fb0);
      return;
    }
    DAT_20450280 = 1;
  }
  return;
}


// ===== FUN_20157778 @ 20157778 (116 bytes)

void FUN_20157778(int param_1)

{
  __aeabi_memset(param_1 + 0x9c7f,0x352,0xff);
  __aeabi_memset(param_1 + 0x9fd1,0x352,0xff);
  __aeabi_memclr4(param_1 + 0x10abc,0x6798);
  __aeabi_memclr(param_1 + 0xa323,24000);
  __aeabi_memclr4(param_1 + 0x17258,0x3ed4);
  __aeabi_memclr4_veneer(param_1 + 0x100e4,0x9d8);
  return;
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


// ===== FUN_20157c50 @ 20157c50 (224 bytes)

void FUN_20157c50(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

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
    FUN_201633a0(param_1,param_3,iVar1,param_4);
    FUN_20164674(0x20470330);
    return;
  }
  if (param_2 == 9) {
    FUN_201633a0(param_1 + 0x1e00,param_3,iVar1,param_4);
    FUN_20164654(0x20473b7c);
    return;
  }
LAB_20157cc4:
  FUN_201633a0(param_1 + 0x2d00,param_3,iVar1,param_4);
  FUN_2016466c(0x204702a4);
  return;
}


// ===== FUN_20157d3c @ 20157d3c (552 bytes)

void FUN_20157d3c(int param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  
  if ((((DAT_20800498 == '\0') && (*(char *)(param_1 + 0x9c7c) == '\0')) &&
      (*(char *)(param_1 + 0x9c7d) == '\0')) && (*(char *)(param_1 + 0x9c7e) == '\0')) {
    iVar4 = FUN_20164828(param_1 + 0x17254,0xffffffff);
    iVar9 = param_1 + iVar4 * 800 + 0x10abc;
    iVar4 = param_1 + 0x1b12c;
    iVar5 = FUN_201647e4(iVar4,0);
    memcpy(iVar9,param_1 + iVar5 * 800 + 0x17258,800);
    iVar5 = 1;
    if (1 < param_2) {
      do {
        iVar6 = FUN_201647e4(iVar4,-iVar5);
        iVar7 = 0;
        do {
          bVar3 = *(byte *)(param_1 + iVar6 * 800 + 0x17258 + iVar7);
          if (*(byte *)(iVar9 + iVar7) < bVar3) {
            *(byte *)(iVar9 + iVar7) = bVar3;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 800);
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_2);
    }
    iVar5 = FUN_20164388(param_1 + 0x82fb4);
    puVar10 = &DAT_20450278;
    if (DAT_20450280 == 1) {
      iVar5 = FUN_20164388(param_1 + 0x82fb0);
    }
    if (param_3 != 0) {
      puVar10 = (undefined4 *)0x0;
    }
    iVar5 = param_1 + DAT_20450280 * 0x33f40 + iVar5 * 0x640 + 0x1b130;
    if (param_3 != 0) {
      do {
        iVar7 = FUN_201341cc(*(undefined1 *)(iVar9 + (int)puVar10),param_3);
        iVar6 = (int)puVar10 * 2;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        *(undefined2 *)(iVar5 + iVar6) = *(undefined2 *)(param_1 + iVar7 * 2 + 0x2e06);
      } while ((int)puVar10 < 800);
    }
    else {
      iVar6 = 0;
      do {
        pbVar2 = (byte *)(iVar9 + iVar6);
        iVar7 = iVar6 * 2;
        iVar6 = iVar6 + 1;
        *(undefined2 *)(iVar5 + iVar7) = *(undefined2 *)(param_1 + (uint)*pbVar2 * 2 + 0x2e06);
      } while (iVar6 < 800);
    }
    iVar6 = 0;
    piVar11 = (int *)(param_1 + 0x1b0d8);
    if (0 < *piVar11) {
      do {
        iVar7 = FUN_201647e4(iVar4,-iVar6);
        uVar8 = (uint)*(ushort *)(piVar11 + iVar7 + 1);
        if (uVar8 < *(ushort *)((int)piVar11 + iVar7 * 4 + 6) + uVar8) {
          do {
            iVar1 = uVar8 * 2;
            pbVar2 = (byte *)(iVar9 + uVar8);
            uVar8 = uVar8 + 1;
            *(undefined2 *)(iVar5 + iVar1) = *(undefined2 *)(param_1 + (uint)*pbVar2 * 2 + 0x3008);
          } while ((int)uVar8 <
                   (int)((uint)*(ushort *)(piVar11 + iVar7 + 1) +
                        (uint)*(ushort *)((int)piVar11 + iVar7 * 4 + 6)));
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar11);
    }
  }
  return;
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


// ===== FUN_20158590 @ 20158590 (104 bytes)

int FUN_20158590(int param_1)

{
  *(undefined4 *)(param_1 + 0x17254) = 0;
  *(undefined4 *)(param_1 + 0x1b12c) = 0;
  *(undefined4 *)(param_1 + 0x82fb0) = 0;
  *(undefined4 *)(param_1 + 0x82fb4) = 0;
  return param_1;
}


// ===== FUN_20158618 @ 20158618 (24 bytes)

void FUN_20158618(int param_1)

{
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  __aeabi_memclr4_veneer(param_1 + 8,0x80);
  return;
}


// ===== mainlink_tx_alloc @ 20158630 (12 bytes)

/* gets a free 0x408-byte buffer */

uint mainlink_tx_alloc(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_201644ac(param_1 + 0x811c);
  return uVar1;
}


// ===== mainlink_tx_init @ 2015863c (96 bytes)

/* 32 x 0x408 B buffer pool + mailbox */

void mainlink_tx_init(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(uint *)(param_1 + 0x18) = param_2;
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


// ===== mainlink_tx_clear_stats @ 2015869c (16 bytes)

void mainlink_tx_clear_stats(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


// ===== task_mainlink_tx @ 201586ac (152 bytes)

/* task "uart" pri 4: mailbox -> scif_write(buf+8, len), then mainlink_trace */

void task_mainlink_tx(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  mainlink_tx_clear_stats(param_1);
  do {
    do {
      itron_trcv_mbx(*(undefined4 *)(param_1 + 0x81a4),local_8,0xffffffff);
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
    mainlink_trace(local_8[0] + 8,(uint)*(ushort *)(local_8[0] + 6));
  } while( true );
}


// ===== mainlink_tx_post @ 20158744 (100 bytes)

/* waits for the 3 ms pacing counter, posts to the TX mailbox, re-arms cmd_interval */

void mainlink_tx_post(int param_1,uint param_2)

{
  while (DAT_20450050 != 0) {
    itron_dly_tsk(1);
  }
  FUN_20162d3c(param_1,*(undefined4 *)(param_1 + 0x81a4),param_2);
  itron_twai_sem(DAT_20450054,0xffffffff);
  DAT_20450050 = 3;
  itron_sig_sem(DAT_20450054);
  return;
}

