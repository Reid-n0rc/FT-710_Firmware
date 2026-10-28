// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0021ac08 @ 0021ac08 (11 bytes)

void FUN_0021ac08(void)

{
  FUN_0021adac();
  FUN_0021adb4();
  return;
}


// ===== env_isr @ 0021ac14 (22 bytes)

/* isr_table[vector] -> virtqueue_notification */

void env_isr(uint param_1)

{
  if (param_1 < 0xc) {
    FUN_0021bd24(*(undefined4 *)(&DAT_002390a0 + param_1 * 4));
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== MU_B_IRQHandler @ 0021ac30 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* rpmsg platform ISR: if MU-B SR RF1 (bit 26): env_isr(RR1 >> 16) */

void MU_B_IRQHandler(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  memw();
  uVar2 = DAT_40111060;
  if ((uVar2 & 0x4000000) == 0) {
    return;
  }
  memw();
  uVar1 = DAT_40111044;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== platform_init_interrupt @ 0021ac58 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* env_register_isr, first use: MU-B CR |= RIE1, xos_register_interrupt_handler(MU_B_IRQHandler) */

void platform_init_interrupt(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== platform_deinit_interrupt @ 0021acb4 (12 bytes)

/* last use: MU-B CR &= ~RIE1, unregister handler */

void platform_deinit_interrupt(void)

{
                    /* WARNING: Subroutine does not return */
  env_lock_mutex(DAT_002390d0);
}


// ===== platform_notify @ 0021ad04 (19 bytes)

/* wait MU-B SR TE1 (bit 22), TR1 = vector << 16 */

void platform_notify(uint param_1)

{
  if (param_1 >> 1 != 1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  env_lock_mutex(DAT_002390d0);
}


// ===== platform_time_delay @ 0021ad44 (32 bytes)

/* busy-wait on CCOUNT (0x1F40 cycles per unit) */

void platform_time_delay(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 in_CCOUNT;
  
  iVar1 = rsr(in_CCOUNT);
  param_1 = param_1 * (int)&DAT_00001f40;
  do {
    iVar2 = rsr(in_CCOUNT);
    param_1 = param_1 + (iVar1 - iVar2);
  } while (param_1 != 0);
  return;
}


// ===== FUN_0021ad64 @ 0021ad64 (7 bytes)

undefined4 FUN_0021ad64(void)

{
  return 0;
}


// ===== FUN_0021ad6c @ 0021ad6c (27 bytes)

void FUN_0021ad6c(void)

{
  if (0 < DAT_002390d8) {
    xos_interrupt_enable(6);
    DAT_002390d8 = DAT_002390d8 + -1;
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0021ad88 @ 0021ad88 (27 bytes)

void FUN_0021ad88(void)

{
  if (-1 < DAT_002390d8) {
    FUN_002267e0(6);
    DAT_002390d8 = DAT_002390d8 + 1;
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0021ada4 @ 0021ada4 (5 bytes)

void FUN_0021ada4(void)

{
  return;
}


// ===== FUN_0021adac @ 0021adac (5 bytes)

void FUN_0021adac(void)

{
  return;
}


// ===== FUN_0021adb4 @ 0021adb4 (5 bytes)

void FUN_0021adb4(void)

{
  return;
}


// ===== FUN_0021adbc @ 0021adbc (5 bytes)

void FUN_0021adbc(void)

{
  return;
}


// ===== FUN_0021adc4 @ 0021adc4 (5 bytes)

void FUN_0021adc4(void)

{
  return;
}


// ===== FUN_0021adcc @ 0021adcc (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021adcc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021ade4 @ 0021ade4 (18 bytes)

void FUN_0021ade4(void)

{
  FUN_0021ab8c(DAT_002390d0);
  DAT_002390d0 = 0;
  return;
}


// ===== FUN_0021ae00 @ 0021ae00 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021ae00(int param_1)

{
  if (*(int *)(param_1 + 100) != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0021aed4 @ 0021aed4 (15 bytes)

void FUN_0021aed4(void)

{
  flix();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0021aee8 @ 0021aee8 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021aee8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021af00 @ 0021af00 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021af00(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021af14 @ 0021af14 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021af14(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021af28 @ 0021af28 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021af28(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021af40 @ 0021af40 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021af40(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021af54 @ 0021af54 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021af54(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021af68 @ 0021af68 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021af68(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021af7c @ 0021af7c (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021af7c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021af90 @ 0021af90 (11 bytes)

void FUN_0021af90(int param_1)

{
  platform_notify(*(undefined2 *)(param_1 + 0x50));
  return;
}


// ===== rpmsg_lite_create_ept @ 0021af9c (14 bytes)

/* called by Thread_Ipc (callback ipc_ept_rx_cb) and rpmsg_ns_bind */

undefined4 rpmsg_lite_create_ept(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
}


// ===== FUN_0021b034 @ 0021b034 (17 bytes)

undefined4 FUN_0021b034(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
                    /* WARNING: Subroutine does not return */
    env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
  }
  return 0xffffec75;
}


// ===== rpmsg_lite_is_link_up @ 0021b078 (13 bytes)

/* returns rl->link_state (+0x10) */

undefined4 rpmsg_lite_is_link_up(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x10);
  }
  return 0;
}


// ===== rpmsg_lite_send @ 0021b088 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* called by handle_srtm_msg and rpmsg_ns_announce */

void rpmsg_lite_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021b190 @ 0021b190 (27 bytes)

void FUN_0021b190(int param_1)

{
  flix();
  if (*(int *)(param_1 + 0x10) != 1) {
    flix();
    return;
  }
                    /* WARNING: Subroutine does not return */
  env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
}


// ===== FUN_0021b238 @ 0021b238 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0021b238(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffffec75;
}


// ===== FUN_0021b2f8 @ 0021b2f8 (18 bytes)

undefined4 FUN_0021b2f8(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
                    /* WARNING: Subroutine does not return */
    env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
  }
  return 0xffffec75;
}


// ===== FUN_0021b34c @ 0021b34c (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021b34c(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== rpmsg_lite_remote_init @ 0021b544 (24 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* called by Thread_Ipc; init_interrupt x2, disable/enable x2 [inference] */

undefined4 rpmsg_lite_remote_init(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  if (((param_2 < 2) && (param_1 != 0)) && (param_4 != 0)) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_0021b664 @ 0021b664 (28 bytes)

/* WARNING: Instruction at (ram,0x0021b67b) overlaps instruction at (ram,0x0021b67a)
    */

undefined1 * FUN_0021b664(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int in_a12;
  undefined1 auStack_1d [29];
  
  if (param_1 == 0) {
    puVar1 = (undefined1 *)0xffffec75;
  }
  else {
    flix();
    *(undefined4 *)(in_a12 + 0x30) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_a12 + 0x20) = param_4;
    puVar1 = auStack_1d;
  }
  return puVar1;
}


// ===== FUN_0021b6d0 @ 0021b6d0 (23 bytes)

void FUN_0021b6d0(void)

{
  int in_a5;
  
  if (in_a5 != 0) {
    flix();
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== rpmsg_ns_bind @ 0021b734 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* creates an endpoint (no callers found) [inference] */

undefined4 rpmsg_ns_bind(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  if ((param_2 != 0) && (param_4 != 0)) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_0021b768 @ 0021b768 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0021b768(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== rpmsg_ns_announce @ 0021b778 (20 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* sends via rpmsg_lite_send, error 0xFFFFEC75 (no callers found) [inference] */

undefined4 rpmsg_ns_announce(undefined4 param_1,int param_2,int param_3)

{
  if ((param_3 != 0) && (param_2 != 0)) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xffffec75;
}


// ===== FUN_0021b7c0 @ 0021b7c0 (47 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0021b7d1) */

undefined4 FUN_0021b7c0(void)

{
  int iVar1;
  
  memw();
  memw();
  iVar1 = FUN_0021aae4(0x68);
  if (iVar1 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0xfffff444;
}


// ===== FUN_0021b854 @ 0021b854 (59 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0021b865) */

void FUN_0021b854(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int unaff_retaddr;
  undefined4 uVar1;
  undefined4 *in_a12;
  int in_a14;
  
  memw();
  memw();
  flix();
  uVar1 = *in_a12;
  *(int *)(unaff_retaddr + 0x38) = param_5 + -1;
  FUN_0021aafc(in_a14 << 2);
  flix();
  *(undefined4 *)(*(int *)(param_2 + unaff_retaddr + 4) + 0x34) = uVar1;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021b8e8 @ 0021b8e8 (33 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0021b8f9) */

void FUN_0021b8e8(void)

{
  memw();
  memw();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021b938 @ 0021b938 (38 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0021b949) */

void FUN_0021b938(void)

{
  memw();
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021b9b4 @ 0021b9b4 (24 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_0021b9b4(int param_1)

{
  if (param_1 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return 0;
}


// ===== FUN_0021ba14 @ 0021ba14 (15 bytes)

undefined4 FUN_0021ba14(void)

{
  int unaff_a8;
  
  flix();
  return *(undefined4 *)(unaff_a8 + 0x88);
}


// ===== FUN_0021ba24 @ 0021ba24 (24 bytes)

void FUN_0021ba24(int param_1)

{
  undefined4 unaff_a9;
  
  if (param_1 != 0) {
    flix();
    *(undefined4 *)(param_1 + 0x28) = unaff_a9;
    *(undefined4 *)(param_1 + 0x2c) = unaff_a9;
    FUN_0021aaf0(param_1);
  }
  return;
}


// ===== FUN_0021ba3c @ 0021ba3c (21 bytes)

void FUN_0021ba3c(int param_1)

{
  undefined4 unaff_a8;
  
  if (param_1 != 0) {
    flix();
    *(undefined4 *)(param_1 + 0x28) = unaff_a8;
    *(undefined4 *)(param_1 + 0x2c) = unaff_a8;
    return;
  }
  return;
}

