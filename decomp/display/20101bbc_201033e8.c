// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== lcd_pins_enable @ 20101bbc (84 bytes)

/* P3_4 LCD_DEN alt1, P11_15 LCD_CLK alt5 (or inputs) */

void lcd_pins_enable(int param_1)

{
  if (param_1 != 0) {
    gpio_cfg_alt(3,4,1,0);
    gpio_cfg_alt(0xb,0xf,5,0);
    return;
  }
  gpio_cfg_input(3,4);
  gpio_cfg_input(0xb,0xf);
  return;
}


// ===== lcd_power @ 20101c10 (52 bytes)

/* lcd_pins_enable + P4_6 LCD_STBY + P10_14 LCD_PWR_EN */

void lcd_power(uint param_1)

{
  undefined4 uVar1;
  
  lcd_pins_enable(param_1 & 0xff);
  if (param_1 != 0) {
    uVar1 = 0x400040;
  }
  else {
    uVar1 = 0x400000;
  }
  DAT_fcfe3110 = uVar1;
  if (param_1 != 0) {
    uVar1 = 0x40004000;
  }
  else {
    uVar1 = 0x40000000;
  }
  DAT_fcfe3128 = uVar1;
  return;
}


// ===== gpio_rx_reset @ 20101c5c (24 bytes)

/* P7_10 (RX_RESET per hardware.md) via PSR7 */

void gpio_rx_reset(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x4000000;
  }
  else {
    uVar1 = 0x4000400;
  }
  DAT_fcfe311c = uVar1;
  return;
}


// ===== gpio_rx_update @ 20101c74 (24 bytes)

/* P4_3 = RX_UPDATE (MAIN boot mode) */

void gpio_rx_update(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x80000;
  }
  else {
    uVar1 = 0x80008;
  }
  DAT_fcfe3110 = uVar1;
  return;
}


// ===== gpio_p8_5 @ 20101c8c (24 bytes)

/* P8_5 (SDR_MOSI) port level, used by the reboot sequence */

void gpio_p8_5(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x200000;
  }
  else {
    uVar1 = 0x200020;
  }
  DAT_fcfe3120 = uVar1;
  return;
}


// ===== gpio_rx_update_b @ 20101ca4 (24 bytes)

/* identical copy of gpio_rx_update */

void gpio_rx_update_b(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x80000;
  }
  else {
    uVar1 = 0x80008;
  }
  DAT_fcfe3110 = uVar1;
  return;
}


// ===== gpio_qf_reset @ 20101cbc (24 bytes)

/* P11_2 = QF_RESETn (W25Q128 reset) */

void gpio_qf_reset(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x40000;
  }
  else {
    uVar1 = 0x40004;
  }
  DAT_fcfe312c = uVar1;
  return;
}


// ===== gpio_p2_4_5_select @ 20101cd4 (64 bytes)

/* NEW ENTRY; 3-way select on P2_4/P2_5/P10_1 */

void gpio_p2_4_5_select(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  if (param_1 == 0) {
    uVar2 = 2;
  }
  else if (param_1 == 1) {
    uVar1 = 0x20;
  }
  else if (param_1 == 2) {
    uVar1 = 0x10;
  }
  DAT_fcfe3108 = uVar1 | 0x300000;
  DAT_fcfe3128 = uVar2 | 0x20000;
  return;
}


// ===== gpio_p2_4_5_clear @ 20101d14 (24 bytes)

/* P2_4, P2_5 and P10_1 low */

void gpio_p2_4_5_clear(void)

{
  DAT_fcfe3108 = 0x300000;
  DAT_fcfe3128 = 0x20000;
  return;
}


// ===== gpio_rx_update_off @ 20101d2c (20 bytes)

/* RX_UPDATE low when arg != 0 */

void gpio_rx_update_off(int param_1)

{
  if (param_1 != 0) {
    gpio_rx_update_b(0);
    return;
  }
  return;
}


// ===== sd_power @ 20101d70 (36 bytes)

/* P7_12 = SDPWS (SD card power switch), 1-tick delay on power-up */

void sd_power(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = 0x10001000;
  }
  else {
    uVar1 = 0x10000000;
  }
  DAT_fcfe311c = uVar1;
  if (param_1 == 0) {
    return;
  }
  itron_dly_tsk(1);
  return;
}


// ===== sd_card_detect @ 20101d94 (16 bytes)

/* P11_4 = SD_CD level */

uint sd_card_detect(void)

{
  ushort uVar1;
  
  uVar1 = DAT_fcfe322c;
  return (uVar1 & 0x1f) >> 4;
}


// ===== gpio_usb0_en @ 20101da4 (32 bytes)

/* NEW ENTRY; (port, on): P8_10 USB0_EN */

void gpio_usb0_en(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    if (param_2 == 0) {
      uVar1 = 0x4000000;
    }
    else {
      uVar1 = 0x4000400;
    }
    DAT_fcfe3120 = uVar1;
  }
  return;
}


// ===== gpio_dvr @ 20101dc4 (40 bytes)

/* P5_9 DVR0 / P5_8 DVR1 (lines to the MAIN DVI chain; P5_8 = 1 for 800x480, 0 for 800x600) */

void gpio_dvr(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0x1000000;
  }
  else {
    uVar2 = 0x1000100;
  }
  if (param_1 == 0) {
    uVar1 = 0x2000000;
  }
  else {
    uVar1 = 0x2000200;
  }
  DAT_fcfe3114 = uVar1 | uVar2;
  return;
}


// ===== lvds_pins_enable @ 20101dec (276 bytes)

/* P5_0..P5_7 LVDS (RA..RCK pairs) alt1, or output low */

void lvds_pins_enable(int param_1)

{
  if (param_1 != 0) {
    gpio_cfg_alt(5,0,1);
    gpio_cfg_alt(5,1,1);
    gpio_cfg_alt(5,2,1);
    gpio_cfg_alt(5,3,1);
    gpio_cfg_alt(5,4,1);
    gpio_cfg_alt(5,5,1);
    gpio_cfg_alt(5,6,1);
    gpio_cfg_alt(5,7,1);
    return;
  }
  gpio_cfg_out_low(5,0);
  gpio_cfg_out_low(5,1);
  gpio_cfg_out_low(5,2);
  gpio_cfg_out_low(5,3);
  gpio_cfg_out_low(5,4);
  gpio_cfg_out_low(5);
  gpio_cfg_out_low(5,6);
  gpio_cfg_out_low(5,7);
  return;
}


// ===== rtc_dt_output @ 20101f44 (12 bytes)

/* P1_0 (RTC_DT) back to output */

void rtc_dt_output(void)

{
  gpio_cfg_out_low(1,0);
  return;
}


// ===== rtc_dt_input @ 20101f50 (12 bytes)

/* P1_0 (RTC_DT) as input for reading */

void rtc_dt_input(void)

{
  gpio_cfg_input(1,0);
  return;
}


// ===== gpio_p2_15 @ 20101f5c (24 bytes)

/* P2_15 (ACC_MOSI) port level */

void gpio_p2_15(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x80000000;
  }
  else {
    uVar1 = 0x80008000;
  }
  DAT_fcfe3108 = uVar1;
  return;
}


// ===== gpio_ft4222_reset @ 20101f8c (24 bytes)

/* P2_7 = FT4222_RESET */

void gpio_ft4222_reset(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x800000;
  }
  else {
    uVar1 = 0x800080;
  }
  DAT_fcfe3108 = uVar1;
  return;
}


// ===== led_set_one @ 20101fa4 (76 bytes)

/* one front LED (P6 pin table) on/off */

void led_set_one(int param_1,int param_2)

{
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_10 = 0xe0b0d0a;
  uStack_c = 0x8050904;
  local_8 = 0xc;
  if (param_1 != 0) {
    gpio_cfg_out_high();
    return;
  }
  gpio_cfg_out_low(6,*(undefined1 *)((int)&local_10 + param_2),&local_10);
  return;
}


// ===== led_set_mask @ 20102040 (88 bytes)

/* 8 front LEDs from a bit mask (D_RED, D_GREEN, D_WHITE, D_BLUE, RXBUSY, TX, STEPCH, VOX) */

void led_set_mask(uint param_1)

{
  uint uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  
  uVar1 = 0;
  local_18 = 0x4090508;
  uStack_14 = 0xd0b0c0e;
  do {
    if ((param_1 >> (uVar1 & 0xff) & 1) == 0) {
      gpio_cfg_out_low(6,*(undefined1 *)((int)&local_18 + uVar1));
    }
    else {
      gpio_cfg_out_high();
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 8);
  return;
}


// ===== cpg_set_clock_profile @ 201020a0 (144 bytes)

/* FRQCR + STBCR1..11 from a 2-entry table at 0x2016517C */

void cpg_set_clock_profile(int param_1)

{
  DAT_fcfe0024 = (&DAT_2016517c)[param_1];
  DAT_fcfe0420 = (&DAT_2016517e)[param_1];
  DAT_fcfe0424 = (&DAT_20165180)[param_1];
  DAT_fcfe0428 = (&DAT_20165182)[param_1];
  DAT_fcfe042c = (&DAT_20165184)[param_1];
  DAT_fcfe0430 = (&DAT_20165186)[param_1];
  DAT_fcfe0434 = (&DAT_20165188)[param_1];
  DAT_fcfe0438 = (&DAT_2016518a)[param_1];
  DAT_fcfe043c = (&DAT_2016518c)[param_1];
  DAT_fcfe0440 = (&DAT_2016518e)[param_1];
  DAT_fcfe0444 = (&DAT_20165190)[param_1];
  return;
}


// ===== pointer_get_event @ 20102138 (400 bytes)

/* (evt, src 1 touch/0 mouse): 0 none 1 release 2 press 3 held 4 re-press 5 tap 6 release+tap */

void pointer_get_event(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_2 == 0) {
    piVar3 = &DAT_2080003c;
    iVar2 = 0x20808bdc;
  }
  else {
    piVar3 = &DAT_20800030;
    iVar2 = 0x20808bd0;
  }
  piVar4 = piVar3 + 2;
  if (*piVar3 == 0) {
    if (piVar3[1] != 0) {
      DAT_20808bec = DAT_20808bec + '\x01';
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
      *param_1 = 2;
      *piVar3 = 1;
      goto LAB_2010226c;
    }
    if (*piVar4 != 0) {
      DAT_20808bed = DAT_20808bed + '\x01';
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
      uVar1 = 5;
      goto LAB_201022a4;
    }
    DAT_20808bee = DAT_20808bee + '\x01';
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
  }
  else {
    if (piVar3[1] != 0) {
      if (*piVar4 == 0) {
        DAT_20808be9 = DAT_20808be9 + '\x01';
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
        *param_1 = 3;
        *piVar3 = 1;
      }
      else {
        DAT_20808be8 = DAT_20808be8 + '\x01';
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
        *param_1 = 4;
        *piVar3 = 1;
      }
      goto LAB_2010226c;
    }
    if (*piVar4 == 0) {
      DAT_20808beb = DAT_20808beb + '\x01';
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 1;
    }
    else {
      DAT_20808bea = DAT_20808bea + '\x01';
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar2 + 8);
      uVar1 = 6;
LAB_201022a4:
      *param_1 = uVar1;
    }
  }
  *piVar3 = 0;
LAB_2010226c:
  *piVar4 = 0;
  return;
}


// ===== touch_set_down @ 201022c8 (84 bytes)

/* pen sample (x, y) -> pointer source "touch" */

void touch_set_down(undefined4 param_1,undefined4 param_2)

{
  DAT_20808bef = DAT_20808bef + '\x01';
  if (((DAT_2080003c == 0 && DAT_20800040 == 0) && DAT_20800044 == 0) && DAT_20800048 == 0) {
    if (DAT_20800034 == 0) {
      DAT_20800038 = 1;
    }
    DAT_20800034 = 1;
    DAT_20808bd4 = param_1;
    DAT_20808bd8 = param_2;
  }
  return;
}


// ===== touch_set_up @ 2010231c (32 bytes)

/* pen released */

void touch_set_up(void)

{
  DAT_20808bf0 = DAT_20808bf0 + '\x01';
  DAT_20800034 = 0;
  return;
}


// ===== mouse_set_down @ 20102348 (84 bytes)

/* left button down at (x, y) -> pointer source "mouse" */

void mouse_set_down(undefined4 param_1,undefined4 param_2)

{
  DAT_20808bf1 = DAT_20808bf1 + '\x01';
  if (((DAT_20800030 == 0 && DAT_20800034 == 0) && DAT_20800038 == 0) && DAT_20800048 == 0) {
    if (DAT_20800040 == 0) {
      DAT_20800044 = 1;
    }
    DAT_20800040 = 1;
    DAT_20808be0 = param_1;
    DAT_20808be4 = param_2;
  }
  return;
}


// ===== mouse_set_up @ 2010239c (32 bytes)

/* left button released */

void mouse_set_up(void)

{
  DAT_20808bf2 = DAT_20808bf2 + '\x01';
  DAT_20800040 = 0;
  return;
}


// ===== mouse_right_get_event @ 201023bc (188 bytes)

void mouse_right_get_event(undefined1 *param_1)

{
  undefined1 uVar1;
  
  if (DAT_2080004c == 0) {
    if (DAT_20800048 != 0) {
      *param_1 = 2;
      DAT_2080004c = 1;
      DAT_20800050 = 0;
      return;
    }
    if (DAT_20800050 == 0) {
      *param_1 = 0;
      DAT_2080004c = 0;
      DAT_20800050 = 0;
      return;
    }
    uVar1 = 5;
  }
  else {
    if (DAT_20800048 != 0) {
      if (DAT_20800050 == 0) {
        uVar1 = 3;
      }
      else {
        uVar1 = 4;
      }
      *param_1 = uVar1;
      DAT_2080004c = 1;
      DAT_20800050 = 0;
      return;
    }
    if (DAT_20800050 == 0) {
      DAT_20808beb = DAT_20808beb + '\x01';
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 1;
      DAT_2080004c = 0;
      DAT_20800050 = 0;
      return;
    }
    uVar1 = 6;
  }
  *param_1 = uVar1;
  DAT_2080004c = 0;
  DAT_20800050 = 0;
  return;
}


// ===== mouse_right_down @ 20102478 (60 bytes)

void mouse_right_down(void)

{
  if (((DAT_20800030 == 0 && DAT_20800034 == 0) && DAT_20800038 == 0) && DAT_20800040 == 0) {
    if (DAT_20800048 == 0) {
      DAT_20800050 = 1;
    }
    DAT_20800048 = 1;
  }
  return;
}


// ===== mouse_right_up @ 201024b4 (16 bytes)

void mouse_right_up(void)

{
  DAT_20800048 = 0;
  return;
}


// ===== mouse_middle_get_event @ 201024c4 (168 bytes)

void mouse_middle_get_event(undefined1 *param_1)

{
  undefined1 uVar1;
  
  if (DAT_20800058 == 0) {
    if (DAT_20800054 != 0) {
      *param_1 = 2;
      DAT_20800058 = 1;
      DAT_2080005c = 0;
      return;
    }
    if (DAT_2080005c == 0) {
      *param_1 = 0;
      DAT_20800058 = 0;
      DAT_2080005c = 0;
      return;
    }
    uVar1 = 5;
  }
  else {
    if (DAT_20800054 != 0) {
      if (DAT_2080005c == 0) {
        uVar1 = 3;
      }
      else {
        uVar1 = 4;
      }
      *param_1 = uVar1;
      DAT_20800058 = 1;
      DAT_2080005c = 0;
      return;
    }
    if (DAT_2080005c == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 1;
      DAT_20800058 = 0;
      DAT_2080005c = 0;
      return;
    }
    uVar1 = 6;
  }
  *param_1 = uVar1;
  DAT_20800058 = 0;
  DAT_2080005c = 0;
  return;
}


// ===== mouse_middle_down @ 2010256c (72 bytes)

void mouse_middle_down(void)

{
  int iVar1;
  
  if ((((DAT_20800030 == 0 && DAT_20800034 == 0) && DAT_20800038 == 0) && DAT_20800048 == 0) &&
     (iVar1 = key_func_is_held(), iVar1 == 0)) {
    if (DAT_20800054 == 0) {
      DAT_2080005c = 1;
    }
    DAT_20800054 = 1;
  }
  return;
}


// ===== mouse_middle_up @ 201025b4 (16 bytes)

void mouse_middle_up(void)

{
  DAT_20800054 = 0;
  return;
}


// ===== mouse_middle_is_func @ 201025c4 (60 bytes)

/* middle button held on a FUNC-type screen (blocks direct key events) */

undefined4 mouse_middle_is_func(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_2080005c != 0 || (DAT_20800058 != 0 || DAT_20800054 != 0)) &&
     (iVar1 = gui_middle_key(), iVar1 == 0x30f)) {
    uVar2 = 1;
  }
  return uVar2;
}


// ===== backlight_pwm_init @ 2010261c (124 bytes)

/* MTU2 ch3/ch4 reset-synchronised PWM, period 320 counts, TIOC4D out */

void backlight_pwm_init(void)

{
  byte bVar1;
  
  DAT_fcff0200 = 0x40;
  DAT_fcff0210 = 0;
  DAT_fcff0212 = 0;
  DAT_fcff0218 = 0;
  DAT_fcff021a = 0x13f;
  DAT_fcff0224 = 0;
  DAT_fcff0226 = 0x13f;
  DAT_fcff021c = 0;
  DAT_fcff021e = 0;
  DAT_fcff0228 = 0;
  DAT_fcff022a = 0;
  DAT_fcff020e = 0x47;
  DAT_fcff020f = 0x7f;
  DAT_fcff0236 = 0x3f;
  DAT_fcff0202 = 0x38;
  bVar1 = DAT_fcff020a;
  DAT_fcff020a = bVar1 | 0x20;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 | 0x40;
  return;
}


// ===== backlight_set_pct @ 20102698 (72 bytes)

/* NEW ENTRY; duty = pct*320/100 -> TGRD_4 */

void backlight_set_pct(int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  iVar1 = div10_round(param_1 * 0x140,param_1 * 0x140 >> 0x1f);
  iVar1 = div10_round(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 0x140) {
    iVar1 = 0x13f;
  }
  DAT_fcff022a = (short)iVar1 + -1;
  return;
}


// ===== backlight_set @ 201026e0 (8 bytes)

/* thunk: backlight_set_pct */

void backlight_set(int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  iVar1 = div10_round(param_1 * 0x140,param_1 * 0x140 >> 0x1f);
  iVar1 = div10_round(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 0x140) {
    iVar1 = 0x13f;
  }
  DAT_fcff022a = (short)iVar1 + -1;
  return;
}


// ===== backlight_init @ 201026e8 (24 bytes)

/* WARNING: Removing unreachable block (ram,0x201026a0) */
/* WARNING: Removing unreachable block (ram,0x201026ac) */
/* backlight_pwm_init + 60 % */

void backlight_init(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  backlight_pwm_init();
  iVar1 = div10_round(0x4b00,0,extraout_r2,extraout_r3,unaff_r4,unaff_lr);
  iVar1 = div10_round(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 0x140) {
    iVar1 = 0x13f;
  }
  DAT_fcff022a = (short)iVar1 + -1;
  return;
}


// ===== touch_cal_load @ 20102708 (108 bytes)

/* flash 0x183D0000: magic 0xA5C30001, 6 doubles, ~CRC-32 */

void touch_cal_load(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((*param_1 != -1) && (*param_1 == -0x5a3cffff)) {
    crc32_make_table();
    uVar1 = crc32_update(0xffffffff,0x30,param_1 + 2);
    if (param_1[0xe] == ~uVar1) {
      iVar2 = param_1[3];
      iVar3 = param_1[4];
      iVar4 = param_1[5];
      *param_2 = param_1[2];
      param_2[1] = iVar2;
      param_2[2] = iVar3;
      param_2[3] = iVar4;
      iVar2 = param_1[7];
      iVar3 = param_1[8];
      iVar4 = param_1[9];
      param_2[4] = param_1[6];
      param_2[5] = iVar2;
      param_2[6] = iVar3;
      param_2[7] = iVar4;
      iVar2 = param_1[0xb];
      iVar3 = param_1[0xc];
      iVar4 = param_1[0xd];
      param_2[8] = param_1[10];
      param_2[9] = iVar2;
      param_2[10] = iVar3;
      param_2[0xb] = iVar4;
    }
  }
  return;
}


// ===== touch_cal_save @ 20102774 (132 bytes)

/* erase + write the 0x40-byte calibration record at flash 0x3D0000 */

void touch_cal_save(undefined4 *param_1)

{
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint local_18;
  
  local_50[0] = 0xa5c30001;
  local_48 = *param_1;
  uStack_44 = param_1[1];
  uStack_40 = param_1[2];
  uStack_3c = param_1[3];
  local_38 = param_1[4];
  uStack_34 = param_1[5];
  uStack_30 = param_1[6];
  uStack_2c = param_1[7];
  local_28 = param_1[8];
  uStack_24 = param_1[9];
  uStack_20 = param_1[10];
  uStack_1c = param_1[0xb];
  crc32_make_table();
  local_18 = crc32_update(0xffffffff,0x30,&local_48);
  local_18 = ~local_18;
  spiflash_erase(0,0x3d0000,0x40);
  spiflash_write(0x3d0000,local_50,0x40);
  return;
}


// ===== touch_cal_fit @ 201027f8 (1836 bytes)

/* least-squares affine fit of 5 measured vs 5 reference points */

void touch_cal_fit(undefined8 *param_1)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  iVar3 = 0;
  do {
    *(undefined4 *)(&local_e0 + iVar3) = 0;
    *(undefined4 *)((int)&local_e0 + iVar3 * 8 + 4) = 0;
    *(undefined4 *)(&local_58 + iVar3) = 0;
    *(undefined4 *)((int)&local_58 + iVar3 * 8 + 4) = 0;
    *(undefined4 *)(&local_40 + iVar3) = 0;
    *(undefined4 *)((int)&local_40 + iVar3 * 8 + 4) = 0;
    iVar1 = iVar3 * 8;
    puVar10 = &local_70 + iVar3;
    iVar3 = iVar3 + 1;
    *(undefined4 *)puVar10 = 0;
    *(undefined4 *)((int)&local_70 + iVar1 + 4) = 0;
    uVar16 = CONCAT44(local_68._4_4_,(undefined4)local_68);
  } while (iVar3 < 3);
  iVar3 = 0;
  do {
    local_68 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20808bf8)[iVar3 * 2]);
    uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar4 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar4,uVar11,(undefined4)local_d0,local_d0._4_4_);
    local_d0 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20808bfa)[iVar3 * 2]);
    uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar5 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar5,uVar12,(undefined4)local_48,local_48._4_4_);
    local_48 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20800060)[iVar3 * 2]);
    uVar13 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar6 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar6,uVar13,(undefined4)local_30,local_30._4_4_);
    local_30 = uVar16;
    uVar16 = FUN_20164d54((int)(short)(&DAT_20800062)[iVar3 * 2]);
    uVar14 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar7 = (undefined4)uVar16;
    uVar16 = FUN_20164888(uVar7,uVar14,(undefined4)local_60,local_60._4_4_);
    local_60 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar4,uVar11);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_e0,
                          local_e0._4_4_);
    local_e0 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar5,uVar12);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_d8,
                          local_d8._4_4_);
    local_d8 = uVar16;
    local_58 = uVar16;
    uVar16 = FUN_20164da8(uVar5,uVar12,uVar5,uVar12);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_50,
                          local_50._4_4_);
    local_50 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar6,uVar13);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_40,
                          local_40._4_4_);
    local_40 = uVar16;
    uVar16 = FUN_20164da8(uVar5,uVar12,uVar6,uVar13);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_38,
                          local_38._4_4_);
    local_38 = uVar16;
    uVar16 = FUN_20164da8(uVar4,uVar11,uVar7,uVar14);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_70,
                          local_70._4_4_);
    local_70 = uVar16;
    uVar16 = FUN_20164da8(uVar5,uVar12,uVar7,uVar14);
    uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_68,
                          local_68._4_4_);
    uVar5 = local_d0._4_4_;
    uVar4 = (undefined4)local_d0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  local_68 = uVar16;
  uVar16 = FUN_201649d8((undefined4)local_e0,local_e0._4_4_);
  uVar7 = local_48._4_4_;
  uVar6 = (undefined4)local_48;
  uVar12 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar8 = (undefined4)uVar16;
  local_e0 = uVar16;
  uVar16 = FUN_201649d8((undefined4)local_d8,local_d8._4_4_,(undefined4)local_48,local_48._4_4_);
  local_d8 = uVar16;
  local_78 = FUN_201649d8((undefined4)local_58,local_58._4_4_,uVar4,uVar5);
  local_58 = local_78;
  local_88 = FUN_201649d8((undefined4)local_50,local_50._4_4_,uVar6,uVar7);
  local_50 = local_88;
  local_98 = FUN_201649d8((undefined4)local_40,local_40._4_4_,uVar4,uVar5);
  local_40 = local_98;
  uVar17 = FUN_201649d8((undefined4)local_38,local_38._4_4_,uVar6,uVar7);
  local_c8._0_4_ = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar11 = (undefined4)uVar17;
  local_c0._0_4_ = (undefined4)local_c8;
  local_38 = uVar17;
  uVar17 = FUN_201649d8((undefined4)local_70,local_70._4_4_,uVar4,uVar5);
  local_70 = uVar17;
  uVar17 = FUN_201649d8((undefined4)local_68,local_68._4_4_,uVar6,uVar7);
  local_68 = uVar17;
  uVar17 = FUN_201649d8(uVar4,uVar5,0,0x40140000);
  uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
  local_d0 = uVar17;
  uVar18 = FUN_201649d8(uVar6,uVar7,0,0x40140000);
  uVar4 = (undefined4)((ulonglong)uVar18 >> 0x20);
  local_48 = uVar18;
  uVar19 = FUN_201649d8((undefined4)local_30,local_30._4_4_,0,0x40140000);
  uVar6 = (undefined4)((ulonglong)uVar19 >> 0x20);
  local_30 = uVar19;
  uVar20 = FUN_201649d8((undefined4)local_60,local_60._4_4_,0,0x40140000);
  local_60 = uVar20;
  uVar20 = FUN_20164fa4((undefined4)local_78,local_78._4_4_,(int)uVar18,uVar4);
  local_80 = (undefined4)((ulonglong)uVar20 >> 0x20);
  local_7c = (undefined4)uVar20;
  local_78._0_4_ = local_7c;
  local_78._4_4_ = local_80;
  local_b0 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,uVar5);
  uVar16 = FUN_20164da8((int)local_b0,(int)((ulonglong)local_b0 >> 0x20),(undefined4)local_78,
                        local_78._4_4_);
  local_a8 = FUN_20164fa4((undefined4)local_88,local_88._4_4_,(int)uVar18,uVar4);
  uVar2 = (ulonglong)local_a8 >> 0x20;
  uVar4 = (undefined4)local_a8;
  uVar17 = FUN_20164fa4(uVar8,uVar12,(int)uVar17,uVar5);
  uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = FUN_20164da8((int)uVar17,uVar5,uVar4,(int)uVar2);
  uVar16 = FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar15 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar9 = (undefined4)uVar16;
  local_90._4_4_ = local_80;
  local_90._0_4_ = local_7c;
  uVar16 = FUN_20164fa4(uVar11,(undefined4)local_c8,(int)uVar19,uVar6);
  uVar4 = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_90 = FUN_20164da8((int)uVar16,uVar4,(undefined4)local_90,local_90._4_4_);
  local_c8 = local_a8;
  uVar18 = FUN_20164fa4((undefined4)local_98,local_98._4_4_,(int)uVar19,uVar6);
  uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = FUN_20164da8((int)uVar18,uVar6,(undefined4)local_c8,local_c8._4_4_);
  uVar19 = FUN_20164fa4((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(undefined4)local_90,
                        local_90._4_4_);
  uVar19 = FUN_201649d8((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar9,uVar15);
  *param_1 = uVar19;
  uVar18 = FUN_20164da8((undefined4)local_b0,local_b0._4_4_,(int)uVar18,uVar6);
  uVar16 = FUN_20164da8((int)uVar17,uVar5,(int)uVar16,uVar4);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar18,
                        (int)((ulonglong)uVar18 >> 0x20));
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[1] = uVar16;
  local_b0._4_4_ = (undefined4)local_c0;
  local_b0._0_4_ = uVar11;
  local_98._0_4_ = uVar12;
  uVar16 = FUN_20164da8(uVar8,uVar12,uVar11);
  uVar5 = local_d8._4_4_;
  uVar4 = (undefined4)local_d8;
  local_c8 = local_40;
  uVar17 = FUN_20164da8((undefined4)local_d8,local_d8._4_4_);
  FUN_20164fa4((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
               (int)((ulonglong)uVar16 >> 0x20));
  local_c0 = local_48;
  uVar16 = FUN_20164da8();
  uVar7 = local_d0._4_4_;
  uVar6 = (undefined4)local_d0;
  uVar17 = FUN_20164da8((undefined4)local_d0,local_d0._4_4_,(undefined4)local_c8,local_c8._4_4_);
  local_90 = local_30;
  uVar18 = FUN_20164da8(uVar8,(undefined4)local_98);
  FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
               (int)((ulonglong)uVar17 >> 0x20));
  local_b8 = local_50;
  uVar17 = FUN_20164da8();
  uVar18 = FUN_20164da8(uVar4,uVar5,(undefined4)local_90,local_90._4_4_);
  local_c8 = uVar18;
  uVar18 = FUN_20164da8(uVar6,uVar7,(undefined4)local_b0,local_b0._4_4_);
  FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(undefined4)local_c8,local_c8._4_4_);
  local_c8 = local_58;
  uVar18 = FUN_20164da8();
  uVar17 = FUN_20164888((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                        (int)((ulonglong)uVar17 >> 0x20));
  uVar16 = FUN_20164888((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[2] = uVar16;
  uVar16 = FUN_20164fa4((undefined4)local_c8,local_c8._4_4_,(undefined4)local_c0,local_c0._4_4_);
  uVar14 = local_60._4_4_;
  uVar13 = (undefined4)local_60;
  local_90 = local_68;
  uVar17 = FUN_20164fa4();
  local_98._4_4_ = (undefined4)((ulonglong)uVar17 >> 0x20);
  local_9c = (undefined4)uVar17;
  local_b0 = FUN_20164da8(local_9c,local_98._4_4_,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_20164fa4((undefined4)local_b8,local_b8._4_4_,(undefined4)local_c0,local_c0._4_4_);
  uVar12 = local_70._4_4_;
  uVar11 = (undefined4)local_70;
  local_88._0_4_ = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_a0 = (undefined4)uVar16;
  uVar16 = FUN_20164fa4((undefined4)local_70,local_70._4_4_,uVar13,uVar14);
  local_a8 = uVar16;
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),local_a0,(undefined4)local_88);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[3] = uVar16;
  uVar16 = FUN_20164fa4(uVar4,uVar5,uVar6,uVar7);
  uVar16 = FUN_20164da8((undefined4)local_a8,local_a8._4_4_,(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  local_b0 = uVar16;
  uVar16 = FUN_20164fa4(uVar8,(undefined4)local_98,uVar6,uVar7);
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),local_9c,local_98._4_4_);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[4] = uVar16;
  uVar16 = FUN_20164da8(uVar8,(undefined4)local_98,(undefined4)local_90,local_90._4_4_);
  local_b0 = uVar16;
  uVar16 = FUN_20164da8(uVar4,uVar5,uVar11,uVar12);
  uVar16 = FUN_20164fa4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        local_b0._4_4_);
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_c0,
                        local_c0._4_4_);
  local_c0._0_4_ = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_b0._0_4_ = (undefined4)uVar16;
  uVar16 = FUN_20164da8(uVar6,uVar7,uVar11,uVar12);
  uVar17 = FUN_20164da8(uVar8,(undefined4)local_98,uVar13,uVar14);
  uVar16 = FUN_20164fa4((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_20164da8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b8,
                        local_b8._4_4_);
  uVar17 = FUN_20164da8(uVar4,uVar5,uVar13,uVar14);
  uVar18 = FUN_20164da8(uVar6,uVar7,(undefined4)local_90,local_90._4_4_);
  uVar17 = FUN_20164fa4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                        (int)((ulonglong)uVar17 >> 0x20));
  uVar17 = FUN_20164da8((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(undefined4)local_c8,
                        local_c8._4_4_);
  uVar16 = FUN_20164888((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                        (int)((ulonglong)uVar16 >> 0x20));
  uVar16 = FUN_20164888((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(undefined4)local_b0,
                        (undefined4)local_c0);
  uVar16 = FUN_201649d8((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar15);
  param_1[5] = uVar16;
  return;
}


// ===== touch_cal_init @ 20102f34 (88 bytes)

/* boot: measured := reference points, load the record from flash */

void touch_cal_init(void)

{
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  memcpy(&DAT_20808bf8,&DAT_20800060,0x14);
  touch_cal_fit(&local_38);
  touch_cal_load(&DAT_183d0000,&local_38);
  DAT_20808c10 = local_38;
  DAT_20808c14 = uStack_34;
  DAT_20808c18 = uStack_30;
  DAT_20808c1c = uStack_2c;
  DAT_20808c20 = local_28;
  DAT_20808c24 = uStack_24;
  DAT_20808c28 = uStack_20;
  DAT_20808c2c = uStack_1c;
  DAT_20808c30 = local_18;
  DAT_20808c34 = uStack_14;
  DAT_20808c38 = uStack_10;
  DAT_20808c3c = uStack_c;
  return;
}


// ===== touch_cal_set_point @ 20102f8c (68 bytes)

void touch_cal_set_point(int param_1,uint param_2,undefined2 *param_3)

{
  if (param_2 < 5) {
    if (param_1 == 0) {
      (&DAT_20800060)[param_2 * 2] = *param_3;
      (&DAT_20800062)[param_2 * 2] = param_3[1];
      return;
    }
    (&DAT_20808bf8)[param_2 * 2] = *param_3;
    (&DAT_20808bfa)[param_2 * 2] = param_3[1];
  }
  return;
}


// ===== touch_cal_store_points @ 20102fd0 (144 bytes)

/* set 4 points (ref set 0 / measured set 1); set 1 -> fit + save */

void touch_cal_store_points(int param_1,int param_2)

{
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  touch_cal_set_point(param_1,2,param_2);
  touch_cal_set_point(param_1,3,param_2 + 4);
  touch_cal_set_point(param_1,0,param_2 + 8);
  touch_cal_set_point(param_1,1,param_2 + 0xc);
  if (param_1 != 0) {
    touch_cal_fit(&local_40);
    touch_cal_save(&local_40);
    DAT_20808c10 = local_40;
    DAT_20808c14 = uStack_3c;
    DAT_20808c18 = uStack_38;
    DAT_20808c1c = uStack_34;
    DAT_20808c20 = local_30;
    DAT_20808c24 = uStack_2c;
    DAT_20808c28 = uStack_28;
    DAT_20808c2c = uStack_24;
    DAT_20808c30 = local_20;
    DAT_20808c34 = uStack_1c;
    DAT_20808c38 = uStack_18;
    DAT_20808c3c = uStack_14;
  }
  return;
}


// ===== touch_cal_apply @ 20103060 (260 bytes)

/* (x, y) -> calibrated pixel, clamp 0..799 / 0..479 */

void touch_cal_apply(undefined4 param_1,undefined4 param_2,short *param_3,short *param_4)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar5 = FUN_20164d54(param_2);
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar6 = FUN_20164da8((int)uVar5,uVar3,DAT_20808c18,DAT_20808c1c);
  uVar7 = FUN_20164d54(param_1);
  uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
  uVar8 = FUN_20164da8((int)uVar7,uVar4,DAT_20808c10,DAT_20808c14);
  uVar6 = FUN_20164888((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar6,
                       (int)((ulonglong)uVar6 >> 0x20));
  uVar6 = FUN_20164888((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),DAT_20808c20,DAT_20808c24);
  FUN_20164888((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fe00000);
  sVar1 = FUN_20164c90();
  uVar5 = FUN_20164da8((int)uVar5,uVar3,DAT_20808c30,DAT_20808c34);
  uVar6 = FUN_20164da8((int)uVar7,uVar4,DAT_20808c28,DAT_20808c2c);
  uVar5 = FUN_20164888((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                       (int)((ulonglong)uVar5 >> 0x20));
  uVar5 = FUN_20164888((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_20808c38,DAT_20808c3c);
  FUN_20164888((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x3fe00000);
  sVar2 = FUN_20164c90();
  if (sVar1 < 0) {
    sVar1 = 0;
  }
  else if (799 < sVar1) {
    sVar1 = 799;
  }
  if (sVar2 < 0) {
    sVar2 = 0;
  }
  else if (0x1df < sVar2) {
    sVar2 = 0x1df;
  }
  *param_3 = sVar1;
  *param_4 = sVar2;
  return;
}


// ===== touch_cal_selftest @ 20103164 (40 bytes)

/* apply to (100,100) after init (result unused) */

void touch_cal_selftest(void)

{
  undefined1 auStack_10 [4];
  undefined1 auStack_c [8];
  
  touch_cal_init();
  touch_cal_apply(100,100,auStack_10,auStack_c);
  return;
}


// ===== tsc2007_write_cmd @ 20103198 (96 bytes)

/* RIIC2 write of one command byte to 0x48 */

undefined4 tsc2007_write_cmd(undefined4 param_1)

{
  int iVar1;
  undefined4 uStack_10;
  
  uStack_10 = param_1;
  FUN_20120674(2,0);
  iVar1 = FUN_20120750(2,0x90,0);
  if (iVar1 == 0) {
    FUN_2012081c(2,&uStack_10,1);
  }
  FUN_20120674(2);
  FUN_20120bc8(2);
  return 0;
}


// ===== tsc2007_read12 @ 201031f8 (248 bytes)

/* command byte, then read 2 bytes -> 12-bit result (-1/-2 on bus error) */

uint tsc2007_read12(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  byte local_14;
  byte local_13;
  undefined4 uStack_10;
  
  uStack_10 = param_1;
  iVar1 = FUN_20120674(2,0);
  if (iVar1 == 0) {
    iVar1 = FUN_20120750(2,0x90,0);
    if ((iVar1 == 0) && (iVar1 = FUN_2012081c(2,&uStack_10,1), iVar1 == 0)) {
      itron_dly_tsk(1);
      FUN_20120674(2,1);
      iVar1 = FUN_20120750(2,0x91,1,0);
      if (iVar1 == 0) {
        iVar1 = FUN_20120a9c(2,&local_14);
      }
    }
    if (iVar1 == -2) {
      FUN_20120674(2);
      FUN_20120bac(2);
      FUN_20120bc8(2);
      uVar2 = 0xfffffffe;
    }
    else {
      uVar2 = (uint)local_14 << 4 | (int)(uint)local_13 >> 4;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== tsc2007_pressure @ 201032f0 (248 bytes)

/* Rtouch = 400 * X/4096 * (Z2/Z1 - 1) */

undefined4 tsc2007_pressure(short *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = 0;
  if (*param_1 == 0xfff) {
    *param_1 = 0;
  }
  if ((*param_1 != 0) && (param_1[2] != 0)) {
    uVar2 = FUN_20164d82(param_1[2]);
    uVar3 = FUN_20164d82(param_1[3]);
    uVar2 = FUN_201649d8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                         (int)((ulonglong)uVar2 >> 0x20));
    uVar2 = FUN_20164fa4((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x3ff00000);
    uVar3 = FUN_20164d82(*param_1);
    uVar3 = FUN_201649d8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x40b00000);
    uVar3 = FUN_20164da8(0,0x40790000,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    FUN_20164da8((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                 (int)((ulonglong)uVar2 >> 0x20));
    uVar1 = FUN_20164cf0();
  }
  return uVar1;
}


// ===== tsc2007_tint_isr @ 201033e8 (124 bytes)

/* IRQ3 (TINT falling): wake task_tsc2007 (was intc_irq_setup) */

void tsc2007_tint_isr(void)

{
  ushort uVar1;
  
  gic_disable_irq(0x23);
  DAT_20808c40 = DAT_20808c40 + 1;
  DAT_20800074 = DAT_20800074 + 1;
  itron_iwup_tsk(DAT_20800088);
  uVar1 = DAT_fcfef804;
  if ((uVar1 & 8) != 0) {
    uVar1 = DAT_fcfef804;
    DAT_fcfef804 = uVar1 & 0xfff7;
  }
  return;
}

