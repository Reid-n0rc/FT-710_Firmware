// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== cpu_delay_cycles4 @ 2013b54c (64 bytes)

/* Spins on the CP15 cycle counter until 4 counts have passed [fact] */

void cpu_delay_cycles4(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  do {
    iVar2 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  } while ((uint)(iVar2 - iVar1) < 4);
  DAT_20808abc = iVar2 - iVar1;
  return;
}


// ===== usbh0_isr @ 2013b58c (12 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* USB0 interrupt (GIC 73, peripherals.md): reads and clears INTSTS0/INTSTS1, counts the causes in
   0x2090BB0C.., masks BRDY/NRDY/BEMP, and sets the port event flags 0x2090B674/680/67C [fact] */

void usbh0_isr(void)

{
  word wVar1;
  word wVar2;
  word wVar3;
  word wVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  
  wVar2 = USB_INTSTS0_0;
  USB_INTSTS0_0 = ~wVar2;
  wVar4 = USB_INTENB0_0;
  wVar3 = USB_INTSTS1_0;
  USB_INTSTS1_0 = ~wVar3;
  wVar1 = USB_INTENB1_0;
  uVar5 = 0;
  uVar6 = 0;
  bVar8 = (wVar2 & 0x8000) != 0;
  iVar7 = 0;
  if (bVar8) {
    _DAT_2090bb0c = _DAT_2090bb0c + 1;
  }
  bVar9 = (wVar2 & 0x2000) != 0;
  if (bVar9) {
    _DAT_2090bb10 = _DAT_2090bb10 + 1;
  }
  bVar10 = (wVar2 & 0x400) != 0;
  bVar11 = (wVar4 & 0x400) != 0;
  if (bVar10 && bVar11) {
    wVar4 = wVar4 & 0xfbff;
    uVar5 = 8;
    _DAT_2090bb14 = _DAT_2090bb14 + 1;
  }
  bVar12 = (wVar2 & 0x200) != 0;
  bVar13 = (wVar4 & 0x200) != 0;
  if (bVar12 && bVar13) {
    wVar4 = wVar4 & 0xfdff;
    uVar5 = uVar5 | 0x10;
    _DAT_2090bb18 = _DAT_2090bb18 + 1;
  }
  if ((wVar2 & 0x100) == 0 || (wVar4 & 0x100) == 0) {
    if (((!bVar12 || !bVar13) && ((!bVar10 || !bVar11) && (!bVar9 && !bVar8))) && (wVar2 != 0)) {
      _DAT_2090bb20 = _DAT_2090bb20 + 1;
    }
  }
  else {
    wVar4 = wVar4 & 0xfeff;
    iVar7 = 1;
    _DAT_2090bb1c = _DAT_2090bb1c + 1;
    _DAT_2090bb04 = 0;
  }
  USB_INTENB0_0 = wVar4;
  if ((wVar3 & 0x800) != 0 && (wVar1 & 0x800) != 0) {
    uVar5 = uVar5 | 2;
    _DAT_2090bb24 = _DAT_2090bb24 + 1;
  }
  if (((wVar3 & 0x1000) != 0) && (_DAT_2090bb28 = _DAT_2090bb28 + 1, (wVar1 & 0x1000) != 0)) {
    uVar5 = uVar5 | 1;
    usbh_pipe_mark_done(0,0);
    FUN_20139658(0,0);
  }
  if ((wVar3 & 0x20) != 0) {
    uVar6 = 2;
    _DAT_2090bb2c = _DAT_2090bb2c + 1;
  }
  if ((wVar3 & 0x10) != 0) {
    uVar6 = uVar6 | 1;
    _DAT_2090bb30 = _DAT_2090bb30 + 1;
  }
  if (uVar5 != 0) {
    itron_set_flg(_DAT_2090b674,uVar5);
  }
  if (iVar7 != 0) {
    itron_set_flg(_DAT_2090b680,iVar7);
  }
  if (uVar6 != 0) {
    itron_set_flg(_DAT_2090b67c,uVar6);
    return;
  }
  return;
}


// ===== usbh1_isr @ 2013b598 (12 bytes)

/* USB1 interrupt (GIC 74): the same handler for port 1 (peripherals.md) [fact for the vector] */

void usbh1_isr(void)

{
  word wVar1;
  word wVar2;
  word wVar3;
  word wVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  
  wVar2 = USB_INTSTS0_1;
  USB_INTSTS0_1 = ~wVar2;
  wVar4 = USB_INTENB0_1;
  wVar3 = USB_INTSTS1_1;
  USB_INTSTS1_1 = ~wVar3;
  wVar1 = USB_INTENB1_1;
  uVar5 = 0;
  uVar6 = 0;
  bVar8 = (wVar2 & 0x8000) != 0;
  iVar7 = 0;
  if (bVar8) {
    iRam2090bfe4 = iRam2090bfe4 + 1;
  }
  bVar9 = (wVar2 & 0x2000) != 0;
  if (bVar9) {
    iRam2090bfe8 = iRam2090bfe8 + 1;
  }
  bVar10 = (wVar2 & 0x400) != 0;
  bVar11 = (wVar4 & 0x400) != 0;
  if (bVar10 && bVar11) {
    wVar4 = wVar4 & 0xfbff;
    uVar5 = 8;
    iRam2090bfec = iRam2090bfec + 1;
  }
  bVar12 = (wVar2 & 0x200) != 0;
  bVar13 = (wVar4 & 0x200) != 0;
  if (bVar12 && bVar13) {
    wVar4 = wVar4 & 0xfdff;
    uVar5 = uVar5 | 0x10;
    iRam2090bff0 = iRam2090bff0 + 1;
  }
  if ((wVar2 & 0x100) == 0 || (wVar4 & 0x100) == 0) {
    if (((!bVar12 || !bVar13) && ((!bVar10 || !bVar11) && (!bVar9 && !bVar8))) && (wVar2 != 0)) {
      iRam2090bff8 = iRam2090bff8 + 1;
    }
  }
  else {
    wVar4 = wVar4 & 0xfeff;
    iVar7 = 1;
    iRam2090bff4 = iRam2090bff4 + 1;
    uRam2090bfdc = 0;
  }
  USB_INTENB0_1 = wVar4;
  if ((wVar3 & 0x800) != 0 && (wVar1 & 0x800) != 0) {
    uVar5 = uVar5 | 2;
    iRam2090bffc = iRam2090bffc + 1;
  }
  if (((wVar3 & 0x1000) != 0) && (iRam2090c000 = iRam2090c000 + 1, (wVar1 & 0x1000) != 0)) {
    uVar5 = uVar5 | 1;
    usbh_pipe_mark_done(1,0);
    FUN_20139658(1,0);
  }
  if ((wVar3 & 0x20) != 0) {
    uVar6 = 2;
    iRam2090c004 = iRam2090c004 + 1;
  }
  if ((wVar3 & 0x10) != 0) {
    uVar6 = uVar6 | 1;
    iRam2090c008 = iRam2090c008 + 1;
  }
  if (uVar5 != 0) {
    itron_set_flg(uRam2090bb4c,uVar5);
  }
  if (iVar7 != 0) {
    itron_set_flg(uRam2090bb58,iVar7);
  }
  if (uVar6 != 0) {
    itron_set_flg(uRam2090bb54,uVar6);
    return;
  }
  return;
}


// ===== usbh_create_objects @ 2013b5bc (696 bytes)

/* m596* / udevtsk%d names */

uint usbh_create_objects(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_1 * 0x10 + 0x2091c368;
  sprintf(iVar1,"m596i%d",param_1);
  iVar1 = os_create_flg_named(&DAT_204201d0,iVar1);
  if (-1 < iVar1) {
    *(int *)(param_2 + 0x14) = iVar1;
    iVar1 = param_1 * 0x10 + 0x2091c388;
    sprintf(iVar1,"m596r%d",param_1);
    iVar1 = os_create_flg_named(&DAT_204201d0,iVar1);
    if (-1 < iVar1) {
      *(int *)(param_2 + 0x20) = iVar1;
      iVar1 = param_1 * 0x10 + 0x2091c3a8;
      sprintf(iVar1,"m596su%d",param_1);
      iVar1 = os_create_flg_named(&DAT_204201d0,iVar1);
      if (-1 < iVar1) {
        *(int *)(param_2 + 0x1c) = iVar1;
        iVar1 = param_1 * 0x10 + 0x2091c508;
        sprintf(iVar1,"m596a%d",param_1);
        iVar1 = os_create_flg_named(&DAT_204201d0,iVar1);
        if (-1 < iVar1) {
          *(int *)(param_2 + 0x18) = iVar1;
          uVar2 = param_1 * 0x10 + 0x2091c528;
          sprintf(uVar2,"m596a%d",param_1);
          uVar2 = os_create_sem_named(&DAT_204201ec,uVar2);
          if (-1 < (int)uVar2) {
            *(uint *)(param_2 + 0x4a0) = uVar2;
            uVar2 = param_1 * 0x10 + 0x2091c548;
            sprintf(uVar2,"m596c%d",param_1);
            uVar2 = os_create_sem_named(&DAT_204201ec,uVar2);
            if (-1 < (int)uVar2) {
              *(uint *)(param_2 + 0x4a8) = uVar2;
              iVar1 = 0;
              do {
                uVar2 = param_1 * 0x30 + 0x2091c308 + iVar1 * 0x10;
                sprintf(uVar2,"m596fi%d%d",param_1,iVar1);
                uVar2 = os_create_sem_named(&DAT_204201ec,uVar2);
                if ((int)uVar2 < 0) {
                  return 0xffffffff;
                }
                iVar3 = iVar1 * 4;
                iVar1 = iVar1 + 1;
                *(uint *)(param_2 + iVar3 + 0x30) = uVar2;
              } while (iVar1 < 3);
              iVar1 = 0;
              do {
                iVar4 = param_2 + iVar1 * 0x70;
                iVar3 = param_1 * 0xa0 + 0x2091c3c8 + iVar1 * 0x10;
                *(int *)(iVar4 + 0x4c) = iVar1;
                *(int *)(iVar4 + 0x44) = param_2;
                sprintf(iVar3,"m596d%dt%d",param_1,iVar1);
                iVar3 = os_create_flg_named(&DAT_204201d0,iVar3);
                if (iVar3 < 0) {
                  return 0xffffffff;
                }
                iVar1 = iVar1 + 1;
                *(int *)(iVar4 + 100) = iVar3;
              } while (iVar1 < 10);
              iVar1 = param_1 * 0x10 + 0x2091c288;
              sprintf(iVar1,"m596m%d",param_1);
              DAT_20808ad8 = param_1;
              iVar1 = os_create_tsk_named(&DAT_20808ad4,iVar1);
              if (-1 < iVar1) {
                *(int *)(param_2 + 0x24) = iVar1;
                iVar1 = param_1 * 0x10 + 0x2091c2a8;
                sprintf(iVar1,"m596r%d",param_1);
                DAT_20808af4 = param_1;
                iVar1 = os_create_tsk_named(&DAT_20808af0,iVar1);
                if (-1 < iVar1) {
                  *(int *)(param_2 + 0x28) = iVar1;
                  iVar1 = param_1 * 0x10 + 0x2091c2e8;
                  sprintf(iVar1,"udevtsk%d",param_1);
                  iVar1 = os_create_dtq_named(&DAT_204201dc,iVar1);
                  if (-1 < iVar1) {
                    *(int *)(&DAT_2091c214 + param_1 * 8) = iVar1;
                    iVar1 = param_1 * 0x10 + 0x2091c2c8;
                    sprintf(iVar1,"udev%d",param_1);
                    DAT_20808b10 = param_1;
                    iVar1 = os_create_tsk_named(&DAT_20808b0c,iVar1);
                    if (-1 < iVar1) {
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== usbh_hid_init @ 2013b928 (72 bytes)

/* UHHID */

uint usbh_hid_init(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    DAT_20808b2c = iVar2;
    iVar1 = os_create_tsk_named(&DAT_20808b28,"UHHID");
    if (iVar1 < 1) {
      return 0xffffffff;
    }
    iVar2 = iVar2 + 1;
    *param_1 = iVar1;
    param_1 = param_1 + 0xc2;
  } while (iVar2 < 2);
  return 0;
}


// ===== usbh_hid_class_init @ 2013b97c (56 bytes)

/* Clears the 0x610-byte HID work area 0x2091C568, usbh_hid_init and usbhid_class_register; -1 on
   error (boot-rtos.md init list) [fact] */

undefined4 usbh_hid_class_init(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  __aeabi_memclr4(&DAT_2091c568,0x610);
  uVar1 = usbh_hid_init((int *)&DAT_2091c568);
  if (((int)uVar1 < 0) || (iVar2 = usbhid_class_register(), iVar2 < 0)) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// ===== usbhid_device_stop @ 2013ba44 (104 bytes)

/* (slot): stops a running HID device: clears its run flag, cancels the pipe (usbh_pipe_cancel) and
   waits up to 1 s for the task to end [fact] */

undefined4 usbhid_device_stop(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  param_1 = param_1 * 0x308;
  if (*(int *)(&DAT_2091c584 + param_1) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(&DAT_2091c57c + param_1) = 0;
    usbh_pipe_cancel(*(undefined4 *)(&DAT_2091c56c + param_1),
                     *(undefined4 *)(&DAT_2091c574 + param_1));
    iVar2 = 0;
    do {
      if (*(int *)(&DAT_2091c580 + param_1) == 0) break;
      itron_dly_tsk(5);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 200);
    uVar1 = 0;
    *(undefined4 *)(&DAT_2091c584 + param_1) = 0;
  }
  return uVar1;
}


// ===== usbkbd_set_leds @ 2013baac (264 bytes)

/* Builds the HID output report from the NumLock/CapsLock/ScrollLock state (report fields 1/2/3) and
   sends it with usbh_class_request (SET_REPORT 0x21, 9, wValue 0x0200, 1 byte); input.md: sends the
   LED report [fact] */

undefined4 usbkbd_set_leds(int param_1,int param_2,byte *param_3)

{
  uint uVar1;
  int iVar2;
  byte local_14 [4];
  
  param_1 = param_1 * 0x308;
  if (((*(int *)(&DAT_2091c57c + param_1) != 0) && (param_2 == 0)) &&
     (*(int *)(&DAT_2091c588 + param_1) == 6)) {
    uVar1 = 0;
    local_14[0] = 0;
    if (0 < *(int *)(&DAT_2091c660 + param_1)) {
      do {
        iVar2 = uVar1 + param_1;
        if ((&DAT_2091c568)[iVar2 + 0xfc] == '\x01') {
          if ((*param_3 & 1) != 0) {
            local_14[0] = local_14[0] | (byte)(1 << (uVar1 & 0xff));
            goto LAB_2013bb24;
          }
        }
        else {
LAB_2013bb24:
          if ((&DAT_2091c568)[iVar2 + 0xfc] == '\x02') {
            if ((*param_3 & 2) == 0) goto LAB_2013bb6c;
            local_14[0] = local_14[0] | (byte)(1 << (uVar1 & 0xff));
          }
          if (((&DAT_2091c568)[iVar2 + 0xfc] == '\x03') && ((*param_3 & 4) != 0)) {
            local_14[0] = local_14[0] | (byte)(1 << (uVar1 & 0xff));
          }
        }
LAB_2013bb6c:
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < *(int *)(&DAT_2091c660 + param_1));
    }
    iVar2 = usbh_class_request(*(undefined4 *)(&DAT_2091c56c + param_1),0x21,9,0x200,
                               (&DAT_2091c570)[param_1],local_14,1);
    if (iVar2 == 1) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== hid_report_bits_get @ 2013bbb4 (124 bytes)

/* (report, bit offset, bit count): little-endian bit-field extract from a HID report [fact] */

uint hid_report_bits_get(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = param_2 & 7;
  uVar5 = 0;
  uVar3 = param_3;
  uVar4 = param_2;
  if (uVar2 != 0) {
    uVar4 = param_2 + 7 & 0xfffffff8;
    uVar3 = param_3 - (uVar4 - param_2);
  }
  uVar1 = 0;
  if (0 < (int)uVar3) {
    do {
      uVar5 = uVar5 | (uint)*(byte *)(param_1 + ((int)(uVar4 + uVar1) >> 3)) << (uVar1 & 0xff);
      uVar1 = uVar1 + 8;
    } while ((int)uVar1 < (int)uVar3);
  }
  if (uVar2 != 0) {
    uVar5 = uVar5 << (8 - uVar2 & 0xff) | (uint)(*(byte *)(param_1 + ((int)param_2 >> 3)) >> uVar2);
  }
  return (1 << (param_3 & 0xff)) - 1U & uVar5;
}


// ===== hid_item_data @ 2013bc30 (240 bytes)

/* (*pos, *out, signed): reads the data of one short HID item (size code 0/1/2/4 bytes from the low
   two bits of the prefix), sign-extends when asked, advances the pointer [fact] */

void hid_item_data(int *param_1,uint *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  ushort *puVar4;
  byte bVar5;
  
  pbVar3 = (byte *)*param_1;
  puVar4 = (ushort *)(pbVar3 + 1);
  bVar5 = *pbVar3 & 3;
  if ((*pbVar3 & 3) == 0) {
    *param_2 = 0;
    iVar2 = *param_1 + 1;
  }
  else if (bVar5 == 1) {
    uVar1 = *puVar4;
    *param_2 = (uint)(byte)uVar1;
    if ((param_3 != 0) && ((*puVar4 & 0x80) != 0)) {
      *param_2 = (byte)uVar1 | 0xffffff00;
    }
    iVar2 = *param_1 + 2;
  }
  else if (bVar5 == 2) {
    uVar1 = *puVar4;
    *param_2 = (uint)uVar1;
    if ((param_3 != 0) && ((pbVar3[2] & 0x80) != 0)) {
      *param_2 = uVar1 | 0xffff0000;
    }
    iVar2 = *param_1 + 3;
  }
  else {
    if (bVar5 != 3) {
      return;
    }
    uVar1 = *puVar4;
    *param_2 = (uint)uVar1;
    if ((param_3 != 0) && ((pbVar3[2] & 0x80) != 0)) {
      *param_2 = uVar1 | 0xffff0000;
    }
    iVar2 = *param_1 + 5;
  }
  *param_1 = iVar2;
  return;
}


// ===== hid_report_desc_parse @ 2013bd20 (1540 bytes)

/* (dev, desc): walks a HID report descriptor item by item (hid_item_data) and records the report
   id, usage and the bit offsets and sizes of the fields the driver uses (buttons, X/Y, wheel, keys)
   [fact for the item walk; inference for the field roles from usbhid_device_task] */

undefined4 hid_report_desc_parse(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  int local_44;
  byte *local_40;
  uint local_3c;
  uint local_38;
  int iStack_30;
  byte *local_2c;
  int local_28;
  
  iVar7 = 0;
  local_38 = 0;
  iVar4 = param_1 + 0x205;
  local_44 = 0;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xdc) = 0xffffffff;
  do {
    iVar6 = iVar2 * 0x10;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(param_1 + iVar6 + 0x24) = 0xffffffff;
  } while (iVar2 < 10);
  *(undefined4 *)(param_1 + 0xf4) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x104) = 0;
  iVar2 = 0;
  local_54 = 0;
  iVar6 = 0;
  uVar5 = 0;
  local_50 = 0;
  iVar8 = 0;
  local_48 = 0;
  local_60 = -1;
  local_58 = 0;
  local_5c = -1;
  local_4c = 0;
  local_40 = param_2;
  iStack_30 = param_1;
  local_2c = param_2;
  local_28 = param_3;
  if (0 < param_3) {
    do {
      bVar1 = *local_40 & 0xfc;
      if (bVar1 == 0x80) {
        hid_item_data(&local_40,&local_3c,0);
        if ((*(int *)(param_1 + 0x20) < 0) || (local_44 != iVar6)) goto LAB_2013c034;
        if (local_48 == 1) {
          if (local_3c == 2 || local_3c == 6) {
            if (local_54 != iVar2) {
              return 0xffffffff;
            }
            iVar2 = 0;
            if (0 < local_54) {
              do {
                if ((*(byte *)(iVar4 + iVar2) - 0x30 < 10) &&
                   (iVar3 = param_1 + (*(byte *)(iVar4 + iVar2) - 0x30) * 0x10,
                   *(int *)(iVar3 + 0x24) < 0)) {
                  *(uint *)(iVar3 + 0x24) = local_58 * iVar2 + uVar5;
                  *(int *)(iVar3 + 0x28) = local_58;
                  *(undefined4 *)(iVar3 + 0x2c) = local_4c;
                  *(undefined4 *)(iVar3 + 0x30) = local_50;
                }
                iVar2 = iVar2 + 1;
              } while (iVar2 < local_54);
            }
          }
        }
        else {
          if (local_48 == 7) {
            if (local_3c == 2) {
              if (((local_54 != iVar2) || (8 < local_54)) || (local_58 != 1)) {
                return 0xffffffff;
              }
              if (*(int *)(param_1 + 0xc4) < 0) {
                *(int *)(param_1 + 200) = local_54;
                iVar3 = param_1 + 0xcc;
                *(uint *)(param_1 + 0xc4) = uVar5;
                iVar2 = local_54;
                goto LAB_2013c1cc;
              }
            }
            else {
              if (local_3c != 0) goto LAB_2013c1d4;
              bVar9 = local_54 == 8;
              if (local_54 < 9) {
                bVar9 = (uVar5 & 7) == 0;
              }
              if (!bVar9) {
                return 0xffffffff;
              }
              if (local_58 != 8) {
                return 0xffffffff;
              }
              if (*(int *)(param_1 + 0xd4) < 0) {
                *(int *)(param_1 + 0xd8) = local_54;
                *(int *)(param_1 + 0xd4) = (int)(uVar5 + ((uint)((int)uVar5 >> 0x1f) >> 0x1d)) >> 3;
              }
            }
          }
          else {
            if ((local_48 != 9) || (local_3c != 2)) goto LAB_2013c1d4;
            if (local_54 < iVar2) {
              iVar2 = local_54;
            }
            if (0x10 < local_54) {
              return 0xffffffff;
            }
            if (local_58 != 1) {
              return 0xffffffff;
            }
            if (*(int *)(param_1 + 0xdc) < 0) {
              *(int *)(param_1 + 0xe0) = iVar2;
              iVar3 = param_1 + 0xe4;
              *(uint *)(param_1 + 0xdc) = uVar5;
LAB_2013c1cc:
              memcpy(iVar3,iVar4,iVar2);
            }
          }
          *(char *)(param_1 + 0x104) = (char)iVar6;
        }
LAB_2013c1d4:
        uVar5 = local_58 * local_54 + uVar5;
LAB_2013c034:
        iVar2 = 0;
        local_60 = -1;
        local_5c = -1;
      }
      else if (bVar1 < 0x80) {
        if (bVar1 == 0x18) {
          hid_item_data(&local_40,&local_60,0);
          if ((-1 < local_60) && (iVar3 = local_60, -1 < local_5c)) {
            for (; iVar3 <= local_5c; iVar3 = iVar3 + 1) {
              if (iVar2 < 0x100) {
                if (iVar3 < 0x100) {
                  *(char *)(iVar4 + iVar2) = (char)iVar3;
                }
                else {
                  *(undefined1 *)(iVar4 + iVar2) = 0;
                }
                iVar2 = iVar2 + 1;
              }
            }
          }
        }
        else if (bVar1 < 0x18) {
          if (bVar1 == 4) {
            hid_item_data(&local_40,&local_48,0);
          }
          else if (bVar1 == 8) {
            hid_item_data(&local_40,&local_3c,0);
            local_38 = local_3c;
            if (iVar7 == 0) {
              if (((local_48 & 0xff00) == 0) && (*(int *)(param_1 + 0x20) < 0)) {
                *(uint *)(param_1 + 0x20) = local_3c;
              }
            }
            else if (iVar2 < 0x100) {
              if (local_3c < 0x100) {
                *(char *)(iVar4 + iVar2) = (char)local_3c;
                iVar2 = iVar2 + 1;
              }
              else {
                *(undefined1 *)(iVar4 + iVar2) = 0;
                iVar2 = iVar2 + 1;
              }
            }
          }
          else {
            if (bVar1 != 0x14) goto LAB_2013be4c;
            hid_item_data(&local_40,&local_50,1);
          }
        }
        else if (bVar1 == 0x24) {
          hid_item_data(&local_40,&local_4c,1);
        }
        else if (bVar1 == 0x28) {
          hid_item_data(&local_40,&local_5c,0);
          if ((-1 < local_60) && (iVar3 = local_60, -1 < local_5c)) {
            for (; iVar3 <= local_5c; iVar3 = iVar3 + 1) {
              if (iVar2 < 0x100) {
                if (iVar3 < 0x100) {
                  *(char *)(iVar4 + iVar2) = (char)iVar3;
                }
                else {
                  *(undefined1 *)(iVar4 + iVar2) = 0;
                }
                iVar2 = iVar2 + 1;
              }
            }
          }
        }
        else {
          if (bVar1 != 0x74) goto LAB_2013be4c;
          hid_item_data(&local_40,&local_58,0);
        }
      }
      else if (bVar1 == 0xa0) {
        hid_item_data(&local_40,&local_3c,0);
        if ((iVar7 == 0) && (local_38 == 6)) {
          local_48 = 7;
        }
        iVar2 = 0;
        iVar7 = iVar7 + 1;
        local_60 = -1;
        local_5c = -1;
      }
      else if (bVar1 < 0xa1) {
        if (bVar1 == 0x84) {
          hid_item_data(&local_40,&local_44,0);
          iVar3 = *(int *)(param_1 + 0x20);
          if (-1 < *(int *)(param_1 + 0x20)) {
            iVar3 = iVar6;
          }
          if (iVar3 == 0) {
            uVar5 = 8;
            iVar8 = 0;
            iVar6 = local_44;
          }
        }
        else {
          if (bVar1 == 0x90) {
            hid_item_data(&local_40,&local_3c,0);
            if ((-1 < *(int *)(param_1 + 0x20)) && (local_44 == iVar6)) {
              if ((local_48 == 8) && (local_3c == 2)) {
                if (local_54 < iVar2) {
                  iVar2 = local_54;
                }
                if (8 < local_54) {
                  return 0xffffffff;
                }
                if (local_58 != 1) {
                  return 0xffffffff;
                }
                if (*(int *)(param_1 + 0xf4) < 0) {
                  *(int *)(param_1 + 0xf8) = iVar2;
                  *(int *)(param_1 + 0xf4) = iVar8;
                  memcpy(param_1 + 0xfc,iVar4,iVar2);
                }
              }
              iVar8 = local_58 * local_54 + iVar8;
            }
            goto LAB_2013c034;
          }
          if (bVar1 != 0x94) goto LAB_2013be4c;
          hid_item_data(&local_40,&local_54,0);
        }
      }
      else {
        if (bVar1 == 0xb0) {
          hid_item_data(&local_40,&local_3c,0);
          goto LAB_2013c034;
        }
        if (bVar1 == 0xc0) {
          hid_item_data(&local_40,&local_3c,0);
          iVar2 = 0;
          iVar7 = iVar7 + -1;
          local_60 = -1;
          local_5c = -1;
        }
        else {
LAB_2013be4c:
          hid_item_data(&local_40,&local_3c,0);
        }
      }
    } while ((int)local_40 - (int)local_2c < local_28);
  }
  return 0;
}


// ===== usbhid_device_task @ 2013c32c (912 bytes)

/* Per-device HID task: GET_DESCRIPTOR configuration (0x80/6/0x200), SET_PROTOCOL (0x21/0x0B),
   GET_DESCRIPTOR report (0x81/6/0x2200), hid_report_desc_parse, SET_IDLE (0x21/0x0A),
   usbhid_attach_event, then reads interrupt reports and passes the extracted fields to
   usbhid_report_event; detach event and itron_ext_tsk at the end [fact] */

void usbhid_device_task(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;
  ushort uVar7;
  uint uVar8;
  byte *pbVar9;
  bool bVar10;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  param_1 = param_1 * 0x308;
  puVar6 = &DAT_2091c568 + param_1;
  pbVar9 = &DAT_2091c66d + param_1;
  *(undefined4 *)(&DAT_2091c580 + param_1) = 1;
  iVar3 = usbh_class_request(*(undefined4 *)(&DAT_2091c56c + param_1),0x80,6,0x200,0,pbVar9,9);
  if (((iVar3 == 9) && (uVar8 = (uint)*(ushort *)(&DAT_2091c66f + param_1), uVar8 < 0x100)) &&
     (uVar4 = usbh_class_request(*(undefined4 *)(&DAT_2091c56c + param_1),0x80,6,0x200,0,pbVar9,
                                 uVar8), uVar4 == uVar8)) {
    uVar7 = 0;
    pbVar9[uVar4] = 0;
    bVar10 = false;
    for (pbVar5 = pbVar9;
        ((0 < (int)uVar4 && (uVar8 = (uint)*pbVar5, uVar8 != 0)) && ((int)uVar8 <= (int)uVar4));
        pbVar5 = pbVar5 + uVar8) {
      if (pbVar5[1] == 4) {
        bVar10 = (uint)pbVar5[2] == *(uint *)(&DAT_2091c570 + param_1);
      }
      else if (((pbVar5[1] == 0x21) && (bVar10)) && (pbVar5[6] == 0x22)) {
        uVar7 = *(ushort *)(pbVar5 + 7);
      }
      uVar4 = uVar4 - uVar8;
    }
    if ((uVar7 != 0) && (uVar7 < 0x100)) {
      usbh_class_request(*(undefined4 *)(&DAT_2091c56c + param_1),0x21,0xb,1,
                         (&DAT_2091c570)[param_1],0,0);
      iVar3 = usbh_class_request(*(undefined4 *)(&DAT_2091c56c + param_1),0x81,6,0x2200,
                                 (&DAT_2091c570)[param_1],pbVar9,uVar7);
      if (((-1 < iVar3) && (iVar3 = hid_report_desc_parse(puVar6,pbVar9), -1 < iVar3)) &&
         ((iVar3 = *(int *)(&DAT_2091c588 + param_1), iVar3 == 2 || iVar3 == 4 ||
          (iVar3 == 5 || iVar3 == 6)))) {
        usbh_class_request(*(undefined4 *)(&DAT_2091c56c + param_1),0x21,10,0,
                           (&DAT_2091c570)[param_1],0,0);
        usbhid_attach_event(*(int *)(&DAT_2091c56c + param_1),*(int *)(&DAT_2091c588 + param_1));
        while ((*(int *)(&DAT_2091c57c + param_1) != 0 &&
               (iVar3 = usbhid_pipe_read(*(undefined4 *)(&DAT_2091c56c + param_1),
                                         *(undefined4 *)(&DAT_2091c574 + param_1),pbVar9,
                                         *(undefined4 *)(&DAT_2091c578 + param_1)), -1 < iVar3))) {
          if (((&DAT_2091c66c)[param_1] == 0) || ((&DAT_2091c66c)[param_1] == *pbVar9)) {
            local_44 = 0;
            local_40 = 0;
            local_3c = 0;
            local_38 = 0;
            local_34 = 0;
            local_30 = 0;
            local_2c = 0;
            local_48 = *(int *)(&DAT_2091c588 + param_1);
            if ((local_48 == 2 || local_48 == 4) || local_48 == 5) {
              if (-1 < *(int *)(&DAT_2091c644 + param_1)) {
                local_44 = (uint)(byte)(&DAT_2091c64c)[param_1];
                uVar2 = hid_report_bits_get(pbVar9,*(undefined4 *)(&DAT_2091c644 + param_1),
                                            *(undefined4 *)(&DAT_2091c648 + param_1));
                local_44 = CONCAT22(uVar2,(undefined2)local_44);
              }
              uVar8 = 0;
              do {
                if (-1 < *(int *)(puVar6 + uVar8 * 0x10 + 0x24)) {
                  local_40 = CONCAT22(local_40._2_2_,
                                      (ushort)local_40 | (ushort)(1 << (uVar8 & 0xff)));
                  uVar4 = hid_report_bits_get(pbVar9,*(undefined4 *)(puVar6 + uVar8 * 0x10 + 0x24),
                                              *(undefined4 *)(puVar6 + uVar8 * 0x10 + 0x28));
                  if ((*(int *)(puVar6 + uVar8 * 0x10 + 0x30) < 0) &&
                     ((uVar4 & 1 << (*(uint *)(puVar6 + uVar8 * 0x10 + 0x28) - 1 & 0xff)) != 0)) {
                    *(ushort *)((int)&local_40 + uVar8 * 2 + 2) =
                         (ushort)uVar4 |
                         ~((short)(1 << (*(uint *)(puVar6 + uVar8 * 0x10 + 0x28) & 0xff)) - 1U);
                  }
                  else {
                    *(ushort *)((int)&local_40 + uVar8 * 2 + 2) = (ushort)uVar4;
                  }
                }
                uVar8 = uVar8 + 1;
              } while ((int)uVar8 < 10);
            }
            else if (local_48 == 6) {
              if (-1 < *(int *)(&DAT_2091c62c + param_1)) {
                local_44 = (uint)(byte)(&DAT_2091c634)[param_1];
                uVar1 = hid_report_bits_get(pbVar9,*(undefined4 *)(&DAT_2091c62c + param_1),
                                            *(undefined4 *)(&DAT_2091c630 + param_1));
                local_44._0_2_ = CONCAT11(uVar1,(undefined1)local_44);
              }
              if (-1 < *(int *)(&DAT_2091c63c + param_1)) {
                local_40 = *(undefined4 *)(&DAT_2091c640 + param_1);
                memcpy(&local_3c,pbVar9 + *(int *)(&DAT_2091c63c + param_1),
                       *(undefined4 *)(&DAT_2091c640 + param_1));
              }
            }
            usbhid_report_event(*(uint *)(&DAT_2091c56c + param_1),&local_48);
          }
        }
        usbhid_attach_event(*(int *)(&DAT_2091c56c + param_1),-1);
      }
    }
  }
  *(undefined4 *)(&DAT_2091c580 + param_1) = 0;
  *(undefined4 *)(&DAT_2091c588 + param_1) = 0xffffffff;
  itron_ext_tsk();
  return;
}


// ===== usbhid_class_register @ 2013c6bc (84 bytes)

/* Clears the two HID device slots 0x2091CB78.. and registers the class table 0x204201FC with the
   host stack (thunk_FUN_201384d4) [fact] */

undefined4 usbhid_class_register(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_2091cb78 = 0;
  DAT_2091cb7c = 0;
  DAT_2091cb80 = 0;
  DAT_2091cb84 = 0;
  DAT_2091cb88 = 0;
  DAT_2091cb8c = 0;
  DAT_2091cb90 = 0;
  DAT_2091cb94 = 0;
  DAT_2091cb98 = 0;
  DAT_2091cb9c = 0;
  DAT_2091cba0 = 0;
  DAT_2091cba4 = 0;
  iVar1 = thunk_FUN_201384d4(&DAT_204201fc);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== usbh_class_request @ 2013c710 (92 bytes)

/* (device, bmRequestType, bRequest, wValue, wIndex, data, length) on device table 0x2091CB78 [fact]
    */

void usbh_class_request(int param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
                       undefined2 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  iVar1 = (&DAT_2091cb78)[param_1 * 6];
  if (iVar1 != 0) {
    local_14 = param_5;
    local_12 = (undefined2)param_7;
    local_18 = param_2;
    local_17 = param_3;
    local_16 = param_4;
    usbh_control_req(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x8d8),&local_18,param_6,
                     param_7);
  }
  return;
}


// ===== usbhid_pipe_read @ 2013c76c (44 bytes)

/* (dev, pipe slot): starts a read on the device's interrupt pipe (usbh_pipe_xfer) [fact] */

void usbhid_pipe_read(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (&DAT_2091cb78)[param_1 * 6];
  if (iVar1 != 0) {
    usbh_pipe_xfer(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + param_2 * 4 + 0x8d8));
    return;
  }
  return;
}


// ===== usbh_pipe_cancel @ 2013c798 (316 bytes)

/* (port, pipe): with the CPU locked, waits for the pipe to go idle (about 50 ticks), clears it in
   the controller and signals the port flag and semaphore [fact for the calls] */

undefined4 usbh_pipe_cancel(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  if ((&DAT_2091cb78)[param_1 * 6] == 0) {
    return 0xffffffff;
  }
  iVar3 = *(int *)((&DAT_2091cb78)[param_1 * 6] + param_2 * 4 + 0x8d8);
  if (iVar3 != 0) {
    iVar5 = *(int *)(iVar3 + 4);
    uVar9 = *(undefined4 *)(iVar3 + 0x24);
    if (*(int *)(iVar3 + 0xc) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = *(int *)(iVar5 + 0x3c);
    }
    iVar6 = (&DAT_20420144)[*(int *)(iVar3 + 0xc)];
    iVar7 = *(int *)(&DAT_2042016c + iVar4 * 4);
    uVar8 = *(undefined4 *)(iVar5 + iVar4 * 4 + 0x30);
    uVar2 = usbh_loc_cpu();
    *(ushort *)(*(int *)(iVar5 + 8) + iVar6) = *(ushort *)(*(int *)(iVar5 + 8) + iVar6) & 0xfffc;
    itron_unl_cpu(uVar2);
    iVar3 = fs_get_tick();
    while ((iVar4 = fs_get_tick(), (uint)(iVar4 - iVar3) < 0x33 &&
           ((*(ushort *)(*(int *)(iVar5 + 8) + iVar6) & 0x1020) != 0))) {
      itron_dly_tsk(2);
    }
    itron_twai_sem(uVar8,0xffffffff);
    *(ushort *)(*(int *)(iVar5 + 8) + iVar7) = *(ushort *)(*(int *)(iVar5 + 8) + iVar7) & 0x100;
    reg_wait_bits27(iVar5,iVar7,0);
    uVar2 = usbh_loc_cpu();
    uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + iVar6);
    *(ushort *)(*(int *)(iVar5 + 8) + iVar6) = uVar1 | 0x200;
    cpu_delay_cycles4();
    *(ushort *)(*(int *)(iVar5 + 8) + iVar6) = uVar1 & 0xfdff;
    itron_unl_cpu(uVar2);
    itron_set_flg(uVar9,8);
    itron_sig_sem(uVar8);
    return 0;
  }
  return 0xffffffff;
}


// ===== usbhid_find_int_in @ 2013c7c4 (156 bytes)

/* (slot, config): first interrupt (type 3) IN endpoint with max packet 1..256; -1 if none [fact] */

undefined4 usbhid_find_int_in(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  *param_1 = *(undefined4 *)(param_2 + 0x850);
  iVar1 = 1;
  if (1 < *(int *)(param_2 + 0x1c)) {
    do {
      iVar2 = param_2 + iVar1 * 0xc;
      if (((*(char *)(iVar2 + 0x861) == '\x03') && ((*(byte *)(iVar2 + 0x860) & 0x80) != 0)) &&
         ((int)param_1[1] < 0)) {
        param_1[1] = iVar1;
        param_1[2] = *(undefined4 *)(iVar2 + 0x864);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_2 + 0x1c));
    if (((-1 < (int)param_1[1]) && (0 < (int)param_1[2])) && ((int)param_1[2] < 0x101)) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== usbhid_class_attach @ 2013c860 (336 bytes)

/* Class attach/detach callback (port, address, config): detach stops the device
   (usbhid_device_stop); attach finds the interrupt-IN endpoint (usbhid_find_int_in), fills a free
   slot (max 2) and starts usbhid_device_task, waiting up to 1 s for it [fact] */

int usbhid_class_attach(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 == 0) {
    iVar4 = 0;
    while( true ) {
      if ((((&DAT_2091cb7c)[iVar4 * 6] == param_1) && ((&DAT_2091cb80)[iVar4 * 6] == param_2)) &&
         ((&DAT_2091cb78)[iVar4 * 6] != 0)) break;
      iVar4 = iVar4 + 1;
      if (1 < iVar4) {
        return iVar4;
      }
    }
    usbhid_device_stop();
    (&DAT_2091cb78)[iVar4 * 6] = 0;
    return 0;
  }
  iVar4 = 0;
  while( true ) {
    iVar1 = (&DAT_2091cb78)[iVar4 * 6];
    if (iVar1 == 0) break;
    iVar4 = iVar4 + 1;
    if (1 < iVar4) {
      return iVar1;
    }
  }
  iVar1 = usbhid_find_int_in(&DAT_2091cb84 + iVar4 * 6,param_3);
  if (iVar1 < 0) {
    return iVar1;
  }
  (&DAT_2091cb80)[iVar4 * 6] = param_2;
  (&DAT_2091cb7c)[iVar4 * 6] = param_1;
  (&DAT_2091cb78)[iVar4 * 6] = param_3;
  if (0x100 < (int)(&DAT_2091cb8c)[iVar4 * 6]) {
    return -1;
  }
  iVar1 = iVar4 * 0x308;
  if (*(int *)(&DAT_2091c584 + iVar1) != 0) {
    return -1;
  }
  *(int *)(&DAT_2091c56c + iVar1) = iVar4;
  uVar3 = (&DAT_2091cb88)[iVar4 * 6];
  uVar2 = (&DAT_2091cb8c)[iVar4 * 6];
  *(undefined4 *)(&DAT_2091c570 + iVar1) = (&DAT_2091cb84)[iVar4 * 6];
  *(undefined4 *)(&DAT_2091c574 + iVar1) = uVar3;
  *(undefined4 *)(&DAT_2091c578 + iVar1) = uVar2;
  *(undefined4 *)(&DAT_2091c57c + iVar1) = 1;
  itron_act_tsk(*(undefined4 *)(&DAT_2091c568 + iVar1));
  iVar4 = 0;
  do {
    if (*(int *)(&DAT_2091c580 + iVar1) != 0) break;
    itron_dly_tsk(5);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 200);
  *(undefined4 *)(&DAT_2091c584 + iVar1) = 1;
  return 0;
}


// ===== FUN_2013c928 @ 2013c928 (56 bytes)

undefined4 FUN_2013c928(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 1) {
    (*(code *)((undefined4 *)param_2[1])[1])();
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x2013c95c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)param_2[1])((int)*(short *)(*param_2 + 0x2c4));
  return uVar1;
}


// ===== sd_cmd0_go_idle @ 2013c960 (112 bytes)

/* CMD0 (GO_IDLE_STATE), 3 tries; clears the RCA +0x2AC first [fact] */

undefined4 sd_cmd0_go_idle(int *param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined2 *)(*param_1 + 0x2ac) = 0;
  (**(code **)(param_1[1] + 0x2c))();
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(0,0,0,*param_1);
    if (iVar1 == 0) {
      if (2 < iVar2) {
        return 0xfffffff7;
      }
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0xfffffff7;
}


// ===== sd_init_v1_or_mmc @ 2013c9d0 (488 bytes)

/* Initialisation without a CMD8 answer: ACMD41 (CMD55 + 41) polling until the busy bit 31 of the
   OCR is set, or CMD1 (MMC, arg 0xFF8000) when CMD55 fails; MMC sets the card type +0x2C6 = 1
   [fact] */

undefined4 sd_init_v1_or_mmc(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
    if (iVar1 != 0) {
      uVar3 = 0;
      while( true ) {
        iVar2 = (**(code **)(param_1[1] + 0x48))(1,0,0xff8000,*param_1);
        if (iVar2 != 0) {
          return 0xfffffff7;
        }
        (**(code **)(param_1[1] + 0x4c))(3,*param_1);
        if ((*(uint *)(*param_1 + 0x2b0) & 0x80000000) != 0) break;
        uVar3 = uVar3 + 1;
        sd_delay_ms(1);
        if (999 < uVar3) {
          return 0xffffffff;
        }
      }
      *(undefined2 *)(*param_1 + 0x2c4) = 0xffff;
      *(undefined2 *)(*param_1 + 0x2c6) = 1;
      return 0;
    }
    (**(code **)(param_1[1] + 0x4c))(1,*param_1);
    iVar1 = (**(code **)(param_1[1] + 0x48))(0x29,1,0,*param_1);
    if (iVar1 == 0) {
      (**(code **)(param_1[1] + 0x4c))(3,*param_1);
      uVar3 = *(uint *)(*param_1 + 0x2b0) & 0xff8000;
      if (uVar3 != 0) {
        if (2 < iVar2) {
          return 0xffffffff;
        }
        uVar4 = 0;
        do {
          iVar2 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
          if (iVar2 == 0) {
            (**(code **)(param_1[1] + 0x4c))(1,*param_1);
            iVar2 = (**(code **)(param_1[1] + 0x48))(0x29,1,uVar3,*param_1);
            if ((iVar2 == 0) &&
               ((**(code **)(param_1[1] + 0x4c))(3,*param_1),
               (*(uint *)(*param_1 + 0x2b0) & 0x80000000) != 0)) {
              return 0;
            }
          }
          uVar4 = uVar4 + 1;
          sd_delay_ms(1);
          if (999 < uVar4) {
            return 0xffffffff;
          }
        } while( true );
      }
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 0xffffffff;
    }
  } while( true );
}


// ===== sd_init_v2 @ 2013cbb8 (560 bytes)

/* CMD8 (arg 0x1AA, echo check), then ACMD41 with HCS (0x41000000 | OCR voltage bits) until ready;
   returns 1 for a standard-capacity card (CCS clear) [fact] */

int sd_init_v2(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(param_1[1] + 0x48))(8,0,0x1aa,*param_1);
  if ((iVar1 == 0) &&
     ((**(code **)(param_1[1] + 0x4c))(7,*param_1), *(int *)(*param_1 + 0x2b0) == 0x1aa)) {
    iVar1 = (**(code **)(param_1[1] + 0x48))(5,0);
    if (iVar1 != 0) {
      iVar1 = 0;
      do {
        iVar2 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
        if (iVar2 == 0) {
          (**(code **)(param_1[1] + 0x4c))(1,*param_1);
          iVar2 = (**(code **)(param_1[1] + 0x48))(0x29,1,0,*param_1);
          if (iVar2 == 0) {
            (**(code **)(param_1[1] + 0x4c))(3,*param_1);
            uVar4 = *(uint *)(*param_1 + 0x2b0) & 0xff8000;
            if (uVar4 != 0) {
              if (2 < iVar1) {
                return -1;
              }
              uVar3 = 0;
              do {
                iVar1 = (**(code **)(param_1[1] + 8))();
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
                if (iVar1 == 0) {
                  (**(code **)(param_1[1] + 0x4c))(1,*param_1);
                  iVar1 = (**(code **)(param_1[1] + 0x48))(0x29,1,uVar4 | 0x41000000,*param_1);
                  if ((iVar1 == 0) &&
                     ((**(code **)(param_1[1] + 0x4c))(3,*param_1),
                     (*(uint *)(*param_1 + 0x2b0) & 0x80000000) != 0)) {
                    if ((*(uint *)(*param_1 + 0x2b0) & 0x40000000) == 0) {
                      return 1;
                    }
                    iVar1 = (**(code **)(param_1[1] + 0x1c))(0);
                    iVar2 = *param_1;
                    if (((*(uint *)(iVar2 + 0x2b0) & 0x1000000) != 0) && (iVar1 == 0)) {
                      *(ushort *)(iVar2 + 0x2c0) = *(ushort *)(iVar2 + 0x2c0) | 4;
                    }
                    return 0;
                  }
                }
                uVar3 = uVar3 + 1;
                sd_delay_ms(1);
                if (999 < uVar3) {
                  return -1;
                }
              } while( true );
            }
          }
        }
        iVar1 = iVar1 + 1;
        if (2 < iVar1) {
          return -1;
        }
      } while( true );
    }
    iVar1 = -5;
  }
  else {
    iVar1 = -9;
  }
  return iVar1;
}


// ===== FUN_2013cde8 @ 2013cde8 (256 bytes)

int FUN_2013cde8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while (iVar1 = (**(code **)(param_1[1] + 0x48))(0xb,0,0,*param_1), iVar1 != 0) {
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return -9;
    }
  }
  if (2 < iVar2) {
    return -9;
  }
  (**(code **)(param_1[1] + 0x4c))(1,*param_1);
  if ((*(uint *)(*param_1 + 0x2b0) & 0x2c80008) != 0) {
    return -0x17;
  }
  iVar2 = FUN_2013c928(0,param_1);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = (**(code **)(param_1[1] + 0x10))();
  if (iVar2 != 2) {
    return -9;
  }
  (**(code **)(param_1[1] + 0x38))();
  sd_delay_ms(10);
  iVar2 = (**(code **)(param_1[1] + 0x14))();
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = FUN_2013c928(1,param_1);
  if (iVar2 == 0) {
    sd_delay_ms(1);
    iVar2 = (**(code **)(param_1[1] + 0x10))();
    if (iVar2 != 3) {
      return -9;
    }
    return 0;
  }
  return iVar2;
}


// ===== sd_cmd2_all_send_cid @ 2013cee8 (152 bytes)

/* CMD2 (ALL_SEND_CID), 3 tries; copies the 16-byte CID to ctx +0x211 [fact] */

undefined4 sd_cmd2_all_send_cid(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(2,0,0,*param_1);
    if (iVar1 == 0) {
      if (2 < iVar3) {
        return 0xfffffff7;
      }
      (**(code **)(param_1[1] + 0x4c))(2,*param_1);
      uVar2 = 0;
      do {
        *(undefined1 *)(*param_1 + uVar2 + 0x211) = *(undefined1 *)(*param_1 + uVar2 + 0x2b0);
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 0x10);
      return 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return 0xfffffff7;
}


// ===== sd_cmd9_send_csd @ 2013d0bc (156 bytes)

/* CMD9 (SEND_CSD, RCA << 16), 3 tries; copies the 16-byte CSD to ctx +0x201 [fact] */

undefined4 sd_cmd9_send_csd(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(9,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      if (2 < iVar2) {
        return 0xfffffff7;
      }
      (**(code **)(param_1[1] + 0x4c))(2,*param_1);
      iVar2 = 0;
      do {
        iVar1 = iVar2 + 0x2b0;
        iVar3 = iVar2 + 0x201;
        iVar2 = iVar2 + 1;
        *(undefined1 *)(*param_1 + iVar3) = *(undefined1 *)(*param_1 + iVar1);
      } while (iVar2 < 0x10);
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0xfffffff7;
}


// ===== sd_csd_check @ 2013d158 (104 bytes)

/* (csd): range check of an SD CSD (structure < 2, TAAC, read/write-partial bits, READ_BL_LEN < 12,
   file format); -5 when invalid [fact for the fields] */

undefined4 sd_csd_check(byte *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 >> 6 < 2) && ((*param_1 & 0x3f) >> 2 < 3)) && ((param_1[1] & 0x80) == 0)) &&
     ((((param_1[3] & 0x80) == 0 && ((param_1[5] & 0xf) < 0xc)) && ((param_1[0xe] & 3) < 2)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}


// ===== mmc_csd_check @ 2013d1c8 (112 bytes)

/* (csd): the same check for an MMC CSD (structure < 4, SPEC_VERS < 5, also WRITE_BL_LEN); used when
   the card type +0x2C6 = 1 [fact] */

undefined4 mmc_csd_check(byte *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 >> 6 < 4) && ((*param_1 & 0x3f) >> 2 < 5)) && ((param_1[1] & 0x80) == 0)) &&
     ((((param_1[3] & 0x80) == 0 && ((param_1[5] & 0xf) < 0xc)) &&
      (((param_1[0xc] & 0x1f) >> 2 < 8 && ((param_1[0xe] & 3) < 2)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}


// ===== sd_cmd10_send_cid @ 2013d238 (156 bytes)

/* CMD10 (SEND_CID, RCA << 16), 3 tries; CID to ctx +0x211 [fact] */

undefined4 sd_cmd10_send_cid(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(10,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      if (2 < iVar2) {
        return 0xfffffff7;
      }
      (**(code **)(param_1[1] + 0x4c))(2,*param_1);
      iVar2 = 0;
      do {
        iVar1 = iVar2 + 0x2b0;
        iVar3 = iVar2 + 0x211;
        iVar2 = iVar2 + 1;
        *(undefined1 *)(*param_1 + iVar3) = *(undefined1 *)(*param_1 + iVar1);
      } while (iVar2 < 0x10);
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0xfffffff7;
}


// ===== sd_cmd13_send_status @ 2013d398 (156 bytes)

/* CMD13 (SEND_STATUS, RCA << 16), checks the R1 bits against the mask table 0x2042022C by card type
   [fact] */

undefined4 sd_cmd13_send_status(uint *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    iVar1 = (**(code **)(param_2[1] + 0x48))(0xd,0,(uint)*(ushort *)(*param_2 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      if (2 < iVar4) {
        return 0xfffffff7;
      }
      (**(code **)(param_2[1] + 0x4c))(1,*param_2);
      uVar3 = *(uint *)(*param_2 + 0x2b0);
      if ((uVar3 & *(uint *)(&DAT_2042022c + (uint)*(ushort *)(*param_2 + 0x2c6) * 4)) == 0) {
        uVar2 = 0;
        *param_1 = uVar3;
      }
      else {
        uVar2 = 0xffffffe9;
      }
      return uVar2;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return 0xfffffff7;
}


// ===== sd_cmd7_select @ 2013d434 (200 bytes)

/* (rca, ctx): CMD7 SELECT/DESELECT_CARD (rca 0 deselects), R1 checked against the mask table
   0x20420224 [fact] */

undefined4 sd_cmd7_select(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 == 0) {
    do {
      iVar1 = (**(code **)(param_2[1] + 0x48))(7,0,0,*param_2);
      if (iVar1 == 0) {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  else {
    do {
      iVar1 = (**(code **)(param_2[1] + 0x48))(7,0,param_1 << 0x10,*param_2);
      if (iVar1 == 0) {
        if (2 < iVar3) {
          return 0xfffffff7;
        }
        (**(code **)(param_2[1] + 0x4c))(1,*param_2);
        uVar2 = 0;
        if ((*(uint *)(&DAT_20420224 + (uint)*(ushort *)(*param_2 + 0x2c6) * 4) &
            *(uint *)(*param_2 + 0x2b0)) != 0) {
          uVar2 = 0xffffffe9;
        }
        return uVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  return 0xfffffff7;
}


// ===== sd_select_card @ 2013d4fc (248 bytes)

/* (ctx, ...): makes sure the card is selected (sd_cmd7_select with the RCA +0x2AA); called before
   data transfers (sd_read_sectors, sd_write_sectors, SCR/status/switch reads) [fact] */

int sd_select_card(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint local_10;
  
  local_10 = param_4;
  iVar1 = sd_cmd13_send_status(&local_10,param_1);
  if (iVar1 == 0) {
    if ((local_10 & 0x1e00) == 0x800) {
      return 0;
    }
    if ((local_10 & 0x1e00) == 0xa00) {
      iVar1 = sd_cmd7_select(0,param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      if ((local_10 & 0x1e00) == 0xa00) goto LAB_2013d5d4;
    }
    if ((local_10 & 0x1e00) == 0x600) {
LAB_2013d5d4:
      iVar1 = sd_cmd7_select(*(undefined2 *)(*param_1 + 0x2aa),param_1);
      return iVar1;
    }
    if ((local_10 & 0x1e00) == 0xc00) {
      iVar1 = (**(code **)(param_1[1] + 0x54))(*param_1);
      if (iVar1 == 0) {
        uVar2 = 0;
        do {
          iVar1 = sd_cmd13_send_status(&local_10,param_1);
          if (iVar1 != 0) {
            return iVar1;
          }
          if ((local_10 & 0x1e00) == 0x800) {
            return 0;
          }
          iVar1 = (**(code **)(param_1[1] + 8))();
          if (iVar1 != 0) {
            return iVar1;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < 0x20000);
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -9;
    }
  }
  return iVar1;
}


// ===== sd_acmd51_read_scr @ 2013d5f4 (336 bytes)

/* ACMD51 (SEND_SCR): CMD55 then CMD51, reads the 8-byte SCR into ctx +0x221 [fact] */

int sd_acmd51_read_scr(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = sd_select_card(param_1);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(param_1[1] + 0x50))(8,1,*param_1), iVar2 == 0)) {
    iVar2 = 0;
    do {
      iVar3 = (**(code **)(param_1[1] + 0x48))(0x37,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
      if (iVar3 == 0) {
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
          return -0x17;
        }
        iVar3 = (**(code **)(param_1[1] + 0x48))(0x33,1,0);
        if (iVar3 == 0) {
          if (iVar2 < 3) {
            (**(code **)(param_1[1] + 0x4c))(1,*param_1);
            if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
              return -0x17;
            }
            iVar2 = (**(code **)(param_1[1] + 0x44))(4);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar1 = (**(code **)(param_1[1] + 0x5c))(iVar1 + 0x221,8);
            if (iVar1 != 0) {
              return iVar1;
            }
                    /* WARNING: Could not recover jumptable at 0x2013d740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            iVar1 = (**(code **)(param_1[1] + 0x44))(2);
            return iVar1;
          }
          break;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = -9;
  }
  return iVar2;
}


// ===== sd_acmd6_set_bus_width @ 2013d744 (212 bytes)

/* ACMD6 (SET_BUS_WIDTH) with the width code +0x2AC, then sets the host bus width (op +0x2C) [fact]
    */

undefined4 sd_acmd6_set_bus_width(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(0x37,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      (**(code **)(param_1[1] + 0x4c))(1,*param_1);
      if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
        return 0xffffffe9;
      }
      iVar1 = (**(code **)(param_1[1] + 0x48))(6,1,*(undefined2 *)(*param_1 + 0x2ac));
      if (iVar1 == 0) {
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        (**(code **)(param_1[1] + 0x2c))(*(undefined2 *)(*param_1 + 0x2ac));
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 0xfffffff7;
    }
  } while( true );
}


// ===== sd_acmd13_read_status @ 2013d818 (336 bytes)

/* ACMD13 (SD_STATUS): CMD55 then CMD13 with data, 64 bytes into ctx +0x229 [fact] */

int sd_acmd13_read_status(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = sd_select_card(param_1);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(param_1[1] + 0x50))(0x40,1,*param_1), iVar2 == 0)) {
    iVar2 = 0;
    do {
      iVar3 = (**(code **)(param_1[1] + 0x48))(0x37,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
      if (iVar3 == 0) {
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
          return -0x17;
        }
        iVar3 = (**(code **)(param_1[1] + 0x48))(0xd,1,0);
        if (iVar3 == 0) {
          if (iVar2 < 3) {
            (**(code **)(param_1[1] + 0x4c))(1,*param_1);
            if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
              return -0x17;
            }
            iVar2 = (**(code **)(param_1[1] + 0x44))(4);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar1 = (**(code **)(param_1[1] + 0x5c))(iVar1 + 0x229,0x40);
            if (iVar1 != 0) {
              return iVar1;
            }
                    /* WARNING: Could not recover jumptable at 0x2013d964. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            iVar1 = (**(code **)(param_1[1] + 0x44))(2);
            return iVar1;
          }
          break;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = -9;
  }
  return iVar2;
}


// ===== sd_cmd6_switch_func @ 2013d968 (260 bytes)

/* (arg, ctx): CMD6 (SWITCH_FUNC) with a 64-byte status read into ctx +0x269 [fact] */

int sd_cmd6_switch_func(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_2;
  iVar2 = sd_select_card(param_2);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(param_2[1] + 0x50))(0x40,1,*param_2), iVar2 == 0)) {
    iVar2 = 0;
    do {
      iVar3 = (**(code **)(param_2[1] + 0x48))(6,0,param_1,*param_2);
      if (iVar3 == 0) {
        if (iVar2 < 3) {
          (**(code **)(param_2[1] + 0x4c))(1,*param_2);
          if ((*(uint *)(*param_2 + 0x2b0) & 0x82f80008) != 0) {
            return -0x17;
          }
          iVar2 = (**(code **)(param_2[1] + 0x44))(4);
          if (iVar2 != 0) {
            return iVar2;
          }
          iVar1 = (**(code **)(param_2[1] + 0x5c))(iVar1 + 0x269,0x40);
          if (iVar1 != 0) {
            return iVar1;
          }
                    /* WARNING: Could not recover jumptable at 0x2013da68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar1 = (**(code **)(param_2[1] + 0x44))(2);
          return iVar1;
        }
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = -9;
  }
  return iVar2;
}


// ===== sd_switch_status_check @ 2013de60 (296 bytes)

/* Checks the CMD6 status block (+0x269 max current <= 800 mA field, function group bits) before a
   speed switch [fact for the fields] */

uint sd_switch_status_check(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  (**(code **)(param_1[1] + 0x34))(0);
  uVar1 = sd_cmd6_switch_func(0xffffff,param_1);
  if ((uVar1 == 0) &&
     (uVar1 = *(byte *)(*param_1 + 0x272) & 1, (*(byte *)(*param_1 + 0x272) & 1) != 0)) {
    iVar2 = (**(code **)(param_1[1] + 0x18))(0);
    if (iVar2 == 0) {
      uVar3 = 0;
      while ((uVar1 = (**(code **)(param_1[1] + 8))(), uVar1 == 0 &&
             (uVar1 = sd_cmd6_switch_func(0xfff0ff,param_1), uVar1 == 0))) {
        iVar2 = *param_1;
        if (800 < CONCAT11(*(undefined1 *)(iVar2 + 0x269),*(undefined1 *)(iVar2 + 0x26a)))
        goto LAB_2013df04;
        if ((*(char *)(iVar2 + 0x27a) != '\x01') || ((*(byte *)(iVar2 + 0x282) & 1) == 0)) {
          if ((~*(byte *)(iVar2 + 0x278) & 0xf) == 0) {
            return 0;
          }
          uVar1 = sd_cmd6_switch_func(0x80fff0ff,param_1);
          if (uVar1 != 0) {
            return uVar1;
          }
          if ((*(byte *)(*param_1 + 0x278) & 0xf) == 0) {
            (**(code **)(param_1[1] + 0x34))(0);
            return 0;
          }
        }
        uVar3 = uVar3 + 1;
        if (0x1ffff < uVar3) {
          return 0xffffffff;
        }
      }
    }
    else {
LAB_2013df04:
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ===== sd_select_bus_speed @ 2013df88 (1084 bytes)

/* For SCR spec >= 1.10 and CSD class 10: CMD6 query/switch of function group 1 (and 3/4 variants
   0xFF3FF2..F4), then sets the host clock mode (op +0x3C) and the speed code +0x2C2/+0x2C4 [fact]
    */

uint sd_select_bus_speed(int *param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  *(undefined2 *)(*param_1 + 0x2c4) = 1;
  iVar7 = *param_1;
  uVar6 = *(byte *)(iVar7 + 0x221) & 0xf;
  if (((*(byte *)(iVar7 + 0x221) & 0xf) != 0) &&
     (uVar6 = *(byte *)(iVar7 + 0x205) & 0x40, (*(byte *)(iVar7 + 0x205) & 0x40) != 0)) {
    if ((*(byte *)(iVar7 + 0x2c0) & 4) == 0) {
      uVar6 = sd_cmd6_switch_func(0xffffff,param_1);
      if ((uVar6 == 0) &&
         (uVar6 = *(byte *)(*param_1 + 0x276) & 2, (*(byte *)(*param_1 + 0x276) & 2) != 0)) {
        uVar8 = 0;
        while (uVar6 = sd_cmd6_switch_func(0xfffff1,param_1), uVar6 == 0) {
          iVar7 = *param_1;
          if (800 < CONCAT11(*(undefined1 *)(iVar7 + 0x269),*(undefined1 *)(iVar7 + 0x26a))) {
            return 0;
          }
          if ((*(char *)(iVar7 + 0x27a) != '\x01') || ((*(byte *)(iVar7 + 0x286) & 2) == 0)) {
            if ((~*(byte *)(iVar7 + 0x279) & 0xf) == 0) {
              return 0;
            }
            uVar6 = sd_cmd6_switch_func(0x80fffff1,param_1);
            if (uVar6 != 0) {
              return uVar6;
            }
            if ((*(byte *)(*param_1 + 0x279) & 0xf) == 1) {
              (**(code **)(param_1[1] + 0x30))(1);
              *(undefined2 *)(*param_1 + 0x2c4) = 2;
              return 0;
            }
            uVar6 = (**(code **)(param_1[1] + 8))();
            if (uVar6 != 0) {
              return uVar6;
            }
          }
          uVar8 = uVar8 + 1;
          if (0x1ffff < uVar8) {
            return 0xffffffff;
          }
        }
      }
      return uVar6;
    }
    uVar6 = sd_switch_status_check();
    if (uVar6 == 0) {
      (**(code **)(param_1[1] + 0x3c))(0);
      uVar6 = sd_cmd6_switch_func(0xffffff,param_1);
      if (uVar6 == 0) {
        uVar6 = 0xfffff1;
        bVar1 = *(byte *)(*param_1 + 0x276);
        if ((bVar1 & 8) == 0) {
          if ((bVar1 & 0x10) == 0) {
            if ((bVar1 & 4) == 0) {
              if ((bVar1 & 2) == 0) {
                return bVar1 & 2;
              }
              uVar8 = 2;
            }
            else {
              uVar8 = 4;
              uVar6 = 0xff3ff2;
            }
          }
          else {
            uVar8 = 0x10;
            uVar6 = 0xff3ff4;
          }
        }
        else {
          uVar8 = 8;
          uVar6 = 0xff3ff3;
        }
        uVar9 = 0;
        do {
          uVar3 = (**(code **)(param_1[1] + 8))();
          if (uVar3 != 0) {
            return uVar3;
          }
          uVar3 = sd_cmd6_switch_func(uVar6,param_1);
          if (uVar3 != 0) {
            return uVar3;
          }
          uVar3 = uVar6 & 0xf;
          iVar7 = (**(code **)(param_1[1] + 0x1c))(uVar3);
          iVar4 = *param_1;
          uVar2 = CONCAT11(*(undefined1 *)(iVar4 + 0x269),*(undefined1 *)(iVar4 + 0x26a));
          bVar10 = uVar2 == 800;
          if (uVar2 < 0x321) {
            bVar10 = iVar7 == 0;
          }
          if (bVar10) {
            if (((*(char *)(iVar4 + 0x27a) != '\x01') || ((*(byte *)(iVar4 + 0x286) & uVar8) == 0))
               && ((uVar6 == 0xfffff1 ||
                   ((*(char *)(iVar4 + 0x27a) != '\x01' || ((*(byte *)(iVar4 + 0x280) & 8) == 0)))))
               ) {
              if ((~*(byte *)(iVar4 + 0x279) & 0xf) == 0) {
                return 0;
              }
              if ((~(*(byte *)(iVar4 + 0x278) >> 4) & 0xf) == 0) {
                return 0;
              }
              uVar5 = sd_cmd6_switch_func(uVar6 | 0x80000000,param_1);
              if (uVar5 != 0) {
                return uVar5;
              }
              uVar5 = (uint)*(byte *)(*param_1 + 0x279);
              if (((uVar5 & 0xf) == uVar3) &&
                 ((uVar6 == 0xfffff1 ||
                  ((uVar6 & 0xffff) >> 0xc == (uint)(*(byte *)(*param_1 + 0x278) >> 4))))) {
                uVar5 = uVar5 & 0xf;
                if (uVar5 == 1) {
                  (**(code **)(param_1[1] + 0x3c))(1);
                  *(undefined2 *)(*param_1 + 0x2c2) = 1;
                  *(undefined2 *)(*param_1 + 0x2c4) = 2;
                  return 0;
                }
                if (uVar5 == 2) {
                  (**(code **)(param_1[1] + 0x3c))(2);
                  *(undefined2 *)(*param_1 + 0x2c2) = 2;
                  *(undefined2 *)(*param_1 + 0x2c4) = 3;
                  return 0;
                }
                if (uVar5 == 3) {
                  (**(code **)(param_1[1] + 0x3c))(3);
                  *(undefined2 *)(*param_1 + 0x2c2) = 3;
                  *(undefined2 *)(*param_1 + 0x2c4) = 4;
                  return 0;
                }
                if (uVar5 == 4) {
                  (**(code **)(param_1[1] + 0x3c))(4);
                  *(undefined2 *)(*param_1 + 0x2c2) = 4;
                  *(undefined2 *)(*param_1 + 0x2c4) = 2;
                  return 0;
                }
              }
            }
          }
          else {
            if (uVar3 == 1) {
              return 0;
            }
            if (uVar3 == 3) {
              if ((*(byte *)(iVar4 + 0x276) & 0x10) == 0) goto LAB_2013dca4;
              uVar6 = uVar6 + 1;
              uVar8 = (uVar8 & 0x7f) << 1;
            }
            else if (uVar3 == 4) {
              uVar8 = uVar8 >> 2;
              uVar6 = uVar6 - 2;
            }
            else {
LAB_2013dca4:
              uVar8 = uVar8 >> 1;
              uVar6 = uVar6 - 1;
            }
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < 0x20000);
        uVar6 = 0xffffffff;
      }
      return uVar6;
    }
  }
  return uVar6;
}


// ===== sd_card_identify @ 2013dff0 (624 bytes)

/* card reset/identify, card-type flags at +0x2C0/+0x2C2 */

int sd_card_identify(int *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_r4;
  
  iVar4 = (**(code **)(param_1[1] + 8))();
  if (iVar4 != 0) {
    return iVar4;
  }
  *(undefined2 *)(*param_1 + 0x2c0) = 0;
  *(undefined2 *)(*param_1 + 0x2c2) = 0;
  *(undefined2 *)(*param_1 + 0x2c4) = 0;
  *(undefined2 *)(*param_1 + 0x2c6) = 0;
  (**(code **)(param_1[1] + 0x30))(0);
  iVar4 = FUN_2013c928(1,param_1);
  if (iVar4 != 0) {
    return iVar4;
  }
  sd_delay_ms(1);
  iVar4 = sd_cmd0_go_idle(param_1);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = sd_init_v2(param_1);
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(*param_1 + 0x2c0);
    *(ushort *)(*param_1 + 0x2c0) = uVar1 | 2;
    if ((uVar1 & 4) == 0) goto LAB_2013e0c0;
    iVar4 = FUN_2013cde8(param_1);
  }
  else {
    if (iVar4 == 1) {
      *(ushort *)(*param_1 + 0x2c0) = *(ushort *)(*param_1 + 0x2c0) | 1;
      goto LAB_2013e0c0;
    }
    if (iVar4 != -9) {
      return iVar4;
    }
    *(ushort *)(*param_1 + 0x2c0) = *(ushort *)(*param_1 + 0x2c0) | 1;
    iVar4 = sd_init_v1_or_mmc(param_1);
  }
  if (iVar4 != 0) {
    return iVar4;
  }
LAB_2013e0c0:
  iVar4 = sd_cmd2_all_send_cid(param_1);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = 0;
  if (*(short *)(*param_1 + 0x2c6) == 1) {
    do {
      iVar2 = (**(code **)(param_1[1] + 0x48))(3,0,0x10000,*param_1,unaff_r4);
      if (iVar2 == 0) {
        if (2 < iVar4) {
          return -9;
        }
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        *(undefined2 *)(*param_1 + 0x2aa) = 1;
        uVar3 = *(uint *)(*param_1 + 0x2b0);
        if ((uVar3 & 0xd80000) != 0) {
          if (((uVar3 & 0xd80000) == 0x400000) && ((uVar3 & 0x1e00) == 0x400)) {
            return 0;
          }
          return -0x17;
        }
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
  }
  else {
    do {
      iVar2 = (**(code **)(param_1[1] + 0x48))(3,0,0,*param_1);
      if (iVar2 == 0) {
        if (2 < iVar4) {
          return -9;
        }
        (**(code **)(param_1[1] + 0x4c))(6,*param_1);
        *(short *)(*param_1 + 0x2aa) = (short)((uint)*(undefined4 *)(*param_1 + 0x2b0) >> 0x10);
        if ((*(uint *)(*param_1 + 0x2b0) & 0xe000) == 0) {
          return 0;
        }
        return -8;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
  }
  return -9;
}


// ===== sd_read_csd_cid @ 2013e124 (304 bytes)

/* CMD9 with sd_csd_check / mmc_csd_check, then CMD10; -5 when the CID is all zero [fact] */

int sd_read_csd_cid(int *param_1)

{
  int iVar1;
  
  iVar1 = sd_cmd9_send_csd();
  if (iVar1 == 0) {
    if (*(short *)(*param_1 + 0x2c6) == 1) {
      iVar1 = mmc_csd_check(*param_1 + 0x201);
    }
    else {
      iVar1 = sd_csd_check();
    }
    if ((iVar1 == 0) && (iVar1 = sd_cmd10_send_cid(param_1), iVar1 == 0)) {
      iVar1 = *param_1;
      if ((((*(char *)(iVar1 + 0x211) != '\0') || (*(char *)(iVar1 + 0x212) != '\0')) ||
          (*(char *)(iVar1 + 0x213) != '\0')) &&
         ((((*(char *)(iVar1 + 0x214) != '\0' || (*(char *)(iVar1 + 0x215) != '\0')) ||
           ((*(char *)(iVar1 + 0x216) != '\0' ||
            ((*(char *)(iVar1 + 0x217) != '\0' || (*(char *)(iVar1 + 0x218) != '\0')))))) ||
          ((*(char *)(iVar1 + 0x219) != '\0' ||
           (((((*(char *)(iVar1 + 0x21a) != '\0' || (*(char *)(iVar1 + 0x21b) != '\0')) ||
              (*(char *)(iVar1 + 0x21c) != '\0')) ||
             ((*(char *)(iVar1 + 0x21d) != '\0' || (*(char *)(iVar1 + 0x21e) != '\0')))) ||
            (*(char *)(iVar1 + 0x21f) != '\0')))))))) {
        return 0;
      }
      return -5;
    }
  }
  return iVar1;
}


// ===== sd_selected_op @ 2013e190 (84 bytes)

/* (rca, a, b, ctx): selects the card, runs op +0x50(a, b) (block length set-up) and deselects
   [fact] */

void sd_selected_op(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = sd_cmd7_select(param_1,param_4);
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(param_4[1] + 0x50))(param_2,param_3,*param_4), iVar1 == 0)) {
    sd_cmd7_select(0,param_4);
    return;
  }
  return;
}


// ===== sd_scr_bus_width @ 2013e1e4 (76 bytes)

/* Reads the SCR and sets the bus-width code +0x2AC from SD_BUS_WIDTHS (bit 2 of SCR byte 1: 4-bit)
   [fact] */

int sd_scr_bus_width(int *param_1)

{
  int iVar1;
  
  iVar1 = sd_acmd51_read_scr();
  if (iVar1 == 0) {
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x222) & 4) == 0) {
      *(undefined2 *)(iVar1 + 0x2ac) = 0;
      return 0;
    }
    *(undefined2 *)(iVar1 + 0x2ac) = 2;
    iVar1 = 0;
  }
  return iVar1;
}


// ===== sd_read_sectors @ 2013e230 (132 bytes)

/* driver op +0x58 */

uint sd_read_sectors(int param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  
  if ((*(byte *)(*param_4 + 0x2c0) & 2) == 0) {
    param_1 = param_1 << 9;
  }
  uVar1 = sd_select_card(param_4);
  if ((uVar1 == 0) &&
     ((*(short *)(*param_4 + 0x2c2) != 2 && *(short *)(*param_4 + 0x2c2) != 3 ||
      (uVar1 = (**(code **)(param_4[1] + 0x40))(), uVar1 == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x2013e2ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_4[1] + 0x58))(param_1,param_2,param_3,*param_4);
    return uVar1;
  }
  return uVar1;
}


// ===== sd_write_sectors @ 2013e2b4 (156 bytes)

/* driver op +0x60; -7 = write-protected */

int sd_write_sectors(int param_1,uint param_2,uint param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_4[1] + 0xc))();
  if (iVar1 == 0) {
    if ((*(byte *)(*param_4 + 0x2c0) & 2) == 0) {
      param_1 = param_1 << 9;
    }
    iVar1 = sd_select_card(param_4);
    if ((iVar1 == 0) &&
       ((*(short *)(*param_4 + 0x2c2) != 2 && *(short *)(*param_4 + 0x2c2) != 3 ||
        (iVar1 = (**(code **)(param_4[1] + 0x40))(), iVar1 == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x2013e348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(param_4[1] + 0x60))(param_1,param_2,param_3,*param_4);
      return iVar1;
    }
  }
  else {
    iVar1 = -7;
  }
  return iVar1;
}


// ===== sd_vol_read @ 2013e35c (112 bytes)

/* (vol, sector, buf, n, ctx): partition read: bounds check against vol +0x14, offset vol +0x30, 3
   tries of sd_read_sectors [fact] */

uint sd_vol_read(int param_1,uint param_2,uint param_3,uint param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    iVar2 = 0;
    do {
      uVar1 = (**(code **)(param_5[1] + 8))();
      if (uVar1 != 0) {
        return uVar1;
      }
      uVar1 = sd_read_sectors(*(int *)(param_1 + 0x30) + param_2,param_3,param_4,param_5);
      if (uVar1 == 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


// ===== sd_vol_write @ 2013e3cc (112 bytes)

/* (vol, sector, buf, n, ctx): partition write, bounds check, one sd_write_sectors try [fact] */

int sd_vol_write(int param_1,uint param_2,uint param_3,uint param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    iVar2 = 0;
    do {
      iVar1 = (**(code **)(param_5[1] + 8))();
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = sd_write_sectors(*(int *)(param_1 + 0x30) + param_2,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 1);
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}


// ===== sd_mount_volume @ 2013e43c (208 bytes)

/* Reads sector 0 (MBR), finds the partition (fat_find_volume), reads its boot sector, fat_mount and
   the FSInfo check (fat32_fsinfo_read) [fact] */

uint sd_mount_volume(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = sd_read_sectors(0,*param_2 + 1,1,param_2);
  if (uVar1 == 0) {
    iVar2 = fat_find_volume(param_1,*param_2 + 1);
    if (iVar2 == 0) {
      uVar1 = sd_read_sectors(*(int *)(param_1 + 0x30),*param_2 + 1,1,param_2);
      if (uVar1 != 0) {
        return uVar1;
      }
      uVar1 = fat_mount(param_1,*param_2 + 1);
      if (-1 < (int)uVar1) {
        if (*(char *)(param_1 + 0x10) == ' ') {
          uVar1 = sd_read_sectors(*(int *)(param_1 + 0x30) + (uint)*(ushort *)(param_1 + 0x3a),
                                  *param_2 + 1,1,param_2);
          if (uVar1 != 0) {
            return uVar1;
          }
          fat32_fsinfo_read(param_1,*param_2 + 1);
        }
        return 0;
      }
    }
    uVar1 = 0xfffffffc;
  }
  return uVar1;
}


// ===== sd_driver_op @ 2013e71c (700 bytes)

/* Driver entry of drive I: (op code): 1 read sectors, 2 write sectors, 5 format step, 7 mount
   (power, sd_card_identify, CSD/CID, RCA select, SCR, bus width, bus speed, SD status, volume
   mount), 8 unmount, others through a table; registered by sdhi_drv_init [fact] */

int sd_driver_op(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int *param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  switch(param_2) {
  default:
    return -3;
  case 1:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      iVar2 = sd_vol_read(param_1,param_3,param_4,param_5,param_6);
      return iVar2;
    }
    break;
  case 2:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      iVar2 = sd_vol_write(param_1,param_3,param_4,param_5,param_6);
      return iVar2;
    }
    break;
  case 5:
    iVar2 = (**(code **)(param_6[1] + 100))();
    if ((iVar2 == 0) && (iVar2 = sd_card_task_start(param_1,*(undefined1 *)*param_6), iVar2 == 0)) {
      *(int **)(param_1 + 0x24) = param_6;
      return 0;
    }
    return -8;
  case 7:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      iVar2 = (**(code **)(param_6[1] + 0x24))();
      if (iVar2 == 0) {
        iVar3 = 0;
        do {
          iVar2 = (**(code **)(param_6[1] + 0x20))(2);
          if ((((((iVar2 == 0) && (iVar2 = sd_card_identify(param_6), iVar2 == 0)) &&
                (iVar2 = sd_read_csd_cid(param_6), iVar2 == 0)) &&
               ((iVar2 = sd_selected_op(*(undefined2 *)(*param_6 + 0x2aa),0x200,1,param_6),
                iVar2 == 0 &&
                (iVar2 = sd_cmd7_select(*(undefined2 *)(*param_6 + 0x2aa),param_6), iVar2 == 0))))
              && ((*(short *)(*param_6 + 0x2c6) == 1 ||
                  (((iVar2 = sd_scr_bus_width(param_6), iVar2 == 0 &&
                    (iVar2 = sd_acmd6_set_bus_width(param_6), iVar2 == 0)) &&
                   ((iVar2 = sd_select_bus_speed(param_6), iVar2 == 0 &&
                    (iVar2 = sd_acmd13_read_status(param_6), iVar2 == 0)))))))) &&
             ((iVar2 = FUN_2013c928(1,param_6), iVar2 == 0 &&
              (((*(short *)(*param_6 + 0x2c2) != 2 && *(short *)(*param_6 + 0x2c2) != 3 ||
                (iVar2 = (**(code **)(param_6[1] + 0x40))(), iVar2 == 0)) &&
               (iVar2 = sd_mount_volume(param_1,param_6), iVar2 == 0)))))) {
            itron_loc_cpu();
            *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) | 0x80;
            iVar2 = (**(code **)(param_6[1] + 0xc))();
            if (iVar2 == 0) {
              bVar1 = *(byte *)(param_1 + 0x68) & 0xdf;
            }
            else {
              bVar1 = *(byte *)(param_1 + 0x68) | 0x20;
            }
            *(byte *)(param_1 + 0x68) = bVar1;
            itron_unl_cpu();
            return 0;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 3);
      }
      return iVar2;
    }
    break;
  case 8:
    (**(code **)(param_6[1] + 0x28))();
    itron_loc_cpu();
    *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
    itron_unl_cpu();
    return 0;
  case 9:
                    /* WARNING: Could not recover jumptable at 0x2013e358. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (**(code **)(param_6[1] + 8))();
    return iVar2;
  }
  return -6;
}


// ===== sd_format_progress_dec @ 2013e7e8 (24 bytes)

/* Decrements the format progress counter ctx +0x2F4 while non-zero [fact] */

void sd_format_progress_dec(int param_1)

{
  if (*(int *)(param_1 + 0x2f4) != 0) {
    *(int *)(param_1 + 0x2f4) = *(int *)(param_1 + 0x2f4) + -1;
  }
  return;
}


// ===== sd_format_progress_set @ 2013e800 (12 bytes)

/* (n, ctx): sets the format progress counters +0x2F4 and +0x2F8 to n [fact] */

void sd_format_progress_set(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x2f4) = param_1;
  *(undefined4 *)(param_2 + 0x2f8) = param_1;
  return;
}


// ===== fat_format_write_fats @ 2013e8d0 (420 bytes)

/* Format step: writes the first sector of each FAT with the media entries (F8 FF FF / F8 FF FF FF /
   F8 FF FF 0F FF FF FF 0F... from 0x20420254..) and zero sectors after them, counting progress
   [fact] */

int fat_format_write_fats(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *param_1;
  iVar7 = 0;
  fs_memset(iVar2 + 1,0,0x200,0);
  cVar1 = *(char *)(iVar2 + 0x2dc);
  if (cVar1 == '\f') {
    fs_memcpy(*param_1 + 1,&DAT_20420254,3);
  }
  else if (cVar1 == '\x10') {
    fs_memcpy(*param_1 + 1,&DAT_20420257,4);
  }
  else {
    if (cVar1 != ' ') {
      return -2;
    }
    fs_memcpy(*param_1 + 1,&DAT_204202f3,0xc);
  }
  iVar6 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4);
  iVar3 = sd_write_sectors(iVar6,*param_1 + 1,1,param_1);
  if (iVar3 == 0) {
    if (*(char *)(iVar2 + 0x2dc) != '@') {
      iVar7 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4) + *(int *)(iVar2 + 0x2e0);
      iVar4 = sd_write_sectors(iVar7,*param_1 + 1,1,param_1);
      iVar3 = 0;
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    sd_format_progress_dec(*param_1);
    fs_memset(*param_1 + 1,0,0x200);
    iVar4 = *(int *)(iVar2 + 0x2e0);
    if ((*(char *)(iVar2 + 0x2dc) != '@') && (uVar5 = 0, iVar4 != 1)) {
      do {
        iVar7 = iVar7 + 1;
        iVar6 = iVar6 + 1;
        iVar2 = sd_write_sectors(iVar6,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = sd_write_sectors(iVar7,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        sd_format_progress_dec(*param_1);
        uVar5 = uVar5 + 1;
        iVar3 = 0;
      } while (uVar5 < iVar4 - 1U);
    }
  }
  return iVar3;
}

