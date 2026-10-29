// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== key_nop @ fffc4a8d (1 bytes)

/* empty key handler (RTS) */

void key_nop(void)

{
  return;
}


// ===== FUN_fffc4a8e @ fffc4a8e (103 bytes)

void FUN_fffc4a8e(void)

{
  PTR_g_ui_00025d54->f_0x443_u8 = 1;
  PTR_g_ui_00025d54->f_0x445_u8 = 1;
  if (g_opstate.vfo_state_a == 5) {
    g_opstate.vfo_state_a = 1;
  }
  if (g_opstate.vfo_state_b == 5) {
    g_opstate.vfo_state_b = 1;
  }
  FUN_fffc4af5();
  vfo_reload(0);
  vfo_reload(1);
  PTR_g_ui_00025d54->vfo_refresh_req = 1;
  return;
}


// ===== FUN_fffc4af5 @ fffc4af5 (72 bytes)

void FUN_fffc4af5(void)

{
  bool bVar1;
  byte local_1;
  
  local_1 = g_qmb_hdr.count;
  if ((g_opstate.ex030112_qmb_ch == 0) && (4 < g_qmb_hdr.count)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_1 = 5;
  }
  g_qmb_hdr.ptr_a[0] = local_1;
  g_qmb_hdr.ptr_b[0] = local_1;
  return;
}


// ===== vfo_filter_byte_ptr @ fffc4b3d (152 bytes)

/* Returns VFO-A/B record (0x9D09/0x9D63) + the per-mode filter byte offset
   (+0x0B/+0x15/+0x1F/+0x29/+0x33/+0x3D by mode nibble) [fact: disassembly]; the decompile shows
   void (#205) */

void vfo_filter_byte_ptr(void)

{
  return;
}


// ===== FUN_fffc4bd5 @ fffc4bd5 (121 bytes)

void FUN_fffc4bd5(radio_mode mode)

{
  switch(mode) {
  case MODE_LSB:
    FUN_fffc0d33(MODE_LSB);
    return;
  case MODE_USB:
    FUN_fffc0d33(MODE_USB);
    return;
  case MODE_CW_L:
    FUN_fffc0d33(MODE_CW_L);
    return;
  case MODE_CW_U:
    FUN_fffc0d33(MODE_CW_U);
    return;
  case MODE_AM:
    FUN_fffc0e31();
    return;
  case MODE_AM_N:
    FUN_fffc0e3e();
    return;
  case MODE_FM:
    FUN_fffc0e4b();
    return;
  case MODE_FM_N:
    FUN_fffc0e58();
    return;
  case MODE_DATA_L:
    FUN_fffc0d33(MODE_DATA_L);
    return;
  case MODE_DATA_U:
    FUN_fffc0d33(MODE_DATA_U);
    return;
  case MODE_DATA_FM:
    FUN_fffc0e65();
    return;
  case MODE_DATA_FM_N:
    FUN_fffc0e72();
    return;
  case MODE_RTTY_L:
    FUN_fffc0d33(MODE_RTTY_L);
    return;
  case MODE_RTTY_U:
    FUN_fffc0d33(MODE_RTTY_U);
    return;
  case MODE_PSK:
    FUN_fffc0d33(MODE_PSK);
    return;
  case MODE_15:
    FUN_fffc0e7f();
    return;
  default:
    return;
  }
}


// ===== band_select_on @ fffc4c4e (61 bytes)

/* (band, side): band_select with 0x9DBD temporarily = side (CAT BS/BU/BD) */

void band_select_on(band_idx param_1,vfo_side param_2)

{
  byte bVar1;
  
  bVar1 = g_opstate.active_vfo;
  g_opstate.active_vfo = param_2;
  band_select(param_1);
  g_opstate.split_on = 0;
  g_opstate.active_vfo = bVar1;
  tuner_rearm();
  return;
}


// ===== FUN_fffc4c8b @ fffc4c8b (11 bytes)

void FUN_fffc4c8b(undefined1 param_1)

{
  FUN_fffc1f2a(param_1);
  return;
}


// ===== FUN_fffc4c96 @ fffc4c96 (20 bytes)

void FUN_fffc4c96(void)

{
  swtimer_start(0x40,200);
  DAT_0001b4dc = 1;
  return;
}


// ===== ui_clear_415_423 @ fffc4caa (27 bytes)

/* UI +0x415 = 0 (dial x4, ui-keys.md) and +0x423 = 0 [fact]; purpose of +0x423 [unknown] */

void ui_clear_415_423(void)

{
  PTR_g_ui_00025d54->f_0x415_u8 = 0;
  PTR_g_ui_00025d54->f_0x423_u8 = 0;
  return;
}


// ===== FUN_fffc4cc5 @ fffc4cc5 (206 bytes)

undefined1 FUN_fffc4cc5(short param_1,uint param_2)

{
  ui_state *puVar1;
  undefined1 local_d;
  char *pcStack_c;
  byte bStack_8;
  byte bStack_6;
  
  local_d = 0;
  if (PTR_g_ui_00025d54->numentry_mode == 1) {
    if (((byte)param_2 & 0xf) == 1) {
      popup_close();
      PTR_g_ui_00025d54->popup_code = 0x5e;
      puVar1 = PTR_g_ui_00025d54;
      bStack_8 = 0xff;
      if ((char)(param_2 >> 4) != '\x04') {
        for (bStack_6 = 0; bStack_6 < 0x1c; bStack_6 = bStack_6 + 1) {
          if (*(short *)(BYTE_ARRAY_fff88270 + (uint)bStack_6 * 0xc + 0x154) == param_1) {
            bStack_8 = bStack_6;
            break;
          }
        }
      }
      if (bStack_8 == 0xff) {
        pcStack_c = "  DISPLAY";
      }
      else {
        pcStack_c = " LOCK/PWR" + (uint)bStack_8 * 0xc;
      }
      PTR_g_ui_00025d54->popup_text[8] = pcStack_c[8];
      *(undefined4 *)(puVar1->popup_text + 4) = *(undefined4 *)(pcStack_c + 4);
      *(undefined4 *)puVar1->popup_text = *(undefined4 *)pcStack_c;
      popup_duration_get(0x5e);
      popup_open_timed();
      beep_request(1);
    }
    local_d = 1;
  }
  return local_d;
}


// ===== FUN_fffc4d93 @ fffc4d93 (89 bytes)

void FUN_fffc4d93(void)

{
  int iVar1;
  preset *ppVar2;
  preset *ppVar3;
  byte local_2;
  
  local_2 = g_opstate.preset_sel;
  if (4 < g_opstate.preset_sel) {
    local_2 = 4;
  }
  ppVar3 = g_opstate.presets + local_2;
  iVar1 = strncmp(0x20b4c,ppVar3,0x1f);
  if (iVar1 != 0) {
    ppVar2 = &g_ui.preset_active;
    for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
      ppVar2->name[0] = ppVar3->name[0];
      ppVar2 = (preset *)(ppVar2->name + 1);
      ppVar3 = (preset *)(ppVar3->name + 1);
    }
    sci3_set_baud();
    return;
  }
  return;
}


// ===== FUN_fffc4dec @ fffc4dec (99 bytes)

void FUN_fffc4dec(void)

{
  bool bVar1;
  byte bVar2;
  
  bVar1 = g_opstate.active_vfo != 0;
  bVar2 = PTR_g_ui_00025d54->dsp_knob_func;
  if (bVar2 == 3) {
    if (PTR_g_ui_00025d54->f_0x47a_u8 != 0) {
      FUN_fffc388d();
      return;
    }
    FUN_fffc3773(bVar1);
    return;
  }
  if (bVar2 == 1) {
    FUN_fffc3582(bVar1);
    return;
  }
  if (bVar2 == 2) {
    FUN_fffc3659(bVar1);
    return;
  }
  if (bVar2 != 0) {
    return;
  }
  FUN_fffc3503(bVar1);
  return;
}


// ===== vfo_filter_width_hz @ fffc4e4f (320 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc4f7a) */
/* Selected filter width in Hz of the active side's mode (docs/code/main/sdr-link.md) [inference] */

ushort vfo_filter_width_hz(void *param_1)

{
  uint uVar1;
  bool bVar2;
  int local_10;
  ushort local_c;
  byte local_9;
  byte local_8;
  byte local_7;
  
  bVar2 = false;
  if (g_opstate.active_vfo == 0) {
    local_8 = g_opstate.vfo_a.nar_flags;
    local_10 = 0x9d09;
    local_7 = g_opstate.vfo_a.mode;
  }
  else {
    local_8 = g_opstate.vfo_b.nar_flags;
    local_10 = 0x9d63;
    local_7 = g_opstate.vfo_b.mode;
  }
  local_7 = local_7 & 0xf;
  uVar1 = (uint)local_7;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      if ((local_8 & 0x20) == 0) {
        *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x1a);
      }
      else {
        local_9 = g_opstate.ex020114_nar_width;
        bVar2 = true;
      }
      goto LAB_fffc4f4c;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        if ((local_8 & 8) == 0) {
          *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x24);
        }
        else {
          local_9 = g_opstate.ex010514_nar_width;
          bVar2 = true;
        }
      }
      else {
        if (1 < uVar1) {
          return 0;
        }
        if ((local_8 & 0x80) == 0) {
          *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x10);
        }
        else {
          local_9 = g_opstate.ex010118_nar_width;
          bVar2 = true;
        }
      }
      goto LAB_fffc4f4c;
    }
  }
  if ((local_8 & 4) == 0) {
    *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x2e);
  }
  else {
    local_9 = g_opstate.ex010418_nar_width;
    bVar2 = true;
  }
LAB_fffc4f4c:
  if (bVar2) {
    local_c = FUN_fffb3775(local_7,local_9);
    if (param_1 != (void *)0x0) {
      *(char *)param_1 = (char)(local_c >> 8);
      *(char *)((int)param_1 + 1) = (char)local_c;
    }
  }
  else {
    local_c = CONCAT11(*(undefined1 *)param_1,*(undefined1 *)((int)param_1 + 1));
  }
  return local_c;
}


// ===== FUN_fffc4f8f @ fffc4f8f (15 bytes)

undefined1 FUN_fffc4f8f(void)

{
  return DAT_0001b4df;
}


// ===== FUN_fffc4f9e @ fffc4f9e (48 bytes)

void FUN_fffc4f9e(char param_1)

{
  if (param_1 != '\0') {
    DAT_0001b4df = 1;
    return;
  }
  DAT_0001b4e0 = g_opstate.ss00_value;
  DAT_0001b4df = 0;
  return;
}


// ===== qmb_current_slot @ fffc4fce (157 bytes)

/* (*slot): in QMB state (5) the QMB slot record 0x9023 + 0x5A*n for the current recall depth
   (0x9020 / 0x9022), else 0 [fact] */

uint qmb_current_slot(void *param_1)

{
  vfo_rec *local_14;
  byte local_a;
  byte local_9;
  
  if (g_opstate.active_vfo == 0) {
    local_9 = g_opstate.vfo_state_a;
    local_a = g_qmb_hdr.ptr_a[1];
  }
  else {
    local_9 = g_opstate.vfo_state_b;
    local_a = g_qmb_hdr.ptr_b[1];
  }
  if (local_a == 0) {
    if (g_opstate.ex030112_qmb_ch == 0) {
      local_a = 4;
    }
    else {
      local_a = 9;
    }
  }
  else {
    local_a = local_a - 1;
  }
  if (local_9 == 5) {
    local_14 = qmb + g_qmb_hdr.order[local_a];
    *(byte *)param_1 = g_qmb_hdr.order[local_a];
  }
  else {
    local_14 = (vfo_rec *)0x0;
  }
  return (uint)local_14;
}


// ===== FUN_fffc506b @ fffc506b (53 bytes)

void FUN_fffc506b(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = qmb_current_slot(&bStack_2);
  if (uVar1 == 0) {
    return;
  }
  local_1 = local_1 & 3;
  *(byte *)(uVar1 + 3) = *(byte *)(uVar1 + 3) & 0xfc;
  *(byte *)(uVar1 + 3) = *(byte *)(uVar1 + 3) | local_1;
  eeprom_save_qmb_slot(bStack_2);
  return;
}


// ===== FUN_fffc50a0 @ fffc50a0 (53 bytes)

void FUN_fffc50a0(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = qmb_current_slot(&bStack_2);
  if (uVar1 == 0) {
    return;
  }
  local_1 = local_1 & 3;
  *(byte *)(uVar1 + 5) = *(byte *)(uVar1 + 5) & 0xfc;
  *(byte *)(uVar1 + 5) = *(byte *)(uVar1 + 5) | local_1;
  eeprom_save_qmb_slot(bStack_2);
  return;
}


// ===== FUN_fffc50d5 @ fffc50d5 (41 bytes)

void FUN_fffc50d5(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = qmb_current_slot(&bStack_2);
  if ((uVar1 != 0) && (local_1 < 2)) {
    FUN_fffc0948(uVar1,local_1);
    eeprom_save_qmb_slot(bStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc50fe @ fffc50fe (41 bytes)

void FUN_fffc50fe(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = qmb_current_slot(&bStack_2);
  if ((uVar1 != 0) && (local_1 < 5)) {
    FUN_fffc0a49(uVar1,local_1);
    eeprom_save_qmb_slot(bStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc5127 @ fffc5127 (54 bytes)

void FUN_fffc5127(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = qmb_current_slot(&bStack_2);
  if ((uVar1 != 0) && (local_1 < 2)) {
    if (local_1 == 0) {
      *(byte *)(uVar1 + 6) = *(byte *)(uVar1 + 6) & 0xef;
    }
    else {
      *(byte *)(uVar1 + 6) = *(byte *)(uVar1 + 6) | 0x10;
    }
    eeprom_save_qmb_slot(bStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc515d @ fffc515d (64 bytes)

void FUN_fffc515d(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = qmb_current_slot(&bStack_2);
  if (uVar1 != 0) {
    if (0xf < local_1) {
      local_1 = 0xf;
    }
    if (local_1 == 0) {
      local_1 = 1;
    }
    *(byte *)(uVar1 + 6) = *(byte *)(uVar1 + 6) & 0xf0;
    *(byte *)(uVar1 + 6) = *(byte *)(uVar1 + 6) | local_1;
    eeprom_save_qmb_slot(bStack_2);
    return;
  }
  return;
}


// ===== key_dest_allowed @ fffc519d (157 bytes)

/* (code, flag): on destinations 0x315B/0x50E2 with UI +0x9A set, refuses every key when flag != 0,
   else the front-panel keys 0x300..0x30E and 0x310..0x312; true elsewhere [fact]; the gate before
   each key handler call (ui-keys.md) [fact] */

bool key_dest_allowed(ushort param_1,char param_2)

{
  bool bVar1;
  ushort uVar2;
  bool bStack_7;
  
  uVar2 = dest_code_get();
  if ((uVar2 == 0x315b) || (uVar2 == 0x50e2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return true;
  }
  if (PTR_g_ui_00025d54->dl_block_34 == 0) {
    return true;
  }
  if (param_2 != '\0') {
    return false;
  }
  if ((param_1 < 0x300) || (0x30e < param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if ((param_1 < 0x310) || (0x312 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      bStack_7 = false;
      goto LAB_fffc521d;
    }
  }
  bStack_7 = true;
LAB_fffc521d:
  bStack_7 = !bStack_7;
  return bStack_7;
}


// ===== FUN_fffc523a @ fffc523a (86 bytes)

undefined1 FUN_fffc523a(char param_1,char param_2,undefined1 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 local_5;
  
  uVar1 = DAT_0001b4e3;
  uVar2 = DAT_0001b4e4;
  local_5 = param_3;
  if (param_1 == '\0') {
    uVar1 = param_3;
    if (param_2 != '\0') {
      local_5 = DAT_0001b4e3;
      uVar1 = DAT_0001b4e3;
    }
  }
  else {
    uVar2 = param_3;
    if (param_2 != '\0') {
      local_5 = DAT_0001b4e4;
      uVar2 = DAT_0001b4e4;
    }
  }
  DAT_0001b4e4 = uVar2;
  DAT_0001b4e3 = uVar1;
  return local_5;
}


// ===== vfo_mark_edited_if_vfo @ fffc5290 (71 bytes)

/* Sets UI +0x443 (A) / +0x445 (B) only when the active side is in VFO state 1 [fact] */

void vfo_mark_edited_if_vfo(void)

{
  if (g_opstate.active_vfo == 0) {
    if (g_opstate.vfo_state_a == 1) {
      PTR_g_ui_00025d54->f_0x443_u8 = 1;
      return;
    }
  }
  else if (g_opstate.vfo_state_b == 1) {
    PTR_g_ui_00025d54->f_0x445_u8 = 1;
    return;
  }
  return;
}


// ===== enc_main_dial @ fffc52d7 (180 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc531a) */
/* main dial steps (encoder id 1/6) -> tuning */

void enc_main_dial(byte param_1)

{
  int iVar1;
  byte local_6;
  ushort local_4;
  byte local_1;
  
  if ((g_ui.dialog_shown == 1) || (PTR_g_ui_00025d58->dl_req_40 == 1)) {
    return;
  }
  local_1 = param_1;
  if (PTR_g_ui_00025d58->f_0x0a1_u8 == 6) {
    if (PTR_g_ui_00025d58->f_0x415_u8 != 1) {
      return;
    }
    local_1 = param_1 << 2;
  }
  if ((char)local_1 < '\0') {
    PTR_g_ui_00025d58->ch_knob_mode = 1;
    local_6 = ~local_1 + 1;
  }
  else {
    PTR_g_ui_00025d58->ch_knob_mode = 0;
    local_6 = local_1;
  }
  DAT_0001ff6a = DAT_0001ff6a + (short)(char)local_1;
  local_4 = DAT_0001ff6a;
  if ((short)DAT_0001ff6a < 0) {
    local_4 = ~DAT_0001ff6a + 1;
  }
  iVar1 = FUN_fffc538b();
  if (iVar1 == 1) {
    FUN_fffc53dc(local_6,(int)(short)local_4);
    return;
  }
  FUN_fffc5a84(local_6,(int)(short)local_4);
  return;
}


// ===== FUN_fffc538b @ fffc538b (81 bytes)

undefined1 FUN_fffc538b(void)

{
  undefined1 local_2;
  
  if (g_opstate.split_on == 1) {
    local_2 = 1;
  }
  else if (g_opstate.active_vfo == 0) {
    if (PTR_g_ui_00025d58->clar_flags_a == 0) {
      local_2 = 0;
    }
    else {
      local_2 = 1;
    }
  }
  else if (PTR_g_ui_00025d58->clar_flags_b == 0) {
    local_2 = 0;
  }
  else {
    local_2 = 1;
  }
  return local_2;
}


// ===== FUN_fffc53dc @ fffc53dc (240 bytes)

void FUN_fffc53dc(byte param_1,ushort param_2)

{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  bool local_5;
  byte local_1;
  
  bVar1 = g_opstate.active_vfo == 0;
  local_5 = !bVar1;
  if (g_opstate.ex030506_main_steps_per_rev == 0) {
    if ((param_2 & 0xfffc) == 0) {
      return;
    }
    uVar5 = (uint)(int)(short)(param_2 & 0xfffc) >> 2;
    uVar2 = uVar5 & 3;
    local_1 = (byte)uVar5 & 3;
  }
  else {
    local_1 = param_1;
    if (g_opstate.ex030506_main_steps_per_rev != 1) goto LAB_fffc5452;
    if ((param_2 & 0xfffe) == 0) {
      return;
    }
    uVar5 = (uint)(int)(short)(param_2 & 0xfffe) >> 1;
    uVar2 = uVar5 & 1;
    local_1 = (byte)uVar5 & 1;
  }
  if (uVar2 == 0) {
    return;
  }
LAB_fffc5452:
  ui_clear_415_423();
  if (((PTR_g_ui_00025d58->txw_swap == 1) && (bVar4 = vfo_is_memory(bVar1), bVar4 == 1)) &&
     (bVar4 = memch_current_is_special(bVar1), bVar4 == 1)) {
    return;
  }
  if (g_opstate.split_on != 1) {
    FUN_fffc5767(local_5);
    return;
  }
  bVar4 = vfo_is_memory(bVar1);
  if ((bVar4 == 1) || (iVar6 = FUN_fffc2f1d(bVar1), iVar6 == 1)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar3) {
    vfo_enter_mem_state(bVar1);
    memtune_flags_clear(bVar1);
    memch_step(local_1,bVar1);
    return;
  }
  FUN_fffc56cd(local_1);
  return;
}


// ===== memch_step @ fffc54cc (117 bytes)

/* (n, side): n channel steps up (+0x47C = 0) or down, skipping SKIP channels while scanning, then
   eeprom_save_memch [fact] (CAT CH) */

void memch_step(byte param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte local_3;
  
  local_3 = 0;
  if (PTR_g_ui_00025d58->ch_knob_mode == 0) {
    for (; local_3 < param_1; local_3 = local_3 + 1) {
      memch_step_up(param_2);
    }
  }
  else {
    for (; local_3 < param_1; local_3 = local_3 + 1) {
      memch_step_down(param_2);
    }
  }
  if ((g_ui.scan_running == 1) && (iVar3 = memch_current_skip(), iVar3 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    bVar2 = memch_current(param_2);
    eeprom_save_memch(bVar2);
    return;
  }
  return;
}


// ===== memch_step_up @ fffc5541 (150 bytes)

/* (side): memory channel +1, wrapping to the first [fact] (#157, cat-commands-primary.md CH) */

void memch_step_up(byte param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bStack_5;
  byte bStack_3;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  FUN_fff9c1a1((char *)&bStack_2,(char *)&bStack_3);
  if (bStack_2 == bStack_3) {
    return;
  }
  bVar2 = memch_current(local_1);
  while( true ) {
    bStack_5 = memch_current(local_1);
    do {
      if (bStack_5 < bStack_3) {
        bStack_5 = bStack_5 + 1;
      }
      else {
        bStack_5 = bStack_2;
      }
      if ((bStack_5 < 0x84) && (0x74 < bStack_5)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    } while ((bVar1) &&
            ((iVar4 = dest_has_5mhz_channels(), iVar4 == 0 ||
             (bVar3 = memch_dest_blocked(bStack_5), bVar3 == 1))));
    memch_current_set(local_1,bStack_5);
    if (0x74 < bStack_5) break;
    bVar3 = memch_current_valid(local_1);
    if (bVar3 == 1) {
      FUN_fffc566d(local_1,bVar2);
      return;
    }
  }
  FUN_fffc566d(local_1,bVar2);
  return;
}


// ===== memch_step_down @ fffc55d7 (150 bytes)

/* (side): memory channel -1 [fact] (#157) */

void memch_step_down(byte param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bStack_5;
  byte bStack_3;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  FUN_fff9c1a1((char *)&bStack_2,(char *)&bStack_3);
  if (bStack_2 == bStack_3) {
    return;
  }
  bVar2 = memch_current(local_1);
  while( true ) {
    bStack_5 = memch_current(local_1);
    do {
      if (bStack_2 < bStack_5) {
        bStack_5 = bStack_5 - 1;
      }
      else {
        bStack_5 = bStack_3;
      }
      if ((bStack_5 < 0x84) && (0x74 < bStack_5)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    } while ((bVar1) &&
            ((iVar4 = dest_has_5mhz_channels(), iVar4 == 0 ||
             (bVar3 = memch_dest_blocked(bStack_5), bVar3 == 1))));
    memch_current_set(local_1,bStack_5);
    if (0x74 < bStack_5) break;
    bVar3 = memch_current_valid(local_1);
    if (bVar3 == 1) {
      FUN_fffc566d(local_1,bVar2);
      return;
    }
  }
  FUN_fffc566d(local_1,bVar2);
  return;
}


// ===== FUN_fffc566d @ fffc566d (29 bytes)

void FUN_fffc566d(byte param_1,byte param_2)

{
  byte bVar1;
  
  bVar1 = memch_current(param_1);
  if (bVar1 == param_2) {
    return;
  }
  FUN_fffc568a(param_1);
  return;
}


// ===== FUN_fffc568a @ fffc568a (67 bytes)

void FUN_fffc568a(byte param_1)

{
  vfo_store_back(param_1);
  if (param_1 == 0) {
    vfo_reload(0);
    PTR_g_ui_00025d58->f_0x444_u8 = 1;
  }
  else {
    vfo_reload(param_1);
    PTR_g_ui_00025d58->f_0x444_u8 = 1;
  }
  PTR_g_ui_00025d58->vfo_refresh_req = 1;
  return;
}


// ===== FUN_fffc56cd @ fffc56cd (154 bytes)

void FUN_fffc56cd(undefined1 param_1)

{
  bool bVar1;
  char local_2;
  
  bVar1 = PTR_g_ui_00025d58->txw_swap == 0;
  if (g_opstate.active_vfo == 0) {
    if (bVar1) {
      local_2 = '\x01';
    }
    else {
      local_2 = '\0';
    }
  }
  else if (bVar1) {
    local_2 = '\0';
  }
  else {
    local_2 = '\x01';
  }
  if ((PTR_g_ui_00025d58->f_0x482_u8 == 1) && (PTR_g_ui_00025d58->txw_swap == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (local_2 == '\0') {
      local_2 = '\x01';
    }
    else {
      local_2 = '\0';
    }
  }
  if (PTR_g_ui_00025d58->f_0x03e_u8 != 0) {
    FUN_fffc5e0a(0,param_1);
    FUN_fffc5e0a(1,param_1);
    return;
  }
  FUN_fffc5e0a(local_2,param_1);
  return;
}


// ===== FUN_fffc5767 @ fffc5767 (49 bytes)

void FUN_fffc5767(vfo_side param_1)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = vfo_is_memory(param_1);
  if ((bVar2 == 1) && (bVar2 = memch_current_is_special(param_1), bVar2 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((!bVar1) && (iVar3 = FUN_fffc59de(), iVar3 != 0)) {
    FUN_fffc5798();
    return;
  }
  return;
}


// ===== FUN_fffc5798 @ fffc5798 (184 bytes)

void FUN_fffc5798(void)

{
  undefined2 uVar1;
  bool local_f;
  bool local_d;
  vfo_rec *local_c;
  vfo_rec *local_8;
  byte local_3;
  
  local_f = g_opstate.active_vfo == 0;
  if (local_f) {
    local_8 = &g_opstate.vfo_a;
    local_c = &g_opstate.vfo_b;
  }
  else {
    local_8 = &g_opstate.vfo_b;
    local_c = &g_opstate.vfo_a;
  }
  local_d = !local_f;
  if (PTR_g_ui_00025d58->transmitting == 0) {
    local_f = local_d;
    local_3 = local_8->mode & 0xf;
  }
  else if (g_opstate.split_on == 1) {
    local_3 = local_c->mode & 0xf;
  }
  else {
    local_f = local_d;
    local_3 = local_8->mode & 0xf;
  }
  uVar1 = FUN_fffc5850(local_3);
  if (PTR_g_ui_00025d58->ch_knob_mode != 0) {
    FUN_fffc5955();
    return;
  }
  FUN_fffc58e1(uVar1,local_f);
  return;
}


// ===== FUN_fffc5850 @ fffc5850 (145 bytes)

undefined2 FUN_fffc5850(byte param_1)

{
  uint uVar1;
  undefined2 local_6;
  
  uVar1 = (uint)param_1;
  if (uVar1 - 0xc < 3) {
LAB_fffc58b3:
    if (g_opstate.ex030502_rtty_psk_dial_step == 0) {
      local_6 = 5;
    }
    else if (g_opstate.ex030502_rtty_psk_dial_step == 1) {
      local_6 = 10;
    }
    else {
      local_6 = 0x14;
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      return 100;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc58b3;
      if (1 < uVar1 - 10) {
        if (3 < uVar1) {
          return 0;
        }
        if (g_opstate.ex030501_ssb_cw_dial_step != 0) {
          if (g_opstate.ex030501_ssb_cw_dial_step != 1) {
            return 0x14;
          }
          return 10;
        }
        return 5;
      }
    }
    local_6 = 100;
  }
  return local_6;
}


// ===== FUN_fffc58e1 @ fffc58e1 (116 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc590a) */

void FUN_fffc58e1(short param_1,int param_2)

{
  short sVar1;
  int local_c;
  undefined1 local_6;
  
  if (param_2 == 0) {
    local_c = 0x9d09;
  }
  else {
    local_c = 0x9d63;
  }
  sVar1 = CONCAT11(*(undefined1 *)(local_c + 0x48),*(undefined1 *)(local_c + 0x49));
  if (param_1 != 0 && (sVar1 != -0x80000000 || param_1 != -1)) {
    sVar1 = sVar1 / param_1;
  }
  param_1 = sVar1 * param_1 + param_1;
  if (0x270e < param_1) {
    return;
  }
  *(char *)(local_c + 0x48) = (char)((ushort)param_1 >> 8);
  local_6 = (undefined1)param_1;
  *(undefined1 *)(local_c + 0x49) = local_6;
  vfo_mark_edited((byte)param_2);
  PTR_g_ui_00025d58->freq_refresh_req = 1;
  return;
}


// ===== FUN_fffc5955 @ fffc5955 (137 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc597e) */

void FUN_fffc5955(short param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  int local_c;
  short local_6;
  
  if (param_2 == 0) {
    local_c = 0x9d09;
  }
  else {
    local_c = 0x9d63;
  }
  sVar3 = CONCAT11(*(undefined1 *)(local_c + 0x48),*(undefined1 *)(local_c + 0x49));
  local_6 = sVar3;
  if (param_1 != 0 && (sVar3 != -0x80000000 || param_1 != -1)) {
    local_6 = sVar3 / param_1;
  }
  local_6 = local_6 * param_1;
  iVar1 = (int)sVar3;
  iVar2 = (int)param_1;
  iVar4 = iVar1;
  if (iVar2 != 0 && (iVar1 != -0x80000000 || iVar2 != -1)) {
    iVar4 = iVar1 / iVar2;
  }
  if ((iVar1 == iVar4 * iVar2) && (local_6 = local_6 - param_1, local_6 < -9999)) {
    return;
  }
  *(char *)(local_c + 0x48) = (char)((ushort)local_6 >> 8);
  *(undefined1 *)(local_c + 0x49) = (undefined1)local_6;
  vfo_mark_edited((byte)param_2);
  PTR_g_ui_00025d58->freq_refresh_req = 1;
  return;
}


// ===== FUN_fffc59de @ fffc59de (166 bytes)

undefined1 FUN_fffc59de(void)

{
  undefined1 local_9;
  undefined2 local_8;
  undefined1 local_5;
  undefined2 local_4;
  
  if (g_opstate.ex030506_main_steps_per_rev == 0) {
    local_5 = 4;
    local_8 = 0xfff0;
  }
  else if (g_opstate.ex030506_main_steps_per_rev == 1) {
    local_5 = 3;
    local_8 = 0xfff8;
  }
  else {
    local_5 = 2;
    local_8 = 0xfffc;
  }
  local_4 = DAT_0001ff6a;
  if ((short)DAT_0001ff6a < 0) {
    local_4 = ~DAT_0001ff6a;
  }
  if ((local_4 & local_8) == 0) {
    local_9 = 0;
  }
  else if (((int)(short)(local_4 & local_8) >> local_5 & 1U) == 0) {
    local_9 = 0;
  }
  else {
    if ((short)DAT_0001ff6a < 0) {
      DAT_0001ff6a = local_8 | DAT_0001ff6a;
    }
    else {
      DAT_0001ff6a = ~local_8 & DAT_0001ff6a;
    }
    local_9 = 1;
  }
  return local_9;
}


// ===== FUN_fffc5a84 @ fffc5a84 (309 bytes)

void FUN_fffc5a84(undefined1 param_1,ushort param_2)

{
  undefined1 local_1;
  
  if (PTR_g_ui_00025d58->f_0x415_u8 == 1) {
    FUN_fffc8ebc();
    if ((param_2 & 0xfffc) != 0) {
      local_1 = (undefined1)((uint)(int)(short)(param_2 & 0xfffc) >> 2);
      if ((short)DAT_0001ff6a < 0) {
        DAT_0001ff6a = ~(~DAT_0001ff6a + 1 & 3) + 1;
      }
      else {
        DAT_0001ff6a = DAT_0001ff6a & 3;
      }
      goto LAB_fffc5bb0;
    }
  }
  else if (g_opstate.ex030506_main_steps_per_rev == 0) {
    if ((param_2 & 0xfffc) != 0) {
      local_1 = (undefined1)((uint)(int)(short)(param_2 & 0xfffc) >> 2);
      if ((short)DAT_0001ff6a < 0) {
        DAT_0001ff6a = ~(~DAT_0001ff6a + 1 & 3) + 1;
      }
      else {
        DAT_0001ff6a = DAT_0001ff6a & 3;
      }
      goto LAB_fffc5bb0;
    }
  }
  else if (g_opstate.ex030506_main_steps_per_rev == 1) {
    if ((param_2 & 0xfffe) != 0) {
      local_1 = (undefined1)((uint)(int)(short)(param_2 & 0xfffe) >> 1);
      if ((short)DAT_0001ff6a < 0) {
        DAT_0001ff6a = ~(~DAT_0001ff6a + 1 & 1) + 1;
      }
      else {
        DAT_0001ff6a = DAT_0001ff6a & 1;
      }
      goto LAB_fffc5bb0;
    }
  }
  else if (param_2 != 0) {
    DAT_0001ff6a = 0;
    local_1 = param_1;
LAB_fffc5bb0:
    FUN_fffc5bb9(local_1);
    return;
  }
  return;
}


// ===== FUN_fffc5bb9 @ fffc5bb9 (214 bytes)

void FUN_fffc5bb9(undefined1 param_1)

{
  bool bVar1;
  byte bVar2;
  byte local_3;
  bool local_2;
  
  local_2 = g_opstate.active_vfo != 0;
  if (PTR_g_ui_00025d58->scan_running == 1) {
    FUN_fffe5d2a();
    return;
  }
  if (PTR_g_ui_00025d58->f_0x46b_u8 != 1) {
    if ((PTR_g_ui_00025d58->transmitting == 1) && (g_opstate.split_on == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if (PTR_g_ui_00025d58->txw_swap == 1) {
        if (local_2) {
          local_2 = false;
        }
        else {
          local_2 = true;
        }
      }
      if (local_2 == false) {
        local_3 = g_opstate.vfo_state_a;
      }
      else {
        local_3 = g_opstate.vfo_state_b;
      }
      if (local_3 == 2) {
        bVar2 = memch_current_is_special(local_2);
        if (bVar2 == 1) {
          return;
        }
        vfo_mem_to_memtune(local_2);
        PTR_g_ui_00025d58->vfo_refresh_req = 1;
      }
      FUN_fffc5e0a(local_2,param_1);
      return;
    }
    FUN_fffc5c8f(local_2,param_1);
    return;
  }
  return;
}


// ===== FUN_fffc5c8f @ fffc5c8f (81 bytes)

void FUN_fffc5c8f(byte param_1,undefined1 param_2)

{
  byte bVar1;
  byte local_3;
  
  if (param_1 == 0) {
    local_3 = g_opstate.vfo_state_a;
  }
  else {
    local_3 = g_opstate.vfo_state_b;
  }
  if (local_3 == 2) {
    bVar1 = memch_current_is_special(param_1);
    if (bVar1 == 1) {
      return;
    }
    vfo_mem_to_memtune(param_1);
    PTR_g_ui_00025d58->vfo_refresh_req = 1;
  }
  FUN_fffc5e0a(param_1,param_2);
  return;
}


// ===== vfo_mem_to_memtune @ fffc5ce0 (51 bytes)

/* state 2 -> 4 (PMS pair) or 3 (memory tune) */

void vfo_mem_to_memtune(char param_1)

{
  byte bVar1;
  undefined1 uStack_2;
  
  bVar1 = pms_load_limits(param_1);
  if (bVar1 == 1) {
    uStack_2 = 4;
  }
  else {
    uStack_2 = 3;
  }
  if (param_1 != '\0') {
    g_opstate.vfo_state_b = uStack_2;
    return;
  }
  g_opstate.vfo_state_a = uStack_2;
  return;
}


// ===== pms_load_limits @ fffc5d13 (247 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc5d92) */
/* WARNING: Removing unreachable block (ram,0xfffc5d8c) */
/* WARNING: Removing unreachable block (ram,0xfffc5db6) */
/* WARNING: Removing unreachable block (ram,0xfffc5dbc) */
/* P-pair channel freqs -> 0x20F74/0x20F78 (sorted) */

byte pms_load_limits(byte param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbStack_8;
  byte bStack_3;
  byte local_1;
  
  local_1 = param_1;
  bStack_3 = memch_current(param_1);
  if ((bStack_3 < 99) || (0x74 < bStack_3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if ((bStack_3 & 1) == 0) {
      bStack_3 = bStack_3 - 1;
    }
    bVar1 = memch_valid(bStack_3,&pbStack_8);
    if ((bVar1) && (bVar1 = memch_valid(bStack_3 + 1,&pbStack_8), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uVar3 = (uint)bStack_3;
      uVar2 = (uint)memch[uVar3].freq_be[0] << 0x18 | (uint)memch[uVar3].freq_be[1] << 0x10 |
              (uint)memch[uVar3].freq_be[2] << 8 | (uint)memch[uVar3].freq_be[3];
      uVar3 = (uint)bStack_3;
      uVar3 = (uint)memch[uVar3 + 1].freq_be[0] << 0x18 | (uint)memch[uVar3 + 1].freq_be[1] << 0x10
              | (uint)memch[uVar3 + 1].freq_be[2] << 8 | (uint)memch[uVar3 + 1].freq_be[3];
      if (uVar3 < uVar2) {
        PTR_g_ui_00025d58->pms_lo = uVar3;
        PTR_g_ui_00025d58->pms_hi = uVar2;
      }
      else {
        PTR_g_ui_00025d58->pms_lo = uVar2;
        PTR_g_ui_00025d58->pms_hi = uVar3;
      }
      return 1;
    }
  }
  return 0;
}


// ===== FUN_fffc5e0a @ fffc5e0a (186 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc5e38) */
/* WARNING: Removing unreachable block (ram,0xfffc5e3e) */

void FUN_fffc5e0a(byte param_1,byte param_2)

{
  vfo_rec *pvVar1;
  uint local_c;
  byte *local_8;
  byte local_3;
  
  if (param_1 == 0) {
    pvVar1 = &g_opstate.vfo_a;
  }
  else {
    pvVar1 = &g_opstate.vfo_b;
  }
  local_8 = pvVar1->freq_be;
  local_c = (uint)*local_8 << 0x18 | (uint)local_8[1] << 0x10 | (uint)local_8[2] << 8 |
            (uint)local_8[3];
  PTR_g_ui_00025d58->f_0x46d_u8 = 1;
  local_3 = 0;
  if (PTR_g_ui_00025d58->ch_knob_mode == 0) {
    for (; local_3 < param_2; local_3 = local_3 + 1) {
      local_c = FUN_fffc5ec4(param_1,local_c);
    }
  }
  else {
    for (; local_3 < param_2; local_3 = local_3 + 1) {
      local_c = FUN_fffc6073(param_1,local_c);
    }
  }
  *local_8 = (byte)(local_c >> 0x18);
  local_8[1] = (byte)(local_c >> 0x10);
  local_8[2] = (byte)(local_c >> 8);
  local_8[3] = (byte)local_c;
  PTR_g_ui_00025d58->f_0x46d_u8 = 0;
  return;
}


// ===== FUN_fffc5ec4 @ fffc5ec4 (104 bytes)

uint FUN_fffc5ec4(byte param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uStack_14;
  uint local_10 [2];
  uint local_8;
  byte local_1;
  
  if ((PTR_g_ui_00025d58->f_0x415_u8 == 0) && (PTR_g_ui_00025d58->f_0x46a_u8 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  uVar3 = param_2;
  local_8 = param_2;
  local_1 = param_1;
  if (bVar1) {
    FUN_fffc6103(param_1,&local_8,(int *)local_10);
    uVar3 = local_10[0];
  }
  local_10[0] = uVar3;
  uVar3 = FUN_fffc616e(local_1);
  local_10[0] = uVar3 + local_10[0];
  bVar2 = FUN_fffc5f2c(local_1,local_10);
  if (bVar2 == 1) {
    uStack_14 = local_10[0];
  }
  else {
    uStack_14 = local_8;
  }
  return uStack_14;
}


// ===== FUN_fffc5f2c @ fffc5f2c (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc5f9a) */

byte FUN_fffc5f2c(byte param_1,void *param_2)

{
  byte bVar1;
  uint uVar2;
  
  if (PTR_g_ui_00025d58->transmitting == 0) {
    uVar2 = freq_clamp(param_1,*(uint *)param_2);
    *(uint *)param_2 = uVar2;
  }
  else if (g_opstate.split_on == 1) {
    uVar2 = freq_clamp(param_1,*(uint *)param_2);
    *(uint *)param_2 = uVar2;
  }
  else {
    bVar1 = FUN_fffc5f9d(param_1,*(uint *)param_2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  vfo_mark_tuned(param_1);
  PTR_g_ui_00025d58->freq_refresh_req = 1;
  return 1;
}


// ===== FUN_fffc5f9d @ fffc5f9d (214 bytes)

byte FUN_fffc5f9d(char param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  uint freq;
  bool bStack_11;
  uint local_10;
  byte local_a;
  uint local_8;
  char local_1;
  
  if (param_1 == '\0') {
    local_a = g_opstate.vfo_state_a;
  }
  else {
    local_a = g_opstate.vfo_state_b;
  }
  if ((local_a == 2) || (local_a == 7)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (local_a != 8)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  local_8 = param_2;
  local_1 = param_1;
  if (bVar1) {
    if ((local_a == 4) &&
       (local_10 = param_2, bVar2 = range_cmp3(&local_10,&PTR_g_ui_00025d58->pms_lo), bVar2 != 2)) {
      return 0;
    }
  }
  else {
    bVar2 = memch_current_is_special(param_1);
    if (bVar2 == 1) {
      return 0;
    }
  }
  if (PTR_g_ui_00025d58->zz_align_mode == 1) {
    if ((local_8 < 1800000) || (74999999 < local_8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      bStack_11 = true;
    }
    else {
      bStack_11 = false;
    }
  }
  else {
    freq = tx_freq_repeater_shift(local_8);
    bStack_11 = tx_freq_allowed(freq);
  }
  return bStack_11;
}


// ===== FUN_fffc6073 @ fffc6073 (144 bytes)

uint FUN_fffc6073(byte param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uStack_18;
  uint local_10 [2];
  uint local_8;
  byte local_1;
  
  if ((PTR_g_ui_00025d58->f_0x415_u8 == 0) && (PTR_g_ui_00025d58->f_0x46a_u8 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  local_10[0] = param_2;
  local_8 = param_2;
  local_1 = param_1;
  if ((!bVar1) || (bVar1 = FUN_fffc6103(param_1,&local_8,(int *)local_10), bVar1)) {
    uVar3 = FUN_fffc616e(local_1);
    if (local_10[0] < uVar3) {
      local_10[0] = 0;
    }
    else {
      local_10[0] = local_10[0] - uVar3;
    }
    bVar2 = FUN_fffc5f2c(local_1,local_10);
    if (bVar2 == 1) {
      uStack_18 = local_10[0];
    }
    else {
      uStack_18 = local_8;
    }
  }
  else {
    bVar2 = FUN_fffc5f2c(local_1,local_10);
    if (bVar2 == 1) {
      uStack_18 = local_10[0];
    }
    else {
      uStack_18 = local_8;
    }
  }
  return uStack_18;
}

