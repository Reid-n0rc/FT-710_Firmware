// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe3b5b @ fffe3b5b (7 bytes)

void FUN_fffe3b5b(void)

{
  msg_cw_slot_key_latched(1);
  return;
}


// ===== FUN_fffe3b62 @ fffe3b62 (7 bytes)

void FUN_fffe3b62(void)

{
  msg_cw_slot_key_latched(2);
  return;
}


// ===== FUN_fffe3b69 @ fffe3b69 (7 bytes)

void FUN_fffe3b69(void)

{
  msg_cw_slot_key_latched(3);
  return;
}


// ===== FUN_fffe3b70 @ fffe3b70 (7 bytes)

void FUN_fffe3b70(void)

{
  msg_cw_slot_key_latched(4);
  return;
}


// ===== FUN_fffe3b77 @ fffe3b77 (7 bytes)

void FUN_fffe3b77(void)

{
  msg_cw_slot_key_latched(5);
  return;
}


// ===== FUN_fffe3b7e @ fffe3b7e (5 bytes)

void FUN_fffe3b7e(void)

{
  msg_type_select();
  return;
}


// ===== FUN_fffe3b83 @ fffe3b83 (46 bytes)

void FUN_fffe3b83(void)

{
  beep_request(1);
  if (PTR_g_ui_00025d74->msg_playing == 1) {
    PTR_g_ui_00025d74->msg_playing = 0;
  }
  else {
    PTR_g_ui_00025d74->msg_playing = 1;
  }
  PTR_g_ui_00025d74->msg_state_1d0 = 0;
  return;
}


// ===== FUN_fffe3bb1 @ fffe3bb1 (46 bytes)

void FUN_fffe3bb1(void)

{
  beep_request(1);
  if (PTR_g_ui_00025d74->msg_state_1d0 == 1) {
    PTR_g_ui_00025d74->msg_state_1d0 = 0;
  }
  else {
    PTR_g_ui_00025d74->msg_state_1d0 = 1;
  }
  PTR_g_ui_00025d74->msg_playing = 0;
  return;
}


// ===== FUN_fffe3bdf @ fffe3bdf (5 bytes)

void FUN_fffe3bdf(void)

{
  FUN_fffe5138();
  return;
}


// ===== FUN_fffe3be4 @ fffe3be4 (320 bytes)

void FUN_fffe3be4(void)

{
  bool bVar1;
  
  beep_request(1);
  if (PTR_g_ui_00025d74->msgmem_type == 0) {
    if ((PTR_g_ui_00025d74->dvs_state == 0) && (PTR_g_ui_00025d74->dvs_busy != 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (PTR_g_ui_00025d74->dvs_armed == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      PTR_g_ui_00025d74->msgmem_open = 0;
      return;
    }
    PTR_g_ui_00025d74->dvs_state = 0;
    PTR_g_ui_00025d74->dvs_busy = 0;
    PTR_g_ui_00025d74->dvs_armed = 0;
    PTR_g_ui_00025d74->msg_tx_wait = 0;
    if (g_ui.ptt_msg_play == 1) {
      g_ui.ptt_msg_play = 0;
      return;
    }
  }
  else if (PTR_g_ui_00025d74->msgmem_type == 1) {
    if ((PTR_g_ui_00025d74->ky_send_0 == 1) || (PTR_g_ui_00025d74->ky_send_1 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      msg_cw_stop();
      return;
    }
    if (PTR_g_ui_00025d74->msg_active == 1) {
      PTR_g_ui_00025d74->msg_active = 0;
      return;
    }
    if (PTR_g_ui_00025d74->msg_rec_active == 1) {
      PTR_g_ui_00025d74->keyer_state = 4;
      PTR_g_ui_00025d74->msg_rec_active = 0;
      return;
    }
    PTR_g_ui_00025d74->msgmem_open = 0;
    PTR_g_ui_00025d74->dvs_busy = 0;
    PTR_g_ui_00025d74->msg_rec_active = 0;
    return;
  }
  return;
}


// ===== msg_send_cancel @ fffe3d24 (262 bytes)

/* Cancels a running keyer/message send (+0x94 / +0x1CC / +0x1CD / +0x1D1), keyer state +0x2B = 7
   [fact] (cat-commands-primary.md) */

void msg_send_cancel(void)

{
  bool bVar1;
  
  if ((PTR_g_ui_00025d74->msgmem_open == 1) || (PTR_g_ui_00025d74->ky_send_0 == 1)) {
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
  if ((bVar1) || (PTR_g_ui_00025d74->msg_active == 1)) {
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
  if ((bVar1) || (PTR_g_ui_00025d74->dvs_busy == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_g_ui_00025d74->msgmem_open = 0;
    PTR_g_ui_00025d74->ky_send_0 = 0;
    PTR_g_ui_00025d74->ky_send_1 = 0;
    PTR_g_ui_00025d74->dvs_busy = 0;
    PTR_g_ui_00025d74->msg_active = 0;
    PTR_g_ui_00025d74->keyer_state = 7;
    PTR_g_ui_00025d74->msg_rec_active = 0;
    PTR_g_ui_00025d74->msgmem_open = 0;
    return;
  }
  return;
}


// ===== ladder_key_task @ fffe3e2a (699 bytes)

/* main_loop task 8: acts on ladder key code 0x1204C */

void ladder_key_task(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
  if (PTR_g_ui_00025d78->dialog_shown != 1) {
    bVar2 = remote_key_get();
    if (DAT_0001b554 == bVar2) {
      if (bVar2 == 0xfa) {
        FUN_fffe4da3();
      }
      else if (bVar2 == 0xf8) {
        FUN_fffe4b73();
      }
      else if (bVar2 == 0xf9) {
        iVar4 = ladder_key_delay();
        if (iVar4 == 1) {
          FUN_fffe4cc1();
        }
      }
      else if ((bVar2 == 0xf7) && (iVar4 = ladder_key_delay(), iVar4 == 1)) {
        FUN_fffe4a67();
      }
    }
    else {
      if (g_ui.cw_spot_on == 1) {
        g_ui.cw_spot_on = 0;
        beep_stop();
        return;
      }
      if (PTR_g_ui_00025d78->numentry_mode == 1) {
        FUN_fffe56e4();
        DAT_0001b554 = bVar2;
        return;
      }
      if ((bVar2 == 0) || (6 < bVar2)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (bVar3 = key_event_filter(bVar2 + 0x86,1), bVar3 == 0)) {
        return;
      }
      if (DAT_0001b554 == 0xfa) {
        FUN_fffe4c04();
      }
      else if (DAT_0001b554 == 1) {
        if (bVar2 == 0xf1) {
          FUN_fffe46f3();
        }
        else {
          FUN_fffe435a();
        }
      }
      else if (DAT_0001b554 == 2) {
        if (bVar2 == 0xf2) {
          FUN_fffe46f9();
        }
        else {
          FUN_fffe4360();
        }
      }
      else if (DAT_0001b554 == 3) {
        if (bVar2 == 0xf3) {
          FUN_fffe46ff();
        }
        else {
          FUN_fffe4366();
        }
      }
      else if (DAT_0001b554 == 4) {
        if (bVar2 == 0xf4) {
          FUN_fffe4705();
        }
        else {
          FUN_fffe436c();
        }
      }
      else if (DAT_0001b554 == 5) {
        if (bVar2 == 0xf5) {
          FUN_fffe470b();
        }
        else {
          FUN_fffe4372();
        }
      }
      else if (DAT_0001b554 == 6) {
        if (bVar2 == 0xf6) {
          FUN_fffe47be();
        }
        else {
          FUN_fffe46b0();
        }
      }
      else if (DAT_0001b554 == 7) {
        if (bVar2 == 0xf7) {
          FUN_fffe49fb();
        }
        else {
          FUN_fffe46d3();
        }
      }
      else if (DAT_0001b554 == 8) {
        if (bVar2 == 0xf8) {
          FUN_fffe4af8();
        }
        else {
          FUN_fffe46d4();
        }
      }
      else if (DAT_0001b554 == 9) {
        if (bVar2 == 0xf9) {
          FUN_fffe4c55();
        }
        else {
          FUN_fffe46e2();
        }
      }
      else if (DAT_0001b554 == 10) {
        if (bVar2 == 0xfa) {
          FUN_fffe4d28();
        }
        else {
          FUN_fffe46e3();
        }
      }
      else if (DAT_0001b554 == 0xb) {
        if (bVar2 == 0xfb) {
          FUN_fffe4de3();
        }
        else {
          FUN_fffe46f1();
        }
      }
      else if (DAT_0001b554 == 0xc) {
        if (bVar2 == 0xfc) {
          FUN_fffe4de4();
        }
        else {
          FUN_fffe46f2();
        }
      }
      else if (DAT_0001b554 == 0xf8) {
        FUN_fffe4bb3();
      }
      else if (DAT_0001b554 == 0) {
        switch(bVar2) {
        case 1:
          FUN_fffe41f3();
          break;
        case 2:
          FUN_fffe41f9();
          break;
        case 3:
          FUN_fffe41ff();
          break;
        case 4:
          FUN_fffe4205();
          break;
        case 5:
          FUN_fffe420b();
          break;
        case 6:
          msg_type_select();
          break;
        case 7:
          FUN_fffe4f15();
          break;
        case 8:
          FUN_fffe4fa9();
          break;
        case 9:
          FUN_fffe5000();
          break;
        case 10:
          FUN_fffe50e0();
          break;
        case 0xb:
          FUN_fffe5137();
          break;
        case 0xc:
          FUN_fffe5138();
        }
      }
      DAT_00018871 = 0;
      DAT_0001b554 = bVar2;
    }
    if ((PTR_g_ui_00025d78->msg_tx_wait == 1) && (bVar2 = swtimer_expired(0x37), bVar2 == 1)) {
      PTR_g_ui_00025d78->msg_tx_wait = 0;
      PTR_g_ui_00025d78->dvs_busy = 0;
      PTR_g_ui_00025d78->dvs_armed = 0;
      PTR_g_ui_00025d78->msg_slot = 0;
      PTR_g_ui_00025d78->keyer_state = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffe40e5 @ fffe40e5 (120 bytes)

void FUN_fffe40e5(void)

{
  uint uVar1;
  radio_mode rVar2;
  byte bVar3;
  
  bVar3 = g_opstate.active_vfo;
  rVar2 = vfo_mode(VFO_RX);
  bVar3 = vfo_is_memory(bVar3);
  if (bVar3 == 1) {
    PTR_g_ui_00025d78->mic_key_hold = 1;
    swtimer_start(0x38,0xfa);
    return;
  }
  uVar1 = (uint)rVar2;
  if ((3 < uVar1 - 4) && (uVar1 != 10 && uVar1 != 0xb)) {
    PTR_g_ui_00025d78->mic_key_hold = 1;
    swtimer_start(0x38,5);
    return;
  }
  PTR_g_ui_00025d78->mic_key_hold = 1;
  swtimer_start(0x38,0x32);
  return;
}


// ===== FUN_fffe415d @ fffe415d (61 bytes)

undefined1 FUN_fffe415d(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (PTR_g_ui_00025d78->mic_key_hold == 1) {
    bVar1 = swtimer_expired(0x38);
    if (bVar1 == 1) {
      PTR_g_ui_00025d78->mic_key_hold = 0;
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== ladder_key_delay @ fffe419a (89 bytes)

/* Remote-keypad helper: the first call starts soft timer 0x38 (200), later calls return 1 once it
   expired [fact]; keys 0xF7/0xF9 in ladder_key_task [fact] */

undefined1 ladder_key_delay(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (DAT_00018871 == '\0') {
    DAT_00018871 = '\x01';
    swtimer_start(0x38,200);
    local_2 = 0;
  }
  else if (DAT_00018871 == '\x01') {
    bVar1 = swtimer_expired(0x38);
    if (bVar1 == 1) {
      DAT_00018871 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe41f3 @ fffe41f3 (6 bytes)

void FUN_fffe41f3(void)

{
  msg_slot_key(1);
  return;
}


// ===== FUN_fffe41f9 @ fffe41f9 (6 bytes)

void FUN_fffe41f9(void)

{
  msg_slot_key(2);
  return;
}


// ===== FUN_fffe41ff @ fffe41ff (6 bytes)

void FUN_fffe41ff(void)

{
  msg_slot_key(3);
  return;
}


// ===== FUN_fffe4205 @ fffe4205 (6 bytes)

void FUN_fffe4205(void)

{
  msg_slot_key(4);
  return;
}


// ===== FUN_fffe420b @ fffe420b (6 bytes)

void FUN_fffe420b(void)

{
  msg_slot_key(5);
  return;
}


// ===== msg_slot_key @ fffe4211 (329 bytes)

/* (ch 1..5): message-memory key: in voice modes plays or stops voice message ch (+0x78 = 1, +0x79 =
   ch - 1, PTT source 0x20B2E), during a recording FUN_fffe4e6e; in CW +0x1C7 = 1 [fact] */

void msg_slot_key(byte param_1)

{
  bool bVar1;
  int iVar2;
  
  if (PTR_g_ui_00025d78->kbd_open != 1) {
    if (PTR_g_ui_00025d78->playlist_open == 1) {
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d78->dvs_busy == 1) {
      FUN_fffe4e6e(param_1);
      beep_request(1);
      return;
    }
    beep_request(1);
    iVar2 = msg_voice_mode_ok();
    if (iVar2 == 1) {
      PTR_g_ui_00025d78->msgmem_type = 0;
      if ((PTR_g_ui_00025d78->dvs_state == 0) && (PTR_g_ui_00025d78->dvs_busy == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) || (PTR_g_ui_00025d78->dvs_armed != 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (g_ui.ptt_msg_play == 1) {
          g_ui.ptt_msg_play = 0;
        }
        PTR_g_ui_00025d78->dvs_state = 0;
        PTR_g_ui_00025d78->dvs_busy = 0;
        PTR_g_ui_00025d78->dvs_armed = 0;
        PTR_g_ui_00025d78->msg_tx_wait = 0;
        return;
      }
      iVar2 = tx_breakin_on();
      if (iVar2 == 1) {
        g_ui.ptt_msg_play = 1;
      }
      PTR_g_ui_00025d78->dvs_state = 1;
      PTR_g_ui_00025d78->dvs_slot = param_1 - 1;
      PTR_g_ui_00025d78->msg_slot = param_1;
      return;
    }
    iVar2 = vfo_mode_is_cw();
    if (iVar2 == 1) {
      PTR_g_ui_00025d78->msgmem_type = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffe435a @ fffe435a (6 bytes)

void FUN_fffe435a(void)

{
  msg_cw_slot_key(1);
  return;
}


// ===== FUN_fffe4360 @ fffe4360 (6 bytes)

void FUN_fffe4360(void)

{
  msg_cw_slot_key(2);
  return;
}


// ===== FUN_fffe4366 @ fffe4366 (6 bytes)

void FUN_fffe4366(void)

{
  msg_cw_slot_key(3);
  return;
}


// ===== FUN_fffe436c @ fffe436c (6 bytes)

void FUN_fffe436c(void)

{
  msg_cw_slot_key(4);
  return;
}


// ===== FUN_fffe4372 @ fffe4372 (6 bytes)

void FUN_fffe4372(void)

{
  msg_cw_slot_key(5);
  return;
}


// ===== msg_cw_slot_key @ fffe4378 (143 bytes)

/* (ch): stops a latched send (+0x1D1) or msg_cw_send_start(ch) [fact] */

void msg_cw_slot_key(undefined1 param_1)

{
  int iVar1;
  
  if ((PTR_g_ui_00025d78->kbd_open == 1) || (PTR_g_ui_00025d78->playlist_open == 1)) {
    return;
  }
  iVar1 = msg_voice_mode_ok();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_g_ui_00025d78->msg_active != 0) {
    PTR_g_ui_00025d78->msg_active = 0;
    msg_cw_stop();
    return;
  }
  msg_cw_send_start(param_1);
  return;
}


// ===== msg_type_select @ fffe4407 (681 bytes)

/* Sets UI +0x1C7 (message type) from vfo_mode(1): CW 1, RTTY 2, PSK 3, voice modes 0 */

void msg_type_select(void)

{
  uint uVar1;
  bool bVar2;
  radio_mode rVar3;
  
  rVar3 = vfo_mode(VFO_TX);
  if (PTR_g_ui_00025d78->kbd_open == 1) {
    if ((PTR_g_ui_00025d78->kbd_target == 2) || (PTR_g_ui_00025d78->kbd_target == 3)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_g_ui_00025d78->kbd_target == 4)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      beep_request(1);
      return;
    }
  }
  else {
    if (PTR_g_ui_00025d78->playlist_open == 1) {
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d78->f_0x40d_u8 == 1) {
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d78->tx_lamp != 0) {
      if (PTR_g_ui_00025d78->dvs_state == 1) {
        PTR_g_ui_00025d78->dvs_state = 0;
        beep_request(1);
        if (g_ui.ptt_msg_play == 1) {
          g_ui.ptt_msg_play = 0;
        }
      }
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d78->msg_rec_active == 1) {
      PTR_g_ui_00025d78->keyer_state = 4;
      PTR_g_ui_00025d78->msg_rec_active = 0;
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d78->dvs_state == 2) {
      PTR_g_ui_00025d78->dvs_state = 0;
      g_ui.msg_slot = 0;
      g_ui.ptt_mic = 0;
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d78->dvs_busy != 0) {
      PTR_g_ui_00025d78->dvs_busy = 0;
      PTR_g_ui_00025d78->dvs_armed = 0;
      PTR_g_ui_00025d78->msg_playing = 0;
      PTR_g_ui_00025d78->msg_state_1d0 = 0;
      PTR_g_ui_00025d78->msg_tx_wait = 0;
      PTR_g_ui_00025d78->msg_slot = 0;
      beep_request(1);
      return;
    }
    uVar1 = (uint)rVar3;
    if (uVar1 == 0xe) {
      PTR_g_ui_00025d78->msgmem_type = 3;
      return;
    }
    if (uVar1 - 2 < 2) {
      if ((PTR_g_ui_00025d78->ky_send_0 == 1) || (PTR_g_ui_00025d78->ky_send_1 == 1)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (!bVar2) {
        if (PTR_g_ui_00025d78->msg_active != 1) {
          PTR_g_ui_00025d78->msgmem_type = 1;
          PTR_g_ui_00025d78->dvs_busy = 1;
          FUN_fffe4efc();
          beep_request(1);
          return;
        }
        msg_cw_stop();
        return;
      }
    }
    else {
      if (3 < uVar1 - 4) {
        if (uVar1 - 0xc < 2) {
          PTR_g_ui_00025d78->msgmem_type = 2;
          return;
        }
        if (1 < uVar1) {
          return;
        }
      }
      if (PTR_g_ui_00025d78->dvs_state != 1) {
        PTR_g_ui_00025d78->msgmem_type = 0;
        PTR_g_ui_00025d78->msg_slot = 0;
        PTR_g_ui_00025d78->msg_playing = 0;
        PTR_g_ui_00025d78->msg_state_1d0 = 0;
        PTR_g_ui_00025d78->dvs_busy = 1;
        FUN_fffe4efc();
        beep_request(1);
        return;
      }
      PTR_g_ui_00025d78->dvs_state = 0;
      beep_request(1);
      if (g_ui.ptt_msg_play == 1) {
        g_ui.ptt_msg_play = 0;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffe46b0 @ fffe46b0 (35 bytes)

void FUN_fffe46b0(void)

{
  PTR_g_ui_00025d78->kbd_open = 0;
  if (PTR_g_ui_00025d78->kbd_target != 5) {
    return;
  }
  FUN_fffe291e(0x84);
  return;
}


// ===== FUN_fffe46d3 @ fffe46d3 (1 bytes)

void FUN_fffe46d3(void)

{
  return;
}


// ===== FUN_fffe46d4 @ fffe46d4 (14 bytes)

void FUN_fffe46d4(void)

{
  PTR_g_ui_00025d78->f_0x46b_u8 = 0;
  return;
}


// ===== FUN_fffe46e2 @ fffe46e2 (1 bytes)

void FUN_fffe46e2(void)

{
  return;
}


// ===== FUN_fffe46e3 @ fffe46e3 (14 bytes)

void FUN_fffe46e3(void)

{
  PTR_g_ui_00025d78->f_0x46b_u8 = 0;
  return;
}


// ===== FUN_fffe46f1 @ fffe46f1 (1 bytes)

void FUN_fffe46f1(void)

{
  return;
}


// ===== FUN_fffe46f2 @ fffe46f2 (1 bytes)

void FUN_fffe46f2(void)

{
  return;
}


// ===== FUN_fffe46f3 @ fffe46f3 (6 bytes)

void FUN_fffe46f3(void)

{
  msg_cw_slot_key_latched(1);
  return;
}


// ===== FUN_fffe46f9 @ fffe46f9 (6 bytes)

void FUN_fffe46f9(void)

{
  msg_cw_slot_key_latched(2);
  return;
}


// ===== FUN_fffe46ff @ fffe46ff (6 bytes)

void FUN_fffe46ff(void)

{
  msg_cw_slot_key_latched(3);
  return;
}


// ===== FUN_fffe4705 @ fffe4705 (6 bytes)

void FUN_fffe4705(void)

{
  msg_cw_slot_key_latched(4);
  return;
}


// ===== FUN_fffe470b @ fffe470b (6 bytes)

void FUN_fffe470b(void)

{
  msg_cw_slot_key_latched(5);
  return;
}


// ===== msg_cw_slot_key_latched @ fffe4711 (173 bytes)

/* (ch): like msg_cw_slot_key but sets +0x1D1 = 1 after a start [fact]; a repeating send [inference]
    */

void msg_cw_slot_key_latched(undefined1 param_1)

{
  bool bVar1;
  int iVar2;
  
  if ((PTR_g_ui_00025d78->dvs_lm1_flag == 1) || (PTR_g_ui_00025d78->playlist_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  iVar2 = msg_voice_mode_ok();
  if (iVar2 == 1) {
    return;
  }
  if (PTR_g_ui_00025d78->msg_active == 1) {
    msg_cw_stop();
    beep_request(1);
    return;
  }
  iVar2 = msg_cw_send_start(param_1);
  if (iVar2 != 0) {
    PTR_g_ui_00025d78->msg_active = 1;
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffe47be @ fffe47be (10 bytes)

void FUN_fffe47be(void)

{
  FUN_fffe47c8();
  beep_request(1);
  return;
}


// ===== FUN_fffe47c8 @ fffe47c8 (85 bytes)

void FUN_fffe47c8(void)

{
  uint uVar1;
  
  uVar1 = (uint)PTR_g_ui_00025d78->kbd_target;
  if (uVar1 != 6) {
    if (uVar1 == 1) {
      FUN_fffe273a(0x85);
    }
    else if (uVar1 == 2) {
      FUN_fffe2811(0x85);
    }
    else if (1 < uVar1 - 3) {
      if (uVar1 == 5) {
        FUN_fffe291e(0x85);
      }
      else {
        if (uVar1 != 0) {
          return;
        }
        FUN_fffe2680(0x85);
      }
    }
  }
  PTR_g_ui_00025d78->kbd_open = 0;
  return;
}


// ===== keyer_text_endmark @ fffe481d (478 bytes)

/* Front-panel keyer text editor: length up to the first } (0x7D) or appends } after the last
   non-space char */

void keyer_text_endmark(void)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  byte bStack_a;
  byte local_9;
  byte *pbStack_8;
  char *pcStack_4;
  
  local_9 = 1;
  pcVar2 = (char *)FUN_fffe52a1();
  bVar1 = PTR_g_ui_00025d78->msg_slot_idx;
  if (bVar1 == 4) {
    pcStack_4 = &DAT_0000976c;
    pbStack_8 = &DAT_0000976b;
  }
  else if (bVar1 == 1) {
    pcStack_4 = &DAT_000096d3;
    pbStack_8 = &DAT_000096d2;
  }
  else if (bVar1 == 2) {
    pcStack_4 = &DAT_00009706;
    pbStack_8 = &DAT_00009705;
  }
  else if (bVar1 == 3) {
    pcStack_4 = &DAT_00009739;
    pbStack_8 = &DAT_00009738;
  }
  else if (bVar1 == 0) {
    pcStack_4 = &DAT_000096a0;
    pbStack_8 = &DAT_0000969f;
  }
  for (bStack_a = 0; bStack_a < 0x32; bStack_a = bStack_a + 1) {
    if (pcVar2[bStack_a] == '}') {
      local_9 = bStack_a + 1;
      break;
    }
  }
  if (bStack_a == 0x32) {
    for (bStack_a = 0x31; bStack_a != 0; bStack_a = bStack_a - 1) {
      if (0x20 < (byte)pcVar2[bStack_a]) {
        local_9 = bStack_a + 1;
        break;
      }
    }
    if (bStack_a < 0x31) {
      if (bStack_a == 0) {
        if (*pcVar2 == ' ') {
          *pcVar2 = '}';
          local_9 = 1;
        }
        else {
          pcVar2[1] = '}';
          local_9 = 2;
        }
      }
      else if (pcVar2[0x31] == ' ') {
        pcVar2[local_9] = '}';
        local_9 = local_9 + 1;
      }
    }
  }
  for (bStack_a = local_9; bStack_a < 0x32; bStack_a = bStack_a + 1) {
    pcVar2[bStack_a] = ' ';
  }
  *pbStack_8 = local_9;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcStack_4 = *pcVar2;
    pcStack_4 = pcStack_4 + 1;
    pcVar2 = pcVar2 + 1;
  }
  if (PTR_g_ui_00025d78->msg_slot_idx == 0) {
    eeprom_save_msg(1,1);
    return;
  }
  if (PTR_g_ui_00025d78->msg_slot_idx == 1) {
    eeprom_save_msg(1,2);
    return;
  }
  if (PTR_g_ui_00025d78->msg_slot_idx == 2) {
    eeprom_save_msg(1,3);
    return;
  }
  if (PTR_g_ui_00025d78->msg_slot_idx == 3) {
    eeprom_save_msg(1,4);
    return;
  }
  if (PTR_g_ui_00025d78->msg_slot_idx == 4) {
    eeprom_save_msg(1,5);
    return;
  }
  return;
}


// ===== FUN_fffe49fb @ fffe49fb (108 bytes)

void FUN_fffe49fb(void)

{
  bool bVar1;
  
  if (PTR_g_ui_00025d78->kbd_open == 0) {
    if ((PTR_g_ui_00025d78->tx_lamp == 0) && (PTR_g_ui_00025d78->f_0x40d_u8 != 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (g_ui.dl_req_40 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    beep_request(1);
    FUN_fffe52dd();
  }
  else {
    FUN_fffe4f82();
  }
  beep_request(1);
  return;
}


// ===== FUN_fffe4a67 @ fffe4a67 (145 bytes)

void FUN_fffe4a67(void)

{
  bool bVar1;
  
  if ((PTR_g_ui_00025d78->dvs_lm1_flag == 1) || (PTR_g_ui_00025d78->playlist_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (PTR_g_ui_00025d78->kbd_open != 0) {
      FUN_fffe4f82();
      return;
    }
    if ((PTR_g_ui_00025d78->tx_lamp == 0) && (PTR_g_ui_00025d78->f_0x40d_u8 != 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (g_ui.dl_req_40 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      beep_request(1);
      FUN_fffe52dd();
      return;
    }
  }
  return;
}


// ===== FUN_fffe4af8 @ fffe4af8 (123 bytes)

void FUN_fffe4af8(void)

{
  bool bVar1;
  
  if ((PTR_g_ui_00025d78->tx_lamp == 0) && (PTR_g_ui_00025d78->f_0x40d_u8 != 1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (g_ui.dl_req_40 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00018872 == '\x01') {
      vfo_step_up(g_opstate.active_vfo);
      FUN_fffe40e5();
      beep_request(1);
      return;
    }
    FUN_fffe4ff2();
    ladder_key_delay();
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffe4b73 @ fffe4b73 (64 bytes)

void FUN_fffe4b73(void)

{
  int iVar1;
  
  if (DAT_00018872 == '\x01') {
    iVar1 = FUN_fffe415d();
    if (iVar1 == 1) {
      if (PTR_g_ui_00025d78->f_0x46b_u8 == 1) {
        vfo_step_up(g_opstate.active_vfo);
      }
      FUN_fffe40e5();
      return;
    }
  }
  else {
    iVar1 = ladder_key_delay();
    if (iVar1 == 1) {
      FUN_fffe4ff2();
      return;
    }
  }
  return;
}


// ===== FUN_fffe4bb3 @ fffe4bb3 (81 bytes)

void FUN_fffe4bb3(void)

{
  byte bVar1;
  
  if ((((DAT_00018872 == '\x01') && (PTR_g_ui_00025d78->tx_lamp == 0)) &&
      (PTR_g_ui_00025d78->f_0x46b_u8 == 1)) && (bVar1 = scan_allowed(), bVar1 == 1)) {
    scan_start_up();
  }
  PTR_g_ui_00025d78->f_0x46b_u8 = 0;
  PTR_g_ui_00025d78->mic_key_hold = 0;
  return;
}


// ===== FUN_fffe4c04 @ fffe4c04 (81 bytes)

void FUN_fffe4c04(void)

{
  byte bVar1;
  
  if ((((DAT_00018872 == '\x01') && (PTR_g_ui_00025d78->tx_lamp == 0)) &&
      (PTR_g_ui_00025d78->f_0x46b_u8 == 1)) && (bVar1 = scan_allowed(), bVar1 == 1)) {
    scan_start_down();
  }
  PTR_g_ui_00025d78->f_0x46b_u8 = 0;
  PTR_g_ui_00025d78->mic_key_hold = 0;
  return;
}

