// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc29f3 @ fffc29f3 (74 bytes)

void FUN_fffc29f3(void)

{
  byte bVar1;
  
  PTR_g_ui_00025d54->memlist_open = 1;
  PTR_g_ui_00025d54->memlist_flag = 0;
  PTR_g_ui_00025d54->memlist_popup55 = 0;
  bVar1 = memch_current(g_opstate.active_vfo != VFO_A);
  FUN_fffc2a3d(bVar1);
  return;
}


// ===== FUN_fffc2a3d @ fffc2a3d (213 bytes)

void FUN_fffc2a3d(byte param_1)

{
  ushort uVar1;
  char cStack_3;
  byte bStack_2;
  
  uVar1 = dest_code_get();
  if ((uVar1 != 0x20b) && (uVar1 != 0x1cb9)) {
    if (uVar1 == 0xd950) {
LAB_fffc2aa2:
      cStack_3 = '\0';
      bStack_2 = 0x78;
      goto LAB_fffc2ad2;
    }
    if (uVar1 != 0x4380) {
      if (uVar1 != 0x50e2) {
        if (uVar1 == 0x60e6) goto LAB_fffc2aaa;
        if (((uVar1 == 0xa4c5) || (uVar1 == 0xa983)) || (uVar1 == 0xb5a7)) goto LAB_fffc2aa2;
        if (uVar1 != 0x315b) {
          cStack_3 = '\0';
          bStack_2 = 0x71;
          goto LAB_fffc2ad2;
        }
      }
      cStack_3 = '\0';
      bStack_2 = 0x80;
      if (g_opstate.ex030406_emergency_freq_tx == 1) {
        bStack_2 = 0x81;
      }
      goto LAB_fffc2ad2;
    }
  }
LAB_fffc2aaa:
  cStack_3 = '\0';
  bStack_2 = 0x71;
  if ((g_opstate.ex030406_emergency_freq_tx == 1) && (param_1 == 0x84)) {
    bStack_2 = 0x81;
    cStack_3 = '\x0f';
  }
LAB_fffc2ad2:
  if (bStack_2 <= param_1) {
    PTR_g_ui_00025d54->memlist_first = bStack_2 - cStack_3;
    PTR_g_ui_00025d54->memlist_row = param_1 - bStack_2;
    return;
  }
  PTR_g_ui_00025d54->memlist_first = param_1;
  PTR_g_ui_00025d54->memlist_row = 0;
  return;
}


// ===== memlist_cursor_channel @ fffc2b12 (28 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc2b2b) */
/* UI +0x43A = FUN_fffc2b2e(top +0x439, row +0x1DB): the channel under the list cursor,
   destination-filtered [fact] */

undefined4 memlist_cursor_channel(void)

{
  ui_state *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_g_ui_00025d54;
  uVar2 = FUN_fffc2b2e(PTR_g_ui_00025d54->memlist_first,PTR_g_ui_00025d54->memlist_row);
  puVar1->memlist_ch = (byte)uVar2;
  return uVar2;
}


// ===== FUN_fffc2b2e @ fffc2b2e (102 bytes)

byte FUN_fffc2b2e(char param_1,char param_2)

{
  bool bVar1;
  ushort uVar2;
  byte local_4;
  
  local_4 = param_1 + param_2;
  uVar2 = dest_code_get();
  if ((uVar2 == 0x4380) || (uVar2 == 0x20b)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (uVar2 == 0x60e6)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (uVar2 == 0x1cb9)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (0x74 < local_4)) {
    local_4 = 0x84;
  }
  return local_4;
}


// ===== FUN_fffc2b94 @ fffc2b94 (187 bytes)

void FUN_fffc2b94(void)

{
  bool bVar1;
  bool bStack_5;
  vfo_state *pvStack_4;
  
  bVar1 = memch_is_special(PTR_g_ui_00025d54->memlist_ch);
  if (bVar1) {
    FUN_fffc2c4f();
    return;
  }
  if (g_opstate.active_vfo == VFO_A) {
    pvStack_4 = &g_opstate.vfo_state_a;
  }
  else {
    pvStack_4 = &g_opstate.vfo_state_b;
  }
  bStack_5 = g_opstate.active_vfo != VFO_A;
  vfo_store_back(bStack_5);
  if (*pvStack_4 == VFO_STATE_PMS) {
    if (0x62 < PTR_g_ui_00025d54->memlist_ch) {
      FUN_fffc2c4f();
      return;
    }
    vfo_enter_mem_state(bStack_5);
    memtune_flags_clear(bStack_5);
  }
  vfo_clear_tag(bStack_5);
  FUN_fffc2c66(bStack_5);
  FUN_fffc2cc8(bStack_5);
  eeprom_save_memch(PTR_g_ui_00025d54->memlist_ch);
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  PTR_g_ui_00025d54->freq_refresh_req = 1;
  memlist_cursor_channel();
  beep_request(2);
  return;
}


// ===== FUN_fffc2c4f @ fffc2c4f (23 bytes)

void FUN_fffc2c4f(void)

{
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  beep_request(3);
  return;
}


// ===== FUN_fffc2c66 @ fffc2c66 (98 bytes)

void FUN_fffc2c66(int param_1)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  byte *apbStack_c [2];
  undefined1 local_1;
  
  local_1 = (undefined1)param_1;
  pvVar1 = memch + PTR_g_ui_00025d54->memlist_ch;
  if (param_1 == 0) {
    pvVar2 = &g_opstate.vfo_a;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pvVar1->mode = pvVar2->mode;
      pvVar1 = (vfo_rec *)&pvVar1->flags1;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
    }
  }
  else {
    pvVar2 = &g_opstate.vfo_b;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pvVar1->mode = pvVar2->mode;
      pvVar1 = (vfo_rec *)&pvVar1->flags1;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
    }
  }
  memch_valid(PTR_g_ui_00025d54->memlist_ch,apbStack_c);
  *apbStack_c[0] = 1;
  return;
}


// ===== FUN_fffc2cc8 @ fffc2cc8 (23 bytes)

void FUN_fffc2cc8(undefined1 param_1)

{
  memch_current_set(param_1,PTR_g_ui_00025d54->memlist_ch);
  return;
}


// ===== memch_current_set @ fffc2cdf (38 bytes)

/* (side, ch): 0x60C9 (A) / 0x60CA (B) = ch [fact] */

void memch_current_set(char param_1,byte param_2)

{
  if (param_1 != '\0') {
    g_mem_hdr.chan_b = param_2;
    return;
  }
  g_mem_hdr.chan_a = param_2;
  return;
}


// ===== FUN_fffc2d05 @ fffc2d05 (142 bytes)

undefined1 FUN_fffc2d05(void)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  pvVar1 = bandstack_a[bandstack_level_a[g_opstate.band_a]] + g_opstate.band_a;
  if (g_opstate.vfo_state_a == VFO_STATE_VFO) {
    pvVar2 = &g_opstate.vfo_a;
    pvVar1 = &g_opstate.vfo_b;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pvVar1->mode = pvVar2->mode;
      pvVar1 = (vfo_rec *)&pvVar1->flags1;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
    }
  }
  else {
    pvVar2 = &g_opstate.vfo_b;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pvVar2->mode = pvVar1->mode;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
      pvVar1 = (vfo_rec *)&pvVar1->flags1;
    }
  }
  g_ui.freq_refresh_req = 1;
  return 1;
}


// ===== vfo_is_memory @ fffc2d93 (86 bytes)

/* state 2, 7 or 8 */

byte vfo_is_memory(vfo_side param_1)

{
  bool bVar1;
  byte bVar2;
  vfo_state local_3;
  
  if (param_1 == VFO_A) {
    local_3 = g_opstate.vfo_state_a;
  }
  else {
    local_3 = g_opstate.vfo_state_b;
  }
  if ((local_3 == VFO_STATE_MEMORY) || (local_3 == VFO_STATE_LOCKED_7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (local_3 == VFO_STATE_LOCKED_8)) {
    bVar2 = 1;
  }
  else {
    bVar2 = 0;
  }
  return bVar2;
}


// ===== memch_current_valid @ fffc2de9 (24 bytes)

byte memch_current_valid(byte param_1)

{
  bool bVar1;
  byte *pbStack_8;
  byte bStack_3;
  byte local_1;
  
  local_1 = param_1;
  bStack_3 = memch_current(param_1);
  bVar1 = memch_valid(bStack_3,&pbStack_8);
  return bVar1;
}


// ===== memch_valid @ fffc2e01 (100 bytes)

/* ch<117: used flag 0x60CB[ch]; 133: valid; else !memch_dest_blocked */

bool memch_valid(byte ch,byte **rec)

{
  byte bVar1;
  bool local_11;
  
  if (ch == 0x85) {
    local_11 = true;
  }
  else if (ch < 0x75) {
    *rec = g_mem_hdr.chan_used + ch;
    if (g_mem_hdr.chan_used[ch] == 1) {
      local_11 = true;
    }
    else {
      local_11 = false;
    }
  }
  else {
    bVar1 = memch_dest_blocked(ch);
    local_11 = bVar1 == 0;
  }
  return local_11;
}


// ===== memch_current @ fffc2e65 (40 bytes)

/* 0x60C9 (A) / 0x60CA (B) */

byte memch_current(byte param_1)

{
  undefined1 local_3;
  
  if (param_1 == 0) {
    local_3 = g_mem_hdr.chan_a;
  }
  else {
    local_3 = g_mem_hdr.chan_b;
  }
  return local_3;
}


// ===== memch_dest_blocked @ fffc2e8d (62 bytes)

/* 5 MHz ch 508..515/EMG blocked for dest codes 0xA4C5 0xA983 0xB5A7 0xD950 */

byte memch_dest_blocked(byte param_1)

{
  ushort uVar1;
  byte bStack_5;
  
  uVar1 = dest_code_get();
  bStack_5 = 0;
  if (((((uVar1 == 0xa4c5) || (uVar1 == 0xa983)) || (uVar1 == 0xb5a7)) || (uVar1 == 0xd950)) &&
     (6 < (int)(param_1 - 0x75))) {
    bStack_5 = 1;
  }
  return bStack_5;
}


// ===== memch_current_is_special @ fffc2ecb (22 bytes)

byte memch_current_is_special(byte param_1)

{
  byte bVar1;
  bool bVar2;
  
  bVar1 = memch_current(param_1);
  bVar2 = memch_is_special(bVar1);
  return bVar2;
}


// ===== memch_is_special @ fffc2ee1 (26 bytes)

/* ch >= 117 (5 MHz / EMG) */

bool memch_is_special(byte param_1)

{
  return 0x74 < param_1;
}


// ===== vfo_enter_memtune_state @ fffc2efb (34 bytes)

/* (side): 0x9DBE / 0x9DBF = 3 (memory tune) [fact] */

void vfo_enter_memtune_state(int param_1)

{
  if (param_1 != 0) {
    g_opstate.vfo_state_b = VFO_STATE_MEMTUNE;
    return;
  }
  g_opstate.vfo_state_a = VFO_STATE_MEMTUNE;
  return;
}


// ===== FUN_fffc2f1d @ fffc2f1d (51 bytes)

bool FUN_fffc2f1d(int param_1)

{
  vfo_state local_3;
  
  if (param_1 == 0) {
    local_3 = g_opstate.vfo_state_a;
  }
  else {
    local_3 = g_opstate.vfo_state_b;
  }
  return local_3 == VFO_STATE_MEMTUNE;
}


// ===== FUN_fffc2f50 @ fffc2f50 (142 bytes)

undefined1 FUN_fffc2f50(void)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  pvVar1 = bandstack_b[bandstack_level_b[g_opstate.band_b]] + g_opstate.band_b;
  if (g_opstate.vfo_state_b == VFO_STATE_VFO) {
    pvVar2 = &g_opstate.vfo_b;
    pvVar1 = &g_opstate.vfo_a;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pvVar1->mode = pvVar2->mode;
      pvVar1 = (vfo_rec *)&pvVar1->flags1;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
    }
  }
  else {
    pvVar2 = &g_opstate.vfo_a;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pvVar2->mode = pvVar1->mode;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
      pvVar1 = (vfo_rec *)&pvVar1->flags1;
    }
  }
  g_ui.freq_refresh_req = 1;
  return 1;
}


// ===== vfo_mark_edited @ fffc2fde (40 bytes)

/* rt+0x443/0x445 = 1, QMB state -> VFO */

void vfo_mark_edited(byte param_1)

{
  if (param_1 != 0) {
    PTR_g_ui_00025d54->edited_b = 1;
    qmb_exit_to_vfo(1);
    return;
  }
  PTR_g_ui_00025d54->edited_a = 1;
  qmb_exit_to_vfo(0);
  return;
}


// ===== FUN_fffc3006 @ fffc3006 (37 bytes)

band_idx FUN_fffc3006(void)

{
  uint freq;
  undefined1 uStack_9;
  
  freq = vfo_freq_clar(VFO_RX,VFO_SIDE_SEL);
  uStack_9 = band_of_freq(freq);
  if (uStack_9 == BAND_NONE) {
    uStack_9 = BAND_GEN;
  }
  return uStack_9;
}


// ===== FUN_fffc302b @ fffc302b (86 bytes)

bool FUN_fffc302b(int param_1)

{
  bool bVar1;
  bool local_4;
  vfo_state local_3;
  
  if (param_1 == 0) {
    local_3 = g_opstate.vfo_state_a;
  }
  else {
    local_3 = g_opstate.vfo_state_b;
  }
  if ((local_3 == VFO_STATE_MEMORY) || (local_3 == VFO_STATE_MEMTUNE)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (local_3 == VFO_STATE_PMS)) {
    local_4 = true;
  }
  else {
    local_4 = false;
  }
  local_4 = !local_4;
  return local_4;
}


// ===== vfo_enter_vfo_state @ fffc3081 (46 bytes)

/* state = 1 */

void vfo_enter_vfo_state(char param_1)

{
  vfo_enter_mem_state(param_1);
  memtune_flags_clear(param_1);
  if (param_1 != '\0') {
    g_opstate.vfo_state_b = VFO_STATE_VFO;
    return;
  }
  g_opstate.vfo_state_a = VFO_STATE_VFO;
  return;
}


// ===== FUN_fffc30af @ fffc30af (107 bytes)

undefined1 FUN_fffc30af(int param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if ((PTR_g_ui_00025d54->edited_a == 1) || (PTR_g_ui_00025d54->tuned_a == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return 1;
    }
  }
  else {
    if ((PTR_g_ui_00025d54->edited_b == 1) || (PTR_g_ui_00025d54->tuned_b == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}


// ===== qmb_set_depth @ fffc311a (82 bytes)

/* 0x901F/0x9021 = stored count (max 5 if 0x9AC0==0) */

void qmb_set_depth(char param_1)

{
  bool bVar1;
  byte local_2;
  
  local_2 = g_qmb_hdr.count;
  if ((g_opstate.ex030112_qmb_ch == 0) && (4 < g_qmb_hdr.count)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_2 = 5;
  }
  if (param_1 == '\0') {
    g_qmb_hdr.ptr_a[0] = local_2;
    return;
  }
  g_qmb_hdr.ptr_b[0] = local_2;
  return;
}


// ===== qmb_enter @ fffc316c (59 bytes)

/* state = 5, load QMB slot, save header */

void qmb_enter(byte param_1)

{
  if (param_1 == 0) {
    g_opstate.vfo_state_a = VFO_STATE_QMB;
  }
  else {
    g_opstate.vfo_state_b = VFO_STATE_QMB;
  }
  FUN_fffc31a7(param_1,1);
  FUN_fffc334c(param_1);
  FUN_fffc33ef();
  eeprom_save_qmb_slot(0);
  tuner_rearm();
  return;
}


// ===== FUN_fffc31a7 @ fffc31a7 (25 bytes)

void FUN_fffc31a7(byte param_1,char param_2)

{
  FUN_fffc31c0(param_1);
  if (param_2 != '\x01') {
    return;
  }
  vfo_retune(param_1);
  return;
}


// ===== FUN_fffc31c0 @ fffc31c0 (128 bytes)

void FUN_fffc31c0(uint param_1)

{
  byte local_4;
  byte local_3;
  byte local_2;
  
  if (param_1 == 0) {
    local_2 = g_qmb_hdr.ptr_a[1];
  }
  else {
    local_2 = g_qmb_hdr.ptr_b[1];
  }
  if (g_qmb_hdr.count <= local_2) {
    local_2 = 0;
  }
  local_3 = g_qmb_hdr.order[local_2];
  if (local_3 < 8) {
    local_4 = g_qmb_hdr.used_mask_be[1];
  }
  else {
    local_3 = local_3 - 8;
    local_4 = g_qmb_hdr.used_mask_be[0];
  }
  if (((uint)local_4 & 1 << (local_3 & 0x1f)) != 0) {
    FUN_fffc3240(g_qmb_hdr.order[local_2],param_1 & 0xff);
    return;
  }
  return;
}


// ===== FUN_fffc3240 @ fffc3240 (71 bytes)

void FUN_fffc3240(byte param_1,int param_2)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  if (param_2 == 0) {
    pvVar2 = qmb + param_1;
    pvVar1 = &g_opstate.vfo_a;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pvVar1->mode = pvVar2->mode;
      pvVar1 = (vfo_rec *)&pvVar1->flags1;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
    }
  }
  else {
    pvVar2 = qmb + param_1;
    pvVar1 = &g_opstate.vfo_b;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pvVar1->mode = pvVar2->mode;
      pvVar1 = (vfo_rec *)&pvVar1->flags1;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
    }
  }
  vfo_retune((byte)param_2);
  return;
}


// ===== vfo_retune @ fffc3287 (197 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc32ca) */
/* WARNING: Removing unreachable block (ram,0xfffc32d1) */
/* freq_clamp the record frequency and apply */

void vfo_retune(byte param_1)

{
  bool bVar1;
  uint uVar2;
  vfo_state local_d;
  int local_c;
  undefined1 local_8;
  
  if (param_1 == 0) {
    local_c = 0x9d09;
    local_d = g_opstate.vfo_state_a;
  }
  else {
    local_c = 0x9d63;
    local_d = g_opstate.vfo_state_b;
  }
  DAT_0001b4e2 = 1;
  uVar2 = freq_clamp(param_1,(uint)*(byte *)(local_c + 0x4a) << 0x18 |
                             (uint)*(byte *)(local_c + 0x4b) << 0x10 |
                             (uint)*(byte *)(local_c + 0x4c) << 8 | (uint)*(byte *)(local_c + 0x4d))
  ;
  DAT_0001b4e2 = 0;
  *(char *)(local_c + 0x4a) = (char)(uVar2 >> 0x18);
  *(char *)(local_c + 0x4b) = (char)(uVar2 >> 0x10);
  *(char *)(local_c + 0x4c) = (char)(uVar2 >> 8);
  local_8 = (undefined1)uVar2;
  *(undefined1 *)(local_c + 0x4d) = local_8;
  if (PTR_g_ui_00025d54->freq_rejected != 0) {
    if ((local_d == VFO_STATE_PMS) || (local_d == VFO_STATE_MEMTUNE)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      vfo_mark_edited(param_1);
      vfo_store_back(param_1);
      return;
    }
  }
  return;
}


// ===== FUN_fffc334c @ fffc334c (163 bytes)

void FUN_fffc334c(int param_1)

{
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
  if (*local_8 != 0) {
    *local_8 = *local_8 - 1;
  }
  *local_c = *local_c + 1;
  if (g_opstate.ex030112_qmb_ch == 0) {
    if (*local_c < 5) {
      if (g_qmb_hdr.count <= *local_c) {
        *local_c = 0;
      }
    }
    else {
      *local_c = 0;
    }
  }
  else if (g_qmb_hdr.count <= *local_c) {
    *local_c = 0;
  }
  PTR_g_ui_00025d54->vfo_refresh_req = 1;
  return;
}


// ===== FUN_fffc33ef @ fffc33ef (25 bytes)

void FUN_fffc33ef(void)

{
  popup_duration_get(0x43);
  popup_open_timed();
  PTR_g_ui_00025d54->popup_code = 0x43;
  return;
}


// ===== FUN_fffc3408 @ fffc3408 (208 bytes)

void FUN_fffc3408(char param_1)

{
  byte local_2;
  
  if (g_opstate.ex030112_qmb_ch == 0) {
    local_2 = 5;
  }
  else {
    local_2 = 10;
  }
  if (g_qmb_hdr.count < local_2) {
    return;
  }
  if (param_1 == '\0') {
    if (g_qmb_hdr.ptr_b[0] != 0) {
      g_qmb_hdr.ptr_b[0] = g_qmb_hdr.ptr_b[0] - 1;
      return;
    }
    g_opstate.vfo_state_b = VFO_STATE_VFO;
    vfo_reload(1);
    PTR_g_ui_00025d54->vfo_refresh_req = 1;
    qmb_set_depth('\0');
    g_qmb_hdr.ptr_b[1] = 0;
    return;
  }
  if (g_qmb_hdr.ptr_a[0] != 0) {
    g_qmb_hdr.ptr_a[0] = g_qmb_hdr.ptr_a[0] - 1;
    return;
  }
  g_opstate.vfo_state_a = VFO_STATE_VFO;
  vfo_reload(0);
  PTR_g_ui_00025d54->vfo_refresh_req = 1;
  qmb_set_depth('\0');
  g_qmb_hdr.ptr_a[1] = 0;
  return;
}


// ===== FUN_fffc34d8 @ fffc34d8 (41 bytes)

void FUN_fffc34d8(char param_1)

{
  qmb_set_depth(param_1);
  if (param_1 != '\0') {
    g_qmb_hdr.ptr_b[1] = 0;
    return;
  }
  g_qmb_hdr.ptr_a[1] = 0;
  return;
}


// ===== FUN_fffc3501 @ fffc3501 (1 bytes)

void FUN_fffc3501(void)

{
  return;
}


// ===== FUN_fffc3502 @ fffc3502 (1 bytes)

void FUN_fffc3502(void)

{
  return;
}


// ===== FUN_fffc3503 @ fffc3503 (127 bytes)

void FUN_fffc3503(int param_1)

{
  uint uVar1;
  vfo_rec *local_8;
  
  if (param_1 == 0) {
    local_8 = &g_opstate.vfo_a;
  }
  else {
    local_8 = &g_opstate.vfo_b;
  }
  uVar1 = (uint)(local_8->mode & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_8->blk[1].shift_be[0] = 0;
      local_8->blk[1].shift_be[1] = 0;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        local_8->blk[2].shift_be[0] = 0;
        local_8->blk[2].shift_be[1] = 0;
        return;
      }
      if (uVar1 < 2) {
        local_8->blk[0].shift_be[0] = 0;
        local_8->blk[0].shift_be[1] = 0;
        return;
      }
      return;
    }
  }
  local_8->blk[3].shift_be[0] = 0;
  local_8->blk[3].shift_be[1] = 0;
  return;
}


// ===== FUN_fffc3582 @ fffc3582 (215 bytes)

void FUN_fffc3582(int param_1)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  byte bStack_c;
  vfo_rec *local_8;
  
  if (param_1 == 0) {
    local_8 = &g_opstate.vfo_a;
  }
  else {
    local_8 = &g_opstate.vfo_b;
  }
  bVar2 = local_8->mode & 0xf;
  uVar1 = (uint)bVar2;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      sVar3 = FUN_fffc38cb(500,bVar2);
      if (sVar3 == 0) {
        return;
      }
      local_8->blk[1].width_be[0] = (byte)((ushort)sVar3 >> 8);
      bStack_c = (byte)sVar3;
      local_8->blk[1].width_be[1] = bStack_c;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        sVar3 = FUN_fffc38cb(500,bVar2);
        if (sVar3 == 0) {
          return;
        }
        local_8->blk[2].width_be[0] = (byte)((ushort)sVar3 >> 8);
        bStack_c = (byte)sVar3;
        local_8->blk[2].width_be[1] = bStack_c;
        return;
      }
      if (1 < uVar1) {
        return;
      }
      sVar3 = FUN_fffc38cb(3000,bVar2);
      if (sVar3 == 0) {
        return;
      }
      local_8->blk[0].width_be[0] = (byte)((ushort)sVar3 >> 8);
      bStack_c = (byte)sVar3;
      local_8->blk[0].width_be[1] = bStack_c;
      return;
    }
  }
  sVar3 = FUN_fffc38cb(0xc80,bVar2);
  if (sVar3 == 0) {
    return;
  }
  local_8->blk[3].width_be[0] = (byte)((ushort)sVar3 >> 8);
  bStack_c = (byte)sVar3;
  local_8->blk[3].width_be[1] = bStack_c;
  return;
}


// ===== FUN_fffc3659 @ fffc3659 (282 bytes)

void FUN_fffc3659(int param_1)

{
  uint uVar1;
  vfo_rec *local_8;
  
  if (param_1 == 0) {
    local_8 = &g_opstate.vfo_a;
  }
  else {
    local_8 = &g_opstate.vfo_b;
  }
  uVar1 = (uint)(local_8->mode & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_8->blk[1].notch_be[0] = 0;
      local_8->blk[1].notch_be[1] = 0x96;
      local_8->blk[1].flags = local_8->blk[1].flags & 0x7f;
      return;
    }
    if (uVar1 - 4 < 2) {
      local_8->blk[4].notch_be[0] = 0;
      local_8->blk[4].notch_be[1] = 0x96;
      local_8->blk[4].flags = local_8->blk[4].flags & 0x7f;
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc3717;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          local_8->blk[2].notch_be[0] = 0;
          local_8->blk[2].notch_be[1] = 0x96;
          local_8->blk[2].flags = local_8->blk[2].flags & 0x7f;
          return;
        }
        if (1 < uVar1) {
          return;
        }
        local_8->blk[0].notch_be[0] = 0;
        local_8->blk[0].notch_be[1] = 0x96;
        local_8->blk[0].flags = local_8->blk[0].flags & 0x7f;
        return;
      }
    }
    local_8->blk[5].notch_be[0] = 0;
    local_8->blk[5].notch_be[1] = 0x96;
    local_8->blk[5].flags = local_8->blk[5].flags & 0x7f;
    return;
  }
LAB_fffc3717:
  local_8->blk[3].notch_be[0] = 0;
  local_8->blk[3].notch_be[1] = 0x96;
  local_8->blk[3].flags = local_8->blk[3].flags & 0x7f;
  return;
}


// ===== FUN_fffc3773 @ fffc3773 (282 bytes)

void FUN_fffc3773(int param_1)

{
  uint uVar1;
  vfo_rec *local_8;
  
  if (param_1 == 0) {
    local_8 = &g_opstate.vfo_a;
  }
  else {
    local_8 = &g_opstate.vfo_b;
  }
  uVar1 = (uint)(local_8->mode & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_8->blk[1].contour_be[0] = 0;
      local_8->blk[1].contour_be[1] = 0x96;
      local_8->blk[1].flags = local_8->blk[1].flags & 0xbf;
      return;
    }
    if (uVar1 - 4 < 2) {
      local_8->blk[4].contour_be[0] = 0;
      local_8->blk[4].contour_be[1] = 0x96;
      local_8->blk[4].flags = local_8->blk[4].flags & 0xbf;
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc3831;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          local_8->blk[2].contour_be[0] = 0;
          local_8->blk[2].contour_be[1] = 0x96;
          local_8->blk[2].flags = local_8->blk[2].flags & 0xbf;
          return;
        }
        if (1 < uVar1) {
          return;
        }
        local_8->blk[0].contour_be[0] = 0;
        local_8->blk[0].contour_be[1] = 0x96;
        local_8->blk[0].flags = local_8->blk[0].flags & 0xbf;
        return;
      }
    }
    local_8->blk[5].contour_be[0] = 0;
    local_8->blk[5].contour_be[1] = 0x96;
    local_8->blk[5].flags = local_8->blk[5].flags & 0xbf;
    return;
  }
LAB_fffc3831:
  local_8->blk[3].contour_be[0] = 0;
  local_8->blk[3].contour_be[1] = 0x96;
  local_8->blk[3].flags = local_8->blk[3].flags & 0xbf;
  return;
}


// ===== FUN_fffc388d @ fffc388d (62 bytes)

void FUN_fffc388d(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0x9d09;
  }
  else {
    local_8 = 0x9d63;
  }
  g_opstate.apf_freq = 0;
  *(byte *)(local_8 + 0x14) = *(byte *)(local_8 + 0x14) & 0xdf;
  return;
}


// ===== FUN_fffc38cb @ fffc38cb (47 bytes)

undefined2 FUN_fffc38cb(undefined2 param_1,undefined1 param_2)

{
  char cVar1;
  undefined2 uStack_c;
  
  cVar1 = FUN_fffb36ff(param_2,param_1);
  if (cVar1 == -1) {
    uStack_c = 0;
  }
  else {
    uStack_c = FUN_fffb3775(param_2,cVar1);
  }
  return uStack_c;
}


// ===== FUN_fffc38fa @ fffc38fa (115 bytes)

void FUN_fffc38fa(void)

{
  PTR_g_ui_00025d54->memlist_edit_on = 0;
  if (PTR_g_ui_00025d54->memlist_flag == 0) {
    PTR_g_ui_00025d54->memlist_flag = 1;
    memlist_cursor_channel();
    PTR_g_ui_00025d54->key_consumed = 1;
    beep_request(2);
    return;
  }
  if (PTR_g_ui_00025d54->memlist_popup55 != 0) {
    PTR_g_ui_00025d54->memlist_popup55 = 0;
    PTR_g_ui_00025d54->key_consumed = 1;
    beep_request(1);
    return;
  }
  FUN_fffc20dd();
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffc396d @ fffc396d (139 bytes)

void FUN_fffc396d(void)

{
  byte bVar1;
  
  bVar1 = PTR_g_ui_00025d54->popup_code;
  if (bVar1 == 0xc) {
    FUN_fffc151d(PTR_g_ui_00025d54->popup_cursor + 0x6b);
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  if (bVar1 != 0xb) {
    if (bVar1 == 5) {
      FUN_fffc0c8f(PTR_g_ui_00025d54->popup_cursor + 0x77);
      PTR_g_ui_00025d54->key_consumed = 1;
      beep_request(1);
      return;
    }
    return;
  }
  if (PTR_g_ui_00025d54->popup_cursor < 0xb) {
    g_opstate.ss03_value = PTR_g_ui_00025d54->popup_cursor;
  }
  FUN_fffc39f8();
  return;
}


// ===== FUN_fffc39f8 @ fffc39f8 (24 bytes)

void FUN_fffc39f8(void)

{
  popup_close();
  PTR_g_ui_00025d54->key_consumed = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc3a10 @ fffc3a10 (245 bytes)

void FUN_fffc3a10(void)

{
  if (PTR_g_ui_00025d54->dl_req_37 == 1) {
    FUN_fffc3b05(g_opstate.func_knob_sf);
    if (g_opstate.func_knob_sf != 0x18) {
      beep_request(1);
      return;
    }
  }
  else if (PTR_g_ui_00025d54->zz_align_mode != 1) {
    if (PTR_g_ui_00025d54->playlist_open == 1) {
      if (PTR_g_ui_00025d54->playlist_row == 4) {
        FUN_fffe35c3();
        return;
      }
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d54->memlist_open == 1) {
      memlist_close();
    }
    if (PTR_g_ui_00025d54->dl_req_popup_b == 1) {
      if (PTR_g_ui_00025d54->popup_code < 0x1e) {
        FUN_fffc396d();
      }
      popup_close();
      PTR_g_ui_00025d54->key_consumed = 1;
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d54->func_panel_open == 1) {
      PTR_g_ui_00025d54->func_blink_en = 0;
      PTR_g_ui_00025d54->func_blink_on = 1;
    }
    popup_close();
    PTR_g_ui_00025d54->func_panel_open = 0;
    menu_close_if_open();
    ui_clear_415_423();
    memlist_close();
    PTR_g_ui_00025d54->dl_req_37 = 1;
    PTR_g_ui_00025d54->func_assigned = 0;
    return;
  }
  return;
}


// ===== FUN_fffc3b05 @ fffc3b05 (29 bytes)

void FUN_fffc3b05(undefined1 param_1)

{
  DAT_0001b4da = 1;
  func_menu_select(param_1);
  DAT_0001b4da = 0;
  return;
}


// ===== func_menu_select @ fffc3b22 (257 bytes)

/* FUNC menu: runs the item at cursor 0x9C08 (func_knob_assign(n) for adjustable items, one-shot
   actions otherwise) */

void func_menu_select(undefined1 param_1)

{
  switch(param_1) {
  case 0:
    func_knob_assign(0);
    return;
  case 1:
    func_knob_assign(1);
    return;
  case 2:
    FUN_fffc3c9f();
    return;
  case 3:
    FUN_fffc3cd9();
    return;
  case 4:
    func_knob_assign(4);
    return;
  case 5:
    func_knob_assign(5);
    return;
  case 6:
    func_knob_assign(6);
    return;
  case 7:
    func_knob_assign(7);
    return;
  case 8:
    FUN_fffc3d26();
    return;
  case 9:
    func_knob_assign(9);
    return;
  case 10:
    func_knob_assign(10);
    return;
  case 0xb:
    func_knob_assign(0xb);
    return;
  case 0xc:
    func_knob_assign(0xc);
    return;
  case 0xd:
    func_knob_assign(0xd);
    return;
  case 0xe:
    func_knob_assign(0xe);
    return;
  case 0xf:
    func_knob_assign(0xf);
    return;
  case 0x10:
    FUN_fffc3de8();
    return;
  case 0x11:
    FUN_fffc3eaa();
    return;
  case 0x12:
    func_knob_assign(0x12);
    return;
  case 0x13:
    func_knob_assign(0x13);
    return;
  case 0x14:
    func_knob_assign(0x14);
    return;
  case 0x15:
    FUN_fffe3979();
    return;
  case 0x16:
    FUN_fffe2ee4();
    return;
  case 0x17:
    FUN_fffe2fa8();
    return;
  case 0x18:
    FUN_fffc3f9c();
    return;
  case 0x1a:
    func_knob_assign(0x15);
    return;
  case 0x1b:
    func_knob_assign(0x3a);
    return;
  case 0x1c:
    FUN_fffc1f2a(0);
    return;
  case 0x1d:
    FUN_fffc1f2a(1);
    return;
  case 0x1e:
    FUN_fffc1f2a(2);
    return;
  case 0x1f:
    FUN_fffc1f2a(3);
    return;
  case 0x20:
    FUN_fffc1f2a(4);
    return;
  case 0x21:
  case 0x22:
    FUN_fffc1f94();
  }
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== func_knob_assign @ fffc3c23 (98 bytes)

/* (n): 0x9DC9 = n (FUNC-knob function), UI +0x490 = 1, +0x1C5 = 1, beep */

void func_knob_assign(byte param_1)

{
  g_opstate.func_knob = param_1;
  PTR_g_ui_00025d54->func_assigned = 1;
  FUN_fffc8e0e(500);
  PTR_g_ui_00025d54->func_cursor_locked = 1;
  if (PTR_g_ui_00025d54->txw_on == 1) {
    PTR_g_ui_00025d54->txw_on = 0;
  }
  beep_request(1);
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}

