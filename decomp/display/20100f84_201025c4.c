// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20100f84 @ 20100f84 (84 bytes)

void FUN_20100f84(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 in_cr0;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    coproc_moveto_Invalidate_Entire_Instruction(param_1);
  }
  else {
    uVar2 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
    iVar1 = 0x10 << (uVar2 & 7);
    uVar2 = param_2 + param_1;
    param_1 = param_1 & ~(iVar1 - 1U);
    do {
      coproc_moveto_Invalidate_Instruction_Cache_by_MVA(param_1);
      param_1 = param_1 + iVar1;
    } while (param_1 < uVar2);
  }
  coproc_moveto_Instruction_cache(param_1,6);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


// ===== dcache_invalidate_range @ 20100fd8 (68 bytes)

/* (addr, size): DCIMVAC per cache line over the range, or the whole cache (dcache_setway_all(2))
   when addr or size is 0 [fact] */

uint dcache_invalidate_range(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 in_cr0;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
    iVar1 = 0x10 << (uVar2 & 7);
    uVar2 = param_1 & ~(iVar1 - 1U);
    do {
      coproc_moveto_Invalidate_Data_Cache_by_MVA(uVar2);
      uVar2 = uVar2 + iVar1;
    } while (uVar2 < param_2 + param_1);
    DataSynchronizationBarrier(0xf);
    return uVar2;
  }
  dcache_setway_all(2);
  return param_1;
}


// ===== dcache_invalidate_all @ 2010101c (20 bytes)

/* dcache_setway_all(2) (invalidate by set/way) [fact] */

undefined4 dcache_invalidate_all(undefined4 param_1)

{
  dcache_setway_all(2);
  return param_1;
}


// ===== dcache_clean_range @ 20101030 (88 bytes)

/* (addr, len): CP15 clean D-cache line by MVA over the range (line size from CTR), then DSB [fact]
    */

uint dcache_clean_range(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 in_cr0;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
    iVar1 = 0x10 << (uVar2 & 7);
    uVar2 = param_1 & ~(iVar1 - 1U);
    do {
      coproc_moveto_Clean_Data_Cache_by_MVA(uVar2);
      uVar2 = uVar2 + iVar1;
    } while (uVar2 < param_2 + param_1);
    DataSynchronizationBarrier(0xf);
    return uVar2;
  }
  dcache_setway_all(1);
  return param_1;
}


// ===== dcache_clean_invalidate_range @ 20101088 (88 bytes)

/* (addr, size): DCCIMVAC per cache line over the range; Reset_Handler, task_audio_codec and
   sdhi_read_block use it [fact] */

uint dcache_clean_invalidate_range(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 in_cr0;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
    iVar1 = 0x10 << (uVar2 & 7);
    uVar2 = param_1 & ~(iVar1 - 1U);
    do {
      coproc_moveto_Invalidate_Entire_Data_by_MVA(uVar2);
      uVar2 = uVar2 + iVar1;
    } while (uVar2 < param_2 + param_1);
    DataSynchronizationBarrier(0xf);
    return uVar2;
  }
  dcache_setway_all(0);
  return param_1;
}


// ===== dcache_setway_all @ 201010e0 (164 bytes)

/* (op): walks every set and way of the data cache levels in CLIDR: op 0 clean and invalidate
   (DCCISW), 1 clean (DCCSW), 2 invalidate (DCISW) [fact for the CP15 operations] */

longlong dcache_setway_all(int param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  uVar2 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  if ((uVar2 & 0x7000000) != 0) {
    uVar7 = 0;
    do {
      param_2 = uVar2 >> (uVar7 + (uVar7 >> 1) & 0xff) & 7;
      if (param_2 != 1) {
        if (param_2 == 0) goto LAB_20101178;
        coprocessor_moveto(0xf,2,0,uVar7,in_cr0,in_cr0);
        InstructionSynchronizationBarrier(0xf);
        uVar3 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar4 = uVar3 >> 3 & 0x3ff;
        uVar5 = uVar3 >> 0xd & 0x7fff;
        do {
          uVar6 = uVar4;
          do {
            param_2 = uVar7 | uVar5 << (uVar3 & 7) + 4 | uVar6 << LZCOUNT(uVar4);
            if (param_1 < 1) {
              coproc_moveto_Invalidate_Entire_Data_by_Index(param_2);
            }
            if (param_1 == 1) {
              coproc_moveto_Clean_Data_Cache_by_Index(param_2);
            }
            if (1 < param_1) {
              coprocessor_moveto(0xf,0,2,param_2,in_cr7,in_cr14);
            }
            bVar1 = 0 < (int)uVar6;
            uVar6 = uVar6 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar5;
          uVar5 = uVar5 - 1;
        } while (bVar1);
      }
      uVar7 = uVar7 + 2;
    } while ((int)uVar7 < (int)((uVar2 & 0x7000000) >> 0x17));
    DataSynchronizationBarrier(0xf);
  }
LAB_20101178:
  coprocessor_moveto(0xf,2,0,0,in_cr0,in_cr0);
  return (ulonglong)param_2 << 0x20;
}


// ===== pinmux_init @ 20101190 (2512 bytes)

/* PFC setup of every port pin (2.5 KB of calls) */

void pinmux_init(void)

{
  gpio_cfg_input(0,0);
  gpio_cfg_input(0,1);
  gpio_cfg_out_low(0,2);
  gpio_cfg_out_low(0,3);
  gpio_cfg_input(0,4);
  gpio_cfg_input(0,5);
  gpio_cfg_out_low(1,0);
  gpio_cfg_out_low(1,1);
  gpio_cfg_out_low(1,2);
  gpio_cfg_alt(1,3,4,0);
  gpio_cfg_alt(1,4,1,3);
  gpio_cfg_alt(1,5,1,3);
  gpio_cfg_input(1,6);
  gpio_cfg_input(1,7);
  gpio_cfg_alt(1,8,1,0);
  gpio_cfg_alt(1,9,1,0);
  gpio_cfg_input(1,10);
  gpio_cfg_alt(1,0xb,1,0);
  gpio_cfg_alt(1,0xc,1,0);
  gpio_cfg_input(1,0xd);
  gpio_cfg_alt(1,0xe,1,0);
  gpio_cfg_input(1,0xf);
  gpio_cfg_alt(2,0,6,0);
  gpio_cfg_input(2,1);
  gpio_cfg_input(2,2);
  gpio_cfg_input(2,3);
  gpio_cfg_input(2,4);
  gpio_cfg_input(2,5);
  gpio_cfg_input(2,6);
  gpio_cfg_out_low(2,7);
  gpio_cfg_alt(2,8,8,0);
  gpio_cfg_alt(2,9,8,0);
  gpio_cfg_alt(2,10,8,0);
  gpio_cfg_alt(2,0xb,8,0);
  gpio_cfg_alt(2,0xc,2,0);
  gpio_cfg_alt(2,0xd,2,0);
  gpio_cfg_alt(2,0xe,2,0);
  gpio_cfg_alt(2,0xf,2,0);
  gpio_cfg_input(3,0);
  gpio_cfg_alt(3,1,3,0);
  gpio_cfg_input(3,2);
  gpio_cfg_alt(3,3,3,0);
  gpio_cfg_alt(3,4,1,0);
  gpio_cfg_input(3,5);
  gpio_cfg_input(3,6);
  gpio_cfg_input(3,7);
  gpio_cfg_alt(3,8,1,0);
  gpio_cfg_alt(3,9,1,0);
  gpio_cfg_alt(3,10,1,0);
  gpio_cfg_alt(3,0xb,1,0);
  gpio_cfg_alt(3,0xc,1,0);
  gpio_cfg_alt(3,0xd,1,0);
  gpio_cfg_alt(3,0xe,1,0);
  gpio_cfg_alt(3,0xf,1,0);
  gpio_cfg_alt(4,0,1,0);
  gpio_cfg_alt(4,1,1,0);
  gpio_cfg_input(4,2);
  gpio_cfg_out_low(4,3);
  gpio_cfg_input(4,4);
  gpio_cfg_input(4,5);
  gpio_cfg_out_low(4,6);
  gpio_cfg_alt(4,7,3,2);
  gpio_cfg_alt(4,8,1,0);
  gpio_cfg_alt(4,9,1,0);
  gpio_cfg_alt(4,10,1,0);
  gpio_cfg_alt(4,0xb,1,0);
  gpio_cfg_alt(4,0xc,1,0);
  gpio_cfg_alt(4,0xd,1,0);
  gpio_cfg_alt(4,0xe,1,0);
  gpio_cfg_alt(4,0xf,1,0);
  gpio_cfg_out_low(5,8);
  gpio_cfg_out_low(5,9);
  gpio_cfg_input(5,10);
  gpio_cfg_input(6,0);
  gpio_cfg_input(6,1);
  gpio_cfg_alt(6,2,7,0);
  gpio_cfg_alt(6,3,7,0);
  gpio_cfg_out_low(6,4);
  gpio_cfg_out_low(6,5);
  gpio_cfg_alt(6,6,5,0);
  gpio_cfg_alt(6,7,5,0);
  gpio_cfg_out_low(6,8);
  gpio_cfg_out_low(6,9);
  gpio_cfg_out_low(6,10);
  gpio_cfg_out_low(6,0xb);
  gpio_cfg_out_low(6,0xc);
  gpio_cfg_out_low(6,0xd);
  gpio_cfg_out_low(6,0xe);
  gpio_cfg_input(6,0xf);
  gpio_cfg_input(7,0);
  gpio_cfg_input(7,1);
  gpio_cfg_input(7,2);
  gpio_cfg_input(7,3);
  gpio_cfg_input(7,4);
  gpio_cfg_input(7,5);
  gpio_cfg_input(7,6);
  gpio_cfg_input(7,7);
  gpio_cfg_input(7,8);
  gpio_cfg_out_low(7,9);
  gpio_cfg_out_low(7,10);
  gpio_cfg_out_low(7,0xc);
  gpio_cfg_input(7,0xd);
  gpio_cfg_input(7,0xe);
  gpio_cfg_input(7,0xf);
  gpio_cfg_input(8,0);
  gpio_cfg_out_low(8,1);
  gpio_cfg_out_low(8,2);
  gpio_cfg_alt(8,3,3,0);
  gpio_cfg_alt(8,4,3,0);
  gpio_cfg_alt(8,5,3,0);
  gpio_cfg_alt(8,6,3,0);
  gpio_cfg_out_low(8,7);
  gpio_cfg_out_low(8,8);
  gpio_cfg_input(8,9);
  gpio_cfg_out_low(8,10);
  gpio_cfg_input(8,0xb);
  gpio_cfg_input(8,0xc);
  gpio_cfg_input(8,0xd);
  gpio_cfg_out_low(8,0xe);
  gpio_cfg_input(8,0xf);
  gpio_cfg_alt(9,0,4,0);
  gpio_cfg_input(9,1);
  gpio_cfg_alt(9,2,2,0);
  gpio_cfg_alt(9,3,2,0);
  gpio_cfg_alt(9,4,2,0);
  gpio_cfg_alt(9,5,2,0);
  gpio_cfg_alt(9,6,2,0);
  gpio_cfg_alt(9,7,2,0);
  gpio_cfg_alt(10,0,2,0);
  gpio_cfg_alt(10,1,2,0);
  gpio_cfg_input(10,2);
  gpio_cfg_alt(10,3,2,0);
  gpio_cfg_alt(10,4,2,2);
  gpio_cfg_input(10,5);
  gpio_cfg_input(10,6);
  gpio_cfg_input(10,7);
  gpio_cfg_alt(10,8,5,0);
  gpio_cfg_alt(10,9,5,0);
  gpio_cfg_alt(10,10,5,0);
  gpio_cfg_alt(10,0xb,5,0);
  gpio_cfg_alt(10,0xc,5,0);
  gpio_cfg_alt(10,0xd,5,0);
  gpio_cfg_out_low(10,0xe);
  gpio_cfg_input(10,0xf);
  gpio_cfg_input(0xb,0);
  gpio_cfg_input(0xb,1);
  gpio_cfg_out_high(0xb,2);
  gpio_cfg_input(0xb,3);
  gpio_cfg_alt(0xb,4,2,0);
  gpio_cfg_alt(0xb,5,2,0);
  gpio_cfg_alt(0xb,6,2,0);
  gpio_cfg_alt(0xb,7,2,0);
  gpio_cfg_alt(0xb,8,2,0);
  gpio_cfg_alt(0xb,9,2,0);
  gpio_cfg_alt(0xb,10,2,0);
  gpio_cfg_alt(0xb,0xb,2,0);
  gpio_cfg_input(0xb,0xc);
  gpio_cfg_input(0xb,0xd);
  gpio_cfg_input(0xb,0xe);
  gpio_cfg_alt(0xb,0xf,5,0);
  return;
}


// ===== backlight_enable @ 20101b60 (68 bytes)

/* P4_7 BLPWM alt3 (MTU2 out) + P10_4 level, or input */

void backlight_enable(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    gpio_cfg_input(4,7);
    uVar1 = 0x100000;
  }
  else {
    gpio_cfg_alt(4,7,3,2);
    uVar1 = 0x100010;
  }
  PORT_PSR10 = uVar1;
  return;
}


// ===== gpio_p8_14 @ 20101ba4 (24 bytes)

/* P8_14 via PSR8 */

void gpio_p8_14(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x40000000;
  }
  else {
    uVar1 = 0x40004000;
  }
  PORT_PSR8 = uVar1;
  return;
}


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
  PORT_PSR4 = uVar1;
  if (param_1 != 0) {
    uVar1 = 0x40004000;
  }
  else {
    uVar1 = 0x40000000;
  }
  PORT_PSR10 = uVar1;
  return;
}


// ===== gpio_p4_7 @ 20101c44 (24 bytes)

/* (v): PORT_PSR4 = 0x800000 / 0x800080: P4_7 low / high [fact] */

void gpio_p4_7(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x800000;
  }
  else {
    uVar1 = 0x800080;
  }
  PORT_PSR4 = uVar1;
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
  PORT_PSR7 = uVar1;
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
  PORT_PSR4 = uVar1;
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
  PORT_PSR8 = uVar1;
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
  PORT_PSR4 = uVar1;
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
  PORT_PSR11 = uVar1;
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
  PORT_PSR2 = uVar1 | 0x300000;
  PORT_PSR10 = uVar2 | 0x20000;
  return;
}


// ===== gpio_p2_4_5_clear @ 20101d14 (24 bytes)

/* P2_4, P2_5 and P10_1 low */

void gpio_p2_4_5_clear(void)

{
  PORT_PSR2 = 0x300000;
  PORT_PSR10 = 0x20000;
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


// ===== gpio_p8_6to9_3 @ 20101d40 (16 bytes)

/* PORT_PSR8 = 0x3C000C0: P8_6..P8_9 = 0b0011 (P8_6, P8_7 high) [fact] */

void gpio_p8_6to9_3(void)

{
  PORT_PSR8 = 0x3c000c0;
  return;
}


// ===== gpio_p8_6to9_8 @ 20101d50 (16 bytes)

/* PORT_PSR8 = 0x3C00200: P8_6..P8_9 = 0b1000 (P8_9 high) [fact] */

void gpio_p8_6to9_8(void)

{
  PORT_PSR8 = 0x3c00200;
  return;
}


// ===== gpio_p8_6to9_6 @ 20101d60 (16 bytes)

/* PORT_PSR8 = 0x3C00180: P8_6..P8_9 = 0b0110 (P8_7, P8_8 high) [fact] */

void gpio_p8_6to9_6(void)

{
  PORT_PSR8 = 0x3c00180;
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
  PORT_PSR7 = uVar1;
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
  
  uVar1 = PORT_PPR11;
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
    PORT_PSR8 = uVar1;
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
  PORT_PSR5 = uVar1 | uVar2;
  return;
}


// ===== lvds_pins_enable @ 20101dec (276 bytes)

/* P5_0..P5_7 LVDS (RA..RCK pairs) alt1, or output low */

void lvds_pins_enable(int param_1)

{
  if (param_1 != 0) {
    gpio_cfg_alt(5,0,1,1);
    gpio_cfg_alt(5,1,1,1);
    gpio_cfg_alt(5,2,1,1);
    gpio_cfg_alt(5,3,1,1);
    gpio_cfg_alt(5,4,1,1);
    gpio_cfg_alt(5,5,1,1);
    gpio_cfg_alt(5,6,1,1);
    gpio_cfg_alt(5,7,1,1);
    return;
  }
  gpio_cfg_out_low(5,0);
  gpio_cfg_out_low(5,1);
  gpio_cfg_out_low(5,2);
  gpio_cfg_out_low(5,3);
  gpio_cfg_out_low(5,4);
  gpio_cfg_out_low(5,5);
  gpio_cfg_out_low(5,6);
  gpio_cfg_out_low(5,7);
  return;
}


// ===== FUN_20101f00 @ 20101f00 (68 bytes)

undefined4 FUN_20101f00(int param_1,uint param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar1 = 1 << (param_2 & 0xff);
  if (param_1 == 6) {
    uVar2 = PORT_PPR6;
    if ((uVar2 & uVar1) == 0) {
      return 0;
    }
  }
  else {
    if (param_1 != 7) {
      return 0;
    }
    uVar2 = PORT_PPR7;
    if ((uVar2 & uVar1) == 0) {
      return 0;
    }
  }
  return 1;
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
  PORT_PSR2 = uVar1;
  return;
}


// ===== gpio_p2_7 @ 20101f74 (24 bytes)

/* (v): PORT_PSR2 = 0x800000 / 0x800080: P2_7 low / high [fact] */

void gpio_p2_7(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x800000;
  }
  else {
    uVar1 = 0x800080;
  }
  PORT_PSR2 = uVar1;
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
  PORT_PSR2 = uVar1;
  return;
}


// ===== led_set_one @ 20101fa4 (76 bytes)

/* one front LED (P6 pin table) on/off */

void led_set_one(int param_1,int param_2)

{
  byte local_10 [12];
  
  local_10[0] = 10;
  local_10[1] = 0xd;
  local_10[2] = 0xb;
  local_10[3] = 0xe;
  local_10[4] = 4;
  local_10[5] = 9;
  local_10[6] = 5;
  local_10[7] = 8;
  local_10[8] = 0xc;
  local_10[9] = 0;
  local_10[10] = 0;
  local_10[0xb] = 0;
  if (param_1 != 0) {
    gpio_cfg_out_high(6,(uint)local_10[param_2]);
    return;
  }
  gpio_cfg_out_low(6,(uint)local_10[param_2]);
  return;
}


// ===== led_set_mask @ 20102040 (88 bytes)

/* 8 front LEDs from a bit mask (D_RED, D_GREEN, D_WHITE, D_BLUE, RXBUSY, TX, STEPCH, VOX) */

void led_set_mask(uint param_1)

{
  uint uVar1;
  byte local_18 [8];
  
  uVar1 = 0;
  local_18[0] = 8;
  local_18[1] = 5;
  local_18[2] = 9;
  local_18[3] = 4;
  local_18[4] = 0xe;
  local_18[5] = 0xc;
  local_18[6] = 0xb;
  local_18[7] = 0xd;
  do {
    if ((param_1 >> (uVar1 & 0xff) & 1) == 0) {
      gpio_cfg_out_low(6,(uint)local_18[uVar1]);
    }
    else {
      gpio_cfg_out_high(6,(uint)local_18[uVar1]);
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 8);
  return;
}


// ===== cpg_set_clock_profile @ 201020a0 (144 bytes)

/* FRQCR + STBCR1..11 from a 2-entry table at 0x2016517C */

void cpg_set_clock_profile(int param_1)

{
  CPG_STBCR2 = (&DAT_2016517c)[param_1];
  CPG_STBCR3 = (&DAT_2016517e)[param_1];
  CPG_STBCR4 = (&DAT_20165180)[param_1];
  CPG_STBCR5 = (&DAT_20165182)[param_1];
  CPG_STBCR6 = (&DAT_20165184)[param_1];
  CPG_STBCR7 = (&DAT_20165186)[param_1];
  CPG_STBCR8 = (&DAT_20165188)[param_1];
  CPG_STBCR9 = (&DAT_2016518a)[param_1];
  CPG_STBCR10 = (&DAT_2016518c)[param_1];
  CPG_STBCR11 = (&DAT_2016518e)[param_1];
  CPG_STBCR12 = (&DAT_20165190)[param_1];
  return;
}


// ===== pointer_get_event @ 20102138 (400 bytes)

/* (evt, src 1 touch/0 mouse): 0 none 1 release 2 press 3 held 4 re-press 5 tap 6 release+tap */

void pointer_get_event(void *param_1,int param_2)

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
      *(undefined4 *)((int)param_1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)((int)param_1 + 8) = *(undefined4 *)(iVar2 + 8);
      *(undefined1 *)param_1 = 2;
      *piVar3 = 1;
      goto LAB_2010226c;
    }
    if (*piVar4 != 0) {
      DAT_20808bed = DAT_20808bed + '\x01';
      *(undefined4 *)((int)param_1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)((int)param_1 + 8) = *(undefined4 *)(iVar2 + 8);
      uVar1 = 5;
      goto LAB_201022a4;
    }
    DAT_20808bee = DAT_20808bee + '\x01';
    *(undefined4 *)((int)param_1 + 4) = 0;
    *(undefined4 *)((int)param_1 + 8) = 0;
    *(undefined1 *)param_1 = 0;
  }
  else {
    if (piVar3[1] != 0) {
      if (*piVar4 == 0) {
        DAT_20808be9 = DAT_20808be9 + '\x01';
        *(undefined4 *)((int)param_1 + 4) = *(undefined4 *)(iVar2 + 4);
        *(undefined4 *)((int)param_1 + 8) = *(undefined4 *)(iVar2 + 8);
        *(undefined1 *)param_1 = 3;
        *piVar3 = 1;
      }
      else {
        DAT_20808be8 = DAT_20808be8 + '\x01';
        *(undefined4 *)((int)param_1 + 4) = *(undefined4 *)(iVar2 + 4);
        *(undefined4 *)((int)param_1 + 8) = *(undefined4 *)(iVar2 + 8);
        *(undefined1 *)param_1 = 4;
        *piVar3 = 1;
      }
      goto LAB_2010226c;
    }
    if (*piVar4 == 0) {
      DAT_20808beb = DAT_20808beb + '\x01';
      *(undefined4 *)((int)param_1 + 4) = 0;
      *(undefined4 *)((int)param_1 + 8) = 0;
      *(undefined1 *)param_1 = 1;
    }
    else {
      DAT_20808bea = DAT_20808bea + '\x01';
      *(undefined4 *)((int)param_1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)((int)param_1 + 8) = *(undefined4 *)(iVar2 + 8);
      uVar1 = 6;
LAB_201022a4:
      *(undefined1 *)param_1 = uVar1;
    }
  }
  *piVar3 = 0;
LAB_2010226c:
  *piVar4 = 0;
  return;
}


// ===== touch_set_down @ 201022c8 (84 bytes)

/* pen sample (x, y) -> pointer source "touch" */

void touch_set_down(uint param_1,uint param_2)

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


// ===== FUN_2010233c @ 2010233c (12 bytes)

undefined4 FUN_2010233c(void)

{
  return DAT_20800034;
}


// ===== mouse_set_down @ 20102348 (84 bytes)

/* left button down at (x, y) -> pointer source "mouse" */

void mouse_set_down(uint param_1,uint param_2)

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

void mouse_right_get_event(void *param_1)

{
  undefined1 uVar1;
  
  if (DAT_2080004c == 0) {
    if (DAT_20800048 != 0) {
      *(undefined1 *)param_1 = 2;
      DAT_2080004c = 1;
      DAT_20800050 = 0;
      return;
    }
    if (DAT_20800050 == 0) {
      *(undefined1 *)param_1 = 0;
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
      *(undefined1 *)param_1 = uVar1;
      DAT_2080004c = 1;
      DAT_20800050 = 0;
      return;
    }
    if (DAT_20800050 == 0) {
      DAT_20808beb = DAT_20808beb + '\x01';
      *(undefined4 *)((int)param_1 + 4) = 0;
      *(undefined4 *)((int)param_1 + 8) = 0;
      *(undefined1 *)param_1 = 1;
      DAT_2080004c = 0;
      DAT_20800050 = 0;
      return;
    }
    uVar1 = 6;
  }
  *(undefined1 *)param_1 = uVar1;
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

void mouse_middle_get_event(void *param_1)

{
  undefined1 uVar1;
  
  if (DAT_20800058 == 0) {
    if (DAT_20800054 != 0) {
      *(undefined1 *)param_1 = 2;
      DAT_20800058 = 1;
      DAT_2080005c = 0;
      return;
    }
    if (DAT_2080005c == 0) {
      *(undefined1 *)param_1 = 0;
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
      *(undefined1 *)param_1 = uVar1;
      DAT_20800058 = 1;
      DAT_2080005c = 0;
      return;
    }
    if (DAT_2080005c == 0) {
      *(undefined4 *)((int)param_1 + 4) = 0;
      *(undefined4 *)((int)param_1 + 8) = 0;
      *(undefined1 *)param_1 = 1;
      DAT_20800058 = 0;
      DAT_2080005c = 0;
      return;
    }
    uVar1 = 6;
  }
  *(undefined1 *)param_1 = uVar1;
  DAT_20800058 = 0;
  DAT_2080005c = 0;
  return;
}


// ===== mouse_middle_down @ 2010256c (72 bytes)

void mouse_middle_down(void)

{
  bool bVar1;
  
  if ((((DAT_20800030 == 0 && DAT_20800034 == 0) && DAT_20800038 == 0) && DAT_20800048 == 0) &&
     (bVar1 = key_func_is_held(), !bVar1)) {
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

uint mouse_middle_is_func(void)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((DAT_2080005c != 0 || (DAT_20800058 != 0 || DAT_20800054 != 0)) &&
     (uVar1 = gui_middle_key(), uVar1 == 0x30f)) {
    uVar2 = 1;
  }
  return uVar2;
}

