// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== mainlink_set_last_frame @ 2011508c (16 bytes)

/* writes the 0x2045F8C0 snapshot (debug replay, GUI) */

void mainlink_set_last_frame(undefined4 param_1)

{
  memcpy(&DAT_2045f8c0,param_1,0x240);
  return;
}


// ===== task_cmd_interval @ 2011509c (68 bytes)

void task_cmd_interval(void)

{
  DAT_20450050 = 0;
  do {
    do {
      FUN_201525f8(0xffffffff);
    } while (DAT_20450050 < 1);
    FUN_20152bb0(DAT_20450054,0xffffffff);
    DAT_20450050 = DAT_20450050 + -1;
    FUN_201511e8(DAT_20450054);
  } while( true );
}


// ===== mainlink_set_wait_cmd @ 201150e0 (12 bytes)

/* cmd byte of the frame waiting for ACK (0x2045002D) */

void mainlink_set_wait_cmd(undefined1 param_1)

{
  DAT_2045002d = param_1;
  return;
}


// ===== mainlink_get_wait_cmd @ 201150ec (12 bytes)

undefined1 mainlink_get_wait_cmd(void)

{
  return DAT_2045002d;
}


// ===== mainlink_submit @ 201150f8 (924 bytes)

/* adds checksum; F0/F1 go out at once; other frames go out if no ACK is pending, else are parked in
   per-type slots 0x2045F240..4B */

void mainlink_submit(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = mainlink_tx_alloc(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar2 + 4) = 0xaa;
  *(short *)(iVar2 + 6) = (short)param_2 + 1;
  memcpy(iVar2 + 8,param_1,param_2);
  bVar1 = *(byte *)(iVar2 + 8);
  if (bVar1 == 0xf0 || bVar1 == 0xf1) {
    cVar5 = '\0';
    iVar3 = 0;
    iVar6 = *(ushort *)(iVar2 + 6) - 1;
    if (0 < iVar6) {
      do {
        iVar7 = iVar2 + iVar3;
        iVar3 = iVar3 + 1;
        cVar5 = cVar5 + *(char *)(iVar7 + 8);
      } while (iVar3 < iVar6);
    }
    *(char *)((uint)*(ushort *)(iVar2 + 6) + iVar2 + 7) = cVar5;
    mainlink_tx_post(DAT_20450060 + 0x8218,iVar2);
    return;
  }
  if (DAT_2080049c == '\0') {
    if (DAT_2045002a == '\0') {
      memclr(&DAT_2045efc0,0x105);
      memcpy(&DAT_2045efc0,param_1,param_2);
      DAT_20450038 = param_2;
      mainlink_set_wait_cmd(*(undefined1 *)(iVar2 + 8));
      cVar5 = '\0';
      iVar3 = 0;
      iVar6 = *(ushort *)(iVar2 + 6) - 1;
      if (0 < iVar6) {
        do {
          iVar7 = iVar2 + iVar3;
          iVar3 = iVar3 + 1;
          cVar5 = cVar5 + *(char *)(iVar7 + 8);
        } while (iVar3 < iVar6);
      }
      *(char *)((uint)*(ushort *)(iVar2 + 6) + iVar2 + 7) = cVar5;
      mainlink_tx_post(DAT_20450060 + 0x8218,iVar2);
      DAT_2045002a = 1;
      DAT_2045002c = 0;
      FUN_20151680(DAT_20450064);
      return;
    }
    if (bVar1 == 0xe4) {
      DAT_20470108 = 0;
      memcpy(&DAT_20470108,param_1,param_2);
      DAT_2045f241 = 1;
      return;
    }
    if (bVar1 < 0xe5) {
      if (bVar1 == 0xe0) {
        uVar4 = DAT_2045002e + 1 & 0xff;
        DAT_2045002e = (byte)(uVar4 % 10);
        iVar2 = (uVar4 % 10) * 5;
        FUN_20163668(iVar2 + 0x20470117,(uVar4 / 10) * -5,uVar4 * -0x33333333);
        memcpy(iVar2 + 0x20470117,param_1,param_2);
        DAT_2045f244 = 1;
        return;
      }
      if (bVar1 < 0xe1) {
        if (bVar1 == 0xc3) {
          FUN_20155274(&DAT_20470165,0x22);
          memcpy(&DAT_20470165,param_1,param_2);
          DAT_2045f249 = 1;
          return;
        }
        if (bVar1 == 0xc4) {
          FUN_20155274(&DAT_20470187,0x106);
          memcpy(&DAT_20470187,param_1,param_2);
          DAT_2045f24a = 1;
          return;
        }
        if (bVar1 == 0xc5) {
          FUN_20163684();
          memcpy(&DAT_2047028d,param_1,param_2);
          DAT_2045f24b = 1;
        }
      }
      else {
        if (bVar1 == 0xe2) {
          FUN_20163684(&DAT_20470149);
          memcpy(&DAT_20470149,param_1,param_2);
          DAT_2045f245 = 1;
          return;
        }
        if (bVar1 == 0xe3) {
          DAT_20470100 = 0;
          DAT_20470104 = 0;
          memcpy(&DAT_20470100,param_1,param_2);
          DAT_2045f240 = 1;
          return;
        }
      }
    }
    else {
      if (bVar1 == 0xe7) {
        FUN_20155274(&DAT_20470153,9);
        memcpy(&DAT_20470153,param_1,param_2);
        DAT_2045f247 = 1;
        return;
      }
      if (bVar1 < 0xe8) {
        if (bVar1 == 0xe5) {
          DAT_2047010c = 0;
          memcpy(&DAT_2047010c,param_1,param_2);
          DAT_2045f242 = 1;
          return;
        }
        if (bVar1 == 0xe6) {
          DAT_2047014f = 0;
          DAT_20470150 = 0;
          DAT_20470151 = 0;
          DAT_20470152 = 0;
          memcpy(&DAT_2047014f,param_1,param_2);
          DAT_2045f246 = 1;
          return;
        }
      }
      else {
        if (bVar1 == 0xe8) {
          FUN_201636b8(&DAT_2047015c);
          memcpy(&DAT_2047015c,param_1,param_2);
          DAT_2045f248 = 1;
          return;
        }
        if (bVar1 == 0xf1) {
          memclr(&DAT_20470110,7);
          memcpy(&DAT_20470110,param_1,param_2);
          DAT_2045f243 = 1;
          return;
        }
      }
    }
  }
  return;
}


// ===== mainlink_queue_frame @ 20115494 (644 bytes)

/* WARNING: Type propagation algorithm not settling */

void mainlink_queue_frame(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_30 [4];
  undefined4 local_2c;
  undefined4 uStack_28;
  
  local_2c = param_1;
  uStack_28 = param_2;
  memcpy(&DAT_2045f4a0,param_1,param_2);
  if (DAT_20800496 != '\0' || DAT_20800494 != '\0') {
    if (DAT_2045f4a0 != -0x1a) {
      if ((DAT_208f0b2a == '@') && (DAT_20800494 != '\0')) {
        if ((DAT_2045f4a0 == -0x20) &&
           (((DAT_2045f4a1 == 1 && (DAT_2045f4a2 == '\x03')) && (DAT_2045f4a3 == '\x0f')))) {
          DAT_20808533 = 1;
          return;
        }
        if (DAT_20800496 == '\0') goto LAB_20115704;
      }
      if (DAT_2045f4a0 != -0x20) {
        return;
      }
      if (2 < DAT_2045f4a1) {
        return;
      }
      if (DAT_2045f4a2 != '\x03') {
        return;
      }
      if (DAT_2045f4a3 != '\0') {
        return;
      }
    }
    goto LAB_20115704;
  }
  if (DAT_208f0b2a == '{') {
    if ((DAT_208f0b2b != '\0') && (DAT_2045f4a0 == -0x1e)) {
      local_30[0] = 0xe4;
      DAT_20800488 = 1;
      mainlink_submit(local_30,4);
      goto LAB_2011553c;
    }
  }
  else {
LAB_2011553c:
    if (((((DAT_208f0b2a == '@') && (DAT_2045f4a0 == -0x20)) &&
         ((DAT_2045f4a1 == 1 &&
          ((((DAT_2045f4a2 == '\x03' && (DAT_2045f4a3 == '\x0f')) && (DAT_208f0bc2 == '\0')) &&
           (((DAT_208f0bc6 & 0x10) != 0 && ((DAT_208f0bc5 & 2) != 0)))))))) &&
        (((uint)DAT_208f0bc4 + (DAT_208f0bc6 & 0xf) == 5 &&
         ((iVar1 = FUN_2015507c((DAT_208f0bc6 & 0xf) * 0x2d + 0x208f0c46,"FIRMWARE UPDATE      ",
                                0x15), iVar1 == 0 && (DAT_208000b2 == '\0')))))) &&
       (iVar1 = FUN_20103ba0(), iVar1 != 0)) {
      DAT_20450027 = 1;
      DAT_20800494 = 1;
      DAT_20808533 = 0;
      return;
    }
  }
  if (DAT_20800494 != '\0') {
    return;
  }
  if ((((DAT_20450027 != '\0') && (DAT_2045f4a0 == -0x20)) && (DAT_2045f4a1 == 0)) &&
     ((DAT_2045f4a2 == '\x03' && (DAT_2045f4a3 == '\x0f')))) {
    DAT_20450027 = 0;
    return;
  }
LAB_20115704:
  mainlink_submit(local_2c,param_2);
  return;
}


// ===== mainlink_send_enc @ 20115780 (420 bytes)

/* E1 encoder frame: sent now, or merged into a 7x10 per-encoder queue (0x2045F0C5) while an ACK is
   pending */

void mainlink_send_enc(byte *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (DAT_20800495 == '\0') {
    return;
  }
  if (DAT_2045002a != '\0') {
    FUN_20152bb0(DAT_20450058,0xffffffff);
    uVar4 = (uint)*param_1;
    DAT_2045002b = DAT_2045002b | (byte)(1 << uVar4);
    iVar5 = (&DAT_2045f224)[uVar4];
    if (iVar5 < 10) {
      FUN_201636cc(&DAT_2045f0c5 + iVar5 * 5 + uVar4 * 0x32,param_1);
      (&DAT_2045f224)[uVar4] = iVar5 + 1;
    }
    else {
      iVar5 = iVar5 * 5 + uVar4 * 0x32;
      cVar2 = (&DAT_2045f0c5)[iVar5 + -4];
      FUN_201636cc(&DAT_2045f0c5 + iVar5 + -5,param_1);
      switch(uVar4) {
      case 1:
      case 2:
      case 3:
        iVar1 = (int)(char)param_1[1] + (int)cVar2;
        if (iVar1 < 0) {
          if (iVar1 < -0x7f) {
            iVar1 = -0x7f;
          }
          iVar1 = iVar1 + 0x100;
        }
        else if (0x7f < iVar1) {
          iVar1 = 0x7f;
        }
        (&DAT_2045f0c5)[iVar5 + -4] = (char)iVar1;
        break;
      case 4:
      case 5:
        (&DAT_2045f0c5)[iVar5 + -4] = param_1[1];
      }
    }
    FUN_201511e8(DAT_20450058);
    return;
  }
  iVar5 = mainlink_tx_alloc(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar5 + 4) = 0xaa;
  *(undefined2 *)(iVar5 + 6) = 7;
  *(undefined1 *)(iVar5 + 8) = 0xe1;
  FUN_201636cc(iVar5 + 9,param_1);
  FUN_201636a8(&DAT_20450068);
  FUN_201636cc(&DAT_20450068,param_1);
  mainlink_set_wait_cmd(*(undefined1 *)(iVar5 + 8));
  cVar2 = '\0';
  iVar1 = 0;
  iVar3 = *(ushort *)(iVar5 + 6) - 1;
  if (0 < iVar3) {
    do {
      iVar6 = iVar5 + iVar1;
      iVar1 = iVar1 + 1;
      cVar2 = cVar2 + *(char *)(iVar6 + 8);
    } while (iVar1 < iVar3);
  }
  *(char *)((uint)*(ushort *)(iVar5 + 6) + iVar5 + 7) = cVar2;
  mainlink_tx_post(DAT_20450060 + 0x8218,iVar5);
  DAT_2045002a = 1;
  DAT_2045002c = 0;
  FUN_20151680(DAT_20450064);
  return;
}


// ===== minmax4 @ 2011593c (80 bytes)

/* min or max of 4 bytes */

void minmax4(int param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = 1;
  bVar2 = *param_2;
  if (param_1 != 0) {
    do {
      pbVar1 = param_2 + uVar3;
      uVar3 = uVar3 + 1 & 0xff;
      if (bVar2 < *pbVar1) {
        bVar2 = *pbVar1;
      }
    } while (uVar3 < 4);
    return;
  }
  do {
    pbVar1 = param_2 + uVar3;
    uVar3 = uVar3 + 1 & 0xff;
    if (*pbVar1 < bVar2) {
      bVar2 = *pbVar1;
    }
  } while (uVar3 < 4);
  return;
}


// ===== pot5_filter @ 2011598c (188 bytes)

/* pot id 5 jitter filter (last 4 values span > 2, value 3..252) */

undefined4 pot5_filter(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (DAT_20450030 != param_1) {
    if (DAT_2045003c == 1) {
      uVar3 = param_1 | param_1 << 8;
      DAT_2045003c = 0;
      DAT_20450040 = uVar3 | uVar3 << 0x10;
    }
    DAT_20450030 = (byte)param_1;
    DAT_20450031 = DAT_20450031 + 1;
    if (3 < DAT_20450031) {
      DAT_20450031 = 0;
    }
    *(byte *)((int)&DAT_20450040 + (uint)DAT_20450031) = DAT_20450030;
    if (((param_1 - 3 < 0xfa) && ((char)DAT_20450040 != DAT_20450040._2_1_)) &&
       (DAT_20450040._1_1_ != DAT_20450040._3_1_)) {
      iVar1 = minmax4(1,&DAT_20450040);
      iVar2 = minmax4(0,&DAT_20450040);
      if (2 < iVar1 - iVar2) {
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}


// ===== pot4_filter @ 20115a48 (188 bytes)

/* pot id 4 jitter filter */

undefined4 pot4_filter(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (DAT_20450032 != param_1) {
    if (DAT_20450044 == 1) {
      uVar3 = param_1 | param_1 << 8;
      DAT_20450044 = 0;
      DAT_20450048 = uVar3 | uVar3 << 0x10;
    }
    DAT_20450032 = (byte)param_1;
    DAT_20450033 = DAT_20450033 + 1;
    if (3 < DAT_20450033) {
      DAT_20450033 = 0;
    }
    *(byte *)((int)&DAT_20450048 + (uint)DAT_20450033) = DAT_20450032;
    if (((param_1 - 3 < 0xfa) && ((char)DAT_20450048 != DAT_20450048._2_1_)) &&
       (DAT_20450048._1_1_ != DAT_20450048._3_1_)) {
      iVar1 = minmax4(1,&DAT_20450048);
      iVar2 = minmax4(0,&DAT_20450048);
      if (2 < iVar1 - iVar2) {
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}


// ===== mainlink_renc_event @ 20115b04 (220 bytes)

/* encoder event from the renc tasks -> E4 (leave screen saver) and/or E1 */

void mainlink_renc_event(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  undefined4 local_10;
  
  if (DAT_20800496 != '\0') {
    return;
  }
  local_10 = param_4;
  iVar2 = FUN_20116dac();
  if (iVar2 == 0) {
    return;
  }
  if (*param_1 == '\x04') {
    iVar2 = pot4_filter(param_1[1]);
    if (iVar2 == 0) {
      bVar1 = false;
      goto LAB_20115b68;
    }
  }
  else if (*param_1 == '\x05') {
    iVar2 = pot5_filter(param_1[1]);
    bVar1 = false;
    if (iVar2 == 0) goto LAB_20115b68;
  }
  bVar1 = true;
LAB_20115b68:
  cVar3 = DAT_208f0b2a;
  if ((DAT_208f0b2a == '{') && (cVar3 = '\0', DAT_208f0b2b != '\0')) {
    if (bVar1) {
      DAT_208f0b2b = '\0';
      local_10 = 0xe4;
      DAT_20800488 = 1;
      mainlink_queue_frame(&local_10,4);
      if (*param_1 == '\x04' || *param_1 == '\x05') {
        mainlink_send_enc(param_1);
      }
    }
    return;
  }
  mainlink_send_enc(param_1,&DAT_208f0b2a,cVar3,local_10);
  return;
}


// ===== mainlink_tx_raw @ 20115be0 (148 bytes)

/* frame = 0xAA tag, length, payload, sum8; posts to the TX task (used for resends) */

void mainlink_tx_raw(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = mainlink_tx_alloc(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(short *)(iVar1 + 6) = (short)param_2 + 1;
  memcpy(iVar1 + 8,param_1,param_2);
  cVar3 = '\0';
  iVar2 = 0;
  iVar4 = *(ushort *)(iVar1 + 6) - 1;
  if (0 < iVar4) {
    do {
      iVar5 = iVar1 + iVar2;
      iVar2 = iVar2 + 1;
      cVar3 = cVar3 + *(char *)(iVar5 + 8);
    } while (iVar2 < iVar4);
  }
  *(char *)((uint)*(ushort *)(iVar1 + 6) + iVar1 + 7) = cVar3;
  mainlink_tx_post(DAT_20450060 + 0x8218,iVar1);
  return;
}


// ===== mainlink_tx_e1_raw @ 20115c74 (136 bytes)

/* resend of the last E1 (encoder) frame kept at 0x20450068 */

void mainlink_tx_e1_raw(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  
  iVar1 = mainlink_tx_alloc(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(undefined2 *)(iVar1 + 6) = 7;
  *(undefined1 *)(iVar1 + 8) = 0xe1;
  FUN_201636cc(iVar1 + 9,param_1);
  cVar3 = '\0';
  uVar2 = 0;
  do {
    iVar4 = iVar1 + uVar2;
    uVar2 = uVar2 + 1;
    cVar3 = cVar3 + *(char *)(iVar4 + 8);
  } while (uVar2 < 6);
  *(char *)((uint)*(ushort *)(iVar1 + 6) + iVar1 + 7) = cVar3;
  mainlink_tx_post(DAT_20450060 + 0x8218,iVar1);
  return;
}


// ===== mainlink_flush_parked @ 20115cfc (608 bytes)

/* after an ACK: sends the next parked frame (E3,E4,E5,F1,E0 ring,E2,E6,E7,E8,C3,C4,C5 order) */

void mainlink_flush_parked(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_2045f240 == '\x01') {
    mainlink_submit(&DAT_20470100,8);
    DAT_20470100 = 0;
    DAT_20470104 = 0;
    DAT_2045f240 = 0;
    return;
  }
  if (DAT_2045f241 == '\x01') {
    mainlink_submit(&DAT_20470108,4);
    DAT_20470108 = 0;
    DAT_2045f241 = 0;
    return;
  }
  if (DAT_2045f242 == '\x01') {
    mainlink_submit(&DAT_2047010c,4);
    DAT_2047010c = 0;
    DAT_2045f242 = 0;
    return;
  }
  if (DAT_2045f243 == '\x01') {
    mainlink_submit(&DAT_20470110,7);
    memclr(&DAT_20470110,7);
    DAT_2045f243 = 0;
    return;
  }
  if (DAT_2045f244 == '\x01') {
    uVar1 = DAT_2045002f + 1 & 0xff;
    uVar2 = uVar1 % 10;
    DAT_2045002f = (byte)uVar2;
    mainlink_submit(uVar2 * 5 + 0x20470117,5,uVar1 * -0x33333333);
    uVar1 = (uint)DAT_2045002f;
    FUN_20163668(uVar1 * 5 + 0x20470117);
    if (DAT_2045002e == uVar1) {
      DAT_2045f244 = '\0';
    }
    return;
  }
  if (DAT_2045f245 == '\x01') {
    mainlink_submit(&DAT_20470149,6);
    FUN_20163684(&DAT_20470149);
    DAT_2045f245 = 0;
    return;
  }
  if (DAT_2045f246 == '\x01') {
    mainlink_submit(&DAT_2047014f,4);
    DAT_2047014f = 0;
    DAT_20470150 = 0;
    DAT_20470151 = 0;
    DAT_20470152 = 0;
    DAT_2045f246 = 0;
    return;
  }
  if (DAT_2045f247 != '\x01') {
    if (DAT_2045f248 == '\x01') {
      mainlink_submit(&DAT_2047015c,9);
      FUN_201636b8(&DAT_2047015c);
      DAT_2045f248 = 0;
      return;
    }
    if (DAT_2045f249 != '\x01') {
      if (DAT_2045f24a != '\x01') {
        if (DAT_2045f24b == '\x01') {
          mainlink_submit(&DAT_2047028d,6);
          FUN_20163684(&DAT_2047028d);
          DAT_2045f24b = '\0';
        }
        return;
      }
      mainlink_submit(&DAT_20470187,0x106);
      FUN_20155274(&DAT_20470187,0x106);
      DAT_2045f24a = 0;
      return;
    }
    mainlink_submit(&DAT_20470165,0x22);
    FUN_20155274(&DAT_20470165,0x22);
    DAT_2045f249 = 0;
    return;
  }
  mainlink_submit(&DAT_20470153,9);
  FUN_20155274(&DAT_20470153,9);
  DAT_2045f247 = 0;
  return;
}


// ===== mainlink_flush_enc @ 20115f5c (248 bytes)

/* after an ACK: sends the oldest queued encoder event */

void mainlink_flush_enc(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_28 [12];
  
  uVar3 = 8;
  FUN_20152bb0(DAT_20450058,0xffffffff);
  uVar1 = 0;
  do {
    if (((uint)DAT_2045002b & 1 << (uVar1 & 0xff)) != 0) {
      uVar3 = uVar1;
      if ((int)(&DAT_2045f224)[uVar1] < 2) {
        DAT_2045002b = DAT_2045002b & ~(byte)(1 << (uVar1 & 0xff));
      }
      break;
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 7);
  if (7 < (int)uVar3) {
    DAT_2045002b = 0;
    FUN_20163668(&DAT_2045f0c5 + (&DAT_2045f224)[uVar3] * 5 + uVar3 * 0x32);
    return;
  }
  FUN_201636cc(auStack_28);
  iVar4 = (&DAT_2045f224)[uVar3];
  iVar2 = 0;
  if (0 < iVar4) {
    do {
      FUN_201636cc(&DAT_2045f0c5 + iVar2 * 5 + uVar3 * 0x32,
                   &DAT_2045f0c5 + iVar2 * 5 + uVar3 * 0x32 + 5);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  (&DAT_2045f224)[uVar3] = iVar4 + -1;
  FUN_201511e8(DAT_20450058);
  mainlink_send_enc(auStack_28);
  return;
}


// ===== mainlink_on_ack @ 2011606c (72 bytes)

/* 0x06 from MAIN: stop timeout, clear wait flag, flush parked frames */

void mainlink_on_ack(void)

{
  if (DAT_2045002a != '\0') {
    FUN_2014eb94(DAT_2045004c,0);
    FUN_20151878(DAT_20450064);
    DAT_2045002a = '\0';
    mainlink_flush_parked();
    if (DAT_2045002b != '\0') {
      mainlink_flush_enc();
    }
    DAT_2045002c = 0;
  }
  return;
}


// ===== mainlink_on_nak @ 201160b4 (140 bytes)

/* 0x15 from MAIN: resend at once (max 3), then give up */

void mainlink_on_nak(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_2045002a != '\0') {
    FUN_20151878(DAT_20450064);
    if (2 < DAT_2045002c) {
      if (DAT_20450029 != '\0') {
        uVar1 = mainlink_get_wait_cmd();
        gui_link_error_popup(0,uVar1);
        return;
      }
      system_reboot();
      return;
    }
    iVar2 = mainlink_get_wait_cmd();
    if (iVar2 == 0xe1) {
      mainlink_tx_e1_raw(&DAT_20450068);
    }
    else {
      mainlink_tx_raw(&DAT_2045efc0,DAT_20450038);
    }
    FUN_20151680(DAT_20450064);
    DAT_2045002c = DAT_2045002c + 1;
  }
  return;
}


// ===== mainlink_tx_reset @ 20116140 (124 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* drops the pending/parked state and the encoder queue (0x7F maintenance key, retry task) */

void mainlink_tx_reset(void)

{
  int iVar1;
  int iVar2;
  
  FUN_2014eb94(DAT_2045004c,0);
  FUN_20151878(DAT_20450064);
  DAT_2045002a = 0;
  iVar2 = 0;
  DAT_2045002b = 0;
  DAT_2045002c = 0;
  _DAT_2045f240 = 0;
  _DAT_2045f244 = 0;
  _DAT_2045f248 = 0;
  do {
    iVar1 = 0;
    do {
      FUN_20163668(&DAT_2045f0c5 + iVar1 * 5 + iVar2 * 0x32);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return;
}


// ===== task_mainlink_retry @ 201161bc (232 bytes)

void task_mainlink_retry(void)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_4;
  
  do {
    while( true ) {
      do {
        do {
          iVar1 = itron_twai_flg(DAT_2045004c,1,5,&iStack_4,0xffffffff);
          FUN_20151878(DAT_20450064);
        } while (iVar1 != 0);
      } while (iStack_4 != 1);
      if (DAT_2080049c == '\0') break;
      mainlink_tx_reset();
    }
    if (DAT_2045002a == '\0') {
      FUN_2014eb94(DAT_2045004c,0);
    }
    else if (DAT_2045002c < 3) {
      iVar1 = mainlink_get_wait_cmd();
      if (iVar1 == 0xe1) {
        mainlink_tx_e1_raw(&DAT_20450068);
      }
      else {
        mainlink_tx_raw(&DAT_2045efc0,DAT_20450038);
      }
      FUN_20151680(DAT_20450064);
      DAT_2045002c = DAT_2045002c + 1;
    }
    else if (DAT_20450029 == '\0') {
      system_reboot();
    }
    else {
      uVar2 = mainlink_get_wait_cmd();
      gui_link_error_popup(1,uVar2);
    }
  } while( true );
}


// ===== mainlink_send_hello @ 201162a4 (116 bytes)

/* F0 frame: version 01-08, date 2023-06-29, power-up key code */

void mainlink_send_hello(undefined1 param_1)

{
  undefined4 local_10;
  undefined3 local_c;
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = 0;
  local_10 = 0x200801f0;
  _local_c = CONCAT13(param_1,0x290623);
  mainlink_queue_frame(&local_10,9);
  return;
}


// ===== mainlink_send_f1 @ 20116334 (52 bytes)

/* F1 frame with one sub-command byte; no caller in V01-08 */

void mainlink_send_f1(undefined1 param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = (uint)CONCAT11(param_1,0xf1);
  mainlink_queue_frame(&local_10,7);
  return;
}


// ===== mainlink_stat_rx_resync @ 20116368 (20 bytes)

/* RX task resync counter (obj+0x38) */

undefined4 mainlink_stat_rx_resync(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_20450060 != 0) {
    uVar1 = *(undefined4 *)(DAT_20450060 + 0x38);
  }
  return uVar1;
}


// ===== mainlink_stat_nak_sent @ 2011637c (20 bytes)

/* RX task NAK counter (obj+0x48) */

undefined4 mainlink_stat_nak_sent(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_20450060 != 0) {
    uVar1 = *(undefined4 *)(DAT_20450060 + 0x48);
  }
  return uVar1;
}


// ===== mainlink_ack_timeout_cyc @ 20116390 (16 bytes)

/* WARNING: Removing unreachable block (ram,0x20150f0c) */
/* cyclic handler: set_flg(0x2045004C, 1) wakes the retry task */

code * mainlink_ack_timeout_cyc(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_r4;
  int *piVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 unaff_lr;
  bool bVar10;
  
  if ((DAT_2045004c == 0) || (0x40 < DAT_2045004c)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar8 = *(int *)(&DAT_208dbda4 + DAT_2045004c * 4);
  if (iVar8 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  for (pbVar9 = (byte *)(iVar8 + 9); uVar7 = (uint)*pbVar9, uVar7 == 0; pbVar9 = pbVar9 + 1) {
  }
  if (0xfd < uVar7) {
    *(uint *)(iVar8 + 4) = *(uint *)(iVar8 + 4) | 1;
    software_interrupt(0);
    return FUN_201567f4;
  }
  piVar6 = *(int **)(&DAT_208dbba0 + uVar7 * 4);
  uVar5 = (uint)*(byte *)((int)piVar6 + 7);
  bVar10 = uVar5 == uVar7;
  if (bVar10) {
    uVar5 = (uint)*(byte *)(iVar8 + 8);
  }
  if (!bVar10 || (uVar5 & 2) != 0) {
    bVar10 = false;
    uVar7 = *(uint *)(iVar8 + 4) | 1;
LAB_20150fa4:
    piVar6 = *(int **)(&DAT_208dbba0 + (uint)*pbVar9 * 4);
    bVar1 = *(byte *)((int)piVar6 + 7);
    uVar5 = (uint)*pbVar9;
    do {
      bVar2 = *(byte *)((int)piVar6 + 5);
      bVar3 = *(byte *)((int)piVar6 + 6);
      if ((bVar2 & 1) == 0) {
        if ((*(uint *)(*piVar6 + 8) & ~uVar7) == 0) goto LAB_2015109c;
      }
      else if ((*(uint *)(*piVar6 + 8) & uVar7) != 0) {
LAB_2015109c:
        **(uint **)(*piVar6 + 0xc) = uVar7;
        if ((bVar2 & 2) != 0) {
          FUN_20153ad4(piVar6,uVar5);
        }
        *(undefined1 *)((int)piVar6 + 5) = 0x10;
        if (*(char *)((int)piVar6 + 9) == '\0') {
          iVar4 = (int)(char)piVar6[1];
          if (iVar4 < DAT_208003df) {
            bVar10 = (bool)(bVar10 | iVar4 < DAT_208003df);
          }
          FUN_20153a38(&DAT_208dc18c + iVar4,piVar6,uVar5);
        }
        else {
          FUN_201539ec(piVar6,uVar5);
        }
        if ((bVar2 & 4) != 0) {
          *(undefined4 *)(iVar8 + 4) = 0;
          if (!bVar10) {
            software_interrupt(0);
            return FUN_201567f4;
          }
          software_interrupt(0);
          return FUN_2015655c;
        }
      }
      if (bVar1 == uVar5) goto LAB_2015116c;
      piVar6 = *(int **)(&DAT_208dbba0 + (uint)bVar3 * 4);
      uVar5 = (uint)bVar3;
    } while( true );
  }
  bVar1 = *(byte *)((int)piVar6 + 5);
  if ((bVar1 & 1) == 0) {
    uVar5 = *(uint *)(iVar8 + 4) | 1;
    if ((*(uint *)(*piVar6 + 8) & ~uVar5) != 0) goto LAB_20151030;
  }
  else {
    uVar5 = *(uint *)(iVar8 + 4) | 1;
    if ((*(uint *)(*piVar6 + 8) & uVar5) == 0) {
LAB_20151030:
      *(uint *)(iVar8 + 4) = uVar5;
      software_interrupt(0);
      return FUN_201567f4;
    }
  }
  **(uint **)(*piVar6 + 0xc) = uVar5;
  if ((bVar1 & 4) != 0) {
    uVar5 = 0;
  }
  *(uint *)(iVar8 + 4) = uVar5;
  if ((bVar1 & 2) != 0) {
    FUN_20153ad4(piVar6,uVar7);
  }
  *(undefined1 *)((int)piVar6 + 5) = 0x10;
  if (*(char *)((int)piVar6 + 9) == '\0') {
    iVar8 = piVar6[1];
    FUN_20153a38(&DAT_208dc18c + (char)iVar8,piVar6,uVar7,&DAT_208dc18c + (char)iVar8,unaff_r4,
                 unaff_lr);
    if ((int)DAT_208003df <= (int)(char)iVar8) {
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return FUN_2015655c;
  }
  FUN_201539ec();
  software_interrupt(0);
  return FUN_201567f4;
LAB_2015116c:
  do {
    pbVar9 = pbVar9 + 1;
  } while (*pbVar9 == 0);
  if (0xfd < *pbVar9) {
    *(uint *)(iVar8 + 4) = uVar7;
    if (!bVar10) {
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return FUN_2015655c;
  }
  goto LAB_20150fa4;
}


// ===== mainlink_init @ 201163a0 (300 bytes)

/* cmd_interval_sem / cmd_waiting_sem, binds SCIF5 */

void mainlink_init(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = os_create_sem_named(&DAT_20165860,"cmd_interval_sem");
  if (0 < iVar1) {
    DAT_20450054 = iVar1;
    FUN_201511e8();
  }
  iVar1 = itron_acre_tsk(0,&DAT_2016589c);
  periodic_wakeup_register(iVar1,3);
  if (0 < iVar1) {
    itron_sta_tsk(iVar1,0);
    iVar1 = os_create_sem_named(&DAT_20165870,"cmd_waiting_sem");
    if (0 < iVar1) {
      DAT_20450058 = iVar1;
      FUN_201511e8();
    }
    memclr(&DAT_2045fd40,0x103c0);
    DAT_20450060 = mainlink_obj_ctor(&DAT_2045fd40);
    iVar1 = itron_acre_tsk(0,&DAT_20165880);
    if ((0 < iVar1) && (iVar2 = itron_acre_flg(0,&DAT_201658b8), 0 < iVar2)) {
      *(int *)(DAT_20450060 + 0x14) = iVar2;
      uVar3 = scif5_get();
      *(undefined4 *)(DAT_20450060 + 0x10) = uVar3;
      itron_sta_tsk(iVar1);
      DAT_2045004c = itron_acre_flg(0,&DAT_201658f4);
      if ((0 < DAT_2045004c) &&
         (((iVar1 = itron_acre_tsk(0,&DAT_201658d8), 0 < iVar1 &&
           (iVar1 = itron_sta_tsk(iVar1,0), iVar1 == 0)) &&
          (iVar1 = FUN_2014ec30(0,&DAT_201658c4), 0 < iVar1)))) {
        DAT_20450064 = iVar1;
      }
    }
  }
  return;
}


// ===== mainlink_rx_ctrl @ 20116518 (72 bytes)

/* set_flg 0x4000/0x8000 on the RX task flag (resets the parser); arg 0 also re-binds the SCIF5 ISR
   to it (used by the update code) */

void mainlink_rx_ctrl(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_20450060 != 0) {
    if (param_1 == 0) {
      uVar1 = 0x4000;
    }
    else {
      uVar1 = 0x8000;
    }
    itron_set_flg(*(undefined4 *)(DAT_20450060 + 0x14),uVar1);
    if (param_1 == 0) {
      scif5_get(*(undefined4 *)(DAT_20450060 + 0x14));
      return;
    }
  }
  return;
}


// ===== mainlink_inject_rx @ 20116560 (472 bytes)

/* rename (was mainlink_send_cmd): builds a frame from the 0x2B-entry table length and posts it to
   the RX dispatcher mailbox, i.e. replays a frame locally; it does not transmit */

void mainlink_inject_rx(char *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = mainlink_disp_alloc(DAT_20450060 + 0x58);
  iVar3 = 0;
  uVar2 = 0;
  do {
    if (*param_1 == (&DAT_20450074)[uVar2 * 0xc]) {
      iVar3 = (ushort)(&DAT_20450076)[uVar2 * 6] + 2;
      break;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x2b);
  if (iVar3 != 0) {
    *(undefined2 *)(iVar1 + 4) = 0xaa;
    *(short *)(iVar1 + 6) = (short)iVar3;
    memcpy(iVar1 + 8,param_1);
    FUN_20162d3c(DAT_20450060 + 0x58,*(undefined4 *)(DAT_20450060 + 0x81f4),iVar1);
    return;
  }
  return;
}


// ===== mainlink_hello_poweron @ 201165f4 (108 bytes)

/* sends F0 every 5 ms (max 30) with the power-up key code until MAIN ACKs */

void mainlink_hello_poweron(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  key_task_pause();
  DAT_20450026 = 0;
  iVar1 = key_scan_first();
  if (iVar1 == 0) {
    if (DAT_208003a1 == '\0') {
      DAT_208003a1 = '\x01';
    }
    else {
      iVar1 = 0x10;
    }
  }
  DAT_20450028 = '\0';
  iVar2 = 0x1d;
  do {
    mainlink_send_hello(iVar1);
    itron_dly_tsk(5);
    if (DAT_20450028 != '\0') {
      iVar2 = 0;
    }
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  return;
}


// ===== mainlink_clear_status @ 20116660 (44 bytes)

/* clears the 0x60 snapshot and the 0x24 settings copy */

void mainlink_clear_status(void)

{
  memclr(&DAT_2045fb00,0x240);
  DAT_20450026 = 0;
  FUN_20163684(&DAT_2045006d);
  DAT_20450024 = 0;
  return;
}


// ===== mainlink_hello_key6 @ 2011668c (60 bytes)

/* same as mainlink_hello_poweron with key code 6 */

void mainlink_hello_key6(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0x1d;
  DAT_20450028 = '\0';
  do {
    mainlink_send_hello(6);
    itron_dly_tsk(5);
    if (DAT_20450028 != '\0') {
      iVar1 = 0;
    }
    bVar2 = iVar1 != 0;
    iVar1 = iVar1 + -1;
  } while (bVar2);
  return;
}


// ===== usbhid_attach_event @ 201166cc (92 bytes)

/* usage 6 keyboard / 2 mouse attach, -1 detach */

void usbhid_attach_event(int param_1,int param_2)

{
  if (param_2 == 6) {
    usbkbd_attach();
  }
  else if (param_2 == 2) {
    mouse_attach_post();
  }
  else if (param_2 < 0) {
    if (*(int *)(&DAT_2080036c + param_1 * 4) == 6) {
      usbkbd_detach();
    }
    else if (*(int *)(&DAT_2080036c + param_1 * 4) == 2) {
      mouse_detach_post();
    }
  }
  *(int *)(&DAT_2080036c + param_1 * 4) = param_2;
  return;
}


// ===== usbhid_report_event @ 20116728 (56 bytes)

/* report -> usbkbd_report (6) or mouse_report_post (2) */

void usbhid_report_event(undefined4 param_1,int *param_2)

{
  if (*param_2 == 6) {
    usbkbd_report();
  }
  else {
    if (*param_2 != 2) {
      return;
    }
    mouse_report_post(param_2);
  }
  DAT_20800487 = 1;
  return;
}


// ===== periodic_wakeup_register @ 20116768 (28 bytes)

/* (task, slot): slot n of 0x208DBAD0 {tskid, ?, period from 0x20800374[n], count} */

void periodic_wakeup_register(undefined4 param_1,int param_2)

{
  (&DAT_208dbad0)[param_2 * 4] = param_1;
  (&DAT_208dbad8)[param_2 * 4] = *(undefined4 *)(&DAT_20800374 + param_2 * 4);
  return;
}


// ===== FUN_20116784 @ 20116784 (8 bytes)

void FUN_20116784(void)

{
  gic_disable_irq(0x87);
  return;
}


// ===== periodic_wakeup_isr @ 2011678c (76 bytes)

/* GIC 0x87, every 1 ms: per slot count++, at period wake the task (0x20152FAC) */

void periodic_wakeup_isr(void)

{
  int iVar1;
  undefined4 extraout_r1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (&DAT_208dbadc)[iVar2 * 4];
    (&DAT_208dbadc)[iVar2 * 4] = iVar1 + 1;
    if ((&DAT_208dbad8)[iVar2 * 4] == iVar1 + 1) {
      itron_iwup_tsk((&DAT_208dbad0)[iVar2 * 4]);
    }
    FUN_20156260((&DAT_208dbadc)[iVar2 * 4],(&DAT_208dbad8)[iVar2 * 4]);
    iVar1 = iVar2 + 1;
    (&DAT_208dbadc)[iVar2 * 4] = extraout_r1;
    iVar2 = iVar1;
  } while (iVar1 < 5);
  return;
}


// ===== periodic_wakeup_start @ 201167d8 (92 bytes)

/* OSTM1 1 ms compare (31999), ISR on GIC ID 0x87 */

int periodic_wakeup_start(void)

{
  byte bVar1;
  int iVar2;
  
  Ramfcfec400 = 31999;
  bVar1 = UNK_fcfec420;
  UNK_fcfec420 = bVar1 & 0xfd;
  UNK_fcfec420 = 1;
  iVar2 = itron_acre_isr(0,&DAT_20165954);
  if (iVar2 < 1) {
    return iVar2;
  }
  gic_enable_irq(0x87);
  bVar1 = DAT_fcfec414;
  DAT_fcfec414 = bVar1 | 1;
  return 0;
}


// ===== cli_exec_line @ 20116848 (392 bytes)

void cli_exec_line(char *param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  uint uVar2;
  ushort *puVar3;
  bool bVar4;
  char cVar5;
  char *local_18;
  
  cVar5 = false;
  local_18 = param_4;
  uVar2 = FUN_20155122();
  bVar4 = uVar2 == 2;
  if (1 < uVar2) {
    bVar4 = *param_1 == 'b';
  }
  if ((bVar4) && (cVar5 = param_1[1] == ' ', (bool)cVar5)) {
LAB_201168a0:
    param_1 = param_1 + 2;
  }
  else {
    uVar2 = FUN_20155122(param_1);
    bVar4 = uVar2 == 2;
    if (1 < uVar2) {
      bVar4 = *param_1 == 'h';
    }
    if ((bVar4) && (param_1[1] == ' ')) {
      cVar5 = '\x02';
      goto LAB_201168a0;
    }
  }
  puVar3 = (ushort *)hex_parse(param_1,8,&local_18);
  pcVar1 = (char *)0x0;
  if (puVar3 != (ushort *)0x0) {
    pcVar1 = local_18;
  }
  if (puVar3 == (ushort *)0x0 || pcVar1 == (char *)0x0) {
    return;
  }
  if (*pcVar1 == ' ') {
    local_18 = pcVar1 + 1;
    DAT_2080038c = hex_parse(local_18,8,&local_18);
    if (cVar5 == '\x01') {
      DAT_20800388 = puVar3;
      *(byte *)puVar3 = (byte)DAT_2080038c;
      goto LAB_201169a8;
    }
    if (cVar5 == '\x02') {
      DAT_20800388 = puVar3;
      *puVar3 = (ushort)DAT_2080038c;
      goto LAB_20116980;
    }
    DAT_20800388 = puVar3;
    *(undefined4 *)puVar3 = DAT_2080038c;
  }
  else {
    if (*pcVar1 != '\0') {
      return;
    }
    DAT_20800388 = puVar3;
    if (cVar5 == '\x01') {
LAB_201169a8:
      kbd_led_status(2,7);
      itron_dly_tsk(10);
      kbd_led_status(0,7);
      DAT_20800390 = (uint)(byte)*puVar3;
      return;
    }
    if (cVar5 == '\x02') {
LAB_20116980:
      kbd_led_status(2,7);
      itron_dly_tsk(10);
      kbd_led_status(0,7);
      DAT_20800390 = (uint)*puVar3;
      return;
    }
  }
  kbd_led_status(7);
  itron_dly_tsk(10);
  kbd_led_status(0,7);
  DAT_20800390 = *(undefined4 *)puVar3;
  return;
}


// ===== cli_run_file @ 201169d0 (224 bytes)

undefined4 cli_run_file(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  byte local_190 [252];
  undefined1 auStack_94 [4];
  undefined1 auStack_90 [64];
  undefined1 auStack_50 [64];
  
  uVar2 = FUN_20155122();
  if (3 < uVar2) {
    memcpy(auStack_90,param_1,0x40);
    iVar3 = FUN_2014e208(auStack_94 + uVar2,&DAT_20116b90);
    if (iVar3 == 0) {
      FUN_20155310(auStack_50,&DAT_20165984,0x40);
      FUN_2015515c(auStack_50,auStack_90);
      iVar3 = fs_fopen(auStack_50,&DAT_20116b9c);
      if (iVar3 != 0) {
        while (iVar4 = FUN_20142390(local_190,0x100,iVar3), iVar4 != 0) {
          uVar2 = 0;
          do {
            bVar1 = local_190[uVar2];
            bVar5 = 0xc < bVar1;
            if (bVar1 != 0xd) {
              bVar5 = 9 < bVar1;
            }
            if (bVar1 != 0xd && bVar1 != 10) {
              uVar2 = uVar2 + 1;
              bVar5 = 0xff < uVar2;
            }
            else {
              local_190[uVar2] = 0;
            }
          } while (!bVar5);
          cli_exec_line(local_190);
        }
        FUN_20141ff0(iVar3);
        return 1;
      }
    }
  }
  return 0;
}


// ===== task_cli @ 20116ab0 (80 bytes)

/* memory monitor: "ADDR", "ADDR VAL", "b ADDR VAL", "h ADDR VAL", or NAME.txt = run I:\NAME.txt */

void task_cli(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 uStack_14;
  
  uStack_14 = in_r3;
  while (iVar1 = itron_twai_flg(DAT_20800394,1,5,&uStack_14,0xffffffff), iVar1 == 0) {
    iVar1 = cli_run_file();
    if (iVar1 == 0) {
      cli_exec_line(&DAT_208dbb24);
    }
  }
  return;
}


// ===== cli_line @ 20116b00 (48 bytes)

void cli_line(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = hid_line_edit(&DAT_208dbb20,param_1,param_2);
  if (iVar1 == 0) {
    return;
  }
  itron_set_flg(DAT_20800394,1);
  return;
}


// ===== cli_init @ 20116b30 (92 bytes)

/* event flag + task "cli"; returns cli_line */

undefined8 cli_init(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10 = 2;
  uStack_c = 0;
  uStack_8 = 0;
  iVar1 = itron_acre_flg(0,&local_10);
  if (0 < iVar1) {
    DAT_20800394 = iVar1;
    iVar1 = itron_acre_tsk(0,&DAT_20165968);
    if ((0 < iVar1) && (iVar1 = itron_sta_tsk(iVar1,0), iVar1 == 0)) {
      pcVar2 = cli_line;
      goto LAB_20116b88;
    }
  }
  pcVar2 = (code *)0x0;
LAB_20116b88:
  return CONCAT44(local_10,pcVar2);
}


// ===== bootinfo_load @ 20116c4c (100 bytes)

/* copies the 0x60-byte boot-info block (pointer in SPIBSC1 reg 0x3FEFB018) or builds defaults */

void bootinfo_load(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_3fefb018;
  if (iVar1 == 0) {
    DAT_208dbb44 = 0;
    DAT_208dbb64 = 0x3e0000;
    DAT_208dbb68 = 0x400000;
    DAT_208dbb84 = 0x3f0000;
    DAT_208dbb88 = 0xa00000;
  }
  else {
    uVar2 = DAT_3fefb018;
    memcpy(&DAT_208dbb44,uVar2,0x60);
  }
  DAT_20800398 = DAT_208dbb44;
  return;
}


// ===== cpg_early_init @ 20116ccc (172 bytes)

/* Reset_Handler: PL310 power ctrl, FRQCR 0x0035, FRQCR2 1, SYSCR3 0x0F, STBCR2..12 */

void cpg_early_init(void)

{
  DAT_3fffff80 = 1;
  DAT_fcfe0010 = 0x35;
  DAT_fcfe0014 = 1;
  DAT_fcfe0408 = 0xf;
  DAT_fcfe0024 = 0x6a;
  DAT_fcfe0420 = 0;
  DAT_fcfe0424 = 0;
  DAT_fcfe0428 = 0;
  DAT_fcfe042c = 0;
  DAT_fcfe0430 = 0x24;
  DAT_fcfe0434 = 5;
  DAT_fcfe0438 = 0;
  DAT_fcfe043c = 0;
  DAT_fcfe0440 = 0xc0;
  DAT_fcfe0444 = 0xf0;
  gpio_early_init();
  gpio_rx_reset(0);
  return;
}


// ===== mmu_cache_enable @ 20116d84 (28 bytes)

/* SCTLR |= M|C|W bits (0xD) after setting TTBR/DACR */

undefined4 mmu_cache_enable(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 in_cr9;
  undefined4 in_cr12;
  undefined4 in_cr13;
  
  coprocessor_moveto(0xf,0,1,0x80000000,in_cr9,in_cr12);
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr12);
  coprocessor_moveto(0xf,0,0,uVar1 | 0xd,in_cr9,in_cr12);
  uVar2 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar2;
}


// ===== FUN_20116da0 @ 20116da0 (12 bytes)

void FUN_20116da0(undefined1 param_1)

{
  DAT_208003a4 = param_1;
  return;
}


// ===== FUN_20116dac @ 20116dac (12 bytes)

undefined1 FUN_20116dac(void)

{
  return DAT_208003a4;
}


// ===== hid_chain1_dispatch @ 20116db8 (60 bytes)

/* calls the 9 debug handlers at 0x208DC1BC */

void hid_chain1_dispatch(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  kbd_set_current();
  iVar1 = 0;
  do {
    if ((code *)(&DAT_208dc1bc)[iVar1] != (code *)0x0) {
      (*(code *)(&DAT_208dc1bc)[iVar1])(param_1,param_2);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  return;
}


// ===== hid_chain0_dispatch @ 20116df4 (60 bytes)

/* calls the 9 handlers at 0x208DC198 (none registered in V01-08) */

void hid_chain0_dispatch(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  kbd_set_current();
  iVar1 = 0;
  do {
    if ((code *)(&DAT_208dc198)[iVar1] != (code *)0x0) {
      (*(code *)(&DAT_208dc198)[iVar1])(param_1,param_2);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  return;
}


// ===== gpio_p2_0_debounced @ 20116e30 (84 bytes)

/* reads P2_0 until 3 equal samples 10 ms apart */

bool gpio_p2_0_debounced(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = gpio_read_bit(2,0);
  iVar3 = 0;
  do {
    itron_dly_tsk(10);
    iVar2 = gpio_read_bit(2,0);
    if (iVar2 != iVar1) {
      iVar3 = 0;
      iVar1 = iVar2;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return iVar1 != 0;
}


// ===== boot_mode_full @ 20116e84 (68 bytes)

/* returns 1 for the full application, 0 for the reduced (standby) start */

undefined1 boot_mode_full(void)

{
  int iVar1;
  
  iVar1 = key_scan_first();
  if (((iVar1 != 6) && (DAT_208003a4 == '\0')) && (DAT_208003a2 != '\0')) {
    return 0;
  }
  return 1;
}

