// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0021258c @ 0021258c (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0021258c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002125bc @ 002125bc (20 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_002125bc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)*_DAT_1303f020)(param_1);
  return uVar1;
}


// ===== FUN_002125d0 @ 002125d0 (18 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_002125d0(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 4))();
  return uVar1;
}


// ===== FUN_002125e4 @ 002125e4 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_002125e4(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002125fc @ 002125fc (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_002125fc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212618 @ 00212618 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212618(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212634 @ 00212634 (18 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00212634(void)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(_DAT_1303f020 + 0x14))();
  return uVar1;
}


// ===== FUN_00212648 @ 00212648 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00212648(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212670 @ 00212670 (17 bytes)

void FUN_00212670(void)

{
  memw();
  DAT_40021048 = 0x80000000;
  return;
}


// ===== INPUTMUX_AttachSignal @ 00212684 (12 bytes)

void INPUTMUX_AttachSignal(void)

{
  flix();
  FUN_0020cac5();
  return;
}


// ===== FUN_002126a0 @ 002126a0 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002126a0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002126e0 @ 002126e0 (17 bytes)

void FUN_002126e0(void)

{
  memw();
  DAT_40021078 = 0x80000000;
  return;
}


// ===== FUN_00212700 @ 00212700 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00212700(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint in_a14;
  
  flix();
  func_0x00192a14(param_1,param_2,(int)((ulonglong)in_a14 * (ulonglong)in_a14 >> 0x20),param_4,
                  &DAT_40000e00);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002128b8 @ 002128b8 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002128b8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002128e8 @ 002128e8 (188 bytes)

/* WARNING: Removing unreachable block (ram,0x00212995) */
/* WARNING: Removing unreachable block (ram,0x00212973) */
/* WARNING: Removing unreachable block (ram,0x00212951) */
/* WARNING: Removing unreachable block (ram,0x00212984) */
/* WARNING: Removing unreachable block (ram,0x00212940) */
/* WARNING: Removing unreachable block (ram,0x00212962) */

void FUN_002128e8(undefined *param_1)

{
  uint extraout_a5;
  int in_a6;
  int iVar1;
  
  iVar1 = 1;
  flix();
  func_0x001f65c0();
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & extraout_a5;
  if (param_1 != &DAT_4013a000) {
    return;
  }
  memw();
  *(int *)(in_a6 + 0x274) = iVar1 << 0x10;
  return;
}


// ===== FUN_002129a8 @ 002129a8 (42 bytes)

int FUN_002129a8(int param_1)

{
  memw();
  if (-1 < *(int *)(param_1 + 0x300)) {
    return 0;
  }
  flix();
  flix();
  flix();
  flix();
  return *(int *)(param_1 + 0x300);
}


// ===== FUN_002129d4 @ 002129d4 (13 bytes)

void FUN_002129d4(void)

{
  flix();
  return;
}


// ===== FUN_00212a18 @ 00212a18 (18 bytes)

void FUN_00212a18(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  return;
}


// ===== FUN_00212a2c @ 00212a2c (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00212a2c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212af4 @ 00212af4 (45 bytes)

void FUN_00212af4(int param_1)

{
  undefined4 unaff_a9;
  
  flix();
  *(undefined4 *)(param_1 + 4) = unaff_a9;
  *(undefined4 *)(param_1 + 8) = unaff_a9;
  *(undefined4 *)(param_1 + 0xc) = unaff_a9;
  *(char *)(param_1 + 0x10) = (char)unaff_a9;
  *(undefined4 *)(param_1 + 0x14) = unaff_a9;
  *(undefined4 *)(param_1 + 0x18) = unaff_a9;
  *(undefined4 *)(param_1 + 0x1c) = unaff_a9;
  *(undefined4 *)(param_1 + 0x20) = unaff_a9;
  *(undefined4 *)(param_1 + 0x24) = unaff_a9;
  flix();
  return;
}


// ===== FUN_00212b30 @ 00212b30 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00212b4c) */

void FUN_00212b30(void)

{
  flix();
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212c04 @ 00212c04 (49 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00212c04(undefined4 *param_1)

{
  uint in_a12;
  uint in_a14;
  
  flix();
  if ((in_a12 & in_a14) != 0) {
    memw();
    *param_1 = 0x80000000;
    memw();
    param_1[4] = 0x80000000;
    memw();
    param_1[8] = 0x80000000;
    memw();
    param_1[0xc] = 0x80000000;
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212cc8 @ 00212cc8 (25 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00212cc8(undefined4 param_1,undefined4 param_2,int param_3)

{
  int in_a12;
  
  flix();
  if (in_a12 != param_3) {
    memw();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== MU_Init @ 00212d00 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* clock enable for MU (base 0x40111000 MU-B passed by Thread_Ipc) */

void MU_Init(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212dac @ 00212dac (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00212dac(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== MU_SendMsg @ 00212e58 (46 bytes)

/* wait SR TEn, TR[reg] (+0x20) */

void MU_SendMsg(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x60);
  while ((uVar1 & 0x800000U >> (param_2 & 0x1f)) == 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x60);
  }
  memw();
  *(undefined4 *)(param_2 * 4 + param_1 + 0x20) = param_3;
  return;
}


// ===== MU_ReceiveMsg @ 00212e88 (47 bytes)

/* wait SR RFn, RR[reg] (+0x40) */

undefined4 MU_ReceiveMsg(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x60);
  while ((uVar1 & 0x8000000U >> (param_2 & 0x1f)) == 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x60);
  }
  memw();
  return *(undefined4 *)(param_2 * 4 + param_1 + 0x40);
}


// ===== MU_SetFlags @ 00212eb8 (41 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* wait SR FUP (bit 8) clear, CR Fn = flags */

void MU_SetFlags(int param_1)

{
  uint uVar1;
  
  memw();
  uVar1 = *(uint *)(param_1 + 0x60);
  while ((uVar1 & 0x100) != 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x60);
  }
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212ef0 @ 00212ef0 (36 bytes)

int FUN_00212ef0(int param_1,uint param_2)

{
  memw();
  if ((param_2 & *(uint *)(param_1 + 100)) != 0) {
    return 1;
  }
  memw();
  flix();
  return param_1;
}


// ===== FUN_00212f20 @ 00212f20 (19 bytes)

void FUN_00212f20(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ===== FUN_00212f34 @ 00212f34 (89 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00212f34(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_a9;
  undefined4 *in_a12;
  undefined4 in_a13;
  int in_a14;
  undefined1 auStack_20 [32];
  
  iVar2 = *(int *)(param_2 + 4);
  uVar3 = 2;
  memw();
  uVar1 = *(uint *)(iVar2 + 0xe0);
  if (((uVar1 & 2) != 0) && ((uVar1 & 1) != 0)) goto LAB_00212f57;
  while( true ) {
    do {
      do {
        memw();
        uVar1 = *(uint *)(iVar2 + 0xe0);
      } while ((uVar1 & uVar3) == 0);
    } while ((uVar1 & 1) == 0);
LAB_00212f57:
    memw();
    flix();
    *in_a12 = in_a13;
    if (in_a14 != 0) break;
    in_a14 = 1;
    flix();
    uVar3 = 0;
    if (((uint)in_a12 & 1 << ((byte)unaff_a9 & 0x1f)) == 0) {
      flix();
      in_a12[5] = auStack_20;
      in_a12[0xd] = unaff_a9;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212fa0 @ 00212fa0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00212fa0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00212fbc @ 00212fbc (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00212fbc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021306c @ 0021306c (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021306c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00213100 @ 00213100 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00213100(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00213170 @ 00213170 (19 bytes)

void FUN_00213170(int param_1,undefined4 param_2,int param_3)

{
  int in_SAR;
  
  flix();
  memw();
  *(int *)(param_1 + 0x20) = param_3 << 0x20 - in_SAR;
  return;
}


// ===== FUN_00213184 @ 00213184 (19 bytes)

void FUN_00213184(int param_1,undefined4 param_2,int param_3)

{
  int in_SAR;
  
  flix();
  memw();
  *(int *)(param_1 + 0x1c) = param_3 << 0x20 - in_SAR;
  return;
}


// ===== FUN_00213198 @ 00213198 (70 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00213198(void)

{
  int in_a5;
  undefined4 in_a6;
  int *unaff_a8;
  
  flix();
  DAT_00238f20 = 0;
  DAT_00238f24 = 0;
  DAT_00238f28 = 0;
  DAT_00238f2c = 0;
  DAT_00238f30 = 0;
  DAT_00238f34 = 0;
  DAT_00238f38 = 0;
  flix();
  cust0();
  flix();
  flix();
  if (*unaff_a8 == -1) {
    flix();
    *(undefined4 *)(in_a5 + 8) = in_a6;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021320c @ 0021320c (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021320c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00213288 @ 00213288 (33 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00213288(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int in_a12;
  
  *param_3 = 0;
  flix();
  memw();
  flix();
  if (in_a12 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002132f4 @ 002132f4 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00213307) overlaps instruction at (ram,0x00213306)
    */

void FUN_002132f4(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 uint param_6)

{
  uint unaff_retaddr;
  undefined4 unaff_a9;
  uint in_a15;
  
  flix();
  if (param_2 * 3 != unaff_retaddr) {
    flix();
    *(undefined4 *)(param_4 + 0x38) = param_5;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((in_a15 & 0x800000) == 0) {
    func_0x00232148();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (unaff_retaddr < 3) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (unaff_retaddr != param_6) {
    if (in_a15 < 0x100) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined4 *)(param_2 + 4) = unaff_a9;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021337c @ 0021337c (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021337c(void)

{
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002133f8 @ 002133f8 (33 bytes)

int FUN_002133f8(int param_1)

{
  memw();
  if (*(uint *)(param_1 + 0x28) >> 0x18 != 0) {
    memw();
    memw();
    flix();
    return param_1;
  }
  return 0;
}


// ===== FUN_0021341c @ 0021341c (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021341c(void)

{
  flix();
  memw();
  memw();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00213448 @ 00213448 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00213448(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002134a8 @ 002134a8 (21 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002134a8(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002134c8 @ 002134c8 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002134c8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002134d8 @ 002134d8 (21 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002134d8(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002134f8 @ 002134f8 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002134f8(undefined4 *param_1)

{
  if (param_1 != &DAT_40025000) {
    return;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00213514 @ 00213514 (56 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00213514(undefined4 param_1)

{
  uint uVar1;
  
  DAT_00238f20 = FUN_002134d8(param_1);
  flix();
  memw();
  flix();
  DAT_00238f24 = DAT_00238f20;
  DAT_00238f28 = DAT_00238f20;
  DAT_00238f2c = DAT_00238f20;
  DAT_00238f30 = DAT_00238f20;
  DAT_00238f34 = DAT_00238f20;
  DAT_00238f38 = DAT_00238f20;
  DAT_00238f3c = DAT_00238f20;
  FUN_002133f8(&DAT_40025000);
  flix();
  memw();
  uVar1 = DAT_40025000;
  if ((uVar1 & 1) != 0) {
    return;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

