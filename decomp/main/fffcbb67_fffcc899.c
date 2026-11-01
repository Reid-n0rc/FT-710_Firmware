// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex030110_draw @ fffcbb67 (21 bytes)

/* Menu item ex030110 CAT-3 RATE: on_draw (#74) */

void menu_ex030110_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_cat_rate(param_1,g_opstate.ex030110_cat_3_rate,3,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030111_draw @ fffcbb7c (21 bytes)

/* Menu item ex030111 CAT-3 TIME OUT TIMER: on_draw (#74) */

void menu_ex030111_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_cat_tot(param_1,g_opstate.ex030111_cat_3_time_out_timer,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030112_draw @ fffcbb91 (128 bytes)

/* Menu item ex030112 QMB CH: on_draw (#74) */

void menu_ex030112_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030112_qmb_ch_val;
  
  g_opstate_ex030112_qmb_ch_val = g_opstate.ex030112_qmb_ch;
  local_7 = g_opstate.ex030112_qmb_ch;
  if (g_opstate.ex030112_qmb_ch == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (1 < g_opstate_ex030112_qmb_ch_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1104);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030113_draw @ fffcbc11 (128 bytes)

/* Menu item ex030113 BAND STACK: on_draw (#74) */

void menu_ex030113_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030113_band_stack_val;
  
  g_opstate_ex030113_band_stack_val = g_opstate.ex030113_band_stack;
  local_7 = g_opstate.ex030113_band_stack;
  if (g_opstate.ex030113_band_stack == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (1 < g_opstate_ex030113_band_stack_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0xdd1);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030114_draw @ fffcbc91 (128 bytes)

/* Menu item ex030114 MEM GROUP: on_draw (#74) */

void menu_ex030114_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030114_mem_group_val;
  
  g_opstate_ex030114_mem_group_val = g_opstate.ex030114_mem_group;
  local_7 = g_opstate.ex030114_mem_group;
  if (g_opstate.ex030114_mem_group == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (1 < g_opstate_ex030114_mem_group_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0xdd1);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030115_draw @ fffcbd11 (218 bytes)

/* Menu item ex030115 TX TIME OUT TIMER: on_draw (#74) */

void menu_ex030115_draw(byte *param_1)

{
  byte bVar1;
  ushort dest_code_get_ret;
  byte local_9;
  
  bVar1 = g_opstate.ex030115_tx_time_out_timer;
  dest_code_get_ret = dest_code_get();
  if ((((((dest_code_get_ret == 0x20b) || (dest_code_get_ret == 0x1cb9)) ||
        (dest_code_get_ret == 0x306f)) ||
       ((dest_code_get_ret == 0x315b || (dest_code_get_ret == 0x4380)))) ||
      ((dest_code_get_ret == 0x50e2 ||
       ((dest_code_get_ret == 0x60e6 || (dest_code_get_ret == 0x7753)))))) ||
     ((dest_code_get_ret == 0x9cf7 || (dest_code_get_ret == 0xd32d)))) {
    local_9 = 0;
  }
  else {
    local_9 = 10;
  }
  if (bVar1 == local_9) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (bVar1 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
                    /* u8 as 1..3 ASCII digits without leading zeros [doc] */
  bVar1 = dec_to_str_u8(bVar1,param_1 + 0x18);
  param_1 = param_1 + bVar1 + 0x18;
  param_1[2] = 0x6e;
  param_1[0] = 0x6d;
  param_1[1] = 0x69;
  return;
}


// ===== menu_ex030116_draw @ fffcbdeb (128 bytes)

/* Menu item ex030116 MIC SCAN: on_draw (#74) */

void menu_ex030116_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030116_mic_scan_val;
  
  g_opstate_ex030116_mic_scan_val = g_opstate.ex030116_mic_scan;
  local_7 = g_opstate.ex030116_mic_scan;
  if (g_opstate.ex030116_mic_scan == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (1 < g_opstate_ex030116_mic_scan_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0xdd1);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030117_draw @ fffcbe6b (128 bytes)

/* Menu item ex030117 MIC SCAN RESUME: on_draw (#74) */

void menu_ex030117_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030117_mic_scan_resume_val;
  
  g_opstate_ex030117_mic_scan_resume_val = g_opstate.ex030117_mic_scan_resume;
  local_7 = g_opstate.ex030117_mic_scan_resume;
  if (g_opstate.ex030117_mic_scan_resume == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (1 < g_opstate_ex030117_mic_scan_resume_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x112e);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030118_draw @ fffcbeeb (107 bytes)

/* Menu item ex030118 REF FREQ FINE ADJ: on_draw (#74) */

void menu_ex030118_draw(byte *param_1)

{
  sbyte g_opstate_ex030118_ref_freq_fine_adj_val;
  
  g_opstate_ex030118_ref_freq_fine_adj_val = g_opstate.ex030118_ref_freq_fine_adj;
  if (g_opstate.ex030118_ref_freq_fine_adj == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
                    /* Signed byte to decimal text [doc] */
  dec_to_str_s8((int)g_opstate_ex030118_ref_freq_fine_adj_val,param_1 + 0x18);
  return;
}


// ===== menu_ex030119_draw @ fffcbf56 (223 bytes)

/* Menu item ex030119 KEYBOARD LANGUAGE: on_draw (#74) */

void menu_ex030119_draw(byte *param_1)

{
  ushort dest_code_get_ret;
  byte *pbVar1;
  int i;
  byte local_8;
  byte local_7;
  byte g_opstate_ex030119_keyboard_language_val;
  
  g_opstate_ex030119_keyboard_language_val = g_opstate.ex030119_keyboard_language;
  local_7 = g_opstate.ex030119_keyboard_language;
  dest_code_get_ret = dest_code_get();
  if (dest_code_get_ret == 0xd950) {
LAB_fffcbfc4:
    local_8 = 2;
    goto LAB_fffcbfc7;
  }
  if (((dest_code_get_ret != 0x1cb9) && (dest_code_get_ret != 0x306f)) &&
     (dest_code_get_ret != 0x315b)) {
    if (dest_code_get_ret == 0x4380) {
LAB_fffcbfb7:
      local_8 = 0;
      goto LAB_fffcbfc7;
    }
    if (dest_code_get_ret != 0x50e2) {
      if (dest_code_get_ret == 0x60e6) goto LAB_fffcbfb7;
      if ((dest_code_get_ret != 0x7753) && (dest_code_get_ret != 0x9cf7)) {
        if (dest_code_get_ret == 0xa4c5) goto LAB_fffcbfc4;
        if (dest_code_get_ret != 0xd32d) {
          if (dest_code_get_ret != 0x20b) {
            local_8 = 5;
            goto LAB_fffcbfc7;
          }
          goto LAB_fffcbfb7;
        }
      }
    }
  }
  local_8 = 1;
LAB_fffcbfc7:
  if (g_opstate_ex030119_keyboard_language_val == local_8) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 0xe;
  param_1[2] = 0;
  if (10 < g_opstate_ex030119_keyboard_language_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1158);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030120_draw @ fffcc035 (21 bytes)

/* Menu item ex030120 MIC P1: on_draw (#74) */

void menu_ex030120_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* MIC P1..P4 / UP / DOWN row [doc] */
  menu_draw_mic_key(param_1,g_opstate.ex030120_mic_p1,0,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_mic_key @ fffcc04a (120 bytes)

/* MIC P1..P4 / UP / DOWN row: LOCK, QMB, .., AGC (21 labels, ROM 0xFFF84753) [fact] */

void menu_draw_mic_key(byte *param_1,byte param_2,byte param_3)

{
  byte *pbVar1;
  int i;
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
  if (0x14 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x123f);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030121_draw @ fffcc0c2 (21 bytes)

/* Menu item ex030121 MIC P2: on_draw (#74) */

void menu_ex030121_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* MIC P1..P4 / UP / DOWN row [doc] */
  menu_draw_mic_key(param_1,g_opstate.ex030121_mic_p2,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030122_draw @ fffcc0d7 (21 bytes)

/* Menu item ex030122 MIC P3: on_draw (#74) */

void menu_ex030122_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* MIC P1..P4 / UP / DOWN row [doc] */
  menu_draw_mic_key(param_1,g_opstate.ex030122_mic_p3,2,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030123_draw @ fffcc0ec (21 bytes)

/* Menu item ex030123 MIC P4: on_draw (#74) */

void menu_ex030123_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* MIC P1..P4 / UP / DOWN row [doc] */
  menu_draw_mic_key(param_1,g_opstate.ex030123_mic_p4,3,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030124_draw @ fffcc101 (21 bytes)

/* Menu item ex030124 MIC UP: on_draw (#74) */

void menu_ex030124_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* MIC P1..P4 / UP / DOWN row [doc] */
  menu_draw_mic_key(param_1,g_opstate.ex030124_mic_up,0xd,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030125_draw @ fffcc116 (21 bytes)

/* Menu item ex030125 MIC DOWN: on_draw (#74) */

void menu_ex030125_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* MIC P1..P4 / UP / DOWN row [doc] */
  menu_draw_mic_key(param_1,g_opstate.ex030125_mic_down,0xe,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030126_draw @ fffcc12b (21 bytes)

/* Menu item ex030126 SCU-LAN10: on_draw (#74) */

void menu_ex030126_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_off_on(param_1,g_opstate.ex030126_scu_lan10,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030201_draw @ fffcc140 (128 bytes)

/* Menu item ex030201 IF NOTCH WIDTH: on_draw (#74) */

void menu_ex030201_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030201_if_notch_width_val;
  
  g_opstate_ex030201_if_notch_width_val = g_opstate.ex030201_if_notch_width;
  local_7 = g_opstate.ex030201_if_notch_width;
  if (g_opstate.ex030201_if_notch_width == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (1 < g_opstate_ex030201_if_notch_width_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x13f8);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030202_draw @ fffcc1c0 (128 bytes)

/* Menu item ex030202 NB REJECTION: on_draw (#74) */

void menu_ex030202_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030202_nb_rejection_val;
  
  g_opstate_ex030202_nb_rejection_val = g_opstate.ex030202_nb_rejection;
  local_7 = g_opstate.ex030202_nb_rejection;
  if (g_opstate.ex030202_nb_rejection == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < g_opstate_ex030202_nb_rejection_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1422);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030203_draw @ fffcc240 (128 bytes)

/* Menu item ex030203 NB WIDTH: on_draw (#74) */

void menu_ex030203_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030203_nb_width_val;
  
  g_opstate_ex030203_nb_width_val = g_opstate.ex030203_nb_width;
  local_7 = g_opstate.ex030203_nb_width;
  if (g_opstate.ex030203_nb_width == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (2 < g_opstate_ex030203_nb_width_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (int)(&DAT_00001461 + (uint)local_7 * 0x15));
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030204_draw @ fffcc2c0 (128 bytes)

/* Menu item ex030204 APF WIDTH: on_draw (#74) */

void menu_ex030204_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030204_apf_width_val;
  
  g_opstate_ex030204_apf_width_val = g_opstate.ex030204_apf_width;
  local_7 = g_opstate.ex030204_apf_width;
  if (g_opstate.ex030204_apf_width == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (2 < g_opstate_ex030204_apf_width_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x14a0);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030205_draw @ fffcc340 (108 bytes)

/* Menu item ex030205 CONTOUR LEVEL: on_draw (#74) */

void menu_ex030205_draw(byte *param_1)

{
  sbyte g_opstate_ex030205_contour_level_val;
  
  g_opstate_ex030205_contour_level_val = g_opstate.ex030205_contour_level;
  if (g_opstate.ex030205_contour_level == -0xf) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
                    /* Signed byte to decimal text [doc] */
  dec_to_str_s8((int)g_opstate_ex030205_contour_level_val,param_1 + 0x18);
  return;
}


// ===== menu_ex030206_draw @ fffcc3ac (107 bytes)

/* Menu item ex030206 CONTOUR WIDTH: on_draw (#74) */

void menu_ex030206_draw(byte *param_1)

{
  byte g_opstate_ex030206_contour_width_val;
  
  g_opstate_ex030206_contour_width_val = g_opstate.ex030206_contour_width;
  if (g_opstate.ex030206_contour_width == 10) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
                    /* u8 as 1..3 ASCII digits without leading zeros [doc] */
  dec_to_str_u8(g_opstate_ex030206_contour_width_val,param_1 + 0x18);
  return;
}


// ===== menu_ex030301_draw @ fffcc417 (128 bytes)

/* Menu item ex030301 AMC RELEASE TIME: on_draw (#74) */

void menu_ex030301_draw(byte *param_1)

{
  byte *pbVar1;
  int i;
  byte local_7;
  byte g_opstate_ex030301_amc_release_time_val;
  
  g_opstate_ex030301_amc_release_time_val = g_opstate.ex030301_amc_release_time;
  local_7 = g_opstate.ex030301_amc_release_time;
  if (g_opstate.ex030301_amc_release_time == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < g_opstate_ex030301_amc_release_time_val) {
    local_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x14df);
  param_1 = param_1 + 0x18;
  for (i = 0x15; i != 0; i = i + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex030302_draw @ fffcc497 (24 bytes)

/* Menu item ex030302 PRMTRC EQ1 FREQ: on_draw (#74) */

void menu_ex030302_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
                    /* PRMTRC EQ1..3 FREQ row [doc] */
  menu_draw_eq_freq(param_1,100,g_opstate.ex030302_prmtrc_eq1_freq,0,in_R15,param_1);
  return;
}


// ===== menu_draw_eq_freq @ fffcc4af (167 bytes)

/* PRMTRC EQ1..3 FREQ row (also the P PRMTRC items) [fact] */

void menu_draw_eq_freq(byte *param_1,short param_2,byte param_3,byte param_4)

{
  byte bVar1;
  ushort local_c;
  
  if (param_3 == param_4) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (param_3 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  local_c = ((ushort)param_3 * 100 + param_2) - 100;
  if (0xc80 < local_c) {
    local_c = 0xc80;
  }
                    /* u16 as 1..5 ASCII digits without leading zeros [doc] */
  bVar1 = dec_to_str_u16(local_c,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== menu_ex030303_draw @ fffcc556 (21 bytes)

/* Menu item ex030303 PRMTRC EQ1 LEVEL: on_draw (#74) */

void menu_ex030303_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 LEVEL row [doc] */
  menu_draw_eq_level(param_1,(int)g_opstate.ex030303_prmtrc_eq1_level,5,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_eq_level @ fffcc56b (99 bytes)

/* PRMTRC EQ1..3 LEVEL row: signed value (FUN_fff9c787) [fact] */

void menu_draw_eq_level(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
                    /* Signed byte to decimal text [doc] */
  dec_to_str_s8((int)param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex030304_draw @ fffcc5ce (21 bytes)

/* Menu item ex030304 PRMTRC EQ1 BWTH: on_draw (#74) */

void menu_ex030304_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 BWTH row [doc] */
  menu_draw_eq_bwth(param_1,g_opstate.ex030304_prmtrc_eq1_bwth,10,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_eq_bwth @ fffcc5e3 (98 bytes)

/* PRMTRC EQ1..3 BWTH row [fact] */

void menu_draw_eq_bwth(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
                    /* u8 as 1..3 ASCII digits without leading zeros [doc] */
  dec_to_str_u8(param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex030305_draw @ fffcc645 (25 bytes)

/* Menu item ex030305 PRMTRC EQ2 FREQ: on_draw (#74) */

void menu_ex030305_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
                    /* PRMTRC EQ1..3 FREQ row [doc] */
  menu_draw_eq_freq(param_1,700,g_opstate.ex030305_prmtrc_eq2_freq,0,in_R15,param_1);
  return;
}


// ===== menu_ex030306_draw @ fffcc65e (21 bytes)

/* Menu item ex030306 PRMTRC EQ2 LEVEL: on_draw (#74) */

void menu_ex030306_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 LEVEL row [doc] */
  menu_draw_eq_level(param_1,(int)g_opstate.ex030306_prmtrc_eq2_level,5,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030307_draw @ fffcc673 (21 bytes)

/* Menu item ex030307 PRMTRC EQ2 BWTH: on_draw (#74) */

void menu_ex030307_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 BWTH row [doc] */
  menu_draw_eq_bwth(param_1,g_opstate.ex030307_prmtrc_eq2_bwth,10,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030308_draw @ fffcc688 (25 bytes)

/* Menu item ex030308 PRMTRC EQ3 FREQ: on_draw (#74) */

void menu_ex030308_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
                    /* PRMTRC EQ1..3 FREQ row [doc] */
  menu_draw_eq_freq(param_1,0x5dc,g_opstate.ex030308_prmtrc_eq3_freq,0,in_R15,param_1);
  return;
}


// ===== menu_ex030309_draw @ fffcc6a1 (21 bytes)

/* Menu item ex030309 PRMTRC EQ3 LEVEL: on_draw (#74) */

void menu_ex030309_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 LEVEL row [doc] */
  menu_draw_eq_level(param_1,(int)g_opstate.ex030309_prmtrc_eq3_level,5,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030310_draw @ fffcc6b6 (21 bytes)

/* Menu item ex030310 PRMTRC EQ3 BWTH: on_draw (#74) */

void menu_ex030310_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 BWTH row [doc] */
  menu_draw_eq_bwth(param_1,g_opstate.ex030310_prmtrc_eq3_bwth,10,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030311_draw @ fffcc6cb (24 bytes)

/* Menu item ex030311 P PRMTRC EQ1 FREQ: on_draw (#74) */

void menu_ex030311_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
                    /* PRMTRC EQ1..3 FREQ row [doc] */
  menu_draw_eq_freq(param_1,100,g_opstate.ex030311_p_prmtrc_eq1_freq,0,in_R15,param_1);
  return;
}


// ===== menu_ex030312_draw @ fffcc6e3 (21 bytes)

/* Menu item ex030312 P PRMTRC EQ1 LEVEL: on_draw (#74) */

void menu_ex030312_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 LEVEL row [doc] */
  menu_draw_eq_level(param_1,(int)g_opstate.ex030312_p_prmtrc_eq1_level,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030313_draw @ fffcc6f8 (21 bytes)

/* Menu item ex030313 P PRMTRC EQ1 BWTH: on_draw (#74) */

void menu_ex030313_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 BWTH row [doc] */
  menu_draw_eq_bwth(param_1,g_opstate.ex030313_p_prmtrc_eq1_bwth,2,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030314_draw @ fffcc70d (25 bytes)

/* Menu item ex030314 P PRMTRC EQ2 FREQ: on_draw (#74) */

void menu_ex030314_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
                    /* PRMTRC EQ1..3 FREQ row [doc] */
  menu_draw_eq_freq(param_1,700,g_opstate.ex030314_p_prmtrc_eq2_freq,0,in_R15,param_1);
  return;
}


// ===== menu_ex030315_draw @ fffcc726 (21 bytes)

/* Menu item ex030315 P PRMTRC EQ2 LEVEL: on_draw (#74) */

void menu_ex030315_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 LEVEL row [doc] */
  menu_draw_eq_level(param_1,(int)g_opstate.ex030315_p_prmtrc_eq2_level,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030316_draw @ fffcc73b (21 bytes)

/* Menu item ex030316 P PRMTRC EQ2 BWTH: on_draw (#74) */

void menu_ex030316_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 BWTH row [doc] */
  menu_draw_eq_bwth(param_1,g_opstate.ex030316_p_prmtrc_eq2_bwth,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030317_draw @ fffcc750 (25 bytes)

/* Menu item ex030317 P PRMTRC EQ3 FREQ: on_draw (#74) */

void menu_ex030317_draw(undefined4 param_1)

{
  undefined4 in_R15;
  
                    /* PRMTRC EQ1..3 FREQ row [doc] */
  menu_draw_eq_freq(param_1,0x5dc,g_opstate.ex030317_p_prmtrc_eq3_freq,0,in_R15,param_1);
  return;
}


// ===== menu_ex030318_draw @ fffcc769 (21 bytes)

/* Menu item ex030318 P PRMTRC EQ3 LEVEL: on_draw (#74) */

void menu_ex030318_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 LEVEL row [doc] */
  menu_draw_eq_level(param_1,(int)g_opstate.ex030318_p_prmtrc_eq3_level,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030319_draw @ fffcc77e (21 bytes)

/* Menu item ex030319 P PRMTRC EQ3 BWTH: on_draw (#74) */

void menu_ex030319_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
                    /* PRMTRC EQ1..3 BWTH row [doc] */
  menu_draw_eq_bwth(param_1,g_opstate.ex030319_p_prmtrc_eq3_bwth,1,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030401_draw @ fffcc793 (73 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcc793) */
/* WARNING: Removing unreachable block (ram,0xfffcc7d9) */
/* WARNING: Removing unreachable block (ram,0xfffcc7d6) */
/* Menu item ex030401 HF MAX POWER: on_draw (#74) */

undefined4 menu_ex030401_draw(undefined4 param_1)

{
  undefined4 uVar1;
  byte g_opstate_ex030401_hf_max_power_val;
  
  g_opstate_ex030401_hf_max_power_val = g_opstate.ex030401_hf_max_power;
  uVar1 = max_power_limit(0);
  menu_draw_max_power(param_1,g_opstate_ex030401_hf_max_power_val,uVar1);
  if (g_opstate.rf_power[0] <= g_opstate.ex030401_hf_max_power) {
    return 0x9aee;
  }
  g_opstate.rf_power[0] = g_opstate.ex030401_hf_max_power;
  return 0x9aee;
}


// ===== menu_draw_max_power @ fffcc7dc (116 bytes)

/* (row, value, default) MAX POWER row: dec_to_str_u8 then 'W'; callers menu_ex030401..030404_draw
   (HF/50M/70M/AM MAX POWER) [fact: fffcc7dc] */

void menu_draw_max_power(byte *param_1,char param_2,char param_3)

{
  byte bVar1;
  
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
                    /* u8 as 1..3 ASCII digits without leading zeros [doc] */
  bVar1 = dec_to_str_u8(param_2,param_1 + 0x18);
  param_1[bVar1 + 0x18] = 0x57;
  return;
}


// ===== menu_ex030402_draw @ fffcc850 (73 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcc850) */
/* WARNING: Removing unreachable block (ram,0xfffcc896) */
/* WARNING: Removing unreachable block (ram,0xfffcc893) */
/* Menu item ex030402 50M MAX POWER: on_draw (#74) */

undefined4 menu_ex030402_draw(undefined4 param_1)

{
  undefined4 uVar1;
  byte g_opstate_ex030402_50m_max_power_val;
  
  g_opstate_ex030402_50m_max_power_val = g_opstate.ex030402_50m_max_power;
  uVar1 = max_power_limit(1);
  menu_draw_max_power(param_1,g_opstate_ex030402_50m_max_power_val,uVar1);
  if (g_opstate.rf_power[1] <= g_opstate.ex030402_50m_max_power) {
    return 0x9aef;
  }
  g_opstate.rf_power[1] = g_opstate.ex030402_50m_max_power;
  return 0x9aef;
}


// ===== menu_ex030403_draw @ fffcc899 (73 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcc899) */
/* WARNING: Removing unreachable block (ram,0xfffcc8df) */
/* WARNING: Removing unreachable block (ram,0xfffcc8dc) */
/* Menu item ex030403 70M MAX POWER: on_draw (#74) */

undefined4 menu_ex030403_draw(undefined4 param_1)

{
  undefined4 uVar1;
  byte g_opstate_ex030403_70m_max_power_val;
  
  g_opstate_ex030403_70m_max_power_val = g_opstate.ex030403_70m_max_power;
  uVar1 = max_power_limit(2);
  menu_draw_max_power(param_1,g_opstate_ex030403_70m_max_power_val,uVar1);
  if (g_opstate.rf_power[2] <= g_opstate.ex030403_70m_max_power) {
    return 0x9af0;
  }
  g_opstate.rf_power[2] = g_opstate.ex030403_70m_max_power;
  return 0x9af0;
}

