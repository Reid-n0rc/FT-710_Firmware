// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== ctcss_config @ 0021f7ec (207 bytes)

/* WARNING: Removing unreachable block (ram,0x0021f856) */
/* reg 0x53 */

void ctcss_config(void)

{
  undefined6 uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar3;
  
  uVar3 = (uint)DAT_200700a6;
  if (DAT_00253640._2_2_ != uVar3) {
    ae_s16i_n(uVar3,&DAT_00253640,2);
    if ((((DAT_200700a6 >> 0xc & 1) == 0) || ((DAT_200700a6 & 0xfff) == 0)) ||
       (0x32 < (uVar3 & 0xfff))) {
      ae_s16i_n(0,&DAT_00253640,0);
      DAT_00253644 = 0;
    }
    else {
      ae_s16i_n(1,&DAT_00253640,0);
      DAT_00253644 = DAT_200700a6;
      DAT_00253648 = iir_cascade_init(&DAT_00253980,4,&DAT_00236940,1);
      DAT_0025364c = iir_cascade_init(&DAT_00253a20,8,&DAT_00236990,1);
      ae_l32_i(FLOAT_ARRAY_00204be0[uVar3 & 0xfff]);
      ctcss_goertzel_init();
    }
    DAT_00253646 = 0;
    uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    if ((uVar3 & 0xf) < 2) {
      uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
      in_st_PSWOE = (undefined1)uVar1;
      in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
      in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
      in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
      in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
      in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
      rsync();
    }
    DAT_20070002 = DAT_20070002 & 0xffbf;
    uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    wsr_ps(uVar3 & 0xf | uVar2 & 0xfffffff0);
    rsync();
    return;
  }
  return;
}


// ===== ctcss_goertzel_retune @ 0021f8bc (166 bytes)

/* (f, 0 = keep): side bins 0.985 / 1.015 f while unlocked, 0.98 / 1.02 f while locked; sin and 2
   cos of 2 pi f / 1500 per bin (#184) */

void ctcss_goertzel_retune(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  float fVar5;
  undefined8 in_aed0;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  uVar7 = const_s(0);
  uVar4 = oeq_s(in_aed0,uVar7);
  if (SUB21(uVar4,0)) {
    in_aed0 = ae_l32_i(DAT_00253b5c);
  }
  else {
    DAT_00253b5c = ae_s32_l_i(in_aed0);
  }
  fVar5 = (float)in_aed0;
  if (DAT_00253646 == 0) {
    DAT_00253b40 = ae_s32_l_i((ulonglong)(uint)(fVar5 * 0.985));
    DAT_00253b78 = ae_s32_l_i((ulonglong)(uint)(fVar5 * 1.015));
  }
  else {
    DAT_00253b78 = ae_s32_l_i((ulonglong)(uint)(fVar5 * 1.02));
    DAT_00253b40 = ae_s32_l_i((ulonglong)(uint)(fVar5 * 0.98));
  }
  puVar3 = &DAT_00253b44;
  do {
    uVar8 = ae_l32_i(puVar3[-1]);
    uVar9 = ae_l32_i(0x43480000);
    uVar7 = ae_l32_i(0x3a2ec33e);
    uVar11 = ae_l32_i(0x40c90fdb);
    uVar10 = ae_l32_i(0x3ba3d70a);
    uVar6 = (ulonglong)
            (uint)((float)uVar8 * (float)uVar9 * (float)uVar7 * (float)uVar11 * (float)uVar10);
    uVar2 = ae_s32_l_i(uVar6);
    sinf_();
    uVar1 = ae_s32_l_i(uVar6);
    puVar3[3] = uVar1;
    uVar7 = ae_l32_i(uVar2);
    cosf_();
    uVar8 = ae_l32_i(&DAT_40000000);
    uVar1 = ae_s32_l_i(uVar7);
    puVar3[4] = uVar1;
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * (float)uVar8));
    *puVar3 = uVar1;
    puVar3 = puVar3 + 7;
  } while (puVar3 != (undefined4 *)0x253b98);
  return;
}


// ===== ctcss_goertzel_init @ 0021f968 (221 bytes)

/* (f): as ctcss_goertzel_retune, then clears the 3 Goertzel states and the 200-sample window (#184)
    */

void ctcss_goertzel_init(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  float fVar5;
  undefined8 in_aed0;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  uVar7 = const_s(0);
  uVar4 = oeq_s(in_aed0,uVar7);
  if (SUB21(uVar4,0)) {
    in_aed0 = ae_l32_i(DAT_00253b5c);
  }
  else {
    DAT_00253b5c = ae_s32_l_i(in_aed0);
  }
  fVar5 = (float)in_aed0;
  if (DAT_00253646 == 0) {
    DAT_00253b40 = ae_s32_l_i((ulonglong)(uint)(fVar5 * 0.985));
    DAT_00253b78 = ae_s32_l_i((ulonglong)(uint)(fVar5 * 1.015));
  }
  else {
    DAT_00253b78 = ae_s32_l_i((ulonglong)(uint)(fVar5 * 1.02));
    DAT_00253b40 = ae_s32_l_i((ulonglong)(uint)(fVar5 * 0.98));
  }
  puVar3 = &DAT_00253b44;
  do {
    uVar7 = ae_l32_i(puVar3[-1]);
    uVar8 = ae_l32_i(0x43480000);
    uVar11 = ae_l32_i(0x3a2ec33e);
    uVar10 = ae_l32_i(0x40c90fdb);
    uVar9 = ae_l32_i(0x3ba3d70a);
    uVar6 = (ulonglong)
            (uint)((float)uVar7 * (float)uVar8 * (float)uVar11 * (float)uVar10 * (float)uVar9);
    uVar2 = ae_s32_l_i(uVar6);
    sinf_();
    uVar1 = ae_s32_l_i(uVar6);
    puVar3[3] = uVar1;
    uVar7 = ae_l32_i(uVar2);
    cosf_();
    uVar8 = ae_l32_i(&DAT_40000000);
    uVar1 = ae_s32_l_i(uVar7);
    puVar3[4] = uVar1;
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * (float)uVar8));
    *puVar3 = uVar1;
    puVar3 = puVar3 + 7;
  } while (puVar3 != (undefined4 *)0x253b98);
  uVar7 = ae_l32_i(0);
  DAT_00253b4c = ae_s32_l_i(uVar7);
  DAT_00253b48 = ae_s32_l_i(uVar7);
  DAT_00253b58 = ae_s32_l_ip(uVar7);
  DAT_00253b68 = ae_s32_l_i(uVar7);
  DAT_00253b64 = ae_s32_l_i(uVar7);
  DAT_00253b74 = ae_s32_l_ip(uVar7);
  DAT_00253b84 = ae_s32_l_i(uVar7);
  DAT_00253b80 = ae_s32_l_i(uVar7);
  DAT_00253b90 = ae_s32_l_ip(uVar7);
  memset(&DAT_00253654,0,800);
  DAT_00253650 = 0;
  DAT_00253652 = 0;
  return;
}


// ===== ctcss_detect @ 0021fa48 (715 bytes)

/* sliding Goertzel, 3 bins, reg 1 bit 6 */

void ctcss_detect(undefined4 param_1)

{
  undefined6 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined2 uVar12;
  ulonglong uVar13;
  float fVar14;
  undefined8 uVar15;
  float fVar16;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined8 uVar17;
  ushort uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  
  ctcss_config();
  iVar9 = ae_l16ui_n(&DAT_00253640,0);
  if (iVar9 == 0) {
    return;
  }
  iir_cascade_process(DAT_00253648,&DAT_00253ba0,param_1,0x30);
  uVar17 = ae_l32_i(DAT_00253ba0);
  uVar19 = ae_l32_i(DAT_00253bc0);
  uVar15 = ae_l32_i(DAT_00253c00);
  DAT_00253c60 = ae_s32_l_ip(uVar17);
  uVar17 = ae_l32_i(DAT_00253be0);
  DAT_00253c64 = ae_s32_l_ip(uVar19);
  DAT_00253c68 = ae_s32_l_ip(uVar17);
  uVar17 = ae_l32_i(DAT_00253c20);
  DAT_00253c6c = ae_s32_l_ip(uVar15);
  DAT_00253c70 = ae_s32_l_ip(uVar17);
  uVar15 = ae_l32_i(DAT_00253c40);
  DAT_00253c74 = ae_s32_l_ip(uVar15);
  iir_cascade_process(DAT_0025364c,&DAT_00253ba0,&DAT_00253c60,6);
  uVar17 = const_s(0);
  uVar15 = ae_l32_i(DAT_00253ba0);
  uVar2 = ae_s32_l_i(uVar15);
  (&DAT_00253654)[DAT_00253650] = uVar2;
  uVar10 = ae_zext16(DAT_00253650 + 1);
  DAT_00253650 = (ushort)uVar10;
  if (199 < uVar10) {
    uVar10 = 0;
    DAT_00253650 = 0;
  }
  puVar8 = &DAT_00253b58;
  uVar10 = ae_zext16(uVar10 + 1);
  uVar15 = ae_mov(uVar17);
  if (199 < uVar10) {
    uVar10 = 0;
  }
  uVar2 = ae_s32_l_i(uVar17);
  uVar3 = ae_s32_l_i(uVar17);
  DAT_00253b58 = ae_s32_l_ip(uVar17);
  uVar4 = ae_s32_l_i(uVar17);
  uVar5 = ae_s32_l_i(uVar17);
  DAT_00253b74 = ae_s32_l_ip(uVar17);
  uVar6 = ae_s32_l_i(uVar17);
  uVar7 = ae_s32_l_i(uVar17);
  DAT_00253b90 = ae_s32_l_ip(uVar17);
  uVar17 = ae_l32_i(uVar3);
  uVar20 = ae_l32_i(DAT_00253b44);
  uVar21 = ae_l32_i(uVar2);
  uVar11 = ae_zext16(uVar10 + 1);
  uVar19 = ae_l32_i((&DAT_00253654)[uVar10]);
  DAT_00253652 = (undefined2)uVar11;
  if (199 < uVar11) {
    DAT_00253652 = 0;
  }
  DAT_00253b4c = ae_s32_l_i(uVar17);
  fVar14 = (float)uVar19;
  DAT_00253b48 = ae_s32_l_ip((ulonglong)
                             (uint)(fVar14 + ((float)uVar20 * (float)uVar17 - (float)uVar21)));
  uVar19 = ae_l32_i(uVar5);
  uVar20 = ae_l32_i(DAT_00253b60);
  uVar17 = ae_l32_i(uVar4);
  DAT_00253b68 = ae_s32_l_i(uVar19);
  DAT_00253b64 = ae_s32_l_ip((ulonglong)
                             (uint)(fVar14 + ((float)uVar20 * (float)uVar19 - (float)uVar17)));
  uVar19 = ae_l32_i(uVar7);
  uVar20 = ae_l32_i(DAT_00253b7c);
  uVar17 = ae_l32_i(uVar6);
  DAT_00253b84 = ae_s32_l_i(uVar19);
  DAT_00253b80 = ae_s32_l_ip((ulonglong)
                             (uint)(fVar14 + ((float)uVar20 * (float)uVar19 - (float)uVar17)));
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar15 + fVar14 * fVar14));
  do {
    uVar15 = ae_l32_i(puVar8[-3]);
    uVar17 = ae_l32_i(puVar8[-4]);
    fVar16 = (float)uVar15;
    fVar14 = (float)uVar17;
    uVar15 = ae_l32_i(puVar8[-5]);
    uVar13 = (ulonglong)
             (uint)((fVar14 * fVar14 + fVar16 * fVar16) - (float)uVar15 * fVar14 * fVar16);
    uVar3 = ae_s32_l_i(uVar13);
    sqrtf_();
    uVar12 = oeq_s(uVar13,uVar13);
    if (!SUB21(uVar12,0)) {
      uVar13 = ae_l32_i(uVar3);
      FUN_00229a20();
    }
    uVar3 = ae_s32_l_ip(uVar13);
    *puVar8 = uVar3;
    puVar8 = puVar8 + 7;
  } while (puVar8 != (undefined4 *)&DAT_00253bac);
  uVar15 = ae_l32_i(uVar2);
  uVar13 = (ulonglong)(uint)((float)uVar15 * 0.005);
  uVar2 = ae_s32_l_i(uVar13);
  sqrtf_();
  uVar12 = oeq_s(uVar13,uVar13);
  if (!SUB21(uVar12,0)) {
    uVar13 = ae_l32_i(uVar2);
    FUN_00229a20();
  }
  fVar14 = (float)uVar13 * 1.4142135;
  uVar12 = ole_s(0x3727c5ac,(ulonglong)(uint)fVar14);
  uVar18 = (ushort)(DAT_00253646 != 0);
  if (SUB21(uVar12,0)) {
    uVar15 = ae_l32_i(DAT_00253b74);
    if (DAT_00253646 == 0) {
      uVar17 = ae_l32_i(DAT_00253b58);
      uVar12 = olt_s(uVar17,uVar15);
      if (SUB21(uVar12,0)) {
        uVar17 = ae_l32_i(DAT_00253b90);
        uVar12 = olt_s(uVar17,uVar15);
        if ((SUB21(uVar12,0)) &&
           (uVar12 = olt_s((ulonglong)(uint)(fVar14 * 50.118725),uVar15), SUB21(uVar12,0))) {
          uVar18 = 1;
        }
      }
LAB_0021fcb9:
      if (DAT_00253646 == uVar18) {
        return;
      }
      goto LAB_0021fc50;
    }
    uVar12 = olt_s(uVar15,(ulonglong)(uint)(fVar14 * 3.1622777));
    if (!SUB21(uVar12,0)) {
      uVar17 = ae_l32_i(DAT_00253b58);
      uVar12 = olt_s(uVar15,uVar17);
      if (!SUB21(uVar12,0)) {
        uVar17 = ae_l32_i(DAT_00253b90);
        uVar12 = olt_s(uVar15,uVar17);
        if (!SUB21(uVar12,0)) goto LAB_0021fcb9;
      }
    }
  }
  if (DAT_00253646 == 0) {
    return;
  }
  uVar18 = 0;
LAB_0021fc50:
  DAT_00253646 = uVar18;
  ae_l32_i(0);
  ctcss_goertzel_retune();
  uVar10 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar11 = uVar10 & 0xf;
  if (uVar11 < 2) {
    uVar1 = wsr_ps(uVar10 & 0xfffffff0 | 2);
    in_st_PSWOE = (undefined1)uVar1;
    in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
  }
  if (DAT_00253646 != 0) {
    DAT_20070002 = DAT_20070002 | 0x40;
    uVar10 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL
                   );
    wsr_ps(uVar11 | uVar10 & 0xfffffff0);
    rsync();
    return;
  }
  DAT_20070002 = DAT_20070002 & 0xffbf;
  uVar10 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar11 | uVar10 & 0xfffffff0);
  rsync();
  return;
}


// ===== dcs_init @ 0021fd20 (152 bytes)

void dcs_init(void)

{
  undefined6 uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar3;
  
  memset(&DAT_00253c80,0,0x184);
  DAT_00253e04 = iir_cascade_init(&DAT_00253e10,4,&DAT_00236a30,1);
  DAT_00253e08 = fir_init(&DAT_00253eb0,0x6d,FLOAT_ARRAY_002051c0);
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar3 = uVar2 & 0xf;
  if (uVar3 < 2) {
    uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 2);
    in_st_PSWOE = (undefined1)uVar1;
    in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
  }
  if (DAT_00253e02 != 0) {
    DAT_20070002 = DAT_20070002 | 0x80;
    uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    wsr_ps(uVar3 | uVar2 & 0xfffffff0);
    rsync();
    return;
  }
  DAT_20070002 = DAT_20070002 & 0xff7f;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar3 | uVar2 & 0xfffffff0);
  rsync();
  return;
}


// ===== dcs_config @ 0021fdbc (1121 bytes)

/* reg 0x51 */

void dcs_config(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  
  uVar4 = (uint)DAT_200700a2;
  uVar11 = (uint)(DAT_200700a2 >> 0xc);
  if (DAT_00253c80 != uVar4) {
    ae_s16i_n(uVar4,&DAT_00253c80,0);
    if (uVar11 == 1) {
      uVar4 = uVar4 & 0xfff;
      uVar9 = uVar4 >> 7;
      uVar11 = uVar4 >> 6;
      uVar12 = uVar4 >> 3;
      uVar5 = uVar4 >> 2;
      uVar13 = uVar4 >> 4;
      uVar6 = uVar4 >> 1;
      uVar14 = uVar4 >> 5;
      uVar15 = uVar4 >> 8;
      uVar16 = uVar15 ^ uVar9;
      uVar7 = uVar6 ^ uVar4;
      uVar8 = uVar12 ^ uVar7 ^ uVar5;
      DAT_00253c84 = uVar4 | ((uVar9 ^ uVar8 ^ uVar13) & 1 |
                             ((uVar15 ^ uVar6 ^ uVar5 ^ uVar12 ^ uVar13 ^ uVar14 ^ 0xffffffff) & 1 |
                             ((uVar7 ^ uVar14 ^ uVar9 ^ uVar11) & 1 |
                             ((uVar15 ^ uVar9 ^ uVar6 ^ uVar5 ^ uVar11 ^ 0xffffffff) & 1 |
                             ((uVar15 ^ uVar7 ^ uVar13 ^ 0xffffffff) & 1 |
                             ((uVar9 ^ uVar13 ^ uVar14 ^ uVar12 ^ uVar4 ^ 0xffffffff) & 1 |
                             ((uVar16 ^ uVar11 ^ uVar14 ^ uVar12 ^ uVar5 ^ uVar4) & 1 |
                             ((uVar16 ^ uVar13 ^ uVar11 ^ uVar6 ^ uVar12) & 1 |
                             ((uVar16 ^ uVar14 ^ uVar13 ^ uVar5) & 1 |
                             ((uVar15 ^ uVar11 ^ uVar14 ^ uVar12 ^ 0xffffffff) & 1 |
                             ((uVar8 ^ uVar11 ^ 0xffffffff) & 1) << 1) << 1) << 1) << 1) << 1) << 1)
                             << 1) << 1) << 1) << 1) << 0xc | 0x800;
      DAT_00253c88 = DAT_00253c84;
      DAT_00253c8c = DAT_00253c84;
    }
    else {
      if (uVar11 == 2) {
        uVar4 = uVar4 & 0xfff;
        uVar12 = uVar4 >> 7;
        uVar5 = uVar4 >> 6;
        uVar13 = uVar4 >> 3;
        uVar6 = uVar4 >> 2;
        uVar14 = uVar4 >> 4;
        uVar7 = uVar4 >> 1;
        uVar15 = uVar4 >> 5;
        uVar16 = uVar4 >> 8;
        uVar17 = uVar16 ^ uVar12;
        uVar8 = uVar7 ^ uVar4;
        uVar9 = uVar13 ^ uVar8 ^ uVar6;
        uVar4 = uVar4 | ((uVar12 ^ uVar9 ^ uVar14) & 1 |
                        ((uVar16 ^ uVar7 ^ uVar6 ^ uVar13 ^ uVar14 ^ uVar15 ^ 0xffffffff) & 1 |
                        ((uVar8 ^ uVar15 ^ uVar12 ^ uVar5) & 1 |
                        ((uVar16 ^ uVar12 ^ uVar7 ^ uVar6 ^ uVar5 ^ 0xffffffff) & 1 |
                        ((uVar16 ^ uVar8 ^ uVar14 ^ 0xffffffff) & 1 |
                        ((uVar12 ^ uVar14 ^ uVar15 ^ uVar13 ^ uVar4 ^ 0xffffffff) & 1 |
                        ((uVar17 ^ uVar5 ^ uVar15 ^ uVar13 ^ uVar6 ^ uVar4) & 1 |
                        ((uVar17 ^ uVar14 ^ uVar5 ^ uVar7 ^ uVar13) & 1 |
                        ((uVar17 ^ uVar15 ^ uVar14 ^ uVar6) & 1 |
                        ((uVar16 ^ uVar5 ^ uVar15 ^ uVar13 ^ 0xffffffff) & 1 |
                        ((uVar9 ^ uVar5 ^ 0xffffffff) & 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1)
                        << 1) << 1) << 1) << 0xc;
      }
      else {
        if (uVar11 != 3) {
          ae_s16i_n(0,&DAT_00253c80,2);
          goto LAB_0021fdee;
        }
        uVar4 = uVar4 & 0xfff;
        uVar12 = uVar4 >> 7;
        uVar5 = uVar4 >> 6;
        uVar13 = uVar4 >> 3;
        uVar6 = uVar4 >> 2;
        uVar14 = uVar4 >> 4;
        uVar7 = uVar4 >> 1;
        uVar15 = uVar4 >> 5;
        uVar16 = uVar4 >> 8;
        uVar17 = uVar16 ^ uVar12;
        uVar8 = uVar7 ^ uVar4;
        uVar9 = uVar13 ^ uVar8 ^ uVar6;
        uVar4 = uVar4 | ((uVar12 ^ uVar9 ^ uVar14) & 1 |
                        ((uVar16 ^ uVar7 ^ uVar6 ^ uVar13 ^ uVar14 ^ uVar15 ^ 0xffffffff) & 1 |
                        ((uVar8 ^ uVar15 ^ uVar12 ^ uVar5) & 1 |
                        ((uVar16 ^ uVar12 ^ uVar7 ^ uVar6 ^ uVar5 ^ 0xffffffff) & 1 |
                        ((uVar16 ^ uVar8 ^ uVar14 ^ 0xffffffff) & 1 |
                        ((uVar12 ^ uVar14 ^ uVar15 ^ uVar13 ^ uVar4 ^ 0xffffffff) & 1 |
                        ((uVar17 ^ uVar5 ^ uVar15 ^ uVar13 ^ uVar6 ^ uVar4) & 1 |
                        ((uVar17 ^ uVar14 ^ uVar5 ^ uVar7 ^ uVar13) & 1 |
                        ((uVar17 ^ uVar15 ^ uVar14 ^ uVar6) & 1 |
                        ((uVar16 ^ uVar5 ^ uVar15 ^ uVar13 ^ 0xffffffff) & 1 |
                        ((uVar9 ^ uVar5 ^ 0xffffffff) & 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1)
                        << 1) << 1) << 1) << 0xc;
      }
      DAT_00253c84 = uVar4 | 0x800;
      ae_s16i_n(uVar11,&DAT_00253c80,2);
      if (uVar11 == 2) {
        DAT_00253c88 = DAT_00253c84 ^ 0x7fffff;
        DAT_00253c8c = DAT_00253c88;
      }
      else if (uVar11 == 3) {
        DAT_00253c8c = DAT_00253c84 ^ 0x7fffff;
        DAT_00253c88 = DAT_00253c84;
      }
    }
    DAT_00253c82 = DAT_200700a2 >> 0xc;
    DAT_00253e04 = iir_cascade_init(&DAT_00253e10,4,&DAT_00236a30,1);
  }
LAB_0021fdee:
  iVar3 = ae_l16ui_n(&DAT_00253c80,2);
  if (iVar3 != 0) {
    iir_cascade_process(DAT_00253e04,&DAT_00254250,param_1,0x30);
    fir_process(DAT_00253e08,&DAT_00254310,&DAT_00254250,0x30);
    puVar2 = &DAT_00254310;
    uVar4 = (uint)DAT_00253c90;
    do {
      uVar10 = ae_l32_i(*puVar2);
      uVar1 = ae_s32_l_i(uVar10);
      (&DAT_002543d0)[uVar4] = uVar1;
      uVar4 = ae_zext16(uVar4 + 1);
      DAT_00253c90 = (ushort)uVar4;
      if (0x857 < uVar4) {
        dcs_detect(&DAT_002543d0);
        uVar4 = 0;
        DAT_00253c90 = 0;
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != &DAT_002543d0);
  }
  return;
}


// ===== dcs_detect @ 00220224 (495 bytes)

/* Golay 23-bit match, reg 1 bit 7 */

void dcs_detect(undefined4 *param_1)

{
  float fVar1;
  undefined6 uVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined2 *puVar10;
  undefined2 uVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined4 uStack_2c;
  
  uVar14 = ae_l32_ip(*param_1);
  uVar15 = const_s(0);
  uVar12 = ae_l32_ip(param_1[1]);
  uVar13 = (ulonglong)
           (uint)(((float)uVar15 + (float)uVar14 * (float)uVar14 + (float)uVar12 * (float)uVar12) *
                 0.0004681648);
  uVar6 = ae_s32_l_i(uVar13);
  sqrtf_();
  uVar11 = oeq_s(uVar13,uVar13);
  uStack_2c = ae_s32_l_i(uVar13);
  if (!SUB21(uVar11,0)) {
    uVar12 = ae_l32_i(uVar6);
    FUN_00229a20();
    uStack_2c = ae_s32_l_i(uVar12);
  }
  uVar12 = ae_l32_i(uStack_2c);
  DAT_00253c94 = ae_s32_l_i(uVar12);
  memset(&DAT_00253c98,0,0x164);
  puVar10 = &DAT_00236a80;
  puVar4 = param_1;
  do {
    uVar12 = ae_l32_ip(*puVar4);
    uVar14 = ae_l32_i(DAT_00253c98);
    DAT_00253c98 = ae_s32_l_ip((ulonglong)(uint)((float)uVar14 + ABS((float)uVar12)));
    iVar5 = ae_l16ui_n(puVar10,0);
    puVar10 = puVar10 + 1;
    puVar4 = param_1 + iVar5;
  } while (puVar10 != (undefined2 *)0x236aae);
  uVar12 = ae_l32_i(DAT_00253c98);
  uVar14 = ae_l32_i(DAT_00253c9c);
  uVar11 = olt_s(uVar12,uVar14);
  if (SUB21(uVar11,0)) {
    ae_mov(uVar14);
  }
  iVar5 = 0;
  DAT_00253dfc = 0;
  bVar3 = true;
  DAT_00253e00 = 1;
  uVar12 = ae_l32_i(uStack_2c);
  fVar1 = (float)uVar12 * 0.7;
  uVar12 = ae_l32_i(param_1[SUB21(uVar11,0)]);
  uVar11 = olt_s((ulonglong)(uint)fVar1,uVar12);
  if (SUB21(uVar11,0)) {
    DAT_00253dfc = 1;
    iVar5 = 1;
    bVar3 = true;
  }
  else {
    uVar11 = olt_s(uVar12,(ulonglong)(uint)-fVar1);
    if (!SUB21(uVar11,0)) {
      bVar3 = false;
      DAT_00253e00 = 0;
    }
  }
  if (bVar3) {
    if ((iVar5 == DAT_00253c88) || (iVar5 == DAT_00253c8c)) {
      uVar6 = 1;
    }
    else {
      uVar6 = 0;
    }
    uVar7 = ae_zext16(uVar6);
    if (DAT_00253e02 == uVar7) {
      return;
    }
  }
  else {
    if (DAT_00253e02 == 0) {
      return;
    }
    uVar7 = 0;
  }
  DAT_00253e02 = (short)uVar7;
  uVar8 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar9 = uVar8 & 0xf;
  if (uVar9 < 2) {
    uVar2 = wsr_ps(uVar8 & 0xfffffff0 | 2);
    in_st_PSWOE = (undefined1)uVar2;
    in_st_PSCALLINC = (undefined1)((uint6)uVar2 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar2 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar2 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar2 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar2 >> 0x28);
    rsync();
  }
  if ((short)uVar7 != 0) {
    DAT_20070002 = DAT_20070002 | 0x80;
    uVar7 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    wsr_ps(uVar9 | uVar7 & 0xfffffff0);
    rsync();
    return;
  }
  DAT_20070002 = DAT_20070002 & 0xff7f;
  uVar7 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar9 | uVar7 & 0xfffffff0);
  rsync();
  return;
}


// ===== FUN_00220420 @ 00220420 (78 bytes)

void FUN_00220420(void)

{
  memset(&DAT_00256530,0,0x20);
  memset(&DAT_00256550,0,0x20);
  memset(&DAT_00256570,0,0x20);
  DAT_00256544 = &DAT_00256590;
  DAT_00256584 = &DAT_00256610;
  DAT_00256548 = &DAT_00256650;
  DAT_00256568 = &DAT_00256670;
  DAT_00256564 = &DAT_002565d0;
  DAT_00256588 = &DAT_00256690;
  return;
}


// ===== rx_eq_update @ 00220470 (792 bytes)

void rx_eq_update(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined2 uVar9;
  float fVar10;
  undefined8 in_aed0;
  ulonglong uVar11;
  undefined8 uVar12;
  float fVar13;
  uint uVar14;
  undefined *puVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  
  FUN_00220790(&DAT_00256530,0x48);
  FUN_00220790(&DAT_00256550,0x4b);
  if ((uint)DAT_00256570 == (uint)DAT_2007009c) {
    iVar7 = (int)DAT_2007009e;
    if (DAT_00256572 != iVar7) goto LAB_002204e0;
    uVar14 = (uint)DAT_200700a0;
    if (DAT_00256574 == uVar14) {
      return;
    }
  }
  else {
    DAT_00256570 = DAT_2007009c;
    DAT_00256576 = DAT_2007009c >> 0xc & 1;
    puVar15 = (undefined *)(DAT_2007009c & 0xfff);
    if ((&DAT_0000176f < puVar15) || ((DAT_2007009c & 0xfff) != 0)) {
      iVar7 = (uint)(puVar15 < &DAT_0000176f) * (int)puVar15 +
              (uint)(puVar15 >= &DAT_0000176f) * (int)&DAT_0000176f;
    }
    else {
      iVar7 = 1;
    }
    uVar8 = ae_zext16(iVar7);
    i2f_scaled(uVar8,0);
    iVar7 = (int)DAT_2007009e;
    DAT_00256578 = ae_s32_l_i(in_aed0);
    if (DAT_00256572 == iVar7) {
      uVar14 = (uint)DAT_200700a0;
      if (DAT_00256574 == uVar14) goto LAB_0022054b;
    }
    else {
LAB_002204e0:
      DAT_00256572 = (short)iVar7;
      if ((iVar7 < 0x15) && ((iVar7 + 0x28U & 0x80000000) != 0)) {
        iVar7 = -0x28;
      }
      else {
        iVar7 = (uint)(iVar7 < 0x14) * iVar7 + (uint)(iVar7 >= 0x14) * 0x14;
      }
      uVar8 = ae_sext16(iVar7);
      i2f_scaled(uVar8,0);
      uVar14 = (uint)DAT_200700a0;
      DAT_0025657c = ae_s32_l_i(in_aed0);
      if (DAT_00256574 == uVar14) {
        in_aed0 = ae_l32_i(DAT_00256578);
        goto LAB_0022054b;
      }
    }
  }
  DAT_00256574 = (ushort)uVar14;
  if (uVar14 == 0) {
    uVar12 = ae_l32_i(0x3f000000);
    DAT_00256580 = ae_s32_l_i(uVar12);
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
    DAT_00256580 = ae_s32_l_i(in_aed0);
  }
  in_aed0 = ae_l32_i(DAT_00256578);
LAB_0022054b:
  uVar11 = (ulonglong)(uint)((float)in_aed0 * 3.1415927 * 8.333333e-05);
  tanf_();
  uVar12 = ae_l32_i(DAT_0025657c);
  uVar8 = ae_s32_l_i(uVar11);
  uVar11 = (ulonglong)(uint)((float)uVar12 * 0.05);
  pow10f_();
  uVar12 = ae_l32_i(DAT_00256580);
  uVar17 = const_s(0);
  uVar9 = oeq_s(uVar12,uVar17);
  uVar4 = ae_s32_l_i(uVar11);
  if (SUB21(uVar9,0)) {
    uVar12 = const_s(3);
    DAT_00256580 = ae_s32_l_i(uVar12);
    ae_l32_i(0x3f000000);
  }
  uVar12 = const_s(1);
  divf_();
  uVar1 = ae_s32_l_i(uVar12);
  ae_l32_i(uVar4);
  uVar12 = ae_l32_i(0x3f800000);
  divf_();
  uVar17 = ae_l32_i(uVar4);
  uVar16 = ae_l32_i(0x3f800000);
  uVar9 = olt_s(uVar17,uVar16);
  iVar7 = ae_l16si_n(&DAT_00256570,2);
  uVar12 = movt_s(uVar17,uVar12,(char)uVar9);
  if (iVar7 < 1) {
    if (iVar7 < 0) {
      uVar16 = ae_l32_i(uVar1);
      uVar17 = ae_l32_i(uVar8);
      fVar13 = (float)uVar17;
      fVar3 = fVar13 * (float)uVar12 * (float)uVar16;
      uVar12 = ae_l32_i(0x3f800000);
      fVar10 = fVar13 * fVar13;
      fVar13 = (float)uVar16 * fVar13;
      uVar4 = ae_s32_l_i((ulonglong)(uint)fVar13);
      uVar1 = ae_s32_l_i((ulonglong)(uint)fVar10);
      uVar5 = ae_s32_l_i((ulonglong)(uint)fVar3);
      uVar2 = ae_s32_l_i((ulonglong)(uint)(fVar3 + (float)uVar12 + fVar10));
      uVar11 = (ulonglong)(uint)(fVar13 + (float)uVar12 + fVar10);
      divf_();
      uVar17 = ae_l32_i(uVar1);
      uVar16 = ae_l32_i(0xbf800000);
      uVar12 = ae_l32_i(&DAT_40000000);
      uVar8 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar2);
      uVar11 = (ulonglong)(uint)(((float)uVar17 + (float)uVar16) * (float)uVar12);
      divf_();
      uVar17 = ae_l32_i(uVar4);
      uVar16 = ae_l32_i(0x3f800000);
      uVar12 = ae_l32_i(uVar1);
      uVar4 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar2);
      uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar16 - (float)uVar17));
      divf_();
      uVar12 = ae_l32_i(uVar5);
      uVar17 = ae_l32_i(0x3f800000);
      uVar16 = ae_l32_i(uVar1);
      uVar1 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar2);
      uVar11 = (ulonglong)(uint)((float)uVar16 + ((float)uVar17 - (float)uVar12));
      divf_();
      uVar17 = ae_l32_i(uVar4);
      uVar16 = ae_l32_i(uVar8);
      uVar12 = ae_l32_i(uVar1);
    }
    else {
      uVar11 = ae_l32_i(0);
      uVar16 = ae_mov(uVar12);
      uVar12 = ae_mov(uVar11);
      uVar17 = ae_mov(uVar11);
    }
  }
  else {
    uVar17 = ae_l32_i(uVar8);
    uVar16 = ae_l32_i(uVar1);
    fVar10 = (float)uVar17;
    fVar13 = (float)uVar16 * fVar10;
    uVar17 = ae_l32_i(0x3f800000);
    fVar3 = fVar10 * fVar10;
    fVar10 = fVar10 * (float)uVar12 * (float)uVar16;
    uVar1 = ae_s32_l_i((ulonglong)(uint)fVar13);
    uVar5 = ae_s32_l_i((ulonglong)(uint)fVar3);
    uVar4 = ae_s32_l_i((ulonglong)(uint)fVar10);
    uVar2 = ae_s32_l_i((ulonglong)(uint)(fVar13 + (float)uVar17 + fVar3));
    uVar11 = (ulonglong)(uint)(fVar10 + (float)uVar17 + fVar3);
    divf_();
    uVar17 = ae_l32_i(uVar5);
    uVar16 = ae_l32_i(0xbf800000);
    uVar12 = ae_l32_i(&DAT_40000000);
    uVar8 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar2);
    uVar11 = (ulonglong)(uint)(((float)uVar17 + (float)uVar16) * (float)uVar12);
    divf_();
    uVar17 = ae_l32_i(uVar4);
    uVar16 = ae_l32_i(0x3f800000);
    uVar12 = ae_l32_i(uVar5);
    uVar4 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar2);
    uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar16 - (float)uVar17));
    divf_();
    uVar12 = ae_l32_i(uVar1);
    uVar17 = ae_l32_i(0x3f800000);
    uVar16 = ae_l32_i(uVar5);
    uVar1 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar2);
    uVar11 = (ulonglong)(uint)((float)uVar16 + ((float)uVar17 - (float)uVar12));
    divf_();
    uVar17 = ae_l32_i(uVar4);
    uVar16 = ae_l32_i(uVar8);
    uVar12 = ae_l32_i(uVar1);
  }
  puVar6 = DAT_00256588;
  uVar8 = ae_s32_l_i(uVar16);
  *DAT_00256588 = uVar8;
  uVar8 = ae_s32_l_i(uVar12);
  puVar6[2] = uVar8;
  uVar8 = ae_s32_l_i(uVar17);
  puVar6[1] = uVar8;
  uVar4 = DAT_00256584;
  uVar8 = ae_s32_l_i(uVar17);
  puVar6[3] = uVar8;
  uVar8 = ae_s32_l_i(uVar11);
  puVar6[4] = uVar8;
  DAT_0025658c = iir_cascade_init(uVar4,1,puVar6,0);
  return;
}


// ===== FUN_00220790 @ 00220790 (783 bytes)

void FUN_00220790(ushort *param_1,int param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined2 uVar9;
  float fVar10;
  undefined8 in_aed0;
  ulonglong uVar11;
  undefined8 uVar12;
  float fVar13;
  undefined *puVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  
  uVar2 = *(ushort *)(&DAT_20070000 + param_2 * 2);
  iVar15 = (param_2 + 1) * 2;
  if ((uint)*param_1 == (uint)uVar2) {
    iVar15 = (int)*(short *)(&DAT_20070000 + iVar15);
    if ((short)param_1[1] != iVar15) goto LAB_002207e9;
    uVar16 = (uint)*(ushort *)(&DAT_20070000 + (param_2 + 2) * 2);
    if (param_1[2] == uVar16) {
      return;
    }
  }
  else {
    param_1[3] = uVar2 >> 0xc & 1;
    *param_1 = uVar2;
    puVar14 = (undefined *)(uVar2 & 0xfff);
    if ((&DAT_0000176f < puVar14) || ((uVar2 & 0xfff) != 0)) {
      iVar6 = (uint)(puVar14 < &DAT_0000176f) * (int)puVar14 +
              (uint)(puVar14 >= &DAT_0000176f) * (int)&DAT_0000176f;
    }
    else {
      iVar6 = 1;
    }
    uVar7 = ae_zext16(iVar6);
    i2f_scaled(uVar7,0);
    iVar15 = (int)*(short *)(&DAT_20070000 + iVar15);
    uVar7 = ae_s32_l_i(in_aed0);
    *(undefined4 *)(param_1 + 4) = uVar7;
    if ((short)param_1[1] == iVar15) {
      uVar16 = (uint)*(ushort *)(&DAT_20070000 + (param_2 + 2) * 2);
      if (param_1[2] == uVar16) goto LAB_00220860;
    }
    else {
LAB_002207e9:
      param_1[1] = (ushort)iVar15;
      if ((iVar15 < 0x15) && ((iVar15 + 0x28U & 0x80000000) != 0)) {
        iVar15 = -0x28;
      }
      else {
        iVar15 = (uint)(iVar15 < 0x14) * iVar15 + (uint)(iVar15 >= 0x14) * 0x14;
      }
      uVar7 = ae_sext16(iVar15);
      i2f_scaled(uVar7,0);
      uVar16 = (uint)*(ushort *)(&DAT_20070000 + (param_2 + 2) * 2);
      uVar7 = ae_s32_l_i(in_aed0);
      *(undefined4 *)(param_1 + 6) = uVar7;
      if (param_1[2] == uVar16) {
        in_aed0 = ae_l32_i(*(undefined4 *)(param_1 + 4));
        goto LAB_00220860;
      }
    }
  }
  param_1[2] = (ushort)uVar16;
  if (uVar16 == 0) {
    uVar12 = ae_l32_i(0x3f000000);
    uVar7 = ae_s32_l_i(uVar12);
    *(undefined4 *)(param_1 + 8) = uVar7;
  }
  else {
    if ((uVar16 < 0xb) && ((uVar16 - 1 & 0x80000000) != 0)) {
      iVar15 = 1;
    }
    else {
      iVar15 = (uVar16 < 10) * uVar16 + (uint)(uVar16 >= 10) * 10;
    }
    uVar7 = ae_zext16(iVar15);
    i2f_scaled(uVar7,0);
    uVar7 = ae_s32_l_i(in_aed0);
    *(undefined4 *)(param_1 + 8) = uVar7;
  }
  in_aed0 = ae_l32_i(*(undefined4 *)(param_1 + 4));
LAB_00220860:
  uVar11 = (ulonglong)(uint)((float)in_aed0 * 3.1415927 * 8.333333e-05);
  tanf_();
  uVar12 = ae_l32_i(*(undefined4 *)(param_1 + 6));
  uVar7 = ae_s32_l_i(uVar11);
  uVar11 = (ulonglong)(uint)((float)uVar12 * 0.05);
  pow10f_();
  uVar12 = ae_l32_i(*(undefined4 *)(param_1 + 8));
  uVar19 = const_s(0);
  uVar9 = oeq_s(uVar12,uVar19);
  uVar17 = ae_s32_l_i(uVar11);
  if (SUB21(uVar9,0)) {
    uVar12 = const_s(3);
    uVar1 = ae_s32_l_i(uVar12);
    *(undefined4 *)(param_1 + 8) = uVar1;
    ae_l32_i(0x3f000000);
  }
  uVar12 = const_s(1);
  divf_();
  uVar1 = ae_s32_l_i(uVar12);
  ae_l32_i(uVar17);
  uVar12 = ae_l32_i(0x3f800000);
  divf_();
  uVar19 = ae_l32_i(uVar17);
  uVar18 = ae_l32_i(0x3f800000);
  uVar9 = olt_s(uVar19,uVar18);
  iVar15 = ae_l16si_n(param_1,2);
  uVar12 = movt_s(uVar19,uVar12,(char)uVar9);
  if (iVar15 < 1) {
    if (iVar15 < 0) {
      uVar18 = ae_l32_i(uVar1);
      uVar19 = ae_l32_i(uVar7);
      fVar13 = (float)uVar19;
      fVar4 = fVar13 * (float)uVar12 * (float)uVar18;
      uVar12 = ae_l32_i(0x3f800000);
      fVar10 = fVar13 * fVar13;
      fVar13 = (float)uVar18 * fVar13;
      uVar17 = ae_s32_l_i((ulonglong)(uint)fVar13);
      uVar1 = ae_s32_l_i((ulonglong)(uint)fVar10);
      uVar5 = ae_s32_l_i((ulonglong)(uint)fVar4);
      uVar3 = ae_s32_l_i((ulonglong)(uint)(fVar4 + (float)uVar12 + fVar10));
      uVar11 = (ulonglong)(uint)(fVar13 + (float)uVar12 + fVar10);
      divf_();
      uVar19 = ae_l32_i(uVar1);
      uVar18 = ae_l32_i(0xbf800000);
      uVar12 = ae_l32_i(&DAT_40000000);
      uVar7 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar3);
      uVar11 = (ulonglong)(uint)(((float)uVar19 + (float)uVar18) * (float)uVar12);
      divf_();
      uVar19 = ae_l32_i(uVar17);
      uVar18 = ae_l32_i(0x3f800000);
      uVar12 = ae_l32_i(uVar1);
      uVar17 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar3);
      uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar18 - (float)uVar19));
      divf_();
      uVar12 = ae_l32_i(uVar5);
      uVar19 = ae_l32_i(0x3f800000);
      uVar18 = ae_l32_i(uVar1);
      uVar1 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar3);
      uVar11 = (ulonglong)(uint)((float)uVar18 + ((float)uVar19 - (float)uVar12));
      divf_();
      uVar19 = ae_l32_i(uVar17);
      uVar18 = ae_l32_i(uVar7);
      uVar12 = ae_l32_i(uVar1);
    }
    else {
      uVar11 = ae_l32_i(0);
      uVar18 = ae_mov(uVar12);
      uVar12 = ae_mov(uVar11);
      uVar19 = ae_mov(uVar11);
    }
  }
  else {
    uVar19 = ae_l32_i(uVar7);
    uVar18 = ae_l32_i(uVar1);
    fVar10 = (float)uVar19;
    fVar13 = (float)uVar18 * fVar10;
    uVar19 = ae_l32_i(0x3f800000);
    fVar4 = fVar10 * fVar10;
    fVar10 = fVar10 * (float)uVar12 * (float)uVar18;
    uVar1 = ae_s32_l_i((ulonglong)(uint)fVar13);
    uVar5 = ae_s32_l_i((ulonglong)(uint)fVar4);
    uVar17 = ae_s32_l_i((ulonglong)(uint)fVar10);
    uVar3 = ae_s32_l_i((ulonglong)(uint)(fVar13 + (float)uVar19 + fVar4));
    uVar11 = (ulonglong)(uint)(fVar10 + (float)uVar19 + fVar4);
    divf_();
    uVar19 = ae_l32_i(uVar5);
    uVar18 = ae_l32_i(0xbf800000);
    uVar12 = ae_l32_i(&DAT_40000000);
    uVar7 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar3);
    uVar11 = (ulonglong)(uint)(((float)uVar19 + (float)uVar18) * (float)uVar12);
    divf_();
    uVar19 = ae_l32_i(uVar17);
    uVar18 = ae_l32_i(0x3f800000);
    uVar12 = ae_l32_i(uVar5);
    uVar17 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar3);
    uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar18 - (float)uVar19));
    divf_();
    uVar12 = ae_l32_i(uVar1);
    uVar19 = ae_l32_i(0x3f800000);
    uVar18 = ae_l32_i(uVar5);
    uVar1 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar3);
    uVar11 = (ulonglong)(uint)((float)uVar18 + ((float)uVar19 - (float)uVar12));
    divf_();
    uVar19 = ae_l32_i(uVar17);
    uVar18 = ae_l32_i(uVar7);
    uVar12 = ae_l32_i(uVar1);
  }
  puVar8 = *(undefined4 **)(param_1 + 0xc);
  uVar7 = ae_s32_l_i(uVar18);
  *puVar8 = uVar7;
  uVar7 = ae_s32_l_i(uVar12);
  puVar8[2] = uVar7;
  uVar7 = ae_s32_l_i(uVar19);
  puVar8[1] = uVar7;
  uVar17 = *(undefined4 *)(param_1 + 10);
  uVar7 = ae_s32_l_i(uVar19);
  puVar8[3] = uVar7;
  uVar7 = ae_s32_l_i(uVar11);
  puVar8[4] = uVar7;
  uVar7 = iir_cascade_init(uVar17,1,puVar8,0);
  *(undefined4 *)(param_1 + 0xe) = uVar7;
  return;
}


// ===== rx_eq_3band @ 00220aa4 (126 bytes)

/* regs 0x48-0x50 */

void rx_eq_3band(int param_1,int param_2)

{
  rx_eq_update();
  if (param_1 != param_2) {
    memcpy(param_2,param_1,0xc0);
  }
  if (DAT_00256536 != 0) {
    memcpy(&DAT_002566b0,param_2,0xc0);
    iir_cascade_process(DAT_0025654c,param_2,&DAT_002566b0,0x30);
  }
  if (DAT_00256556 != 0) {
    memcpy(&DAT_002566b0,param_2,0xc0);
    iir_cascade_process(DAT_0025656c,param_2,&DAT_002566b0,0x30);
  }
  if (DAT_00256576 != 0) {
    memcpy(&DAT_002566b0,param_2,0xc0);
    iir_cascade_process(DAT_0025658c,param_2,&DAT_002566b0,0x30);
  }
  return;
}


// ===== FUN_00220b30 @ 00220b30 (44 bytes)

void FUN_00220b30(void)

{
  ctcss_init();
  dcs_init();
  DAT_00256770 = iir_cascade_init(&DAT_00256840,5,&DAT_00236ab0,1);
  DAT_00256776 = 0;
  DAT_00256774 = 0xffff;
  return;
}


// ===== fm_audio_post @ 00220b5c (106 bytes)

/* CTCSS, DCS, subtone HPF, de-emphasis (reg 0x3A) */

void fm_audio_post(undefined4 param_1,undefined4 param_2)

{
  ctcss_detect(param_1);
  dcs_config(param_1);
  iir_cascade_process(DAT_00256770,&DAT_00256780,param_1,0x30);
  if (DAT_00256774 != DAT_20070074) {
    DAT_00256774 = DAT_20070074;
    DAT_00256776 = DAT_20070074 & 1;
    DAT_00256778 = iir_cascade_init(&DAT_00256900,8,&DAT_00236b20,3);
  }
  if (DAT_00256776 != 0) {
    iir_cascade_process(DAT_00256778,param_2,&DAT_00256780,0x30);
    return;
  }
  memcpy(param_2,&DAT_00256780,0xc0);
  return;
}


// ===== create_Thread_Rx_Audio @ 00220bd0 (152 bytes)

void create_Thread_Rx_Audio(void)

{
  undefined6 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar2 & 0xf) < 2) {
    uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 2);
    in_st_PSWOE = (undefined1)uVar1;
    in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
  }
  DAT_00257320 = 0;
  DAT_00257322 = 0;
  DAT_00257321 = 0;
  DAT_002580f0 = 0;
  DAT_002580f2 = 0;
  DAT_002580f1 = 0;
  DAT_002589f8 = 0;
  DAT_002589fa = 0;
  DAT_002589f9 = 0;
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar2 & 0xf | uVar3 & 0xfffffff0);
  rsync();
  xos_thread_create(0x257328,0,Thread_Rx_Audio_entry,0,"Thread_Rx_Audio",&DAT_00258a00,&DAT_00001398
                    ,6,0,0);
  xos_msgq_create(PTR_DAT_00236bc0,2,4,0);
  if_agc_init();
  FUN_00220c68();
  return;
}


// ===== FUN_00220c68 @ 00220c68 (17 bytes)

void FUN_00220c68(void)

{
  DAT_002577e0 = 0xffff;
  FUN_0021f410();
  return;
}


// ===== rx_audio_fifo_push @ 00220c7c (151 bytes)

undefined4 rx_audio_fifo_push(undefined4 param_1)

{
  undefined6 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  bool bVar4;
  undefined4 auStack_30 [12];
  
  if (DAT_00257320 == '\x18') {
    return 0;
  }
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar3 & 0xf) < 2) {
    uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
    in_st_PSWOE = (undefined1)uVar1;
    in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
  }
  memcpy(&DAT_00256a20 + (uint)DAT_00257321 * 0x60,param_1,0x60);
  bVar4 = 0x16 < DAT_00257321;
  DAT_00257321 = DAT_00257321 + 1;
  if (bVar4) {
    DAT_00257321 = '\0';
  }
  DAT_00257320 = DAT_00257320 + 1;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar3 & 0xf | uVar2 & 0xfffffff0);
  rsync();
  if (0xb < DAT_00257320) {
    auStack_30[0] = 0;
    xos_msgq_put(PTR_DAT_00236bc0,auStack_30);
    return 1;
  }
  return 1;
}


// ===== FUN_00220d14 @ 00220d14 (142 bytes)

undefined4 FUN_00220d14(int param_1)

{
  undefined6 uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  if (0xb < DAT_00257320) {
    uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    if ((uVar4 & 0xf) < 2) {
      uVar1 = wsr_ps(uVar4 & 0xfffffff0 | 2);
      in_st_PSWOE = (undefined1)uVar1;
      in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
      in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
      in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
      in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
      in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
      rsync();
    }
    iVar3 = 0;
    do {
      memcpy(param_1,&DAT_00256a20 + (uint)DAT_00257322 * 0x60,0x60);
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 0x60;
      DAT_00257320 = DAT_00257320 - 1;
      bVar2 = 0;
      if (DAT_00257322 < 0x17) {
        bVar2 = DAT_00257322 + 1;
      }
      DAT_00257322 = bVar2;
    } while (iVar3 != 0xc);
    uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    wsr_ps(uVar4 & 0xf | uVar5 & 0xfffffff0);
    rsync();
    return 1;
  }
  memset(param_1,0,0x480);
  return 0;
}


// ===== FUN_00220da4 @ 00220da4 (140 bytes)

undefined4 FUN_00220da4(int param_1,int param_2)

{
  undefined6 uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  param_1 = param_1 * (int)&DAT_00000908;
  if ((byte)(&DAT_002580f0)[param_1] < 0xd) {
    uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    if ((uVar4 & 0xf) < 2) {
      uVar1 = wsr_ps(uVar4 & 0xfffffff0 | 2);
      in_st_PSWOE = (undefined1)uVar1;
      in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
      in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
      in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
      in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
      in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
      rsync();
    }
    iVar2 = 0;
    do {
      memcpy(&DAT_002577f0 + (uint)(byte)(&DAT_002580f1)[param_1] * 0x60 + param_1,param_2,0x60);
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 0x60;
      cVar3 = '\0';
      if ((byte)(&DAT_002580f1)[param_1] < 0x17) {
        cVar3 = (&DAT_002580f1)[param_1] + 1;
      }
      (&DAT_002580f1)[param_1] = cVar3;
      (&DAT_002580f0)[param_1] = (&DAT_002580f0)[param_1] + '\x01';
    } while (iVar2 != 0xc);
    uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    wsr_ps(uVar4 & 0xf | uVar5 & 0xfffffff0);
    rsync();
    return 1;
  }
  return 0;
}


// ===== FUN_00220e34 @ 00220e34 (168 bytes)

undefined4 FUN_00220e34(int param_1,undefined4 param_2)

{
  undefined6 uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar3;
  
  param_1 = param_1 * (int)&DAT_00000908;
  if ((&DAT_002580f0)[param_1] == '\0') {
    memset(param_2,0,0x60);
    return 0;
  }
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar3 = uVar2 & 0xf;
  if (uVar3 < 2) {
    uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 2);
    in_st_PSWOE = (undefined1)uVar1;
    in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
  }
  memcpy(param_2,&DAT_002577f0 + (uint)(byte)(&DAT_002580f2)[param_1] * 0x60 + param_1,0x60);
  if ((byte)(&DAT_002580f2)[param_1] < 0x17) {
    (&DAT_002580f0)[param_1] = (&DAT_002580f0)[param_1] + -1;
    (&DAT_002580f2)[param_1] = (&DAT_002580f2)[param_1] + 1;
    uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    wsr_ps(uVar3 | uVar2 & 0xfffffff0);
    rsync();
    return 1;
  }
  (&DAT_002580f2)[param_1] = 0;
  (&DAT_002580f0)[param_1] = (&DAT_002580f0)[param_1] + -1;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar3 | uVar2 & 0xfffffff0);
  rsync();
  return 1;
}


// ===== rx_demod_dispatch @ 00220ee0 (146 bytes)

/* reg 6: 0/2/4/6 Weaver(0), 1/3/5/7 Weaver(1), 8 AM, 9 FM (docs/code/ifdsp/dsp-chains.md) */

void rx_demod_dispatch(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  memcpy(&DAT_00259da0,param_1,0x60);
  uVar1 = DAT_2007000c;
  DAT_002577e0 = DAT_2007000c;
  if_agc_process(&DAT_00259da0);
  switch(uVar1) {
  case 0:
  case 2:
  case 4:
  case 6:
    ssb_weaver_init(0);
    ssb_weaver_demod(&DAT_00259da0,&DAT_00259da0);
    break;
  case 1:
  case 3:
  case 5:
  case 7:
    ssb_weaver_init(1);
    ssb_weaver_demod(&DAT_00259da0,&DAT_00259da0);
    break;
  case 8:
    am_demod_init();
    am_demod(&DAT_00259da0,&DAT_00259da0);
    break;
  case 9:
    fm_demod_init();
    fm_demod(&DAT_00259da0,&DAT_00259da0);
  }
  memcpy(param_2,&DAT_00259da0,0x60);
  return;
}


// ===== rx_audio_push_block @ 00220f74 (28 bytes)

void rx_audio_push_block(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  rx_audio_fifo_push(param_1);
  FUN_00220e34(0,param_2);
  FUN_00220e34(1,param_3);
  return;
}


// ===== Thread_Rx_Audio_entry @ 00220f90 (64 bytes)

void Thread_Rx_Audio_entry(void)

{
  int iVar1;
  undefined1 auStack_30 [48];
  
  do {
    do {
      iVar1 = xos_msgq_get(PTR_DAT_00236bc0,auStack_30);
    } while (iVar1 != 0);
    FUN_00220d14(&DAT_00259e00);
    rx_audio_chain(&DAT_00259e00,&DAT_0025a280,&DAT_0025a700);
    FUN_00220da4(0,&DAT_0025a280);
    FUN_00220da4(1,&DAT_0025a700);
  } while( true );
}


// ===== fc1_spi_dma_init @ 00220fd0 (210 bytes)

void fc1_spi_dma_init(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [4];
  undefined4 uStack_4c;
  undefined *puStack_40;
  undefined4 uStack_38;
  
  DAT_0025abb0 = 0;
  INPUTMUX_AttachSignal(&DAT_40026000,0x11,0x14000013);
  xos_register_interrupt_handler(0x16,DMA_IRQHandle,&DAT_40104000);
  xos_interrupt_enable(0x16);
  CLOCK_AttachClk(0x80002528);
  uVar2 = CLOCK_GetFlexCommClkFreq(1);
  SPI_MasterGetDefaultConfig(auStack_50);
  uStack_38 = 0;
  puStack_40 = &DAT_000f4240;
  uStack_4c = 1;
  SPI_MasterInit(&DAT_40107000,auStack_50,uVar2);
  DMA_Init(&DAT_40104000);
  memw();
  uVar1 = DAT_40104020;
  memw();
  DAT_40104020 = uVar1 | 8;
  memw();
  uVar1 = DAT_40104020;
  memw();
  DAT_40104020 = uVar1 | 4;
  memw();
  uVar1 = DAT_40104430;
  memw();
  DAT_40104430 = uVar1 & 0xfff8ffff | (uint)&DAT_00030000;
  memw();
  uVar1 = DAT_40104420;
  memw();
  DAT_40104420 = uVar1 & 0xfff8ffff | (uint)&DAT_00020000;
  DMA_CreateHandle(&DAT_0025abb4,&DAT_40104000,3);
  DMA_CreateHandle(&DAT_0025abc4,&DAT_40104000,2);
  return;
}


// ===== FUN_002210a4 @ 002210a4 (55 bytes)

void FUN_002210a4(void)

{
  DAT_0025abb0 = 0;
  memset(&DAT_200607e0,0,&DAT_000011f8);
  memset(&DAT_200619e0,0,&DAT_000011f8);
  FUN_00214c30(&DAT_40107000,&DAT_0025abd4,FUN_0022118c,0,&DAT_0025abb4,&DAT_0025abc4);
  return;
}


// ===== FUN_002210dc @ 002210dc (62 bytes)

void FUN_002210dc(void)

{
  int iVar1;
  undefined *puStack_30;
  undefined *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = 0;
  uStack_24 = 600;
  puStack_30 = &DAT_200607e0;
  DAT_0025abb0 = 0;
  puStack_2c = &DAT_200619e0;
  iVar1 = FUN_00214c8c(&DAT_40107000,&DAT_0025abd4,&puStack_30);
  if (iVar1 != 0) {
    DAT_0025abb0 = 1;
    return;
  }
  DAT_0025abb0 = 1;
  return;
}


// ===== FUN_0022111c @ 0022111c (109 bytes)

void FUN_0022111c(void)

{
  undefined *local_30;
  undefined *puStack_2c;
  undefined *puStack_28;
  undefined4 uStack_24;
  
  if (DAT_0025abb0 != 0) {
    uStack_24 = *(undefined4 *)(&DAT_00204d30 + DAT_0025abb0 * 4);
    puStack_2c = &DAT_200619e0 + *(int *)(&DAT_00204d10 + DAT_0025abb0 * 4);
    local_30 = &DAT_200607e0 + *(int *)(&DAT_00204d10 + DAT_0025abb0 * 4);
    puStack_28 = (undefined *)0x0;
    if (3 < DAT_0025abb0) {
      puStack_28 = &DAT_00100000;
    }
    FUN_00214c8c(&DAT_40107000,&DAT_0025abd4,&local_30);
    if (DAT_0025abb0 < 4) {
      DAT_0025abb0 = DAT_0025abb0 + 1;
      return;
    }
    DAT_0025abb0 = 0;
    spi_post_tx_done();
  }
  return;
}


// ===== FUN_0022118c @ 0022118c (12 bytes)

void FUN_0022118c(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    return;
  }
  FUN_0022111c();
  return;
}


// ===== FUN_00221198 @ 00221198 (29 bytes)

void FUN_00221198(int param_1,undefined4 param_2,int param_3)

{
  if (&DAT_000011f8 < (undefined *)(param_1 + param_3)) {
    return;
  }
  memcpy(&DAT_200607e0 + param_1,param_2,param_3);
  return;
}


// ===== FUN_002211b8 @ 002211b8 (8 bytes)

undefined * FUN_002211b8(void)

{
  return &DAT_200607e0;
}


// ===== FUN_002211c0 @ 002211c0 (8 bytes)

undefined * FUN_002211c0(void)

{
  return &DAT_200619e0;
}


// ===== FUN_002211d0 @ 002211d0 (78 bytes)

void FUN_002211d0(void)

{
  memset(&DAT_0025ac00,0,0x20);
  memset(&DAT_0025ac20,0,0x20);
  memset(&DAT_0025ac40,0,0x20);
  DAT_0025ac14 = &DAT_0025ac60;
  DAT_0025ac54 = &DAT_0025ace0;
  DAT_0025ac18 = &DAT_0025ad20;
  DAT_0025ac38 = &DAT_0025ad40;
  DAT_0025ac34 = &DAT_0025aca0;
  DAT_0025ac58 = &DAT_0025ad60;
  return;
}


// ===== tx_eq_band3_update @ 00221220 (792 bytes)

void tx_eq_band3_update(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined2 uVar9;
  float fVar10;
  undefined8 in_aed0;
  ulonglong uVar11;
  undefined8 uVar12;
  float fVar13;
  uint uVar14;
  undefined *puVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  
  tx_eq_band_update(&DAT_0025ac00,0x25);
  tx_eq_band_update(&DAT_0025ac20,0x28);
  if ((uint)DAT_0025ac40 == (uint)DAT_20070056) {
    iVar7 = (int)DAT_20070058;
    if (DAT_0025ac42 != iVar7) goto LAB_00221290;
    uVar14 = (uint)DAT_2007005a;
    if (DAT_0025ac44 == uVar14) {
      return;
    }
  }
  else {
    DAT_0025ac40 = DAT_20070056;
    DAT_0025ac46 = DAT_20070056 >> 0xc & 1;
    puVar15 = (undefined *)(DAT_20070056 & 0xfff);
    if ((&DAT_0000176f < puVar15) || ((DAT_20070056 & 0xfff) != 0)) {
      iVar7 = (uint)(puVar15 < &DAT_0000176f) * (int)puVar15 +
              (uint)(puVar15 >= &DAT_0000176f) * (int)&DAT_0000176f;
    }
    else {
      iVar7 = 1;
    }
    uVar8 = ae_zext16(iVar7);
    i2f_scaled(uVar8,0);
    iVar7 = (int)DAT_20070058;
    DAT_0025ac48 = ae_s32_l_i(in_aed0);
    if (DAT_0025ac42 == iVar7) {
      uVar14 = (uint)DAT_2007005a;
      if (DAT_0025ac44 == uVar14) goto LAB_002212fb;
    }
    else {
LAB_00221290:
      DAT_0025ac42 = (short)iVar7;
      if ((iVar7 < 0x15) && ((iVar7 + 0x28U & 0x80000000) != 0)) {
        iVar7 = -0x28;
      }
      else {
        iVar7 = (uint)(iVar7 < 0x14) * iVar7 + (uint)(iVar7 >= 0x14) * 0x14;
      }
      uVar8 = ae_sext16(iVar7);
      i2f_scaled(uVar8,0);
      uVar14 = (uint)DAT_2007005a;
      DAT_0025ac4c = ae_s32_l_i(in_aed0);
      if (DAT_0025ac44 == uVar14) {
        in_aed0 = ae_l32_i(DAT_0025ac48);
        goto LAB_002212fb;
      }
    }
  }
  DAT_0025ac44 = (ushort)uVar14;
  if (uVar14 == 0) {
    uVar12 = ae_l32_i(0x3f000000);
    DAT_0025ac50 = ae_s32_l_i(uVar12);
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
    DAT_0025ac50 = ae_s32_l_i(in_aed0);
  }
  in_aed0 = ae_l32_i(DAT_0025ac48);
LAB_002212fb:
  uVar11 = (ulonglong)(uint)((float)in_aed0 * 3.1415927 * 8.333333e-05);
  tanf_();
  uVar12 = ae_l32_i(DAT_0025ac4c);
  uVar8 = ae_s32_l_i(uVar11);
  uVar11 = (ulonglong)(uint)((float)uVar12 * 0.05);
  pow10f_();
  uVar12 = ae_l32_i(DAT_0025ac50);
  uVar17 = const_s(0);
  uVar9 = oeq_s(uVar12,uVar17);
  uVar4 = ae_s32_l_i(uVar11);
  if (SUB21(uVar9,0)) {
    uVar12 = const_s(3);
    DAT_0025ac50 = ae_s32_l_i(uVar12);
    ae_l32_i(0x3f000000);
  }
  uVar12 = const_s(1);
  divf_();
  uVar1 = ae_s32_l_i(uVar12);
  ae_l32_i(uVar4);
  uVar12 = ae_l32_i(0x3f800000);
  divf_();
  uVar17 = ae_l32_i(uVar4);
  uVar16 = ae_l32_i(0x3f800000);
  uVar9 = olt_s(uVar17,uVar16);
  iVar7 = ae_l16si_n(&DAT_0025ac40,2);
  uVar12 = movt_s(uVar17,uVar12,(char)uVar9);
  if (iVar7 < 1) {
    if (iVar7 < 0) {
      uVar16 = ae_l32_i(uVar1);
      uVar17 = ae_l32_i(uVar8);
      fVar13 = (float)uVar17;
      fVar3 = fVar13 * (float)uVar12 * (float)uVar16;
      uVar12 = ae_l32_i(0x3f800000);
      fVar10 = fVar13 * fVar13;
      fVar13 = (float)uVar16 * fVar13;
      uVar4 = ae_s32_l_i((ulonglong)(uint)fVar13);
      uVar1 = ae_s32_l_i((ulonglong)(uint)fVar10);
      uVar5 = ae_s32_l_i((ulonglong)(uint)fVar3);
      uVar2 = ae_s32_l_i((ulonglong)(uint)(fVar3 + (float)uVar12 + fVar10));
      uVar11 = (ulonglong)(uint)(fVar13 + (float)uVar12 + fVar10);
      divf_();
      uVar17 = ae_l32_i(uVar1);
      uVar16 = ae_l32_i(0xbf800000);
      uVar12 = ae_l32_i(&DAT_40000000);
      uVar8 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar2);
      uVar11 = (ulonglong)(uint)(((float)uVar17 + (float)uVar16) * (float)uVar12);
      divf_();
      uVar17 = ae_l32_i(uVar4);
      uVar16 = ae_l32_i(0x3f800000);
      uVar12 = ae_l32_i(uVar1);
      uVar4 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar2);
      uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar16 - (float)uVar17));
      divf_();
      uVar12 = ae_l32_i(uVar5);
      uVar17 = ae_l32_i(0x3f800000);
      uVar16 = ae_l32_i(uVar1);
      uVar1 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar2);
      uVar11 = (ulonglong)(uint)((float)uVar16 + ((float)uVar17 - (float)uVar12));
      divf_();
      uVar17 = ae_l32_i(uVar4);
      uVar16 = ae_l32_i(uVar8);
      uVar12 = ae_l32_i(uVar1);
    }
    else {
      uVar11 = ae_l32_i(0);
      uVar16 = ae_mov(uVar12);
      uVar12 = ae_mov(uVar11);
      uVar17 = ae_mov(uVar11);
    }
  }
  else {
    uVar17 = ae_l32_i(uVar8);
    uVar16 = ae_l32_i(uVar1);
    fVar10 = (float)uVar17;
    fVar13 = (float)uVar16 * fVar10;
    uVar17 = ae_l32_i(0x3f800000);
    fVar3 = fVar10 * fVar10;
    fVar10 = fVar10 * (float)uVar12 * (float)uVar16;
    uVar1 = ae_s32_l_i((ulonglong)(uint)fVar13);
    uVar5 = ae_s32_l_i((ulonglong)(uint)fVar3);
    uVar4 = ae_s32_l_i((ulonglong)(uint)fVar10);
    uVar2 = ae_s32_l_i((ulonglong)(uint)(fVar13 + (float)uVar17 + fVar3));
    uVar11 = (ulonglong)(uint)(fVar10 + (float)uVar17 + fVar3);
    divf_();
    uVar17 = ae_l32_i(uVar5);
    uVar16 = ae_l32_i(0xbf800000);
    uVar12 = ae_l32_i(&DAT_40000000);
    uVar8 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar2);
    uVar11 = (ulonglong)(uint)(((float)uVar17 + (float)uVar16) * (float)uVar12);
    divf_();
    uVar17 = ae_l32_i(uVar4);
    uVar16 = ae_l32_i(0x3f800000);
    uVar12 = ae_l32_i(uVar5);
    uVar4 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar2);
    uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar16 - (float)uVar17));
    divf_();
    uVar12 = ae_l32_i(uVar1);
    uVar17 = ae_l32_i(0x3f800000);
    uVar16 = ae_l32_i(uVar5);
    uVar1 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar2);
    uVar11 = (ulonglong)(uint)((float)uVar16 + ((float)uVar17 - (float)uVar12));
    divf_();
    uVar17 = ae_l32_i(uVar4);
    uVar16 = ae_l32_i(uVar8);
    uVar12 = ae_l32_i(uVar1);
  }
  puVar6 = DAT_0025ac58;
  uVar8 = ae_s32_l_i(uVar16);
  *DAT_0025ac58 = uVar8;
  uVar8 = ae_s32_l_i(uVar12);
  puVar6[2] = uVar8;
  uVar8 = ae_s32_l_i(uVar17);
  puVar6[1] = uVar8;
  uVar4 = DAT_0025ac54;
  uVar8 = ae_s32_l_i(uVar17);
  puVar6[3] = uVar8;
  uVar8 = ae_s32_l_i(uVar11);
  puVar6[4] = uVar8;
  DAT_0025ac5c = iir_cascade_init(uVar4,1,puVar6,0);
  return;
}


// ===== tx_eq_band_update @ 00221540 (783 bytes)

void tx_eq_band_update(ushort *param_1,int param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined2 uVar9;
  float fVar10;
  undefined8 in_aed0;
  ulonglong uVar11;
  undefined8 uVar12;
  float fVar13;
  undefined *puVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  
  uVar2 = *(ushort *)(&DAT_20070000 + param_2 * 2);
  iVar15 = (param_2 + 1) * 2;
  if ((uint)*param_1 == (uint)uVar2) {
    iVar15 = (int)*(short *)(&DAT_20070000 + iVar15);
    if ((short)param_1[1] != iVar15) goto LAB_00221599;
    uVar16 = (uint)*(ushort *)(&DAT_20070000 + (param_2 + 2) * 2);
    if (param_1[2] == uVar16) {
      return;
    }
  }
  else {
    param_1[3] = uVar2 >> 0xc & 1;
    *param_1 = uVar2;
    puVar14 = (undefined *)(uVar2 & 0xfff);
    if ((&DAT_0000176f < puVar14) || ((uVar2 & 0xfff) != 0)) {
      iVar6 = (uint)(puVar14 < &DAT_0000176f) * (int)puVar14 +
              (uint)(puVar14 >= &DAT_0000176f) * (int)&DAT_0000176f;
    }
    else {
      iVar6 = 1;
    }
    uVar7 = ae_zext16(iVar6);
    i2f_scaled(uVar7,0);
    iVar15 = (int)*(short *)(&DAT_20070000 + iVar15);
    uVar7 = ae_s32_l_i(in_aed0);
    *(undefined4 *)(param_1 + 4) = uVar7;
    if ((short)param_1[1] == iVar15) {
      uVar16 = (uint)*(ushort *)(&DAT_20070000 + (param_2 + 2) * 2);
      if (param_1[2] == uVar16) goto LAB_00221610;
    }
    else {
LAB_00221599:
      param_1[1] = (ushort)iVar15;
      if ((iVar15 < 0x15) && ((iVar15 + 0x28U & 0x80000000) != 0)) {
        iVar15 = -0x28;
      }
      else {
        iVar15 = (uint)(iVar15 < 0x14) * iVar15 + (uint)(iVar15 >= 0x14) * 0x14;
      }
      uVar7 = ae_sext16(iVar15);
      i2f_scaled(uVar7,0);
      uVar16 = (uint)*(ushort *)(&DAT_20070000 + (param_2 + 2) * 2);
      uVar7 = ae_s32_l_i(in_aed0);
      *(undefined4 *)(param_1 + 6) = uVar7;
      if (param_1[2] == uVar16) {
        in_aed0 = ae_l32_i(*(undefined4 *)(param_1 + 4));
        goto LAB_00221610;
      }
    }
  }
  param_1[2] = (ushort)uVar16;
  if (uVar16 == 0) {
    uVar12 = ae_l32_i(0x3f000000);
    uVar7 = ae_s32_l_i(uVar12);
    *(undefined4 *)(param_1 + 8) = uVar7;
  }
  else {
    if ((uVar16 < 0xb) && ((uVar16 - 1 & 0x80000000) != 0)) {
      iVar15 = 1;
    }
    else {
      iVar15 = (uVar16 < 10) * uVar16 + (uint)(uVar16 >= 10) * 10;
    }
    uVar7 = ae_zext16(iVar15);
    i2f_scaled(uVar7,0);
    uVar7 = ae_s32_l_i(in_aed0);
    *(undefined4 *)(param_1 + 8) = uVar7;
  }
  in_aed0 = ae_l32_i(*(undefined4 *)(param_1 + 4));
LAB_00221610:
  uVar11 = (ulonglong)(uint)((float)in_aed0 * 3.1415927 * 8.333333e-05);
  tanf_();
  uVar12 = ae_l32_i(*(undefined4 *)(param_1 + 6));
  uVar7 = ae_s32_l_i(uVar11);
  uVar11 = (ulonglong)(uint)((float)uVar12 * 0.05);
  pow10f_();
  uVar12 = ae_l32_i(*(undefined4 *)(param_1 + 8));
  uVar19 = const_s(0);
  uVar9 = oeq_s(uVar12,uVar19);
  uVar17 = ae_s32_l_i(uVar11);
  if (SUB21(uVar9,0)) {
    uVar12 = const_s(3);
    uVar1 = ae_s32_l_i(uVar12);
    *(undefined4 *)(param_1 + 8) = uVar1;
    ae_l32_i(0x3f000000);
  }
  uVar12 = const_s(1);
  divf_();
  uVar1 = ae_s32_l_i(uVar12);
  ae_l32_i(uVar17);
  uVar12 = ae_l32_i(0x3f800000);
  divf_();
  uVar19 = ae_l32_i(uVar17);
  uVar18 = ae_l32_i(0x3f800000);
  uVar9 = olt_s(uVar19,uVar18);
  iVar15 = ae_l16si_n(param_1,2);
  uVar12 = movt_s(uVar19,uVar12,(char)uVar9);
  if (iVar15 < 1) {
    if (iVar15 < 0) {
      uVar18 = ae_l32_i(uVar1);
      uVar19 = ae_l32_i(uVar7);
      fVar13 = (float)uVar19;
      fVar4 = fVar13 * (float)uVar12 * (float)uVar18;
      uVar12 = ae_l32_i(0x3f800000);
      fVar10 = fVar13 * fVar13;
      fVar13 = (float)uVar18 * fVar13;
      uVar17 = ae_s32_l_i((ulonglong)(uint)fVar13);
      uVar1 = ae_s32_l_i((ulonglong)(uint)fVar10);
      uVar5 = ae_s32_l_i((ulonglong)(uint)fVar4);
      uVar3 = ae_s32_l_i((ulonglong)(uint)(fVar4 + (float)uVar12 + fVar10));
      uVar11 = (ulonglong)(uint)(fVar13 + (float)uVar12 + fVar10);
      divf_();
      uVar19 = ae_l32_i(uVar1);
      uVar18 = ae_l32_i(0xbf800000);
      uVar12 = ae_l32_i(&DAT_40000000);
      uVar7 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar3);
      uVar11 = (ulonglong)(uint)(((float)uVar19 + (float)uVar18) * (float)uVar12);
      divf_();
      uVar19 = ae_l32_i(uVar17);
      uVar18 = ae_l32_i(0x3f800000);
      uVar12 = ae_l32_i(uVar1);
      uVar17 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar3);
      uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar18 - (float)uVar19));
      divf_();
      uVar12 = ae_l32_i(uVar5);
      uVar19 = ae_l32_i(0x3f800000);
      uVar18 = ae_l32_i(uVar1);
      uVar1 = ae_s32_l_i(uVar11);
      ae_l32_i(uVar3);
      uVar11 = (ulonglong)(uint)((float)uVar18 + ((float)uVar19 - (float)uVar12));
      divf_();
      uVar19 = ae_l32_i(uVar17);
      uVar18 = ae_l32_i(uVar7);
      uVar12 = ae_l32_i(uVar1);
    }
    else {
      uVar11 = ae_l32_i(0);
      uVar18 = ae_mov(uVar12);
      uVar12 = ae_mov(uVar11);
      uVar19 = ae_mov(uVar11);
    }
  }
  else {
    uVar19 = ae_l32_i(uVar7);
    uVar18 = ae_l32_i(uVar1);
    fVar10 = (float)uVar19;
    fVar13 = (float)uVar18 * fVar10;
    uVar19 = ae_l32_i(0x3f800000);
    fVar4 = fVar10 * fVar10;
    fVar10 = fVar10 * (float)uVar12 * (float)uVar18;
    uVar1 = ae_s32_l_i((ulonglong)(uint)fVar13);
    uVar5 = ae_s32_l_i((ulonglong)(uint)fVar4);
    uVar17 = ae_s32_l_i((ulonglong)(uint)fVar10);
    uVar3 = ae_s32_l_i((ulonglong)(uint)(fVar13 + (float)uVar19 + fVar4));
    uVar11 = (ulonglong)(uint)(fVar10 + (float)uVar19 + fVar4);
    divf_();
    uVar19 = ae_l32_i(uVar5);
    uVar18 = ae_l32_i(0xbf800000);
    uVar12 = ae_l32_i(&DAT_40000000);
    uVar7 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar3);
    uVar11 = (ulonglong)(uint)(((float)uVar19 + (float)uVar18) * (float)uVar12);
    divf_();
    uVar19 = ae_l32_i(uVar17);
    uVar18 = ae_l32_i(0x3f800000);
    uVar12 = ae_l32_i(uVar5);
    uVar17 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar3);
    uVar11 = (ulonglong)(uint)((float)uVar12 + ((float)uVar18 - (float)uVar19));
    divf_();
    uVar12 = ae_l32_i(uVar1);
    uVar19 = ae_l32_i(0x3f800000);
    uVar18 = ae_l32_i(uVar5);
    uVar1 = ae_s32_l_i(uVar11);
    ae_l32_i(uVar3);
    uVar11 = (ulonglong)(uint)((float)uVar18 + ((float)uVar19 - (float)uVar12));
    divf_();
    uVar19 = ae_l32_i(uVar17);
    uVar18 = ae_l32_i(uVar7);
    uVar12 = ae_l32_i(uVar1);
  }
  puVar8 = *(undefined4 **)(param_1 + 0xc);
  uVar7 = ae_s32_l_i(uVar18);
  *puVar8 = uVar7;
  uVar7 = ae_s32_l_i(uVar12);
  puVar8[2] = uVar7;
  uVar7 = ae_s32_l_i(uVar19);
  puVar8[1] = uVar7;
  uVar17 = *(undefined4 *)(param_1 + 10);
  uVar7 = ae_s32_l_i(uVar19);
  puVar8[3] = uVar7;
  uVar7 = ae_s32_l_i(uVar11);
  puVar8[4] = uVar7;
  uVar7 = iir_cascade_init(uVar17,1,puVar8,0);
  *(undefined4 *)(param_1 + 0xe) = uVar7;
  return;
}


// ===== tx_param_eq_3band @ 00221854 (126 bytes)

/* regs 0x25-0x2D */

void tx_param_eq_3band(int param_1,int param_2)

{
  tx_eq_band3_update();
  if (param_1 != param_2) {
    memcpy(param_2,param_1,0x10);
  }
  if (DAT_0025ac06 != 0) {
    memcpy(&DAT_0025ad80,param_2,0x10);
    iir_cascade_process(DAT_0025ac1c,param_2,&DAT_0025ad80,4);
  }
  if (DAT_0025ac26 != 0) {
    memcpy(&DAT_0025ad80,param_2,0x10);
    iir_cascade_process(DAT_0025ac3c,param_2,&DAT_0025ad80,4);
  }
  if (DAT_0025ac46 != 0) {
    memcpy(&DAT_0025ad80,param_2,0x10);
    iir_cascade_process(DAT_0025ac5c,param_2,&DAT_0025ad80,4);
  }
  return;
}


// ===== am_modulator_init @ 002218e0 (37 bytes)

void am_modulator_init(void)

{
  undefined8 uVar1;
  
  uVar1 = const_s(0);
  DAT_0025ad94 = ae_s32_l_i(uVar1);
  DAT_0025ad90 = ae_s32_l_i(uVar1);
  DAT_0025ad98 = ae_s32_l_i(uVar1);
  DAT_0025ad9c = iir_cascade_init(0x25ada0,6,&DAT_00236bd0,1);
  return;
}


// ===== am_modulator @ 00221908 (247 bytes)

/* 24 kHz carrier, 30 %, BP 0x236BD0 */

void am_modulator(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  float fVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar9 = ae_l32_i(DAT_0025ad94);
  uVar8 = ae_l32_i(*param_1);
  uVar7 = ae_l32_i(DAT_0025ad90);
  fVar5 = ((float)uVar8 + (float)uVar9 * 0.999) - (float)uVar7;
  puVar3 = &DAT_0025ae80;
  ae_s32_l_i((ulonglong)(uint)fVar5);
  uVar8 = ae_l32_ip(*param_1);
  ae_s32_l_i(uVar8);
  DAT_0025ae80 = ae_s32_l_ip((ulonglong)(uint)fVar5);
  uVar7 = ae_l32_i(param_1[1]);
  uVar6 = (ulonglong)(uint)(((float)uVar7 + fVar5 * 0.999) - (float)uVar8);
  DAT_0025ad94 = ae_s32_l_i(uVar6);
  uVar7 = ae_l32_ip(param_1[1]);
  DAT_0025ad90 = ae_s32_l_i(uVar7);
  DAT_0025ae84 = ae_s32_l_ip(uVar6);
  puVar2 = &DAT_0025aee0;
  do {
    uVar7 = ae_l32_i(DAT_0025ad98);
    uVar8 = ae_l32_i(&DAT_40060a92);
    uVar6 = (ulonglong)(uint)((float)uVar7 + (float)uVar8);
    uVar7 = ae_l32_i(0x40c90fdb);
    uVar4 = olt_s(uVar7,uVar6);
    DAT_0025ad98 = ae_s32_l_i(uVar6);
    if (SUB21(uVar4,0)) {
      do {
        uVar7 = ae_l32_i(0xc0c90fdb);
        uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar7);
        uVar7 = ae_l32_i(0x40c90fdb);
        uVar4 = olt_s(uVar7,uVar6);
        DAT_0025ad98 = ae_s32_l_i(uVar6);
      } while (SUB21(uVar4,0));
    }
    uVar7 = ae_l32_i(0);
    uVar4 = olt_s(uVar6,uVar7);
    if (SUB21(uVar4,0)) {
      do {
        uVar7 = ae_l32_i(0x40c90fdb);
        uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar7);
        uVar7 = ae_l32_i(0);
        uVar4 = olt_s(uVar6,uVar7);
        DAT_0025ad98 = ae_s32_l_i(uVar6);
      } while (SUB21(uVar4,0));
    }
    fVar5 = (float)uVar6;
    cosf_();
    uVar7 = ae_l32_ip(*puVar3);
    puVar3 = puVar3 + 1;
    uVar8 = ae_l32_i(0x3f800000);
    uVar9 = ae_l32_i(0x3e99999a);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)(fVar5 * ((float)uVar7 + (float)uVar8) * (float)uVar9));
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (puVar3 != &DAT_0025aee0);
  iir_cascade_process(DAT_0025ad9c,param_2,&DAT_0025aee0,0x18);
  return;
}


// ===== fm_modulator_init @ 00221a10 (30 bytes)

void fm_modulator_init(void)

{
  undefined8 uVar1;
  
  ae_s16i_n(0xff,&DAT_0025af40,0);
  DAT_0025af44 = 0x3f278d37;
  uVar1 = const_s(0);
  DAT_0025af48 = ae_s32_l_i(uVar1);
  return;
}


// ===== fm_modulator @ 00221a30 (206 bytes)

/* 24 kHz centre, deviation reg 0x4007 */

void fm_modulator(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  float in_aed0;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  if (DAT_0025af40 != DAT_2007800e) {
    DAT_0025af40 = DAT_2007800e;
    i2f_scaled(DAT_2007800e,0xfffffff8);
    DAT_0025af44 = ae_s32_l_i((ulonglong)(uint)(in_aed0 * 7500.0 * 8.726647e-05));
  }
  uVar10 = const_s(0);
  iVar8 = 0;
  uVar4 = 0x40c90fdb;
  do {
    uVar7 = ae_l32_i(DAT_0025af44);
    uVar9 = ae_l32_i(*param_1);
    uVar6 = ae_l32_i(&DAT_40060a92);
    uVar5 = ae_l32_i(DAT_0025af48);
    uVar3 = (ulonglong)(uint)((float)uVar5 + (float)uVar9 * (float)uVar7 + (float)uVar6);
    uVar2 = olt_s(uVar4,uVar3);
    DAT_0025af48 = ae_s32_l_i(uVar3);
    if (SUB21(uVar2,0)) {
      do {
        uVar5 = ae_l32_i(0xc0c90fdb);
        uVar3 = (ulonglong)(uint)((float)uVar3 + (float)uVar5);
        uVar2 = olt_s(uVar4,uVar3);
        DAT_0025af48 = ae_s32_l_i(uVar3);
      } while (SUB21(uVar2,0));
    }
    uVar2 = olt_s(uVar3,uVar10);
    if (SUB21(uVar2,0)) {
      do {
        uVar3 = (ulonglong)(uint)((float)uVar3 + (float)uVar4);
        uVar2 = olt_s(uVar3,uVar10);
        DAT_0025af48 = ae_s32_l_i(uVar3);
      } while (SUB21(uVar2,0));
    }
    cosf_();
    uVar1 = ae_s32_l_ip(uVar3);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    uVar4 = ae_l32_i(0x40c90fdb);
    iVar8 = iVar8 + 1;
    uVar10 = ae_l32_i(0);
  } while (iVar8 != 0x18);
  return;
}


// ===== weaver_ssb_mod_init @ 00221b10 (165 bytes)

void weaver_ssb_mod_init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = const_s(0);
  DAT_0025af54 = ae_s32_l_i(uVar3);
  DAT_0025af58 = ae_s32_l_i(uVar3);
  uVar3 = const_s(1);
  uVar3 = movnez_s(uVar3,0xbf800000,(uint)(param_1 == 0));
  DAT_0025af50 = ae_s32_l_i(uVar3);
  DAT_0025af5c = iir_cascade_init(&DAT_0025af70,5,&DAT_002373d0,1);
  DAT_0025b1b0 = iir_cascade_init(&DAT_0025b030,5,&DAT_002373d0,1);
  DAT_0025b1b4 = iir_cascade_init(&DAT_0025b0f0,5,&DAT_002373d0,1);
  iVar1 = ae_l16si_n(&DAT_00205534,0);
  uVar2 = ae_sext16(iVar1 + 1);
  DAT_0025af60 = iir_cascade_init(0x25b1c0,9,&DAT_00237440,uVar2);
  iVar1 = ae_l16si_n(&DAT_00205534,0);
  uVar2 = ae_sext16(iVar1 + 1);
  DAT_0025af64 = iir_cascade_init(&DAT_0025b300,9,&DAT_00237440,uVar2);
  return;
}


// ===== weaver_ssb_mod @ 00221bb8 (628 bytes)

/* 2 kHz NCO at 12 kHz, (+-2000+18000) Hz at 72 kHz */

void weaver_ssb_mod(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  float fVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  float fVar12;
  undefined8 uVar13;
  
  memcpy(&DAT_0025b440,param_1,0x60);
  iir_cascade_process(DAT_0025af5c,&DAT_0025b4a0,&DAT_0025b440,0x18);
  uVar9 = ae_l32_ip(DAT_0025b4a0);
  DAT_0025b440 = ae_s32_l_ip(uVar9);
  uVar9 = ae_l32_ip(DAT_0025b4b8);
  DAT_0025b444 = ae_s32_l_ip(uVar9);
  uVar9 = ae_l32_ip(DAT_0025b4d0);
  DAT_0025b448 = ae_s32_l_ip(uVar9);
  uVar9 = ae_l32_ip(DAT_0025b4e8);
  DAT_0025b44c = ae_s32_l_ip(uVar9);
  puVar4 = &DAT_0025b4a0;
  uVar10 = 0x3f860a92;
  uVar9 = 0x40c90fdb;
  uVar13 = const_s(0);
  puVar3 = &DAT_0025b500;
  puVar5 = &DAT_0025b440;
  do {
    uVar11 = ae_l32_i(DAT_0025af54);
    uVar8 = (ulonglong)(uint)((float)uVar11 + (float)uVar10);
    uVar6 = olt_s(uVar9,uVar8);
    DAT_0025af54 = ae_s32_l_i(uVar8);
    if (SUB21(uVar6,0)) {
      do {
        uVar10 = ae_l32_i(0xc0c90fdb);
        uVar8 = (ulonglong)(uint)((float)uVar8 + (float)uVar10);
        uVar6 = olt_s(uVar9,uVar8);
        DAT_0025af54 = ae_s32_l_i(uVar8);
      } while (SUB21(uVar6,0));
    }
    uVar6 = olt_s(uVar8,uVar13);
    if (SUB21(uVar6,0)) {
      do {
        uVar8 = (ulonglong)(uint)((float)uVar8 + (float)uVar9);
        uVar6 = olt_s(uVar8,uVar13);
        DAT_0025af54 = ae_s32_l_i(uVar8);
      } while (SUB21(uVar6,0));
    }
    cosf_();
    uVar1 = ae_s32_l_i(uVar8);
    uVar9 = ae_l32_i(DAT_0025af54);
    fVar7 = (float)uVar9;
    sinf_();
    uVar13 = ae_l32_ip(*puVar5);
    puVar5 = puVar5 + 1;
    uVar9 = ae_l32_i(uVar1);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar9 * (float)uVar13));
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    uVar9 = ae_l32_i(0x40c90fdb);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)(fVar7 * (float)uVar13));
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
    uVar13 = ae_l32_i(0);
    uVar10 = ae_l32_i(0x3f860a92);
  } while (puVar5 != (undefined4 *)&DAT_0025b450);
  iir_cascade_process(DAT_0025af60,&DAT_0025b440,&DAT_0025b4a0,4);
  iir_cascade_process(DAT_0025af64,&DAT_0025b560,&DAT_0025b500,4);
  memset(&DAT_0025b4a0,0,0x60);
  uVar9 = ae_l32_ip(DAT_0025b440);
  uVar13 = ae_l32_ip(DAT_0025b444);
  uVar10 = ae_l32_ip(DAT_0025b448);
  uVar11 = ae_l32_ip(DAT_0025b44c);
  DAT_0025b4a0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar9 * 6.0));
  DAT_0025b4b8 = ae_s32_l_ip((ulonglong)(uint)((float)uVar13 * 6.0));
  DAT_0025b4d0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar10 * 6.0));
  DAT_0025b4e8 = ae_s32_l_ip((ulonglong)(uint)((float)uVar11 * 6.0));
  iir_cascade_process(DAT_0025b1b0,&DAT_0025b440,&DAT_0025b4a0,0x18);
  memset(&DAT_0025b500,0,0x60);
  uVar10 = ae_l32_i(0x40c00000);
  uVar9 = ae_l32_ip(DAT_0025b560);
  uVar13 = ae_l32_ip(DAT_0025b564);
  fVar7 = (float)uVar10;
  uVar10 = ae_l32_ip(DAT_0025b568);
  uVar11 = ae_l32_ip(DAT_0025b56c);
  DAT_0025b500 = ae_s32_l_ip((ulonglong)(uint)((float)uVar9 * fVar7));
  DAT_0025b518 = ae_s32_l_ip((ulonglong)(uint)((float)uVar13 * fVar7));
  DAT_0025b530 = ae_s32_l_ip((ulonglong)(uint)((float)uVar10 * fVar7));
  DAT_0025b548 = ae_s32_l_ip((ulonglong)(uint)((float)uVar11 * fVar7));
  iir_cascade_process(DAT_0025b1b4,&DAT_0025b560,&DAT_0025b500,0x18);
  puVar3 = &DAT_0025b560;
  uVar10 = ae_l32_i(DAT_0025af50);
  uVar9 = ae_l32_i(0x40c90fdb);
  uVar13 = ae_l32_i(0);
  uVar1 = ae_s32_l_i((ulonglong)
                     (uint)(((float)uVar10 * 2000.0 + 18000.0) * (float)uVar9 * 1.3888889e-05));
  puVar4 = &DAT_0025b440;
  do {
    uVar10 = ae_l32_i(uVar1);
    uVar11 = ae_l32_i(DAT_0025af58);
    uVar8 = (ulonglong)(uint)((float)uVar11 + (float)uVar10);
    uVar6 = olt_s(uVar9,uVar8);
    DAT_0025af58 = ae_s32_l_i(uVar8);
    if (SUB21(uVar6,0)) {
      do {
        uVar10 = ae_l32_i(0xc0c90fdb);
        uVar8 = (ulonglong)(uint)((float)uVar8 + (float)uVar10);
        uVar6 = olt_s(uVar9,uVar8);
        DAT_0025af58 = ae_s32_l_i(uVar8);
      } while (SUB21(uVar6,0));
    }
    uVar6 = olt_s(uVar8,uVar13);
    if (SUB21(uVar6,0)) {
      do {
        uVar8 = (ulonglong)(uint)((float)uVar8 + (float)uVar9);
        uVar6 = olt_s(uVar8,uVar13);
        DAT_0025af58 = ae_s32_l_i(uVar8);
      } while (SUB21(uVar6,0));
    }
    cosf_();
    uVar2 = ae_s32_l_i(uVar8);
    uVar9 = ae_l32_i(DAT_0025af58);
    fVar12 = (float)uVar9;
    sinf_();
    uVar9 = ae_l32_i(*puVar3);
    fVar12 = (float)uVar9 * fVar12;
    uVar9 = ae_l32_i(DAT_0025af50);
    uVar10 = ae_l32_i(uVar2);
    uVar13 = ae_l32_i(*puVar4);
    fVar7 = (float)uVar13 * (float)uVar10;
    uVar2 = ae_s32_l_ip((ulonglong)(uint)fVar12);
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
    uVar2 = ae_s32_l_ip((ulonglong)(uint)fVar7);
    *puVar4 = uVar2;
    puVar4 = puVar4 + 1;
    uVar2 = ae_s32_l_ip((ulonglong)(uint)(fVar7 + (float)uVar9 * fVar12));
    *param_2 = uVar2;
    param_2 = param_2 + 1;
    uVar9 = ae_l32_i(0x40c90fdb);
    uVar13 = ae_l32_i(0);
  } while (puVar4 != &DAT_0025b4a0);
  return;
}


// ===== FUN_00221e40 @ 00221e40 (66 bytes)

void FUN_00221e40(void)

{
  undefined8 uVar1;
  
  memset(&DAT_0025b5c0,0,0x30);
  uVar1 = const_s(1);
  DAT_0025b5cc = ae_s32_l_i(uVar1);
  DAT_0025b5d0 = ae_s32_l_i(uVar1);
  DAT_0025b5d4 = ae_s32_l_i(uVar1);
  DAT_0025b5d8 = ae_s32_l_i(uVar1);
  DAT_0025b5dc = ae_s32_l_i(uVar1);
  DAT_0025b5e0 = ae_s32_l_i(uVar1);
  DAT_0025b5ec = ae_s32_l_i(uVar1);
  uVar1 = const_s(3);
  DAT_0025b5e4 = ae_s32_l_i(uVar1);
  uVar1 = const_s(0);
  DAT_0025b5e8 = ae_s32_l_i(uVar1);
  return;
}


// ===== tx_alc_update @ 00221e84 (266 bytes)

/* reg 0x34 bit 12 on, bits 11-0 level % (1..100); 0x31/0x32 10^(x/40); 0x33 release coefficient
   powf(0.5, x) per 72 kHz sample (#184) */

void tx_alc_update(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  ulonglong in_aed0;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  
  if ((uint)DAT_0025b5c0 != (uint)DAT_20070068) {
    DAT_0025b5c0 = DAT_20070068;
    uVar6 = DAT_20070068 & 0xfff;
    if ((uVar6 < 0x65) && ((DAT_20070068 & 0xfff) == 0)) {
      iVar2 = 1;
    }
    else {
      iVar2 = (uVar6 < 100) * uVar6 + (uint)(uVar6 >= 100) * 100;
    }
    uVar3 = ae_zext16(iVar2);
    DAT_0025b5c8 = DAT_20070068 >> 0xc & 1;
    i2f_scaled(uVar3,0);
    fVar1 = (float)in_aed0 * 0.01;
    uVar4 = ae_l32_i(DAT_0025b5d4);
    uVar5 = ae_l32_i(DAT_0025b5d8);
    DAT_0025b5d0 = ae_s32_l_i((ulonglong)(uint)fVar1);
    DAT_0025b5cc = ae_s32_l_i((ulonglong)(uint)((float)uVar4 * fVar1));
    DAT_0025b5dc = ae_s32_l_i((ulonglong)(uint)((float)uVar5 * fVar1));
  }
  if ((int)(short)DAT_0025b5c2 != (uint)DAT_20070062) {
    DAT_0025b5c2 = DAT_20070062;
    i2f_scaled(DAT_20070062 | 0xfffff000,0xffffffff);
    uVar4 = ae_l32_i(0x3d4ccccd);
    in_aed0 = (ulonglong)(uint)((float)in_aed0 * (float)uVar4);
    pow10f_();
    uVar4 = ae_l32_i(DAT_0025b5d0);
    DAT_0025b5d4 = ae_s32_l_i(in_aed0);
    DAT_0025b5cc = ae_s32_l_i((ulonglong)(uint)((float)uVar4 * (float)in_aed0));
  }
  if ((int)(short)DAT_0025b5c4 != (uint)DAT_20070064) {
    DAT_0025b5c4 = DAT_20070064;
    i2f_scaled(DAT_20070064 | 0xfffff000,0xffffffff);
    uVar4 = ae_l32_i(0x3d4ccccd);
    in_aed0 = (ulonglong)(uint)((float)in_aed0 * (float)uVar4);
    pow10f_();
    uVar4 = ae_l32_i(DAT_0025b5d0);
    DAT_0025b5d8 = ae_s32_l_i(in_aed0);
    DAT_0025b5dc = ae_s32_l_i((ulonglong)(uint)((float)uVar4 * (float)in_aed0));
  }
  uVar6 = (uint)DAT_20070066;
  if ((int)DAT_0025b5c6 != uVar6) {
    ae_s16i_n(uVar6,&DAT_0025b5c4,2);
    i2f_scaled(uVar6 & 0xfff,0);
    ae_mov(in_aed0);
    uVar4 = const_s(3);
    powf();
    DAT_0025b5e0 = ae_s32_l_i(uVar4);
    return;
  }
  return;
}


// ===== tx_alc @ 00221f98 (156 bytes)

/* reg 2 high byte = ALC gain reduction */

void tx_alc(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined8 uVar8;
  
  tx_alc_update();
  iVar7 = 0;
  if (DAT_0025b5c8 == 0) {
    if (param_1 != param_2) {
      memcpy(param_2,param_1,0x60);
      return;
    }
  }
  else {
    do {
      uVar4 = ae_l32_i(*param_1);
      uVar6 = ae_l32_i(DAT_0025b5e8);
      uVar2 = ole_s(uVar6,(ulonglong)(uint)ABS((float)uVar4));
      uVar5 = ae_l32_i(DAT_0025b5e4);
      uVar8 = ae_l32_i(DAT_0025b5e0);
      uVar5 = movt_s(uVar8,uVar5,(char)uVar2);
      uVar8 = ae_l32_i(0x3f800000);
      uVar3 = (ulonglong)
              (uint)(ABS((float)uVar4) * (float)uVar5 + (float)uVar6 * ((float)uVar8 - (float)uVar5)
                    );
      uVar4 = ae_l32_i(DAT_0025b5dc);
      uVar2 = ole_s(uVar4,uVar3);
      DAT_0025b5e8 = ae_s32_l_i(uVar3);
      movt_s(uVar4,uVar3,(char)uVar2);
      uVar4 = ae_l32_i(DAT_0025b5cc);
      divf_();
      DAT_0025b5ec = ae_s32_l_i(uVar4);
      uVar5 = ae_l32_ip(*param_1);
      param_1 = param_1 + 1;
      uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar5 * (float)uVar4));
      *param_2 = uVar1;
      param_2 = param_2 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0x18);
    FUN_00222034();
  }
  return;
}


// ===== FUN_00222034 @ 00222034 (101 bytes)

void FUN_00222034(void)

{
  undefined4 extraout_a3;
  int iVar1;
  uint uVar2;
  
  iVar1 = ae_l16ui_n(&DAT_0025b5f0,0);
  uVar2 = ae_zext16(iVar1 + 1);
  if (uVar2 < 5) {
    ae_s16i_n(uVar2,&DAT_0025b5f0,0);
    return;
  }
  DAT_0025b5f0 = 0;
  ae_l32_i(DAT_0025b5ec);
  log10f_();
  iVar1 = f2i_scaled(0xffffffff,extraout_a3,0xc1a00000);
  if ((iVar1 != 0) && (iVar1 < 1)) {
    DAT_20070004 = DAT_20070004 & 0xff;
    return;
  }
  if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  DAT_20070004 = DAT_20070004 & 0xff | (ushort)(iVar1 << 8);
  return;
}


// ===== FUN_002220a0 @ 002220a0 (72 bytes)

void FUN_002220a0(void)

{
  DAT_0025b600 = iir_cascade_init(&DAT_0025b610,5,&DAT_002373d0,1);
  DAT_0025b604 = iir_cascade_init(&DAT_0025b6d0,5,&DAT_002373d0,1);
  FUN_002211d0();
  peak_limiter_init(0);
  FUN_00222230();
  FUN_002221c0();
  FUN_00222d00();
  FUN_002230d0();
  FUN_00222e10();
  return;
}


// ===== tx_core_12k @ 002220e8 (216 bytes)

/* /6, EQ, processor, compressor, BPF, FM, limiter, x6 */

undefined * tx_core_12k(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  iir_cascade_process(DAT_0025b600,&DAT_0025b790,param_1,0x18);
  uVar2 = ae_l32_ip(DAT_0025b790);
  uVar1 = ae_l32_ip(DAT_0025b7a8);
  uVar4 = ae_l32_ip(DAT_0025b7c0);
  DAT_0025b7f0 = ae_s32_l_ip(uVar2);
  DAT_0025b7f4 = ae_s32_l_ip(uVar1);
  DAT_0025b7f8 = ae_s32_l_ip(uVar4);
  uVar1 = ae_l32_ip(DAT_0025b7d8);
  DAT_0025b7fc = ae_s32_l_ip(uVar1);
  tx_param_eq_3band(&DAT_0025b7f0,&DAT_0025b7f0);
  peak_limiter(0,&DAT_0025b7f0,&DAT_0025b7f0);
  soft_knee_compressor(&DAT_0025b7f0,&DAT_0025b7f0);
  tx_bpf_select(&DAT_0025b7f0,&DAT_0025b800);
  if (DAT_2007000c == 9) {
    fm_tx_audio(&DAT_0025b800,&DAT_0025b7f0);
  }
  else {
    memcpy(&DAT_0025b7f0,&DAT_0025b800,0x10);
  }
  soft_knee_limiter(&DAT_0025b7f0,&DAT_0025b7f0);
  memset(&DAT_0025b790,0,0x60);
  uVar1 = ae_l32_ip(DAT_0025b7f0);
  uVar2 = ae_l32_ip(DAT_0025b7f4);
  uVar4 = ae_l32_ip(DAT_0025b7f8);
  uVar3 = ae_l32_ip(DAT_0025b7fc);
  DAT_0025b790 = ae_s32_l_ip((ulonglong)(uint)((float)uVar1 * 6.0));
  DAT_0025b7a8 = ae_s32_l_ip((ulonglong)(uint)((float)uVar2 * 6.0));
  DAT_0025b7c0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar4 * 6.0));
  DAT_0025b7d8 = ae_s32_l_ip((ulonglong)(uint)((float)uVar3 * 6.0));
  iir_cascade_process(DAT_0025b604,param_2,&DAT_0025b790,0x18);
  return &DAT_0025b800;
}


// ===== FUN_002221c0 @ 002221c0 (13 bytes)

undefined8 FUN_002221c0(void)

{
  ae_s16i_n(0,&DAT_0025b810,0);
  return 0x25b81000000000;
}


// ===== tx_bpf_select @ 002221d0 (91 bytes)

/* reg 0x2F = 1..7 -> 0x236C50 passbands */

void tx_bpf_select(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)DAT_2007005e;
  uVar2 = (uint)DAT_0025b810;
  if (uVar1 != uVar2) {
    if ((uVar1 < 8) && (ae_s16i_n(uVar1,&DAT_0025b810,0), uVar1 != 0)) {
      DAT_0025b814 = iir_cascade_init(0x25b820,*(undefined2 *)(&DAT_00204d9e + uVar1 * 2),
                                      *(undefined4 *)(&DAT_00236c4c + uVar1 * 4),1);
    }
    uVar2 = ae_l16ui_n(&DAT_0025b810,0);
  }
  if (uVar2 != 0) {
    iir_cascade_process(DAT_0025b814,param_2,param_1,4);
    return;
  }
  memcpy(param_2,param_1,0x10);
  return;
}


// ===== FUN_00222230 @ 00222230 (17 bytes)

void FUN_00222230(void)

{
  memset(&DAT_0025b9c0,0,0x34);
  return;
}


// ===== soft_knee_compressor @ 00222244 (653 bytes)

/* regs 0x401A-0x401F (off by default) */

void soft_knee_compressor(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  ulonglong in_aed0;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  undefined8 uVar9;
  int iVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  
  DAT_0025b9ca = DAT_20078034;
  uVar8 = (uint)DAT_20078036;
  if (DAT_0025b9c0 != uVar8) {
    ae_s16i_n(uVar8,&DAT_0025b9c0,0);
    i2f_scaled(uVar8 & 0xfff,0);
    uVar5 = ae_l32_i(0x3a83126f);
    in_aed0 = (ulonglong)(uint)((float)in_aed0 * (float)uVar5);
    log10f_();
    uVar5 = ae_l32_i(0x41a00000);
    DAT_0025b9cc = ae_s32_l_i((ulonglong)(uint)((float)in_aed0 * (float)uVar5));
  }
  if (DAT_0025b9c2 != DAT_2007803c) {
    DAT_0025b9c2 = DAT_2007803c;
    i2f_scaled(DAT_2007803c,0);
    uVar5 = const_s(3);
    DAT_0025b9d0 = ae_s32_l_i(in_aed0);
    uVar9 = ae_l32_i(0);
    uVar4 = oeq_s(in_aed0,uVar9);
    DAT_0025b9d4 = ae_s32_l_i((ulonglong)(uint)((float)in_aed0 * (float)uVar5));
    if (SUB21(uVar4,0)) {
      in_aed0 = 0x40a00000;
    }
    else {
      const_s(2);
      in_aed0 = ae_l32_i(0x3f800000);
      divf_();
    }
    DAT_0025b9d8 = ae_s32_l_i(in_aed0);
  }
  if (DAT_0025b9c4 != DAT_20078038) {
    DAT_0025b9c4 = DAT_20078038;
    i2f_scaled(DAT_20078038,0);
    uVar9 = ae_l32_i(0x3a83126f);
    uVar5 = ae_l32_i(0);
    uVar4 = oeq_s((ulonglong)(uint)((float)in_aed0 * (float)uVar9),uVar5);
    if (SUB21(uVar4,0)) {
      DAT_0025b9dc = ae_s32_l_i(uVar5);
    }
    else {
      ae_l32_i(0x463b8000);
      in_aed0 = ae_l32_i(0xc00c9f54);
      divf_();
      FUN_00218cf0();
      DAT_0025b9dc = ae_s32_l_i(in_aed0);
    }
  }
  if (DAT_0025b9c6 != DAT_2007803a) {
    DAT_0025b9c6 = DAT_2007803a;
    i2f_scaled(DAT_2007803a,0);
    uVar9 = ae_l32_i(0x3a83126f);
    uVar5 = ae_l32_i(0);
    uVar4 = oeq_s((ulonglong)(uint)((float)in_aed0 * (float)uVar9),uVar5);
    if (SUB21(uVar4,0)) {
      DAT_0025b9e0 = ae_s32_l_i(uVar5);
    }
    else {
      ae_l32_i(0x463b8000);
      in_aed0 = ae_l32_i(0xc00c9f54);
      divf_();
      FUN_00218cf0();
      DAT_0025b9e0 = ae_s32_l_i(in_aed0);
    }
  }
  if (DAT_0025b9c8 != DAT_2007803e) {
    DAT_0025b9c8 = DAT_2007803e;
    i2f_scaled(DAT_2007803e,0);
    uVar5 = ae_l32_i(0);
    uVar4 = oeq_s(in_aed0,uVar5);
    DAT_0025b9e4 = ae_s32_l_i(in_aed0);
    uVar5 = ae_l32_i(0x3f800000);
    ae_mov(in_aed0);
    if (!SUB21(uVar4,0)) {
      uVar5 = ae_l32_i(0x3f800000);
      divf_();
    }
    DAT_0025b9e8 = ae_s32_l_i(uVar5);
  }
  iVar10 = 4;
  if (DAT_0025b9ca == 0) {
    if (param_1 != param_2) {
      memcpy(param_2,param_1,0x10);
      return;
    }
  }
  else {
    do {
      uVar5 = ae_l32_i(*param_1);
      uVar9 = ae_l32_i(0x358637bd);
      uVar4 = olt_s(uVar9,(ulonglong)(uint)ABS((float)uVar5));
      uVar5 = movf_s((ulonglong)(uint)ABS((float)uVar5),uVar9,(char)uVar4);
      fVar6 = (float)uVar5;
      log10f_();
      uVar9 = ae_l32_i(DAT_0025b9d4);
      uVar11 = ae_l32_i(DAT_0025b9cc);
      uVar5 = ae_l32_i(0x41a00000);
      fVar7 = (float)uVar11;
      fVar6 = fVar6 * (float)uVar5;
      uVar12 = (ulonglong)(uint)fVar6;
      uVar4 = olt_s(uVar12,(ulonglong)(uint)(fVar7 - (float)uVar9));
      uVar5 = ae_l32_i(DAT_0025b9e8);
      if (SUB21(uVar4,0)) {
        uVar5 = ae_mov(uVar12);
        fVar7 = (float)uVar5;
      }
      else {
        uVar4 = ole_s((ulonglong)(uint)(fVar7 + (float)uVar9),uVar12);
        if (SUB21(uVar4,0)) {
          fVar7 = fVar7 + (float)uVar5 * (fVar6 - fVar7);
        }
        else {
          uVar2 = ae_s32_l_i(uVar5);
          uVar1 = ae_s32_l_i(uVar12);
          uVar9 = FUN_0022b96c();
          uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
          uVar5 = ae_l32_i(uVar2);
          fVar7 = (float)uVar5;
          uVar5 = FUN_0022b96c();
          uVar5 = FUN_00235510((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0xbff00000);
          uVar5 = FUN_00235630((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar9,uVar3);
          FUN_00235630((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar9,uVar3);
          FUN_0022b8ac();
          uVar9 = ae_l32_i(DAT_0025b9d8);
          uVar5 = ae_l32_i(uVar1);
          fVar6 = (float)uVar5;
          fVar7 = (float)uVar9 * fVar7 + fVar6;
        }
      }
      uVar9 = ae_l32_i(DAT_0025b9f0);
      uVar4 = ole_s((ulonglong)(uint)(fVar7 - fVar6),uVar9);
      uVar5 = ae_l32_i(DAT_0025b9e0);
      uVar11 = ae_l32_i(DAT_0025b9dc);
      uVar5 = movt_s(uVar5,uVar11,(char)uVar4);
      uVar11 = ae_l32_i(0x3f800000);
      fVar6 = (float)uVar5 * (float)uVar9 + (fVar7 - fVar6) * ((float)uVar11 - (float)uVar5);
      uVar5 = ae_l32_i(0x3d4ccccd);
      DAT_0025b9f0 = ae_s32_l_i((ulonglong)(uint)fVar6);
      fVar6 = fVar6 * (float)uVar5;
      pow10f_();
      uVar5 = ae_l32_ip(*param_1);
      param_1 = param_1 + 1;
      uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar5 * fVar6));
      *param_2 = uVar1;
      param_2 = param_2 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  return;
}

