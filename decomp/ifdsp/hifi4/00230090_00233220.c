// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00230090 @ 00230090 (73 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0023004e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00230090(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int in_t0;
  
  FUN_00228dc0(param_1);
  flix();
  flix();
  if (in_t0 < (int)((param_2 + 0x1000U & param_4 + 0x6e0U) - 0x1000)) {
    flix();
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_00228df0(param_1);
  return 0;
}


// ===== FUN_00230160 @ 00230160 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined * FUN_00230160(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return &DAT_00206410;
}


// ===== FUN_002301a0 @ 002301a0 (8 bytes)

char * FUN_002301a0(void)

{
  return s_ASCII_00238370;
}


// ===== FUN_002301b0 @ 002301b0 (10 bytes)

undefined4 FUN_002301b0(void)

{
  return DAT_00238330;
}


// ===== FUN_002301c0 @ 002301c0 (8 bytes)

char * FUN_002301c0(void)

{
  return s_ASCII_00238390;
}


// ===== FUN_002301d0 @ 002301d0 (10 bytes)

undefined4 FUN_002301d0(void)

{
  return DAT_002cd73c;
}


// ===== FUN_002301e0 @ 002301e0 (8 bytes)

undefined ** FUN_002301e0(void)

{
  return &PTR_DAT_00238334;
}


// ===== FUN_002301f0 @ 002301f0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002301f0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230210 @ 00230210 (18 bytes)

undefined4 FUN_00230210(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_002301e0(PTR_DAT_00237f00);
  return uVar1;
}


// ===== FUN_00230230 @ 00230230 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00230230(void)

{
  code *pcVar1;
  int in_a13;
  undefined1 uVar2;
  longlong lVar3;
  
  flix();
  uVar2 = 0;
  pcVar1 = (code *)0x23023c;
  lVar3 = FUN_00210294();
  flix();
  (*pcVar1)();
  if (in_a13 == 0x100) {
    rsr(uVar2);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (lVar3 < -0x100000000) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cust0();
  if (-0x100000001 < lVar3) {
    if ((int)lVar3 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  flix();
  if (*(char *)((int)lVar3 + 0x20) != '\0') {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00230340 @ 00230340 (84 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x002303a6) overlaps instruction at (ram,0x002303a5)
    */

byte * FUN_00230340(byte *param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5)

{
  int unaff_retaddr;
  undefined4 unaff_a9;
  undefined4 in_a12;
  int in_a13;
  int in_a14;
  int iVar1;
  int in_a15;
  undefined4 in_f14;
  undefined1 auStack_20 [32];
  
  if (((uint)param_1 & 3) != 0) {
    do {
      param_3 = param_3 - 1;
      if (param_3 == 0xffffffff) {
        return (byte *)0x0;
      }
      param_5 = (uint)*param_1;
      if (param_5 == (param_2 & 0xff)) {
        return param_1;
      }
      param_1 = param_1 + 1;
    } while (((uint)param_1 & 3) != 0);
  }
  if (3 < param_3) {
    flix();
    flix();
    iVar1 = *(int *)(in_a14 + 0x2c);
    *(undefined4 *)(in_a15 + 0x3c) = unaff_a9;
    *(undefined4 *)(iVar1 + 0x2c8) = in_f14;
    *(undefined4 *)(unaff_retaddr + 4) = in_a12;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  if (param_1 < (byte *)0x1000) {
    if (param_3 == 0xffffffff) {
      return (byte *)0x0;
    }
    if (param_5 == 1) {
      isync();
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  release(in_a13 + 0x98);
  *(undefined1 **)(in_a13 + 0x98) = auStack_20;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002303d0 @ 002303d0 (33 bytes)

void FUN_002303d0(int param_1)

{
  int *piVar1;
  int extraout_a3;
  undefined4 unaff_a8;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4c);
  flix();
  func_0x001eb3e0();
  piVar2 = (int *)(extraout_a3 * 4 + iVar3);
  piVar1 = (int *)*piVar2;
  flix();
  *piVar2 = *piVar1;
  piVar1[4] = unaff_a8;
  piVar1[3] = unaff_a8;
  return;
}


// ===== FUN_00230440 @ 00230440 (55 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230440(undefined4 param_1,int param_2)

{
  undefined4 unaff_retaddr;
  int iVar1;
  int unaff_a8;
  int unaff_a9;
  float in_f6;
  
  iVar1 = *(int *)(param_2 + 0x10);
  flix();
  *(undefined4 *)(iVar1 + 8) = unaff_retaddr;
  cust0();
  if (-1 < unaff_a9) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  *(undefined4 *)(iVar1 + 8) = unaff_retaddr;
  dpfr(iVar1 + 0x268);
  func_0x00289008();
  *(float *)(unaff_a8 + 0x30) = CEIL(in_f6 * 16384.0);
  flix();
  cust1();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002304f0 @ 002304f0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002304f0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002305a0 @ 002305a0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002305a0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002305c0 @ 002305c0 (21 bytes)

/* WARNING: Instruction at (ram,0x002305cd) overlaps instruction at (ram,0x002305cc)
    */

void FUN_002305c0(void)

{
  int unaff_retaddr;
  int in_a6;
  int in_a13;
  
  flix();
  if ((in_a6 < unaff_retaddr) && (in_a13 == 0x100)) {
    do {
      ill();
    } while( true );
  }
  flix();
  FUN_0021dfd6();
  return;
}


// ===== FUN_00230750 @ 00230750 (25 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00230757) overlaps instruction at (ram,0x00230756)
    */

void FUN_00230750(void)

{
  int unaff_retaddr;
  
  flix();
  if (unaff_retaddr != 1) {
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230800 @ 00230800 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230800(void)

{
  flix();
  func_0x00245df4();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002308e0 @ 002308e0 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002308e0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230a30 @ 00230a30 (38 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00230a3b) overlaps instruction at (ram,0x00230a39)
    */

void FUN_00230a30(void)

{
  int unaff_a8;
  int unaff_a11;
  int in_a13;
  undefined4 in_f1;
  
  flix();
  while (in_a13 == unaff_a11) {
    cust0();
    *(undefined4 *)(unaff_a8 + 0x70) = in_f1;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230a90 @ 00230a90 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230a90(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230b70 @ 00230b70 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230b70(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230c40 @ 00230c40 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230c40(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230cc0 @ 00230cc0 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230cc0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230d10 @ 00230d10 (34 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00230d10(int param_1,int param_2)

{
  if ((param_2 == 0) && (param_1 == 0)) {
    return 2;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230d80 @ 00230d80 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230d80(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230dc0 @ 00230dc0 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230dc0(undefined4 param_1,int param_2)

{
  if ((*(ushort *)(param_2 + 0xc) & 0x100) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230e00 @ 00230e00 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230e00(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230e40 @ 00230e40 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230e40(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230e50 @ 00230e50 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230e50(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230ec0 @ 00230ec0 (43 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00230ec0(undefined4 param_1,int param_2,int param_3)

{
  if (*(int *)(param_3 + 8) == 0) {
    flix();
    return 0;
  }
  if ((*(uint *)(param_2 + 100) & 0x2000) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00230f60 @ 00230f60 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230f60(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00231020 @ 00231020 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00231020(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00231040 @ 00231040 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00231040(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00232264 @ 00232264 (11 bytes)

/* WARNING: Instruction at (ram,0x0023226d) overlaps instruction at (ram,0x0023226c)
    */

void FUN_00232264(void)

{
  uint unaff_a11;
  
  if ((unaff_a11 & 0x8000000) == 0) {
    do {
      ill();
    } while( true );
  }
  do {
    ill();
  } while( true );
}


// ===== FUN_00232470 @ 00232470 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00232470(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002324a0 @ 002324a0 (32 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002324a0(undefined4 param_1,int param_2,int param_3)

{
  FUN_0022ba80(param_1,param_2 * param_3);
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00232520 @ 00232520 (38 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00232520(int param_1,int param_2)

{
  if (param_2 != 0) {
    if ((param_1 != 0) && (*(int *)(param_1 + 0x38) == 0)) {
      FUN_0022fd00(param_1);
    }
    if (*(short *)(param_2 + 0xc) != 0) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return 0;
}


// ===== FUN_002325f0 @ 002325f0 (64 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002325f0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((*(ushort *)(param_3 + 0xc) & 0x2000) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar1 = FUN_002301b0();
  if ((iVar1 == 1) && (param_2 != 0)) {
    flix();
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00232700 @ 00232700 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00232700(void)

{
  if ((PTR_DAT_00237f00 != (undefined *)0x0) && (*(int *)(PTR_DAT_00237f00 + 0x38) == 0)) {
    FUN_0022fd00();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00232730 @ 00232730 (43 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00232730(undefined4 param_1,int param_2,int param_3)

{
  int unaff_retaddr;
  undefined4 uVar1;
  int unaff_a9;
  
  if (*(int *)(param_3 + 8) == 0) {
    return 0;
  }
  flix();
  if (*(uint *)(param_2 + 0x10) != 0) {
    flix();
    if ((unaff_retaddr * 8 + unaff_a9 & *(uint *)(param_2 + 0x10)) != 0) {
      flix();
      uVar1 = FUN_0022a7bf();
      return uVar1;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00232af0 @ 00232af0 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00232af0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_00228dc0(param_1);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00232ca3 @ 00232ca3 (49 bytes)

int FUN_00232ca3(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                uint param_6)

{
  int unaff_retaddr;
  int iVar1;
  int unaff_a9;
  undefined4 in_a12;
  
  while( true ) {
    if (0xf < param_6 - param_4) {
      flix();
      iVar1 = FUN_0022d11b();
      return iVar1;
    }
    flix();
    if (unaff_a9 != unaff_retaddr) break;
    *(undefined4 *)((param_6 | *(uint *)(param_5 + 4) & 1) + 8) = in_a12;
  }
  *(uint *)(unaff_a9 + 4) = *(uint *)(unaff_a9 + 4) | 1;
  FUN_00228df0(param_1);
  return param_5 + 8;
}


// ===== FUN_00233010 @ 00233010 (25 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00233010(int param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_retaddr;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x38) == 0)) {
    FUN_0022fd00(param_1);
  }
  flix();
  *(undefined4 *)(*(int *)(param_3 + 0x18) + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002330e0 @ 002330e0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002330e0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00233100 @ 00233100 (17 bytes)

void FUN_00233100(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_002301a0();
  }
                    /* WARNING: Subroutine does not return */
  FUN_002301a0();
}


// ===== FUN_00233160 @ 00233160 (23 bytes)

void FUN_00233160(int param_1)

{
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_002301a0();
  }
                    /* WARNING: Subroutine does not return */
  FUN_002301a0();
}


// ===== FUN_002331d0 @ 002331d0 (6 bytes)

void FUN_002331d0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_002301a0();
}


// ===== FUN_00233200 @ 00233200 (20 bytes)

void FUN_00233200(undefined4 param_1,undefined4 param_2,int param_3)

{
  flix();
  *(undefined4 *)(param_3 + 4) = param_2;
  *(short *)(param_3 + 10) = (short)param_1;
  *(undefined4 *)(param_3 + 0x2c) = param_1;
  *(undefined4 *)(param_3 + 0x10) = param_1;
  return;
}


// ===== FUN_00233220 @ 00233220 (37 bytes)

undefined8 FUN_00233220(undefined1 *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  
  flix();
  do {
    uVar1 = FUN_0023329c();
    *param_1 = uVar1;
    flix();
    flix();
  } while (param_4 != 0);
  return CONCAT44(0xd,(int)param_1 - param_3);
}

