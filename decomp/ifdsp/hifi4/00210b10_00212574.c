// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00210b10 @ 00210b10 (26 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210b10(undefined4 param_1)

{
  FUN_002105ac(param_1);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210c20 @ 00210c20 (22 bytes)

undefined4 FUN_00210c20(int param_1)

{
  memw();
  return *(undefined4 *)(&DAT_00200420 + (*(uint *)(param_1 + 0x88) & 7) * 4);
}


// ===== FUN_00210c38 @ 00210c38 (117 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210c38(int param_1)

{
  int iVar1;
  int extraout_a3;
  uint uVar2;
  int in_a12;
  int in_t0;
  
  iVar1 = FUN_002105ac(param_1);
  flix();
  FUN_00213910(*(undefined4 *)(param_1 * 4 + iVar1));
  uVar2 = *(uint *)(&DAT_00200404 + param_1 * 4);
  flix();
  cust0();
  *(undefined4 *)(in_t0 + 0x14) = 4;
  if (in_t0 == 2) {
    memw();
    *(int *)(extraout_a3 + 0x278) = in_a12 << 0x20 - (0x20 - (uVar2 & 0x1f));
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  flix();
  if (in_t0 != 5) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  DAT_40021078 = in_a12 << 0x20 - (0x20 - (uVar2 & 0x1f));
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210d30 @ 00210d30 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210d30(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210d58 @ 00210d58 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210d58(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210e38 @ 00210e38 (49 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined * FUN_00210e38(undefined4 param_1,int param_2)

{
  int iVar1;
  int *in_t0;
  
  iVar1 = FUN_00210c20(param_1);
  if (param_2 == 2) {
    flix();
    if ((iVar1 == 3) || (*in_t0 == 0)) goto LAB_00210e67;
  }
  else if ((iVar1 == 0) || (iVar1 == 3)) {
LAB_00210e67:
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return &DAT_00001edc;
}


// ===== FUN_00210e7c @ 00210e7c (31 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210e7c(int param_1)

{
  undefined4 unaff_a9;
  int unaff_a10;
  
  memw();
  *(undefined **)(param_1 + 0x88) = &DAT_0008a700;
  memw();
  flix();
  cust0();
  *(undefined4 *)(unaff_a10 + 0x18) = unaff_a9;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210ecc @ 00210ecc (57 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00210ece) overlaps instruction at (ram,0x00210ecc)
    */

undefined8 FUN_00210ecc(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  uint unaff_retaddr;
  int iVar1;
  int in_a13;
  uint in_t0;
  ulonglong uVar2;
  
  iVar1 = param_1;
  while( true ) {
    uVar2 = FUN_00210c20(iVar1);
    if ((int)uVar2 != 3) {
      return CONCAT44(param_2,&DAT_00001ee6);
    }
    flix();
    if (in_a13 == -1) break;
    param_2 = unaff_retaddr >> 6;
    iVar1 = 3;
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & in_t0 | param_5;
  flix();
  if (uVar2 < 0xa00000000) {
    memw();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210f34 @ 00210f34 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210f34(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210f50 @ 00210f50 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210f50(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210fa4 @ 00210fa4 (46 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00210fa4(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    flix();
    flix();
    flix();
    flix();
    uVar1 = func_0x001f1150();
    FUN_002104f0(uVar1);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_002110e4 @ 002110e4 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002110e4(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211204 @ 00211204 (35 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00211204(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 unaff_retaddr;
  
  flix();
  DAT_00010003 = unaff_retaddr;
  *param_2 = param_3;
  flix();
  *(undefined4 *)(param_1 + 0x10c) = _DAT_01000033;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021139c @ 0021139c (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021139c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211590 @ 00211590 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00211590(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002115f8 @ 002115f8 (36 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined * FUN_002115f8(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00210c20(param_1);
  if ((*param_2 == '\0') && ((flix(), iVar1 == 0 || (iVar1 == 3)))) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return &DAT_00001edc;
}


// ===== FUN_0021171e @ 0021171e (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021171e(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211748 @ 00211748 (34 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00211748(undefined4 param_1,char *param_2)

{
  flix();
  if (*param_2 != '\0') {
    FUN_00210544(param_1);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  return;
}


// ===== FUN_00211776 @ 00211776 (26 bytes)

void FUN_00211776(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  flix();
  if (param_4 != 4) {
    flix();
    *param_3 = param_2;
    return;
  }
  flix();
  return;
}


// ===== FUN_002117a8 @ 002117a8 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002117a8(undefined4 param_1,char *param_2)

{
  if (*param_2 != '\0') {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_002117dc @ 002117dc (17 bytes)

void FUN_002117dc(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    flix();
    FUN_0020a758();
    return;
  }
  return;
}


// ===== FUN_00211bec @ 00211bec (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00211bec(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211c28 @ 00211c28 (41 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00211c28(void)

{
  memw();
  flix();
  func_0x001e9e94();
  FUN_002105ac();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211de8 @ 00211de8 (36 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00211de8(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int extraout_a3;
  uint uVar3;
  int in_a12;
  int in_a13;
  int in_t0;
  
  iVar1 = FUN_002105ac(param_1);
  flix();
  iVar2 = (uint)*(byte *)(in_a13 + 0xfd) * 4;
  FUN_00213910(*(undefined4 *)(iVar2 + iVar1));
  uVar3 = *(uint *)(&DAT_00200404 + iVar2);
  flix();
  cust0();
  *(undefined4 *)(in_t0 + 0x14) = 4;
  if (in_t0 == 2) {
    memw();
    *(int *)(extraout_a3 + 0x278) = in_a12 << 0x20 - (0x20 - (uVar3 & 0x1f));
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  flix();
  if (in_t0 != 5) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  DAT_40021078 = in_a12 << 0x20 - (0x20 - (uVar3 & 0x1f));
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211e0e @ 00211e0e (107 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00211e0e(undefined4 param_1,undefined4 param_2)

{
  int unaff_a9;
  uint unaff_a10;
  int unaff_a11;
  undefined4 *in_a12;
  
  *in_a12 = param_2;
  if (unaff_a9 == 1) {
    memw();
    *(int *)(unaff_a11 + 0x274) = (int)in_a12 << 0x20 - (0x20 - (unaff_a10 & 0x1f));
    flix();
    return;
  }
  if (unaff_a9 != 2) {
    flix();
    flix();
    if (unaff_a9 != 5) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    memw();
    DAT_40021078 = (int)in_a12 << 0x20 - (0x20 - (unaff_a10 & 0x1f));
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  *(int *)(unaff_a11 + 0x278) = (int)in_a12 << 0x20 - (0x20 - (unaff_a10 & 0x1f));
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211ee0 @ 00211ee0 (36 bytes)

undefined4 FUN_00211ee0(uint param_1)

{
  uint uVar1;
  int in_a13;
  undefined4 in_f2;
  
  memw();
  uVar1 = *(uint *)(param_1 + 8);
  flix();
  *(undefined4 *)(in_a13 + 0x304) = in_f2;
  if (param_1 < 4) {
    return *(undefined4 *)(param_1 * 4 + (uVar1 & 0x30000000));
  }
  return 0;
}


// ===== FUN_00211f04 @ 00211f04 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00211f04(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211f20 @ 00211f20 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00211f20(void)

{
  memw();
  flix();
  if (&stack0x00000000 == (undefined1 *)0x20) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211f68 @ 00211f68 (67 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00211f75) overlaps instruction at (ram,0x00211f73)
    */

undefined4 FUN_00211f68(undefined4 param_1,undefined4 param_2,int param_3)

{
  int unaff_a11;
  
  if (param_3 == 0) {
    return 0;
  }
  memw();
  flix();
  memw();
  do {
    flix();
  } while (*(short *)(unaff_a11 + 0x1f8) != 0xc000000);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00211ff0 @ 00211ff0 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00211ff0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    FUN_0021055c(param_1);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_0021202c @ 0021202c (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021202c(void)

{
  flix();
  cust1();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212060 @ 00212060 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined * FUN_00212060(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x1c) != '\0') {
    return &DAT_00001edc;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002120a8 @ 002120a8 (24 bytes)

undefined4 FUN_002120a8(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_3 != (undefined4 *)0x0) {
    flix();
    *param_3 = *(undefined4 *)(param_2 + 0x24);
    return param_1;
  }
  return 4;
}


// ===== FUN_002120cc @ 002120cc (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002120cc(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x1c) != '\0') {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_002120f4 @ 002120f4 (24 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002120f4(void)

{
  flix();
  func_0x0026220c();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002121bc @ 002121bc (29 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002121bc(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined1 unaff_a10;
  
  *param_2 = param_5;
  *(undefined1 *)(param_2 + 7) = unaff_a10;
  if (((param_2[8] & 0x100) != 0) && (param_2[10] != 0)) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002123e0 @ 002123e0 (51 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002123e0(void)

{
  uint uVar1;
  
  memw();
  uVar1 = DAT_40036000;
  if (((uVar1 & 3) == 1) && (DAT_00238e30 != (code *)0x0)) {
    (*DAT_00238e30)(&DAT_40036000,DAT_00238e38);
  }
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212430 @ 00212430 (16 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212430(undefined4 param_1)

{
  (*_DAT_1303f000)(param_1);
  return;
}


// ===== FUN_00212440 @ 00212440 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212440(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212458 @ 00212458 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212458(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212478 @ 00212478 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212478(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212490 @ 00212490 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212490(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002124b0 @ 002124b0 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_002124b0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002124cc @ 002124cc (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_002124cc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002124e8 @ 002124e8 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_002124e8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212504 @ 00212504 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212504(void)

{
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212528 @ 00212528 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212528(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212540 @ 00212540 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212540(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212560 @ 00212560 (20 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212560(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f01c + 0x2c))(param_1);
  return uVar1;
}


// ===== FUN_00212574 @ 00212574 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212574(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

