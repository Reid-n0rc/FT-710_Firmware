// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc6103 @ fffc6103 (107 bytes)

bool FUN_fffc6103(byte param_1,uint *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uStack_14;
  
  DAT_0001b4e5 = 1;
  DAT_0001b4e6 = '\0';
  uStack_14 = FUN_fffc616e(param_1);
  DAT_0001b4e5 = 0;
  if (DAT_0001b4e6 == '\x01') {
    uStack_14 = uStack_14 * 10;
  }
  uVar1 = *param_2;
  uVar3 = uVar1;
  if (uStack_14 != 0) {
    uVar3 = uVar1 / uStack_14;
  }
  uVar2 = *param_2;
  if (uStack_14 != 0) {
    uVar2 = uVar2 / uStack_14;
  }
  *param_3 = uVar2 * uStack_14;
  return uVar1 == uVar3 * uStack_14;
}


// ===== FUN_fffc616e @ fffc616e (320 bytes)

uint FUN_fffc616e(byte param_1)

{
  bool bVar1;
  short sVar2;
  byte local_d;
  undefined *local_c;
  
  local_d = g_opstate.vfo_a.mode;
  if (param_1 != 0) {
    local_d = g_opstate.vfo_b.mode;
  }
  local_d = local_d & 0xf;
  if (PTR_g_ui_00025d58->f_0x415_u8 == 1) {
    if (PTR_g_ui_00025d58->f_0x416_u8 == 0) {
      local_c = &DAT_000f4240;
    }
    else {
      local_c = (undefined *)0x3e8;
    }
  }
  else if (PTR_g_ui_00025d58->f_0x46a_u8 == 1) {
    if (PTR_g_ui_00025d58->f_0x479_u8 == 1) {
      local_c = &DAT_000186a0;
    }
    else {
      local_c = &DAT_000f4240;
    }
  }
  else {
    if ((PTR_g_ui_00025d58->scan_running == 1) || (PTR_g_ui_00025d58->f_0x46b_u8 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if ((local_d == 6) || (local_d == 7)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 10)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 0xb)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 4)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 5)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        local_c = (undefined *)FUN_fffc63e6(local_d);
      }
      else {
        sVar2 = FUN_fffc62ae(local_d);
        local_c = (undefined *)(int)sVar2;
      }
    }
    else if (PTR_g_ui_00025d58->f_0x46d_u8 == 1) {
      sVar2 = FUN_fffc62ae(local_d);
      local_c = (undefined *)(int)sVar2;
    }
    else if (PTR_g_ui_00025d58->f_0x478_u8 == 1) {
      local_c = (undefined *)FUN_fffc63e6(local_d);
    }
    else {
      sVar2 = FUN_fffc62ae(local_d);
      local_c = (undefined *)(int)sVar2;
    }
  }
  return (uint)local_c;
}


// ===== FUN_fffc62ae @ fffc62ae (312 bytes)

short FUN_fffc62ae(byte param_1)

{
  uint uVar1;
  short local_6;
  
  uVar1 = (uint)param_1;
  if (uVar1 - 0xc < 3) {
LAB_fffc6393:
    if (g_opstate.fn_select == 1) {
      local_6 = 1;
    }
    else {
      if (g_opstate.ex030502_rtty_psk_dial_step == 0) {
        local_6 = 5;
      }
      else if (g_opstate.ex030502_rtty_psk_dial_step == 1) {
        local_6 = 10;
      }
      else {
        local_6 = 0x14;
      }
      if (g_opstate.fn_select == 2) {
        local_6 = local_6 * 10;
      }
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (g_opstate.fn_select == 1) {
        return 10;
      }
      if (g_opstate.fn_select != 2) {
        return 100;
      }
      return 1000;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc6393;
      if (1 < uVar1 - 10) {
        if (3 < uVar1) {
          return local_6;
        }
        if (g_opstate.fn_select != 1) {
          if (g_opstate.ex030501_ssb_cw_dial_step == 0) {
            local_6 = 5;
          }
          else if (g_opstate.ex030501_ssb_cw_dial_step == 1) {
            local_6 = 10;
          }
          else {
            local_6 = 0x14;
          }
          if (g_opstate.fn_select != 2) {
            return local_6;
          }
          return local_6 * 10;
        }
        return 1;
      }
    }
    if (g_opstate.fn_select == 1) {
      local_6 = 10;
    }
    else {
      local_6 = 100;
      if (g_opstate.fn_select == 2) {
        local_6 = 1000;
      }
    }
  }
  return local_6;
}


// ===== FUN_fffc63e6 @ fffc63e6 (166 bytes)

uint FUN_fffc63e6(byte param_1)

{
  uint uVar1;
  byte local_d;
  
  uVar1 = (uint)param_1;
  if (3 < uVar1) {
    if (uVar1 - 4 < 2) {
      local_d = g_opstate.ex030504_am_ch_step;
      if (5 < g_opstate.ex030504_am_ch_step) {
        local_d = 0;
      }
      uVar1 = FUN_fffc648c((uint)*(ushort *)(BYTE_ARRAY_fff88514 + (uint)local_d * 2 + 8));
      return uVar1;
    }
    if (uVar1 - 6 < 2) {
LAB_fffc6462:
      local_d = g_opstate.ex030505_fm_ch_step;
      if (5 < g_opstate.ex030505_fm_ch_step) {
        local_d = 0;
      }
      uVar1 = FUN_fffc648c((uint)*(ushort *)(BYTE_ARRAY_fff88514 + (uint)local_d * 2 + 0x14));
      return uVar1;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 10 < 2) goto LAB_fffc6462;
      if (2 < uVar1 - 0xc) {
        return 0;
      }
    }
  }
  local_d = g_opstate.ex030503_ch_step;
  if (3 < g_opstate.ex030503_ch_step) {
    local_d = 0;
  }
  uVar1 = FUN_fffc648c((uint)*(ushort *)(BYTE_ARRAY_fff88514 + (uint)local_d * 2));
  return uVar1;
}


// ===== FUN_fffc648c @ fffc648c (52 bytes)

uint FUN_fffc648c(uint param_1)

{
  undefined4 local_4;
  
  local_4 = param_1;
  if (g_opstate.fn_select == 2) {
    if (DAT_0001b4e5 == '\x01') {
      DAT_0001b4e6 = 1;
    }
    else {
      local_4 = param_1 * 10;
    }
  }
  return local_4;
}


// ===== enc2_step @ fffc64c0 (213 bytes)

/* encoder id 2 by screen [inference: multi knob] */

void enc2_step(char param_1)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d58->numentry_mode == 1) {
    FUN_fffc670d((int)param_1);
    return;
  }
  ui_clear_415_423();
  if (PTR_g_ui_00025d58->dl_block_34 != 1) {
    if (PTR_g_ui_00025d58->dialog_shown != 1) {
      if (PTR_g_ui_00025d58->dl_req_40 == 1) {
        FUN_fffd1790((int)param_1);
        return;
      }
      if (PTR_g_ui_00025d58->zz_align_mode != 1) {
        if ((PTR_g_ui_00025d58->playlist_open == 1) || (PTR_g_ui_00025d58->msgmem_open == 1)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (!bVar1) {
          if (PTR_g_ui_00025d58->dl_req_37 == 1) {
            func_menu_cursor_step((int)param_1);
            return;
          }
          func_knob_turn((int)param_1);
          return;
        }
        FUN_fffc6595((int)param_1);
        return;
      }
      FUN_fffbb963((int)param_1);
      return;
    }
    if (PTR_g_ui_00025d58->f_0x448_u8 == 1) {
      if ('\0' < param_1) {
        PTR_g_ui_00025d58->dialog_button = 1;
        return;
      }
      PTR_g_ui_00025d58->dialog_button = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffc6595 @ fffc6595 (376 bytes)

void FUN_fffc6595(char param_1)

{
  if (PTR_g_ui_00025d58->playlist_open == 1) {
    if (PTR_g_ui_00025d58->playlist_playing == 1) {
      PTR_g_ui_00025d58->playlist_req = 1;
      PTR_g_ui_00025d58->playlist_substate = 4;
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (g_opstate.play_volume != 0)) {
          g_opstate.play_volume = g_opstate.play_volume - 1;
          return;
        }
      }
      else if (g_opstate.play_volume < 100) {
        g_opstate.play_volume = g_opstate.play_volume + 1;
        return;
      }
    }
    else {
      if (param_1 < '\0') {
        FUN_fffe3121();
        return;
      }
      if ('\0' < param_1) {
        FUN_fffe32fd();
        return;
      }
    }
  }
  else if (PTR_g_ui_00025d58->msgmem_open == 1) {
    if (PTR_g_ui_00025d58->msg_playing == 1) {
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (g_opstate.play_volume != 0)) {
          g_opstate.play_volume = g_opstate.play_volume - 1;
          return;
        }
      }
      else if (g_opstate.play_volume < 100) {
        g_opstate.play_volume = g_opstate.play_volume + 1;
        return;
      }
    }
    else if (PTR_g_ui_00025d58->msg_state_1d0 == 1) {
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (g_opstate.level_9dc2 != 0)) {
          g_opstate.level_9dc2 = g_opstate.level_9dc2 - 1;
          return;
        }
      }
      else if (g_opstate.level_9dc2 < 100) {
        g_opstate.level_9dc2 = g_opstate.level_9dc2 + 1;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffc670d @ fffc670d (243 bytes)

void FUN_fffc670d(char param_1)

{
  byte bVar1;
  
  if (DAT_0001b4eb == '\x01') {
    bVar1 = swtimer_expired(0x47);
    if (bVar1 == 0) {
      return;
    }
    DAT_0001b4eb = '\0';
  }
  if (DAT_0001b4ea == '\0') {
    DAT_0001b4ea = 1;
    ui_lamp_set(DAT_0001b4e9,1);
    swtimer_start(0x47,100);
    DAT_0001b4eb = 1;
    return;
  }
  DAT_0001b4ea = 0;
  ui_lamp_set(DAT_0001b4e9,0);
  swtimer_start(0x47,100);
  DAT_0001b4eb = 1;
  if ('\0' < param_1) {
    if (DAT_0001b4e9 < DAT_0001b4e7) {
      DAT_0001b4e9 = DAT_0001b4e9 + 1;
      return;
    }
    DAT_0001b4e9 = DAT_0001b4e8;
    return;
  }
  if (DAT_0001b4e8 < DAT_0001b4e9) {
    DAT_0001b4e9 = DAT_0001b4e9 - 1;
    return;
  }
  DAT_0001b4e9 = DAT_0001b4e7;
  return;
}


// ===== FUN_fffc6800 @ fffc6800 (111 bytes)

void FUN_fffc6800(char param_1)

{
  byte bVar1;
  
  if (PTR_g_ui_00025d58->f_0x43c_u8 == 0) {
    if (PTR_g_ui_00025d58->memlist_flag == 0) {
      FUN_fffc686f((int)param_1);
      return;
    }
    if (PTR_g_ui_00025d58->f_0x43b_u8 == 0) {
      FUN_fffc6bd8((int)param_1);
      return;
    }
  }
  bVar1 = PTR_g_ui_00025d58->memlist_group;
  if (bVar1 == 3) {
    FUN_fffc6b86((int)param_1);
    return;
  }
  if (bVar1 != 2) {
    if (bVar1 == 1) {
      FUN_fffc6ac4((int)param_1);
      return;
    }
    return;
  }
  FUN_fffc6b34((int)param_1);
  return;
}


// ===== FUN_fffc686f @ fffc686f (83 bytes)

void FUN_fffc686f(char param_1)

{
  if (param_1 < '\x01') {
    if (PTR_g_ui_00025d58->memlist_row == 0) {
      FUN_fffc6a0a();
    }
    else {
      PTR_g_ui_00025d58->memlist_row = PTR_g_ui_00025d58->memlist_row - 1;
    }
  }
  else if (PTR_g_ui_00025d58->memlist_row < 3) {
    PTR_g_ui_00025d58->memlist_row = PTR_g_ui_00025d58->memlist_row + 1;
  }
  else {
    FUN_fffc68c2();
  }
  memlist_cursor_channel();
  return;
}


// ===== FUN_fffc68c2 @ fffc68c2 (328 bytes)

void FUN_fffc68c2(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  
  if (PTR_g_ui_00025d58->memlist_row != 3) {
    PTR_g_ui_00025d58->memlist_first = PTR_g_ui_00025d58->memlist_first + 1;
    return;
  }
  bVar2 = PTR_g_ui_00025d58->memlist_first + PTR_g_ui_00025d58->memlist_row;
  if (bVar2 < 0x84) {
    bVar2 = bVar2 + 1;
    if (bVar2 < 0x75) {
      PTR_g_ui_00025d58->memlist_first = PTR_g_ui_00025d58->memlist_first + 1;
      return;
    }
    uVar3 = dest_code_get();
    if ((uVar3 == 0x4380) || (uVar3 == 0x20b)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (uVar3 == 0x60e6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (uVar3 == 0x1cb9)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (g_opstate.ex030406_emergency_freq_tx == 1) {
        PTR_g_ui_00025d58->memlist_first = 0x72;
        return;
      }
    }
    else {
      if ((uVar3 == 0x315b) || (uVar3 == 0x50e2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (bVar2 < 0x84) {
          PTR_g_ui_00025d58->memlist_first = PTR_g_ui_00025d58->memlist_first + 1;
          return;
        }
        if (g_opstate.ex030406_emergency_freq_tx == 1) {
          PTR_g_ui_00025d58->memlist_first = 0x81;
          return;
        }
      }
      else {
        if ((uVar3 == 0xd950) || (uVar3 == 0xa4c5)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if ((bVar1) && (bVar2 < 0x7c)) {
          PTR_g_ui_00025d58->memlist_first = PTR_g_ui_00025d58->memlist_first + 1;
          return;
        }
      }
    }
  }
  return;
}


// ===== FUN_fffc6a0a @ fffc6a0a (186 bytes)

void FUN_fffc6a0a(void)

{
  bool bVar1;
  ushort uVar2;
  
  if (PTR_g_ui_00025d58->memlist_first < 0x84) {
    if (PTR_g_ui_00025d58->memlist_first != 0) {
      PTR_g_ui_00025d58->memlist_first = PTR_g_ui_00025d58->memlist_first - 1;
      return;
    }
  }
  else {
    uVar2 = dest_code_get();
    if ((uVar2 == 0x315b) || (uVar2 == 0x50e2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_g_ui_00025d58->memlist_first = 0x83;
      return;
    }
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
    if (bVar1) {
      PTR_g_ui_00025d58->memlist_first = 0x74;
      return;
    }
  }
  return;
}


// ===== FUN_fffc6ac4 @ fffc6ac4 (112 bytes)

void FUN_fffc6ac4(char param_1)

{
  vfo_rec *pvVar1;
  byte bStack_9;
  
  popup_duration_get(0x55);
  popup_open_timed();
  pvVar1 = memch + PTR_g_ui_00025d58->f_0x43a_u8;
  bStack_9 = pvVar1->mode & 0xf;
  if (param_1 < '\x01') {
    if (bStack_9 != 0) {
      bStack_9 = bStack_9 - 1;
    }
  }
  else if (bStack_9 < 0xe) {
    bStack_9 = bStack_9 + 1;
  }
  pvVar1->mode = pvVar1->mode & 0xf0 | bStack_9;
  eeprom_save_memch(PTR_g_ui_00025d58->f_0x43a_u8);
  return;
}


// ===== FUN_fffc6b34 @ fffc6b34 (82 bytes)

void FUN_fffc6b34(char param_1)

{
  byte *pbVar1;
  
  popup_duration_get(0x56);
  popup_open_timed();
  pbVar1 = &memch[PTR_g_ui_00025d58->f_0x43a_u8].flags1;
  if (param_1 < '\x01') {
    *pbVar1 = *pbVar1 & 0x7f;
  }
  else {
    *pbVar1 = *pbVar1 | 0x80;
  }
  eeprom_save_memch(PTR_g_ui_00025d58->f_0x43a_u8);
  return;
}


// ===== FUN_fffc6b86 @ fffc6b86 (82 bytes)

void FUN_fffc6b86(char param_1)

{
  byte *pbVar1;
  
  popup_duration_get(0x57);
  popup_open_timed();
  pbVar1 = &memch[PTR_g_ui_00025d58->f_0x43a_u8].flags5;
  if (param_1 < '\x01') {
    *pbVar1 = *pbVar1 & 0x7f;
  }
  else {
    *pbVar1 = *pbVar1 | 0x80;
  }
  eeprom_save_memch(PTR_g_ui_00025d58->f_0x43a_u8);
  return;
}


// ===== FUN_fffc6bd8 @ fffc6bd8 (72 bytes)

void FUN_fffc6bd8(char param_1)

{
  if (param_1 < '\x01') {
    if (PTR_g_ui_00025d58->memlist_group != 0) {
      PTR_g_ui_00025d58->memlist_group = PTR_g_ui_00025d58->memlist_group - 1;
      return;
    }
  }
  else if (PTR_g_ui_00025d58->memlist_group < 5) {
    PTR_g_ui_00025d58->memlist_group = PTR_g_ui_00025d58->memlist_group + 1;
    return;
  }
  return;
}


// ===== func_knob_turn @ fffc6c20 (132 bytes)

/* (step): FUNC knob rotation -> FUN_fffc6f11(0x9DC9, step) unless a +0x1C1 pop-up owns the knob */

void func_knob_turn(char param_1)

{
  if (PTR_g_ui_00025d58->dl_req_popup_b != 1) {
    FUN_fffc6f11(g_opstate.func_knob,(int)param_1);
    return;
  }
  if (PTR_g_ui_00025d58->popup_code < 0x1e) {
    FUN_fffc6ca4((int)param_1);
    return;
  }
  if (PTR_g_ui_00025d58->f_0x41c_u8 == 1) {
    FUN_fffc6f11(g_opstate.func_knob,(int)param_1);
    return;
  }
  if (PTR_g_ui_00025d58->popup_code < 0x1e) {
    return;
  }
  FUN_fffc6ddd(PTR_g_ui_00025d58->popup_code,(int)param_1);
  return;
}


// ===== FUN_fffc6ca4 @ fffc6ca4 (51 bytes)

void FUN_fffc6ca4(char param_1)

{
  byte bVar1;
  
  bVar1 = PTR_g_ui_00025d58->popup_code;
  if (bVar1 == 0xc) {
    FUN_fffc6d8c((int)param_1);
    return;
  }
  if (bVar1 == 0xb) {
    FUN_fffc6d28((int)param_1);
    return;
  }
  if (bVar1 != 5) {
    return;
  }
  FUN_fffc6cd7((int)param_1);
  return;
}


// ===== FUN_fffc6cd7 @ fffc6cd7 (81 bytes)

void FUN_fffc6cd7(char param_1)

{
  short local_4;
  
  local_4 = (ushort)PTR_g_ui_00025d58->band_cur + (short)param_1;
  if (param_1 < '\x01') {
    if ((param_1 < '\0') && (local_4 < 0)) {
      local_4 = 0;
    }
  }
  else if (0xf < local_4) {
    local_4 = 0xf;
  }
  PTR_g_ui_00025d58->band_cur = (byte)local_4;
  popup_duration_get(5);
  popup_open_timed();
  return;
}


// ===== FUN_fffc6d28 @ fffc6d28 (100 bytes)

void FUN_fffc6d28(char param_1)

{
  short sVar1;
  byte local_4;
  
  sVar1 = (ushort)PTR_g_ui_00025d58->band_cur + (short)param_1;
  local_4 = (byte)sVar1;
  if (param_1 < '\x01') {
    if (param_1 < '\0') {
      if (sVar1 < 0) {
        PTR_g_ui_00025d58->band_cur = 0;
      }
      else {
        PTR_g_ui_00025d58->band_cur = local_4;
      }
    }
  }
  else if (sVar1 < 0xc) {
    PTR_g_ui_00025d58->band_cur = local_4;
  }
  else {
    PTR_g_ui_00025d58->band_cur = 0xb;
  }
  popup_duration_get(0xb);
  popup_open_timed();
  return;
}


// ===== FUN_fffc6d8c @ fffc6d8c (81 bytes)

void FUN_fffc6d8c(char param_1)

{
  short local_4;
  
  local_4 = (ushort)PTR_g_ui_00025d58->band_cur + (short)param_1;
  if (param_1 < '\x01') {
    if ((param_1 < '\0') && (local_4 < 0)) {
      local_4 = 0;
    }
  }
  else if (0xb < local_4) {
    local_4 = 0xb;
  }
  PTR_g_ui_00025d58->band_cur = (byte)local_4;
  popup_duration_get(0xc);
  popup_open_timed();
  return;
}


// ===== FUN_fffc6ddd @ fffc6ddd (308 bytes)

void FUN_fffc6ddd(char param_1,char param_2)

{
  if (param_1 == 'X') {
    FUN_fffc7c15((int)param_2);
    return;
  }
  if (param_1 == '\x1f') {
    FUN_fffc706b((int)param_2);
    return;
  }
  if (param_1 == '\"') {
    FUN_fffc70f3((int)param_2);
    return;
  }
  if (param_1 == '#') {
    FUN_fffc715d((int)param_2);
    return;
  }
  if (param_1 == '$') {
    FUN_fffc71c7((int)param_2);
    return;
  }
  if (param_1 == '%') {
    FUN_fffc7506((int)param_2);
    return;
  }
  if (param_1 == '&') {
    FUN_fffc754b((int)param_2);
    return;
  }
  if (param_1 == '\'') {
    FUN_fffc75d4((int)param_2);
    return;
  }
  if (param_1 == '(') {
    FUN_fffc7631((int)param_2);
    return;
  }
  if (param_1 == ')') {
    FUN_fffc768c((int)param_2);
    return;
  }
  if (param_1 == '*') {
    FUN_fffc76e9((int)param_2);
    return;
  }
  if (param_1 == '+') {
    FUN_fffc7764((int)param_2);
    return;
  }
  if (param_1 == ',') {
    FUN_fffc77df(param_2);
    return;
  }
  if (param_1 == '-') {
    FUN_fffc7923((int)param_2);
    return;
  }
  if (param_1 == '/') {
    FUN_fffc79b8((int)param_2);
    return;
  }
  if (param_1 == '0') {
    FUN_fffc7aa7((int)param_2);
    return;
  }
  if (param_1 == '1') {
    FUN_fffc7b02((int)param_2);
    return;
  }
  if (param_1 == '2') {
    FUN_fffc7b5f((int)param_2);
    return;
  }
  if (param_1 == '3') {
    FUN_fffc7bbc((int)param_2);
    return;
  }
  if (param_1 == '8') {
    FUN_fffc7cfd((int)param_2);
    return;
  }
  if (param_1 == '9') {
    FUN_fffc7d41((int)param_2);
    return;
  }
  if (param_1 == 'F') {
    FUN_fffc7975((int)param_2);
    return;
  }
  if (param_1 != '\x1e') {
    return;
  }
  FUN_fffc7016((int)param_2);
  return;
}


// ===== FUN_fffc6f11 @ fffc6f11 (237 bytes)

void FUN_fffc6f11(char param_1,char param_2)

{
  PTR_g_ui_00025d58->f_0x41c_u8 = 0;
  if (param_1 == ':') {
    FUN_fffc7bfd((int)param_2);
    return;
  }
  if (param_1 == '\x01') {
    FUN_fffc7053((int)param_2);
    return;
  }
  if (param_1 == '\x03') {
    FUN_fffc70af();
    return;
  }
  if (param_1 == '\x04') {
    FUN_fffc70db((int)param_2);
    return;
  }
  if (param_1 == '\x05') {
    FUN_fffc7145((int)param_2);
    return;
  }
  if (param_1 == '\x06') {
    FUN_fffc71af((int)param_2);
    return;
  }
  if (param_1 == '\a') {
    FUN_fffc74ee((int)param_2);
    return;
  }
  if (param_1 == '\t') {
    FUN_fffc75bc((int)param_2);
    return;
  }
  if (param_1 == '\n') {
    FUN_fffc7619((int)param_2);
    return;
  }
  if (param_1 == '\v') {
    FUN_fffc7674((int)param_2);
    return;
  }
  if (param_1 == '\f') {
    FUN_fffc76d1((int)param_2);
    return;
  }
  if (param_1 == '\r') {
    FUN_fffc774c((int)param_2);
    return;
  }
  if (param_1 == '\x0e') {
    FUN_fffc77c7((int)param_2);
    return;
  }
  if (param_1 == '\x0f') {
    FUN_fffc790b((int)param_2);
    return;
  }
  if (param_1 == '\x12') {
    FUN_fffc7a8f((int)param_2);
    return;
  }
  if (param_1 == '\x13') {
    FUN_fffc7aea((int)param_2);
    return;
  }
  if (param_1 == '\x14') {
    FUN_fffc7b47((int)param_2);
    return;
  }
  if (param_1 == '\x15') {
    FUN_fffc7ba4((int)param_2);
    return;
  }
  if (param_1 != '\0') {
    return;
  }
  FUN_fffc6ffe((int)param_2);
  return;
}


// ===== FUN_fffc6ffe @ fffc6ffe (24 bytes)

void FUN_fffc6ffe(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x1e;
  FUN_fffc7016((int)param_1);
  return;
}


// ===== FUN_fffc7016 @ fffc7016 (61 bytes)

void FUN_fffc7016(char param_1)

{
  byte *pbVar1;
  undefined2 uStack_4;
  
  popup_duration_get(0x1e);
  popup_open_timed();
  pbVar1 = (byte *)FUN_fff9c6ab();
  uStack_4 = (ushort)*pbVar1 + (short)param_1;
  if (uStack_4 < 0x79) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 0x78;
  }
  *pbVar1 = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7053 @ fffc7053 (24 bytes)

void FUN_fffc7053(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x1f;
  FUN_fffc706b((int)param_1);
  return;
}


// ===== FUN_fffc706b @ fffc706b (68 bytes)

void FUN_fffc706b(char param_1)

{
  undefined2 uStack_4;
  
  popup_duration_get(0x1f);
  popup_open_timed();
  uStack_4 = (ushort)g_opstate.ss01_peak + (short)param_1;
  if (uStack_4 < 5) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 4;
  }
  g_opstate.ss01_peak = (byte)uStack_4;
  return;
}


// ===== FUN_fffc70af @ fffc70af (44 bytes)

void FUN_fffc70af(void)

{
  popup_duration_get(0xb);
  popup_open_timed();
  PTR_g_ui_00025d58->popup_code = 0xb;
  PTR_g_ui_00025d58->band_cur = g_opstate.ss03_value;
  return;
}


// ===== FUN_fffc70db @ fffc70db (24 bytes)

void FUN_fffc70db(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x22;
  FUN_fffc70f3((int)param_1);
  return;
}


// ===== FUN_fffc70f3 @ fffc70f3 (82 bytes)

void FUN_fffc70f3(char param_1)

{
  short sStack_4;
  
  popup_duration_get(0x22);
  popup_open_timed();
  sStack_4 = (ushort)g_opstate.tft_contrast + (short)param_1;
  if (sStack_4 < 0x15) {
    if (sStack_4 < 0) {
      sStack_4 = 0;
    }
  }
  else {
    sStack_4 = 0x14;
  }
  g_opstate.tft_contrast = (byte)sStack_4;
  PTR_g_ui_00025d58->dl_req_24 = 1;
  return;
}


// ===== FUN_fffc7145 @ fffc7145 (24 bytes)

void FUN_fffc7145(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x23;
  FUN_fffc715d((int)param_1);
  return;
}


// ===== FUN_fffc715d @ fffc715d (82 bytes)

void FUN_fffc715d(char param_1)

{
  short sStack_4;
  
  popup_duration_get(0x23);
  popup_open_timed();
  sStack_4 = (ushort)g_opstate.tft_brightness + (short)param_1;
  if (sStack_4 < 0x15) {
    if (sStack_4 < 0) {
      sStack_4 = 0;
    }
  }
  else {
    sStack_4 = 0x14;
  }
  g_opstate.tft_brightness = (byte)sStack_4;
  PTR_g_ui_00025d58->dl_req_24 = 1;
  return;
}


// ===== FUN_fffc71af @ fffc71af (24 bytes)

void FUN_fffc71af(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x24;
  FUN_fffc71c7((int)param_1);
  return;
}


// ===== FUN_fffc71c7 @ fffc71c7 (213 bytes)

void FUN_fffc71c7(char param_1)

{
  bool bVar1;
  byte bVar2;
  
  popup_duration_get(0x24);
  popup_open_timed();
  if ((g_opstate.ex030114_mem_group == 0) || (PTR_g_ui_00025d58->transmitting == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_g_ui_00025d58->tune_cycle != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_g_ui_00025d58->f_0x46b_u8 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_g_ui_00025d58->f_0x40d_u8 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    bVar1 = g_opstate.active_vfo != 0;
    bVar2 = vfo_is_memory(bVar1);
    if (bVar2 != 0) {
      if (param_1 < '\x01') {
        if (param_1 < '\0') {
          FUN_fffc73df(bVar1);
        }
      }
      else {
        FUN_fffc729c(bVar1);
      }
      bVar2 = memch_current(bVar1);
      eeprom_save_memch(bVar2);
      return;
    }
  }
  return;
}


// ===== FUN_fffc729c @ fffc729c (246 bytes)

void FUN_fffc729c(byte param_1)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  byte *pbStack_c;
  byte bStack_6;
  char cStack_5;
  byte bStack_4;
  byte bStack_3;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  bStack_2 = memch_current(param_1);
  bStack_3 = FUN_fff9bfe1(bStack_2);
  while (bStack_3 = bStack_3 + 1, bStack_3 < 7) {
    if (bStack_3 == 6) {
      bStack_4 = 99;
      cStack_5 = '\x12';
    }
    else {
      bStack_4 = 0;
      for (bStack_6 = 0; (int)(uint)bStack_6 < (int)(bStack_3 - 1); bStack_6 = bStack_6 + 1) {
        cVar1 = FUN_fff9cb6b();
        bStack_4 = cVar1 + bStack_4;
      }
      cStack_5 = FUN_fff9cb6b();
    }
    do {
      bVar2 = memch_valid(bStack_4,&pbStack_c);
      if (bVar2) {
        FUN_fffc73bf(bStack_4,bStack_2,local_1);
        return;
      }
      bStack_4 = bStack_4 + 1;
      cStack_5 = cStack_5 + -1;
    } while (cStack_5 != '\0');
    cStack_5 = 0;
  }
  if (bStack_3 == 7) {
    uVar3 = dest_code_get();
    if ((((uVar3 == 0x315b) || (uVar3 == 0x50e2)) || (uVar3 == 0xa4c5)) || (uVar3 == 0xd950)) {
      bStack_4 = FUN_fffc7392();
      FUN_fffc73bf(bStack_4,bStack_2,local_1);
      return;
    }
    if (g_opstate.ex030406_emergency_freq_tx == 1) {
      bStack_3 = 8;
    }
  }
  if ((bStack_3 == 8) && (bStack_4 = 0x84, g_opstate.ex030406_emergency_freq_tx == 1)) {
    FUN_fffc73bf(0x84,bStack_2,local_1);
    return;
  }
  bStack_4 = 0;
  FUN_fffc73bf(0,bStack_2,local_1);
  return;
}


// ===== FUN_fffc7392 @ fffc7392 (45 bytes)

char FUN_fffc7392(void)

{
  byte bVar1;
  byte local_2;
  
  local_2 = 0;
  while ((local_2 < 0xf && (bVar1 = memch_dest_blocked(local_2 + 0x75), bVar1 != 0))) {
    local_2 = local_2 + 1;
  }
  return local_2 + 0x75;
}


// ===== FUN_fffc73bf @ fffc73bf (32 bytes)

void FUN_fffc73bf(char param_1,char param_2,undefined1 param_3)

{
  if (param_1 == param_2) {
    return;
  }
  memch_current_set(param_3,param_1);
  FUN_fffc568a(param_3);
  return;
}


// ===== FUN_fffc73df @ fffc73df (271 bytes)

void FUN_fffc73df(byte param_1)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  byte *pbStack_c;
  byte bStack_6;
  char cStack_5;
  byte bStack_4;
  byte bStack_3;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  bStack_2 = memch_current(param_1);
  bStack_3 = FUN_fff9bfe1(bStack_2);
  while( true ) {
    while( true ) {
      bStack_3 = bStack_3 - 1;
      if ((((bStack_3 == 7) && (uVar3 = dest_code_get(), uVar3 != 0x315b)) && (uVar3 != 0x50e2)) &&
         ((uVar3 != 0xa4c5 && (uVar3 != 0xd950)))) {
        bStack_3 = 6;
      }
      if (bStack_3 == 0) break;
      if (bStack_3 == 7) {
        bStack_4 = FUN_fffc7392();
        FUN_fffc73bf(bStack_4,bStack_2,local_1);
        return;
      }
      if (bStack_3 == 6) {
        bStack_4 = 99;
        cStack_5 = '\x12';
      }
      else {
        bStack_4 = 0;
        for (bStack_6 = 0; (int)(uint)bStack_6 < (int)(bStack_3 - 1); bStack_6 = bStack_6 + 1) {
          cVar1 = FUN_fff9cb6b();
          bStack_4 = cVar1 + bStack_4;
        }
        cStack_5 = FUN_fff9cb6b();
      }
      do {
        bVar2 = memch_valid(bStack_4,&pbStack_c);
        if (bVar2) {
          FUN_fffc73bf(bStack_4,bStack_2,local_1);
          return;
        }
        bStack_4 = bStack_4 + 1;
        cStack_5 = cStack_5 + -1;
      } while (cStack_5 != '\0');
      cStack_5 = 0;
    }
    if (g_opstate.ex030406_emergency_freq_tx == 1) {
      bStack_4 = 0x84;
      FUN_fffc73bf(0x84,bStack_2,local_1);
      return;
    }
    uVar3 = dest_code_get();
    if (((uVar3 == 0x315b) || (uVar3 == 0x50e2)) || ((uVar3 == 0xa4c5 || (uVar3 == 0xd950)))) break;
    bStack_3 = 7;
  }
  bStack_4 = FUN_fffc7392();
  FUN_fffc73bf(bStack_4,bStack_2,local_1);
  return;
}


// ===== FUN_fffc74ee @ fffc74ee (24 bytes)

void FUN_fffc74ee(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x25;
  FUN_fffc7506((int)param_1);
  return;
}


// ===== FUN_fffc7506 @ fffc7506 (69 bytes)

void FUN_fffc7506(char param_1)

{
  byte *pbVar1;
  short sStack_4;
  
  popup_duration_get(0x25);
  popup_open_timed();
  pbVar1 = (byte *)FUN_fff99877();
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
    return;
  }
  return;
}


// ===== FUN_fffc754b @ fffc754b (113 bytes)

void FUN_fffc754b(char param_1)

{
  bool bVar1;
  
  bVar1 = false;
  popup_duration_get(0x26);
  popup_open_timed();
  if (param_1 < '\x01') {
    if ((param_1 < '\0') && (g_opstate.proc_on == 1)) {
      g_opstate.proc_on = 0;
      bVar1 = true;
    }
  }
  else if (g_opstate.proc_on == 0) {
    g_opstate.proc_on = 1;
    bVar1 = true;
  }
  if (bVar1) {
    PTR_g_ui_00025d58->vfo_refresh_req = 1;
    return;
  }
  return;
}


// ===== FUN_fffc75bc @ fffc75bc (24 bytes)

void FUN_fffc75bc(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x27;
  FUN_fffc75d4((int)param_1);
  return;
}


// ===== FUN_fffc75d4 @ fffc75d4 (69 bytes)

void FUN_fffc75d4(char param_1)

{
  undefined2 uStack_4;
  
  popup_duration_get(0x27);
  popup_open_timed();
  uStack_4 = (ushort)g_opstate.proc_level + (short)param_1;
  if (uStack_4 < 0x65) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 100;
  }
  g_opstate.proc_level = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7619 @ fffc7619 (24 bytes)

void FUN_fffc7619(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x28;
  FUN_fffc7631((int)param_1);
  return;
}


// ===== FUN_fffc7631 @ fffc7631 (67 bytes)

void FUN_fffc7631(char param_1)

{
  undefined2 uStack_4;
  
  popup_duration_get(0x28);
  popup_open_timed();
  uStack_4 = (ushort)g_opstate.amc_level + (short)param_1;
  if (uStack_4 < 0x65) {
    if (uStack_4 < 1) {
      uStack_4 = 1;
    }
  }
  else {
    uStack_4 = 100;
  }
  g_opstate.amc_level = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7674 @ fffc7674 (24 bytes)

void FUN_fffc7674(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x29;
  FUN_fffc768c((int)param_1);
  return;
}


// ===== FUN_fffc768c @ fffc768c (69 bytes)

void FUN_fffc768c(char param_1)

{
  undefined2 uStack_4;
  
  popup_duration_get(0x29);
  popup_open_timed();
  uStack_4 = (ushort)g_opstate.vox_gain + (short)param_1;
  if (uStack_4 < 0x65) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 100;
  }
  g_opstate.vox_gain = (byte)uStack_4;
  return;
}


// ===== FUN_fffc76d1 @ fffc76d1 (24 bytes)

void FUN_fffc76d1(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x2a;
  FUN_fffc76e9((int)param_1);
  return;
}


// ===== FUN_fffc76e9 @ fffc76e9 (99 bytes)

void FUN_fffc76e9(char param_1)

{
  short sStack_a;
  byte *pbStack_8;
  
  popup_duration_get(0x2a);
  popup_open_timed();
  if (g_opstate.ex030405_vox_select == 0) {
    pbStack_8 = g_opstate.vox_delay;
  }
  else {
    pbStack_8 = g_opstate.vox_delay + 1;
  }
  sStack_a = (ushort)*pbStack_8 + (short)param_1;
  if (sStack_a < 0x22) {
    if (sStack_a < 0) {
      sStack_a = 0;
    }
  }
  else {
    sStack_a = 0x21;
  }
  *pbStack_8 = (byte)sStack_a;
  return;
}


// ===== FUN_fffc774c @ fffc774c (24 bytes)

void FUN_fffc774c(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x2b;
  FUN_fffc7764((int)param_1);
  return;
}

