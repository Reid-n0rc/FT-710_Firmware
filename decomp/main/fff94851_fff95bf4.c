// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== r_sci5_transmit_interrupt @ fff94851 (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94887) */
/* WARNING: Removing unreachable block (ram,0xfff94851) */
/* WARNING: Removing unreachable block (ram,0xfff94899) */

void r_sci5_transmit_interrupt(void)

{
  byte bVar1;
  
  if (DAT_0001b622 == 0) {
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0x7f;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 | 4;
    return;
  }
  DAT_0008a0a3 = *DAT_0002081c;
  DAT_0002081c = DAT_0002081c + 1;
  DAT_0001b622 = DAT_0001b622 + -1;
  return;
}


// ===== r_sci5_transmitend_interrupt @ fff9489d (37 bytes)

/* TEI5 (cb 0x1E) */

void r_sci5_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c06c;
  DAT_0008c06c = bVar1 & 0xf7;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0x7f;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xdf;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xfb;
  r_sci5_callback_transmitend();
  return;
}


// ===== r_sci5_receive_interrupt @ fff948c2 (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94928) */
/* WARNING: Removing unreachable block (ram,0xfff94930) */
/* WARNING: Removing unreachable block (ram,0xfff9492e) */
/* WARNING: Removing unreachable block (ram,0xfff948c2) */
/* WARNING: Removing unreachable block (ram,0xfff948c4) */
/* WARNING: Removing unreachable block (ram,0xfff9492a) */

void r_sci5_receive_interrupt(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b624 < DAT_0001b626) {
    uVar2 = DAT_0008a0a5;
    *DAT_00020820 = uVar2;
    sci5_rx_byte_hook();
    DAT_00020820 = DAT_00020820 + 1;
    DAT_0001b624 = DAT_0001b624 + 1;
  }
  if (DAT_0001b626 <= DAT_0001b624) {
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0xbf;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0xef;
    r_sci5_callback_receiveend();
    return;
  }
  return;
}


// ===== r_sci5_receiveerror_interrupt @ fff94934 (39 bytes)

/* ERI5 (cb 0x1F) */

void r_sci5_receiveerror_interrupt(void)

{
  byte bVar1;
  
  r_sci5_callback_receiveerror();
  bVar1 = DAT_0008a0a4;
  DAT_0008a0a4 = bVar1 & 199 | 0xc0;
  return;
}


// ===== r_sci5_callback_transmitend @ fff9495b (1 bytes)

/* empty */

void r_sci5_callback_transmitend(void)

{
  return;
}


// ===== r_sci5_callback_receiveend @ fff9495c (5 bytes)

/* SCI5 receive-end callback: calls sdr_rx_done_cb (0xA2B3=1) */

void r_sci5_callback_receiveend(void)

{
  sdr_rx_done_cb();
  return;
}


// ===== r_sci5_callback_receiveerror @ fff94961 (1 bytes)

/* empty */

void r_sci5_callback_receiveerror(void)

{
  return;
}


// ===== sci5_rx_byte_hook @ fff94962 (82 bytes)

/* 06/'?' = 1 byte, 'r' = 7 bytes */

void sci5_rx_byte_hook(void)

{
  char cVar1;
  
  if (DAT_0001b624 != 0) {
    return;
  }
  cVar1 = *DAT_00020820;
  if ((cVar1 != '\x06') && (cVar1 != '?')) {
    if (cVar1 == 'r') {
      DAT_0001b626 = 7;
      return;
    }
    DAT_00020820 = DAT_00020820 + -1;
    DAT_0001b624 = 0xffff;
    return;
  }
  DAT_0001b626 = 1;
  return;
}


// ===== R_TPU0_Create @ fff949b4 (132 bytes)

/* TPU0 PCLKB/16, TGRA=374: 10 kHz (0.1 ms) tick, vec130 */

void R_TPU0_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xfe;
  DAT_00087782 = 0xf;
  bVar2 = DAT_00087382;
  DAT_00087382 = bVar2 & 0xf4 | 4;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xfe;
  DAT_00088110 = 0x2a;
  bVar2 = DAT_00088114;
  DAT_00088114 = bVar2 | 0x41;
  DAT_00088112 = 0;
  DAT_00088113 = 0;
  DAT_00088118 = 0x176;
  DAT_0008811a = 0x176;
  DAT_0008811c = 0x176;
  DAT_0008811e = 0x176;
  FUN_fff94a56();
  return;
}


// ===== R_TPU0_Start @ fff94a38 (15 bytes)

/* Enable vector 130 and TSTR bit 0 */

void R_TPU0_Start(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087210;
  DAT_00087210 = bVar1 | 4;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 1;
  return;
}


// ===== FUN_fff94a47 @ fff94a47 (15 bytes)

void FUN_fff94a47(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087210;
  DAT_00087210 = bVar1 & 0xfb;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 & 0xfe;
  return;
}


// ===== FUN_fff94a56 @ fff94a56 (1 bytes)

void FUN_fff94a56(void)

{
  return;
}


// ===== r_tpu0_tgia_isr @ fff94a57 (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94a5f) */
/* WARNING: Removing unreachable block (ram,0xfff94a57) */
/* WARNING: Removing unreachable block (ram,0xfff94a59) */
/* WARNING: Removing unreachable block (ram,0xfff94a61) */
/* vec130 -> swtimer_tick */

void r_tpu0_tgia_isr(void)

{
  swtimer_tick();
  return;
}


// ===== R_TPU1_Create @ fff94a65 (104 bytes)

/* TPU1 PCLKB/1, TGRA set by tone_set: tone sample clock, vec144 */

void R_TPU1_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xfd;
  DAT_00087790 = 0x14;
  bVar2 = DAT_00087390;
  DAT_00087390 = bVar2 & 0xfe | 0xe;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xfd;
  DAT_00088120 = 0x20;
  bVar2 = DAT_00088124;
  DAT_00088124 = bVar2 | 0x41;
  DAT_00088122 = 0;
  DAT_00088128 = 0x270;
  DAT_0008812a = 5999;
  FUN_fff94aeb();
  return;
}


// ===== R_TPU1_Start @ fff94acd (15 bytes)

/* TSTR bit 1 */

void R_TPU1_Start(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087212;
  DAT_00087212 = bVar1 | 1;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 2;
  return;
}


// ===== R_TPU1_Stop @ fff94adc (15 bytes)

/* Stop TPU1 */

void R_TPU1_Stop(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087212;
  DAT_00087212 = bVar1 & 0xfe;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 & 0xfd;
  return;
}


// ===== FUN_fff94aeb @ fff94aeb (1 bytes)

void FUN_fff94aeb(void)

{
  return;
}


// ===== r_tpu1_tgia_isr @ fff94aec (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94af4) */
/* WARNING: Removing unreachable block (ram,0xfff94aec) */
/* WARNING: Removing unreachable block (ram,0xfff94aee) */
/* WARNING: Removing unreachable block (ram,0xfff94af6) */
/* vec144 -> tone_sample_isr */

void r_tpu1_tgia_isr(void)

{
  tone_sample_isr();
  return;
}


// ===== app_main @ fff94afa (145 bytes)

/* Init sequence, waits for power-on (flag 0x20B3A) while still serving cat_parse (so PS works when
   off), then subsystem init and main_loop */

void app_main(void)

{
  wdt_kick();
  timers_init();
  FUN_fffb27df();
  eeprom_init();
  eeprom_load_all();
  key_task_init();
  sci_start_all();
  qmb_boot_init();
  while (DAT_00020b3a == '\0') {
    displink_task();
    cat_parse();
    wdt_kick();
  }
  if (DAT_00020b45 == '\x01') {
    DAT_00020b45 = '\0';
    eeprom_save_all();
    DAT_00020f10 = 1;
    wdt_kick();
  }
  shreg_bus_init();
  trx_init();
  sdr_init();
  dsp_link_init();
  portctl_init();
  dac_init_idle();
  keyer_init();
  tuner_init();
  menu_subsys_init();
  cat_apo_reset();
  main_loop();
  return;
}


// ===== main_loop @ fff94b8b (66 bytes)

/* Super-loop (no RTOS): polls ~16 tasks incl. cat_parse each pass */

void main_loop(void)

{
  do {
    wdt_kick();
    io_task();
    sdr_task();
    dsp_link_poll();
    rf_ctrl_task();
    beep_task();
    cat_parse();
    ladder_key_task();
    scan_task();
    dispreq_e8_task();
    dispreq_e7_task();
    keyer_task();
    sd_menu_task();
    displink_task();
    key_task();
    tuner_task();
  } while( true );
}


// ===== ver_main @ fff94bcd (12 bytes)

/* Returns pointer to MAIN version string 0xFFFFFF00 (VE0) */

uint ver_main(void)

{
  return 0xffffff00;
}


// ===== FUN_fff94bd9 @ fff94bd9 (12 bytes)

undefined4 FUN_fff94bd9(void)

{
  return 0xffffff10;
}


// ===== FUN_fff94be5 @ fff94be5 (12 bytes)

undefined4 FUN_fff94be5(void)

{
  return 0xffffff20;
}


// ===== ver_display @ fff94bf1 (12 bytes)

/* Returns pointer to DISPLAY version 0x1436 (VE1) */

uint ver_display(void)

{
  return 0x1436;
}


// ===== FUN_fff94bfd @ fff94bfd (18 bytes)

void FUN_fff94bfd(undefined4 *param_1)

{
  DAT_0000143a = *(undefined2 *)(param_1 + 1);
  DAT_00001436 = *param_1;
  return;
}


// ===== FUN_fff94c0f @ fff94c0f (12 bytes)

void FUN_fff94c0f(void)

{
  return;
}


// ===== FUN_fff94c1b @ fff94c1b (18 bytes)

void FUN_fff94c1b(undefined4 *param_1)

{
  DAT_00001440 = param_1[1];
  DAT_0000143c = *param_1;
  return;
}


// ===== ver_dsp @ fff94c2d (12 bytes)

/* Returns pointer to DSP version 0x1444 (VE3) */

uint ver_dsp(void)

{
  return 0x1444;
}


// ===== ver_dsp_set @ fff94c39 (18 bytes)

/* Copies the 6-char "V01-01" DSP version text to 0x1444 (read by ver_dsp / VE3) */

void ver_dsp_set(void *param_1)

{
  DAT_00001448 = *(undefined2 *)((int)param_1 + 4);
  DAT_00001444 = *(undefined4 *)param_1;
  return;
}


// ===== ver_sdr @ fff94c4b (12 bytes)

/* Returns pointer to SDR version 0x144A (VE2) */

uint ver_sdr(void)

{
  return 0x144a;
}


// ===== FUN_fff94c57 @ fff94c57 (18 bytes)

void FUN_fff94c57(undefined4 *param_1)

{
  DAT_0000144e = *(undefined2 *)(param_1 + 1);
  DAT_0000144a = *param_1;
  return;
}


// ===== FUN_fff94c69 @ fff94c69 (12 bytes)

void FUN_fff94c69(void)

{
  return;
}


// ===== FUN_fff94c75 @ fff94c75 (54 bytes)

void FUN_fff94c75(byte *param_1)

{
  byte2hex(&DAT_00001451,*param_1);
  byte2hex(&DAT_00001454,param_1[1]);
  DAT_00001450 = 0x56;
  DAT_00001453 = 0x2d;
  return;
}


// ===== qmb_boot_init @ fff94cab (196 bytes)

/* Boot: re-validates QMB recall state (0x9DBE/0x9DBF==5) and saves the QMB block if needed */

void qmb_boot_init(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = false;
  bVar2 = false;
  PTR_DAT_00025d38[0xb8] = 0xff;
  PTR_DAT_00025d38[0xb9] = 0xff;
  FUN_fffc3501();
  if (DAT_00009dbe == '\x05') {
    bVar2 = true;
    iVar3 = FUN_fff94fd5(0);
    if (iVar3 == 0) {
      bVar1 = true;
    }
  }
  if (DAT_00009dbf == '\x05') {
    bVar2 = true;
    iVar3 = FUN_fff94fd5(1);
    if (iVar3 == 0) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    FUN_fffc4a8e();
  }
  if (bVar2) {
    eeprom_save_qmb();
  }
  FUN_fff950fb();
  PTR_DAT_00025d38[0x40b] = 1;
  freq_cache_update();
  PTR_DAT_00025d38[0x72] = 0;
  PTR_DAT_00025d38[0x71] = 1;
  PTR_DAT_00025d38[0x484] = DAT_00009dc7;
  PTR_DAT_00025d38[0x485] = DAT_00009dc8;
  return;
}


// ===== displink_task @ fff94d6f (614 bytes)

/* DISPLAY link task (main_loop and power-off loop): rx validate/dispatch, ACK/NAK, gap 2 / ACK-wait
   30 units, scheduler, 3 retries */

void displink_task(void)

{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  ushort uVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  
  freq_cache_update();
  FUN_fffc8b55();
  FUN_fffcf45c();
  FUN_fff9513c();
  bVar2 = displink_rx_ready();
  if (bVar2 == 1) {
    bVar1 = false;
    pcVar6 = (char *)displink_rx_buf();
    uVar5 = displink_rx_len_of(*pcVar6);
    pcVar7 = &DAT_0000198f;
    pcVar9 = pcVar6;
    for (uVar10 = (uint)uVar5; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pcVar7 = *pcVar9;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
    displink_rx_rearm();
    if (uVar5 == 0) {
      DAT_0001b3cd = '\x01';
      bVar1 = true;
    }
    else {
      if ((*pcVar6 == '\x06') || (*pcVar6 == '\x15')) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if ((bVar3) && (bVar3 = displink_check_sum(0x198f,uVar5), !bVar3)) {
        DAT_0001b3cd = '\x01';
        bVar1 = true;
      }
    }
    if (!bVar1) {
      displink_rx_dispatch(&DAT_0000198f);
    }
  }
  if ((PTR_DAT_00025d38[0x401] == '\x01') && (bVar2 = swtimer_expired(0x2b), bVar2 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d38[0x401] = 0;
    PTR_DAT_00025d38[0x400] = 1;
  }
  if (DAT_0001b3d2 == '\x01') {
    bVar2 = sci1_tx_end();
    if (bVar2 == 0) {
      return;
    }
    DAT_0001b3d2 = '\0';
    DAT_0001b3d3 = '\x01';
    swtimer_start(0x3b,2);
  }
  if ((DAT_0001b3d3 == '\x01') && (bVar2 = swtimer_expired(0x3b), bVar2 == 1)) {
    DAT_0001b3d3 = '\0';
  }
  if (DAT_0001b3d5 == '\x01') {
    DAT_0001b3d5 = '\0';
    DAT_0001b3d4 = '\x01';
    swtimer_start(0x3c,0x1e);
  }
  if (DAT_0001b3d3 != '\x01') {
    if (DAT_0001b3d4 == '\0') {
      if (DAT_0001b3cc == '\x01') {
        DAT_0001b3cc = '\0';
        displink_send_ack();
      }
      else if (DAT_0001b3cd == '\x01') {
        DAT_0001b3cd = '\0';
        displink_send_nak();
      }
      else {
        displink_tx_poll();
        if (DAT_0001b3d2 == '\x01') {
          DAT_0001b3d5 = '\x01';
        }
      }
    }
    else {
      bVar2 = swtimer_expired(0x3c);
      if (bVar2 == 1) {
        DAT_0001b3d4 = '\0';
        displink_tx_poll();
        if (DAT_0001b3d2 == '\x01') {
          DAT_0001b3d5 = '\x01';
        }
      }
      else if (DAT_0001b3cc == '\x01') {
        DAT_0001b3cc = '\0';
        displink_send_ack();
      }
      else if (DAT_0001b3cd == '\x01') {
        DAT_0001b3cd = '\0';
        displink_send_nak();
      }
    }
    iVar8 = FUN_fffc911e();
    if (iVar8 == 0) {
      cVar4 = FUN_fff9ccd3();
      if (cVar4 == '\0') {
        PTR_DAT_00025d38[0x6a] = 1;
        PTR_DAT_00025d38[0x6b] = 1;
      }
      else {
        PTR_DAT_00025d38[0x6a] = 0;
        PTR_DAT_00025d38[0x6b] = 0;
      }
      swtimer_start(0x4a,100);
      FUN_fffc912d(1);
      return;
    }
  }
  return;
}


// ===== FUN_fff94fd5 @ fff94fd5 (294 bytes)

undefined1 FUN_fff94fd5(uint param_1)

{
  byte bVar1;
  byte *local_c;
  char *local_8;
  
  if (param_1 == 0) {
    local_8 = &DAT_0000901f;
    local_c = &DAT_00009020;
  }
  else {
    local_8 = &DAT_00009021;
    local_c = &DAT_00009022;
  }
  if (10 < DAT_00009014) {
    DAT_00009014 = 10;
  }
  if (*local_c == 0) {
    *local_8 = '\x01';
    if (DAT_00009ac0 == '\0') {
      if (DAT_00009014 < 6) {
        *local_c = DAT_00009014 - *local_8;
      }
      else {
        *local_c = 4;
      }
    }
    else {
      *local_c = DAT_00009014 - *local_8;
    }
  }
  else {
    bVar1 = *local_c + *local_8;
    if (DAT_00009ac0 == '\0') {
      *local_c = *local_c - 1;
      if (bVar1 < 6) {
        *local_8 = bVar1 - *local_c;
      }
      else {
        if (4 < *local_c) {
          *local_c = 0;
          return 0;
        }
        *local_8 = '\x05' - *local_c;
      }
    }
    else {
      *local_c = *local_c - 1;
      *local_8 = bVar1 - *local_c;
    }
  }
  FUN_fffc31a7(param_1 & 0xff,1);
  FUN_fffc334c(param_1 & 0xff);
  return 1;
}


// ===== FUN_fff950fb @ fff950fb (65 bytes)

void FUN_fff950fb(void)

{
  DAT_0000198b = DAT_0000901f;
  DAT_0000198c = DAT_00009020;
  DAT_0000198d = DAT_00009021;
  DAT_0000198e = DAT_00009022;
  return;
}


// ===== FUN_fff9513c @ fff9513c (195 bytes)

void FUN_fff9513c(void)

{
  if (DAT_0000198b != DAT_0000901f) {
    DAT_0000198b = DAT_0000901f;
  }
  if (DAT_0000198c != DAT_00009020) {
    DAT_0000198c = DAT_00009020;
  }
  if (DAT_0000198d != DAT_00009021) {
    DAT_0000198d = DAT_00009021;
  }
  if (DAT_0000198e != DAT_00009022) {
    DAT_0000198e = DAT_00009022;
  }
  if (PTR_DAT_00025d38[0x47f] != '\0') {
    eeprom_save_qmb_slot(PTR_DAT_00025d38[0x47f] - 1);
    PTR_DAT_00025d38[0x47f] = 0;
    return;
  }
  return;
}


// ===== displink_tx_poll @ fff951ff (120 bytes)

/* Next frame (scheduler) or resend; after 3 retries drop, link down if hello */

void displink_tx_poll(void)

{
  if (PTR_DAT_00025d38[0x98] == '\x01') {
    if (DAT_0001b3ce == '\0') {
      displink_tx_schedule();
      return;
    }
    DAT_0001b3cf = DAT_0001b3cf + 1;
    if (DAT_0001b3cf < 4) {
      displink_tx_resend();
      return;
    }
    DAT_0001b3cf = '\0';
    DAT_0001b3ce = '\0';
    if (DAT_0001b3d1 == '\x01') {
      DAT_0001b3d1 = 0;
      DAT_0001b3d0 = 0;
      PTR_DAT_00025d38[0x98] = 0;
      return;
    }
  }
  return;
}


// ===== displink_rx_len_of @ fff95277 (186 bytes)

/* Frame length by type for received frames (0 = unknown -> NAK) */

ushort displink_rx_len_of(char param_1)

{
  ushort local_6;
  
  if ((param_1 == '\x06') || (param_1 == '\x15')) {
    local_6 = 1;
  }
  else if (param_1 == -0x3d) {
    local_6 = 0x23;
  }
  else if (param_1 == -0x3c) {
    local_6 = 0x107;
  }
  else if (param_1 == -0x3b) {
    local_6 = 7;
  }
  else if (param_1 == -0x20) {
    local_6 = 6;
  }
  else if (param_1 == -0x1f) {
    local_6 = 7;
  }
  else if (param_1 == -0x1e) {
    local_6 = 7;
  }
  else if (param_1 == -0x1d) {
    local_6 = 9;
  }
  else if (param_1 == -0x1c) {
    local_6 = 5;
  }
  else if (param_1 == -0x1b) {
    local_6 = 5;
  }
  else if (param_1 == -0x1a) {
    local_6 = 5;
  }
  else if (param_1 == -0x19) {
    local_6 = 10;
  }
  else if (param_1 == -0x18) {
    local_6 = 10;
  }
  else if (param_1 == -3) {
    local_6 = 0xb;
  }
  else if (param_1 == -0xf) {
    local_6 = 8;
  }
  else if (param_1 == -0x10) {
    local_6 = 10;
  }
  else {
    local_6 = 0;
  }
  return local_6;
}


// ===== displink_rx_dispatch @ fff95331 (237 bytes)

/* Switch on received type; APO reset for all but 06/15/E3 */

void displink_rx_dispatch(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 == -0xf) {
    displink_rx_F1_sys((int)param_1);
  }
  else if (cVar1 == '\x15') {
    displink_rx_nak();
  }
  else if (cVar1 == -0x4d) {
    FUN_fff95ec9();
  }
  else if (cVar1 == -0x3d) {
    displink_rx_C3((int)param_1);
  }
  else if (cVar1 == -0x3c) {
    displink_rx_C4_C5((int)param_1);
  }
  else if (cVar1 == -0x3b) {
    displink_rx_C4_C5((int)param_1);
  }
  else if (cVar1 == -0x20) {
    displink_rx_E0_key((int)param_1);
  }
  else if (cVar1 == -0x1f) {
    displink_rx_E1_encoder((int)param_1);
  }
  else if (cVar1 == -0x1e) {
    displink_rx_E2((int)param_1);
  }
  else if (cVar1 == -0x1d) {
    displink_rx_E3_clock((int)param_1);
  }
  else if (cVar1 == -0x1c) {
    displink_rx_E4();
    PTR_DAT_00025d38[0x82] = 0;
  }
  else if (cVar1 == -0x1b) {
    displink_rx_E5();
  }
  else if (cVar1 == -0x1a) {
    displink_rx_E6_beep((int)param_1);
  }
  else if (cVar1 == -0x19) {
    displink_rx_E7((int)param_1);
  }
  else if (cVar1 == -0x18) {
    displink_rx_E8((int)param_1);
  }
  else if (cVar1 == -0x10) {
    displink_rx_F0_hello((int)param_1);
  }
  else if (cVar1 == '\x06') {
    displink_rx_ack();
  }
  cVar1 = *param_1;
  if (((cVar1 != '\x06') && (cVar1 != '\x15')) && (cVar1 != -0x1d)) {
    cat_apo_reset();
    return;
  }
  return;
}


// ===== displink_rx_ack @ fff9541e (75 bytes)

/* ACK: clear outstanding; after the hello reply sets +0x400 (send 0x24) */

void displink_rx_ack(void)

{
  if (DAT_0001b3ce == '\x01') {
    DAT_0001b3ce = '\0';
    DAT_0001b3cf = 0;
    if (DAT_0001b3d1 == '\x01') {
      DAT_0001b3d1 = 0;
      DAT_0001b3d0 = 0;
      PTR_DAT_00025d38[0x400] = 1;
      return;
    }
  }
  return;
}


// ===== displink_rx_nak @ fff95469 (1 bytes)

/* NAK: no action */

void displink_rx_nak(void)

{
  return;
}


// ===== displink_rx_F0_hello @ fff9546a (892 bytes)

/* F0: DISPLAY version/date, boot code b7 (1 reset, 2, 4 numeric mode, 5, 6 link down, 7 destination
   swap, 0x10 warm), link up, power on (+0x36) */

void displink_rx_F0_hello(int param_1)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  ushort uVar4;
  
  DAT_000019bb = 0;
  DAT_000019b7 = 0;
  DAT_000019b3 = 0;
  DAT_000019af = 0;
  DAT_000019ab = 0;
  DAT_000019a7 = 0;
  DAT_000019a3 = 0;
  DAT_0000199f = 0;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._0_1_ = 0x56;
  bVar3 = *(byte *)(param_1 + 1) >> 4;
  if ((bVar3 < 10) || (0xf < bVar3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._1_1_ = bVar3 + 0x37;
  }
  else {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._1_1_ = bVar3 + 0x30;
  }
  bVar3 = *(byte *)(param_1 + 1) & 0xf;
  if ((bVar3 < 10) || (0xf < bVar3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._2_1_ = bVar3 + 0x37;
  }
  else {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._2_1_ = bVar3 + 0x30;
  }
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._3_1_ = 0x2d;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._0_1_ = *(byte *)(param_1 + 2) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._1_1_ = *(byte *)(param_1 + 2) & 0x3f | 0x30;
  FUN_fff94bfd(&DAT_0000199f);
  DAT_000019bb = 0;
  DAT_000019b7 = 0;
  DAT_000019b3 = 0;
  DAT_000019af = 0;
  DAT_000019ab = 0;
  DAT_000019a7 = 0;
  DAT_000019a3 = 0;
  DAT_0000199f = 0;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._0_1_ = *(byte *)(param_1 + 4) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._1_1_ = *(byte *)(param_1 + 4) & 0x3f | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._2_1_ = 0x2d;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._3_1_ = *(byte *)(param_1 + 5) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._0_1_ = *(byte *)(param_1 + 5) & 0x3f | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._1_1_ = 0x2d;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._2_1_ = *(byte *)(param_1 + 6) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._3_1_ = *(byte *)(param_1 + 6) & 0x3f | 0x30;
  FUN_fff94c1b(&DAT_0000199f);
  PTR_DAT_00025d38[0x9b] = *(undefined1 *)(param_1 + 7);
  PTR_DAT_00025d38[0x98] = 1;
  DAT_0001b3cc = 1;
  DAT_0001b3d0 = 1;
  PTR_DAT_00025d38[0x36] = 1;
  cVar1 = PTR_DAT_00025d38[0x9b];
  if (cVar1 == '\x10') {
    if (DAT_00009dc5 == '\0') {
      PTR_DAT_00025d38[0x36] = 0;
      return;
    }
  }
  else {
    if (cVar1 == '\x02') {
      PTR_DAT_00025d38[0xba] = 1;
      align_load_preset();
      return;
    }
    if (cVar1 == '\x04') {
      PTR_DAT_00025d38[0x437] = 1;
      PTR_DAT_00025d38[0x34] = 0;
      return;
    }
    if (cVar1 == '\x05') {
      if (DAT_00004760 == '\0') {
        DAT_00004760 = 1;
        return;
      }
      DAT_00004760 = '\0';
      if (4 < DAT_00009a36) {
        DAT_00009a36 = 1;
        return;
      }
    }
    else {
      if (cVar1 == '\x06') {
        PTR_DAT_00025d38[0x98] = 0;
        DAT_0001b3d0 = 0;
        return;
      }
      if (cVar1 == '\a') {
        uVar4 = dest_code_get();
        if ((uVar4 == 0xa983) || (uVar4 == 0xb5a7)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          dest_code_set(0xd950);
        }
        else {
          if ((uVar4 == 0xd950) || (uVar4 == 0xa4c5)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (bVar2) {
            dest_code_set(0xa983);
          }
        }
        dest_jumper_apply();
        return;
      }
      if (cVar1 == '\x01') {
        settings_defaults(0);
        DAT_00020b45 = 1;
        dest_jumper_apply();
        return;
      }
    }
  }
  return;
}


// ===== displink_rx_F1_sys @ fff957e6 (67 bytes)

/* F1 sub: 01 SDR bridge, 02 DSP ISP tunnel, 03 CAT disable (0x20B46), 83 nop */

void displink_rx_F1_sys(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 != -0x7d) {
    if (cVar1 == '\x02') {
      dsp_isp_request();
      return;
    }
    if (cVar1 != '\x03') {
      if (cVar1 == '\x01') {
        sdr_bridge_request();
        return;
      }
      DAT_0001b3cd = 1;
      return;
    }
    DAT_00020b46 = 1;
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E0_key @ fff95829 (98 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9582f) */
/* E0 key/touch event -> key_event_filter -> mailbox +0x9C..+0xA0 */

void displink_rx_E0_key(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  
  uVar3 = CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3));
  bVar1 = *(byte *)(param_1 + 1);
  DAT_0001b3cc = 1;
  bVar2 = key_event_filter(uVar3,bVar1);
  if (bVar2 != 0) {
    PTR_DAT_00025d38[0x9c] = bVar1 >> 4;
    PTR_DAT_00025d38[0x9d] = bVar1 & 0xf;
    *(ushort *)(PTR_DAT_00025d38 + 0x9e) = uVar3;
    PTR_DAT_00025d38[0xa0] = 1;
    return;
  }
  return;
}


// ===== displink_rx_E1_encoder @ fff9588b (473 bytes)

/* E1 encoder id/step -> main dial / knobs / +0xA3/+0xA4 */

void displink_rx_E1_encoder(int param_1)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  
  if (PTR_DAT_00025d38[0x80] == '\x01') {
    DAT_0001b3cc = 1;
    return;
  }
  PTR_DAT_00025d38[0xa1] = *(undefined1 *)(param_1 + 1);
  if ((PTR_DAT_00025d38[0xa1] == '\x06') && (PTR_DAT_00025d38[0x70] == '\x01')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (PTR_DAT_00025d38[0xa1] = 3, PTR_DAT_00025d38[0x74] == '\0')) {
    *(byte *)(param_1 + 2) = ~*(byte *)(param_1 + 2) + 1;
  }
  cVar1 = PTR_DAT_00025d38[0xa1];
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      bVar3 = key_event_filter(0xff1,0);
      if (bVar3 == 0) {
        DAT_0001b3cc = 1;
        return;
      }
      enc2_step(*(char *)(param_1 + 2));
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 == '\x03') {
      bVar3 = key_event_filter(0xff2,0);
      if (bVar3 == 0) {
        DAT_0001b3cc = 1;
        return;
      }
      enc3_step(*(char *)(param_1 + 2));
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 == '\x04') {
      if (PTR_DAT_00025d38[0x93] == '\x01') {
        if ((PTR_DAT_00025d38[0x3fd] == '\x01') || (PTR_DAT_00025d38[0x3fd] == '\x02')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if ((bVar2) || (PTR_DAT_00025d38[0x3fd] == '\x03')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          DAT_0001b3cc = 1;
          return;
        }
      }
      if (PTR_DAT_00025d38[0x437] != '\0') {
        FUN_fffc89ef(*(undefined1 *)(param_1 + 2));
        DAT_0001b3cc = 1;
        return;
      }
      FUN_fffc523a(0,0);
      iVar4 = FUN_fffc519d(0,1);
      if (iVar4 != 1) {
        DAT_0001b3cc = 1;
        return;
      }
      PTR_DAT_00025d38[0xa3] = *(undefined1 *)(param_1 + 2);
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 == '\x05') {
      if (PTR_DAT_00025d38[0x437] != '\0') {
        FUN_fffc8a90(*(undefined1 *)(param_1 + 2));
        DAT_0001b3cc = 1;
        return;
      }
      PTR_DAT_00025d38[0xa4] = *(undefined1 *)(param_1 + 2);
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 != '\x06') {
      DAT_0001b3cc = 1;
      return;
    }
  }
  bVar3 = key_event_filter(0xff0,0);
  if (bVar3 != 0) {
    PTR_DAT_00025d38[0xa2] = *(undefined1 *)(param_1 + 2);
    if (PTR_DAT_00025d38[0x437] == '\0') {
      enc_main_dial(PTR_DAT_00025d38[0xa2]);
    }
    else {
      ui_numentry_step(PTR_DAT_00025d38[0xa2]);
    }
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== ui_numentry_step @ fff95a64 (106 bytes)

/* Signed step on counter 0x25D3C (0..99999999) */

void ui_numentry_step(byte param_1)

{
  if (0x80 < param_1) {
    if ((byte)(~param_1 + 1) < DAT_00025d3c) {
      DAT_00025d3c = DAT_00025d3c - (byte)(~param_1 + 1);
      return;
    }
    DAT_00025d3c = 0;
    return;
  }
  if (DAT_00025d3c + param_1 < 99999999) {
    DAT_00025d3c = DAT_00025d3c + param_1;
    return;
  }
  DAT_00025d3c = 99999999;
  return;
}


// ===== ui_numentry_to_bcd @ fff95ace (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfff95b7f) */
/* WARNING: Removing unreachable block (ram,0xfff95b76) */
/* WARNING: Removing unreachable block (ram,0xfff95b50) */
/* WARNING: Removing unreachable block (ram,0xfff95ae5) */
/* WARNING: Removing unreachable block (ram,0xfff95ada) */
/* WARNING: Removing unreachable block (ram,0xfff95b02) */
/* WARNING: Removing unreachable block (ram,0xfff95b2a) */
/* WARNING: Removing unreachable block (ram,0xfff95b34) */
/* WARNING: Removing unreachable block (ram,0xfff95b9a) */
/* WARNING: Removing unreachable block (ram,0xfff95bbe) */
/* WARNING: Removing unreachable block (ram,0xfff95bc6) */
/* 0x25D3C -> BCD at +0x7C..+0x7F */

void ui_numentry_to_bcd(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = DAT_00025d3c;
  uVar2 = DAT_00025d3c / 10000000;
  PTR_DAT_00025d38[0x7c] = (char)uVar2 << 4;
  uVar3 = uVar3 + (uVar2 & 0xff) * -10000000;
  uVar2 = uVar3 / 1000000;
  PTR_DAT_00025d38[0x7c] = PTR_DAT_00025d38[0x7c] | (byte)uVar2;
  uVar3 = uVar3 + (uVar2 & 0xff) * -1000000;
  uVar2 = uVar3 / 100000;
  PTR_DAT_00025d38[0x7d] = (char)uVar2 << 4;
  uVar3 = uVar3 + (uVar2 & 0xff) * -100000;
  uVar2 = uVar3 / 10000;
  PTR_DAT_00025d38[0x7d] = PTR_DAT_00025d38[0x7d] | (byte)uVar2;
  uVar3 = uVar3 + (uVar2 & 0xff) * -10000;
  uVar2 = uVar3 / 1000;
  PTR_DAT_00025d38[0x7e] = (char)uVar2 << 4;
  uVar3 = uVar3 + (uVar2 & 0xff) * -1000;
  uVar2 = uVar3 / 100;
  PTR_DAT_00025d38[0x7e] = PTR_DAT_00025d38[0x7e] | (byte)uVar2;
  uVar3 = uVar3 + (uVar2 & 0xff) * -100;
  cVar1 = (char)(uVar3 / 10);
  PTR_DAT_00025d38[0x7f] = cVar1 << 4;
  PTR_DAT_00025d38[0x7f] = PTR_DAT_00025d38[0x7f] | (char)uVar3 + cVar1 * -10;
  return;
}


// ===== displink_rx_E2 @ fff95bf4 (118 bytes)

/* E2: +0xA5..+0xA7 on/off state */

void displink_rx_E2(int param_1)

{
  if (PTR_DAT_00025d38[0xa5] == '\0') {
    PTR_DAT_00025d38[0xa5] = 1;
    if (*(char *)(param_1 + 1) == '\0') {
      PTR_DAT_00025d38[0xa6] = 0;
      PTR_DAT_00025d38[0xa7] = 0;
    }
    else {
      PTR_DAT_00025d38[0xa6] = 1;
      PTR_DAT_00025d38[0xa7] = 1;
    }
  }
  else if (*(char *)(param_1 + 1) == '\0') {
    PTR_DAT_00025d38[0xa6] = 0;
  }
  else {
    PTR_DAT_00025d38[0xa6] = 1;
  }
  DAT_0001b3cc = 1;
  return;
}

