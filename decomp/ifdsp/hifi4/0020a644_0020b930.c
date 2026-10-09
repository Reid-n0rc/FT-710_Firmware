// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0020a644 @ 0020a644 (9 bytes)

void FUN_0020a644(void)

{
  flix();
  FUN_0020358a();
  return;
}


// ===== FUN_0020a708 @ 0020a708 (51 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a708(int param_1,int param_2)

{
  int in_a7;
  uint in_a14;
  
  flix();
  if (0x7fff < in_a14) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  flix();
  if (param_1 + param_2 * 0x10 + 4 != in_a7) {
    flix();
    func_0x001e2888();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a73c @ 0020a73c (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a73c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a758 @ 0020a758 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

int FUN_0020a758(uint param_1)

{
  uint in_a6;
  int in_a12;
  
  if (in_a12 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return ((param_1 & in_a6) >> 0x10) + 1;
}


// ===== FUN_0020a78c @ 0020a78c (46 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a78c(undefined4 *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined4 unaff_a10;
  
  uVar1 = param_2 >> 8 & 3;
  flix();
  flix();
  if (((param_3 % uVar1 == 0) && (param_4 != 0)) && (param_4 % uVar1 == 0)) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  *param_1 = unaff_a10;
  param_1[1] = unaff_a10;
  param_1[2] = unaff_a10;
  return;
}


// ===== FUN_0020a818 @ 0020a818 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a818(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a94c @ 0020a94c (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a94c(void)

{
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020aa20 @ 0020aa20 (69 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0020aa38) overlaps instruction at (ram,0x0020aa37)
    */

void FUN_0020aa20(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int unaff_retaddr;
  uint uVar1;
  int unaff_a10;
  int in_a14;
  int in_t0;
  
  flix();
  if (unaff_retaddr == 0) {
    memw();
    memw();
    *(uint *)(unaff_a10 + 0x28) = *(uint *)(unaff_a10 + 0x28) | *(uint *)(param_1 + 8);
    param_4 = (uint)*(byte *)(param_1 + 0xc);
    param_3 = (uint)(*(byte *)(param_1 + 0xc) >> 5);
    flix();
    func_0x001ccc18();
    memw();
    uVar1 = *(uint *)(param_3 + 0x38) >> (param_4 & 0x1f);
    while ((uVar1 & 1) != 0) {
      memw();
      uVar1 = *(uint *)(param_3 + 0x38) >> (param_4 & 0x1f);
    }
  }
  else {
    in_t0 = in_a14 + 0xf;
    flix();
    unaff_retaddr = DAT_001cb2a0;
    if (DAT_001cb2a0 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  memw();
  memw();
  *(uint *)(param_3 + 0x78) = *(uint *)(param_3 + 0x78) | in_t0 << 0x20 - (0x20 - (param_4 & 0x1f));
  flix();
  flix();
  if (unaff_retaddr == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020aab4 @ 0020aab4 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020aab4(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020ab28 @ 0020ab28 (9 bytes)

void FUN_0020ab28(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ===== FUN_0020ab34 @ 0020ab34 (78 bytes)

/* WARNING: Instruction at (ram,0x0020ab6a) overlaps instruction at (ram,0x0020ab69)
    */
/* WARNING: Control flow encountered bad instruction data */

void FUN_0020ab34(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  uint unaff_a8;
  undefined1 unaff_a9;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  puVar1 = DAT_001f7b58;
  flix();
  flix();
  flix();
  *(undefined1 *)(DAT_001f7b58 + 6) = unaff_a9;
  puVar1[1] = param_3;
  *puVar1 = param_2;
  *(undefined1 *)(puVar1 + 4) = unaff_a9;
  *(undefined1 *)(puVar1 + 3) = unaff_a9;
  *(undefined1 *)((int)puVar1 + 0x12) = param_4;
  *(undefined1 *)((int)puVar1 + 0x13) = 0;
  flix();
  if (&stack0x00000000 == (undefined1 *)0x20) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar1[2] = param_6;
  flix();
  if ((unaff_a8 & 1 << ((byte)unaff_a8 & 0x1f)) == 0) {
    *(char *)((int)puVar1 + 0xd) = (char)param_6;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020ac04 @ 0020ac04 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020ac04(void)

{
  undefined4 *unaff_retaddr;
  int unaff_a8;
  int in_a14;
  
  flix();
  if (in_a14 == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (unaff_a8 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_retaddr = 0;
  return;
}


// ===== FUN_0020ac54 @ 0020ac54 (66 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0020ac94) overlaps instruction at (ram,0x0020ac93)
    */

void FUN_0020ac54(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_5 != 0) {
    flix();
    *(undefined1 *)(param_1 + 5) = 0;
    param_1[1] = param_3;
    *param_1 = param_2;
    param_1[4] = param_6;
    flix();
    puVar1 = (undefined4 *)(uint)*(ushort *)(iRam00000020 + 0x1e0);
    *(undefined1 *)(puVar1 + 5) = 0;
    puVar1[1] = param_3;
    *puVar1 = param_2;
    puVar1[4] = param_6;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[4] = param_6;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020aca8 @ 0020aca8 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020aca8(void)

{
  int unaff_retaddr;
  int in_a5;
  int in_SCOMPARE1;
  
  flix();
  if (*(int *)(in_a5 + 0x38) == in_SCOMPARE1) {
    *(int *)(in_a5 + 0x38) = unaff_retaddr;
  }
  cust1();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020ad04 @ 0020ad04 (10 bytes)

void FUN_0020ad04(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}


// ===== FUN_0020ad10 @ 0020ad10 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020ad10(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020ad68 @ 0020ad68 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020ad68(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020ad78 @ 0020ad78 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020ad78(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020ae18 @ 0020ae18 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020ae18(void)

{
  int unaff_retaddr;
  int unaff_a8;
  int in_SCOMPARE1;
  
  flix();
  cust1();
  if (*(int *)(unaff_a8 + 0x38) == in_SCOMPARE1) {
    *(int *)(unaff_a8 + 0x38) = unaff_retaddr;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020aed8 @ 0020aed8 (92 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: This function may have set the stack pointer */

void FUN_0020aed8(undefined4 *param_1)

{
  int unaff_retaddr;
  int in_a12;
  uint in_a13;
  undefined4 in_f0;
  
  flix();
  if (unaff_retaddr == param_1[2]) {
    memw();
    *(uint *)(in_a12 + 0x1fc) = *(uint *)(in_a12 + 0x1fc) & in_a13;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  flix();
  if (unaff_retaddr == 0) {
    *param_1 = in_f0;
    func_0x0024f600();
    memw();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0020af38 @ 0020af38 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020af38(void)

{
  undefined4 in_a13;
  undefined4 *in_a14;
  
  flix();
  *in_a14 = in_a13;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b050 @ 0020b050 (11 bytes)

void FUN_0020b050(void)

{
  FUN_0020af38(&DAT_40104000);
  return;
}


// ===== FUN_0020b05c @ 0020b05c (11 bytes)

void FUN_0020b05c(void)

{
  FUN_0020af38(&DAT_40105000);
  return;
}


// ===== FUN_0020b070 @ 0020b070 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b070(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b084 @ 0020b084 (130 bytes)

/* WARNING: This function may have set the stack pointer */

void FUN_0020b084(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int in_a12;
  int in_t0;
  
  iVar1 = FUN_0020b070(param_1);
  uVar2 = *(uint *)(&DAT_002001ac + iVar1 * 4);
  flix();
  cust0();
  *(undefined4 *)(param_3 + 0x1c) = 6;
  flix();
  flix();
  flix();
  if (in_t0 == 5) {
    memw();
    DAT_40021048 = in_a12 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  FUN_00213910(0x318);
  memw();
  *(undefined4 *)(param_1 + 0x80) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x180) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x380) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x480) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x580) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x680) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x780) = 0;
  return;
}


// ===== FUN_0020b164 @ 0020b164 (116 bytes)

void FUN_0020b164(int param_1)

{
  int iVar1;
  uint uVar2;
  int in_a12;
  int in_t0;
  
  iVar1 = FUN_0020b070(param_1);
  uVar2 = *(uint *)(&DAT_002001ac + iVar1 * 4);
  flix();
  cust0();
  *(undefined4 *)(param_1 + 0xc) = 2;
  if (in_t0 == 2) {
    memw();
    DAT_00200424 = in_a12 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (in_t0 == 3) {
    memw();
    DAT_40021070 = in_a12 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (in_t0 == 4) {
    memw();
    DAT_40021074 = in_a12 << 0x20 - (0x20 - (uVar2 & 0x1f));
    return;
  }
  if (in_t0 != 5) {
    return;
  }
  memw();
  DAT_40021078 = in_a12 << 0x20 - (0x20 - (uVar2 & 0x1f));
  return;
}


// ===== FUN_0020b1fc @ 0020b1fc (80 bytes)

void FUN_0020b1fc(int param_1,int param_2)

{
  if (param_2 == 1) {
    memw();
    memw();
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 4;
    memw();
    memw();
    *(uint *)(param_1 + 0x180) = *(uint *)(param_1 + 0x180) | 4;
  }
  else if (param_2 == 2) {
    memw();
    memw();
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 8;
    memw();
    memw();
    *(uint *)(param_1 + 0x180) = *(uint *)(param_1 + 0x180) | 8;
    return;
  }
  return;
}


// ===== FUN_0020b24c @ 0020b24c (55 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b24c(void)

{
  int iVar1;
  int in_a5;
  int in_a6;
  
  flix();
  iVar1 = *(int *)(in_a6 + 0x14);
  cust1();
  memw();
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(in_a5 + 4);
  memw();
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(in_a5 + 8);
  memw();
  *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(in_a5 + 0xc);
  memw();
  *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(in_a5 + 0x10);
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b2d8 @ 0020b2d8 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b2d8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b304 @ 0020b304 (13 bytes)

void FUN_0020b304(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0xf10) = param_2;
  return;
}


// ===== FUN_0020b314 @ 0020b314 (25 bytes)

void FUN_0020b314(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0xf00) = *(uint *)(param_1 + 0xf00) | param_2;
  return;
}


// ===== FUN_0020b330 @ 0020b330 (19 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b330(void)

{
  flix();
  func_0x001cb4e8();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b36c @ 0020b36c (55 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b36c(int param_1)

{
  uint in_a6;
  uint unaff_a11;
  int in_a14;
  
  flix();
  if (in_a14 == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  if (9 < unaff_a11) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | in_a6;
  return;
}


// ===== FUN_0020b3dc @ 0020b3dc (18 bytes)

void FUN_0020b3dc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0020b070(param_1);
  (&DAT_00238578)[iVar1] = param_2;
  return;
}


// ===== FUN_0020b3f0 @ 0020b3f0 (21 bytes)

void FUN_0020b3f0(undefined4 param_1)

{
  FUN_0020b070(param_1);
  flix();
  return;
}


// ===== FUN_0020b408 @ 0020b408 (18 bytes)

void FUN_0020b408(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0020b070(param_1);
  (&DAT_0023857c)[iVar1] = param_2;
  return;
}


// ===== FUN_0020b41c @ 0020b41c (21 bytes)

void FUN_0020b41c(undefined4 param_1)

{
  FUN_0020b070(param_1);
  flix();
  return;
}


// ===== FUN_0020b434 @ 0020b434 (15 bytes)

void FUN_0020b434(void)

{
  if (DAT_00238578 != (code *)0x0) {
    (*DAT_00238578)();
  }
  return;
}


// ===== FUN_0020b444 @ 0020b444 (15 bytes)

void FUN_0020b444(void)

{
  if (DAT_0023857c != (code *)0x0) {
    (*DAT_0023857c)();
  }
  return;
}


// ===== FUN_0020b460 @ 0020b460 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b460(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x18) == 0) {
    memw();
    *(undefined1 *)(param_2 + 0x14) = 0;
  }
  if (*(int *)(param_2 + 8) != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0020b488 @ 0020b488 (9 bytes)

void FUN_0020b488(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  return;
}


// ===== FUN_0020b494 @ 0020b494 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b494(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b4c4 @ 0020b4c4 (37 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0020b4cb) overlaps instruction at (ram,0x0020b4ca)
    */

void FUN_0020b4c4(void)

{
  int iVar1;
  int unaff_a8;
  uint in_a12;
  uint in_a14;
  undefined4 in_f6;
  
  flix();
  if ((in_a14 & in_a12) == 0) {
    flix();
  }
  flix();
  iVar1 = func_0x001a3780();
  *(undefined4 *)(unaff_a8 + 0x110) = in_f6;
  flix();
  if (iVar1 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b74c @ 0020b74c (18 bytes)

void FUN_0020b74c(undefined4 param_1,int param_2)

{
  FUN_0020aa20(*(undefined4 *)(param_2 + 4));
  memw();
  *(undefined1 *)(param_2 + 0x14) = 0;
  return;
}


// ===== FUN_0020b760 @ 0020b760 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b760(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b790 @ 0020b790 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b790(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b7b0 @ 0020b7b0 (33 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020b7b0(undefined4 param_1)

{
  FUN_0020b790(param_1);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020b8e4 @ 0020b8e4 (32 bytes)

void FUN_0020b8e4(undefined4 param_1)

{
  undefined4 unaff_retaddr;
  int iVar1;
  int in_a13;
  undefined4 in_a14;
  
  iVar1 = FUN_0020b790(param_1);
  flix();
  *(undefined4 *)(iVar1 + 0x20) = unaff_retaddr;
  *(undefined4 *)(iVar1 * 4 + 0x10) = in_a14;
  iVar1 = (**(code **)(in_a13 + 4))();
  FUN_0020b790(&DAT_40106000,&DAT_00238580);
  flix();
  flix();
  flix();
  flix();
  *(int *)(iVar1 + 0x28) = iVar1;
  return;
}


// ===== FUN_0020b904 @ 0020b904 (44 bytes)

void FUN_0020b904(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40106000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}


// ===== FUN_0020b930 @ 0020b930 (44 bytes)

void FUN_0020b930(void)

{
  int in_a14;
  
  FUN_0020b790(&DAT_40107000);
  flix();
  flix();
  flix();
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
  return;
}

