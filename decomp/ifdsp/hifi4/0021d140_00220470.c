// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0021d140 @ 0021d140 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d140(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d190 @ 0021d190 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d190(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d1e0 @ 0021d1e0 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d1e0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d234 @ 0021d234 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d234(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== status_reg4_update @ 0021d270 (41 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* reg 4 = rounded value or 0x7FFF (CW zero-in offset [inference]) */

void status_reg4_update(void)

{
  int in_a7;
  int in_a13;
  
  flix();
  if (in_a13 <= in_a7) {
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d5b0 @ 0021d5b0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d5b0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d5c8 @ 0021d5c8 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d5c8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d650 @ 0021d650 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d650(void)

{
  FUN_00225340(&DAT_00247270);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d68c @ 0021d68c (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d68c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d8a0 @ 0021d8a0 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d8a0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d940 @ 0021d940 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d940(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021dbb0 @ 0021dbb0 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021dbb0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021dbd0 @ 0021dbd0 (20 bytes)

void FUN_0021dbd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  flix();
  FUN_00213839(param_1,param_2,&DAT_00247dd0,param_4,&DAT_2006ff00);
  return;
}


// ===== FUN_0021df20 @ 0021df20 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0021df20(void)

{
  DAT_00248720 = 0;
  _DAT_00248724 = 0;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021dfd6 @ 0021dfd6 (60 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021dfd6(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 *unaff_a10;
  undefined4 uVar1;
  int in_a13;
  int in_a15;
  
  uVar1 = *unaff_a10;
  flix();
  if (param_1 == param_3) {
    return;
  }
  flix();
  cust1();
  if (&stack0x00000000 != (undefined1 *)0x0) {
    FUN_00232264();
    FUN_00218fc0(uVar1,in_a13 + param_5);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_5 + -1 != in_a13 + in_a15) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0021dfe4 @ 0021dfe4 (21 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021dfe4(void)

{
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e0f4 @ 0021e0f4 (57 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0021e11c) overlaps instruction at (ram,0x0021e11b)
    */

void FUN_0021e0f4(uint param_1,uint param_2)

{
  int in_a12;
  int in_a14;
  int in_a15;
  
  FUN_0021dfe4();
  if (DAT_00248724 == 0) {
    if (param_1 != param_2) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    return;
  }
  flix();
  if (in_a14 == 0) {
    *(undefined4 *)(in_a12 + 0x30) = DAT_001e0824;
    flix();
    func_0x001edeac(param_1,param_2,0,&DAT_00249340);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((param_2 & param_2 + in_a15) != 0) {
    acquire(in_a14 + 0x1b8);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e24c @ 0021e24c (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021e24c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e520 @ 0021e520 (15 bytes)

void FUN_0021e520(undefined4 param_1,uint *param_2)

{
  byte bVar1;
  int unaff_a10;
  
  flix();
  bVar1 = *(byte *)(unaff_a10 + 0xe0);
  *param_2 = (uint)bVar1;
  param_2[1] = (uint)bVar1;
  return;
}


// ===== FUN_0021e530 @ 0021e530 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021e530(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e6b0 @ 0021e6b0 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021e6b0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e6c4 @ 0021e6c4 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021e6c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_retaddr;
  int in_a13;
  int in_a14;
  
  flix();
  if (in_a14 < in_a13) {
    FUN_0021e9d8(param_1,param_2,&DAT_00250cd0,param_4 + unaff_retaddr);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e740 @ 0021e740 (20 bytes)

/* WARNING: Instruction at (ram,0x0021e742) overlaps instruction at (ram,0x0021e740)
    */

void FUN_0021e740(void)

{
  int unaff_retaddr;
  undefined1 *puVar1;
  int unaff_a11;
  undefined1 *in_a13;
  
  flix();
  for (puVar1 = (undefined1 *)(unaff_a11 + 2); cust0(), in_a13 == puVar1;
      puVar1 = puVar1 + unaff_retaddr) {
  }
  do {
    ill();
  } while( true );
}


// ===== FUN_0021e754 @ 0021e754 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021e754(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e82c @ 0021e82c (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021e82c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e890 @ 0021e890 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021e890(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e8b0 @ 0021e8b0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021e8b0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021e9d8 @ 0021e9d8 (1 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021e9d8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021ec18 @ 0021ec18 (3 bytes)

void FUN_0021ec18(void)

{
  do {
    ill();
  } while( true );
}


// ===== FUN_0021ec20 @ 0021ec20 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021ec20(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021ec40 @ 0021ec40 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021ec40(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021ef90 @ 0021ef90 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021ef90(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021f004 @ 0021f004 (19 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021f004(void)

{
  undefined4 unaff_retaddr;
  int unaff_a10;
  uint in_a12;
  uint in_a13;
  
  flix();
  if ((in_a12 & in_a13) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined4 *)(unaff_a10 + 0x20) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021f0dc @ 0021f0dc (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021f0dc(void)

{
  FUN_0021f004();
  flix();
  FUN_0021c314();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021f2d0 @ 0021f2d0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021f2d0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== meter_to_reg4005 @ 0021f348 (67 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: This function may have set the stack pointer */
/* reg 0x4005 = 0..99 level for the M33 PWM; also level byte for reg 3 */

void meter_to_reg4005(undefined4 param_1,uint param_2)

{
  int in_a14;
  uint in_a15;
  int in_t0;
  
  do {
    flix();
    FUN_00234710();
    flix();
  } while (in_a15 < 0x100);
  *(undefined **)(in_t0 + 0x28) = &DAT_0000ffff;
  if (in_a14 < (int)(in_t0 + in_a15)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x001c6e1c();
  flix();
  func_0x002642b0(param_2 >> 0x1a);
  func_0x001e611c();
  release(in_a15);
  *(uint *)in_a15 = in_a15;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== status_reg3_update @ 0021f388 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* reg 3 = level<<8 | (255 - x) */

void status_reg3_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021f410 @ 0021f410 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021f410(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021f484 @ 0021f484 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021f484(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021f6d0 @ 0021f6d0 (26 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021f6d0(void)

{
  flix();
  func_0x001ff77c(&DAT_00253980);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021f7ec @ 0021f7ec (39 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021f7ec(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  uint in_a12;
  uint in_a13;
  
  flix();
  if ((in_a12 & in_a13) != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DAT_00253644 = param_3;
  DAT_00253646 = param_3;
  rsr(0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021f8bc @ 0021f8bc (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021f8bc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021f968 @ 0021f968 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021f968(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021fa48 @ 0021fa48 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021fa48(void)

{
  FUN_0021f7ec();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021fd20 @ 0021fd20 (65 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021fd20(undefined4 param_1,int param_2)

{
  int unaff_retaddr;
  int unaff_a9;
  int in_a12;
  int in_a15;
  
  flix();
  if (&stack0x00000000 == (undefined1 *)0x20) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (&stack0x00000000 != (undefined1 *)0x20) {
    if (in_a12 == in_a15) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_2 < -1) {
    release((int *)(unaff_retaddr + 0x30));
    *(int *)(unaff_retaddr + 0x30) = unaff_retaddr;
    flix();
    *(int *)(in_a12 + 0x24) = unaff_a9;
    wsr(0,unaff_retaddr + unaff_a9);
    rsync();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021fdbc @ 0021fdbc (19 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021fdbc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220224 @ 00220224 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220224(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220370 @ 00220370 (1 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220370(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220420 @ 00220420 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00220420(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00220470 @ 00220470 (92 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_00220470(void)

{
  int iVar1;
  int in_a5;
  int unaff_a9;
  int unaff_a11;
  undefined2 in_a12;
  int in_a14;
  
  flix();
  iVar1 = unaff_a9 + 0xb;
  *(int *)(unaff_a9 + 0x43) = iVar1;
  FUN_00220790((uint)(in_a14 < 0x7f) *
               ((uint)(-0x80 < in_a14) * in_a14 + (uint)(-0x80 >= in_a14) * -0x80) +
               (uint)(in_a14 >= 0x7f) * 0x7f,unaff_a11 + 4);
  flix();
  if (in_a5 + iVar1 < 0) {
    *(int *)(DAT_00256574 + 0x24) = iVar1;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DAT_00256574 = CONCAT22(in_a12,(undefined2)DAT_00256574);
  flix();
  func_0x0029c2ac();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

