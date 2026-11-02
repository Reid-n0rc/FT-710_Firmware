// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== update_error_screen @ 20159158 (428 bytes)

/* "UPDATE ERROR", waits for a touch */

void update_error_screen(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  short sVar8;
  short sVar9;
  undefined1 auStack_74 [68];
  char local_30 [16];
  
  __aeabi_memcpy4(auStack_74,"UPDATE ERROR",0x44);
  confirm_dialog_draw(1,1,1,0,0x105,0xbf,(int)auStack_74);
  uVar6 = **(ushort **)(&DAT_2080228c + (uint)DAT_20800655 * 4) + 0x119 & 0xffff;
  uVar5 = (*(ushort **)(&DAT_2080228c + (uint)DAT_20800655 * 4))[1] + 0x11d & 0xffff;
  pointer_touch_poll();
  do {
    cursor_window_update();
                    /* Radio off from the GUI side [doc] */
    if (DAT_20800493 != '\0') {
      display_power_down();
    }
    uVar4 = 0;
    uVar3 = 0;
    pointer_get_event(local_30,1);
    touch_cal_apply((int)(short)local_30._4_4_,(int)(short)local_30._8_4_,(short *)&stack0xffffff80,
                    (short *)&stack0xffffff84);
    sVar9 = (short)uVar3;
    sVar8 = (short)uVar4;
    if ((local_30[0] == '\x02' || local_30[0] == '\x04') ||
       (local_30[0] == '\x05' || local_30[0] == '\x06')) {
      mouse_cursor_set_pos(uVar4 & 0xffff,uVar3 & 0xffff);
      uVar3 = (uint)sVar8;
      bVar7 = SBORROW4(uVar3,0x119);
      iVar1 = uVar3 - 0x119;
      uVar4 = 0x119;
      if (0x118 < (int)uVar3) {
        bVar7 = SBORROW4(uVar6,uVar3);
        iVar1 = uVar6 - uVar3;
        uVar4 = uVar6;
      }
      if (((uVar3 != uVar4 && iVar1 < 0 == bVar7) && (0x11c < sVar9)) && ((int)sVar9 < (int)uVar5))
      {
        return;
      }
    }
    pointer_get_event(local_30,0);
    uVar4 = (uint)(short)local_30._4_4_;
    uVar3 = (uint)(short)local_30._8_4_;
    if ((DAT_20800494 != '\0') &&
       ((local_30[0] == '\x02' || local_30[0] == '\x04' ||
        (local_30[0] == '\x05' || local_30[0] == '\x06')))) {
      bVar7 = SBORROW4(uVar4,0x119);
      iVar1 = uVar4 - 0x119;
      uVar2 = 0x119;
      if (0x118 < (int)uVar4) {
        bVar7 = SBORROW4(uVar6,uVar4);
        iVar1 = uVar6 - uVar4;
        uVar2 = uVar6;
      }
      if (uVar4 != uVar2 && iVar1 < 0 == bVar7) {
        bVar7 = SBORROW4(uVar3,0x11d);
        iVar1 = uVar3 - 0x11d;
        uVar4 = 0x11d;
        if (0x11c < (int)uVar3) {
          bVar7 = SBORROW4(uVar5,uVar3);
          iVar1 = uVar5 - uVar3;
          uVar4 = uVar5;
        }
        if (uVar3 != uVar4 && iVar1 < 0 == bVar7) {
          return;
        }
      }
    }
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
  } while( true );
}


// ===== pointer_touch_poll @ 20159320 (28 bytes)

/* pointer_get_event(evt, 1 = touch) with the event dropped (clears a pending touch before a dialog)
   [inference] */

void pointer_touch_poll(void)

{
  undefined1 auStack_10 [12];
  
  pointer_get_event(auStack_10,1);
  return;
}


// ===== FUN_2015933c @ 2015933c (76 bytes)

void FUN_2015933c(void)

{
  undefined1 auStack_4c [68];
  
  __aeabi_memcpy4(auStack_4c,"INSERT FIRMWARE",0x44);
  confirm_dialog_draw(1,1,3,0,0xe6,0xb7,(int)auStack_4c);
  return;
}


// ===== bootloader_screen @ 2015938c (552 bytes)

/* YAESU FT-710 BOOT LOADER V01-02 */

void bootloader_screen(undefined4 param_1,undefined4 *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_20808540;
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  FUN_2010da68();
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,8,400,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,iVar3,8,400,0xc,0x20803a40);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uVar2,(&DAT_2080856c)[uVar4],uVar4 * 0x20 + 100,400,0xc,0x208038c0);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  gui_update_layers();
  DAT_20808532 = 1;
  uVar2 = bootloader_unlock_wait();
  if (DAT_20800493 == '\0') {
    bVar1 = usbkbd_last_key();
    fwupdate_set_hotkey(bVar1);
    iVar3 = sd_state_bit7();
    if (iVar3 == 0) {
      uVar4 = fb_get_layer_addr(DAT_208085bc);
      fb_clear_rect(uVar4,100,0,800,0x17c);
      gui_draw_text_centered(uVar4,DAT_2080856c,100,400,0xc,0x208038c0);
      gui_update_layers();
    }
    iVar3 = sd_state_bit7();
    while (iVar3 == 0) {
      if (DAT_20800493 != '\0') {
        return;
      }
      itron_tslp_tsk(0xffffffff);
      iVar3 = sd_state_bit7();
    }
    if (uVar2 != 0) {
      *param_2 = 0xbbbb;
      fwupdate_ui_run(param_1,"YAESU FT-710 BOOT LOADER V01-02");
      return;
    }
    param_2[2] = 1;
    fwupdate_ui_run(param_1,DAT_20808540);
    DAT_20800496 = 0;
    DAT_20800495 = 1;
  }
  return;
}


// ===== fw_installed_versions_set @ 201595f0 (64 bytes)

/* installed versions from the MAIN 0x60 frame (this = update-UI object, r1 = frame) */

void fw_installed_versions_set(ushort *param_1,byte *param_2)

{
  ushort uVar1;
  
  uVar1 = be16_load(param_2);
  *param_1 = uVar1;
  uVar1 = be16_load(param_2 + 2);
  param_1[1] = uVar1;
  uVar1 = be16_load(param_2 + 4);
  param_1[2] = uVar1;
  uVar1 = be16_load(param_2 + 10);
  param_1[3] = uVar1;
  return;
}


// ===== pointer_idle_loop @ 20159630 (220 bytes)

/* Endless loop: cursor_window_update, pointer events with touch_cal_apply to move the mouse cursor,
   gui_update_layers, 1-tick sleeps; fwupdate_ui_run ends in it [fact] */

void pointer_idle_loop(void)

{
  char local_28 [12];
  ushort local_1c [2];
  ushort local_18 [4];
  
  while( true ) {
    if (DAT_20800493 != '\0') {
      return;
    }
    cursor_window_update();
    local_1c[0] = 0;
    local_18[0] = 0;
    pointer_get_event(local_28,1);
    touch_cal_apply((int)(short)local_28._4_4_,(int)(short)local_28._8_4_,(short *)local_1c,
                    (short *)local_18);
    if ((local_28[0] == '\x02' || local_28[0] == '\x04') ||
       (local_28[0] == '\x05' || local_28[0] == '\x06')) {
      mouse_cursor_set_pos((uint)local_1c[0],(uint)local_18[0]);
      return;
    }
    pointer_get_event(local_28,0);
    if (local_28[0] == '\x02' || local_28[0] == '\x04') {
      return;
    }
    if (local_28[0] == '\x05' || local_28[0] == '\x06') break;
    if (DAT_20808533 != '\0') {
      DAT_20808533 = 0;
      return;
    }
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
  }
  return;
}


// ===== fwupdate_screen @ 20159714 (1376 bytes)

/* MAIN/DISPLAY FIRMWARE UPDATE, STEP 1 of 2 (this = update-UI object) */

void fwupdate_screen(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_288 [288];
  undefined1 auStack_168 [72];
  char cStack_120;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  
  uStack_28 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect(uStack_28,0x132,0,800,0xae);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uStack_28,(&DAT_20808564)[uVar4],uVar4 * 0x20 + 0x132,400,0xf,0x20800b1c)
    ;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  gui_update_layers();
  touch_wait_tap();
  bVar1 = usbkbd_last_key();
  fwupdate_set_hotkey(bVar1);
  do {
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect(uStack_28,0x132,0,800,0xae);
    gui_draw_text_centered(uStack_28,DAT_20808538,0x132,400,0xf,0x20800b1c);
    gui_update_layers();
    fb_get_layer_addr(DAT_208085bc);
    fwfile_check_versions(param_1 + 8);
    *(undefined4 *)(param_1 + 0x3c) = 1;
    *(undefined4 *)(param_1 + 0x84) = 1;
    fwfile_status_text(param_1 + 8,1);
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    gui_update_layers();
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    iVar3 = sd_state_bit7();
    if (iVar3 != 0) {
      if ((*(char *)(param_1 + 8) == '\x01') && (*(char *)(param_1 + 0x50) == '\x01')) break;
      fb_clear_rect(uStack_28,0x132,0,800,0xae);
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      if (*(char *)(param_1 + 8) == '\x01') {
        sprintf(&uStack_48,"[ OK ]");
      }
      else {
        sprintf(&uStack_48,"[ NG : %s ]",param_1 + 0x1d);
      }
      gui_draw_text_words(uStack_28,0x204280ef,0x132,0x9d,0xf,0x20800b1c);
      gui_draw_text_words(uStack_28,(uint)&uStack_48,0x132,0x1a4,0xf,0x20800b1c);
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      if (*(char *)(param_1 + 0x50) == '\x01') {
        sprintf(&uStack_48,"[ OK ] %s",param_1 + 0x8c);
      }
      else {
        sprintf(&uStack_48,"[ NG : %s ]",param_1 + 0x65);
      }
      gui_draw_text_words(uStack_28,0x2042810c,0x152,0x9d,0xf,0x20800b1c);
      gui_draw_text_words(uStack_28,(uint)&uStack_48,0x152,0x1a4,0xf,0x20800b1c);
      gui_draw_text_centered(uStack_28,DAT_2080853c,0x192,400,0xf,0x20800b1c);
    }
    gui_update_layers();
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    iVar3 = sd_state_bit6();
    while (iVar3 != 0) {
      if (DAT_20800493 != '\0') {
        display_power_down();
      }
      itron_tslp_tsk(0xffffffff);
      gui_update_layers();
      uStack_28 = fb_get_layer_addr(DAT_208085bc);
      iVar3 = sd_state_bit6();
    }
    fb_clear_rect(uStack_28,0x132,0,800,0xae);
    gui_draw_text_centered(uStack_28,DAT_2080856c,0x132,400,0xf,0x20800b1c);
    gui_update_layers();
    fb_get_layer_addr(DAT_208085bc);
    iVar3 = sd_state_bit7();
    while (iVar3 == 0) {
      if (DAT_20800493 != '\0') {
        display_power_down();
      }
      itron_tslp_tsk(0xffffffff);
      iVar3 = sd_state_bit7();
    }
  } while( true );
  *(undefined4 *)(param_1 + 0x3c) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  fb_clear_rect(uStack_28,0x132,0,800,0xae);
  gui_draw_text_centered(uStack_28,0x20428122,0x132,400,0xf,0x20800b1c);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uStack_28,(&DAT_20808548)[uVar4],uVar4 * 0x20 + 0x152,400,0xf,0x20800b1c)
    ;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 2);
  __aeabi_memcpy4(auStack_168,param_1 + 8,0x120);
  __aeabi_memcpy4(auStack_288,param_1 + 8,0x120);
  bVar1 = 0xff;
  while( true ) {
    bVar2 = fwupdate_poll(param_1 + 8);
    iVar3 = sd_state_bit6();
    if (iVar3 == 0) break;
    if ((bVar1 != bVar2) ||
       (iVar3 = memcmp(param_1 + 8,auStack_288,0x120), bVar1 = bVar2, iVar3 != 0)) {
      __aeabi_memcpy4(auStack_288,param_1 + 8,0x120);
      if (*(char *)(param_1 + 8) == '\x04') {
        gui_draw_progress_bar
                  (uStack_28,0x1a5,0x129,*(uint *)(param_1 + 0x40) & 0xffff,
                   *(uint *)(param_1 + 0x40));
      }
      else if (*(char *)(param_1 + 0x50) == '\x04') {
        if (cStack_120 != '\x04') {
          fb_clear_rect(uStack_28,0x132,0,800,0xae);
          gui_draw_text_centered(uStack_28,0x2042812f,0x132,400,0xf,0x20800b1c);
          uVar4 = 0;
          do {
            gui_draw_text_centered
                      (uStack_28,(&DAT_20808550)[uVar4],uVar4 * 0x20 + 0x152,400,0xf,0x20800b1c);
            uVar4 = uVar4 + 1 & 0xff;
          } while (uVar4 < 2);
        }
        gui_draw_progress_bar
                  (uStack_28,0x1a5,0x129,*(uint *)(param_1 + 0x88) & 0xffff,
                   *(uint *)(param_1 + 0x88));
        gui_update_layers();
        fb_get_layer_addr(DAT_208085bc);
      }
      __aeabi_memcpy4(auStack_168,param_1 + 8,0x120);
      if (bVar2 != 0) goto LAB_20159c44;
      gui_update_layers();
      uStack_28 = fb_get_layer_addr(DAT_208085bc);
      bVar1 = bVar2;
    }
  }
  bVar2 = 2;
LAB_20159c44:
  FUN_2010e4a0();
  if (bVar2 != 1) {
    update_error_screen();
  }
  system_reboot();
  return;
}


// ===== bootloader_unlock_wait @ 20159cb0 (216 bytes)

/* key-6 mode: > 4 encoder steps -> loader-install mode */

uint bootloader_unlock_wait(void)

{
  uint uVar1;
  char local_30 [12];
  short local_24 [2];
  short local_20 [4];
  
  uVar1 = 0;
  pointer_touch_poll();
  DAT_208001e4 = '\0';
  while( true ) {
    if (DAT_20800493 != '\0') {
      return 0;
    }
    if ((g_bootinfo.mode == 2) &&
       (uVar1 = FUN_20164568(&DAT_20808bcc,uVar1,(int)DAT_208001e4), 4 < uVar1)) {
      return 1;
    }
    gui_update_layers();
    local_24[0] = 0;
    local_20[0] = 0;
    pointer_get_event(local_30,1);
    touch_cal_apply((int)(short)local_30._4_4_,(int)(short)local_30._8_4_,local_24,local_20);
    if (local_30[0] == '\x02' || local_30[0] == '\x04') {
      return 0;
    }
    if (local_30[0] == '\x05' || local_30[0] == '\x06') break;
    pointer_get_event(local_30,0);
    itron_tslp_tsk(0xffffffff);
  }
  return 0;
}


// ===== fwupdate_ui_run @ 20159d98 (956 bytes)

/* Update-UI method behind fwupdate_title_screen_thunk and bootloader_screen ("YAESU FT-710 FIRMWARE
   UPDATE"): menu, target selection (fwupdate_select_loop), "UPDATE?" confirmation
   (fwupdate_confirm_loop), then fwupdate_progress_screen; card-missing and error texts [fact] */

void fwupdate_ui_run(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_4b8 [3];
  char local_4b5;
  undefined1 local_4b4;
  undefined1 local_4b3;
  undefined1 auStack_278 [5];
  undefined1 local_273;
  int iStack_30;
  undefined4 local_2c;
  
  iStack_30 = param_1;
  local_2c = param_2;
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  if (DAT_20800494 != '\0') {
    mainlink_send_e6(0);
  }
  DAT_20800496 = 1;
  DAT_20800495 = 0;
LAB_20159dec:
  fb_clear_rect(iVar1,0,0,800,0x1e0);
  cursor_window_update();
  fwupdate_menu_screen(param_1,0,local_2c);
  gui_update_layers();
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  if (*(char *)(param_1 + 0x128) == -0x3d) {
    __aeabi_memclr4(local_4b8,0x240);
    local_4b8[0] = 0x43;
    if ((*(char *)(param_1 + 0x12a) == '\0') && (*(char *)(param_1 + 299) != '\0')) {
      if ((*(byte *)(param_1 + 299) & 0x40) == 0) {
        local_4b4 = 0;
      }
      else {
        local_4b4 = 0x40;
      }
      local_4b5 = *(char *)(param_1 + 299);
      local_4b3 = FUN_20158fa8(*(undefined1 *)(param_1 + 299));
                    /* title bar, four target rows [doc] */
      fwupdate_select_draw(param_1,local_4b8,local_2c);
      if (DAT_20800494 == '\0') {
        iVar1 = fb_get_layer_addr(DAT_208085bc);
        fb_clear_rect_checked(iVar1,0x19a,0x1a4,0x17c,0x46);
        gui_update_layers();
      }
                    /* Touch/mouse loop of the target list [doc] */
      iVar2 = fwupdate_select_loop(param_1,local_4b8,local_2c);
      if (iVar2 == 0) {
LAB_20159f50:
        if (DAT_20800493 != '\0') {
          return;
        }
        goto LAB_2015a040;
      }
      if ((DAT_20800494 == '\0') || (mainlink_send_e6(0), DAT_20808530 == '\0')) goto LAB_2015a100;
      local_4b3 = 10;
      fwupdate_confirm_draw(param_1,local_4b8);
      gui_update_layers();
                    /* Touch/mouse loop of the "UPDATE?" box [doc] */
      iVar2 = fwupdate_confirm_loop(param_1);
      if (iVar2 == 0) goto LAB_20159f50;
      mainlink_send_e6(0);
      if (DAT_20808531 != '\0') goto LAB_2015a100;
      goto LAB_20159dec;
    }
    if (DAT_20800494 != '\0') {
      __aeabi_memclr4(auStack_278,0x240);
      local_273 = 0xb;
      fwupdate_select_draw(param_1,auStack_278,local_2c);
      gui_update_layers();
      iVar1 = fwupdate_select_loop(param_1,auStack_278,local_2c);
      if (iVar1 == 0) {
        if (DAT_20800493 != '\0') {
          return;
        }
        goto LAB_2015a040;
      }
      goto LAB_2015a100;
    }
    uVar3 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect_checked(uVar3,0x19a,0,800,0x46);
    gui_draw_text_centered(uVar3,DAT_2080853c,0x1a7,400,0xc,0x208038c0);
    iVar1 = sd_state_bit6();
    while (iVar1 != 0) {
      if (DAT_20800493 != '\0') {
        return;
      }
      itron_tslp_tsk(0xffffffff);
      gui_update_layers();
      fb_get_layer_addr(DAT_208085bc);
      iVar1 = sd_state_bit6();
    }
  }
LAB_2015a040:
  if (DAT_20800494 != '\0') {
    FUN_2015933c();
    pointer_idle_loop();
    if (DAT_20800493 == '\0') {
      mainlink_send_e6(0);
    }
LAB_2015a100:
    layer_alpha_rect_opaque(5);
    if ((DAT_20800494 != '\0') && (DAT_20808531 == '\0')) {
      DAT_20800494 = 0;
      return;
    }
    fwupdate_progress_screen(param_1,0,local_2c);
    do {
      gui_update_layers();
      itron_tslp_tsk(0xffffffff);
    } while( true );
  }
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect_checked(uVar3,0x1a,0,800,0x1c6);
  gui_draw_text_centered(uVar3,DAT_2080856c,100,400,0xc,0x208038c0);
                    /* full-screen window, alpha 0xFF [doc, inference] */
  layer_alpha_rect_opaque(5);
  gui_update_layers();
  iVar1 = fb_get_layer_addr(DAT_208085bc);
  iVar2 = sd_state_bit7();
  while (iVar2 == 0) {
    if (DAT_20800493 != '\0') {
      return;
    }
    itron_tslp_tsk(0xffffffff);
    iVar2 = sd_state_bit7();
  }
  goto LAB_20159dec;
}


// ===== fwupdate_confirm_loop @ 2015a17c (832 bytes)

/* Touch/mouse loop of the "UPDATE?" box: YES at (0x19A, 0xFA) / NO at (0x19A, 0x1A4), redraws with
   fwupdate_confirm_draw [fact] */

undefined4 fwupdate_confirm_loop(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  ushort local_2a0 [2];
  ushort local_29c [2];
  undefined1 auStack_298 [5];
  undefined1 local_293;
  int local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  char local_34 [12];
  int local_28;
  
  local_28 = param_1;
  __aeabi_memclr4(auStack_298,0x240);
  sVar5 = DAT_20808536;
  iVar4 = 10;
  pointer_touch_poll();
  local_58 = 0xfa;
  local_54 = *DAT_20802294 + 0xfa & 0xffff;
  uVar7 = *DAT_20802294 + 0x1a4 & 0xffff;
  uVar8 = DAT_20802294[1] + 0x19a & 0xffff;
  uVar6 = DAT_20802294[1] + 0x19a & 0xffff;
  do {
    iVar1 = sd_state_bit7();
    if (iVar1 == 0) {
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_58 = 0x447;
      mainlink_send_ui_c3((void *)(local_28 + 0x128),(uint)&local_58);
      return 0;
    }
    cursor_window_update();
    if (DAT_20800493 != '\0') {
      return 0;
    }
    gui_update_layers();
    local_29c[0] = 0;
    local_2a0[0] = 0;
    pointer_get_event(local_34,1);
    touch_cal_apply((int)(short)local_34._4_4_,(int)(short)local_34._8_4_,(short *)local_29c,
                    (short *)local_2a0);
    if ((local_34[0] == '\x02' || local_34[0] == '\x04') ||
       (local_34[0] == '\x05' || local_34[0] == '\x06')) {
      mouse_cursor_set_pos((uint)local_29c[0],(uint)local_2a0[0]);
      uVar2 = (uint)(short)local_29c[0];
      if ((local_58 <= (int)uVar2) && ((int)uVar2 < (int)local_54)) {
        iVar3 = (int)(short)local_2a0[0];
        bVar9 = SBORROW4(0x19a,iVar3);
        iVar1 = 0x19a - iVar3;
        if (0x199 < iVar3) {
          bVar9 = SBORROW4(iVar3,uVar8);
          iVar1 = iVar3 - uVar8;
        }
        if (iVar1 < 0 != bVar9) {
          DAT_20808531 = 1;
          return 1;
        }
      }
      bVar10 = SBORROW4(uVar2,0x1a4);
      iVar1 = uVar2 - 0x1a4;
      bVar9 = uVar2 == 0x1a4;
      if (0x1a3 < (int)uVar2) {
        bVar10 = SBORROW4(uVar7,uVar2);
        iVar1 = uVar7 - uVar2;
        bVar9 = uVar7 == uVar2;
      }
      if (!bVar9 && iVar1 < 0 == bVar10) {
        iVar3 = (int)(short)local_2a0[0];
        bVar9 = SBORROW4(0x19a,iVar3);
        iVar1 = 0x19a - iVar3;
        if (0x199 < iVar3) {
          bVar9 = SBORROW4(iVar3,uVar6);
          iVar1 = iVar3 - uVar6;
        }
        if (iVar1 < 0 != bVar9) {
          DAT_20808531 = 0;
          return 1;
        }
      }
    }
    pointer_get_event(local_34,0);
    local_29c[0] = (ushort)local_34._4_4_;
    uVar2 = (uint)(short)local_29c[0];
    local_2a0[0] = (ushort)local_34._8_4_;
    iVar1 = (int)(short)local_2a0[0];
    if ((local_34[0] == '\x02' || local_34[0] == '\x04') ||
       (local_34[0] == '\x05' || local_34[0] == '\x06')) {
      if ((local_58 <= (int)uVar2) && ((int)uVar2 < (int)local_54)) {
        bVar9 = SBORROW4(0x19a,iVar1);
        iVar3 = 0x19a - iVar1;
        if (0x199 < iVar1) {
          bVar9 = SBORROW4(iVar1,uVar8);
          iVar3 = iVar1 - uVar8;
        }
        if (iVar3 < 0 != bVar9) {
          DAT_20808531 = 1;
          return 1;
        }
      }
      bVar10 = SBORROW4(uVar2,0x1a4);
      iVar3 = uVar2 - 0x1a4;
      bVar9 = uVar2 == 0x1a4;
      if (0x1a3 < (int)uVar2) {
        bVar10 = SBORROW4(uVar7,uVar2);
        iVar3 = uVar7 - uVar2;
        bVar9 = uVar7 == uVar2;
      }
      if (((!bVar9 && iVar3 < 0 == bVar10) && (0x199 < iVar1)) && (iVar1 < (int)uVar6)) {
        DAT_20808531 = 0;
        return 1;
      }
    }
    mouse_right_get_event(local_34);
    if ((local_34[0] == '\x02' || local_34[0] == '\x04') ||
       (local_34[0] == '\x05' || local_34[0] == '\x06')) {
      DAT_20808531 = 0;
      return 1;
    }
    if ((sVar5 != DAT_20808536) || (DAT_20808534 != 0)) {
      if ((sVar5 < DAT_20808536) || (DAT_20808534 < 0)) {
        if (iVar4 != 0xb) {
          iVar4 = 0xb;
          local_293 = 0xb;
          fwupdate_confirm_draw(local_28,auStack_298);
        }
      }
      else if (iVar4 != 10) {
        iVar4 = 10;
        local_293 = 10;
        fwupdate_confirm_draw(local_28,auStack_298);
      }
      DAT_20808534 = 0;
      sVar5 = DAT_20808536;
    }
    if (DAT_20808533 != '\0') {
      DAT_20808531 = iVar4 == 10;
      DAT_20808533 = 0;
      return 1;
    }
    itron_tslp_tsk(0xffffffff);
  } while( true );
}


// ===== FUN_2015a4c8 @ 2015a4c8 (52 bytes)

void FUN_2015a4c8(void)

{
  touch_set_up();
  mouse_set_up();
  if (DAT_20800494 != '\0') {
    mainlink_send_touch_key(0,0xffff);
  }
  pointer_touch_poll();
  return;
}


// ===== fwupdate_menu_screen @ 2015a500 (964 bytes)

/* file list, CRC check, pre-marks newer versions */

void fwupdate_menu_screen(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_70;
  uint local_6c;
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
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = usbkbd_last_key();
  fwupdate_set_hotkey(bVar1);
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  if (param_3 == 0) {
    param_3 = DAT_20808540;
  }
  gui_draw_text_centered(uVar2,param_3,4,400,0xf,0x20800cac);
  gui_update_layers();
  local_4c = fb_get_layer_addr(DAT_208085bc);
  iVar3 = sd_state_bit7();
  if (iVar3 == 0) {
    local_38 = 0;
    local_4c = 0x447;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    mainlink_send_ui_c3((void *)(param_1 + 0x128),(uint)&local_4c);
    return;
  }
  fwfile_check_versions(param_1 + 8);
  iVar3 = 0;
  do {
    iVar4 = param_1 + iVar3 * 0x48;
    gui_draw_text(local_4c,iVar4 + 9,iVar3 * 0x44 + 0x41U & 0xffff,0xc4);
    gui_draw_text(local_4c,iVar4 + 0x1d,iVar3 * 0x44 + 0x43U & 0xffff,0x1dc);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  gui_update_layers();
  fb_get_layer_addr(DAT_208085bc);
  gui_scope_draw_hold_set(1);
  uVar2 = fwfile_status_text(param_1 + 8,0);
  gui_update_layers();
  local_4c = fb_get_layer_addr(DAT_208085bc);
                    /* Builds the 3DSS line offset tables 0x20907F7C/7FF4 [doc] */
  scope3d_tables_init();
  gui_scope_draw_hold_set(0);
  itron_dly_tsk(0x32);
  iVar3 = sd_state_bit6();
  if (iVar3 != 0) {
    if (uVar2 != 1 && uVar2 != 3) {
      iVar3 = 0x47;
      local_5c = 0;
      local_6c = 0;
      local_68 = 0;
      if (uVar2 == 0) {
        iVar3 = 0;
      }
      local_64 = 0;
      local_70._0_2_ = CONCAT11((char)uVar2,0x47);
      local_70 = (uint)(ushort)local_70;
      local_60 = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      if (uVar2 == 0) {
        do {
          iVar4 = param_1 + iVar3 * 0x48;
          if (*(char *)(iVar4 + 8) == '\x01') {
            local_70._0_3_ =
                 CONCAT12(local_70._2_1_ | (byte)(1 << (7U - iVar3 & 0xff)),(ushort)local_70);
            local_70 = (uint)(uint3)local_70;
          }
          if (*(char *)(iVar4 + 8) == '\x03') {
            local_6c = (uint)(byte)((byte)local_6c | (byte)(1 << (7U - iVar3 & 0xff)));
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 4);
      }
      iVar3 = 0;
      do {
        sprintf(&stack0xffffff88,&DAT_2042813c,*(undefined2 *)(param_1 + iVar3 * 2));
                    /* Case-insensitive compare with tolower [doc] */
        iVar4 = strcasecmp(param_1 + iVar3 * 0x48 + 0x31,&stack0xffffff88);
        if (0 < iVar4) {
          local_70 = CONCAT13(local_70._3_1_ | (byte)(1 << (7U - iVar3 & 0xff)),(uint3)local_70);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      mainlink_send_ui_c3((void *)(param_1 + 0x128),(uint)&local_70);
      iVar3 = 0;
      do {
        uVar2 = iVar3 * 0x44 + 0x41;
        fb_fill_rect(local_4c,0x821,uVar2 & 0xffff,0x25c,800,0x1a);
        iVar4 = param_1 + iVar3 * 0x48;
        gui_draw_text(local_4c,iVar4 + 9,uVar2 & 0xffff,0xc4);
        gui_draw_text(local_4c,iVar4 + 0x1d,iVar3 * 0x44 + 0x43U & 0xffff,0x1dc);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      FUN_2015a4c8();
      return;
    }
    local_38 = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_4c = (uint)CONCAT11((char)uVar2,0x47);
    local_3c = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    mainlink_send_ui_c3((void *)(param_1 + 0x128),(uint)&local_4c);
    return;
  }
  mainlink_send_ui_e2((void *)(param_1 + 0x128),(uint)&stack0xffffff88);
  return;
}


// ===== fwupdate_select_screen @ 2015a8dc (52 bytes)

/* WARNING: Removing unreachable block (ram,0x2015b1d4) */
/* WARNING: Removing unreachable block (ram,0x2015b4d4) */
/* Update-UI method (thunk 0x201322D8), packet step 1: four target rows with tick boxes and the
   OK/CANCEL keys; 2: "UPDATE?"; 3: runs fwupdate_poll with per-row progress bars, then
   update_error_screen on failure and system_reboot [fact] */

void fwupdate_select_screen(int param_1,int param_2)

{
  char cVar1;
  byte fwupdate_poll_ret;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  bool bVar7;
  char acStack_270 [288];
  undefined1 auStack_150 [288];
  uint uVar8;
  
  cVar1 = *(char *)(param_2 + 2);
  if (cVar1 == '\x01') {
    uVar8 = fb_get_layer_addr(DAT_208085bc);
    uVar6 = (uint)*(byte *)(param_2 + 5);
    fb_clear_rect(uVar8,0,0,800,0x1e0);
    fb_fill_rect(uVar8,0x3186,2,2,0x31a,0x18);
    gui_draw_runs(uVar8,4,400,&DAT_2016dc08);
    gui_draw_text_centered(uVar8,DAT_20808540,4,400,0xf,0x20800cac);
    uVar2 = 0;
    do {
      uVar4 = 1 << (7 - uVar2 & 0xff);
      if ((*(byte *)(param_2 + 3) & uVar4) != 0) {
        iVar3 = uVar2 * 0x44 + 0x32;
        fb_clear_rect(uVar8,iVar3,0x75,0x78,0x43);
        if ((*(byte *)(param_2 + 4) & uVar4) == 0) {
          puVar5 = (undefined2 *)&DAT_203a5684;
          *(undefined4 *)(param_1 + uVar2 * 0x48 + 0x3c) = 0;
        }
        else {
          puVar5 = &DAT_203a5694;
          *(undefined4 *)(param_1 + uVar2 * 0x48 + 0x3c) = 1;
        }
        gui_draw_runs(uVar8,iVar3,0x75,puVar5);
        if (uVar2 == uVar6) {
          fb_draw_round_frame_wrap(uVar8,iVar3,0x75,*puVar5);
        }
      }
      iVar3 = param_1 + uVar2 * 0x48;
      gui_draw_text(uVar8,iVar3 + 9,uVar2 * 0x44 + 0x41,0xc4);
      gui_draw_text(uVar8,iVar3 + 0x1d,uVar2 * 0x44 + 0x43,0x1dc);
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
    gui_button_draw_shadow(uVar8,0x19a,0xfa,2);
    if (*(char *)(param_2 + 4) == '\0') {
      gui_draw_runs(uVar8,0x1a6,0x10f,&DAT_20255114);
    }
    else {
      gui_draw_runs(uVar8,0x1a6,0x10f,&DAT_20254600);
    }
    if (uVar6 == 10) {
      fb_draw_round_frame_wrap(uVar8,0x19a,0xfa,*DAT_20802294);
    }
    if (DAT_20800494 != '\0') {
      gui_button_draw_shadow(uVar8,0x19a,0x1a4,2);
      gui_draw_runs(uVar8,0x1a6,0x1b9,&DAT_20251ec8);
      if (uVar6 == 0xb) {
        fb_draw_round_frame_wrap(uVar8,0x19a,0x1a4,*DAT_20802294);
      }
    }
    return;
  }
  if (cVar1 == '\x02') {
    uVar8 = fb_get_layer_addr(DAT_208085bc);
    cVar1 = *(char *)(param_2 + 5);
    fb_clear_rect(uVar8,0,0,800,0x1e0);
    fb_fill_rect(uVar8,0x3186,2,2,0x31a,0x18);
    gui_draw_runs(uVar8,4,400,&DAT_2016dc08);
    gui_draw_runs(uVar8,8,0x168,&DAT_203a56b4);
    gui_draw_text_centered(uVar8,0x20428153,0xf0,400,0xf,0x20800cac);
    gui_button_draw_shadow(uVar8,0x19a,0xfa,2);
    gui_draw_runs(uVar8,0x1a6,0x10f,&DAT_20253aec);
    if (cVar1 == '\n') {
      fb_draw_round_frame_wrap(uVar8,0x19a,0xfa,*DAT_20802294);
    }
    gui_button_draw_shadow(uVar8,0x19a,0x1a4,2);
    gui_draw_runs(uVar8,0x1a6,0x1b9,&DAT_20251ec8);
    if (cVar1 == '\v') {
      fb_draw_round_frame_wrap(uVar8,0x19a,0x1a4,*DAT_20802294);
    }
    return;
  }
  if (cVar1 != '\x03') {
    return;
  }
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  mouse_detach_post();
  DAT_20800496 = 1;
  DAT_20800495 = 0;
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,DAT_20808540,4,400,0xf,0x20800cac);
  gui_draw_text_centered(uVar2,DAT_20808544,0x1a7,400,0xf,0x20800cac);
  uVar8 = 0xff;
  __aeabi_memcpy4(acStack_270,param_1 + 8,0x120);
  __aeabi_memcpy4(auStack_150,param_1 + 8,0x120);
  gui_scope_draw_hold_set(1);
  while( true ) {
    fwupdate_poll_ret = fwupdate_poll(param_1 + 8);
    uVar6 = (uint)fwupdate_poll_ret;
    iVar3 = sd_state_bit6();
    if (iVar3 == 0) break;
    bVar7 = uVar8 != uVar6;
    uVar8 = uVar6;
    if ((bVar7) || (iVar3 = memcmp(param_1 + 8,auStack_150,0x120), iVar3 != 0)) {
      __aeabi_memcpy4(auStack_150,param_1 + 8,0x120);
      uVar4 = 0;
      do {
        iVar3 = param_1 + uVar4 * 0x48;
        gui_draw_text(uVar2,iVar3 + 9,uVar4 * 0x44 + 0x41,0xc4,0xf,&DAT_20800b1c);
        cVar1 = *(char *)(iVar3 + 8);
        if (cVar1 == '\x04') {
          if (acStack_270[uVar4 * 0x48] != '\x04') {
            fb_clear_rect(uVar2,uVar4 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          gui_draw_progress_bar
                    (uVar2,uVar4 * 0x44 + 0x42,0x1dc,*(uint *)(iVar3 + 0x40) & 0xffff,
                     *(uint *)(iVar3 + 0x40));
        }
        else {
          if (cVar1 == '\x05') {
            if (acStack_270[uVar4 * 0x48] != '\x05') {
              fb_clear_rect(uVar2,uVar4 * 0x44 + 0x42,0x1dc,0x144,0x19);
            }
            gui_draw_runs(uVar2,uVar4 * 0x44 + 0x32,0x75,&DAT_203a56a4);
          }
          else if (cVar1 != acStack_270[uVar4 * 0x48]) {
            fb_clear_rect(uVar2,uVar4 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          gui_draw_text(uVar2,iVar3 + 0x1d,uVar4 * 0x44 + 0x43,0x1dc,0xf,&DAT_20800b1c);
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 4);
      __aeabi_memcpy4(acStack_270,param_1 + 8,0x120);
      if (uVar6 != 0) goto LAB_2015b360;
      gui_update_layers();
      uVar2 = fb_get_layer_addr(DAT_208085bc);
    }
  }
  uVar6 = 2;
LAB_2015b360:
  FUN_2010e4a0();
  if (uVar6 != 1) {
    update_error_screen();
  }
  system_reboot();
  return;
}


// ===== fwupdate_select_loop @ 2015a910 (1628 bytes)

/* WARNING: Removing unreachable block (ram,0x2015ae84) */
/* Touch/mouse loop of the target list (pointer_get_event, touch_cal_apply, mouse cursor): toggles
   the tick boxes of the four rows, OK / CANCEL keys, redraws with fwupdate_select_draw, mirrors the
   state to MAIN (mainlink_send_ui_c3, E6) [fact] */

undefined4 fwupdate_select_loop(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *extraout_r1;
  uint *extraout_r1_00;
  uint uVar9;
  int iVar10;
  short sVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  bool bVar17;
  ushort local_2a8 [2];
  ushort local_2a4 [2];
  undefined1 auStack_2a0 [3];
  byte local_29d;
  byte local_29c;
  byte local_29b;
  uint *local_60;
  uint local_5c;
  int local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  byte local_48 [24];
  int local_30;
  uint uStack_2c;
  undefined4 local_28;
  
  sVar11 = DAT_20808536;
  local_30 = param_1;
  uStack_2c = param_2;
  local_28 = param_3;
  pointer_touch_poll();
  local_58 = 0xfa;
  local_50 = *DAT_20802294 + 0xfa & 0xffff;
  uVar14 = *DAT_20802294 + 0x1a4 & 0xffff;
  local_60 = (uint *)0x19a;
  local_54 = DAT_20802294[1] + 0x19a & 0xffff;
  puVar13 = (uint *)(DAT_20802294[1] + 0x19a & 0xffff);
  local_5c = 0x1a4;
  __aeabi_memclr4(auStack_2a0,0x240);
  memcpy(auStack_2a0,param_2,0x240);
LAB_2015a994:
  iVar4 = sd_state_bit7();
  if (iVar4 == 0) {
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_48[0] = 0;
    local_48[1] = 0;
    local_48[2] = 0;
    local_48[3] = 0;
    local_48[4] = 0;
    local_48[5] = 0;
    local_48[6] = 0;
    local_48[7] = 0;
    local_48[8] = 0;
    local_48[9] = 0;
    local_48[10] = 0;
    local_48[0xb] = 0;
    local_60 = (uint *)0x447;
    mainlink_send_ui_c3((void *)(local_30 + 0x128),(uint)&local_60);
    return 0;
  }
  cursor_window_update();
  if (DAT_20800493 != '\0') {
    return 0;
  }
  gui_update_layers();
  local_2a8[0] = 0;
  local_2a4[0] = 0;
  pointer_get_event(local_48 + 0xc,1);
  touch_cal_apply((int)(short)local_48._16_4_,(int)(short)local_48._20_4_,(short *)local_2a8,
                  (short *)local_2a4);
  if ((local_48[0xc] == '\x02' || local_48[0xc] == '\x04') ||
     (local_48[0xc] == '\x05' || local_48[0xc] == '\x06')) {
    mouse_cursor_set_pos((uint)local_2a8[0],(uint)local_2a4[0]);
    if ((local_29c != 0) &&
       ((((local_58 <= (short)local_2a8[0] && ((int)(short)local_2a8[0] < (int)local_50)) &&
         (0x199 < (short)local_2a4[0])) && ((int)(short)local_2a4[0] < (int)local_54)))) {
      DAT_20808530 = 1;
      return 1;
    }
    if (DAT_20800494 != '\0') {
      uVar5 = (uint)(short)local_2a8[0];
      bVar17 = SBORROW4(uVar5,local_5c);
      iVar4 = uVar5 - local_5c;
      uVar7 = local_5c;
      if ((int)local_5c <= (int)uVar5) {
        bVar17 = SBORROW4(uVar14,uVar5);
        iVar4 = uVar14 - uVar5;
        uVar7 = uVar14;
      }
      if (uVar5 != uVar7 && iVar4 < 0 == bVar17) {
        puVar6 = (uint *)(int)(short)local_2a4[0];
        bVar17 = SBORROW4((int)puVar6,(int)local_60);
        iVar4 = (int)puVar6 - (int)local_60;
        puVar8 = local_60;
        if ((int)local_60 <= (int)puVar6) {
          bVar17 = SBORROW4((int)puVar13,(int)puVar6);
          iVar4 = (int)puVar13 - (int)puVar6;
          puVar8 = puVar13;
        }
        if (puVar6 != puVar8 && iVar4 < 0 == bVar17) {
          mainlink_send_e6(0);
          DAT_20808530 = 0;
          return 1;
        }
      }
    }
    uVar7 = 0;
    do {
      iVar4 = uVar7 * 0x44 + 0x32;
      iVar10 = uVar7 * 0x44 + 0x75;
      if (((((uint)local_29d & 1 << (7 - uVar7 & 0xff)) != 0) && (0x74 < (short)local_2a8[0])) &&
         ((short)local_2a8[0] < 0xed)) {
        iVar15 = (int)(short)local_2a4[0];
        bVar17 = SBORROW4(iVar15,iVar4);
        iVar1 = iVar15 - iVar4;
        if (iVar4 <= iVar15) {
          bVar17 = SBORROW4(iVar10,iVar15);
          iVar1 = iVar10 - iVar15;
          iVar4 = iVar10;
        }
        if (iVar15 != iVar4 && iVar1 < 0 == bVar17) {
          local_29c = local_29c ^ (byte)(1 << (7 - uVar7 & 0xff));
          local_29b = (byte)uVar7;
                    /* title bar, four target rows [doc] */
          fwupdate_select_draw(local_30,auStack_2a0,local_28);
          if (DAT_20800494 != '\0') {
            mainlink_send_e6(0);
          }
          break;
        }
      }
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < 4);
  }
  pointer_get_event(local_48 + 0xc,0);
  local_2a8[0] = (ushort)local_48._16_4_;
  iVar4 = (int)(short)local_2a8[0];
  local_2a4[0] = (ushort)local_48._20_4_;
  puVar8 = (uint *)(int)(short)local_2a4[0];
  if (DAT_20800494 != '\0') {
    if ((local_48[0xc] == '\x02' || local_48[0xc] == '\x04') ||
       (local_48[0xc] == '\x05' || local_48[0xc] == '\x06')) {
      local_4c = (uint)local_29c;
      if (((local_4c != 0) &&
          (((local_58 <= iVar4 && (iVar4 < (int)local_50)) && (0x199 < (int)puVar8)))) &&
         ((int)puVar8 < (int)local_54)) {
        DAT_20808530 = 1;
        return 1;
      }
      bVar17 = SBORROW4(local_5c,iVar4);
      iVar10 = local_5c - iVar4;
      if ((int)local_5c <= iVar4) {
        bVar17 = SBORROW4(iVar4,uVar14);
        iVar10 = iVar4 - uVar14;
      }
      if (iVar10 < 0 != bVar17) {
        bVar17 = SBORROW4((int)puVar8,(int)local_60);
        iVar10 = (int)puVar8 - (int)local_60;
        puVar6 = local_60;
        if ((int)local_60 <= (int)puVar8) {
          bVar17 = SBORROW4((int)puVar13,(int)puVar8);
          iVar10 = (int)puVar13 - (int)puVar8;
          puVar6 = puVar13;
        }
        if (puVar8 != puVar6 && iVar10 < 0 == bVar17) {
          DAT_20808530 = 0;
          return 1;
        }
      }
      uVar7 = 0;
      do {
        puVar6 = (uint *)(uVar7 * 0x44 + 0x32);
        puVar16 = (uint *)(uVar7 * 0x44 + 0x75);
        if (((((uint)local_29d & 1 << (7 - uVar7 & 0xff)) != 0) && (0x74 < iVar4)) && (iVar4 < 0xed)
           ) {
          bVar17 = SBORROW4((int)puVar8,(int)puVar6);
          iVar10 = (int)puVar8 - (int)puVar6;
          if ((int)puVar6 <= (int)puVar8) {
            bVar17 = SBORROW4((int)puVar16,(int)puVar8);
            iVar10 = (int)puVar16 - (int)puVar8;
            puVar6 = puVar16;
          }
          if (puVar8 != puVar6 && iVar10 < 0 == bVar17) {
            local_29c = local_29c ^ (byte)(1 << (7 - uVar7 & 0xff));
            local_29b = (byte)uVar7;
            fwupdate_select_draw(local_30,auStack_2a0,local_28);
            if (DAT_20800494 != '\0') {
              mainlink_send_e6(0);
            }
            break;
          }
        }
        uVar7 = uVar7 + 1 & 0xff;
      } while (uVar7 < 4);
    }
    mouse_right_get_event(local_48 + 0xc);
    if ((local_48[0xc] == '\x02' || local_48[0xc] == '\x04') ||
       (puVar8 = extraout_r1, local_48[0xc] == '\x05' || local_48[0xc] == '\x06')) {
      DAT_20808530 = 0;
      return 1;
    }
  }
  if (DAT_20808533 != '\0') {
    DAT_20808533 = '\0';
    local_4c = 0x10204080;
    switch(local_29b) {
    case 0:
    case 1:
    case 2:
    case 3:
      if (DAT_20800494 != '\0') {
        mainlink_send_e6(0);
      }
      puVar8 = (uint *)(uint)local_29c;
      bVar2 = *(byte *)((int)&local_4c + (uint)local_29b);
      if ((local_29c & bVar2) == 0) {
        local_29c = bVar2 | local_29c;
      }
      else {
        local_29c = local_29c & ~bVar2;
      }
      break;
    case 10:
      DAT_20808530 = 1;
      DAT_20808533 = 0;
      return 1;
    case 0xb:
      if (DAT_20800494 != '\0') {
        mainlink_send_e6(0);
        puVar8 = extraout_r1_00;
      }
      DAT_20808530 = 0;
    }
    if (local_29b == 10 || local_29b == 0xb) {
      return 1;
    }
  }
  sVar3 = DAT_20808536;
  uVar7 = param_2;
  if (DAT_20800494 != '\0') {
    if ((sVar11 != DAT_20808536) || (DAT_20808534 != 0)) {
      if ((sVar11 < DAT_20808536) || (DAT_20808534 < 0)) {
        uVar5 = local_29b + 1;
        if (uVar5 < 0xb) {
          if (uVar5 < 4) {
            puVar8 = &local_4c;
          }
          local_4c = 0x10204080;
          if (uVar5 < 4) {
            do {
              if ((*(byte *)((int)puVar8 + uVar5) & local_29d) != 0) goto LAB_2015af84;
              uVar5 = uVar5 + 1;
            } while ((int)uVar5 < 4);
          }
          if (local_29c != 0) goto LAB_2015af20;
        }
LAB_2015af4c:
        uVar7 = 0xb;
      }
      else {
        uVar12 = (uint)local_29b;
        if (uVar12 == 0xb) {
          if (local_29c == 0) {
            local_48[0] = 0x80;
            local_48[1] = 0x40;
            local_48[2] = 0x20;
            local_48[3] = 0x10;
            if (local_29d == 0) goto LAB_2015af4c;
            uVar5 = 3;
            do {
              if ((local_48[uVar5] & local_29d) != 0) goto LAB_2015af84;
              uVar5 = uVar5 - 1;
            } while (((int)uVar5 < 4) && (-1 < (int)uVar5));
          }
          else {
LAB_2015af20:
            uVar7 = 10;
          }
        }
        else {
          local_48[4] = 0x80;
          local_48[5] = 0x40;
          local_48[6] = 0x20;
          local_48[7] = 0x10;
          if (uVar12 == 10) {
            uVar5 = 3;
            uVar9 = uVar5;
          }
          else {
            uVar5 = uVar12 - 1;
            uVar9 = uVar5;
          }
          do {
            uVar7 = uVar12;
            if ((int)uVar5 < 0) break;
            if ((local_48[uVar5 + 4] & local_29d) != 0) goto LAB_2015af84;
            uVar5 = uVar5 - 1;
            uVar7 = param_2;
          } while ((int)uVar5 <= (int)uVar9);
        }
      }
      goto LAB_2015aea4;
    }
    goto LAB_2015aea8;
  }
  goto LAB_2015aec4;
LAB_2015af84:
  uVar7 = (int)(short)uVar5;
LAB_2015aea4:
  local_29b = (byte)uVar7;
LAB_2015aea8:
  DAT_20808534 = 0;
  fwupdate_select_draw(local_30,auStack_2a0,local_28);
  sVar11 = sVar3;
LAB_2015aec4:
  itron_tslp_tsk(0xffffffff);
  param_2 = uVar7;
  goto LAB_2015a994;
}


// ===== fwupdate_insert_sd_screen @ 2015afb0 (356 bytes)

/* INSERT FIRMWARE SD CARD screen (MAIN timeout path, docs/code/display/gui.md) */

void fwupdate_insert_sd_screen(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_278 [14];
  char cStack_26a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  fb_clear_rect(uVar2,0x132,0,800,0xae);
  uVar4 = 0;
  do {
    gui_draw_text_centered(uVar2,(&DAT_20808558)[uVar4],uVar4 * 0x20 + 0x132,400,0xf,0x20800b1c);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 3);
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  mainlink_get_frame60((uint)auStack_278);
  if ((cStack_26a != '\x01' && cStack_26a != '\x02') && (cStack_26a != '\x03')) {
    cStack_26a = '\x01';
  }
  sprintf(&uStack_38,"ERROR CODE : %03d",cStack_26a);
  gui_draw_text_centered(uVar2,(int)&uStack_38,0x192,400,0xf,0x20800b1c);
  gui_update_layers();
  key_task_resume();
  DAT_20808532 = 1;
  touch_wait_tap();
  if (DAT_20800493 == '\0') {
    bVar1 = usbkbd_last_key();
    fwupdate_set_hotkey(bVar1);
    iVar3 = fb_get_layer_addr(DAT_208085b8);
    fb_clear_rect(iVar3,0,0,800,0x1e0);
    iVar3 = fb_get_layer_addr(DAT_208085bc);
    fb_clear_rect(iVar3,0,0,800,0x1e0);
    gui_update_layers();
    bootloader_screen(param_1,&g_bootinfo);
    DAT_20808532 = 0;
  }
  return;
}


// ===== fwupdate_progress_screen @ 2015b134 (764 bytes)

/* progress rows, error screen, update_finish_reset */

void fwupdate_progress_screen(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  byte fwupdate_poll_ret;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  char local_270 [288];
  undefined1 auStack_150 [288];
  uint local_30;
  uint local_2c;
  
  local_30 = fb_get_layer_addr(DAT_208085bc);
  mouse_detach_post();
  DAT_20800496 = 1;
  DAT_20800495 = 0;
  fb_clear_rect(local_30,0,0,800,0x1e0);
  fb_fill_rect(local_30,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(local_30,4,400,&DAT_2016dc08);
  if (param_3 == 0) {
    param_3 = DAT_20808540;
  }
  gui_draw_text_centered(local_30,param_3,4,400,0xf,0x20800cac);
  gui_draw_text_centered(local_30,DAT_20808544,0x1a7,400,0xf,0x20800cac);
  local_2c = 0xff;
  __aeabi_memcpy4(local_270,param_1 + 8,0x120);
  __aeabi_memcpy4(auStack_150,param_1 + 8,0x120);
  gui_scope_draw_hold_set(1);
  while( true ) {
    fwupdate_poll_ret = fwupdate_poll(param_1 + 8);
    uVar4 = (uint)fwupdate_poll_ret;
    iVar2 = sd_state_bit6();
    if (iVar2 == 0) break;
    bVar5 = local_2c != uVar4;
    local_2c = uVar4;
    if ((bVar5) || (iVar2 = memcmp(param_1 + 8,auStack_150,0x120), iVar2 != 0)) {
      __aeabi_memcpy4(auStack_150,param_1 + 8,0x120);
      uVar3 = 0;
      do {
        iVar2 = param_1 + uVar3 * 0x48;
        gui_draw_text(local_30,iVar2 + 9,uVar3 * 0x44 + 0x41,0xc4,0xf,&DAT_20800b1c);
        cVar1 = *(char *)(iVar2 + 8);
        if (cVar1 == '\x04') {
          if (local_270[uVar3 * 0x48] != '\x04') {
            fb_clear_rect(local_30,uVar3 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          gui_draw_progress_bar
                    (local_30,uVar3 * 0x44 + 0x42,0x1dc,*(uint *)(iVar2 + 0x40) & 0xffff,
                     *(uint *)(iVar2 + 0x40));
        }
        else {
          if (cVar1 == '\x05') {
            if (local_270[uVar3 * 0x48] != '\x05') {
              fb_clear_rect(local_30,uVar3 * 0x44 + 0x42,0x1dc,0x144,0x19);
            }
            gui_draw_runs(local_30,uVar3 * 0x44 + 0x32,0x75,&DAT_203a56a4);
          }
          else if (cVar1 != local_270[uVar3 * 0x48]) {
            fb_clear_rect(local_30,uVar3 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          gui_draw_text(local_30,iVar2 + 0x1d,uVar3 * 0x44 + 0x43,0x1dc,0xf,&DAT_20800b1c);
        }
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 4);
      __aeabi_memcpy4(local_270,param_1 + 8,0x120);
      if (uVar4 != 0) goto LAB_2015b360;
      gui_update_layers();
      local_30 = fb_get_layer_addr(DAT_208085bc);
    }
  }
  uVar4 = 2;
LAB_2015b360:
  FUN_2010e4a0();
  if (uVar4 != 1) {
    update_error_screen();
  }
  system_reboot();
  return;
}


// ===== fwupdate_select_draw @ 2015b450 (708 bytes)

/* (ui, state, title): title bar, four target rows (name, status text, tick sprite 0x203A5684/94,
   cursor frame) and the OK / CANCEL buttons [fact] */

void fwupdate_select_draw(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  uVar6 = (uint)*(byte *)(param_2 + 5);
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  if (param_3 == 0) {
    param_3 = DAT_20808540;
  }
  gui_draw_text_centered(uVar2,param_3,4,400,0xf,0x20800cac);
  uVar3 = 0;
  do {
    uVar1 = 1 << (7 - uVar3 & 0xff);
    if ((*(byte *)(param_2 + 3) & uVar1) != 0) {
      iVar5 = uVar3 * 0x44 + 0x32;
      fb_clear_rect(uVar2,iVar5,0x75,0x78,0x43);
      if ((*(byte *)(param_2 + 4) & uVar1) == 0) {
        puVar4 = (undefined2 *)&DAT_203a5684;
        *(undefined4 *)(param_1 + uVar3 * 0x48 + 0x3c) = 0;
      }
      else {
        puVar4 = &DAT_203a5694;
        *(undefined4 *)(param_1 + uVar3 * 0x48 + 0x3c) = 1;
      }
      gui_draw_runs(uVar2,iVar5,0x75,puVar4);
      if (uVar3 == uVar6) {
        fb_draw_round_frame_wrap(uVar2,iVar5,0x75,*puVar4,puVar4[1],3);
      }
    }
    iVar5 = param_1 + uVar3 * 0x48;
    gui_draw_text(uVar2,iVar5 + 9,uVar3 * 0x44 + 0x41,0xc4,0xf,&DAT_20800b1c);
    gui_draw_text(uVar2,iVar5 + 0x1d,uVar3 * 0x44 + 0x43,0x1dc,0xf,&DAT_20800b1c);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 4);
  gui_button_draw_shadow(uVar2,0x19a,0xfa,2);
  if (*(char *)(param_2 + 4) == '\0') {
    gui_draw_runs(uVar2,0x1a6,0x10f,&DAT_20255114);
  }
  else {
    gui_draw_runs(uVar2,0x1a6,0x10f,&DAT_20254600);
  }
  if (uVar6 == 10) {
    fb_draw_round_frame_wrap(uVar2,0x19a,0xfa,*DAT_20802294,DAT_20802294[1],3);
  }
  if (DAT_20800494 != '\0') {
    gui_button_draw_shadow(uVar2,0x19a,0x1a4,2);
    gui_draw_runs(uVar2,0x1a6,0x1b9,&DAT_20251ec8);
    if (uVar6 == 0xb) {
      fb_draw_round_frame_wrap(uVar2,0x19a,0x1a4,*DAT_20802294,DAT_20802294[1],3);
    }
  }
  return;
}


// ===== fwupdate_confirm_draw @ 2015b748 (392 bytes)

/* (ui, state): "UPDATE?" box with the YES / NO buttons and the cursor frame [fact] */

void fwupdate_confirm_draw(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  cVar1 = *(char *)(param_2 + 5);
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  gui_draw_runs(uVar2,8,0x168,&DAT_203a56b4);
  gui_draw_text_centered(uVar2,0x20428153,0xf0,400,0xf,0x20800cac);
  gui_button_draw_shadow(uVar2,0x19a,0xfa,2);
  gui_draw_runs(uVar2,0x1a6,0x10f,&DAT_20253aec);
  if (cVar1 == '\n') {
    fb_draw_round_frame_wrap(uVar2,0x19a,0xfa,*DAT_20802294,DAT_20802294[1],3);
  }
  gui_button_draw_shadow(uVar2,0x19a,0x1a4,2);
  gui_draw_runs(uVar2,0x1a6,0x1b9,&DAT_20251ec8);
  if (cVar1 == '\v') {
    fb_draw_round_frame_wrap(uVar2,0x19a,0x1a4,*DAT_20802294,DAT_20802294[1],3);
  }
  return;
}


// ===== scope3d_line_render @ 2015b8f8 (176 bytes)

/* (buf, i, y, x0, mode, ...): one 3DSS line: levels (FUN_201343c4), colour ramp scope_ramp_get,
   markers scope3d_line_markers, scale scope3d_vscale, then scope3d_draw_line at x = 5i + x0, width
   0x317 - 10i (gui.md 3DSS step 4) [fact] */

void scope3d_line_render(undefined4 param_1,int param_2,undefined4 param_3,int param_4,
                        undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_358 [804];
  undefined4 local_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  local_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  iStack_28 = param_4;
  uVar1 = FUN_201343c4(param_2,param_5,auStack_358);
  uVar2 = scope_ramp_get(param_5);
  uVar3 = scope3d_line_markers(param_2);
                    /* entry i of the vertical scale table 0x20450278 [doc] */
  uVar4 = scope3d_vscale(param_2,param_5);
                    /* line i at x = 5i+4, width 791-10i [doc, inference] */
  scope3d_draw_line(local_34,param_3,param_2 * 5 + param_4 & 0xffff,param_2 * -10 + 0x317U & 0xffff,
                    uVar4,auStack_358 + param_2 * 5,uVar1,param_2,uVar2,uVar3,param_6);
  return;
}


// ===== scope3d_history_clear @ 2015b9a8 (28 bytes)

/* Resets the history (0x20134310) and clears 0x6B080 bytes of the 3D buffer *0x208085B4 [fact] */

void scope3d_history_clear(void)

{
  scope_history_reset();
  __aeabi_memclr_veneer(DAT_208085b4,0x6b080);
  return;
}


// ===== scope3d_render_large @ 2015b9cc (240 bytes)

/* mode 8: 29 lines, 222/274 rows */

void scope3d_render_large(void *param_1,uint n,int param_3,ushort *param_4,uint param_5)

{
  short sVar1;
  int i;
  code *pcVar2;
  int unaff_r7;
  bool bVar3;
  ulonglong __aeabi_idivmod_ret;
  undefined4 local_28;
  
  bVar3 = param_3 == 0;
  if (!bVar3) {
    unaff_r7 = (int)param_1 + 0x7c;
  }
  local_28 = 0;
  if (bVar3) {
    unaff_r7 = (int)param_1 + 4;
  }
  if (bVar3) {
    pcVar2 = scope3d_line_render;
  }
  else {
    pcVar2 = scope3d_line_render_alt;
  }
  if (3 < *param_4) {
    local_28 = CONCAT22(param_4[1],*param_4);
  }
  scope_history_push(DAT_208085b0,&local_28);
  scope3d_add_line(8,DAT_208085b0,param_3);
  __aeabi_idivmod_ret = __aeabi_idivmod(n,(uint)DAT_208085b0);
  if ((int)(__aeabi_idivmod_ret >> 0x20) == 0) {
                    /* every N frames [doc, inference] */
    scope3d_redraw_history(8,param_3);
  }
                    /* zero fill with alignment fix-up, 32-byte blocks [doc] */
  __aeabi_memclr(*(undefined4 *)param_1,0x6b080);
  i = 1;
  do {
    (*pcVar2)(*(undefined4 *)param_1,i,*(uint *)(unaff_r7 + i * 4) & 0xffff,4,8,0);
    i = i + 1;
  } while (i < 0x1e);
  if (param_3 == 0) {
    sVar1 = 0xde;
  }
  else {
    sVar1 = 0x112;
  }
  memcpy(param_5,*(undefined4 *)param_1,sVar1 * 0x640);
  return;
}


// ===== scope3d_line_render_alt @ 2015bacc (176 bytes)

/* Identical copy of scope3d_line_render that scope3d_render_large uses when its third argument is
   non-zero [fact] */

void scope3d_line_render_alt
               (undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
               undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_358 [804];
  undefined4 local_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  local_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  iStack_28 = param_4;
  uVar1 = FUN_201343c4(param_2,param_5,auStack_358);
  uVar2 = scope_ramp_get(param_5);
  uVar3 = scope3d_line_markers(param_2);
                    /* entry i of the vertical scale table 0x20450278 [doc] */
  uVar4 = scope3d_vscale(param_2,param_5);
                    /* line i at x = 5i+4, width 791-10i [doc, inference] */
  scope3d_draw_line(local_34,param_3,param_2 * 5 + param_4 & 0xffff,param_2 * -10 + 0x317U & 0xffff,
                    uVar4,auStack_358 + param_2 * 5,uVar1,param_2,uVar2,uVar3,param_6);
  return;
}


// ===== scope3d_render_small @ 2015bb7c (236 bytes)

/* mode 9: 14 lines, 104/156 rows */

void scope3d_render_small(void *param_1,uint n,int param_3,ushort *param_4,uint param_5)

{
  short unaff_r4;
  int i;
  int unaff_r6;
  undefined4 uVar1;
  bool bVar2;
  ulonglong __aeabi_idivmod_ret;
  undefined4 local_28;
  
  bVar2 = param_3 != 0;
  if (bVar2) {
    unaff_r6 = (int)param_1 + 0x130;
  }
  local_28 = 0;
  if (bVar2) {
    unaff_r4 = 0x9c;
  }
  if (!bVar2) {
    unaff_r6 = (int)param_1 + 0xf4;
    unaff_r4 = 0x68;
  }
  if (3 < *param_4) {
    local_28 = CONCAT22(param_4[1],*param_4);
  }
  scope_history_push(DAT_208085b0,&local_28);
  scope3d_add_line(9,DAT_208085b0,param_3);
  __aeabi_idivmod_ret = __aeabi_idivmod(n,(uint)DAT_208085b0);
  if ((int)(__aeabi_idivmod_ret >> 0x20) == 0) {
                    /* every N frames [doc, inference] */
    scope3d_redraw_history(9,param_3);
  }
  uVar1 = *(undefined4 *)param_1;
                    /* zero fill with alignment fix-up, 32-byte blocks [doc] */
  __aeabi_memclr(uVar1,unaff_r4 * 0x640);
  i = 1;
  do {
    scope3d_line_render(*(undefined4 *)param_1,i,*(uint *)(unaff_r6 + i * 4) & 0xffff,4,9,0);
    i = i + 1;
  } while (i < 0xf);
  memcpy(param_5,uVar1,unaff_r4 * 0x640);
  return;
}


// ===== scope3d_draw_line @ 2015bc6c (484 bytes)

/* WARNING: Type propagation algorithm not settling */
/* line i at x = 5i+4, width 791-10i */

void scope3d_draw_line(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                      ushort *param_7,int param_8,int param_9,int *param_10,int param_11)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  ushort *puVar4;
  short *psVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  short local_400 [240];
  short local_220 [240];
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int iStack_30;
  int iStack_2c;
  int local_28;
  
  local_28 = param_4;
  iStack_2c = param_3;
  iStack_30 = param_2;
  local_34 = param_1;
  local_38 = param_2 * 800;
  uVar6 = (uint)param_7[1];
  uVar1 = *param_7;
  iVar11 = *(int *)(param_7 + 2);
  iVar3 = 0;
  iVar9 = *(int *)(param_9 + 4);
  if (uVar6 != 0) {
    do {
      iVar8 = (uVar6 - param_5) + iVar3;
      psVar5 = local_400 + iVar3;
      iVar3 = iVar3 + 1;
      *psVar5 = *(short *)(iVar11 + (iVar8 * (uint)uVar1 + param_8) * 2);
    } while (iVar3 < (int)uVar6);
  }
  iVar3 = 0;
  if (uVar6 != 0) {
    do {
      iVar11 = (uVar6 - param_5) + iVar3;
      psVar5 = local_220 + iVar3;
      iVar3 = iVar3 + 1;
      *psVar5 = *(short *)(iVar9 + (iVar11 * (uint)uVar1 + param_8) * 2);
    } while (iVar3 < (int)uVar6);
  }
  iVar3 = 0;
  local_3c = local_28 + param_3;
  if (param_3 < local_3c) {
    local_40 = param_11 + -1;
    do {
      bVar2 = false;
      iVar8 = 0;
      iVar9 = param_5 - (uint)*(byte *)(param_6 + iVar3);
      iVar11 = local_38 + iVar9 * 800;
      puVar7 = (ushort *)0x0;
      if (0 < *param_10) {
        do {
          puVar4 = (ushort *)(param_10 + iVar8 + 1);
          if (((((puVar7 == (ushort *)0x0) || (*puVar7 != *puVar4)) ||
               (puVar7[1] != *(ushort *)((int)param_10 + iVar8 * 4 + 6))) &&
              ((uVar6 = (uint)*(ushort *)((int)param_10 + iVar8 * 4 + 6), uVar6 != 0 &&
               (puVar7 = puVar4, (int)((uint)*puVar4 + param_11) <= param_3)))) &&
             (param_3 <= (int)(param_11 + -1 + uVar6 + *puVar4))) {
            bVar2 = true;
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < *param_10);
      }
      while ((iVar9 < param_5 &&
             (psVar5 = (short *)(local_34 + (param_3 + iVar11) * 2), *psVar5 == 0))) {
        iVar11 = iVar11 + 800;
        if (bVar2) {
          psVar10 = local_220;
        }
        else {
          psVar10 = local_400;
        }
        psVar10 = psVar10 + iVar9;
        iVar9 = iVar9 + 1;
        *psVar5 = *psVar10;
      }
      param_3 = param_3 + 1;
      iVar3 = iVar3 + 1;
    } while (param_3 < local_3c);
  }
  return;
}


// ===== touch_hit_table @ 2015bf88 (184 bytes)

/* first entry of u16 {x, y, w, h, code} [n] containing (x, y), else 0x1FF [fact] (#212) */

undefined2 touch_hit_table(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = 0;
  if (0 < param_4) {
    do {
      puVar2 = (ushort *)(param_3 + uVar6 * 10);
      uVar1 = (uint)*puVar2;
      uVar3 = puVar2[2] + uVar1;
      uVar4 = (uint)puVar2[1];
      uVar5 = puVar2[3] + uVar4 & 0xffff;
      if ((uVar6 == 0x20) &&
         ((&DAT_20801d73)[(uint)DAT_20800465 * 0x2f] != -0x1e &&
          (&DAT_20801d73)[(uint)DAT_20800465 * 0x2f] != -0x1d)) {
        uVar1 = uVar1 + 0x24 & 0xffff;
      }
      bVar7 = param_1 <= uVar1;
      if (uVar1 <= param_1) {
        bVar7 = (uVar3 & 0xffff) <= param_1;
      }
      if (!bVar7) {
        uVar1 = uVar4;
        if (uVar4 <= param_2) {
          uVar1 = uVar5;
        }
        if ((uVar4 <= param_2 && param_2 <= uVar5) && param_2 != uVar1) {
          return *(undefined2 *)(param_3 + uVar6 * 10 + 8);
        }
      }
      uVar6 = uVar6 + 1 & 0xff;
    } while ((int)uVar6 < param_4);
  }
  return 0x1ff;
}


// ===== touch_hit_test @ 2015c048 (912 bytes)

/* (x, y) -> soft key code per screen 0x208F0B2A, 0x1FF = none; main screen: 0x20192748 (0x1011
   filter graph), 0x2042007C, 0x20350AC8, 0x2021CC58, 0x2016E15C, 0x201AC45C, 0x2016E304 [fact]
   (#212) */

int touch_hit_test(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  byte bVar5;
  undefined4 uVar6;
  byte gui_frame_dsp_knob_val;
  
  if (gui_frame.cmd == 0x40) {
                    /* touch_hit_test for screen 0x40 [doc] */
    iVar4 = touch_hit_text_list(param_1,param_2);
switchD_2015c074_caseD_32:
    if (iVar4 != 0x1ff) {
      return iVar4;
    }
  }
  else {
    if (gui_frame.cmd < 0x41) {
      iVar4 = 0x1ff;
      switch(gui_frame.cmd) {
      case 0x30:
                    /* touch_hit_test for screen 0x30 [doc] */
        iVar4 = touch_hit_select_popup(param_1,param_2,gui_frame.payload[0]);
        break;
      case 0x31:
        iVar4 = FUN_20130998();
        if (iVar4 == 0) {
          return 0xff;
        }
        goto LAB_2015c240;
      case 0x34:
        iVar4 = touch_hit_table(param_1,param_2,&DAT_20266736,4);
        break;
      case 0x37:
        iVar4 = touch_hit_table(param_1,param_2,&DAT_2080188c,0x23);
        if ((iVar4 == 0x10e7) && (gui_frame.payload[0xe0] == 0x35)) {
          return 0x10e9;
        }
        break;
      case 0x39:
        if ((gui_frame.payload[0x19] & 3) == 0) {
          iVar4 = touch_hit_table(param_1,param_2,&DAT_2016ebdc,0xb);
        }
        else if ((gui_frame.payload[0x19] & 3) == 1) {
          iVar4 = touch_hit_table(param_1,param_2,&DAT_2016ec4a,0xb);
        }
        else {
          iVar4 = touch_hit_table(param_1,param_2,&DAT_20376520,0xb);
        }
        break;
      case 0x3a:
        iVar4 = touch_hit_table(param_1,param_2,&DAT_2016e1c4,0xd);
      }
      goto switchD_2015c074_caseD_32;
    }
    if (gui_frame.cmd == 0x50) {
      iVar4 = touch_hit_table(param_1,param_2,(&PTR_DAT_20802198)[DAT_20800464],0x30);
      goto switchD_2015c074_caseD_32;
    }
    if (gui_frame.cmd < 0x51) {
      if (gui_frame.cmd == 0x41) {
        iVar4 = touch_hit_table(param_1,param_2,&DAT_2016db98,0xb);
      }
      else {
        if (gui_frame.cmd != 0x43) goto LAB_2015c240;
                    /* touch_hit_test for screen 0x43 [doc] */
        iVar4 = touch_hit_sd_menu(param_1,param_2);
      }
      goto switchD_2015c074_caseD_32;
    }
    if (gui_frame.cmd == 0x70) {
                    /* touch_hit_test for screen 0x70 [doc] */
      iVar4 = touch_hit_dialog(param_1,param_2);
      goto switchD_2015c074_caseD_32;
    }
    if (gui_frame.cmd == 0x7c) {
      return 0xff;
    }
  }
LAB_2015c240:
  gui_frame_dsp_knob_val = gui_frame.dsp_knob;
  uVar1 = (uint)gui_frame.scope_flags;
  uVar2 = (uint)gui_frame.dsp_knob;
  uVar3 = (uint)gui_frame.scope_cfg[0];
  bVar5 = gui_frame.scope_cfg[1] & 0x7f;
  uVar6 = param_2;
  if ((((int)(uVar1 << 0x1a) < 0) || (gui_frame.cmd == 0x37)) ||
     (iVar4 = touch_hit_rect(param_1,param_2,&DAT_20192748,0,param_1,param_2,unaff_r4,unaff_r5,
                             unaff_r6), iVar4 == 0x1ff)) {
    iVar4 = touch_hit_rect(param_1,param_2,&DAT_2042007c,0,param_1,uVar6,unaff_r4,unaff_r5,unaff_r6)
    ;
  }
  if (iVar4 == 0x1ff) {
    iVar4 = touch_hit_rect(param_1,param_2,&DAT_20350ac8,0,param_1,uVar6,unaff_r4,unaff_r5,unaff_r6)
    ;
  }
  if (iVar4 == 0x1ff) {
    iVar4 = touch_hit_table(param_1,param_2,&DAT_2021cc58,3);
  }
  if (((iVar4 == 0x1ff) || (gui_frame.cmd != 0x30)) || (3 < gui_frame.payload[0] - 1)) {
    if (iVar4 != 0x1ff) goto LAB_2015cc24;
  }
  else {
    iVar4 = 0x1ff;
  }
  if ((-1 < (int)(uVar1 << 0x1a)) && (gui_frame.cmd != 0x37)) {
    iVar4 = touch_hit_table(param_1,param_2,&DAT_2016e15c,4);
  }
LAB_2015cc24:
  if ((((iVar4 == 0x1ff) && ((char)gui_frame_dsp_knob_val < '\0')) &&
      (iVar4 = touch_hit_table(param_1,param_2,&DAT_201ac45c,5), iVar4 == 0x10c3)) &&
     ((int)(uVar2 << 0x1d) < 0)) {
    iVar4 = 0x10c4;
  }
  if (DAT_20800483 == '\0') {
    if (iVar4 == 0x1ff) {
      iVar4 = touch_hit_scope(param_1,param_2);
    }
    if (iVar4 == 0x1ff) {
      iVar4 = touch_hit_table(param_1,param_2,&DAT_2016e304,6);
      if (iVar4 == 0x1000) {
        if ((uVar3 & 0x7f) == 0xb) {
          return 0x1008;
        }
        iVar4 = (uVar3 & 0x7f) + 0x1000;
      }
      if (iVar4 == 0x1003 && bVar5 == 0xc) {
        iVar4 = 0x1009;
      }
    }
  }
  return iVar4;
}


// ===== FUN_2015c278 @ 2015c278 (84 bytes)

bool FUN_2015c278(void)

{
  uint strcmp_ret;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  memcpy(local_20,0x208f0bc7,0x14);
  strcmp_ret = strcmp((uint *)"EXTENSION SETTING   ",local_20);
  return strcmp_ret == 0;
}


// ===== FUN_2015c2d4 @ 2015c2d4 (112 bytes)

bool FUN_2015c2d4(int param_1)

{
  uint strcmp_ret;
  uint local_20 [7];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  memcpy(local_20,(param_1 - 0x1128U & 0xff) * 0x2d + 0x208f0c46,0x15);
  strcmp_ret = strcmp((uint *)"FIRMWARE UPDATE      ",local_20);
  return strcmp_ret == 0;
}


// ===== touch_hit_text_list @ 2015c34c (224 bytes)

/* touch_hit_test for screen 0x40 (text list): soft key of the touched row or button (rows through
   touch_hit_text_list_rows) [fact for the dispatch] */

int touch_hit_text_list(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_2015c978();
  if (iVar1 == 0x1ff) {
    iVar1 = FUN_2015ccf8(param_1,param_2,&DAT_202665ec,1);
  }
  if (iVar1 == 0x1ff) {
    iVar1 = FUN_2015ccf8(param_1,param_2,&DAT_202665ec,3);
  }
                    /* row index from [doc] */
  if ((((iVar1 == 0x1ff) && (iVar1 = touch_hit_text_list_rows(param_1,param_2), iVar1 != 0x1ff)) &&
      (iVar2 = FUN_2015c278(), iVar2 != 0)) &&
     ((iVar2 = FUN_2015c2d4(iVar1), iVar2 != 0 && (DAT_208000b2 == '\0')))) {
    DAT_20800494 = 1;
  }
  if (iVar1 == 0x1ff) {
    iVar1 = touch_hit_table(param_1,param_2,&DAT_202665d8,2);
  }
  if (iVar1 == 0x1ff) {
    iVar1 = 0xff;
  }
  return iVar1;
}


// ===== touch_hit_select_popup @ 2015c43c (376 bytes)

/* touch_hit_test for screen 0x30 (selection popup, payload byte 0 = popup type) [fact for the
   dispatch] */

undefined4 touch_hit_select_popup(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 0:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2016dd44,7);
    return uVar1;
  case 1:
  case 2:
  case 3:
  case 4:
    break;
  case 5:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2016e734,0x11);
    return uVar1;
  case 6:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2016e6a4,0xb);
    return uVar1;
  case 7:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2016da0c,0x10);
    return uVar1;
  case 8:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2024bc94,0x10);
    return uVar1;
  case 9:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2016d358,4);
    return uVar1;
  case 10:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2016dffc,0xd);
    return uVar1;
  case 0xb:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2016e530,0xd);
    return uVar1;
  case 0xc:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2016ea38,0xd);
    return uVar1;
  case 0xd:
    uVar1 = touch_hit_table(param_1,param_2,&DAT_2016ed68,7);
    return uVar1;
  default:
    return 0x1ff;
  }
  uVar1 = 0x1ff;
  if (param_3 == 1) {
    uVar1 = FUN_2015cfb4(param_1,param_2,&DAT_202ca3a0,4,gui_frame.payload[1],gui_frame.payload[2]);
    return uVar1;
  }
  if (param_3 != 2) {
    if (param_3 == 3) {
      uVar1 = FUN_2015cfb4(param_1,param_2,&DAT_202ca418,2,gui_frame.payload[1],gui_frame.payload[2]
                          );
      return uVar1;
    }
    if (param_3 == 4) {
      uVar1 = FUN_2015cfb4(param_1,param_2,&DAT_202ca3e6,5,gui_frame.payload[1],gui_frame.payload[2]
                          );
    }
    return uVar1;
  }
  uVar1 = FUN_2015cfb4(param_1,param_2,&DAT_202ca3c8,3,gui_frame.payload[1],gui_frame.payload[2]);
  return uVar1;
}


// ===== touch_hit_scope @ 2015c558 (304 bytes)

/* Touch hit test of the scope area: hit table chosen by layout (byte 1) and scope mode (byte 2),
   expanded flag; input.md lists it for soft keys 0x1016..0x1019 [fact] */

undefined4 touch_hit_scope(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  
  bVar3 = gui_frame.byte1;
  if (1 < gui_frame.byte1) {
    bVar3 = 1;
  }
  iVar1 = (int)((uint)gui_frame.scope_flags << 0x1a) >> 0x1f;
  if (bVar3 == 0) {
    if ((gui_frame.vfo_flags & 4) == 0) {
      switch(gui_frame.scope_mode) {
      case 0:
      case 1:
      case 2:
        uVar2 = touch_hit_table(param_1,param_2,&UNK_20302c8a + iVar1 * -0x50,4);
        return uVar2;
      case 3:
      case 6:
      case 9:
        uVar2 = touch_hit_table(param_1,param_2,&UNK_20302dca + iVar1 * -0x3c,2);
        return uVar2;
      case 4:
      case 7:
      case 10:
        uVar2 = touch_hit_table(param_1,param_2,&UNK_20302dde + iVar1 * -0x3c,2);
        return uVar2;
      case 5:
      case 8:
      case 0xb:
        uVar2 = touch_hit_table(param_1,param_2,&UNK_20302df2 + iVar1 * -0x3c,2);
        return uVar2;
      default:
        return 0x1ff;
      }
    }
  }
  else {
    if (bVar3 != 1) {
      return 0x1ff;
    }
    if ((gui_frame.vfo_flags & 4) == 0) {
      switch(gui_frame.scope_mode) {
      case 0:
      case 1:
      case 2:
        uVar2 = touch_hit_table(param_1,param_2,&UNK_20302cb2 + iVar1 * -0x50,4);
        return uVar2;
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
        uVar2 = touch_hit_table(param_1,param_2,&UNK_20302d52 + iVar1 * -0x50,4);
        return uVar2;
      default:
        return 0x1ff;
      }
    }
  }
  uVar2 = touch_hit_scope_drag(param_1,param_2,&DAT_203a53d4,2);
  return uVar2;
}


// ===== touch_hit_rect @ 2015c6fc (84 bytes)

/* one u16 {x, y, w, h, code} rectangle (r3 = 1: y from 0) [fact] (#212) */

ushort touch_hit_rect(uint param_1,uint param_2,ushort *param_3,int param_4)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar1 = (uint)*param_3;
  uVar2 = 0x1ff;
  uVar4 = (uint)param_3[1];
  uVar3 = param_3[3] + uVar4;
  if (param_4 == 1) {
    uVar4 = 0;
  }
  bVar5 = param_1 <= uVar1;
  if (uVar1 <= param_1) {
    bVar5 = (param_3[2] + uVar1 & 0xffff) <= param_1;
  }
  if (!bVar5) {
    bVar5 = param_2 <= uVar4;
    if (uVar4 <= param_2) {
      bVar5 = (uVar3 & 0xffff) <= param_2;
    }
    if (!bVar5) {
      uVar2 = param_3[4];
    }
  }
  return uVar2;
}


// ===== touch_hit_sd_menu @ 2015c750 (500 bytes)

/* touch_hit_test for screen 0x43 (SD-card menu) [fact for the dispatch] */

int touch_hit_sd_menu(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  switch(DAT_208f0d6a) {
  case 0x41:
  case 0x43:
    if (DAT_208f0d6b != '\x10') {
      iVar2 = touch_hit_table(param_1,param_2,&DAT_2026668c,10);
      return iVar2;
    }
    break;
  case 0x42:
  case 0x44:
    if (DAT_208f0d6b != '\x04' && DAT_208f0d6b != '\x10') {
      iVar2 = touch_hit_table(param_1,param_2,&DAT_20266628,10);
      return iVar2;
    }
    break;
  case 0x45:
    iVar2 = touch_hit_table(param_1,param_2,&DAT_202666f0,3);
    return iVar2;
  default:
    return 0x1ff;
  case 0x47:
    iVar2 = 0x1ff;
    if (DAT_208f0d6b == '\x01') {
      uVar3 = 0;
      do {
        uVar5 = uVar3 * 0x44 + 0x32;
        bVar6 = param_1 < 0x76;
        if (0x74 < param_1) {
          bVar6 = 0xec < param_1;
        }
        uVar4 = uVar3 * 0x44 + 0x75;
        if (!bVar6) {
          uVar1 = uVar5;
          if (uVar5 <= param_2) {
            uVar1 = uVar4;
          }
          if ((uVar5 <= param_2 && param_2 <= uVar4) && param_2 != uVar1) {
            iVar2 = uVar3 + 0x1160;
            break;
          }
        }
        uVar3 = uVar3 + 1 & 0xff;
      } while (uVar3 < 4);
    }
    else {
      iVar2 = 0x1ff;
      if (DAT_208f0d6b != '\x02') goto LAB_2015d19c;
    }
    if (iVar2 == 0x1ff) {
      bVar6 = param_1 < 0xfb;
      uVar3 = DAT_20802294[1] + 0x19a & 0xffff;
      if (0xf9 < param_1) {
        bVar6 = (*DAT_20802294 + 0xfa & 0xffff) <= param_1;
      }
      if (!bVar6) {
        uVar5 = 0x19a;
        if (0x199 < param_2) {
          uVar5 = uVar3;
        }
        if ((0x199 < param_2 && param_2 <= uVar3) && param_2 != uVar5) {
          if (DAT_208f0d6b == '\x01') {
            iVar2 = 0x1165;
          }
          else {
            iVar2 = 0x116a;
          }
          return iVar2;
        }
      }
    }
    if (iVar2 == 0x1ff) {
      bVar6 = param_1 < 0x1a5;
      uVar3 = DAT_20802294[1] + 0x19a & 0xffff;
      if (0x1a3 < param_1) {
        bVar6 = (*DAT_20802294 + 0x1a4 & 0xffff) <= param_1;
      }
      if (!bVar6) {
        uVar5 = 0x19a;
        if (0x199 < param_2) {
          uVar5 = uVar3;
        }
        if ((0x199 < param_2 && param_2 <= uVar3) && param_2 != uVar5) {
          if (DAT_208f0d6b == '\x01') {
            iVar2 = 0x1166;
          }
          else {
            iVar2 = 0x116b;
          }
          return iVar2;
        }
      }
    }
LAB_2015d19c:
    if (iVar2 == 0x1ff) {
      iVar2 = 0xff;
    }
    return iVar2;
  case 0x48:
    iVar2 = touch_hit_table(param_1,param_2,&DAT_2026670e,3);
    return iVar2;
  }
  iVar2 = touch_hit_table(param_1,param_2,&DAT_2026672c,1);
  return iVar2;
}


// ===== touch_hit_scope_drag @ 2015c81c (344 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* (x, y, table, n): scope-area touch with drag handling: sends E6 frames (mainlink_send_e6 0 / 2 /
   step) while the finger moves; called by touch_hit_scope [fact for the calls] */

undefined4 touch_hit_scope_drag(uint param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  ushort *puVar8;
  bool bVar9;
  
  sVar6 = 0x1ff;
  if (_DAT_208f4bf0 == _DAT_208f4bf2) {
    return 0x1ff;
  }
  _DAT_208f4bf2 = _DAT_208f4bf0;
  uVar7 = 0;
  if (param_4 < 1) goto LAB_2015c958;
  do {
    puVar8 = (ushort *)(param_3 + uVar7 * 10);
    uVar5 = (uint)*puVar8;
    bVar9 = param_1 <= uVar5;
    uVar4 = (uint)puVar8[1];
    if (uVar5 <= param_1) {
      bVar9 = (puVar8[2] + uVar5 & 0xffff) <= param_1;
    }
    uVar5 = puVar8[3] + uVar4 & 0xffff;
    if (!bVar9) {
      uVar1 = uVar4;
      if (uVar4 <= param_2) {
        uVar1 = uVar5;
      }
      if ((uVar4 <= param_2 && param_2 <= uVar5) && param_2 != uVar1) {
        sVar6 = *(short *)(param_3 + uVar7 * 10 + 8);
        break;
      }
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while ((int)uVar7 < param_4);
  if (sVar6 == 0x16c) {
    if (DAT_208f4bef == '\0') goto LAB_2015c950;
    if ((uint)DAT_208f4899 <= (uint)DAT_208f489c) {
      mainlink_send_e6(2);
      goto LAB_2015c958;
    }
    iVar3 = (uint)DAT_208f4899 - (uint)DAT_208f489c;
    if (iVar3 <= (int)(uint)DAT_208f489e) {
      DAT_208f489e = (byte)iVar3;
      mainlink_send_e6(2);
      goto LAB_2015c958;
    }
    DAT_208f489e = DAT_208f489e + 1;
    bVar2 = 0;
  }
  else {
    if (sVar6 != 0x16d) goto LAB_2015c958;
    if (DAT_208f489e != 0) {
      mainlink_send_e6(0);
      DAT_208f489e = DAT_208f489e - 1;
      goto LAB_2015c958;
    }
LAB_2015c950:
    bVar2 = 2;
  }
  mainlink_send_e6(bVar2);
LAB_2015c958:
  if (0xf < DAT_208f489e) {
    DAT_208f489e = 0xf;
  }
  return 0x1ff;
}


// ===== FUN_2015c978 @ 2015c978 (144 bytes)

undefined2 FUN_2015c978(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  bool bVar7;
  
  puVar5 = &DAT_2016dc78;
  uVar2 = 0;
  if (gui_frame.payload[0] == 1) {
    puVar5 = &DAT_20266588;
  }
  do {
    puVar3 = puVar5 + uVar2 * 5;
    uVar4 = (uint)*puVar3;
    bVar7 = param_1 <= uVar4;
    uVar6 = (uint)puVar3[1];
    if (uVar4 <= param_1) {
      bVar7 = (puVar3[2] + uVar4 & 0xffff) <= param_1;
    }
    uVar4 = puVar3[3] + uVar6 & 0xffff;
    if (!bVar7) {
      uVar1 = uVar6;
      if (uVar6 <= param_2) {
        uVar1 = uVar4;
      }
      if ((uVar6 <= param_2 && param_2 <= uVar4) && param_2 != uVar1) {
        return puVar5[uVar2 * 5 + 4];
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
    if (7 < uVar2) {
      return 0x1ff;
    }
  } while( true );
}


// ===== touch_hit_dialog @ 2015ca14 (244 bytes)

/* touch_hit_test for screen 0x70 (dialog / confirm screen) [fact for the dispatch] */

int touch_hit_dialog(uint param_1,uint param_2)

{
  ushort be16_load_ret;
  ushort be16_load_ret_2;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar5 = 0x1ff;
  uVar4 = (uint)gui_frame.payload[1];
  be16_load_ret = be16_load(gui_frame.payload + 4);
  be16_load_ret_2 = be16_load(gui_frame.payload + 6);
  if (uVar4 < 3) {
    uVar2 = 0;
    if ((byte)(&DAT_20800650)[uVar4] != 0) {
      do {
        uVar6 = (uint)be16_load_ret_2 + (uint)*(ushort *)(&DAT_20266760 + uVar4 * 4) & 0xffff;
        uVar3 = (uint)*(ushort *)(&DAT_2016dcd4 + uVar2 * 4 + uVar4 * 8) + (uint)be16_load_ret &
                0xffff;
        bVar7 = param_1 <= uVar3;
        uVar1 = (uint)(*(ushort **)(&DAT_2080228c + (uint)(byte)(&DAT_20800654)[uVar4] * 4))[1] +
                ((uint)be16_load_ret_2 + (uint)*(ushort *)(&DAT_20266760 + uVar4 * 4) & 0xffff) &
                0xffff;
        if (uVar3 <= param_1) {
          bVar7 = (**(ushort **)(&DAT_2080228c + (uint)(byte)(&DAT_20800654)[uVar4] * 4) + uVar3 &
                  0xffff) <= param_1;
        }
        if (!bVar7) {
          uVar3 = uVar6;
          if (uVar6 <= param_2) {
            uVar3 = uVar1;
          }
          if ((uVar6 <= param_2 && param_2 <= uVar1) && param_2 != uVar3) {
            iVar5 = uVar2 + 0x10fe;
            break;
          }
        }
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < (byte)(&DAT_20800650)[uVar4]);
      if (iVar5 != 0x1ff) {
        return iVar5;
      }
    }
    iVar5 = 0xff;
  }
  else {
    iVar5 = 0x10fe;
  }
  return iVar5;
}


// ===== FUN_2015ccf8 @ 2015ccf8 (208 bytes)

ushort FUN_2015ccf8(uint param_1,uint param_2,ushort *param_3,int param_4)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  bool bVar6;
  
  iVar2 = 0;
  iVar5 = 0;
  uVar4 = 0x1ff;
  if (param_4 == 1) {
    iVar5 = 0x32;
  }
  if ((param_4 != 1) && (param_4 == 3)) {
    iVar2 = 0x32;
    iVar5 = 0x32;
  }
  if (((gui_frame.payload[3] & 0xf) == 3) && (DAT_2080060a <= param_2)) {
    puVar1 = param_3 + param_4 * 5;
    uVar3 = ((uint)*param_3 + (uint)*puVar1) - iVar2 & 0xffff;
    bVar6 = param_1 <= uVar3;
    if (uVar3 <= param_1) {
      bVar6 = (iVar5 + uVar3 + (uint)puVar1[2] & 0xffff) <= param_1;
    }
    uVar3 = (uint)DAT_2080064e * (gui_frame.payload[4] & 0xf) + (uint)param_3[1] + (uint)puVar1[1] &
            0xffff;
    if (!bVar6) {
      bVar6 = param_2 <= uVar3;
      if (uVar3 <= param_2) {
        bVar6 = (puVar1[3] + uVar3 & 0xffff) <= param_2;
      }
      if (!bVar6) {
        uVar4 = puVar1[4];
      }
    }
  }
  return uVar4;
}


// ===== touch_hit_text_list_rows @ 2015cdd4 (244 bytes)

/* (x, y): row index from (y - 0x2080060A) / row pitch 0x2080064E in the right pane; a "DONE" row
   (0x208F0C5B + 0x2D*row) gives its own code [fact] */

int touch_hit_text_list_rows(uint param_1,uint param_2)

{
  ushort uVar1;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  ulonglong __aeabi_idivmod_ret;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  iVar8 = 0x1ff;
  if (((int)param_2 <= (int)(0x1e0 - (uint)DAT_2080064e)) && (DAT_2080060a <= param_2)) {
    __aeabi_idivmod_ret = __aeabi_idivmod(param_2 - DAT_2080060a,(uint)DAT_2080064e);
    uVar7 = (uint)__aeabi_idivmod_ret & 0xff;
    iVar5 = memcmp(uVar7 * 0x2d + 0x208f0c5b,&DAT_20428186,4);
    uVar1 = DAT_20800646;
    uVar2 = DAT_20800644;
    uVar3 = DAT_20800642;
    uVar4 = DAT_20800640;
    if (iVar5 != 0) {
      uVar1 = DAT_20800612;
      uVar2 = DAT_20800610;
      uVar3 = DAT_2080060a;
      uVar4 = DAT_20800608;
    }
    uVar6 = (uint)uVar4;
    bVar9 = param_1 <= uVar6;
    if (uVar6 <= param_1) {
      bVar9 = (uVar2 + uVar6 & 0xffff) <= param_1;
    }
    uVar6 = DAT_2080064e * uVar7 + (uint)uVar3 & 0xffff;
    if (!bVar9) {
      bVar9 = param_2 <= uVar6;
      if (uVar6 <= param_2) {
        bVar9 = (uVar1 + uVar6 & 0xffff) <= param_2;
      }
      if (!bVar9) {
        iVar8 = uVar7 + 0x1128;
      }
    }
  }
  return iVar8;
}


// ===== FUN_2015cfb4 @ 2015cfb4 (148 bytes)

undefined2 FUN_2015cfb4(uint param_1,uint param_2,int param_3,int param_4,uint param_5,int param_6)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = 0;
  if (0 < param_4) {
    do {
      puVar1 = (ushort *)(param_3 + uVar5 * 10);
      uVar4 = (uint)*puVar1;
      uVar3 = (uint)puVar1[1];
      uVar2 = puVar1[3] + uVar3;
      if (uVar5 == param_5 && param_6 == 1) {
        uVar3 = 0;
      }
      bVar6 = param_1 <= uVar4;
      uVar2 = uVar2 & 0xffff;
      if (uVar4 <= param_1) {
        bVar6 = (puVar1[2] + uVar4 & 0xffff) <= param_1;
      }
      if (!bVar6) {
        uVar4 = uVar3;
        if (uVar3 <= param_2) {
          uVar4 = uVar2;
        }
        if ((uVar3 <= param_2 && param_2 <= uVar2) && param_2 != uVar4) {
          return *(undefined2 *)(param_3 + uVar5 * 10 + 8);
        }
      }
      uVar5 = uVar5 + 1 & 0xff;
    } while ((int)uVar5 < param_4);
  }
  return 0x1ff;
}


// ===== scope2d_set_speed @ 2015d1c4 (204 bytes)

/* SPEED -> period 0x208084CE (600..30), depth 0x208084D2 (20..1), 100 rows/period */

void scope2d_set_speed(undefined4 param_1)

{
  int i;
  uint d;
  ulonglong __aeabi_idivmod_ret;
  ulonglong __aeabi_idivmod_ret_2;
  
  switch(param_1) {
  case 0:
    DAT_208084ce = 600;
    DAT_208084d2 = 0x14;
    break;
  case 1:
    DAT_208084ce = 0x1c2;
    DAT_208084d2 = 0xf;
    break;
  case 2:
    DAT_208084ce = 300;
    DAT_208084d2 = 10;
    break;
  case 3:
    DAT_208084ce = 0x96;
    DAT_208084d2 = 5;
    break;
  default:
    DAT_208084ce = 0x1e;
    DAT_208084d2 = 1;
  }
  i = 1;
  DAT_208f463e = 1;
  d = (uint)DAT_208084ce;
  if (1 < d) {
    do {
      __aeabi_idivmod_ret = __aeabi_idivmod(i * 100,d);
      __aeabi_idivmod_ret_2 = __aeabi_idivmod((i + -1) * 100,d);
      if ((int)__aeabi_idivmod_ret_2 < (int)__aeabi_idivmod_ret) {
        (&DAT_208f463e)[i] = 1;
      }
      else {
        (&DAT_208f463e)[i] = 0;
      }
      i = i + 1;
    } while (i < (int)d);
  }
  DAT_208084d0 = 0;
  return;
}


// ===== scope2d_set_color @ 2015d2a8 (92 bytes)

/* COLOR 0..10 -> spectrum fill 0x208084CC */

void scope2d_set_color(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  case 1:
    DAT_208084cc = 0xb5bf;
    return;
  case 2:
  case 8:
    DAT_208084cc = 0xffff;
    break;
  case 3:
  case 10:
    DAT_208084cc = 0xfef0;
    break;
  default:
    DAT_208084cc = 0xb5bf;
    break;
  case 5:
    DAT_208084cc = 0xfdb6;
    break;
  case 6:
    DAT_208084cc = 0xe71f;
    break;
  case 7:
    DAT_208084cc = 0xfe1f;
    break;
  case 9:
    DAT_208084cc = 0x6fed;
  }
  return;
}


// ===== multi_panel_draw @ 2015d334 (128 bytes)

/* MULTI: oscilloscope + AF-FFT spectrum + AF-FFT waterfall at y 325 */

void multi_panel_draw(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  affft_spectrum_draw(uVar1,0x145,0x195,0x187,param_1);
                    /* Writes one colour-mapped AF-FFT row [doc] */
  affft_wf_add_row();
  affft_waterfall_blit(uVar1,0x16d,0x195,0x187,0x27);
  osc_draw(uVar1,0x145,4,0,0x4f,param_1);
  return;
}


// ===== scope2d_draw_normal @ 2015d3b8 (212 bytes)

/* 2D spectrum + waterfall 100/133 px (waterfall size 1 NORMAL) */

void scope2d_draw_normal(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 0;
    iVar3 = 100;
  }
  else {
    iVar2 = 3;
    iVar3 = 0x85;
  }
  scope2d_spectrum_fill
            (uVar1,((0x192 - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
             (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    scope_wf_add_row(DAT_208084d2);
  }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  __aeabi_uidivmod(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  scope2d_waterfall_blit(uVar1,0x192 - iVar3,4,0x317,iVar3);
  return;
}


// ===== scope3d_front_large @ 2015d49c (104 bytes)

/* 3DSS front trace, large layout (mode 8, h 186/240) */

void scope3d_front_large(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    uVar2 = 0xba;
    iVar3 = 0xba;
  }
  else {
    uVar2 = 0xf0;
    iVar3 = 0xf0;
  }
  scope_front_trace_draw(uVar1,0x192 - iVar3,4,0x317,uVar2,8,param_2,0x1e);
  return;
}


// ===== scope2d_draw_multi @ 2015d508 (208 bytes)

/* 2D spectrum + waterfall 42/75 px, MULTI layout */

void scope2d_draw_multi(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 6;
    iVar3 = 0x2a;
  }
  else {
    iVar2 = 7;
    iVar3 = 0x4b;
  }
  scope2d_spectrum_fill
            (uVar1,((0x11c - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
             (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    scope_wf_add_row(DAT_208084d2);
  }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  __aeabi_uidivmod(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  scope2d_waterfall_blit(uVar1,0x11c - iVar3,4,0x317,iVar3);
  return;
}


// ===== scope3d_front_small @ 2015d5e8 (100 bytes)

/* 3DSS front trace, MULTI layout (mode 9, h 80/144) */

void scope3d_front_small(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    uVar2 = 0x50;
    iVar3 = 0x50;
  }
  else {
    uVar2 = 0x90;
    iVar3 = 0x90;
  }
  scope_front_trace_draw(uVar1,0x11c - iVar3,4,0x317,uVar2,9,param_2,0xf);
  return;
}


// ===== osc_draw @ 2015d650 (188 bytes)

/* oscilloscope min/max envelope, 391 x 79 at (4, 325) */

void osc_draw(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,undefined4 param_6)

{
  int i;
  int iVar1;
  int iVar2;
  int iVar3;
  byte local_338 [788];
  
  iVar2 = 0;
  osc_column_pairs(param_6,local_338);
  iVar3 = param_3 + 0x187;
  for (; param_3 < iVar3; param_3 = param_3 + 1) {
    i = 1;
    if (0 < param_5) {
      iVar1 = param_2 * 800;
      do {
        if ((i < (int)(uint)local_338[iVar2 * 2 + 1]) || ((int)(uint)local_338[iVar2 * 2] < i)) {
          *(undefined2 *)(param_1 + (param_3 + iVar1) * 2) = 0;
        }
        else {
          *(undefined2 *)(param_1 + (param_3 + iVar1) * 2) = 0x65f;
        }
        i = i + 1;
        iVar1 = iVar1 + 800;
      } while (i <= param_5);
    }
    iVar2 = iVar2 + 1;
  }
  return;
}


// ===== scope_front_trace_draw @ 2015d70c (360 bytes)

/* (fb, y, x, w, h, mode, range, stride): gradient-filled level trace */

void scope_front_trace_draw
               (int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
               ushort *param_7,int param_8)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  byte abStack_708 [800];
  undefined2 local_3e8 [240];
  undefined2 local_208 [242];
  
  iVar2 = scope_levels_get(param_6,abStack_708);
  iVar3 = scope_ramp_get(param_6);
  iVar8 = *(int *)(iVar2 + 4);
  iVar4 = *(int *)(iVar3 + 4);
  iVar3 = (uint)*param_7 - param_3;
  uVar1 = param_7[1];
  iVar2 = 0;
  if (0 < param_5) {
    do {
      iVar5 = iVar2 * param_8;
      puVar6 = local_3e8 + iVar2;
      iVar2 = iVar2 + 1;
      *puVar6 = *(undefined2 *)(iVar8 + iVar5 * 2);
    } while (iVar2 < param_5);
  }
  iVar2 = 0;
  if (0 < param_5) {
    do {
      iVar8 = iVar2 * param_8;
      puVar6 = local_208 + iVar2;
      iVar2 = iVar2 + 1;
      *puVar6 = *(undefined2 *)(iVar4 + iVar8 * 2);
    } while (iVar2 < param_5);
  }
  iVar4 = 0;
  iVar2 = param_3;
  if (0 < param_4) {
    do {
      bVar9 = SBORROW4(iVar3,iVar4);
      iVar8 = iVar3 - iVar4;
      if (iVar3 <= iVar4) {
        bVar9 = SBORROW4(iVar4,(uint)uVar1 + iVar3);
        iVar8 = iVar4 - ((uint)uVar1 + iVar3);
      }
      iVar5 = param_5 - (uint)abStack_708[iVar4 + param_3];
      iVar7 = (param_2 + iVar5) * 800;
      if (iVar8 < 0 == bVar9) {
        for (; iVar5 < param_5; iVar5 = iVar5 + 1) {
          iVar8 = iVar2 + iVar7;
          iVar7 = iVar7 + 800;
          *(undefined2 *)(param_1 + iVar8 * 2) = local_3e8[iVar5];
        }
      }
      else {
        for (; iVar5 < param_5; iVar5 = iVar5 + 1) {
          iVar8 = iVar2 + iVar7;
          iVar7 = iVar7 + 800;
          *(undefined2 *)(param_1 + iVar8 * 2) = local_208[iVar5];
        }
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar4 < param_4);
  }
  return;
}


// ===== scope2d_draw_size0 @ 2015d874 (212 bytes)

/* 2D spectrum + waterfall 60/63 px (size 0, never sent by MAIN) */

void scope2d_draw_size0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 1;
    iVar3 = 0x3c;
  }
  else {
    iVar2 = 4;
    iVar3 = 0x3f;
  }
  scope2d_spectrum_fill
            (uVar1,((0x192 - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
             (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    scope_wf_add_row(DAT_208084d2);
  }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  __aeabi_uidivmod(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  scope2d_waterfall_blit(uVar1,0x192 - iVar3,4,0x317,iVar3);
  return;
}


// ===== scope2d_draw_expand @ 2015d958 (212 bytes)

/* 2D spectrum + waterfall 140/213 px (size 2 EXPAND) */

void scope2d_draw_expand(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 extraout_r1;
  int iVar2;
  int iVar3;
  
  uVar1 = fb_get_layer_addr(DAT_208085b8);
  if (param_1 == 0) {
    iVar2 = 2;
    iVar3 = 0x8c;
  }
  else {
    iVar2 = 5;
    iVar3 = 0xd5;
  }
  scope2d_spectrum_fill
            (uVar1,((0x192 - iVar3) - (uint)(ushort)(&DAT_203a1ee0)[iVar2]) - 1 & 0xffff,4,0x317,
             (uint)(ushort)(&DAT_203a1ee0)[iVar2],iVar2,param_2);
  scope_history_push(DAT_208084d2,param_2);
  if ((&DAT_208f463e)[DAT_208084d0] != '\0') {
    scope_wf_add_row(DAT_208084d2);
  }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  __aeabi_uidivmod(DAT_208084d0 + 1,DAT_208084ce);
  DAT_208084d0 = extraout_r1;
  scope2d_waterfall_blit(uVar1,0x192 - iVar3,4,0x317,iVar3);
  return;
}

