// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== memtune_backup_b @ fffc1913 (20 bytes)

/* 0x9D63 -> 0x9E28 */

void memtune_backup_b(void)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  pvVar2 = &g_opstate.vfo_b;
  pvVar1 = &g_opstate.memtune_b;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    pvVar1->mode = pvVar2->mode;
    pvVar1 = (vfo_rec *)&pvVar1->flags1;
    pvVar2 = (vfo_rec *)&pvVar2->flags1;
  }
  return;
}


// ===== bandstack_save @ fffc1927 (230 bytes)

/* Record -> band-stack slot 0x4761/0x5409 + level*0x438 + band*0x5A, EEPROM if changed */

void bandstack_save(void)

{
  uint uVar1;
  vfo_rec *pvVar2;
  int iVar3;
  vfo_rec *pvVar4;
  bool local_13;
  byte bStack_12;
  band_idx bStack_11;
  vfo_rec (*pavStack_c) [12];
  vfo_rec *pvStack_4;
  
  local_13 = g_opstate.active_vfo == VFO_A;
  if (local_13) {
    uVar1 = vfo_freq(0,0);
    g_opstate.band_a = band_of_freq(uVar1);
    pvStack_4 = &g_opstate.vfo_a;
    bStack_12 = bandstack_level_a[g_opstate.band_a];
    pavStack_c = bandstack_a + bStack_12;
    bStack_11 = g_opstate.band_a;
  }
  else {
    uVar1 = vfo_freq(0,1);
    g_opstate.band_b = band_of_freq(uVar1);
    pvStack_4 = &g_opstate.vfo_b;
    bStack_12 = bandstack_level_b[g_opstate.band_b];
    pavStack_c = bandstack_b + bStack_12;
    bStack_11 = g_opstate.band_b;
  }
  local_13 = !local_13;
  pvVar2 = *pavStack_c + bStack_11;
  iVar3 = strncmp(pvVar2,pvStack_4,0x5a);
  if (iVar3 == 0) {
    return;
  }
  pvVar4 = pvVar2;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    pvVar4->mode = pvStack_4->mode;
    pvVar4 = (vfo_rec *)&pvVar4->flags1;
    pvStack_4 = (vfo_rec *)&pvStack_4->flags1;
  }
  eeprom_save_bandstack(local_13,bStack_11,bStack_12,(uint)pvVar2);
  return;
}


// ===== FUN_fffc1a0d @ fffc1a0d (40 bytes)

void FUN_fffc1a0d(void)

{
  g_opstate.memtune_a.mode = g_opstate.vfo_a.mode;
  g_opstate.memtune_a.freq_be = g_opstate.vfo_a.freq_be;
  PTR_g_ui_00025d54->memtune_valid_a = 1;
  return;
}


// ===== FUN_fffc1a35 @ fffc1a35 (42 bytes)

void FUN_fffc1a35(void)

{
  g_opstate.memtune_b.mode = g_opstate.vfo_b.mode;
  g_opstate.memtune_b.freq_be = g_opstate.vfo_b.freq_be;
  PTR_g_ui_00025d54->memtune_valid_a = 1;
  return;
}


// ===== band_select_pms @ fffc1a5f (73 bytes)

/* Band key in PMS state */

void band_select_pms(char param_1,byte param_2)

{
  if (param_1 == '\0') {
    if (g_opstate.vfo_state_a == VFO_STATE_PMS) {
      g_opstate.vfo_state_a = VFO_STATE_VFO;
    }
  }
  else if (g_opstate.vfo_state_b == VFO_STATE_PMS) {
    g_opstate.vfo_state_b = VFO_STATE_VFO;
  }
  band_select_mem(param_1,param_2);
  return;
}


// ===== band_select_mem @ fffc1aa8 (39 bytes)

/* Band key in memory state */

void band_select_mem(byte param_1,byte param_2)

{
  byte bVar1;
  
  bVar1 = memch_current_is_special(param_1);
  if (bVar1 != 0) {
    return;
  }
  vfo_clear_tag(param_1);
  vfo_enter_vfo_state(param_1);
  FUN_fffc18bf();
  band_select_stack(param_1,param_2);
  return;
}


// ===== band_select_memtune @ fffc1acf (23 bytes)

/* Band key in memory-tune state */

void band_select_memtune(byte param_1,byte param_2)

{
  vfo_enter_vfo_state(param_1);
  FUN_fffc18bf();
  band_select_stack(param_1,param_2);
  return;
}


// ===== band_select_vfo @ fffc1ae6 (73 bytes)

/* Band key in VFO/QMB state */

void band_select_vfo(char param_1,byte param_2)

{
  if (param_1 == '\0') {
    if (g_opstate.vfo_state_a == VFO_STATE_QMB) {
      g_opstate.vfo_state_a = VFO_STATE_VFO;
    }
  }
  else if (g_opstate.vfo_state_b == VFO_STATE_QMB) {
    g_opstate.vfo_state_b = VFO_STATE_VFO;
  }
  band_select_stack(param_1,param_2);
  return;
}


// ===== band_select_stack @ fffc1b2f (213 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc1bcf) */
/* WARNING: Removing unreachable block (ram,0xfffc1b7d) */
/* (side, band): same band steps stack level mod 3 (if 0x9AC1), then vfo_reload */

void band_select_stack(char param_1,byte param_2)

{
  band_idx bVar1;
  band_idx bVar2;
  byte local_3;
  
  if (param_1 == '\0') {
    bVar1 = param_2;
    bVar2 = g_opstate.band_b;
    if (g_opstate.band_a == param_2) {
      local_3 = bandstack_level_a[g_opstate.band_a];
      if (g_opstate.ex030113_band_stack != 0) {
        local_3 = (char)(local_3 + 1) + (char)((local_3 + 1) / 3) * -3;
      }
      bandstack_level_a[g_opstate.band_a] = local_3;
      bVar1 = g_opstate.band_a;
      bVar2 = g_opstate.band_b;
    }
  }
  else {
    bVar1 = g_opstate.band_a;
    bVar2 = param_2;
    if (g_opstate.band_b == param_2) {
      local_3 = bandstack_level_b[g_opstate.band_b];
      if (g_opstate.ex030113_band_stack != 0) {
        local_3 = (char)(local_3 + 1) + (char)((local_3 + 1) / 3) * -3;
      }
      bandstack_level_b[g_opstate.band_b] = local_3;
      bVar1 = g_opstate.band_a;
      bVar2 = g_opstate.band_b;
    }
  }
  g_opstate.band_b = bVar2;
  g_opstate.band_a = bVar1;
  vfo_reload(g_opstate.active_vfo);
  PTR_g_ui_00025d54->vfo_refresh_req = 1;
  return;
}


// ===== vfo_reload @ fffc1c04 (186 bytes)

/* Reload operating record by state (band stack / memory / memory tune) */

void vfo_reload(byte param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if (PTR_g_ui_00025d54->force_bandstack_a == 1) {
      vfo_reload_bandstack(0);
      return;
    }
    if ((g_opstate.vfo_state_a == VFO_STATE_MEMTUNE) || (g_opstate.vfo_state_a == VFO_STATE_PMS)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if (g_opstate.vfo_state_a == VFO_STATE_MEMORY) {
        vfo_reload_memory(0);
        return;
      }
      vfo_reload_bandstack(0);
      return;
    }
    FUN_fffc1d95();
    return;
  }
  if (PTR_g_ui_00025d54->force_bandstack_b == 1) {
    vfo_reload_bandstack(1);
    return;
  }
  if ((g_opstate.vfo_state_b == VFO_STATE_MEMTUNE) || (g_opstate.vfo_state_b == VFO_STATE_PMS)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (g_opstate.vfo_state_b == VFO_STATE_MEMORY) {
      vfo_reload_memory(1);
      return;
    }
    vfo_reload_bandstack(1);
    return;
  }
  FUN_fffc1dca();
  return;
}


// ===== vfo_reload_bandstack @ fffc1cbe (27 bytes)

/* bandstack_load + vfo_retune, split off */

void vfo_reload_bandstack(byte param_1)

{
  bandstack_load(param_1);
  vfo_retune(param_1);
  g_opstate.split_on = 0;
  return;
}


// ===== bandstack_load @ fffc1cd9 (188 bytes)

/* Band-stack slot -> operating record (QMB slot in state 5) */

void bandstack_load(byte param_1)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  if (param_1 == 0) {
    if (g_opstate.vfo_state_a != VFO_STATE_QMB) {
      pvVar1 = &g_opstate.vfo_a;
      pvVar2 = bandstack_a[bandstack_level_a[g_opstate.band_a]] + g_opstate.band_a;
      for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
        pvVar1->mode = pvVar2->mode;
        pvVar1 = (vfo_rec *)&pvVar1->flags1;
        pvVar2 = (vfo_rec *)&pvVar2->flags1;
      }
      return;
    }
    FUN_fffc31a7(0,1);
    FUN_fffc334c(0);
    return;
  }
  if (g_opstate.vfo_state_b != VFO_STATE_QMB) {
    pvVar1 = &g_opstate.vfo_b;
    pvVar2 = bandstack_b[bandstack_level_b[g_opstate.band_b]] + g_opstate.band_b;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pvVar1->mode = pvVar2->mode;
      pvVar1 = (vfo_rec *)&pvVar1->flags1;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
    }
    return;
  }
  FUN_fffc31a7(param_1,1);
  FUN_fffc334c(param_1);
  return;
}


// ===== FUN_fffc1d95 @ fffc1d95 (49 bytes)

void FUN_fffc1d95(void)

{
  if (PTR_g_ui_00025d54->memtune_valid_a == 0) {
    vfo_reload_memory(0);
    return;
  }
  if (PTR_g_ui_00025d54->memtune_backup_a != 1) {
    memch_load_to_vfo('\0');
    FUN_fffc1e37();
    return;
  }
  FUN_fffc1dc6();
  return;
}


// ===== FUN_fffc1dc6 @ fffc1dc6 (4 bytes)

void FUN_fffc1dc6(void)

{
  memtune_restore_a();
  return;
}


// ===== FUN_fffc1dca @ fffc1dca (49 bytes)

void FUN_fffc1dca(void)

{
  if (PTR_g_ui_00025d54->memtune_valid_b == 0) {
    vfo_reload_memory(1);
    return;
  }
  if (PTR_g_ui_00025d54->memtune_backup_b != 1) {
    memch_load_to_vfo('\x01');
    FUN_fffc1e52();
    return;
  }
  FUN_fffc1dfb();
  return;
}


// ===== FUN_fffc1dfb @ fffc1dfb (4 bytes)

void FUN_fffc1dfb(void)

{
  memtune_restore_b();
  return;
}


// ===== vfo_reload_memory @ fffc1dff (16 bytes)

/* memch_load_to_vfo + vfo_retune */

void vfo_reload_memory(byte param_1)

{
  memch_load_to_vfo(param_1);
  vfo_retune(param_1);
  return;
}


// ===== memtune_restore_a @ fffc1e0f (20 bytes)

/* 0x9DCE -> 0x9D09 */

void memtune_restore_a(void)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  pvVar2 = &g_opstate.memtune_a;
  pvVar1 = &g_opstate.vfo_a;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    pvVar1->mode = pvVar2->mode;
    pvVar1 = (vfo_rec *)&pvVar1->flags1;
    pvVar2 = (vfo_rec *)&pvVar2->flags1;
  }
  return;
}


// ===== memtune_restore_b @ fffc1e23 (20 bytes)

/* 0x9E28 -> 0x9D63 */

void memtune_restore_b(void)

{
  vfo_rec *pvVar1;
  vfo_rec *pvVar2;
  int iVar3;
  
  pvVar2 = &g_opstate.memtune_b;
  pvVar1 = &g_opstate.vfo_b;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    pvVar1->mode = pvVar2->mode;
    pvVar1 = (vfo_rec *)&pvVar1->flags1;
    pvVar2 = (vfo_rec *)&pvVar2->flags1;
  }
  return;
}


// ===== FUN_fffc1e37 @ fffc1e37 (27 bytes)

void FUN_fffc1e37(void)

{
  g_opstate.vfo_a.mode = g_opstate.memtune_a.mode;
  g_opstate.vfo_a.freq_be = g_opstate.memtune_a.freq_be;
  return;
}


// ===== FUN_fffc1e52 @ fffc1e52 (29 bytes)

void FUN_fffc1e52(void)

{
  g_opstate.vfo_b.mode = g_opstate.memtune_b.mode;
  g_opstate.vfo_b.freq_be = g_opstate.memtune_b.freq_be;
  return;
}


// ===== FUN_fffc1e6f @ fffc1e6f (111 bytes)

void FUN_fffc1e6f(void)

{
  byte *pbVar1;
  vfo_rec *pvVar2;
  vfo_rec *pvVar3;
  int iVar4;
  
  if (PTR_g_ui_00025d54->txw_swap != 1) {
    return;
  }
  PTR_g_ui_00025d54->txw_swap = 0;
  pvVar2 = &g_opstate.vfo_a;
  pbVar1 = &DAT_0001216d;
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
  pbVar1 = &DAT_0001216d;
  for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
    pvVar2->mode = *pbVar1;
    pvVar2 = (vfo_rec *)&pvVar2->flags1;
    pbVar1 = pbVar1 + 1;
  }
  PTR_g_ui_00025d54->vfo_refresh_req = 1;
  beep_request(1);
  return;
}


// ===== func_knob_assign_key @ fffc1ede (76 bytes)

/* (key 0xD0..0xF3): 0x9C08 (FUNC knob function) = ROM table[key - 0xD0] unless -1, then the FUNC
   item action FUN_fffc3b22 [fact] */

void func_knob_assign_key(short param_1)

{
  ushort local_4;
  
  local_4 = param_1 - 0xd0;
  if (0x23 < local_4) {
    local_4 = 0;
  }
  if (" 001 [GN] VDD MTR         002 [GN] FAN             003 [GN] REF FREQ        004 [GN] TX INH          005 [GN] --RESERVED--    006 [GN] --RESERVED--    007 [GN] --RESERVED--    008 [GN] DBG MODE ENABLE 009 [MT] PO MTR 100W POS 010 [MT] PO MTR  50W POS 011 [MT] PO MTR  20W POS 012 [MT] PO MTR  10W POS 013 [MT] PO MTR   5W POS 014 [MT] ALC MTR POS     015 [MT] VDD MTR POS     016 [MT] IDD MTR POS     017 [MT] SWR 1.5 MTR POS 018 [MT] SWR 2.0 MTR POS 019 [MT] SWR 3.0 MTR POS 020 [MT] --RESERVED--    021 [MT] --RESERVED--    022 [MT] --RESERVED--    023 [RX] RF-AGC  7       024 [RX] RF-AGC 14       025 [RX] RF-AGC 21       026 [RX] RF-AGC 28       027 [RX] RF-AGC 50       028 [RX] IF-AGC  7       029 [RX] IF-AGC 14       030 [RX] IF-AGC 21       031 [RX] IF-AGC 28       032 [RX] IF-AGC 50       033 [RX] S-MTR 0         034 [RX] S-MTR 2         035 [RX] S-MTR 5         036 [RX] S-MTR 7         037 [RX] S-MTR 9         038 [RX] S-MTR +10       039 [RX] S-MTR +20       040 [RX] S-MTR +30       041 [RX] S-MTR +40       042 [RX] S-MTR +50       043 [RX] S-MTR +60       044 [RX] --RESERVED--    045 [RX] --RESERVED--    046 [RX] FM SQL THW      047 [RX] FM SQL THN      048 [RX] FM SQL TI       049 [RX] SCOPE SDR REF   050 [TX] MF PREDR BIAS   051 [TX] MF DRIVE BIAS   052 [TX] MF FINAL BIAS   053 [TX] HF PREDR BIAS   054 [TX] HF DRIVE BIAS   055 [TX] HF FINAL BIAS   056 [TX] VHF PREDR BIAS  057 [TX] VHF DRIVE BIAS  058 [TX] VHF FINAL BIAS  059 [TX] I-ALC 1.8       060 [TX] I-ALC 3.5       061 [TX] I-ALC 7         062 [TX] I-ALC 10        063 [TX] I-ALC 14        064 [TX] I-ALC 18        065 [TX] I-ALC 21        066 [TX] I-ALC 24        067 [TX] I-ALC 28        068 [TX] I-ALC 50        069 [TX] I-ALC 70        070 [TX] 100W FALC 1.8   071 [TX] 100W MTR  1.8   072 [TX] 100W TXG  1.8   073 [TX]  50W FALC 1.8   074 [TX]  50W MTR  1.8   075 [TX]  50W TXG  1.8   076 [TX]  20W FALC 1.8   077 [TX]  20W MTR  1.8   078 [TX]  20W TXG  1.8   079 [TX]  10W FALC 1.8   080 [TX]  10W MTR  1.8   081 [TX]  10W TXG  1.8   082 [TX]   5W FALC 1.8..." /* TRUNCATED STRING LITERAL */
      [local_4 + 0x197d] != -1) {
    g_opstate.func_knob_sf =
         " 001 [GN] VDD MTR         002 [GN] FAN             003 [GN] REF FREQ        004 [GN] TX INH          005 [GN] --RESERVED--    006 [GN] --RESERVED--    007 [GN] --RESERVED--    008 [GN] DBG MODE ENABLE 009 [MT] PO MTR 100W POS 010 [MT] PO MTR  50W POS 011 [MT] PO MTR  20W POS 012 [MT] PO MTR  10W POS 013 [MT] PO MTR   5W POS 014 [MT] ALC MTR POS     015 [MT] VDD MTR POS     016 [MT] IDD MTR POS     017 [MT] SWR 1.5 MTR POS 018 [MT] SWR 2.0 MTR POS 019 [MT] SWR 3.0 MTR POS 020 [MT] --RESERVED--    021 [MT] --RESERVED--    022 [MT] --RESERVED--    023 [RX] RF-AGC  7       024 [RX] RF-AGC 14       025 [RX] RF-AGC 21       026 [RX] RF-AGC 28       027 [RX] RF-AGC 50       028 [RX] IF-AGC  7       029 [RX] IF-AGC 14       030 [RX] IF-AGC 21       031 [RX] IF-AGC 28       032 [RX] IF-AGC 50       033 [RX] S-MTR 0         034 [RX] S-MTR 2         035 [RX] S-MTR 5         036 [RX] S-MTR 7         037 [RX] S-MTR 9         038 [RX] S-MTR +10       039 [RX] S-MTR +20       040 [RX] S-MTR +30       041 [RX] S-MTR +40       042 [RX] S-MTR +50       043 [RX] S-MTR +60       044 [RX] --RESERVED--    045 [RX] --RESERVED--    046 [RX] FM SQL THW      047 [RX] FM SQL THN      048 [RX] FM SQL TI       049 [RX] SCOPE SDR REF   050 [TX] MF PREDR BIAS   051 [TX] MF DRIVE BIAS   052 [TX] MF FINAL BIAS   053 [TX] HF PREDR BIAS   054 [TX] HF DRIVE BIAS   055 [TX] HF FINAL BIAS   056 [TX] VHF PREDR BIAS  057 [TX] VHF DRIVE BIAS  058 [TX] VHF FINAL BIAS  059 [TX] I-ALC 1.8       060 [TX] I-ALC 3.5       061 [TX] I-ALC 7         062 [TX] I-ALC 10        063 [TX] I-ALC 14        064 [TX] I-ALC 18        065 [TX] I-ALC 21        066 [TX] I-ALC 24        067 [TX] I-ALC 28        068 [TX] I-ALC 50        069 [TX] I-ALC 70        070 [TX] 100W FALC 1.8   071 [TX] 100W MTR  1.8   072 [TX] 100W TXG  1.8   073 [TX]  50W FALC 1.8   074 [TX]  50W MTR  1.8   075 [TX]  50W TXG  1.8   076 [TX]  20W FALC 1.8   077 [TX]  20W MTR  1.8   078 [TX]  20W TXG  1.8   079 [TX]  10W FALC 1.8   080 [TX]  10W MTR  1.8   081 [TX]  10W TXG  1.8   082 [TX]   5W FALC 1.8..." /* TRUNCATED STRING LITERAL */
         [local_4 + 0x197d];
    func_menu_select(g_opstate.func_knob_sf);
    return;
  }
  return;
}


// ===== FUN_fffc1f2a @ fffc1f2a (106 bytes)

void FUN_fffc1f2a(byte param_1)

{
  PTR_g_ui_00025d54->menu_p1 = param_1;
  FUN_fffc98b3();
  PTR_g_ui_00025d54->dl_req_40 = 1;
  if (PTR_g_ui_00025d54->menu_state == 3) {
    PTR_g_ui_00025d54->menu_state = 2;
  }
  func_panel_close();
  if (param_1 != 5) {
    beep_request(1);
    PTR_g_ui_00025d54->key_consumed = 1;
    return;
  }
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== FUN_fffc1f94 @ fffc1f94 (34 bytes)

void FUN_fffc1f94(void)

{
  func_panel_close();
  if (DAT_0001b4da == '\0') {
    beep_request(1);
  }
  PTR_g_ui_00025d54->key_consumed = 1;
  return;
}


// ===== memlist_key @ fffc1fb6 (295 bytes)

/* (key 4..9): MEMORY CH LIST (+0x97) keys: cursor and select (+0x1D9..+0x1DB, +0x43A..+0x43C),
   stores with eeprom_save_memch, 9 closes [fact for the fields] */

void memlist_key(byte param_1)

{
  uint uVar1;
  bool bVar2;
  
  if (PTR_g_ui_00025d54->memlist_open != 0) {
    PTR_g_ui_00025d54->memlist_edit_on = 0;
    uVar1 = (uint)param_1;
    if (uVar1 == 9) {
      if (PTR_g_ui_00025d54->memlist_flag == 1) {
        PTR_g_ui_00025d54->memlist_group = param_1 - 4;
        FUN_fffc20dd();
        return;
      }
      memlist_close();
      beep_request(1);
      return;
    }
    if (uVar1 - 4 < 4) {
      if (param_1 != 4) {
        PTR_g_ui_00025d54->memlist_edit_on = 1;
      }
      if ((PTR_g_ui_00025d54->memlist_flag == 1) && (PTR_g_ui_00025d54->memlist_popup55 == 1)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        PTR_g_ui_00025d54->memlist_popup55 = 0;
        beep_request(1);
        return;
      }
      PTR_g_ui_00025d54->memlist_group = param_1 - 4;
      if (PTR_g_ui_00025d54->memlist_flag == 0) {
        memlist_cursor_channel();
      }
      FUN_fffc20dd();
      return;
    }
    if (uVar1 == 8) {
      FUN_fffc22de();
      eeprom_save_memch(PTR_g_ui_00025d54->memlist_ch);
      return;
    }
    if (uVar1 < 4) {
      PTR_g_ui_00025d54->memlist_row = param_1;
      PTR_g_ui_00025d54->memlist_flag = 0;
      PTR_g_ui_00025d54->memlist_popup55 = 0;
      memlist_cursor_channel();
      beep_request(1);
      return;
    }
  }
  return;
}


// ===== FUN_fffc20dd @ fffc20dd (90 bytes)

void FUN_fffc20dd(void)

{
  byte bVar1;
  
  bVar1 = PTR_g_ui_00025d54->memlist_group;
  if (bVar1 == 5) {
    PTR_g_ui_00025d54->memlist_flag = 0;
    PTR_g_ui_00025d54->key_consumed = 1;
    beep_request(1);
    return;
  }
  if (bVar1 == 1) {
    FUN_fffc21e8();
    return;
  }
  if (bVar1 == 2) {
    FUN_fffc224e();
    return;
  }
  if (bVar1 == 3) {
    FUN_fffc2296();
    return;
  }
  if (bVar1 == 4) {
    FUN_fffc22de();
    return;
  }
  if (bVar1 != 0) {
    return;
  }
  FUN_fffc2137();
  return;
}


// ===== FUN_fffc2137 @ fffc2137 (144 bytes)

void FUN_fffc2137(void)

{
  byte bVar1;
  ui_state *puVar2;
  bool bVar3;
  byte (*pabVar4) [50];
  int iVar5;
  byte *pbStack_4;
  
  bVar3 = memch_valid(PTR_g_ui_00025d54->memlist_ch,&pbStack_4);
  if (bVar3) {
    PTR_g_ui_00025d54->kbd_open = 1;
    PTR_g_ui_00025d54->kbd_target = 1;
    PTR_g_ui_00025d54->kbd_cursor = 0;
    pabVar4 = PTR_g_ui_00025d54->msg_text;
    for (iVar5 = 0x32; puVar2 = PTR_g_ui_00025d54, iVar5 != 0; iVar5 = iVar5 + -1) {
      (*pabVar4)[0] = 0x20;
      pabVar4 = (byte (*) [50])(*pabVar4 + 1);
    }
    bVar1 = PTR_g_ui_00025d54->memlist_ch;
    *(undefined4 *)(PTR_g_ui_00025d54->msg_text[0] + 8) = *(undefined4 *)(memch[bVar1].tag + 8);
    *(undefined4 *)(puVar2->msg_text[0] + 4) = *(undefined4 *)(memch[bVar1].tag + 4);
    *(undefined4 *)puVar2->msg_text[0] = *(undefined4 *)memch[bVar1].tag;
    beep_request(1);
    return;
  }
  ui_key_reject();
  return;
}


// ===== ui_key_reject @ fffc21c7 (33 bytes)

/* UI +0x43C = 0, +0x409 = 1 (key consumed), beep_request(3) (error beep) [fact] */

void ui_key_reject(void)

{
  PTR_g_ui_00025d54->memlist_edit_on = 0;
  PTR_g_ui_00025d54->key_consumed = 1;
  beep_request(3);
  return;
}


// ===== FUN_fffc21e8 @ fffc21e8 (102 bytes)

void FUN_fffc21e8(void)

{
  bool bVar1;
  byte *pbStack_4;
  
  if ((PTR_g_ui_00025d54->memlist_ch < 0x75) &&
     (bVar1 = memch_valid(PTR_g_ui_00025d54->memlist_ch,&pbStack_4), bVar1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    ui_key_reject();
    return;
  }
  PTR_g_ui_00025d54->memlist_popup55 = 1;
  PTR_g_ui_00025d54->popup_code = 0x55;
  popup_duration_get(0x55);
  popup_open_timed();
  beep_request(1);
  return;
}


// ===== FUN_fffc224e @ fffc224e (72 bytes)

void FUN_fffc224e(void)

{
  bool bVar1;
  byte *pbStack_4;
  
  bVar1 = memch_valid(PTR_g_ui_00025d54->memlist_ch,&pbStack_4);
  if (bVar1) {
    PTR_g_ui_00025d54->memlist_popup55 = 1;
    PTR_g_ui_00025d54->popup_code = 0x44;
    popup_duration_get(0x44);
    popup_open_timed();
    beep_request(1);
    return;
  }
  ui_key_reject();
  return;
}


// ===== FUN_fffc2296 @ fffc2296 (72 bytes)

void FUN_fffc2296(void)

{
  bool bVar1;
  byte *pbStack_4;
  
  bVar1 = memch_valid(PTR_g_ui_00025d54->memlist_ch,&pbStack_4);
  if (bVar1) {
    PTR_g_ui_00025d54->memlist_popup55 = 1;
    PTR_g_ui_00025d54->popup_code = 0x45;
    popup_duration_get(0x45);
    popup_open_timed();
    beep_request(1);
    return;
  }
  ui_key_reject();
  return;
}


// ===== FUN_fffc22de @ fffc22de (120 bytes)

void FUN_fffc22de(void)

{
  bool bVar1;
  byte *local_4;
  
  if ((PTR_g_ui_00025d54->memlist_ch < 0x75) && (PTR_g_ui_00025d54->memlist_ch != 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    *local_4 = (byte)(1 << (PTR_g_ui_00025d54->memlist_ch & 7)) | *local_4;
    bVar1 = memch_valid(PTR_g_ui_00025d54->memlist_ch,&local_4);
    if (bVar1) {
      *local_4 = 0;
    }
    else {
      *local_4 = 1;
    }
    beep_request(1);
    return;
  }
  ui_key_reject();
  return;
}


// ===== menu_group_key @ fffc2356 (27 bytes)

/* (n): menu_select_group(n), beep on success [fact]; menu tab soft keys [inference] */

void menu_group_key(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = menu_select_group(param_1);
  if (cVar1 != '\x01') {
    return;
  }
  beep_request(1);
  return;
}


// ===== menu_row_key @ fffc2371 (27 bytes)

/* (n): menu_select_row(n), beep on success [fact]; menu row soft keys [inference] */

void menu_row_key(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = menu_select_row(param_1);
  if (cVar1 != '\x01') {
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffc238c @ fffc238c (24 bytes)

void FUN_fffc238c(byte param_1)

{
  PTR_g_ui_00025d54->menu_state = param_1;
  beep_request(1);
  return;
}


// ===== FUN_fffc23a4 @ fffc23a4 (18 bytes)

void FUN_fffc23a4(void)

{
  PTR_g_ui_00025d54->key_consumed = 1;
  menu_screen_close();
  return;
}


// ===== popup8_close @ fffc23b6 (77 bytes)

/* Closes pop-up 8 if it is shown, clears UI +0x40D and +0x414 [fact] */

void popup8_close(void)

{
  bool bVar1;
  
  if ((PTR_g_ui_00025d54->dl_req_popup_b == 1) && (PTR_g_ui_00025d54->popup_code == 8)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    popup_close();
  }
  PTR_g_ui_00025d54->keypad_open = 0;
  PTR_g_ui_00025d54->keypad_set_fix = 0;
  return;
}


// ===== FUN_fffc2403 @ fffc2403 (35 bytes)

void FUN_fffc2403(void)

{
  if (PTR_g_ui_00025d54->cw_spot_on != 1) {
    return;
  }
  PTR_g_ui_00025d54->cw_spot_on = 0;
  beep_stop();
  return;
}


// ===== FUN_fffc2426 @ fffc2426 (486 bytes)

undefined1 FUN_fffc2426(void)

{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  ushort uVar4;
  byte local_4;
  
  bVar1 = g_opstate.active_vfo != VFO_A;
  if (PTR_g_ui_00025d54->memlist_open == 1) {
    memch_current_set(bVar1,PTR_g_ui_00025d54->memlist_ch);
    local_4 = PTR_g_ui_00025d54->memlist_ch;
    if (g_opstate.split_on == 1) {
      g_opstate.split_on = 0;
      g_opstate.vfo_state_a = VFO_STATE_VFO;
      g_opstate.vfo_state_b = VFO_STATE_VFO;
      PTR_g_ui_00025d54->txw_on = 0;
      g_ui.txw_swap = 0;
      PTR_g_ui_00025d54->edited_a = 1;
      PTR_g_ui_00025d54->edited_b = 1;
      PTR_g_ui_00025d54->freq_refresh_req = 1;
    }
  }
  else {
    if (g_opstate.split_on == 1) {
      g_opstate.split_on = 0;
      g_opstate.vfo_state_a = PTR_g_ui_00025d54->split_saved_state_a;
      g_opstate.vfo_state_b = PTR_g_ui_00025d54->split_saved_state_b;
      PTR_g_ui_00025d54->txw_on = 0;
      g_ui.txw_swap = 0;
      PTR_g_ui_00025d54->edited_a = 1;
      PTR_g_ui_00025d54->edited_b = 1;
      PTR_g_ui_00025d54->freq_refresh_req = 1;
      return 1;
    }
    if (bVar1) {
      if (g_opstate.vfo_state_b == VFO_STATE_QMB) {
        g_opstate.vfo_state_b = VFO_STATE_VFO;
        vfo_reload(1);
        return 1;
      }
    }
    else if (g_opstate.vfo_state_a == VFO_STATE_QMB) {
      g_opstate.vfo_state_a = VFO_STATE_VFO;
      vfo_reload(0);
      return 1;
    }
    if (bVar1) {
      local_4 = g_mem_hdr.chan_b;
    }
    else {
      local_4 = g_mem_hdr.chan_a;
    }
  }
  uVar4 = dest_code_get();
  if (uVar4 == 0x315b) {
    if ((local_4 < 0x75) || (0x83 < local_4)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      return 0;
    }
  }
  uVar3 = FUN_fffc260c(bVar1);
  return uVar3;
}


// ===== FUN_fffc260c @ fffc260c (117 bytes)

undefined1 FUN_fffc260c(byte param_1)

{
  byte bVar1;
  undefined1 uStack_3;
  
  bVar1 = memch_current_valid(param_1);
  if (bVar1 == 0) {
    uStack_3 = 0;
  }
  else {
    if (g_opstate.vfo_state_a == VFO_STATE_QMB) {
      g_opstate.vfo_state_a = VFO_STATE_VFO;
    }
    if (g_opstate.vfo_state_b == VFO_STATE_QMB) {
      g_opstate.vfo_state_b = VFO_STATE_VFO;
    }
    qmb_set_depth(param_1);
    memch_load_to_vfo(param_1);
    vfo_clear_tag(param_1);
    vfo_enter_vfo_state(param_1);
    FUN_fffc18bf();
    memlist_close();
    PTR_g_ui_00025d54->vfo_refresh_req = 1;
    uStack_3 = 1;
  }
  return uStack_3;
}


// ===== memch_load_to_vfo @ fffc2681 (189 bytes)

/* 0x6150+ch*0x5A -> operating record, clar cleared */

void memch_load_to_vfo(char param_1)

{
  byte bVar1;
  vfo_rec *pvVar2;
  vfo_rec *pvVar3;
  int iVar4;
  
  bVar1 = memch_current_valid(param_1);
  if (bVar1 == 0) {
    return;
  }
  bVar1 = memch_current(param_1);
  if (param_1 == '\0') {
    pvVar3 = memch + bVar1;
    pvVar2 = &g_opstate.vfo_a;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      pvVar2->mode = pvVar3->mode;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
      pvVar3 = (vfo_rec *)&pvVar3->flags1;
    }
  }
  else {
    pvVar3 = memch + bVar1;
    pvVar2 = &g_opstate.vfo_b;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      pvVar2->mode = pvVar3->mode;
      pvVar2 = (vfo_rec *)&pvVar2->flags1;
      pvVar3 = (vfo_rec *)&pvVar3->flags1;
    }
  }
  if (param_1 == '\0') {
    PTR_g_ui_00025d54->clar_flags_a = 0;
    g_opstate.vfo_a.flags1 = g_opstate.vfo_a.flags1 & 0xe7;
    g_opstate.vfo_a.clar_offset_be[0] = 0;
    g_opstate.vfo_a.clar_offset_be[1] = 0;
    return;
  }
  PTR_g_ui_00025d54->clar_flags_b = 0;
  g_opstate.vfo_b.flags1 = g_opstate.vfo_b.flags1 & 0xe7;
  g_opstate.vfo_b.clar_offset_be[0] = 0;
  g_opstate.vfo_b.clar_offset_be[1] = 0;
  return;
}


// ===== vfo_clear_tag @ fffc273e (86 bytes)

/* Blank tag (+0x4E) and tag flag (+5 bit7) of the operating record */

void vfo_clear_tag(byte param_1)

{
  if (param_1 != 0) {
    g_opstate.vfo_b.flags5 = g_opstate.vfo_b.flags5 & 0x7f;
    builtin_strncpy(g_opstate.vfo_b.tag + 8,"    ",4);
    builtin_strncpy(g_opstate.vfo_b.tag + 4,"    ",4);
    builtin_strncpy(g_opstate.vfo_b.tag,"    ",4);
    return;
  }
  g_opstate.vfo_a.flags5 = g_opstate.vfo_a.flags5 & 0x7f;
  builtin_strncpy(g_opstate.vfo_a.tag + 8,"    ",4);
  builtin_strncpy(g_opstate.vfo_a.tag + 4,"    ",4);
  builtin_strncpy(g_opstate.vfo_a.tag,"    ",4);
  return;
}


// ===== memlist_close @ fffc2794 (25 bytes)

/* UI +0x97 = 0 (MEMORY CH LIST, frame 0x41) and +0x90 = 0 [fact] */

void memlist_close(void)

{
  PTR_g_ui_00025d54->memlist_open = 0;
  PTR_g_ui_00025d54->kbd_open = 0;
  return;
}


// ===== vm_toggle_core @ fffc27ad (318 bytes)

/* VFO <-> memory state change and reload */

void vm_toggle_core(void)

{
  bool bVar1;
  vfo_state vStack_2;
  byte bStack_1;
  
  popup_close();
  menu_close_if_open();
  func_panel_close();
  popup8_close();
  ui_clear_415_423();
  if (g_opstate.active_vfo == VFO_A) {
    bStack_1 = 0;
    vStack_2 = g_opstate.vfo_state_a;
    if (g_opstate.vfo_state_a != VFO_STATE_QMB) {
      vfo_store_back(0);
    }
  }
  else {
    bStack_1 = 1;
    vStack_2 = g_opstate.vfo_state_b;
    if (g_opstate.vfo_state_b != VFO_STATE_QMB) {
      vfo_store_back(1);
    }
  }
  if ((vStack_2 == VFO_STATE_PMS) || (vStack_2 == VFO_STATE_MEMTUNE)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc28eb(bStack_1);
  }
  else if (vStack_2 == VFO_STATE_MEMORY) {
    FUN_fffc296f(bStack_1);
    if (bStack_1 == 0) {
      PTR_g_ui_00025d54->clar_flags_a = 0;
      g_opstate.vfo_a.flags1 = g_opstate.vfo_a.flags1 & 0xe7;
    }
    else {
      PTR_g_ui_00025d54->clar_flags_b = 0;
      g_opstate.vfo_b.flags1 = g_opstate.vfo_b.flags1 & 0xe7;
    }
  }
  else {
    if (g_opstate.split_on == 1) {
      g_opstate.split_on = 0;
      g_opstate.vfo_state_a = PTR_g_ui_00025d54->split_saved_state_a;
      g_opstate.vfo_state_b = PTR_g_ui_00025d54->split_saved_state_b;
      PTR_g_ui_00025d54->txw_on = 0;
      g_ui.txw_swap = 0;
      return;
    }
    FUN_fffc2991(bStack_1);
  }
  vfo_reload(bStack_1);
  PTR_g_ui_00025d54->vfo_refresh_req = 1;
  return;
}


// ===== FUN_fffc28eb @ fffc28eb (16 bytes)

void FUN_fffc28eb(byte param_1)

{
  vfo_enter_mem_state(param_1);
  memtune_flags_clear(param_1);
  return;
}


// ===== vfo_enter_mem_state @ fffc28fb (60 bytes)

/* state = 2 */

void vfo_enter_mem_state(byte param_1)

{
  if (param_1 != 0) {
    g_opstate.vfo_state_b = VFO_STATE_MEMORY;
    PTR_g_ui_00025d54->force_bandstack_b = 0;
    return;
  }
  g_opstate.vfo_state_a = VFO_STATE_MEMORY;
  PTR_g_ui_00025d54->force_bandstack_a = 0;
  return;
}


// ===== memtune_flags_clear @ fffc2937 (56 bytes)

/* (side): UI +0x43F/+0x441 (A) or +0x440/+0x442 (B) = 0 */

void memtune_flags_clear(int param_1)

{
  if (param_1 != 0) {
    PTR_g_ui_00025d54->memtune_valid_b = 0;
    PTR_g_ui_00025d54->memtune_backup_b = 0;
    return;
  }
  PTR_g_ui_00025d54->memtune_valid_a = 0;
  PTR_g_ui_00025d54->memtune_backup_a = 0;
  return;
}


// ===== FUN_fffc296f @ fffc296f (34 bytes)

void FUN_fffc296f(int param_1)

{
  if (param_1 != 0) {
    g_opstate.vfo_state_b = VFO_STATE_VFO;
    return;
  }
  g_opstate.vfo_state_a = VFO_STATE_VFO;
  return;
}


// ===== FUN_fffc2991 @ fffc2991 (98 bytes)

void FUN_fffc2991(uint param_1)

{
  if (param_1 == 0) {
    if (g_opstate.vfo_state_a != VFO_STATE_QMB) {
      memtune_flags_clear(0);
      g_opstate.vfo_state_a = VFO_STATE_MEMORY;
      return;
    }
    g_opstate.vfo_state_a = VFO_STATE_VFO;
    return;
  }
  if (g_opstate.vfo_state_b != VFO_STATE_QMB) {
    memtune_flags_clear(param_1 & 0xff);
    g_opstate.vfo_state_b = VFO_STATE_MEMORY;
    return;
  }
  g_opstate.vfo_state_b = VFO_STATE_VFO;
  return;
}

