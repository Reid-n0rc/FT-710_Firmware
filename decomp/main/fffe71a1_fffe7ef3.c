// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== ai_ex010114 @ fffe71a1 (76 bytes)

/* AI change detector for menu item EX010114 (table 0xFFF8E1A0[13]) */

void ai_ex010114(void)

{
  if (DAT_0001b2a7 == g_opstate.ex010114_mod_source) {
    return;
  }
  DAT_0001b2a7 = g_opstate.ex010114_mod_source;
  DAT_0001b23d = nib2hex(g_opstate.ex010114_mod_source);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010115 @ fffe71ed (61 bytes)

/* AI change detector for menu item EX010115 (table 0xFFF8E1A0[14]) */

void ai_ex010115(void)

{
  if (DAT_0001b2a8 == g_opstate.ex010115_usb_mod_gain) {
    return;
  }
  DAT_0001b2a8 = g_opstate.ex010115_usb_mod_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010115_usb_mod_gain,1,0);
  return;
}


// ===== ai_ex010116 @ fffe722a (61 bytes)

/* AI change detector for menu item EX010116 (table 0xFFF8E1A0[15]) */

void ai_ex010116(void)

{
  if (DAT_0001b2a9 == g_opstate.ex010116_rear_mod_gain) {
    return;
  }
  DAT_0001b2a9 = g_opstate.ex010116_rear_mod_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010116_rear_mod_gain,1,0);
  return;
}


// ===== ai_ex010117 @ fffe7267 (76 bytes)

/* AI change detector for menu item EX010117 (table 0xFFF8E1A0[16]) */

void ai_ex010117(void)

{
  if (DAT_0001b2aa == g_opstate.ex010117_rptt_select) {
    return;
  }
  DAT_0001b2aa = g_opstate.ex010117_rptt_select;
  DAT_0001b23d = nib2hex(g_opstate.ex010117_rptt_select);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010118 @ fffe72b3 (61 bytes)

/* AI change detector for menu item EX010118 (table 0xFFF8E1A0[17]) */

void ai_ex010118(void)

{
  if (DAT_0001b2ab == g_opstate.ex010118_nar_width) {
    return;
  }
  DAT_0001b2ab = g_opstate.ex010118_nar_width;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010118_nar_width,0,0);
  return;
}


// ===== ai_ex010119 @ fffe72f0 (76 bytes)

/* AI change detector for menu item EX010119 (table 0xFFF8E1A0[18]) */

void ai_ex010119(void)

{
  if (DAT_0001b2ac == g_opstate.ex010119_cw_auto_mode) {
    return;
  }
  DAT_0001b2ac = g_opstate.ex010119_cw_auto_mode;
  DAT_0001b23d = nib2hex(g_opstate.ex010119_cw_auto_mode);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010201 @ fffe733c (61 bytes)

/* AI change detector for menu item EX010201 (table 0xFFF8E1A0[19]) */

void ai_ex010201(void)

{
  if (DAT_0001b2ad == g_opstate.ex010201_af_treble_gain) {
    return;
  }
  DAT_0001b2ad = g_opstate.ex010201_af_treble_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010201_af_treble_gain,0,1);
  return;
}


// ===== ai_ex010202 @ fffe7379 (61 bytes)

/* AI change detector for menu item EX010202 (table 0xFFF8E1A0[20]) */

void ai_ex010202(void)

{
  if (DAT_0001b2ae == g_opstate.ex010202_af_middle_tone_gain) {
    return;
  }
  DAT_0001b2ae = g_opstate.ex010202_af_middle_tone_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010202_af_middle_tone_gain,0,1);
  return;
}


// ===== ai_ex010203 @ fffe73b6 (61 bytes)

/* AI change detector for menu item EX010203 (table 0xFFF8E1A0[21]) */

void ai_ex010203(void)

{
  if (DAT_0001b2af == g_opstate.ex010203_af_bass_gain) {
    return;
  }
  DAT_0001b2af = g_opstate.ex010203_af_bass_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010203_af_bass_gain,0,1);
  return;
}


// ===== ai_ex010204 @ fffe73f3 (72 bytes)

/* AI change detector for menu item EX010204 (table 0xFFF8E1A0[22]) */

void ai_ex010204(void)

{
  if (DAT_0001b2b0 == g_opstate.ex010204_agc_fast_delay) {
    return;
  }
  DAT_0001b2b0 = g_opstate.ex010204_agc_fast_delay;
  DAT_0001ff12 = ai_ex_fmt_u16_4((g_opstate.ex010204_agc_fast_delay + 1) * 0x14);
  return;
}


// ===== ai_ex010205 @ fffe743b (72 bytes)

/* AI change detector for menu item EX010205 (table 0xFFF8E1A0[23]) */

void ai_ex010205(void)

{
  if (DAT_0001b2b1 == g_opstate.ex010205_agc_mid_delay) {
    return;
  }
  DAT_0001b2b1 = g_opstate.ex010205_agc_mid_delay;
  DAT_0001ff12 = ai_ex_fmt_u16_4((g_opstate.ex010205_agc_mid_delay + 1) * 0x14);
  return;
}


// ===== ai_ex010206 @ fffe7483 (72 bytes)

/* AI change detector for menu item EX010206 (table 0xFFF8E1A0[24]) */

void ai_ex010206(void)

{
  if (DAT_0001b2b2 == g_opstate.ex010206_agc_slow_delay) {
    return;
  }
  DAT_0001b2b2 = g_opstate.ex010206_agc_slow_delay;
  DAT_0001ff12 = ai_ex_fmt_u16_4((g_opstate.ex010206_agc_slow_delay + 1) * 0x14);
  return;
}


// ===== ai_ex010207 @ fffe74cb (61 bytes)

/* AI change detector for menu item EX010207 (table 0xFFF8E1A0[25]) */

void ai_ex010207(void)

{
  if (DAT_0001b2b3 == g_opstate.ex010207_lcut_freq) {
    return;
  }
  DAT_0001b2b3 = g_opstate.ex010207_lcut_freq;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010207_lcut_freq,0,0);
  return;
}


// ===== ai_ex010208 @ fffe7508 (76 bytes)

/* AI change detector for menu item EX010208 (table 0xFFF8E1A0[26]) */

void ai_ex010208(void)

{
  if (DAT_0001b2b4 == g_opstate.ex010208_lcut_slope) {
    return;
  }
  DAT_0001b2b4 = g_opstate.ex010208_lcut_slope;
  DAT_0001b23d = nib2hex(g_opstate.ex010208_lcut_slope);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010209 @ fffe7554 (61 bytes)

/* AI change detector for menu item EX010209 (table 0xFFF8E1A0[27]) */

void ai_ex010209(void)

{
  if (DAT_0001b2b5 == g_opstate.ex010209_hcut_freq) {
    return;
  }
  DAT_0001b2b5 = g_opstate.ex010209_hcut_freq;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010209_hcut_freq,0,0);
  return;
}


// ===== ai_ex010210 @ fffe7591 (76 bytes)

/* AI change detector for menu item EX010210 (table 0xFFF8E1A0[28]) */

void ai_ex010210(void)

{
  if (DAT_0001b2b6 == g_opstate.ex010210_hcut_slope) {
    return;
  }
  DAT_0001b2b6 = g_opstate.ex010210_hcut_slope;
  DAT_0001b23d = nib2hex(g_opstate.ex010210_hcut_slope);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010211 @ fffe75dd (61 bytes)

/* AI change detector for menu item EX010211 (table 0xFFF8E1A0[29]) */

void ai_ex010211(void)

{
  if (DAT_0001b2b7 == g_opstate.ex010211_usb_out_level) {
    return;
  }
  DAT_0001b2b7 = g_opstate.ex010211_usb_out_level;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010211_usb_out_level,1,0);
  return;
}


// ===== ai_ex010212 @ fffe761a (61 bytes)

/* AI change detector for menu item EX010212 (table 0xFFF8E1A0[30]) */

void ai_ex010212(void)

{
  if (DAT_0001b2b8 == g_opstate.ex010212_rear_out_level) {
    return;
  }
  DAT_0001b2b8 = g_opstate.ex010212_rear_out_level;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010212_rear_out_level,1,0);
  return;
}


// ===== ai_ex010213 @ fffe7657 (76 bytes)

/* AI change detector for menu item EX010213 (table 0xFFF8E1A0[31]) */

void ai_ex010213(void)

{
  if (DAT_0001b2b9 == g_opstate.ex010213_tx_bpf_sel) {
    return;
  }
  DAT_0001b2b9 = g_opstate.ex010213_tx_bpf_sel;
  DAT_0001b23d = nib2hex(g_opstate.ex010213_tx_bpf_sel);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010214 @ fffe76a3 (76 bytes)

/* AI change detector for menu item EX010214 (table 0xFFF8E1A0[32]) */

void ai_ex010214(void)

{
  if (DAT_0001b2ba == g_opstate.ex010214_mod_source) {
    return;
  }
  DAT_0001b2ba = g_opstate.ex010214_mod_source;
  DAT_0001b23d = nib2hex(g_opstate.ex010214_mod_source);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010215 @ fffe76ef (61 bytes)

/* AI change detector for menu item EX010215 (table 0xFFF8E1A0[33]) */

void ai_ex010215(void)

{
  if (DAT_0001b2bb == g_opstate.ex010215_usb_mod_gain) {
    return;
  }
  DAT_0001b2bb = g_opstate.ex010215_usb_mod_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010215_usb_mod_gain,1,0);
  return;
}


// ===== ai_ex010216 @ fffe772c (61 bytes)

/* AI change detector for menu item EX010216 (table 0xFFF8E1A0[34]) */

void ai_ex010216(void)

{
  if (DAT_0001b2bc == g_opstate.ex010216_rear_mod_gain) {
    return;
  }
  DAT_0001b2bc = g_opstate.ex010216_rear_mod_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010216_rear_mod_gain,1,0);
  return;
}


// ===== ai_ex010217 @ fffe7769 (76 bytes)

/* AI change detector for menu item EX010217 (table 0xFFF8E1A0[35]) */

void ai_ex010217(void)

{
  if (DAT_0001b2bd == g_opstate.ex010217_rptt_select) {
    return;
  }
  DAT_0001b2bd = g_opstate.ex010217_rptt_select;
  DAT_0001b23d = nib2hex(g_opstate.ex010217_rptt_select);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010301 @ fffe77b5 (61 bytes)

/* AI change detector for menu item EX010301 (table 0xFFF8E1A0[36]) */

void ai_ex010301(void)

{
  if (DAT_0001b2be == g_opstate.ex010301_af_treble_gain) {
    return;
  }
  DAT_0001b2be = g_opstate.ex010301_af_treble_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010301_af_treble_gain,0,1);
  return;
}


// ===== ai_ex010302 @ fffe77f2 (61 bytes)

/* AI change detector for menu item EX010302 (table 0xFFF8E1A0[37]) */

void ai_ex010302(void)

{
  if (DAT_0001b2bf == g_opstate.ex010302_af_middle_tone_gain) {
    return;
  }
  DAT_0001b2bf = g_opstate.ex010302_af_middle_tone_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010302_af_middle_tone_gain,0,1);
  return;
}


// ===== ai_ex010303 @ fffe782f (61 bytes)

/* AI change detector for menu item EX010303 (table 0xFFF8E1A0[38]) */

void ai_ex010303(void)

{
  if (DAT_0001b2c0 == g_opstate.ex010303_af_bass_gain) {
    return;
  }
  DAT_0001b2c0 = g_opstate.ex010303_af_bass_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010303_af_bass_gain,0,1);
  return;
}


// ===== ai_ex010304 @ fffe786c (72 bytes)

/* AI change detector for menu item EX010304 (table 0xFFF8E1A0[39]) */

void ai_ex010304(void)

{
  if (DAT_0001b2c1 == g_opstate.ex010304_agc_fast_delay) {
    return;
  }
  DAT_0001b2c1 = g_opstate.ex010304_agc_fast_delay;
  DAT_0001ff12 = ai_ex_fmt_u16_4((g_opstate.ex010304_agc_fast_delay + 1) * 0x14);
  return;
}


// ===== ai_ex010305 @ fffe78b4 (72 bytes)

/* AI change detector for menu item EX010305 (table 0xFFF8E1A0[40]) */

void ai_ex010305(void)

{
  if (DAT_0001b2c2 == g_opstate.ex010305_agc_mid_delay) {
    return;
  }
  DAT_0001b2c2 = g_opstate.ex010305_agc_mid_delay;
  DAT_0001ff12 = ai_ex_fmt_u16_4((g_opstate.ex010305_agc_mid_delay + 1) * 0x14);
  return;
}


// ===== ai_ex010306 @ fffe78fc (72 bytes)

/* AI change detector for menu item EX010306 (table 0xFFF8E1A0[41]) */

void ai_ex010306(void)

{
  if (DAT_0001b2c3 == g_opstate.ex010306_agc_slow_delay) {
    return;
  }
  DAT_0001b2c3 = g_opstate.ex010306_agc_slow_delay;
  DAT_0001ff12 = ai_ex_fmt_u16_4((g_opstate.ex010306_agc_slow_delay + 1) * 0x14);
  return;
}


// ===== ai_ex010307 @ fffe7944 (61 bytes)

/* AI change detector for menu item EX010307 (table 0xFFF8E1A0[42]) */

void ai_ex010307(void)

{
  if (DAT_0001b2c4 == g_opstate.ex010307_lcut_freq) {
    return;
  }
  DAT_0001b2c4 = g_opstate.ex010307_lcut_freq;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010307_lcut_freq,0,0);
  return;
}


// ===== ai_ex010308 @ fffe7981 (76 bytes)

/* AI change detector for menu item EX010308 (table 0xFFF8E1A0[43]) */

void ai_ex010308(void)

{
  if (DAT_0001b2c5 == g_opstate.ex010308_lcut_slope) {
    return;
  }
  DAT_0001b2c5 = g_opstate.ex010308_lcut_slope;
  DAT_0001b23d = nib2hex(g_opstate.ex010308_lcut_slope);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010309 @ fffe79cd (61 bytes)

/* AI change detector for menu item EX010309 (table 0xFFF8E1A0[44]) */

void ai_ex010309(void)

{
  if (DAT_0001b2c6 == g_opstate.ex010309_hcut_freq) {
    return;
  }
  DAT_0001b2c6 = g_opstate.ex010309_hcut_freq;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010309_hcut_freq,0,0);
  return;
}


// ===== ai_ex010310 @ fffe7a0a (76 bytes)

/* AI change detector for menu item EX010310 (table 0xFFF8E1A0[45]) */

void ai_ex010310(void)

{
  if (DAT_0001b2c7 == g_opstate.ex010310_hcut_slope) {
    return;
  }
  DAT_0001b2c7 = g_opstate.ex010310_hcut_slope;
  DAT_0001b23d = nib2hex(g_opstate.ex010310_hcut_slope);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010311 @ fffe7a56 (61 bytes)

/* AI change detector for menu item EX010311 (table 0xFFF8E1A0[46]) */

void ai_ex010311(void)

{
  if (DAT_0001b2c8 == g_opstate.ex010311_usb_out_level) {
    return;
  }
  DAT_0001b2c8 = g_opstate.ex010311_usb_out_level;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010311_usb_out_level,1,0);
  return;
}


// ===== ai_ex010312 @ fffe7a93 (61 bytes)

/* AI change detector for menu item EX010312 (table 0xFFF8E1A0[47]) */

void ai_ex010312(void)

{
  if (DAT_0001b2c9 == g_opstate.ex010312_rear_out_level) {
    return;
  }
  DAT_0001b2c9 = g_opstate.ex010312_rear_out_level;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010312_rear_out_level,1,0);
  return;
}


// ===== ai_ex010313 @ fffe7ad0 (76 bytes)

/* AI change detector for menu item EX010313 (table 0xFFF8E1A0[48]) */

void ai_ex010313(void)

{
  if (DAT_0001b2ca == g_opstate.ex010313_mod_source) {
    return;
  }
  DAT_0001b2ca = g_opstate.ex010313_mod_source;
  DAT_0001b23d = nib2hex(g_opstate.ex010313_mod_source);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010314 @ fffe7b1c (61 bytes)

/* AI change detector for menu item EX010314 (table 0xFFF8E1A0[49]) */

void ai_ex010314(void)

{
  if (DAT_0001b2cb == g_opstate.ex010314_usb_mod_gain) {
    return;
  }
  DAT_0001b2cb = g_opstate.ex010314_usb_mod_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010314_usb_mod_gain,1,0);
  return;
}


// ===== ai_ex010315 @ fffe7b59 (61 bytes)

/* AI change detector for menu item EX010315 (table 0xFFF8E1A0[50]) */

void ai_ex010315(void)

{
  if (DAT_0001b2cc == g_opstate.ex010315_rear_mod_gain) {
    return;
  }
  DAT_0001b2cc = g_opstate.ex010315_rear_mod_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010315_rear_mod_gain,1,0);
  return;
}


// ===== ai_ex010316 @ fffe7b96 (76 bytes)

/* AI change detector for menu item EX010316 (table 0xFFF8E1A0[51]) */

void ai_ex010316(void)

{
  if (DAT_0001b2cd == g_opstate.ex010316_rptt_select) {
    return;
  }
  DAT_0001b2cd = g_opstate.ex010316_rptt_select;
  DAT_0001b23d = nib2hex(g_opstate.ex010316_rptt_select);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010317 @ fffe7be2 (106 bytes)

/* AI change detector for menu item EX010317 (table 0xFFF8E1A0[52]) */

void ai_ex010317(void)

{
  byte n;
  undefined1 local_1;
  
  if (g_opstate.active_vfo == 0) {
    local_1 = g_opstate.vfo_a.flags2;
  }
  else {
    local_1 = g_opstate.vfo_b.flags2;
  }
  n = local_1 >> 2 & 3;
  if (DAT_0001b2ce == n) {
    return;
  }
  DAT_0001b2ce = n;
  DAT_0001b23d = nib2hex(n);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010318 @ fffe7c4c (67 bytes)

/* AI change detector for menu item EX010318 (table 0xFFF8E1A0[53]) */

void ai_ex010318(void)

{
  if (DAT_0001b2cf == g_opstate.ex010318_rpt_shift_28mhz) {
    return;
  }
  DAT_0001b2cf = g_opstate.ex010318_rpt_shift_28mhz;
  DAT_0001ff12 = ai_ex_fmt_u16_4((ushort)g_opstate.ex010318_rpt_shift_28mhz * 10);
  return;
}


// ===== ai_ex010319 @ fffe7c8f (82 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe7c9f) */
/* AI change detector for menu item EX010319 (table 0xFFF8E1A0[54]) */

void ai_ex010319(void)

{
  short sVar1;
  
  sVar1 = CONCAT11(g_opstate.ex010319_rpt_shift_50mhz_be[0],g_opstate.ex010319_rpt_shift_50mhz_be[1]
                  );
  if (DAT_0001ff14 == sVar1) {
    return;
  }
  DAT_0001ff14 = sVar1;
  DAT_0001ff12 = ai_ex_fmt_u16_4(sVar1 * 10);
  return;
}


// ===== ai_ex010320 @ fffe7ce1 (114 bytes)

/* AI change detector for menu item EX010320 (table 0xFFF8E1A0[55]) */

void ai_ex010320(void)

{
  byte local_1;
  
  local_1 = g_opstate.vfo_a.flags3;
  if (g_opstate.active_vfo != 0) {
    local_1 = g_opstate.vfo_b.flags3;
  }
  local_1 = local_1 & 0x38;
  if (DAT_0001b2d0 != local_1) {
    DAT_0001b2d0 = local_1;
    DAT_0001b23d = nib2hex(local_1 >> 3);
    DAT_0001b23e = 0x3b;
    DAT_0001ff12 = 10;
    return;
  }
  return;
}


// ===== ai_ex010321 @ fffe7d53 (89 bytes)

/* AI change detector for menu item EX010321 (table 0xFFF8E1A0[56]) */

void ai_ex010321(void)

{
  undefined1 local_1;
  
  if (g_opstate.active_vfo == 0) {
    local_1 = g_opstate.vfo_a.tone_num;
  }
  else {
    local_1 = g_opstate.vfo_b.tone_num;
  }
  if (DAT_0001b2d1 == local_1) {
    return;
  }
  DAT_0001b2d1 = local_1;
  DAT_0001ff12 = ai_ex_fmt_u8(local_1,1,0);
  return;
}


// ===== ai_ex010401 @ fffe7dac (61 bytes)

/* AI change detector for menu item EX010401 (table 0xFFF8E1A0[57]) */

void ai_ex010401(void)

{
  if (DAT_0001b2d2 == g_opstate.ex010401_af_treble_gain) {
    return;
  }
  DAT_0001b2d2 = g_opstate.ex010401_af_treble_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010401_af_treble_gain,0,1);
  return;
}


// ===== ai_ex010402 @ fffe7de9 (61 bytes)

/* AI change detector for menu item EX010402 (table 0xFFF8E1A0[58]) */

void ai_ex010402(void)

{
  if (DAT_0001b2d3 == g_opstate.ex010402_af_middle_tone_gain) {
    return;
  }
  DAT_0001b2d3 = g_opstate.ex010402_af_middle_tone_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010402_af_middle_tone_gain,0,1);
  return;
}


// ===== ai_ex010403 @ fffe7e26 (61 bytes)

/* AI change detector for menu item EX010403 (table 0xFFF8E1A0[59]) */

void ai_ex010403(void)

{
  if (DAT_0001b2d4 == g_opstate.ex010403_af_bass_gain) {
    return;
  }
  DAT_0001b2d4 = g_opstate.ex010403_af_bass_gain;
  DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.ex010403_af_bass_gain,0,1);
  return;
}


// ===== ai_ex010404 @ fffe7e63 (72 bytes)

/* AI change detector for menu item EX010404 (table 0xFFF8E1A0[60]) */

void ai_ex010404(void)

{
  if (DAT_0001b2d5 == g_opstate.ex010404_agc_fast_delay) {
    return;
  }
  DAT_0001b2d5 = g_opstate.ex010404_agc_fast_delay;
  DAT_0001ff12 = ai_ex_fmt_u16_4((g_opstate.ex010404_agc_fast_delay + 1) * 0x14);
  return;
}


// ===== ai_ex010405 @ fffe7eab (72 bytes)

/* AI change detector for menu item EX010405 (table 0xFFF8E1A0[61]) */

void ai_ex010405(void)

{
  if (DAT_0001b2d6 == g_opstate.ex010405_agc_mid_delay) {
    return;
  }
  DAT_0001b2d6 = g_opstate.ex010405_agc_mid_delay;
  DAT_0001ff12 = ai_ex_fmt_u16_4((g_opstate.ex010405_agc_mid_delay + 1) * 0x14);
  return;
}


// ===== ai_ex010406 @ fffe7ef3 (72 bytes)

/* AI change detector for menu item EX010406 (table 0xFFF8E1A0[62]) */

void ai_ex010406(void)

{
  if (DAT_0001b2d7 == g_opstate.ex010406_agc_slow_delay) {
    return;
  }
  DAT_0001b2d7 = g_opstate.ex010406_agc_slow_delay;
  DAT_0001ff12 = ai_ex_fmt_u16_4((g_opstate.ex010406_agc_slow_delay + 1) * 0x14);
  return;
}

