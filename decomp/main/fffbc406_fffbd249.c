// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== key_call_repeat @ fffbc406 (47 bytes)

/* JSR key_repeat_table[code] */

void key_call_repeat(void)

{
  char cVar1;
  
  cVar1 = key_dest_allowed(DAT_0001fa40,0);
  if (cVar1 == '\0') {
    return;
  }
  (*(code *)(&key_repeat_table)[DAT_0001fa40])();
  return;
}


// ===== key_call_release @ fffbc435 (47 bytes)

/* JSR key_release_table[code] */

void key_call_release(void)

{
  char cVar1;
  
  cVar1 = key_dest_allowed(DAT_0001fa40,0);
  if (cVar1 == '\0') {
    return;
  }
  (*(code *)(&key_release_table)[DAT_0001fa40])();
  return;
}


// ===== key_touch_scope_tune @ fffbc464 (405 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbc507) */
/* WARNING: Removing unreachable block (ram,0xfffbc500) */
/* WARNING: Removing unreachable block (ram,0xfffbc55d) */
/* Touch (source 4) x position (0..0x316) -> VFO frequency in the scope span */

void key_touch_scope_tune(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  void *pvVar4;
  bool bStack_15;
  uint uStack_10;
  int iStack_8;
  
  iVar3 = FUN_fffc8ca8();
  if (iVar3 == 1) {
    if (PTR_g_ui_00025d54->popup_code == 8) {
      popup8_close();
      return;
    }
    popup_close();
    return;
  }
  iVar3 = FUN_fffc90ed();
  if (iVar3 != 1) {
    menu_close_if_open();
    func_panel_close();
    ui_clear_415_423();
    if (PTR_g_ui_00025d54->scan_running == 1) {
      scan_stop();
    }
    if (g_opstate.active_vfo == 0) {
      iStack_8 = 0x9d09;
    }
    else {
      iStack_8 = 0x9d63;
    }
    bStack_15 = g_opstate.active_vfo != 0;
    bVar2 = scope_span_index(bStack_15);
    uVar1 = *(uint *)(scope_span_table + (uint)bVar2 * 4);
    if (g_opstate.scope_mode == 0) {
      uStack_10 = ((uint)*(byte *)(iStack_8 + 0x4a) << 0x18 |
                   (uint)*(byte *)(iStack_8 + 0x4b) << 0x10 | (uint)*(byte *)(iStack_8 + 0x4c) << 8
                  | (uint)*(byte *)(iStack_8 + 0x4d)) - (uVar1 >> 1);
    }
    else if (g_opstate.scope_mode == 1) {
      uStack_10 = g_ui.scope_cursor_start;
    }
    else {
      uStack_10 = bandmem_get('\x02');
    }
    if (param_1 < 0x317) {
      pvVar4 = (void *)((uVar1 * param_1) / 0x316 + uStack_10);
      bVar2 = freq_in_range(pvVar4);
      if (bVar2 != 0) {
        *(char *)(iStack_8 + 0x4a) = (char)((uint)pvVar4 >> 0x18);
        *(char *)(iStack_8 + 0x4b) = (char)((uint)pvVar4 >> 0x10);
        *(char *)(iStack_8 + 0x4c) = (char)((uint)pvVar4 >> 8);
        uStack_10._0_1_ = SUB41(pvVar4,0);
        *(undefined1 *)(iStack_8 + 0x4d) = (undefined1)uStack_10;
        vfo_store_back(g_opstate.active_vfo);
        bVar2 = vfo_is_memory(g_opstate.active_vfo);
        if (bVar2 == 1) {
          if (g_opstate.active_vfo == 0) {
            g_opstate.vfo_state_a = 3;
          }
          else {
            g_opstate.vfo_state_b = 3;
          }
        }
        PTR_g_ui_00025d54->freq_refresh_req = 1;
        beep_request(1);
        return;
      }
      beep_request(3);
      return;
    }
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffbc5f9 @ fffbc5f9 (4 bytes)

void FUN_fffbc5f9(void)

{
  FUN_fffbc605();
  return;
}


// ===== FUN_fffbc5fd @ fffbc5fd (4 bytes)

void FUN_fffbc5fd(void)

{
  FUN_fffbc605();
  return;
}


// ===== FUN_fffbc601 @ fffbc601 (4 bytes)

void FUN_fffbc601(void)

{
  FUN_fffbc605();
  return;
}


// ===== FUN_fffbc605 @ fffbc605 (51 bytes)

void FUN_fffbc605(void)

{
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running != 1) {
    FUN_fffbc65b();
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== menu_close_if_open @ fffbc638 (35 bytes)

/* menu_screen_close when UI +0x95 (menu screen, frame 0x40) is set; returns whether it was open
   [fact] */

bool menu_close_if_open(void)

{
  bool bVar1;
  
  bVar1 = PTR_g_ui_00025d54->dl_req_40 != 0;
  if (bVar1) {
    menu_screen_close();
  }
  return bVar1;
}


// ===== FUN_fffbc65b @ fffbc65b (28 bytes)

void FUN_fffbc65b(void)

{
  popup_close();
  beep_request(1);
  if (g_opstate.scope_mode == 2) {
    return;
  }
  FUN_fffbc677();
  return;
}


// ===== FUN_fffbc677 @ fffbc677 (114 bytes)

void FUN_fffbc677(void)

{
  PTR_g_ui_00025d54->key_consumed = 1;
  if (g_opstate.scope_mode == 2) {
    g_opstate.scope_mode = 0;
    PTR_g_ui_00025d54->freq_refresh_req = 1;
    return;
  }
  if (g_opstate.scope_mode == 1) {
    g_opstate.scope_mode = 2;
    PTR_g_ui_00025d54->freq_refresh_req = 1;
    return;
  }
  if (g_opstate.scope_mode != 0) {
    return;
  }
  scope_cursor_center();
  g_opstate.scope_mode = 1;
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  return;
}


// ===== scope_cursor_center @ fffbc6e9 (149 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbc778) */
/* WARNING: Removing unreachable block (ram,0xfffbc77b) */
/* CURSOR start = dial - span/2 */

void scope_cursor_center(void)

{
  band_idx bVar1;
  byte bVar2;
  bool local_b;
  byte bStack_a;
  uint local_8;
  
  if (g_opstate.active_vfo == 0) {
    local_8 = PTR_g_ui_00025d54->freq_a;
  }
  else {
    local_8 = PTR_g_ui_00025d54->freq_b;
  }
  local_b = g_opstate.active_vfo != 0;
  bVar1 = band_of_freq(local_8);
  if (bVar1 == BAND_NONE) {
    return;
  }
  bVar2 = scope_span_index(local_b);
  local_8 = local_8 - (*(uint *)(scope_span_table + (uint)bVar2 * 4) >> 1);
  PTR_g_ui_00025d54->scope_cursor_start = local_8;
  for (bStack_a = 0; bStack_a < 4; bStack_a = bStack_a + 1) {
    g_opstate.scope_cursor_start_be[bStack_a] = (byte)(local_8 >> ((3 - bStack_a & 3) << 3));
  }
  bandmem_set('\x01',local_8);
  return;
}


// ===== FUN_fffbc77e @ fffbc77e (4 bytes)

void FUN_fffbc77e(void)

{
  FUN_fffbc677();
  return;
}


// ===== FUN_fffbc782 @ fffbc782 (192 bytes)

void FUN_fffbc782(void)

{
  bool bVar1;
  ui_state *puVar2;
  
  if (PTR_g_ui_00025d54->f_0x46b_u8 == 1) {
    beep_request(1);
    return;
  }
  if (g_opstate.split_on != 1) {
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 8)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup8_close();
    }
    else {
      ui_clear_415_423();
      puVar2 = PTR_g_ui_00025d54;
      PTR_g_ui_00025d54->f_0x413_u8 = 0xff;
      puVar2->f_0x40f_u8 = 0xff;
      puVar2->f_0x410_u8 = 0xff;
      puVar2->f_0x411_u8 = 0xff;
      puVar2->f_0x412_u8 = 0xff;
      PTR_g_ui_00025d54->f_0x40d_u8 = 1;
      FUN_fffe1e70();
      PTR_g_ui_00025d54->f_0x468_u8 = 0;
      PTR_g_ui_00025d54->f_0x414_u8 = 1;
      popup_duration_get(8);
      popup_open_timed();
      PTR_g_ui_00025d54->popup_code = 8;
    }
    beep_request(2);
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbc842 @ fffbc842 (108 bytes)

void FUN_fffbc842(void)

{
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  if (g_opstate.scope_3dss != 0) {
    g_opstate.scope_3dss = 0;
    return;
  }
  g_opstate.scope_3dss = 1;
  return;
}


// ===== FUN_fffbc8ae @ fffbc8ae (108 bytes)

void FUN_fffbc8ae(void)

{
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  if (g_opstate.scope_flag_37 != 0) {
    g_opstate.scope_flag_37 = 0;
    return;
  }
  g_opstate.scope_flag_37 = 1;
  return;
}


// ===== FUN_fffbc91a @ fffbc91a (130 bytes)

void FUN_fffbc91a(void)

{
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  if (g_opstate.scope_expand != 0) {
    g_opstate.scope_expand = 0;
    g_opstate.wf_size = 1;
    return;
  }
  g_opstate.scope_expand = 1;
  g_opstate.wf_size = 2;
  return;
}


// ===== FUN_fffbc99c @ fffbc99c (143 bytes)

void FUN_fffbc99c(void)

{
  bool bVar1;
  
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 6)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
    return;
  }
  popup_duration_get(6);
  popup_open_timed();
  PTR_g_ui_00025d54->popup_code = 6;
  return;
}


// ===== FUN_fffbca2b @ fffbca2b (143 bytes)

void FUN_fffbca2b(void)

{
  bool bVar1;
  
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 0xd)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
    return;
  }
  popup_duration_get(0xd);
  popup_open_timed();
  PTR_g_ui_00025d54->popup_code = 0xd;
  return;
}


// ===== FUN_fffbcaba @ fffbcaba (95 bytes)

void FUN_fffbcaba(void)

{
  bool bVar1;
  
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
  }
  else {
    popup_duration_get(0);
    popup_open_timed();
    PTR_g_ui_00025d54->popup_code = 0;
  }
  beep_request(1);
  return;
}


// ===== key_011_press @ fffbcb19 (94 bytes)

/* Soft key 0x011 press: error beep 3 and +0x409 (short skipped) while UI +0x97 or mode 6/7/0xA/0xB,
   else beep 1 [fact] (#179) */

void key_011_press(void)

{
  bool bVar1;
  radio_mode rVar2;
  uint uVar3;
  
  bVar1 = false;
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->memlist_open == 1) {
    bVar1 = true;
  }
  else {
    rVar2 = vfo_mode(VFO_RX);
    uVar3 = (uint)rVar2;
    if ((uVar3 - 6 < 2) || (uVar3 == 10 || uVar3 == 0xb)) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    beep_request(3);
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  beep_request(1);
  return;
}


// ===== key_011_short @ fffbcb77 (70 bytes)

/* Soft key 0x011 short: toggle UI +0x70 (on: FUN_fffc8beb, timer 0x44 = 2000) unless UI +0x97
   [fact] (#179) */

void key_011_short(void)

{
  if (PTR_g_ui_00025d54->memlist_open != 1) {
    if (PTR_g_ui_00025d54->func_panel_open == 1) {
      PTR_g_ui_00025d54->func_panel_open = 0;
    }
    else {
      PTR_g_ui_00025d54->func_panel_open = 1;
    }
    if (PTR_g_ui_00025d54->func_panel_open == 1) {
      popup_close();
      swtimer_start(0x44,2000);
      return;
    }
  }
  return;
}


// ===== key_011_long @ fffbcbbd (45 bytes)

/* Soft key 0x011 long (key_long_table 0xFFF8B8D0): toggle 0x9C5C = status byte 9 bit 3, beep 2
   [fact]; DISPLAY AF-FFT overlay in the filter graph [inference] (#179) */

void key_011_long(void)

{
  g_opstate.toggle_9c5c = g_opstate.toggle_9c5c != 1;
  beep_request(2);
  return;
}


// ===== FUN_fffbcbea @ fffbcbea (133 bytes)

void FUN_fffbcbea(void)

{
  menu_close_if_open();
  func_panel_close();
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (g_opstate.split_on == 1) {
    beep_request(1);
    return;
  }
  PTR_g_ui_00025d54->f_0x416_u8 = 0;
  if (PTR_g_ui_00025d54->f_0x415_u8 == 0) {
    PTR_g_ui_00025d54->f_0x415_u8 = 1;
  }
  else {
    ui_clear_415_423();
  }
  if (PTR_g_ui_00025d54->f_0x415_u8 == 1) {
    FUN_fffc8ebc();
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbcc6f @ fffbcc6f (133 bytes)

void FUN_fffbcc6f(void)

{
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  menu_close_if_open();
  func_panel_close();
  if (g_opstate.split_on == 1) {
    beep_request(1);
    return;
  }
  PTR_g_ui_00025d54->f_0x416_u8 = 1;
  if (PTR_g_ui_00025d54->f_0x415_u8 == 0) {
    PTR_g_ui_00025d54->f_0x415_u8 = 1;
  }
  else {
    ui_clear_415_423();
  }
  if (PTR_g_ui_00025d54->f_0x415_u8 == 1) {
    FUN_fffc8ebc();
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbccf4 @ fffbccf4 (23 bytes)

void FUN_fffbccf4(void)

{
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  key_mode_short();
  return;
}


// ===== FUN_fffbcd0b @ fffbcd0b (61 bytes)

void FUN_fffbcd0b(void)

{
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running != 1) {
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffbcd48 @ fffbcd48 (143 bytes)

void FUN_fffbcd48(void)

{
  bool bVar1;
  
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
    return;
  }
  popup_duration_get(10);
  popup_open_timed();
  PTR_g_ui_00025d54->popup_code = 10;
  return;
}


// ===== FUN_fffbcdd7 @ fffbcdd7 (143 bytes)

void FUN_fffbcdd7(void)

{
  bool bVar1;
  
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 9)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
    return;
  }
  popup_duration_get(9);
  popup_open_timed();
  PTR_g_ui_00025d54->popup_code = 9;
  return;
}


// ===== FUN_fffbce66 @ fffbce66 (150 bytes)

void FUN_fffbce66(void)

{
  bool bVar1;
  
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  PTR_g_ui_00025d54->func_panel_open = 0;
  if (PTR_g_ui_00025d54->scan_running != 1) {
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup_close();
    }
    else {
      popup_duration_get(1);
      popup_open_timed();
      PTR_g_ui_00025d54->popup_code = 1;
      popup_mark_clear();
    }
    beep_request(1);
    vfo_mark_edited_if_vfo();
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffbcefc @ fffbcefc (149 bytes)

void FUN_fffbcefc(void)

{
  bool bVar1;
  
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  PTR_g_ui_00025d54->func_panel_open = 0;
  if (PTR_g_ui_00025d54->scan_running != 1) {
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup_close();
    }
    else {
      popup_duration_get(2);
      popup_open_timed();
      PTR_g_ui_00025d54->popup_code = 2;
      popup_mark_clear();
    }
    beep_request(1);
    vfo_mark_edited_if_vfo();
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffbcf91 @ fffbcf91 (227 bytes)

void FUN_fffbcf91(void)

{
  bool bVar1;
  radio_mode rVar2;
  
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  PTR_g_ui_00025d54->func_panel_open = 0;
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  rVar2 = vfo_mode(VFO_RX);
  if ((rVar2 == MODE_FM) || (rVar2 == MODE_FM_N)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (rVar2 == MODE_DATA_FM)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (rVar2 == MODE_DATA_FM_N)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup_close();
    }
    else {
      popup_duration_get(3);
      popup_open_timed();
      PTR_g_ui_00025d54->popup_code = 3;
      popup_mark_clear();
    }
    beep_request(1);
    vfo_mark_edited_if_vfo();
    return;
  }
  PTR_g_ui_00025d54->key_consumed = 1;
  beep_request(3);
  return;
}


// ===== FUN_fffbd074 @ fffbd074 (69 bytes)

void FUN_fffbd074(void)

{
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  PTR_g_ui_00025d54->func_panel_open = 0;
  if (PTR_g_ui_00025d54->scan_running != 1) {
    beep_request(1);
    vfo_mark_edited_if_vfo();
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffbd0b9 @ fffbd0b9 (80 bytes)

void FUN_fffbd0b9(void)

{
  bool bVar1;
  
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 4)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
    return;
  }
  popup_duration_get(4);
  popup_open_timed();
  PTR_g_ui_00025d54->popup_code = 4;
  popup_mark_clear();
  return;
}


// ===== FUN_fffbd109 @ fffbd109 (76 bytes)

void FUN_fffbd109(void)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)vfo_filter_byte_ptr(g_opstate.active_vfo != 0);
  if (pbVar2 == (byte *)0x0) {
    return;
  }
  bVar1 = *pbVar2;
  if ((bVar1 & 0x40) == 0) {
    *pbVar2 = bVar1 | 0x40;
  }
  else {
    *pbVar2 = bVar1 & 0xbf;
  }
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  beep_request(2);
  return;
}


// ===== FUN_fffbd155 @ fffbd155 (23 bytes)

void FUN_fffbd155(void)

{
  if (PTR_g_ui_00025d54->popup_code != 1) {
    return;
  }
  ui_softkey_dispatch(0x20);
  return;
}


// ===== FUN_fffbd16c @ fffbd16c (20 bytes)

void FUN_fffbd16c(void)

{
  if (PTR_g_ui_00025d54->popup_code != 1) {
    return;
  }
  popup_open_2000();
  return;
}


// ===== FUN_fffbd180 @ fffbd180 (23 bytes)

void FUN_fffbd180(void)

{
  if (PTR_g_ui_00025d54->popup_code != 1) {
    return;
  }
  ui_softkey_dispatch(0x21);
  return;
}


// ===== FUN_fffbd197 @ fffbd197 (4 bytes)

void FUN_fffbd197(void)

{
  FUN_fffbd16c();
  return;
}


// ===== FUN_fffbd19b @ fffbd19b (23 bytes)

void FUN_fffbd19b(void)

{
  if (PTR_g_ui_00025d54->popup_code != 1) {
    return;
  }
  ui_softkey_dispatch(0x22);
  return;
}


// ===== FUN_fffbd1b2 @ fffbd1b2 (4 bytes)

void FUN_fffbd1b2(void)

{
  FUN_fffbd16c();
  return;
}


// ===== FUN_fffbd1b6 @ fffbd1b6 (23 bytes)

void FUN_fffbd1b6(void)

{
  if (PTR_g_ui_00025d54->popup_code != 1) {
    return;
  }
  ui_softkey_dispatch(0x23);
  return;
}


// ===== FUN_fffbd1cd @ fffbd1cd (4 bytes)

void FUN_fffbd1cd(void)

{
  FUN_fffbd16c();
  return;
}


// ===== FUN_fffbd1d1 @ fffbd1d1 (23 bytes)

void FUN_fffbd1d1(void)

{
  if (PTR_g_ui_00025d54->popup_code != 2) {
    return;
  }
  ui_softkey_dispatch(0x24);
  return;
}


// ===== FUN_fffbd1e8 @ fffbd1e8 (20 bytes)

void FUN_fffbd1e8(void)

{
  if (PTR_g_ui_00025d54->popup_code != 2) {
    return;
  }
  popup_open_2000();
  return;
}


// ===== FUN_fffbd1fc @ fffbd1fc (23 bytes)

void FUN_fffbd1fc(void)

{
  if (PTR_g_ui_00025d54->popup_code != 2) {
    return;
  }
  ui_softkey_dispatch(0x25);
  return;
}


// ===== FUN_fffbd213 @ fffbd213 (4 bytes)

void FUN_fffbd213(void)

{
  FUN_fffbd1e8();
  return;
}


// ===== FUN_fffbd217 @ fffbd217 (23 bytes)

void FUN_fffbd217(void)

{
  if (PTR_g_ui_00025d54->popup_code != 2) {
    return;
  }
  ui_softkey_dispatch(0x26);
  return;
}


// ===== FUN_fffbd22e @ fffbd22e (4 bytes)

void FUN_fffbd22e(void)

{
  FUN_fffbd1e8();
  return;
}


// ===== FUN_fffbd232 @ fffbd232 (23 bytes)

void FUN_fffbd232(void)

{
  if (PTR_g_ui_00025d54->popup_code != 3) {
    return;
  }
  ui_softkey_dispatch(0x27);
  return;
}


// ===== FUN_fffbd249 @ fffbd249 (20 bytes)

void FUN_fffbd249(void)

{
  if (PTR_g_ui_00025d54->popup_code != 3) {
    return;
  }
  popup_open_2000();
  return;
}

