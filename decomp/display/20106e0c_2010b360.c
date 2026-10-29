// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== usbkbd_attach @ 20106e0c (168 bytes)

void usbkbd_attach(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 local_20;
  
  bVar1 = false;
  local_20 = param_4;
  FUN_201571b8(&local_20,DAT_20800118,1);
  FUN_2015f098(&DAT_20811080 + param_1 * 0xd0,param_1,1);
  iVar2 = 0;
  do {
    if ((&DAT_20811100)[iVar2 * 0xd0] != '\0') {
      bVar1 = true;
      goto LAB_20106e8c;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  FUN_2015f0b4(&DAT_20811080 + param_1 * 0xd0);
LAB_20106e8c:
  FUN_201571d4(&local_20);
  if (bVar1) {
    return;
  }
  FUN_2013baac(param_1,0,&DAT_2080010c,local_20);
  return;
}


// ===== usbkbd_detach @ 20106eb4 (164 bytes)

void usbkbd_detach(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  
  iVar2 = -1;
  local_18 = param_4;
  FUN_201571b8(&local_18,DAT_20800118,1);
  FUN_2015f098(&DAT_20811080 + param_1 * 0xd0,param_1,0);
  iVar1 = 0;
  do {
    if ((&DAT_20811101)[iVar1 * 0xd0] != '\0') {
      FUN_2015f0b4(&DAT_20811080 + iVar1 * 0xd0);
      iVar2 = iVar1;
      break;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  FUN_201571d4(&local_18);
  if (iVar2 != -1) {
    FUN_2013baac(iVar2,0,&DAT_2080010c,local_18);
    return;
  }
  return;
}


// ===== usbkbd_queue_key @ 20106f58 (104 bytes)

/* (modifier, first usage) -> per-keyboard FIFO 0x20811108 */

void usbkbd_queue_key(int param_1,int param_2)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined1 auStack_10 [8];
  
  if (*(char *)(param_2 + 0xd) != '\0') {
    return;
  }
  local_17 = *(undefined1 *)(param_2 + 0xc);
  local_18 = *(undefined1 *)(param_2 + 5);
  FUN_201571b8(auStack_10,DAT_20800118,1);
  FUN_201645a0(param_1 * 0xd0 + 0x20811108,&local_18);
  FUN_201571d4(auStack_10);
  return;
}


// ===== usbkbd_report @ 20106fc0 (220 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* USB keyboard HID report: NumLock/ScrollLock LEDs, chain 0, chain 1 if debug_enabled */

void usbkbd_report(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  DAT_20811220 = *param_2;
  _DAT_20811224 = param_2[1];
  DAT_20811228 = param_2[2];
  DAT_2081122c = param_2[3];
  DAT_20811230 = param_2[4];
  DAT_20811234 = param_2[5];
  DAT_20811238 = param_2[6];
  DAT_2081123c = param_2[7];
  usbkbd_queue_key(param_1,param_2);
  DAT_2080010d = *(char *)(param_2 + 3);
  if (*(char *)((int)param_2 + 0xd) == '\0') {
    if (DAT_2080010d == 'S') {
      DAT_2080010c = DAT_2080010c ^ 1;
      FUN_2013baac(param_1,0,&DAT_2080010c);
    }
    else if (DAT_2080010d == 'G') {
      DAT_2080010c = DAT_2080010c ^ 4;
      FUN_2013baac(param_1,0,&DAT_2080010c);
    }
  }
  if (DAT_20800110 != (code *)0x0) {
    (*DAT_20800110)(param_1,param_2);
  }
  iVar1 = debug_enabled();
  if ((iVar1 != 0) && (DAT_20800114 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x20107094. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_20800114)(param_1,param_2);
    return;
  }
  return;
}


// ===== usbkbd_active @ 2010709c (68 bytes)

undefined * usbkbd_active(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_20811100)[iVar1 * 0xd0] != '\0') {
      return &DAT_20811080 + iVar1 * 0xd0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return (undefined *)0x0;
}


// ===== usbkbd_get_device @ 201070e0 (92 bytes)

undefined1
usbkbd_get_device(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,DAT_20800118,1);
  iVar1 = usbkbd_active();
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x84);
    *param_1 = *(undefined4 *)(iVar1 + 0x80);
    param_1[1] = uVar2;
    FUN_201571d4(&uStack_10);
    return *(undefined1 *)param_1;
  }
  FUN_201571d4(&uStack_10);
  return 0;
}


// ===== usbkbd_pop_key @ 2010713c (140 bytes)

undefined4
usbkbd_pop_key(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_201571b8(&uStack_10,DAT_20800118,1);
  iVar1 = usbkbd_active();
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0x80);
    iVar1 = *(int *)(iVar1 + 0x84);
    param_1[1] = iVar1;
    *param_1 = uVar3;
    puVar2 = (undefined4 *)FUN_20164604(iVar1 * 0xd0 + 0x20811108);
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = puVar2[1];
      param_1[2] = *puVar2;
      param_1[3] = uVar3;
      FUN_201571d4(&uStack_10);
      return 1;
    }
  }
  FUN_201571d4(&uStack_10);
  return 0;
}


// ===== usbkbd_flush_all @ 201071c8 (72 bytes)

void usbkbd_flush_all(void)

{
  undefined4 in_r3;
  int iVar1;
  undefined4 uStack_10;
  
  uStack_10 = in_r3;
  FUN_201571b8(&uStack_10,DAT_20800118,1);
  iVar1 = 0;
  do {
    FUN_2015f0c4(&DAT_20811080 + iVar1 * 0xd0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  FUN_201571d4(&uStack_10);
  return;
}


// ===== usbkbd_get_char @ 20107210 (108 bytes)

/* FIFO -> char via the KEYBOARD LANGUAGE layout (0x2080010E) */

undefined4 usbkbd_get_char(byte *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined1 auStack_18 [8];
  undefined4 local_10;
  undefined4 uStack_c;
  
  iVar2 = usbkbd_pop_key(auStack_18);
  uVar3 = 0;
  if (iVar2 != 0) {
    *(undefined4 *)param_1 = local_10;
    *(undefined4 *)(param_1 + 4) = uStack_c;
    bVar1 = *param_1;
    if ((bVar1 & 0x9d) == 0) {
      bVar4 = (bVar1 & 0x22) != 0;
      if ((bVar1 & 0x40) != 0) {
        bVar4 = bVar4 | 2;
      }
    }
    else {
      bVar4 = 0xff;
    }
    uVar3 = FUN_2010a684(param_1[1],bVar4,DAT_2080010e);
    *(undefined4 *)(param_1 + 4) = uVar3;
    uVar3 = 1;
  }
  return uVar3;
}


// ===== kbd_text_append @ 201072d8 (36 bytes)

/* text buffer 0x20811240 (64 chars) */

void kbd_text_append(undefined1 param_1)

{
  if (DAT_2080011c < 0x40) {
    *(undefined1 *)((int)&DAT_20811240 + DAT_2080011c) = param_1;
    DAT_2080011c = DAT_2080011c + 1;
  }
  return;
}


// ===== kbd_text_backspace @ 201072fc (40 bytes)

void kbd_text_backspace(void)

{
  int iVar1;
  
  if (0 < DAT_2080011c) {
    iVar1 = DAT_2080011c + 3;
    DAT_2080011c = DAT_2080011c + -1;
    *(undefined1 *)((int)&DAT_2081123c + iVar1) = 0;
  }
  return;
}


// ===== kbd_text_clear @ 20107324 (84 bytes)

void kbd_text_clear(void)

{
  DAT_20811240 = 0;
  DAT_20811244 = 0;
  DAT_20811248 = 0;
  DAT_2081124c = 0;
  DAT_20811250 = 0;
  DAT_20811254 = 0;
  DAT_20811258 = 0;
  DAT_2081125c = 0;
  DAT_20811260 = 0;
  DAT_20811264 = 0;
  DAT_20811268 = 0;
  DAT_2081126c = 0;
  DAT_20811270 = 0;
  DAT_20811274 = 0;
  DAT_20811278 = 0;
  DAT_2081127c = 0;
  DAT_2080011c = 0;
  return;
}


// ===== usbkbd_set_layout @ 20107378 (20 bytes)

/* 0..10 (JPN US UK FRA(AZ) FRA(QW) DEU POR POR(BR) ESP ESP(LA) ITA) */

void usbkbd_set_layout(uint param_1)

{
  if (10 < param_1) {
    param_1 = 0;
  }
  DAT_2080010e = (char)param_1;
  return;
}


// ===== usbkbd_reset @ 2010738c (24 bytes)

void usbkbd_reset(void)

{
  usbkbd_flush_all();
  DAT_20800129 = 0;
  return;
}


// ===== usbkbd_capslock_for_mode @ 201073a4 (1800 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CapsLock LED on for text modes 0,3,5,8,10 */

void usbkbd_capslock_for_mode(uint param_1)

{
  undefined2 uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined2 auStack_1a8 [48];
  undefined1 auStack_148 [96];
  undefined1 auStack_e8 [96];
  undefined1 auStack_88 [96];
  undefined4 local_28;
  uint local_24;
  
  iVar4 = usbkbd_get_char(&local_28);
  if (iVar4 == 0) {
    return;
  }
  FUN_20155310(auStack_148,&DAT_20165348,0x60);
  FUN_20155310(auStack_e8,&DAT_201653a8,0x60);
  FUN_20155310(auStack_88,&DAT_20165408,0x60);
  FUN_20155310(auStack_1a8,auStack_e8,0x60);
  uVar3 = local_24;
  if (local_28._1_1_ == '\0') {
    _DAT_20800128 = local_28;
    DAT_2080012c = local_24;
    return;
  }
  if (DAT_20800129 != '\0') {
    _DAT_20800128 = local_28;
    DAT_2080012c = local_24;
    return;
  }
  uVar7 = 0;
  iVar4 = 0xff;
  bVar2 = false;
  uVar5 = local_24 - 0x30;
  if (uVar5 < 10) {
    uVar7 = local_24 & 0xff;
    switch(uVar5) {
    case 0:
switchD_20107444_caseD_0:
      iVar4 = 9;
      break;
    case 1:
switchD_20107444_caseD_1:
      iVar4 = 0;
      break;
    case 2:
switchD_20107444_caseD_2:
      iVar4 = 1;
      break;
    case 3:
switchD_20107444_caseD_3:
      iVar4 = 2;
      break;
    case 4:
switchD_20107444_caseD_4:
      iVar4 = 3;
      break;
    case 5:
switchD_20107444_caseD_5:
      iVar4 = 4;
      break;
    case 6:
switchD_20107444_caseD_6:
      iVar4 = 5;
      break;
    case 7:
switchD_20107444_caseD_7:
      iVar4 = 6;
      break;
    case 8:
switchD_20107444_caseD_8:
      iVar4 = 7;
      break;
    case 9:
switchD_20107444_caseD_9:
      iVar4 = 8;
      break;
    default:
switchD_20107444_default:
      if (iVar4 == 0xff) goto LAB_20107d28;
    }
  }
  else {
    if (local_24 - 0x60 < 10) {
      uVar7 = uVar5 & 0xff;
      switch(local_24) {
      case 0x60:
        goto switchD_20107444_caseD_0;
      case 0x61:
        goto switchD_20107444_caseD_1;
      case 0x62:
        goto switchD_20107444_caseD_2;
      case 99:
        goto switchD_20107444_caseD_3;
      case 100:
        goto switchD_20107444_caseD_4;
      case 0x65:
        goto switchD_20107444_caseD_5;
      case 0x66:
        goto switchD_20107444_caseD_6;
      case 0x67:
        goto switchD_20107444_caseD_7;
      case 0x68:
        goto switchD_20107444_caseD_8;
      case 0x69:
        goto switchD_20107444_caseD_9;
      default:
        goto switchD_20107444_default;
      }
    }
    uVar5 = local_24 - 0x41;
    if (0x19 < uVar5) {
      if (local_24 == 0x1b) {
        iVar4 = 0x2a;
      }
      else if (local_24 == 0x25) {
        iVar4 = 0x2b;
      }
      else if (local_24 == 0x20) {
        iVar4 = 0x2c;
      }
      else if (local_24 == 0x27) {
        iVar4 = 0x2d;
      }
      else if (local_24 == 0xd || local_24 == 0xd8) {
        iVar4 = 0x2e;
      }
      else {
        if (local_24 != 8) {
          if (param_1 < 3) {
            bVar2 = true;
            if (local_24 == 0xbc) {
switchD_20107c58_caseD_bc:
              iVar4 = 0x25;
            }
            else if ((int)local_24 < 0xbd) {
              if (local_24 == 0xb3) {
LAB_20107854:
                iVar4 = 0xd;
              }
              else if ((int)local_24 < 0xb4) {
                if (local_24 == 0x6e) goto switchD_20107b38_caseD_6e;
                if ((int)local_24 < 0x6f) {
                  if (local_24 == 0x14) goto switchD_20107b38_caseD_70;
                  if (local_24 == 0x6a) goto switchD_20107ab8_caseD_c1;
                  if (local_24 == 0x6b) goto switchD_20107b38_caseD_6b;
joined_r0x20107790:
                  if (local_24 == 0x6d) goto switchD_20107c58_caseD_bd;
                }
                else {
                  if (local_24 == 0x6f) goto switchD_20107b38_caseD_6f;
                  if (local_24 == 0xb1) goto LAB_20107844;
joined_r0x201077ac:
                  if (local_24 == 0xb2) goto LAB_2010784c;
                }
              }
              else {
                switch(local_24) {
                case 0xb4:
                  goto switchD_20107a88_caseD_b4;
                case 0xb5:
switchD_20107c34_caseD_b5:
                  iVar4 = 0xf;
                  break;
                case 0xb6:
                  goto switchD_20107c34_caseD_b6;
                case 0xb7:
                  goto switchD_20107c34_caseD_b7;
                case 0xb8:
                  goto switchD_20107c34_caseD_b8;
                case 0xb9:
                  goto switchD_20107c34_caseD_b9;
                case 0xba:
                  goto switchD_20107b98_caseD_ba;
                case 0xbb:
                  goto switchD_20107b38_caseD_6b;
                }
              }
            }
            else {
              switch(local_24) {
              case 0xbd:
                goto switchD_20107c58_caseD_bd;
              case 0xbe:
switchD_20107b38_caseD_6e:
                iVar4 = 0x26;
                break;
              case 0xbf:
                goto switchD_20107b38_caseD_6f;
              case 0xc0:
              case 0xcc:
switchD_20107c58_caseD_c0:
                iVar4 = 0x1f;
                break;
              case 0xc1:
switchD_20107ab8_caseD_c1:
                iVar4 = 0x19;
                break;
              case 0xc3:
switchD_20107ab8_caseD_c3:
                iVar4 = 0x1a;
                break;
              case 0xc4:
                goto switchD_20107c58_caseD_c4;
              case 0xc5:
switchD_20107ab8_caseD_c5:
                iVar4 = 0x1b;
                break;
              case 0xc6:
switchD_20107b98_caseD_c6:
                iVar4 = 0x1c;
                break;
              case 200:
                goto switchD_20107c58_caseD_c8;
              case 0xc9:
switchD_20107c58_caseD_c9:
                iVar4 = 0x23;
                break;
              case 0xca:
switchD_20107c58_caseD_ca:
                iVar4 = 0x21;
                break;
              case 0xcb:
                goto switchD_20107c58_caseD_cb;
              case 0xce:
switchD_20107c58_caseD_ce:
                iVar4 = 0x1d;
                break;
              case 0xcf:
switchD_20107ab8_caseD_cf:
                iVar4 = 0x24;
                break;
              case 0xd0:
switchD_20107b38_caseD_70:
                iVar4 = 0x20;
              }
            }
          }
          else {
            bVar2 = param_1 == 3 || param_1 == 4;
            if (param_1 == 3 || param_1 == 4) {
              if (local_24 == 0xbc) goto switchD_20107c58_caseD_bc;
              if ((int)local_24 < 0xbd) {
                if (local_24 == 0xb4) {
switchD_20107a88_caseD_b4:
                  iVar4 = 0xe;
                }
                else if ((int)local_24 < 0xb5) {
                  if (local_24 == 0x6f) goto switchD_20107b38_caseD_6f;
                  if ((int)local_24 < 0x70) {
                    if (local_24 == 0x6b) goto switchD_20107b38_caseD_6b;
                    if (local_24 == 0x6d) goto switchD_20107c58_caseD_bd;
                    if (local_24 == 0x6e) goto switchD_20107b38_caseD_6e;
                  }
                  else {
                    if (local_24 == 0xb1) goto LAB_20107844;
                    if (local_24 == 0xb2) goto LAB_2010784c;
joined_r0x20107978:
                    if (local_24 == 0xb3) goto LAB_20107854;
                  }
                }
                else {
                  switch(local_24) {
                  case 0xb5:
                    goto switchD_20107c34_caseD_b5;
                  case 0xb6:
                    goto switchD_20107c34_caseD_b6;
                  case 0xb7:
                    goto switchD_20107c34_caseD_b7;
                  case 0xb8:
                    goto switchD_20107c34_caseD_b8;
                  case 0xb9:
                    goto switchD_20107c34_caseD_b9;
                  case 0xba:
                    goto switchD_20107b98_caseD_ba;
                  case 0xbb:
                    goto switchD_20107b38_caseD_6b;
                  }
                }
              }
              else {
                switch(local_24) {
                case 0xbd:
                  goto switchD_20107c58_caseD_bd;
                case 0xbe:
                  goto switchD_20107b38_caseD_6e;
                case 0xbf:
switchD_20107b38_caseD_6f:
                  iVar4 = 0x18;
                  break;
                case 0xc0:
                case 0xcc:
                  goto switchD_20107c58_caseD_c0;
                case 0xc2:
switchD_20107b98_caseD_c2:
                  iVar4 = 0x27;
                  break;
                case 0xc3:
                  goto switchD_20107ab8_caseD_c3;
                case 0xc4:
                  goto switchD_20107c58_caseD_c4;
                case 0xc5:
                  goto switchD_20107ab8_caseD_c5;
                case 0xc6:
                  goto switchD_20107b98_caseD_c6;
                case 200:
                  goto switchD_20107c58_caseD_c8;
                case 0xc9:
                  goto switchD_20107c58_caseD_c9;
                case 0xca:
                  goto switchD_20107c58_caseD_ca;
                case 0xce:
                  goto switchD_20107c58_caseD_ce;
                case 0xd0:
                  goto switchD_20107b38_caseD_70;
                }
              }
            }
            else {
              bVar2 = ((param_1 == 5 || param_1 == 6) || param_1 == 7) || bVar2;
              if ((param_1 == 5 || param_1 == 6) || param_1 == 7) {
                if (local_24 == 0xbc) goto switchD_20107c58_caseD_bc;
                if ((int)local_24 < 0xbd) {
                  if (local_24 == 0xb3) goto LAB_20107854;
                  if (0xb3 < (int)local_24) {
                    switch(local_24) {
                    case 0xb4:
                      goto switchD_20107a88_caseD_b4;
                    case 0xb5:
                      goto switchD_20107c34_caseD_b5;
                    case 0xb6:
                      goto switchD_20107c34_caseD_b6;
                    case 0xb7:
                      goto switchD_20107c34_caseD_b7;
                    case 0xb8:
                      goto switchD_20107c34_caseD_b8;
                    case 0xb9:
                      goto switchD_20107c34_caseD_b9;
                    case 0xba:
                      goto switchD_20107b98_caseD_ba;
                    case 0xbb:
                      goto switchD_20107b38_caseD_6b;
                    default:
                      goto switchD_20107c34_default;
                    }
                  }
                  if (local_24 == 0x6e) goto switchD_20107b38_caseD_6e;
                  if (0x6e < (int)local_24) {
                    if (local_24 != 0x6f) {
                      if (local_24 == 0x79) goto LAB_20107b10;
                      if (local_24 != 0xb1) goto joined_r0x201077ac;
                      goto LAB_20107844;
                    }
                    goto switchD_20107b38_caseD_6f;
                  }
                  if (local_24 == 0x14) goto switchD_20107b38_caseD_70;
                  if (local_24 == 0x6a) goto switchD_20107ab8_caseD_c1;
                  if (local_24 != 0x6b) goto joined_r0x20107790;
switchD_20107b38_caseD_6b:
                  iVar4 = 0x15;
                }
                else {
                  switch(local_24) {
                  case 0xbd:
                    goto switchD_20107c58_caseD_bd;
                  case 0xbe:
                    goto switchD_20107b38_caseD_6e;
                  case 0xbf:
                    goto switchD_20107b38_caseD_6f;
                  case 0xc0:
                  case 0xcc:
                    goto switchD_20107c58_caseD_c0;
                  case 0xc1:
                    goto switchD_20107ab8_caseD_c1;
                  case 0xc2:
                    goto switchD_20107b98_caseD_c2;
                  case 0xc3:
                    goto switchD_20107ab8_caseD_c3;
                  case 0xc4:
                    goto switchD_20107c58_caseD_c4;
                  case 0xc5:
                    goto switchD_20107ab8_caseD_c5;
                  case 0xc6:
                    goto switchD_20107b98_caseD_c6;
                  case 200:
                    goto switchD_20107c58_caseD_c8;
                  case 0xc9:
                    goto switchD_20107c58_caseD_c9;
                  case 0xca:
                    goto switchD_20107c58_caseD_ca;
                  case 0xcb:
switchD_20107c58_caseD_cb:
                    iVar4 = 0x1e;
                    break;
                  case 0xce:
                    goto switchD_20107c58_caseD_ce;
                  case 0xcf:
                    goto switchD_20107ab8_caseD_cf;
                  case 0xd0:
                    goto switchD_20107b38_caseD_70;
                  }
                }
              }
              else {
                bVar2 = (param_1 == 8 || param_1 == 9) || bVar2;
                if (param_1 == 8 || param_1 == 9) {
                  if (local_24 == 0xb6) {
switchD_20107c34_caseD_b6:
                    iVar4 = 0x10;
                  }
                  else if ((int)local_24 < 0xb7) {
                    if (local_24 == 0x72) goto switchD_20107c58_caseD_c8;
                    if ((int)local_24 < 0x73) {
                      switch(local_24) {
                      case 0x6b:
                        goto switchD_20107b38_caseD_6b;
                      case 0x6d:
                        goto switchD_20107c58_caseD_bd;
                      case 0x6e:
                        goto switchD_20107b38_caseD_6e;
                      case 0x6f:
                        goto switchD_20107b38_caseD_6f;
                      case 0x70:
                        goto switchD_20107b38_caseD_70;
                      case 0x71:
                        goto switchD_20107c58_caseD_ca;
                      }
                    }
                    else if (local_24 == 0xb2) {
LAB_2010784c:
                      iVar4 = 0xc;
                    }
                    else if ((int)local_24 < 0xb3) {
                      if (local_24 == 0x79) {
LAB_20107b10:
                        iVar4 = 0x14;
                      }
                      else if (local_24 == 0xb1) goto LAB_20107844;
                    }
                    else {
                      if (local_24 == 0xb3) goto LAB_20107854;
                      if (local_24 == 0xb4) goto switchD_20107a88_caseD_b4;
                    }
                  }
                  else {
                    switch(local_24) {
                    case 0xb7:
switchD_20107c34_caseD_b7:
                      iVar4 = 0x11;
                      break;
                    case 0xb8:
switchD_20107c34_caseD_b8:
                      iVar4 = 0x12;
                      break;
                    case 0xb9:
switchD_20107c34_caseD_b9:
                      iVar4 = 0x13;
                      break;
                    case 0xba:
switchD_20107b98_caseD_ba:
                      iVar4 = 0x28;
                      break;
                    case 0xbb:
                      goto switchD_20107b38_caseD_6b;
                    case 0xbc:
                      goto switchD_20107c58_caseD_bc;
                    case 0xbd:
                      goto switchD_20107c58_caseD_bd;
                    case 0xbe:
                      goto switchD_20107b38_caseD_6e;
                    case 0xbf:
                      goto switchD_20107b38_caseD_6f;
                    case 0xc2:
                      goto switchD_20107b98_caseD_c2;
                    case 0xc4:
                      goto switchD_20107c58_caseD_c4;
                    case 0xc6:
                      goto switchD_20107b98_caseD_c6;
                    }
                  }
                }
                else {
                  bVar2 = ((param_1 == 10 || param_1 == 0xb) || param_1 == 0xc) || bVar2;
                  if ((param_1 != 10 && param_1 != 0xb) && param_1 != 0xc) {
                    _DAT_20800128 = local_28;
                    DAT_2080012c = local_24;
                    return;
                  }
                  if (local_24 == 0xbb) goto switchD_20107b38_caseD_6b;
                  if ((int)local_24 < 0xbc) {
                    if (local_24 == 0xb4) goto switchD_20107a88_caseD_b4;
                    if ((int)local_24 < 0xb5) {
                      if (local_24 == 0x6d) goto switchD_20107c58_caseD_bd;
                      if ((int)local_24 < 0x6e) {
                        if (local_24 == 0x14) goto switchD_20107b38_caseD_70;
                        if (local_24 == 0x6b) goto switchD_20107b38_caseD_6b;
                      }
                      else {
                        if (local_24 != 0xb1) goto joined_r0x20107978;
LAB_20107844:
                        iVar4 = 0xb;
                      }
                    }
                    else {
                      switch(local_24) {
                      case 0xb5:
                        goto switchD_20107c34_caseD_b5;
                      case 0xb6:
                        goto switchD_20107c34_caseD_b6;
                      case 0xb7:
                        goto switchD_20107c34_caseD_b7;
                      case 0xb8:
                        goto switchD_20107c34_caseD_b8;
                      case 0xb9:
                        goto switchD_20107c34_caseD_b9;
                      }
                    }
                  }
                  else {
                    switch(local_24) {
                    case 0xbc:
                      goto switchD_20107c58_caseD_bc;
                    case 0xbd:
switchD_20107c58_caseD_bd:
                      iVar4 = 0x16;
                      break;
                    case 0xc0:
                    case 0xcc:
                      goto switchD_20107c58_caseD_c0;
                    case 0xc4:
switchD_20107c58_caseD_c4:
                      iVar4 = 0x17;
                      break;
                    case 200:
switchD_20107c58_caseD_c8:
                      iVar4 = 0x22;
                      break;
                    case 0xc9:
                      goto switchD_20107c58_caseD_c9;
                    case 0xca:
                      goto switchD_20107c58_caseD_ca;
                    case 0xcb:
                      goto switchD_20107c58_caseD_cb;
                    case 0xce:
                      goto switchD_20107c58_caseD_ce;
                    }
                  }
                }
              }
            }
          }
switchD_20107c34_default:
          FUN_20155310(auStack_1a8,auStack_148,0x60);
          goto switchD_20107444_default;
        }
        iVar4 = 10;
      }
      goto LAB_20107cc4;
    }
    if ((local_28 & 0xdd) != 0) goto LAB_20107d28;
    iVar6 = 0x20;
    if ((local_28 & 0x22) == 0) {
      if (DAT_2080010f != '\0') goto LAB_20107538;
LAB_20107548:
      FUN_20155310(auStack_1a8,auStack_88,0x60);
    }
    else {
      if (DAT_2080010f != '\0') goto LAB_20107548;
LAB_20107538:
      iVar6 = 0;
    }
    uVar7 = uVar3 + iVar6 & 0xff;
    switch(uVar5) {
    case 0:
      iVar4 = 0x16;
      break;
    case 1:
      iVar4 = 0x25;
      break;
    case 2:
      iVar4 = 0x23;
      break;
    case 3:
      iVar4 = 0x18;
      break;
    case 4:
      iVar4 = 0xd;
      break;
    case 5:
      iVar4 = 0x19;
      break;
    case 6:
      iVar4 = 0x1a;
      break;
    case 7:
      iVar4 = 0x1b;
      break;
    case 8:
      iVar4 = 0x12;
      break;
    case 9:
      iVar4 = 0x1c;
      break;
    case 10:
      iVar4 = 0x1d;
      break;
    case 0xb:
      iVar4 = 0x1e;
      break;
    case 0xc:
      iVar4 = 0x27;
      break;
    case 0xd:
      iVar4 = 0x26;
      break;
    case 0xe:
      iVar4 = 0x13;
      break;
    case 0xf:
      iVar4 = 0x14;
      break;
    case 0x10:
      iVar4 = 0xb;
      break;
    case 0x11:
      iVar4 = 0xe;
      break;
    case 0x12:
      iVar4 = 0x17;
      break;
    case 0x13:
      iVar4 = 0xf;
      break;
    case 0x14:
      iVar4 = 0x11;
      break;
    case 0x15:
      iVar4 = 0x24;
      break;
    case 0x16:
      iVar4 = 0xc;
      break;
    case 0x17:
      iVar4 = 0x22;
      break;
    case 0x18:
      iVar4 = 0x10;
      break;
    case 0x19:
      iVar4 = 0x21;
      break;
    default:
      goto switchD_20107444_default;
    }
  }
LAB_20107cc4:
  if (uVar3 == 0x14 || uVar3 == 0xc0) {
    FUN_20155310(auStack_1a8,auStack_e8,0x60);
  }
  uVar5 = 0x10;
  uVar1 = auStack_1a8[iVar4];
  if (uVar7 - 0x41 < 0x1a) {
    uVar5 = 0x20;
  }
  if ((bVar2 && uVar3 != 0xc0) && (uVar3 != 0x14)) {
    uVar5 = 0x30;
  }
  mainlink_send_e0(uVar5 | 1,uVar1);
  mainlink_send_e0(uVar5,uVar1);
LAB_20107d28:
  if (uVar3 == 0x1b) {
    kbd_text_clear();
  }
  else if (uVar3 == 8) {
    kbd_text_backspace();
  }
  else if (uVar7 != 0) {
    kbd_text_append(uVar7);
  }
  DAT_2080012c = local_24;
  _DAT_20800128 = local_28;
  return;
}


// ===== FUN_20107d8c @ 20107d8c (144 bytes)

void FUN_20107d8c(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_18 [4];
  undefined4 local_14;
  
  if (param_1 == 5) {
LAB_20107db8:
    uVar3 = 1;
  }
  else {
    if (param_1 < 6) {
      if (param_1 == 0 || param_1 == 3) goto LAB_20107db8;
    }
    else if (param_1 == 8 || param_1 == 10) goto LAB_20107db8;
    uVar3 = 0;
  }
  iVar1 = usbkbd_get_device(auStack_18);
  DAT_2080010f = (undefined1)uVar3;
  uVar2 = (uint)DAT_2080010c;
  if (uVar3 == 0) {
    DAT_2080010c = DAT_2080010c & 0xfd;
  }
  else {
    DAT_2080010c = DAT_2080010c | 2;
  }
  if ((uVar2 & 3) >> 1 != uVar3 && iVar1 != 0) {
    FUN_2013baac(local_14,0,&DAT_2080010c);
  }
  return;
}


// ===== debug_unlock_check @ 20107dc0 (168 bytes)

/* P4_2/P4_3/P8_3 low + Ctrl + Backspace in the HID report */

uint debug_unlock_check(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = gpio_read_bit(4,2);
  iVar3 = gpio_read_bit(4,3);
  iVar4 = gpio_read_bit(8,3);
  uVar1 = (uint)(byte)(iVar2 == 0 | (iVar3 == 0) << 1 | (iVar4 == 0) << 2) << 0x18;
  DAT_20800124 = uVar1;
  if (iVar3 == 0 && iVar4 == 0) {
    itron_dly_tsk(0x1e);
    DAT_20800124 = uVar1 | (uint)DAT_20811225 << 0x10 | (uint)(byte)DAT_2081122c;
    if (((DAT_20811225 & 0x11) != 0) && ((byte)DAT_2081122c == 0x2a)) {
      return DAT_20800124;
    }
  }
  return 0;
}


// ===== debug_unlock @ 20107e68 (56 bytes)

/* sets 0x20450000 = 0xA0B9C8E7; no caller in V01-08 */

void debug_unlock(void)

{
  DAT_20800120 = debug_unlock_check();
  if (DAT_20800120 != 0) {
    DAT_20450000 = 0xa0b9c8e7;
    return;
  }
  return;
}


// ===== usbkbd_last_key @ 20107e90 (12 bytes)

/* first key usage of the last USB keyboard report */

undefined1 usbkbd_last_key(void)

{
  return DAT_2080010d;
}


// ===== FUN_20107e9c @ 20107e9c (68 bytes)

void FUN_20107e9c(void)

{
  int iVar1;
  
  DAT_20800118 = FUN_2014fd24(0,&DAT_2016533c);
  iVar1 = 0;
  do {
    FUN_2015f05c(&DAT_20811080 + iVar1 * 0xd0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  kbd_layout_tables_init();
  return;
}


// ===== FUN_20107ee0 @ 20107ee0 (62 bytes)

undefined * FUN_20107ee0(void)

{
  int iVar1;
  undefined *puVar2;
  bool bVar3;
  
  iVar1 = 2;
  puVar2 = &DAT_20811080;
  while (bVar3 = iVar1 != 0, iVar1 = iVar1 + -1, bVar3) {
    FUN_2015f0cc(puVar2);
    puVar2 = puVar2 + 0xd0;
  }
  return &DAT_20811080;
}


// ===== vk_key_name @ 20107efc (2420 bytes)

/* USB keyboard VK_* names */

void vk_key_name(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  DAT_2045c290 = 8;
  DAT_2045c294 = 0x425f4b56;
  DAT_2045c298 = 0x4b4341;
  DAT_2045c2b4 = 0xd;
  FUN_20163770(&DAT_2045c2b8,"VK_RETURN");
  DAT_2045c2d8 = 0x14;
  FUN_20155310(&DAT_2045c2dc,"VK_CAPITAL",0xb);
  DAT_2045c2fc = 0x20;
  FUN_201637bc(&DAT_2045c300,"VK_SPACE");
  DAT_2045c320 = 0x25;
  DAT_2045c324 = 0x4c5f4b56;
  DAT_2045c328 = 0x544645;
  DAT_2045c344 = 0x26;
  DAT_2045c348 = 0x4b56;
  DAT_2045c34a = 0x555f;
  DAT_2045c34c = 0x50;
  DAT_2045c368 = 0x27;
  FUN_201637bc(&DAT_2045c36c,"VK_RIGHT");
  DAT_2045c38c = 0x28;
  iVar1 = 8;
  DAT_2045c390 = 0x445f4b56;
  DAT_2045c394 = 0x4e574f;
  DAT_2045c3b0 = 0x30;
  FUN_2016378c(&DAT_2045c3b4,"VK_0");
  iVar3 = 1;
  do {
    iVar1 = iVar1 + 1;
    (&DAT_2045c290)[iVar1 * 9] = iVar3 + 0x30;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_20154a30(&local_40,0x20,"VK_%d",iVar3);
    iVar4 = iVar1 * 0x24;
    iVar3 = iVar3 + 1;
    (&DAT_2045c294)[iVar1 * 9] = local_40;
    (&DAT_2045c298)[iVar1 * 9] = local_3c;
    *(undefined4 *)(iVar4 + 0x2045c29c) = local_38;
    *(undefined4 *)(iVar4 + 0x2045c2a0) = local_34;
    *(undefined4 *)(iVar4 + 0x2045c2a4) = local_30;
    *(undefined4 *)(iVar4 + 0x2045c2a8) = local_2c;
    *(undefined4 *)(iVar4 + 0x2045c2ac) = local_28;
    *(undefined4 *)(iVar4 + 0x2045c2b0) = local_24;
  } while (iVar3 < 10);
  iVar3 = 0;
  do {
    iVar2 = iVar1;
    iVar1 = iVar2 + 1;
    (&DAT_2045c290)[iVar1 * 9] = iVar3 + 0x41;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_20154a30(&local_40,0x20,"VK_%c",iVar3 + 0x41);
    iVar4 = iVar1 * 0x24;
    iVar3 = iVar3 + 1;
    (&DAT_2045c294)[iVar1 * 9] = local_40;
    (&DAT_2045c298)[iVar1 * 9] = local_3c;
    *(undefined4 *)(iVar4 + 0x2045c29c) = local_38;
    *(undefined4 *)(iVar4 + 0x2045c2a0) = local_34;
    *(undefined4 *)(iVar4 + 0x2045c2a4) = local_30;
    *(undefined4 *)(iVar4 + 0x2045c2a8) = local_2c;
    *(undefined4 *)(iVar4 + 0x2045c2ac) = local_28;
    *(undefined4 *)(iVar4 + 0x2045c2b0) = local_24;
  } while (iVar3 < 0x1a);
  iVar2 = iVar2 + 2;
  (&DAT_2045c290)[iVar2 * 9] = 0x60;
  FUN_20155310(&DAT_2045c294 + iVar2 * 9,"VK_NUMPAD0",0xb);
  iVar1 = 1;
  do {
    iVar4 = iVar2;
    iVar2 = iVar4 + 1;
    (&DAT_2045c290)[iVar2 * 9] = iVar1 + 0x60;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_20154a30(&local_40,0x20,"VK_NUMPAD%d",iVar1);
    iVar3 = iVar2 * 0x24;
    iVar1 = iVar1 + 1;
    (&DAT_2045c294)[iVar2 * 9] = local_40;
    (&DAT_2045c298)[iVar2 * 9] = local_3c;
    *(undefined4 *)(iVar3 + 0x2045c29c) = local_38;
    *(undefined4 *)(iVar3 + 0x2045c2a0) = local_34;
    *(undefined4 *)(iVar3 + 0x2045c2a4) = local_30;
    *(undefined4 *)(iVar3 + 0x2045c2a8) = local_2c;
    *(undefined4 *)(iVar3 + 0x2045c2ac) = local_28;
    *(undefined4 *)(iVar3 + 0x2045c2b0) = local_24;
  } while (iVar1 < 10);
  iVar1 = iVar4 + 2;
  (&DAT_2045c290)[iVar1 * 9] = 0x6a;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_M",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"ULTI",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"PLY",4);
  (&DAT_2045c290)[(iVar4 + 3) * 9] = 0x6b;
  FUN_201637a0(&DAT_2045c294 + (iVar4 + 3) * 9,"VK_ADD");
  iVar1 = iVar4 + 4;
  (&DAT_2045c290)[iVar1 * 9] = 0x6d;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_S",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"UBTR",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"ACT",4);
  (&DAT_2045c290)[(iVar4 + 5) * 9] = 0x6e;
  FUN_20155310(&DAT_2045c294 + (iVar4 + 5) * 9,"VK_DECIMAL",0xb);
  iVar4 = iVar4 + 6;
  (&DAT_2045c290)[iVar4 * 9] = 0x6f;
  FUN_20163770(&DAT_2045c294 + iVar4 * 9,"VK_DIVIDE");
  iVar1 = 0;
  do {
    iVar2 = iVar4;
    iVar4 = iVar2 + 1;
    (&DAT_2045c290)[iVar4 * 9] = iVar1 + 0x70;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_20154a30(&local_40,0x20,"VK_F%d",iVar1 + 1);
    iVar3 = iVar4 * 0x24;
    iVar1 = iVar1 + 1;
    (&DAT_2045c294)[iVar4 * 9] = local_40;
    (&DAT_2045c298)[iVar4 * 9] = local_3c;
    *(undefined4 *)(iVar3 + 0x2045c29c) = local_38;
    *(undefined4 *)(iVar3 + 0x2045c2a0) = local_34;
    *(undefined4 *)(iVar3 + 0x2045c2a4) = local_30;
    *(undefined4 *)(iVar3 + 0x2045c2a8) = local_2c;
    *(undefined4 *)(iVar3 + 0x2045c2ac) = local_28;
    *(undefined4 *)(iVar3 + 0x2045c2b0) = local_24;
  } while (iVar1 < 0xc);
  (&DAT_2045c290)[(iVar2 + 2) * 9] = 0xa0;
  FUN_20163770(&DAT_2045c294 + (iVar2 + 2) * 9,"VK_LSHIFT");
  (&DAT_2045c290)[(iVar2 + 3) * 9] = 0xa1;
  FUN_20163770(&DAT_2045c294 + (iVar2 + 3) * 9,"VK_RSHIFT");
  iVar1 = iVar2 + 4;
  iVar3 = iVar2 + 5;
  (&DAT_2045c290)[iVar1 * 9] = 0xa2;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_L",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"CONT",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"ROL",4);
  (&DAT_2045c290)[iVar3 * 9] = 0xa3;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar3 * 9),"VK_R",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar3 * 9),"CONT",4);
  builtin_strncpy((char *)(iVar3 * 0x24 + 0x2045c29c),"ROL",4);
  (&DAT_2045c290)[(iVar2 + 6) * 9] = 0xa4;
  FUN_201637bc(&DAT_2045c294 + (iVar2 + 6) * 9,"VK_LMENU");
  (&DAT_2045c290)[(iVar2 + 7) * 9] = 0xa5;
  FUN_201637bc(&DAT_2045c294 + (iVar2 + 7) * 9,"VK_RMENU");
  (&DAT_2045c290)[(iVar2 + 8) * 9] = 0xb1;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 8) * 9,"VK_OEM_EXCLAMATION",0x13);
  (&DAT_2045c290)[(iVar2 + 9) * 9] = 0xb2;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 9) * 9,"VK_OEM_DOUBLEQUOTE",0x13);
  (&DAT_2045c290)[(iVar2 + 10) * 9] = 0xb3;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 10) * 9,"VK_OEM_SHARP",0xd);
  (&DAT_2045c290)[(iVar2 + 0xb) * 9] = 0xb4;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xb) * 9,"VK_OEM_DOLLAR",0xe);
  (&DAT_2045c290)[(iVar2 + 0xc) * 9] = 0xb5;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xc) * 9,"VK_OEM_PERCENT",0xf);
  (&DAT_2045c290)[(iVar2 + 0xd) * 9] = 0xb6;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xd) * 9,"VK_OEM_AMPERSAND",0x11);
  (&DAT_2045c290)[(iVar2 + 0xe) * 9] = 0xb7;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xe) * 9,"VK_OEM_SINGLEQUOTE",0x13);
  (&DAT_2045c290)[(iVar2 + 0xf) * 9] = 0xb8;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0xf) * 9,"VK_OEM_PARENTHESIS_1",0x15);
  (&DAT_2045c290)[(iVar2 + 0x10) * 9] = 0xb9;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x10) * 9,"VK_OEM_PARENTHESIS_2",0x15);
  (&DAT_2045c290)[(iVar2 + 0x11) * 9] = 0xba;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x11) * 9,"VK_OEM_COLON",0xd);
  iVar1 = iVar2 + 0x12;
  (&DAT_2045c290)[iVar1 * 9] = 0xbb;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_P",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"LUS",4);
  (&DAT_2045c290)[(iVar2 + 0x13) * 9] = 0xbc;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x13) * 9,"VK_OEM_COMMA",0xd);
  (&DAT_2045c290)[(iVar2 + 0x14) * 9] = 0xbd;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x14) * 9,"VK_OEM_MINUS",0xd);
  (&DAT_2045c290)[(iVar2 + 0x15) * 9] = 0xbe;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x15) * 9,"VK_OEM_PERIOD",0xe);
  (&DAT_2045c290)[(iVar2 + 0x16) * 9] = 0xbf;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x16) * 9,"VK_OEM_SLASH",0xd);
  (&DAT_2045c290)[(iVar2 + 0x17) * 9] = 0xc0;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x17) * 9,"VK_OEM_ATMARK",0xe);
  iVar1 = iVar2 + 0x18;
  (&DAT_2045c290)[iVar1 * 9] = 0xc1;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_A",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"STER",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c2a0),"ISK",4);
  (&DAT_2045c290)[(iVar2 + 0x19) * 9] = 0xc2;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x19) * 9,"VK_OEM_SEMICOLON",0x11);
  iVar1 = iVar2 + 0x1a;
  (&DAT_2045c290)[iVar1 * 9] = 0xc3;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_L",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"ESST",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c2a0),"HAN",4);
  (&DAT_2045c290)[(iVar2 + 0x1b) * 9] = 0xc4;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x1b) * 9,"VK_OEM_EQUAL",0xd);
  (&DAT_2045c290)[(iVar2 + 0x1c) * 9] = 0xc5;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x1c) * 9,"VK_OEM_GREATERTHAN",0x13);
  iVar1 = iVar2 + 0x1d;
  (&DAT_2045c290)[iVar1 * 9] = 0xc6;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_Q",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"UEST",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c2a0),"ION",4);
  (&DAT_2045c290)[(iVar2 + 0x1e) * 9] = 199;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x1e) * 9,"VK_OEM_BACKQUOTE",0x11);
  (&DAT_2045c290)[(iVar2 + 0x1f) * 9] = 200;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x1f) * 9,"VK_OEM_BRACKET_1",0x11);
  (&DAT_2045c290)[(iVar2 + 0x20) * 9] = 0xc9;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x20) * 9,"VK_OEM_BRACKET_2",0x11);
  (&DAT_2045c290)[(iVar2 + 0x21) * 9] = 0xca;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x21) * 9,"VK_OEM_HAT",0xb);
  (&DAT_2045c290)[(iVar2 + 0x22) * 9] = 0xcb;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x22) * 9,"VK_OEM_BRACKET_3",0x11);
  (&DAT_2045c290)[(iVar2 + 0x23) * 9] = 0xcc;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x23) * 9,"VK_OEM_BRACKET_4",0x11);
  (&DAT_2045c290)[(iVar2 + 0x24) * 9] = 0xcd;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x24) * 9,"VK_OEM_TILDE",0xd);
  iVar1 = iVar2 + 0x25;
  (&DAT_2045c290)[iVar1 * 9] = 0xce;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_U",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"BAR",4);
  (&DAT_2045c290)[(iVar2 + 0x26) * 9] = 0x1b;
  FUN_20163770(&DAT_2045c294 + (iVar2 + 0x26) * 9,"VK_ESCAPE");
  iVar1 = iVar2 + 0x27;
  (&DAT_2045c290)[iVar1 * 9] = 0xcf;
  builtin_strncpy((char *)(&DAT_2045c294 + iVar1 * 9),"VK_O",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar1 * 9),"EM_V",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c29c),"ERTI",4);
  builtin_strncpy((char *)(iVar1 * 0x24 + 0x2045c2a0),"CAL",4);
  (&DAT_2045c290)[(iVar2 + 0x28) * 9] = 0xd0;
  FUN_20155310(&DAT_2045c294 + (iVar2 + 0x28) * 9,"VK_OEM_BACKSLASH",0x11);
  iVar2 = iVar2 + 0x29;
  (&DAT_2045c290)[iVar2 * 9] = 0xd8;
  builtin_strncpy((char *)(iVar2 * 0x24 + 0x2045c29c),"TER",4);
  builtin_strncpy((char *)(&DAT_2045c294 + iVar2 * 9),"VK_N",4);
  builtin_strncpy((char *)(&DAT_2045c298 + iVar2 * 9),"UMEN",4);
  return;
}


// ===== FUN_20108bc8 @ 20108bc8 (1240 bytes)

void FUN_20108bc8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(&DAT_20450290 + param_1 * 0x600) = 0x2a;
  param_1 = param_1 * 0x600;
  *(undefined4 *)(&DAT_20450298 + param_1) = 8;
  *(undefined4 *)(&DAT_2045029c + param_1) = 0x28;
  *(undefined4 *)(&DAT_20450294 + param_1) = 0;
  *(undefined4 *)(&DAT_204502a4 + param_1) = 0xd;
  *(undefined4 *)(&DAT_204502a8 + param_1) = 0x39;
  *(undefined4 *)(&DAT_204502ac + param_1) = 1;
  *(undefined4 *)(&DAT_204502b0 + param_1) = 0x14;
  *(undefined4 *)(&DAT_204502a0 + param_1) = 0;
  *(undefined4 *)(&DAT_204502b4 + param_1) = 0x2c;
  *(undefined4 *)(&DAT_204502b8 + param_1) = 0;
  *(undefined4 *)(&DAT_204502bc + param_1) = 0x20;
  *(undefined4 *)(&DAT_204502c0 + param_1) = 0x50;
  *(undefined4 *)(&DAT_204502c4 + param_1) = 0;
  *(undefined4 *)(&DAT_204502c8 + param_1) = 0x25;
  *(undefined4 *)(&DAT_204502cc + param_1) = 0x52;
  *(undefined4 *)(&DAT_204502d0 + param_1) = 0;
  *(undefined4 *)(&DAT_204502d4 + param_1) = 0x26;
  *(undefined4 *)(&DAT_204502d8 + param_1) = 0x4f;
  *(undefined4 *)(&DAT_204502dc + param_1) = 0;
  *(undefined4 *)(&DAT_204502e0 + param_1) = 0x27;
  *(undefined4 *)(&DAT_204502e4 + param_1) = 0x51;
  *(undefined4 *)(&DAT_204502ec + param_1) = 0x28;
  iVar2 = 1;
  *(undefined4 *)(&DAT_204502f0 + param_1) = 0x27;
  *(undefined4 *)(&DAT_204502e8 + param_1) = 0;
  *(undefined4 *)(&DAT_204502f4 + param_1) = 0;
  *(undefined4 *)(&DAT_204502f8 + param_1) = 0x30;
  do {
    iVar1 = iVar2 * 0xc + param_1;
    *(int *)(&DAT_20450290 + iVar1 + 0x60) = iVar2 + 0x1d;
    iVar3 = iVar2 + 0x30;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_20450290 + iVar1 + 100) = 0;
    *(int *)(&DAT_20450290 + iVar1 + 0x68) = iVar3;
  } while (iVar2 < 10);
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 0xc + param_1;
    *(int *)(&DAT_20450290 + iVar1 + 0xd8) = iVar2 + 4;
    iVar3 = iVar2 + 0x41;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_20450290 + iVar1 + 0xdc) = 0;
    *(int *)(&DAT_20450290 + iVar1 + 0xe0) = iVar3;
  } while (iVar2 < 0x1a);
  *(undefined4 *)(&DAT_204504b8 + param_1) = 0x62;
  *(undefined4 *)(&DAT_204504bc + param_1) = 0;
  *(undefined4 *)(&DAT_204504c0 + param_1) = 0x60;
  iVar2 = 1;
  do {
    iVar1 = iVar2 * 0xc + param_1;
    *(int *)(&DAT_20450290 + iVar1 + 0x228) = iVar2 + 0x58;
    iVar3 = iVar2 + 0x60;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_20450290 + iVar1 + 0x22c) = 0;
    *(int *)(&DAT_20450290 + iVar1 + 0x230) = iVar3;
  } while (iVar2 < 10);
  *(undefined4 *)(&DAT_20450530 + param_1) = 0x55;
  *(undefined4 *)(&DAT_20450534 + param_1) = 0;
  *(undefined4 *)(&DAT_20450538 + param_1) = 0x6a;
  *(undefined4 *)(&DAT_2045053c + param_1) = 0x57;
  *(undefined4 *)(&DAT_20450540 + param_1) = 0;
  *(undefined4 *)(&DAT_20450544 + param_1) = 0x6b;
  *(undefined4 *)(&DAT_20450548 + param_1) = 0x56;
  *(undefined4 *)(&DAT_2045054c + param_1) = 0;
  *(undefined4 *)(&DAT_20450550 + param_1) = 0x6d;
  *(undefined4 *)(&DAT_20450554 + param_1) = 99;
  *(undefined4 *)(&DAT_20450558 + param_1) = 0;
  *(undefined4 *)(&DAT_2045055c + param_1) = 0x6e;
  *(undefined4 *)(&DAT_20450560 + param_1) = 0x54;
  *(undefined4 *)(&DAT_20450564 + param_1) = 0;
  *(undefined4 *)(&DAT_20450568 + param_1) = 0x6f;
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 0xc + param_1;
    *(int *)(&DAT_20450290 + iVar1 + 0x2dc) = iVar2 + 0x3a;
    iVar3 = iVar2 + 0x70;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(&DAT_20450290 + iVar1 + 0x2e0) = 0;
    *(int *)(&DAT_20450290 + iVar1 + 0x2e4) = iVar3;
  } while (iVar2 < 0xc);
  *(undefined4 *)(&DAT_204505fc + param_1) = 0xe1;
  *(undefined4 *)(&DAT_20450600 + param_1) = 0;
  *(undefined4 *)(&DAT_20450604 + param_1) = 0xa0;
  *(undefined4 *)(&DAT_20450608 + param_1) = 0xe5;
  *(undefined4 *)(&DAT_2045060c + param_1) = 0;
  *(undefined4 *)(&DAT_20450610 + param_1) = 0xa1;
  *(undefined4 *)(&DAT_20450614 + param_1) = 0xe0;
  *(undefined4 *)(&DAT_20450618 + param_1) = 0;
  *(undefined4 *)(&DAT_2045061c + param_1) = 0xa2;
  *(undefined4 *)(&DAT_20450620 + param_1) = 0xe4;
  *(undefined4 *)(&DAT_20450624 + param_1) = 0;
  *(undefined4 *)(&DAT_20450628 + param_1) = 0xa3;
  *(undefined4 *)(&DAT_2045062c + param_1) = 0xe2;
  *(undefined4 *)(&DAT_20450630 + param_1) = 0;
  *(undefined4 *)(&DAT_20450634 + param_1) = 0xa4;
  *(undefined4 *)(&DAT_20450638 + param_1) = 0xe6;
  *(undefined4 *)(&DAT_2045063c + param_1) = 0;
  *(undefined4 *)(&DAT_20450640 + param_1) = 0xa5;
  *(undefined4 *)(&DAT_20450644 + param_1) = 0x1e;
  *(undefined4 *)(&DAT_20450648 + param_1) = 1;
  *(undefined4 *)(&DAT_2045064c + param_1) = 0xb1;
  *(undefined4 *)(&DAT_20450650 + param_1) = 0x1f;
  *(undefined4 *)(&DAT_20450654 + param_1) = 1;
  *(undefined4 *)(&DAT_20450658 + param_1) = 0xb2;
  *(undefined4 *)(&DAT_2045065c + param_1) = 0x20;
  *(undefined4 *)(&DAT_20450664 + param_1) = 0xb3;
  *(undefined4 *)(&DAT_20450668 + param_1) = 0x21;
  *(undefined4 *)(&DAT_20450660 + param_1) = 1;
  *(undefined4 *)(&DAT_20450670 + param_1) = 0xb4;
  *(undefined4 *)(&DAT_20450674 + param_1) = 0x22;
  *(undefined4 *)(&DAT_2045066c + param_1) = 1;
  *(undefined4 *)(&DAT_2045067c + param_1) = 0xb5;
  *(undefined4 *)(&DAT_20450680 + param_1) = 0x23;
  *(undefined4 *)(&DAT_20450678 + param_1) = 1;
  *(undefined4 *)(&DAT_20450688 + param_1) = 0xb6;
  *(undefined4 *)(&DAT_2045068c + param_1) = 0x24;
  *(undefined4 *)(&DAT_20450684 + param_1) = 1;
  *(undefined4 *)(&DAT_20450694 + param_1) = 0xb7;
  *(undefined4 *)(&DAT_20450698 + param_1) = 0x25;
  *(undefined4 *)(&DAT_20450690 + param_1) = 1;
  *(undefined4 *)(&DAT_204506a0 + param_1) = 0xb8;
  *(undefined4 *)(&DAT_204506a4 + param_1) = 0x26;
  *(undefined4 *)(&DAT_2045069c + param_1) = 1;
  *(undefined4 *)(&DAT_204506ac + param_1) = 0xb9;
  *(undefined4 *)(&DAT_204506b0 + param_1) = 0x34;
  *(undefined4 *)(&DAT_204506b8 + param_1) = 0xba;
  *(undefined4 *)(&DAT_204506bc + param_1) = 0x33;
  *(undefined4 *)(&DAT_204506a8 + param_1) = 1;
  *(undefined4 *)(&DAT_204506b4 + param_1) = 0;
  *(undefined4 *)(&DAT_204506c4 + param_1) = 0xbb;
  *(undefined4 *)(&DAT_204506c8 + param_1) = 0x36;
  *(undefined4 *)(&DAT_204506d0 + param_1) = 0xbc;
  *(undefined4 *)(&DAT_204506d4 + param_1) = 0x2d;
  *(undefined4 *)(&DAT_204506c0 + param_1) = 1;
  *(undefined4 *)(&DAT_204506cc + param_1) = 0;
  *(undefined4 *)(&DAT_204506dc + param_1) = 0xbd;
  *(undefined4 *)(&DAT_204506e0 + param_1) = 0x37;
  *(undefined4 *)(&DAT_204506d8 + param_1) = 0;
  *(undefined4 *)(&DAT_204506e8 + param_1) = 0xbe;
  *(undefined4 *)(&DAT_204506ec + param_1) = 0x38;
  *(undefined4 *)(&DAT_204506e4 + param_1) = 0;
  *(undefined4 *)(&DAT_204506f4 + param_1) = 0xbf;
  *(undefined4 *)(&DAT_204506f8 + param_1) = 0x2f;
  *(undefined4 *)(&DAT_204506f0 + param_1) = 0;
  *(undefined4 *)(&DAT_204506fc + param_1) = 0;
  *(undefined4 *)(&DAT_20450700 + param_1) = 0xc0;
  *(undefined4 *)(&DAT_20450704 + param_1) = 0x34;
  *(undefined4 *)(&DAT_20450708 + param_1) = 1;
  *(undefined4 *)(&DAT_2045070c + param_1) = 0xc1;
  *(undefined4 *)(&DAT_20450714 + param_1) = 0;
  *(undefined4 *)(&DAT_20450718 + param_1) = 0xc2;
  *(undefined4 *)(&DAT_20450720 + param_1) = 1;
  *(undefined4 *)(&DAT_20450724 + param_1) = 0xc3;
  *(undefined4 *)(&DAT_20450710 + param_1) = 0x33;
  *(undefined4 *)(&DAT_2045071c + param_1) = 0x36;
  *(undefined4 *)(&DAT_20450728 + param_1) = 0x2d;
  *(undefined4 *)(&DAT_2045072c + param_1) = 1;
  *(undefined4 *)(&DAT_20450730 + param_1) = 0xc4;
  *(undefined4 *)(&DAT_20450734 + param_1) = 0x37;
  *(undefined4 *)(&DAT_20450738 + param_1) = 1;
  *(undefined4 *)(&DAT_2045073c + param_1) = 0xc5;
  *(undefined4 *)(&DAT_20450740 + param_1) = 0x38;
  *(undefined4 *)(&DAT_2045074c + param_1) = 0x2f;
  *(undefined4 *)(&DAT_20450744 + param_1) = 1;
  *(undefined4 *)(&DAT_20450748 + param_1) = 0xc6;
  *(undefined4 *)(&DAT_20450754 + param_1) = 199;
  *(undefined4 *)(&DAT_20450758 + param_1) = 0x30;
  *(undefined4 *)(&DAT_20450760 + param_1) = 200;
  *(undefined4 *)(&DAT_20450764 + param_1) = 0x32;
  *(undefined4 *)(&DAT_20450750 + param_1) = 1;
  *(undefined4 *)(&DAT_2045075c + param_1) = 0;
  *(undefined4 *)(&DAT_20450768 + param_1) = 0;
  *(undefined4 *)(&DAT_2045076c + param_1) = 0xc9;
  *(undefined4 *)(&DAT_2045077c + param_1) = 0x30;
  *(undefined4 *)(&DAT_20450788 + param_1) = 0x32;
  *(undefined4 *)(&DAT_20450780 + param_1) = 1;
  *(undefined4 *)(&DAT_20450784 + param_1) = 0xcb;
  *(undefined4 *)(&DAT_20450774 + param_1) = 0;
  *(undefined4 *)(&DAT_20450778 + param_1) = 0xca;
  *(undefined4 *)(&DAT_20450770 + param_1) = 0x2e;
  *(undefined4 *)(&DAT_20450790 + param_1) = 0xcc;
  *(undefined4 *)(&DAT_20450794 + param_1) = 0x2e;
  *(undefined4 *)(&DAT_2045078c + param_1) = 1;
  *(undefined4 *)(&DAT_2045079c + param_1) = 0xcd;
  *(undefined4 *)(&DAT_204507a0 + param_1) = 0x87;
  *(undefined4 *)(&DAT_20450798 + param_1) = 1;
  *(undefined4 *)(&DAT_204507a4 + param_1) = 1;
  *(undefined4 *)(&DAT_204507a8 + param_1) = 0xce;
  *(undefined4 *)(&DAT_204507ac + param_1) = 0x29;
  *(undefined4 *)(&DAT_204507b0 + param_1) = 0;
  *(undefined4 *)(&DAT_204507b4 + param_1) = 0x1b;
  *(undefined4 *)(&DAT_204507bc + param_1) = 1;
  *(undefined4 *)(&DAT_204507c4 + param_1) = 0x87;
  *(undefined4 *)(&DAT_204507c8 + param_1) = 0;
  *(undefined4 *)(&DAT_204507cc + param_1) = 0xd0;
  *(undefined4 *)(&DAT_204507d0 + param_1) = 0x58;
  *(undefined4 *)(&DAT_204507d4 + param_1) = 0;
  *(undefined4 *)(&DAT_204507b8 + param_1) = 0x89;
  *(undefined4 *)(&DAT_204507c0 + param_1) = 0xcf;
  *(undefined4 *)(&DAT_204507d8 + param_1) = 0xd8;
  return;
}


// ===== FUN_201090a0 @ 201090a0 (8 bytes)

void FUN_201090a0(void)

{
  FUN_20108bc8(0);
  return;
}


// ===== FUN_201090a8 @ 201090a8 (432 bytes)

void FUN_201090a8(void)

{
  FUN_20108bc8(1);
  DAT_204508a8 = 0x39;
  DAT_204508ac = 0xfe;
  DAT_204508b0 = 0x14;
  DAT_20450c54 = 1;
  DAT_20450c58 = 0xb2;
  DAT_20450c80 = 0x24;
  DAT_20450c84 = 1;
  DAT_20450c88 = 0xb6;
  DAT_20450c50 = 0x34;
  DAT_20450c8c = 0x34;
  DAT_20450c90 = 0;
  DAT_20450c94 = 0xb7;
  DAT_20450c98 = 0x26;
  DAT_20450c9c = 1;
  DAT_20450ca0 = 0xb8;
  DAT_20450ca4 = 0x27;
  DAT_20450ca8 = 1;
  DAT_20450cac = 0xb9;
  DAT_20450cb0 = 0x33;
  DAT_20450cb4 = 1;
  DAT_20450cb8 = 0xba;
  DAT_20450cc0 = 1;
  DAT_20450cc4 = 0xbb;
  DAT_20450cf8 = 0x1f;
  DAT_20450cfc = 1;
  DAT_20450d00 = 0xc0;
  DAT_20450d04 = 0x25;
  DAT_20450d08 = 1;
  DAT_20450d0c = 0xc1;
  DAT_20450cbc = 0x2e;
  DAT_20450d28 = 0x2e;
  DAT_20450d2c = 0;
  DAT_20450d30 = 0xc4;
  DAT_20450d50 = 0;
  DAT_20450d54 = 199;
  DAT_20450d5c = 0;
  DAT_20450d60 = 200;
  DAT_20450d68 = 0;
  DAT_20450d6c = 0xc9;
  DAT_20450d70 = 0x23;
  DAT_20450d74 = 1;
  DAT_20450d78 = 0xca;
  DAT_20450d4c = 0x35;
  DAT_20450d58 = 0x2f;
  DAT_20450d64 = 0x30;
  DAT_20450d7c = 0x2f;
  DAT_20450d80 = 1;
  DAT_20450d84 = 0xcb;
  DAT_20450d88 = 0x30;
  DAT_20450d8c = 1;
  DAT_20450d90 = 0xcc;
  DAT_20450d94 = 0x35;
  DAT_20450d98 = 1;
  DAT_20450d9c = 0xcd;
  DAT_20450da0 = 0x2d;
  DAT_20450da4 = 1;
  DAT_20450da8 = 0xce;
  DAT_20450dbc = 1;
  DAT_20450dc0 = 0xcf;
  DAT_20450db8 = 0x31;
  DAT_20450dc4 = 0x31;
  DAT_20450dc8 = 0;
  DAT_20450dcc = 0xd0;
  return;
}


// ===== FUN_20109258 @ 20109258 (432 bytes)

void FUN_20109258(void)

{
  FUN_20108bc8(2);
  DAT_20450ea8 = 0x39;
  DAT_20450eac = 0xfe;
  DAT_20450eb0 = 0x14;
  DAT_20451264 = 0xb3;
  DAT_20451280 = 0x24;
  DAT_20451284 = 1;
  DAT_20451288 = 0xb6;
  DAT_20451260 = 0;
  DAT_2045125c = 0x31;
  DAT_2045128c = 0x34;
  DAT_20451290 = 0;
  DAT_20451294 = 0xb7;
  DAT_20451298 = 0x26;
  DAT_2045129c = 1;
  DAT_204512a0 = 0xb8;
  DAT_204512a4 = 0x27;
  DAT_204512a8 = 1;
  DAT_204512ac = 0xb9;
  DAT_204512b0 = 0x33;
  DAT_204512b4 = 1;
  DAT_204512b8 = 0xba;
  DAT_204512c0 = 1;
  DAT_204512c4 = 0xbb;
  DAT_204512f8 = 0x34;
  DAT_204512bc = 0x2e;
  DAT_204512fc = 1;
  DAT_20451300 = 0xc0;
  DAT_20451304 = 0x25;
  DAT_20451308 = 1;
  DAT_2045130c = 0xc1;
  DAT_2045132c = 0;
  DAT_20451330 = 0xc4;
  DAT_2045134c = 0x35;
  DAT_20451350 = 0;
  DAT_20451354 = 199;
  DAT_20451328 = 0x2e;
  DAT_2045135c = 0;
  DAT_20451360 = 200;
  DAT_20451368 = 0;
  DAT_2045136c = 0xc9;
  DAT_20451370 = 0x23;
  DAT_20451374 = 1;
  DAT_20451378 = 0xca;
  DAT_20451358 = 0x2f;
  DAT_20451364 = 0x30;
  DAT_2045137c = 0x2f;
  DAT_20451380 = 1;
  DAT_20451384 = 0xcb;
  DAT_20451388 = 0x30;
  DAT_2045138c = 1;
  DAT_20451390 = 0xcc;
  DAT_20451394 = 0x31;
  DAT_20451398 = 1;
  DAT_2045139c = 0xcd;
  DAT_204513a0 = 0x2d;
  DAT_204513a4 = 1;
  DAT_204513a8 = 0xce;
  DAT_204513bc = 1;
  DAT_204513c0 = 0xcf;
  DAT_204513b8 = 100;
  DAT_204513c4 = 100;
  DAT_204513c8 = 0;
  DAT_204513cc = 0xd0;
  return;
}


// ===== FUN_2010940c @ 2010940c (816 bytes)

void FUN_2010940c(void)

{
  int iVar1;
  int iVar2;
  
  FUN_20108bc8(3);
  DAT_204514f0 = 0x27;
  DAT_204514f4 = 1;
  DAT_204514f8 = 0x30;
  iVar1 = 1;
  do {
    (&DAT_204514f0)[iVar1 * 3] = iVar1 + 0x1d;
    iVar2 = iVar1 + 1;
    (&DAT_204514f4)[iVar1 * 3] = 1;
    (&DAT_204514f8)[iVar1 * 3] = iVar1 + 0x30;
    iVar1 = iVar2;
  } while (iVar2 < 10);
  DAT_204514a8 = 0x39;
  DAT_204514ac = 0xfe;
  DAT_204514b0 = 0x14;
  DAT_20451568 = 0x14;
  DAT_2045156c = 0;
  DAT_20451570 = 0x41;
  DAT_204515f8 = 0x33;
  DAT_204515fc = 0;
  DAT_20451600 = 0x4d;
  DAT_20451628 = 4;
  DAT_2045162c = 0;
  DAT_20451630 = 0x51;
  DAT_20451670 = 0x1d;
  DAT_20451674 = 0;
  DAT_20451678 = 0x57;
  DAT_20451694 = 0x1a;
  DAT_20451698 = 0;
  DAT_2045169c = 0x5a;
  DAT_20451844 = 0x38;
  DAT_20451848 = 0;
  DAT_2045184c = 0xb1;
  DAT_20451854 = 0;
  DAT_20451858 = 0xb2;
  DAT_20451850 = 0x20;
  DAT_2045185c = 0x20;
  DAT_20451860 = 2;
  DAT_20451864 = 0xb3;
  DAT_20451868 = 0x30;
  DAT_2045186c = 0;
  DAT_20451870 = 0xb4;
  DAT_20451874 = 0x34;
  DAT_20451878 = 1;
  DAT_2045187c = 0xb5;
  DAT_20451880 = 0x1e;
  DAT_20451884 = 0;
  DAT_20451888 = 0xb6;
  DAT_2045188c = 0x21;
  DAT_20451890 = 0;
  DAT_20451894 = 0xb7;
  DAT_20451898 = 0x22;
  DAT_2045189c = 0;
  DAT_204518a0 = 0xb8;
  DAT_204518a4 = 0x2d;
  DAT_204518a8 = 0;
  DAT_204518ac = 0xb9;
  DAT_204518b0 = 0x37;
  DAT_204518b4 = 0;
  DAT_204518b8 = 0xba;
  DAT_204518c0 = 1;
  DAT_204518c4 = 0xbb;
  DAT_204518cc = 0;
  DAT_204518d0 = 0xbc;
  DAT_204518d8 = 0;
  DAT_204518dc = 0xbd;
  DAT_204518e4 = 1;
  DAT_204518e8 = 0xbe;
  DAT_204518c8 = 0x10;
  DAT_204518d4 = 0x23;
  DAT_204518e0 = 0x36;
  DAT_204518ec = 0x37;
  DAT_204518bc = 0x2e;
  DAT_204518f0 = 1;
  DAT_204518f4 = 0xbf;
  DAT_204518f8 = 0x27;
  DAT_204518fc = 2;
  DAT_20451900 = 0xc0;
  DAT_20451904 = 0x32;
  DAT_20451908 = 0;
  DAT_2045190c = 0xc1;
  DAT_20451910 = 0x36;
  DAT_20451914 = 0;
  DAT_20451918 = 0xc2;
  DAT_20451920 = 0;
  DAT_20451924 = 0xc3;
  DAT_20451928 = 0x2e;
  DAT_2045191c = 100;
  DAT_2045192c = 0;
  DAT_20451930 = 0xc4;
  DAT_20451934 = 100;
  DAT_20451938 = 1;
  DAT_2045193c = 0xc5;
  DAT_20451940 = 0x10;
  DAT_20451944 = 1;
  DAT_20451948 = 0xc6;
  DAT_2045194c = 0x24;
  DAT_20451950 = 2;
  DAT_20451954 = 199;
  DAT_20451958 = 0x22;
  DAT_2045195c = 2;
  DAT_20451960 = 200;
  DAT_20451964 = 0x2d;
  DAT_20451968 = 2;
  DAT_2045196c = 0xc9;
  DAT_20451970 = 0x26;
  DAT_20451974 = 2;
  DAT_20451978 = 0xca;
  DAT_2045197c = 0x21;
  DAT_20451980 = 2;
  DAT_20451984 = 0xcb;
  DAT_20451988 = 0x2e;
  DAT_2045198c = 2;
  DAT_20451990 = 0xcc;
  DAT_20451994 = 0x1f;
  DAT_20451998 = 2;
  DAT_2045199c = 0xcd;
  DAT_204519a4 = 0;
  DAT_204519a8 = 0xce;
  DAT_204519c0 = 0xcf;
  DAT_204519bc = 2;
  DAT_204519a0 = 0x25;
  DAT_204519b8 = 0x23;
  DAT_204519c4 = 0x25;
  DAT_204519c8 = 2;
  DAT_204519cc = 0xd0;
  return;
}


// ===== FUN_2010973c @ 2010973c (520 bytes)

void FUN_2010973c(void)

{
  FUN_20108bc8(4);
  DAT_20451aa8 = 0x39;
  DAT_20451aac = 0xfe;
  DAT_20451ab0 = 0x14;
  DAT_20451e54 = 1;
  DAT_20451e58 = 0xb2;
  DAT_20451e5c = 0x35;
  DAT_20451e60 = 0;
  DAT_20451e64 = 0xb3;
  DAT_20451e80 = 0x24;
  DAT_20451e84 = 1;
  DAT_20451e88 = 0xb6;
  DAT_20451e8c = 0x36;
  DAT_20451e90 = 1;
  DAT_20451e94 = 0xb7;
  DAT_20451e98 = 0x26;
  DAT_20451e9c = 1;
  DAT_20451ea0 = 0xb8;
  DAT_20451ea4 = 0x27;
  DAT_20451ea8 = 1;
  DAT_20451eac = 0xb9;
  DAT_20451e50 = 0x1f;
  DAT_20451eb0 = 0x33;
  DAT_20451eb4 = 1;
  DAT_20451eb8 = 0xba;
  DAT_20451ebc = 0x2e;
  DAT_20451ec0 = 1;
  DAT_20451ec4 = 0xbb;
  DAT_20451eec = 0x20;
  DAT_20451ef8 = 0x1f;
  DAT_20451ef0 = 1;
  DAT_20451ef4 = 0xbf;
  DAT_20451efc = 2;
  DAT_20451f00 = 0xc0;
  DAT_20451f04 = 0x25;
  DAT_20451f08 = 1;
  DAT_20451f0c = 0xc1;
  DAT_20451f20 = 0;
  DAT_20451f24 = 0xc3;
  DAT_20451f28 = 0x2e;
  DAT_20451f1c = 0x32;
  DAT_20451f2c = 0;
  DAT_20451f30 = 0xc4;
  DAT_20451f34 = 0x32;
  DAT_20451f38 = 1;
  DAT_20451f3c = 0xc5;
  DAT_20451f40 = 0x23;
  DAT_20451f44 = 1;
  DAT_20451f48 = 0xc6;
  DAT_20451f50 = 0;
  DAT_20451f54 = 199;
  DAT_20451f5c = 2;
  DAT_20451f60 = 200;
  DAT_20451f64 = 0x30;
  DAT_20451f68 = 2;
  DAT_20451f6c = 0xc9;
  DAT_20451f4c = 0x34;
  DAT_20451f58 = 0x2f;
  DAT_20451f74 = 0;
  DAT_20451f78 = 0xca;
  DAT_20451f7c = 0x34;
  DAT_20451f80 = 2;
  DAT_20451f84 = 0xcb;
  DAT_20451f88 = 0x32;
  DAT_20451f70 = 0x2f;
  DAT_20451f8c = 2;
  DAT_20451f90 = 0xcc;
  DAT_20451f94 = 0x33;
  DAT_20451f98 = 2;
  DAT_20451f9c = 0xcd;
  DAT_20451fa0 = 0x2d;
  DAT_20451fa4 = 1;
  DAT_20451fa8 = 0xce;
  DAT_20451fb8 = 0x35;
  DAT_20451fbc = 1;
  DAT_20451fc0 = 0xcf;
  DAT_20451fc4 = 0x35;
  DAT_20451fc8 = 2;
  DAT_20451fcc = 0xd0;
  return;
}


// ===== FUN_20109944 @ 20109944 (464 bytes)

void FUN_20109944(void)

{
  FUN_20108bc8(4);
  DAT_20451aa8 = 0x39;
  DAT_20451aac = 0xfe;
  DAT_20451ab0 = 0x14;
  DAT_20451e54 = 1;
  DAT_20451e58 = 0xb2;
  DAT_20451e50 = 0x37;
  DAT_20451e80 = 0x24;
  DAT_20451e84 = 1;
  DAT_20451e88 = 0xb6;
  DAT_20451e8c = 0x26;
  DAT_20451e90 = 1;
  DAT_20451e94 = 0xb7;
  DAT_20451e9c = 1;
  DAT_20451ea0 = 0xb8;
  DAT_20451ea8 = 1;
  DAT_20451eac = 0xb9;
  DAT_20451eb0 = 0x33;
  DAT_20451eb4 = 1;
  DAT_20451eb8 = 0xba;
  DAT_20451ec0 = 1;
  DAT_20451ec4 = 0xbb;
  DAT_20451eec = 0x35;
  DAT_20451ef0 = 1;
  DAT_20451ef4 = 0xbf;
  DAT_20451ef8 = 0x1f;
  DAT_20451efc = 1;
  DAT_20451f00 = 0xc0;
  DAT_20451f08 = 1;
  DAT_20451f0c = 0xc1;
  DAT_20451e98 = 0x36;
  DAT_20451ea4 = 0x27;
  DAT_20451ebc = 0x2e;
  DAT_20451f04 = 0x25;
  DAT_20451f1c = 0x36;
  DAT_20451f28 = 0x2e;
  DAT_20451f20 = 2;
  DAT_20451f24 = 0xc3;
  DAT_20451f34 = 0x37;
  DAT_20451f38 = 2;
  DAT_20451f3c = 0xc5;
  DAT_20451f40 = 0x23;
  DAT_20451f44 = 1;
  DAT_20451f48 = 0xc6;
  DAT_20451f2c = 0;
  DAT_20451f30 = 0xc4;
  DAT_20451f50 = 2;
  DAT_20451f54 = 199;
  DAT_20451f58 = 0x26;
  DAT_20451f4c = 0x2f;
  DAT_20451f5c = 2;
  DAT_20451f60 = 200;
  DAT_20451f64 = 0x27;
  DAT_20451f70 = 0x2f;
  DAT_20451f74 = 0;
  DAT_20451f68 = 2;
  DAT_20451f6c = 0xc9;
  DAT_20451f78 = 0xca;
  DAT_20451f7c = 0x24;
  DAT_20451f80 = 2;
  DAT_20451f84 = 0xcb;
  DAT_20451f88 = 0x25;
  DAT_20451f8c = 2;
  DAT_20451f90 = 0xcc;
  DAT_20451f98 = 2;
  DAT_20451f9c = 0xcd;
  DAT_20451fa4 = 1;
  DAT_20451f94 = 0x30;
  DAT_20451fa0 = 0x2d;
  DAT_20451fa8 = 0xce;
  return;
}


// ===== FUN_20109b14 @ 20109b14 (516 bytes)

void FUN_20109b14(void)

{
  FUN_20108bc8(5);
  DAT_204520a8 = 0x39;
  DAT_204520ac = 0xfe;
  DAT_204520b0 = 0x14;
  DAT_20452288 = 0x1d;
  DAT_2045228c = 0;
  DAT_20452290 = 0x59;
  DAT_20452294 = 0x1c;
  DAT_20452298 = 0;
  DAT_2045229c = 0x5a;
  DAT_2045245c = 0x32;
  DAT_20452460 = 0;
  DAT_20452464 = 0xb3;
  DAT_2045248c = 0x32;
  DAT_20452490 = 1;
  DAT_20452494 = 0xb7;
  DAT_204524b0 = 0x37;
  DAT_204524b4 = 1;
  DAT_204524b8 = 0xba;
  DAT_204524c0 = 0;
  DAT_204524c4 = 0xbb;
  DAT_204524d4 = 0x38;
  DAT_204524bc = 0x30;
  DAT_204524d8 = 0;
  DAT_204524dc = 0xbd;
  DAT_204524f8 = 0x14;
  DAT_204524f0 = 1;
  DAT_204524f4 = 0xbf;
  DAT_204524fc = 2;
  DAT_20452500 = 0xc0;
  DAT_20452508 = 1;
  DAT_2045250c = 0xc1;
  DAT_20452510 = 0x36;
  DAT_20452514 = 1;
  DAT_20452518 = 0xc2;
  DAT_20452520 = 0;
  DAT_20452524 = 0xc3;
  DAT_2045252c = 1;
  DAT_20452530 = 0xc4;
  DAT_204524ec = 0x24;
  DAT_20452528 = 0x27;
  DAT_20452504 = 0x30;
  DAT_2045251c = 100;
  DAT_20452538 = 1;
  DAT_2045253c = 0xc5;
  DAT_20452544 = 1;
  DAT_20452548 = 0xc6;
  DAT_2045254c = 0x2e;
  DAT_20452550 = 1;
  DAT_20452554 = 199;
  DAT_20452558 = 0x25;
  DAT_2045255c = 2;
  DAT_20452560 = 200;
  DAT_20452564 = 0x26;
  DAT_20452568 = 2;
  DAT_2045256c = 0xc9;
  DAT_20452574 = 0;
  DAT_20452578 = 0xca;
  DAT_2045257c = 0x24;
  DAT_20452580 = 2;
  DAT_20452584 = 0xcb;
  DAT_20452588 = 0x27;
  DAT_20452540 = 0x2d;
  DAT_20452570 = 0x35;
  DAT_20452534 = 100;
  DAT_2045258c = 2;
  DAT_20452590 = 0xcc;
  DAT_20452594 = 0x30;
  DAT_204525a4 = 1;
  DAT_204525a8 = 0xce;
  DAT_20452598 = 2;
  DAT_2045259c = 0xcd;
  DAT_204525a0 = 0x38;
  DAT_204525b8 = 100;
  DAT_204525c0 = 0xcf;
  DAT_204525c4 = 0x2d;
  DAT_204525bc = 2;
  DAT_204525c8 = 2;
  DAT_204525cc = 0xd0;
  return;
}


// ===== FUN_20109d24 @ 20109d24 (464 bytes)

void FUN_20109d24(void)

{
  FUN_20108bc8(6);
  DAT_204526a8 = 0x39;
  DAT_204526ac = 0xfe;
  DAT_204526b0 = 0x14;
  DAT_20452a94 = 0xb7;
  DAT_20452ab0 = 0x37;
  DAT_20452ab4 = 1;
  DAT_20452ab8 = 0xba;
  DAT_20452abc = 0x2f;
  DAT_20452a90 = 0;
  DAT_20452a8c = 0x2d;
  DAT_20452ac0 = 0;
  DAT_20452ac4 = 0xbb;
  DAT_20452ad4 = 0x38;
  DAT_20452ad8 = 0;
  DAT_20452adc = 0xbd;
  DAT_20452af0 = 1;
  DAT_20452af4 = 0xbf;
  DAT_20452af8 = 0x1f;
  DAT_20452b04 = 0x2f;
  DAT_20452b08 = 1;
  DAT_20452b0c = 0xc1;
  DAT_20452b10 = 0x36;
  DAT_20452b14 = 1;
  DAT_20452b18 = 0xc2;
  DAT_20452afc = 2;
  DAT_20452b00 = 0xc0;
  DAT_20452b20 = 0;
  DAT_20452b24 = 0xc3;
  DAT_20452b2c = 1;
  DAT_20452b30 = 0xc4;
  DAT_20452aec = 0x24;
  DAT_20452b1c = 100;
  DAT_20452b28 = 0x27;
  DAT_20452b34 = 100;
  DAT_20452b38 = 1;
  DAT_20452b3c = 0xc5;
  DAT_20452b40 = 0x2d;
  DAT_20452b44 = 1;
  DAT_20452b48 = 0xc6;
  DAT_20452b4c = 0x30;
  DAT_20452b50 = 1;
  DAT_20452b54 = 199;
  DAT_20452b58 = 0x25;
  DAT_20452b5c = 2;
  DAT_20452b60 = 200;
  DAT_20452b64 = 0x26;
  DAT_20452b68 = 2;
  DAT_20452b6c = 0xc9;
  DAT_20452b7c = 0x24;
  DAT_20452b74 = 1;
  DAT_20452b78 = 0xca;
  DAT_20452b80 = 2;
  DAT_20452b84 = 0xcb;
  DAT_20452b88 = 0x27;
  DAT_20452b70 = 0x32;
  DAT_20452b8c = 2;
  DAT_20452b90 = 0xcc;
  DAT_20452b94 = 0x32;
  DAT_20452b98 = 0;
  DAT_20452b9c = 0xcd;
  DAT_20452ba0 = 0x38;
  DAT_20452ba4 = 1;
  DAT_20452ba8 = 0xce;
  DAT_20452bbc = 1;
  DAT_20452bc0 = 0xcf;
  DAT_20452bb8 = 0x35;
  DAT_20452bc4 = 0x35;
  DAT_20452bc8 = 0;
  DAT_20452bcc = 0xd0;
  return;
}


// ===== FUN_20109ef4 @ 20109ef4 (408 bytes)

void FUN_20109ef4(void)

{
  FUN_20108bc8(7);
  DAT_20452ca8 = 0x39;
  DAT_20452cac = 0xfe;
  DAT_20452cb0 = 0x14;
  DAT_20453054 = 1;
  DAT_20453058 = 0xb2;
  DAT_20453080 = 0x24;
  DAT_20453084 = 1;
  DAT_20453088 = 0xb6;
  DAT_20453050 = 0x35;
  DAT_2045308c = 0x35;
  DAT_20453090 = 0;
  DAT_20453094 = 0xb7;
  DAT_20453098 = 0x26;
  DAT_2045309c = 1;
  DAT_204530a0 = 0xb8;
  DAT_204530a4 = 0x27;
  DAT_204530a8 = 1;
  DAT_204530ac = 0xb9;
  DAT_204530b4 = 1;
  DAT_204530b8 = 0xba;
  DAT_204530c0 = 1;
  DAT_204530c4 = 0xbb;
  DAT_204530f0 = 0;
  DAT_204530f4 = 0xbf;
  DAT_204530f8 = 0x1f;
  DAT_204530fc = 1;
  DAT_20453100 = 0xc0;
  DAT_20453104 = 0x25;
  DAT_20453108 = 1;
  DAT_2045310c = 0xc1;
  DAT_204530b0 = 0x38;
  DAT_204530bc = 0x2e;
  DAT_204530ec = 0x87;
  DAT_20453110 = 0x38;
  DAT_20453114 = 0;
  DAT_20453118 = 0xc2;
  DAT_20453128 = 0x2e;
  DAT_2045312c = 0;
  DAT_20453130 = 0xc4;
  DAT_20453144 = 1;
  DAT_20453148 = 0xc6;
  DAT_2045314c = 0x2f;
  DAT_20453150 = 0;
  DAT_20453154 = 199;
  DAT_20453174 = 1;
  DAT_20453178 = 0xca;
  DAT_20453170 = 0x34;
  DAT_20453140 = 0x87;
  DAT_20453194 = 0x34;
  DAT_20453198 = 0;
  DAT_2045319c = 0xcd;
  DAT_204531a0 = 0x2d;
  DAT_204531a4 = 1;
  DAT_204531a8 = 0xce;
  DAT_204531bc = 1;
  DAT_204531c0 = 0xcf;
  DAT_204531b8 = 100;
  DAT_204531c4 = 100;
  DAT_204531c8 = 0;
  DAT_204531cc = 0xd0;
  return;
}


// ===== FUN_2010a08c @ 2010a08c (488 bytes)

void FUN_2010a08c(void)

{
  FUN_20108bc8(8);
  DAT_204532a8 = 0x39;
  DAT_204532ac = 0xfe;
  DAT_204532b0 = 0x14;
  DAT_2045365c = 0x20;
  DAT_20453660 = 2;
  DAT_20453664 = 0xb3;
  DAT_20453694 = 0xb7;
  DAT_204536b0 = 0x37;
  DAT_204536b4 = 1;
  DAT_204536b8 = 0xba;
  DAT_20453690 = 0;
  DAT_204536bc = 0x30;
  DAT_2045368c = 0x2d;
  DAT_204536c0 = 0;
  DAT_204536c4 = 0xbb;
  DAT_204536d8 = 0;
  DAT_204536dc = 0xbd;
  DAT_204536ec = 0x24;
  DAT_204536f0 = 1;
  DAT_204536f4 = 0xbf;
  DAT_204536f8 = 0x1f;
  DAT_204536fc = 2;
  DAT_20453700 = 0xc0;
  DAT_20453704 = 0x30;
  DAT_20453708 = 1;
  DAT_2045370c = 0xc1;
  DAT_20453710 = 0x36;
  DAT_20453714 = 1;
  DAT_20453718 = 0xc2;
  DAT_20453720 = 0;
  DAT_20453724 = 0xc3;
  DAT_20453728 = 0x27;
  DAT_2045372c = 1;
  DAT_20453730 = 0xc4;
  DAT_204536d4 = 0x38;
  DAT_2045371c = 100;
  DAT_20453734 = 100;
  DAT_20453738 = 1;
  DAT_2045373c = 0xc5;
  DAT_20453740 = 0x2d;
  DAT_20453744 = 1;
  DAT_20453748 = 0xc6;
  DAT_20453750 = 0;
  DAT_20453754 = 199;
  DAT_2045374c = 0x2f;
  DAT_2045375c = 2;
  DAT_20453760 = 200;
  DAT_20453764 = 0x30;
  DAT_20453758 = 0x2f;
  DAT_20453768 = 2;
  DAT_2045376c = 0xc9;
  DAT_20453770 = 0x2f;
  DAT_20453774 = 1;
  DAT_20453778 = 0xca;
  DAT_2045377c = 0x34;
  DAT_20453780 = 2;
  DAT_20453784 = 0xcb;
  DAT_20453788 = 0x32;
  DAT_2045378c = 2;
  DAT_20453790 = 0xcc;
  DAT_20453794 = 0x21;
  DAT_204537a4 = 1;
  DAT_204537a8 = 0xce;
  DAT_20453798 = 2;
  DAT_2045379c = 0xcd;
  DAT_204537a0 = 0x38;
  DAT_204537b8 = 0x1e;
  DAT_204537bc = 2;
  DAT_204537c0 = 0xcf;
  DAT_204537c8 = 2;
  DAT_204537c4 = 0x35;
  DAT_204537cc = 0xd0;
  return;
}


// ===== FUN_2010a274 @ 2010a274 (452 bytes)

void FUN_2010a274(void)

{
  FUN_20108bc8(9);
  DAT_204538a8 = 0x39;
  DAT_204538ac = 0xfe;
  DAT_204538b0 = 0x14;
  DAT_20453c94 = 0xb7;
  DAT_20453cb0 = 0x37;
  DAT_20453cb4 = 1;
  DAT_20453cb8 = 0xba;
  DAT_20453c90 = 0;
  DAT_20453c8c = 0x2d;
  DAT_20453cbc = 0x30;
  DAT_20453cc0 = 0;
  DAT_20453cc4 = 0xbb;
  DAT_20453cd4 = 0x38;
  DAT_20453cd8 = 0;
  DAT_20453cdc = 0xbd;
  DAT_20453cec = 0x24;
  DAT_20453cf8 = 0x14;
  DAT_20453cf0 = 1;
  DAT_20453cf4 = 0xbf;
  DAT_20453cfc = 2;
  DAT_20453d00 = 0xc0;
  DAT_20453d04 = 0x30;
  DAT_20453d08 = 1;
  DAT_20453d0c = 0xc1;
  DAT_20453d10 = 0x36;
  DAT_20453d14 = 1;
  DAT_20453d18 = 0xc2;
  DAT_20453d20 = 0;
  DAT_20453d24 = 0xc3;
  DAT_20453d28 = 0x27;
  DAT_20453d2c = 1;
  DAT_20453d30 = 0xc4;
  DAT_20453d1c = 100;
  DAT_20453d34 = 100;
  DAT_20453d38 = 1;
  DAT_20453d3c = 0xc5;
  DAT_20453d40 = 0x2d;
  DAT_20453d44 = 1;
  DAT_20453d48 = 0xc6;
  DAT_20453d50 = 2;
  DAT_20453d54 = 199;
  DAT_20453d5c = 1;
  DAT_20453d60 = 200;
  DAT_20453d4c = 0x32;
  DAT_20453d58 = 0x34;
  DAT_20453d68 = 1;
  DAT_20453d6c = 0xc9;
  DAT_20453d74 = 2;
  DAT_20453d78 = 0xca;
  DAT_20453d64 = 0x32;
  DAT_20453d70 = 0x34;
  DAT_20453d7c = 0x34;
  DAT_20453d80 = 0;
  DAT_20453d84 = 0xcb;
  DAT_20453d88 = 0x32;
  DAT_20453d8c = 0;
  DAT_20453d90 = 0xcc;
  DAT_20453d94 = 0x30;
  DAT_20453da4 = 1;
  DAT_20453da8 = 0xce;
  DAT_20453db8 = 0x35;
  DAT_20453dbc = 0;
  DAT_20453dc0 = 0xcf;
  DAT_20453dc4 = 0x2d;
  DAT_20453d98 = 2;
  DAT_20453d9c = 0xcd;
  DAT_20453da0 = 0x38;
  DAT_20453dc8 = 2;
  DAT_20453dcc = 0xd0;
  return;
}


// ===== FUN_2010a438 @ 2010a438 (484 bytes)

void FUN_2010a438(void)

{
  FUN_20108bc8(10);
  DAT_20453ea8 = 0x39;
  DAT_20453eac = 0xfe;
  DAT_20453eb0 = 0x14;
  DAT_2045425c = 0x34;
  DAT_20454260 = 2;
  DAT_20454264 = 0xb3;
  DAT_20454294 = 0xb7;
  DAT_204542b0 = 0x37;
  DAT_204542b4 = 1;
  DAT_204542b8 = 0xba;
  DAT_20454290 = 0;
  DAT_204542bc = 0x30;
  DAT_2045428c = 0x2d;
  DAT_204542c0 = 0;
  DAT_204542c4 = 0xbb;
  DAT_204542d8 = 0;
  DAT_204542dc = 0xbd;
  DAT_204542ec = 0x24;
  DAT_204542f0 = 1;
  DAT_204542f4 = 0xbf;
  DAT_204542f8 = 0x33;
  DAT_204542fc = 2;
  DAT_20454300 = 0xc0;
  DAT_20454304 = 0x30;
  DAT_20454308 = 1;
  DAT_2045430c = 0xc1;
  DAT_20454310 = 0x36;
  DAT_20454314 = 1;
  DAT_20454318 = 0xc2;
  DAT_20454320 = 0;
  DAT_20454324 = 0xc3;
  DAT_20454328 = 0x27;
  DAT_2045432c = 1;
  DAT_20454330 = 0xc4;
  DAT_204542d4 = 0x38;
  DAT_2045431c = 100;
  DAT_20454334 = 100;
  DAT_20454338 = 1;
  DAT_2045433c = 0xc5;
  DAT_20454340 = 0x2d;
  DAT_20454344 = 1;
  DAT_20454348 = 0xc6;
  DAT_2045434c = 0x2d;
  DAT_20454350 = 2;
  DAT_20454354 = 199;
  DAT_2045435c = 2;
  DAT_20454360 = 200;
  DAT_20454364 = 0x30;
  DAT_20454358 = 0x2f;
  DAT_20454368 = 2;
  DAT_2045436c = 0xc9;
  DAT_20454370 = 0x2e;
  DAT_20454374 = 1;
  DAT_20454378 = 0xca;
  DAT_2045437c = 0x2f;
  DAT_20454384 = 0xcb;
  DAT_20454388 = 0x30;
  DAT_20454380 = 3;
  DAT_20454390 = 0xcc;
  DAT_20454398 = 2;
  DAT_2045439c = 0xcd;
  DAT_204543a0 = 0x38;
  DAT_204543a4 = 1;
  DAT_204543a8 = 0xce;
  DAT_204543bc = 1;
  DAT_204543c0 = 0xcf;
  DAT_204543b8 = 0x35;
  DAT_20454394 = 0x32;
  DAT_2045438c = 3;
  DAT_204543c4 = 0x35;
  DAT_204543c8 = 0;
  DAT_204543cc = 0xd0;
  return;
}


// ===== kbd_layout_tables_init @ 2010a630 (84 bytes)

/* fills the keyboard layout tables 0x20450290 / 0x2045C290 */

undefined4 kbd_layout_tables_init(void)

{
  memclr(&DAT_20450290,0xc000);
  memclr(&DAT_2045c290,0x1200);
  vk_key_name();
  FUN_201090a0();
  FUN_201090a8();
  FUN_20109258();
  FUN_20109b14();
  FUN_2010940c();
  FUN_2010973c();
  FUN_20109ef4();
  FUN_20109d24();
  FUN_2010a08c();
  FUN_2010a274();
  FUN_2010a438();
  return 0;
}


// ===== FUN_2010a684 @ 2010a684 (212 bytes)

undefined4 FUN_2010a684(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  iVar1 = 0;
  do {
    iVar2 = *(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600);
    if (param_2 == 0) {
      if ((iVar2 == param_1) && (*(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 4) == 0))
      goto LAB_2010a744;
      if (iVar2 == param_1) {
        iVar2 = *(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 4);
        goto joined_r0x2010a728;
      }
    }
    else {
      if (iVar2 == param_1) {
        uVar3 = *(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 8) - 0x41;
        bVar4 = uVar3 == 0x19;
        if (uVar3 < 0x1a) {
          bVar4 = param_2 == 1;
        }
        if (bVar4) goto LAB_2010a744;
      }
      if ((iVar2 == param_1) &&
         (*(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 4) == param_2))
      goto LAB_2010a744;
      if (iVar2 == param_1) {
        iVar2 = *(int *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 4);
joined_r0x2010a728:
        if (iVar2 == 0xfe) {
LAB_2010a744:
          return *(undefined4 *)(&DAT_20450290 + iVar1 * 0xc + param_3 * 0x600 + 8);
        }
      }
    }
    iVar1 = iVar1 + 1;
    if (0x7f < iVar1) {
      return 0xffffffff;
    }
  } while( true );
}


// ===== vk_name_lookup @ 2010a758 (60 bytes)

undefined4 * vk_name_lookup(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_2045c290)[iVar1 * 9] == param_1) {
      return &DAT_2045c294 + iVar1 * 9;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x80);
  return (undefined4 *)0x0;
}


// ===== kbdtest_draw @ 2010a79c (180 bytes)

/* F12 overlay: layout, usage hex, VK name */

void kbdtest_draw(undefined4 param_1)

{
  undefined1 auStack_50 [64];
  
  if (((ushort)DAT_20808a84 & 0x800) != 0) {
    DAT_20800130 = 0;
    fb_fill_rect(param_1,0xf800,0x28,10,400,100);
    FUN_2013608c(param_1,(&PTR_DAT_20800134)[DAT_20800130],0x32);
    sprintf(auStack_50,"%02X",DAT_20811282);
    FUN_2013608c(param_1,auStack_50,0x50,0x32);
    if (DAT_20811288 != 0) {
      FUN_2013608c(param_1,DAT_20811288,0x6e,0x32);
    }
  }
  return;
}


// ===== kbdtest_record @ 2010a864 (52 bytes)

void kbdtest_record(undefined1 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_2010a684();
  DAT_20811288 = vk_name_lookup();
  DAT_20811282 = param_1;
  DAT_20811284 = uVar1;
  DAT_20811280 = DAT_20811280 + '\x01';
  return;
}


// ===== kbdtest_line @ 2010a898 (96 bytes)

/* record last usage + modifier class for the F12 overlay */

void kbdtest_line(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(param_2 + 5);
  if (*(char *)(param_2 + 0xc) == '\0' && bVar1 == 0) {
    return;
  }
  uVar2 = 0;
  if ((bVar1 & 0x22) == 0) {
    if ((bVar1 & 0x40) == 0) {
      if (bVar1 == 0) goto LAB_2010a8e8;
    }
    else if ((bVar1 & 0xbf) == 0) {
      uVar2 = 2;
      goto LAB_2010a8e8;
    }
  }
  else if ((bVar1 & 0xdd) == 0) {
    uVar2 = 1;
    goto LAB_2010a8e8;
  }
  uVar2 = 0xff;
LAB_2010a8e8:
  kbdtest_record(*(char *)(param_2 + 0xc),uVar2,DAT_20800130);
  return;
}


// ===== kbdtest_init @ 2010a8f8 (28 bytes)

/* returns kbdtest_line */

code * kbdtest_init(void)

{
  DAT_20800130 = 0;
  kbd_layout_tables_init();
  return kbdtest_line;
}


// ===== be_bytes_to_u32 @ 2010a918 (40 bytes)

/* big-endian bytes to integer */

int be_bytes_to_u32(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < param_2; iVar2 = iVar2 + 1) {
    iVar1 = (uint)*(byte *)(param_1 + iVar2) + iVar1 * 0x100;
  }
  return iVar1;
}


// ===== sum8_neg_append @ 2010a940 (52 bytes)

/* appends the negated 8-bit sum */

void sum8_neg_append(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  cVar2 = '\0';
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    cVar2 = cVar2 + *(char *)(param_1 + iVar1);
  }
  *(char *)(param_1 + param_2) = -cVar2;
  return;
}


// ===== isp_relay_mode_cmd @ 2010a974 (188 bytes)

/* same F1 <code> frame (DSP 02/82) */

undefined4 isp_relay_mode_cmd(int *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  
  iVar2 = 0;
  local_1c = (uint)CONCAT11(param_2,0xf1);
  local_18 = (uint)(byte)(param_2 - 0xf) << 0x18;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  while( true ) {
    itron_dly_tsk(1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_1c,8);
    if (iVar1 != 8) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_28,1,100);
    if ((iVar1 != -1) && ((char)local_28 == '\x06')) break;
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return 0;
    }
  }
  return 1;
}


// ===== crc16_xmodem @ 2010aa30 (76 bytes)

/* CRC-16 poly 0x1021 init 0 (NXP framing) */

void crc16_xmodem(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar4 = 0;
  while (uVar4 < param_2) {
    uVar3 = 0;
    uVar2 = uVar2 ^ (uint)*(byte *)(param_1 + uVar4) << 8;
    do {
      uVar1 = uVar2 & 0x8000;
      uVar2 = uVar2 << 1;
      uVar3 = uVar3 + 1;
      if (uVar1 != 0) {
        uVar2 = uVar2 ^ 0x1021;
      }
      uVar4 = uVar4 + (7 < uVar3);
    } while (7 >= uVar3);
  }
  return;
}


// ===== dsp_isp_ping @ 2010aa7c (248 bytes)

/* 5A A6 ping -> 5A A7 */

undefined4 dsp_isp_ping(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  char local_20;
  
  local_38 = 0x5a;
  local_37 = 2;
  iVar2 = 0;
  local_36 = 0;
  local_34 = 0xa6;
  local_35 = 0x5a;
  local_33 = 0x5c;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  while( true ) {
    itron_dly_tsk(1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_38,6);
    if (iVar1 != 6) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_30,1,100);
    if ((((iVar1 != -1) && ((char)local_30 == '\x06')) &&
        (iVar1 = (**(code **)(*param_1 + 0x18))(param_1,auStack_24,0xe,100), iVar1 != -1)) &&
       (local_20 == -0x59)) break;
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return 0;
    }
  }
  return 1;
}


// ===== dsp_isp_write_image @ 2010ab74 (1408 bytes)

/* WriteMemory 256 B per packet from 0x08000000 */

undefined4 dsp_isp_write_image(int *param_1,undefined4 param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 extraout_r1;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int local_194;
  int local_190;
  char *local_18c;
  char local_188 [5];
  undefined2 local_183;
  undefined1 local_181;
  undefined1 local_180;
  undefined1 auStack_17f [256];
  char local_7f;
  char local_7c [5];
  undefined2 local_77;
  undefined1 local_75;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_6d;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  undefined1 local_65;
  undefined1 local_64;
  char local_63;
  char local_60 [4];
  char local_5c;
  char local_57;
  char local_53;
  char local_52;
  char local_51;
  char local_50;
  undefined1 auStack_48 [24];
  undefined1 auStack_30 [12];
  
  iVar10 = 0;
  iVar9 = 0;
  memclr(local_60,0x18);
  memclr(local_7c,0x1c);
  memclr(local_188,0x10c);
  local_7c[0] = 'Z';
  local_7c[1] = 0x16;
  local_7c[4] = 0xa4;
  local_70 = 3;
  local_7c[2] = 0;
  local_7c[3] = 0x5a;
  local_74 = 0;
  local_73 = 4;
  local_6f = 0;
  local_68 = 0;
  local_6e = 0;
  local_67 = 9;
  local_6d = 0;
  local_6c = 0;
  local_188[0] = 'Z';
  local_6b = 0;
  local_188[1] = 6;
  local_6a = 1;
  local_188[2] = 1;
  local_69 = 0;
  local_188[3] = 0x5a;
  local_77 = 0x10;
  local_188[4] = 0xa5;
  local_75 = 0;
  local_72 = 1;
  local_66 = 0;
  local_71 = 0;
  local_65 = 0;
  local_64 = 0;
  local_183 = 0x100;
  thunk_FUN_2014af64(param_2,&local_194);
  uVar7 = 0;
  if (local_194 != 0) {
    progress_scale(&DAT_20800178,extraout_r1,0,0x3ff00000);
    progress_set();
    progress_range_init(auStack_30,DAT_2080017c,99);
    sfl_stream_init(auStack_48,param_2,0,param_1);
    itron_dly_tsk(100);
    iVar6 = dsp_isp_ping(param_1);
    uVar7 = 0;
    if (iVar6 != 0) {
LAB_2010acc8:
      local_190 = sfl_stream_read(auStack_17f,1,0x100,auStack_48);
      if (local_190 != 0) {
        iVar11 = 0;
        iVar6 = iVar9 * 0x100 + 0x8000000;
        local_6f = 0;
        local_6e = (undefined1)((uint)iVar6 >> 8);
        local_6c = (undefined1)((uint)iVar6 >> 0x18);
        local_18c = local_7c + 2;
        local_6d = (undefined1)((uint)iVar6 >> 0x10);
        do {
          uVar4 = local_77;
          cVar3 = local_7c[4];
          cVar2 = local_7c[3];
          local_75 = (undefined1)local_77;
          uVar8 = (uint)local_77;
          local_74 = local_77._1_1_;
          local_77 = CONCAT11(local_7c[4],local_7c[3]);
          uVar5 = crc16_xmodem(local_18c + 3,uVar8 + 4);
          local_7c[4] = cVar3;
          local_77 = uVar4;
          local_75 = (char)uVar5;
          local_7c[3] = cVar2;
          local_74 = (char)((ushort)uVar5 >> 8);
          iVar6 = 0;
          do {
            pcVar1 = local_7c + iVar6;
            iVar6 = iVar6 + 1;
            local_63 = local_63 + *pcVar1;
          } while (iVar6 < 0x19);
          iVar6 = (**(code **)(*param_1 + 0x24))(param_1,local_7c,0x1a);
          if (iVar6 != 0x1a) {
            return 0;
          }
          iVar6 = (**(code **)(*param_1 + 0x18))(param_1,local_60,1,100);
          if (((((iVar6 != -1) && (local_60[0] == '\x06')) &&
               (iVar6 = (**(code **)(*param_1 + 0x18))(param_1,local_60,6,100), iVar6 != -1)) &&
              ((local_5c == -0x5f &&
               (iVar6 = (**(code **)(*param_1 + 0x18))(param_1,local_60,0x16,100), iVar6 != -1))))
             && (local_57 == -0x60)) {
            cVar2 = local_53;
            if (local_53 == '\0') {
              cVar2 = local_52;
            }
            if (local_53 != '\0' || cVar2 != '\0') {
              return 0;
            }
            cVar2 = local_51;
            if (local_51 == '\0') {
              cVar2 = local_50;
            }
            if (local_51 != '\0' || cVar2 != '\0') {
              return 0;
            }
            iVar6 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
            if (iVar6 != 6) {
              return 0;
            }
            iVar6 = (**(code **)(*param_1 + 0x18))(param_1,local_60,1,100);
            if ((iVar6 != -1) && (local_60[0] == '\x06')) goto LAB_2010aed8;
          }
          iVar11 = iVar11 + 1;
          if (4 < iVar11) {
            return 0;
          }
        } while( true );
      }
      uVar7 = 1;
    }
  }
  return uVar7;
LAB_2010aed8:
  iVar6 = 0;
  local_18c = local_188 + 2;
  do {
    uVar4 = local_183;
    cVar3 = local_188[4];
    cVar2 = local_188[3];
    local_180 = local_183._1_1_;
    local_181 = (undefined1)local_183;
    uVar8 = (uint)local_183;
    local_183 = CONCAT11(local_188[4],local_188[3]);
    uVar5 = crc16_xmodem(local_18c + 3,uVar8 + 4);
    local_188[4] = cVar3;
    local_183 = uVar4;
    local_181 = (char)uVar5;
    local_188[3] = cVar2;
    local_180 = (char)((ushort)uVar5 >> 8);
    iVar11 = 0;
    do {
      pcVar1 = local_188 + iVar11;
      iVar11 = iVar11 + 1;
      local_7f = local_7f + *pcVar1;
    } while (iVar11 < 0x109);
    iVar11 = (**(code **)(*param_1 + 0x24))(param_1,local_188,0x10a);
    if (iVar11 != 0x10a) {
      return 0;
    }
    iVar11 = (**(code **)(*param_1 + 0x18))(param_1,local_60,1,100);
    if ((((iVar11 != -1) && (local_60[0] == '\x06')) &&
        (iVar11 = (**(code **)(*param_1 + 0x18))(param_1,local_60,6,100), iVar11 != -1)) &&
       (((local_5c == -0x5f &&
         (iVar11 = (**(code **)(*param_1 + 0x18))(param_1,local_60,0x16,100), iVar11 != -1)) &&
        (local_57 == -0x60)))) {
      cVar2 = local_53;
      if (local_53 == '\0') {
        cVar2 = local_52;
      }
      if (local_53 != '\0' || cVar2 != '\0') {
        return 0;
      }
      cVar2 = local_51;
      if (local_51 == '\0') {
        cVar2 = local_50;
      }
      if (local_51 != '\0' || cVar2 != '\0') {
        return 0;
      }
      iVar11 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
      if (iVar11 != 6) {
        return 0;
      }
      iVar11 = (**(code **)(*param_1 + 0x18))(param_1,local_60,1,100);
      if ((iVar11 != -1) && (local_60[0] == '\x06')) break;
    }
    iVar6 = iVar6 + 1;
    if (4 < iVar6) {
      return 0;
    }
  } while( true );
  iVar10 = iVar10 + local_190;
  uVar12 = FUN_20164d82(local_194);
  uVar13 = FUN_20164d82(iVar10);
  uVar12 = FUN_201649d8((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,
                        (int)((ulonglong)uVar12 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar12 >> 0x20);
  progress_scale(auStack_30,uVar7,(int)uVar12,uVar7);
  progress_set();
  iVar9 = iVar9 + 1;
  goto LAB_2010acc8;
}


// ===== dsp_isp_erase_region @ 2010b0f4 (620 bytes)

/* FlashEraseRegion 0x08000000, 0xA0000, 9 */

undefined4 dsp_isp_erase_region(int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  char local_50 [28];
  char local_34 [4];
  char local_30;
  char local_2b;
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  
  memclr(local_34,0x18);
  memclr(local_50,0x1c);
  local_50[0] = 'Z';
  local_50[1] = 0x16;
  local_50[8] = 0;
  local_50[9] = 2;
  local_50[0xc] = 3;
  local_50[0x10] = 8;
  local_50[2] = 0;
  local_50[0x11] = 0;
  local_50[3] = 0x5a;
  local_50[0x12] = 0;
  local_50[4] = 0xa4;
  local_50[0x13] = 10;
  local_50[0x14] = 0;
  local_50[0x18] = 0;
  local_50[0x15] = 9;
  local_50[0xd] = 0;
  local_50[5] = 0x5a;
  local_50[10] = 0;
  local_50[0xe] = 0;
  local_50[0x16] = 0;
  local_50[6] = 0xa4;
  local_50[0xb] = 0;
  local_50[0xf] = 0;
  local_50[0x17] = 0;
  local_50[7] = 0x10;
  uVar3 = crc16_xmodem(local_50 + 5,0x14);
  local_50[4] = 0xa4;
  local_50[5] = 0x10;
  local_50[6] = 0;
  local_50[7] = (char)uVar3;
  local_50[8] = (char)((ushort)uVar3 >> 8);
  local_50[3] = 0x5a;
  iVar4 = dsp_isp_ping(param_1);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = local_50 + iVar4;
      iVar4 = iVar4 + 1;
      iVar5 = 0;
      local_50[0x19] = local_50[0x19] + *pcVar1;
    } while (iVar4 < 0x19);
    do {
      itron_dly_tsk(1);
      iVar4 = (**(code **)(*param_1 + 0x24))(param_1,local_50,0x1a);
      if (iVar4 != 0x1a) {
        return 0;
      }
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,1,100);
      if (((((iVar4 != -1) && (local_34[0] == '\x06')) &&
           (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,6,1000), iVar4 != -1)) &&
          ((local_30 == -0x5f &&
           (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,0x16,100), iVar4 != -1)))) &&
         (local_2b == -0x60)) {
        cVar2 = local_27;
        if (local_27 == '\0') {
          cVar2 = local_26;
        }
        if (local_27 != '\0' || cVar2 != '\0') {
          return 0;
        }
        cVar2 = local_25;
        if (local_25 == '\0') {
          cVar2 = local_24;
        }
        if (local_25 != '\0' || cVar2 != '\0') {
          return 0;
        }
        iVar4 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
        if (iVar4 != 6) {
          return 0;
        }
        iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_34,1,100);
        if ((iVar4 != -1) && (local_34[0] == '\x06')) {
          return 1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
  }
  return 0;
}


// ===== dsp_isp_configure_memory @ 2010b360 (604 bytes)

/* ConfigureMemory 9 (FlexSPI NOR), 0x1C000 */

undefined4 dsp_isp_configure_memory(int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  char local_50 [24];
  char local_38 [4];
  char local_34;
  char local_2f;
  char local_2b;
  char local_2a;
  char local_29;
  char local_28;
  
  memclr(local_38,0x18);
  memclr(local_50,0x18);
  local_50[0] = 'Z';
  local_50[1] = 0x12;
  local_50[8] = 0;
  local_50[9] = 0x11;
  local_50[0xc] = 2;
  local_50[0xd] = 9;
  local_50[0x10] = 0;
  local_50[4] = 0xa4;
  local_50[0x11] = 0;
  local_50[2] = 0;
  local_50[5] = 0x5a;
  local_50[0x12] = 0xc0;
  local_50[3] = 0x5a;
  local_50[10] = 0;
  local_50[0xe] = 0;
  local_50[6] = 0xa4;
  local_50[0x13] = 1;
  local_50[0xb] = 0;
  local_50[0xf] = 0;
  local_50[0x14] = 0;
  local_50[7] = 0xc;
  uVar3 = crc16_xmodem(local_50 + 5,0x10);
  local_50[4] = 0xa4;
  local_50[5] = 0xc;
  local_50[6] = 0;
  local_50[7] = (char)uVar3;
  local_50[8] = (char)((ushort)uVar3 >> 8);
  local_50[3] = 0x5a;
  iVar4 = dsp_isp_ping(param_1);
  if (iVar4 != 0) {
    iVar4 = 0;
    do {
      pcVar1 = local_50 + iVar4;
      iVar4 = iVar4 + 1;
      iVar5 = 0;
      local_50[0x15] = local_50[0x15] + *pcVar1;
    } while (iVar4 < 0x15);
    do {
      itron_dly_tsk(1);
      iVar4 = (**(code **)(*param_1 + 0x24))(param_1,local_50,0x16);
      if (iVar4 != 0x16) {
        return 0;
      }
      iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_38,1,100);
      if (((((iVar4 != -1) && (local_38[0] == '\x06')) &&
           (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_38,6,100), iVar4 != -1)) &&
          ((local_34 == -0x5f &&
           (iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_38,0x16,100), iVar4 != -1)))) &&
         (local_2f == -0x60)) {
        cVar2 = local_2b;
        if (local_2b == '\0') {
          cVar2 = local_2a;
        }
        if (local_2b != '\0' || cVar2 != '\0') {
          return 0;
        }
        cVar2 = local_29;
        if (local_29 == '\0') {
          cVar2 = local_28;
        }
        if (local_29 != '\0' || cVar2 != '\0') {
          return 0;
        }
        iVar4 = (**(code **)(*param_1 + 0x24))(param_1,&DAT_20800170,6);
        if (iVar4 != 6) {
          return 0;
        }
        iVar4 = (**(code **)(*param_1 + 0x18))(param_1,local_38,1,100);
        if ((iVar4 != -1) && (local_38[0] == '\x06')) {
          return 1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
  }
  return 0;
}

