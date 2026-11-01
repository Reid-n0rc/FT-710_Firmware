// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== kbd_edit_cw_text @ fffe2811 (257 bytes)

/* Keyboard target 2 (CW TEXT) editor; calls kbd_edit_key and keyer_text_endmark [fact:
   kbd_key_dispatch target 2] */

void kbd_edit_cw_text(char param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte (*pabVar3) [50];
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puStack_c;
  
  bVar1 = PTR_g_ui_00025d6c->msg_slot_idx;
  if (DAT_0001b551 == '\x01') {
    pbVar2 = &DAT_00018823;
    pabVar3 = g_ui.msg_text + bVar1;
    for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pbVar2 = (*pabVar3)[0];
      pbVar2 = pbVar2 + 1;
      pabVar3 = (byte (*) [50])(*pabVar3 + 1);
    }
    DAT_0001b551 = '\0';
  }
                    /* the on-screen keyboard key handler [doc] */
  kbd_edit_key(g_ui.msg_text + bVar1,param_1);
  if (param_1 == -0x7c) {
    if (PTR_g_ui_00025d6c->msg_slot_idx == 0) {
      puStack_c = &DAT_000096a0;
    }
    else if (PTR_g_ui_00025d6c->msg_slot_idx == 1) {
      puStack_c = &DAT_000096d3;
    }
    else if (PTR_g_ui_00025d6c->msg_slot_idx == 2) {
      puStack_c = &DAT_00009706;
    }
    else if (PTR_g_ui_00025d6c->msg_slot_idx == 3) {
      puStack_c = &DAT_00009739;
    }
    else {
      puStack_c = &DAT_0000976c;
    }
    puVar4 = &DAT_00018823;
    for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puStack_c = *puVar4;
      puStack_c = puStack_c + 1;
      puVar4 = puVar4 + 1;
    }
    DAT_0001b551 = 1;
    return;
  }
  if (param_1 == -0x7b) {
    DAT_0001b551 = 1;
    keyer_text_endmark();
    return;
  }
  return;
}


// ===== kbd_edit_rtty_text @ fffe2912 (6 bytes)

/* Keyboard target 3 (RTTY TEXT) entry of kbd_key_dispatch: an empty function (RTS) in V01-12 [fact:
   fffe2912] */

void kbd_edit_rtty_text(void)

{
  return;
}


// ===== kbd_edit_psk_text @ fffe2918 (6 bytes)

/* Keyboard target 4 (PSK TEXT) entry of kbd_key_dispatch: an empty function (RTS) in V01-12 [fact:
   fffe2918] */

void kbd_edit_psk_text(void)

{
  return;
}


// ===== kbd_edit_file_name @ fffe291e (153 bytes)

/* Keyboard target 5 (FILE NAME) editor [fact: kbd_key_dispatch target 5] */

void kbd_edit_file_name(char param_1)

{
  byte *pbVar1;
  byte (*pabVar2) [50];
  int i;
  byte j;
  
  if (DAT_0001b552 == '\x01') {
    pabVar2 = g_ui.msg_text;
    pbVar1 = &DAT_00018855;
    for (i = 0xf; i != 0; i = i + -1) {
      *pbVar1 = (*pabVar2)[0];
      pbVar1 = pbVar1 + 1;
      pabVar2 = (byte (*) [50])(*pabVar2 + 1);
    }
    DAT_0001b552 = '\0';
  }
                    /* the on-screen keyboard key handler [doc] */
  kbd_edit_key(0x20bc6,param_1);
  if (param_1 != -0x7c) {
    if (param_1 == -0x7b) {
      DAT_0001b552 = 1;
      for (j = 0xe; (j != 0 && (g_ui.msg_text[0][j] == 0x20)); j = j - 1) {
        g_ui.msg_text[0][j] = 0;
      }
      FUN_fffd0e37();
      return;
    }
    return;
  }
  DAT_0001b552 = 1;
  FUN_fffd0c27();
  return;
}


// ===== kbd_edit_key @ fffe29b7 (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe2a1e) */
/* WARNING: Removing unreachable block (ram,0xfffe2a9a) */
/* WARNING: Removing unreachable block (ram,0xfffe2a92) */
/* WARNING: Removing unreachable block (ram,0xfffe2ada) */
/* WARNING: Removing unreachable block (ram,0xfffe2a33) */
/* WARNING: Removing unreachable block (ram,0xfffe2a48) */
/* WARNING: Removing unreachable block (ram,0xfffe2a5d) */
/* WARNING: Removing unreachable block (ram,0xfffe2a72) */
/* WARNING: Removing unreachable block (ram,0xfffe2a82) */
/* WARNING: Removing unreachable block (ram,0xfffe2ad7) */
/* WARNING: Removing unreachable block (ram,0xfffe2a07) */
/* (text, key): the on-screen keyboard key handler: 0x08 backspace, 0x81 toggles layout 0/1, 0x82
   layout 0, 0x83 layout 2, 0x84/0x85 close (cancel / ENT), 0x86/0x87 cursor left/right, else stores
   the character at the cursor [fact: fffe29b7; display-link.md frame 0x50] */

int kbd_edit_key(int param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  
  if (param_2 == '\b') {
                    /* deletes the character before the cursor [doc] */
    iVar2 = kbd_backspace(param_1);
    return iVar2;
  }
  if (param_2 == -0x79) {
                    /* Moves g_ui.kbd_cursor right while below kbd_max_cursor [doc] */
    iVar2 = kbd_cursor_right();
    if (iVar2 == 0) {
      iVar2 = 3;
      beep_request(3);
      return iVar2;
    }
  }
  else {
    if (param_2 == -0x7e) {
      iVar2 = 1;
      beep_request(1);
      PTR_g_ui_00025d6c->kbd_layout = 0;
      return iVar2;
    }
    if (param_2 == -0x7d) {
      iVar2 = 1;
      beep_request(1);
      PTR_g_ui_00025d6c->kbd_layout = 2;
      return iVar2;
    }
    if (param_2 == -0x7c) {
      iVar2 = 1;
      beep_request(1);
      PTR_g_ui_00025d6c->kbd_open = 0;
      return iVar2;
    }
    if (param_2 == -0x7b) {
      iVar2 = 1;
      beep_request(1);
      PTR_g_ui_00025d6c->kbd_open = 0;
      return iVar2;
    }
    if (param_2 == -0x7a) {
                    /* Moves g_ui.kbd_cursor left while above 0 [doc] */
      iVar2 = kbd_cursor_left();
      if (iVar2 == 0) {
        iVar2 = 3;
        beep_request(3);
        return iVar2;
      }
    }
    else if (param_2 == -0x7f) {
      iVar2 = 1;
      beep_request(1);
      if (PTR_g_ui_00025d6c->kbd_layout == 0) {
        PTR_g_ui_00025d6c->kbd_layout = 1;
        return iVar2;
      }
      if (PTR_g_ui_00025d6c->kbd_layout == 1) {
        PTR_g_ui_00025d6c->kbd_layout = 0;
        return iVar2;
      }
    }
    else {
      beep_request(1);
      *(char *)((uint)PTR_g_ui_00025d6c->kbd_cursor + param_1) = param_2;
      bVar1 = PTR_g_ui_00025d6c->kbd_cursor;
                    /* Last cursor position for the keyboard target [doc] */
      iVar2 = kbd_max_cursor();
      if ((int)(uint)bVar1 < iVar2) {
        PTR_g_ui_00025d6c->kbd_cursor = PTR_g_ui_00025d6c->kbd_cursor + 1;
        return iVar2;
      }
    }
  }
  return iVar2;
}


// ===== kbd_backspace @ fffe2add (157 bytes)

/* (text): deletes the character before the cursor (shifts the rest left, pads with a space; at the
   last position clears it), beep 3 at position 0 [fact: fffe2add] */

void kbd_backspace(int param_1)

{
  byte bVar1;
  int iVar2;
  char cStack_6;
  byte local_5;
  
  if (PTR_g_ui_00025d6c->kbd_cursor == 0) {
    beep_request(3);
    return;
  }
  local_5 = PTR_g_ui_00025d6c->kbd_cursor;
                    /* Last cursor position for the keyboard target [doc] */
  bVar1 = kbd_max_cursor();
  if ((bVar1 == PTR_g_ui_00025d6c->kbd_cursor) && (*(char *)((uint)local_5 + param_1) != ' ')) {
    *(undefined1 *)((uint)local_5 + param_1) = 0x20;
    return;
  }
  for (cStack_6 = (bVar1 + 1) - PTR_g_ui_00025d6c->kbd_cursor; cStack_6 != '\0';
      cStack_6 = cStack_6 + -1) {
    *(undefined1 *)(param_1 + (local_5 - 1)) = *(undefined1 *)((uint)local_5 + param_1);
    local_5 = local_5 + 1;
  }
  *(undefined1 *)(param_1 + (local_5 - 1)) = 0x20;
                    /* Moves g_ui.kbd_cursor left while above 0 [doc] */
  iVar2 = kbd_cursor_left();
  if (iVar2 == 0) {
    beep_request(3);
    return;
  }
  return;
}


// ===== kbd_max_cursor @ fffe2b7a (83 bytes)

/* Last cursor position for the keyboard target: 0xB (12 chars) for targets 0, 1, 6, 0x31 (50) for
   CW TEXT, 0xE (15) for the others [fact: fffe2b7a] */

undefined1 kbd_max_cursor(void)

{
  uint uVar1;
  undefined1 local_2;
  
  local_2 = 0xe;
  uVar1 = (uint)PTR_g_ui_00025d6c->kbd_target;
  if (uVar1 == 6) {
    local_2 = 0xb;
  }
  else if (uVar1 == 1) {
    local_2 = 0xb;
  }
  else if (uVar1 == 2) {
    local_2 = 0x31;
  }
  else if (1 < uVar1 - 3) {
    if (uVar1 == 5) {
      local_2 = 0xe;
    }
    else {
      if (uVar1 != 0) {
        return 0xe;
      }
      local_2 = 0xb;
    }
  }
  return local_2;
}


// ===== kbd_cursor_left @ fffe2bcd (48 bytes)

/* Moves g_ui.kbd_cursor left while above 0; returns whether it moved [fact: fffe2bcd] */

bool kbd_cursor_left(void)

{
  bool bVar1;
  
  bVar1 = PTR_g_ui_00025d6c->kbd_cursor != 0;
  if (bVar1) {
    PTR_g_ui_00025d6c->kbd_cursor = PTR_g_ui_00025d6c->kbd_cursor - 1;
  }
  return bVar1;
}


// ===== kbd_cursor_right @ fffe2bfd (54 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe2c30) */
/* Moves g_ui.kbd_cursor right while below kbd_max_cursor; returns whether it moved [fact: fffe2bfd]
    */

bool kbd_cursor_right(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = PTR_g_ui_00025d6c->kbd_cursor;
                    /* Last cursor position for the keyboard target [doc] */
  iVar3 = kbd_max_cursor();
  bVar1 = (int)(uint)bVar2 < iVar3;
  if (bVar1) {
    PTR_g_ui_00025d6c->kbd_cursor = PTR_g_ui_00025d6c->kbd_cursor + 1;
  }
  return bVar1;
}


// ===== kbd_edit_preset_name @ fffe2c33 (157 bytes)

/* Keyboard target 6 (PRESET NAME) editor; uses menu_preset_name_ptr [fact: kbd_key_dispatch target
   6] */

void kbd_edit_preset_name(char param_1)

{
  byte *menu_preset_name_ptr_ret;
  
                    /* Returns the RAM address of the open PRESET's name [doc] */
  menu_preset_name_ptr_ret = (byte *)menu_preset_name_ptr();
  if (menu_preset_name_ptr_ret != (byte *)0x0) {
    if (DAT_0001b553 == '\x01') {
      DAT_0001886c = *(undefined4 *)(menu_preset_name_ptr_ret + 8);
      DAT_00018868 = *(undefined4 *)(menu_preset_name_ptr_ret + 4);
      DAT_00018864 = *(undefined4 *)menu_preset_name_ptr_ret;
      DAT_0001b553 = '\0';
    }
                    /* the on-screen keyboard key handler [doc] */
    kbd_edit_key(PTR_g_ui_00025d6c->msg_text,param_1);
    if (param_1 == -0x7c) {
      *(undefined4 *)(menu_preset_name_ptr_ret + 8) = DAT_0001886c;
      *(undefined4 *)(menu_preset_name_ptr_ret + 4) = DAT_00018868;
      *(undefined4 *)menu_preset_name_ptr_ret = DAT_00018864;
      DAT_0001b553 = 1;
      return;
    }
    if (param_1 == -0x7b) {
      *(undefined4 *)(menu_preset_name_ptr_ret + 8) = g_ui.msg_text[0]._8_4_;
      *(undefined4 *)(menu_preset_name_ptr_ret + 4) = g_ui.msg_text[0]._4_4_;
      *(undefined4 *)menu_preset_name_ptr_ret = g_ui.msg_text[0]._0_4_;
      DAT_0001b553 = 1;
      return;
    }
  }
  return;
}


// ===== dispreq_e7_task @ fffe2cd0 (532 bytes)

/* main_loop task 11: acts on the E7 status (+0x488) of the DISPLAY's PlayList recorder/player
   (0x2080048E = 1) (#65) */

void dispreq_e7_task(void)

{
  if (PTR_g_ui_00025d70->e7_status == 1) {
    PTR_g_ui_00025d70->e7_status = 0;
    if ((PTR_g_ui_00025d70->playlist_substate == 3) && (PTR_g_ui_00025d70->playlist_row != 0)) {
      PTR_g_ui_00025d70->playlist_row = PTR_g_ui_00025d70->playlist_row - 1;
    }
    PTR_g_ui_00025d70->playlist_substate = 1;
    PTR_g_ui_00025d70->playlist_req = 1;
    return;
  }
  if (PTR_g_ui_00025d70->e7_status == 2) {
    PTR_g_ui_00025d70->e7_status = 0;
    if (PTR_g_ui_00025d70->playlist_open == 1) {
      PTR_g_ui_00025d70->playlist_playing = 0;
      if (PTR_g_ui_00025d70->playlist_cmd == 1) {
        PTR_g_ui_00025d70->playlist_cmd = 0;
        PTR_g_ui_00025d70->playlist_req = 1;
        PTR_g_ui_00025d70->playlist_substate = 1;
        return;
      }
      if (PTR_g_ui_00025d70->playlist_cmd != 0) {
        PTR_g_ui_00025d70->playlist_cmd = 0;
        PTR_g_ui_00025d70->playlist_req = 1;
        PTR_g_ui_00025d70->playlist_substate = 1;
        return;
      }
    }
  }
  else {
    if (PTR_g_ui_00025d70->e7_status == 3) {
      PTR_g_ui_00025d70->e7_status = 0;
      return;
    }
    if (PTR_g_ui_00025d70->e7_status == 4) {
      PTR_g_ui_00025d70->e7_status = 0;
      return;
    }
    if (PTR_g_ui_00025d70->e7_status == 5) {
      PTR_g_ui_00025d70->e7_status = 0;
      PTR_g_ui_00025d70->playlist_open = 0;
      PTR_g_ui_00025d70->playlist_req = 0;
      PTR_g_ui_00025d70->dvs_lm1_flag = 0;
      beep_request(3);
      if (PTR_g_ui_00025d70->audio_error == 0) {
        PTR_g_ui_00025d70->dialog_msg = 0x10;
      }
      else if (PTR_g_ui_00025d70->audio_error == 1) {
        PTR_g_ui_00025d70->dialog_msg = 0x11;
      }
      else if (PTR_g_ui_00025d70->audio_error == 2) {
        PTR_g_ui_00025d70->dialog_msg = 0x12;
      }
      else if (PTR_g_ui_00025d70->audio_error == 3) {
        PTR_g_ui_00025d70->dialog_msg = 0x13;
      }
      else if (PTR_g_ui_00025d70->audio_error == 4) {
        PTR_g_ui_00025d70->dialog_msg = 0x14;
      }
      else if (PTR_g_ui_00025d70->audio_error == 5) {
        PTR_g_ui_00025d70->dialog_msg = 0x15;
      }
      else if (PTR_g_ui_00025d70->audio_error == 6) {
        PTR_g_ui_00025d70->dialog_msg = 0x18;
      }
      else if (PTR_g_ui_00025d70->audio_error == 7) {
        PTR_g_ui_00025d70->dialog_msg = 0x19;
      }
      else {
        PTR_g_ui_00025d70->dialog_msg = 0x1a;
      }
      PTR_g_ui_00025d70->dialog_shown = 1;
      return;
    }
  }
  return;
}


// ===== func_record_toggle @ fffe2ee4 (196 bytes)

/* FUNC menu slot 22 (RECORD/STOP): stops a scan; unless DVS is busy toggles g_ui.dvs_lm1_flag
   (which dl37_slot_record shows as id 0x35 STOP) [fact: fffe2ee4] */

void func_record_toggle(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d70->scan_running == 1) {
    scan_stop();
    return;
  }
  if (PTR_g_ui_00025d70->ch_step_mode != 1) {
    if ((g_ui.dvs_state == 0) && (g_ui.dvs_busy != 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (g_ui.dvs_armed == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if (PTR_g_ui_00025d70->dvs_lm1_flag == 0) {
        PTR_g_ui_00025d70->dvs_lm1_flag = 1;
      }
      else {
        PTR_g_ui_00025d70->dvs_lm1_flag = 0;
      }
      PTR_g_ui_00025d70->dl_req_3f = 1;
      PTR_g_ui_00025d70->key_consumed = 1;
      beep_request(1);
      return;
    }
    return;
  }
  PTR_g_ui_00025d70->ch_step_mode = 0;
  PTR_g_ui_00025d70->mic_key_hold = 0;
  beep_request(6);
  return;
}


// ===== func_play_open @ fffe2fa8 (283 bytes)

/* FUNC menu slot 23 (PLAY): stops a scan; unless recording / DVS / keyer send runs, opens the
   PlayList (playlist_open = playlist_req = 1, sub-state and row 0) and closes the FUNC panel [fact:
   fffe2fa8] */

void func_play_open(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d70->scan_running == 1) {
    scan_stop();
    return;
  }
  if (PTR_g_ui_00025d70->mic_key_hold != 1) {
    beep_request(1);
    if (PTR_g_ui_00025d70->dvs_busy == 1) {
      PTR_g_ui_00025d70->dvs_busy = 0;
      return;
    }
    if (PTR_g_ui_00025d70->dvs_lm1_flag != 1) {
      if ((g_ui.msg_rec_active == 1) || (g_ui.dvs_state != 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (g_ui.ky_send_0 == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (g_ui.ky_send_1 == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        g_ui.msg_active = 0;
        PTR_g_ui_00025d70->playlist_open = 1;
        PTR_g_ui_00025d70->playlist_req = 1;
        PTR_g_ui_00025d70->playlist_substate = 0;
        PTR_g_ui_00025d70->playlist_row = 0;
        func_panel_close();
        PTR_g_ui_00025d70->key_consumed = 1;
        return;
      }
    }
    return;
  }
  PTR_g_ui_00025d70->ch_step_mode = 0;
  PTR_g_ui_00025d70->mic_key_hold = 0;
  beep_request(6);
  return;
}


// ===== FUN_fffe30c3 @ fffe30c3 (7 bytes)

void FUN_fffe30c3(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30ca @ fffe30ca (7 bytes)

void FUN_fffe30ca(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30d1 @ fffe30d1 (7 bytes)

void FUN_fffe30d1(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30d8 @ fffe30d8 (7 bytes)

void FUN_fffe30d8(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30df @ fffe30df (7 bytes)

void FUN_fffe30df(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30e6 @ fffe30e6 (7 bytes)

void FUN_fffe30e6(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30ed @ fffe30ed (7 bytes)

void FUN_fffe30ed(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30f4 @ fffe30f4 (7 bytes)

void FUN_fffe30f4(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30fb @ fffe30fb (7 bytes)

void FUN_fffe30fb(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe3102 @ fffe3102 (7 bytes)

void FUN_fffe3102(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe3109 @ fffe3109 (23 bytes)

void FUN_fffe3109(void)

{
  if (PTR_g_ui_00025d70->playlist_row == 4) {
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffe3120 @ fffe3120 (1 bytes)

void FUN_fffe3120(void)

{
  return;
}


// ===== playlist_cursor_up @ fffe3121 (202 bytes)

/* Moves the PlayList cursor up one file (playlist_row, scrolling playlist_first when the list holds
   more than 4 WAV files), requests a redraw (playlist_req, sub-state 1) [fact: fffe3121] */

void playlist_cursor_up(void)

{
  byte bVar1;
  
  bVar1 = PTR_g_ui_00025d70->playlist_row;
  if (PTR_g_ui_00025d70->wav_count < 4) {
    if (bVar1 == 0) {
      return;
    }
    if ((int)(PTR_g_ui_00025d70->wav_count - 1) < (int)(uint)(byte)(bVar1 - 1)) {
      PTR_g_ui_00025d70->playlist_row = PTR_g_ui_00025d70->wav_count - 1;
    }
    else {
      PTR_g_ui_00025d70->playlist_row = bVar1 - 1;
    }
  }
  else if (bVar1 == 0) {
    if (PTR_g_ui_00025d70->playlist_first == 0) {
      return;
    }
    PTR_g_ui_00025d70->playlist_first = PTR_g_ui_00025d70->playlist_first - 1;
  }
  else {
    PTR_g_ui_00025d70->playlist_row = bVar1 - 1;
  }
  PTR_g_ui_00025d70->playlist_req = 1;
  PTR_g_ui_00025d70->playlist_substate = 1;
  PTR_g_ui_00025d70->key_consumed = 1;
  return;
}


// ===== FUN_fffe31eb @ fffe31eb (75 bytes)

void FUN_fffe31eb(void)

{
  if (PTR_g_ui_00025d70->playlist_cmd != 0) {
    PTR_g_ui_00025d70->playlist_req = 1;
    PTR_g_ui_00025d70->playlist_substate = 2;
    PTR_g_ui_00025d70->playlist_cmd = 2;
    PTR_g_ui_00025d70->key_consumed = 1;
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffe3236 @ fffe3236 (124 bytes)

void FUN_fffe3236(void)

{
  if (PTR_g_ui_00025d70->playlist_row == 4) {
    return;
  }
  PTR_g_ui_00025d70->playlist_req = 1;
  if (PTR_g_ui_00025d70->playlist_cmd == 0) {
    PTR_g_ui_00025d70->playlist_cmd = 1;
    PTR_g_ui_00025d70->playlist_substate = 2;
    PTR_g_ui_00025d70->playlist_playing = 1;
  }
  else {
    PTR_g_ui_00025d70->playlist_cmd = 0;
    PTR_g_ui_00025d70->playlist_substate = 2;
    PTR_g_ui_00025d70->playlist_playing = 0;
  }
  PTR_g_ui_00025d70->key_consumed = 1;
  return;
}


// ===== FUN_fffe32b2 @ fffe32b2 (75 bytes)

void FUN_fffe32b2(void)

{
  if (PTR_g_ui_00025d70->playlist_cmd != 0) {
    PTR_g_ui_00025d70->playlist_req = 1;
    PTR_g_ui_00025d70->playlist_substate = 2;
    PTR_g_ui_00025d70->playlist_cmd = 3;
    PTR_g_ui_00025d70->key_consumed = 1;
    return;
  }
  beep_request(3);
  return;
}


// ===== playlist_cursor_down @ fffe32fd (211 bytes)

/* Moves the PlayList cursor down one file, scrolling while wav_count > 4, requests a redraw [fact:
   fffe32fd] */

void playlist_cursor_down(void)

{
  ushort local_4;
  byte local_1;
  
  local_1 = PTR_g_ui_00025d70->playlist_row;
  local_4 = PTR_g_ui_00025d70->playlist_first;
  if (local_1 < 3) {
    local_1 = local_1 + 1;
  }
  else {
    local_4 = local_4 + 1;
  }
  if (PTR_g_ui_00025d70->wav_count < 4) {
    local_4 = 0;
    if ((int)(PTR_g_ui_00025d70->wav_count - 1) < (int)(uint)local_1) {
      PTR_g_ui_00025d70->playlist_row = 4;
    }
    else {
      PTR_g_ui_00025d70->playlist_row = local_1;
    }
  }
  else if ((int)(PTR_g_ui_00025d70->wav_count - 4) < (int)(uint)local_4) {
    local_4 = PTR_g_ui_00025d70->wav_count - 4;
    PTR_g_ui_00025d70->playlist_row = 4;
  }
  else {
    PTR_g_ui_00025d70->playlist_row = local_1;
  }
  PTR_g_ui_00025d70->playlist_first = local_4;
  PTR_g_ui_00025d70->playlist_req = 1;
  PTR_g_ui_00025d70->playlist_substate = 1;
  PTR_g_ui_00025d70->key_consumed = 1;
  return;
}


// ===== FUN_fffe33d0 @ fffe33d0 (83 bytes)

void FUN_fffe33d0(void)

{
  if (PTR_g_ui_00025d70->playlist_cmd == 1) {
    return;
  }
  PTR_g_ui_00025d70->playlist_req = 1;
  PTR_g_ui_00025d70->playlist_substate = 1;
  PTR_g_ui_00025d70->playlist_row = 0;
  PTR_g_ui_00025d70->playlist_playing = 0;
  PTR_g_ui_00025d70->key_consumed = 1;
  return;
}


// ===== FUN_fffe3423 @ fffe3423 (83 bytes)

void FUN_fffe3423(void)

{
  if (PTR_g_ui_00025d70->playlist_cmd == 1) {
    return;
  }
  PTR_g_ui_00025d70->playlist_req = 1;
  PTR_g_ui_00025d70->playlist_substate = 1;
  PTR_g_ui_00025d70->playlist_row = 1;
  PTR_g_ui_00025d70->playlist_playing = 0;
  PTR_g_ui_00025d70->key_consumed = 1;
  return;
}


// ===== FUN_fffe3476 @ fffe3476 (83 bytes)

void FUN_fffe3476(void)

{
  if (PTR_g_ui_00025d70->playlist_cmd == 1) {
    return;
  }
  PTR_g_ui_00025d70->playlist_req = 1;
  PTR_g_ui_00025d70->playlist_substate = 1;
  PTR_g_ui_00025d70->playlist_row = 2;
  PTR_g_ui_00025d70->playlist_playing = 0;
  PTR_g_ui_00025d70->key_consumed = 1;
  return;
}


// ===== FUN_fffe34c9 @ fffe34c9 (83 bytes)

void FUN_fffe34c9(void)

{
  if (PTR_g_ui_00025d70->playlist_cmd == 1) {
    return;
  }
  PTR_g_ui_00025d70->playlist_req = 1;
  PTR_g_ui_00025d70->playlist_substate = 1;
  PTR_g_ui_00025d70->playlist_row = 3;
  PTR_g_ui_00025d70->playlist_playing = 0;
  PTR_g_ui_00025d70->key_consumed = 1;
  return;
}


// ===== FUN_fffe351c @ fffe351c (83 bytes)

void FUN_fffe351c(void)

{
  if (PTR_g_ui_00025d70->playlist_cmd == 1) {
    return;
  }
  PTR_g_ui_00025d70->playlist_req = 1;
  PTR_g_ui_00025d70->playlist_substate = 4;
  if (PTR_g_ui_00025d70->playlist_playing == 0) {
    PTR_g_ui_00025d70->playlist_playing = 1;
  }
  else {
    PTR_g_ui_00025d70->playlist_playing = 0;
  }
  PTR_g_ui_00025d70->key_consumed = 1;
  return;
}


// ===== FUN_fffe356f @ fffe356f (84 bytes)

void FUN_fffe356f(void)

{
  if ((PTR_g_ui_00025d70->playlist_cmd != 1) && (PTR_g_ui_00025d70->playlist_row != 4)) {
    PTR_g_ui_00025d70->dialog_msg = 0x17;
    PTR_g_ui_00025d70->dialog_has_choice = 1;
    PTR_g_ui_00025d70->dialog_shown = 1;
    PTR_g_ui_00025d70->key_consumed = 1;
    return;
  }
  return;
}


// ===== FUN_fffe35c3 @ fffe35c3 (75 bytes)

void FUN_fffe35c3(void)

{
  if (PTR_g_ui_00025d70->playlist_cmd != 0) {
    return;
  }
  PTR_g_ui_00025d70->playlist_open = 0;
  PTR_g_ui_00025d70->playlist_req = 0;
  PTR_g_ui_00025d70->key_consumed = 1;
  PTR_g_ui_00025d70->playlist_playing = 0;
  beep_request(1);
  return;
}


// ===== dispreq_e8_task @ fffe360e (7 bytes)

/* main_loop task 10: acts on the E8 status (+0x48C) of the DISPLAY's non-PlayList audio screens
   (voice messages) [inference] (#65) */

void dispreq_e8_task(void)

{
  dispreq_e8_result();
  FUN_fffe3615();
  return;
}


// ===== FUN_fffe3615 @ fffe3615 (341 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe3703) */
/* WARNING: Removing unreachable block (ram,0xfffe372f) */
/* WARNING: Removing unreachable block (ram,0xfffe3767) */
/* WARNING: Removing unreachable block (ram,0xfffe3764) */
/* WARNING: Removing unreachable block (ram,0xfffe375c) */
/* WARNING: Removing unreachable block (ram,0xfffe36ba) */

uint FUN_fffe3615(void)

{
  byte vfo_mode_ret;
  uint uVar1;
  uint uStack_c;
  byte g_ui_keyer_state_val;
  ui_state *p_ui_state;
  
  g_ui_keyer_state_val = g_ui.keyer_state;
  vfo_mode_ret = vfo_mode(1);
  if ((vfo_mode_ret == 3) || (vfo_mode_ret == 2)) {
    uStack_c = 0;
  }
  else {
    uStack_c = 1;
  }
  if (uStack_c != 0) {
    PTR_g_ui_00025d74->msg_active = 0;
  }
  p_ui_state = PTR_g_ui_00025d74;
  if (DAT_00018870 != g_ui_keyer_state_val) {
    DAT_00018870 = g_ui_keyer_state_val;
    uStack_c = (uint)g_ui_keyer_state_val;
    if (uStack_c == 7) {
      uVar1 = contest_number_get();
      p_ui_state->msg_timer = (ushort)uVar1;
      PTR_g_ui_00025d74->ky_send_0 = 0;
      PTR_g_ui_00025d74->ky_send_1 = 0;
      return uVar1;
    }
    if (uStack_c == 5) {
      if (PTR_g_ui_00025d74->msg_active == 1) {
        uVar1 = FUN_fffe5544(PTR_g_ui_00025d74->msg_slot);
        if (uVar1 != 0) {
          PTR_g_ui_00025d74->ky_send_1 = 1;
          return uVar1;
        }
        PTR_g_ui_00025d74->ky_send_0 = 1;
        return 0;
      }
    }
    else if (uStack_c == 1) {
      if (g_ui.ky_queued == 1) {
        g_ui.ky_queued = 0;
        uVar1 = FUN_fffe5544(PTR_g_ui_00025d74->msg_slot);
        if (uVar1 == 0) {
          PTR_g_ui_00025d74->ky_send_0 = 1;
        }
        else {
          PTR_g_ui_00025d74->ky_send_1 = 1;
        }
        g_ui.keyer_state = 5;
        return uVar1;
      }
      uStack_c = contest_number_get();
      p_ui_state->msg_timer = (ushort)uStack_c;
      PTR_g_ui_00025d74->ky_send_0 = 0;
      PTR_g_ui_00025d74->ky_send_1 = 0;
      if (PTR_g_ui_00025d74->msg_rec_active == 1) {
        PTR_g_ui_00025d74->msg_rec_active = 0;
        return uStack_c;
      }
    }
  }
  return uStack_c;
}


// ===== dispreq_e8_result @ fffe376a (527 bytes)

/* E8 code actions (+0x48C 1..5), called by dispreq_e8_task (#179) */

void dispreq_e8_result(void)

{
  if (PTR_g_ui_00025d74->e8_status == 1) {
    PTR_g_ui_00025d74->e8_status = 0;
    return;
  }
  if (PTR_g_ui_00025d74->e8_status == 2) {
    PTR_g_ui_00025d74->e8_status = 0;
    if ((PTR_g_ui_00025d74->dvs_state == 1) && (g_ui.ptt_msg_play == 1)) {
      g_ui.ptt_msg_play = 0;
    }
    PTR_g_ui_00025d74->dvs_state = 0;
    PTR_g_ui_00025d74->msg_playing = 0;
    PTR_g_ui_00025d74->msg_state_1d0 = 0;
    PTR_g_ui_00025d74->msg_slot = 0;
    return;
  }
  if (PTR_g_ui_00025d74->e8_status == 3) {
    PTR_g_ui_00025d74->e8_status = 0;
    PTR_g_ui_00025d74->msg_playing = 1;
    PTR_g_ui_00025d74->msg_state_1d0 = 0;
    return;
  }
  if (PTR_g_ui_00025d74->e8_status == 4) {
    PTR_g_ui_00025d74->e8_status = 0;
    return;
  }
  if (PTR_g_ui_00025d74->e8_status == 5) {
    PTR_g_ui_00025d74->e8_status = 0;
    FUN_fffe556a();
    PTR_g_ui_00025d74->msg_slot = 0;
    beep_request(3);
    if (g_ui.ptt_msg_play == 1) {
      g_ui.ptt_msg_play = 0;
    }
    if (PTR_g_ui_00025d74->audio_error == 0) {
      PTR_g_ui_00025d74->dialog_msg = 0x10;
      PTR_g_ui_00025d74->msgmem_open = 0;
    }
    else if (PTR_g_ui_00025d74->audio_error == 1) {
      PTR_g_ui_00025d74->dialog_msg = 0x11;
      PTR_g_ui_00025d74->msgmem_open = 0;
    }
    else if (PTR_g_ui_00025d74->audio_error == 2) {
      PTR_g_ui_00025d74->dialog_msg = 0x12;
    }
    else if (PTR_g_ui_00025d74->audio_error == 3) {
      PTR_g_ui_00025d74->dvs_state = 0;
      PTR_g_ui_00025d74->msg_playing = 0;
      PTR_g_ui_00025d74->msg_state_1d0 = 0;
      PTR_g_ui_00025d74->msg_slot = 0;
      PTR_g_ui_00025d74->dialog_msg = 0x13;
    }
    else if (PTR_g_ui_00025d74->audio_error == 4) {
      PTR_g_ui_00025d74->dialog_msg = 0x14;
    }
    else if (PTR_g_ui_00025d74->audio_error == 5) {
      PTR_g_ui_00025d74->dialog_msg = 0x15;
    }
    else if (PTR_g_ui_00025d74->audio_error == 6) {
      PTR_g_ui_00025d74->dialog_msg = 0x18;
    }
    else if (PTR_g_ui_00025d74->audio_error == 7) {
      PTR_g_ui_00025d74->dialog_msg = 0x19;
    }
    else {
      PTR_g_ui_00025d74->dialog_msg = 0x1a;
    }
    PTR_g_ui_00025d74->dialog_shown = 1;
    return;
  }
  return;
}


// ===== func_message_open @ fffe3979 (412 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe3990) */
/* WARNING: Removing unreachable block (ram,0xfffe3b12) */
/* WARNING: Removing unreachable block (ram,0xfffe3b0f) */
/* WARNING: Removing unreachable block (ram,0xfffe39bb) */
/* FUNC menu item 0x15 (case 0x15 of func_menu_select): stops a scan, refuses while DVS / keyer send
   / recording / PlayList run; otherwise opens the message-memory screen (g_ui.msgmem_open = 1,
   msgmem_type 0 voice by msg_voice_mode_ok or 1 CW with the contest number) and closes the FUNC
   panel; beep 3 when neither [fact: fffe3979] */

int func_message_open(int param_1)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int local_8;
  ui_state *p_ui_state;
  
  if (PTR_g_ui_00025d74->scan_running == 1) {
    scan_stop();
    return param_1;
  }
  if (PTR_g_ui_00025d74->ch_step_mode != 1) {
    if ((PTR_g_ui_00025d74->dvs_busy == 1) || (PTR_g_ui_00025d74->dvs_state != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (PTR_g_ui_00025d74->ky_send_0 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (PTR_g_ui_00025d74->ky_send_1 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (PTR_g_ui_00025d74->msg_rec_active == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.playlist_open == 1)) {
      local_8 = 1;
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      iVar3 = vfo_mode_is_cw();
      if ((iVar3 == 0) && (g_ui.dvs_lm1_flag == 1)) {
        local_8 = 1;
      }
      else {
        local_8 = 0;
      }
      if (local_8 == 0) {
        iVar3 = msg_voice_mode_ok();
        if (iVar3 == 1) {
          PTR_g_ui_00025d74->msgmem_type = 0;
          PTR_g_ui_00025d74->msgmem_open = 1;
          PTR_g_ui_00025d74->msg_state_1d0 = 0;
          PTR_g_ui_00025d74->msg_playing = 0;
          beep_request(1);
        }
        else {
          iVar3 = vfo_mode_is_cw();
          if (iVar3 == 1) {
            PTR_g_ui_00025d74->msgmem_type = 1;
            PTR_g_ui_00025d74->msgmem_open = 1;
            p_ui_state = PTR_g_ui_00025d74;
            uVar2 = contest_number_get();
            p_ui_state->msg_timer = uVar2;
            PTR_g_ui_00025d74->msg_state_1d0 = 0;
            PTR_g_ui_00025d74->msg_playing = 0;
            beep_request(1);
          }
          else {
            beep_request(3);
          }
        }
        iVar3 = func_panel_close();
        return iVar3;
      }
    }
    return local_8;
  }
  PTR_g_ui_00025d74->ch_step_mode = 0;
  PTR_g_ui_00025d74->mic_key_hold = 0;
  iVar3 = 6;
  beep_request(6);
  return iVar3;
}


// ===== FUN_fffe3b15 @ fffe3b15 (7 bytes)

void FUN_fffe3b15(void)

{
  msg_slot_key(1);
  return;
}


// ===== FUN_fffe3b1c @ fffe3b1c (7 bytes)

void FUN_fffe3b1c(void)

{
  msg_slot_key(2);
  return;
}


// ===== FUN_fffe3b23 @ fffe3b23 (7 bytes)

void FUN_fffe3b23(void)

{
  msg_slot_key(3);
  return;
}


// ===== FUN_fffe3b2a @ fffe3b2a (7 bytes)

void FUN_fffe3b2a(void)

{
  msg_slot_key(4);
  return;
}


// ===== FUN_fffe3b31 @ fffe3b31 (7 bytes)

void FUN_fffe3b31(void)

{
  msg_slot_key(5);
  return;
}


// ===== FUN_fffe3b38 @ fffe3b38 (7 bytes)

void FUN_fffe3b38(void)

{
                    /* stops a latched send [doc] */
  msg_cw_slot_key(1);
  return;
}


// ===== FUN_fffe3b3f @ fffe3b3f (7 bytes)

void FUN_fffe3b3f(void)

{
                    /* stops a latched send [doc] */
  msg_cw_slot_key(2);
  return;
}


// ===== FUN_fffe3b46 @ fffe3b46 (7 bytes)

void FUN_fffe3b46(void)

{
                    /* stops a latched send [doc] */
  msg_cw_slot_key(3);
  return;
}


// ===== FUN_fffe3b4d @ fffe3b4d (7 bytes)

void FUN_fffe3b4d(void)

{
                    /* stops a latched send [doc] */
  msg_cw_slot_key(4);
  return;
}

