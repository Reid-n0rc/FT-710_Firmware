// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00208be0 @ 00208be0 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208be0(void)

{
  undefined4 in_a5;
  int in_a14;
  
  flix();
  *(undefined4 *)(in_a14 + 0xc) = in_a5;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208d94 @ 00208d94 (105 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208d94(int param_1)

{
  flix();
  flix();
  memw();
  memw();
  memw();
  if ((*(uint *)(&DAT_40021500 + param_1 * 0x20) & 7) == 0) {
    FUN_00208958(&DAT_0000ff00,&DAT_40021600);
  }
  else {
    flix();
    if ((*(uint *)(&DAT_40021500 + param_1 * 0x20) & 7) != 2) {
      flix();
    }
  }
  flix();
  cust0();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208e90 @ 00208e90 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208e90(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208f10 @ 00208f10 (92 bytes)

uint FUN_00208f10(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  memw();
  uVar2 = *(uint *)(&DAT_40021720 + param_1 * 4) & 7;
  if (uVar2 == 0) {
    uVar2 = FUN_00208958();
    return uVar2;
  }
  if (uVar2 == 1) {
    return 16000000;
  }
  if (uVar2 == 2) {
    uVar2 = FUN_002086b4();
    return uVar2;
  }
  if (uVar2 != 3) {
    if (uVar2 != 4) {
      flix();
      return param_1;
    }
    memw();
    return DAT_00238424;
  }
  uVar1 = FUN_002088a8(0);
  memw();
  uVar2 = DAT_40021240;
  return uVar1 / ((uVar2 & 0xff) + 1);
}


// ===== FUN_00208f5c @ 00208f5c (2 bytes)

void FUN_00208f5c(void)

{
  return;
}


// ===== FUN_00208f78 @ 00208f78 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_00208f78(void)

{
  undefined4 uVar1;
  undefined4 in_a5;
  undefined4 *in_a15;
  
  memw();
  uVar1 = DAT_40001620;
  flix();
  *in_a15 = in_a5;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209038 @ 00209038 (29 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_00209038(void)

{
  undefined4 uVar1;
  undefined4 in_a5;
  undefined4 *in_a15;
  
  memw();
  uVar1 = DAT_40001640;
  flix();
  *in_a15 = in_a5;
  FUN_002222b0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209130 @ 00209130 (62 bytes)

uint FUN_00209130(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint unaff_a10;
  
  memw();
  iVar1 = DAT_40021740;
  if (iVar1 != 0) {
    memw();
    uVar2 = DAT_40021740;
    flix();
    memw();
    uVar3 = DAT_40021744;
    return unaff_a10 / ((uVar3 & 0xff) + 1);
  }
  uVar4 = FUN_002086b4();
  memw();
  uVar3 = DAT_40021744;
  return uVar4 / ((uVar3 & 0xff) + 1);
}


// ===== FUN_00209194 @ 00209194 (43 bytes)

void FUN_00209194(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *in_a15;
  
  if (param_1 != 0) {
    memw();
    uVar1 = DAT_400217a0;
    flix();
    return;
  }
  memw();
  uVar1 = DAT_40001720;
  flix();
  *in_a15 = param_3;
  return;
}


// ===== FUN_002091d0 @ 002091d0 (75 bytes)

undefined * FUN_002091d0(void)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  undefined *unaff_a8;
  
  memw();
  iVar2 = DAT_40001760;
  if (iVar2 == 0) {
    uVar4 = FUN_00208958();
    memw();
    uVar1 = DAT_40001764;
    return (undefined *)(uVar4 / ((uVar1 & 0xff) + 1));
  }
  if (iVar2 != 1) {
    if (iVar2 != 2) {
      flix();
      return &DAT_40001600;
    }
    flix();
    memw();
    uVar1 = DAT_400011c0;
    puVar3 = &DAT_40001600;
    if ((uVar1 & 1) != 0) {
      puVar3 = unaff_a8;
    }
    return puVar3;
  }
  return &DAT_000f4240;
}


// ===== FUN_00209220 @ 00209220 (39 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209220(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_a15;
  
  memw();
  flix();
  *in_a15 = param_3;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002092f4 @ 002092f4 (58 bytes)

uint FUN_002092f4(void)

{
  uint uVar1;
  uint uVar2;
  uint unaff_a10;
  
  memw();
  uVar1 = DAT_40021780;
  if ((uVar1 & 7) != 0) {
    flix();
    memw();
    uVar1 = DAT_40021790;
    return unaff_a10 / ((uVar1 & 0xff) + 1);
  }
  uVar2 = FUN_00208958();
  memw();
  uVar1 = DAT_40021790;
  return uVar2 / ((uVar1 & 0xff) + 1);
}


// ===== FUN_00209344 @ 00209344 (93 bytes)

/* WARNING: Control flow encountered bad instruction data */

uint FUN_00209344(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint unaff_a10;
  
  memw();
  iVar1 = DAT_40001660;
  if (iVar1 != 0) {
    memw();
    uVar2 = DAT_40001660;
    flix();
    memw();
    uVar3 = DAT_40001664;
    return unaff_a10 / ((uVar3 & 0xff) + 1);
  }
  memw();
  iVar1 = DAT_40001168;
  if (iVar1 != 0) {
    memw();
    memw();
    uVar2 = DAT_40001168;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  memw();
  uVar3 = DAT_40001664;
  return DAT_00238420 / ((uVar3 & 0xff) + 1);
}


// ===== FUN_002093cc @ 002093cc (140 bytes)

/* WARNING: Control flow encountered bad instruction data */

uint FUN_002093cc(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  memw();
  uVar1 = DAT_40021700;
  if ((uVar1 & 7) == 0) {
    memw();
    uVar1 = DAT_40021704;
    return 16000000 / ((uVar1 & 0xff) + 1);
  }
  flix();
  flix();
  flix();
  flix();
  if ((uVar1 & 7) != 5) {
    memw();
    uVar2 = DAT_40021704;
    return 0;
  }
  memw();
  uVar1 = DAT_40001730;
  if ((uVar1 & 7) != 0) {
    memw();
    uVar1 = DAT_40001734;
    memw();
    uVar3 = DAT_40021704;
    return ((uint)&DAT_000f4240 / ((uVar1 & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002094dc @ 002094dc (144 bytes)

uint FUN_002094dc(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_a10;
  
  memw();
  uVar3 = DAT_400217c0;
  uVar3 = uVar3 & 7;
  if (uVar3 == 0) {
    uVar1 = FUN_00208958();
    memw();
    uVar3 = DAT_400217c4;
    return uVar1 / ((uVar3 & 0xff) + 1);
  }
  if (uVar3 == 1) {
    memw();
    uVar3 = DAT_400217c4;
    return 16000000 / ((uVar3 & 0xff) + 1);
  }
  if (uVar3 == 2) {
    uVar1 = FUN_002086b4();
    memw();
    uVar3 = DAT_400217c4;
    return uVar1 / ((uVar3 & 0xff) + 1);
  }
  if (uVar3 != 3) {
    flix();
    memw();
    uVar3 = DAT_400217c4;
    return unaff_a10 / ((uVar3 & 0xff) + 1);
  }
  uVar2 = FUN_0020876c(2);
  memw();
  uVar3 = DAT_40001248;
  memw();
  uVar1 = DAT_400217c4;
  return (uVar2 / ((uVar3 & 0xff) + 1)) / ((uVar1 & 0xff) + 1);
}


// ===== FUN_00209590 @ 00209590 (41 bytes)

/* WARNING: Removing unreachable block (ram,0x00209531) */

undefined4 FUN_00209590(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *in_a15;
  
  flix();
                    /* WARNING: Could not recover jumptable at 0x002095a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2,*in_a15);
  return uVar1;
}


// ===== FUN_0020969c @ 0020969c (21 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020969c(void)

{
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209720 @ 00209720 (157 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209720(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  undefined *in_a14;
  
  puVar1 = &DAT_40002600;
  uVar2 = 0xff00ffff;
  memw();
  DAT_40002620 = &DAT_00060000;
  memw();
  DAT_40001200 = *param_1;
  memw();
  DAT_40001210 = param_1[1];
  memw();
  DAT_40001214 = param_1[2];
  if (param_1[3] == 0) {
    memw();
    uVar2 = DAT_40001204;
    in_a14 = (undefined *)(uVar2 & 0xff00ffff | (uint)&DAT_00100000);
    memw();
    DAT_40001204 = in_a14;
  }
  else {
    flix();
    flix();
    flix();
    flix();
    flix();
    if (param_1[3] == 6) {
      in_a14 = &DAT_00160000;
      memw();
      uVar3 = DAT_40001204;
      goto LAB_002097e0;
    }
  }
  while( true ) {
    uVar3 = 0xfffffffd;
    memw();
    uVar2 = DAT_40001204;
    uVar2 = uVar2 & 0xfffffffd;
    memw();
    DAT_40001204 = uVar2;
    memw();
    *(undefined **)(puVar1 + 0x30) = &DAT_00060000;
    memw();
    puVar1 = (undefined *)DAT_4000120c;
    flix();
    if ((int)uVar2 <= param_4) break;
LAB_002097e0:
    memw();
    DAT_40001204 = uVar3 & uVar2 | (uint)in_a14;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209878 @ 00209878 (65 bytes)

/* WARNING: Control flow encountered bad instruction data */

uint FUN_00209878(uint param_1,int param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int unaff_a9;
  uint unaff_a10;
  int in_a12;
  int in_a14;
  int in_SAR;
  undefined1 auStack_20 [32];
  
  flix();
  *(undefined1 **)(in_a12 + 0x34) = auStack_20;
  if (param_1 == 0) {
    *param_3 = in_a14 + 0x2fc;
    if (unaff_a9 != 1) {
      flix();
      flix();
      flix();
      memw();
      return unaff_a10 / ((uRam00000000 & 0xff) + 1);
    }
    uVar2 = FUN_0020876c(0);
    memw();
    memw();
    return (uVar2 / ((*(uint *)(param_2 + 0x40) & 0xff) + 1)) / ((uRam00000000 & 0xff) + 1);
  }
  if (in_a14 + 0x2fc == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = param_4 << 0x20 - in_SAR;
  memw();
  uVar2 = *(uint *)(param_1 + 0x18);
  while ((uVar2 & uVar1) == 0) {
    memw();
    uVar2 = *(uint *)(param_1 + 0x18);
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | uVar1;
  return param_1;
}


// ===== FUN_002098ec @ 002098ec (174 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002098ec(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined *in_a15;
  undefined4 in_f15;
  
  memw();
  DAT_40002620 = &DAT_00180000;
  memw();
  DAT_40021200 = *param_1;
  memw();
  DAT_40021210 = param_1[1];
  memw();
  DAT_40021214 = param_1[2];
  if (param_1[3] == 0) {
    in_a15 = &DAT_00100000;
    memw();
    uVar1 = DAT_40021204;
    memw();
    DAT_40021204 = uVar1 & 0xff00ffff | (uint)&DAT_00100000;
  }
  else {
    flix();
    flix();
    flix();
    flix();
    flix();
    if (param_1[3] == 6) {
      memw();
      uVar1 = DAT_40021204;
      memw();
      DAT_40021204 = uVar1 & 0xff00ffff | (uint)&DAT_00160000;
    }
  }
  memw();
  uVar1 = DAT_40021204;
  memw();
  DAT_40021204 = uVar1 & 0xfffffffd;
  memw();
  DAT_40002630 = &DAT_00180000;
  memw();
  uVar2 = DAT_4002120c;
  flix();
  if ((param_4 & 0x1000) != 0) {
    *(undefined4 *)(in_a15 + 0x40021280) = in_f15;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DAT_40021204 = &DAT_00180000;
  memw();
  uVar2 = DAT_4002120c;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209a40 @ 00209a40 (65 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209a40(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int in_a12;
  int in_a14;
  int in_SAR;
  undefined1 auStack_20 [32];
  
  flix();
  *(undefined1 **)(in_a12 + 0x34) = auStack_20;
  if (param_1 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (in_a14 == -0x2fc) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = param_4 << 0x20 - in_SAR;
  memw();
  uVar2 = *(uint *)(param_1 + 0x18);
  while ((uVar2 & uVar1) == 0) {
    memw();
    uVar2 = *(uint *)(param_1 + 0x18);
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | uVar1;
  return;
}


// ===== FUN_00209ab4 @ 00209ab4 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209ab4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209ae8 @ 00209ae8 (35 bytes)

void FUN_00209ae8(void)

{
  memw();
  DAT_40001040 = &DAT_00100000;
  memw();
  DAT_40001040 = &DAT_00200000;
  memw();
  DAT_40001040 = 0x800000;
  return;
}


// ===== FUN_00209b0c @ 00209b0c (35 bytes)

void FUN_00209b0c(void)

{
  memw();
  DAT_40001040 = &DAT_00100000;
  memw();
  DAT_40001040 = &DAT_00400000;
  memw();
  DAT_40001040 = 0x800000;
  return;
}


// ===== FUN_00209b30 @ 00209b30 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209b30(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209c10 @ 00209c10 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209c10(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209c54 @ 00209c54 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209c54(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209c70 @ 00209c70 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209c70(int param_1)

{
  if (param_1 != 0) {
    FUN_00236470();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_00209d20 @ 00209d20 (25 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209d20(int param_1)

{
  undefined4 unaff_retaddr;
  
  memw();
  flix();
  *(undefined4 *)(param_1 + 0x3c) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209d88 @ 00209d88 (51 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00209dc0) */

void FUN_00209d88(undefined4 param_1,int param_2,undefined2 param_3)

{
  int in_a14;
  
  flix();
  flix();
  if (in_a14 == 0) {
    *(undefined2 *)(param_2 + 0x12) = param_3;
    flix();
    dhi(param_2 + 0x10);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209dcc @ 00209dcc (10 bytes)

void FUN_00209dcc(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}


// ===== FUN_00209dd8 @ 00209dd8 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209dd8(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209e18 @ 00209e18 (69 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0020995c) */

void FUN_00209e18(undefined4 param_1,uint param_2,uint param_3)

{
  int unaff_retaddr;
  int unaff_a10;
  undefined4 unaff_a11;
  uint in_a14;
  uint in_a15;
  
  flix();
  if ((param_2 & 3) != 0) {
    memw();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  if (unaff_retaddr == 0) {
    memw();
    *(uint *)(param_2 + 4) = in_a14 | in_a15;
    memw();
    memw();
    *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
    memw();
    *(undefined4 *)(unaff_a10 + 0x30) = unaff_a11;
    memw();
    flix();
    *(undefined4 *)(param_2 + 4) = unaff_a11;
    memw();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  param_3 = param_3 >> 2;
  if ((param_3 != 0) && ((param_3 == 1 || (param_3 != 0)))) {
    memw();
    flix();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209e90 @ 00209e90 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209e90(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00209f9c @ 00209f9c (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00209f9c(undefined4 param_1,int param_2)

{
  int in_a15;
  
  flix();
  if (in_a15 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  dhi(param_2 + 0x10);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a05c @ 0020a05c (13 bytes)

void FUN_0020a05c(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ===== FUN_0020a06c @ 0020a06c (33 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a06c(void)

{
  int in_a6;
  
  memw();
  flix();
  cust1();
  ipf(in_a6 + 0x2a0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a138 @ 0020a138 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a138(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a1cc @ 0020a1cc (48 bytes)

void FUN_0020a1cc(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 unaff_a8;
  int unaff_a9;
  
  memw();
  if (param_4 != 0) {
    memw();
    *(uint *)(param_3 * 4 + param_1 + 0x18) =
         (uint)(*(int *)(param_2 * 4 + param_1 + 0x18) * (100 - param_4)) / 100;
    return;
  }
  flix();
  memw();
  *(undefined4 *)(unaff_a9 + 0x18) = unaff_a8;
  return;
}


// ===== FUN_0020a200 @ 0020a200 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a200(void)

{
  flix();
  func_0x001ea2f8();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a2bc @ 0020a2bc (13 bytes)

uint FUN_0020a2bc(int param_1,uint param_2)

{
  memw();
  return *(uint *)(param_1 + 0x3c) & param_2;
}


// ===== FUN_0020a2cc @ 0020a2cc (12 bytes)

void FUN_0020a2cc(void)

{
  memw();
  flix();
  FUN_00202315();
  return;
}


// ===== FUN_0020a330 @ 0020a330 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a330(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a378 @ 0020a378 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a378(void)

{
  undefined4 uVar1;
  
  memw();
  uVar1 = DAT_40028000;
  memw();
  flix();
  uVar1 = DAT_40027e24;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a3c4 @ 0020a3c4 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a3c4(void)

{
  undefined4 uVar1;
  
  memw();
  uVar1 = DAT_40029000;
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a410 @ 0020a410 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a410(void)

{
  undefined4 uVar1;
  
  memw();
  uVar1 = DAT_4002a000;
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a45c @ 0020a45c (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a45c(void)

{
  undefined4 uVar1;
  
  memw();
  uVar1 = DAT_4002b000;
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a4a8 @ 0020a4a8 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a4a8(void)

{
  undefined4 uVar1;
  
  memw();
  uVar1 = DAT_4002c000;
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a500 @ 0020a500 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a500(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020a528 @ 0020a528 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020a528(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

