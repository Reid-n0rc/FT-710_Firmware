// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex010504_step @ fffce800 (19 bytes)

/* Menu item ex010504 AGC FAST DELAY: on_step (#74) */

void menu_ex010504_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex010504_agc_fast_delay);
  return;
}


// ===== menu_ex010505_step @ fffce813 (19 bytes)

/* Menu item ex010505 AGC MID DELAY: on_step (#74) */

void menu_ex010505_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex010505_agc_mid_delay);
  return;
}


// ===== menu_ex010506_step @ fffce826 (19 bytes)

/* Menu item ex010506 AGC SLOW DELAY: on_step (#74) */

void menu_ex010506_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex010506_agc_slow_delay);
  return;
}


// ===== menu_ex010507_step @ fffce839 (14 bytes)

/* Menu item ex010507 LCUT FREQ: on_step (#74) */

void menu_ex010507_step(void)

{
  menu_step_lcut_freq(0x9a84);
  return;
}


// ===== menu_ex010508_step @ fffce847 (18 bytes)

/* Menu item ex010508 LCUT SLOPE: on_step (#74) */

void menu_ex010508_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex010508_lcut_slope);
  return;
}


// ===== menu_ex010509_step @ fffce859 (14 bytes)

/* Menu item ex010509 HCUT FREQ: on_step (#74) */

void menu_ex010509_step(void)

{
  menu_step_hcut_freq(0x9a86);
  return;
}


// ===== menu_ex010510_step @ fffce867 (18 bytes)

/* Menu item ex010510 HCUT SLOPE: on_step (#74) */

void menu_ex010510_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex010510_hcut_slope);
  return;
}


// ===== menu_ex010511_step @ fffce879 (19 bytes)

/* Menu item ex010511 USB OUT LEVEL: on_step (#74) */

void menu_ex010511_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010511_usb_out_level);
  return;
}


// ===== menu_ex010512_step @ fffce88c (19 bytes)

/* Menu item ex010512 REAR OUT LEVEL: on_step (#74) */

void menu_ex010512_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex010512_rear_out_level);
  return;
}


// ===== menu_ex010513_step @ fffce89f (18 bytes)

/* Menu item ex010513 RPTT SELECT: on_step (#74) */

void menu_ex010513_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex010513_rptt_select);
  return;
}


// ===== menu_ex010514_step @ fffce8b1 (19 bytes)

/* Menu item ex010514 NAR WIDTH: on_step (#74) */

void menu_ex010514_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex010514_nar_width);
  return;
}


// ===== menu_ex010515_step @ fffce8c4 (18 bytes)

/* Menu item ex010515 MARK FREQUENCY: on_step (#74) */

void menu_ex010515_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex010515_mark_frequency);
  return;
}


// ===== menu_ex010516_step @ fffce8d6 (18 bytes)

/* Menu item ex010516 SHIFT FREQUENCY: on_step (#74) */

void menu_ex010516_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex010516_shift_frequency);
  return;
}


// ===== menu_ex010517_step @ fffce8e8 (18 bytes)

/* Menu item ex010517 POLARITY TX: on_step (#74) */

void menu_ex010517_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex010517_polarity_tx);
  return;
}


// ===== menu_ex020101_step @ fffce8fa (19 bytes)

/* Menu item ex020101 AF TREBLE GAIN: on_step (#74) */

void menu_ex020101_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex020101_af_treble_gain);
  return;
}


// ===== menu_ex020102_step @ fffce90d (19 bytes)

/* Menu item ex020102 AF MIDDLE TONE GAIN: on_step (#74) */

void menu_ex020102_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex020102_af_middle_tone_gain);
  return;
}


// ===== menu_ex020103_step @ fffce920 (19 bytes)

/* Menu item ex020103 AF BASS GAIN: on_step (#74) */

void menu_ex020103_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex020103_af_bass_gain);
  return;
}


// ===== menu_ex020104_step @ fffce933 (19 bytes)

/* Menu item ex020104 AGC FAST DELAY: on_step (#74) */

void menu_ex020104_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex020104_agc_fast_delay);
  return;
}


// ===== menu_ex020105_step @ fffce946 (19 bytes)

/* Menu item ex020105 AGC MID DELAY: on_step (#74) */

void menu_ex020105_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex020105_agc_mid_delay);
  return;
}


// ===== menu_ex020106_step @ fffce959 (19 bytes)

/* Menu item ex020106 AGC SLOW DELAY: on_step (#74) */

void menu_ex020106_step(void)

{
  menu_step_u8(0,199,&g_opstate.ex020106_agc_slow_delay);
  return;
}


// ===== menu_ex020107_step @ fffce96c (14 bytes)

/* Menu item ex020107 LCUT FREQ: on_step (#74) */

void menu_ex020107_step(void)

{
  menu_step_lcut_freq(0x9a97);
  return;
}


// ===== menu_ex020108_step @ fffce97a (18 bytes)

/* Menu item ex020108 LCUT SLOPE: on_step (#74) */

void menu_ex020108_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020108_lcut_slope);
  return;
}


// ===== menu_ex020109_step @ fffce98c (14 bytes)

/* Menu item ex020109 HCUT FREQ: on_step (#74) */

void menu_ex020109_step(void)

{
  menu_step_hcut_freq(0x9a99);
  return;
}


// ===== menu_ex020110_step @ fffce99a (18 bytes)

/* Menu item ex020110 HCUT SLOPE: on_step (#74) */

void menu_ex020110_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020110_hcut_slope);
  return;
}


// ===== menu_ex020111_step @ fffce9ac (19 bytes)

/* Menu item ex020111 USB OUT LEVEL: on_step (#74) */

void menu_ex020111_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex020111_usb_out_level);
  return;
}


// ===== menu_ex020112_step @ fffce9bf (19 bytes)

/* Menu item ex020112 REAR OUT LEVEL: on_step (#74) */

void menu_ex020112_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex020112_rear_out_level);
  return;
}


// ===== menu_ex020113_step @ fffce9d2 (18 bytes)

/* Menu item ex020113 RPTT SELECT: on_step (#74) */

void menu_ex020113_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex020113_rptt_select);
  return;
}


// ===== menu_ex020114_step @ fffce9e4 (19 bytes)

/* Menu item ex020114 NAR WIDTH: on_step (#74) */

void menu_ex020114_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex020114_nar_width);
  return;
}


// ===== menu_ex020115_step @ fffce9f7 (18 bytes)

/* Menu item ex020115 PC KEYING: on_step (#74) */

void menu_ex020115_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex020115_pc_keying);
  return;
}


// ===== menu_ex020116_step @ fffcea09 (18 bytes)

/* Menu item ex020116 CW BK-IN TYPE: on_step (#74) */

void menu_ex020116_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020116_cw_bk_in_type);
  return;
}


// ===== menu_ex020117_step @ fffcea1b (18 bytes)

/* Menu item ex020117 CW WAVE SHAPE: on_step (#74) */

void menu_ex020117_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex020117_cw_wave_shape);
  return;
}


// ===== menu_ex020118_step @ fffcea2d (18 bytes)

/* Menu item ex020118 CW FREQ DISPLAY: on_step (#74) */

void menu_ex020118_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020118_cw_freq_display);
  return;
}


// ===== menu_ex020119_step @ fffcea3f (18 bytes)

/* Menu item ex020119 QSK DELAY TIME: on_step (#74) */

void menu_ex020119_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex020119_qsk_delay_time);
  return;
}


// ===== menu_ex020120_step @ fffcea51 (18 bytes)

/* Menu item ex020120 CW INDICATOR: on_step (#74) */

void menu_ex020120_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020120_cw_indicator);
  return;
}


// ===== menu_ex020201_step @ fffcea63 (22 bytes)

/* Menu item ex020201 KEYER TYPE: on_step (#74) */

void menu_ex020201_step(void)

{
  menu_step_u8(0,5,&g_opstate.ex020201_keyer_type);
  keyer_init();
  return;
}


// ===== menu_ex020202_step @ fffcea79 (18 bytes)

/* Menu item ex020202 KEYER DOT/DASH: on_step (#74) */

void menu_ex020202_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020202_keyer_dot_dash);
  return;
}


// ===== menu_ex020203_step @ fffcea8b (19 bytes)

/* Menu item ex020203 CW WEIGHT: on_step (#74) */

void menu_ex020203_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex020203_cw_weight);
  return;
}


// ===== menu_ex020204_step @ fffcea9e (18 bytes)

/* Menu item ex020204 NUMBER STYLE: on_step (#74) */

void menu_ex020204_step(void)

{
  menu_step_u8(0,6,&g_opstate.ex020204_number_style);
  return;
}


// ===== menu_ex020205_step @ fffceab0 (28 bytes)

/* Menu item ex020205 CONTEST NUMBER: on_step (#74) */

void menu_ex020205_step(void)

{
  undefined2 uStack_2;
  
  uStack_2 = contest_number_get();
  FUN_fffce495(1,&DAT_0000270f,&uStack_2);
  FUN_fffba336(uStack_2);
  return;
}


// ===== menu_ex020206_step @ fffceacc (18 bytes)

/* Menu item ex020206 CW MEMORY 1: on_step (#74) */

void menu_ex020206_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020206_cw_memory_1);
  return;
}


// ===== menu_ex020207_step @ fffceade (18 bytes)

/* Menu item ex020207 CW MEMORY 2: on_step (#74) */

void menu_ex020207_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020207_cw_memory_2);
  return;
}


// ===== menu_ex020208_step @ fffceaf0 (18 bytes)

/* Menu item ex020208 CW MEMORY 3: on_step (#74) */

void menu_ex020208_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020208_cw_memory_3);
  return;
}


// ===== menu_ex020209_step @ fffceb02 (18 bytes)

/* Menu item ex020209 CW MEMORY 4: on_step (#74) */

void menu_ex020209_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020209_cw_memory_4);
  return;
}


// ===== menu_ex020210_step @ fffceb14 (18 bytes)

/* Menu item ex020210 CW MEMORY 5: on_step (#74) */

void menu_ex020210_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex020210_cw_memory_5);
  return;
}


// ===== menu_ex020211_step @ fffceb26 (19 bytes)

/* Menu item ex020211 REPEAT INTERVAL: on_step (#74) */

void menu_ex020211_step(void)

{
  menu_step_u8(1,0x3c,&g_opstate.ex020211_repeat_interval);
  return;
}


// ===== menu_ex030101_step @ fffceb39 (19 bytes)

/* Menu item ex030101 BEEP LEVEL: on_step (#74) */

void menu_ex030101_step(void)

{
  menu_step_u8(0,100,&g_opstate.ex030101_beep_level);
  return;
}


// ===== menu_ex030102_step @ fffceb4c (18 bytes)

/* Menu item ex030102 RF/SQL VR: on_step (#74) */

void menu_ex030102_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex030102_rf_sql_vr);
  return;
}


// ===== menu_ex030103_step @ fffceb5e (22 bytes)

/* Menu item ex030103 TUN/LIN PORT SELECT: on_step (#74) */

void menu_ex030103_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex030103_tun_lin_port_select);
  sci2_configure();
  return;
}


// ===== menu_ex030104_step @ fffceb74 (68 bytes)

/* Menu item ex030104 TUNER TYPE SELECT: on_step (#74) */

void menu_ex030104_step(void)

{
  byte bVar1;
  
  bVar1 = g_opstate.ex030104_tuner_type_select;
  menu_step_u8(0,3,&g_opstate.ex030104_tuner_type_select);
  if (bVar1 == g_opstate.ex030104_tuner_type_select) {
    return;
  }
  g_ui.tuner_indicator = 0;
  vfo_tuner_bit_set(0);
  tuner_rearm();
  return;
}


// ===== menu_ex030105_step @ fffcebb8 (22 bytes)

/* Menu item ex030105 CAT-1 RATE: on_step (#74) */

void menu_ex030105_step(void)

{
  menu_step_u8(0,4,&g_opstate.ex030105_cat_1_rate);
  sci3_set_baud();
  return;
}

