// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00220790 @ 00220790 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220790(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220aa4 @ 00220aa4 (65 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220aa4(int param_1,int param_2)

{
  FUN_00220470();
  if (param_1 != param_2) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (DAT_00256536 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (DAT_00256556 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (DAT_00256574._2_2_ != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_00220b30 @ 00220b30 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220b30(void)

{
  FUN_0021f6d0();
  FUN_0021fd20();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220b5c @ 00220b5c (21 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220b5c(undefined4 param_1)

{
  FUN_0021fa48(param_1);
  FUN_0021fdbc(param_1);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220bd0 @ 00220bd0 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220bd0(void)

{
  rsr(0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220c68 @ 00220c68 (17 bytes)

void FUN_00220c68(void)

{
  DAT_002577e0 = 0xffff;
  FUN_0021f410();
  return;
}


// ===== FUN_00220c7c @ 00220c7c (40 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220c7c(void)

{
  flix();
  rsr(0);
  flix();
  rur(0xee);
  func_0x001a0ca0();
  func_0x001ca1a4();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220d14 @ 00220d14 (89 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00220da0) overlaps instruction at (ram,0x00220d9f)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00220d14(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            ,undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  uint in_a12;
  undefined1 uVar3;
  
  if (DAT_00257320 < 0xc) {
    flix();
    FUN_00222e60(param_4 << 2);
    return param_1;
  }
  rsr(0);
  flix();
  cust1();
  wsr(0,param_4 * 2 + (uint)DAT_00257320 | in_a12);
  rsync();
  uVar2 = (uint)DAT_00257322;
  flix();
  uVar3 = 0;
  _DAT_ffffffe1 = param_6;
  uVar1 = FUN_00200ef8();
  flix();
  if (0x7fff < uVar1) {
    FUN_00235d30();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cust0();
  if ((byte)(&DAT_002580f0)[uVar1 * uVar2] < 0xd) {
    rsr(uVar3);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_00220da4 @ 00220da4 (32 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00220da4(int param_1)

{
  if ((byte)(&DAT_002580f0)[param_1 * (int)&DAT_00000908] < 0xd) {
    rsr(0);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_00220e34 @ 00220e34 (35 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220e34(int param_1)

{
  if ((&DAT_002580f0)[param_1 * (int)&DAT_00000908] != '\0') {
    rsr(0);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220ee0 @ 00220ee0 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220ee0(void)

{
  flix();
  rur(0x5e);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220f74 @ 00220f74 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220f74(undefined4 param_1)

{
  FUN_00220c7c(param_1);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220f90 @ 00220f90 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220f90(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220fd0 @ 00220fd0 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220fd0(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002210a4 @ 002210a4 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002210a4(void)

{
  flix();
  FUN_00235eb0(&DAT_200607e0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002210dc @ 002210dc (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002210dc(void)

{
  int unaff_retaddr;
  undefined4 unaff_a8;
  undefined4 *unaff_a9;
  int in_a14;
  
  flix();
  *unaff_a9 = unaff_a8;
  *(int *)(unaff_retaddr + 0x38) = in_a14 >> 0xe;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022111c @ 0022111c (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022111c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
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


// ===== FUN_00221198 @ 00221198 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00221198(int param_1,undefined4 param_2,int param_3)

{
  if (&DAT_000011f8 < (undefined *)(param_1 + param_3)) {
    return;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
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


// ===== FUN_002211d0 @ 002211d0 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002211d0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221220 @ 00221220 (108 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00221244) overlaps instruction at (ram,0x00221243)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_00221220(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_a5;
  int iVar3;
  int unaff_a9;
  int in_a12;
  int in_a14;
  uint in_a15;
  uint in_t0;
  
  flix();
  iVar2 = unaff_a9 + 7;
  iVar3 = in_a14 >> 0x15;
  *(int *)(unaff_a9 + 0x3f) = iVar2;
  FUN_00221540();
  uVar1 = _FUN_00207220;
  flix();
  if (-1 < in_a5 + iVar2) {
    do {
      ill();
    } while( true );
  }
  if ((~(in_a5 + iVar2) & in_t0) != 0) {
    if ((~in_a15 & in_t0) != 0) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    DAT_0025ac54 = _FUN_00207220;
    flix();
    *(int *)(in_a14 + 0x2c) = in_a12;
    *(uint *)(in_t0 + 0x30) = in_t0;
    flix();
    *(int *)(in_t0 + 4) = iVar2;
    *(int *)(in_a14 + 0x24) = in_a12;
    *(uint *)(in_a12 + 0x30) = in_t0 + 1;
    DAT_0025ac98 = uVar1;
    return;
  }
  func_0x00252fa8(iVar3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221540 @ 00221540 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00221540(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221854 @ 00221854 (74 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00221854(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 in_a14;
  
  FUN_00221220();
  if (param_1 != param_2) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (DAT_0025ac06 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (DAT_0025ac26 != 0) {
    flix();
    *(undefined4 *)(param_4 + -0x38) = in_a14;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (DAT_0025ac46 != 0) {
    flix();
    cust1();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_002218e0 @ 002218e0 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002218e0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221908 @ 00221908 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00221908(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221a10 @ 00221a10 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00221a10(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221a30 @ 00221a30 (40 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_00221a30(void)

{
  int in_a14;
  
  flix();
  if (in_a14 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x001d86e8(&DAT_0025af40);
  func_0x001aed98();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221b10 @ 00221b10 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00221b10(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221bb8 @ 00221bb8 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00221bb8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221e40 @ 00221e40 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00221e40(void)

{
  flix();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221e84 @ 00221e84 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00221e84(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00221f98 @ 00221f98 (18 bytes)

void FUN_00221f98(void)

{
  FUN_00221e84();
  flix();
  FUN_0021a017();
  return;
}


// ===== FUN_00222034 @ 00222034 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00222034(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002220a0 @ 002220a0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002220a0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002220e8 @ 002220e8 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002220e8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002221c0 @ 002221c0 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002221c0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002221d0 @ 002221d0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002221d0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00222230 @ 00222230 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00222230(void)

{
  flix();
  cust1();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00222244 @ 00222244 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00222244(void)

{
  DAT_0025b9ca = DAT_20078034;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002222b0 @ 002222b0 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002222b0(void)

{
  int unaff_a11;
  
  acquire(unaff_a11 + 0x318);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022239d @ 0022239d (2 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022239d(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_retaddr;
  
  *(undefined4 *)(param_3 + 0x38) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002224e0 @ 002224e0 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002224e0(int param_1,undefined2 param_2)

{
  flix();
  *(undefined2 *)(param_1 + 10) = param_2;
  *(char *)(param_1 + 0x14) = (char)param_2;
  *(undefined2 *)(param_1 + 8) = param_2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00222510 @ 00222510 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00222510(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00222640 @ 00222640 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00222640(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00222688 @ 00222688 (19 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00222688(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00222ab0 @ 00222ab0 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00222ab0(int param_1,undefined2 param_2)

{
  flix();
  *(undefined2 *)(param_1 + 0xe) = param_2;
  *(char *)(param_1 + 0x21) = (char)param_2;
  *(char *)(param_1 + 0x20) = (char)param_2;
  *(undefined2 *)(param_1 + 0xc) = param_2;
  *(undefined2 *)(param_1 + 10) = param_2;
  *(undefined2 *)(param_1 + 8) = param_2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00222af0 @ 00222af0 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00222af0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00222d00 @ 00222d00 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00222d00(void)

{
  FUN_00222dd4();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

