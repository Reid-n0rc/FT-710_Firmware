// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe19d6 @ fffe19d6 (6 bytes)

void FUN_fffe19d6(void)

{
                    /* direct frequency entry [doc] */
  freq_keypad_key(8);
  return;
}


// ===== FUN_fffe19dc @ fffe19dc (6 bytes)

void FUN_fffe19dc(void)

{
                    /* direct frequency entry [doc] */
  freq_keypad_key(9);
  return;
}


// ===== FUN_fffe19e2 @ fffe19e2 (6 bytes)

void FUN_fffe19e2(void)

{
                    /* direct frequency entry [doc] */
  freq_keypad_key(10);
  return;
}


// ===== FUN_fffe19e8 @ fffe19e8 (6 bytes)

void FUN_fffe19e8(void)

{
                    /* direct frequency entry [doc] */
  freq_keypad_key(0xb);
  return;
}


// ===== FUN_fffe19ee @ fffe19ee (6 bytes)

void FUN_fffe19ee(void)

{
                    /* direct frequency entry [doc] */
  freq_keypad_key(0xc);
  return;
}


// ===== FUN_fffe19f4 @ fffe19f4 (6 bytes)

void FUN_fffe19f4(void)

{
                    /* direct frequency entry [doc] */
  freq_keypad_key(0xd);
  return;
}


// ===== FUN_fffe19fa @ fffe19fa (6 bytes)

void FUN_fffe19fa(void)

{
                    /* direct frequency entry [doc] */
  freq_keypad_key(0xe);
  return;
}


// ===== freq_keypad_key @ fffe1a00 (904 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1d52) */
/* (key): direct frequency entry: digits 0..9 into BCD UI +0x40F..+0x413 (count +0x468), 0x0A..0x0E
   edit / enter / cancel; enter converts with bcd_to_bin and stores the VFO (vfo_store_back) [fact
   for the digits; frequency inference] */

void freq_keypad_key(char param_1)

{
  byte bVar1;
  bool bVar2;
  char bcd_to_bin_ret;
  char bcd_to_bin_ret_2;
  char bcd_to_bin_ret_3;
  char bcd_to_bin_ret_4;
  int iVar3;
  uint uVar4;
  byte i;
  byte local_1;
  
  if (DAT_0001b54e == '\x01') {
    DAT_00018809 = g_opstate.vfo_state_a;
    DAT_0001880a = g_opstate.vfo_state_b;
    DAT_0001b54e = '\0';
  }
  if (PTR_g_ui_00025d6c->keypad_pos < 2) {
    PTR_g_ui_00025d6c->keypad_pos = 2;
  }
  if (param_1 == '\n') {
    FUN_fffe1e85();
    beep_request(1);
    return;
  }
  if (param_1 == '\v') {
    if (PTR_g_ui_00025d6c->keypad_pos == 3) {
      PTR_g_ui_00025d6c->keypad_bcd[1] = PTR_g_ui_00025d6c->keypad_bcd[1] >> 4;
      PTR_g_ui_00025d6c->keypad_pos = 4;
      FUN_fffe1e70();
      beep_request(1);
      return;
    }
    if (PTR_g_ui_00025d6c->keypad_pos != 2) {
      FUN_fffe1e70();
      beep_request(1);
      return;
    }
    PTR_g_ui_00025d6c->keypad_bcd[1] = 0;
    PTR_g_ui_00025d6c->keypad_pos = 4;
    FUN_fffe1e70();
    beep_request(1);
    return;
  }
  if (param_1 != '\f') {
    if (param_1 != '\r') {
      if (param_1 != '\x0e') {
        local_1 = param_1 + 1;
        if (local_1 == 10) {
          local_1 = 0;
        }
        bVar1 = PTR_g_ui_00025d6c->keypad_pos >> 1;
        if ((PTR_g_ui_00025d6c->keypad_pos & 1) == 0) {
          PTR_g_ui_00025d6c->keypad_bcd[bVar1] =
               PTR_g_ui_00025d6c->keypad_bcd[bVar1] & 0xf | local_1 << 4;
        }
        else {
          PTR_g_ui_00025d6c->keypad_bcd[bVar1] =
               PTR_g_ui_00025d6c->keypad_bcd[bVar1] & 0xf0 | local_1;
        }
        if (PTR_g_ui_00025d6c->keypad_pos < 9) {
          PTR_g_ui_00025d6c->keypad_pos = PTR_g_ui_00025d6c->keypad_pos + 1;
        }
        FUN_fffe1e70();
        beep_request(1);
        return;
      }
      g_opstate.vfo_state_a = DAT_00018809;
      g_opstate.vfo_state_b = DAT_0001880a;
      DAT_0001b54e = 1;
      popup8_close();
      FUN_fffe1e70();
      beep_request(1);
      return;
    }
    for (i = 1; i < 5; i = i + 1) {
      if (0x90 < (PTR_g_ui_00025d6c->keypad_bcd[i] & 0xf0)) {
        PTR_g_ui_00025d6c->keypad_bcd[i] = PTR_g_ui_00025d6c->keypad_bcd[i] & 0xf;
      }
      if (9 < (PTR_g_ui_00025d6c->keypad_bcd[i] & 0xf)) {
        PTR_g_ui_00025d6c->keypad_bcd[i] = PTR_g_ui_00025d6c->keypad_bcd[i] & 0xf0;
      }
    }
                    /* Packed BCD byte [doc] */
    bcd_to_bin_ret = bcd_to_bin(PTR_g_ui_00025d6c->keypad_bcd[1]);
    bcd_to_bin_ret_2 = bcd_to_bin(PTR_g_ui_00025d6c->keypad_bcd[2]);
    bcd_to_bin_ret_3 = bcd_to_bin(PTR_g_ui_00025d6c->keypad_bcd[3]);
    bcd_to_bin_ret_4 = bcd_to_bin(PTR_g_ui_00025d6c->keypad_bcd[4]);
    iVar3 = FUN_fffe1dd7((int)bcd_to_bin_ret_4 +
                         bcd_to_bin_ret_3 * 100 +
                         bcd_to_bin_ret_2 * 10000 + bcd_to_bin_ret * 1000000);
    if (iVar3 != 0) {
      uVar4 = PTR_g_ui_00025d6c->freq_clamp_result;
      FUN_fffe1da4(uVar4);
      if (PTR_g_ui_00025d6c->keypad_set_fix == 1) {
        FUN_fffe1d96(uVar4);
      }
      PTR_g_ui_00025d6c->freq_refresh_req = 1;
      FUN_fffe1d88(uVar4);
      popup8_close();
      vfo_mark_edited(g_opstate.active_vfo);
      vfo_store_back(g_opstate.active_vfo);
      FUN_fffe1e70();
      DAT_0001b54e = 1;
      beep_request(1);
      return;
    }
    FUN_fffe1e85();
    beep_request(3);
    return;
  }
  if (PTR_g_ui_00025d6c->keypad_pos == 2) {
    FUN_fffe1e70();
    beep_request(3);
    return;
  }
  if ((PTR_g_ui_00025d6c->keypad_pos == 9) && ((PTR_g_ui_00025d6c->keypad_bcd[4] & 0xf) != 0xf)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    uVar4 = (uint)(PTR_g_ui_00025d6c->keypad_pos >> 1);
    if ((PTR_g_ui_00025d6c->keypad_pos & 1) == 0) {
      PTR_g_ui_00025d6c->keypad_bcd[uVar4 - 1] = PTR_g_ui_00025d6c->keypad_bcd[uVar4 - 1] | 0xf;
    }
    else {
      PTR_g_ui_00025d6c->keypad_bcd[uVar4] = 0xff;
    }
    PTR_g_ui_00025d6c->keypad_pos = PTR_g_ui_00025d6c->keypad_pos - 1;
    FUN_fffe1e70();
    beep_request(1);
    return;
  }
  PTR_g_ui_00025d6c->keypad_bcd[4] = PTR_g_ui_00025d6c->keypad_bcd[4] | 0xf;
  FUN_fffe1e70();
  beep_request(1);
  return;
}


// ===== FUN_fffe1d88 @ fffe1d88 (14 bytes)

void FUN_fffe1d88(uint freq)

{
  bandmem_set('\x01',freq);
  return;
}


// ===== FUN_fffe1d96 @ fffe1d96 (14 bytes)

void FUN_fffe1d96(uint freq)

{
  bandmem_set('\x02',freq);
  return;
}


// ===== FUN_fffe1da4 @ fffe1da4 (51 bytes)

void FUN_fffe1da4(uint param_1)

{
  byte *vfo_rec_ptr_ret;
  byte i;
  
  vfo_rec_ptr_ret = vfo_rec_ptr(0);
  for (i = 0; i < 4; i = i + 1) {
    vfo_rec_ptr_ret[i + 0x4a] = (byte)(param_1 >> ((3 - i & 3) << 3));
  }
  return;
}


// ===== FUN_fffe1dd7 @ fffe1dd7 (153 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1e6d) */

bool FUN_fffe1dd7(uint param_1)

{
  uint freq_clamp_ret;
  vfo_side g_opstate_active_vfo_val;
  ui_state *p_ui_state;
  
  PTR_g_ui_00025d6c->freq_clamp_result = param_1;
  g_opstate_active_vfo_val = g_opstate.active_vfo;
  if (g_opstate.active_vfo == VFO_A) {
    if (g_opstate.vfo_state_a == VFO_STATE_MEMORY) {
      vfo_mem_to_memtune('\0');
    }
  }
  else if (g_opstate.vfo_state_b == VFO_STATE_MEMORY) {
    vfo_mem_to_memtune(g_opstate.active_vfo);
  }
  PTR_g_ui_00025d6c->pms_inhibit = 1;
  p_ui_state = PTR_g_ui_00025d6c;
  freq_clamp_ret = freq_clamp(g_opstate_active_vfo_val,param_1);
  p_ui_state->freq_clamp_result = freq_clamp_ret;
  PTR_g_ui_00025d6c->pms_inhibit = 0;
  return PTR_g_ui_00025d6c->freq_rejected != 1;
}


// ===== FUN_fffe1e70 @ fffe1e70 (21 bytes)

void FUN_fffe1e70(void)

{
  DAT_00018808 = 1;
  swtimer_start(0x46,10000);
  return;
}


// ===== FUN_fffe1e85 @ fffe1e85 (95 bytes)

void FUN_fffe1e85(void)

{
  PTR_g_ui_00025d6c->keypad_bcd[0] = 0xff;
  PTR_g_ui_00025d6c->keypad_bcd[1] = 0xff;
  PTR_g_ui_00025d6c->keypad_bcd[2] = 0xff;
  PTR_g_ui_00025d6c->keypad_bcd[3] = 0xff;
  PTR_g_ui_00025d6c->keypad_bcd[4] = 0xff;
  PTR_g_ui_00025d6c->keypad_open = 1;
  FUN_fffe1e70();
  PTR_g_ui_00025d6c->keypad_pos = 0;
  return;
}


// ===== FUN_fffe1ee4 @ fffe1ee4 (89 bytes)

void FUN_fffe1ee4(void)

{
  bool bVar1;
  byte swtimer_expired_ret;
  
  if (DAT_00018808 != '\0') {
    if ((PTR_g_ui_00025d6c->keypad_open == 1) || (PTR_g_ui_00025d6c->popup7_open == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (swtimer_expired_ret = swtimer_expired(0x46), swtimer_expired_ret == 1)) {
      DAT_00018808 = 0;
      popup8_close();
      FUN_fffe1f3d();
      return;
    }
  }
  return;
}


// ===== FUN_fffe1f3d @ fffe1f3d (35 bytes)

void FUN_fffe1f3d(void)

{
  if (PTR_g_ui_00025d6c->popup7_open != 1) {
    return;
  }
  PTR_g_ui_00025d6c->popup7_open = 0;
  popup_close();
  return;
}


// ===== FUN_fffe1f60 @ fffe1f60 (197 bytes)

void FUN_fffe1f60(void)

{
  bool bVar1;
  ui_state *p_ui_state;
  
  if (PTR_g_ui_00025d6c->popup7_open == 1) {
    popup8_close();
    FUN_fffe1f3d();
    beep_request(1);
    return;
  }
  if ((PTR_g_ui_00025d6c->dl_req_popup_b == 1) && (PTR_g_ui_00025d6c->popup_code == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    beep_request(1);
    return;
  }
  PTR_g_ui_00025d6c->popup_code = 7;
  PTR_g_ui_00025d6c->dl_req_popup_b = 1;
  PTR_g_ui_00025d6c->dl_req_popup_a = 1;
  g_opstate.split_on = 1;
  PTR_g_ui_00025d6c->popup7_open = 1;
  p_ui_state = PTR_g_ui_00025d6c;
  p_ui_state->keypad_bcd[0] = 0xff;
  p_ui_state->keypad_bcd[1] = 0xff;
  p_ui_state->keypad_bcd[2] = 0xff;
  p_ui_state->keypad_bcd[3] = 0xff;
  swtimer_start(0x46,10000);
  DAT_00018808 = 1;
  PTR_g_ui_00025d6c->keypad_pos = 0;
  return;
}


// ===== FUN_fffe2025 @ fffe2025 (6 bytes)

void FUN_fffe2025(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\0');
  return;
}


// ===== FUN_fffe202b @ fffe202b (6 bytes)

void FUN_fffe202b(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\x01');
  return;
}


// ===== FUN_fffe2031 @ fffe2031 (6 bytes)

void FUN_fffe2031(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\x02');
  return;
}


// ===== FUN_fffe2037 @ fffe2037 (6 bytes)

void FUN_fffe2037(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\x03');
  return;
}


// ===== FUN_fffe203d @ fffe203d (6 bytes)

void FUN_fffe203d(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\x04');
  return;
}


// ===== FUN_fffe2043 @ fffe2043 (6 bytes)

void FUN_fffe2043(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\x05');
  return;
}


// ===== FUN_fffe2049 @ fffe2049 (6 bytes)

void FUN_fffe2049(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\x06');
  return;
}


// ===== FUN_fffe204f @ fffe204f (6 bytes)

void FUN_fffe204f(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\a');
  return;
}


// ===== FUN_fffe2055 @ fffe2055 (6 bytes)

void FUN_fffe2055(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\b');
  return;
}


// ===== FUN_fffe205b @ fffe205b (6 bytes)

void FUN_fffe205b(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\t');
  return;
}


// ===== FUN_fffe2061 @ fffe2061 (6 bytes)

void FUN_fffe2061(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\n');
  return;
}


// ===== FUN_fffe2067 @ fffe2067 (6 bytes)

void FUN_fffe2067(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\v');
  return;
}


// ===== FUN_fffe206d @ fffe206d (6 bytes)

void FUN_fffe206d(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\f');
  return;
}


// ===== FUN_fffe2073 @ fffe2073 (6 bytes)

void FUN_fffe2073(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\r');
  return;
}


// ===== FUN_fffe2079 @ fffe2079 (6 bytes)

void FUN_fffe2079(void)

{
                    /* two-digit BCD entry in UI +0x411/+0x412 [doc] */
  keypad_2digit_key('\x0e');
  return;
}


// ===== keypad_2digit_key @ fffe207f (538 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe20c9) */
/* WARNING: Removing unreachable block (ram,0xfffe20f0) */
/* WARNING: Removing unreachable block (ram,0xfffe225e) */
/* (key): two-digit BCD entry in UI +0x411/+0x412 (count +0x468); enter accepts 0..20 (bcd_to_bin),
   else FUN_fffe2299 [fact]; what the value selects [unknown] */

void keypad_2digit_key(char param_1)

{
  bool bVar1;
  byte bVar2;
  byte local_1;
  
  beep_request(1);
  if (param_1 == '\n') {
    PTR_g_ui_00025d6c->keypad_bcd[2] = 0xff;
    PTR_g_ui_00025d6c->keypad_bcd[3] = 0xff;
    PTR_g_ui_00025d6c->keypad_pos = 0;
    FUN_fffe1e70();
    return;
  }
  if (param_1 == '\v') {
    if ((PTR_g_ui_00025d6c->keypad_bcd[2] & 0xf0) == 0xa0) {
      PTR_g_ui_00025d6c->keypad_bcd[2] = PTR_g_ui_00025d6c->keypad_bcd[2] | 0xf0;
    }
    else {
      PTR_g_ui_00025d6c->keypad_bcd[2] = PTR_g_ui_00025d6c->keypad_bcd[2] & 0xaf | 0xa0;
    }
    FUN_fffe1e70();
    return;
  }
  if (param_1 != '\f') {
    if (param_1 != '\r') {
      if (param_1 == '\x0e') {
        popup8_close();
        FUN_fffe1f3d();
        return;
      }
      local_1 = param_1 + 1;
      if (local_1 == 10) {
        local_1 = 0;
      }
      if (PTR_g_ui_00025d6c->keypad_pos == 0) {
        PTR_g_ui_00025d6c->keypad_bcd[2] = PTR_g_ui_00025d6c->keypad_bcd[2] & 0xf0 | local_1;
      }
      else {
        PTR_g_ui_00025d6c->keypad_bcd[3] = PTR_g_ui_00025d6c->keypad_bcd[3] & 0xf | local_1 << 4;
      }
      if (PTR_g_ui_00025d6c->keypad_pos != 1) {
        PTR_g_ui_00025d6c->keypad_pos = PTR_g_ui_00025d6c->keypad_pos + 1;
      }
      FUN_fffe1e70();
      return;
    }
    if (PTR_g_ui_00025d6c->keypad_bcd[3] == 0xff) {
      PTR_g_ui_00025d6c->keypad_bcd[3] = PTR_g_ui_00025d6c->keypad_bcd[2] << 4 | 0xf;
      PTR_g_ui_00025d6c->keypad_bcd[2] = PTR_g_ui_00025d6c->keypad_bcd[2] & 0xf0;
    }
    bVar2 = PTR_g_ui_00025d6c->keypad_bcd[2] << 4 | PTR_g_ui_00025d6c->keypad_bcd[3] >> 4;
    if (0x20 < bVar2) {
      FUN_fffe2299();
      FUN_fffe1e70();
      return;
    }
                    /* Packed BCD byte [doc] */
    bcd_to_bin(bVar2);
    popup8_close();
    FUN_fffe1f3d();
    return;
  }
  if (PTR_g_ui_00025d6c->keypad_pos == 0) {
    FUN_fffe1e70();
    return;
  }
  if ((PTR_g_ui_00025d6c->keypad_pos == 1) && ((PTR_g_ui_00025d6c->keypad_bcd[3] & 0xf0) != 0xf0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_g_ui_00025d6c->keypad_bcd[3] = PTR_g_ui_00025d6c->keypad_bcd[3] | 0xf0;
    FUN_fffe1e70();
    return;
  }
  PTR_g_ui_00025d6c->keypad_pos = 0;
  PTR_g_ui_00025d6c->keypad_bcd[2] = PTR_g_ui_00025d6c->keypad_bcd[2] | 0xf;
  PTR_g_ui_00025d6c->keypad_bcd[3] = 0xff;
  FUN_fffe1e70();
  return;
}


// ===== FUN_fffe2299 @ fffe2299 (40 bytes)

void FUN_fffe2299(void)

{
  PTR_g_ui_00025d6c->keypad_bcd[2] = 0xff;
  PTR_g_ui_00025d6c->keypad_bcd[3] = 0xff;
  PTR_g_ui_00025d6c->keypad_pos = 0;
  return;
}


// ===== FUN_fffe22c1 @ fffe22c1 (7 bytes)

void FUN_fffe22c1(void)

{
  kbd_key_dispatch(0x20);
  return;
}


// ===== FUN_fffe22c8 @ fffe22c8 (7 bytes)

void FUN_fffe22c8(void)

{
  kbd_key_dispatch(0x21);
  return;
}


// ===== FUN_fffe22cf @ fffe22cf (7 bytes)

void FUN_fffe22cf(void)

{
  kbd_key_dispatch(0x22);
  return;
}


// ===== FUN_fffe22d6 @ fffe22d6 (7 bytes)

void FUN_fffe22d6(void)

{
  kbd_key_dispatch(0x23);
  return;
}


// ===== FUN_fffe22dd @ fffe22dd (7 bytes)

void FUN_fffe22dd(void)

{
  kbd_key_dispatch(0x24);
  return;
}


// ===== FUN_fffe22e4 @ fffe22e4 (7 bytes)

void FUN_fffe22e4(void)

{
  kbd_key_dispatch(0x25);
  return;
}


// ===== FUN_fffe22eb @ fffe22eb (7 bytes)

void FUN_fffe22eb(void)

{
  kbd_key_dispatch(0x26);
  return;
}


// ===== FUN_fffe22f2 @ fffe22f2 (7 bytes)

void FUN_fffe22f2(void)

{
  kbd_key_dispatch(0x27);
  return;
}


// ===== FUN_fffe22f9 @ fffe22f9 (7 bytes)

void FUN_fffe22f9(void)

{
  kbd_key_dispatch(0x28);
  return;
}


// ===== FUN_fffe2300 @ fffe2300 (7 bytes)

void FUN_fffe2300(void)

{
  kbd_key_dispatch(0x29);
  return;
}


// ===== FUN_fffe2307 @ fffe2307 (7 bytes)

void FUN_fffe2307(void)

{
  kbd_key_dispatch(0x2a);
  return;
}


// ===== FUN_fffe230e @ fffe230e (7 bytes)

void FUN_fffe230e(void)

{
  kbd_key_dispatch(0x2b);
  return;
}


// ===== FUN_fffe2315 @ fffe2315 (7 bytes)

void FUN_fffe2315(void)

{
  kbd_key_dispatch(0x2c);
  return;
}


// ===== FUN_fffe231c @ fffe231c (7 bytes)

void FUN_fffe231c(void)

{
  kbd_key_dispatch(0x2d);
  return;
}


// ===== FUN_fffe2323 @ fffe2323 (7 bytes)

void FUN_fffe2323(void)

{
  kbd_key_dispatch(0x2e);
  return;
}


// ===== FUN_fffe232a @ fffe232a (7 bytes)

void FUN_fffe232a(void)

{
  kbd_key_dispatch(0x2f);
  return;
}

