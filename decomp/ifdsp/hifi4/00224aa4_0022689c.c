// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== Thread_Spi_entry @ 00224aa4 (655 bytes)

void Thread_Spi_entry(void)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  undefined2 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined1 *puVar10;
  undefined *puVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined4 uStack_40;
  undefined1 auStack_3c [4];
  int iStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  
  FUN_002210a4();
  uVar1 = FUN_002211b8();
  memset(uVar1,1,200);
  memset(&DAT_00266490,1,400);
  FUN_00221198(200,&DAT_00266490,400);
  uVar8 = const_s(0);
  uVar9 = 0x3dfa35de;
  uVar7 = 0x40c90fdb;
  uVar13 = ae_mov(uVar8);
  puVar10 = &DAT_00266490;
  do {
    uVar6 = (ulonglong)(uint)((float)uVar13 + (float)uVar9);
    uVar5 = olt_s(uVar7,uVar6);
    if (SUB21(uVar5,0)) {
      do {
        uVar13 = ae_l32_i(0xc0c90fdb);
        uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar13);
        uVar5 = olt_s(uVar7,uVar6);
      } while (SUB21(uVar5,0));
    }
    uVar5 = olt_s(uVar6,uVar8);
    uStack_30 = ae_s32_l_i(uVar6);
    if (SUB21(uVar5,0)) {
      do {
        uVar6 = (ulonglong)(uint)((float)uVar6 + (float)uVar7);
        uVar5 = olt_s(uVar6,uVar8);
      } while (SUB21(uVar5,0));
      uStack_30 = ae_s32_l_i(uVar6);
    }
    uVar13 = ae_l32_i(uStack_30);
    FUN_00218fc0();
    uStack_40 = ae_s32_l_i(uVar13);
    FUN_00224df0(&uStack_40,auStack_3c,1);
    puVar10[1] = auStack_3c[0];
    uVar13 = ae_l32_i(uStack_30);
    *puVar10 = auStack_3c[0];
    uVar7 = ae_l32_i(0x40c90fdb);
    uVar8 = ae_l32_i(0);
    puVar10 = puVar10 + 2;
    uVar9 = ae_l32_i(0x3dfa35de);
  } while (puVar10 != &DAT_00266620);
  FUN_00221198(200,&DAT_00266490,400);
  iVar2 = FUN_002211b8();
  *(undefined1 *)(iVar2 + 600) = 0;
  *(undefined1 *)(iVar2 + 0x259) = 0;
  *(undefined1 *)(iVar2 + 0x25a) = 0;
  *(undefined1 *)(iVar2 + 0x25b) = 0;
  iVar2 = FUN_002211b8();
  memset(iVar2 + 0x25c,0xf0,0xf9c);
  do {
    do {
      while( true ) {
        do {
          iVar2 = xos_msgq_get(PTR_DAT_002374f4,&iStack_38);
        } while (iVar2 != 0);
        if (iStack_38 == 0) break;
        if (iStack_38 == 1) {
          FUN_002211c0();
          FUN_00225834();
        }
      }
    } while (DAT_002642a0 < 7);
    uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uStack_34 = uVar4 & 0xf;
    if (uStack_34 < 2) {
      uVar4 = uVar4 & 0xfffffff0 | 2;
      in_st_PSWOE = wsr_ps(uVar4);
      in_st_PSCALLINC = wsr_ps_1(uVar4);
      in_st_PSOWB = wsr_ps_2(uVar4);
      in_st_PSUM = wsr_ps_3(uVar4);
      in_st_PSEXCM = wsr_ps_4(uVar4);
      in_st_PSINTLEVEL = wsr_ps_5(uVar4);
      rsync();
    }
    iVar2 = 0;
    puVar11 = &DAT_00266620;
    do {
      memcpy(puVar11,&DAT_00263d60 + (uint)DAT_002642a2 * 0x60,0x60);
      iVar2 = iVar2 + 1;
      puVar11 = puVar11 + 0x60;
      if (DAT_002642a2 < 0xd) {
        DAT_002642a2 = DAT_002642a2 + 1;
      }
      else {
        DAT_002642a2 = 0;
      }
      DAT_002642a0 = DAT_002642a0 - 1;
    } while (iVar2 != 7);
    uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar4 = uStack_34 | uVar4 & 0xfffffff0;
    in_st_PSWOE = wsr_ps(uVar4);
    in_st_PSCALLINC = wsr_ps_1(uVar4);
    in_st_PSOWB = wsr_ps_2(uVar4);
    in_st_PSUM = wsr_ps_3(uVar4);
    in_st_PSEXCM = wsr_ps_4(uVar4);
    in_st_PSINTLEVEL = wsr_ps_5(uVar4);
    rsync();
    FUN_00233a10(DAT_002642a8,&DAT_00266b20,&DAT_00266620,0xa8);
    uVar13 = ae_l32_ip(DAT_00266b20);
    DAT_002668c0 = ae_s32_l_ip(uVar13);
    uVar13 = ae_l32_ip(DAT_00266b3c);
    uVar4 = (uint)DAT_00264b68;
    DAT_002668c4 = ae_s32_l_ip(uVar13);
    if (uVar4 < 0xe9) {
      uVar13 = ae_l32_ip(DAT_002668c0);
      uVar1 = ae_s32_l_i(uVar13);
      *(undefined4 *)(&DAT_00264768 + (uint)DAT_00264b69 * 4) = uVar1;
      bVar3 = 0;
      if (DAT_00264b69 != 0xff) {
        bVar3 = DAT_00264b69 + 1;
      }
      uVar4 = DAT_00264b68 + 1 & 0xff;
      DAT_00264b68 = (byte)(DAT_00264b68 + 1);
      DAT_00264b69 = bVar3;
    }
    if (uVar4 >> 7 != 0) {
      uVar12 = (uint)DAT_00264b6a;
      DAT_00264b68 = (char)uVar4 - 1;
      uVar13 = ae_l32_i(*(undefined4 *)(&DAT_00264768 + uVar12 * 4));
      DAT_00264b6a = DAT_00264b6a + 1;
      DAT_00266920 = ae_s32_l_ip(uVar13);
      if (0xfe < uVar12) {
        DAT_00264b6a = 0;
      }
      FUN_00224060(&DAT_00266920);
      iVar2 = FUN_00223c8c(&DAT_00266920);
      if (iVar2 != 0) {
        FUN_002211b8();
        FUN_00223fe8();
        iVar2 = FUN_002211b8();
        FUN_002244c8(iVar2 + 200);
        iVar2 = FUN_002211b8();
        FUN_00225790(iVar2 + 600);
        FUN_002210dc();
      }
    }
  } while( true );
}


// ===== spi_post_tx_done @ 00224d40 (23 bytes)

void spi_post_tx_done(void)

{
  undefined4 auStack_30 [12];
  
  auStack_30[0] = 1;
  xos_msgq_put(PTR_DAT_002374f4,auStack_30);
  return;
}


// ===== spi_fifo_push @ 00224d58 (152 bytes)

undefined4 spi_fifo_push(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  bool bVar3;
  undefined4 auStack_30 [12];
  
  if (DAT_002642a0 == '\x0e') {
    return 0;
  }
  uVar1 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar1 & 0xf) < 2) {
    uVar2 = uVar1 & 0xfffffff0 | 2;
    in_st_PSWOE = wsr_ps(uVar2);
    in_st_PSCALLINC = wsr_ps_1(uVar2);
    in_st_PSOWB = wsr_ps_2(uVar2);
    in_st_PSUM = wsr_ps_3(uVar2);
    in_st_PSEXCM = wsr_ps_4(uVar2);
    in_st_PSINTLEVEL = wsr_ps_5(uVar2);
    rsync();
  }
  memcpy(&DAT_00263d60 + (uint)DAT_002642a1 * 0x60,param_1,0x60);
  bVar3 = 0xc < DAT_002642a1;
  DAT_002642a1 = DAT_002642a1 + 1;
  if (bVar3) {
    DAT_002642a1 = '\0';
  }
  DAT_002642a0 = DAT_002642a0 + 1;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar1 = uVar1 & 0xf | uVar2 & 0xfffffff0;
  wsr_ps(uVar1);
  wsr_ps_1(uVar1);
  wsr_ps_2(uVar1);
  wsr_ps_3(uVar1);
  wsr_ps_4(uVar1);
  wsr_ps_5(uVar1);
  rsync();
  if (6 < DAT_002642a0) {
    auStack_30[0] = 0;
    xos_msgq_put(PTR_DAT_002374f4,auStack_30);
    return 1;
  }
  return 1;
}


// ===== FUN_00224df0 @ 00224df0 (139 bytes)

undefined8 FUN_00224df0(undefined4 *param_1,char *param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  undefined2 uVar3;
  float fVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  uVar8 = const_s(3);
  if (param_3 != 0) {
    uVar6 = ae_l32_ip(*param_1);
    param_1 = param_1 + 1;
    uVar5 = (ulonglong)(uint)((float)uVar6 * (float)uVar8 * 124.0);
    uVar3 = olt_s(uVar5,0xc2f80000);
    if ((SUB21(uVar3,0)) || (uVar3 = olt_s(0x42f80000,uVar5), !SUB21(uVar3,0))) {
      uVar3 = olt_s(uVar5,0xc2f80000);
      uVar8 = movt_s(uVar5,0xc2f80000,(char)uVar3);
      fVar4 = (float)uVar8;
    }
    else {
      uVar8 = ae_mov(0x42f80000);
      fVar4 = (float)uVar8;
    }
    uVar7 = utrunc_s((ulonglong)(uint)(fVar4 + 126.0),0);
    uVar2 = uVar7 & 0xff;
    if ((uVar2 < 2) || (uVar2 < 0xfb)) {
      cVar1 = (uVar2 < 2) * '\x02' + (uVar2 >= 2) * (char)uVar7;
    }
    else {
      cVar1 = -6;
    }
    *param_2 = cVar1;
    param_2 = param_2 + 1;
  }
  return CONCAT44(param_2,param_1);
}


// ===== FUN_00224e80 @ 00224e80 (85 bytes)

void FUN_00224e80(int param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  memset(&DAT_00266e10 + param_1 * 0x26,0);
  uVar2 = const_s(1);
  uVar1 = ae_s32_l_i(uVar2);
  *(undefined4 *)(&DAT_00266e30 + param_1 * 0x4c) = uVar1;
  uVar1 = ae_s32_l_x(uVar2);
  (&DAT_00266e34)[param_1 * 0x13] = uVar1;
  if (param_1 != 0) {
    DAT_00266e5c = 0x57;
    DAT_00266e5e = 0x58;
    DAT_00266e68 = 0x30;
    return;
  }
  DAT_00266e10 = 0x2e;
  DAT_00266e12 = 0x3b;
  DAT_00266e1c = 4;
  return;
}


// ===== FUN_00224ed8 @ 00224ed8 (873 bytes)

void FUN_00224ed8(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 extraout_a3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined2 uVar7;
  float in_aed0;
  ulonglong uVar8;
  float fVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  ushort uVar17;
  ushort uVar18;
  undefined2 *puVar19;
  uint uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  
  iVar4 = param_1 * 0x4c;
  puVar19 = &DAT_00266e10 + param_1 * 0x26;
  iVar6 = ae_l16ui_n(puVar19,0);
  uVar18 = *(ushort *)(&DAT_20070000 + iVar6 * 2);
  fVar9 = 0.05;
  uVar2 = (&DAT_00266e12)[param_1 * 0x26];
  uVar17 = uVar18 & 0xff;
  if (*(ushort *)(&DAT_00266e14 + iVar4) == uVar18) {
    iVar6 = ae_l16ui_n(puVar19,2);
    uVar20 = (uint)*(ushort *)(&DAT_20070000 + iVar6 * 2);
    if (*(ushort *)(&DAT_00266e16 + iVar4) == uVar20) goto LAB_00224f7d;
LAB_002251f0:
    *(short *)(&DAT_00266e16 + iVar4) = (short)uVar20;
    uVar5 = 0;
    if ((uVar20 >> 0xb & 1) != 0) {
      uVar5 = uVar20 | 0xfffff000;
    }
    FUN_00234730(uVar5,0xffffffff);
    uVar15 = ae_l32_i(0x3d4ccccd);
    uVar8 = (ulonglong)(uint)(in_aed0 * (float)uVar15);
    FUN_00218b70();
    uVar1 = ae_s32_l_i(uVar8);
    *(undefined4 *)(&DAT_00266e20 + iVar4) = uVar1;
    uVar15 = ae_l32_i(0x3d4ccccd);
    fVar9 = (float)uVar15;
    uVar18 = *(ushort *)(&DAT_00266e18 + iVar4);
  }
  else {
    *(ushort *)(&DAT_00266e14 + iVar4) = uVar18;
    uVar18 = uVar18 >> 0xc & 1;
    *(ushort *)(&DAT_00266e18 + iVar4) = uVar18;
    if (100 < uVar17) {
      uVar17 = 100;
    }
    *(ushort *)(&DAT_00266e1a + iVar4) = uVar17;
    uVar20 = (uint)*(ushort *)(&DAT_20070000 + (uint)uVar2 * 2);
    if (*(ushort *)(&DAT_00266e16 + iVar4) != uVar20) goto LAB_002251f0;
  }
  if (uVar18 != 0) {
    uVar15 = float_s((uint)*(ushort *)(&DAT_00266e1a + iVar4),0);
    uVar8 = (ulonglong)(uint)((float)uVar15 * 0.06 * fVar9);
    FUN_00218b70();
    uVar1 = ae_s32_l_i(uVar8);
    *(undefined4 *)(&DAT_00266e24 + iVar4) = uVar1;
    FUN_00234730(*(undefined2 *)(&DAT_00237500 + (uint)*(ushort *)(&DAT_00266e1a + iVar4) * 2),0);
    const_s(2);
    uVar15 = ae_l32_i(0x3f800000);
    FUN_00235ba8();
    uVar1 = ae_s32_l_i(uVar15);
    *(undefined4 *)(&DAT_00266e28 + iVar4) = uVar1;
    uVar1 = ae_s32_l_i(uVar15);
    *(undefined4 *)(&DAT_00266e2c + iVar4) = uVar1;
  }
LAB_00224f7d:
  if (*(short *)(&DAT_00266e18 + iVar4) == 0) {
    if (param_2 != param_3) {
      memcpy(param_3,param_2,(&DAT_00266e1c)[param_1 * 0x13] << 2);
      return;
    }
  }
  else {
    uVar20 = 0;
    if ((&DAT_00266e1c)[param_1 * 0x13] != 0) {
      uVar15 = const_s(0);
      do {
        uVar2 = *(ushort *)(&DAT_00266e38 + iVar4);
        uVar16 = ae_l32_i(*param_2);
        uVar21 = ae_l32_i(*(undefined4 *)(&DAT_00266e24 + iVar4));
        *(ushort *)(&DAT_00266e38 + iVar4) = uVar2 + 1;
        uVar1 = ae_s32_l_i((ulonglong)(uint)((float)uVar21 * (float)uVar16));
        *(undefined4 *)(puVar19 + (uint)uVar2 * 2 + 0x16) = uVar1;
        uVar5 = (uint)*(ushort *)(&DAT_00266e38 + iVar4);
        if (6 < uVar5) {
          *(undefined2 *)(&DAT_00266e38 + iVar4) = 0;
          uVar5 = 0;
        }
        uVar11 = ae_l32_ip(*(undefined4 *)(&DAT_00266e3c + iVar4));
        uVar16 = ae_l32_i(*(undefined4 *)(puVar19 + uVar5 * 2 + 0x16));
        uVar1 = ae_s32_l_i(uVar16);
        uVar22 = ae_l32_ip(*(undefined4 *)(&DAT_00266e40 + iVar4));
        uVar21 = ae_l32_ip(*(undefined4 *)(&DAT_00266e44 + iVar4));
        uVar16 = ae_l32_ip(*(undefined4 *)(&DAT_00266e48 + iVar4));
        uVar14 = ae_l32_ip(*(undefined4 *)(&DAT_00266e4c + iVar4));
        uVar12 = ae_l32_ip(*(undefined4 *)(&DAT_00266e50 + iVar4));
        uVar10 = ae_l32_ip(*(undefined4 *)(&DAT_00266e54 + iVar4));
        uVar13 = ae_l32_i(0x3e124925);
        uVar8 = (ulonglong)
                (uint)(((float)uVar15 + (float)uVar11 * (float)uVar11 +
                        (float)uVar22 * (float)uVar22 + (float)uVar21 * (float)uVar21 +
                        (float)uVar16 * (float)uVar16 + (float)uVar14 * (float)uVar14 +
                        (float)uVar12 * (float)uVar12 + (float)uVar10 * (float)uVar10) *
                      (float)uVar13);
        uVar3 = ae_s32_l_i(uVar8);
        FUN_00235c8c();
        uVar7 = oeq_s(uVar8,uVar8);
        uVar16 = ae_l32_i(0x3f800000);
        uVar15 = ae_l32_i(0);
        if (!SUB21(uVar7,0)) {
          uVar8 = ae_l32_i(uVar3);
          FUN_00229a20();
          uVar16 = ae_l32_i(0x3f800000);
          uVar15 = ae_l32_i(0);
        }
        uVar21 = ae_l32_i(0x3fb504f3);
        uVar8 = (ulonglong)(uint)((float)uVar21 * (float)uVar8);
        uVar21 = ae_l32_i(*(undefined4 *)(&DAT_00266e20 + iVar4));
        uVar7 = olt_s(uVar21,uVar8);
        uVar3 = ae_s32_l_i(uVar8);
        *(undefined4 *)(&DAT_00266e58 + iVar4) = uVar3;
        if (SUB21(uVar7,0)) {
          FUN_00235ba8();
          uVar15 = ae_l32_i(0x38d1b717);
          uVar7 = olt_s(uVar15,uVar21);
          uVar16 = ae_l32_i(0x3f800000);
          uVar21 = ae_mov(uVar21);
          uVar21 = movf_s(uVar21,uVar15,(char)uVar7);
          uVar15 = ae_l32_i(0);
        }
        else {
          uVar21 = ae_mov(uVar16);
        }
        uVar10 = ae_l32_i(*(undefined4 *)(&DAT_00266e30 + iVar4));
        uVar7 = olt_s(uVar21,uVar10);
        uVar11 = ae_l32_i(*(undefined4 *)(&DAT_00266e28 + iVar4));
        if (SUB21(uVar7,0)) {
          uVar8 = (ulonglong)(uint)((float)uVar11 * ((float)uVar16 - (float)uVar21));
          uVar7 = olt_s(uVar8,uVar15);
          uVar3 = ae_s32_l_i(uVar21);
          *(undefined4 *)(&DAT_00266e30 + iVar4) = uVar3;
          uVar3 = ae_s32_l_i(uVar8);
          *(undefined4 *)(&DAT_00266e2c + iVar4) = uVar3;
          uVar8 = ae_mov(uVar21);
          if (SUB21(uVar7,0)) {
            uVar3 = ae_s32_l_i(uVar16);
            *(undefined4 *)(&DAT_00266e2c + iVar4) = uVar3;
          }
        }
        else {
          uVar7 = ole_s(uVar10,uVar16);
          if (SUB21(uVar7,0)) {
            uVar21 = ae_l32_i(*(undefined4 *)(&DAT_00266e2c + iVar4));
            uVar8 = (ulonglong)(uint)((float)uVar21 + (float)uVar10);
          }
          else {
            uVar8 = ae_mov(uVar16);
          }
          uVar3 = ae_s32_l_i(uVar8);
          *(undefined4 *)(&DAT_00266e30 + iVar4) = uVar3;
        }
        uVar7 = olt_s(uVar16,uVar8);
        uVar21 = ae_l32_i(uVar1);
        uVar10 = ae_mov(uVar16);
        if (SUB21(uVar7,0)) {
LAB_00225114:
          uVar7 = olt_s(uVar16,uVar8);
          uVar16 = movf_s(uVar10,uVar8,(char)uVar7);
        }
        else {
          uVar11 = ae_l32_i(0x3a83126f);
          uVar7 = olt_s(uVar8,uVar11);
          if ((char)uVar7 == '\0') goto LAB_00225114;
          uVar16 = ae_l32_i(0x3a83126f);
        }
        uVar1 = ae_s32_l_i(uVar16);
        *(undefined4 *)(&DAT_00266e30 + iVar4) = uVar1;
        uVar1 = ae_s32_l_i((ulonglong)(uint)((float)uVar21 * (float)uVar16));
        *param_3 = uVar1;
        uVar16 = ae_l32_i((&DAT_00266e34)[param_1 * 0x13]);
        uVar21 = ae_l32_i(*(undefined4 *)(&DAT_00266e30 + iVar4));
        uVar7 = olt_s(uVar21,uVar16);
        uVar20 = uVar20 + 1;
        param_2 = param_2 + 1;
        param_3 = param_3 + 1;
        if (SUB21(uVar7,0)) {
          uVar1 = ae_s32_l_i(uVar21);
          (&DAT_00266e34)[param_1 * 0x13] = uVar1;
        }
      } while (uVar20 < (uint)(&DAT_00266e1c)[param_1 * 0x13]);
    }
    if (param_1 == 0) {
      iVar4 = ae_l16ui_n(&DAT_00266e00,0);
      uVar20 = ae_zext16(iVar4 + 1);
      if (uVar20 < 5) {
        ae_s16i_n(uVar20,&DAT_00266e00,0);
        return;
      }
      DAT_00266e00 = 0;
      ae_l32_i(DAT_00266e34);
      FUN_002190f0();
      iVar6 = FUN_00234710(0xffffffff,extraout_a3,0xc1a00000);
      uVar15 = ae_l32_i(0x3f800000);
      DAT_00266e34 = ae_s32_l_i(uVar15);
      iVar4 = iVar6;
      if (0xff < iVar6) {
        iVar4 = 0xff;
      }
      if ((iVar6 != 0) && (iVar6 < 1)) {
        DAT_20070004 = DAT_20070004 & 0xff00;
        return;
      }
      DAT_20070004 = DAT_20070004 & 0xff00 | (ushort)iVar4 & 0xff;
      return;
    }
  }
  return;
}


// ===== FUN_00225250 @ 00225250 (19 bytes)

void FUN_00225250(void)

{
  DAT_00266ea8 = 0;
  DAT_00266eac = 0;
  DAT_00266eb0 = 0;
  DAT_00266eb4 = 0;
  return;
}


// ===== FUN_00225264 @ 00225264 (213 bytes)

void FUN_00225264(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 uVar3;
  float in_aed0;
  float fVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  if ((short)DAT_00266ea8 != DAT_20078026) {
    DAT_00266ea8._0_2_ = DAT_20078026;
    FUN_00234730(DAT_20078026,0);
    DAT_00266eb0 = ae_s32_l_i((ulonglong)(uint)(in_aed0 * 8.726647e-05));
  }
  if ((int)DAT_00266ea8._2_2_ != (int)DAT_20078028) {
    DAT_00266ea8._2_2_ = DAT_20078028;
    FUN_00234730((int)DAT_20078028,0xffffffff);
    uVar5 = (ulonglong)(uint)(in_aed0 * 0.05);
    FUN_00218b70();
    DAT_00266eb4 = ae_s32_l_i(uVar5);
  }
  if (param_2 != 0) {
    uVar7 = const_s(0);
    iVar2 = 0;
    uVar6 = 0x40c90fdb;
    do {
      uVar8 = ae_l32_i(DAT_00266eb0);
      uVar9 = ae_l32_i(DAT_00266eac);
      uVar5 = (ulonglong)(uint)((float)uVar9 + (float)uVar8);
      uVar3 = olt_s(uVar6,uVar5);
      DAT_00266eac = ae_s32_l_i(uVar5);
      if (SUB21(uVar3,0)) {
        do {
          uVar8 = ae_l32_i(0xc0c90fdb);
          uVar5 = (ulonglong)(uint)((float)uVar5 + (float)uVar8);
          uVar3 = olt_s(uVar6,uVar5);
          DAT_00266eac = ae_s32_l_i(uVar5);
        } while (SUB21(uVar3,0));
      }
      uVar3 = olt_s(uVar5,uVar7);
      if (SUB21(uVar3,0)) {
        do {
          uVar5 = (ulonglong)(uint)((float)uVar5 + (float)uVar6);
          uVar3 = olt_s(uVar5,uVar7);
          DAT_00266eac = ae_s32_l_i(uVar5);
        } while (SUB21(uVar3,0));
      }
      fVar4 = (float)uVar5;
      FUN_00218fc0();
      uVar6 = ae_l32_i(DAT_00266eb4);
      iVar2 = iVar2 + 1;
      uVar1 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * fVar4));
      *param_1 = uVar1;
      param_1 = param_1 + 1;
      uVar6 = ae_l32_i(0x40c90fdb);
      uVar7 = ae_l32_i(0);
    } while (param_2 != iVar2);
  }
  return;
}


// ===== FUN_00225340 @ 00225340 (46 bytes)

void FUN_00225340(int param_1)

{
  undefined4 uVar1;
  
  memset(param_1 + 600,0,0x8c);
  *(undefined2 *)(param_1 + 0x2e4) = 0;
  uVar1 = FUN_00233984(param_1,0x47,&DAT_00205840);
  *(undefined4 *)(param_1 + 0x2e8) = uVar1;
  return;
}


// ===== FUN_00225370 @ 00225370 (119 bytes)

void FUN_00225370(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,int param_5
                 )

{
  undefined4 uVar1;
  ushort uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x200;
  if (((param_5 != 0) && (uVar4 = (uint)*(ushort *)(param_1 + 0x2e4), param_5 != 0)) &&
     ((param_5 == 1 || (param_5 != 0)))) {
    uVar2 = *(ushort *)(param_1 + 0x2e4);
    uVar3 = ae_l32_i(*(undefined4 *)(uVar4 * 4 + param_1 + 600));
    uVar1 = ae_s32_l_ip(uVar3);
    *param_3 = uVar1;
    *(ushort *)(param_1 + 0x2e4) = uVar2 + 1;
    uVar3 = ae_l32_i(*param_2);
    uVar1 = ae_s32_l_i(uVar3);
    *(undefined4 *)((uint)uVar2 * 4 + param_1 + 600) = uVar1;
    uVar4 = (uint)*(ushort *)(param_1 + 0x2e4);
    if (0x22 < uVar4) {
      *(undefined2 *)(param_1 + 0x2e4) = 0;
      uVar4 = 0;
    }
  }
  FUN_00233a10(*(undefined4 *)(param_1 + 0x2e8),param_4,param_2,param_5,uVar4);
  return;
}


// ===== FUN_002253f0 @ 002253f0 (23 bytes)

void FUN_002253f0(int param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = const_s(1);
  ae_s16i_n(0,param_1,0);
  ae_s16i_n(0x48,param_1,2);
  uVar1 = ae_s32_l_i(uVar2);
  *(undefined4 *)(param_1 + 4) = uVar1;
  return;
}


// ===== FUN_00225408 @ 00225408 (111 bytes)

void FUN_00225408(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  
  iVar2 = ae_l16ui_n(param_1,0);
  if (iVar2 == 2) {
    iVar2 = ae_l16ui_n(param_1,2);
    if (iVar2 != 0) {
      iVar2 = ae_zext16(iVar2 + -1);
      *(short *)(param_1 + 2) = (short)iVar2;
      uVar4 = ae_l32_i(*(undefined4 *)(&DAT_002375d0 + iVar2 * 4));
      uVar1 = ae_s32_l_i(uVar4);
      *(undefined4 *)(param_1 + 4) = uVar1;
      return;
    }
    *(undefined2 *)(param_1 + 2) = 0;
    uVar4 = const_s(0);
    uVar1 = ae_s32_l_i(uVar4);
    *(undefined4 *)(param_1 + 4) = uVar1;
    ae_s16i_n(1,param_1,0);
    return;
  }
  if (iVar2 == 3) {
    uVar3 = ae_l16ui_n(param_1,2);
    uVar4 = const_s(1);
    if (uVar3 < 0x48) {
      iVar2 = ae_zext16(uVar3 + 1);
      *(short *)(param_1 + 2) = (short)iVar2;
      uVar4 = ae_l32_i(*(undefined4 *)(&DAT_002375d0 + iVar2 * 4));
      uVar1 = ae_s32_l_i(uVar4);
      *(undefined4 *)(param_1 + 4) = uVar1;
      return;
    }
    ae_s16i_n(0,param_1,0);
    ae_s16i_n(0x48,param_1,2);
    uVar1 = ae_s32_l_i(uVar4);
    *(undefined4 *)(param_1 + 4) = uVar1;
    return;
  }
  return;
}


// ===== FUN_00225478 @ 00225478 (17 bytes)

void FUN_00225478(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ae_l16ui_n(param_1,0);
  if (iVar1 != 0) {
    ae_s16i_n(3,param_1,0);
    return;
  }
  return;
}


// ===== FUN_0022548c @ 0022548c (17 bytes)

void FUN_0022548c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ae_l16ui_n(param_1,0);
  if (iVar1 != 1) {
    ae_s16i_n(2,param_1,0);
    return;
  }
  return;
}


// ===== FUN_002254a0 @ 002254a0 (76 bytes)

void FUN_002254a0(void)

{
  undefined8 uVar1;
  
  FUN_002254ec();
  FUN_00225550();
  DAT_00266ec0 = iir_cascade_init(&DAT_002c6a30,3,&DAT_00237700,1);
  DAT_00266ec4 = iir_cascade_init(&DAT_002c6ab0,3,&DAT_00237700,1);
  DAT_00266ec8 = 0;
  DAT_00266ed0 = 0;
  uVar1 = const_s(1);
  DAT_00266ecc = ae_s32_l_i(uVar1);
  DAT_00266ed4 = ae_s32_l_i(uVar1);
  return;
}


// ===== FUN_002254ec @ 002254ec (98 bytes)

void FUN_002254ec(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar7;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar8;
  
  uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar8 = uVar6 & 0xf;
  if (uVar8 < 2) {
    uVar6 = uVar6 & 0xfffffff0 | 2;
    uVar1 = wsr_ps(uVar6);
    uVar2 = wsr_ps_1(uVar6);
    uVar3 = wsr_ps_2(uVar6);
    uVar4 = wsr_ps_3(uVar6);
    uVar5 = wsr_ps_4(uVar6);
    uVar7 = wsr_ps_5(uVar6);
    rsync();
    DAT_00268e1a = 0;
    DAT_00268e1c = 0;
    DAT_00268e18 = 0;
    uVar6 = rsr_ps(uVar1,uVar2,uVar3,uVar4,uVar5,uVar7);
    uVar8 = uVar8 | uVar6 & 0xfffffff0;
    wsr_ps(uVar8);
    wsr_ps_1(uVar8);
    wsr_ps_2(uVar8);
    wsr_ps_3(uVar8);
    wsr_ps_4(uVar8);
    wsr_ps_5(uVar8);
    rsync();
    DAT_00268e1e = 0;
    return;
  }
  DAT_00268e1a = 0;
  DAT_00268e1c = 0;
  DAT_00268e18 = 0;
  uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar8 = uVar8 | uVar6 & 0xfffffff0;
  wsr_ps(uVar8);
  wsr_ps_1(uVar8);
  wsr_ps_2(uVar8);
  wsr_ps_3(uVar8);
  wsr_ps_4(uVar8);
  wsr_ps_5(uVar8);
  rsync();
  DAT_00268e1e = 0;
  return;
}


// ===== FUN_00225550 @ 00225550 (98 bytes)

void FUN_00225550(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar7;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar8;
  
  uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar8 = uVar6 & 0xf;
  if (uVar8 < 2) {
    uVar6 = uVar6 & 0xfffffff0 | 2;
    uVar1 = wsr_ps(uVar6);
    uVar2 = wsr_ps_1(uVar6);
    uVar3 = wsr_ps_2(uVar6);
    uVar4 = wsr_ps_3(uVar6);
    uVar5 = wsr_ps_4(uVar6);
    uVar7 = wsr_ps_5(uVar6);
    rsync();
    DAT_002c6a22 = 0;
    DAT_002c6a24 = 0;
    DAT_002c6a20 = 0;
    uVar6 = rsr_ps(uVar1,uVar2,uVar3,uVar4,uVar5,uVar7);
    uVar8 = uVar8 | uVar6 & 0xfffffff0;
    wsr_ps(uVar8);
    wsr_ps_1(uVar8);
    wsr_ps_2(uVar8);
    wsr_ps_3(uVar8);
    wsr_ps_4(uVar8);
    wsr_ps_5(uVar8);
    rsync();
    DAT_002c6a28 = 0;
    return;
  }
  DAT_002c6a22 = 0;
  DAT_002c6a24 = 0;
  DAT_002c6a20 = 0;
  uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar8 = uVar8 | uVar6 & 0xfffffff0;
  wsr_ps(uVar8);
  wsr_ps_1(uVar8);
  wsr_ps_2(uVar8);
  wsr_ps_3(uVar8);
  wsr_ps_4(uVar8);
  wsr_ps_5(uVar8);
  rsync();
  DAT_002c6a28 = 0;
  return;
}


// ===== FUN_002255b4 @ 002255b4 (465 bytes)

void FUN_002255b4(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  float fVar4;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  ae_l32_i(DAT_00266ecc);
  const_s(1);
  FUN_00234e00(&DAT_002c6b30,param_1,0x18);
  uVar6 = ae_l32_ip(DAT_002c6b30);
  uVar8 = const_s(2);
  uVar5 = (uint)DAT_00268e1e;
  fVar4 = (float)uVar8;
  iVar1 = uVar5 * 4;
  uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar6 * fVar4));
  (&DAT_002c6b90)[uVar5] = uVar2;
  uVar9 = const_s(0);
  uVar2 = ae_s32_l_i(uVar9);
  (&DAT_002c6b94)[uVar5] = uVar2;
  uVar8 = ae_l32_i(DAT_002c6b34);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6b9c + iVar1) = uVar2;
  uVar6 = ae_l32_i(DAT_002c6b38);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6ba4 + iVar1) = uVar2;
  uVar7 = ae_l32_i(DAT_002c6b3c);
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * fVar4));
  *(undefined4 *)(&DAT_002c6b98 + iVar1) = uVar2;
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar6 * fVar4));
  *(undefined4 *)(&DAT_002c6ba0 + iVar1) = uVar2;
  uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * fVar4));
  *(undefined4 *)(&DAT_002c6ba8 + iVar1) = uVar2;
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bac + iVar1) = uVar2;
  uVar8 = ae_l32_i(DAT_002c6b40);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bb4 + iVar1) = uVar2;
  uVar6 = ae_l32_i(DAT_002c6b44);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bbc + iVar1) = uVar2;
  uVar7 = ae_l32_i(DAT_002c6b48);
  uVar5 = ae_zext16(uVar5 + 0x30);
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * fVar4));
  *(undefined4 *)(&DAT_002c6bb0 + iVar1) = uVar2;
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar6 * fVar4));
  *(undefined4 *)(&DAT_002c6bb8 + iVar1) = uVar2;
  uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * fVar4));
  *(undefined4 *)(&DAT_002c6bc0 + iVar1) = uVar2;
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bc4 + iVar1) = uVar2;
  uVar6 = ae_l32_ip(DAT_002c6b4c);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bcc + iVar1) = uVar2;
  uVar8 = ae_l32_ip(DAT_002c6b50);
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar6 * fVar4));
  *(undefined4 *)(&DAT_002c6bc8 + iVar1) = uVar2;
  uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar8 * fVar4));
  *(undefined4 *)(&DAT_002c6bd0 + iVar1) = uVar2;
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bd4 + iVar1) = uVar2;
  uVar6 = ae_l32_i(DAT_002c6b54);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bdc + iVar1) = uVar2;
  uVar8 = ae_l32_i(DAT_002c6b58);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6be4 + iVar1) = uVar2;
  uVar7 = ae_l32_i(DAT_002c6b5c);
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar6 * fVar4));
  *(undefined4 *)(&DAT_002c6bd8 + iVar1) = uVar2;
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * fVar4));
  *(undefined4 *)(&DAT_002c6be0 + iVar1) = uVar2;
  uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * fVar4));
  *(undefined4 *)(&DAT_002c6be8 + iVar1) = uVar2;
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bec + iVar1) = uVar2;
  uVar6 = ae_l32_i(DAT_002c6b60);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bf4 + iVar1) = uVar2;
  uVar8 = ae_l32_i(DAT_002c6b64);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6bfc + iVar1) = uVar2;
  uVar7 = ae_l32_i(DAT_002c6b68);
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar6 * fVar4));
  *(undefined4 *)(&DAT_002c6bf0 + iVar1) = uVar2;
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar8 * fVar4));
  *(undefined4 *)(&DAT_002c6bf8 + iVar1) = uVar2;
  uVar2 = ae_s32_l_ip((ulonglong)(uint)((float)uVar7 * fVar4));
  *(undefined4 *)(&DAT_002c6c00 + iVar1) = uVar2;
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6c04 + iVar1) = uVar2;
  uVar6 = ae_l32_ip(DAT_002c6b6c);
  uVar2 = ae_s32_l_i(uVar9);
  *(undefined4 *)(&DAT_002c6c0c + iVar1) = uVar2;
  uVar2 = ae_s32_l_i((ulonglong)(uint)((float)uVar6 * fVar4));
  *(undefined4 *)(&DAT_002c6c08 + iVar1) = uVar2;
  if (uVar5 < 0x90) {
    DAT_00268e1e = (short)uVar5;
    return;
  }
  DAT_00268e1e = 0;
  iir_cascade_process(DAT_00266ec0,&DAT_002c6dd0,&DAT_002c6b90,0x90);
  uVar6 = ae_l32_i(DAT_002c6dd0);
  DAT_002c6b90 = ae_s32_l_ip(uVar6);
  uVar6 = ae_l32_i(DAT_002c6df4);
  DAT_002c6b94 = ae_s32_l_i(uVar6);
  if (0xf90 < DAT_00268e18) {
    return;
  }
  FUN_00234750(&DAT_002c7010,&DAT_002c6b90,0xfffffff1,0x10);
  uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar5 & 0xf) < 2) {
    uVar3 = uVar5 & 0xfffffff0 | 2;
    in_st_PSWOE = wsr_ps(uVar3);
    in_st_PSCALLINC = wsr_ps_1(uVar3);
    in_st_PSOWB = wsr_ps_2(uVar3);
    in_st_PSUM = wsr_ps_3(uVar3);
    in_st_PSEXCM = wsr_ps_4(uVar3);
    in_st_PSINTLEVEL = wsr_ps_5(uVar3);
    rsync();
  }
  ae_s16i_n((int)DAT_002c7010,&DAT_00266ed8 + (uint)DAT_00268e1a * 2,0);
  if (DAT_00268e1a < 3999) {
    iVar1 = DAT_00268e1a + 1;
  }
  else {
    iVar1 = 0;
  }
  DAT_00268e18 = DAT_00268e18 + 1;
  uVar2 = ae_zext16(iVar1);
  DAT_00268e1a = (short)uVar2;
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar5 = uVar5 & 0xf | uVar3 & 0xfffffff0;
  wsr_ps(uVar5);
  wsr_ps_1(uVar5);
  wsr_ps_2(uVar5);
  wsr_ps_3(uVar5);
  wsr_ps_4(uVar5);
  wsr_ps_5(uVar5);
  rsync();
  return;
}


// ===== FUN_00225790 @ 00225790 (162 bytes)

void FUN_00225790(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar4;
  int iVar5;
  
  memset(param_1,0xf0,4000);
  uVar2 = (uint)DAT_00268e18;
  if (0x7ce < uVar2) {
    uVar2 = 0x7ce;
  }
  ae_s16i_n(uVar2,param_1,0);
  *(short *)(param_1 + 2) = (short)((int)(4000 - (uint)DAT_002c6a20) / 6);
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar4 = uVar3 & 0xfffffff0 | 2;
  if ((uVar3 & 0xf) < 2) {
    in_st_PSWOE = wsr_ps(uVar4);
    in_st_PSCALLINC = wsr_ps_1(uVar4);
    in_st_PSOWB = wsr_ps_2(uVar4);
    in_st_PSUM = wsr_ps_3(uVar4);
    in_st_PSEXCM = wsr_ps_4(uVar4);
    in_st_PSINTLEVEL = wsr_ps_5(uVar4);
    rsync();
  }
  uVar4 = (uint)DAT_00268e1c;
  if ((uVar2 != 0) && ((uVar2 == 1 || (uVar2 != 0)))) {
    uVar1 = ae_l16si_n(&DAT_00266ed8 + uVar4 * 2,0);
    *(short *)(param_1 + 4) = (short)uVar1;
    DAT_00268e18 = DAT_00268e18 - 1;
    iVar5 = uVar4 + 1;
    if (0xf9e < uVar4) {
      iVar5 = 0;
    }
    uVar1 = ae_zext16(iVar5);
    DAT_00268e1c = (ushort)uVar1;
  }
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar2 = uVar3 & 0xf | uVar2 & 0xfffffff0;
  wsr_ps(uVar2);
  wsr_ps_1(uVar2);
  wsr_ps_2(uVar2);
  wsr_ps_3(uVar2);
  wsr_ps_4(uVar2);
  wsr_ps_5(uVar2);
  rsync();
  return;
}


// ===== FUN_00225834 @ 00225834 (426 bytes)

void FUN_00225834(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  ushort uVar5;
  uint uVar6;
  undefined8 uVar7;
  float fVar8;
  undefined8 uVar9;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  short *psVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  int local_30;
  
  uVar2 = ae_l16si_n(param_1,0);
  uVar2 = uVar2 & 0xfff;
  iVar3 = ae_zext16((uVar2 < 0x7ce) * uVar2 + (uint)(uVar2 >= 0x7ce) * 0x7ce);
  psVar10 = (short *)(param_1 + 4);
  if (iVar3 != 0) {
    iVar1 = 0;
    do {
      (&DAT_002c7050)[DAT_002c6a28] = (int)*psVar10;
      uVar2 = ae_zext16(DAT_002c6a28 + 1);
      psVar10 = psVar10 + 1;
      if (uVar2 < 0x10) {
        DAT_002c6a28 = (ushort)uVar2;
      }
      else {
        DAT_002c6a28 = 0;
        FUN_00234890(&DAT_002c7090,&DAT_002c7050,0xfffffff1,0x10);
        memset(&DAT_002c72d0,0,0x240);
        uVar9 = ae_l32_i(0x41100000);
        uVar7 = ae_l32_ip(DAT_002c7090);
        fVar8 = (float)uVar9;
        uVar9 = ae_l32_i(DAT_002c709c);
        uVar11 = ae_l32_i(DAT_002c7094);
        DAT_002c72d0 = ae_s32_l_i((ulonglong)(uint)((float)uVar7 * fVar8));
        uVar12 = ae_l32_i(DAT_002c7098);
        uVar7 = ae_l32_ip(DAT_002c70a0);
        uVar13 = ae_l32_i(DAT_002c70a4);
        DAT_002c72f4 = ae_s32_l_i((ulonglong)(uint)((float)uVar11 * fVar8));
        uVar11 = ae_l32_i(DAT_002c70a8);
        uVar14 = ae_l32_i(DAT_002c70ac);
        DAT_002c7318 = ae_s32_l_i((ulonglong)(uint)((float)uVar12 * fVar8));
        DAT_002c733c = ae_s32_l_i((ulonglong)(uint)((float)uVar9 * fVar8));
        DAT_002c7360 = ae_s32_l_i((ulonglong)(uint)((float)uVar7 * fVar8));
        DAT_002c7384 = ae_s32_l_i((ulonglong)(uint)((float)uVar13 * fVar8));
        DAT_002c73a8 = ae_s32_l_i((ulonglong)(uint)((float)uVar11 * fVar8));
        DAT_002c73cc = ae_s32_l_i((ulonglong)(uint)((float)uVar14 * fVar8));
        iir_cascade_process(DAT_00266ec4,&DAT_002c7090,&DAT_002c72d0,0x90);
        puVar4 = &DAT_002c72d0;
        uVar7 = ae_l32_ip(DAT_002c7090);
        DAT_002c72d0 = ae_s32_l_ip(uVar7);
        uVar7 = ae_l32_ip(DAT_002c7098);
        DAT_002c72d4 = ae_s32_l_ip(uVar7);
        local_30 = 0;
        do {
          if (3999 < DAT_002c6a20) {
            return;
          }
          uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,
                         in_st_PSINTLEVEL);
          if ((uVar2 & 0xf) < 2) {
            uVar6 = uVar2 & 0xfffffff0 | 2;
            in_st_PSWOE = wsr_ps(uVar6);
            in_st_PSCALLINC = wsr_ps_1(uVar6);
            in_st_PSOWB = wsr_ps_2(uVar6);
            in_st_PSUM = wsr_ps_3(uVar6);
            in_st_PSEXCM = wsr_ps_4(uVar6);
            in_st_PSINTLEVEL = wsr_ps_5(uVar6);
            rsync();
          }
          memcpy(&DAT_00268e20 + (uint)DAT_002c6a22 * 0x60,puVar4,0x60);
          uVar5 = 0;
          DAT_002c6a20 = DAT_002c6a20 + 1;
          if (DAT_002c6a22 < 3999) {
            uVar5 = DAT_002c6a22 + 1;
          }
          uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,
                         in_st_PSINTLEVEL);
          uVar2 = uVar2 & 0xf | uVar6 & 0xfffffff0;
          in_st_PSWOE = wsr_ps(uVar2);
          in_st_PSCALLINC = wsr_ps_1(uVar2);
          in_st_PSOWB = wsr_ps_2(uVar2);
          in_st_PSUM = wsr_ps_3(uVar2);
          in_st_PSEXCM = wsr_ps_4(uVar2);
          in_st_PSINTLEVEL = wsr_ps_5(uVar2);
          rsync();
          local_30 = local_30 + 1;
          puVar4 = puVar4 + 0x18;
          DAT_002c6a22 = uVar5;
        } while (local_30 != 3);
      }
      iVar1 = iVar1 + 1;
    } while (iVar3 != iVar1);
  }
  return;
}


// ===== FUN_002259e4 @ 002259e4 (159 bytes)

void FUN_002259e4(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  bool bVar3;
  
  if (DAT_002c6a20 == 0) {
    memset(&DAT_002c7510,0,0x60);
  }
  else {
    uVar1 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    if ((uVar1 & 0xf) < 2) {
      uVar2 = uVar1 & 0xfffffff0 | 2;
      in_st_PSWOE = wsr_ps(uVar2);
      in_st_PSCALLINC = wsr_ps_1(uVar2);
      in_st_PSOWB = wsr_ps_2(uVar2);
      in_st_PSUM = wsr_ps_3(uVar2);
      in_st_PSEXCM = wsr_ps_4(uVar2);
      in_st_PSINTLEVEL = wsr_ps_5(uVar2);
      rsync();
    }
    memcpy(&DAT_002c7510,&DAT_00268e20 + (uint)DAT_002c6a24 * 0x60,0x60);
    DAT_002c6a20 = DAT_002c6a20 + -1;
    bVar3 = 0xf9e < DAT_002c6a24;
    DAT_002c6a24 = DAT_002c6a24 + 1;
    if (bVar3) {
      DAT_002c6a24 = 0;
    }
    uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = uVar1 & 0xf | uVar2 & 0xfffffff0;
    wsr_ps(uVar1);
    wsr_ps_1(uVar1);
    wsr_ps_2(uVar1);
    wsr_ps_3(uVar1);
    wsr_ps_4(uVar1);
    wsr_ps_5(uVar1);
    rsync();
  }
  ae_l32_i(DAT_00266ed4);
  const_s(1);
  FUN_00234e00(param_1,&DAT_002c7510,0x18);
  return;
}


// ===== FUN_00225a84 @ 00225a84 (46 bytes)

void FUN_00225a84(void)

{
  float in_aed0;
  ulonglong uVar1;
  
  if ((int)DAT_00266ec8 == (int)DAT_20070024) {
    return;
  }
  DAT_00266ec8 = DAT_20070024;
  FUN_00234730((int)DAT_20070024,0xffffffff);
  uVar1 = (ulonglong)(uint)(in_aed0 * 0.05);
  FUN_00218b70();
  DAT_00266ecc = ae_s32_l_i(uVar1);
  return;
}


// ===== FUN_00225ab4 @ 00225ab4 (46 bytes)

void FUN_00225ab4(void)

{
  float in_aed0;
  ulonglong uVar1;
  
  if ((int)DAT_00266ed0 == (int)DAT_20070026) {
    return;
  }
  DAT_00266ed0 = DAT_20070026;
  FUN_00234730((int)DAT_20070026,0xffffffff);
  uVar1 = (ulonglong)(uint)(in_aed0 * 0.05);
  FUN_00218b70();
  DAT_00266ed4 = ae_s32_l_i(uVar1);
  return;
}


// ===== FUN_00225af0 @ 00225af0 (62 bytes)

void FUN_00225af0(void)

{
  undefined8 uVar1;
  
  memset(&DAT_002c7710,0,0xc0);
  memset(&DAT_002c77d0,0,0x60);
  FUN_00225b30();
  FUN_00225b8c();
  ae_s16i_n(0,&DAT_002c7570,0);
  DAT_002c7578 = 0;
  uVar1 = const_s(1);
  DAT_002c7574 = ae_s32_l_i(uVar1);
  FUN_002253f0(&DAT_002c757c);
  return;
}


// ===== FUN_00225b30 @ 00225b30 (92 bytes)

uint FUN_00225b30(uint param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar7;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar8;
  
  uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar8 = uVar6 & 0xf;
  if (uVar8 < 2) {
    uVar6 = uVar6 & 0xfffffff0 | 2;
    uVar1 = wsr_ps(uVar6);
    uVar2 = wsr_ps_1(uVar6);
    uVar3 = wsr_ps_2(uVar6);
    uVar4 = wsr_ps_3(uVar6);
    uVar5 = wsr_ps_4(uVar6);
    uVar7 = wsr_ps_5(uVar6);
    rsync();
    DAT_002c7645 = 0;
    DAT_002c7646 = 0;
    DAT_002c7644 = 0;
    uVar6 = rsr_ps(uVar1,uVar2,uVar3,uVar4,uVar5,uVar7);
    uVar8 = uVar8 | uVar6 & 0xfffffff0;
    wsr_ps(uVar8);
    wsr_ps_1(uVar8);
    wsr_ps_2(uVar8);
    wsr_ps_3(uVar8);
    wsr_ps_4(uVar8);
    wsr_ps_5(uVar8);
    rsync();
    return uVar8;
  }
  DAT_002c7645 = 0;
  DAT_002c7646 = 0;
  DAT_002c7644 = 0;
  uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar8 = uVar8 | uVar6 & 0xfffffff0;
  wsr_ps(uVar8);
  wsr_ps_1(uVar8);
  wsr_ps_2(uVar8);
  wsr_ps_3(uVar8);
  wsr_ps_4(uVar8);
  wsr_ps_5(uVar8);
  rsync();
  return param_1;
}


// ===== FUN_00225b8c @ 00225b8c (92 bytes)

uint FUN_00225b8c(uint param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar7;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar8;
  
  uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar8 = uVar6 & 0xf;
  if (uVar8 < 2) {
    uVar6 = uVar6 & 0xfffffff0 | 2;
    uVar1 = wsr_ps(uVar6);
    uVar2 = wsr_ps_1(uVar6);
    uVar3 = wsr_ps_2(uVar6);
    uVar4 = wsr_ps_3(uVar6);
    uVar5 = wsr_ps_4(uVar6);
    uVar7 = wsr_ps_5(uVar6);
    rsync();
    DAT_002c7709 = 0;
    DAT_002c770a = 0;
    DAT_002c7708 = 0;
    uVar6 = rsr_ps(uVar1,uVar2,uVar3,uVar4,uVar5,uVar7);
    uVar8 = uVar8 | uVar6 & 0xfffffff0;
    wsr_ps(uVar8);
    wsr_ps_1(uVar8);
    wsr_ps_2(uVar8);
    wsr_ps_3(uVar8);
    wsr_ps_4(uVar8);
    wsr_ps_5(uVar8);
    rsync();
    return uVar8;
  }
  DAT_002c7709 = 0;
  DAT_002c770a = 0;
  DAT_002c7708 = 0;
  uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar8 = uVar8 | uVar6 & 0xfffffff0;
  wsr_ps(uVar8);
  wsr_ps_1(uVar8);
  wsr_ps_2(uVar8);
  wsr_ps_3(uVar8);
  wsr_ps_4(uVar8);
  wsr_ps_5(uVar8);
  rsync();
  return param_1;
}


// ===== FUN_00225be8 @ 00225be8 (178 bytes)

void FUN_00225be8(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined8 uVar5;
  undefined8 uVar6;
  
  if (DAT_002c7644 < 2) {
    uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    if ((uVar3 & 0xf) < 2) {
      uVar4 = uVar3 & 0xfffffff0 | 2;
      in_st_PSWOE = wsr_ps(uVar4);
      in_st_PSCALLINC = wsr_ps_1(uVar4);
      in_st_PSOWB = wsr_ps_2(uVar4);
      in_st_PSUM = wsr_ps_3(uVar4);
      in_st_PSEXCM = wsr_ps_4(uVar4);
      in_st_PSINTLEVEL = wsr_ps_5(uVar4);
      rsync();
    }
    ae_l32_i(DAT_002c7574);
    const_s(1);
    FUN_00234e00(&DAT_002c7830,param_1,0x18);
    puVar2 = &DAT_002c7830;
    do {
      uVar5 = ae_l32_i(DAT_002c7580);
      uVar6 = ae_l32_i(*puVar2);
      uVar1 = ae_s32_l_i((ulonglong)(uint)((float)uVar6 * (float)uVar5));
      *puVar2 = uVar1;
      FUN_00225408(&DAT_002c757c);
      puVar2 = puVar2 + 1;
    } while (puVar2 != (undefined4 *)&DAT_002c7890);
    FUN_00234750(&DAT_002c7584 + (uint)DAT_002c7645 * 0x60,&DAT_002c7830,0xffffffe1,0x18);
    DAT_002c7644 = DAT_002c7644 + 1;
    DAT_002c7645 = DAT_002c7645 + 1 & 1;
    uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar3 = uVar3 & 0xf | uVar4 & 0xfffffff0;
    wsr_ps(uVar3);
    wsr_ps_1(uVar3);
    wsr_ps_2(uVar3);
    wsr_ps_3(uVar3);
    wsr_ps_4(uVar3);
    wsr_ps_5(uVar3);
    rsync();
    return;
  }
  return;
}


// ===== txaf_fifo_pop_to_dma @ 00225c9c (90 bytes)

void txaf_fifo_pop_to_dma(undefined4 param_1)

{
  if (DAT_002c7644 == '\0') {
    memset(&DAT_002c7710,0,0x60);
  }
  else {
    memcpy(&DAT_002c7710,&DAT_002c7584 + (uint)DAT_002c7646 * 0x60,0x60);
    DAT_002c7644 = DAT_002c7644 + -1;
    DAT_002c7646 = DAT_002c7646 + 1 & 1;
  }
  FUN_0021c598(param_1,&DAT_002c7710,&DAT_002c77d0,0x18);
  return;
}


// ===== rxif_dma_to_fifo @ 00225cf8 (78 bytes)

void rxif_dma_to_fifo(undefined4 param_1)

{
  FUN_0021c560(&DAT_002c7710,0x2c7770,param_1,0x18);
  if (1 < DAT_002c7708) {
    return;
  }
  memcpy(&DAT_002c7648 + (uint)DAT_002c7709 * 0x60,&DAT_002c7710,0x60);
  DAT_002c7708 = DAT_002c7708 + 1;
  DAT_002c7709 = DAT_002c7709 + 1 & 1;
  return;
}


// ===== FUN_00225d48 @ 00225d48 (123 bytes)

void FUN_00225d48(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  if (DAT_002c7708 != '\0') {
    uVar1 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    if ((uVar1 & 0xf) < 2) {
      uVar2 = uVar1 & 0xfffffff0 | 2;
      in_st_PSWOE = wsr_ps(uVar2);
      in_st_PSCALLINC = wsr_ps_1(uVar2);
      in_st_PSOWB = wsr_ps_2(uVar2);
      in_st_PSUM = wsr_ps_3(uVar2);
      in_st_PSEXCM = wsr_ps_4(uVar2);
      in_st_PSINTLEVEL = wsr_ps_5(uVar2);
      rsync();
    }
    FUN_00234890(param_1,&DAT_002c7648 + (uint)DAT_002c770a * 0x60,0xffffffe1,0x18);
    DAT_002c7708 = DAT_002c7708 + -1;
    DAT_002c770a = DAT_002c770a + 1 & 1;
    uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = uVar1 & 0xf | uVar2 & 0xfffffff0;
    wsr_ps(uVar1);
    wsr_ps_1(uVar1);
    wsr_ps_2(uVar1);
    wsr_ps_3(uVar1);
    wsr_ps_4(uVar1);
    wsr_ps_5(uVar1);
    rsync();
    return;
  }
  memset(param_1,0,0x60);
  return;
}


// ===== FUN_00225dc4 @ 00225dc4 (112 bytes)

void FUN_00225dc4(void)

{
  ushort uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  float in_aed0;
  ulonglong uVar5;
  
  if ((int)DAT_002c7570 != (int)DAT_2007001e) {
    DAT_002c7570 = DAT_2007001e;
    FUN_00234730((int)DAT_2007001e,0xffffffff);
    uVar5 = (ulonglong)(uint)(in_aed0 * 0.05);
    FUN_00218b70();
    DAT_002c7574 = ae_s32_l_i(uVar5);
  }
  uVar1 = DAT_20070020 >> 1;
  uVar3 = regfile_gpio_sel();
  uVar2 = FUN_00223a74();
  uVar3 = uVar1 & 1 | uVar3;
  uVar4 = ae_zext16(uVar3);
  if (DAT_002c7578 != uVar4) {
    DAT_002c7578 = (ushort)uVar3;
    if (uVar4 != 0) {
      FUN_0022548c();
      memw();
      DAT_40100044 = uVar2;
      return;
    }
    FUN_00225478(&DAT_002c757c);
  }
  memw();
  DAT_40100044 = uVar2;
  return;
}


// ===== create_rx_tx_path_threads @ 00225e40 (661 bytes)

void create_rx_tx_path_threads(void)

{
  uint uVar1;
  undefined8 uVar2;
  
  INPUTMUX_AttachSignal(&DAT_40026000,0x12,0x14000014);
  CLOCK_AttachClk(0x80002548);
  CLOCK_AttachClk(0x80002568);
  CLOCK_AttachClk(0x80002588);
  CLOCK_AttachClk(0x800025a8);
  FUN_00213910(0x30a);
  FUN_00213910(0x30b);
  FUN_00213910(0x30c);
  FUN_00213910(0x30d);
  CLOCK_AttachClk(0x80001740);
  FUN_00208654(0x80000744,1);
  memw();
  DAT_40022010 = 1;
  memw();
  DAT_40022080 = 0x22;
  memw();
  DAT_4002204c = 0x101;
  memw();
  DAT_40022084 = 0x55;
  memw();
  DAT_40022050 = 0x202;
  xos_register_interrupt_handler(0x17,DMA_IRQHandle,&DAT_40105000);
  xos_interrupt_enable(0x17);
  I2S_TxGetDefaultConfig(&DAT_002c8208);
  DAT_002c8216 = 1;
  DAT_002c8208 = 0;
  DAT_002c8219 = 0x20;
  DAT_002c821a = 0x40;
  I2S_TxGetDefaultConfig();
  DAT_002c8224 = 0;
  ae_s16i_n(1,0x2c8230,2);
  DAT_002c8235 = 0x20;
  DAT_002c8236 = 0x40;
  I2S_RxGetDefaultConfig();
  DAT_002c8240 = 0;
  DAT_002c824e = 1;
  DAT_002c8251 = 0x20;
  DAT_002c8252 = 0x40;
  I2S_RxGetDefaultConfig(&DAT_002c825c);
  DAT_002c826a = 1;
  DAT_002c825c = 0;
  DAT_002c826d = 0x20;
  DAT_002c826e = 0x40;
  I2S_TxInit(&DAT_40108000,&DAT_002c8208);
  I2S_RxInit(&DAT_40109000,&DAT_002c8240);
  I2S_TxInit(&DAT_40123000,&DAT_002c8224);
  I2S_RxInit(&DAT_40122000,&DAT_002c825c);
  DMA_Init(&DAT_40105000);
  memw();
  uVar1 = DAT_40105020;
  memw();
  DAT_40105020 = uVar1 | 0x20;
  memw();
  uVar1 = DAT_40105020;
  memw();
  DAT_40105020 = uVar1 | 0x40;
  memw();
  uVar1 = DAT_40105450;
  memw();
  DAT_40105450 = uVar1 & 0xfff8ffff | (uint)&DAT_00050000;
  memw();
  uVar1 = DAT_40105460;
  memw();
  DAT_40105460 = uVar1 & 0xfff8ffff | (uint)&DAT_00030000;
  DMA_CreateHandle(&DAT_002c8278,&DAT_40105000,5);
  DMA_CreateHandle(&DAT_002c8288,&DAT_40105000,6);
  memw();
  uVar1 = DAT_40105020;
  memw();
  DAT_40105020 = uVar1 | 0x800;
  memw();
  uVar1 = DAT_40105020;
  memw();
  DAT_40105020 = uVar1 | 0x100;
  memw();
  uVar1 = DAT_401054b0;
  memw();
  DAT_401054b0 = uVar1 & 0xfff8ffff | (uint)&DAT_00040000;
  memw();
  uVar1 = DAT_40105480;
  memw();
  DAT_40105480 = uVar1 & 0xfff8ffff | (uint)&DAT_00020000;
  DMA_CreateHandle(&DAT_002c8298,&DAT_40105000,0xb);
  DMA_CreateHandle(&DAT_002c82a8,&DAT_40105000,8);
  FUN_00225af0();
  FUN_002244e0();
  xos_thread_create(&DAT_002c7890,0,Thread_Rx_Path_entry,0,"Thread_Rx_Path",&DAT_002c83b0,
                    &DAT_00001398,7,0,0);
  xos_msgq_create(PTR_DAT_0023773c,2,4,0);
  xos_thread_create(&DAT_002c7d48,0,Thread_Tx_Path_entry,0,"Thread_Tx_Path",&DAT_002c9750,
                    &DAT_00001398,7,0,0);
  xos_msgq_create(PTR_DAT_00237740,2,4,0);
  memset(&DAT_002caaf0,0,0x60);
  FUN_002249b0();
  DAT_002c8200 = 0;
  uVar2 = const_s(1);
  DAT_002c8204 = ae_s32_l_i(uVar2);
  FUN_00223320();
  FUN_0022338c();
  FUN_002248a0();
  FUN_00223110();
  create_Thread_Rx_Audio();
  FUN_00225250();
  return;
}


// ===== audio_i2s_fc3_fc4_fc5_init @ 002260d8 (331 bytes)

void audio_i2s_fc3_fc4_fc5_init(void)

{
  DAT_002cab58 = &DAT_20062ca0;
  DAT_002cab54 = 0xc0;
  DAT_002cab5c = 0xc0;
  DAT_002cab64 = 0xc0;
  DAT_002cab6c = 0xc0;
  DAT_002cab60 = &DAT_20062d60;
  DAT_002cab68 = &DAT_20062e20;
  DAT_002c82b8 = 0;
  DAT_002c82bc = 0;
  DAT_002cab50 = &DAT_20062be0;
  I2S_TxTransferCreateHandleDMA
            (&DAT_40108000,&DAT_002c82c0,&DAT_002c8278,fc2_txaf_dma_done,&DAT_002c82bc);
  I2S_RxTransferCreateHandleDMA
            (&DAT_40109000,&DAT_002c82f8,&DAT_002c8288,fc3_rxif_dma_done,&DAT_002c82b8);
  I2S_RxTransferReceiveDMA(&DAT_40109000,&DAT_002c82f8,DAT_002cab60,DAT_002cab64);
  I2S_RxTransferReceiveDMA(&DAT_40109000,&DAT_002c82f8,DAT_002cab68,DAT_002cab6c);
  I2S_TxTransferSendDMA(&DAT_40108000,&DAT_002c82c0,DAT_002cab50,DAT_002cab54);
  I2S_TxTransferSendDMA(&DAT_40108000,&DAT_002c82c0,DAT_002cab58,DAT_002cab5c);
  DAT_002cab74 = 0xc0;
  DAT_002cab7c = 0xc0;
  DAT_002cab84 = 0xc0;
  DAT_002cab8c = 0xc0;
  DAT_002cab80 = &DAT_20063060;
  DAT_002cab88 = &DAT_20063120;
  DAT_002cab70 = &DAT_20062ee0;
  DAT_002cab78 = &DAT_20062fa0;
  DAT_002c8330 = 0;
  DAT_002c8334 = 0;
  I2S_TxTransferCreateHandleDMA
            (&DAT_40123000,&DAT_002c8338,&DAT_002c8298,fc5_codec_out_dma_done,&DAT_002c8334);
  I2S_RxTransferCreateHandleDMA
            (&DAT_40122000,&DAT_002c8370,&DAT_002c82a8,fc4_codec_in_dma_done,&DAT_002c8330);
  I2S_RxTransferReceiveDMA(&DAT_40122000,&DAT_002c8370,DAT_002cab80,DAT_002cab84);
  I2S_RxTransferReceiveDMA(&DAT_40122000,&DAT_002c8370,DAT_002cab88,DAT_002cab8c);
  I2S_TxTransferSendDMA(&DAT_40123000,&DAT_002c8338,DAT_002cab70,DAT_002cab74);
  I2S_TxTransferSendDMA(&DAT_40123000,&DAT_002c8338,DAT_002cab78,DAT_002cab7c);
  return;
}


// ===== fc2_txaf_dma_done @ 00226224 (47 bytes)

void fc2_txaf_dma_done(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  I2S_TxTransferSendDMA(param_1,param_2,(&DAT_002cab50)[*param_4 * 2],(&DAT_002cab54)[*param_4 * 2])
  ;
  txaf_fifo_pop_to_dma((&DAT_002cab50)[*param_4 * 2]);
  *param_4 = *param_4 ^ 1;
  return;
}


// ===== fc3_rxif_dma_done @ 00226254 (47 bytes)

void fc3_rxif_dma_done(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  I2S_RxTransferReceiveDMA
            (param_1,param_2,(&DAT_002cab60)[*param_4 * 2],(&DAT_002cab64)[*param_4 * 2]);
  rxif_dma_to_fifo((&DAT_002cab60)[*param_4 * 2]);
  *param_4 = *param_4 ^ 1;
  return;
}


// ===== fc5_codec_out_dma_done @ 00226284 (59 bytes)

void fc5_codec_out_dma_done(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  I2S_TxTransferSendDMA(param_1,param_2,(&DAT_002cab70)[*param_4 * 2],(&DAT_002cab74)[*param_4 * 2])
  ;
  codec_out_fill_dma((&DAT_002cab70)[*param_4 * 2]);
  xos_msgq_put(PTR_DAT_0023773c,param_4);
  *param_4 = *param_4 ^ 1;
  return;
}


// ===== fc4_codec_in_dma_done @ 002262c0 (59 bytes)

void fc4_codec_in_dma_done(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  I2S_RxTransferReceiveDMA
            (param_1,param_2,(&DAT_002cab80)[*param_4 * 2],(&DAT_002cab84)[*param_4 * 2]);
  codec_in_from_dma((&DAT_002cab80)[*param_4 * 2]);
  xos_msgq_put(PTR_DAT_00237740,param_4);
  *param_4 = *param_4 ^ 1;
  return;
}


// ===== Thread_Rx_Path_entry @ 002262fc (353 bytes)

void Thread_Rx_Path_entry(void)

{
  int iVar1;
  undefined1 auStack_30 [48];
  
  do {
    do {
      iVar1 = xos_msgq_get(PTR_DAT_0023773c,auStack_30);
    } while (iVar1 != 0);
    FUN_00225d48(&DAT_002cab90);
    FUN_00220ee0(&DAT_002cab90,&DAT_002cab90);
    if ((DAT_2007000c == 10) && (iVar1 = ae_l16ui_n(&DAT_00263d5c,0), iVar1 == 1)) {
      FUN_00224798(1,&DAT_002cabf0);
      FUN_00224960(&DAT_002cabf0);
      rx_audio_push_block(&DAT_002cabf0,&DAT_002cac50,&DAT_002cacb0);
      memcpy(&DAT_002cad10,&DAT_002cab90,0x60);
    }
    else {
      rx_audio_push_block(&DAT_002cab90,&DAT_002cac50,&DAT_002cacb0);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d56,0);
    if (iVar1 == 3) {
      FUN_00224604(1,&DAT_002cac50);
    }
    else if (iVar1 == 4) {
      FUN_00224604(1,&DAT_002cad10);
    }
    else if (iVar1 == 6) {
      FUN_00224604(1,&DAT_002cacb0);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d54,0);
    if (iVar1 == 3) {
      FUN_00224604(0,&DAT_002cac50);
    }
    else if (iVar1 == 4) {
      FUN_00224604(0,&DAT_002cad10);
    }
    else if (iVar1 == 6) {
      FUN_00224604(0,&DAT_002cacb0);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d52,0);
    if (iVar1 == 3) {
      FUN_00223734(&DAT_002cac50,0);
    }
    else if (iVar1 == 6) {
      FUN_00223734(&DAT_002cacb0,0);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d50,0);
    if (iVar1 == 3) {
      spi_fifo_push(&DAT_002cac50);
    }
    else if (iVar1 == 6) {
      spi_fifo_push(&DAT_002cacb0);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d5a,0);
    if (iVar1 == 5) {
      FUN_002255b4(&DAT_002cac50);
    }
    else if (iVar1 == 6) {
      FUN_002255b4(&DAT_002cacb0);
    }
    FUN_00224814();
    FUN_00225ab4();
  } while( true );
}


// ===== Thread_Tx_Path_entry @ 0022647c (595 bytes)

void Thread_Tx_Path_entry(void)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  undefined8 in_aed0;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined1 auStack_30 [48];
  
  do {
    do {
      iVar1 = xos_msgq_get(PTR_DAT_00237740,auStack_30);
      fVar3 = (float)in_aed0;
    } while (iVar1 != 0);
    FUN_002249d0();
    FUN_00224798(0,&DAT_002cad70);
    uVar2 = 0;
    if ((DAT_2007000c == 10) && (iVar1 = ae_l16ui_n(&DAT_00263d5c,0), uVar2 = 0, iVar1 != 1)) {
      FUN_00224798(1,&DAT_002cadd0);
      uVar2 = 1;
    }
    FUN_002248d8(uVar2,&DAT_002cadd0);
    FUN_002259e4(&DAT_002cae30);
    iVar1 = ae_l16ui_n(&DAT_00263d5a,0);
    if (iVar1 == 2) {
      FUN_002255b4(&DAT_002cad70);
    }
    else if (iVar1 == 3) {
      FUN_002255b4(&DAT_002cae30);
    }
    else if (iVar1 == 4) {
      FUN_00225264(&DAT_002cae90,0x18);
      FUN_002255b4(&DAT_002cae90);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d5c,0);
    if (iVar1 == 2) {
      memcpy(&DAT_002cae90,&DAT_002cad70,0x60);
    }
    else if (iVar1 == 3) {
      memcpy(&DAT_002cae90,&DAT_002cae30,0x60);
    }
    else if (iVar1 == 4) {
      FUN_00225264(&DAT_002cae90,0x18);
    }
    else {
      memset(&DAT_002cae90,0,0x60);
    }
    FUN_002233fc(&DAT_002cae90,&DAT_002caef0);
    if ((int)(short)DAT_20070040 != (uint)DAT_002c8200) {
      DAT_002c8200 = DAT_20070040;
      FUN_00234730((int)(short)DAT_20070040,0xffffffff);
      uVar5 = ae_l32_i(0x3d4ccccd);
      uVar4 = (ulonglong)(uint)(fVar3 * (float)uVar5);
      FUN_00218b70();
      DAT_002c8204 = ae_s32_l_i(uVar4);
    }
    memcpy(&DAT_002cb010,&DAT_002cae90,0x60);
    in_aed0 = ae_l32_i(DAT_002c8204);
    FUN_00234f40(&DAT_002cae90,&DAT_002cb010,0x18);
    FUN_0022313c(&DAT_002cae90,&DAT_002caf50,&DAT_002cafb0);
    iVar1 = ae_l16ui_n(&DAT_00263d56,0);
    if (iVar1 == 1) {
      FUN_00224604(1,&DAT_002cafb0);
    }
    else if (iVar1 == 2) {
      FUN_00224604(1,&DAT_002caf50);
    }
    else if (iVar1 == 5) {
      FUN_00224604(1,&DAT_002cadd0);
    }
    else if (iVar1 == 7) {
      FUN_00224604(1,&DAT_002caef0);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d54,0);
    if (iVar1 == 1) {
      FUN_00224604(0,&DAT_002cafb0);
    }
    else if (iVar1 == 2) {
      FUN_00224604(0,&DAT_002caf50);
    }
    else if (iVar1 == 5) {
      FUN_00224604(0,&DAT_002cadd0);
    }
    else if (iVar1 == 7) {
      FUN_00224604(0,&DAT_002caef0);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d52,0);
    if (iVar1 == 1) {
      FUN_00223734(&DAT_002cafb0,0);
    }
    else if (iVar1 == 2) {
      FUN_00223734(&DAT_002caf50,0);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d50,0);
    if (iVar1 == 0) {
      spi_fifo_push(&DAT_002caaf0);
    }
    else if (iVar1 == 1) {
      spi_fifo_push(&DAT_002cafb0);
    }
    else if (iVar1 == 2) {
      spi_fifo_push(&DAT_002caf50);
    }
    iVar1 = ae_l16ui_n(&DAT_00263d58,0);
    if (iVar1 == 1) {
      FUN_00225be8(&DAT_002cadd0);
    }
    else if (iVar1 == 2) {
      FUN_00225be8(&DAT_002cafb0);
    }
    FUN_00225dc4();
    FUN_00225a84();
  } while( true );
}


// ===== xos_register_interrupt_handler @ 002266fc (29 bytes)

/* called with MU_B_IRQHandler [inference] */

undefined4 xos_register_interrupt_handler(uint param_1,undefined *param_2,undefined4 param_3)

{
  if (0x1f < param_1) {
    return 0xffff0001;
  }
  (&PTR_FUN_00237860)[param_1 * 4] = param_2;
  *(undefined4 *)(&DAT_00237864 + param_1 * 0x10) = param_3;
  return 0;
}


// ===== FUN_0022671c @ 0022671c (14 bytes)

void FUN_0022671c(void)

{
  FUN_00226854(0xffff001a,0);
  return;
}


// ===== FUN_00226744 @ 00226744 (69 bytes)

undefined4 FUN_00226744(int param_1,undefined *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  if (1 < param_1 - 3U) {
    return 0xffff0001;
  }
  uVar1 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar1 & 0xf) < 4) {
    uVar2 = uVar1 & 0xfffffff0 | 4;
    in_st_PSWOE = wsr_ps(uVar2);
    in_st_PSCALLINC = wsr_ps_1(uVar2);
    in_st_PSOWB = wsr_ps_2(uVar2);
    in_st_PSUM = wsr_ps_3(uVar2);
    in_st_PSEXCM = wsr_ps_4(uVar2);
    in_st_PSINTLEVEL = wsr_ps_5(uVar2);
    rsync();
  }
  (&PTR_DAT_00237a8c)[param_1] = param_2;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar1 = uVar1 & 0xf | uVar2 & 0xfffffff0;
  wsr_ps(uVar1);
  wsr_ps_1(uVar1);
  wsr_ps_2(uVar1);
  wsr_ps_3(uVar1);
  wsr_ps_4(uVar1);
  wsr_ps_5(uVar1);
  rsync();
  return 0;
}


// ===== xos_interrupt_enable @ 0022678c (57 bytes)

void xos_interrupt_enable(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = rsil(0xf);
  DAT_00237854 = DAT_00237854 | 1 << 0x20 - (0x20 - (param_1 & 0x1f));
  iVar1 = FUN_002278a4();
  if (iVar1 == 1) {
    wsr_intenable(DAT_00237854 & DAT_00237850);
  }
  wsr_ps(uVar2);
  wsr_ps_1(uVar2);
  wsr_ps_2(uVar2);
  wsr_ps_3(uVar2);
  wsr_ps_4(uVar2);
  wsr_ps_5(uVar2);
  rsync();
  return;
}


// ===== FUN_002267c8 @ 002267c8 (24 bytes)

bool FUN_002267c8(uint param_1)

{
  return (DAT_00237854 & 1 << 0x20 - (0x20 - (param_1 & 0x1f))) != 0;
}


// ===== FUN_002267e0 @ 002267e0 (61 bytes)

void FUN_002267e0(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = rsil(0xf);
  DAT_00237854 = DAT_00237854 & (1 << 0x20 - (0x20 - (param_1 & 0x1f)) ^ 0xffffffffU);
  iVar1 = FUN_002278a4();
  if (iVar1 == 1) {
    wsr_intenable(DAT_00237854 & DAT_00237850);
  }
  wsr_ps(uVar2);
  wsr_ps_1(uVar2);
  wsr_ps_2(uVar2);
  wsr_ps_3(uVar2);
  wsr_ps_4(uVar2);
  wsr_ps_5(uVar2);
  rsync();
  return;
}


// ===== FUN_00226820 @ 00226820 (35 bytes)

bool FUN_00226820(uint param_1)

{
  if (0x1f < param_1) {
    return false;
  }
  return (code *)(&PTR_FUN_00237860)[param_1 * 4] != FUN_0022671c;
}


// ===== FUN_00226844 @ 00226844 (15 bytes)

undefined4 FUN_00226844(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_002cb0d8;
  DAT_002cb0d8 = param_1;
  return uVar1;
}


// ===== FUN_00226854 @ 00226854 (28 bytes)

void FUN_00226854(undefined4 param_1,undefined4 param_2)

{
  if (DAT_002cb0d8 != (code *)0x0) {
    (*DAT_002cb0d8)(param_1,param_2);
  }
  FUN_00227f3c();
  breakpoint(0x1000,0x22686a,1,0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_00226870 @ 00226870 (41 bytes)

void FUN_00226870(void)

{
  uint uVar1;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  uVar1 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((((uVar1 & 0x20) == 0) || (DAT_00237858 == (undefined *)0x0)) ||
     (DAT_00237858 == &DAT_002cb0f0)) {
    FUN_00226854(0xffff001b,0);
  }
  FUN_00227c64(0xffff001b);
  return;
}


// ===== FUN_0022689c @ 0022689c (67 bytes)

undefined * FUN_0022689c(uint param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar8;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined *puVar9;
  code *pcVar10;
  
  if (param_1 < 0x40) {
    uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    pcVar10 = (code *)0x2;
    uVar7 = uVar6 & 0xfffffff0 | 2;
    uVar1 = wsr_ps(uVar7);
    uVar2 = wsr_ps_1(uVar7);
    uVar3 = wsr_ps_2(uVar7);
    uVar4 = wsr_ps_3(uVar7);
    uVar5 = wsr_ps_4(uVar7);
    uVar8 = wsr_ps_5(uVar7);
    rsync();
    puVar9 = (&PTR_FUN_00237744)[param_1];
    if (param_2 == 0) {
      pcVar10 = FUN_00226870;
    }
    (&PTR_FUN_00237744)[param_1] = pcVar10;
    uVar7 = rsr_ps(uVar1,uVar2,uVar3,uVar4,uVar5,uVar8);
    uVar6 = uVar7 & 0xfffffff0 | uVar6 & 0xf;
    wsr_ps(uVar6);
    wsr_ps_1(uVar6);
    wsr_ps_2(uVar6);
    wsr_ps_3(uVar6);
    wsr_ps_4(uVar6);
    wsr_ps_5(uVar6);
    rsync();
    return puVar9;
  }
  return (undefined *)0x0;
}

