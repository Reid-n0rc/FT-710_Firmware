// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== bcd_to_bin @ fffb2fc0 (44 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2fd4) */
/* Packed BCD byte -> binary: ROM table 0xFFF880C2 (0, 10, .., 90 at stride 2)[high nibble] + low
   nibble [fact] */

char bcd_to_bin(byte param_1)

{
  return *(char *)((int)&PTR_USB0_SYSCFG_fff880c2 + (uint)(param_1 >> 4) * 2) + (param_1 & 0xf);
}


// ===== FUN_fffb2fec @ fffb2fec (93 bytes)

short FUN_fffb2fec(ushort param_1)

{
  return *(short *)(BYTE_ARRAY_fff880c6 + (uint)(param_1 >> 0xc) * 2 + 0x24) +
         *(short *)(BYTE_ARRAY_fff880c6 + (param_1 >> 8 & 0xf) * 2 + 0x10) +
         *(short *)((int)&PTR_USB0_SYSCFG_fff880c2 + (param_1 >> 4 & 0xf) * 2) + (param_1 & 0xf);
}


// ===== FUN_fffb3049 @ fffb3049 (108 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb3083) */
/* WARNING: Removing unreachable block (ram,0xfffb3059) */
/* WARNING: Removing unreachable block (ram,0xfffb3070) */
/* WARNING: Removing unreachable block (ram,0xfffb309d) */

ushort FUN_fffb3049(byte param_1)

{
  ushort local_8;
  byte local_1;
  
  local_8 = 0;
  local_1 = param_1;
  if (99 < param_1) {
    local_8 = *(ushort *)(BYTE_ARRAY_fff88111 + (uint)(param_1 / 100) * 2 + 1);
    local_1 = param_1 % 100;
  }
  if (9 < local_1) {
    local_8 = *(ushort *)(BYTE_ARRAY_fff880c6 + (uint)(local_1 / 10) * 2 + 0x38) | local_8;
    local_1 = local_1 % 10;
  }
  return local_8 | local_1;
}


// ===== ascii2_to_bcd @ fffb30b5 (104 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb30e6) */
/* Two ASCII digits -> packed BCD byte (each digit only if '0'..'9', checked on the first char)
   [fact: fffb30b5]; only caller cat_DT */

byte ascii2_to_bcd(byte *param_1)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte local_6;
  
  local_6 = 0;
  if ((*param_1 < 0x30) || (0x39 < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    cVar2 = hex2nib(*param_1);
    local_6 = cVar2 << 4;
  }
  if ((*param_1 < 0x30) || (0x39 < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bVar3 = hex2nib(param_1[1]);
    local_6 = bVar3 | local_6;
  }
  return local_6;
}


// ===== bcd_to_ascii2 @ fffb311d (75 bytes)

/* Packed BCD byte -> two ASCII digits from "0123456789ABCDEF", a space for a nibble above 9 [fact:
   fffb311d]; only caller cat_DT */

void bcd_to_ascii2(char *param_1,uint param_2)

{
  byte bVar1;
  
  if ((param_2 >> 4 & 0xff) < 10) {
    *param_1 = "@0123456789ABCDEF"[(param_2 >> 4 & 0xff) + 1];
  }
  else {
    *param_1 = ' ';
  }
  bVar1 = (byte)param_2 & 0xf;
  if (9 < bVar1) {
    param_1[1] = ' ';
    return;
  }
  param_1[1] = "@0123456789ABCDEF"[bVar1 + 1];
  return;
}


// ===== toupper_inplace @ fffb3168 (46 bytes)

/* a-z -> A-Z on one byte in place */

void toupper_inplace(char *c)

{
  bool bVar1;
  
  if (((byte)*c < 0x61) || (0x7a < (byte)*c)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    *c = *c + -0x20;
    return;
  }
  return;
}


// ===== vfo_mode @ fffb3196 (182 bytes)

/* (which): mode nibble (rec+0) of vfo_rec_ptr(which); forced to 2 during tune cycles */

byte vfo_mode(byte which)

{
  undefined1 local_a;
  undefined1 local_9;
  
  local_a = 0;
  if (which != 0) {
    local_a = g_opstate.split_on;
  }
  if (g_opstate.active_vfo == VFO_A) {
    if (local_a == 0) {
      local_9 = g_opstate.vfo_a.mode;
    }
    else {
      local_9 = g_opstate.vfo_b.mode;
    }
  }
  else if (local_a == 0) {
    local_9 = g_opstate.vfo_b.mode;
  }
  else {
    local_9 = g_opstate.vfo_a.mode;
  }
  if (g_ui.tune_cycle == 1) {
    local_9 = 2;
  }
  else if (g_ui.tune_cycle == 2) {
    local_9 = 2;
  }
  else if (g_ui.tune_cycle_3c == 2) {
    local_9 = 2;
  }
  else if (g_ui.tune_cycle_3d == 2) {
    local_9 = 2;
  }
  else if (g_ui.ptt_extpa == 1) {
    local_9 = 2;
  }
  return local_9 & 0xf;
}


// ===== vfo_rec_ptr @ fffb324c (94 bytes)

/* (which): 0 = active VFO record (0x9DBD), !=0 = TX record (other VFO while split 0x9C5E); returns
   0x9D09/0x9D63 in R1 */

byte * vfo_rec_ptr(byte which)

{
  byte local_11;
  vfo_rec *local_10;
  
  local_11 = 0;
  if (which != 0) {
    local_11 = g_opstate.split_on;
  }
  if (g_opstate.active_vfo == VFO_A) {
    if (local_11 == 0) {
      local_10 = &g_opstate.vfo_a;
    }
    else {
      local_10 = &g_opstate.vfo_b;
    }
  }
  else if (local_11 == 0) {
    local_10 = &g_opstate.vfo_b;
  }
  else {
    local_10 = &g_opstate.vfo_a;
  }
  return &local_10->mode;
}


// ===== FUN_fffb32aa @ fffb32aa (83 bytes)

undefined1 FUN_fffb32aa(char param_1)

{
  undefined1 local_a;
  undefined1 local_9;
  
  local_9 = 0;
  if (param_1 != '\0') {
    local_9 = g_opstate.split_on;
  }
  if (g_opstate.active_vfo == VFO_A) {
    if (local_9 == 0) {
      local_a = 0;
    }
    else {
      local_a = 1;
    }
  }
  else if (local_9 == 0) {
    local_a = 1;
  }
  else {
    local_a = 0;
  }
  return local_a;
}


// ===== FUN_fffb32fd @ fffb32fd (58 bytes)

byte FUN_fffb32fd(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xd < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886b8 + (uint)local_d * 4)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb3337 @ fffb3337 (58 bytes)

byte FUN_fffb3337(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (6 < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_d * 4 + 0x28)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== tx_band_of_freq @ fffb3371 (58 bytes)

/* (f): index 0..10 of the first bound in ROM 0xFFF8870C (2.1 / 4.7 / 7.5 / 11.5 / 14.5 / 20.9 / 22
   / 25.5 / 41.5 / 60 / 75 MHz) above f, else 0xFF [fact] */

byte tx_band_of_freq(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (10 < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_d * 4 + 0x44)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb33ab @ fffb33ab (58 bytes)

byte FUN_fffb33ab(uint param_1)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xc < local_d) {
      return 0xff;
    }
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_d * 4 + 0x70)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== band_of_freq @ fffb33e5 (96 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb33f4) */
/* WARNING: Removing unreachable block (ram,0xfffb3403) */
/* Band index 0..11 of a frequency (ranges at 0xFFF8876C), 0xFF if none */

byte band_of_freq(uint freq)

{
  bool bVar1;
  byte local_11;
  
  local_11 = 0;
  while( true ) {
    if (0xb < local_11) {
      return 0xff;
    }
    if ((freq < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_11 * 8 + 0xa4)) ||
       (*(uint *)(BYTE_ARRAY_fff886c8 + (uint)local_11 * 8 + 0xa8) <= freq)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) break;
    local_11 = local_11 + 1;
  }
  return local_11;
}


// ===== gen_subband_of_freq @ fffb3445 (59 bytes)

/* GEN sub-slot 0..15 from boundaries at 0xFFF887CC */

byte gen_subband_of_freq(uint freq)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0x11 < local_d) {
      return 0xff;
    }
    if (freq < *(uint *)(BYTE_ARRAY_fff887c4 + (uint)local_d * 4 + 8)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== freq_range_index @ fffb3480 (58 bytes)

/* Index of f in boundary table 0xFFF88814 */

byte freq_range_index(uint freq)

{
  byte local_d;
  
  local_d = 0;
  while( true ) {
    if (0xd < local_d) {
      return 0xff;
    }
    if (freq < *(uint *)(BYTE_ARRAY_fff887dc + (uint)local_d * 4 + 0x38)) break;
    local_d = local_d + 1;
  }
  return local_d;
}


// ===== FUN_fffb34ba @ fffb34ba (21 bytes)

char FUN_fffb34ba(byte param_1)

{
  return "@0123456789ABCDEF"[param_1 + 0x11];
}


// ===== FUN_fffb34cf @ fffb34cf (21 bytes)

byte FUN_fffb34cf(byte param_1)

{
  return BYTE_ARRAY_fff81041[param_1 + 0xd7];
}


// ===== FUN_fffb34e4 @ fffb34e4 (21 bytes)

undefined2 FUN_fffb34e4(byte param_1)

{
  return *(undefined2 *)((int)&PTR_DAT_fff88126 + (uint)param_1 * 2);
}


// ===== FUN_fffb34f9 @ fffb34f9 (21 bytes)

byte FUN_fffb34f9(byte param_1)

{
  return BYTE_ARRAY_fff81041[param_1 + 0x13c];
}


// ===== FUN_fffb350e @ fffb350e (21 bytes)

undefined2 FUN_fffb350e(byte param_1)

{
  return *(undefined2 *)(BYTE_ARRAY_fff881a8 + (uint)param_1 * 2 + 0x48);
}


// ===== FUN_fffb3523 @ fffb3523 (21 bytes)

byte FUN_fffb3523(byte param_1)

{
  return BYTE_ARRAY_fff81041[param_1 + 0x1a1];
}


// ===== FUN_fffb3538 @ fffb3538 (21 bytes)

byte FUN_fffb3538(byte param_1)

{
  return BYTE_ARRAY_fff812ba[param_1 + 0x28];
}


// ===== FUN_fffb354d @ fffb354d (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb3553) */

char FUN_fffb354d(byte param_1)

{
  return " \"#%&(*+-/1357:<<<<<<<<<<<"[(uint)param_1 * 2 + 0x1a];
}


// ===== FUN_fffb3564 @ fffb3564 (24 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb356a) */

byte FUN_fffb3564(byte param_1)

{
  return BYTE_ARRAY_fff81348[(uint)param_1 * 2];
}


// ===== vfo_freq @ fffb357c (91 bytes)

/* (which, side): BE u32 at rec+0x4A; side 0=A 1=B 2=vfo_rec_ptr(which) */

uint vfo_freq(byte which,byte side)

{
  byte local_15;
  uint uStack_14;
  vfo_rec *local_10;
  
  if (side == 0) {
    local_10 = &g_opstate.vfo_a;
  }
  else if (side == 1) {
    local_10 = &g_opstate.vfo_b;
  }
  else {
    local_10 = (vfo_rec *)vfo_rec_ptr(which);
  }
  for (local_15 = 0; local_15 < 4; local_15 = local_15 + 1) {
    uStack_14 = (uint)local_10->freq_be[local_15] | uStack_14 << 8;
  }
  return uStack_14;
}


// ===== vfo_freq_clar @ fffb35d7 (296 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb36cf) */
/* (which, side): vfo_freq + clar offset rec+0x48 if RX/TX clar bit set in 0x20F29/0x20F2A */

uint vfo_freq_clar(byte which,byte side)

{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  byte bStack_18;
  byte bStack_17;
  uint uStack_14;
  vfo_rec *pvStack_10;
  
  uStack_14 = vfo_freq(which,side);
  bStack_18 = 0;
  bVar2 = false;
  if (side == 0) {
    bStack_17 = g_ui.clar_flags_a;
    pvStack_10 = &g_opstate.vfo_a;
  }
  else if (side == 1) {
    bStack_17 = g_ui.clar_flags_b;
    pvStack_10 = &g_opstate.vfo_b;
  }
  else {
    pvStack_10 = (vfo_rec *)vfo_rec_ptr(which);
    if (which != 0) {
      bStack_18 = g_opstate.split_on;
    }
    if (g_opstate.active_vfo == VFO_A) {
      if (bStack_18 == 0) {
        bStack_17 = g_ui.clar_flags_a;
      }
      else {
        bStack_17 = g_ui.clar_flags_b;
      }
    }
    else if (bStack_18 == 0) {
      bStack_17 = g_ui.clar_flags_b;
    }
    else {
      bStack_17 = g_ui.clar_flags_a;
    }
  }
  if ((which == 0) || ((bStack_17 & 2) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    bVar2 = true;
  }
  else {
    if ((which == 0) && ((bStack_17 & 1) != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    uVar3 = CONCAT11(pvStack_10->clar_offset_be[0],pvStack_10->clar_offset_be[1]);
    if ((pvStack_10->clar_offset_be[0] & 0x80) == 0) {
      uStack_14 = uVar3 + uStack_14;
    }
    else {
      uStack_14 = uStack_14 - (ushort)(~uVar3 + 1);
    }
  }
  return uStack_14;
}


// ===== width_index_of_hz @ fffb36ff (118 bytes)

/* (mode, hz): index of a filter width in Hz in table 0xFFF88270 (+0x78: 21 entries for
   CW/DATA/RTTY/PSK, +0x4A: 23 entries for LSB/USB), 0xFF if none [fact: fffb36ff]; callers cat_SH,
   cat_ai_SH, dsp_knob_width_step */

byte width_index_of_hz(byte param_1,short param_2)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    for (local_6 = 0; local_6 < 0x15; local_6 = local_6 + 1) {
      if (param_2 == *(short *)(BYTE_ARRAY_fff88270 + (uint)local_6 * 2 + 0x78)) {
        return local_6;
      }
    }
  }
  else if (uVar1 < 2) {
    for (local_6 = 0; local_6 < 0x17; local_6 = local_6 + 1) {
      if (param_2 == *(short *)(BYTE_ARRAY_fff88270 + (uint)local_6 * 2 + 0x4a)) {
        return local_6;
      }
    }
  }
  return 0xff;
}


// ===== width_hz_of_index @ fffb3775 (88 bytes)

/* (mode, index): filter width in Hz from the same tables at 0xFFF88270, 0xFFFF if out of range
   [fact: fffb3775]; callers cat_SH, vfo_filter_width_hz, dsp_knob_width_step */

undefined2 width_hz_of_index(byte param_1,byte param_2)

{
  uint uVar1;
  undefined2 local_6;
  
  local_6 = 0xffff;
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    if (param_2 < 0x15) {
      local_6 = *(undefined2 *)(BYTE_ARRAY_fff88270 + (uint)param_2 * 2 + 0x78);
    }
  }
  else if ((uVar1 < 2) && (param_2 < 0x17)) {
    local_6 = *(undefined2 *)(BYTE_ARRAY_fff88270 + (uint)param_2 * 2 + 0x4a);
  }
  return local_6;
}


// ===== FUN_fffb37cd @ fffb37cd (49 bytes)

undefined1 FUN_fffb37cd(byte param_1)

{
  uint uVar1;
  undefined1 local_3;
  
  local_3 = 0xff;
  uVar1 = (uint)param_1;
  if (((uVar1 - 0xc < 3) || (uVar1 - 2 < 2)) || (uVar1 - 8 < 2)) {
    local_3 = 0x15;
  }
  else if (uVar1 < 2) {
    local_3 = 0x17;
  }
  return local_3;
}


// ===== tx_freq_allowed @ fffb37fe (675 bytes)

/* (freq): destination-code band table 0xFFF8884C.., inhibit flags */

bool tx_freq_allowed(uint freq)

{
  undefined *puVar1;
  bool bVar2;
  ushort uVar3;
  undefined **ppuVar4;
  int iVar5;
  byte bStack_1c;
  vfo_state vStack_1b;
  bool bStack_1a;
  byte bStack_19;
  byte bStack_18;
  byte bStack_17;
  undefined **ppuStack_14;
  
  uVar3 = dest_code_get();
  bStack_18 = 0;
  bStack_1a = false;
  bStack_19 = 0xff;
  if (g_ui.zz_align_mode != 0) {
    return true;
  }
  if ((g_cfg105.a004_gn_tx_inh == 0) && (g_opstate.ex030407_tx_inhitbit == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (g_ui.cat_disabled == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (g_ui.tot_tripped == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return false;
  }
  if (uVar3 == 0xd950) {
    bStack_18 = 0xc;
    ppuStack_14 = (undefined **)&DAT_fff88a0c;
    goto LAB_fffb3933;
  }
  if (uVar3 == 0x1cb9) {
    bStack_18 = 1;
    ppuStack_14 = &PTR_memch_56__blk_3__shift_be_0__fff88a6c;
    goto LAB_fffb3933;
  }
  if (uVar3 == 0x306f) goto LAB_fffb38f4;
  if (uVar3 == 0x315b) {
    bStack_18 = 0x15;
    ppuStack_14 = (undefined **)(BYTE_ARRAY_fff887dc + 200);
    goto LAB_fffb3933;
  }
  if (uVar3 == 0x4380) {
LAB_fffb38da:
    bStack_18 = 0xb;
    ppuStack_14 = (undefined **)(BYTE_ARRAY_fff887dc + 0x70);
  }
  else {
    if (uVar3 != 0x50e2) {
      if (uVar3 == 0x60e6) goto LAB_fffb38da;
      if (uVar3 == 0x7753) {
LAB_fffb3901:
        bStack_18 = 10;
        ppuStack_14 = (undefined **)(BYTE_ARRAY_fff8894c + 0x18);
        goto LAB_fffb3933;
      }
      if ((uVar3 != 0x9cf7) && (uVar3 != 0xa4c5)) {
        if (uVar3 == 0xa983) {
          bStack_18 = 0xb;
          ppuStack_14 = (undefined **)(BYTE_ARRAY_fff8894c + 0x68);
          goto LAB_fffb3933;
        }
        if (uVar3 != 0xb5a7) {
          if (uVar3 != 0xd32d) {
            if (uVar3 != 0x20b) goto LAB_fffb3933;
            goto LAB_fffb38da;
          }
          goto LAB_fffb3901;
        }
      }
    }
LAB_fffb38f4:
    bStack_18 = 3;
    ppuStack_14 = (undefined **)BYTE_ARRAY_fff8894c;
  }
LAB_fffb3933:
  bStack_17 = 0;
  do {
    if (bStack_18 <= bStack_17) {
LAB_fffb397e:
      if (bStack_19 != 0xff) {
        if ((uVar3 == 0x315b) && (9 < bStack_19)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          iVar5 = FUN_fffb32aa(1);
          if (iVar5 == 0) {
            vStack_1b = g_opstate.vfo_state_a;
            bStack_1c = g_mem_hdr.chan_a;
          }
          else {
            vStack_1b = g_opstate.vfo_state_b;
            bStack_1c = g_mem_hdr.chan_b;
          }
          if ((vStack_1b == VFO_STATE_MEMORY) && (0x74 < bStack_1c)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if ((bVar2) && (bStack_1c < 0x85)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (!bVar2) {
            bStack_1a = false;
          }
        }
        if ((g_ui.dl_req_50 == 1) || (g_ui.dl_block_34 == 1)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          bStack_1a = false;
          g_ui.ptt_data = 0;
          g_ui.ptt_extpa = 0;
          g_ui.ptt_usb_rts = 0;
          g_ui.ptt_usb_dtr = 0;
          g_ui.cat_tx_req = 0;
          g_ui.ptt_vox = 0;
          g_ui.ptt_mic = 0;
          g_ui.ptt_mox = 0;
          g_ui.ptt_atu_tune = 0;
          g_ui.ptt_msg_play = 0;
        }
      }
      return bStack_1a;
    }
    puVar1 = *ppuStack_14;
    ppuVar4 = ppuStack_14 + 1;
    ppuStack_14 = ppuStack_14 + 2;
    if ((freq < puVar1) || (*ppuVar4 <= freq)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      bStack_19 = bStack_17;
      bStack_1a = true;
      goto LAB_fffb397e;
    }
    bStack_17 = bStack_17 + 1;
  } while( true );
}


// ===== freq_in_range @ fffb3aa1 (77 bytes)

/* 29999 < f < 75000001 */

byte freq_in_range(void *param_1)

{
  byte bVar1;
  
  if ((memch[0x38].blk[3].width_be + 1 < param_1) && (param_1 < (void *)0x47868c1)) {
    bVar1 = 1;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}


// ===== FUN_fffb3aee @ fffb3aee (69 bytes)

void FUN_fffb3aee(void)

{
  return;
}


// ===== dest_code_get @ fffb3b33 (42 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb3b43) */
/* Returns destination code 0x475E:0x475F */

ushort dest_code_get(void)

{
  return CONCAT11(dest_code[0],dest_code[1]);
}


// ===== dest_code_set @ fffb3b5d (73 bytes)

/* Sets destination code, writes EEPROM, settings_defaults(0), requests restart (0x20F4B=1,
   0x20B39=0x11) */

void dest_code_set(ushort param_1)

{
  undefined1 local_2;
  
  g_opstate.auto_power_on = 1;
  dest_code[0] = (byte)(param_1 >> 8);
  local_2 = (byte)param_1;
  dest_code[1] = local_2;
  eeprom_save_dest();
  settings_defaults(0);
  g_ui.restart_req = 1;
  g_ui.power_cmd = 0x11;
  return;
}


// ===== dest_jumper_apply @ fffb3ba6 (363 bytes)

/* JP_P51 strap: switch destination code between restricted/wide pairs */

void dest_jumper_apply(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  
  uVar3 = dest_code_get();
  bVar2 = jp_p51_get();
  if ((uVar3 == 0x315b) && (bVar2 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0x50e2);
    return;
  }
  if ((uVar3 == 0x50e2) && (bVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0x315b);
    return;
  }
  if ((uVar3 == 0xa983) && (bVar2 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xb5a7);
    return;
  }
  if ((uVar3 == 0xb5a7) && (bVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xa983);
    return;
  }
  if ((uVar3 == 0xd950) && (bVar2 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xa4c5);
    return;
  }
  if ((uVar3 == 0xa4c5) && (bVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xd950);
    return;
  }
  if ((uVar3 == 0xd32d) && (bVar2 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0x306f);
    return;
  }
  if ((uVar3 == 0x306f) && (bVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((uVar3 == 0x7753) && (bVar2 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      dest_code_set(0x9cf7);
      return;
    }
    if ((uVar3 == 0x9cf7) && (bVar2 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      dest_code_set(0x7753);
      return;
    }
    return;
  }
  dest_code_set(0xd32d);
  return;
}


// ===== tx_mod_source @ fffb3d11 (324 bytes)

/* (mode): MOD SOURCE for the mode (EX010114 / 010214 / 010313 / 010414 or the active PRESET); while
   DVS records 0; with PTT source 0/6 and VOX on the VOX SELECT source; AUTO (3) resolves by the PTT
   source to 2 (rear), 1 (USB) or 0 (MIC) [fact: fffb3d11]; callers tx_mod_gain, audio_level_update,
   tx_audio_select */

char tx_mod_source(byte param_1)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  byte local_3;
  
  local_3 = 0xff;
  bVar3 = ptt_source_get();
  uVar1 = (uint)param_1;
  if (uVar1 == 0xe) {
LAB_fffb3dc1:
    if (g_opstate.preset_on == 0) {
      local_3 = g_opstate.ex010414_mod_source;
    }
    else {
      local_3 = g_ui.preset_active.mod_source;
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (g_opstate.preset_on == 0) {
        local_3 = g_opstate.ex010214_mod_source;
      }
      else {
        local_3 = g_ui.preset_active.mod_source;
      }
      goto LAB_fffb3de6;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffb3dc1;
      if (1 < uVar1 - 10) {
        if (uVar1 < 2) {
          if (g_opstate.preset_on == 0) {
            local_3 = g_opstate.ex010114_mod_source;
          }
          else {
            local_3 = g_ui.preset_active.mod_source;
          }
        }
        goto LAB_fffb3de6;
      }
    }
    if (g_opstate.preset_on == 0) {
      local_3 = g_opstate.ex010313_mod_source;
    }
    else {
      local_3 = g_ui.preset_active.mod_source;
    }
  }
LAB_fffb3de6:
  if (local_3 != 0xff) {
    if (g_ui.dvs_state == 2) {
      local_3 = 0;
    }
    else {
      if ((bVar3 == 0) || (bVar3 == 6)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        if (g_opstate.vox_on != 0) {
          local_3 = g_opstate.ex030405_vox_select;
        }
      }
      else if (local_3 == 3) {
        if (bVar3 == 1) {
          local_3 = 2;
        }
        else if (bVar3 - 3 < 3) {
          local_3 = 1;
        }
        else {
          local_3 = 0;
        }
      }
    }
  }
  return local_3;
}


// ===== sw_reset @ fffb3e55 (21 bytes)

/* PRCR=0xA502, SWRR 0x800C2=0xA501: software reset (end of power-off) [inference] */

void sw_reset(void)

{
  SYSTEM_PRCR = 0xa502;
  SYSTEM_SWRR = 0xa501;
  return;
}


// ===== wdt_kick @ fffb3e6a (5 bytes)

/* main_loop task 1 / power-off loop: R_IWDT_Restart */

void wdt_kick(void)

{
  iwdt_refresh();
  return;
}


// ===== max_power_limit @ fffb3e6f (156 bytes)

/* (0..4): destination-dependent upper limit for HF / 50M / 70M / AM MAX POWER (menu.md) [fact] */

undefined1 max_power_limit(byte param_1)

{
  ushort uVar1;
  byte bStack_5;
  
  uVar1 = dest_code_get();
  if (uVar1 == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3ef4;
  }
  if (uVar1 == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3ef4;
  }
  if (uVar1 == 0x306f) {
LAB_fffb3edf:
    bStack_5 = 5;
  }
  else {
    if (uVar1 == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3ef4;
    }
    if (uVar1 != 0xd950) {
      if (uVar1 == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3ef4;
      }
      if (uVar1 == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3ef4;
      }
      if ((uVar1 == 0x7753) || (uVar1 == 0x9cf7)) {
        bStack_5 = 9;
        goto LAB_fffb3ef4;
      }
      if (uVar1 != 0xa4c5) {
        if (uVar1 != 0xd32d) {
          if (uVar1 == 0x4380) {
            bStack_5 = 0;
          }
          else {
            bStack_5 = 6;
          }
          goto LAB_fffb3ef4;
        }
        goto LAB_fffb3edf;
      }
    }
    bStack_5 = 7;
  }
LAB_fffb3ef4:
  return *(undefined1 *)((uint)param_1 + (uint)bStack_5 * 5 + -0x7eab9);
}


// ===== FUN_fffb3f0b @ fffb3f0b (156 bytes)

undefined1 FUN_fffb3f0b(byte param_1)

{
  ushort uVar1;
  byte bStack_5;
  
  uVar1 = dest_code_get();
  if (uVar1 == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3f90;
  }
  if (uVar1 == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3f90;
  }
  if (uVar1 == 0x306f) {
LAB_fffb3f7b:
    bStack_5 = 5;
  }
  else {
    if (uVar1 == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3f90;
    }
    if (uVar1 != 0xd950) {
      if (uVar1 == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3f90;
      }
      if (uVar1 == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3f90;
      }
      if ((uVar1 == 0x7753) || (uVar1 == 0x9cf7)) {
        bStack_5 = 9;
        goto LAB_fffb3f90;
      }
      if (uVar1 != 0xa4c5) {
        if (uVar1 != 0xd32d) {
          if (uVar1 == 0x4380) {
            bStack_5 = 0;
          }
          else {
            bStack_5 = 6;
          }
          goto LAB_fffb3f90;
        }
        goto LAB_fffb3f7b;
      }
    }
    bStack_5 = 7;
  }
LAB_fffb3f90:
  return *(undefined1 *)((uint)param_1 + (uint)bStack_5 * 5 + -0x7ea87);
}


// ===== FUN_fffb3fa7 @ fffb3fa7 (187 bytes)

uint FUN_fffb3fa7(void)

{
  ushort uVar1;
  byte bStack_7;
  
  uVar1 = dest_code_get();
  if (uVar1 == 0x20b) {
    bStack_7 = 1;
  }
  else if (uVar1 == 0x1cb9) {
    bStack_7 = 8;
  }
  else if (uVar1 == 0x306f) {
    bStack_7 = 0xd;
  }
  else if (uVar1 == 0x315b) {
    bStack_7 = 3;
  }
  else if (uVar1 == 0xd950) {
    bStack_7 = 7;
  }
  else if (uVar1 == 0x50e2) {
    bStack_7 = 4;
  }
  else if (uVar1 == 0x60e6) {
    bStack_7 = 2;
  }
  else if (uVar1 == 0x7753) {
    bStack_7 = 9;
  }
  else if (uVar1 == 0x9cf7) {
    bStack_7 = 0xe;
  }
  else if (uVar1 == 0xa4c5) {
    bStack_7 = 0xc;
  }
  else if (uVar1 == 0xa983) {
    bStack_7 = 6;
  }
  else if (uVar1 == 0xb5a7) {
    bStack_7 = 0xb;
  }
  else if (uVar1 == 0xd32d) {
    bStack_7 = 5;
  }
  else if (uVar1 == 0x4380) {
    bStack_7 = 0;
  }
  else {
    bStack_7 = 10;
  }
  return (uint)(s_Japan_0001b3e4 + (uint)bStack_7 * 0xf);
}


// ===== FUN_fffb4062 @ fffb4062 (211 bytes)

byte FUN_fffb4062(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  uint uVar6;
  byte bStack_f;
  
  uVar6 = vfo_freq(1,2);
  bVar3 = vfo_mode(1);
  cVar4 = tx_band_of_freq(uVar6);
  bVar2 = g_opstate.rf_power[3];
  if ((bVar3 == 4) || (bVar3 == 5)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_f = g_opstate.rf_power[3];
    uVar5 = dest_code_get();
    if (uVar5 == 0x60e6) {
      if ((cVar4 == '\t') || (bVar2 < 0xb)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        bStack_f = 10;
      }
    }
  }
  else if (cVar4 == '\t') {
    bStack_f = g_opstate.rf_power[1];
  }
  else if (cVar4 == '\n') {
    bStack_f = g_opstate.rf_power[2];
  }
  else {
    bStack_f = g_opstate.rf_power[0];
  }
  if (g_ui.tune_cycle == 1) {
    bStack_f = 10;
  }
  else if (g_ui.tune_cycle == 2) {
    bStack_f = 5;
  }
  else if (g_ui.tune_cycle_3c == 2) {
    bStack_f = 5;
  }
  else if (g_ui.tune_cycle_3d == 2) {
    bStack_f = 5;
  }
  return bStack_f;
}


// ===== FUN_fffb4135 @ fffb4135 (85 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4172) */

uint FUN_fffb4135(uint param_1)

{
  uint uVar1;
  byte local_15;
  uint local_14;
  uint local_c;
  uint local_4;
  
  local_c = 0;
  local_14 = 10000000;
  local_4 = param_1;
  for (local_15 = 0; local_15 < 8; local_15 = local_15 + 1) {
    uVar1 = local_4;
    if (local_14 != 0) {
      uVar1 = local_4 / local_14;
    }
    local_c = uVar1 << (7 - local_15 & 7) * 4 | local_c;
    local_4 = local_4 - uVar1 * local_14;
    local_14 = local_14 / 10;
  }
  return local_c;
}


// ===== FUN_fffb418a @ fffb418a (143 bytes)

byte FUN_fffb418a(byte param_1)

{
  byte bVar1;
  byte local_9;
  byte local_1;
  uint uVar2;
  
  local_1 = param_1;
  if (g_opstate.split_on != 0) {
    local_1 = 1;
  }
  bVar1 = vfo_mode(local_1);
  uVar2 = (uint)bVar1;
  if (uVar2 == 0xe) {
LAB_fffb41fc:
    local_9 = g_opstate.monitor[3];
  }
  else {
    if (uVar2 - 2 < 2) {
      return g_opstate.monitor[1];
    }
    if (uVar2 - 4 < 2) {
      return g_opstate.monitor[4];
    }
    if (1 < uVar2 - 6) {
      if (uVar2 - 8 < 2) goto LAB_fffb41fc;
      if (1 < uVar2 - 10) {
        if (uVar2 - 0xc < 2) {
          return g_opstate.monitor[2];
        }
        if (1 < uVar2) {
          return 0;
        }
        return g_opstate.monitor[0];
      }
    }
    local_9 = g_opstate.monitor_fm;
  }
  return local_9;
}


// ===== audio_route_state @ fffb4219 (734 bytes)

/* Returns 0..14: CW/RTTY RX 0, record 1/3, spot 2, playback 4/5, CW/RTTY TX 6/7, voice RX 8 (9-12
   variants), voice TX 13, playback TX 14 */

uint audio_route_state(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bStack_b;
  uint uStack_8;
  
  bVar2 = g_ui.tx_lamp;
  bStack_b = vfo_mode(g_ui.transmitting);
  bVar9 = FUN_fffb2dfe();
  bVar8 = g_ui.ky_send_1;
  bVar7 = g_ui.ky_send_0;
  bVar6 = g_ui.msg_rec_active;
  bVar5 = g_ui.audio_playing;
  bVar4 = g_ui.dvs_lm1_flag;
  bVar3 = g_ui.dvs_state;
  bVar10 = tx_cw_keying_class();
  if ((g_ui.dvs_lm1_flag == 1) || (g_ui.playlist_open == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_b = vfo_mode(0);
  }
  else {
    if ((bVar3 == 0) && (bVar7 != 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (bVar8 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (bVar6 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui.dvs_busy == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bStack_b = vfo_mode(1);
    }
  }
  if ((bStack_b == 3) || (bStack_b == 2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bStack_b == 0xd)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bStack_b == 0xc)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (bVar2 != 1) {
      if ((g_ui.cw_spot_on == 1) || (bVar9 == 4)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 2;
      }
      else if (bVar4 == 1) {
        uStack_8 = 1;
      }
      else if (bVar6 == 1) {
        uStack_8 = 3;
      }
      else {
        if ((bVar5 == 1) && (g_ui.playlist_open == 1)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_8 = 5;
        }
        else {
          if ((bVar5 == 1) || (bVar7 == 1)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if ((bVar1) || (bVar8 == 1)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            uStack_8 = 4;
          }
          else {
            uStack_8 = 0;
          }
        }
      }
    }
    else {
      if ((bVar5 == 1) || (bVar7 == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (bVar8 == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 7;
      }
      else {
        uStack_8 = 6;
      }
    }
  }
  else if (bVar2 != 1) {
    if ((bVar10 == 0) || (bVar9 != 4)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uStack_8 = 2;
    }
    else if (bVar4 == 1) {
      uStack_8 = 9;
    }
    else {
      if ((bVar3 == 2) || (g_ui.dvs_busy == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 10;
      }
      else {
        if ((bVar3 == 1) && (g_ui.playlist_open == 0)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_8 = 0xb;
        }
        else {
          if ((bVar5 == 1) && (g_ui.playlist_open == 1)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            uStack_8 = 0xc;
          }
          else {
            uStack_8 = 8;
          }
        }
      }
    }
  }
  else {
    if ((bVar10 == 3) && (bVar9 == 4)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uStack_8 = 6;
    }
    else {
      if ((bVar5 == 1) || (bVar3 == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 0xe;
      }
      else {
        uStack_8 = 0xd;
      }
    }
  }
  return uStack_8;
}


// ===== key_event_filter @ fffb44f7 (1585 bytes)

/* Front-panel key event gate (key code, action): returns 1 if the key may run now; used by many CAT
   handlers */

byte key_event_filter(ushort param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  byte local_7;
  byte bStack_6;
  ushort local_2;
  
  bVar2 = param_2 >> 4;
  local_7 = 1;
  iVar6 = FUN_fffc4cc5(param_1,param_2);
  if ((iVar6 == 1) && (2 < param_1 - 0xff0)) {
    local_7 = 0;
  }
  bVar4 = param_2 & 0xf;
  bStack_6 = 0xff;
  if (param_1 == 0x348) {
    bStack_6 = g_opstate.ex030124_mic_up;
  }
  else if (param_1 == 0x34e) {
    bStack_6 = g_opstate.ex030125_mic_down;
  }
  else if (param_1 == 0x35e) {
    bStack_6 = g_opstate.ex030123_mic_p4;
  }
  else if (param_1 == 0x35c) {
    bStack_6 = g_opstate.ex030121_mic_p2;
  }
  else if (param_1 == 0x35d) {
    bStack_6 = g_opstate.ex030122_mic_p3;
  }
  else if (param_1 == 0x35b) {
    bStack_6 = g_opstate.ex030120_mic_p1;
  }
  local_2 = param_1;
  if (bStack_6 != 0xff) {
    if ((*(short *)(BYTE_ARRAY_fff88270 + (uint)bStack_6 * 2 + 0xa2) == 0x300) && (bVar4 == 2)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (!bVar3) {
      local_2 = *(ushort *)(BYTE_ARRAY_fff88270 + (uint)bStack_6 * 2 + 0xa2);
    }
  }
  if ((local_2 == 0x300) && (bVar4 == 2)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar3) {
    g_ui.power_key_req = 2;
    local_7 = 0;
  }
  if (g_ui.zz_align_mode == 1) {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if ((local_2 < 8) || (local_2 - 0x16 < 4)) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
  }
  if (g_ui.dialog_shown == 1) {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((((1 < uVar1 - 0xfe) && (uVar1 != 0xff1)) && (uVar1 != 0x302)) &&
         ((uVar1 != 0x30f && (uVar1 != 0x340)))) {
        if (uVar1 == 0x300) {
          local_7 = 0;
        }
        else {
          if (bVar4 == 1) {
            beep_request(3);
          }
          local_7 = 0;
        }
      }
    }
    return local_7;
  }
  if (g_ui.msgmem_open != 0) {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      if ((local_2 < 0x200) || (0x288 < local_2)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if ((((!bVar3) && (uVar1 = (uint)local_2, 9 < uVar1 - 0x87)) && (uVar1 != 0xe6)) &&
         (((0xe < uVar1 - 0x300 && (1 < uVar1 - 0x310)) && ((uVar1 != 0x340 && (1 < uVar1 - 0xff0)))
          ))) {
        if (bVar4 == 1) {
          beep_request(3);
        }
        local_7 = 0;
      }
    }
  }
  if ((g_ui.dvs_state == 2) && ((local_2 - 0x87 < 5 || (local_2 - 0x8d < 4)))) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((((g_ui.playlist_open != 0) && (uVar1 = (uint)local_2, uVar1 != 0xe8)) && (1 < uVar1 - 0xfe))
     && (((0xb < uVar1 - 0x110 && (uVar1 != 0xff1)) && ((uVar1 != 0x30c && (uVar1 != 0x30f)))))) {
    if (uVar1 == 0x300) {
      local_7 = 0;
    }
    else {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
  }
  if (((g_ui.audio_playing == 1) && (uVar1 = (uint)local_2, 9 < uVar1 - 0x87)) &&
     ((4 < uVar1 - 0x110 &&
      ((((uVar1 != 0x119 && (uVar1 != 0x302)) && (uVar1 != 0x340)) && (uVar1 != 0xff1)))))) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if (g_ui.tx_lamp != 0) {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if (((uVar1 != 0x10) && (5 < uVar1 - 0x30)) &&
         (((((9 < uVar1 - 0x87 && ((5 < uVar1 - 0xd0 && (0xd < uVar1 - 0xd7)))) &&
            (1 < uVar1 - 0xe6)) &&
           (((((uVar1 != 0xe9 && (6 < uVar1 - 0xec)) && (uVar1 != 0x12d)) &&
             (((2 < uVar1 - 0x300 && (uVar1 != 0x306)) &&
              ((uVar1 != 0x30f && ((uVar1 != 0x311 && (2 < uVar1 - 0xff0)))))))) && (uVar1 != 0x340)
            ))) && (((uVar1 != 0x348 && (uVar1 != 0x34e)) &&
                    ((uVar1 != 0x312 || (g_ui.zz_align_mode == 0)))))))) {
        if (bVar4 == 1) {
          beep_request(3);
        }
        local_7 = 0;
      }
    }
  }
  if (g_ui.keypad_open != 0) {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((uVar1 != 0x14) && (0xe < uVar1 - 0xb0)) {
        if (uVar1 == 0x300) {
          local_7 = 0;
        }
        else {
          if (uVar1 != 0x302) {
            if (uVar1 == 0x30c) goto LAB_fffb48f7;
            if (uVar1 != 0x340) {
              if (bVar4 == 1) {
                beep_request(3);
              }
              local_7 = 0;
              goto LAB_fffb48f7;
            }
          }
          popup8_close();
        }
      }
    }
  }
LAB_fffb48f7:
  if (g_ui.tune_cycle != 0) {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else {
      uVar1 = (uint)local_2;
      if ((((2 < uVar1 - 0x300) && (uVar1 != 0x340)) && (uVar1 != 0x348)) &&
         ((uVar1 != 0x34e && (uVar1 != 0xff0)))) {
        if (bVar4 == 1) {
          beep_request(3);
        }
        local_7 = 0;
      }
    }
  }
  if (g_ui.func_panel_open != 0) {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if (local_2 == 0x14) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if ((local_2 == 0x302) || (local_2 == 0x340)) {
      g_ui.func_panel_open = 0;
    }
  }
  bVar5 = vfo_tune_locked('\x02');
  if (bVar5 == 1) {
    if (bVar2 == 4) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
    else if (local_2 - 0x12 < 3) {
      if (bVar4 == 1) {
        beep_request(3);
      }
      local_7 = 0;
    }
  }
  if ((g_ui.memlist_open == 1) && (local_2 == 0xff1)) {
    local_7 = 0;
  }
  if ((g_ui.dvs_busy == 1) && (local_2 == 0x30e)) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((g_ui.msg_rec_active == 1) && (local_2 == 0x30e)) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((g_opstate.split_on != 0) && (local_2 == 0x306)) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  if ((g_opstate.lock_on == 0) || (g_ui.playlist_open != 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if ((bVar3) && (local_2 == 0xff0)) {
    popup_duration_get(0x47);
    popup_open_timed();
    g_ui.popup_code = 0x47;
    local_7 = 0;
  }
  if (((g_ui.cw_spot_on != 0) && (local_2 != 0x340)) && (2 < local_2 - 0xff0)) {
    g_ui.cw_spot_on = 0;
    beep_stop();
  }
  if ((bVar4 == 0) && (2 < local_2 - 0xff0)) {
    local_7 = 1;
  }
  if ((g_ui.dl_req_50 == 1) || (g_ui.dl_block_34 == 1)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((bVar3) && ((local_2 == 0x302 || (local_2 == 0x340)))) {
    if (bVar4 == 1) {
      beep_request(3);
    }
    local_7 = 0;
  }
  return local_7;
}


// ===== supply_undervolt_check @ fffb4b28 (146 bytes)

/* AN003 < 0x7DD -> power_off_io, save, shutdown request 0x20B39=0x90 */

char supply_undervolt_check(void)

{
  byte bVar1;
  
  if ((g_ui.power_fail_latch != 1) && (g_ui.adc_pa_vdd < 0x7dd)) {
    bVar1 = swtimer_expired(0x13);
    g_ui.power_fail_latch = 1;
    if (bVar1 == 1) {
      power_off_io();
      g_opstate.auto_power_on = 1;
      menu_cursors_save();
      eeprom_save_opstate();
      g_ui.restart_req = 1;
      g_ui.power_cmd = 0x90;
    }
    else {
      power_off_io();
      g_opstate.auto_power_on = 1;
      g_ui.restart_req = 1;
      g_ui.power_cmd = 0x90;
    }
  }
  return g_ui.power_fail_latch;
}


// ===== vfo_tune_locked @ fffb4bba (139 bytes)

/* 1 if side is in state 7/8 or on 5 MHz/EMG memory (ch 117..132) */

byte vfo_tune_locked(char param_1)

{
  bool bVar1;
  byte local_5;
  byte local_4;
  vfo_state local_3;
  char local_1;
  
  local_5 = 0;
  local_1 = param_1;
  if (param_1 == '\x02') {
    if (g_opstate.active_vfo == VFO_A) {
      local_1 = '\0';
    }
    else {
      local_1 = '\x01';
    }
  }
  if (local_1 == '\0') {
    local_3 = g_opstate.vfo_state_a;
    local_4 = g_mem_hdr.chan_a;
  }
  else {
    local_3 = g_opstate.vfo_state_b;
    local_4 = g_mem_hdr.chan_b;
  }
  if (local_3 == VFO_STATE_MEMORY) {
    if ((local_4 < 0x75) || (0x84 < local_4)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_5 = 1;
    }
  }
  else if (local_3 == VFO_STATE_LOCKED_7 || local_3 == VFO_STATE_LOCKED_8) {
    local_5 = 1;
  }
  return local_5;
}


// ===== vfo_display_offset @ fffb4c45 (467 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb4d66) */
/* WARNING: Removing unreachable block (ram,0xfffb4c6a) */
/* WARNING: Removing unreachable block (ram,0xfffb4dfd) */
/* WARNING: Removing unreachable block (ram,0xfffb4cbe) */
/* WARNING: Removing unreachable block (ram,0xfffb4d3b) */
/* WARNING: Removing unreachable block (ram,0xfffb4d06) */
/* Mode-dependent signed offset added to dial freq (0x20F5C); 0 if setting 0x9B15 != 0 */

ushort vfo_display_offset(void)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  byte *pbVar4;
  ushort uStack_e;
  ushort uStack_a;
  
  pbVar4 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  uStack_e = 0;
  if (g_opstate.ex040202_scope_ctr == 0) {
    uVar1 = (uint)bVar2;
    if (uVar1 == 0xe) {
      uStack_e = CONCAT11(pbVar4[0x30],pbVar4[0x31]);
    }
    else if (uVar1 - 2 < 2) {
      uStack_a = CONCAT11(pbVar4[0x1c],pbVar4[0x1d]);
      if (bVar2 == 2) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 8 < 2) {
      uStack_a = CONCAT11(g_opstate.ex010420_data_shift_ssb_be[0],
                          g_opstate.ex010420_data_shift_ssb_be[1]) * 10 +
                 CONCAT11(pbVar4[0x30],pbVar4[0x31]);
      if (bVar2 == 8) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 0xc < 2) {
      sVar3 = CONCAT11(pbVar4[0x26],pbVar4[0x27]);
      if (g_opstate.ex010516_shift_frequency == 1) {
        if (bVar2 == 0xc) {
          uStack_a = sVar3 + 0x69;
        }
        else {
          uStack_a = 0x69 - sVar3;
        }
      }
      else if (g_opstate.ex010516_shift_frequency == 2) {
        if (bVar2 == 0xc) {
          uStack_a = sVar3 + 0xd7;
        }
        else {
          uStack_a = 0xd7 - sVar3;
        }
      }
      else if (g_opstate.ex010516_shift_frequency == 3) {
        if (bVar2 == 0xc) {
          uStack_a = sVar3 + 0x1a9;
        }
        else {
          uStack_a = 0x1a9 - sVar3;
        }
      }
      else if (bVar2 == 0xc) {
        uStack_a = sVar3 + 0x55;
      }
      else {
        uStack_a = 0x55 - sVar3;
      }
      uStack_e = ~uStack_a + 1;
    }
    else if (uVar1 < 2) {
      uStack_a = CONCAT11(pbVar4[0x12],pbVar4[0x13]);
      if ((pbVar4[0x12] & 0x80) != 0) {
        uStack_a = -(~uStack_a + 1);
      }
      uStack_a = uStack_a + 0x5dc;
      if (bVar2 == 0) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
  }
  return uStack_e;
}

