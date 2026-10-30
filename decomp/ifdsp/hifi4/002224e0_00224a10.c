// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== ctcss_encoder_init @ 002224e0 (48 bytes)

/* state 0x25B9F4; placed before ctcss_encoder [inference] */

void ctcss_encoder_init(void)

{
  undefined8 uVar1;
  
  DAT_0025b9fe = 0;
  DAT_0025ba08 = 0;
  DAT_0025b9fc = 0;
  DAT_0025b9f4 = 0;
  uVar1 = const_s(1);
  DAT_0025b9f8 = ae_s32_l_i(uVar1);
  uVar1 = const_s(0);
  DAT_0025ba00 = ae_s32_l_i(uVar1);
  DAT_0025ba04 = ae_s32_l_i(uVar1);
  return;
}


// ===== ctcss_encoder @ 00222510 (294 bytes)

/* reg 0x35, level reg 0x11 */

void ctcss_encoder(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  float in_aed0;
  float fVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined8 uVar8;
  int iVar9;
  undefined8 uVar10;
  
  if ((int)(short)DAT_20070022 != (uint)DAT_0025b9f4) {
    DAT_0025b9f4 = DAT_20070022;
    scl_int2float((int)(short)DAT_20070022,0xffffffff);
    uVar4 = (ulonglong)(uint)(in_aed0 * 0.05);
    scl_antilog10f();
    DAT_0025b9f8 = ae_s32_l_i(uVar4);
  }
  if ((uint)DAT_0025b9fc == (uint)DAT_2007006a) {
    if (DAT_0025ba08 == '\0') goto LAB_00222610;
  }
  else {
    DAT_0025b9fc = DAT_2007006a;
    if ((((DAT_2007006a >> 0xc & 1) == 0) ||
        (uVar2 = DAT_2007006a & 0xfff, (DAT_2007006a & 0xfff) == 0)) || (0x32 < uVar2)) {
      DAT_0025ba08 = '\0';
LAB_00222610:
      if (param_1 != param_2) {
        memcpy(param_2,param_1,0x60);
      }
      return;
    }
    uVar5 = ae_l32_i(FLOAT_ARRAY_00204dd0[uVar2]);
    DAT_0025ba08 = '\x01';
    DAT_0025ba04 = ae_s32_l_i((ulonglong)(uint)((float)uVar5 * 8.726647e-05));
  }
  uVar6 = const_s(0);
  iVar9 = 0;
  uVar5 = 0x40c90fdb;
  do {
    uVar8 = ae_l32_i(DAT_0025ba04);
    uVar10 = ae_l32_i(DAT_0025ba00);
    uVar4 = (ulonglong)(uint)((float)uVar10 + (float)uVar8);
    uVar7 = olt_s(uVar5,uVar4);
    uVar8 = ae_l32_i(*param_1);
    uVar1 = ae_s32_l_i(uVar8);
    DAT_0025ba00 = ae_s32_l_i(uVar4);
    if (SUB21(uVar7,0)) {
      do {
        uVar8 = ae_l32_i(0xc0c90fdb);
        uVar4 = (ulonglong)(uint)((float)uVar4 + (float)uVar8);
        uVar7 = olt_s(uVar5,uVar4);
        DAT_0025ba00 = ae_s32_l_i(uVar4);
      } while (SUB21(uVar7,0));
    }
    uVar7 = olt_s(uVar4,uVar6);
    if (SUB21(uVar7,0)) {
      do {
        uVar4 = (ulonglong)(uint)((float)uVar4 + (float)uVar5);
        uVar7 = olt_s(uVar4,uVar6);
        DAT_0025ba00 = ae_s32_l_i(uVar4);
      } while (SUB21(uVar7,0));
    }
    fVar3 = (float)uVar4;
    scl_cosinef();
    uVar6 = ae_l32_i(DAT_0025b9f8);
    uVar5 = ae_l32_i(uVar1);
    param_1 = param_1 + 1;
    iVar9 = iVar9 + 1;
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar5 + (float)uVar6 * fVar3));
    *param_2 = uVar1;
    param_2 = param_2 + 1;
    uVar5 = ae_l32_i(0x40c90fdb);
    uVar6 = ae_l32_i(0);
  } while (iVar9 != 0x18);
  return;
}


// ===== dcs_encoder_init @ 00222640 (69 bytes)

/* bkfiraf_init (0x205380) and iir_cascade_init; placed before dcs_encoder [inference] */

void dcs_encoder_init(void)

{
  undefined8 uVar1;
  
  uVar1 = const_s(1);
  DAT_0025ba18 = ae_s32_l_i(uVar1);
  DAT_0025ba10 = 0;
  DAT_0025ba14 = 0;
  DAT_0025ba1c = 0;
  DAT_0025ba20 = 0;
  DAT_0025ba24 = 0;
  DAT_0025ba28 = 0;
  DAT_0025ba2c = bkfiraf_init(0x25ba40,0x6d,FLOAT_ARRAY_00205380);
  DAT_0025ba30 = iir_cascade_init(&DAT_0025bde0,5,&DAT_002373d0,1);
  return;
}


// ===== dcs_encoder @ 00222688 (1050 bytes)

/* reg 0x38 */

undefined8 dcs_encoder(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  float in_aed0;
  float fVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  
  if ((int)(short)DAT_0025ba10 != (int)DAT_20070022) {
    DAT_0025ba10._0_2_ = DAT_20070022;
    scl_int2float((int)DAT_20070022,0xffffffff);
    uVar5 = (ulonglong)(uint)(in_aed0 * 0.05);
    scl_antilog10f();
    DAT_0025ba18 = ae_s32_l_i(uVar5);
  }
  uVar12 = (uint)DAT_20070070;
  uVar6 = const_s(1);
  if (DAT_0025ba10._2_2_ == uVar12) {
joined_r0x002226e3:
    if ((ushort)DAT_0025ba14 != 0) {
      uVar12 = (uint)DAT_0025ba24._2_2_;
      uVar19 = ae_l32_i(DAT_0025ba18);
      uVar7 = (uint)(ushort)DAT_0025ba24;
      if (uVar7 == 0) {
        DAT_0025ba28._0_2_ = DAT_20070072 & 1;
        if ((DAT_20070072 & 1) != 0) goto LAB_00222720;
LAB_00222740:
        uVar2 = 0;
        DAT_0025ba28._2_2_ = 0;
        uVar4 = ae_mov(0xbf800000);
        uVar6 = movnez_s(uVar4,uVar6,DAT_0025ba20 >> (uVar7 & 0x1f) & 1);
        fVar3 = (float)uVar6;
        if (uVar12 < 0xb2) goto LAB_00222729;
LAB_0022275c:
        DAT_0025ba24._2_2_ = 0;
        DAT_0025ba28._2_2_ = uVar2 + 1;
        if (uVar7 < 0x16) {
          uVar1 = ae_zext16(uVar7 + 1);
          DAT_0025ba24._0_2_ = (ushort)uVar1;
        }
        else {
          DAT_0025ba24._0_2_ = 0;
        }
      }
      else {
        if ((ushort)DAT_0025ba28 == 0) goto LAB_00222740;
LAB_00222720:
        uVar4 = ae_mov(0xbf800000);
        uVar6 = movnez_s(uVar4,uVar6,DAT_0025ba28._2_2_ & 1);
        fVar3 = (float)uVar6;
        uVar2 = DAT_0025ba28._2_2_;
        if (0xb1 < uVar12) goto LAB_0022275c;
LAB_00222729:
        uVar1 = ae_zext16(uVar12 + 1);
        DAT_0025ba24._2_2_ = (ushort)uVar1;
      }
      DAT_0025bea0 = ae_s32_l_ip((ulonglong)(uint)(fVar3 * (float)uVar19));
      bkfiraf_process(DAT_0025ba2c,&DAT_0025bf00,&DAT_0025bea0,8);
      memset(&DAT_0025bea0,0,0x60);
      uVar6 = ae_l32_ip(DAT_0025bf00);
      uVar19 = ae_l32_i(DAT_0025bf04);
      uVar4 = ae_l32_ip(DAT_0025bf08);
      uVar20 = ae_l32_i(DAT_0025bf0c);
      DAT_0025bea0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * 3.0));
      DAT_0025beac = ae_s32_l_i((ulonglong)(uint)((float)uVar19 * 3.0));
      DAT_0025beb8 = ae_s32_l_ip((ulonglong)(uint)((float)uVar4 * 3.0));
      DAT_0025bec4 = ae_s32_l_i((ulonglong)(uint)((float)uVar20 * 3.0));
      iir_cascade_process(DAT_0025ba30,&DAT_0025bf00,&DAT_0025bea0,0x18);
      uVar6 = ae_l32_ip(DAT_0025bf00);
      uVar19 = ae_l32_ip(*param_1);
      param_1 = param_1 + 1;
      uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar19 + (float)uVar6));
      *param_2 = uVar1;
      param_2 = param_2 + 1;
      goto LAB_002227f5;
    }
  }
  else {
    DAT_0025ba10._2_2_ = DAT_20070070;
    DAT_0025ba14._0_2_ = DAT_20070070 >> 0xc;
    if ((ushort)DAT_0025ba14 == 1) {
      uVar12 = uVar12 & 0xfff;
      uVar7 = uVar12 >> 4;
      uVar13 = uVar12 >> 1;
      uVar8 = uVar12 >> 2;
      uVar14 = uVar12 >> 5;
      uVar9 = uVar12 >> 6;
      uVar15 = uVar12 >> 3;
      uVar10 = uVar13 ^ uVar12;
      uVar16 = uVar15 ^ uVar10 ^ uVar8;
      uVar11 = uVar12 >> 8;
      uVar17 = uVar12 >> 7;
      uVar18 = uVar11 ^ uVar17;
      DAT_0025ba1c = uVar12 | ((uVar17 ^ uVar16 ^ uVar7) & 1 |
                              ((uVar11 ^ uVar13 ^ uVar8 ^ uVar15 ^ uVar7 ^ uVar14 ^ 0xffffffff) & 1
                              | ((uVar10 ^ uVar14 ^ uVar17 ^ uVar9) & 1 |
                                ((uVar11 ^ uVar17 ^ uVar13 ^ uVar8 ^ uVar9 ^ 0xffffffff) & 1 |
                                ((uVar11 ^ uVar10 ^ uVar7 ^ 0xffffffff) & 1 |
                                ((uVar17 ^ uVar7 ^ uVar14 ^ uVar15 ^ uVar12 ^ 0xffffffff) & 1 |
                                ((uVar18 ^ uVar9 ^ uVar14 ^ uVar15 ^ uVar8 ^ uVar12) & 1 |
                                ((uVar18 ^ uVar7 ^ uVar9 ^ uVar13 ^ uVar15) & 1 |
                                ((uVar18 ^ uVar14 ^ uVar7 ^ uVar8) & 1 |
                                ((uVar11 ^ uVar9 ^ uVar14 ^ uVar15 ^ 0xffffffff) & 1 |
                                ((uVar16 ^ uVar9 ^ 0xffffffff) & 1) << 1) << 1) << 1) << 1) << 1) <<
                                1) << 1) << 1) << 1) << 1) << 0xc | 0x800;
LAB_00222a94:
      DAT_0025ba24._0_2_ = 0;
      DAT_0025ba20 = DAT_0025ba1c;
      DAT_0025ba24._2_2_ = (ushort)DAT_0025ba24;
      goto joined_r0x002226e3;
    }
    if ((ushort)DAT_0025ba14 == 2) {
      uVar12 = uVar12 & 0xfff;
      uVar7 = uVar12 >> 7;
      uVar13 = uVar12 >> 8;
      uVar8 = uVar12 >> 4;
      uVar14 = uVar12 >> 3;
      uVar9 = uVar12 >> 5;
      uVar15 = uVar12 >> 6;
      uVar10 = uVar12 >> 1;
      uVar16 = uVar12 >> 2;
      uVar17 = uVar13 ^ uVar7;
      uVar11 = uVar10 ^ uVar12;
      uVar18 = uVar14 ^ uVar11 ^ uVar16;
      DAT_0025ba1c = (uVar12 | ((uVar7 ^ uVar18 ^ uVar8) & 1 |
                               ((uVar13 ^ uVar10 ^ uVar16 ^ uVar14 ^ uVar8 ^ uVar9 ^ 0xffffffff) & 1
                               | ((uVar11 ^ uVar9 ^ uVar7 ^ uVar15) & 1 |
                                 ((uVar13 ^ uVar7 ^ uVar10 ^ uVar16 ^ uVar15 ^ 0xffffffff) & 1 |
                                 ((uVar13 ^ uVar11 ^ uVar8 ^ 0xffffffff) & 1 |
                                 ((uVar7 ^ uVar8 ^ uVar9 ^ uVar14 ^ uVar12 ^ 0xffffffff) & 1 |
                                 ((uVar17 ^ uVar15 ^ uVar9 ^ uVar14 ^ uVar16 ^ uVar12) & 1 |
                                 ((uVar17 ^ uVar8 ^ uVar15 ^ uVar10 ^ uVar14) & 1 |
                                 ((uVar17 ^ uVar9 ^ uVar8 ^ uVar16) & 1 |
                                 ((uVar13 ^ uVar15 ^ uVar9 ^ uVar14 ^ 0xffffffff) & 1 |
                                 ((uVar18 ^ uVar15 ^ 0xffffffff) & 1) << 1) << 1) << 1) << 1) << 1)
                                 << 1) << 1) << 1) << 1) << 1) << 0xc | 0x800) ^ 0x7fffff;
      goto LAB_00222a94;
    }
    DAT_0025ba14._0_2_ = 0;
  }
  if (param_1 != param_2) {
    memcpy(param_2,param_1,0x60);
    return CONCAT44(param_2,param_1);
  }
LAB_002227f5:
  return CONCAT44(param_2,param_1);
}


// ===== two_tone_test_init @ 00222ab0 (63 bytes)

/* state 0x25BF60; placed before two_tone_test_gen [inference] */

void two_tone_test_init(void)

{
  undefined8 uVar1;
  
  DAT_0025bf6e = 0;
  DAT_0025bf81 = 0;
  DAT_0025bf80 = 0;
  DAT_0025bf6c = 0;
  DAT_0025bf6a = 0;
  DAT_0025bf68 = 0;
  DAT_0025bf60 = 0;
  uVar1 = const_s(1);
  DAT_0025bf64 = ae_s32_l_i(uVar1);
  uVar1 = const_s(0);
  DAT_0025bf70 = ae_s32_l_i(uVar1);
  DAT_0025bf74 = ae_s32_l_i(uVar1);
  DAT_0025bf78 = ae_s32_l_i(uVar1);
  DAT_0025bf7c = ae_s32_l_i(uVar1);
  return;
}


// ===== two_tone_test_gen @ 00222af0 (519 bytes)

/* regs 0x36 0x37 */

void two_tone_test_gen(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 uVar4;
  float fVar5;
  ulonglong in_aed0;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined *puVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  
  memcpy(&DAT_0025bf90,param_1,0x60);
  fVar5 = (float)in_aed0;
  if ((int)(short)DAT_20070022 != (uint)DAT_0025bf60) {
    DAT_0025bf60 = DAT_20070022;
    scl_int2float((int)(short)DAT_20070022,0xffffffff);
    in_aed0 = (ulonglong)(uint)(fVar5 * 0.05);
    scl_antilog10f();
    DAT_0025bf64 = ae_s32_l_i(in_aed0);
  }
  fVar5 = (float)in_aed0;
  if ((uint)DAT_0025bf68 != (uint)DAT_2007006c) {
    DAT_0025bf68 = DAT_2007006c;
    DAT_0025bf80 = DAT_2007006c >> 0xc == 1;
    puVar10 = (undefined *)(DAT_2007006c & 0xfff);
    if ((&DAT_00008c9f < puVar10) || ((DAT_2007006c & 0xfff) != 0)) {
      iVar3 = (uint)(puVar10 < &DAT_00008c9f) * (int)puVar10 +
              (uint)(puVar10 >= &DAT_00008c9f) * (int)&DAT_00008c9f;
    }
    else {
      iVar3 = 1;
    }
    uVar2 = ae_zext16(iVar3);
    scl_int2float(uVar2,0);
    uVar8 = ae_l32_i(0x38b702d4);
    DAT_0025bf78 = ae_s32_l_i((ulonglong)(uint)(fVar5 * (float)uVar8));
  }
  uVar12 = const_s(0);
  uVar8 = 0x40c90fdb;
  uVar7 = 0xc0c90fdb;
  if (DAT_0025bf80 != '\0') {
    puVar1 = &DAT_0025bf90;
    do {
      uVar9 = ae_l32_i(DAT_0025bf78);
      uVar11 = ae_l32_i(DAT_0025bf70);
      uVar6 = (ulonglong)(uint)((float)uVar11 + (float)uVar9);
      uVar4 = olt_s(uVar8,uVar6);
      DAT_0025bf70 = ae_s32_l_i(uVar6);
      if (SUB21(uVar4,0)) {
        do {
          uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar7);
          uVar4 = olt_s(uVar8,uVar6);
          DAT_0025bf70 = ae_s32_l_i(uVar6);
        } while (SUB21(uVar4,0));
      }
      uVar4 = olt_s(uVar6,uVar12);
      if (SUB21(uVar4,0)) {
        do {
          uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar8);
          uVar4 = olt_s(uVar6,uVar12);
          DAT_0025bf70 = ae_s32_l_i(uVar6);
        } while (SUB21(uVar4,0));
      }
      fVar5 = (float)uVar6;
      scl_cosinef();
      uVar7 = ae_l32_i(DAT_0025bf64);
      uVar12 = ae_l32_i(*puVar1);
      uVar8 = ae_l32_i(0x40c90fdb);
      uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar12 + (float)uVar7 * fVar5));
      *puVar1 = uVar2;
      puVar1 = puVar1 + 1;
      uVar12 = ae_l32_i(0);
      uVar7 = ae_l32_i(0xc0c90fdb);
    } while (puVar1 != &DAT_0025bff0);
  }
  if ((uint)DAT_0025bf6a != (uint)DAT_2007006e) {
    DAT_0025bf6a = DAT_2007006e;
    DAT_0025bf81 = DAT_2007006e >> 0xc == 1;
    puVar10 = (undefined *)(DAT_2007006e & 0xfff);
    if ((&DAT_00008c9f < puVar10) || ((DAT_2007006e & 0xfff) != 0)) {
      iVar3 = (uint)(puVar10 < &DAT_00008c9f) * (int)puVar10 +
              (uint)(puVar10 >= &DAT_00008c9f) * (int)&DAT_00008c9f;
    }
    else {
      iVar3 = 1;
    }
    uVar2 = ae_zext16(iVar3);
    scl_int2float(uVar2,0);
    uVar7 = ae_l32_i(0x38b702d4);
    uVar8 = ae_l32_i(0x40c90fdb);
    uVar12 = ae_l32_i(0);
    DAT_0025bf7c = ae_s32_l_i((ulonglong)(uint)(fVar5 * (float)uVar7));
    uVar7 = ae_l32_i(0xc0c90fdb);
  }
  if (DAT_0025bf81 != '\0') {
    puVar1 = &DAT_0025bf90;
    do {
      uVar9 = ae_l32_i(DAT_0025bf7c);
      uVar11 = ae_l32_i(DAT_0025bf74);
      uVar6 = (ulonglong)(uint)((float)uVar11 + (float)uVar9);
      uVar4 = olt_s(uVar8,uVar6);
      DAT_0025bf74 = ae_s32_l_i(uVar6);
      if (SUB21(uVar4,0)) {
        do {
          uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar7);
          uVar4 = olt_s(uVar8,uVar6);
          DAT_0025bf74 = ae_s32_l_i(uVar6);
        } while (SUB21(uVar4,0));
      }
      uVar4 = olt_s(uVar6,uVar12);
      if (SUB21(uVar4,0)) {
        do {
          uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar8);
          uVar4 = olt_s(uVar6,uVar12);
          DAT_0025bf74 = ae_s32_l_i(uVar6);
        } while (SUB21(uVar4,0));
      }
      fVar5 = (float)uVar6;
      scl_cosinef();
      uVar12 = ae_l32_i(DAT_0025bf64);
      uVar7 = ae_l32_i(*puVar1);
      uVar8 = ae_l32_i(0x40c90fdb);
      uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 + (float)uVar12 * fVar5));
      *puVar1 = uVar2;
      puVar1 = puVar1 + 1;
      uVar12 = ae_l32_i(0);
      uVar7 = ae_l32_i(0xc0c90fdb);
    } while (puVar1 != &DAT_0025bff0);
  }
  memcpy(param_2,&DAT_0025bf90,0x60);
  return;
}


// ===== fm_tx_audio_init @ 00222d00 (52 bytes)

/* gain from reg via scl_int2float, then fm_tx_hpf_init; placed before fm_tx_audio [inference] */

void fm_tx_audio_init(void)

{
  float in_aed0;
  
  fm_tx_hpf_init();
  DAT_0025bff4 = DAT_20070060;
  scl_int2float(DAT_20070060 & 0xff,0);
  DAT_0025bffc = 0xffff;
  DAT_0025bffe = 0;
  DAT_0025bff8 = ae_s32_l_i((ulonglong)(uint)(in_aed0 * 0.003921569));
  return;
}


// ===== fm_tx_audio @ 00222d34 (157 bytes)

/* HPF 293 Hz, gain reg 0x30, pre-emphasis reg 0x3A */

void fm_tx_audio(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  undefined8 uVar2;
  
  fm_tx_hpf_process(param_1,&DAT_0025c010);
  uVar2 = ae_l32_i(DAT_0025bff8);
  fVar1 = (float)uVar2;
  if (DAT_0025bff4 != DAT_20070060) {
    DAT_0025bff4 = DAT_20070060;
    scl_int2float(DAT_20070060 & 0xff,0);
    DAT_0025bff8 = ae_s32_l_i((ulonglong)(uint)(fVar1 * 0.003921569));
  }
  vec_scalef(&DAT_0025c020,&DAT_0025c010,4);
  if (DAT_0025bffc != DAT_20070074) {
    DAT_0025bffc = DAT_20070074;
    DAT_0025bffe = DAT_20070074 & 1;
    if ((DAT_20070074 & 1) != 0) {
      DAT_0025c000 = iir_cascade_init(&DAT_0025c0d0,8,&DAT_00237240,3);
    }
  }
  if (DAT_0025bffe != 0) {
    iir_cascade_process(DAT_0025c000,param_2,&DAT_0025c020,4);
    return;
  }
  memcpy(param_2,&DAT_0025c020,0x10);
  return;
}


// ===== fm_tx_hpf_init @ 00222dd4 (25 bytes)

/* iir_cascade_init(0x25C030, coefficients 0x2371F0) [inference] */

void fm_tx_hpf_init(void)

{
  DAT_0025bff0 = iir_cascade_init(&DAT_0025c030,4,&DAT_002371f0,1);
  return;
}


// ===== fm_tx_hpf_process @ 00222df0 (23 bytes)

/* iir_cascade_process on 0x25BFF0; called by fm_tx_audio (HPF 293 Hz) [inference] */

void fm_tx_hpf_process(undefined4 param_1,undefined4 param_2)

{
  iir_cascade_process(DAT_0025bff0,param_2,param_1,4);
  return;
}


// ===== soft_knee_limiter_init @ 00222e10 (31 bytes)

/* memset 0x25C1F0; placed before soft_knee_limiter [inference] */

void soft_knee_limiter_init(void)

{
  undefined8 uVar1;
  
  memset(&DAT_0025c1f0,0,0x34);
  uVar1 = const_s(1);
  DAT_0025c1fc = ae_s32_l_i(uVar1);
  DAT_0025c200 = ae_s32_l_i(uVar1);
  DAT_0025c204 = ae_s32_l_i(uVar1);
  return;
}


// ===== soft_knee_limiter @ 00222e30 (574 bytes)

/* regs 0x4015-0x4019 (off by default) */

void soft_knee_limiter(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  float fVar3;
  undefined8 in_aed0;
  undefined8 uVar4;
  float fVar5;
  float fVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  
  uVar8 = (uint)DAT_2007802a;
  if (DAT_0025c1f0 != uVar8) {
    DAT_0025c1f0 = DAT_2007802a;
    DAT_0025c1fa = DAT_2007802a >> 0xc & 1;
    uVar10 = uVar8 & 0xfff;
    if ((DAT_2007802a >> 0xb & 1) != 0) {
      uVar10 = uVar8 | 0xfffff000;
    }
    scl_int2float(uVar10,0xffffffff);
    uVar4 = ae_l32_i(DAT_0025c200);
    DAT_0025c1fc = ae_s32_l_i(in_aed0);
    DAT_0025c204 = ae_s32_l_i((ulonglong)(uint)((float)uVar4 + (float)in_aed0));
  }
  if ((uint)DAT_0025c1f2 != (uint)DAT_2007802c) {
    DAT_0025c1f2 = DAT_2007802c;
    scl_int2float(DAT_2007802c | 0xfffff000,0xffffffff);
    uVar4 = ae_l32_i(DAT_0025c1fc);
    DAT_0025c200 = ae_s32_l_i(in_aed0);
    DAT_0025c204 = ae_s32_l_i((ulonglong)(uint)((float)uVar4 + (float)in_aed0));
  }
  if (DAT_0025c1f4 != DAT_20078032) {
    DAT_0025c1f4 = DAT_20078032;
    scl_int2float(DAT_20078032,0);
    uVar4 = const_s(3);
    DAT_0025c208 = ae_s32_l_i(in_aed0);
    uVar7 = ae_l32_i(0);
    uVar2 = oeq_s(in_aed0,uVar7);
    DAT_0025c20c = ae_s32_l_i((ulonglong)(uint)((float)in_aed0 * (float)uVar4));
    if (SUB21(uVar2,0)) {
      in_aed0 = 0x40a00000;
    }
    else {
      const_s(2);
      in_aed0 = ae_l32_i(0x3f800000);
      __divsf3();
    }
    DAT_0025c210 = ae_s32_l_i(in_aed0);
  }
  if (DAT_0025c1f6 != DAT_2007802e) {
    DAT_0025c1f6 = DAT_2007802e;
    scl_int2float(DAT_2007802e,0);
    uVar7 = ae_l32_i(0x3a83126f);
    uVar4 = ae_l32_i(0);
    uVar2 = oeq_s((ulonglong)(uint)((float)in_aed0 * (float)uVar7),uVar4);
    if (SUB21(uVar2,0)) {
      DAT_0025c214 = ae_s32_l_i(uVar4);
    }
    else {
      ae_l32_i(0x463b8000);
      in_aed0 = ae_l32_i(0xc00c9f54);
      __divsf3();
      scl_antilognf();
      DAT_0025c214 = ae_s32_l_i(in_aed0);
    }
  }
  fVar3 = (float)in_aed0;
  if (DAT_0025c1f8 != DAT_20078030) {
    DAT_0025c1f8 = DAT_20078030;
    scl_int2float(DAT_20078030,0);
    uVar7 = ae_l32_i(0x3a83126f);
    uVar4 = ae_l32_i(0);
    uVar2 = oeq_s((ulonglong)(uint)(fVar3 * (float)uVar7),uVar4);
    uVar4 = ae_l32_i(0);
    if (SUB21(uVar2,0)) {
      DAT_0025c218 = ae_s32_l_i(uVar4);
    }
    else {
      ae_l32_i(0x463b8000);
      uVar4 = ae_l32_i(0xc00c9f54);
      __divsf3();
      scl_antilognf();
      DAT_0025c218 = ae_s32_l_i(uVar4);
    }
  }
  iVar9 = 4;
  if (DAT_0025c1fa == 0) {
    if (param_1 != param_2) {
      memcpy(param_2,param_1,0x10);
      return;
    }
  }
  else {
    do {
      uVar4 = ae_l32_i(*param_1);
      uVar7 = ae_l32_i(0x358637bd);
      uVar2 = olt_s(uVar7,(ulonglong)(uint)ABS((float)uVar4));
      uVar4 = movf_s((ulonglong)(uint)ABS((float)uVar4),uVar7,(char)uVar2);
      fVar3 = (float)uVar4;
      scl_log10f();
      uVar7 = ae_l32_i(DAT_0025c20c);
      uVar11 = ae_l32_i(DAT_0025c204);
      uVar4 = ae_l32_i(0x41a00000);
      fVar5 = (float)uVar11;
      fVar6 = (float)uVar7;
      fVar3 = fVar3 * (float)uVar4;
      uVar12 = (ulonglong)(uint)fVar3;
      uVar2 = olt_s(uVar12,(ulonglong)(uint)(fVar5 - fVar6));
      if (SUB21(uVar2,0)) {
        uVar4 = ae_mov(uVar12);
        fVar5 = (float)uVar4;
      }
      else {
        uVar2 = ole_s((ulonglong)(uint)(fVar5 + fVar6),uVar12);
        uVar4 = ae_l32_i(DAT_0025c210);
        if (!SUB21(uVar2,0)) {
          fVar6 = fVar6 + (fVar3 - fVar5);
          fVar5 = fVar3 - (float)uVar4 * fVar6 * fVar6;
        }
      }
      uVar7 = ae_l32_i(DAT_0025c220);
      uVar2 = ole_s((ulonglong)(uint)(fVar5 - fVar3),uVar7);
      uVar4 = ae_l32_i(DAT_0025c214);
      uVar11 = ae_l32_i(DAT_0025c218);
      uVar4 = movt_s(uVar11,uVar4,(char)uVar2);
      uVar11 = ae_l32_i(0x3f800000);
      fVar3 = (float)uVar4 * (float)uVar7 + (fVar5 - fVar3) * ((float)uVar11 - (float)uVar4);
      uVar4 = ae_l32_i(0x3d4ccccd);
      DAT_0025c220 = ae_s32_l_i((ulonglong)(uint)fVar3);
      fVar3 = fVar3 * (float)uVar4;
      scl_antilog10f();
      uVar4 = ae_l32_ip(*param_1);
      param_1 = param_1 + 1;
      uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar4 * fVar3));
      *param_2 = uVar1;
      param_2 = param_2 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  return;
}


// ===== fm_post_lpf_init @ 00223080 (25 bytes)

/* iir_cascade_init(coefficients 0x2372E0); placed before fm_post_lpf [inference] */

void fm_post_lpf_init(void)

{
  DAT_0025c230 = iir_cascade_init(&DAT_0025c240,2,&DAT_002372e0,1);
  return;
}


// ===== fm_post_lpf @ 0022309c (45 bytes)

/* LP 3 kHz at 72 kHz, reg 0xC bit 8 */

void fm_post_lpf(undefined4 param_1,undefined4 param_2)

{
  if ((DAT_20070018 & 0x100) != 0) {
    memcpy(param_2,param_1,0x60);
    return;
  }
  iir_cascade_process(DAT_0025c230,param_2,param_1,0x18);
  return;
}


// ===== FUN_002230d0 @ 002230d0 (25 bytes)

void FUN_002230d0(void)

{
  DAT_0025c2a0 = iir_cascade_init(&DAT_0025c2b0,4,&DAT_00237310,1);
  return;
}


// ===== FUN_002230ec @ 002230ec (23 bytes)

void FUN_002230ec(undefined4 param_1,undefined4 param_2)

{
  iir_cascade_process(DAT_0025c2a0,param_2,param_1,4);
  return;
}


// ===== tx_chain_init @ 00223110 (26 bytes)

/* tx_core_init, tx_alc_init, fm_post_lpf_init, ctcss/dcs encoder inits, two_tone_test_init; placed
   before tx_chain [inference] */

void tx_chain_init(void)

{
  FUN_0022312c();
  tx_core_init();
  tx_alc_init();
  fm_post_lpf_init();
  ctcss_encoder_init();
  two_tone_test_init();
  dcs_encoder_init();
  return;
}


// ===== FUN_0022312c @ 0022312c (13 bytes)

undefined8 FUN_0022312c(void)

{
  ae_s16i_n(&DAT_0000ffff,&DAT_0025c350,0);
  return 0x25c3500000ffff;
}


// ===== tx_chain @ 0022313c (269 bytes)

/* core, ALC, sub-tones, modulators only if reg 0x4006 != 0 */

void tx_chain(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  
  memcpy(&DAT_0025c360,param_1,0x60);
  tx_core_12k(&DAT_0025c360,&DAT_0025c360);
  tx_alc(&DAT_0025c360,&DAT_0025c3c0);
  if (DAT_2007000c == 9) {
    fm_post_lpf(&DAT_0025c3c0,&DAT_0025c360);
  }
  else {
    memcpy(&DAT_0025c360,&DAT_0025c3c0,0x60);
  }
  memcpy(param_2,&DAT_0025c360,0x60);
  ctcss_encoder(&DAT_0025c360,&DAT_0025c420);
  two_tone_test_gen(&DAT_0025c420,&DAT_0025c420);
  dcs_encoder(&DAT_0025c420,&DAT_0025c420);
  memcpy(param_3,&DAT_0025c420,0x60);
  sVar1 = DAT_0025c350;
  if (DAT_2007800c != 0) {
    DAT_0025c350 = DAT_2007000c;
    iVar2 = 0xb;
    if (sVar1 != DAT_2007000c) {
      iVar2 = 1;
    }
    switch(DAT_2007000c) {
    case 0:
    case 2:
    case 4:
    case 6:
      if (iVar2 != 0) {
        weaver_ssb_mod_init(0);
      }
      weaver_ssb_mod(&DAT_0025c420,&DAT_0025c420);
      break;
    case 1:
    case 3:
    case 5:
    case 7:
      if (iVar2 != 0) {
        weaver_ssb_mod_init();
      }
      weaver_ssb_mod(&DAT_0025c420,&DAT_0025c420);
      break;
    case 8:
      if (iVar2 != 0) {
        am_modulator_init();
      }
      am_modulator(&DAT_0025c420,&DAT_0025c420);
      break;
    case 9:
      if (iVar2 != 0) {
        fm_modulator_init();
      }
      fm_modulator(&DAT_0025c420,&DAT_0025c420);
    }
  }
  memcpy(param_3,&DAT_0025c420,0x60);
  return;
}


// ===== nlms_51tap_update @ 00223250 (207 bytes)

undefined4 *
nlms_51tap_update(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  undefined8 in_aed0;
  ulonglong uVar5;
  undefined8 in_aed1;
  undefined2 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  
  uVar4 = ae_s32_l_i(in_aed1);
  uVar1 = ae_s32_l_i(in_aed0);
  puVar7 = param_5 + 8;
  iVar10 = 0;
  uVar11 = ae_l32_i(0);
  iVar9 = param_1;
  do {
    uVar12 = ae_l32_i(0);
    uVar2 = ae_s32_l_i(uVar12);
    *param_5 = uVar2;
    puVar8 = (undefined4 *)(iVar10 + param_1);
    uVar12 = ae_l32_ip(*param_2);
    uVar13 = ae_l32_ip(*puVar8);
    fVar3 = (float)uVar13 * (float)uVar12;
    uVar5 = (ulonglong)(uint)fVar3;
    fVar3 = (float)uVar11 + fVar3;
    uVar2 = ae_s32_l_i((ulonglong)(uint)fVar3);
    *param_5 = uVar2;
    uVar11 = ae_l32_i(*param_3);
    uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar11 - fVar3));
    *param_4 = uVar2;
    vec_powerf(iVar9,0x33);
    uVar12 = ae_l32_i(0x2b8cbccc);
    uVar6 = olt_s(uVar5,uVar12);
    uVar14 = ae_l32_i(uVar1);
    uVar11 = ae_l32_i(*param_4);
    uVar13 = ae_mov(uVar5);
    uVar5 = (ulonglong)(uint)((float)uVar11 * (float)uVar14);
    movt_s(uVar13,uVar12,(char)uVar6);
    __divsf3();
    uVar12 = ae_l32_i(uVar4);
    uVar14 = ae_mov(uVar5);
    uVar11 = ae_l32_ip(*puVar8);
    uVar13 = ae_l32_i(*param_2);
    uVar2 = ae_s32_l_ip((ulonglong)
                        (uint)((float)uVar11 * (float)uVar14 + (float)uVar13 * (float)uVar12));
    *param_2 = uVar2;
    param_3 = param_3 + 1;
    param_4 = param_4 + 1;
    iVar9 = iVar9 + 4;
    param_5 = param_5 + 1;
    iVar10 = iVar10 + 4;
    uVar11 = ae_l32_i(0);
  } while (param_5 != puVar7);
  return puVar8 + 1;
}


// ===== vox_detector_init @ 00223320 (108 bytes)

/* memset, LP 0x237360 (docs: vox_detector +0x223320) [inference] */

void vox_detector_init(void)

{
  undefined8 uVar1;
  
  memset(&DAT_0025c480,0,0x304);
  DAT_0025c480 = &DAT_20070042;
  DAT_0025c484 = &DAT_20078010;
  DAT_0025c4b4 = iir_cascade_init(&DAT_0025ca90,3,&DAT_00237360,1);
  DAT_0025c4b8 = iir_cascade_init(&DAT_0025cb90,3,&DAT_00237360,1);
  DAT_0025c4a8 = &DAT_0025cc90;
  DAT_0025c4ac = &DAT_0025cdb0;
  DAT_0025c4b0 = &DAT_0025d110;
  memset(&DAT_0025d110,0,0x120);
  uVar1 = const_s(1);
  DAT_0025c780 = ae_s32_l_i(uVar1);
  return;
}


// ===== antivox_detector_init @ 0022338c (109 bytes)

/* memset, LP 0x237360 (docs: antivox_detector +0x22338C) [inference] */

void antivox_detector_init(void)

{
  undefined8 uVar1;
  
  memset(&DAT_0025c784,0,0x304);
  DAT_0025c784 = &DAT_20070044;
  DAT_0025c788 = &DAT_20078012;
  DAT_0025c7b8 = iir_cascade_init(&DAT_0025cb10,3,&DAT_00237360,1);
  DAT_0025c7bc = iir_cascade_init(&DAT_0025cc10,3,&DAT_00237360,1);
  DAT_0025c7ac = &DAT_0025ced0;
  DAT_0025c7b0 = &DAT_0025cff0;
  DAT_0025c7b4 = &DAT_0025d230;
  memset(&DAT_0025d230,0,0x120);
  uVar1 = const_s(1);
  DAT_0025ca84 = ae_s32_l_i(uVar1);
  return;
}


// ===== vox_detector @ 002233fc (820 bytes)

/* ch0, threshold reg 0x21, 20 ms level, 100 ms hang; with reg 0xC bit 0 the NLMS gets raw 72 kHz
   samples (bundle 0x2234BC, bug, #184) */

undefined8 vox_detector(undefined4 *param_1,undefined4 *param_2)

{
  short sVar1;
  undefined6 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  undefined8 in_aed0;
  ulonglong uVar10;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined2 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  sVar1 = *DAT_0025c480;
  if ((int)DAT_0025c48e != (int)sVar1) {
    DAT_0025c48e = sVar1;
    scl_int2float((int)sVar1,0xffffffff);
    DAT_0025c490 = ae_s32_l_i(in_aed0);
  }
  fVar9 = (float)in_aed0;
  if (DAT_0025c488 != (DAT_20070018 & 0xf)) {
    DAT_0025c498 = DAT_20070018 & 1;
    DAT_0025c488 = DAT_20070018 & 0xf;
    memset(&DAT_0025c670,0,0xcc);
    memset(&DAT_0025c4bc,0,0x1b4);
  }
  sVar1 = DAT_20078022;
  if (DAT_0025c48a != DAT_20078022) {
    DAT_0025c48a = DAT_20078022;
    scl_int2float(DAT_20078022,0);
    uVar10 = 0x3fe66666;
    uVar11 = olt_s(0x3fe66666,(ulonglong)(uint)(fVar9 * 0.001));
    if (!SUB21(uVar11,0)) {
      scl_int2float(sVar1,0);
      uVar12 = ae_l32_i(0x3a83126f);
      uVar10 = (ulonglong)(uint)(fVar9 * (float)uVar12);
    }
    DAT_0025c77c = ae_s32_l_i(uVar10);
    memset(&DAT_0025c670,0,0xcc);
    memset(&DAT_0025c4bc,0,0x1b4);
  }
  if (DAT_0025c48c != DAT_20078024) {
    DAT_0025c48c = DAT_20078024;
    scl_int2float(DAT_20078024,0);
    uVar12 = const_s(1);
    DAT_0025c780 = ae_s32_l_i((ulonglong)(uint)(fVar9 * -1e-06 + (float)uVar12));
    memset(&DAT_0025c670,0,0xcc);
    memset(&DAT_0025c4bc,0,0x1b4);
  }
  if (param_2 != (undefined4 *)0x0) {
    memcpy(param_2,(uint)DAT_0025c4a6 * 4 + DAT_0025c4b0,0x60);
  }
  memcpy(DAT_0025c4a8 + DAT_0025c4a6,param_1,0x60);
  uVar8 = ae_zext16(DAT_0025c4a6 + 0x18);
  DAT_0025c4a6 = (ushort)uVar8;
  if (0x47 < uVar8) {
    DAT_0025c4a6 = 0;
    iir_cascade_process(DAT_0025c4b4,DAT_0025c4ac,DAT_0025c4a8,0x48);
    uVar12 = ae_l32_i(*DAT_0025c4ac);
    uVar5 = ae_s32_l_ip(uVar12);
    *DAT_0025c4a8 = uVar5;
    uVar12 = ae_l32_i(DAT_0025c49c);
    if (DAT_0025c498 == 0) {
      uVar13 = ae_l32_ip(*DAT_0025c4a8);
      DAT_0025c49c = ae_s32_l_i((ulonglong)(uint)((float)uVar12 + ABS((float)uVar13)));
    }
    else {
      memcpy(0x25c650,param_1,0x20);
      ae_l32_i(DAT_0025c77c);
      ae_l32_i(DAT_0025c780);
      nlms_51tap_update(&DAT_0025c4bc,&DAT_0025c670,0x25c650,0x25c73c,&DAT_0025c75c);
      uVar12 = ae_l32_ip(DAT_0025c4dc);
      DAT_0025c4bc = ae_s32_l_ip(uVar12);
      memcpy(DAT_0025c4a8,&DAT_0025c75c,0x20);
      uVar13 = ae_l32_i(DAT_0025c49c);
      uVar12 = ae_l32_ip(DAT_0025c75c);
      param_1 = (undefined4 *)&DAT_0025c760;
      DAT_0025c49c = ae_s32_l_i((ulonglong)(uint)((float)uVar13 + ABS((float)uVar12)));
    }
    puVar4 = DAT_0025c4ac;
    puVar3 = DAT_0025c4a8;
    uVar5 = 8;
    if (param_2 != (undefined4 *)0x0) {
      memset(DAT_0025c4ac,0,0x120);
      uVar12 = ae_l32_ip(*puVar3);
      param_2 = puVar3 + 1;
      uVar5 = ae_s32_l_i((ulonglong)(uint)((float)uVar12 * 9.0));
      *puVar4 = uVar5;
      param_1 = puVar4 + 9;
      uVar5 = iir_cascade_process(DAT_0025c4b8,DAT_0025c4b0,DAT_0025c4ac,0x48);
    }
    uVar8 = ae_zext16(DAT_0025c4a0 + 8);
    DAT_0025c4a0 = (ushort)uVar8;
    if (0x9f < uVar8) {
      uVar12 = ae_l32_i(DAT_0025c49c);
      fVar9 = (float)uVar12 * 0.00625;
      scl_log10f(uVar5);
      DAT_0025c4a0 = 0;
      uVar12 = ae_l32_i(DAT_0025c490);
      uVar11 = olt_s(uVar12,(ulonglong)(uint)(fVar9 * 20.0));
      uVar12 = const_s(0);
      DAT_0025c49c = ae_s32_l_i(uVar12);
      DAT_0025c494 = ae_s32_l_i((ulonglong)(uint)(fVar9 * 20.0));
      if (SUB21(uVar11,0)) {
        DAT_0025c4a4 = 1;
        DAT_0025c4a2 = 5;
      }
      else {
        if (DAT_0025c4a2 == 0) {
          DAT_0025c4a4 = 0;
        }
        else {
          DAT_0025c4a2 = DAT_0025c4a2 + -1;
        }
        ae_l32_i(DAT_0025c494);
      }
      uVar5 = scl_float2int(0xffffffff);
      ae_s16i_n(uVar5,DAT_0025c484,0);
      iVar6 = vox_state();
      DAT_20078014 = DAT_0025c4a4 | DAT_0025c7a8 << 1 | (ushort)(iVar6 << 2);
      uVar7 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,
                     in_st_PSINTLEVEL);
      uVar8 = uVar7 & 0xf;
      if (uVar8 < 2) {
        uVar2 = wsr_ps(uVar7 & 0xfffffff0 | 2);
        rsync();
        DAT_20070002 = (ushort)(iVar6 << 4) | DAT_20070002 & 0xffef;
        uVar7 = rsr_ps((char)uVar2,(char)((uint6)uVar2 >> 8),(char)((uint6)uVar2 >> 0x10),
                       (char)((uint6)uVar2 >> 0x18),(char)((uint6)uVar2 >> 0x20),
                       (char)((uint6)uVar2 >> 0x28));
        wsr_ps(uVar8 | uVar7 & 0xfffffff0);
        rsync();
        return CONCAT44(param_2,param_1);
      }
      DAT_20070002 = (ushort)(iVar6 << 4) | DAT_20070002 & 0xffef;
      uVar7 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,
                     in_st_PSINTLEVEL);
      wsr_ps(uVar8 | uVar7 & 0xfffffff0);
      rsync();
      return CONCAT44(param_2,param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}


// ===== antivox_detector @ 00223734 (823 bytes)

/* ch1, threshold reg 0x22; reg 0x400A, reg 1 bit 4; same raw-sample NLMS bug at 0x2237F4 (#184) */

undefined8 antivox_detector(undefined4 *param_1,undefined4 *param_2)

{
  short sVar1;
  undefined6 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  undefined8 in_aed0;
  ulonglong uVar10;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined2 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  sVar1 = *DAT_0025c784;
  if ((int)DAT_0025c792 != (int)sVar1) {
    DAT_0025c792 = sVar1;
    scl_int2float((int)sVar1,0xffffffff);
    DAT_0025c794 = ae_s32_l_i(in_aed0);
  }
  fVar9 = (float)in_aed0;
  if (DAT_0025c78c != (DAT_20070018 & 0xf)) {
    DAT_0025c79c = DAT_20070018 & 1;
    DAT_0025c78c = DAT_20070018 & 0xf;
    memset(&DAT_0025c974,0,0xcc);
    memset(&DAT_0025c7c0,0,0x1b4);
  }
  sVar1 = DAT_20078022;
  if (DAT_0025c78e != DAT_20078022) {
    DAT_0025c78e = DAT_20078022;
    scl_int2float(DAT_20078022,0);
    uVar10 = 0x3fe66666;
    uVar11 = olt_s(0x3fe66666,(ulonglong)(uint)(fVar9 * 0.001));
    if (!SUB21(uVar11,0)) {
      scl_int2float(sVar1,0);
      uVar12 = ae_l32_i(0x3a83126f);
      uVar10 = (ulonglong)(uint)(fVar9 * (float)uVar12);
    }
    DAT_0025ca80 = ae_s32_l_i(uVar10);
    memset(&DAT_0025c974,0,0xcc);
    memset(&DAT_0025c7c0,0,0x1b4);
  }
  if (DAT_0025c790 != DAT_20078024) {
    DAT_0025c790 = DAT_20078024;
    scl_int2float(DAT_20078024,0);
    uVar12 = const_s(1);
    DAT_0025ca84 = ae_s32_l_i((ulonglong)(uint)(fVar9 * -1e-06 + (float)uVar12));
    memset(&DAT_0025c974,0,0xcc);
    memset(&DAT_0025c7c0,0,0x1b4);
  }
  if (param_2 != (undefined4 *)0x0) {
    memcpy(param_2,(uint)DAT_0025c7aa * 4 + DAT_0025c7b4,0x60);
  }
  memcpy(DAT_0025c7ac + DAT_0025c7aa,param_1,0x60);
  uVar8 = ae_zext16(DAT_0025c7aa + 0x18);
  DAT_0025c7aa = (ushort)uVar8;
  if (0x47 < uVar8) {
    DAT_0025c7aa = 0;
    iir_cascade_process(DAT_0025c7b8,DAT_0025c7b0,DAT_0025c7ac,0x48);
    uVar12 = ae_l32_i(*DAT_0025c7b0);
    uVar5 = ae_s32_l_ip(uVar12);
    *DAT_0025c7ac = uVar5;
    uVar12 = ae_l32_i(DAT_0025c7a0);
    if (DAT_0025c79c == 0) {
      uVar13 = ae_l32_ip(*DAT_0025c7ac);
      DAT_0025c7a0 = ae_s32_l_i((ulonglong)(uint)((float)uVar12 + ABS((float)uVar13)));
    }
    else {
      memcpy(0x25c954,param_1,0x20);
      ae_l32_i(DAT_0025ca80);
      ae_l32_i(DAT_0025ca84);
      nlms_51tap_update(&DAT_0025c7c0,&DAT_0025c974,0x25c954,0x25ca40,&DAT_0025ca60);
      uVar12 = ae_l32_ip(DAT_0025c7e0);
      DAT_0025c7c0 = ae_s32_l_ip(uVar12);
      memcpy(DAT_0025c7ac,&DAT_0025ca60,0x20);
      uVar13 = ae_l32_i(DAT_0025c7a0);
      uVar12 = ae_l32_ip(DAT_0025ca60);
      param_1 = (undefined4 *)&DAT_0025ca64;
      DAT_0025c7a0 = ae_s32_l_i((ulonglong)(uint)((float)uVar13 + ABS((float)uVar12)));
    }
    puVar4 = DAT_0025c7b0;
    puVar3 = DAT_0025c7ac;
    uVar5 = 8;
    if (param_2 != (undefined4 *)0x0) {
      memset(DAT_0025c7b0,0,0x120);
      uVar12 = ae_l32_ip(*puVar3);
      param_2 = puVar3 + 1;
      uVar5 = ae_s32_l_i((ulonglong)(uint)((float)uVar12 * 9.0));
      *puVar4 = uVar5;
      param_1 = puVar4 + 9;
      uVar5 = iir_cascade_process(DAT_0025c7bc,DAT_0025c7b4,DAT_0025c7b0,0x48);
    }
    uVar8 = ae_zext16(DAT_0025c7a4 + 8);
    DAT_0025c7a4 = (ushort)uVar8;
    if (0x9f < uVar8) {
      uVar12 = ae_l32_i(DAT_0025c7a0);
      fVar9 = (float)uVar12 * 0.00625;
      scl_log10f(uVar5);
      DAT_0025c7a4 = 0;
      uVar12 = ae_l32_i(DAT_0025c794);
      uVar11 = olt_s(uVar12,(ulonglong)(uint)(fVar9 * 20.0));
      uVar12 = const_s(0);
      DAT_0025c7a0 = ae_s32_l_i(uVar12);
      DAT_0025c798 = ae_s32_l_i((ulonglong)(uint)(fVar9 * 20.0));
      if (SUB21(uVar11,0)) {
        DAT_0025c7a8 = 1;
        DAT_0025c7a6 = 5;
      }
      else {
        if (DAT_0025c7a6 == 0) {
          DAT_0025c7a8 = 0;
        }
        else {
          DAT_0025c7a6 = DAT_0025c7a6 + -1;
        }
        ae_l32_i(DAT_0025c798);
      }
      uVar5 = scl_float2int(0xffffffff);
      ae_s16i_n(uVar5,DAT_0025c788,0);
      iVar6 = vox_state();
      DAT_20078014 = DAT_0025c4a4 | DAT_0025c7a8 << 1 | (ushort)(iVar6 << 2);
      uVar7 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,
                     in_st_PSINTLEVEL);
      uVar8 = uVar7 & 0xf;
      if (uVar8 < 2) {
        uVar2 = wsr_ps(uVar7 & 0xfffffff0 | 2);
        rsync();
        DAT_20070002 = (ushort)(iVar6 << 4) | DAT_20070002 & 0xffef;
        uVar7 = rsr_ps((char)uVar2,(char)((uint6)uVar2 >> 8),(char)((uint6)uVar2 >> 0x10),
                       (char)((uint6)uVar2 >> 0x18),(char)((uint6)uVar2 >> 0x20),
                       (char)((uint6)uVar2 >> 0x28));
        wsr_ps(uVar8 | uVar7 & 0xfffffff0);
        rsync();
        return CONCAT44(param_2,&DAT_0025c780);
      }
      DAT_20070002 = (ushort)(iVar6 << 4) | DAT_20070002 & 0xffef;
      uVar7 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,
                     in_st_PSINTLEVEL);
      wsr_ps(uVar8 | uVar7 & 0xfffffff0);
      rsync();
      return CONCAT44(param_2,&DAT_0025c780);
    }
  }
  return CONCAT44(param_2,param_1);
}


// ===== vox_state @ 00223a74 (28 bytes)

/* mic and not speaker */

undefined4 vox_state(void)

{
  undefined4 uVar1;
  
  uVar1 = ae_zext16((uint)DAT_0025c4a4 & (DAT_0025c7a8 ^ 0xffffffff));
  return uVar1;
}


// ===== noise_gen_seed @ 00223a90 (34 bytes)

/* srand wrapper [inference] */

void noise_gen_seed(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 in_CCOUNT;
  undefined8 in_aed0;
  undefined8 in_aed1;
  undefined8 uVar2;
  
  uVar1 = ae_s32_l_i(in_aed1);
  param_1[1] = uVar1;
  uVar1 = ae_s32_l_i(in_aed0);
  *param_1 = uVar1;
  uVar2 = const_s(0);
  uVar1 = ae_s32_l_i(uVar2);
  param_1[3] = uVar1;
  param_1[2] = 0;
  uVar1 = rsr_ccount(in_CCOUNT);
  srand(uVar1);
  return;
}


// ===== noise_gen_set_level @ 00223ab4 (38 bytes)

/* 10^(x / 20) with powf, then noise_gen_seed [inference] */

void noise_gen_set_level(undefined4 param_1)

{
  undefined4 uVar1;
  undefined8 in_aed0;
  undefined8 in_aed1;
  
  uVar1 = ae_s32_l_i(in_aed1);
  __divsf3();
  ae_mov(in_aed0);
  powf();
  ae_l32_i(uVar1);
  noise_gen_seed(param_1);
  return;
}


// ===== gaussian_noise_gen @ 00223adc (263 bytes)

/* Box-Muller: rand, scl_lognf, sqrt, scl_cosinef / scl_sinef, 2*pi [inference] */

void gaussian_noise_gen(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  float fVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  if ((param_1[2] & 1) == 0) {
    do {
      uVar2 = rand();
      uVar3 = rand();
      uVar8 = float_s(uVar2,0);
      uVar7 = ae_l32_i(0x30000000);
      uVar6 = (ulonglong)(uint)((float)uVar8 * (float)uVar7);
      uVar7 = ae_l32_i(0x800000);
      uVar4 = ole_s(uVar6,uVar7);
      uVar2 = ae_s32_l_i(uVar6);
    } while (SUB21(uVar4,0));
    uVar7 = ae_l32_i(uVar2);
    fVar5 = (float)uVar7;
    scl_lognf();
    uVar6 = (ulonglong)(uint)(fVar5 * -2.0);
    uVar1 = ae_s32_l_i(uVar6);
    __ieee754_sqrtf();
    uVar4 = oeq_s(uVar6,uVar6);
    uStack_30 = ae_s32_l_i(uVar6);
    if (!SUB21(uVar4,0)) {
      uVar7 = ae_l32_i(uVar1);
      sqrtf();
      uStack_30 = ae_s32_l_i(uVar7);
    }
    uVar8 = float_s(uVar3,0);
    uVar7 = ae_l32_i(0x30000000);
    uVar6 = (ulonglong)(uint)((float)uVar8 * (float)uVar7 * 6.2831855);
    uVar1 = ae_s32_l_i(uVar6);
    scl_cosinef();
    uVar3 = ae_s32_l_i(uVar6);
    uVar7 = ae_l32_i(uVar2);
    fVar5 = (float)uVar7;
    scl_lognf();
    uVar7 = ae_l32_i(0xc0000000);
    uVar6 = (ulonglong)(uint)(fVar5 * (float)uVar7);
    uVar2 = ae_s32_l_i(uVar6);
    __ieee754_sqrtf();
    uVar4 = oeq_s(uVar6,uVar6);
    uStack_2c = ae_s32_l_i(uVar6);
    if (!SUB21(uVar4,0)) {
      uVar7 = ae_l32_i(uVar2);
      sqrtf();
      uStack_2c = ae_s32_l_i(uVar7);
    }
    uVar7 = ae_l32_i(uVar1);
    fVar5 = (float)uVar7;
    scl_sinef();
    uVar7 = ae_l32_i(uStack_2c);
    ae_l32_i(uVar3);
    ae_l32_i(uStack_30);
    uVar9 = ae_l32_i(*param_1);
    uVar8 = ae_l32_i(param_1[1]);
    param_1[2] = param_1[2] + 1;
    uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 + (float)uVar9 * (float)uVar7 * fVar5));
    param_1[3] = uVar2;
    return;
  }
  param_1[2] = param_1[2] + 1;
  ae_l32_i(param_1[3]);
  return;
}


// ===== spectrum_init @ 00223bf0 (153 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* create_Thread_Spi: window with scl_cosinef, buffers 0x25D350 / 0x25DB60 / 0x25EB60 [inference] */

void spectrum_init(void)

{
  undefined4 uVar1;
  int iVar2;
  float fVar3;
  ulonglong in_aed0;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  
  _DAT_0025d350 = 0;
  iVar2 = 0;
  _DAT_0025d354 = 0;
  DAT_0025d358 = 0;
  puVar6 = &DAT_0025d360;
  do {
    fVar3 = (float)in_aed0;
    scl_int2float(iVar2,0);
    uVar5 = ae_l32_i(0x40c90fdb);
    uVar4 = ae_l32_i(0x3b000000);
    in_aed0 = (ulonglong)(uint)(fVar3 * (float)uVar5 * (float)uVar4);
    scl_cosinef();
    uVar5 = ae_l32_i(0xbf000000);
    uVar4 = ae_l32_i(0x3f000000);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)in_aed0 * (float)uVar5 + (float)uVar4));
    *puVar6 = uVar1;
    puVar6 = puVar6 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x200);
  puVar6 = &DAT_0025db60;
  iVar2 = 0;
  do {
    fVar3 = (float)in_aed0;
    scl_int2float(iVar2,0);
    uVar4 = ae_l32_i(0x40c90fdb);
    uVar5 = ae_l32_i(0x3a800000);
    in_aed0 = (ulonglong)(uint)(fVar3 * (float)uVar4 * (float)uVar5);
    scl_cosinef();
    uVar5 = ae_l32_i(0xbf000000);
    uVar4 = ae_l32_i(0x3f000000);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)in_aed0 * (float)uVar5 + (float)uVar4));
    *puVar6 = uVar1;
    puVar6 = puVar6 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x400);
  memset(&DAT_0025eb60,1,200);
  return;
}


// ===== spectrum_frame @ 00223c8c (856 bytes)

/* Thread_Spi: window, fft_realf_ie, fft_spectrumf, vec_log10f, vec_scale_sf (regs 0x5C/0x5D, docs)
   [inference] */

uint spectrum_frame(undefined4 *param_1)

{
  undefined4 uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar3 = (uint)DAT_0025d352;
  uVar4 = (uint)DAT_0025d356;
  if ((uint)DAT_0025d350 != (uint)DAT_200700b8) {
    uVar3 = DAT_200700b8 >> 8 & 0xf;
    if (DAT_200700b8 >> 0xc < 2) {
      uVar4 = DAT_200700b8 & 0xff;
      if (uVar3 < 3) {
        if (((DAT_200700b8 & 0xff) == 0) || (uVar4 - 100 < 0x97)) {
          DAT_0025d350 = DAT_200700b8;
          uVar5 = ae_l32_i(*(undefined4 *)(&DAT_00204f40 + uVar3 * 4));
          sVar2 = (short)uVar4;
          if (DAT_200700b8 >> 0xc == 0) {
            DAT_0025d358 = ae_s32_l_i(uVar5);
            ae_s16i_n(0,&DAT_0025d350,2);
            if ((DAT_200700b8 & 0xff) == 0) {
              DAT_0025d354 = 0;
            }
            else {
              DAT_0025d354 = sVar2 - 100;
            }
            uVar4 = 0;
            goto LAB_00223d26;
          }
          DAT_0025d358 = ae_s32_l_i(uVar5);
          if ((DAT_200700b8 & 0xff) == 0) {
            uVar5 = 1;
          }
          uVar3 = (uint)uVar5;
          ae_s16i_n(uVar3,&DAT_0025d350,2);
          if ((DAT_200700b8 & 0xff) == 0) {
            DAT_0025d354 = 0;
          }
          else {
            DAT_0025d354 = sVar2 - 100;
          }
          uVar4 = 0;
          DAT_0025d356 = 0;
        }
        else {
          uVar3 = (uint)DAT_0025d352;
          uVar4 = (uint)DAT_0025d356;
        }
      }
      else {
        uVar4 = (uint)DAT_0025d356;
        uVar3 = (uint)DAT_0025d352;
      }
    }
    else {
      uVar4 = (uint)DAT_0025d356;
      uVar3 = (uint)DAT_0025d352;
    }
  }
  if (uVar3 == 1) {
    if (3 < uVar4) {
      uVar4 = 0;
      DAT_0025d356 = 0;
    }
    uVar5 = ae_l32_ip(*param_1);
    uVar6 = ae_l32_ip((&DAT_0025d360)[uVar4 * 0x80]);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * (float)uVar5));
    (&DAT_0025ec30)[uVar4 * 0x80] = uVar1;
    uVar6 = ae_l32_ip((&DAT_0025d364)[uVar4 * 0x80]);
    uVar5 = ae_l32_ip(param_1[1]);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * (float)uVar5));
    (&DAT_0025ec34)[uVar4 * 0x80] = uVar1;
    if (uVar4 == 3) {
      fft_realf_ie(&DAT_0025fc30,&DAT_0025ec30,FLOAT_ARRAY_00200d00,1,0x200);
      fft_spectrumf(&DAT_00260c40,&DAT_0025fc30,0x200,1);
      memcpy(&DAT_00261450,&DAT_00260c40 + (uint)DAT_0025d354 * 4,800);
      ae_l32_i(DAT_0025d358);
      ae_l32_i(&RSTCTL0_SYSRSTSTAT);
      vec_scalef(&DAT_00261770,&DAT_00261450,200);
      vec_log10f(&DAT_00261450,&DAT_00261770,200);
      ae_l32_i(0x41a00000);
      ae_l32_i(0xc2fa0000);
      ae_l32_i(0);
      vec_scale_sf(&DAT_00261770,&DAT_00261450,200);
      uVar6 = ae_l32_i(&RSTCTL0_SYSRSTSTAT);
      uVar7 = ae_l32_i(0x42fa0000);
      uVar8 = ae_l32_i(0x3f000000);
      uVar5 = ae_l32_i(DAT_00261770);
      utrunc_s((ulonglong)(uint)(((float)uVar5 + (float)uVar7) * (float)uVar6 + (float)uVar8),0);
      DAT_0025eb60 = 1;
      uVar3 = DAT_0025d356 + 1 & 3;
      DAT_0025d356 = (short)uVar3;
      if (uVar3 == 0) {
        uVar3 = 1;
      }
      return uVar3;
    }
    uVar3 = uVar4 + 1 & 3;
    DAT_0025d356 = (short)uVar3;
    return (uint)(uVar3 == 0);
  }
  if (uVar3 == 2) {
    if (7 < uVar4) {
      uVar4 = 0;
      DAT_0025d356 = 0;
    }
    uVar5 = ae_l32_ip(*param_1);
    uVar6 = ae_l32_ip((&DAT_0025db60)[uVar4 * 0x80]);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * (float)uVar5));
    (&DAT_0025ec30)[uVar4 * 0x80] = uVar1;
    uVar6 = ae_l32_ip((&DAT_0025db64)[uVar4 * 0x80]);
    uVar5 = ae_l32_ip(param_1[1]);
    uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * (float)uVar5));
    (&DAT_0025ec34)[uVar4 * 0x80] = uVar1;
    if (uVar4 == 7) {
      fft_realf_ie(&DAT_0025fc30,&DAT_0025ec30,FLOAT_ARRAY_00201900,1,0x400);
      fft_spectrumf(&DAT_00260c40,&DAT_0025fc30,0x400,1);
      memcpy(&DAT_00261450,&DAT_00260c40 + (uint)DAT_0025d354 * 4,800);
      ae_l32_i(DAT_0025d358);
      ae_l32_i(&RSTCTL0_SYSRSTSTAT);
      vec_scalef(&DAT_00261770,&DAT_00261450,200);
      vec_log10f(&DAT_00261450,&DAT_00261770,200);
      ae_l32_i(0x41a00000);
      ae_l32_i(0xc2fa0000);
      ae_l32_i(0);
      vec_scale_sf(&DAT_00261770,&DAT_00261450,200);
      uVar6 = ae_l32_i(&RSTCTL0_SYSRSTSTAT);
      uVar7 = ae_l32_i(0x42fa0000);
      uVar8 = ae_l32_i(0x3f000000);
      uVar5 = ae_l32_i(DAT_00261770);
      utrunc_s((ulonglong)(uint)(((float)uVar5 + (float)uVar7) * (float)uVar6 + (float)uVar8),0);
      uVar4 = (uint)DAT_0025d356;
      DAT_0025eb60 = 1;
      uVar3 = uVar4 + 1 & 7;
      DAT_0025d356 = (short)uVar3;
      if ((uVar4 + 1 & 3) == 0) {
        uVar3 = 1;
      }
      return uVar3;
    }
    uVar3 = uVar4 + 1 & 7;
    DAT_0025d356 = (short)uVar3;
    if ((uVar4 + 1 & 3) == 0) {
      uVar3 = 1;
    }
    return uVar3;
  }
LAB_00223d26:
  uVar3 = uVar4 + 1 & 3;
  DAT_0025d356 = (ushort)uVar3;
  if (uVar3 == 0) {
    memset(&DAT_0025eb60,1,200);
    return 1;
  }
  return 0;
}


// ===== FUN_00223fe8 @ 00223fe8 (16 bytes)

void FUN_00223fe8(undefined4 param_1)

{
  memcpy(param_1,&DAT_0025eb60,200);
  return;
}


// ===== FUN_00224000 @ 00224000 (94 bytes)

void FUN_00224000(void)

{
  memset(&DAT_00261a90,0,0x348);
  DAT_00261dd8 = bkfiraf_init(&DAT_00261de0,0x7b,FLOAT_ARRAY_00204f80);
  DAT_00261a94 = 0;
  DAT_00261aa4 = 0;
  DAT_00261aa8 = 0;
  DAT_00261aac = 0;
  DAT_00261ab0 = 0;
  DAT_00261dd4 = 2;
  DAT_00261dd5 = 0xfa;
  memset(&DAT_00261ab4,1,400);
  memset(&DAT_00261c44,1,400);
  return;
}


// ===== FUN_00224060 @ 00224060 (313 bytes)

undefined4 FUN_00224060(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar7 = (uint)DAT_200700ba;
  if (DAT_00261a90 != uVar7) {
    uVar8 = DAT_200700ba >> 8 & 0xf;
    if (((DAT_200700ba >> 0xc < 2) && (uVar9 = uVar7 & 0xff, uVar8 < 3)) && (uVar9 < 6)) {
      ae_s16i_n(uVar7,&DAT_00261a90,0);
      DAT_00261a94 = 0;
      DAT_00261aa4 = 0;
      DAT_00261aa8 = 0;
      DAT_00261aac = 0;
      DAT_00261ab0 = 0;
      uVar6 = ae_l32_i(FLOAT_ARRAY_00205170[uVar8]);
      DAT_00261a98 = ae_s32_l_i(uVar6);
      DAT_00261aa0 = *(undefined4 *)(&DAT_00205190 + uVar9 * 4);
      DAT_00261a96 = *(ushort *)((int)&PTR_DAT_00205180 + uVar9 * 2);
      DAT_00261dd4 = 2;
      DAT_00261dd5 = 0xfa;
      DAT_00261a9c = (uint)DAT_00261a96 * 400;
      DAT_00261a92 = DAT_200700ba >> 0xc;
      memset(&DAT_00261ab4,1);
      memset(&DAT_00261c44,1,400);
    }
  }
  iVar5 = ae_l16ui_n(&DAT_00261a90,2);
  if (iVar5 != 0) {
    memset(&DAT_002621e0,0,0xa00);
    uVar6 = ae_l32_ip(*param_1);
    DAT_002621e0 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * 5.0));
    bkfiraf_process(DAT_00261dd8,&DAT_00262be0,&DAT_002621e0,0x280);
    ae_l32_i(DAT_00261a98);
    vec_scale_sf(&DAT_002621e0,&DAT_00262be0,0x280);
    puVar3 = &DAT_002621e0;
    puVar4 = &DAT_002635e0;
    do {
      ae_l32_i(*puVar3);
      ae_l32_i(0x42fc0000);
      uVar1 = scl_float2int(0);
      *puVar4 = uVar1;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (puVar3 != (undefined4 *)&DAT_00262be0);
    if (DAT_00261a96 < 100) {
      uVar2 = FUN_0022419c(&DAT_002635e0);
      return uVar2;
    }
    uVar2 = FUN_0022439c(&DAT_002635e0);
    return uVar2;
  }
  return 0;
}


// ===== FUN_0022419c @ 0022419c (504 bytes)

undefined4 FUN_0022419c(byte *param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  char cVar7;
  char cVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  
  iVar6 = 0;
  uVar4 = 0;
  bVar5 = DAT_00261dd5;
  bVar10 = DAT_00261dd4;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    if (DAT_00261a94 == 0) {
      if (0x7d < bVar1) goto LAB_002241ea;
      DAT_00261a94 = 1;
LAB_002241f0:
      if ((DAT_00261ab0 < DAT_00261a9c) &&
         (DAT_00261ab0 = DAT_00261ab0 + 1, DAT_00261a9c <= DAT_00261ab0)) {
        DAT_00261a94 = 2;
        memset(&DAT_00261ab4,2,400);
        DAT_00261aa8 = 0;
        DAT_00261aa4 = 0;
        bVar10 = 2;
        DAT_00261dd4 = 2;
        bVar5 = 0xfa;
        DAT_00261dd5 = 0xfa;
      }
    }
    else {
      if ((DAT_00261a94 == 1) && (0x7d < bVar1)) {
        DAT_00261a94 = 2;
        memset(&DAT_00261ab4,2,400);
        DAT_00261aa8 = 0;
        DAT_00261aa4 = 0;
        bVar10 = 2;
        DAT_00261dd4 = 2;
        bVar5 = 0xfa;
        DAT_00261dd5 = 0xfa;
      }
LAB_002241ea:
      if (DAT_00261a94 < 2) goto LAB_002241f0;
      DAT_00261ab0 = 0;
    }
    if (DAT_00261a94 == 2) {
      DAT_00261dd4 = bVar10;
      if (bVar10 < bVar1) {
        DAT_00261dd4 = bVar1;
      }
      DAT_00261dd5 = bVar5;
      if (bVar1 < bVar5) {
        DAT_00261dd5 = bVar1;
      }
      DAT_00261aa8 = DAT_00261aa8 + 1;
      bVar10 = DAT_00261dd4;
      bVar5 = DAT_00261dd5;
      if (DAT_00261a96 <= DAT_00261aa8) {
        DAT_00261aa8 = 0;
        (&DAT_00261ab4)[DAT_00261aa4 * 2] = DAT_00261dd4;
        (&DAT_00261ab5)[DAT_00261aa4 * 2] = DAT_00261dd5;
        DAT_00261aa4 = DAT_00261aa4 + 1;
        if (199 < DAT_00261aa4) {
          iVar11 = (uint)DAT_00261ab7 - (uint)DAT_00261ab4;
          if ((uint)DAT_00261ab4 < (uint)DAT_00261ab7) {
            iVar9 = iVar11 + 1;
            if (-1 < iVar11) {
              iVar9 = iVar11;
            }
            DAT_00261ab4 = DAT_00261ab4 + (char)(iVar9 >> 1);
            DAT_00261ab7 = DAT_00261ab4;
          }
          iVar11 = (uint)DAT_00261ab5 - (uint)DAT_00261ab6;
          if ((uint)DAT_00261ab6 < (uint)DAT_00261ab5) {
            iVar9 = iVar11 + 1;
            if (-1 < iVar11) {
              iVar9 = iVar11;
            }
            DAT_00261ab5 = DAT_00261ab6 + (char)(iVar9 >> 1);
            DAT_00261ab6 = DAT_00261ab5;
          }
          cVar2 = -DAT_00261ab4;
          DAT_00261ab4 = -DAT_00261ab5 - 4;
          cVar3 = -DAT_00261ab6;
          DAT_00261ab6 = -DAT_00261ab7 - 4;
          cVar7 = -4 - DAT_00261ab8;
          DAT_00261ab8 = -4 - DAT_00261ab9;
          cVar8 = -4 - DAT_00261aba;
          DAT_00261aba = -4 - DAT_00261abb;
          DAT_00261ab5 = cVar2 - 4;
          DAT_00261ab7 = cVar3 - 4;
          DAT_00261ab9 = cVar7;
          DAT_00261abb = cVar8;
          memcpy(&DAT_00261c44,&DAT_00261ab4,400);
          DAT_00261a94 = 0;
          DAT_00261ab0 = 0;
          uVar4 = 1;
        }
        bVar10 = 2;
        DAT_00261dd4 = 2;
        bVar5 = 0xfa;
        DAT_00261dd5 = 0xfa;
      }
    }
    iVar6 = iVar6 + 1;
    if (iVar6 == 0x280) {
      return uVar4;
    }
  } while( true );
}


// ===== FUN_0022439c @ 0022439c (298 bytes)

undefined4 FUN_0022439c(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  byte *local_30;
  
  iVar6 = 0;
  uVar2 = 0;
  local_30 = param_1;
  do {
    bVar1 = *local_30;
    DAT_00261aa8 = DAT_00261aa8 + 1;
    local_30 = local_30 + 1;
    if (DAT_00261dd4 < bVar1) {
      DAT_00261dd4 = bVar1;
    }
    if (bVar1 < DAT_00261dd5) {
      DAT_00261dd5 = bVar1;
    }
    iVar6 = iVar6 + 1;
    if (DAT_00261a96 <= DAT_00261aa8) {
      DAT_00261aa8 = 0;
      (&DAT_00261ab4)[DAT_00261aa4 * 2] = DAT_00261dd4;
      (&DAT_00261ab5)[DAT_00261aa4 * 2] = DAT_00261dd5;
      DAT_00261aa4 = DAT_00261aa4 + 1;
      DAT_00261aac = DAT_00261aac + 1;
      if (199 < DAT_00261aa4) {
        DAT_00261aa4 = 0;
      }
      if (DAT_00261aa0 <= DAT_00261aac) {
        DAT_00261aac = 0;
        DAT_00261c45 = -4 - (&DAT_00261ab4)[DAT_00261aa4 * 2];
        DAT_00261c44 = -4 - (&DAT_00261ab5)[DAT_00261aa4 * 2];
        cVar3 = -4 - DAT_00261c46;
        DAT_00261c46 = -4 - DAT_00261c47;
        cVar4 = -4 - DAT_00261c48;
        DAT_00261c48 = -4 - DAT_00261c49;
        cVar5 = -4 - DAT_00261c4a;
        DAT_00261c4a = -4 - DAT_00261c4b;
        uVar2 = 1;
        DAT_00261c47 = cVar3;
        DAT_00261c49 = cVar4;
        DAT_00261c4b = cVar5;
      }
      DAT_00261dd4 = 2;
      DAT_00261dd5 = 0xfa;
    }
  } while (iVar6 != 0x280);
  return uVar2;
}


// ===== FUN_002244c8 @ 002244c8 (16 bytes)

void FUN_002244c8(undefined4 param_1)

{
  memcpy(param_1,&DAT_00261c44,400);
  return;
}


// ===== codec_out_init @ 002244e0 (67 bytes)

/* resets both codec-out FIFOs and the mute ramp; placed before codec_out_sink [inference] */

void codec_out_init(void)

{
  undefined8 uVar1;
  
  memset(&DAT_00263870,0,0xc0);
  codec_out_fifo_reset_0();
  codec_out_fifo_reset_1();
  DAT_00263932 = 0;
  DAT_00263930 = 0;
  uVar1 = const_s(1);
  DAT_0026393c = ae_s32_l_i(uVar1);
  DAT_00263938 = ae_s32_l_i(uVar1);
  DAT_00263860 = 0;
  mute_ramp_init(&DAT_00263940);
  mute_ramp_init(&DAT_00263948);
  return;
}


// ===== codec_out_fifo_reset_0 @ 00224524 (110 bytes)

/* clears count / read / write of the FIFO 0x2639F4 under PS.INTLEVEL 2 [fact for the code] */

uint codec_out_fifo_reset_0(uint param_1)

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
  
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar3 = uVar2 & 0xf;
  if (uVar3 < 2) {
    uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 2);
    rsync();
    DAT_00263a12 = 0;
    DAT_00263ad6 = 0;
    DAT_00263a11 = 0;
    DAT_00263ad5 = 0;
    DAT_00263a10 = 0;
    DAT_00263ad4 = 0;
    uVar2 = rsr_ps((char)uVar1,(char)((uint6)uVar1 >> 8),(char)((uint6)uVar1 >> 0x10),
                   (char)((uint6)uVar1 >> 0x18),(char)((uint6)uVar1 >> 0x20),
                   (char)((uint6)uVar1 >> 0x28));
    uVar3 = uVar3 | uVar2 & 0xfffffff0;
    wsr_ps(uVar3);
    rsync();
    return uVar3;
  }
  DAT_00263a12 = 0;
  DAT_00263ad6 = 0;
  DAT_00263a11 = 0;
  DAT_00263ad5 = 0;
  DAT_00263a10 = 0;
  DAT_00263ad4 = 0;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar3 | uVar2 & 0xfffffff0);
  rsync();
  return param_1;
}


// ===== codec_out_fifo_reset_1 @ 00224594 (110 bytes)

/* same for the FIFO 0x263B84 [inference] */

uint codec_out_fifo_reset_1(uint param_1)

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
  
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar3 = uVar2 & 0xf;
  if (uVar3 < 2) {
    uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 2);
    rsync();
    DAT_00263ba2 = 0;
    DAT_00263c66 = 0;
    DAT_00263ba1 = 0;
    DAT_00263c65 = 0;
    DAT_00263ba0 = 0;
    DAT_00263c64 = 0;
    uVar2 = rsr_ps((char)uVar1,(char)((uint6)uVar1 >> 8),(char)((uint6)uVar1 >> 0x10),
                   (char)((uint6)uVar1 >> 0x18),(char)((uint6)uVar1 >> 0x20),
                   (char)((uint6)uVar1 >> 0x28));
    uVar3 = uVar3 | uVar2 & 0xfffffff0;
    wsr_ps(uVar3);
    rsync();
    return uVar3;
  }
  DAT_00263ba2 = 0;
  DAT_00263c66 = 0;
  DAT_00263ba1 = 0;
  DAT_00263c65 = 0;
  DAT_00263ba0 = 0;
  DAT_00263c64 = 0;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar3 | uVar2 & 0xfffffff0);
  rsync();
  return param_1;
}


// ===== codec_out_sink @ 00224604 (186 bytes)

/* per-output gain, clip, into the codec-out object */

void codec_out_sink(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined6 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined8 uVar7;
  undefined8 uVar8;
  
  iVar4 = param_1 * 0xc4;
  if ((byte)(&DAT_00263a10)[iVar4] < 2) {
    uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    if ((uVar5 & 0xf) < 2) {
      uVar2 = wsr_ps(uVar5 & 0xfffffff0 | 2);
      in_st_PSWOE = (undefined1)uVar2;
      in_st_PSCALLINC = (undefined1)((uint6)uVar2 >> 8);
      in_st_PSOWB = (undefined1)((uint6)uVar2 >> 0x10);
      in_st_PSUM = (undefined1)((uint6)uVar2 >> 0x18);
      in_st_PSEXCM = (undefined1)((uint6)uVar2 >> 0x20);
      in_st_PSINTLEVEL = (undefined1)((uint6)uVar2 >> 0x28);
      rsync();
    }
    ae_l32_i((&DAT_00263938)[param_1]);
    const_s(1);
    vec_scale_sf(&DAT_00263c70,param_2,0x18,0xbf800000);
    puVar3 = &DAT_00263c70;
    do {
      uVar7 = ae_l32_i(*(undefined4 *)(&DAT_00263944 + param_1 * 8));
      uVar8 = ae_l32_i(*puVar3);
      uVar1 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * (float)uVar7));
      *puVar3 = uVar1;
      mute_ramp_step(&DAT_00263940 + param_1 * 8);
      puVar3 = puVar3 + 1;
    } while (puVar3 != (undefined4 *)&DAT_00263cd0);
    vec_float2int(&DAT_00263950 + (uint)(byte)(&DAT_00263a11)[iVar4] * 0x60 + iVar4,&DAT_00263c70,
                  0xffffffe1,0x18);
    (&DAT_00263a10)[iVar4] = (&DAT_00263a10)[iVar4] + '\x01';
    (&DAT_00263a11)[iVar4] = (&DAT_00263a11)[iVar4] + 1 & 1;
    uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    wsr_ps(uVar5 & 0xf | uVar6 & 0xfffffff0);
    rsync();
    return;
  }
  return;
}


// ===== codec_out_fill_dma @ 002246c0 (113 bytes)

void codec_out_fill_dma(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = &DAT_00263950;
  puVar2 = &DAT_00263870;
  do {
    if (puVar1[0xc0] == '\0') {
      memset(puVar2,0,0x60);
    }
    else {
      memcpy(puVar2,puVar1 + (uint)(byte)puVar1[0xc2] * 0x60,0x60);
      puVar1[0xc0] = puVar1[0xc0] + -1;
      puVar1[0xc2] = puVar1[0xc2] + 1 & 1;
    }
    puVar1 = puVar1 + 0xc4;
    puVar2 = puVar2 + 0x60;
  } while (puVar1 != &DAT_00263ad8);
  interleave2_u32(param_1,&DAT_00263870,&DAT_002638d0,0x18);
  return;
}


// ===== codec_in_from_dma @ 00224734 (96 bytes)

void codec_in_from_dma(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  deinterleave2_u32(&DAT_00263870,&DAT_002638d0,param_1,0x18);
  puVar2 = &DAT_00263870;
  puVar1 = &DAT_00263ae0;
  do {
    if ((byte)puVar1[0xc0] < 2) {
      memcpy(puVar1 + (uint)(byte)puVar1[0xc1] * 0x60,puVar2,0x60);
      puVar1[0xc0] = puVar1[0xc0] + '\x01';
      puVar1[0xc1] = puVar1[0xc1] + 1 & 1;
    }
    puVar1 = puVar1 + 0xc4;
    puVar2 = puVar2 + 0x60;
  } while (puVar1 != &DAT_00263c68);
  return;
}


// ===== codec_in_fifo_pop @ 00224798 (123 bytes)

/* (ch, dst), Q31 -> float */

void codec_in_fifo_pop(int param_1,undefined4 param_2)

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
  
  param_1 = param_1 * 0xc4;
  if ((&DAT_00263ba0)[param_1] != '\0') {
    uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
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
    vec_int2float(param_2,&DAT_00263ae0 + (uint)(byte)(&DAT_00263ba2)[param_1] * 0x60 + param_1,
                  0xffffffe1,0x18);
    (&DAT_00263ba0)[param_1] = (&DAT_00263ba0)[param_1] + -1;
    (&DAT_00263ba2)[param_1] = (&DAT_00263ba2)[param_1] + 1 & 1;
    uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    wsr_ps(uVar2 & 0xf | uVar3 & 0xfffffff0);
    rsync();
    return;
  }
  memset(param_2,0,0x60);
  return;
}


// ===== rx_out_gain_mute_update @ 00224814 (134 bytes)

/* regs 0xD 0xE 0x10 */

void rx_out_gain_mute_update(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  ulonglong in_aed0;
  ulonglong uVar6;
  undefined8 uVar7;
  
  fVar5 = (float)in_aed0;
  if ((int)DAT_00263930 != (int)DAT_2007001c) {
    DAT_00263930 = DAT_2007001c;
    scl_int2float((int)DAT_2007001c,0xffffffff);
    uVar7 = ae_l32_i(0x3d4ccccd);
    in_aed0 = (ulonglong)(uint)(fVar5 * (float)uVar7);
    scl_antilog10f();
    DAT_00263938 = ae_s32_l_i(in_aed0);
  }
  fVar5 = (float)in_aed0;
  if ((int)DAT_00263932 != (int)DAT_2007001a) {
    DAT_00263932 = DAT_2007001a;
    scl_int2float((int)DAT_2007001a,0xffffffff);
    uVar7 = ae_l32_i(0x3d4ccccd);
    uVar6 = (ulonglong)(uint)(fVar5 * (float)uVar7);
    scl_antilog10f();
    DAT_0026393c = ae_s32_l_i(uVar6);
  }
  uVar1 = (uint)DAT_20070020;
  uVar2 = regfile_gpio_sel();
  iVar3 = ae_l16ui_n(&DAT_00263860,0);
  uVar2 = uVar1 & 1 | uVar2;
  iVar4 = ae_zext16(uVar2);
  if (iVar3 != iVar4) {
    ae_s16i_n(uVar2,&DAT_00263860,0);
    if (iVar4 != 0) {
      FUN_0022548c();
      FUN_0022548c(&DAT_00263948);
      return;
    }
    FUN_00225478();
    FUN_00225478(&DAT_00263948);
  }
  return;
}


// ===== aux_in_lp_init @ 002248a0 (54 bytes)

/* iir_cascade_init(coefficients 0x2373A0); placed before aux_in_gain_lp [inference] */

void aux_in_lp_init(void)

{
  undefined8 uVar1;
  
  DAT_00263cd0 = 0;
  DAT_00263cd4 = 0;
  uVar1 = const_s(1);
  DAT_00263cd8 = ae_s32_l_i(uVar1);
  DAT_00263cdc = iir_cascade_init(0x263cf0,2,&DAT_002373a0,1);
  DAT_00263ce0 = 0;
  uVar1 = ae_l32_i(0x3f800000);
  DAT_00263ce4 = ae_s32_l_i(uVar1);
  return;
}


// ===== aux_in_gain_lp @ 002248d8 (133 bytes)

/* reg 0x23, only with reg 6 = 10 */

void aux_in_gain_lp(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  float fVar4;
  undefined8 uVar5;
  
  uVar2 = (undefined1)param_1;
  iVar1 = DAT_00263cd4;
  if (DAT_00263cd0 != param_1) {
    if (param_1 == 0) goto LAB_002248f9;
    DAT_00263cdc = iir_cascade_init(0x263cf0,2,&DAT_002373a0,1);
    iVar1 = DAT_00263cd4;
  }
  DAT_00263cd4 = iVar1;
  if (param_1 != 0) {
    DAT_00263cd4 = (int)DAT_20070046;
    uVar5 = ae_l32_i(DAT_00263cd8);
    fVar4 = (float)uVar5;
    DAT_00263cd0 = uVar2;
    if (iVar1 != DAT_00263cd4) {
      scl_int2float(DAT_00263cd4,0xffffffff);
      uVar3 = (ulonglong)(uint)(fVar4 * 0.05);
      scl_antilog10f();
      DAT_00263cd8 = ae_s32_l_i(uVar3);
      iVar1 = DAT_00263cd4;
    }
    DAT_00263cd4 = iVar1;
    vec_scalef(param_3,param_2,0x18);
    iir_cascade_process(DAT_00263cdc,param_3,param_2,0x18);
    return;
  }
LAB_002248f9:
  DAT_00263cd0 = uVar2;
  memset(param_3,0,0x60);
  return;
}


// ===== rx_aux_in_gain @ 00224960 (66 bytes)

/* reg 0x60 gain on codec ADC channel 1, which replaces the demodulator output into Rx_Audio when
   reg 6 = 10 and reg 10 n0 = 1 (#184; was rx_loop_gain) */

void rx_aux_in_gain(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  int iVar2;
  float fVar3;
  undefined8 uVar4;
  
  iVar2 = (int)DAT_200700c0;
  uVar4 = ae_l32_i(DAT_00263ce4);
  fVar3 = (float)uVar4;
  if (DAT_00263ce0 != iVar2) {
    DAT_00263ce0 = iVar2;
    scl_int2float(iVar2,0xffffffff);
    uVar1 = (ulonglong)(uint)(fVar3 * 0.05);
    scl_antilog10f();
    DAT_00263ce4 = ae_s32_l_i(uVar1);
  }
  vec_scalef(param_2,param_1,0x18);
  return;
}


// ===== routing_regs_init @ 002249b0 (30 bytes)

/* clears the 7 selector words 0x263D50 used by routing_regs_decode [fact for the code] */

void routing_regs_init(void)

{
  DAT_00263d5c = 0;
  DAT_00263d5a = 0;
  DAT_00263d58 = 0;
  DAT_00263d56 = 0;
  DAT_00263d54 = 0;
  ae_s16i_n(0,&DAT_00263d50,2);
  ae_s16i_n(0,&DAT_00263d50,0);
  return;
}


// ===== routing_regs_decode @ 002249d0 (61 bytes)

/* regs 8, 9, 10 -> selector nibbles */

void routing_regs_decode(void)

{
  DAT_00263d52 = DAT_20070010 >> 8 & 0xf;
  DAT_00263d54 = DAT_20070010 >> 4 & 0xf;
  DAT_00263d56 = DAT_20070010 & 0xf;
  ae_s16i_n((uint)(DAT_20070010 >> 0xc),&DAT_00263d50,0);
  DAT_00263d58 = DAT_20070012 & 0xf;
  DAT_00263d5a = DAT_20070014 >> 4 & 0xf;
  DAT_00263d5c = DAT_20070014 & 0xf;
  return;
}


// ===== create_Thread_Spi @ 00224a10 (148 bytes)

void create_Thread_Spi(void)

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
  
  spectrum_init();
  FUN_00224000();
  rec_resample_init();
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
  DAT_002642a1 = 0;
  DAT_002642a2 = 0;
  DAT_002642a0 = 0;
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar2 = uVar2 & 0xf | uVar3 & 0xfffffff0;
  wsr_ps(uVar2);
  rsync();
  DAT_002642a8 = bkfiraf_init(&DAT_00264b70,0xab,FLOAT_ARRAY_00205540,uVar2);
  xos_thread_create(&DAT_002642b0,0,Thread_Spi_entry,0,"Thread_Spi",&DAT_002650f0,&DAT_00001398,5,0,
                    0);
  xos_msgq_create(PTR_DAT_002374f4,4,4,0);
  return;
}

