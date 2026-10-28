// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== send_a_set @ fffb6fd2 (63 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7007) */
/* PA2 SEND_A, forced 0 if ETUN_TXINH_REQ or TX line low */

void send_a_set(byte param_1)

{
  byte bVar1;
  bool bVar2;
  byte local_1;
  
  bVar1 = DAT_0008c041;
  if (((bVar1 >> 4 & 1) == 1) || (bVar1 = DAT_0008c027, (bVar1 & 8) == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_1 = param_1;
  if (bVar2) {
    local_1 = 0;
  }
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xfb | (local_1 & 1) << 2;
  return;
}


// ===== send_b_set @ fffb7011 (64 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7046) */
/* PB4 SEND_B, same gating */

void send_b_set(byte param_1)

{
  byte bVar1;
  bool bVar2;
  byte local_1;
  
  bVar1 = DAT_0008c041;
  if (((bVar1 >> 4 & 1) == 1) || (bVar1 = DAT_0008c027, (bVar1 & 8) == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_1 = param_1;
  if (bVar2) {
    local_1 = 0;
  }
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xef | (local_1 & 1) << 4;
  return;
}


// ===== sdr_reset_set @ fffb7051 (22 bytes)

/* P77 */

void sdr_reset_set(char param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0x7f | param_1 << 7;
  return;
}


// ===== sdr_update_set @ fffb7067 (25 bytes)

/* P76 */

void sdr_update_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xbf | (param_1 & 1) << 6;
  return;
}


// ===== dsp_reset_set @ fffb7080 (24 bytes)

/* P71 */

void dsp_reset_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xfd | (param_1 & 1) << 1;
  return;
}


// ===== dsp_update_set @ fffb7098 (24 bytes)

/* P72 */

void dsp_update_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== af_reset_set @ fffb70b0 (25 bytes)

/* P74 */

void af_reset_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xef | (param_1 & 1) << 4;
  return;
}


// ===== pa_pon_set @ fffb70c9 (22 bytes)

/* PC0 PA_PON */

void pa_pon_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02c;
  DAT_0008c02c = bVar1 & 0xfe | param_1 & 1;
  return;
}


// ===== tun_lin_sel_set @ fffb70df (24 bytes)

/* P83 */

void tun_lin_sel_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c028;
  DAT_0008c028 = bVar1 & 0xf7 | (param_1 & 1) << 3;
  return;
}


// ===== rem_key_sel_set @ fffb70f7 (25 bytes)

/* P86 */

void rem_key_sel_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c028;
  DAT_0008c028 = bVar1 & 0xbf | (param_1 & 1) << 6;
  return;
}


// ===== gpo_a_dir_out @ fffb7110 (12 bytes)

/* PDR P13 */

void gpo_a_dir_out(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c001;
  DAT_0008c001 = bVar1 | 8;
  return;
}


// ===== gpo_b_dir_out @ fffb711c (12 bytes)

/* PDR P12 */

void gpo_b_dir_out(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c001;
  DAT_0008c001 = bVar1 | 4;
  return;
}


// ===== gpo_c_dir @ fffb7128 (37 bytes)

/* PDR P50 */

void gpo_c_dir(char param_1)

{
  byte bVar1;
  
  if (param_1 != '\0') {
    bVar1 = DAT_0008c005;
    DAT_0008c005 = bVar1 | 1;
    return;
  }
  bVar1 = DAT_0008c005;
  DAT_0008c005 = bVar1 & 0xfe;
  return;
}


// ===== gpo_a_set @ fffb714d (24 bytes)

/* P13 */

void gpo_a_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c021;
  DAT_0008c021 = bVar1 & 0xf7 | (param_1 & 1) << 3;
  return;
}


// ===== gpo_b_set @ fffb7165 (24 bytes)

/* P12 */

void gpo_b_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c021;
  DAT_0008c021 = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== gpo_c_set @ fffb717d (22 bytes)

/* P50 */

void gpo_c_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c025;
  DAT_0008c025 = bVar1 & 0xfe | param_1 & 1;
  return;
}


// ===== gpo_d_set @ fffb7193 (24 bytes)

/* P22 */

void gpo_d_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = DAT_0008c022;
  DAT_0008c022 = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== gpo_a_get @ fffb71ab (19 bytes)

byte gpo_a_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c021;
  return bVar1 >> 3 & 1;
}


// ===== gpo_b_get @ fffb71be (19 bytes)

byte gpo_b_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c021;
  return bVar1 >> 2 & 1;
}


// ===== gpo_c_get @ fffb71d1 (17 bytes)

byte gpo_c_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c025;
  return bVar1 & 1;
}


// ===== gpo_d_get @ fffb71e2 (19 bytes)

byte gpo_d_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c022;
  return bVar1 >> 2 & 1;
}


// ===== FUN_fffb71f5 @ fffb71f5 (10 bytes)

void FUN_fffb71f5(void)

{
  DAT_0001204e = 1;
  return;
}


// ===== etun_reset_set @ fffb71ff (27 bytes)

/* P22 inverted */

void etun_reset_set(char param_1)

{
  byte bVar1;
  
  if (param_1 != '\0') {
    bVar1 = DAT_0008c022;
    DAT_0008c022 = bVar1 & 0xfb;
    return;
  }
  bVar1 = DAT_0008c022;
  DAT_0008c022 = bVar1 | 4;
  return;
}


// ===== rx_line_get @ fffb721a (17 bytes)

/* PB7 RX */

byte rx_line_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02b;
  return bVar1 >> 7;
}


// ===== af_mute_get @ fffb722b (24 bytes)

/* PB3 */

bool af_mute_get(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02b;
  return (bVar1 & 8) != 0;
}


// ===== af_mute_set @ fffb7243 (199 bytes)

/* AF_MUTE (PB3) */

void af_mute_set(char param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char local_1;
  
  iVar3 = audio_route_state();
  if ((iVar3 - 4U < 2) || (local_1 = param_1, iVar3 == 0xb || iVar3 == 0xc)) {
    local_1 = '\0';
  }
  iVar3 = swtimer_expired(0x2a);
  if (iVar3 == 0) {
    bVar1 = DAT_0008c02b;
    if ((bVar1 & 8) == 0) {
      bVar1 = DAT_0008c02b;
      DAT_0008c02b = bVar1 | 8;
    }
    if (DAT_0001204f == '\0') {
      if ((DAT_00020b18 == '\b') || (DAT_00020b18 == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if (local_1 == '\0') {
          DAT_00020b44 = 0;
          return;
        }
        DAT_00020b44 = 1;
        return;
      }
    }
  }
  else if (local_1 == '\0') {
    bVar1 = DAT_0008c02b;
    DAT_0008c02b = bVar1 & 0xf7;
    if (DAT_00020b18 == '\b') {
      DAT_00020b44 = 0;
      return;
    }
  }
  else {
    bVar1 = DAT_0008c02b;
    DAT_0008c02b = bVar1 | 8;
    if (DAT_00020b18 == '\b') {
      DAT_00020b44 = 1;
      return;
    }
  }
  return;
}


// ===== ear_det @ fffb730a (24 bytes)

/* PF5 low */

bool ear_det(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c04f;
  return (bVar1 & 0x20) == 0;
}


// ===== speaker_switch_set @ fffb7322 (132 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7384) */
/* WARNING: Removing unreachable block (ram,0xfffb739a) */
/* route 0:INT_SP_SW 1:EAR_SW 2:INT+EXT 3:EXT_SP_SW */

void speaker_switch_set(byte param_1)

{
  byte bVar1;
  
  if (DAT_00020fcc == 3) {
    bVar1 = DAT_0008c02b;
    DAT_0008c02b = bVar1 & 0xfb | (param_1 & 1) << 2;
    return;
  }
  if (DAT_00020fcc == 1) {
    bVar1 = DAT_0008c028;
    DAT_0008c028 = bVar1 & 0xfe | param_1 & 1;
    return;
  }
  if (DAT_00020fcc == 2) {
    bVar1 = DAT_0008c027;
    DAT_0008c027 = bVar1 & 0xfe | param_1 & 1;
    bVar1 = DAT_0008c02b;
    DAT_0008c02b = bVar1 & 0xfb | (param_1 & 1) << 2;
    return;
  }
  if (DAT_00020fcc != 0) {
    return;
  }
  bVar1 = DAT_0008c027;
  DAT_0008c027 = bVar1 & 0xfe | param_1 & 1;
  return;
}


// ===== power_off_io @ fffb73a6 (55 bytes)

/* Power-down: clears several port bits, stops SCI5 [inference] */

void power_off_io(void)

{
  byte bVar1;
  
  pa_pon_set(0);
  sdr_update_set(0);
  tun_lin_sel_set(0);
  bVar1 = DAT_0008c02c;
  DAT_0008c02c = bVar1 & 0xef;
  R_SCI5_Stop();
  bVar1 = DAT_0008c02c;
  DAT_0008c02c = bVar1 & 0xf7;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0x7f;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xdf;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0x7f;
  return;
}


// ===== meter_task @ fffb73dd (65 bytes)

/* 5 ms: ADC scan + SWR; 10 ms: VDD IDD ALC PO COMP S remote-keypad */

void meter_task(void)

{
  int iVar1;
  
  iVar1 = swtimer_expired(9);
  if (iVar1 == 1) {
    swtimer_start(9,5);
    adc_scan_blocking();
    swr_meter_protect();
  }
  iVar1 = swtimer_expired(10);
  if (iVar1 == 1) {
    swtimer_start(10,10);
    meter_vdd();
    meter_idd();
    meter_alc();
    meter_po();
    meter_comp();
    meter_s();
    remote_keypad_scan();
    return;
  }
  return;
}


// ===== adc_scan_blocking @ fffb741e (13 bytes)

void adc_scan_blocking(void)

{
  int iVar1;
  
  adc_scan_start();
  do {
    iVar1 = adc_scan_done();
  } while (iVar1 != 1);
  return;
}


// ===== vdd_scale_calc @ fffb742b (81 bytes)

/* cal 0x4659, 0x4667 */

void vdd_scale_calc(void)

{
  DAT_00020fc0 = ((float)DAT_00004659 / 192.0) * (0.07176471 / (13.8 / (float)DAT_00004667));
  return;
}


// ===== meter_vdd @ fffb747c (60 bytes)

/* AN003 -> 0x12043 */

void meter_vdd(void)

{
  ushort uVar1;
  float fVar2;
  undefined1 uStack_4;
  
  uVar1 = DAT_00020b08 >> 4;
  vdd_scale_calc();
  fVar2 = ROUND((float)(byte)uVar1 * DAT_00020fc0);
  uStack_4 = SUB41(fVar2,0);
  if (0xff < ((uint)fVar2 & 0xffff)) {
    uStack_4 = 0xff;
  }
  DAT_00012043 = FUN_fffb92e7(uStack_4);
  return;
}


// ===== meter_idd @ fffb74b8 (71 bytes)

/* AN007 -> 0x12044 (cal 0x475D) */

void meter_idd(void)

{
  uint uVar1;
  int in_stack_0000000c;
  undefined1 local_6;
  
  uVar1 = (uint)(byte)(DAT_00020b0e >> 4) * in_stack_0000000c;
  if (DAT_0000475d != 0) {
    uVar1 = uVar1 / DAT_0000475d;
  }
  local_6 = (undefined1)uVar1;
  if (0xff < (uVar1 & 0xffff)) {
    local_6 = 0xff;
  }
  DAT_00012044 = FUN_fffb9350(local_6);
  return;
}


// ===== meter_alc @ fffb74ff (70 bytes)

/* AN005 -> 0x12045 (cal 0x474E) */

void meter_alc(void)

{
  uint uVar1;
  int in_stack_0000000c;
  undefined1 local_6;
  
  uVar1 = (uint)(byte)(DAT_00020b0c >> 4) * in_stack_0000000c;
  if (DAT_0000474e != 0) {
    uVar1 = uVar1 / DAT_0000474e;
  }
  local_6 = (undefined1)uVar1;
  if (0xff < (uVar1 & 0xffff)) {
    local_6 = 0xff;
  }
  DAT_00012045 = FUN_fffb93b9(local_6);
  return;
}


// ===== swr_meter_protect @ fffb7545 (557 bytes)

/* SWR=(1+r)/(1-r), r=AN001/AN002; outside [1,5) for 9 passes while TX -> 0x20B6D (HI-SWR) */

void swr_meter_protect(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  undefined1 uStack_22;
  float fStack_20;
  float fStack_1c;
  float local_18;
  
  uVar7 = (uint)DAT_00020b04;
  uVar2 = (uint)DAT_00020b06;
  uVar3 = (uint)DAT_00004669;
  fStack_20 = (float)DAT_0000466a;
  uVar4 = (uint)DAT_0000466b;
  fVar5 = (float)uVar7 / (float)uVar2;
  local_18 = (fVar5 + 1.0) / (1.0 - fVar5);
  if (DAT_00020b6b != '\0') {
    if ((local_18 - 1.0 < 0.0) || (0.0 <= local_18 - 5.0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_0001b4c7 < 9) {
        bVar1 = SCARRY4((uint)DAT_0001b4c7,1);
        DAT_0001b4c7 = DAT_0001b4c7 + 1;
      }
      else {
        iVar6 = blink_phase(1);
        bVar1 = false;
        if (iVar6 == 0) {
          DAT_00020b6d = 1;
        }
        else {
          DAT_00020b6d = 2;
        }
      }
      DAT_0001b4c6 = 0;
    }
    else {
      bVar1 = SBORROW4((uint)DAT_0001b4c6,8);
      if (DAT_0001b4c6 < 9) {
        bVar1 = SCARRY4((uint)DAT_0001b4c6,1);
        DAT_0001b4c6 = DAT_0001b4c6 + 1;
      }
      else {
        DAT_00020b6d = 0;
      }
      DAT_0001b4c7 = 0;
    }
    if ((10.0 < (float)uVar7 == bVar1) && (10.0 < (float)uVar2 == bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (local_18 - 1.0 < 0.0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    uVar7 = 0;
    if (bVar1) {
      DAT_00020b6d = 0;
      uVar7 = (uint)SBORROW4((uint)DAT_00020b41,2) << 3;
      if (DAT_00020b41 == 2) {
        local_18 = 255.0;
      }
      else {
        local_18 = 1.0;
      }
    }
    DAT_00020fc4 = local_18;
    FUN_fffb948b(local_18);
    if (1.5 < local_18 == (bool)((byte)(uVar7 >> 3) & 1)) {
      fStack_1c = (float)uVar3 / 1.5;
      fStack_20 = -fStack_1c;
    }
    else {
      if ((local_18 <= 1.5) || (2.0 < local_18 != (bool)((byte)(uVar7 >> 3) & 1))) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        fStack_1c = (fStack_20 - (float)uVar3) / 0.5;
        fStack_20 = fStack_1c * -2.0 + fStack_20;
      }
      else {
        fStack_1c = ((float)uVar4 - fStack_20) / 1.0;
        fStack_20 = fStack_1c * -3.0 + (float)uVar4;
      }
    }
    fVar5 = ROUND(fStack_1c * local_18 + fStack_20);
    uStack_22 = SUB41(fVar5,0);
    if (0xff < ((uint)fVar5 & 0xffff)) {
      uStack_22 = 0xff;
    }
    DAT_00012047 = uStack_22;
    DAT_00012046 = FUN_fffb9422(uStack_22);
    return;
  }
  DAT_00020b6d = 0;
  return;
}


// ===== meter_po @ fffb7772 (247 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7794) */
/* AN002 -> 0x12048 (table 0xFFF88C74) */

void meter_po(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  byte bStack_2d;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  fVar2 = (float)DAT_00020b06;
  fVar3 = (float)((DAT_00020b1e & 0xf) << 4);
  cVar1 = FUN_fffb3371(DAT_00020f50);
  if (cVar1 == '\n') {
    fStack_28 = 50.0;
  }
  else {
    fStack_28 = 100.0;
  }
  fVar2 = fVar2 * (((fStack_28 - fVar3 * 0.00694025) - 0.0) / (fVar3 * fVar3)) * fVar2 +
          fVar2 * 0.00694025 + 0.0;
  bStack_2d = 0;
  do {
    if (7 < bStack_2d) {
LAB_fffb7837:
      fStack_1c = fStack_20 * fVar2 + fStack_24;
      if (255.0 < fStack_1c) {
        fStack_1c = 255.0;
      }
      DAT_00012048 = FUN_fffb94f9((uint)ROUND(fStack_1c) & 0xff);
      return;
    }
    iVar4 = (uint)bStack_2d * 0xc;
    if (fVar2 < *(float *)(&DAT_fff88c74 + iVar4) == SCARRY4(iVar4,-0x7738c)) {
      fStack_20 = *(float *)(&DAT_fff88c78 + (uint)bStack_2d * 0xc);
      fStack_24 = *(float *)(&DAT_fff88c7c + (uint)bStack_2d * 0xc);
      goto LAB_fffb7837;
    }
    bStack_2d = bStack_2d + 1;
  } while( true );
}


// ===== meter_comp @ fffb7869 (240 bytes)

/* DSP value -> 0x12049 [inference] */

void meter_comp(void)

{
  uint uVar1;
  float fVar2;
  uint uVar3;
  undefined1 uStack_1a;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uVar3 = 0;
  if (DAT_00009bf1 == '\0') {
    uVar1 = dsp_comp_level();
    uVar1 = uVar1 >> 8;
    uVar3 = uVar3 & 0xfffffff8;
  }
  else {
    uVar1 = dsp_comp_level();
  }
  uStack_10 = (float)(uVar1 & 0xff);
  if (10.0 < uStack_10 == (bool)((byte)(uVar3 >> 3) & 1)) {
    uStack_14 = 10.3;
    uStack_18 = 0.0;
  }
  else if (20.0 < uStack_10 == (bool)((byte)(uVar3 >> 3) & 1)) {
    uStack_14 = 8.7;
    uStack_18 = 16.0;
  }
  else {
    uStack_14 = 5.8;
    if (30.0 < uStack_10 == (bool)((byte)(uVar3 >> 3) & 1)) {
      uStack_18 = 74.0;
    }
    else {
      uStack_18 = 75.2;
    }
  }
  fVar2 = ROUND((uStack_14 * uStack_10) / 2.0 + uStack_18);
  uStack_1a = SUB41(fVar2,0);
  if (0xff < ((uint)fVar2 & 0xffff)) {
    uStack_1a = 0xff;
  }
  DAT_00012049 = uStack_1a;
  return;
}


// ===== meter_s @ fffb7959 (231 bytes)

/* DSP value vs cal 0x4681 -> 0x1204A */

void meter_s(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  byte bStack_1a;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  
  uVar1 = (uint)DAT_00004681;
  bVar2 = dsp_signal_level();
  iVar3 = swtimer_expired(0x2a);
  if (iVar3 == 0) {
    return;
  }
  fStack_c = 1.95;
  fStack_10 = 177.0;
  bStack_1a = 0;
  do {
    if (9 < bStack_1a) {
LAB_fffb79e0:
      fStack_18 = ((float)uVar1 - (float)bVar2) * fStack_c + fStack_10;
      if (fStack_18 - 0.0 < 0.0) {
        fStack_18 = 0.0;
      }
      else if (255.0 < fStack_18) {
        fStack_18 = 255.0;
      }
      if (DAT_00020b3d != '\0') {
        DAT_0001204a = 0;
        return;
      }
      DAT_0001204a = FUN_fffb959c((uint)ROUND(fStack_18) & 0xff);
      return;
    }
    iVar3 = (uint)bStack_1a * 0xc;
    if (*(float *)(&DAT_fff88c04 + iVar3) < (float)uVar1 - (float)bVar2 == SCARRY4(iVar3,-0x77404))
    {
      fStack_c = *(float *)(&DAT_fff88bfc + (uint)bStack_1a * 0xc);
      fStack_10 = *(float *)(&DAT_fff88c00 + (uint)bStack_1a * 0xc);
      goto LAB_fffb79e0;
    }
    bStack_1a = bStack_1a + 1;
  } while( true );
}


// ===== remote_keypad_scan @ fffb7a40 (259 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7a58) */
/* WARNING: Removing unreachable block (ram,0xfffb7a67) */
/* AN108 REM_KEY: 12 voltage windows (0xFFF815AB) -> key 0x1204C */

void remote_keypad_scan(void)

{
  bool bVar1;
  byte bVar2;
  byte local_3;
  
  bVar2 = (byte)(DAT_00020b10 >> 4);
  local_3 = 0;
  do {
    if (0xb < local_3) {
LAB_fffb7abb:
      if (0xb < local_3) {
        DAT_0001b4c8 = 0;
        DAT_0001b4c9 = 0;
        DAT_0001204c = 0;
        return;
      }
      if (DAT_0001b4c8 == 2) {
        cat_apo_reset();
        if (DAT_00020b86 == '\0') {
          DAT_0001204c = DAT_0001b4c9;
        }
      }
      else if (DAT_0001b4c8 == 100) {
        DAT_0001204c = DAT_0001204c | 0xf0;
      }
      if (100 < DAT_0001b4c8) {
        return;
      }
      DAT_0001b4c8 = DAT_0001b4c8 + 1;
      return;
    }
    if (((byte)(&DAT_fff815ab)[(uint)local_3 * 2] < bVar2) &&
       (bVar2 < (byte)(&DAT_fff815ac)[(uint)local_3 * 2])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_0001b4c9 != (byte)(local_3 + 1)) {
        DAT_0001b4c9 = local_3 + 1;
      }
      goto LAB_fffb7abb;
    }
    local_3 = local_3 + 1;
  } while( true );
}


// ===== io_poll @ fffb7b43 (34 bytes)

/* after timer 0x13: PTT inputs, TRX sequencer, TX audio select, speaker route, AF mute, band data,
   keying */

void io_poll(void)

{
  int iVar1;
  
  iVar1 = swtimer_expired(0x13);
  if (iVar1 != 1) {
    return;
  }
  ptt_inputs_read();
  trx_sequencer();
  tx_audio_select();
  speaker_route();
  af_mute_update();
  linear_band_data();
  FUN_fffb915e();
  return;
}


// ===== af_mute_update @ fffb7b65 (391 bytes)

void af_mute_update(void)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = vfo_rec_ptr(DAT_00020b6b);
  cVar3 = DAT_00009ab6;
  bVar1 = *(byte *)(iVar4 + 3);
  iVar4 = swtimer_expired(0x2a);
  if (iVar4 != 0) {
    if (DAT_00020b18 == '\b') {
      if (DAT_0001b4ca != cVar3) {
        DAT_0001b4ca = cVar3;
        iVar4 = af_mute_get();
        if (iVar4 != 0) {
          af_mute_set(0);
        }
        DAT_00020b48 = 0;
        swtimer_start(0x2a,0x32);
        DAT_0001204f = 1;
        af_mute_set(1);
        DAT_0001204f = 0;
        return;
      }
      iVar4 = audio_route_state();
      if (((iVar4 - 4U < 2) || (iVar4 == 0xb || iVar4 == 0xc)) &&
         (iVar4 = af_mute_get(), iVar4 != 0)) {
        af_mute_set(0);
      }
      if ((char)((bVar1 & 0x38) >> 3) == '\x02') {
        iVar4 = vfo_mode(0);
        if ((iVar4 - 6U < 2) || (iVar4 == 10 || iVar4 == 0xb)) {
          iVar4 = dsp_tone_detect();
          if (iVar4 == 0) {
            DAT_00020b48 = '\0';
            iVar4 = af_mute_get();
            if (iVar4 == 0) {
              af_mute_set(1);
            }
          }
          else {
            DAT_00020b48 = '\x01';
            iVar4 = af_mute_get();
            if (iVar4 != 0) {
              af_mute_set(0);
            }
          }
        }
        else {
          iVar4 = af_mute_get();
          if (iVar4 != 0) {
            af_mute_set(0);
          }
        }
      }
      else {
        if (cVar3 == '\0') {
          bVar1 = DAT_0008c022;
          DAT_0008c022 = bVar1 & 0xef;
          iVar4 = af_mute_get();
          if (iVar4 == 0) {
            return;
          }
          af_mute_set(0);
          DAT_00020b48 = 0;
          return;
        }
        FUN_fffb7cec();
        if (cVar3 == '\x01') {
          FUN_fffb7e61();
        }
      }
      if (DAT_00020b48 != '\x01') {
        bVar1 = DAT_0008c022;
        DAT_0008c022 = bVar1 | 0x10;
        return;
      }
      bVar1 = DAT_0008c022;
      DAT_0008c022 = bVar1 & 0xef;
      return;
    }
    bVar1 = DAT_0008c022;
    DAT_0008c022 = bVar1 | 0x10;
    iVar4 = af_mute_get();
    if ((iVar4 == 0) || (DAT_00020b18 != '\x03')) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      af_mute_set(0);
      return;
    }
  }
  return;
}


// ===== FUN_fffb7cec @ fffb7cec (373 bytes)

void FUN_fffb7cec(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  float fStack_1c;
  float fStack_18;
  float fStack_8;
  
  bVar2 = vfo_mode(0);
  bVar3 = DAT_00004687;
  if ((((bVar2 == 0xb) || (bVar2 == 7)) || (bVar3 = DAT_00004686, bVar2 == 10)) || (bVar2 == 6)) {
    fStack_8 = (float)bVar3;
    fStack_18 = (float)DAT_00004688;
    if (DAT_00020ba7 < 0x19) {
      fStack_18 = 256.0;
      fStack_1c = 0.0;
    }
    else if (DAT_00020ba7 < 0x32) {
      fStack_18 = fStack_8;
      fStack_1c = 30.0;
    }
    else if (DAT_00020ba7 < 0xfa) {
      fStack_18 = (float)DAT_00020ba7 * ((fStack_8 - fStack_18) / -200.0) +
                  (fStack_8 * 5.0 - fStack_18) / 4.0;
      if (DAT_00020ba7 < 100) {
        fStack_1c = 15.0;
      }
      else if (DAT_00020ba7 < 0x96) {
        fStack_1c = 22.0;
      }
      else if (DAT_00020ba7 < 200) {
        fStack_1c = 25.0;
      }
      else {
        fStack_1c = 30.0;
      }
    }
    else {
      fStack_1c = 25.0;
    }
    DAT_0001b4cb = bVar2;
    bVar3 = dsp_fm_noise();
    if ((float)bVar3 < fStack_18) {
      DAT_00020b48 = 1;
      iVar4 = af_mute_get();
      if (iVar4 != 0) {
        af_mute_set(0);
        return;
      }
    }
    else if (fStack_18 + fStack_1c < (float)bVar3) {
      DAT_00020b48 = 0;
      iVar4 = af_mute_get();
      if (iVar4 == 0) {
        af_mute_set(1);
        return;
      }
    }
  }
  else {
    uVar1 = (uint)DAT_0001b4cb;
    if (((uVar1 - 6 < 2) || (uVar1 == 10 || uVar1 == 0xb)) &&
       (DAT_0001b4cb = bVar2, iVar4 = af_mute_get(), iVar4 != 0)) {
      af_mute_set(0);
      return;
    }
  }
  return;
}


// ===== FUN_fffb7e61 @ fffb7e61 (270 bytes)

void FUN_fffb7e61(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  float fStack_24;
  float fStack_20;
  
  uVar1 = (uint)DAT_00004681;
  uVar3 = vfo_mode(0);
  if (((uVar3 < 6) || (uVar3 - 8 < 2)) || (uVar3 - 0xc < 3)) {
    fVar4 = (float)uVar1 + 110.0;
    fStack_20 = (float)uVar1 + 80.0;
    if (DAT_00020ba7 < 0x19) {
      fStack_20 = 256.0;
      fStack_24 = 0.0;
    }
    else if (DAT_00020ba7 < 0xf0) {
      fStack_20 = (float)DAT_00020ba7 * ((fStack_20 - fVar4) / 216.0) +
                  (fVar4 * 240.0 - fStack_20 * 24.0) / 216.0;
      fStack_24 = 6.0;
    }
    else {
      fStack_24 = 6.0;
    }
    bVar2 = dsp_signal_level();
    if ((float)bVar2 < fStack_20) {
      DAT_00020b48 = 1;
      iVar5 = af_mute_get();
      if (iVar5 != 0) {
        af_mute_set(0);
        return;
      }
    }
    else if (fStack_20 + fStack_24 < (float)bVar2) {
      DAT_00020b48 = 0;
      iVar5 = af_mute_get();
      if (iVar5 == 0) {
        af_mute_set(1);
        return;
      }
    }
  }
  return;
}


// ===== ptt_inputs_read @ fffb7f6f (394 bytes)

/* DATA_PTT/RTS/DTR/EXTPA_TXREQ/VOX -> 0x20B24..0x20B29 */

void ptt_inputs_read(void)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  byte bStack_5;
  byte bStack_4;
  char cStack_2;
  
  bVar3 = vfo_mode(1);
  cStack_2 = FUN_fffb50d7(bVar3);
  cVar4 = FUN_fffba192();
  DAT_00020b24 = 0;
  DAT_00020b26 = 0;
  DAT_00020b27 = 0;
  DAT_00020b29 = 0;
  bVar1 = DAT_0008c041;
  DAT_00020b25 = (bVar1 & 0x20) == 0;
  if (cVar4 == '\0') {
    bStack_5 = 1;
  }
  else {
    bStack_5 = 2;
  }
  for (bStack_4 = 0; bStack_4 < bStack_5; bStack_4 = bStack_4 + 1) {
    if (cVar4 == '\x01') {
      if ((bStack_4 == 1) && (cStack_2 == '\0')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        cStack_2 = DAT_00009a9f;
      }
    }
    else if (bStack_4 == 1) {
      cStack_2 = DAT_00009a9f;
    }
    if ((cStack_2 == '\x03') && (bVar1 = DAT_0008c042, (bVar1 & 1) == 0)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      DAT_00020b24 = 1;
joined_r0xfffb8040:
      if (cVar4 == '\x01') break;
    }
    else {
      bVar1 = DAT_0008c047;
      if ((bVar1 >> 5 & 1) == 1) {
        if ((cStack_2 == '\x01') && (bVar1 = DAT_0008c04c, (bVar1 & 0x40) == 0)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          DAT_00020b26 = 1;
        }
        else {
          if ((cStack_2 == '\x02') && (bVar1 = DAT_0008c04c, (bVar1 & 0x20) == 0)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (!bVar2) goto LAB_fffb80ab;
          DAT_00020b27 = 1;
        }
        goto joined_r0xfffb8040;
      }
    }
LAB_fffb80ab:
  }
  if ((((1 < bVar3 - 2) && (1 < bVar3 - 0xc)) && (DAT_00009c5d != '\0')) &&
     ((uVar5 = dsp_status1_raw(), (uVar5 & 0x10) != 0 && (iVar6 = swtimer_expired(0x2f), iVar6 == 1)
      ))) {
    DAT_00020b29 = 1;
    return;
  }
  return;
}


// ===== trx_sequencer @ fffb80f9 (1193 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb812b) */
/* trx_state 0x20B18 machine: RX->TX (0..3), TX->RX (4..8) */

void trx_sequencer(void)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  undefined1 uStack_9;
  
  uVar3 = DAT_00020f50;
  uStack_9 = FUN_fffb548a();
  cVar1 = DAT_00009aa1;
  cVar4 = FUN_fffba192();
  bVar5 = cVar1 * '\x02' + 4;
  ptt_arbiter();
  iVar6 = FUN_fffb521a();
  if (iVar6 == 1) {
    if (DAT_0001204d == '\a') {
      uStack_9 = 0;
    }
    else if ((DAT_0001204d == '\b' || DAT_0001204d == '\t') && (iVar6 = ckey_det(), iVar6 != 0)) {
      if ((cVar4 == '\0') || (cVar4 == '\x02')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (!bVar2) {
        uStack_9 = 0;
      }
    }
  }
  if (DAT_00020b18 == '\0') {
    iVar6 = tx_freq_allowed(uVar3);
    if (iVar6 != 0) {
      DAT_00020b18 = '\x01';
      swtimer_start(0xc,1);
      swtimer_start(0xd,1);
      swtimer_start(0xe,5);
      swtimer_start(0xf,1);
      swtimer_start(0x10,3);
      swtimer_start(0x11,uStack_9);
    }
    DAT_00020b19 = '\0';
    DAT_00020b1a = '\0';
  }
  else if (DAT_00020b18 == '\x01') {
    bVar5 = DAT_0008c022;
    if (((bVar5 & 0x10) == 0) && (iVar6 = swtimer_expired(0xc), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar5 = DAT_0008c022;
      DAT_0008c022 = bVar5 | 0x10;
    }
    iVar6 = af_mute_get();
    if ((iVar6 == 0) && (iVar6 = swtimer_expired(0xd), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      af_mute_set(1);
    }
    iVar6 = swtimer_expired(0xe);
    if (iVar6 == 1) {
      if ((cVar4 == '\x01') || (cVar4 == '\x03')) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        bVar5 = DAT_0008c027;
        DAT_0008c027 = bVar5 & 0xfe;
        bVar5 = DAT_0008c02b;
        DAT_0008c02b = bVar5 & 0xfb;
        bVar5 = DAT_0008c028;
        DAT_0008c028 = bVar5 & 0xfe;
      }
      if ((DAT_00020b19 == '\x01') && (DAT_00020b1a == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if (DAT_00020fcc != 4) {
          iVar6 = ear_det();
          if (iVar6 != 1) {
            bVar5 = DAT_0008c027;
            DAT_0008c027 = bVar5 | 1;
            bVar5 = DAT_0008c02b;
            DAT_0008c02b = bVar5 | 4;
          }
          bVar5 = DAT_0008c028;
          DAT_0008c028 = bVar5 | 1;
        }
        iVar6 = af_mute_get();
        if (iVar6 != 0) {
          af_mute_set(0);
        }
        DAT_00020b18 = '\x02';
      }
    }
    cVar1 = DAT_0008c02b;
    if ((cVar1 < '\0') && (iVar6 = swtimer_expired(0xf), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar5 = DAT_0008c02b;
      DAT_0008c02b = bVar5 & 0x7f;
    }
    iVar6 = swtimer_expired(0x10);
    if (iVar6 == 1) {
      bVar5 = DAT_0008c027;
      DAT_0008c027 = bVar5 | 8;
    }
  }
  else if (DAT_00020b18 == '\x02') {
    iVar6 = swtimer_expired(0x11);
    if (iVar6 == 1) {
      DAT_00012051 = 1;
      DAT_00020b18 = '\x03';
    }
  }
  else if (DAT_00020b18 == '\x03') {
    bVar5 = DAT_0008c041;
    if (DAT_00012051 != (bVar5 >> 4 & 1)) {
      bVar5 = DAT_0008c041;
      if ((bVar5 >> 4 & 1) == 1) {
        send_a_set(0);
        send_b_set(0);
      }
      else if (DAT_0001204d != '\a') {
        if (DAT_0001204d == '\b' || DAT_0001204d == '\t') {
          iVar6 = ckey_det();
          if (iVar6 == 0) {
            send_a_set(1);
            send_b_set(1);
          }
          else {
            if ((cVar4 == '\0') || (cVar4 == '\x02')) {
              bVar2 = true;
            }
            else {
              bVar2 = false;
            }
            if (bVar2) {
              send_a_set(1);
              send_b_set(1);
            }
          }
        }
        else {
          if ((DAT_00012050 == '\0') || (iVar6 = FUN_fffb521a(), iVar6 == 1)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (bVar2) {
            send_a_set(1);
            send_b_set(1);
          }
        }
      }
      bVar5 = DAT_0008c041;
      DAT_00012051 = bVar5 >> 4 & 1;
    }
  }
  else if (DAT_00020b18 == '\x04') {
    DAT_00020b18 = '\x05';
    DAT_00020b19 = '\0';
    DAT_00020b1a = '\0';
  }
  else if (DAT_00020b18 == '\x05') {
    send_a_set(0);
    send_b_set(0);
    DAT_00020b18 = '\x06';
    swtimer_start(0x12,bVar5);
    swtimer_start(0xc,bVar5 + 6);
    swtimer_start(0xd,DAT_00020b4a + (ushort)bVar5);
    swtimer_start(0xe,bVar5 + 5);
    swtimer_start(0xf,bVar5 + 4);
    swtimer_start(0x10,bVar5 + 3);
  }
  else if (DAT_00020b18 == '\x06') {
    iVar6 = swtimer_expired(0x12);
    if ((iVar6 == 1) && (DAT_00020b49 == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      iVar6 = af_mute_get();
      if (iVar6 == 0) {
        af_mute_set(1);
      }
      DAT_00020b18 = '\a';
    }
  }
  else if (DAT_00020b18 == '\a') {
    bVar5 = DAT_0008c027;
    if (((bVar5 >> 3 & 1) == 1) && (iVar6 = swtimer_expired(0x10), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar5 = DAT_0008c027;
      DAT_0008c027 = bVar5 & 0xf7;
    }
    cVar1 = DAT_0008c02b;
    if ((cVar1 < '\0') || (iVar6 = swtimer_expired(0xf), iVar6 != 1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      bVar5 = DAT_0008c02b;
      DAT_0008c02b = bVar5 | 0x80;
    }
    bVar5 = DAT_0008c022;
    if (((bVar5 >> 4 & 1) == 1) && (iVar6 = swtimer_expired(0xc), iVar6 == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar5 = DAT_0008c022;
      DAT_0008c022 = bVar5 & 0xef;
    }
    iVar6 = swtimer_expired(0xe);
    if ((iVar6 == 1) && (DAT_00020fcc != 4)) {
      iVar6 = ear_det();
      if (iVar6 != 1) {
        bVar5 = DAT_0008c027;
        DAT_0008c027 = bVar5 | 1;
        bVar5 = DAT_0008c02b;
        DAT_0008c02b = bVar5 | 4;
      }
      bVar5 = DAT_0008c028;
      DAT_0008c028 = bVar5 | 1;
    }
    iVar6 = swtimer_expired(0xd);
    if (iVar6 == 1) {
      iVar6 = af_mute_get();
      if ((iVar6 == 0) || (DAT_00020b44 != '\0')) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        swtimer_start(0x2a,0);
        af_mute_set(0);
      }
      DAT_00020b18 = '\b';
    }
  }
  pc_keying();
  return;
}


// ===== ptt_source_select @ fffb85a2 (326 bytes)

/* priority CAT TX1 > EXTPA > DATA > RTS > DTR > ... > VOX -> 0x1204D */

byte ptt_source_select(void)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  byte bStack_5;
  byte bStack_3;
  
  vfo_mode(1);
  bStack_3 = 0;
  cVar3 = FUN_fffba192();
  if (DAT_00020b97 == '\0') {
    if (DAT_00020b28 == '\x01') {
      bStack_3 = 5;
    }
    else if (DAT_00020b25 == '\x01') {
      bStack_3 = 2;
    }
    else if (DAT_00020b24 == '\x01') {
      bStack_3 = 1;
    }
    else if (DAT_00020b26 == '\x01') {
      bStack_3 = 3;
    }
    else if (DAT_00020b27 == '\x01') {
      bStack_3 = 4;
    }
    else if (DAT_00020b2a == '\x01') {
      bStack_3 = 7;
    }
    else if (DAT_00020b2b == '\x01') {
      bStack_3 = 8;
    }
    else if (DAT_00020b2c == '\x01') {
      bStack_3 = 9;
    }
    else if (DAT_00020b2d == '\x01') {
      bStack_3 = 10;
    }
    else if (DAT_00020b2e == '\x01') {
      bStack_3 = 0xb;
    }
    else if (DAT_00020b29 == '\x01') {
      bStack_3 = 6;
    }
    if (bStack_3 != 0) {
      cat_apo_reset();
    }
    DAT_00012050 = 0;
    uVar1 = (uint)bStack_3;
    if (((uVar1 == 1) || (uVar1 - 3 < 2)) || (uVar1 == 8 || uVar1 == 9)) {
      if ((cVar3 == '\x01') || (cVar3 == '\x03')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        DAT_00012050 = 1;
      }
    }
    if ((bStack_3 != 0) && (bStack_3 != 6)) {
      swtimer_start(0x2f,200);
    }
    bStack_5 = bStack_3;
  }
  else {
    bStack_5 = 0;
  }
  return bStack_5;
}


// ===== ptt_arbiter @ fffb86e8 (794 bytes)

/* TX allowed check, TXINH line, debounce, hang/delay, trx_state 0 or 4 */

void ptt_arbiter(void)

{
  uint uVar1;
  bool bVar2;
  undefined4 uVar3;
  char cVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  byte bStack_f;
  char cStack_c;
  
  uVar3 = DAT_00020f50;
  vfo_mode(1);
  cVar4 = FUN_fffba192();
  bVar5 = ptt_source_select();
  if (DAT_0001204d != bVar5) {
    DAT_0001b4cd = DAT_0001204d;
    DAT_0001204d = bVar5;
  }
  if (DAT_0001204d == 0) {
    cStack_c = '\0';
    DAT_00020b47 = 0;
  }
  else if (DAT_00020b7c != '\x02') {
    cStack_c = '\x01';
  }
  iVar7 = tx_freq_allowed(uVar3);
  if (iVar7 == 0) {
    bVar5 = DAT_0008c02a;
    if ((bVar5 >> 1 & 1) != 1) {
      bVar5 = DAT_0008c02a;
      DAT_0008c02a = bVar5 | 2;
    }
    if (DAT_00020b6b != '\x01') {
      return;
    }
    DAT_0001b4cc = 0;
    DAT_0001b4ce = 0;
    DAT_00020b18 = 4;
    DAT_00020b6b = 0;
    return;
  }
  bVar5 = DAT_0008c041;
  if (((bVar5 >> 4 & 1) == 1) && (bVar5 = DAT_0008c02a, (bVar5 >> 1 & 1) != 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    bVar5 = DAT_0008c02a;
    DAT_0008c02a = bVar5 | 2;
  }
  else {
    bVar5 = DAT_0008c041;
    if (((bVar5 >> 4 & 1) == 1) || (bVar5 = DAT_0008c02a, (bVar5 >> 1 & 1) != 1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      bVar5 = DAT_0008c02a;
      DAT_0008c02a = bVar5 & 0xfd;
    }
  }
  if (cStack_c == '\x01') {
    if (DAT_0001b4ce == '\0') {
      if ((byte)(DAT_0001b4cc + 1) < 2) {
        DAT_0001b4cc = DAT_0001b4cc + 1;
        return;
      }
      DAT_0001b4cc = 0;
      DAT_0001b4ce = 1;
      DAT_00020b18 = 0;
      DAT_00020b6b = 1;
      tot_start();
      return;
    }
    DAT_0001b4cc = 0;
    iVar7 = tot_expired();
    if (iVar7 != 1) {
      iVar7 = tot_prewarn();
      if (iVar7 != 1) {
        return;
      }
      beep_request(7);
      return;
    }
    DAT_00020b47 = 1;
    return;
  }
  if (DAT_0001b4ce != '\x01') {
    DAT_0001b4cc = 0;
    return;
  }
  uVar1 = (uint)DAT_0001b4cd;
  if ((uVar1 != 1) && (1 < uVar1 - 3)) {
    if (uVar1 == 6) {
      if (DAT_0001b4cc == 0) {
        if (DAT_00009af3 == '\0') {
          bStack_f = DAT_00009bf4;
        }
        else {
          bStack_f = DAT_00009bf5;
        }
        swtimer_start(0x15,*(undefined2 *)(&DAT_fff8833c + (uint)bStack_f * 2));
        DAT_0001b4cc = DAT_0001b4cc + 1;
      }
      else {
        iVar7 = swtimer_expired(0x15);
        if (iVar7 == 1) {
          DAT_0001b4cc = DAT_0001b4cc + 1;
        }
      }
    }
    else {
      DAT_0001b4cc = DAT_0001b4cc + 1;
    }
    goto LAB_fffb89c6;
  }
  if (DAT_00009aa0 == '\0') {
    if ((cVar4 == '\x01') || (cVar4 == '\x03')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (cVar4 == '\x04')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) goto LAB_fffb8963;
    bVar2 = true;
  }
  else {
LAB_fffb8963:
    bVar2 = false;
  }
  if (bVar2) {
    if (DAT_0001b4cc == 0) {
      uVar6 = FUN_fffba35c();
      swtimer_start(0x1a,uVar6);
      DAT_0001b4cc = DAT_0001b4cc + 1;
    }
    else {
      iVar7 = swtimer_expired(0x1a);
      if (iVar7 == 1) {
        DAT_0001b4cc = DAT_0001b4cc + 1;
      }
    }
  }
  else {
    DAT_0001b4cc = DAT_0001b4cc + 1;
  }
LAB_fffb89c6:
  if (DAT_0001b4cc < 2) {
    return;
  }
  DAT_0001b4cc = 0;
  DAT_0001b4ce = 0;
  DAT_00020b18 = 4;
  DAT_00020b6b = 0;
  return;
}


// ===== tx_audio_select @ fffb8a02 (138 bytes)

/* TX_SEL_A/B (P81/P82) from mode/setting */

void tx_audio_select(void)

{
  uint uVar1;
  byte bVar2;
  char cStack_2;
  
  bVar2 = vfo_mode(1);
  cStack_2 = FUN_fffb3d11(bVar2);
  uVar1 = (uint)bVar2;
  if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
    cStack_2 = '\x03';
  }
  if (DAT_0001b4cf == cStack_2) {
    return;
  }
  DAT_0001b4cf = cStack_2;
  if (cStack_2 == '\x02') {
    bVar2 = DAT_0008c028;
    DAT_0008c028 = bVar2 | 2;
    bVar2 = DAT_0008c028;
    DAT_0008c028 = bVar2 & 0xfb;
    return;
  }
  if (cStack_2 != '\x01') {
    if (cStack_2 == '\0') {
      bVar2 = DAT_0008c028;
      DAT_0008c028 = bVar2 & 0xfd;
      bVar2 = DAT_0008c028;
      DAT_0008c028 = bVar2 & 0xfb;
      return;
    }
    bVar2 = DAT_0008c028;
    DAT_0008c028 = bVar2 | 2;
    bVar2 = DAT_0008c028;
    DAT_0008c028 = bVar2 | 4;
    return;
  }
  bVar2 = DAT_0008c028;
  DAT_0008c028 = bVar2 & 0xfd;
  bVar2 = DAT_0008c028;
  DAT_0008c028 = bVar2 | 4;
  return;
}


// ===== speaker_route @ fffb8a8c (747 bytes)

/* EXT_SP_DET/EAR_DET -> 0x20FCC route 0..4 */

void speaker_route(void)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar4 = (char *)FUN_fffb54a0();
  cVar1 = *pcVar4;
  if (DAT_00020b18 != '\a') {
    bVar2 = DAT_0008c040;
    if ((bVar2 >> 2 & 1) == 1) {
      iVar5 = ear_det();
      if (iVar5 == 1) {
        DAT_00020fcc = 1;
      }
      else {
        DAT_00020fcc = 0;
      }
    }
    else {
      iVar5 = ear_det();
      if (iVar5 == 1) {
        DAT_00020fcc = 1;
      }
      else if ((char)(cVar1 * '\x05') == '\0') {
        DAT_00020fcc = 3;
      }
      else {
        DAT_00020fcc = 2;
      }
    }
    if ((DAT_0001204e == '\x01') || (DAT_00020b3b == '\x01')) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((bVar3) || (DAT_00020b46 == '\x01')) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      DAT_00020fcc = 4;
      DAT_0001204e = '\0';
    }
    iVar5 = swtimer_expired(0x2c);
    if (iVar5 == 0) {
      DAT_00020fcc = 4;
    }
    if (DAT_00025d44 != DAT_00020fcc) {
      if (DAT_00025d44 == 4) {
        swtimer_start(0x2d,5);
        R_TPU2_Start();
      }
      DAT_00025d44 = DAT_00020fcc;
    }
    iVar5 = swtimer_expired(0x2d);
    if (iVar5 != 0) {
      if (DAT_00020fcc == 0) {
        bVar2 = DAT_0008c027;
        DAT_0008c027 = bVar2 | 1;
        bVar2 = DAT_0008c02b;
        DAT_0008c02b = bVar2 & 0xfb;
        bVar2 = DAT_0008c028;
        DAT_0008c028 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02a;
        DAT_0008c02a = bVar2 & 0xbf;
        DAT_00020b31 = 0xff;
        DAT_00020b32 = 0;
        if (DAT_00020b6b == '\x01') {
          DAT_00020b34 = 0x2222;
          return;
        }
        DAT_00020b34 = 0x3233;
        return;
      }
      if (DAT_00020fcc == 1) {
        bVar2 = DAT_0008c027;
        DAT_0008c027 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02b;
        DAT_0008c02b = bVar2 & 0xfb;
        bVar2 = DAT_0008c028;
        DAT_0008c028 = bVar2 | 1;
        bVar2 = DAT_0008c02a;
        DAT_0008c02a = bVar2 & 0xbf;
        DAT_00020b31 = 0xff;
        DAT_00020b32 = 0;
        if (DAT_00020b6b == '\x01') {
          DAT_00020b34 = 0x2222;
          return;
        }
        DAT_00020b34 = 0x3233;
        return;
      }
      if (DAT_00020fcc == 2) {
        bVar2 = DAT_0008c027;
        DAT_0008c027 = bVar2 | 1;
        bVar2 = DAT_0008c02b;
        DAT_0008c02b = bVar2 | 4;
        bVar2 = DAT_0008c028;
        DAT_0008c028 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02a;
        DAT_0008c02a = bVar2 | 0x40;
        DAT_00020b31 = FUN_fffb34f9(cVar1 * '\x05');
        DAT_00020b32 = 1;
        if (DAT_00020b6b == '\x01') {
          DAT_00020b34 = 0x2222;
          return;
        }
        DAT_00020b34 = 0x3263;
        return;
      }
      if (DAT_00020fcc == 3) {
        bVar2 = DAT_0008c027;
        DAT_0008c027 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02b;
        DAT_0008c02b = bVar2 | 4;
        bVar2 = DAT_0008c028;
        DAT_0008c028 = bVar2 & 0xfe;
        bVar2 = DAT_0008c02a;
        DAT_0008c02a = bVar2 & 0xbf;
        DAT_00020b31 = 0;
        DAT_00020b32 = 0;
        if (DAT_00020b6b == '\x01') {
          DAT_00020b34 = 0x2222;
          return;
        }
        DAT_00020b34 = 0x3233;
        return;
      }
      bVar2 = DAT_0008c027;
      DAT_0008c027 = bVar2 & 0xfe;
      bVar2 = DAT_0008c02b;
      DAT_0008c02b = bVar2 & 0xfb;
      bVar2 = DAT_0008c028;
      DAT_0008c028 = bVar2 & 0xfe;
      DAT_00020b31 = 0;
      DAT_00020b32 = 0;
      if (DAT_00020b6b == '\x01') {
        DAT_00020b34 = 0x2222;
        return;
      }
      DAT_00020b34 = 0x3233;
      return;
    }
  }
  return;
}

