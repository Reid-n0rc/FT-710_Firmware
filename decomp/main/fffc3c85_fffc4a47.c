// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== func_panel_close @ fffc3c85 (26 bytes)

/* UI +0x96 = 0 (FUNC panel, frame 0x37) and +0x1C5 = 0 (FUNC item highlighted) [fact for the
   stores; panel from display-link.md] */

void func_panel_close(void)

{
  PTR_g_ui_00025d54->dl_req_37 = 0;
  PTR_g_ui_00025d54->f_0x1c5_u8 = 0;
  return;
}


// ===== FUN_fffc3c9f @ fffc3c9f (58 bytes)

void FUN_fffc3c9f(void)

{
  g_opstate.ss02_marker = g_opstate.ss02_marker != 1;
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffc3cd9 @ fffc3cd9 (77 bytes)

void FUN_fffc3cd9(void)

{
  g_opstate.func_knob = 3;
  popup_duration_get(0xb);
  popup_open_timed();
  PTR_g_ui_00025d54->popup_code = 0xb;
  PTR_g_ui_00025d54->band_cur = g_opstate.ss03_value;
  func_panel_close();
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffc3d26 @ fffc3d26 (79 bytes)

void FUN_fffc3d26(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc3d75();
  if (iVar1 == 0) {
    return;
  }
  g_opstate.proc_on = g_opstate.proc_on == 0;
  PTR_g_ui_00025d54->vfo_refresh_req = 1;
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffc3d75 @ fffc3d75 (115 bytes)

undefined1 FUN_fffc3d75(void)

{
  bool bVar1;
  undefined1 uVar2;
  radio_mode rVar3;
  
  rVar3 = vfo_mode(VFO_RX);
  if ((rVar3 == MODE_LSB) || (rVar3 == MODE_USB)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (rVar3 == MODE_AM)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (rVar3 == MODE_AM_N)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (rVar3 == MODE_FM)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (rVar3 == MODE_FM_N)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_fffc3de8 @ fffc3de8 (84 bytes)

void FUN_fffc3de8(void)

{
  vfo_rec *pvVar1;
  int iVar2;
  
  pvVar1 = vfo_rec_ptr(VFO_TX);
  iVar2 = keyer_mode_class(pvVar1);
  if (iVar2 == 0) {
    return;
  }
  g_opstate.keyer_on = g_opstate.keyer_on != 1;
  keyer_init();
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== keyer_mode_class @ fffc3e3c (110 bytes)

/* (rec): 1 in CW (mode 2/3); in SSB 2 when CW AUTO MODE 0x9A3C allows it, else 0 [fact] */

undefined1 keyer_mode_class(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  undefined1 local_7;
  
  bVar2 = *param_1 & 0xf;
  if ((bVar2 == 2) || (bVar2 == 3)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_7 = 1;
  }
  else {
    if ((bVar2 == 0) || (bVar2 == 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_7 = 0;
    }
    else if (g_opstate.ex010119_cw_auto_mode == 2) {
      local_7 = 2;
    }
    else if (g_opstate.ex010119_cw_auto_mode == 0) {
      local_7 = 0;
    }
    else {
      local_7 = 2;
    }
  }
  return local_7;
}


// ===== FUN_fffc3eaa @ fffc3eaa (113 bytes)

void FUN_fffc3eaa(void)

{
  bool bVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  pvVar2 = vfo_rec_ptr(VFO_TX);
  iVar3 = FUN_fffc3f1b(pvVar2);
  if ((iVar3 == 0) && (iVar3 = keyer_mode_class(pvVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (g_ui.tx_lamp != 0) {
      PTR_g_ui_00025d54->key_consumed = 1;
      return;
    }
    FUN_fffc3f40(pvVar2);
    keyer_init();
    beep_request(1);
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffc3f1b @ fffc3f1b (37 bytes)

undefined1 FUN_fffc3f1b(byte *param_1)

{
  undefined1 local_7;
  
  if (((*param_1 & 0xf) < 2) || ((*param_1 & 0xf) - 4 < 4)) {
    local_7 = 1;
  }
  else {
    local_7 = 0;
  }
  return local_7;
}


// ===== FUN_fffc3f40 @ fffc3f40 (92 bytes)

void FUN_fffc3f40(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  byte *local_c;
  
  uVar2 = (uint)(*param_1 & 0xf);
  if (uVar2 - 6 < 2) {
    local_c = param_1 + 0x3c;
  }
  else if (uVar2 - 2 < 2) {
    local_c = param_1 + 0x14;
  }
  else if (uVar2 - 4 < 2) {
    local_c = param_1 + 0x32;
  }
  else {
    if (1 < uVar2) {
      return;
    }
    local_c = param_1 + 10;
  }
  bVar1 = *local_c;
  if ((bVar1 & 2) != 0) {
    *local_c = bVar1 & 0xfd;
    return;
  }
  *local_c = bVar1 | 2;
  return;
}


// ===== FUN_fffc3f9c @ fffc3f9c (83 bytes)

void FUN_fffc3f9c(void)

{
  if (g_opstate.split_on != 1) {
    return;
  }
  if (PTR_g_ui_00025d54->txw_on == 1) {
    PTR_g_ui_00025d54->txw_on = 0;
  }
  else {
    PTR_g_ui_00025d54->txw_on = 1;
    PTR_g_ui_00025d54->f_0x1c5_u8 = 1;
    FUN_fffc8e0e(500);
    PTR_g_ui_00025d54->key_consumed = 1;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffc3fef @ fffc3fef (117 bytes)

void FUN_fffc3fef(void)

{
  byte *pbVar1;
  vfo_rec *pvVar2;
  vfo_rec *pvVar3;
  int iVar4;
  
  if (PTR_g_ui_00025d54->scan_running != 1) {
    menu_close_if_open();
    popup8_close();
    ui_clear_415_423();
    PTR_g_ui_00025d54->txw_swap = 1;
    pvVar2 = &g_opstate.vfo_a;
    pbVar1 = &DAT_000121c7;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pbVar1 = pvVar2->mode;
      pbVar1 = pbVar1 + 1;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
    }
    pvVar3 = &g_opstate.vfo_b;
    pvVar2 = &g_opstate.vfo_a;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      pvVar2->mode = pvVar3->mode;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
      pvVar3 = (vfo_rec *)&pvVar3->flags1;
    }
    pvVar2 = &g_opstate.vfo_b;
    pbVar1 = &DAT_000121c7;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      pvVar2->mode = *pbVar1;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
      pbVar1 = pbVar1 + 1;
    }
    PTR_g_ui_00025d54->vfo_refresh_req = 1;
    return;
  }
  scan_stop();
  return;
}


// ===== FUN_fffc4064 @ fffc4064 (115 bytes)

void FUN_fffc4064(void)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte *pbStack_4;
  
  bVar2 = memch_valid(PTR_g_ui_00025d54->f_0x43a_u8,&pbStack_4);
  bVar1 = g_opstate.active_vfo;
  if (!bVar2) {
    beep_request(3);
    return;
  }
  bVar3 = vfo_is_memory(g_opstate.active_vfo);
  if (bVar3 == 0) {
    vm_toggle_core();
  }
  memch_current_set(bVar1,PTR_g_ui_00025d54->f_0x43a_u8);
  eeprom_save_memch(PTR_g_ui_00025d54->f_0x43a_u8);
  vfo_reload(bVar1);
  PTR_g_ui_00025d54->vfo_refresh_req = 1;
  memlist_close();
  beep_request(1);
  return;
}


// ===== key_slot_press @ fffc40d7 (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc40f7) */
/* Mic/slot key, press role: slots 0..0xC via the code list 0xFFF88534 into key_press_table,
   0xD..0x14 via 0xFFF8E0CC [fact] (ui-keys.md) */

void key_slot_press(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_key_nop_fff8e0cc)[uVar1])();
    return;
  }
  (*(code *)(&key_press_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== key_slot_short @ fffc410a (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc412a) */
/* Same for the short role (key_short_table, 0xFFF8E0EC) [fact] */

void key_slot_short(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_FUN_fff8e0ec)[uVar1])();
    return;
  }
  (*(code *)(&key_short_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== key_slot_long @ fffc413d (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc415d) */
/* Same for the long role (key_long_table, 0xFFF8E10C) [fact] */

void key_slot_long(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_FUN_fff8e10c)[uVar1])();
    return;
  }
  (*(code *)(&key_long_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== key_slot_repeat @ fffc4170 (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc4190) */
/* Same for the repeat role (key_repeat_table, 0xFFF8E12C) [fact] */

void key_slot_repeat(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_FUN_fff8e12c)[uVar1])();
    return;
  }
  (*(code *)(&key_repeat_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== key_slot_release @ fffc41a3 (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc41c3) */
/* Same for the release role (key_release_table) [fact] */

void key_slot_release(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_FUN_fff8e14c)[uVar1])();
    return;
  }
  (*(code *)(&key_release_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== FUN_fffc41d6 @ fffc41d6 (98 bytes)

void FUN_fffc41d6(void)

{
  bool bVar1;
  
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
  }
  if (PTR_g_ui_00025d54->tx_lamp == 0) {
    if (g_ui.dl_req_40 == 1) {
      beep_request(1);
      return;
    }
    FUN_fffe60a6();
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc4238 @ fffc4238 (81 bytes)

void FUN_fffc4238(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d54->tx_lamp != 0) {
    if ((g_opstate.ex030104_tuner_type_select == 3) && (PTR_g_ui_00025d54->tune_cycle != 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_g_ui_00025d54->f_0x03a_u8 = 1;
      tuner_tune_state_set(2);
      return;
    }
  }
  return;
}


// ===== FUN_fffc4289 @ fffc4289 (66 bytes)

void FUN_fffc4289(void)

{
  if ((PTR_g_ui_00025d54->tx_lamp == 0) && (PTR_g_ui_00025d54->f_0x46b_u8 == 1)) {
    vfo_step_up(g_opstate.active_vfo);
    FUN_fffe602e();
    DAT_0001b4dc = 1;
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc42cb @ fffc42cb (36 bytes)

void FUN_fffc42cb(void)

{
  if (PTR_g_ui_00025d54->f_0x46b_u8 != 1) {
    return;
  }
  vfo_step_up(g_opstate.active_vfo);
  FUN_fffe602e();
  return;
}


// ===== FUN_fffc42ef @ fffc42ef (155 bytes)

void FUN_fffc42ef(void)

{
  bool bVar1;
  byte bVar2;
  
  if (PTR_g_ui_00025d54->tune_cycle == 2) {
    PTR_g_ui_00025d54->f_0x03a_u8 = 3;
    swtimer_start(0x20,1000);
  }
  if (PTR_g_ui_00025d54->tx_lamp == 0) {
    if ((PTR_g_ui_00025d54->f_0x46b_u8 == 1) && (PTR_g_ui_00025d54->mic_key_hold == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar2 = scan_allowed();
      if (bVar2 == 1) {
        scan_start_up();
      }
    }
    else {
      bVar2 = FUN_fffb32aa(0);
      bVar2 = memch_current(bVar2);
      eeprom_save_memch(bVar2);
    }
  }
  PTR_g_ui_00025d54->mic_key_hold = 0;
  PTR_g_ui_00025d54->f_0x46b_u8 = 0;
  return;
}


// ===== FUN_fffc438a @ fffc438a (98 bytes)

void FUN_fffc438a(void)

{
  bool bVar1;
  
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
  }
  if (PTR_g_ui_00025d54->tx_lamp == 0) {
    if (g_ui.dl_req_40 == 1) {
      beep_request(1);
      return;
    }
    FUN_fffe6138();
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc43ec @ fffc43ec (81 bytes)

void FUN_fffc43ec(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d54->tx_lamp != 0) {
    if ((g_opstate.ex030104_tuner_type_select == 3) && (PTR_g_ui_00025d54->tune_cycle != 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_g_ui_00025d54->f_0x03a_u8 = 2;
      tuner_tune_state_set(2);
      return;
    }
  }
  return;
}


// ===== FUN_fffc443d @ fffc443d (66 bytes)

void FUN_fffc443d(void)

{
  if ((PTR_g_ui_00025d54->tx_lamp == 0) && (PTR_g_ui_00025d54->f_0x46b_u8 == 1)) {
    vfo_step_down(g_opstate.active_vfo);
    FUN_fffe602e();
    DAT_0001b4dc = 1;
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc447f @ fffc447f (36 bytes)

void FUN_fffc447f(void)

{
  if (PTR_g_ui_00025d54->f_0x46b_u8 != 1) {
    return;
  }
  vfo_step_down(g_opstate.active_vfo);
  FUN_fffe602e();
  return;
}


// ===== FUN_fffc44a3 @ fffc44a3 (155 bytes)

void FUN_fffc44a3(void)

{
  bool bVar1;
  byte bVar2;
  
  if (PTR_g_ui_00025d54->tune_cycle == 2) {
    PTR_g_ui_00025d54->f_0x03a_u8 = 3;
    swtimer_start(0x20,1000);
  }
  if (PTR_g_ui_00025d54->tx_lamp == 0) {
    if ((PTR_g_ui_00025d54->f_0x46b_u8 == 1) && (PTR_g_ui_00025d54->mic_key_hold == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar2 = scan_allowed();
      if (bVar2 == 1) {
        scan_start_down();
      }
    }
    else {
      bVar2 = FUN_fffb32aa(0);
      bVar2 = memch_current(bVar2);
      eeprom_save_memch(bVar2);
    }
  }
  PTR_g_ui_00025d54->mic_key_hold = 0;
  PTR_g_ui_00025d54->f_0x46b_u8 = 0;
  return;
}


// ===== FUN_fffc453e @ fffc453e (66 bytes)

void FUN_fffc453e(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = ui_close_overlays();
  if (iVar2 != 0) {
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup_close();
    }
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc4580 @ fffc4580 (11 bytes)

void FUN_fffc4580(void)

{
  cat_BU(-0x70bf0);
  return;
}


// ===== FUN_fffc458b @ fffc458b (36 bytes)

void FUN_fffc458b(void)

{
  cat_BU(-0x70bf0);
  swtimer_start(0x40,0xfa);
  DAT_0001b4dc = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc45af @ fffc45af (21 bytes)

void FUN_fffc45af(void)

{
  cat_BU(-0x70bf0);
  swtimer_start(0x40,0xfa);
  return;
}


// ===== FUN_fffc45c4 @ fffc45c4 (1 bytes)

void FUN_fffc45c4(void)

{
  return;
}


// ===== FUN_fffc45c5 @ fffc45c5 (66 bytes)

void FUN_fffc45c5(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = ui_close_overlays();
  if (iVar2 != 0) {
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup_close();
    }
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc4607 @ fffc4607 (11 bytes)

void FUN_fffc4607(void)

{
  cat_BD(-0x70bec);
  return;
}


// ===== FUN_fffc4612 @ fffc4612 (36 bytes)

void FUN_fffc4612(void)

{
  cat_BD(-0x70bec);
  swtimer_start(0x40,0xfa);
  DAT_0001b4dc = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc4636 @ fffc4636 (21 bytes)

void FUN_fffc4636(void)

{
  cat_BD(-0x70bec);
  swtimer_start(0x40,0xfa);
  return;
}


// ===== FUN_fffc464b @ fffc464b (1 bytes)

void FUN_fffc464b(void)

{
  return;
}


// ===== FUN_fffc464c @ fffc464c (60 bytes)

void FUN_fffc464c(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = ui_close_overlays();
  if (iVar2 != 0) {
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup_close();
      return;
    }
  }
  return;
}


// ===== FUN_fffc4688 @ fffc4688 (133 bytes)

void FUN_fffc4688(void)

{
  byte bVar1;
  int local_4;
  
  if (g_opstate.active_vfo == 0) {
    local_4 = 0x9d09;
  }
  else {
    local_4 = 0x9d63;
  }
  bVar1 = *(byte *)(local_4 + 3) & 3;
  if (bVar1 == 3) {
    *(byte *)(local_4 + 3) = *(byte *)(local_4 + 3) & 0xfc;
  }
  else if (bVar1 == 1) {
    *(byte *)(local_4 + 3) = *(byte *)(local_4 + 3) & 0xfe | 2;
  }
  else if (bVar1 == 2) {
    *(byte *)(local_4 + 3) = *(byte *)(local_4 + 3) | 3;
  }
  else if ((*(byte *)(local_4 + 3) & 3) == 0) {
    *(byte *)(local_4 + 3) = *(byte *)(local_4 + 3) & 0xfd | 1;
  }
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc470d @ fffc470d (73 bytes)

void FUN_fffc470d(void)

{
  int local_4;
  
  if (g_opstate.active_vfo == 0) {
    local_4 = 0x9d09;
  }
  else {
    local_4 = 0x9d63;
  }
  *(byte *)(local_4 + 3) = *(byte *)(local_4 + 3) & 0xfc;
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  beep_request(2);
  return;
}


// ===== ui_close_overlays @ fffc4756 (75 bytes)

/* menu_close_if_open, func_panel_close, popup8_close, ui_clear_415_423, +0x70 = 0; stops a running
   scan (+0x418) and sets +0x409; returns false if it stopped a scan [fact] */

bool ui_close_overlays(void)

{
  bool bStack_2;
  
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  PTR_g_ui_00025d54->func_panel_open = 0;
  bStack_2 = PTR_g_ui_00025d54->scan_running == 1;
  if (bStack_2) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
  }
  bStack_2 = !bStack_2;
  return bStack_2;
}


// ===== FUN_fffc47a1 @ fffc47a1 (60 bytes)

void FUN_fffc47a1(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = ui_close_overlays();
  if (iVar2 != 0) {
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup_close();
      return;
    }
  }
  return;
}


// ===== preamp_step @ fffc47dd (115 bytes)

/* Record +0x05 bits 0-1: IPO(0) -> AMP1(2) -> AMP2(3) -> IPO, beep 1 [fact]; the IPO key
   [inference] (#205) */

void preamp_step(void)

{
  byte bVar1;
  int local_4;
  
  if (g_opstate.active_vfo == 0) {
    local_4 = 0x9d09;
  }
  else {
    local_4 = 0x9d63;
  }
  bVar1 = *(byte *)(local_4 + 5) & 3;
  if (bVar1 == 3) {
    *(byte *)(local_4 + 5) = *(byte *)(local_4 + 5) & 0xfc;
  }
  else if (bVar1 == 2) {
    *(byte *)(local_4 + 5) = *(byte *)(local_4 + 5) | 3;
  }
  else if ((*(byte *)(local_4 + 5) & 3) == 0) {
    *(byte *)(local_4 + 5) = *(byte *)(local_4 + 5) & 0xfe | 2;
  }
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  beep_request(1);
  return;
}


// ===== preamp_ipo @ fffc4850 (73 bytes)

/* Record +0x05 bits 0-1 = 0 (IPO), beep 2 [fact] (#205) */

void preamp_ipo(void)

{
  int local_4;
  
  if (g_opstate.active_vfo == 0) {
    local_4 = 0x9d09;
  }
  else {
    local_4 = 0x9d63;
  }
  *(byte *)(local_4 + 5) = *(byte *)(local_4 + 5) & 0xfc;
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  beep_request(2);
  return;
}


// ===== FUN_fffc4899 @ fffc4899 (139 bytes)

void FUN_fffc4899(void)

{
  bool bVar1;
  radio_mode rVar2;
  int iVar3;
  
  iVar3 = ui_close_overlays();
  if (iVar3 != 0) {
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
      beep_request(3);
      return;
    }
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup_close();
      return;
    }
  }
  return;
}


// ===== FUN_fffc4924 @ fffc4924 (88 bytes)

void FUN_fffc4924(void)

{
  byte bVar1;
  undefined4 local_4;
  
  if (g_opstate.active_vfo == 0) {
    local_4 = 0x9d09;
  }
  else {
    local_4 = 0x9d63;
  }
  bVar1 = mode_block_byte1(local_4);
  if ((bVar1 & 0x80) == 0) {
    FUN_fffc0948(local_4,1);
  }
  else {
    FUN_fffc0948(local_4,0);
  }
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc497c @ fffc497c (69 bytes)

void FUN_fffc497c(void)

{
  bool bVar1;
  int iVar2;
  
  FUN_fffbd074();
  iVar2 = ui_close_overlays();
  if (iVar2 != 0) {
    if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 4)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      popup_close();
    }
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc49c1 @ fffc49c1 (134 bytes)

void FUN_fffc49c1(void)

{
  byte *pbVar1;
  byte bVar2;
  
  pbVar1 = (byte *)vfo_filter_byte_ptr(g_opstate.active_vfo != 0);
  if (pbVar1 == (byte *)0x0) {
    return;
  }
  if ((*pbVar1 & 0x40) == 0) {
    *pbVar1 = *pbVar1 | 0x40;
  }
  bVar2 = *pbVar1 & 0x30;
  if (bVar2 == 0x30) {
    *pbVar1 = *pbVar1 & 0xef | 0x20;
  }
  else if (bVar2 == 0x10) {
    *pbVar1 = *pbVar1 & 0xcf;
  }
  else if (bVar2 == 0x20) {
    *pbVar1 = *pbVar1 & 0xdf | 0x10;
  }
  else if ((*pbVar1 & 0x30) == 0) {
    *pbVar1 = *pbVar1 | 0x30;
  }
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  return;
}


// ===== FUN_fffc4a47 @ fffc4a47 (70 bytes)

void FUN_fffc4a47(void)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)vfo_filter_byte_ptr(g_opstate.active_vfo != 0);
  if (pbVar1 == (byte *)0x0) {
    return;
  }
  if ((*pbVar1 & 0x40) == 0) {
    *pbVar1 = *pbVar1 | 0x40;
  }
  *pbVar1 = *pbVar1 & 0xcf;
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  return;
}

