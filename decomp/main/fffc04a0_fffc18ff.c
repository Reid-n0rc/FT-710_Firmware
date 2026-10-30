// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc04a0 @ fffc04a0 (14 bytes)

void FUN_fffc04a0(void)

{
  key_slot_release(g_opstate.ex030122_mic_p3);
  return;
}


// ===== FUN_fffc04ae @ fffc04ae (14 bytes)

void FUN_fffc04ae(void)

{
  key_slot_press(g_opstate.ex030123_mic_p4);
  return;
}


// ===== FUN_fffc04bc @ fffc04bc (14 bytes)

void FUN_fffc04bc(void)

{
  key_slot_short(g_opstate.ex030123_mic_p4);
  return;
}


// ===== FUN_fffc04ca @ fffc04ca (14 bytes)

void FUN_fffc04ca(void)

{
  key_slot_long(g_opstate.ex030123_mic_p4);
  return;
}


// ===== FUN_fffc04d8 @ fffc04d8 (14 bytes)

void FUN_fffc04d8(void)

{
  key_slot_repeat(g_opstate.ex030123_mic_p4);
  return;
}


// ===== FUN_fffc04e6 @ fffc04e6 (14 bytes)

void FUN_fffc04e6(void)

{
  key_slot_release(g_opstate.ex030123_mic_p4);
  return;
}


// ===== FUN_fffc052b @ fffc052b (108 bytes)

void FUN_fffc052b(byte param_1)

{
  byte bVar1;
  uint uVar2;
  
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  if (g_opstate.scope_mode == 2) {
    uVar2 = vfo_freq(VFO_RX,VFO_SIDE_SEL);
    bVar1 = freq_range_index(uVar2);
    g_opstate.scope_span_idx_b[bVar1] = param_1;
    return;
  }
  uVar2 = vfo_freq_clar(VFO_RX,VFO_SIDE_SEL);
  bVar1 = freq_range_index(uVar2);
  if (bVar1 == 0xff) {
    return;
  }
  g_opstate.scope_span_idx_a[bVar1] = param_1;
  return;
}


// ===== FUN_fffc06ab @ fffc06ab (18 bytes)

void FUN_fffc06ab(void)

{
  popup_mark_clear();
  PTR_g_ui_00025d54->popup_sel = 1;
  return;
}


// ===== popup_open_2000 @ fffc078d (13 bytes)

/* popup_mark_start, then popup_open_timed(2000) [fact] */

void popup_open_2000(void)

{
  popup_mark_start();
  popup_open_timed(2000);
  return;
}


// ===== FUN_fffc0948 @ fffc0948 (132 bytes)

void FUN_fffc0948(byte *param_1,char param_2)

{
  uint uVar1;
  bool bVar2;
  byte *local_c;
  
  bVar2 = false;
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_c = param_1 + 0x15;
      goto LAB_fffc09ae;
    }
    if (uVar1 - 4 < 2) {
      local_c = param_1 + 0x33;
      goto LAB_fffc09ae;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        local_c = param_1 + 0x1f;
      }
      else if (uVar1 < 2) {
        local_c = param_1 + 0xb;
      }
      else {
        bVar2 = true;
      }
      goto LAB_fffc09ae;
    }
  }
  local_c = param_1 + 0x29;
LAB_fffc09ae:
  if (bVar2) {
    return;
  }
  if (param_2 == '\0') {
    *local_c = *local_c & 0x7f;
    return;
  }
  *local_c = *local_c & 0x7f | 0x80;
  return;
}


// ===== FUN_fffc0a49 @ fffc0a49 (139 bytes)

void FUN_fffc0a49(byte *param_1,undefined1 param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      FUN_fffc0ad4(param_1 + 0x15,param_2);
      return;
    }
    if (uVar1 - 4 < 2) {
      FUN_fffc0ad4(param_1 + 0x33,param_2);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc0ac6;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          FUN_fffc0ad4(param_1 + 0x1f,param_2);
          return;
        }
        if (uVar1 < 2) {
          FUN_fffc0ad4(param_1 + 0xb,param_2);
          return;
        }
        return;
      }
    }
    FUN_fffc0ad4(param_1 + 0x3d,param_2);
    return;
  }
LAB_fffc0ac6:
  FUN_fffc0ad4(param_1 + 0x29,param_2);
  return;
}


// ===== FUN_fffc0ad4 @ fffc0ad4 (91 bytes)

void FUN_fffc0ad4(byte *param_1,char param_2)

{
  if (param_2 == '\x04') {
    *param_1 = *param_1 | 0x70;
    return;
  }
  if (param_2 == '\x01') {
    *param_1 = *param_1 & 0xcf | 0x40;
    return;
  }
  if (param_2 == '\x02') {
    *param_1 = *param_1 & 0xdf | 0x50;
    return;
  }
  if (param_2 == '\x03') {
    *param_1 = *param_1 & 0xef | 0x60;
    return;
  }
  if (param_2 != '\0') {
    return;
  }
  *param_1 = *param_1 & 0xbf;
  return;
}


// ===== ui_softkey_dispatch @ fffc0b2f (352 bytes)

/* (key): dialog (+0x86): scan_stop + FUN_fffd0046(key); keyboard (+0x88): FUN_fffcfaa9; PlayList /
   message-screen guards; with a pop-up shown (+0x1C1) and code +0x1C2 <= 0x0D: handler table
   0xFFF89D54[code](key); otherwise +0x409 = 1 (key consumed). 116 soft-key handlers call it [fact]
    */

void ui_softkey_dispatch(ushort param_1)

{
  bool bVar1;
  char cVar2;
  radio_mode rVar3;
  
  if (PTR_g_ui_00025d54->dialog_shown == 1) {
    scan_stop();
    FUN_fffd0046(param_1);
    beep_request(1);
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->dl_req_50 == 1) {
    cVar2 = FUN_fffcfaa9(param_1);
    if (cVar2 == '\0') {
      PTR_g_ui_00025d54->key_consumed = 1;
      return;
    }
    if (cVar2 == '\x01') {
      beep_request(1);
      PTR_g_ui_00025d54->key_consumed = 1;
      return;
    }
    return;
  }
  if (PTR_g_ui_00025d54->playlist_open == 1) {
    beep_request(1);
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->msgmem_open == 1) {
    if (PTR_g_ui_00025d54->msg_active == 1) {
      PTR_g_ui_00025d54->msg_active = 0;
      beep_request(1);
    }
    else {
      if ((param_1 < 0x87) || (0x8b < param_1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        rVar3 = vfo_mode(VFO_RX);
        if ((rVar3 == MODE_CW_L) || (rVar3 == MODE_CW_U)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          beep_request(1);
          return;
        }
      }
    }
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (PTR_g_ui_00025d54->dl_req_popup_b == 0) {
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (0xd < PTR_g_ui_00025d54->popup_code) {
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  (*(code *)(&PTR_LAB_fff89d54)[PTR_g_ui_00025d54->popup_code])(param_1);
  return;
}


// ===== FUN_fffc0c8f @ fffc0c8f (164 bytes)

void FUN_fffc0c8f(ushort param_1)

{
  bool bVar1;
  
  if ((param_1 < 0x77) || (0x86 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    popup_open_timed(1000);
    switch(param_1) {
    case 0x77:
      FUN_fffc0d33(MODE_LSB);
      return;
    case 0x78:
      FUN_fffc0d33(MODE_USB);
      return;
    case 0x79:
      FUN_fffc0d33(MODE_CW_L);
      return;
    case 0x7a:
      FUN_fffc0d33(MODE_CW_U);
      return;
    case 0x7b:
      FUN_fffc0e31();
      return;
    case 0x7c:
      FUN_fffc0e3e();
      return;
    case 0x7d:
      FUN_fffc0e4b();
      return;
    case 0x7e:
      FUN_fffc0e58();
      return;
    case 0x7f:
      FUN_fffc0d33(MODE_DATA_L);
      return;
    case 0x80:
      FUN_fffc0d33(MODE_DATA_U);
      return;
    case 0x81:
      FUN_fffc0e65();
      return;
    case 0x82:
      FUN_fffc0e72();
      return;
    case 0x83:
      FUN_fffc0d33(MODE_RTTY_L);
      return;
    case 0x84:
      FUN_fffc0d33(MODE_RTTY_U);
      return;
    case 0x85:
      FUN_fffc0d33(MODE_PSK);
      return;
    case 0x86:
      FUN_fffc0e7f();
      return;
    }
  }
  return;
}


// ===== FUN_fffc0d33 @ fffc0d33 (54 bytes)

void FUN_fffc0d33(radio_mode mode)

{
  int iVar1;
  
  iVar1 = vfo_edit_begin();
  if (iVar1 == 1) {
    vfo_mode_set(mode);
    if (PTR_g_ui_00025d54->dl_req_popup_b == 1) {
      beep_request(1);
    }
    PTR_g_ui_00025d54->popup_cursor = mode;
    return;
  }
  return;
}


// ===== vfo_edit_begin @ fffc0d69 (142 bytes)

/* Returns 0 while a message plays (+0x417) or +0x67; stops a scan; memory state -> memory tune
   unless a special channel; returns 1 [fact] */

undefined1 vfo_edit_begin(void)

{
  byte bVar1;
  undefined1 local_4;
  bool local_3;
  vfo_state local_2;
  
  if (PTR_g_ui_00025d54->dvs_busy == 1) {
    local_4 = 0;
  }
  else if (PTR_g_ui_00025d54->scan_running == 1) {
    scan_stop();
    local_4 = 0;
  }
  else if (PTR_g_ui_00025d54->transmitting == 1) {
    local_4 = 0;
  }
  else {
    if (g_opstate.active_vfo == VFO_A) {
      local_2 = g_opstate.vfo_state_a;
    }
    else {
      local_2 = g_opstate.vfo_state_b;
    }
    local_3 = g_opstate.active_vfo != VFO_A;
    if (local_2 == VFO_STATE_MEMORY) {
      bVar1 = memch_current_is_special(local_3);
      if (bVar1 == 1) {
        return 0;
      }
      vfo_enter_memtune_state(local_3);
    }
    local_4 = 1;
  }
  return local_4;
}


// ===== mode_popup_select @ fffc0df7 (58 bytes)

/* (mode): +0x1D1 = 0, vfo_mode_set, beep while a pop-up is shown, mode cursor +0x424 = mode [fact]
    */

void mode_popup_select(radio_mode param_1)

{
  PTR_g_ui_00025d54->msg_active = 0;
  vfo_mode_set(param_1);
  if (PTR_g_ui_00025d54->dl_req_popup_b == 1) {
    beep_request(1);
  }
  PTR_g_ui_00025d54->popup_cursor = param_1;
  return;
}


// ===== FUN_fffc0e31 @ fffc0e31 (13 bytes)

void FUN_fffc0e31(void)

{
  int iVar1;
  
  iVar1 = vfo_edit_begin();
  if (iVar1 != 1) {
    return;
  }
  mode_popup_select(4);
  return;
}


// ===== FUN_fffc0e3e @ fffc0e3e (13 bytes)

void FUN_fffc0e3e(void)

{
  int iVar1;
  
  iVar1 = vfo_edit_begin();
  if (iVar1 != 1) {
    return;
  }
  mode_popup_select(5);
  return;
}


// ===== FUN_fffc0e4b @ fffc0e4b (13 bytes)

void FUN_fffc0e4b(void)

{
  int iVar1;
  
  iVar1 = vfo_edit_begin();
  if (iVar1 != 1) {
    return;
  }
  mode_popup_select(6);
  return;
}


// ===== FUN_fffc0e58 @ fffc0e58 (13 bytes)

void FUN_fffc0e58(void)

{
  int iVar1;
  
  iVar1 = vfo_edit_begin();
  if (iVar1 != 1) {
    return;
  }
  mode_popup_select(7);
  return;
}


// ===== FUN_fffc0e65 @ fffc0e65 (13 bytes)

void FUN_fffc0e65(void)

{
  int iVar1;
  
  iVar1 = vfo_edit_begin();
  if (iVar1 != 1) {
    return;
  }
  mode_popup_select(10);
  return;
}


// ===== FUN_fffc0e72 @ fffc0e72 (13 bytes)

void FUN_fffc0e72(void)

{
  int iVar1;
  
  iVar1 = vfo_edit_begin();
  if (iVar1 != 1) {
    return;
  }
  mode_popup_select(0xb);
  return;
}


// ===== FUN_fffc0e7f @ fffc0e7f (57 bytes)

void FUN_fffc0e7f(void)

{
  popup_open_timed(3000);
  g_opstate.preset_on = g_opstate.preset_on == 0;
  sci3_set_baud();
  beep_request(1);
  return;
}


// ===== vfo_mode_set @ fffc0eb8 (88 bytes)

/* (mode): active record rec+0 = rec+0 & 0xF0 | mode, FUN_fffc0f10(old, new, rec), UI +0x40B = 1
   [fact] */

void vfo_mode_set(radio_mode mode)

{
  radio_mode rVar1;
  vfo_rec *local_8;
  
  if (g_opstate.active_vfo == VFO_A) {
    local_8 = &g_opstate.vfo_a;
  }
  else {
    local_8 = &g_opstate.vfo_b;
  }
  rVar1 = local_8->mode;
  local_8->mode = rVar1 & ~MODE_15 | mode;
  FUN_fffc0f10(rVar1 & MODE_15,mode,&local_8->mode);
  PTR_g_ui_00025d54->vfo_refresh_req = 1;
  return;
}


// ===== FUN_fffc0f10 @ fffc0f10 (188 bytes)

void FUN_fffc0f10(radio_mode old_mode,radio_mode new_mode,byte *rec)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (g_opstate.ex020118_cw_freq_display != 0) {
    uVar1 = (uint)old_mode;
    if (uVar1 - 4 < 0xb) {
      if (new_mode == MODE_USB) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,rec);
        return;
      }
      if (new_mode == MODE_LSB) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,rec);
        return;
      }
    }
    else if (uVar1 == 1) {
      if (new_mode - 2 < 0xd) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,rec);
        return;
      }
      if (new_mode == 0) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(iVar3 << 1,rec);
        return;
      }
    }
    else if (uVar1 - 2 < 2) {
      if (new_mode == MODE_USB) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,rec);
        return;
      }
      if (new_mode == MODE_LSB) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,rec);
        return;
      }
    }
    else if (uVar1 == 0) {
      if (new_mode - 2 < 0xd) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,rec);
        return;
      }
      if (new_mode == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(iVar3 * -2,rec);
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffc0fcc @ fffc0fcc (225 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc0fe3) */
/* WARNING: Removing unreachable block (ram,0xfffc0fee) */

void FUN_fffc0fcc(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  uint local_c;
  
  if (param_1 != 0) {
    local_c = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                         *(undefined1 *)(param_2 + 0x4b)),
                                *(undefined1 *)(param_2 + 0x4c)),*(undefined1 *)(param_2 + 0x4d));
    if ((local_c < 0x3b9ac9f7) && (param_1 < 0x3b9ac9f7)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (param_1 < -0x3b9ac9f6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_c = local_c + param_1;
      if ((int)local_c < 0) {
        local_c = 0;
      }
      DAT_0001b4e1 = 1;
      uVar2 = freq_clamp(param_2 != 0x9d09,local_c);
      DAT_0001b4e1 = 0;
      *(char *)(param_2 + 0x4a) = (char)(uVar2 >> 0x18);
      *(char *)(param_2 + 0x4b) = (char)(uVar2 >> 0x10);
      *(char *)(param_2 + 0x4c) = (char)(uVar2 >> 8);
      local_c._0_1_ = (undefined1)uVar2;
      *(undefined1 *)(param_2 + 0x4d) = (undefined1)local_c;
      vfo_mark_tuned(param_2 != 0x9d09);
      return;
    }
  }
  return;
}


// ===== FUN_fffc10ad @ fffc10ad (22 bytes)

void FUN_fffc10ad(void)

{
  return;
}


// ===== freq_clamp @ fffc10c3 (229 bytes)

/* (side, f): clamp/wrap to 30k..75M (0xFFF89D4C) or PMS limits 0x20F74/78; returns f */

uint freq_clamp(char param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint local_10 [2];
  uint local_8;
  char local_1;
  
  PTR_g_ui_00025d54->freq_rejected = 0;
  local_10[0] = param_2;
  local_8 = param_2;
  local_1 = param_1;
  if (param_1 == '\0') {
    if (g_opstate.vfo_state_a == VFO_STATE_PMS) {
      if ((g_ui.pms_lo == 0) || (g_ui.pms_hi == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        pms_load_limits(0);
      }
      uVar3 = freq_clamp_pms(local_10[0]);
      return uVar3;
    }
  }
  else if (g_opstate.vfo_state_b == VFO_STATE_PMS) {
    if ((g_ui.pms_lo == 0) || (g_ui.pms_hi == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      pms_load_limits(param_1);
    }
    uVar3 = freq_clamp_pms(local_10[0]);
    return uVar3;
  }
  bVar2 = range_cmp3(local_10,(uint *)&tune_limits);
  if (bVar2 == 0) {
    freq_fix_below(local_10,&tune_limits);
  }
  else if (bVar2 == 1) {
    freq_fix_above(local_10,&tune_limits);
  }
  return local_10[0];
}


// ===== freq_clamp_pms @ fffc11a8 (178 bytes)

/* PMS-limit variant of freq_clamp */

uint freq_clamp_pms(uint param_1)

{
  bool bVar1;
  uint uStack_10;
  byte bStack_9;
  uint local_4;
  
  local_4 = param_1;
  bStack_9 = range_cmp3(&local_4,&PTR_g_ui_00025d54->pms_lo);
  uStack_10 = local_4;
  if (bStack_9 == 0) {
    if ((PTR_g_ui_00025d54->pms_inhibit == 1) || (DAT_0001b4e2 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_g_ui_00025d54->freq_rejected = 1;
    }
    else {
      freq_fix_below(&uStack_10,&PTR_g_ui_00025d54->pms_lo);
    }
  }
  else if (bStack_9 == 1) {
    if ((PTR_g_ui_00025d54->pms_inhibit == 1) || (DAT_0001b4e2 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_g_ui_00025d54->freq_rejected = 1;
    }
    else {
      freq_fix_above(&uStack_10,&PTR_g_ui_00025d54->pms_lo);
    }
  }
  return uStack_10;
}


// ===== vfo_mark_tuned @ fffc125a (33 bytes)

/* rt+0x444/0x446 = 1, QMB state -> VFO */

void vfo_mark_tuned(byte param_1)

{
  if (param_1 == 0) {
    PTR_g_ui_00025d54->tuned_a = 1;
  }
  else {
    PTR_g_ui_00025d54->tuned_b = 1;
  }
  qmb_exit_to_vfo(param_1);
  return;
}


// ===== qmb_exit_to_vfo @ fffc127b (144 bytes)

/* state 5 -> 1 */

void qmb_exit_to_vfo(byte param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if ((g_opstate.vfo_state_a == VFO_STATE_PMS) || (g_opstate.vfo_state_a != VFO_STATE_MEMTUNE)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (g_opstate.vfo_state_a == VFO_STATE_QMB)) {
      g_opstate.vfo_state_a = VFO_STATE_VFO;
      return;
    }
  }
  else {
    if ((g_opstate.vfo_state_b == VFO_STATE_PMS) || (g_opstate.vfo_state_b != VFO_STATE_MEMTUNE)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (g_opstate.vfo_state_b == VFO_STATE_QMB)) {
      g_opstate.vfo_state_b = VFO_STATE_VFO;
      return;
    }
  }
  return;
}


// ===== freq_fix_below @ fffc130b (109 bytes)

/* Below-limit handling (clamp, or wrap while scanning) */

void freq_fix_below(void *param_1,void *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_g_ui_00025d54->digit_step_on == 1) {
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return;
  }
  if (PTR_g_ui_00025d54->step_fast_req != 1) {
    if (PTR_g_ui_00025d54->scan_running != 1) {
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
      return;
    }
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
    return;
  }
  FUN_fffc142c(param_1,param_2);
  return;
}


// ===== freq_fix_above @ fffc1378 (111 bytes)

/* Above-limit handling (clamp, or wrap while scanning) */

void freq_fix_above(void *param_1,void *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_g_ui_00025d54->digit_step_on == 1) {
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
    return;
  }
  if (PTR_g_ui_00025d54->step_fast_req != 1) {
    if (PTR_g_ui_00025d54->scan_running != 1) {
      *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
      return;
    }
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return;
  }
  FUN_fffc14c6(param_1,param_2);
  return;
}


// ===== FUN_fffc13e7 @ fffc13e7 (69 bytes)

undefined1 FUN_fffc13e7(void)

{
  undefined1 uVar1;
  
  PTR_g_ui_00025d54->freq_rejected = 1;
  if ((PTR_g_ui_00025d54->pms_inhibit == 1) || (DAT_0001b4e2 == '\x01')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_fffc142c @ fffc142c (41 bytes)

void FUN_fffc142c(uint *param_1,int param_2)

{
  undefined4 uStack_c;
  
  uStack_c = FUN_fffc1455(param_1,*(undefined4 *)(param_2 + 4));
  if (*(uint *)(param_2 + 4) < uStack_c) {
    uStack_c = uStack_c - 100000;
  }
  *param_1 = uStack_c;
  return;
}


// ===== FUN_fffc1455 @ fffc1455 (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc1470) */
/* WARNING: Removing unreachable block (ram,0xfffc149c) */
/* WARNING: Removing unreachable block (ram,0xfffc14ab) */
/* WARNING: Removing unreachable block (ram,0xfffc147f) */

void FUN_fffc1455(void)

{
  return;
}


// ===== FUN_fffc14c6 @ fffc14c6 (75 bytes)

void FUN_fffc14c6(int *param_1,undefined4 *param_2)

{
  undefined *puStack_c;
  
  if (*param_1 < 0) {
    *param_1 = (int)(&DAT_000186a0 + *param_1);
    FUN_fffc142c(param_1,param_2);
    return;
  }
  puStack_c = (undefined *)FUN_fffc1455(param_1,*param_2);
  if (puStack_c < (undefined *)*param_2) {
    puStack_c = &DAT_000186a0 + (int)puStack_c;
  }
  *param_1 = (int)puStack_c;
  return;
}


// ===== FUN_fffc151d @ fffc151d (183 bytes)

void FUN_fffc151d(ushort param_1)

{
  bool bVar1;
  
  if ((param_1 < 0x6b) || (0x76 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    PTR_g_ui_00025d54->band_popup_pick = 1;
    PTR_g_ui_00025d54->popup_band = (char)param_1 + 0x95;
    PTR_g_ui_00025d54->popup_cursor = PTR_g_ui_00025d54->popup_band;
    if (g_opstate.split_on == 1) {
      g_opstate.split_on = 0;
      g_opstate.vfo_state_a = PTR_g_ui_00025d54->split_saved_state_a;
      g_opstate.vfo_state_b = PTR_g_ui_00025d54->split_saved_state_b;
      PTR_g_ui_00025d54->txw_on = 0;
      g_ui.txw_swap = 0;
    }
    popup_open_timed(1000);
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc15d4 @ fffc15d4 (49 bytes)

void FUN_fffc15d4(void)

{
  if ((PTR_g_ui_00025d54->band_popup_pick == 1) && (PTR_g_ui_00025d54->popup_code == 0xc)) {
    FUN_fffc1605(PTR_g_ui_00025d54->popup_cursor);
    return;
  }
  return;
}


// ===== FUN_fffc1605 @ fffc1605 (32 bytes)

void FUN_fffc1605(byte param_1)

{
  PTR_g_ui_00025d54->band_popup_pick = 1;
  if (0xb < param_1) {
    return;
  }
  FUN_fffc1625(param_1);
  return;
}


// ===== FUN_fffc1625 @ fffc1625 (62 bytes)

void FUN_fffc1625(band_idx param_1)

{
  if (PTR_g_ui_00025d54->scan_running != 1) {
    menu_close_if_open();
    func_panel_close();
    popup8_close();
    ui_clear_415_423();
    band_select(param_1);
    tuner_rearm();
    return;
  }
  scan_stop();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== band_select @ fffc1663 (147 bytes)

/* Band key on the active side; 0x20F28 = min(band,11); dispatch by state */

void band_select(band_idx param_1)

{
  vfo_state local_3;
  bool local_2;
  
  if (param_1 < BAND_GEN) {
    PTR_g_ui_00025d54->popup_cursor = param_1;
  }
  else {
    PTR_g_ui_00025d54->popup_cursor = 0xb;
  }
  if (g_opstate.active_vfo == VFO_A) {
    local_3 = g_opstate.vfo_state_a;
    g_ui.clar_flags_a = 0;
  }
  else {
    local_3 = g_opstate.vfo_state_b;
    g_ui.clar_flags_b = 0;
  }
  local_2 = g_opstate.active_vfo != VFO_A;
  vfo_store_back(local_2);
  if (local_3 == VFO_STATE_PMS) {
    band_select_pms(local_2,param_1);
    return;
  }
  if (local_3 == VFO_STATE_MEMTUNE) {
    band_select_memtune(local_2,param_1);
    return;
  }
  if (local_3 != VFO_STATE_MEMORY) {
    band_select_vfo(local_2,param_1);
    return;
  }
  band_select_mem(local_2,param_1);
  return;
}


// ===== vfo_store_back @ fffc16f6 (233 bytes)

/* Store operating record back (band stack / memory-tune backup) according to state */

void vfo_store_back(byte param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if (PTR_g_ui_00025d54->edited_a == 0) {
      FUN_fffc17df();
      return;
    }
    PTR_g_ui_00025d54->edited_a = 0;
    if (PTR_g_ui_00025d54->force_bandstack_a == 1) {
      FUN_fffc18bf();
      return;
    }
    if ((g_opstate.vfo_state_a == VFO_STATE_MEMTUNE) || (g_opstate.vfo_state_a == VFO_STATE_PMS)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc18c3();
      return;
    }
    if (g_opstate.vfo_state_a != VFO_STATE_MEMORY) {
      FUN_fffc18bf();
      return;
    }
  }
  else {
    if (PTR_g_ui_00025d54->edited_b == 0) {
      FUN_fffc184f();
      return;
    }
    PTR_g_ui_00025d54->edited_b = 0;
    if (PTR_g_ui_00025d54->force_bandstack_b == 1) {
      FUN_fffc18bf();
      return;
    }
    if ((g_opstate.vfo_state_b == VFO_STATE_MEMTUNE) || (g_opstate.vfo_state_b == VFO_STATE_PMS)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc18e1();
      return;
    }
    if (g_opstate.vfo_state_b != VFO_STATE_MEMORY) {
      FUN_fffc18bf();
      return;
    }
  }
  return;
}


// ===== FUN_fffc17df @ fffc17df (112 bytes)

void FUN_fffc17df(void)

{
  bool bVar1;
  
  PTR_g_ui_00025d54->edited_a = 0;
  PTR_g_ui_00025d54->tuned_a = 0;
  if (PTR_g_ui_00025d54->force_bandstack_a == 1) {
    bandstack_save();
    return;
  }
  if ((g_opstate.vfo_state_a == VFO_STATE_MEMTUNE) || (g_opstate.vfo_state_a == VFO_STATE_PMS)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (g_opstate.vfo_state_a != VFO_STATE_MEMORY) {
      bandstack_save();
      return;
    }
    return;
  }
  FUN_fffc1a0d();
  return;
}


// ===== FUN_fffc184f @ fffc184f (112 bytes)

void FUN_fffc184f(void)

{
  bool bVar1;
  
  PTR_g_ui_00025d54->edited_b = 0;
  PTR_g_ui_00025d54->tuned_b = 0;
  if (PTR_g_ui_00025d54->force_bandstack_b == 1) {
    bandstack_save();
    return;
  }
  if ((g_opstate.vfo_state_b == VFO_STATE_MEMTUNE) || (g_opstate.vfo_state_b == VFO_STATE_PMS)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (g_opstate.vfo_state_b != VFO_STATE_MEMORY) {
      bandstack_save();
      return;
    }
    return;
  }
  FUN_fffc1a35();
  return;
}


// ===== FUN_fffc18bf @ fffc18bf (4 bytes)

void FUN_fffc18bf(void)

{
  bandstack_save();
  return;
}


// ===== FUN_fffc18c3 @ fffc18c3 (30 bytes)

void FUN_fffc18c3(void)

{
  memtune_backup_a();
  PTR_g_ui_00025d54->memtune_valid_a = 1;
  PTR_g_ui_00025d54->memtune_backup_a = 1;
  return;
}


// ===== FUN_fffc18e1 @ fffc18e1 (30 bytes)

void FUN_fffc18e1(void)

{
  memtune_backup_b();
  PTR_g_ui_00025d54->memtune_valid_b = 1;
  PTR_g_ui_00025d54->memtune_backup_b = 1;
  return;
}


// ===== memtune_backup_a @ fffc18ff (20 bytes)

/* 0x9D09 -> 0x9DCE */

void memtune_backup_a(void)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  pvVar2 = &g_opstate.vfo_a;
  pvVar1 = &g_opstate.memtune_a;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    pvVar1->mode = pvVar2->mode;
    pvVar1 = (vfo_rec *)&pvVar1->flags1;
    pvVar2 = (vfo_rec *)&pvVar2->flags1;
  }
  return;
}

