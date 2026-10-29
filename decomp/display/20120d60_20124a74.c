// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20120d60 @ 20120d60 (152 bytes)

undefined4 FUN_20120d60(int param_1,int param_2)

{
  int iVar1;
  byte local_260 [392];
  undefined1 auStack_d8 [200];
  
  FUN_20157214(&DAT_208dce3c,auStack_d8,&DAT_208dd73c,200);
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
  int iVar1;
  undefined1 auStack_1a0 [200];
  byte abStack_d8 [204];
  
  FUN_20157214(&DAT_208dce3c,auStack_1a0,&DAT_208dd73c,200);
  FUN_20134084(abStack_d8,auStack_1a0);
  iVar1 = 0;
  do {
    *(undefined *)(param_3 + iVar1) = (&DAT_208dd23c)[abStack_d8[iVar1]];
    iVar1 = iVar1 + 1;
  } while (iVar1 < 200);
  return 0x2c;
}


// ===== FUN_20120d84 @ 20120d84 (92 bytes)

undefined4 FUN_20120d84(int param_1)

{
  int iVar1;
  byte local_d8 [204];
  
  FUN_20157214(&DAT_208dce3c,local_d8,&DAT_208dd73c,200);
  iVar1 = 0;
  do {
    *(undefined *)(param_1 + iVar1) = (&DAT_208dd23c)[local_d8[iVar1]];
    iVar1 = iVar1 + 1;
  } while (iVar1 < 200);
  return 0x2c;
}


// ===== FUN_20120d90 @ 20120d90 (168 bytes)

void FUN_20120d90(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte local_4b0 [391];
  undefined1 auStack_329 [393];
  undefined1 auStack_1a0 [200];
  undefined1 auStack_d8 [200];
  
  if (DAT_208dd994 == '\0') {
    FUN_20157214(&DAT_208dce3c,auStack_1a0,&DAT_208dd73c,200);
    FUN_20134074(local_4b0,auStack_1a0);
    FUN_20134074(auStack_329,auStack_d8);
    iVar3 = FUN_20164360(&DAT_208f0b14);
    iVar4 = 0;
    do {
      pbVar2 = local_4b0 + iVar4;
      iVar1 = iVar4 * 2;
      iVar4 = iVar4 + 1;
      *(undefined2 *)(&DAT_208dd99c + iVar1 + iVar3 * 0x30e) =
           *(undefined2 *)(&DAT_208dd53c + (uint)*pbVar2 * 2);
    } while (iVar4 < 0x187);
  }
  return;
}


// ===== FUN_20120d98 @ 20120d98 (56 bytes)

undefined * FUN_20120d98(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_20164758(&DAT_208f0b14,~param_1);
  return &DAT_208dd99c + iVar1 * 0x30e;
}


// ===== FUN_20120da4 @ 20120da4 (192 bytes)

void FUN_20120da4(int param_1,int param_2)

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

undefined4 afscope_buf_ptr(void)

{
  return DAT_208dd998;
}


// ===== FUN_20120dd4 @ 20120dd4 (8 bytes)

void FUN_20120dd4(void)

{
  FUN_20157604(&DAT_208dce3c);
  return;
}


// ===== FUN_20120de4 @ 20120de4 (184 bytes)

void FUN_20120de4(void)

{
  undefined1 uVar1;
  int iVar2;
  byte bVar3;
  undefined1 uStack_18;
  byte local_17;
  
  if (DAT_208f0b2a == 'P') {
    if (DAT_20450024 != '\0') {
      bVar3 = 0;
      uVar1 = (&DAT_20801d44 + ((uint)(DAT_208f0bc2 >> 4) % 5) * 3)[(DAT_208f0bc2 & 0xf) % 3];
      iVar2 = mainlink_get_settings24
                        (&uStack_18,&DAT_20801d44 + ((uint)(DAT_208f0bc2 >> 4) % 5) * 3,
                         &DAT_20801d44,(DAT_208f0bc2 & 0xf) * -0x55555555);
      if (iVar2 != 0) {
        bVar3 = local_17 & 0xf;
      }
      usbkbd_set_layout(bVar3);
      usbkbd_capslock_for_mode(uVar1);
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
    if ((DAT_208f0b2a != '{') || (DAT_208f0b2b == '\0')) {
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

undefined4 gui_middle_key(void)

{
  if (DAT_208f0b2a != 0x3a) {
    if (DAT_208f0b2a < 0x3b) {
      if (DAT_208f0b2a == 0x30) {
        if ((DAT_208f0bc2 != '\x05' && DAT_208f0bc2 != '\v') && DAT_208f0bc2 != '\f') {
          return 0xffff;
        }
      }
      else if (DAT_208f0b2a != 0x34 && DAT_208f0b2a != 0x37) {
        return 0xffff;
      }
    }
    else if ((DAT_208f0b2a != 0x40 && DAT_208f0b2a != 0x43) && DAT_208f0b2a != 0x70) {
      return 0xffff;
    }
  }
  return 0x30f;
}


// ===== FUN_20121044 @ 20121044 (256 bytes)

void FUN_20121044(void)

{
  undefined4 uVar1;
  undefined1 local_18 [12];
  
  mouse_middle_get_event(local_18);
  switch(local_18[0]) {
  default:
    goto switchD_20121064_caseD_0;
  case 2:
    DAT_20800470 = gui_middle_key();
    if (DAT_20800470 == -1) {
      return;
    }
    break;
  case 4:
    mainlink_send_touch_key(0,DAT_20800470);
    if (DAT_20800470 == -1) {
      return;
    }
    DAT_20800470 = gui_middle_key();
    break;
  case 5:
    DAT_20800470 = gui_middle_key();
    if (DAT_20800470 == -1) {
      return;
    }
    mainlink_send_touch_key(1,DAT_20800470,0);
  case 1:
    uVar1 = 0;
    goto LAB_201210b8;
  case 6:
    DAT_20800470 = gui_middle_key();
    if (DAT_20800470 != -1) {
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

undefined4 gui_right_key(void)

{
  undefined4 uVar1;
  
  uVar1 = 0xffff;
  if (DAT_208f0b2a == 0x40) {
    uVar1 = 0x12d;
  }
  else if (DAT_208f0b2a < 0x41) {
    if (DAT_208f0b2a == 0x37) {
      uVar1 = 0xf2;
    }
    else if (DAT_208f0b2a < 0x38) {
      if (DAT_208f0b2a == 0x20) {
        if (DAT_208f0b4d < '\0') {
          uVar1 = 0x310;
        }
        else {
          uVar1 = 0x130f;
        }
        return uVar1;
      }
      if (DAT_208f0b2a == 0x30) {
        switch(DAT_208f0bc2) {
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
      if (DAT_208f0b2a == 0x34) {
        uVar1 = 0x199;
      }
    }
    else {
      if (DAT_208f0b2a != 0x39) {
        if (DAT_208f0b2a == 0x3a) {
          uVar1 = 0x11b;
        }
        return uVar1;
      }
      uVar1 = 0x90;
    }
  }
  else if (DAT_208f0b2a == 0x50) {
    uVar1 = 0x284;
  }
  else if (DAT_208f0b2a < 0x51) {
    if (DAT_208f0b2a == 0x41) {
      uVar1 = 0x109;
    }
    else if (DAT_208f0b2a == 0x43) {
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
    if (DAT_208f0b2a != 0x70) {
      if (DAT_208f0b2a == 0x7c) {
        uVar1 = 0x30f;
      }
      return uVar1;
    }
    uVar1 = 0xff;
  }
switchD_20121250_caseD_7:
  return uVar1;
}


// ===== FUN_20121318 @ 20121318 (372 bytes)

void FUN_20121318(void)

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
    if (DAT_2080046e == -1) {
      return;
    }
    break;
  case 4:
    mainlink_send_touch_key(0,DAT_2080046e);
    if (DAT_2080046e == -1) {
      return;
    }
    DAT_2080046e = gui_right_key();
    break;
  case 5:
    DAT_2080046e = gui_right_key();
    if (DAT_2080046e == -1) {
      return;
    }
    if (DAT_208f0b2a == '|') {
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
    if (DAT_2080046e != -1) {
      mainlink_send_touch_key(0,DAT_2080046e);
      if (DAT_208f0b2a == '|') {
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
  if (DAT_208f0b2a != '|') {
    uVar1 = 1;
LAB_201213bc:
    mainlink_send_touch_key(uVar1,DAT_2080046e,0);
    return;
  }
  mainlink_queue_frame(&local_20,4);
switchD_20121348_caseD_0:
  return;
}


// ===== FUN_201214b0 @ 201214b0 (740 bytes)

void FUN_201214b0(int param_1)

{
  short sVar1;
  short sVar2;
  short local_30 [2];
  short local_2c [2];
  undefined1 local_28 [4];
  uint local_24;
  uint local_20;
  
  local_30[0] = 0;
  local_2c[0] = 0;
  pointer_get_event(local_28,param_1);
  sVar1 = (short)local_24;
  sVar2 = (short)local_20;
  if (param_1 != 0) {
    touch_cal_apply((int)(short)local_24,(int)(short)local_20,local_30,local_2c);
    sVar1 = local_30[0];
    sVar2 = local_2c[0];
  }
  local_2c[0] = sVar2;
  local_30[0] = sVar1;
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
    DAT_2080046c = thunk_FUN_2015c048(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (DAT_208f0b2a == '{')) && (DAT_208f0b2b != '\0')))) {
      mainlink_send_touch_key(1,DAT_2080046c,(int)local_30[0]);
    }
    break;
  case 3:
    DAT_2080047c = DAT_2080047c + 1;
    return;
  case 4:
    if (((DAT_2080046c & 0x1000) != 0) || (DAT_2080046c == 0x1ff)) {
      mainlink_send_touch_key(0,DAT_2080046c);
    }
    DAT_2080046c = thunk_FUN_2015c048(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (DAT_208f0b2a == '{')) && (DAT_208f0b2b != '\0')))) {
      mainlink_send_touch_key(1,DAT_2080046c,(int)local_30[0]);
    }
    break;
  case 5:
    DAT_2080046c = thunk_FUN_2015c048(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (DAT_208f0b2a == '{')) && (DAT_208f0b2b != '\0')))) {
      mainlink_send_touch_key(1,DAT_2080046c,(int)local_30[0]);
      mainlink_send_touch_key(0,DAT_2080046c);
    }
    break;
  case 6:
    DAT_2080046c = thunk_FUN_2015c048(local_30[0],local_2c[0]);
    if (((DAT_2080046c & 0x1000) != 0) || (DAT_2080046c == 0x1ff)) {
      mainlink_send_touch_key(0,DAT_2080046c);
    }
    if (((DAT_2080046c & 0x1000) != 0) ||
       (((DAT_2080046c == 0x1ff && (DAT_208f0b2a == '{')) && (DAT_208f0b2b != '\0')))) {
      mainlink_send_touch_key(1,DAT_2080046c,(int)local_30[0]);
      mainlink_send_touch_key(0,DAT_2080046c);
    }
    if (param_1 == 0) {
      return;
    }
    goto LAB_201215e0;
  }
  if (param_1 != 0) {
LAB_201215e0:
    mouse_cursor_set_pos(local_30[0],local_2c[0]);
    return;
  }
switchD_20121518_caseD_0:
  return;
}


// ===== FUN_201217b0 @ 201217b0 (128 bytes)

void FUN_201217b0(void)

{
  undefined4 in_r3;
  undefined4 local_8;
  
  local_8 = in_r3;
  FUN_20120de4();
  local_8 = 0;
  if ((DAT_208f0b2a == '{') && (DAT_208f0b2b != '\0')) {
    local_8 = 0xe4;
    if (DAT_20800487 != '\0') {
      DAT_20800487 = 0;
      DAT_20800488 = 1;
      mainlink_queue_frame(&local_8,4);
      return;
    }
  }
  FUN_201214b0(0);
  FUN_201214b0(1);
  FUN_20121318();
  FUN_20121044();
  return;
}


// ===== mainlink_send_e6 @ 20121830 (40 bytes)

void mainlink_send_e6(undefined1 param_1)

{
  undefined4 local_8;
  
  local_8 = (uint)CONCAT11(param_1,0xe6);
  mainlink_queue_frame(&local_8,4);
  return;
}


// ===== mainlink_send_e0 @ 20121858 (64 bytes)

/* E0 with a given flag byte and 16-bit code */

void mainlink_send_e0(undefined1 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  local_10._0_2_ = CONCAT11(param_1,0xe0);
  local_10 = CONCAT13((char)param_2,CONCAT12((char)((uint)param_2 >> 8),(undefined2)local_10)) &
             0xffefffff;
  mainlink_queue_frame(&local_10,5);
  return;
}


// ===== FUN_201218a4 @ 201218a4 (168 bytes)

void FUN_201218a4(void)

{
  undefined2 local_18 [2];
  undefined2 local_14 [2];
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  mouse_cursor_get_pos(local_14,local_18);
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

void FUN_2012194c(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(byte *)(param_1 + 0x9a) & 0x1f;
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


// ===== FUN_201219b8 @ 201219b8 (312 bytes)

void FUN_201219b8(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  fb_fill_rect(param_1,0x821,param_2,param_3,0xce,0x10);
  fb_fill_box_t(param_1,param_2 + 2U & 0xffff,param_3,0xc,1,0x4a69);
  fb_fill_box_t(param_1,param_2 + 2U & 0xffff,param_3 + 0xcdU & 0xffff,0xc,1,0x4a69);
  fb_fill_box(param_1,param_2,param_3 + 2U & 0xffff,0xca,1,0x4a69);
  fb_fill_box(param_1,param_2 + 0xfU & 0xffff,param_3 + 2U & 0xffff,0xca,1,0x4a69);
  gui_draw_runs(param_1,param_2,param_3,&DAT_2016e258);
  uVar1 = 0;
  if (100 < param_4) {
    param_4 = 100;
  }
  if ((param_4 & 0x7fffffff) != 0) {
    do {
      fb_blit_raw(param_1,(uint)DAT_208006fe + param_2 & 0xffff,
                  (uint)DAT_208006fc + param_3 + uVar1 & 0xffff,&DAT_2016e268,1,10);
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < param_4 << 1);
  }
  return;
}


// ===== FUN_20121af0 @ 20121af0 (160 bytes)

void FUN_20121af0(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  byte local_f0 [204];
  
  param_2 = param_2 * 800;
  iVar2 = FUN_20120d84(local_f0);
  iVar6 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = 0;
      sVar1 = (&DAT_2016d390)[iVar6];
      if (param_3 < param_4 + param_3) {
        iVar5 = param_3;
        do {
          if ((iVar2 - iVar6 <= (int)(uint)local_f0[iVar3]) &&
             (psVar4 = (short *)(param_1 + (iVar5 + param_2) * 2), *psVar4 == 0)) {
            *psVar4 = sVar1;
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar5 < param_4 + param_3);
      }
      iVar6 = iVar6 + 1;
      param_2 = param_2 + 800;
    } while (iVar6 < iVar2);
  }
  return;
}


// ===== FUN_20121b90 @ 20121b90 (172 bytes)

void FUN_20121b90(int param_1,int param_2,int param_3,undefined2 *param_4)

{
  undefined2 uVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar1 = *param_4;
  iVar4 = 0;
  uVar5 = 0;
  if (*(int *)(param_4 + 2) != 0) {
    do {
      uVar3 = (uint)*(ushort *)(*(int *)(param_4 + 4) + uVar5 * 4 + 2);
      uVar6 = (uint)*(ushort *)(*(int *)(param_4 + 4) + uVar5 * 4);
      while (uVar3 != 0) {
        uVar3 = uVar3 - 1;
        uVar7 = __aeabi_uidivmod(uVar6,uVar1);
        psVar2 = (short *)(param_1 + (param_3 + param_2 * 800) * 2 +
                          (int)((ulonglong)uVar7 >> 0x20) * 2 + (int)uVar7 * 0x640);
        if (*psVar2 == 0) {
          *psVar2 = *(short *)(*(int *)(param_4 + 6) + iVar4 * 2);
        }
        iVar4 = iVar4 + 1;
        uVar6 = uVar6 + 1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_4 + 2));
  }
  return;
}


// ===== scr_screen_saver @ 20121c3c (196 bytes)

/* packet 0x7B: YAESU logo hopping between 3 places every 180 frames */

void scr_screen_saver(void)

{
  short sVar1;
  undefined4 uVar2;
  bool bVar3;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  if (DAT_208004ca == 0) {
    FUN_20155274(uVar2,0xbb800);
    layer_hide(3);
    layer_hide(4);
    layer_hide(6);
    layer_fade(5,1);
    gui_draw_runs(uVar2,*(undefined2 *)(&DAT_20800842 + (uint)DAT_208004cc * 4),
                  *(undefined2 *)(&DAT_20800840 + (uint)DAT_208004cc * 4),&DAT_2016d2c0);
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
  iVar1 = FUN_20103ba0();
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
  if (DAT_208f0b2a == '{') {
    if (DAT_208f0b2b != '\0') {
      DAT_208004c8 = 9;
      return;
    }
  }
  else if (DAT_208f0b2a == '#') {
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
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  undefined4 uVar5;
  byte local_260 [12];
  byte local_254;
  byte local_252;
  byte local_251;
  byte local_24f;
  byte local_24e;
  byte local_200;
  char local_1c8;
  
  uVar2 = fb_get_layer_addr(DAT_208085b8);
  mainlink_get_last_frame(local_260);
  cVar1 = DAT_208f0b2a;
  if (((DAT_208f0b2a == 'p') && (local_260[0] == 0x30)) && (local_1c8 == -1)) {
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
  if ((DAT_208f4634 == '\0') && ((DAT_208f4633 == '\0' || (cVar1 != '7')))) {
    if ((local_260[0] == 0x20 || local_260[0] == 0x37) || local_260[0] == 0x39) {
      fb_clear_rect(uVar2,DAT_2080065e,DAT_2080065c,0x30,0x13);
      bVar4 = local_251 & 0xc0;
      if (bVar4 == 0x40) {
        gui_draw_runs(uVar2,DAT_20800662,DAT_20800660,&DAT_2016ddfc);
      }
      else if (bVar4 == 0x80) {
        gui_draw_runs(uVar2,DAT_20800662,DAT_20800660,&DAT_2016dddc);
      }
      else if (bVar4 == 0xc0) {
        gui_draw_runs(uVar2,DAT_2080065e,DAT_2080065c,&DAT_2016de0c);
      }
    }
    bVar4 = local_200 & 3;
    fb_clear_rect(uVar2,DAT_20800666,DAT_20800664,0x2c,0x13);
    if (bVar4 == 1) {
      gui_draw_runs(uVar2,DAT_20800666,DAT_20800664,&DAT_2016de8c);
    }
    else if (bVar4 == 2) {
      gui_draw_runs(uVar2,DAT_20800666,DAT_20800664,&DAT_2016de7c);
    }
    uVar3 = (uint)local_200;
    fb_clear_rect(uVar2,DAT_2080066a,DAT_20800668,0x16,0x13);
    if ((int)(uVar3 << 0x1c) < 0) {
      gui_draw_runs(uVar2,DAT_2080066a,DAT_20800668,&DAT_2016deac);
    }
    uVar3 = (uint)local_200;
    fb_clear_rect(uVar2,DAT_2080066e,DAT_2080066c,0x22,0x13);
    if ((int)(uVar3 << 0x1b) < 0) {
      gui_draw_runs(uVar2,DAT_2080066e,DAT_2080066c,&DAT_2016de6c);
    }
    fb_clear_rect(uVar2,DAT_20800672,DAT_20800670,0x2c,0xf);
    if ((int)((uint)local_200 << 0x1d) < 0) {
      gui_draw_runs(uVar2,DAT_20800672,DAT_20800670,&DAT_2016de9c);
    }
    if ((DAT_208f4631 == '\0') && (DAT_208f4632 == '\0')) {
      if (DAT_208f4630 == '\0') {
        uVar5 = 0xb4;
      }
      else {
        uVar5 = 0x6d;
      }
      bVar4 = local_252 & 3;
      fb_clear_rect(uVar2,uVar5,DAT_208004b2,0x11,0x11);
      if (bVar4 == 1) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b2,&DAT_2016de1c);
      }
      else if (bVar4 == 3) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b2,&DAT_2016de2c);
      }
      bVar4 = local_251 & 3;
      fb_clear_rect(uVar2,uVar5,DAT_208004b4,0x22,0x13);
      if (bVar4 == 1) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b4,&DAT_2016ddac);
      }
      else if (bVar4 == 2) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b4,&DAT_2016de3c);
      }
      uVar3 = (uint)local_252;
      fb_clear_rect(uVar2,uVar5,DAT_208004b0,0x2d,0x13);
      if ((int)(uVar3 << 0x1d) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b0,&DAT_2016dd8c);
      }
      uVar3 = (uint)local_252;
      fb_clear_rect(uVar2,uVar5,DAT_208004ac,0x28,0x13);
      if ((int)(uVar3 << 0x1b) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004ac,&DAT_2016ddcc);
      }
      fb_clear_rect(uVar2,uVar5,DAT_208004b6,0x22,0x13);
      if ((int)((uint)local_254 << 0x1b) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004b6,&DAT_2016dd9c);
      }
      uVar3 = (uint)local_252;
      fb_clear_rect(uVar2,uVar5,DAT_208004a8,0x2e,0x13);
      if ((int)(uVar3 << 0x19) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004a8,&DAT_2016ddec);
      }
      fb_clear_rect(uVar2,uVar5,DAT_208004aa,0x39,0x13);
      if ((int)((uint)local_252 << 0x1a) < 0) {
        gui_draw_runs(uVar2,uVar5,DAT_208004aa,&DAT_2016ddbc);
      }
      uVar3 = (local_251 & 0x1f) >> 3;
      fb_clear_rect(uVar2,uVar5,DAT_208004ae,0x2d,0x13);
      if (uVar3 == 1) {
        gui_draw_runs(uVar2,uVar5,DAT_208004ae,&DAT_2016de4c);
      }
      else if (uVar3 == 2) {
        gui_draw_runs(uVar2,uVar5,DAT_208004ae,&DAT_2016de5c);
      }
      if (DAT_208f4633 == '\0') {
        uVar3 = (uint)(local_24f >> 6);
        fb_clear_rect(uVar2,uVar5,DAT_208004b8,*DAT_208025e4,DAT_208025e4[1]);
        if (2 < uVar3) {
          uVar3 = 2;
        }
        gui_draw_runs(uVar2,uVar5,DAT_208004b8,(&DAT_208025e4)[uVar3]);
        uVar3 = (uint)(local_24e >> 4);
        fb_clear_rect(uVar2,uVar5,DAT_208004ba,*(undefined2 *)PTR_DAT_208025f0,
                      *(undefined2 *)(PTR_DAT_208025f0 + 2));
        if (5 < uVar3) {
          uVar3 = 5;
        }
        gui_draw_runs(uVar2,uVar5,DAT_208004ba,(&PTR_DAT_208025f0)[uVar3]);
        uVar3 = local_24f & 0x1f;
        fb_clear_rect(uVar2,uVar5,DAT_208004bc,0x2d,0x13);
        fb_clear_rect(uVar2,uVar5,DAT_208004be,*(undefined2 *)PTR_DAT_20802608,
                      *(undefined2 *)(PTR_DAT_20802608 + 2));
        gui_draw_runs(uVar2,uVar5,DAT_208004bc,&DAT_2016debc);
        if (9 < uVar3) {
          uVar3 = 9;
        }
        gui_draw_runs(uVar2,uVar5,DAT_208004be,(&PTR_DAT_20802608)[uVar3]);
      }
    }
    memcpy(&DAT_208f0d8b,local_260,0x240);
  }
  return;
}


// ===== FUN_201224c8 @ 201224c8 (160 bytes)

void FUN_201224c8(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  
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
    sVar3 = DAT_208007e4 + 0x1bb;
    sVar1 = DAT_208007e6 + 0x1bb;
    FUN_20121b90(param_1,0x81,DAT_208007e4 + 0x1b1,&DAT_2016d66c);
    FUN_20121b90(param_1,0x81,sVar1,&DAT_2016d67c);
    uVar2 = 0;
    if (sVar1 != sVar3) {
      do {
        FUN_20121b90(param_1,0x81,sVar3 + uVar2,&DAT_2016d65c);
        uVar2 = uVar2 + 1;
      } while (uVar2 < (ushort)(sVar1 - sVar3));
      return;
    }
  }
  return;
}


// ===== FUN_20122638 @ 20122638 (356 bytes)

void FUN_20122638(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

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

void FUN_201227d8(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint unaff_r6;
  uint unaff_r7;
  uint uVar6;
  int iVar7;
  
  bVar2 = false;
  iVar7 = 0;
  uVar3 = (uint)DAT_208f0b92;
  bVar1 = DAT_208f0b92 >> 7;
  uVar6 = (DAT_208f0b93 & 0x3f) >> 4;
  iVar5 = (uint)DAT_208f0b4c * 10;
  uVar4 = be16_load(&DAT_208f0b9d);
  uVar4 = uVar4 & 0xffff;
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
    if ((DAT_208f0b43 & 0x80) == 0) {
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


// ===== FUN_20122d00 @ 20122d00 (772 bytes)

void FUN_20122d00(short *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
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
    uVar3 = be16_load(&DAT_208f0b9d);
    sVar4 = (short)(((uVar3 & 0xffff) * 10) / 200) + 0x4e;
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
    iVar1 = ((int)*(short *)(&DAT_2016d288 + (uint)(DAT_208f0b92 >> 7) * 2) +
            (int)*(short *)(&DAT_2016d29e + (DAT_208f0b92 & 3) * 2) / 2) * 10;
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
    iVar1 = *(short *)(&DAT_2016d298 + ((DAT_208f0b93 & 0x3f) >> 4) * 2) * 10;
    sVar4 = (((short)(iVar1 / 200) +
             (*(short *)(&DAT_2016d298 + ((DAT_208f0b93 & 0x3f) >> 4) * 2) >> 0xf)) -
            (short)((longlong)iVar1 * 0x51eb851f >> 0x3f)) + 0x4e;
    sVar5 = *(short *)(&UNK_2016d542 + uVar6 * 6) + sVar4;
    sVar2 = *(short *)(&UNK_2016d544 + uVar6 * 6) + sVar4;
  }
  *param_1 = sVar4;
  param_1[1] = sVar5;
  param_1[2] = sVar2;
  return;
}


// ===== FUN_20123088 @ 20123088 (784 bytes)

void FUN_20123088(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  undefined1 uVar8;
  short sVar9;
  int iVar10;
  ushort uVar11;
  ushort uVar12;
  int iVar13;
  uint uVar14;
  undefined4 local_28;
  
  uVar4 = (ushort)DAT_208f0b4c;
  iVar13 = (uint)DAT_208f0b4d << 0x1d;
  uVar14 = DAT_208f0b4d & 3;
  uVar11 = (ushort)DAT_208f0b48 + (ushort)DAT_208f0b47 * 0x100;
  if (uVar11 < 0x32) {
    uVar11 = 0x32;
  }
  if (16000 < uVar11) {
    uVar11 = 16000;
  }
  local_28 = param_4;
  iVar7 = be16_load(&DAT_208f0b49);
  if (iVar7 < -0x4b0) {
    iVar7 = -0x4b0;
  }
  uVar12 = (ushort)DAT_208f0b57;
  if (0x4b0 < iVar7) {
    iVar7 = 0x4b0;
  }
  if (0xf < uVar12) {
    uVar12 = 0xf;
  }
  uVar5 = be16_load(&DAT_208f0b45);
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  if (0x140 < uVar5) {
    uVar5 = 0x140;
  }
  local_28 = CONCAT31(CONCAT21(local_28._2_2_,DAT_208f0b44),DAT_208f0b43) & 0xffffff7f;
  uVar6 = be16_load(&local_28);
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  if (0x140 < uVar6) {
    uVar6 = 0x140;
  }
  iVar10 = (int)DAT_208f0b4b;
  param_1[1] = (byte)((uint)iVar13 >> 0x1f);
  if (iVar10 < -0x19) {
    iVar10 = -0x19;
  }
  if (0x19 < iVar10) {
    iVar10 = 0x19;
  }
  sVar9 = (short)iVar10 * 10;
  if ((uVar14 == 3) && (iVar13 < 0)) {
    *param_1 = 4;
  }
  else {
    *param_1 = (char)uVar14;
  }
  *(ushort *)(param_1 + 6) = uVar12;
  *(short *)(param_1 + 10) = (short)iVar7;
  param_1[8] = (byte)(((uint)DAT_208f0b4d << 0x1a) >> 0x1f);
  *(ushort *)(param_1 + 0xe) = uVar11;
  param_1[0x10] = (byte)(((uint)DAT_208f0b4d << 0x1b) >> 0x1f);
  *(ushort *)(param_1 + 0x1a) = uVar5 * 10;
  bVar1 = (byte)(((uint)DAT_208f0b37 << 0x1b) >> 0x1f);
  param_1[0x18] = bVar1;
  *(ushort *)(param_1 + 0x1e) = uVar6 * 10;
  bVar2 = (byte)(((uint)DAT_208f0b37 << 0x1a) >> 0x1f);
  param_1[0x1c] = bVar2;
  *(ushort *)(param_1 + 0x22) = sVar9 + uVar4 * 10;
  *(short *)(param_1 + 0x26) = sVar9;
  bVar3 = (byte)(((uint)DAT_208f0b37 << 0x19) >> 0x1f);
  param_1[0x20] = bVar3;
  *(ushort *)(param_1 + 0x28) = uVar4 * 10;
  param_1[0x19] = bVar1;
  param_1[0x1d] = bVar2;
  param_1[0x21] = bVar3;
  switch(uVar12) {
  case 0:
  case 1:
    param_1[2] = 0;
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) == sVar9) break;
LAB_201232ac:
    uVar8 = 1;
    goto LAB_201232b0;
  case 2:
  case 3:
    param_1[2] = 1;
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) != sVar9) goto LAB_201232ac;
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
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) != sVar9) goto LAB_201232ac;
    break;
  case 0xc:
  case 0xd:
    param_1[2] = 5;
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) != sVar9) goto LAB_201232ac;
    break;
  case 0xe:
    param_1[2] = 6;
    sVar9 = (ushort)DAT_208f0b3e + (ushort)DAT_208f0b3d * 0x100;
    *(short *)(param_1 + 0x16) = sVar9;
    param_1[8] = iVar7 != 0;
    *(ushort *)(param_1 + 0x12) = uVar11;
    if (*(short *)(param_1 + 0xe) != sVar9) goto LAB_201232ac;
    break;
  default:
    param_1[8] = 1;
    param_1[0x10] = 1;
    goto LAB_201233c4;
  }
  uVar8 = 0;
LAB_201232b0:
  param_1[0x10] = uVar8;
LAB_201233c4:
  param_1[0x2a] = (byte)(((uint)DAT_208f0b4d << 0x19) >> 0x1f);
  return;
}


// ===== FUN_201233d4 @ 201233d4 (472 bytes)

void FUN_201233d4(void)

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
    iVar8 = FUN_20133640();
  }
  else {
    iVar8 = 0;
  }
  iVar2 = fb_get_layer_addr(DAT_208085b8);
  iVar3 = fb_get_layer_addr(DAT_208085b8);
  uVar4 = (uint)DAT_208f0b2f;
  uVar5 = (uint)DAT_208f0b34;
  FUN_20123088(&DAT_208f4600);
  uVar1 = DAT_208f4606;
  uVar7 = (uint)DAT_208f4628;
  iVar9 = (int)DAT_208f460a;
  uVar6 = (uint)DAT_208f4616;
  FUN_20122d00(&DAT_208007dc,DAT_208f4606,DAT_208f460e,uVar7);
  FUN_20122d00(&DAT_208007e2,uVar1,uVar6,uVar7);
  if (-1 < (int)(uVar4 << 0x1a)) {
    if (iVar8 != 0) {
      iVar3 = iVar8 + -0x2a940;
    }
    fb_fill_rect(iVar3,0,0x6d,0x1bb,0x164,0x45);
    gui_draw_runs(iVar3,0x6d,0x1bb,&DAT_2016d380);
    if ((DAT_2080048a == '\0') && (FUN_20122b48(iVar3), DAT_2080048a == '\0')) {
      FUN_20122638(iVar3,uVar1,iVar9,1);
    }
    else if ((DAT_208f0b34 & 0x80) != 0) {
      iVar9 = ((uVar5 & 0x7f) >> 4) * 4;
      DAT_208007de = *(undefined2 *)(&DAT_2016d5be + iVar9);
      DAT_208007e0 = *(undefined2 *)(&DAT_2016d5c0 + iVar9);
      FUN_20122638(iVar3,uVar1,0);
    }
    if ((DAT_208f0b33 & 8) != 0) {
      FUN_20121af0(iVar3,0x81,0x209,200);
    }
    FUN_201224c8(iVar3,uVar1);
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


// ===== FUN_201235ac @ 201235ac (604 bytes)

void FUN_201235ac(undefined4 param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  bool bVar5;
  
  cVar3 = DAT_208f4601;
  cVar2 = DAT_208f4600;
  bVar5 = DAT_208f4608 != '\0';
  if (bVar5) {
    uVar4 = 0xfc00;
  }
  else {
    uVar4 = 0x8410;
  }
  if (DAT_208f4600 == '\0') {
    fb_fill_rect(param_1,uVar4,0x116,0x1bb,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x1bb,(&DAT_208008c8)[bVar5]);
  }
  else {
    gui_draw_runs(param_1,0x127,0x1bb,(&DAT_208008d0)[bVar5]);
  }
  bVar5 = DAT_208f4610 != '\0';
  if (bVar5) {
    uVar4 = 0xfc00;
  }
  else {
    uVar4 = 0x8410;
  }
  if (cVar2 == '\x01') {
    fb_fill_rect(param_1,uVar4,0x116,0x214,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x214,(&DAT_208008d8)[bVar5]);
  }
  else {
    gui_draw_runs(param_1,0x127,0x214,(&DAT_208008e0)[bVar5]);
  }
  bVar5 = DAT_208f4618 != '\0';
  if (bVar5) {
    uVar4 = 0xfc00;
  }
  else {
    uVar4 = 0x8410;
  }
  if (cVar2 == '\x02') {
    fb_fill_rect(param_1,uVar4,0x116,0x26d,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x26d,(&DAT_208008e8)[bVar5]);
  }
  else {
    gui_draw_runs(param_1,0x127,0x26d,(&DAT_208008f0)[bVar5]);
  }
  if (cVar3 != '\0') {
    if (DAT_208f4620 == '\0') {
      uVar4 = 0x8410;
    }
    else {
      uVar4 = 0xfc00;
    }
    uVar1 = (uint)(DAT_208f4620 != '\0');
    if (cVar2 == '\x04') {
      fb_fill_rect(param_1,uVar4,0x116,0x2c6,0x58,0x31);
      gui_draw_runs(param_1,0x127,0x2c6,*(undefined4 *)(uVar1 * 4 + 0x20800908));
      return;
    }
    gui_draw_runs(param_1,0x127,0x2c6,(&DAT_20800910)[uVar1]);
    return;
  }
  bVar5 = DAT_208f461c != '\0';
  if (bVar5) {
    uVar4 = 0xfc00;
  }
  else {
    uVar4 = 0x8410;
  }
  if (cVar2 == '\x03') {
    fb_fill_rect(param_1,uVar4,0x116,0x2c6,0x58,0x31);
    gui_draw_runs(param_1,0x127,0x2c6,(&DAT_208008f8)[bVar5]);
    return;
  }
  gui_draw_runs(param_1,0x127,0x2c6,(&DAT_20800900)[bVar5]);
  return;
}


// ===== FUN_20123808 @ 20123808 (68 bytes)

void FUN_20123808(undefined4 param_1)

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
  gui_draw_runs(param_1,0xd0,0x2f7,*(undefined4 *)(&DAT_208007f0 + uVar1 * 4));
  return;
}


// ===== FUN_2012384c @ 2012384c (884 bytes)

void FUN_2012384c(undefined4 param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined4 local_48;
  undefined4 local_44;
  undefined *local_40 [5];
  undefined4 local_2c;
  int iStack_28;
  
  uVar6 = 0;
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
    uVar6 = *(undefined4 *)(&DAT_208008a0 + (uint)DAT_208f4608 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4608 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f460a);
      sVar1 = FUN_20155122(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x01') {
    uVar6 = *(undefined4 *)(&DAT_208008a8 + (uint)DAT_208f4610 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4610 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f4612);
      sVar1 = FUN_20155122(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x02') {
    uVar6 = *(undefined4 *)(&DAT_208008b0 + (uint)DAT_208f4618 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4618 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f461a);
      sVar1 = FUN_20155122(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x03') {
    uVar6 = *(undefined4 *)(&DAT_208008b8 + (uint)DAT_208f461c * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f461c == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f461e);
      sVar1 = FUN_20155122(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  else if (DAT_208f4600 == '\x04') {
    uVar6 = *(undefined4 *)(&DAT_208008c0 + (uint)DAT_208f4620 * 4);
    if (DAT_208f462a != '\0') {
      if (DAT_208f4620 == 0) {
        puVar5 = (undefined *)0x208034d0;
      }
      else {
        puVar5 = &DAT_20803350;
      }
      sprintf(&local_48,"%dHz",(int)DAT_208f4626);
      sVar1 = FUN_20155122(&local_48);
      gui_draw_text(local_2c,&local_48,0xe2,sVar1 * -0x1b + 0x2ed,0x1b,puVar5);
    }
  }
  gui_draw_runs(local_2c,0xe4,0x1c1,uVar6);
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
    iVar8 = FUN_20133640();
  }
  else {
    iVar8 = 0;
  }
  iVar4 = fb_get_layer_addr(DAT_208085b8);
  iVar5 = fb_get_layer_addr(DAT_208085b8);
  iVar6 = fb_get_layer_addr(DAT_208085bc);
  FUN_20123088(&DAT_208f4600);
  uVar3 = DAT_208f4628;
  uVar2 = DAT_208f4616;
  uVar1 = DAT_208f4606;
  iVar10 = (int)DAT_208f460a;
  FUN_20122d00(&DAT_208007dc,DAT_208f4606,DAT_208f460e,DAT_208f4628);
  FUN_20122d00(&DAT_208007e2,uVar1,uVar2,uVar3);
  if (iVar8 != 0) {
    iVar5 = iVar8 + -0x2a940;
  }
  if ((((DAT_208f0b2a == '0' || DAT_208f0b2a == 'b') || DAT_208f0b2a == 'P') ||
      (iVar9 = iVar5, DAT_208f4630 != '\0')) && (iVar9 = iVar6, DAT_208f0b2a != 'P')) {
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
  FUN_20122638(iVar9,uVar1,iVar10,1);
  if ((DAT_208f0b33 & 8) != 0) {
    FUN_20121af0(iVar9,0x81,0x209,200);
  }
  FUN_201224c8(iVar9,uVar1);
  FUN_2012384c(iVar6,DAT_208007e2);
  FUN_20123808(iVar6);
  FUN_201235ac(iVar6);
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


// ===== FUN_201244d8 @ 201244d8 (1544 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_201244d8(void)

{
  short sVar1;
  int iVar2;
  undefined2 uVar3;
  char cVar5;
  undefined2 uVar6;
  short sVar7;
  undefined2 uVar8;
  short sVar9;
  byte bVar10;
  short sVar11;
  short sVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint unaff_r7;
  short sVar23;
  uint unaff_r9;
  bool bVar24;
  uint local_5c;
  undefined2 uVar4;
  
  cVar5 = DAT_208004d1;
  if (DAT_20800482 == '\0') {
    if (1 < DAT_208004d0) {
      return;
    }
    bVar24 = false;
  }
  else {
    if ((DAT_20800482 != '\x01') || (1 < DAT_208004d0)) {
      return;
    }
    bVar24 = true;
  }
  uVar13 = fb_get_layer_addr(DAT_208085b8);
  bVar10 = DAT_208f0b33;
  sVar9 = DAT_2080082e;
  uVar8 = DAT_2080082c;
  sVar7 = DAT_2080082a;
  uVar6 = DAT_20800828;
  uVar18 = (uint)DAT_208f0b33;
  iVar19 = (uint)DAT_208f0b2f << 0x1a;
  if (iVar19 < 0) {
    sVar23 = 0x80;
  }
  else {
    sVar23 = 0xc9;
  }
  if (bVar24) {
    if (bVar24) {
      unaff_r9 = _DAT_20800718;
      uVar3 = DAT_20800832;
      uVar4 = DAT_20800830;
      if (iVar19 < 0) {
        unaff_r9 = _DAT_2080071c;
        uVar3 = DAT_20800836;
        uVar4 = DAT_20800834;
      }
      uVar20 = CONCAT22(uVar3,uVar4);
      if (DAT_208004d0 == 1) goto joined_r0x20123fbc;
      goto joined_r0x20123fcc;
    }
  }
  else {
    if (iVar19 < 0) {
      uVar20 = *(uint *)(&DAT_20802d78 + (uint)DAT_208004d2 * 4);
      unaff_r9 = _DAT_20800714;
    }
    else {
      uVar20 = *(uint *)(&DAT_20802d6c + (uint)DAT_208004d2 * 4);
      unaff_r9 = _DAT_20800710;
    }
    if (DAT_208004d0 == 1) {
joined_r0x20123fbc:
      unaff_r7 = uVar20;
      if (-1 < (int)(uVar18 << 0x19)) goto joined_r0x20123fcc;
    }
    else {
joined_r0x20123fcc:
      unaff_r7 = unaff_r9;
      unaff_r9 = unaff_r7;
      if (DAT_208004d0 != 1) goto LAB_20124054;
    }
    if ((int)(uVar18 << 0x1a) < 0) {
      unaff_r9 = uVar20;
    }
  }
LAB_20124054:
  if (iVar19 < 0) {
    uVar14 = 0x80;
  }
  else {
    uVar14 = 0xc9;
  }
  uVar20 = (uint)(short)(DAT_20802d86 + sVar23);
  sVar1 = DAT_20802d8e + sVar23;
  iVar19 = be32_load(&DAT_208f0b9f);
  iVar15 = be32_load(&DAT_208f0ba3);
  uVar21 = DAT_208f0b3b & 0x1f;
  if (9 < uVar21) {
    uVar21 = 9;
  }
  if (cVar5 == '\0') {
    iVar22 = be32_load(&DAT_208f0ba7);
    iVar16 = iVar22 - *(int *)(&UNK_2016d6e8 + uVar21 * 4) / 2;
    iVar22 = iVar22 + *(int *)(&UNK_2016d6e8 + uVar21 * 4) / 2;
  }
  else {
    iVar16 = be32_load(&DAT_208f0bab);
    iVar22 = *(int *)(&UNK_2016d6e8 + uVar21 * 4) + iVar16;
  }
  sVar11 = FUN_20156260((iVar19 - iVar16) * 0x317,iVar22 - iVar16);
  local_5c = (uint)(short)(sVar11 + 4);
  bVar24 = SBORROW4(local_5c,10);
  iVar2 = local_5c - 10;
  if (9 < (int)local_5c) {
    bVar24 = SBORROW4(iVar19,iVar16);
    iVar2 = iVar19 - iVar16;
  }
  if (iVar2 < 0 == bVar24) {
    if (0x314 < (int)local_5c) {
      local_5c = 0x314;
    }
  }
  else {
    local_5c = 10;
  }
  sVar11 = FUN_20156260((iVar15 - iVar16) * 0x317,iVar22 - iVar16);
  uVar21 = (uint)(short)(sVar11 + 4);
  bVar24 = SBORROW4(uVar21,10);
  iVar2 = uVar21 - 10;
  if (9 < (int)uVar21) {
    bVar24 = SBORROW4(iVar15,iVar16);
    iVar2 = iVar15 - iVar16;
  }
  if (iVar2 < 0 == bVar24) {
    if (0x314 < (int)uVar21) {
      uVar21 = 0x314;
    }
  }
  else {
    uVar21 = 10;
  }
  DAT_208007d4 = 0;
  DAT_208007d6 = 0;
  sVar12 = sVar23 + 0xd;
  uVar17 = (uint)(short)((short)local_5c + -6);
  sVar11 = (short)uVar21 + -6;
  if (-1 < (char)bVar10) {
    DAT_208007d4 = 0;
    DAT_208007d6 = 0;
    return;
  }
  if (cVar5 == '\0') {
LAB_201241e8:
    if (cVar5 != '\x01') goto LAB_20124394;
LAB_201242a0:
    bVar24 = SBORROW4(iVar16,iVar15);
    iVar19 = iVar16 - iVar15;
    iVar2 = iVar16;
    if (iVar16 <= iVar15) {
      bVar24 = SBORROW4(iVar15,iVar22);
      iVar19 = iVar15 - iVar22;
      iVar2 = iVar22;
    }
    if (iVar2 == iVar15 || iVar19 < 0 != bVar24) {
      gui_draw_runs(uVar13,sVar12,sVar11,&DAT_2016e410);
      fb_fill_box_t(uVar13,sVar12,uVar21 & 0xffff,(unaff_r9 >> 0x10) - 0xd & 0xffff,unaff_r9 & 0xff,
                    0xf800);
    }
    if (iVar16 <= iVar15) {
      if (iVar15 <= iVar22) goto LAB_2012442c;
      goto LAB_20124410;
    }
  }
  else {
    if (cVar5 == '\x01') {
      if (iVar16 < iVar19) {
        if (iVar22 <= iVar19) {
          gui_draw_runs(uVar13,sVar9 + sVar23,uVar8,&DAT_2016e3f0);
        }
      }
      else {
        gui_draw_runs(uVar13,sVar7 + sVar23,uVar6,&DAT_2016e3e0);
      }
      gui_draw_runs(uVar13,sVar23,uVar17 & 0xffff,&DAT_2016e400);
      fb_fill_box_t(uVar13,sVar23,local_5c & 0xffff,unaff_r7 >> 0x10,unaff_r7 & 0xff,0x7e0);
      goto LAB_201242a0;
    }
    if (cVar5 != '\x02') goto LAB_201241e8;
    if (iVar16 < iVar19) {
      if (iVar22 <= iVar19) {
        gui_draw_runs(uVar13,uVar20 & 0xffff,DAT_20802d88,&DAT_2016e3b0);
      }
    }
    else {
      gui_draw_runs(uVar13,uVar20 & 0xffff,DAT_20802d84,&DAT_2016e3a0);
    }
    bVar24 = SBORROW4(iVar16,iVar19);
    iVar2 = iVar16 - iVar19;
    if (iVar16 < iVar19) {
      bVar24 = SBORROW4(iVar19,iVar22);
      iVar2 = iVar19 - iVar22;
    }
    if (iVar2 < 0 != bVar24) {
      gui_draw_runs(uVar13,sVar23,uVar17 & 0xffff,&DAT_2016e400);
      fb_fill_box_t(uVar13,sVar23,local_5c & 0xffff,unaff_r7 >> 0x10,unaff_r7 & 0xff,0x7e0);
    }
LAB_20124394:
    bVar24 = SBORROW4(iVar16,iVar15);
    iVar19 = iVar16 - iVar15;
    if (iVar16 < iVar15) {
      bVar24 = SBORROW4(iVar15,iVar22);
      iVar19 = iVar15 - iVar22;
    }
    if (iVar19 < 0 != bVar24) {
      gui_draw_runs(uVar13,sVar12,sVar11,&DAT_2016e410);
      fb_fill_box_t(uVar13,sVar12,uVar21 & 0xffff,(unaff_r9 >> 0x10) - 0xd & 0xffff,unaff_r9 & 0xff,
                    0xf800);
    }
    if (iVar16 < iVar15) {
      if (iVar15 < iVar22) goto LAB_2012442c;
LAB_20124410:
      gui_draw_runs(uVar13,sVar1,DAT_20802d90,&DAT_2016e3d0);
      goto LAB_2012442c;
    }
  }
  gui_draw_runs(uVar13,sVar1,DAT_20802d8c,&DAT_2016e3c0);
LAB_2012442c:
  if ((((uVar18 & 0x1f) >> 4 != 0) && (cVar5 == '\0')) && (1 < DAT_208f0b57)) {
    fb_fill_box_t(uVar13,uVar14,399,unaff_r7 >> 0x10,1,0xffff);
  }
  return;
}


// ===== FUN_20124528 @ 20124528 (484 bytes)

void FUN_20124528(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar2 = fb_get_layer_addr(DAT_208085b8);
  iVar4 = -((int)((uint)DAT_208f0b2f << 0x1a) >> 0x1f);
  DAT_20800498 = DAT_208f0b3c >> 4 == 5;
  DAT_20800499 = (bool)DAT_20800498 && DAT_208004d0 == 0;
  if ((DAT_20800489 != '\0') &&
     (cVar1 = DAT_20800489 + -1, bVar5 = DAT_20800489 == '\x01', DAT_20800489 = cVar1, bVar5)) {
    FUN_20134304(0);
  }
  if (DAT_20800482 == '\0') {
    if (DAT_208004d0 == 0) {
      if (DAT_20800480 == '\0') {
        if (iVar4 == 0) {
          iVar3 = 0xb4;
        }
        else {
          iVar3 = 0x80;
        }
        FUN_201335d8(DAT_208007c8,iVar4,&DAT_208007d4,iVar2 + iVar3 * 0x640);
      }
      thunk_FUN_2015d49c(iVar4,&DAT_208007d4);
    }
    else if (DAT_208004d0 == 1) {
      if (DAT_208004d2 == '\x02') {
        thunk_FUN_2015d958(iVar4,&DAT_208007d4);
      }
      else if (DAT_208004d2 == '\0') {
        thunk_FUN_2015d874(iVar4,&DAT_208007d4);
      }
      else {
        thunk_FUN_2015d3b8();
      }
    }
  }
  else if (DAT_20800482 == '\x01') {
    if (DAT_208004d0 == 0) {
      if (DAT_20800480 == '\0') {
        if (iVar4 == 0) {
          iVar3 = 0xb4;
        }
        else {
          iVar3 = 0x80;
        }
        FUN_201335f8(DAT_208007c8,iVar4,&DAT_208007d4,iVar2 + iVar3 * 0x640);
      }
      thunk_FUN_2015d5e8(iVar4,&DAT_208007d4);
    }
    else {
      if (DAT_208004d0 != 1) goto LAB_201246dc;
      thunk_FUN_2015d508(iVar4,&DAT_208007d4);
    }
    if (DAT_208004d0 < 2) {
      thunk_FUN_2015d334(iVar4);
    }
  }
LAB_201246dc:
  DAT_208007c8 = (DAT_208007c8 + 1) % 0x308f4;
  return;
}


// ===== FUN_2012470c @ 2012470c (1132 bytes)

uint FUN_2012470c(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
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
  undefined4 local_28;
  
  if ((1 < DAT_20800482) || (DAT_208004d0 != '\x03')) {
    return (DAT_208f0b2f & 0x3f) >> 5;
  }
  local_28 = fb_get_layer_addr(DAT_208085b8);
  uVar6 = 0;
  fb_clear_rect(local_28,DAT_208084ea,DAT_208084e8,DAT_208084f0,DAT_208084f2);
  fb_clear_rect(local_28,DAT_208084f6,DAT_208084f4,DAT_208084f8,DAT_208084fa);
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
  uVar7 = (uint)DAT_208f4bab;
  if (uVar1 < DAT_208f4bab) {
    uVar7 = uVar1;
  }
  if (uVar3 < uVar1) {
    iVar4 = uVar1 - uVar7;
    if (iVar4 < (int)uVar3) {
      uVar7 = uVar1 - uVar3 & 0xff;
    }
    uVar6 = uVar1 - iVar4 & 0xff;
    if (uVar7 < uVar6) {
      uVar1 = uVar6 - uVar7 & 0xff;
    }
    else {
      uVar1 = 0;
    }
    uVar3 = uVar3 - uVar1 & 0xff;
    uVar6 = uVar7;
  }
  else {
    uVar3 = uVar1 - uVar7 & 0xff;
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
  memcpy(&local_68,&DAT_208f489f + uVar6,uVar1);
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
  memcpy(&local_68,&DAT_208f489f + uVar6 + uVar1,uVar3);
  gui_draw_text(local_28,&local_68,DAT_208084fe,DAT_20808508 * uVar1 + (uint)DAT_208084fc & 0xffff,
                (uint)DAT_20808508,&DAT_20800b1c);
  uVar7 = 0x10 - DAT_208f489c & 0xffff;
  if (DAT_208f489e <= uVar7) {
    uVar7 = uVar7 - DAT_208f489e & 0xffff;
  }
  uVar5 = 0;
  bVar8 = uVar7 != 0;
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
      uVar2 = FUN_20155122(&DAT_208f48f1 + uVar7 * 0x29);
      memcpy(&local_68,&DAT_208f48f1 + uVar7 * 0x29,uVar2);
      gui_draw_text(local_28,&local_68,DAT_2080850a * uVar5 + DAT_208084ee,DAT_208084ec,DAT_20808508
                    ,&DAT_20800b1c);
      uVar5 = uVar5 + 1;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar5 < DAT_208f489c);
  }
  if (bVar8) {
    if (((uint)DAT_208f489c < (uint)DAT_208f4899) &&
       ((int)(uint)DAT_208f489e < (int)((uint)DAT_208f4899 - (uint)DAT_208f489c))) {
      DAT_208f4bef = 1;
      goto LAB_20131eb8;
    }
  }
  DAT_208f4bef = 0;
LAB_20131eb8:
  gui_draw_runs(local_28,DAT_2080851a + DAT_20808502,DAT_20808518 + DAT_20808500,&DAT_2016dc58);
  gui_draw_runs(local_28,DAT_2080851e + DAT_20808502,DAT_2080851c + DAT_20808500,&DAT_2016dc68);
  uVar7 = (uint)DAT_208f4899;
  uVar6 = (uint)DAT_208f489c;
  if (uVar6 < uVar7) {
    iVar4 = (uVar7 - uVar6) - (uint)DAT_208f489e;
  }
  else {
    iVar4 = 0;
    uVar6 = 0;
    uVar7 = 0;
  }
  uVar7 = FUN_20136584(local_28,DAT_20808522,DAT_20808520,DAT_20808504,DAT_20808506,iVar4,uVar7,
                       uVar6);
  return uVar7;
}


// ===== FUN_20124744 @ 20124744 (200 bytes)

void FUN_20124744(int param_1)

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


// ===== FUN_20124848 @ 20124848 (80 bytes)

undefined4 FUN_20124848(byte param_1)

{
  undefined4 local_18;
  int iStack_14;
  undefined4 local_10;
  
  local_10 = 0;
  local_18 = 0x1e7;
  DAT_208f1221 = 0x7f;
  DAT_208f1220 = 1;
  iStack_14 = (uint)param_1 << 8;
  mainlink_queue_frame(&local_18,9);
  return 1;
}


// ===== FUN_201248a4 @ 201248a4 (72 bytes)

void FUN_201248a4(byte param_1)

{
  undefined4 local_10;
  int iStack_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_10 = 0x1e8;
  DAT_208f1221 = 0;
  DAT_208f1220 = 1;
  iStack_c = (uint)param_1 << 8;
  mainlink_queue_frame(&local_10,9);
  return;
}


// ===== FUN_201248f8 @ 201248f8 (380 bytes)

undefined4 FUN_201248f8(void)

{
  int iVar1;
  
  if (DAT_2080048e == '\x02' || DAT_2080048e == '\x03') {
    if (((DAT_208f0b57 < 2) || (DAT_208f0b57 == 4 || DAT_208f0b57 == 5)) ||
       (DAT_208f0b57 == 6 || DAT_208f0b57 == 7)) {
      iVar1 = FUN_20103ba0();
      if (((iVar1 == 0) && (iVar1 = audio_error(), iVar1 == 0)) &&
         (DAT_20800490 == '\0' && DAT_2080048f == '\0')) {
        FUN_20124744(0xffffffff);
        DAT_2080048e = 0;
        return 0;
      }
      if ((((DAT_208f0b57 < 2) || (DAT_208f0b57 == 4 || DAT_208f0b57 == 5)) ||
          (DAT_208f0b57 == 6 || DAT_208f0b57 == 7)) &&
         (((DAT_20800490 == '\x01' || (DAT_2080048f == '\x01')) &&
          (iVar1 = audio_error(), iVar1 != 0)))) {
        FUN_201248a4(0,1);
        audio_error();
        FUN_20124744();
      }
    }
    iVar1 = audio_state();
    if ((iVar1 == 0) && (DAT_20800490 != '\0' || DAT_2080048f != '\0')) {
      if (DAT_2080048f == '\x01') {
        rec_stop();
        DAT_2080048f = '\0';
      }
      if (DAT_20800490 == '\x01') {
        play_stop();
        DAT_20800490 = '\0';
      }
      FUN_201248a4(0);
    }
  }
  if ((DAT_2080048e == '\x01') && (iVar1 = audio_error(), iVar1 != 0)) {
    FUN_20124848(0,1);
    audio_error();
    FUN_20124744();
    DAT_208007d8 = 0;
    DAT_2080048e = '\0';
    audio_clear_error();
    DAT_20800490 = '\0';
    DAT_20800491 = 0;
  }
  return 0;
}


// ===== FUN_20124a74 @ 20124a74 (36 bytes)

void FUN_20124a74(int param_1,int param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)(&DAT_208f1264 + (param_1 + param_2 & 0xffffU) * 0x34);
  return;
}

