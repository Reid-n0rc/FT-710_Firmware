// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== ai_ex_preset_lcut_freq @ fffeb165 (340 bytes)

/* Shared AI detector for EX060n08 (PRESET n lcut_freq): called by ai_ex06{01..05}08 with n = 1..5;
   compares g_opstate.presets[n-1].lcut_freq with its shadow, formats with ai_ex_fmt_u8 [fact:
   fffeb165] */

void ai_ex_preset_lcut_freq(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b577 != g_opstate.presets[4].lcut_freq) {
      DAT_0001b577 = g_opstate.presets[4].lcut_freq;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[4].lcut_freq,0,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b574 != g_opstate.presets[1].lcut_freq) {
      DAT_0001b574 = g_opstate.presets[1].lcut_freq;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[1].lcut_freq,0,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b575 != g_opstate.presets[2].lcut_freq) {
      DAT_0001b575 = g_opstate.presets[2].lcut_freq;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[2].lcut_freq,0,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b576 != g_opstate.presets[3].lcut_freq) {
      DAT_0001b576 = g_opstate.presets[3].lcut_freq;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[3].lcut_freq,0,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b573 != g_opstate.presets[0].lcut_freq)) {
    DAT_0001b573 = g_opstate.presets[0].lcut_freq;
    DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[0].lcut_freq,0,0);
    return;
  }
  return;
}


// ===== ai_ex_preset_lcut_slope @ fffeb2b9 (380 bytes)

/* Shared AI detector for EX060n09 (PRESET n lcut_slope): called by ai_ex06{01..05}09 with n = 1..5;
   compares g_opstate.presets[n-1].lcut_slope with its shadow, formats with nib2hex [fact: fffeb2b9]
    */

void ai_ex_preset_lcut_slope(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b57c != g_opstate.presets[4].lcut_slope) {
      DAT_0001b57c = g_opstate.presets[4].lcut_slope;
      DAT_0001b23d = nib2hex(g_opstate.presets[4].lcut_slope);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b579 != g_opstate.presets[1].lcut_slope) {
      DAT_0001b579 = g_opstate.presets[1].lcut_slope;
      DAT_0001b23d = nib2hex(g_opstate.presets[1].lcut_slope);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b57a != g_opstate.presets[2].lcut_slope) {
      DAT_0001b57a = g_opstate.presets[2].lcut_slope;
      DAT_0001b23d = nib2hex(g_opstate.presets[2].lcut_slope);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b57b != g_opstate.presets[3].lcut_slope) {
      DAT_0001b57b = g_opstate.presets[3].lcut_slope;
      DAT_0001b23d = nib2hex(g_opstate.presets[3].lcut_slope);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b578 != g_opstate.presets[0].lcut_slope)) {
    DAT_0001b578 = g_opstate.presets[0].lcut_slope;
    DAT_0001b23d = nib2hex(g_opstate.presets[0].lcut_slope);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== ai_ex_preset_hcut_freq @ fffeb435 (340 bytes)

/* Shared AI detector for EX060n10 (PRESET n hcut_freq): called by ai_ex06{01..05}10 with n = 1..5;
   compares g_opstate.presets[n-1].hcut_freq with its shadow, formats with ai_ex_fmt_u8 [fact:
   fffeb435] */

void ai_ex_preset_hcut_freq(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b581 != g_opstate.presets[4].hcut_freq) {
      DAT_0001b581 = g_opstate.presets[4].hcut_freq;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[4].hcut_freq,0,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b57e != g_opstate.presets[1].hcut_freq) {
      DAT_0001b57e = g_opstate.presets[1].hcut_freq;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[1].hcut_freq,0,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b57f != g_opstate.presets[2].hcut_freq) {
      DAT_0001b57f = g_opstate.presets[2].hcut_freq;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[2].hcut_freq,0,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b580 != g_opstate.presets[3].hcut_freq) {
      DAT_0001b580 = g_opstate.presets[3].hcut_freq;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[3].hcut_freq,0,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b57d != g_opstate.presets[0].hcut_freq)) {
    DAT_0001b57d = g_opstate.presets[0].hcut_freq;
    DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[0].hcut_freq,0,0);
    return;
  }
  return;
}


// ===== ai_ex_preset_hcut_slope @ fffeb589 (380 bytes)

/* Shared AI detector for EX060n11 (PRESET n hcut_slope): called by ai_ex06{01..05}11 with n = 1..5;
   compares g_opstate.presets[n-1].hcut_slope with its shadow, formats with nib2hex [fact: fffeb589]
    */

void ai_ex_preset_hcut_slope(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b586 != g_opstate.presets[4].hcut_slope) {
      DAT_0001b586 = g_opstate.presets[4].hcut_slope;
      DAT_0001b23d = nib2hex(g_opstate.presets[4].hcut_slope);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b583 != g_opstate.presets[1].hcut_slope) {
      DAT_0001b583 = g_opstate.presets[1].hcut_slope;
      DAT_0001b23d = nib2hex(g_opstate.presets[1].hcut_slope);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b584 != g_opstate.presets[2].hcut_slope) {
      DAT_0001b584 = g_opstate.presets[2].hcut_slope;
      DAT_0001b23d = nib2hex(g_opstate.presets[2].hcut_slope);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b585 != g_opstate.presets[3].hcut_slope) {
      DAT_0001b585 = g_opstate.presets[3].hcut_slope;
      DAT_0001b23d = nib2hex(g_opstate.presets[3].hcut_slope);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b582 != g_opstate.presets[0].hcut_slope)) {
    DAT_0001b582 = g_opstate.presets[0].hcut_slope;
    DAT_0001b23d = nib2hex(g_opstate.presets[0].hcut_slope);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== ai_ex_preset_usb_out_level @ fffeb705 (340 bytes)

/* Shared AI detector for EX060n12 (PRESET n usb_out_level): called by ai_ex06{01..05}12 with n =
   1..5; compares g_opstate.presets[n-1].usb_out_level with its shadow, formats with ai_ex_fmt_u8
   [fact: fffeb705] */

void ai_ex_preset_usb_out_level(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b58b != g_opstate.presets[4].usb_out_level) {
      DAT_0001b58b = g_opstate.presets[4].usb_out_level;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[4].usb_out_level,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b588 != g_opstate.presets[1].usb_out_level) {
      DAT_0001b588 = g_opstate.presets[1].usb_out_level;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[1].usb_out_level,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b589 != g_opstate.presets[2].usb_out_level) {
      DAT_0001b589 = g_opstate.presets[2].usb_out_level;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[2].usb_out_level,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b58a != g_opstate.presets[3].usb_out_level) {
      DAT_0001b58a = g_opstate.presets[3].usb_out_level;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[3].usb_out_level,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b587 != g_opstate.presets[0].usb_out_level)) {
    DAT_0001b587 = g_opstate.presets[0].usb_out_level;
    DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[0].usb_out_level,1,0);
    return;
  }
  return;
}


// ===== ai_ex_preset_rear_out_level @ fffeb859 (340 bytes)

/* Shared AI detector for EX060n13 (PRESET n rear_out_level): called by ai_ex06{01..05}13 with n =
   1..5; compares g_opstate.presets[n-1].rear_out_level with its shadow, formats with ai_ex_fmt_u8
   [fact: fffeb859] */

void ai_ex_preset_rear_out_level(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b590 != g_opstate.presets[4].rear_out_level) {
      DAT_0001b590 = g_opstate.presets[4].rear_out_level;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[4].rear_out_level,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b58d != g_opstate.presets[1].rear_out_level) {
      DAT_0001b58d = g_opstate.presets[1].rear_out_level;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[1].rear_out_level,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b58e != g_opstate.presets[2].rear_out_level) {
      DAT_0001b58e = g_opstate.presets[2].rear_out_level;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[2].rear_out_level,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b58f != g_opstate.presets[3].rear_out_level) {
      DAT_0001b58f = g_opstate.presets[3].rear_out_level;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[3].rear_out_level,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b58c != g_opstate.presets[0].rear_out_level)) {
    DAT_0001b58c = g_opstate.presets[0].rear_out_level;
    DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[0].rear_out_level,1,0);
    return;
  }
  return;
}


// ===== ai_ex_preset_tx_bpf_sel @ fffeb9ad (380 bytes)

/* Shared AI detector for EX060n14 (PRESET n tx_bpf_sel): called by ai_ex06{01..05}14 with n = 1..5;
   compares g_opstate.presets[n-1].tx_bpf_sel with its shadow, formats with nib2hex [fact: fffeb9ad]
    */

void ai_ex_preset_tx_bpf_sel(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b595 != g_opstate.presets[4].tx_bpf_sel) {
      DAT_0001b595 = g_opstate.presets[4].tx_bpf_sel;
      DAT_0001b23d = nib2hex(g_opstate.presets[4].tx_bpf_sel);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b592 != g_opstate.presets[1].tx_bpf_sel) {
      DAT_0001b592 = g_opstate.presets[1].tx_bpf_sel;
      DAT_0001b23d = nib2hex(g_opstate.presets[1].tx_bpf_sel);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b593 != g_opstate.presets[2].tx_bpf_sel) {
      DAT_0001b593 = g_opstate.presets[2].tx_bpf_sel;
      DAT_0001b23d = nib2hex(g_opstate.presets[2].tx_bpf_sel);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b594 != g_opstate.presets[3].tx_bpf_sel) {
      DAT_0001b594 = g_opstate.presets[3].tx_bpf_sel;
      DAT_0001b23d = nib2hex(g_opstate.presets[3].tx_bpf_sel);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b591 != g_opstate.presets[0].tx_bpf_sel)) {
    DAT_0001b591 = g_opstate.presets[0].tx_bpf_sel;
    DAT_0001b23d = nib2hex(g_opstate.presets[0].tx_bpf_sel);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== ai_ex_preset_mod_source @ fffebb29 (380 bytes)

/* Shared AI detector for EX060n15 (PRESET n mod_source): called by ai_ex06{01..05}15 with n = 1..5;
   compares g_opstate.presets[n-1].mod_source with its shadow, formats with nib2hex [fact: fffebb29]
    */

void ai_ex_preset_mod_source(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b59a != g_opstate.presets[4].mod_source) {
      DAT_0001b59a = g_opstate.presets[4].mod_source;
      DAT_0001b23d = nib2hex(g_opstate.presets[4].mod_source);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b597 != g_opstate.presets[1].mod_source) {
      DAT_0001b597 = g_opstate.presets[1].mod_source;
      DAT_0001b23d = nib2hex(g_opstate.presets[1].mod_source);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b598 != g_opstate.presets[2].mod_source) {
      DAT_0001b598 = g_opstate.presets[2].mod_source;
      DAT_0001b23d = nib2hex(g_opstate.presets[2].mod_source);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b599 != g_opstate.presets[3].mod_source) {
      DAT_0001b599 = g_opstate.presets[3].mod_source;
      DAT_0001b23d = nib2hex(g_opstate.presets[3].mod_source);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b596 != g_opstate.presets[0].mod_source)) {
    DAT_0001b596 = g_opstate.presets[0].mod_source;
    DAT_0001b23d = nib2hex(g_opstate.presets[0].mod_source);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== ai_ex_preset_usb_mod_gain @ fffebca5 (340 bytes)

/* Shared AI detector for EX060n16 (PRESET n usb_mod_gain): called by ai_ex06{01..05}16 with n =
   1..5; compares g_opstate.presets[n-1].usb_mod_gain with its shadow, formats with ai_ex_fmt_u8
   [fact: fffebca5] */

void ai_ex_preset_usb_mod_gain(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b59f != g_opstate.presets[4].usb_mod_gain) {
      DAT_0001b59f = g_opstate.presets[4].usb_mod_gain;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[4].usb_mod_gain,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b59c != g_opstate.presets[1].usb_mod_gain) {
      DAT_0001b59c = g_opstate.presets[1].usb_mod_gain;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[1].usb_mod_gain,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b59d != g_opstate.presets[2].usb_mod_gain) {
      DAT_0001b59d = g_opstate.presets[2].usb_mod_gain;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[2].usb_mod_gain,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b59e != g_opstate.presets[3].usb_mod_gain) {
      DAT_0001b59e = g_opstate.presets[3].usb_mod_gain;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[3].usb_mod_gain,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b59b != g_opstate.presets[0].usb_mod_gain)) {
    DAT_0001b59b = g_opstate.presets[0].usb_mod_gain;
    DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[0].usb_mod_gain,1,0);
    return;
  }
  return;
}


// ===== ai_ex_preset_rear_mod_gain @ fffebdf9 (340 bytes)

/* Shared AI detector for EX060n17 (PRESET n rear_mod_gain): called by ai_ex06{01..05}17 with n =
   1..5; compares g_opstate.presets[n-1].rear_mod_gain with its shadow, formats with ai_ex_fmt_u8
   [fact: fffebdf9] */

void ai_ex_preset_rear_mod_gain(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b5a4 != g_opstate.presets[4].rear_mod_gain) {
      DAT_0001b5a4 = g_opstate.presets[4].rear_mod_gain;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[4].rear_mod_gain,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b5a1 != g_opstate.presets[1].rear_mod_gain) {
      DAT_0001b5a1 = g_opstate.presets[1].rear_mod_gain;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[1].rear_mod_gain,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b5a2 != g_opstate.presets[2].rear_mod_gain) {
      DAT_0001b5a2 = g_opstate.presets[2].rear_mod_gain;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[2].rear_mod_gain,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b5a3 != g_opstate.presets[3].rear_mod_gain) {
      DAT_0001b5a3 = g_opstate.presets[3].rear_mod_gain;
      DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[3].rear_mod_gain,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b5a0 != g_opstate.presets[0].rear_mod_gain)) {
    DAT_0001b5a0 = g_opstate.presets[0].rear_mod_gain;
    DAT_0001ff12 = ai_ex_fmt_u8(g_opstate.presets[0].rear_mod_gain,1,0);
    return;
  }
  return;
}


// ===== ai_ex_preset_rptt_select @ fffebf4d (380 bytes)

/* Shared AI detector for EX060n18 (PRESET n rptt_select): called by ai_ex06{01..05}18 with n =
   1..5; compares g_opstate.presets[n-1].rptt_select with its shadow, formats with nib2hex [fact:
   fffebf4d] */

void ai_ex_preset_rptt_select(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b5a9 != g_opstate.presets[4].rptt_select) {
      DAT_0001b5a9 = g_opstate.presets[4].rptt_select;
      DAT_0001b23d = nib2hex(g_opstate.presets[4].rptt_select);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b5a6 != g_opstate.presets[1].rptt_select) {
      DAT_0001b5a6 = g_opstate.presets[1].rptt_select;
      DAT_0001b23d = nib2hex(g_opstate.presets[1].rptt_select);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b5a7 != g_opstate.presets[2].rptt_select) {
      DAT_0001b5a7 = g_opstate.presets[2].rptt_select;
      DAT_0001b23d = nib2hex(g_opstate.presets[2].rptt_select);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b5a8 != g_opstate.presets[3].rptt_select) {
      DAT_0001b5a8 = g_opstate.presets[3].rptt_select;
      DAT_0001b23d = nib2hex(g_opstate.presets[3].rptt_select);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b5a5 != g_opstate.presets[0].rptt_select)) {
    DAT_0001b5a5 = g_opstate.presets[0].rptt_select;
    DAT_0001b23d = nib2hex(g_opstate.presets[0].rptt_select);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== ai_ex060101 @ fffec0c9 (6 bytes)

/* AI change detector for menu item EX060101 (table 0xFFF8E1A0[206]) */

void ai_ex060101(void)

{
  ai_ex_preset_name(1);
  return;
}


// ===== ai_ex060102 @ fffec0cf (6 bytes)

/* AI change detector for menu item EX060102 (table 0xFFF8E1A0[207]) */

void ai_ex060102(void)

{
  ai_ex_preset_cat1_rate(1);
  return;
}


// ===== ai_ex060103 @ fffec0d5 (6 bytes)

/* AI change detector for menu item EX060103 (table 0xFFF8E1A0[208]) */

void ai_ex060103(void)

{
  ai_ex_preset_cat1_tot(1);
  return;
}


// ===== ai_ex060104 @ fffec0db (6 bytes)

/* AI change detector for menu item EX060104 (table 0xFFF8E1A0[209]) */

void ai_ex060104(void)

{
  ai_ex_preset_cat1_cat3_stop_bit(1);
  return;
}


// ===== ai_ex060105 @ fffec0e1 (6 bytes)

/* AI change detector for menu item EX060105 (table 0xFFF8E1A0[210]) */

void ai_ex060105(void)

{
  ai_ex_preset_agc_fast_delay(1);
  return;
}


// ===== ai_ex060106 @ fffec0e7 (6 bytes)

/* AI change detector for menu item EX060106 (table 0xFFF8E1A0[211]) */

void ai_ex060106(void)

{
  ai_ex_preset_agc_mid_delay(1);
  return;
}


// ===== ai_ex060107 @ fffec0ed (6 bytes)

/* AI change detector for menu item EX060107 (table 0xFFF8E1A0[212]) */

void ai_ex060107(void)

{
  ai_ex_preset_agc_slow_delay(1);
  return;
}


// ===== ai_ex060108 @ fffec0f3 (6 bytes)

/* AI change detector for menu item EX060108 (table 0xFFF8E1A0[213]) */

void ai_ex060108(void)

{
  ai_ex_preset_lcut_freq(1);
  return;
}


// ===== ai_ex060109 @ fffec0f9 (6 bytes)

/* AI change detector for menu item EX060109 (table 0xFFF8E1A0[214]) */

void ai_ex060109(void)

{
  ai_ex_preset_lcut_slope(1);
  return;
}


// ===== ai_ex060110 @ fffec0ff (6 bytes)

/* AI change detector for menu item EX060110 (table 0xFFF8E1A0[215]) */

void ai_ex060110(void)

{
  ai_ex_preset_hcut_freq(1);
  return;
}


// ===== ai_ex060111 @ fffec105 (6 bytes)

/* AI change detector for menu item EX060111 (table 0xFFF8E1A0[216]) */

void ai_ex060111(void)

{
  ai_ex_preset_hcut_slope(1);
  return;
}


// ===== ai_ex060112 @ fffec10b (6 bytes)

/* AI change detector for menu item EX060112 (table 0xFFF8E1A0[217]) */

void ai_ex060112(void)

{
  ai_ex_preset_usb_out_level(1);
  return;
}


// ===== ai_ex060113 @ fffec111 (6 bytes)

/* AI change detector for menu item EX060113 (table 0xFFF8E1A0[218]) */

void ai_ex060113(void)

{
  ai_ex_preset_rear_out_level(1);
  return;
}


// ===== ai_ex060114 @ fffec117 (6 bytes)

/* AI change detector for menu item EX060114 (table 0xFFF8E1A0[219]) */

void ai_ex060114(void)

{
  ai_ex_preset_tx_bpf_sel(1);
  return;
}


// ===== ai_ex060115 @ fffec11d (6 bytes)

/* AI change detector for menu item EX060115 (table 0xFFF8E1A0[220]) */

void ai_ex060115(void)

{
  ai_ex_preset_mod_source(1);
  return;
}


// ===== ai_ex060116 @ fffec123 (6 bytes)

/* AI change detector for menu item EX060116 (table 0xFFF8E1A0[221]) */

void ai_ex060116(void)

{
  ai_ex_preset_usb_mod_gain(1);
  return;
}


// ===== ai_ex060117 @ fffec129 (6 bytes)

/* AI change detector for menu item EX060117 (table 0xFFF8E1A0[222]) */

void ai_ex060117(void)

{
  ai_ex_preset_rear_mod_gain(1);
  return;
}


// ===== ai_ex060118 @ fffec12f (6 bytes)

/* AI change detector for menu item EX060118 (table 0xFFF8E1A0[223]) */

void ai_ex060118(void)

{
  ai_ex_preset_rptt_select(1);
  return;
}


// ===== ai_ex060201 @ fffec135 (6 bytes)

/* AI change detector for menu item EX060201 (table 0xFFF8E1A0[224]) */

void ai_ex060201(void)

{
  ai_ex_preset_name(2);
  return;
}


// ===== ai_ex060202 @ fffec13b (6 bytes)

/* AI change detector for menu item EX060202 (table 0xFFF8E1A0[225]) */

void ai_ex060202(void)

{
  ai_ex_preset_cat1_rate(2);
  return;
}


// ===== ai_ex060203 @ fffec141 (6 bytes)

/* AI change detector for menu item EX060203 (table 0xFFF8E1A0[226]) */

void ai_ex060203(void)

{
  ai_ex_preset_cat1_tot(2);
  return;
}


// ===== ai_ex060204 @ fffec147 (6 bytes)

/* AI change detector for menu item EX060204 (table 0xFFF8E1A0[227]) */

void ai_ex060204(void)

{
  ai_ex_preset_cat1_cat3_stop_bit(2);
  return;
}


// ===== ai_ex060205 @ fffec14d (6 bytes)

/* AI change detector for menu item EX060205 (table 0xFFF8E1A0[228]) */

void ai_ex060205(void)

{
  ai_ex_preset_agc_fast_delay(2);
  return;
}


// ===== ai_ex060206 @ fffec153 (6 bytes)

/* AI change detector for menu item EX060206 (table 0xFFF8E1A0[229]) */

void ai_ex060206(void)

{
  ai_ex_preset_agc_mid_delay(2);
  return;
}


// ===== ai_ex060207 @ fffec159 (6 bytes)

/* AI change detector for menu item EX060207 (table 0xFFF8E1A0[230]) */

void ai_ex060207(void)

{
  ai_ex_preset_agc_slow_delay(2);
  return;
}


// ===== ai_ex060208 @ fffec15f (6 bytes)

/* AI change detector for menu item EX060208 (table 0xFFF8E1A0[231]) */

void ai_ex060208(void)

{
  ai_ex_preset_lcut_freq(2);
  return;
}


// ===== ai_ex060209 @ fffec165 (6 bytes)

/* AI change detector for menu item EX060209 (table 0xFFF8E1A0[232]) */

void ai_ex060209(void)

{
  ai_ex_preset_lcut_slope(2);
  return;
}


// ===== ai_ex060210 @ fffec16b (6 bytes)

/* AI change detector for menu item EX060210 (table 0xFFF8E1A0[233]) */

void ai_ex060210(void)

{
  ai_ex_preset_hcut_freq(2);
  return;
}


// ===== ai_ex060211 @ fffec171 (6 bytes)

/* AI change detector for menu item EX060211 (table 0xFFF8E1A0[234]) */

void ai_ex060211(void)

{
  ai_ex_preset_hcut_slope(2);
  return;
}


// ===== ai_ex060212 @ fffec177 (6 bytes)

/* AI change detector for menu item EX060212 (table 0xFFF8E1A0[235]) */

void ai_ex060212(void)

{
  ai_ex_preset_usb_out_level(2);
  return;
}


// ===== ai_ex060213 @ fffec17d (6 bytes)

/* AI change detector for menu item EX060213 (table 0xFFF8E1A0[236]) */

void ai_ex060213(void)

{
  ai_ex_preset_rear_out_level(2);
  return;
}


// ===== ai_ex060214 @ fffec183 (6 bytes)

/* AI change detector for menu item EX060214 (table 0xFFF8E1A0[237]) */

void ai_ex060214(void)

{
  ai_ex_preset_tx_bpf_sel(2);
  return;
}


// ===== ai_ex060215 @ fffec189 (6 bytes)

/* AI change detector for menu item EX060215 (table 0xFFF8E1A0[238]) */

void ai_ex060215(void)

{
  ai_ex_preset_mod_source(2);
  return;
}


// ===== ai_ex060216 @ fffec18f (6 bytes)

/* AI change detector for menu item EX060216 (table 0xFFF8E1A0[239]) */

void ai_ex060216(void)

{
  ai_ex_preset_usb_mod_gain(2);
  return;
}


// ===== ai_ex060217 @ fffec195 (6 bytes)

/* AI change detector for menu item EX060217 (table 0xFFF8E1A0[240]) */

void ai_ex060217(void)

{
  ai_ex_preset_rear_mod_gain(2);
  return;
}


// ===== ai_ex060218 @ fffec19b (6 bytes)

/* AI change detector for menu item EX060218 (table 0xFFF8E1A0[241]) */

void ai_ex060218(void)

{
  ai_ex_preset_rptt_select(2);
  return;
}


// ===== ai_ex060301 @ fffec1a1 (6 bytes)

/* AI change detector for menu item EX060301 (table 0xFFF8E1A0[242]) */

void ai_ex060301(void)

{
  ai_ex_preset_name(3);
  return;
}


// ===== ai_ex060302 @ fffec1a7 (6 bytes)

/* AI change detector for menu item EX060302 (table 0xFFF8E1A0[243]) */

void ai_ex060302(void)

{
  ai_ex_preset_cat1_rate(3);
  return;
}


// ===== ai_ex060303 @ fffec1ad (6 bytes)

/* AI change detector for menu item EX060303 (table 0xFFF8E1A0[244]) */

void ai_ex060303(void)

{
  ai_ex_preset_cat1_tot(3);
  return;
}

