// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00200ef8 @ 00200ef8 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00200ef8(void)

{
  func_0x002787b8();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00201a1a @ 00201a1a (2 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00201a1a(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00201e38 @ 00201e38 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00201e38(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020218c @ 0020218c (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020218c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00202258 @ 00202258 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00202258(void)

{
  uint in_a7;
  uint in_a15;
  
  flix();
  if (in_a15 < in_a7) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00202315 @ 00202315 (2 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00202315(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00202878 @ 00202878 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00202878(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00202bec @ 00202bec (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00202bec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020358a @ 0020358a (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020358a(undefined4 param_1,undefined4 param_2)

{
  int in_a7;
  int in_a15;
  undefined8 uVar1;
  
  uVar1 = func_0x0023e920();
  if (in_a15 == 0) {
    *(undefined4 *)((int)uVar1 + 0x20) = param_2;
    *(undefined4 *)(*(int *)((int)((ulonglong)uVar1 >> 0x20) + 0xc) + 0x34) = param_2;
    *(undefined4 *)(in_a7 + 0x38) = param_2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x0023c028();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00203fc0 @ 00203fc0 (60 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0020400f) overlaps instruction at (ram,0x0020400e)
    */

void FUN_00203fc0(uint param_1,uint param_2,int param_3,undefined4 param_4,uint param_5,int param_6)

{
  uint unaff_retaddr;
  uint uVar1;
  undefined4 *unaff_a8;
  uint unaff_a9;
  uint unaff_a10;
  uint unaff_a11;
  uint in_a13;
  undefined2 in_a15;
  
  if (unaff_a9 < 0x40) {
    acquire(param_6 + 0x160);
    *(uint *)(param_6 + 0x30) = unaff_a10;
    if (unaff_a11 <= unaff_a9) {
      if ((unaff_retaddr & 0x8000000) == 0) {
        flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (param_5 <= in_a13) {
        flix();
        flix();
        *unaff_a8 = *(undefined4 *)(param_5 + 0x30);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (0xf < param_6) {
      uVar1 = unaff_a9 + param_3;
      if ((uVar1 & 0x8000000) == 0) {
        func_0x001bdb84();
        flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if ((param_2 & 1 << ((byte)param_2 & 0x1f)) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (unaff_a11 <= param_5) {
        func_0x00189b28();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      *(uint *)(uVar1 + 0x2c) = uVar1;
      if (((param_5 & 1 << ((byte)in_a15 & 0x1f)) == 0) || ((~(param_2 + 6) & param_1) != 0)) {
        if (unaff_a9 < 0x10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        if (unaff_retaddr <= param_5) {
          *(undefined2 *)(param_2 + 0x6e) = in_a15;
          flix();
          if ((~unaff_a10 & param_2) == 0) {
            if (2 < param_5) {
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            }
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
        }
      }
      else {
        *(char *)(unaff_a10 + 0x86) = (char)unaff_a11;
        if ((int)param_5 < (int)unaff_a10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00204234 @ 00204234 (5 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00204234(void)

{
  int unaff_retaddr;
  undefined4 unaff_a11;
  
  flix();
  *(undefined4 *)(unaff_retaddr + 0x18) = unaff_a11;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00204340 @ 00204340 (26 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00204345) overlaps instruction at (ram,0x00204343)
    */

void FUN_00204340(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5,
                 undefined4 *param_6)

{
  undefined *puVar1;
  uint unaff_retaddr;
  int extraout_a3;
  int extraout_a4;
  undefined4 *unaff_a8;
  int unaff_a9;
  uint unaff_a10;
  undefined4 *in_a12;
  
  if (unaff_a8 < &DAT_00008000) {
    if (unaff_retaddr < 0x8000) {
      do {
        ill();
      } while( true );
    }
    do {
      ill();
    } while( true );
  }
  if (param_5 < 0xc) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (unaff_a10 <= param_1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (5 < unaff_a10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 < 3) {
    param_4 = *(uint *)(unaff_a9 + 0x28);
  }
  else {
    *(undefined4 *)(param_5 + 0x2c) = 0xfffffd39;
    if (0x3f < unaff_a9) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (((uint)unaff_a8 & 0x4000000) == 0) {
      flix();
      func_0x00212760();
      if (extraout_a4 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (param_6 <= unaff_a8) {
        func_0x001c5314();
        if (0xfffffd38 < param_1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  if (in_a12 <= param_6) {
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (((uint)unaff_a8 & 0x800) == 0) {
    flix();
    unaff_a8 = (undefined4 *)0x180;
    if (0xff < param_1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  flix();
  if (&stack0x00000000 != (undefined1 *)0x789a) {
    if ((param_4 & 0x2000000) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    func_0x00215ea0();
    if (((uint)unaff_a8 & 0x8000000) != 0) {
      *unaff_a8 = 0xfffffd39;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar1 = &UNK_0020430d;
  func_0x0026de7c();
  if (puVar1 != (undefined *)0x0) {
    *(undefined4 *)(extraout_a3 + 0xc) = 0x3a;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002044e7 @ 002044e7 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002044e7(undefined4 param_1,undefined4 param_2)

{
  int in_a15;
  
  *(undefined4 *)(in_a15 + 0x2c) = param_2;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002054f8 @ 002054f8 (5 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002054f8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00207220 @ 00207220 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00207220(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00207cf0 @ 00207cf0 (60 bytes)

/* WARNING: Removing unreachable block (ram,0x00207d1a) */

void FUN_00207cf0(void)

{
  code *pcVar1;
  
  if (DAT_00238400 == '\0') {
    DAT_00238400 = 0;
    pcVar1 = *(code **)PTR_DAT_00236820;
    while (pcVar1 != (code *)0x0) {
      PTR_DAT_00236820 = PTR_DAT_00236820 + 4;
      (*pcVar1)();
      pcVar1 = *(code **)PTR_DAT_00236820;
    }
    DAT_00238400 = 1;
    return;
  }
  return;
}


// ===== FUN_00207d2c @ 00207d2c (25 bytes)

/* WARNING: Removing unreachable block (ram,0x00207d37) */

void FUN_00207d2c(void)

{
  return;
}


// ===== FUN_00207d50 @ 00207d50 (8 bytes)

void FUN_00207d50(void)

{
  FUN_00208050();
  return;
}


// ===== FUN_00207d58 @ 00207d58 (26 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00207d58(void)

{
  undefined4 uVar1;
  int in_a15;
  
  memw();
  uVar1 = DAT_40021434;
  flix();
  *(undefined4 *)(in_a15 + 0x20) = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208050 @ 00208050 (5 bytes)

void FUN_00208050(void)

{
  return;
}


// ===== FUN_00208060 @ 00208060 (72 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208060(void)

{
  int unaff_retaddr;
  int unaff_a9;
  uint unaff_a11;
  int in_a12;
  int in_a15;
  
  flix();
  if (in_a15 != 0) {
    *(int *)(unaff_retaddr + 0xc) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  flix();
  flix();
  if (unaff_a9 == 5) {
    memw();
    DAT_40021048 = in_a12 << 0x20 - (0x20 - (unaff_a11 & 0x1f));
  }
  flix();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208164 @ 00208164 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208164(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020821c @ 0020821c (23 bytes)

void FUN_0020821c(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0;
  return;
}


// ===== FUN_00208234 @ 00208234 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208234(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208268 @ 00208268 (44 bytes)

void FUN_00208268(int param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0x79ffffff | 0x80000000;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0x79ffffff;
  return;
}


// ===== FUN_00208294 @ 00208294 (65 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208294(void)

{
  int iVar1;
  uint extraout_a5;
  byte in_a7;
  int unaff_a10;
  int in_a12;
  
  memw();
  flix();
  iVar1 = func_0x001e0404();
  while( true ) {
    flix();
    if ((extraout_a5 & 1 << (in_a7 & 0x1f)) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (unaff_a10 != 0) break;
    flix();
    if (in_a12 != 0x7000000) {
      memw();
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | extraout_a5;
      return;
    }
  }
  *(short *)(*(int *)(in_a12 + 4) + 0x66) = (short)iVar1;
  return;
}


// ===== FUN_002082c8 @ 002082c8 (29 bytes)

void FUN_002082c8(int param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xb9ffffff | (uint)&DAT_40000000;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xb9ffffff;
  return;
}


// ===== FUN_002082f4 @ 002082f4 (44 bytes)

void FUN_002082f4(int param_1,int param_2)

{
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xf9ffbfff | (uint)&DAT_00004000;
    return;
  }
  memw();
  memw();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xf9ffbfff;
  return;
}


// ===== FUN_00208320 @ 00208320 (63 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00208357) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_00208320(void)

{
  int in_a5;
  int unaff_a9;
  int in_a12;
  int in_a13;
  int in_a14;
  
  memw();
  flix();
  if (in_a14 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  if (in_a12 == unaff_a9) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  if (in_a14 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cust1();
  flix();
  if (in_a5 != 0x100) {
    memw();
    unique0x1000000d = unaff_a9;
    *(int *)(*(int *)(in_a13 + 0x34) + 0xc) = unaff_a9;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208360 @ 00208360 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208360(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002083d0 @ 002083d0 (59 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002083d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 unaff_retaddr;
  int unaff_a8;
  undefined4 unaff_a9;
  undefined4 in_t0;
  
  if (param_2 != 0) {
    memw();
    flix();
    *(undefined4 *)(param_5 + 4) = unaff_retaddr;
    *(undefined4 *)(unaff_a8 + 0x20) = unaff_a9;
    func_0x001f31a8();
    memw();
    *(undefined4 *)(param_1 + 0xc) = in_t0;
    memw();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xff00ffff;
  return;
}


// ===== FUN_00208450 @ 00208450 (24 bytes)

void FUN_00208450(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = param_2 | *(uint *)(param_1 + 0x10) & 0xff00ffc0;
  return;
}


// ===== FUN_00208468 @ 00208468 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208468(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int in_a12;
  
  memw();
  flix();
  if (in_a12 != 0) {
    memw();
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | param_4;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208484 @ 00208484 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208484(void)

{
  memw();
  flix();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002084d8 @ 002084d8 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002084d8(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208514 @ 00208514 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208514(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020853c @ 0020853c (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020853c(void)

{
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020856c @ 0020856c (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020856c(void)

{
  int iVar1;
  undefined2 uVar2;
  int in_a14;
  
  flix();
  iVar1 = 0x208578;
  uVar2 = func_0x001e8670();
  flix();
  if (in_a14 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (iVar1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uRam00000066 = uVar2;
  return;
}


// ===== FUN_002085dc @ 002085dc (26 bytes)

void FUN_002085dc(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = 0;
  *(undefined1 *)param_1 = 0;
  *(undefined1 *)((int)param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 2) = 0;
  return;
}


// ===== CLOCK_AttachClk @ 00208600 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void CLOCK_AttachClk(void)

{
  uint extraout_a3;
  uint in_a7;
  
  flix();
  func_0x001e8700();
  flix();
  if ((extraout_a3 & in_a7) == 0) {
    do {
      ill();
    } while( true );
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208654 @ 00208654 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208654(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208690 @ 00208690 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00208690(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002086b4 @ 002086b4 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002086b4(void)

{
  undefined4 uVar1;
  
  memw();
  uVar1 = DAT_40001100;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002086e0 @ 002086e0 (127 bytes)

int FUN_002086e0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 in_a7;
  undefined4 *in_a15;
  
  memw();
  uVar2 = DAT_40001200;
  flix();
  *in_a15 = in_a7;
  if (uVar2 == 1) {
    memw();
    iVar1 = DAT_40001168;
    if (iVar1 == 0) {
      memw();
      param_1 = DAT_00238420;
    }
    else {
      memw();
      memw();
      iVar1 = DAT_40001168;
      flix();
      if (iVar1 == 0) {
        param_1 = DAT_0023841c;
      }
    }
  }
  else {
    flix();
  }
  memw();
  uVar3 = DAT_40001204;
  if ((uVar3 & 1) == 0) {
    memw();
    iVar1 = DAT_40001210;
    memw();
    flix();
    flix();
    memw();
    uVar3 = DAT_40001204;
    return ((uVar3 & uVar2) >> 0x10) * param_1 + param_1 * iVar1;
  }
  return param_1;
}


// ===== FUN_0020876c @ 0020876c (103 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0020876c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_002086e0();
  memw();
  uVar1 = DAT_40001204;
  if ((uVar1 & 1) != 0) {
    return uVar2;
  }
  if (param_1 == 0) {
    memw();
    uVar2 = DAT_40001218;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 == 1) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 != 2) {
    if (param_1 != 3) {
      return 0;
    }
    flix();
    flix();
    memw();
    uVar2 = DAT_40001218;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  flix();
  memw();
  uVar2 = DAT_40001218;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208818 @ 00208818 (127 bytes)

int FUN_00208818(int param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5,
                undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  uint unaff_retaddr;
  undefined4 *in_a15;
  
  memw();
  iVar1 = DAT_40021200;
  flix();
  *in_a15 = param_6;
  if (iVar1 == 1) {
    memw();
    iVar1 = DAT_40001168;
    if (iVar1 == 0) {
      memw();
      param_1 = DAT_00238420;
    }
    else {
      memw();
      memw();
      iVar1 = DAT_40001168;
      flix();
      if (iVar1 == 0) {
        param_1 = DAT_0023841c;
      }
    }
  }
  else {
    flix();
    unaff_retaddr = param_5 & 0xfff;
  }
  memw();
  uVar2 = DAT_40021204;
  if ((uVar2 & 1) == 0) {
    memw();
    iVar1 = DAT_40021210;
    memw();
    flix();
    memw();
    uVar2 = DAT_40021204;
    return ((uVar2 & 0xff0000) >> 0x10) * (*(int *)(param_4 + 0x28) + unaff_retaddr) +
           param_1 * iVar1;
  }
  return param_1;
}


// ===== FUN_002088a8 @ 002088a8 (103 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_002088a8(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_00208818();
  memw();
  uVar1 = DAT_40021204;
  if ((uVar1 & 1) != 0) {
    return uVar2;
  }
  if (param_1 == 0) {
    memw();
    uVar2 = DAT_40021218;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 == 1) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 != 2) {
    if (param_1 != 3) {
      return 0;
    }
    flix();
    flix();
    memw();
    uVar2 = DAT_40021218;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  flix();
  memw();
  uVar2 = DAT_40021218;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208958 @ 00208958 (156 bytes)

undefined * FUN_00208958(undefined *param_1)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  int unaff_a10;
  
  flix();
  memw();
  uVar3 = DAT_40001434;
  uVar3 = uVar3 & 3;
  if (uVar3 == 0) {
    memw();
    uVar3 = DAT_40001430;
    uVar3 = uVar3 & 3;
    if (uVar3 == 0) {
      uVar3 = FUN_002086b4();
      return (undefined *)(uVar3 >> 2);
    }
    if (uVar3 == 1) {
      memw();
      if (*(int *)(unaff_a10 + 0x368) != 0) {
        memw();
        memw();
        if (*(int *)(unaff_a10 + 0x368) == 1) {
          param_1 = DAT_0023841c;
        }
        return param_1;
      }
      memw();
      return DAT_00238420;
    }
    if (uVar3 == 2) {
      return &DAT_000f4240;
    }
    if (uVar3 == 3) {
      puVar1 = (undefined *)FUN_002086b4();
      return puVar1;
    }
  }
  else {
    if (uVar3 == 1) {
      return (undefined *)0xf42400;
    }
    if (uVar3 == 2) {
      uVar2 = FUN_0020876c(0);
      memw();
      uVar3 = DAT_40001240;
      return (undefined *)(uVar2 / ((uVar3 & 0xff) + 1));
    }
    if (uVar3 == 3) {
      memw();
      if ((*(uint *)(unaff_a10 + 0x3c0) & 1) != 0) {
        param_1 = &DAT_00008000;
      }
      return param_1;
    }
  }
  return (undefined *)0x0;
}


// ===== FUN_002089f8 @ 002089f8 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002089f8(void)

{
  undefined4 uVar1;
  int in_a15;
  
  flix();
  memw();
  uVar1 = DAT_40021434;
  flix();
  *(uint *)(in_a15 + 0x20) = (uint)*(byte *)(in_a15 + 0xe0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00208aa8 @ 00208aa8 (88 bytes)

uint FUN_00208aa8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *in_a15;
  
  memw();
  iVar1 = DAT_400016d4;
  flix();
  *in_a15 = param_5;
  flix();
  flix();
  if (iVar1 != 5) {
    memw();
    uVar2 = DAT_400016d8;
    return 0;
  }
  uVar4 = FUN_0020876c(3);
  memw();
  memw();
  uVar3 = DAT_400016d8;
  return (uVar4 / ((*(uint *)(param_2 + 0x4c) & 0xff) + 1)) / ((uVar3 & 0xff) + 1);
}

