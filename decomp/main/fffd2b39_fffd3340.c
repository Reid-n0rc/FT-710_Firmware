// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex060114_draw @ fffd2b39 (13 bytes)

/* Menu item ex060114 TX BPF SEL: on_draw (#74) */

void menu_ex060114_draw(void)

{
  FUN_fffd2b7a(1);
  return;
}


// ===== menu_ex060214_draw @ fffd2b46 (13 bytes)

/* Menu item ex060214 TX BPF SEL: on_draw (#74) */

void menu_ex060214_draw(void)

{
  FUN_fffd2b7a(2);
  return;
}


// ===== menu_ex060314_draw @ fffd2b53 (13 bytes)

/* Menu item ex060314 TX BPF SEL: on_draw (#74) */

void menu_ex060314_draw(void)

{
  FUN_fffd2b7a(3);
  return;
}


// ===== menu_ex060414_draw @ fffd2b60 (13 bytes)

/* Menu item ex060414 TX BPF SEL: on_draw (#74) */

void menu_ex060414_draw(void)

{
  FUN_fffd2b7a(4);
  return;
}


// ===== menu_ex060514_draw @ fffd2b6d (13 bytes)

/* Menu item ex060514 TX BPF SEL: on_draw (#74) */

void menu_ex060514_draw(void)

{
  FUN_fffd2b7a(5);
  return;
}


// ===== FUN_fffd2b7a @ fffd2b7a (234 bytes)

void FUN_fffd2b7a(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
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
    local_b = g_opstate.presets[4].tx_bpf_sel;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].tx_bpf_sel;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].tx_bpf_sel;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].tx_bpf_sel;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].tx_bpf_sel;
  }
  if (local_b == 0) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 10;
  param_2[2] = 0;
  if (4 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x22bf);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060115_draw @ fffd2c64 (13 bytes)

/* Menu item ex060115 MOD SOURCE: on_draw (#74) */

void menu_ex060115_draw(void)

{
  FUN_fffd2ca5(1);
  return;
}


// ===== menu_ex060215_draw @ fffd2c71 (13 bytes)

/* Menu item ex060215 MOD SOURCE: on_draw (#74) */

void menu_ex060215_draw(void)

{
  FUN_fffd2ca5(2);
  return;
}


// ===== menu_ex060315_draw @ fffd2c7e (13 bytes)

/* Menu item ex060315 MOD SOURCE: on_draw (#74) */

void menu_ex060315_draw(void)

{
  FUN_fffd2ca5(3);
  return;
}


// ===== menu_ex060415_draw @ fffd2c8b (13 bytes)

/* Menu item ex060415 MOD SOURCE: on_draw (#74) */

void menu_ex060415_draw(void)

{
  FUN_fffd2ca5(4);
  return;
}


// ===== menu_ex060515_draw @ fffd2c98 (13 bytes)

/* Menu item ex060515 MOD SOURCE: on_draw (#74) */

void menu_ex060515_draw(void)

{
  FUN_fffd2ca5(5);
  return;
}


// ===== FUN_fffd2ca5 @ fffd2ca5 (234 bytes)

void FUN_fffd2ca5(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
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
    local_b = g_opstate.presets[4].mod_source;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].mod_source;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].mod_source;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].mod_source;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].mod_source;
  }
  if (local_b == 3) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 10;
  param_2[2] = 0;
  if (3 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x2e8);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060116_draw @ fffd2d8f (13 bytes)

/* Menu item ex060116 USB MOD GAIN: on_draw (#74) */

void menu_ex060116_draw(void)

{
  FUN_fffd2dd0(1);
  return;
}


// ===== menu_ex060216_draw @ fffd2d9c (13 bytes)

/* Menu item ex060216 USB MOD GAIN: on_draw (#74) */

void menu_ex060216_draw(void)

{
  FUN_fffd2dd0(2);
  return;
}


// ===== menu_ex060316_draw @ fffd2da9 (13 bytes)

/* Menu item ex060316 USB MOD GAIN: on_draw (#74) */

void menu_ex060316_draw(void)

{
  FUN_fffd2dd0(3);
  return;
}


// ===== menu_ex060416_draw @ fffd2db6 (13 bytes)

/* Menu item ex060416 USB MOD GAIN: on_draw (#74) */

void menu_ex060416_draw(void)

{
  FUN_fffd2dd0(4);
  return;
}


// ===== menu_ex060516_draw @ fffd2dc3 (13 bytes)

/* Menu item ex060516 USB MOD GAIN: on_draw (#74) */

void menu_ex060516_draw(void)

{
  FUN_fffd2dd0(5);
  return;
}


// ===== FUN_fffd2dd0 @ fffd2dd0 (214 bytes)

void FUN_fffd2dd0(byte param_1,byte *param_2)

{
  bool bVar1;
  byte local_b;
  
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
    local_b = g_opstate.presets[4].usb_mod_gain;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].usb_mod_gain;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].usb_mod_gain;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].usb_mod_gain;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].usb_mod_gain;
  }
  if (local_b == 0x32) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xc;
  param_2[2] = 0;
  dec_to_str_u8(local_b,param_2 + 0x18);
  return;
}


// ===== menu_ex060117_draw @ fffd2ea6 (13 bytes)

/* Menu item ex060117 REAR MOD GAIN: on_draw (#74) */

void menu_ex060117_draw(void)

{
  FUN_fffd2ee7(1);
  return;
}


// ===== menu_ex060217_draw @ fffd2eb3 (13 bytes)

/* Menu item ex060217 REAR MOD GAIN: on_draw (#74) */

void menu_ex060217_draw(void)

{
  FUN_fffd2ee7(2);
  return;
}


// ===== menu_ex060317_draw @ fffd2ec0 (13 bytes)

/* Menu item ex060317 REAR MOD GAIN: on_draw (#74) */

void menu_ex060317_draw(void)

{
  FUN_fffd2ee7(3);
  return;
}


// ===== menu_ex060417_draw @ fffd2ecd (13 bytes)

/* Menu item ex060417 REAR MOD GAIN: on_draw (#74) */

void menu_ex060417_draw(void)

{
  FUN_fffd2ee7(4);
  return;
}


// ===== menu_ex060517_draw @ fffd2eda (13 bytes)

/* Menu item ex060517 REAR MOD GAIN: on_draw (#74) */

void menu_ex060517_draw(void)

{
  FUN_fffd2ee7(5);
  return;
}


// ===== FUN_fffd2ee7 @ fffd2ee7 (214 bytes)

void FUN_fffd2ee7(byte param_1,byte *param_2)

{
  bool bVar1;
  byte local_b;
  
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
    local_b = g_opstate.presets[4].rear_mod_gain;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].rear_mod_gain;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].rear_mod_gain;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].rear_mod_gain;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].rear_mod_gain;
  }
  if (local_b == 0x32) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xd;
  param_2[2] = 0;
  dec_to_str_u8(local_b,param_2 + 0x18);
  return;
}


// ===== menu_ex060118_draw @ fffd2fbd (13 bytes)

/* Menu item ex060118 RPTT SELECT: on_draw (#74) */

void menu_ex060118_draw(void)

{
  FUN_fffd2ffe(1);
  return;
}


// ===== menu_ex060218_draw @ fffd2fca (13 bytes)

/* Menu item ex060218 RPTT SELECT: on_draw (#74) */

void menu_ex060218_draw(void)

{
  FUN_fffd2ffe(2);
  return;
}


// ===== menu_ex060318_draw @ fffd2fd7 (13 bytes)

/* Menu item ex060318 RPTT SELECT: on_draw (#74) */

void menu_ex060318_draw(void)

{
  FUN_fffd2ffe(3);
  return;
}


// ===== menu_ex060418_draw @ fffd2fe4 (13 bytes)

/* Menu item ex060418 RPTT SELECT: on_draw (#74) */

void menu_ex060418_draw(void)

{
  FUN_fffd2ffe(4);
  return;
}


// ===== menu_ex060518_draw @ fffd2ff1 (13 bytes)

/* Menu item ex060518 RPTT SELECT: on_draw (#74) */

void menu_ex060518_draw(void)

{
  FUN_fffd2ffe(5);
  return;
}


// ===== FUN_fffd2ffe @ fffd2ffe (234 bytes)

void FUN_fffd2ffe(byte param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_b;
  
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
    local_b = g_opstate.presets[4].rptt_select;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].rptt_select;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].rptt_select;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].rptt_select;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].rptt_select;
  }
  if (local_b == 1) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xb;
  param_2[2] = 0;
  if (3 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x33c);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== FUN_fffd30e8 @ fffd30e8 (138 bytes)

uint FUN_fffd30e8(void)

{
  char cVar1;
  uint uStack_8;
  
  cVar1 = menu_p2_global(PTR_g_ui_00025d60->menu_p1,PTR_g_ui_00025d60->menu_p2);
  if (cVar1 == '\x1a') {
    uStack_8 = 0x9baa;
  }
  else if (cVar1 == '\x17') {
    uStack_8 = 0x9b4d;
  }
  else if (cVar1 == '\x18') {
    uStack_8 = 0x9b6c;
  }
  else if (cVar1 == '\x19') {
    uStack_8 = 0x9b8b;
  }
  else if (cVar1 == '\x16') {
    uStack_8 = 0x9b2e;
  }
  else {
    uStack_8 = 0x9b2e;
  }
  return uStack_8;
}


// ===== menu_ex060101_enter @ fffd3172 (113 bytes)

/* Menu item ex060101 PRESET NAME: on_enter; also ex060201, ex060301, ex060401, ex060501 (#74) */

void menu_ex060101_enter(void)

{
  ui_state *puVar1;
  ui_state *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)FUN_fffd30e8();
  PTR_g_ui_00025d60->kbd_open = 1;
  PTR_g_ui_00025d60->kbd_target = 6;
  PTR_g_ui_00025d60->kbd_cursor = 0;
  puVar1 = PTR_g_ui_00025d60;
  *(byte *)((int)(puVar1->msg_text + 0) + 8) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 9) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 10) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 0xb) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 4) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 5) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 6) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 7) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 0) = 0x20;
  puVar2 = PTR_g_ui_00025d60;
  *(byte *)((int)(puVar1->msg_text + 0) + 1) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 2) = 0x20;
  *(byte *)((int)(puVar1->msg_text + 0) + 3) = 0x20;
  *(undefined4 *)(PTR_g_ui_00025d60->msg_text[0] + 8) = puVar3[2];
  *(undefined4 *)(puVar2->msg_text[0] + 4) = puVar3[1];
  *(undefined4 *)puVar2->msg_text[0] = *puVar3;
  beep_request(1);
  return;
}


// ===== menu_step_nop @ fffd31e3 (1 bytes)

/* Empty menu on_step (RTS), shared by 18 items (#74) */

void menu_step_nop(void)

{
  return;
}


// ===== menu_ex060102_step @ fffd31e4 (6 bytes)

/* Menu item ex060102 CAT-1 RATE: on_step (#74) */

void menu_ex060102_step(void)

{
  FUN_fffd3202(1);
  return;
}


// ===== menu_ex060202_step @ fffd31ea (6 bytes)

/* Menu item ex060202 CAT-1 RATE: on_step (#74) */

void menu_ex060202_step(void)

{
  FUN_fffd3202(2);
  return;
}


// ===== menu_ex060302_step @ fffd31f0 (6 bytes)

/* Menu item ex060302 CAT-1 RATE: on_step (#74) */

void menu_ex060302_step(void)

{
  FUN_fffd3202(3);
  return;
}


// ===== menu_ex060402_step @ fffd31f6 (6 bytes)

/* Menu item ex060402 CAT-1 RATE: on_step (#74) */

void menu_ex060402_step(void)

{
  FUN_fffd3202(4);
  return;
}


// ===== menu_ex060502_step @ fffd31fc (6 bytes)

/* Menu item ex060502 CAT-1 RATE: on_step (#74) */

void menu_ex060502_step(void)

{
  FUN_fffd3202(5);
  return;
}


// ===== FUN_fffd3202 @ fffd3202 (132 bytes)

void FUN_fffd3202(byte param_1)

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
    local_8 = &g_opstate.presets[4].cat1_rate;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].cat1_rate;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].cat1_rate;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].cat1_rate;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].cat1_rate;
  }
  menu_step_u8(0,4,local_8);
  return;
}


// ===== menu_ex060103_step @ fffd3286 (6 bytes)

/* Menu item ex060103 CAT-1 TIME OUT TIMER: on_step (#74) */

void menu_ex060103_step(void)

{
  FUN_fffd32a4(1);
  return;
}


// ===== menu_ex060203_step @ fffd328c (6 bytes)

/* Menu item ex060203 CAT-1 TIME OUT TIMER: on_step (#74) */

void menu_ex060203_step(void)

{
  FUN_fffd32a4(2);
  return;
}


// ===== menu_ex060303_step @ fffd3292 (6 bytes)

/* Menu item ex060303 CAT-1 TIME OUT TIMER: on_step (#74) */

void menu_ex060303_step(void)

{
  FUN_fffd32a4(3);
  return;
}


// ===== menu_ex060403_step @ fffd3298 (6 bytes)

/* Menu item ex060403 CAT-1 TIME OUT TIMER: on_step (#74) */

void menu_ex060403_step(void)

{
  FUN_fffd32a4(4);
  return;
}


// ===== menu_ex060503_step @ fffd329e (6 bytes)

/* Menu item ex060503 CAT-1 TIME OUT TIMER: on_step (#74) */

void menu_ex060503_step(void)

{
  FUN_fffd32a4(5);
  return;
}


// ===== FUN_fffd32a4 @ fffd32a4 (132 bytes)

void FUN_fffd32a4(byte param_1)

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
    local_8 = &g_opstate.presets[4].cat1_tot;
  }
  else if (param_1 == 2) {
    local_8 = &g_opstate.presets[1].cat1_tot;
  }
  else if (param_1 == 3) {
    local_8 = &g_opstate.presets[2].cat1_tot;
  }
  else if (param_1 == 4) {
    local_8 = &g_opstate.presets[3].cat1_tot;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &g_opstate.presets[0].cat1_tot;
  }
  menu_step_u8(0,3,local_8);
  return;
}


// ===== menu_ex060104_step @ fffd3328 (6 bytes)

/* Menu item ex060104 CAT-1 CAT-3 STOP BIT: on_step (#74) */

void menu_ex060104_step(void)

{
  FUN_fffd3346(1);
  return;
}


// ===== menu_ex060204_step @ fffd332e (6 bytes)

/* Menu item ex060204 CAT-1 CAT-3 STOP BIT: on_step (#74) */

void menu_ex060204_step(void)

{
  FUN_fffd3346(2);
  return;
}


// ===== menu_ex060304_step @ fffd3334 (6 bytes)

/* Menu item ex060304 CAT-1 CAT-3 STOP BIT: on_step (#74) */

void menu_ex060304_step(void)

{
  FUN_fffd3346(3);
  return;
}


// ===== menu_ex060404_step @ fffd333a (6 bytes)

/* Menu item ex060404 CAT-1 CAT-3 STOP BIT: on_step (#74) */

void menu_ex060404_step(void)

{
  FUN_fffd3346(4);
  return;
}


// ===== menu_ex060504_step @ fffd3340 (6 bytes)

/* Menu item ex060504 CAT-1 CAT-3 STOP BIT: on_step (#74) */

void menu_ex060504_step(void)

{
  FUN_fffd3346(5);
  return;
}

