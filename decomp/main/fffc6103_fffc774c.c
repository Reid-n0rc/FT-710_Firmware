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
  uStack_14 = dial_step_hz(param_1);
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


// ===== dial_step_hz @ fffc616e (320 bytes)

/* (side): tuning step of the VFO in Hz: 1 MHz / 1 kHz in digit-step mode, 100 kHz / .. with the
   fast-step request, else the mode's step (dial_step_mode_hz) or the AM/FM channel step
   (ch_step_hz) [fact: fffc616e] */

uint dial_step_hz(byte param_1)

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
  if (PTR_g_ui_00025d58->digit_step_on == 1) {
    if (PTR_g_ui_00025d58->digit_step_khz == 0) {
      local_c = &DAT_000f4240;
    }
    else {
      local_c = (undefined *)0x3e8;
    }
  }
  else if (PTR_g_ui_00025d58->step_fast_req == 1) {
    if (PTR_g_ui_00025d58->step_fast_100k == 1) {
      local_c = &DAT_000186a0;
    }
    else {
      local_c = &DAT_000f4240;
    }
  }
  else {
    if ((PTR_g_ui_00025d58->scan_running == 1) || (PTR_g_ui_00025d58->ch_step_mode == 1)) {
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
        local_c = (undefined *)ch_step_hz(local_d);
      }
      else {
        sVar2 = dial_step_mode_hz(local_d);
        local_c = (undefined *)(int)sVar2;
      }
    }
    else if (PTR_g_ui_00025d58->step_dial_req == 1) {
      sVar2 = dial_step_mode_hz(local_d);
      local_c = (undefined *)(int)sVar2;
    }
    else if (PTR_g_ui_00025d58->step_ch_req == 1) {
      local_c = (undefined *)ch_step_hz(local_d);
    }
    else {
      sVar2 = dial_step_mode_hz(local_d);
      local_c = (undefined *)(int)sVar2;
    }
  }
  return (uint)local_c;
}


// ===== dial_step_mode_hz @ fffc62ae (312 bytes)

/* (mode): dial step in Hz by g_opstate.fn_select (1 = fine, 2 = x10): SSB/CW 1 or EX030501 SSB/CW
   DIAL STEP 5/10/20 Hz; RTTY/PSK/DATA 1 or EX030502 5/10/20 Hz; AM 10/100/1000; FM 10/100/1000
   [fact: fffc62ae]; only caller dial_step_hz */

short dial_step_mode_hz(byte param_1)

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


// ===== ch_step_hz @ fffc63e6 (166 bytes)

/* (mode): AM / FM channel step from EX030504 AM CH STEP / EX030505 FM CH STEP via table 0xFFF88514
   [fact: fffc63e6]; only caller dial_step_hz */

uint ch_step_hz(byte param_1)

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
        playback_knob_turn((int)param_1);
        return;
      }
      FUN_fffbb963((int)param_1);
      return;
    }
    if (PTR_g_ui_00025d58->dialog_has_choice == 1) {
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


// ===== playback_knob_turn @ fffc6595 (376 bytes)

/* (steps): knob turn on the PlayList / message-memory screens: while playing steps
   g_opstate.play_volume 0..100, in the PlayList otherwise moves the file cursor (playlist_cursor_up
   / _down) [fact: fffc6595]; only caller enc2_step */

void playback_knob_turn(char param_1)

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
        playlist_cursor_up();
        return;
      }
      if ('\0' < param_1) {
        playlist_cursor_down();
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


// ===== memlist_knob_turn @ fffc6800 (111 bytes)

/* (steps): knob turn in the memory list: moves the row (memlist_row_step) or the button
   (memlist_group_step), or with a pop-up open steps MODE / SCAN / TYPE of the channel [fact:
   fffc6800]; caller FUN_fffc7eeb (enc3_step) */

void memlist_knob_turn(char param_1)

{
  byte bVar1;
  
  if (PTR_g_ui_00025d58->memlist_edit_on == 0) {
    if (PTR_g_ui_00025d58->memlist_flag == 0) {
      memlist_row_step((int)param_1);
      return;
    }
    if (PTR_g_ui_00025d58->memlist_popup55 == 0) {
      memlist_group_step((int)param_1);
      return;
    }
  }
  bVar1 = PTR_g_ui_00025d58->memlist_group;
  if (bVar1 == 3) {
    memlist_type_bit_step((int)param_1);
    return;
  }
  if (bVar1 != 2) {
    if (bVar1 == 1) {
      memlist_mode_step((int)param_1);
      return;
    }
    return;
  }
  memlist_scan_bit_step((int)param_1);
  return;
}


// ===== memlist_row_step @ fffc686f (83 bytes)

/* (dir): moves the memory-list cursor row 0..3, scrolling the page at the ends, then
   memlist_cursor_channel [fact: fffc686f] */

void memlist_row_step(char param_1)

{
  if (param_1 < '\x01') {
    if (PTR_g_ui_00025d58->memlist_row == 0) {
      memlist_page_up();
    }
    else {
      PTR_g_ui_00025d58->memlist_row = PTR_g_ui_00025d58->memlist_row - 1;
    }
  }
  else if (PTR_g_ui_00025d58->memlist_row < 3) {
    PTR_g_ui_00025d58->memlist_row = PTR_g_ui_00025d58->memlist_row + 1;
  }
  else {
    memlist_page_down();
  }
  memlist_cursor_channel();
  return;
}


// ===== memlist_page_down @ fffc68c2 (328 bytes)

/* Scrolls the memory list down one channel (memlist_first + 1) up to 0x74 or the region's special
   channels (dest 0x4380 / 0x020B) [fact: fffc68c2]; caller memlist_row_step */

void memlist_page_down(void)

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


// ===== memlist_page_up @ fffc6a0a (186 bytes)

/* Scrolls the memory list up one channel (memlist_first - 1), wrapping by region (dest 0x315B /
   0x50E2 to 0x83) [fact: fffc6a0a]; caller memlist_row_step */

void memlist_page_up(void)

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


// ===== memlist_mode_step @ fffc6ac4 (112 bytes)

/* (dir): pop-up 0x55: steps the memory channel's mode (low nibble, 0..14), eeprom_save_memch [fact:
   fffc6ac4] */

void memlist_mode_step(char param_1)

{
  vfo_rec *pvVar1;
  byte bStack_9;
  
  popup_duration_get(0x55);
  popup_open_timed();
  pvVar1 = memch + PTR_g_ui_00025d58->memlist_ch;
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
  eeprom_save_memch(PTR_g_ui_00025d58->memlist_ch);
  return;
}


// ===== memlist_scan_bit_step @ fffc6b34 (82 bytes)

/* (dir): pop-up 0x56: sets (dir > 0) or clears bit 7 of memch[memlist_ch].flags1 (SCAN/SKIP),
   eeprom_save_memch [fact: fffc6b34] */

void memlist_scan_bit_step(char param_1)

{
  byte *pbVar1;
  
  popup_duration_get(0x56);
  popup_open_timed();
  pbVar1 = &memch[PTR_g_ui_00025d58->memlist_ch].flags1;
  if (param_1 < '\x01') {
    *pbVar1 = *pbVar1 & 0x7f;
  }
  else {
    *pbVar1 = *pbVar1 | 0x80;
  }
  eeprom_save_memch(PTR_g_ui_00025d58->memlist_ch);
  return;
}


// ===== memlist_type_bit_step @ fffc6b86 (82 bytes)

/* (dir): pop-up 0x57: steps the memory TYPE bit (FREQ/NAME), eeprom_save_memch [fact: fffc6b86 and
   display gui.md] */

void memlist_type_bit_step(char param_1)

{
  byte *pbVar1;
  
  popup_duration_get(0x57);
  popup_open_timed();
  pbVar1 = &memch[PTR_g_ui_00025d58->memlist_ch].flags5;
  if (param_1 < '\x01') {
    *pbVar1 = *pbVar1 & 0x7f;
  }
  else {
    *pbVar1 = *pbVar1 | 0x80;
  }
  eeprom_save_memch(PTR_g_ui_00025d58->memlist_ch);
  return;
}


// ===== memlist_group_step @ fffc6bd8 (72 bytes)

/* (dir): moves the selected memory-list button g_ui.memlist_group 0..5 [fact: fffc6bd8] */

void memlist_group_step(char param_1)

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
    funcknob_step(g_opstate.func_knob,(int)param_1);
    return;
  }
  if (PTR_g_ui_00025d58->popup_code < 0x1e) {
    funcknob_list_popup_step((int)param_1);
    return;
  }
  if (PTR_g_ui_00025d58->f_0x41c_u8 == 1) {
    funcknob_step(g_opstate.func_knob,(int)param_1);
    return;
  }
  if (PTR_g_ui_00025d58->popup_code < 0x1e) {
    return;
  }
  funcknob_popup_step(PTR_g_ui_00025d58->popup_code,(int)param_1);
  return;
}


// ===== funcknob_list_popup_step @ fffc6ca4 (51 bytes)

/* (steps): knob turn while a list pop-up (code < 0x1E) is open: code 0xC, 0xB or 5 -> its own step
   function [fact: fffc6ca4]; caller func_knob_turn */

void funcknob_list_popup_step(char param_1)

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
  
  local_4 = (ushort)PTR_g_ui_00025d58->popup_cursor + (short)param_1;
  if (param_1 < '\x01') {
    if ((param_1 < '\0') && (local_4 < 0)) {
      local_4 = 0;
    }
  }
  else if (0xf < local_4) {
    local_4 = 0xf;
  }
  PTR_g_ui_00025d58->popup_cursor = (byte)local_4;
  popup_duration_get(5);
  popup_open_timed();
  return;
}


// ===== FUN_fffc6d28 @ fffc6d28 (100 bytes)

void FUN_fffc6d28(char param_1)

{
  short sVar1;
  byte local_4;
  
  sVar1 = (ushort)PTR_g_ui_00025d58->popup_cursor + (short)param_1;
  local_4 = (byte)sVar1;
  if (param_1 < '\x01') {
    if (param_1 < '\0') {
      if (sVar1 < 0) {
        PTR_g_ui_00025d58->popup_cursor = 0;
      }
      else {
        PTR_g_ui_00025d58->popup_cursor = local_4;
      }
    }
  }
  else if (sVar1 < 0xc) {
    PTR_g_ui_00025d58->popup_cursor = local_4;
  }
  else {
    PTR_g_ui_00025d58->popup_cursor = 0xb;
  }
  popup_duration_get(0xb);
  popup_open_timed();
  return;
}


// ===== FUN_fffc6d8c @ fffc6d8c (81 bytes)

void FUN_fffc6d8c(char param_1)

{
  short local_4;
  
  local_4 = (ushort)PTR_g_ui_00025d58->popup_cursor + (short)param_1;
  if (param_1 < '\x01') {
    if ((param_1 < '\0') && (local_4 < 0)) {
      local_4 = 0;
    }
  }
  else if (0xb < local_4) {
    local_4 = 0xb;
  }
  PTR_g_ui_00025d58->popup_cursor = (byte)local_4;
  popup_duration_get(0xc);
  popup_open_timed();
  return;
}


// ===== funcknob_popup_step @ fffc6ddd (308 bytes)

/* (popup id, steps): while a value pop-up owns the knob, steps the setting of popup id 0x1F..0x58
   (funcknob_*_step) [fact: fffc6ddd]; caller func_knob_turn */

void funcknob_popup_step(char param_1,char param_2)

{
  if (param_1 == 'X') {
    funcknob_aess_cf_step((int)param_2);
    return;
  }
  if (param_1 == '\x1f') {
    funcknob_peak_step((int)param_2);
    return;
  }
  if (param_1 == '\"') {
    funcknob_contrast_step((int)param_2);
    return;
  }
  if (param_1 == '#') {
    funcknob_dimmer_step((int)param_2);
    return;
  }
  if (param_1 == '$') {
    funcknob_mgroup_step((int)param_2);
    return;
  }
  if (param_1 == '%') {
    funcknob_mic_gain_step((int)param_2);
    return;
  }
  if (param_1 == '&') {
    funcknob_mic_eq_step((int)param_2);
    return;
  }
  if (param_1 == '\'') {
    funcknob_proc_level_step((int)param_2);
    return;
  }
  if (param_1 == '(') {
    funcknob_amc_level_step((int)param_2);
    return;
  }
  if (param_1 == ')') {
    funcknob_vox_gain_step((int)param_2);
    return;
  }
  if (param_1 == '*') {
    funcknob_vox_delay_step((int)param_2);
    return;
  }
  if (param_1 == '+') {
    funcknob_anti_vox_step((int)param_2);
    return;
  }
  if (param_1 == ',') {
    funcknob_rf_power_step(param_2);
    return;
  }
  if (param_1 == '-') {
    funcknob_moni_level_step((int)param_2);
    return;
  }
  if (param_1 == '/') {
    funcknob_bk_in_step((int)param_2);
    return;
  }
  if (param_1 == '0') {
    funcknob_cw_speed_step((int)param_2);
    return;
  }
  if (param_1 == '1') {
    funcknob_cw_pitch_step((int)param_2);
    return;
  }
  if (param_1 == '2') {
    funcknob_bk_delay_step((int)param_2);
    return;
  }
  if (param_1 == '3') {
    funcknob_aess_level_step((int)param_2);
    return;
  }
  if (param_1 == '8') {
    funcknob_nb_level_step((int)param_2);
    return;
  }
  if (param_1 == '9') {
    funcknob_dnr_level_step((int)param_2);
    return;
  }
  if (param_1 == 'F') {
    funcknob_keyer_step((int)param_2);
    return;
  }
  if (param_1 != '\x1e') {
    return;
  }
  funcknob_scope_level_step((int)param_2);
  return;
}


// ===== funcknob_step @ fffc6f11 (237 bytes)

/* (func, steps): FUNC-knob turn by the assigned function g_opstate.func_knob: 1 PEAK, 3 opens popup
   0xB, 4 CONTRAST, 5 DIMMER, 6 M-GROUP, 7 MIC GAIN, 9 PROC LEVEL, 10 AMC, 11 VOX GAIN, 12 VOX
   DELAY, 13 ANTI VOX, 14 RF POWER, 15 MONI, 0x12 CW SPEED, 0x13 PITCH, 0x14 BK-DELAY, 0x15 AESS,
   0x3A AESS-CF, else SCOPE LEVEL [fact: fffc6f11]; caller func_knob_turn */

void funcknob_step(char param_1,char param_2)

{
  PTR_g_ui_00025d58->f_0x41c_u8 = 0;
  if (param_1 == ':') {
    funcknob_aess_cf((int)param_2);
    return;
  }
  if (param_1 == '\x01') {
    funcknob_peak((int)param_2);
    return;
  }
  if (param_1 == '\x03') {
    funcknob_color_popup();
    return;
  }
  if (param_1 == '\x04') {
    funcknob_contrast((int)param_2);
    return;
  }
  if (param_1 == '\x05') {
    funcknob_dimmer((int)param_2);
    return;
  }
  if (param_1 == '\x06') {
    funcknob_mgroup((int)param_2);
    return;
  }
  if (param_1 == '\a') {
    funcknob_mic_gain((int)param_2);
    return;
  }
  if (param_1 == '\t') {
    funcknob_proc_level((int)param_2);
    return;
  }
  if (param_1 == '\n') {
    funcknob_amc_level((int)param_2);
    return;
  }
  if (param_1 == '\v') {
    funcknob_vox_gain((int)param_2);
    return;
  }
  if (param_1 == '\f') {
    funcknob_vox_delay((int)param_2);
    return;
  }
  if (param_1 == '\r') {
    funcknob_anti_vox((int)param_2);
    return;
  }
  if (param_1 == '\x0e') {
    funcknob_rf_power((int)param_2);
    return;
  }
  if (param_1 == '\x0f') {
    funcknob_moni_level((int)param_2);
    return;
  }
  if (param_1 == '\x12') {
    funcknob_cw_speed((int)param_2);
    return;
  }
  if (param_1 == '\x13') {
    funcknob_cw_pitch((int)param_2);
    return;
  }
  if (param_1 == '\x14') {
    funcknob_bk_delay((int)param_2);
    return;
  }
  if (param_1 == '\x15') {
    funcknob_aess_level((int)param_2);
    return;
  }
  if (param_1 != '\0') {
    return;
  }
  funcknob_scope_level((int)param_2);
  return;
}


// ===== funcknob_scope_level @ fffc6ffe (24 bytes)

/* FUNC-knob function for SCOPE LEVEL: sets popup_code = 0x1E and calls funcknob_scope_level_step
   [fact: fffc6ffe]; called from funcknob_step */

void funcknob_scope_level(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x1e;
  funcknob_scope_level_step((int)param_1);
  return;
}


// ===== funcknob_scope_level_step @ fffc7016 (61 bytes)

/* (steps): SCOPE LEVEL pop-up (id 0x1E): popup_duration_get(0x1E) + popup_open_timed, then steps
   and clamps the setting [fact: fffc7016]; setting per display gui.md popup-slot table (#178)
   [fact] */

void funcknob_scope_level_step(char param_1)

{
  byte *pbVar1;
  undefined2 uStack_4;
  
  popup_duration_get(0x1e);
  popup_open_timed();
  pbVar1 = (byte *)scope_level_cur_ptr();
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


// ===== funcknob_peak @ fffc7053 (24 bytes)

/* FUNC-knob function for PEAK: sets popup_code = 0x1F and calls funcknob_peak_step [fact:
   fffc7053]; called from funcknob_step */

void funcknob_peak(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x1f;
  funcknob_peak_step((int)param_1);
  return;
}


// ===== funcknob_peak_step @ fffc706b (68 bytes)

/* (steps): PEAK pop-up (id 0x1F): popup_duration_get(0x1F) + popup_open_timed, then steps and
   clamps the setting [fact: fffc706b]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_peak_step(char param_1)

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


// ===== funcknob_color_popup @ fffc70af (44 bytes)

/* FUNC-knob function 3 (COLOR, function id 3 in display-link.md "0x37"): opens pop-up 0xB
   (popup_duration_get(0xB), popup_open_timed), popup_code = 0xB, cursor = g_opstate.ss03_value
   [fact: fffc70af] */

void funcknob_color_popup(void)

{
  popup_duration_get(0xb);
  popup_open_timed();
  PTR_g_ui_00025d58->popup_code = 0xb;
  PTR_g_ui_00025d58->popup_cursor = g_opstate.ss03_value;
  return;
}


// ===== funcknob_contrast @ fffc70db (24 bytes)

/* FUNC-knob function for CONTRAST: sets popup_code = 0x22 and calls funcknob_contrast_step [fact:
   fffc70db]; called from funcknob_step */

void funcknob_contrast(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x22;
  funcknob_contrast_step((int)param_1);
  return;
}


// ===== funcknob_contrast_step @ fffc70f3 (82 bytes)

/* (steps): CONTRAST pop-up (id 0x22): popup_duration_get(0x22) + popup_open_timed, then steps and
   clamps the setting [fact: fffc70f3]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_contrast_step(char param_1)

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


// ===== funcknob_dimmer @ fffc7145 (24 bytes)

/* FUNC-knob function for DIMMER: sets popup_code = 0x23 and calls funcknob_dimmer_step [fact:
   fffc7145]; called from funcknob_step */

void funcknob_dimmer(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x23;
  funcknob_dimmer_step((int)param_1);
  return;
}


// ===== funcknob_dimmer_step @ fffc715d (82 bytes)

/* (steps): DIMMER pop-up (id 0x23): popup_duration_get(0x23) + popup_open_timed, then steps and
   clamps the setting [fact: fffc715d]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_dimmer_step(char param_1)

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


// ===== funcknob_mgroup @ fffc71af (24 bytes)

/* FUNC-knob function for M GROUP: sets popup_code = 0x24 and calls funcknob_mgroup_step [fact:
   fffc71af]; called from funcknob_step */

void funcknob_mgroup(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x24;
  funcknob_mgroup_step((int)param_1);
  return;
}


// ===== funcknob_mgroup_step @ fffc71c7 (213 bytes)

/* (steps): M GROUP pop-up (id 0x24): popup_duration_get(0x24) + popup_open_timed, then steps and
   clamps the setting [fact: fffc71c7]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_mgroup_step(char param_1)

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
  if ((bVar1) || (PTR_g_ui_00025d58->ch_step_mode == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_g_ui_00025d58->keypad_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    bVar1 = g_opstate.active_vfo != VFO_A;
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
  bStack_3 = memch_group_of(bStack_2);
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
  bStack_3 = memch_group_of(bStack_2);
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


// ===== funcknob_mic_gain @ fffc74ee (24 bytes)

/* FUNC-knob function for MIC GAIN: sets popup_code = 0x25 and calls funcknob_mic_gain_step [fact:
   fffc74ee]; called from funcknob_step */

void funcknob_mic_gain(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x25;
  funcknob_mic_gain_step((int)param_1);
  return;
}


// ===== funcknob_mic_gain_step @ fffc7506 (69 bytes)

/* (steps): MIC GAIN pop-up (id 0x25): popup_duration_get(0x25) + popup_open_timed, then steps and
   clamps the setting [fact: fffc7506]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_mic_gain_step(char param_1)

{
  byte *pbVar1;
  short sStack_4;
  
  popup_duration_get(0x25);
  popup_open_timed();
  pbVar1 = (byte *)mic_gain_ptr();
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


// ===== funcknob_mic_eq_step @ fffc754b (113 bytes)

/* (steps): MIC EQ pop-up (id 0x26): popup_duration_get(0x26) + popup_open_timed, then steps and
   clamps the setting [fact: fffc754b]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_mic_eq_step(char param_1)

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


// ===== funcknob_proc_level @ fffc75bc (24 bytes)

/* FUNC-knob function for PROC LEVEL: sets popup_code = 0x27 and calls funcknob_proc_level_step
   [fact: fffc75bc]; called from funcknob_step */

void funcknob_proc_level(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x27;
  funcknob_proc_level_step((int)param_1);
  return;
}


// ===== funcknob_proc_level_step @ fffc75d4 (69 bytes)

/* (steps): PROC LEVEL pop-up (id 0x27): popup_duration_get(0x27) + popup_open_timed, then steps and
   clamps the setting [fact: fffc75d4]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_proc_level_step(char param_1)

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


// ===== funcknob_amc_level @ fffc7619 (24 bytes)

/* FUNC-knob function for AMC LEVEL: sets popup_code = 0x28 and calls funcknob_amc_level_step [fact:
   fffc7619]; called from funcknob_step */

void funcknob_amc_level(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x28;
  funcknob_amc_level_step((int)param_1);
  return;
}


// ===== funcknob_amc_level_step @ fffc7631 (67 bytes)

/* (steps): AMC LEVEL pop-up (id 0x28): popup_duration_get(0x28) + popup_open_timed, then steps and
   clamps the setting [fact: fffc7631]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_amc_level_step(char param_1)

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


// ===== funcknob_vox_gain @ fffc7674 (24 bytes)

/* FUNC-knob function for VOX GAIN: sets popup_code = 0x29 and calls funcknob_vox_gain_step [fact:
   fffc7674]; called from funcknob_step */

void funcknob_vox_gain(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x29;
  funcknob_vox_gain_step((int)param_1);
  return;
}


// ===== funcknob_vox_gain_step @ fffc768c (69 bytes)

/* (steps): VOX GAIN pop-up (id 0x29): popup_duration_get(0x29) + popup_open_timed, then steps and
   clamps the setting [fact: fffc768c]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_vox_gain_step(char param_1)

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


// ===== funcknob_vox_delay @ fffc76d1 (24 bytes)

/* FUNC-knob function for VOX DELAY: sets popup_code = 0x2A and calls funcknob_vox_delay_step [fact:
   fffc76d1]; called from funcknob_step */

void funcknob_vox_delay(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x2a;
  funcknob_vox_delay_step((int)param_1);
  return;
}


// ===== funcknob_vox_delay_step @ fffc76e9 (99 bytes)

/* (steps): VOX DELAY pop-up (id 0x2A): popup_duration_get(0x2A) + popup_open_timed, then steps and
   clamps the setting [fact: fffc76e9]; setting per display gui.md popup-slot table (#178) [fact] */

void funcknob_vox_delay_step(char param_1)

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


// ===== funcknob_anti_vox @ fffc774c (24 bytes)

/* FUNC-knob function for ANTI VOX: sets popup_code = 0x2B and calls funcknob_anti_vox_step [fact:
   fffc774c]; called from funcknob_step */

void funcknob_anti_vox(char param_1)

{
  PTR_g_ui_00025d58->popup_code = 0x2b;
  funcknob_anti_vox_step((int)param_1);
  return;
}

