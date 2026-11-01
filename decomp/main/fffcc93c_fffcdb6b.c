// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex030405_draw @ fffcc93c (128 bytes)

/* Menu item ex030405 VOX SELECT: on_draw (#74) */

void menu_ex030405_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030405_vox_select;
  local_7 = g_opstate.ex030405_vox_select;
  if (g_opstate.ex030405_vox_select == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x151e);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030406_draw @ fffcc9bc (21 bytes)

/* Menu item ex030406 EMERGENCY FREQ TX: on_draw (#74) */

void menu_ex030406_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_off_on(param_1,g_opstate.ex030406_emergency_freq_tx,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030407_draw @ fffcc9d1 (21 bytes)

/* Menu item ex030407 TX INHITBIT: on_draw (#74) */

void menu_ex030407_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_off_on(param_1,g_opstate.ex030407_tx_inhitbit,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex030408_draw @ fffcc9e6 (128 bytes)

/* Menu item ex030408 METER DETECTOR: on_draw (#74) */

void menu_ex030408_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030408_meter_detector;
  local_7 = g_opstate.ex030408_meter_detector;
  if (g_opstate.ex030408_meter_detector == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x155d);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030501_draw @ fffcca66 (128 bytes)

/* Menu item ex030501 SSB/CW DIAL STEP: on_draw (#74) */

void menu_ex030501_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030501_ssb_cw_dial_step;
  local_7 = g_opstate.ex030501_ssb_cw_dial_step;
  if (g_opstate.ex030501_ssb_cw_dial_step == 2) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1587);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030502_draw @ fffccae6 (128 bytes)

/* Menu item ex030502 RTTY/PSK DIAL STEP: on_draw (#74) */

void menu_ex030502_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030502_rtty_psk_dial_step;
  local_7 = g_opstate.ex030502_rtty_psk_dial_step;
  if (g_opstate.ex030502_rtty_psk_dial_step == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1587);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030503_draw @ fffccb66 (128 bytes)

/* Menu item ex030503 CH STEP: on_draw (#74) */

void menu_ex030503_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030503_ch_step;
  local_7 = g_opstate.ex030503_ch_step;
  if (g_opstate.ex030503_ch_step == 2) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x15c6);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030504_draw @ fffccbe6 (128 bytes)

/* Menu item ex030504 AM CH STEP: on_draw (#74) */

void menu_ex030504_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030504_am_ch_step;
  local_7 = g_opstate.ex030504_am_ch_step;
  if (g_opstate.ex030504_am_ch_step == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (5 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x161a);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030505_draw @ fffccc66 (128 bytes)

/* Menu item ex030505 FM CH STEP: on_draw (#74) */

void menu_ex030505_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030505_fm_ch_step;
  local_7 = g_opstate.ex030505_fm_ch_step;
  if (g_opstate.ex030505_fm_ch_step == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (5 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1698);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex030506_draw @ fffccce6 (128 bytes)

/* Menu item ex030506 MAIN STEPS PER REV.: on_draw (#74) */

void menu_ex030506_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex030506_main_steps_per_rev;
  local_7 = g_opstate.ex030506_main_steps_per_rev;
  if (g_opstate.ex030506_main_steps_per_rev == 2) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1716);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040101_draw @ fffccd66 (103 bytes)

/* Menu item ex040101 MY CALL: on_draw (#74) */

void menu_ex040101_draw(byte *param_1)

{
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 0xc;
  param_1[2] = 0;
  *(undefined4 *)(param_1 + 0x20) = g_opstate.ex040101_my_call._8_4_;
  *(undefined4 *)(param_1 + 0x1c) = g_opstate.ex040101_my_call._4_4_;
  *(undefined4 *)(param_1 + 0x18) = g_opstate.ex040101_my_call._0_4_;
  return;
}


// ===== menu_ex040102_draw @ fffccdcd (128 bytes)

/* Menu item ex040102 MY CALL TIME: on_draw (#74) */

void menu_ex040102_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040102_my_call_time;
  local_7 = g_opstate.ex040102_my_call_time;
  if (g_opstate.ex040102_my_call_time == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (5 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1755);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040103_draw @ fffcce4d (128 bytes)

/* Menu item ex040103 POP-UP TIME: on_draw (#74) */

void menu_ex040103_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040103_pop_up_time;
  local_7 = g_opstate.ex040103_pop_up_time;
  if (g_opstate.ex040103_pop_up_time == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x17d3);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040104_draw @ fffccecd (128 bytes)

/* Menu item ex040104 SCREEN SAVER: on_draw (#74) */

void menu_ex040104_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040104_screen_saver;
  local_7 = g_opstate.ex040104_screen_saver;
  if (g_opstate.ex040104_screen_saver == 3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 5;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (int)(&DAT_00001812 + (uint)local_7 * 0x15));
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040105_draw @ fffccf4d (129 bytes)

/* Menu item ex040105 LED DIMMER: on_draw (#74) */

void menu_ex040105_draw(byte *param_1)

{
  byte bVar1;
  
  bVar1 = g_opstate.ex040105_led_dimmer;
  if (g_opstate.ex040105_led_dimmer == 0x14) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  if (bVar1 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  dec_to_str_u8(bVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex040106_draw @ fffccfce (107 bytes)

/* Menu item ex040106 MOUSE POINTER SPEED: on_draw (#74) */

void menu_ex040106_draw(byte *param_1)

{
  byte bVar1;
  
  bVar1 = g_opstate.ex040106_mouse_pointer_speed;
  if (g_opstate.ex040106_mouse_pointer_speed == 10) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  dec_to_str_u8(bVar1,param_1 + 0x18);
  return;
}


// ===== menu_ex040201_draw @ fffcd039 (128 bytes)

/* Menu item ex040201 RBW: on_draw (#74) */

void menu_ex040201_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040201_rbw;
  local_7 = g_opstate.ex040201_rbw;
  if (g_opstate.ex040201_rbw == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  if (2 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1866);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040202_draw @ fffcd0b9 (128 bytes)

/* Menu item ex040202 SCOPE CTR: on_draw (#74) */

void menu_ex040202_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040202_scope_ctr;
  local_7 = g_opstate.ex040202_scope_ctr;
  if (g_opstate.ex040202_scope_ctr == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x18a5);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040203_draw @ fffcd139 (128 bytes)

/* Menu item ex040203 2D DISP SENSITIVITY: on_draw (#74) */

void menu_ex040203_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040203_2d_disp_sensitivity;
  local_7 = g_opstate.ex040203_2d_disp_sensitivity;
  if (g_opstate.ex040203_2d_disp_sensitivity == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x18cf);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040204_draw @ fffcd1b9 (128 bytes)

/* Menu item ex040204 3DSS DISP SENSITIVITY: on_draw (#74) */

void menu_ex040204_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040204_3dss_disp_sensitivity;
  local_7 = g_opstate.ex040204_3dss_disp_sensitivity;
  if (g_opstate.ex040204_3dss_disp_sensitivity == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x18cf);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040301_draw @ fffcd239 (128 bytes)

/* Menu item ex040301 VMI COLOR VFO-A: on_draw (#74) */

void menu_ex040301_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040301_vmi_color_vfo_a;
  local_7 = g_opstate.ex040301_vmi_color_vfo_a;
  if (g_opstate.ex040301_vmi_color_vfo_a == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1ab5);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040302_draw @ fffcd2b9 (128 bytes)

/* Menu item ex040302 VMI COLOR VFO-B: on_draw (#74) */

void menu_ex040302_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040302_vmi_color_vfo_b;
  local_7 = g_opstate.ex040302_vmi_color_vfo_b;
  if (g_opstate.ex040302_vmi_color_vfo_b == 1) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1ab5);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040303_draw @ fffcd339 (128 bytes)

/* Menu item ex040303 VMI COLOR MEMORY: on_draw (#74) */

void menu_ex040303_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040303_vmi_color_memory;
  local_7 = g_opstate.ex040303_vmi_color_memory;
  if (g_opstate.ex040303_vmi_color_memory == 2) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (3 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1b33);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040304_draw @ fffcd3b9 (128 bytes)

/* Menu item ex040304 VMI COLOR CLAR: on_draw (#74) */

void menu_ex040304_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040304_vmi_color_clar;
  local_7 = g_opstate.ex040304_vmi_color_clar;
  if (g_opstate.ex040304_vmi_color_clar == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x1b09);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex040401_draw @ fffcd439 (21 bytes)

/* Menu item ex040401 EXT DISPLAY: on_draw (#74) */

void menu_ex040401_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_off_on(param_1,g_opstate.ex040401_ext_display,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex040402_draw @ fffcd44e (128 bytes)

/* Menu item ex040402 PIXEL: on_draw (#74) */

void menu_ex040402_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_7;
  
  bVar1 = g_opstate.ex040402_pixel;
  local_7 = g_opstate.ex040402_pixel;
  if (g_opstate.ex040402_pixel == 0) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 7;
  param_1[2] = 0;
  if (1 < bVar1) {
    local_7 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_7 * 0x15 + 0x18f9);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_m4_16_0_draw @ fffcd4ce (127 bytes)

/* Menu item m4_16_0 DAY: on_draw (#74) */

void menu_m4_16_0_draw(byte *param_1)

{
  datetime_edit_load();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  param_1[0x18] = PTR_g_ui_00025d60->rtc_set[2] >> 4 | 0x30;
  param_1[0x19] = PTR_g_ui_00025d60->rtc_set[2] & 0x3f | 0x30;
  return;
}


// ===== datetime_edit_load @ fffcd54d (136 bytes)

/* DATE&TIME draw: unless +0x3FF = 3, copies the clock UI +0xAD..+0xB1 to the edit copy +0xB2..+0xB6
   (day/month 0 -> 1) [fact] */

void datetime_edit_load(void)

{
  if (PTR_g_ui_00025d60->menu_state == 3) {
    PTR_g_ui_00025d60->rtc_edit_apply = 1;
    return;
  }
  PTR_g_ui_00025d60->rtc_set[1] = PTR_g_ui_00025d60->rtc_mm;
  if (PTR_g_ui_00025d60->rtc_mm == 0) {
    PTR_g_ui_00025d60->rtc_set[1] = 1;
  }
  PTR_g_ui_00025d60->rtc_set[2] = PTR_g_ui_00025d60->rtc_dd;
  if (PTR_g_ui_00025d60->rtc_dd == 0) {
    PTR_g_ui_00025d60->rtc_set[2] = 1;
  }
  PTR_g_ui_00025d60->rtc_set[0] = PTR_g_ui_00025d60->rtc_yy;
  PTR_g_ui_00025d60->rtc_set[3] = PTR_g_ui_00025d60->rtc_hh;
  PTR_g_ui_00025d60->rtc_set[4] = PTR_g_ui_00025d60->rtc_min;
  return;
}


// ===== menu_m4_16_1_draw @ fffcd5d5 (136 bytes)

/* Menu item m4_16_1 MONTH: on_draw (#74) */

void menu_m4_16_1_draw(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bStack_7;
  
  datetime_edit_load();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  bStack_7 = ((PTR_g_ui_00025d60->rtc_set[1] >> 4) * '\n' + (PTR_g_ui_00025d60->rtc_set[1] & 0xf)) -
             1;
  if (0xb < bStack_7) {
    bStack_7 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_7 * 0x15 + 0x1923);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_m4_16_2_draw @ fffcd65d (159 bytes)

/* Menu item m4_16_2 YEAR: on_draw (#74) */

void menu_m4_16_2_draw(byte *param_1)

{
  datetime_edit_load();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 4;
  param_1[2] = 0;
  param_1[0x18] = 0x32;
  param_1[0x19] = 0x30;
  param_1[0x1a] = PTR_g_ui_00025d60->rtc_set[0] >> 4 | 0x30;
  param_1[0x1b] = PTR_g_ui_00025d60->rtc_set[0] & 0x3f | 0x30;
  return;
}


// ===== menu_m4_16_3_draw @ fffcd6fc (127 bytes)

/* Menu item m4_16_3 HOUR: on_draw (#74) */

void menu_m4_16_3_draw(byte *param_1)

{
  datetime_edit_load();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  param_1[0x18] = PTR_g_ui_00025d60->rtc_set[3] >> 4 | 0x30;
  param_1[0x19] = PTR_g_ui_00025d60->rtc_set[3] & 0x3f | 0x30;
  return;
}


// ===== menu_m4_16_4_draw @ fffcd77b (127 bytes)

/* Menu item m4_16_4 MINUTE: on_draw (#74) */

void menu_m4_16_4_draw(byte *param_1)

{
  datetime_edit_load();
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 2;
  param_1[2] = 0;
  param_1[0x18] = PTR_g_ui_00025d60->rtc_set[4] >> 4 | 0x30;
  param_1[0x19] = PTR_g_ui_00025d60->rtc_set[4] & 0x3f | 0x30;
  return;
}


// ===== menu_m4_17_0_draw @ fffcd7fa (9 bytes)

/* Menu item m4_17_0 MEM LIST LOAD: on_draw (#74) */

void menu_m4_17_0_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_draw_done @ fffcd803 (98 bytes)

/* Action rows (SD CARD, CALIBRATION, RESET, CERTIFICATION): width 4, text "DONE" [fact] */

void menu_draw_done(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 4;
  param_1[2] = 0;
  *(undefined4 *)(param_1 + 0x28) = 0x20202020;
  *(undefined4 *)(param_1 + 0x24) = 0x20202020;
  *(undefined4 *)(param_1 + 0x20) = 0x20202020;
  *(undefined4 *)(param_1 + 0x1c) = 0x20202020;
  *(undefined4 *)(param_1 + 0x18) = 0x20202020;
  param_1[0x2c] = 0x20;
  *(undefined4 *)(param_1 + 0x18) = 0x454e4f44;
  return;
}


// ===== menu_m4_17_1_draw @ fffcd865 (9 bytes)

/* Menu item m4_17_1 MEM LIST SAVE: on_draw (#74) */

void menu_m4_17_1_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_17_2_draw @ fffcd86e (9 bytes)

/* Menu item m4_17_2 MENU LOAD: on_draw (#74) */

void menu_m4_17_2_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_17_3_draw @ fffcd877 (9 bytes)

/* Menu item m4_17_3 MENU SAVE: on_draw (#74) */

void menu_m4_17_3_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_17_4_draw @ fffcd880 (9 bytes)

/* Menu item m4_17_4 INFORMATIONS: on_draw (#74) */

void menu_m4_17_4_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_17_5_draw @ fffcd889 (9 bytes)

/* Menu item m4_17_5 FIRMWARE UPDATE: on_draw (#74) */

void menu_m4_17_5_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_17_6_draw @ fffcd892 (9 bytes)

/* Menu item m4_17_6 FORMAT: on_draw (#74) */

void menu_m4_17_6_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_18_0_draw @ fffcd89b (209 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcd969) */
/* Menu item m4_18_0 SOFTVERSION: on_draw (#74) */

char * menu_m4_18_0_draw(char *param_1)

{
  byte bVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  
  bVar1 = g_cfg105.a008_gn_dbg_mode_enable;
  pcVar4 = 
  "MAIN    : V00-00              DISPLAY : V00-00              DSP     : V00-00              SDR     : V00-00              DST     :                     BLUE                 GREEN                RED                  NONE                 RED                  NONE                 BLUE                 GREEN                WHITE                NONE                 OFF                  100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                550Hz                600Hz                650Hz                700Hz                750Hz                800Hz                850Hz                900Hz                950Hz                1000Hz               OFF                  700Hz                750Hz                800Hz                850Hz                900Hz                950Hz                1000Hz               1050Hz               1100Hz               1150Hz               1200Hz               1250Hz               1300Hz               1350Hz               1400Hz               1450Hz               1500Hz               1550Hz               1600Hz               1650Hz               1700Hz               1750Hz               1800Hz               1850Hz               1900Hz               1950Hz               2000Hz               2050Hz               2100Hz               2150Hz               2200Hz               2250Hz               2300Hz               2350Hz               2400Hz               2450Hz               2500Hz               2550Hz               2600Hz               2650Hz               2700Hz               2750Hz               2800Hz               2850Hz               2900Hz               2950Hz               3000Hz               3050Hz               3100Hz               3150Hz               3200Hz               3250Hz               3300Hz               3350Hz               3400Hz               3450Hz               3500Hz               3550Hz               3600Hz               3650Hz  ..." /* TRUNCATED STRING LITERAL */
  ;
  pcVar2 = param_1;
  for (iVar5 = 0x96; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pcVar2 = *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  }
  puVar3 = (undefined4 *)ver_main();
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(puVar3 + 1);
  *(undefined4 *)(param_1 + 10) = *puVar3;
  if (bVar1 != 0) {
    param_1[0x10] = '-';
    puVar3 = (undefined4 *)ver_main_ext1();
    *(undefined4 *)(param_1 + 0x11) = *puVar3;
    puVar3 = (undefined4 *)ver_main_ext2();
    *(undefined4 *)(param_1 + 0x1a) = puVar3[1];
    *(undefined4 *)(param_1 + 0x16) = *puVar3;
  }
  puVar3 = (undefined4 *)ver_display();
  *(undefined2 *)(param_1 + 0x2c) = *(undefined2 *)(puVar3 + 1);
  *(undefined4 *)(param_1 + 0x28) = *puVar3;
  if (bVar1 != 0) {
    puVar3 = (undefined4 *)ver_display_date();
    *(undefined4 *)(param_1 + 0x38) = puVar3[1];
    *(undefined4 *)(param_1 + 0x34) = *puVar3;
  }
  puVar3 = (undefined4 *)ver_dsp();
  *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(puVar3 + 1);
  *(undefined4 *)(param_1 + 0x46) = *puVar3;
  puVar3 = (undefined4 *)ver_sdr();
  *(undefined2 *)(param_1 + 0x68) = *(undefined2 *)(puVar3 + 1);
  *(undefined4 *)(param_1 + 100) = *puVar3;
  param_1 = param_1 + 0x82;
  pcVar2 = (char *)FUN_fffb3fa7();
  for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
    *param_1 = *pcVar2;
    param_1 = param_1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  return param_1;
}


// ===== menu_m4_19_0_draw @ fffcd96c (9 bytes)

/* Menu item m4_19_0 CALIBRATION: on_draw (#74) */

void menu_m4_19_0_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_20_0_draw @ fffcd975 (9 bytes)

/* Menu item m4_20_0 MEMORY CLEAR: on_draw (#74) */

void menu_m4_20_0_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_20_1_draw @ fffcd97e (9 bytes)

/* Menu item m4_20_1 MENU CLEAR: on_draw (#74) */

void menu_m4_20_1_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_20_2_draw @ fffcd987 (9 bytes)

/* Menu item m4_20_2 ALL RESET: on_draw (#74) */

void menu_m4_20_2_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_m4_21_0_draw @ fffcd990 (9 bytes)

/* Menu item m4_21_0 CERTIFICATION: on_draw (#74) */

void menu_m4_21_0_draw(void)

{
  menu_draw_done();
  return;
}


// ===== menu_select_group @ fffcd999 (184 bytes)

/* (n): P2 group n-1 of the current P1 (+0x41F) if it exists: group cursor 0x15E00[P1], +0x420,
   +0x3FF = 2 [fact] */

undefined1 menu_select_group(char param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uStack_4;
  
  bVar2 = param_1 - 1;
  bVar3 = menu_count_groups(PTR_g_ui_00025d60->menu_p1);
  if (bVar2 < bVar3) {
    (&DAT_00015e00)[PTR_g_ui_00025d60->menu_p1] = bVar2;
    PTR_g_ui_00025d60->menu_p2 = bVar2;
    if ((PTR_g_ui_00025d60->menu_p1 == 4) && (bVar2 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (PTR_g_ui_00025d60->menu_state == 2) {
        PTR_g_ui_00025d60->menu_state = 0;
      }
      uStack_4 = 1;
    }
    else {
      if (PTR_g_ui_00025d60->menu_p1 != 5) {
        bVar2 = g_opstate.preset_sel;
      }
      g_opstate.preset_sel = bVar2;
      PTR_g_ui_00025d60->menu_state = 2;
      uStack_4 = 1;
    }
  }
  else {
    uStack_4 = 0;
  }
  return uStack_4;
}


// ===== menu_select_row @ fffcda51 (213 bytes)

/* (n): sets the row cursor of the current group (menu_cursor_of) and runs the row request [fact] */

undefined1 menu_select_row(char param_1)

{
  bool bVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  undefined1 uStack_9;
  
  bVar2 = menu_p2_global(PTR_g_ui_00025d60->menu_p1,PTR_g_ui_00025d60->menu_p2);
  if (bVar2 == 0x12) {
    uStack_9 = 0;
  }
  else {
    pcVar3 = (char *)menu_cursor_of(bVar2);
    *pcVar3 = param_1;
    if (DAT_0001b4fc == '\0') {
      DAT_00015dfd = PTR_g_ui_00025d60->menu_p1;
      DAT_00015dff = *pcVar3 + pcVar3[1];
      if ((DAT_00015dfd == 4) && (bVar2 == 0x11)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) && (DAT_00015dff == '\x05')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        PTR_s_V01_12_0001b4fd._0_1_ = 1;
      }
      DAT_00015dfe = bVar2;
      iVar4 = FUN_fffcdb6b(&DAT_00015dfd);
      if (iVar4 == 1) {
        DAT_0001b4fc = '\x01';
      }
      else {
        menu_ui_enter();
      }
    }
    uStack_9 = 1;
  }
  return uStack_9;
}


// ===== FUN_fffcdb26 @ fffcdb26 (69 bytes)

void FUN_fffcdb26(void)

{
  byte bVar1;
  
  if (DAT_0001b4fc == '\x01') {
    DAT_0001b4fc = 2;
    swtimer_start(0x31,200);
    return;
  }
  if ((DAT_0001b4fc == '\x02') && (bVar1 = swtimer_expired(0x31), bVar1 == 1)) {
    DAT_0001b4fc = 0;
    menu_ui_enter();
    return;
  }
  return;
}


// ===== FUN_fffcdb6b @ fffcdb6b (77 bytes)

undefined1 FUN_fffcdb6b(int param_1)

{
  bool bVar1;
  undefined1 local_6;
  
  if ((*(char *)(param_1 + 1) == '\x14') || (*(char *)(param_1 + 1) == '\x11')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = 1;
  }
  else {
    if ((*(char *)(param_1 + 1) == '\f') && (*(char *)(param_1 + 2) == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_6 = 1;
    }
    else {
      local_6 = 0;
    }
  }
  return local_6;
}

