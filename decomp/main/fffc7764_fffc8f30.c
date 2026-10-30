// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc7764 @ fffc7764 (99 bytes)

void FUN_fffc7764(char param_1)

{
  short sStack_a;
  byte *pbStack_8;
  
  popup_duration_get(0x2b);
  popup_open_timed();
  if (g_opstate.ex030405_vox_select == 0) {
    pbStack_8 = g_opstate.antivox;
  }
  else {
    pbStack_8 = g_opstate.antivox + 1;
  }
  sStack_a = (ushort)*pbStack_8 + (short)param_1;
  if (sStack_a < 0x65) {
    if (sStack_a < 0) {
      sStack_a = 0;
    }
  }
  else {
    sStack_a = 100;
  }
  *pbStack_8 = (byte)sStack_a;
  return;
}


// ===== FUN_fffc77c7 @ fffc77c7 (24 bytes)

void FUN_fffc77c7(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x2c;
  FUN_fffc77df(param_1);
  return;
}


// ===== FUN_fffc77df @ fffc77df (72 bytes)

void FUN_fffc77df(char param_1)

{
  byte *pbVar1;
  ushort uStack_c;
  byte bStack_a;
  byte abStack_9 [8];
  char local_1;
  
  local_1 = param_1;
  popup_duration_get(0x2c);
  popup_open_timed();
  pbVar1 = FUN_fffc7827(abStack_9,&bStack_a);
  uStack_c = (ushort)*pbVar1 + (short)local_1;
  if ((short)(ushort)bStack_a < (short)uStack_c) {
    uStack_c = (ushort)bStack_a;
  }
  else if ((short)uStack_c < (short)(ushort)abStack_9[0]) {
    uStack_c = (ushort)abStack_9[0];
  }
  *pbVar1 = (byte)uStack_c;
  return;
}


// ===== FUN_fffc7827 @ fffc7827 (228 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc7908) */

void * FUN_fffc7827(void *param_1,byte *param_2)

{
  bool bVar1;
  radio_mode rVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  byte *pbStack_1c;
  undefined1 uStack_17;
  
  uVar5 = vfo_freq(VFO_TX,VFO_SIDE_SEL);
  rVar2 = vfo_mode(VFO_TX);
  bVar3 = tx_band_of_freq(uVar5);
  if ((rVar2 == MODE_AM) || (rVar2 == MODE_AM_N)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *param_2 = g_opstate.ex030404_am_max_power;
    pbStack_1c = g_opstate.rf_power + 3;
    uStack_17 = 3;
    if ((bVar3 < 9) && (bVar3 = max_power_limit(3), bVar3 < *param_2)) {
      *param_2 = bVar3;
    }
  }
  else if (bVar3 < 9) {
    *param_2 = g_opstate.ex030401_hf_max_power;
    pbStack_1c = g_opstate.rf_power;
    uStack_17 = 0;
  }
  else if (bVar3 < 10) {
    *param_2 = g_opstate.ex030402_50m_max_power;
    pbStack_1c = g_opstate.rf_power + 1;
    uStack_17 = 1;
  }
  else {
    *param_2 = g_opstate.ex030403_70m_max_power;
    pbStack_1c = g_opstate.rf_power + 2;
    uStack_17 = 2;
  }
  uVar4 = FUN_fffb3f0b(uStack_17);
  *(undefined1 *)param_1 = uVar4;
  return pbStack_1c;
}


// ===== FUN_fffc790b @ fffc790b (24 bytes)

void FUN_fffc790b(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x2d;
  FUN_fffc7923((int)param_1);
  return;
}


// ===== FUN_fffc7923 @ fffc7923 (82 bytes)

void FUN_fffc7923(char param_1)

{
  byte *pbVar1;
  short sStack_4;
  
  popup_duration_get(0x2d);
  popup_open_timed();
  pbVar1 = (byte *)FUN_fff99669();
  if (pbVar1 != (byte *)0x0) {
    sStack_4 = (ushort)*pbVar1 + (short)param_1;
    if (sStack_4 < 0x65) {
      if (sStack_4 < 0) {
        sStack_4 = 0;
      }
    }
    else {
      sStack_4 = 100;
    }
    *pbVar1 = (byte)sStack_4;
    PTR_g_ui_00025d58->freq_refresh_req = 1;
    return;
  }
  return;
}


// ===== FUN_fffc7975 @ fffc7975 (67 bytes)

void FUN_fffc7975(char param_1)

{
  popup_duration_get(0x46);
  popup_open_timed();
  if (param_1 < '\x01') {
    if (g_opstate.keyer_on == 1) {
      g_opstate.keyer_on = 0;
      return;
    }
  }
  else if (g_opstate.keyer_on == 0) {
    g_opstate.keyer_on = 1;
    return;
  }
  return;
}


// ===== FUN_fffc79b8 @ fffc79b8 (215 bytes)

void FUN_fffc79b8(char param_1)

{
  uint uVar1;
  mode_blk *pmStack_c;
  vfo_rec *pvStack_8;
  
  popup_duration_get(0x2f);
  popup_open_timed();
  if (g_opstate.split_on == 0) {
    if (g_opstate.active_vfo == VFO_A) {
      pvStack_8 = &g_opstate.vfo_a;
    }
    else {
      pvStack_8 = &g_opstate.vfo_b;
    }
  }
  else if (g_opstate.active_vfo == VFO_A) {
    pvStack_8 = &g_opstate.vfo_b;
  }
  else {
    pvStack_8 = &g_opstate.vfo_a;
  }
  uVar1 = (uint)(pvStack_8->mode & 0xf);
  if (uVar1 - 6 < 2) {
    pmStack_c = pvStack_8->blk + 5;
  }
  else if (uVar1 - 2 < 2) {
    pmStack_c = pvStack_8->blk + 1;
  }
  else if (uVar1 - 4 < 2) {
    pmStack_c = pvStack_8->blk + 4;
  }
  else {
    if (1 < uVar1) {
      return;
    }
    pmStack_c = pvStack_8->blk;
  }
  if (param_1 < '\x01') {
    if ((pmStack_c->flags & 2) != 0) {
      pmStack_c->flags = pmStack_c->flags & 0xfd;
LAB_fffc7a7e:
      PTR_g_ui_00025d58->freq_refresh_req = 1;
      return;
    }
  }
  else if ((pmStack_c->flags & 2) == 0) {
    pmStack_c->flags = pmStack_c->flags | 2;
    goto LAB_fffc7a7e;
  }
  return;
}


// ===== FUN_fffc7a8f @ fffc7a8f (24 bytes)

void FUN_fffc7a8f(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x30;
  FUN_fffc7aa7((int)param_1);
  return;
}


// ===== FUN_fffc7aa7 @ fffc7aa7 (67 bytes)

void FUN_fffc7aa7(char param_1)

{
  undefined2 uStack_4;
  
  popup_duration_get(0x30);
  popup_open_timed();
  uStack_4 = (ushort)g_opstate.key_speed + (short)param_1;
  if (uStack_4 < 0x3d) {
    if (uStack_4 < 4) {
      uStack_4 = 4;
    }
  }
  else {
    uStack_4 = 0x3c;
  }
  g_opstate.key_speed = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7aea @ fffc7aea (24 bytes)

void FUN_fffc7aea(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x31;
  FUN_fffc7b02((int)param_1);
  return;
}


// ===== FUN_fffc7b02 @ fffc7b02 (69 bytes)

void FUN_fffc7b02(char param_1)

{
  undefined2 uStack_4;
  
  popup_duration_get(0x31);
  popup_open_timed();
  uStack_4 = (ushort)g_opstate.cw_pitch + (short)param_1;
  if (uStack_4 < 0x4c) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 0x4b;
  }
  g_opstate.cw_pitch = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7b47 @ fffc7b47 (24 bytes)

void FUN_fffc7b47(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x32;
  FUN_fffc7b5f((int)param_1);
  return;
}


// ===== FUN_fffc7b5f @ fffc7b5f (69 bytes)

void FUN_fffc7b5f(char param_1)

{
  undefined2 uStack_4;
  
  popup_duration_get(0x32);
  popup_open_timed();
  uStack_4 = (ushort)g_opstate.cw_bkin_delay + (short)param_1;
  if (uStack_4 < 0x22) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 0x21;
  }
  g_opstate.cw_bkin_delay = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7ba4 @ fffc7ba4 (24 bytes)

void FUN_fffc7ba4(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x33;
  FUN_fffc7bbc((int)param_1);
  return;
}


// ===== FUN_fffc7bbc @ fffc7bbc (65 bytes)

void FUN_fffc7bbc(char param_1)

{
  byte *pbVar1;
  undefined2 uStack_4;
  
  pbVar1 = (byte *)aess_level_ptr();
  popup_duration_get(0x33);
  popup_open_timed();
  uStack_4 = (ushort)*pbVar1 + (short)param_1;
  if (uStack_4 < 0x15) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 0x14;
  }
  *pbVar1 = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7bfd @ fffc7bfd (24 bytes)

void FUN_fffc7bfd(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x58;
  FUN_fffc7c15((int)param_1);
  return;
}


// ===== FUN_fffc7c15 @ fffc7c15 (64 bytes)

void FUN_fffc7c15(char param_1)

{
  byte *pbVar1;
  undefined2 uStack_4;
  
  pbVar1 = (byte *)aess_mode_ptr();
  popup_duration_get(0x58);
  popup_open_timed();
  uStack_4 = (ushort)*pbVar1 + (short)param_1;
  if (uStack_4 < 2) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 1;
  }
  *pbVar1 = (byte)uStack_4;
  return;
}


// ===== func_menu_cursor_step @ fffc7c55 (168 bytes)

/* (step): FUNC-menu cursor 0x9C08 over 0..0x21, skipping 0x19, while UI +0x490 != 1 */

void func_menu_cursor_step(char param_1)

{
  short sVar1;
  
  if (PTR_g_ui_00025d58->func_cursor_locked != 1) {
    sVar1 = (ushort)g_opstate.func_knob_sf + (short)param_1;
    if ('\0' < param_1) {
      if (0x20 < sVar1) {
        g_opstate.func_knob_sf = 0x21;
        return;
      }
      if (sVar1 == 0x19) {
        g_opstate.func_knob_sf = 0x1a;
        return;
      }
      g_opstate.func_knob_sf = g_opstate.func_knob_sf + 1;
      return;
    }
    if (param_1 < '\0') {
      if (sVar1 < 1) {
        g_opstate.func_knob_sf = 0;
        return;
      }
      if (sVar1 == 0x19) {
        g_opstate.func_knob_sf = 0x18;
        return;
      }
      g_opstate.func_knob_sf = g_opstate.func_knob_sf - 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffc7cfd @ fffc7cfd (68 bytes)

void FUN_fffc7cfd(char param_1)

{
  undefined2 uStack_4;
  
  popup_duration_get(0x38);
  popup_open_timed();
  uStack_4 = (ushort)g_opstate.nb_level + (short)param_1;
  if (uStack_4 < 0xb) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 10;
  }
  g_opstate.nb_level = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7d41 @ fffc7d41 (110 bytes)

void FUN_fffc7d41(char param_1)

{
  vfo_rec *pvVar1;
  byte *pbStack_8;
  short sStack_4;
  
  popup_duration_get(0x39);
  popup_open_timed();
  if (g_opstate.active_vfo == VFO_A) {
    pvVar1 = &g_opstate.vfo_a;
  }
  else {
    pvVar1 = &g_opstate.vfo_b;
  }
  pbStack_8 = &pvVar1->dnr;
  sStack_4 = (*pbStack_8 & 0xf) + (short)param_1;
  if (sStack_4 < 0x10) {
    if (sStack_4 < 1) {
      sStack_4 = 1;
    }
  }
  else {
    sStack_4 = 0xf;
  }
  *pbStack_8 = *pbStack_8 & 0xf0 | (byte)sStack_4;
  FUN_fffc515d((byte)sStack_4);
  return;
}


// ===== enc3_step @ fffc7daf (316 bytes)

/* encoder id 3 by screen [inference: multi knob] */

void enc3_step(char param_1)

{
  byte local_2;
  
  if (PTR_g_ui_00025d58->numentry_mode == 1) {
    FUN_fffc82b7((int)param_1);
    return;
  }
  if (PTR_g_ui_00025d58->zz_align_mode == 1) {
    FUN_fffbba04((int)param_1);
    return;
  }
  if ((g_ui.dialog_shown == 1) || (g_ui.dl_req_40 == 1)) {
    return;
  }
  if (PTR_g_ui_00025d58->func_panel_open == 1) {
    local_2 = PTR_g_ui_00025d58->dsp_knob_func;
    if (PTR_g_ui_00025d58->dsp_knob_edit == 1) {
      FUN_fffc836a((int)param_1);
      return;
    }
    if (param_1 < '\0') {
      if (local_2 < (byte)-param_1) {
        local_2 = 0;
      }
      else {
        local_2 = local_2 + param_1;
      }
    }
    else {
      local_2 = param_1 + local_2;
    }
    if (local_2 == 2) {
      PTR_g_ui_00025d58->func_knob_item = 0x1f;
    }
    else if (local_2 == 1) {
      PTR_g_ui_00025d58->func_knob_item = 0x1e;
    }
    else if (local_2 == 0) {
      PTR_g_ui_00025d58->func_knob_item = 0x1d;
    }
    else {
      if (PTR_g_ui_00025d58->dsp_knob_apf == 0) {
        PTR_g_ui_00025d58->func_knob_item = 0x20;
      }
      else {
        PTR_g_ui_00025d58->func_knob_item = 0x21;
      }
      local_2 = 3;
    }
    PTR_g_ui_00025d58->dsp_knob_func = local_2;
    func_display_open();
    return;
  }
  if (g_opstate.lock_on == 0) {
    FUN_fffc7eeb((int)param_1);
    return;
  }
  PTR_g_ui_00025d58->popup_code = 0x47;
  popup_duration_get(0x47);
  popup_open_timed();
  return;
}


// ===== FUN_fffc7eeb @ fffc7eeb (225 bytes)

void FUN_fffc7eeb(byte param_1)

{
  bool bVar1;
  byte bVar2;
  byte local_5;
  
  if ((char)param_1 < '\0') {
    PTR_g_ui_00025d58->ch_knob_mode = 1;
    local_5 = ~param_1 + 1;
  }
  else {
    PTR_g_ui_00025d58->ch_knob_mode = 0;
    local_5 = param_1;
  }
  DAT_0001ff6c = DAT_0001ff6c + (char)param_1;
  ui_clear_415_423();
  if (PTR_g_ui_00025d58->memlist_open != 1) {
    if (PTR_g_ui_00025d58->txw_swap == 1) {
      bVar1 = g_opstate.active_vfo == VFO_A;
      bVar2 = vfo_is_memory(bVar1);
      if ((bVar2 == 1) && (bVar2 = memch_current_is_special(bVar1), bVar2 == 1)) {
        return;
      }
    }
    if (PTR_g_ui_00025d58->cw_spot_on == 1) {
      FUN_fffc5bb9(local_5);
      return;
    }
    FUN_fffc81e5();
    return;
  }
  if (PTR_g_ui_00025d58->dl_req_popup_b != 1) {
    FUN_fffc6800((int)(char)param_1);
    return;
  }
  if ((1 < PTR_g_ui_00025d58->popup_code - 0x44) && (PTR_g_ui_00025d58->popup_code != 0x55)) {
    return;
  }
  FUN_fffc6800((int)(char)param_1);
  return;
}


// ===== FUN_fffc7fcc @ fffc7fcc (178 bytes)

void FUN_fffc7fcc(void)

{
  bool bVar1;
  char local_1;
  
  PTR_g_ui_00025d58->step_ch_req = 1;
  if (g_opstate.split_on == 0) {
    if (g_opstate.active_vfo == VFO_A) {
      local_1 = '\0';
    }
    else {
      local_1 = '\x01';
    }
  }
  else {
    if (g_opstate.active_vfo == VFO_A) {
      if (PTR_g_ui_00025d58->txw_swap == 0) {
        local_1 = '\x01';
      }
      else {
        local_1 = '\0';
      }
    }
    else if (PTR_g_ui_00025d58->txw_swap == 0) {
      local_1 = '\0';
    }
    else {
      local_1 = '\x01';
    }
    if ((PTR_g_ui_00025d58->split_long_on == 1) && (PTR_g_ui_00025d58->txw_swap == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (local_1 == '\0') {
        local_1 = '\x01';
      }
      else {
        local_1 = '\0';
      }
    }
  }
  FUN_fffc807e(local_1);
  PTR_g_ui_00025d58->step_ch_req = 0;
  return;
}


// ===== FUN_fffc807e @ fffc807e (31 bytes)

void FUN_fffc807e(undefined1 param_1)

{
  if (PTR_g_ui_00025d58->ch_knob_mode != 0) {
    vfo_step_down();
    return;
  }
  vfo_step_up(param_1);
  return;
}


// ===== vfo_step_up @ fffc809d (164 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc8107) */
/* WARNING: Removing unreachable block (ram,0xfffc810d) */
/* (side): memory state: channel up (+0x46B) or memory tune; then rec+0x4A frequency =
   FUN_fffc5ec4(side, f), the dial step up [fact for the flow] */

void vfo_step_up(uint param_1)

{
  vfo_rec *pvVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  byte local_c;
  byte *local_8;
  vfo_state local_2;
  
  bVar2 = (byte)param_1;
  if (param_1 == 0) {
    local_2 = g_opstate.vfo_state_a;
    pvVar1 = &g_opstate.vfo_a;
  }
  else {
    local_2 = g_opstate.vfo_state_b;
    pvVar1 = &g_opstate.vfo_b;
  }
  local_8 = pvVar1->freq_be;
  if (local_2 == VFO_STATE_MEMORY) {
    if (PTR_g_ui_00025d58->ch_step_mode == 1) {
      memch_step_up(bVar2);
      return;
    }
    bVar3 = memch_current_is_special(bVar2);
    if (bVar3 == 1) {
      return;
    }
    vfo_enter_memtune_state(param_1 & 0xff);
  }
  uVar4 = FUN_fffc5ec4(bVar2,(uint)*local_8 << 0x18 | (uint)local_8[1] << 0x10 |
                             (uint)local_8[2] << 8 | (uint)local_8[3]);
  *local_8 = (byte)(uVar4 >> 0x18);
  local_8[1] = (byte)(uVar4 >> 0x10);
  local_8[2] = (byte)(uVar4 >> 8);
  local_c = (byte)uVar4;
  local_8[3] = local_c;
  return;
}


// ===== vfo_step_down @ fffc8141 (164 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc81ab) */
/* WARNING: Removing unreachable block (ram,0xfffc81b1) */
/* (side): as vfo_step_up with channel down and FUN_fffc6073 (dial step down) [fact for the flow] */

void vfo_step_down(uint param_1)

{
  vfo_rec *pvVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  byte local_c;
  byte *local_8;
  vfo_state local_2;
  
  bVar2 = (byte)param_1;
  if (param_1 == 0) {
    local_2 = g_opstate.vfo_state_a;
    pvVar1 = &g_opstate.vfo_a;
  }
  else {
    local_2 = g_opstate.vfo_state_b;
    pvVar1 = &g_opstate.vfo_b;
  }
  local_8 = pvVar1->freq_be;
  if (local_2 == VFO_STATE_MEMORY) {
    if (PTR_g_ui_00025d58->ch_step_mode == 1) {
      memch_step_down(bVar2);
      return;
    }
    bVar3 = memch_current_is_special(bVar2);
    if (bVar3 == 1) {
      return;
    }
    vfo_enter_memtune_state(param_1 & 0xff);
  }
  uVar4 = FUN_fffc6073(bVar2,(uint)*local_8 << 0x18 | (uint)local_8[1] << 0x10 |
                             (uint)local_8[2] << 8 | (uint)local_8[3]);
  *local_8 = (byte)(uVar4 >> 0x18);
  local_8[1] = (byte)(uVar4 >> 0x10);
  local_8[2] = (byte)(uVar4 >> 8);
  local_c = (byte)uVar4;
  local_8[3] = local_c;
  return;
}


// ===== FUN_fffc81e5 @ fffc81e5 (210 bytes)

void FUN_fffc81e5(undefined1 param_1)

{
  bool bVar1;
  vfo_state local_3;
  bool local_2;
  
  if (g_opstate.active_vfo == VFO_A) {
    local_3 = g_opstate.vfo_state_a;
  }
  else {
    local_3 = g_opstate.vfo_state_b;
  }
  local_2 = g_opstate.active_vfo != VFO_A;
  if ((local_3 == VFO_STATE_LOCKED_7) || (local_3 == VFO_STATE_LOCKED_8)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    memch_step(param_1,local_2);
    return;
  }
  if (g_opstate.split_on == 1) {
    FUN_fffc7fcc();
    return;
  }
  if ((local_3 == VFO_STATE_VFO) || (local_3 == VFO_STATE_PMS)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc7fcc();
    return;
  }
  if (local_3 == VFO_STATE_MEMORY) {
    memch_step(param_1,local_2);
    return;
  }
  if (local_3 == VFO_STATE_MEMTUNE) {
    vm_toggle();
    vfo_enter_mem_state(local_2);
    memtune_flags_clear(local_2);
    return;
  }
  if (local_3 != VFO_STATE_QMB) {
    return;
  }
  if (g_opstate.active_vfo == VFO_A) {
    g_opstate.vfo_state_a = VFO_STATE_VFO;
    return;
  }
  g_opstate.vfo_state_b = VFO_STATE_VFO;
  return;
}


// ===== FUN_fffc82b7 @ fffc82b7 (179 bytes)

void FUN_fffc82b7(char param_1)

{
  if (param_1 < '\x01') {
    if (DAT_0001b4ed < DAT_0001b4ec) {
      DAT_0001b4ec = DAT_0001b4ec - 1;
    }
    else {
      DAT_0001b4ec = DAT_0001b4ee;
    }
  }
  else if (DAT_0001b4ec < DAT_0001b4ee) {
    DAT_0001b4ec = DAT_0001b4ec + 1;
  }
  else {
    DAT_0001b4ec = DAT_0001b4ed;
  }
  if (DAT_0001b4ec == DAT_0001b4ed) {
    PTR_g_ui_00025d58->dl_req_64 = 0;
    PTR_g_ui_00025d58->dl_64_value = 0xff;
    PTR_g_ui_00025d58->dl_64_sent = 0xff;
    return;
  }
  PTR_g_ui_00025d58->dl_req_64 = 1;
  PTR_g_ui_00025d58->dl_64_value = DAT_0001b4ec - 1;
  return;
}


// ===== FUN_fffc836a @ fffc836a (199 bytes)

void FUN_fffc836a(char param_1)

{
  if (PTR_g_ui_00025d58->func_panel_open == 1) {
    if (PTR_g_ui_00025d58->func_knob_item == 0x1d) {
      FUN_fffc8431((int)param_1);
      PTR_g_ui_00025d58->dsp_knob_func = 0;
    }
    else if (PTR_g_ui_00025d58->func_knob_item == 0x1e) {
      FUN_fffc84f9(param_1);
      PTR_g_ui_00025d58->dsp_knob_func = 1;
    }
    else if (PTR_g_ui_00025d58->func_knob_item == 0x1f) {
      FUN_fffc8685((int)param_1);
      PTR_g_ui_00025d58->dsp_knob_func = 2;
    }
    else if (PTR_g_ui_00025d58->func_knob_item == 0x20) {
      FUN_fffc87ab((int)param_1);
      PTR_g_ui_00025d58->dsp_knob_func = 3;
    }
    else if (PTR_g_ui_00025d58->func_knob_item == 0x21) {
      FUN_fffc8930((int)param_1);
      PTR_g_ui_00025d58->dsp_knob_func = 3;
    }
  }
  func_display_open();
  return;
}


// ===== FUN_fffc8431 @ fffc8431 (200 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc84aa) */

void FUN_fffc8431(char param_1)

{
  uint uVar1;
  byte *local_10;
  short local_c;
  vfo_rec *local_8;
  
  if (g_opstate.active_vfo == VFO_A) {
    local_8 = &g_opstate.vfo_a;
  }
  else {
    local_8 = &g_opstate.vfo_b;
  }
  uVar1 = local_8->mode & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_10 = local_8->blk[1].shift_be;
      goto LAB_fffc84a2;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        local_10 = local_8->blk[2].shift_be;
      }
      else {
        if ((local_8->mode & 0xf) != 0 && uVar1 != 1) {
          return;
        }
        local_10 = local_8->blk[0].shift_be;
      }
      goto LAB_fffc84a2;
    }
  }
  local_10 = local_8->blk[3].shift_be;
LAB_fffc84a2:
  local_c = param_1 * 0x14 + CONCAT11(*local_10,local_10[1]);
  if (local_c < 0x4b1) {
    if (local_c < -0x4b0) {
      local_c = -0x4b0;
    }
  }
  else {
    local_c = 0x4b0;
  }
  *local_10 = (byte)((ushort)local_c >> 8);
  local_10[1] = (byte)local_c;
  PTR_g_ui_00025d58->freq_refresh_req = 1;
  return;
}


// ===== FUN_fffc84f9 @ fffc84f9 (396 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc860a) */

void FUN_fffc84f9(char param_1)

{
  uint uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uStack_18;
  short sStack_16;
  byte bStack_14;
  char cStack_13;
  undefined2 uStack_12;
  byte *pbStack_10;
  byte local_9;
  vfo_rec *local_8;
  char local_1;
  
  if (g_opstate.active_vfo == VFO_A) {
    local_8 = &g_opstate.vfo_a;
  }
  else {
    local_8 = &g_opstate.vfo_b;
  }
  local_9 = local_8->mode & 0xf;
  local_1 = param_1;
  uVar2 = vfo_filter_width_hz(&uStack_18);
  if (uVar2 == 0) {
    return;
  }
  uVar1 = (uint)local_9;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      if (local_8->nar_flags != 0) {
        *(undefined2 *)local_8->blk[1].width_be = uStack_18;
        local_8->nar_flags = local_8->nar_flags & 0xdf;
      }
      pbStack_10 = local_8->blk[1].width_be;
      goto LAB_fffc8602;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        if (local_8->nar_flags != 0) {
          *(undefined2 *)local_8->blk[2].width_be = uStack_18;
          local_8->nar_flags = local_8->nar_flags & 0xf7;
        }
        pbStack_10 = local_8->blk[2].width_be;
      }
      else {
        if (1 < uVar1) {
          return;
        }
        if (local_8->nar_flags != 0) {
          *(undefined2 *)local_8->blk[0].width_be = uStack_18;
          local_8->nar_flags = local_8->nar_flags & 0x7f;
        }
        pbStack_10 = local_8->blk[0].width_be;
      }
      goto LAB_fffc8602;
    }
  }
  if (local_8->nar_flags != 0) {
    *(undefined2 *)local_8->blk[3].width_be = uStack_18;
    local_8->nar_flags = local_8->nar_flags & 0xfb;
  }
  pbStack_10 = local_8->blk[3].width_be;
LAB_fffc8602:
  uStack_12 = CONCAT11(*pbStack_10,pbStack_10[1]);
  cStack_13 = FUN_fffb36ff(local_9,uStack_12);
  if ((cStack_13 != -1) && (bStack_14 = FUN_fffb37cd(local_9), bStack_14 != 0xff)) {
    sStack_16 = (short)cStack_13 + (short)local_1;
    if (sStack_16 < 0) {
      cStack_13 = '\0';
    }
    else if ((int)(bStack_14 - 1) < (int)sStack_16) {
      cStack_13 = bStack_14 - 1;
    }
    else {
      cStack_13 = (char)sStack_16;
    }
    uVar3 = FUN_fffb3775(local_9,cStack_13);
    *pbStack_10 = (byte)((ushort)uVar3 >> 8);
    pbStack_10[1] = (byte)uVar3;
    PTR_g_ui_00025d58->freq_refresh_req = 1;
    return;
  }
  return;
}


// ===== FUN_fffc8685 @ fffc8685 (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc875b) */

void FUN_fffc8685(char param_1)

{
  bool bVar1;
  uint uVar2;
  mode_blk *local_14;
  byte *local_10;
  short local_c;
  vfo_rec *local_8;
  
  bVar1 = false;
  if (g_opstate.active_vfo == VFO_A) {
    local_8 = &g_opstate.vfo_a;
  }
  else {
    local_8 = &g_opstate.vfo_b;
  }
  uVar2 = local_8->mode & 0xf;
  if (uVar2 == 0xe) {
LAB_fffc8745:
    local_10 = local_8->blk[3].notch_be;
    local_14 = local_8->blk + 3;
  }
  else {
    if (uVar2 - 2 < 2) {
      local_10 = local_8->blk[1].notch_be;
      local_14 = local_8->blk + 1;
      goto LAB_fffc8753;
    }
    if (uVar2 - 4 < 2) {
      local_10 = local_8->blk[4].notch_be;
      local_14 = local_8->blk + 4;
      bVar1 = true;
      goto LAB_fffc8753;
    }
    if (1 < uVar2 - 6) {
      if (uVar2 - 8 < 2) goto LAB_fffc8745;
      if (1 < uVar2 - 10) {
        if (uVar2 - 0xc < 2) {
          local_10 = local_8->blk[2].notch_be;
          local_14 = local_8->blk + 2;
        }
        else {
          if ((local_8->mode & 0xf) != 0 && uVar2 != 1) {
            return;
          }
          local_10 = local_8->blk[0].notch_be;
          local_14 = local_8->blk;
        }
        goto LAB_fffc8753;
      }
    }
    local_10 = local_8->blk[5].notch_be;
    local_14 = local_8->blk + 5;
    bVar1 = true;
  }
LAB_fffc8753:
  local_c = CONCAT11(*local_10,local_10[1]) + (short)param_1;
  if (local_c < 0x141) {
    if (local_c < 1) {
      local_c = 1;
    }
  }
  else {
    local_c = 0x140;
  }
  *local_10 = (byte)((ushort)local_c >> 8);
  local_10[1] = (byte)local_c;
  if (!bVar1) {
    local_14->flags = local_14->flags | 0x80;
  }
  PTR_g_ui_00025d58->freq_refresh_req = 1;
  return;
}


// ===== FUN_fffc87ab @ fffc87ab (389 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc88b9) */
/* WARNING: Removing unreachable block (ram,0xfffc88ac) */

void FUN_fffc87ab(char param_1)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  byte local_2a [21];
  undefined1 local_15;
  mode_blk *local_14;
  byte *local_10;
  short local_c;
  ushort local_a;
  vfo_rec *local_8;
  char local_1;
  
  local_1 = param_1;
  local_15 = 0;
  bVar2 = false;
  local_2a[0x12] = 3;
  local_2a[0x13] = 4;
  local_2a[0xe] = 4;
  local_2a[0xf] = 0;
  local_2a[0x10] = 1;
  local_2a[0x11] = 2;
  local_2a[10] = 0;
  local_2a[0xb] = 1;
  local_2a[0xc] = 2;
  local_2a[0xd] = 3;
  local_2a[8] = 2;
  local_2a[9] = 1;
  local_2a[4] = 1;
  local_2a[5] = 0;
  local_2a[6] = 4;
  local_2a[7] = 3;
  local_2a[0] = 0;
  local_2a[1] = 4;
  local_2a[2] = 3;
  local_2a[3] = 2;
  if (g_opstate.active_vfo == VFO_A) {
    local_8 = &g_opstate.vfo_a;
  }
  else {
    local_8 = &g_opstate.vfo_b;
  }
  uVar3 = local_8->mode & 0xf;
  if (uVar3 == 0xe) {
LAB_fffc8896:
    local_10 = local_8->blk[3].contour_be;
    local_14 = local_8->blk + 3;
  }
  else {
    if (uVar3 - 2 < 2) {
      local_10 = local_8->blk[1].contour_be;
      local_14 = local_8->blk + 1;
      goto LAB_fffc88a4;
    }
    if (uVar3 - 4 < 2) {
      local_10 = local_8->blk[4].contour_be;
      local_14 = local_8->blk + 4;
      local_15 = 1;
      bVar2 = true;
      goto LAB_fffc88a4;
    }
    if (1 < uVar3 - 6) {
      if (uVar3 - 8 < 2) goto LAB_fffc8896;
      if (1 < uVar3 - 10) {
        if (uVar3 - 0xc < 2) {
          local_10 = local_8->blk[2].contour_be;
          local_14 = local_8->blk + 2;
        }
        else {
          if ((local_8->mode & 0xf) != 0 && uVar3 != 1) {
            return;
          }
          local_10 = local_8->blk[0].contour_be;
          local_14 = local_8->blk;
        }
        goto LAB_fffc88a4;
      }
    }
    local_10 = local_8->blk[5].contour_be;
    local_14 = local_8->blk + 5;
    local_15 = 1;
    bVar2 = true;
  }
LAB_fffc88a4:
  local_a = CONCAT11(*local_10,local_10[1]);
  local_2a[0x14] = local_10[1] + (char)(local_a / 10) * -10;
  if (param_1 < '\x01') {
    uVar1 = (ushort)local_2a[local_2a[0x14]];
  }
  else {
    uVar1 = -(ushort)local_2a[local_2a[0x14] + 10];
  }
  local_a = local_a + uVar1;
  local_c = param_1 * 5 + local_a;
  if (local_c < 0x141) {
    if (local_c < 5) {
      local_c = 5;
    }
  }
  else {
    local_c = 0x140;
  }
  *local_10 = (byte)((ushort)local_c >> 8);
  local_10[1] = (byte)local_c;
  if (!bVar2) {
    local_14->flags = local_14->flags | 0x40;
  }
  PTR_g_ui_00025d58->freq_refresh_req = 1;
  return;
}


// ===== FUN_fffc8930 @ fffc8930 (128 bytes)

void FUN_fffc8930(char param_1)

{
  int local_8;
  short local_4;
  
  local_4 = (short)g_opstate.apf_freq + (short)param_1;
  if (local_4 < 0x1a) {
    if (local_4 < -0x19) {
      local_4 = -0x19;
    }
  }
  else {
    local_4 = 0x19;
  }
  g_opstate.apf_freq = (sbyte)local_4;
  PTR_g_ui_00025d58->freq_refresh_req = 1;
  if (g_opstate.active_vfo == VFO_A) {
    local_8 = 0x9d09;
  }
  else {
    local_8 = 0x9d63;
  }
  *(byte *)(local_8 + 0x14) = *(byte *)(local_8 + 0x14) | 0x20;
  PTR_g_ui_00025d58->freq_refresh_req = 1;
  return;
}


// ===== func_display_open @ fffc89b0 (63 bytes)

/* Opens the FUNC-knob function display: closes pop-up, menu and FUNC panel, UI +0x70 = 1, +0x74 =
   0, 5 s timer 0x44 [fact] (cat-commands-primary.md SF) */

void func_display_open(void)

{
  if (PTR_g_ui_00025d58->func_panel_open == 0) {
    popup_close();
    menu_close_if_open();
    func_panel_close();
    PTR_g_ui_00025d58->func_panel_open = 1;
    PTR_g_ui_00025d58->dsp_knob_edit = 0;
  }
  swtimer_start(0x44,5000);
  return;
}


// ===== FUN_fffc89ef @ fffc89ef (161 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc8a6e) */

void FUN_fffc89ef(byte param_1)

{
  ui_state *puVar1;
  ushort local_4;
  
  PTR_g_ui_00025d58->popup_code = 0x5e;
  DAT_00012229 = ' ';
  DAT_00012225 = 0x20202020;
  DAT_00012221 = 0x204e4f43;
  if (param_1 < 10) {
    local_4 = 7;
  }
  else if (param_1 < 100) {
    local_4 = 6;
  }
  else {
    local_4 = 5;
  }
  dec_to_str_u8(param_1,(int)&DAT_00012221 + (uint)local_4);
  puVar1 = PTR_g_ui_00025d58;
  PTR_g_ui_00025d58->popup_text[8] = DAT_00012229;
  *(undefined4 *)(puVar1->popup_text + 4) = DAT_00012225;
  *(undefined4 *)puVar1->popup_text = DAT_00012221;
  popup_duration_get(0x5e);
  popup_open_timed();
  local_4._0_1_ = (byte)(((uint)param_1 * 0x14) / 0xff);
  PTR_g_ui_00025d58->svc_contrast = (byte)local_4;
  PTR_g_ui_00025d58->dl_req_24 = 1;
  return;
}


// ===== FUN_fffc8a90 @ fffc8a90 (197 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc8b33) */

void FUN_fffc8a90(byte param_1)

{
  ui_state *puVar1;
  byte bStack_4;
  
  PTR_g_ui_00025d58->popup_code = 0x5e;
  DAT_00012232 = ' ';
  DAT_0001222e = 0x20202020;
  DAT_0001222a = 0x204d4944;
  if (param_1 == 0) {
    DAT_0001222e = 0x46464f20;
  }
  else if (param_1 < 10) {
    dec_to_str_u8(param_1,0x12231);
  }
  else if (param_1 < 100) {
    dec_to_str_u8(param_1,0x12230);
  }
  else {
    dec_to_str_u8(param_1,0x1222f);
  }
  puVar1 = PTR_g_ui_00025d58;
  PTR_g_ui_00025d58->popup_text[8] = DAT_00012232;
  *(undefined4 *)(puVar1->popup_text + 4) = DAT_0001222e;
  *(undefined4 *)puVar1->popup_text = DAT_0001222a;
  popup_duration_get(0x5e);
  popup_open_timed();
  bStack_4 = (byte)(((uint)param_1 * 0x14) / 0xff);
  PTR_g_ui_00025d58->svc_brightness = bStack_4;
  PTR_g_ui_00025d58->dl_req_24 = 1;
  return;
}


// ===== FUN_fffc8b55 @ fffc8b55 (42 bytes)

void FUN_fffc8b55(void)

{
  FUN_fffc8b7f();
  FUN_fffc8dd8();
  FUN_fffc8e26();
  FUN_fffc8ee2();
  FUN_fffc9046();
  FUN_fffbba2e();
  FUN_fffc8fa6();
  FUN_fffc8f48();
  FUN_fffe1ee4();
  FUN_fffc9084();
  FUN_fffc90cb();
  FUN_fffc8ff9();
  FUN_fffc90fc();
  return;
}


// ===== FUN_fffc8b7f @ fffc8b7f (108 bytes)

void FUN_fffc8b7f(void)

{
  uint uVar1;
  byte bVar2;
  
  if ((((DAT_0001b4ef != '\0') && (PTR_g_ui_00025d5c->dl_req_popup_b == 1)) &&
      (uVar1 = (uint)PTR_g_ui_00025d5c->popup_code, 2 < uVar1 - 6)) &&
     (((uVar1 != 0xd && (uVar1 != 0x49)) &&
      ((PTR_g_ui_00025d5c->popup_code < 0x5f && (bVar2 = swtimer_expired(0x39), bVar2 == 1)))))) {
    popup_close();
    DAT_0001b4f3 = 1;
    swtimer_start(0x49,200);
    return;
  }
  return;
}


// ===== popup_close @ fffc8beb (189 bytes)

/* UI +0x1C2 = 0xFF, +0x1C1 = 0, +0x1C0 = 1, 0x1B4EF = 0, clears +0x8F / +0x41C (+0x43B / +0x43C for
   codes 'U'/'D'/'E') [fact] */

void popup_close(void)

{
  bool bVar1;
  
  FUN_fffc15d4();
  if ((PTR_g_ui_00025d5c->popup_code == 0x55) || (PTR_g_ui_00025d5c->popup_code == 0x44)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_g_ui_00025d5c->popup_code == 0x45)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_g_ui_00025d5c->memlist_edit_on = 0;
    PTR_g_ui_00025d5c->memlist_popup55 = 0;
  }
  PTR_g_ui_00025d5c->dl_req_popup_b = 0;
  PTR_g_ui_00025d5c->popup_hold = 0;
  PTR_g_ui_00025d5c->f_0x41c_u8 = 0;
  FUN_fffe1f3d();
  PTR_g_ui_00025d5c->dl_req_popup_a = 1;
  PTR_g_ui_00025d5c->popup_code = 0xff;
  DAT_0001b4ef = 0;
  popup_mark_clear();
  return;
}


// ===== FUN_fffc8ca8 @ fffc8ca8 (19 bytes)

byte FUN_fffc8ca8(void)

{
  return PTR_g_ui_00025d5c->dl_req_popup_b;
}


// ===== popup_duration_get @ fffc8cbb (209 bytes)

/* (id): display time of pop-up id for POP-UP TIME 0x9B0E: index tables 0xFFF834BE (ids 0..0xD) /
   0xFFF834D6 (0x1E..0x58) select a 3 x u16 row in 0xFFF8854E / 0xFFF88566; id 0x5E uses 0xFFF88578
   [fact] (#157, listing check) */

undefined2 popup_duration_get(byte param_1)

{
  bool bVar1;
  undefined2 local_a;
  char local_8;
  
  if (param_1 < 0xe) {
    local_8 = '\0';
  }
  else {
    if ((param_1 < 0x1e) || (0x58 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_8 = '\x01';
    }
    else {
      if (param_1 != 0x5e) {
        return 0;
      }
      local_8 = '\x02';
    }
  }
  if (local_8 == '\0') {
    if (0xd < param_1) {
      return 0;
    }
    local_a = *(undefined2 *)
               ((uint)BYTE_ARRAY_fff834be[param_1 + 0xd] * 6 + -0x77ab2 +
               (uint)g_opstate.ex040103_pop_up_time * 2);
  }
  else if (local_8 == '\x01') {
    if (0x3a < (byte)(param_1 - 0x1e)) {
      return 0;
    }
    local_a = *(undefined2 *)
               ((uint)BYTE_ARRAY_fff834d6[(byte)(param_1 - 0x1e) + 3] * 6 + -0x77a9a +
               (uint)g_opstate.ex040103_pop_up_time * 2);
  }
  else {
    local_a = *(undefined2 *)(BYTE_ARRAY_fff88514 + (uint)g_opstate.ex040103_pop_up_time * 2 + 100);
  }
  return local_a;
}


// ===== popup_open_timed @ fffc8d8c (76 bytes)

/* (time): 0x1B4EF = 1 and soft timer 0x39 = time (0: no timer), UI +0x1C1 = 1 (shown), +0x1C0 = 1,
   +0x70 = 0 [fact]; callers pass popup_duration_get(code) [fact] */

void popup_open_timed(int param_1)

{
  if (param_1 == 0) {
    DAT_0001b4ef = 0;
  }
  else {
    DAT_0001b4ef = 1;
    swtimer_start(0x39,(ushort)param_1);
  }
  PTR_g_ui_00025d5c->dl_req_popup_b = 1;
  PTR_g_ui_00025d5c->dl_req_popup_a = 1;
  PTR_g_ui_00025d5c->func_panel_open = 0;
  return;
}


// ===== FUN_fffc8dd8 @ fffc8dd8 (54 bytes)

void FUN_fffc8dd8(void)

{
  byte bVar1;
  
  if ((DAT_0001b4f0 != '\0') && (bVar1 = swtimer_expired(0x3a), bVar1 == 1)) {
    DAT_0001b4f0 = 0;
    func_panel_close();
    popup_close();
    PTR_g_ui_00025d5c->func_cursor_locked = 0;
    return;
  }
  return;
}


// ===== FUN_fffc8e0e @ fffc8e0e (24 bytes)

void FUN_fffc8e0e(ushort param_1)

{
  DAT_0001b4f0 = 1;
  swtimer_start(0x3a,param_1);
  return;
}


// ===== FUN_fffc8e26 @ fffc8e26 (150 bytes)

void FUN_fffc8e26(void)

{
  byte bVar1;
  
  if (PTR_g_ui_00025d5c->digit_step_on != 0) {
    bVar1 = blink_phase(0);
    if (bVar1 == 1) {
      if (DAT_0001b4f5 != '\x01') {
        PTR_g_ui_00025d5c->digit_step_blink_on = 0;
        DAT_0001b4f5 = '\x01';
        PTR_g_ui_00025d5c->digit_step_blinks = PTR_g_ui_00025d5c->digit_step_blinks + 1;
        if (5 < PTR_g_ui_00025d5c->digit_step_blinks) {
          PTR_g_ui_00025d5c->digit_step_blinks = 0;
          PTR_g_ui_00025d5c->digit_step_on = 0;
          return;
        }
      }
    }
    else if (DAT_0001b4f5 != '\0') {
      PTR_g_ui_00025d5c->digit_step_blink_on = 1;
      DAT_0001b4f5 = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffc8ebc @ fffc8ebc (38 bytes)

void FUN_fffc8ebc(void)

{
  PTR_g_ui_00025d5c->digit_step_blinks = 0;
  PTR_g_ui_00025d5c->digit_step_blink_on = 0;
  swtimer_start(0x3d,0x1c2);
  return;
}


// ===== FUN_fffc8ee2 @ fffc8ee2 (78 bytes)

void FUN_fffc8ee2(void)

{
  byte bVar1;
  
  if ((((DAT_0001b4f1 != '\0') && (bVar1 = swtimer_expired(0x3e), bVar1 == 1)) &&
      (DAT_0001b4f1 = '\0', PTR_g_ui_00025d5c->dl_req_40 == 1)) &&
     (PTR_g_ui_00025d5c->menu_state == 3)) {
    PTR_g_ui_00025d5c->menu_state = 2;
    return;
  }
  return;
}


// ===== FUN_fffc8f30 @ fffc8f30 (24 bytes)

void FUN_fffc8f30(ushort param_1)

{
  DAT_0001b4f1 = 1;
  swtimer_start(0x3e,param_1);
  return;
}

