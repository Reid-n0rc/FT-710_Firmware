// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== menu_ex010103_draw @ fffc9bfa (24 bytes)

/* Menu item ex010103 AF BASS GAIN: on_draw (#74) */

void menu_ex010103_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex010103_af_bass_gain);
  return;
}


// ===== menu_ex010104_draw @ fffc9c12 (23 bytes)

/* Menu item ex010104 AGC FAST DELAY: on_draw (#74) */

void menu_ex010104_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex010104_agc_fast_delay,300,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_agc_delay @ fffc9c29 (130 bytes)

/* AGC FAST/MID/SLOW DELAY row: raw*20+20 in decimal + "msec", bit 7 on the default [fact] */

void menu_draw_agc_delay(byte *param_1,byte param_2,short param_3)

{
  byte bVar1;
  short sVar2;
  
  sVar2 = (ushort)param_2 * 0x14 + 0x14;
  if (sVar2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 8;
  param_1[2] = 0;
  bVar1 = dec_to_str_u16(sVar2,param_1 + 0x18);
  param_1 = param_1 + bVar1 + 0x18;
  param_1[0] = 0x6d;
  param_1[1] = 0x73;
  param_1[2] = 0x65;
  param_1[3] = 99;
  return;
}


// ===== menu_ex010105_draw @ fffc9cab (23 bytes)

/* Menu item ex010105 AGC MID DELAY: on_draw (#74) */

void menu_ex010105_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex010105_agc_mid_delay,1000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010106_draw @ fffc9cc2 (23 bytes)

/* Menu item ex010106 AGC SLOW DELY: on_draw (#74) */

void menu_ex010106_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex010106_agc_slow_dely,3000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010107_draw @ fffc9cd9 (21 bytes)

/* Menu item ex010107 LCUT FREQ: on_draw (#74) */

void menu_ex010107_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_lcut_freq(param_1,g_opstate.ex010107_lcut_freq,1,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_lcut_freq @ fffc9cee (151 bytes)

/* LCUT FREQ row: OFF or the frequency (dec_to_str_u16) [fact] */

void menu_draw_lcut_freq(byte *param_1,byte param_2,byte param_3)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = (ushort)param_2;
  if (uVar2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (uVar2 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  bVar1 = dec_to_str_u16(uVar2 * 0x32 + 0x32,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== menu_ex010108_draw @ fffc9d85 (21 bytes)

/* Menu item ex010108 LCUT SLOPE: on_draw (#74) */

void menu_ex010108_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_lcut_slope(param_1,g_opstate.ex010108_lcut_slope,0,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_lcut_slope @ fffc9d9a (119 bytes)

/* LCUT SLOPE row: 6dB/oct / 18dB/oct (ROM 0xFFF836EB) [fact] */

void menu_draw_lcut_slope(byte *param_1,byte param_2,byte param_3)

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
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x1d7);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010109_draw @ fffc9e11 (22 bytes)

/* Menu item ex010109 HCUT FREQ: on_draw (#74) */

void menu_ex010109_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_hcut_freq(param_1,g_opstate.ex010109_hcut_freq,0x2f,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_hcut_freq @ fffc9e27 (152 bytes)

/* HCUT FREQ row: OFF or the frequency [fact] */

void menu_draw_hcut_freq(byte *param_1,byte param_2,byte param_3)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = (ushort)param_2;
  if (uVar2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (uVar2 == 0) {
    param_1[0x1a] = 0x46;
    param_1[0x18] = 0x4f;
    param_1[0x19] = 0x46;
    return;
  }
  bVar1 = dec_to_str_u16(uVar2 * 0x32 + 0x28a,param_1 + 0x18);
  (param_1 + bVar1 + 0x18)[0] = 0x48;
  (param_1 + bVar1 + 0x18)[1] = 0x7a;
  return;
}


// ===== menu_ex010110_draw @ fffc9ebf (21 bytes)

/* Menu item ex010110 HCUT SLOPE: on_draw (#74) */

void menu_ex010110_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_hcut_slope(param_1,g_opstate.ex010110_hcut_slope,0,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_hcut_slope @ fffc9ed4 (119 bytes)

/* HCUT SLOPE row: 6dB/oct / 18dB/oct [fact] */

void menu_draw_hcut_slope(byte *param_1,byte param_2,byte param_3)

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
  if (1 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x1d7);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010111_draw @ fffc9f4b (22 bytes)

/* Menu item ex010111 USB OUT LEVEL: on_draw (#74) */

void menu_ex010111_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_out_level(param_1,g_opstate.ex010111_usb_out_level,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_out_level @ fffc9f61 (98 bytes)

/* USB / REAR OUT LEVEL row: value via dec_to_str_u8 [fact] */

void menu_draw_out_level(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  dec_to_str_u8(param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex010112_draw @ fffc9fc3 (22 bytes)

/* Menu item ex010112 REAR OUT LEVEL: on_draw (#74) */

void menu_ex010112_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_out_level(param_1,g_opstate.ex010112_rear_out_level,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010113_draw @ fffc9fd9 (148 bytes)

/* Menu item ex010113 TX BPF SEL: on_draw (#74) */

void menu_ex010113_draw(undefined4 param_1)

{
  bool bVar1;
  ushort uVar2;
  byte local_5;
  
  local_5 = g_opstate.ex010113_tx_bpf_sel;
  if (g_opstate.ex010113_tx_bpf_sel == 6) {
    uVar2 = dest_code_get();
    if ((uVar2 == 0x315b) || (uVar2 == 0x50e2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (uVar2 == 0x1cb9)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (dest_code[2] == 0) {
        g_opstate.ex010113_tx_bpf_sel = 1;
        local_5 = 1;
      }
      else {
        local_5 = 5;
      }
    }
    else {
      g_opstate.ex010113_tx_bpf_sel = 1;
      local_5 = 1;
    }
  }
  menu_draw_tx_bpf_sel(param_1,local_5,1);
  return;
}


// ===== menu_draw_tx_bpf_sel @ fffca06d (163 bytes)

/* (row, value, default) TX BPF SEL row: 10 chars from the menu text table, " 50-3050Hz".."
   50-4000Hz" (0xFFF83715) or "TTBF".."400-2600Hz" (0xFFF83793) when 0x12272 != 0; callers
   menu_ex010113/010213/010413_draw [fact: fffca06d] */

void menu_draw_tx_bpf_sel(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 10;
  param_1[2] = 0;
  local_5 = param_2;
  if (DAT_00012272 == '\0') {
    if (5 < param_2) {
      local_5 = 0;
    }
    pbVar1 = (byte *)(
                     "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                     + (uint)local_5 * 0x15 + 0x201);
    param_1 = param_1 + 0x18;
    for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *pbVar1;
      param_1 = param_1 + 1;
      pbVar1 = pbVar1 + 1;
    }
    return;
  }
  if (4 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x27f);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010114_draw @ fffca110 (21 bytes)

/* Menu item ex010114 MOD SOURCE: on_draw (#74) */

void menu_ex010114_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_mod_source(param_1,g_opstate.ex010114_mod_source,3,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_mod_source @ fffca125 (119 bytes)

/* (row, value, default) MOD SOURCE row: MIC/USB/REAR/AUTO from 0xFFF837FC; callers
   menu_ex010114/010214/010313/010414_draw [fact: fffca125] */

void menu_draw_mod_source(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 4;
  param_1[2] = 0;
  local_5 = param_2;
  if (3 < param_2) {
    local_5 = 3;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x2e8);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010115_draw @ fffca19c (22 bytes)

/* Menu item ex010115 USB MOD GAIN: on_draw (#74) */

void menu_ex010115_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_usb_mod_gain(param_1,g_opstate.ex010115_usb_mod_gain,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_usb_mod_gain @ fffca1b2 (98 bytes)

/* (row, value, default) USB MOD GAIN row: 3 digits by dec_to_str_u8; callers
   menu_ex010115/010215/010314/010415_draw [fact: fffca1b2] */

void menu_draw_usb_mod_gain(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  dec_to_str_u8(param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex010116_draw @ fffca214 (22 bytes)

/* Menu item ex010116 REAR MOD GAIN: on_draw (#74) */

void menu_ex010116_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_rear_mod_gain(param_1,g_opstate.ex010116_rear_mod_gain,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_rear_mod_gain @ fffca22a (98 bytes)

/* (row, value, default) REAR MOD GAIN row: 3 digits by dec_to_str_u8; callers
   menu_ex010116/010216/010315/010416_draw [fact: fffca22a] */

void menu_draw_rear_mod_gain(byte *param_1,char param_2,char param_3)

{
  if (param_2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  dec_to_str_u8(param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex010117_draw @ fffca28c (21 bytes)

/* Menu item ex010117 RPTT SELECT: on_draw (#74) */

void menu_ex010117_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_rptt_select(param_1,g_opstate.ex010117_rptt_select,0,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_rptt_select @ fffca2a1 (119 bytes)

/* RPTT SELECT / PC KEYING row: OFF / RTS / DTR / DAKY (ROM 0xFFF83850) [fact] */

void menu_draw_rptt_select(byte *param_1,byte param_2,byte param_3)

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
  param_1[1] = 4;
  param_1[2] = 0;
  local_5 = param_2;
  if (3 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x33c);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010118_draw @ fffca318 (126 bytes)

/* Menu item ex010118 NAR WIDTH: on_draw (#74) */

void menu_ex010118_draw(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte local_5;
  
  bVar1 = g_opstate.ex010118_nar_width;
  local_5 = g_opstate.ex010118_nar_width;
  if (g_opstate.ex010118_nar_width == 6) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 6;
  param_1[2] = 0;
  if (0x16 < bVar1) {
    local_5 = 0;
  }
  pbVar2 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x390);
  param_1 = param_1 + 0x18;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pbVar2;
    param_1 = param_1 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ===== menu_ex010119_draw @ fffca396 (21 bytes)

/* Menu item ex010119 CW AUTO MODE: on_draw (#74) */

void menu_ex010119_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_cw_auto_mode(param_1,g_opstate.ex010119_cw_auto_mode,0,param_4,param_5,param_1);
  return;
}


// ===== menu_draw_cw_auto_mode @ fffca3ab (119 bytes)

/* (row, value, default) CW AUTO MODE row: OFF/50M/ON from 0xFFF83C40; only caller
   menu_ex010119_draw [fact: fffca3ab] */

void menu_draw_cw_auto_mode(byte *param_1,byte param_2,byte param_3)

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
  if (2 < param_2) {
    local_5 = 0;
  }
  pbVar1 = (byte *)(
                   "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)local_5 * 0x15 + 0x72c);
  param_1 = param_1 + 0x18;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *pbVar1;
    param_1 = param_1 + 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ===== menu_ex010201_draw @ fffca422 (24 bytes)

/* Menu item ex010201 AF TREBLE GAIN: on_draw (#74) */

void menu_ex010201_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex010201_af_treble_gain);
  return;
}


// ===== menu_ex010202_draw @ fffca43a (24 bytes)

/* Menu item ex010202 AF MIDDLE TONE GAIN: on_draw (#74) */

void menu_ex010202_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex010202_af_middle_tone_gain);
  return;
}


// ===== menu_ex010203_draw @ fffca452 (24 bytes)

/* Menu item ex010203 AF BASS GAIN: on_draw (#74) */

void menu_ex010203_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex010203_af_bass_gain);
  return;
}


// ===== menu_ex010204_draw @ fffca46a (23 bytes)

/* Menu item ex010204 AGC FAST DELAY: on_draw (#74) */

void menu_ex010204_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex010204_agc_fast_delay,1000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010205_draw @ fffca481 (23 bytes)

/* Menu item ex010205 AGC MID DELAY: on_draw (#74) */

void menu_ex010205_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex010205_agc_mid_delay,2000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010206_draw @ fffca498 (23 bytes)

/* Menu item ex010206 AGC SLOW DELAY: on_draw (#74) */

void menu_ex010206_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex010206_agc_slow_delay,4000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010207_draw @ fffca4af (21 bytes)

/* Menu item ex010207 LCUT FREQ: on_draw (#74) */

void menu_ex010207_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_lcut_freq(param_1,g_opstate.ex010207_lcut_freq,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010208_draw @ fffca4c4 (21 bytes)

/* Menu item ex010208 LCUT SLOPE: on_draw (#74) */

void menu_ex010208_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_lcut_slope(param_1,g_opstate.ex010208_lcut_slope,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010209_draw @ fffca4d9 (21 bytes)

/* Menu item ex010209 HCUT FREQ: on_draw (#74) */

void menu_ex010209_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_hcut_freq(param_1,g_opstate.ex010209_hcut_freq,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010210_draw @ fffca4ee (21 bytes)

/* Menu item ex010210 HCUT SLOPE: on_draw (#74) */

void menu_ex010210_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_hcut_slope(param_1,g_opstate.ex010210_hcut_slope,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010211_draw @ fffca503 (22 bytes)

/* Menu item ex010211 USB OUT LEVEL: on_draw (#74) */

void menu_ex010211_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_out_level(param_1,g_opstate.ex010211_usb_out_level,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010212_draw @ fffca519 (22 bytes)

/* Menu item ex010212 REAR OUT LEVEL: on_draw (#74) */

void menu_ex010212_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_out_level(param_1,g_opstate.ex010212_rear_out_level,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010213_draw @ fffca52f (21 bytes)

/* Menu item ex010213 TX BPF SEL: on_draw (#74) */

void menu_ex010213_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_tx_bpf_sel(param_1,g_opstate.ex010213_tx_bpf_sel,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010214_draw @ fffca544 (21 bytes)

/* Menu item ex010214 MOD SOURCE: on_draw (#74) */

void menu_ex010214_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_mod_source(param_1,g_opstate.ex010214_mod_source,3,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010215_draw @ fffca559 (22 bytes)

/* Menu item ex010215 USB MOD GAIN: on_draw (#74) */

void menu_ex010215_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_usb_mod_gain(param_1,g_opstate.ex010215_usb_mod_gain,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010216_draw @ fffca56f (22 bytes)

/* Menu item ex010216 REAR MOD GAIN: on_draw (#74) */

void menu_ex010216_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_rear_mod_gain(param_1,g_opstate.ex010216_rear_mod_gain,0x32,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010217_draw @ fffca585 (21 bytes)

/* Menu item ex010217 RPTT SELECT: on_draw (#74) */

void menu_ex010217_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_rptt_select(param_1,g_opstate.ex010217_rptt_select,0,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010301_draw @ fffca59a (24 bytes)

/* Menu item ex010301 AF TREBLE GAIN: on_draw (#74) */

void menu_ex010301_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex010301_af_treble_gain);
  return;
}


// ===== menu_ex010302_draw @ fffca5b2 (24 bytes)

/* Menu item ex010302 AF MIDDLE TONE GAIN: on_draw (#74) */

void menu_ex010302_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex010302_af_middle_tone_gain);
  return;
}


// ===== menu_ex010303_draw @ fffca5ca (24 bytes)

/* Menu item ex010303 AF BASS GAIN: on_draw (#74) */

void menu_ex010303_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex010303_af_bass_gain);
  return;
}


// ===== menu_ex010304_draw @ fffca5e2 (22 bytes)

/* Menu item ex010304 AGC FAST DELAY: on_draw (#74) */

void menu_ex010304_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  menu_draw_agc_delay(param_1,g_opstate.ex010304_agc_fast_delay,0xa0,param_4,param_5,param_1);
  return;
}

