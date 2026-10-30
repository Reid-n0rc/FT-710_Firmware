// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== r_sci5_transmit_interrupt @ fff94851 (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94887) */
/* WARNING: Removing unreachable block (ram,0xfff94851) */
/* WARNING: Removing unreachable block (ram,0xfff94899) */

void r_sci5_transmit_interrupt(void)

{
  byte bVar1;
  
  if (DAT_0001b622 == 0) {
    bVar1 = SCI5_SCR;
    SCI5_SCR = bVar1 & 0x7f;
    bVar1 = SCI5_SCR;
    SCI5_SCR = bVar1 | 4;
    return;
  }
  SCI5_TDR = *DAT_0002081c;
  DAT_0002081c = DAT_0002081c + 1;
  DAT_0001b622 = DAT_0001b622 + -1;
  return;
}


// ===== r_sci5_transmitend_interrupt @ fff9489d (37 bytes)

/* TEI5 (cb 0x1E) */

void r_sci5_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = PORTC_PMR;
  PORTC_PMR = bVar1 & 0xf7;
  bVar1 = SCI5_SCR;
  SCI5_SCR = bVar1 & 0x7f;
  bVar1 = SCI5_SCR;
  SCI5_SCR = bVar1 & 0xdf;
  bVar1 = SCI5_SCR;
  SCI5_SCR = bVar1 & 0xfb;
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
    uVar2 = SCI5_RDR;
    *DAT_00020820 = uVar2;
    sci5_rx_byte_hook();
    DAT_00020820 = DAT_00020820 + 1;
    DAT_0001b624 = DAT_0001b624 + 1;
  }
  if (DAT_0001b626 <= DAT_0001b624) {
    bVar1 = SCI5_SCR;
    SCI5_SCR = bVar1 & 0xbf;
    bVar1 = SCI5_SCR;
    SCI5_SCR = bVar1 & 0xef;
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
  bVar1 = SCI5_SSR;
  SCI5_SSR = bVar1 & 199 | 0xc0;
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
  
  uVar1 = SYSTEM_MSTPCRA;
  SYSTEM_MSTPCRA = uVar1 & 0xffffdfff;
  bVar2 = TPUA_TSTR;
  TPUA_TSTR = bVar2 & 0xfe;
  ICU_SLIBXR130 = 0xf;
  bVar2 = ICU_IPR130;
  ICU_IPR130 = bVar2 & 0xf4 | 4;
  bVar2 = TPUA_TSYR;
  TPUA_TSYR = bVar2 & 0xfe;
  TPU0_TCR = 0x2a;
  bVar2 = TPU0_TIER;
  TPU0_TIER = bVar2 | 0x41;
  TPU0_TIORH = 0;
  TPU0_TIORL = 0;
  TPU0_TGRA = 0x176;
  TPU0_TGRB = 0x176;
  TPU0_TGRC = 0x176;
  TPU0_TGRD = 0x176;
  R_TPU0_Create_UserInit();
  return;
}


// ===== R_TPU0_Start @ fff94a38 (15 bytes)

/* Enable vector 130 and TSTR bit 0 */

void R_TPU0_Start(void)

{
  byte bVar1;
  
  bVar1 = ICU_IER10;
  ICU_IER10 = bVar1 | 4;
  bVar1 = TPUA_TSTR;
  TPUA_TSTR = bVar1 | 1;
  return;
}


// ===== R_TPU0_Stop @ fff94a47 (15 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.950): IEN of
   TGI0A (0x87210 bit 2) off, TPU TSTR (0x88100) CST0 off; after R_TPU0_Start [inference] */

void R_TPU0_Stop(void)

{
  byte bVar1;
  
  bVar1 = ICU_IER10;
  ICU_IER10 = bVar1 & 0xfb;
  bVar1 = TPUA_TSTR;
  TPUA_TSTR = bVar1 & 0xfe;
  return;
}


// ===== R_TPU0_Create_UserInit @ fff94a56 (1 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): empty rts,
   called last by R_TPU0_Create [inference] */

void R_TPU0_Create_UserInit(void)

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
  
  uVar1 = SYSTEM_MSTPCRA;
  SYSTEM_MSTPCRA = uVar1 & 0xffffdfff;
  bVar2 = TPUA_TSTR;
  TPUA_TSTR = bVar2 & 0xfd;
  ICU_SLIBR144 = 0x14;
  bVar2 = ICU_IPR144;
  ICU_IPR144 = bVar2 & 0xfe | 0xe;
  bVar2 = TPUA_TSYR;
  TPUA_TSYR = bVar2 & 0xfd;
  TPU1_TCR = 0x20;
  bVar2 = TPU1_TIER;
  TPU1_TIER = bVar2 | 0x41;
  TPU1_TIOR = 0;
  TPU1_TGRA = 0x270;
  TPU1_TGRB = 5999;
  R_TPU1_Create_UserInit();
  return;
}


// ===== R_TPU1_Start @ fff94acd (15 bytes)

/* TSTR bit 1 */

void R_TPU1_Start(void)

{
  byte bVar1;
  
  bVar1 = ICU_IER12;
  ICU_IER12 = bVar1 | 1;
  bVar1 = TPUA_TSTR;
  TPUA_TSTR = bVar1 | 2;
  return;
}


// ===== R_TPU1_Stop @ fff94adc (15 bytes)

/* Stop TPU1 */

void R_TPU1_Stop(void)

{
  byte bVar1;
  
  bVar1 = ICU_IER12;
  ICU_IER12 = bVar1 & 0xfe;
  bVar1 = TPUA_TSTR;
  TPUA_TSTR = bVar1 & 0xfd;
  return;
}


// ===== R_TPU1_Create_UserInit @ fff94aeb (1 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): empty rts,
   called last by R_TPU1_Create [inference] */

void R_TPU1_Create_UserInit(void)

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
  while (g_ui.radio_on == 0) {
    displink_task();
    cat_parse();
    wdt_kick();
  }
  if (g_ui.defaults_loaded == 1) {
    g_ui.defaults_loaded = 0;
    eeprom_save_all();
    g_ui.freq_refresh_req = 1;
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
  screensaver_timer_restart();
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


// ===== ver_main_ext1 @ fff94bd9 (12 bytes)

/* Returns 0xFFFFFF10, ROM string "2101", shown after "V01-12-" in SOFT VERSION when DBG MODE ENABLE
   (0x4660) is set [fact: MAIN image]; meaning open (#205) */

undefined4 ver_main_ext1(void)

{
  return 0xffffff10;
}


// ===== ver_main_ext2 @ fff94be5 (12 bytes)

/* Returns 0xFFFFFF20, ROM string "24-02-16" (release date, = SFL header [DATE] 2024/02/16), shown
   in SOFT VERSION when DBG MODE ENABLE (0x4660) is set [fact] (#205) */

undefined4 ver_main_ext2(void)

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


// ===== ver_display_date @ fff94c0f (12 bytes)

/* Returns 0x143C, the 8-char DISPLAY date "yy-mm-dd" (ver_display_date_set); shown in SOFT VERSION
   when DBG MODE ENABLE is set [fact: disassembly 0xFFF94C11] (#205) */

void ver_display_date(void)

{
  return;
}


// ===== ver_display_date_set @ fff94c1b (18 bytes)

/* Stores the 8-char DISPLAY date "yy-mm-dd" (from F0 hello bytes 4..6) at 0x143C [fact] (#205) */

void ver_display_date_set(undefined4 *param_1)

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
  PTR_g_ui_00025d38->dl_64_value = 0xff;
  PTR_g_ui_00025d38->dl_64_sent = 0xff;
  FUN_fffc3501();
  if (g_opstate.vfo_state_a == VFO_STATE_QMB) {
    bVar2 = true;
    iVar3 = FUN_fff94fd5(0);
    if (iVar3 == 0) {
      bVar1 = true;
    }
  }
  if (g_opstate.vfo_state_b == VFO_STATE_QMB) {
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
  PTR_g_ui_00025d38->vfo_refresh_req = 1;
  freq_cache_update();
  PTR_g_ui_00025d38->func_blink_en = 0;
  PTR_g_ui_00025d38->func_blink_on = 1;
  PTR_g_ui_00025d38->split_saved_state_a = g_opstate.split_saved_vfo_state_a;
  PTR_g_ui_00025d38->split_saved_state_b = g_opstate.split_saved_vfo_state_b;
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
  if ((PTR_g_ui_00025d38->dl_req_24_later == 1) && (bVar2 = swtimer_expired(0x2b), bVar2 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_g_ui_00025d38->dl_req_24_later = 0;
    PTR_g_ui_00025d38->dl_req_24 = 1;
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
        PTR_g_ui_00025d38->freq_settled_a = 1;
        PTR_g_ui_00025d38->freq_settled_b = 1;
      }
      else {
        PTR_g_ui_00025d38->freq_settled_a = 0;
        PTR_g_ui_00025d38->freq_settled_b = 0;
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
  byte *local_8;
  
  if (param_1 == 0) {
    local_8 = g_qmb_hdr.ptr_a;
    local_c = g_qmb_hdr.ptr_a;
  }
  else {
    local_8 = g_qmb_hdr.ptr_b;
    local_c = g_qmb_hdr.ptr_b;
  }
  local_c = local_c + 1;
  if (10 < g_qmb_hdr.count) {
    g_qmb_hdr.count = 10;
  }
  if (*local_c == 0) {
    *local_8 = 1;
    if (g_opstate.ex030112_qmb_ch == 0) {
      if (g_qmb_hdr.count < 6) {
        *local_c = g_qmb_hdr.count - *local_8;
      }
      else {
        *local_c = 4;
      }
    }
    else {
      *local_c = g_qmb_hdr.count - *local_8;
    }
  }
  else {
    bVar1 = *local_c + *local_8;
    if (g_opstate.ex030112_qmb_ch == 0) {
      *local_c = *local_c - 1;
      if (bVar1 < 6) {
        *local_8 = bVar1 - *local_c;
      }
      else {
        if (4 < *local_c) {
          *local_c = 0;
          return 0;
        }
        *local_8 = 5 - *local_c;
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
  DAT_0000198b = g_qmb_hdr.ptr_a[0];
  DAT_0000198c = g_qmb_hdr.ptr_a[1];
  DAT_0000198d = g_qmb_hdr.ptr_b[0];
  DAT_0000198e = g_qmb_hdr.ptr_b[1];
  return;
}


// ===== FUN_fff9513c @ fff9513c (195 bytes)

void FUN_fff9513c(void)

{
  if (DAT_0000198b != g_qmb_hdr.ptr_a[0]) {
    DAT_0000198b = g_qmb_hdr.ptr_a[0];
  }
  if (DAT_0000198c != g_qmb_hdr.ptr_a[1]) {
    DAT_0000198c = g_qmb_hdr.ptr_a[1];
  }
  if (DAT_0000198d != g_qmb_hdr.ptr_b[0]) {
    DAT_0000198d = g_qmb_hdr.ptr_b[0];
  }
  if (DAT_0000198e != g_qmb_hdr.ptr_b[1]) {
    DAT_0000198e = g_qmb_hdr.ptr_b[1];
  }
  if (PTR_g_ui_00025d38->qmb_pending_slot != 0) {
    eeprom_save_qmb_slot(PTR_g_ui_00025d38->qmb_pending_slot - 1);
    PTR_g_ui_00025d38->qmb_pending_slot = 0;
    return;
  }
  return;
}


// ===== displink_tx_poll @ fff951ff (120 bytes)

/* Next frame (scheduler) or resend; after 3 retries drop, link down if hello */

void displink_tx_poll(void)

{
  if (PTR_g_ui_00025d38->link_tx_enabled == 1) {
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
      PTR_g_ui_00025d38->link_tx_enabled = 0;
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

/* Switch on received type; screen-saver timer restart for all but 06/15/E3 */

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
    PTR_g_ui_00025d38->screensaver_on = 0;
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
    screensaver_timer_restart();
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
      PTR_g_ui_00025d38->dl_req_24 = 1;
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
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  
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
  bVar2 = *(byte *)(param_1 + 1) >> 4;
  if ((bVar2 < 10) || (0xf < bVar2)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._1_1_ = bVar2 + 0x37;
  }
  else {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._1_1_ = bVar2 + 0x30;
  }
  bVar2 = *(byte *)(param_1 + 1) & 0xf;
  if ((bVar2 < 10) || (0xf < bVar2)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._2_1_ = bVar2 + 0x37;
  }
  else {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._2_1_ = bVar2 + 0x30;
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
  ver_display_date_set(&DAT_0000199f);
  PTR_g_ui_00025d38->power_on_reason = *(byte *)(param_1 + 7);
  PTR_g_ui_00025d38->link_tx_enabled = 1;
  DAT_0001b3cc = 1;
  DAT_0001b3d0 = 1;
  PTR_g_ui_00025d38->radio_on = 1;
  bVar2 = PTR_g_ui_00025d38->power_on_reason;
  if (bVar2 == 0x10) {
    if (g_opstate.auto_power_on == 0) {
      PTR_g_ui_00025d38->radio_on = 0;
      return;
    }
  }
  else {
    if (bVar2 == 2) {
      PTR_g_ui_00025d38->zz_align_mode = 1;
      align_load_preset();
      return;
    }
    if (bVar2 == 4) {
      PTR_g_ui_00025d38->numentry_mode = 1;
      PTR_g_ui_00025d38->lamp_map = 0;
      return;
    }
    if (bVar2 == 5) {
      if (dest_code[2] == 0) {
        dest_code[2] = 1;
        return;
      }
      dest_code[2] = 0;
      if (4 < g_opstate.ex010113_tx_bpf_sel) {
        g_opstate.ex010113_tx_bpf_sel = 1;
        return;
      }
    }
    else {
      if (bVar2 == 6) {
        PTR_g_ui_00025d38->link_tx_enabled = 0;
        DAT_0001b3d0 = 0;
        return;
      }
      if (bVar2 == 7) {
        uVar3 = dest_code_get();
        if ((uVar3 == 0xa983) || (uVar3 == 0xb5a7)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          dest_code_set(0xd950);
        }
        else {
          if ((uVar3 == 0xd950) || (uVar3 == 0xa4c5)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            dest_code_set(0xa983);
          }
        }
        dest_jumper_apply();
        return;
      }
      if (bVar2 == 1) {
        settings_defaults(0);
        g_ui.defaults_loaded = 1;
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
    g_ui.cat_disabled = 1;
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
    PTR_g_ui_00025d38->key_ev_src = bVar1 >> 4;
    PTR_g_ui_00025d38->key_ev_type = bVar1 & 0xf;
    PTR_g_ui_00025d38->key_ev_code = uVar3;
    PTR_g_ui_00025d38->key_ev_flag = 1;
    return;
  }
  return;
}


// ===== displink_rx_E1_encoder @ fff9588b (473 bytes)

/* E1 encoder id/step -> main dial / knobs / +0xA3/+0xA4 */

void displink_rx_E1_encoder(int param_1)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  if (PTR_g_ui_00025d38->enc_blocked == 1) {
    DAT_0001b3cc = 1;
    return;
  }
  PTR_g_ui_00025d38->enc_ev_id = *(byte *)(param_1 + 1);
  if ((PTR_g_ui_00025d38->enc_ev_id == 6) && (PTR_g_ui_00025d38->func_panel_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (PTR_g_ui_00025d38->enc_ev_id = 3, PTR_g_ui_00025d38->dsp_knob_edit == 0)) {
    *(byte *)(param_1 + 2) = ~*(byte *)(param_1 + 2) + 1;
  }
  bVar2 = PTR_g_ui_00025d38->enc_ev_id;
  if (bVar2 != 1) {
    if (bVar2 == 2) {
      bVar2 = key_event_filter(0xff1,0);
      if (bVar2 == 0) {
        DAT_0001b3cc = 1;
        return;
      }
      enc2_step(*(char *)(param_1 + 2));
      DAT_0001b3cc = 1;
      return;
    }
    if (bVar2 == 3) {
      bVar2 = key_event_filter(0xff2,0);
      if (bVar2 == 0) {
        DAT_0001b3cc = 1;
        return;
      }
      enc3_step(*(char *)(param_1 + 2));
      DAT_0001b3cc = 1;
      return;
    }
    if (bVar2 == 4) {
      if (PTR_g_ui_00025d38->playlist_open == 1) {
        if ((PTR_g_ui_00025d38->playlist_cmd == 1) || (PTR_g_ui_00025d38->playlist_cmd == 2)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if ((bVar1) || (PTR_g_ui_00025d38->playlist_cmd == 3)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_0001b3cc = 1;
          return;
        }
      }
      if (PTR_g_ui_00025d38->numentry_mode != 0) {
        FUN_fffc89ef(*(undefined1 *)(param_1 + 2));
        DAT_0001b3cc = 1;
        return;
      }
      FUN_fffc523a(0,0);
      iVar3 = key_dest_allowed(0,1);
      if (iVar3 != 1) {
        DAT_0001b3cc = 1;
        return;
      }
      PTR_g_ui_00025d38->rf_gain = *(byte *)(param_1 + 2);
      DAT_0001b3cc = 1;
      return;
    }
    if (bVar2 == 5) {
      if (PTR_g_ui_00025d38->numentry_mode != 0) {
        FUN_fffc8a90(*(undefined1 *)(param_1 + 2));
        DAT_0001b3cc = 1;
        return;
      }
      PTR_g_ui_00025d38->af_gain = *(byte *)(param_1 + 2);
      DAT_0001b3cc = 1;
      return;
    }
    if (bVar2 != 6) {
      DAT_0001b3cc = 1;
      return;
    }
  }
  bVar2 = key_event_filter(0xff0,0);
  if (bVar2 != 0) {
    PTR_g_ui_00025d38->enc_ev_steps = *(byte *)(param_1 + 2);
    if (PTR_g_ui_00025d38->numentry_mode == 0) {
      enc_main_dial(PTR_g_ui_00025d38->enc_ev_steps);
    }
    else {
      ui_numentry_step(PTR_g_ui_00025d38->enc_ev_steps);
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
  PTR_g_ui_00025d38->numentry_bcd[1] = (char)uVar2 << 4;
  uVar3 = uVar3 + (uVar2 & 0xff) * -10000000;
  uVar2 = uVar3 / 1000000;
  PTR_g_ui_00025d38->numentry_bcd[1] = PTR_g_ui_00025d38->numentry_bcd[1] | (byte)uVar2;
  uVar3 = uVar3 + (uVar2 & 0xff) * -1000000;
  uVar2 = uVar3 / 100000;
  PTR_g_ui_00025d38->numentry_bcd[2] = (char)uVar2 << 4;
  uVar3 = uVar3 + (uVar2 & 0xff) * -100000;
  uVar2 = uVar3 / 10000;
  PTR_g_ui_00025d38->numentry_bcd[2] = PTR_g_ui_00025d38->numentry_bcd[2] | (byte)uVar2;
  uVar3 = uVar3 + (uVar2 & 0xff) * -10000;
  uVar2 = uVar3 / 1000;
  PTR_g_ui_00025d38->numentry_bcd[3] = (char)uVar2 << 4;
  uVar3 = uVar3 + (uVar2 & 0xff) * -1000;
  uVar2 = uVar3 / 100;
  PTR_g_ui_00025d38->numentry_bcd[3] = PTR_g_ui_00025d38->numentry_bcd[3] | (byte)uVar2;
  uVar3 = uVar3 + (uVar2 & 0xff) * -100;
  cVar1 = (char)(uVar3 / 10);
  PTR_g_ui_00025d38->numentry_bcd[4] = cVar1 << 4;
  PTR_g_ui_00025d38->numentry_bcd[4] =
       PTR_g_ui_00025d38->numentry_bcd[4] | (char)uVar3 + cVar1 * -10;
  return;
}


// ===== displink_rx_E2 @ fff95bf4 (118 bytes)

/* E2: +0xA5..+0xA7 on/off state */

void displink_rx_E2(int param_1)

{
  if (PTR_g_ui_00025d38->sd_state_known == 0) {
    PTR_g_ui_00025d38->sd_state_known = 1;
    if (*(char *)(param_1 + 1) == '\0') {
      PTR_g_ui_00025d38->sd_present = 0;
      PTR_g_ui_00025d38->sd_present_prev = 0;
    }
    else {
      PTR_g_ui_00025d38->sd_present = 1;
      PTR_g_ui_00025d38->sd_present_prev = 1;
    }
  }
  else if (*(char *)(param_1 + 1) == '\0') {
    PTR_g_ui_00025d38->sd_present = 0;
  }
  else {
    PTR_g_ui_00025d38->sd_present = 1;
  }
  DAT_0001b3cc = 1;
  return;
}

