// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== mainlink_rx_bind @ 2015eb74 (12 bytes)

/* (uart, tx, dispatcher) */

void mainlink_rx_bind(int param_1,uint param_2,uint param_3,uint param_4)

{
  *(uint *)(param_1 + 0x10) = param_2;
  *(uint *)(param_1 + 0x14) = param_3;
  *(uint *)(param_1 + 0x18) = param_4;
  return;
}


// ===== mainlink_rx_clear_stats @ 2015eb80 (16 bytes)

void mainlink_rx_clear_stats(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}


// ===== mainlink_rx_parse @ 2015eb90 (168 bytes)

/* first byte: 06/15/1B single byte; else table lookup 0x20450074 */

int mainlink_rx_parse(uint param_1,char *param_2,int param_3,void *param_4)

{
  char cVar1;
  uint i;
  int mainlink_rx_frame_ret;
  
  cVar1 = *param_2;
  if (cVar1 == '\x06') {
    if (g_ml.hello_acked == 0) {
                    /* 0x06 from MAIN: the hello was acknowledged [fact: mainlink.md] */
      g_ml.hello_acked = 1;
    }
  }
  else if (cVar1 != '\x15' && cVar1 != '\x1b') {
    i = 0;
    do {
      if ((&DAT_20450074)[i * 0xc] == cVar1) {
        mainlink_rx_frame_ret =
             mainlink_rx_frame(param_1,(int)(&DAT_20450074 + i * 0xc),(uint)param_2,param_3);
        if (mainlink_rx_frame_ret == 0) {
          *(undefined1 **)param_4 = &DAT_20450074 + i * 0xc;
        }
        return mainlink_rx_frame_ret;
      }
      i = i + 1;
    } while (i < 0x2b);
    return param_3;
  }
  mainlink_rx_deliver(param_1,param_2,1);
  return 1;
}


// ===== task_mainlink_rx @ 2015ec40 (512 bytes)

/* task "uart" pri 3: reads SCIF5, re-assembles frames, NAK after 3 empty reads */

void task_mainlink_rx(uint param_1)

{
  void *itron_twai_flg_ret;
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int tmout;
  uint uVar5;
  bool bVar6;
  int local_534;
  char acStack_530 [1024];
  undefined1 auStack_130 [256];
  uint local_30 [2];
  
  __aeabi_memclr4(auStack_130,0x100);
  __aeabi_memclr4(acStack_530,0x400);
  uVar3 = 0;
  tmout = -1;
  local_534 = 0;
  mainlink_rx_clear_stats(param_1);
  uVar4 = 0;
LAB_2015ec90:
                    /* Wait for RX data (2 ms while a frame is partial) [fact: mainlink.md] */
  while (itron_twai_flg_ret = itron_twai_flg(*(uint *)(param_1 + 0x34),0xc001,5,local_30,tmout),
        itron_twai_flg_ret != (void *)0xffffffce) {
    if (itron_twai_flg_ret != (void *)0x0) {
      return;
    }
    if ((local_30[0] & 0xc000) == 0) goto LAB_2015ed10;
    tmout = -1;
    uVar3 = 0;
    local_534 = 0;
  }
  goto joined_r0x2015ece4;
LAB_2015ed10:
  if ((local_30[0] & 1) != 0) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x10))
                      (*(int **)(param_1 + 0x10),auStack_130,0x100);
    if (iVar1 == 0) {
joined_r0x2015ece4:
      bVar6 = 2 < (int)uVar4;
      uVar4 = uVar4 + 1;
      if (bVar6) {
                    /* 3 timeouts with a partial frame: NAK and resync [fact: mainlink.md] */
        mainlink_send_nak(param_1);
        local_534 = 0;
        uVar3 = 0;
        tmout = -1;
        uVar4 = 0;
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      }
      itron_dly_tsk(1);
    }
    else {
      uVar5 = uVar3 + iVar1;
      if (0x3ff < uVar5) {
        *(uint *)(param_1 + 0x38) = uVar5;
      }
      memcpy(acStack_530 + uVar3,auStack_130);
      if (local_534 == 0) {
        uVar2 = mainlink_rx_parse(param_1,acStack_530,uVar5,&local_534);
        uVar3 = uVar5;
      }
      else {
                    /* Table command: wait for n + 2 bytes, check, ACK [fact: 0x2015EEC8] */
        uVar2 = mainlink_rx_frame(param_1,local_534,(uint)acStack_530,uVar5);
        if (600 < uVar2) {
          mainlink_send_nak(param_1);
          uVar5 = 0;
          local_534 = 0;
          uVar4 = 0;
        }
        for (; uVar3 = uVar5, 0 < (int)uVar2;
            uVar2 = mainlink_rx_parse(param_1,acStack_530 + uVar2,uVar5,&local_534)) {
          if ((int)uVar5 <= (int)uVar2) goto LAB_2015edf4;
          uVar5 = uVar5 - uVar2;
        }
      }
      if (uVar2 == 0) {
        tmout = 2;
      }
      else {
LAB_2015edf4:
        bVar6 = uVar2 == uVar3;
        uVar4 = uVar2 - uVar3;
        if (!bVar6) {
          uVar4 = uVar2;
        }
        if ((!bVar6 && uVar2 != 0) && (int)uVar4 < 0 == (bVar6 && SBORROW4(uVar2,uVar3))) {
          mainlink_send_nak(param_1);
        }
        uVar3 = 0;
        tmout = -1;
        local_534 = 0;
        uVar4 = uVar3;
      }
    }
  }
  goto LAB_2015ec90;
}


// ===== mainlink_send_ack @ 2015ee40 (68 bytes)

/* 1-byte 0x06 frame */

void mainlink_send_ack(int param_1)

{
  uint mainlink_tx_alloc_ret;
  
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  mainlink_tx_alloc_ret = mainlink_tx_alloc(*(int *)(param_1 + 0x14));
  *(undefined2 *)(mainlink_tx_alloc_ret + 4) = 0xaa;
  *(undefined2 *)(mainlink_tx_alloc_ret + 6) = 1;
  *(undefined1 *)(mainlink_tx_alloc_ret + 8) = 6;
  mainlink_tx_post(*(int *)(param_1 + 0x14),mainlink_tx_alloc_ret);
  return;
}


// ===== mainlink_send_nak @ 2015ee84 (68 bytes)

/* 1-byte 0x15 frame */

void mainlink_send_nak(int param_1)

{
  uint mainlink_tx_alloc_ret;
  
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  mainlink_tx_alloc_ret = mainlink_tx_alloc(*(int *)(param_1 + 0x14));
  *(undefined2 *)(mainlink_tx_alloc_ret + 4) = 0xaa;
  *(undefined2 *)(mainlink_tx_alloc_ret + 6) = 1;
  *(undefined1 *)(mainlink_tx_alloc_ret + 8) = 0x15;
  mainlink_tx_post(*(int *)(param_1 + 0x14),mainlink_tx_alloc_ret);
  return;
}


// ===== mainlink_rx_frame @ 2015eec8 (116 bytes)

/* waits for len+2 bytes, validates, ACKs, delivers */

int mainlink_rx_frame(uint param_1,int param_2,uint param_3,int param_4)

{
  bool mainlink_rx_validate_ret;
  uint uVar1;
  
  uVar1 = *(ushort *)(param_2 + 2) + 2;
  if (param_4 < (int)uVar1) {
    uVar1 = 0;
  }
  else {
    mainlink_rx_validate_ret = mainlink_rx_validate(param_1,(byte *)param_3);
    if (mainlink_rx_validate_ret) {
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
      if (*(char *)(param_2 + 4) == '\0') {
        mainlink_send_ack(param_1);
      }
      mainlink_rx_deliver(param_1,(char *)param_3,uVar1);
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}


// ===== mainlink_rx_ctor @ 2015efe4 (12 bytes)

/* vtbl 0x20427FF8 */

void mainlink_rx_ctor(undefined4 *param_1)

{
  *param_1 = &DAT_20427ff8;
  return;
}


// ===== mouse_cursor_task_create @ 2015eff4 (72 bytes)

void mouse_cursor_task_create(int param_1)

{
  uint uVar1;
  
  uVar1 = itron_acre_tsk(0,(byte *)&ctsk_mouse_cursor_5700);
  if (0 < (int)uVar1) {
    mouse_cursor_obj_init(param_1 + 4);
    uVar1 = itron_sta_tsk(uVar1,param_1 + 4);
    if (uVar1 == 0) {
      itron_tslp_tsk(0xffffffff);
      return;
    }
  }
  return;
}


// ===== FUN_2015f040 @ 2015f040 (24 bytes)

int FUN_2015f040(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428004;
  iVar1 = FUN_2015ff70(param_1 + 1);
  return iVar1 + -4;
}


// ===== FUN_2015f05c @ 2015f05c (60 bytes)

void FUN_2015f05c(int param_1)

{
  uint uVar1;
  
  *(undefined1 *)(param_1 + 0x81) = 0;
  uVar1 = 0;
  do {
    ring16_set_slot(param_1 + 0x88,uVar1 & 0xffff,param_1 + uVar1 * 8);
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x10);
  ring16_reset(param_1 + 0x88);
  return;
}


// ===== kbdobj_set_device @ 2015f098 (28 bytes)

/* (obj, device, present): stores the present flag (+0x81) and the device (+0x84); clears the active
   flag +0x80 when not present; usbkbd_attach / usbkbd_detach [fact] */

void kbdobj_set_device(int param_1,undefined4 param_2,int param_3)

{
  *(char *)(param_1 + 0x81) = (char)param_3;
  *(undefined4 *)(param_1 + 0x84) = param_2;
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + 0x80) = 0;
  }
  return;
}


// ===== kbdobj_activate @ 2015f0b4 (16 bytes)

/* (obj): active flag +0x80 = 1 and resets the key ring at +0x88 (ring16_reset) [fact] */

void kbdobj_activate(int param_1)

{
  *(undefined1 *)(param_1 + 0x80) = 1;
  ring16_reset(param_1 + 0x88);
  return;
}


// ===== kbdobj_flush @ 2015f0c4 (8 bytes)

/* (obj): ring16_reset of the key ring at +0x88; usbkbd_flush_all [fact] */

void kbdobj_flush(int param_1)

{
  ring16_reset(param_1 + 0x88);
  return;
}


// ===== kbdobj_ctor @ 2015f0cc (20 bytes)

/* (obj): constructs the key ring at +0x88 (ring16_ctor) [fact] */

int kbdobj_ctor(int param_1)

{
  int iVar1;
  
                    /* ring16_reset, returns this [doc] */
  iVar1 = ring16_ctor(param_1 + 0x88);
  return iVar1 + -0x88;
}


// ===== task_fwdbg @ 2015f0e0 (12 bytes)

/* task entry: loops on update_display_self */

undefined4 task_fwdbg(void *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  ulonglong update_display_self_ret;
  
  update_display_self_ret = update_display_self(param_1);
  puVar4 = (uint *)(update_display_self_ret >> 0x20);
  puVar1 = (undefined4 *)update_display_self_ret;
  uVar2 = strcmp((uint *)"fw1up",puVar4);
  if (uVar2 == 0) {
    itron_set_flg(*puVar1,0x1001,*puVar1,extraout_r3,param_1);
    uVar3 = 1;
  }
  else {
    uVar2 = strcmp((uint *)"fw1chk",puVar4);
    if (uVar2 == 0) {
      itron_set_flg(*puVar1,0x3001,*puVar1,extraout_r3_00,param_1);
      uVar3 = 1;
    }
    else {
      uVar2 = strcmp((uint *)&DAT_20428198,puVar4);
      if (uVar2 == 0) {
        itron_set_flg(*puVar1,1,*puVar1,extraout_r3_01,param_1);
        uVar3 = 1;
      }
      else {
        uVar2 = strcmp((uint *)&DAT_2042819c,puVar4);
        if (uVar2 == 0) {
          itron_set_flg(*puVar1,2,*puVar1,extraout_r3_02,param_1);
          uVar3 = 1;
        }
        else {
          uVar2 = strcmp((uint *)&DAT_204281a0,puVar4);
          if (uVar2 == 0) {
            itron_set_flg(*puVar1,4);
            uVar3 = 1;
          }
          else {
            uVar3 = 0;
          }
        }
      }
    }
  }
  return uVar3;
}


// ===== fwdbg_cmd @ 2015f0ec (240 bytes)

/* fw1up, fw1chk, up0, up1, up2 -> event flags of the self-update task */

undefined4 fwdbg_cmd(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = strcmp((uint *)"fw1up",param_2);
  if (uVar1 == 0) {
    itron_set_flg(*param_1,0x1001);
    uVar2 = 1;
  }
  else {
    uVar1 = strcmp((uint *)"fw1chk",param_2);
    if (uVar1 == 0) {
      itron_set_flg(*param_1,0x3001);
      uVar2 = 1;
    }
    else {
      uVar1 = strcmp((uint *)&DAT_20428198,param_2);
      if (uVar1 == 0) {
        itron_set_flg(*param_1,1);
        uVar2 = 1;
      }
      else {
        uVar1 = strcmp((uint *)&DAT_2042819c,param_2);
        if (uVar1 == 0) {
          itron_set_flg(*param_1,2);
          uVar2 = 1;
        }
        else {
          uVar1 = strcmp((uint *)&DAT_204281a0,param_2);
          if (uVar1 == 0) {
            itron_set_flg(*param_1,4);
            uVar2 = 1;
          }
          else {
            uVar2 = 0;
          }
        }
      }
    }
  }
  return uVar2;
}


// ===== fwdbg_verify_bank1 @ 2015f1f0 (332 bytes)

/* fw1chk: compares a file with bank 1 (0x18400000), forever (was display_flash_write_bank) */

undefined4 fwdbg_verify_bank1(int param_1,uint param_2)

{
  int iVar1;
  uint fs_fopen_ret;
  undefined4 uVar2;
  uint fs_fread_ret;
  int iVar3;
  code *pcVar4;
  uint n;
  ulonglong __aeabi_idivmod_ret;
  
  iVar1 = DAT_208001c4;
  DAT_208001c0 = DAT_208001c0 + 1;
  fs_fopen_ret = fs_fopen(param_2,0x204281a4);
  if (fs_fopen_ret == 0) {
    uVar2 = 3;
  }
  else {
    kbd_led_status(3,7);
    itron_dly_tsk(10);
    itron_dly_tsk(10);
    kbd_led_status(4,7);
    pcVar4 = FUN_18400000;
    n = 0;
    do {
      fs_fread_ret = fs_fread(param_1 + 4,1,0x100,fs_fopen_ret);
      if (fs_fread_ret == 0) break;
      n = n + 1;
      __aeabi_idivmod_ret = __aeabi_idivmod(n,100);
      if ((int)(__aeabi_idivmod_ret >> 0x20) == 0) {
        itron_dly_tsk(10);
      }
      iVar3 = memcmp(param_1 + 4,pcVar4,fs_fread_ret);
      if (iVar3 != 0) {
        DAT_208001c4 = DAT_208001c4 + 1;
      }
      pcVar4 = pcVar4 + 0x100;
    } while (fs_fread_ret != 0);
    fs_fclose(fs_fopen_ret);
    if (iVar1 == DAT_208001c4) {
      uVar2 = 0;
    }
    else {
      uVar2 = 3;
    }
  }
  return uVar2;
}


// ===== fwdbg_write_other_bank @ 2015f348 (512 bytes)

/* fw1up: raw I:\AH076H_DISPLAY.bin to the non-running bank + flag */

undefined4 fwdbg_write_other_bank(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint spiflash_write_ret;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  int local_30;
  int iStack_2c;
  uint local_28;
  
  iStack_2c = param_1;
  local_28 = param_2;
  uVar1 = fs_fopen(param_2,0x204281a6);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else {
    fs_fsize(uVar1,&local_30);
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    if (g_bootinfo.bank == 1) {
      puVar4 = &g_bootinfo.bank2_flag;
      puVar5 = &g_bootinfo.bank1_flag;
    }
    else if (g_bootinfo.bank == 2) {
      puVar4 = &g_bootinfo.bank1_flag;
      puVar5 = &g_bootinfo.bank2_flag;
    }
    else {
      puVar4 = &g_bootinfo.bank1_flag;
      puVar5 = &g_bootinfo.bank2_flag;
    }
    uVar6 = puVar4[1];
    kbd_led_status(3,7);
    uVar3 = spiflash_erase(0,*puVar4,0x14);
    if (uVar3 == 0) {
      uVar3 = spiflash_erase(0,puVar4[1],local_30);
      if (uVar3 == 0) {
        kbd_led_status(4,7);
        local_48 = 0xffffffff;
                    /* reflected poly 0xEDB88320 [doc, inference] */
        crc32_make_table();
        do {
          uVar3 = fs_fread(param_1 + 4,1,0x100,uVar1);
          if (uVar3 == 0) break;
          spiflash_write_ret = spiflash_write(uVar6,param_1 + 4,uVar3);
          if (spiflash_write_ret != 0) {
            fs_fclose(uVar1);
            return 3;
          }
          local_48 = crc32_update(local_48,uVar3,param_1 + 4);
          uVar6 = uVar6 + 0x100;
        } while (uVar3 != 0);
        fs_fclose(uVar1);
        local_44 = 0x11111111;
        local_34 = ~local_48;
        local_40 = local_30;
        uVar1 = spiflash_write(*puVar4,(uint)&local_44,0x14);
        if (uVar1 == 0) {
          uVar1 = spiflash_erase(0,*puVar5,0x14);
          if (uVar1 == 0) {
            uVar2 = 0;
          }
          else {
            uVar2 = 3;
          }
        }
        else {
          uVar2 = 3;
        }
      }
      else {
        fs_fclose(uVar1);
        uVar2 = 3;
      }
    }
    else {
      fs_fclose(uVar1);
      uVar2 = 3;
    }
  }
  return uVar2;
}


// ===== fwdbg_task_create @ 2015f55c (200 bytes)

/* event flag + task (entry 0x2015F0E0, pri 5, stack 0x2000) */

undefined4 fwdbg_task_create(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  code *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_2c = 0;
  local_28 = 0;
  local_24 = task_fwdbg;
  local_20 = 5;
  local_1c = 0x2000;
  local_18 = 0;
  local_14 = 0;
  local_38 = 2;
  local_34 = 0;
  local_30 = 0;
  uVar1 = itron_acre_flg(0,(byte *)&local_38);
  *param_1 = uVar1;
  if ((int)*param_1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar1 = itron_acre_tsk(0,(byte *)&local_2c);
    if ((int)uVar1 < 1) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar1 = itron_sta_tsk(uVar1,(uint)param_1);
      if (uVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}


// ===== update_display_self @ 2015f62c (1028 bytes)

/* I:\AH076H_DISPLAY.bin, I:\AH068_DISPLAY_Loader.bin */

ulonglong update_display_self(void *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint local_54;
  undefined1 auStack_48 [52];
  int local_14;
  char *local_10;
  void *local_c;
  uint local_8 [2];
  
LAB_2015f638:
  do {
    local_c = itron_twai_flg(*(uint *)param_1,0xffff,5,local_8,-1);
    iVar7 = 0;
    iVar6 = 0;
    if ((local_8[0] & 1) == 0) {
      if ((local_8[0] & 2) == 0) {
        if ((local_8[0] & 4) != 0) {
          iVar6 = 0xa00000;
          iVar7 = 0x3f0000;
        }
      }
      else {
        iVar6 = 0x400000;
        iVar7 = 0x3e0000;
      }
    }
    else {
      iVar6 = 0;
    }
    kbd_led_status(0,7);
    do {
      do {
        kbd_led_status(0,7);
        itron_dly_tsk(100);
        kbd_led_status(1,7);
        local_10 = "I:\\AH076H_DISPLAY.bin";
        if (local_8[0] == 1) {
          local_10 = "I:\\AH068_DISPLAY_Loader.bin";
        }
        iVar2 = fs_stat(local_10,auStack_48);
      } while ((iVar2 != 0) || (uVar3 = fs_fopen((uint)local_10,(uint)&DAT_204281da), uVar3 == 0));
      kbd_led_status(2,7);
      iVar2 = 0;
      do {
        uVar4 = fs_fread((int)param_1 + 4,1,0x100,uVar3);
        iVar2 = iVar2 + uVar4;
      } while (uVar4 != 0);
      if (local_14 != iVar2) goto LAB_2015f638;
      fs_fclose(uVar3);
      if (local_8[0] == 0x1001) {
        iVar6 = fwdbg_write_other_bank(param_1,local_10);
        if (iVar6 == 0) {
          kbd_led_status(7,7);
        }
        else {
          kbd_led_status(5,7);
        }
        goto LAB_2015f638;
      }
      if (local_8[0] == 0x3001) {
        do {
          iVar6 = fwdbg_verify_bank1(param_1,local_10);
          if (iVar6 == 0) {
            kbd_led_status(7,7);
          }
          else {
            kbd_led_status(5,7);
          }
          itron_dly_tsk(0x32);
        } while( true );
      }
      kbd_led_status(3,7);
      if ((((iVar7 != 0) || ((local_8[0] & 0x1000) != 0)) &&
          ((uVar3 = spiflash_erase(0,0x3e0000,0x14), uVar3 != 0 ||
           (uVar3 = spiflash_erase(0,0x3f0000,0x14), uVar3 != 0)))) ||
         (uVar3 = spiflash_erase(0,iVar6,iVar2), uVar3 != 0)) goto LAB_2015f638;
      kbd_led_status(4,7);
      uVar3 = fs_fopen((uint)local_10,(uint)&DAT_204281da);
    } while (uVar3 == 0);
    bVar1 = false;
    local_54 = 0xffffffff;
                    /* reflected poly 0xEDB88320 [doc, inference] */
    crc32_make_table();
    do {
      uVar4 = fs_fread((int)param_1 + 4,1,0x100,uVar3);
      if (uVar4 == 0) break;
      for (uVar5 = 0; uVar5 < uVar4; uVar5 = uVar5 + 1) {
      }
      local_54 = crc32_update(local_54,uVar4,(int)param_1 + 4);
      uVar5 = spiflash_write(iVar6,(int)param_1 + 4,uVar4);
      if (uVar5 != 0) {
        bVar1 = false;
        break;
      }
      iVar6 = iVar6 + 0x100;
      bVar1 = true;
    } while (uVar4 != 0);
    fs_fclose(uVar3);
    if (((bVar1) && (iVar7 != 0)) &&
       (uVar3 = spiflash_write(iVar7,(uint)&stack0xffffff98,0x14), uVar3 != 0)) {
      bVar1 = false;
    }
    if (bVar1) {
      kbd_led_status(7,7);
    }
    else {
      kbd_led_status(5,7);
    }
  } while( true );
}


// ===== FUN_2015fa40 @ 2015fa40 (68 bytes)

undefined4 FUN_2015fa40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  mutex_guard_ctor(&uStack_10,*(undefined4 *)(param_1 + 0x588),1);
  iVar1 = ring32_post_inc(param_1 + 0x504);
  uVar2 = *(undefined4 *)(param_1 + 0x504 + iVar1 * 4 + 4);
                    /* Scoped lock destructor [doc] */
  mutex_guard_dtor(&uStack_10);
  return uVar2;
}


// ===== mouse_cursor_move @ 2015fa54 (52 bytes)

void mouse_cursor_move(int param_1,ushort param_2,ushort param_3)

{
  itron_twai_sem(*(undefined4 *)(param_1 + 0x598),0xffffffff);
  *(ushort *)(param_1 + 0x592) = param_2;
  *(ushort *)(param_1 + 0x594) = param_3;
  itron_sig_sem(*(undefined4 *)(param_1 + 0x598));
  return;
}


// ===== mouse_wheel_event @ 2015fac4 (360 bytes)

/* wheel -> encoder id 6/2/3 or list scroll by screen id */

void mouse_wheel_event(undefined4 param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined2 uVar2;
  undefined *puVar3;
  
  DAT_20808534 = *(undefined2 *)(param_2 + 0x22);
  puVar3 = (undefined *)0x0;
  cVar1 = (char)DAT_20808534;
  if (gui_frame.cmd != 0x3a) {
    if (gui_frame.cmd < 0x3b) {
      if (gui_frame.cmd == 0x20) {
        FUN_20113de0(6,(int)cVar1,param_3,param_2);
        mainlink_renc_event(&DAT_208d9c1e);
        return;
      }
      if (gui_frame.cmd == 0x30) {
        switch(gui_frame.payload[0]) {
        case 0:
          puVar3 = &DAT_20800342;
          param_3 = 6;
          break;
        case 1:
          puVar3 = &DAT_2080033a;
          param_3 = 4;
          break;
        case 2:
          puVar3 = &DAT_20800334;
          param_3 = 3;
          break;
        case 3:
          puVar3 = &DAT_2080032a;
          param_3 = 2;
          break;
        case 4:
          puVar3 = &DAT_2080034e;
          param_3 = 5;
          break;
        case 5:
        case 0xb:
        case 0xc:
          goto switchD_2015fb98_caseD_5;
        }
        if (puVar3 != (undefined *)0x0) {
          uVar2 = FUN_2015fc80(param_1,puVar3,param_3);
          mainlink_send_touch_key(1,uVar2,0);
          mainlink_send_touch_key(0,uVar2);
          return;
        }
      }
      else if (gui_frame.cmd == 0x34 || gui_frame.cmd == 0x37) goto switchD_2015fb98_caseD_5;
      return;
    }
    if (gui_frame.cmd == 0x40) {
      if ((gui_frame.payload[3] & 0xf) == 3) {
        FUN_20113de0(2,(int)cVar1,param_3,param_2);
        mainlink_renc_event(&DAT_208d9c0a);
        return;
      }
    }
    else {
      if (gui_frame.cmd == 0x41) {
        FUN_20113de0(3,(int)-cVar1,param_3,param_2);
        mainlink_renc_event(&DAT_208d9c0f);
        return;
      }
      if (gui_frame.cmd != 0x43 && gui_frame.cmd != 0x70) {
        return;
      }
    }
  }
switchD_2015fb98_caseD_5:
  FUN_20113de0(2,(int)-cVar1,param_3,param_2);
  mainlink_renc_event(&DAT_208d9c0a);
  return;
}


// ===== FUN_2015fc80 @ 2015fc80 (64 bytes)

undefined2 FUN_2015fc80(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = (uint)gui_frame.payload[1] + (int)-*(short *)(param_4 + 0x22);
  if (-*(short *)(param_4 + 0x22) < 0) {
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else if (param_3 <= iVar1) {
    iVar1 = param_3 + -1;
  }
  return *(undefined2 *)(param_2 + iVar1 * 2);
}


// ===== mouse_cursor_obj_init @ 2015fcc4 (148 bytes)

/* cursor at (400,240), sem "mouse_cursor_sem" */

void mouse_cursor_obj_init(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  FUN_201644e4();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x28;
    FUN_201587d0(iVar3 + 4);
    FUN_20164524(param_1 + 0x504,uVar2 & 0xffff,iVar3 + 4);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
                    /* itron_acre_mbx with a zeroed T_CMBX [doc] */
  uVar1 = os_mbx_create_fifo(param_1);
  *(undefined4 *)(param_1 + 0x58c) = uVar1;
  *(undefined1 *)(param_1 + 0x590) = 0;
  *(undefined2 *)(param_1 + 0x592) = 400;
  *(undefined2 *)(param_1 + 0x594) = 0xf0;
  uVar2 = os_create_sem_named(&DAT_201656d4,0x204281dc);
  if (0 < (int)uVar2) {
    *(uint *)(param_1 + 0x598) = uVar2;
    itron_sig_sem();
    return;
  }
  return;
}


// ===== mouse_cursor_run @ 2015fd60 (500 bytes)

/* attach/detach/report loop: buttons -> pointer sources, dx/dy * speed */

void mouse_cursor_run(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iStack_10;
  undefined1 *puStack_c;
  undefined1 auStack_8 [8];
  
  do {
    do {
      while( true ) {
        while( true ) {
          itron_trcv_mbx(*(undefined4 *)(param_1 + 0x58c),&iStack_10,0xffffffff);
          cVar1 = *(char *)(iStack_10 + 4);
          if (cVar1 != '\0') break;
          *(undefined1 *)(param_1 + 0x590) = 0;
          r_vdc5_stop_process(0,6);
          r_vdc5_stop_process(1,6);
          mouse_set_up();
        }
        if (cVar1 != '\x01') break;
        *(undefined1 *)(param_1 + 0x590) = 1;
        auStack_8[0] = 3;
        puStack_c = auStack_8;
        r_vdc5_start_process(0,6,(uint)&puStack_c);
        r_vdc5_start_process(1,6,(uint)&puStack_c);
        mouse_cursor_move(param_1,400,0xf0);
      }
    } while (cVar1 != '\x02');
    if (DAT_20800496 == '\0' && DAT_20800495 == '\0') {
      if ((*(byte *)(iStack_10 + 0xe) & 1) == 0) {
        mouse_set_up();
      }
    }
    else {
      itron_twai_sem(*(undefined4 *)(param_1 + 0x598),0xffffffff);
      iVar2 = (int)*(short *)(iStack_10 + 0x12) * (DAT_20800328 + 0x96);
      uVar4 = (uint)(short)((((short)(iVar2 / 100) + (short)(iVar2 >> 0x1f)) -
                            (short)((longlong)iVar2 * 0x51eb851f >> 0x3f)) +
                           *(short *)(param_1 + 0x592));
      if ((int)uVar4 < 0) {
        uVar4 = 0;
      }
      else if (799 < (int)uVar4) {
        uVar4 = 799;
      }
      iVar2 = (int)*(short *)(iStack_10 + 0x14) * (DAT_20800328 + 0x96);
      uVar3 = (uint)(short)((((short)(iVar2 / 100) + (short)(iVar2 >> 0x1f)) -
                            (short)((longlong)iVar2 * 0x51eb851f >> 0x3f)) +
                           *(short *)(param_1 + 0x594));
      if ((int)uVar3 < 0) {
        uVar3 = 0;
      }
      else if (0x1df < (int)uVar3) {
        uVar3 = 0x1df;
      }
      itron_sig_sem(*(undefined4 *)(param_1 + 0x598));
      mouse_cursor_move(param_1,(ushort)uVar4,(ushort)uVar3);
      if ((*(byte *)(iStack_10 + 0xe) & 1) == 0) {
        mouse_set_up();
      }
      else {
        mouse_set_down(uVar4 & 0xffff,uVar3 & 0xffff);
      }
      if ((*(ushort *)(iStack_10 + 0xe) & 2) == 0) {
        if ((*(ushort *)(iStack_10 + 0xe) & 4) == 0) {
          mouse_right_up();
          mouse_middle_up();
        }
        else {
          mouse_middle_down();
        }
      }
      else {
        mouse_right_down();
      }
      if (((*(ushort *)(iStack_10 + 0x10) & 0x100) != 0) && (*(short *)(iStack_10 + 0x22) != 0)) {
        mouse_wheel_event(param_1);
      }
    }
  } while( true );
}


// ===== FUN_2015ff64 @ 2015ff64 (12 bytes)

void FUN_2015ff64(int param_1,undefined4 param_2)

{
  os_mbx_send(param_1,*(undefined4 *)(param_1 + 0x58c),param_2);
  return;
}


// ===== FUN_2015ff70 @ 2015ff70 (32 bytes)

int FUN_2015ff70(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428018;
  iVar1 = FUN_20162c20(param_1 + 0x141);
  return iVar1 + -0x504;
}


// ===== FUN_2015ff94 @ 2015ff94 (92 bytes)

void FUN_2015ff94(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x10) = param_2;
  FUN_20164414();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x88;
    msgbuf_init(iVar3 + 0x14);
    FUN_20164454(param_1 + 0x894,uVar2 & 0xffff,iVar3 + 0x14);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
                    /* itron_acre_mbx with a zeroed T_CMBX [doc] */
  uVar1 = os_mbx_create_fifo(param_1);
  *(undefined4 *)(param_1 + 0x8dc) = uVar1;
  return;
}


// ===== task_uart4_dispatch @ 2015fff0 (40 bytes)

/* only counts */

void task_uart4_dispatch(int param_1)

{
  undefined1 auStack_8 [8];
  
  do {
    itron_trcv_mbx(*(undefined4 *)(param_1 + 0x8dc),auStack_8,0xffffffff);
    *(int *)(param_1 + 0x8e0) = *(int *)(param_1 + 0x8e0) + 1;
  } while( true );
}


// ===== FUN_20160018 @ 20160018 (32 bytes)

int FUN_20160018(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428024;
  iVar1 = FUN_20162c10(param_1 + 0x225);
  return iVar1 + -0x894;
}


// ===== mainlink_disp_alloc @ 2016003c (12 bytes)

uint mainlink_disp_alloc(int param_1)

{
  uint uVar1;
  
  uVar1 = txpool_next_slot(param_1 + 0x8114);
  return uVar1;
}


// ===== mainlink_disp_init @ 20160048 (96 bytes)

/* 32 x 0x408 B pool + mailbox */

void mainlink_disp_init(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(uint *)(param_1 + 0x10) = param_2;
                    /* Creates the pool mutex [doc] */
  txpool_init_mutex();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x408;
    msgbuf_init(iVar3 + 0x14);
    txpool_set_slot(param_1 + 0x8114,uVar2 & 0xffff,iVar3 + 0x14);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
                    /* itron_acre_mbx with a zeroed T_CMBX [doc] */
  uVar1 = os_mbx_create_fifo(param_1);
  *(undefined4 *)(param_1 + 0x819c) = uVar1;
  return;
}


// ===== task_mainlink_dispatch @ 201600a8 (440 bytes)

/* task "uart" pri 4: ACK/NAK -> TX state; copies frames into the GUI snapshots
   0x2045F260/0x2045F8C0 */

void task_mainlink_dispatch(int param_1)

{
  byte bVar1;
  int iVar2;
  int aiStack_8 [2];
  
  do {
    itron_trcv_mbx(*(undefined4 *)(param_1 + 0x819c),aiStack_8,0xffffffff);
    *(int *)(param_1 + 0x81a0) = *(int *)(param_1 + 0x81a0) + 1;
    bVar1 = *(byte *)(aiStack_8[0] + 8);
    if (bVar1 == 0x21) {
                    /* 0x21: payload to 0x20450035 [fact: mainlink.md] */
      memcpy(&g_ml.last21,aiStack_8[0] + 9,*(ushort *)(aiStack_8[0] + 6) - 2);
      g_ml.got21 = 1;
    }
    else if (bVar1 < 0x22) {
      if (bVar1 == 6) {
        *(int *)(param_1 + 0x81a4) = *(int *)(param_1 + 0x81a4) + 1;
                    /* 0x06: ACK [fact: mainlink.md] */
        mainlink_audio_ack();
        mainlink_on_ack();
      }
      else if (bVar1 == 0x15) {
        *(int *)(param_1 + 0x81a8) = *(int *)(param_1 + 0x81a8) + 1;
                    /* 0x15: NAK [fact: mainlink.md] */
        mainlink_on_nak();
      }
      else if (bVar1 == 0x1b) {
        g_ml.got_esc = 1;
        *(int *)(param_1 + 0x81ac) = *(int *)(param_1 + 0x81ac) + 1;
      }
      else if (bVar1 == 0x20) {
        *(int *)(param_1 + 0x81b4) = *(int *)(param_1 + 0x81b4) + 1;
      }
    }
    else if (bVar1 == 0x23) {
      DAT_208084d4 = 1;
    }
    else if (bVar1 == 0x24) {
                    /* 0x24: display settings from +0x98 [fact: mainlink.md] */
      FUN_201636f8(g_ml.settings24,aiStack_8[0] + 0xa0);
      g_ml.got24 = 1;
    }
    else if (bVar1 == 0x43) {
      *(int *)(param_1 + 0x81b8) = *(int *)(param_1 + 0x81b8) + 1;
    }
    else if (bVar1 == 0x60) {
      g_ml.got60 = 1;
      __aeabi_memcpy4(&DAT_2045fb00,aiStack_8[0] + 8,*(undefined2 *)(aiStack_8[0] + 6));
                    /* Returns the radio-on flag 0x208003A0 [doc] */
      iVar2 = radio_on_flag_get();
      if (((iVar2 == 0) && (*(int *)(param_1 + 0x81b0) != 0)) && (DAT_2045fbb3 == '\x01')) {
                    /* 2nd 0x60 with 0xB3 = 1 while off: power on [fact: mainlink.md] */
        radio_on_flag_set(1);
      }
      *(int *)(param_1 + 0x81b0) = *(int *)(param_1 + 0x81b0) + 1;
    }
    g_ml.last_rx_cmd = *(byte *)(aiStack_8[0] + 8);
    if ((g_ml.last_rx_cmd != 6 && g_ml.last_rx_cmd != 0x15) && g_ml.last_rx_cmd != 0x1b) {
      __aeabi_memcpy4(&ml_rx_frame,aiStack_8[0] + 8,*(undefined2 *)(aiStack_8[0] + 6));
                    /* GUI snapshot of the frame (0x240 bytes) [fact: mainlink.md] */
      __aeabi_memcpy4(&ml_gui_snapshot,aiStack_8[0] + 8,*(undefined2 *)(aiStack_8[0] + 6));
    }
  } while( true );
}


// ===== mainlink_disp_post @ 20160278 (16 bytes)

void mainlink_disp_post(int param_1,undefined4 param_2)

{
  os_mbx_send(param_1,*(undefined4 *)(param_1 + 0x819c),param_2);
  return;
}


// ===== mainlink_disp_ctor @ 20160288 (32 bytes)

/* vtbl 0x20428030 */

int mainlink_disp_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_20428030;
  iVar1 = FUN_20162c18((int)param_1 + 0x8114);
  return iVar1 + -0x8114;
}


// ===== fwobj_sdr_run @ 201602ac (288 bytes)

/* vtbl[0]: size == 0x43075A, CRC check, then sdr_flash_write */

undefined4 fwobj_sdr_run(int param_1,uint param_2,int param_3)

{
  uint fs_fopen_ret;
  undefined4 uVar1;
  uint uVar2;
  int local_20;
  int local_1c;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  fs_fopen_ret = fs_fopen(param_2,0x204281ed);
  if (fs_fopen_ret == 0) {
    uVar1 = 1;
  }
  else {
                    /* progress percent 0x20800364 [doc, inference] */
    progress_set(5);
    itron_rot_rdq(0);
    fs_fsize(fs_fopen_ret,&local_1c);
    if (local_1c == 0x43075a) {
      itron_get_pri(0,&local_20);
      local_20 = local_20 + -1;
      itron_chg_pri(0);
      uVar2 = sfl_read_header(fs_fopen_ret,0);
      itron_chg_pri(0);
      if (param_3 == 0) {
        fs_fclose(fs_fopen_ret);
        if (uVar2 != 0) {
          return 2;
        }
      }
      else {
        gpio_p7_9_11(1);
        gpio_rx_reset(1);
        gpio_rx_update_off(1);
        uVar2 = sdr_flash_write(fs_fopen_ret,1,(uint)*(byte *)(param_1 + 0xab));
        fs_fclose(fs_fopen_ret);
        if (uVar2 == 0) {
          return 3;
        }
      }
      return 0;
    }
    fs_fclose(fs_fopen_ret);
    uVar1 = 2;
  }
  return uVar1;
}


// ===== fwobj_sdr_ctor @ 201603d4 (28 bytes)

/* SDR object, vtable 0x20428070, +0xAB flag */

uint fwobj_sdr_ctor(uint param_1,byte param_2)

{
  undefined4 *fwobj_base_ctor_ret;
  
                    /* base update-object constructor, vtable 0x2042807C [doc, inference] */
  fwobj_base_ctor_ret = (undefined4 *)fwobj_base_ctor((void *)param_1);
  *fwobj_base_ctor_ret = &DAT_20428070;
  *(byte *)((int)fwobj_base_ctor_ret + 0xab) = param_2;
  return (uint)fwobj_base_ctor_ret;
}


// ===== fwobj_build_path @ 201603f4 (20 bytes)

/* "%s%s" dir + file name */

void fwobj_build_path(int param_1,uint param_2)

{
  sprintf_veneer(param_1 + 0x58,&DAT_204281f0,param_2,param_1 + 0x37);
  return;
}


// ===== FUN_2016040c @ 2016040c (12 bytes)

void FUN_2016040c(int param_1)

{
  *(undefined1 *)(param_1 + 0x57) = 0;
  return;
}


// ===== fwobj_match_name @ 20160418 (132 bytes)

/* keeps the highest matching file name per object */

uint fwobj_match_name(int param_1,uint param_2,uint param_3)

{
  uint fwname_pattern_match_ret;
  int iVar1;
  uint uVar2;
  undefined1 auStack_30 [36];
  
  fwname_pattern_match_ret = fwname_pattern_match((int *)(param_1 + 0x14),param_2,param_3);
  uVar2 = 0;
  if (fwname_pattern_match_ret != 0) {
                    /* memcpy of 0x20 bytes, returns dst [doc] */
    copy32(auStack_30,param_2);
    if (*(char *)(param_1 + 0x57) == '\0') {
      memcpy(param_1 + 0x37,auStack_30,0x20);
      *(undefined1 *)(param_1 + 0x57) = 1;
    }
    else {
      iVar1 = strcasecmp(param_1 + 0x37,auStack_30);
      if (iVar1 < 1) {
        memcpy(param_1 + 0x37,auStack_30,0x20);
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


// ===== fwobj_set_status @ 2016049c (44 bytes)

/* status text (Ready, failed, ...) */

void fwobj_set_status(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 auStack_28 [32];
  
                    /* memcpy of 0x20 bytes, returns dst [doc] */
  uVar1 = copy32(auStack_28);
  memcpy(param_1 + 0x89,uVar1,0x20);
  return;
}


// ===== fwobj_version_from_name @ 201604c8 (20 bytes)

/* "0108" in the name -> "01-08" */

void fwobj_version_from_name(int param_1)

{
  FUN_20160c28(param_1 + 0xe,*(int *)(param_1 + 0x20) + param_1 + 0x37);
  return;
}


// ===== fwobj_select @ 201604dc (24 bytes)

/* marks the object selected for update */

void fwobj_select(int param_1,byte param_2)

{
  *(undefined1 *)(param_1 + 0xaa) = 0;
  *(byte *)(param_1 + 0x88) = param_2;
  *(undefined1 *)(param_1 + 0xa9) = 1;
  return;
}


// ===== fwobj_base_ctor @ 201604f4 (88 bytes)

/* base update-object constructor, vtable 0x2042807C */

int fwobj_base_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_2042807c;
                    /* memcpy of 10 bytes, returns dst [doc] */
  iVar1 = copy10((int)param_1 + 4,&DAT_20428430);
  iVar1 = FUN_20160c5c(iVar1 + 10,"-----");
  iVar1 = copy10(iVar1 + 0x1e,&DAT_20428430);
                    /* memcpy of 0x20 bytes, returns dst [doc] */
  iVar1 = copy32(iVar1 + 0xb,&DAT_20428430);
                    /* memcpy of 0x30 bytes, returns dst [doc] */
  iVar1 = copy48(iVar1 + 0x21,&DAT_20428430);
  iVar1 = copy32(iVar1 + 0x31,&DAT_20428430);
  return iVar1 + -0x89;
}


// ===== fwname_pattern_init @ 20160558 (80 bytes)

/* builds the name pattern (prefix, "NNNN", suffix) */

void fwname_pattern_init(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  param_1[1] = param_2;
  param_1[2] = param_3;
                    /* Word-at-a-time string length [doc] */
  iVar1 = strlen(param_2);
  param_1[3] = iVar1;
  iVar1 = strlen(param_3);
  param_1[5] = iVar1;
  iVar1 = strlen(&DAT_204281f5);
  param_1[4] = iVar1 + param_1[3];
  *param_1 = iVar1 + param_1[3] + param_1[5];
  return;
}


// ===== fwobj_main_run @ 201605ac (244 bytes)

/* vtbl[0]: CRC check, then RX boot mode entry + rx_boot_program */

undefined4 fwobj_main_run(int param_1,uint param_2,int param_3,int param_4)

{
  uint fs_fopen_ret;
  undefined4 uVar1;
  uint sfl_read_header_ret;
  int iVar2;
  int local_18;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  local_18 = param_4;
  fs_fopen_ret = fs_fopen(param_2,0x204281fa);
  if (fs_fopen_ret == 0) {
    uVar1 = 1;
  }
  else {
                    /* progress percent 0x20800364 [doc, inference] */
    progress_set(5);
    itron_rot_rdq(0);
    itron_get_pri(0,&local_18);
    local_18 = local_18 + -1;
    itron_chg_pri(0);
    sfl_read_header_ret = sfl_read_header(fs_fopen_ret,0);
    itron_chg_pri(0);
    if (param_3 == 0) {
      fs_fclose(fs_fopen_ret);
      if (sfl_read_header_ret != 0) {
        return 2;
      }
    }
    else {
      mainlink_rx_ctrl(1);
      gpio_rx_reset(0);
      gpio_rx_update_b(1);
      itron_dly_tsk(5);
      gpio_rx_reset(1);
      itron_dly_tsk(0x28);
      iVar2 = rx_boot_program(fs_fopen_ret,1);
      fs_fclose(fs_fopen_ret);
      if (iVar2 == 0) {
        return 3;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fwobj_main_ctor @ 201606a4 (20 bytes)

/* MAIN object, vtable 0x20428088 */

uint fwobj_main_ctor(uint param_1)

{
  undefined4 *fwobj_base_ctor_ret;
  
                    /* base update-object constructor, vtable 0x2042807C [doc, inference] */
  fwobj_base_ctor_ret = (undefined4 *)fwobj_base_ctor((void *)param_1);
  *fwobj_base_ctor_ret = &DAT_20428088;
  return (uint)fwobj_base_ctor_ret;
}


// ===== fwobj_ifdsp_run @ 201606bc (264 bytes)

/* vtbl[0]: CRC check, then dsp_isp_program */

undefined4 fwobj_ifdsp_run(int param_1,uint param_2,int param_3)

{
  uint fs_fopen_ret;
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  fs_fopen_ret = fs_fopen(param_2,0x204281fd);
  if (fs_fopen_ret == 0) {
    uVar1 = 1;
  }
  else {
                    /* progress percent 0x20800364 [doc, inference] */
    progress_set(5);
    itron_rot_rdq(0);
    itron_get_pri(0,&stack0xffffffd8);
    itron_chg_pri(0);
    uVar2 = sfl_read_header(fs_fopen_ret,0);
    itron_chg_pri(0);
    if (param_3 == 0) {
      fs_fclose(fs_fopen_ret);
      if (uVar2 != 0) {
        return 2;
      }
    }
    else {
      gpio_p7_9_11(1);
      gpio_rx_reset(1);
      uVar2 = dsp_isp_program(fs_fopen_ret,1,0,0,(uint)*(byte *)(param_1 + 0xab));
      fs_fclose(fs_fopen_ret);
      if (uVar2 == 0) {
        return 3;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

