// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex010302_step @ fffce280 (19 bytes)

/* Menu item ex010302 AF MIDDLE TONE GAIN: on_step (#74) */

void menu_ex010302_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex010302_af_middle_tone_gain);
  return;
}


// ===== menu_ex010303_step @ fffce293 (19 bytes)

/* Menu item ex010303 AF BASS GAIN: on_step (#74) */

void menu_ex010303_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex010303_af_bass_gain);
  return;
}


// ===== menu_ex010304_step @ fffce2a6 (19 bytes)

/* Menu item ex010304 AGC FAST DELAY: on_step (#74) */

void menu_ex010304_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex010304_agc_fast_delay);
  return;
}


// ===== menu_ex010305_step @ fffce2b9 (19 bytes)

/* Menu item ex010305 AGC MID DELAY: on_step (#74) */

void menu_ex010305_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex010305_agc_mid_delay);
  return;
}


// ===== menu_ex010306_step @ fffce2cc (19 bytes)

/* Menu item ex010306 AGC SLOW DELAY: on_step (#74) */

void menu_ex010306_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex010306_agc_slow_delay);
  return;
}


// ===== menu_ex010307_step @ fffce2df (14 bytes)

/* Menu item ex010307 LCUT FREQ: on_step (#74) */

void menu_ex010307_step(void)

{
  menu_step_lcut_freq(0x9a58);
  return;
}


// ===== menu_ex010308_step @ fffce2ed (18 bytes)

/* Menu item ex010308 LCUT SLOPE: on_step (#74) */

void menu_ex010308_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex010308_lcut_slope);
  return;
}


// ===== menu_ex010309_step @ fffce2ff (14 bytes)

/* Menu item ex010309 HCUT FREQ: on_step (#74) */

void menu_ex010309_step(void)

{
  menu_step_hcut_freq(0x9a5a);
  return;
}


// ===== menu_ex010310_step @ fffce30d (18 bytes)

/* Menu item ex010310 HCUT SLOPE: on_step (#74) */

void menu_ex010310_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex010310_hcut_slope);
  return;
}


// ===== menu_ex010311_step @ fffce31f (19 bytes)

/* Menu item ex010311 USB OUT LEVEL: on_step (#74) */

void menu_ex010311_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010311_usb_out_level);
  return;
}


// ===== menu_ex010312_step @ fffce332 (19 bytes)

/* Menu item ex010312 REAR OUT LEVEL: on_step (#74) */

void menu_ex010312_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010312_rear_out_level);
  return;
}


// ===== menu_ex010313_step @ fffce345 (18 bytes)

/* Menu item ex010313 MOD SOURCE: on_step (#74) */

void menu_ex010313_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex010313_mod_source);
  return;
}


// ===== menu_ex010314_step @ fffce357 (19 bytes)

/* Menu item ex010314 USB MOD GAIN: on_step (#74) */

void menu_ex010314_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010314_usb_mod_gain);
  return;
}


// ===== menu_ex010315_step @ fffce36a (19 bytes)

/* Menu item ex010315 REAR MOD GAIN: on_step (#74) */

void menu_ex010315_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010315_rear_mod_gain);
  return;
}


// ===== menu_ex010316_step @ fffce37d (18 bytes)

/* Menu item ex010316 RPTT SELECT: on_step (#74) */

void menu_ex010316_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex010316_rptt_select);
  return;
}


// ===== menu_ex010317_step @ fffce38f (92 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce3bf) */
/* Menu item ex010317 RPT SHIFT: on_step (#74) */

void menu_ex010317_step(void)

{
  bool local_9;
  byte *local_8;
  vfo_rec *local_4;
  
  local_4 = vfo_rec_ptr(VFO_TX);
  local_8 = &local_4->flags2;
  local_9 = (bool)(*local_8 >> 2 & 3);
  menu_step_u8(0,2,&local_9);
  *local_8 = *local_8 & 0xf3 | (local_9 & 3U) << 2;
  local_9 = local_4 != &g_opstate.vfo_a;
  vfo_mark_edited(local_9);
  vfo_store_back(local_9);
  return;
}


// ===== menu_fm_rptshift_get @ fffce3eb (38 bytes)

/* EX010317 accessor: (VFO byte+2 >> 2) & 3 */

byte menu_fm_rptshift_get(void)

{
  vfo_rec *pvVar1;
  
  pvVar1 = vfo_rec_ptr(VFO_TX);
  return pvVar1->flags2 >> 2 & 3;
}


// ===== menu_fm_rptshift_set @ fffce411 (37 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce42c) */
/* EX010317 accessor (set) */

void menu_fm_rptshift_set(byte param_1)

{
  vfo_rec *pvVar1;
  
  pvVar1 = vfo_rec_ptr(VFO_TX);
  pvVar1->flags2 = pvVar1->flags2 & 0xf3 | (param_1 & 3) << 2;
  return;
}


// ===== menu_ex010318_step @ fffce436 (26 bytes)

/* Menu item ex010318 RPT SHIFT(28MHz): on_step (#74) */

void menu_ex010318_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010318_rpt_shift_28mhz);
  return;
}


// ===== menu_ex010319_step @ fffce450 (69 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce460) */
/* Menu item ex010319 RPT SHIFT(50MHz): on_step (#74) */

void menu_ex010319_step(void)

{
  byte local_2;
  byte bStack_1;
  
  local_2 = g_opstate.ex010319_rpt_shift_50mhz_be[1];
  bStack_1 = g_opstate.ex010319_rpt_shift_50mhz_be[0];
  FUN_fffce495(0,400,&local_2);
  g_opstate.ex010319_rpt_shift_50mhz_be[0] = bStack_1;
  g_opstate.ex010319_rpt_shift_50mhz_be[1] = local_2;
  return;
}


// ===== FUN_fffce495 @ fffce495 (74 bytes)

void FUN_fffce495(ushort param_1,ushort param_2,ushort *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_g_ui_00025d60->menu_step_dir == 0) {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + 1;
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 - 1;
      return;
    }
  }
  return;
}


// ===== menu_ex010320_step @ fffce4df (93 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce50f) */
/* Menu item ex010320 ENC/DEC: on_step (#74) */

void menu_ex010320_step(void)

{
  bool local_9;
  byte *local_8;
  vfo_rec *local_4;
  
  local_4 = vfo_rec_ptr(VFO_TX);
  local_8 = &local_4->flags3;
  local_9 = (bool)(*local_8 >> 3 & 7);
  menu_step_u8(0,2,&local_9);
  *local_8 = *local_8 & 199 | (local_9 & 7U) << 3;
  local_9 = local_4 != &g_opstate.vfo_a;
  vfo_mark_edited(local_9);
  vfo_store_back(local_9);
  return;
}


// ===== menu_fm_encdec_get @ fffce53c (38 bytes)

/* EX010320 accessor */

byte menu_fm_encdec_get(void)

{
  vfo_rec *pvVar1;
  
  pvVar1 = vfo_rec_ptr(VFO_TX);
  return pvVar1->flags3 >> 3 & 7;
}


// ===== menu_fm_encdec_set @ fffce562 (38 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce57d) */
/* EX010320 accessor (set) */

void menu_fm_encdec_set(byte param_1)

{
  vfo_rec *pvVar1;
  
  pvVar1 = vfo_rec_ptr(VFO_TX);
  pvVar1->flags3 = pvVar1->flags3 & 199 | (param_1 & 7) << 3;
  return;
}


// ===== menu_ex010321_step @ fffce588 (54 bytes)

/* Menu item ex010321 TONE FREQ: on_step (#74) */

void menu_ex010321_step(void)

{
  vfo_rec *pvVar1;
  byte *local_4;
  
  if (g_opstate.active_vfo == 0) {
    pvVar1 = &g_opstate.vfo_a;
  }
  else {
    pvVar1 = &g_opstate.vfo_b;
  }
  local_4 = &pvVar1->tone_num;
  menu_step_u8(0,0x31,local_4);
  return;
}


// ===== menu_fm_tone_get @ fffce5be (55 bytes)

/* EX010321 accessor */

byte menu_fm_tone_get(void)

{
  vfo_rec *pvVar1;
  byte *local_8;
  
  if (g_opstate.active_vfo == 0) {
    pvVar1 = &g_opstate.vfo_a;
  }
  else {
    pvVar1 = &g_opstate.vfo_b;
  }
  local_8 = &pvVar1->tone_num;
  return *local_8;
}


// ===== menu_fm_tone_set @ fffce5f5 (52 bytes)

/* EX010321 accessor (set) */

void menu_fm_tone_set(byte param_1)

{
  vfo_rec *pvVar1;
  byte *local_8;
  
  if (g_opstate.active_vfo == 0) {
    pvVar1 = &g_opstate.vfo_a;
  }
  else {
    pvVar1 = &g_opstate.vfo_b;
  }
  local_8 = &pvVar1->tone_num;
  *local_8 = param_1;
  return;
}


// ===== menu_ex010401_step @ fffce629 (19 bytes)

/* Menu item ex010401 AF TREBLE GAIN: on_step (#74) */

void menu_ex010401_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex010401_af_treble_gain);
  return;
}


// ===== menu_ex010402_step @ fffce63c (19 bytes)

/* Menu item ex010402 AF MIDDLE TONE GAIN: on_step (#74) */

void menu_ex010402_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex010402_af_middle_tone_gain);
  return;
}


// ===== menu_ex010403_step @ fffce64f (19 bytes)

/* Menu item ex010403 AF BASS GAIN: on_step (#74) */

void menu_ex010403_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex010403_af_bass_gain);
  return;
}


// ===== menu_ex010404_step @ fffce662 (19 bytes)

/* Menu item ex010404 AGC FAST DELAY: on_step (#74) */

void menu_ex010404_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex010404_agc_fast_delay);
  return;
}


// ===== menu_ex010405_step @ fffce675 (19 bytes)

/* Menu item ex010405 AGC MID DELAY: on_step (#74) */

void menu_ex010405_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex010405_agc_mid_delay);
  return;
}


// ===== menu_ex010406_step @ fffce688 (19 bytes)

/* Menu item ex010406 AGC SLOW DELAY: on_step (#74) */

void menu_ex010406_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex010406_agc_slow_delay);
  return;
}


// ===== menu_ex010407_step @ fffce69b (14 bytes)

/* Menu item ex010407 LCUT FREQ: on_step (#74) */

void menu_ex010407_step(void)

{
  menu_step_lcut_freq(0x9a6d);
  return;
}


// ===== menu_ex010408_step @ fffce6a9 (18 bytes)

/* Menu item ex010408 LCUT SLOPE: on_step (#74) */

void menu_ex010408_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex010408_lcut_slope);
  return;
}


// ===== menu_ex010409_step @ fffce6bb (14 bytes)

/* Menu item ex010409 HCUT FREQ: on_step (#74) */

void menu_ex010409_step(void)

{
  menu_step_hcut_freq(0x9a6f);
  return;
}


// ===== menu_ex010410_step @ fffce6c9 (18 bytes)

/* Menu item ex010410 HCUT SLOPE: on_step (#74) */

void menu_ex010410_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex010410_hcut_slope);
  return;
}


// ===== menu_ex010411_step @ fffce6db (19 bytes)

/* Menu item ex010411 USB OUT LEVEL: on_step (#74) */

void menu_ex010411_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010411_usb_out_level);
  return;
}


// ===== menu_ex010412_step @ fffce6ee (19 bytes)

/* Menu item ex010412 REAR OUT LEVEL: on_step (#74) */

void menu_ex010412_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010412_rear_out_level);
  return;
}


// ===== menu_ex010413_step @ fffce701 (18 bytes)

/* Menu item ex010413 TX BPF SEL: on_step (#74) */

void menu_ex010413_step(void)

{
  menu_step_u8(0,4,&g_opstate.ex010413_tx_bpf_sel);
  return;
}


// ===== menu_ex010414_step @ fffce713 (18 bytes)

/* Menu item ex010414 MOD SOURCE: on_step (#74) */

void menu_ex010414_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex010414_mod_source);
  return;
}


// ===== menu_ex010415_step @ fffce725 (19 bytes)

/* Menu item ex010415 USB MOD GAIN: on_step (#74) */

void menu_ex010415_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010415_usb_mod_gain);
  return;
}


// ===== menu_ex010416_step @ fffce738 (19 bytes)

/* Menu item ex010416 REAR MOD GAIN: on_step (#74) */

void menu_ex010416_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010416_rear_mod_gain);
  return;
}


// ===== menu_ex010417_step @ fffce74b (18 bytes)

/* Menu item ex010417 RPTT SELECT: on_step (#74) */

void menu_ex010417_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex010417_rptt_select);
  return;
}


// ===== menu_ex010418_step @ fffce75d (19 bytes)

/* Menu item ex010418 NAR WIDTH: on_step (#74) */

void menu_ex010418_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex010418_nar_width);
  return;
}


// ===== menu_ex010419_step @ fffce770 (18 bytes)

/* Menu item ex010419 PSK TONE: on_step (#74) */

void menu_ex010419_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex010419_psk_tone);
  return;
}


// ===== menu_ex010420_step @ fffce782 (69 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce792) */
/* Menu item ex010420 DATA SHIFT (SSB): on_step (#74) */

void menu_ex010420_step(void)

{
  byte local_2;
  byte bStack_1;
  
  local_2 = g_opstate.ex010420_data_shift_ssb_be[1];
  bStack_1 = g_opstate.ex010420_data_shift_ssb_be[0];
  FUN_fffce495(0,300,&local_2);
  g_opstate.ex010420_data_shift_ssb_be[0] = bStack_1;
  g_opstate.ex010420_data_shift_ssb_be[1] = local_2;
  return;
}


// ===== menu_ex010501_step @ fffce7c7 (19 bytes)

/* Menu item ex010501 AF TREBLE GAIN: on_step (#74) */

void menu_ex010501_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex010501_af_treble_gain);
  return;
}


// ===== menu_ex010502_step @ fffce7da (19 bytes)

/* Menu item ex010502 AF MIDDLE TONE GAIN: on_step (#74) */

void menu_ex010502_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex010502_af_middle_tone_gain);
  return;
}


// ===== menu_ex010503_step @ fffce7ed (19 bytes)

/* Menu item ex010503 AF BASS GAIN: on_step (#74) */

void menu_ex010503_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex010503_af_bass_gain);
  return;
}

