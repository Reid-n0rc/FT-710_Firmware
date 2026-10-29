// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex010513_draw @ fffcae56 (21 bytes)

/* Menu item ex010513 RPTT SELECT: on_draw (#74) */

void menu_ex010513_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_rptt_select(param_1,g_opstate.ex010513_rptt_select,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010514_draw @ fffcae6b (21 bytes)

/* Menu item ex010514 NAR WIDTH: on_draw (#74) */

void menu_ex010514_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcabc2(param_1,g_opstate.ex010514_nar_width,5,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010515_draw @ fffcae80 (125 bytes)

/* Menu item ex010515 MARK FREQUENCY: on_draw (#74) */

void menu_ex010515_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex010515_mark_frequency;
  local_5 = g_opstate.ex010515_mark_frequency;
  if (g_opstate.ex010515_mark_frequency == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xc42);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex010516_draw @ fffcaefd (125 bytes)

/* Menu item ex010516 SHIFT FREQUENCY: on_draw (#74) */

void menu_ex010516_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex010516_shift_frequency;
  local_5 = g_opstate.ex010516_shift_frequency;
  if (g_opstate.ex010516_shift_frequency == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xc6c);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex010517_draw @ fffcaf7a (125 bytes)

/* Menu item ex010517 POLARITY TX: on_draw (#74) */

void menu_ex010517_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex010517_polarity_tx;
  local_5 = g_opstate.ex010517_polarity_tx;
  if (g_opstate.ex010517_polarity_tx == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xcc0);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020101_draw @ fffcaff7 (24 bytes)

/* Menu item ex020101 AF TREBLE GAIN: on_draw (#74) */

void menu_ex020101_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex020101_af_treble_gain);
  return;
}


// ===== menu_ex020102_draw @ fffcb00f (24 bytes)

/* Menu item ex020102 AF MIDDLE TONE GAIN: on_draw (#74) */

void menu_ex020102_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex020102_af_middle_tone_gain);
  return;
}


// ===== menu_ex020103_draw @ fffcb027 (24 bytes)

/* Menu item ex020103 AF BASS GAIN: on_draw (#74) */

void menu_ex020103_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex020103_af_bass_gain);
  return;
}


// ===== menu_ex020104_draw @ fffcb03f (22 bytes)

/* Menu item ex020104 AGC FAST DELAY: on_draw (#74) */

void menu_ex020104_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex020104_agc_fast_delay,0xa0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020105_draw @ fffcb055 (23 bytes)

/* Menu item ex020105 AGC MID DELAY: on_draw (#74) */

void menu_ex020105_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex020105_agc_mid_delay,500,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020106_draw @ fffcb06c (23 bytes)

/* Menu item ex020106 AGC SLOW DELAY: on_draw (#74) */

void menu_ex020106_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex020106_agc_slow_delay,0x5dc,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020107_draw @ fffcb083 (21 bytes)

/* Menu item ex020107 LCUT FREQ: on_draw (#74) */

void menu_ex020107_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_lcut_freq(param_1,g_opstate.ex020107_lcut_freq,4,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020108_draw @ fffcb098 (21 bytes)

/* Menu item ex020108 LCUT SLOPE: on_draw (#74) */

void menu_ex020108_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_lcut_slope(param_1,g_opstate.ex020108_lcut_slope,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020109_draw @ fffcb0ad (21 bytes)

/* Menu item ex020109 HCUT FREQ: on_draw (#74) */

void menu_ex020109_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_hcut_freq(param_1,g_opstate.ex020109_hcut_freq,0xb,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020110_draw @ fffcb0c2 (21 bytes)

/* Menu item ex020110 HCUT SLOPE: on_draw (#74) */

void menu_ex020110_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_hcut_slope(param_1,g_opstate.ex020110_hcut_slope,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020111_draw @ fffcb0d7 (22 bytes)

/* Menu item ex020111 USB OUT LEVEL: on_draw (#74) */

void menu_ex020111_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_out_level(param_1,g_opstate.ex020111_usb_out_level,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020112_draw @ fffcb0ed (22 bytes)

/* Menu item ex020112 REAR OUT LEVEL: on_draw (#74) */

void menu_ex020112_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_out_level(param_1,g_opstate.ex020112_rear_out_level,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020113_draw @ fffcb103 (21 bytes)

/* Menu item ex020113 RPTT SELECT: on_draw (#74) */

void menu_ex020113_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_rptt_select(param_1,g_opstate.ex020113_rptt_select,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020114_draw @ fffcb118 (21 bytes)

/* Menu item ex020114 NAR WIDTH: on_draw (#74) */

void menu_ex020114_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcabc2(param_1,g_opstate.ex020114_nar_width,4,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020115_draw @ fffcb12d (21 bytes)

/* Menu item ex020115 PC KEYING: on_draw (#74) */

void menu_ex020115_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_rptt_select(param_1,g_opstate.ex020115_pc_keying,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020116_draw @ fffcb142 (125 bytes)

/* Menu item ex020116 CW BK-IN TYPE: on_draw (#74) */

void menu_ex020116_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex020116_cw_bk_in_type;
  local_5 = g_opstate.ex020116_cw_bk_in_type;
  if (g_opstate.ex020116_cw_bk_in_type == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xcea);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020117_draw @ fffcb1bf (125 bytes)

/* Menu item ex020117 CW WAVE SHAPE: on_draw (#74) */

void menu_ex020117_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex020117_cw_wave_shape;
  local_5 = g_opstate.ex020117_cw_wave_shape;
  if (g_opstate.ex020117_cw_wave_shape == 2) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xd14);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020118_draw @ fffcb23c (125 bytes)

/* Menu item ex020118 CW FREQ DISPLAY: on_draw (#74) */

void menu_ex020118_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex020118_cw_freq_display;
  local_5 = g_opstate.ex020118_cw_freq_display;
  if (g_opstate.ex020118_cw_freq_display == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 0xc;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xd53);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020119_draw @ fffcb2b9 (125 bytes)

/* Menu item ex020119 QSK DELAY TIME: on_draw (#74) */

void menu_ex020119_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex020119_qsk_delay_time;
  local_5 = g_opstate.ex020119_qsk_delay_time;
  if (g_opstate.ex020119_qsk_delay_time == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xd7d);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020120_draw @ fffcb336 (21 bytes)

/* Menu item ex020120 CW INDICATOR: on_draw (#74) */

void menu_ex020120_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_off_on(param_1,g_opstate.ex020120_cw_indicator,1,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_off_on @ fffcb34b (119 bytes)

/* OFF / ON row (ROM 0xFFF842E5): CW INDICATOR, SCU-LAN10, EMERGENCY FREQ TX, TX INHIBIT, EXT
   DISPLAY [fact] */

void menu_draw_off_on(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  local_5 = param_2;
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xdd1);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex020201_draw @ fffcb3c2 (125 bytes)

/* Menu item ex020201 KEYER TYPE: on_draw (#74) */

void menu_ex020201_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex020201_keyer_type;
  local_5 = g_opstate.ex020201_keyer_type;
  if (g_opstate.ex020201_keyer_type == 3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 8;
  param_1[2] = 0;
  if (5 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xdfb);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020202_draw @ fffcb43f (125 bytes)

/* Menu item ex020202 KEYER DOT/DASH: on_draw (#74) */

void menu_ex020202_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex020202_keyer_dot_dash;
  local_5 = g_opstate.ex020202_keyer_dot_dash;
  if (g_opstate.ex020202_keyer_dot_dash == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xe79);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020203_draw @ fffcb4bc (190 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcb538) */
/* WARNING: Removing unreachable block (ram,0xfffcb560) */
/* Menu item ex020203 CW WEIGHT: on_draw (#74) */

void menu_ex020203_draw(byte *param_1)

{
  byte bVar1;
  
  bVar1 = g_opstate.ex020203_cw_weight;
  if (g_opstate.ex020203_cw_weight == 5) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  param_1[0x28] = 0x20;
  param_1[0x29] = 0x20;
  param_1[0x2a] = 0x20;
  param_1[0x2b] = 0x20;
  param_1[0x24] = 0x20;
  param_1[0x25] = 0x20;
  param_1[0x26] = 0x20;
  param_1[0x27] = 0x20;
  param_1[0x20] = 0x20;
  param_1[0x21] = 0x20;
  param_1[0x22] = 0x20;
  param_1[0x23] = 0x20;
  param_1[0x1c] = 0x20;
  param_1[0x1d] = 0x20;
  param_1[0x1e] = 0x20;
  param_1[0x1f] = 0x20;
  param_1[0x18] = 0x20;
  param_1[0x19] = 0x20;
  param_1[0x1a] = 0x20;
  param_1[0x1b] = 0x20;
  param_1[0x2c] = 0x20;
  param_1[0x18] = (byte)(bVar1 + 0x19) / 10 | 0x30;
  param_1[0x19] = 0x2e;
  param_1[0x1a] = (byte)(bVar1 + 0x19) % 10 | 0x30;
  return;
}


// ===== menu_ex020204_draw @ fffcb57a (125 bytes)

/* Menu item ex020204 NUMBER STYLE: on_draw (#74) */

void menu_ex020204_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex020204_number_style;
  local_5 = g_opstate.ex020204_number_style;
  if (g_opstate.ex020204_number_style == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (6 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xea3);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex020205_draw @ fffcb5f7 (102 bytes)

/* Menu item ex020205 CONTEST NUMBER: on_draw (#74) */

void menu_ex020205_draw(byte *param_1)

{
  short sVar1;
  
  sVar1 = contest_number_get();
  if (sVar1 == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  dec_to_str_u16(sVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex020206_draw @ fffcb65d (21 bytes)

/* Menu item ex020206 CW MEMORY 1: on_draw (#74) */

void menu_ex020206_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_cw_memory(param_1,g_opstate.ex020206_cw_memory_1,0,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_cw_memory @ fffcb672 (119 bytes)

/* CW MEMORY 1..5 row: TEXT / MESSAGE (ROM 0xFFF8444A) [fact] */

void menu_draw_cw_memory(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  local_5 = param_2;
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0xf36);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex020207_draw @ fffcb6e9 (21 bytes)

/* Menu item ex020207 CW MEMORY 2: on_draw (#74) */

void menu_ex020207_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_cw_memory(param_1,g_opstate.ex020207_cw_memory_2,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020208_draw @ fffcb6fe (21 bytes)

/* Menu item ex020208 CW MEMORY 3: on_draw (#74) */

void menu_ex020208_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_cw_memory(param_1,g_opstate.ex020208_cw_memory_3,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020209_draw @ fffcb713 (21 bytes)

/* Menu item ex020209 CW MEMORY 4: on_draw (#74) */

void menu_ex020209_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_cw_memory(param_1,g_opstate.ex020209_cw_memory_4,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020210_draw @ fffcb728 (21 bytes)

/* Menu item ex020210 CW MEMORY 5: on_draw (#74) */

void menu_ex020210_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_cw_memory(param_1,g_opstate.ex020210_cw_memory_5,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex020211_draw @ fffcb73d (124 bytes)

/* Menu item ex020211 REPEAT INTERVAL: on_draw (#74) */

void menu_ex020211_draw(byte *param_1)

{
  byte bVar1;
  
  bVar1 = g_opstate.ex020211_repeat_interval;
  if (g_opstate.ex020211_repeat_interval == 5) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  bVar1 = dec_to_str_u8(bVar1,param_1 + 0x18);
  param_1 = param_1 + bVar1 + 0x18;
  param_1[2] = 99;
  param_1[0] = 0x73;
  param_1[1] = 0x65;
  return;
}


// ===== menu_ex030101_draw @ fffcb7b9 (108 bytes)

/* Menu item ex030101 BEEP LEVEL: on_draw (#74) */

void menu_ex030101_draw(byte *param_1)

{
  byte bVar1;
  
  bVar1 = g_opstate.ex030101_beep_level;
  if (g_opstate.ex030101_beep_level == 0x14) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  dec_to_str_u8(bVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex030102_draw @ fffcb825 (128 bytes)

/* Menu item ex030102 RF/SQL VR: on_draw (#74) */

void menu_ex030102_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030102_rf_sql_vr;
  local_7 = g_opstate.ex030102_rf_sql_vr;
  if (g_opstate.ex030102_rf_sql_vr == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 0xc;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0xf60);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030103_draw @ fffcb8a5 (128 bytes)

/* Menu item ex030103 TUN/LIN PORT SELECT: on_draw (#74) */

void menu_ex030103_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030103_tun_lin_port_select;
  local_7 = g_opstate.ex030103_tun_lin_port_select;
  if (g_opstate.ex030103_tun_lin_port_select == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 9;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 3999);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030104_draw @ fffcb925 (128 bytes)

/* Menu item ex030104 TUNER TYPE SELECT: on_draw (#74) */

void menu_ex030104_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030104_tuner_type_select;
  local_7 = g_opstate.ex030104_tuner_type_select;
  if (g_opstate.ex030104_tuner_type_select == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 9;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0xff3);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030105_draw @ fffcb9a5 (21 bytes)

/* Menu item ex030105 CAT-1 RATE: on_draw (#74) */

void menu_ex030105_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb9ba(param_1,g_opstate.ex030105_cat_1_rate,3,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcb9ba @ fffcb9ba (119 bytes)

void FUN_fffcb9ba(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 9;
  param_1[2] = 0;
  local_5 = param_2;
  if (4 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x1047);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030106_draw @ fffcba31 (21 bytes)

/* Menu item ex030106 CAT-1 TIME OUT TIMER: on_draw (#74) */

void menu_ex030106_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcba46(param_1,g_opstate.ex030106_cat_1_time_out_timer,0,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffcba46 @ fffcba46 (119 bytes)

void FUN_fffcba46(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  byte local_5;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 8;
  param_1[2] = 0;
  local_5 = param_2;
  if (3 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x10b0);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030107_draw @ fffcbabd (128 bytes)

/* Menu item ex030107 CAT-1 CAT-3 STOP BIT: on_draw (#74) */

void menu_ex030107_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030107_cat_1_cat_3_stop_bit;
  local_7 = g_opstate.ex030107_cat_1_cat_3_stop_bit;
  if (g_opstate.ex030107_cat_1_cat_3_stop_bit == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (int)(&DAT_00002328 + (uint)local_7 * 0x15));
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030108_draw @ fffcbb3d (21 bytes)

/* Menu item ex030108 CAT-2 RATE: on_draw (#74) */

void menu_ex030108_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb9ba(param_1,g_opstate.ex030108_cat_2_rate,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030109_draw @ fffcbb52 (21 bytes)

/* Menu item ex030109 CAT-2 TIME OUT TIMER: on_draw (#74) */

void menu_ex030109_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcba46(param_1,g_opstate.ex030109_cat_2_time_out_timer,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030110_draw @ fffcbb67 (21 bytes)

/* Menu item ex030110 CAT-3 RATE: on_draw (#74) */

void menu_ex030110_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffcb9ba(param_1,g_opstate.ex030110_cat_3_rate,3,param_4,param_5,param_1);
  return;
}

