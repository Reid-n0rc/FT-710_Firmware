// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_00224ed8 @ 00224ed8 (46 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00224ee9) */

void FUN_00224ed8(void)

{
  undefined4 unaff_retaddr;
  int unaff_a11;
  int in_a14;
  int in_t0;
  undefined1 auStack_30 [48];
  
  flix();
  flix();
  *(int *)(in_a14 + 0x20) = in_a14;
  if (unaff_a11 == -1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x00275c60();
  *(undefined1 **)(in_t0 + 0x3c) = auStack_30;
  flix();
  *(undefined4 *)(in_t0 + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225250 @ 00225250 (19 bytes)

void FUN_00225250(undefined4 param_1,undefined4 *param_2)

{
  flix();
  *param_2 = param_1;
  param_2[1] = param_1;
  param_2[2] = param_1;
  param_2[3] = param_1;
  return;
}


// ===== FUN_00225264 @ 00225264 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void FUN_00225264(void)

{
  int in_a14;
  
  flix();
  if (in_a14 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225340 @ 00225340 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225340(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225370 @ 00225370 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225370(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002253a8 @ 002253a8 (5 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002253a8(void)

{
  int in_a12;
  
  func_0x00213958(*(undefined4 *)(in_a12 + 4));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002253f0 @ 002253f0 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002253f0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225408 @ 00225408 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225408(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225478 @ 00225478 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225478(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0022548c @ 0022548c (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022548c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002254a0 @ 002254a0 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002254a0(void)

{
  FUN_002254ec();
  FUN_00225550();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002254ec @ 002254ec (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002254ec(void)

{
  int unaff_retaddr;
  undefined4 in_a6;
  
  rsr(0);
  flix();
  *(undefined4 *)(unaff_retaddr + 4) = in_a6;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225550 @ 00225550 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225550(void)

{
  int unaff_retaddr;
  undefined4 in_a6;
  
  rsr(0);
  flix();
  *(undefined4 *)(unaff_retaddr + 4) = in_a6;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002255b4 @ 002255b4 (39 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002255b4(undefined4 param_1,undefined4 param_2)

{
  int extraout_a5;
  
  flix();
  func_0x002927cc();
  *(undefined4 *)(extraout_a5 + 0x28) = param_2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225790 @ 00225790 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225790(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225834 @ 00225834 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225834(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002259e4 @ 002259e4 (134 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002259e4(void)

{
  uint uVar1;
  undefined4 extraout_a3;
  undefined4 in_a6;
  undefined4 in_a7;
  undefined4 *puVar2;
  int iVar3;
  int in_a12;
  uint uVar4;
  uint in_a14;
  short in_a15;
  bool in_b0;
  undefined1 uVar5;
  
  if (DAT_002c6a20 == 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar3 = rsr(0);
  flix();
  uVar1 = in_a14 >> 0xe & 0x7fff;
  if (in_b0) {
    func_0x001cf00c();
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
  uVar4 = *(uint *)(in_a14 + 0x38);
  *(undefined4 *)(iVar3 + 0x38) = DAT_001e9038;
  uVar5 = 0;
  memcpy();
  flix();
  xos_interrupt_enable(in_a6,in_a7,0xf9e);
  puVar2 = *(undefined4 **)(in_a12 + 0x30);
  *(short *)(uVar1 + 0xf8) = (short)in_a12;
  *(short *)(uVar1 + 0xfa) = in_a15 + 1;
  uVar1 = rsr(uVar5);
  wsr(uVar5,uVar4 | uVar1 & 0xfffffff0);
  rsync();
  flix();
  *puVar2 = extraout_a3;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225a84 @ 00225a84 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225a84(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225ab4 @ 00225ab4 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225ab4(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225af0 @ 00225af0 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225af0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225b30 @ 00225b30 (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225b30(void)

{
  rsr(0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225b8c @ 00225b8c (14 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225b8c(void)

{
  rsr(0);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225be8 @ 00225be8 (44 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00225be8(void)

{
  uint unaff_a10;
  uint in_a12;
  
  flix();
  rsr(0);
  flix();
  cust0();
  _DAT_ffffffec = (unaff_a10 >> 0x10 & 0xfff) + 0x163ab80;
  wsr(0,_DAT_ffffffec | in_a12);
  rsync();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== txaf_fifo_pop_to_dma @ 00225c9c (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

void txaf_fifo_pop_to_dma(void)

{
  if (DAT_002c7644 != '\0') {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== rxif_dma_to_fifo @ 00225cf8 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void rxif_dma_to_fifo(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225d48 @ 00225d48 (33 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225d48(void)

{
  if (DAT_002c7708 != '\0') {
    rsr(0);
    flix();
    rur(0xee);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00225dc4 @ 00225dc4 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00225dc4(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== create_rx_tx_path_threads @ 00225e40 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

void create_rx_tx_path_threads(void)

{
  flix();
  if (&stack0x00000000 == &DAT_00000030) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_00213910(&DAT_40026000);
  CLOCK_AttachClk(0x80001740);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== audio_i2s_fc3_fc4_fc5_init @ 002260d8 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

void audio_i2s_fc3_fc4_fc5_init(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== fc2_txaf_dma_done @ 00226224 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void fc2_txaf_dma_done(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== fc3_rxif_dma_done @ 00226254 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void fc3_rxif_dma_done(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== fc5_codec_out_dma_done @ 00226284 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void fc5_codec_out_dma_done(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== fc4_codec_in_dma_done @ 002262c0 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void fc4_codec_in_dma_done(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== Thread_Rx_Path_entry @ 002262fc (46 bytes)

/* WARNING: Control flow encountered bad instruction data */

void Thread_Rx_Path_entry(void)

{
  undefined4 extraout_a3;
  undefined4 in_a5;
  
  flix();
  func_0x001efb94(&PTR_DAT_0023773c,&DAT_002cab90,&DAT_2006ff00,in_a5,&DAT_002cac50);
  flix();
  func_0x0027c39c();
  FUN_00225d48(extraout_a3);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== Thread_Tx_Path_entry @ 0022647c (24 bytes)

void Thread_Tx_Path_entry(void)

{
  undefined4 in_a5;
  undefined4 in_a6;
  
  flix();
  FUN_00226579(&PTR_DAT_0023773c,&DAT_002cae30,&DAT_2006ff00,in_a5,in_a6,&DAT_002cb010);
  return;
}


// ===== FUN_002264a9 @ 002264a9 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002264a9(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00226562 @ 00226562 (3 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00226562(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00226579 @ 00226579 (28 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00226579(void)

{
  int unaff_retaddr;
  int in_a6;
  bool in_b0;
  
  flix();
  if (in_b0) {
    FUN_002249d0();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_002264a9(in_a6 + unaff_retaddr);
  return;
}


// ===== FUN_002266b6 @ 002266b6 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002266b6(void)

{
  FUN_00223734();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== xos_register_interrupt_handler @ 002266fc (29 bytes)

/* called with MU_B_IRQHandler [inference] */

undefined ** xos_register_interrupt_handler(uint param_1,undefined *param_2)

{
  if (0x1f < param_1) {
    return (undefined **)0xffff0001;
  }
  (&PTR_FUN_00237860)[param_1 * 4] = param_2;
  flix();
  return &PTR_FUN_00237860 + param_1 * 4;
}


// ===== FUN_0022671c @ 0022671c (26 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0022671c(void)

{
  flix();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00226744 @ 00226744 (31 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00226744(int param_1,int param_2)

{
  uint unaff_retaddr;
  undefined4 uVar1;
  uint in_a7;
  uint in_a14;
  
  if (1 < param_1 - 3U) {
    return 0xffff0001;
  }
  uVar1 = rsr(0);
  flix();
  *(undefined4 *)(unaff_retaddr + 4) = uVar1;
  if ((unaff_retaddr & in_a7) != 0) {
    func_0x001ace6c();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_2 == 0) {
    spi_fifo_push();
    uVar1 = FUN_00226562(param_1,0,in_a14 >> 0x1e);
    return uVar1;
  }
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== xos_interrupt_enable @ 0022678c (57 bytes)

void xos_interrupt_enable(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_a9;
  int in_SAR;
  undefined1 in_INTENABLE;
  undefined1 uVar3;
  
  uVar2 = rsil(0xf);
  flix();
  DAT_00237854 = DAT_00237854 | unaff_a9 << 0x20 - in_SAR;
  uVar3 = 0;
  iVar1 = FUN_002278a4();
  if (iVar1 == 1) {
    flix();
    wsr(in_INTENABLE,1);
  }
  wsr(uVar3,uVar2);
  rsync();
  return;
}


// ===== FUN_002267c8 @ 002267c8 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002267c8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002267e0 @ 002267e0 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002267e0(void)

{
  undefined4 unaff_retaddr;
  int in_a6;
  
  rsil(0xf);
  flix();
  *(undefined4 *)(in_a6 + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00226800 @ 00226800 (29 bytes)

void FUN_00226800(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 in_INTENABLE;
  undefined1 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_002278a4();
  if (iVar1 == 1) {
    flix();
    wsr(in_INTENABLE,1);
  }
  wsr(uVar2,param_2);
  rsync();
  return;
}


// ===== FUN_00226820 @ 00226820 (27 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00226820(uint param_1)

{
  if (0x1f < param_1) {
    return 0;
  }
  flix();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00226844 @ 00226844 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00226844(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00226854 @ 00226854 (24 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00226854(void)

{
  if (DAT_002cb0d8 != 0) {
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_00227f3c();
  breakpoint(0x1000,0x22686a,1,0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_00226870 @ 00226870 (37 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00226870(void)

{
  uint uVar1;
  
  uVar1 = rsr(0);
  if ((((uVar1 & 0x20) != 0) && (DAT_00237858 != (undefined *)0x0)) &&
     (DAT_00237858 != &DAT_002cb0f0)) {
    FUN_00227c64(0xffff001b);
    return;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

