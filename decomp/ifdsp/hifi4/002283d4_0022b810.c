// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_002283d4 @ 002283d4 (10 bytes)

undefined4 FUN_002283d4(void)

{
  return DAT_00237a88;
}


// ===== FUN_002283e0 @ 002283e0 (34 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_002283e0(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x20) != '\0') {
      uVar1 = 0;
      FUN_002284e8(param_1);
    }
    rsr(uVar1);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_002284e8 @ 002284e8 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_002284e8(int param_1)

{
  if (param_1 == 0) {
    return 0xffff0001;
  }
  rsr(0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00228564 @ 00228564 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00228564(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (param_1 == 0) {
    return 0xffff0001;
  }
  if (*(char *)(param_1 + 0x20) != '\0') {
    uVar1 = 0;
    FUN_002284e8(param_1);
  }
  rsr(uVar1);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00228634 @ 00228634 (26 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00228634(int param_1)

{
  if (param_1 != 0) {
    rsr(0);
    flix();
    cust1();
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== xos_thread_sleep @ 0022866c (45 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0022868f) */

void xos_thread_sleep(void)

{
  int unaff_retaddr;
  uint uVar1;
  int unaff_a11;
  
  uVar1 = rsr(0);
  if ((uVar1 & 0x20) != 0) {
    flix();
    FUN_002354c0(unaff_a11 + unaff_retaddr + 0x10);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002286fc @ 002286fc (41 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0022870e) overlaps instruction at (ram,0x0022870d)
    */

undefined4 FUN_002286fc(int param_1)

{
  uint uVar1;
  
  uVar1 = rsr(0);
  if ((uVar1 & 0x20) == 0) {
    flix();
    flix();
  }
  else if (param_1 == 0) {
    return 0xffff0001;
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    return 0xffff0001;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00228734 @ 00228734 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228734(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00228748 @ 00228748 (36 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228748(int param_1)

{
  flix();
  flix();
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002287f8 @ 002287f8 (2 bytes)

void FUN_002287f8(void)

{
  return;
}


// ===== FUN_00228818 @ 00228818 (26 bytes)

undefined4 FUN_00228818(undefined4 param_1)

{
  undefined1 in_EXCSAVE3;
  
  DAT_00237aac = param_1;
  if (PTR_FUN_00237a98 != (undefined *)0x0) {
    (*(code *)PTR_FUN_00237a98)();
  }
  rsr(in_EXCSAVE3);
  return DAT_00237aac;
}


// ===== FUN_00228834 @ 00228834 (25 bytes)

void FUN_00228834(void)

{
  undefined4 unaff_retaddr;
  undefined1 in_EXCSAVE5;
  
  wsr(in_EXCSAVE5,unaff_retaddr);
  if (DAT_00237ab0 != (code *)0x0) {
    (*DAT_00237ab0)();
    rsr(in_EXCSAVE5);
    return;
  }
  breakpoint(0x1000,0x228847,1,0xf);
  do {
    ill();
  } while( true );
}


// ===== FUN_00228c44 @ 00228c44 (61 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228c44(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_a13;
  int in_SAR;
  undefined1 in_WindowBase;
  undefined1 in_WindowStart;
  undefined1 in_CCOUNT;
  
  if (*(char *)(DAT_00237858 + 0x30) == '\0') {
    rsr(in_WindowBase);
    flix();
    wsr(in_WindowStart,0 << 0x20 - in_SAR);
    rsync();
    rsil(2);
    *(undefined1 **)(DAT_00237858 + 0xc) = &LAB_00228c94;
    uVar3 = rsr(in_CCOUNT);
    flix();
    DAT_00237858 = param_1;
    DAT_0023785c = param_1;
    *(undefined **)(in_a13 + 0x14) = &DAT_00237850;
    *(undefined4 *)(param_1 + 0x2c) = uVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar2 = rsr(0);
  iVar1 = (uVar2 & 0xfffbfff0) + 2;
  wsr(0,iVar1);
  rsync();
  FUN_002332c4(param_1,&DAT_00237850,param_1,iVar1);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00228cfc @ 00228cfc (40 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228cfc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = rsr(0);
  iVar1 = (uVar2 & 0xfffbfff0) + 2;
  wsr(0,iVar1);
  rsync();
  FUN_002332c4(param_1,param_2,param_1,iVar1);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
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


// ===== FUN_00228dc0 @ 00228dc0 (31 bytes)

void FUN_00228dc0(void)

{
  undefined4 unaff_retaddr;
  undefined4 *in_a7;
  undefined4 unaff_a9;
  undefined1 auStack_20 [32];
  
  flix();
  *(undefined1 **)unaff_retaddr = auStack_20;
  *in_a7 = unaff_a9;
  DAT_002cd6d0 = DAT_002cd6d0 + 1;
  return;
}


// ===== FUN_00228df0 @ 00228df0 (43 bytes)

void FUN_00228df0(void)

{
  int unaff_retaddr;
  int in_a7;
  undefined4 unaff_a9;
  int in_a12;
  undefined1 auStack_20 [32];
  
  flix();
  *(undefined1 **)unaff_retaddr = auStack_20;
  *(undefined4 *)(unaff_retaddr + 4) = unaff_a9;
  flix();
  DAT_002cd6d0 = in_a12;
  if (in_a12 == 0) {
    xos_mutex_unlock(&DAT_002cd6b0,in_a7 + 10);
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


// ===== FUN_00228e34 @ 00228e34 (12 bytes)

void FUN_00228e34(void)

{
  flix();
  FUN_00228299();
  return;
}


// ===== FUN_00228e60 @ 00228e60 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228e60(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00228e84 @ 00228e84 (25 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228e84(int param_1)

{
  undefined4 *in_a12;
  
  flix();
  if (param_1 != 0x77) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_00228299(*in_a12,0x177);
  return;
}


// ===== FUN_00228fb0 @ 00228fb0 (39 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228fb0(int param_1)

{
  undefined4 unaff_retaddr;
  undefined4 uVar1;
  int unaff_a11;
  undefined4 in_a12;
  int in_a13;
  int in_t0;
  
  flix();
  *(undefined4 *)(unaff_a11 + 4) = unaff_retaddr;
  if (in_a13 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = func_0x001bbdc0();
  *(undefined4 *)(in_t0 + 0x18) = in_a12;
  *(undefined4 *)(in_t0 + 0x40) = uVar1;
  FUN_0022c150(param_1 + 0x90);
  FUN_0022c0c0(param_1 + 0x90);
  return;
}


// ===== FUN_00229224 @ 00229224 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00229224(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00229238 @ 00229238 (67 bytes)

/* WARNING: Control flow encountered bad instruction data */

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
        flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      xos_mutex_unlock(&DAT_002cd6dc);
    }
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_00229284 @ 00229284 (33 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00229284(void)

{
  undefined4 uVar1;
  undefined1 in_CCOMPARE0;
  undefined1 in_CCOMPARE1;
  
  if (DAT_00237ac8 == 1) {
    uVar1 = rsr(in_CCOMPARE1);
    return uVar1;
  }
  if (DAT_00237ac8 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = rsr(in_CCOMPARE0);
  return uVar1;
}


// ===== FUN_002292ac @ 002292ac (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002292ac(void)

{
  rsr(0);
  flix();
  rur(0xee);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022930c @ 0022930c (38 bytes)

bool FUN_0022930c(void)

{
  uint uVar1;
  int in_SAR;
  undefined1 in_INTSET;
  
  if (DAT_002cd6fc < 0x20) {
    uVar1 = rsr(in_INTSET);
    flix();
    uVar1 = uVar1 & DAT_002cd6fc << 0x20 - in_SAR;
  }
  else {
    uVar1 = 0;
  }
  return uVar1 != 0;
}


// ===== FUN_00229340 @ 00229340 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00229340(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint in_a7;
  uint unaff_a9;
  
  flix();
  if ((in_a7 & unaff_a9) != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = param_2;
  }
  return uVar1;
}


// ===== FUN_002293ac @ 002293ac (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002293ac(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002293cc @ 002293cc (8 bytes)

void FUN_002293cc(void)

{
  FUN_00228158();
  return;
}


// ===== FUN_002293e0 @ 002293e0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002293e0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00229460 @ 00229460 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00229460(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002294e0 @ 002294e0 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002294e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 in_a12;
  
  flix();
  *(undefined4 *)(param_3 + 0x20) = in_a12;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00229a20 @ 00229a20 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00229a20(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00229b10 @ 00229b10 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00229b10(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022a320 @ 0022a320 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022a320(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022a610 @ 0022a610 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022a610(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022a6f0 @ 0022a6f0 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022a6f0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022a7bf @ 0022a7bf (7 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022a7bf(undefined4 param_1,int param_2)

{
  int unaff_a11;
  
  if (param_2 < unaff_a11) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b420 @ 0022b420 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b420(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b456 @ 0022b456 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b456(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b4d0 @ 0022b4d0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b4d0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b4f0 @ 0022b4f0 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b4f0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b680 @ 0022b680 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b680(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b6a0 @ 0022b6a0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b6a0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b6c0 @ 0022b6c0 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b6c0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b710 @ 0022b710 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b710(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b720 @ 0022b720 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b720(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b810 @ 0022b810 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b810(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

