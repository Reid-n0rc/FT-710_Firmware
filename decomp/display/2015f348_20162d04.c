// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== fwdbg_write_other_bank @ 2015f348 (512 bytes)

/* fw1up: raw I:\AH076H_DISPLAY.bin to the non-running bank + flag */

undefined4 fwdbg_write_other_bank(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  int iStack_2c;
  undefined4 local_28;
  
  iStack_2c = param_1;
  local_28 = param_2;
  iVar1 = fs_fopen(param_2,&DAT_204281a6);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    thunk_FUN_2014af64(iVar1,&local_30);
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    if (DAT_208dbb44 == 1) {
      puVar5 = &DAT_208dbb84;
      puVar6 = &DAT_208dbb64;
    }
    else if (DAT_208dbb44 == 2) {
      puVar5 = &DAT_208dbb64;
      puVar6 = &DAT_208dbb84;
    }
    else {
      puVar5 = &DAT_208dbb64;
      puVar6 = &DAT_208dbb84;
    }
    iVar7 = puVar5[1];
    kbd_led_status(3,7);
    iVar3 = spiflash_erase(0,*puVar5,0x14);
    if (iVar3 == 0) {
      iVar3 = spiflash_erase(0,puVar5[1],local_30);
      if (iVar3 == 0) {
        kbd_led_status(4,7);
        local_48 = 0xffffffff;
        crc32_make_table();
        do {
          iVar3 = fs_fread(param_1 + 4,1,0x100,iVar1);
          if (iVar3 == 0) break;
          iVar4 = spiflash_write(iVar7,param_1 + 4,iVar3);
          if (iVar4 != 0) {
            FUN_20141ff0(iVar1);
            return 3;
          }
          local_48 = crc32_update(local_48,iVar3,param_1 + 4);
          iVar7 = iVar7 + 0x100;
        } while (iVar3 != 0);
        FUN_20141ff0(iVar1);
        local_44 = 0x11111111;
        local_34 = ~local_48;
        local_40 = local_30;
        iVar1 = spiflash_write(*puVar5,&local_44,0x14);
        if (iVar1 == 0) {
          iVar1 = spiflash_erase(0,*puVar6,0x14);
          if (iVar1 == 0) {
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
        FUN_20141ff0(iVar1);
        uVar2 = 3;
      }
    }
    else {
      FUN_20141ff0(iVar1);
      uVar2 = 3;
    }
  }
  return uVar2;
}


// ===== fwdbg_task_create @ 2015f55c (200 bytes)

/* event flag + task (entry 0x2015F0E0, pri 5, stack 0x2000) */

undefined4 fwdbg_task_create(int *param_1)

{
  int iVar1;
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
  iVar1 = itron_acre_flg(0,&local_38);
  *param_1 = iVar1;
  if (*param_1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = itron_acre_tsk(0,&local_2c);
    if (iVar1 < 1) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar1 = itron_sta_tsk(iVar1,param_1);
      if (iVar1 == 0) {
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

void update_display_self(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  int local_4c;
  undefined1 auStack_48 [52];
  int local_14;
  char *local_10;
  undefined4 local_c;
  uint local_8 [2];
  
LAB_2015f638:
  do {
    local_68 = 0xffffffff;
    local_c = itron_twai_flg(*param_1,0xffff,5,local_8);
    iVar8 = 0;
    iVar6 = 0;
    if ((local_8[0] & 1) == 0) {
      if ((local_8[0] & 2) == 0) {
        if ((local_8[0] & 4) != 0) {
          iVar6 = 0xa00000;
          iVar8 = 0x3f0000;
        }
      }
      else {
        iVar6 = 0x400000;
        iVar8 = 0x3e0000;
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
        local_4c = FUN_2014aec8(local_10,auStack_48);
      } while ((local_4c != 0) || (iVar2 = fs_fopen(local_10,&DAT_204281da), iVar2 == 0));
      kbd_led_status(2,7);
      iVar7 = 0;
      do {
        iVar3 = fs_fread(param_1 + 1,1,0x100,iVar2);
        iVar7 = iVar7 + iVar3;
      } while (iVar3 != 0);
      if (local_14 != iVar7) goto LAB_2015f638;
      FUN_20141ff0(iVar2);
      if (local_8[0] == 0x1001) {
        local_58 = fwdbg_write_other_bank(param_1,local_10);
        if (local_58 == 0) {
          kbd_led_status(7);
        }
        else {
          kbd_led_status(5,7);
        }
        goto LAB_2015f638;
      }
      if (local_8[0] == 0x3001) {
        do {
          local_58 = fwdbg_verify_bank1(param_1,local_10);
          if (local_58 == 0) {
            kbd_led_status(7);
          }
          else {
            kbd_led_status(5,7);
          }
          itron_dly_tsk(0x32);
        } while( true );
      }
      kbd_led_status(3,7);
      if ((((iVar8 != 0) || ((local_8[0] & 0x1000) != 0)) &&
          ((iVar2 = spiflash_erase(0,0x3e0000,0x14), iVar2 != 0 ||
           (iVar2 = spiflash_erase(0,0x3f0000,0x14), iVar2 != 0)))) ||
         (iVar2 = spiflash_erase(0,iVar6,iVar7), iVar2 != 0)) goto LAB_2015f638;
      kbd_led_status(4,7);
      iVar2 = fs_fopen(local_10,&DAT_204281da);
    } while (iVar2 == 0);
    bVar1 = false;
    local_50 = 0;
    local_54 = 0xffffffff;
    crc32_make_table();
    do {
      uVar4 = fs_fread(param_1 + 1,1,0x100,iVar2);
      if (uVar4 == 0) break;
      for (uVar5 = 0; uVar5 < uVar4; uVar5 = uVar5 + 1) {
        local_50 = (uint)*(byte *)((int)param_1 + uVar5 + 4) + (local_50 & 0xff) & 0xff;
      }
      local_54 = crc32_update(local_54,uVar4,param_1 + 1);
      iVar3 = spiflash_write(iVar6,param_1 + 1,uVar4);
      if (iVar3 != 0) {
        bVar1 = false;
        break;
      }
      iVar6 = iVar6 + 0x100;
      bVar1 = true;
    } while (uVar4 != 0);
    FUN_20141ff0(iVar2);
    if ((bVar1) && (iVar8 != 0)) {
      local_60 = 0;
      local_5c = 0;
      local_68 = 0x11111111;
      local_58 = ~local_54;
      local_64 = iVar7;
      iVar6 = spiflash_write(iVar8,&local_68,0x14);
      if (iVar6 != 0) {
        bVar1 = false;
      }
    }
    if (bVar1) {
      kbd_led_status(7);
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
  FUN_201571b8(&uStack_10,*(undefined4 *)(param_1 + 0x588),1);
  iVar1 = FUN_201643f0(param_1 + 0x504);
  uVar2 = *(undefined4 *)(param_1 + 0x504 + iVar1 * 4 + 4);
  FUN_201571d4(&uStack_10);
  return uVar2;
}


// ===== mouse_cursor_move @ 2015fa54 (52 bytes)

void mouse_cursor_move(int param_1,undefined2 param_2,undefined2 param_3)

{
  FUN_20152bb0(*(undefined4 *)(param_1 + 0x598),0xffffffff);
  *(undefined2 *)(param_1 + 0x592) = param_2;
  *(undefined2 *)(param_1 + 0x594) = param_3;
  FUN_201511e8(*(undefined4 *)(param_1 + 0x598));
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
  if (DAT_208f0b2a != 0x3a) {
    if (DAT_208f0b2a < 0x3b) {
      if (DAT_208f0b2a == 0x20) {
        FUN_20113de0(6,(int)cVar1,param_3,param_2);
        mainlink_renc_event(&DAT_208d9c1e);
        return;
      }
      if (DAT_208f0b2a == 0x30) {
        switch(DAT_208f0bc2) {
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
      else if (DAT_208f0b2a == 0x34 || DAT_208f0b2a == 0x37) goto switchD_2015fb98_caseD_5;
      return;
    }
    if (DAT_208f0b2a == 0x40) {
      if ((DAT_208f0bc5 & 0xf) == 3) {
        FUN_20113de0(2,(int)cVar1,param_3,param_2);
        mainlink_renc_event(&DAT_208d9c0a);
        return;
      }
    }
    else {
      if (DAT_208f0b2a == 0x41) {
        FUN_20113de0(3,(int)-cVar1,param_3,param_2);
        mainlink_renc_event(&DAT_208d9c0f);
        return;
      }
      if (DAT_208f0b2a != 0x43 && DAT_208f0b2a != 0x70) {
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
  
  iVar1 = (uint)DAT_208f0bc3 + (int)-*(short *)(param_4 + 0x22);
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
  uVar1 = FUN_20162d10(param_1);
  *(undefined4 *)(param_1 + 0x58c) = uVar1;
  *(undefined1 *)(param_1 + 0x590) = 0;
  *(undefined2 *)(param_1 + 0x592) = 400;
  *(undefined2 *)(param_1 + 0x594) = 0xf0;
  iVar3 = os_create_sem_named(&DAT_201656d4,"mouse_cursor_sem");
  if (0 < iVar3) {
    *(int *)(param_1 + 0x598) = iVar3;
    FUN_201511e8();
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
          FUN_20152434(*(undefined4 *)(param_1 + 0x58c),&iStack_10,0xffffffff);
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
        r_vdc5_start_process(0,6,&puStack_c);
        r_vdc5_start_process(1,6,&puStack_c);
        mouse_cursor_move(param_1,400,0xf0);
      }
    } while (cVar1 != '\x02');
    if (DAT_20800496 == '\0' && DAT_20800495 == '\0') {
      if ((*(byte *)(iStack_10 + 0xe) & 1) == 0) {
        mouse_set_up();
      }
    }
    else {
      FUN_20152bb0(*(undefined4 *)(param_1 + 0x598),0xffffffff);
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
      FUN_201511e8(*(undefined4 *)(param_1 + 0x598));
      mouse_cursor_move(param_1,uVar4 & 0xffff,uVar3 & 0xffff);
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
  FUN_20162d3c(param_1,*(undefined4 *)(param_1 + 0x58c),param_2);
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
    FUN_20158618(iVar3 + 0x14);
    FUN_20164454(param_1 + 0x894,uVar2 & 0xffff,iVar3 + 0x14);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x10);
  uVar1 = FUN_20162d10(param_1);
  *(undefined4 *)(param_1 + 0x8dc) = uVar1;
  return;
}


// ===== task_uart4_dispatch @ 2015fff0 (40 bytes)

/* only counts */

void task_uart4_dispatch(int param_1)

{
  undefined1 auStack_8 [8];
  
  do {
    FUN_20152434(*(undefined4 *)(param_1 + 0x8dc),auStack_8,0xffffffff);
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

void mainlink_disp_alloc(int param_1)

{
  FUN_201644ac(param_1 + 0x8114);
  return;
}


// ===== mainlink_disp_init @ 20160048 (96 bytes)

/* 32 x 0x408 B pool + mailbox */

void mainlink_disp_init(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x10) = param_2;
  FUN_20164460();
  uVar2 = 0;
  do {
    iVar3 = param_1 + uVar2 * 0x408;
    FUN_20158618(iVar3 + 0x14);
    FUN_201644a0(param_1 + 0x8114,uVar2 & 0xffff,iVar3 + 0x14);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
  uVar1 = FUN_20162d10(param_1);
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
    FUN_20152434(*(undefined4 *)(param_1 + 0x819c),aiStack_8,0xffffffff);
    *(int *)(param_1 + 0x81a0) = *(int *)(param_1 + 0x81a0) + 1;
    bVar1 = *(byte *)(aiStack_8[0] + 8);
    if (bVar1 == 0x21) {
      memcpy(&DAT_20450035,aiStack_8[0] + 9,*(ushort *)(aiStack_8[0] + 6) - 2);
      uRam20450025 = 1;
    }
    else if (bVar1 < 0x22) {
      if (bVar1 == 6) {
        *(int *)(param_1 + 0x81a4) = *(int *)(param_1 + 0x81a4) + 1;
        FUN_20130968();
        mainlink_on_ack();
      }
      else if (bVar1 == 0x15) {
        *(int *)(param_1 + 0x81a8) = *(int *)(param_1 + 0x81a8) + 1;
        mainlink_on_nak();
      }
      else if (bVar1 == 0x1b) {
        DAT_2045005c = 1;
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
      FUN_201636f8(&DAT_2045006d,aiStack_8[0] + 0xa0);
      DAT_20450024 = 1;
    }
    else if (bVar1 == 0x43) {
      *(int *)(param_1 + 0x81b8) = *(int *)(param_1 + 0x81b8) + 1;
    }
    else if (bVar1 == 0x60) {
      DAT_20450026 = 1;
      FUN_20155310(&DAT_2045fb00,aiStack_8[0] + 8,*(undefined2 *)(aiStack_8[0] + 6));
      iVar2 = FUN_2011727c();
      if (((iVar2 == 0) && (*(int *)(param_1 + 0x81b0) != 0)) && (DAT_2045fbb3 == '\x01')) {
        FUN_20117288(1);
      }
      *(int *)(param_1 + 0x81b0) = *(int *)(param_1 + 0x81b0) + 1;
    }
    DAT_20450034 = *(char *)(aiStack_8[0] + 8);
    if ((DAT_20450034 != '\x06' && DAT_20450034 != '\x15') && DAT_20450034 != '\x1b') {
      FUN_20155310(&DAT_2045f260,aiStack_8[0] + 8,*(undefined2 *)(aiStack_8[0] + 6));
      FUN_20155310(&DAT_2045f8c0,aiStack_8[0] + 8,*(undefined2 *)(aiStack_8[0] + 6));
    }
  } while( true );
}


// ===== mainlink_disp_post @ 20160278 (16 bytes)

void mainlink_disp_post(int param_1,undefined4 param_2)

{
  FUN_20162d3c(param_1,*(undefined4 *)(param_1 + 0x819c),param_2);
  return;
}


// ===== mainlink_disp_ctor @ 20160288 (32 bytes)

/* vtbl 0x20428030 */

int mainlink_disp_ctor(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_20428030;
  iVar1 = FUN_20162c18(param_1 + 0x2045);
  return iVar1 + -0x8114;
}


// ===== fwobj_sdr_run @ 201602ac (288 bytes)

/* vtbl[0]: size == 0x43075A, CRC check, then sdr_flash_write */

undefined4 fwobj_sdr_run(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_20;
  int local_1c;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  iVar1 = fs_fopen(param_2,&DAT_204281ed);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    progress_set(5);
    FUN_20150dcc(0);
    thunk_FUN_2014af64(iVar1,&local_1c);
    if (local_1c == 0x43075a) {
      FUN_20150aac(0,&local_20);
      local_20 = local_20 + -1;
      FUN_2014e884(0);
      iVar3 = sfl_read_header(iVar1,0);
      FUN_2014e884(0);
      if (param_3 == 0) {
        FUN_20141ff0(iVar1);
        if (iVar3 != 0) {
          return 2;
        }
      }
      else {
        gpio_p7_9_11(1);
        gpio_rx_reset(1);
        gpio_rx_update_off(1);
        iVar3 = sdr_flash_write(iVar1,1,*(undefined1 *)(param_1 + 0xab));
        FUN_20141ff0(iVar1);
        if (iVar3 == 0) {
          return 3;
        }
      }
      return 0;
    }
    FUN_20141ff0(iVar1);
    uVar2 = 2;
  }
  return uVar2;
}


// ===== fwobj_sdr_ctor @ 201603d4 (28 bytes)

/* SDR object, vtable 0x20428070, +0xAB flag */

void fwobj_sdr_ctor(undefined4 param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)fwobj_base_ctor();
  *puVar1 = &DAT_20428070;
  *(undefined1 *)((int)puVar1 + 0xab) = param_2;
  return;
}


// ===== fwobj_build_path @ 201603f4 (20 bytes)

/* "%s%s" dir + file name */

void fwobj_build_path(int param_1,undefined4 param_2)

{
  FUN_20154a00(param_1 + 0x58,&DAT_204281f0,param_2,param_1 + 0x37);
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

undefined4 fwobj_match_name(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [36];
  
  iVar1 = fwname_pattern_match(param_1 + 0x14);
  uVar2 = 0;
  if (iVar1 != 0) {
    FUN_20164104(auStack_30,param_2);
    if (*(char *)(param_1 + 0x57) == '\0') {
      memcpy(param_1 + 0x37,auStack_30,0x20);
      *(undefined1 *)(param_1 + 0x57) = 1;
    }
    else {
      iVar1 = thunk_FUN_2014e208(param_1 + 0x37,auStack_30);
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

void fwobj_set_status(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_28 [32];
  
  uVar1 = FUN_20164104(auStack_28);
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

void fwobj_select(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xaa) = 0;
  *(undefined1 *)(param_1 + 0x88) = param_2;
  *(undefined1 *)(param_1 + 0xa9) = 1;
  return;
}


// ===== fwobj_base_ctor @ 201604f4 (88 bytes)

/* base update-object constructor, vtable 0x2042807C */

int fwobj_base_ctor(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &DAT_2042807c;
  iVar1 = FUN_201640ec(param_1 + 1,&DAT_20428430);
  iVar1 = FUN_20160c5c(iVar1 + 10,"-----");
  iVar1 = FUN_201640ec(iVar1 + 0x1e,&DAT_20428430);
  iVar1 = FUN_20164104(iVar1 + 0xb,&DAT_20428430);
  iVar1 = FUN_2016411c(iVar1 + 0x21,&DAT_20428430);
  iVar1 = FUN_20164104(iVar1 + 0x31,&DAT_20428430);
  return iVar1 + -0x89;
}


// ===== fwname_pattern_init @ 20160558 (80 bytes)

/* builds the name pattern (prefix, "NNNN", suffix) */

void fwname_pattern_init(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  param_1[1] = param_2;
  param_1[2] = param_3;
  iVar1 = FUN_20155122(param_2);
  param_1[3] = iVar1;
  iVar1 = FUN_20155122(param_3);
  param_1[5] = iVar1;
  iVar1 = FUN_20155122(&DAT_204281f5);
  param_1[4] = iVar1 + param_1[3];
  *param_1 = iVar1 + param_1[3] + param_1[5];
  return;
}


// ===== fwobj_main_run @ 201605ac (244 bytes)

/* vtbl[0]: CRC check, then RX boot mode entry + rx_boot_program */

undefined4 fwobj_main_run(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  local_18 = param_4;
  iVar1 = fs_fopen(param_2,&DAT_204281fa);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    progress_set(5);
    FUN_20150dcc(0);
    FUN_20150aac(0,&local_18);
    local_18 = local_18 + -1;
    FUN_2014e884(0);
    iVar3 = sfl_read_header(iVar1,0);
    FUN_2014e884(0);
    if (param_3 == 0) {
      FUN_20141ff0(iVar1);
      if (iVar3 != 0) {
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
      iVar3 = rx_boot_program(iVar1,1);
      FUN_20141ff0(iVar1);
      if (iVar3 == 0) {
        return 3;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== fwobj_main_ctor @ 201606a4 (20 bytes)

/* MAIN object, vtable 0x20428088 */

void fwobj_main_ctor(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)fwobj_base_ctor();
  *puVar1 = &DAT_20428088;
  return;
}


// ===== fwobj_ifdsp_run @ 201606bc (264 bytes)

/* vtbl[0]: CRC check, then dsp_isp_program */

undefined4 fwobj_ifdsp_run(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_28;
  uint uStack_24;
  undefined4 local_20;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  iVar1 = fs_fopen(param_2,&DAT_204281fd);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    progress_set(5);
    FUN_20150dcc(0);
    FUN_20150aac(0,&local_28);
    local_28 = local_28 - 1;
    FUN_2014e884(0);
    iVar3 = sfl_read_header(iVar1,0);
    FUN_2014e884(0);
    if (param_3 == 0) {
      FUN_20141ff0(iVar1);
      if (iVar3 != 0) {
        return 2;
      }
    }
    else {
      gpio_p7_9_11(1);
      gpio_rx_reset(1);
      local_28 = (uint)*(byte *)(param_1 + 0xab);
      local_20 = 0;
      uStack_24 = (uint)(local_28 == 0);
      iVar3 = dsp_isp_program(iVar1,1,0);
      FUN_20141ff0(iVar1);
      if (iVar3 == 0) {
        return 3;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== fwobj_ifdsp_ctor @ 201607c8 (28 bytes)

/* IFDSP object, vtable 0x20428094, +0xAB flag */

void fwobj_ifdsp_ctor(undefined4 param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)fwobj_base_ctor();
  *puVar1 = &DAT_20428094;
  *(undefined1 *)((int)puVar1 + 0xab) = param_2;
  return;
}


// ===== fwobj_display_run @ 201607e8 (1032 bytes)

/* vtbl[0]: CRC check, then decoded write to the other bank (or loader) + flag */

undefined4 fwobj_display_run(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_r1;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *unaff_r10;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 auStack_d0 [68];
  undefined4 local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  int local_78;
  int local_74;
  undefined1 auStack_70 [4];
  undefined4 local_6c;
  undefined1 auStack_68 [24];
  undefined4 local_50;
  uint local_4c;
  undefined1 auStack_48 [8];
  uint local_40;
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [12];
  
  bVar1 = false;
  memclr(auStack_d0,0x44);
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  local_78 = fs_fopen(param_2,&DAT_20428200);
  if (local_78 == 0) {
    return 1;
  }
  FUN_20150aac(0,&local_74);
  local_74 = local_74 + -1;
  FUN_2014e884(0);
  iVar2 = sfl_read_header(local_78,auStack_d0);
  FUN_2014e884(0);
  if (DAT_20800181 == ':') {
    unaff_r10 = (undefined4 *)&DAT_20428203;
    iVar3 = thunk_FUN_20155058(auStack_d0,&DAT_20428203);
    if (iVar3 != 0) {
      iVar4 = FUN_20155122(&DAT_20428203);
      iVar3 = iVar3 + iVar4;
      *(undefined1 *)(iVar3 + 8) = 0;
      iVar4 = FUN_2015507c("#UP0    ",iVar3,8);
      if (iVar4 == 0) {
        uVar5 = FUN_201640ec(auStack_3c,iVar3);
        memcpy(param_1 + 4,uVar5,10);
        uVar5 = FUN_201640ec(auStack_30,&DAT_20428210);
        memcpy(param_1 + 0x2c,uVar5,10);
        bVar1 = true;
      }
    }
  }
  if (param_3 == 0) {
    FUN_20141ff0(local_78);
    if (iVar2 == 0) {
      return 0;
    }
    return 2;
  }
  iVar2 = mainlink_fw_mode_cmd(3);
  if (iVar2 == 0) {
    return 3;
  }
  gpio_p7_9_11(1);
  gpio_rx_reset(1);
  gpio_rx_update_off(1);
  local_50 = FUN_20111174(0x100);
  progress_range_init(auStack_70,5,0x1e);
  uVar8 = 0;
  iVar2 = 0;
  thunk_FUN_2014af64(local_78,&local_40);
  if (local_40 < 0x242) {
    return 3;
  }
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_74 = local_40 - 0x240;
  if (DAT_208dbb44 == 1) {
    puVar7 = &DAT_208dbb84;
    unaff_r10 = &DAT_208dbb64;
  }
  else {
    puVar7 = &DAT_208dbb64;
  }
  iVar3 = puVar7[1];
  if (DAT_208dbb44 != 1) {
    unaff_r10 = &DAT_208dbb84;
  }
  sfl_stream_init(auStack_68,local_78,0,1);
  progress_scale(auStack_70,extraout_r1,0,0x3ff00000);
  progress_set();
  if (DAT_208dbb4c == 2) {
    bVar1 = true;
LAB_201609ec:
    iVar3 = 0;
    iVar4 = spiflash_erase(0,0x3c0000,0x14);
    if (iVar4 != 0) goto LAB_20160ac8;
    iVar4 = spiflash_erase(auStack_70,0,local_74);
  }
  else {
    if (bVar1) goto LAB_201609ec;
    iVar4 = spiflash_erase(0,*puVar7,0x14);
    if (iVar4 != 0) goto LAB_20160ac8;
    iVar4 = spiflash_erase(auStack_70,puVar7[1],local_74);
  }
  if (iVar4 == 0) {
    progress_range_init(auStack_48,local_6c,99);
    local_4c = 0xffffffff;
    crc32_make_table();
    while( true ) {
      iVar4 = sfl_stream_read(local_50,1,0x100,auStack_68);
      if (iVar4 == 0) {
        progress_set(100);
        FUN_20141ff0(local_78);
        if (local_74 != iVar2) {
          return 3;
        }
        local_8c = 0x11111111;
        local_7c = ~local_4c;
        local_88 = local_74;
        if (bVar1) {
          iVar2 = spiflash_write(0x3c0000,&local_8c,0x14);
        }
        else {
          iVar2 = spiflash_write(*puVar7,&local_8c,0x14);
          if (iVar2 != 0) {
            return 3;
          }
          iVar2 = spiflash_erase(0,*unaff_r10,0x14);
        }
        if (iVar2 == 0) {
          iVar2 = mainlink_fw_mode_cmd(0x83);
          if (iVar2 != 0) {
            return 0;
          }
          return 3;
        }
        return 3;
      }
      iVar6 = spiflash_write(iVar3,local_50,iVar4);
      if (iVar6 != 0) break;
      local_4c = crc32_update(local_4c,iVar4,local_50);
      iVar2 = iVar2 + iVar4;
      iVar3 = iVar3 + 0x100;
      uVar9 = FUN_20164d82(local_74);
      uVar10 = FUN_20164d82(iVar2);
      uVar9 = FUN_201649d8((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar9,
                           (int)((ulonglong)uVar9 >> 0x20));
      uVar5 = (undefined4)((ulonglong)uVar9 >> 0x20);
      progress_scale(auStack_48,uVar5,(int)uVar9,uVar5);
      progress_set();
      if ((uVar8 & 0xf) == 0) {
        FUN_20150dcc(0);
      }
      uVar8 = uVar8 + 1;
    }
  }
LAB_20160ac8:
  FUN_20141ff0(local_78);
  return 3;
}


// ===== fwobj_display_ctor @ 20160c10 (20 bytes)

/* DISPLAY object, vtable 0x204280A0 */

void fwobj_display_ctor(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)fwobj_base_ctor();
  *puVar1 = &DAT_204280a0;
  return;
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


// ===== FUN_20160c70 @ 20160c70 (124 bytes)

void FUN_20160c70(int param_1)

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


// ===== FUN_20160cf0 @ 20160cf0 (92 bytes)

void FUN_20160cf0(int param_1)

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


// ===== FUN_20160d50 @ 20160d50 (144 bytes)

void FUN_20160d50(int param_1)

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


// ===== FUN_20160de4 @ 20160de4 (92 bytes)

void FUN_20160de4(int param_1)

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


// ===== FUN_20160e44 @ 20160e44 (144 bytes)

void FUN_20160e44(int param_1)

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


// ===== FUN_20160ed8 @ 20160ed8 (52 bytes)

void FUN_20160ed8(void)

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
  int iVar6;
  uint uVar7;
  
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0;
  } while (iVar3 < 0x100);
  uVar7 = (uint)*(byte *)(param_1 + 0x200);
  uVar4 = (uint)*(byte *)(param_1 + 0x201);
  iVar3 = *(int *)(param_2 + 4);
  if (uVar7 <= uVar4) {
    do {
      bVar2 = *(byte *)(param_1 + 0x200);
      iVar5 = __aeabi_uidivmod(640000,(uVar4 - bVar2) + 1);
      iVar6 = uVar7 - bVar2;
      iVar1 = uVar7 * 2;
      uVar7 = uVar7 + 1;
      *(undefined2 *)(param_1 + iVar1) =
           *(undefined2 *)
            (iVar3 + ((uint)*(ushort *)(param_2 + 2) - (iVar5 * (iVar6 + 1) + 0x26ac) / 10000) * 2);
      uVar4 = (uint)*(byte *)(param_1 + 0x201);
    } while ((int)uVar7 <= (int)uVar4);
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


// ===== cpp_task_thunk @ 20162d04 (12 bytes)

/* task entry for C++ objects: exinf = object, calls obj->vtbl[0] */

void cpp_task_thunk(undefined4 *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x20162d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}

