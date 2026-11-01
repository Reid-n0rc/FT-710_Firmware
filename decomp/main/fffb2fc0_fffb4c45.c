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
  char hex2nib_ret;
  byte hex2nib_ret_2;
  byte local_6;
  
  local_6 = 0;
  if ((*param_1 < 0x30) || (0x39 < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
                    /* Accepts 0-9/A-F/a-f, else returns 0xFF [doc] */
    hex2nib_ret = hex2nib(*param_1);
    local_6 = hex2nib_ret << 4;
  }
  if ((*param_1 < 0x30) || (0x39 < *param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    hex2nib_ret_2 = hex2nib(param_1[1]);
    local_6 = hex2nib_ret_2 | local_6;
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
  vfo_rec *p_vfo_rec;
  
  local_11 = 0;
  if (which != 0) {
    local_11 = g_opstate.split_on;
  }
  if (g_opstate.active_vfo == VFO_A) {
    if (local_11 == 0) {
      p_vfo_rec = &g_opstate.vfo_a;
    }
    else {
      p_vfo_rec = &g_opstate.vfo_b;
    }
  }
  else if (local_11 == 0) {
    p_vfo_rec = &g_opstate.vfo_b;
  }
  else {
    p_vfo_rec = &g_opstate.vfo_a;
  }
  return &p_vfo_rec->mode;
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
  byte i;
  
  i = 0;
  while( true ) {
    if (0xd < i) {
      return 0xff;
    }
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886b8 + (uint)i * 4)) break;
    i = i + 1;
  }
  return i;
}


// ===== FUN_fffb3337 @ fffb3337 (58 bytes)

byte FUN_fffb3337(uint param_1)

{
  byte i;
  
  i = 0;
  while( true ) {
    if (6 < i) {
      return 0xff;
    }
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)i * 4 + 0x28)) break;
    i = i + 1;
  }
  return i;
}


// ===== tx_band_of_freq @ fffb3371 (58 bytes)

/* (f): index 0..10 of the first bound in ROM 0xFFF8870C (2.1 / 4.7 / 7.5 / 11.5 / 14.5 / 20.9 / 22
   / 25.5 / 41.5 / 60 / 75 MHz) above f, else 0xFF [fact] */

byte tx_band_of_freq(uint param_1)

{
  byte i;
  
  i = 0;
  while( true ) {
    if (10 < i) {
      return 0xff;
    }
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)i * 4 + 0x44)) break;
    i = i + 1;
  }
  return i;
}


// ===== FUN_fffb33ab @ fffb33ab (58 bytes)

byte FUN_fffb33ab(uint param_1)

{
  byte i;
  
  i = 0;
  while( true ) {
    if (0xc < i) {
      return 0xff;
    }
    if (param_1 < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)i * 4 + 0x70)) break;
    i = i + 1;
  }
  return i;
}


// ===== band_of_freq @ fffb33e5 (96 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb33f4) */
/* WARNING: Removing unreachable block (ram,0xfffb3403) */
/* Band index 0..11 of a frequency (ranges at 0xFFF8876C), 0xFF if none */

byte band_of_freq(uint freq)

{
  bool bVar1;
  byte i;
  
  i = 0;
  while( true ) {
    if (0xb < i) {
      return 0xff;
    }
    if ((freq < *(uint *)(BYTE_ARRAY_fff886c8 + (uint)i * 8 + 0xa4)) ||
       (*(uint *)(BYTE_ARRAY_fff886c8 + (uint)i * 8 + 0xa8) <= freq)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) break;
    i = i + 1;
  }
  return i;
}


// ===== gen_subband_of_freq @ fffb3445 (59 bytes)

/* GEN sub-slot 0..15 from boundaries at 0xFFF887CC */

byte gen_subband_of_freq(uint freq)

{
  byte i;
  
  i = 0;
  while( true ) {
    if (0x11 < i) {
      return 0xff;
    }
    if (freq < *(uint *)(BYTE_ARRAY_fff887c4 + (uint)i * 4 + 8)) break;
    i = i + 1;
  }
  return i;
}


// ===== freq_range_index @ fffb3480 (58 bytes)

/* Index of f in boundary table 0xFFF88814 */

byte freq_range_index(uint freq)

{
  byte i;
  
  i = 0;
  while( true ) {
    if (0xd < i) {
      return 0xff;
    }
    if (freq < *(uint *)(BYTE_ARRAY_fff887dc + (uint)i * 4 + 0x38)) break;
    i = i + 1;
  }
  return i;
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
  byte i;
  uint uStack_14;
  vfo_rec *p_vfo_rec;
  
  if (side == 0) {
    p_vfo_rec = &g_opstate.vfo_a;
  }
  else if (side == 1) {
    p_vfo_rec = &g_opstate.vfo_b;
  }
  else {
    p_vfo_rec = (vfo_rec *)vfo_rec_ptr(which);
  }
  for (i = 0; i < 4; i = i + 1) {
    uStack_14 = (uint)p_vfo_rec->freq_be[i] | uStack_14 << 8;
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
  vfo_rec *p_vfo_rec;
  
  uStack_14 = vfo_freq(which,side);
  bStack_18 = 0;
  bVar2 = false;
  if (side == 0) {
    bStack_17 = g_ui.clar_flags_a;
    p_vfo_rec = &g_opstate.vfo_a;
  }
  else if (side == 1) {
    bStack_17 = g_ui.clar_flags_b;
    p_vfo_rec = &g_opstate.vfo_b;
  }
  else {
    p_vfo_rec = (vfo_rec *)vfo_rec_ptr(which);
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
    uVar3 = CONCAT11(p_vfo_rec->clar_offset_be[0],p_vfo_rec->clar_offset_be[1]);
    if ((p_vfo_rec->clar_offset_be[0] & 0x80) == 0) {
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
  ushort dest_code_get_ret;
  undefined **ppuVar3;
  int iVar4;
  byte bStack_1c;
  vfo_state vStack_1b;
  bool bStack_1a;
  byte bStack_19;
  byte bStack_18;
  byte i;
  undefined **ppuStack_14;
  
  dest_code_get_ret = dest_code_get();
  bStack_18 = 0;
  bStack_1a = false;
  bStack_19 = 0xff;
  if (g_ui.zz_align_mode != 0) {
    return true;
  }
                    /* TX inhibit: cfg105[3] or TX INHIBIT (EX030407) [fact: tx-protection.md] */
  if ((g_cfg105.a004_gn_tx_inh == 0) && (g_opstate.ex030407_tx_inhitbit == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
                    /* CAT disabled from the DISPLAY link: no TX [fact: tx-protection.md] */
  if ((bVar2) && (g_ui.cat_disabled == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
                    /* TX time-out tripped: no TX [fact: tx-protection.md] */
  if ((bVar2) && (g_ui.tot_tripped == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return false;
  }
  if (dest_code_get_ret == 0xd950) {
    bStack_18 = 0xc;
    ppuStack_14 = (undefined **)&DAT_fff88a0c;
    goto LAB_fffb3933;
  }
  if (dest_code_get_ret == 0x1cb9) {
    bStack_18 = 1;
    ppuStack_14 = &PTR_memch_56__blk_3__shift_be_0__fff88a6c;
    goto LAB_fffb3933;
  }
  if (dest_code_get_ret == 0x306f) goto LAB_fffb38f4;
  if (dest_code_get_ret == 0x315b) {
    bStack_18 = 0x15;
    ppuStack_14 = (undefined **)(BYTE_ARRAY_fff887dc + 200);
    goto LAB_fffb3933;
  }
  if (dest_code_get_ret == 0x4380) {
LAB_fffb38da:
    bStack_18 = 0xb;
    ppuStack_14 = (undefined **)(BYTE_ARRAY_fff887dc + 0x70);
  }
  else {
    if (dest_code_get_ret != 0x50e2) {
      if (dest_code_get_ret == 0x60e6) goto LAB_fffb38da;
      if (dest_code_get_ret == 0x7753) {
LAB_fffb3901:
        bStack_18 = 10;
        ppuStack_14 = (undefined **)(BYTE_ARRAY_fff8894c + 0x18);
        goto LAB_fffb3933;
      }
      if ((dest_code_get_ret != 0x9cf7) && (dest_code_get_ret != 0xa4c5)) {
        if (dest_code_get_ret == 0xa983) {
          bStack_18 = 0xb;
          ppuStack_14 = (undefined **)(BYTE_ARRAY_fff8894c + 0x68);
          goto LAB_fffb3933;
        }
        if (dest_code_get_ret != 0xb5a7) {
          if (dest_code_get_ret != 0xd32d) {
            if (dest_code_get_ret != 0x20b) goto LAB_fffb3933;
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
  i = 0;
  do {
    if (bStack_18 <= i) {
LAB_fffb397e:
      if (bStack_19 != 0xff) {
        if ((dest_code_get_ret == 0x315b) && (9 < bStack_19)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          iVar4 = FUN_fffb32aa(1);
          if (iVar4 == 0) {
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
                    /* Tuning or 0x20B9E: clear every PTT request [fact: tx-protection.md] */
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
                    /* Walk the destination's {lo, hi} TX ranges [fact: tx-protection.md] */
    puVar1 = *ppuStack_14;
    ppuVar3 = ppuStack_14 + 1;
    ppuStack_14 = ppuStack_14 + 2;
    if ((freq < puVar1) || (*ppuVar3 <= freq)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      bStack_19 = i;
      bStack_1a = true;
      goto LAB_fffb397e;
    }
    i = i + 1;
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
  byte jp_p51_get_ret;
  ushort dest_code_get_ret;
  
  dest_code_get_ret = dest_code_get();
  jp_p51_get_ret = jp_p51_get();
  if ((dest_code_get_ret == 0x315b) && (jp_p51_get_ret == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0x50e2);
    return;
  }
  if ((dest_code_get_ret == 0x50e2) && (jp_p51_get_ret != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0x315b);
    return;
  }
  if ((dest_code_get_ret == 0xa983) && (jp_p51_get_ret == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xb5a7);
    return;
  }
  if ((dest_code_get_ret == 0xb5a7) && (jp_p51_get_ret != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xa983);
    return;
  }
  if ((dest_code_get_ret == 0xd950) && (jp_p51_get_ret == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xa4c5);
    return;
  }
  if ((dest_code_get_ret == 0xa4c5) && (jp_p51_get_ret != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0xd950);
    return;
  }
  if ((dest_code_get_ret == 0xd32d) && (jp_p51_get_ret == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    dest_code_set(0x306f);
    return;
  }
  if ((dest_code_get_ret == 0x306f) && (jp_p51_get_ret != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((dest_code_get_ret == 0x7753) && (jp_p51_get_ret == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      dest_code_set(0x9cf7);
      return;
    }
    if ((dest_code_get_ret == 0x9cf7) && (jp_p51_get_ret != 0)) {
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
  byte ptt_source_get_ret;
  byte local_3;
  
  local_3 = 0xff;
  ptt_source_get_ret = ptt_source_get();
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
      if ((ptt_source_get_ret == 0) || (ptt_source_get_ret == 6)) {
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
        if (ptt_source_get_ret == 1) {
          local_3 = 2;
        }
        else if (ptt_source_get_ret - 3 < 3) {
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
                    /* Protect [sfr] */
  SYSTEM_PRCR = 0xa502;
                    /* Software Reset [sfr] */
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
  ushort dest_code_get_ret;
  byte bStack_5;
  
  dest_code_get_ret = dest_code_get();
  if (dest_code_get_ret == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3ef4;
  }
  if (dest_code_get_ret == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3ef4;
  }
  if (dest_code_get_ret == 0x306f) {
LAB_fffb3edf:
    bStack_5 = 5;
  }
  else {
    if (dest_code_get_ret == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3ef4;
    }
    if (dest_code_get_ret != 0xd950) {
      if (dest_code_get_ret == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3ef4;
      }
      if (dest_code_get_ret == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3ef4;
      }
      if ((dest_code_get_ret == 0x7753) || (dest_code_get_ret == 0x9cf7)) {
        bStack_5 = 9;
        goto LAB_fffb3ef4;
      }
      if (dest_code_get_ret != 0xa4c5) {
        if (dest_code_get_ret != 0xd32d) {
          if (dest_code_get_ret == 0x4380) {
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
  ushort dest_code_get_ret;
  byte bStack_5;
  
  dest_code_get_ret = dest_code_get();
  if (dest_code_get_ret == 0x20b) {
    bStack_5 = 1;
    goto LAB_fffb3f90;
  }
  if (dest_code_get_ret == 0x1cb9) {
    bStack_5 = 8;
    goto LAB_fffb3f90;
  }
  if (dest_code_get_ret == 0x306f) {
LAB_fffb3f7b:
    bStack_5 = 5;
  }
  else {
    if (dest_code_get_ret == 0x315b) {
      bStack_5 = 3;
      goto LAB_fffb3f90;
    }
    if (dest_code_get_ret != 0xd950) {
      if (dest_code_get_ret == 0x50e2) {
        bStack_5 = 4;
        goto LAB_fffb3f90;
      }
      if (dest_code_get_ret == 0x60e6) {
        bStack_5 = 2;
        goto LAB_fffb3f90;
      }
      if ((dest_code_get_ret == 0x7753) || (dest_code_get_ret == 0x9cf7)) {
        bStack_5 = 9;
        goto LAB_fffb3f90;
      }
      if (dest_code_get_ret != 0xa4c5) {
        if (dest_code_get_ret != 0xd32d) {
          if (dest_code_get_ret == 0x4380) {
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
  ushort dest_code_get_ret;
  byte bStack_7;
  
  dest_code_get_ret = dest_code_get();
  if (dest_code_get_ret == 0x20b) {
    bStack_7 = 1;
  }
  else if (dest_code_get_ret == 0x1cb9) {
    bStack_7 = 8;
  }
  else if (dest_code_get_ret == 0x306f) {
    bStack_7 = 0xd;
  }
  else if (dest_code_get_ret == 0x315b) {
    bStack_7 = 3;
  }
  else if (dest_code_get_ret == 0xd950) {
    bStack_7 = 7;
  }
  else if (dest_code_get_ret == 0x50e2) {
    bStack_7 = 4;
  }
  else if (dest_code_get_ret == 0x60e6) {
    bStack_7 = 2;
  }
  else if (dest_code_get_ret == 0x7753) {
    bStack_7 = 9;
  }
  else if (dest_code_get_ret == 0x9cf7) {
    bStack_7 = 0xe;
  }
  else if (dest_code_get_ret == 0xa4c5) {
    bStack_7 = 0xc;
  }
  else if (dest_code_get_ret == 0xa983) {
    bStack_7 = 6;
  }
  else if (dest_code_get_ret == 0xb5a7) {
    bStack_7 = 0xb;
  }
  else if (dest_code_get_ret == 0xd32d) {
    bStack_7 = 5;
  }
  else if (dest_code_get_ret == 0x4380) {
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
  byte vfo_mode_ret;
  char cVar3;
  ushort dest_code_get_ret;
  uint vfo_freq_ret;
  byte bStack_f;
  
  vfo_freq_ret = vfo_freq(1,2);
  vfo_mode_ret = vfo_mode(1);
                    /* index 0..10 of the first bound in ROM 0xFFF8870C [doc] */
  cVar3 = tx_band_of_freq(vfo_freq_ret);
  bVar2 = g_opstate.rf_power[3];
  if ((vfo_mode_ret == 4) || (vfo_mode_ret == 5)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_f = g_opstate.rf_power[3];
    dest_code_get_ret = dest_code_get();
    if (dest_code_get_ret == 0x60e6) {
      if ((cVar3 == '\t') || (bVar2 < 0xb)) {
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
  else if (cVar3 == '\t') {
    bStack_f = g_opstate.rf_power[1];
  }
  else if (cVar3 == '\n') {
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
  byte i;
  uint local_14;
  uint local_c;
  uint local_4;
  
  local_c = 0;
  local_14 = 10000000;
  local_4 = param_1;
  for (i = 0; i < 8; i = i + 1) {
    uVar1 = local_4;
    if (local_14 != 0) {
      uVar1 = local_4 / local_14;
    }
    local_c = uVar1 << (7 - i & 7) * 4 | local_c;
    local_4 = local_4 - uVar1 * local_14;
    local_14 = local_14 / 10;
  }
  return local_c;
}


// ===== FUN_fffb418a @ fffb418a (143 bytes)

byte FUN_fffb418a(byte param_1)

{
  byte vfo_mode_ret_2;
  byte local_9;
  byte local_1;
  uint vfo_mode_ret;
  
  local_1 = param_1;
  if (g_opstate.split_on != 0) {
    local_1 = 1;
  }
  vfo_mode_ret_2 = vfo_mode(local_1);
  vfo_mode_ret = (uint)vfo_mode_ret_2;
  if (vfo_mode_ret == 0xe) {
LAB_fffb41fc:
    local_9 = g_opstate.monitor[3];
  }
  else {
    if (vfo_mode_ret - 2 < 2) {
      return g_opstate.monitor[1];
    }
    if (vfo_mode_ret - 4 < 2) {
      return g_opstate.monitor[4];
    }
    if (1 < vfo_mode_ret - 6) {
      if (vfo_mode_ret - 8 < 2) goto LAB_fffb41fc;
      if (1 < vfo_mode_ret - 10) {
        if (vfo_mode_ret - 0xc < 2) {
          return g_opstate.monitor[2];
        }
        if (1 < vfo_mode_ret) {
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
  byte tx_cw_keying_class_ret;
  byte bStack_b;
  uint uStack_8;
  byte g_ui_audio_playing_val;
  byte g_ui_dvs_lm1_flag_val;
  byte g_ui_dvs_state_val;
  byte g_ui_ky_send_0_val;
  byte g_ui_ky_send_1_val;
  byte g_ui_msg_rec_active_val;
  byte g_ui_tx_lamp_val;
  
  g_ui_tx_lamp_val = g_ui.tx_lamp;
  bStack_b = vfo_mode(g_ui.transmitting);
  bVar2 = FUN_fffb2dfe();
  g_ui_ky_send_1_val = g_ui.ky_send_1;
  g_ui_ky_send_0_val = g_ui.ky_send_0;
  g_ui_msg_rec_active_val = g_ui.msg_rec_active;
  g_ui_audio_playing_val = g_ui.audio_playing;
  g_ui_dvs_lm1_flag_val = g_ui.dvs_lm1_flag;
  g_ui_dvs_state_val = g_ui.dvs_state;
  tx_cw_keying_class_ret = tx_cw_keying_class();
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
    if ((g_ui_dvs_state_val == 0) && (g_ui_ky_send_0_val != 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (g_ui_ky_send_1_val == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (g_ui_msg_rec_active_val == 1)) {
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
    if (g_ui_tx_lamp_val != 1) {
      if ((g_ui.cw_spot_on == 1) || (bVar2 == 4)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 2;
      }
      else if (g_ui_dvs_lm1_flag_val == 1) {
        uStack_8 = 1;
      }
      else if (g_ui_msg_rec_active_val == 1) {
        uStack_8 = 3;
      }
      else {
        if ((g_ui_audio_playing_val == 1) && (g_ui.playlist_open == 1)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_8 = 5;
        }
        else {
          if ((g_ui_audio_playing_val == 1) || (g_ui_ky_send_0_val == 1)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if ((bVar1) || (g_ui_ky_send_1_val == 1)) {
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
      if ((g_ui_audio_playing_val == 1) || (g_ui_ky_send_0_val == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (g_ui_ky_send_1_val == 1)) {
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
  else if (g_ui_tx_lamp_val != 1) {
    if ((tx_cw_keying_class_ret == 0) || (bVar2 != 4)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      uStack_8 = 2;
    }
    else if (g_ui_dvs_lm1_flag_val == 1) {
      uStack_8 = 9;
    }
    else {
      if ((g_ui_dvs_state_val == 2) || (g_ui.dvs_busy == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        uStack_8 = 10;
      }
      else {
        if ((g_ui_dvs_state_val == 1) && (g_ui.playlist_open == 0)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_8 = 0xb;
        }
        else {
          if ((g_ui_audio_playing_val == 1) && (g_ui.playlist_open == 1)) {
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
    if ((tx_cw_keying_class_ret == 3) && (bVar2 == 4)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uStack_8 = 6;
    }
    else {
      if ((g_ui_audio_playing_val == 1) || (g_ui_dvs_state_val == 1)) {
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
  byte vfo_tune_locked_ret;
  int iVar5;
  byte local_7;
  byte bStack_6;
  ushort local_2;
  
  bVar2 = param_2 >> 4;
  local_7 = 1;
  iVar5 = FUN_fffc4cc5(param_1,param_2);
  if ((iVar5 == 1) && (2 < param_1 - 0xff0)) {
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
  vfo_tune_locked_ret = vfo_tune_locked('\x02');
  if (vfo_tune_locked_ret == 1) {
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
                    /* display time of pop-up id for POP-UP TIME 0x9B0E [doc] */
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
  byte swtimer_expired_ret;
  
  if ((g_ui.power_fail_latch != 1) && (g_ui.adc_pa_vdd < 0x7dd)) {
    swtimer_expired_ret = swtimer_expired(0x13);
    g_ui.power_fail_latch = 1;
    if (swtimer_expired_ret == 1) {
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
  byte vfo_mode_ret;
  short sVar2;
  byte *vfo_rec_ptr_ret;
  ushort uStack_e;
  ushort uStack_a;
  
  vfo_rec_ptr_ret = vfo_rec_ptr(0);
  vfo_mode_ret = vfo_mode(0);
  uStack_e = 0;
  if (g_opstate.ex040202_scope_ctr == 0) {
    uVar1 = (uint)vfo_mode_ret;
    if (uVar1 == 0xe) {
      uStack_e = CONCAT11(vfo_rec_ptr_ret[0x30],vfo_rec_ptr_ret[0x31]);
    }
    else if (uVar1 - 2 < 2) {
      uStack_a = CONCAT11(vfo_rec_ptr_ret[0x1c],vfo_rec_ptr_ret[0x1d]);
      if (vfo_mode_ret == 2) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 8 < 2) {
      uStack_a = CONCAT11(g_opstate.ex010420_data_shift_ssb_be[0],
                          g_opstate.ex010420_data_shift_ssb_be[1]) * 10 +
                 CONCAT11(vfo_rec_ptr_ret[0x30],vfo_rec_ptr_ret[0x31]);
      if (vfo_mode_ret == 8) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
    else if (uVar1 - 0xc < 2) {
      sVar2 = CONCAT11(vfo_rec_ptr_ret[0x26],vfo_rec_ptr_ret[0x27]);
      if (g_opstate.ex010516_shift_frequency == 1) {
        if (vfo_mode_ret == 0xc) {
          uStack_a = sVar2 + 0x69;
        }
        else {
          uStack_a = 0x69 - sVar2;
        }
      }
      else if (g_opstate.ex010516_shift_frequency == 2) {
        if (vfo_mode_ret == 0xc) {
          uStack_a = sVar2 + 0xd7;
        }
        else {
          uStack_a = 0xd7 - sVar2;
        }
      }
      else if (g_opstate.ex010516_shift_frequency == 3) {
        if (vfo_mode_ret == 0xc) {
          uStack_a = sVar2 + 0x1a9;
        }
        else {
          uStack_a = 0x1a9 - sVar2;
        }
      }
      else if (vfo_mode_ret == 0xc) {
        uStack_a = sVar2 + 0x55;
      }
      else {
        uStack_a = 0x55 - sVar2;
      }
      uStack_e = ~uStack_a + 1;
    }
    else if (uVar1 < 2) {
      uStack_a = CONCAT11(vfo_rec_ptr_ret[0x12],vfo_rec_ptr_ret[0x13]);
      if ((vfo_rec_ptr_ret[0x12] & 0x80) != 0) {
        uStack_a = -(~uStack_a + 1);
      }
      uStack_a = uStack_a + 0x5dc;
      if (vfo_mode_ret == 0) {
        uStack_a = ~uStack_a + 1;
      }
      uStack_e = uStack_a;
    }
  }
  return uStack_e;
}

