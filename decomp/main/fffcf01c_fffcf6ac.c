// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex030405_step @ fffcf01c (18 bytes)

/* Menu item ex030405 VOX SELECT: on_step (#74) */

void menu_ex030405_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex030405_vox_select);
  return;
}


// ===== menu_ex030406_step @ fffcf02e (64 bytes)

/* Menu item ex030406 EMERGENCY FREQ TX: on_step (#74) */

void menu_ex030406_step(void)

{
  ushort uVar1;
  
  uVar1 = dest_code_get();
  if ((((uVar1 != 0x20b) && (uVar1 != 0x1cb9)) && (uVar1 != 0x315b)) &&
     (((uVar1 != 0x4380 && (uVar1 != 0x50e2)) && (uVar1 != 0x60e6)))) {
    beep_request(3);
    return;
  }
  menu_step_u8(0,1,&g_opstate.ex030406_emergency_freq_tx);
  return;
}


// ===== menu_ex030407_step @ fffcf06e (18 bytes)

/* Menu item ex030407 TX INHITBIT: on_step (#74) */

void menu_ex030407_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030407_tx_inhitbit);
  return;
}


// ===== menu_ex030408_step @ fffcf080 (18 bytes)

/* Menu item ex030408 METER DETECTOR: on_step (#74) */

void menu_ex030408_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030408_meter_detector);
  return;
}


// ===== menu_ex030501_step @ fffcf092 (18 bytes)

/* Menu item ex030501 SSB/CW DIAL STEP: on_step (#74) */

void menu_ex030501_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex030501_ssb_cw_dial_step);
  return;
}


// ===== menu_ex030502_step @ fffcf0a4 (18 bytes)

/* Menu item ex030502 RTTY/PSK DIAL STEP: on_step (#74) */

void menu_ex030502_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex030502_rtty_psk_dial_step);
  return;
}


// ===== menu_ex030503_step @ fffcf0b6 (18 bytes)

/* Menu item ex030503 CH STEP: on_step (#74) */

void menu_ex030503_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex030503_ch_step);
  return;
}


// ===== menu_ex030504_step @ fffcf0c8 (18 bytes)

/* Menu item ex030504 AM CH STEP: on_step (#74) */

void menu_ex030504_step(void)

{
  menu_step_u8(0,5,&g_opstate.ex030504_am_ch_step);
  return;
}


// ===== menu_ex030505_step @ fffcf0da (18 bytes)

/* Menu item ex030505 FM CH STEP: on_step (#74) */

void menu_ex030505_step(void)

{
  menu_step_u8(0,5,&g_opstate.ex030505_fm_ch_step);
  return;
}


// ===== menu_ex030506_step @ fffcf0ec (18 bytes)

/* Menu item ex030506 MAIN STEPS PER REV.: on_step (#74) */

void menu_ex030506_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex030506_main_steps_per_rev);
  return;
}


// ===== menu_ex040101_step @ fffcf0fe (1 bytes)

/* Menu item ex040101 MY CALL: on_step (#74) */

void menu_ex040101_step(void)

{
  return;
}


// ===== menu_ex040102_step @ fffcf0ff (18 bytes)

/* Menu item ex040102 MY CALL TIME: on_step (#74) */

void menu_ex040102_step(void)

{
  menu_step_u8(0,5,&g_opstate.ex040102_my_call_time);
  return;
}


// ===== menu_ex040103_step @ fffcf111 (18 bytes)

/* Menu item ex040103 POP-UP TIME: on_step (#74) */

void menu_ex040103_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex040103_pop_up_time);
  return;
}


// ===== menu_ex040104_step @ fffcf123 (22 bytes)

/* Menu item ex040104 SCREEN SAVER: on_step (#74) */

void menu_ex040104_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex040104_screen_saver);
  screensaver_timer_restart();
  return;
}


// ===== menu_ex040105_step @ fffcf139 (79 bytes)

/* Menu item ex040105 LED DIMMER: on_step (#74) */

void menu_ex040105_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex040105_led_dimmer);
  if (PTR_s_V01_12_0001b4fd._3_1_ == g_opstate.ex040105_led_dimmer) {
    return;
  }
  PTR_s_V01_12_0001b4fd._3_1_ = g_opstate.ex040105_led_dimmer;
  swtimer_start(0x2b,100);
  PTR_g_ui_00025d60->dl_req_24_later = 1;
  return;
}


// ===== menu_ex040106_step @ fffcf188 (79 bytes)

/* Menu item ex040106 MOUSE POINTER SPEED: on_step (#74) */

void menu_ex040106_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex040106_mouse_pointer_speed);
  if (DAT_0001b501 == g_opstate.ex040106_mouse_pointer_speed) {
    return;
  }
  DAT_0001b501 = g_opstate.ex040106_mouse_pointer_speed;
  swtimer_start(0x2b,100);
  PTR_g_ui_00025d60->dl_req_24_later = 1;
  return;
}


// ===== menu_ex040201_step @ fffcf1d7 (18 bytes)

/* Menu item ex040201 RBW: on_step (#74) */

void menu_ex040201_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex040201_rbw);
  return;
}


// ===== menu_ex040202_step @ fffcf1e9 (18 bytes)

/* Menu item ex040202 SCOPE CTR: on_step (#74) */

void menu_ex040202_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex040202_scope_ctr);
  return;
}


// ===== menu_ex040203_step @ fffcf1fb (18 bytes)

/* Menu item ex040203 2D DISP SENSITIVITY: on_step (#74) */

void menu_ex040203_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex040203_2d_disp_sensitivity);
  return;
}


// ===== menu_ex040204_step @ fffcf20d (18 bytes)

/* Menu item ex040204 3DSS DISP SENSITIVITY: on_step (#74) */

void menu_ex040204_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex040204_3dss_disp_sensitivity);
  return;
}


// ===== menu_ex040301_step @ fffcf21f (18 bytes)

/* Menu item ex040301 VMI COLOR VFO-A: on_step (#74) */

void menu_ex040301_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex040301_vmi_color_vfo_a);
  return;
}


// ===== menu_ex040302_step @ fffcf231 (18 bytes)

/* Menu item ex040302 VMI COLOR VFO-B: on_step (#74) */

void menu_ex040302_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex040302_vmi_color_vfo_b);
  return;
}


// ===== menu_ex040303_step @ fffcf243 (18 bytes)

/* Menu item ex040303 VMI COLOR MEMORY: on_step (#74) */

void menu_ex040303_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex040303_vmi_color_memory);
  return;
}


// ===== menu_ex040304_step @ fffcf255 (18 bytes)

/* Menu item ex040304 VMI COLOR CLAR: on_step (#74) */

void menu_ex040304_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex040304_vmi_color_clar);
  return;
}


// ===== menu_ex040401_step @ fffcf267 (78 bytes)

/* Menu item ex040401 EXT DISPLAY: on_step (#74) */

void menu_ex040401_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex040401_ext_display);
  if (DAT_0001b502 == g_opstate.ex040401_ext_display) {
    return;
  }
  DAT_0001b502 = g_opstate.ex040401_ext_display;
  swtimer_start(0x2b,100);
  PTR_g_ui_00025d60->dl_req_24_later = 1;
  return;
}


// ===== menu_ex040402_step @ fffcf2b5 (78 bytes)

/* Menu item ex040402 PIXEL: on_step (#74) */

void menu_ex040402_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex040402_pixel);
  if (DAT_0001b503 == g_opstate.ex040402_pixel) {
    return;
  }
  DAT_0001b503 = g_opstate.ex040402_pixel;
  swtimer_start(0x2b,100);
  PTR_g_ui_00025d60->dl_req_24_later = 1;
  return;
}


// ===== menu_ex040101_enter @ fffcf303 (119 bytes)

/* Menu item ex040101 MY CALL: on_enter (#74) */

void menu_ex040101_enter(void)

{
  ui_state *puVar1;
  ui_state *puVar2;
  
  PTR_g_ui_00025d60->kbd_open = 1;
  PTR_g_ui_00025d60->kbd_target = 0;
  PTR_g_ui_00025d60->kbd_cursor = 0;
  puVar1 = PTR_g_ui_00025d60;
  *(byte *)((int)(puVar1->msg_text + 0) + 8) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 9) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 10) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 0xb) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 4) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 5) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 6) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 7) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 0) = 0x20;
  puVar2 = PTR_g_ui_00025d60;
  *(byte *)((int)(puVar1->msg_text + 0) + 1) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 2) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 3) = 0x20;
  *(undefined4 *)(PTR_g_ui_00025d60->msg_text[0] + 8) = g_opstate.ex040101_my_call._8_4_;
  *(undefined4 *)(puVar2->msg_text[0] + 4) = g_opstate.ex040101_my_call._4_4_;
  *(undefined4 *)puVar2->msg_text[0] = g_opstate.ex040101_my_call._0_4_;
  beep_request(1);
  return;
}


// ===== menu_m4_16_0_step @ fffcf37a (21 bytes)

/* Menu item m4_16_0 DAY: on_step (#74) */

void menu_m4_16_0_step(void)

{
  menu_step_bcd(1,0x31,PTR_g_ui_00025d60->rtc_set + 2);
  return;
}


// ===== menu_step_bcd @ fffcf38f (108 bytes)

/* (min, max, *v): +/-1 on a packed-BCD byte by direction +0x421, clamped; DATE&TIME items [fact] */

void menu_step_bcd(byte param_1,byte param_2,byte *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_g_ui_00025d60->menu_step_dir == 0) {
      if ((*param_3 < param_2) && (*param_3 = *param_3 + 1, 9 < (*param_3 & 0xf))) {
        *param_3 = *param_3 + 6;
        return;
      }
    }
    else if ((param_1 < *param_3) && (*param_3 = *param_3 - 1, 9 < (*param_3 & 0xf))) {
      *param_3 = *param_3 - 6;
      return;
    }
  }
  return;
}


// ===== menu_m4_16_1_step @ fffcf3fb (21 bytes)

/* Menu item m4_16_1 MONTH: on_step (#74) */

void menu_m4_16_1_step(void)

{
  menu_step_bcd(1,0x12,PTR_g_ui_00025d60->rtc_set + 1);
  return;
}


// ===== menu_m4_16_2_step @ fffcf410 (21 bytes)

/* Menu item m4_16_2 YEAR: on_step (#74) */

void menu_m4_16_2_step(void)

{
  menu_step_bcd(0,0x99,PTR_g_ui_00025d60->rtc_set);
  return;
}


// ===== menu_m4_16_3_step @ fffcf425 (21 bytes)

/* Menu item m4_16_3 HOUR: on_step (#74) */

void menu_m4_16_3_step(void)

{
  menu_step_bcd(0,0x23,PTR_g_ui_00025d60->rtc_set + 3);
  return;
}


// ===== menu_m4_16_4_step @ fffcf43a (21 bytes)

/* Menu item m4_16_4 MINUTE: on_step (#74) */

void menu_m4_16_4_step(void)

{
  menu_step_bcd(0,0x59,PTR_g_ui_00025d60->rtc_set + 4);
  return;
}


// ===== menu_m4_17_0_enter @ fffcf44f (13 bytes)

/* Menu item m4_17_0 MEM LIST LOAD: on_enter (#74) */

void menu_m4_17_0_enter(void)

{
  int iVar1;
  
  iVar1 = sd_menu_enter_check(2);
  if (iVar1 != 1) {
    return;
  }
  sd_memlist_load_start();
  return;
}


// ===== FUN_fffcf45c @ fffcf45c (92 bytes)

void FUN_fffcf45c(void)

{
  if ((((PTR_g_ui_00025d60->sd_state_known == 1) &&
       (PTR_g_ui_00025d60->sd_present_prev != PTR_g_ui_00025d60->sd_present)) &&
      (PTR_g_ui_00025d60->sd_present_prev = PTR_g_ui_00025d60->sd_present,
      PTR_g_ui_00025d60->sd_present == 1)) &&
     ((PTR_g_ui_00025d60->zz_align_mode == 0 && (PTR_g_ui_00025d60->dl_req_40 == 0)))) {
    FUN_fffcf4b8();
    return;
  }
  return;
}


// ===== FUN_fffcf4b8 @ fffcf4b8 (29 bytes)

void FUN_fffcf4b8(void)

{
  PTR_g_ui_00025d60->dialog_msg = 1;
  PTR_g_ui_00025d60->dialog_has_choice = 1;
  dialog_open();
  return;
}


// ===== dialog_insert_fw_sd @ fffcf4d5 (29 bytes)

/* Dialog n = 2 (UI +0xBB; ROM text "INSERT FIRMWARE / SD CARD"), +0x448 = 0, dialog_open [fact] */

void dialog_insert_fw_sd(void)

{
  PTR_g_ui_00025d60->dialog_msg = 2;
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  dialog_open();
  return;
}


// ===== dialog_no_sd_card @ fffcf4f2 (29 bytes)

/* Dialog n = 3 (ROM text "NO SD CARD"), +0x448 = 0, dialog_open [fact] */

void dialog_no_sd_card(void)

{
  PTR_g_ui_00025d60->dialog_msg = 3;
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  dialog_open();
  return;
}


// ===== FUN_fffcf50f @ fffcf50f (29 bytes)

void FUN_fffcf50f(void)

{
  PTR_g_ui_00025d60->dialog_msg = 5;
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  dialog_open();
  return;
}


// ===== FUN_fffcf52c @ fffcf52c (29 bytes)

void FUN_fffcf52c(void)

{
  PTR_g_ui_00025d60->dialog_msg = 6;
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  dialog_open();
  return;
}


// ===== FUN_fffcf549 @ fffcf549 (29 bytes)

void FUN_fffcf549(void)

{
  PTR_g_ui_00025d60->dialog_msg = 7;
  PTR_g_ui_00025d60->dialog_has_choice = 1;
  dialog_open();
  return;
}


// ===== FUN_fffcf566 @ fffcf566 (29 bytes)

void FUN_fffcf566(void)

{
  PTR_g_ui_00025d60->dialog_msg = 8;
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  dialog_open();
  return;
}


// ===== FUN_fffcf583 @ fffcf583 (29 bytes)

void FUN_fffcf583(void)

{
  PTR_g_ui_00025d60->dialog_msg = 0xd;
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  dialog_open();
  return;
}


// ===== FUN_fffcf5a0 @ fffcf5a0 (29 bytes)

void FUN_fffcf5a0(void)

{
  PTR_g_ui_00025d60->dialog_msg = 9;
  PTR_g_ui_00025d60->dialog_has_choice = 1;
  dialog_open();
  return;
}


// ===== FUN_fffcf5bd @ fffcf5bd (60 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcf5da) */

ushort FUN_fffcf5bd(void)

{
  undefined2 local_4;
  
  if (DAT_00015de5 == '\0') {
    local_4 = CONCAT11(DAT_00012274,DAT_00012273);
  }
  else {
    local_4 = dest_code_get();
  }
  return local_4;
}


// ===== FUN_fffcf5f9 @ fffcf5f9 (92 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcf652) */

undefined4 FUN_fffcf5f9(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = dest_code_get();
  if (DAT_00015de5 == '\0') {
    uVar2 = FUN_fffcf5bd();
    if (uVar1 == uVar2) {
      PTR_g_ui_00025d60->dialog_msg = 10;
    }
    else {
      PTR_g_ui_00025d60->dialog_msg = 0xf;
    }
  }
  else {
    uVar2 = FUN_fffcf5bd();
    if (uVar1 == uVar2) {
      PTR_g_ui_00025d60->dialog_msg = 10;
    }
    else {
      PTR_g_ui_00025d60->dialog_msg = 0xf;
    }
  }
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  uVar3 = dialog_open();
  return uVar3;
}


// ===== FUN_fffcf655 @ fffcf655 (29 bytes)

void FUN_fffcf655(void)

{
  PTR_g_ui_00025d60->dialog_msg = 0xb;
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  dialog_open();
  return;
}


// ===== FUN_fffcf672 @ fffcf672 (29 bytes)

void FUN_fffcf672(void)

{
  PTR_g_ui_00025d60->dialog_msg = 0xc;
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  dialog_open();
  return;
}


// ===== FUN_fffcf68f @ fffcf68f (29 bytes)

void FUN_fffcf68f(void)

{
  PTR_g_ui_00025d60->dialog_msg = 4;
  PTR_g_ui_00025d60->dialog_has_choice = 0;
  dialog_open();
  return;
}


// ===== dialog_open @ fffcf6ac (49 bytes)

/* UI +0x86 = 1 (frame 0x70 due), selected button +0xBD = 0, clears +0x70 [fact] */

void dialog_open(void)

{
  PTR_g_ui_00025d60->dialog_shown = 1;
  PTR_g_ui_00025d60->dialog_button = 0;
  if (g_ui.func_panel_open == 0) {
    return;
  }
  g_ui.func_panel_open = 0;
  return;
}

