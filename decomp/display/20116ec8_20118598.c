// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== power_on_full_init @ 20116ec8 (360 bytes)

/* standby -> full start: same init list as task_root full branch, run once (flag 0x208003A5) */

void power_on_full_init(void)

{
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_24;
  undefined1 *local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_18 [8];
  
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_1a = 0x80;
  local_1c = 0x80;
  local_1b = 0x80;
  local_28 = &local_1c;
  r_vdc5_display_calibration(0,&local_30);
  local_18[0] = 2;
  local_20 = local_18;
  r_vdc5_start_process(0,3,&local_20);
  local_18[0] = 3;
  local_20 = local_18;
  r_vdc5_start_process(0,4,&local_20);
  r_vdc5_start_process(0,5,&local_20);
  DAT_208003a0 = 1;
  FUN_20116da0(1);
  key_matrix_press_check();
  if (DAT_208003a5 == '\0') {
    gpio_p7_9_11(1);
    gpio_p8_14(1);
    lcd_power(1);
    cpg_set_clock_profile(1);
    dimmer_init();
    backlight_enable(0);
    backlight_init();
    FUN_20107e9c();
    mouse_cursor_init();
    FUN_201385b4();
    FUN_2013b97c();
    FUN_2013b4cc();
    adc_start_scan();
    DAT_208dc1c0 = uptest_init();
    DAT_208dc1c8 = cli_init();
    touch_init();
    DAT_208dc1d0 = keycode_init();
    DAT_208dc1dc = kbdtest_init();
    renc_init();
    link_ss_irq_init();
    DAT_208dc1d8 = sdr_debug_init();
    spi_slave_init();
    fwupdate_init();
    sdmenu_init();
    DAT_208003a5 = '\x01';
    touch_cal_init();
    audio_codec_init();
    DAT_208003a0 = 1;
  }
  else {
    gpio_p7_9_11(1);
    gpio_p8_14(1);
    lcd_power(1);
  }
  return;
}


// ===== FUN_20117030 @ 20117030 (152 bytes)

void FUN_20117030(void)

{
  int iVar1;
  
  DAT_208003a0 = 0;
  FUN_20116da0();
  led_set_one(0);
  led_set_mask(0);
  r_vdc5_stop_process(0,0xffffffff);
  iVar1 = gpio_read_bit(8,0xc);
  if (iVar1 == 0) {
    FUN_20116784();
    key_task_pause();
    itron_dly_tsk(100);
    gpio_ft4222_reset(0);
    gpio_rx_reset(0);
    gpio_qf_reset(1);
  }
  else {
    backlight_enable(0);
    lcd_power(0);
  }
  gpio_p7_9_11(0);
  gpio_p8_14(0);
  return;
}


// ===== task_root @ 201170c8 (356 bytes)

/* root task (pri 8), created by main; runs the whole init sequence */

void task_root(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_20800110 = hid_chain0_dispatch;
  DAT_20800114 = hid_chain1_dispatch;
  bootinfo_load();
  fb_clear_all();
  rtc_init();
  sd_fs_init();
  DAT_208dc1bc = fwdbg_init();
  loader_selfinstall();
  DAT_208003a1 = gpio_p2_0_debounced();
  DAT_208003a2 = DAT_208003a1;
  iVar1 = gpio_read_bit(8,0xc);
  DAT_208003a3 = iVar1 != 0;
  powon_init();
  key_init();
  DAT_208003a0 = boot_mode_full(DAT_208003a2,DAT_208003a3);
  cpg_set_clock_profile();
  gpio_rx_reset(1);
  if (DAT_208003a0 == '\0') {
    gpio_p8_14(0);
    mainlink_init();
    uVar2 = FUN_2014e710();
    periodic_wakeup_register(uVar2,0);
    iVar1 = periodic_wakeup_start();
    if (iVar1 != 0) {
      return;
    }
  }
  else {
    DAT_208003a5 = 1;
    gpio_p8_14();
    FUN_20116da0(1);
    dimmer_init();
    backlight_enable(0);
    backlight_init();
    FUN_20107e9c();
    mouse_cursor_init();
    FUN_201385b4();
    FUN_2013b97c();
    FUN_2013b4cc();
    adc_start_scan();
    DAT_208dc1c0 = uptest_init();
    DAT_208dc1c8 = cli_init();
    touch_init();
    DAT_208dc1d0 = keycode_init();
    DAT_208dc1dc = kbdtest_init();
    mainlink_init();
    renc_init();
    link_ss_irq_init();
    DAT_208dc1d8 = sdr_debug_init();
    spi_slave_init();
    fwupdate_init();
    sdmenu_init();
    uVar2 = FUN_2014e710();
    periodic_wakeup_register(uVar2,0);
    iVar1 = periodic_wakeup_start();
    if (iVar1 != 0) {
      return;
    }
    touch_cal_init();
    audio_codec_init();
  }
  gui_start();
  return;
}


// ===== FUN_2011722c @ 2011722c (56 bytes)

void FUN_2011722c(void)

{
  if (DAT_208003a0 != '\0') {
    DAT_20800493 = 1;
    return;
  }
  DAT_208003a1 = 0;
  DAT_208003a0 = 1;
  return;
}


// ===== FUN_20117260 @ 20117260 (28 bytes)

bool FUN_20117260(void)

{
  int iVar1;
  
  iVar1 = gpio_read_bit(8,0xc);
  return iVar1 != 0;
}


// ===== FUN_2011727c @ 2011727c (12 bytes)

undefined1 FUN_2011727c(void)

{
  return DAT_208003a0;
}


// ===== FUN_20117288 @ 20117288 (12 bytes)

void FUN_20117288(undefined1 param_1)

{
  DAT_208003a0 = param_1;
  return;
}


// ===== main @ 20117294 (312 bytes)

/* called from __rt_entry; creates tasks then idles */

void main(void)

{
  int iVar1;
  uint uVar2;
  
  mmu_cache_enable();
  pinmux_init();
  gpio_p7_9_11(1);
  kernel_heap_init();
  iVar1 = itron_acre_tsk(0,&DAT_20165a44);
  if (iVar1 < 1) {
    return;
  }
  ostm_init();
  if (DAT_208003d4 != 0) {
    return;
  }
  DAT_208003db = '\0';
  DAT_208003cc = DAT_208003cc & 0xffffff7f;
  do {
    if (DAT_208003db == '\0') {
      DAT_208003dc = 0;
    }
    else {
      DAT_208003dc = DAT_208003de;
    }
    software_interrupt(0);
    DAT_208dc17c = 9;
    if (DAT_208003b0 != (code *)0x0) {
      (*DAT_208003b0)();
    }
    uVar2 = 0xffffffff;
    while (DAT_208003dd == '\0') {
      if (uVar2 != 0) {
        uVar2 = uVar2 - 1;
      }
    }
    DAT_208003d0 = ~uVar2;
    software_interrupt(0);
    do {
      DAT_208003c8 = DAT_208003c8 + 1;
      if (DAT_208003c8 == 0) {
        DAT_208003c4 = DAT_208003c4 + 1;
      }
      FUN_201540c4();
      FUN_20153788();
      FUN_20153620();
      DAT_208003dd = DAT_208003dd + -1;
    } while (DAT_208003dd != '\0');
  } while( true );
}


// ===== FUN_201172ec @ 201172ec (20 bytes)

undefined4 FUN_201172ec(void)

{
  return 0x20a00000;
}


// ===== gic_set_priority @ 20117300 (60 bytes)

/* GICD_IPRIORITYR byte = prio << 3 */

void gic_set_priority(uint param_1,int param_2)

{
  *(uint *)((int)&DAT_e8201400 + (param_1 & 0xfffffffc)) =
       *(uint *)((int)&DAT_e8201400 + (param_1 & 0xfffffffc)) & ~(0xff << ((param_1 & 3) << 3)) |
       param_2 << (param_1 & 3) * 8 + 3;
  return;
}


// ===== gic_init @ 2011733c (592 bytes)

/* distributor/CPU interface set-up, 587 handler slots = gic_default_handler */

undefined4 gic_init(void)

{
  int iVar1;
  
  DAT_e8202000 = 0;
  iVar1 = 0;
  do {
    (&DAT_e8201080)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x13);
  DAT_e8201c00 = 0xaaaaaaaa;
  DAT_e8201c04 = 0x55;
  DAT_e8201c08 = 0xfffd5555;
  DAT_e8201c0c = 0x555fffff;
  DAT_e8201c10 = 0x55555555;
  DAT_e8201c14 = 0x55555555;
  DAT_e8201c18 = 0x55555555;
  DAT_e8201c1c = 0x55555555;
  DAT_e8201c20 = 0x5555f555;
  DAT_e8201c24 = 0x55555555;
  DAT_e8201c28 = 0x55555555;
  DAT_e8201c2c = 0xf5555555;
  DAT_e8201c30 = 0xf555f555;
  DAT_e8201c34 = 0x5555f555;
  DAT_e8201c38 = 0x55555555;
  DAT_e8201c3c = 0x55555555;
  DAT_e8201c40 = 0x55555555;
  DAT_e8201c44 = 0xfd555555;
  DAT_e8201c48 = 0x55555557;
  DAT_e8201c4c = 0x55555555;
  DAT_e8201c50 = 0x55555555;
  DAT_e8201c54 = 0x5f555555;
  DAT_e8201c58 = 0xfd55555f;
  DAT_e8201c5c = 0x55555557;
  iVar1 = 0x18;
  do {
    (&DAT_e8201c00)[iVar1] = 0xffffffff;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x25);
  DAT_e8201400 = 0x60687078;
  DAT_e8201404 = 0x40485058;
  DAT_e8201408 = 0x20283038;
  DAT_e820140c = 0x81018;
  iVar1 = 0x20;
  do {
    (&DAT_e8201400)[iVar1 / 4] = 0xf8f8f8f8;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x247);
  iVar1 = 0;
  do {
    (&DAT_e8201180)[(int)(iVar1 + ((uint)(iVar1 >> 0x1f) >> 0x1b)) >> 5] = 0xffffffff;
    iVar1 = iVar1 + 0x20;
  } while (iVar1 < 0x22b);
  iVar1 = 0x20;
  do {
    *(undefined4 *)(&UNK_e8201800 + (iVar1 / 4) * 4) = 0x1010101;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x247);
  iVar1 = 0;
  do {
    (&DAT_208dc1e0)[iVar1] = gic_default_handler;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x24b);
  iVar1 = 0;
  do {
    (&DAT_208dcb0c)[iVar1] = 0;
    (&DAT_208dcb8c)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  DAT_20800404 = 0;
  DAT_e8202004 = 0xf8;
  DAT_e8202000 = 3;
  DAT_e8201000 = 1;
  DAT_20800408 = 0;
  return 0;
}


// ===== FUN_2011758c @ 2011758c (40 bytes)

undefined4 FUN_2011758c(code *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < __main) || ((code *)0x20428834 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== isr_desc_check @ 201175b4 (40 bytes)

/* intno < 0x24B, prio < 0x20 */

undefined4 isr_desc_check(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 8) < 0x24b) && (*(uint *)(param_1 + 0x10) < 0x20)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffef;
  }
  return uVar1;
}


// ===== gic_install_isr_stub @ 201175dc (64 bytes)

/* copies a 0x58-byte ISR stub, sets priority and handler slot */

void gic_install_isr_stub(undefined4 param_1,int param_2)

{
  FUN_20100f84(param_1,0x58);
  FUN_20101030(param_1,0x58);
  gic_set_priority(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0x10));
  (&DAT_208dc1e0)[*(int *)(param_2 + 8)] = param_1;
  return;
}


// ===== gic_get_handler @ 2011761c (16 bytes)

undefined4 gic_get_handler(int param_1)

{
  return (&DAT_208dc1e0)[*(int *)(param_1 + 8)];
}


// ===== gic_def_inh @ 2011762c (136 bytes)

/* (intno, {attr, handler, prio}) direct handler, no stub */

undefined4 gic_def_inh(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  if (0x24a < param_1) {
    return 0xffffffef;
  }
  if (param_2 == 0) {
    uVar1 = FUN_2015686c();
    (&DAT_208dc1e0)[param_1] = gic_default_handler;
    gic_set_priority(param_1,0x1f);
  }
  else {
    if (0x1f < *(uint *)(param_2 + 8)) {
      return 0xffffffef;
    }
    uVar1 = FUN_2015686c();
    (&DAT_208dc1e0)[param_1] = *(undefined4 *)(param_2 + 4);
    gic_set_priority(param_1,*(undefined4 *)(param_2 + 8));
  }
  FUN_2015688c(uVar1);
  return 0;
}


// ===== gic_dispatch @ 201176b4 (116 bytes)

/* IRQ_Handler -> handler table 0x208DC1E0 */

undefined4 gic_dispatch(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)DAT_20800404;
  if (uVar3 < 0x20) {
    uVar2 = DAT_e820200c;
    uVar2 = uVar2 & 0x3ff;
    if (uVar2 < 0x24b) {
      uVar1 = (&DAT_208dc1e0)[uVar2];
      (&DAT_208dcb8c)[uVar3] = uVar2;
      uVar2 = DAT_e8202004;
      (&DAT_208dcb0c)[uVar3] = uVar2 & 0xff;
      DAT_20800404 = DAT_20800404 + 1;
      uVar3 = DAT_e8202014;
      DAT_e8202004 = uVar3 & 0xff;
      return uVar1;
    }
  }
  return 0;
}


// ===== gic_irq_exit @ 20117728 (52 bytes)

/* pops nesting stack, EOIR + PMR restore */

void gic_irq_exit(void)

{
  DAT_20800404 = DAT_20800404 - 1;
  DAT_e8202010 = (&DAT_208dcb8c)[DAT_20800404];
  DAT_e8202004 = (&DAT_208dcb0c)[DAT_20800404];
  return;
}


// ===== gic_enable_irq @ 2011775c (68 bytes)

/* enable one GIC interrupt ID */

undefined4 gic_enable_irq(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x24b) {
    FUN_2015686c();
    *(int *)(&DAT_e8201100 + (param_1 >> 5) * 4) = 1 << (param_1 & 0x1f);
    FUN_2015688c();
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffef;
  }
  return uVar1;
}


// ===== gic_disable_irq @ 201177a0 (68 bytes)

/* GICD_ICENABLER bit */

undefined4 gic_disable_irq(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x24b) {
    FUN_2015686c();
    (&DAT_e8201180)[param_1 >> 5] = 1 << (param_1 & 0x1f);
    FUN_2015688c();
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffef;
  }
  return uVar1;
}


// ===== ostm_init @ 201177e4 (84 bytes)

/* OSTM 0xFCFEC000 (system tick) */

int ostm_init(void)

{
  byte bVar1;
  int iVar2;
  
  DAT_fcfec000 = 319999;
  bVar1 = DAT_fcfec020;
  DAT_fcfec020 = bVar1 & 0xfd;
  DAT_fcfec020 = 1;
  iVar2 = itron_acre_isr(0,&DAT_20165a60);
  if (0 < iVar2) {
    gic_enable_irq(0x86);
    bVar1 = DAT_fcfec014;
    DAT_fcfec014 = bVar1 | 1;
    iVar2 = 0;
  }
  return iVar2;
}


// ===== ostm0_tick_isr @ 20117838 (92 bytes)

/* GIC 0x86: system time += 10000 us, kernel tick */

void ostm0_tick_isr(void)

{
  FUN_2015686c();
  DAT_20800408 = DAT_20800408 + 10000;
  FUN_2015688c();
  DAT_208dc17c = 0;
  DAT_208003dc = (char)DAT_201659d0 + '\x01';
  DAT_208003dd = DAT_208003dd + '\x01';
  return;
}


// ===== ostm_time_us @ 20117860 (148 bytes)

/* system time (us) interpolated from the OSTM0 counter */

undefined8 ostm_time_us(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  uVar1 = DAT_20800408;
  iVar3 = DAT_fcfec004;
  bVar2 = DAT_fcfec010;
  iVar3 = 320000 - iVar3;
  if ((bVar2 & 1) != 0) {
    uVar1 = DAT_e8205580;
    if ((uVar1 & 0x40) != 0) {
      iVar3 = DAT_fcfec004;
      iVar3 = 640000 - iVar3;
    }
    return CONCAT44(iVar3 * 0x333333a8,DAT_20800408 + ((uint)(iVar3 * 1000) / 320000) * 10);
  }
  DAT_20800408 = DAT_20800408 + 1;
  return CONCAT44(&DAT_20800408,uVar1 / 3);
}


// ===== delay_us @ 201178f4 (56 bytes)

/* busy-wait on ostm_time_us */

void delay_us(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if ((int)param_1 < 0) {
    DAT_20800408 = 0;
    return;
  }
  iVar1 = ostm_time_us();
  do {
    iVar2 = ostm_time_us();
  } while ((uint)(iVar2 - iVar1) < param_1);
  return;
}


// ===== r_vdc5_initialize @ 201179c0 (168 bytes)

/* (ch, vdc5_init_t*, init_func, user_num) */

undefined4 r_vdc5_initialize(undefined4 param_1,int param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  FUN_2011d080();
  iVar1 = FUN_2011d830(param_1,4);
  if ((iVar1 == 0) || (*(int *)(param_2 + 4) == 0)) {
    FUN_2011d19c(param_1,param_2);
    if (param_3 != (code *)0x0) {
      (*param_3)(param_4);
    }
    FUN_201193ec(param_1,param_2);
    vdc5_int_callbacks_clear(param_1);
    FUN_2011d7d8(param_1,0,1);
    if (*(int *)(param_2 + 4) != 0) {
      FUN_2011d7d8(param_1,4,1);
    }
  }
  else {
    uVar2 = 0xd;
  }
  return uVar2;
}


// ===== FUN_20117ad4 @ 20117ad4 (56 bytes)

undefined4 FUN_20117ad4(undefined4 param_1,undefined4 param_2)

{
  FUN_2011d1f4();
  FUN_201197c0(param_1,param_2);
  FUN_2011d7d8(param_1,1);
  return 0;
}


// ===== r_vdc5_sync_control @ 20117b0c (156 bytes)

/* (ch, vdc5_sync_ctrl_t*): total raster, H/V sync windows */

undefined4 r_vdc5_sync_control(uint param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    if (*param_2 == '\0') {
      uVar2 = param_1;
      if (param_2[1] != '\0') {
        uVar2 = (uint)(param_1 == 0);
      }
      iVar1 = FUN_2011d830(uVar2,1);
      if (iVar1 != 1) {
        return 0xb;
      }
    }
    FUN_2011d248(param_1,param_2);
    FUN_20119990(param_1,param_2);
    FUN_2011d7d8(param_1,2,1);
  }
  else {
    uVar3 = 9;
  }
  return uVar3;
}


// ===== r_vdc5_display_output @ 20117ba8 (108 bytes)

/* (ch, vdc5_output_t*): TCON pins, panel output */

undefined4 r_vdc5_display_output(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_2011d830(param_1,2);
    if (iVar1 == 1) {
      FUN_2011d2b4(param_1,param_2);
      FUN_20119e60(param_1,param_2);
      FUN_2011d7d8(param_1,3,1);
    }
    else {
      uVar2 = 10;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}


// ===== FUN_20117c64 @ 20117c64 (24 bytes)

uint FUN_20117c64(uint param_1)

{
  if ((1 < param_1) && (param_1 != 2)) {
    param_1 = 3;
  }
  return param_1;
}


// ===== FUN_20117c7c @ 20117c7c (176 bytes)

undefined4 FUN_20117c7c(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_20117c64(param_2);
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 != 0) {
    return 0xe;
  }
  iVar2 = param_1;
  if (param_2 != 0) {
    if (param_2 != 1) goto LAB_20117cf4;
    if (param_1 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 0;
    }
  }
  iVar2 = FUN_2011d830(iVar2,1);
  if (iVar2 != 1) {
    return 0xb;
  }
LAB_20117cf4:
  FUN_2011d374(param_1,uVar1,param_3);
  vdc5_config(param_1,uVar1,param_3);
  FUN_2011d7f0(param_1,param_2,1);
  return 0;
}


// ===== FUN_20117d2c @ 20117d2c (96 bytes)

undefined4 FUN_20117d2c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_20117c64(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d920(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    FUN_2011d3f0(param_1,uVar1,param_3);
    FUN_2011a6c8(param_1,uVar1,param_3);
  }
  return uVar3;
}


// ===== vdc5_layer_to_gr @ 20117d8c (72 bytes)

/* layer id 3..8 -> graphics index 0..5 */

undefined4 vdc5_layer_to_gr(undefined4 param_1)

{
  switch(param_1) {
  case 3:
    return 0;
  case 4:
    return 1;
  case 5:
    return 2;
  case 6:
    return 3;
  case 7:
    return 4;
  case 8:
    return 5;
  default:
    return 6;
  }
}


// ===== r_vdc5_read_data_control @ 20117dec (112 bytes)

/* (ch, layer, vdc5_read_t*): frame buffer, stride, format, window */

undefined4 r_vdc5_read_data_control(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 == 0) {
    FUN_2011d438(param_1,uVar1,param_3);
    FUN_2011af34(param_1,uVar1,param_3);
    FUN_2011d7f0(param_1,param_2,1);
  }
  else {
    uVar3 = 0xe;
  }
  return uVar3;
}


// ===== r_vdc5_change_read_process @ 20117e5c (96 bytes)

/* (ch, layer, {base,...}): new frame-buffer address */

undefined4 r_vdc5_change_read_process(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d920(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    FUN_2011d514(param_1,uVar1,param_3);
    FUN_2011b498(param_1,uVar1,param_3);
  }
  return uVar3;
}


// ===== r_vdc5_start_process @ 20117ebc (68 bytes)

/* (ch, layer, &disp_sel): show a layer (2 current, 3 blend) */

undefined4 r_vdc5_start_process(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 == -1) || (iVar1 = FUN_2011d8e8(), iVar1 != 0)) {
    FUN_2011b8b8(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0xe;
  }
  return uVar2;
}


// ===== r_vdc5_stop_process @ 20117f00 (60 bytes)

/* (ch, layer): hide a layer */

undefined4 r_vdc5_stop_process(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 == -1) || (iVar1 = FUN_2011d920(), iVar1 != 0)) {
    FUN_2011b988(param_1,param_2);
  }
  else {
    uVar2 = 0xe;
  }
  return uVar2;
}


// ===== FUN_20117f88 @ 20117f88 (64 bytes)

undefined4 FUN_20117f88(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,1);
  if (iVar1 == 1) {
    FUN_2011bb84(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}


// ===== FUN_20117fc8 @ 20117fc8 (140 bytes)

undefined4 FUN_20117fc8(uint param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*param_2 == '\0') {
    iVar1 = FUN_2011d84c(param_1,0);
    if (iVar1 != 0) goto LAB_2011801c;
    uVar3 = 1;
    uVar2 = (uint)(param_1 == 0);
LAB_2011804c:
    iVar1 = FUN_2011d84c(uVar2,uVar3);
  }
  else {
    if (*param_2 == '\x01') {
      uVar3 = 3;
      uVar2 = param_1;
      goto LAB_2011804c;
    }
    iVar1 = FUN_2011d84c(param_1,4);
  }
  if (iVar1 == 0) {
    return 0xe;
  }
LAB_2011801c:
  FUN_2011bc8c(param_1,param_2);
  return 0;
}


// ===== FUN_20118054 @ 20118054 (140 bytes)

undefined4
FUN_20118054(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_2 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 4;
  }
  iVar1 = FUN_2011d84c(param_1,uVar2);
  if (iVar1 == 0) {
    uVar3 = 0xe;
  }
  else {
    iVar1 = FUN_2011d6fc(param_1,param_2 != 0);
    if (iVar1 == 0) {
      uVar3 = 8;
    }
    else {
      FUN_2011bf00(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  return uVar3;
}


// ===== FUN_201180e0 @ 201180e0 (108 bytes)

undefined4 FUN_201180e0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_2 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 4;
  }
  iVar1 = FUN_2011d84c(param_1,uVar2);
  if (iVar1 == 0) {
    uVar3 = 0xe;
  }
  else {
    iVar1 = FUN_2011d6fc(param_1,param_2 != 0);
    if (iVar1 == 0) {
      uVar3 = 8;
    }
    else {
      FUN_2011bfc4(param_1,param_2,param_3,param_4);
    }
  }
  return uVar3;
}


// ===== FUN_2011814c @ 2011814c (80 bytes)

undefined4 FUN_2011814c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    FUN_2011c068(param_1,uVar1,param_3);
  }
  return uVar3;
}


// ===== r_vdc5_alpha_blending_rect @ 2011819c (120 bytes)

/* (ch, layer, on, {rect, alpha, ...}): alpha window / fades */

undefined4
r_vdc5_alpha_blending_rect(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  if (param_2 != 7) {
    iVar2 = FUN_2011d84c(param_1,param_2);
    if (iVar2 == 0) {
      return 0xe;
    }
    iVar2 = FUN_2011d6fc(param_1,uVar1);
    if (iVar2 == 1) {
      return 8;
    }
  }
  FUN_2011c22c(param_1,uVar1,param_3,param_4);
  return 0;
}


// ===== r_vdc5_chromakey @ 20118214 (112 bytes)

/* (ch, layer, on, {ck_color, rep_color, rep_alpha}); used with color 0 = transparent */

undefined4
r_vdc5_chromakey(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    iVar2 = FUN_2011d6fc(param_1,uVar1);
    if (iVar2 == 1) {
      uVar3 = 8;
    }
    else {
      FUN_2011c4d4(param_1,uVar1,param_3,param_4);
    }
  }
  return uVar3;
}


// ===== FUN_20118284 @ 20118284 (80 bytes)

undefined4 FUN_20118284(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    FUN_2011c5e4(param_1,uVar1,param_3);
  }
  return uVar3;
}


// ===== r_vdc5_display_calibration @ 201182d4 (56 bytes)

/* (ch, vdc5_disp_calibration_t*): used for the LCD contrast setting */

undefined4 r_vdc5_display_calibration(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,3);
  if (iVar1 == 1) {
    FUN_2011c6ec(param_1,param_2);
  }
  else {
    uVar2 = 0xc;
  }
  return uVar2;
}


// ===== FUN_2011830c @ 2011830c (64 bytes)

undefined4 FUN_2011830c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,3);
  if (iVar1 == 1) {
    FUN_2011c950(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0xc;
  }
  return uVar2;
}


// ===== vdc5_int_callbacks_clear @ 20118364 (76 bytes)

/* clears the 23 per-channel interrupt callbacks */

void vdc5_int_callbacks_clear(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    (&DAT_208dcc0c)[param_1 * 0x17 + iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x17);
  *(undefined4 *)(&DAT_20166a3c)[param_1 * 8] = 0;
  *(undefined4 *)(&DAT_20166a40)[param_1 * 8] = 0;
  *(undefined4 *)(&DAT_20166a44)[param_1 * 8] = 0;
  return;
}


// ===== r_vdc5_callback_isr @ 201183b0 (408 bytes)

/* (ch, {type, callback, line}): enable one VDC5 interrupt */

void r_vdc5_callback_isr(int param_1,byte *param_2)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (uint)*param_2;
  if (uVar5 < 8) {
    puVar3 = (uint *)(&DAT_20166a30)[param_1 * 8];
    puVar2 = (uint *)(&DAT_20166a3c)[param_1 * 8];
  }
  else if (uVar5 < 0x10) {
    puVar3 = (uint *)(&DAT_20166a34)[param_1 * 8];
    puVar2 = (uint *)(&DAT_20166a40)[param_1 * 8];
  }
  else {
    puVar3 = (uint *)(&DAT_20166a38)[param_1 * 8];
    puVar2 = (uint *)(&DAT_20166a44)[param_1 * 8];
  }
  uVar4 = *(uint *)(&DAT_20165b2c + uVar5 * 4);
  (&DAT_208dcc0c)[param_1 * 0x17 + uVar5] = *(undefined4 *)(param_2 + 4);
  if (*(int *)(param_2 + 4) == 0) {
    *puVar2 = *puVar2 & ~uVar4;
    *puVar3 = *puVar2;
    return;
  }
  if ((*puVar2 & uVar4) == 0) {
    *puVar2 = *puVar2 | uVar4;
    *puVar3 = *puVar2;
  }
  bVar1 = *param_2;
  if (bVar1 == 3) {
    puVar2 = *(uint **)(&DAT_20166418 + param_1 * 0x210);
    puVar3 = *(uint **)(&DAT_201663c8 + param_1 * 0x210);
    *puVar2 = *puVar2 & 0xfffff800;
    *puVar2 = (uint)*(ushort *)(param_2 + 8) | *puVar2;
    *puVar3 = *puVar3 | 0x10;
    return;
  }
  if (bVar1 == 9) {
    puVar2 = *(uint **)(&DAT_20165ce0 + param_1 * 0x228);
    *(undefined2 *)(&PTR_DAT_20165d08)[param_1 * 0x8a] = *(undefined2 *)(param_2 + 8);
    *puVar2 = *puVar2 | 1;
    return;
  }
  if (bVar1 != 0x10) {
    if (bVar1 == 0x13) {
      puVar2 = (uint *)(&PTR_DAT_201664c8)[param_1 * 0x84];
      puVar3 = (uint *)(&PTR_DAT_20166478)[param_1 * 0x84];
      *puVar2 = *puVar2 & 0xfffff800;
      *puVar2 = (uint)*(ushort *)(param_2 + 8) | *puVar2;
      *puVar3 = *puVar3 | 0x10;
    }
    return;
  }
  puVar2 = *(uint **)(&DAT_20165d98 + param_1 * 0x228);
  *(undefined2 *)(&PTR_DAT_20165dc0)[param_1 * 0x8a] = *(undefined2 *)(param_2 + 8);
  *puVar2 = *puVar2 | 1;
  return;
}


// ===== FUN_20118548 @ 20118548 (80 bytes)

void FUN_20118548(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 1) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 1) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xfffffffe;
    if (DAT_208dcc0c != (code *)0x0) {
      (*DAT_208dcc0c)(0);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}


// ===== FUN_20118598 @ 20118598 (80 bytes)

void FUN_20118598(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 0x10) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 0x10) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xffffffef;
    if (DAT_208dcc10 != (code *)0x0) {
      (*DAT_208dcc10)(1);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}

