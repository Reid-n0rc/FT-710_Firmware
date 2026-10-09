// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0022b838 @ 0022b838 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b838(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b848 @ 0022b848 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b848(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b858 @ 0022b858 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b858(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b864 @ 0022b864 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b864(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b874 @ 0022b874 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b874(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b880 @ 0022b880 (42 bytes)

undefined4 FUN_0022b880(int param_1,uint param_2,int param_3,uint param_4)

{
  if (((~param_2 & 0x7ff00000) == 0) && ((param_2 & 0xfffff) != 0 || param_1 != 0)) {
    return 1;
  }
  if (((~param_4 & 0x7ff00000) == 0) && ((param_4 & 0xfffff) != 0 || param_3 != 0)) {
    return 1;
  }
  return 0;
}


// ===== FUN_0022b8ac @ 0022b8ac (93 bytes)

/* WARNING: Control flow encountered bad instruction data */

uint FUN_0022b8ac(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int in_t0;
  
  if ((-1 < (int)(param_2 ^ param_2 + 0xc8000000)) &&
     (uVar2 = param_2 + 0xc8000000 >> 0x14 & 0x7ff, uVar2 != 0)) {
    if (0xfe < uVar2) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    flix();
    *(uint *)(param_2 + 0xc80003b4) = uVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  iVar1 = FUN_0020c63c();
  if (0x1f < (in_t0 - iVar1) + 1U) {
    return param_2 & 0x80000000;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b96c @ 0022b96c (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022b96c(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022b9e0 @ 0022b9e0 (35 bytes)

void FUN_0022b9e0(undefined4 param_1,undefined4 *param_2,undefined *param_3,code *param_4,
                 int param_5)

{
  if (param_2 != (undefined4 *)0x0) {
    DAT_002cd700 = *param_2;
  }
  PTR_DAT_00237ad0 = param_3;
  if (param_4 != (code *)0x0) {
    (*param_4)();
  }
  if (param_5 != 0) {
    FUN_0022e710(param_5);
  }
  return;
}


// ===== FUN_0022ba10 @ 0022ba10 (10 bytes)

undefined * FUN_0022ba10(void)

{
  return PTR_DAT_00237f00;
}


// ===== FUN_0022ba20 @ 0022ba20 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022ba20(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022ba40 @ 0022ba40 (20 bytes)

undefined4 FUN_0022ba40(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0022ba80(PTR_DAT_00237f00,param_1);
  return uVar1;
}


// ===== FUN_0022ba60 @ 0022ba60 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022ba60(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022ba80 @ 0022ba80 (45 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022ba80(undefined4 param_1,uint param_2)

{
  int in_a14;
  
  flix();
  cust0();
  if ((*(uint *)(in_a14 + 0x30) & 5) < param_2) {
    flix();
    return;
  }
  FUN_00228dc0(param_1);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022bfb0 @ 0022bfb0 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022bfb0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022bff0 @ 0022bff0 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022bff0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022c030 @ 0022c030 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c030(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022c050 @ 0022c050 (70 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c050(void)

{
  uint uVar1;
  uint uVar2;
  int unaff_a8;
  int in_SCOMPARE1;
  undefined1 auStack_20 [32];
  
  uVar2 = *(uint *)(PTR_DAT_00237f00 + 0xa8);
  flix();
  uVar1 = 0x22c076;
  func_0x001f4238(uVar2 * 0x4c957f2d,0x4c957f2d,(int)((ulonglong)uVar2 * 0x4c957f2d >> 0x20),
                  uVar2 * 0x5851f42d,PTR_DAT_00237f00,*(int *)(PTR_DAT_00237f00 + 0xac) * 0x4c957f2d
                 );
  flix();
  if ((uVar1 & (uint)auStack_20) != 0) {
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (*(int *)(DAT_001f3c14 + 0x3b8) == in_SCOMPARE1) {
    *(int *)(DAT_001f3c14 + 0x3b8) = (int)auStack_20;
  }
  *(undefined4 *)(unaff_a8 + 0x34) = DAT_001eec38;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022c0a0 @ 0022c0a0 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c0a0(undefined4 param_1,int *param_2)

{
  if (*param_2 != 0) {
    FUN_0022c0a0(param_1);
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022c0c0 @ 0022c0c0 (115 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c0c0(undefined *param_1)

{
  int iVar1;
  
  if (PTR_DAT_00237f00 != param_1) {
    if (*(int *)(param_1 + 0x4c) != 0) {
      iVar1 = 0;
      do {
        if (*(int *)(*(int *)(param_1 + 0x4c) + iVar1) != 0) {
          flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        iVar1 = iVar1 + 4;
      } while (iVar1 != 0x80);
      FUN_0022fe50(param_1);
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      FUN_0022fe50(param_1);
    }
    if ((*(undefined **)(param_1 + 0x148) != (undefined *)0x0) &&
       (param_1 + 0x14c != *(undefined **)(param_1 + 0x148))) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (*(int *)(param_1 + 0x54) != 0) {
      FUN_0022fe50(param_1);
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      (**(code **)(param_1 + 0x3c))(param_1);
      if (*(int *)(param_1 + 0x2e0) != 0) {
        FUN_0022c0a0(param_1);
      }
    }
  }
  return;
}


// ===== FUN_0022c150 @ 0022c150 (29 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c150(undefined *param_1)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_00237f00;
  }
  if (*(int *)(param_1 + 0x148) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (*(code **)(param_1 + 0x3c) != (code *)0x0) {
    (**(code **)(param_1 + 0x3c))(param_1);
  }
  return;
}


// ===== FUN_0022c190 @ 0022c190 (110 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0022c1e1) */
/* WARNING: Removing unreachable block (ram,0x0022c22e) */

int FUN_0022c190(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                int param_6)

{
  int unaff_retaddr;
  int unaff_a8;
  int unaff_a9;
  uint unaff_a10;
  uint unaff_a11;
  int in_a12;
  uint in_a14;
  
  flix();
  *(int *)(param_6 + 4) = unaff_retaddr;
  if (in_a12 == 0) {
    unaff_a9 = *(int *)(unaff_a8 + 0x14);
    if (((param_1 | param_2) & unaff_a10) == 0) goto LAB_0022c1fc;
    unaff_a11 = param_1 ^ param_2;
    if ((unaff_a11 & unaff_a10) != 0) {
      flix();
      *(int *)(param_6 + 4) = unaff_retaddr;
      if (unaff_a11 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (unaff_retaddr != 0) {
        flix();
        *(int *)((param_5 & in_a14) + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      (*(code *)0x0)();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  if (unaff_a8 != 0) {
    flix();
    flix();
    *(int *)(param_6 + 4) = unaff_retaddr;
    if (unaff_a11 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (unaff_a8 != unaff_a9) {
      return unaff_a8 - unaff_a9;
    }
    if (unaff_a8 != 0) {
LAB_0022c1fc:
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return 0;
}


// ===== FUN_0022c1d2 @ 0022c1d2 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0022c1d2(void)

{
  int unaff_a8;
  
  if (unaff_a8 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_0022c2e0 @ 0022c2e0 (87 bytes)

/* WARNING: Instruction at (ram,0x0022c30b) overlaps instruction at (ram,0x0022c30a)
    */
/* WARNING: Control flow encountered bad instruction data */

byte * FUN_0022c2e0(byte *param_1,uint param_2,uint param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  uint unaff_a8;
  int unaff_a11;
  int in_a14;
  
  if (param_3 == 0) {
    return (byte *)0x0;
  }
  if (((param_2 | (uint)param_1) & 3) == 0) goto LAB_0022c33b;
  do {
    uVar3 = (uint)*param_1;
    flix();
    iVar1 = *(int *)(param_5 + 8);
    if (in_a14 != 0) {
      if (unaff_a11 <= (int)param_1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *(uint *)(param_3 + 0x10) = unaff_a8;
    if (uVar3 != unaff_a8) {
      return (byte *)(uVar3 - unaff_a8);
    }
    do {
      flix();
      if (iVar1 == -1) {
        return param_1;
      }
      flix();
      param_3 = param_3 - 1;
      flix();
      flix();
      iVar1 = *(int *)(uVar3 + 4);
    } while (uVar3 == 0);
LAB_0022c33b:
  } while (param_3 < 4);
  flix();
  pbVar2 = (byte *)FUN_0022239d();
  return pbVar2;
}


// ===== FUN_0022c3bc @ 0022c3bc (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c3bc(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0022c4d0 @ 0022c4d0 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c4d0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022c590 @ 0022c590 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c590(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022c5b0 @ 0022c5b0 (21 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c5b0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022c79b @ 0022c79b (55 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022c79b(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int unaff_a8;
  undefined4 uVar2;
  int in_a14;
  int in_t0;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  
  if (param_3 < 0x11) {
    *(int *)(param_2 + 4) = param_3;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(int *)(param_2 + 4) = param_1;
  uVar1 = DAT_001f3018;
  flix();
  uVar2 = *(undefined4 *)(in_a14 + 0x2c);
  *(BADSPACEBASE **)(unaff_a8 + 0x30) = register0x00000004;
  flix();
  if (param_1 < 0x10) {
    func_0x0028e3a4(uVar1);
    *(undefined4 *)(in_t0 + 0x28) = uVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022d050 @ 0022d050 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022d050(void)

{
  undefined4 in_a6;
  int unaff_a11;
  
  flix();
  *(undefined4 *)(unaff_a11 + 0x20) = in_a6;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022d11b @ 0022d11b (31 bytes)

void FUN_0022d11b(undefined4 param_1,undefined4 param_2)

{
  int in_a12;
  undefined4 in_a13;
  int in_a15;
  undefined4 uStack0000010c;
  int in_stack_00000144;
  
  *(undefined4 *)(in_a12 + 0x38) = in_a13;
  flix();
  flix();
  cust1();
  uStack0000010c = 0;
  FUN_0022c79b(param_1,param_2,in_stack_00000144 - in_a15);
  return;
}


// ===== FUN_0022d6da @ 0022d6da (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022d6da(void)

{
  func_0x00240b6c();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022df88 @ 0022df88 (79 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022df88(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  int unaff_a8;
  undefined4 uVar2;
  int in_a14;
  int in_t0;
  undefined4 in_f3;
  undefined4 in_stack_00000054;
  
  *(undefined4 *)(unaff_a8 + 0x14) = in_f3;
  func_0x0024f7b4(param_5,param_6,(undefined4 *)(unaff_a8 + 0x14));
  *(int *)(in_a14 + 8) = in_t0;
  cust1();
  flix();
  cust0();
  *(int *)(param_2 + 4) = param_1;
  uVar1 = DAT_001f4c1c;
  flix();
  uVar2 = *(undefined4 *)(in_a14 + 0x30);
  *(BADSPACEBASE **)(in_t0 + 0x30) = register0x00000004;
  flix();
  if (param_1 < 5) {
    func_0x0028fba4(uVar1);
    *(undefined4 *)(in_t0 + 0x28) = uVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  *(undefined4 *)(in_t0 + 0x28) = uVar2;
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022e630 @ 0022e630 (31 bytes)

void FUN_0022e630(void)

{
  if ((PTR_DAT_00237f00 != (undefined *)0x0) && (*(int *)(PTR_DAT_00237f00 + 0x38) == 0)) {
    FUN_0022fd00();
  }
  flix();
  FUN_002266b6();
  return;
}


// ===== FUN_0022e710 @ 0022e710 (27 bytes)

undefined4 FUN_0022e710(void)

{
  if (*(int *)(PTR_DAT_00237f00 + 0x148) == 0) {
    *(undefined **)(PTR_DAT_00237f00 + 0x148) = PTR_DAT_00237f00 + 0x14c;
  }
  flix();
  return 0xffffffff;
}


// ===== FUN_0022e740 @ 0022e740 (34 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0022e72e) overlaps instruction at (ram,0x0022e72d)
    */

undefined4 FUN_0022e740(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte unaff_retaddr;
  uint unaff_a9;
  uint in_a12;
  
  flix();
  if ((unaff_a9 & 1 << (unaff_retaddr & 0x1f)) != 0) {
    if ((in_a12 & 0x2000000) == 0) {
      *(undefined4 *)(param_4 + 0x148) = param_3;
      flix();
      param_1 = 0xffffffff;
    }
    return param_1;
  }
  flix();
  flix();
  if (param_4 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return param_1;
}


// ===== FUN_0022e810 @ 0022e810 (15 bytes)

void FUN_0022e810(void)

{
  flix();
  FUN_0021ca24();
  return;
}


// ===== FUN_0022e990 @ 0022e990 (58 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0022ea47) */

void FUN_0022e990(undefined4 param_1,int param_2)

{
  int unaff_a9;
  int in_a14;
  undefined1 auStack_120 [288];
  
  flix();
  *(undefined1 **)(*(int *)(in_a14 + 0x10) + 0x3c) = auStack_120;
  flix();
  if (unaff_a9 == param_2) {
    do {
      ill();
    } while( true );
  }
  flix();
  flix();
  if (in_a14 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022fa00 @ 0022fa00 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022fa00(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022fb80 @ 0022fb80 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0022fb80(int param_1,int param_2)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x38) == 0)) {
    FUN_0022fd00(param_1);
  }
  if (*(short *)(param_2 + 0xc) == 0) {
    return 0;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022fbb0 @ 0022fbb0 (40 bytes)

undefined4 FUN_0022fbb0(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_00236000(&DAT_00237ad8,FUN_0022fb80);
    return uVar1;
  }
  uVar1 = FUN_0022fb80(PTR_DAT_00237f00,param_1);
  return uVar1;
}


// ===== FUN_0022fbe0 @ 0022fbe0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022fbe0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022fc20 @ 0022fc20 (82 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022fc20(void)

{
  undefined4 *puVar1;
  
  FUN_00235f40();
  if (DAT_00237b10 == 0) {
    FUN_0022fd00();
  }
  puVar1 = &DAT_00237db8;
  do {
    flix();
    if (puVar1[1] == 1) {
      isync();
    }
    if (0 < (int)puVar1[1]) {
      flix();
    }
    puVar1 = (undefined4 *)*puVar1;
  } while (puVar1 != (undefined4 *)0x0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022fce0 @ 0022fce0 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022fce0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022fcf0 @ 0022fcf0 (13 bytes)

void FUN_0022fcf0(void)

{
  FUN_0022fce0(&DAT_00237ad8);
  return;
}


// ===== FUN_0022fd00 @ 0022fd00 (24 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022fd00(int param_1)

{
  FUN_00235f60();
  if (*(int *)(param_1 + 0x38) != 0) {
    FUN_00235f70();
    return;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022fe10 @ 0022fe10 (19 bytes)

void FUN_0022fe10(void)

{
  FUN_00235f40();
  FUN_00235fa0(PTR_DAT_00237f00,&LAB_00235f80);
  return;
}


// ===== FUN_0022fe30 @ 0022fe30 (19 bytes)

void FUN_0022fe30(void)

{
  FUN_00235fa0(PTR_DAT_00237f00,&LAB_00235f90);
  FUN_00235f50();
  return;
}


// ===== FUN_0022fe50 @ 0022fe50 (39 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022fe50(undefined4 param_1,int param_2,int param_3)

{
  int in_a12;
  
  if (param_2 != 0) {
    do {
      FUN_00228dc0(param_1);
      flix();
      flix();
      flix();
    } while (in_a12 != param_3);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_00230015 @ 00230015 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00230015(void)

{
  int in_a14;
  
  *(int *)(in_a14 + 0x34) = in_a14;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

