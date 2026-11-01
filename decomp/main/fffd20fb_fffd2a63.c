// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex060505_draw @ fffd20fb (13 bytes)

/* Menu item ex060505 AGC FAST DELAY: on_draw (#74) */

void menu_ex060505_draw(void)

{
  menu_draw_preset_agc_fast(5);
  return;
}


// ===== menu_draw_preset_agc_fast @ fffd2108 (240 bytes)

/* PRESET n AGC FAST DELAY row [fact] */

void menu_draw_preset_agc_fast(byte param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
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
    local_b = g_opstate.presets[4].agc_fast_delay;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].agc_fast_delay;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].agc_fast_delay;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].agc_fast_delay;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].agc_fast_delay;
  }
  if (local_b == 7) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xe;
  param_2[2] = 0;
  bVar2 = dec_to_str_u16((ushort)local_b * 0x14 + 0x14,param_2 + 0x18);
  param_2 = param_2 + bVar2 + 0x18;
  param_2[0] = 0x6d;
  param_2[1] = 0x73;
  param_2[2] = 0x65;
  param_2[3] = 99;
  return;
}


// ===== menu_ex060106_draw @ fffd21f8 (13 bytes)

/* Menu item ex060106 AGC MID DELAY: on_draw (#74) */

void menu_ex060106_draw(void)

{
  menu_draw_preset_agc_mid(1);
  return;
}


// ===== menu_ex060206_draw @ fffd2205 (13 bytes)

/* Menu item ex060206 AGC MID DELAY: on_draw (#74) */

void menu_ex060206_draw(void)

{
  menu_draw_preset_agc_mid(2);
  return;
}


// ===== menu_ex060306_draw @ fffd2212 (13 bytes)

/* Menu item ex060306 AGC MID DELAY: on_draw (#74) */

void menu_ex060306_draw(void)

{
  menu_draw_preset_agc_mid(3);
  return;
}


// ===== menu_ex060406_draw @ fffd221f (13 bytes)

/* Menu item ex060406 AGC MID DELAY: on_draw (#74) */

void menu_ex060406_draw(void)

{
  menu_draw_preset_agc_mid(4);
  return;
}


// ===== menu_ex060506_draw @ fffd222c (13 bytes)

/* Menu item ex060506 AGC MID DELAY: on_draw (#74) */

void menu_ex060506_draw(void)

{
  menu_draw_preset_agc_mid(5);
  return;
}


// ===== menu_draw_preset_agc_mid @ fffd2239 (241 bytes)

/* PRESET n AGC MID DELAY row [fact] */

void menu_draw_preset_agc_mid(byte param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
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
    local_b = g_opstate.presets[4].agc_mid_delay;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].agc_mid_delay;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].agc_mid_delay;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].agc_mid_delay;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].agc_mid_delay;
  }
  if (local_b == 0x18) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xd;
  param_2[2] = 0;
  bVar2 = dec_to_str_u16((ushort)local_b * 0x14 + 0x14,param_2 + 0x18);
  param_2 = param_2 + bVar2 + 0x18;
  param_2[0] = 0x6d;
  param_2[1] = 0x73;
  param_2[2] = 0x65;
  param_2[3] = 99;
  return;
}


// ===== menu_ex060107_draw @ fffd232a (13 bytes)

/* Menu item ex060107 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060107_draw(void)

{
  menu_draw_preset_agc_slow(1);
  return;
}


// ===== menu_ex060207_draw @ fffd2337 (13 bytes)

/* Menu item ex060207 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060207_draw(void)

{
  menu_draw_preset_agc_slow(2);
  return;
}


// ===== menu_ex060307_draw @ fffd2344 (13 bytes)

/* Menu item ex060307 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060307_draw(void)

{
  menu_draw_preset_agc_slow(3);
  return;
}


// ===== menu_ex060407_draw @ fffd2351 (13 bytes)

/* Menu item ex060407 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060407_draw(void)

{
  menu_draw_preset_agc_slow(4);
  return;
}


// ===== menu_ex060507_draw @ fffd235e (13 bytes)

/* Menu item ex060507 AGC SLOW DELAY: on_draw (#74) */

void menu_ex060507_draw(void)

{
  menu_draw_preset_agc_slow(5);
  return;
}


// ===== menu_draw_preset_agc_slow @ fffd236b (241 bytes)

/* PRESET n AGC SLOW DELAY row [fact] */

void menu_draw_preset_agc_slow(byte param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
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
    local_b = g_opstate.presets[4].agc_slow_delay;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].agc_slow_delay;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].agc_slow_delay;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].agc_slow_delay;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].agc_slow_delay;
  }
  if (local_b == 0x4a) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xe;
  param_2[2] = 0;
  bVar2 = dec_to_str_u16((ushort)local_b * 0x14 + 0x14,param_2 + 0x18);
  param_2 = param_2 + bVar2 + 0x18;
  param_2[0] = 0x6d;
  param_2[1] = 0x73;
  param_2[2] = 0x65;
  param_2[3] = 99;
  return;
}


// ===== menu_ex060108_draw @ fffd245c (13 bytes)

/* Menu item ex060108 LCUT FREQ: on_draw (#74) */

void menu_ex060108_draw(void)

{
  menu_draw_preset_lcut_freq(1);
  return;
}


// ===== menu_ex060208_draw @ fffd2469 (13 bytes)

/* Menu item ex060208 LCUT FREQ: on_draw (#74) */

void menu_ex060208_draw(void)

{
  menu_draw_preset_lcut_freq(2);
  return;
}


// ===== menu_ex060308_draw @ fffd2476 (13 bytes)

/* Menu item ex060308 LCUT FREQ: on_draw (#74) */

void menu_ex060308_draw(void)

{
  menu_draw_preset_lcut_freq(3);
  return;
}


// ===== menu_ex060408_draw @ fffd2483 (13 bytes)

/* Menu item ex060408 LCUT FREQ: on_draw (#74) */

void menu_ex060408_draw(void)

{
  menu_draw_preset_lcut_freq(4);
  return;
}


// ===== menu_ex060508_draw @ fffd2490 (13 bytes)

/* Menu item ex060508 LCUT FREQ: on_draw (#74) */

void menu_ex060508_draw(void)

{
  menu_draw_preset_lcut_freq(5);
  return;
}


// ===== menu_draw_preset_lcut_freq @ fffd249d (235 bytes)

/* PRESET n LCUT FREQ row: OFF / 100Hz / 150Hz .. (ROM 0xFFF8509B) [fact] */

void menu_draw_preset_lcut_freq(byte param_1,byte *param_2)

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
    local_b = g_opstate.presets[4].lcut_freq;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].lcut_freq;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].lcut_freq;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].lcut_freq;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].lcut_freq;
  }
  if (local_b == 1) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 9;
  param_2[2] = 0;
  if (0x13 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x1b87);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060109_draw @ fffd2588 (13 bytes)

/* Menu item ex060109 LCUT SLOPE: on_draw (#74) */

void menu_ex060109_draw(void)

{
  menu_draw_preset_lcut_slope(1);
  return;
}


// ===== menu_ex060209_draw @ fffd2595 (13 bytes)

/* Menu item ex060209 LCUT SLOPE: on_draw (#74) */

void menu_ex060209_draw(void)

{
  menu_draw_preset_lcut_slope(2);
  return;
}


// ===== menu_ex060309_draw @ fffd25a2 (13 bytes)

/* Menu item ex060309 LCUT SLOPE: on_draw (#74) */

void menu_ex060309_draw(void)

{
  menu_draw_preset_lcut_slope(3);
  return;
}


// ===== menu_ex060409_draw @ fffd25af (13 bytes)

/* Menu item ex060409 LCUT SLOPE: on_draw (#74) */

void menu_ex060409_draw(void)

{
  menu_draw_preset_lcut_slope(4);
  return;
}


// ===== menu_ex060509_draw @ fffd25bc (13 bytes)

/* Menu item ex060509 LCUT SLOPE: on_draw (#74) */

void menu_ex060509_draw(void)

{
  menu_draw_preset_lcut_slope(5);
  return;
}


// ===== menu_draw_preset_lcut_slope @ fffd25c9 (234 bytes)

/* PRESET n lcut_slope row (EX060n09): called by menu_ex06{01..05}09_draw with n = 1..5, reads
   g_opstate.presets[n-1].lcut_slope, sets the default flag 0x80, writes the value text at +0x18
   [fact: fffd25c9] */

void menu_draw_preset_lcut_slope(byte param_1,byte *param_2)

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
    local_b = g_opstate.presets[4].lcut_slope;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].lcut_slope;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].lcut_slope;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].lcut_slope;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].lcut_slope;
  }
  if (local_b == 1) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 10;
  param_2[2] = 0;
  if (1 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x1d7);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060110_draw @ fffd26b3 (13 bytes)

/* Menu item ex060110 HCUT FREQ: on_draw (#74) */

void menu_ex060110_draw(void)

{
  menu_draw_preset_hcut_freq(1);
  return;
}


// ===== menu_ex060210_draw @ fffd26c0 (13 bytes)

/* Menu item ex060210 HCUT FREQ: on_draw (#74) */

void menu_ex060210_draw(void)

{
  menu_draw_preset_hcut_freq(2);
  return;
}


// ===== menu_ex060310_draw @ fffd26cd (13 bytes)

/* Menu item ex060310 HCUT FREQ: on_draw (#74) */

void menu_ex060310_draw(void)

{
  menu_draw_preset_hcut_freq(3);
  return;
}


// ===== menu_ex060410_draw @ fffd26da (13 bytes)

/* Menu item ex060410 HCUT FREQ: on_draw (#74) */

void menu_ex060410_draw(void)

{
  menu_draw_preset_hcut_freq(4);
  return;
}


// ===== menu_ex060510_draw @ fffd26e7 (13 bytes)

/* Menu item ex060510 HCUT FREQ: on_draw (#74) */

void menu_ex060510_draw(void)

{
  menu_draw_preset_hcut_freq(5);
  return;
}


// ===== menu_draw_preset_hcut_freq @ fffd26f4 (236 bytes)

/* PRESET n hcut_freq row (EX060n10): called by menu_ex06{01..05}10_draw with n = 1..5, reads
   g_opstate.presets[n-1].hcut_freq, sets the default flag 0x80, writes the value text at +0x18
   [fact: fffd26f4] */

void menu_draw_preset_hcut_freq(byte param_1,byte *param_2)

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
    local_b = g_opstate.presets[4].hcut_freq;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].hcut_freq;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].hcut_freq;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].hcut_freq;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].hcut_freq;
  }
  if (local_b == 0x33) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 9;
  param_2[2] = 0;
  if (0x43 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x1d2b);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060111_draw @ fffd27e0 (13 bytes)

/* Menu item ex060111 HCUT SLOPE: on_draw (#74) */

void menu_ex060111_draw(void)

{
  menu_draw_preset_hcut_slope(1);
  return;
}


// ===== menu_ex060211_draw @ fffd27ed (13 bytes)

/* Menu item ex060211 HCUT SLOPE: on_draw (#74) */

void menu_ex060211_draw(void)

{
  menu_draw_preset_hcut_slope(2);
  return;
}


// ===== menu_ex060311_draw @ fffd27fa (13 bytes)

/* Menu item ex060311 HCUT SLOPE: on_draw (#74) */

void menu_ex060311_draw(void)

{
  menu_draw_preset_hcut_slope(3);
  return;
}


// ===== menu_ex060411_draw @ fffd2807 (13 bytes)

/* Menu item ex060411 HCUT SLOPE: on_draw (#74) */

void menu_ex060411_draw(void)

{
  menu_draw_preset_hcut_slope(4);
  return;
}


// ===== menu_ex060511_draw @ fffd2814 (13 bytes)

/* Menu item ex060511 HCUT SLOPE: on_draw (#74) */

void menu_ex060511_draw(void)

{
  menu_draw_preset_hcut_slope(5);
  return;
}


// ===== menu_draw_preset_hcut_slope @ fffd2821 (234 bytes)

/* PRESET n hcut_slope row (EX060n11): called by menu_ex06{01..05}11_draw with n = 1..5, reads
   g_opstate.presets[n-1].hcut_slope, sets the default flag 0x80, writes the value text at +0x18
   [fact: fffd2821] */

void menu_draw_preset_hcut_slope(byte param_1,byte *param_2)

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
    local_b = g_opstate.presets[4].hcut_slope;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].hcut_slope;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].hcut_slope;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].hcut_slope;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].hcut_slope;
  }
  if (local_b == 1) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 10;
  param_2[2] = 0;
  if (1 < local_b) {
    local_b = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_b * 0x15 + 0x1d7);
  param_2 = param_2 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_2 = *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex060112_draw @ fffd290b (13 bytes)

/* Menu item ex060112 USB OUT LEVEL: on_draw (#74) */

void menu_ex060112_draw(void)

{
  menu_draw_preset_usb_out_level(1);
  return;
}


// ===== menu_ex060212_draw @ fffd2918 (13 bytes)

/* Menu item ex060212 USB OUT LEVEL: on_draw (#74) */

void menu_ex060212_draw(void)

{
  menu_draw_preset_usb_out_level(2);
  return;
}


// ===== menu_ex060312_draw @ fffd2925 (13 bytes)

/* Menu item ex060312 USB OUT LEVEL: on_draw (#74) */

void menu_ex060312_draw(void)

{
  menu_draw_preset_usb_out_level(3);
  return;
}


// ===== menu_ex060412_draw @ fffd2932 (13 bytes)

/* Menu item ex060412 USB OUT LEVEL: on_draw (#74) */

void menu_ex060412_draw(void)

{
  menu_draw_preset_usb_out_level(4);
  return;
}


// ===== menu_ex060512_draw @ fffd293f (13 bytes)

/* Menu item ex060512 USB OUT LEVEL: on_draw (#74) */

void menu_ex060512_draw(void)

{
  menu_draw_preset_usb_out_level(5);
  return;
}


// ===== menu_draw_preset_usb_out_level @ fffd294c (214 bytes)

/* PRESET n usb_out_level row (EX060n12): called by menu_ex06{01..05}12_draw with n = 1..5, reads
   g_opstate.presets[n-1].usb_out_level, sets the default flag 0x80, writes the value text at +0x18
   [fact: fffd294c] */

void menu_draw_preset_usb_out_level(byte param_1,byte *param_2)

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
    local_b = g_opstate.presets[4].usb_out_level;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].usb_out_level;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].usb_out_level;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].usb_out_level;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].usb_out_level;
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


// ===== menu_ex060113_draw @ fffd2a22 (13 bytes)

/* Menu item ex060113 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060113_draw(void)

{
  menu_draw_preset_rear_out_level(1);
  return;
}


// ===== menu_ex060213_draw @ fffd2a2f (13 bytes)

/* Menu item ex060213 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060213_draw(void)

{
  menu_draw_preset_rear_out_level(2);
  return;
}


// ===== menu_ex060313_draw @ fffd2a3c (13 bytes)

/* Menu item ex060313 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060313_draw(void)

{
  menu_draw_preset_rear_out_level(3);
  return;
}


// ===== menu_ex060413_draw @ fffd2a49 (13 bytes)

/* Menu item ex060413 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060413_draw(void)

{
  menu_draw_preset_rear_out_level(4);
  return;
}


// ===== menu_ex060513_draw @ fffd2a56 (13 bytes)

/* Menu item ex060513 REAR OUT LEVEL: on_draw (#74) */

void menu_ex060513_draw(void)

{
  menu_draw_preset_rear_out_level(5);
  return;
}


// ===== menu_draw_preset_rear_out_level @ fffd2a63 (214 bytes)

/* PRESET n rear_out_level row (EX060n13): called by menu_ex06{01..05}13_draw with n = 1..5, reads
   g_opstate.presets[n-1].rear_out_level, sets the default flag 0x80, writes the value text at +0x18
   [fact: fffd2a63] */

void menu_draw_preset_rear_out_level(byte param_1,byte *param_2)

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
    local_b = g_opstate.presets[4].rear_out_level;
  }
  else if (param_1 == 2) {
    local_b = g_opstate.presets[1].rear_out_level;
  }
  else if (param_1 == 3) {
    local_b = g_opstate.presets[2].rear_out_level;
  }
  else if (param_1 == 4) {
    local_b = g_opstate.presets[3].rear_out_level;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = g_opstate.presets[0].rear_out_level;
  }
  if (local_b == 0x32) {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xe;
  param_2[2] = 0;
  dec_to_str_u8(local_b,param_2 + 0x18);
  return;
}

