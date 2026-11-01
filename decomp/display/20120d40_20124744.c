// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== afscope_store_frame @ 20120d40 (188 bytes)

/* 600 B -> 0x208DD73C */

void afscope_store_frame(char *param_1)

{
  if (DAT_208dd994 == '\0') {
    if (*param_1 == '\x01') {
      if ((DAT_208004a0 != '\0') || (DAT_208dd995 != '\0')) goto LAB_20157258;
      memcpy(&DAT_208dd73c,param_1,600);
      DAT_208dd73c = 0xff;
      DAT_208dd73d = 0xff;
      if (((ushort)DAT_20808a84 & 0x400) != 0) {
        memcpy(&DAT_208dd73c,&DAT_20166de8,200);
        memcpy(&DAT_208dd804,&DAT_20166eb0,400);
        return;
      }
    }
  }
  else if (DAT_208dd995 != '\0') {
LAB_20157258:
    __aeabi_memset_veneer(&DAT_208dd73c,600,0xff);
    return;
  }
  return;
}


// ===== affft_wf_freeze_set @ 20120d4c (20 bytes)

/* (v): 0x208DD994 = v; affft_wf_add_row adds no row while it is set; gui_screen_update sets it
   [fact] */

void affft_wf_freeze_set(undefined1 param_1)

{
  DAT_208dd994 = param_1;
  return;
}


// ===== afscope_clear @ 20120d58 (8 bytes)

/* afscope_obj_clear(0x208DCE3C); scope_area_setup calls it [fact] */

void afscope_clear(void)

{
  afscope_obj_clear(&DAT_208dce3c);
  return;
}


// ===== affft_spectrum_columns @ 20120d60 (152 bytes)

/* (colour set, out): the 200 AF-FFT bins stretched to 391 columns through 0x208DCE3C / 0x208DCF3C;
   returns the height 0x27 (gui.md) [fact] */

undefined4 affft_spectrum_columns(int param_1,int param_2)

{
  int iVar1;
  byte local_260 [392];
  undefined1 auStack_d8 [200];
  
                    /* n/4 words dst = ~src [doc] */
  copy_inverted_words(&DAT_208dce3c,auStack_d8,&DAT_208dd73c,200);
  FUN_20134074(local_260,auStack_d8);
  iVar1 = 0;
  if (param_1 == 0) {
    do {
      *(undefined *)(param_2 + iVar1) = (&DAT_208dce3c)[local_260[iVar1]];
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x187);
  }
  else {
    do {
      *(undefined *)(param_2 + iVar1) = (&DAT_208dcf3c)[local_260[iVar1]];
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x187);
  }
  return 0x27;
}


// ===== FUN_20120d70 @ 20120d70 (20 bytes)

undefined4 FUN_20120d70(undefined4 param_1,undefined4 param_2,int param_3)

{
  int i;
  undefined1 auStack_1a0 [200];
  byte abStack_d8 [204];
  
  copy_inverted_words(&DAT_208dce3c,auStack_1a0,&DAT_208dd73c,200);
  FUN_20134084(abStack_d8,auStack_1a0);
  i = 0;
  do {
    *(undefined *)(param_3 + i) = (&DAT_208dd23c)[abStack_d8[i]];
    i = i + 1;
  } while (i < 200);
  return 0x2c;
}


// ===== affft_bins_get @ 20120d84 (92 bytes)

/* 200 AF-FFT bins of 0x208DD73C through FUN_20157214 and the table 0x208DD23C; returns the bar
   height 0x2C [fact] (#179) */

undefined4 affft_bins_get(int param_1)

{
  int i;
  byte local_d8 [204];
  
                    /* n/4 words dst = ~src [doc] */
  copy_inverted_words(&DAT_208dce3c,local_d8,&DAT_208dd73c,200);
  i = 0;
  do {
    *(undefined *)(param_1 + i) = (&DAT_208dd23c)[local_d8[i]];
    i = i + 1;
  } while (i < 200);
  return 0x2c;
}


// ===== affft_wf_add_row @ 20120d90 (168 bytes)

/* Writes one colour-mapped AF-FFT row (palette 0x208DD53C) into the next slot of the ring
   0x208DD99C unless 0x208DD994 is set (gui.md) [fact] */

void affft_wf_add_row(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int i;
  byte local_4b0 [391];
  undefined1 auStack_329 [393];
  undefined1 auStack_1a0 [200];
  undefined1 auStack_d8 [200];
  
  if (DAT_208dd994 == '\0') {
                    /* n/4 words dst = ~src [doc] */
    copy_inverted_words(&DAT_208dce3c,auStack_1a0,&DAT_208dd73c,200);
    FUN_20134074(local_4b0,auStack_1a0);
    FUN_20134074(auStack_329,auStack_d8);
                    /* returns idx and advances it with ring100_next [doc] */
    iVar3 = ring100_advance(&DAT_208f0b14);
    i = 0;
    do {
      pbVar2 = local_4b0 + i;
      iVar1 = i * 2;
      i = i + 1;
      *(undefined2 *)(&DAT_208dd99c + iVar1 + iVar3 * 0x30e) =
           *(undefined2 *)(&DAT_208dd53c + (uint)*pbVar2 * 2);
    } while (i < 0x187);
  }
  return;
}


// ===== affft_wf_row_addr @ 20120d98 (56 bytes)

/* (i): address of the i-th newest AF-FFT waterfall row in the ring 0x208DD99C (0x30E bytes per row,
   index object 0x208F0B14) [fact] */

undefined * affft_wf_row_addr(uint param_1)

{
  int iVar1;
  
  iVar1 = ring100_offset(&DAT_208f0b14,~param_1);
  return &DAT_208dd99c + iVar1 * 0x30e;
}


// ===== osc_column_pairs @ 20120da4 (192 bytes)

/* (colour set, out): the oscilloscope {max, min} pairs of the 400-byte half 0x208DD804 stretched to
   391 columns and mapped through 0x208DD03C or 0x208DD13C (gui.md osc_draw) [fact] */

void osc_column_pairs(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  byte local_320 [784];
  
  FUN_20134094(local_320,&DAT_208dd804);
  iVar3 = 0;
  if (param_1 != 0) {
    do {
      bVar2 = local_320[iVar3 * 2 + 1];
      *(undefined *)(param_2 + iVar3 * 2) = (&DAT_208dd13c)[local_320[iVar3 * 2]];
      iVar1 = iVar3 * 2;
      iVar3 = iVar3 + 1;
      *(undefined *)(param_2 + iVar1 + 1) = (&DAT_208dd13c)[bVar2];
    } while (iVar3 < 0x187);
    return;
  }
  do {
    bVar2 = local_320[iVar3 * 2 + 1];
    *(undefined *)(param_2 + iVar3 * 2) = (&DAT_208dd03c)[local_320[iVar3 * 2]];
    iVar1 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined *)(param_2 + iVar1 + 1) = (&DAT_208dd03c)[bVar2];
  } while (iVar3 < 0x187);
  return;
}


// ===== FUN_20120db4 @ 20120db4 (12 bytes)

void FUN_20120db4(undefined4 param_1)

{
  FUN_201572f8(&DAT_208dce3c,param_1);
  return;
}


// ===== FUN_20120dc0 @ 20120dc0 (8 bytes)

void FUN_20120dc0(void)

{
  FUN_201575f8(&DAT_208dce3c);
  return;
}


// ===== afscope_buf_ptr @ 20120dc8 (12 bytes)

uint afscope_buf_ptr(void)

{
  return DAT_208dd998;
}


// ===== FUN_20120dd4 @ 20120dd4 (8 bytes)

void FUN_20120dd4(void)

{
  FUN_20157604(&DAT_208dce3c);
  return;
}


// ===== usbkbd_screen_settings @ 20120de4 (184 bytes)

/* Every GUI frame (gui_input_poll): on the keyboard screen 0x50 with a 0x24 settings frame, sets
   the layout from settings byte 1 (usbkbd_set_layout) and CapsLock by the text mode of payload byte
   0 (table 0x20801D44, usbkbd_capslock_for_mode); on other screens usbkbd_reset [fact] */

void usbkbd_screen_settings(void)

{
  byte bVar1;
  byte mainlink_get_settings24_ret;
  uint uVar2;
  undefined1 uStack_18;
  byte local_17;
  
  if (gui_frame.cmd == 0x50) {
    if (g_ml.got24 != 0) {
      uVar2 = 0;
      bVar1 = (&DAT_20801d44)
              [(gui_frame.payload[0] & 0xf) % 3 + ((uint)(gui_frame.payload[0] >> 4) % 5) * 3];
      mainlink_get_settings24_ret = mainlink_get_settings24((uint)&uStack_18);
      if (mainlink_get_settings24_ret != 0) {
        uVar2 = local_17 & 0xf;
      }
      usbkbd_set_layout(uVar2);
      usbkbd_capslock_for_mode((uint)bVar1);
      return;
    }
  }
  else {
    usbkbd_reset();
  }
  return;
}


// ===== mainlink_send_touch_key @ 20120e9c (288 bytes)

/* E0 touch soft-key press/release (code 0x1016 = special) */

void mainlink_send_touch_key(uint param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  short sVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  sVar2 = 0;
  local_c = 0;
  if (DAT_20800468 != param_1) {
    if (param_1 == 0) {
      DAT_20800478 = DAT_20800478 + 1;
      local_10._0_2_ = 0xe0;
    }
    else {
      DAT_20800474 = DAT_20800474 + 1;
      local_10._0_2_ = 0x1e0;
    }
    if (param_2 == 0x1016) {
      if (param_1 == 0) {
        uVar1 = 0x40;
      }
      else {
        if (param_3 < 3) {
          sVar2 = 1;
        }
        else {
          sVar2 = (short)param_3 + -3;
        }
        uVar1 = 0x41;
      }
      local_10._0_2_ = CONCAT11(uVar1,(undefined1)(undefined2)local_10);
      local_10 = CONCAT13((char)sVar2,CONCAT12((char)((ushort)sVar2 >> 8),(undefined2)local_10));
    }
    else if (param_2 == 0xffff) {
      local_10 = CONCAT13((char)DAT_2080046a,
                          CONCAT12((char)((ushort)DAT_2080046a >> 8),(undefined2)local_10)) &
                 0xffefffff;
    }
    else {
      local_10 = CONCAT13((char)param_2,CONCAT12((char)((uint)param_2 >> 8),(undefined2)local_10)) &
                 0xffefffff;
    }
    DAT_20800468 = (byte)param_1;
    if ((gui_frame.cmd != 0x7b) || (gui_frame.byte1 == 0)) {
      DAT_2080046a = (undefined2)param_2;
      mainlink_queue_frame(&local_10,5);
      return;
    }
    DAT_20800487 = 1;
  }
  return;
}


// ===== gui_middle_key @ 20120fe4 (96 bytes)

/* 0x30F (FUNC) on menu-type screens, else 0xFFFF */

ushort gui_middle_key(void)

{
  if (gui_frame.cmd != 0x3a) {
    if (gui_frame.cmd < 0x3b) {
      if (gui_frame.cmd == 0x30) {
        if ((gui_frame.payload[0] != 5 && gui_frame.payload[0] != 0xb) &&
            gui_frame.payload[0] != 0xc) {
          return 0xffff;
        }
      }
      else if (gui_frame.cmd != 0x34 && gui_frame.cmd != 0x37) {
        return 0xffff;
      }
    }
    else if ((gui_frame.cmd != 0x40 && gui_frame.cmd != 0x43) && gui_frame.cmd != 0x70) {
      return 0xffff;
    }
  }
  return 0x30f;
}


// ===== gui_mouse_middle_poll @ 20121044 (256 bytes)

/* Middle mouse button events (mouse_middle_get_event): soft key from gui_middle_key, sent with
   mainlink_send_touch_key [fact] */

void gui_mouse_middle_poll(void)

{
  undefined4 uVar1;
  undefined1 local_18 [12];
  
  mouse_middle_get_event(local_18);
  switch(local_18[0]) {
  default:
    goto switchD_20121064_caseD_0;
  case 2:
    DAT_20800470 = gui_middle_key();
    if (DAT_20800470 == 0xffff) {
      return;
    }
    break;
  case 4:
    mainlink_send_touch_key(0,DAT_20800470);
    if (DAT_20800470 == 0xffff) {
      return;
    }
    DAT_20800470 = gui_middle_key();
    break;
  case 5:
    DAT_20800470 = gui_middle_key();
    if (DAT_20800470 == 0xffff) {
      return;
    }
    mainlink_send_touch_key(1,DAT_20800470,0);
  case 1:
    uVar1 = 0;
    goto LAB_201210b8;
  case 6:
    DAT_20800470 = gui_middle_key();
    if (DAT_20800470 != 0xffff) {
      mainlink_send_touch_key(0,DAT_20800470);
      mainlink_send_touch_key(1,DAT_20800470,0);
      mainlink_send_touch_key(0,DAT_20800470);
      return;
    }
    goto switchD_20121064_caseD_0;
  }
  uVar1 = 1;
LAB_201210b8:
  mainlink_send_touch_key(uVar1,DAT_20800470,0);
switchD_20121064_caseD_0:
  return;
}


// ===== gui_right_key @ 20121160 (352 bytes)

/* right button -> screen-dependent key code */

ushort gui_right_key(void)

{
  ushort uVar1;
  
  uVar1 = 0xffff;
  if (gui_frame.cmd == 0x40) {
    uVar1 = 0x12d;
  }
  else if (gui_frame.cmd < 0x41) {
    if (gui_frame.cmd == 0x37) {
      uVar1 = 0xf2;
    }
    else if (gui_frame.cmd < 0x38) {
      if (gui_frame.cmd == 0x20) {
        if ((char)gui_frame.dsp_knob < '\0') {
          uVar1 = 0x310;
        }
        else {
          uVar1 = 0x130f;
        }
        return uVar1;
      }
      if (gui_frame.cmd == 0x30) {
        switch(gui_frame.payload[0]) {
        case 0:
          return 0x10;
        case 1:
          return 0x1a;
        case 2:
          return 0x1b;
        case 3:
          return 0x1c;
        case 4:
          return 0x1d;
        case 5:
          return 0x30c;
        case 6:
          return 6;
        case 7:
          goto switchD_20121250_caseD_7;
        case 8:
          return 0xbe;
        case 9:
          return 0x19;
        case 10:
          return 0x18;
        case 0xb:
          return 0x56;
        case 0xc:
          return 0x30b;
        case 0xd:
          return 7;
        default:
          return 0xffff;
        }
      }
      if (gui_frame.cmd == 0x34) {
        uVar1 = 0x199;
      }
    }
    else {
      if (gui_frame.cmd != 0x39) {
        if (gui_frame.cmd == 0x3a) {
          uVar1 = 0x11b;
        }
        return uVar1;
      }
      uVar1 = 0x90;
    }
  }
  else if (gui_frame.cmd == 0x50) {
    uVar1 = 0x284;
  }
  else if (gui_frame.cmd < 0x51) {
    if (gui_frame.cmd == 0x41) {
      uVar1 = 0x109;
    }
    else if (gui_frame.cmd == 0x43) {
      switch(DAT_208f0d6a) {
      case 0x41:
      case 0x43:
        return 0x159;
      case 0x42:
      case 0x44:
        return 0x149;
      case 0x45:
        return 0x170;
      case 0x46:
      case 0x47:
        break;
      case 0x48:
        return 0x181;
      default:
        return 0xffff;
      }
    }
  }
  else {
    if (gui_frame.cmd != 0x70) {
      if (gui_frame.cmd == 0x7c) {
        uVar1 = 0x30f;
      }
      return uVar1;
    }
    uVar1 = 0xff;
  }
switchD_20121250_caseD_7:
  return uVar1;
}


// ===== gui_mouse_right_poll @ 20121318 (372 bytes)

/* Right mouse button events (mouse_right_get_event): soft key from gui_right_key, press / long
   press / release sent with mainlink_send_touch_key [fact] */

void gui_mouse_right_poll(void)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined1 local_1c [12];
  
  local_20 = 0xe5;
  mouse_right_get_event(local_1c);
  switch(local_1c[0]) {
  default:
    goto switchD_20121348_caseD_0;
  case 2:
    DAT_2080046e = gui_right_key();
    if (DAT_2080046e == 0xffff) {
      return;
    }
    break;
  case 4:
    mainlink_send_touch_key(0,DAT_2080046e);
    if (DAT_2080046e == 0xffff) {
      return;
    }
    DAT_2080046e = gui_right_key();
    break;
  case 5:
    DAT_2080046e = gui_right_key();
    if (DAT_2080046e == 0xffff) {
      return;
    }
    if (gui_frame.cmd == 0x7c) {
      mainlink_queue_frame(&local_20,4);
    }
    else {
      mainlink_send_touch_key(1,DAT_2080046e,0);
    }
  case 1:
    uVar1 = 0;
    goto LAB_201213bc;
  case 6:
    DAT_2080046e = gui_right_key();
    if (DAT_2080046e != 0xffff) {
      mainlink_send_touch_key(0,DAT_2080046e);
      if (gui_frame.cmd == 0x7c) {
        mainlink_queue_frame(&local_20,4);
      }
      else {
        mainlink_send_touch_key(1,DAT_2080046e,0);
      }
      mainlink_send_touch_key(0,DAT_2080046e);
      return;
    }
    goto switchD_20121348_caseD_0;
  }
  if (gui_frame.cmd != 0x7c) {
    uVar1 = 1;
LAB_201213bc:
    mainlink_send_touch_key(uVar1,DAT_2080046e,0);
    return;
  }
  mainlink_queue_frame(&local_20,4);
switchD_20121348_caseD_0:
  return;
}


// ===== touch_key_poll @ 201214b0 (740 bytes)

/* touch events (pointer_get_event src 1, touch_cal_apply) -> touch_hit_test ->
   mainlink_send_touch_key 0x2080046C [fact] (#212) */

void touch_key_poll(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort local_30 [2];
  ushort local_2c [2];
  undefined1 local_28 [4];
  uint local_24;
  uint local_20;
  
  local_30[0] = 0;
  local_2c[0] = 0;
  pointer_get_event(local_28,param_1);
  uVar1 = (ushort)local_24;
  uVar2 = (ushort)local_20;
  if (param_1 != 0) {
    touch_cal_apply((int)(short)(ushort)local_24,(int)(short)(ushort)local_20,(short *)local_30,
                    (short *)local_2c);
    uVar1 = local_30[0];
    uVar2 = local_2c[0];
  }
  local_2c[0] = uVar2;
  local_30[0] = uVar1;
  switch(local_28[0]) {
  default:
    goto switchD_20121518_caseD_0;
  case 1:
    if (((DAT_2080046c & 0x1000) == 0) && (DAT_2080046c != 0x1ff)) {
      return;
    }
    mainlink_send_touch_key(0,DAT_2080046c);
    return;
  case 2:
    if (param_1 != 0) {
      touch_cal_step(local_24 & 0xffff,local_20 & 0xffff);
    }
    DAT_2080046c = touch_hit_test(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (gui_frame.cmd == 0x7b)) && (gui_frame.byte1 != 0)))) {
      mainlink_send_touch_key(1,DAT_2080046c,(int)(short)local_30[0]);
    }
    break;
  case 3:
    DAT_2080047c = DAT_2080047c + 1;
    return;
  case 4:
    if (((DAT_2080046c & 0x1000) != 0) || (DAT_2080046c == 0x1ff)) {
      mainlink_send_touch_key(0,DAT_2080046c);
    }
    DAT_2080046c = touch_hit_test(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (gui_frame.cmd == 0x7b)) && (gui_frame.byte1 != 0)))) {
      mainlink_send_touch_key(1,DAT_2080046c,(int)(short)local_30[0]);
    }
    break;
  case 5:
    DAT_2080046c = touch_hit_test(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (gui_frame.cmd == 0x7b)) && (gui_frame.byte1 != 0)))) {
      mainlink_send_touch_key(1,DAT_2080046c,(int)(short)local_30[0]);
      mainlink_send_touch_key(0,DAT_2080046c);
    }
    break;
  case 6:
    DAT_2080046c = touch_hit_test(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) || (DAT_2080046c == 0x1ff)) {
      mainlink_send_touch_key(0,DAT_2080046c);
    }
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (gui_frame.cmd == 0x7b)) && (gui_frame.byte1 != 0)))) {
      mainlink_send_touch_key(1,DAT_2080046c,(int)(short)local_30[0]);
      mainlink_send_touch_key(0,DAT_2080046c);
    }
    if (param_1 == 0) {
      return;
    }
    goto LAB_201215e0;
  }
  if (param_1 != 0) {
LAB_201215e0:
    mouse_cursor_set_pos((uint)local_30[0],(uint)local_2c[0]);
    return;
  }
switchD_20121518_caseD_0:
  return;
}


// ===== gui_input_poll @ 201217b0 (128 bytes)

/* gui_main_loop: usbkbd_screen_settings, sends E4 (leave screen saver) once on screen 0x7B, polls
   touch keys of both layers, then gui_mouse_right_poll and gui_mouse_middle_poll [fact] */

void gui_input_poll(void)

{
  undefined4 in_r3;
  undefined4 local_8;
  
  local_8 = in_r3;
                    /* Every GUI frame [doc] */
  usbkbd_screen_settings();
  local_8 = 0;
  if ((gui_frame.cmd == 0x7b) && (gui_frame.byte1 != 0)) {
    local_8 = 0xe4;
    if (DAT_20800487 != '\0') {
      DAT_20800487 = 0;
      DAT_20800488 = 1;
      mainlink_queue_frame(&local_8,4);
      return;
    }
  }
  touch_key_poll(0);
  touch_key_poll(1);
  gui_mouse_right_poll();
  gui_mouse_middle_poll();
  return;
}


// ===== mainlink_send_e6 @ 20121830 (40 bytes)

void mainlink_send_e6(byte param_1)

{
  undefined4 local_8;
  
  local_8 = (uint)CONCAT11(param_1,0xe6);
  mainlink_queue_frame(&local_8,4);
  return;
}


// ===== mainlink_send_e0 @ 20121858 (64 bytes)

/* E0 with a given flag byte and 16-bit code */

void mainlink_send_e0(byte param_1,uint param_2)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  local_10._0_2_ = CONCAT11(param_1,0xe0);
  local_10 = CONCAT13((char)param_2,CONCAT12((char)(param_2 >> 8),(undefined2)local_10)) &
             0xffefffff;
  mainlink_queue_frame(&local_10,5);
  return;
}


// ===== cursor_window_update @ 201218a4 (168 bytes)

/* Mouse position -> cursor window 0x20808584 (cursor_rect_calc) and r_vdc5_change_read_process for
   both channels [fact] */

void cursor_window_update(void)

{
  short local_18 [2];
  short local_14 [2];
  short local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  mouse_cursor_get_pos(local_14,local_18);
                    /* 12x21 mouse-cursor window for graphics 3 [doc, inference] */
  cursor_rect_calc(&local_10,0,local_14[0],local_18[0]);
  DAT_20808584 = local_10;
  DAT_20808586 = local_e;
  DAT_20808588 = local_c;
  DAT_2080858a = local_a;
  r_vdc5_change_read_process(0,6,&DAT_208f4d70);
  cursor_rect_calc(&local_10,1,local_14[0],local_18[0]);
  DAT_20808584 = local_10;
  DAT_20808586 = local_e;
  DAT_20808588 = local_c;
  DAT_2080858a = local_a;
  r_vdc5_change_read_process(1,6,&DAT_208f4d70);
  return;
}


// ===== FUN_2012194c @ 2012194c (40 bytes)

void FUN_2012194c(ml_frame *frame)

{
  ushort uVar1;
  
  uVar1 = frame->payload[2] & 0x1f;
  if (0x14 < uVar1) {
    uVar1 = 0x14;
  }
  DAT_20800328 = (uVar1 - 10) * 10;
  return;
}


// ===== FUN_20121980 @ 20121980 (8 bytes)

undefined4 FUN_20121980(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
}


// ===== FUN_20121988 @ 20121988 (48 bytes)

int FUN_20121988(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== gui_draw_progress_bar @ 201219b8 (312 bytes)

/* (fb, x, y, percent): frame and bar 0xCE x 0x10, percent clamped to 100 [fact] */

void gui_draw_progress_bar(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  fb_fill_rect(param_1,0x821,param_2,param_3,0xce,0x10);
  fb_fill_box_t(param_1,param_2 + 2 & 0xffff,param_3,0xc,1,0x4a69);
  fb_fill_box_t(param_1,param_2 + 2 & 0xffff,param_3 + 0xcd & 0xffff,0xc,1,0x4a69);
  fb_fill_box(param_1,param_2,param_3 + 2 & 0xffff,0xca,1,0x4a69);
  fb_fill_box(param_1,param_2 + 0xf & 0xffff,param_3 + 2 & 0xffff,0xca,1,0x4a69);
  gui_draw_runs(param_1,param_2,param_3,&DAT_2016e258);
  uVar1 = 0;
  if (100 < param_4) {
    param_4 = 100;
  }
  if ((param_4 & 0x7fffffff) != 0) {
    do {
      fb_blit_raw(param_1,DAT_208006fe + param_2 & 0xffff,
                  (uint)DAT_208006fc + param_3 + uVar1 & 0xffff,0x2016e268,1,10);
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < param_4 << 1);
  }
  return;
}


// ===== filter_graph_affft_overlay @ 20121af0 (160 bytes)

/* bars of affft_bins_get into empty pixels of the filter graph (row 129, x 521..720) when status
   byte 9 bit 3 (MAIN 0x9C5C) is set [fact] (#179) */

void filter_graph_affft_overlay(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int i;
  byte local_f0 [204];
  
  param_2 = param_2 * 800;
  iVar2 = affft_bins_get(local_f0);
  i = 0;
  if (0 < iVar2) {
    do {
      iVar3 = 0;
      sVar1 = (&DAT_2016d390)[i];
      if (param_3 < param_4 + param_3) {
        iVar5 = param_3;
        do {
          if ((iVar2 - i <= (int)(uint)local_f0[iVar3]) &&
             (psVar4 = (short *)(param_1 + (iVar5 + param_2) * 2), *psVar4 == 0)) {
            *psVar4 = sVar1;
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar5 < param_4 + param_3);
      }
      i = i + 1;
      param_2 = param_2 + 800;
    } while (i < iVar2);
  }
  return;
}


// ===== FUN_20121b90 @ 20121b90 (172 bytes)

void FUN_20121b90(int param_1,int param_2,int param_3,ushort *param_4)

{
  ushort uVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  uint i;
  uint n;
  ulonglong __aeabi_idivmod_ret;
  
  uVar1 = *param_4;
  iVar4 = 0;
  i = 0;
  if (*(int *)(param_4 + 2) != 0) {
    do {
      uVar3 = (uint)*(ushort *)(*(int *)(param_4 + 4) + i * 4 + 2);
      n = (uint)*(ushort *)(*(int *)(param_4 + 4) + i * 4);
      while (uVar3 != 0) {
        uVar3 = uVar3 - 1;
        __aeabi_idivmod_ret = __aeabi_idivmod(n,(uint)uVar1);
        psVar2 = (short *)(param_1 + (param_3 + param_2 * 800) * 2 +
                          ((int)(__aeabi_idivmod_ret >> 0x20) + (int)__aeabi_idivmod_ret * 800) * 2)
        ;
        if (*psVar2 == 0) {
          *psVar2 = *(short *)(*(int *)(param_4 + 6) + iVar4 * 2);
        }
        iVar4 = iVar4 + 1;
        n = n + 1;
      }
      i = i + 1;
    } while (i < *(uint *)(param_4 + 2));
  }
  return;
}


// ===== scr_screen_saver @ 20121c3c (196 bytes)

/* packet 0x7B: YAESU logo hopping between 3 places every 180 frames */

void scr_screen_saver(void)

{
  short sVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = fb_get_layer_addr(DAT_208085bc);
  if (DAT_208004ca == 0) {
                    /* zero fill with alignment fix-up, 32-byte blocks [doc] */
    __aeabi_memclr(iVar2,0xbb800);
    layer_hide(3);
    layer_hide(4);
    layer_hide(6);
    layer_fade(5,1);
    gui_draw_runs(iVar2,(uint)*(ushort *)(&DAT_20800842 + (uint)DAT_208004cc * 4),
                  (uint)*(ushort *)(&DAT_20800840 + (uint)DAT_208004cc * 4),&DAT_2016d2c0);
    DAT_208004cc = (ushort)(DAT_208004cc + 1) % 3;
    DAT_208004ca = 0xb4;
  }
  else {
    sVar1 = DAT_208004ca + -1;
    bVar3 = DAT_208004ca == 0x5b;
    DAT_208004ca = sVar1;
    if (bVar3) {
      layer_fade(5,0);
      return;
    }
  }
  return;
}


// ===== mainlink_send_sd_state @ 20121d00 (96 bytes)

/* E2 SD card present, on change */

void mainlink_send_sd_state(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0xe2;
  uStack_14 = 0;
  iVar1 = sd_state_bit6();
  if ((DAT_208007d0 != iVar1) || (DAT_20800486 == '\0')) {
    local_18._0_2_ = CONCAT11((char)iVar1,(undefined1)local_18);
    mainlink_queue_frame(&local_18,6);
    DAT_20800486 = '\x01';
    DAT_208007d0 = iVar1;
  }
  return;
}


// ===== mainlink_send_rtc @ 20121d90 (248 bytes)

/* E3 RTC date/time, every 10th GUI pass when the minute changed */

void mainlink_send_rtc(void)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_28 [4];
  byte local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 auStack_14 [8];
  
  local_30 = 0xe3;
  local_2c = 0;
  if (gui_frame.cmd == 0x7b) {
    if (gui_frame.byte1 != 0) {
      DAT_208004c8 = 9;
      return;
    }
  }
  else if (gui_frame.cmd == 0x23) {
    DAT_208004c8 = 9;
    return;
  }
  if (DAT_208004c8 == 0) {
    rtc_get_time(local_28,local_24,auStack_14);
    iVar1 = (short)(ushort)(((uint)local_28[0] << 0x1a) >> 0x1e) * 600 + (local_28[0] & 0xf) * 0x3c
            + (uint)local_24[0];
    if (iVar1 != DAT_208004c6) {
      DAT_208004c6 = (short)iVar1;
      rtc_get_date(local_20,local_1c,local_18);
      local_30 = CONCAT13(local_18[0],
                          CONCAT12(local_1c[0],CONCAT11(local_20[0],(undefined1)local_30)));
      local_2c._0_2_ = CONCAT11(local_24[0],local_28[0]);
      mainlink_queue_frame(&local_30,8);
    }
    DAT_208004c8 = 9;
    return;
  }
  DAT_208004c8 = DAT_208004c8 + -1;
  return;
}


// ===== main_status_icons @ 20121e88 (1600 bytes)

/* REC/MSG/LOCK/... indicator row, scope SPAN/SPEED labels */

void main_status_icons(void)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  byte local_260 [12];
  byte local_254;
  byte local_252;
  byte local_251;
  byte local_24f;
  byte local_24e;
  byte local_200;
  char local_1c8;
  
  iVar1 = fb_get_layer_addr(DAT_208085b8);
  mainlink_get_last_frame((uint)local_260);
  bVar3 = gui_frame.cmd;
  if (((gui_frame.cmd == 0x70) && (local_260[0] == 0x30)) && (local_1c8 == -1)) {
    return;
  }
  if (local_260[0] != 100) {
    if (local_260[0] < 0x65) {
      if (local_260[0] != 0x3a) {
        if (local_260[0] < 0x3b) {
          if (local_260[0] != 0x21 && local_260[0] != 0x23) goto LAB_20121f38;
        }
        else if (local_260[0] != 0x3f && local_260[0] != 0x60) goto LAB_20121f38;
      }
    }
    else if ((local_260[0] != 0x65 && local_260[0] != 0x7a) &&
            (local_260[0] != 0x7b && local_260[0] != 0x7c)) goto LAB_20121f38;
  }
  memcpy(local_260,&DAT_208f0d8b,0x240);
LAB_20121f38:
  if ((DAT_208f4634 == '\0') && ((DAT_208f4633 == '\0' || (bVar3 != 0x37)))) {
    if ((local_260[0] == 0x20 || local_260[0] == 0x37) || local_260[0] == 0x39) {
      fb_clear_rect(iVar1,(uint)DAT_2080065e,(uint)DAT_2080065c,0x30,0x13);
      bVar3 = local_251 & 0xc0;
      if (bVar3 == 0x40) {
        gui_draw_runs(iVar1,(uint)DAT_20800662,(uint)DAT_20800660,&DAT_2016ddfc);
      }
      else if (bVar3 == 0x80) {
        gui_draw_runs(iVar1,(uint)DAT_20800662,(uint)DAT_20800660,&DAT_2016dddc);
      }
      else if (bVar3 == 0xc0) {
        gui_draw_runs(iVar1,(uint)DAT_2080065e,(uint)DAT_2080065c,&DAT_2016de0c);
      }
    }
    bVar3 = local_200 & 3;
    fb_clear_rect(iVar1,(uint)DAT_20800666,(uint)DAT_20800664,0x2c,0x13);
    if (bVar3 == 1) {
      gui_draw_runs(iVar1,(uint)DAT_20800666,(uint)DAT_20800664,&DAT_2016de8c);
    }
    else if (bVar3 == 2) {
      gui_draw_runs(iVar1,(uint)DAT_20800666,(uint)DAT_20800664,&DAT_2016de7c);
    }
    uVar2 = (uint)local_200;
    fb_clear_rect(iVar1,(uint)DAT_2080066a,(uint)DAT_20800668,0x16,0x13);
    if ((int)(uVar2 << 0x1c) < 0) {
      gui_draw_runs(iVar1,(uint)DAT_2080066a,(uint)DAT_20800668,&DAT_2016deac);
    }
    uVar2 = (uint)local_200;
    fb_clear_rect(iVar1,(uint)DAT_2080066e,(uint)DAT_2080066c,0x22,0x13);
    if ((int)(uVar2 << 0x1b) < 0) {
      gui_draw_runs(iVar1,(uint)DAT_2080066e,(uint)DAT_2080066c,&DAT_2016de6c);
    }
    fb_clear_rect(iVar1,(uint)DAT_20800672,(uint)DAT_20800670,0x2c,0xf);
    if ((int)((uint)local_200 << 0x1d) < 0) {
      gui_draw_runs(iVar1,(uint)DAT_20800672,(uint)DAT_20800670,&DAT_2016de9c);
    }
    if ((DAT_208f4631 == '\0') && (DAT_208f4632 == '\0')) {
      if (DAT_208f4630 == '\0') {
        iVar4 = 0xb4;
      }
      else {
        iVar4 = 0x6d;
      }
      bVar3 = local_252 & 3;
      fb_clear_rect(iVar1,iVar4,(uint)DAT_208004b2,0x11,0x11);
      if (bVar3 == 1) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004b2,&DAT_2016de1c);
      }
      else if (bVar3 == 3) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004b2,&DAT_2016de2c);
      }
      bVar3 = local_251 & 3;
      fb_clear_rect(iVar1,iVar4,(uint)DAT_208004b4,0x22,0x13);
      if (bVar3 == 1) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004b4,&DAT_2016ddac);
      }
      else if (bVar3 == 2) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004b4,&DAT_2016de3c);
      }
      uVar2 = (uint)local_252;
      fb_clear_rect(iVar1,iVar4,(uint)DAT_208004b0,0x2d,0x13);
      if ((int)(uVar2 << 0x1d) < 0) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004b0,&DAT_2016dd8c);
      }
      uVar2 = (uint)local_252;
      fb_clear_rect(iVar1,iVar4,(uint)DAT_208004ac,0x28,0x13);
      if ((int)(uVar2 << 0x1b) < 0) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004ac,&DAT_2016ddcc);
      }
      fb_clear_rect(iVar1,iVar4,(uint)DAT_208004b6,0x22,0x13);
      if ((int)((uint)local_254 << 0x1b) < 0) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004b6,&DAT_2016dd9c);
      }
      uVar2 = (uint)local_252;
      fb_clear_rect(iVar1,iVar4,(uint)DAT_208004a8,0x2e,0x13);
      if ((int)(uVar2 << 0x19) < 0) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004a8,&DAT_2016ddec);
      }
      fb_clear_rect(iVar1,iVar4,(uint)DAT_208004aa,0x39,0x13);
      if ((int)((uint)local_252 << 0x1a) < 0) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004aa,&DAT_2016ddbc);
      }
      uVar2 = (local_251 & 0x1f) >> 3;
      fb_clear_rect(iVar1,iVar4,(uint)DAT_208004ae,0x2d,0x13);
      if (uVar2 == 1) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004ae,&DAT_2016de4c);
      }
      else if (uVar2 == 2) {
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004ae,&DAT_2016de5c);
      }
      if (DAT_208f4633 == '\0') {
        uVar2 = (uint)(local_24f >> 6);
        fb_clear_rect(iVar1,iVar4,(uint)DAT_208004b8,(uint)*DAT_208025e4,(uint)DAT_208025e4[1]);
        if (2 < uVar2) {
          uVar2 = 2;
        }
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004b8,(&DAT_208025e4)[uVar2]);
        uVar2 = (uint)(local_24e >> 4);
        fb_clear_rect(iVar1,iVar4,(uint)DAT_208004ba,(uint)*(ushort *)PTR_DAT_208025f0,
                      (uint)*(ushort *)(PTR_DAT_208025f0 + 2));
        if (5 < uVar2) {
          uVar2 = 5;
        }
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004ba,(&PTR_DAT_208025f0)[uVar2]);
        uVar2 = local_24f & 0x1f;
        fb_clear_rect(iVar1,iVar4,(uint)DAT_208004bc,0x2d,0x13);
        fb_clear_rect(iVar1,iVar4,(uint)DAT_208004be,(uint)*(ushort *)PTR_DAT_20802608,
                      (uint)*(ushort *)(PTR_DAT_20802608 + 2));
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004bc,&DAT_2016debc);
        if (9 < uVar2) {
          uVar2 = 9;
        }
        gui_draw_runs(iVar1,iVar4,(uint)DAT_208004be,(&PTR_DAT_20802608)[uVar2]);
      }
    }
    memcpy(&DAT_208f0d8b,local_260,0x240);
  }
  return;
}


// ===== filter_graph_draw_markers @ 201224c8 (160 bytes)

/* (fb, mode): marker sprites on row 0x81 at the computed positions (0x208007E4 + 0x1B1 ...) [fact]
    */

void filter_graph_draw_markers(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  ushort i;
  short sVar2;
  
  switch(param_2) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 8:
  case 9:
  case 0xc:
  case 0xd:
  case 0xe:
    sVar2 = DAT_208007e4 + 0x1bb;
    sVar1 = DAT_208007e6 + 0x1bb;
    FUN_20121b90(param_1,0x81,DAT_208007e4 + 0x1b1,&DAT_2016d66c);
    FUN_20121b90(param_1,0x81,sVar1,&DAT_2016d67c);
    i = 0;
    if (sVar1 != sVar2) {
      do {
        FUN_20121b90(param_1,0x81,sVar2 + i,&DAT_2016d65c);
        i = i + 1;
      } while (i < (ushort)(sVar1 - sVar2));
      return;
    }
  }
  return;
}


// ===== filter_graph_draw_edges @ 20122638 (356 bytes)

/* (fb, mode, ...): draws the passband slopes and edges for the mode group (FUN_20136670 lines,
   FUN_20121B90 edge sprites) [fact for the calls] */

void filter_graph_draw_edges(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  
  switch(param_2) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 8:
  case 9:
  case 0xc:
  case 0xd:
  case 0xe:
    break;
  default:
    if (param_4 != 0) {
      return;
    }
  }
  iVar1 = (int)(short)param_3 / 0x14;
  uVar2 = (uint)DAT_208007de + iVar1 + 0x1bb & 0xffff;
  uVar3 = iVar1 + (uint)DAT_208007e0 + 0x1bb & 0xffff;
  uVar4 = uVar2 - 0xb & 0xffff;
  uVar5 = uVar3 + 0xb & 0xffff;
  puVar6 = &DAT_2016d428;
  if (0 < (int)(uVar4 - 0x1bd)) {
    FUN_20136670(param_1,0xac,0x1bd,uVar4 - 0x1bd & 0xffff,2,0xffff,&DAT_2016d428,param_1,param_2,
                 param_3,param_4);
  }
  if (uVar4 - 0x1bd < 0x161) {
    FUN_20121b90(param_1,0x7f,uVar4,puVar6);
  }
  else {
    uVar2 = 0x1bd;
  }
  if (uVar3 - 0x1b1 < 0x161) {
    FUN_20121b90(param_1,0x7f,uVar3,&DAT_2016d438);
  }
  else {
    uVar3 = 0x31d;
  }
  if (uVar2 - 0x1bd < 0x161) {
    FUN_20136670(param_1,0x7f,uVar2,uVar3 - uVar2 & 0xffff,2,0xffff,puVar6,param_1,param_2,param_3,
                 param_4);
  }
  uVar2 = 0x31d - uVar5;
  if (0 < (int)uVar2) {
    FUN_20136670(param_1,0xac,uVar5,uVar2 & 0xffff,2,0xffff,puVar6,param_1,param_2,param_3,param_4);
  }
  return;
}


// ===== FUN_201227d8 @ 201227d8 (820 bytes)

void FUN_201227d8(uint param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  ushort be16_load_ret;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint unaff_r6;
  uint unaff_r7;
  uint uVar6;
  int iVar7;
  
  bVar2 = false;
  iVar7 = 0;
  uVar3 = (uint)gui_frame.rtty;
  bVar1 = gui_frame.rtty >> 7;
  uVar6 = (gui_frame.psk & 0x3f) >> 4;
  iVar5 = (uint)gui_frame.cw_pitch * 10;
  be16_load_ret = be16_load(gui_frame.data_offset_be);
  uVar4 = (uint)be16_load_ret;
  if (2 < uVar6) {
    uVar6 = 2;
  }
  if (3000 < uVar4) {
    uVar4 = 3000;
  }
  switch(param_2) {
  default:
    if (iVar7 == 0) goto LAB_20122aec;
    break;
  case 2:
  case 3:
    unaff_r7 = (uint)(iVar5 * 10) / 200 + 0x4e & 0xffff | 0x6f0000;
    break;
  case 8:
  case 9:
    uVar3 = (uVar4 * 10) / 200 + 0x4e;
    goto LAB_20122a4c;
  case 0xc:
    iVar7 = (int)*(short *)(&DAT_2016d288 + (uint)bVar1 * 2);
    iVar5 = iVar7 + *(short *)(&DAT_2016d29e + (uVar3 & 3) * 2);
    goto LAB_20122aa0;
  case 0xd:
    iVar7 = (int)*(short *)(&DAT_2016d288 + (uint)bVar1 * 2);
    iVar5 = *(short *)(&DAT_2016d29e + (uVar3 & 3) * 2) + iVar7;
LAB_20122aa0:
    uVar3 = (iVar7 * 10) / 200 + 0x4eU & 0xffff;
    bVar2 = true;
    unaff_r6 = (iVar5 * 10) / 200 + 0x4eU & 0xffff | 0x6f0000;
    gui_draw_runs(param_1,0x6f,uVar3 + 0x1af & 0xffff,&DAT_2016d458);
    fb_fill_box(param_1,0x7e,uVar3 + 0x1bb & 0xffff,1,0x30,0xfc00);
    goto LAB_20122aec;
  case 0xe:
    uVar3 = (*(short *)(&DAT_2016d298 + uVar6 * 2) * 10) / 200 + 0x4eU & 0xffff;
LAB_20122a4c:
    gui_draw_runs(param_1,0x6f,uVar3 + 0x1b4 & 0xffff,&DAT_2016d448);
    fb_fill_box(param_1,0x7e,uVar3 + 0x1bb & 0xffff,1,0x30,0xfc00);
    goto LAB_20122aec;
  }
  gui_draw_runs(param_1,unaff_r7 >> 0x10,unaff_r7 + 0x1b4 & 0xffff,&DAT_2016d468);
  fb_fill_box(param_1,(unaff_r7 >> 0x10) + 0xf & 0xffff,unaff_r7 + 0x1bb & 0xffff,1,0x30,0xfc00);
LAB_20122aec:
  if (bVar2) {
    gui_draw_runs(param_1,unaff_r6 >> 0x10,unaff_r6 + 0x1b9 & 0xffff,&DAT_2016d478);
    fb_fill_box(param_1,(unaff_r6 >> 0x10) + 0xf & 0xffff,unaff_r6 + 0x1bb & 0xffff,1,0x30,0xffe0);
  }
  return;
}


// ===== FUN_20122b48 @ 20122b48 (440 bytes)

void FUN_20122b48(undefined4 param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  short local_40 [4];
  int local_38;
  uint local_34;
  undefined *local_30 [3];
  
  cVar2 = DAT_208f4606;
  local_30[1] = (undefined *)0x0;
  local_30[2] = (undefined *)0x0;
  local_30[0] = (undefined *)0x0;
  local_38 = 0;
  local_34 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  if (DAT_208f4619 != '\0') {
    local_30[1] = (undefined *)&DAT_2016d418;
    local_40[0] = 0;
    local_40[1] = 0x7c;
    local_38 = (uint)(ushort)((short)(((uint)DAT_208f461a * 10) / 200) + 0x203) << 0x10;
  }
  if (DAT_208f461d != '\0') {
    sVar1 = (short)(((uint)DAT_208f461e * 10) / 200) + 0x1fe;
    if ((gui_frame.contour_be[0] & 0x80) == 0) {
      local_40[0] = 0x7c;
      local_38 = CONCAT22(local_38._2_2_,sVar1);
      local_30[0] = &DAT_2016d408;
    }
    else {
      local_40[0] = 0x7c;
      local_38 = CONCAT22(local_38._2_2_,sVar1);
      local_30[0] = (undefined *)&DAT_2016d3f8;
    }
  }
  if (DAT_208f4621 != '\0') {
    local_30[2] = &DAT_2016d3e8;
    local_40[2] = 0x7c;
    local_40[3] = 0;
    local_34 = (uint)(ushort)((short)(((uint)DAT_208f4622 * 10) / 200) + 0x208);
  }
  if (((DAT_208f4606 != '\x04' && DAT_208f4606 != '\x05') &&
      (DAT_208f4606 != '\x06' && DAT_208f4606 != '\a')) &&
     (DAT_208f4606 != '\n' && DAT_208f4606 != '\v')) {
    uVar5 = 0;
    do {
      puVar4 = (ushort *)local_30[uVar5];
      if (((puVar4 != (ushort *)0x0) &&
          (iVar3 = (int)*(short *)((int)&local_38 + uVar5 * 2), 0x1bd < iVar3)) &&
         ((int)((uint)*puVar4 + iVar3) < 0x31e)) {
        FUN_201366e0(param_1,(int)local_40[uVar5],iVar3,puVar4,0x1bd,0x31d);
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < 3);
    FUN_201227d8(param_1,cVar2);
  }
  return;
}


// ===== filter_passband_calc @ 20122d00 (772 bytes)

/* (out, mode, ...): passband edge pixels for the mode group (SSB/CW/AM/FM/DATA cases; DATA uses
   data_offset_be) into the records 0x208007DC / 0x208007E2 [fact for the fields] */

void filter_passband_calc(short *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  ushort be16_load_ret;
  short sVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  
  uVar6 = 0;
  switch(param_2) {
  case 0:
  case 1:
    uVar3 = 0;
    do {
      if ((ushort)(&DAT_2016d488)[uVar3] < param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x17);
    if (0x16 < uVar6) {
      uVar6 = 0x16;
    }
    iVar1 = uVar6 * 6;
    sVar5 = *(short *)(&UNK_2016d4b6 + iVar1);
    sVar4 = *(short *)(&UNK_2016d4b8 + iVar1);
    sVar2 = *(short *)(&UNK_2016d4ba + iVar1);
    break;
  case 2:
  case 3:
    uVar3 = 0;
    do {
      if ((int)(short)(&DAT_2016d540)[uVar3 * 3] < (int)param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x15);
    if (0x14 < uVar6) {
      uVar6 = 0x14;
    }
    if ((ushort)(&DAT_2016d540)[uVar6 * 3] < param_4) {
      uVar3 = (uint)((ulonglong)(param_4 * 10) * 0x51eb851f >> 0x20);
    }
    else {
      uVar3 = (uint)((ulonglong)(((ushort)(&DAT_2016d540)[uVar6 * 3] + param_4 >> 1) * 10) *
                     0x51eb851f >> 0x20);
    }
    sVar4 = (short)(uVar3 >> 6) + 0x4e;
    sVar5 = *(short *)(&UNK_2016d542 + uVar6 * 6) + sVar4;
    sVar2 = *(short *)(&UNK_2016d544 + uVar6 * 6) + sVar4;
    break;
  default:
    sVar4 = 0x99;
    sVar5 = 0x91;
    sVar2 = 0xa0;
    break;
  case 8:
  case 9:
    uVar3 = 0;
    do {
      if ((int)(short)(&DAT_2016d540)[uVar3 * 3] < (int)param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x15);
    if (0x14 < uVar6) {
      uVar6 = 0x14;
    }
    be16_load_ret = be16_load(gui_frame.data_offset_be);
    sVar4 = (short)(((uint)be16_load_ret * 10) / 200) + 0x4e;
    sVar5 = *(short *)(&UNK_2016d542 + uVar6 * 6) + sVar4;
    sVar2 = *(short *)(&UNK_2016d544 + uVar6 * 6) + sVar4;
    break;
  case 0xc:
  case 0xd:
    uVar3 = 0;
    do {
      if ((int)(short)(&DAT_2016d540)[uVar3 * 3] < (int)param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x15);
    if (0x14 < uVar6) {
      uVar6 = 0x14;
    }
    iVar1 = ((int)*(short *)(&DAT_2016d288 + (uint)(gui_frame.rtty >> 7) * 2) +
            (int)*(short *)(&DAT_2016d29e + (gui_frame.rtty & 3) * 2) / 2) * 10;
    sVar4 = (((short)(iVar1 / 200) + (short)(iVar1 >> 0x1f)) -
            (short)((longlong)iVar1 * 0x51eb851f >> 0x3f)) + 0x4e;
    sVar5 = *(short *)(&UNK_2016d542 + uVar6 * 6) + sVar4;
    sVar2 = *(short *)(&UNK_2016d544 + uVar6 * 6) + sVar4;
    break;
  case 0xe:
    uVar3 = 0;
    do {
      if ((int)(short)(&DAT_2016d540)[uVar3 * 3] < (int)param_3) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 0x15);
    if (0x14 < uVar6) {
      uVar6 = 0x14;
    }
    iVar1 = *(short *)(&DAT_2016d298 + ((gui_frame.psk & 0x3f) >> 4) * 2) * 10;
    sVar4 = (((short)(iVar1 / 200) +
             (*(short *)(&DAT_2016d298 + ((gui_frame.psk & 0x3f) >> 4) * 2) >> 0xf)) -
            (short)((longlong)iVar1 * 0x51eb851f >> 0x3f)) + 0x4e;
    sVar5 = *(short *)(&UNK_2016d542 + uVar6 * 6) + sVar4;
    sVar2 = *(short *)(&UNK_2016d544 + uVar6 * 6) + sVar4;
  }
  *param_1 = sVar4;
  param_1[1] = sVar5;
  param_1[2] = sVar2;
  return;
}


// ===== filter_graph_state_update @ 20123088 (784 bytes)

/* (state 0x208F4600): reads IF SHIFT, NOTCH and CONTOUR from the current frame (shift_be, notch_be,
   contour_be) and derives the per-mode graph values [fact for the fields] */

void filter_graph_state_update
               (undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  uint uVar8;
  undefined1 uVar9;
  short sVar10;
  int iVar11;
  ushort uVar12;
  int iVar13;
  uint uVar14;
  undefined4 local_28;
  
  uVar4 = (ushort)gui_frame.cw_pitch;
  iVar13 = (uint)gui_frame.dsp_knob << 0x1d;
  uVar14 = gui_frame.dsp_knob & 3;
  uVar12 = (ushort)gui_frame.width_be[1] + (ushort)gui_frame.width_be[0] * 0x100;
  if (uVar12 < 0x32) {
    uVar12 = 0x32;
  }
  if (16000 < uVar12) {
    uVar12 = 16000;
  }
  local_28 = param_4;
  uVar5 = be16_load(gui_frame.shift_be);
  uVar8 = (uint)uVar5;
  if (SCARRY4(uVar8,0x4b0)) {
    uVar8 = 0xfffffb50;
  }
  uVar5 = (ushort)gui_frame.main_vfo.mode;
  if (0x4b0 < (int)uVar8) {
    uVar8 = 0x4b0;
  }
  if (0xf < uVar5) {
    uVar5 = 0xf;
  }
  uVar6 = be16_load(gui_frame.notch_be);
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  if (0x140 < uVar6) {
    uVar6 = 0x140;
  }
  local_28 = CONCAT31(CONCAT21(local_28._2_2_,gui_frame.contour_be[1]),gui_frame.contour_be[0]) &
             0xffffff7f;
  uVar7 = be16_load((byte *)&local_28);
  if (uVar7 == 0) {
    uVar7 = 1;
  }
  if (0x140 < uVar7) {
    uVar7 = 0x140;
  }
  iVar11 = (int)(char)gui_frame.apf_offset;
  param_1[1] = (byte)((uint)iVar13 >> 0x1f);
  if (iVar11 < -0x19) {
    iVar11 = -0x19;
  }
  if (0x19 < iVar11) {
    iVar11 = 0x19;
  }
  sVar10 = (short)iVar11 * 10;
  if ((uVar14 == 3) && (iVar13 < 0)) {
    *param_1 = 4;
  }
  else {
    *param_1 = (char)uVar14;
  }
  *(ushort *)(param_1 + 6) = uVar5;
  *(short *)(param_1 + 10) = (short)uVar8;
  param_1[8] = (byte)(((uint)gui_frame.dsp_knob << 0x1a) >> 0x1f);
  *(ushort *)(param_1 + 0xe) = uVar12;
  param_1[0x10] = (byte)(((uint)gui_frame.dsp_knob << 0x1b) >> 0x1f);
  *(ushort *)(param_1 + 0x1a) = uVar6 * 10;
  bVar1 = (byte)(((uint)gui_frame.cw_apf_contour_notch_agc << 0x1b) >> 0x1f);
  param_1[0x18] = bVar1;
  *(ushort *)(param_1 + 0x1e) = uVar7 * 10;
  bVar2 = (byte)(((uint)gui_frame.cw_apf_contour_notch_agc << 0x1a) >> 0x1f);
  param_1[0x1c] = bVar2;
  *(ushort *)(param_1 + 0x22) = sVar10 + uVar4 * 10;
  *(short *)(param_1 + 0x26) = sVar10;
  bVar3 = (byte)(((uint)gui_frame.cw_apf_contour_notch_agc << 0x19) >> 0x1f);
  param_1[0x20] = bVar3;
  *(ushort *)(param_1 + 0x28) = uVar4 * 10;
  param_1[0x19] = bVar1;
  param_1[0x1d] = bVar2;
  param_1[0x21] = bVar3;
  switch(uVar5) {
  case 0:
  case 1:
    param_1[2] = 0;
    sVar10 = (ushort)gui_frame.width_default_be[1] + (ushort)gui_frame.width_default_be[0] * 0x100;
    *(short *)(param_1 + 0x16) = sVar10;
    param_1[8] = uVar8 != 0;
    *(ushort *)(param_1 + 0x12) = uVar12;
    if (*(short *)(param_1 + 0xe) == sVar10) break;
LAB_201232ac:
    uVar9 = 1;
    goto LAB_201232b0;
  case 2:
  case 3:
    param_1[2] = 1;
    sVar10 = (ushort)gui_frame.width_default_be[1] + (ushort)gui_frame.width_default_be[0] * 0x100;
    *(short *)(param_1 + 0x16) = sVar10;
    param_1[8] = uVar8 != 0;
    *(ushort *)(param_1 + 0x12) = uVar12;
    if (*(short *)(param_1 + 0xe) != sVar10) goto LAB_201232ac;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 10:
  case 0xb:
    param_1[2] = 3;
    *(undefined2 *)(param_1 + 0x16) = 0;
    param_1[8] = 0;
    param_1[0x10] = 0;
    *(undefined2 *)(param_1 + 0x12) = 0;
    goto LAB_201233c4;
  case 8:
  case 9:
    param_1[2] = 4;
    sVar10 = (ushort)gui_frame.width_default_be[1] + (ushort)gui_frame.width_default_be[0] * 0x100;
    *(short *)(param_1 + 0x16) = sVar10;
    param_1[8] = uVar8 != 0;
    *(ushort *)(param_1 + 0x12) = uVar12;
    if (*(short *)(param_1 + 0xe) != sVar10) goto LAB_201232ac;
    break;
  case 0xc:
  case 0xd:
    param_1[2] = 5;
    sVar10 = (ushort)gui_frame.width_default_be[1] + (ushort)gui_frame.width_default_be[0] * 0x100;
    *(short *)(param_1 + 0x16) = sVar10;
    param_1[8] = uVar8 != 0;
    *(ushort *)(param_1 + 0x12) = uVar12;
    if (*(short *)(param_1 + 0xe) != sVar10) goto LAB_201232ac;
    break;
  case 0xe:
    param_1[2] = 6;
    sVar10 = (ushort)gui_frame.width_default_be[1] + (ushort)gui_frame.width_default_be[0] * 0x100;
    *(short *)(param_1 + 0x16) = sVar10;
    param_1[8] = uVar8 != 0;
    *(ushort *)(param_1 + 0x12) = uVar12;
    if (*(short *)(param_1 + 0xe) != sVar10) goto LAB_201232ac;
    break;
  default:
    param_1[8] = 1;
    param_1[0x10] = 1;
    goto LAB_201233c4;
  }
  uVar9 = 0;
LAB_201232b0:
  param_1[0x10] = uVar9;
LAB_201233c4:
  param_1[0x2a] = (byte)(((uint)gui_frame.dsp_knob << 0x19) >> 0x1f);
  return;
}


// ===== filter_graph_small @ 201233d4 (472 bytes)

/* gui_main_loop draws it instead of main_filter_graph while 0x208F4633 is 0: the same passband
   computation (filter_graph_state_update, filter_passband_calc) and curve/edge drawing in the 0x164
   x 0x45 box at (x 0x1BB, y 0x6D), without the value texts and buttons; skipped while
   gui_scope_draw_hold_set holds [fact] */

void filter_graph_small(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  if (DAT_20800480 == '\0') {
                    /* Returns the 3D work buffer pointer 0x208085B4 [doc] */
    iVar8 = scope3d_buf_get();
  }
  else {
    iVar8 = 0;
  }
  iVar2 = fb_get_layer_addr(DAT_208085b8);
  iVar3 = fb_get_layer_addr(DAT_208085b8);
  uVar4 = (uint)gui_frame.scope_flags;
  uVar5 = (uint)gui_frame.tx_bpf;
  filter_graph_state_update(&DAT_208f4600);
  uVar1 = DAT_208f4606;
  uVar7 = (uint)DAT_208f4628;
  iVar9 = (int)DAT_208f460a;
  uVar6 = (uint)DAT_208f4616;
                    /* passband edge pixels for the mode group [doc] */
  filter_passband_calc(&DAT_208007dc,DAT_208f4606,DAT_208f460e,uVar7);
  filter_passband_calc(&DAT_208007e2,uVar1,uVar6,uVar7);
  if (-1 < (int)(uVar4 << 0x1a)) {
    if (iVar8 != 0) {
      iVar3 = iVar8 + -0x2a940;
    }
    fb_fill_rect(iVar3,0,0x6d,0x1bb,0x164,0x45);
    gui_draw_runs(iVar3,0x6d,0x1bb,&DAT_2016d380);
    if ((DAT_2080048a == '\0') && (FUN_20122b48(iVar3), DAT_2080048a == '\0')) {
      filter_graph_draw_edges(iVar3,uVar1,iVar9,1);
    }
    else if ((gui_frame.tx_bpf & 0x80) != 0) {
      iVar9 = ((uVar5 & 0x7f) >> 4) * 4;
      DAT_208007de = *(undefined2 *)(&DAT_2016d5be + iVar9);
      DAT_208007e0 = *(undefined2 *)(&DAT_2016d5c0 + iVar9);
      filter_graph_draw_edges(iVar3,uVar1,0);
    }
    if ((gui_frame.flags9 & 8) != 0) {
      filter_graph_affft_overlay(iVar3,0x81,0x209,200);
    }
                    /* marker sprites on row 0x81 at the computed positions [doc] */
    filter_graph_draw_markers(iVar3,uVar1);
    if (iVar8 != 0) {
      iVar2 = iVar2 + 0x2acb6;
      iVar8 = iVar8 + 0x376;
      iVar3 = 0;
      do {
        memcpy(iVar2,iVar8,0x2c8);
        iVar3 = iVar3 + 1;
        iVar8 = iVar8 + 0x640;
        iVar2 = iVar2 + 0x640;
      } while (iVar3 < 0x45);
    }
  }
  return;
}


// ===== filter_graph_buttons @ 201235ac (604 bytes)

/* Bottom row of main_filter_graph: four 0x58 x 0x31 sprite buttons at y 0x116, x 0x1BB / 0x214 /
   0x26D / 0x2C6 with on/off sprites from the tables 0x208008C8.. [fact] */

void filter_graph_buttons(int param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  bool bVar5;
  
  cVar3 = DAT_208f4601;
  cVar2 = DAT_208f4600;
  bVar5 = DAT_208f4608 != '\0';
  if (bVar5) {
    iVar4 = 0xfc00;
  }
  else {
    iVar4 = 0x8410;
  }
  if (DAT_208f4600 == '\0') {
    fb_fill_rect(param_1,iVar4,0x116,0x1bb,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x1bb,(void *)(&DAT_208008c8)[bVar5]);
  }
  else {
    gui_draw_runs(param_1,0x127,0x1bb,(void *)(&DAT_208008d0)[bVar5]);
  }
  bVar5 = DAT_208f4610 != '\0';
  if (bVar5) {
    iVar4 = 0xfc00;
  }
  else {
    iVar4 = 0x8410;
  }
  if (cVar2 == '\x01') {
    fb_fill_rect(param_1,iVar4,0x116,0x214,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x214,(void *)(&DAT_208008d8)[bVar5]);
  }
  else {
    gui_draw_runs(param_1,0x127,0x214,(void *)(&DAT_208008e0)[bVar5]);
  }
  bVar5 = DAT_208f4618 != '\0';
  if (bVar5) {
    iVar4 = 0xfc00;
  }
  else {
    iVar4 = 0x8410;
  }
  if (cVar2 == '\x02') {
    fb_fill_rect(param_1,iVar4,0x116,0x26d,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x26d,(void *)(&DAT_208008e8)[bVar5]);
  }
  else {
    gui_draw_runs(param_1,0x127,0x26d,(void *)(&DAT_208008f0)[bVar5]);
  }
  if (cVar3 != '\0') {
    if (DAT_208f4620 == '\0') {
      iVar4 = 0x8410;
    }
    else {
      iVar4 = 0xfc00;
    }
    uVar1 = (uint)(DAT_208f4620 != '\0');
    if (cVar2 == '\x04') {
      fb_fill_rect(param_1,iVar4,0x116,0x2c6,0x58,0x31);
      gui_draw_runs(param_1,0x127,0x2c6,*(void **)(uVar1 * 4 + 0x20800908));
      return;
    }
    gui_draw_runs(param_1,0x127,0x2c6,(void *)(&DAT_20800910)[uVar1]);
    return;
  }
  bVar5 = DAT_208f461c != '\0';
  if (bVar5) {
    iVar4 = 0xfc00;
  }
  else {
    iVar4 = 0x8410;
  }
  if (cVar2 == '\x03') {
    fb_fill_rect(param_1,iVar4,0x116,0x2c6,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x2c6,(void *)(&DAT_208008f8)[bVar5]);
    return;
  }
  gui_draw_runs(param_1,0x127,0x2c6,(void *)(&DAT_20800900)[bVar5]);
  return;
}


// ===== FUN_20123808 @ 20123808 (68 bytes)

void FUN_20123808(int param_1)

{
  uint uVar1;
  
  if (DAT_208f4600 == '\x02') {
    uVar1 = (uint)DAT_208f4618;
  }
  else if (DAT_208f4600 == '\x03') {
    uVar1 = (uint)DAT_208f461c;
  }
  else {
    if (DAT_208f4600 != '\x04') {
      return;
    }
    uVar1 = (uint)DAT_208f4620;
  }
  gui_draw_runs(param_1,0xd0,0x2f7,*(void **)(&DAT_208007f0 + uVar1 * 4));
  return;
}


// ===== filter_graph_value_text @ 2012384c (884 bytes)

/* (fb, sel): value line under the graph: tick marks and the "%dHz" values of the selected function
   (0x208F460A / 4612 / 461A / 461E / 4626) right-aligned at y 0xE2 [fact] */

void filter_graph_value_text(uint param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  void *pvVar6;
  undefined4 local_48;
  undefined4 local_44;
  undefined *local_40 [5];
  uint local_2c;
  int iStack_28;
  
  pvVar6 = (void *)0x0;
  local_40[0] = &DAT_201a05f4;
  local_40[1] = &DAT_201a04d0;
  local_40[2] = &DAT_201a03b8;
  local_40[3] = &DAT_201a04d0;
  local_40[4] = &DAT_201a05f4;
  local_2c = param_1;
  iStack_28 = param_2;
  fb_fill_box(param_1,0xb4,0x1bd,0x160,1,0xffff);
  uVar3 = 0xfffffff2;
  do {
    uVar2 = uVar3 * 0x19 + param_2 + 0x1ba & 0xffff;
    if (uVar2 - 0x1bd < 0x15f) {
      if ((uVar3 & 1) == 0) {
        fb_fill_box_t(local_2c,0xb6,uVar2,6,2,0xffff);
      }
      else {
        fb_fill_box_t(local_2c,0xb6,uVar2,4,2,0xffff);
      }
    }
    uVar3 = (uint)(short)((short)uVar3 + 1);
  } while ((int)uVar3 < 0xf);
  iVar4 = 0;
  do {
    uVar3 = (uint)(ushort)(&DAT_2016d6dc)[iVar4] + param_2 + 0x1bb & 0xffff;
    if (uVar3 - 0x1bd < 0x161) {
      gui_draw_runs(local_2c,0xbe,uVar3,local_40[iVar4]);
    }
    iVar4 = (int)(short)((short)iVar4 + 1);
  } while (iVar4 < 5);
  local_48 = 0;
  local_44 = 0;
  if (DAT_208f4600 == '\0') {
    pvVar6 = *(void **)(&DAT_208008a0 + (uint)DAT_208f4608 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4608 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f460a);
                    /* Word-at-a-time string length [doc] */
      sVar1 = strlen(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x01') {
    pvVar6 = *(void **)(&DAT_208008a8 + (uint)DAT_208f4610 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4610 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f4612);
      sVar1 = strlen(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x02') {
    pvVar6 = *(void **)(&DAT_208008b0 + (uint)DAT_208f4618 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4618 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f461a);
      sVar1 = strlen(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x03') {
    pvVar6 = *(void **)(&DAT_208008b8 + (uint)DAT_208f461c * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f461c == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f461e);
      sVar1 = strlen(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x04') {
    pvVar6 = *(void **)(&DAT_208008c0 + (uint)DAT_208f4620 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4620 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f4626);
      sVar1 = strlen(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  gui_draw_runs(local_2c,0xe4,0x1c1,pvVar6);
  return;
}


// ===== main_filter_graph @ 20123c04 (704 bytes)

/* SHIFT/WIDTH/NOTCH/CONTOUR/APF graph */

void main_filter_graph(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (DAT_20800480 == '\0') {
                    /* Returns the 3D work buffer pointer 0x208085B4 [doc] */
    iVar8 = scope3d_buf_get();
  }
  else {
    iVar8 = 0;
  }
  iVar4 = fb_get_layer_addr(DAT_208085b8);
  iVar5 = fb_get_layer_addr(DAT_208085b8);
  iVar6 = fb_get_layer_addr(DAT_208085bc);
  filter_graph_state_update(&DAT_208f4600);
  uVar3 = DAT_208f4628;
  uVar2 = DAT_208f4616;
  uVar1 = DAT_208f4606;
  iVar10 = (int)DAT_208f460a;
                    /* passband edge pixels for the mode group [doc] */
  filter_passband_calc(&DAT_208007dc,DAT_208f4606,DAT_208f460e,DAT_208f4628);
  filter_passband_calc(&DAT_208007e2,uVar1,uVar2,uVar3);
  if (iVar8 != 0) {
    iVar5 = iVar8 + -0x2a940;
  }
  if ((((gui_frame.cmd == 0x30 || gui_frame.cmd == 0x62) || gui_frame.cmd == 0x50) ||
      (iVar9 = iVar5, DAT_208f4630 != '\0')) && (iVar9 = iVar6, gui_frame.cmd != 0x50)) {
    fb_fill_rect(iVar5,0x821,0x6d,0x1bb,0x164,0x45);
  }
  fb_fill_rect(iVar9,0,0x6d,0x1bb,0x164,0x45);
  gui_draw_runs(iVar9,0x6d,0x1bb,&DAT_2016d68c);
  uVar7 = 0;
  do {
    gui_draw_runs(iVar9,uVar7 + 0x70,0x1bb,&DAT_2016d69c);
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 0x42);
  fb_fill_rect(iVar6,0x821,0xb2,0x1bb,0x164,100);
  fb_fill_rect(iVar6,0x821,0x116,0x1bb,0x164,0x32);
  uVar7 = 0;
  do {
    gui_draw_runs(iVar6,uVar7 + 0xb2,0x1bb,&DAT_2016d69c);
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 99);
  gui_draw_runs(iVar6,uVar7 + 0xb2,0x1bb,&DAT_2016d6ac);
  uVar7 = 0;
  do {
    gui_draw_runs(iVar6,uVar7 + 0x116,0x1bb,&DAT_2016d6bc);
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 0x2f);
  gui_draw_runs(iVar6,uVar7 + 0x116,0x1bb,&DAT_2016d6cc);
  FUN_20122b48(iVar9);
  filter_graph_draw_edges(iVar9,uVar1,iVar10,1);
  if ((gui_frame.flags9 & 8) != 0) {
    filter_graph_affft_overlay(iVar9,0x81,0x209,200);
  }
                    /* marker sprites on row 0x81 at the computed positions [doc] */
  filter_graph_draw_markers(iVar9,uVar1);
  filter_graph_value_text(iVar6,DAT_208007e2);
  FUN_20123808(iVar6);
                    /* Bottom row of main_filter_graph [doc] */
  filter_graph_buttons(iVar6);
  if (iVar8 != 0) {
    iVar5 = 0;
    iVar4 = iVar4 + 0x2acb6;
    iVar8 = iVar8 + 0x376;
    do {
      memcpy(iVar4,iVar8,0x2c8);
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + 0x640;
      iVar4 = iVar4 + 0x640;
    } while (iVar5 < 0x45);
  }
  return;
}


// ===== scope_markers_draw @ 20123ec4 (1464 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* (r0 = 1 MULTI / 0 large) red 0xF800 RX/TX marker frames on graphics 1; zeroes range 0x208007D4 */

void scope_markers_draw(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  short sVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint be32_load_ret;
  uint be32_load_ret_2;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint unaff_r7;
  uint uVar20;
  uint unaff_r9;
  bool bVar21;
  uint uStack_5c;
  undefined2 uVar4;
  byte gui_frame_flags9_val;
  
  uVar6 = fb_get_layer_addr(DAT_208085b8);
  gui_frame_flags9_val = gui_frame.flags9;
  uVar15 = (uint)gui_frame.flags9;
  iVar16 = (uint)gui_frame.scope_flags << 0x1a;
  if (iVar16 < 0) {
    uVar20 = 0x80;
  }
  else {
    uVar20 = 0xc9;
  }
  if (param_1 == 0) {
    if (iVar16 < 0) {
      uVar7 = *(uint *)(&DAT_20802d78 + (uint)DAT_208004d2 * 4);
      unaff_r9 = _DAT_20800714;
    }
    else {
      uVar7 = *(uint *)(&DAT_20802d6c + (uint)DAT_208004d2 * 4);
      unaff_r9 = _DAT_20800710;
    }
    if (DAT_208004d0 == '\x01') {
joined_r0x20123fbc:
      unaff_r7 = uVar7;
      if (-1 < (int)(uVar15 << 0x19)) goto joined_r0x20123fcc;
    }
    else {
joined_r0x20123fcc:
      unaff_r7 = unaff_r9;
      unaff_r9 = unaff_r7;
      if (DAT_208004d0 != '\x01') goto LAB_20124054;
    }
    if ((int)(uVar15 << 0x1a) < 0) {
      unaff_r9 = uVar7;
    }
  }
  else if (param_1 == 1) {
    unaff_r9 = _DAT_20800718;
    uVar3 = DAT_20800832;
    uVar4 = DAT_20800830;
    if (iVar16 < 0) {
      unaff_r9 = _DAT_2080071c;
      uVar3 = DAT_20800836;
      uVar4 = DAT_20800834;
    }
    uVar7 = CONCAT22(uVar3,uVar4);
    if (DAT_208004d0 == '\x01') goto joined_r0x20123fbc;
    goto joined_r0x20123fcc;
  }
LAB_20124054:
  if (iVar16 < 0) {
    uVar7 = 0x80;
  }
  else {
    uVar7 = 0xc9;
  }
  uVar17 = (uint)(short)(DAT_20802d86 + (short)uVar20);
  uVar1 = DAT_20802d8e + (short)uVar20;
  uVar8 = (uint)DAT_20800828;
  uVar9 = (uint)DAT_2080082a;
  uVar10 = (uint)DAT_2080082c;
  uVar11 = (uint)DAT_2080082e;
  be32_load_ret = be32_load(gui_frame.op_freq_be);
  be32_load_ret_2 = be32_load(gui_frame.tx_freq_be);
  uVar18 = gui_frame.span_ccf & 0x1f;
  if (9 < uVar18) {
    uVar18 = 9;
  }
  if (param_2 == 0) {
    uVar19 = be32_load(gui_frame.dial_freq_be);
    uVar12 = uVar19 - *(int *)(&UNK_2016d6e8 + uVar18 * 4) / 2;
    uVar19 = uVar19 + *(int *)(&UNK_2016d6e8 + uVar18 * 4) / 2;
  }
  else {
    uVar12 = be32_load(gui_frame.scope_start_be);
    uVar19 = *(int *)(&UNK_2016d6e8 + uVar18 * 4) + uVar12;
  }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  sVar5 = __aeabi_uidivmod((be32_load_ret - uVar12) * 0x317,uVar19 - uVar12);
  uStack_5c = (uint)(short)(sVar5 + 4);
  bVar21 = SBORROW4(uStack_5c,10);
  iVar16 = uStack_5c - 10;
  if (9 < (int)uStack_5c) {
    bVar21 = SBORROW4(be32_load_ret,uVar12);
    iVar16 = be32_load_ret - uVar12;
  }
  if (iVar16 < 0 == bVar21) {
    if (0x314 < (int)uStack_5c) {
      uStack_5c = 0x314;
    }
  }
  else {
    uStack_5c = 10;
  }
  sVar5 = __aeabi_uidivmod((be32_load_ret_2 - uVar12) * 0x317,uVar19 - uVar12);
  uVar18 = (uint)(short)(sVar5 + 4);
  bVar21 = SBORROW4(uVar18,10);
  iVar16 = uVar18 - 10;
  if (9 < (int)uVar18) {
    bVar21 = SBORROW4(be32_load_ret_2,uVar12);
    iVar16 = be32_load_ret_2 - uVar12;
  }
  if (iVar16 < 0 == bVar21) {
    if (0x314 < (int)uVar18) {
      uVar18 = 0x314;
    }
  }
  else {
    uVar18 = 10;
  }
  DAT_208007d4 = 0;
  DAT_208007d6 = 0;
  uVar13 = uVar20 + 0xd;
  uVar14 = (uint)(short)((short)uStack_5c + -6);
  uVar2 = (short)uVar18 - 6;
  if (-1 < (char)gui_frame_flags9_val) {
    DAT_208007d4 = 0;
    DAT_208007d6 = 0;
    return;
  }
  if (param_2 == 0) {
LAB_201241e8:
    if (param_2 != 1) goto LAB_20124394;
LAB_201242a0:
    bVar21 = SBORROW4(uVar12,be32_load_ret_2);
    iVar16 = uVar12 - be32_load_ret_2;
    uVar20 = uVar12;
    if ((int)uVar12 <= (int)be32_load_ret_2) {
      bVar21 = SBORROW4(be32_load_ret_2,uVar19);
      iVar16 = be32_load_ret_2 - uVar19;
      uVar20 = uVar19;
    }
    if (uVar20 == be32_load_ret_2 || iVar16 < 0 != bVar21) {
      gui_draw_runs(uVar6,uVar13,(uint)uVar2,&DAT_2016e410);
      fb_fill_box_t(uVar6,uVar13,uVar18 & 0xffff,(unaff_r9 >> 0x10) - 0xd & 0xffff,unaff_r9 & 0xff,
                    0xf800);
    }
    if ((int)uVar12 <= (int)be32_load_ret_2) {
      if ((int)be32_load_ret_2 <= (int)uVar19) goto LAB_2012442c;
      goto LAB_20124410;
    }
  }
  else {
    if (param_2 == 1) {
      if ((int)uVar12 < (int)be32_load_ret) {
        if ((int)uVar19 <= (int)be32_load_ret) {
          gui_draw_runs(uVar6,uVar11 + uVar20 & 0xffff,uVar10,&DAT_2016e3f0);
        }
      }
      else {
        gui_draw_runs(uVar6,uVar9 + uVar20 & 0xffff,uVar8,&DAT_2016e3e0);
      }
      gui_draw_runs(uVar6,uVar20,uVar14 & 0xffff,&DAT_2016e400);
      fb_fill_box_t(uVar6,uVar20,uStack_5c & 0xffff,unaff_r7 >> 0x10,unaff_r7 & 0xff,0x7e0);
      goto LAB_201242a0;
    }
    if (param_2 != 2) goto LAB_201241e8;
    if ((int)uVar12 < (int)be32_load_ret) {
      if ((int)uVar19 <= (int)be32_load_ret) {
        gui_draw_runs(uVar6,uVar17 & 0xffff,(uint)DAT_20802d88,&DAT_2016e3b0);
      }
    }
    else {
      gui_draw_runs(uVar6,uVar17 & 0xffff,(uint)DAT_20802d84,&DAT_2016e3a0);
    }
    bVar21 = SBORROW4(uVar12,be32_load_ret);
    iVar16 = uVar12 - be32_load_ret;
    if ((int)uVar12 < (int)be32_load_ret) {
      bVar21 = SBORROW4(be32_load_ret,uVar19);
      iVar16 = be32_load_ret - uVar19;
    }
    if (iVar16 < 0 != bVar21) {
      gui_draw_runs(uVar6,uVar20,uVar14 & 0xffff,&DAT_2016e400);
      fb_fill_box_t(uVar6,uVar20,uStack_5c & 0xffff,unaff_r7 >> 0x10,unaff_r7 & 0xff,0x7e0);
    }
LAB_20124394:
    bVar21 = SBORROW4(uVar12,be32_load_ret_2);
    iVar16 = uVar12 - be32_load_ret_2;
    if ((int)uVar12 < (int)be32_load_ret_2) {
      bVar21 = SBORROW4(be32_load_ret_2,uVar19);
      iVar16 = be32_load_ret_2 - uVar19;
    }
    if (iVar16 < 0 != bVar21) {
      gui_draw_runs(uVar6,uVar13,(uint)uVar2,&DAT_2016e410);
      fb_fill_box_t(uVar6,uVar13,uVar18 & 0xffff,(unaff_r9 >> 0x10) - 0xd & 0xffff,unaff_r9 & 0xff,
                    0xf800);
    }
    if ((int)uVar12 < (int)be32_load_ret_2) {
      if ((int)be32_load_ret_2 < (int)uVar19) goto LAB_2012442c;
LAB_20124410:
      gui_draw_runs(uVar6,(uint)uVar1,(uint)DAT_20802d90,&DAT_2016e3d0);
      goto LAB_2012442c;
    }
  }
  gui_draw_runs(uVar6,(uint)uVar1,(uint)DAT_20802d8c,&DAT_2016e3c0);
LAB_2012442c:
  if ((((uVar15 & 0x1f) >> 4 != 0) && (param_2 == 0)) && (1 < gui_frame.main_vfo.mode)) {
    fb_fill_box_t(uVar6,uVar7,399,unaff_r7 >> 0x10,1,0xffff);
  }
  return;
}


// ===== scope_markers_update @ 201244d8 (80 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* checks 0x20800482 / 0x208004D0, tail-branches to scope_markers_draw(layout) */

void scope_markers_update(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  char cVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint be32_load_ret;
  uint be32_load_ret_2;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint unaff_r7;
  uint uVar21;
  uint unaff_r9;
  bool bVar22;
  uint local_5c;
  undefined2 uVar4;
  byte gui_frame_flags9_val;
  
  cVar5 = DAT_208004d1;
  if (DAT_20800482 == '\0') {
    if (1 < DAT_208004d0) {
      return;
    }
    bVar22 = false;
  }
  else {
    if ((DAT_20800482 != '\x01') || (1 < DAT_208004d0)) {
      return;
    }
    bVar22 = true;
  }
  uVar7 = fb_get_layer_addr(DAT_208085b8);
  gui_frame_flags9_val = gui_frame.flags9;
  uVar16 = (uint)gui_frame.flags9;
  iVar17 = (uint)gui_frame.scope_flags << 0x1a;
  if (iVar17 < 0) {
    uVar21 = 0x80;
  }
  else {
    uVar21 = 0xc9;
  }
  if (bVar22) {
    if (bVar22) {
      unaff_r9 = _DAT_20800718;
      uVar3 = DAT_20800832;
      uVar4 = DAT_20800830;
      if (iVar17 < 0) {
        unaff_r9 = _DAT_2080071c;
        uVar3 = DAT_20800836;
        uVar4 = DAT_20800834;
      }
      uVar8 = CONCAT22(uVar3,uVar4);
      if (DAT_208004d0 == 1) goto joined_r0x20123fbc;
      goto joined_r0x20123fcc;
    }
  }
  else {
    if (iVar17 < 0) {
      uVar8 = *(uint *)(&DAT_20802d78 + (uint)DAT_208004d2 * 4);
      unaff_r9 = _DAT_20800714;
    }
    else {
      uVar8 = *(uint *)(&DAT_20802d6c + (uint)DAT_208004d2 * 4);
      unaff_r9 = _DAT_20800710;
    }
    if (DAT_208004d0 == 1) {
joined_r0x20123fbc:
      unaff_r7 = uVar8;
      if (-1 < (int)(uVar16 << 0x19)) goto joined_r0x20123fcc;
    }
    else {
joined_r0x20123fcc:
      unaff_r7 = unaff_r9;
      unaff_r9 = unaff_r7;
      if (DAT_208004d0 != 1) goto LAB_20124054;
    }
    if ((int)(uVar16 << 0x1a) < 0) {
      unaff_r9 = uVar8;
    }
  }
LAB_20124054:
  if (iVar17 < 0) {
    uVar8 = 0x80;
  }
  else {
    uVar8 = 0xc9;
  }
  uVar18 = (uint)(short)(DAT_20802d86 + (short)uVar21);
  uVar1 = DAT_20802d8e + (short)uVar21;
  uVar9 = (uint)DAT_20800828;
  uVar10 = (uint)DAT_2080082a;
  uVar11 = (uint)DAT_2080082c;
  uVar12 = (uint)DAT_2080082e;
  be32_load_ret = be32_load(gui_frame.op_freq_be);
  be32_load_ret_2 = be32_load(gui_frame.tx_freq_be);
  uVar19 = gui_frame.span_ccf & 0x1f;
  if (9 < uVar19) {
    uVar19 = 9;
  }
  if (cVar5 == '\0') {
    uVar20 = be32_load(gui_frame.dial_freq_be);
    uVar13 = uVar20 - *(int *)(&UNK_2016d6e8 + uVar19 * 4) / 2;
    uVar20 = uVar20 + *(int *)(&UNK_2016d6e8 + uVar19 * 4) / 2;
  }
  else {
    uVar13 = be32_load(gui_frame.scope_start_be);
    uVar20 = *(int *)(&UNK_2016d6e8 + uVar19 * 4) + uVar13;
  }
  sVar6 = __aeabi_uidivmod((be32_load_ret - uVar13) * 0x317,uVar20 - uVar13);
  local_5c = (uint)(short)(sVar6 + 4);
  bVar22 = SBORROW4(local_5c,10);
  iVar17 = local_5c - 10;
  if (9 < (int)local_5c) {
    bVar22 = SBORROW4(be32_load_ret,uVar13);
    iVar17 = be32_load_ret - uVar13;
  }
  if (iVar17 < 0 == bVar22) {
    if (0x314 < (int)local_5c) {
      local_5c = 0x314;
    }
  }
  else {
    local_5c = 10;
  }
  sVar6 = __aeabi_uidivmod((be32_load_ret_2 - uVar13) * 0x317,uVar20 - uVar13);
  uVar19 = (uint)(short)(sVar6 + 4);
  bVar22 = SBORROW4(uVar19,10);
  iVar17 = uVar19 - 10;
  if (9 < (int)uVar19) {
    bVar22 = SBORROW4(be32_load_ret_2,uVar13);
    iVar17 = be32_load_ret_2 - uVar13;
  }
  if (iVar17 < 0 == bVar22) {
    if (0x314 < (int)uVar19) {
      uVar19 = 0x314;
    }
  }
  else {
    uVar19 = 10;
  }
  DAT_208007d4 = 0;
  DAT_208007d6 = 0;
  uVar14 = uVar21 + 0xd;
  uVar15 = (uint)(short)((short)local_5c + -6);
  uVar2 = (short)uVar19 - 6;
  if (-1 < (char)gui_frame_flags9_val) {
    DAT_208007d4 = 0;
    DAT_208007d6 = 0;
    return;
  }
  if (cVar5 == '\0') {
LAB_201241e8:
    if (cVar5 != '\x01') goto LAB_20124394;
LAB_201242a0:
    bVar22 = SBORROW4(uVar13,be32_load_ret_2);
    iVar17 = uVar13 - be32_load_ret_2;
    uVar21 = uVar13;
    if ((int)uVar13 <= (int)be32_load_ret_2) {
      bVar22 = SBORROW4(be32_load_ret_2,uVar20);
      iVar17 = be32_load_ret_2 - uVar20;
      uVar21 = uVar20;
    }
    if (uVar21 == be32_load_ret_2 || iVar17 < 0 != bVar22) {
      gui_draw_runs(uVar7,uVar14,(uint)uVar2,&DAT_2016e410);
      fb_fill_box_t(uVar7,uVar14,uVar19 & 0xffff,(unaff_r9 >> 0x10) - 0xd & 0xffff,unaff_r9 & 0xff,
                    0xf800);
    }
    if ((int)uVar13 <= (int)be32_load_ret_2) {
      if ((int)be32_load_ret_2 <= (int)uVar20) goto LAB_2012442c;
      goto LAB_20124410;
    }
  }
  else {
    if (cVar5 == '\x01') {
      if ((int)uVar13 < (int)be32_load_ret) {
        if ((int)uVar20 <= (int)be32_load_ret) {
          gui_draw_runs(uVar7,uVar12 + uVar21 & 0xffff,uVar11,&DAT_2016e3f0);
        }
      }
      else {
        gui_draw_runs(uVar7,uVar10 + uVar21 & 0xffff,uVar9,&DAT_2016e3e0);
      }
      gui_draw_runs(uVar7,uVar21,uVar15 & 0xffff,&DAT_2016e400);
      fb_fill_box_t(uVar7,uVar21,local_5c & 0xffff,unaff_r7 >> 0x10,unaff_r7 & 0xff,0x7e0);
      goto LAB_201242a0;
    }
    if (cVar5 != '\x02') goto LAB_201241e8;
    if ((int)uVar13 < (int)be32_load_ret) {
      if ((int)uVar20 <= (int)be32_load_ret) {
        gui_draw_runs(uVar7,uVar18 & 0xffff,(uint)DAT_20802d88,&DAT_2016e3b0);
      }
    }
    else {
      gui_draw_runs(uVar7,uVar18 & 0xffff,(uint)DAT_20802d84,&DAT_2016e3a0);
    }
    bVar22 = SBORROW4(uVar13,be32_load_ret);
    iVar17 = uVar13 - be32_load_ret;
    if ((int)uVar13 < (int)be32_load_ret) {
      bVar22 = SBORROW4(be32_load_ret,uVar20);
      iVar17 = be32_load_ret - uVar20;
    }
    if (iVar17 < 0 != bVar22) {
      gui_draw_runs(uVar7,uVar21,uVar15 & 0xffff,&DAT_2016e400);
      fb_fill_box_t(uVar7,uVar21,local_5c & 0xffff,unaff_r7 >> 0x10,unaff_r7 & 0xff,0x7e0);
    }
LAB_20124394:
    bVar22 = SBORROW4(uVar13,be32_load_ret_2);
    iVar17 = uVar13 - be32_load_ret_2;
    if ((int)uVar13 < (int)be32_load_ret_2) {
      bVar22 = SBORROW4(be32_load_ret_2,uVar20);
      iVar17 = be32_load_ret_2 - uVar20;
    }
    if (iVar17 < 0 != bVar22) {
      gui_draw_runs(uVar7,uVar14,(uint)uVar2,&DAT_2016e410);
      fb_fill_box_t(uVar7,uVar14,uVar19 & 0xffff,(unaff_r9 >> 0x10) - 0xd & 0xffff,unaff_r9 & 0xff,
                    0xf800);
    }
    if ((int)uVar13 < (int)be32_load_ret_2) {
      if ((int)be32_load_ret_2 < (int)uVar20) goto LAB_2012442c;
LAB_20124410:
      gui_draw_runs(uVar7,(uint)uVar1,(uint)DAT_20802d90,&DAT_2016e3d0);
      goto LAB_2012442c;
    }
  }
  gui_draw_runs(uVar7,(uint)uVar1,(uint)DAT_20802d8c,&DAT_2016e3c0);
LAB_2012442c:
  if ((((uVar16 & 0x1f) >> 4 != 0) && (cVar5 == '\0')) && (1 < gui_frame.main_vfo.mode)) {
    fb_fill_box_t(uVar7,uVar8,399,unaff_r7 >> 0x10,1,0xffff);
  }
  return;
}


// ===== scope_draw_frame @ 20124528 (484 bytes)

/* per GUI frame: 3DSS (mode 8/9) or 2D renderers by 0x208004D0/D2 (gui.md Scope drawing) */

void scope_draw_frame(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  iVar2 = fb_get_layer_addr(DAT_208085b8);
  uVar4 = -((int)((uint)gui_frame.scope_flags << 0x1a) >> 0x1f);
  DAT_20800498 = gui_frame.speed_color >> 4 == 5;
  DAT_20800499 = (bool)DAT_20800498 && DAT_208004d0 == 0;
  if ((DAT_20800489 != '\0') &&
     (cVar1 = DAT_20800489 + -1, bVar5 = DAT_20800489 == '\x01', DAT_20800489 = cVar1, bVar5)) {
    scope_freeze_b_set(0);
  }
  if (DAT_20800482 == '\0') {
    if (DAT_208004d0 == 0) {
      if (DAT_20800480 == '\0') {
        if (uVar4 == 0) {
          iVar3 = 0xb4;
        }
        else {
          iVar3 = 0x80;
        }
        scope3d_render_large_thunk(DAT_208007c8,uVar4,0x208007d4,iVar2 + iVar3 * 0x640);
      }
      scope3d_front_large(uVar4,&DAT_208007d4);
    }
    else if (DAT_208004d0 == 1) {
      if (DAT_208004d2 == '\x02') {
        scope2d_draw_expand(uVar4,&DAT_208007d4);
      }
      else if (DAT_208004d2 == '\0') {
        scope2d_draw_size0(uVar4,&DAT_208007d4);
      }
      else {
        scope2d_draw_normal();
      }
    }
  }
  else if (DAT_20800482 == '\x01') {
    if (DAT_208004d0 == 0) {
      if (DAT_20800480 == '\0') {
        if (uVar4 == 0) {
          iVar3 = 0xb4;
        }
        else {
          iVar3 = 0x80;
        }
        scope3d_render_small_thunk(DAT_208007c8,uVar4,0x208007d4,iVar2 + iVar3 * 0x640);
      }
      scope3d_front_small(uVar4,&DAT_208007d4);
    }
    else {
      if (DAT_208004d0 != 1) goto LAB_201246dc;
      scope2d_draw_multi(uVar4,&DAT_208007d4);
    }
    if (DAT_208004d0 < 2) {
      multi_panel_draw(uVar4);
    }
  }
LAB_201246dc:
  DAT_208007c8 = (int)(DAT_208007c8 + 1) % 0x308f4;
  return;
}


// ===== scope_text_view_draw @ 2012470c (1132 bytes)

/* third scope view (0x208004D0 = 3): RX/TX text lines */

uint scope_text_view_draw(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  ushort i;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  
  if ((1 < DAT_20800482) || (DAT_208004d0 != '\x03')) {
    return (gui_frame.scope_flags & 0x3f) >> 5;
  }
  local_28 = fb_get_layer_addr(DAT_208085b8);
  uVar5 = 0;
  fb_clear_rect(local_28,(uint)DAT_208084ea,(uint)DAT_208084e8,(uint)DAT_208084f0,(uint)DAT_208084f2
               );
  fb_clear_rect(local_28,(uint)DAT_208084f6,(uint)DAT_208084f4,(uint)DAT_208084f8,(uint)DAT_208084fa
               );
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_68,&DAT_208f48c8,DAT_208f489a);
  gui_draw_text(local_28,&local_68,DAT_2080850a * (ushort)DAT_208f489c + DAT_208084ee,DAT_208084ec,
                DAT_20808508,&DAT_20800b1c);
  uVar1 = (uint)DAT_208f489b;
  uVar3 = (uint)DAT_208f489d;
  uVar6 = (uint)DAT_208f4bab;
  if (uVar1 < DAT_208f4bab) {
    uVar6 = uVar1;
  }
  if (uVar3 < uVar1) {
    iVar4 = uVar1 - uVar6;
    if (iVar4 < (int)uVar3) {
      uVar6 = uVar1 - uVar3 & 0xff;
    }
    uVar5 = uVar1 - iVar4 & 0xff;
    if (uVar6 < uVar5) {
      uVar1 = uVar5 - uVar6 & 0xff;
    }
    else {
      uVar1 = 0;
    }
    uVar3 = uVar3 - uVar1 & 0xff;
    uVar5 = uVar6;
  }
  else {
    uVar3 = uVar1 - uVar6 & 0xff;
    uVar1 = uVar1 - uVar3 & 0xff;
  }
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_68,&DAT_208f489f + uVar5,uVar1);
  gui_draw_text(local_28,&local_68,DAT_208084fe,DAT_208084fc,DAT_20808508,&DAT_20800fb4);
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_68,&DAT_208f489f + uVar5 + uVar1,uVar3);
  gui_draw_text(local_28,&local_68,DAT_208084fe,DAT_20808508 * uVar1 + (uint)DAT_208084fc & 0xffff,
                (uint)DAT_20808508,&DAT_20800b1c);
  uVar6 = 0x10 - DAT_208f489c & 0xffff;
  if (DAT_208f489e <= uVar6) {
    uVar6 = uVar6 - DAT_208f489e & 0xffff;
  }
  i = 0;
  bVar7 = uVar6 != 0;
  if (DAT_208f489c != 0) {
    do {
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      uVar2 = strlen(&DAT_208f48f1 + uVar6 * 0x29);
      memcpy(&local_68,&DAT_208f48f1 + uVar6 * 0x29,uVar2);
      gui_draw_text(local_28,&local_68,DAT_2080850a * i + DAT_208084ee,DAT_208084ec,DAT_20808508,
                    &DAT_20800b1c);
      i = i + 1;
      uVar6 = uVar6 + 1 & 0xffff;
    } while (i < DAT_208f489c);
  }
  if (bVar7) {
    if (((uint)DAT_208f489c < (uint)DAT_208f4899) &&
       ((int)(uint)DAT_208f489e < (int)((uint)DAT_208f4899 - (uint)DAT_208f489c))) {
      DAT_208f4bef = 1;
      goto LAB_20131eb8;
    }
  }
  DAT_208f4bef = 0;
LAB_20131eb8:
  gui_draw_runs(local_28,(uint)DAT_2080851a + (uint)DAT_20808502 & 0xffff,
                (uint)DAT_20808518 + (uint)DAT_20808500 & 0xffff,&DAT_2016dc58);
  gui_draw_runs(local_28,(uint)DAT_2080851e + (uint)DAT_20808502 & 0xffff,
                (uint)DAT_2080851c + (uint)DAT_20808500 & 0xffff,&DAT_2016dc68);
  uVar6 = (uint)DAT_208f4899;
  uVar5 = (uint)DAT_208f489c;
  if (uVar5 < uVar6) {
    iVar4 = (uVar6 - uVar5) - (uint)DAT_208f489e;
  }
  else {
    iVar4 = 0;
    uVar5 = 0;
    uVar6 = 0;
  }
  uVar6 = FUN_20136584(local_28,DAT_20808522,DAT_20808520,DAT_20808504,DAT_20808506,iVar4,uVar6,
                       uVar5);
  return uVar6;
}


// ===== mainlink_send_audio_error @ 20124744 (200 bytes)

/* (code): E7 (PlayList owner 0x2080048E = 1) or E8 status frame with b1 = 0xFF and the error code
   (mainlink.md) [fact] */

void mainlink_send_audio_error(int param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined1 local_18;
  undefined3 uStack_17;
  uint uStack_14;
  undefined4 local_10;
  
  if (DAT_2080048e == '\x01') {
    uVar2 = 0xe7;
  }
  else {
    uVar2 = 0xe8;
  }
  _local_18 = CONCAT31(0xff,uVar2);
  local_10 = 0;
  if (param_1 == DAT_208007d8) {
    return;
  }
  switch(param_1) {
  case -9:
    bVar3 = 7;
    break;
  case -8:
    bVar3 = 6;
    break;
  default:
    uVar1 = 0xff;
    goto LAB_20124808;
  case -6:
    bVar3 = 5;
    break;
  case -5:
    bVar3 = 4;
    break;
  case -4:
    bVar3 = 3;
    break;
  case -3:
    bVar3 = 2;
    break;
  case -2:
    bVar3 = 1;
    break;
  case -1:
    bVar3 = 0;
  }
  uVar1 = (ushort)bVar3;
LAB_20124808:
  uStack_14 = (uint)(ushort)(uVar1 << 8);
  DAT_208f1221 = 0x7f;
  DAT_208f1220 = 0xff;
  mainlink_queue_frame(&local_18,9);
  DAT_208007d8 = param_1;
  return;
}

