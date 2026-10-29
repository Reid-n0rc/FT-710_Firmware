// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== displink_rx_E4 @ fff95c6a (10 bytes)

/* E4: answer to 0x7B (clears +0x82, set by caller) */

void displink_rx_E4(void)

{
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E5 @ fff95c74 (22 bytes)

/* E5: clears +0x80 */

void displink_rx_E5(void)

{
  PTR_g_ui_00025d38->enc_blocked = 0;
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E6_beep @ fff95c8a (50 bytes)

/* E6: beep_request(b1+1) */

void displink_rx_E6_beep(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == '\x02') {
    beep_request(3);
  }
  else if (cVar1 == '\x01') {
    beep_request(2);
  }
  else if (cVar1 == '\0') {
    beep_request(1);
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E7 @ fff95cbc (241 bytes)

/* E7: result code in +0x488 */

void displink_rx_E7(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == -1) {
    PTR_g_ui_00025d38->f_0x0a8_u8 = *(byte *)(param_1 + 1);
    PTR_g_ui_00025d38->audio_error = *(byte *)(param_1 + 5);
    DAT_0001b3cc = 1;
    PTR_g_ui_00025d38->e7_status = 5;
    beep_stop();
    return;
  }
  if (cVar1 == '\x01') {
    PTR_g_ui_00025d38->f_0x0a8_u8 = *(byte *)(param_1 + 1);
    PTR_g_ui_00025d38->audio_playing = *(byte *)(param_1 + 5);
    DAT_0001b3cc = 1;
    if (*(char *)(param_1 + 5) == '\0') {
      PTR_g_ui_00025d38->e7_status = 2;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x01') {
      PTR_g_ui_00025d38->e7_status = 3;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x02') {
      PTR_g_ui_00025d38->e7_status = 4;
      return;
    }
  }
  else if (cVar1 == '\0') {
    PTR_g_ui_00025d38->f_0x0a8_u8 = *(byte *)(param_1 + 1);
    PTR_g_ui_00025d38->wav_count = *(byte *)(param_1 + 5);
    DAT_0001b3cc = 1;
    PTR_g_ui_00025d38->e7_status = 1;
    return;
  }
  return;
}


// ===== displink_rx_E8 @ fff95dad (184 bytes)

/* E8: result code in +0x48C */

void displink_rx_E8(int param_1)

{
  if (*(char *)(param_1 + 1) == -1) {
    PTR_g_ui_00025d38->f_0x0a8_u8 = *(byte *)(param_1 + 1);
    PTR_g_ui_00025d38->audio_error = *(byte *)(param_1 + 5);
    DAT_0001b3cc = 1;
    PTR_g_ui_00025d38->e8_status = 5;
    beep_stop();
    return;
  }
  if (*(char *)(param_1 + 1) == '\x01') {
    PTR_g_ui_00025d38->f_0x0a8_u8 = *(byte *)(param_1 + 1);
    PTR_g_ui_00025d38->audio_playing = *(byte *)(param_1 + 5);
    DAT_0001b3cc = 1;
    if (*(char *)(param_1 + 5) == '\0') {
      PTR_g_ui_00025d38->e8_status = 2;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x01') {
      PTR_g_ui_00025d38->e8_status = 3;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x02') {
      PTR_g_ui_00025d38->e8_status = 4;
      return;
    }
  }
  return;
}


// ===== displink_rx_C3 @ fff95e65 (50 bytes)

/* C3 reply (to 0x43): payload -> +0x2ED, +0x3F6=1 */

void displink_rx_C3(int param_1)

{
  byte *pbVar1;
  int iVar2;
  
  DAT_0001b3cc = 1;
  PTR_g_ui_00025d38->sd_answer_ready = 1;
  pbVar1 = PTR_g_ui_00025d38->sd_answer;
  for (iVar2 = 0x109; param_1 = param_1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *pbVar1 = *(byte *)param_1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== displink_rx_C4_C5 @ fff95e97 (50 bytes)

/* C4/C5 replies (to 0x45/0x44): payload -> +0x2ED, +0x3F6=1 */

void displink_rx_C4_C5(int param_1)

{
  byte *pbVar1;
  int iVar2;
  
  DAT_0001b3cc = 1;
  PTR_g_ui_00025d38->sd_answer_ready = 1;
  pbVar1 = PTR_g_ui_00025d38->sd_answer;
  for (iVar2 = 0x109; param_1 = param_1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *pbVar1 = *(byte *)param_1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== FUN_fff95ec9 @ fff95ec9 (10 bytes)

void FUN_fff95ec9(void)

{
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E3_clock @ fff95ed3 (83 bytes)

/* E3: 5 bytes -> +0xAD..+0xB1 (DISPLAY RTC date/time [inference]) */

void displink_rx_E3_clock(int param_1)

{
  PTR_g_ui_00025d38->rtc_yy = *(byte *)(param_1 + 1);
  PTR_g_ui_00025d38->rtc_mm = *(byte *)(param_1 + 2);
  PTR_g_ui_00025d38->rtc_dd = *(byte *)(param_1 + 3);
  PTR_g_ui_00025d38->rtc_hh = *(byte *)(param_1 + 4);
  PTR_g_ui_00025d38->rtc_min = *(byte *)(param_1 + 5);
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_send_ack @ fff95f26 (25 bytes)

/* send 0x06 */

void displink_send_ack(void)

{
  undefined1 local_1;
  
  local_1 = 6;
  displink_uart_send((uint)&local_1,1);
  DAT_0001b3d2 = 1;
  return;
}


// ===== displink_send_nak @ fff95f3f (25 bytes)

/* send 0x15 */

void displink_send_nak(void)

{
  undefined1 local_1;
  
  local_1 = 0x15;
  displink_uart_send((uint)&local_1,1);
  DAT_0001b3d2 = 1;
  return;
}


// ===== displink_tx_schedule @ fff95f58 (689 bytes)

/* MAIN->DISPLAY frame scheduler (priority list in display-link.md) */

void displink_tx_schedule(void)

{
  bool bVar1;
  byte bVar2;
  
  if (DAT_0001b3d0 == '\x01') {
    displink_tx_60_hello();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_64 == 1) {
    displink_tx_64();
    return;
  }
  if ((PTR_g_ui_00025d38->dl_req_24 == 1) && (PTR_g_ui_00025d38->playlist_open != 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_g_ui_00025d38->dl_req_24 = 0;
    displink_tx_24();
    return;
  }
  if (PTR_g_ui_00025d38->restart_req == 1) {
    power_down_save();
    return;
  }
  if (PTR_g_ui_00025d38->zz_align_mode != 0) {
    if ((PTR_g_ui_00025d38->dl_req_popup_a == 1) || (PTR_g_ui_00025d38->dl_req_popup_b == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      displink_tx_62();
      return;
    }
    displink_tx_30_31();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_7c == 1) {
    PTR_g_ui_00025d38->dl_req_7c = 0;
    displink_tx_7C();
    return;
  }
  if (PTR_g_ui_00025d38->enc_blocked == 1) {
    return;
  }
  if (PTR_g_ui_00025d38->screensaver_toggle_req == 1) {
    PTR_g_ui_00025d38->screensaver_toggle_req = 0;
    displink_tx_7B();
    return;
  }
  if (PTR_g_ui_00025d38->screensaver_on == 1) {
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_7a == 1) {
    PTR_g_ui_00025d38->dl_req_7a = 0;
    displink_tx_7A();
    return;
  }
  if (PTR_g_ui_00025d38->dl_block_7a == 1) {
    return;
  }
  if (PTR_g_ui_00025d38->dialog_shown == 1) {
    displink_tx_70();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_sd == 1) {
    displink_tx_req();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_50 != 0) {
    if (PTR_g_ui_00025d38->kbd_open != 1) {
      return;
    }
    displink_tx_50();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_23 == 1) {
    displink_tx_23();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_23b == 1) {
    FUN_fff98e58();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_23c == 1) {
    FUN_fff98e77();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_popup == 1) {
    displink_tx_30_31();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_65_clock == 1) {
    displink_tx_65_clock();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_34 == 1) {
    displink_tx_34();
    return;
  }
  if (PTR_g_ui_00025d38->dl_block_34 == 1) {
    return;
  }
  if (PTR_g_ui_00025d38->popup_hold == 0) {
    if ((PTR_g_ui_00025d38->dl_req_popup_a == 1) || (PTR_g_ui_00025d38->dl_req_popup_b == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fff96124;
    }
  }
  bVar1 = false;
LAB_fff96124:
  if (bVar1) {
    displink_tx_30_31();
    return;
  }
  if (PTR_g_ui_00025d38->kbd_open == 1) {
    displink_tx_50();
    return;
  }
  if (PTR_g_ui_00025d38->playlist_open == 1) {
    displink_tx_3A();
    return;
  }
  if (PTR_g_ui_00025d38->msgmem_open == 1) {
    displink_tx_39();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_3f == 1) {
    displink_tx_3F();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_40 == 1) {
    bVar2 = swtimer_expired(0x29);
    if (bVar2 != 1) {
      return;
    }
    swtimer_start(0x29,100);
    displink_tx_40();
    return;
  }
  if (PTR_g_ui_00025d38->dl_req_37 == 1) {
    displink_tx_37();
    return;
  }
  if (PTR_g_ui_00025d38->memlist_open != 1) {
    displink_tx_20_status();
    return;
  }
  displink_tx_41();
  return;
}


// ===== displink_tx_resend @ fff96209 (28 bytes)

/* resend frame 0x1456 (len 0x1B628) */

void displink_tx_resend(void)

{
  displink_uart_send(0x1456,DAT_0001b628);
  DAT_0001b3d2 = 1;
  return;
}


// ===== displink_tx_60_hello @ fff96225 (28 bytes)

/* 0x60 hello reply (0xB6 bytes) */

void displink_tx_60_hello(void)

{
  DAT_0001b3d1 = 1;
  displink_build_60();
  DAT_0001b628 = 0xb6;
  displink_tx_start(0xb6);
  return;
}


// ===== displink_build_60 @ fff96241 (532 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96241) */
/* WARNING: Removing unreachable block (ram,0xfff96452) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* versions (MAIN/DISPLAY/DSP/SDR) + status block */

void displink_build_60(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  
  mem_zero(0xb5,0x1456);
  DAT_00001456 = 0x60;
  puVar3 = (undefined4 *)ver_main();
  _DAT_000019c3 = *(undefined2 *)(puVar3 + 1);
  DAT_000019bf._1_1_ = (byte)((uint)*puVar3 >> 8);
  bVar2 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar3;
  cVar1 = hex2nib(bVar2);
  bVar2 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001457 = cVar1 << 4 | bVar2;
  cVar1 = hex2nib(DAT_000019c3);
  bVar2 = hex2nib(DAT_000019c4);
  DAT_00001458 = cVar1 << 4 | bVar2;
  puVar3 = (undefined4 *)ver_display();
  _DAT_000019c3 = *(undefined2 *)(puVar3 + 1);
  DAT_000019bf._1_1_ = (byte)((uint)*puVar3 >> 8);
  bVar2 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar3;
  cVar1 = hex2nib(bVar2);
  bVar2 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001459 = cVar1 << 4 | bVar2;
  cVar1 = hex2nib(DAT_000019c3);
  bVar2 = hex2nib(DAT_000019c4);
  DAT_0000145a = cVar1 << 4 | bVar2;
  puVar3 = (undefined4 *)ver_dsp();
  _DAT_000019c3 = *(undefined2 *)(puVar3 + 1);
  DAT_000019bf._1_1_ = (byte)((uint)*puVar3 >> 8);
  bVar2 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar3;
  cVar1 = hex2nib(bVar2);
  bVar2 = hex2nib(DAT_000019bf._2_1_);
  DAT_0000145b = cVar1 << 4 | bVar2;
  cVar1 = hex2nib(DAT_000019c3);
  bVar2 = hex2nib(DAT_000019c4);
  DAT_0000145c = cVar1 << 4 | bVar2;
  puVar3 = (undefined4 *)ver_sdr();
  _DAT_000019c3 = *(undefined2 *)(puVar3 + 1);
  DAT_000019bf._1_1_ = (byte)((uint)*puVar3 >> 8);
  bVar2 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar3;
  cVar1 = hex2nib(bVar2);
  bVar2 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001461 = cVar1 << 4 | bVar2;
  cVar1 = hex2nib(DAT_000019c3);
  bVar2 = hex2nib(DAT_000019c4);
  DAT_00001462 = cVar1 << 4 | bVar2;
  if ((PTR_g_ui_00025d38->boot_error == 0) && (g_cfg105.a008_gn_dbg_mode_enable != 0)) {
    PTR_g_ui_00025d38->boot_error = 0xdb;
  }
  DAT_00001463 = (undefined1)(PTR_g_ui_00025d38->boot_error >> 8);
  DAT_00001464 = (undefined1)PTR_g_ui_00025d38->boot_error;
  PTR_g_ui_00025d38->boot_error = 0;
  displink_build_status();
  puVar5 = &DAT_000016a1;
  puVar4 = &DAT_00001465;
  for (iVar6 = 0x97; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar4 = *puVar5;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  DAT_000014fc = g_opstate.ex040102_my_call_time;
  DAT_00001505._0_1_ = g_opstate.ex040101_my_call[8];
  DAT_00001505._1_1_ = g_opstate.ex040101_my_call[9];
  DAT_00001505._2_1_ = g_opstate.ex040101_my_call[10];
  DAT_00001505._3_1_ = g_opstate.ex040101_my_call[0xb];
  DAT_00001501._0_1_ = g_opstate.ex040101_my_call[4];
  DAT_00001501._1_1_ = g_opstate.ex040101_my_call[5];
  DAT_00001501._2_1_ = g_opstate.ex040101_my_call[6];
  DAT_00001501._3_1_ = g_opstate.ex040101_my_call[7];
  DAT_000014fd._0_1_ = g_opstate.ex040101_my_call[0];
  DAT_000014fd._1_1_ = g_opstate.ex040101_my_call[1];
  DAT_000014fd._2_1_ = g_opstate.ex040101_my_call[2];
  DAT_000014fd._3_1_ = g_opstate.ex040101_my_call[3];
  DAT_00001509 = g_opstate.auto_power_on;
  return;
}


// ===== displink_build_status @ fff96455 (2367 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96d91) */
/* WARNING: Removing unreachable block (ram,0xfff96bd9) */
/* WARNING: Removing unreachable block (ram,0xfff96645) */
/* WARNING: Removing unreachable block (ram,0xfff96c0b) */
/* WARNING: Removing unreachable block (ram,0xfff96cbc) */
/* WARNING: Removing unreachable block (ram,0xfff96d02) */
/* 0x97-byte status block at 0x16A1 (used by 0x20 and 0x60) */

ushort displink_build_status(void)

{
  uint uVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool local_a;
  byte local_9;
  short sStack_8;
  ushort local_6;
  
  local_9 = 0;
  local_a = g_opstate.active_vfo == 0;
  if (local_a) {
    DAT_00020874 = &g_opstate.vfo_a;
    PTR_g_ui_00025d38->f_0x40e_u8 = 0;
  }
  else {
    DAT_00020874 = &g_opstate.vfo_b;
    PTR_g_ui_00025d38->f_0x40e_u8 = 1;
  }
  local_a = !local_a;
  DAT_000016a1 = g_opstate.scope_flag_37;
  local_6 = 2;
  DAT_000016a2 = FUN_fff96dde();
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff96f3e();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff96fb7();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9700b();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97049();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97075();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff970b8();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97105();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9716f(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  (&DAT_000016a0)[(ushort)(local_6 + 1)] = g_opstate.meter_sel & 7;
  local_6 = local_6 + 2;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff971fc(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9728c(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97430();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97567();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff976d2();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9770b(local_a);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  iVar6 = FUN_fffc4f8f();
  if (iVar6 == 0) {
    (&DAT_000016a0)[local_6] = g_opstate.ss00_value << 4 | g_opstate.ss03_value & 0xf;
  }
  else {
    (&DAT_000016a0)[local_6] = g_opstate.ss03_value & 0x5f | 0x50;
  }
  local_6 = local_6 + 1;
  FUN_fff977b3(&DAT_000016a0 + local_6,DAT_00020874);
  local_6 = local_6 + 2;
  local_9 = DAT_00020874->mode & 0xf;
  if ((local_9 == 3) || (local_9 == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff9782b(&DAT_000016a0 + local_6);
  }
  local_6 = local_6 + 4;
  FUN_fff978eb(&DAT_000016a0 + local_6,DAT_00020874);
  if (g_opstate.ex030205_contour_level < 0) {
    (&DAT_000016a0)[local_6] = (&DAT_000016a0)[local_6] | 0x80;
  }
  local_6 = local_6 + 2;
  FUN_fff9795f(&DAT_000016a0 + local_6,DAT_00020874);
  local_6 = local_6 + 2;
  FUN_fff979d3(&DAT_000016a0 + local_6,DAT_00020874);
  local_6 = local_6 + 2;
  FUN_fff97a44(&DAT_000016a0 + local_6,DAT_00020874);
  (&DAT_000016a0)[(ushort)(local_6 + 2)] = g_opstate.apf_freq;
  (&DAT_000016a0)[(ushort)(local_6 + 3)] = g_opstate.cw_pitch + 0x1e;
  local_6 = local_6 + 4;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97abc(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97b7b();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  FUN_fff97ba6(&DAT_000016a0 + local_6);
  (&DAT_000016a0)[(ushort)(local_6 + 6)] = 0xff;
  uVar5 = local_6 + 7;
  if (PTR_g_ui_00025d38->txw_on == 1) {
    (&DAT_000016a0)[uVar5] = 0x2d;
    local_6 = local_6 + 8;
  }
  else {
    local_6 = uVar5;
    uVar3 = FUN_fff97c74();
    (&DAT_000016a0)[uVar5] = uVar3;
    local_6 = local_6 + 1;
  }
  DAT_0001b62a = local_6;
  (&DAT_000016a0)[local_6] = g_opstate.vfo_a.mode & 0xf;
  DAT_0001b62e = local_6 + 1;
  uVar1 = (uint)DAT_0001b62e;
  local_6 = DAT_0001b62e;
  bVar4 = FUN_fff97cf7('\0',&local_9);
  (&DAT_000016a0)[uVar1] = bVar4;
  (&DAT_000016a0)[(ushort)(local_6 + 1)] = local_9;
  local_6 = local_6 + 2;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97e1d(0);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  if (PTR_g_ui_00025d38->numentry_mode == 0) {
    DAT_000019c9 = 0;
    DAT_000019c5 = 0;
    FUN_fff982aa(0,0x19c5,local_6 + 0x169f);
    (&DAT_000016a4)[local_6] = DAT_000019c9;
    *(undefined4 *)(&DAT_000016a0 + local_6) = DAT_000019c5;
    uVar5 = local_6;
  }
  else {
    ui_numentry_to_bcd();
    local_9 = 5;
    pbVar8 = PTR_g_ui_00025d38->numentry_bcd;
    pbVar7 = &DAT_000016a0 + local_6;
    for (iVar6 = 5; uVar5 = local_6, iVar6 != 0; iVar6 = iVar6 + -1) {
      *pbVar7 = *pbVar8;
      pbVar7 = pbVar7 + 1;
      pbVar8 = pbVar8 + 1;
    }
  }
  local_6 = uVar5 + 5;
  uVar1 = (uint)local_6;
  *(undefined4 *)(&DAT_000016a8 + uVar1) = g_opstate.vfo_a.tag._8_4_;
  *(undefined4 *)(&DAT_000016a4 + uVar1) = g_opstate.vfo_a.tag._4_4_;
  *(undefined4 *)(&DAT_000016a0 + uVar1) = g_opstate.vfo_a.tag._0_4_;
  (&DAT_000016a0)[(ushort)(uVar5 + 0x11)] = PTR_g_ui_00025d38->clar_flags_a;
  (&DAT_000016a0)[(ushort)(uVar5 + 0x12)] = g_opstate.vfo_a.clar_offset_be[0];
  (&DAT_000016a0)[(ushort)(uVar5 + 0x13)] = g_opstate.vfo_a.clar_offset_be[1];
  DAT_0001b62c = uVar5 + 0x15;
  (&DAT_000016a0)[DAT_0001b62c] = g_opstate.vfo_b.mode & 0xf;
  DAT_0001b630 = uVar5 + 0x16;
  uVar1 = (uint)DAT_0001b630;
  local_6 = DAT_0001b630;
  bVar4 = FUN_fff97cf7('\x01',&local_9);
  (&DAT_000016a0)[uVar1] = bVar4;
  (&DAT_000016a0)[(ushort)(local_6 + 1)] = local_9;
  local_6 = local_6 + 2;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97e1d(1);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  DAT_000019c9 = 0;
  DAT_000019c5 = 0;
  FUN_fff982aa(1,0x19c5,local_6 + 0x169f);
  (&DAT_000016a4)[local_6] = DAT_000019c9;
  *(undefined4 *)(&DAT_000016a0 + local_6) = DAT_000019c5;
  uVar5 = local_6 + 5;
  *(undefined4 *)(&DAT_000016a8 + uVar5) = g_opstate.vfo_b.tag._8_4_;
  *(undefined4 *)(&DAT_000016a4 + uVar5) = g_opstate.vfo_b.tag._4_4_;
  *(undefined4 *)(&DAT_000016a0 + uVar5) = g_opstate.vfo_b.tag._0_4_;
  (&DAT_000016a0)[(ushort)(local_6 + 0x11)] = PTR_g_ui_00025d38->clar_flags_b;
  (&DAT_000016a0)[(ushort)(local_6 + 0x12)] = g_opstate.vfo_b.clar_offset_be[0];
  (&DAT_000016a0)[(ushort)(local_6 + 0x13)] = g_opstate.vfo_b.clar_offset_be[1];
  local_6 = local_6 + 0x15;
  if (g_opstate.active_vfo == 1) {
    DAT_00020878 = &DAT_000016a0 + DAT_0001b62a;
    DAT_0002087c = &DAT_000016a0 + DAT_0001b62c;
    for (sStack_8 = DAT_0001b62c - DAT_0001b62a; sStack_8 != 0; sStack_8 = sStack_8 + -1) {
      local_9 = *DAT_00020878;
      *DAT_00020878 = *DAT_0002087c;
      *DAT_0002087c = local_9;
      DAT_00020878 = DAT_00020878 + 1;
      DAT_0002087c = DAT_0002087c + 1;
    }
  }
  if (g_opstate.split_on == 1) {
    (&DAT_000016a0)[DAT_0001b62e] = 9;
    (&DAT_000016a0)[DAT_0001b630] = 10;
  }
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9849e();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff98526(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  (&DAT_000016a0)[(ushort)(local_6 + 7)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 8)] =
       g_opstate.ex010516_shift_frequency & 3 | g_opstate.ex010515_mark_frequency << 7;
  (&DAT_000016a0)[(ushort)(local_6 + 9)] = (g_opstate.ex010419_psk_tone & 3) << 4;
  (&DAT_000016a0)[(ushort)(local_6 + 10)] = g_opstate.key_speed;
  (&DAT_000016a0)[(ushort)(local_6 + 0xb)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0xc)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0xd)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0xe)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0xf)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0x10)] = 0;
  local_9 = g_opstate.osc_time & 7 | (g_opstate.ss07_affft_att & 3) << 5 | 0x18;
  (&DAT_000016a0)[(ushort)(local_6 + 0x11)] = local_9;
  sStack_8 = CONCAT11(g_opstate.ex010420_data_shift_ssb_be[0],
                      g_opstate.ex010420_data_shift_ssb_be[1]) * 10;
  (&DAT_000016a0)[(ushort)(local_6 + 0x13)] = (char)((ushort)sStack_8 >> 8);
  (&DAT_000016a0)[(ushort)(local_6 + 0x14)] = (char)sStack_8;
  local_6 = local_6 + 0x15;
  disp_put_op_freq(&DAT_000016a0 + local_6);
  local_6 = local_6 + 4;
  disp_put_tx_freq(&DAT_000016a0 + local_6);
  local_6 = local_6 + 4;
  disp_put_dial_freq(&DAT_000016a0 + local_6);
  local_6 = local_6 + 4;
  disp_put_scope_start((int)(&DAT_000016a0 + local_6));
  return local_6 + 0x17;
}


// ===== FUN_fff96d94 @ fff96d94 (74 bytes)

char FUN_fff96d94(byte param_1)

{
  byte bVar1;
  byte local_3;
  
  local_3 = g_qmb_hdr.count;
  if ((g_opstate.ex030112_qmb_ch == 0) && (4 < g_qmb_hdr.count)) {
    local_3 = 5;
  }
  bVar1 = param_1;
  if (param_1 < local_3) {
    bVar1 = local_3;
  }
  local_3 = bVar1;
  local_3 = local_3 - param_1;
  if (local_3 == '\0') {
    local_3 = '\x01';
  }
  return local_3;
}


// ===== FUN_fff96dde @ fff96dde (352 bytes)

undefined1 FUN_fff96dde(void)

{
  bool bVar1;
  undefined1 local_2;
  
  if (g_opstate.scope_3dss == 0) {
    if (g_opstate.scope_mode == 0) {
      if (g_opstate.wf_size == 0) {
        local_2 = 3;
      }
      else if (g_opstate.wf_size == 1) {
        local_2 = 4;
      }
      else {
        local_2 = 5;
      }
    }
    else {
      bVar1 = PTR_g_ui_00025d38->transmitting == 0;
      if (g_opstate.scope_mode == 1) {
        if (bVar1) {
          if (g_opstate.wf_size == 0) {
            local_2 = 6;
          }
          else if (g_opstate.wf_size == 1) {
            local_2 = 7;
          }
          else {
            local_2 = 8;
          }
        }
        else if (g_opstate.wf_size == 0) {
          local_2 = 3;
        }
        else if (g_opstate.wf_size == 1) {
          local_2 = 4;
        }
        else {
          local_2 = 5;
        }
      }
      else if (bVar1) {
        if (g_opstate.wf_size == 0) {
          local_2 = 9;
        }
        else if (g_opstate.wf_size == 1) {
          local_2 = 10;
        }
        else {
          local_2 = 0xb;
        }
      }
      else if (g_opstate.wf_size == 0) {
        local_2 = 3;
      }
      else if (g_opstate.wf_size == 1) {
        local_2 = 4;
      }
      else {
        local_2 = 5;
      }
    }
  }
  else if (g_opstate.scope_mode == 0) {
    local_2 = 0;
  }
  else {
    bVar1 = PTR_g_ui_00025d38->transmitting == 0;
    if (g_opstate.scope_mode == 1) {
      if (bVar1) {
        local_2 = 1;
      }
      else {
        local_2 = 0;
      }
    }
    else if (bVar1) {
      local_2 = 2;
    }
    else {
      local_2 = 0;
    }
  }
  return local_2;
}


// ===== FUN_fff96f3e @ fff96f3e (121 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96f69) */

byte FUN_fff96f3e(void)

{
  byte local_3;
  byte local_2;
  
  local_2 = g_opstate.active_vfo;
  if (PTR_g_ui_00025d38->txw_swap == 1) {
    if (g_opstate.active_vfo == 0) {
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  local_2 = local_2 << 7;
  if (g_opstate.active_vfo == 0) {
    local_3 = PTR_g_ui_00025d38->clar_flags_a;
  }
  else {
    local_3 = PTR_g_ui_00025d38->clar_flags_b;
  }
  if (g_opstate.split_on == 1) {
    local_2 = local_2 | 0x20;
  }
  else if (local_3 == 0) {
    local_2 = local_2 | 0x10;
  }
  else {
    local_2 = local_2 | 0x40;
  }
  return local_2;
}


// ===== FUN_fff96fb7 @ fff96fb7 (84 bytes)

undefined1 FUN_fff96fb7(void)

{
  bool bVar1;
  undefined1 local_2;
  
  local_2 = 0;
  if ((PTR_g_ui_00025d38->dl_req_37 == 1) || (PTR_g_ui_00025d38->memlist_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_g_ui_00025d38->dl_req_40 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_2 = 0x20;
  }
  return local_2;
}


// ===== FUN_fff9700b @ fff9700b (62 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97017) */
/* WARNING: Removing unreachable block (ram,0xfff97028) */

byte FUN_fff9700b(void)

{
  return g_opstate.split_on | (g_opstate.scope_expand & 1) << 5 | (g_opstate.preset_on & 1) << 6;
}


// ===== FUN_fff97049 @ fff97049 (44 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97055) */
/* WARNING: Removing unreachable block (ram,0xfff97063) */

byte FUN_fff97049(void)

{
  return (g_opstate.ex040204_3dss_disp_sensitivity & 1) << 6 |
         g_opstate.ex040203_2d_disp_sensitivity << 7;
}


// ===== FUN_fff97075 @ fff97075 (67 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97082) */
/* WARNING: Removing unreachable block (ram,0xfff97091) */
/* WARNING: Removing unreachable block (ram,0xfff970a6) */

byte FUN_fff97075(void)

{
  return (PTR_g_ui_00025d38->hi_swr & 3) << 4 |
         (PTR_g_ui_00025d38->status_bit_68 & 1) << 6 | PTR_g_ui_00025d38->transmitting << 7;
}


// ===== FUN_fff970b8 @ fff970b8 (77 bytes)

byte FUN_fff970b8(void)

{
  byte local_3;
  byte local_2;
  
  local_3 = PTR_g_ui_00025d38->lamp_map;
  if (PTR_g_ui_00025d38->numentry_mode == 0) {
    local_2 = g_opstate.ex040105_led_dimmer;
  }
  else {
    local_2 = PTR_g_ui_00025d38->svc_brightness;
  }
  if (local_2 == 0) {
    local_3 = local_3 & 0xf0;
  }
  return local_3;
}


// ===== FUN_fff97105 @ fff97105 (106 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97135) */
/* WARNING: Removing unreachable block (ram,0xfff97111) */
/* WARNING: Removing unreachable block (ram,0xfff97120) */
/* WARNING: Removing unreachable block (ram,0xfff9714a) */
/* WARNING: Removing unreachable block (ram,0xfff9715e) */

byte FUN_fff97105(void)

{
  return (g_opstate.toggle_9c5c & 1) << 3 |
         (PTR_g_ui_00025d38->f_0x06c_u8 & 1) << 4 |
         (PTR_g_ui_00025d38->freq_settled_b & 1) << 5 |
         (PTR_g_ui_00025d38->freq_settled_a & 1) << 6 | g_opstate.ss02_marker << 7;
}


// ===== FUN_fff9716f @ fff9716f (141 bytes)

byte FUN_fff9716f(byte *param_1)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 4 < 2) {
      local_6 = g_opstate.ex010213_tx_bpf_sel | 0x80;
      goto LAB_fff971e9;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 < 2) {
        local_6 = g_opstate.ex010113_tx_bpf_sel | 0x80;
      }
      else {
        local_6 = 0;
      }
      goto LAB_fff971e9;
    }
  }
  local_6 = g_opstate.ex010413_tx_bpf_sel | 0x80;
LAB_fff971e9:
  if ((local_6 & 0x7f) == 6) {
    local_6 = local_6 & 0x7f;
  }
  return local_6;
}


// ===== FUN_fff971fc @ fff971fc (144 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97257) */
/* WARNING: Removing unreachable block (ram,0xfff97270) */

byte FUN_fff971fc(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bStack_7;
  char cStack_6;
  
  bVar2 = mode_block_byte1();
  bVar3 = *param_1 & 0xf;
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cStack_6 = '\x02';
  }
  else if ((bVar2 & 0x80) == 0) {
    cStack_6 = '\0';
  }
  else {
    cStack_6 = '\x01';
  }
  if ((param_1[5] & 3) == 0) {
    bStack_7 = 0;
  }
  else {
    bStack_7 = (param_1[5] & 3) - 1;
  }
  return param_1[3] & 3 | (bStack_7 & 3) << 2 | cStack_6 << 4;
}


// ===== FUN_fff9728c @ fff9728c (304 bytes)

byte FUN_fff9728c(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bStack_9;
  byte local_6;
  
  local_6 = 0;
  bVar3 = *param_1 & 0xf;
  if (g_opstate.ex020120_cw_indicator == 1) {
    if ((bVar3 == 3) || (bVar3 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fff972c7;
    }
  }
  bVar1 = false;
LAB_fff972c7:
  if (bVar1) {
    local_6 = 0x80;
  }
  if ((bVar3 == 3) || (bVar3 == 2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && ((param_1[0x14] & 0x20) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | 0x40;
  }
  bVar2 = mode_block_byte0(param_1);
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (bVar3 != 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar3 != 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | (byte)((bVar2 & 0x40) >> 1);
  }
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (bVar3 != 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar3 != 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | (byte)((bVar2 & 0x80) >> 3);
  }
  bVar3 = mode_block_byte1(param_1);
  if ((bVar3 & 0x40) == 0) {
    bStack_9 = 0;
  }
  else {
    bStack_9 = (bVar3 >> 4 & 3) + 1;
  }
  return local_6 | bStack_9;
}


// ===== mode_block_byte0 @ fff973bc (116 bytes)

/* active mode's per-mode block byte +0 (NOTCH/CONTOUR/APF/BI flags) (#179) */

byte mode_block_byte0(byte *param_1)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = *param_1 & 0xf;
  if (uVar1 == 0xe) {
LAB_fff97422:
    local_6 = param_1[0x28];
  }
  else {
    if (uVar1 - 2 < 2) {
      return param_1[0x14];
    }
    if (uVar1 - 4 < 2) {
      return param_1[0x32];
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97422;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return param_1[0x1e];
        }
        if ((*param_1 & 0xf) != 0 && uVar1 != 1) {
          return 0;
        }
        return param_1[10];
      }
    }
    local_6 = param_1[0x3c];
  }
  return local_6;
}


// ===== FUN_fff97430 @ fff97430 (251 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97487) */
/* WARNING: Removing unreachable block (ram,0xfff97454) */
/* WARNING: Removing unreachable block (ram,0xfff974b0) */
/* WARNING: Removing unreachable block (ram,0xfff974ce) */

byte FUN_fff97430(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  vfo_rec *pvVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  byte bStack_a;
  char cStack_9;
  
  pvVar5 = vfo_rec_ptr(VFO_TX);
  bVar3 = pvVar5->mode & 0xf;
  iVar6 = FUN_fff9752b(pvVar5);
  iVar7 = keyer_mode_class(pvVar5);
  if ((iVar7 == 0) || (g_opstate.keyer_on != 1)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  pcVar8 = (char *)FUN_fff99669();
  if (pcVar8 == (char *)0x0) {
    cStack_9 = '\0';
  }
  else if (*pcVar8 == '\0') {
    cStack_9 = '\0';
  }
  else {
    cStack_9 = '\x01';
  }
  bVar4 = mode_block_byte0(pvVar5);
  bStack_a = ((bVar4 & 2) != 0) << 2 | cStack_9 << 4 | cVar2 << 5 | (iVar6 != 0) << 6;
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_a = bStack_a | (pvVar5->flags2 >> 2 & 3) + 1;
  }
  return bStack_a;
}


// ===== FUN_fff9752b @ fff9752b (60 bytes)

undefined1 FUN_fff9752b(byte *param_1)

{
  bool bVar1;
  undefined1 local_7;
  
  local_7 = 0;
  if (((*param_1 & 0xf) == 0) || ((*param_1 & 0xf) == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (g_opstate.proc_level != 0)) {
    local_7 = 1;
  }
  return local_7;
}


// ===== FUN_fff97567 @ fff97567 (363 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9769f) */
/* WARNING: Removing unreachable block (ram,0xfff976ae) */

byte FUN_fff97567(void)

{
  bool bVar1;
  char local_3;
  
  if ((PTR_g_ui_00025d38->msg_rec_active == 1) || (PTR_g_ui_00025d38->dvs_state == 2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_3 = '\x01';
  }
  else {
    if ((PTR_g_ui_00025d38->dvs_busy == 1) && (PTR_g_ui_00025d38->kbd_show_cursor_char == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_3 = '\x01';
    }
    else {
      if ((PTR_g_ui_00025d38->dvs_busy == 1) && (PTR_g_ui_00025d38->kbd_show_cursor_char == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        local_3 = '\0';
      }
      else {
        if ((PTR_g_ui_00025d38->ky_send_0 == 1) || (PTR_g_ui_00025d38->ky_send_1 == 1)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if ((bVar1) || (PTR_g_ui_00025d38->dvs_state == 1)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          local_3 = '\x02';
        }
        else {
          if ((PTR_g_ui_00025d38->dvs_lm1_flag == 1) &&
             (PTR_g_ui_00025d38->kbd_show_cursor_char == 1)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            local_3 = '\x03';
          }
          else {
            local_3 = '\0';
          }
        }
      }
    }
  }
  return PTR_g_ui_00025d38->fm_tone_mode & 3 |
         (PTR_g_ui_00025d38->tuner_indicator & 3) << 3 | local_3 << 6;
}


// ===== FUN_fff976d2 @ fff976d2 (57 bytes)

/* WARNING: Removing unreachable block (ram,0xfff976ee) */

byte FUN_fff976d2(void)

{
  byte bVar1;
  byte bStack_2;
  
  bVar1 = swtimer_expired(0x2a);
  if (bVar1 == 0) {
    bStack_2 = 0x40;
  }
  else {
    bStack_2 = PTR_g_ui_00025d38->status_bit_6f << 4;
  }
  return g_opstate.ss01_peak & 7 | bStack_2;
}


// ===== FUN_fff9770b @ fff9770b (36 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97719) */

byte FUN_fff9770b(byte param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = g_opstate.scope_mode << 6;
  bVar2 = scope_span_index(param_1);
  return bVar2 | bVar1;
}


// ===== scope_span_index @ fff9772f (85 bytes)

/* Index into span table 0xFFF89D24 */

byte scope_span_index(byte param_1)

{
  byte bVar1;
  uint freq;
  byte bStack_9;
  
  freq = vfo_freq_clar(VFO_RX,param_1);
  bVar1 = freq_range_index(freq);
  if (bVar1 == 0xff) {
    bStack_9 = 0;
  }
  else if (g_opstate.scope_mode == 2) {
    bStack_9 = g_opstate.scope_span_idx_b[bVar1];
  }
  else {
    bStack_9 = g_opstate.scope_span_idx_a[bVar1];
  }
  return bStack_9;
}


// ===== range_cmp3 @ fff97784 (47 bytes)

/* 0 if v<lo, 1 if v>hi, else 2 */

byte range_cmp3(uint *v,uint *range)

{
  byte local_a;
  
  if (*v < *range) {
    local_a = 0;
  }
  else if (range[1] < *v) {
    local_a = 1;
  }
  else {
    local_a = 2;
  }
  return local_a;
}


// ===== FUN_fff977b3 @ fff977b3 (120 bytes)

void FUN_fff977b3(undefined1 *param_1,byte *param_2)

{
  uint uVar1;
  undefined2 local_a;
  
  local_a = 0;
  uVar1 = *param_2 & 0xf;
  if (uVar1 == 0xe) {
LAB_fff97816:
    local_a = 0xc80;
  }
  else {
    if (uVar1 - 2 < 2) {
      local_a = 500;
      goto LAB_fff9781b;
    }
    if (uVar1 - 4 < 2) {
      local_a = 9000;
      goto LAB_fff9781b;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97816;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          local_a = 500;
        }
        else if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          local_a = 3000;
        }
        goto LAB_fff9781b;
      }
    }
    local_a = 16000;
  }
LAB_fff9781b:
  *param_1 = (char)((ushort)local_a >> 8);
  param_1[1] = (char)local_a;
  return;
}


// ===== FUN_fff9782b @ fff9782b (192 bytes)

void FUN_fff9782b(void *param_1)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x28);
  if (bVar1 == 1) {
    swtimer_start(0x28,100);
    if (PTR_g_ui_00025d38->transmitting == 1) {
      DAT_0001ff1a = 0;
    }
    else {
      DAT_0001ff1a = dsp_tune_offset();
    }
    if ((short)DAT_0001ff1a < -99) {
      DAT_0001ff1a = 0xff9d;
    }
    else if (99 < (short)DAT_0001ff1a) {
      DAT_0001ff1a = 99;
    }
    DAT_0001ff1a = DAT_0001ff1a + 0xc;
    if ((short)DAT_0001ff1a < 0x19) {
      if ((short)DAT_0001ff1a < 0) {
        DAT_0001ff1a = 0;
      }
    }
    else {
      DAT_0001ff1a = 0;
    }
  }
  *(undefined4 *)param_1 = (&DAT_fff804de)[(short)DAT_0001ff1a];
  return;
}


// ===== FUN_fff978eb @ fff978eb (116 bytes)

void FUN_fff978eb(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2 & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x16);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x34);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97954;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x20);
          return;
        }
        if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          *param_1 = *(undefined2 *)(param_2 + 0xc);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x3e);
    return;
  }
LAB_fff97954:
  *param_1 = *(undefined2 *)(param_2 + 0x2a);
  return;
}


// ===== FUN_fff9795f @ fff9795f (116 bytes)

void FUN_fff9795f(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2 & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x18);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x36);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff979c8;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x22);
          return;
        }
        if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          *param_1 = *(undefined2 *)(param_2 + 0xe);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x40);
    return;
  }
LAB_fff979c8:
  *param_1 = *(undefined2 *)(param_2 + 0x2c);
  return;
}


// ===== FUN_fff979d3 @ fff979d3 (113 bytes)

void FUN_fff979d3(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  undefined2 uStack_a;
  byte *local_8;
  undefined2 *local_4;
  
  uVar1 = (uint)(*param_2 & 0xf);
  if (3 < uVar1) {
    if (uVar1 == 4) {
      *param_1 = *(undefined2 *)(param_2 + 0x38);
      return;
    }
    if (uVar1 == 5) {
      *(undefined1 *)param_1 = 0x17;
      *(undefined1 *)((int)param_1 + 1) = 0x70;
      return;
    }
    if (uVar1 == 6) {
LAB_fff97a2d:
      *param_1 = *(undefined2 *)(param_2 + 0x42);
      return;
    }
    if (uVar1 == 7) {
LAB_fff97a36:
      *(undefined1 *)param_1 = 0x3e;
      *(undefined1 *)((int)param_1 + 1) = 0x80;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 == 10) goto LAB_fff97a2d;
      if (uVar1 == 0xb) goto LAB_fff97a36;
      if (2 < uVar1 - 0xc) {
        return;
      }
    }
  }
  local_8 = param_2;
  local_4 = param_1;
  vfo_filter_width_hz(&uStack_a);
  *local_4 = uStack_a;
  return;
}


// ===== FUN_fff97a44 @ fff97a44 (120 bytes)

void FUN_fff97a44(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(*param_2 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x1c);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x3a);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97ab1;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x26);
          return;
        }
        if (uVar1 < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x12);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x44);
    return;
  }
LAB_fff97ab1:
  *param_1 = *(undefined2 *)(param_2 + 0x30);
  return;
}


// ===== FUN_fff97abc @ fff97abc (191 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97af2) */
/* WARNING: Removing unreachable block (ram,0xfff97b1d) */

byte FUN_fff97abc(undefined4 param_1)

{
  int iVar1;
  undefined2 uStack_a;
  undefined1 auStack_8 [2];
  byte local_6;
  undefined4 local_4;
  
  if (PTR_g_ui_00025d38->func_panel_open == 0) {
    PTR_g_ui_00025d38->f_0x071_u8 = 1;
    PTR_g_ui_00025d38->f_0x072_u8 = 0;
  }
  local_6 = PTR_g_ui_00025d38->func_panel_open << 7;
  if (PTR_g_ui_00025d38->f_0x071_u8 != 0) {
    local_6 = local_6 | 0x40;
  }
  local_6 = PTR_g_ui_00025d38->dsp_knob_func | PTR_g_ui_00025d38->f_0x47a_u8 << 2 | local_6;
  local_4 = param_1;
  FUN_fff979d3(auStack_8,param_1);
  FUN_fff977b3(&uStack_a,local_4);
  iVar1 = strncmp(auStack_8,&uStack_a,2);
  if (iVar1 != 0) {
    local_6 = local_6 | 0x10;
  }
  FUN_fff97a44(auStack_8,local_4);
  uStack_a = 0;
  iVar1 = strncmp(auStack_8,&uStack_a,2);
  if (iVar1 != 0) {
    local_6 = local_6 | 0x20;
  }
  return local_6;
}


// ===== FUN_fff97b7b @ fff97b7b (43 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97b88) */

byte FUN_fff97b7b(void)

{
  return PTR_g_ui_00025d38->dvs_slot & 0xf | PTR_g_ui_00025d38->dvs_state << 4;
}


// ===== FUN_fff97ba6 @ fff97ba6 (206 bytes)

void FUN_fff97ba6(void *param_1)

{
  if (PTR_g_ui_00025d38->scope_skip != 1) {
    if (PTR_g_ui_00025d38->transmitting == 1) {
      *(undefined1 *)param_1 = 0;
    }
    else if (g_opstate.scope_mode == 0) {
      *(undefined1 *)param_1 = 0;
    }
    else if (g_opstate.scope_mode == 1) {
      *(undefined1 *)param_1 = 1;
    }
    else {
      *(undefined1 *)param_1 = 2;
    }
    if (g_opstate.scope_3dss == 1) {
      *(undefined1 *)((int)param_1 + 1) = 0x84;
    }
    else {
      *(undefined1 *)((int)param_1 + 1) = 3;
    }
    if (g_opstate.scope_flag_37 == 1) {
      *(undefined1 *)((int)param_1 + 2) = 0x86;
    }
    else {
      *(undefined1 *)((int)param_1 + 2) = 5;
    }
    if (g_opstate.scope_expand == 1) {
      *(undefined1 *)((int)param_1 + 3) = 0x88;
    }
    else {
      *(undefined1 *)((int)param_1 + 3) = 7;
    }
    *(undefined1 *)((int)param_1 + 4) = 9;
    *(undefined1 *)((int)param_1 + 5) = 10;
    return;
  }
  *(undefined2 *)((int)param_1 + 4) = 0x7f7f;
  *(undefined4 *)param_1 = 0x7f7f0c0b;
  return;
}


// ===== FUN_fff97c74 @ fff97c74 (131 bytes)

byte FUN_fff97c74(void)

{
  byte bVar1;
  byte local_2;
  
  if (PTR_g_ui_00025d38->dl_req_popup_b == 0) {
    local_2 = g_opstate.func_knob;
  }
  else {
    bVar1 = PTR_g_ui_00025d38->popup_code;
    if (bVar1 == 0xb) {
      local_2 = 3;
    }
    else if (bVar1 == 0x26) {
      local_2 = 8;
    }
    else if (bVar1 == 0x2f) {
      local_2 = 0x11;
    }
    else if (bVar1 == 0x54) {
      local_2 = 0x36;
    }
    else if (bVar1 == 0x39) {
      local_2 = 0x1b;
    }
    else if (bVar1 == 0x46) {
      local_2 = 0x10;
    }
    else if (bVar1 == 0x38) {
      local_2 = 0x1a;
    }
    else {
      local_2 = g_opstate.func_knob;
    }
  }
  return local_2;
}


// ===== FUN_fff97cf7 @ fff97cf7 (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97e1a) */

byte FUN_fff97cf7(char param_1,byte *param_2)

{
  char cVar1;
  byte local_11;
  byte local_10;
  byte local_f;
  byte local_e;
  
  if (PTR_g_ui_00025d38->txw_swap == 0) {
    if (param_1 == '\0') {
      *param_2 = g_mem_hdr.chan_a;
      local_f = g_opstate.vfo_state_a;
      local_10 = g_qmb_hdr.ptr_a[0];
    }
    else {
      *param_2 = g_mem_hdr.chan_b;
      local_f = g_opstate.vfo_state_b;
      local_10 = g_qmb_hdr.ptr_b[0];
    }
  }
  else if (param_1 == '\0') {
    *param_2 = g_mem_hdr.chan_b;
    local_f = g_opstate.vfo_state_b;
    local_10 = g_qmb_hdr.ptr_b[0];
  }
  else {
    *param_2 = g_mem_hdr.chan_a;
    local_f = g_opstate.vfo_state_a;
    local_10 = g_qmb_hdr.ptr_a[0];
  }
  if (local_f == 5) {
    cVar1 = FUN_fff96d94(local_10);
    *param_2 = cVar1 - 0x39;
    local_11 = 5;
  }
  else if (local_f == 2) {
    if (*param_2 < 0x84) {
      if (*param_2 < 0x75) {
        local_e = 2;
      }
      else {
        *param_2 = *param_2 + 0x21;
        local_e = 7;
      }
    }
    else {
      *param_2 = 199;
      local_e = 8;
    }
    local_11 = local_e;
  }
  else if (local_f == 3) {
    local_11 = 3;
  }
  else if (local_f == 4) {
    local_11 = 4;
  }
  else if (local_f == 0) {
    local_11 = 0;
  }
  else {
    local_11 = 1;
  }
  return local_11;
}


// ===== FUN_fff97e1d @ fff97e1d (162 bytes)

byte FUN_fff97e1d(byte param_1)

{
  int iVar1;
  byte local_3;
  
  local_3 = 0;
  if (PTR_g_ui_00025d38->f_0x40d_u8 == 0) {
    if (param_1 == g_opstate.active_vfo) {
      iVar1 = FUN_fff9847e();
      if (iVar1 == 0) {
        local_3 = 0x20;
      }
      local_3 = FUN_fff97ebf(param_1,local_3);
    }
    else {
      if (PTR_g_ui_00025d38->f_0x41d_u8 == 0) {
        local_3 = 0x20;
      }
      local_3 = FUN_fff97ebf(param_1,local_3);
    }
  }
  else if (param_1 == PTR_g_ui_00025d38->f_0x40e_u8) {
    local_3 = FUN_fff97ebf(param_1,0);
  }
  else if (param_1 == g_opstate.active_vfo) {
    iVar1 = FUN_fff9847e();
    if (iVar1 == 0) {
      local_3 = 0x20;
    }
    local_3 = FUN_fff97ebf(param_1,local_3);
  }
  else {
    local_3 = FUN_fff97ebf(param_1,0x20);
  }
  return local_3;
}


// ===== FUN_fff97ebf @ fff97ebf (591 bytes)

byte FUN_fff97ebf(char param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  undefined1 uStack_a;
  char cStack_9;
  byte bStack_5;
  byte local_4;
  byte local_2;
  vfo_side local_1;
  
  bVar2 = param_2 & 0xf0;
  local_4 = bVar2 | 0xd4;
  if (g_opstate.split_on == 0) {
    if (g_opstate.active_vfo == 0) {
      if (param_1 == '\x01') {
        local_4 = bVar2 | 0xd7;
      }
    }
    else if (param_1 == '\0') {
      local_4 = bVar2 | 0xd7;
    }
  }
  local_2 = param_2;
  local_1 = param_1;
  if (PTR_g_ui_00025d38->scan_running == 1) {
    if ((g_opstate.active_vfo == param_1) && (PTR_g_ui_00025d38->scan_hold == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (PTR_g_ui_00025d38->kbd_show_cursor_char == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_4 = local_4 & 0x3f;
    }
  }
  else {
    FUN_fff9810e(param_1,(uint)&uStack_a);
    if (cStack_9 == '\0') {
      local_4 = local_4 & 0x7f;
    }
    if (g_opstate.split_on == 1) {
      bVar1 = PTR_g_ui_00025d38->f_0x482_u8 != 0;
      if (g_opstate.active_vfo == 0) {
        if ((bVar1) || (local_1 != VFO_B)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_4 = local_4 & 0xf0 | 5;
        }
        if ((PTR_g_ui_00025d38->f_0x482_u8 == 1) && (local_1 == VFO_A)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          local_4 = local_4 & 0xf0 | 6;
        }
      }
      else {
        if ((bVar1) || (local_1 != VFO_A)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_4 = local_4 & 0xf0 | 5;
        }
        if ((PTR_g_ui_00025d38->f_0x482_u8 == 1) && (local_1 == VFO_B)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          local_4 = local_4 & 0xf0 | 6;
        }
      }
    }
    if (g_opstate.active_vfo == 0) {
      if ((PTR_g_ui_00025d38->clar_flags_a != 0) && (local_1 == VFO_B)) {
        local_4 = local_4 & 0xf0 | 9;
      }
    }
    else if ((PTR_g_ui_00025d38->clar_flags_b != 0) && (local_1 == VFO_A)) {
      local_4 = local_4 & 0xf0 | 9;
    }
  }
  if (local_1 == VFO_A) {
    bStack_5 = g_opstate.vfo_a.flags5;
  }
  else {
    bStack_5 = g_opstate.vfo_b.flags5;
  }
  bVar2 = vfo_is_memory(local_1);
  if ((bVar2 == 1) && ((bStack_5 & 0x80) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_4 = local_4 & 0xf0 | 1;
  }
  return local_4;
}


// ===== FUN_fff9810e @ fff9810e (172 bytes)

void FUN_fff9810e(char param_1,uint param_2)

{
  byte local_d;
  int local_c;
  
  if (param_1 == '\0') {
    local_c = 0x9d09;
    local_d = PTR_g_ui_00025d38->clar_flags_a;
  }
  else {
    local_c = 0x9d63;
    local_d = PTR_g_ui_00025d38->clar_flags_b;
  }
  if (g_ui.tx_lamp == 0) {
    FUN_fff981ba(param_1,local_c,local_d,param_2);
    return;
  }
  if (param_1 == g_opstate.active_vfo) {
    if (g_opstate.split_on != 1) {
      FUN_fff98258(param_1,local_c,local_d,param_2);
      return;
    }
    FUN_fff981ba(param_1,local_c,local_d,param_2);
    return;
  }
  if (g_opstate.split_on != 1) {
    FUN_fff981ba(param_1,local_c,local_d,param_2);
    return;
  }
  FUN_fff98258(param_1,local_c,local_d,param_2);
  return;
}

