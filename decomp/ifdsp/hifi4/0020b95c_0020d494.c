// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0020b95c @ 0020b95c (44 bytes)

void FUN_0020b95c(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40108000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020b988 @ 0020b988 (24 bytes)

void FUN_0020b988(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40109000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020b9a0 @ 0020b9a0 (20 bytes)

void FUN_0020b9a0(void)

{
  int in_a14;
  
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020b9b4 @ 0020b9b4 (44 bytes)

void FUN_0020b9b4(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40122000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020b9e0 @ 0020b9e0 (44 bytes)

void FUN_0020b9e0(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40123000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020ba0c @ 0020ba0c (44 bytes)

void FUN_0020ba0c(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40124000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020ba38 @ 0020ba38 (44 bytes)

void FUN_0020ba38(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40125000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020ba64 @ 0020ba64 (44 bytes)

void FUN_0020ba64(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40126000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020ba90 @ 0020ba90 (44 bytes)

void FUN_0020ba90(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40127000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020bac0 @ 0020bac0 (18 bytes)

void FUN_0020bac0(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | param_2;
  return;
}


// ===== FUN_0020bad4 @ 0020bad4 (23 bytes)

void FUN_0020bad4(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & (param_2 ^ 0xffffffff);
  return;
}


// ===== FUN_0020baec @ 0020baec (18 bytes)

void FUN_0020baec(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | param_2;
  return;
}


// ===== FUN_0020bb00 @ 0020bb00 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020bb00(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020bb14 @ 0020bb14 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020bb14(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020bb74 @ 0020bb74 (159 bytes)
// decompile failed: Exception while decompiling 0020bb74: Decompiler process died


// ===== FUN_0020be6c @ 0020be6c (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020be6c(void)

{
  flix();
  FUN_00208f5c();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020bf30 @ 0020bf30 (42 bytes)

void FUN_0020bf30(uint *param_1)

{
  uint uVar1;
  
  memw();
  memw();
  *param_1 = *param_1 | 1;
  memw();
  uVar1 = *param_1;
  while ((uVar1 & 1) != 0) {
    memw();
    uVar1 = *param_1;
  }
  return;
}


// ===== FUN_0020bf5c @ 0020bf5c (205 bytes)

/* WARNING: Instruction at (ram,0x0020bfce) overlaps instruction at (ram,0x0020bfcc)
    */
/* WARNING: Control flow encountered bad instruction data */

void FUN_0020bf5c(uint *param_1,uint *param_2,uint param_3)

{
  int unaff_retaddr;
  uint uVar1;
  uint uVar2;
  uint unaff_a9;
  undefined4 *puVar3;
  int in_a14;
  
  memw();
  uVar1 = param_1[0x38];
  if ((uVar1 & 2) == 0) {
    do {
      do {
        memw();
      } while ((param_1[0x38] & 2) == 0);
      memw();
      unaff_a9 = param_1[0x38];
    } while ((unaff_a9 & 1) == 0);
  }
  else {
    memw();
    uVar1 = param_1[0x38];
    flix();
  }
  memw();
  uVar2 = (*param_1 & 0x30) >> 4;
  if ((((uVar2 == 0) || (uVar2 == 1)) || (uVar2 == 2)) ||
     ((uVar2 != 3 || ((char)param_2[1] != '\0')))) {
    uVar2 = 0x100;
  }
  else {
    unaff_a9 = 99999999;
    if (*param_2 < 100000000) {
      flix();
      *(undefined4 *)(in_a14 + 0x10) = 99999999;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar2 = 0x79;
  }
  puVar3 = (undefined4 *)(param_3 >> 1 & 0x7f);
  memw();
  param_1[(int)(puVar3 + 0xc)] = uVar2;
  memw();
  memw();
  flix();
  *(int *)(unaff_a9 + 4) = unaff_retaddr;
  cust0();
  *puVar3 = &DAT_00030000;
  if (unaff_retaddr * 8 - uVar1 == 0) {
    flix();
    licw(0);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  uVar1 = ~*(uint *)(&stack0x000000c8 + unaff_retaddr) & (uint)&DAT_00030000;
  while (uVar1 != 0) {
    memw();
    uVar1 = ~*(uint *)(&stack0x000000c8 + unaff_retaddr) & (uint)&DAT_00030000;
  }
  return;
}


// ===== FUN_0020c03c @ 0020c03c (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c03c(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c224 @ 0020c224 (91 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0020c255) overlaps instruction at (ram,0x0020c253)
    */

void FUN_0020c224(void)

{
  ushort uVar1;
  int in_a7;
  uint unaff_a9;
  int unaff_a11;
  uint uVar2;
  undefined4 in_f0;
  
  flix();
  flix();
  uVar1 = *(ushort *)(unaff_a11 + 0x1fa);
  memw();
  if ((*(uint *)(in_a7 + 0xe0) & 2) == 0) goto LAB_0020c244;
  memw();
  uVar2 = *(uint *)(in_a7 + 0xe0);
  while ((uVar2 & 1) == 0) {
LAB_0020c244:
    do {
      memw();
    } while ((*(uint *)(in_a7 + 0xe0) & 2) == 0);
    memw();
    uVar2 = *(uint *)(in_a7 + 0xe0);
  }
  memw();
  *(undefined4 *)(in_a7 + 0x18) = 0x5af05af0;
  memw();
  flix();
  if (unaff_a9 != uVar1) {
    *(undefined4 *)(*(uint *)(in_a7 + 0xe0) + 0x3e4) = in_f0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c2a8 @ 0020c2a8 (64 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c2a8(int param_1)

{
  uint uVar1;
  
  memw();
  if ((*(uint *)(param_1 + 0xe0) & 2) == 0) goto LAB_0020c2bc;
  memw();
  uVar1 = *(uint *)(param_1 + 0xe0);
  while ((uVar1 & 1) == 0) {
LAB_0020c2bc:
    do {
      memw();
    } while ((*(uint *)(param_1 + 0xe0) & 2) == 0);
    memw();
    uVar1 = *(uint *)(param_1 + 0xe0);
  }
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c320 @ 0020c320 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c320(void)

{
  memw();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c3cc @ 0020c3cc (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c3cc(void)

{
  memw();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c4d0 @ 0020c4d0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c4d0(void)

{
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c5e4 @ 0020c5e4 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c5e4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0020bb00(param_1);
  *(undefined4 *)(param_2 + 0x10) = param_3;
  *(undefined4 *)(param_2 + 0x14) = param_4;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c610 @ 0020c610 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined * FUN_0020c610(undefined4 param_1,int *param_2)

{
  if (*param_2 != 0) {
    return &DAT_00001b58;
  }
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c63c @ 0020c63c (7 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c63c(undefined4 param_1,undefined4 *param_2)

{
  undefined4 unaff_a10;
  
  *param_2 = unaff_a10;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c6f8 @ 0020c6f8 (24 bytes)

void FUN_0020c6f8(void)

{
  int iVar1;
  int in_a6;
  undefined4 *in_t0;
  
  flix();
  iVar1 = *(int *)(in_a6 + 4);
  FUN_0020c730();
  *in_t0 = *(undefined4 *)(iVar1 + 0x30);
  return;
}


// ===== FUN_0020c714 @ 0020c714 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c714(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c728 @ 0020c728 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c728(int param_1)

{
  memw();
  memw();
  if ((*(uint *)(param_1 + 0x10) & *(uint *)(param_1 + 0x14)) != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0020c730 @ 0020c730 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c730(int param_1,undefined4 param_2,uint param_3)

{
  memw();
  if ((*(uint *)(param_1 + 0x10) & param_3) != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0020c92c @ 0020c92c (18 bytes)

void FUN_0020c92c(void)

{
  (*DAT_002385d8)(&DAT_40134000,DAT_002385dc);
  return;
}


// ===== FUN_0020c940 @ 0020c940 (72 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c940(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    iVar1 = *param_2;
    memw();
    if ((*(uint *)(iVar1 + 0xe0) & 2) == 0) goto LAB_0020c954;
    memw();
    uVar2 = *(uint *)(iVar1 + 0xe0);
    while ((uVar2 & 1) == 0) {
LAB_0020c954:
      do {
        memw();
      } while ((*(uint *)(iVar1 + 0xe0) & 2) == 0);
      memw();
      uVar2 = *(uint *)(iVar1 + 0xe0);
    }
    FUN_0020d01c(iVar1,param_2[1]);
    if (*(int *)(param_2[1] + 0x18) != 0) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return;
}


// ===== FUN_0020c990 @ 0020c990 (19 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c990(undefined4 param_1)

{
  FUN_0020bb00(param_1);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020c9c8 @ 0020c9c8 (7 bytes)

void FUN_0020c9c8(undefined4 param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0xc) = param_3;
  return;
}


// ===== FUN_0020c9d0 @ 0020c9d0 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020c9d0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020cac5 @ 0020cac5 (5 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020cac5(undefined4 param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x14) = param_3;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d01c @ 0020d01c (49 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d01c(int param_1,int param_2)

{
  undefined4 unaff_a10;
  
  memw();
  if ((*(uint *)(param_1 + 0xbc) & 2) == 0) {
    memw();
    flix();
    *(undefined4 *)(param_2 + 0x14) = unaff_a10;
    return;
  }
  memw();
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d070 @ 0020d070 (81 bytes)

int FUN_0020d070(int param_1,int param_2)

{
  if (*(int *)(param_2 + 0x14) != 1) {
    return 6;
  }
  memw();
  if ((*(uint *)(param_1 + 0xb8) & 2) == 0) {
    memw();
    flix();
    flix();
    flix();
    return param_1;
  }
  flix();
  flix();
  return param_1;
}


// ===== FUN_0020d0d0 @ 0020d0d0 (47 bytes)

void FUN_0020d0d0(void)

{
  int unaff_a8;
  int in_a14;
  int in_SCOMPARE1;
  
  memw();
  flix();
  cust1();
  flix();
  if (*(int *)(in_a14 + 0x200) == in_SCOMPARE1) {
    *(int *)(in_a14 + 0x200) = unaff_a8;
  }
  do {
    ill();
  } while( true );
}


// ===== FUN_0020d100 @ 0020d100 (21 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d100(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d1a4 @ 0020d1a4 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d1a4(void)

{
  flix();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d2b0 @ 0020d2b0 (60 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d2b0(uint param_1,undefined4 param_2,uint param_3,uint param_4,int param_5)

{
  int unaff_retaddr;
  int iVar1;
  uint unaff_a9;
  uint unaff_a10;
  uint unaff_a11;
  int in_a13;
  int in_a14;
  uint in_a15;
  
  flix();
  if (in_a14 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar1 = *(int *)(in_a13 + 0x14);
  if (unaff_retaddr == 0) {
    if ((in_a15 & param_1) == 0) {
      memw();
      *(uint *)(iVar1 + 0x23c) = unaff_a10 | unaff_a11;
      memw();
      memw();
      *(uint *)(iVar1 + 0x1bc) =
           *(uint *)(iVar1 + 0x1bc) & unaff_a9 |
           (uint)*(byte *)(param_4 + 1) << 0x20 - (0x20 - (param_3 & 0x1f));
      return;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  memw();
  *(uint *)(param_5 + 0x280) = *(uint *)(param_5 + 0x280) | param_4;
  return;
}


// ===== FUN_0020d300 @ 0020d300 (62 bytes)

void FUN_0020d300(int param_1,int param_2,int param_3,uint param_4)

{
  if (param_3 == 0) {
    param_1 = param_2 * 4 + param_1;
    memw();
    memw();
    *(uint *)(&DAT_00002500 + param_1) = *(uint *)(&DAT_00002500 + param_1) | param_4;
    return;
  }
  if (param_3 != 1) {
    return;
  }
  param_1 = param_2 * 4 + param_1;
  memw();
  memw();
  *(uint *)(&DAT_00002580 + param_1) = *(uint *)(&DAT_00002580 + param_1) | param_4;
  return;
}


// ===== FUN_0020d340 @ 0020d340 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d340(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d38c @ 0020d38c (43 bytes)

void FUN_0020d38c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    memw();
    *(undefined4 *)(&DAT_00002700 + param_2 * 4 + param_1) = param_4;
    return;
  }
  if (param_3 != 1) {
    return;
  }
  memw();
  *(undefined4 *)(&DAT_00002780 + param_2 * 4 + param_1) = param_4;
  return;
}


// ===== FUN_0020d3b8 @ 0020d3b8 (45 bytes)

undefined4 FUN_0020d3b8(int param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    memw();
    return *(undefined4 *)(&DAT_00002700 + param_2 * 4 + param_1);
  }
  if (param_3 != 1) {
    return 0;
  }
  memw();
  return *(undefined4 *)(&DAT_00002780 + param_2 * 4 + param_1);
}


// ===== FUN_0020d3e8 @ 0020d3e8 (46 bytes)

/* WARNING: Removing unreachable block (ram,0x0020d405) */

int FUN_0020d3e8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  flix();
  if (param_4 == 1) {
    flix();
    flix();
    return (int)*(short *)(param_2 + 0x1f8);
  }
  return DAT_001fbff0;
}


// ===== FUN_0020d438 @ 0020d438 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020d438(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020d494 @ 0020d494 (43 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0020d4b1) */

undefined4 FUN_0020d494(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_retaddr;
  undefined4 in_a12;
  
  flix();
  if (param_4 == 1) {
    flix();
    flix();
    flix();
    *(undefined4 *)(unaff_retaddr + 0x30) = in_a12;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return param_1;
}

