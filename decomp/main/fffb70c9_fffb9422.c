// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== pa_pon_set @ fffb70c9 (22 bytes)

/* PC0 PA_PON */

void pa_pon_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORTC_PODR;
  PORTC_PODR = bVar1 & 0xfe | param_1 & 1;
  return;
}


// ===== tun_lin_sel_set @ fffb70df (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb70ed) */
/* P83 */

void tun_lin_sel_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT8_PODR;
  PORT8_PODR = bVar1 & 0xf7 | (param_1 & 1) << 3;
  return;
}


// ===== rem_key_sel_set @ fffb70f7 (25 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7105) */
/* P86 */

void rem_key_sel_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT8_PODR;
  PORT8_PODR = bVar1 & 0xbf | (param_1 & 1) << 6;
  return;
}


// ===== gpo_a_dir_out @ fffb7110 (12 bytes)

/* PDR P13 */

void gpo_a_dir_out(void)

{
  byte bVar1;
  
  bVar1 = PORT1_PDR;
  PORT1_PDR = bVar1 | 8;
  return;
}


// ===== gpo_b_dir_out @ fffb711c (12 bytes)

/* PDR P12 */

void gpo_b_dir_out(void)

{
  byte bVar1;
  
  bVar1 = PORT1_PDR;
  PORT1_PDR = bVar1 | 4;
  return;
}


// ===== gpo_c_dir @ fffb7128 (37 bytes)

/* PDR P50 */

void gpo_c_dir(char param_1)

{
  byte bVar1;
  
  if (param_1 != '\0') {
    bVar1 = PORT5_PDR;
    PORT5_PDR = bVar1 | 1;
    return;
  }
  bVar1 = PORT5_PDR;
  PORT5_PDR = bVar1 & 0xfe;
  return;
}


// ===== gpo_a_set @ fffb714d (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb715b) */
/* P13 */

void gpo_a_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT1_PODR;
  PORT1_PODR = bVar1 & 0xf7 | (param_1 & 1) << 3;
  return;
}


// ===== gpo_b_set @ fffb7165 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7173) */
/* P12 */

void gpo_b_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT1_PODR;
  PORT1_PODR = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== gpo_c_set @ fffb717d (22 bytes)

/* P50 */

void gpo_c_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT5_PODR;
  PORT5_PODR = bVar1 & 0xfe | param_1 & 1;
  return;
}


// ===== gpo_d_set @ fffb7193 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb71a1) */
/* P22 */

void gpo_d_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT2_PODR;
  PORT2_PODR = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== gpo_a_get @ fffb71ab (19 bytes)

byte gpo_a_get(void)

{
  byte bVar1;
  
  bVar1 = PORT1_PODR;
  return bVar1 >> 3 & 1;
}


// ===== gpo_b_get @ fffb71be (19 bytes)

byte gpo_b_get(void)

{
  byte bVar1;
  
  bVar1 = PORT1_PODR;
  return bVar1 >> 2 & 1;
}


// ===== gpo_c_get @ fffb71d1 (17 bytes)

byte gpo_c_get(void)

{
  byte bVar1;
  
  bVar1 = PORT5_PODR;
  return bVar1 & 1;
}


// ===== gpo_d_get @ fffb71e2 (19 bytes)

byte gpo_d_get(void)

{
  byte bVar1;
  
  bVar1 = PORT2_PODR;
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
    bVar1 = PORT2_PODR;
    PORT2_PODR = bVar1 & 0xfb;
    return;
  }
  bVar1 = PORT2_PODR;
  PORT2_PODR = bVar1 | 4;
  return;
}


// ===== rx_line_get @ fffb721a (17 bytes)

/* PB7 RX */

byte rx_line_get(void)

{
  byte bVar1;
  
  bVar1 = PORTB_PODR;
  return bVar1 >> 7;
}


// ===== af_mute_get @ fffb722b (24 bytes)

/* PB3 */

bool af_mute_get(void)

{
  byte bVar1;
  
  bVar1 = PORTB_PODR;
  return (bVar1 & 8) != 0;
}


// ===== af_mute_set @ fffb7243 (199 bytes)

/* AF_MUTE (PB3) */

void af_mute_set(char param_1)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  char local_1;
  
  uVar3 = audio_route_state();
  if ((uVar3 - 4 < 2) || (local_1 = param_1, uVar3 == 0xb || uVar3 == 0xc)) {
    local_1 = '\0';
  }
  bVar2 = swtimer_expired(0x2a);
  if (bVar2 == 0) {
    bVar2 = PORTB_PODR;
    if ((bVar2 & 8) == 0) {
      bVar2 = PORTB_PODR;
      PORTB_PODR = bVar2 | 8;
    }
    if (DAT_0001204f == '\0') {
      if ((g_ui.trx_state == 8) || (g_ui.trx_state == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (local_1 == '\0') {
          g_ui.pb3_last = 0;
          return;
        }
        g_ui.pb3_last = 1;
        return;
      }
    }
  }
  else if (local_1 == '\0') {
    bVar2 = PORTB_PODR;
    PORTB_PODR = bVar2 & 0xf7;
    if (g_ui.trx_state == 8) {
      g_ui.pb3_last = 0;
      return;
    }
  }
  else {
    bVar2 = PORTB_PODR;
    PORTB_PODR = bVar2 | 8;
    if (g_ui.trx_state == 8) {
      g_ui.pb3_last = 1;
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
  
  bVar1 = PORTF_PIDR;
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
    bVar1 = PORTB_PODR;
    PORTB_PODR = bVar1 & 0xfb | (param_1 & 1) << 2;
    return;
  }
  if (DAT_00020fcc == 1) {
    bVar1 = PORT8_PODR;
    PORT8_PODR = bVar1 & 0xfe | param_1 & 1;
    return;
  }
  if (DAT_00020fcc == 2) {
    bVar1 = PORT7_PODR;
    PORT7_PODR = bVar1 & 0xfe | param_1 & 1;
    bVar1 = PORTB_PODR;
    PORTB_PODR = bVar1 & 0xfb | (param_1 & 1) << 2;
    return;
  }
  if (DAT_00020fcc != 0) {
    return;
  }
  bVar1 = PORT7_PODR;
  PORT7_PODR = bVar1 & 0xfe | param_1 & 1;
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
  bVar1 = PORTC_PODR;
  PORTC_PODR = bVar1 & 0xef;
  R_SCI5_Stop();
  bVar1 = PORTC_PODR;
  PORTC_PODR = bVar1 & 0xf7;
  bVar1 = PORT6_PODR;
  PORT6_PODR = bVar1 & 0x7f;
  bVar1 = PORTB_PODR;
  PORTB_PODR = bVar1 & 0xdf;
  bVar1 = PORTA_PODR;
  PORTA_PODR = bVar1 & 0x7f;
  return;
}


// ===== meter_task @ fffb73dd (65 bytes)

/* 5 ms: ADC scan + SWR; 10 ms: VDD IDD ALC PO COMP S remote-keypad */

void meter_task(void)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(9);
  if (bVar1 == 1) {
    swtimer_start(9,5);
    adc_scan_blocking();
    swr_meter_protect();
  }
  bVar1 = swtimer_expired(10);
  if (bVar1 == 1) {
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
  byte bVar1;
  
  adc_scan_start();
  do {
    bVar1 = adc_scan_done();
  } while (bVar1 != 1);
  return;
}


// ===== vdd_scale_calc @ fffb742b (81 bytes)

/* cal 0x4659, 0x4667 */

void vdd_scale_calc(void)

{
  DAT_00020fc0 = ((float)g_cfg105.a001_gn_vdd_mtr / 192.0) *
                 (0.07176471 / (13.8 / (float)g_cfg105.a015_mt_vdd_mtr_pos));
  return;
}


// ===== meter_vdd @ fffb747c (60 bytes)

/* AN003 -> 0x12043 */

void meter_vdd(void)

{
  ushort uVar1;
  float fVar2;
  undefined1 uStack_4;
  
  uVar1 = g_ui.adc_pa_vdd >> 4;
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
  undefined1 local_6;
  
  uVar1 = (uint)(byte)(g_ui.adc_pa_idd >> 4) * (uint)g_cfg105.a016_mt_idd_mtr_pos;
  if (g_cfg105.a261_tx_idd_mtr != 0) {
    uVar1 = uVar1 / g_cfg105.a261_tx_idd_mtr;
  }
  local_6 = (undefined1)uVar1;
  if (0xff < uVar1) {
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
  undefined1 local_6;
  
  uVar1 = (uint)(byte)(g_ui.adc_alcm >> 4) * (uint)g_cfg105.a014_mt_alc_mtr_pos;
  if (g_cfg105.a246_tx_alc_mtr != 0) {
    uVar1 = uVar1 / g_cfg105.a246_tx_alc_mtr;
  }
  local_6 = (undefined1)uVar1;
  if (0xff < uVar1) {
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
  byte bVar5;
  float fVar6;
  uint uVar7;
  undefined1 uStack_22;
  float fStack_20;
  float fStack_1c;
  float local_18;
  
  uVar7 = (uint)g_ui.adc_mcup_rvs;
  uVar2 = (uint)g_ui.adc_mcup_for;
  uVar3 = (uint)g_cfg105.a017_mt_swr_1_5_mtr_pos;
  fStack_20 = (float)g_cfg105.a018_mt_swr_2_0_mtr_pos;
  uVar4 = (uint)g_cfg105.a019_mt_swr_3_0_mtr_pos;
  fVar6 = (float)uVar7 / (float)uVar2;
  local_18 = (fVar6 + 1.0) / (1.0 - fVar6);
  if (g_ui.transmitting != 0) {
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
        bVar5 = blink_phase(1);
        bVar1 = false;
        if (bVar5 == 0) {
          g_ui.hi_swr = 1;
        }
        else {
          g_ui.hi_swr = 2;
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
        g_ui.hi_swr = 0;
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
      g_ui.hi_swr = 0;
      uVar7 = (uint)SBORROW4((uint)g_ui.tune_cycle_3d,2) << 3;
      if (g_ui.tune_cycle_3d == 2) {
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
    fVar6 = ROUND(fStack_1c * local_18 + fStack_20);
    uStack_22 = SUB41(fVar6,0);
    if (0xff < ((uint)fVar6 & 0xffff)) {
      uStack_22 = 0xff;
    }
    DAT_00012047 = uStack_22;
    DAT_00012046 = FUN_fffb9422(uStack_22);
    return;
  }
  g_ui.hi_swr = 0;
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
  
  fVar2 = (float)g_ui.adc_mcup_for;
  fVar3 = (float)((uint)g_ui.po_meter_scale << 4);
  cVar1 = tx_band_of_freq(g_ui.freq_tx);
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
    if (fVar2 < *(float *)(BYTE_ARRAY_fff88c70 + iVar4 + 4) == SCARRY4(iVar4,-0x7738c)) {
      fStack_20 = *(float *)(BYTE_ARRAY_fff88c70 + (uint)bStack_2d * 0xc + 8);
      fStack_24 = *(float *)(BYTE_ARRAY_fff88c70 + (uint)bStack_2d * 0xc + 0xc);
      goto LAB_fffb7837;
    }
    bStack_2d = bStack_2d + 1;
  } while( true );
}


// ===== meter_comp @ fffb7869 (240 bytes)

/* DSP value -> 0x12049 [inference] */

void meter_comp(void)

{
  ushort uVar1;
  float fVar2;
  uint uVar3;
  undefined1 uStack_1a;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uVar3 = 0;
  if (g_opstate.proc_level == 0) {
    uVar1 = dsp_comp_level();
    uVar1 = uVar1 >> 8;
    uVar3 = uVar3 & 0xfffffff8;
  }
  else {
    uVar1 = dsp_comp_level();
    uVar1 = uVar1 & 0xff;
    uVar3 = uVar3 & 0xfffffff9;
  }
  uStack_10 = (float)uVar1;
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
  ushort uVar3;
  int iVar4;
  byte bStack_1a;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  
  uVar1 = (uint)g_cfg105.a041_rx_s_mtr_40;
  uVar3 = dsp_signal_level();
  bVar2 = swtimer_expired(0x2a);
  if (bVar2 == 0) {
    return;
  }
  fStack_c = 1.95;
  fStack_10 = 177.0;
  bStack_1a = 0;
  do {
    if (9 < bStack_1a) {
LAB_fffb79e0:
      fStack_18 = ((float)uVar1 - (float)(byte)uVar3) * fStack_c + fStack_10;
      if (fStack_18 - 0.0 < 0.0) {
        fStack_18 = 0.0;
      }
      else if (255.0 < fStack_18) {
        fStack_18 = 255.0;
      }
      if (g_ui.tx_lamp != 0) {
        DAT_0001204a = 0;
        return;
      }
      DAT_0001204a = FUN_fffb959c((uint)ROUND(fStack_18) & 0xff);
      return;
    }
    iVar4 = (uint)bStack_1a * 0xc;
    if (*(float *)("@-D" + iVar4 + 3) < (float)uVar1 - (float)(byte)uVar3 == SCARRY4(iVar4,-0x77404)
       ) {
      fStack_c = *(float *)(BYTE_ARRAY_fff88aca + (uint)bStack_1a * 0xc + 0x132);
      fStack_10 = *(float *)(BYTE_ARRAY_fff88aca + (uint)bStack_1a * 0xc + 0x136);
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
  
  bVar2 = (byte)(g_ui.adc_rem_key >> 4);
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
        screensaver_timer_restart();
        if (g_ui.screensaver_on == 0) {
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
    if ((BYTE_ARRAY_fff8134f[(uint)local_3 * 2 + 0x25c] < bVar2) &&
       (bVar2 < BYTE_ARRAY_fff8134f[(uint)local_3 * 2 + 0x25d])) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if ((uint)DAT_0001b4c9 != local_3 + 1) {
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
  byte bVar1;
  
  bVar1 = swtimer_expired(0x13);
  if (bVar1 != 1) {
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
  byte bVar2;
  bool bVar3;
  radio_mode rVar4;
  byte bVar5;
  vfo_rec *pvVar6;
  uint uVar7;
  
  pvVar6 = vfo_rec_ptr(g_ui.transmitting);
  bVar1 = g_opstate.ex030102_rf_sql_vr;
  bVar5 = pvVar6->flags3;
  bVar2 = swtimer_expired(0x2a);
  if (bVar2 != 0) {
    if (g_ui.trx_state == 8) {
      if (DAT_0001b4ca != bVar1) {
        DAT_0001b4ca = bVar1;
        bVar3 = af_mute_get();
        if (bVar3) {
          af_mute_set('\0');
        }
        g_ui.squelch_open = 0;
        swtimer_start(0x2a,0x32);
        DAT_0001204f = 1;
        af_mute_set('\x01');
        DAT_0001204f = 0;
        return;
      }
      uVar7 = audio_route_state();
      if (((uVar7 - 4 < 2) || (uVar7 == 0xb || uVar7 == 0xc)) && (bVar3 = af_mute_get(), bVar3)) {
        af_mute_set('\0');
      }
      if ((char)((bVar5 & 0x38) >> 3) == '\x02') {
        rVar4 = vfo_mode(VFO_RX);
        uVar7 = (uint)rVar4;
        if ((uVar7 - 6 < 2) || (uVar7 == 10 || uVar7 == 0xb)) {
          bVar5 = dsp_tone_detect();
          if (bVar5 == 0) {
            g_ui.squelch_open = 0;
            bVar3 = af_mute_get();
            if (!bVar3) {
              af_mute_set('\x01');
            }
          }
          else {
            g_ui.squelch_open = 1;
            bVar3 = af_mute_get();
            if (bVar3) {
              af_mute_set('\0');
            }
          }
        }
        else {
          bVar3 = af_mute_get();
          if (bVar3) {
            af_mute_set('\0');
          }
        }
      }
      else {
        if (bVar1 == 0) {
          bVar5 = PORT2_PODR;
          PORT2_PODR = bVar5 & 0xef;
          bVar3 = af_mute_get();
          if (!bVar3) {
            return;
          }
          af_mute_set('\0');
          g_ui.squelch_open = 0;
          return;
        }
        FUN_fffb7cec();
        if (bVar1 == 1) {
          FUN_fffb7e61();
        }
      }
      if (g_ui.squelch_open != 1) {
        bVar5 = PORT2_PODR;
        PORT2_PODR = bVar5 | 0x10;
        return;
      }
      bVar5 = PORT2_PODR;
      PORT2_PODR = bVar5 & 0xef;
      return;
    }
    bVar5 = PORT2_PODR;
    PORT2_PODR = bVar5 | 0x10;
    bVar3 = af_mute_get();
    if ((bVar3) && (g_ui.trx_state == 3)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      af_mute_set('\0');
      return;
    }
  }
  return;
}


// ===== FUN_fffb7cec @ fffb7cec (373 bytes)

void FUN_fffb7cec(void)

{
  uint uVar1;
  radio_mode rVar2;
  byte bVar3;
  bool bVar4;
  float fStack_1c;
  float fStack_18;
  float fStack_8;
  
  rVar2 = vfo_mode(VFO_RX);
  bVar3 = g_cfg105.a047_rx_fm_sql_thn;
  if ((((rVar2 == MODE_DATA_FM_N) || (rVar2 == MODE_FM_N)) ||
      (bVar3 = g_cfg105.a046_rx_fm_sql_thw, rVar2 == MODE_DATA_FM)) || (rVar2 == MODE_FM)) {
    fStack_8 = (float)bVar3;
    fStack_18 = (float)g_cfg105.a048_rx_fm_sql_ti;
    if (g_ui.rf_gain < 0x19) {
      fStack_18 = 256.0;
      fStack_1c = 0.0;
    }
    else if (g_ui.rf_gain < 0x32) {
      fStack_18 = fStack_8;
      fStack_1c = 30.0;
    }
    else if (g_ui.rf_gain < 0xfa) {
      fStack_18 = (float)g_ui.rf_gain * ((fStack_8 - fStack_18) / -200.0) +
                  (fStack_8 * 5.0 - fStack_18) / 4.0;
      if (g_ui.rf_gain < 100) {
        fStack_1c = 15.0;
      }
      else if (g_ui.rf_gain < 0x96) {
        fStack_1c = 22.0;
      }
      else if (g_ui.rf_gain < 200) {
        fStack_1c = 25.0;
      }
      else {
        fStack_1c = 30.0;
      }
    }
    else {
      fStack_1c = 25.0;
    }
    DAT_0001b4cb = rVar2;
    bVar3 = dsp_fm_noise();
    if ((float)bVar3 < fStack_18) {
      g_ui.squelch_open = 1;
      bVar4 = af_mute_get();
      if (bVar4) {
        af_mute_set('\0');
        return;
      }
    }
    else if (fStack_18 + fStack_1c < (float)bVar3) {
      g_ui.squelch_open = 0;
      bVar4 = af_mute_get();
      if (!bVar4) {
        af_mute_set('\x01');
        return;
      }
    }
  }
  else {
    uVar1 = (uint)DAT_0001b4cb;
    if (((uVar1 - 6 < 2) || (uVar1 == 10 || uVar1 == 0xb)) &&
       (DAT_0001b4cb = rVar2, bVar4 = af_mute_get(), bVar4)) {
      af_mute_set('\0');
      return;
    }
  }
  return;
}


// ===== FUN_fffb7e61 @ fffb7e61 (270 bytes)

void FUN_fffb7e61(void)

{
  uint uVar1;
  radio_mode rVar2;
  bool bVar3;
  ushort uVar4;
  float fVar6;
  float fStack_24;
  float fStack_20;
  uint uVar5;
  
  uVar1 = (uint)g_cfg105.a041_rx_s_mtr_40;
  rVar2 = vfo_mode(VFO_RX);
  uVar5 = (uint)rVar2;
  if (((uVar5 < 6) || (uVar5 - 8 < 2)) || (uVar5 - 0xc < 3)) {
    fVar6 = (float)uVar1 + 110.0;
    fStack_20 = (float)uVar1 + 80.0;
    if (g_ui.rf_gain < 0x19) {
      fStack_20 = 256.0;
      fStack_24 = 0.0;
    }
    else if (g_ui.rf_gain < 0xf0) {
      fStack_20 = (float)g_ui.rf_gain * ((fStack_20 - fVar6) / 216.0) +
                  (fVar6 * 240.0 - fStack_20 * 24.0) / 216.0;
      fStack_24 = 6.0;
    }
    else {
      fStack_24 = 6.0;
    }
    uVar4 = dsp_signal_level();
    if ((float)(byte)uVar4 < fStack_20) {
      g_ui.squelch_open = 1;
      bVar3 = af_mute_get();
      if (bVar3) {
        af_mute_set('\0');
        return;
      }
    }
    else if (fStack_20 + fStack_24 < (float)(byte)uVar4) {
      g_ui.squelch_open = 0;
      bVar3 = af_mute_get();
      if (!bVar3) {
        af_mute_set('\x01');
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
  bool bVar1;
  radio_mode rVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  byte bStack_5;
  byte bStack_4;
  byte bStack_2;
  
  rVar2 = vfo_mode(VFO_TX);
  bStack_2 = FUN_fffb50d7(rVar2);
  bVar3 = tx_cw_keying_class();
  g_ui.ptt_data = 0;
  g_ui.ptt_usb_rts = 0;
  g_ui.ptt_usb_dtr = 0;
  g_ui.ptt_vox = 0;
  bVar4 = PORT1_PIDR;
  g_ui.ptt_extpa = (bVar4 & 0x20) == 0;
  if (bVar3 == 0) {
    bStack_5 = 1;
  }
  else {
    bStack_5 = 2;
  }
  for (bStack_4 = 0; bStack_4 < bStack_5; bStack_4 = bStack_4 + 1) {
    if (bVar3 == 1) {
      if ((bStack_4 == 1) && (bStack_2 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        bStack_2 = g_opstate.ex020115_pc_keying;
      }
    }
    else if (bStack_4 == 1) {
      bStack_2 = g_opstate.ex020115_pc_keying;
    }
    if ((bStack_2 == 3) && (bVar4 = PORT2_PIDR, (bVar4 & 1) == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      g_ui.ptt_data = 1;
joined_r0xfffb8040:
      if (bVar3 == 1) break;
    }
    else {
      bVar4 = PORT7_PIDR;
      if ((bVar4 >> 5 & 1) == 1) {
        if ((bStack_2 == 1) && (bVar4 = PORTC_PIDR, (bVar4 & 0x40) == 0)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          g_ui.ptt_usb_rts = 1;
        }
        else {
          if ((bStack_2 == 2) && (bVar4 = PORTC_PIDR, (bVar4 & 0x20) == 0)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (!bVar1) goto LAB_fffb80ab;
          g_ui.ptt_usb_dtr = 1;
        }
        goto joined_r0xfffb8040;
      }
    }
LAB_fffb80ab:
  }
  if ((((1 < rVar2 - 2) && (1 < rVar2 - 0xc)) && (g_opstate.vox_on != 0)) &&
     ((uVar5 = dsp_status1_raw(), (uVar5 & 0x10) != 0 && (bVar4 = swtimer_expired(0x2f), bVar4 == 1)
      ))) {
    g_ui.ptt_vox = 1;
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
  uint freq;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  byte bStack_9;
  
  freq = g_ui.freq_tx;
  bStack_9 = FUN_fffb548a();
  bVar3 = g_opstate.ex020117_cw_wave_shape;
  bVar2 = tx_cw_keying_class();
  bVar3 = bVar3 * '\x02' + 4;
  ptt_arbiter();
  iVar5 = tx_breakin_on();
  if (iVar5 == 1) {
    if (DAT_0001204d == '\a') {
      bStack_9 = 0;
    }
    else if ((DAT_0001204d == '\b' || DAT_0001204d == '\t') && (bVar4 = ckey_det(), bVar4)) {
      if ((bVar2 == 0) || (bVar2 == 2)) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      if (!bVar4) {
        bStack_9 = 0;
      }
    }
  }
  if (g_ui.trx_state == 0) {
    bVar4 = tx_freq_allowed(freq);
    if (bVar4) {
      g_ui.trx_state = 1;
      swtimer_start(0xc,1);
      swtimer_start(0xd,1);
      swtimer_start(0xe,5);
      swtimer_start(0xf,1);
      swtimer_start(0x10,3);
      swtimer_start(0x11,(ushort)bStack_9);
    }
    g_ui.tx_ack_sdr = 0;
    g_ui.tx_ack_dsp = 0;
  }
  else if (g_ui.trx_state == 1) {
    bVar3 = PORT2_PODR;
    if (((bVar3 & 0x10) == 0) && (bVar3 = swtimer_expired(0xc), bVar3 == 1)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if (bVar4) {
      bVar3 = PORT2_PODR;
      PORT2_PODR = bVar3 | 0x10;
    }
    bVar4 = af_mute_get();
    if ((bVar4) || (bVar3 = swtimer_expired(0xd), bVar3 != 1)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (bVar4) {
      af_mute_set('\x01');
    }
    bVar3 = swtimer_expired(0xe);
    if (bVar3 == 1) {
      if ((bVar2 == 1) || (bVar2 == 3)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if (bVar4) {
        bVar3 = PORT7_PODR;
        PORT7_PODR = bVar3 & 0xfe;
        bVar3 = PORTB_PODR;
        PORTB_PODR = bVar3 & 0xfb;
        bVar3 = PORT8_PODR;
        PORT8_PODR = bVar3 & 0xfe;
      }
      if ((g_ui.tx_ack_sdr == 1) && (g_ui.tx_ack_dsp == 1)) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      if (bVar4) {
        if (DAT_00020fcc != 4) {
          bVar4 = ear_det();
          if (!bVar4) {
            bVar3 = PORT7_PODR;
            PORT7_PODR = bVar3 | 1;
            bVar3 = PORTB_PODR;
            PORTB_PODR = bVar3 | 4;
          }
          bVar3 = PORT8_PODR;
          PORT8_PODR = bVar3 | 1;
        }
        bVar4 = af_mute_get();
        if (bVar4) {
          af_mute_set('\0');
        }
        g_ui.trx_state = 2;
      }
    }
    cVar1 = PORTB_PODR;
    if ((cVar1 < '\0') && (bVar3 = swtimer_expired(0xf), bVar3 == 1)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if (bVar4) {
      bVar3 = PORTB_PODR;
      PORTB_PODR = bVar3 & 0x7f;
    }
    bVar3 = swtimer_expired(0x10);
    if (bVar3 == 1) {
      bVar3 = PORT7_PODR;
      PORT7_PODR = bVar3 | 8;
    }
  }
  else if (g_ui.trx_state == 2) {
    bVar3 = swtimer_expired(0x11);
    if (bVar3 == 1) {
      DAT_00012051 = 1;
      g_ui.trx_state = 3;
    }
  }
  else if (g_ui.trx_state == 3) {
    bVar3 = PORT1_PIDR;
    if (DAT_00012051 != (bVar3 >> 4 & 1)) {
      bVar3 = PORT1_PIDR;
      if ((bVar3 >> 4 & 1) == 1) {
        send_a_set(0);
        send_b_set(0);
      }
      else if (DAT_0001204d != '\a') {
        if (DAT_0001204d == '\b' || DAT_0001204d == '\t') {
          bVar4 = ckey_det();
          if (bVar4) {
            if ((bVar2 == 0) || (bVar2 == 2)) {
              bVar4 = true;
            }
            else {
              bVar4 = false;
            }
            if (bVar4) {
              send_a_set(1);
              send_b_set(1);
            }
          }
          else {
            send_a_set(1);
            send_b_set(1);
          }
        }
        else {
          if ((DAT_00012050 == '\0') || (iVar5 = tx_breakin_on(), iVar5 == 1)) {
            bVar4 = true;
          }
          else {
            bVar4 = false;
          }
          if (bVar4) {
            send_a_set(1);
            send_b_set(1);
          }
        }
      }
      bVar3 = PORT1_PIDR;
      DAT_00012051 = bVar3 >> 4 & 1;
    }
  }
  else if (g_ui.trx_state == 4) {
    g_ui.trx_state = 5;
    g_ui.tx_ack_sdr = 0;
    g_ui.tx_ack_dsp = 0;
  }
  else if (g_ui.trx_state == 5) {
    send_a_set(0);
    send_b_set(0);
    g_ui.trx_state = 6;
    swtimer_start(0x12,(ushort)bVar3);
    swtimer_start(0xc,bVar3 + 6);
    swtimer_start(0xd,g_ui.rx_unmute_delay_ms + bVar3);
    swtimer_start(0xe,bVar3 + 5);
    swtimer_start(0xf,bVar3 + 4);
    swtimer_start(0x10,bVar3 + 3);
  }
  else if (g_ui.trx_state == 6) {
    bVar3 = swtimer_expired(0x12);
    if ((bVar3 == 1) && (g_ui.dsp_route_ready == 1)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if (bVar4) {
      bVar4 = af_mute_get();
      if (!bVar4) {
        af_mute_set('\x01');
      }
      g_ui.trx_state = 7;
    }
  }
  else if (g_ui.trx_state == 7) {
    bVar3 = PORT7_PODR;
    if (((bVar3 >> 3 & 1) == 1) && (bVar3 = swtimer_expired(0x10), bVar3 == 1)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if (bVar4) {
      bVar3 = PORT7_PODR;
      PORT7_PODR = bVar3 & 0xf7;
    }
    cVar1 = PORTB_PODR;
    if ((cVar1 < '\0') || (bVar3 = swtimer_expired(0xf), bVar3 != 1)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (bVar4) {
      bVar3 = PORTB_PODR;
      PORTB_PODR = bVar3 | 0x80;
    }
    bVar3 = PORT2_PODR;
    if (((bVar3 >> 4 & 1) == 1) && (bVar3 = swtimer_expired(0xc), bVar3 == 1)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if (bVar4) {
      bVar3 = PORT2_PODR;
      PORT2_PODR = bVar3 & 0xef;
    }
    bVar3 = swtimer_expired(0xe);
    if ((bVar3 == 1) && (DAT_00020fcc != 4)) {
      bVar4 = ear_det();
      if (!bVar4) {
        bVar3 = PORT7_PODR;
        PORT7_PODR = bVar3 | 1;
        bVar3 = PORTB_PODR;
        PORTB_PODR = bVar3 | 4;
      }
      bVar3 = PORT8_PODR;
      PORT8_PODR = bVar3 | 1;
    }
    bVar3 = swtimer_expired(0xd);
    if (bVar3 == 1) {
      bVar4 = af_mute_get();
      if ((bVar4) && (g_ui.pb3_last == 0)) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      if (bVar4) {
        swtimer_start(0x2a,0);
        af_mute_set('\0');
      }
      g_ui.trx_state = 8;
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
  byte bVar3;
  byte bStack_5;
  byte bStack_3;
  
  vfo_mode(VFO_TX);
  bStack_3 = 0;
  bVar3 = tx_cw_keying_class();
  if (g_ui.playlist_open == 0) {
    if (g_ui.cat_tx_req == 1) {
      bStack_3 = 5;
    }
    else if (g_ui.ptt_extpa == 1) {
      bStack_3 = 2;
    }
    else if (g_ui.ptt_data == 1) {
      bStack_3 = 1;
    }
    else if (g_ui.ptt_usb_rts == 1) {
      bStack_3 = 3;
    }
    else if (g_ui.ptt_usb_dtr == 1) {
      bStack_3 = 4;
    }
    else if (g_ui.ptt_keyer == 1) {
      bStack_3 = 7;
    }
    else if (g_ui.ptt_mic == 1) {
      bStack_3 = 8;
    }
    else if (g_ui.ptt_mox == 1) {
      bStack_3 = 9;
    }
    else if (g_ui.ptt_atu_tune == 1) {
      bStack_3 = 10;
    }
    else if (g_ui.ptt_msg_play == 1) {
      bStack_3 = 0xb;
    }
    else if (g_ui.ptt_vox == 1) {
      bStack_3 = 6;
    }
    if (bStack_3 != 0) {
      screensaver_timer_restart();
    }
    DAT_00012050 = 0;
    uVar1 = (uint)bStack_3;
    if (((uVar1 == 1) || (uVar1 - 3 < 2)) || (uVar1 == 8 || uVar1 == 9)) {
      if ((bVar3 == 1) || (bVar3 == 3)) {
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
  byte bVar2;
  byte bVar3;
  bool bVar4;
  char cVar5;
  ushort uVar6;
  byte bStack_f;
  char cStack_c;
  
  uVar1 = g_ui.freq_tx;
  vfo_mode(VFO_TX);
  bVar2 = tx_cw_keying_class();
  bVar3 = ptt_source_select();
  if (DAT_0001204d != bVar3) {
    DAT_0001b4cd = DAT_0001204d;
    DAT_0001204d = bVar3;
  }
  if (DAT_0001204d == 0) {
    cStack_c = '\0';
    g_ui.tot_tripped = 0;
  }
  else if (g_ui.dvs_state != 2) {
    cStack_c = '\x01';
  }
  bVar4 = tx_freq_allowed(uVar1);
  if (!bVar4) {
    bVar2 = PORTA_PODR;
    if ((bVar2 >> 1 & 1) != 1) {
      bVar2 = PORTA_PODR;
      PORTA_PODR = bVar2 | 2;
    }
    if (g_ui.transmitting != 1) {
      return;
    }
    DAT_0001b4cc = 0;
    DAT_0001b4ce = 0;
    g_ui.trx_state = 4;
    g_ui.transmitting = 0;
    return;
  }
  bVar3 = PORT1_PIDR;
  if (((bVar3 >> 4 & 1) == 1) && (bVar3 = PORTA_PODR, (bVar3 >> 1 & 1) != 1)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (bVar4) {
    bVar3 = PORTA_PODR;
    PORTA_PODR = bVar3 | 2;
  }
  else {
    bVar3 = PORT1_PIDR;
    if (((bVar3 >> 4 & 1) == 1) || (bVar3 = PORTA_PODR, (bVar3 >> 1 & 1) != 1)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (bVar4) {
      bVar3 = PORTA_PODR;
      PORTA_PODR = bVar3 & 0xfd;
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
      g_ui.trx_state = 0;
      g_ui.transmitting = 1;
      tot_start();
      return;
    }
    DAT_0001b4cc = 0;
    bVar2 = tot_expired();
    if (bVar2 != 1) {
      cVar5 = tot_prewarn();
      if (cVar5 != '\x01') {
        return;
      }
      beep_request(7);
      return;
    }
    g_ui.tot_tripped = 1;
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
        if (g_opstate.ex030405_vox_select == 0) {
          bStack_f = g_opstate.vox_delay[0];
        }
        else {
          bStack_f = g_opstate.vox_delay[1];
        }
        swtimer_start(0x15,*(ushort *)(BYTE_ARRAY_fff88270 + (uint)bStack_f * 2 + 0xcc));
        DAT_0001b4cc = DAT_0001b4cc + 1;
      }
      else {
        bVar2 = swtimer_expired(0x15);
        if (bVar2 == 1) {
          DAT_0001b4cc = DAT_0001b4cc + 1;
        }
      }
    }
    else {
      DAT_0001b4cc = DAT_0001b4cc + 1;
    }
    goto LAB_fffb89c6;
  }
  if (g_opstate.ex020116_cw_bk_in_type == 0) {
    if ((bVar2 == 1) || (bVar2 == 3)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if ((bVar4) || (bVar2 == 4)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if (!bVar4) goto LAB_fffb8963;
    bVar4 = true;
  }
  else {
LAB_fffb8963:
    bVar4 = false;
  }
  if (bVar4) {
    if (DAT_0001b4cc == 0) {
      uVar6 = FUN_fffba35c();
      swtimer_start(0x1a,uVar6);
      DAT_0001b4cc = DAT_0001b4cc + 1;
    }
    else {
      bVar2 = swtimer_expired(0x1a);
      if (bVar2 == 1) {
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
  g_ui.trx_state = 4;
  g_ui.transmitting = 0;
  return;
}


// ===== tx_audio_select @ fffb8a02 (138 bytes)

/* TX_SEL_A/B (P81/P82) from mode/setting */

void tx_audio_select(void)

{
  uint uVar1;
  byte bVar2;
  radio_mode rVar3;
  char cStack_2;
  
  rVar3 = vfo_mode(VFO_TX);
  cStack_2 = FUN_fffb3d11(rVar3);
  uVar1 = (uint)rVar3;
  if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
    cStack_2 = '\x03';
  }
  if (DAT_0001b4cf == cStack_2) {
    return;
  }
  DAT_0001b4cf = cStack_2;
  if (cStack_2 == '\x02') {
    bVar2 = PORT8_PODR;
    PORT8_PODR = bVar2 | 2;
    bVar2 = PORT8_PODR;
    PORT8_PODR = bVar2 & 0xfb;
    return;
  }
  if (cStack_2 != '\x01') {
    if (cStack_2 == '\0') {
      bVar2 = PORT8_PODR;
      PORT8_PODR = bVar2 & 0xfd;
      bVar2 = PORT8_PODR;
      PORT8_PODR = bVar2 & 0xfb;
      return;
    }
    bVar2 = PORT8_PODR;
    PORT8_PODR = bVar2 | 2;
    bVar2 = PORT8_PODR;
    PORT8_PODR = bVar2 | 4;
    return;
  }
  bVar2 = PORT8_PODR;
  PORT8_PODR = bVar2 & 0xfd;
  bVar2 = PORT8_PODR;
  PORT8_PODR = bVar2 | 4;
  return;
}


// ===== speaker_route @ fffb8a8c (747 bytes)

/* EXT_SP_DET/EAR_DET -> 0x20FCC route 0..4 */

void speaker_route(void)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  char *pcVar4;
  
  pcVar4 = (char *)aess_level_ptr();
  cVar1 = *pcVar4;
  if (g_ui.trx_state != 7) {
    bVar3 = PORT0_PIDR;
    if ((bVar3 >> 2 & 1) == 1) {
      bVar2 = ear_det();
      if (bVar2) {
        DAT_00020fcc = 1;
      }
      else {
        DAT_00020fcc = 0;
      }
    }
    else {
      bVar2 = ear_det();
      if (bVar2) {
        DAT_00020fcc = 1;
      }
      else if ((char)(cVar1 * '\x05') == '\0') {
        DAT_00020fcc = 3;
      }
      else {
        DAT_00020fcc = 2;
      }
    }
    if ((DAT_0001204e == '\x01') || (g_ui.spk_off_req == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (g_ui.cat_disabled == 1)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      DAT_00020fcc = 4;
      DAT_0001204e = '\0';
    }
    bVar3 = swtimer_expired(0x2c);
    if (bVar3 == 0) {
      DAT_00020fcc = 4;
    }
    if (DAT_00025d44 != DAT_00020fcc) {
      if (DAT_00025d44 == 4) {
        swtimer_start(0x2d,5);
        R_TPU2_Start();
      }
      DAT_00025d44 = DAT_00020fcc;
    }
    bVar3 = swtimer_expired(0x2d);
    if (bVar3 != 0) {
      if (DAT_00020fcc == 0) {
        bVar3 = PORT7_PODR;
        PORT7_PODR = bVar3 | 1;
        bVar3 = PORTB_PODR;
        PORTB_PODR = bVar3 & 0xfb;
        bVar3 = PORT8_PODR;
        PORT8_PODR = bVar3 & 0xfe;
        bVar3 = PORTA_PODR;
        PORTA_PODR = bVar3 & 0xbf;
        g_ui.spk_boost_level = 0xff;
        g_ui.f_0x02e_u8 = 0;
        if (g_ui.transmitting == 1) {
          g_ui.dsp_route_word = 0x2222;
          return;
        }
        g_ui.dsp_route_word = 0x3233;
        return;
      }
      if (DAT_00020fcc == 1) {
        bVar3 = PORT7_PODR;
        PORT7_PODR = bVar3 & 0xfe;
        bVar3 = PORTB_PODR;
        PORTB_PODR = bVar3 & 0xfb;
        bVar3 = PORT8_PODR;
        PORT8_PODR = bVar3 | 1;
        bVar3 = PORTA_PODR;
        PORTA_PODR = bVar3 & 0xbf;
        g_ui.spk_boost_level = 0xff;
        g_ui.f_0x02e_u8 = 0;
        if (g_ui.transmitting == 1) {
          g_ui.dsp_route_word = 0x2222;
          return;
        }
        g_ui.dsp_route_word = 0x3233;
        return;
      }
      if (DAT_00020fcc == 2) {
        bVar3 = PORT7_PODR;
        PORT7_PODR = bVar3 | 1;
        bVar3 = PORTB_PODR;
        PORTB_PODR = bVar3 | 4;
        bVar3 = PORT8_PODR;
        PORT8_PODR = bVar3 & 0xfe;
        bVar3 = PORTA_PODR;
        PORTA_PODR = bVar3 | 0x40;
        g_ui.spk_boost_level = FUN_fffb34f9(cVar1 * '\x05');
        g_ui.f_0x02e_u8 = 1;
        if (g_ui.transmitting == 1) {
          g_ui.dsp_route_word = 0x2222;
          return;
        }
        g_ui.dsp_route_word = 0x3263;
        return;
      }
      if (DAT_00020fcc == 3) {
        bVar3 = PORT7_PODR;
        PORT7_PODR = bVar3 & 0xfe;
        bVar3 = PORTB_PODR;
        PORTB_PODR = bVar3 | 4;
        bVar3 = PORT8_PODR;
        PORT8_PODR = bVar3 & 0xfe;
        bVar3 = PORTA_PODR;
        PORTA_PODR = bVar3 & 0xbf;
        g_ui.spk_boost_level = 0;
        g_ui.f_0x02e_u8 = 0;
        if (g_ui.transmitting == 1) {
          g_ui.dsp_route_word = 0x2222;
          return;
        }
        g_ui.dsp_route_word = 0x3233;
        return;
      }
      bVar3 = PORT7_PODR;
      PORT7_PODR = bVar3 & 0xfe;
      bVar3 = PORTB_PODR;
      PORTB_PODR = bVar3 & 0xfb;
      bVar3 = PORT8_PODR;
      PORT8_PODR = bVar3 & 0xfe;
      g_ui.spk_boost_level = 0;
      g_ui.f_0x02e_u8 = 0;
      if (g_ui.transmitting == 1) {
        g_ui.dsp_route_word = 0x2222;
        return;
      }
      g_ui.dsp_route_word = 0x3233;
      return;
    }
  }
  return;
}


// ===== FUN_fffb8d77 @ fffb8d77 (518 bytes)

void FUN_fffb8d77(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  radio_mode rVar7;
  bool bVar8;
  byte bVar9;
  byte local_b;
  byte local_a;
  byte local_9;
  byte bStack_7;
  byte bStack_6;
  byte local_5;
  
  uVar1 = g_ui.freq_tx;
  bVar6 = g_opstate.active_vfo;
  bVar5 = g_opstate.ex040304_vmi_color_clar;
  bVar4 = g_opstate.ex040303_vmi_color_memory;
  bVar3 = g_opstate.ex040302_vmi_color_vfo_b;
  bVar2 = g_opstate.ex040301_vmi_color_vfo_a;
  if (g_ui.numentry_mode != 1) {
    local_5 = 0;
    if (g_ui.squelch_open == 1) {
      local_5 = 0x10;
    }
    rVar7 = vfo_mode(VFO_TX);
    if (((1 < rVar7 - 2) && (1 < rVar7 - 0xc)) && (g_opstate.vox_on != 0)) {
      local_5 = local_5 | 0x80;
    }
    g_ui.tx_lamp = 0;
    if (g_ui.transmitting == 1) {
      local_5 = local_5 & 0xef | 0x20;
      g_ui.tx_lamp = 1;
    }
    else {
      if ((DAT_0001204d == '\0') || (bVar8 = tx_freq_allowed(uVar1), bVar8)) {
        bVar8 = false;
      }
      else {
        bVar8 = true;
      }
      if (bVar8) {
        local_5 = local_5 & 0xef;
        bVar9 = blink_phase(0);
        if (bVar9 != 0) {
          local_5 = local_5 | 0x20;
        }
        g_ui.tx_lamp = 2;
      }
    }
    if (bVar6 == 0) {
      bStack_6 = g_opstate.vfo_state_a;
      bStack_7 = g_ui.clar_flags_a;
    }
    else {
      bStack_6 = g_opstate.vfo_state_b;
      bStack_7 = g_ui.clar_flags_b;
    }
    if (bVar2 == 2) {
      local_9 = 1;
    }
    else if (bVar2 == 1) {
      local_9 = 2;
    }
    else if (bVar2 == 0) {
      local_9 = 8;
    }
    else {
      local_9 = 0;
    }
    if (bVar3 == 2) {
      local_a = 1;
    }
    else if (bVar3 == 1) {
      local_a = 2;
    }
    else if (bVar3 == 0) {
      local_a = 8;
    }
    else {
      local_a = 0;
    }
    if (bVar4 == 2) {
      local_b = 4;
    }
    else if (bVar4 == 1) {
      local_b = 2;
    }
    else if (bVar4 == 0) {
      local_b = 8;
    }
    else {
      local_b = 0;
    }
    if (g_opstate.split_on == 0) {
      if (bStack_7 == 0) {
        uVar1 = (uint)bStack_6;
        if ((uVar1 - 7 < 2) || (uVar1 - 2 < 3)) {
          local_5 = local_5 | local_b;
        }
        else if ((uVar1 == 5) || (uVar1 == 1)) {
          if (bVar6 == 0) {
            local_5 = local_5 | local_9;
          }
          else {
            local_5 = local_5 | local_a;
          }
        }
      }
      else {
        local_5 = local_5 | bVar5 == 0;
      }
    }
    else {
      local_5 = local_5 | 1;
    }
    if (g_ui.func_panel_open != 0) {
      local_5 = local_5 | 0x40;
    }
    if (g_ui.lamp_map != local_5) {
      g_ui.lamp_map = local_5;
      return;
    }
  }
  return;
}


// ===== linear_band_data @ fffb8f7d (481 bytes)

/* TUN/LIN=LINEAR: band code on P13/P12/P50/P22 */

void linear_band_data(void)

{
  byte bVar1;
  tunlin_mode tVar2;
  char cVar3;
  
  tVar2 = tunlin_port_mode();
  if (tVar2 == TUNLIN_LINEAR) {
    cVar3 = FUN_fffb33ab(g_ui.freq_tx);
    if (DAT_0001b4d0 != cVar3) {
      DAT_0001b4d0 = cVar3;
      switch(cVar3) {
      case '\0':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 8;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xfb;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 | 1;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 | 4;
        return;
      case '\x01':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xf7;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 4;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 | 1;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 | 4;
        return;
      case '\x02':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 8;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xfb;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 & 0xfe;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 & 0xfb;
        return;
      case '\x03':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xf7;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 4;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 & 0xfe;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 & 0xfb;
        return;
      case '\x04':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 8;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 4;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 & 0xfe;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 & 0xfb;
        return;
      case '\x05':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xf7;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xfb;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 | 1;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 & 0xfb;
        return;
      case '\x06':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 8;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xfb;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 | 1;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 & 0xfb;
        return;
      case '\a':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xf7;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 4;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 | 1;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 & 0xfb;
        return;
      case '\b':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 8;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 4;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 | 1;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 & 0xfb;
        return;
      case '\t':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xf7;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xfb;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 & 0xfe;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 | 4;
        return;
      case '\n':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 8;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xfb;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 & 0xfe;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 | 4;
        return;
      case '\v':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 & 0xf7;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 4;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 & 0xfe;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 | 4;
        return;
      case '\f':
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 8;
        bVar1 = PORT1_PODR;
        PORT1_PODR = bVar1 | 4;
        bVar1 = PORT5_PODR;
        PORT5_PODR = bVar1 | 1;
        bVar1 = PORT2_PODR;
        PORT2_PODR = bVar1 | 4;
        return;
      }
    }
    return;
  }
  DAT_0001b4d0 = 0xff;
  return;
}


// ===== FUN_fffb915e @ fffb915e (393 bytes)

void FUN_fffb915e(void)

{
  byte bVar1;
  bool bVar2;
  radio_mode rVar3;
  byte bStack_4;
  byte bStack_3;
  
  if (g_ui.transmitting == 0) {
    if (DAT_0001b4d1 != '\0') {
      DAT_0001b4d1 = 0;
      beep_stop();
      bVar1 = PORTC_PODR;
      PORTC_PODR = bVar1 | 0x10;
      return;
    }
  }
  else {
    rVar3 = vfo_mode(VFO_TX);
    if (g_opstate.preset_on == 0) {
      bStack_3 = g_opstate.ex010513_rptt_select;
    }
    else {
      bStack_3 = g_ui.preset_active.rptt_select;
    }
    if (bStack_3 == 3) {
      bVar1 = PORT2_PIDR;
      bStack_4 = bVar1 >> 1 & 1;
    }
    else if (bStack_3 == 2) {
      bVar1 = PORTC_PIDR;
      bStack_4 = bVar1 >> 6 & 1;
    }
    else {
      if (bStack_3 != 1) {
        return;
      }
      bVar1 = PORTC_PIDR;
      bStack_4 = bVar1 >> 5 & 1;
    }
    if ((rVar3 == MODE_RTTY_L) || (rVar3 == MODE_RTTY_U)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      if (g_opstate.ex010517_polarity_tx == 0) {
        if (bStack_4 == 0) {
          bVar1 = PORTC_PODR;
          PORTC_PODR = bVar1 & 0xef;
          if (DAT_0001b4d1 != '\x03') {
            DAT_0001b4d1 = 3;
            beep_request(0xb);
            return;
          }
        }
        else {
          bVar1 = PORTC_PODR;
          PORTC_PODR = bVar1 | 0x10;
          if (DAT_0001b4d1 != '\x01') {
            DAT_0001b4d1 = 1;
            beep_request(9);
            return;
          }
        }
      }
      else if (bStack_4 == 0) {
        bVar1 = PORTC_PODR;
        PORTC_PODR = bVar1 | 0x10;
        if (DAT_0001b4d1 != '\x01') {
          DAT_0001b4d1 = 1;
          beep_request(9);
          return;
        }
      }
      else {
        bVar1 = PORTC_PODR;
        PORTC_PODR = bVar1 & 0xef;
        if (DAT_0001b4d1 != '\x03') {
          DAT_0001b4d1 = 3;
          beep_request(0xb);
          return;
        }
      }
    }
    else if (DAT_0001b4d1 != '\0') {
      DAT_0001b4d1 = 0;
      beep_stop();
      bVar1 = PORTC_PODR;
      PORTC_PODR = bVar1 | 0x10;
      return;
    }
  }
  return;
}


// ===== FUN_fffb92e7 @ fffb92e7 (105 bytes)

undefined1 FUN_fffb92e7(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012052)[DAT_00012062] = param_1;
  DAT_00012062 = DAT_00012062 + 1;
  if (0xf < DAT_00012062) {
    DAT_00012062 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012052)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb9350 @ fffb9350 (105 bytes)

undefined1 FUN_fffb9350(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012063)[DAT_00012073] = param_1;
  DAT_00012073 = DAT_00012073 + 1;
  if (0xf < DAT_00012073) {
    DAT_00012073 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012063)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb93b9 @ fffb93b9 (105 bytes)

undefined1 FUN_fffb93b9(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012074)[DAT_00012084] = param_1;
  DAT_00012084 = DAT_00012084 + 1;
  if (0xf < DAT_00012084) {
    DAT_00012084 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012074)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}


// ===== FUN_fffb9422 @ fffb9422 (105 bytes)

undefined1 FUN_fffb9422(undefined1 param_1)

{
  byte local_5;
  ushort local_4;
  
  (&DAT_00012085)[DAT_00012095] = param_1;
  DAT_00012095 = DAT_00012095 + 1;
  if (0xf < DAT_00012095) {
    DAT_00012095 = 0;
  }
  local_4 = 0;
  for (local_5 = 0; local_5 < 0x10; local_5 = local_5 + 1) {
    local_4 = (byte)(&DAT_00012085)[local_5] + local_4;
  }
  return (char)(local_4 >> 4);
}

