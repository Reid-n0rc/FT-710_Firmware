// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffd3346 @ fffd3346 (132 bytes)

void FUN_fffd3346(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &g_opstate.presets[4].cat1_cat3_stop_bit;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].cat1_cat3_stop_bit;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].cat1_cat3_stop_bit;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].cat1_cat3_stop_bit;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].cat1_cat3_stop_bit;
  }
  menu_step_u8(0,1,local_8);
  return;
}


// ===== menu_ex060105_step @ fffd33ca (6 bytes)

/* Menu item ex060105 AGC FAST DELAY: on_step (#74) */

void menu_ex060105_step(void)

{
  FUN_fffd33e8(1);
  return;
}


// ===== menu_ex060205_step @ fffd33d0 (6 bytes)

/* Menu item ex060205 AGC FAST DELAY: on_step (#74) */

void menu_ex060205_step(void)

{
  FUN_fffd33e8(2);
  return;
}


// ===== menu_ex060305_step @ fffd33d6 (6 bytes)

/* Menu item ex060305 AGC FAST DELAY: on_step (#74) */

void menu_ex060305_step(void)

{
  FUN_fffd33e8(3);
  return;
}


// ===== menu_ex060405_step @ fffd33dc (6 bytes)

/* Menu item ex060405 AGC FAST DELAY: on_step (#74) */

void menu_ex060405_step(void)

{
  FUN_fffd33e8(4);
  return;
}


// ===== menu_ex060505_step @ fffd33e2 (6 bytes)

/* Menu item ex060505 AGC FAST DELAY: on_step (#74) */

void menu_ex060505_step(void)

{
  FUN_fffd33e8(5);
  return;
}


// ===== FUN_fffd33e8 @ fffd33e8 (133 bytes)

void FUN_fffd33e8(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &g_opstate.presets[4].agc_fast_delay;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].agc_fast_delay;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].agc_fast_delay;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].agc_fast_delay;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].agc_fast_delay;
  }
  menu_step_u8(0,199,local_8);
  return;
}


// ===== menu_ex060106_step @ fffd346d (6 bytes)

/* Menu item ex060106 AGC MID DELAY: on_step (#74) */

void menu_ex060106_step(void)

{
  FUN_fffd348b(1);
  return;
}


// ===== menu_ex060206_step @ fffd3473 (6 bytes)

/* Menu item ex060206 AGC MID DELAY: on_step (#74) */

void menu_ex060206_step(void)

{
  FUN_fffd348b(2);
  return;
}


// ===== menu_ex060306_step @ fffd3479 (6 bytes)

/* Menu item ex060306 AGC MID DELAY: on_step (#74) */

void menu_ex060306_step(void)

{
  FUN_fffd348b(3);
  return;
}


// ===== menu_ex060406_step @ fffd347f (6 bytes)

/* Menu item ex060406 AGC MID DELAY: on_step (#74) */

void menu_ex060406_step(void)

{
  FUN_fffd348b(4);
  return;
}


// ===== menu_ex060506_step @ fffd3485 (6 bytes)

/* Menu item ex060506 AGC MID DELAY: on_step (#74) */

void menu_ex060506_step(void)

{
  FUN_fffd348b(5);
  return;
}


// ===== FUN_fffd348b @ fffd348b (133 bytes)

void FUN_fffd348b(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &g_opstate.presets[4].agc_mid_delay;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].agc_mid_delay;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].agc_mid_delay;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].agc_mid_delay;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].agc_mid_delay;
  }
  menu_step_u8(0,199,local_8);
  return;
}


// ===== menu_ex060107_step @ fffd3510 (6 bytes)

/* Menu item ex060107 AGC SLOW DELAY: on_step (#74) */

void menu_ex060107_step(void)

{
  FUN_fffd352e(1);
  return;
}


// ===== menu_ex060207_step @ fffd3516 (6 bytes)

/* Menu item ex060207 AGC SLOW DELAY: on_step (#74) */

void menu_ex060207_step(void)

{
  FUN_fffd352e(2);
  return;
}


// ===== menu_ex060307_step @ fffd351c (6 bytes)

/* Menu item ex060307 AGC SLOW DELAY: on_step (#74) */

void menu_ex060307_step(void)

{
  FUN_fffd352e(3);
  return;
}


// ===== menu_ex060407_step @ fffd3522 (6 bytes)

/* Menu item ex060407 AGC SLOW DELAY: on_step (#74) */

void menu_ex060407_step(void)

{
  FUN_fffd352e(4);
  return;
}


// ===== menu_ex060507_step @ fffd3528 (6 bytes)

/* Menu item ex060507 AGC SLOW DELAY: on_step (#74) */

void menu_ex060507_step(void)

{
  FUN_fffd352e(5);
  return;
}


// ===== FUN_fffd352e @ fffd352e (133 bytes)

void FUN_fffd352e(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &g_opstate.presets[4].agc_slow_delay;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].agc_slow_delay;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].agc_slow_delay;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].agc_slow_delay;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].agc_slow_delay;
  }
  menu_step_u8(0,199,local_8);
  return;
}


// ===== menu_ex060108_step @ fffd35b3 (6 bytes)

/* Menu item ex060108 LCUT FREQ: on_step (#74) */

void menu_ex060108_step(void)

{
  FUN_fffd35d1(1);
  return;
}


// ===== menu_ex060208_step @ fffd35b9 (6 bytes)

/* Menu item ex060208 LCUT FREQ: on_step (#74) */

void menu_ex060208_step(void)

{
  FUN_fffd35d1(2);
  return;
}


// ===== menu_ex060308_step @ fffd35bf (6 bytes)

/* Menu item ex060308 LCUT FREQ: on_step (#74) */

void menu_ex060308_step(void)

{
  FUN_fffd35d1(3);
  return;
}


// ===== menu_ex060408_step @ fffd35c5 (6 bytes)

/* Menu item ex060408 LCUT FREQ: on_step (#74) */

void menu_ex060408_step(void)

{
  FUN_fffd35d1(4);
  return;
}


// ===== menu_ex060508_step @ fffd35cb (6 bytes)

/* Menu item ex060508 LCUT FREQ: on_step (#74) */

void menu_ex060508_step(void)

{
  FUN_fffd35d1(5);
  return;
}


// ===== FUN_fffd35d1 @ fffd35d1 (133 bytes)

void FUN_fffd35d1(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &g_opstate.presets[4].lcut_freq;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].lcut_freq;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].lcut_freq;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].lcut_freq;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].lcut_freq;
  }
  menu_step_u8(0,0x13,local_8);
  return;
}


// ===== menu_ex060109_step @ fffd3656 (6 bytes)

/* Menu item ex060109 LCUT SLOPE: on_step (#74) */

void menu_ex060109_step(void)

{
  FUN_fffd3674(1);
  return;
}


// ===== menu_ex060209_step @ fffd365c (6 bytes)

/* Menu item ex060209 LCUT SLOPE: on_step (#74) */

void menu_ex060209_step(void)

{
  FUN_fffd3674(2);
  return;
}


// ===== menu_ex060309_step @ fffd3662 (6 bytes)

/* Menu item ex060309 LCUT SLOPE: on_step (#74) */

void menu_ex060309_step(void)

{
  FUN_fffd3674(3);
  return;
}


// ===== menu_ex060409_step @ fffd3668 (6 bytes)

/* Menu item ex060409 LCUT SLOPE: on_step (#74) */

void menu_ex060409_step(void)

{
  FUN_fffd3674(4);
  return;
}


// ===== menu_ex060509_step @ fffd366e (6 bytes)

/* Menu item ex060509 LCUT SLOPE: on_step (#74) */

void menu_ex060509_step(void)

{
  FUN_fffd3674(5);
  return;
}


// ===== FUN_fffd3674 @ fffd3674 (132 bytes)

void FUN_fffd3674(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &g_opstate.presets[4].lcut_slope;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].lcut_slope;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].lcut_slope;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].lcut_slope;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].lcut_slope;
  }
  menu_step_u8(0,1,local_8);
  return;
}


// ===== menu_ex060110_step @ fffd36f8 (6 bytes)

/* Menu item ex060110 HCUT FREQ: on_step (#74) */

void menu_ex060110_step(void)

{
  FUN_fffd3716(1);
  return;
}


// ===== menu_ex060210_step @ fffd36fe (6 bytes)

/* Menu item ex060210 HCUT FREQ: on_step (#74) */

void menu_ex060210_step(void)

{
  FUN_fffd3716(2);
  return;
}


// ===== menu_ex060310_step @ fffd3704 (6 bytes)

/* Menu item ex060310 HCUT FREQ: on_step (#74) */

void menu_ex060310_step(void)

{
  FUN_fffd3716(3);
  return;
}


// ===== menu_ex060410_step @ fffd370a (6 bytes)

/* Menu item ex060410 HCUT FREQ: on_step (#74) */

void menu_ex060410_step(void)

{
  FUN_fffd3716(4);
  return;
}


// ===== menu_ex060510_step @ fffd3710 (6 bytes)

/* Menu item ex060510 HCUT FREQ: on_step (#74) */

void menu_ex060510_step(void)

{
  FUN_fffd3716(5);
  return;
}


// ===== FUN_fffd3716 @ fffd3716 (133 bytes)

void FUN_fffd3716(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &g_opstate.presets[4].hcut_freq;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].hcut_freq;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].hcut_freq;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].hcut_freq;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].hcut_freq;
  }
  menu_step_u8(0,0x43,local_8);
  return;
}


// ===== menu_ex060111_step @ fffd379b (6 bytes)

/* Menu item ex060111 HCUT SLOPE: on_step (#74) */

void menu_ex060111_step(void)

{
  FUN_fffd37b9(1);
  return;
}


// ===== menu_ex060211_step @ fffd37a1 (6 bytes)

/* Menu item ex060211 HCUT SLOPE: on_step (#74) */

void menu_ex060211_step(void)

{
  FUN_fffd37b9(2);
  return;
}


// ===== menu_ex060311_step @ fffd37a7 (6 bytes)

/* Menu item ex060311 HCUT SLOPE: on_step (#74) */

void menu_ex060311_step(void)

{
  FUN_fffd37b9(3);
  return;
}


// ===== menu_ex060411_step @ fffd37ad (6 bytes)

/* Menu item ex060411 HCUT SLOPE: on_step (#74) */

void menu_ex060411_step(void)

{
  FUN_fffd37b9(4);
  return;
}


// ===== menu_ex060511_step @ fffd37b3 (6 bytes)

/* Menu item ex060511 HCUT SLOPE: on_step (#74) */

void menu_ex060511_step(void)

{
  FUN_fffd37b9(5);
  return;
}


// ===== FUN_fffd37b9 @ fffd37b9 (132 bytes)

void FUN_fffd37b9(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &g_opstate.presets[4].hcut_slope;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].hcut_slope;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].hcut_slope;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].hcut_slope;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].hcut_slope;
  }
  menu_step_u8(0,1,local_8);
  return;
}


// ===== menu_ex060112_step @ fffd383d (6 bytes)

/* Menu item ex060112 USB OUT LEVEL: on_step (#74) */

void menu_ex060112_step(void)

{
  FUN_fffd385b(1);
  return;
}


// ===== menu_ex060212_step @ fffd3843 (6 bytes)

/* Menu item ex060212 USB OUT LEVEL: on_step (#74) */

void menu_ex060212_step(void)

{
  FUN_fffd385b(2);
  return;
}


// ===== menu_ex060312_step @ fffd3849 (6 bytes)

/* Menu item ex060312 USB OUT LEVEL: on_step (#74) */

void menu_ex060312_step(void)

{
  FUN_fffd385b(3);
  return;
}


// ===== menu_ex060412_step @ fffd384f (6 bytes)

/* Menu item ex060412 USB OUT LEVEL: on_step (#74) */

void menu_ex060412_step(void)

{
  FUN_fffd385b(4);
  return;
}


// ===== menu_ex060512_step @ fffd3855 (6 bytes)

/* Menu item ex060512 USB OUT LEVEL: on_step (#74) */

void menu_ex060512_step(void)

{
  FUN_fffd385b(5);
  return;
}


// ===== FUN_fffd385b @ fffd385b (133 bytes)

void FUN_fffd385b(byte param_1)

{
  bool bVar1;
  byte *local_8;
  
  if ((param_1 == 0) || (5 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (param_1 == 5) {
    local_8 = &g_opstate.presets[4].usb_out_level;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].usb_out_level;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].usb_out_level;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].usb_out_level;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].usb_out_level;
  }
  menu_step_u8(0,100,local_8);
  return;
}


// ===== menu_ex060113_step @ fffd38e0 (6 bytes)

/* Menu item ex060113 REAR OUT LEVEL: on_step (#74) */

void menu_ex060113_step(void)

{
  FUN_fffd38fe(1);
  return;
}

