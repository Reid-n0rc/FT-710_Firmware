// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffbe4a8 @ fffbe4a8 (8 bytes)

void FUN_fffbe4a8(void)

{
  ui_softkey_dispatch(0x155);
  return;
}


// ===== FUN_fffbe4b0 @ fffbe4b0 (8 bytes)

void FUN_fffbe4b0(void)

{
  ui_softkey_dispatch(0x156);
  return;
}


// ===== FUN_fffbe4b8 @ fffbe4b8 (8 bytes)

void FUN_fffbe4b8(void)

{
  ui_softkey_dispatch(0x157);
  return;
}


// ===== FUN_fffbe4c0 @ fffbe4c0 (8 bytes)

void FUN_fffbe4c0(void)

{
  ui_softkey_dispatch(0x159);
  return;
}


// ===== FUN_fffbe4c8 @ fffbe4c8 (8 bytes)

void FUN_fffbe4c8(void)

{
  ui_softkey_dispatch(0x166);
  return;
}


// ===== FUN_fffbe4d0 @ fffbe4d0 (8 bytes)

void FUN_fffbe4d0(void)

{
  ui_softkey_dispatch(0x170);
  return;
}


// ===== FUN_fffbe4d8 @ fffbe4d8 (8 bytes)

void FUN_fffbe4d8(void)

{
  ui_softkey_dispatch(0x180);
  return;
}


// ===== FUN_fffbe4e0 @ fffbe4e0 (8 bytes)

void FUN_fffbe4e0(void)

{
  ui_softkey_dispatch(0x181);
  return;
}


// ===== FUN_fffbe4e8 @ fffbe4e8 (46 bytes)

void FUN_fffbe4e8(void)

{
  byte bVar1;
  
  bVar1 = FUN_fff9cc3d();
  if (1 < bVar1) {
    FUN_fff9cc4c(bVar1 - 1);
    PTR_g_ui_00025d54->dl_req_34 = 1;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbe516 @ fffbe516 (46 bytes)

void FUN_fffbe516(void)

{
  byte bVar1;
  
  bVar1 = FUN_fff9cc3d();
  if (bVar1 < 3) {
    FUN_fff9cc4c(bVar1 + 1);
    PTR_g_ui_00025d54->dl_req_34 = 1;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbe544 @ fffbe544 (62 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbe57f) */

undefined4 FUN_fffbe544(void)

{
  ui_state *puVar1;
  undefined4 uVar2;
  
  PTR_g_ui_00025d54->dl_block_34 = 0;
  FUN_fff9cc4c(1);
  PTR_g_ui_00025d54->menu_state = 2;
  beep_request(1);
  puVar1 = PTR_g_ui_00025d54;
  uVar2 = FUN_fffc523a(0,1,0);
  puVar1->rf_gain = (byte)uVar2;
  return uVar2;
}


// ===== key_lock_pwr_press @ fffbe582 (17 bytes)

/* Front-panel key 0x300 LOCK/PWR, press handler (key tables, display/input.md key codes) (#70) */

void key_lock_pwr_press(void)

{
  if (g_ui.memlist_open != 1) {
    return;
  }
  memlist_close();
  return;
}


// ===== key_lock_pwr_short @ fffbe593 (170 bytes)

/* Front-panel key 0x300 LOCK/PWR, short handler (key tables, display/input.md key codes) (#70) */

void key_lock_pwr_short(void)

{
  PTR_g_ui_00025d54->power_key_req = 1;
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
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (g_opstate.lock_on == 0) {
    g_opstate.lock_on = 1;
    PTR_g_ui_00025d54->popup_code = 0x47;
    popup_duration_get(0x47);
    popup_open_timed();
  }
  else {
    g_opstate.lock_on = 0;
    PTR_g_ui_00025d54->popup_code = 0x48;
    popup_duration_get(0x48);
    popup_open_timed();
  }
  beep_request(1);
  return;
}


// ===== key_lock_pwr_long @ fffbe63d (67 bytes)

/* Front-panel key 0x300 LOCK/PWR, long handler (key tables, display/input.md key codes) (#70) */

void key_lock_pwr_long(void)

{
  if (DAT_0001fa40 == 0x300) {
    if (PTR_g_ui_00025d54->dvs_lm1_flag == 1) {
      PTR_g_ui_00025d54->dvs_lm1_flag = 0;
      PTR_g_ui_00025d54->dl_req_3f = 1;
    }
    PTR_g_ui_00025d54->power_key_req = 2;
    return;
  }
  return;
}


// ===== key_tune_press @ fffbe680 (60 bytes)

/* Front-panel key 0x301 TUNE, press handler (key tables, display/input.md key codes) (#70) */

void key_tune_press(void)

{
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running != 1) {
    beep_request(1);
    vfo_mark_edited_if_vfo();
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== key_tune_short @ fffbe6bc (216 bytes)

/* Front-panel key 0x301 TUNE, short handler (key tables, display/input.md key codes) (#70) */

void key_tune_short(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = g_opstate.ex030104_tuner_type_select;
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (bVar1 == 3) {
    if (PTR_g_ui_00025d54->tune_cycle == 0) {
      tuner_tune_state_set(1);
      return;
    }
    if (PTR_g_ui_00025d54->tune_cycle == 1) {
      tuner_tune_state_set(0);
      return;
    }
  }
  else {
    if (bVar1 == 2) {
      iVar2 = FUN_fffed6f5();
      if (iVar2 != 1) {
        beep_request(3);
        return;
      }
      iVar2 = FUN_fffec55a();
      if (iVar2 == 0) {
        vfo_tuner_bit_set(1);
        g_ui.atu_state = 4;
        return;
      }
      vfo_tuner_bit_set(0);
      g_ui.atu_state = 6;
      return;
    }
    if (bVar1 < 2) {
      if (g_ui.tune_cycle_3d != 0) {
        FUN_fffec52d();
        return;
      }
      iVar2 = FUN_fffec55a();
      if (iVar2 == 0) {
        vfo_tuner_bit_set(1);
        g_ui.atu_state = 1;
        return;
      }
      vfo_tuner_bit_set(0);
      g_ui.atu_state = 3;
      return;
    }
  }
  return;
}


// ===== key_tune_long @ fffbe794 (83 bytes)

/* Front-panel key 0x301 TUNE, long handler (key tables, display/input.md key codes) (#70) */

void key_tune_long(void)

{
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (g_opstate.ex030104_tuner_type_select < 2) {
    if (g_ui.tx_lamp != 0) {
      beep_request(3);
      return;
    }
    g_ui.tune_cycle_3d = 1;
  }
  else if (g_opstate.ex030104_tuner_type_select == 2) {
    g_ui.tune_cycle_3c = 1;
  }
  beep_request(2);
  return;
}


// ===== key_mox_vox_press @ fffbe7e7 (88 bytes)

/* Front-panel key 0x302 MOX/VOX, press handler (key tables, display/input.md key codes) (#70) */

void key_mox_vox_press(void)

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
  if ((DAT_0001b4d9 != '\0') && (DAT_0001b4d9 != '\x01')) {
    PTR_g_ui_00025d54->ptt_mox = 0;
    return;
  }
  return;
}


// ===== key_mox_vox_short @ fffbe83f (147 bytes)

/* Front-panel key 0x302 MOX/VOX, short handler (key tables, display/input.md key codes) (#70) */

void key_mox_vox_short(void)

{
  bool bVar1;
  radio_mode rVar2;
  uint uVar3;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if ((DAT_0001b4d9 == '\0') || (DAT_0001b4d9 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    DAT_0001b4d9 = 0;
    return;
  }
  rVar2 = vfo_mode(VFO_TX);
  uVar3 = (uint)rVar2;
  if ((1 < uVar3 - 2) && (uVar3 != 0xc && uVar3 != 0xd)) {
    g_opstate.vox_on = g_opstate.vox_on == 0;
    beep_request(1);
    swtimer_start(0x2f,100);
    return;
  }
  beep_request(3);
  return;
}


// ===== key_mox_vox_long @ fffbe8d2 (93 bytes)

/* Front-panel key 0x302 MOX/VOX, long handler (key tables, display/input.md key codes) (#70) */

void key_mox_vox_long(void)

{
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (DAT_0001b4d9 == '\0') {
    DAT_0001b4d9 = 2;
    PTR_g_ui_00025d54->ptt_mox = 1;
    return;
  }
  if (DAT_0001b4d9 == '\x01') {
    DAT_0001b4d9 = 2;
    PTR_g_ui_00025d54->ptt_mox = 1;
    return;
  }
  DAT_0001b4d9 = 0;
  return;
}


// ===== key_nb_press @ fffbe92f (60 bytes)

/* Front-panel key 0x303 NB, press handler (key tables, display/input.md key codes) (#70) */

void key_nb_press(void)

{
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running != 1) {
    beep_request(1);
    vfo_mark_edited_if_vfo();
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== key_nb_short @ fffbe96b (107 bytes)

/* Front-panel key 0x303 NB, short handler (key tables, display/input.md key codes) (#70) */

void key_nb_short(void)

{
  byte bVar1;
  vfo_rec *pvVar2;
  byte *local_4;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (PTR_g_ui_00025d54->dl_req_37 == 1) {
    func_panel_close();
  }
  if (g_opstate.active_vfo == 0) {
    pvVar2 = &g_opstate.vfo_a;
  }
  else {
    pvVar2 = &g_opstate.vfo_b;
  }
  local_4 = &pvVar2->flags2;
  bVar1 = *local_4;
  if ((bVar1 & 2) == 0) {
    *local_4 = bVar1 | 2;
  }
  else {
    *local_4 = bVar1 & 0xfd;
  }
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  return;
}


// ===== key_nb_long @ fffbe9d6 (198 bytes)

/* Front-panel key 0x303 NB, long handler (key tables, display/input.md key codes) (#70) */

void key_nb_long(void)

{
  bool bVar1;
  vfo_rec *pvVar2;
  byte *pbStack_4;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (PTR_g_ui_00025d54->dl_req_37 == 1) {
    func_panel_close();
  }
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 0x38)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    g_opstate.nb_level = 0;
    popup_duration_get(0x38);
    popup_open_timed();
    beep_request(1);
    return;
  }
  PTR_g_ui_00025d54->popup_code = 0x38;
  popup_duration_get(0x38);
  popup_open_timed();
  if (g_opstate.active_vfo == 0) {
    pvVar2 = &g_opstate.vfo_a;
  }
  else {
    pvVar2 = &g_opstate.vfo_b;
  }
  pbStack_4 = &pvVar2->flags2;
  *pbStack_4 = *pbStack_4 | 2;
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  beep_request(2);
  return;
}


// ===== key_dnr_press @ fffbea9c (144 bytes)

/* Front-panel key 0x304 DNR, press handler (key tables, display/input.md key codes) (#70) */

void key_dnr_press(void)

{
  bool bVar1;
  radio_mode rVar2;
  
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
  if (bVar1) {
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  beep_request(1);
  vfo_mark_edited_if_vfo();
  return;
}


// ===== key_dnr_short @ fffbeb2c (119 bytes)

/* Front-panel key 0x304 DNR, short handler (key tables, display/input.md key codes) (#70) */

void key_dnr_short(void)

{
  byte bVar1;
  vfo_rec *pvVar2;
  bool local_5;
  byte *local_4;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (PTR_g_ui_00025d54->dl_req_37 == 1) {
    func_panel_close();
  }
  if (g_opstate.active_vfo == 0) {
    pvVar2 = &g_opstate.vfo_a;
  }
  else {
    pvVar2 = &g_opstate.vfo_b;
  }
  local_4 = &pvVar2->dnr;
  bVar1 = *local_4;
  local_5 = (bVar1 & 0x10) != 0;
  if (local_5) {
    *local_4 = bVar1 & 0xef;
  }
  else {
    *local_4 = bVar1 | 0x10;
  }
  local_5 = !local_5;
  FUN_fffc5127(local_5);
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  return;
}


// ===== key_dnr_long @ fffbeba3 (201 bytes)

/* Front-panel key 0x304 DNR, long handler (key tables, display/input.md key codes) (#70) */

void key_dnr_long(void)

{
  bool bVar1;
  vfo_rec *pvVar2;
  byte *local_4;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (PTR_g_ui_00025d54->dl_req_37 == 1) {
    func_panel_close();
  }
  if (g_opstate.active_vfo == 0) {
    pvVar2 = &g_opstate.vfo_a;
  }
  else {
    pvVar2 = &g_opstate.vfo_b;
  }
  local_4 = &pvVar2->dnr;
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 0x39)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *local_4 = *local_4 & 0xf1 | 1;
    PTR_g_ui_00025d54->freq_refresh_req = 1;
  }
  else {
    PTR_g_ui_00025d54->popup_code = 0x39;
    if ((*local_4 & 0x10) == 0) {
      *local_4 = *local_4 | 0x10;
      PTR_g_ui_00025d54->freq_refresh_req = 1;
    }
  }
  popup_duration_get(0x39);
  popup_open_timed();
  beep_request(2);
  return;
}


// ===== key_split_press @ fffbec6c (57 bytes)

/* Front-panel key 0x305 SPLIT, press handler (key tables, display/input.md key codes) (#70) */

void key_split_press(void)

{
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running != 1) {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== split_toggle @ fffbeca5 (352 bytes)

/* FT/ST: toggle 0x9C5E, save/restore 0x9DBE/0x9DBF */

void split_toggle(void)

{
  byte bVar1;
  byte *pbStack_4;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  msg_send_cancel();
  if (g_opstate.split_on == 1) {
    g_opstate.split_on = 0;
    g_opstate.vfo_state_a = PTR_g_ui_00025d54->split_saved_state_a;
    g_opstate.vfo_state_b = PTR_g_ui_00025d54->split_saved_state_b;
    PTR_g_ui_00025d54->txw_on = 0;
    g_ui.txw_swap = 0;
    FUN_fff9cdb0('\0');
    goto LAB_fffbede9;
  }
  if (g_opstate.active_vfo == 0) {
    pbStack_4 = &g_opstate.vfo_state_a;
  }
  else {
    pbStack_4 = &g_opstate.vfo_state_b;
  }
  bVar1 = *pbStack_4;
  if (bVar1 == 2) {
LAB_fffbed59:
    vm_toggle_core();
  }
  else if (bVar1 == 4) {
    *pbStack_4 = 1;
  }
  else if ((bVar1 == 5) || (bVar1 == 7 || bVar1 == 8)) goto LAB_fffbed59;
  g_opstate.split_on = 1;
  PTR_g_ui_00025d54->split_saved_state_a = g_opstate.vfo_state_a;
  PTR_g_ui_00025d54->split_saved_state_b = g_opstate.vfo_state_b;
  g_opstate.split_saved_vfo_state_a = g_opstate.vfo_state_a;
  g_opstate.split_saved_vfo_state_b = g_opstate.vfo_state_b;
  if (g_opstate.active_vfo == 0) {
    PTR_g_ui_00025d54->clar_flags_a = 0;
  }
  else {
    PTR_g_ui_00025d54->clar_flags_b = 0;
  }
  if (PTR_g_ui_00025d54->f_0x482_u8 == 1) {
    FUN_fff9cdb0('\0');
  }
  else {
    FUN_fff9cdb0('\x01');
  }
LAB_fffbede9:
  PTR_g_ui_00025d54->clar_flags_a = 0;
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  return;
}


// ===== key_split_long @ fffbee05 (77 bytes)

/* Front-panel key 0x305 SPLIT, long handler (key tables, display/input.md key codes) (#70) */

void key_split_long(void)

{
  if (g_opstate.split_on == 1) {
    if (g_ui.memlist_open == 1) {
      memlist_close();
    }
    if (PTR_g_ui_00025d54->f_0x482_u8 == 0) {
      PTR_g_ui_00025d54->f_0x482_u8 = 1;
      FUN_fff9cdb0('\0');
    }
    else {
      PTR_g_ui_00025d54->f_0x482_u8 = 0;
      FUN_fff9cdb0('\x01');
    }
    beep_request(2);
    return;
  }
  return;
}


// ===== key_clar_press @ fffbee52 (87 bytes)

/* Front-panel key 0x306 CLAR, press handler (key tables, display/input.md key codes) (#70) */

void key_clar_press(void)

{
  byte bVar1;
  
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
  bVar1 = vfo_tune_locked(VFO_SIDE_SEL);
  if (bVar1 != 1) {
    beep_request(1);
    return;
  }
  beep_request(3);
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== key_clar_short @ fffbeea9 (247 bytes)

/* Front-panel key 0x306 CLAR, short handler (key tables, display/input.md key codes) (#70) */

void key_clar_short(void)

{
  bool bVar1;
  vfo_rec *pvVar2;
  byte bVar3;
  byte *local_c;
  byte *local_8;
  byte local_2;
  bool local_1;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (g_opstate.active_vfo == 0) {
    local_8 = &PTR_g_ui_00025d54->clar_flags_a;
    pvVar2 = &g_opstate.vfo_a;
    local_2 = g_opstate.vfo_state_a;
  }
  else {
    local_8 = &PTR_g_ui_00025d54->clar_flags_b;
    pvVar2 = &g_opstate.vfo_b;
    local_2 = g_opstate.vfo_state_b;
  }
  local_c = &pvVar2->flags1;
  local_1 = g_opstate.active_vfo != 0;
  if ((local_2 == 2) && (bVar3 = memch_current_valid(local_1), bVar3 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    beep_request(3);
    return;
  }
  if (*local_8 == 0) {
    *local_8 = 1;
    *local_c = *local_c | 0x10;
    FUN_fffc3502();
  }
  else if (*local_8 == 1) {
    *local_8 = *local_8 + 1;
    *local_c = *local_c & 0xef | 8;
  }
  else if (*local_8 == 2) {
    *local_8 = *local_8 + 1;
    *local_c = *local_c | 0x18;
  }
  else {
    *local_8 = 0;
    *local_c = *local_c & 0xe7;
  }
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  return;
}


// ===== key_clar_long @ fffbefa0 (109 bytes)

/* Front-panel key 0x306 CLAR, long handler (key tables, display/input.md key codes) (#70) */

void key_clar_long(void)

{
  bool local_1;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (g_opstate.active_vfo == 0) {
    g_opstate.vfo_a.clar_offset_be[0] = 0;
    g_opstate.vfo_a.clar_offset_be[1] = 0;
  }
  else {
    g_opstate.vfo_b.clar_offset_be[0] = 0;
    g_opstate.vfo_b.clar_offset_be[1] = 0;
  }
  local_1 = g_opstate.active_vfo != 0;
  vfo_mark_edited(local_1);
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  beep_request(2);
  return;
}


// ===== key_zin_spot_press @ fffbf00d (169 bytes)

/* Front-panel key 0x307 ZIN/SPOT, press handler (key tables, display/input.md key codes) (#70) */

void key_zin_spot_press(void)

{
  bool bVar1;
  byte bVar2;
  vfo_rec *pvVar3;
  
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
  pvVar3 = vfo_rec_ptr(PTR_g_ui_00025d54->transmitting);
  bVar2 = pvVar3->mode & 0xf;
  if ((bVar2 == 2) || (bVar2 == 3)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    PTR_g_ui_00025d54->key_consumed = 1;
    if (g_ui.memlist_open == 1) {
      memlist_close();
      beep_request(1);
      return;
    }
    beep_request(3);
    return;
  }
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  beep_request(1);
  return;
}


// ===== key_zin_spot_short @ fffbf0b6 (286 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbf119) */
/* WARNING: Removing unreachable block (ram,0xfffbf120) */
/* Front-panel key 0x307 ZIN/SPOT, short handler (key tables, display/input.md key codes) (#70) */

void key_zin_spot_short(void)

{
  int iVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  uint local_c;
  bool local_5;
  vfo_rec *local_4;
  
  if (g_opstate.active_vfo == 0) {
    local_4 = &g_opstate.vfo_a;
  }
  else {
    local_4 = &g_opstate.vfo_b;
  }
  local_5 = g_opstate.active_vfo != 0;
  uVar3 = dsp_tune_offset();
  if (((short)uVar3 < -0x23) || (0x23 < (short)uVar3)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    iVar1 = (int)(short)(uVar3 * 10);
    if ((local_4->mode & 0xf) == 2) {
      iVar1 = -iVar1;
    }
    local_c = ((uint)local_4->freq_be[0] << 0x18 | (uint)local_4->freq_be[1] << 0x10 |
               (uint)local_4->freq_be[2] << 8 | (uint)local_4->freq_be[3]) + iVar1;
    DAT_0001b4e2 = 1;
    uVar4 = freq_clamp(local_5,local_c);
    DAT_0001b4e2 = 0;
    if (PTR_g_ui_00025d54->freq_rejected != 1) {
      local_4->freq_be[0] = (byte)(uVar4 >> 0x18);
      local_4->freq_be[1] = (byte)(uVar4 >> 0x10);
      local_4->freq_be[2] = (byte)(uVar4 >> 8);
      local_c._0_1_ = (byte)uVar4;
      local_4->freq_be[3] = (byte)local_c;
      if (local_5) {
        if (g_opstate.vfo_state_b == 2) {
          vfo_enter_memtune_state(1);
        }
      }
      else if (g_opstate.vfo_state_a == 2) {
        vfo_enter_memtune_state(0);
      }
      vfo_mark_edited(local_5);
      vfo_store_back(local_5);
      PTR_g_ui_00025d54->freq_refresh_req = 1;
      return;
    }
  }
  return;
}


// ===== key_zin_spot_long @ fffbf1d4 (55 bytes)

/* Front-panel key 0x307 ZIN/SPOT, long handler (key tables, display/input.md key codes) (#70) */

void key_zin_spot_long(void)

{
  vfo_rec *pvVar1;
  int iVar2;
  
  PTR_g_ui_00025d54->key_consumed = 1;
  pvVar1 = vfo_rec_ptr(VFO_TX);
  iVar2 = keyer_mode_class(pvVar1);
  if (iVar2 == 0) {
    return;
  }
  PTR_g_ui_00025d54->cw_spot_on = 1;
  beep_request(4);
  return;
}


// ===== key_m_to_v_press @ fffbf20b (41 bytes)

/* Front-panel key 0x308 M>V, press handler (key tables, display/input.md key codes) (#70) */

void key_m_to_v_press(void)

{
  if (PTR_g_ui_00025d54->scan_running != 1) {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== key_m_to_v_short @ fffbf234 (26 bytes)

/* Front-panel key 0x308 M>V, short handler (key tables, display/input.md key codes) (#70) */

void key_m_to_v_short(void)

{
  char cVar1;
  
  msg_send_cancel();
  cVar1 = FUN_fffc2426();
  if (cVar1 == '\x01') {
    return;
  }
  beep_request(3);
  return;
}


// ===== key_m_to_v_long @ fffbf24e (424 bytes)

/* Front-panel key 0x308 M>V, long handler (key tables, display/input.md key codes) (#70) */

void key_m_to_v_long(void)

{
  bool bVar1;
  ushort uVar2;
  vfo_rec *pvVar3;
  vfo_rec *pvVar4;
  int iVar5;
  byte *pbStack_c;
  vfo_rec *local_8;
  byte local_2;
  byte local_1;
  
  local_1 = g_opstate.active_vfo;
  if (g_opstate.active_vfo == 0) {
    if (g_opstate.vfo_state_a == 5) {
      g_opstate.vfo_state_a = 1;
      vfo_reload(0);
      beep_request(2);
      return;
    }
  }
  else if (g_opstate.vfo_state_b == 5) {
    g_opstate.vfo_state_b = 1;
    vfo_reload(1);
    beep_request(2);
    return;
  }
  if (PTR_g_ui_00025d54->memlist_open == 1) {
    local_2 = PTR_g_ui_00025d54->f_0x43a_u8;
  }
  else if (g_opstate.active_vfo == 0) {
    local_2 = g_mem_hdr.chan_b;
  }
  else {
    local_2 = g_mem_hdr.chan_a;
  }
  if (g_opstate.split_on == 1) {
    g_opstate.split_on = 0;
    if (g_opstate.active_vfo == 0) {
      g_opstate.vfo_state_a = g_ui.split_saved_state_a;
      g_opstate.vfo_state_b = 1;
    }
    else {
      g_opstate.vfo_state_b = g_ui.split_saved_state_b;
      g_opstate.vfo_state_a = 1;
    }
  }
  else if (g_opstate.active_vfo == 0) {
    g_opstate.vfo_state_b = 1;
  }
  else {
    g_opstate.vfo_state_a = 1;
  }
  uVar2 = dest_code_get();
  if (uVar2 == 0x315b) {
    if ((local_2 < 0x75) || (0x83 < local_2)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      beep_request(3);
      return;
    }
  }
  bVar1 = memch_valid(local_2,&pbStack_c);
  if (!bVar1) {
    beep_request(3);
    return;
  }
  local_8 = memch + local_2;
  if (local_1 == 0) {
    pvVar3 = &g_opstate.vfo_b;
    pvVar4 = local_8;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      pvVar3->mode = pvVar4->mode;
      pvVar3 = (vfo_rec *)&pvVar3->flags1;
      pvVar4 = (vfo_rec *)&pvVar4->flags1;
    }
    vfo_store_back(0);
  }
  else {
    pvVar3 = &g_opstate.vfo_a;
    pvVar4 = local_8;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      pvVar3->mode = pvVar4->mode;
      pvVar3 = (vfo_rec *)&pvVar3->flags1;
      pvVar4 = (vfo_rec *)&pvVar4->flags1;
    }
    vfo_store_back(1);
  }
  memlist_close();
  beep_request(2);
  return;
}


// ===== key_vm_mw_press @ fffbf3f6 (41 bytes)

/* Front-panel key 0x309 V/M W, press handler (key tables, display/input.md key codes) (#70) */

void key_vm_mw_press(void)

{
  if (PTR_g_ui_00025d54->scan_running != 1) {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== vm_toggle @ fffbf41f (28 bytes)

/* V/M key */

void vm_toggle(void)

{
  if (g_ui.memlist_open != 1) {
    msg_send_cancel();
    vm_toggle_core();
    tuner_rearm();
    return;
  }
  memlist_close();
  return;
}


// ===== key_vm_mw_long @ fffbf43b (71 bytes)

/* Front-panel key 0x309 V/M W, long handler (key tables, display/input.md key codes) (#70) */

void key_vm_mw_long(void)

{
  if (PTR_g_ui_00025d54->func_panel_open == 1) {
    PTR_g_ui_00025d54->func_panel_open = 0;
  }
  if (PTR_g_ui_00025d54->memlist_open == 0) {
    menu_close_if_open();
    func_panel_close();
    popup8_close();
    ui_clear_415_423();
    FUN_fffc29f3();
    memlist_cursor_channel();
    beep_request(2);
    return;
  }
  FUN_fffc2b94();
  return;
}


// ===== key_a_b_press @ fffbf482 (57 bytes)

/* Front-panel key 0x30A A/B, press handler (key tables, display/input.md key codes) (#70) */

void key_a_b_press(void)

{
  if (PTR_g_ui_00025d54->scan_running != 1) {
    popup_close();
    menu_close_if_open();
    func_panel_close();
    popup8_close();
    ui_clear_415_423();
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== vfo_ab_toggle @ fffbf4bb (283 bytes)

/* SV/VS: flip 0x9DBD in VFO state, else step toward VFO */

void vfo_ab_toggle(void)

{
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  msg_send_cancel();
  g_opstate.split_on = 0;
  if (g_opstate.active_vfo == 0) {
    if (g_opstate.vfo_state_a == 3) {
      vm_toggle();
      vm_toggle();
    }
    else if (g_opstate.vfo_state_a == 5) {
      g_opstate.vfo_state_a = 1;
      vfo_reload(0);
    }
    else if (g_opstate.vfo_state_a == 1) {
      g_opstate.active_vfo = 1;
      PTR_g_ui_00025d54->f_0x443_u8 = 1;
      PTR_g_ui_00025d54->f_0x445_u8 = 1;
    }
    else {
      vm_toggle();
    }
  }
  else if (g_opstate.vfo_state_b == 3) {
    vm_toggle();
    vm_toggle();
  }
  else if (g_opstate.vfo_state_b == 5) {
    g_opstate.vfo_state_b = 1;
    vfo_reload(1);
  }
  else if (g_opstate.vfo_state_b == 1) {
    g_opstate.active_vfo = 0;
    PTR_g_ui_00025d54->f_0x443_u8 = 1;
    PTR_g_ui_00025d54->f_0x445_u8 = 1;
  }
  else {
    vm_toggle();
  }
  tuner_rearm();
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  return;
}


// ===== key_a_b_long @ fffbf5d6 (42 bytes)

/* Front-panel key 0x30A A/B, long handler (key tables, display/input.md key codes) (#70) */

void key_a_b_long(void)

{
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (g_opstate.active_vfo == 0) {
    FUN_fffc2d05();
  }
  else {
    FUN_fffc2f50();
  }
  beep_request(2);
  return;
}


// ===== key_band_press @ fffbf600 (47 bytes)

/* Front-panel key 0x30B BAND, press handler (key tables, display/input.md key codes) (#70) */

void key_band_press(void)

{
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running != 1) {
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== key_band_short @ fffbf62f (146 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbf6be) */
/* Front-panel key 0x30B BAND, short handler (key tables, display/input.md key codes) (#70) */

void key_band_short(void)

{
  bool bVar1;
  ui_state *puVar2;
  byte bVar3;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  msg_send_cancel();
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 0xc)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
  }
  else {
    PTR_g_ui_00025d54->f_0x41e_u8 = 0;
    popup_duration_get(0xc);
    popup_open_timed();
    PTR_g_ui_00025d54->popup_code = 0xc;
    puVar2 = PTR_g_ui_00025d54;
    bVar3 = FUN_fffc3006();
    puVar2->popup_band = bVar3;
    PTR_g_ui_00025d54->band_cur = PTR_g_ui_00025d54->popup_band;
  }
  beep_request(1);
  return;
}


// ===== key_mode_press @ fffbf6c1 (7 bytes)

/* Front-panel key 0x30C MODE, press handler (key tables, display/input.md key codes) (#70) */

void key_mode_press(void)

{
  beep_request(1);
  return;
}


// ===== key_mode_short @ fffbf6c8 (223 bytes)

/* Front-panel key 0x30C MODE, short handler (key tables, display/input.md key codes) (#70) */

void key_mode_short(void)

{
  bool bVar1;
  vfo_rec *pvStack_4;
  
  if (g_ui.playlist_open != 0) {
    g_ui.playlist_open = 0;
  }
  msg_send_cancel();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 5)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
    return;
  }
  if (g_opstate.active_vfo == 0) {
    pvStack_4 = &g_opstate.vfo_a;
  }
  else {
    pvStack_4 = &g_opstate.vfo_b;
  }
  PTR_g_ui_00025d54->band_cur = pvStack_4->mode & 0xf;
  popup_duration_get(5);
  popup_open_timed();
  PTR_g_ui_00025d54->popup_code = 5;
  return;
}


// ===== key_mode_long @ fffbf7a7 (48 bytes)

/* Front-panel key 0x30C MODE, long handler (key tables, display/input.md key codes) (#70) */

void key_mode_long(void)

{
  if (PTR_g_ui_00025d54->sd_present != 0) {
    PTR_g_ui_00025d54->dl_req_7a = 1;
    FUN_fffc8f8b(1000);
    beep_request(2);
    return;
  }
  beep_request(3);
  return;
}


// ===== key_nar_press @ fffbf7d7 (48 bytes)

/* Front-panel key 0x30D NAR, press handler (key tables, display/input.md key codes) (#70) */

void key_nar_press(void)

{
  popup_close();
  menu_close_if_open();
  func_panel_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running != 1) {
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}

