// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0021ba54 @ 0021ba54 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021ba54(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021baa8 @ 0021baa8 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0021baa8(int param_1,uint param_2)

{
  if (*(ushort *)(param_1 + 0x52) < param_2) {
    return 0xfffff441;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021bae0 @ 0021bae0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021bae0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021bb44 @ 0021bb44 (16 bytes)

int FUN_0021bb44(void)

{
  int in_a6;
  
  flix();
  return in_a6 + -1;
}


// ===== FUN_0021bb54 @ 0021bb54 (32 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021bb54(void)

{
  int in_a6;
  
  flix();
  if (in_a6 != 0) {
    flix();
    func_0x001f04b4();
    flix();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  do {
    ill();
  } while( true );
}


// ===== FUN_0021bb84 @ 0021bb84 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021bb84(void)

{
  undefined4 unaff_retaddr;
  int in_a6;
  undefined1 auStack_20 [32];
  
  FUN_0021ab50();
  flix();
  *(undefined1 **)(in_a6 + 0x14) = auStack_20;
  flix();
  *(undefined4 *)(in_a6 + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021bbe0 @ 0021bbe0 (24 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021bbe0(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021bc20 @ 0021bc20 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0021bc20(void)

{
  int extraout_a3;
  int extraout_a5;
  
  flix();
  func_0x001f057c();
  if (extraout_a3 == extraout_a5) {
    return 0;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021bc54 @ 0021bc54 (29 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0021bcb5) */

void FUN_0021bc54(uint param_1)

{
  int unaff_retaddr;
  int in_a14;
  byte in_a15;
  
  flix();
  if ((param_1 & 1 << (in_a15 & 0x1f)) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  if (unaff_retaddr != -1) {
    if (*(short *)(param_1 + 0x7c) == 0) {
      *(int *)(in_a14 + 8) = in_a14;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    func_0x0019d974();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021bcd8 @ 0021bcd8 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021bcd8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021bd24 @ 0021bd24 (16 bytes)

void FUN_0021bd24(int param_1)

{
  if ((param_1 != 0) && (*(code **)(param_1 + 0x30) != (code *)0x0)) {
    (**(code **)(param_1 + 0x30))(param_1);
  }
  return;
}


// ===== FUN_0021bd40 @ 0021bd40 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021bd40(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021bdcc @ 0021bdcc (25 bytes)

undefined1 FUN_0021bdcc(undefined4 param_1,int param_2)

{
  flix();
  *(undefined1 *)(param_2 + 0xb) = 2;
  flix();
  return *(undefined1 *)(param_2 + 0xc);
}


// ===== FUN_0021be20 @ 0021be20 (29 bytes)

int FUN_0021be20(int param_1)

{
  uint in_a14;
  undefined1 auStack_20 [32];
  
  flix();
  *(undefined1 **)((in_a14 >> 0xe & 0x3fff) + 0x38) = auStack_20;
  return param_1 + 10;
}


// ===== FUN_0021be54 @ 0021be54 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021be54(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021be80 @ 0021be80 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021be80(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c060 @ 0021c060 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c060(void)

{
  undefined1 uVar1;
  
  FUN_0021c5cc();
  memw();
  uVar1 = DAT_40100015;
  memw();
  uVar1 = DAT_40100016;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c090 @ 0021c090 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c090(void)

{
  DAT_002390e0 = &DAT_2007e000;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c0b8 @ 0021c0b8 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c0b8(uint param_1)

{
  int in_a14;
  
  if (1 < param_1) {
    return;
  }
  flix();
  *(int *)(in_a14 + 0x28) = in_a14;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c0d4 @ 0021c0d4 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c0d4(uint param_1)

{
  if (1 < param_1) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c0e8 @ 0021c0e8 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c0e8(uint param_1)

{
  if (param_1 < 2) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0021c140 @ 0021c140 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c140(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c21c @ 0021c21c (5 bytes)

void FUN_0021c21c(void)

{
  return;
}


// ===== FUN_0021c230 @ 0021c230 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c230(void)

{
  flix();
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c314 @ 0021c314 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c314(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c360 @ 0021c360 (26 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c360(void)

{
  FUN_002260d8();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c398 @ 0021c398 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0021c398(undefined4 param_1,int param_2)

{
  if (param_2 != 0x98) {
    return 0;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c3b4 @ 0021c3b4 (58 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c3b4(void)

{
  int unaff_retaddr;
  undefined4 *puVar1;
  uint in_a6;
  uint in_a14;
  uint in_a15;
  int in_t0;
  
  FUN_00212d00(&DAT_40111000);
  flix();
  puVar1 = (undefined4 *)(in_a14 >> 5 & 0x1fff);
  unaff_retaddr = (int)puVar1 + unaff_retaddr;
  if (in_t0 < 1) {
    while (unaff_retaddr == 0) {
      unaff_retaddr = FUN_0021b078(*puVar1);
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((in_a15 & in_a6) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c498 @ 0021c498 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c498(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c560 @ 0021c560 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c560(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c598 @ 0021c598 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c598(void)

{
  flix();
  flix();
  FUN_00219808();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c5cc @ 0021c5cc (42 bytes)

undefined1 FUN_0021c5cc(void)

{
  undefined1 uVar1;
  
  if ((DAT_20070018 & 0xf000) != 0x1000) {
    memw();
    uVar1 = DAT_40100004;
    return uVar1;
  }
  memw();
  uVar1 = DAT_40100005;
  return uVar1;
}


// ===== FUN_0021c600 @ 0021c600 (15 bytes)

void FUN_0021c600(undefined4 param_1,undefined4 *param_2)

{
  flix();
  *param_2 = param_1;
  param_2[1] = param_1;
  return;
}


// ===== FUN_0021c610 @ 0021c610 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c610(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c670 @ 0021c670 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c670(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c748 @ 0021c748 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c748(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c76b @ 0021c76b (2 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c76b(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c818 @ 0021c818 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c818(void)

{
  FUN_0021c610();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c890 @ 0021c890 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c890(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021c8ac @ 0021c8ac (14 bytes)

void FUN_0021c8ac(undefined1 param_1,int param_2)

{
  flix();
  *(undefined1 *)(param_2 + 0x80) = param_1;
  return;
}


// ===== FUN_0021c8bc @ 0021c8bc (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021c8bc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021ca24 @ 0021ca24 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021ca24(int param_1)

{
  undefined4 unaff_retaddr;
  uint in_a15;
  
  if ((in_a15 & 0x10000000) != 0) {
    FUN_00235ba8();
    flix();
    *(undefined4 *)(param_1 + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((in_a15 & 0x10000000) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021cc50 @ 0021cc50 (23 bytes)

void FUN_0021cc50(undefined4 param_1,undefined4 *param_2)

{
  flix();
  *param_2 = param_1;
  param_2[1] = param_1;
  param_2[2] = param_1;
  param_2[3] = param_1;
  param_2[4] = param_1;
  param_2[5] = param_1;
  return;
}


// ===== FUN_0021cc68 @ 0021cc68 (45 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021cc68(void)

{
  int unaff_retaddr;
  int in_a7;
  int in_a13;
  
  flix();
  if (in_a7 < in_a13) {
    acquire(&DAT_00246520 + unaff_retaddr);
    FUN_00227644();
    flix();
    func_0x001c8778();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d010 @ 0021d010 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d010(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d02c @ 0021d02c (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d02c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d058 @ 0021d058 (15 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d058(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d07c @ 0021d07c (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d07c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d0a8 @ 0021d0a8 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d0a8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021d0d0 @ 0021d0d0 (26 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021d0d0(void)

{
  bool in_b10;
  
  flix();
  if (in_b10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

