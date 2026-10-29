// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== fir_process @ 00233a10 (731 bytes)

void fir_process(int *param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uVar20;
  int iVar21;
  int iVar22;
  float fVar23;
  uint uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 *puVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  ulonglong uVar34;
  ulonglong uVar35;
  undefined8 uVar36;
  ulonglong uVar37;
  ulonglong uVar38;
  
  if (0 < (int)param_4) {
    iVar14 = *param_1;
    puVar15 = (undefined8 *)param_1[3];
    uVar12 = wur_ae_cbegin0(param_1[2]);
    puVar16 = (undefined8 *)param_1[1];
    wur_ae_cbegin1(puVar16);
    uVar28 = const_s(0);
    uVar13 = wur_ae_cend0(iVar14 * 4 + param_1[2]);
    wur_ae_cend1(iVar14 * 4 + (int)puVar16);
    puVar27 = puVar16 + 1;
    iVar14 = iVar14 >> 2;
    if (((uint)puVar15 >> 2 & 1) != 0) {
      uVar17 = ae_addcirc_xc(puVar15,0xfffffffc,uVar13,uVar12);
      uVar25 = ae_l32x2_xc1(*puVar16);
      puVar16 = (undefined8 *)ae_circ1(puVar16,0x10);
      fVar1 = (float)uVar25;
      uVar18 = ae_l32_ip(*param_3);
      param_3 = param_3 + 1;
      uVar20 = ae_s32_l_xc(uVar18);
      *(undefined4 *)puVar15 = uVar20;
      puVar15 = (undefined8 *)ae_circ0(puVar15,4);
      uVar25 = ae_l32x2_xc1(*puVar27);
      puVar27 = (undefined8 *)ae_circ1(puVar27,0x10);
      fVar6 = (float)uVar25;
      uVar25 = ae_la32x2neg_pc(uVar17,uVar12,uVar13);
      uVar20 = ae_la32x2neg_pc_1(uVar17,uVar12,uVar13);
      uVar26 = ae_la32x2_ric(uVar25,uVar20,uVar13,uVar12);
      uVar29 = ae_la32x2_ric_1(uVar25,uVar20,uVar13,uVar12);
      uVar20 = ae_la32x2_ric_2(uVar25,uVar20,uVar13,uVar12);
      uVar25 = ae_la32x2_ric(uVar29,uVar20,uVar13,uVar12);
      uVar30 = ae_la32x2_ric_1(uVar29,uVar20,uVar13,uVar12);
      uVar20 = ae_la32x2_ric_2(uVar29,uVar20,uVar13,uVar12);
      uVar29 = ae_mov(uVar28);
      fVar8 = (float)uVar29;
      iVar21 = iVar14 + -1;
      uVar29 = ae_sel16i_n(uVar18,uVar26,0);
      uVar18 = ae_mov(uVar28);
      fVar5 = (float)uVar29;
      fVar7 = (float)uVar18;
      uVar26 = ae_sel16i(uVar26,uVar25,0);
      fVar3 = (float)uVar26;
      if ((0 < iVar21) && ((iVar21 == 1 || (0 < iVar21)))) {
        uVar26 = ae_la32x2_ric(uVar30,uVar20,uVar13,uVar12);
        uVar29 = ae_la32x2_ric_1(uVar30,uVar20,uVar13,uVar12);
        uVar20 = ae_la32x2_ric_2(uVar30,uVar20,uVar13,uVar12);
        fVar7 = fVar7 + fVar5 * fVar1;
        fVar8 = fVar8 + fVar3 * fVar6;
        uVar30 = ae_la32x2_ric(uVar29,uVar20,uVar13,uVar12);
        ae_la32x2_ric_1(uVar29,uVar20,uVar13,uVar12);
        ae_la32x2_ric_2(uVar29,uVar20,uVar13,uVar12);
        uVar25 = ae_sel16i(uVar25,uVar26,0);
        uVar29 = ae_l32x2_xc1(*puVar27);
        puVar27 = (undefined8 *)ae_circ1(puVar27,0x10);
        fVar5 = (float)uVar25;
        fVar6 = (float)uVar29;
        ae_mov(uVar30);
        uVar25 = ae_l32x2_xc1(*puVar16);
        puVar16 = (undefined8 *)ae_circ1(puVar16,0x10);
        uVar30 = ae_sel16i_n(uVar26,uVar30,0);
        fVar1 = (float)uVar25;
        fVar3 = (float)uVar30;
      }
      fVar7 = fVar7 + fVar5 * fVar1 + fVar8 + fVar3 * fVar6;
      uVar25 = ae_sel16i((ulonglong)(uint)fVar7,(ulonglong)(uint)fVar7,0);
      param_4 = param_4 - 1;
      uVar20 = ae_s32_l_ip((ulonglong)(uint)((float)uVar25 + fVar7));
      *param_2 = uVar20;
      param_2 = param_2 + 1;
    }
    uVar30 = ae_la64_pp(param_3);
    uVar25 = ae_zalign64();
    if (0 < (int)param_4 >> 2) {
      uVar19 = ae_mov(uVar28);
      uVar31 = ae_mov(uVar28);
      uVar36 = ae_mov(uVar28);
      iVar21 = 0;
      uVar32 = ae_mov(uVar28);
      uVar26 = ae_mov(uVar28);
      uVar20 = ae_addcirc_xc(puVar15,0xfffffff8,uVar13,uVar12);
      uVar18 = ae_mov(uVar28);
      uVar29 = ae_mov(uVar28);
      do {
        fVar11 = (float)uVar19;
        fVar10 = (float)uVar31;
        fVar6 = (float)uVar36;
        fVar8 = (float)uVar32;
        uVar19 = ae_la32x2_ip(uVar30,param_3);
        uVar32 = ae_la32x2_ip_1(uVar30,param_3);
        uVar17 = ae_la32x2_ip_2(uVar30,param_3);
        uVar31 = ae_la32x2_ip(uVar32,uVar17);
        uVar30 = ae_la32x2_ip_1(uVar32,uVar17);
        param_3 = (undefined4 *)ae_la32x2_ip_2(uVar32,uVar17);
        iVar21 = iVar21 + 1;
        uVar32 = ae_l32x2_xc1(*puVar16);
        puVar16 = (undefined8 *)ae_circ1(puVar16,0x10);
        uVar36 = ae_sel16i_n(uVar19,uVar19,0);
        fVar2 = (float)uVar32;
        uVar32 = ae_l32x2_ric(uVar20,uVar13,uVar12);
        uVar20 = ae_l32x2_ric_1(uVar20,uVar13,uVar12);
        iVar22 = iVar14 + -1;
        uVar33 = ae_sel16i_n(uVar31,uVar19,2);
        fVar9 = (float)uVar36;
        fVar5 = (float)uVar18 + fVar9 * fVar2;
        uVar18 = ae_sel16i(uVar36,uVar32,0);
        fVar4 = (float)uVar18;
        uVar18 = ae_l32x2_xc1(*puVar27);
        fVar23 = (float)uVar18;
        puVar27 = (undefined8 *)ae_circ1(puVar27,0x10);
        fVar7 = (float)uVar29 + (float)uVar33 * fVar2;
        uVar18 = ae_sel16i(uVar31,uVar31,0);
        uVar29 = ae_mov(uVar28);
        fVar1 = (float)uVar29;
        fVar3 = (float)uVar26 + (float)uVar18 * fVar2;
        if ((0 < iVar22) && ((iVar22 == 1 || (0 < iVar22)))) {
          uVar26 = ae_l32x2_xc1(*puVar16);
          puVar16 = (undefined8 *)ae_circ1(puVar16,0x10);
          fVar8 = fVar8 + fVar4 * fVar2;
          fVar6 = fVar6 + fVar4 * fVar23;
          fVar2 = (float)uVar26;
          uVar36 = ae_l32x2_ric(uVar20,uVar13,uVar12);
          uVar20 = ae_l32x2_ric_1(uVar20,uVar13,uVar12);
          fVar1 = fVar1 + fVar9 * fVar23;
          fVar4 = (float)uVar32;
          fVar10 = fVar10 + fVar4 * fVar23;
          uVar26 = ae_sel16i(uVar32,uVar36,0);
          uVar32 = ae_l32x2_ric(uVar20,uVar13,uVar12);
          uVar20 = ae_l32x2_ric_1(uVar20,uVar13,uVar12);
          fVar3 = fVar3 + fVar4 * fVar2;
          fVar5 = fVar5 + (float)uVar36 * fVar2;
          uVar29 = ae_sel16i(uVar36,uVar32,0);
          uVar18 = ae_l32x2_xc1(*puVar27);
          puVar27 = (undefined8 *)ae_circ1(puVar27,0x10);
          fVar7 = fVar7 + (float)uVar26 * fVar2;
          fVar11 = fVar11 + (float)uVar26 * fVar23;
          fVar4 = (float)uVar29;
          fVar23 = (float)uVar18;
        }
        uVar26 = ae_l32x2_ric(uVar20,uVar13,uVar12);
        ae_l32x2_ric_1(uVar20,uVar13,uVar12);
        uVar26 = ae_sel16i(uVar32,uVar26,0);
        uVar34 = (ulonglong)(uint)(fVar3 + fVar1 + (float)uVar36 * fVar23);
        uVar37 = (ulonglong)(uint)(fVar7 + fVar6 + fVar4 * fVar23);
        uVar35 = (ulonglong)(uint)(fVar5 + fVar10 + (float)uVar32 * fVar23);
        uVar38 = (ulonglong)(uint)(fVar8 + fVar4 * fVar2 + fVar11 + (float)uVar26 * fVar23);
        uVar26 = ae_sel16i(uVar38,uVar35,0);
        uVar18 = ae_sel16i_n(uVar38,uVar35,2);
        uVar29 = ae_sel16i(uVar37,uVar34,0);
        uVar35 = (ulonglong)(uint)((float)uVar18 + (float)uVar26);
        uVar26 = ae_sel16i(uVar37,uVar34,2);
        uVar34 = (ulonglong)(uint)((float)uVar26 + (float)uVar29);
        uVar26 = ae_s32x2_xc(uVar19);
        *puVar15 = uVar26;
        puVar15 = (undefined8 *)ae_circ0(puVar15,8);
        uVar26 = ae_s32x2_xc(uVar31);
        *puVar15 = uVar26;
        puVar15 = (undefined8 *)ae_circ0(puVar15,8);
        uVar31 = ae_mov(uVar28);
        uVar19 = ae_mov(uVar28);
        uVar26 = ae_sa32x2_ip(uVar35,uVar25,param_2);
        uVar20 = ae_sa32x2_ip_1(uVar35,uVar25,param_2);
        uVar32 = ae_mov(uVar28);
        uVar36 = ae_mov(uVar28);
        uVar25 = ae_sa32x2_ip(uVar34,uVar26,uVar20);
        param_2 = (undefined4 *)ae_sa32x2_ip_1(uVar34,uVar26,uVar20);
        uVar20 = ae_addcirc_xc(puVar15,0xfffffff8,uVar13,uVar12);
        uVar18 = ae_mov(uVar28);
        uVar29 = ae_mov(uVar28);
        uVar26 = ae_mov(uVar28);
      } while ((int)param_4 >> 2 != iVar21);
    }
    ae_sa64pos_fp(uVar25,param_2);
    uVar24 = param_4 & 0xfffffffc;
    if ((int)uVar24 < (int)param_4) {
      uVar20 = ae_addcirc_xc(puVar15,0xfffffffc,uVar13,uVar12);
      uVar30 = ae_mov(uVar28);
      uVar25 = ae_mov(uVar28);
      do {
        iVar21 = iVar14 + -1;
        fVar8 = (float)uVar30;
        fVar7 = (float)uVar25;
        uVar30 = ae_la32x2neg_pc(uVar20,uVar12,uVar13);
        uVar17 = ae_la32x2neg_pc_1(uVar20,uVar12,uVar13);
        uVar18 = ae_l32_ip(*param_3);
        param_3 = param_3 + 1;
        uVar20 = ae_s32_l_xc(uVar18);
        *(undefined4 *)puVar15 = uVar20;
        puVar15 = (undefined8 *)ae_circ0(puVar15,4);
        uVar24 = uVar24 + 1;
        uVar25 = ae_la32x2_ric(uVar30,uVar17,uVar13,uVar12);
        uVar26 = ae_la32x2_ric_1(uVar30,uVar17,uVar13,uVar12);
        uVar20 = ae_la32x2_ric_2(uVar30,uVar17,uVar13,uVar12);
        uVar30 = ae_l32x2_xc1(*puVar16);
        puVar16 = (undefined8 *)ae_circ1(puVar16,0x10);
        fVar1 = (float)uVar30;
        uVar30 = ae_la32x2_ric(uVar26,uVar20,uVar13,uVar12);
        uVar29 = ae_la32x2_ric_1(uVar26,uVar20,uVar13,uVar12);
        uVar20 = ae_la32x2_ric_2(uVar26,uVar20,uVar13,uVar12);
        uVar26 = ae_l32x2_xc1(*puVar27);
        puVar27 = (undefined8 *)ae_circ1(puVar27,0x10);
        fVar6 = (float)uVar26;
        uVar26 = ae_sel16i_n(uVar18,uVar25,0);
        fVar5 = (float)uVar26;
        uVar25 = ae_sel16i(uVar25,uVar30,0);
        fVar3 = (float)uVar25;
        if ((0 < iVar21) && ((iVar21 == 1 || (0 < iVar21)))) {
          uVar25 = ae_la32x2_ric(uVar29,uVar20,uVar13,uVar12);
          uVar26 = ae_la32x2_ric_1(uVar29,uVar20,uVar13,uVar12);
          uVar20 = ae_la32x2_ric_2(uVar29,uVar20,uVar13,uVar12);
          fVar7 = fVar7 + fVar5 * fVar1;
          fVar8 = fVar8 + fVar3 * fVar6;
          uVar29 = ae_la32x2_ric(uVar26,uVar20,uVar13,uVar12);
          ae_la32x2_ric_1(uVar26,uVar20,uVar13,uVar12);
          ae_la32x2_ric_2(uVar26,uVar20,uVar13,uVar12);
          uVar30 = ae_sel16i(uVar30,uVar25,0);
          uVar26 = ae_l32x2_xc1(*puVar27);
          puVar27 = (undefined8 *)ae_circ1(puVar27,0x10);
          fVar5 = (float)uVar30;
          fVar6 = (float)uVar26;
          ae_mov(uVar29);
          uVar30 = ae_l32x2_xc1(*puVar16);
          puVar16 = (undefined8 *)ae_circ1(puVar16,0x10);
          uVar25 = ae_sel16i_n(uVar25,uVar29,0);
          fVar1 = (float)uVar30;
          fVar3 = (float)uVar25;
        }
        fVar7 = fVar7 + fVar5 * fVar1 + fVar8 + fVar3 * fVar6;
        uVar25 = ae_sel16i((ulonglong)(uint)fVar7,(ulonglong)(uint)fVar7,0);
        uVar20 = ae_s32_l_ip((ulonglong)(uint)((float)uVar25 + fVar7));
        *param_2 = uVar20;
        param_2 = param_2 + 1;
        uVar20 = ae_addcirc_xc(puVar15,0xfffffffc,uVar13,uVar12);
        uVar30 = ae_mov(uVar28);
        uVar25 = ae_mov(uVar28);
      } while (param_4 != uVar24);
    }
    param_1[3] = (int)puVar15;
    return;
  }
  return;
}


// ===== FUN_00233cf0 @ 00233cf0 (22 bytes)

int FUN_00233cf0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 << 2;
  if (param_2 != 0) {
    iVar1 = 0;
  }
  return param_1 * 4 + iVar1 + 0x17;
}


// ===== FUN_00233d08 @ 00233d08 (102 bytes)

undefined8 FUN_00233d08(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  int *piVar6;
  
  puVar2 = (undefined4 *)(param_1 + 7U & 0xfffffff8);
  piVar6 = puVar2 + param_2;
  if (param_3 == 0) {
    puVar4 = puVar2 + param_2;
    piVar3 = puVar4 + param_2;
    piVar3[1] = (int)piVar6;
    *piVar3 = param_2;
    piVar3[3] = (int)puVar4;
    piVar3[2] = (int)puVar4;
    if (param_2 < 1) goto LAB_00233d44;
    if ((0 < param_2) && ((param_2 == 1 || (0 < param_2)))) {
      uVar5 = ae_l32_ip(*param_4);
      uVar1 = ae_s32_l_ip(uVar5);
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    }
  }
  else {
    piVar6[1] = (int)param_4;
    piVar6[3] = (int)puVar2;
    piVar6[2] = (int)puVar2;
    *piVar6 = param_2;
    puVar4 = puVar2;
    piVar3 = piVar6;
  }
  if (((0 < param_2) && (uVar5 = const_s(0), 0 < param_2)) && ((param_2 == 1 || (0 < param_2)))) {
    uVar1 = ae_s32_l_ip(uVar5);
    *puVar4 = uVar1;
  }
LAB_00233d44:
  return CONCAT44(puVar2,piVar3);
}


// ===== FUN_00233d70 @ 00233d70 (311 bytes)

void FUN_00233d70(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 *puVar12;
  int iVar13;
  float fVar14;
  undefined8 *puVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  int iVar21;
  undefined8 *puVar22;
  int iVar23;
  undefined4 uVar24;
  undefined8 uVar25;
  float fVar26;
  float fVar27;
  undefined8 uVar28;
  undefined8 uVar30;
  undefined8 uVar31;
  float fVar32;
  undefined8 uVar33;
  ulonglong uVar34;
  ulonglong uVar35;
  undefined8 uVar29;
  
  if (0 < param_4) {
    uVar16 = ae_zalign64();
    iVar23 = 0;
    puVar12 = (undefined8 *)(param_3 + 8);
    iVar21 = *param_1;
    uVar10 = wur_ae_cbegin0(param_1[2]);
    iVar13 = param_1[3];
    puVar22 = (undefined8 *)param_1[1];
    uVar28 = const_s(0);
    uVar28 = ae_s32x2_i(uVar28);
    wur_ae_cbegin1(puVar22);
    uVar11 = wur_ae_cend0(iVar21 * 4 + param_1[2]);
    wur_ae_cend1(iVar21 * 4 + (int)puVar22);
    do {
      iVar1 = (iVar21 >> 2) + -1;
      uVar17 = ae_l32x2_i(uVar28);
      iVar23 = iVar23 + 1;
      uVar18 = ae_l32x2_xc1(*puVar22);
      puVar22 = (undefined8 *)ae_circ1(puVar22,8);
      uVar25 = ae_l64_ip(*puVar12);
      uVar29 = ae_mov(uVar17);
      fVar26 = (float)uVar29;
      uVar29 = ae_mov(uVar17);
      fVar32 = (float)uVar29;
      fVar2 = (float)uVar18;
      uVar18 = ae_mov(uVar17);
      fVar14 = (float)uVar18;
      uVar29 = ae_l64_ip(puVar12[-1]);
      puVar12 = puVar12 + 2;
      uVar30 = ae_mov(uVar17);
      uVar18 = ae_mov(uVar17);
      uVar19 = ae_sel16i(uVar25,uVar25,0);
      uVar24 = ae_addcirc_xc(iVar13,0xfffffff8,uVar11,uVar10);
      uVar31 = ae_sel16i_n(uVar25,uVar29,0);
      fVar3 = (float)uVar18 + (float)uVar25 * fVar2;
      uVar20 = ae_mov(uVar17);
      uVar18 = ae_l32x2_ric(uVar24,uVar11,uVar10);
      uVar24 = ae_l32x2_ric_1(uVar24,uVar11,uVar10);
      fVar5 = (float)uVar30 + (float)uVar31 * fVar2;
      uVar33 = ae_mov(uVar17);
      uVar30 = ae_sel16i(uVar29,uVar29,0);
      uVar25 = ae_l32x2_xc1(*puVar22);
      puVar22 = (undefined8 *)ae_circ1(puVar22,8);
      uVar31 = ae_sel16i_n(uVar29,uVar18,0);
      fVar27 = (float)uVar31;
      fVar7 = (float)uVar29;
      fVar6 = (float)uVar33 + fVar7 * fVar2;
      fVar8 = (float)uVar25;
      uVar25 = ae_l32x2_ric(uVar24,uVar11,uVar10);
      uVar24 = ae_l32x2_ric_1(uVar24,uVar11,uVar10);
      fVar4 = (float)uVar18;
      fVar9 = (float)uVar20 + fVar4 * fVar8;
      if ((0 < iVar1) && ((iVar1 == 1 || (0 < iVar1)))) {
        uVar20 = ae_sel16i(uVar18,uVar25,0);
        uVar18 = ae_l32x2_xc1(*puVar22);
        puVar22 = (undefined8 *)ae_circ1(puVar22,8);
        uVar17 = (ulonglong)(uint)((float)uVar17 + fVar27 * fVar2);
        fVar14 = fVar14 + fVar27 * fVar8;
        fVar2 = (float)uVar18;
        uVar18 = ae_l32x2_ric(uVar24,uVar11,uVar10);
        uVar24 = ae_l32x2_ric_1(uVar24,uVar11,uVar10);
        fVar3 = fVar3 + fVar4 * fVar2;
        fVar5 = fVar5 + (float)uVar20 * fVar2;
        uVar29 = ae_mov(uVar25);
        uVar25 = ae_l32x2_xc1(*puVar22);
        puVar22 = (undefined8 *)ae_circ1(puVar22,8);
        fVar32 = fVar32 + fVar7 * fVar8;
        fVar26 = fVar26 + (float)uVar20 * fVar8;
        fVar8 = (float)uVar25;
        uVar20 = ae_sel16i(uVar29,uVar18,0);
        uVar25 = ae_l32x2_ric(uVar24,uVar11,uVar10);
        uVar24 = ae_l32x2_ric_1(uVar24,uVar11,uVar10);
        fVar6 = fVar6 + (float)uVar29 * fVar2;
        fVar9 = fVar9 + (float)uVar18 * fVar8;
        fVar27 = (float)uVar20;
      }
      uVar18 = ae_sel16i(uVar18,uVar25,0);
      uVar34 = (ulonglong)(uint)((float)uVar17 + fVar27 * fVar2 + fVar26 + (float)uVar18 * fVar8);
      uVar17 = (ulonglong)(uint)(fVar3 + fVar32 + (float)uVar29 * fVar8);
      uVar35 = (ulonglong)(uint)(fVar5 + fVar14 + fVar27 * fVar8);
      uVar18 = ae_sel16i(uVar34,(ulonglong)(uint)(fVar6 + fVar9),0);
      uVar29 = ae_sel16i_n(uVar34,(ulonglong)(uint)(fVar6 + fVar9),2);
      uVar25 = ae_sel16i(uVar35,uVar17,0);
      uVar34 = (ulonglong)(uint)((float)uVar29 + (float)uVar18);
      uVar18 = ae_sel16i(uVar35,uVar17,2);
      puVar15 = (undefined8 *)ae_addcirc_xc(uVar24,8,uVar11,uVar10);
      uVar17 = (ulonglong)(uint)((float)uVar18 + (float)uVar25);
      uVar18 = ae_s32x2_xc(uVar30);
      *puVar15 = uVar18;
      puVar15 = (undefined8 *)ae_circ0(puVar15,8);
      uVar18 = ae_s32x2_xc(uVar19);
      *puVar15 = uVar18;
      iVar13 = ae_circ0(puVar15,8);
      uVar18 = ae_sa32x2_ip(uVar34,uVar16,param_2);
      uVar24 = ae_sa32x2_ip_1(uVar34,uVar16,param_2);
      uVar16 = ae_sa32x2_ip(uVar17,uVar18,uVar24);
      param_2 = ae_sa32x2_ip_1(uVar17,uVar18,uVar24);
    } while (param_4 >> 2 != iVar23);
    param_1[3] = iVar13;
    ae_sa64pos_fp(uVar16,param_2);
    return;
  }
  return;
}


// ===== FUN_00233eb0 @ 00233eb0 (567 bytes)

void FUN_00233eb0(undefined8 *param_1,int param_2,undefined8 *param_3,undefined8 *param_4,
                 int param_5,int param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  float fVar7;
  undefined8 in_aed0;
  float fVar8;
  undefined8 in_aed1;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined8 *puVar14;
  float fVar15;
  float fVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  undefined8 uVar20;
  float fVar21;
  int iVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  float fVar25;
  undefined8 uVar26;
  undefined8 uVar28;
  undefined8 uVar29;
  ulonglong uVar30;
  undefined8 uVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  undefined8 uVar19;
  undefined8 uVar27;
  
  uVar1 = ae_s32_l_i(in_aed1);
  iVar22 = 0;
  uVar2 = ae_s32_l_i(in_aed0);
  puVar4 = param_4 + 1;
  param_2 = param_6 * 4 + param_2;
  uVar26 = const_s(0);
  uVar26 = ae_s32x2_i(uVar26);
  puVar14 = (undefined8 *)(param_2 + -8);
  puVar3 = param_4;
  puVar5 = param_1;
  puVar6 = puVar4;
  do {
    uVar17 = ae_l32x2_ip(*puVar3);
    uVar18 = ae_l32x2_i(uVar26);
    uVar23 = ae_l64_ip(*puVar14);
    uVar19 = ae_mov(uVar18);
    fVar15 = (float)uVar19;
    uVar19 = ae_l32x2_ip(*puVar6);
    uVar27 = ae_mov(uVar18);
    fVar25 = (float)uVar27;
    uVar27 = ae_mov(uVar18);
    fVar13 = (float)uVar27;
    uVar27 = ae_mov(uVar18);
    fVar16 = (float)uVar27;
    uVar27 = ae_l32x2_ip(puVar6[2]);
    uVar28 = ae_mov(uVar18);
    uVar31 = ae_mov(uVar18);
    uVar20 = ae_sel16i(uVar17,uVar19,0);
    uVar24 = ae_l64_i(*(undefined8 *)(param_2 + -0x10));
    uVar29 = ae_mov(uVar18);
    fVar7 = (float)uVar23;
    fVar8 = (float)uVar31 + (float)uVar17 * fVar7;
    fVar12 = (float)uVar24;
    uVar23 = ae_l32x2_ip(puVar3[2]);
    fVar11 = (float)uVar19;
    fVar10 = (float)uVar29 + fVar11 * fVar7;
    fVar9 = (float)uVar28 + (float)uVar20 * fVar7;
    uVar17 = ae_sel16i(uVar19,uVar23,0);
    fVar21 = (float)uVar17;
    uVar17 = uVar23;
    if (0 < (param_6 >> 2) + -1) {
      uVar20 = ae_sel16i(uVar23,uVar27,0);
      uVar17 = ae_l64_ip(*(undefined8 *)(param_2 + -0x18));
      uVar18 = (ulonglong)(uint)((float)uVar18 + fVar21 * fVar7);
      fVar16 = fVar16 + fVar21 * fVar12;
      fVar7 = (float)uVar17;
      uVar17 = ae_l32x2_ip(puVar3[4]);
      fVar8 = fVar8 + (float)uVar23 * fVar7;
      fVar25 = fVar25 + (float)uVar23 * fVar12;
      uVar19 = ae_mov(uVar27);
      uVar27 = ae_l32x2_ip(puVar6[4]);
      fVar13 = fVar13 + fVar11 * fVar12;
      fVar15 = fVar15 + (float)uVar20 * fVar12;
      uVar23 = ae_sel16i(uVar19,uVar17,0);
      uVar24 = ae_l64_i(*(undefined8 *)(param_2 + -0x20));
      fVar9 = fVar9 + (float)uVar20 * fVar7;
      fVar10 = fVar10 + (float)uVar19 * fVar7;
      fVar21 = (float)uVar23;
      fVar12 = (float)uVar24;
    }
    uVar27 = ae_sel16i(uVar17,uVar27,0);
    uVar30 = (ulonglong)(uint)(fVar9 + fVar16 + fVar21 * fVar12);
    uVar32 = (ulonglong)(uint)(fVar8 + fVar13 + (float)uVar19 * fVar12);
    uVar18 = (ulonglong)(uint)((float)uVar18 + fVar21 * fVar7 + fVar15 + (float)uVar27 * fVar12);
    uVar33 = (ulonglong)(uint)(fVar10 + fVar25 + (float)uVar17 * fVar12);
    uVar19 = ae_sel16i(uVar32,uVar30,0);
    uVar23 = ae_sel16i_n(uVar32,uVar30,2);
    uVar27 = ae_sel16i(uVar33,uVar18,0);
    uVar24 = ae_sel16i_n(uVar33,uVar18,2);
    uVar17 = ae_l32x2_ip(*param_3);
    uVar20 = ae_l32x2_ip(param_3[1]);
    param_3 = param_3 + 2;
    puVar6 = puVar6 + 2;
    iVar22 = iVar22 + 4;
    uVar17 = ae_s32x2_ip((ulonglong)(uint)((float)uVar17 - ((float)uVar23 + (float)uVar19)));
    *puVar5 = uVar17;
    puVar3 = puVar3 + 2;
    uVar17 = ae_s32x2_ip((ulonglong)(uint)((float)uVar20 - ((float)uVar24 + (float)uVar27)));
    puVar5[1] = uVar17;
    puVar5 = puVar5 + 2;
  } while (iVar22 < param_5);
  uVar17 = ae_l32_i(uVar1);
  ae_l32_i(uVar2);
  iVar22 = 0;
  divf_();
  uVar17 = ae_s32x2_i(uVar17);
  puVar3 = puVar14;
  do {
    iVar22 = iVar22 + 4;
    uVar19 = ae_l32x2_ip(*param_4);
    uVar18 = ae_l32x2_i(uVar26);
    uVar20 = ae_l32x2_ip(*param_1);
    uVar27 = ae_l32x2_ip(*puVar4);
    uVar23 = ae_mov(uVar18);
    fVar25 = (float)uVar23;
    fVar7 = (float)uVar20;
    uVar20 = ae_mov(uVar18);
    fVar16 = (float)uVar20;
    uVar20 = ae_l32x2_ip(puVar4[2]);
    uVar23 = ae_mov(uVar18);
    fVar8 = (float)uVar23;
    uVar23 = ae_mov(uVar18);
    fVar9 = (float)uVar23;
    uVar23 = ae_mov(uVar18);
    uVar24 = ae_l32x2_i(param_1[1]);
    fVar12 = (float)uVar24;
    uVar28 = ae_sel16i_n(uVar19,uVar27,0);
    uVar31 = ae_mov(uVar18);
    uVar24 = ae_l32x2_ip(param_4[2]);
    puVar5 = param_4 + 4;
    uVar29 = ae_mov(uVar18);
    fVar13 = (float)uVar31 + (float)uVar28 * fVar7;
    param_4 = param_4 + 2;
    uVar28 = ae_sel16i_n(uVar27,uVar24,0);
    fVar10 = (float)uVar29 + (float)uVar19 * fVar7;
    fVar21 = (float)uVar28;
    fVar11 = (float)uVar27;
    fVar15 = (float)uVar23 + fVar11 * fVar7;
    uVar19 = uVar24;
    if (0 < (param_5 >> 2) + -1) {
      uVar23 = ae_sel16i(uVar24,uVar20,0);
      uVar19 = ae_l32x2_ip(param_1[2]);
      uVar18 = (ulonglong)(uint)((float)uVar18 + fVar21 * fVar7);
      fVar9 = fVar9 + fVar21 * fVar12;
      fVar7 = (float)uVar19;
      uVar19 = ae_l32x2_ip(*puVar5);
      fVar10 = fVar10 + (float)uVar24 * fVar7;
      fVar16 = fVar16 + (float)uVar24 * fVar12;
      uVar27 = ae_mov(uVar20);
      uVar20 = ae_l32x2_ip(puVar4[4]);
      fVar8 = fVar8 + fVar11 * fVar12;
      fVar25 = fVar25 + (float)uVar23 * fVar12;
      uVar24 = ae_sel16i(uVar27,uVar19,0);
      uVar28 = ae_l32x2_i(param_1[3]);
      fVar13 = fVar13 + (float)uVar23 * fVar7;
      fVar15 = fVar15 + (float)uVar27 * fVar7;
      fVar21 = (float)uVar24;
      fVar12 = (float)uVar28;
    }
    uVar20 = ae_sel16i(uVar19,uVar20,0);
    uVar30 = (ulonglong)(uint)(fVar13 + fVar9 + fVar21 * fVar12);
    uVar33 = (ulonglong)(uint)(fVar10 + fVar8 + (float)uVar27 * fVar12);
    uVar32 = (ulonglong)(uint)(fVar15 + fVar16 + (float)uVar19 * fVar12);
    uVar18 = (ulonglong)(uint)((float)uVar18 + fVar21 * fVar7 + fVar25 + (float)uVar20 * fVar12);
    uVar20 = ae_sel16i(uVar33,uVar30,0);
    uVar28 = ae_sel16i_n(uVar33,uVar30,2);
    uVar23 = ae_sel16i(uVar32,uVar18,0);
    uVar29 = ae_sel16i_n(uVar32,uVar18,2);
    uVar19 = ae_l64_ip(*puVar3);
    uVar27 = ae_l32x2_i(uVar17);
    uVar24 = ae_l64_ip(puVar3[-1]);
    puVar3 = puVar3 + -2;
    uVar19 = ae_s64_ip((ulonglong)
                       (uint)((float)uVar19 + (float)uVar27 * ((float)uVar28 + (float)uVar20)));
    *puVar14 = uVar19;
    uVar19 = ae_s64_ip((ulonglong)
                       (uint)((float)uVar24 + (float)uVar27 * ((float)uVar29 + (float)uVar23)));
    puVar14[-1] = uVar19;
    puVar14 = puVar14 + -2;
    puVar4 = puVar4 + 2;
  } while (iVar22 < param_6);
  return;
}


// ===== FUN_002340f0 @ 002340f0 (11 bytes)

int FUN_002340f0(int param_1)

{
  return param_1 * 0x20 + 0x1e;
}


// ===== iir_cascade_init @ 002340fc (194 bytes)

/* (state, sections, coefs b0 b1 b2 a1 a2, ?) */

undefined1  [16] iir_cascade_init(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  
  puVar8 = (undefined4 *)(param_1 + 7U & 0xfffffff8);
  puVar11 = (undefined4 *)(param_2 * 3);
  uVar9 = (int)puVar8 + param_2 * 0xc + 7 & 0xfffffff8;
  piVar3 = (int *)(param_2 * 0x14 + uVar9);
  *piVar3 = param_2;
  piVar3[3] = (int)puVar8;
  piVar3[1] = uVar9;
  *(short *)(piVar3 + 2) = (short)param_4;
  puVar12 = param_3;
  if (0 < param_2) {
    uVar7 = const_s(0);
    if ((0 < (int)puVar11) && ((puVar11 == (undefined4 *)0x1 || (0 < (int)puVar11)))) {
      uVar1 = ae_s32_l_ip(uVar7);
      *puVar8 = uVar1;
    }
    iVar5 = 0;
    iVar6 = 0;
    iVar4 = 0;
    do {
      puVar11 = (undefined4 *)(iVar5 + uVar9);
      iVar10 = 4;
      if (param_2 - iVar4 < 4) {
        iVar10 = param_2 - iVar4;
      }
      iVar4 = iVar4 + 4;
      if (0 < iVar10) {
        puVar8 = (undefined4 *)(iVar5 + (int)param_3);
        puVar12 = (undefined4 *)((iVar6 + iVar10) * 4 + uVar9);
        param_4 = (undefined4 *)((iVar10 * 2 + iVar6) * 4 + uVar9);
        if ((0 < iVar10) && ((iVar10 == 1 || (0 < iVar10)))) {
          uVar7 = ae_l32_i(*puVar8);
          uVar1 = ae_s32_l_ip(uVar7);
          *puVar11 = uVar1;
          puVar11 = puVar11 + 1;
          uVar7 = ae_l32_i(puVar8[1]);
          uVar1 = ae_s32_l_ip(uVar7);
          *puVar12 = uVar1;
          puVar12 = puVar12 + 1;
          uVar7 = ae_l32_i(puVar8[2]);
          uVar1 = ae_s32_l_ip(uVar7);
          *param_4 = uVar1;
          param_4 = param_4 + 1;
          uVar7 = ae_l32_i(puVar8[3]);
          uVar1 = ae_s32_l_ip(uVar7);
          *(undefined4 *)((iVar6 + iVar10 * 3) * 4 + uVar9) = uVar1;
          uVar7 = ae_l32_ip(puVar8[4]);
          uVar1 = ae_s32_l_ip(uVar7);
          *(undefined4 *)((iVar10 * 4 + iVar6) * 4 + uVar9) = uVar1;
        }
      }
      iVar5 = iVar5 + 0x50;
      iVar6 = iVar6 + 0x14;
    } while (iVar4 < param_2);
  }
  auVar2._4_4_ = puVar11;
  auVar2._0_4_ = piVar3;
  auVar2._8_4_ = puVar12;
  auVar2._12_4_ = param_4;
  return auVar2;
}


// ===== iir_cascade_process @ 002341c0 (1352 bytes)

/* (state, out, in, n) */

void iir_cascade_process(uint *param_1,undefined8 *param_2,undefined8 *param_3,uint param_4)

{
  undefined4 uVar1;
  float fVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 in_aed7;
  undefined8 uVar11;
  undefined8 *puVar12;
  uint uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 *puVar19;
  undefined8 *puVar20;
  int iVar21;
  float fVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 *puVar30;
  float fVar31;
  undefined8 uVar32;
  ulonglong uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 uVar38;
  ulonglong uVar39;
  undefined8 uStack_80;
  undefined4 *puStack_28;
  
  if (1 < (int)param_4) {
    uVar7 = *param_1;
    puVar19 = (undefined8 *)param_1[3];
    puVar20 = (undefined8 *)param_1[1];
    puVar30 = puVar19;
    if (0 < (int)uVar7 >> 2) {
      iVar21 = 0;
      do {
        uVar9 = ae_l32x2_ip(*puVar30);
        uVar10 = ae_l32x2_ip(puVar30[1]);
        in_aed7 = ae_l32x2_i(puVar20[2]);
        uVar23 = ae_l32x2_ip(puVar30[2]);
        uVar14 = ae_l32x2_i(puVar20[3]);
        uVar24 = ae_l32x2_ip(puVar30[3]);
        uVar15 = ae_l32x2_ip(puVar30[4]);
        iVar21 = iVar21 + 1;
        uVar25 = ae_l32x2_ip(puVar30[5]);
        puVar30 = puVar30 + 6;
        if (0 < (int)param_4) {
          puVar12 = param_2;
          if ((param_4 & 1) != 0) {
            uVar11 = ae_l32x2_x(puVar20[9]);
            uVar16 = ae_l32x2_i(puVar20[7]);
            uVar26 = ae_l32x2_i(puVar20[5]);
            uVar17 = ae_l32x2_x(puVar20[8]);
            uVar38 = ae_sel16i(uVar9,uVar10,0);
            uVar16 = maddn_s((ulonglong)(uint)((float)uVar11 * (float)uVar25),uVar16,uVar24);
            uVar10 = ae_l32_ip(*(undefined4 *)param_3);
            param_3 = (undefined8 *)((int)param_3 + 4);
            uVar11 = ae_l32x2_i(puVar20[4]);
            uVar9 = ae_sel16i(uVar10,uVar9,1);
            uVar10 = ae_l32x2_i(puVar20[6]);
            uVar26 = maddn_s((ulonglong)(uint)((float)uVar26 * (float)uVar25),uVar14,uVar24);
            uVar25 = ae_mov(uVar24);
            uVar17 = maddn_s((ulonglong)(uint)((float)uVar17 * (float)uVar15),uVar10,uVar23);
            uVar24 = (ulonglong)(uint)((float)uVar38 - (float)uVar16);
            uVar10 = ae_l32x2_i(puVar20[1]);
            uVar11 = maddn_s((ulonglong)(uint)((float)uVar11 * (float)uVar15),in_aed7,uVar23);
            uVar15 = ae_mov(uVar23);
            uVar10 = maddn_s(uVar26,uVar10,uVar24);
            uVar23 = (ulonglong)(uint)((float)uVar9 - (float)uVar17);
            uVar9 = ae_l32x2_i(*puVar20);
            uVar1 = ae_s32_l_ip(uVar10);
            *(undefined4 *)param_2 = uVar1;
            puVar12 = (undefined8 *)((int)param_2 + 4);
            uVar9 = maddn_s(uVar11,uVar9,uVar23);
          }
          if ((int)param_4 >> 1 != 0) {
            uVar17 = ae_l32x2_i(puVar20[6]);
            uVar27 = ae_l32x2_i(puVar20[4]);
            uVar15 = ae_s32x2_i(uVar15);
            uVar28 = ae_l32x2_x(puVar20[8]);
            uVar16 = ae_l32x2_i(uVar15);
            uVar26 = ae_l32x2_x(puVar20[9]);
            uVar38 = ae_l32x2_i(uVar15);
            uVar15 = ae_s32x2_i(in_aed7);
            uVar29 = ae_l32x2_i(puVar20[7]);
            uVar11 = ae_l32x2_i(uVar15);
            uVar18 = ae_l32_ip(*(undefined4 *)param_3);
            uVar28 = maddn_s((ulonglong)(uint)((float)uVar28 * (float)uVar16),uVar17,uVar23);
            uVar17 = ae_l32_i(*(undefined4 *)((int)param_3 + 4));
            uVar29 = maddn_s((ulonglong)(uint)((float)uVar26 * (float)uVar25),uVar29,uVar24);
            uVar26 = ae_l32x2_i(puVar20[4]);
            uVar16 = ae_l32x2_i(puVar20[5]);
            uVar32 = maddn_s((ulonglong)(uint)((float)uVar27 * (float)uVar38),uVar11,uVar23);
            uVar14 = ae_s32x2_i(uVar14);
            uVar27 = ae_l32x2_x(puVar20[8]);
            uVar11 = ae_sel16i(uVar18,uVar9,1);
            uVar38 = ae_l32x2_x(puVar20[9]);
            uVar39 = (ulonglong)(uint)((float)uVar11 - (float)uVar28);
            uVar11 = ae_l32x2_i(uVar15);
            uVar10 = ae_sel16i(uVar9,uVar10,0);
            uVar9 = ae_l32x2_i(uVar14);
            uVar33 = (ulonglong)(uint)((float)uVar10 - (float)uVar29);
            uVar10 = ae_l32x2_i(puVar20[6]);
            uVar16 = maddn_s((ulonglong)(uint)((float)uVar16 * (float)uVar25),uVar9,uVar24);
            uVar9 = ae_l32x2_i(*puVar20);
            uVar10 = maddn_s((ulonglong)(uint)((float)uVar27 * (float)uVar23),uVar10,uVar39);
            fVar31 = (float)uVar10;
            in_aed7 = ae_l32x2_i(uVar14);
            uVar27 = maddn_s(uVar32,uVar9,uVar39);
            uStack_80 = ae_s32x2_i(uVar39);
            uVar10 = ae_l32x2_i(puVar20[7]);
            uVar11 = maddn_s((ulonglong)(uint)((float)uVar26 * (float)uVar23),uVar11,uVar39);
            uVar9 = ae_l32x2_i(puVar20[1]);
            uVar18 = ae_l32x2_i(puVar20[5]);
            uVar10 = maddn_s((ulonglong)(uint)((float)uVar38 * (float)uVar24),uVar10,uVar33);
            fVar22 = (float)uVar10;
            uVar25 = ae_mov(uVar33);
            uVar26 = ae_l32x2_i(*puVar20);
            uVar38 = ae_l32x2_i(puVar20[1]);
            uVar9 = ae_mov(uVar9);
            uVar24 = (ulonglong)(uint)((float)uVar18 * (float)uVar24);
            uVar10 = ae_mov(uVar27);
            puVar3 = puVar12;
            if (0 < ((int)param_4 >> 1) + -1) {
              uVar27 = ae_l32x2_x(puVar20[9]);
              uVar34 = maddn_s(uVar16,uVar9,uVar25);
              uVar16 = ae_sel16i(uVar17,uVar10,1);
              uVar9 = ae_l32x2_x(puVar20[8]);
              fVar2 = (float)uVar16 - fVar31;
              uVar23 = (ulonglong)(uint)fVar2;
              uVar16 = ae_l32x2_i(uStack_80);
              uVar35 = maddn_s(uVar24,in_aed7,uVar25);
              uVar28 = ae_l32x2_i(puVar20[4]);
              uVar18 = ae_l32x2_i(puVar20[6]);
              uVar29 = ae_l32x2_i(puVar20[5]);
              uVar32 = ae_l32x2_i(puVar20[7]);
              uVar10 = ae_sel16i_n(uVar10,uVar34,0);
              uVar1 = ae_s32_l_ip(uVar34);
              *(undefined4 *)puVar12 = uVar1;
              puVar3 = puVar12 + 1;
              uVar34 = ae_l32x2_i(uStack_80);
              uVar36 = maddn_s(uVar11,uVar26,uVar23);
              fVar22 = (float)uVar10 - fVar22;
              uVar24 = (ulonglong)(uint)fVar22;
              uVar11 = ae_l32x2_x(puVar20[8]);
              uVar10 = ae_l32_ip(*(undefined4 *)(param_3 + 1));
              uVar17 = ae_l32_i(*(undefined4 *)((int)param_3 + 0xc));
              uVar37 = maddn_s((ulonglong)(uint)((float)uVar9 * (float)uVar16),uVar18,uVar23);
              uVar18 = ae_l32x2_x(puVar20[9]);
              uVar9 = ae_sel16i(uVar10,uVar36,1);
              uVar16 = ae_l32x2_i(uVar15);
              uVar35 = maddn_s(uVar35,uVar38,uVar24);
              uVar10 = ae_l32x2_i(uVar14);
              uVar32 = maddn_s((ulonglong)(uint)((float)uVar27 * (float)uVar25),uVar32,uVar24);
              uVar26 = ae_l32x2_i(puVar20[5]);
              uVar27 = ae_l32x2_i(puVar20[4]);
              uVar34 = maddn_s((ulonglong)(uint)((float)uVar28 * (float)uVar34),uVar16,uVar23);
              uVar23 = (ulonglong)(uint)((float)uVar9 - (float)uVar37);
              uVar38 = ae_l32x2_i(*puVar20);
              uVar28 = ae_l32x2_i(puVar20[6]);
              uVar16 = maddn_s((ulonglong)(uint)((float)uVar29 * (float)uVar25),uVar10,uVar24);
              uVar1 = ae_s32_l_i(uVar35);
              *(undefined4 *)((int)puVar12 + 4) = uVar1;
              uVar29 = ae_l32x2_i(puVar20[7]);
              uVar9 = ae_sel16i_n(uVar36,uVar35,0);
              uVar15 = ae_l32x2_i(uVar15);
              uVar25 = (ulonglong)(uint)((float)uVar9 - (float)uVar32);
              uVar24 = (ulonglong)(uint)((float)uVar26 * fVar22);
              uStack_80 = ae_s32x2_i(uVar23);
              uVar9 = ae_l32x2_i(puVar20[1]);
              uVar10 = maddn_s(uVar34,uVar38,uVar23);
              in_aed7 = ae_l32x2_i(uVar14);
              uVar14 = maddn_s((ulonglong)(uint)((float)uVar11 * fVar2),uVar28,uVar23);
              fVar31 = (float)uVar14;
              uVar38 = ae_l32x2_i(puVar20[1]);
              uVar26 = ae_l32x2_i(*puVar20);
              uVar11 = maddn_s((ulonglong)(uint)((float)uVar27 * fVar2),uVar15,uVar23);
              uVar15 = maddn_s((ulonglong)(uint)((float)uVar18 * fVar22),uVar29,uVar25);
              fVar22 = (float)uVar15;
            }
            uVar9 = maddn_s(uVar16,uVar9,uVar25);
            uVar15 = ae_sel16i(uVar10,uVar9,0);
            uVar14 = maddn_s(uVar24,in_aed7,uVar25);
            uVar24 = (ulonglong)(uint)((float)uVar15 - fVar22);
            uVar15 = ae_sel16i(uVar17,uVar10,1);
            uVar10 = maddn_s(uVar14,uVar38,uVar24);
            uVar23 = (ulonglong)(uint)((float)uVar15 - fVar31);
            uVar1 = ae_s32_l_ip(uVar9);
            *(undefined4 *)puVar3 = uVar1;
            uVar1 = ae_s32_l_i(uVar10);
            *(undefined4 *)((int)puVar3 + 4) = uVar1;
            uVar15 = ae_l32x2_i(uStack_80);
            uVar9 = maddn_s(uVar11,uVar26,uVar23);
          }
        }
        uVar9 = ae_s32x2_ip(uVar9);
        *puVar19 = uVar9;
        uVar9 = ae_s32x2_ip(uVar10);
        puVar19[1] = uVar9;
        uVar9 = ae_s32x2_ip(uVar23);
        puVar19[2] = uVar9;
        uVar9 = ae_s32x2_ip(uVar24);
        puVar19[3] = uVar9;
        uVar15 = ae_s32x2_ip(uVar15);
        puVar19[4] = uVar15;
        puVar20 = puVar20 + 10;
        uVar15 = ae_s32x2_ip(uVar25);
        puVar19[5] = uVar15;
        puVar19 = puVar19 + 6;
        param_3 = param_2;
      } while ((int)uVar7 >> 2 != iVar21);
    }
    uVar5 = uVar7 & 3;
    puStack_28 = (undefined4 *)(uVar5 * 4 + (int)puVar20);
    puVar4 = puStack_28 + uVar5;
    uVar13 = uVar7 & 0xfffffffc;
    puVar8 = puVar4 + uVar5;
    puVar6 = puVar8 + uVar5;
    if ((int)uVar13 < (int)uVar7) {
      do {
        uVar14 = ae_l32_ip(*(undefined4 *)puVar20);
        puVar20 = (undefined8 *)((int)puVar20 + 4);
        uVar11 = ae_l32_ip(*puVar4);
        puVar4 = puVar4 + 1;
        uVar17 = ae_l32_ip(*puVar6);
        puVar6 = puVar6 + 1;
        uVar16 = ae_l32_ip(*puVar8);
        puVar8 = puVar8 + 1;
        uVar15 = ae_l32_ip(*(undefined4 *)puVar30);
        uVar10 = ae_l32_ip(*(undefined4 *)((int)puVar30 + 4));
        uVar26 = ae_l32_ip(*puStack_28);
        puStack_28 = puStack_28 + 1;
        uVar9 = ae_l32_ip(*(undefined4 *)(puVar30 + 1));
        puVar30 = (undefined8 *)((int)puVar30 + 0xc);
        uVar25 = (ulonglong)(uint)-(float)uVar16;
        if (0 < (int)param_4) {
          uVar5 = param_4 & 3;
          fVar22 = (float)uVar11;
          puVar12 = param_2;
          if ((uVar5 != 0) && ((uVar5 == 1 || (uVar5 != 0)))) {
            uVar15 = ae_l32_ip(*(undefined4 *)param_3);
            param_3 = (undefined8 *)((int)param_3 + 4);
            uVar11 = msubn_s(uVar15,uVar17,uVar9);
            uVar15 = maddn_s((ulonglong)(uint)(fVar22 * (float)uVar9),uVar26,uVar10);
            uVar11 = maddn_s(uVar11,uVar25,uVar10);
            in_aed7 = maddn_s(uVar15,uVar14,uVar11);
            uVar1 = ae_s32_l_ip(in_aed7);
            *(undefined4 *)param_2 = uVar1;
            puVar12 = (undefined8 *)((int)param_2 + 4);
            uVar9 = ae_mov(uVar10);
            uVar10 = ae_mov(uVar11);
          }
          if ((int)param_4 >> 2 != 0) {
            uVar15 = ae_l32_ip(*(undefined4 *)param_3);
            uVar11 = msubn_s(uVar15,uVar17,uVar9);
            uVar15 = ae_l32_i(*(undefined4 *)((int)param_3 + 4));
            uVar11 = maddn_s(uVar11,uVar25,uVar10);
            uVar16 = msubn_s(uVar15,uVar17,uVar10);
            uVar9 = maddn_s((ulonglong)(uint)(fVar22 * (float)uVar9),uVar26,uVar10);
            uVar15 = ae_l32_i(*(undefined4 *)(param_3 + 1));
            uVar38 = maddn_s(uVar16,uVar25,uVar11);
            uVar16 = msubn_s(uVar15,uVar17,uVar11);
            uVar18 = maddn_s((ulonglong)(uint)(fVar22 * (float)uVar10),uVar26,uVar11);
            uVar15 = maddn_s(uVar9,uVar14,uVar11);
            uVar9 = maddn_s(uVar16,uVar25,uVar38);
            uVar10 = ae_l32_i(*(undefined4 *)((int)param_3 + 0xc));
            uVar16 = maddn_s((ulonglong)(uint)(fVar22 * (float)uVar11),uVar26,uVar38);
            uVar1 = ae_s32_l_ip(uVar15);
            *(undefined4 *)puVar12 = uVar1;
            puVar3 = puVar12 + 2;
            uVar11 = maddn_s(uVar18,uVar14,uVar38);
            uVar15 = msubn_s(uVar10,uVar17,uVar38);
            uVar24 = (ulonglong)(uint)(fVar22 * (float)uVar38);
            if (0 < ((int)param_4 >> 2) + -1) {
              uVar10 = ae_l32_ip(*(undefined4 *)(param_3 + 2));
              uVar38 = ae_l32_i(*(undefined4 *)((int)param_3 + 0x14));
              uVar18 = maddn_s(uVar15,uVar25,uVar9);
              uVar27 = msubn_s(uVar10,uVar17,uVar9);
              uVar1 = ae_s32_l_i(uVar11);
              *(undefined4 *)((int)puVar12 + 4) = uVar1;
              uVar11 = maddn_s(uVar24,uVar26,uVar9);
              uVar15 = ae_l32_i(*(undefined4 *)(param_3 + 3));
              uVar10 = maddn_s(uVar16,uVar14,uVar9);
              uVar16 = maddn_s(uVar27,uVar25,uVar18);
              uVar38 = msubn_s(uVar38,uVar17,uVar18);
              uVar9 = maddn_s((ulonglong)(uint)(fVar22 * (float)uVar9),uVar26,uVar18);
              uVar1 = ae_s32_l_i(uVar10);
              *(undefined4 *)(puVar12 + 1) = uVar1;
              uVar10 = ae_l32_i(*(undefined4 *)((int)param_3 + 0x1c));
              uVar11 = maddn_s(uVar11,uVar14,uVar18);
              uVar38 = maddn_s(uVar38,uVar25,uVar16);
              uVar15 = msubn_s(uVar15,uVar17,uVar16);
              uVar18 = maddn_s((ulonglong)(uint)(fVar22 * (float)uVar18),uVar26,uVar16);
              uVar1 = ae_s32_l_i(uVar11);
              *(undefined4 *)((int)puVar12 + 0xc) = uVar1;
              uVar27 = maddn_s(uVar9,uVar14,uVar16);
              uVar9 = maddn_s(uVar15,uVar25,uVar38);
              uVar15 = msubn_s(uVar10,uVar17,uVar38);
              uVar11 = maddn_s(uVar18,uVar14,uVar38);
              uVar24 = (ulonglong)(uint)(fVar22 * (float)uVar38);
              uVar1 = ae_s32_l_ip(uVar27);
              *(undefined4 *)puVar3 = uVar1;
              puVar3 = puVar12 + 4;
              uVar16 = maddn_s((ulonglong)(uint)(fVar22 * (float)uVar16),uVar26,uVar38);
            }
            uVar10 = maddn_s(uVar15,uVar25,uVar9);
            uVar17 = maddn_s(uVar24,uVar26,uVar9);
            uVar15 = maddn_s(uVar16,uVar14,uVar9);
            in_aed7 = maddn_s(uVar17,uVar14,uVar10);
            uVar1 = ae_s32_l_i(uVar11);
            *(undefined4 *)((int)puVar3 + -0xc) = uVar1;
            uVar1 = ae_s32_l_i(uVar15);
            *(undefined4 *)(puVar3 + -1) = uVar1;
            uVar1 = ae_s32_l_i(in_aed7);
            *(undefined4 *)((int)puVar3 + -4) = uVar1;
          }
          uVar15 = ae_mov(in_aed7);
        }
        uVar1 = ae_s32_l_ip(uVar15);
        *(undefined4 *)puVar19 = uVar1;
        uVar1 = ae_s32_l_ip(uVar10);
        *(undefined4 *)((int)puVar19 + 4) = uVar1;
        uVar1 = ae_s32_l_ip(uVar9);
        *(undefined4 *)(puVar19 + 1) = uVar1;
        puVar19 = (undefined8 *)((int)puVar19 + 0xc);
        uVar13 = uVar13 + 1;
        param_3 = param_2;
      } while (uVar7 != uVar13);
    }
    fVar22 = (float)(((int)(short)param_1[2] + 0x7fU & 0xff) << 0x17);
    if (((uint)param_2 & 7) != 0) {
      uVar15 = ae_l32_ip(*(undefined4 *)param_3);
      param_3 = (undefined8 *)((int)param_3 + 4);
      iVar21 = param_4 * 4 + -8;
      uVar9 = ae_l32_x(*(undefined4 *)((int)param_3 + iVar21));
      uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar15 * fVar22));
      *(undefined4 *)param_2 = uVar1;
      param_2 = (undefined8 *)((int)param_2 + 4);
      param_4 = param_4 - 2;
      uVar1 = ae_s32_l_x((ulonglong)(uint)((float)uVar9 * fVar22));
      *(undefined4 *)((int)param_2 + iVar21) = uVar1;
    }
    if (0 < (int)param_4 >> 1) {
      uVar15 = ae_movda32x2(fVar22,fVar22);
      uVar7 = param_4 >> 1 & 3;
      fVar22 = (float)uVar15;
      if ((uVar7 != 0) && ((uVar7 == 1 || (uVar7 != 0)))) {
        uVar15 = ae_l32x2_ip(*param_3);
        param_3 = param_3 + 1;
        uVar15 = ae_s32x2_ip((ulonglong)(uint)((float)uVar15 * fVar22));
        *param_2 = uVar15;
        param_2 = param_2 + 1;
      }
      iVar21 = (int)param_4 >> 3;
      if (iVar21 != 0) {
        uVar15 = ae_l32x2_ip(*param_3);
        uVar9 = ae_l32x2_i(param_3[1]);
        uVar10 = ae_l32x2_i(param_3[2]);
        uVar15 = ae_s32x2_ip((ulonglong)(uint)((float)uVar15 * fVar22));
        *param_2 = uVar15;
        puVar30 = param_2 + 4;
        uVar15 = ae_s32x2_i((ulonglong)(uint)((float)uVar9 * fVar22));
        param_2[1] = uVar15;
        uVar15 = ae_s32x2_i((ulonglong)(uint)((float)uVar10 * fVar22));
        param_2[2] = uVar15;
        uVar15 = ae_l32x2_i(param_3[3]);
        uVar25 = (ulonglong)(uint)((float)uVar15 * fVar22);
        if (iVar21 < 2) {
          uVar15 = ae_s32x2_i(uVar25);
          param_2[3] = uVar15;
          return;
        }
        uVar15 = ae_l32x2_ip(param_3[4]);
        uVar9 = ae_l32x2_i(param_3[6]);
        uVar10 = ae_l32x2_i(param_3[5]);
        iVar21 = iVar21 + -2;
        uVar24 = (ulonglong)(uint)((float)uVar15 * fVar22);
        uVar33 = (ulonglong)(uint)((float)uVar9 * fVar22);
        uVar15 = ae_l32x2_i(param_3[7]);
        uVar23 = (ulonglong)(uint)((float)uVar10 * fVar22);
        fVar31 = (float)uVar15;
        if ((0 < iVar21) && ((iVar21 == 1 || (0 < iVar21)))) {
          uVar15 = ae_s32x2_i(uVar25);
          param_2[3] = uVar15;
          uVar9 = ae_l32x2_ip(param_3[8]);
          uVar25 = (ulonglong)(uint)(fVar31 * fVar22);
          uVar15 = ae_s32x2_ip(uVar24);
          *puVar30 = uVar15;
          puVar30 = param_2 + 8;
          uVar10 = ae_l32x2_i(param_3[9]);
          uVar24 = (ulonglong)(uint)((float)uVar9 * fVar22);
          uVar15 = ae_s32x2_i(uVar23);
          param_2[5] = uVar15;
          uVar9 = ae_l32x2_i(param_3[10]);
          uVar23 = (ulonglong)(uint)((float)uVar10 * fVar22);
          uVar15 = ae_s32x2_i(uVar33);
          param_2[6] = uVar15;
          uVar15 = ae_l32x2_i(param_3[0xb]);
          uVar33 = (ulonglong)(uint)((float)uVar9 * fVar22);
          fVar31 = (float)uVar15;
        }
        uVar15 = ae_s32x2_i(uVar25);
        puVar30[-1] = uVar15;
        uVar15 = ae_s32x2_ip(uVar24);
        *puVar30 = uVar15;
        uVar15 = ae_s32x2_i(uVar23);
        puVar30[1] = uVar15;
        uVar15 = ae_s32x2_i(uVar33);
        puVar30[2] = uVar15;
        uVar15 = ae_s32x2_i((ulonglong)(uint)(fVar31 * fVar22));
        puVar30[3] = uVar15;
        return;
      }
    }
  }
  return;
}


// ===== f2i_scaled @ 00234710 (31 bytes)

/* trunc(x * 2^-s) */

undefined4 f2i_scaled(int param_1)

{
  float in_aed0;
  undefined4 uVar1;
  
  uVar1 = trunc_s((ulonglong)(uint)(in_aed0 * (float)((0x7f - param_1) * 0x800000)),0);
  return uVar1;
}


// ===== i2f_scaled @ 00234730 (25 bytes)

/* float(i) * 2^s; s = -1 turns half-dB registers into dB */

void i2f_scaled(undefined4 param_1)

{
  float_s(param_1,0);
  return;
}


// ===== FUN_00234750 @ 00234750 (309 bytes)

void FUN_00234750(undefined4 *param_1,undefined8 *param_2,int param_3,uint param_4)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  float fVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar11;
  ulonglong uVar12;
  undefined8 uVar10;
  
  if (0 < (int)param_4) {
    if (((uint)param_2 & 7) != 0) {
      uVar3 = ae_movda32((0x7f - param_3) * 0x800000);
      uVar8 = ae_l32_x(*(undefined4 *)param_2);
      uVar3 = ae_sel16i(uVar3,uVar3,3);
      uVar5 = trunc_s((ulonglong)(uint)((float)uVar8 * (float)uVar3),0);
      uVar3 = ae_movda32(uVar5);
      param_4 = param_4 - 1;
      uVar5 = ae_s32_l_ip(uVar3);
      *param_1 = uVar5;
      param_1 = param_1 + 1;
      ae_l32_ip(*(undefined4 *)param_2);
      param_2 = (undefined8 *)((int)param_2 + 4);
    }
    uVar3 = ae_zalign64();
    puVar1 = param_2;
    if (0 < (int)param_4 >> 1) {
      iVar6 = (int)param_4 >> 2;
      uVar8 = ae_movda32((0x7f - param_3) * 0x800000);
      fVar4 = (float)uVar8;
      if ((param_4 >> 1 & 1) != 0) {
        uVar8 = ae_l32x2_ip(*param_2);
        param_2 = param_2 + 1;
        uVar9 = trunc_sx2((ulonglong)(uint)((float)uVar8 * fVar4),0);
        uVar8 = ae_sa32x2_ip(uVar9,uVar3,param_1);
        param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar9,uVar3,param_1);
        uVar3 = uVar8;
      }
      puVar1 = param_2;
      if (iVar6 != 0) {
        uVar9 = ae_l32x2_ip(*param_2);
        puVar1 = param_2 + 2;
        uVar8 = ae_l32x2_i(param_2[1]);
        uVar2 = (ulonglong)(uint)((float)uVar8 * fVar4);
        uVar8 = trunc_sx2((ulonglong)(uint)((float)uVar9 * fVar4),0);
        if (1 < iVar6) {
          uVar9 = ae_l32x2_ip(*puVar1);
          puVar1 = param_2 + 4;
          iVar6 = iVar6 + -2;
          uVar10 = ae_l32x2_i(param_2[3]);
          fVar7 = (float)uVar10;
          uVar12 = (ulonglong)(uint)((float)uVar9 * fVar4);
          if ((0 < iVar6) && ((iVar6 == 1 || (0 < iVar6)))) {
            uVar9 = ae_sa32x2_ip(uVar8,uVar3,param_1);
            uVar5 = ae_sa32x2_ip_1(uVar8,uVar3,param_1);
            uVar3 = ae_l32x2_ip(*puVar1);
            puVar1 = param_2 + 6;
            uVar10 = trunc_sx2(uVar2,0);
            uVar8 = ae_l32x2_i(param_2[5]);
            uVar2 = (ulonglong)(uint)(fVar7 * fVar4);
            fVar7 = (float)uVar8;
            uVar8 = trunc_sx2(uVar12,0);
            uVar12 = (ulonglong)(uint)((float)uVar3 * fVar4);
            uVar3 = ae_sa32x2_ip(uVar10,uVar9,uVar5);
            param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar10,uVar9,uVar5);
          }
          uVar10 = trunc_sx2(uVar2,0);
          uVar11 = ae_mov(uVar8);
          uVar2 = (ulonglong)(uint)(fVar7 * fVar4);
          uVar8 = trunc_sx2(uVar12,0);
          uVar9 = ae_sa32x2_ip(uVar11,uVar3,param_1);
          uVar5 = ae_sa32x2_ip_1(uVar11,uVar3,param_1);
          uVar3 = ae_sa32x2_ip(uVar10,uVar9,uVar5);
          param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar10,uVar9,uVar5);
        }
        uVar10 = trunc_sx2(uVar2,0);
        uVar9 = ae_sa32x2_ip(uVar8,uVar3,param_1);
        uVar5 = ae_sa32x2_ip_1(uVar8,uVar3,param_1);
        uVar3 = ae_sa32x2_ip(uVar10,uVar9,uVar5);
        param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar10,uVar9,uVar5);
      }
    }
    ae_sa64pos_fp(uVar3,param_1);
    if ((param_4 & 1) != 0) {
      uVar3 = ae_movda32((0x7f - param_3) * 0x800000);
      uVar8 = ae_l32_x(*(undefined4 *)puVar1);
      uVar3 = ae_sel16i(uVar3,uVar3,3);
      uVar5 = trunc_s((ulonglong)(uint)((float)uVar8 * (float)uVar3),0);
      *param_1 = uVar5;
      return;
    }
  }
  return;
}


// ===== FUN_00234890 @ 00234890 (347 bytes)

void FUN_00234890(undefined4 *param_1,undefined8 *param_2,int param_3,uint param_4)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  
  if (0 < (int)param_4) {
    uVar5 = ae_zalign64();
    if (((uint)param_2 & 7) != 0) {
      uVar6 = float_s(*(undefined4 *)param_2,0);
      uVar11 = ae_movda32((param_3 + 0x7f) * 0x800000);
      uVar11 = ae_sel16i(uVar11,uVar11,3);
      param_4 = param_4 - 1;
      uVar9 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * (float)uVar11));
      *param_1 = uVar9;
      param_1 = param_1 + 1;
      ae_l32_ip(*(undefined4 *)param_2);
      param_2 = (undefined8 *)((int)param_2 + 4);
    }
    puVar1 = param_2;
    if (0 < (int)param_4 >> 1) {
      uVar11 = ae_movda32((param_3 + 0x7f) * 0x800000);
      iVar10 = (int)param_4 >> 2;
      fVar3 = (float)uVar11;
      if ((param_4 >> 1 & 1) != 0) {
        uVar11 = ae_l32x2_ip(*param_2);
        param_2 = param_2 + 1;
        uVar11 = float_sx2(uVar11,0);
        uVar2 = (ulonglong)(uint)((float)uVar11 * fVar3);
        uVar11 = ae_sa32x2_ip(uVar2,uVar5,param_1);
        param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar2,uVar5,param_1);
        uVar5 = uVar11;
      }
      puVar1 = param_2;
      if (iVar10 != 0) {
        uVar11 = ae_l32x2_ip(*param_2);
        puVar1 = param_2 + 2;
        uVar11 = float_sx2(uVar11,0);
        uVar6 = ae_l32x2_i(param_2[1]);
        uVar12 = (ulonglong)(uint)((float)uVar11 * fVar3);
        uVar11 = float_sx2(uVar6,0);
        uVar2 = (ulonglong)(uint)((float)uVar11 * fVar3);
        uVar11 = ae_sa32x2_ip(uVar12,uVar5,param_1);
        uVar9 = ae_sa32x2_ip_1(uVar12,uVar5,param_1);
        if (1 < iVar10) {
          uVar5 = ae_l32x2_ip(*puVar1);
          puVar1 = param_2 + 4;
          uVar5 = float_sx2(uVar5,0);
          uVar6 = ae_l32x2_i(param_2[3]);
          uVar6 = float_sx2(uVar6,0);
          fVar4 = (float)uVar6;
          uVar12 = (ulonglong)(uint)((float)uVar5 * fVar3);
          if (2 < iVar10) {
            uVar5 = ae_l32x2_ip(*puVar1);
            puVar1 = param_2 + 6;
            iVar10 = iVar10 + -3;
            uVar6 = ae_l32x2_i(param_2[5]);
            if ((0 < iVar10) && ((iVar10 == 1 || (0 < iVar10)))) {
              uVar7 = float_sx2(uVar5,0);
              uVar5 = ae_l32x2_ip(*puVar1);
              puVar1 = param_2 + 8;
              uVar8 = ae_sa32x2_ip(uVar2,uVar11,uVar9);
              uVar9 = ae_sa32x2_ip_1(uVar2,uVar11,uVar9);
              uVar2 = (ulonglong)(uint)(fVar4 * fVar3);
              uVar11 = float_sx2(uVar6,0);
              uVar6 = ae_l32x2_i(param_2[7]);
              fVar4 = (float)uVar11;
              uVar11 = ae_sa32x2_ip(uVar12,uVar8,uVar9);
              uVar9 = ae_sa32x2_ip_1(uVar12,uVar8,uVar9);
              uVar12 = (ulonglong)(uint)((float)uVar7 * fVar3);
            }
            uVar8 = float_sx2(uVar5,0);
            uVar5 = ae_sa32x2_ip(uVar2,uVar11,uVar9);
            uVar9 = ae_sa32x2_ip_1(uVar2,uVar11,uVar9);
            uVar11 = float_sx2(uVar6,0);
            uVar2 = (ulonglong)(uint)(fVar4 * fVar3);
            fVar4 = (float)uVar11;
            uVar11 = ae_sa32x2_ip(uVar12,uVar5,uVar9);
            uVar9 = ae_sa32x2_ip_1(uVar12,uVar5,uVar9);
            uVar12 = (ulonglong)(uint)((float)uVar8 * fVar3);
          }
          uVar5 = ae_sa32x2_ip(uVar2,uVar11,uVar9);
          uVar9 = ae_sa32x2_ip_1(uVar2,uVar11,uVar9);
          uVar2 = (ulonglong)(uint)(fVar4 * fVar3);
          uVar11 = ae_sa32x2_ip(uVar12,uVar5,uVar9);
          uVar9 = ae_sa32x2_ip_1(uVar12,uVar5,uVar9);
        }
        uVar5 = ae_sa32x2_ip(uVar2,uVar11,uVar9);
        param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar2,uVar11,uVar9);
      }
    }
    ae_sa64pos_fp(uVar5,param_1);
    if ((param_4 & 1) != 0) {
      uVar11 = float_s(*(undefined4 *)puVar1,0);
      uVar5 = ae_movda32((param_3 + 0x7f) * 0x800000);
      uVar5 = ae_sel16i(uVar5,uVar5,3);
      uVar9 = ae_s32_l_i((ulonglong)(uint)((float)uVar11 * (float)uVar5));
      *param_1 = uVar9;
      return;
    }
  }
  return;
}


// ===== FUN_002349f0 @ 002349f0 (341 bytes)

void FUN_002349f0(undefined4 *param_1,undefined8 *param_2,undefined4 param_3,uint param_4)

{
  float fVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 *puVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  
  if (0 < (int)param_4) {
    uVar7 = ae_zalign64();
    iVar12 = (int)param_4 >> 2;
    if (((uint)param_2 & 7) == 0) {
      uVar8 = ae_la64_pp(param_3);
      uVar3 = ae_la32x2_ip(uVar8,param_3);
      uVar2 = ae_la32x2_ip_1(uVar8,param_3);
      uVar10 = ae_la32x2_ip_2(uVar8,param_3);
      fVar4 = (float)uVar3;
      uVar3 = ae_l32x2_ip(*param_2);
      puVar17 = param_2 + 1;
      fVar5 = (float)uVar3;
      if (1 < (int)param_4) {
        uVar3 = uVar2;
        if ((param_4 >> 1 & 1) != 0) {
          fVar5 = fVar5 + fVar4;
          uVar3 = ae_la32x2_ip(uVar2,uVar10);
          fVar4 = (float)uVar3;
          uVar3 = ae_la32x2_ip_1(uVar2,uVar10);
          uVar10 = ae_la32x2_ip_2(uVar2,uVar10);
          uVar2 = ae_sa32x2_ip((ulonglong)(uint)fVar5,uVar7,param_1);
          param_1 = (undefined4 *)ae_sa32x2_ip_1((ulonglong)(uint)fVar5,uVar7,param_1);
          uVar7 = ae_l32x2_ip(*puVar17);
          fVar5 = (float)uVar7;
          puVar17 = param_2 + 2;
          uVar7 = uVar2;
        }
        iVar13 = iVar12 + -1;
        if (iVar12 != 0) {
          uVar2 = ae_la32x2_ip(uVar3,uVar10);
          uVar8 = ae_la32x2_ip_1(uVar3,uVar10);
          uVar10 = ae_la32x2_ip_2(uVar3,uVar10);
          uVar3 = ae_la32x2_ip(uVar8,uVar10);
          fVar1 = (float)uVar3;
          uVar3 = ae_la32x2_ip_1(uVar8,uVar10);
          uVar10 = ae_la32x2_ip_2(uVar8,uVar10);
          uVar8 = ae_l32x2_ip(*puVar17);
          uVar18 = (ulonglong)(uint)(fVar5 + fVar4);
          uVar14 = ae_l32x2_i(puVar17[1]);
          fVar5 = (float)uVar14;
          uVar6 = (ulonglong)(uint)((float)uVar8 + (float)uVar2);
          fVar4 = fVar1;
          if ((0 < iVar13) && ((iVar13 == 1 || (0 < iVar13)))) {
            uVar2 = ae_la32x2_ip(uVar3,uVar10);
            uVar8 = ae_la32x2_ip_1(uVar3,uVar10);
            uVar10 = ae_la32x2_ip_2(uVar3,uVar10);
            uVar3 = ae_sa32x2_ip(uVar18,uVar7,param_1);
            uVar11 = ae_sa32x2_ip_1(uVar18,uVar7,param_1);
            uVar14 = ae_l32x2_ip(puVar17[2]);
            uVar18 = (ulonglong)(uint)(fVar5 + fVar1);
            uVar7 = ae_la32x2_ip(uVar8,uVar10);
            ae_la32x2_ip_1(uVar8,uVar10);
            ae_la32x2_ip_2(uVar8,uVar10);
            fVar4 = (float)uVar7;
            uVar7 = ae_sa32x2_ip(uVar6,uVar3,uVar11);
            param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar6,uVar3,uVar11);
            uVar3 = ae_l32x2_i(puVar17[3]);
            uVar6 = (ulonglong)(uint)((float)uVar14 + (float)uVar2);
            fVar5 = (float)uVar3;
          }
          uVar3 = ae_sa32x2_ip(uVar18,uVar7,param_1);
          uVar10 = ae_sa32x2_ip_1(uVar18,uVar7,param_1);
          uVar7 = ae_sa32x2_ip(uVar6,uVar3,uVar10);
          param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar6,uVar3,uVar10);
        }
      }
    }
    else {
      uVar2 = ae_l32_ip(*(undefined4 *)param_2);
      uVar8 = ae_la64_pp(param_3);
      uVar14 = ae_l32x2_ip(*(undefined8 *)((int)param_2 + 4));
      puVar17 = (undefined8 *)((int)param_2 + 0xc);
      uVar3 = ae_la32x2_ip(uVar8,param_3);
      fVar4 = (float)uVar3;
      uVar3 = ae_la32x2_ip_1(uVar8,param_3);
      uVar10 = ae_la32x2_ip_2(uVar8,param_3);
      uVar2 = ae_sel16i(uVar2,uVar14,0);
      fVar5 = (float)uVar2;
      if (1 < (int)param_4) {
        uVar8 = uVar14;
        uVar2 = uVar3;
        if ((param_4 >> 1 & 1) != 0) {
          fVar5 = fVar5 + fVar4;
          uVar2 = ae_la32x2_ip(uVar3,uVar10);
          fVar4 = (float)uVar2;
          uVar2 = ae_la32x2_ip_1(uVar3,uVar10);
          uVar10 = ae_la32x2_ip_2(uVar3,uVar10);
          uVar8 = ae_l32x2_ip(*puVar17);
          puVar17 = (undefined8 *)((int)param_2 + 0x14);
          uVar14 = ae_mov(uVar14);
          uVar3 = ae_sa32x2_ip((ulonglong)(uint)fVar5,uVar7,param_1);
          param_1 = (undefined4 *)ae_sa32x2_ip_1((ulonglong)(uint)fVar5,uVar7,param_1);
          uVar7 = ae_sel16i(uVar14,uVar8,0);
          fVar5 = (float)uVar7;
          uVar7 = uVar3;
        }
        if (iVar12 != 0) {
          uVar14 = ae_la32x2_ip(uVar2,uVar10);
          uVar16 = ae_la32x2_ip_1(uVar2,uVar10);
          uVar10 = ae_la32x2_ip_2(uVar2,uVar10);
          uVar15 = ae_l32x2_ip(*puVar17);
          uVar8 = ae_sel16i(uVar8,uVar15,0);
          uVar3 = ae_la32x2_ip(uVar16,uVar10);
          uVar2 = ae_la32x2_ip_1(uVar16,uVar10);
          uVar11 = ae_la32x2_ip_2(uVar16,uVar10);
          uVar16 = ae_l32x2_i(puVar17[1]);
          uVar18 = (ulonglong)(uint)((float)uVar8 + (float)uVar14);
          uVar8 = ae_sa32x2_ip((ulonglong)(uint)(fVar5 + fVar4),uVar7,param_1);
          uVar10 = ae_sa32x2_ip_1((ulonglong)(uint)(fVar5 + fVar4),uVar7,param_1);
          uVar14 = ae_sel16i(uVar15,uVar16,0);
          if (1 < iVar12) {
            uVar15 = ae_la32x2_ip(uVar2,uVar11);
            uVar7 = ae_la32x2_ip_1(uVar2,uVar11);
            uVar11 = ae_la32x2_ip_2(uVar2,uVar11);
            fVar5 = (float)uVar15;
            uVar6 = (ulonglong)(uint)((float)uVar14 + (float)uVar3);
            uVar3 = ae_l32x2_ip(puVar17[2]);
            uVar14 = ae_l32x2_i(puVar17[3]);
            iVar12 = iVar12 + -2;
            uVar2 = ae_sel16i_n(uVar16,uVar3,0);
            fVar4 = (float)uVar2;
            uVar2 = uVar3;
            if ((0 < iVar12) && ((iVar12 == 1 || (0 < iVar12)))) {
              uVar16 = ae_sa32x2_ip(uVar18,uVar8,uVar10);
              uVar9 = ae_sa32x2_ip_1(uVar18,uVar8,uVar10);
              uVar2 = ae_l32x2_ip(puVar17[4]);
              uVar18 = (ulonglong)(uint)(fVar4 + fVar5);
              uVar19 = ae_sel16i(uVar3,uVar14,0);
              uVar15 = ae_la32x2_ip(uVar7,uVar11);
              uVar8 = ae_la32x2_ip_1(uVar7,uVar11);
              uVar10 = ae_la32x2_ip_2(uVar7,uVar11);
              uVar3 = ae_la32x2_ip(uVar8,uVar10);
              uVar7 = ae_la32x2_ip_1(uVar8,uVar10);
              uVar11 = ae_la32x2_ip_2(uVar8,uVar10);
              uVar8 = ae_sel16i(uVar14,uVar2,0);
              fVar4 = (float)uVar8;
              fVar5 = (float)uVar3;
              uVar8 = ae_sa32x2_ip(uVar6,uVar16,uVar9);
              uVar10 = ae_sa32x2_ip_1(uVar6,uVar16,uVar9);
              uVar14 = ae_l32x2_i(puVar17[5]);
              uVar6 = (ulonglong)(uint)((float)uVar19 + (float)uVar15);
            }
            uVar16 = ae_sa32x2_ip(uVar18,uVar8,uVar10);
            uVar10 = ae_sa32x2_ip_1(uVar18,uVar8,uVar10);
            uVar18 = (ulonglong)(uint)(fVar4 + fVar5);
            uVar3 = ae_la32x2_ip(uVar7,uVar11);
            ae_la32x2_ip_1(uVar7,uVar11);
            ae_la32x2_ip_2(uVar7,uVar11);
            uVar8 = ae_sa32x2_ip(uVar6,uVar16,uVar10);
            uVar10 = ae_sa32x2_ip_1(uVar6,uVar16,uVar10);
            uVar14 = ae_sel16i(uVar2,uVar14,0);
          }
          uVar7 = ae_sa32x2_ip(uVar18,uVar8,uVar10);
          param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar18,uVar8,uVar10);
          uVar3 = ae_mov(uVar3);
          uVar2 = ae_mov(uVar14);
          fVar4 = (float)uVar3;
          fVar5 = (float)uVar2;
        }
      }
    }
    ae_sa64pos_fp(uVar7,param_1);
    if ((param_4 & 1) != 0) {
      uVar7 = ae_sel16i((ulonglong)(uint)(fVar5 + fVar4),(ulonglong)(uint)(fVar5 + fVar4),1);
      uVar10 = ae_s32_l_i(uVar7);
      *param_1 = uVar10;
      return;
    }
  }
  return;
}


// ===== FUN_00234b50 @ 00234b50 (130 bytes)

void FUN_00234b50(undefined8 *param_1,undefined4 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  
  uVar4 = const_s(0);
  ae_mov(uVar4);
  if ((int)param_3 < 1) {
    ae_mov(uVar4);
    return;
  }
  if (((uint)param_1 & 7) != 0) {
    param_3 = param_3 - 1;
    ae_l32_i(*param_2);
    ae_l32_i(*(undefined4 *)param_1);
    ae_l32_ip(*(undefined4 *)param_1);
    param_1 = (undefined8 *)((int)param_1 + 4);
    ae_l32_ip(*param_2);
    param_2 = param_2 + 1;
  }
  uVar2 = ae_la64_pp(param_2);
  iVar3 = (int)param_3 >> 1;
  if ((0 < iVar3) && ((iVar3 == 1 || (0 < iVar3)))) {
    uVar1 = ae_la32x2_ip(uVar2,param_2);
    ae_la32x2_ip_1(uVar2,param_2);
    param_2 = (undefined4 *)ae_la32x2_ip_2(uVar2,param_2);
    uVar2 = ae_l32x2_ip(*param_1);
    param_1 = param_1 + 1;
    uVar2 = ae_sel16i(uVar2,uVar2,2);
    uVar4 = (ulonglong)(uint)((float)uVar4 + (float)uVar2 * (float)uVar1);
  }
  if ((param_3 & 1) != 0) {
    ae_l32_i(*param_2);
    ae_l32_i(*(undefined4 *)param_1);
    ae_sel16i_n(uVar4,uVar4,0);
    return;
  }
  ae_sel16i(uVar4,uVar4,0);
  return;
}


// ===== vec_sum_sq @ 00234be0 (533 bytes)

/* sum of squares (madd.s loop) */

void vec_sum_sq(undefined8 *param_1,uint param_2)

{
  float fVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  float fVar10;
  undefined8 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  float fVar20;
  ulonglong uVar21;
  undefined8 uVar15;
  
  uVar21 = const_s(0);
  uVar15 = ae_mov(uVar21);
  fVar12 = (float)uVar15;
  if ((int)param_2 < 1) {
    ae_mov(uVar21);
    return;
  }
  uVar15 = ae_mov(uVar21);
  fVar10 = (float)uVar15;
  uVar15 = ae_mov(uVar21);
  fVar20 = (float)uVar15;
  uVar15 = ae_mov(uVar21);
  fVar4 = (float)uVar15;
  ae_mov(uVar21);
  uVar15 = ae_mov(uVar21);
  fVar6 = (float)uVar15;
  uVar15 = ae_mov(uVar21);
  fVar5 = (float)uVar15;
  uVar15 = ae_mov(uVar21);
  fVar13 = (float)uVar15;
  if (((uint)param_1 & 7) != 0) {
    ae_l32_i(*(undefined4 *)param_1);
    ae_l32_ip(*(undefined4 *)param_1);
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_2 = param_2 - 1;
  }
  puVar2 = param_1;
  if (0 < (int)param_2 >> 4) {
    if ((param_2 >> 4 & 1) != 0) {
      uVar7 = ae_l32x2_ip(*param_1);
      uVar3 = ae_l32x2_ip(param_1[1]);
      uVar15 = ae_l32x2_ip(param_1[2]);
      uVar9 = ae_l32x2_ip(param_1[3]);
      uVar8 = ae_l32x2_ip(param_1[4]);
      uVar11 = ae_l32x2_ip(param_1[5]);
      fVar4 = fVar4 + (float)uVar7 * (float)uVar7;
      fVar20 = fVar20 + (float)uVar3 * (float)uVar3;
      uVar3 = ae_l32x2_ip(param_1[6]);
      fVar10 = fVar10 + (float)uVar15 * (float)uVar15;
      uVar21 = (ulonglong)(uint)((float)uVar21 + (float)uVar9 * (float)uVar9);
      uVar15 = ae_l32x2_ip(param_1[7]);
      param_1 = param_1 + 8;
      fVar12 = fVar12 + (float)uVar8 * (float)uVar8;
      fVar13 = fVar13 + (float)uVar11 * (float)uVar11;
      fVar5 = fVar5 + (float)uVar3 * (float)uVar3;
      fVar6 = fVar6 + (float)uVar15 * (float)uVar15;
    }
    puVar2 = param_1;
    if ((int)param_2 >> 5 != 0) {
      uVar3 = ae_l32x2_ip(*param_1);
      uVar15 = ae_l32x2_i(param_1[3]);
      uVar7 = ae_l32x2_i(param_1[1]);
      uVar16 = ae_l32x2_i(param_1[2]);
      uVar8 = ae_l32x2_i(param_1[4]);
      uVar17 = ae_l32x2_i(param_1[5]);
      uVar9 = ae_l32x2_i(param_1[6]);
      uVar18 = ae_l32x2_ip(param_1[7]);
      uVar11 = ae_l32x2_i(param_1[8]);
      fVar5 = fVar5 + (float)uVar9 * (float)uVar9;
      uVar9 = ae_l32x2_i(param_1[10]);
      uVar19 = ae_l32x2_i(param_1[9]);
      fVar6 = fVar6 + (float)uVar18 * (float)uVar18;
      fVar4 = fVar4 + (float)uVar3 * (float)uVar3 + (float)uVar11 * (float)uVar11;
      uVar3 = ae_l32x2_i(param_1[0xd]);
      uVar11 = ae_l32x2_i(param_1[0xc]);
      fVar20 = fVar20 + (float)uVar7 * (float)uVar7 + (float)uVar19 * (float)uVar19;
      fVar10 = fVar10 + (float)uVar16 * (float)uVar16 + (float)uVar9 * (float)uVar9;
      uVar7 = ae_l32x2_i(param_1[0xb]);
      fVar12 = fVar12 + (float)uVar8 * (float)uVar8 + (float)uVar11 * (float)uVar11;
      fVar13 = fVar13 + (float)uVar17 * (float)uVar17 + (float)uVar3 * (float)uVar3;
      uVar3 = ae_l32x2_ip(param_1[0xe]);
      fVar14 = (float)uVar3;
      puVar2 = param_1 + 0x10;
      fVar1 = (float)uVar21 + (float)uVar15 * (float)uVar15 + (float)uVar7 * (float)uVar7;
      if (0 < ((int)param_2 >> 5) + -1) {
        uVar15 = ae_l32x2_ip(*puVar2);
        uVar16 = ae_l32x2_i(param_1[0xf]);
        uVar3 = ae_l32x2_i(param_1[0x11]);
        uVar17 = ae_l32x2_i(param_1[0x12]);
        uVar7 = ae_l32x2_i(param_1[0x13]);
        uVar18 = ae_l32x2_i(param_1[0x14]);
        uVar8 = ae_l32x2_i(param_1[0x15]);
        uVar11 = ae_l32x2_i(param_1[0x16]);
        uVar9 = ae_l32x2_ip(param_1[0x17]);
        fVar5 = fVar5 + fVar14 * fVar14 + (float)uVar11 * (float)uVar11;
        uVar11 = ae_l32x2_i(param_1[0x18]);
        uVar19 = ae_l32x2_i(param_1[0x19]);
        fVar6 = fVar6 + (float)uVar16 * (float)uVar16 + (float)uVar9 * (float)uVar9;
        uVar9 = ae_l32x2_i(param_1[0x1a]);
        uVar16 = ae_l32x2_i(param_1[0x1b]);
        fVar4 = fVar4 + (float)uVar15 * (float)uVar15 + (float)uVar11 * (float)uVar11;
        fVar20 = fVar20 + (float)uVar3 * (float)uVar3 + (float)uVar19 * (float)uVar19;
        uVar15 = ae_l32x2_i(param_1[0x1c]);
        uVar11 = ae_l32x2_i(param_1[0x1d]);
        fVar10 = fVar10 + (float)uVar17 * (float)uVar17 + (float)uVar9 * (float)uVar9;
        fVar1 = fVar1 + (float)uVar7 * (float)uVar7 + (float)uVar16 * (float)uVar16;
        uVar3 = ae_l32x2_ip(param_1[0x1e]);
        puVar2 = param_1 + 0x20;
        fVar12 = fVar12 + (float)uVar18 * (float)uVar18 + (float)uVar15 * (float)uVar15;
        fVar13 = fVar13 + (float)uVar8 * (float)uVar8 + (float)uVar11 * (float)uVar11;
        fVar14 = (float)uVar3;
      }
      uVar21 = (ulonglong)(uint)fVar1;
      uVar15 = ae_l32x2_i(puVar2[-1]);
      fVar5 = fVar5 + fVar14 * fVar14;
      fVar6 = fVar6 + (float)uVar15 * (float)uVar15;
    }
  }
  if ((param_2 & 8) != 0) {
    uVar7 = ae_l32x2_ip(*puVar2);
    uVar3 = ae_l32x2_ip(puVar2[1]);
    uVar15 = ae_l32x2_ip(puVar2[2]);
    uVar8 = ae_l32x2_ip(puVar2[3]);
    puVar2 = puVar2 + 4;
    fVar4 = fVar4 + (float)uVar7 * (float)uVar7 + (float)uVar3 * (float)uVar3 +
            (float)uVar15 * (float)uVar15 + (float)uVar8 * (float)uVar8;
  }
  if ((param_2 & 4) != 0) {
    uVar3 = ae_l32x2_ip(*puVar2);
    uVar15 = ae_l32x2_ip(puVar2[1]);
    puVar2 = puVar2 + 2;
    fVar4 = fVar4 + (float)uVar3 * (float)uVar3 + (float)uVar15 * (float)uVar15;
  }
  if ((param_2 & 2) != 0) {
    uVar15 = ae_l32x2_ip(*puVar2);
    puVar2 = puVar2 + 1;
    fVar4 = fVar4 + (float)uVar15 * (float)uVar15;
  }
  if ((param_2 & 1) != 0) {
    uVar21 = (ulonglong)
             (uint)(fVar4 + fVar20 + (float)uVar21 + fVar10 + fVar12 + fVar13 + fVar5 + fVar6);
    ae_l32_i(*(undefined4 *)puVar2);
    ae_sel16i(uVar21,uVar21,0);
    return;
  }
  uVar21 = (ulonglong)
           (uint)(fVar4 + fVar20 + (float)uVar21 + fVar10 + fVar12 + fVar13 + fVar5 + fVar6);
  ae_sel16i(uVar21,uVar21,0);
  return;
}


// ===== FUN_00234e00 @ 00234e00 (315 bytes)

void FUN_00234e00(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 in_aed0;
  undefined8 in_aed1;
  undefined8 in_aed2;
  float fVar2;
  float fVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  
  uVar5 = ae_mov(in_aed2);
  uVar10 = ae_mov(in_aed1);
  uVar15 = ae_mov(in_aed0);
  if (0 < (int)param_3) {
    uVar4 = ae_zalign64();
    uVar6 = ae_la64_pp(param_2);
    uVar11 = ae_mov(in_aed2);
    uVar9 = ae_mov(in_aed1);
    fVar3 = (float)uVar15;
    if (0 < (int)param_3 >> 1) {
      iVar8 = (int)param_3 >> 2;
      uVar15 = uVar6;
      if ((param_3 >> 1 & 1) != 0) {
        uVar12 = ae_la32x2_ip(uVar6,param_2);
        uVar15 = ae_la32x2_ip_1(uVar6,param_2);
        param_2 = (undefined4 *)ae_la32x2_ip_2(uVar6,param_2);
        uVar6 = max_s((ulonglong)(uint)((float)uVar12 * (float)in_aed0),in_aed1);
        uVar12 = min_s(uVar6,uVar5);
        uVar6 = ae_sa32x2_ip(uVar12,uVar4,param_1);
        param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar12,uVar4,param_1);
        uVar4 = uVar6;
      }
      if (iVar8 != 0) {
        uVar6 = ae_la32x2_ip(uVar15,param_2);
        uVar12 = ae_la32x2_ip_1(uVar15,param_2);
        uVar7 = ae_la32x2_ip_2(uVar15,param_2);
        uVar15 = ae_la32x2_ip(uVar12,uVar7);
        uVar14 = ae_la32x2_ip_1(uVar12,uVar7);
        param_2 = (undefined4 *)ae_la32x2_ip_2(uVar12,uVar7);
        uVar6 = max_s((ulonglong)(uint)((float)uVar6 * fVar3),uVar9);
        uVar16 = (ulonglong)(uint)((float)uVar15 * fVar3);
        uVar15 = min_s(uVar6,uVar11);
        if (1 < iVar8) {
          uVar6 = ae_la32x2_ip(uVar14,param_2);
          uVar1 = ae_la32x2_ip_1(uVar14,param_2);
          uVar7 = ae_la32x2_ip_2(uVar14,param_2);
          iVar8 = iVar8 + -2;
          uVar12 = ae_la32x2_ip(uVar1,uVar7);
          uVar14 = ae_la32x2_ip_1(uVar1,uVar7);
          param_2 = (undefined4 *)ae_la32x2_ip_2(uVar1,uVar7);
          fVar2 = (float)uVar12;
          uVar13 = (ulonglong)(uint)((float)uVar6 * fVar3);
          if ((0 < iVar8) && ((iVar8 == 1 || (0 < iVar8)))) {
            uVar6 = ae_la32x2_ip(uVar14,param_2);
            uVar1 = ae_la32x2_ip_1(uVar14,param_2);
            uVar7 = ae_la32x2_ip_2(uVar14,param_2);
            uVar14 = max_s(uVar16,uVar9);
            uVar16 = (ulonglong)(uint)(fVar2 * fVar3);
            uVar12 = ae_la32x2_ip(uVar1,uVar7);
            ae_la32x2_ip_1(uVar1,uVar7);
            param_2 = (undefined4 *)ae_la32x2_ip_2(uVar1,uVar7);
            uVar14 = min_s(uVar14,uVar11);
            fVar2 = (float)uVar12;
            uVar12 = ae_sa32x2_ip(uVar15,uVar4,param_1);
            uVar7 = ae_sa32x2_ip_1(uVar15,uVar4,param_1);
            uVar15 = max_s(uVar13,uVar9);
            uVar13 = (ulonglong)(uint)((float)uVar6 * fVar3);
            uVar4 = ae_sa32x2_ip(uVar14,uVar12,uVar7);
            param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar14,uVar12,uVar7);
            uVar15 = min_s(uVar15,uVar11);
          }
          uVar12 = max_s(uVar16,uVar9);
          uVar16 = (ulonglong)(uint)(fVar2 * fVar3);
          uVar14 = max_s(uVar13,uVar9);
          uVar6 = ae_sa32x2_ip(uVar15,uVar4,param_1);
          uVar7 = ae_sa32x2_ip_1(uVar15,uVar4,param_1);
          uVar15 = min_s(uVar12,uVar11);
          uVar4 = ae_sa32x2_ip(uVar15,uVar6,uVar7);
          param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar15,uVar6,uVar7);
          uVar15 = min_s(uVar14,uVar11);
        }
        uVar9 = max_s(uVar16,uVar9);
        uVar6 = ae_sa32x2_ip(uVar15,uVar4,param_1);
        uVar7 = ae_sa32x2_ip_1(uVar15,uVar4,param_1);
        uVar15 = min_s(uVar9,uVar11);
        uVar4 = ae_sa32x2_ip(uVar15,uVar6,uVar7);
        param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar15,uVar6,uVar7);
      }
    }
    ae_sa64pos_fp(uVar4,param_1);
    if ((param_3 & 1) != 0) {
      uVar15 = ae_l32_i(*param_2);
      uVar10 = max_s((ulonglong)(uint)((float)uVar15 * fVar3),uVar10);
      uVar5 = min_s(uVar10,uVar5);
      uVar7 = ae_s32_l_i(uVar5);
      *param_1 = uVar7;
      return;
    }
  }
  return;
}


// ===== vec_scale_f32 @ 00234f40 (568 bytes)

/* y[i] = x[i] * scalar */

void vec_scale_f32(undefined4 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 in_aed0;
  undefined8 uVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  float fVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  float fVar21;
  undefined8 uVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  undefined8 uVar25;
  ulonglong uVar26;
  
  uVar5 = ae_zalign64();
  uVar22 = ae_mov(in_aed0);
  if (0 < (int)param_3) {
    fVar4 = (float)uVar22;
    iVar14 = (int)param_3 >> 3;
    if (((uint)param_2 & 7) == 0) {
      uVar22 = ae_l32x2_ip(*param_2);
      puVar1 = param_2 + 1;
      fVar21 = (float)uVar22;
      if (1 < (int)param_3) {
        uVar13 = param_3 >> 1 & 3;
        if ((uVar13 != 0) && ((uVar13 == 1 || (uVar13 != 0)))) {
          uVar22 = ae_sa32x2_ip((ulonglong)(uint)(fVar21 * fVar4),uVar5,param_1);
          param_1 = (undefined4 *)ae_sa32x2_ip_1((ulonglong)(uint)(fVar21 * fVar4),uVar5,param_1);
          uVar5 = ae_l32x2_ip(*puVar1);
          puVar1 = param_2 + 2;
          fVar21 = (float)uVar5;
          uVar5 = uVar22;
        }
        if (iVar14 != 0) {
          uVar22 = ae_l32x2_ip(*puVar1);
          uVar2 = ae_l32x2_i(puVar1[1]);
          uVar26 = (ulonglong)(uint)((float)uVar22 * fVar4);
          uVar22 = ae_sa32x2_ip((ulonglong)(uint)(fVar21 * fVar4),uVar5,param_1);
          uVar12 = ae_sa32x2_ip_1((ulonglong)(uint)(fVar21 * fVar4),uVar5,param_1);
          uVar5 = ae_l32x2_i(puVar1[2]);
          uVar16 = (ulonglong)(uint)((float)uVar2 * fVar4);
          uVar2 = ae_l32x2_i(puVar1[3]);
          uVar23 = (ulonglong)(uint)((float)uVar5 * fVar4);
          if (1 < iVar14) {
            uVar5 = ae_l32x2_ip(puVar1[4]);
            iVar14 = iVar14 + -2;
            fVar21 = (float)uVar5;
            uVar5 = ae_l32x2_i(puVar1[5]);
            fVar3 = (float)uVar5;
            uVar5 = ae_l32x2_i(puVar1[6]);
            fVar15 = (float)uVar5;
            uVar5 = ae_l32x2_i(puVar1[7]);
            uVar24 = (ulonglong)(uint)((float)uVar2 * fVar4);
            uVar2 = uVar5;
            if ((0 < iVar14) && ((iVar14 == 1 || (0 < iVar14)))) {
              uVar2 = ae_sa32x2_ip(uVar26,uVar22,uVar12);
              uVar12 = ae_sa32x2_ip_1(uVar26,uVar22,uVar12);
              uVar22 = ae_l32x2_ip(puVar1[8]);
              uVar26 = (ulonglong)(uint)(fVar21 * fVar4);
              fVar21 = (float)uVar22;
              uVar22 = ae_sa32x2_ip(uVar16,uVar2,uVar12);
              uVar12 = ae_sa32x2_ip_1(uVar16,uVar2,uVar12);
              uVar2 = ae_l32x2_i(puVar1[9]);
              uVar16 = (ulonglong)(uint)(fVar3 * fVar4);
              fVar3 = (float)uVar2;
              uVar2 = ae_sa32x2_ip(uVar23,uVar22,uVar12);
              uVar12 = ae_sa32x2_ip_1(uVar23,uVar22,uVar12);
              uVar22 = ae_l32x2_i(puVar1[10]);
              uVar23 = (ulonglong)(uint)(fVar15 * fVar4);
              fVar15 = (float)uVar22;
              uVar22 = ae_sa32x2_ip(uVar24,uVar2,uVar12);
              uVar12 = ae_sa32x2_ip_1(uVar24,uVar2,uVar12);
              uVar2 = ae_l32x2_i(puVar1[0xb]);
              uVar24 = (ulonglong)(uint)((float)uVar5 * fVar4);
            }
            uVar5 = ae_sa32x2_ip(uVar26,uVar22,uVar12);
            uVar12 = ae_sa32x2_ip_1(uVar26,uVar22,uVar12);
            uVar26 = (ulonglong)(uint)(fVar21 * fVar4);
            uVar22 = ae_sa32x2_ip(uVar16,uVar5,uVar12);
            uVar12 = ae_sa32x2_ip_1(uVar16,uVar5,uVar12);
            uVar16 = (ulonglong)(uint)(fVar3 * fVar4);
            uVar5 = ae_sa32x2_ip(uVar23,uVar22,uVar12);
            uVar12 = ae_sa32x2_ip_1(uVar23,uVar22,uVar12);
            uVar23 = (ulonglong)(uint)(fVar15 * fVar4);
            uVar22 = ae_sa32x2_ip(uVar24,uVar5,uVar12);
            uVar12 = ae_sa32x2_ip_1(uVar24,uVar5,uVar12);
          }
          uVar5 = ae_sa32x2_ip(uVar26,uVar22,uVar12);
          uVar12 = ae_sa32x2_ip_1(uVar26,uVar22,uVar12);
          uVar22 = ae_sa32x2_ip(uVar16,uVar5,uVar12);
          uVar12 = ae_sa32x2_ip_1(uVar16,uVar5,uVar12);
          uVar5 = ae_sa32x2_ip(uVar23,uVar22,uVar12);
          param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar23,uVar22,uVar12);
          uVar22 = ae_mov(uVar2);
          fVar21 = (float)uVar22;
        }
      }
    }
    else {
      uVar22 = ae_l32_ip(*(undefined4 *)param_2);
      uVar2 = ae_l32x2_ip(*(undefined8 *)((int)param_2 + 4));
      puVar1 = (undefined8 *)((int)param_2 + 0xc);
      uVar6 = ae_mov(in_aed0);
      uVar22 = ae_sel16i(uVar22,uVar2,0);
      fVar21 = (float)uVar22;
      uVar13 = param_3 >> 1 & 3;
      if (1 < (int)param_3) {
        fVar3 = (float)uVar6;
        uVar22 = uVar2;
        if ((uVar13 != 0) && ((uVar13 == 1 || (uVar13 != 0)))) {
          uVar22 = ae_l32x2_ip(*puVar1);
          puVar1 = (undefined8 *)((int)param_2 + 0x14);
          uVar6 = ae_mov(uVar2);
          uVar2 = ae_sa32x2_ip((ulonglong)(uint)(fVar21 * fVar3),uVar5,param_1);
          param_1 = (undefined4 *)ae_sa32x2_ip_1((ulonglong)(uint)(fVar21 * fVar3),uVar5,param_1);
          uVar5 = ae_sel16i(uVar6,uVar22,0);
          fVar21 = (float)uVar5;
          uVar5 = uVar2;
        }
        if (iVar14 != 0) {
          uVar6 = ae_l32x2_ip(*puVar1);
          uVar22 = ae_sel16i(uVar22,uVar6,0);
          uVar7 = ae_l32x2_i(puVar1[1]);
          uVar16 = (ulonglong)(uint)((float)uVar22 * fVar3);
          uVar8 = ae_l32x2_i(puVar1[3]);
          uVar17 = ae_l32x2_i(puVar1[2]);
          uVar2 = ae_sel16i(uVar17,uVar8,0);
          uVar6 = ae_sel16i_n(uVar6,uVar7,0);
          uVar22 = ae_sa32x2_ip((ulonglong)(uint)(fVar21 * fVar3),uVar5,param_1);
          uVar12 = ae_sa32x2_ip_1((ulonglong)(uint)(fVar21 * fVar3),uVar5,param_1);
          uVar7 = ae_sel16i_n(uVar7,uVar17,0);
          uVar26 = (ulonglong)(uint)((float)uVar6 * fVar3);
          uVar5 = ae_sa32x2_ip(uVar16,uVar22,uVar12);
          uVar12 = ae_sa32x2_ip_1(uVar16,uVar22,uVar12);
          uVar16 = (ulonglong)(uint)((float)uVar7 * fVar3);
          if (1 < iVar14) {
            uVar22 = ae_l32x2_ip(puVar1[4]);
            uVar7 = ae_l32x2_i(puVar1[7]);
            uVar17 = ae_sel16i(uVar8,uVar22,0);
            uVar8 = ae_l32x2_i(puVar1[6]);
            uVar6 = ae_l32x2_i(puVar1[5]);
            uVar23 = (ulonglong)(uint)((float)uVar2 * fVar3);
            uVar22 = ae_sel16i(uVar22,uVar6,0);
            uVar6 = ae_sel16i_n(uVar6,uVar8,0);
            uVar2 = ae_sel16i(uVar8,uVar7,0);
            uVar24 = (ulonglong)(uint)((float)uVar17 * fVar3);
            if (2 < iVar14) {
              uVar9 = ae_l32x2_ip(puVar1[8]);
              iVar14 = iVar14 + -3;
              uVar10 = ae_l32x2_i(puVar1[9]);
              uVar11 = ae_l32x2_i(puVar1[10]);
              uVar18 = ae_l32x2_i(puVar1[0xb]);
              uVar7 = ae_sel16i_n(uVar7,uVar9,0);
              fVar21 = (float)uVar7;
              uVar7 = uVar18;
              uVar8 = uVar10;
              uVar17 = uVar22;
              uVar20 = uVar11;
              uVar25 = uVar6;
              uVar19 = uVar9;
              if ((0 < iVar14) && ((iVar14 == 1 || (0 < iVar14)))) {
                uVar7 = ae_sa32x2_ip(uVar26,uVar5,uVar12);
                uVar12 = ae_sa32x2_ip_1(uVar26,uVar5,uVar12);
                uVar19 = ae_l32x2_ip(puVar1[0xc]);
                uVar17 = ae_sel16i_n(uVar9,uVar10,0);
                uVar26 = (ulonglong)(uint)((float)uVar22 * fVar3);
                uVar5 = ae_sa32x2_ip(uVar16,uVar7,uVar12);
                uVar12 = ae_sa32x2_ip_1(uVar16,uVar7,uVar12);
                uVar8 = ae_l32x2_i(puVar1[0xd]);
                uVar25 = ae_sel16i_n(uVar10,uVar11,0);
                uVar16 = (ulonglong)(uint)((float)uVar6 * fVar3);
                uVar22 = ae_sa32x2_ip(uVar23,uVar5,uVar12);
                uVar12 = ae_sa32x2_ip_1(uVar23,uVar5,uVar12);
                uVar20 = ae_l32x2_i(puVar1[0xe]);
                uVar23 = (ulonglong)(uint)((float)uVar2 * fVar3);
                uVar2 = ae_sel16i(uVar11,uVar18,0);
                uVar5 = ae_sa32x2_ip(uVar24,uVar22,uVar12);
                uVar12 = ae_sa32x2_ip_1(uVar24,uVar22,uVar12);
                uVar7 = ae_l32x2_i(puVar1[0xf]);
                uVar22 = ae_sel16i_n(uVar18,uVar19,0);
                uVar24 = (ulonglong)(uint)(fVar21 * fVar3);
                fVar21 = (float)uVar22;
              }
              uVar6 = ae_mov(uVar17);
              uVar22 = ae_sa32x2_ip(uVar26,uVar5,uVar12);
              uVar12 = ae_sa32x2_ip_1(uVar26,uVar5,uVar12);
              uVar26 = (ulonglong)(uint)((float)uVar6 * fVar3);
              uVar9 = ae_mov(uVar24);
              uVar5 = ae_sa32x2_ip(uVar16,uVar22,uVar12);
              uVar12 = ae_sa32x2_ip_1(uVar16,uVar22,uVar12);
              uVar17 = ae_mov(uVar19);
              uVar19 = ae_mov(uVar2);
              uVar22 = ae_sa32x2_ip(uVar23,uVar5,uVar12);
              uVar12 = ae_sa32x2_ip_1(uVar23,uVar5,uVar12);
              uVar5 = ae_mov(uVar25);
              uVar6 = ae_sel16i(uVar8,uVar20,0);
              uVar2 = ae_sel16i(uVar20,uVar7,0);
              uVar16 = (ulonglong)(uint)((float)uVar5 * fVar3);
              uVar23 = (ulonglong)(uint)((float)uVar19 * fVar3);
              uVar5 = ae_sa32x2_ip(uVar9,uVar22,uVar12);
              uVar12 = ae_sa32x2_ip_1(uVar9,uVar22,uVar12);
              uVar22 = ae_sel16i_n(uVar17,uVar8,0);
              uVar24 = (ulonglong)(uint)(fVar21 * fVar3);
            }
            uVar7 = ae_sa32x2_ip(uVar26,uVar5,uVar12);
            uVar12 = ae_sa32x2_ip_1(uVar26,uVar5,uVar12);
            uVar26 = (ulonglong)(uint)((float)uVar22 * fVar3);
            uVar5 = ae_sa32x2_ip(uVar16,uVar7,uVar12);
            uVar12 = ae_sa32x2_ip_1(uVar16,uVar7,uVar12);
            uVar16 = (ulonglong)(uint)((float)uVar6 * fVar3);
            uVar22 = ae_sa32x2_ip(uVar23,uVar5,uVar12);
            uVar12 = ae_sa32x2_ip_1(uVar23,uVar5,uVar12);
            uVar5 = ae_sa32x2_ip(uVar24,uVar22,uVar12);
            uVar12 = ae_sa32x2_ip_1(uVar24,uVar22,uVar12);
          }
          uVar22 = ae_sa32x2_ip(uVar26,uVar5,uVar12);
          uVar12 = ae_sa32x2_ip_1(uVar26,uVar5,uVar12);
          uVar5 = ae_sa32x2_ip(uVar16,uVar22,uVar12);
          param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar16,uVar22,uVar12);
          uVar22 = ae_mov(uVar2);
          fVar21 = (float)uVar22;
        }
      }
    }
    ae_sa64pos_fp(uVar5,param_1);
    if ((param_3 & 1) != 0) {
      uVar5 = ae_sel16i((ulonglong)(uint)(fVar21 * fVar4),(ulonglong)(uint)(fVar21 * fVar4),1);
      uVar12 = ae_s32_l_i(uVar5);
      *param_1 = uVar12;
      return;
    }
  }
  return;
}


// ===== FUN_00235190 @ 00235190 (472 bytes)

void FUN_00235190(undefined4 *param_1,undefined8 *param_2,int param_3,uint param_4)

{
  undefined8 *puVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  float fVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  undefined8 uVar30;
  
  if (0 < (int)param_4) {
    uVar14 = ae_zalign64();
    iVar17 = param_3 >> 1;
    if (((uint)param_2 & 7) != 0) {
      iVar2 = (iVar17 + 0x7f) * 0x800000;
      uVar5 = ae_movda32x2(iVar2,iVar2);
      uVar15 = ae_l32_i(*(undefined4 *)param_2);
      uVar22 = ae_sel16i_n(uVar5,uVar5,3);
      iVar2 = ((param_3 - iVar17) + 0x7f) * 0x800000;
      uVar5 = ae_movda32x2(iVar2,iVar2);
      uVar5 = ae_sel16i(uVar5,uVar5,3);
      param_4 = param_4 - 1;
      uVar16 = ae_s32_l_ip((ulonglong)(uint)((float)uVar15 * (float)uVar22 * (float)uVar5));
      *param_1 = uVar16;
      param_1 = param_1 + 1;
      ae_l32_ip(*(undefined4 *)param_2);
      param_2 = (undefined8 *)((int)param_2 + 4);
    }
    puVar1 = param_2;
    if (0 < (int)param_4 >> 1) {
      uVar18 = param_4 >> 1 & 3;
      iVar2 = (iVar17 + 0x7f) * 0x800000;
      iVar19 = ((param_3 - iVar17) + 0x7f) * 0x800000;
      uVar5 = ae_movda32x2(iVar2,iVar2);
      uVar15 = ae_movda32x2(iVar19,iVar19);
      iVar2 = (int)param_4 >> 3;
      fVar9 = (float)uVar5;
      fVar10 = (float)uVar15;
      if ((uVar18 != 0) && ((uVar18 == 1 || (uVar18 != 0)))) {
        uVar5 = ae_l32x2_ip(*param_2);
        param_2 = param_2 + 1;
        uVar6 = (ulonglong)(uint)((float)uVar5 * fVar9 * fVar10);
        uVar5 = ae_sa32x2_ip(uVar6,uVar14,param_1);
        param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar6,uVar14,param_1);
        uVar14 = uVar5;
      }
      puVar1 = param_2;
      if (iVar2 != 0) {
        uVar5 = ae_l32x2_ip(*param_2);
        puVar1 = param_2 + 4;
        uVar15 = ae_l32x2_i(param_2[2]);
        uVar21 = ae_l32x2_i(param_2[1]);
        uVar22 = ae_l32x2_i(param_2[3]);
        uVar6 = (ulonglong)(uint)((float)uVar5 * fVar9 * fVar10);
        uVar23 = (ulonglong)(uint)((float)uVar15 * fVar9 * fVar10);
        uVar28 = (ulonglong)(uint)((float)uVar21 * fVar9 * fVar10);
        uVar24 = (ulonglong)(uint)((float)uVar22 * fVar9 * fVar10);
        if (1 < iVar2) {
          uVar5 = ae_l32x2_ip(*puVar1);
          puVar1 = param_2 + 8;
          uVar15 = ae_l32x2_i(param_2[6]);
          uVar22 = ae_l32x2_i(param_2[5]);
          fVar3 = (float)uVar5 * fVar9;
          uVar25 = (ulonglong)(uint)fVar3;
          uVar5 = ae_l32x2_i(param_2[7]);
          fVar4 = (float)uVar22 * fVar9;
          uVar26 = (ulonglong)(uint)fVar4;
          fVar7 = (float)uVar15 * fVar9;
          uVar29 = (ulonglong)(uint)fVar7;
          fVar8 = (float)uVar5 * fVar9;
          uVar27 = (ulonglong)(uint)fVar8;
          if (2 < iVar2) {
            uVar5 = ae_l32x2_ip(*puVar1);
            fVar11 = (float)uVar5;
            puVar1 = param_2 + 0xc;
            iVar2 = iVar2 + -3;
            uVar5 = ae_l32x2_i(param_2[9]);
            fVar12 = (float)uVar5;
            uVar5 = ae_l32x2_i(param_2[10]);
            fVar13 = (float)uVar5;
            uVar5 = ae_l32x2_i(param_2[0xb]);
            fVar20 = (float)uVar5;
            if ((0 < iVar2) && ((iVar2 == 1 || (0 < iVar2)))) {
              uVar5 = ae_sa32x2_ip(uVar6,uVar14,param_1);
              uVar16 = ae_sa32x2_ip_1(uVar6,uVar14,param_1);
              uVar14 = ae_l32x2_ip(*puVar1);
              puVar1 = param_2 + 0x10;
              uVar25 = (ulonglong)(uint)(fVar11 * fVar9);
              uVar6 = (ulonglong)(uint)(fVar3 * fVar10);
              fVar11 = (float)uVar14;
              uVar14 = ae_sa32x2_ip(uVar28,uVar5,uVar16);
              uVar16 = ae_sa32x2_ip_1(uVar28,uVar5,uVar16);
              uVar5 = ae_l32x2_i(param_2[0xd]);
              uVar26 = (ulonglong)(uint)(fVar12 * fVar9);
              uVar28 = (ulonglong)(uint)(fVar4 * fVar10);
              fVar12 = (float)uVar5;
              uVar5 = ae_sa32x2_ip(uVar23,uVar14,uVar16);
              uVar16 = ae_sa32x2_ip_1(uVar23,uVar14,uVar16);
              uVar14 = ae_l32x2_i(param_2[0xe]);
              uVar29 = (ulonglong)(uint)(fVar13 * fVar9);
              uVar23 = (ulonglong)(uint)(fVar7 * fVar10);
              fVar13 = (float)uVar14;
              uVar14 = ae_sa32x2_ip(uVar24,uVar5,uVar16);
              param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar24,uVar5,uVar16);
              uVar5 = ae_l32x2_i(param_2[0xf]);
              uVar27 = (ulonglong)(uint)(fVar20 * fVar9);
              uVar24 = (ulonglong)(uint)(fVar8 * fVar10);
              fVar20 = (float)uVar5;
            }
            uVar15 = ae_mov(uVar27);
            uVar22 = ae_mov(uVar29);
            fVar7 = fVar13 * fVar9;
            fVar8 = fVar20 * fVar9;
            uVar5 = ae_sa32x2_ip(uVar6,uVar14,param_1);
            uVar16 = ae_sa32x2_ip_1(uVar6,uVar14,param_1);
            fVar3 = fVar11 * fVar9;
            uVar30 = ae_mov(uVar25);
            uVar14 = ae_sa32x2_ip(uVar28,uVar5,uVar16);
            uVar16 = ae_sa32x2_ip_1(uVar28,uVar5,uVar16);
            uVar21 = ae_mov(uVar26);
            fVar4 = fVar12 * fVar9;
            uVar5 = ae_sa32x2_ip(uVar23,uVar14,uVar16);
            uVar16 = ae_sa32x2_ip_1(uVar23,uVar14,uVar16);
            uVar6 = (ulonglong)(uint)((float)uVar30 * fVar10);
            uVar28 = (ulonglong)(uint)((float)uVar21 * fVar10);
            uVar14 = ae_sa32x2_ip(uVar24,uVar5,uVar16);
            param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar24,uVar5,uVar16);
            uVar23 = (ulonglong)(uint)((float)uVar22 * fVar10);
            uVar24 = (ulonglong)(uint)((float)uVar15 * fVar10);
          }
          uVar5 = ae_sa32x2_ip(uVar6,uVar14,param_1);
          uVar16 = ae_sa32x2_ip_1(uVar6,uVar14,param_1);
          uVar6 = (ulonglong)(uint)(fVar3 * fVar10);
          uVar14 = ae_sa32x2_ip(uVar28,uVar5,uVar16);
          uVar16 = ae_sa32x2_ip_1(uVar28,uVar5,uVar16);
          uVar28 = (ulonglong)(uint)(fVar4 * fVar10);
          uVar5 = ae_sa32x2_ip(uVar23,uVar14,uVar16);
          uVar16 = ae_sa32x2_ip_1(uVar23,uVar14,uVar16);
          uVar23 = (ulonglong)(uint)(fVar7 * fVar10);
          uVar14 = ae_sa32x2_ip(uVar24,uVar5,uVar16);
          param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar24,uVar5,uVar16);
          uVar24 = (ulonglong)(uint)(fVar8 * fVar10);
        }
        uVar5 = ae_sa32x2_ip(uVar6,uVar14,param_1);
        uVar16 = ae_sa32x2_ip_1(uVar6,uVar14,param_1);
        uVar14 = ae_sa32x2_ip(uVar28,uVar5,uVar16);
        uVar16 = ae_sa32x2_ip_1(uVar28,uVar5,uVar16);
        uVar5 = ae_sa32x2_ip(uVar23,uVar14,uVar16);
        uVar16 = ae_sa32x2_ip_1(uVar23,uVar14,uVar16);
        uVar14 = ae_sa32x2_ip(uVar24,uVar5,uVar16);
        param_1 = (undefined4 *)ae_sa32x2_ip_1(uVar24,uVar5,uVar16);
      }
    }
    ae_sa64pos_fp(uVar14,param_1);
    if ((param_4 & 1) != 0) {
      iVar2 = (iVar17 + 0x7f) * 0x800000;
      uVar14 = ae_movda32x2(iVar2,iVar2);
      uVar5 = ae_l32_i(*(undefined4 *)puVar1);
      uVar15 = ae_sel16i_n(uVar14,uVar14,3);
      iVar17 = ((param_3 - iVar17) + 0x7f) * 0x800000;
      uVar14 = ae_movda32x2(iVar17,iVar17);
      uVar14 = ae_sel16i(uVar14,uVar14,3);
      uVar16 = ae_s32_l_i((ulonglong)(uint)((float)uVar5 * (float)uVar15 * (float)uVar14));
      *param_1 = uVar16;
      return;
    }
  }
  return;
}


// ===== FUN_00235370 @ 00235370 (37 bytes)

void FUN_00235370(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    return;
  }
  iVar1 = *param_1;
  if (iVar1 != 0) {
    *(undefined4 *)(param_2 + 0xc) = 0;
    *(int *)(param_2 + 8) = iVar1;
    *(int *)(*param_1 + 0xc) = param_2;
    *param_1 = param_2;
    return;
  }
  *param_1 = param_2;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(*param_1 + 0xc) = 0;
  return;
}


// ===== FUN_00235398 @ 00235398 (38 bytes)

void FUN_00235398(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((iVar1 == 0) || (param_2 == 0)) {
    return;
  }
  if (iVar1 == param_2) {
    *param_1 = *(int *)(iVar1 + 8);
    return;
  }
  iVar1 = *(int *)(param_2 + 0xc);
  if (*(int *)(param_2 + 8) != 0) {
    *(int *)(iVar1 + 8) = *(int *)(param_2 + 8);
    *(int *)(*(int *)(param_2 + 8) + 0xc) = iVar1;
    return;
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  return;
}


// ===== FUN_002353c0 @ 002353c0 (32 bytes)

undefined4 FUN_002353c0(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 1;
  }
  uVar1 = ae_l16ui_n(param_1,0);
  if ((*(short *)(param_1 + 8) == *(short *)(param_1 + 10)) && ((uVar1 & 2) == 0)) {
    return 1;
  }
  return 0;
}


// ===== FUN_002353e0 @ 002353e0 (19 bytes)

undefined4 FUN_002353e0(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = ae_l16ui_n(param_1,0);
    if ((uVar1 >> 1 & 1) != 0) {
      return 1;
    }
  }
  return 0;
}


// ===== FUN_002353f4 @ 002353f4 (28 bytes)

void FUN_002353f4(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_2[1];
  iVar2 = *param_2;
  *piVar1 = iVar2;
  if (iVar2 == 0) {
    iVar2 = param_1;
  }
  *(int **)(iVar2 + 4) = piVar1;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[0x12] = 0;
  return;
}


// ===== FUN_00235410 @ 00235410 (16 bytes)

void FUN_00235410(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  *(int **)(param_2 + 4) = piVar1;
  *piVar1 = param_2;
  *(int *)(param_1 + 4) = param_2;
  *(int *)(param_2 + 0x48) = param_1;
  return;
}


// ===== FUN_00235420 @ 00235420 (25 bytes)

void FUN_00235420(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    param_1[1] = (int)param_2;
  }
  else {
    *(int **)(iVar1 + 4) = param_2;
  }
  *param_2 = iVar1;
  param_2[1] = (int)param_1;
  *param_1 = (int)param_2;
  param_2[0x12] = (int)param_1;
  return;
}


// ===== FUN_0023543c @ 0023543c (46 bytes)

void FUN_0023543c(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1;
  do {
    piVar2 = piVar1;
    piVar1 = (int *)*piVar2;
    if (piVar1 == (int *)0x0) {
      param_1[1] = (int)param_2;
      break;
    }
  } while (*(char *)((int)param_2 + 0x33) <= *(char *)((int)piVar1 + 0x33));
  param_2[1] = piVar2;
  *piVar2 = (int)param_2;
  *param_2 = piVar1;
  if (piVar1 != (int *)0x0) {
    piVar1[1] = (int)param_2;
  }
  param_2[0x12] = param_1;
  return;
}


// ===== FUN_0023546c @ 0023546c (74 bytes)

void FUN_0023546c(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x20) == param_2) {
    iVar2 = 0x48;
    if (param_3 != 0) {
      iVar2 = 0x118;
    }
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x24) - iVar2 & 0xfffffffc);
    *(uint *)(param_1 + 0x24) = (uint)(puVar1 + -1) & 0xfffffff0;
  }
  else {
    puVar1 = (undefined4 *)(param_2 + 3U & 0xfffffffc);
  }
  *(undefined4 **)(param_1 + 0x14) = puVar1;
  uVar3 = (int)puVar1 + 0x17U & 0xfffffff8;
  *puVar1 = 0;
  puVar1[2] = uVar3;
  puVar1[1] = 0;
  if (param_3 == 0) {
    uVar3 = 0;
  }
  puVar1[3] = uVar3;
  return;
}


// ===== FUN_002354b8 @ 002354b8 (7 bytes)

undefined4 FUN_002354b8(void)

{
  return 0;
}


// ===== FUN_002354c0 @ 002354c0 (32 bytes)

void FUN_002354c0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[5] = 0;
    param_1[4] = 0;
    *(undefined1 *)(param_1 + 8) = 0;
    *param_1 = 0;
    param_1[9] = 0;
    param_1[10] = param_1 + 9;
  }
  return;
}


// ===== FUN_002354e0 @ 002354e0 (43 bytes)

void FUN_002354e0(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 in_EPC1;
  undefined4 in_EXCSAVE1;
  undefined4 in_EXCSAVE4;
  undefined4 uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  uVar2 = rsr_excsave4(in_EXCSAVE4);
  uVar3 = wsr_excsave4(param_1);
  simcall();
  wsr_exccause(0x15);
  rsr_excsave4(uVar3);
  pcVar1 = (code *)xsr_excsave1(uVar2,in_EXCSAVE1);
  xsr_excsave1_1(uVar2,in_EXCSAVE1);
  rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  rsr_epc1(in_EPC1);
                    /* WARNING: Does not return */
  (*pcVar1)();
}


// ===== FUN_00235510 @ 00235510 (92 bytes)

undefined8
FUN_00235510(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            uint param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  int iVar12;
  
  f64cmpl(param_1,param_3);
  uVar11 = f64cmpl_1(param_1,param_3);
  uVar5 = f64cmph(param_2,param_4,4,uVar11);
  auVar6 = f64cmph_1(param_2,param_4,4,uVar11);
  iVar3 = auVar6._0_4_;
  uVar11 = auVar6._12_4_;
  if (-1 < (int)uVar5) {
    if ((uVar5 & 0x10000) == 0) {
      param_6 = f64sig(param_2);
      iVar12 = param_1 << 0x20 - iVar3;
      uVar2 = (undefined4)(CONCAT44(param_6,param_1) >> iVar3);
      uVar7 = f64sig(param_4);
      uVar1 = uVar5 & 0x100000;
      param_1 = param_3;
      uVar9 = param_6;
    }
    else {
      uVar9 = f64sig(param_4);
      iVar12 = param_3 << 0x20 - iVar3;
      uVar2 = (undefined4)(CONCAT44(uVar9,param_3) >> iVar3);
      uVar7 = f64sig(param_2);
      uVar1 = uVar5 >> 0x14 & 1;
    }
    uVar9 = uVar9 >> iVar3;
    if (uVar1 != 0) {
      uVar8 = f64subc(param_6,iVar12,3,1,uVar11);
      uVar11 = f64subc_1(param_6,iVar12,3,1,uVar11);
      uVar4 = f64subc(param_1,uVar2,0,1,uVar11);
      uVar11 = f64subc_1(param_1,uVar2,0,1,uVar11);
      uVar2 = f64subc(uVar7,uVar9,0,1,uVar11);
      uVar11 = f64subc_1(uVar7,uVar9,0,1,uVar11);
      iVar3 = f64subc(uVar8,iVar12,3,1,uVar11);
      uVar11 = f64subc_1(uVar8,iVar12,3,1,uVar11);
      uVar5 = f64norm(uVar2,uVar4,0,uVar11);
      uVar10 = f64norm_1(uVar2,uVar4,0,uVar11);
      iVar12 = (int)uVar10;
      uVar7 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar11 = (undefined4)(CONCAT44(uVar4,iVar3) >> iVar12);
      if ((uVar5 & 0x400000) != 0) {
        uVar11 = f64sexp(uVar11,uVar5);
        return CONCAT44(uVar11,iVar3 << 0x20 - iVar12);
      }
      uVar8 = f64sexp((int)(CONCAT44(uVar2,uVar4) >> iVar12),uVar5);
      uVar2 = f64addc(uVar11,uVar11,2,0,uVar7);
      uVar7 = f64addc_1(uVar11,uVar11,2,0,uVar7);
      uVar11 = f64addc(uVar8,uVar8,2,0,uVar7);
      f64addc_1(uVar8,uVar8,2,0,uVar7);
      return CONCAT44(uVar11,uVar2);
    }
    if ((uVar5 & 0x200000) != 0) {
      if ((uVar5 >> 0x11 & 1) == 0) {
        uVar10 = wf64r(uVar2,iVar12,0);
        uVar2 = f64addc(param_1,uVar9,1,1,uVar11);
        uVar8 = f64addc_1(param_1,uVar9,1,1,uVar11);
        uVar11 = f64addc(uVar7,uVar7,2,1,uVar8);
        uVar7 = f64addc_1(uVar7,uVar7,2,1,uVar8);
        uVar8 = f64rnd(uVar11,uVar2,1,uVar10,uVar7);
        uVar10 = f64rnd_1(uVar11,uVar2,1,uVar10,uVar7);
        uVar11 = rf64r(0,uVar10);
        return CONCAT44(uVar8,uVar11);
      }
      uVar8 = f64subc(iVar12,iVar12,3,1,uVar11);
      uVar4 = f64subc_1(iVar12,iVar12,3,1,uVar11);
      uVar11 = f64subc(uVar2,uVar2,2,1,uVar4);
      uVar2 = f64subc_1(uVar2,uVar2,2,1,uVar4);
      uVar10 = wf64r(uVar11,uVar8,0);
      uVar11 = f64subc(param_1,uVar9,0,1,uVar2);
      uVar8 = f64subc_1(param_1,uVar9,0,1,uVar2);
      uVar2 = f64subc(uVar7,0,0,1,uVar8);
      uVar7 = f64subc_1(uVar7,0,0,1,uVar8);
      uVar8 = f64rnd(uVar2,uVar11,1,uVar10,uVar7);
      uVar10 = f64rnd_1(uVar2,uVar11,1,uVar10,uVar7);
      uVar11 = rf64r(0,uVar10);
      return CONCAT44(uVar8,uVar11);
    }
    if ((uVar5 & 0x20000) == 0) {
      uVar8 = f64addc(param_1,uVar2,1,1,uVar11);
      uVar2 = f64addc_1(param_1,uVar2,1,1,uVar11);
      uVar11 = f64addc(uVar7,uVar9,0,1,uVar2);
      uVar2 = f64addc_1(uVar7,uVar9,0,1,uVar2);
      uVar10 = wf64r(iVar12,iVar12,1);
      uVar7 = f64rnd(uVar11,uVar8,1,uVar10,uVar2);
      uVar10 = f64rnd_1(uVar11,uVar8,1,uVar10,uVar2);
      uVar11 = rf64r(0,uVar10);
      return CONCAT44(uVar7,uVar11);
    }
    uVar8 = f64subc(iVar12,iVar12,3,1,uVar11);
    uVar4 = f64subc_1(iVar12,iVar12,3,1,uVar11);
    uVar11 = f64subc(param_1,uVar2,0,1,uVar4);
    uVar4 = f64subc_1(param_1,uVar2,0,1,uVar4);
    uVar2 = f64subc(uVar7,uVar9,0,1,uVar4);
    uVar7 = f64subc_1(uVar7,uVar9,0,1,uVar4);
    uVar10 = wf64r(uVar8,uVar8,1);
    uVar8 = f64rnd(uVar2,uVar11,1,uVar10,uVar7);
    uVar10 = f64rnd_1(uVar2,uVar11,1,uVar10,uVar7);
    uVar11 = rf64r(0,uVar10);
    return CONCAT44(uVar8,uVar11);
  }
  if ((uVar5 & 0x40000000) != 0) {
    uVar2 = f64rnd(param_2,param_1,2,auVar6._4_8_,uVar11);
    uVar10 = f64rnd_1(param_2,param_1,2,auVar6._4_8_,uVar11);
    uVar11 = rf64r(0,uVar10);
    return CONCAT44(uVar2,uVar11);
  }
  if ((uVar5 & 0x8000) != 0) {
    uVar11 = f64sexp(param_4,uVar5);
    return CONCAT44(uVar11,param_3);
  }
  if ((uVar5 & 0x20000) == 0) {
    uVar8 = f64sig(param_4);
    uVar2 = f64addc(param_1,param_3,1,0,uVar11);
    uVar7 = f64addc_1(param_1,param_3,1,0,uVar11);
    uVar11 = f64addc(param_2,uVar8,0,0,uVar7);
    f64addc_1(param_2,uVar8,0,0,uVar7);
    return CONCAT44(uVar11,uVar2);
  }
  if ((uVar5 & 0x10000) != 0) {
    uVar2 = f64subc(param_1,param_3,1,0,uVar11);
    uVar7 = f64subc_1(param_1,param_3,1,0,uVar11);
    uVar11 = f64subc(param_2,param_4,0,0,uVar7);
    f64subc_1(param_2,param_4,0,0,uVar7);
    uVar11 = f64sexp(uVar11,uVar5);
    return CONCAT44(uVar11,uVar2);
  }
  uVar2 = f64subc(param_3,param_1,1,0,uVar11);
  uVar7 = f64subc_1(param_3,param_1,1,0,uVar11);
  uVar11 = f64subc(param_4,param_2,0,0,uVar7);
  f64subc_1(param_4,param_2,0,0,uVar7);
  uVar11 = f64sexp(uVar11,uVar5);
  return CONCAT44(uVar11,uVar2);
}


// ===== FUN_00235570 @ 00235570 (189 bytes)

undefined8
FUN_00235570(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            uint param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  int iVar12;
  
  f64cmpl(param_1,param_3);
  uVar11 = f64cmpl_1(param_1,param_3);
  uVar5 = f64cmph(param_2,param_4,0,uVar11);
  auVar6 = f64cmph_1(param_2,param_4,0,uVar11);
  iVar3 = auVar6._0_4_;
  uVar11 = auVar6._12_4_;
  if (-1 < (int)uVar5) {
    if ((uVar5 & 0x10000) == 0) {
      param_6 = f64sig(param_2);
      iVar12 = param_1 << 0x20 - iVar3;
      uVar2 = (undefined4)(CONCAT44(param_6,param_1) >> iVar3);
      uVar7 = f64sig(param_4);
      uVar1 = uVar5 & 0x100000;
      uVar9 = param_6;
    }
    else {
      uVar9 = f64sig(param_4);
      iVar12 = param_3 << 0x20 - iVar3;
      uVar2 = (undefined4)(CONCAT44(uVar9,param_3) >> iVar3);
      uVar7 = f64sig(param_2);
      uVar1 = uVar5 >> 0x14 & 1;
      param_3 = param_1;
    }
    uVar9 = uVar9 >> iVar3;
    if (uVar1 != 0) {
      uVar8 = f64subc(param_6,iVar12,3,1,uVar11);
      uVar11 = f64subc_1(param_6,iVar12,3,1,uVar11);
      uVar4 = f64subc(param_3,uVar2,0,1,uVar11);
      uVar11 = f64subc_1(param_3,uVar2,0,1,uVar11);
      uVar2 = f64subc(uVar7,uVar9,0,1,uVar11);
      uVar11 = f64subc_1(uVar7,uVar9,0,1,uVar11);
      iVar3 = f64subc(uVar8,iVar12,3,1,uVar11);
      uVar11 = f64subc_1(uVar8,iVar12,3,1,uVar11);
      uVar5 = f64norm(uVar2,uVar4,0,uVar11);
      uVar10 = f64norm_1(uVar2,uVar4,0,uVar11);
      iVar12 = (int)uVar10;
      uVar7 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar11 = (undefined4)(CONCAT44(uVar4,iVar3) >> iVar12);
      if ((uVar5 & 0x400000) != 0) {
        uVar11 = f64sexp(uVar11,uVar5);
        return CONCAT44(uVar11,iVar3 << 0x20 - iVar12);
      }
      uVar8 = f64sexp((int)(CONCAT44(uVar2,uVar4) >> iVar12),uVar5);
      uVar2 = f64addc(uVar11,uVar11,2,0,uVar7);
      uVar7 = f64addc_1(uVar11,uVar11,2,0,uVar7);
      uVar11 = f64addc(uVar8,uVar8,2,0,uVar7);
      f64addc_1(uVar8,uVar8,2,0,uVar7);
      return CONCAT44(uVar11,uVar2);
    }
    if ((uVar5 & 0x200000) != 0) {
      if ((uVar5 >> 0x11 & 1) == 0) {
        uVar10 = wf64r(uVar2,iVar12,0);
        uVar2 = f64addc(param_3,uVar9,1,1,uVar11);
        uVar8 = f64addc_1(param_3,uVar9,1,1,uVar11);
        uVar11 = f64addc(uVar7,uVar7,2,1,uVar8);
        uVar7 = f64addc_1(uVar7,uVar7,2,1,uVar8);
        uVar8 = f64rnd(uVar11,uVar2,1,uVar10,uVar7);
        uVar10 = f64rnd_1(uVar11,uVar2,1,uVar10,uVar7);
        uVar11 = rf64r(0,uVar10);
        return CONCAT44(uVar8,uVar11);
      }
      uVar8 = f64subc(iVar12,iVar12,3,1,uVar11);
      uVar4 = f64subc_1(iVar12,iVar12,3,1,uVar11);
      uVar11 = f64subc(uVar2,uVar2,2,1,uVar4);
      uVar2 = f64subc_1(uVar2,uVar2,2,1,uVar4);
      uVar10 = wf64r(uVar11,uVar8,0);
      uVar11 = f64subc(param_3,uVar9,0,1,uVar2);
      uVar8 = f64subc_1(param_3,uVar9,0,1,uVar2);
      uVar2 = f64subc(uVar7,0,0,1,uVar8);
      uVar7 = f64subc_1(uVar7,0,0,1,uVar8);
      uVar8 = f64rnd(uVar2,uVar11,1,uVar10,uVar7);
      uVar10 = f64rnd_1(uVar2,uVar11,1,uVar10,uVar7);
      uVar11 = rf64r(0,uVar10);
      return CONCAT44(uVar8,uVar11);
    }
    if ((uVar5 & 0x20000) != 0) {
      uVar8 = f64subc(iVar12,iVar12,3,1,uVar11);
      uVar4 = f64subc_1(iVar12,iVar12,3,1,uVar11);
      uVar11 = f64subc(param_3,uVar2,0,1,uVar4);
      uVar4 = f64subc_1(param_3,uVar2,0,1,uVar4);
      uVar2 = f64subc(uVar7,uVar9,0,1,uVar4);
      uVar7 = f64subc_1(uVar7,uVar9,0,1,uVar4);
      uVar10 = wf64r(uVar8,uVar8,1);
      uVar8 = f64rnd(uVar2,uVar11,1,uVar10,uVar7);
      uVar10 = f64rnd_1(uVar2,uVar11,1,uVar10,uVar7);
      uVar11 = rf64r(0,uVar10);
      return CONCAT44(uVar8,uVar11);
    }
    uVar8 = f64addc(param_3,uVar2,1,1,uVar11);
    uVar2 = f64addc_1(param_3,uVar2,1,1,uVar11);
    uVar11 = f64addc(uVar7,uVar9,0,1,uVar2);
    uVar2 = f64addc_1(uVar7,uVar9,0,1,uVar2);
    uVar10 = wf64r(iVar12,iVar12,1);
    uVar7 = f64rnd(uVar11,uVar8,1,uVar10,uVar2);
    uVar10 = f64rnd_1(uVar11,uVar8,1,uVar10,uVar2);
    uVar11 = rf64r(0,uVar10);
    return CONCAT44(uVar7,uVar11);
  }
  if ((uVar5 & 0x40000000) != 0) {
    uVar2 = f64rnd(param_2,param_1,2,auVar6._4_8_,uVar11);
    uVar10 = f64rnd_1(param_2,param_1,2,auVar6._4_8_,uVar11);
    uVar11 = rf64r(0,uVar10);
    return CONCAT44(uVar2,uVar11);
  }
  if ((uVar5 & 0x8000) != 0) {
    uVar11 = f64sexp(param_4,uVar5);
    return CONCAT44(uVar11,param_3);
  }
  if ((uVar5 & 0x20000) == 0) {
    uVar8 = f64sig(param_4);
    uVar2 = f64addc(param_1,param_3,1,0,uVar11);
    uVar7 = f64addc_1(param_1,param_3,1,0,uVar11);
    uVar11 = f64addc(param_2,uVar8,0,0,uVar7);
    f64addc_1(param_2,uVar8,0,0,uVar7);
    return CONCAT44(uVar11,uVar2);
  }
  if ((uVar5 & 0x10000) != 0) {
    uVar2 = f64subc(param_1,param_3,1,0,uVar11);
    uVar7 = f64subc_1(param_1,param_3,1,0,uVar11);
    uVar11 = f64subc(param_2,param_4,0,0,uVar7);
    f64subc_1(param_2,param_4,0,0,uVar7);
    uVar11 = f64sexp(uVar11,uVar5);
    return CONCAT44(uVar11,uVar2);
  }
  uVar2 = f64subc(param_3,param_1,1,0,uVar11);
  uVar7 = f64subc_1(param_3,param_1,1,0,uVar11);
  uVar11 = f64subc(param_4,param_2,0,0,uVar7);
  f64subc_1(param_4,param_2,0,0,uVar7);
  uVar11 = f64sexp(uVar11,uVar5);
  return CONCAT44(uVar11,uVar2);
}


// ===== FUN_00235630 @ 00235630 (392 bytes)

undefined8 FUN_00235630(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auVar2 [16];
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  
  f64cmpl(param_1,param_3);
  uVar11 = f64cmpl_1(param_1,param_3);
  uVar8 = f64cmph(param_2,param_4,1,uVar11);
  auVar2 = f64cmph_1(param_2,param_4,1,uVar11);
  iVar12 = auVar2._0_4_;
  uVar11 = auVar2._12_4_;
  if ((int)uVar8 < 0) {
    if ((uVar8 & 0x8000) != 0) {
      param_1 = param_3;
      param_2 = param_4;
    }
    uVar6 = f64rnd(param_2,param_1,2,auVar2._4_8_,uVar11);
    uVar10 = f64rnd_1(param_2,param_1,2,auVar2._4_8_,uVar11);
    uVar11 = rf64r(0,uVar10);
    return CONCAT44(uVar6,uVar11);
  }
  uVar4 = f64sig(param_2);
  uVar5 = f64sig(param_4);
  uVar3 = (undefined4)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20);
  uVar6 = f64addc(uVar4 * param_3,uVar5 * param_1,1,1,uVar11);
  uVar11 = f64addc_1(uVar4 * param_3,uVar5 * param_1,1,1,uVar11);
  uVar9 = f64addc(uVar6,uVar3,1,0,uVar11);
  uVar6 = f64addc_1(uVar6,uVar3,1,0,uVar11);
  uVar3 = (undefined4)((ulonglong)uVar4 * (ulonglong)param_3 >> 0x20);
  uVar7 = (undefined4)((ulonglong)uVar5 * (ulonglong)param_1 >> 0x20);
  uVar11 = f64addc(uVar3,uVar7,0,1,uVar6);
  uVar6 = f64addc_1(uVar3,uVar7,0,1,uVar6);
  uVar15 = f64addc(uVar11,uVar4 * uVar5,0,0,uVar6);
  uVar11 = f64addc_1(uVar11,uVar4 * uVar5,0,0,uVar6);
  uVar6 = (undefined4)((ulonglong)uVar4 * (ulonglong)uVar5 >> 0x20);
  param_1 = param_1 * param_3;
  uVar4 = f64addc(uVar6,uVar6,2,0,uVar11);
  uVar11 = f64addc_1(uVar6,uVar6,2,0,uVar11);
  if ((uVar8 & 0x400000) == 0) {
    uVar6 = (undefined4)(CONCAT44(uVar15,uVar9) >> iVar12);
    uVar3 = (undefined4)(CONCAT44(uVar4,uVar15) >> iVar12);
    uVar10 = wf64r((int)(CONCAT44(uVar9,param_1) >> iVar12),param_1,0);
    uVar7 = f64rnd(uVar3,uVar6,1,uVar10,uVar11);
    uVar10 = f64rnd_1(uVar3,uVar6,1,uVar10,uVar11);
    uVar11 = rf64r(0,uVar10);
    return CONCAT44(uVar7,uVar11);
  }
  if ((uVar8 & 0x200000) != 0) {
    uVar11 = (undefined4)(CONCAT44(uVar4,uVar15) >> iVar12);
    uVar6 = (undefined4)(CONCAT44(uVar15,uVar9) >> iVar12);
    uVar7 = wur_f64s(uVar8 + (uVar4 >> 9 & 1));
    uVar10 = wf64r(uVar9 << 0x20 - iVar12,param_1,0);
    uVar3 = f64rnd(uVar11,uVar6,0,uVar10,uVar7);
    uVar10 = f64rnd_1(uVar11,uVar6,0,uVar10,uVar7);
    uVar11 = rf64r(0,uVar10);
    return CONCAT44(uVar3,uVar11);
  }
  uVar5 = (int)(uVar8 << 0x15) >> 0x1f;
  iVar12 = ((int)(uVar8 << 0x15) >> 0x15 ^ uVar5) - uVar5;
  uVar11 = wur_f64s(uVar8 & 0xfffff800);
  if ((uVar8 & 0x400) != 0) {
    uVar5 = iVar12 + 0x13;
    if (((uVar8 >> 0xc & 1) == 0) && ((uVar8 & 0x2000) == 0)) {
      uVar5 = iVar12 + 0x14;
    }
    uVar8 = uVar5 & 0x1f;
    if (0x1f < uVar5) {
      if (uVar5 < 0x40) {
        uVar6 = (undefined4)(CONCAT44(uVar4,uVar15) >> uVar8);
        uVar10 = wf64r((int)(CONCAT44(uVar15,uVar9) >> uVar8),param_1 | uVar9,0);
        uVar3 = f64rnd(uVar4 >> uVar8,uVar6,0,uVar10,uVar11);
        uVar10 = f64rnd_1(uVar4 >> uVar8,uVar6,0,uVar10,uVar11);
        uVar11 = rf64r(0,uVar10);
        return CONCAT44(uVar3,uVar11);
      }
      uVar10 = wf64r((int)(CONCAT44(uVar4,uVar15) >> uVar8),param_1 | uVar9 | uVar15,0);
      uVar6 = f64rnd(0,uVar4 >> uVar8,0,uVar10,uVar11);
      uVar10 = f64rnd_1(0,uVar4 >> uVar8,0,uVar10,uVar11);
      uVar11 = rf64r(0,uVar10);
      return CONCAT44(uVar6,uVar11);
    }
    uVar6 = (undefined4)(CONCAT44(uVar15,uVar9) >> uVar8);
    uVar3 = (undefined4)(CONCAT44(uVar4,uVar15) >> uVar8);
    uVar10 = wf64r((int)(CONCAT44(uVar9,param_1) >> uVar8),param_1,0);
    uVar7 = f64rnd(uVar3,uVar6,0,uVar10,uVar11);
    uVar10 = f64rnd_1(uVar3,uVar6,0,uVar10,uVar11);
    uVar11 = rf64r(0,uVar10);
    return CONCAT44(uVar7,uVar11);
  }
  uVar5 = f64norm(uVar4,uVar15,1,uVar11);
  uVar10 = f64norm_1(uVar4,uVar15,1,uVar11);
  iVar1 = (int)uVar10;
  uVar11 = (undefined4)((ulonglong)uVar10 >> 0x20);
  if (uVar5 < 0x20) {
    uVar4 = (uint)(CONCAT44(uVar4,uVar15) >> iVar1);
    iVar13 = uVar5 - 0xc;
    uVar15 = (uint)(CONCAT44(uVar15,uVar9) >> iVar1);
    uVar5 = param_1 << 0x20 - iVar1;
    iVar14 = (int)(CONCAT44(uVar9,param_1) >> iVar1);
  }
  else {
    uVar4 = f64norm(uVar15,uVar9,1,uVar11);
    uVar10 = f64norm_1(uVar15,uVar9,1,uVar11);
    iVar1 = (int)uVar10;
    uVar11 = (undefined4)((ulonglong)uVar10 >> 0x20);
    if (uVar4 < 0x20) {
      iVar13 = uVar4 + 0x14;
      uVar4 = (uint)(CONCAT44(uVar15,uVar9) >> iVar1);
      iVar14 = param_1 << 0x20 - iVar1;
      uVar15 = (uint)(CONCAT44(uVar9,param_1) >> iVar1);
      uVar5 = 0;
    }
    else {
      iVar13 = f64norm(uVar9,param_1,1,uVar11);
      uVar10 = f64norm_1(uVar9,param_1,1,uVar11);
      uVar11 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar15 = param_1 << 0x20 - (int)uVar10;
      iVar13 = iVar13 + 0x34;
      uVar4 = (uint)(CONCAT44(uVar9,param_1) >> (int)uVar10);
      iVar14 = 0;
      uVar5 = 0;
    }
  }
  iVar12 = iVar12 - iVar13;
  if (iVar12 < 0) {
    if (iVar12 < 1) {
      iVar12 = -iVar12;
    }
    uVar9 = iVar12 - 1U & 0x1f;
    uVar8 = uVar4;
    if (0x1f < iVar12 - 1U) {
      uVar5 = uVar5 | uVar15;
      uVar8 = 0;
      uVar15 = uVar4;
    }
    uVar6 = (undefined4)(CONCAT44(uVar8,uVar15) >> uVar9);
    uVar10 = wf64r(iVar14,uVar5 | (uint)(CONCAT44(uVar15,iVar14) >> uVar9),0);
    uVar3 = f64rnd(uVar8 >> uVar9,uVar6,0,uVar10,uVar11);
    uVar10 = f64rnd_1(uVar8 >> uVar9,uVar6,0,uVar10,uVar11);
    uVar11 = rf64r(0,uVar10);
    return CONCAT44(uVar3,uVar11);
  }
  uVar10 = wf64r(iVar14,uVar5,0);
  uVar6 = wur_f64s(uVar8 & 0xfffff800 | iVar12 + 1U);
  uVar11 = f64rnd(uVar4,uVar15,2,uVar10,uVar6);
  uVar10 = f64rnd_1(uVar4,uVar15,2,uVar10,uVar6);
  uVar6 = rf64r(0,uVar10);
  return CONCAT44(uVar11,uVar6);
}


// ===== FUN_002357c0 @ 002357c0 (275 bytes)

/* WARNING: Removing unreachable block (ram,0x00235800) */

longlong FUN_002357c0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined1 auVar1 [12];
  undefined1 auVar2 [16];
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  f64cmpl(param_1,param_3);
  uVar5 = f64cmpl_1(param_1,param_3);
  uVar12 = f64cmph(param_2,param_4,3,uVar5);
  auVar2 = f64cmph_1(param_2,param_4,3,uVar5);
  uVar5 = auVar2._0_4_;
  uVar9 = auVar2._12_4_;
  if (-1 < (int)uVar12) {
    iVar6 = rsr_sar(uVar5);
    goto LAB_002357cf;
  }
  if ((uVar12 & 0x40000000) != 0) {
    uVar5 = f64rnd(param_2,param_1,2,auVar2._4_8_,uVar9);
    uVar8 = f64rnd_1(param_2,param_1,2,auVar2._4_8_,uVar9);
    uVar9 = rf64r(0,uVar8);
    return CONCAT44(uVar5,uVar9);
  }
  if ((uVar12 & 0x400000) == 0) {
LAB_00235858:
    uVar11 = param_2 >> 0x14 & 0x7ff;
    uVar13 = param_4 >> 0x14 & 0x7ff;
    if ((uVar12 >> 0xc & 1) == 0) {
LAB_00235881:
      uVar13 = f64norm(param_4,param_3,1,uVar9);
      uVar8 = f64norm_1(param_4,param_3,1,uVar9);
      uVar4 = param_3;
      if (0x1f < uVar13) {
        uVar4 = 0;
        param_4 = param_3;
      }
      uVar13 = 1 - uVar13;
      param_4 = (uint)(CONCAT44(param_4,uVar4) >> (int)uVar8);
      param_3 = uVar4 << 0x20 - (int)uVar8;
    }
    else {
      uVar11 = f64norm(param_2,param_1,1,uVar9);
      uVar8 = f64norm_1(param_2,param_1,1,uVar9);
      uVar9 = (undefined4)((ulonglong)uVar8 >> 0x20);
      uVar4 = param_1;
      if (0x1f < uVar11) {
        uVar4 = 0;
        param_2 = param_1;
      }
      uVar11 = 1 - uVar11;
      param_2 = (uint)(CONCAT44(param_2,uVar4) >> (int)uVar8);
      param_1 = uVar4 << 0x20 - (int)uVar8;
      if ((uVar12 >> 0xd & 1) != 0) goto LAB_00235881;
    }
    f64cmpl(param_1,param_3);
    uVar5 = f64cmpl_1(param_1,param_3);
    f64cmph(param_2,param_4,3,uVar5);
    auVar2 = f64cmph_1(param_2,param_4,3,uVar5);
    uVar5 = auVar2._0_4_;
    iVar6 = rsr_sar(uVar5);
    iVar7 = ((uVar11 - uVar13) + 0x400) - (iVar6 + -0x36);
    if (-1 < iVar7 + -0x800) {
      uVar12 = f64sexp(0,uVar12 | 0x7ff);
      return (ulonglong)uVar12 << 0x20;
    }
    uVar11 = iVar7 - 1;
    uVar12 = (uVar12 >> 0xb & 1) << 0xb | uVar11 & 0x7ff;
    if (-1 < iVar7 + -2) goto LAB_002357cf;
  }
  else {
    uVar11 = (int)(uVar12 << 0x15) >> 0x15;
    if ((int)(uVar11 + 0x35) < 0) goto LAB_0023583a;
    if ((uVar12 & 0x1000) != 0) goto LAB_00235858;
  }
  iVar6 = rsr_sar(uVar5);
  iVar6 = iVar6 + uVar11 + -1;
  uVar12 = uVar12 & 0xfffff800;
  if (iVar6 < 1) {
LAB_0023583a:
    uVar12 = f64sexp(0,uVar12 & 0xfffff800);
    return (ulonglong)uVar12 << 0x20;
  }
LAB_002357cf:
  uVar5 = f64sig(param_2);
  uVar8 = wf64r(uVar5,param_1,0);
  uVar5 = 0;
  uVar9 = f64sig(param_4);
  iVar7 = iVar6 + -0x21;
  if (iVar6 + -0x21 < 0) {
    iVar7 = iVar6 + -1;
  }
  uVar10 = wur_f64s(0);
  uVar3 = f64iter(uVar9,uVar9,param_3,2,1,uVar8,uVar10);
  auVar1 = f64iter_1(uVar9,uVar9,param_3,2,1,uVar8,uVar10);
  uVar8 = auVar1._0_8_;
  uVar9 = auVar1._8_4_;
  if (iVar7 == 1) {
    isync();
  }
  uVar10 = uVar3;
  if (0 < iVar7) {
    uVar10 = f64iter(uVar3,uVar3,param_3,2,0,uVar8,uVar9);
    auVar1 = f64iter_1(uVar3,uVar3,param_3,2,0,uVar8,uVar9);
    uVar8 = auVar1._0_8_;
    uVar9 = auVar1._8_4_;
  }
  if (0x1f < iVar6 + -1) {
    uVar5 = rur_f64s(uVar9);
    uVar3 = f64iter(uVar10,uVar10,param_3,2,0,uVar8,uVar9);
    auVar1 = f64iter_1(uVar10,uVar10,param_3,2,0,uVar8,uVar9);
    f64iter(uVar3,uVar3,param_3,2,0,auVar1._0_8_,auVar1._8_4_);
    auVar1 = f64iter_1(uVar3,uVar3,param_3,2,0,auVar1._0_8_,auVar1._8_4_);
    uVar8 = auVar1._0_8_;
    uVar9 = auVar1._8_4_;
  }
  uVar3 = rur_f64s(uVar9);
  uVar10 = wur_f64s(uVar12);
  uVar9 = f64rnd(uVar5,uVar3,0,uVar8,uVar10);
  uVar8 = f64rnd_1(uVar5,uVar3,0,uVar8,uVar10);
  uVar5 = rf64r(0,uVar8);
  return CONCAT44(uVar9,uVar5);
}


// ===== FUN_002358e0 @ 002358e0 (23 bytes)

undefined8 FUN_002358e0(uint param_1,int param_2,uint param_3,int param_4)

{
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_4 * param_1,param_1 * param_3);
}


// ===== __udivdi3 @ 00235900 (619 bytes)

ulonglong __udivdi3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_4 == 0) {
    if (param_3 <= param_2) {
      if (param_3 == 0) {
        param_3 = 1 / param_3;
      }
      uVar3 = LZCOUNT(param_3);
      if (uVar3 == 0) {
        uVar4 = 1;
        iVar8 = ae_zext16(param_3);
        uVar3 = param_3 >> 0x10;
        param_2 = param_2 - param_3;
      }
      else {
        param_3 = param_3 << 0x20 - (0x20 - (uVar3 & 0x1f));
        uVar4 = param_2 >> (0x20 - uVar3 & 0x1f);
        iVar9 = 0x20 - (uVar3 & 0x1f);
        iVar8 = ae_zext16(param_3);
        uVar3 = param_3 >> 0x10;
        uVar1 = CONCAT44(param_2,param_1) >> iVar9;
        uVar11 = uVar4 / uVar3;
        param_1 = param_1 << 0x20 - iVar9;
        uVar10 = iVar8 * uVar11;
        uVar4 = (uint)(((ulonglong)(uVar4 % uVar3) << 0x20) >> 0x10) |
                (uint)(uVar1 >> 0x10) & 0xffff;
        uVar12 = uVar11;
        if (uVar4 < uVar10) {
          uVar4 = uVar4 + param_3;
          uVar12 = uVar11 - 1;
          if ((param_3 <= uVar4) && (uVar4 < uVar10)) {
            uVar12 = uVar11 - 2;
            uVar4 = param_3 + uVar4;
          }
        }
        param_2 = ae_zext16((int)uVar1);
        uVar2 = (uVar4 - uVar10) / uVar3;
        uVar11 = iVar8 * uVar2;
        param_2 = param_2 | (uVar4 - uVar10) % uVar3 << 0x10;
        uVar4 = uVar2;
        if (param_2 < uVar11) {
          param_2 = param_2 + param_3;
          uVar4 = uVar2 - 1;
          if ((param_3 <= param_2) && (param_2 < uVar11)) {
            uVar4 = uVar2 - 2;
            param_2 = param_3 + param_2;
          }
        }
        param_2 = param_2 - uVar11;
        uVar4 = uVar4 | uVar12 << 0x10;
      }
      uVar11 = ae_zext16(param_1);
      uVar5 = param_2 / uVar3;
      uVar2 = iVar8 * uVar5;
      uVar12 = (uint)(CONCAT44(param_2 % uVar3,param_1) >> 0x10);
      uVar10 = uVar5;
      if (uVar12 < uVar2) {
        uVar12 = uVar12 + param_3;
        uVar10 = uVar5 - 1;
        if ((param_3 <= uVar12) && (uVar12 < uVar2)) {
          uVar10 = uVar5 - 2;
          uVar12 = param_3 + uVar12;
        }
      }
      uVar5 = (uVar12 - uVar2) / uVar3;
      uVar11 = uVar11 | (uVar12 - uVar2) % uVar3 << 0x10;
      uVar3 = uVar5;
      if (uVar11 < iVar8 * uVar5) {
        uVar11 = uVar11 + param_3;
        uVar3 = uVar5 - 1;
        if ((param_3 <= uVar11) && (uVar11 < iVar8 * uVar5)) {
          return CONCAT44(uVar4,uVar5 - 2 | uVar10 << 0x10);
        }
      }
      return CONCAT44(uVar4,uVar3 | uVar10 << 0x10);
    }
    iVar8 = 0x20 - (LZCOUNT(param_3) & 0x1fU);
    uVar3 = param_1;
    if (LZCOUNT(param_3) != 0) {
      param_3 = param_3 << 0x20 - iVar8;
      uVar3 = param_1 << 0x20 - iVar8;
      param_2 = (uint)(CONCAT44(param_2,param_1) >> iVar8);
    }
    uVar10 = ae_zext16(uVar3);
    iVar8 = ae_zext16(param_3);
    uVar4 = param_3 >> 0x10;
    uVar2 = param_2 / uVar4;
    uVar11 = iVar8 * uVar2;
    uVar3 = (uint)(CONCAT44(param_2 % uVar4,uVar3) >> 0x10);
    uVar12 = uVar2;
    if (uVar3 < uVar11) {
      uVar3 = uVar3 + param_3;
      uVar12 = uVar2 - 1;
      if ((param_3 <= uVar3) && (uVar3 < uVar11)) {
        uVar12 = uVar2 - 2;
        uVar3 = param_3 + uVar3;
      }
    }
    uVar2 = (uVar3 - uVar11) / uVar4;
    uVar10 = uVar10 | (uVar3 - uVar11) % uVar4 << 0x10;
    uVar3 = uVar2;
    if (uVar10 < iVar8 * uVar2) {
      uVar10 = uVar10 + param_3;
      uVar3 = uVar2 - 1;
      if ((param_3 <= uVar10) && (uVar10 < iVar8 * uVar2)) {
        return (ulonglong)(uVar2 - 2 | uVar12 << 0x10);
      }
    }
    return (ulonglong)(uVar3 | uVar12 << 0x10);
  }
  if (param_2 < param_4) {
    return 0;
  }
  uVar3 = LZCOUNT(param_4);
  if (uVar3 != 0) {
    uVar10 = param_2 >> (0x20 - uVar3 & 0x1f);
    iVar8 = 0x20 - (uVar3 & 0x1f);
    uVar1 = CONCAT44(param_2,param_1) >> iVar8;
    uVar4 = (uint)(CONCAT44(param_4,param_3) >> iVar8);
    iVar8 = ae_zext16(uVar4);
    uVar12 = uVar4 >> 0x10;
    uVar6 = uVar10 / uVar12;
    uVar2 = iVar8 * uVar6;
    uVar10 = (uint)(((ulonglong)(uVar10 % uVar12) << 0x20) >> 0x10) | (uint)(uVar1 >> 0x10) & 0xffff
    ;
    uVar5 = ae_zext16((int)uVar1);
    uVar11 = uVar6;
    if (uVar10 < uVar2) {
      uVar10 = uVar4 + uVar10;
      uVar11 = uVar6 - 1;
      if ((uVar4 <= uVar10) && (uVar10 < uVar2)) {
        uVar11 = uVar6 - 2;
        uVar10 = uVar4 + uVar10;
      }
    }
    uVar7 = (uVar10 - uVar2) / uVar12;
    uVar6 = iVar8 * uVar7;
    iVar8 = 0x20 - (uVar3 & 0x1f);
    uVar5 = uVar5 | (uVar10 - uVar2) % uVar12 << 0x10;
    uVar3 = uVar7;
    if (uVar5 < uVar6) {
      uVar5 = uVar4 + uVar5;
      uVar3 = uVar7 - 1;
      if ((uVar4 <= uVar5) && (uVar5 < uVar6)) {
        uVar3 = uVar7 - 2;
        uVar5 = uVar4 + uVar5;
      }
    }
    param_3 = param_3 << 0x20 - iVar8;
    uVar3 = uVar3 | uVar11 << 0x10;
    uVar4 = (uint)((ulonglong)uVar3 * (ulonglong)param_3 >> 0x20);
    if ((uVar4 <= uVar5 - uVar6) &&
       ((uVar5 - uVar6 != uVar4 || (uVar3 * param_3 <= param_1 << 0x20 - iVar8)))) {
      return (ulonglong)uVar3;
    }
    return (ulonglong)(uVar3 - 1);
  }
  if ((param_2 <= param_4) && (param_1 < param_3)) {
    return 0;
  }
  return 1;
}


// ===== FUN_00235b80 @ 00235b80 (39 bytes)

void FUN_00235b80(void)

{
  undefined8 in_aed0;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar2 = ae_mov(in_aed0);
  uVar3 = recip0_s(in_aed0);
  uVar1 = const_s(1);
  uVar4 = const_s(1);
  uVar1 = maddn_s(uVar3,uVar3,(ulonglong)(uint)((float)uVar1 - (float)uVar2 * (float)uVar3));
  maddn_s(uVar1,uVar1,(ulonglong)(uint)((float)uVar4 - (float)uVar2 * (float)uVar1));
  return;
}


// ===== divf_ @ 00235ba8 (164 bytes)

/* float divide */

void divf_(void)

{
  undefined8 in_aed0;
  undefined8 in_aed1;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar4 = nexp01_s(in_aed0);
  uVar5 = nexp01_s(in_aed1);
  uVar6 = div0_s(in_aed1);
  uVar2 = const_s(1);
  uVar3 = ae_mov(in_aed0);
  uVar2 = maddn_s(uVar2,uVar5,uVar6);
  uVar7 = ae_mov(uVar6);
  uVar7 = maddn_s(uVar7,uVar2,uVar6);
  uVar2 = const_s(0);
  uVar1 = const_s(1);
  uVar1 = maddn_s(uVar1,uVar5,uVar7);
  uVar6 = msubn_s(uVar2,uVar4,uVar6);
  uVar2 = ae_mov(uVar4);
  uVar7 = maddn_s(uVar7,uVar1,uVar7);
  uVar1 = msubn_s(uVar2,uVar5,uVar6);
  uVar2 = const_s(1);
  uVar2 = maddn_s(uVar2,uVar5,uVar7);
  uVar6 = msubn_s(uVar6,uVar1,uVar7);
  uVar1 = mkdadj_s(in_aed1,uVar3);
  uVar7 = maddn_s(uVar7,uVar2,uVar7);
  uVar2 = maddn_s((ulonglong)(uint)-(float)uVar4,uVar5,uVar6);
  uVar3 = addexpm_s(uVar6,uVar1);
  uVar7 = addexp_s(uVar7,uVar1);
  divn_s(uVar3,uVar2,uVar7);
  return;
}


// ===== FUN_00235c50 @ 00235c50 (59 bytes)

void FUN_00235c50(void)

{
  float fVar1;
  undefined8 in_aed0;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar4 = ae_mov(in_aed0);
  uVar5 = rsqrt0_s(in_aed0);
  uVar3 = const_s(1);
  uVar6 = const_s(3);
  fVar1 = (float)uVar5;
  uVar2 = const_s(1);
  uVar3 = maddn_s(uVar5,(ulonglong)(uint)((float)uVar6 * fVar1),
                  (ulonglong)(uint)((float)uVar3 - (float)uVar4 * fVar1 * fVar1));
  fVar1 = (float)uVar3;
  maddn_s(uVar3,(ulonglong)(uint)((float)uVar6 * fVar1),
          (ulonglong)(uint)((float)uVar2 - (float)uVar4 * fVar1 * fVar1));
  return;
}


// ===== sqrtf_ @ 00235c8c (160 bytes)

/* sqrt */

void sqrtf_(void)

{
  undefined8 in_aed0;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar3 = ae_mov(in_aed0);
  uVar4 = sqrt0_s(in_aed0);
  uVar2 = const_s(0);
  uVar1 = const_s(3);
  uVar5 = nexp01_s(in_aed0);
  uVar2 = maddn_s(uVar2,uVar4,uVar4);
  uVar6 = addexp_s(uVar5,uVar1);
  uVar1 = maddn_s(uVar1,uVar2,uVar6);
  uVar4 = maddn_s(uVar4,uVar1,uVar4);
  uVar7 = nexp01_s(in_aed0);
  uVar1 = const_s(0);
  uVar2 = ae_mov(uVar1);
  uVar8 = msubn_s(uVar1,uVar7,uVar4);
  uVar1 = const_s(3);
  uVar5 = ae_mov(uVar2);
  uVar6 = maddn_s(uVar2,uVar4,uVar6);
  uVar2 = maddn_s(uVar5,uVar1,uVar4);
  uVar5 = maddn_s(uVar7,uVar8,uVar8);
  uVar4 = maddn_s(uVar1,uVar6,uVar4);
  uVar1 = maddn_s(uVar8,uVar5,(ulonglong)(uint)-(float)uVar2);
  uVar5 = nexp01_s(uVar3);
  uVar4 = maddn_s(uVar2,uVar4,uVar2);
  uVar3 = mksadj_s(uVar3);
  uVar2 = maddn_s(uVar5,uVar1,uVar1);
  uVar1 = addexpm_s(uVar1,uVar3);
  uVar4 = addexp_s((ulonglong)(uint)-(float)uVar4,uVar3);
  divn_s(uVar1,uVar2,uVar4);
  return;
}


// ===== memcpy @ 00235d30 (364 bytes)

void memcpy(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined2 uVar1;
  ulonglong *puVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  
  if (((uint)param_1 & 1) != 0) {
    if (param_3 < 7) goto LAB_00235e60;
    param_3 = param_3 - 1;
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  if (((uint)param_1 >> 1 & 1) != 0) {
    if (param_3 < 6) {
LAB_00235e60:
      if (param_3 == 1) {
        isync();
      }
      if (param_3 != 0) {
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
      }
      return;
    }
    uVar4 = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_3 = param_3 - 2;
    *(undefined1 *)((int)param_1 + 1) = uVar4;
    param_2 = (undefined4 *)((int)param_2 + 2);
    param_1 = (undefined4 *)((int)param_1 + 2);
  }
  uVar9 = param_3 >> 4;
  if (((uint)param_2 & 3) != 0) {
    if (param_3 == 0) {
      return;
    }
    iVar8 = ((uint)param_2 & 3) << 3;
    puVar6 = (undefined4 *)((int)param_2 - ((uint)param_2 & 3));
    if (uVar9 == 1) {
      isync();
    }
    uVar7 = *puVar6;
    if (uVar9 != 0) {
      uVar11 = puVar6[2];
      uVar5 = *(ulonglong *)(puVar6 + 1);
      *param_1 = (int)(CONCAT44((int)*(ulonglong *)(puVar6 + 1),uVar7) >> iVar8);
      uVar10 = puVar6[3];
      param_1[1] = (int)(uVar5 >> iVar8);
      uVar7 = puVar6[4];
      puVar6 = puVar6 + 4;
      param_1[2] = (int)(CONCAT44(uVar10,uVar11) >> iVar8);
      param_1[3] = (int)(CONCAT44(uVar7,uVar10) >> iVar8);
      param_1 = param_1 + 4;
    }
    uVar11 = uVar7;
    if ((param_3 & 8) != 0) {
      puVar2 = (ulonglong *)(puVar6 + 1);
      uVar11 = puVar6[2];
      uVar5 = *puVar2;
      puVar6 = puVar6 + 2;
      *param_1 = (int)(CONCAT44((int)*puVar2,uVar7) >> iVar8);
      param_1[1] = (int)(uVar5 >> iVar8);
      param_1 = param_1 + 2;
    }
    if ((param_3 & 4) != 0) {
      puVar3 = puVar6 + 1;
      puVar6 = puVar6 + 1;
      *param_1 = (int)(CONCAT44(*puVar3,uVar11) >> iVar8);
      param_1 = param_1 + 1;
    }
    puVar12 = (undefined1 *)((int)puVar6 + ((uint)param_2 & 3));
    if ((param_3 >> 1 & 1) == 0) {
      if ((param_3 & 1) == 0) {
        return;
      }
    }
    else {
      uVar4 = puVar12[1];
      *(undefined1 *)param_1 = *puVar12;
      puVar12 = puVar12 + 2;
      *(undefined1 *)((int)param_1 + 1) = uVar4;
      param_1 = (undefined4 *)((int)param_1 + 2);
      if ((param_3 & 1) == 0) {
        return;
      }
    }
    *(undefined1 *)param_1 = *puVar12;
    return;
  }
  if (uVar9 == 1) {
    isync();
  }
  if (uVar9 != 0) {
    uVar11 = param_2[1];
    *param_1 = *param_2;
    uVar7 = param_2[2];
    param_1[1] = uVar11;
    uVar11 = param_2[3];
    param_2 = param_2 + 4;
    param_1[2] = uVar7;
    param_1[3] = uVar11;
    param_1 = param_1 + 4;
  }
  if ((param_3 & 8) != 0) {
    uVar7 = param_2[1];
    *param_1 = *param_2;
    param_2 = param_2 + 2;
    param_1[1] = uVar7;
    param_1 = param_1 + 2;
  }
  if ((param_3 & 4) == 0) {
    if ((param_3 & 2) == 0) {
      if ((param_3 & 1) == 0) {
        return;
      }
      goto LAB_00235db2;
    }
  }
  else {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    if ((param_3 >> 1 & 1) == 0) {
      if ((param_3 & 1) == 0) {
        return;
      }
      goto LAB_00235db2;
    }
  }
  uVar1 = *(undefined2 *)param_2;
  param_2 = (undefined4 *)((int)param_2 + 2);
  *(undefined2 *)param_1 = uVar1;
  param_1 = (undefined4 *)((int)param_1 + 2);
  if ((param_3 & 1) == 0) {
    return;
  }
LAB_00235db2:
  *(undefined1 *)param_1 = *(undefined1 *)param_2;
  return;
}


// ===== memset @ 00235eb0 (134 bytes)

void memset(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = CONCAT11(param_2,param_2);
  uVar2 = CONCAT22(uVar1,uVar1);
  if (((uint)param_1 & 1) != 0) {
    if (param_3 < 8) goto LAB_00235f2e;
    *(undefined1 *)param_1 = param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_3 = param_3 - 1;
  }
  if (((uint)param_1 & 2) != 0) {
    if (param_3 < 8) {
LAB_00235f2e:
      if (param_3 == 1) {
        isync();
      }
      if (param_3 != 0) {
        *(undefined1 *)param_1 = param_2;
      }
      return;
    }
    *(undefined2 *)param_1 = uVar1;
    param_3 = param_3 - 2;
    param_1 = (undefined4 *)((int)param_1 + 2);
  }
  if (param_3 >> 4 == 1) {
    isync();
  }
  if (param_3 >> 4 != 0) {
    *param_1 = uVar2;
    param_1[1] = uVar2;
    param_1[2] = uVar2;
    param_1[3] = uVar2;
    param_1 = param_1 + 4;
  }
  if ((param_3 & 8) != 0) {
    *param_1 = uVar2;
    param_1[1] = uVar2;
    param_1 = param_1 + 2;
  }
  if ((param_3 & 4) != 0) {
    *param_1 = uVar2;
    param_1 = param_1 + 1;
  }
  if ((param_3 & 2) != 0) {
    *(undefined2 *)param_1 = uVar1;
    param_1 = (undefined4 *)((int)param_1 + 2);
  }
  if ((param_3 & 1) != 0) {
    *(undefined1 *)param_1 = param_2;
  }
  return;
}


// ===== FUN_00235f40 @ 00235f40 (5 bytes)

void FUN_00235f40(void)

{
  return;
}


// ===== FUN_00235f50 @ 00235f50 (5 bytes)

void FUN_00235f50(void)

{
  return;
}


// ===== FUN_00235f60 @ 00235f60 (5 bytes)

void FUN_00235f60(void)

{
  return;
}


// ===== FUN_00235f70 @ 00235f70 (5 bytes)

void FUN_00235f70(void)

{
  return;
}


// ===== FUN_00235fa0 @ 00235fa0 (84 bytes)

uint FUN_00235fa0(int param_1,code *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(param_1 + 0x2e0);
  if (param_1 != -0x2e0) {
    uVar1 = 0;
    do {
      iVar5 = piVar4[2];
      if (0 < piVar4[1]) {
        iVar3 = iVar5 + piVar4[1] * 0x68;
        do {
          if (((*(short *)(iVar5 + 0xc) != 0) && (*(short *)(iVar5 + 0xc) != 1)) &&
             (*(short *)(iVar5 + 0xe) != -1)) {
            uVar2 = (*param_2)(iVar5);
            uVar1 = uVar2 | uVar1;
          }
          iVar5 = iVar5 + 0x68;
        } while (iVar5 != iVar3);
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    return uVar1;
  }
  return 0;
}


// ===== FUN_00236000 @ 00236000 (89 bytes)

uint FUN_00236000(int param_1,code *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(param_1 + 0x2e0);
  if (param_1 != -0x2e0) {
    uVar1 = 0;
    do {
      iVar5 = piVar4[2];
      if (0 < piVar4[1]) {
        iVar3 = iVar5 + piVar4[1] * 0x68;
        do {
          if (((*(short *)(iVar5 + 0xc) != 0) && (*(short *)(iVar5 + 0xc) != 1)) &&
             (*(short *)(iVar5 + 0xe) != -1)) {
            uVar2 = (*param_2)(param_1,iVar5);
            uVar1 = uVar2 | uVar1;
          }
          iVar5 = iVar5 + 0x68;
        } while (iVar5 != iVar3);
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    return uVar1;
  }
  return 0;
}


// ===== FUN_00236060 @ 00236060 (24 bytes)

void FUN_00236060(int param_1,int *param_2)

{
  int *piVar1;
  
  if (param_2 != (int *)0x0) {
    piVar1 = (int *)(param_2[1] * 4 + *(int *)(param_1 + 0x4c));
    *param_2 = *piVar1;
    *piVar1 = (int)param_2;
    return;
  }
  return;
}


// ===== FUN_00236080 @ 00236080 (80 bytes)

int FUN_00236080(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 >> 0x10 == 0) {
    iVar1 = 0x10;
    param_1 = param_1 << 0x10;
  }
  if (param_1 >> 0x18 == 0) {
    iVar1 = iVar1 + 8;
    param_1 = param_1 << 8;
  }
  if (param_1 >> 0x1c == 0) {
    iVar1 = iVar1 + 4;
    param_1 = param_1 << 4;
  }
  if (param_1 >> 0x1e == 0) {
    iVar1 = iVar1 + 2;
    param_1 = param_1 << 2;
  }
  if ((-1 < (int)param_1) && (iVar1 = iVar1 + 1, (param_1 >> 0x1e & 1) == 0)) {
    return 0x20;
  }
  return iVar1;
}

