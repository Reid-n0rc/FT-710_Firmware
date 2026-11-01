// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== fwdbg_verify_bank1 @ 2015f1f0 (332 bytes)

/* fw1chk: compares a file with bank 1 (0x18400000), forever (was display_flash_write_bank) */

undefined4 fwdbg_verify_bank1(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  uint n;
  ulonglong uVar7;
  
  iVar1 = DAT_208001c4;
  DAT_208001c0 = DAT_208001c0 + 1;
  uVar2 = fs_fopen(param_2,0x204281a4);
  if (uVar2 == 0) {
    uVar3 = 3;
  }
  else {
    kbd_led_status(3,7);
    itron_dly_tsk(10);
    itron_dly_tsk(10);
    kbd_led_status(4,7);
    pcVar6 = FUN_18400000;
    n = 0;
    do {
      uVar4 = fs_fread(param_1 + 4,1,0x100,uVar2);
      if (uVar4 == 0) break;
      n = n + 1;
      uVar7 = __aeabi_idivmod(n,100);
      if ((int)(uVar7 >> 0x20) == 0) {
        itron_dly_tsk(10);
      }
      iVar5 = memcmp(param_1 + 4,pcVar6,uVar4);
      if (iVar5 != 0) {
        DAT_208001c4 = DAT_208001c4 + 1;
      }
      pcVar6 = pcVar6 + 0x100;
    } while (uVar4 != 0);
    fs_fclose(uVar2);
    if (iVar1 == DAT_208001c4) {
      uVar3 = 0;
    }
    else {
      uVar3 = 3;
    }
  }
  return uVar3;
}


// ===== fwdbg_write_other_bank @ 2015f348 (512 bytes)

/* fw1up: raw I:\AH076H_DISPLAY.bin to the non-running bank + flag */

undefined4 fwdbg_write_other_bank(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
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
      puVar5 = &g_bootinfo.bank2_flag;
      puVar6 = &g_bootinfo.bank1_flag;
    }
    else if (g_bootinfo.bank == 2) {
      puVar5 = &g_bootinfo.bank1_flag;
      puVar6 = &g_bootinfo.bank2_flag;
    }
    else {
      puVar5 = &g_bootinfo.bank1_flag;
      puVar6 = &g_bootinfo.bank2_flag;
    }
    uVar7 = puVar5[1];
    kbd_led_status(3,7);
    uVar3 = spiflash_erase(0,*puVar5,0x14);
    if (uVar3 == 0) {
      uVar3 = spiflash_erase(0,puVar5[1],local_30);
      if (uVar3 == 0) {
        kbd_led_status(4,7);
        local_48 = 0xffffffff;
        crc32_make_table();
        do {
          uVar3 = fs_fread(param_1 + 4,1,0x100,uVar1);
          if (uVar3 == 0) break;
          uVar4 = spiflash_write(uVar7,param_1 + 4,uVar3);
          if (uVar4 != 0) {
            fs_fclose(uVar1);
            return 3;
          }
          local_48 = crc32_update(local_48,uVar3,param_1 + 4);
          uVar7 = uVar7 + 0x100;
        } while (uVar3 != 0);
        fs_fclose(uVar1);
        local_44 = 0x11111111;
        local_34 = ~local_48;
        local_40 = local_30;
        uVar1 = spiflash_write(*puVar5,(uint)&local_44,0x14);
        if (uVar1 == 0) {
          uVar1 = spiflash_erase(0,*puVar6,0x14);
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
  txpool_init_mutex();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x408;
    msgbuf_init(iVar3 + 0x14);
    txpool_set_slot(param_1 + 0x8114,uVar2 & 0xffff,iVar3 + 0x14);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
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
      memcpy(&g_ml.last21,aiStack_8[0] + 9,*(ushort *)(aiStack_8[0] + 6) - 2);
      g_ml.got21 = 1;
    }
    else if (bVar1 < 0x22) {
      if (bVar1 == 6) {
        *(int *)(param_1 + 0x81a4) = *(int *)(param_1 + 0x81a4) + 1;
        mainlink_audio_ack();
        mainlink_on_ack();
      }
      else if (bVar1 == 0x15) {
        *(int *)(param_1 + 0x81a8) = *(int *)(param_1 + 0x81a8) + 1;
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
      FUN_201636f8(g_ml.settings24,aiStack_8[0] + 0xa0);
      g_ml.got24 = 1;
    }
    else if (bVar1 == 0x43) {
      *(int *)(param_1 + 0x81b8) = *(int *)(param_1 + 0x81b8) + 1;
    }
    else if (bVar1 == 0x60) {
      g_ml.got60 = 1;
      __aeabi_memcpy4(&DAT_2045fb00,aiStack_8[0] + 8,*(undefined2 *)(aiStack_8[0] + 6));
      iVar2 = radio_on_flag_get();
      if (((iVar2 == 0) && (*(int *)(param_1 + 0x81b0) != 0)) && (DAT_2045fbb3 == '\x01')) {
        radio_on_flag_set(1);
      }
      *(int *)(param_1 + 0x81b0) = *(int *)(param_1 + 0x81b0) + 1;
    }
    g_ml.last_rx_cmd = *(byte *)(aiStack_8[0] + 8);
    if ((g_ml.last_rx_cmd != 6 && g_ml.last_rx_cmd != 0x15) && g_ml.last_rx_cmd != 0x1b) {
      __aeabi_memcpy4(&ml_rx_frame,aiStack_8[0] + 8,*(undefined2 *)(aiStack_8[0] + 6));
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
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_20;
  int local_1c;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  uVar1 = fs_fopen(param_2,0x204281ed);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else {
    progress_set(5);
    itron_rot_rdq(0);
    fs_fsize(uVar1,&local_1c);
    if (local_1c == 0x43075a) {
      itron_get_pri(0,&local_20);
      local_20 = local_20 + -1;
      itron_chg_pri(0);
      uVar3 = sfl_read_header(uVar1,0);
      itron_chg_pri(0);
      if (param_3 == 0) {
        fs_fclose(uVar1);
        if (uVar3 != 0) {
          return 2;
        }
      }
      else {
        gpio_p7_9_11(1);
        gpio_rx_reset(1);
        gpio_rx_update_off(1);
        uVar3 = sdr_flash_write(uVar1,1,(uint)*(byte *)(param_1 + 0xab));
        fs_fclose(uVar1);
        if (uVar3 == 0) {
          return 3;
        }
      }
      return 0;
    }
    fs_fclose(uVar1);
    uVar2 = 2;
  }
  return uVar2;
}


// ===== fwobj_sdr_ctor @ 201603d4 (28 bytes)

/* SDR object, vtable 0x20428070, +0xAB flag */

uint fwobj_sdr_ctor(uint param_1,byte param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)fwobj_base_ctor((void *)param_1);
  *puVar1 = &DAT_20428070;
  *(byte *)((int)puVar1 + 0xab) = param_2;
  return (uint)puVar1;
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
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_30 [36];
  
  uVar1 = fwname_pattern_match((int *)(param_1 + 0x14),param_2,param_3);
  uVar3 = 0;
  if (uVar1 != 0) {
    copy32(auStack_30,param_2);
    if (*(char *)(param_1 + 0x57) == '\0') {
      memcpy(param_1 + 0x37,auStack_30,0x20);
      *(undefined1 *)(param_1 + 0x57) = 1;
    }
    else {
      iVar2 = strcasecmp(param_1 + 0x37,auStack_30);
      if (iVar2 < 1) {
        memcpy(param_1 + 0x37,auStack_30,0x20);
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}


// ===== fwobj_set_status @ 2016049c (44 bytes)

/* status text (Ready, failed, ...) */

void fwobj_set_status(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 auStack_28 [32];
  
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
  iVar1 = copy10((int)param_1 + 4,&DAT_20428430);
  iVar1 = FUN_20160c5c(iVar1 + 10,"-----");
  iVar1 = copy10(iVar1 + 0x1e,&DAT_20428430);
  iVar1 = copy32(iVar1 + 0xb,&DAT_20428430);
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
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int local_18;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  local_18 = param_4;
  uVar1 = fs_fopen(param_2,0x204281fa);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else {
    progress_set(5);
    itron_rot_rdq(0);
    itron_get_pri(0,&local_18);
    local_18 = local_18 + -1;
    itron_chg_pri(0);
    uVar3 = sfl_read_header(uVar1,0);
    itron_chg_pri(0);
    if (param_3 == 0) {
      fs_fclose(uVar1);
      if (uVar3 != 0) {
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
      iVar4 = rx_boot_program(uVar1,1);
      fs_fclose(uVar1);
      if (iVar4 == 0) {
        return 3;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== fwobj_main_ctor @ 201606a4 (20 bytes)

/* MAIN object, vtable 0x20428088 */

uint fwobj_main_ctor(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)fwobj_base_ctor((void *)param_1);
  *puVar1 = &DAT_20428088;
  return (uint)puVar1;
}


// ===== fwobj_ifdsp_run @ 201606bc (264 bytes)

/* vtbl[0]: CRC check, then dsp_isp_program */

undefined4 fwobj_ifdsp_run(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  uVar1 = fs_fopen(param_2,0x204281fd);
  if (uVar1 == 0) {
    uVar2 = 1;
  }
  else {
    progress_set(5);
    itron_rot_rdq(0);
    itron_get_pri(0,&stack0xffffffd8);
    itron_chg_pri(0);
    uVar3 = sfl_read_header(uVar1,0);
    itron_chg_pri(0);
    if (param_3 == 0) {
      fs_fclose(uVar1);
      if (uVar3 != 0) {
        return 2;
      }
    }
    else {
      gpio_p7_9_11(1);
      gpio_rx_reset(1);
      uVar3 = dsp_isp_program(uVar1,1,0,0,(uint)*(byte *)(param_1 + 0xab));
      fs_fclose(uVar1);
      if (uVar3 == 0) {
        return 3;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== fwobj_ifdsp_ctor @ 201607c8 (28 bytes)

/* IFDSP object, vtable 0x20428094, +0xAB flag */

uint fwobj_ifdsp_ctor(uint param_1,byte param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)fwobj_base_ctor((void *)param_1);
  *puVar1 = &DAT_20428094;
  *(byte *)((int)puVar1 + 0xab) = param_2;
  return (uint)puVar1;
}


// ===== fwobj_display_run @ 201607e8 (1032 bytes)

/* vtbl[0]: CRC check, then decoded write to the other bank (or loader) + flag */

undefined4 fwobj_display_run(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint *unaff_r10;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined1 auStack_d0 [68];
  undefined4 local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  undefined1 auStack_70 [4];
  uint local_6c;
  undefined1 auStack_68 [24];
  uint local_50;
  uint local_4c;
  undefined1 auStack_48 [8];
  uint local_40;
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [12];
  
  bVar1 = false;
  __aeabi_memclr4(auStack_d0,0x44);
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  local_78 = fs_fopen(param_2,0x20428200);
  if (local_78 == 0) {
    return 1;
  }
  itron_get_pri(0,&local_74);
  local_74 = local_74 + -1;
  itron_chg_pri(0);
  uVar2 = sfl_read_header(local_78,(int)auStack_d0);
  itron_chg_pri(0);
  if (DAT_20800181 == ':') {
    unaff_r10 = (uint *)&DAT_20428203;
    iVar3 = strstr(auStack_d0,&DAT_20428203);
    if (iVar3 != 0) {
      iVar4 = strlen(&DAT_20428203);
      iVar3 = iVar3 + iVar4;
      *(undefined1 *)(iVar3 + 8) = 0;
      iVar4 = memcmp("#UP0    ",iVar3,8);
      if (iVar4 == 0) {
        uVar5 = copy10(auStack_3c,iVar3);
        memcpy(param_1 + 4,uVar5,10);
        uVar5 = copy10(auStack_30,&DAT_20428210);
        memcpy(param_1 + 0x2c,uVar5,10);
        bVar1 = true;
      }
    }
  }
  if (param_3 == 0) {
    fs_fclose(local_78);
    if (uVar2 == 0) {
      return 0;
    }
    return 2;
  }
  uVar2 = mainlink_fw_mode_cmd('\x03');
  if (uVar2 == 0) {
    return 3;
  }
  gpio_p7_9_11(1);
  gpio_rx_reset(1);
  gpio_rx_update_off(1);
  local_50 = work_buf_get(0x100);
  progress_range_init(auStack_70,5,0x1e);
  uVar2 = 0;
  iVar3 = 0;
  fs_fsize(local_78,&local_40);
  if (local_40 < 0x242) {
    return 3;
  }
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_74 = local_40 - 0x240;
  if (g_bootinfo.bank == 1) {
    puVar8 = &g_bootinfo.bank2_flag;
    unaff_r10 = &g_bootinfo.bank1_flag;
  }
  else {
    puVar8 = &g_bootinfo.bank1_flag;
  }
  uVar9 = puVar8[1];
  if (g_bootinfo.bank != 1) {
    unaff_r10 = &g_bootinfo.bank2_flag;
  }
  sfl_stream_init(auStack_68,local_78,0,1);
  uVar6 = progress_scale(auStack_70);
  progress_set(uVar6);
  if (g_bootinfo.mode == 2) {
    bVar1 = true;
LAB_201609ec:
    uVar9 = 0;
    uVar6 = spiflash_erase(0,0x3c0000,0x14);
    if (uVar6 != 0) goto LAB_20160ac8;
    uVar6 = spiflash_erase((int)auStack_70,0,local_74);
  }
  else {
    if (bVar1) goto LAB_201609ec;
    uVar6 = spiflash_erase(0,*puVar8,0x14);
    if (uVar6 != 0) goto LAB_20160ac8;
    uVar6 = spiflash_erase((int)auStack_70,puVar8[1],local_74);
  }
  if (uVar6 == 0) {
    progress_range_init(auStack_48,local_6c,99);
    local_4c = 0xffffffff;
    crc32_make_table();
    while( true ) {
      uVar6 = sfl_stream_read(local_50,1,0x100,(int)auStack_68);
      if (uVar6 == 0) {
        progress_set(100);
        fs_fclose(local_78);
        if (local_74 != iVar3) {
          return 3;
        }
        local_8c = 0x11111111;
        local_7c = ~local_4c;
        local_88 = local_74;
        if (bVar1) {
          uVar2 = spiflash_write(0x3c0000,(uint)&local_8c,0x14);
        }
        else {
          uVar2 = spiflash_write(*puVar8,(uint)&local_8c,0x14);
          if (uVar2 != 0) {
            return 3;
          }
          uVar2 = spiflash_erase(0,*unaff_r10,0x14);
        }
        if (uVar2 == 0) {
          uVar2 = mainlink_fw_mode_cmd(-0x7d);
          if (uVar2 != 0) {
            return 0;
          }
          return 3;
        }
        return 3;
      }
      uVar7 = spiflash_write(uVar9,local_50,uVar6);
      if (uVar7 != 0) break;
      local_4c = crc32_update(local_4c,uVar6,local_50);
      iVar3 = iVar3 + uVar6;
      uVar9 = uVar9 + 0x100;
      uVar10 = __aeabi_ui2d(local_74);
      uVar11 = __aeabi_ui2d(iVar3);
      uVar10 = __aeabi_ddiv((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar10,
                            (int)((ulonglong)uVar10 >> 0x20));
      uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar6 = progress_scale(auStack_48,uVar5,(int)uVar10,uVar5);
      progress_set(uVar6);
      if ((uVar2 & 0xf) == 0) {
        itron_rot_rdq(0);
      }
      uVar2 = uVar2 + 1;
    }
  }
LAB_20160ac8:
  fs_fclose(local_78);
  return 3;
}


// ===== fwobj_display_ctor @ 20160c10 (20 bytes)

/* DISPLAY object, vtable 0x204280A0 */

uint fwobj_display_ctor(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)fwobj_base_ctor((void *)param_1);
  *puVar1 = &DAT_204280a0;
  return (uint)puVar1;
}


// ===== FUN_20160c28 @ 20160c28 (52 bytes)

void FUN_20160c28(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = 0x2d;
  param_1[3] = param_2[2];
  param_1[4] = param_2[3];
  param_1[5] = 0;
  return;
}


// ===== FUN_20160c5c @ 20160c5c (20 bytes)

undefined4 FUN_20160c5c(undefined4 param_1)

{
  FUN_20160c28();
  return param_1;
}


// ===== afscope_map0_init @ 20160c70 (124 bytes)

/* Map 0 (obj +0x000): levels 0x81..0xFA -> (i - 0x81) * 0.3223 + 0.99 pixels, below 0, from 0xFB on
   0x27 (39, the AF-FFT spectrum height of gui.md) [fact] */

void afscope_map0_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    *(undefined1 *)(param_1 + iVar1) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  iVar1 = 0x81;
  do {
    if (iVar1 + -0x81 < 1) {
      *(undefined1 *)(param_1 + iVar1) = 0;
    }
    else {
      iVar2 = (iVar1 + -0x81) * 0xc97 + 0x26ac;
      *(char *)(param_1 + iVar1) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xfb);
  iVar1 = 0xfb;
  do {
    *(undefined1 *)(param_1 + iVar1) = 0x27;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return;
}


// ===== afscope_map2_init @ 20160cf0 (92 bytes)

/* Map 2 (obj +0x200): level i -> i * 0.3098 + 0.85 for 1..255 [fact] */

void afscope_map2_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    *(undefined1 *)(param_1 + iVar1 + 0x200) = 0;
    while( true ) {
      iVar1 = iVar1 + 1;
      if (0xff < iVar1) {
        return;
      }
      if (iVar1 < 1) break;
      iVar2 = iVar1 * 0xc1a + 0x2134;
      *(char *)(param_1 + iVar1 + 0x200) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
  } while( true );
}


// ===== afscope_map1_init @ 20160d50 (144 bytes)

/* Map 1 (obj +0x100): the same curve as map 0 [fact] */

void afscope_map1_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x100) = 0;
  } while (iVar1 < 0x100);
  iVar1 = 0x81;
  do {
    if (iVar1 + -0x81 < 1) {
      *(undefined1 *)(param_1 + iVar1 + 0x100) = 0;
    }
    else {
      iVar2 = (iVar1 + -0x81) * 0xc97 + 0x26ac;
      *(char *)(param_1 + iVar1 + 0x100) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xfb);
  iVar1 = 0xfb;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x100) = 0x27;
  } while (iVar1 < 0x100);
  return;
}


// ===== afscope_map3_init @ 20160de4 (92 bytes)

/* Map 3 (obj +0x300): the same curve as map 2 [fact] */

void afscope_map3_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    *(undefined1 *)(param_1 + iVar1 + 0x300) = 0;
    while( true ) {
      iVar1 = iVar1 + 1;
      if (0xff < iVar1) {
        return;
      }
      if (iVar1 < 1) break;
      iVar2 = iVar1 * 0xc1a + 0x2134;
      *(char *)(param_1 + iVar1 + 0x300) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
  } while( true );
}


// ===== afscope_map4_init @ 20160e44 (144 bytes)

/* Map 4 (obj +0x400): levels 0x81..0xFA -> (i - 0x81) * 0.3636 + 0.99, from 0xFB on 0x2C (44, the
   bar height affft_bins_get returns) [fact] */

void afscope_map4_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x400) = 0;
  } while (iVar1 < 0x100);
  iVar1 = 0x81;
  do {
    if (iVar1 + -0x81 < 1) {
      *(undefined1 *)(param_1 + iVar1 + 0x400) = 0;
    }
    else {
      iVar2 = (iVar1 + -0x81) * 0xe34 + 0x26ac;
      *(char *)(param_1 + iVar1 + 0x400) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xfb);
  iVar1 = 0xfb;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x400) = 0x2c;
  } while (iVar1 < 0x100);
  return;
}


// ===== mainlink_send_sd_absent @ 20160ed8 (52 bytes)

/* E2 frame with byte 1 = 0 (SD card not present, mainlink.md); the SD menu screens send it when
   sd_state_bit7 reads 0 [inference] */

void mainlink_send_sd_absent(void)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  local_10 = 0xe2;
  mainlink_queue_frame(&local_10,6);
  return;
}


// ===== FUN_20161bb0 @ 20161bb0 (52 bytes)

void FUN_20161bb0(void)

{
  undefined1 auStack_10 [12];
  
  touch_set_up();
  mouse_set_up();
  mainlink_send_touch_key(0,0xffff);
  pointer_get_event(auStack_10,1);
  return;
}


// ===== FUN_20162b50 @ 20162b50 (176 bytes)

void FUN_20162b50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0xf;
  } while (iVar2 < 0x100);
  iVar2 = 0x81;
  do {
    if (iVar2 + -0x81 < 1) {
      *(undefined2 *)(param_1 + iVar2 * 2) = 0xf;
    }
    else {
      *(undefined2 *)(param_1 + iVar2 * 2) =
           *(undefined2 *)(&UNK_20166da8 + (0x20 - ((iVar2 + -0x81) * 0xa54 + 0x26ac) / 10000) * 2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xfb);
  iVar2 = 0xfb;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0xffff;
  } while (iVar2 < 0x100);
  return;
}


// ===== FUN_20162c10 @ 20162c10 (16 bytes)

void FUN_20162c10(undefined2 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== FUN_20162c18 @ 20162c18 (8 bytes)

void FUN_20162c18(undefined4 param_1)

{
  FUN_2016440c(param_1,0);
  return;
}


// ===== FUN_20162c20 @ 20162c20 (8 bytes)

void FUN_20162c20(undefined4 param_1)

{
  FUN_2016440c(param_1,0);
  return;
}


// ===== FUN_20162c28 @ 20162c28 (212 bytes)

void FUN_20162c28(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0;
  } while (iVar3 < 0x100);
  uVar6 = (uint)*(byte *)(param_1 + 0x200);
  uVar4 = (uint)*(byte *)(param_1 + 0x201);
  iVar3 = *(int *)(param_2 + 4);
  if (uVar6 <= uVar4) {
    do {
      bVar2 = *(byte *)(param_1 + 0x200);
      uVar7 = __aeabi_idivmod(640000,(uVar4 - bVar2) + 1);
      iVar5 = uVar6 - bVar2;
      iVar1 = uVar6 * 2;
      uVar6 = uVar6 + 1;
      *(undefined2 *)(param_1 + iVar1) =
           *(undefined2 *)
            (iVar3 + ((uint)*(ushort *)(param_2 + 2) - ((int)uVar7 * (iVar5 + 1) + 0x26ac) / 10000)
                     * 2);
      uVar4 = (uint)*(byte *)(param_1 + 0x201);
    } while ((int)uVar6 <= (int)uVar4);
  }
  uVar4 = uVar4 + 1;
  if (uVar4 < 0x100) {
    do {
      iVar1 = uVar4 * 2;
      uVar4 = uVar4 + 1;
      *(undefined2 *)(param_1 + iVar1) =
           *(undefined2 *)(iVar3 + (uint)*(ushort *)(param_2 + 2) * 2 + -0x80);
    } while ((int)uVar4 < 0x100);
  }
  return;
}

