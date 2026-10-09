// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_002151f0 @ 002151f0 (19 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002151f0(void)

{
  undefined4 unaff_retaddr;
  int in_a6;
  
  flix();
  *(undefined4 *)(in_a6 + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215228 @ 00215228 (31 bytes)

void FUN_00215228(undefined4 param_1,undefined1 *param_2)

{
  FUN_0020aa20(*(undefined4 *)(param_2 + 4));
  FUN_0020aa20(*(undefined4 *)(param_2 + 8));
  memw();
  *param_2 = 0;
  memw();
  param_2[1] = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  return;
}


// ===== FUN_00215248 @ 00215248 (19 bytes)

undefined4 FUN_00215248(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    flix();
    uVar1 = FUN_00202258();
    return uVar1;
  }
  return 4;
}


// ===== FUN_00215280 @ 00215280 (38 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00215280(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  flix();
  *param_1 = (char)param_3;
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 8) = param_3;
  flix();
  *(undefined4 *)(param_1 + 0xc) = param_2;
  param_1[0x16] = (char)param_2;
  *(undefined4 *)(param_1 + 0x44) = param_2;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215318 @ 00215318 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00215318(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_002155d0 @ 002155d0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002155d0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215880 @ 00215880 (208 bytes)

/* WARNING: Removing unreachable block (ram,0x00215947) */
/* WARNING: Removing unreachable block (ram,0x00215903) */
/* WARNING: Removing unreachable block (ram,0x002158d6) */
/* WARNING: Removing unreachable block (ram,0x002158d9) */
/* WARNING: Removing unreachable block (ram,0x002158dc) */
/* WARNING: Removing unreachable block (ram,0x002158e2) */
/* WARNING: Removing unreachable block (ram,0x002158e5) */
/* WARNING: Removing unreachable block (ram,0x00215958) */
/* WARNING: Removing unreachable block (ram,0x00215936) */
/* WARNING: Removing unreachable block (ram,0x00215925) */

void FUN_00215880(uint *param_1)

{
  uint uVar1;
  
  if (param_1 == (uint *)0x0) {
    return;
  }
  memw();
  memw();
  *param_1 = *param_1 & 0xfffeefff | (uint)&DAT_00010000;
  memw();
  uVar1 = *param_1 & (uint)&DAT_00002000;
  while (uVar1 == 0) {
    memw();
    uVar1 = *param_1 & (uint)&DAT_00002000;
  }
  flix();
  memw();
  DAT_40001070 = &DAT_00010000;
  return;
}


// ===== FUN_0021596c @ 0021596c (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021596c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215ad0 @ 00215ad0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00215ad0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215ae0 @ 00215ae0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00215ae0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215af0 @ 00215af0 (13 bytes)

undefined4 FUN_00215af0(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0xe10);
}


// ===== FUN_00215b00 @ 00215b00 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00215b00(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215b20 @ 00215b20 (29 bytes)

int FUN_00215b20(void)

{
  int iVar1;
  int extraout_a5;
  
  memw();
  memw();
  flix();
  iVar1 = func_0x001ea090();
  flix();
  return iVar1 - extraout_a5;
}


// ===== FUN_00215b44 @ 00215b44 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00215b44(undefined4 param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + 0x18) = param_3;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215b68 @ 00215b68 (33 bytes)

void FUN_00215b68(undefined4 param_1,int param_2)

{
  undefined4 unaff_a8;
  
  memw();
  flix();
  *(undefined4 *)(param_2 + 0x18) = unaff_a8;
  *(undefined4 *)(param_2 + 0x1c) = unaff_a8;
  memw();
  *(short *)(param_2 + 0x20) = (short)unaff_a8;
  memw();
  *(short *)(param_2 + 0x22) = (short)unaff_a8;
  return;
}


// ===== FUN_00215bac @ 00215bac (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00215bac(int param_1,int param_2,int param_3)

{
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 4;
}


// ===== FUN_00215d70 @ 00215d70 (38 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00215d70(int param_1)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 8);
  while ((uVar1 & 8) == 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 8);
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215dc0 @ 00215dc0 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00215dc0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215dfc @ 00215dfc (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00215dfc(int param_1,int param_2,int param_3)

{
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    memw();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 4;
}


// ===== FUN_00215ed4 @ 00215ed4 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00215edb) overlaps instruction at (ram,0x00215eda)
    */

void FUN_00215ed4(uint *param_1)

{
  uint unaff_a9;
  
  flix();
  memw();
  memw();
  *param_1 = *param_1 & unaff_a9;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215f70 @ 00215f70 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00215f70(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00215fb4 @ 00215fb4 (19 bytes)

void FUN_00215fb4(undefined4 param_1,uint param_2)

{
  uint in_t0;
  
  flix();
  func_0x001e216c();
  memw();
  *(uint *)(in_t0 + 0x20) = param_2 | in_t0;
  return;
}


// ===== FUN_00215fc8 @ 00215fc8 (94 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00215fc8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (((param_1 != 0) && (param_2 != 0)) && (memw(), (*(uint *)(param_1 + 0xe00) & 1) != 0)) {
    if (param_3 != 0) {
      memw();
      uVar1 = *(uint *)(param_1 + 0xe04);
      while ((uVar1 & 0x20) == 0) {
        memw();
        uVar1 = *(uint *)(param_1 + 0xe04);
      }
      memw();
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    memw();
    uVar1 = *(uint *)(param_1 + 8);
    while ((uVar1 & 8) == 0) {
      memw();
      uVar1 = *(uint *)(param_1 + 8);
    }
    return 0;
  }
  return 4;
}


// ===== FUN_00216034 @ 00216034 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00216034(uint param_1)

{
  int unaff_retaddr;
  int in_a6;
  uint in_a12;
  int in_SCOMPARE1;
  
  flix();
  if ((param_1 & in_a12) != 0) {
    if (*(int *)(unaff_retaddr + 0x308) == in_SCOMPARE1) {
      *(int *)(unaff_retaddr + 0x308) = in_a6 + 0xb;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cust1();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002160f8 @ 002160f8 (24 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_002160f8(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_00215b00(param_1);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 4;
}


// ===== FUN_00216164 @ 00216164 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00216164(int param_1,int param_2,int param_3)

{
  int unaff_retaddr;
  undefined4 in_a12;
  undefined1 auStack_20 [32];
  
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    flix();
    *(undefined1 **)unaff_retaddr = auStack_20;
    *(undefined4 *)(unaff_retaddr + 0x30) = in_a12;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 4;
}


// ===== FUN_002161c4 @ 002161c4 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002161c4(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002161f8 @ 002161f8 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002161f8(void)

{
  memw();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00216238 @ 00216238 (35 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00216238(int param_1,int param_2,int param_3)

{
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    flix();
    memw();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 4;
}


// ===== FUN_00216394 @ 00216394 (26 bytes)

void FUN_00216394(undefined4 param_1,int param_2)

{
  undefined4 unaff_a10;
  
  flix();
  memw();
  *(undefined4 *)(param_2 + 0x10) = unaff_a10;
  memw();
  *(undefined1 *)(param_2 + 0x2d) = 2;
  return;
}


// ===== FUN_002163e4 @ 002163e4 (40 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002163e4(void)

{
  int unaff_retaddr;
  
  memw();
  flix();
  if (unaff_retaddr != 0) {
    memw();
    flix();
    flix();
    return;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021640c @ 0021640c (39 bytes)

void FUN_0021640c(void)

{
  memw();
  memw();
  flix();
  FUN_00211776();
  return;
}


// ===== FUN_00216718 @ 00216718 (61 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00216718(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  int unaff_retaddr;
  undefined4 uVar1;
  int unaff_a11;
  int iVar2;
  
  uVar1 = *param_2;
  flix();
  if (unaff_a11 == 0) {
    memw();
    *(undefined4 *)(*(int *)(unaff_retaddr + 0x30) + 0x1fc) = 0;
    iVar2 = param_2[1];
    memw();
    *(undefined1 *)(iVar2 + 0x1d) = 2;
    if (*(int *)(iVar2 + 4) != 0) {
      (**(code **)(iVar2 + 4))(uVar1,iVar2,&DAT_00001647,*(undefined4 *)(iVar2 + 8));
    }
    return;
  }
  *(int *)(param_4 + 0xe8) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00216750 @ 00216750 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00216750(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_00215b00(param_1);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 4;
}


// ===== FUN_002167c8 @ 002167c8 (58 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined * FUN_002167c8(undefined4 param_1,int param_2)

{
  undefined4 in_a14;
  
  memw();
  if (*(char *)(param_2 + 0x1c) == '\x01') {
    return &DAT_00001644;
  }
  memw();
  flix();
  flix();
  *(undefined4 *)(param_2 + 0x10) = in_a14;
  flix();
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021682c @ 0021682c (64 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined * FUN_0021682c(int param_1,int param_2)

{
  uint unaff_a10;
  undefined4 in_a14;
  
  memw();
  if (*(char *)(param_2 + 0x1d) == '\x03') {
    return &DAT_00001645;
  }
  memw();
  flix();
  flix();
  *(undefined4 *)(param_2 + 0xc) = in_a14;
  flix();
  memw();
  *(uint *)(param_1 + 0xdfc) = unaff_a10 | *(uint *)(param_1 + 0xc3f);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00216894 @ 00216894 (18 bytes)

void FUN_00216894(undefined4 param_1,int param_2)

{
  FUN_0020aa20(*(undefined4 *)(param_2 + 0x14));
  memw();
  *(undefined1 *)(param_2 + 0x1c) = 0;
  return;
}


// ===== FUN_002168a8 @ 002168a8 (18 bytes)

void FUN_002168a8(undefined4 param_1,int param_2)

{
  FUN_0020aa20(*(undefined4 *)(param_2 + 0x18));
  memw();
  *(undefined1 *)(param_2 + 0x1d) = 2;
  return;
}


// ===== FUN_002168bc @ 002168bc (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002168bc(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002168e8 @ 002168e8 (15 bytes)

void FUN_002168e8(void)

{
  memw();
  flix();
  FUN_002054f8();
  return;
}


// ===== FUN_00216914 @ 00216914 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00216914(int param_1,int param_2)

{
  int iVar1;
  
  memw();
  *(undefined1 *)(param_2 + 0x1c) = 0;
  memw();
  iVar1 = *(int *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x10) = 8;
  if (iVar1 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_00216940 @ 00216940 (154 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00216940(void)

{
  int unaff_retaddr;
  uint uVar1;
  uint *unaff_a11;
  int in_a12;
  uint uVar2;
  int iVar3;
  
  flix();
  if (unaff_a11 == (uint *)0x0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar3 = unaff_retaddr + -1;
  flix();
  uVar2 = *unaff_a11;
  uVar1 = uVar2 >> 8 & 0xff;
  if (uVar1 == 0) {
    memw();
    *(int *)(in_a12 + 0x240) = iVar3 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar1 == 1) {
    memw();
    *(int *)(in_a12 + 0x244) = iVar3 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else if (uVar1 == 2) {
    memw();
    *(int *)(in_a12 + 0x248) = iVar3 << 0x20 - (0x20 - ((byte)(&DAT_00200618)[iVar3 * 4] & 0x1f));
  }
  else if (uVar1 == 3) {
    memw();
    DAT_40021040 = iVar3 << 0x20 - (0x20 - (uVar2 & 0x1f));
  }
  else {
    flix();
    if (uVar1 == 5) {
      memw();
      DAT_40021048 = iVar3 << 0x20 - (0x20 - (uVar2 & 0x1f));
    }
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00216970 @ 00216970 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00216a00) */
/* WARNING: Removing unreachable block (ram,0x002169a2) */
/* WARNING: Removing unreachable block (ram,0x00216993) */
/* WARNING: Removing unreachable block (ram,0x00216999) */
/* WARNING: Removing unreachable block (ram,0x00216a12) */
/* WARNING: Removing unreachable block (ram,0x002169e7) */

void FUN_00216970(void)

{
  int in_a12;
  int in_a14;
  
  flix();
  flix();
  flix();
  memw();
  *(int *)(in_a12 + 0x248) = in_a14 << 0x20 - (0x20 - ((byte)(&DAT_00200618)[in_a14 * 4] & 0x1f));
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00216a38 @ 00216a38 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00216a38(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00216aec @ 00216aec (10 bytes)

undefined4 FUN_00216aec(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 4);
}


// ===== FUN_00216af8 @ 00216af8 (12 bytes)

void FUN_00216af8(int param_1)

{
  memw();
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}


// ===== FUN_00216b04 @ 00216b04 (15 bytes)

void FUN_00216b04(undefined4 param_1,code *param_2)

{
  FUN_00216af8(param_1);
  if (param_2 != (code *)0x0) {
    (*param_2)();
  }
  return;
}


// ===== FUN_00216b14 @ 00216b14 (18 bytes)

void FUN_00216b14(void)

{
  (*DAT_00239080)(&DAT_4000f000,DAT_00239084);
  return;
}


// ===== FUN_00216b30 @ 00216b30 (37 bytes)

void FUN_00216b30(undefined4 *param_1,undefined1 param_2)

{
  undefined1 uVar1;
  undefined4 unaff_a8;
  
  flix();
  param_1[3] = unaff_a8;
  param_1[4] = unaff_a8;
  *param_1 = unaff_a8;
  uVar1 = (undefined1)unaff_a8;
  *(undefined1 *)((int)param_1 + 1) = uVar1;
  *(undefined1 *)((int)param_1 + 2) = uVar1;
  *(undefined1 *)((int)param_1 + 3) = uVar1;
  *(undefined1 *)param_1 = param_2;
  return;
}


// ===== FUN_00216b58 @ 00216b58 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00216b58(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

