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


// ===== ipc_handle_msg @ 0021bd40 (9 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* checks version byte, dispatch on category (+8): 0 general, 1 audio, else error at +0x14; if type
   (+0xB) == request, reply with rpmsg_lite_send under mutex */

void ipc_handle_msg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== handle_msg_general @ 0021bdcc (25 bytes)

/* category 0: command (+0xC); system info fills param[] with 9 component versions (0x00020000,
   0x00010003, ...) */

undefined1 handle_msg_general(undefined4 param_1,int param_2)

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


// ===== handle_msg_audio @ 0021be54 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* category 1 (M33 prints it as Mute on/off): command (+0xC), result in +0x14/+0x18 */

void handle_msg_audio(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== regfile_set_defaults @ 0021be80 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* writes the default of every DSP register (all but 0, 1, 0x4000) */

void regfile_set_defaults(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== tx_gpio_to_reg4004 @ 0021c060 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* reg 0x4004 = (f()<<2) | (GPIO P0_21<<1) | GPIO P0_22; called from Thread_Main loop 0x0021C360 */

void tx_gpio_to_reg4004(void)

{
  undefined1 uVar1;
  
  regfile_gpio_sel();
  memw();
  uVar1 = DAT_40100015;
  memw();
  uVar1 = DAT_40100016;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== regfile_capture_init @ 0021c090 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* capture block table 0x2390E0 = {0x2007E000, 0x2007F000} (regs 0x7000/0x7800), memset 4 KB each */

void regfile_capture_init(void)

{
  DAT_002390e0 = &DAT_2007e000;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== regfile_capture_clear @ 0021c0b8 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* memset(block[idx], 0, 0x1000) */

void regfile_capture_clear(uint param_1)

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


// ===== regfile_capture_set_ctrl @ 0021c0d4 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* *(u16 *)block[idx] = v (control word); no caller */

void regfile_capture_set_ctrl(uint param_1)

{
  if (1 < param_1) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== regfile_capture_append @ 0021c0e8 (16 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* append u32 if ctrl bit 0, count at +2 (max 0x3FE), wrap if ctrl bit 1; no caller */

void regfile_capture_append(uint param_1)

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


// ===== cpu_load_to_regs_2000 @ 0021c230 (30 bytes)

/* WARNING: Control flow encountered bad instruction data */

void cpu_load_to_regs_2000(void)

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


// ===== Thread_Main_entry @ 0021c360 (26 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* XOS thread "Thread_Main" (entry from literal 0x206CD0) */

void Thread_Main_entry(void)

{
  audio_i2s_fc3_fc4_fc5_init();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== ipc_ept_rx_cb @ 0021c398 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* rpmsg ept callback: if len == 0x98 xos_msgq_put(msg); return RL_RELEASE (NXP my_ept_read_cb) */

undefined4 ipc_ept_rx_cb(undefined4 param_1,int param_2)

{
  if (param_2 != 0x98) {
    return 0;
  }
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== Thread_Ipc_entry @ 0021c3b4 (58 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* XOS thread "Thread_Ipc": MU_Init(MUB), msgq, rpmsg_lite_remote_init(0x20020000), wait link up,
   ept 0x1E, MU flag/SEMA42 boot handshake, then loop xos_msgq_get -> handle_srtm_msg */

void Thread_Ipc_entry(void)

{
  int unaff_retaddr;
  undefined4 *puVar1;
  uint in_a6;
  uint in_a14;
  uint in_a15;
  int in_t0;
  
  MU_Init(&DAT_40111000);
  flix();
  puVar1 = (undefined4 *)(in_a14 >> 5 & 0x1fff);
  unaff_retaddr = (int)puVar1 + unaff_retaddr;
  if (in_t0 < 1) {
    while (unaff_retaddr == 0) {
      unaff_retaddr = rpmsg_lite_is_link_up(*puVar1);
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


// ===== xos_create_main_ipc_threads @ 0021c498 (12 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* XOS main: zero DMA area 0x20060000..0x200631E0, regfile_init_defaults, clock globals (24 MHz,
   18.432 MHz), creates Thread_Main, Thread_Ipc, others, xos_start */

void xos_create_main_ipc_threads(void)

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


// ===== regfile_gpio_sel @ 0021c5cc (42 bytes)

/* (reg 0xC & 0xF000) == 0x1000 -> GPIO P0_4 byte */

undefined1 regfile_gpio_sel(void)

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

