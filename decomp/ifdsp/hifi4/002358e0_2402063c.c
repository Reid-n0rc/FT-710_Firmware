// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 48 functions

// ===== FUN_002358e0 @ 002358e0 (23 bytes)

undefined8 FUN_002358e0(uint param_1,int param_2,uint param_3,int param_4)

{
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_4 * param_1,param_1 * param_3);
}


// ===== __udivdi3 @ 00235900 (28 bytes)

void __udivdi3(void)

{
  undefined1 in_LBEG;
  
  flix();
  func_0x001e5bc4();
  cust1();
  rsr(in_LBEG);
  return;
}


// ===== FUN_00235b80 @ 00235b80 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00235b80(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00235ba8 @ 00235ba8 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00235ba8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00235c50 @ 00235c50 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00235c50(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00235c8c @ 00235c8c (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00235c8c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== memcpy @ 00235d30 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void memcpy(void)

{
  flix();
  func_0x001e6d4c();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== memset @ 00235eb0 (129 bytes)

/* WARNING: Control flow encountered bad instruction data */

void memset(uint *param_1,uint param_2,uint param_3,uint *param_4)

{
  undefined1 extraout_a3;
  undefined1 extraout_a3_00;
  undefined1 uVar1;
  uint extraout_a3_01;
  uint extraout_a3_02;
  uint extraout_a3_03;
  int extraout_a4;
  uint extraout_a4_00;
  uint extraout_a4_01;
  uint extraout_a4_02;
  uint extraout_a4_03;
  uint *extraout_a5;
  uint *extraout_a5_00;
  uint *extraout_a5_01;
  uint *extraout_a5_02;
  uint *extraout_a5_03;
  
  flix();
  thunk_FUN_00232ca3();
  param_2 = param_2 | param_2 << 8;
  param_2 = param_2 | param_2 << 0x10;
  if (((uint)param_1 & 1) != 0) {
    if (param_3 < 8) goto LAB_00235f2e;
    flix();
    func_0x001fe07c();
    param_3 = extraout_a4 - 1;
    param_2 = extraout_a3_01;
    param_4 = extraout_a5;
    param_1 = extraout_a5;
  }
  if (((uint)param_1 & 2) == 0) {
    if (param_3 >> 4 == 1) {
      isync();
    }
    if (param_3 >> 4 != 0) {
      *param_4 = param_2;
      param_4[1] = param_2;
      param_4[2] = param_2;
      flix();
      func_0x001fe494();
      param_2 = extraout_a3_02;
      param_3 = extraout_a4_00;
      param_4 = extraout_a5_00;
    }
    if ((param_3 & 8) != 0) {
      *param_4 = param_2;
      flix();
      func_0x001fe0a0();
      param_2 = extraout_a3_03;
      param_3 = extraout_a4_01;
      param_4 = extraout_a5_01;
    }
    uVar1 = (undefined1)param_2;
    if ((param_3 & 4) != 0) {
      flix();
      func_0x001fe0a8();
      param_3 = extraout_a4_02;
      param_4 = extraout_a5_02;
      uVar1 = extraout_a3;
    }
    if ((param_3 & 2) != 0) {
      flix();
      func_0x001fe0a0();
      param_3 = extraout_a4_03;
      param_4 = extraout_a5_03;
      uVar1 = extraout_a3_00;
    }
    if ((param_3 & 1) != 0) {
      *(undefined1 *)param_4 = uVar1;
    }
    return;
  }
  if (7 < param_3) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
LAB_00235f2e:
  if (param_3 == 1) {
    isync();
  }
  if (param_3 != 0) {
    flix();
    func_0x001fe0dc();
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


// ===== FUN_00235fa0 @ 00235fa0 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00235fa0(void)

{
  int unaff_a11;
  
  flix();
  if (unaff_a11 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cust1();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00236000 @ 00236000 (46 bytes)

/* WARNING: Control flow encountered bad instruction data */

int * FUN_00236000(int *param_1,code *param_2,int param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  int unaff_a8;
  int unaff_a11;
  int in_a13;
  
  flix();
  if (unaff_a11 != in_a13) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  piVar2 = param_1;
  if (unaff_a8 != -1) {
    uVar1 = (*param_2)(param_3);
    piVar2 = (int *)(uVar1 | (uint)param_1);
  }
  if (param_3 + 0x68 == param_4) {
    if (*param_1 == 0) {
      return piVar2;
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00236060 @ 00236060 (24 bytes)

void FUN_00236060(undefined4 param_1,int param_2)

{
  undefined4 *extraout_a3;
  int extraout_a4;
  undefined4 *puVar1;
  int extraout_a5;
  
  if (param_2 != 0) {
    flix();
    FUN_0020e5cc();
    puVar1 = (undefined4 *)(extraout_a4 * 4 + extraout_a5);
    *extraout_a3 = *puVar1;
    *puVar1 = extraout_a3;
    return;
  }
  return;
}


// ===== FUN_00236080 @ 00236080 (73 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined8 FUN_00236080(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 in_a15;
  
  flix();
  if (param_1 >> 0x18 == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 >> 0x1c != 0) {
    if (param_1 >> 0x1e == 0) {
      flix();
      flix();
    }
    if (-1 < (int)param_1) {
      flix();
      return CONCAT44(param_1 >> 0x10,0x20);
    }
    return CONCAT44(param_1 >> 0x10,param_3);
  }
  flix();
  release(in_a15);
  *(undefined4 *)in_a15 = in_a15;
  do {
    ill();
  } while( true );
}


// ===== FUN_002360e0 @ 002360e0 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_002360e0(uint *param_1)

{
  if ((*param_1 & 7) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((*param_1 & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_00236170 @ 00236170 (9 bytes)

void FUN_00236170(void)

{
  flix();
  FUN_0022c1d2();
  return;
}


// ===== FUN_002361d0 @ 002361d0 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002361d0(int param_1)

{
  undefined4 in_a15;
  
  flix();
  *(undefined4 *)(param_1 + 4) = in_a15;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00236270 @ 00236270 (19 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00236270(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x10) < param_2 >> 5) {
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002362f0 @ 002362f0 (7 bytes)

undefined4 FUN_002362f0(void)

{
  return 0;
}


// ===== FUN_00236300 @ 00236300 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00236307) overlaps instruction at (ram,0x00236306)
    */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_00236300(void)

{
  int unaff_retaddr;
  int in_a6;
  int in_a13;
  
  flix();
  if (unaff_retaddr <= in_a6) {
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (in_a13 == 0x100) {
    do {
      ill();
    } while( true );
  }
  if (in_a13 == 0x100) {
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002363f0 @ 002363f0 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_002363f0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_00236420 @ 00236420 (7 bytes)

undefined4 FUN_00236420(void)

{
  return 0;
}


// ===== FUN_00236430 @ 00236430 (13 bytes)

void FUN_00236430(void)

{
  flix();
  return;
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
  undefined1 in_CCOUNT;
  
  uVar1 = rsr(in_CCOUNT);
  return uVar1;
}


// ===== FUN_00236478 @ 00236478 (26 bytes)

void FUN_00236478(int param_1,undefined4 param_2)

{
  undefined1 in_CCOMPARE0;
  undefined1 in_CCOMPARE1;
  
  if (param_1 == 0) {
    wsr(in_CCOMPARE0,param_2);
    rsync();
    return;
  }
  if (param_1 == 1) {
    wsr(in_CCOMPARE1,param_2);
    rsync();
    return;
  }
  return;
}


// ===== FUN_00236494 @ 00236494 (22 bytes)

undefined4 FUN_00236494(int param_1)

{
  undefined4 uVar1;
  undefined1 in_CCOMPARE0;
  undefined1 in_CCOMPARE1;
  
  if (param_1 == 0) {
    uVar1 = rsr(in_CCOMPARE0);
    return uVar1;
  }
  if (param_1 == 1) {
    uVar1 = rsr(in_CCOMPARE1);
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

/* WARNING: Control flow encountered bad instruction data */

void FUN_002364f4(int param_1)

{
  if (param_1 != 0) {
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_00236500 @ 00236500 (34 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00236500(int param_1)

{
  if (param_1 != 0) {
    flix();
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_00236540 @ 00236540 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00236540(void)

{
  flix();
  FUN_00226800();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_24020044 @ 24020044 (102 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_24020044(void)

{
  undefined *puVar1;
  undefined1 in_ATOMCTL;
  undefined1 in_INTENABLE;
  undefined1 in_VECBASE;
  
  wsr(in_INTENABLE,0);
  wsr(in_VECBASE,PTR__WindowOverflow4_24020004);
  wsr(in_ATOMCTL,0x15);
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
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
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

undefined8 _Vector_57c(void)

{
  undefined4 unaff_retaddr;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 in_EPC2;
  undefined1 in_EPS2;
  undefined1 in_EXCSAVE1;
  undefined1 in_EXCCAUSE;
  
  wsr(in_EXCCAUSE,4);
  xsr(in_EXCSAVE1,unaff_retaddr);
  uVar1 = rsr(in_EPS2);
  uVar2 = rsr(in_EPC2);
  return CONCAT44(uVar2,uVar1);
}


// ===== _Vector_59c @ 2402059c (12 bytes)

void _Vector_59c(void)

{
  undefined4 unaff_retaddr;
  undefined1 in_EXCSAVE3;
  
  wsr(in_EXCSAVE3,unaff_retaddr);
  (*(code *)dsp_dtcm_base)();
  do {
    ill();
  } while( true );
}


// ===== _Vector_5bc @ 240205bc (12 bytes)

void _Vector_5bc(void)

{
  undefined4 unaff_retaddr;
  undefined1 in_EXCSAVE4;
  
  wsr(in_EXCSAVE4,unaff_retaddr);
  (*(code *)PTR_FUN_24000004)();
  do {
    ill();
  } while( true );
}


// ===== _Vector_5dc @ 240205dc (12 bytes)

void _Vector_5dc(void)

{
  undefined4 unaff_retaddr;
  undefined1 in_EXCSAVE5;
  
  wsr(in_EXCSAVE5,unaff_retaddr);
  (*(code *)PTR_FUN_24000008)();
  do {
    ill();
  } while( true );
}


// ===== _Vector_61c @ 2402061c (24 bytes)

undefined8 _Vector_61c(void)

{
  undefined4 unaff_retaddr;
  int iVar1;
  undefined4 uVar2;
  undefined1 in_EPC1;
  undefined1 in_EXCSAVE1;
  
  xsr(in_EXCSAVE1,unaff_retaddr);
  iVar1 = rsr(0);
  uVar2 = rsr(in_EPC1);
  return CONCAT44(uVar2,iVar1 + -0x10);
}


// ===== _Vector_63c @ 2402063c (6 bytes)

void _Vector_63c(void)

{
  do {
    breakpoint(0x1000,0x2402063c,1,0xf);
  } while( true );
}

