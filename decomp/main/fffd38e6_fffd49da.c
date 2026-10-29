// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex060213_step @ fffd38e6 (6 bytes)

/* Menu item ex060213 REAR OUT LEVEL: on_step (#74) */

void menu_ex060213_step(void)

{
  FUN_fffd38fe(2);
  return;
}


// ===== menu_ex060313_step @ fffd38ec (6 bytes)

/* Menu item ex060313 REAR OUT LEVEL: on_step (#74) */

void menu_ex060313_step(void)

{
  FUN_fffd38fe(3);
  return;
}


// ===== menu_ex060413_step @ fffd38f2 (6 bytes)

/* Menu item ex060413 REAR OUT LEVEL: on_step (#74) */

void menu_ex060413_step(void)

{
  FUN_fffd38fe(4);
  return;
}


// ===== menu_ex060513_step @ fffd38f8 (6 bytes)

/* Menu item ex060513 REAR OUT LEVEL: on_step (#74) */

void menu_ex060513_step(void)

{
  FUN_fffd38fe(5);
  return;
}


// ===== FUN_fffd38fe @ fffd38fe (133 bytes)

void FUN_fffd38fe(byte param_1)

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
    local_8 = &g_opstate.presets[4].rear_out_level;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].rear_out_level;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].rear_out_level;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].rear_out_level;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].rear_out_level;
  }
  menu_step_u8(0,100,local_8);
  return;
}


// ===== menu_ex060114_step @ fffd3983 (6 bytes)

/* Menu item ex060114 TX BPF SEL: on_step (#74) */

void menu_ex060114_step(void)

{
  FUN_fffd39a1(1);
  return;
}


// ===== menu_ex060214_step @ fffd3989 (6 bytes)

/* Menu item ex060214 TX BPF SEL: on_step (#74) */

void menu_ex060214_step(void)

{
  FUN_fffd39a1(2);
  return;
}


// ===== menu_ex060314_step @ fffd398f (6 bytes)

/* Menu item ex060314 TX BPF SEL: on_step (#74) */

void menu_ex060314_step(void)

{
  FUN_fffd39a1(3);
  return;
}


// ===== menu_ex060414_step @ fffd3995 (6 bytes)

/* Menu item ex060414 TX BPF SEL: on_step (#74) */

void menu_ex060414_step(void)

{
  FUN_fffd39a1(4);
  return;
}


// ===== menu_ex060514_step @ fffd399b (6 bytes)

/* Menu item ex060514 TX BPF SEL: on_step (#74) */

void menu_ex060514_step(void)

{
  FUN_fffd39a1(5);
  return;
}


// ===== FUN_fffd39a1 @ fffd39a1 (132 bytes)

void FUN_fffd39a1(byte param_1)

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
    local_8 = &g_opstate.presets[4].tx_bpf_sel;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].tx_bpf_sel;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].tx_bpf_sel;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].tx_bpf_sel;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].tx_bpf_sel;
  }
  menu_step_u8(0,4,local_8);
  return;
}


// ===== menu_ex060115_step @ fffd3a25 (6 bytes)

/* Menu item ex060115 MOD SOURCE: on_step (#74) */

void menu_ex060115_step(void)

{
  FUN_fffd3a43(1);
  return;
}


// ===== menu_ex060215_step @ fffd3a2b (6 bytes)

/* Menu item ex060215 MOD SOURCE: on_step (#74) */

void menu_ex060215_step(void)

{
  FUN_fffd3a43(2);
  return;
}


// ===== menu_ex060315_step @ fffd3a31 (6 bytes)

/* Menu item ex060315 MOD SOURCE: on_step (#74) */

void menu_ex060315_step(void)

{
  FUN_fffd3a43(3);
  return;
}


// ===== menu_ex060415_step @ fffd3a37 (6 bytes)

/* Menu item ex060415 MOD SOURCE: on_step (#74) */

void menu_ex060415_step(void)

{
  FUN_fffd3a43(4);
  return;
}


// ===== menu_ex060515_step @ fffd3a3d (6 bytes)

/* Menu item ex060515 MOD SOURCE: on_step (#74) */

void menu_ex060515_step(void)

{
  FUN_fffd3a43(5);
  return;
}


// ===== FUN_fffd3a43 @ fffd3a43 (132 bytes)

void FUN_fffd3a43(byte param_1)

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
    local_8 = &g_opstate.presets[4].mod_source;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].mod_source;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].mod_source;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].mod_source;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].mod_source;
  }
  menu_step_u8(0,3,local_8);
  return;
}


// ===== menu_ex060116_step @ fffd3ac7 (6 bytes)

/* Menu item ex060116 USB MOD GAIN: on_step (#74) */

void menu_ex060116_step(void)

{
  FUN_fffd3ae5(1);
  return;
}


// ===== menu_ex060216_step @ fffd3acd (6 bytes)

/* Menu item ex060216 USB MOD GAIN: on_step (#74) */

void menu_ex060216_step(void)

{
  FUN_fffd3ae5(2);
  return;
}


// ===== menu_ex060316_step @ fffd3ad3 (6 bytes)

/* Menu item ex060316 USB MOD GAIN: on_step (#74) */

void menu_ex060316_step(void)

{
  FUN_fffd3ae5(3);
  return;
}


// ===== menu_ex060416_step @ fffd3ad9 (6 bytes)

/* Menu item ex060416 USB MOD GAIN: on_step (#74) */

void menu_ex060416_step(void)

{
  FUN_fffd3ae5(4);
  return;
}


// ===== menu_ex060516_step @ fffd3adf (6 bytes)

/* Menu item ex060516 USB MOD GAIN: on_step (#74) */

void menu_ex060516_step(void)

{
  FUN_fffd3ae5(5);
  return;
}


// ===== FUN_fffd3ae5 @ fffd3ae5 (133 bytes)

void FUN_fffd3ae5(byte param_1)

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
    local_8 = &g_opstate.presets[4].usb_mod_gain;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].usb_mod_gain;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].usb_mod_gain;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].usb_mod_gain;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].usb_mod_gain;
  }
  menu_step_u8(0,100,local_8);
  return;
}


// ===== menu_ex060117_step @ fffd3b6a (6 bytes)

/* Menu item ex060117 REAR MOD GAIN: on_step (#74) */

void menu_ex060117_step(void)

{
  FUN_fffd3b88(1);
  return;
}


// ===== menu_ex060217_step @ fffd3b70 (6 bytes)

/* Menu item ex060217 REAR MOD GAIN: on_step (#74) */

void menu_ex060217_step(void)

{
  FUN_fffd3b88(2);
  return;
}


// ===== menu_ex060317_step @ fffd3b76 (6 bytes)

/* Menu item ex060317 REAR MOD GAIN: on_step (#74) */

void menu_ex060317_step(void)

{
  FUN_fffd3b88(3);
  return;
}


// ===== menu_ex060417_step @ fffd3b7c (6 bytes)

/* Menu item ex060417 REAR MOD GAIN: on_step (#74) */

void menu_ex060417_step(void)

{
  FUN_fffd3b88(4);
  return;
}


// ===== menu_ex060517_step @ fffd3b82 (6 bytes)

/* Menu item ex060517 REAR MOD GAIN: on_step (#74) */

void menu_ex060517_step(void)

{
  FUN_fffd3b88(5);
  return;
}


// ===== FUN_fffd3b88 @ fffd3b88 (133 bytes)

void FUN_fffd3b88(byte param_1)

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
    local_8 = &g_opstate.presets[4].rear_mod_gain;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].rear_mod_gain;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].rear_mod_gain;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].rear_mod_gain;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].rear_mod_gain;
  }
  menu_step_u8(0,100,local_8);
  return;
}


// ===== menu_ex060118_step @ fffd3c0d (6 bytes)

/* Menu item ex060118 RPTT SELECT: on_step (#74) */

void menu_ex060118_step(void)

{
  FUN_fffd3c2b(1);
  return;
}


// ===== menu_ex060218_step @ fffd3c13 (6 bytes)

/* Menu item ex060218 RPTT SELECT: on_step (#74) */

void menu_ex060218_step(void)

{
  FUN_fffd3c2b(2);
  return;
}


// ===== menu_ex060318_step @ fffd3c19 (6 bytes)

/* Menu item ex060318 RPTT SELECT: on_step (#74) */

void menu_ex060318_step(void)

{
  FUN_fffd3c2b(3);
  return;
}


// ===== menu_ex060418_step @ fffd3c1f (6 bytes)

/* Menu item ex060418 RPTT SELECT: on_step (#74) */

void menu_ex060418_step(void)

{
  FUN_fffd3c2b(4);
  return;
}


// ===== menu_ex060518_step @ fffd3c25 (6 bytes)

/* Menu item ex060518 RPTT SELECT: on_step (#74) */

void menu_ex060518_step(void)

{
  FUN_fffd3c2b(5);
  return;
}


// ===== FUN_fffd3c2b @ fffd3c2b (132 bytes)

void FUN_fffd3c2b(byte param_1)

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
    local_8 = &g_opstate.presets[4].rptt_select;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].rptt_select;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].rptt_select;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].rptt_select;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].rptt_select;
  }
  menu_step_u8(0,3,local_8);
  return;
}


// ===== FUN_fffd3caf @ fffd3caf (38 bytes)

void FUN_fffd3caf(void)

{
  DAT_00015e05 = g_opstate.preset_sel;
  PTR_g_ui_00025d60->menu_p2 = g_opstate.preset_sel;
  return;
}


// ===== menu_m4_21_0_enter @ fffd3cd5 (46 bytes)

/* Menu item m4_21_0 CERTIFICATION: on_enter (#74) */

void menu_m4_21_0_enter(void)

{
  if (PTR_g_ui_00025d60->dl_block_34 != 0) {
    FUN_fffbe544();
    return;
  }
  PTR_g_ui_00025d60->dl_req_34 = 1;
  PTR_g_ui_00025d60->menu_state = 2;
  return;
}


// ===== FUN_fffd3d03 @ fffd3d03 (859 bytes)

void FUN_fffd3d03(void)

{
  g_opstate.menu_cursor_9a3d[0] = DAT_00012238;
  g_opstate.menu_cursor_9a3d[1] = DAT_00012239;
  g_opstate.menu_cursor_9a50[0] = DAT_0001223a;
  g_opstate.menu_cursor_9a50[1] = DAT_0001223b;
  g_opstate.menu_cursor_9a65[0] = DAT_0001223c;
  g_opstate.menu_cursor_9a65[1] = DAT_0001223d;
  g_opstate.menu_cursor_9a7c[0] = DAT_0001223e;
  g_opstate.menu_cursor_9a7c[1] = DAT_0001223f;
  g_opstate.menu_cursor_9a8f[0] = DAT_00012240;
  g_opstate.menu_cursor_9a8f[1] = DAT_00012241;
  g_opstate.menu_cursor_9aa5[0] = DAT_00012242;
  g_opstate.menu_cursor_9aa5[1] = DAT_00012243;
  g_opstate.menu_cursor_9ab3[0] = DAT_00012244;
  g_opstate.menu_cursor_9ab3[1] = DAT_00012245;
  g_opstate.menu_cursor_9acf[0] = DAT_00012246;
  g_opstate.menu_cursor_9acf[1] = DAT_00012247;
  g_opstate.menu_cursor_9ad7[0] = DAT_00012248;
  g_opstate.menu_cursor_9ad7[1] = DAT_00012249;
  g_opstate.menu_cursor_9aec[0] = DAT_0001224a;
  g_opstate.menu_cursor_9aec[1] = DAT_0001224b;
  g_opstate.menu_cursor_9af7[0] = DAT_0001224c;
  g_opstate.menu_cursor_9af7[1] = DAT_0001224d;
  g_opstate.menu_cursor_9aff[0] = DAT_0001224e;
  g_opstate.menu_cursor_9aff[1] = DAT_0001224f;
  g_opstate.menu_cursor_9b12[0] = DAT_00012250;
  g_opstate.menu_cursor_9b12[1] = DAT_00012251;
  g_opstate.menu_cursor_9b18[0] = DAT_00012252;
  g_opstate.menu_cursor_9b18[1] = DAT_00012253;
  g_opstate.menu_cursor_9b1e[0] = DAT_00012254;
  g_opstate.menu_cursor_9b1e[1] = DAT_00012255;
  g_opstate.menu_cursor_9b22[0] = DAT_00012256;
  g_opstate.menu_cursor_9b22[1] = DAT_00012257;
  g_opstate.menu_cursor_9b24[0] = DAT_00012258;
  g_opstate.menu_cursor_9b24[1] = DAT_00012259;
  g_opstate.menu_cursor_9b26[0] = DAT_0001225a;
  g_opstate.menu_cursor_9b26[1] = DAT_0001225b;
  g_opstate.menu_cursor_9b28[0] = DAT_0001225e;
  g_opstate.menu_cursor_9b28[1] = DAT_0001225f;
  g_opstate.menu_cursor_9b2a[0] = DAT_00012260;
  g_opstate.menu_cursor_9b2a[1] = DAT_00012261;
  g_opstate.menu_cursor_9b2c[0] = DAT_00012262;
  g_opstate.menu_cursor_9b2c[1] = DAT_00012263;
  g_opstate.presets[0].menu_cursor[0] = DAT_00012264;
  g_opstate.presets[0].menu_cursor[1] = DAT_00012265;
  g_opstate.presets[1].menu_cursor[0] = DAT_00012266;
  g_opstate.presets[1].menu_cursor[1] = DAT_00012267;
  g_opstate.presets[2].menu_cursor[0] = DAT_00012268;
  g_opstate.presets[2].menu_cursor[1] = DAT_00012269;
  g_opstate.presets[3].menu_cursor[0] = DAT_0001226a;
  g_opstate.presets[3].menu_cursor[1] = DAT_0001226b;
  g_opstate.presets[4].menu_cursor[0] = DAT_0001226c;
  g_opstate.presets[4].menu_cursor[1] = DAT_0001226d;
  return;
}


// ===== FUN_fffd405e @ fffd405e (859 bytes)

void FUN_fffd405e(void)

{
  DAT_00012238 = g_opstate.menu_cursor_9a3d[0];
  DAT_00012239 = g_opstate.menu_cursor_9a3d[1];
  DAT_0001223a = g_opstate.menu_cursor_9a50[0];
  DAT_0001223b = g_opstate.menu_cursor_9a50[1];
  DAT_0001223c = g_opstate.menu_cursor_9a65[0];
  DAT_0001223d = g_opstate.menu_cursor_9a65[1];
  DAT_0001223e = g_opstate.menu_cursor_9a7c[0];
  DAT_0001223f = g_opstate.menu_cursor_9a7c[1];
  DAT_00012240 = g_opstate.menu_cursor_9a8f[0];
  DAT_00012241 = g_opstate.menu_cursor_9a8f[1];
  DAT_00012242 = g_opstate.menu_cursor_9aa5[0];
  DAT_00012243 = g_opstate.menu_cursor_9aa5[1];
  DAT_00012244 = g_opstate.menu_cursor_9ab3[0];
  DAT_00012245 = g_opstate.menu_cursor_9ab3[1];
  DAT_00012246 = g_opstate.menu_cursor_9acf[0];
  DAT_00012247 = g_opstate.menu_cursor_9acf[1];
  DAT_00012248 = g_opstate.menu_cursor_9ad7[0];
  DAT_00012249 = g_opstate.menu_cursor_9ad7[1];
  DAT_0001224a = g_opstate.menu_cursor_9aec[0];
  DAT_0001224b = g_opstate.menu_cursor_9aec[1];
  DAT_0001224c = g_opstate.menu_cursor_9af7[0];
  DAT_0001224d = g_opstate.menu_cursor_9af7[1];
  DAT_0001224e = g_opstate.menu_cursor_9aff[0];
  DAT_0001224f = g_opstate.menu_cursor_9aff[1];
  DAT_00012250 = g_opstate.menu_cursor_9b12[0];
  DAT_00012251 = g_opstate.menu_cursor_9b12[1];
  DAT_00012252 = g_opstate.menu_cursor_9b18[0];
  DAT_00012253 = g_opstate.menu_cursor_9b18[1];
  DAT_00012254 = g_opstate.menu_cursor_9b1e[0];
  DAT_00012255 = g_opstate.menu_cursor_9b1e[1];
  DAT_00012256 = g_opstate.menu_cursor_9b22[0];
  DAT_00012257 = g_opstate.menu_cursor_9b22[1];
  DAT_00012258 = g_opstate.menu_cursor_9b24[0];
  DAT_00012259 = g_opstate.menu_cursor_9b24[1];
  DAT_0001225a = g_opstate.menu_cursor_9b26[0];
  DAT_0001225b = g_opstate.menu_cursor_9b26[1];
  DAT_0001225e = g_opstate.menu_cursor_9b28[0];
  DAT_0001225f = g_opstate.menu_cursor_9b28[1];
  DAT_00012260 = g_opstate.menu_cursor_9b2a[0];
  DAT_00012261 = g_opstate.menu_cursor_9b2a[1];
  DAT_00012262 = g_opstate.menu_cursor_9b2c[0];
  DAT_00012263 = g_opstate.menu_cursor_9b2c[1];
  DAT_00012264 = g_opstate.presets[0].menu_cursor[0];
  DAT_00012265 = g_opstate.presets[0].menu_cursor[1];
  DAT_00012266 = g_opstate.presets[1].menu_cursor[0];
  DAT_00012267 = g_opstate.presets[1].menu_cursor[1];
  DAT_00012268 = g_opstate.presets[2].menu_cursor[0];
  DAT_00012269 = g_opstate.presets[2].menu_cursor[1];
  DAT_0001226a = g_opstate.presets[3].menu_cursor[0];
  DAT_0001226b = g_opstate.presets[3].menu_cursor[1];
  DAT_0001226c = g_opstate.presets[4].menu_cursor[0];
  DAT_0001226d = g_opstate.presets[4].menu_cursor[1];
  return;
}


// ===== sd_menu_enter_check @ fffd43b9 (118 bytes)

/* SD CARD action on_enter guard: refuses while +0x93 / +0x92 (PlayList, recording); with no card
   (+0xA6 != 1) shows dialog 2 (arg 1) or 3 and returns 0 with an error beep [fact] */

char sd_menu_enter_check(char param_1)

{
  bool bVar1;
  char local_3;
  
  local_3 = '\x01';
  if (g_ui.playlist_open == 0) {
    if (g_ui.dvs_lm1_flag != 0) {
      local_3 = '\0';
    }
  }
  else {
    local_3 = '\0';
  }
  if ((local_3 == '\0') || (param_1 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (PTR_g_ui_00025d60->sd_present != 1)) {
    local_3 = '\0';
    if (param_1 == '\x01') {
      dialog_insert_fw_sd();
    }
    else {
      dialog_no_sd_card();
    }
  }
  if (local_3 == '\0') {
    beep_request(3);
    FUN_fffc8f30(0);
  }
  return local_3;
}


// ===== menu_register @ fffd442f (377 bytes)

/* Copy a 0x38-byte item descriptor into RAM table 0x2105C[0x15E]; append index to per-P1 list
   0x1FA50+0xC8*P1 (counts 0x1B4F6..FB) */

byte menu_register(byte *desc)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  byte local_6;
  
  if (desc == (byte *)0x0) {
    local_6 = 0;
  }
  else if (DAT_0001fa4e == 0x15e) {
    local_6 = 0;
  }
  else {
    pbVar2 = &DAT_0002105c + (uint)DAT_0001fa4e * 0x38;
    pbVar3 = desc;
    for (iVar4 = 0x38; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pbVar2 = *pbVar3;
      pbVar2 = pbVar2 + 1;
      pbVar3 = pbVar3 + 1;
    }
    bVar1 = desc[3];
    if (bVar1 == 5) {
      *(ushort *)(&DAT_0001fe38 + (uint)DAT_0001b4fb * 2) = DAT_0001fa4e;
      DAT_0001b4fb = DAT_0001b4fb + 1;
    }
    else if (bVar1 == 1) {
      *(ushort *)(&DAT_0001fb18 + (uint)DAT_0001b4f7 * 2) = DAT_0001fa4e;
      DAT_0001b4f7 = DAT_0001b4f7 + 1;
    }
    else if (bVar1 == 2) {
      *(ushort *)(&DAT_0001fbe0 + (uint)DAT_0001b4f8 * 2) = DAT_0001fa4e;
      DAT_0001b4f8 = DAT_0001b4f8 + 1;
    }
    else if (bVar1 == 3) {
      *(ushort *)(&DAT_0001fca8 + (uint)DAT_0001b4f9 * 2) = DAT_0001fa4e;
      DAT_0001b4f9 = DAT_0001b4f9 + 1;
    }
    else if (bVar1 == 4) {
      *(ushort *)(&DAT_0001fd70 + (uint)DAT_0001b4fa * 2) = DAT_0001fa4e;
      DAT_0001b4fa = DAT_0001b4fa + 1;
    }
    else {
      if (bVar1 != 0) {
        return 0;
      }
      *(ushort *)(&DAT_0001fa50 + (uint)DAT_0001b4f6 * 2) = DAT_0001fa4e;
      DAT_0001b4f6 = DAT_0001b4f6 + 1;
    }
    DAT_0001fa4e = DAT_0001fa4e + 1;
    if (0x15e < DAT_0001fa4e) {
      DAT_0001fa4e = 0x15f;
    }
    local_6 = 1;
  }
  return local_6;
}


// ===== menu_group_visible @ fffd45a8 (169 bytes)

/* (P1, global P2): 1 if any item of that group exists for this destination */

byte menu_group_visible(char param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  ushort uStack_6;
  
  bVar2 = menu_dest_mask();
  uStack_6 = 0;
  do {
    if (0x15d < uStack_6) {
      return 0;
    }
    if ((&DAT_0002105c)[(uint)uStack_6 * 0x38] == '\x01') {
      if (((&DAT_0002105f)[(uint)uStack_6 * 0x38] == param_1) &&
         ((&DAT_00021060)[(uint)uStack_6 * 0x38] == param_2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if ((&DAT_0002105d)[(uint)uStack_6 * 0x38] == '\0') {
          return 1;
        }
        if (((&DAT_0002105d)[(uint)uStack_6 * 0x38] & bVar2) != 0) {
          return 1;
        }
      }
    }
    uStack_6 = uStack_6 + 1;
  } while( true );
}


// ===== menu_find @ fffd4651 (324 bytes)

/* key {P1,P2,P3} -> table index via per-P1 list, honours dest_mask (+1); 0xFFFF if none */

ushort menu_find(char *param_1)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  byte bVar4;
  undefined *puStack_10;
  ushort uStack_8;
  
  if (param_1 != (char *)0x0) {
    bVar4 = menu_dest_mask();
    cVar1 = *param_1;
    if (cVar1 == '\x05') {
      puStack_10 = &DAT_0001fe38;
    }
    else if (cVar1 == '\x01') {
      puStack_10 = &DAT_0001fb18;
    }
    else if (cVar1 == '\x02') {
      puStack_10 = &DAT_0001fbe0;
    }
    else if (cVar1 == '\x03') {
      puStack_10 = &DAT_0001fca8;
    }
    else if (cVar1 == '\x04') {
      puStack_10 = &DAT_0001fd70;
    }
    else {
      if (cVar1 != '\0') {
        return 0xffff;
      }
      puStack_10 = &DAT_0001fa50;
    }
    for (uStack_8 = 0; uStack_8 < 100; uStack_8 = uStack_8 + 1) {
      uVar2 = *(ushort *)(puStack_10 + (uint)uStack_8 * 2);
      if ((&DAT_0002105c)[(uint)uVar2 * 0x38] == '\x01') {
        if ((*param_1 == (&DAT_0002105f)[(uint)uVar2 * 0x38]) &&
           (param_1[1] == (&DAT_00021060)[(uint)uVar2 * 0x38])) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if ((bVar3) && (param_1[2] == (&DAT_00021061)[(uint)uVar2 * 0x38])) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          if ((&DAT_0002105d)[(uint)uVar2 * 0x38] == '\0') {
            return uVar2;
          }
          if (((&DAT_0002105d)[(uint)uVar2 * 0x38] & bVar4) != 0) {
            return uVar2;
          }
        }
      }
    }
  }
  return 0xffff;
}


// ===== menu_get_desc @ fffd4795 (85 bytes)

/* key -> copy of the 0x38-byte descriptor */

byte menu_get_desc(char *key,byte *desc)

{
  bool bVar1;
  ushort uVar2;
  byte *pbVar3;
  int iVar4;
  byte local_d;
  
  if ((key == (char *)0x0) || (desc == (byte *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_d = 0;
  }
  else {
    uVar2 = menu_find(key);
    if (uVar2 == 0xffff) {
      local_d = 0;
    }
    else {
      pbVar3 = &DAT_0002105c + (uint)uVar2 * 0x38;
      for (iVar4 = 0x38; iVar4 != 0; iVar4 = iVar4 + -1) {
        *desc = *pbVar3;
        desc = desc + 1;
        pbVar3 = pbVar3 + 1;
      }
      local_d = 1;
    }
  }
  return local_d;
}


// ===== menu_get_name @ fffd47ea (87 bytes)

/* key -> 21-char item name (desc+6) */

byte menu_get_name(char *key,char *name)

{
  bool bVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  byte local_d;
  
  if ((key == (char *)0x0) || (name == (char *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_d = 0;
  }
  else {
    uVar2 = menu_find(key);
    if (uVar2 == 0xffff) {
      local_d = 0;
    }
    else {
      pcVar3 = &DAT_00021062 + (uint)uVar2 * 0x38;
      for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
        *name = *pcVar3;
        name = name + 1;
        pcVar3 = pcVar3 + 1;
      }
      local_d = 1;
    }
  }
  return local_d;
}


// ===== menu_count_items @ fffd4841 (144 bytes)

/* Number of items in global P2 group (dest-filtered) */

char menu_count_items(char param_1)

{
  bool bVar1;
  byte bVar2;
  ushort local_6;
  char local_3;
  
  local_3 = '\0';
  for (local_6 = 0; local_6 < 0x15e; local_6 = local_6 + 1) {
    if (((&DAT_0002105c)[(uint)local_6 * 0x38] == '\x01') &&
       (param_1 == (&DAT_00021060)[(uint)local_6 * 0x38])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if ((&DAT_0002105d)[(uint)local_6 * 0x38] == '\0') {
        local_3 = local_3 + '\x01';
      }
      else {
        bVar2 = menu_dest_mask();
        if (((&DAT_0002105d)[(uint)local_6 * 0x38] & bVar2) != 0) {
          local_3 = local_3 + '\x01';
        }
      }
    }
  }
  return local_3;
}


// ===== menu_count_groups @ fffd48d1 (207 bytes)

/* Number of P2 groups in a P1 group (dest-filtered) */

char menu_count_groups(char param_1)

{
  bool bVar1;
  byte bVar2;
  ushort local_8;
  char local_5;
  char local_3;
  
  local_3 = '\0';
  local_5 = -1;
  for (local_8 = 0; local_8 < 0x15e; local_8 = local_8 + 1) {
    if (((&DAT_0002105c)[(uint)local_8 * 0x38] == '\x01') &&
       (param_1 == (&DAT_0002105f)[(uint)local_8 * 0x38])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (local_5 != (&DAT_00021060)[(uint)local_8 * 0x38])) {
      if ((&DAT_0002105d)[(uint)local_8 * 0x38] == '\0') {
        local_3 = local_3 + '\x01';
        local_5 = (&DAT_00021060)[(uint)local_8 * 0x38];
      }
      else {
        bVar2 = menu_dest_mask();
        if (((&DAT_0002105d)[(uint)local_8 * 0x38] & bVar2) != 0) {
          local_3 = local_3 + '\x01';
          local_5 = (&DAT_00021060)[(uint)local_8 * 0x38];
        }
      }
    }
  }
  return local_3;
}


// ===== menu_call_draw @ fffd49a0 (32 bytes)

/* key, buf -> desc.on_draw(buf) (+0x1C): encode value for the DISPLAY menu page */

void menu_call_draw(uint param_1,uint param_2)

{
  byte bVar1;
  byte abStack_40 [28];
  code *pcStack_24;
  uint local_8;
  uint local_4;
  
  local_8 = param_2;
  local_4 = param_1;
  bVar1 = menu_get_desc((char *)param_1,abStack_40);
  if (bVar1 != 1) {
    return;
  }
  (*pcStack_24)(local_8,pcStack_24);
  return;
}


// ===== menu_call_step @ fffd49c0 (26 bytes)

/* key -> desc.on_step() (+0x20): dial step, or apply hook when 0x15DFC=1 (CAT) */

void menu_call_step(uint param_1)

{
  byte bVar1;
  byte abStack_3c [32];
  code *pcStack_1c;
  uint local_4;
  
  local_4 = param_1;
  bVar1 = menu_get_desc((char *)param_1,abStack_3c);
  if (bVar1 != 1) {
    return;
  }
  (*pcStack_1c)(pcStack_1c);
  return;
}


// ===== menu_call_enter @ fffd49da (26 bytes)

/* key -> desc.on_enter() (+0x24): action items (SD card, reset, calibration...) */

void menu_call_enter(uint param_1)

{
  byte bVar1;
  byte abStack_3c [36];
  code *pcStack_18;
  uint local_4;
  
  local_4 = param_1;
  bVar1 = menu_get_desc((char *)param_1,abStack_3c);
  if (bVar1 != 1) {
    return;
  }
  (*pcStack_18)(pcStack_18);
  return;
}

