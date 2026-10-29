// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex030106_step @ fffcebce (18 bytes)

/* Menu item ex030106 CAT-1 TIME OUT TIMER: on_step (#74) */

void menu_ex030106_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex030106_cat_1_time_out_timer);
  return;
}


// ===== menu_ex030107_step @ fffcebe0 (26 bytes)

/* Menu item ex030107 CAT-1 CAT-3 STOP BIT: on_step (#74) */

void menu_ex030107_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030107_cat_1_cat_3_stop_bit);
  sci2_configure();
  sci3_set_baud();
  return;
}


// ===== menu_ex030108_step @ fffcebfa (22 bytes)

/* Menu item ex030108 CAT-2 RATE: on_step (#74) */

void menu_ex030108_step(void)

{
  menu_step_u8(0,4,&g_opstate.ex030108_cat_2_rate);
  sci0_set_baud();
  return;
}


// ===== menu_ex030109_step @ fffcec10 (18 bytes)

/* Menu item ex030109 CAT-2 TIME OUT TIMER: on_step (#74) */

void menu_ex030109_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex030109_cat_2_time_out_timer);
  return;
}


// ===== menu_ex030110_step @ fffcec22 (22 bytes)

/* Menu item ex030110 CAT-3 RATE: on_step (#74) */

void menu_ex030110_step(void)

{
  menu_step_u8(0,4,&g_opstate.ex030110_cat_3_rate);
  sci2_configure();
  return;
}


// ===== menu_ex030111_step @ fffcec38 (18 bytes)

/* Menu item ex030111 CAT-3 TIME OUT TIMER: on_step (#74) */

void menu_ex030111_step(void)

{
  menu_step_u8(0,3,&g_opstate.ex030111_cat_3_time_out_timer);
  return;
}


// ===== menu_ex030112_step @ fffcec4a (22 bytes)

/* Menu item ex030112 QMB CH: on_step (#74) */

void menu_ex030112_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030112_qmb_ch);
  FUN_fffc4a8e();
  return;
}


// ===== menu_ex030113_step @ fffcec60 (18 bytes)

/* Menu item ex030113 BAND STACK: on_step (#74) */

void menu_ex030113_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030113_band_stack);
  return;
}


// ===== menu_ex030114_step @ fffcec72 (18 bytes)

/* Menu item ex030114 MEM GROUP: on_step (#74) */

void menu_ex030114_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030114_mem_group);
  return;
}


// ===== menu_ex030115_step @ fffcec84 (19 bytes)

/* Menu item ex030115 TX TIME OUT TIMER: on_step (#74) */

void menu_ex030115_step(void)

{
  menu_step_u8(0,0x1e,&g_opstate.ex030115_tx_time_out_timer);
  return;
}


// ===== menu_ex030116_step @ fffcec97 (18 bytes)

/* Menu item ex030116 MIC SCAN: on_step (#74) */

void menu_ex030116_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030116_mic_scan);
  return;
}


// ===== menu_ex030117_step @ fffceca9 (18 bytes)

/* Menu item ex030117 MIC SCAN RESUME: on_step (#74) */

void menu_ex030117_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030117_mic_scan_resume);
  return;
}


// ===== menu_ex030118_step @ fffcecbb (20 bytes)

/* Menu item ex030118 REF FREQ FINE ADJ: on_step (#74) */

void menu_ex030118_step(void)

{
  menu_step_s8(-0x19,'\x19',&g_opstate.ex030118_ref_freq_fine_adj);
  return;
}


// ===== menu_ex030119_step @ fffceccf (78 bytes)

/* Menu item ex030119 KEYBOARD LANGUAGE: on_step (#74) */

void menu_ex030119_step(void)

{
  menu_step_u8(0,10,&g_opstate.ex030119_keyboard_language);
  if (PTR_s_V01_12_0001b4fd._1_1_ == g_opstate.ex030119_keyboard_language) {
    return;
  }
  PTR_s_V01_12_0001b4fd._1_1_ = g_opstate.ex030119_keyboard_language;
  swtimer_start(0x2b,100);
  PTR_g_ui_00025d60->dl_req_24_later = 1;
  return;
}


// ===== menu_ex030120_step @ fffced1d (19 bytes)

/* Menu item ex030120 MIC P1: on_step (#74) */

void menu_ex030120_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex030120_mic_p1);
  return;
}


// ===== menu_ex030121_step @ fffced30 (19 bytes)

/* Menu item ex030121 MIC P2: on_step (#74) */

void menu_ex030121_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex030121_mic_p2);
  return;
}


// ===== menu_ex030122_step @ fffced43 (19 bytes)

/* Menu item ex030122 MIC P3: on_step (#74) */

void menu_ex030122_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex030122_mic_p3);
  return;
}


// ===== menu_ex030123_step @ fffced56 (19 bytes)

/* Menu item ex030123 MIC P4: on_step (#74) */

void menu_ex030123_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex030123_mic_p4);
  return;
}


// ===== menu_ex030124_step @ fffced69 (19 bytes)

/* Menu item ex030124 MIC UP: on_step (#74) */

void menu_ex030124_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex030124_mic_up);
  return;
}


// ===== menu_ex030125_step @ fffced7c (19 bytes)

/* Menu item ex030125 MIC DOWN: on_step (#74) */

void menu_ex030125_step(void)

{
  menu_step_u8(0,0x14,&g_opstate.ex030125_mic_down);
  return;
}


// ===== menu_ex030126_step @ fffced8f (78 bytes)

/* Menu item ex030126 SCU-LAN10: on_step (#74) */

void menu_ex030126_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030126_scu_lan10);
  if (PTR_s_V01_12_0001b4fd._2_1_ == g_opstate.ex030126_scu_lan10) {
    return;
  }
  PTR_s_V01_12_0001b4fd._2_1_ = g_opstate.ex030126_scu_lan10;
  swtimer_start(0x2b,100);
  PTR_g_ui_00025d60->dl_req_24_later = 1;
  return;
}


// ===== menu_ex030201_step @ fffceddd (18 bytes)

/* Menu item ex030201 IF NOTCH WIDTH: on_step (#74) */

void menu_ex030201_step(void)

{
  menu_step_u8(0,1,&g_opstate.ex030201_if_notch_width);
  return;
}


// ===== menu_ex030202_step @ fffcedef (18 bytes)

/* Menu item ex030202 NB REJECTION: on_step (#74) */

void menu_ex030202_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex030202_nb_rejection);
  return;
}


// ===== menu_ex030203_step @ fffcee01 (18 bytes)

/* Menu item ex030203 NB WIDTH: on_step (#74) */

void menu_ex030203_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex030203_nb_width);
  return;
}


// ===== menu_ex030204_step @ fffcee13 (18 bytes)

/* Menu item ex030204 APF WIDTH: on_step (#74) */

void menu_ex030204_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex030204_apf_width);
  return;
}


// ===== menu_ex030205_step @ fffcee25 (20 bytes)

/* Menu item ex030205 CONTOUR LEVEL: on_step (#74) */

void menu_ex030205_step(void)

{
  menu_step_s8(-0x28,'\x14',&g_opstate.ex030205_contour_level);
  return;
}


// ===== menu_ex030206_step @ fffcee39 (18 bytes)

/* Menu item ex030206 CONTOUR WIDTH: on_step (#74) */

void menu_ex030206_step(void)

{
  menu_step_u8(1,0xb,&g_opstate.ex030206_contour_width);
  return;
}


// ===== menu_ex030301_step @ fffcee4b (18 bytes)

/* Menu item ex030301 AMC RELEASE TIME: on_step (#74) */

void menu_ex030301_step(void)

{
  menu_step_u8(0,2,&g_opstate.ex030301_amc_release_time);
  return;
}


// ===== menu_ex030302_step @ fffcee5d (18 bytes)

/* Menu item ex030302 PRMTRC EQ1 FREQ: on_step (#74) */

void menu_ex030302_step(void)

{
  menu_step_u8(0,7,&g_opstate.ex030302_prmtrc_eq1_freq);
  return;
}


// ===== menu_ex030303_step @ fffcee6f (19 bytes)

/* Menu item ex030303 PRMTRC EQ1 LEVEL: on_step (#74) */

void menu_ex030303_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex030303_prmtrc_eq1_level);
  return;
}


// ===== menu_ex030304_step @ fffcee82 (18 bytes)

/* Menu item ex030304 PRMTRC EQ1 BWTH: on_step (#74) */

void menu_ex030304_step(void)

{
  menu_step_u8(0,10,&g_opstate.ex030304_prmtrc_eq1_bwth);
  return;
}


// ===== menu_ex030305_step @ fffcee94 (18 bytes)

/* Menu item ex030305 PRMTRC EQ2 FREQ: on_step (#74) */

void menu_ex030305_step(void)

{
  menu_step_u8(0,9,&g_opstate.ex030305_prmtrc_eq2_freq);
  return;
}


// ===== menu_ex030306_step @ fffceea6 (19 bytes)

/* Menu item ex030306 PRMTRC EQ2 LEVEL: on_step (#74) */

void menu_ex030306_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex030306_prmtrc_eq2_level);
  return;
}


// ===== menu_ex030307_step @ fffceeb9 (18 bytes)

/* Menu item ex030307 PRMTRC EQ2 BWTH: on_step (#74) */

void menu_ex030307_step(void)

{
  menu_step_u8(0,10,&g_opstate.ex030307_prmtrc_eq2_bwth);
  return;
}


// ===== menu_ex030308_step @ fffceecb (19 bytes)

/* Menu item ex030308 PRMTRC EQ3 FREQ: on_step (#74) */

void menu_ex030308_step(void)

{
  menu_step_u8(0,0x12,&g_opstate.ex030308_prmtrc_eq3_freq);
  return;
}


// ===== menu_ex030309_step @ fffceede (19 bytes)

/* Menu item ex030309 PRMTRC EQ3 LEVEL: on_step (#74) */

void menu_ex030309_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex030309_prmtrc_eq3_level);
  return;
}


// ===== menu_ex030310_step @ fffceef1 (18 bytes)

/* Menu item ex030310 PRMTRC EQ3 BWTH: on_step (#74) */

void menu_ex030310_step(void)

{
  menu_step_u8(0,10,&g_opstate.ex030310_prmtrc_eq3_bwth);
  return;
}


// ===== menu_ex030311_step @ fffcef03 (18 bytes)

/* Menu item ex030311 P PRMTRC EQ1 FREQ: on_step (#74) */

void menu_ex030311_step(void)

{
  menu_step_u8(0,7,&g_opstate.ex030311_p_prmtrc_eq1_freq);
  return;
}


// ===== menu_ex030312_step @ fffcef15 (19 bytes)

/* Menu item ex030312 P PRMTRC EQ1 LEVEL: on_step (#74) */

void menu_ex030312_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex030312_p_prmtrc_eq1_level);
  return;
}


// ===== menu_ex030313_step @ fffcef28 (18 bytes)

/* Menu item ex030313 P PRMTRC EQ1 BWTH: on_step (#74) */

void menu_ex030313_step(void)

{
  menu_step_u8(0,10,&g_opstate.ex030313_p_prmtrc_eq1_bwth);
  return;
}


// ===== menu_ex030314_step @ fffcef3a (18 bytes)

/* Menu item ex030314 P PRMTRC EQ2 FREQ: on_step (#74) */

void menu_ex030314_step(void)

{
  menu_step_u8(0,9,&g_opstate.ex030314_p_prmtrc_eq2_freq);
  return;
}


// ===== menu_ex030315_step @ fffcef4c (19 bytes)

/* Menu item ex030315 P PRMTRC EQ2 LEVEL: on_step (#74) */

void menu_ex030315_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex030315_p_prmtrc_eq2_level);
  return;
}


// ===== menu_ex030316_step @ fffcef5f (18 bytes)

/* Menu item ex030316 P PRMTRC EQ2 BWTH: on_step (#74) */

void menu_ex030316_step(void)

{
  menu_step_u8(0,10,&g_opstate.ex030316_p_prmtrc_eq2_bwth);
  return;
}


// ===== menu_ex030317_step @ fffcef71 (19 bytes)

/* Menu item ex030317 P PRMTRC EQ3 FREQ: on_step (#74) */

void menu_ex030317_step(void)

{
  menu_step_u8(0,0x12,&g_opstate.ex030317_p_prmtrc_eq3_freq);
  return;
}


// ===== menu_ex030318_step @ fffcef84 (19 bytes)

/* Menu item ex030318 P PRMTRC EQ3 LEVEL: on_step (#74) */

void menu_ex030318_step(void)

{
  menu_step_s8(-0x14,'\n',&g_opstate.ex030318_p_prmtrc_eq3_level);
  return;
}


// ===== menu_ex030319_step @ fffcef97 (18 bytes)

/* Menu item ex030319 P PRMTRC EQ3 BWTH: on_step (#74) */

void menu_ex030319_step(void)

{
  menu_step_u8(0,10,&g_opstate.ex030319_p_prmtrc_eq3_bwth);
  return;
}


// ===== menu_ex030401_step @ fffcefa9 (24 bytes)

/* Menu item ex030401 HF MAX POWER: on_step (#74) */

void menu_ex030401_step(void)

{
  byte bVar1;
  
  bVar1 = max_power_limit(0);
  menu_step_u8(5,bVar1,&g_opstate.ex030401_hf_max_power);
  return;
}


// ===== menu_ex030402_step @ fffcefc1 (24 bytes)

/* Menu item ex030402 50M MAX POWER: on_step (#74) */

void menu_ex030402_step(void)

{
  byte bVar1;
  
  bVar1 = max_power_limit(1);
  menu_step_u8(5,bVar1,&g_opstate.ex030402_50m_max_power);
  return;
}


// ===== menu_ex030403_step @ fffcefd9 (24 bytes)

/* Menu item ex030403 70M MAX POWER: on_step (#74) */

void menu_ex030403_step(void)

{
  byte bVar1;
  
  bVar1 = max_power_limit(2);
  menu_step_u8(5,bVar1,&g_opstate.ex030403_70m_max_power);
  return;
}


// ===== menu_ex030404_step @ fffceff1 (43 bytes)

/* Menu item ex030404 AM MAX POWER: on_step (#74) */

void menu_ex030404_step(void)

{
  byte bVar1;
  ushort uVar2;
  undefined1 local_1;
  
  uVar2 = dest_code_get();
  if (uVar2 == 0x60e6) {
    local_1 = 4;
  }
  else {
    local_1 = 3;
  }
  bVar1 = max_power_limit(local_1);
  menu_step_u8(5,bVar1,&g_opstate.ex030404_am_max_power);
  return;
}

