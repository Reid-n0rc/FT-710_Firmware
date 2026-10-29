// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== apf_peak_filter @ 0021c818 (104 bytes)

/* reg 0x45: resonator (1) or FIR band-pass (2-4) */

void apf_peak_filter(undefined *param_1,undefined *param_2)

{
  int iVar1;
  
  apf_config();
  iVar1 = ae_l16ui_n(&DAT_00244510,2);
  if (iVar1 - 1U < 4) {
    if (param_1 == param_2) {
      memcpy(&DAT_00245360,param_1,0xc0);
      iVar1 = ae_l16ui_n(&DAT_00244510,2);
      param_1 = &DAT_00245360;
    }
    if (iVar1 == 1) {
      iir_cascade_process(DAT_00244518,param_2,param_1,0x30);
      return;
    }
    if (iVar1 - 2U < 3) {
      fir_process(DAT_0024451c,param_2,param_1,0x30);
      return;
    }
  }
  else if (param_1 != param_2) {
    memcpy(param_2,param_1,0xc0);
    return;
  }
  return;
}


// ===== FUN_0021c890 @ 0021c890 (26 bytes)

void FUN_0021c890(void)

{
  undefined8 uVar1;
  
  memset(&DAT_00245420,0,0xc98);
  uVar1 = const_s(1);
  DAT_002460ac = ae_s32_l_i(uVar1);
  return;
}


// ===== FUN_0021c8ac @ 0021c8ac (14 bytes)

void FUN_0021c8ac(void)

{
  DAT_002460b4 = 1;
  return;
}


// ===== nlms_auto_notch @ 0021c8bc (909 bytes)

/* 128-tap NLMS predictor error output, regs 0x41 0x400C 0x400E */

undefined8 nlms_auto_notch(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined2 uVar9;
  float in_aed0;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined *puVar12;
  int iVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  
  if (DAT_00245420 != DAT_20070082) {
    DAT_00245420 = DAT_20070082;
    DAT_00245426 = DAT_20070082 & 1;
    if ((DAT_20070082 & 1) != 0) {
      memset(&DAT_00245ba8,0,0x200);
      memset(&DAT_00245428,0,0x780);
      uVar11 = ae_l32_i(0);
      DAT_002460b0 = ae_s32_l_i(uVar11);
      DAT_002460b8 = iir_cascade_init(&DAT_002460c0,6,&DAT_00236850,1);
    }
  }
  puVar6 = &DAT_00245428;
  if (DAT_00245422 != DAT_20078018) {
    DAT_00245422 = DAT_20078018;
    i2f_scaled(DAT_20078018,0);
    DAT_002460a8 = ae_s32_l_i((ulonglong)(uint)(in_aed0 * 1e-06));
    memset(&DAT_00245ba8,0,0x200);
    memset(&DAT_00245428,0,0x780);
    uVar11 = ae_l32_i(0);
    DAT_002460b0 = ae_s32_l_i(uVar11);
    DAT_002460b8 = iir_cascade_init(&DAT_002460c0,6,&DAT_00236850,1);
  }
  if (DAT_00245424 != DAT_2007801c) {
    DAT_00245424 = DAT_2007801c;
    i2f_scaled(DAT_2007801c,0);
    uVar11 = ae_l32_i(0x3f800000);
    DAT_002460ac = ae_s32_l_i((ulonglong)(uint)(in_aed0 * -1e-06 + (float)uVar11));
    memset(&DAT_00245ba8,0,0x200);
    memset(&DAT_00245428,0,0x780);
    uVar11 = ae_l32_i(0);
    DAT_002460b0 = ae_s32_l_i(uVar11);
    DAT_002460b8 = iir_cascade_init(&DAT_002460c0,6,&DAT_00236850,1);
  }
  if (DAT_002460b4 != '\0') {
    DAT_002460b4 = '\0';
    memset(&DAT_00245ba8,0,0x200);
    memset(&DAT_00245428,0,0x780);
    uVar11 = ae_l32_i(0);
    DAT_002460b0 = ae_s32_l_i(uVar11);
    DAT_002460b8 = iir_cascade_init(&DAT_002460c0,6,&DAT_00236850,1);
  }
  if (DAT_00245426 == 0) {
    if (param_1 != param_2) {
      memcpy(param_2,param_1,0xc0);
    }
    return 0x2460ac00245ba8;
  }
  memset(&DAT_002461a0,0,0x180);
  uVar15 = const_s(2);
  uVar11 = ae_l32_ip(*param_1);
  DAT_002461a0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar11 * (float)uVar15));
  iir_cascade_process(DAT_002460b8,&DAT_00246320,&DAT_002461a0,0x60);
  memcpy(&DAT_00245a28,&DAT_00246320,0x180);
  puVar7 = &DAT_00245a28;
  puVar8 = &DAT_00245f28;
  uVar11 = ae_l32_i(DAT_002460a8);
  uVar1 = ae_s32_l_i(uVar11);
  uVar11 = ae_l32_i(DAT_002460ac);
  uVar4 = ae_s32_l_i(uVar11);
  puVar5 = &DAT_00245da8;
  iVar13 = 0;
  do {
    uVar11 = ae_l32_i(0);
    uVar15 = ae_l32_i(0);
    uVar2 = ae_s32_l_i(uVar15);
    *puVar8 = uVar2;
    uVar15 = ae_l32_ip(DAT_00245ba8);
    uVar14 = ae_l32_ip(*(undefined4 *)((int)&DAT_00245428 + iVar13));
    fVar3 = (float)uVar14 * (float)uVar15;
    uVar10 = (ulonglong)(uint)fVar3;
    fVar3 = (float)uVar11 + fVar3;
    uVar2 = ae_s32_l_i((ulonglong)(uint)fVar3);
    *puVar8 = uVar2;
    uVar11 = ae_l32_i(*puVar7);
    uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar11 - fVar3));
    *puVar5 = uVar2;
    vec_sum_sq(puVar6,0x80);
    uVar15 = ae_l32_i(0x3a83126f);
    uVar9 = olt_s(uVar10,uVar15);
    uVar11 = ae_l32_i(uVar1);
    uVar14 = ae_l32_i(*puVar5);
    uVar16 = ae_mov(uVar10);
    movt_s(uVar16,uVar15,(char)uVar9);
    uVar10 = (ulonglong)(uint)((float)uVar14 * (float)uVar11);
    divf_();
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
    uVar16 = ae_mov(uVar10);
    uVar15 = ae_l32_i(uVar4);
    uVar11 = ae_l32_ip(*(undefined4 *)((int)&DAT_00245428 + iVar13));
    puVar12 = &DAT_0024542c + iVar13;
    uVar14 = ae_l32_i(DAT_00245ba8);
    DAT_00245ba8 = ae_s32_l_ip((ulonglong)
                               (uint)((float)uVar11 * (float)uVar16 + (float)uVar14 * (float)uVar15)
                              );
    iVar13 = iVar13 + 4;
  } while (puVar8 != &DAT_002460a8);
  uVar11 = ae_l32_ip(DAT_002455a8);
  DAT_00245428 = ae_s32_l_ip(uVar11);
  memcpy(&DAT_002461a0,&DAT_00245da8,0x180);
  uVar11 = ae_l32_ip(DAT_002461a0);
  DAT_00246320 = ae_s32_l_ip(uVar11);
  uVar11 = ae_l32_ip(DAT_002461a8);
  DAT_00246324 = ae_s32_l_ip(uVar11);
  uVar11 = ae_l32_i(0x3f800000);
  uVar15 = ae_l32_i(DAT_002460b0);
  uVar9 = olt_s(uVar15,uVar11);
  if (SUB21(uVar9,0)) {
    uVar17 = const_s(1);
    uVar16 = ae_l32_i(0x3f800000);
    uVar11 = ae_l32_i(*param_1);
    uVar14 = ae_l32_i(DAT_00246320);
    uVar1 = ae_s32_l_i((ulonglong)
                       (uint)((float)uVar15 * (float)uVar14 +
                             (float)uVar11 * ((float)uVar16 - (float)uVar15)));
    *param_2 = uVar1;
    uVar11 = ae_l32_i(DAT_002460b0);
    uVar9 = olt_s(uVar11,uVar16);
    uVar15 = ae_l32_i(0x3f800000);
    if (SUB21(uVar9,0)) {
      uVar10 = (ulonglong)(uint)((float)uVar11 + 12000.0);
      uVar9 = olt_s(uVar15,uVar10);
      DAT_002460b0 = ae_s32_l_i(uVar10);
      if (SUB21(uVar9,0)) {
        DAT_002460b0 = ae_s32_l_i(uVar17);
        ae_l32_i(0x3f800000);
      }
    }
    return CONCAT44(param_2 + 1,param_1 + 1);
  }
  memcpy(param_2,&DAT_00246320,0xc0);
  return CONCAT44(puVar12,&DAT_00245ba8);
}


// ===== FUN_0021cc50 @ 0021cc50 (23 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0021cc50(void)

{
  DAT_002464a0 = 0;
  _DAT_002464a4 = 0;
  DAT_002464a8 = 0;
  DAT_002464ac = 0;
  DAT_002464b0 = 0;
  DAT_002464b4 = 0;
  return;
}


// ===== contour_peaking @ 0021cc68 (916 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* regs 0x42-0x44 */

void contour_peaking(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined2 uVar9;
  float fVar10;
  undefined8 in_aed0;
  ulonglong uVar11;
  undefined8 uVar12;
  float fVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined *puVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  
  if ((uint)(ushort)DAT_002464a0 == (uint)DAT_20070084) {
    iVar7 = (int)DAT_20070086;
    if (DAT_002464a0._2_2_ != iVar7) goto LAB_0021ccb6;
    uVar14 = (uint)DAT_20070088;
    if (DAT_002464a4 == uVar14) goto LAB_0021ced3;
LAB_0021cce5:
    DAT_002464a4 = (ushort)uVar14;
    if (uVar14 == 0) {
      uVar12 = ae_l32_i(0x3f000000);
      DAT_002464b0 = ae_s32_l_i(uVar12);
    }
    else {
      if ((uVar14 < 0xb) && ((uVar14 - 1 & 0x80000000) != 0)) {
        iVar7 = 1;
      }
      else {
        iVar7 = (uVar14 < 10) * uVar14 + (uint)(uVar14 >= 10) * 10;
      }
      uVar8 = ae_zext16(iVar7);
      i2f_scaled(uVar8,0);
      DAT_002464b0 = ae_s32_l_i(in_aed0);
    }
    in_aed0 = ae_l32_i(DAT_002464a8);
  }
  else {
    DAT_002464a0._0_2_ = DAT_20070084;
    _DAT_002464a6 = DAT_20070084 >> 0xc & 1;
    puVar16 = (undefined *)(DAT_20070084 & 0xfff);
    if ((&DAT_0000176f < puVar16) || ((DAT_20070084 & 0xfff) != 0)) {
      iVar7 = (uint)(puVar16 < &DAT_0000176f) * (int)puVar16 +
              (uint)(puVar16 >= &DAT_0000176f) * (int)&DAT_0000176f;
    }
    else {
      iVar7 = 1;
    }
    uVar8 = ae_zext16(iVar7);
    i2f_scaled(uVar8,0);
    iVar7 = (int)DAT_20070086;
    DAT_002464a8 = ae_s32_l_i(in_aed0);
    if (DAT_002464a0._2_2_ == iVar7) {
      uVar14 = (uint)DAT_20070088;
      if (DAT_002464a4 != uVar14) goto LAB_0021cce5;
    }
    else {
LAB_0021ccb6:
      DAT_002464a0._2_2_ = (short)iVar7;
      if ((iVar7 < 0x15) && ((iVar7 + 0x28U & 0x80000000) != 0)) {
        iVar7 = -0x28;
      }
      else {
        iVar7 = (uint)(iVar7 < 0x14) * iVar7 + (uint)(iVar7 >= 0x14) * 0x14;
      }
      uVar8 = ae_sext16(iVar7);
      i2f_scaled(uVar8,0);
      uVar14 = (uint)DAT_20070088;
      DAT_002464ac = ae_s32_l_i(in_aed0);
      if (DAT_002464a4 != uVar14) goto LAB_0021cce5;
      in_aed0 = ae_l32_i(DAT_002464a8);
    }
  }
  uVar11 = (ulonglong)(uint)((float)in_aed0 * 3.1415927 * 8.333333e-05);
  tanf_();
  uVar12 = ae_l32_i(DAT_002464ac);
  uVar8 = ae_s32_l_i(uVar11);
  uVar11 = (ulonglong)(uint)((float)uVar12 * 0.05);
  pow10f_();
  uVar12 = ae_l32_i(DAT_002464b0);
  uVar19 = const_s(0);
  uVar9 = oeq_s(uVar12,uVar19);
  uVar4 = ae_s32_l_i(uVar11);
  if (SUB21(uVar9,0)) {
    uVar12 = const_s(3);
    DAT_002464b0 = ae_s32_l_i(uVar12);
    ae_l32_i(0x3f000000);
  }
  uVar12 = const_s(1);
  divf_();
  uVar1 = ae_s32_l_i(uVar12);
  ae_l32_i(uVar4);
  uVar12 = ae_l32_i(0x3f800000);
  divf_();
  uVar15 = ae_l32_i(uVar4);
  uVar19 = ae_l32_i(0x3f800000);
  uVar9 = olt_s(uVar15,uVar19);
  uVar12 = movt_s(uVar15,uVar12,(char)uVar9);
  uVar4 = ae_s32_l_i(uVar12);
  if (DAT_002464a0._2_2_ < 1) {
    if (DAT_002464a0._2_2_ < 0) {
      uVar15 = ae_l32_i(uVar1);
      uVar19 = ae_l32_i(uVar8);
      fVar13 = (float)uVar19;
      fVar3 = fVar13 * (float)uVar12 * (float)uVar15;
      uVar12 = ae_l32_i(0x3f800000);
      fVar10 = fVar13 * fVar13;
      fVar13 = (float)uVar15 * fVar13;
      uVar1 = ae_s32_l_i((ulonglong)(uint)fVar10);
      uVar4 = ae_s32_l_i((ulonglong)(uint)fVar13);
      uVar2 = ae_s32_l_i((ulonglong)(uint)fVar3);
      uVar5 = ae_s32_l_i((ulonglong)(uint)(fVar3 + (float)uVar12 + fVar10));
      uVar11 = (ulonglong)(uint)(fVar13 + (float)uVar12 + fVar10);
      divf_();
      uVar19 = ae_l32_i(uVar1);
      uVar15 = ae_l32_i(0xbf800000);
      uVar12 = ae_l32_i(&DAT_40000000);
      uVar8 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar5);
      uVar11 = (ulonglong)(uint)(((float)uVar19 + (float)uVar15) * (float)uVar12);
      divf_();
      uVar19 = ae_l32_i(uVar4);
      uVar15 = ae_l32_i(0x3f800000);
      uVar12 = ae_l32_i(uVar1);
      uVar4 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar5);
      uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar15 - (float)uVar19));
      divf_();
      uVar19 = ae_l32_i(uVar2);
      uVar15 = ae_l32_i(0x3f800000);
      uVar12 = ae_l32_i(uVar1);
      uVar1 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar5);
      uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar15 - (float)uVar19));
      divf_();
      uVar12 = ae_l32_i(uVar1);
      uVar17 = ae_l32_i(uVar4);
      uVar19 = ae_l32_i(0x3f800000);
      ae_s32_l_i(uVar19);
      uVar18 = ae_l32_i(uVar8);
      uVar15 = ae_mov(uVar11);
    }
    else {
      uVar15 = ae_l32_i(0);
      uVar18 = ae_mov(uVar12);
      ae_s32_l_i(uVar19);
      uVar12 = ae_mov(uVar15);
      uVar17 = ae_mov(uVar15);
    }
    DAT_002464b4 = ae_s32_l_i(uVar19);
  }
  else {
    uVar12 = ae_l32_i(uVar8);
    uVar19 = ae_l32_i(uVar4);
    uVar15 = ae_l32_i(uVar1);
    fVar10 = (float)uVar12;
    fVar13 = (float)uVar15 * fVar10;
    uVar12 = ae_l32_i(0x3f800000);
    fVar3 = fVar10 * fVar10;
    fVar10 = fVar10 * (float)uVar19 * (float)uVar15;
    uVar5 = ae_s32_l_i((ulonglong)(uint)fVar3);
    uVar6 = ae_s32_l_i((ulonglong)(uint)fVar13);
    uVar1 = ae_s32_l_i((ulonglong)(uint)fVar10);
    uVar2 = ae_s32_l_i((ulonglong)(uint)(fVar13 + (float)uVar12 + fVar3));
    uVar11 = (ulonglong)(uint)(fVar10 + (float)uVar12 + fVar3);
    divf_();
    uVar12 = ae_l32_i(uVar5);
    uVar19 = ae_l32_i(0xbf800000);
    uVar15 = ae_l32_i(&DAT_40000000);
    uVar8 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar2);
    uVar11 = (ulonglong)(uint)(((float)uVar12 + (float)uVar19) * (float)uVar15);
    divf_();
    uVar12 = ae_l32_i(uVar1);
    uVar19 = ae_l32_i(0x3f800000);
    uVar15 = ae_l32_i(uVar5);
    uVar1 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar2);
    uVar11 = (ulonglong)(uint)((float)uVar15 + ((float)uVar19 - (float)uVar12));
    divf_();
    uVar12 = ae_l32_i(uVar6);
    uVar19 = ae_l32_i(0x3f800000);
    uVar15 = ae_l32_i(uVar5);
    uVar5 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar2);
    uVar11 = (ulonglong)(uint)((float)uVar15 + ((float)uVar19 - (float)uVar12));
    divf_();
    uVar12 = ae_l32_i(uVar4);
    uVar19 = ae_l32_i(0);
    uVar15 = ae_mov(uVar11);
    uVar9 = oeq_s(uVar12,uVar19);
    uVar12 = ae_l32_i(uVar5);
    uVar17 = ae_l32_i(uVar1);
    uVar18 = ae_l32_i(uVar8);
    if (SUB21(uVar9,0)) {
      uVar19 = ae_l32_i(0x3f800000);
    }
    else {
      uVar4 = ae_s32_l_i(uVar15);
      uVar19 = ae_l32_i(0x3f800000);
      divf_();
      uVar12 = ae_l32_i(uVar5);
      uVar17 = ae_l32_i(uVar1);
      uVar18 = ae_l32_i(uVar8);
      uVar15 = ae_l32_i(uVar4);
    }
    DAT_002464b4 = ae_s32_l_i(uVar19);
  }
  DAT_002464c0 = ae_s32_l_i(uVar18);
  DAT_002464c8 = ae_s32_l_i(uVar12);
  DAT_002464c4 = ae_s32_l_i(uVar17);
  DAT_002464cc = ae_s32_l_i(uVar17);
  DAT_002464d0 = ae_s32_l_i(uVar15);
  DAT_002464b8 = iir_cascade_init(&DAT_002464e0,1,&DAT_002464c0,0);
LAB_0021ced3:
  iVar7 = ae_l16ui_n(&DAT_002464a4,2);
  if (iVar7 != 0) {
    iir_cascade_process(DAT_002464b8,&DAT_00246520,param_1,0x30);
    ae_l32_i(DAT_002464b4);
    vec_scale_f32(param_2,&DAT_00246520,0x30);
    return;
  }
  if (param_1 != param_2) {
    memcpy(param_2,param_1,0xc0);
  }
  return;
}


// ===== FUN_0021d010 @ 0021d010 (28 bytes)

void FUN_0021d010(void)

{
  memset(&DAT_00246600,0,0x3c0);
  DAT_002469c0 = 0;
  DAT_002469c2 = 0;
  return;
}


// ===== FUN_0021d02c @ 0021d02c (44 bytes)

void FUN_0021d02c(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 in_aed0;
  
  uVar1 = ae_s32_l_i(in_aed0);
  (&DAT_00246600)[DAT_002469c0] = uVar1;
  uVar2 = ae_zext16(DAT_002469c0 + 1);
  DAT_002469c0 = (short)uVar2;
  if (uVar2 < 0xf0) {
    return;
  }
  DAT_002469c0 = 0;
  return;
}


// ===== FUN_0021d058 @ 0021d058 (33 bytes)

void FUN_0021d058(void)

{
  uint uVar1;
  
  uVar1 = ae_zext16(DAT_002469c0 + 1);
  if (0xef < uVar1) {
    DAT_002469c2 = 0;
    return;
  }
  DAT_002469c2 = (short)(DAT_002469c0 + 1);
  return;
}


// ===== FUN_0021d07c @ 0021d07c (42 bytes)

void FUN_0021d07c(void)

{
  uint uVar1;
  
  ae_l32_i((&DAT_00246600)[DAT_002469c2]);
  uVar1 = ae_zext16(DAT_002469c2 + 1);
  DAT_002469c2 = (short)uVar1;
  if (uVar1 < 0xf0) {
    return;
  }
  DAT_002469c2 = 0;
  return;
}


// ===== zeroin_goertzel_reset @ 0021d0a8 (38 bytes)

/* s1 = s2 = 0 for the 3 bins (#184) */

void zeroin_goertzel_reset(void)

{
  undefined8 uVar1;
  
  uVar1 = const_s(0);
  DAT_00246ccc = ae_s32_l_i(uVar1);
  DAT_00246cc8 = ae_s32_l_i(uVar1);
  DAT_00246cd8 = ae_s32_l_ip(uVar1);
  DAT_00246ce8 = ae_s32_l_i(uVar1);
  DAT_00246ce4 = ae_s32_l_i(uVar1);
  DAT_00246cf4 = ae_s32_l_ip(uVar1);
  DAT_00246d04 = ae_s32_l_i(uVar1);
  DAT_00246d00 = ae_s32_l_i(uVar1);
  DAT_00246d10 = ae_s32_l_ip(uVar1);
  return;
}


// ===== zeroin_goertzel_tune @ 0021d0d0 (112 bytes)

/* (f): 3 Goertzel bins at f, f - 15, f + 15 Hz over 240 samples, coeff 2 cos(2 pi f / 12000); then
   reset (#184) */

void zeroin_goertzel_tune(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined8 in_aed0;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  DAT_00246cc0 = ae_s32_l_i(in_aed0);
  DAT_00246cdc = ae_s32_l_i((ulonglong)(uint)((float)in_aed0 + -15.0));
  DAT_00246cf8 = ae_s32_l_i((ulonglong)(uint)((float)in_aed0 + 15.0));
  puVar3 = &DAT_00246cc4;
  do {
    uVar4 = ae_l32_i(puVar3[-1]);
    uVar6 = ae_l32_i(0x43700000);
    uVar9 = ae_l32_i(0x38aec33e);
    uVar8 = ae_l32_i(0x40c90fdb);
    uVar7 = ae_l32_i(0x3b888889);
    uVar5 = (ulonglong)
            (uint)((float)uVar4 * (float)uVar6 * (float)uVar9 * (float)uVar8 * (float)uVar7);
    uVar2 = ae_s32_l_i(uVar5);
    sinf();
    uVar1 = ae_s32_l_i(uVar5);
    puVar3[3] = uVar1;
    uVar4 = ae_l32_i(uVar2);
    cosf();
    uVar6 = ae_l32_i(&DAT_40000000);
    uVar1 = ae_s32_l_i(uVar4);
    puVar3[4] = uVar1;
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar4 * (float)uVar6));
    *puVar3 = uVar1;
    puVar3 = puVar3 + 7;
  } while (puVar3 != (undefined4 *)0x246d18);
  zeroin_goertzel_reset();
  return;
}


// ===== zeroin_goertzel_step @ 0021d140 (80 bytes)

/* (x): s = x + c s1 - s2 for the 3 bins (#184) */

void zeroin_goertzel_step(void)

{
  float in_aed0;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = ae_l32_i(DAT_00246cc8);
  uVar3 = ae_l32_i(DAT_00246cc4);
  uVar1 = ae_l32_i(DAT_00246ccc);
  DAT_00246ccc = ae_s32_l_i(uVar2);
  DAT_00246cc8 = ae_s32_l_ip((ulonglong)
                             (uint)(in_aed0 + ((float)uVar3 * (float)uVar2 - (float)uVar1)));
  uVar2 = ae_l32_i(DAT_00246ce4);
  uVar3 = ae_l32_i(DAT_00246ce0);
  uVar1 = ae_l32_i(DAT_00246ce8);
  DAT_00246ce8 = ae_s32_l_i(uVar2);
  DAT_00246ce4 = ae_s32_l_ip((ulonglong)
                             (uint)(in_aed0 + ((float)uVar3 * (float)uVar2 - (float)uVar1)));
  uVar2 = ae_l32_i(DAT_00246d00);
  uVar3 = ae_l32_i(DAT_00246cfc);
  uVar1 = ae_l32_i(DAT_00246d04);
  DAT_00246d04 = ae_s32_l_i(uVar2);
  DAT_00246d00 = ae_s32_l_ip((ulonglong)
                             (uint)(in_aed0 + ((float)uVar3 * (float)uVar2 - (float)uVar1)));
  return;
}


// ===== zeroin_goertzel_mag @ 0021d190 (78 bytes)

/* |X| = sqrt(s1^2 + s2^2 - c s1 s2) per bin (#184) */

void zeroin_goertzel_mag(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  float fVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  puVar2 = &DAT_00246cd8;
  do {
    uVar7 = ae_l32_i(puVar2[-3]);
    uVar8 = ae_l32_i(puVar2[-4]);
    fVar6 = (float)uVar7;
    fVar5 = (float)uVar8;
    uVar7 = ae_l32_i(puVar2[-5]);
    uVar4 = (ulonglong)(uint)((fVar5 * fVar5 + fVar6 * fVar6) - (float)uVar7 * fVar5 * fVar6);
    uVar1 = ae_s32_l_i(uVar4);
    sqrtf_();
    uVar3 = oeq_s(uVar4,uVar4);
    if (!SUB21(uVar3,0)) {
      uVar4 = ae_l32_i(uVar1);
      FUN_00229a20();
    }
    uVar1 = ae_s32_l_ip(uVar4);
    *puVar2 = uVar1;
    puVar2 = puVar2 + 7;
  } while (puVar2 != (undefined4 *)0x246d2c);
  return;
}


// ===== zeroin_tone_gate @ 0021d1e0 (84 bytes)

/* (state): off -> on when the centre bin > 90.83 A and > both side bins; on -> off when centre <
   90.83 A (A = sqrt 2 RMS) (#184) */

uint zeroin_tone_gate(uint param_1)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = ae_l32_i(DAT_00246cd8);
  if (param_1 != 0) {
    uVar2 = ae_l32_i(DAT_002469c8);
    uVar1 = olt_s(uVar3,uVar2);
    if (SUB21(uVar1,0)) {
      param_1 = 0;
    }
    return param_1;
  }
  uVar2 = ae_l32_i(DAT_002469c4);
  uVar1 = olt_s(uVar2,uVar3);
  if (SUB21(uVar1,0)) {
    uVar2 = ae_l32_i(DAT_00246cf4);
    uVar1 = olt_s(uVar2,uVar3);
    if (SUB21(uVar1,0)) {
      uVar2 = ae_l32_i(DAT_00246d10);
      uVar1 = olt_s(uVar2,uVar3);
      return (uint)(byte)uVar1;
    }
  }
  return 0;
}


// ===== cw_zero_in_init @ 0021d234 (60 bytes)

/* clears the zero-in state, reg 4 = 0x7FFF, hilbert state (#184) */

void cw_zero_in_init(void)

{
  undefined8 uVar1;
  
  uVar1 = const_s(0);
  DAT_002465e8 = ae_s32_l_i(uVar1);
  DAT_002465ec = ae_s32_l_i(uVar1);
  DAT_002465f4 = ae_s32_l_i(uVar1);
  DAT_002465f0 = ae_s32_l_i(uVar1);
  DAT_002465f8 = ae_s32_l_i(uVar1);
  ae_s16i_n(0,&DAT_002465e0,2);
  DAT_002465e4 = 0;
  DAT_002465fc = 0;
  ae_s16i_n(&DAT_00007fff,&DAT_002465e0,0);
  FUN_00225340(&DAT_002469d0);
  DAT_002469c0 = 0;
  DAT_002469c2 = 0;
  DAT_002469cc = 0;
  return;
}


// ===== cw_zero_in_estimator @ 0021d270 (823 bytes)

/* reg 4 = (f - pitch)/10 Hz or 0x7FFF; pitch in reg 0x61 */

void cw_zero_in_estimator(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  float fVar5;
  undefined8 in_aed0;
  ulonglong uVar6;
  undefined2 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined *puVar11;
  undefined8 uVar12;
  int local_30;
  undefined4 *puStack_2c;
  
  if ((uint)DAT_002465e0 != (uint)DAT_200700c2) {
    DAT_002465e4 = DAT_200700c2 >> 0xc & 1;
    DAT_002465e0 = DAT_200700c2;
    puVar11 = (undefined *)(DAT_200700c2 & 0xfff);
    if ((&DAT_0000176f < puVar11) || ((DAT_200700c2 & 0xfff) != 0)) {
      iVar1 = (uint)(puVar11 < &DAT_0000176f) * (int)puVar11 +
              (uint)(puVar11 >= &DAT_0000176f) * (int)&DAT_0000176f;
    }
    else {
      iVar1 = 1;
    }
    uVar2 = ae_zext16(iVar1);
    i2f_scaled(uVar2,0);
    DAT_002465e8 = ae_s32_l_i(in_aed0);
    DAT_20070008 = 0;
  }
  if (DAT_002465e4 != 0) {
    hilbert_iq(&DAT_002469d0,param_1,&DAT_00246d20,&DAT_00246de0,0x30);
    puStack_2c = &DAT_00246de0;
    local_30 = 0x30;
    puVar3 = &DAT_00246d20;
    do {
      uVar8 = ae_l32_i(*puVar3);
      uVar2 = ae_s32_l_i(uVar8);
      (&DAT_00246600)[DAT_002469c0] = uVar2;
      uVar4 = ae_zext16(DAT_002469c0 + 1);
      DAT_002469c0 = (ushort)uVar4;
      if (0xef < uVar4) {
        DAT_002469c0 = 0;
      }
      uVar9 = ae_l32_i(DAT_002465f4);
      uVar12 = ae_l32_i(DAT_002465f0);
      uVar10 = ae_l32_i(*puStack_2c);
      fVar5 = (float)uVar10 * (float)uVar12 - (float)uVar8 * (float)uVar9;
      atan2f_();
      uVar8 = ae_l32_i(DAT_002465f8);
      uVar9 = ae_l32_i(*puVar3);
      fVar5 = (float)uVar8 + fVar5;
      DAT_002465f0 = ae_s32_l_i(uVar9);
      uVar8 = ae_l32_i(*puStack_2c);
      DAT_002465f4 = ae_s32_l_i(uVar8);
      uVar4 = ae_zext16(DAT_002465fc + 1);
      DAT_002465f8 = ae_s32_l_i((ulonglong)(uint)fVar5);
      DAT_002465fc = (ushort)uVar4;
      if (0xef < uVar4) {
        DAT_002465fc = 0;
        uVar9 = ae_l32_i(0x3b888889);
        uVar8 = ae_l32_i(0);
        DAT_002465f8 = ae_s32_l_i(uVar8);
        uVar8 = ae_l32_i(0x44eebb7f);
        memw();
        DAT_00246eac = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * fVar5 * (float)uVar9));
        memw();
        uVar9 = ae_l32_i(DAT_00246eac);
        memw();
        uVar8 = ae_l32_i(0x41200000);
        uVar7 = ole_s(uVar8,uVar9);
        if (SUB21(uVar7,0)) {
          DAT_002469c2 = (ushort)(DAT_002469c0 + 1);
          uVar4 = ae_zext16(DAT_002469c0 + 1);
          if (0xef < uVar4) {
            DAT_002469c2 = 0;
          }
          memw();
          ae_l32_i(DAT_00246eac);
          zeroin_goertzel_tune();
          memw();
          uVar8 = ae_l32_i(0);
          DAT_00246ea8 = ae_s32_l_i(uVar8);
          iVar1 = 0;
          do {
            uVar8 = ae_l32_i((&DAT_00246600)[DAT_002469c2]);
            uVar4 = ae_zext16(DAT_002469c2 + 1);
            DAT_002469c2 = (ushort)uVar4;
            if (0xef < uVar4) {
              DAT_002469c2 = 0;
            }
            memw();
            DAT_00246ea4 = ae_s32_l_i(uVar8);
            memw();
            ae_l32_i(DAT_00246ea4);
            zeroin_goertzel_step();
            memw();
            uVar10 = ae_l32_i(DAT_00246ea8);
            memw();
            uVar9 = ae_l32_i(DAT_00246ea4);
            memw();
            uVar8 = ae_l32_i(DAT_00246ea4);
            memw();
            DAT_00246ea8 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * (float)uVar9 + (float)uVar10)
                                     );
            iVar1 = iVar1 + 1;
          } while (iVar1 != 0xf0);
          zeroin_goertzel_mag();
          memw();
          uVar9 = ae_l32_i(DAT_00246ea8);
          uVar8 = ae_l32_i(0x3b888889);
          uVar6 = (ulonglong)(uint)((float)uVar8 * (float)uVar9);
          uVar2 = ae_s32_l_i(uVar6);
          sqrtf_();
          uVar7 = oeq_s(uVar6,uVar6);
          if (!SUB21(uVar7,0)) {
            uVar6 = ae_l32_i(uVar2);
            FUN_00229a20();
          }
          memw();
          DAT_00246ea8 = ae_s32_l_i(uVar6);
          memw();
          uVar9 = ae_l32_i(DAT_00246ea8);
          uVar8 = ae_l32_i(0x3fb504f3);
          memw();
          DAT_00246ea0 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * (float)uVar9));
          memw();
          uVar9 = ae_l32_i(DAT_00246ea0);
          uVar8 = ae_l32_i(0x42b5aa1a);
          DAT_002469c4 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * (float)uVar9));
          memw();
          uVar9 = ae_l32_i(DAT_00246ea0);
          DAT_002469c8 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * (float)uVar9));
          memw();
          uVar9 = ae_l32_i(DAT_00246ea0);
          memw();
          uVar8 = ae_l32_i(0x3727c5ac);
          uVar7 = ole_s(uVar8,uVar9);
          if (!SUB21(uVar7,0)) goto LAB_0021d307;
          uVar2 = zeroin_tone_gate(DAT_002469cc);
          iVar1 = ae_zext16(uVar2);
          DAT_002469cc = (undefined2)iVar1;
          uVar8 = ae_l32_i(DAT_002465e8);
          if (iVar1 != 0) {
            memw();
            uVar9 = ae_l32_i(DAT_00246eac);
            uVar6 = (ulonglong)(uint)((float)uVar9 - (float)uVar8);
            uVar8 = ae_l32_i(0x4479c000);
            uVar7 = olt_s(uVar8,uVar6);
            ae_s32_l_i(uVar6);
            uVar8 = ae_l32_i(0x4479c000);
            uVar9 = ae_l32_i(0xc479c000);
            if ((SUB21(uVar7,0)) || (uVar7 = olt_s(uVar6,uVar9), !SUB21(uVar7,0))) {
              uVar7 = olt_s(uVar8,uVar6);
              uVar8 = movt_s(uVar6,uVar8,(char)uVar7);
            }
            else {
              uVar8 = ae_l32_i(0xc479c000);
            }
            uVar9 = ae_l32_i(0x3dcccccd);
            uVar9 = firound_s((ulonglong)(uint)((float)uVar8 * (float)uVar9));
            DAT_002465ec = ae_s32_l_i(uVar8);
            ae_mov(uVar9);
            uVar2 = f2i_scaled(0);
            ae_s16i_n(uVar2,&DAT_002465e0,2);
            DAT_20070008 = (undefined2)uVar2;
            goto LAB_0021d315;
          }
        }
        else {
LAB_0021d307:
          DAT_002469cc = 0;
        }
        DAT_20070008 = 0x7fff;
      }
LAB_0021d315:
      puStack_2c = puStack_2c + 1;
      local_30 = local_30 + -1;
      puVar3 = puVar3 + 1;
    } while (local_30 != 0);
  }
  return;
}


// ===== am_demod_init @ 0021d5b0 (23 bytes)

void am_demod_init(void)

{
  undefined8 uVar1;
  
  uVar1 = const_s(0);
  DAT_00246eb4 = ae_s32_l_i(uVar1);
  DAT_00246eb0 = ae_s32_l_i(uVar1);
  FUN_00225340(&DAT_00246eb8);
  return;
}


// ===== am_demod @ 0021d5c8 (121 bytes)

/* Hilbert envelope + DC blocker */

void am_demod(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  undefined8 uVar10;
  
  puVar2 = &DAT_002471b0;
  hilbert_iq(&DAT_00246eb8,param_1,&DAT_002471b0,&DAT_00247210,0x18);
  puVar3 = &DAT_00247210;
  iVar9 = 0;
  do {
    uVar8 = ae_l32_i(*puVar2);
    uVar10 = ae_l32_i(*puVar3);
    uVar5 = (ulonglong)(uint)((float)uVar8 * (float)uVar8 + (float)uVar10 * (float)uVar10);
    uVar1 = ae_s32_l_i(uVar5);
    sqrtf_();
    uVar4 = oeq_s(uVar5,uVar5);
    if (!SUB21(uVar4,0)) {
      uVar5 = ae_l32_i(uVar1);
      FUN_00229a20();
    }
    uVar10 = ae_l32_i(DAT_00246eb4);
    uVar7 = ae_l32_i(0x3f7fbe77);
    uVar8 = ae_l32_i(DAT_00246eb0);
    uVar6 = (ulonglong)(uint)(((float)uVar5 + (float)uVar10 * (float)uVar7) - (float)uVar8);
    DAT_00246eb0 = ae_s32_l_i(uVar5);
    DAT_00246eb4 = ae_s32_l_i(uVar6);
    puVar2 = puVar2 + 1;
    uVar1 = ae_s32_l_ip(uVar6);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    iVar9 = iVar9 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar9 != 0x18);
  return;
}


// ===== fm_demod_init @ 0021d650 (60 bytes)

void fm_demod_init(void)

{
  undefined8 uVar1;
  
  FUN_00225340(&DAT_00247270);
  uVar1 = const_s(0);
  DAT_00247560 = ae_s32_l_i(uVar1);
  DAT_00247568 = ae_s32_l_i(uVar1);
  DAT_0024756c = ae_s32_l_i(uVar1);
  DAT_00247570 = ae_s32_l_i(uVar1);
  uVar1 = const_s(1);
  DAT_00247564 = ae_s32_l_i(uVar1);
  DAT_00247574 = 0;
  DAT_00247578 = iir_cascade_init(0x247580,5,&DAT_002368d0,1);
  return;
}


// ===== fm_demod @ 0021d68c (514 bytes)

/* NCO -fs/3, atan2 discriminator, noise squelch level -> reg 1 high byte */

undefined * fm_demod(undefined4 param_1,undefined4 *param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined6 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  undefined2 uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  int iVar15;
  float fVar16;
  undefined8 uVar17;
  
  puVar5 = &DAT_00247640;
  hilbert_iq(&DAT_00247270,param_1,&DAT_00247640,&DAT_002476a0,0x18);
  puVar6 = &DAT_002476a0;
  uVar12 = 0x40c90fdb;
  uVar17 = const_s(0);
  iVar15 = 0x18;
  puVar4 = param_2;
  do {
    uVar13 = ae_l32_i(DAT_00247560);
    uVar14 = ae_l32_i(0xc0060a92);
    uVar11 = (ulonglong)(uint)((float)uVar13 + (float)uVar14);
    uVar10 = olt_s(uVar12,uVar11);
    DAT_00247560 = ae_s32_l_i(uVar11);
    if (SUB21(uVar10,0)) {
      do {
        uVar13 = ae_l32_i(0xc0c90fdb);
        uVar11 = (ulonglong)(uint)((float)uVar11 + (float)uVar13);
        uVar10 = olt_s(uVar12,uVar11);
        DAT_00247560 = ae_s32_l_i(uVar11);
      } while (SUB21(uVar10,0));
    }
    uVar10 = olt_s(uVar11,uVar17);
    if (SUB21(uVar10,0)) {
      do {
        uVar11 = (ulonglong)(uint)((float)uVar11 + (float)uVar12);
        uVar10 = olt_s(uVar11,uVar17);
        DAT_00247560 = ae_s32_l_i(uVar11);
      } while (SUB21(uVar10,0));
    }
    cosf_();
    uVar2 = ae_s32_l_i(uVar11);
    uVar12 = ae_l32_i(DAT_00247560);
    fVar16 = (float)uVar12;
    sinf_();
    uVar12 = ae_l32_ip(*puVar6);
    puVar6 = puVar6 + 1;
    uVar13 = ae_l32_i(uVar2);
    uVar17 = ae_l32_ip(*puVar5);
    puVar5 = puVar5 + 1;
    fVar1 = (float)uVar13 * (float)uVar17 - fVar16 * (float)uVar12;
    fVar16 = fVar16 * (float)uVar17 + (float)uVar13 * (float)uVar12;
    uVar13 = ae_l32_i(DAT_00247564);
    uVar14 = ae_l32_i(DAT_00247568);
    uVar17 = ae_l32_i(0);
    uVar10 = oeq_s((ulonglong)(uint)(fVar1 * (float)uVar13 + fVar16 * (float)uVar14),uVar17);
    DAT_00247564 = ae_s32_l_i((ulonglong)(uint)fVar1);
    DAT_00247568 = ae_s32_l_i((ulonglong)(uint)fVar16);
    uVar12 = ae_l32_i(0x40c90fdb);
    uVar11 = (ulonglong)(uint)(fVar16 * (float)uVar13 - fVar1 * (float)uVar14);
    if ((SUB21(uVar10,0)) && (uVar10 = oeq_s(uVar11,uVar17), SUB21(uVar10,0))) {
      uVar11 = ae_l32_i(DAT_0024756c);
    }
    else {
      atan2f_();
      uVar12 = ae_l32_i(0x40c90fdb);
      uVar17 = ae_l32_i(0);
    }
    uVar13 = ae_l32_i(0x3fcfadd3);
    DAT_0024756c = ae_s32_l_i(uVar11);
    uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar13 * (float)uVar11));
    *puVar4 = uVar2;
    puVar4 = puVar4 + 1;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  iir_cascade_process(DAT_00247578,&DAT_00247700,param_2,0x18);
  uVar17 = ae_l32_i(DAT_00247570);
  uVar12 = ae_l32_ip(DAT_00247700);
  uVar7 = ae_zext16(DAT_00247574 + 0x18);
  if (0x707 < uVar7) {
    DAT_00247574 = 0;
    uVar12 = ae_l32_i(0);
    DAT_00247570 = ae_s32_l_i(uVar12);
    iVar15 = f2i_scaled(0xfffffff0,0x40200000,0x3a11a2b4);
    if ((iVar15 == 0) || (0 < iVar15)) {
      uVar8 = (ushort)(iVar15 < (int)&DAT_0000ffff) * (short)iVar15 -
              (ushort)(iVar15 >= (int)&DAT_0000ffff);
    }
    else {
      uVar8 = 0;
    }
    uVar9 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar7 = uVar9 & 0xf;
    if (1 < uVar7) {
      DAT_20070002 = DAT_20070002 & 0xff | uVar8 & 0xff00;
      uVar9 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,
                     in_st_PSINTLEVEL);
      wsr_ps(uVar7 | uVar9 & 0xfffffff0);
      rsync();
      return &DAT_00247704;
    }
    uVar3 = wsr_ps(uVar9 & 0xfffffff0 | 2);
    rsync();
    DAT_20070002 = DAT_20070002 & 0xff | uVar8 & 0xff00;
    uVar9 = rsr_ps((char)uVar3,(char)((uint6)uVar3 >> 8),(char)((uint6)uVar3 >> 0x10),
                   (char)((uint6)uVar3 >> 0x18),(char)((uint6)uVar3 >> 0x20),
                   (char)((uint6)uVar3 >> 0x28));
    wsr_ps(uVar7 | uVar9 & 0xfffffff0);
    rsync();
    return &DAT_00247704;
  }
  DAT_00247574 = (short)uVar7;
  DAT_00247570 = ae_s32_l_i((ulonglong)(uint)((float)uVar17 + ABS((float)uVar12)));
  return &DAT_00247704;
}


// ===== ssb_weaver_init @ 0021d8a0 (159 bytes)

/* param 0 (CW-U/USB): NCO1 16 kHz, 1: 20 kHz */

void ssb_weaver_init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = const_s(0);
  DAT_00247764 = ae_s32_l_i(uVar3);
  DAT_00247768 = ae_s32_l_i(uVar3);
  uVar3 = const_s(1);
  uVar3 = movnez_s(uVar3,0xbf800000,(uint)(param_1 == 0));
  DAT_00247760 = ae_s32_l_i(uVar3);
  DAT_00247900 = iir_cascade_init(&DAT_00247780,5,&DAT_002373d0,1);
  DAT_00247904 = iir_cascade_init(&DAT_00247840,5,&DAT_002373d0,1);
  DAT_0024776c = iir_cascade_init(&DAT_00247910,5,&DAT_002373d0,1);
  iVar1 = ae_l16si_n(&DAT_00205534,0);
  uVar2 = ae_sext16(iVar1 + 1);
  DAT_00247770 = iir_cascade_init(&DAT_002479d0,9,&DAT_00237440,uVar2);
  iVar1 = ae_l16si_n(&DAT_00205534,0);
  uVar2 = ae_sext16(iVar1 + 1);
  DAT_00247774 = iir_cascade_init(&DAT_00247b10,9,&DAT_00237440,uVar2);
  return;
}


// ===== ssb_weaver_demod @ 0021d940 (605 bytes)

/* Weaver SSB/CW demodulator, NCO1 (+-2000+18000) Hz at 72 kHz, NCO2 2 kHz at 12 kHz */

undefined4 * ssb_weaver_demod(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  float fVar11;
  float fVar12;
  undefined8 uVar13;
  
  uVar8 = ae_l32_i(DAT_00247760);
  uVar7 = 0x40c90fdb;
  puVar4 = param_1 + 0x18;
  puVar9 = &DAT_00247c50;
  puVar3 = &DAT_00247cb0;
  uVar1 = ae_s32_l_i((ulonglong)
                     (uint)(((float)uVar8 * 2000.0 + 18000.0) * 6.2831855 * 1.3888889e-05));
  uVar8 = const_s(0);
  do {
    uVar10 = ae_l32_i(uVar1);
    uVar13 = ae_l32_i(DAT_00247764);
    uVar6 = (ulonglong)(uint)((float)uVar13 + (float)uVar10);
    uVar5 = olt_s(uVar7,uVar6);
    DAT_00247764 = ae_s32_l_i(uVar6);
    if (SUB21(uVar5,0)) {
      do {
        uVar10 = ae_l32_i(0xc0c90fdb);
        uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar10);
        uVar5 = olt_s(uVar7,uVar6);
        DAT_00247764 = ae_s32_l_i(uVar6);
      } while (SUB21(uVar5,0));
    }
    uVar5 = olt_s(uVar6,uVar8);
    if (SUB21(uVar5,0)) {
      do {
        uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar7);
        uVar5 = olt_s(uVar6,uVar8);
        DAT_00247764 = ae_s32_l_i(uVar6);
      } while (SUB21(uVar5,0));
    }
    cosf_();
    uVar2 = ae_s32_l_i(uVar6);
    uVar7 = ae_l32_i(DAT_00247764);
    fVar11 = (float)uVar7;
    sinf_();
    uVar7 = ae_l32_i(uVar2);
    uVar8 = ae_l32_i(*param_1);
    uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar8 * (float)uVar7));
    *puVar9 = uVar2;
    puVar9 = puVar9 + 1;
    uVar7 = ae_l32_ip(*param_1);
    param_1 = param_1 + 1;
    uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * fVar11));
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
    uVar7 = ae_l32_i(0x40c90fdb);
    uVar8 = ae_l32_i(0);
  } while (param_1 != puVar4);
  iir_cascade_process(DAT_00247900,&DAT_00247d10,&DAT_00247c50,0x18);
  uVar7 = ae_l32_ip(DAT_00247d10);
  DAT_00247c50 = ae_s32_l_ip(uVar7);
  uVar7 = ae_l32_ip(DAT_00247d28);
  DAT_00247c54 = ae_s32_l_ip(uVar7);
  iir_cascade_process(DAT_00247904,&DAT_00247d70,&DAT_00247cb0,0x18);
  uVar7 = ae_l32_ip(DAT_00247d70);
  DAT_00247cb0 = ae_s32_l_ip(uVar7);
  uVar7 = ae_l32_ip(DAT_00247d88);
  DAT_00247cb4 = ae_s32_l_ip(uVar7);
  iir_cascade_process(DAT_00247770,&DAT_00247d10,&DAT_00247c50,4);
  iir_cascade_process(DAT_00247774,&DAT_00247d70,&DAT_00247cb0,4);
  puVar9 = &DAT_00247d70;
  puVar3 = &DAT_00247c50;
  uVar7 = ae_l32_i(0x40c90fdb);
  uVar8 = ae_l32_i(0);
  puVar4 = &DAT_00247d10;
  uVar10 = 0x3f860a92;
  do {
    uVar13 = ae_l32_i(DAT_00247768);
    uVar6 = (ulonglong)(uint)((float)uVar13 + (float)uVar10);
    uVar5 = olt_s(uVar7,uVar6);
    DAT_00247768 = ae_s32_l_i(uVar6);
    if (SUB21(uVar5,0)) {
      do {
        uVar10 = ae_l32_i(0xc0c90fdb);
        uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar10);
        uVar5 = olt_s(uVar7,uVar6);
        DAT_00247768 = ae_s32_l_i(uVar6);
      } while (SUB21(uVar5,0));
    }
    uVar5 = olt_s(uVar6,uVar8);
    if (SUB21(uVar5,0)) {
      do {
        uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar7);
        uVar5 = olt_s(uVar6,uVar8);
        DAT_00247768 = ae_s32_l_i(uVar6);
      } while (SUB21(uVar5,0));
    }
    cosf_();
    uVar1 = ae_s32_l_i(uVar6);
    uVar7 = ae_l32_i(DAT_00247768);
    fVar12 = (float)uVar7;
    sinf_();
    uVar7 = ae_l32_i(*puVar9);
    fVar12 = (float)uVar7 * fVar12;
    uVar8 = ae_l32_i(DAT_00247760);
    uVar10 = ae_l32_i(uVar1);
    uVar7 = ae_l32_i(*puVar4);
    fVar11 = (float)uVar7 * (float)uVar10;
    uVar1 = ae_s32_l_ip((ulonglong)(uint)fVar12);
    *puVar9 = uVar1;
    puVar9 = puVar9 + 1;
    uVar1 = ae_s32_l_ip((ulonglong)(uint)fVar11);
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    uVar7 = ae_l32_i(0x40c90fdb);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)(fVar11 + (float)uVar8 * fVar12));
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
    uVar8 = ae_l32_i(0);
    uVar10 = ae_l32_i(0x3f860a92);
  } while (puVar4 != (undefined4 *)0x247d20);
  memset(&DAT_00247d10,0,0x60);
  uVar7 = ae_l32_ip(DAT_00247c50);
  uVar8 = ae_l32_ip(DAT_00247c54);
  uVar10 = ae_l32_ip(DAT_00247c58);
  uVar13 = ae_l32_ip(DAT_00247c5c);
  DAT_00247d10 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * 6.0));
  DAT_00247d28 = ae_s32_l_ip((ulonglong)(uint)((float)uVar8 * 6.0));
  DAT_00247d40 = ae_s32_l_ip((ulonglong)(uint)((float)uVar10 * 6.0));
  DAT_00247d58 = ae_s32_l_ip((ulonglong)(uint)((float)uVar13 * 6.0));
  iir_cascade_process(DAT_0024776c,&DAT_00247c50,&DAT_00247d10,0x18);
  uVar7 = ae_l32_ip(DAT_00247c50);
  uVar1 = ae_s32_l_ip(uVar7);
  *param_2 = uVar1;
  return &DAT_00247c54;
}


// ===== FUN_0021dbb0 @ 0021dbb0 (32 bytes)

void FUN_0021dbb0(void)

{
  undefined8 uVar1;
  
  memset(&DAT_00247dd0,0,0x6e4);
  uVar1 = const_s(1);
  DAT_002484a4 = ae_s32_l_i(uVar1);
  DAT_002484ac = ae_s32_l_i(uVar1);
  DAT_002484b0 = ae_s32_l_i(uVar1);
  return;
}


// ===== lms_ale_nr @ 0021dbd0 (837 bytes)

/* 128-tap LMS line enhancer NR, regs 0x40 0x400B 0x400D 0x4025 0x4026 */

undefined8 lms_ale_nr(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float fVar5;
  ulonglong in_aed0;
  ulonglong uVar6;
  undefined2 uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined *puVar11;
  int iVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  
  if (DAT_00247dd0 != DAT_20070080) {
    DAT_00247dd0 = DAT_20070080;
    DAT_00247dd6 = DAT_20070080 & 1;
    if ((DAT_20070080 & 1) != 0) {
      memset(&DAT_00248120,0,0x200);
      memset(&DAT_00247de0,0,0x340);
      uVar9 = ae_l32_i(0);
      DAT_002484a8 = ae_s32_l_i(uVar9);
      DAT_002484b4 = iir_cascade_init(0x2484c0,6,&DAT_00236850,1);
    }
  }
  uVar8 = (uint)DAT_20078016;
  if (DAT_00247dd2 != uVar8) {
    ae_s16i_n(uVar8,0x247dd0,2);
    i2f_scaled(uVar8,0);
    uVar6 = 0x3fe66666;
    uVar7 = olt_s(0x3fe66666,(ulonglong)(uint)((float)in_aed0 * 0.001));
    if (!SUB21(uVar7,0)) {
      i2f_scaled(uVar8,0);
      uVar9 = ae_l32_i(0x3a83126f);
      uVar6 = (ulonglong)(uint)((float)in_aed0 * (float)uVar9);
    }
    DAT_002484a0 = ae_s32_l_i(uVar6);
  }
  if (DAT_00247dd4 != DAT_2007801a) {
    DAT_00247dd4 = DAT_2007801a;
    i2f_scaled(DAT_2007801a,0);
    uVar9 = ae_l32_i(0x3f800000);
    DAT_002484a4 = ae_s32_l_i((ulonglong)(uint)((float)in_aed0 * -1e-06 + (float)uVar9));
  }
  fVar5 = (float)in_aed0;
  iVar12 = (int)DAT_2007804a;
  if (DAT_00247dd8 != iVar12) {
    DAT_00247dd8 = iVar12;
    i2f_scaled(iVar12,0xffffffff);
    uVar9 = ae_l32_i(0x3d4ccccd);
    in_aed0 = (ulonglong)(uint)(fVar5 * (float)uVar9);
    pow10f_();
    DAT_002484ac = ae_s32_l_i(in_aed0);
  }
  fVar5 = (float)in_aed0;
  iVar12 = (int)DAT_2007804c;
  if (DAT_00247ddc != iVar12) {
    DAT_00247ddc = iVar12;
    i2f_scaled(iVar12,0xffffffff);
    uVar9 = ae_l32_i(0x3d4ccccd);
    uVar6 = (ulonglong)(uint)(fVar5 * (float)uVar9);
    pow10f_();
    DAT_002484b0 = ae_s32_l_i(uVar6);
  }
  if (DAT_00247dd6 == 0) {
    if (param_1 != param_2) {
      memcpy(param_2,param_1,0xc0);
    }
    return CONCAT44(param_2,param_1);
  }
  ae_l32_i(DAT_002484ac);
  vec_scale_f32(&DAT_002485a0,param_1,0x30);
  iir_cascade_process(DAT_002484b4,&DAT_00248660,&DAT_002485a0,0x30);
  memcpy(&DAT_00248060,&DAT_00248660,0xc0);
  puVar2 = &DAT_00248060;
  puVar4 = &DAT_002483e0;
  uVar9 = ae_l32_i(DAT_002484a0);
  uVar13 = ae_l32_i(DAT_002484a4);
  puVar3 = &DAT_00248320;
  uVar16 = const_s(0);
  iVar12 = 0;
  do {
    uVar1 = ae_s32_l_i(uVar16);
    *puVar4 = uVar1;
    uVar14 = ae_l32_i(0);
    uVar10 = ae_l32_ip(DAT_00248120);
    uVar15 = ae_l32_ip(*(undefined4 *)((int)&DAT_00247de0 + iVar12));
    uVar6 = (ulonglong)(uint)((float)uVar14 + (float)uVar15 * (float)uVar10);
    uVar1 = ae_s32_l_i(uVar6);
    *puVar4 = uVar1;
    uVar7 = olt_s(0x41200000,uVar6);
    if (SUB21(uVar7,0)) {
      uVar1 = ae_s32_l_i(0x41200000);
      *puVar4 = uVar1;
      uVar6 = ae_mov(0x41200000);
    }
    uVar7 = olt_s(uVar6,0xc1200000);
    if (SUB21(uVar7,0)) {
      uVar1 = ae_s32_l_i(0xc1200000);
      *puVar4 = uVar1;
      uVar6 = ae_mov(0xc1200000);
    }
    uVar10 = ae_l32_i(*puVar2);
    uVar6 = (ulonglong)(uint)((float)uVar10 - (float)uVar6);
    uVar7 = olt_s(0x41200000,uVar6);
    uVar1 = ae_s32_l_i(uVar6);
    *puVar3 = uVar1;
    if (SUB21(uVar7,0)) {
      uVar1 = ae_s32_l_i(0x41200000);
      *puVar3 = uVar1;
      uVar6 = ae_mov(0x41200000);
    }
    uVar7 = olt_s(uVar6,0xc1200000);
    if (SUB21(uVar7,0)) {
      uVar1 = ae_s32_l_i(0xc1200000);
      *puVar3 = uVar1;
      uVar6 = ae_mov(0xc1200000);
    }
    puVar3 = puVar3 + 1;
    uVar10 = ae_l32_ip(*(undefined4 *)((int)&DAT_00247de0 + iVar12));
    puVar11 = &DAT_00247de4 + iVar12;
    uVar14 = ae_l32_i(DAT_00248120);
    DAT_00248120 = ae_s32_l_ip((ulonglong)
                               (uint)((float)uVar10 * (float)uVar9 * (float)uVar6 +
                                     (float)uVar14 * (float)uVar13));
    puVar4 = puVar4 + 1;
    puVar2 = puVar2 + 1;
    iVar12 = iVar12 + 4;
  } while (puVar4 != &DAT_002484a0);
  uVar9 = ae_l32_ip(DAT_00247ea0);
  DAT_00247de0 = ae_s32_l_ip(uVar9);
  memcpy(&DAT_002485a0,&DAT_002483e0,0xc0,0x41200000,puVar11);
  uVar9 = ae_l32_i(DAT_002484a8);
  uVar13 = ae_l32_i(0x3f800000);
  uVar7 = olt_s(uVar9,uVar13);
  if (SUB21(uVar7,0)) {
    uVar16 = const_s(1);
    uVar10 = ae_l32_i(0x3f800000);
    uVar14 = ae_l32_i(*param_1);
    uVar13 = ae_l32_i(DAT_002485a0);
    uVar1 = ae_s32_l_i((ulonglong)
                       (uint)((float)uVar9 * (float)uVar13 +
                             (float)uVar14 * ((float)uVar10 - (float)uVar9)));
    *param_2 = uVar1;
    uVar9 = ae_l32_i(DAT_002484a8);
    uVar7 = olt_s(uVar9,uVar10);
    uVar13 = ae_l32_i(0x3f800000);
    if (SUB21(uVar7,0)) {
      uVar6 = (ulonglong)(uint)((float)uVar9 + 8.333333e-05);
      uVar7 = olt_s(uVar13,uVar6);
      DAT_002484a8 = ae_s32_l_i(uVar6);
      if (SUB21(uVar7,0)) {
        DAT_002484a8 = ae_s32_l_i(uVar16);
        ae_l32_i(0x3f800000);
      }
    }
    return CONCAT44(param_2 + 1,param_1 + 1);
  }
  ae_l32_i(DAT_002484b0);
  vec_scale_f32(&DAT_00248660,&DAT_002485a0,0x30);
  memcpy(param_2,&DAT_00248660,0xc0);
  return CONCAT44(param_2,param_1);
}


// ===== spectral_nr_init @ 0021df20 (195 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spectral_nr_init(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  float fVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  
  _DAT_00248720 = 0;
  _DAT_00248724 = 0;
  DAT_00248728 = 0;
  _DAT_0024872c = 0;
  DAT_00248730 = 0;
  memset(&DAT_00248740,0,0x400);
  memset(&DAT_00248b40,0,0x400);
  memset(&DAT_00248f40,0,0x400);
  memset(&DAT_00249340,0,0x800);
  memset(&DAT_00249b40,0,0x800);
  memset(&DAT_0024a340,0,0x800);
  memset(&DAT_0024ab40,0,0x800);
  memset(&DAT_0024b340,0,0x800);
  puVar3 = &DAT_0024c340;
  iVar2 = 0;
  uVar7 = const_s(1);
  DAT_0024bb40 = ae_s32_l_ip(uVar7);
  do {
    fVar4 = (float)uVar7;
    i2f_scaled(iVar2,0);
    uVar6 = ae_l32_i(0x40c90fdb);
    uVar5 = ae_l32_i(0x3b000000);
    uVar7 = (ulonglong)(uint)(fVar4 * (float)uVar6 * (float)uVar5);
    cosf_();
    uVar6 = ae_l32_i(0xbf000000);
    uVar5 = ae_l32_i(0x3f000000);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * (float)uVar6 + (float)uVar5));
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x200);
  return;
}


// ===== spectral_nr_params @ 0021dfe4 (270 bytes)

/* regs 0x4022 0x4023 */

void spectral_nr_params(void)

{
  undefined2 uVar1;
  float fVar2;
  undefined8 in_aed0;
  undefined8 uVar3;
  ushort uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar6 = (uint)DAT_20078044;
  if (DAT_00248720 != uVar6) {
    ae_s16i_n(uVar6,&DAT_00248720,0);
    if (uVar6 < 4) {
      DAT_00248724 = DAT_20078044;
      if (uVar6 == 1) {
        DAT_0024872c = 0;
        memset(&DAT_0024ab40,0,0x800);
      }
      else if (uVar6 == 2) {
        uVar5 = ufloat_s((uint)DAT_0024872c,0);
        uVar3 = ae_l32_i(0x3f800000);
        uVar1 = olt_s(uVar5,uVar3);
        uVar3 = ae_l32_i(0x3f800000);
        fVar2 = (float)uVar3;
        if (!SUB21(uVar1,0)) {
          uVar3 = ae_l32_i(0x3f800000);
          divf_();
          uVar3 = ae_mov(uVar3);
          fVar2 = (float)uVar3;
        }
        uVar3 = ae_l32_ip(DAT_0024ab40);
        uVar5 = ae_l32_i(0x3f800000);
        DAT_0024bb40 = ae_s32_l_ip(uVar5);
        DAT_0024bb44 = ae_s32_l_i(uVar5);
        uVar7 = ae_l32_i(DAT_0024ab44);
        DAT_0024bb48 = ae_s32_l_ip(uVar5);
        uVar8 = ae_l32_ip(DAT_0024ab48);
        DAT_0024a340 = ae_s32_l_ip((ulonglong)(uint)((float)uVar3 * fVar2));
        in_aed0 = ae_l32_i(DAT_0024ab4c);
        DAT_0024bb4c = ae_s32_l_i(uVar5);
        DAT_0024a344 = ae_s32_l_i((ulonglong)(uint)((float)uVar7 * fVar2));
        DAT_0024a348 = ae_s32_l_ip((ulonglong)(uint)((float)uVar8 * fVar2));
        DAT_0024a34c = ae_s32_l_i((ulonglong)(uint)((float)in_aed0 * fVar2));
      }
      else if (uVar6 == 3) {
        memset(&DAT_0024a340,0,0x800);
        in_aed0 = ae_l32_i(0x3f800000);
        DAT_0024bb40 = ae_s32_l_ip(in_aed0);
      }
    }
    else {
      DAT_00248724 = 0;
    }
  }
  fVar2 = (float)in_aed0;
  if (DAT_00248722 == DAT_20078046) {
    return;
  }
  DAT_00248722 = DAT_20078046;
  uVar4 = DAT_20078046;
  if (100 < DAT_20078046) {
    uVar4 = 100;
  }
  i2f_scaled(uVar4,0);
  DAT_00248730 = ae_s32_l_i((ulonglong)(uint)(fVar2 * 0.01));
  return;
}


// ===== spectral_nr @ 0021e0f4 (343 bytes)

/* 512-pt STFT decision-directed Wiener NR, regs 0x4022/0x4023 */

void spectral_nr(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  
  spectral_nr_params();
  if (DAT_00248724 == 0) {
    if (param_1 != param_2) {
      memcpy(param_2,param_1,0xc0);
    }
  }
  else {
    iVar2 = 0;
    do {
      uVar3 = (uint)DAT_00248726;
      uVar4 = ae_l32_ip(*param_1);
      param_1 = param_1 + 1;
      uVar1 = ae_s32_l_i(uVar4);
      (&DAT_00248740)[uVar3] = uVar1;
      uVar4 = ae_l32_i((&DAT_00248b40)[uVar3]);
      uVar1 = ae_s32_l_i(uVar4);
      uVar3 = ae_zext16(uVar3 + 1);
      DAT_00248726 = (ushort)uVar3;
      if (0xff < uVar3) {
        DAT_00248726 = 0;
        memcpy(&DAT_00249340,&DAT_00249740,0x400);
        memcpy(&DAT_00249740,&DAT_00248740,0x400);
        spectral_nr_frame(&DAT_00249340,&DAT_00249b40);
        uVar11 = ae_l32_ip(DAT_00248f40);
        uVar4 = ae_l32_ip(DAT_00249b40);
        uVar5 = ae_l32_i(DAT_00248f44);
        uVar12 = ae_l32_i(DAT_00248f48);
        uVar6 = ae_l32_i(DAT_00248f4c);
        uVar13 = ae_l32_ip(DAT_00248f50);
        uVar7 = ae_l32_i(DAT_00249b44);
        uVar8 = ae_l32_i(DAT_00249b4c);
        uVar14 = ae_l32_i(DAT_00249b48);
        uVar9 = ae_l32_i(DAT_00248f5c);
        uVar10 = ae_l32_i(DAT_00248f58);
        uVar15 = ae_l32_i(DAT_00248f54);
        DAT_00248b40 = ae_s32_l_ip((ulonglong)(uint)((float)uVar11 + (float)uVar4));
        uVar11 = ae_l32_ip(DAT_00249b50);
        DAT_00248b44 = ae_s32_l_i((ulonglong)(uint)((float)uVar5 + (float)uVar7));
        uVar7 = ae_l32_i(DAT_00249b54);
        DAT_00248b48 = ae_s32_l_i((ulonglong)(uint)((float)uVar12 + (float)uVar14));
        uVar12 = ae_l32_i(DAT_00249b58);
        uVar14 = ae_l32_i(DAT_00249b5c);
        DAT_00248b4c = ae_s32_l_i((ulonglong)(uint)((float)uVar6 + (float)uVar8));
        uVar6 = ae_l32_ip(DAT_00249b60);
        uVar4 = ae_l32_ip(DAT_00248f60);
        uVar8 = ae_l32_i(DAT_00248f64);
        DAT_00248b50 = ae_s32_l_ip((ulonglong)(uint)((float)uVar13 + (float)uVar11));
        uVar11 = ae_l32_i(DAT_00249b68);
        uVar5 = ae_l32_i(DAT_00248f68);
        uVar13 = ae_l32_i(DAT_00248f6c);
        DAT_00248b54 = ae_s32_l_i((ulonglong)(uint)((float)uVar15 + (float)uVar7));
        uVar7 = ae_l32_i(DAT_00249b64);
        DAT_00248b58 = ae_s32_l_i((ulonglong)(uint)((float)uVar10 + (float)uVar12));
        uVar10 = ae_l32_i(DAT_00249b6c);
        DAT_00248b5c = ae_s32_l_i((ulonglong)(uint)((float)uVar9 + (float)uVar14));
        DAT_00248b60 = ae_s32_l_ip((ulonglong)(uint)((float)uVar4 + (float)uVar6));
        DAT_00248b64 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 + (float)uVar7));
        DAT_00248b68 = ae_s32_l_i((ulonglong)(uint)((float)uVar5 + (float)uVar11));
        DAT_00248b6c = ae_s32_l_i((ulonglong)(uint)((float)uVar13 + (float)uVar10));
        memcpy(&DAT_00248f40,&DAT_00249f40,0x400);
      }
      uVar4 = ae_l32_i(uVar1);
      uVar1 = ae_s32_l_ip(uVar4);
      *param_2 = uVar1;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x30);
  }
  return;
}


// ===== spectral_nr_frame @ 0021e24c (708 bytes)

void spectral_nr_frame(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined2 uVar10;
  ulonglong uVar11;
  float fVar12;
  int iVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined4 *puVar4;
  
  uVar14 = ae_l32_ip(*param_1);
  uVar18 = const_s(0);
  DAT_0024cb44 = ae_s32_l_i(uVar18);
  uVar15 = ae_l32_ip(DAT_0024c340);
  DAT_0024cb40 = ae_s32_l_ip((ulonglong)(uint)((float)uVar15 * (float)uVar14));
  uVar15 = ae_l32_ip(DAT_0024c344);
  uVar14 = ae_l32_ip(param_1[1]);
  DAT_0024cb4c = ae_s32_l_i(uVar18);
  DAT_0024cb48 = ae_s32_l_ip((ulonglong)(uint)((float)uVar15 * (float)uVar14));
  fft512_cplx(&DAT_0024db40,&DAT_0024cb40,FLOAT_ARRAY_00200d00,1,0x200);
  FUN_00216e00(&DAT_0024eb40,&DAT_0024db40,0x200);
  uVar14 = ae_l32_ip(DAT_0024db40);
  DAT_0024f340 = ae_s32_l_ip(uVar14);
  uVar14 = ae_l32_i(DAT_0024db44);
  DAT_0024fb40 = ae_s32_l_ip(uVar14);
  uVar14 = ae_l32_ip(DAT_0024db48);
  DAT_0024f344 = ae_s32_l_ip(uVar14);
  uVar14 = ae_l32_i(DAT_0024db4c);
  DAT_0024fb44 = ae_s32_l_ip(uVar14);
  uVar3 = FUN_00219800(&DAT_00250340,&DAT_0024fb40,&DAT_0024f340,0x200);
  puVar4 = &DAT_00250340;
  puVar6 = &DAT_0024eb40;
  puVar8 = (undefined4 *)&DAT_0024b340;
  puVar7 = &DAT_0024a340;
  if (DAT_00248724 == 1) {
    uVar14 = ae_l32_i(DAT_0024ab40);
    uVar15 = ae_l32_i(DAT_0024db44);
    DAT_0024cb44 = ae_s32_l_i(uVar15);
    uVar15 = ae_l32_ip(DAT_0024db40);
    DAT_0024cb40 = ae_s32_l_ip(uVar15);
    uVar16 = ae_l32_ip(DAT_0024eb40);
    uVar15 = ae_l32_ip(DAT_0024eb44);
    uVar18 = ae_l32_i(DAT_0024db4c);
    uVar17 = ae_l32_ip(DAT_0024db48);
    DAT_0024cb4c = ae_s32_l_i(uVar18);
    DAT_0024cb48 = ae_s32_l_ip(uVar17);
    DAT_0024ab40 = ae_s32_l_ip((ulonglong)(uint)((float)uVar14 + (float)uVar16 * (float)uVar16));
    uVar14 = ae_l32_i(DAT_0024ab44);
    DAT_0024872c = DAT_0024872c + 1;
    DAT_0024ab44 = ae_s32_l_ip((ulonglong)(uint)((float)uVar14 + (float)uVar15 * (float)uVar15));
  }
  else {
    puVar5 = &DAT_0024bb40;
    iVar13 = 0x200;
    if (DAT_00248724 == 3) {
      uVar18 = ae_l32_ip(DAT_0024eb40);
      uVar15 = ae_l32_i(DAT_0024a340);
      uVar3 = 0x1ff;
      uVar14 = ae_l32_ip(DAT_0024eb44);
      DAT_0024a340 = ae_s32_l_ip((ulonglong)
                                 (uint)((float)uVar15 * 0.99 + (float)uVar18 * (float)uVar18 * 0.01)
                                );
      uVar15 = ae_l32_i(DAT_0024a344);
      DAT_0024a344 = ae_s32_l_ip((ulonglong)
                                 (uint)((float)uVar15 * 0.99 + (float)uVar14 * (float)uVar14 * 0.01)
                                );
    }
    uVar14 = const_s(0);
    puVar9 = &DAT_0024cb40;
    do {
      uVar15 = ae_l32_i(*puVar7);
      uVar10 = oeq_s(uVar15,uVar14);
      uVar14 = ae_l32_i(*puVar5);
      uVar2 = ae_s32_l_i(uVar14);
      uVar15 = ae_l32_i(*puVar6);
      if (!SUB21(uVar10,0)) {
        uVar1 = ae_s32_l_i(uVar15);
        uVar14 = ae_l32_i(uVar1);
        uVar11 = (ulonglong)(uint)((float)uVar14 * (float)uVar14);
        divf_(uVar3);
        uVar14 = ae_l32_i(0xbf800000);
        fVar12 = (float)uVar14 + (float)uVar11;
        uVar14 = ae_l32_i(0);
        uVar10 = olt_s((ulonglong)(uint)fVar12,uVar14);
        ae_l32_i(0x3f800000);
        uVar14 = ae_l32_i(0x3ca3d700);
        if (SUB21(uVar10,0)) {
          uVar14 = ae_l32_i(0);
          fVar12 = (float)uVar14;
        }
        else {
          fVar12 = fVar12 * (float)uVar14;
        }
        uVar15 = ae_l32_i(*puVar8);
        uVar18 = ae_l32_i(0x3f7ae148);
        uVar14 = ae_l32_i(uVar2);
        uVar3 = ae_s32_l_i(uVar11);
        *puVar8 = uVar3;
        uVar14 = ae_mov((ulonglong)
                        (uint)(fVar12 + (float)uVar14 *
                                        (float)uVar14 * (float)uVar15 * (float)uVar18));
        divf_();
        uVar18 = ae_l32_i(0x3f800000);
        uVar10 = olt_s(uVar18,uVar14);
        uVar15 = ae_l32_i(uVar1);
        uVar16 = ae_l32_i(0);
        if ((SUB21(uVar10,0)) || (uVar10 = olt_s(uVar14,uVar16), !SUB21(uVar10,0))) {
          uVar10 = olt_s(uVar18,uVar14);
          uVar14 = movt_s(uVar14,uVar18,(char)uVar10);
        }
        else {
          uVar14 = ae_l32_i(0);
        }
        uVar3 = ae_s32_l_i(uVar14);
        *puVar5 = uVar3;
      }
      uVar16 = ae_l32_i(DAT_00248730);
      uVar18 = ae_l32_i(0x3f800000);
      uVar2 = ae_s32_l_i((ulonglong)
                         (uint)((float)uVar15 *
                               ((float)uVar16 * (float)uVar14 + ((float)uVar18 - (float)uVar16))));
      uVar14 = ae_l32_i(*puVar4);
      cosf_();
      uVar1 = ae_s32_l_i(uVar14);
      uVar14 = ae_l32_i(*puVar4);
      fVar12 = (float)uVar14;
      uVar3 = sinf_();
      uVar15 = ae_l32_i(uVar2);
      fVar12 = (float)uVar15 * fVar12;
      uVar18 = ae_l32_i(uVar1);
      uVar14 = ae_l32_i(0);
      puVar8 = puVar8 + 1;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
      uVar2 = ae_s32_l_i((ulonglong)(uint)fVar12);
      puVar9[1] = uVar2;
      puVar7 = puVar7 + 1;
      uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar15 * (float)uVar18 + fVar12 * (float)uVar14))
      ;
      *puVar9 = uVar2;
      puVar9 = puVar9 + 2;
      iVar13 = iVar13 + -1;
      uVar14 = ae_l32_i(0);
    } while (iVar13 != 0);
  }
  ifft512_cplx(&DAT_0024db40,&DAT_0024cb40,FLOAT_ARRAY_00200d00,1,0x200);
  uVar14 = ae_l32_ip(DAT_0024db40);
  uVar3 = ae_s32_l_ip(uVar14);
  *param_2 = uVar3;
  return;
}


// ===== FUN_0021e520 @ 0021e520 (15 bytes)

void FUN_0021e520(void)

{
  DAT_00250b40 = 0;
  DAT_00250b44 = 0;
  return;
}


// ===== manual_notch @ 0021e530 (364 bytes)

/* 3 notch biquads, reg 0x52 */

void manual_notch(undefined *param_1,undefined *param_2)

{
  undefined4 uVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_aed0;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined4 local_30;
  
  uVar3 = ae_l16ui_n(&DAT_00250b40,2);
  if ((uint)(ushort)DAT_00250b40 != (uint)DAT_200700a4) {
    DAT_00250b40._0_2_ = DAT_200700a4;
    uVar3 = 0;
    puVar9 = (undefined *)(DAT_200700a4 & 0xfff);
    if (DAT_200700a4 >> 0xc < 3) {
      if ((&DAT_0000176f < puVar9) || ((DAT_200700a4 & 0xfff) != 0)) {
        iVar4 = (uint)(puVar9 < &DAT_0000176f) * (int)puVar9 +
                (uint)(puVar9 >= &DAT_0000176f) * (int)&DAT_0000176f;
      }
      else {
        iVar4 = 1;
      }
      uVar5 = ae_zext16(iVar4);
      DAT_00250b40._2_2_ = DAT_200700a4 >> 0xc;
      i2f_scaled(uVar5,0);
      uVar3 = ae_l16ui_n(&DAT_00250b40,2);
      DAT_00250b44 = ae_s32_l_i(in_aed0);
      if (uVar3 == 1) {
        local_30 = ae_s32_l_i(0x3d4ccccd);
      }
      else {
        if (uVar3 != 2) goto LAB_0021e59c;
        local_30 = ae_s32_l_i(0x3fbc3850);
      }
      fVar2 = (float)in_aed0 * 6.2831855 * 8.333333e-05;
      uVar6 = const_s(3);
      uVar1 = ae_s32_l_i((ulonglong)(uint)fVar2);
      uVar10 = (ulonglong)(uint)(fVar2 * 0.057142857 * (float)uVar6);
      tanf_();
      uVar5 = ae_s32_l_i(uVar10);
      uVar6 = ae_l32_i(uVar1);
      cosf_();
      ae_l32_i(local_30);
      ae_l32_i(uVar5);
      uVar8 = const_s(1);
      uVar5 = ae_s32_l_i(uVar6);
      uVar6 = ae_mov(uVar8);
      divf_();
      uVar7 = const_s(2);
      uVar8 = ae_l32_i(uVar5);
      DAT_00250b50 = ae_s32_l_ip(uVar6);
      uVar10 = (ulonglong)(uint)((float)uVar8 * (float)uVar6 * -2.0);
      uVar11 = (ulonglong)(uint)((float)uVar6 * (float)uVar7 + -1.0);
      DAT_00250b58 = ae_s32_l_i(uVar6);
      DAT_00250b54 = ae_s32_l_i(uVar10);
      DAT_00250b5c = ae_s32_l_i(uVar10);
      DAT_00250b60 = ae_s32_l_i(uVar11);
      DAT_00250b64 = ae_s32_l_ip(uVar6);
      DAT_00250b68 = ae_s32_l_i(uVar10);
      DAT_00250b6c = ae_s32_l_i(uVar6);
      DAT_00250b70 = ae_s32_l_i(uVar10);
      DAT_00250b74 = ae_s32_l_i(uVar11);
      DAT_00250b78 = ae_s32_l_ip(uVar6);
      DAT_00250b80 = ae_s32_l_i(uVar6);
      DAT_00250b7c = ae_s32_l_i(uVar10);
      DAT_00250b84 = ae_s32_l_i(uVar10);
      DAT_00250b88 = ae_s32_l_i(uVar11);
      DAT_00250b48 = iir_cascade_init(&DAT_00250b90,3,&DAT_00250b50,0);
      uVar3 = (uint)DAT_00250b40._2_2_;
    }
    else {
      ae_s16i_n(0,&DAT_00250b40,2);
    }
  }
LAB_0021e59c:
  if (uVar3 != 0) {
    if (param_1 == param_2) {
      memcpy(&DAT_00250c10,param_1,0xc0);
      param_1 = &DAT_00250c10;
    }
    iir_cascade_process(DAT_00250b48,param_2,param_1,0x30);
    return;
  }
  if (param_1 != param_2) {
    memcpy(param_2,param_1,0xc0);
  }
  return;
}


// ===== FUN_0021e6b0 @ 0021e6b0 (17 bytes)

void FUN_0021e6b0(void)

{
  memset(&DAT_00250cd0,0,&DAT_000012c8);
  return;
}


// ===== branch_b_delay @ 0021e6c4 (124 bytes)

/* reg 0x56 samples (MAIN 32), max 1200, branch B (AESS output) only */

undefined8 branch_b_delay(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar3 = (uint)DAT_200700ac;
  if (DAT_00250cd0 != uVar3) {
    DAT_00250cd4 = 0;
    DAT_00250cd0 = DAT_200700ac;
    if (0x4b0 < uVar3) {
      uVar3 = 0x4b0;
    }
    DAT_00250cd2 = (ushort)uVar3;
    iVar2 = ae_zext16(uVar3);
    memset(&DAT_00250cd8,0,iVar2 << 2);
  }
  iVar2 = ae_l16ui_n(&DAT_00250cd0,2);
  if (iVar2 == 0) {
    if (param_1 != param_2) {
      memcpy(param_2,param_1,0xc0);
      return CONCAT44(param_2,param_1);
    }
  }
  else {
    uVar3 = (uint)DAT_00250cd4;
    DAT_00250cd4 = DAT_00250cd4 + 1;
    uVar4 = ae_l32_ip(*param_1);
    param_1 = param_1 + 1;
    uVar1 = ae_s32_l_i(uVar4);
    (&DAT_00250cd8)[uVar3] = uVar1;
    uVar3 = (uint)DAT_00250cd4;
    if (DAT_00250cd2 <= uVar3) {
      DAT_00250cd4 = 0;
      uVar3 = 0;
    }
    uVar4 = ae_l32_i((&DAT_00250cd8)[uVar3]);
    uVar1 = ae_s32_l_ip(uVar4);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return CONCAT44(param_2,param_1);
}


// ===== FUN_0021e740 @ 0021e740 (17 bytes)

void FUN_0021e740(void)

{
  memset(&DAT_00251fa0,0,0x210);
  return;
}


// ===== aess_lowpass_fir @ 0021e754 (206 bytes)

/* AESS crossover (branch B): 257-tap low-pass, reg 0x4020 bits 15-12 = 1 gentle / 2 steep, bits
   11-0 = 700 or 1000 Hz (#184; was cw_fir_lowpass) */

void aess_lowpass_fir(undefined *param_1,undefined *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)DAT_20078040;
  uVar3 = (uint)(DAT_20078040 >> 0xc);
  uVar1 = (uint)DAT_00251fa2;
  if (DAT_00251fa0 != uVar2) {
    ae_s16i_n(uVar2,&DAT_00251fa0,0);
    if ((uVar3 != 1) && (uVar3 != 2)) {
      ae_s16i_n(0,&DAT_00251fa0,2);
      goto LAB_0021e780;
    }
    ae_s16i_n(uVar3,&DAT_00251fa0,2);
    uVar2 = uVar2 & 0xfff;
    if ((uVar2 == 700) || (uVar2 == 1000)) {
      DAT_00251fa4 = (undefined2)uVar2;
      if (uVar3 == 1) {
        if (uVar2 == 700) {
          DAT_00251fa8 = FLOAT_ARRAY_00203b70;
        }
        else {
          DAT_00251fa8 = FLOAT_ARRAY_00203f80;
        }
      }
      else if (uVar2 == 700) {
        DAT_00251fa8 = FLOAT_ARRAY_00204390;
      }
      else {
        DAT_00251fa8 = FLOAT_ARRAY_002047a0;
      }
      ae_s16i_n(uVar3,&DAT_00251fa0,2);
      DAT_002521b0 = fir_init(&DAT_002521c0,0x101);
      DAT_00251fac = 0;
      memset(&DAT_00251fb0,0,0x200);
      uVar1 = ae_l16ui_n(&DAT_00251fa0,2);
    }
    else {
      ae_s16i_n(uVar3,&DAT_00251fa0,2);
      uVar1 = uVar3;
    }
  }
  if (uVar1 - 1 < 2) {
    if (param_1 == param_2) {
      memcpy(&DAT_00252a00,param_1,0xc0);
      param_1 = &DAT_00252a00;
    }
    fir_process(DAT_002521b0,param_2,param_1,0x30);
    return;
  }
LAB_0021e780:
  if (param_1 != param_2) {
    memcpy(param_2,param_1,0xc0);
  }
  return;
}


// ===== branch_a_align_delay @ 0021e82c (91 bytes)

/* 128 samples = the AESS FIR group delay, only while that FIR is on */

undefined8 branch_a_align_delay(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  iVar2 = ae_l16ui_n(&DAT_00251fa0,2);
  if (iVar2 == 0) {
    if (param_1 != param_2) {
      memcpy(param_2,param_1,0xc0);
      return CONCAT44(param_2,param_1);
    }
  }
  else {
    uVar3 = (uint)DAT_00251fac;
    uVar5 = ae_l32_ip(*param_1);
    param_1 = param_1 + 1;
    uVar4 = ae_l32_i(*(undefined4 *)(&DAT_00251fb0 + (uint)DAT_00251fac * 4));
    uVar1 = ae_s32_l_ip(uVar4);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    DAT_00251fac = DAT_00251fac + 1;
    uVar1 = ae_s32_l_i(uVar5);
    *(undefined4 *)(&DAT_00251fb0 + uVar3 * 4) = uVar1;
    if (0x7f < DAT_00251fac) {
      DAT_00251fac = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}


// ===== FUN_0021e890 @ 0021e890 (30 bytes)

void FUN_0021e890(void)

{
  memset(&DAT_00252ac0,0,0x70);
  DAT_00252ac0 = 0x47;
  DAT_00252af8 = 0x55;
  return;
}


// ===== af_locut @ 0021e8b0 (860 bytes)

/* 6 or 18 dB/oct high-pass, regs 0x47 / 0x55 */

void af_locut(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined2 uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined8 in_aed0;
  ulonglong uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  uint uVar19;
  undefined *puVar20;
  undefined4 *puVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  
  iVar7 = param_1 * 0x38;
  iVar9 = ae_l16ui_n(&DAT_00252ac0 + param_1 * 0x1c,0);
  uVar10 = ae_l16ui_n(&DAT_20070000 + iVar9 * 2,0);
  sVar8 = 0;
  if (*(ushort *)(&DAT_00252ac2 + iVar7) != uVar10) {
    *(short *)(&DAT_00252ac2 + iVar7) = (short)uVar10;
    uVar19 = uVar10 >> 0xc;
    if ((uVar19 != 1) && (uVar19 != 2)) {
      *(undefined2 *)(&DAT_00252ac4 + iVar7) = 0;
      goto LAB_0021ea5a;
    }
    puVar20 = (undefined *)(uVar10 & 0xfff);
    *(short *)(&DAT_00252ac4 + iVar7) = (short)uVar19;
    if ((&DAT_0000176f < puVar20) || (puVar20 != (undefined *)0x0)) {
      iVar9 = (uint)(puVar20 < &DAT_0000176f) * (int)puVar20 +
              (uint)(puVar20 >= &DAT_0000176f) * (int)&DAT_0000176f;
    }
    else {
      iVar9 = 1;
    }
    uVar11 = ae_zext16(iVar9);
    i2f_scaled(uVar11,0);
    *(undefined4 *)(&DAT_00252aec + iVar7) = 0;
    *(undefined4 *)(&DAT_00252af0 + iVar7) = 0;
    *(undefined4 *)(&DAT_00252af4 + iVar7) = 0;
    uVar11 = ae_s32_l_i(in_aed0);
    *(undefined4 *)(&DAT_00252ac8 + iVar7) = uVar11;
    puVar21 = (undefined4 *)(&DAT_00252adc + iVar7);
    uVar17 = ae_l32_i(*(undefined4 *)(&DAT_00252ac8 + iVar7));
    uVar11 = ae_s32_l_i((ulonglong)(uint)((float)uVar17 * 6.2831855 * 8.333333e-05));
    uVar17 = const_s(3);
    if (*(short *)(&DAT_00252ac4 + iVar7) == 1) {
      uVar22 = ae_l32_i(uVar11);
      uVar23 = ae_l32_i(0x3f000000);
      uVar17 = ae_l32_i(0x3f490fdb);
      uVar16 = (ulonglong)(uint)((float)uVar22 * (float)uVar23 + (float)uVar17);
      sinf_();
      uVar17 = ae_l32_i(0);
      uVar12 = oeq_s(uVar16,uVar17);
      uVar4 = ae_s32_l_i(uVar16);
      if (!SUB21(uVar12,0)) {
        uVar22 = ae_l32_i(0xbf000000);
        uVar23 = ae_l32_i(uVar11);
        uVar17 = ae_l32_i(0x3f490fdb);
        uVar16 = (ulonglong)(uint)((float)uVar23 * (float)uVar22 + (float)uVar17);
        sinf_();
        ae_l32_i(uVar4);
        divf_();
      }
      uVar17 = ae_l32_i(0x3f800000);
      fVar3 = (float)uVar17 + (float)uVar16;
      uVar11 = ae_s32_l_i((ulonglong)(uint)-(float)uVar16);
      *(undefined4 *)(&DAT_00252ae0 + iVar7) = uVar11;
      uVar22 = ae_l32_i(0x3f000000);
      uVar11 = ae_s32_l_i(uVar17);
      *puVar21 = uVar11;
      uVar17 = ae_l32_i(0);
      uVar11 = ae_s32_l_i(uVar17);
      *(undefined4 *)(&DAT_00252ad8 + iVar7) = uVar11;
      uVar11 = ae_s32_l_i(uVar17);
      *(undefined4 *)(&DAT_00252ad4 + iVar7) = uVar11;
      uVar11 = ae_s32_l_i(uVar17);
      *(undefined4 *)(&DAT_00252ae8 + iVar7) = uVar11;
      uVar11 = ae_s32_l_i(uVar17);
      *(undefined4 *)(&DAT_00252ae4 + iVar7) = uVar11;
      uVar11 = ae_s32_l_i((ulonglong)(uint)(fVar3 * (float)uVar22));
      *(undefined4 *)(&DAT_00252acc + iVar7) = uVar11;
      uVar11 = ae_s32_l_i((ulonglong)(uint)(fVar3 * -0.5));
      *(undefined4 *)(&DAT_00252ad0 + iVar7) = uVar11;
    }
    else {
      uVar23 = ae_l32_i(uVar11);
      uVar22 = ae_l32_i(0x3f490fdb);
      uVar16 = (ulonglong)(uint)((float)uVar23 * (float)uVar17 + (float)uVar22);
      sinf_();
      uVar17 = ae_l32_i(0);
      uVar12 = oeq_s(uVar16,uVar17);
      uVar4 = ae_s32_l_i(uVar16);
      if (!SUB21(uVar12,0)) {
        uVar22 = ae_l32_i(0xbf000000);
        uVar23 = ae_l32_i(uVar11);
        uVar17 = ae_l32_i(0x3f490fdb);
        uVar16 = (ulonglong)(uint)((float)uVar23 * (float)uVar22 + (float)uVar17);
        sinf_();
        ae_l32_i(uVar4);
        divf_();
      }
      uVar17 = const_s(2);
      fVar13 = (float)uVar16;
      fVar14 = fVar13 * fVar13;
      fVar3 = fVar13 * fVar14;
      uVar16 = (ulonglong)(uint)(fVar14 * -22.0 + -2.0);
      uVar29 = (ulonglong)(uint)(fVar13 * 22.0 + fVar3 * (float)uVar17);
      uVar4 = ae_s32_l_i(uVar16);
      uVar11 = ae_s32_l_i(uVar16);
      *(undefined4 *)(&DAT_00252ae4 + iVar7) = uVar11;
      uVar28 = (ulonglong)(uint)((float)uVar17 * fVar13 + fVar3 * 6.0);
      uVar1 = ae_s32_l_i(uVar29);
      fVar15 = fVar13 * -3.0 + (fVar14 * -3.0 - fVar3) + -1.0;
      uVar11 = ae_s32_l_i(uVar29);
      *(undefined4 *)(&DAT_00252ae0 + iVar7) = uVar11;
      uVar2 = ae_s32_l_i(uVar28);
      uVar16 = (ulonglong)(uint)(fVar14 * -2.0 + -6.0);
      uVar11 = ae_s32_l_i(uVar28);
      *(undefined4 *)(&DAT_00252ae8 + iVar7) = uVar11;
      uVar5 = ae_s32_l_i((ulonglong)(uint)fVar15);
      uVar11 = ae_s32_l_i((ulonglong)(uint)fVar15);
      *(undefined4 *)(&DAT_00252acc + iVar7) = uVar11;
      fVar3 = fVar13 * 9.0 + fVar14 * 9.0 + fVar3 * 3.0 + 3.0;
      uVar11 = ae_s32_l_i(uVar16);
      *puVar21 = uVar11;
      uVar17 = ae_l32_i(0);
      uVar12 = oeq_s(uVar16,uVar17);
      uVar11 = ae_s32_l_i((ulonglong)(uint)-fVar15);
      *(undefined4 *)(&DAT_00252ad8 + iVar7) = uVar11;
      uVar11 = ae_s32_l_i((ulonglong)(uint)fVar3);
      uVar6 = ae_s32_l_i((ulonglong)(uint)fVar3);
      *(undefined4 *)(&DAT_00252ad0 + iVar7) = uVar6;
      uVar6 = ae_s32_l_i((ulonglong)(uint)-fVar3);
      *(undefined4 *)(&DAT_00252ad4 + iVar7) = uVar6;
      if (!SUB21(uVar12,0)) {
        uVar17 = ae_l32_i(0x3f800000);
        fVar15 = (float)uVar17;
        divf_();
        uVar17 = ae_l32_i(uVar1);
        uVar22 = ae_l32_i(uVar4);
        uVar23 = ae_l32_i(uVar2);
        uVar18 = ae_l32_i(uVar11);
        uVar24 = ae_l32_i(0x3f800000);
        uVar11 = ae_s32_l_i(uVar24);
        *puVar21 = uVar11;
        uVar24 = ae_l32_i(uVar5);
        fVar3 = fVar15 * (float)uVar18;
        uVar11 = ae_s32_l_i((ulonglong)(uint)((float)uVar17 * fVar15));
        *(undefined4 *)(&DAT_00252ae0 + iVar7) = uVar11;
        fVar14 = fVar15 * (float)uVar24;
        uVar11 = ae_s32_l_i((ulonglong)(uint)((float)uVar22 * fVar15));
        *(undefined4 *)(&DAT_00252ae4 + iVar7) = uVar11;
        uVar11 = ae_s32_l_i((ulonglong)(uint)((float)uVar23 * fVar15));
        *(undefined4 *)(&DAT_00252ae8 + iVar7) = uVar11;
        uVar11 = ae_s32_l_i((ulonglong)(uint)fVar3);
        *(undefined4 *)(&DAT_00252ad0 + iVar7) = uVar11;
        uVar11 = ae_s32_l_i((ulonglong)(uint)fVar14);
        *(undefined4 *)(&DAT_00252acc + iVar7) = uVar11;
        uVar11 = ae_s32_l_i((ulonglong)(uint)-fVar3);
        *(undefined4 *)(&DAT_00252ad4 + iVar7) = uVar11;
        uVar11 = ae_s32_l_i((ulonglong)(uint)-fVar14);
        *(undefined4 *)(&DAT_00252ad8 + iVar7) = uVar11;
      }
    }
  }
  sVar8 = *(short *)(&DAT_00252ac4 + iVar7);
LAB_0021ea5a:
  if (sVar8 == 1) {
    uVar22 = ae_l32_i(*(undefined4 *)(&DAT_00252aec + iVar7));
    uVar17 = ae_l32_ip(*param_2);
    uVar23 = ae_l32_i(*(undefined4 *)(&DAT_00252acc + iVar7));
    fVar3 = (float)uVar22 + (float)uVar23 * (float)uVar17;
    uVar11 = ae_s32_l_ip((ulonglong)(uint)fVar3);
    *param_3 = uVar11;
    uVar22 = ae_l32_i(*(undefined4 *)(&DAT_00252ad0 + iVar7));
    uVar23 = ae_l32_i(*(undefined4 *)(&DAT_00252ae0 + iVar7));
    uVar11 = ae_s32_l_i((ulonglong)(uint)((float)uVar22 * (float)uVar17 - (float)uVar23 * fVar3));
    *(undefined4 *)(&DAT_00252aec + iVar7) = uVar11;
    return;
  }
  if (sVar8 == 2) {
    uVar22 = ae_l32_i(*(undefined4 *)(&DAT_00252aec + iVar7));
    uVar17 = ae_l32_ip(*param_2);
    uVar23 = ae_l32_i(*(undefined4 *)(&DAT_00252acc + iVar7));
    fVar14 = (float)uVar17;
    fVar3 = (float)uVar22 + (float)uVar23 * fVar14;
    uVar11 = ae_s32_l_i((ulonglong)(uint)fVar3);
    *param_3 = uVar11;
    uVar17 = ae_l32_i(*(undefined4 *)(&DAT_00252ad0 + iVar7));
    uVar24 = ae_l32_i(*(undefined4 *)(&DAT_00252ae0 + iVar7));
    uVar22 = ae_l32_i(*(undefined4 *)(&DAT_00252af0 + iVar7));
    uVar25 = ae_l32_i(*(undefined4 *)(&DAT_00252ad4 + iVar7));
    uVar23 = ae_l32_i(*(undefined4 *)(&DAT_00252ae4 + iVar7));
    uVar26 = ae_l32_i(*(undefined4 *)(&DAT_00252af4 + iVar7));
    uVar18 = ae_l32_i(*(undefined4 *)(&DAT_00252ae8 + iVar7));
    uVar27 = ae_l32_i(*(undefined4 *)(&DAT_00252ad8 + iVar7));
    uVar11 = ae_s32_l_i((ulonglong)
                        (uint)((float)uVar22 + ((float)uVar17 * fVar14 - (float)uVar24 * fVar3)));
    *(undefined4 *)(&DAT_00252aec + iVar7) = uVar11;
    uVar17 = ae_l32_i(*param_3);
    uVar11 = ae_s32_l_i((ulonglong)
                        (uint)((float)uVar26 +
                              ((float)uVar25 * fVar14 - (float)uVar17 * (float)uVar23)));
    *(undefined4 *)(&DAT_00252af0 + iVar7) = uVar11;
    uVar17 = ae_l32_ip(*param_3);
    uVar11 = ae_s32_l_i((ulonglong)(uint)((float)uVar27 * fVar14 - (float)uVar17 * (float)uVar18));
    *(undefined4 *)(&DAT_00252af4 + iVar7) = uVar11;
    return;
  }
  if (param_2 != param_3) {
    memcpy(param_3,param_2,0xc0);
  }
  return;
}


// ===== FUN_0021ec20 @ 0021ec20 (30 bytes)

void FUN_0021ec20(void)

{
  memset(&DAT_00252b30,0,0x70);
  DAT_00252b30 = 0x46;
  DAT_00252b68 = 0x54;
  return;
}


// ===== af_hicut @ 0021ec40 (828 bytes)

/* 6 or 18 dB/oct low-pass, regs 0x46 / 0x54 */

void af_hicut(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined2 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined8 in_aed0;
  ulonglong uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  uint uVar18;
  undefined *puVar19;
  undefined4 *puVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  ulonglong uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  
  iVar6 = param_1 * 0x38;
  iVar8 = ae_l16ui_n(&DAT_00252b30 + param_1 * 0x1c,0);
  uVar9 = ae_l16ui_n(&DAT_20070000 + iVar8 * 2,0);
  sVar7 = 0;
  if (*(ushort *)(&DAT_00252b32 + iVar6) != uVar9) {
    *(short *)(&DAT_00252b32 + iVar6) = (short)uVar9;
    uVar18 = uVar9 >> 0xc;
    if ((uVar18 != 1) && (uVar18 != 2)) {
      *(undefined2 *)(&DAT_00252b34 + iVar6) = 0;
      goto LAB_0021ede4;
    }
    puVar19 = (undefined *)(uVar9 & 0xfff);
    *(short *)(&DAT_00252b34 + iVar6) = (short)uVar18;
    if ((&DAT_0000176f < puVar19) || (puVar19 != (undefined *)0x0)) {
      iVar8 = (uint)(puVar19 < &DAT_0000176f) * (int)puVar19 +
              (uint)(puVar19 >= &DAT_0000176f) * (int)&DAT_0000176f;
    }
    else {
      iVar8 = 1;
    }
    uVar10 = ae_zext16(iVar8);
    i2f_scaled(uVar10,0);
    *(undefined4 *)(&DAT_00252b5c + iVar6) = 0;
    *(undefined4 *)(&DAT_00252b60 + iVar6) = 0;
    *(undefined4 *)(&DAT_00252b64 + iVar6) = 0;
    uVar10 = ae_s32_l_i(in_aed0);
    *(undefined4 *)(&DAT_00252b38 + iVar6) = uVar10;
    puVar20 = (undefined4 *)(&DAT_00252b4c + iVar6);
    uVar16 = ae_l32_i(*(undefined4 *)(&DAT_00252b38 + iVar6));
    uVar10 = ae_s32_l_i((ulonglong)(uint)((float)uVar16 * 6.2831855 * 8.333333e-05));
    uVar16 = const_s(3);
    if (*(short *)(&DAT_00252b34 + iVar6) == 1) {
      uVar21 = ae_l32_i(uVar10);
      uVar22 = ae_l32_i(0x3f000000);
      uVar16 = ae_l32_i(0x3f490fdb);
      uVar15 = (ulonglong)(uint)((float)uVar21 * (float)uVar22 + (float)uVar16);
      sinf_();
      uVar16 = ae_l32_i(0);
      uVar11 = oeq_s(uVar15,uVar16);
      uVar1 = ae_s32_l_i(uVar15);
      if (!SUB21(uVar11,0)) {
        uVar21 = ae_l32_i(0xbf000000);
        uVar22 = ae_l32_i(uVar10);
        uVar16 = ae_l32_i(0x3f490fdb);
        uVar15 = (ulonglong)(uint)((float)uVar22 * (float)uVar21 + (float)uVar16);
        sinf_();
        ae_l32_i(uVar1);
        divf_();
      }
      uVar16 = ae_l32_i(0x3f800000);
      uVar10 = ae_s32_l_i((ulonglong)(uint)-(float)uVar15);
      *(undefined4 *)(&DAT_00252b50 + iVar6) = uVar10;
      uVar21 = ae_l32_i(0x3f000000);
      uVar10 = ae_s32_l_i(uVar16);
      *puVar20 = uVar10;
      uVar22 = ae_l32_i(0);
      uVar10 = ae_s32_l_i(uVar22);
      *(undefined4 *)(&DAT_00252b48 + iVar6) = uVar10;
      uVar15 = (ulonglong)(uint)(((float)uVar16 - (float)uVar15) * (float)uVar21);
      uVar10 = ae_s32_l_i(uVar22);
      *(undefined4 *)(&DAT_00252b44 + iVar6) = uVar10;
      uVar10 = ae_s32_l_i(uVar22);
      *(undefined4 *)(&DAT_00252b58 + iVar6) = uVar10;
      uVar10 = ae_s32_l_i(uVar22);
      *(undefined4 *)(&DAT_00252b54 + iVar6) = uVar10;
      uVar10 = ae_s32_l_i(uVar15);
      *(undefined4 *)(&DAT_00252b40 + iVar6) = uVar10;
      uVar10 = ae_s32_l_i(uVar15);
      *(undefined4 *)(&DAT_00252b3c + iVar6) = uVar10;
    }
    else {
      uVar22 = ae_l32_i(uVar10);
      uVar21 = ae_l32_i(0x3f490fdb);
      uVar15 = (ulonglong)(uint)((float)uVar22 * (float)uVar16 + (float)uVar21);
      sinf_();
      uVar16 = ae_l32_i(0);
      uVar11 = oeq_s(uVar15,uVar16);
      uVar1 = ae_s32_l_i(uVar15);
      if (!SUB21(uVar11,0)) {
        uVar21 = ae_l32_i(0xbf000000);
        uVar22 = ae_l32_i(uVar10);
        uVar16 = ae_l32_i(0x3f490fdb);
        uVar15 = (ulonglong)(uint)((float)uVar22 * (float)uVar21 + (float)uVar16);
        sinf_();
        ae_l32_i(uVar1);
        divf_();
      }
      fVar12 = (float)uVar15;
      fVar14 = fVar12 * fVar12;
      fVar13 = fVar12 * fVar14;
      uVar16 = const_s(2);
      uVar15 = (ulonglong)(uint)(fVar14 * 22.0 + (float)uVar16);
      uVar28 = (ulonglong)(uint)(fVar14 * (float)uVar16 + 6.0);
      uVar10 = ae_s32_l_i(uVar15);
      uVar29 = (ulonglong)(uint)(fVar12 * -22.0 + fVar13 * -2.0);
      uVar1 = ae_s32_l_i(uVar15);
      *(undefined4 *)(&DAT_00252b54 + iVar6) = uVar1;
      uVar15 = (ulonglong)(uint)(fVar12 * -2.0 + fVar13 * -6.0);
      uVar1 = ae_s32_l_i(uVar28);
      *puVar20 = uVar1;
      uVar16 = ae_l32_i(0);
      uVar27 = (ulonglong)(uint)(fVar12 * -9.0 + fVar14 * 9.0 + fVar13 * -3.0 + 3.0);
      uVar11 = oeq_s(uVar28,uVar16);
      uVar2 = ae_s32_l_i(uVar29);
      uVar3 = ae_s32_l_i(uVar15);
      uVar4 = ae_s32_l_i(uVar27);
      uVar1 = ae_s32_l_i(uVar29);
      *(undefined4 *)(&DAT_00252b50 + iVar6) = uVar1;
      uVar16 = ae_l32_i(0x3f800000);
      uVar1 = ae_s32_l_i(uVar15);
      *(undefined4 *)(&DAT_00252b58 + iVar6) = uVar1;
      uVar15 = (ulonglong)(uint)(fVar12 * -3.0 + (fVar14 * 3.0 - fVar13) + (float)uVar16);
      uVar1 = ae_s32_l_i(uVar27);
      *(undefined4 *)(&DAT_00252b44 + iVar6) = uVar1;
      uVar1 = ae_s32_l_i(uVar27);
      *(undefined4 *)(&DAT_00252b40 + iVar6) = uVar1;
      uVar1 = ae_s32_l_i(uVar15);
      uVar5 = ae_s32_l_i(uVar15);
      *(undefined4 *)(&DAT_00252b48 + iVar6) = uVar5;
      uVar5 = ae_s32_l_i(uVar15);
      *(undefined4 *)(&DAT_00252b3c + iVar6) = uVar5;
      if (!SUB21(uVar11,0)) {
        uVar16 = ae_l32_i(0x3f800000);
        fVar14 = (float)uVar16;
        divf_();
        uVar16 = ae_l32_i(uVar4);
        uVar15 = (ulonglong)(uint)(fVar14 * (float)uVar16);
        uVar16 = ae_l32_i(uVar1);
        uVar21 = ae_l32_i(0x3f800000);
        uVar27 = (ulonglong)(uint)(fVar14 * (float)uVar16);
        uVar1 = ae_s32_l_i(uVar21);
        *puVar20 = uVar1;
        uVar16 = ae_l32_i(uVar2);
        uVar1 = ae_s32_l_i(uVar15);
        *(undefined4 *)(&DAT_00252b40 + iVar6) = uVar1;
        uVar21 = ae_l32_i(uVar10);
        uVar10 = ae_s32_l_i(uVar15);
        *(undefined4 *)(&DAT_00252b44 + iVar6) = uVar10;
        uVar22 = ae_l32_i(uVar3);
        uVar10 = ae_s32_l_i(uVar27);
        *(undefined4 *)(&DAT_00252b3c + iVar6) = uVar10;
        uVar10 = ae_s32_l_i(uVar27);
        *(undefined4 *)(&DAT_00252b48 + iVar6) = uVar10;
        uVar10 = ae_s32_l_i((ulonglong)(uint)((float)uVar16 * fVar14));
        *(undefined4 *)(&DAT_00252b50 + iVar6) = uVar10;
        uVar10 = ae_s32_l_i((ulonglong)(uint)((float)uVar21 * fVar14));
        *(undefined4 *)(&DAT_00252b54 + iVar6) = uVar10;
        uVar10 = ae_s32_l_i((ulonglong)(uint)((float)uVar22 * fVar14));
        *(undefined4 *)(&DAT_00252b58 + iVar6) = uVar10;
      }
    }
  }
  sVar7 = *(short *)(&DAT_00252b34 + iVar6);
LAB_0021ede4:
  if (sVar7 == 1) {
    uVar21 = ae_l32_i(*(undefined4 *)(&DAT_00252b5c + iVar6));
    uVar16 = ae_l32_ip(*param_2);
    uVar22 = ae_l32_i(*(undefined4 *)(&DAT_00252b3c + iVar6));
    fVar14 = (float)uVar21 + (float)uVar22 * (float)uVar16;
    uVar10 = ae_s32_l_ip((ulonglong)(uint)fVar14);
    *param_3 = uVar10;
    uVar21 = ae_l32_i(*(undefined4 *)(&DAT_00252b40 + iVar6));
    uVar22 = ae_l32_i(*(undefined4 *)(&DAT_00252b50 + iVar6));
    uVar10 = ae_s32_l_i((ulonglong)(uint)((float)uVar21 * (float)uVar16 - (float)uVar22 * fVar14));
    *(undefined4 *)(&DAT_00252b5c + iVar6) = uVar10;
    return;
  }
  if (sVar7 == 2) {
    uVar21 = ae_l32_i(*(undefined4 *)(&DAT_00252b5c + iVar6));
    uVar16 = ae_l32_ip(*param_2);
    uVar22 = ae_l32_i(*(undefined4 *)(&DAT_00252b3c + iVar6));
    fVar13 = (float)uVar16;
    fVar14 = (float)uVar21 + (float)uVar22 * fVar13;
    uVar10 = ae_s32_l_i((ulonglong)(uint)fVar14);
    *param_3 = uVar10;
    uVar16 = ae_l32_i(*(undefined4 *)(&DAT_00252b40 + iVar6));
    uVar23 = ae_l32_i(*(undefined4 *)(&DAT_00252b50 + iVar6));
    uVar21 = ae_l32_i(*(undefined4 *)(&DAT_00252b60 + iVar6));
    uVar24 = ae_l32_i(*(undefined4 *)(&DAT_00252b44 + iVar6));
    uVar22 = ae_l32_i(*(undefined4 *)(&DAT_00252b54 + iVar6));
    uVar25 = ae_l32_i(*(undefined4 *)(&DAT_00252b64 + iVar6));
    uVar17 = ae_l32_i(*(undefined4 *)(&DAT_00252b58 + iVar6));
    uVar26 = ae_l32_i(*(undefined4 *)(&DAT_00252b48 + iVar6));
    uVar10 = ae_s32_l_i((ulonglong)
                        (uint)((float)uVar21 + ((float)uVar16 * fVar13 - (float)uVar23 * fVar14)));
    *(undefined4 *)(&DAT_00252b5c + iVar6) = uVar10;
    uVar16 = ae_l32_i(*param_3);
    uVar10 = ae_s32_l_i((ulonglong)
                        (uint)((float)uVar25 +
                              ((float)uVar24 * fVar13 - (float)uVar16 * (float)uVar22)));
    *(undefined4 *)(&DAT_00252b60 + iVar6) = uVar10;
    uVar16 = ae_l32_ip(*param_3);
    uVar10 = ae_s32_l_i((ulonglong)(uint)((float)uVar26 * fVar13 - (float)uVar16 * (float)uVar17));
    *(undefined4 *)(&DAT_00252b64 + iVar6) = uVar10;
    return;
  }
  if (param_2 != param_3) {
    memcpy(param_3,param_2,0xc0);
  }
  return;
}


// ===== if_agc_init @ 0021ef90 (116 bytes)

void if_agc_init(void)

{
  undefined8 uVar1;
  
  uVar1 = const_s(0);
  DAT_00252bc0 = ae_s32_l_i(uVar1);
  DAT_00252bc8 = ae_s32_l_i(uVar1);
  DAT_00252bcc = ae_s32_l_i(uVar1);
  DAT_00252bd0 = ae_s32_l_i(uVar1);
  DAT_00252bd8 = ae_s32_l_i(uVar1);
  DAT_00252bdc = ae_s32_l_i(uVar1);
  DAT_00252be0 = ae_s32_l_i(uVar1);
  DAT_00252be4 = ae_s32_l_i(uVar1);
  DAT_00252be8 = ae_s32_l_i(uVar1);
  uVar1 = const_s(1);
  DAT_00252bbc = ae_s32_l_i(uVar1);
  DAT_00252bd4 = 0x42fe0000;
  DAT_00252ba8 = 0;
  DAT_00252baa = 0;
  DAT_00252bac = 0;
  DAT_00252bae = 0;
  ae_s16i_n(&DAT_0000ffff,0x252ba0,0);
  ae_s16i_n(&DAT_0000ffff,0x252ba0,2);
  DAT_00252ba4 = 0xffff;
  DAT_00252bb8 = 0x3c888889;
  DAT_00252ba6 = 0xffff;
  memset(&DAT_00252c00,0,0xc0);
  DAT_00252bec = 0;
  uVar1 = ae_l32_i(0x3f800000);
  DAT_00252bf0 = ae_s32_l_i(uVar1);
  return;
}


// ===== if_agc_params @ 0021f004 (213 bytes)

/* regs 0x62 on, 0x63 gain ceiling 0.2512 10^((255 - x)/40), 0x66 decay, 0x67 10^((x - 255)/40) */

bool if_agc_params(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  ulonglong in_aed0;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar6 = (uint)DAT_00252ba0;
  uVar9 = (uint)DAT_200700c4;
  uVar10 = (uint)DAT_00252ba2;
  if (uVar6 != uVar9) {
    ae_s16i_n(uVar9,&DAT_00252ba0,0);
    DAT_00252ba8 = DAT_200700c4;
  }
  uVar1 = (uint)DAT_200700ce;
  if (uVar10 != uVar1) {
    iVar3 = ae_sext16(uVar1);
    DAT_00252ba2 = DAT_200700ce;
    i2f_scaled(iVar3 + -0xff,0);
    uVar5 = ae_l32_i(0x3ccccccd);
    in_aed0 = (ulonglong)(uint)((float)in_aed0 * (float)uVar5);
    pow10f_();
    DAT_00252bb0 = ae_s32_l_i(in_aed0);
  }
  uVar7 = (uint)DAT_200700c6;
  uVar11 = (uint)DAT_00252ba4;
  if (uVar11 != uVar7) {
    iVar3 = ae_sext16(uVar7);
    DAT_00252ba4 = DAT_200700c6;
    i2f_scaled(0xff - iVar3,0);
    uVar5 = ae_l32_i(0x3ccccccd);
    in_aed0 = (ulonglong)(uint)((float)in_aed0 * (float)uVar5);
    pow10f_();
    DAT_00252bb4 = ae_s32_l_i((ulonglong)(uint)((float)in_aed0 * 0.25118864));
  }
  uVar8 = (uint)DAT_200700cc;
  if (DAT_00252ba6 == uVar8) {
    return uVar11 != uVar7 || (uVar10 != uVar1 || uVar6 != uVar9);
  }
  DAT_00252ba6 = DAT_200700cc;
  uVar6 = 0x14;
  if (0x14 < uVar8) {
    uVar6 = uVar8;
  }
  uVar9 = ae_zext16(uVar6);
  uVar6 = 4000;
  if (uVar9 < 4000) {
    uVar6 = uVar9;
  }
  uVar2 = ae_zext16(uVar6);
  i2f_scaled(uVar2,0);
  ae_mov(in_aed0);
  fVar4 = 40.0;
  divf_();
  divf_();
  DAT_00252bbc = ae_s32_l_i((ulonglong)(uint)(fVar4 * 24.0));
  return true;
}


// ===== if_agc_process @ 0021f0dc (494 bytes)

/* feed-forward IF AGC, target -12 dBFS, 1-block look-ahead, 20 ms hang, decay reg 0x66 */

void if_agc_process(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  float fVar8;
  undefined8 uVar9;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar1 = if_agc_params();
  uVar7 = ae_l32_i(DAT_00252bc0);
  DAT_00252bc4 = ae_s32_l_i(uVar7);
  vec_sum_sq(param_1,0x18);
  uVar4 = (ulonglong)(uint)((float)uVar7 * 0.041666668);
  uStack_2c = ae_s32_l_i(uVar4);
  sqrtf_();
  uVar3 = oeq_s(uVar4,uVar4);
  if (!SUB21(uVar3,0)) {
    uVar4 = ae_l32_i(uStack_2c);
    FUN_00229a20();
  }
  uVar6 = ae_l32_i(DAT_00252bc4);
  uVar7 = const_s(3);
  DAT_00252bc0 = ae_s32_l_i(uVar4);
  uVar7 = ae_mov((ulonglong)(uint)(((float)uVar4 + (float)uVar6) * (float)uVar7));
  local_30 = ae_s32_l_i(uVar7);
  if_meter_tick();
  FUN_0021f2d0(&local_30,param_1,&DAT_00252cc0);
  uVar7 = ae_l32_i(DAT_00252bb4);
  uVar6 = ae_l32_i(DAT_00252bb0);
  uVar4 = (ulonglong)(uint)((float)uVar6 * (float)uVar7);
  DAT_00252bc8 = ae_s32_l_i(uVar4);
  log10f_();
  uVar7 = ae_l32_i(local_30);
  uVar6 = const_s(0);
  uVar3 = oeq_s(uVar7,uVar6);
  DAT_00252bcc = ae_s32_l_i((ulonglong)(uint)((float)uVar4 * 20.0));
  uVar7 = ae_l32_i(DAT_00252bc8);
  if (SUB21(uVar3,0)) {
    uStack_28 = ae_s32_l_i(uVar7);
  }
  else {
    uStack_24 = ae_s32_l_i(uVar7);
    uVar7 = 0x3e809bcc;
    divf_();
    uStack_28 = ae_s32_l_i(uVar7);
    uVar7 = ae_l32_i(uStack_24);
  }
  uVar6 = ae_l32_i(uStack_28);
  uVar3 = olt_s(uVar7,uVar6);
  uVar7 = movt_s(uVar6,uVar7,(char)uVar3);
  uStack_28 = ae_s32_l_i(uVar7);
  log10f_();
  uVar6 = ae_l32_i(0x41a00000);
  uVar5 = (ulonglong)(uint)((float)uVar7 * (float)uVar6);
  uVar7 = ae_l32_i(DAT_00252bd4);
  uVar3 = olt_s(uVar5,uVar7);
  uVar6 = ae_l32_i(0);
  uVar4 = ae_l32_i(uStack_28);
  uVar9 = const_s(1);
  if ((SUB21(uVar3,0)) || (iVar1 != 0)) {
    DAT_00252bd4 = ae_s32_l_i(uVar5);
    DAT_00252bd0 = ae_s32_l_i(uVar4);
    ae_s16i_n(0,&DAT_00252ba8,2);
    DAT_00252bd8 = ae_s32_l_i(uVar6);
    uVar7 = ae_mov(uVar5);
  }
  else {
    iVar1 = ae_l16ui_n(&DAT_00252ba8,2);
    if (iVar1 != 0) {
      uVar6 = ae_l32_i(DAT_00252bcc);
      uVar7 = ae_l32_i(DAT_00252be0);
      uVar3 = olt_s(uVar7,uVar6);
      if (SUB21(uVar3,0)) {
        uVar9 = ae_l32_i(DAT_00252bbc);
        fVar8 = (float)uVar9 + (float)uVar7;
        uVar3 = olt_s(uVar6,(ulonglong)(uint)fVar8);
        if (SUB21(uVar3,0)) {
          DAT_00252be0 = ae_s32_l_i(uVar6);
          uVar7 = ae_mov(uVar6);
          fVar8 = (float)uVar7;
        }
        else {
          DAT_00252be0 = ae_s32_l_i((ulonglong)(uint)fVar8);
        }
        uVar4 = (ulonglong)(uint)(fVar8 * 0.05);
        pow10f_(&DAT_00204bd4,0);
        DAT_00252bdc = ae_s32_l_i(uVar4);
        uVar7 = ae_l32_i(DAT_00252be0);
      }
      else {
        uVar4 = ae_l32_i(DAT_00252bdc);
      }
      DAT_00252bd4 = ae_s32_l_i(uVar7);
      DAT_00252bd0 = ae_s32_l_i(uVar4);
      goto LAB_0021f1d9;
    }
    uVar6 = ae_l32_i(DAT_00252bd8);
    uVar4 = ae_l32_i(DAT_00252bd0);
  }
  uVar3 = olt_s(uVar6,uVar9);
  uVar9 = ae_l32_i(DAT_00252bb8);
  if (SUB21(uVar3,0)) {
    DAT_00252bd8 = ae_s32_l_i((ulonglong)(uint)((float)uVar9 + (float)uVar6));
  }
  else {
    uVar6 = ae_l32_i(DAT_00252bbc);
    uVar3 = olt_s((ulonglong)(uint)((float)uVar6 + (float)uVar7),uVar5);
    DAT_00252be0 = ae_s32_l_i(uVar7);
    DAT_00252bdc = ae_s32_l_i(uVar4);
    uVar7 = ae_l32_i(0);
    if (SUB21(uVar3,0)) {
      ae_s16i_n(1,&DAT_00252ba8,2);
    }
    else {
      DAT_00252bd8 = ae_s32_l_i(uVar7);
    }
  }
LAB_0021f1d9:
  iVar1 = ae_l16ui_n(&DAT_00252ba8,0);
  if (iVar1 == 0) {
    uVar4 = ae_l32_i(DAT_00252bc8);
    DAT_00252be4 = ae_s32_l_i(uVar4);
  }
  else {
    DAT_00252be4 = ae_s32_l_i(uVar4);
  }
  iVar1 = ae_l16ui_n(&DAT_00252d20,0);
  DAT_00252be8 = ae_s32_l_i(uVar4);
  memcpy(&DAT_00252c00 + iVar1 * 0x60,&DAT_00252cc0,0x60);
  uVar2 = ae_l16ui_n(&DAT_00252d20,0);
  iVar1 = ae_zext16(uVar2 ^ 1);
  ae_l32_i(DAT_00252be8);
  DAT_00252d20 = (undefined2)iVar1;
  vec_scale_f32(param_1,&DAT_00252c00 + iVar1 * 0x60,0x18);
  return;
}


// ===== FUN_0021f2d0 @ 0021f2d0 (78 bytes)

void FUN_0021f2d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  ulonglong uVar2;
  float fVar3;
  undefined8 uVar5;
  undefined8 uVar4;
  
  uVar4 = ae_l32_i(DAT_00252bf0);
  fVar3 = (float)uVar4;
  if ((int)(short)DAT_200700d0 != (uint)DAT_00252bec) {
    DAT_00252bec = DAT_200700d0;
    i2f_scaled((int)(short)DAT_200700d0,0xffffffff);
    uVar2 = (ulonglong)(uint)(fVar3 * 0.05);
    pow10f_();
    DAT_00252bf0 = ae_s32_l_i(uVar2);
  }
  vec_scale_f32(param_3,param_2,0x18);
  uVar4 = ae_l32_i(DAT_00252bf0);
  uVar5 = ae_l32_i(*param_1);
  uVar1 = ae_s32_l_i((ulonglong)(uint)((float)uVar5 * (float)uVar4));
  *param_1 = uVar1;
  return;
}


// ===== if_meter_tick @ 0021f320 (35 bytes)

/* every 60 blocks: reg 0x4005, reg 3 */

void if_meter_tick(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = ae_l16ui_n(&DAT_00252d22,0);
  uVar2 = ae_zext16(iVar1 + 1);
  if (uVar2 < 0x3c) {
    ae_s16i_n(uVar2,&DAT_00252d22,0);
    return;
  }
  ae_s16i_n(0,&DAT_00252d22,0);
  meter_to_reg4005(uVar2,&DAT_00252d22,0);
  status_reg3_update();
  return;
}


// ===== meter_to_reg4005 @ 0021f348 (62 bytes)

/* reg 0x4005 = 0..99 level for the M33 PWM; also level byte for reg 3 */

void meter_to_reg4005(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  
  puVar1 = (undefined *)f2i_scaled(0);
  puVar4 = &DAT_0000ffff;
  if (puVar1 < &DAT_0000ffff) {
    puVar4 = puVar1;
  }
  uVar2 = (uint)puVar4 >> 6 & 0xffff;
  uVar3 = 0xff;
  if (uVar2 < 0xff) {
    uVar3 = uVar2;
  }
  uVar5 = (uint)puVar4 >> 8 & 0xffff;
  uVar2 = 0xff;
  if (uVar5 < 0xff) {
    uVar2 = uVar5;
  }
  DAT_00252bac = (short)uVar3;
  DAT_2007800a = (short)(uVar2 * 100 >> 8);
  return;
}


// ===== status_reg3_update @ 0021f388 (122 bytes)

/* reg 3: hi = IF level, lo = AGC gain reduction (0.5 dB) */

void status_reg3_update(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar4 = ae_l32_i(DAT_00252be4);
  uVar5 = const_s(0);
  uVar3 = oeq_s(uVar4,uVar5);
  if (SUB21(uVar3,0)) {
    return;
  }
  ae_l32_i(DAT_00252bb0);
  log10f_();
  ae_l32_i(DAT_00252bcc);
  const_s(2);
  uVar1 = f2i_scaled(0);
  uVar2 = ae_zext16(uVar1);
  DAT_00252bae = 0xff - (short)uVar2;
  if (uVar2 < 0x100) {
    DAT_20070006 = DAT_00252bae | DAT_00252bac << 8;
    return;
  }
  DAT_00252bae = 0;
  DAT_20070006 = DAT_00252bac << 8;
  return;
}


// ===== FUN_0021f410 @ 0021f410 (113 bytes)

void FUN_0021f410(void)

{
  DAT_00252d30 = iir_cascade_init(&DAT_00252d40,5,&DAT_002373d0,1);
  DAT_00252d34 = iir_cascade_init(&DAT_00252e00,5,&DAT_002373d0,1);
  DAT_00252d38 = iir_cascade_init(&DAT_00252ec0,5,&DAT_002373d0,1);
  FUN_00220b30();
  cw_zero_in_init();
  FUN_0021e520();
  FUN_0021dbb0();
  spectral_nr_init();
  FUN_0021c890();
  FUN_0021cc50();
  FUN_0021c600();
  peak_limiter_init(1);
  FUN_0021ec20();
  FUN_0021e890();
  FUN_00220420();
  FUN_0021e740();
  FUN_0021e6b0();
  return;
}


// ===== rx_audio_chain @ 0021f484 (582 bytes)

/* Rx_Audio: /6, NR/notch/contour/APF/EQ, x6 */

void rx_audio_chain(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  iir_cascade_process(DAT_00252d30,&DAT_00252f80,param_1,0x120);
  uVar2 = ae_l32_ip(DAT_00252f80);
  DAT_00253400 = ae_s32_l_ip(uVar2);
  uVar2 = ae_l32_ip(DAT_00252f98);
  DAT_00253404 = ae_s32_l_ip(uVar2);
  if (DAT_2007000c != 10) {
    if (DAT_2007000c == 9) {
      fm_audio_post(&DAT_00253400,&DAT_00253400);
    }
    else {
      cw_zero_in_estimator(&DAT_00253400);
    }
  }
  manual_notch(&DAT_00253400,&DAT_00253400);
  spectral_nr(&DAT_00253400,&DAT_00253400);
  lms_ale_nr(&DAT_00253400,&DAT_00253400);
  nlms_auto_notch(&DAT_00253400,&DAT_00253400);
  contour_peaking(&DAT_00253400,&DAT_00253400);
  apf_peak_filter(&DAT_00253400,&DAT_00253400);
  peak_limiter(1,&DAT_00253400,&DAT_00253400);
  af_hicut(0,&DAT_00253400,&DAT_002534c0);
  af_locut(0,&DAT_002534c0,&DAT_002534c0);
  rx_eq_3band(&DAT_002534c0,&DAT_002534c0);
  branch_a_align_delay(&DAT_002534c0,&DAT_002534c0);
  af_hicut(1,&DAT_00253400,&DAT_00253580);
  af_locut(1,&DAT_00253580,&DAT_00253580);
  aess_lowpass_fir(&DAT_00253580,&DAT_00253580);
  branch_b_delay(&DAT_00253580,&DAT_00253580);
  memset(&DAT_00252f80,0,0x480);
  uVar2 = ae_l32_ip(DAT_002534c0);
  uVar3 = ae_l32_i(DAT_002534c4);
  uVar6 = ae_l32_i(DAT_002534c8);
  uVar4 = ae_l32_i(DAT_002534cc);
  uVar7 = ae_l32_ip(DAT_002534d0);
  uVar5 = ae_l32_i(DAT_002534d4);
  uVar8 = ae_l32_i(DAT_002534d8);
  uVar9 = ae_l32_i(DAT_002534dc);
  DAT_00252f80 = ae_s32_l_ip((ulonglong)(uint)((float)uVar2 * 6.0));
  uVar2 = ae_l32_ip(DAT_002534e0);
  DAT_00252f98 = ae_s32_l_ip((ulonglong)(uint)((float)uVar3 * 6.0));
  uVar3 = ae_l32_i(DAT_002534e4);
  DAT_00252fb0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * 6.0));
  uVar6 = ae_l32_i(DAT_002534e8);
  DAT_00252fc8 = ae_s32_l_ip((ulonglong)(uint)((float)uVar4 * 6.0));
  uVar4 = ae_l32_i(DAT_002534ec);
  DAT_00252fe0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * 6.0));
  DAT_00252ff8 = ae_s32_l_ip((ulonglong)(uint)((float)uVar5 * 6.0));
  DAT_00253010 = ae_s32_l_ip((ulonglong)(uint)((float)uVar8 * 6.0));
  DAT_00253028 = ae_s32_l_ip((ulonglong)(uint)((float)uVar9 * 6.0));
  DAT_00253040 = ae_s32_l_ip((ulonglong)(uint)((float)uVar2 * 6.0));
  DAT_00253058 = ae_s32_l_ip((ulonglong)(uint)((float)uVar3 * 6.0));
  DAT_00253070 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * 6.0));
  DAT_00253088 = ae_s32_l_ip((ulonglong)(uint)((float)uVar4 * 6.0));
  iir_cascade_process(DAT_00252d34,param_2,&DAT_00252f80,0x120);
  memset(&DAT_00252f80,0,0x480);
  uVar2 = ae_l32_ip(DAT_00253580);
  uVar3 = ae_l32_i(DAT_00253584);
  uVar4 = ae_l32_i(DAT_00253588);
  uVar7 = ae_l32_i(DAT_0025358c);
  uVar5 = ae_l32_ip(DAT_00253590);
  uVar6 = ae_l32_i(0x40c00000);
  fVar1 = (float)uVar6;
  uVar6 = ae_l32_i(DAT_00253594);
  uVar8 = ae_l32_i(DAT_00253598);
  uVar9 = ae_l32_i(DAT_0025359c);
  DAT_00252f80 = ae_s32_l_ip((ulonglong)(uint)((float)uVar2 * fVar1));
  uVar2 = ae_l32_ip(DAT_002535a0);
  DAT_00252f98 = ae_s32_l_ip((ulonglong)(uint)((float)uVar3 * fVar1));
  uVar3 = ae_l32_i(DAT_002535a4);
  DAT_00252fb0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar4 * fVar1));
  uVar4 = ae_l32_i(DAT_002535a8);
  DAT_00252fc8 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * fVar1));
  uVar7 = ae_l32_i(DAT_002535ac);
  DAT_00252fe0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar5 * fVar1));
  DAT_00252ff8 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * fVar1));
  DAT_00253010 = ae_s32_l_ip((ulonglong)(uint)((float)uVar8 * fVar1));
  DAT_00253028 = ae_s32_l_ip((ulonglong)(uint)((float)uVar9 * fVar1));
  DAT_00253040 = ae_s32_l_ip((ulonglong)(uint)((float)uVar2 * fVar1));
  DAT_00253058 = ae_s32_l_ip((ulonglong)(uint)((float)uVar3 * fVar1));
  DAT_00253070 = ae_s32_l_ip((ulonglong)(uint)((float)uVar4 * fVar1));
  DAT_00253088 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * fVar1));
  iir_cascade_process(DAT_00252d38,param_3,&DAT_00252f80,0x120);
  return;
}


// ===== ctcss_init @ 0021f6d0 (278 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ctcss_init(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  DAT_00253640 = 0;
  _DAT_00253644 = 0;
  DAT_00253648 = iir_cascade_init(&DAT_00253980,4,&DAT_00236940,1);
  DAT_0025364c = iir_cascade_init(&DAT_00253a20,8,&DAT_00236990,1);
  uVar10 = ae_l32_i(FLOAT_ARRAY_00204be0[_DAT_00253644 & 0xffff]);
  uVar11 = const_s(0);
  uVar4 = oeq_s(uVar10,uVar11);
  if (SUB21(uVar4,0)) {
    uVar10 = ae_l32_i(DAT_00253b5c);
  }
  else {
    DAT_00253b5c = ae_s32_l_i(uVar10);
  }
  fVar6 = (float)uVar10;
  if (DAT_00253646 == 0) {
    DAT_00253b40 = ae_s32_l_i((ulonglong)(uint)(fVar6 * 0.985));
    DAT_00253b78 = ae_s32_l_i((ulonglong)(uint)(fVar6 * 1.015));
  }
  else {
    DAT_00253b78 = ae_s32_l_i((ulonglong)(uint)(fVar6 * 1.02));
    DAT_00253b40 = ae_s32_l_i((ulonglong)(uint)(fVar6 * 0.98));
  }
  puVar3 = &DAT_00253b44;
  do {
    uVar10 = ae_l32_i(puVar3[-1]);
    uVar11 = ae_l32_i(0x43480000);
    uVar9 = ae_l32_i(0x3a2ec33e);
    uVar8 = ae_l32_i(0x40c90fdb);
    uVar7 = ae_l32_i(0x3ba3d70a);
    uVar5 = (ulonglong)
            (uint)((float)uVar10 * (float)uVar11 * (float)uVar9 * (float)uVar8 * (float)uVar7);
    uVar2 = ae_s32_l_i(uVar5);
    sinf_();
    uVar1 = ae_s32_l_i(uVar5);
    puVar3[3] = uVar1;
    uVar10 = ae_l32_i(uVar2);
    cosf_();
    uVar11 = ae_l32_i(&DAT_40000000);
    uVar1 = ae_s32_l_i(uVar10);
    puVar3[4] = uVar1;
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar10 * (float)uVar11));
    *puVar3 = uVar1;
    puVar3 = puVar3 + 7;
  } while (puVar3 != (undefined4 *)0x253b98);
  uVar10 = ae_l32_i(0);
  DAT_00253b4c = ae_s32_l_i(uVar10);
  DAT_00253b48 = ae_s32_l_i(uVar10);
  DAT_00253b58 = ae_s32_l_ip(uVar10);
  DAT_00253b68 = ae_s32_l_i(uVar10);
  DAT_00253b64 = ae_s32_l_i(uVar10);
  DAT_00253b74 = ae_s32_l_ip(uVar10);
  DAT_00253b84 = ae_s32_l_i(uVar10);
  DAT_00253b80 = ae_s32_l_i(uVar10);
  DAT_00253b90 = ae_s32_l_ip(uVar10);
  memset(&DAT_00253654,0,800);
  DAT_00253650 = 0;
  DAT_00253652 = 0;
  return;
}

