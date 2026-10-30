// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== dsp_knob_notch_toggle @ fffbdb63 (298 bytes)

/* DSP key short press with knob function 2 (NOTCH): toggles dsp_knob_edit, FUNC item 0x1F, and in
   edit mode bit 0x80 of the active VFO mode-block flags [fact: fffbdb63]; caller key_dsp_release */

void dsp_knob_notch_toggle(void)

{
  byte bVar1;
  uint uVar2;
  mode_blk *local_8;
  vfo_rec *local_4;
  
  if (PTR_g_ui_00025d54->dsp_knob_edit != 0) {
    PTR_g_ui_00025d54->dsp_knob_edit = 0;
    PTR_g_ui_00025d54->func_blink_en = 0;
    PTR_g_ui_00025d54->func_blink_on = 1;
    goto LAB_fffbdc83;
  }
  PTR_g_ui_00025d54->dsp_knob_edit = 1;
  PTR_g_ui_00025d54->func_knob_item = 0x1f;
  if (PTR_g_ui_00025d54->dsp_knob_func == 2) {
    if (g_opstate.active_vfo == VFO_A) {
      local_4 = &g_opstate.vfo_a;
    }
    else {
      local_4 = &g_opstate.vfo_b;
    }
    uVar2 = local_4->mode & 0xf;
    if (uVar2 == 0xe) {
LAB_fffbdc16:
      local_8 = local_4->blk + 3;
    }
    else if (uVar2 - 2 < 2) {
      local_8 = local_4->blk + 1;
    }
    else if (uVar2 - 4 < 2) {
      local_8 = local_4->blk + 4;
    }
    else {
      if (uVar2 - 8 < 2) goto LAB_fffbdc16;
      if (uVar2 - 0xc < 2) {
        local_8 = local_4->blk + 2;
      }
      else {
        if ((local_4->mode & 0xf) != 0 && uVar2 != 1) {
          return;
        }
        local_8 = local_4->blk;
      }
    }
    bVar1 = local_8->flags;
    if ((bVar1 & 0x80) == 0) {
      local_8->flags = bVar1 | 0x80;
    }
    else {
      local_8->flags = bVar1 & 0x7f;
    }
  }
  else {
    PTR_g_ui_00025d54->func_knob_item = 0x1f;
    PTR_g_ui_00025d54->dsp_knob_func = 2;
  }
  PTR_g_ui_00025d54->func_blink_en = 1;
  swtimer_start(0x45,0x1c2);
  func_display_open();
LAB_fffbdc83:
  beep_request(1);
  return;
}


// ===== notch_reset_beep @ fffbdc8d (35 bytes)

/* vfo_notch_reset(active VFO), beep 2 [fact: fffbdc8d]; no direct caller (reached through a table)
    */

void notch_reset_beep(void)

{
  vfo_notch_reset(g_opstate.active_vfo != VFO_A);
  beep_request(2);
  return;
}


// ===== dsp_knob_contour_toggle @ fffbdcb0 (389 bytes)

/* DSP key short press with knob function 3 and APF off: toggles dsp_knob_edit, FUNC item 0x20
   (CONTOUR), changes bit 0x40 of the active VFO mode-block flags [fact: fffbdcb0]; caller
   key_dsp_release */

void dsp_knob_contour_toggle(void)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  mode_blk *local_8;
  vfo_rec *local_4;
  
  bVar2 = false;
  if (PTR_g_ui_00025d54->dsp_knob_edit != 0) {
    PTR_g_ui_00025d54->dsp_knob_edit = 0;
    PTR_g_ui_00025d54->func_blink_en = 0;
    PTR_g_ui_00025d54->func_blink_on = 1;
    goto LAB_fffbde2b;
  }
  PTR_g_ui_00025d54->dsp_knob_edit = 1;
  PTR_g_ui_00025d54->func_knob_item = 0x20;
  if (PTR_g_ui_00025d54->dsp_knob_func == 3) {
    if (g_opstate.active_vfo == VFO_A) {
      local_4 = &g_opstate.vfo_a;
    }
    else {
      local_4 = &g_opstate.vfo_b;
    }
    uVar3 = local_4->mode & 0xf;
    if (uVar3 == 0xe) {
LAB_fffbdd86:
      local_8 = local_4->blk + 3;
    }
    else if (uVar3 - 2 < 2) {
      local_8 = local_4->blk + 1;
      bVar2 = true;
    }
    else if (uVar3 - 4 < 2) {
      local_8 = local_4->blk + 4;
    }
    else {
      if (1 < uVar3 - 6) {
        if (uVar3 - 8 < 2) goto LAB_fffbdd86;
        if (1 < uVar3 - 10) {
          if (uVar3 - 0xc < 2) {
            local_8 = local_4->blk + 2;
          }
          else {
            if ((local_4->mode & 0xf) != 0 && uVar3 != 1) {
              return;
            }
            local_8 = local_4->blk;
          }
          goto LAB_fffbdd8f;
        }
      }
      local_8 = local_4->blk + 5;
    }
LAB_fffbdd8f:
    bVar1 = local_8->flags;
    if (bVar2) {
      if ((bVar1 & 0x40) == 0) {
        local_8->flags = bVar1 | 0x40;
      }
      else {
        local_8->flags = bVar1 & 0xbf;
        PTR_g_ui_00025d54->dsp_knob_apf = 1;
        PTR_g_ui_00025d54->func_knob_item = 0x21;
      }
    }
    else if ((bVar1 & 0x40) == 0) {
      local_8->flags = bVar1 | 0x40;
    }
    else {
      local_8->flags = bVar1 & 0xbf;
    }
  }
  else {
    PTR_g_ui_00025d54->func_knob_item = 0x20;
    PTR_g_ui_00025d54->dsp_knob_func = 3;
  }
  PTR_g_ui_00025d54->func_blink_en = 1;
  swtimer_start(0x45,0x1c2);
  func_display_open();
LAB_fffbde2b:
  beep_request(1);
  return;
}


// ===== contour_reset_beep @ fffbde35 (35 bytes)

/* vfo_contour_reset(active VFO), beep 2 [fact: fffbde35]; no direct caller (reached through a
   table) */

void contour_reset_beep(void)

{
  vfo_contour_reset(g_opstate.active_vfo != VFO_A);
  beep_request(2);
  return;
}


// ===== dsp_knob_apf_toggle @ fffbde58 (285 bytes)

/* DSP key short press with knob function 3 and dsp_knob_apf set: toggles dsp_knob_edit, FUNC item
   0x21 (APF) [fact: fffbde58]; caller key_dsp_release */

void dsp_knob_apf_toggle(void)

{
  bool bVar1;
  byte bVar2;
  vfo_rec *local_4;
  
  if (PTR_g_ui_00025d54->dsp_knob_edit == 0) {
    PTR_g_ui_00025d54->dsp_knob_edit = 1;
    PTR_g_ui_00025d54->func_knob_item = 0x21;
    if (PTR_g_ui_00025d54->dsp_knob_func == 3) {
      if (g_opstate.active_vfo == VFO_A) {
        local_4 = &g_opstate.vfo_a;
      }
      else {
        local_4 = &g_opstate.vfo_b;
      }
      bVar2 = local_4->mode & 0xf;
      if ((bVar2 == 3) || (bVar2 == 2)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        return;
      }
      bVar2 = local_4->blk[1].flags;
      if ((local_4->blk[1].flags & 0x20) == 0) {
        local_4->blk[1].flags = bVar2 | 0x20;
      }
      else {
        local_4->blk[1].flags = bVar2 & 0xdf;
        local_4->blk[1].flags = local_4->blk[1].flags | 0x40;
        PTR_g_ui_00025d54->dsp_knob_apf = 0;
        PTR_g_ui_00025d54->func_knob_item = 0x20;
      }
    }
    else {
      PTR_g_ui_00025d54->func_knob_item = 0x21;
      PTR_g_ui_00025d54->dsp_knob_func = 3;
    }
    PTR_g_ui_00025d54->func_blink_en = 1;
    swtimer_start(0x45,0x1c2);
    func_display_open();
  }
  else {
    PTR_g_ui_00025d54->dsp_knob_edit = 0;
    PTR_g_ui_00025d54->func_blink_en = 0;
    PTR_g_ui_00025d54->func_blink_on = 1;
  }
  beep_request(1);
  return;
}


// ===== apf_reset_beep @ fffbdf75 (35 bytes)

/* vfo_apf_reset(active VFO), beep 2 [fact: fffbdf75]; no direct caller (reached through a table) */

void apf_reset_beep(void)

{
  vfo_apf_reset(g_opstate.active_vfo != VFO_A);
  beep_request(2);
  return;
}


// ===== FUN_fffbdf98 @ fffbdf98 (416 bytes)

void FUN_fffbdf98(void)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  mode_blk *local_8;
  vfo_rec *local_4;
  
  bVar2 = false;
  if (PTR_g_ui_00025d54->dsp_knob_edit != 0) {
    PTR_g_ui_00025d54->dsp_knob_edit = 0;
    PTR_g_ui_00025d54->func_blink_en = 0;
    PTR_g_ui_00025d54->func_blink_on = 1;
    goto LAB_fffbe12e;
  }
  PTR_g_ui_00025d54->dsp_knob_edit = 1;
  if (g_opstate.active_vfo == VFO_A) {
    local_4 = &g_opstate.vfo_a;
  }
  else {
    local_4 = &g_opstate.vfo_b;
  }
  uVar3 = local_4->mode & 0xf;
  if (uVar3 == 0xe) {
LAB_fffbe052:
    local_8 = local_4->blk + 3;
  }
  else if (uVar3 - 2 < 2) {
    local_8 = local_4->blk + 1;
    bVar2 = true;
  }
  else if (uVar3 - 4 < 2) {
    local_8 = local_4->blk + 4;
  }
  else {
    if (1 < uVar3 - 6) {
      if (uVar3 - 8 < 2) goto LAB_fffbe052;
      if (1 < uVar3 - 10) {
        if (uVar3 - 0xc < 2) {
          local_8 = local_4->blk + 2;
        }
        else {
          if ((local_4->mode & 0xf) != 0 && uVar3 != 1) {
            return;
          }
          local_8 = local_4->blk;
        }
        goto LAB_fffbe05b;
      }
    }
    local_8 = local_4->blk + 5;
  }
LAB_fffbe05b:
  if (PTR_g_ui_00025d54->dsp_knob_func == 2) {
    bVar1 = local_8->flags;
    if ((bVar1 & 0x80) == 0) {
      local_8->flags = bVar1 | 0x80;
    }
    else {
      local_8->flags = bVar1 & 0x7f;
    }
  }
  else if (PTR_g_ui_00025d54->dsp_knob_func == 3) {
    if (bVar2) {
      if (PTR_g_ui_00025d54->dsp_knob_apf == 0) {
        bVar1 = local_8->flags;
        if ((bVar1 & 0x40) == 0) {
          local_8->flags = bVar1 | 0x40;
        }
        else {
          local_8->flags = bVar1 & 0xbf;
        }
      }
      else if (PTR_g_ui_00025d54->dsp_knob_apf == 1) {
        bVar1 = local_8->flags;
        if ((bVar1 & 0x20) == 0) {
          local_8->flags = bVar1 | 0x20;
        }
        else {
          local_8->flags = bVar1 & 0xdf;
        }
      }
    }
    else {
      bVar1 = local_8->flags;
      if ((bVar1 & 0x40) == 0) {
        local_8->flags = bVar1 | 0x40;
      }
      else {
        local_8->flags = bVar1 & 0xbf;
      }
    }
  }
  PTR_g_ui_00025d54->func_blink_en = 1;
  swtimer_start(0x45,0x1c2);
  func_display_open();
LAB_fffbe12e:
  beep_request(1);
  return;
}


// ===== FUN_fffbe138 @ fffbe138 (7 bytes)

void FUN_fffbe138(void)

{
  func_knob_assign_key(0xd0);
  return;
}


// ===== FUN_fffbe13f @ fffbe13f (7 bytes)

void FUN_fffbe13f(void)

{
  func_knob_assign_key(0xd1);
  return;
}


// ===== FUN_fffbe146 @ fffbe146 (7 bytes)

void FUN_fffbe146(void)

{
  func_knob_assign_key(0xd2);
  return;
}


// ===== FUN_fffbe14d @ fffbe14d (7 bytes)

void FUN_fffbe14d(void)

{
  func_knob_assign_key(0xd3);
  return;
}


// ===== FUN_fffbe154 @ fffbe154 (7 bytes)

void FUN_fffbe154(void)

{
  func_knob_assign_key(0xd4);
  return;
}


// ===== FUN_fffbe15b @ fffbe15b (7 bytes)

void FUN_fffbe15b(void)

{
  func_knob_assign_key(0xd5);
  return;
}


// ===== FUN_fffbe162 @ fffbe162 (7 bytes)

void FUN_fffbe162(void)

{
  func_knob_assign_key(0xd6);
  return;
}


// ===== FUN_fffbe169 @ fffbe169 (7 bytes)

void FUN_fffbe169(void)

{
  func_knob_assign_key(0xd7);
  return;
}


// ===== FUN_fffbe170 @ fffbe170 (7 bytes)

void FUN_fffbe170(void)

{
  func_knob_assign_key(0xd8);
  return;
}


// ===== FUN_fffbe177 @ fffbe177 (7 bytes)

void FUN_fffbe177(void)

{
  func_knob_assign_key(0xd9);
  return;
}


// ===== FUN_fffbe17e @ fffbe17e (7 bytes)

void FUN_fffbe17e(void)

{
  func_knob_assign_key(0xda);
  return;
}


// ===== FUN_fffbe185 @ fffbe185 (7 bytes)

void FUN_fffbe185(void)

{
  func_knob_assign_key(0xdb);
  return;
}


// ===== FUN_fffbe18c @ fffbe18c (7 bytes)

void FUN_fffbe18c(void)

{
  func_knob_assign_key(0xdc);
  return;
}


// ===== FUN_fffbe193 @ fffbe193 (7 bytes)

void FUN_fffbe193(void)

{
  func_knob_assign_key(0xdd);
  return;
}


// ===== FUN_fffbe19a @ fffbe19a (7 bytes)

void FUN_fffbe19a(void)

{
  func_knob_assign_key(0xde);
  return;
}


// ===== FUN_fffbe1a1 @ fffbe1a1 (7 bytes)

void FUN_fffbe1a1(void)

{
  func_knob_assign_key(0xdf);
  return;
}


// ===== FUN_fffbe1a8 @ fffbe1a8 (7 bytes)

void FUN_fffbe1a8(void)

{
  func_knob_assign_key(0xe0);
  return;
}


// ===== FUN_fffbe1af @ fffbe1af (10 bytes)

void FUN_fffbe1af(void)

{
  func_knob_assign_key(0xe1);
  vfo_mark_edited_if_vfo();
  return;
}


// ===== FUN_fffbe1b9 @ fffbe1b9 (7 bytes)

void FUN_fffbe1b9(void)

{
  func_knob_assign_key(0xe2);
  return;
}


// ===== FUN_fffbe1c0 @ fffbe1c0 (7 bytes)

void FUN_fffbe1c0(void)

{
  func_knob_assign_key(0xe3);
  return;
}


// ===== FUN_fffbe1c7 @ fffbe1c7 (7 bytes)

void FUN_fffbe1c7(void)

{
  func_knob_assign_key(0xe4);
  return;
}


// ===== FUN_fffbe1ce @ fffbe1ce (7 bytes)

void FUN_fffbe1ce(void)

{
  func_knob_assign_key(0xe5);
  return;
}


// ===== FUN_fffbe1d5 @ fffbe1d5 (7 bytes)

void FUN_fffbe1d5(void)

{
  func_knob_assign_key(0xe6);
  return;
}


// ===== FUN_fffbe1dc @ fffbe1dc (7 bytes)

void FUN_fffbe1dc(void)

{
  func_knob_assign_key(0xe7);
  return;
}


// ===== FUN_fffbe1e3 @ fffbe1e3 (7 bytes)

void FUN_fffbe1e3(void)

{
  func_knob_assign_key(0xe8);
  return;
}


// ===== FUN_fffbe1ea @ fffbe1ea (7 bytes)

void FUN_fffbe1ea(void)

{
  func_knob_assign_key(0xe9);
  return;
}


// ===== FUN_fffbe1f1 @ fffbe1f1 (7 bytes)

void FUN_fffbe1f1(void)

{
  func_knob_assign_key(0xec);
  return;
}


// ===== FUN_fffbe1f8 @ fffbe1f8 (1 bytes)

void FUN_fffbe1f8(void)

{
  return;
}


// ===== FUN_fffbe1f9 @ fffbe1f9 (7 bytes)

void FUN_fffbe1f9(void)

{
  func_knob_assign_key(0xed);
  return;
}


// ===== FUN_fffbe200 @ fffbe200 (7 bytes)

void FUN_fffbe200(void)

{
  func_knob_assign_key(0xee);
  return;
}


// ===== FUN_fffbe207 @ fffbe207 (7 bytes)

void FUN_fffbe207(void)

{
  func_knob_assign_key(0xef);
  return;
}


// ===== FUN_fffbe20e @ fffbe20e (7 bytes)

void FUN_fffbe20e(void)

{
  func_knob_assign_key(0xf0);
  return;
}


// ===== FUN_fffbe215 @ fffbe215 (7 bytes)

void FUN_fffbe215(void)

{
  func_knob_assign_key(0xf1);
  return;
}


// ===== FUN_fffbe21c @ fffbe21c (7 bytes)

void FUN_fffbe21c(void)

{
  func_knob_assign_key(0xf2);
  return;
}


// ===== FUN_fffbe223 @ fffbe223 (7 bytes)

void FUN_fffbe223(void)

{
  func_knob_assign_key(0xf3);
  return;
}


// ===== FUN_fffbe22a @ fffbe22a (7 bytes)

void FUN_fffbe22a(void)

{
  ui_softkey_dispatch(0xfe);
  return;
}


// ===== FUN_fffbe231 @ fffbe231 (1 bytes)

void FUN_fffbe231(void)

{
  return;
}


// ===== FUN_fffbe232 @ fffbe232 (7 bytes)

void FUN_fffbe232(void)

{
  ui_softkey_dispatch(0xff);
  return;
}


// ===== FUN_fffbe239 @ fffbe239 (6 bytes)

void FUN_fffbe239(void)

{
  memlist_key(0);
  return;
}


// ===== FUN_fffbe23f @ fffbe23f (6 bytes)

void FUN_fffbe23f(void)

{
  memlist_key(1);
  return;
}


// ===== FUN_fffbe245 @ fffbe245 (6 bytes)

void FUN_fffbe245(void)

{
  memlist_key(2);
  return;
}


// ===== FUN_fffbe24b @ fffbe24b (6 bytes)

void FUN_fffbe24b(void)

{
  memlist_key(3);
  return;
}


// ===== FUN_fffbe251 @ fffbe251 (6 bytes)

void FUN_fffbe251(void)

{
  memlist_key(4);
  return;
}

