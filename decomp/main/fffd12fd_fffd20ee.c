// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd12fd @ fffd12fd (151 bytes)

/* WARNING: Removing unreachable block (ram,0xfffd1388) */
/* WARNING: Removing unreachable block (ram,0xfffd1391) */
/* WARNING: Removing unreachable block (ram,0xfffd138e) */

undefined4 FUN_fffd12fd(undefined4 param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (PTR_g_ui_00025d60->sd_answer_ready != 1) {
    return param_1;
  }
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  bVar1 = PTR_g_ui_00025d60->sd_answer[0];
  uVar3 = sd_save_xfer_id();
  if ((bVar1 == uVar3) && (PTR_g_ui_00025d60->sd_answer[1] == 0x10)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (PTR_g_ui_00025d60->sd_answer[2] == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    uVar4 = FUN_fffcf566();
    PTR_g_ui_00025d60->f_0x3f7_u8 = 0xb;
    PTR_g_ui_00025d60->f_0x406_u8 = 0;
    return uVar4;
  }
  uVar4 = sd_abort_no_card();
  return uVar4;
}


// ===== sd_info_step @ fffd1394 (20 bytes)

/* Mode 3 step machine (#65) */

void sd_info_step(void)

{
  if (PTR_g_ui_00025d60->f_0x3f7_u8 != 1) {
    return;
  }
  FUN_fffd13a8();
  return;
}


// ===== FUN_fffd13a8 @ fffd13a8 (144 bytes)

void FUN_fffd13a8(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d60->sd_answer_ready != 1) {
    return;
  }
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  if ((PTR_g_ui_00025d60->sd_answer[0] == 0x45) && (PTR_g_ui_00025d60->sd_answer[1] == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (PTR_g_ui_00025d60->sd_answer[2] == 0) {
      FUN_fffd1438();
      PTR_g_ui_00025d60->f_0x3f7_u8 = 2;
      return;
    }
    if (PTR_g_ui_00025d60->sd_answer[2] == 4) {
      FUN_fffcf583();
      sd_step_reset();
      return;
    }
  }
  dialog_no_sd_card();
  sd_step_reset();
  return;
}


// ===== FUN_fffd1438 @ fffd1438 (129 bytes)

void FUN_fffd1438(void)

{
  PTR_g_ui_00025d60->dl_req_sd = 1;
  PTR_g_ui_00025d60->f_0x1e4_u8 = 0x45;
  PTR_g_ui_00025d60->f_0x1e5_u8 = 1;
  PTR_g_ui_00025d60->f_0x1e6_u8 = 0;
  PTR_g_ui_00025d60->f_0x1e7_u8 = 0xff;
  PTR_g_ui_00025d60->f_0x1e8_u8 = 0;
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->f_0x3f7_u8 = 2;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return;
}


// ===== sd_format_step @ fffd14b9 (324 bytes)

/* Mode 4 step machine (#65) */

void sd_format_step(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d60->f_0x3f7_u8 == 3) {
    if (PTR_g_ui_00025d60->sd_answer_ready == 1) {
      PTR_g_ui_00025d60->sd_answer_ready = 0;
      PTR_g_ui_00025d60->f_0x406_u8 = 0;
      if ((PTR_g_ui_00025d60->sd_answer[0] == 0x48) && (PTR_g_ui_00025d60->sd_answer[1] == 0x10)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (PTR_g_ui_00025d60->sd_answer[2] == 0) {
          FUN_fffcf655();
          PTR_g_ui_00025d60->f_0x3f7_u8 = 4;
          return;
        }
        FUN_fffcf672();
        PTR_g_ui_00025d60->f_0x3f7_u8 = 4;
        return;
      }
      dialog_no_sd_card();
      sd_step_reset();
      return;
    }
  }
  else if ((PTR_g_ui_00025d60->f_0x3f7_u8 == 1) && (PTR_g_ui_00025d60->sd_answer_ready == 1)) {
    PTR_g_ui_00025d60->sd_answer_ready = 0;
    if ((PTR_g_ui_00025d60->sd_answer[0] == 0x48) && (PTR_g_ui_00025d60->sd_answer[1] == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (PTR_g_ui_00025d60->sd_answer[2] == 0) {
        DAT_00015de8 = 0xfe;
        FUN_fffd15fd();
        PTR_g_ui_00025d60->f_0x3f7_u8 = 2;
        return;
      }
      if (PTR_g_ui_00025d60->sd_answer[2] == 1) {
        FUN_fffcf68f();
        sd_step_reset();
        return;
      }
    }
    dialog_no_sd_card();
    sd_step_reset();
    return;
  }
  return;
}


// ===== FUN_fffd15fd @ fffd15fd (134 bytes)

void FUN_fffd15fd(void)

{
  PTR_g_ui_00025d60->dl_req_sd = 1;
  PTR_g_ui_00025d60->f_0x1e4_u8 = 0x48;
  PTR_g_ui_00025d60->f_0x1e5_u8 = 1;
  PTR_g_ui_00025d60->f_0x1e6_u8 = 0;
  PTR_g_ui_00025d60->f_0x1e7_u8 = DAT_00015de8;
  PTR_g_ui_00025d60->f_0x1e8_u8 = 0;
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->f_0x3f7_u8 = 2;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return;
}


// ===== FUN_fffd1683 @ fffd1683 (116 bytes)

void FUN_fffd1683(void)

{
  PTR_g_ui_00025d60->dl_req_sd = 1;
  PTR_g_ui_00025d60->f_0x1e4_u8 = 0x48;
  PTR_g_ui_00025d60->f_0x1e5_u8 = 0x10;
  PTR_g_ui_00025d60->f_0x1e6_u8 = 0;
  PTR_g_ui_00025d60->f_0x1e7_u8 = 0;
  PTR_g_ui_00025d60->f_0x1e8_u8 = 0;
  PTR_g_ui_00025d60->sdreq_len = 0x23;
  PTR_g_ui_00025d60->sd_answer_ready = 0;
  PTR_g_ui_00025d60->sdreq_type = 0x43;
  return;
}


// ===== FUN_fffd16f7 @ fffd16f7 (27 bytes)

void FUN_fffd16f7(void)

{
  PTR_g_ui_00025d60->f_0x3f7_u8 = 3;
  PTR_g_ui_00025d60->f_0x406_u8 = 1;
  return;
}


// ===== menu_screen_close @ fffd1712 (126 bytes)

/* Clears UI +0x95 (menu shown), +0x90, +0x88, +0x86, +0x1C5 and sets +0x96 = 1; in PRESET (P1
   +0x41F = 5) opens the MODE pop-up 5 instead [fact] */

void menu_screen_close(void)

{
  PTR_g_ui_00025d60->dl_req_40 = 0;
  PTR_g_ui_00025d60->kbd_open = 0;
  PTR_g_ui_00025d60->dl_req_50 = 0;
  PTR_g_ui_00025d60->dialog_shown = 0;
  PTR_g_ui_00025d60->dl_req_37 = 1;
  PTR_g_ui_00025d60->f_0x1c5_u8 = 0;
  if (PTR_g_ui_00025d60->menu_p1 != 5) {
    return;
  }
  PTR_g_ui_00025d60->dl_req_37 = 0;
  PTR_g_ui_00025d60->popup_code = 5;
  popup_duration_get(5);
  popup_open_timed();
  return;
}


// ===== FUN_fffd1790 @ fffd1790 (94 bytes)

void FUN_fffd1790(char param_1)

{
  byte bVar1;
  
  if (PTR_g_ui_00025d60->dl_req_50 == 1) {
    FUN_fffd17ee((int)param_1);
    return;
  }
  bVar1 = PTR_g_ui_00025d60->menu_state;
  if (bVar1 == 4) {
    FUN_fffd1a46((int)param_1);
    return;
  }
  if (bVar1 == 1) {
    FUN_fffd1943((int)param_1);
    return;
  }
  if (bVar1 == 2) {
    FUN_fffd199a((int)param_1);
    return;
  }
  if (bVar1 == 3) {
    FUN_fffd1a24((int)param_1);
    return;
  }
  if (bVar1 != 0) {
    return;
  }
  FUN_fffd18a5((int)param_1);
  return;
}


// ===== FUN_fffd17ee @ fffd17ee (47 bytes)

void FUN_fffd17ee(char param_1)

{
  if (DAT_00015de3 == '\x04') {
    FUN_fffd1871((int)param_1);
    return;
  }
  if (DAT_00015de3 == '\x02') {
    FUN_fffd1847((int)param_1);
    return;
  }
  if (DAT_00015de3 != '\x01') {
    return;
  }
  FUN_fffd181d((int)param_1);
  return;
}


// ===== FUN_fffd181d @ fffd181d (42 bytes)

void FUN_fffd181d(char param_1)

{
  if (PTR_g_ui_00025d60->f_0x3f7_u8 != 2) {
    return;
  }
  if (param_1 < '\x01') {
    FUN_fffcfc50(1);
    return;
  }
  FUN_fffcfc50(0);
  return;
}


// ===== FUN_fffd1847 @ fffd1847 (42 bytes)

void FUN_fffd1847(char param_1)

{
  if (PTR_g_ui_00025d60->f_0x3f7_u8 != 2) {
    return;
  }
  if (param_1 < '\x01') {
    FUN_fffcfe83(1);
    return;
  }
  FUN_fffcfe83(0);
  return;
}


// ===== FUN_fffd1871 @ fffd1871 (52 bytes)

void FUN_fffd1871(char param_1)

{
  if (PTR_g_ui_00025d60->f_0x3f7_u8 != 2) {
    return;
  }
  if (param_1 < '\x01') {
    DAT_00015de8 = 0xfe;
  }
  else {
    DAT_00015de8 = 0xff;
  }
  FUN_fffd15fd();
  return;
}


// ===== FUN_fffd18a5 @ fffd18a5 (158 bytes)

void FUN_fffd18a5(char param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  
  bVar2 = menu_count_groups(PTR_g_ui_00025d60->menu_p1);
  cVar1 = (&DAT_00015e00)[PTR_g_ui_00025d60->menu_p1];
  if ('\0' < param_1) {
    bVar3 = cVar1 + 1;
    if (bVar3 < bVar2) {
      (&DAT_00015e00)[PTR_g_ui_00025d60->menu_p1] = bVar3;
      PTR_g_ui_00025d60->menu_p2 = bVar3;
      return;
    }
    PTR_g_ui_00025d60->menu_state = 1;
    return;
  }
  if (cVar1 == '\0') {
    return;
  }
  (&DAT_00015e00)[PTR_g_ui_00025d60->menu_p1] = cVar1 - 1U;
  PTR_g_ui_00025d60->menu_p2 = cVar1 - 1U;
  return;
}


// ===== FUN_fffd1943 @ fffd1943 (87 bytes)

void FUN_fffd1943(char param_1)

{
  char cVar1;
  
  cVar1 = menu_count_groups(PTR_g_ui_00025d60->menu_p1);
  if (-1 < param_1) {
    return;
  }
  (&DAT_00015e00)[PTR_g_ui_00025d60->menu_p1] = cVar1 + -1;
  PTR_g_ui_00025d60->menu_p2 = cVar1 - 1;
  PTR_g_ui_00025d60->menu_state = 0;
  return;
}


// ===== FUN_fffd199a @ fffd199a (138 bytes)

void FUN_fffd199a(char param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  bVar1 = menu_p2_global(PTR_g_ui_00025d60->menu_p1,PTR_g_ui_00025d60->menu_p2);
  pbVar2 = (byte *)menu_cursor_of(bVar1);
  if (pbVar2 != (byte *)0x0) {
    bVar1 = menu_count_items(bVar1);
    if ('\0' < param_1) {
      if ((int)(bVar1 - 1) <= (int)(uint)(byte)(*pbVar2 + pbVar2[1])) {
        PTR_g_ui_00025d60->menu_state = 4;
        return;
      }
      if (*pbVar2 < 4) {
        *pbVar2 = *pbVar2 + 1;
        return;
      }
      pbVar2[1] = pbVar2[1] + 1;
      return;
    }
    if ((byte)(*pbVar2 + pbVar2[1]) != 0) {
      if (*pbVar2 != 0) {
        *pbVar2 = *pbVar2 - 1;
        return;
      }
      pbVar2[1] = pbVar2[1] - 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffd1a24 @ fffd1a24 (34 bytes)

void FUN_fffd1a24(char param_1)

{
  if (param_1 < '\x01') {
    PTR_g_ui_00025d60->menu_step_dir = 1;
  }
  else {
    PTR_g_ui_00025d60->menu_step_dir = 0;
  }
  menu_ui_step();
  return;
}


// ===== FUN_fffd1a46 @ fffd1a46 (119 bytes)

void FUN_fffd1a46(char param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  
  cVar1 = menu_count_items(PTR_g_ui_00025d60->menu_p2);
  if ((cVar1 != '\0') && (param_1 < '\0')) {
    bVar2 = menu_p2_global(PTR_g_ui_00025d60->menu_p1,PTR_g_ui_00025d60->menu_p2);
    bVar3 = menu_count_items(bVar2);
    pcVar4 = (char *)menu_cursor_of(bVar2);
    if (bVar3 < 6) {
      pcVar4[1] = '\0';
      *pcVar4 = bVar3 - 1;
    }
    else {
      pcVar4[1] = bVar3 - 5;
      *pcVar4 = '\x04';
    }
    PTR_g_ui_00025d60->menu_state = 2;
    return;
  }
  return;
}


// ===== FUN_fffd1abd @ fffd1abd (27 bytes)

bool FUN_fffd1abd(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc98c1();
  if (iVar1 != 1) {
    FUN_fffd1ad8();
  }
  return iVar1 != 1;
}


// ===== FUN_fffd1ad8 @ fffd1ad8 (206 bytes)

void FUN_fffd1ad8(void)

{
  byte bVar1;
  
  bVar1 = PTR_g_ui_00025d60->menu_state;
  if (bVar1 == 4) {
    PTR_g_ui_00025d60->menu_state = 0;
    return;
  }
  if (bVar1 == 1) {
    beep_request(1);
    FUN_fffc23a4();
    return;
  }
  if (bVar1 == 2) {
    menu_ui_enter();
    return;
  }
  if (bVar1 == 3) {
    FUN_fffcdcfe();
    return;
  }
  if (bVar1 == 0) {
    PTR_g_ui_00025d60->menu_state = 2;
    PTR_g_ui_00025d60->menu_p2 = DAT_0001226e;
    if (PTR_g_ui_00025d60->menu_p1 == 5) {
      if (DAT_0001226e == 4) {
        g_opstate.preset_sel = 4;
        return;
      }
      if (DAT_0001226e == 1) {
        g_opstate.preset_sel = 1;
        return;
      }
      if (DAT_0001226e == 2) {
        g_opstate.preset_sel = 2;
        return;
      }
      if (DAT_0001226e == 3) {
        g_opstate.preset_sel = 3;
        return;
      }
      if (DAT_0001226e == 0) {
        g_opstate.preset_sel = 0;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffd1ba6 @ fffd1ba6 (62 bytes)

undefined1 FUN_fffd1ba6(void)

{
  undefined1 local_2;
  
  local_2 = 0;
  if (DAT_00015de3 == '\x04') {
    local_2 = FUN_fffd000d();
  }
  else if (DAT_00015de3 == '\x02') {
    local_2 = FUN_fffcfdca();
  }
  else if (DAT_00015de3 == '\x03') {
    local_2 = FUN_fffcffb4();
  }
  else if (DAT_00015de3 == '\x01') {
    local_2 = FUN_fffcfb9a();
  }
  return local_2;
}


// ===== menu_ex060101_draw @ fffd1be4 (13 bytes)

/* Menu item ex060101 PRESET NAME: on_draw (#74) */

void menu_ex060101_draw(void)

{
  menu_draw_preset_name(1);
  return;
}


// ===== menu_ex060201_draw @ fffd1bf1 (13 bytes)

/* Menu item ex060201 PRESET NAME: on_draw (#74) */

void menu_ex060201_draw(void)

{
  menu_draw_preset_name(2);
  return;
}


// ===== menu_ex060301_draw @ fffd1bfe (13 bytes)

/* Menu item ex060301 PRESET NAME: on_draw (#74) */

void menu_ex060301_draw(void)

{
  menu_draw_preset_name(3);
  return;
}


// ===== menu_ex060401_draw @ fffd1c0b (13 bytes)

/* Menu item ex060401 PRESET NAME: on_draw (#74) */

void menu_ex060401_draw(void)

{
  menu_draw_preset_name(4);
  return;
}


// ===== menu_ex060501_draw @ fffd1c18 (13 bytes)

/* Menu item ex060501 PRESET NAME: on_draw (#74) */

void menu_ex060501_draw(void)

{
  menu_draw_preset_name(5);
  return;
}


// ===== menu_draw_preset_name @ fffd1c25 (288 bytes)

/* PRESET1..5 PRESET NAME row (12 chars at 0x9B2E + 0x1F*(n-1)) [fact] */

void menu_draw_preset_name(byte param_1,byte *param_2)

{
  bool bVar1;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00012271 == '\x01') {
      *param_2 = *param_2 | 0x40;
    }
    param_2[1] = 0xc;
    param_2[2] = 0;
    if (param_1 == 5) {
      *(undefined4 *)(param_2 + 0x20) = g_opstate.presets[4].name._8_4_;
      *(undefined4 *)(param_2 + 0x1c) = g_opstate.presets[4].name._4_4_;
      *(undefined4 *)(param_2 + 0x18) = g_opstate.presets[4].name._0_4_;
      return;
    }
    if (param_1 == 2) {
      *(undefined4 *)(param_2 + 0x20) = g_opstate.presets[1].name._8_4_;
      *(undefined4 *)(param_2 + 0x1c) = g_opstate.presets[1].name._4_4_;
      *(undefined4 *)(param_2 + 0x18) = g_opstate.presets[1].name._0_4_;
      return;
    }
    if (param_1 == 3) {
      *(undefined4 *)(param_2 + 0x20) = g_opstate.presets[2].name._8_4_;
      *(undefined4 *)(param_2 + 0x1c) = g_opstate.presets[2].name._4_4_;
      *(undefined4 *)(param_2 + 0x18) = g_opstate.presets[2].name._0_4_;
      return;
    }
    if (param_1 == 4) {
      *(undefined4 *)(param_2 + 0x20) = g_opstate.presets[3].name._8_4_;
      *(undefined4 *)(param_2 + 0x1c) = g_opstate.presets[3].name._4_4_;
      *(undefined4 *)(param_2 + 0x18) = g_opstate.presets[3].name._0_4_;
      return;
    }
    if (param_1 == 1) {
      *(undefined4 *)(param_2 + 0x20) = g_opstate.presets[0].name._8_4_;
      *(undefined4 *)(param_2 + 0x1c) = g_opstate.presets[0].name._4_4_;
      *(undefined4 *)(param_2 + 0x18) = g_opstate.presets[0].name._0_4_;
      return;
    }
  }
  return;
}


// ===== menu_ex060102_draw @ fffd1d45 (13 bytes)

/* Menu item ex060102 CAT-1 RATE: on_draw (#74) */

void menu_ex060102_draw(void)

{
  menu_draw_preset_cat_rate(1);
  return;
}


// ===== menu_ex060202_draw @ fffd1d52 (13 bytes)

/* Menu item ex060202 CAT-1 RATE: on_draw (#74) */

void menu_ex060202_draw(void)

{
  menu_draw_preset_cat_rate(2);
  return;
}


// ===== menu_ex060302_draw @ fffd1d5f (13 bytes)

/* Menu item ex060302 CAT-1 RATE: on_draw (#74) */

void menu_ex060302_draw(void)

{
  menu_draw_preset_cat_rate(3);
  return;
}


// ===== menu_ex060402_draw @ fffd1d6c (13 bytes)

/* Menu item ex060402 CAT-1 RATE: on_draw (#74) */

void menu_ex060402_draw(void)

{
  menu_draw_preset_cat_rate(4);
  return;
}


// ===== menu_ex060502_draw @ fffd1d79 (13 bytes)

/* Menu item ex060502 CAT-1 RATE: on_draw (#74) */

void menu_ex060502_draw(void)

{
  menu_draw_preset_cat_rate(5);
  return;
}


// ===== menu_draw_preset_cat_rate @ fffd1d86 (234 bytes)

/* PRESET n CAT-1 RATE row: 4800..115200bps (ROM 0xFFF8455B) [fact] */

void menu_draw_preset_cat_rate(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = g_opstate.presets[4].cat1_rate;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].cat1_rate;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].cat1_rate;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].cat1_rate;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].cat1_rate;
  }
  if (local_b == 3) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 10;
  param_2[2] = 0;
  if (4 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x1047);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060103_draw @ fffd1e70 (13 bytes)

/* Menu item ex060103 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060103_draw(void)

{
  menu_draw_preset_cat_tot(1);
  return;
}


// ===== menu_ex060203_draw @ fffd1e7d (13 bytes)

/* Menu item ex060203 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060203_draw(void)

{
  menu_draw_preset_cat_tot(2);
  return;
}


// ===== menu_ex060303_draw @ fffd1e8a (13 bytes)

/* Menu item ex060303 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060303_draw(void)

{
  menu_draw_preset_cat_tot(3);
  return;
}


// ===== menu_ex060403_draw @ fffd1e97 (13 bytes)

/* Menu item ex060403 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060403_draw(void)

{
  menu_draw_preset_cat_tot(4);
  return;
}


// ===== menu_ex060503_draw @ fffd1ea4 (13 bytes)

/* Menu item ex060503 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex060503_draw(void)

{
  menu_draw_preset_cat_tot(5);
  return;
}


// ===== menu_draw_preset_cat_tot @ fffd1eb1 (235 bytes)

/* PRESET n CAT-1 TIME OUT TIMER row: 10/100/1000/3000msec (ROM 0xFFF845C4) [fact] */

void menu_draw_preset_cat_tot(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = g_opstate.presets[4].cat1_tot;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].cat1_tot;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].cat1_tot;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].cat1_tot;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].cat1_tot;
  }
  if (local_b == 0) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0x14;
  param_2[2] = 0;
  if (3 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x10b0);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060104_draw @ fffd1f9c (13 bytes)

/* Menu item ex060104 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060104_draw(void)

{
  menu_draw_preset_stop_bit(1);
  return;
}


// ===== menu_ex060204_draw @ fffd1fa9 (13 bytes)

/* Menu item ex060204 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060204_draw(void)

{
  menu_draw_preset_stop_bit(2);
  return;
}


// ===== menu_ex060304_draw @ fffd1fb6 (13 bytes)

/* Menu item ex060304 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060304_draw(void)

{
  menu_draw_preset_stop_bit(3);
  return;
}


// ===== menu_ex060404_draw @ fffd1fc3 (13 bytes)

/* Menu item ex060404 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060404_draw(void)

{
  menu_draw_preset_stop_bit(4);
  return;
}


// ===== menu_ex060504_draw @ fffd1fd0 (13 bytes)

/* Menu item ex060504 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex060504_draw(void)

{
  menu_draw_preset_stop_bit(5);
  return;
}


// ===== menu_draw_preset_stop_bit @ fffd1fdd (234 bytes)

/* PRESET n CAT-1 CAT-3 STOP BIT row [fact] */

void menu_draw_preset_stop_bit(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_b = g_opstate.presets[4].cat1_cat3_stop_bit;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].cat1_cat3_stop_bit;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].cat1_cat3_stop_bit;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].cat1_cat3_stop_bit;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].cat1_cat3_stop_bit;
  }
  if (local_b == 0) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 4;
  param_2[2] = 0;
  if (1 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (int)(&DAT_00002328 + (uint)local_b * 0x15));
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060105_draw @ fffd20c7 (13 bytes)

/* Menu item ex060105 AGC FAST DELAY: on_draw (#74) */

void menu_ex060105_draw(void)

{
  menu_draw_preset_agc_fast(1);
  return;
}


// ===== menu_ex060205_draw @ fffd20d4 (13 bytes)

/* Menu item ex060205 AGC FAST DELAY: on_draw (#74) */

void menu_ex060205_draw(void)

{
  menu_draw_preset_agc_fast(2);
  return;
}


// ===== menu_ex060305_draw @ fffd20e1 (13 bytes)

/* Menu item ex060305 AGC FAST DELAY: on_draw (#74) */

void menu_ex060305_draw(void)

{
  menu_draw_preset_agc_fast(3);
  return;
}


// ===== menu_ex060405_draw @ fffd20ee (13 bytes)

/* Menu item ex060405 AGC FAST DELAY: on_draw (#74) */

void menu_ex060405_draw(void)

{
  menu_draw_preset_agc_fast(4);
  return;
}

