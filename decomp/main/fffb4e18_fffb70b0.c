// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== bandmem_set @ fffb4e18 (166 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4e89) */
/* WARNING: Removing unreachable block (ram,0xfffb4e33) */
/* WARNING: Removing unreachable block (ram,0xfffb4e52) */
/* (kind, f): kind 1 -> 0x9C69[band] (scope CURSOR start), 2 -> 0x9C99[band] / 0x9CC9[GEN sub] (FIX
   start) */

void bandmem_set(char param_1,uint param_2)

{
  byte bVar1;
  uint freq;
  int iStack_10;
  byte bStack_b;
  
  freq = vfo_freq_clar(0,2);
  bVar1 = band_of_freq(freq);
  if (param_1 == '\x02') {
    iStack_10 = (uint)bVar1 * 4 + 0x9c99;
    if (bVar1 == 0xb) {
      bVar1 = gen_subband_of_freq(param_2);
      for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
        *(char *)((uint)bStack_b + (uint)bVar1 * 4 + 0x9cc9) =
             (char)(param_2 >> ((3 - bStack_b & 3) << 3));
      }
    }
  }
  else {
    iStack_10 = (uint)bVar1 * 4 + 0x9c69;
  }
  for (bStack_b = 0; bStack_b < 4; bStack_b = bStack_b + 1) {
    *(char *)((uint)bStack_b + iStack_10) = (char)(param_2 >> ((3 - bStack_b & 3) << 3));
  }
  return;
}


// ===== bandmem_get @ fffb4ebe (148 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4edb) */
/* WARNING: Removing unreachable block (ram,0xfffb4f17) */
/* WARNING: Removing unreachable block (ram,0xfffb4f03) */
/* (kind): read band memory of the band containing the active frequency */

uint bandmem_get(char param_1)

{
  byte bVar1;
  uint freq;
  int iStack_14;
  byte bStack_e;
  byte bStack_d;
  uint uStack_c;
  
  freq = vfo_freq(0,2);
  bVar1 = band_of_freq(freq);
  if (param_1 == '\x02') {
    iStack_14 = (uint)bVar1 * 4 + 0x9c99;
    if (bVar1 == 0xb) {
      bStack_d = gen_subband_of_freq(freq);
      if (0xf < bStack_d) {
        bStack_d = 0xf;
      }
      iStack_14 = (uint)bStack_d * 4 + 0x9cc9;
    }
  }
  else {
    iStack_14 = (uint)bVar1 * 4 + 0x9c69;
  }
  uStack_c = 0;
  for (bStack_e = 0; bStack_e < 4; bStack_e = bStack_e + 1) {
    uStack_c = (uint)*(byte *)((uint)bStack_e + iStack_14) | uStack_c << 8;
  }
  return uStack_c;
}


// ===== tx_freq_repeater_shift @ fffb4f52 (389 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb5062) */
/* FM/DATA-FM repeater shift (rec+2 bits2-3) on 28/50 MHz, x10 kHz settings */

uint tx_freq_repeater_shift(uint param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  byte *pbVar6;
  uint uStack_14;
  uint local_4;
  uint uVar7;
  
  pbVar6 = vfo_rec_ptr(1);
  bVar4 = pbVar6[2] >> 2 & 3;
  bVar3 = false;
  bVar2 = false;
  bVar5 = vfo_mode(1);
  uVar7 = (uint)bVar5;
  if ((uVar7 - 6 < 2) || (uVar7 == 10 || uVar7 == 0xb)) {
    if ((param_1 < 28000000) || (29999999 < param_1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar4 == 2) {
      uStack_14 = param_1 + (uint)g_opstate.ex010318_rpt_shift_28mhz * 10000;
    }
    else {
      uStack_14 = param_1;
      if (bVar4 == 0) {
        uStack_14 = param_1 + (uint)g_opstate.ex010318_rpt_shift_28mhz * -10000;
      }
    }
    if ((uStack_14 < 28000000) || (29999999 < uStack_14)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if ((bVar2) || (bVar3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if ((param_1 < 50000000) || (53999999 < param_1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        bVar2 = true;
      }
      if (bVar4 == 2) {
        uStack_14 = param_1 + (uint)CONCAT11(g_opstate.ex010319_rpt_shift_50mhz_be[0],
                                             g_opstate.ex010319_rpt_shift_50mhz_be[1]) * 10000;
      }
      else {
        uStack_14 = param_1;
        if (bVar4 == 0) {
          uStack_14 = param_1 + (uint)CONCAT11(g_opstate.ex010319_rpt_shift_50mhz_be[0],
                                               g_opstate.ex010319_rpt_shift_50mhz_be[1]) * -10000;
        }
      }
      if ((uStack_14 < 50000000) || (53999999 < uStack_14)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        bVar3 = true;
      }
    }
  }
  if ((bVar2) || (bVar3)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_4 = param_1;
  if (bVar2) {
    local_4 = uStack_14;
  }
  return local_4;
}


// ===== FUN_fffb50d7 @ fffb50d7 (323 bytes)

byte FUN_fffb50d7(byte param_1)

{
  uint uVar1;
  byte local_3;
  
  uVar1 = (uint)param_1;
  if (uVar1 == 0xe) {
LAB_fffb51ed:
    if (g_opstate.preset_on == 0) {
      local_3 = g_opstate.ex010417_rptt_select;
    }
    else {
      local_3 = g_ui.preset_active.rptt_select;
    }
  }
  else {
    if (uVar1 - 2 < 2) {
      if (g_opstate.preset_on != 0) {
        return g_ui.preset_active.rptt_select;
      }
      return g_opstate.ex020113_rptt_select;
    }
    if (uVar1 - 4 < 2) {
      if (g_opstate.preset_on != 0) {
        return g_ui.preset_active.rptt_select;
      }
      return g_opstate.ex010217_rptt_select;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb51ed;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (g_opstate.preset_on != 0) {
            return g_ui.preset_active.rptt_select;
          }
          return g_opstate.ex010513_rptt_select;
        }
        if (1 < uVar1) {
          return 0;
        }
        if (g_opstate.preset_on != 0) {
          return g_ui.preset_active.rptt_select;
        }
        return g_opstate.ex010117_rptt_select;
      }
    }
    if (g_opstate.preset_on == 0) {
      local_3 = g_opstate.ex010316_rptt_select;
    }
    else {
      local_3 = g_ui.preset_active.rptt_select;
    }
  }
  return local_3;
}


// ===== tx_breakin_on @ fffb521a (98 bytes)

/* Bit 1 (BI break-in flag) of the TX VFO per-mode byte (vfo_rec_ptr(1)/vfo_mode(1)) */

bool tx_breakin_on(void)

{
  byte bVar1;
  byte *pbVar2;
  byte bStack_9;
  uint uVar3;
  
  pbVar2 = vfo_rec_ptr(1);
  bVar1 = vfo_mode(1);
  uVar3 = (uint)bVar1;
  if (1 < uVar3 - 10) {
    if (uVar3 - 2 < 2) {
      bStack_9 = pbVar2[0x14];
      goto LAB_fffb526d;
    }
    if (uVar3 - 4 < 2) {
      bStack_9 = pbVar2[0x32];
      goto LAB_fffb526d;
    }
    if (1 < uVar3 - 6) {
      if (uVar3 < 2) {
        bStack_9 = pbVar2[10];
      }
      else {
        bStack_9 = 0;
      }
      goto LAB_fffb526d;
    }
  }
  bStack_9 = pbVar2[0x3c];
LAB_fffb526d:
  return (bStack_9 & 2) != 0;
}


// ===== tx_mod_gain @ fffb527c (526 bytes)

/* Current modulation gain: MIC GAIN or per-mode USB/REAR MOD GAIN by MOD SOURCE */

byte tx_mod_gain(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  byte bStack_b;
  
  bVar2 = vfo_mode(g_ui.transmitting);
  cVar3 = FUN_fffb3d11(bVar2);
  bStack_b = 0;
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fffb5345:
    if (cVar3 == '\0') {
      bStack_b = g_opstate.mic_gain[1];
    }
    else if (cVar3 == '\x01') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010415_usb_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.usb_mod_gain;
      }
    }
    else if (cVar3 == '\x02') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010416_rear_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.rear_mod_gain;
      }
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (cVar3 == '\0') {
        return g_opstate.mic_gain[2];
      }
      if (cVar3 == '\x01') {
        if (g_opstate.preset_on != 0) {
          return g_ui.preset_active.usb_mod_gain;
        }
        return g_opstate.ex010215_usb_mod_gain;
      }
      if (cVar3 != '\x02') {
        return 0;
      }
      if (g_opstate.preset_on != 0) {
        return g_ui.preset_active.rear_mod_gain;
      }
      return g_opstate.ex010216_rear_mod_gain;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb5345;
      if (1 < uVar1 - 10) {
        if (1 < uVar1) {
          return 0;
        }
        if (cVar3 == '\0') {
          return g_opstate.mic_gain[0];
        }
        if (cVar3 == '\x01') {
          if (g_opstate.preset_on != 0) {
            return g_ui.preset_active.usb_mod_gain;
          }
          return g_opstate.ex010115_usb_mod_gain;
        }
        if (cVar3 != '\x02') {
          return 0;
        }
        if (g_opstate.preset_on != 0) {
          return g_ui.preset_active.rear_mod_gain;
        }
        return g_opstate.ex010116_rear_mod_gain;
      }
    }
    if (cVar3 == '\0') {
      bStack_b = g_opstate.mic_gain[3];
    }
    else if (cVar3 == '\x01') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010314_usb_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.usb_mod_gain;
      }
    }
    else if (cVar3 == '\x02') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010315_rear_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.rear_mod_gain;
      }
    }
  }
  return bStack_b;
}


// ===== FUN_fffb548a @ fffb548a (22 bytes)

char FUN_fffb548a(void)

{
  return g_opstate.ex020119_qsk_delay_time * '\x05' + '\x0f';
}


// ===== aess_level_ptr @ fffb54a0 (140 bytes)

/* Pointer to the active mode's AESS level byte (0x9C06 / 09 / 0A / 0B / 0C / 0E / 0F) [fact] (#157,
   CAT AS) */

uint aess_level_ptr(void)

{
  byte bVar1;
  undefined4 uStack_c;
  uint uVar2;
  
  bVar1 = vfo_mode(0);
  uVar2 = (uint)bVar1;
  if (uVar2 - 2 < 2) {
    uStack_c = 0x9c09;
  }
  else if (uVar2 - 4 < 2) {
    uStack_c = 0x9c0e;
  }
  else if (uVar2 - 6 < 2) {
    uStack_c = 0x9c0f;
  }
  else if (uVar2 - 8 < 2) {
    uStack_c = 0x9c0a;
  }
  else if (uVar2 - 10 < 2) {
    uStack_c = 0x9c0c;
  }
  else if (uVar2 - 0xc < 2) {
    uStack_c = 0x9c0b;
  }
  else if (uVar2 == 0xe) {
    uStack_c = 0x9c0d;
  }
  else {
    uStack_c = 0x9c06;
  }
  return uStack_c;
}


// ===== aess_mode_ptr @ fffb552c (140 bytes)

/* Pointer to the active mode's AESS on/off byte (0x9C10..) [fact] (#157, CAT AS) */

uint aess_mode_ptr(void)

{
  byte bVar1;
  undefined4 uStack_c;
  uint uVar2;
  
  bVar1 = vfo_mode(0);
  uVar2 = (uint)bVar1;
  if (uVar2 - 2 < 2) {
    uStack_c = 0x9c10;
  }
  else if (uVar2 - 4 < 2) {
    uStack_c = 0x9c15;
  }
  else if (uVar2 - 6 < 2) {
    uStack_c = 0x9c16;
  }
  else if (uVar2 - 8 < 2) {
    uStack_c = 0x9c11;
  }
  else if (uVar2 - 10 < 2) {
    uStack_c = 0x9c13;
  }
  else if (uVar2 - 0xc < 2) {
    uStack_c = 0x9c12;
  }
  else if (uVar2 == 0xe) {
    uStack_c = 0x9c14;
  }
  else {
    uStack_c = 0x9c07;
  }
  return uStack_c;
}


// ===== portctl_init @ fffb55b8 (10 bytes)

/* 0x12042=0 */

void portctl_init(void)

{
  DAT_00012042 = 0;
  return;
}


// ===== rf_ctrl_task @ fffb55c2 (41 bytes)

/* main loop: updates all shift registers and DACs when values change */

void rf_ctrl_task(void)

{
  pa_relay_update();
  rf_bpf_update();
  atu_relay_update();
  main_dac_update();
  pa_dac_update();
  FUN_fffb5d68();
  if (DAT_00012042 != '\0') {
    return;
  }
  DAT_00012042 = 1;
  return;
}


// ===== pa_relay_update @ fffb55eb (186 bytes)

/* /SST4: TX band one-hot + tuner/AM/RX/band-10 bits [inference] */

void pa_relay_update(void)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  uint uStack_8;
  
  bVar3 = vfo_mode(1);
  uVar2 = g_ui.freq_tx;
  bVar4 = FUN_fffb3337(g_ui.freq_tx);
  uStack_8 = 1 << (bVar4 & 0x1f);
  if (g_ui.atu_state == 2) {
    iVar6 = atu_tc_get();
    if ((iVar6 == 0) && (iVar6 = atu_ac_get(), iVar6 == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uStack_8 = uStack_8 | 0x80;
    }
  }
  if (bVar3 == 4) {
    uStack_8 = uStack_8 | 0x100;
  }
  bVar3 = rx_line_get();
  if (bVar3 == 1) {
    uStack_8 = uStack_8 | 0x200;
  }
  cVar5 = tx_band_of_freq(uVar2);
  if (cVar5 == '\n') {
    uStack_8 = uStack_8 | 0x400;
  }
  if ((DAT_00020f98 == uStack_8) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  shreg_write24(3,uStack_8);
  DAT_00020f98 = uStack_8;
  return;
}


// ===== rf_bpf_update @ fffb56a5 (225 bytes)

/* /SST3: RX/TX band one-hot + preamp/ATT bits [inference] */

void rf_bpf_update(void)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  uint uStack_c;
  uint uStack_8;
  
  pbVar5 = vfo_rec_ptr(g_ui.transmitting);
  bVar3 = pbVar5[3] & 3;
  bVar1 = pbVar5[5];
  if (g_ui.transmitting == 1) {
    uStack_8 = g_ui.freq_tx;
  }
  else {
    uStack_8 = vfo_freq(0,2);
    bVar4 = tx_line_get();
    if (bVar4 != 0) {
      return;
    }
  }
  bVar4 = FUN_fffb32fd(uStack_8);
  uStack_c = 1 << (bVar4 & 0x1f);
  if (bVar3 == 1) {
    uStack_c = uStack_c | 0x8000;
  }
  else if (bVar3 == 2) {
    uStack_c = uStack_c | 0x10000;
  }
  else if (bVar3 != 3) {
    uStack_c = uStack_c | 0x18000;
  }
  if ((bVar1 & 3) == 3) {
    uStack_c = uStack_c | 0x40000;
  }
  else if ((bVar1 & 3) == 0) {
    uStack_c = uStack_c | 0x20000;
  }
  uStack_c = uStack_c | 0x200000;
  if ((DAT_00020f9c == uStack_c) && (DAT_00012042 != '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (!bVar2) {
    return;
  }
  shreg_write24(2,uStack_c);
  DAT_00020f9c = uStack_c;
  return;
}


// ===== atu_relay_update @ fffb5786 (238 bytes)

/* /SST6: internal tuner relay bytes, SEND dropped 15 ms while switching [inference] */

void atu_relay_update(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uStack_8;
  
  bVar2 = send_a_get();
  uStack_8 = 0;
  if (g_ui.atu_state == 2) {
    iVar3 = atu_tc_get();
    uVar4 = atu_ac_get();
    uStack_8 = FUN_fffec51e();
    uStack_8 = uStack_8 | (uVar4 | iVar3 << 8) << 8;
  }
  if ((DAT_00020fa0 == uStack_8) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if (bVar2 != 0) {
      send_a_set(0);
      send_b_set(0);
      DAT_0001b4c5 = '\x01';
      swtimer_start(0x30,0xf);
    }
    shreg_write24(5,uStack_8);
    DAT_00020fa0 = uStack_8;
  }
  if ((DAT_0001b4c5 == '\x01') && (bVar2 = swtimer_expired(0x30), bVar2 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (g_ui.trx_state == 3)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return;
  }
  DAT_0001b4c5 = 0;
  send_a_set(1);
  send_b_set(1);
  return;
}


// ===== main_dac_update @ fffb5874 (258 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb58a4) */
/* WARNING: Removing unreachable block (ram,0xfffb5934) */
/* Q1005 ch3 (FADJ) and ch5 */

void main_dac_update(void)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  ushort local_a;
  
  sVar3 = ((ushort)g_cfg105.a003_gn_ref_freq - (ushort)(byte)g_opstate.ex030118_ref_freq_fine_adj &
          0xff) << 2;
  if ((DAT_00020fa4 == sVar3) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(0,3,sVar3);
    DAT_00020fa4 = sVar3;
  }
  uVar4 = vfo_freq(0,2);
  bVar2 = FUN_fffb33ab(uVar4);
  if (bVar2 < 5) {
    local_a = (ushort)g_cfg105.a023_rx_rf_agc_7;
  }
  else if (bVar2 < 7) {
    local_a = (ushort)g_cfg105.a024_rx_rf_agc_14;
  }
  else if (bVar2 < 9) {
    local_a = (ushort)g_cfg105.a025_rx_rf_agc_21;
  }
  else if (bVar2 < 0xb) {
    local_a = (ushort)g_cfg105.a026_rx_rf_agc_28;
  }
  else {
    local_a = (ushort)g_cfg105.a027_rx_rf_agc_50;
  }
  sVar3 = local_a << 2;
  if ((DAT_00020fa6 == sVar3) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(0,5,sVar3);
    DAT_00020fa6 = sVar3;
    return;
  }
  return;
}


// ===== pa_dac_update @ fffb5976 (1010 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb5b07) */
/* WARNING: Removing unreachable block (ram,0xfffb5a6c) */
/* WARNING: Removing unreachable block (ram,0xfffb5bbc) */
/* WARNING: Removing unreachable block (ram,0xfffb5caf) */
/* WARNING: Removing unreachable block (ram,0xfffb5d26) */
/* WARNING: Removing unreachable block (ram,0xfffb5aaf) */
/* WARNING: Removing unreachable block (ram,0xfffb5bff) */
/* WARNING: Removing unreachable block (ram,0xfffb5c42) */
/* PA BU2505 ch1..7,10: per-band cal, drive level, fan (ch6 from PA_HF_TH) [inference] */

void pa_dac_update(void)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  short sVar6;
  ushort uStack_14;
  ushort uStack_12;
  ushort uStack_10;
  ushort uStack_e;
  ushort uStack_c;
  ushort uStack_a;
  
  uVar2 = g_ui.freq_tx;
  bVar3 = (byte)(g_ui.adc_pa_hf_th >> 4);
  uVar4 = tx_band_of_freq(g_ui.freq_tx);
  switch(uVar4) {
  case 0:
    uStack_c = (ushort)g_cfg105.a235_tx_rev_alc_1_8;
    uStack_e = (ushort)g_cfg105.a059_tx_i_alc_1_8;
    break;
  case 1:
    uStack_c = (ushort)g_cfg105.a236_tx_rev_alc_3_5;
    uStack_e = (ushort)g_cfg105.a060_tx_i_alc_3_5;
    break;
  case 2:
    uStack_c = (ushort)g_cfg105.a237_tx_rev_alc_7;
    uStack_e = (ushort)g_cfg105.a061_tx_i_alc_7;
    break;
  case 3:
    uStack_c = (ushort)g_cfg105.a238_tx_rev_alc_10;
    uStack_e = (ushort)g_cfg105.a062_tx_i_alc_10;
    break;
  case 4:
    uStack_c = (ushort)g_cfg105.a239_tx_rev_alc_14;
    uStack_e = (ushort)g_cfg105.a063_tx_i_alc_14;
    break;
  case 5:
    uStack_c = (ushort)g_cfg105.a240_tx_rev_alc_18;
    uStack_e = (ushort)g_cfg105.a064_tx_i_alc_18;
    break;
  case 6:
    uStack_c = (ushort)g_cfg105.a241_tx_rev_alc_21;
    uStack_e = (ushort)g_cfg105.a065_tx_i_alc_21;
    break;
  case 7:
    uStack_c = (ushort)g_cfg105.a242_tx_rev_alc_24;
    uStack_e = (ushort)g_cfg105.a066_tx_i_alc_24;
    break;
  case 8:
    uStack_c = (ushort)g_cfg105.a243_tx_rev_alc_28;
    uStack_e = (ushort)g_cfg105.a067_tx_i_alc_28;
    break;
  case 9:
    uStack_c = (ushort)g_cfg105.a244_tx_rev_alc_50;
    uStack_e = (ushort)g_cfg105.a068_tx_i_alc_50;
    break;
  default:
    uStack_c = (ushort)g_cfg105.a245_tx_rev_alc_70;
    uStack_e = (ushort)g_cfg105.a069_tx_i_alc_70;
  }
  sVar6 = uStack_c << 2;
  if ((DAT_00020fa8 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,1,sVar6);
    DAT_00020fa8 = sVar6;
  }
  sVar6 = uStack_e << 2;
  if ((DAT_00020fb6 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,10,sVar6);
    DAT_00020fb6 = sVar6;
  }
  bVar5 = FUN_fffb4062();
  sVar6 = FUN_fffb667a(uVar4,bVar5);
  sVar6 = SUB42(ROUND((float)(((int)sVar6 & 0x3fffU) << 2) *
                      *(float *)(BYTE_ARRAY_fff88a14 + (uint)bVar5 * 4 + 0x54) + 0.5),0);
  if ((DAT_00020faa == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,2,sVar6);
    DAT_00020faa = sVar6;
  }
  bVar5 = FUN_fffb3337(uVar2);
  if (bVar5 == 0) {
    uStack_10 = (ushort)g_cfg105.a052_tx_mf_final_bias;
    uStack_12 = (ushort)g_cfg105.a051_tx_mf_drive_bias;
    uStack_14 = (ushort)g_cfg105.a050_tx_mf_predr_bias;
  }
  else if (bVar5 < 6) {
    uStack_10 = (ushort)g_cfg105.a055_tx_hf_final_bias;
    uStack_12 = (ushort)g_cfg105.a054_tx_hf_drive_bias;
    uStack_14 = (ushort)g_cfg105.a053_tx_hf_predr_bias;
  }
  else {
    uStack_10 = (ushort)g_cfg105.a058_tx_vhf_final_bias;
    uStack_12 = (ushort)g_cfg105.a057_tx_vhf_drive_bias;
    uStack_14 = (ushort)g_cfg105.a056_tx_vhf_predr_bias;
  }
  sVar6 = uStack_10 << 2;
  if ((DAT_00020fac == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,3,sVar6);
    DAT_00020fac = sVar6;
  }
  sVar6 = uStack_12 << 2;
  if ((DAT_00020fae == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,4,sVar6);
    DAT_00020fae = sVar6;
  }
  sVar6 = uStack_14 << 2;
  if ((DAT_00020fb0 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,5,sVar6);
    DAT_00020fb0 = sVar6;
  }
  if (bVar3 < g_cfg105.a002_gn_fan) {
    uStack_a = 0xad;
  }
  else if (g_cfg105.a002_gn_fan + 10 < (uint)bVar3) {
    uStack_a = 0;
  }
  else {
    uStack_a = DAT_00020fb2 >> 2;
  }
  uStack_a = uStack_a << 2;
  if ((DAT_00020fb2 == uStack_a) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bu2505_write(4,6,uStack_a);
    DAT_00020fb2 = uStack_a;
  }
  if (g_ui.tuner_result == 3) {
    uStack_a = 0xff;
  }
  else if (g_ui.tuner_result == 2) {
    uStack_a = 0x51;
  }
  else if (g_ui.tuner_result == 1) {
    uStack_a = 0x60;
  }
  else {
    uStack_a = 0;
  }
  if (g_opstate.ex030104_tuner_type_select != 3) {
    uStack_a = 0;
  }
  sVar6 = uStack_a << 2;
  if ((DAT_00020fb4 == sVar6) && (DAT_00012042 != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  bu2505_write(4,7,sVar6);
  DAT_00020fb4 = sVar6;
  return;
}


// ===== FUN_fffb5d68 @ fffb5d68 (2322 bytes)

void FUN_fffb5d68(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  byte bStack_b;
  byte bStack_a;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  
  uVar8 = audio_route_state();
  bVar2 = vfo_mode(0);
  bVar3 = FUN_fffb2dfe();
  FUN_fffb3d11(bVar2);
  bVar7 = g_ui.transmitting;
  bVar6 = false;
  bStack_e = 0;
  bStack_d = 0;
  bStack_b = 0;
  bStack_a = 0;
  bStack_9 = 0;
  bStack_8 = 0;
  bStack_f = g_ui.spk_boost_level;
  cVar4 = FUN_fffb3d11(bVar2);
  uVar1 = (uint)bVar2;
  if (uVar1 == 0xe) {
LAB_fffb6009:
    if (g_opstate.preset_on == 0) {
      bStack_9 = g_opstate.ex010411_usb_out_level;
      bStack_a = g_opstate.ex010412_rear_out_level;
    }
    else {
      bStack_9 = g_ui.preset_active.usb_out_level;
      bStack_a = g_ui.preset_active.rear_out_level;
    }
    if (cVar4 == '\0') {
      bStack_b = g_opstate.mic_gain[1];
    }
    else if (cVar4 == '\x01') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010415_usb_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.usb_mod_gain;
      }
    }
    else if (cVar4 == '\x02') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010416_rear_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.rear_mod_gain;
      }
    }
  }
  else if (uVar1 - 2 < 2) {
    if (g_opstate.preset_on == 0) {
      bStack_9 = g_opstate.ex020111_usb_out_level;
      bStack_a = g_opstate.ex020112_rear_out_level;
    }
    else {
      bStack_9 = g_ui.preset_active.usb_out_level;
      bStack_a = g_ui.preset_active.rear_out_level;
    }
  }
  else if (uVar1 - 4 < 2) {
    if (g_opstate.preset_on == 0) {
      bStack_9 = g_opstate.ex010211_usb_out_level;
      bStack_a = g_opstate.ex010212_rear_out_level;
    }
    else {
      bStack_9 = g_ui.preset_active.usb_out_level;
      bStack_a = g_ui.preset_active.rear_out_level;
    }
    if (cVar4 == '\0') {
      bStack_b = g_opstate.mic_gain[2];
    }
    else if (cVar4 == '\x01') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010215_usb_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.usb_mod_gain;
      }
    }
    else if (cVar4 == '\x02') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010216_rear_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.rear_mod_gain;
      }
    }
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb6009;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          if (g_opstate.preset_on == 0) {
            bStack_9 = g_opstate.ex010511_usb_out_level;
            bStack_a = g_opstate.ex010512_rear_out_level;
          }
          else {
            bStack_9 = g_ui.preset_active.usb_out_level;
            bStack_a = g_ui.preset_active.rear_out_level;
          }
        }
        else if (uVar1 < 2) {
          if (g_opstate.preset_on == 0) {
            bStack_9 = g_opstate.ex010111_usb_out_level;
            bStack_a = g_opstate.ex010112_rear_out_level;
          }
          else {
            bStack_9 = g_ui.preset_active.usb_out_level;
            bStack_a = g_ui.preset_active.rear_out_level;
          }
          if (cVar4 == '\0') {
            bStack_b = g_opstate.mic_gain[0];
          }
          else if (cVar4 == '\x01') {
            if (g_opstate.preset_on == 0) {
              bStack_b = g_opstate.ex010115_usb_mod_gain;
            }
            else {
              bStack_b = g_ui.preset_active.usb_mod_gain;
            }
          }
          else if (cVar4 == '\x02') {
            if (g_opstate.preset_on == 0) {
              bStack_b = g_opstate.ex010116_rear_mod_gain;
            }
            else {
              bStack_b = g_ui.preset_active.rear_mod_gain;
            }
          }
        }
        goto LAB_fffb612b;
      }
    }
    if (g_opstate.preset_on == 0) {
      bStack_9 = g_opstate.ex010311_usb_out_level;
      bStack_a = g_opstate.ex010312_rear_out_level;
    }
    else {
      bStack_9 = g_ui.preset_active.usb_out_level;
      bStack_a = g_ui.preset_active.rear_out_level;
    }
    if (cVar4 == '\0') {
      bStack_b = g_opstate.mic_gain[3];
    }
    else if (cVar4 == '\x01') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010314_usb_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.usb_mod_gain;
      }
    }
    else if (cVar4 == '\x02') {
      if (g_opstate.preset_on == 0) {
        bStack_b = g_opstate.ex010315_rear_mod_gain;
      }
      else {
        bStack_b = g_ui.preset_active.rear_mod_gain;
      }
    }
  }
LAB_fffb612b:
  bVar2 = FUN_fffb418a(bVar7);
  bVar7 = g_ui.af_gain;
  switch(uVar8) {
  case 0:
    bVar6 = ear_det();
    if (bVar6) {
      bStack_8 = FUN_fffb354d(bVar7);
      bStack_f = FUN_fffb3564(bVar7);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bVar6 = true;
    break;
  case 1:
    bVar6 = ear_det();
    if (bVar6) {
      bStack_8 = FUN_fffb354d(bVar7);
      bStack_f = FUN_fffb3564(bVar7);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    bVar6 = true;
    break;
  case 2:
    bVar5 = ear_det();
    if (bVar5) {
      bStack_8 = FUN_fffb354d(bVar7);
      bStack_f = FUN_fffb3564(bVar7);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    bStack_e = bVar2;
    break;
  case 3:
    bVar5 = ear_det();
    if (bVar5) {
      bStack_8 = FUN_fffb354d(bVar7);
      bStack_f = FUN_fffb3564(bVar7);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    bStack_e = bVar2;
    break;
  case 4:
    bVar5 = ear_det();
    if (bVar5) {
      bStack_8 = FUN_fffb354d(bVar7);
      bStack_f = FUN_fffb3564(bVar7);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    bStack_e = bVar2;
    break;
  case 5:
    bStack_8 = g_opstate.play_volume;
    bStack_d = 0xff;
    bStack_b = FUN_fffb34cf(0x32);
    break;
  case 6:
    bVar5 = ear_det();
    if (bVar5) {
      bStack_8 = FUN_fffb354d(bVar7);
      bStack_f = FUN_fffb3564(bVar7);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_d = 0xff;
    bStack_b = FUN_fffb34cf(0x1a);
    bStack_e = bVar2;
    break;
  case 7:
    bStack_8 = FUN_fffb34f9(bVar2);
    bStack_d = 0xff;
    bStack_b = FUN_fffb34cf(0x1a);
    break;
  case 8:
    bVar6 = ear_det();
    if (bVar6) {
      bStack_8 = FUN_fffb354d(bVar7);
      bStack_f = FUN_fffb3564(bVar7);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bVar7 = tx_mod_gain();
    bStack_b = FUN_fffb34cf(bVar7);
    bVar6 = true;
    break;
  case 9:
    bVar6 = ear_det();
    if (bVar6) {
      bStack_8 = FUN_fffb354d(bVar7);
      bStack_f = FUN_fffb3564(bVar7);
    }
    else {
      bStack_8 = FUN_fffb34ba();
    }
    bStack_b = FUN_fffb34cf(0x32);
    bVar6 = true;
    break;
  case 10:
    bStack_8 = FUN_fffb34f9(bVar2);
    bStack_b = FUN_fffb34cf(0x32);
    break;
  case 0xb:
  case 0xc:
    bStack_8 = g_opstate.play_volume;
    bStack_b = FUN_fffb34cf(0x32);
    break;
  case 0xd:
    bStack_8 = FUN_fffb34f9(bVar2);
    bVar7 = tx_mod_gain();
    bStack_b = FUN_fffb34cf(bVar7);
    break;
  case 0xe:
    bStack_8 = g_opstate.play_volume;
    bStack_b = FUN_fffb350e(g_opstate.level_9dc2);
  }
  if ((bVar3 - 1 < 3) || (bVar3 - 5 < 4)) {
    bStack_d = 0;
    bStack_e = g_opstate.ex030101_beep_level;
    if (g_opstate.ex030101_beep_level != 0) goto LAB_fffb6432;
  }
  if (g_ui.af_gain == 0) {
    if ((uVar8 == 4) || (uVar8 == 7)) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    if (bVar5) {
      iVar9 = FUN_fffb418a(g_ui.transmitting);
      if (iVar9 == 0) {
        FUN_fffb71f5();
      }
    }
    else if (bVar6) {
      FUN_fffb71f5();
    }
  }
LAB_fffb6432:
  if ((g_ui.trx_state < 3) && (bVar7 = swtimer_expired(0xe), bVar7 != 1)) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
  }
  if ((!bVar6) && (g_ui.tx_lamp != 2)) {
    if ((DAT_00020fbd == bStack_8) && (DAT_00012042 != '\0')) {
      bVar6 = false;
    }
    else {
      bVar6 = true;
    }
    if (bVar6) {
      sst2_write12('\x01',bStack_8);
      DAT_00020fbd = bStack_8;
    }
    if ((DAT_00020fbc == bStack_8) && (DAT_00012042 != '\0')) {
      bVar6 = false;
    }
    else {
      bVar6 = true;
    }
    if (bVar6) {
      sst2_write12('\x05',bStack_8);
      DAT_00020fbc = bStack_8;
    }
  }
  bStack_7 = FUN_fffb34f9(bStack_9);
  if (g_ui.transmitting != 0) {
    bStack_7 = 0;
  }
  if ((DAT_00020fb8 == bStack_7) && (DAT_00012042 != '\0')) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  if (bVar6) {
    sst2_write12('\x02',bStack_7);
    DAT_00020fb8 = bStack_7;
  }
  bVar7 = FUN_fffb34f9(bStack_a);
  if ((DAT_00020fb9 == bVar7) && (DAT_00012042 != '\0')) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  if (bVar6) {
    sst2_write12('\x03',bVar7);
    DAT_00020fb9 = bVar7;
  }
  if ((DAT_00020fba == bStack_b) && (DAT_00012042 != '\0')) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  if (bVar6) {
    sst2_write12('\x04',bStack_b);
    DAT_00020fba = bStack_b;
  }
  if ((DAT_00020fbe == bStack_d) && (DAT_00012042 != '\0')) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  if (bVar6) {
    sst2_write12('\x06',bStack_d);
    DAT_00020fbe = bStack_d;
  }
  bVar7 = FUN_fffb34f9(bStack_e);
  if ((DAT_00020fbf == bVar7) && (DAT_00012042 != '\0')) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  if (bVar6) {
    sst2_write12('\a',bVar7);
    DAT_00020fbf = bVar7;
  }
  if ((DAT_00020fbb == bStack_f) && (DAT_00012042 != '\0')) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  if (bVar6) {
    sst2_write12('\b',bStack_f);
    DAT_00020fbb = bStack_f;
    return;
  }
  return;
}


// ===== FUN_fffb667a @ fffb667a (1636 bytes)

char FUN_fffb667a(undefined1 param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  byte local_e;
  char local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  byte local_9;
  
  switch(param_1) {
  case 0:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a070_tx_100w_falc_1_8;
      local_c = g_cfg105.a070_tx_100w_falc_1_8;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a079_tx_10w_falc_1_8;
          local_c = g_cfg105.a082_tx_5w_falc_1_8;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a076_tx_20w_falc_1_8;
          local_c = g_cfg105.a079_tx_10w_falc_1_8;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a073_tx_50w_falc_1_8;
        local_c = g_cfg105.a076_tx_20w_falc_1_8;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a070_tx_100w_falc_1_8;
      local_c = g_cfg105.a073_tx_50w_falc_1_8;
    }
    local_e = g_cfg105.a071_tx_100w_mtr_1_8;
    break;
  case 1:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a085_tx_100w_falc_3_5;
      local_c = g_cfg105.a085_tx_100w_falc_3_5;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a094_tx_10w_falc_3_5;
          local_c = g_cfg105.a097_tx_5w_falc_3_5;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a091_tx_20w_falc_3_5;
          local_c = g_cfg105.a094_tx_10w_falc_3_5;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a088_tx_50w_falc_3_5;
        local_c = g_cfg105.a091_tx_20w_falc_3_5;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a085_tx_100w_falc_3_5;
      local_c = g_cfg105.a088_tx_50w_falc_3_5;
    }
    local_e = g_cfg105.a086_tx_100w_mtr_3_5;
    break;
  case 2:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a100_tx_100w_falc_7;
      local_c = g_cfg105.a100_tx_100w_falc_7;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a109_tx_10w_falc_7;
          local_c = g_cfg105.a112_tx_5w_falc_7;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a106_tx_20w_falc_7;
          local_c = g_cfg105.a109_tx_10w_falc_7;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a103_tx_50w_falc_7;
        local_c = g_cfg105.a106_tx_20w_falc_7;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a100_tx_100w_falc_7;
      local_c = g_cfg105.a103_tx_50w_falc_7;
    }
    local_e = g_cfg105.a101_tx_100w_mtr_7;
    break;
  case 3:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a115_tx_100w_falc_10;
      local_c = g_cfg105.a115_tx_100w_falc_10;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a124_tx_10w_falc_10;
          local_c = g_cfg105.a127_tx_5w_falc_10;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a121_tx_20w_falc_10;
          local_c = g_cfg105.a124_tx_10w_falc_10;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a118_tx_50w_falc_10;
        local_c = g_cfg105.a121_tx_20w_falc_10;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a115_tx_100w_falc_10;
      local_c = g_cfg105.a118_tx_50w_falc_10;
    }
    local_e = g_cfg105.a116_tx_100w_mtr_10;
    break;
  case 4:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a130_tx_100w_falc_14;
      local_c = g_cfg105.a130_tx_100w_falc_14;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a139_tx_10w_falc_14;
          local_c = g_cfg105.a142_tx_5w_falc_14;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a136_tx_20w_falc_14;
          local_c = g_cfg105.a139_tx_10w_falc_14;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a133_tx_50w_falc_14;
        local_c = g_cfg105.a136_tx_20w_falc_14;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a130_tx_100w_falc_14;
      local_c = g_cfg105.a133_tx_50w_falc_14;
    }
    local_e = g_cfg105.a131_tx_100w_mtr_14;
    break;
  case 5:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a145_tx_100w_falc_18;
      local_c = g_cfg105.a145_tx_100w_falc_18;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a154_tx_10w_falc_18;
          local_c = g_cfg105.a157_tx_5w_falc_18;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a151_tx_20w_falc_18;
          local_c = g_cfg105.a154_tx_10w_falc_18;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a148_tx_50w_falc_18;
        local_c = g_cfg105.a151_tx_20w_falc_18;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a145_tx_100w_falc_18;
      local_c = g_cfg105.a148_tx_50w_falc_18;
    }
    local_e = g_cfg105.a146_tx_100w_mtr_18;
    break;
  case 6:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a160_tx_100w_falc_21;
      local_c = g_cfg105.a160_tx_100w_falc_21;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a169_tx_10w_falc_21;
          local_c = g_cfg105.a172_tx_5w_falc_21;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a166_tx_20w_falc_21;
          local_c = g_cfg105.a169_tx_10w_falc_21;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a163_tx_50w_falc_21;
        local_c = g_cfg105.a166_tx_20w_falc_21;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a160_tx_100w_falc_21;
      local_c = g_cfg105.a163_tx_50w_falc_21;
    }
    local_e = g_cfg105.a161_tx_100w_mtr_21;
    break;
  case 7:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a175_tx_100w_falc_24;
      local_c = g_cfg105.a175_tx_100w_falc_24;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a184_tx_10w_falc_24;
          local_c = g_cfg105.a187_tx_5w_falc_24;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a181_tx_20w_falc_24;
          local_c = g_cfg105.a184_tx_10w_falc_24;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a178_tx_50w_falc_24;
        local_c = g_cfg105.a181_tx_20w_falc_24;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a175_tx_100w_falc_24;
      local_c = g_cfg105.a178_tx_50w_falc_24;
    }
    local_e = g_cfg105.a176_tx_100w_mtr_24;
    break;
  case 8:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a190_tx_100w_falc_28;
      local_c = g_cfg105.a190_tx_100w_falc_28;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a199_tx_10w_falc_28;
          local_c = g_cfg105.a202_tx_5w_falc_28;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a196_tx_20w_falc_28;
          local_c = g_cfg105.a199_tx_10w_falc_28;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a193_tx_50w_falc_28;
        local_c = g_cfg105.a196_tx_20w_falc_28;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a190_tx_100w_falc_28;
      local_c = g_cfg105.a193_tx_50w_falc_28;
    }
    local_e = g_cfg105.a191_tx_100w_mtr_28;
    break;
  case 9:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a205_tx_100w_falc_50;
      local_c = g_cfg105.a205_tx_100w_falc_50;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a214_tx_10w_falc_50;
          local_c = g_cfg105.a217_tx_5w_falc_50;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a211_tx_20w_falc_50;
          local_c = g_cfg105.a214_tx_10w_falc_50;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a208_tx_50w_falc_50;
        local_c = g_cfg105.a211_tx_20w_falc_50;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a205_tx_100w_falc_50;
      local_c = g_cfg105.a208_tx_50w_falc_50;
    }
    local_e = g_cfg105.a206_tx_100w_mtr_50;
    break;
  default:
    if (param_2 == 100) {
      local_9 = 0;
      local_a = 0;
      local_b = g_cfg105.a223_tx_50w_falc_70;
      local_c = g_cfg105.a223_tx_50w_falc_70;
    }
    else if (param_2 < 0x32) {
      if (param_2 < 0x14) {
        if (param_2 < 10) {
          local_9 = param_2 - 5;
          local_a = 5;
          local_b = g_cfg105.a229_tx_10w_falc_70;
          local_c = g_cfg105.a232_tx_5w_falc_70;
        }
        else {
          local_9 = param_2 - 10;
          local_a = 10;
          local_b = g_cfg105.a226_tx_20w_falc_70;
          local_c = g_cfg105.a229_tx_10w_falc_70;
        }
      }
      else {
        local_9 = param_2 - 0x14;
        local_a = 0x1e;
        local_b = g_cfg105.a223_tx_50w_falc_70;
        local_c = g_cfg105.a226_tx_20w_falc_70;
      }
    }
    else {
      local_9 = param_2 - 0x32;
      local_a = 0x32;
      local_b = g_cfg105.a223_tx_50w_falc_70;
      local_c = g_cfg105.a223_tx_50w_falc_70;
    }
    local_e = g_cfg105.a224_tx_50w_mtr_70;
  }
  g_ui.po_meter_scale = local_e;
  if (local_b < local_c) {
    iVar2 = ((uint)local_c - (uint)local_b) * (uint)local_9;
    uVar1 = (uint)local_a;
    if (uVar1 != 0 && (iVar2 != -0x80000000 || uVar1 != 0xffffffff)) {
      iVar2 = iVar2 / (int)uVar1;
    }
    local_d = (char)iVar2;
  }
  else {
    iVar2 = ((uint)local_b - (uint)local_c) * (uint)local_9;
    uVar1 = (uint)local_a;
    if (uVar1 != 0 && (iVar2 != -0x80000000 || uVar1 != 0xffffffff)) {
      iVar2 = iVar2 / (int)uVar1;
    }
    local_d = (char)iVar2;
  }
  local_d = local_d + local_c;
  return local_d;
}


// ===== trx_init @ fffb6cde (120 bytes)

/* trx_state=4, timer 0x13 2.5 s, AF_MUTE on */

void trx_init(void)

{
  byte bVar1;
  byte bStack_1;
  
  g_ui.trx_state = 4;
  g_ui.transmitting = 0;
  DAT_0001204d = 0;
  swtimer_start(0x13,0x9c4);
  bVar1 = PORTB_PODR;
  PORTB_PODR = bVar1 | 8;
  g_ui.pb3_last = 1;
  for (bStack_1 = 0; bStack_1 < 4; bStack_1 = bStack_1 + 1) {
    g_ui.scope_cursor_start =
         g_ui.scope_cursor_start << 8 | (uint)g_opstate.scope_cursor_start_be[bStack_1];
  }
  return;
}


// ===== io_task @ fffb6d56 (173 bytes)

/* main loop: AF mute, meters, io_poll, power checks */

void io_task(void)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  
  bVar1 = swtimer_expired(0x2a);
  if (((bVar1 != 0) && (bVar2 = af_mute_get(), bVar2 != (bool)g_ui.pb3_last)) &&
     (g_ui.trx_state == 8)) {
    af_mute_set(g_ui.pb3_last);
  }
  meter_task();
  io_poll();
  FUN_fffb8d77();
  FUN_fffb9605();
  cVar3 = supply_undervolt_check();
  if (cVar3 != '\x01') {
    if (g_ui.power_key_req == 2) {
      g_opstate.auto_power_on = 0;
      FUN_fffd3d03();
      if (g_ui.zz_align_mode == 0) {
        eeprom_save_opstate();
      }
      do {
        bVar1 = sci1_tx_end();
      } while (bVar1 == 0);
      sw_reset();
    }
    iVar4 = screensaver_timer_expired();
    if (iVar4 == 1) {
      if (g_ui.screensaver_on == 0) {
        g_ui.screensaver_toggle_req = 1;
        return;
      }
    }
    else if (g_ui.screensaver_on != 0) {
      g_ui.screensaver_toggle_req = 1;
      return;
    }
  }
  return;
}


// ===== meter_get_vdd @ fffb6e03 (15 bytes)

byte meter_get_vdd(void)

{
  return DAT_00012043;
}


// ===== meter_get_idd @ fffb6e12 (15 bytes)

byte meter_get_idd(void)

{
  return DAT_00012044;
}


// ===== meter_get_alc @ fffb6e21 (15 bytes)

byte meter_get_alc(void)

{
  return DAT_00012045;
}


// ===== meter_get_swr @ fffb6e30 (15 bytes)

byte meter_get_swr(void)

{
  return DAT_00012046;
}


// ===== meter_get_swr_raw @ fffb6e3f (15 bytes)

byte meter_get_swr_raw(void)

{
  return DAT_00012047;
}


// ===== FUN_fffb6e4e @ fffb6e4e (14 bytes)

void FUN_fffb6e4e(void)

{
  return;
}


// ===== FUN_fffb6e5c @ fffb6e5c (14 bytes)

void FUN_fffb6e5c(void)

{
  return;
}


// ===== meter_get_po @ fffb6e6a (46 bytes)

byte meter_get_po(void)

{
  undefined1 local_3;
  
  if (g_opstate.ex030408_meter_detector == 0) {
    local_3 = DAT_00012048;
  }
  else {
    local_3 = DAT_0001204b;
  }
  return local_3;
}


// ===== meter_get_comp @ fffb6e98 (15 bytes)

byte meter_get_comp(void)

{
  return DAT_00012049;
}


// ===== meter_get_s @ fffb6ea7 (15 bytes)

byte meter_get_s(void)

{
  return DAT_0001204a;
}


// ===== remote_key_get @ fffb6eb6 (15 bytes)

byte remote_key_get(void)

{
  return DAT_0001204c;
}


// ===== ptt_source_get @ fffb6ec5 (15 bytes)

/* returns 0x1204D (CAT TX read: 0->TX0, 5->TX1, else TX2) */

byte ptt_source_get(void)

{
  return DAT_0001204d;
}


// ===== ckey_det @ fffb6ed4 (31 bytes)

/* P87 */

bool ckey_det(void)

{
  char cVar1;
  
  cVar1 = PORT8_PIDR;
  return -1 < cVar1;
}


// ===== ckey_dot @ fffb6ef3 (24 bytes)

/* P16 low */

bool ckey_dot(void)

{
  byte bVar1;
  
  bVar1 = PORT1_PIDR;
  return (bVar1 & 0x40) == 0;
}


// ===== ckey_dash @ fffb6f0b (31 bytes)

/* P17 low */

bool ckey_dash(void)

{
  char cVar1;
  
  cVar1 = PORT1_PIDR;
  return -1 < cVar1;
}


// ===== jp_p51_get @ fffb6f2a (19 bytes)

/* P51 strap */

byte jp_p51_get(void)

{
  byte bVar1;
  
  bVar1 = PORT5_PIDR;
  return bVar1 >> 1 & 1;
}


// ===== FUN_fffb6f3d @ fffb6f3d (19 bytes)

byte FUN_fffb6f3d(void)

{
  byte bVar1;
  
  bVar1 = PORT5_PIDR;
  return bVar1 >> 2 & 1;
}


// ===== FUN_fffb6f50 @ fffb6f50 (19 bytes)

byte FUN_fffb6f50(void)

{
  byte bVar1;
  
  bVar1 = PORT5_PIDR;
  return bVar1 >> 3 & 1;
}


// ===== FUN_fffb6f63 @ fffb6f63 (19 bytes)

byte FUN_fffb6f63(void)

{
  byte bVar1;
  
  bVar1 = PORT5_PIDR;
  return bVar1 >> 4 & 1;
}


// ===== atas_det @ fffb6f76 (30 bytes)

/* P55 */

bool atas_det(void)

{
  byte bVar1;
  
  bVar1 = PORT5_PIDR;
  return (bVar1 >> 5 & 1) == 1;
}


// ===== FUN_fffb6f94 @ fffb6f94 (24 bytes)

void FUN_fffb6f94(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT7_PODR;
  PORT7_PODR = bVar1 & 0xf7 | (param_1 & 1) << 3;
  return;
}


// ===== tx_line_get @ fffb6fac (19 bytes)

/* P73 TX */

byte tx_line_get(void)

{
  byte bVar1;
  
  bVar1 = PORT7_PODR;
  return bVar1 >> 3 & 1;
}


// ===== send_a_get @ fffb6fbf (19 bytes)

byte send_a_get(void)

{
  byte bVar1;
  
  bVar1 = PORTA_PODR;
  return bVar1 >> 2 & 1;
}


// ===== send_a_set @ fffb6fd2 (63 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7007) */
/* PA2 SEND_A, forced 0 if ETUN_TXINH_REQ or TX line low */

void send_a_set(byte param_1)

{
  byte bVar1;
  bool bVar2;
  byte local_1;
  
  bVar1 = PORT1_PIDR;
  if (((bVar1 >> 4 & 1) == 1) || (bVar1 = PORT7_PODR, (bVar1 & 8) == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_1 = param_1;
  if (bVar2) {
    local_1 = 0;
  }
  bVar1 = PORTA_PODR;
  PORTA_PODR = bVar1 & 0xfb | (local_1 & 1) << 2;
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
  
  bVar1 = PORT1_PIDR;
  if (((bVar1 >> 4 & 1) == 1) || (bVar1 = PORT7_PODR, (bVar1 & 8) == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_1 = param_1;
  if (bVar2) {
    local_1 = 0;
  }
  bVar1 = PORTB_PODR;
  PORTB_PODR = bVar1 & 0xef | (local_1 & 1) << 4;
  return;
}


// ===== sdr_reset_set @ fffb7051 (22 bytes)

/* P77 */

void sdr_reset_set(char param_1)

{
  byte bVar1;
  
  bVar1 = PORT7_PODR;
  PORT7_PODR = bVar1 & 0x7f | param_1 << 7;
  return;
}


// ===== sdr_update_set @ fffb7067 (25 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb7075) */
/* P76 */

void sdr_update_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT7_PODR;
  PORT7_PODR = bVar1 & 0xbf | (param_1 & 1) << 6;
  return;
}


// ===== dsp_reset_set @ fffb7080 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb708e) */
/* P71 */

void dsp_reset_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT7_PODR;
  PORT7_PODR = bVar1 & 0xfd | (param_1 & 1) << 1;
  return;
}


// ===== dsp_update_set @ fffb7098 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb70a6) */
/* P72 */

void dsp_update_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT7_PODR;
  PORT7_PODR = bVar1 & 0xfb | (param_1 & 1) << 2;
  return;
}


// ===== af_reset_set @ fffb70b0 (25 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb70be) */
/* P74 */

void af_reset_set(byte param_1)

{
  byte bVar1;
  
  bVar1 = PORT7_PODR;
  PORT7_PODR = bVar1 & 0xef | (param_1 & 1) << 4;
  return;
}

