// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0020d4d0 @ 0020d4d0 (13 bytes)

void FUN_0020d4d0(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x808) = param_2;
  return;
}


// ===== FUN_0020d4e0 @ 0020d4e0 (13 bytes)

void FUN_0020d4e0(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x80c) = param_2;
  return;
}


// ===== FUN_0020d4f0 @ 0020d4f0 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d4f0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d510 @ 0020d510 (33 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d510(int *param_1)

{
  int unaff_a10;
  int in_a13;
  
  flix();
  *param_1 = unaff_a10;
  param_1[2] = unaff_a10;
  flix();
  *(undefined4 *)(in_a13 + 4) = *(undefined4 *)(unaff_a10 + 4);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d584 @ 0020d584 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d584(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d5a0 @ 0020d5a0 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d5a0(void)

{
  int in_a14;
  
  memw();
  flix();
  *(undefined **)(in_a14 + 0x30) = &DAT_00100000;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d604 @ 0020d604 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d604(void)

{
  flix();
  cust1();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d6d0 @ 0020d6d0 (51 bytes)

/* WARNING: Instruction at (ram,0x0020d6e7) overlaps instruction at (ram,0x0020d6e5)
    */
/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d6d0(uint param_1,uint param_2,int param_3,uint param_4,undefined4 param_5,uint param_6
                 )

{
  uint unaff_retaddr;
  uint uVar1;
  undefined1 *in_a12;
  uint in_a14;
  undefined1 auStack_20 [32];
  
  uVar1 = param_2 * param_3;
  flix();
  while( true ) {
    if ((in_a14 & param_2) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    flix();
    if (param_1 == unaff_retaddr) break;
    uVar1 = (uVar1 / param_6) / param_6;
    param_4 = ((param_4 < uVar1) * param_4 + (param_4 >= uVar1) * uVar1) - 1;
    while (flix(), in_a12 != auStack_20) {
      flix();
      if (param_2 != unaff_retaddr) {
        memw();
        *(uint *)(uVar1 + 0x10) = param_4;
        return;
      }
      *(undefined1 **)(unaff_retaddr + 0x154) = in_a12;
    }
    param_1 = param_1 + 0x178;
    if (unaff_retaddr == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d700 @ 0020d700 (20 bytes)

void FUN_0020d700(void)

{
  undefined4 in_a5;
  
  flix();
                    /* WARNING: Subroutine does not return */
  FUN_0020d5a0(in_a5);
}


// ===== FUN_0020d748 @ 0020d748 (20 bytes)

void FUN_0020d748(void)

{
  undefined4 in_a7;
  
  flix();
                    /* WARNING: Subroutine does not return */
  FUN_0020d5a0(in_a7);
}


// ===== FUN_0020d7b4 @ 0020d7b4 (20 bytes)

void FUN_0020d7b4(void)

{
  undefined4 in_a5;
  
  flix();
                    /* WARNING: Subroutine does not return */
  FUN_0020d5a0(in_a5);
}


// ===== FUN_0020d814 @ 0020d814 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d814(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d8f4 @ 0020d8f4 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d8f4(void)

{
  undefined4 unaff_retaddr;
  int in_a6;
  
  flix();
  *(undefined4 *)(in_a6 + 8) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020da04 @ 0020da04 (20 bytes)

void FUN_0020da04(void)

{
  undefined4 in_a5;
  
  flix();
                    /* WARNING: Subroutine does not return */
  FUN_0020d5a0(in_a5);
}


// ===== FUN_0020da74 @ 0020da74 (34 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020da74(void)

{
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020db88 @ 0020db88 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020db88(void)

{
  undefined4 unaff_retaddr;
  int in_a5;
  
  flix();
  *(undefined4 *)(in_a5 + 0x254) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020dbb8 @ 0020dbb8 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined * FUN_0020dbb8(undefined4 param_1,char *param_2)

{
  if (*param_2 != '\0') {
    return &DAT_00000a28;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020dcb0 @ 0020dcb0 (24 bytes)

undefined4 FUN_0020dcb0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_3 != (undefined4 *)0x0) {
    flix();
    *param_3 = *(undefined4 *)(param_2 + 4);
    return param_1;
  }
  return 4;
}


// ===== FUN_0020dcd4 @ 0020dcd4 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0020dcd4(undefined4 param_1,char *param_2)

{
  if (*param_2 != '\0') {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_0020dd40 @ 0020dd40 (25 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_0020dd40(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020dfe8 @ 0020dfe8 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020dfe8(undefined4 param_1,int param_2,uint param_3)

{
  memw();
  memw();
  *(uint *)(param_2 + 4) = param_3;
  if ((*(int *)(param_2 + 0x30) != 0) && ((*(uint *)(param_2 + 0xc) & param_3) != 0)) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0020e050 @ 0020e050 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e050(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e0c8 @ 0020e0c8 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e0c8(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e140 @ 0020e140 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e140(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e160 @ 0020e160 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e160(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e18c @ 0020e18c (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e18c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e248 @ 0020e248 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e248(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e258 @ 0020e258 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e258(undefined4 param_1,int param_2)

{
  undefined4 unaff_retaddr;
  
  flix();
  *(undefined4 *)(param_2 + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e31c @ 0020e31c (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e31c(undefined4 param_1,int param_2)

{
  undefined4 unaff_retaddr;
  
  flix();
  *(undefined4 *)(param_2 + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e3e0 @ 0020e3e0 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e3e0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e41c @ 0020e41c (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e41c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e490 @ 0020e490 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e490(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e4bc @ 0020e4bc (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e4bc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e4e8 @ 0020e4e8 (65 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0020e4ef) overlaps instruction at (ram,0x0020e4ee)
    */

undefined4 FUN_0020e4e8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int extraout_a5;
  int unaff_a9;
  int in_SAR;
  undefined8 uVar1;
  
  uVar1 = CONCAT44(param_2,param_1);
  do {
    flix();
    uVar1 = func_0x001d6dd4((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),param_3,(int)uVar1 + 0x600);
    memw();
    param_3 = *(undefined4 *)(extraout_a5 + 0x1dc);
    flix();
    flix();
    flix();
  } while (unaff_a9 >> in_SAR == (int)uVar1);
  flix();
  memw();
  flix();
  if (*(int *)((int)((ulonglong)uVar1 >> 0x20) + 0x2c) != 3) {
    return DAT_001fd118;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e5cc @ 0020e5cc (93 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e5cc(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  int unaff_a9;
  int in_a12;
  uint in_a15;
  
  memw();
  if ((*(int *)(param_2 + 0x10) != 0) && (unaff_a9 != 0)) {
    memw();
    *(undefined4 *)(param_4 + 0x218) = param_3;
    memw();
    in_a15 = *(uint *)(param_4 + 0x21c) & 0xff;
    memw();
    **(undefined1 **)(param_2 + 0x10) = (char)*(uint *)(param_4 + 0x21c);
    memw();
    memw();
    *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + -1;
    memw();
    memw();
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    memw();
    in_a12 = *(int *)(param_2 + 0x20) + 1;
    memw();
    *(int *)(param_2 + 0x20) = in_a12;
  }
  memw();
  memw();
  flix();
  *(undefined4 *)(in_a15 + 0x1c) = param_6;
  *(int *)(param_5 + 0x3c) = in_a12;
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e720 @ 0020e720 (13 bytes)

void FUN_0020e720(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x808) = param_2;
  return;
}


// ===== FUN_0020e730 @ 0020e730 (13 bytes)

void FUN_0020e730(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x80c) = param_2;
  return;
}


// ===== FUN_0020e740 @ 0020e740 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020e740(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020e7d0 @ 0020e7d0 (13 bytes)

void FUN_0020e7d0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0020d5a0(param_1);
  }
  return;
}


// ===== FUN_0020eaec @ 0020eaec (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020eaec(int param_1)

{
  if (param_1 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0020eb84 @ 0020eb84 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020eb84(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int in_a13;
  
  flix();
  if (in_a13 < param_1) {
    FUN_0020d4f0(param_2,1);
  }
  *(undefined4 *)(param_2 + 0x40) = param_4;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020ebd0 @ 0020ebd0 (39 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined * FUN_0020ebd0(byte param_1,char *param_2)

{
  undefined4 unaff_retaddr;
  uint in_t0;
  
  if (*param_2 != '\0') {
    return &DAT_00000a28;
  }
  flix();
  func_0x001eed04();
  flix();
  if ((in_t0 & 1 << (param_1 & 0x1f)) != 0) {
    flix();
    *(undefined4 *)(in_t0 + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020eccc @ 0020eccc (24 bytes)

undefined4 FUN_0020eccc(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_3 != (undefined4 *)0x0) {
    flix();
    *param_3 = *(undefined4 *)(param_2 + 4);
    return param_1;
  }
  return 4;
}


// ===== FUN_0020ecf0 @ 0020ecf0 (95 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0020ecf0(int param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 )

{
  undefined4 unaff_retaddr;
  int iVar1;
  int in_a13;
  undefined4 in_a14;
  int in_t0;
  
  if (*param_2 == '\0') {
    return;
  }
  iVar1 = FUN_0020aa20(*(undefined4 *)(param_2 + 0x1c));
  flix();
  if (param_1 != 0) {
    memw();
    *(undefined4 *)(param_1 + 0x80c) = param_5;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined4 *)(in_t0 + 0x34) = unaff_retaddr;
  _DAT_00000600 = in_a14;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  if (in_a13 == 0x100) {
    memw();
    uRam00000020 = 0x600;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020ed70 @ 0020ed70 (13 bytes)

void FUN_0020ed70(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0xe10) = param_2;
  return;
}


// ===== FUN_0020ed80 @ 0020ed80 (13 bytes)

void FUN_0020ed80(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0xe14) = param_2;
  return;
}


// ===== FUN_0020ed90 @ 0020ed90 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020ed90(void)

{
  int unaff_retaddr;
  
  flix();
  if (unaff_retaddr == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020edac @ 0020edac (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020edac(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020eecc @ 0020eecc (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020eecc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020efdc @ 0020efdc (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020efdc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

