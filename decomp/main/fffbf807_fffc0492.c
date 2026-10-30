// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== key_nar_short @ fffbf807 (231 bytes)

/* Front-panel key 0x30D NAR, short handler (key tables, display/input.md key codes) (#70) */

void key_nar_short(void)

{
  bool bVar1;
  vfo_rec *pvVar2;
  byte local_d;
  byte *local_c;
  bool local_5;
  vfo_rec *local_4;
  
  bVar1 = false;
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (g_opstate.active_vfo == VFO_A) {
    local_4 = &g_opstate.vfo_a;
    pvVar2 = &g_opstate.vfo_a;
  }
  else {
    local_4 = &g_opstate.vfo_b;
    pvVar2 = &g_opstate.vfo_b;
  }
  local_c = &pvVar2->nar_flags;
  local_5 = g_opstate.active_vfo != VFO_A;
  switch(local_4->mode & 0xf) {
  case 0:
  case 1:
    bVar1 = true;
    local_d = 0x80;
    break;
  case 2:
  case 3:
    bVar1 = true;
    local_d = 0x20;
    break;
  case 4:
    FUN_fffc0e3e();
    break;
  case 5:
    FUN_fffc0e31();
    break;
  case 6:
    FUN_fffc0e58();
    break;
  case 7:
    FUN_fffc0e4b();
    break;
  case 8:
  case 9:
  case 0xe:
    bVar1 = true;
    local_d = 4;
    break;
  case 10:
    FUN_fffc0e72();
    break;
  case 0xb:
    FUN_fffc0e65();
    break;
  case 0xc:
  case 0xd:
    bVar1 = true;
    local_d = 8;
  }
  if (bVar1) {
    if ((local_d & *local_c) == 0) {
      *local_c = local_d | *local_c;
    }
    else {
      *local_c = ~local_d & *local_c;
    }
    vfo_mark_edited(local_5);
    vfo_store_back(local_5);
    PTR_g_ui_00025d54->freq_refresh_req = 1;
  }
  beep_request(1);
  return;
}


// ===== key_qmb_press @ fffbf8ee (54 bytes)

/* Front-panel key 0x30E QMB, press handler (key tables, display/input.md key codes) (#70) */

void key_qmb_press(void)

{
  popup_close();
  menu_close_if_open();
  func_panel_close();
  ui_clear_415_423();
  if (PTR_g_ui_00025d54->scan_running != 1) {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== qmb_recall @ fffbf924 (416 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbf95a) */
/* QR: leave split, enter state 5, load slot */

void qmb_recall(void)

{
  int iVar1;
  byte local_3;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (g_ui.msgmem_open != 0) {
    msg_send_cancel();
    g_ui.msgmem_open = 0;
  }
  if ((CONCAT11(g_qmb_hdr.used_mask_be[0],g_qmb_hdr.used_mask_be[1]) & 0x3ff) != 0) {
    if (g_opstate.split_on == 1) {
      g_opstate.split_on = 0;
      g_opstate.vfo_state_a = PTR_g_ui_00025d54->split_saved_state_a;
      g_opstate.vfo_state_b = PTR_g_ui_00025d54->split_saved_state_b;
      PTR_g_ui_00025d54->txw_on = 0;
      g_ui.txw_swap = 0;
    }
    if (g_opstate.active_vfo == VFO_A) {
      local_3 = 0;
      if (g_opstate.vfo_state_a != VFO_STATE_QMB) {
        FUN_fffc34d8(0);
      }
    }
    else {
      local_3 = 1;
      if (g_opstate.vfo_state_b != VFO_STATE_QMB) {
        FUN_fffc34d8(1);
      }
    }
    iVar1 = FUN_fffc302b(local_3);
    if (iVar1 == 0) {
      if (local_3 == 0) {
        PTR_g_ui_00025d54->edited_a = 0;
        PTR_g_ui_00025d54->tuned_a = 0;
      }
      else {
        PTR_g_ui_00025d54->edited_b = 0;
        PTR_g_ui_00025d54->tuned_b = 0;
      }
    }
    vfo_enter_vfo_state(local_3);
    iVar1 = FUN_fffc30af(local_3);
    if (iVar1 == 1) {
      qmb_set_depth(local_3);
      vfo_store_back(local_3);
    }
    if (local_3 == 0) {
      if (g_qmb_hdr.ptr_a[0] != 0) {
        qmb_enter(0);
        return;
      }
      g_opstate.vfo_state_a = VFO_STATE_VFO;
    }
    else {
      if (g_qmb_hdr.ptr_b[0] != 0) {
        qmb_enter(1);
        return;
      }
      g_opstate.vfo_state_b = VFO_STATE_VFO;
    }
    qmb_set_depth(local_3);
    vfo_reload(local_3);
    PTR_g_ui_00025d54->vfo_refresh_req = 1;
    tuner_rearm();
    popup_close();
    return;
  }
  beep_request(3);
  return;
}


// ===== qmb_store @ fffbfac4 (371 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbfb0d) */
/* QI: operating record -> QMB slot (0x9023+n*0x5A), mask 0x9012 */

void qmb_store(void)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  vfo_rec *pvVar4;
  int iVar5;
  vfo_rec *local_10;
  bool local_5;
  ushort local_4;
  byte local_2;
  
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  bVar1 = g_opstate.active_vfo != VFO_A;
  bVar3 = vfo_is_memory(bVar1);
  if ((bVar3 == 1) && (bVar3 = memch_current_is_special(bVar1), bVar3 == 1)) {
    beep_request(3);
    return;
  }
  local_4 = CONCAT11(g_qmb_hdr.used_mask_be[0],g_qmb_hdr.used_mask_be[1]) & 0x3ff;
  if (local_4 == 0x3ff) {
    local_2 = g_qmb_hdr.order[9];
  }
  else {
    local_5 = false;
    for (; (local_5 < 10 && ((local_4 & 1) != 0)); local_4 = local_4 >> 1) {
      local_5 = (bool)(local_5 + 1);
    }
    local_2 = local_5;
  }
  for (local_5 = false; local_5 < 9; local_5 = (bool)(local_5 + 1)) {
    *(undefined1 *)((int)&g_qmb_hdr + (0xc - (uint)local_5)) =
         *(undefined1 *)((int)&g_qmb_hdr + (0xb - (uint)local_5));
  }
  g_qmb_hdr.order[0] = local_2;
  pvVar4 = qmb + local_2;
  if (bVar1) {
    local_10 = &g_opstate.vfo_b;
  }
  else {
    local_10 = &g_opstate.vfo_a;
  }
  for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
    pvVar4->mode = local_10->mode;
    pvVar4 = (vfo_rec *)&pvVar4->flags1;
    local_10 = (vfo_rec *)&local_10->flags1;
  }
  bVar2 = 7 < local_2;
  if (bVar2) {
    local_2 = local_2 - 8;
  }
  local_5 = !bVar2;
  g_qmb_hdr.used_mask_be[local_5] = (byte)(1 << (local_2 & 0x1f)) | g_qmb_hdr.used_mask_be[local_5];
  FUN_fffc3408(bVar1);
  if (g_qmb_hdr.count < 10) {
    g_qmb_hdr.count = g_qmb_hdr.count + 1;
  }
  FUN_fffc34d8(bVar1);
  beep_request(5);
  FUN_fffc33ef();
  PTR_g_ui_00025d54->qmb_pending_slot = g_qmb_hdr.order[0] + 1;
  return;
}


// ===== key_func_press @ fffbfc37 (224 bytes)

/* Front-panel key 0x30F FUNC, press handler (key tables, display/input.md key codes) (#70) */

void key_func_press(void)

{
  int iVar1;
  
  if (PTR_g_ui_00025d54->zz_align_mode == 1) {
    beep_request(1);
    return;
  }
  if (PTR_g_ui_00025d54->dialog_shown == 1) {
    FUN_fffd00ac();
    beep_request(1);
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->dl_req_40 == 1) {
    if (PTR_g_ui_00025d54->dl_req_50 == 1) {
      iVar1 = FUN_fffd1ba6();
      if (iVar1 == 1) {
        beep_request(1);
      }
    }
    else {
      iVar1 = FUN_fffd1abd();
      if (iVar1 == 1) {
        beep_request(1);
      }
    }
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if ((PTR_g_ui_00025d54->playlist_open != 1) && (PTR_g_ui_00025d54->msgmem_open != 1)) {
    if (PTR_g_ui_00025d54->memlist_open == 1) {
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d54->scan_running == 1) {
      scan_stop();
      PTR_g_ui_00025d54->key_consumed = 1;
      return;
    }
    if (PTR_g_ui_00025d54->dl_req_37 == 0) {
      beep_request(1);
      return;
    }
  }
  return;
}


// ===== key_func_short @ fffbfd17 (10 bytes)

/* Front-panel key 0x30F FUNC, short handler (key tables, display/input.md key codes) (#70) */

void key_func_short(void)

{
  DAT_0001b4dd = 1;
  return;
}


// ===== key_func_long @ fffbfd21 (93 bytes)

/* Front-panel key 0x30F FUNC, long handler (key tables, display/input.md key codes) (#70) */

void key_func_long(void)

{
  bool bVar1;
  
  DAT_0001b4de = 1;
  if ((g_opstate.split_on == 1) && (PTR_g_ui_00025d54->txw_on == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (PTR_g_ui_00025d54->zz_align_mode == 1) {
      beep_request(2);
      eeprom_save_cfg105();
      return;
    }
    return;
  }
  beep_request(2);
  FUN_fffc3fef();
  return;
}


// ===== key_func_release @ fffbfd7e (150 bytes)

/* Front-panel key 0x30F FUNC, release handler (key tables, display/input.md key codes) (#70) */

void key_func_release(void)

{
  bool bVar1;
  
  if ((DAT_0001b4dd == '\x01') && (DAT_0001b4de == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((DAT_0001b4dd == '\x01') && (DAT_0001b4de == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (g_ui.memlist_open == 1) {
        memlist_close();
      }
      if (g_opstate.split_on == 1) {
        FUN_fffc1e6f();
      }
      DAT_0001b4dd = 0;
      DAT_0001b4de = 0;
      return;
    }
    return;
  }
  FUN_fffc3a10();
  DAT_0001b4dd = 0;
  DAT_0001b4de = 0;
  return;
}


// ===== key_step_mch_press @ fffbfe14 (74 bytes)

/* Front-panel key 0x310 STEP/MCH, press handler (key tables, display/input.md key codes) (#70) */

void key_step_mch_press(void)

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
  if (g_ui.memlist_open != 1) {
    return;
  }
  memlist_close();
  beep_request(1);
  return;
}


// ===== key_step_mch_short @ fffbfe5e (48 bytes)

/* Front-panel key 0x310 STEP/MCH, short handler (key tables, display/input.md key codes) (#70) */

void key_step_mch_short(void)

{
  if (PTR_g_ui_00025d54->func_panel_open != 1) {
    return;
  }
  PTR_g_ui_00025d54->func_panel_open = 0;
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== key_step_mch_long @ fffbfe8e (91 bytes)

/* Front-panel key 0x310 STEP/MCH, long handler (key tables, display/input.md key codes) (#70) */

void key_step_mch_long(void)

{
  bool bVar1;
  
  bVar1 = g_opstate.active_vfo != VFO_A;
  FUN_fffc3503(bVar1);
  FUN_fffc3582(bVar1);
  FUN_fffc3659(bVar1);
  FUN_fffc3773(bVar1);
  FUN_fffc388d(bVar1);
  vfo_mark_edited(bVar1);
  vfo_store_back(bVar1);
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  beep_request(2);
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== key_fine_fast_press @ fffbfee9 (57 bytes)

/* Front-panel key 0x311 FINE/FAST, press handler (key tables, display/input.md key codes) (#70) */

void key_fine_fast_press(void)

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


// ===== key_fine_fast_short @ fffbff22 (53 bytes)

/* Front-panel key 0x311 FINE/FAST, short handler (key tables, display/input.md key codes) (#70) */

void key_fine_fast_short(void)

{
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (g_opstate.fn_select == 0) {
    g_opstate.fn_select = 1;
    return;
  }
  g_opstate.fn_select = 0;
  return;
}


// ===== key_fine_fast_long @ fffbff57 (60 bytes)

/* Front-panel key 0x311 FINE/FAST, long handler (key tables, display/input.md key codes) (#70) */

void key_fine_fast_long(void)

{
  if (g_ui.memlist_open == 1) {
    memlist_close();
  }
  if (g_opstate.fn_select == 2) {
    g_opstate.fn_select = 0;
  }
  else {
    g_opstate.fn_select = 2;
  }
  beep_request(2);
  return;
}


// ===== key_dsp_press @ fffbff93 (112 bytes)

/* Front-panel key 0x312 DSP, press handler (key tables, display/input.md key codes) (#70) */

void key_dsp_press(void)

{
  int iVar1;
  
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
  if (PTR_g_ui_00025d54->zz_align_mode == 1) {
    iVar1 = align_store();
    if (iVar1 == 1) {
      beep_request(1);
    }
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->func_panel_open == 1) {
    func_display_open();
    return;
  }
  return;
}


// ===== key_dsp_short @ fffc0003 (68 bytes)

/* Front-panel key 0x312 DSP, short handler (key tables, display/input.md key codes) (#70) */

void key_dsp_short(void)

{
  if (PTR_g_ui_00025d54->memlist_open == 1) {
    if (PTR_g_ui_00025d54->memlist_flag != 0) {
      FUN_fffc38fa();
      PTR_g_ui_00025d54->key_consumed = 1;
    }
  }
  else if (PTR_g_ui_00025d54->func_panel_open == 1) {
    PTR_g_ui_00025d54->dsp_key_func_short = 1;
  }
  else {
    PTR_g_ui_00025d54->dsp_key_state = 1;
  }
  vfo_mark_edited_if_vfo();
  return;
}


// ===== key_dsp_long @ fffc0047 (72 bytes)

/* Front-panel key 0x312 DSP, long handler (key tables, display/input.md key codes) (#70) */

void key_dsp_long(void)

{
  if (PTR_g_ui_00025d54->memlist_open == 1) {
    if (PTR_g_ui_00025d54->memlist_flag != 0) {
      return;
    }
    FUN_fffc38fa();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->func_panel_open != 1) {
    PTR_g_ui_00025d54->dsp_key_state = 2;
    return;
  }
  PTR_g_ui_00025d54->dsp_key_func_long = 1;
  beep_request(2);
  return;
}


// ===== key_dsp_release @ fffc008f (385 bytes)

/* Front-panel key 0x312 DSP, release handler (key tables, display/input.md key codes) (#70) */

void key_dsp_release(void)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  
  if (g_ui.zz_align_mode != 1) {
    if (PTR_g_ui_00025d54->func_panel_open == 1) {
      if (PTR_g_ui_00025d54->dsp_key_func_short == 1) {
        if (PTR_g_ui_00025d54->dsp_key_func_long == 1) {
          FUN_fffc4dec();
          PTR_g_ui_00025d54->dsp_key_func_long = 0;
          PTR_g_ui_00025d54->dsp_key_func_short = 0;
        }
        else {
          beep_request(1);
          if (PTR_g_ui_00025d54->dsp_knob_edit == 0) {
            PTR_g_ui_00025d54->func_blink_en = 1;
            swtimer_start(0x45,0x1c2);
            bVar2 = PTR_g_ui_00025d54->dsp_knob_func;
            if (bVar2 == 3) {
              if (PTR_g_ui_00025d54->dsp_knob_apf == 0) {
                FUN_fffbdcb0();
              }
              else {
                FUN_fffbde58();
              }
            }
            else if (bVar2 == 1) {
              FUN_fffbdad5();
            }
            else if (bVar2 == 2) {
              FUN_fffbdb63();
            }
            else if (bVar2 == 0) {
              FUN_fffbda47();
            }
          }
          else {
            PTR_g_ui_00025d54->dsp_knob_edit = 0;
            PTR_g_ui_00025d54->func_blink_en = 0;
            PTR_g_ui_00025d54->func_blink_on = 1;
          }
          PTR_g_ui_00025d54->dsp_key_func_short = 0;
        }
      }
    }
    else if (PTR_g_ui_00025d54->memlist_open == 1) {
      if ((PTR_g_ui_00025d54->memlist_flag == 0) && (PTR_g_ui_00025d54->key_consumed == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_fffc4064();
      }
    }
    else if (PTR_g_ui_00025d54->dsp_key_state != 2) {
      bVar2 = vfo_mode(0);
      uVar3 = (uint)bVar2;
      if ((uVar3 - 6 < 2) || (uVar3 == 10 || uVar3 == 0xb)) {
        beep_request(3);
        PTR_g_ui_00025d54->key_consumed = 1;
      }
      else {
        beep_request(1);
        func_display_open();
        PTR_g_ui_00025d54->func_knob_item = 0x1d;
      }
    }
    PTR_g_ui_00025d54->dsp_key_state = 0;
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  return;
}


// ===== FUN_fffc0210 @ fffc0210 (289 bytes)

void FUN_fffc0210(void)

{
  if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->ch_step_mode == 1) {
    beep_request(6);
    PTR_g_ui_00025d54->ch_step_mode = 0;
    PTR_g_ui_00025d54->mic_key_hold = 0;
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->dvs_armed == 1) {
    PTR_g_ui_00025d54->dvs_busy = 0;
    PTR_g_ui_00025d54->dvs_armed = 0;
    PTR_g_ui_00025d54->dvs_state = 2;
    PTR_g_ui_00025d54->msg_tx_wait = 0;
    PTR_g_ui_00025d54->msg_playing = 1;
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->dvs_busy == 1) {
    PTR_g_ui_00025d54->dvs_busy = 0;
    PTR_g_ui_00025d54->msg_tx_wait = 0;
    PTR_g_ui_00025d54->msg_slot = 0;
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->dvs_state == 1) {
    PTR_g_ui_00025d54->msg_playing = 0;
    PTR_g_ui_00025d54->msg_state_1d0 = 1;
  }
  PTR_g_ui_00025d54->ptt_mic = 1;
  return;
}


// ===== FUN_fffc0331 @ fffc0331 (1 bytes)

void FUN_fffc0331(void)

{
  return;
}


// ===== FUN_fffc0332 @ fffc0332 (1 bytes)

void FUN_fffc0332(void)

{
  return;
}


// ===== FUN_fffc0333 @ fffc0333 (1 bytes)

void FUN_fffc0333(void)

{
  return;
}


// ===== FUN_fffc0334 @ fffc0334 (1 bytes)

void FUN_fffc0334(void)

{
  return;
}


// ===== FUN_fffc0335 @ fffc0335 (14 bytes)

void FUN_fffc0335(void)

{
  key_slot_press(g_opstate.ex030124_mic_up);
  return;
}


// ===== FUN_fffc0343 @ fffc0343 (14 bytes)

void FUN_fffc0343(void)

{
  key_slot_short(g_opstate.ex030124_mic_up);
  return;
}


// ===== FUN_fffc0351 @ fffc0351 (14 bytes)

void FUN_fffc0351(void)

{
  key_slot_long(g_opstate.ex030124_mic_up);
  return;
}


// ===== FUN_fffc035f @ fffc035f (14 bytes)

void FUN_fffc035f(void)

{
  key_slot_repeat(g_opstate.ex030124_mic_up);
  return;
}


// ===== FUN_fffc036d @ fffc036d (14 bytes)

void FUN_fffc036d(void)

{
  key_slot_release(g_opstate.ex030124_mic_up);
  return;
}


// ===== FUN_fffc037b @ fffc037b (14 bytes)

void FUN_fffc037b(void)

{
  key_slot_press(g_opstate.ex030125_mic_down);
  return;
}


// ===== FUN_fffc0389 @ fffc0389 (14 bytes)

void FUN_fffc0389(void)

{
  key_slot_short(g_opstate.ex030125_mic_down);
  return;
}


// ===== FUN_fffc0397 @ fffc0397 (14 bytes)

void FUN_fffc0397(void)

{
  key_slot_long(g_opstate.ex030125_mic_down);
  return;
}


// ===== FUN_fffc03a5 @ fffc03a5 (14 bytes)

void FUN_fffc03a5(void)

{
  key_slot_repeat(g_opstate.ex030125_mic_down);
  return;
}


// ===== FUN_fffc03b3 @ fffc03b3 (14 bytes)

void FUN_fffc03b3(void)

{
  key_slot_release(g_opstate.ex030125_mic_down);
  return;
}


// ===== FUN_fffc03c1 @ fffc03c1 (13 bytes)

void FUN_fffc03c1(void)

{
  PTR_g_ui_00025d54->spk_off_req = 1;
  return;
}


// ===== FUN_fffc03ce @ fffc03ce (1 bytes)

void FUN_fffc03ce(void)

{
  return;
}


// ===== FUN_fffc03cf @ fffc03cf (13 bytes)

void FUN_fffc03cf(void)

{
  PTR_g_ui_00025d54->spk_off_req = 0;
  return;
}


// ===== FUN_fffc03dc @ fffc03dc (14 bytes)

void FUN_fffc03dc(void)

{
  key_slot_press(g_opstate.ex030120_mic_p1);
  return;
}


// ===== FUN_fffc03ea @ fffc03ea (14 bytes)

void FUN_fffc03ea(void)

{
  key_slot_short(g_opstate.ex030120_mic_p1);
  return;
}


// ===== FUN_fffc03f8 @ fffc03f8 (14 bytes)

void FUN_fffc03f8(void)

{
  key_slot_long(g_opstate.ex030120_mic_p1);
  return;
}


// ===== FUN_fffc0406 @ fffc0406 (14 bytes)

void FUN_fffc0406(void)

{
  key_slot_repeat(g_opstate.ex030120_mic_p1);
  return;
}


// ===== FUN_fffc0414 @ fffc0414 (14 bytes)

void FUN_fffc0414(void)

{
  key_slot_release(g_opstate.ex030120_mic_p1);
  return;
}


// ===== FUN_fffc0422 @ fffc0422 (14 bytes)

void FUN_fffc0422(void)

{
  key_slot_press(g_opstate.ex030121_mic_p2);
  return;
}


// ===== FUN_fffc0430 @ fffc0430 (14 bytes)

void FUN_fffc0430(void)

{
  key_slot_short(g_opstate.ex030121_mic_p2);
  return;
}


// ===== FUN_fffc043e @ fffc043e (14 bytes)

void FUN_fffc043e(void)

{
  key_slot_long(g_opstate.ex030121_mic_p2);
  return;
}


// ===== FUN_fffc044c @ fffc044c (14 bytes)

void FUN_fffc044c(void)

{
  key_slot_repeat(g_opstate.ex030121_mic_p2);
  return;
}


// ===== FUN_fffc045a @ fffc045a (14 bytes)

void FUN_fffc045a(void)

{
  key_slot_release(g_opstate.ex030121_mic_p2);
  return;
}


// ===== FUN_fffc0468 @ fffc0468 (14 bytes)

void FUN_fffc0468(void)

{
  key_slot_press(g_opstate.ex030122_mic_p3);
  return;
}


// ===== FUN_fffc0476 @ fffc0476 (14 bytes)

void FUN_fffc0476(void)

{
  key_slot_short(g_opstate.ex030122_mic_p3);
  return;
}


// ===== FUN_fffc0484 @ fffc0484 (14 bytes)

void FUN_fffc0484(void)

{
  key_slot_long(g_opstate.ex030122_mic_p3);
  return;
}


// ===== FUN_fffc0492 @ fffc0492 (14 bytes)

void FUN_fffc0492(void)

{
  key_slot_repeat(g_opstate.ex030122_mic_p3);
  return;
}

