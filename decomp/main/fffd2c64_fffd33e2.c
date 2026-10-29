// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
    local_b = DAT_00009bc3;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b66;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b85;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba4;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b47;
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
  char local_b;
  
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
    local_b = DAT_00009bc4;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b67;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b86;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba5;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b48;
  }
  if (local_b == '2') {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xc;
  param_2[2] = 0;
  FUN_fff9c6f0(local_b,param_2 + 0x18);
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
  char local_b;
  
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
    local_b = DAT_00009bc5;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b68;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b87;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba6;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b49;
  }
  if (local_b == '2') {
    *param_2 = *param_2 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_2 = *param_2 | 0x40;
  }
  param_2[1] = 0xd;
  param_2[2] = 0;
  FUN_fff9c6f0(local_b,param_2 + 0x18);
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
    local_b = DAT_00009bc6;
  }
  else if (param_1 == 2) {
    local_b = DAT_00009b69;
  }
  else if (param_1 == 3) {
    local_b = DAT_00009b88;
  }
  else if (param_1 == 4) {
    local_b = DAT_00009ba7;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_b = DAT_00009b4a;
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
  undefined4 *puStack_8;
  
  cVar1 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  if (cVar1 == '\x1a') {
    puStack_8 = &DAT_00009baa;
  }
  else if (cVar1 == '\x17') {
    puStack_8 = &DAT_00009b4d;
  }
  else if (cVar1 == '\x18') {
    puStack_8 = &DAT_00009b6c;
  }
  else if (cVar1 == '\x19') {
    puStack_8 = &DAT_00009b8b;
  }
  else if (cVar1 == '\x16') {
    puStack_8 = &DAT_00009b2e;
  }
  else {
    puStack_8 = &DAT_00009b2e;
  }
  return (uint)puStack_8;
}


// ===== menu_ex060101_enter @ fffd3172 (113 bytes)

/* Menu item ex060101 PRESET NAME: on_enter; also ex060201, ex060301, ex060401, ex060501 (#74) */

void menu_ex060101_enter(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_fffd30e8();
  PTR_DAT_00025d60[0x90] = 1;
  PTR_DAT_00025d60[0xbe] = 6;
  PTR_DAT_00025d60[0xc1] = 0;
  puVar1 = PTR_DAT_00025d60;
  *(undefined4 *)(PTR_DAT_00025d60 + 0xca) = 0x20202020;
  *(undefined4 *)(puVar1 + 0xc6) = 0x20202020;
  *(undefined4 *)(puVar1 + 0xc2) = 0x20202020;
  puVar1 = PTR_DAT_00025d60;
  *(undefined4 *)(PTR_DAT_00025d60 + 0xca) = puVar2[2];
  *(undefined4 *)(puVar1 + 0xc6) = puVar2[1];
  *(undefined4 *)(puVar1 + 0xc2) = *puVar2;
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
    local_8 = &DAT_00009bb6;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b59;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b78;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b97;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b3a;
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
    local_8 = &DAT_00009bb7;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b5a;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b79;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b98;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b3b;
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


// ===== FUN_fffd3346 @ fffd3346 (132 bytes)

void FUN_fffd3346(byte param_1)

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
    local_8 = &DAT_00009bb8;
  }
  else if (param_1 == 2) {
    local_8 = &DAT_00009b5b;
  }
  else if (param_1 == 3) {
    local_8 = &DAT_00009b7a;
  }
  else if (param_1 == 4) {
    local_8 = &DAT_00009b99;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    local_8 = &DAT_00009b3c;
  }
  menu_step_u8(0,1,local_8);
  return;
}


// ===== menu_ex060105_step @ fffd33ca (6 bytes)

/* Menu item ex060105 AGC FAST DELAY: on_step (#74) */

void menu_ex060105_step(void)

{
  FUN_fffd33e8(1);
  return;
}


// ===== menu_ex060205_step @ fffd33d0 (6 bytes)

/* Menu item ex060205 AGC FAST DELAY: on_step (#74) */

void menu_ex060205_step(void)

{
  FUN_fffd33e8(2);
  return;
}


// ===== menu_ex060305_step @ fffd33d6 (6 bytes)

/* Menu item ex060305 AGC FAST DELAY: on_step (#74) */

void menu_ex060305_step(void)

{
  FUN_fffd33e8(3);
  return;
}


// ===== menu_ex060405_step @ fffd33dc (6 bytes)

/* Menu item ex060405 AGC FAST DELAY: on_step (#74) */

void menu_ex060405_step(void)

{
  FUN_fffd33e8(4);
  return;
}


// ===== menu_ex060505_step @ fffd33e2 (6 bytes)

/* Menu item ex060505 AGC FAST DELAY: on_step (#74) */

void menu_ex060505_step(void)

{
  FUN_fffd33e8(5);
  return;
}

