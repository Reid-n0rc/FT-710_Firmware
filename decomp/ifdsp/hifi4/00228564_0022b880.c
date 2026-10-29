// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00228564 @ 00228564 (207 bytes)

undefined8 FUN_00228564(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined6 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 in_CCOUNT;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar7;
  undefined1 in_st_PSUM;
  undefined1 uVar8;
  undefined1 in_st_PSWOE;
  undefined1 uVar9;
  undefined1 in_st_PSEXCM;
  undefined1 uVar10;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar11;
  undefined1 in_st_PSOWB;
  undefined1 uVar12;
  
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x20) != '\0') {
      FUN_002284e8(param_1);
    }
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
    uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar3 & 0xf | uVar2 & 0xfffffff0);
    rsync();
    iVar6 = rsr_ccount(in_CCOUNT);
    uVar3 = (iVar6 - DAT_002cb6a0) + DAT_002cb698;
    iVar4 = DAT_002cb69c;
    if (uVar3 < (uint)(iVar6 - DAT_002cb6a0)) {
      iVar4 = DAT_002cb69c + 1;
    }
    iVar4 = param_4 + iVar4;
    uVar3 = param_3 + uVar3;
    uVar2 = uVar3;
    if (*(int *)(param_1 + 0x14) != 0) {
      uVar2 = 1;
    }
    if (uVar3 < param_3) {
      iVar4 = iVar4 + 1;
    }
    *(uint *)(param_1 + 8) = uVar3;
    uVar3 = uVar2;
    if (*(int *)(param_1 + 0x10) != 0) {
      uVar3 = 1;
    }
    *(int *)(param_1 + 0xc) = iVar4;
    uVar5 = param_3;
    iVar4 = param_4;
    if (uVar3 == 0 && uVar2 == 0) {
      uVar5 = 0;
      iVar4 = 0;
    }
    *(int *)(param_1 + 0x14) = iVar4;
    *(uint *)(param_1 + 0x10) = uVar5;
    uVar3 = rsr_ps((char)uVar1,(char)((uint6)uVar1 >> 8),(char)((uint6)uVar1 >> 0x10),
                   (char)((uint6)uVar1 >> 0x18),(char)((uint6)uVar1 >> 0x20),
                   (char)((uint6)uVar1 >> 0x28));
    uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
    uVar9 = (undefined1)uVar1;
    uVar11 = (undefined1)((uint6)uVar1 >> 8);
    uVar12 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar8 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar10 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar7 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    FUN_00228748(param_1,2,param_3,param_4);
    *(undefined1 *)(param_1 + 0x20) = 1;
    uVar2 = rsr_ps(uVar9,uVar11,uVar12,uVar8,uVar10,uVar7);
    wsr_ps(uVar2 & 0xfffffff0 | uVar3 & 0xf);
    rsync();
    return 0xfffffff000000000;
  }
  return CONCAT44(param_2,0xffff0001);
}


// ===== FUN_00228634 @ 00228634 (56 bytes)

longlong FUN_00228634(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  
  if (param_1 != 0) {
    uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
    rsync();
    *(undefined4 *)(param_1 + 0x10) = param_3;
    *(undefined4 *)(param_1 + 0x14) = param_4;
    uVar2 = rsr_ps((char)uVar1,(char)((uint6)uVar1 >> 8),(char)((uint6)uVar1 >> 0x10),
                   (char)((uint6)uVar1 >> 0x18),(char)((uint6)uVar1 >> 0x20),
                   (char)((uint6)uVar1 >> 0x28));
    wsr_ps(uVar2 & 0xfffffff0 | uVar3 & 0xf);
    rsync();
    return (ulonglong)(uVar3 & 0xf) << 0x20;
  }
  return CONCAT44(param_2,0xffff0001);
}


// ===== xos_thread_sleep @ 0022866c (140 bytes)

int xos_thread_sleep(int param_1,undefined4 param_2)

{
  undefined6 uVar1;
  int iVar2;
  undefined4 extraout_a3;
  uint uVar3;
  uint uVar4;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar5;
  undefined1 in_st_PSUM;
  undefined1 uVar6;
  undefined1 in_st_PSWOE;
  undefined1 uVar7;
  undefined1 in_st_PSEXCM;
  undefined1 uVar8;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar9;
  undefined1 in_st_PSOWB;
  undefined1 uVar10;
  undefined1 auStack_50 [80];
  
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar3 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  if (param_1 != 0) {
    FUN_002354c0(auStack_50);
    uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
    uVar7 = (undefined1)uVar1;
    uVar9 = (undefined1)((uint6)uVar1 >> 8);
    uVar10 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar6 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar8 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar5 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    iVar2 = FUN_002283e0(auStack_50,extraout_a3,param_1,param_2,0,FUN_00228734,DAT_00237858);
    if (iVar2 == 0) {
      iVar2 = FUN_0022795c("delay",0,0,0);
    }
    uVar4 = rsr_ps(uVar7,uVar9,uVar10,uVar6,uVar8,uVar5);
    wsr_ps(uVar4 & 0xfffffff0 | uVar3 & 0xf);
    rsync();
    return iVar2;
  }
  return -0xffff;
}


// ===== FUN_002286fc @ 002286fc (54 bytes)

undefined4 FUN_002286fc(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar2 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  if ((param_1 != 0) && (*(char *)(param_1 + 0x20) != '\0')) {
    uVar1 = FUN_0022795c("delay",param_1 + 0x24,0,0);
    return uVar1;
  }
  return 0xffff0001;
}


// ===== FUN_00228734 @ 00228734 (19 bytes)

void FUN_00228734(undefined4 param_1)

{
  FUN_00227a24(param_1,"delay",0);
  return;
}


// ===== FUN_00228748 @ 00228748 (175 bytes)

void FUN_00228748(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined4 in_CCOUNT;
  
  puVar1 = DAT_002cb6a8;
  puVar5 = &DAT_002cb6a8;
  while (puVar2 = puVar1, bVar4 = false, puVar2 != (undefined4 *)0x0) {
    if (((uint)puVar2[3] <= (uint)param_1[3]) &&
       ((puVar2[3] != param_1[3] || ((uint)puVar2[2] < (uint)param_1[2])))) {
      bVar4 = true;
    }
    if (!bVar4) break;
    puVar5 = puVar2;
    puVar1 = (undefined4 *)*puVar2;
  }
  *param_1 = (int)puVar2;
  *puVar5 = param_1;
  iVar3 = *param_1;
  if (iVar3 != 0) {
    bVar4 = false;
    if ((*(uint *)(iVar3 + 0xc) <= (uint)param_1[3]) &&
       ((*(uint *)(iVar3 + 0xc) != param_1[3] || (*(uint *)(iVar3 + 8) < (uint)param_1[2])))) {
      bVar4 = true;
    }
    if (bVar4) {
      FUN_00226854(0xffff0020,0);
    }
  }
  if (DAT_002cb688 != '\0') {
    iVar3 = rsr_ccount(in_CCOUNT);
    if (PTR_DAT_00237a8c + param_3 < PTR_DAT_00237a8c) {
      param_4 = param_4 + 1;
    }
    bVar4 = false;
    if ((param_4 != 0) || ((undefined *)(DAT_002cb6a4 - iVar3) <= PTR_DAT_00237a8c + param_3)) {
      bVar4 = true;
    }
    if ((!bVar4) && (iVar3 = FUN_0022930c(), iVar3 != 1)) {
      iVar3 = rsr_ccount(in_CCOUNT);
      DAT_002cb6a4 = iVar3 + param_3;
      FUN_002292ac(param_3);
    }
  }
  return;
}


// ===== FUN_002287f8 @ 002287f8 (2 bytes)

void FUN_002287f8(void)

{
  return;
}


// ===== FUN_00228b08 @ 00228b08 (43 bytes)

void FUN_00228b08(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 in_CCOUNT;
  
  uVar1 = rsr_ccount(in_CCOUNT);
  *(undefined4 *)(param_1 + 0x6c) = uVar1;
  wsr_excsave1(&LAB_0022884d);
  *param_2 = 0xffffffff;
  wsr_intenable(param_2[1]);
  wsr_ps(&DAT_00040020);
  rsync();
  do {
    waiti(0);
  } while( true );
}


// ===== FUN_00228c44 @ 00228c44 (77 bytes)

void FUN_00228c44(int param_1)

{
  int *piVar1;
  int extraout_a2;
  undefined4 *puVar2;
  undefined4 *extraout_a3;
  int extraout_a4;
  int extraout_a4_00;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE_00;
  int iVar6;
  undefined4 in_WindowBase;
  undefined4 in_CCOUNT;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  int iVar7;
  int iVar8;
  
  iVar3 = DAT_00237858;
  if (*(char *)(DAT_00237858 + 0x30) == '\0') {
    uVar5 = rsr_windowbase(in_WindowBase);
    wsr_windowstart(1 << 0x20 - (0x20 - (uVar5 & 0x1f)));
    rsync();
    rsil(2);
    *(undefined1 **)(DAT_00237858 + 0xc) = &LAB_00228c94;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(param_1 + 0xc);
    iVar6 = rsr_ccount(in_CCOUNT);
    iVar7 = *(int *)(DAT_00237858 + 0x70);
    iVar6 = iVar7 + (iVar6 - *(int *)(DAT_00237858 + 0x6c));
    piVar1 = (int *)(DAT_00237858 + 0x70);
    DAT_00237858 = param_1;
    DAT_0023785c = param_1;
    *piVar1 = iVar6;
    if (iVar6 < iVar7) {
      *(int *)(iVar3 + 0x74) = *(int *)(iVar3 + 0x74) + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00228c8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)();
    return;
  }
  uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  iVar3 = (uVar5 & 0xfffbfff0) + 2;
  wsr_ps(iVar3);
  rsync();
  FUN_002332c4(param_1,&DAT_00237850,param_1,iVar3);
  iVar3 = DAT_00237858;
  puVar2 = &DAT_00237850;
  *(undefined1 **)(DAT_00237858 + 0x10) = &stack0xffffffd0;
  *(undefined1 **)(iVar3 + 0xc) = &LAB_00228d78;
  puVar4 = *(undefined2 **)(iVar3 + 0x14);
  iVar7 = rsr_cpenable();
  iVar6 = extraout_a4;
  if (iVar7 != 0) {
    func_0x002291d8();
    wsr_cpenable(0);
    iVar6 = extraout_a2;
    puVar2 = extraout_a3;
    iVar3 = extraout_a4_00;
  }
  if (puVar4 != (undefined2 *)0x0) {
    *puVar4 = 0;
  }
  iVar7 = rsr_ccount(in_CCOUNT);
  iVar8 = *(int *)(iVar3 + 0x70);
  iVar7 = iVar8 + (iVar7 - *(int *)(iVar3 + 0x6c));
  *(int *)(iVar3 + 0x70) = iVar7;
  if (iVar7 < iVar8) {
    *(int *)(iVar3 + 0x74) = *(int *)(iVar3 + 0x74) + 1;
  }
  UNRECOVERED_JUMPTABLE_00 = *(code **)(iVar6 + 0xc);
  puVar2[3] = iVar6;
  puVar2[2] = iVar6;
                    /* WARNING: Could not recover jumptable at 0x00228d65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)();
  return;
}


// ===== FUN_00228cfc @ 00228cfc (108 bytes)

void FUN_00228cfc(undefined4 param_1,undefined4 param_2)

{
  int extraout_a2;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *extraout_a3;
  int extraout_a4;
  int extraout_a4_00;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 in_CCOUNT;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  int iVar7;
  
  uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  iVar3 = (uVar5 & 0xfffbfff0) + 2;
  wsr_ps(iVar3);
  rsync();
  FUN_002332c4(param_1,param_2,param_1,iVar3);
  iVar3 = DAT_00237858;
  puVar2 = &DAT_00237850;
  *(undefined1 **)(DAT_00237858 + 0x10) = &stack0xffffffd0;
  *(undefined1 **)(iVar3 + 0xc) = &LAB_00228d78;
  puVar6 = *(undefined2 **)(iVar3 + 0x14);
  iVar4 = rsr_cpenable();
  iVar1 = extraout_a4;
  if (iVar4 != 0) {
    func_0x002291d8();
    wsr_cpenable(0);
    iVar1 = extraout_a2;
    puVar2 = extraout_a3;
    iVar3 = extraout_a4_00;
  }
  if (puVar6 != (undefined2 *)0x0) {
    *puVar6 = 0;
  }
  iVar4 = rsr_ccount(in_CCOUNT);
  iVar7 = *(int *)(iVar3 + 0x70);
  iVar4 = iVar7 + (iVar4 - *(int *)(iVar3 + 0x6c));
  *(int *)(iVar3 + 0x70) = iVar4;
  if (iVar4 < iVar7) {
    *(int *)(iVar3 + 0x74) = *(int *)(iVar3 + 0x74) + 1;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xc);
  puVar2[3] = iVar1;
  puVar2[2] = iVar1;
                    /* WARNING: Could not recover jumptable at 0x00228d65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ===== FUN_00228d68 @ 00228d68 (15 bytes)

void FUN_00228d68(int param_1)

{
  DAT_00237858 = param_1;
  DAT_0023785c = param_1;
                    /* WARNING: Could not recover jumptable at 0x00228d74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0xc))(param_1,&DAT_00237850,*(code **)(param_1 + 0xc));
  return;
}


// ===== FUN_00228dc0 @ 00228dc0 (43 bytes)

void FUN_00228dc0(void)

{
  if ((char)DAT_002cd6d4 != '\0') {
    if (DAT_002cd6b0 == DAT_00237858) {
      DAT_002cd6d0 = DAT_002cd6d0 + 1;
    }
    else {
      xos_mutex_lock(&DAT_002cd6b0);
      DAT_002cd6d0 = 1;
    }
    return;
  }
  return;
}


// ===== FUN_00228df0 @ 00228df0 (43 bytes)

void FUN_00228df0(void)

{
  int iVar1;
  
  if (((((char)DAT_002cd6d4 != '\0') && (DAT_002cd6b0 == DAT_00237858)) &&
      (iVar1 = DAT_002cd6d0 + -1, DAT_002cd6d0 != 0)) && (DAT_002cd6d0 = iVar1, iVar1 == 0)) {
    xos_mutex_unlock();
  }
  return;
}


// ===== FUN_00228e1c @ 00228e1c (10 bytes)

void FUN_00228e1c(undefined4 param_1)

{
  FUN_00228dc0(param_1);
  return;
}


// ===== FUN_00228e28 @ 00228e28 (10 bytes)

void FUN_00228e28(undefined4 param_1)

{
  FUN_00228df0(param_1);
  return;
}


// ===== FUN_00228e34 @ 00228e34 (42 bytes)

undefined * FUN_00228e34(undefined4 *param_1,int param_2)

{
  undefined *puVar1;
  
  puVar1 = DAT_002cd6d8;
  if (DAT_002cd6d8 == (undefined *)0x0) {
    puVar1 = &DAT_002cd860;
  }
  if ((undefined *)0x47ffff < puVar1 + param_2) {
    DAT_002cd6d8 = puVar1;
    *param_1 = 0xc;
    return (undefined *)0xffffffff;
  }
  DAT_002cd6d8 = puVar1 + param_2;
  return puVar1;
}


// ===== FUN_00228e60 @ 00228e60 (33 bytes)

void FUN_00228e60(void)

{
  FUN_0022700c(&DAT_002cd6b0,0,0);
  DAT_002cd6d0 = 0;
  DAT_002cd6d4._0_1_ = 1;
  return;
}


// ===== FUN_00228e84 @ 00228e84 (290 bytes)

void FUN_00228e84(int param_1)

{
  memset(param_1 + 0x90,0,0x428);
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(int *)(param_1 + 0x98) = param_1 + 0x3e4;
  *(int *)(param_1 + 0x94) = param_1 + 0x37c;
  *(int *)(param_1 + 0x9c) = param_1 + 0x44c;
  memset(param_1 + 0xa4,0,0x19);
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined1 *)(param_1 + 0xf0) = 0;
  *(undefined **)(param_1 + 0xc4) = &DAT_00206410;
  memset(param_1 + 0x10c,0,0x24);
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 400) = 0;
  *(undefined4 *)(param_1 + 0x194) = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined2 *)(param_1 + 0x142) = 0xabcd;
  *(undefined2 *)(param_1 + 0x144) = 0x1234;
  *(undefined2 *)(param_1 + 0x146) = 0xe66d;
  *(undefined2 *)(param_1 + 0x148) = 0xdeec;
  *(undefined2 *)(param_1 + 0x14a) = 5;
  *(undefined4 *)(param_1 + 0x138) = 1;
  *(undefined2 *)(param_1 + 0x140) = 0x330e;
  *(undefined2 *)(param_1 + 0x14c) = 0xb;
  *(undefined1 *)(param_1 + 0x168) = 0;
  *(undefined1 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  *(undefined4 *)(param_1 + 0x1e0) = 0;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined4 *)(param_1 + 0x364) = 0;
  *(undefined4 *)(param_1 + 0x264) = 0;
  *(undefined4 *)(param_1 + 0x36c) = 0;
  *(undefined4 *)(param_1 + 0x370) = 0;
  *(undefined4 *)(param_1 + 0x374) = 0;
  *(undefined4 *)(param_1 + 0x378) = 0;
  memset(param_1 + 0x37c,0,0x138);
  *(int *)(param_1 + 100) = param_1 + 0x90;
  return;
}


// ===== FUN_00228fb0 @ 00228fb0 (44 bytes)

void FUN_00228fb0(int param_1)

{
  *(undefined4 *)(param_1 + 0x3a8) = 0;
  FUN_0022c150(param_1 + 0x90);
  FUN_0022c0c0(param_1 + 0x90);
  return;
}


// ===== FUN_00229224 @ 00229224 (17 bytes)

void FUN_00229224(void)

{
  FUN_0022700c(&DAT_002cd6dc,0,0);
  return;
}


// ===== FUN_00229238 @ 00229238 (71 bytes)

undefined4 FUN_00229238(int *param_1,code *param_2)

{
  if ((param_1 != (int *)0x0) && (param_2 != (code *)0x0)) {
    if (*param_1 != 2) {
      xos_mutex_lock(&DAT_002cd6dc);
      if (*param_1 == 0) {
        *param_1 = 1;
        (*param_2)();
        *param_1 = 2;
      }
      else if (*param_1 != 2) {
        FUN_00226854(0xffff0020,0);
      }
      xos_mutex_unlock(&DAT_002cd6dc);
    }
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_00229284 @ 00229284 (39 bytes)

undefined4 FUN_00229284(void)

{
  undefined4 uVar1;
  undefined4 in_CCOMPARE0;
  undefined4 in_CCOMPARE1;
  
  if (DAT_00237ac8 == 1) {
    uVar1 = rsr_ccompare1(in_CCOMPARE1);
    return uVar1;
  }
  if (DAT_00237ac8 != 0) {
    FUN_00226854(0xffff0020,0);
    return 0;
  }
  uVar1 = rsr_ccompare0(in_CCOMPARE0);
  return uVar1;
}


// ===== FUN_002292ac @ 002292ac (93 bytes)

void FUN_002292ac(int param_1)

{
  undefined6 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 in_INTERRUPT;
  undefined4 in_CCOUNT;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar2 & 0xf) < 4) {
    uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 4);
    in_st_PSWOE = (undefined1)uVar1;
    in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
  }
  iVar3 = rsr_ccount(in_CCOUNT);
  if (DAT_00237ac8 == 1) {
    wsr_ccompare1(iVar3 + param_1,in_INTERRUPT);
    isync();
  }
  else if (DAT_00237ac8 == 0) {
    wsr_ccompare0(iVar3 + param_1,in_INTERRUPT);
    isync();
  }
  else {
    FUN_00226854(0xffff0020,0);
  }
  uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar2 & 0xf | uVar4 & 0xfffffff0);
  rsync();
  return;
}


// ===== FUN_0022930c @ 0022930c (38 bytes)

bool FUN_0022930c(void)

{
  uint uVar1;
  undefined4 in_INTERRUPT;
  
  if (DAT_002cd6fc < 0x20) {
    uVar1 = rsr_interrupt(in_INTERRUPT);
    uVar1 = uVar1 & 1 << 0x20 - (0x20 - (DAT_002cd6fc & 0x1f));
  }
  else {
    uVar1 = 0;
  }
  return uVar1 != 0;
}


// ===== FUN_00229340 @ 00229340 (106 bytes)

/* WARNING: Removing unreachable block (ram,0x002293a5) */

undefined4 FUN_00229340(int param_1,int *param_2)

{
  if (param_1 == -1) {
    param_1 = 0;
  }
  if (((-1 < param_1) && (param_1 < 2)) &&
     (DAT_002cd6fc = (&DAT_00200060)[param_1], (byte)(&DAT_00200000)[DAT_002cd6fc] < 3)) {
    *param_2 = param_1;
    DAT_00237ac8 = param_1;
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_002293ac @ 002293ac (31 bytes)

void FUN_002293ac(undefined4 param_1)

{
  xos_register_interrupt_handler(DAT_002cd6fc,FUN_002293cc,0);
  FUN_002292ac(param_1);
  xos_interrupt_enable(DAT_002cd6fc);
  return;
}


// ===== FUN_002293cc @ 002293cc (8 bytes)

void FUN_002293cc(void)

{
  FUN_00228158();
  return;
}


// ===== FUN_002293e0 @ 002293e0 (100 bytes)

void FUN_002293e0(void)

{
  uint uVar1;
  undefined8 in_aed0;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar1 = ae_s32_l_i(in_aed0);
  if ((uVar1 & 0x7fffffff) < 0x3f490fd9) {
    const_s(0);
    FUN_0022a610();
    return;
  }
  if (0x7f7fffff < (uVar1 & 0x7fffffff)) {
    return;
  }
  uVar1 = FUN_0022a320(&uStack_28);
  uVar1 = uVar1 & 3;
  ae_l32_i(uStack_24);
  ae_l32_i(uStack_28);
  if (uVar1 == 0) {
    FUN_0022a610();
    return;
  }
  if (uVar1 != 1) {
    if (uVar1 != 2) {
      FUN_0022b420(1);
      return;
    }
    FUN_0022a610();
    return;
  }
  FUN_0022b420(1);
  return;
}


// ===== FUN_00229460 @ 00229460 (105 bytes)

void FUN_00229460(void)

{
  uint uVar1;
  undefined8 in_aed0;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar1 = ae_s32_l_i(in_aed0);
  if ((uVar1 & 0x7fffffff) < 0x3f490fd9) {
    const_s(0);
    FUN_0022b420(0);
    return;
  }
  if (0x7f7fffff < (uVar1 & 0x7fffffff)) {
    return;
  }
  uVar1 = FUN_0022a320(&uStack_28);
  uVar1 = uVar1 & 3;
  ae_l32_i(uStack_24);
  ae_l32_i(uStack_28);
  if (uVar1 == 0) {
    FUN_0022b420(1);
    return;
  }
  if (uVar1 != 1) {
    if (uVar1 != 2) {
      FUN_0022a610();
      return;
    }
    FUN_0022b420(1);
    return;
  }
  FUN_0022a610();
  return;
}


// ===== FUN_002294e0 @ 002294e0 (1240 bytes)

void FUN_002294e0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  undefined8 in_aed0;
  undefined8 uVar5;
  undefined8 in_aed1;
  undefined8 uVar6;
  undefined4 local_70;
  char *pcStack_6c;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  int iStack_50;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uStack_2c = ae_s32_l_i(in_aed1);
  uStack_30 = ae_s32_l_i(in_aed0);
  uVar6 = ae_l32_i(uStack_30);
  ae_l32_i(uStack_2c);
  FUN_00229b10();
  uStack_38 = ae_s64_i(uVar6);
  if (DAT_00237acc == -1) {
LAB_002295b7:
    ae_l64_i(uStack_38);
    return;
  }
  ae_l32_i(uStack_2c);
  iVar1 = FUN_0022b6c0();
  if (iVar1 == 0) goto LAB_002295b7;
  ae_l32_i(uStack_30);
  iVar1 = FUN_0022b6c0();
  uVar6 = const_s(0);
  if (iVar1 == 0) {
    uVar5 = ae_l32_i(uStack_2c);
    uVar4 = oeq_s(uVar5,uVar6);
    if (SUB21(uVar4,0)) {
      local_70 = 1;
      pcStack_6c = "powf";
      iStack_50 = 0;
      ae_l32_i(uStack_30);
      uStack_68 = FUN_0022b96c();
      ae_l32_i(uStack_2c);
      uStack_60 = FUN_0022b96c();
      uStack_58._4_4_ = 0x3ff00000;
      uStack_58._0_4_ = 0;
      if ((DAT_00237acc == -1) || (DAT_00237acc == 2)) {
        uStack_58._0_4_ = 0;
        uStack_58._4_4_ = 0x3ff00000;
      }
      else {
        iVar1 = FUN_0022b4d0(&local_70);
        if (iVar1 == 0) {
          puVar3 = (undefined4 *)FUN_0022ba10();
          *puVar3 = 0x21;
        }
        if (iStack_50 != 0) {
          piVar2 = (int *)FUN_0022ba10();
          *piVar2 = iStack_50;
        }
      }
      FUN_0022b8ac((undefined4)uStack_58,uStack_58._4_4_);
      return;
    }
    ae_l64_i(uStack_38);
    return;
  }
  uVar5 = ae_l32_i(uStack_30);
  uVar4 = oeq_s(uVar5,uVar6);
  uVar5 = ae_l32_i(uStack_2c);
  if (!SUB21(uVar4,0)) {
    ae_l64_i(uStack_38);
    iVar1 = FUN_0022b6a0();
    if (iVar1 != 0) {
LAB_00229667:
      uVar6 = ae_l64_i(uStack_38);
      uVar5 = ae_l32_i(0);
      uVar4 = oeq_s(uVar6,uVar5);
      if (SUB21(uVar4,0)) {
        ae_l32_i(uStack_30);
        iVar1 = FUN_0022b6a0();
        if (iVar1 != 0) {
          ae_l32_i(uStack_2c);
          iVar1 = FUN_0022b6a0();
          if (iVar1 != 0) {
            iStack_50 = 0;
            pcStack_6c = "powf";
            local_70 = 4;
            ae_l32_i(uStack_30);
            uStack_68 = FUN_0022b96c();
            ae_l32_i(uStack_2c);
            uStack_60 = FUN_0022b96c();
            uStack_58._4_4_ = 0;
            uStack_58._0_4_ = 0;
            if (DAT_00237acc == 2) {
              puVar3 = (undefined4 *)FUN_0022ba10();
              *puVar3 = 0x22;
            }
            else {
              iVar1 = FUN_0022b4d0(&local_70);
              if (iVar1 == 0) {
                puVar3 = (undefined4 *)FUN_0022ba10();
                *puVar3 = 0x22;
              }
            }
            if (iStack_50 != 0) {
              piVar2 = (int *)FUN_0022ba10();
              *piVar2 = iStack_50;
            }
            FUN_0022b8ac((undefined4)uStack_58,uStack_58._4_4_);
            return;
          }
        }
      }
      ae_l64_i(uStack_38);
      return;
    }
    ae_l32_i(uStack_30);
    iVar1 = FUN_0022b6a0();
    if (iVar1 == 0) goto LAB_00229667;
    ae_l32_i(uStack_2c);
    iVar1 = FUN_0022b6a0();
    if (iVar1 == 0) goto LAB_00229667;
    ae_l64_i(uStack_38);
    iStack_48 = FUN_0022b6c0();
    ae_l32_i(uStack_30);
    uVar6 = FUN_0022b96c();
    uStack_44 = (undefined4)((ulonglong)uVar6 >> 0x20);
    uStack_40 = (undefined4)uVar6;
    ae_l32_i(uStack_2c);
    uStack_60 = FUN_0022b96c();
    iVar1 = DAT_00237acc;
    if (iStack_48 != 0) {
      iStack_50 = 0;
      pcStack_6c = "powf";
      uStack_68._4_4_ = uStack_44;
      uStack_68._0_4_ = uStack_40;
      local_70 = 3;
      const_s(3);
      if (DAT_00237acc == 0) {
        uVar6 = ae_l32_i(uStack_30);
        uVar5 = ae_l32_i(0);
        uVar4 = olt_s(uVar6,uVar5);
        uStack_58._4_4_ = 0x47efffff;
        uStack_58._0_4_ = 0xe0000000;
        if (SUB21(uVar4,0)) {
          ae_l32_i(uStack_2c);
          uVar6 = FUN_0022b96c();
          uVar5 = FUN_0022b4f0();
          iVar1 = FUN_0022b874((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar6,
                               (int)((ulonglong)uVar6 >> 0x20));
          if (iVar1 != 0) {
            uStack_58._4_4_ = 0xc7efffff;
            uStack_58._0_4_ = 0xe0000000;
          }
        }
      }
      else {
        uVar6 = ae_l32_i(uStack_30);
        uVar5 = ae_l32_i(0);
        uVar4 = olt_s(uVar6,uVar5);
        uStack_58._4_4_ = 0x7ff00000;
        uStack_58._0_4_ = 0;
        if (SUB21(uVar4,0)) {
          ae_l32_i(uStack_2c);
          uVar6 = FUN_0022b96c();
          uVar5 = FUN_0022b4f0();
          iVar1 = FUN_0022b874((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar6,
                               (int)((ulonglong)uVar6 >> 0x20));
          if (iVar1 != 0) {
            uStack_58._4_4_ = 0xfff00000;
            uStack_58._0_4_ = 0;
          }
        }
      }
      if (DAT_00237acc == 2) {
        puVar3 = (undefined4 *)FUN_0022ba10();
        *puVar3 = 0x22;
      }
      else {
        iVar1 = FUN_0022b4d0(&local_70);
        if (iVar1 == 0) {
          puVar3 = (undefined4 *)FUN_0022ba10();
          *puVar3 = 0x22;
        }
      }
      if (iStack_50 != 0) {
        piVar2 = (int *)FUN_0022ba10();
        *piVar2 = iStack_50;
      }
      FUN_0022b8ac((undefined4)uStack_58,uStack_58._4_4_);
      return;
    }
    iStack_50 = 0;
    local_70 = 1;
    pcStack_6c = "powf";
    uStack_68._4_4_ = uStack_44;
    uStack_68._0_4_ = uStack_40;
    if (DAT_00237acc == 0) {
      uStack_58 = 0;
    }
    else {
      uStack_58 = FUN_002357c0(0,0,0,0);
      if (iVar1 == 2) {
        puVar3 = (undefined4 *)FUN_0022ba10();
        *puVar3 = 0x21;
        goto LAB_0022993e;
      }
    }
    iVar1 = FUN_0022b4d0(&local_70);
    if (iVar1 == 0) {
      puVar3 = (undefined4 *)FUN_0022ba10();
      *puVar3 = 0x21;
    }
LAB_0022993e:
    uVar6 = uStack_58;
    if (iStack_50 != 0) {
      piVar2 = (int *)FUN_0022ba10();
      *piVar2 = iStack_50;
      uVar6 = uStack_58;
    }
    uStack_58._4_4_ = (undefined4)((ulonglong)uVar6 >> 0x20);
    uStack_58._0_4_ = (undefined4)uVar6;
    FUN_0022b8ac((undefined4)uStack_58,uStack_58._4_4_);
    uStack_58 = uVar6;
    return;
  }
  uVar4 = oeq_s(uVar5,uVar6);
  if (SUB21(uVar4,0)) {
    local_70 = 1;
    pcStack_6c = "powf";
    iStack_50 = 0;
    ae_l32_i(uStack_30);
    uStack_68 = FUN_0022b96c();
    ae_l32_i(uStack_2c);
    uStack_60 = FUN_0022b96c();
    uStack_58._4_4_ = 0;
    uStack_58._0_4_ = 0;
    if (DAT_00237acc == 0) {
      iVar1 = FUN_0022b4d0(&local_70);
      if (iVar1 == 0) {
        puVar3 = (undefined4 *)FUN_0022ba10();
        *puVar3 = 0x21;
      }
      if (iStack_50 != 0) {
        piVar2 = (int *)FUN_0022ba10();
        *piVar2 = iStack_50;
      }
    }
    else {
      uStack_58._0_4_ = 0;
      uStack_58._4_4_ = 0x3ff00000;
    }
    FUN_0022b8ac((undefined4)uStack_58,uStack_58._4_4_);
    return;
  }
  ae_l32_i(uStack_2c);
  iVar1 = FUN_0022b6a0();
  if (iVar1 == 0) {
LAB_00229650:
    ae_l64_i(uStack_38);
    return;
  }
  uVar6 = ae_l32_i(uStack_2c);
  uVar5 = ae_l32_i(0);
  uVar4 = olt_s(uVar6,uVar5);
  if (!SUB21(uVar4,0)) goto LAB_00229650;
  iStack_50 = 0;
  local_70 = 1;
  pcStack_6c = "powf";
  ae_l32_i(uStack_30);
  uStack_68 = FUN_0022b96c();
  ae_l32_i(uStack_2c);
  uStack_60 = FUN_0022b96c();
  if (DAT_00237acc == 0) {
    uStack_58._4_4_ = 0;
  }
  else {
    uStack_58._4_4_ = 0xfff00000;
    if (DAT_00237acc == 2) {
      uStack_58._0_4_ = 0;
      puVar3 = (undefined4 *)FUN_0022ba10();
      *puVar3 = 0x21;
      goto LAB_00229631;
    }
  }
  uStack_58._0_4_ = 0;
  iVar1 = FUN_0022b4d0(&local_70);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)FUN_0022ba10();
    *puVar3 = 0x21;
  }
LAB_00229631:
  if (iStack_50 != 0) {
    piVar2 = (int *)FUN_0022ba10();
    *piVar2 = iStack_50;
  }
  FUN_0022b8ac((undefined4)uStack_58,uStack_58._4_4_);
  return;
}


// ===== FUN_00229a20 @ 00229a20 (224 bytes)

void FUN_00229a20(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  undefined8 in_aed0;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uStack_60;
  char *pcStack_5c;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  int iStack_40;
  undefined8 uStack_38;
  undefined4 uStack_30;
  
  uStack_30 = ae_s32_l_i(in_aed0);
  uVar5 = ae_l32_i(uStack_30);
  sqrtf_();
  uStack_38 = ae_s64_i(uVar5);
  if (DAT_00237acc != -1) {
    ae_l32_i(uStack_30);
    iVar1 = FUN_0022b6c0();
    if (iVar1 != 0) {
      uVar5 = ae_l32_i(uStack_30);
      uVar6 = const_s(0);
      uVar4 = olt_s(uVar5,uVar6);
      ae_l64_i(uStack_38);
      if (SUB21(uVar4,0)) {
        ae_l32_i(uStack_30);
        pcStack_5c = "sqrtf";
        uStack_60 = 1;
        iStack_40 = 0;
        uStack_58 = FUN_0022b96c();
        iVar1 = DAT_00237acc;
        uStack_50 = uStack_58;
        if (DAT_00237acc == 0) {
          uStack_48 = 0;
        }
        else {
          uStack_48 = FUN_002357c0(0,0,0,0);
        }
        if (iVar1 == 2) {
          puVar3 = (undefined4 *)FUN_0022ba10();
          *puVar3 = 0x21;
        }
        else {
          iVar1 = FUN_0022b4d0(&uStack_60);
          if (iVar1 == 0) {
            puVar3 = (undefined4 *)FUN_0022ba10();
            *puVar3 = 0x21;
          }
        }
        uVar5 = uStack_48;
        if (iStack_40 != 0) {
          piVar2 = (int *)FUN_0022ba10();
          *piVar2 = iStack_40;
          uVar5 = uStack_48;
        }
        uStack_48._4_4_ = (undefined4)((ulonglong)uVar5 >> 0x20);
        uStack_48._0_4_ = (undefined4)uVar5;
        FUN_0022b8ac((undefined4)uStack_48,uStack_48._4_4_);
        uStack_48 = uVar5;
        return;
      }
      return;
    }
  }
  ae_l64_i(uStack_38);
  return;
}


// ===== FUN_00229b10 @ 00229b10 (2019 bytes)

void FUN_00229b10(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  float fVar8;
  undefined8 in_aed0;
  float fVar9;
  undefined8 in_aed1;
  float fVar10;
  float fVar11;
  undefined8 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined *puVar17;
  float fVar18;
  uint uVar19;
  int iVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  int iStack_74;
  
  uVar19 = ae_s32_l_i(in_aed0);
  puVar17 = (undefined *)ae_s32_l_i(in_aed1);
  uVar23 = const_s(1);
  uVar21 = ae_mov(in_aed0);
  uVar15 = uVar19 & 0x7fffffff;
  uVar16 = (uint)puVar17 & 0x7fffffff;
  if (((uint)puVar17 & 0x7fffffff) == 0) {
    ae_mov(uVar23);
    return;
  }
  if ((0x7f800000 < uVar15) || (0x7f800000 < uVar16)) {
    if (uVar15 == 0x3f800000) {
      ae_mov(uVar23);
      return;
    }
    FUN_0022b710("");
    return;
  }
  uVar12 = const_s(0);
  iVar6 = 0;
  if ((int)uVar19 < 0) {
    if (uVar16 < 0x4b800000) {
      if (uVar16 < 0x3f800000) {
        iVar6 = 0;
      }
      else {
        uVar13 = 0x96 - ((uint)puVar17 >> 0x17 & 0xff);
        uVar14 = (int)uVar16 >> (uVar13 & 0x1f);
        iVar6 = 2 - (uVar14 & 1);
        if (uVar16 != uVar14 << 0x20 - (0x20 - (uVar13 & 0x1f))) {
          iVar6 = 0;
        }
      }
    }
    else {
      iVar6 = 2;
    }
  }
  if (uVar16 == 0x7f800000) {
    if (uVar15 == 0x3f800000) {
      ae_mov(uVar23);
      return;
    }
    if (uVar15 < 0x3f800001) {
      movgez_s((ulonglong)(uint)-(float)in_aed1,uVar12,puVar17);
      return;
    }
    uVar21 = movnez_s(uVar12,in_aed1,(uint)puVar17 >> 0x1f ^ 1);
    ae_mov(uVar21);
    return;
  }
  if (uVar16 == 0x3f800000) {
    if (-1 < (int)puVar17) {
      ae_mov(uVar21);
      return;
    }
    ae_s64_i(uVar21);
    ae_l32_i(0x3f800000);
    ae_mov(uVar21);
    divf_();
    return;
  }
  if (puVar17 == &DAT_40000000) {
    return;
  }
  if (puVar17 == (undefined *)0x3f000000) {
    ae_s64_i(uVar12);
    ae_s64_i(uVar21);
    ae_s32_l_i(in_aed1);
    if (-1 < (int)uVar19) {
      ae_mov(uVar21);
      sqrtf_();
      return;
    }
  }
  uVar23 = ae_s64_i(uVar12);
  uVar24 = ae_mov(uVar21);
  uVar21 = ae_s64_i(uVar24);
  uVar3 = ae_s32_l_i(in_aed1);
  FUN_0022b680();
  uVar12 = ae_s64_i(uVar24);
  if (((uVar15 == 0x7f800000) || (uVar15 == 0)) || (uVar15 == 0x3f800000)) {
    ae_l64_i(uVar12);
    uVar21 = ae_l32_i(0x3f800000);
    divf_();
    uVar23 = ae_l64_i(uVar12);
    uVar21 = ae_mov(uVar21);
    uVar21 = movnez_s(uVar23,uVar21,(uint)puVar17 >> 0x1f);
    ae_s64_i(uVar21);
    if (-1 < (int)uVar19) {
      return;
    }
    fVar18 = (float)uVar21;
    if (iVar6 != 0 || uVar15 != 0x3f800000) {
      movnez_s(uVar21,(ulonglong)(uint)-fVar18,1);
      return;
    }
    ae_mov((ulonglong)(uint)(fVar18 - fVar18));
    divf_();
    return;
  }
  if (iVar6 == 0 && (int)uVar19 < 0) {
    uVar21 = ae_l64_i(uVar21);
    ae_mov((ulonglong)(uint)((float)uVar21 - (float)uVar21));
    divf_();
    return;
  }
  if (uVar16 < 0x4d000001) {
    if (uVar15 < 0x800000) {
      uVar15 = ae_s32_l_i((ulonglong)(uint)((float)uVar24 * 16777216.0));
      iVar20 = -0x18;
    }
    else {
      iVar20 = 0;
    }
    puVar17 = (undefined *)(uVar15 & 0x7fffff);
    uVar16 = (uint)puVar17 | 0x3f800000;
    iVar20 = iVar20 + ((int)uVar15 >> 0x17) + -0x7f;
    if (&DAT_001cc471 < puVar17) {
      if (puVar17 < (undefined *)0x5db3d7) {
        iStack_74 = 1;
      }
      else {
        iVar20 = iVar20 + 1;
        iStack_74 = 0;
        uVar16 = uVar16 - 0x800000;
      }
    }
    else {
      iStack_74 = 0;
    }
    iVar5 = iStack_74 * 4;
    uVar21 = ae_l32_i(uVar16);
    uVar23 = ae_l32_x(*(undefined4 *)(&DAT_002059c8 + iVar5));
    uVar2 = ae_s32_l_i(uVar21);
    uVar4 = ae_s32_l_i(uVar23);
    uVar1 = ae_s32_l_i((ulonglong)(uint)((float)uVar21 - (float)uVar23));
    uVar21 = ae_l32_i(0x3f800000);
    fVar18 = (float)uVar21;
    divf_();
    uVar23 = ae_l32_i(uVar1);
    fVar11 = (float)uVar23 * fVar18;
    fVar10 = fVar11 * fVar11;
    uVar24 = ae_l32_i(uVar4);
    uVar15 = ae_s32_l_i((ulonglong)(uint)fVar11);
    uVar22 = ae_l32_i(&DAT_00040000 +
                      ((int)uVar16 >> 1 | (uint)&DAT_20000000) + iStack_74 * 0x200000);
    uVar12 = ae_l32_i(uVar2);
    uVar21 = ae_l32_i(uVar15 & 0xfffff000);
    fVar9 = (float)uVar21;
    fVar18 = fVar18 * (((float)uVar23 - (float)uVar22 * fVar9) -
                      ((float)uVar12 - ((float)uVar22 - (float)uVar24)) * fVar9);
    fVar10 = (((((fVar10 * 0.20697501 + 0.23066075) * fVar10 + 0.27272812) * fVar10 + 0.33333334) *
               fVar10 + 0.42857143) * fVar10 + 0.6) * fVar10 * fVar10 + (fVar11 + fVar9) * fVar18;
    uVar15 = ae_s32_l_i((ulonglong)(uint)(fVar10 + fVar9 * fVar9 + 3.0));
    uVar21 = ae_l32_i(uVar15 & 0xfffff000);
    fVar8 = (float)uVar21;
    fVar18 = (fVar10 - ((fVar8 + -3.0) - fVar9 * fVar9)) * fVar11 + fVar18 * fVar8;
    uVar15 = ae_s32_l_i((ulonglong)(uint)(fVar8 * fVar9 + fVar18));
    uVar21 = ae_l32_i(uVar15 & 0xfffff000);
    fVar10 = (float)uVar21;
    uVar21 = ae_l32_x(*(undefined4 *)(&DAT_002059d0 + iVar5));
    fVar18 = (float)uVar21 +
             fVar10 * 4.7017384e-06 + (fVar18 - (fVar10 - fVar8 * fVar9)) * 0.9617967;
    uVar23 = ae_l32_x(*(undefined4 *)(&DAT_002059d8 + iVar5));
    uVar12 = float_s(iVar20,0);
    uVar15 = ae_s32_l_i((ulonglong)
                        (uint)((float)uVar12 + (float)uVar23 + fVar10 * 0.961792 + fVar18));
    uVar21 = ae_l32_i(uVar15 & 0xfffff000);
    fVar11 = (float)uVar21;
    fVar18 = fVar18 - (((fVar11 - (float)uVar12) - (float)uVar23) - fVar10 * 0.961792);
  }
  else {
    if (uVar15 < 0x3f7ffff8) {
      uVar21 = ae_l64_i(uVar23);
      uVar21 = movnez_s(uVar21,0x7f800000,(uint)puVar17 >> 0x1f);
      ae_s64_i(uVar21);
      ae_mov(uVar21);
      return;
    }
    if (0x3f800007 < uVar15) {
      if ((int)puVar17 < 1) {
        uVar21 = ae_l64_i(uVar23);
        uVar21 = movnez_s(uVar21,0x7f800000,0);
        ae_s64_i(uVar21);
        return;
      }
      uVar21 = ae_l64_i(uVar23);
      uVar21 = movnez_s(uVar21,0x7f800000,1);
      ae_s64_i(uVar21);
      ae_mov(uVar21);
      return;
    }
    uVar21 = ae_l64_i(uVar12);
    fVar10 = (float)uVar21 + -1.0;
    uVar21 = const_s(3);
    fVar18 = fVar10 * 7.0526075e-06 -
             fVar10 * fVar10 * ((float)uVar21 - fVar10 * (fVar10 * -0.25 + 0.33333334)) * 1.442695;
    uVar15 = ae_s32_l_i((ulonglong)(uint)(fVar10 * 1.442688 + fVar18));
    uVar21 = ae_l32_i(uVar15 & 0xfffff000);
    fVar11 = (float)uVar21;
    fVar18 = fVar18 - (fVar11 - fVar10 * 1.442688);
  }
  uVar23 = ae_l32_i(uVar3);
  uVar15 = ae_s32_l_i(uVar23);
  uVar21 = ae_l32_i(uVar15 & 0xfffff000);
  fVar10 = fVar11 * (float)uVar21;
  fVar18 = (float)uVar23 * fVar18 + fVar11 * ((float)uVar23 - (float)uVar21);
  fVar11 = fVar18 + fVar10;
  uVar15 = ae_s32_l_i((ulonglong)(uint)fVar11);
  uVar21 = ae_l32_i(0x3f800000);
  uVar21 = ae_mov(uVar21);
  uVar21 = movnez_s(uVar21,0xbf800000,(uint)((int)uVar19 < 0 && iVar6 == 1));
  uVar19 = uVar15 & 0x7fffffff;
  if ((int)uVar15 < 1) {
    if (0x43160000 < uVar19) {
      return;
    }
    if ((uVar19 == 0x43160000) &&
       (uVar7 = ole_s((ulonglong)(uint)fVar18,(ulonglong)(uint)(fVar11 - fVar10)), SUB21(uVar7,0)))
    {
      return;
    }
  }
  else {
    if (0x43000000 < uVar19) {
      return;
    }
    if ((uVar19 == 0x43000000) &&
       (uVar7 = olt_s((ulonglong)(uint)(fVar11 - fVar10),(ulonglong)(uint)(fVar18 + 4.2995666e-08)),
       SUB21(uVar7,0))) {
      return;
    }
  }
  uVar3 = ae_s32_l_i(uVar21);
  if (uVar19 < 0x3f000001) {
    uVar19 = ae_s32_l_i((ulonglong)(uint)fVar11);
    uVar21 = ae_l32_i(uVar19 & 0xfffff000);
    fVar8 = (float)uVar21;
    fVar18 = fVar8 * 1.4286065e-06 + (fVar18 - (fVar8 - fVar10)) * 0.6931472;
    fVar10 = fVar8 * 0.69314575 + fVar18;
    fVar11 = fVar10 * fVar10;
    uVar2 = ae_s32_l_i((ulonglong)(uint)fVar10);
    uVar1 = ae_s32_l_i((ulonglong)(uint)(fVar18 - (fVar10 - fVar8 * 0.69314575)));
    fVar10 = (fVar10 - ((((fVar11 * 4.138137e-08 + -1.6533902e-06) * fVar11 + 6.613756e-05) * fVar11
                        + -0.0027777778) * fVar11 + 0.16666667) * fVar11) * fVar10;
    divf_();
    uVar23 = ae_l32_i(uVar2);
    uVar12 = ae_l32_i(uVar1);
    uVar21 = ae_l32_i(0x3f800000);
    iVar6 = ae_s32_l_i((ulonglong)
                       (uint)((float)uVar21 -
                             ((fVar10 - ((float)uVar12 + (float)uVar12 * (float)uVar23)) -
                             (float)uVar23)));
    if (0 < iVar6 >> 0x17) goto LAB_0022a0c0;
    iVar20 = 0;
  }
  else {
    uVar15 = uVar15 + (0x800000 >> ((uVar15 >> 0x17 & 0xff) - 0x7e & 0x1f));
    uVar16 = uVar15 >> 0x17 & 0xff;
    uVar21 = ae_l32_i(uVar15 & (0x7fffff >> (uVar16 - 0x7f & 0x1f) ^ 0xffffffffU));
    fVar10 = fVar10 - (float)uVar21;
    uVar19 = ae_s32_l_i((ulonglong)(uint)(fVar10 + fVar18));
    uVar21 = ae_l32_i(uVar19 & 0xfffff000);
    fVar8 = (float)uVar21;
    fVar18 = fVar8 * 1.4286065e-06 + (fVar18 - (fVar8 - fVar10)) * 0.6931472;
    fVar10 = fVar8 * 0.69314575 + fVar18;
    fVar11 = fVar10 * fVar10;
    uVar2 = ae_s32_l_i((ulonglong)(uint)fVar10);
    iVar5 = (int)(uVar15 & 0x7fffff | 0x800000) >> (0x96 - uVar16 & 0x1f);
    iVar20 = -iVar5;
    uVar1 = ae_s32_l_i((ulonglong)(uint)(fVar18 - (fVar10 - fVar8 * 0.69314575)));
    fVar10 = (fVar10 - ((((fVar11 * 4.138137e-08 + -1.6533902e-06) * fVar11 + 6.613756e-05) * fVar11
                        + -0.0027777778) * fVar11 + 0.16666667) * fVar11) * fVar10;
    divf_();
    uVar23 = ae_l32_i(uVar2);
    uVar12 = ae_l32_i(uVar1);
    uVar21 = ae_l32_i(0x3f800000);
    iVar6 = ae_s32_l_i((ulonglong)
                       (uint)((float)uVar21 -
                             ((fVar10 - ((float)uVar12 + (float)uVar12 * (float)uVar23)) -
                             (float)uVar23)));
    iVar6 = iVar6 + iVar5 * -0x800000;
    if (0 < iVar6 >> 0x17) {
LAB_0022a0c0:
      ae_l32_i(uVar3);
      ae_l32_i(iVar6);
      return;
    }
  }
  FUN_0022b720(iVar20);
  ae_l32_i(uVar3);
  return;
}


// ===== FUN_0022a320 @ 0022a320 (725 bytes)

int FUN_0022a320(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined2 uVar7;
  float fVar8;
  undefined8 in_aed0;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined8 uVar15;
  int iVar16;
  undefined4 uStack_30;
  undefined4 local_2c [11];
  
  uVar3 = ae_s32_l_i(in_aed0);
  uVar4 = uVar3 & 0x7fffffff;
  if (uVar4 < 0x3f490fd9) {
    uVar13 = ae_s32_l_i(in_aed0);
    *param_1 = uVar13;
    uVar12 = const_s(0);
    uVar13 = ae_s32_l_i(uVar12);
    param_1[1] = uVar13;
    return 0;
  }
  fVar9 = (float)in_aed0;
  if (uVar4 < 0x4016cbe4) {
    if ((int)uVar3 < 1) {
      fVar9 = fVar9 + 1.5707855;
      if ((uVar3 & 0x7ffffff0) == 0x3fc90fd0) {
        fVar1 = fVar9 + 1.0804273e-05 + 6.0771e-11;
        uVar13 = ae_s32_l_i((ulonglong)(uint)fVar1);
        *param_1 = uVar13;
        uVar13 = ae_s32_l_i((ulonglong)(uint)(((fVar9 + 1.0804273e-05) - fVar1) + 6.0771e-11));
        param_1[1] = uVar13;
        return -1;
      }
      uVar13 = ae_s32_l_i((ulonglong)(uint)(fVar9 + 1.0804334e-05));
      *param_1 = uVar13;
      uVar13 = ae_s32_l_i((ulonglong)(uint)((fVar9 - (fVar9 + 1.0804334e-05)) + 1.0804334e-05));
      param_1[1] = uVar13;
      return -1;
    }
    fVar9 = fVar9 + -1.5707855;
    if ((uVar3 & 0x7ffffff0) == 0x3fc90fd0) {
      fVar1 = fVar9 + -1.0804273e-05 + -6.0771e-11;
      uVar13 = ae_s32_l_i((ulonglong)(uint)fVar1);
      *param_1 = uVar13;
      uVar13 = ae_s32_l_i((ulonglong)(uint)(((fVar9 + -1.0804273e-05) - fVar1) + -6.0771e-11));
      param_1[1] = uVar13;
      return 1;
    }
    uVar13 = ae_s32_l_i((ulonglong)(uint)(fVar9 + -1.0804334e-05));
    *param_1 = uVar13;
    uVar13 = ae_s32_l_i((ulonglong)(uint)((fVar9 - (fVar9 + -1.0804334e-05)) + -1.0804334e-05));
    param_1[1] = uVar13;
    return 1;
  }
  if (uVar4 < 0x43490f81) {
    FUN_0022b680();
    uVar12 = const_s(3);
    iVar16 = trunc_s((ulonglong)(uint)((float)in_aed0 * 0.6366198 + (float)uVar12),0);
    uVar15 = float_s(iVar16,0);
    uVar12 = ae_l32_i(0x3fc90f80);
    fVar11 = (float)uVar15;
    fVar1 = (float)in_aed0 - fVar11 * (float)uVar12;
    uVar12 = ae_l32_i(0x37354443);
    uVar15 = ae_mov((ulonglong)(uint)fVar1);
    fVar9 = fVar11 * (float)uVar12;
    fVar10 = (float)uVar15;
    if ((iVar16 < 0x20) && (FLOAT_ARRAY_00205a1c[iVar16] != (float)(uVar3 & 0x7fffff00))) {
      fVar8 = fVar1 - fVar9;
      uVar13 = ae_s32_l_i((ulonglong)(uint)fVar8);
      *param_1 = uVar13;
    }
    else {
      fVar8 = fVar1 - fVar9;
      uVar4 = ae_s32_l_i((ulonglong)(uint)fVar8);
      uVar14 = uVar3 >> 0x17 & 0xff;
      uVar13 = ae_s32_l_i((ulonglong)(uint)fVar8);
      *param_1 = uVar13;
      if (8 < (int)(uVar14 - (uVar4 >> 0x17 & 0xff))) {
        uVar12 = ae_l32_i(0x37354400);
        fVar9 = fVar11 * (float)uVar12;
        fVar2 = fVar1 - fVar9;
        uVar12 = ae_l32_i(0x2e85a308);
        fVar9 = fVar11 * (float)uVar12 - ((fVar1 - fVar2) - fVar9);
        fVar8 = fVar2 - fVar9;
        uVar4 = ae_s32_l_i((ulonglong)(uint)fVar8);
        uVar13 = ae_s32_l_i((ulonglong)(uint)fVar8);
        *param_1 = uVar13;
        uVar12 = ae_mov((ulonglong)(uint)fVar2);
        fVar10 = (float)uVar12;
        if (0x19 < (int)(uVar14 - (uVar4 >> 0x17 & 0xff))) {
          fVar10 = fVar2 - fVar11 * 6.0770944e-11;
          fVar9 = fVar11 * 6.123234e-17 - ((fVar2 - fVar10) - fVar11 * 6.0770944e-11);
          fVar8 = fVar10 - fVar9;
          uVar13 = ae_s32_l_i((ulonglong)(uint)fVar8);
          *param_1 = uVar13;
        }
      }
    }
    fVar9 = (fVar10 - fVar8) - fVar9;
    uVar13 = ae_s32_l_i((ulonglong)(uint)fVar9);
    param_1[1] = uVar13;
    if ((int)uVar3 < 0) {
      uVar13 = ae_s32_l_i((ulonglong)(uint)-fVar8);
      *param_1 = uVar13;
      uVar13 = ae_s32_l_i((ulonglong)(uint)-fVar9);
      param_1[1] = uVar13;
      return -iVar16;
    }
    return iVar16;
  }
  if (0x7f7fffff < uVar4) {
    uVar13 = ae_s32_l_i((ulonglong)(uint)(fVar9 - fVar9));
    param_1[1] = uVar13;
    uVar13 = ae_s32_l_i((ulonglong)(uint)(fVar9 - fVar9));
    *param_1 = uVar13;
    return 0;
  }
  iVar6 = (uVar3 >> 0x17 & 0xff) - 0x86;
  uVar12 = ae_l32_i(uVar4 + iVar6 * -0x800000);
  uVar13 = trunc_s(uVar12,0);
  uVar15 = float_s(uVar13,0);
  fVar9 = ((float)uVar12 - (float)uVar15) * 256.0;
  uVar13 = trunc_s((ulonglong)(uint)fVar9,0);
  uVar12 = float_s(uVar13,0);
  uStack_30 = ae_s32_l_i(uVar15);
  local_2c[0] = ae_s32_l_i(uVar12);
  local_2c[1] = ae_s32_l_i((ulonglong)(uint)((fVar9 - (float)uVar12) * 256.0));
  puVar5 = local_2c;
  uVar12 = ae_l32_i(local_2c[1]);
  uVar15 = const_s(0);
  uVar7 = oeq_s(uVar12,uVar15);
  iVar16 = 0;
  if (SUB21(uVar7,0)) {
    do {
      uVar12 = ae_l32_ip(*puVar5);
      puVar5 = puVar5 + -1;
      uVar7 = oeq_s(uVar12,uVar15);
      iVar16 = iVar16 + 1;
    } while (SUB21(uVar7,0));
  }
  iVar16 = FUN_0022a6f0(&uStack_30,param_1,iVar6,3 - iVar16,2,two_over_pi);
  if ((int)uVar3 < 0) {
    uVar12 = ae_l32_i(*param_1);
    uVar15 = ae_l32_i(param_1[1]);
    uVar13 = ae_s32_l_i((ulonglong)(uint)-(float)uVar12);
    *param_1 = uVar13;
    uVar13 = ae_s32_l_i((ulonglong)(uint)-(float)uVar15);
    param_1[1] = uVar13;
    return -iVar16;
  }
  return iVar16;
}


// ===== FUN_0022a610 @ 0022a610 (218 bytes)

undefined4 FUN_0022a610(void)

{
  undefined4 uVar1;
  undefined8 in_aed0;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar2 = ae_s32_l_i(in_aed0);
  uVar2 = uVar2 & 0x7fffffff;
  uVar4 = const_s(1);
  if ((uVar2 < 0x32000000) && (iVar3 = trunc_s(in_aed0,0), iVar3 == 0)) {
    ae_mov(uVar4);
    return 0x31ffffff;
  }
  uVar1 = 0xad47d74e;
  const_s(3);
  if (uVar2 < 0x3e99999a) {
    return uVar1;
  }
  if (0x3f480000 < uVar2) {
    return uVar1;
  }
  ae_l32_i(uVar2 - 0x1000000);
  return uVar1;
}


// ===== FUN_0022a6f0 @ 0022a6f0 (3349 bytes)

/* WARNING: Removing unreachable block (ram,0x0022ab47) */
/* WARNING: Type propagation algorithm not settling */

uint FUN_0022a6f0(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4,int param_5,
                 int param_6)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined2 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  ulonglong uVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined8 uVar24;
  uint uVar25;
  undefined4 uVar26;
  uint uVar27;
  undefined4 uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  ulonglong uVar32;
  int iVar33;
  int iVar34;
  float fVar35;
  float fVar36;
  int iVar37;
  uint *puVar38;
  uint uVar39;
  undefined1 *puVar40;
  uint uVar41;
  undefined4 *puVar42;
  undefined4 *puVar43;
  undefined8 uVar44;
  undefined8 uVar45;
  undefined8 uVar46;
  undefined8 uVar47;
  undefined1 auStack_2d4 [4];
  undefined1 auStack_2d0 [348];
  undefined4 uStack_174;
  undefined4 local_170 [18];
  undefined4 auStack_128 [21];
  uint auStack_d4 [25];
  int iStack_70;
  undefined4 *puStack_6c;
  undefined1 *puStack_68;
  undefined1 *puStack_64;
  undefined4 *puStack_60;
  int iStack_5c;
  uint uStack_58;
  uint uStack_54;
  undefined4 *puStack_50;
  uint uStack_4c;
  undefined4 *puStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  uint uStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  
  puStack_50 = param_2;
  iStack_30 = param_5;
  puStack_28 = param_1;
  iStack_44 = param_6;
  iVar33 = param_3 + 4;
  if (-1 < param_3 + -3) {
    iVar33 = param_3 + -3;
  }
  iStack_5c = 0;
  if (0 < iVar33 >> 3) {
    iStack_5c = iVar33 >> 3;
  }
  uVar25 = *(uint *)(&DAT_00205de0 + param_5 * 4);
  param_3 = param_3 + iStack_5c * -8;
  iStack_3c = param_3;
  iVar33 = param_3 + -8;
  iStack_40 = iVar33;
  iVar34 = uVar25 + param_4;
  if ((0 < iVar34) && ((iVar34 == 1 || (0 < iVar34)))) {
    if (iStack_5c - param_4 < -1) {
      uVar29 = ae_l32_i(0);
    }
    else {
      uVar29 = float_s(*(undefined4 *)((iStack_5c - param_4) * 4 + param_6 + 4),0);
    }
    local_170[0] = ae_s32_l_ip(uVar29);
  }
  puVar7 = auStack_128 + 2;
  if ((int)uVar25 < 3) {
    iVar34 = 0;
    if ((int)uVar25 < 0) goto LAB_0022a8d9;
  }
  else {
    puVar42 = (undefined4 *)((int)local_170 + param_4 * 4);
    puVar9 = puVar7 + (uVar25 - 3);
    do {
      uVar29 = ae_l32_i(0);
      uVar26 = ae_s32_l_i(uVar29);
      *puVar7 = uVar26;
      uVar26 = ae_s32_l_i(uVar29);
      puVar7[1] = uVar26;
      uVar26 = ae_s32_l_i(uVar29);
      puVar7[2] = uVar26;
      uVar26 = ae_s32_l_i(uVar29);
      puVar7[3] = uVar26;
      if (0 < param_4) {
        uVar24 = ae_l32_i(puVar42[-1]);
        uVar29 = ae_l32_ip(*puStack_28);
        uVar30 = ae_l32_ip(*puVar42);
        fVar20 = (float)uVar29;
        uVar31 = ae_l32_i(puVar42[1]);
        uVar29 = ae_l32_i(puVar42[2]);
        uVar32 = ae_l32_i(0);
        fVar19 = fVar20 * (float)uVar29;
        fVar22 = fVar20 * (float)uVar31;
        fVar23 = (float)uVar32;
        fVar13 = fVar23 + (float)uVar24 * fVar20;
        uVar29 = ae_mov(uVar32);
        fVar17 = (float)uVar29;
        fVar20 = fVar23 + fVar20 * (float)uVar30;
        if (1 < param_4) {
          uVar29 = ae_l32_ip(puStack_28[1]);
          uVar24 = ae_l32_i(puVar42[-2]);
          uVar30 = ae_l32_ip(puVar42[-1]);
          iVar34 = param_4 + -2;
          uVar31 = ae_l32_i(*puVar42);
          fVar35 = (float)uVar31;
          fVar12 = (float)uVar29;
          fVar1 = (float)uVar24 * fVar12;
          uVar29 = ae_l32_i(puVar42[1]);
          fVar36 = (float)uVar29;
          fVar2 = fVar12 * (float)uVar30;
          fVar18 = fVar19;
          fVar21 = fVar22;
          fVar14 = fVar1;
          fVar15 = fVar2;
          if ((0 < iVar34) && ((iVar34 == 1 || (0 < iVar34)))) {
            uVar29 = ae_l32_i(puVar42[-3]);
            uVar31 = ae_l32_ip(puVar42[-2]);
            fVar18 = fVar12 * fVar36;
            fVar17 = fVar17 + fVar19;
            uVar24 = ae_l32_ip(puStack_28[2]);
            fVar21 = fVar12 * fVar35;
            uVar32 = (ulonglong)(uint)(fVar23 + fVar22);
            uVar30 = ae_l32_i(puVar42[-1]);
            uVar44 = ae_l32_i(*puVar42);
            fVar12 = (float)uVar24;
            fVar15 = fVar12 * (float)uVar31;
            fVar20 = fVar20 + fVar2;
            fVar35 = (float)uVar30;
            fVar36 = (float)uVar44;
            fVar14 = (float)uVar29 * fVar12;
            fVar13 = fVar13 + fVar1;
          }
          fVar13 = fVar13 + fVar14;
          fVar20 = fVar20 + fVar15;
          uVar32 = (ulonglong)(uint)((float)uVar32 + fVar21);
          fVar17 = fVar17 + fVar18;
          fVar19 = fVar12 * fVar36;
          fVar22 = fVar12 * fVar35;
        }
        uVar26 = ae_s32_l_i((ulonglong)(uint)fVar20);
        puVar7[1] = uVar26;
        uVar26 = ae_s32_l_i((ulonglong)(uint)fVar13);
        *puVar7 = uVar26;
        uVar26 = ae_s32_l_i((ulonglong)(uint)((float)uVar32 + fVar22));
        puVar7[2] = uVar26;
        uVar26 = ae_s32_l_i((ulonglong)(uint)(fVar17 + fVar19));
        puVar7[3] = uVar26;
      }
      puVar7 = puVar7 + 4;
      puVar42 = puVar42 + 4;
    } while (puVar7 <= puVar9);
    iVar34 = ((int)(uVar25 + 1) >> 2) << 2;
    if ((int)uVar25 < iVar34) goto LAB_0022a8d9;
  }
  puVar7 = auStack_128 + iVar34 + 2;
  iVar34 = (int)local_170 + (iVar34 + param_4) * 4;
  do {
    uVar29 = ae_l32_i(0);
    uVar26 = ae_s32_l_i(uVar29);
    *puVar7 = uVar26;
    if (0 < param_4) {
      uVar29 = ae_l32_ip(*(undefined4 *)(iVar34 + -4));
      uVar24 = ae_l32_ip(*puStack_28);
      iVar37 = param_4 + -1;
      uVar30 = ae_l32_i(0);
      fVar19 = (float)uVar29 * (float)uVar24;
      fVar22 = (float)uVar30;
      fVar13 = fVar19;
      if ((0 < iVar37) && ((iVar37 == 1 || (0 < iVar37)))) {
        uVar29 = ae_l32_ip(puStack_28[1]);
        uVar24 = ae_l32_ip(*(undefined4 *)(iVar34 + -8));
        fVar13 = (float)uVar24 * (float)uVar29;
        fVar22 = fVar22 + fVar19;
      }
      uVar26 = ae_s32_l_i((ulonglong)(uint)(fVar22 + fVar13));
      *puVar7 = uVar26;
    }
    puVar7 = puVar7 + 1;
    iVar34 = iVar34 + 4;
  } while (puVar7 != auStack_128 + uVar25 + 3);
LAB_0022a8d9:
  uStack_54 = 7 - iVar33;
  uStack_58 = 8 - iVar33;
  puStack_68 = auStack_2d0 + (uVar25 - 1) * 4;
  puStack_64 = auStack_2d0 + uVar25 * 4;
  puVar38 = auStack_d4 + 1;
  uVar41 = uVar25;
LAB_0022a90b:
  iStack_38 = uVar41 << 2;
  uVar29 = ae_l32_i(auStack_128[uVar41 + 2]);
  fVar13 = (float)uVar29;
  if (0 < (int)uVar41) {
    puVar7 = auStack_128 + uVar41 + 1;
    puVar5 = auStack_d4 + 1;
    if ((uVar41 & 1) != 0) {
      uVar29 = ae_l32_i(0x3b800000);
      uVar26 = trunc_s((ulonglong)(uint)((float)uVar29 * fVar13),0);
      uVar24 = float_s(uVar26,0);
      uVar29 = ae_l32_i(0x43800000);
      auStack_d4[1] = trunc_s((ulonglong)(uint)(fVar13 - (float)uVar24 * (float)uVar29),0);
      uVar29 = ae_l32_ip(*puVar7);
      puVar7 = auStack_128 + uVar41;
      puVar5 = auStack_d4 + 2;
      fVar13 = (float)uVar24 + (float)uVar29;
    }
    if ((int)uVar41 >> 1 != 0) {
      uVar29 = ae_l32_i(0x3b800000);
      fVar20 = (float)uVar29;
      uVar26 = trunc_s((ulonglong)(uint)(fVar20 * fVar13),0);
      uVar24 = float_s(uVar26,0);
      uVar29 = ae_l32_ip(*puVar7);
      uVar30 = ae_l32_i(0x43800000);
      fVar19 = (float)uVar24 + (float)uVar29;
      fVar17 = (float)uVar30;
      uVar26 = trunc_s((ulonglong)(uint)(fVar20 * fVar19),0);
      uVar27 = trunc_s((ulonglong)(uint)(fVar13 - (float)uVar24 * fVar17),0);
      uVar24 = float_s(uVar26,0);
      uVar29 = ae_l32_i(puVar7[-1]);
      *puVar5 = uVar27;
      fVar13 = (float)uVar24 + (float)uVar29;
      fVar22 = (float)uVar24 * fVar17;
      if (0 < ((int)uVar41 >> 1) + -1) {
        uVar29 = ae_l32_ip(puVar7[-2]);
        uVar30 = ae_l32_i(puVar7[-3]);
        uVar26 = trunc_s((ulonglong)(uint)(fVar20 * fVar13),0);
        uVar27 = trunc_s((ulonglong)(uint)(fVar19 - fVar22),0);
        uVar24 = float_s(uVar26,0);
        puVar5[1] = uVar27;
        puVar5 = puVar5 + 2;
        fVar19 = (float)uVar24 + (float)uVar29;
        uVar26 = trunc_s((ulonglong)(uint)(fVar20 * fVar19),0);
        uVar27 = trunc_s((ulonglong)(uint)(fVar13 - (float)uVar24 * fVar17),0);
        uVar29 = float_s(uVar26,0);
        *puVar5 = uVar27;
        fVar22 = (float)uVar29 * fVar17;
        fVar13 = (float)uVar29 + (float)uVar30;
      }
      uVar27 = trunc_s((ulonglong)(uint)(fVar19 - fVar22),0);
      puVar5[1] = uVar27;
    }
  }
  FUN_0022b720(iVar33);
  uVar29 = ae_l32_i(0x3e000000);
  uVar24 = fifloor_s((ulonglong)(uint)(fVar13 * (float)uVar29));
  uVar29 = ae_l32_i(0xc1000000);
  fVar13 = fVar13 + (float)uVar24 * (float)uVar29;
  uStack_2c = trunc_s((ulonglong)(uint)fVar13,0);
  uVar29 = float_s(uStack_2c,0);
  fVar13 = fVar13 - (float)uVar29;
  uVar32 = ae_mov((ulonglong)(uint)fVar13);
  if (iStack_3c < 9) {
    if (iStack_3c == 8) {
      iStack_34 = *(int *)((int)auStack_d4 + iStack_38) >> 8;
    }
    else {
      uVar29 = ae_l32_i(0x3f000000);
      uVar11 = ole_s(uVar29,(ulonglong)(uint)fVar13);
      iStack_34 = (uint)(byte)uVar11 << 1;
    }
  }
  else {
    iVar34 = *(int *)((int)auStack_d4 + iStack_38) >> (uStack_58 & 0x1f);
    iVar37 = *(int *)((int)auStack_d4 + iStack_38) - (iVar34 << 0x20 - (0x20 - (uStack_58 & 0x1f)));
    uStack_2c = iVar34 + uStack_2c;
    uVar27 = uStack_54 & 0x1f;
    *(int *)((int)auStack_d4 + iStack_38) = iVar37;
    iStack_34 = iVar37 >> uVar27;
  }
  if (0 < iStack_34) {
    uStack_2c = uStack_2c + 1;
    if ((int)uVar41 < 1) {
      if (0 < iVar33) {
        if (iVar33 == 1) {
          *(uint *)((int)auStack_d4 + iStack_38) = *(uint *)((int)auStack_d4 + iStack_38) & 0x7f;
        }
        else if (iVar33 == 2) {
          *(uint *)((int)auStack_d4 + iStack_38) = *(uint *)((int)auStack_d4 + iStack_38) & 0x3f;
        }
      }
      if (iStack_34 == 2) {
        uVar29 = ae_l32_i(0x3f800000);
        uVar32 = (ulonglong)(uint)((float)uVar29 - fVar13);
      }
    }
    else {
      bVar8 = false;
      if ((0 < (int)uVar41) &&
         (((uVar41 == 1 || (bVar8 = false, 0 < (int)uVar41)) && (bVar8 = auStack_d4[1] != 0, bVar8))
         )) {
        auStack_d4[1] = 0x100 - auStack_d4[1];
      }
      if (0 < iVar33) {
        if (iVar33 == 1) {
          *(uint *)((int)auStack_d4 + iStack_38) = *(uint *)((int)auStack_d4 + iStack_38) & 0x7f;
        }
        else if (iVar33 == 2) {
          *(uint *)((int)auStack_d4 + iStack_38) = *(uint *)((int)auStack_d4 + iStack_38) & 0x3f;
        }
      }
      if (iStack_34 == 2) {
        uVar29 = ae_l32_i(0x3f800000);
        uVar32 = (ulonglong)(uint)((float)uVar29 - fVar13);
        uStack_24 = ae_s32_l_i(uVar32);
        if (bVar8) {
          uVar29 = ae_l32_i(0x3f800000);
          fVar13 = (float)uVar29;
          FUN_0022b720(iVar33);
          uVar29 = ae_l32_i(uStack_24);
          uVar32 = (ulonglong)(uint)((float)uVar29 - fVar13);
        }
      }
    }
  }
  iVar34 = iStack_38;
  uVar29 = ae_l32_i(0);
  uVar11 = oeq_s(uVar32,uVar29);
  if (!SUB21(uVar11,0)) {
LAB_0022ac68:
    uVar29 = ae_l32_i(0);
    uVar11 = oeq_s(uVar32,uVar29);
    puVar40 = auStack_2d0 + iStack_38;
    if (SUB21(uVar11,0)) {
      iStack_40 = param_3 + -0x10;
      iVar33 = 0;
      if (*(int *)((int)auStack_d4 + iStack_38) == 0) {
        do {
          piVar3 = (int *)(puVar40 + 0x1f8);
          iVar33 = iVar33 + 1;
          uVar41 = uVar41 - 1;
          puVar40 = puVar40 + -4;
        } while (*piVar3 == 0);
        iStack_40 = param_3 + -0x10 + iVar33 * -8;
      }
      uVar41 = uVar41 - 1;
    }
    else {
      FUN_0022b720(8 - iStack_3c);
      uVar29 = ae_l32_i(0x43800000);
      uVar11 = ole_s(uVar29,uVar32);
      if (SUB21(uVar11,0)) {
        uVar29 = ae_l32_i(0x3b800000);
        uVar26 = trunc_s((ulonglong)(uint)((float)uVar32 * (float)uVar29),0);
        uVar24 = float_s(uVar26,0);
        uVar29 = ae_l32_i(0x43800000);
        iStack_40 = iStack_3c;
        uVar26 = trunc_s(uVar24,0);
        uVar28 = trunc_s((ulonglong)(uint)((float)uVar32 - (float)uVar24 * (float)uVar29),0);
        *(undefined4 *)((int)auStack_d4 + iVar34 + 8) = uVar26;
        *(undefined4 *)((int)auStack_d4 + iVar34 + 4) = uVar28;
        uVar41 = uVar41 + 1;
      }
      else {
        uVar26 = trunc_s(uVar32,0);
        *(undefined4 *)((int)auStack_d4 + iVar34 + 4) = uVar26;
      }
    }
    uVar29 = ae_l32_i(0x3f800000);
    fVar13 = (float)uVar29;
    FUN_0022b720(iStack_40);
    if (-1 < (int)uVar41) {
      uVar29 = float_s(auStack_d4[uVar41 + 1],0);
      puVar42 = auStack_128 + uVar41 + 2;
      uVar24 = ae_l32_i(0x3b800000);
      uVar32 = (ulonglong)(uint)((float)uVar29 * fVar13);
      puVar7 = puVar42;
      if ((0 < (int)uVar41) && ((uVar41 == 1 || (0 < (int)uVar41)))) {
        uVar29 = float_s(auStack_d4[uVar41],0);
        uVar26 = ae_s32_l_ip(uVar32);
        *puVar42 = uVar26;
        puVar7 = auStack_128 + uVar41 + 1;
        uVar32 = (ulonglong)(uint)((float)uVar29 * fVar13 * (float)uVar24);
      }
      puVar5 = auStack_d4 + 1;
      uVar26 = ae_s32_l_ip(uVar32);
      *puVar7 = uVar26;
      puVar7 = &DAT_00205df0;
      do {
        uVar32 = ae_l32_i(0);
        iVar33 = 0;
        if ((-1 < (int)uVar25) && (puVar38 <= puVar5)) {
          puVar4 = &DAT_00205df0;
          puVar9 = puVar42;
          do {
            uVar29 = ae_l32_ip(*puVar9);
            puVar9 = puVar9 + 1;
            uVar24 = ae_l32_ip(*puVar4);
            puVar4 = puVar4 + 1;
            iVar33 = iVar33 + 1;
            uVar32 = (ulonglong)(uint)((float)uVar32 + (float)uVar24 * (float)uVar29);
            if ((int)uVar25 < iVar33) break;
          } while (puVar4 <= puVar7);
        }
        puVar42 = puVar42 + -1;
        uVar27 = ae_s32_l_i(uVar32);
        *puVar5 = uVar27;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      } while (puVar5 != puVar38 + uVar41 + 1);
    }
    if (iStack_30 == 0) {
      iVar33 = uVar41 + 1;
      uVar32 = ae_l32_i(0);
      if ((0 < iVar33) && ((iVar33 == 1 || (0 < iVar33)))) {
        uVar29 = ae_l32_ip(puVar38[uVar41]);
        uVar32 = (ulonglong)(uint)((float)uVar29 + (float)uVar32);
      }
      uVar25 = uStack_2c;
      if (iStack_34 != 0) {
        uVar25 = 1;
      }
      uVar29 = movnez_s(uVar32,(ulonglong)(uint)-(float)uVar32,uVar25);
      uVar26 = ae_s32_l_i(uVar29);
      *puStack_50 = uVar26;
      return uStack_2c & 7;
    }
    if ((iStack_30 == 1) || (iStack_30 == 2)) {
      uVar32 = ae_l32_i(0);
      if (0 < (int)(uVar41 + 1)) {
        uVar29 = ae_l32_ip(puVar38[uVar41]);
        uVar32 = (ulonglong)(uint)((float)uVar29 + (float)uVar32);
      }
      puVar7 = puStack_50;
      if (iStack_34 != 0) {
        puVar7 = (undefined4 *)0x1;
      }
      uVar29 = ae_mov(uVar32);
      uVar29 = movnez_s(uVar29,(ulonglong)(uint)-(float)uVar32,puVar7);
      uVar26 = ae_s32_l_i(uVar29);
      *puStack_50 = uVar26;
      uVar29 = ae_l32_i(auStack_d4[1]);
      fVar13 = (float)uVar29 - (float)uVar32;
      if (0 < (int)uVar41) {
        uVar29 = ae_l32_ip(auStack_d4[2]);
        fVar13 = (float)uVar29 + fVar13;
      }
      uVar29 = movnez_s((ulonglong)(uint)fVar13,(ulonglong)(uint)-fVar13,puVar7);
      uVar26 = ae_s32_l_i(uVar29);
      puStack_50[1] = uVar26;
      return uStack_2c & 7;
    }
    if (iStack_30 != 3) {
      return uStack_2c & 7;
    }
    if (0 < (int)uVar41) {
      uVar29 = ae_l32_i(puVar38[uVar41]);
      uVar24 = ae_l32_i(auStack_d4[uVar41]);
      fVar13 = (float)uVar24 + (float)uVar29;
      uVar25 = ae_s32_l_i((ulonglong)(uint)fVar13);
      auStack_d4[uVar41] = uVar25;
      uVar25 = ae_s32_l_i((ulonglong)(uint)((float)uVar29 + ((float)uVar24 - fVar13)));
      puVar38[uVar41] = uVar25;
    }
    if ((int)uVar41 < 2) {
      uVar32 = ae_l32_i(0);
    }
    else {
      uVar25 = uVar41 - 1;
      uVar32 = ae_l32_i(0);
      uVar27 = uVar25 & 3;
      puVar5 = puVar38 + uVar25;
      if ((uVar27 != 0) && ((uVar27 == 1 || (uVar27 != 0)))) {
        uVar29 = ae_l32_i(*puVar5);
        uVar24 = ae_l32_i(auStack_d4[uVar25]);
        fVar13 = (float)uVar24 + (float)uVar29;
        fVar22 = (float)uVar29 + ((float)uVar24 - fVar13);
        uVar29 = ae_l32_i(auStack_d4[uVar41 + 1]);
        fVar19 = (float)uVar29 + fVar22;
        uVar27 = ae_s32_l_i((ulonglong)(uint)fVar13);
        auStack_d4[uVar25] = uVar27;
        uVar27 = ae_s32_l_i((ulonglong)(uint)((float)uVar29 + (fVar22 - fVar19)));
        auStack_d4[uVar41 + 1] = uVar27;
        uVar27 = ae_s32_l_ip((ulonglong)(uint)fVar19);
        *puVar5 = uVar27;
        puVar5 = auStack_d4 + uVar25;
      }
      if ((int)uVar25 >> 2 != 0) {
        uVar29 = ae_l32_i(*puVar5);
        uVar24 = ae_l32_i(puVar5[-1]);
        fVar13 = (float)uVar24 + (float)uVar29;
        fVar19 = (float)uVar29 + ((float)uVar24 - fVar13);
        uVar29 = ae_l32_i(puVar5[1]);
        fVar17 = (float)uVar29 + fVar19;
        uVar27 = ae_s32_l_i((ulonglong)(uint)fVar13);
        puVar5[-1] = uVar27;
        uVar27 = ae_s32_l_ip((ulonglong)(uint)fVar17);
        *puVar5 = uVar27;
        puVar6 = puVar5 + -4;
        uVar24 = ae_l32_i(puVar5[-1]);
        uVar44 = ae_l32_i(puVar5[-2]);
        fVar13 = (float)uVar44 + (float)uVar24;
        uVar27 = ae_s32_l_i((ulonglong)(uint)fVar13);
        puVar5[-2] = uVar27;
        uVar30 = ae_l32_i(puVar5[-3]);
        uVar45 = ae_l32_i(puVar5[-2]);
        fVar20 = (float)uVar30 + (float)uVar45;
        uVar27 = ae_s32_l_i((ulonglong)(uint)fVar20);
        puVar5[-3] = uVar27;
        uVar31 = ae_l32_i(*puVar6);
        uVar46 = ae_l32_i(puVar5[-3]);
        fVar23 = (float)uVar46;
        fVar22 = (float)uVar31 + fVar23;
        uVar16 = (ulonglong)(uint)((float)uVar29 + (fVar19 - fVar17));
        uVar27 = ae_s32_l_i((ulonglong)(uint)fVar22);
        *puVar6 = uVar27;
        fVar13 = (float)uVar24 + ((float)uVar44 - fVar13);
        fVar19 = (float)uVar45 + ((float)uVar30 - fVar20);
        uVar29 = ae_l32_i(*puVar5);
        fVar22 = (float)uVar31 - fVar22;
        fVar17 = (float)uVar29;
        if (0 < ((int)uVar25 >> 2) + -1) {
          uVar29 = ae_l32_i(*puVar6);
          uVar30 = ae_l32_i(puVar5[-5]);
          fVar1 = (float)uVar30 + (float)uVar29;
          uVar24 = ae_l32_i(puVar5[-6]);
          uVar31 = ae_l32_i(puVar5[-7]);
          fVar22 = fVar23 + fVar22;
          uVar27 = ae_s32_l_i((ulonglong)(uint)(fVar17 + fVar13));
          puVar5[-1] = uVar27;
          uVar44 = ae_l32_i(puVar5[-8]);
          uVar27 = ae_s32_l_i((ulonglong)(uint)fVar1);
          puVar5[-5] = uVar27;
          uVar45 = ae_l32_i(puVar5[-1]);
          uVar27 = ae_s32_l_i(uVar16);
          puVar5[1] = uVar27;
          uVar46 = ae_l32_i(puVar5[-5]);
          fVar20 = (float)uVar45 + fVar19;
          fVar23 = (float)uVar24 + (float)uVar46;
          fVar18 = (float)uVar29 + ((float)uVar30 - fVar1);
          uVar27 = ae_s32_l_i((ulonglong)(uint)fVar20);
          puVar5[-2] = uVar27;
          uVar27 = ae_s32_l_i((ulonglong)(uint)fVar23);
          puVar5[-6] = uVar27;
          uVar30 = ae_l32_i(puVar5[-2]);
          uVar27 = ae_s32_l_i((ulonglong)(uint)(fVar17 + (fVar13 - (fVar17 + fVar13))));
          *puVar5 = uVar27;
          uVar47 = ae_l32_i(puVar5[-6]);
          fVar17 = (float)uVar30 + fVar22;
          fVar21 = (float)uVar31 + (float)uVar47;
          fVar13 = (float)uVar46 + ((float)uVar24 - fVar23);
          uVar27 = ae_s32_l_i((ulonglong)(uint)fVar17);
          puVar5[-3] = uVar27;
          uVar29 = ae_l32_i(puVar5[-3]);
          uVar27 = ae_s32_l_i((ulonglong)(uint)fVar21);
          puVar5[-7] = uVar27;
          fVar1 = (float)uVar29 + fVar18;
          uVar27 = ae_s32_l_i((ulonglong)(uint)((float)uVar45 + (fVar19 - fVar20)));
          puVar5[-1] = uVar27;
          uVar24 = ae_l32_i(puVar5[-7]);
          fVar23 = (float)uVar24;
          fVar20 = (float)uVar44 + fVar23;
          fVar19 = (float)uVar47 + ((float)uVar31 - fVar21);
          uVar27 = ae_s32_l_i((ulonglong)(uint)((float)uVar30 + (fVar22 - fVar17)));
          puVar5[-2] = uVar27;
          uVar27 = ae_s32_l_ip((ulonglong)(uint)fVar1);
          *puVar6 = uVar27;
          puVar6 = puVar5 + -8;
          fVar22 = (float)uVar44 - fVar20;
          uVar27 = ae_s32_l_i((ulonglong)(uint)fVar20);
          *puVar6 = uVar27;
          uVar24 = ae_l32_i(puVar5[-4]);
          uVar16 = (ulonglong)(uint)((float)uVar29 + (fVar18 - fVar1));
          fVar17 = (float)uVar24;
        }
        uVar27 = ae_s32_l_i((ulonglong)(uint)(fVar17 + fVar13));
        puVar6[3] = uVar27;
        uVar24 = ae_l32_i(puVar6[3]);
        fVar20 = (float)uVar24 + fVar19;
        uVar27 = ae_s32_l_i((ulonglong)(uint)fVar20);
        puVar6[2] = uVar27;
        uVar29 = ae_l32_i(puVar6[2]);
        fVar1 = (float)uVar29 + fVar23 + fVar22;
        uVar27 = ae_s32_l_i(uVar16);
        puVar6[5] = uVar27;
        uVar27 = ae_s32_l_i((ulonglong)(uint)(fVar17 + (fVar13 - (fVar17 + fVar13))));
        puVar6[4] = uVar27;
        uVar27 = ae_s32_l_i((ulonglong)(uint)fVar1);
        puVar6[1] = uVar27;
        uVar27 = ae_s32_l_i((ulonglong)(uint)((float)uVar24 + (fVar19 - fVar20)));
        puVar6[3] = uVar27;
        uVar27 = ae_s32_l_i((ulonglong)(uint)((float)uVar29 + ((fVar23 + fVar22) - fVar1)));
        puVar6[2] = uVar27;
      }
      if ((0 < (int)uVar25) && ((uVar25 == 1 || (0 < (int)uVar25)))) {
        uVar29 = ae_l32_ip(puVar38[uVar41]);
        uVar32 = (ulonglong)(uint)((float)uVar29 + (float)uVar32);
      }
    }
    uVar29 = ae_l32_i(auStack_d4[2]);
    uVar24 = ae_l32_i(auStack_d4[1]);
    if (iStack_34 == 0) {
      uVar26 = ae_s32_l_i(uVar24);
      *puStack_50 = uVar26;
      uVar26 = ae_s32_l_i(uVar29);
      puStack_50[1] = uVar26;
      uVar26 = ae_s32_l_i(uVar32);
      puStack_50[2] = uVar26;
      return uStack_2c & 7;
    }
    uVar26 = ae_s32_l_i((ulonglong)(uint)-(float)uVar24);
    *puStack_50 = uVar26;
    uVar26 = ae_s32_l_i((ulonglong)(uint)-(float)uVar29);
    puStack_50[1] = uVar26;
    uVar26 = ae_s32_l_i((ulonglong)(uint)-(float)uVar32);
    puStack_50[2] = uVar26;
    return uStack_2c & 7;
  }
  uVar27 = uVar41 - uVar25;
  if (0 < (int)uVar27) {
    uVar39 = uVar27 & 7;
    puVar40 = auStack_2d0 + iStack_38;
    uVar10 = 0;
    if ((uVar39 != 0) && ((uVar39 == 1 || (uVar10 = 0, uVar39 != 0)))) {
      uVar10 = *(uint *)((int)auStack_d4 + iStack_38);
      puVar40 = auStack_2d4 + iStack_38;
    }
    if ((int)uVar27 >> 3 != 0) {
      iVar37 = ((int)uVar27 >> 3) + -1;
      uVar39 = *(uint *)(puVar40 + 0x1e4);
      uVar27 = *(uint *)(puVar40 + 0x1e8) |
               *(uint *)(puVar40 + 0x1ec) |
               *(uint *)(puVar40 + 0x1f0) |
               *(uint *)(puVar40 + 500) |
               *(uint *)(puVar40 + 0x1f8) | *(uint *)(puVar40 + 0x1fc) | uVar10;
      uVar10 = *(uint *)(puVar40 + 0x1e0);
      if ((0 < iVar37) && ((iVar37 == 1 || (0 < iVar37)))) {
        uVar27 = uVar10 | uVar39 | uVar27;
        uVar39 = *(uint *)(puVar40 + 0x1c4);
        uVar10 = *(uint *)(puVar40 + 0x1c0);
        uVar27 = *(uint *)(puVar40 + 0x1c8) |
                 *(uint *)(puVar40 + 0x1cc) |
                 *(uint *)(puVar40 + 0x1d0) |
                 *(uint *)(puVar40 + 0x1d4) |
                 *(uint *)(puVar40 + 0x1d8) | *(uint *)(puVar40 + 0x1dc) | uVar27;
      }
      uVar10 = uVar10 | uVar39 | uVar27;
    }
    if (uVar10 != 0) goto LAB_0022ac68;
  }
  uVar27 = uVar41 + 1;
  if (*(int *)(puStack_64 + 0x1fc) == 0) goto code_r0x0022ac37;
  uStack_4c = uVar27;
  goto LAB_0022afca;
code_r0x0022ac37:
  iVar34 = 1;
  puVar40 = puStack_68;
  do {
    piVar3 = (int *)(puVar40 + 0x1fc);
    iVar34 = iVar34 + 1;
    puVar40 = puVar40 + -4;
  } while (*piVar3 == 0);
  uStack_4c = uVar41 + iVar34;
  iVar37 = (uVar41 + iVar34) - 3;
  if ((int)uVar41 < iVar37) {
    iStack_70 = iVar34 >> 2;
    puStack_6c = &uStack_174 + iVar37 + param_4;
    puStack_48 = (undefined4 *)((int)local_170 + (uVar27 + param_4) * 4);
    puVar9 = auStack_128 + uVar41 + 3;
    puVar42 = (undefined4 *)((iStack_5c + uVar27) * 4 + iStack_44);
    uVar29 = ae_l32_i(0);
    puVar7 = &uStack_174 + uVar27 + param_4;
    do {
      uVar26 = ae_s32_l_i(uVar29);
      *puVar9 = uVar26;
      uVar26 = ae_s32_l_i(uVar29);
      puVar9[1] = uVar26;
      uVar26 = ae_s32_l_i(uVar29);
      puVar9[2] = uVar26;
      uVar26 = ae_s32_l_i(uVar29);
      puVar9[3] = uVar26;
      uVar29 = float_s(puVar42[2],0);
      uVar24 = float_s(puVar42[3],0);
      uVar30 = float_s(*puVar42,0);
      uVar31 = float_s(puVar42[1],0);
      puVar43 = puVar7 + 4;
      uVar26 = ae_s32_l_i(uVar30);
      *puVar7 = uVar26;
      uVar26 = ae_s32_l_i(uVar31);
      puVar7[1] = uVar26;
      uVar26 = ae_s32_l_i(uVar29);
      puVar7[2] = uVar26;
      puVar4 = puStack_48;
      uVar26 = ae_s32_l_i(uVar24);
      puVar7[3] = uVar26;
      puVar42 = puVar42 + 4;
      if (0 < param_4) {
        uVar29 = ae_l32_ip(*puStack_28);
        uVar30 = ae_l32_i(puVar4[-1]);
        uVar24 = ae_l32_ip(*puVar4);
        fVar20 = (float)uVar29;
        uVar29 = ae_l32_i(puVar4[1]);
        uVar32 = ae_l32_i(0);
        uVar31 = ae_l32_i(puVar4[2]);
        fVar22 = fVar20 * (float)uVar29;
        fVar19 = fVar20 * (float)uVar31;
        fVar23 = (float)uVar32;
        fVar17 = fVar23 + (float)uVar30 * fVar20;
        uVar29 = ae_mov(uVar32);
        fVar13 = (float)uVar29;
        fVar20 = fVar23 + fVar20 * (float)uVar24;
        if (1 < param_4) {
          uVar29 = ae_l32_ip(puStack_28[1]);
          uVar24 = ae_l32_i(puVar4[-2]);
          uVar30 = ae_l32_ip(puVar4[-1]);
          iVar34 = param_4 + -2;
          uVar31 = ae_l32_i(*puVar4);
          fVar12 = (float)uVar29;
          fVar1 = (float)uVar24 * fVar12;
          fVar35 = (float)uVar31;
          uVar29 = ae_l32_i(puVar4[1]);
          fVar36 = (float)uVar29;
          fVar2 = fVar12 * (float)uVar30;
          fVar21 = fVar22;
          fVar18 = fVar19;
          fVar14 = fVar1;
          fVar15 = fVar2;
          if ((0 < iVar34) && ((iVar34 == 1 || (0 < iVar34)))) {
            uVar29 = ae_l32_i(puVar4[-3]);
            uVar30 = ae_l32_ip(puVar4[-2]);
            fVar18 = fVar12 * fVar36;
            fVar13 = fVar13 + fVar19;
            uVar24 = ae_l32_ip(puStack_28[2]);
            fVar21 = fVar12 * fVar35;
            uVar32 = (ulonglong)(uint)(fVar23 + fVar22);
            fVar12 = (float)uVar24;
            uVar24 = ae_l32_i(puVar4[-1]);
            uVar31 = ae_l32_i(*puVar4);
            fVar15 = fVar12 * (float)uVar30;
            fVar20 = fVar20 + fVar2;
            fVar35 = (float)uVar24;
            fVar36 = (float)uVar31;
            fVar14 = (float)uVar29 * fVar12;
            fVar17 = fVar17 + fVar1;
          }
          uVar32 = (ulonglong)(uint)((float)uVar32 + fVar21);
          fVar22 = fVar12 * fVar35;
          fVar13 = fVar13 + fVar18;
          fVar19 = fVar12 * fVar36;
          fVar20 = fVar20 + fVar15;
          fVar17 = fVar17 + fVar14;
        }
        uVar26 = ae_s32_l_i((ulonglong)(uint)fVar20);
        puVar9[1] = uVar26;
        uVar26 = ae_s32_l_i((ulonglong)(uint)fVar17);
        *puVar9 = uVar26;
        uVar26 = ae_s32_l_i((ulonglong)(uint)((float)uVar32 + fVar22));
        puVar9[2] = uVar26;
        uVar26 = ae_s32_l_i((ulonglong)(uint)(fVar13 + fVar19));
        puVar9[3] = uVar26;
      }
      puStack_48 = puStack_48 + 4;
      puVar9 = puVar9 + 4;
      uVar29 = ae_l32_i(0);
      puVar7 = puVar43;
    } while (puVar43 <= puStack_6c);
    uVar27 = iStack_70 * 4 + uVar41 + 1;
  }
  uVar41 = uStack_4c;
  if ((int)uVar27 <= (int)uStack_4c) {
LAB_0022afca:
    puVar7 = auStack_128 + uVar27 + 2;
    puVar9 = &uStack_174 + uVar27 + param_4;
    iVar34 = (int)local_170 + (uVar27 + param_4) * 4;
    puStack_60 = &uStack_174 + uStack_4c + param_4 + 1;
    puVar42 = (undefined4 *)((iStack_5c + uVar27) * 4 + iStack_44);
    do {
      puVar43 = puStack_28;
      uVar29 = float_s(*puVar42,0);
      uVar24 = ae_l32_i(0);
      uVar26 = ae_s32_l_i(uVar24);
      *puVar7 = uVar26;
      puVar42 = puVar42 + 1;
      uVar26 = ae_s32_l_i(uVar29);
      *puVar9 = uVar26;
      puVar4 = puStack_60;
      puVar9 = puVar9 + 1;
      if (0 < param_4) {
        uVar29 = ae_l32_ip(*puVar43);
        uVar24 = ae_l32_ip(*(undefined4 *)(iVar34 + -4));
        iVar37 = param_4 + -1;
        uVar30 = ae_l32_i(0);
        fVar19 = (float)uVar24 * (float)uVar29;
        fVar22 = (float)uVar30;
        fVar13 = fVar19;
        if ((0 < iVar37) && ((iVar37 == 1 || (0 < iVar37)))) {
          uVar29 = ae_l32_ip(puVar43[1]);
          uVar24 = ae_l32_ip(*(undefined4 *)(iVar34 + -8));
          fVar13 = (float)uVar24 * (float)uVar29;
          fVar22 = fVar22 + fVar19;
        }
        uVar26 = ae_s32_l_i((ulonglong)(uint)(fVar22 + fVar13));
        *puVar7 = uVar26;
      }
      puVar7 = puVar7 + 1;
      iVar34 = iVar34 + 4;
      uVar41 = uStack_4c;
    } while (puVar9 != puVar4);
  }
  goto LAB_0022a90b;
}


// ===== FUN_0022b420 @ 0022b420 (163 bytes)

void FUN_0022b420(int param_1)

{
  uint uVar1;
  undefined8 in_aed0;
  int iVar2;
  
  uVar1 = ae_s32_l_i(in_aed0);
  if (((uVar1 & 0x7fffffff) < 0x32000000) && (iVar2 = trunc_s(in_aed0,0), iVar2 == 0)) {
    return;
  }
  const_s(3);
  if (param_1 != 0) {
    return;
  }
  return;
}


// ===== FUN_0022b4d0 @ 0022b4d0 (22 bytes)

undefined4 FUN_0022b4d0(int param_1)

{
  FUN_0022b874(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  return 0;
}


// ===== FUN_0022b4f0 @ 0022b4f0 (396 bytes)

uint FUN_0022b4f0(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  uVar4 = param_2 >> 0x14 & 0x7ff;
  iVar1 = (int)param_2 >> 0x1f;
  if (0x412 < uVar4) {
    if (0x432 < uVar4) {
      if (uVar4 != 0x7ff) {
        return param_1;
      }
      uVar4 = FUN_00235630(0,&DAT_40000000,param_1,param_2,0x7ff,0x7ff,param_1,param_2);
      return uVar4;
    }
    uVar2 = uVar4 - 0x413 & 0x1f;
    uVar4 = 0xffffffff >> uVar2;
    if ((uVar4 & param_1) == 0) {
      return param_1;
    }
    uVar4 = uVar4 >> 1;
    if ((param_1 & uVar4) != 0) {
      param_1 = (int)&DAT_40000000 >> uVar2 | param_1 & (uVar4 ^ 0xffffffff);
    }
LAB_0022b584:
    iVar1 = iVar1 * -8;
    uVar6 = *(undefined4 *)(&DAT_00205e54 + iVar1);
    uVar7 = *(undefined4 *)(&DAT_00205e50 + iVar1);
    uVar8 = FUN_00235510(param_1,param_2,uVar7,uVar6);
    memw();
    memw();
    memw();
    memw();
    uVar4 = FUN_00235570((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar7,uVar6);
    return uVar4;
  }
  if (uVar4 < 0x3ff) {
    if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) {
      uVar4 = param_1 | param_2 & (uint)&DAT_000fffff;
      iVar1 = iVar1 * -8;
      uVar6 = *(undefined4 *)(&DAT_00205e54 + iVar1);
      uVar7 = *(undefined4 *)(&DAT_00205e50 + iVar1);
      uVar8 = FUN_00235510(param_1,param_2 & 0xfffe0000 |
                                   (uVar4 | -uVar4) >> 0xc & (uint)&DAT_00080000,uVar7,uVar6);
      memw();
      memw();
      memw();
      memw();
      uVar4 = FUN_00235570((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar7,uVar6);
      return uVar4;
    }
  }
  else {
    uVar3 = uVar4 - 0x3ff & 0x1f;
    uVar2 = (int)&DAT_000fffff >> uVar3;
    uVar5 = uVar2 >> 1;
    if (param_1 != 0 || (uVar2 & param_2) != 0) {
      if (param_1 != 0 || (param_2 & uVar5) != 0) {
        param_2 = param_2 & (uVar5 ^ 0xffffffff);
        param_1 = param_2;
        if (uVar4 == 0x412) {
          param_1 = 0x80000000;
        }
        param_2 = (int)&DAT_00040000 >> uVar3 | param_2;
      }
      goto LAB_0022b584;
    }
  }
  return param_1;
}


// ===== FUN_0022b680 @ 0022b680 (21 bytes)

void FUN_0022b680(void)

{
  uint uVar1;
  undefined8 in_aed0;
  
  uVar1 = ae_s32_l_i(in_aed0);
  ae_l32_i(uVar1 & 0x7fffffff);
  return;
}


// ===== FUN_0022b6a0 @ 0022b6a0 (29 bytes)

undefined4 FUN_0022b6a0(void)

{
  uint uVar1;
  undefined8 in_aed0;
  
  uVar1 = ae_s32_l_i(in_aed0);
  if (0x7f7fffff < (uVar1 & 0x7fffffff)) {
    return 0;
  }
  return 1;
}


// ===== FUN_0022b6c0 @ 0022b6c0 (79 bytes)

undefined4 FUN_0022b6c0(void)

{
  int iVar1;
  undefined8 in_aed0;
  
  iVar1 = ae_s32_l_i(in_aed0);
  if ((iVar1 == 0) || (iVar1 == -0x80000000)) {
    return 2;
  }
  if ((iVar1 - 0x800000U < 0x7f000000) || (iVar1 + 0x7f800000U < 0x7f000000)) {
    return 4;
  }
  if ((iVar1 - 1U < 0x7fffff) || (iVar1 + 0x7fffffffU < 0x7fffff)) {
    return 3;
  }
  if ((iVar1 != 0x7f800000) && (iVar1 != -0x800000)) {
    return 0;
  }
  return 1;
}


// ===== FUN_0022b710 @ 0022b710 (13 bytes)

void FUN_0022b710(void)

{
  ae_l32_i(0x7fc00000);
  return;
}


// ===== FUN_0022b720 @ 0022b720 (226 bytes)

void FUN_0022b720(int param_1)

{
  uint uVar1;
  undefined8 in_aed0;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar1 = ae_s32_l_i(in_aed0);
  uVar2 = uVar1 >> 0x17 & 0xff;
  uVar4 = ae_mov(in_aed0);
  if ((uVar1 & 0x7fffffff) == 0) {
    return;
  }
  if (0x7f7fffff < (uVar1 & 0x7fffffff)) {
    const_s(2);
    return;
  }
  if ((uVar1 & 0x7fffffff) < 0x800000) {
    uVar1 = ae_s32_l_i((ulonglong)(uint)((float)uVar4 * 33554432.0));
    uVar2 = (uVar1 >> 0x17 & 0xff) - 0x19;
    if (param_1 < -50000) {
      return;
    }
  }
  iVar3 = param_1 + uVar2;
  if (iVar3 < 0xff) {
    if (0 < iVar3) {
      ae_l32_i(iVar3 * 0x800000 | uVar1 & 0x807fffff);
      return;
    }
    if (iVar3 < -0x16) {
      if ((int)&DAT_0000c350 < param_1) {
        ae_l32_i(0x7149f2ca);
        FUN_0022b810();
        ae_l32_i(0x7149f2ca);
        return;
      }
      ae_l32_i(0xda24260);
      FUN_0022b810();
      ae_l32_i(0xda24260);
      return;
    }
    ae_l32_i((iVar3 + 0x19) * 0x800000 | uVar1 & 0x807fffff);
    return;
  }
  ae_l32_i(0x7149f2ca);
  FUN_0022b810();
  ae_l32_i(0x7149f2ca);
  return;
}


// ===== FUN_0022b810 @ 0022b810 (37 bytes)

void FUN_0022b810(void)

{
  uint uVar1;
  uint uVar2;
  undefined8 in_aed0;
  undefined8 in_aed1;
  
  uVar1 = ae_s32_l_i(in_aed1);
  uVar2 = ae_s32_l_i(in_aed0);
  ae_l32_i(uVar2 & 0x7fffffff | uVar1 & 0x80000000);
  return;
}


// ===== FUN_0022b838 @ 0022b838 (14 bytes)

int FUN_0022b838(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  f64cmpl(param_1,param_3);
  uVar1 = f64cmpl_1(param_1,param_3);
  iVar2 = f64cmph(param_2,param_4,5,uVar1);
  f64cmph_1(param_2,param_4,5,uVar1);
  return -iVar2;
}


// ===== FUN_0022b848 @ 0022b848 (16 bytes)

int FUN_0022b848(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  f64cmpl(param_1,param_3);
  uVar1 = f64cmpl_1(param_1,param_3);
  iVar2 = f64cmph(param_2,param_4,6,uVar1);
  f64cmph_1(param_2,param_4,6,uVar1);
  return iVar2 * -0x80000000 + 1;
}


// ===== FUN_0022b858 @ 0022b858 (11 bytes)

undefined4 FUN_0022b858(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  f64cmpl(param_1,param_3);
  uVar1 = f64cmpl_1(param_1,param_3);
  uVar2 = f64cmph(param_2,param_4,8,uVar1);
  f64cmph_1(param_2,param_4,8,uVar1);
  return uVar2;
}


// ===== FUN_0022b864 @ 0022b864 (16 bytes)

int FUN_0022b864(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  f64cmpl(param_1,param_3);
  uVar1 = f64cmpl_1(param_1,param_3);
  iVar2 = f64cmph(param_2,param_4,9,uVar1);
  f64cmph_1(param_2,param_4,9,uVar1);
  return iVar2 * 2 + -1;
}


// ===== FUN_0022b874 @ 0022b874 (11 bytes)

undefined4 FUN_0022b874(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  f64cmpl(param_1,param_3);
  uVar1 = f64cmpl_1(param_1,param_3);
  uVar2 = f64cmph(param_2,param_4,10,uVar1);
  f64cmph_1(param_2,param_4,10,uVar1);
  return uVar2;
}


// ===== FUN_0022b880 @ 0022b880 (42 bytes)

undefined4 FUN_0022b880(int param_1,uint param_2,int param_3,uint param_4)

{
  if (((~param_2 & 0x7ff00000) == 0) && ((param_2 & 0xfffff) != 0 || param_1 != 0)) {
    return 1;
  }
  if (((~param_4 & 0x7ff00000) == 0) && ((param_4 & 0xfffff) != 0 || param_3 != 0)) {
    return 1;
  }
  return 0;
}

