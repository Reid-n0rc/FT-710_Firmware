// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00233250 @ 00233250 (11 bytes)

void FUN_00233250(int param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  flix();
  iVar2 = 0;
  do {
    uVar1 = *param_3;
    flix();
    FUN_00233280(0xd);
    FUN_00233280(uVar1);
    iVar2 = iVar2 + 1;
  } while (param_1 != iVar2);
  return;
}


// ===== FUN_00233280 @ 00233280 (17 bytes)

void FUN_00233280(void)

{
  flix();
  FUN_0022d6da();
  return;
}


// ===== FUN_0023329c @ 0023329c (7 bytes)

undefined4 FUN_0023329c(void)

{
  return 0xffffffff;
}


// ===== FUN_002332a4 @ 002332a4 (29 bytes)

void FUN_002332a4(void)

{
  FUN_00236450();
  extw();
  do {
    simcall();
    breakpoint(0x1000,0x2332b8,1,0xf);
    waiti(0xf);
  } while( true );
}


// ===== FUN_002332c4 @ 002332c4 (197 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00233315) overlaps instruction at (ram,0x00233314)
    */

longlong FUN_002332c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     int param_5,undefined4 param_6)

{
  int unaff_retaddr;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int unaff_a9;
  int in_a13;
  int iVar5;
  char in_WindowBase;
  undefined1 in_WindowStart;
  
  iVar1 = rsr(in_WindowBase);
  rsr(in_WindowStart);
  flix();
  if (param_5 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar2 = iVar1 + 1U | *(uint *)(param_4 + 0x1c);
  iVar5 = 0x20 - (LZCOUNT(-uVar2 & uVar2) & 0x1fU);
  wsr(in_WindowStart,uVar2 >> iVar5);
  iVar1 = rsr(in_WindowBase);
  puVar3 = (undefined4 *)((iVar1 + 0x1f) - LZCOUNT(-uVar2 & uVar2));
  wsr(in_WindowBase,puVar3);
  rsync();
  uVar2 = rsr(in_WindowStart);
  while( true ) {
    if (uVar2 == 0) {
      iVar1 = rsr(in_WindowBase + '\x01');
      flix();
      wsr(in_WindowStart,iVar1 << 0x20 - iVar5);
      rsync();
      return ZEXT48(puVar3) << 0x20;
    }
    if ((uVar2 & 1) == 0) break;
    puVar3 = (undefined4 *)(unaff_a9 - 0x10);
    *puVar3 = param_3;
    *(int *)(unaff_a9 + -0xc) = param_4;
    flix();
    unaff_retaddr = (int)*(short *)(unaff_a9 + 0x1f6);
    *(undefined4 *)(unaff_a9 + -4) = param_6;
    in_WindowBase = in_WindowBase + '\x01';
  }
  if ((uVar2 & 2) != 0) {
    *(undefined4 *)(in_a13 + -0x10) = param_3;
    *(int *)(in_a13 + -0xc) = param_4;
    *(undefined4 *)(in_a13 + -8) = 0;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((uVar2 & 4) != 0) {
    *(int *)(in_a13 + -0x10) = unaff_retaddr;
    *(BADSPACEBASE **)(in_a13 + -0xc) = register0x00000004;
    *(uint *)(in_a13 + -8) = uVar2;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar2 = uVar2 * 2 + 1;
  uVar4 = rsr(in_WindowBase);
  if ((uVar2 & 0x80) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  wsr(in_WindowStart,(uint)(CONCAT44(uVar2,uVar4) >> iVar5) & 0xff);
  iVar1 = rsr((char)iVar5);
  wsr(in_WindowBase,0x20 - iVar1);
  rsync();
  return CONCAT44(0x20 - iVar1,2);
}


// ===== FUN_002333e0 @ 002333e0 (15 bytes)

void FUN_002333e0(void)

{
  rsr(0);
  flix();
  FUN_0022df88();
  return;
}


// ===== xthal_set_region_attribute @ 00233410 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00233417) overlaps instruction at (ram,0x00233416)
    */
/* (vaddr, size, cattr, flags): called by the DSP main with (0x20060000, 0x31E0, 2, 0) and
   (0x20070000, 0x10000, 2, 0); T12c proposed memset, but memset is 0x235EB0 [inference] */

void xthal_set_region_attribute(void)

{
  int unaff_retaddr;
  int in_a6;
  int in_a13;
  undefined2 in_a15;
  
  flix();
  if (unaff_retaddr <= in_a6) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (in_a13 != 0x100) {
    flix();
    uRam655464d2 = in_a15;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00233580 @ 00233580 (32 bytes)

uint FUN_00233580(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar2 = 0;
  do {
    uVar2 = uVar2 + 0xe0000000;
    uVar3 = rdtlb1(uVar2);
    dsync();
    uVar1 = uVar1 << 4 | uVar3 & 0xf;
  } while (0xf < uVar2);
  return uVar1;
}


// ===== FUN_002335a0 @ 002335a0 (83 bytes)

void FUN_002335a0(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  uVar2 = param_1;
  do {
    if (iVar1 == 0) {
      witlb(0,uVar2 & 0xf);
      isync();
    }
    else {
      witlb(iVar1,uVar2 & 0xf);
      if (iVar1 + 0x20000000U < 0x10) {
        isync();
        uVar2 = 0;
        do {
          wdtlb(uVar2,param_1 & 0xf);
          uVar2 = uVar2 + 0x20000000;
          param_1 = param_1 >> 4;
        } while (0xf < uVar2);
        dsync();
        return;
      }
    }
    iVar1 = iVar1 + 0x20000000;
    uVar2 = uVar2 >> 4;
  } while( true );
}


// ===== FUN_00233600 @ 00233600 (58 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00233600(int param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((~param_2 & 0x7ff00000) == 0) {
    if ((param_2 & 0xfffff) != 0 || param_1 != 0) {
      param_2 = 0;
    }
  }
  else {
    flix();
    if (&stack0x00000000 != (undefined1 *)0x10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (param_3 - param_4 < 0x20) {
      if (0 < param_3 - param_4) {
        flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      return 0;
    }
  }
  uVar1 = 0x80000000;
  if (-1 < (int)param_2) {
    uVar1 = 0x7fffffff;
  }
  return uVar1;
}


// ===== FUN_00233650 @ 00233650 (30 bytes)

/* WARNING: Removing unreachable block (ram,0x0023365f) */
/* WARNING: Removing unreachable block (ram,0x00233661) */

void FUN_00233650(void)

{
  return;
}


// ===== FUN_00233670 @ 00233670 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00233670(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00233818 @ 00233818 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00233818(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00233920 @ 00233920 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00233920(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (2 < param_3) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_00233970 @ 00233970 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00233970(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00233984 @ 00233984 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00233984(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00233a10 @ 00233a10 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00233a10(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00233cf0 @ 00233cf0 (22 bytes)

int FUN_00233cf0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int unaff_a8;
  
  flix();
  flix();
  if (param_2 != 0) {
    param_4 = unaff_a8;
  }
  return param_1 * 4 + param_4 + 0x17;
}


// ===== FUN_00233d08 @ 00233d08 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00233d11) overlaps instruction at (ram,0x00233d10)
    */

void FUN_00233d08(int param_1)

{
  int unaff_retaddr;
  int in_a13;
  undefined1 auStack_20 [32];
  
  flix();
  if (param_1 != unaff_retaddr) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  release(in_a13 + 0x180);
  *(undefined1 **)(in_a13 + 0x180) = auStack_20;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00233d70 @ 00233d70 (93 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00233d7a) overlaps instruction at (ram,0x00233d78)
    */
/* WARNING: This function may have set the stack pointer */

int FUN_00233d70(uint param_1,uint param_2,undefined4 param_3,uint param_4,uint param_5,uint param_6
                )

{
  uint unaff_retaddr;
  uint unaff_a8;
  int unaff_a9;
  uint unaff_a10;
  uint unaff_a11;
  uint in_a12;
  int in_a13;
  uint in_a14;
  
  flix();
  if (unaff_a11 <= in_a14) {
    cust0();
    if (param_2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    flix();
    if (param_1 == unaff_retaddr) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((param_2 & 0x20) == 0) {
    unaff_a11 = param_6 ^ unaff_retaddr;
    cust0();
    if ((unaff_a8 & 0x20) == 0) {
      func_0x00238ea4();
      flix();
      if ((~param_5 & in_a12) != 0) {
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((param_1 & 0x20) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((param_1 & unaff_a10) != 0) {
      return unaff_a9;
    }
  }
  else {
    if (unaff_a9 <= (int)unaff_retaddr) {
      func_0x0025697c();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *(undefined4 *)(unaff_a9 + 0x1c) = 0x20;
    *(uint *)(unaff_a9 + 0x28) = unaff_retaddr;
    *(uint *)(unaff_a9 + 0x28) = param_2;
  }
  *(uint *)(param_5 + 0x28) = param_1;
  if ((unaff_a8 & 2) != 0) {
    if (in_a13 == 0x20) {
      if (param_2 != 0) {
        param_4 = unaff_a8;
      }
      return param_1 * 4 + param_4 + 0x17;
    }
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((unaff_a11 & 0x20) != 0) {
    if ((param_1 & 0x20) == 0) {
      cust1();
      *(uint *)(unaff_a8 + 8) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((param_4 & unaff_a10) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    func_0x00248948();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00233eb0 @ 00233eb0 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00233eb0(void)

{
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002340f0 @ 002340f0 (11 bytes)

int FUN_002340f0(int param_1)

{
  return param_1 * 0x20 + 0x1e;
}


// ===== iir_cascade_init @ 002340fc (11 bytes)

void iir_cascade_init(void)

{
  flix();
  FUN_0022d050();
  return;
}


// ===== iir_cascade_process @ 002341c0 (11 bytes)

void iir_cascade_process(undefined4 *param_1)

{
  flix();
  while( true ) {
    param_1 = param_1 + -1;
    if ((code *)*param_1 == (code *)0xffffffff) break;
    (*(code *)*param_1)();
  }
  return;
}


// ===== FUN_00234710 @ 00234710 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00234710(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00234730 @ 00234730 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00234730(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00234750 @ 00234750 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0023475c) overlaps instruction at (ram,0x0023475b)
    */

void FUN_00234750(void)

{
  uint unaff_retaddr;
  uint in_a6;
  int unaff_a11;
  int in_a14;
  
  flix();
  if (unaff_a11 <= in_a14) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((in_a6 & unaff_retaddr) != 0) {
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00234890 @ 00234890 (77 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00234890(int param_1)

{
  uint unaff_retaddr;
  uint in_a6;
  int unaff_a9;
  uint unaff_a11;
  int in_a13;
  uint in_a14;
  undefined4 local_20 [8];
  
  flix();
  if (in_a14 < unaff_a11) {
    acquire(unaff_a9 + 0x20);
    if (in_a13 < 0x80) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    func_0x0023e410(param_1,local_20[0],0xc);
    if ((int)local_20 * 3 != 0) {
      return;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((in_a6 & unaff_retaddr) != 0) {
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (unaff_a9 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((DAT_001ff4ac + param_1 & DAT_001f7d30) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002349f0 @ 002349f0 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002349f0(void)

{
  uint unaff_retaddr;
  uint in_a12;
  
  flix();
  if ((unaff_retaddr & in_a12) != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00234b50 @ 00234b50 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00234b50(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00234be0 @ 00234be0 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00234be0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00234e00 @ 00234e00 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00234e00(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00234f40 @ 00234f40 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00234f40(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00235190 @ 00235190 (29 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00235190(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5)

{
  uint unaff_retaddr;
  uint unaff_a11;
  uint in_a14;
  int in_a15;
  
  flix();
  if (in_a14 < unaff_a11) {
    *(undefined4 *)(in_a15 + 4) = param_2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((param_5 & unaff_retaddr) != 0) {
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00235370 @ 00235370 (35 bytes)

void FUN_00235370(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  flix();
  iVar1 = *param_1;
  if (iVar1 != 0) {
    *(undefined4 *)(param_2 + 0xc) = param_5;
    *(int *)(param_2 + 8) = iVar1;
    *(int *)(*param_1 + 0xc) = param_2;
    *param_1 = param_2;
    return;
  }
  *param_1 = param_2;
  *(undefined4 *)(param_2 + 8) = param_5;
  *(undefined4 *)(*param_1 + 0xc) = param_5;
  return;
}


// ===== FUN_00235398 @ 00235398 (38 bytes)

void FUN_00235398(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((iVar1 == 0) || (param_2 == 0)) {
    return;
  }
  if (iVar1 == param_2) {
    *param_1 = *(int *)(iVar1 + 8);
    return;
  }
  iVar1 = *(int *)(param_2 + 0xc);
  if (*(int *)(param_2 + 8) != 0) {
    *(int *)(iVar1 + 8) = *(int *)(param_2 + 8);
    *(int *)(*(int *)(param_2 + 8) + 0xc) = iVar1;
    return;
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  return;
}


// ===== FUN_002353c0 @ 002353c0 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_002353c0(int param_1)

{
  if (param_1 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 1;
}


// ===== FUN_002353e0 @ 002353e0 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_002353e0(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_002353f4 @ 002353f4 (9 bytes)

void FUN_002353f4(void)

{
  flix();
  FUN_0022b456();
  return;
}


// ===== FUN_00235410 @ 00235410 (16 bytes)

void FUN_00235410(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  *(int **)(param_2 + 4) = piVar1;
  *piVar1 = param_2;
  *(int *)(param_1 + 4) = param_2;
  *(int *)(param_2 + 0x48) = param_1;
  return;
}


// ===== FUN_00235420 @ 00235420 (25 bytes)

void FUN_00235420(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    param_1[1] = (int)param_2;
  }
  else {
    *(int **)(iVar1 + 4) = param_2;
  }
  *param_2 = iVar1;
  param_2[1] = (int)param_1;
  *param_1 = (int)param_2;
  param_2[0x12] = (int)param_1;
  return;
}


// ===== FUN_0023543c @ 0023543c (46 bytes)

void FUN_0023543c(int *param_1,undefined4 *param_2)

{
  int extraout_a4;
  int extraout_a5;
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1;
  do {
    piVar2 = piVar1;
    piVar1 = (int *)*piVar2;
    if (piVar1 == (int *)0x0) {
      param_1[1] = (int)param_2;
      break;
    }
    flix();
    FUN_002121bc();
    flix();
    cust0();
  } while (extraout_a5 <= extraout_a4);
  param_2[1] = piVar2;
  *piVar2 = (int)param_2;
  *param_2 = piVar1;
  if (piVar1 != (int *)0x0) {
    piVar1[1] = (int)param_2;
  }
  param_2[0x12] = param_1;
  return;
}


// ===== FUN_0023546c @ 0023546c (58 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0023546c(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5,int *param_6)

{
  uint uVar1;
  int iVar2;
  uint unaff_a8;
  uint unaff_a11;
  
  flix();
  if ((unaff_a11 & 1) != 0) {
    param_2[1] = (int)param_6;
    *param_6 = (int)param_2;
    *param_2 = param_5;
    if (param_5 != 0) {
      *(int **)(param_5 + 4) = param_2;
    }
    param_2[0x12] = param_1;
    return;
  }
  flix();
  iVar2 = 0x48;
  if (param_3 != 0) {
    iVar2 = param_5;
  }
  uVar1 = *(int *)(param_1 + 0x24) - iVar2 & (uint)param_6;
  *(uint *)(param_1 + 0x24) = uVar1 - 4 & unaff_a8;
  *(uint *)(param_1 + 0x14) = uVar1;
  flix();
  if (param_1 != 0) {
    flix();
    FUN_00230015();
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002354b8 @ 002354b8 (7 bytes)

undefined4 FUN_002354b8(void)

{
  return 0;
}


// ===== FUN_002354c0 @ 002354c0 (25 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002354c0(undefined4 *param_1)

{
  undefined4 unaff_a8;
  
  flix();
  param_1[3] = unaff_a8;
  param_1[2] = unaff_a8;
  param_1[5] = unaff_a8;
  param_1[4] = unaff_a8;
  *(char *)(param_1 + 8) = (char)unaff_a8;
  *param_1 = unaff_a8;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002354e0 @ 002354e0 (43 bytes)

undefined8 FUN_002354e0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 in_EPC1;
  undefined1 in_EXCSAVE1;
  undefined1 in_EXCSAVE4;
  undefined1 in_EXCCAUSE;
  
  uVar1 = rsr(in_EXCSAVE4);
  wsr(in_EXCSAVE4,param_1);
  simcall();
  wsr(in_EXCCAUSE,0x15);
  rsr(in_EXCSAVE4);
  xsr(in_EXCSAVE1,uVar1);
  iVar2 = rsr(0);
  uVar1 = rsr(in_EPC1);
  return CONCAT44(uVar1,iVar2 + -0x10);
}


// ===== FUN_00235510 @ 00235510 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00235510(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00235570 @ 00235570 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00235570(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00235630 @ 00235630 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00235630(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002357c0 @ 002357c0 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002357c0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

