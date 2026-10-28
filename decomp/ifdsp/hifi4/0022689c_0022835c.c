// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0022689c @ 0022689c (20 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0022689c(uint param_1)

{
  if (param_1 < 0x40) {
    rsr(0);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== xos_msgq_create @ 00226a50 (19 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* called by Thread_Ipc and the other thread creators [inference] */

undefined4 xos_msgq_create(int param_1)

{
  if (param_1 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00226aa4 @ 00226aa4 (21 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00226aa4(int param_1)

{
  undefined4 unaff_a9;
  int in_a12;
  
  if (param_1 == 0) {
    return 0xffff0001;
  }
  rsr(0);
  flix();
  *(undefined4 *)(in_a12 + 4) = unaff_a9;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== xos_msgq_put @ 00226b38 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* called from ipc_ept_rx_cb [inference] */

undefined4 xos_msgq_put(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    rsr(0);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00226bc4 @ 00226bc4 (48 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00226bc4(int param_1,int param_2)

{
  uint in_a13;
  uint in_a14;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    rsr(0);
    flix();
    flix();
    wsr(0,in_a13 | in_a14);
    rsync();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== xos_msgq_get @ 00226cec (23 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* Thread_Ipc main loop [inference] */

undefined4 xos_msgq_get(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    rsr(0);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00226d7c @ 00226d7c (50 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00226d7c(int param_1,int param_2)

{
  uint in_a13;
  uint in_a14;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    rsr(0);
    flix();
    flix();
    wsr(0,in_a13 | in_a14);
    rsync();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00226eb0 @ 00226eb0 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00226eb0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00226f58 @ 00226f58 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00226f58(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00226f70 @ 00226f70 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00226f70(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022700c @ 0022700c (55 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4
FUN_0022700c(undefined4 *param_1,uint param_2,int param_3,int *param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  int unaff_a9;
  int in_a13;
  int in_SCOMPARE1;
  undefined1 auStack_20 [32];
  
  if ((param_1 != (undefined4 *)0x0) && (-1 < param_3)) {
    flix();
    *param_1 = param_6;
    param_1[5] = param_6;
    flix();
    *(uint *)(unaff_a9 + 4) = param_2 >> 0x10 & 0xfff;
    iVar1 = *(int *)(*param_4 + 0x1b8);
    if (iVar1 == in_SCOMPARE1) {
      *(int *)(*param_4 + 0x1b8) = (int)auStack_20;
    }
    *(short *)(param_2 + 10) = (short)param_1;
    *(int *)(in_a13 + 0x38) = iVar1;
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00227058 @ 00227058 (71 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00227058(int *param_1)

{
  int iVar1;
  undefined4 extraout_a5;
  uint uVar2;
  int iVar3;
  
  iVar1 = DAT_00237858;
  uVar2 = rsr(0);
  if ((uVar2 & 0x20) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 == (int *)0x0) {
    return 0xffff0001;
  }
  FUN_00227f3c();
  iVar3 = *param_1;
  if (iVar3 != 0) {
    if (iVar3 != iVar1) {
      FUN_00227f58();
      return 0xffff0005;
    }
    if (iVar3 != 0) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  flix();
  iVar1 = FUN_00207220();
  *(char *)(iVar1 + 0x1c) = (char)extraout_a5;
  *(undefined4 *)(iVar1 + 0x18) = extraout_a5;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== xos_mutex_lock @ 002270d4 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* around the reply rpmsg_lite_send [inference] */

void xos_mutex_lock(void)

{
  uint uVar1;
  
  uVar1 = rsr(0);
  if ((uVar1 & 0x20) == 0) {
    flix();
    cust1();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00227168 @ 00227168 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00227168(void)

{
  uint uVar1;
  
  uVar1 = rsr(0);
  if ((uVar1 & 0x20) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  return 0xffff0001;
}


// ===== xos_mutex_unlock @ 00227230 (84 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* [inference] */

undefined4 xos_mutex_unlock(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int in_a14;
  undefined4 in_t0;
  
  uVar1 = rsr(0);
  if ((uVar1 & 0x20) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 != (undefined4 *)0x0) {
    FUN_00227f3c();
    flix();
    *(undefined4 *)(in_a14 + 8) = in_t0;
    iVar2 = param_1[5];
    param_1[5] = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_00227ff0(&DAT_00237858,param_1);
      iVar2 = FUN_002274c8(param_1 + 1);
      if (iVar2 != 0) {
        flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      *param_1 = 0;
    }
    FUN_00227f58();
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_00227294 @ 00227294 (73 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00227294(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = DAT_00237858;
  uVar3 = rsr(0);
  if ((uVar3 & 0x20) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 == (int *)0x0) {
    return 0xffff0001;
  }
  FUN_00227f3c();
  if (*param_1 == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (*param_1 == iVar1) {
    param_1[5] = param_1[5] + 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffff0004;
  }
  FUN_00227f58();
  return uVar2;
}


// ===== FUN_002272ec @ 002272ec (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002272ec(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00227300 @ 00227300 (63 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00227300(undefined *param_1,int param_2)

{
  int unaff_retaddr;
  int unaff_a9;
  undefined1 auStack_20 [32];
  
  if (param_1 == (undefined *)0x1) {
    param_1 = &DAT_002cb0f0;
  }
  if (((param_1 != (undefined *)0x0) && (param_2 != 0)) && (*(int *)(param_1 + 0x68) == 0x54485244))
  {
    if (param_1 == (undefined *)0x2) {
      flix();
      *(int *)(unaff_a9 + 4) = unaff_retaddr;
      *(undefined1 **)(unaff_retaddr + 0x38) = auStack_20;
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== xos_get_cpu_load @ 0022735c (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void xos_get_cpu_load(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002274c8 @ 002274c8 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002274c8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== xos_thread_create @ 002274e0 (16 bytes)

/* called with thread entry, name, stack [inference] */

undefined4 xos_thread_create(void)

{
  flix();
  func_0x001e24ec();
  return 0xffff0001;
}


// ===== FUN_00227644 @ 00227644 (109 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00227698) overlaps instruction at (ram,0x00227697)
    */

undefined4
FUN_00227644(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,int param_5,
            undefined4 param_6,undefined4 param_7,int param_8)

{
  int unaff_a10;
  int unaff_a11;
  int in_a14;
  
  if ((param_3 & 2) == 0) {
    *(undefined1 **)(param_5 + 0xc) = &LAB_00228c94;
    *(int *)(param_5 + 0x1c) = unaff_a11;
    if (param_2 != 0) {
      return 0xffff0013;
    }
    if (param_8 != 0) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined1 **)(param_5 + 0xc) = &LAB_00228c94;
  *(code **)(param_5 + 0x1c) = FUN_00228c44;
  if (param_2 == 0) {
    if (param_8 == 0) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    flix();
  }
  else {
    if ((*(uint *)(param_2 + 0x34) & 2) == 0) {
      return 0xffff0010;
    }
    flix();
    if (in_a14 == 0) {
      cust0();
      if (unaff_a10 + 0xb != unaff_a11) {
        return 0xffff0011;
      }
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  cust1();
  cust0();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002276f0 @ 002276f0 (24 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_002276f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int unaff_retaddr;
  
  if (param_1 != 0) {
    flix();
    *(undefined4 *)(unaff_retaddr + 0x20) = param_4;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0014;
}


// ===== FUN_00227770 @ 00227770 (43 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00227770(void)

{
  undefined1 in_EXCSAVE1;
  
  if (DAT_00237a80 != '\x01') {
    FUN_00227f3c();
    wsr(in_EXCSAVE1,&DAT_00228904);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_002277e4 @ 002277e4 (11 bytes)

undefined1 FUN_002277e4(void)

{
  return DAT_00237a80;
}


// ===== xos_start @ 002277f0 (45 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* last call of main, arg 0 [inference] */

void xos_start(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = rsr(0);
  if ((uVar2 & 0x20) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar1 = FUN_002278a4();
  if (iVar1 == 1) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_00227770();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002278a4 @ 002278a4 (11 bytes)

undefined1 FUN_002278a4(void)

{
  return DAT_00237a81;
}


// ===== FUN_002278b0 @ 002278b0 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002278b0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002278f8 @ 002278f8 (34 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002278f8(void)

{
  flix();
  rsr(0);
  flix();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022795c @ 0022795c (53 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022795c(void)

{
  uint uVar1;
  
  uVar1 = rsr(0);
  if (((uVar1 & 0x20) == 0) && (*(char *)(DAT_00237858 + 0x30) == '\0')) {
    flix();
    rur(0x5e);
    flix();
    return;
  }
  rsr(0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00227a24 @ 00227a24 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00227a24(void)

{
  rsr(0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00227af0 @ 00227af0 (35 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00227af0(int param_1,int param_2)

{
  int in_a12;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) && (-1 < param_2)) &&
     (param_2 < 0x10)) {
    rsr(0);
    flix();
    *(undefined4 *)(in_a12 + 4) = 0x54485244;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00227be4 @ 00227be4 (102 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00227be4(void)

{
  int extraout_a3;
  uint uVar1;
  uint in_a12;
  int in_a13;
  undefined4 in_t0;
  undefined1 uVar2;
  undefined8 uVar3;
  
  uVar2 = 0;
  uVar3 = FUN_00227f3c();
  uVar1 = (uint)((ulonglong)uVar3 >> 0x20);
  flix();
  FUN_0020b9a0();
  rsr(uVar2);
  flix();
  cust1();
  *(undefined4 *)uVar3 = in_t0;
  if (in_a13 == 0x80) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (extraout_a3 < 1) {
    uVar1 = rsr(uVar2);
    flix();
    if ((int)in_a12 < 0) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar1 = uVar1 | in_a12;
  }
  wsr(uVar2,uVar1);
  rsync();
  if ((undefined4 *)uVar3 == (undefined4 *)0x0) {
    return;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00227c38 @ 00227c38 (36 bytes)

undefined4 FUN_00227c38(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    flix();
    return 0xffff0015;
  }
  return 0xffff0001;
}


// ===== FUN_00227c64 @ 00227c64 (63 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00227c64(undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int in_a14;
  
  uVar2 = rsr(0);
  if ((uVar2 & 0x20) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puVar1 = (undefined4 *)(DAT_00237858 + 0x44);
  *(undefined1 *)(DAT_00237858 + 0x31) = 1;
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)(param_1);
  }
  flix();
  if (in_a14 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_0022795c();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00227cbc @ 00227cbc (42 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00227cbc(int param_1)

{
  uint uVar1;
  
  uVar1 = rsr(0);
  if ((uVar1 & 0x20) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    rsr(0);
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00227d3c @ 00227d3c (40 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00227d3c(int param_1)

{
  int in_a12;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    if (*(char *)(param_1 + 0x30) == '\0') {
      return 0xffff001d;
    }
    rsr(0);
    flix();
    *(undefined4 *)(in_a12 + 4) = 0x54485244;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00227de0 @ 00227de0 (35 bytes)

undefined4 FUN_00227de0(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    flix();
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_00227e10 @ 00227e10 (44 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00227e10(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    if (DAT_00237858 == param_1) {
      return 0xffff0014;
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffff0001;
}


// ===== FUN_00227ef4 @ 00227ef4 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00227ef4(int param_1)

{
  undefined4 *in_a7;
  undefined4 in_a14;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    flix();
    *in_a7 = in_a14;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_00227f3c @ 00227f3c (25 bytes)

undefined8 FUN_00227f3c(void)

{
  undefined4 uVar1;
  
  uVar1 = rsil(2);
  DAT_002cb5b8 = DAT_002cb5b8 + 1;
  wsr(0,uVar1);
  return CONCAT44(uVar1,DAT_002cb5b8);
}


// ===== FUN_00227f58 @ 00227f58 (47 bytes)

int FUN_00227f58(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_a8;
  undefined1 uVar3;
  
  uVar3 = 0;
  uVar1 = rsil(2);
  flix();
  DAT_002cb5b8 = unaff_a8;
  if (unaff_a8 == 0) {
    uVar3 = 0;
    iVar2 = FUN_002278a4();
    if (iVar2 == 1) {
      FUN_002278b0(DAT_00237858);
    }
  }
  wsr(uVar3,uVar1);
  return DAT_002cb5b8;
}


// ===== FUN_00227f88 @ 00227f88 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00227f88(int param_1)

{
  if (param_1 != -1) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_00227ff0 @ 00227ff0 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00227ff0(void)

{
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00228054 @ 00228054 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228054(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002280c4 @ 002280c4 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002280c4(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00228120 @ 00228120 (53 bytes)

int FUN_00228120(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  if (DAT_002cb5b8 == 0) {
    uVar1 = rsr(0);
    if ((uVar1 & 0x20) == 0) {
      flix();
    }
    else {
      param_1 = (**(code **)(param_1 + 0x1c))(param_2);
    }
    DAT_002cb5b4 = DAT_002cb5b4 + 1;
  }
  else {
    param_1 = 0;
  }
  return param_1;
}


// ===== FUN_00228158 @ 00228158 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228158(void)

{
  uint in_a7;
  uint in_a13;
  
  flix();
  if ((in_a7 & in_a13) != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00228299 @ 00228299 (32 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00228299(void)

{
  int in_a14;
  
  flix();
  acquire(in_a14 + 0x88);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== xos_start_system_timer @ 0022835c (25 bytes)

/* WARNING: Control flow encountered bad instruction data */

void xos_start_system_timer(void)

{
  uint uVar1;
  
  uVar1 = rsr(0);
  if ((uVar1 & 0x20) == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_00227770();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

