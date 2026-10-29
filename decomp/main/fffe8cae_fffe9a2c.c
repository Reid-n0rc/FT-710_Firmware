// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== ai_ex020120 @ fffe8cae (76 bytes)

/* AI change detector for menu item EX020120 (table 0xFFF8E1A0[113]) */

void ai_ex020120(void)

{
  if (DAT_0001b309 == g_opstate.ex020120_cw_indicator) {
    return;
  }
  DAT_0001b309 = g_opstate.ex020120_cw_indicator;
  DAT_0001b23d = nib2hex(g_opstate.ex020120_cw_indicator);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020201 @ fffe8cfa (76 bytes)

/* AI change detector for menu item EX020201 (table 0xFFF8E1A0[114]) */

void ai_ex020201(void)

{
  if (DAT_0001b30a == g_opstate.ex020201_keyer_type) {
    return;
  }
  DAT_0001b30a = g_opstate.ex020201_keyer_type;
  DAT_0001b23d = nib2hex(g_opstate.ex020201_keyer_type);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020202 @ fffe8d46 (76 bytes)

/* AI change detector for menu item EX020202 (table 0xFFF8E1A0[115]) */

void ai_ex020202(void)

{
  if (DAT_0001b30b == g_opstate.ex020202_keyer_dot_dash) {
    return;
  }
  DAT_0001b30b = g_opstate.ex020202_keyer_dot_dash;
  DAT_0001b23d = nib2hex(g_opstate.ex020202_keyer_dot_dash);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020203 @ fffe8d92 (61 bytes)

/* AI change detector for menu item EX020203 (table 0xFFF8E1A0[116]) */

void ai_ex020203(void)

{
  if (DAT_0001b30c == g_opstate.ex020203_cw_weight) {
    return;
  }
  DAT_0001b30c = g_opstate.ex020203_cw_weight;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex020203_cw_weight,0,0);
  return;
}


// ===== ai_ex020204 @ fffe8dcf (76 bytes)

/* AI change detector for menu item EX020204 (table 0xFFF8E1A0[117]) */

void ai_ex020204(void)

{
  if (DAT_0001b30d == g_opstate.ex020204_number_style) {
    return;
  }
  DAT_0001b30d = g_opstate.ex020204_number_style;
  DAT_0001b23d = nib2hex(g_opstate.ex020204_number_style);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020205 @ fffe8e1b (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe8e2b) */
/* AI change detector for menu item EX020205 (table 0xFFF8E1A0[118]) */

void ai_ex020205(void)

{
  short sVar1;
  
  sVar1 = CONCAT11(g_opstate.ex020205_contest_number_be[0],g_opstate.ex020205_contest_number_be[1]);
  if (DAT_0001ff18 == sVar1) {
    return;
  }
  DAT_0001ff18 = sVar1;
  DAT_0001ff12 = ai_ex_fmt_u16_4(sVar1);
  return;
}


// ===== ai_ex020206 @ fffe8e67 (76 bytes)

/* AI change detector for menu item EX020206 (table 0xFFF8E1A0[119]) */

void ai_ex020206(void)

{
  if (DAT_0001b30e == g_opstate.ex020206_cw_memory_1) {
    return;
  }
  DAT_0001b30e = g_opstate.ex020206_cw_memory_1;
  DAT_0001b23d = nib2hex(g_opstate.ex020206_cw_memory_1);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020207 @ fffe8eb3 (76 bytes)

/* AI change detector for menu item EX020207 (table 0xFFF8E1A0[120]) */

void ai_ex020207(void)

{
  if (DAT_0001b30f == g_opstate.ex020207_cw_memory_2) {
    return;
  }
  DAT_0001b30f = g_opstate.ex020207_cw_memory_2;
  DAT_0001b23d = nib2hex(g_opstate.ex020207_cw_memory_2);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020208 @ fffe8eff (76 bytes)

/* AI change detector for menu item EX020208 (table 0xFFF8E1A0[121]) */

void ai_ex020208(void)

{
  if (DAT_0001b310 == g_opstate.ex020208_cw_memory_3) {
    return;
  }
  DAT_0001b310 = g_opstate.ex020208_cw_memory_3;
  DAT_0001b23d = nib2hex(g_opstate.ex020208_cw_memory_3);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020209 @ fffe8f4b (76 bytes)

/* AI change detector for menu item EX020209 (table 0xFFF8E1A0[122]) */

void ai_ex020209(void)

{
  if (DAT_0001b311 == g_opstate.ex020209_cw_memory_4) {
    return;
  }
  DAT_0001b311 = g_opstate.ex020209_cw_memory_4;
  DAT_0001b23d = nib2hex(g_opstate.ex020209_cw_memory_4);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020210 @ fffe8f97 (76 bytes)

/* AI change detector for menu item EX020210 (table 0xFFF8E1A0[123]) */

void ai_ex020210(void)

{
  if (DAT_0001b312 == g_opstate.ex020210_cw_memory_5) {
    return;
  }
  DAT_0001b312 = g_opstate.ex020210_cw_memory_5;
  DAT_0001b23d = nib2hex(g_opstate.ex020210_cw_memory_5);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex020211 @ fffe8fe3 (61 bytes)

/* AI change detector for menu item EX020211 (table 0xFFF8E1A0[124]) */

void ai_ex020211(void)

{
  if (DAT_0001b313 == g_opstate.ex020211_repeat_interval) {
    return;
  }
  DAT_0001b313 = g_opstate.ex020211_repeat_interval;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex020211_repeat_interval,0,0);
  return;
}


// ===== ai_ex030101 @ fffe9020 (61 bytes)

/* AI change detector for menu item EX030101 (table 0xFFF8E1A0[125]) */

void ai_ex030101(void)

{
  if (DAT_0001b314 == g_opstate.ex030101_beep_level) {
    return;
  }
  DAT_0001b314 = g_opstate.ex030101_beep_level;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030101_beep_level,1,0);
  return;
}


// ===== ai_ex030102 @ fffe905d (76 bytes)

/* AI change detector for menu item EX030102 (table 0xFFF8E1A0[126]) */

void ai_ex030102(void)

{
  if (DAT_0001b315 == g_opstate.ex030102_rf_sql_vr) {
    return;
  }
  DAT_0001b315 = g_opstate.ex030102_rf_sql_vr;
  DAT_0001b23d = nib2hex(g_opstate.ex030102_rf_sql_vr);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030103 @ fffe90a9 (76 bytes)

/* AI change detector for menu item EX030103 (table 0xFFF8E1A0[127]) */

void ai_ex030103(void)

{
  if (DAT_0001b316 == g_opstate.ex030103_tun_lin_port_select) {
    return;
  }
  DAT_0001b316 = g_opstate.ex030103_tun_lin_port_select;
  DAT_0001b23d = nib2hex(g_opstate.ex030103_tun_lin_port_select);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030104 @ fffe90f5 (76 bytes)

/* AI change detector for menu item EX030104 (table 0xFFF8E1A0[128]) */

void ai_ex030104(void)

{
  if (DAT_0001b317 == g_opstate.ex030104_tuner_type_select) {
    return;
  }
  DAT_0001b317 = g_opstate.ex030104_tuner_type_select;
  DAT_0001b23d = nib2hex(g_opstate.ex030104_tuner_type_select);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030105 @ fffe9141 (76 bytes)

/* AI change detector for menu item EX030105 (table 0xFFF8E1A0[129]) */

void ai_ex030105(void)

{
  if (DAT_0001b318 == g_opstate.ex030105_cat_1_rate) {
    return;
  }
  DAT_0001b318 = g_opstate.ex030105_cat_1_rate;
  DAT_0001b23d = nib2hex(g_opstate.ex030105_cat_1_rate);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030106 @ fffe918d (76 bytes)

/* AI change detector for menu item EX030106 (table 0xFFF8E1A0[130]) */

void ai_ex030106(void)

{
  if (DAT_0001b319 == g_opstate.ex030106_cat_1_time_out_timer) {
    return;
  }
  DAT_0001b319 = g_opstate.ex030106_cat_1_time_out_timer;
  DAT_0001b23d = nib2hex(g_opstate.ex030106_cat_1_time_out_timer);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030107 @ fffe91d9 (76 bytes)

/* AI change detector for menu item EX030107 (table 0xFFF8E1A0[131]) */

void ai_ex030107(void)

{
  if (DAT_0001b31a == g_opstate.ex030107_cat_1_cat_3_stop_bit) {
    return;
  }
  DAT_0001b31a = g_opstate.ex030107_cat_1_cat_3_stop_bit;
  DAT_0001b23d = nib2hex(g_opstate.ex030107_cat_1_cat_3_stop_bit);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030108 @ fffe9225 (76 bytes)

/* AI change detector for menu item EX030108 (table 0xFFF8E1A0[132]) */

void ai_ex030108(void)

{
  if (DAT_0001b31b == g_opstate.ex030108_cat_2_rate) {
    return;
  }
  DAT_0001b31b = g_opstate.ex030108_cat_2_rate;
  DAT_0001b23d = nib2hex(g_opstate.ex030108_cat_2_rate);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030109 @ fffe9271 (76 bytes)

/* AI change detector for menu item EX030109 (table 0xFFF8E1A0[133]) */

void ai_ex030109(void)

{
  if (DAT_0001b31c == g_opstate.ex030109_cat_2_time_out_timer) {
    return;
  }
  DAT_0001b31c = g_opstate.ex030109_cat_2_time_out_timer;
  DAT_0001b23d = nib2hex(g_opstate.ex030109_cat_2_time_out_timer);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030110 @ fffe92bd (76 bytes)

/* AI change detector for menu item EX030110 (table 0xFFF8E1A0[134]) */

void ai_ex030110(void)

{
  if (DAT_0001b31d == g_opstate.ex030110_cat_3_rate) {
    return;
  }
  DAT_0001b31d = g_opstate.ex030110_cat_3_rate;
  DAT_0001b23d = nib2hex(g_opstate.ex030110_cat_3_rate);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030111 @ fffe9309 (76 bytes)

/* AI change detector for menu item EX030111 (table 0xFFF8E1A0[135]) */

void ai_ex030111(void)

{
  if (DAT_0001b31e == g_opstate.ex030111_cat_3_time_out_timer) {
    return;
  }
  DAT_0001b31e = g_opstate.ex030111_cat_3_time_out_timer;
  DAT_0001b23d = nib2hex(g_opstate.ex030111_cat_3_time_out_timer);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030112 @ fffe9355 (76 bytes)

/* AI change detector for menu item EX030112 (table 0xFFF8E1A0[136]) */

void ai_ex030112(void)

{
  if (DAT_0001b31f == g_opstate.ex030112_qmb_ch) {
    return;
  }
  DAT_0001b31f = g_opstate.ex030112_qmb_ch;
  DAT_0001b23d = nib2hex(g_opstate.ex030112_qmb_ch);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030113 @ fffe93a1 (76 bytes)

/* AI change detector for menu item EX030113 (table 0xFFF8E1A0[137]) */

void ai_ex030113(void)

{
  if (DAT_0001b320 == g_opstate.ex030113_band_stack) {
    return;
  }
  DAT_0001b320 = g_opstate.ex030113_band_stack;
  DAT_0001b23d = nib2hex(g_opstate.ex030113_band_stack);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030114 @ fffe93ed (76 bytes)

/* AI change detector for menu item EX030114 (table 0xFFF8E1A0[138]) */

void ai_ex030114(void)

{
  if (DAT_0001b321 == g_opstate.ex030114_mem_group) {
    return;
  }
  DAT_0001b321 = g_opstate.ex030114_mem_group;
  DAT_0001b23d = nib2hex(g_opstate.ex030114_mem_group);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030115 @ fffe9439 (61 bytes)

/* AI change detector for menu item EX030115 (table 0xFFF8E1A0[139]) */

void ai_ex030115(void)

{
  if (DAT_0001b322 == g_opstate.ex030115_tx_time_out_timer) {
    return;
  }
  DAT_0001b322 = g_opstate.ex030115_tx_time_out_timer;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030115_tx_time_out_timer,0,0);
  return;
}


// ===== ai_ex030116 @ fffe9476 (76 bytes)

/* AI change detector for menu item EX030116 (table 0xFFF8E1A0[140]) */

void ai_ex030116(void)

{
  if (DAT_0001b323 == g_opstate.ex030116_mic_scan) {
    return;
  }
  DAT_0001b323 = g_opstate.ex030116_mic_scan;
  DAT_0001b23d = nib2hex(g_opstate.ex030116_mic_scan);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030117 @ fffe94c2 (76 bytes)

/* AI change detector for menu item EX030117 (table 0xFFF8E1A0[141]) */

void ai_ex030117(void)

{
  if (DAT_0001b324 == g_opstate.ex030117_mic_scan_resume) {
    return;
  }
  DAT_0001b324 = g_opstate.ex030117_mic_scan_resume;
  DAT_0001b23d = nib2hex(g_opstate.ex030117_mic_scan_resume);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030118 @ fffe950e (61 bytes)

/* AI change detector for menu item EX030118 (table 0xFFF8E1A0[142]) */

void ai_ex030118(void)

{
  if (DAT_0001b325 == g_opstate.ex030118_ref_freq_fine_adj) {
    return;
  }
  DAT_0001b325 = g_opstate.ex030118_ref_freq_fine_adj;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030118_ref_freq_fine_adj,0,1);
  return;
}


// ===== ai_ex030119 @ fffe954b (61 bytes)

/* AI change detector for menu item EX030119 (table 0xFFF8E1A0[143]) */

void ai_ex030119(void)

{
  if (DAT_0001b326 == g_opstate.ex030119_keyboard_language) {
    return;
  }
  DAT_0001b326 = g_opstate.ex030119_keyboard_language;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030119_keyboard_language,0,0);
  return;
}


// ===== ai_ex030120 @ fffe9588 (61 bytes)

/* AI change detector for menu item EX030120 (table 0xFFF8E1A0[144]) */

void ai_ex030120(void)

{
  if (DAT_0001b327 == g_opstate.ex030120_mic_p1) {
    return;
  }
  DAT_0001b327 = g_opstate.ex030120_mic_p1;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030120_mic_p1,0,0);
  return;
}


// ===== ai_ex030121 @ fffe95c5 (61 bytes)

/* AI change detector for menu item EX030121 (table 0xFFF8E1A0[145]) */

void ai_ex030121(void)

{
  if (DAT_0001b328 == g_opstate.ex030121_mic_p2) {
    return;
  }
  DAT_0001b328 = g_opstate.ex030121_mic_p2;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030121_mic_p2,0,0);
  return;
}


// ===== ai_ex030122 @ fffe9602 (61 bytes)

/* AI change detector for menu item EX030122 (table 0xFFF8E1A0[146]) */

void ai_ex030122(void)

{
  if (DAT_0001b329 == g_opstate.ex030122_mic_p3) {
    return;
  }
  DAT_0001b329 = g_opstate.ex030122_mic_p3;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030122_mic_p3,0,0);
  return;
}


// ===== ai_ex030123 @ fffe963f (61 bytes)

/* AI change detector for menu item EX030123 (table 0xFFF8E1A0[147]) */

void ai_ex030123(void)

{
  if (DAT_0001b32a == g_opstate.ex030123_mic_p4) {
    return;
  }
  DAT_0001b32a = g_opstate.ex030123_mic_p4;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030123_mic_p4,0,0);
  return;
}


// ===== ai_ex030124 @ fffe967c (61 bytes)

/* AI change detector for menu item EX030124 (table 0xFFF8E1A0[148]) */

void ai_ex030124(void)

{
  if (DAT_0001b32b == g_opstate.ex030124_mic_up) {
    return;
  }
  DAT_0001b32b = g_opstate.ex030124_mic_up;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030124_mic_up,0,0);
  return;
}


// ===== ai_ex030125 @ fffe96b9 (61 bytes)

/* AI change detector for menu item EX030125 (table 0xFFF8E1A0[149]) */

void ai_ex030125(void)

{
  if (DAT_0001b32c == g_opstate.ex030125_mic_down) {
    return;
  }
  DAT_0001b32c = g_opstate.ex030125_mic_down;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030125_mic_down,0,0);
  return;
}


// ===== ai_ex030126 @ fffe96f6 (76 bytes)

/* AI change detector for menu item EX030126 (table 0xFFF8E1A0[150]) */

void ai_ex030126(void)

{
  if (DAT_0001b32d == g_opstate.ex030126_scu_lan10) {
    return;
  }
  DAT_0001b32d = g_opstate.ex030126_scu_lan10;
  DAT_0001b23d = nib2hex(g_opstate.ex030126_scu_lan10);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030201 @ fffe9742 (76 bytes)

/* AI change detector for menu item EX030201 (table 0xFFF8E1A0[151]) */

void ai_ex030201(void)

{
  if (DAT_0001b32e == g_opstate.ex030201_if_notch_width) {
    return;
  }
  DAT_0001b32e = g_opstate.ex030201_if_notch_width;
  DAT_0001b23d = nib2hex(g_opstate.ex030201_if_notch_width);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030202 @ fffe978e (76 bytes)

/* AI change detector for menu item EX030202 (table 0xFFF8E1A0[152]) */

void ai_ex030202(void)

{
  if (DAT_0001b32f == g_opstate.ex030202_nb_rejection) {
    return;
  }
  DAT_0001b32f = g_opstate.ex030202_nb_rejection;
  DAT_0001b23d = nib2hex(g_opstate.ex030202_nb_rejection);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030203 @ fffe97da (76 bytes)

/* AI change detector for menu item EX030203 (table 0xFFF8E1A0[153]) */

void ai_ex030203(void)

{
  if (DAT_0001b330 == g_opstate.ex030203_nb_width) {
    return;
  }
  DAT_0001b330 = g_opstate.ex030203_nb_width;
  DAT_0001b23d = nib2hex(g_opstate.ex030203_nb_width);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030204 @ fffe9826 (76 bytes)

/* AI change detector for menu item EX030204 (table 0xFFF8E1A0[154]) */

void ai_ex030204(void)

{
  if (DAT_0001b331 == g_opstate.ex030204_apf_width) {
    return;
  }
  DAT_0001b331 = g_opstate.ex030204_apf_width;
  DAT_0001b23d = nib2hex(g_opstate.ex030204_apf_width);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030205 @ fffe9872 (61 bytes)

/* AI change detector for menu item EX030205 (table 0xFFF8E1A0[155]) */

void ai_ex030205(void)

{
  if (DAT_0001b332 == g_opstate.ex030205_contour_level) {
    return;
  }
  DAT_0001b332 = g_opstate.ex030205_contour_level;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030205_contour_level,0,1);
  return;
}


// ===== ai_ex030206 @ fffe98af (61 bytes)

/* AI change detector for menu item EX030206 (table 0xFFF8E1A0[156]) */

void ai_ex030206(void)

{
  if (DAT_0001b333 == g_opstate.ex030206_contour_width) {
    return;
  }
  DAT_0001b333 = g_opstate.ex030206_contour_width;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030206_contour_width,0,0);
  return;
}


// ===== ai_ex030301 @ fffe98ec (76 bytes)

/* AI change detector for menu item EX030301 (table 0xFFF8E1A0[157]) */

void ai_ex030301(void)

{
  if (DAT_0001b334 == g_opstate.ex030301_amc_release_time) {
    return;
  }
  DAT_0001b334 = g_opstate.ex030301_amc_release_time;
  DAT_0001b23d = nib2hex(g_opstate.ex030301_amc_release_time);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex030302 @ fffe9938 (61 bytes)

/* AI change detector for menu item EX030302 (table 0xFFF8E1A0[158]) */

void ai_ex030302(void)

{
  if (DAT_0001b335 == g_opstate.ex030302_prmtrc_eq1_freq) {
    return;
  }
  DAT_0001b335 = g_opstate.ex030302_prmtrc_eq1_freq;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030302_prmtrc_eq1_freq,0,0);
  return;
}


// ===== ai_ex030303 @ fffe9975 (61 bytes)

/* AI change detector for menu item EX030303 (table 0xFFF8E1A0[159]) */

void ai_ex030303(void)

{
  if (DAT_0001b336 == g_opstate.ex030303_prmtrc_eq1_level) {
    return;
  }
  DAT_0001b336 = g_opstate.ex030303_prmtrc_eq1_level;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030303_prmtrc_eq1_level,0,1);
  return;
}


// ===== ai_ex030304 @ fffe99b2 (61 bytes)

/* AI change detector for menu item EX030304 (table 0xFFF8E1A0[160]) */

void ai_ex030304(void)

{
  if (DAT_0001b337 == g_opstate.ex030304_prmtrc_eq1_bwth) {
    return;
  }
  DAT_0001b337 = g_opstate.ex030304_prmtrc_eq1_bwth;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030304_prmtrc_eq1_bwth,0,0);
  return;
}


// ===== ai_ex030305 @ fffe99ef (61 bytes)

/* AI change detector for menu item EX030305 (table 0xFFF8E1A0[161]) */

void ai_ex030305(void)

{
  if (DAT_0001b338 == g_opstate.ex030305_prmtrc_eq2_freq) {
    return;
  }
  DAT_0001b338 = g_opstate.ex030305_prmtrc_eq2_freq;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030305_prmtrc_eq2_freq,0,0);
  return;
}


// ===== ai_ex030306 @ fffe9a2c (61 bytes)

/* AI change detector for menu item EX030306 (table 0xFFF8E1A0[162]) */

void ai_ex030306(void)

{
  if (DAT_0001b339 == g_opstate.ex030306_prmtrc_eq2_level) {
    return;
  }
  DAT_0001b339 = g_opstate.ex030306_prmtrc_eq2_level;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex030306_prmtrc_eq2_level,0,1);
  return;
}

