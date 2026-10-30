// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== dsp_status1_filter @ fffa0032 (270 bytes)

/* reg1: bit6 debounced over 5 polls -> 0x1C61; in RX (0x20B18==8) high byte averaged over 2 ->
   0x1C60 */

void dsp_status1_filter(void)

{
  ushort uVar1;
  char local_6;
  byte local_5;
  ushort local_4;
  
  uVar1 = DAT_0001b636;
  if (g_ui.trx_state == 8) {
    (&DAT_00001c64)[DAT_00001c66] = (char)(DAT_0001b636 >> 8);
    DAT_00001c66 = DAT_00001c66 + 1;
    if (1 < DAT_00001c66) {
      DAT_00001c66 = 0;
    }
    local_4 = 0;
    for (local_5 = 0; local_5 < 2; local_5 = local_5 + 1) {
      local_4 = (byte)(&DAT_00001c64)[local_5] + local_4;
    }
    DAT_00001c60 = (undefined1)(local_4 >> 1);
  }
  if ((uVar1 & 0x40) == 0) {
    (&DAT_00001c67)[DAT_00001c6c] = 0;
  }
  else {
    (&DAT_00001c67)[DAT_00001c6c] = 1;
  }
  DAT_00001c6c = DAT_00001c6c + 1;
  if (4 < DAT_00001c6c) {
    DAT_00001c6c = 0;
  }
  local_6 = '\0';
  for (local_5 = 0; local_5 < 5; local_5 = local_5 + 1) {
    local_6 = (&DAT_00001c67)[local_5] + local_6;
  }
  if (local_6 == '\x05') {
    DAT_00001c61 = 1;
    return;
  }
  if (local_6 == '\0') {
    DAT_00001c61 = 0;
    return;
  }
  return;
}


// ===== dsp_status2_filter @ fffa0140 (178 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa01bf) */
/* WARNING: Removing unreachable block (ram,0xfffa019f) */
/* WARNING: Removing unreachable block (ram,0xfffa01c7) */
/* WARNING: Removing unreachable block (ram,0xfffa01de) */
/* reg2: 32-sample average of each byte -> 0x1B6E2 */

void dsp_status2_filter(void)

{
  byte local_5;
  ushort local_4;
  ushort local_2;
  
  *(undefined2 *)(&DAT_0001b6e6 + (uint)DAT_00001c6d * 2) = DAT_0001b638;
  DAT_00001c6d = DAT_00001c6d + 1;
  if (0x1f < DAT_00001c6d) {
    DAT_00001c6d = 0;
  }
  local_4 = 0;
  local_2 = 0;
  for (local_5 = 0; local_5 < 0x20; local_5 = local_5 + 1) {
    local_2 = (*(ushort *)(&DAT_0001b6e6 + (uint)local_5 * 2) >> 8) + local_2;
    local_4 = (byte)(&DAT_0001b6e6)[(uint)local_5 * 2] + local_4;
  }
  DAT_0001b6e2 = local_2 / 0x20 << 8 | local_4 / 0x20;
  return;
}


// ===== dsp_status3_filter @ fffa01f2 (115 bytes)

/* reg3: 16-sample average of low byte -> 0x1C62 */

void dsp_status3_filter(void)

{
  byte local_3;
  ushort local_2;
  
  (&DAT_00001c6e)[DAT_00001c7e] = (char)DAT_0001b63a;
  DAT_00001c7e = DAT_00001c7e + 1;
  if (0xf < DAT_00001c7e) {
    DAT_00001c7e = 0;
  }
  local_2 = 0;
  for (local_3 = 0; local_3 < 0x10; local_3 = local_3 + 1) {
    local_2 = (byte)(&DAT_00001c6e)[local_3] + local_2;
  }
  DAT_00001c62 = (char)(local_2 >> 4);
  return;
}


// ===== dsp_status4_filter @ fffa0265 (277 bytes)

/* reg4: most frequent of last 8 samples -> 0x1B6E4 (100 if none repeats) */

void dsp_status4_filter(void)

{
  byte local_f [9];
  byte local_6;
  byte local_5;
  byte local_4;
  byte local_3;
  short local_2;
  
  local_3 = 8;
  local_f[1] = 0;
  local_f[2] = 0;
  local_f[3] = 0;
  local_f[4] = 0;
  local_f[5] = 0;
  local_f[6] = 0;
  local_f[7] = 0;
  local_f[0] = 0;
  *(undefined2 *)(&DAT_0001b726 + (uint)DAT_0001b3db * 2) = DAT_0001b63c;
  DAT_0001b3db = DAT_0001b3db + 1;
  if (7 < DAT_0001b3db) {
    DAT_0001b3db = 0;
  }
  for (local_4 = 0; local_4 < local_3; local_4 = local_4 + 1) {
    local_2 = *(short *)(&DAT_0001b726 + (uint)local_4 * 2);
    local_6 = 0;
    if (local_2 != 0x7fff) {
      for (local_5 = 0; local_5 < local_3; local_5 = local_5 + 1) {
        if (local_2 == *(short *)(&DAT_0001b726 + (uint)local_5 * 2)) {
          local_6 = local_6 + 1;
        }
      }
    }
    local_f[local_4] = local_6;
  }
  local_6 = 0;
  for (local_4 = 0; local_4 < local_3; local_4 = local_4 + 1) {
    for (local_5 = 0; local_5 < local_3; local_5 = local_5 + 1) {
      if (local_6 < local_f[local_5]) {
        local_6 = local_f[local_5];
        local_f[8] = local_5;
      }
    }
  }
  if (local_6 < 2) {
    local_2 = 100;
  }
  else {
    local_2 = *(short *)(&DAT_0001b726 + (uint)local_f[8] * 2);
  }
  DAT_0001b6e4 = local_2;
  return;
}


// ===== dsp_shadow_store @ fffa037a (1884 bytes)

/* Store 0x1B6E0 into the shadow of register 0x1B6DE (table 0x1B634..0x1B6DD); regs 1-4 also run
   their status filters */

void dsp_shadow_store(void)

{
  if (DAT_0001b6de == 0) {
    DAT_0001b634 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 1) {
    DAT_0001b636 = DAT_0001b6e0;
    dsp_status1_filter();
    return;
  }
  if (DAT_0001b6de == 2) {
    DAT_0001b638 = DAT_0001b6e0;
    dsp_status2_filter();
    return;
  }
  if (DAT_0001b6de == 3) {
    DAT_0001b63a = DAT_0001b6e0;
    dsp_status3_filter();
    return;
  }
  if (DAT_0001b6de == 4) {
    DAT_0001b63c = DAT_0001b6e0;
    dsp_status4_filter();
    return;
  }
  if (DAT_0001b6de == 0x4026) {
    DAT_0001b6dc = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 8) {
    DAT_0001b640 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 9) {
    DAT_0001b642 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 10) {
    DAT_0001b644 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xc) {
    DAT_0001b646 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xd) {
    DAT_0001b648 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xe) {
    DAT_0001b64a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0xf) {
    DAT_0001b64c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x10) {
    DAT_0001b64e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x11) {
    DAT_0001b650 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x12) {
    DAT_0001b652 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x13) {
    DAT_0001b654 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x20) {
    DAT_0001b656 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x21) {
    DAT_0001b658 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x22) {
    DAT_0001b65a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x25) {
    DAT_0001b65c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x26) {
    DAT_0001b662 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x27) {
    DAT_0001b668 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x28) {
    DAT_0001b65e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x29) {
    DAT_0001b664 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2a) {
    DAT_0001b66a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2b) {
    DAT_0001b660 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2c) {
    DAT_0001b666 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2d) {
    DAT_0001b66c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2e) {
    DAT_0001b66e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x2f) {
    DAT_0001b670 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x30) {
    DAT_0001b672 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x31) {
    DAT_0001b674 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x32) {
    DAT_0001b676 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x33) {
    DAT_0001b678 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x34) {
    DAT_0001b67a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x35) {
    DAT_0001b67c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x36) {
    DAT_0001b67e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x37) {
    DAT_0001b680 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x38) {
    DAT_0001b682 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x3a) {
    DAT_0001b684 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x3b) {
    DAT_0001b686 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x40) {
    DAT_0001b688 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x41) {
    DAT_0001b68a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x42) {
    DAT_0001b68c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x43) {
    DAT_0001b68e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x44) {
    DAT_0001b690 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x45) {
    DAT_0001b692 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x46) {
    DAT_0001b694 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x47) {
    DAT_0001b696 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x48) {
    DAT_0001b698 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x49) {
    DAT_0001b69e = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4a) {
    DAT_0001b6a4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4b) {
    DAT_0001b69a = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4c) {
    DAT_0001b6a0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4d) {
    DAT_0001b6a6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4e) {
    DAT_0001b69c = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4f) {
    DAT_0001b6a2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x50) {
    DAT_0001b6a8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x51) {
    DAT_0001b6aa = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x52) {
    DAT_0001b6ac = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x53) {
    DAT_0001b6ae = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x54) {
    DAT_0001b6b0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x55) {
    DAT_0001b6b2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x56) {
    DAT_0001b6b4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x57) {
    DAT_0001b6b6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x58) {
    DAT_0001b6b8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x5c) {
    DAT_0001b6ba = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x5d) {
    DAT_0001b6bc = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x60) {
    DAT_0001b6be = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x61) {
    DAT_0001b6c0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x62) {
    DAT_0001b6c2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 99) {
    DAT_0001b6c4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 100) {
    DAT_0001b6c6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x65) {
    DAT_0001b6c8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x66) {
    DAT_0001b6ca = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x67) {
    DAT_0001b6cc = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x68) {
    DAT_0001b6ce = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x400b) {
    DAT_0001b6d0 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x400d) {
    DAT_0001b6d2 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4020) {
    DAT_0001b6d4 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4022) {
    DAT_0001b6d6 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4023) {
    DAT_0001b6d8 = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de == 0x4025) {
    DAT_0001b6da = DAT_0001b6e0;
    return;
  }
  if (DAT_0001b6de != 6) {
    return;
  }
  dsp_demod_0001b63e = DAT_0001b6e0;
  return;
}


// ===== dsp_check_reply @ fffa0ad6 (118 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa0b49) */
/* Poll SCI4 reply: 'r'+4hex+2hex sum (read) or 0x06 (write ACK) -> 1; timer 3 expiry clears busy
   flags */

byte dsp_check_reply(char param_1,void *param_2)

{
  byte bVar1;
  uint uVar2;
  undefined1 local_e;
  
  local_e = 0;
  bVar1 = sci4_rx_ready();
  if (bVar1 == 1) {
    uVar2 = sci4_rx_buf();
    *(uint *)param_2 = uVar2;
    DAT_00001c5e = 0;
    DAT_00001c5f = 0;
    if (param_1 == 'r') {
      bVar1 = dsp_reply_sum_ok((int)*(char **)param_2,5);
      if (bVar1 == 1) {
        local_e = 1;
      }
    }
    else if (**(char **)param_2 == '\x06') {
      local_e = 1;
    }
  }
  else {
    bVar1 = swtimer_expired(3);
    if (bVar1 == 1) {
      DAT_00001c5e = 0;
      DAT_00001c5f = 0;
    }
  }
  return local_e;
}


// ===== dsp_send_frame @ fffa0b4c (181 bytes)

/* Build "rAAAACC\r" / "wAAAADDDDCC\r" from 0x1B6DE/0x1B6E0 into 0x1A5E, send on SCI4, start 6 ms
   reply timer 3, set busy flag 0x1C5F/0x1C5E */

void dsp_send_frame(char param_1)

{
  byte bVar1;
  byte local_2;
  
  DAT_00001a5e = param_1;
  word2hex(0x1a5f,DAT_0001b6de);
  local_2 = 5;
  if (param_1 == 'w') {
    word2hex(0x1a63,DAT_0001b6e0);
    local_2 = 9;
    DAT_00001c5e = 1;
  }
  else {
    DAT_00001c5f = 1;
  }
  bVar1 = dsp_sum8(0x1a5e,local_2);
  byte2hex(&DAT_00001a5e + local_2,bVar1);
  (&DAT_00001a5e)[(byte)(local_2 + 2)] = 0xd;
  sci4_send(0x1a5e,(ushort)(byte)(local_2 + 3));
  swtimer_start(3,6);
  return;
}


// ===== dsp_sum8 @ fffa0c01 (45 bytes)

/* 8-bit additive checksum over n bytes */

char dsp_sum8(int param_1,byte param_2)

{
  undefined1 local_8;
  undefined1 local_7;
  
  local_8 = '\0';
  for (local_7 = 0; local_7 < param_2; local_7 = local_7 + 1) {
    local_8 = *(char *)((uint)local_7 + param_1) + local_8;
  }
  return local_8;
}


// ===== dsp_reply_sum_ok @ fffa0c2e (75 bytes)

/* Checks the 2 hex checksum chars after n reply chars */

byte dsp_reply_sum_ok(int param_1,byte param_2)

{
  byte bVar1;
  char cStack_8;
  char cStack_7;
  byte local_5;
  int local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  bVar1 = dsp_sum8(param_1,param_2);
  byte2hex(&cStack_8,bVar1);
  if ((cStack_8 == *(char *)((uint)local_5 + local_4)) &&
     (cStack_7 == *(char *)(local_4 + (uint)local_5 + 1))) {
    bVar1 = 1;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}


// ===== dsp_isp_bridge @ fffa0c79 (449 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa0c79) */
/* WARNING: Removing unreachable block (ram,0xfffa0d7d) */
/* WARNING: Removing unreachable block (ram,0xfffa0da3) */
/* DSP firmware update: P71=0/P72=1 (ISP boot), ping 5A A6, then forward MCUBoot frames
   DISPLAY(SCI1) <-> DSP(SCI4) until DISPLAY sends F1 82; never returns to normal mode */

void dsp_isp_bridge(void)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  char acStack_40c [516];
  char acStack_208 [516];
  
  sci4_send(0x1a5e,0);
  DAT_00001c63 = 0;
  dsp_reset_set(0);
  dsp_update_set(1);
  swtimer_start(0x1e,100);
  do {
    bVar2 = swtimer_expired(0x1e);
  } while (bVar2 != 1);
  dsp_reset_set(1);
  swtimer_start(0x1e,100);
  do {
    bVar2 = swtimer_expired(0x1e);
  } while (bVar2 != 1);
  DAT_00001a5e = 0x5a;
  DAT_00001a5f = 0xa6;
  sci4_send(0x1a5e,2);
  swtimer_start(0x1e,0x32);
  do {
    bVar2 = swtimer_expired(0x1e);
  } while (bVar2 != 1);
  sci4_send(0x1a5e,0);
  do {
    bVar2 = sci1_tx_end();
  } while (bVar2 == 0);
  acStack_40c[0] = '\x06';
  displink_uart_send((uint)acStack_40c,1);
  do {
    wdt_kick();
    bVar2 = displink_rx_ready();
    if (bVar2 == 1) {
      pcVar5 = (char *)displink_rx_buf();
      pcVar6 = acStack_208;
      for (iVar7 = 0x204; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pcVar6 = *pcVar5;
        pcVar6 = pcVar6 + 1;
        pcVar5 = pcVar5 + 1;
      }
      displink_rx_rearm();
      if (acStack_208[0] != '\x06') {
        if ((acStack_208[0] == -0xf) && (acStack_208[1] == -0x7e)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          do {
            bVar2 = sci1_tx_end();
          } while (bVar2 == 0);
          acStack_40c[0] = '\x06';
          displink_uart_send((uint)acStack_40c,1);
          return;
        }
        if (acStack_208[0] == 'Z') {
          do {
            bVar2 = sci1_tx_end();
          } while (bVar2 == 0);
          acStack_40c[0] = '\x06';
          displink_uart_send((uint)acStack_40c,1);
          pcVar6 = acStack_208 + 3;
          pcVar5 = &DAT_00001a5e;
          for (uVar8 = (uint)CONCAT11(acStack_208[2],acStack_208[1]); uVar8 != 0; uVar8 = uVar8 - 1)
          {
            *pcVar5 = *pcVar6;
            pcVar5 = pcVar5 + 1;
            pcVar6 = pcVar6 + 1;
          }
          sci4_send(0x1a5e,CONCAT11(acStack_208[2],acStack_208[1]));
        }
      }
    }
    bVar2 = sci4_rx_ready();
    if (bVar2 == 1) {
      pcVar5 = (char *)sci4_rx_buf();
      uVar4 = sci4_rx_len();
      do {
        bVar2 = sci1_tx_end();
      } while (bVar2 == 0);
      acStack_40c[0] = 'Z';
      acStack_40c[1] = (char)uVar4;
      acStack_40c[2] = (char)(uVar4 >> 8);
      pcVar6 = acStack_40c + 3;
      for (uVar8 = (uint)uVar4; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar6 = *pcVar5;
        pcVar6 = pcVar6 + 1;
        pcVar5 = pcVar5 + 1;
      }
      cVar3 = dsp_sum8((int)acStack_40c,(byte)(uVar4 + 3));
      acStack_40c[(ushort)(uVar4 + 3)] = cVar3;
      displink_uart_send((uint)acStack_40c,uVar4 + 4);
      sci4_send(0x1a5e,0);
    }
  } while( true );
}


// ===== dsp_route_param @ fffa0e3a (760 bytes)

/* Per-audio-route constants for regs 8, 9, 10, 0x0D/0x0E, 0x20 and EQ enable 0x25/0x28/0x2B; sets
   0x20B49 */

ushort dsp_route_param(ushort param_1)

{
  uint uVar1;
  uint uVar2;
  ushort uStack_a;
  
  uVar2 = audio_route_state();
  uStack_a = 0;
  switch(uVar2) {
  case 0:
    if (param_1 == 0x20) {
      uStack_a = 0xffff;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x52;
    }
    else if (param_1 == 8) {
      uStack_a = g_ui.dsp_route_word;
    }
    break;
  case 1:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x50;
    }
    else if (param_1 == 8) {
      uStack_a = g_ui.dsp_route_word;
    }
    break;
  case 2:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x52;
    }
    else if (param_1 == 8) {
      uStack_a = g_ui.dsp_route_word;
    }
    break;
  case 3:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 2;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 4:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 2;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 5:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 3;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 6:
    uVar1 = (uint)param_1;
    if (uVar1 == 0x20) {
      uStack_a = 0;
    }
    else if (uVar1 == 9) {
      uStack_a = 0;
    }
    else if (uVar1 == 10) {
      uStack_a = 0x22;
    }
    else if (uVar1 - 0xd < 2) {
      uStack_a = 0xf000;
    }
    else if (uVar1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 7:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x22;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 8:
    if (param_1 == 0x20) {
      uStack_a = 0xffff;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x52;
    }
    else if (param_1 == 8) {
      uStack_a = g_ui.dsp_route_word;
    }
    break;
  case 9:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x50;
    }
    else if (param_1 == 8) {
      uStack_a = g_ui.dsp_route_word;
    }
    break;
  case 10:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 0x22;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 0xb:
  case 0xc:
    if (param_1 == 0x20) {
      uStack_a = 0;
    }
    else if (param_1 == 9) {
      uStack_a = 0;
    }
    else if (param_1 == 10) {
      uStack_a = 3;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2022;
    }
    break;
  case 0xd:
    if (param_1 == 0x20) {
      uStack_a = 0xffff;
    }
    else if (param_1 == 9) {
      uStack_a = 2;
    }
    else if (param_1 == 10) {
      uStack_a = 0x22;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2222;
    }
    break;
  case 0xe:
    if (param_1 == 0x20) {
      uStack_a = 0xfffe;
    }
    else if (param_1 == 9) {
      uStack_a = 2;
    }
    else if (param_1 == 10) {
      uStack_a = 3;
    }
    else if (param_1 == 8) {
      uStack_a = 0x2222;
    }
  }
  if (((param_1 == 0x25) || (param_1 == 0x28)) || (param_1 == 0x2b)) {
    if ((int)uVar2 < 8) {
      uStack_a = 0;
    }
    else {
      uStack_a = 0xffff;
    }
  }
  if (param_1 == 0x20) {
    g_ui.dsp_route_ready = 1;
  }
  return uStack_a;
}


// ===== sdr_init @ fffa1132 (187 bytes)

/* Boot (app_main): SDR_RESET P77=1, wait 1000 ms, clear shadows, read regs 0 and 1 (fail ->
   0x20B36=3), build SDR version 'Vxx-yy' from reg 0 into 0x144A (VE P1=2) */

void sdr_init(void)

{
  byte bVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  local_7 = 0x56;
  local_6 = 0x2a;
  local_5 = 0x2a;
  local_4 = 0x2d;
  local_3 = 0x2a;
  local_2 = 0x2a;
  local_1 = 0;
  sdr_reset_set('\x01');
  swtimer_start(0x1f,1000);
  do {
    bVar1 = swtimer_expired(0x1f);
  } while (bVar1 != 1);
  puVar2 = &DAT_0001b736;
  for (iVar3 = 0x4e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar2 = 0xff;
    puVar2 = (undefined2 *)((int)puVar2 + 1);
  }
  DAT_00001c8b = 0;
  DAT_00001c8d = 0;
  sdr_req_reg0();
  bVar1 = sdr_wait_reply('r','\0');
  if (bVar1 != 1) {
    g_ui.boot_error = 3;
    return;
  }
  sdr_req_reg1();
  bVar1 = sdr_wait_reply('r','\0');
  if (bVar1 != 1) {
    g_ui.boot_error = 3;
    return;
  }
  word2hex((int)&uStack_b,DAT_0001b736);
  local_6 = uStack_b;
  local_5 = uStack_a;
  local_3 = uStack_9;
  local_2 = uStack_8;
  FUN_fff94c57(&local_7);
  return;
}


// ===== sdr_task @ fffa11ed (664 bytes)

/* Main-loop SDR task: completes a pending write, runs sdr_bridge_mode on request, waits for TX/RX
   line changes, then calls the per-register updaters in order until one sends a frame (one write
   per pass) */

void sdr_task(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 auStack_8 [6];
  byte local_2;
  byte local_1;
  
  local_1 = g_ui.transmitting;
  local_2 = g_ui.trx_state;
  if (DAT_00001c8b == '\x01') {
    bVar2 = sdr_poll_reply('w',auStack_8);
    if (bVar2 != 1) {
      return;
    }
    sdr_shadow_update();
  }
  if (DAT_00001c8d == '\x01') {
    sdr_bridge_mode();
  }
  if (DAT_0001b3dd != local_1) {
    if ((local_1 == 1) && (bVar2 = rx_line_get(), bVar2 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    if ((local_1 == 0) && (bVar2 = tx_line_get(), bVar2 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    DAT_0001b3dd = local_1;
  }
  sdr_upd_r0a_demod(local_1);
  if (((((((((DAT_00001c8b == '\0') && (sdr_upd_r0b_band(local_1), DAT_00001c8b == '\0')) &&
           (sdr_upd_r0c_rtty_shift(), DAT_00001c8b == '\0')) &&
          ((sdr_upd_r0d(), DAT_00001c8b == '\0' && (sdr_upd_r0f_band(local_1), DAT_00001c8b == '\0')
           ))) && (sdr_upd_r20_scope_freq(local_1), DAT_00001c8b == '\0')) &&
        (((sdr_upd_r22_scope_span(local_1), DAT_00001c8b == '\0' &&
          (sdr_upd_r23(), DAT_00001c8b == '\0')) &&
         ((sdr_upd_r25_tx_drive(local_1), DAT_00001c8b == '\0' &&
          (((sdr_upd_r26(local_1), DAT_00001c8b == '\0' &&
            (sdr_upd_r27_scope_level(local_1), DAT_00001c8b == '\0')) &&
           (sdr_upd_r03(), DAT_00001c8b == '\0')))))))) &&
       ((sdr_upd_r08_tx_freq(), DAT_00001c8b == '\0' && (sdr_upd_r0e(), DAT_00001c8b == '\0')))) &&
      (sdr_upd_r14_mode(), DAT_00001c8b == '\0')) &&
     ((local_1 != 0 ||
      ((((sdr_upd_r04(), DAT_00001c8b == '\0' && (sdr_upd_r12(), DAT_00001c8b == '\0')) &&
        ((sdr_upd_r13(), DAT_00001c8b == '\0' &&
         (((sdr_upd_r16_filter(), DAT_00001c8b == '\0' &&
           (sdr_upd_r18_rx_freq(), DAT_00001c8b == '\0')) &&
          (sdr_upd_r1a_nb_level(), DAT_00001c8b == '\0')))))) &&
       (((sdr_upd_r1b(), DAT_00001c8b == '\0' && (sdr_upd_r1c(), DAT_00001c8b == '\0')) &&
        ((sdr_upd_r1d_notch(), DAT_00001c8b == '\0' &&
         ((sdr_upd_r1e_passband(), DAT_00001c8b == '\0' &&
          (sdr_upd_r1f_width(), DAT_00001c8b == '\0')))))))))))) {
    if (DAT_0001b3dc == '\0') {
      sdr_init_r15();
      if (DAT_00001c8b != '\0') {
        return;
      }
      sdr_init_r24();
      if (DAT_00001c8b != '\0') {
        return;
      }
      DAT_0001b3dc = '\x01';
    }
    if ((local_2 == 1) || (local_2 == 7)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      g_ui.tx_ack_sdr = 1;
      return;
    }
  }
  return;
}


// ===== sdr_reg_access @ fffa1485 (135 bytes)

/* SDR register r/w over SCI5 ('r'/'w' + hex addr [+ value] + sum + CR, waits for reply) */

byte sdr_reg_access(ushort param_1,void *param_2,char param_3)

{
  bool bVar1;
  byte bVar2;
  byte local_b;
  
  local_b = 0;
  while( true ) {
    if ((DAT_00001c8b == '\x01') || (DAT_00001c8c == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) break;
    sdr_task();
  }
  DAT_0001b784 = param_1;
  if (param_3 == '\0') {
    sdr_send_frame('r');
    bVar2 = sdr_wait_reply('r','\x01');
    if (bVar2 == 1) {
      *(undefined2 *)param_2 = DAT_0001b782;
      local_b = 1;
    }
  }
  else {
    DAT_0001b786 = *(undefined2 *)param_2;
    sdr_send_frame('w');
    local_b = sdr_wait_reply('w','\x01');
  }
  return local_b;
}


// ===== scope_level_ptr @ fffa150c (53 bytes)

/* Returns the pointer to the scope reference-level byte for a frequency and VFO side
   (FUN_fffb3480); used by SS sel 4 and SDR reg 0x27 [inference] */

uint scope_level_ptr(uint param_1,byte param_2)

{
  byte bVar1;
  undefined *puStack_14;
  
  bVar1 = freq_range_index(param_1);
  if (param_2 == 0) {
    puStack_14 = (&PTR_g_opstate_scope_level_rx_0__fff88648)[bVar1];
  }
  else {
    puStack_14 = (&PTR_g_opstate_scope_level_tx_0__fff88680)[bVar1];
  }
  return (uint)puStack_14;
}


// ===== scope_span_ptr @ fffa1541 (53 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa155b) */
/* Returns the pointer to the scope span index for a frequency (FUN_fffb3480); used by SS sel 5 and
   SDR reg 0x20/0x21 [inference] */

uint scope_span_ptr(uint param_1)

{
  byte bVar1;
  byte bVar2;
  undefined *puStack_10;
  
  bVar1 = g_opstate.scope_mode;
  bVar2 = freq_range_index(param_1);
  if (bVar1 == 2) {
    puStack_10 = (&PTR_g_opstate_scope_span_idx_b_0__fff885b0)[(uint)bVar2 * 2];
  }
  else {
    puStack_10 = (&PTR_g_opstate_scope_span_idx_a_0__fff885ac)[(uint)bVar2 * 2];
  }
  return (uint)puStack_10;
}


// ===== sdr_bridge_request @ fffa1576 (10 bytes)

/* DISPLAY-link sub-command 1: sets 0x1C8D so sdr_task enters sdr_bridge_mode */

void sdr_bridge_request(void)

{
  DAT_00001c8d = 1;
  return;
}


// ===== sdr_req_reg0 @ fffa1580 (16 bytes)

/* Sends a read of SDR register 0 (version) */

void sdr_req_reg0(void)

{
  DAT_0001b784 = 0;
  sdr_send_frame('r');
  return;
}


// ===== sdr_req_reg1 @ fffa1590 (16 bytes)

/* Sends a read of SDR register 1 */

void sdr_req_reg1(void)

{
  DAT_0001b784 = 1;
  sdr_send_frame('r');
  return;
}


// ===== sdr_upd_r03 @ fffa15a0 (83 bytes)

/* Reg 0x03 = 0xE63D if TX-side frequency <= 62.5 MHz else 0xE61D */

void sdr_upd_r03(void)

{
  uint uVar1;
  undefined2 uStack_6;
  
  uVar1 = vfo_freq(1,2);
  if (uVar1 < 0x3b9aca1) {
    uStack_6 = -0x19c3;
  }
  else {
    uStack_6 = -0x19e3;
  }
  if (DAT_0001b73a == uStack_6) {
    return;
  }
  DAT_0001b784 = 3;
  DAT_0001b786 = uStack_6;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r04 @ fffa15f3 (57 bytes)

/* Reg 0x04 = 0xE519 (constant; RX only) */

void sdr_upd_r04(void)

{
  vfo_rec_ptr(0);
  if (DAT_0001b73c == -0x1ae7) {
    return;
  }
  DAT_0001b784 = 4;
  DAT_0001b786 = 0xe519;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r08_tx_freq @ fffa162c (268 bytes)

/* Regs 0x08/0x09 = 32-bit operating frequency 0x20F50 in Hz, with PSK tone / CW pitch offsets
   [inference: TX NCO] */

void sdr_upd_r08_tx_freq(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uStack_6;
  undefined4 uStack_4;
  
  bVar1 = vfo_mode(1);
  uStack_4 = g_ui.freq_tx;
  if (bVar1 == 0xe) {
    if (g_opstate.ex010419_psk_tone == 1) {
      uStack_6 = 0x5dc;
    }
    else if (g_opstate.ex010419_psk_tone == 2) {
      uStack_6 = 2000;
    }
    else {
      uStack_6 = 1000;
    }
    uStack_4 = g_ui.freq_tx - uStack_6;
  }
  else {
    bVar2 = tx_cw_keying_class();
    if (bVar2 == 3) {
      uVar3 = (ushort)g_opstate.cw_pitch * 10 + 300;
      if (bVar1 == 0) {
        uStack_4 = uStack_4 - uVar3;
      }
      else if (bVar1 == 1) {
        uStack_4 = uStack_4 + uVar3;
      }
      DAT_0001b3de = '\x01';
    }
    else if (DAT_0001b3de == '\x01') {
      bVar1 = tx_line_get();
      if (bVar1 == 1) {
        return;
      }
      DAT_0001b3de = '\0';
    }
  }
  if (uStack_4._2_2_ == DAT_0001b73e) {
    if ((uStack_4 & 0xffff) == (uint)DAT_0001b740) {
      return;
    }
    DAT_0001b784 = 9;
    DAT_0001b786 = (undefined2)uStack_4;
    sdr_send_frame('w');
    return;
  }
  DAT_0001b784 = 8;
  DAT_0001b786 = uStack_4._2_2_;
  sdr_send_frame('w');
  DAT_0001b740 = 0xffff;
  return;
}


// ===== sdr_upd_r0a_demod @ fffa1738 (164 bytes)

/* Reg 0x0A = mode class 0..5 (CW, AM, FM, LSB-side, USB-side, RTTY) of the RX/TX VFO; only while
   0x1204D != 0 */

void sdr_upd_r0a_demod(byte param_1)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  sdr_mod_class sStack_4;
  
  bVar2 = vfo_mode(param_1);
  bVar3 = ptt_source_get();
  if (bVar3 == 0) {
    return;
  }
  uVar1 = (uint)bVar2;
  if (uVar1 == 0) {
LAB_fffa1791:
    sStack_4 = SDR_MOD_LSB;
    bVar2 = tx_cw_keying_class();
    if (bVar2 == 3) {
      sStack_4 = SDR_MOD_CW;
    }
  }
  else {
    if ((uVar1 == 1) || (uVar1 == 0xe)) {
LAB_fffa17a1:
      sStack_4 = SDR_MOD_USB;
      bVar2 = tx_cw_keying_class();
      if (bVar2 == 3) {
        sStack_4 = SDR_MOD_CW;
      }
      goto LAB_fffa17b2;
    }
    if (uVar1 - 4 < 2) {
      sStack_4 = SDR_MOD_AM;
      goto LAB_fffa17b2;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 == 8) goto LAB_fffa1791;
      if (uVar1 == 9) goto LAB_fffa17a1;
      if (1 < uVar1 - 10) {
        if (uVar1 == 2 || uVar1 == 3) {
          sStack_4 = SDR_MOD_CW;
        }
        else {
          sStack_4 = SDR_MOD_RTTY;
        }
        goto LAB_fffa17b2;
      }
    }
    sStack_4 = SDR_MOD_FM;
  }
LAB_fffa17b2:
  if (sdr_mod_class_0001b742 == sStack_4) {
    return;
  }
  DAT_0001b784 = 10;
  DAT_0001b786 = sStack_4;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r0b_band @ fffa17dc (97 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa17fc) */
/* Reg 0x0B = per-band word from 0xFFF87FFA (RX) / 0xFFF87FFE (TX), 8-byte rows */

void sdr_upd_r0b_band(char param_1)

{
  byte bVar1;
  uint freq;
  short sStack_a;
  
  vfo_mode(param_1);
  freq = vfo_freq(param_1,2);
  bVar1 = gen_subband_of_freq(freq);
  if (param_1 == '\0') {
    sStack_a = *(short *)(BYTE_ARRAY_fff87ffa + (uint)bVar1 * 8);
  }
  else {
    sStack_a = *(short *)(BYTE_ARRAY_fff87ffa + (uint)bVar1 * 8 + 4);
  }
  if (DAT_0001b744 != sStack_a) {
    DAT_0001b784 = 0xb;
    DAT_0001b786 = sStack_a;
    sdr_send_frame('w');
    return;
  }
  return;
}


// ===== sdr_upd_r0c_rtty_shift @ fffa183d (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa1872) */
/* WARNING: Removing unreachable block (ram,0xfffa187a) */
/* Reg 0x0C = (RTTY shift 170/200/425/850 Hz from 0x9A8D)/5 << 8 | 3 */

void sdr_upd_r0c_rtty_shift(void)

{
  ushort uVar1;
  undefined2 local_2;
  
  if (g_opstate.ex010516_shift_frequency == 1) {
    local_2 = 200;
  }
  else if (g_opstate.ex010516_shift_frequency == 2) {
    local_2 = 0x1a9;
  }
  else if (g_opstate.ex010516_shift_frequency == 3) {
    local_2 = 0x352;
  }
  else {
    local_2 = 0xaa;
  }
  uVar1 = local_2 / 5 << 8 | 3;
  if (DAT_0001b746 == uVar1) {
    return;
  }
  DAT_0001b784 = 0xc;
  DAT_0001b786 = uVar1;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r0d @ fffa18ae (74 bytes)

/* Reg 0x0D = 9/14/19 from setting 0x9AA1 (0..2) [meaning unknown] */

void sdr_upd_r0d(void)

{
  undefined2 local_2;
  
  if (g_opstate.ex020117_cw_wave_shape == 1) {
    local_2 = 0xe;
  }
  else if (g_opstate.ex020117_cw_wave_shape == 0) {
    local_2 = 9;
  }
  else {
    local_2 = 0x13;
  }
  if (DAT_0001b748 == local_2) {
    return;
  }
  DAT_0001b784 = 0xd;
  DAT_0001b786 = local_2;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r0e @ fffa18f8 (49 bytes)

/* Reg 0x0E = 0x1200 (constant) */

void sdr_upd_r0e(void)

{
  if (DAT_0001b74a == 0x1200) {
    return;
  }
  DAT_0001b784 = 0xe;
  DAT_0001b786 = 0x1200;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r0f_band @ fffa1929 (131 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa196a) */
/* Reg 0x0F = per-band word 0xFFF87FFC/0xFFF88000, 0 when ADC 0x20B14 >= 0xE8B, unchanged between
   0x9B3..0xE8A */

void sdr_upd_r0f_band(char param_1)

{
  byte bVar1;
  uint freq;
  short sStack_a;
  
  vfo_mode(param_1);
  if (g_ui.adc_sdr_det < 0xe8b) {
    if (0x9b2 < g_ui.adc_sdr_det) {
      return;
    }
    freq = vfo_freq(param_1,2);
    bVar1 = gen_subband_of_freq(freq);
    if (param_1 == '\0') {
      sStack_a = *(short *)(BYTE_ARRAY_fff87ffa + (uint)bVar1 * 8 + 2);
    }
    else {
      sStack_a = *(short *)(BYTE_ARRAY_fff87ffa + (uint)bVar1 * 8 + 6);
    }
  }
  else {
    sStack_a = 0;
  }
  if (DAT_0001b74c == sStack_a) {
    return;
  }
  DAT_0001b784 = 0xf;
  DAT_0001b786 = sStack_a;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r12 @ fffa19ac (49 bytes)

/* Reg 0x12 = 0x8000 (constant; RX only) */

void sdr_upd_r12(void)

{
  if (DAT_0001b74e == -0x8000) {
    return;
  }
  DAT_0001b784 = 0x12;
  DAT_0001b786 = 0x8000;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r13 @ fffa19dd (49 bytes)

/* Reg 0x13 = 0x8000 (constant; RX only) */

void sdr_upd_r13(void)

{
  if (DAT_0001b750 == -0x8000) {
    return;
  }
  DAT_0001b784 = 0x13;
  DAT_0001b786 = 0x8000;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r14_mode @ fffa1a0e (124 bytes)

/* Reg 0x14 = 0x2000/0x3200 (AM)/0x7800 (FM, DATA-FM)/0x3C00 (FM-N, DATA-FM-N) by TX-side mode */

void sdr_upd_r14_mode(void)

{
  byte bVar1;
  short sStack_2;
  
  bVar1 = vfo_mode(1);
  switch(bVar1) {
  case 2:
  case 3:
    sStack_2 = 0x2000;
    break;
  case 4:
  case 5:
    sStack_2 = 0x3200;
    break;
  case 6:
  case 10:
    sStack_2 = 0x7800;
    break;
  case 7:
  case 0xb:
    sStack_2 = 0x3c00;
    break;
  case 8:
  case 9:
    sStack_2 = 0x2000;
    break;
  case 0xc:
  case 0xd:
    sStack_2 = 0x2000;
    break;
  case 0xe:
    sStack_2 = 0x2000;
    break;
  default:
    sStack_2 = 0x2000;
  }
  if (DAT_0001b752 != sStack_2) {
    DAT_0001b784 = 0x14;
    DAT_0001b786 = sStack_2;
    sdr_send_frame('w');
    return;
  }
  return;
}


// ===== sdr_init_r15 @ fffa1a8a (49 bytes)

/* Reg 0x15 = 0x2000, sent once after the first full sync */

void sdr_init_r15(void)

{
  if (DAT_0001b754 == 0x2000) {
    return;
  }
  DAT_0001b784 = 0x15;
  DAT_0001b786 = 0x2000;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r16_filter @ fffa1abb (430 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa1ae7) */
/* Reg 0x16 = filter class by mode and width (CW 0..2, SSB/data 0x10..0x12, AM 0x20/0x21, FM
   0x30/0x31); also sets 0x20B4A */

void sdr_upd_r16_filter(void)

{
  bool bVar1;
  uint uVar2;
  ushort uVar3;
  char *pcVar4;
  undefined1 uStack_7;
  undefined1 uStack_6;
  byte bStack_5;
  short sStack_2;
  
  bStack_5 = vfo_mode(0);
  pcVar4 = (char *)aess_level_ptr();
  bVar1 = *pcVar4 == '\0';
  vfo_filter_width_hz(&uStack_7);
  uVar3 = CONCAT11(uStack_7,uStack_6);
  uVar2 = (uint)bStack_5;
  if (1 < uVar2 - 10) {
    if (uVar2 == 4) {
      sStack_2 = 0x21;
      g_ui.rx_unmute_delay_ms = 0x1e;
      goto LAB_fffa1c3f;
    }
    if (uVar2 == 5) {
      sStack_2 = 0x20;
      g_ui.rx_unmute_delay_ms = 0x1e;
      goto LAB_fffa1c3f;
    }
    if (uVar2 != 6) {
      if (uVar2 == 7) {
        sStack_2 = 0x30;
        g_ui.rx_unmute_delay_ms = 0x1e;
      }
      else if (uVar2 == 2 || uVar2 == 3) {
        if (uVar3 < 0xfb) {
          sStack_2 = 0;
          if (bVar1) {
            g_ui.rx_unmute_delay_ms = 0x4a;
          }
          else {
            g_ui.rx_unmute_delay_ms = 0x54;
          }
        }
        else if (uVar3 < 800) {
          sStack_2 = 1;
          if (bVar1) {
            g_ui.rx_unmute_delay_ms = 0x27;
          }
          else {
            g_ui.rx_unmute_delay_ms = 0x31;
          }
        }
        else {
          sStack_2 = 2;
          if (bVar1) {
            g_ui.rx_unmute_delay_ms = 0x17;
          }
          else {
            g_ui.rx_unmute_delay_ms = 0x21;
          }
        }
      }
      else if (uVar3 < 0x44d) {
        sStack_2 = 0x10;
        if (bVar1) {
          g_ui.rx_unmute_delay_ms = 0x1f;
        }
        else {
          g_ui.rx_unmute_delay_ms = 0x29;
        }
      }
      else if (uVar3 < 2000) {
        sStack_2 = 0x11;
        if (bVar1) {
          g_ui.rx_unmute_delay_ms = 0x17;
        }
        else {
          g_ui.rx_unmute_delay_ms = 0x21;
        }
      }
      else {
        sStack_2 = 0x12;
        if (bVar1) {
          g_ui.rx_unmute_delay_ms = 0x15;
        }
        else {
          g_ui.rx_unmute_delay_ms = 0x1f;
        }
      }
      goto LAB_fffa1c3f;
    }
  }
  sStack_2 = 0x31;
  g_ui.rx_unmute_delay_ms = 0x1e;
LAB_fffa1c3f:
  if (DAT_0001b756 == sStack_2) {
    return;
  }
  DAT_0001b784 = 0x16;
  DAT_0001b786 = sStack_2;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r18_rx_freq @ fffa1c69 (872 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa1e6a) */
/* WARNING: Removing unreachable block (ram,0xfffa1ed4) */
/* WARNING: Removing unreachable block (ram,0xfffa1f47) */
/* WARNING: Removing unreachable block (ram,0xfffa1c97) */
/* WARNING: Removing unreachable block (ram,0xfffa1cdf) */
/* WARNING: Removing unreachable block (ram,0xfffa1d55) */
/* WARNING: Removing unreachable block (ram,0xfffa1dcd) */
/* WARNING: Removing unreachable block (ram,0xfffa1de8) */
/* Regs 0x18/0x19 = 32-bit RX VFO frequency in Hz plus the mode offset (SSB 1500 Hz + shift, CW
   pitch, RTTY mark/shift, DATA offset, PSK) [inference: RX NCO] */

void sdr_upd_r18_rx_freq(void)

{
  uint uVar1;
  bool bVar2;
  short sVar3;
  undefined1 uStack_16;
  undefined1 uStack_15;
  byte bStack_14;
  byte bStack_13;
  short sStack_12;
  short sStack_10;
  ushort uStack_e;
  ushort uStack_a;
  undefined4 uStack_8;
  byte *pbStack_4;
  
  pbStack_4 = vfo_rec_ptr(0);
  bStack_14 = vfo_mode(0);
  uStack_a = 0;
  uStack_8 = vfo_freq_clar(0,2);
  sStack_10 = CONCAT11(g_opstate.ex010420_data_shift_ssb_be[0],
                       g_opstate.ex010420_data_shift_ssb_be[1]);
  uVar1 = (uint)bStack_14;
  if (uVar1 == 0xe) {
    uStack_a = CONCAT11(pbStack_4[0x30],pbStack_4[0x31]);
    if ((pbStack_4[0x30] & 0x80) == 0) {
      uStack_8 = uStack_a + uStack_8;
    }
    else {
      uStack_a = ~uStack_a + 1;
      uStack_8 = uStack_8 - uStack_a;
    }
  }
  else if (uVar1 - 2 < 2) {
    uStack_a = CONCAT11(pbStack_4[0x1c],pbStack_4[0x1d]);
    vfo_filter_width_hz(&uStack_16);
    uStack_e = (ushort)g_opstate.cw_pitch * 10 + 300;
    if (CONCAT11(uStack_16,uStack_15) < uStack_e) {
      bVar2 = (uStack_a & 0x8000) != 0;
      if (bStack_14 == 2) {
        if (bVar2) {
          uStack_a = ~uStack_a + 1;
          uStack_8 = uStack_8 + uStack_a;
        }
        else {
          uStack_8 = uStack_8 - uStack_a;
        }
      }
      else if (bVar2) {
        uStack_a = ~uStack_a + 1;
        uStack_8 = uStack_8 - uStack_a;
      }
      else {
        uStack_8 = uStack_8 + uStack_a;
      }
    }
    else {
      uStack_a = (short)((int)((uint)CONCAT11(uStack_16,uStack_15) - (uint)uStack_e) / 2) + uStack_a
      ;
      bVar2 = (uStack_a & 0x8000) != 0;
      if (bStack_14 == 2) {
        if (bVar2) {
          uStack_a = ~uStack_a + 1;
          uStack_8 = uStack_8 + uStack_a;
        }
        else {
          uStack_8 = uStack_8 - uStack_a;
        }
      }
      else if (bVar2) {
        uStack_a = ~uStack_a + 1;
        uStack_8 = uStack_8 - uStack_a;
      }
      else {
        uStack_8 = uStack_8 + uStack_a;
      }
    }
  }
  else if (uVar1 - 8 < 2) {
    uStack_a = sStack_10 * 10 + CONCAT11(pbStack_4[0x30],pbStack_4[0x31]);
    bVar2 = (uStack_a & 0x8000) != 0;
    if (bStack_14 == 8) {
      if (bVar2) {
        uStack_a = ~uStack_a + 1;
        uStack_8 = uStack_8 + uStack_a;
      }
      else {
        uStack_8 = uStack_8 - uStack_a;
      }
    }
    else if (bVar2) {
      uStack_a = ~uStack_a + 1;
      uStack_8 = uStack_8 - uStack_a;
    }
    else {
      uStack_8 = uStack_8 + uStack_a;
    }
  }
  else if (uVar1 - 0xc < 2) {
    sVar3 = CONCAT11(pbStack_4[0x26],pbStack_4[0x27]);
    bStack_13 = g_opstate.ex010516_shift_frequency;
    if (g_opstate.ex010516_shift_frequency == 1) {
      sStack_12 = 0x69;
    }
    else if (g_opstate.ex010516_shift_frequency == 2) {
      sStack_12 = 0xd7;
    }
    else if (g_opstate.ex010516_shift_frequency == 3) {
      sStack_12 = 0x1a9;
    }
    else {
      sStack_12 = 0x55;
    }
    if (bStack_14 != 0xc) {
      sVar3 = -sVar3;
    }
    uStack_a = sStack_12 + sVar3;
    if ((uStack_a & 0x8000) == 0) {
      uStack_8 = uStack_8 - uStack_a;
    }
    else {
      uStack_a = ~uStack_a + 1;
      uStack_8 = uStack_8 + uStack_a;
    }
  }
  else if (uVar1 < 2) {
    uStack_a = CONCAT11(pbStack_4[0x12],pbStack_4[0x13]) + 0x5dc;
    bVar2 = (uStack_a & 0x8000) != 0;
    if (bStack_14 == 0) {
      if (bVar2) {
        uStack_a = ~uStack_a + 1;
        uStack_8 = uStack_8 + uStack_a;
      }
      else {
        uStack_8 = uStack_8 - uStack_a;
      }
    }
    else if (bVar2) {
      uStack_a = ~uStack_a + 1;
      uStack_8 = uStack_8 - uStack_a;
    }
    else {
      uStack_8 = uStack_8 + uStack_a;
    }
  }
  if (uStack_8._2_2_ != DAT_0001b758) {
    DAT_0001b784 = 0x18;
    DAT_0001b786 = uStack_8._2_2_;
    sdr_send_frame('w');
    DAT_0001b75a = 0xffff;
    return;
  }
  if ((uStack_8 & 0xffff) != (uint)DAT_0001b75a) {
    DAT_0001b784 = 0x19;
    DAT_0001b786 = (undefined2)uStack_8;
    sdr_send_frame('w');
    return;
  }
  return;
}


// ===== sdr_upd_r1a_nb_level @ fffa1fd1 (120 bytes)

/* Reg 0x1A = NB level (NL 0x9DC0) mapped through 0xFFF8808A (AM) / 0xFFF880A0, 0 when NB is off */

void sdr_upd_r1a_nb_level(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  short sStack_6;
  
  pbVar3 = vfo_rec_ptr(0);
  bVar1 = g_opstate.nb_level;
  if ((pbVar3[2] & 2) == 0) {
    sStack_6 = 0;
  }
  else {
    bVar2 = vfo_mode(0);
    if (bVar2 == 4 || bVar2 == 5) {
      sStack_6 = *(short *)(BYTE_ARRAY_fff87ffa + (uint)bVar1 * 2 + 0x90);
    }
    else {
      sStack_6 = *(short *)(BYTE_ARRAY_fff87ffa + (uint)bVar1 * 2 + 0xa6);
    }
  }
  if (DAT_0001b75c == sStack_6) {
    return;
  }
  DAT_0001b784 = 0x1a;
  DAT_0001b786 = sStack_6;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r1b @ fffa2049 (102 bytes)

/* Reg 0x1B = table 0xFFF880B6 (AM) / 0xFFF880BC indexed by NB WIDTH 0x9AD3 (EX030203) [fact]; NB
   width parameter [inference: only input] */

void sdr_upd_r1b(void)

{
  byte bVar1;
  byte bVar2;
  short sStack_2;
  
  vfo_mode(0);
  bVar1 = g_opstate.ex030203_nb_width;
  bVar2 = vfo_mode(0);
  if (bVar2 == 4 || bVar2 == 5) {
    sStack_2 = *(short *)(BYTE_ARRAY_fff87ffa + (uint)bVar1 * 2 + 0xbc);
  }
  else {
    sStack_2 = *(short *)((int)&PTR_DAT_fff880bc + (uint)bVar1 * 2);
  }
  if (DAT_0001b75e == sStack_2) {
    return;
  }
  DAT_0001b784 = 0x1b;
  DAT_0001b786 = sStack_2;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r1c @ fffa20af (72 bytes)

/* Reg 0x1C = 2/5/10 from NB REJECTION 0x9AD2 (EX030202) [fact]; NB rejection parameter [inference:
   only input] */

void sdr_upd_r1c(void)

{
  undefined2 local_2;
  
  if (g_opstate.ex030202_nb_rejection == 2) {
    local_2 = 10;
  }
  else if (g_opstate.ex030202_nb_rejection == 0) {
    local_2 = 2;
  }
  else {
    local_2 = 5;
  }
  if (DAT_0001b760 == local_2) {
    return;
  }
  DAT_0001b784 = 0x1c;
  DAT_0001b786 = local_2;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r1d_notch @ fffa20f7 (897 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa2407) */
/* WARNING: Removing unreachable block (ram,0xfffa2239) */
/* WARNING: Removing unreachable block (ram,0xfffa23f8) */
/* WARNING: Removing unreachable block (ram,0xfffa225d) */
/* WARNING: Removing unreachable block (ram,0xfffa217d) */
/* WARNING: Removing unreachable block (ram,0xfffa21ff) */
/* WARNING: Removing unreachable block (ram,0xfffa21e4) */
/* WARNING: Removing unreachable block (ram,0xfffa2123) */
/* WARNING: Removing unreachable block (ram,0xfffa21c8) */
/* WARNING: Removing unreachable block (ram,0xfffa2199) */
/* WARNING: Removing unreachable block (ram,0xfffa227b) */
/* WARNING: Removing unreachable block (ram,0xfffa234b) */
/* WARNING: Removing unreachable block (ram,0xfffa2369) */
/* WARNING: Removing unreachable block (ram,0xfffa239f) */
/* Reg 0x1D = notch offset/5 Hz (12 bits) | 0x2000 or 0x1000 (width 0x9AD1), 0 when off [inference:
   manual notch] */

void sdr_upd_r1d_notch(void)

{
  uint uVar1;
  short sVar2;
  undefined1 uStack_17;
  undefined1 uStack_16;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  ushort uStack_10;
  short sStack_c;
  short sStack_a;
  short sStack_8;
  ushort uStack_6;
  byte *pbStack_4;
  
  pbStack_4 = vfo_rec_ptr(0);
  bStack_12 = vfo_mode(0);
  bStack_13 = g_opstate.ex030201_if_notch_width;
  sStack_c = CONCAT11(g_opstate.ex010420_data_shift_ssb_be[0],
                      g_opstate.ex010420_data_shift_ssb_be[1]);
  sStack_a = 0;
  sStack_8 = 0;
  uStack_6 = 0;
  bStack_11 = 0;
  uVar1 = (uint)bStack_12;
  if (uVar1 == 0xe) {
    bStack_11 = pbStack_4[0x28] & 0x80;
    sStack_8 = CONCAT11(pbStack_4[0x2c],pbStack_4[0x2d]) * 10;
    if (g_opstate.ex010419_psk_tone == 1) {
      sStack_a = 0x5dc;
    }
    else if (g_opstate.ex010419_psk_tone == 2) {
      sStack_a = 2000;
    }
    else {
      sStack_a = 1000;
    }
    sStack_a = sStack_c * 10 + sStack_a;
    uStack_6 = sStack_a + CONCAT11(pbStack_4[0x2c],pbStack_4[0x2d]) * -10;
  }
  else if (uVar1 - 2 < 2) {
    bStack_11 = pbStack_4[0x14] & 0x80;
    sStack_8 = CONCAT11(pbStack_4[0x18],pbStack_4[0x19]) * 10;
    sStack_a = CONCAT11(pbStack_4[0x1c],pbStack_4[0x1d]);
    vfo_filter_width_hz(&uStack_17);
    uStack_10 = (ushort)g_opstate.cw_pitch * 10 + 300;
    if (CONCAT11(uStack_17,uStack_16) < uStack_10) {
      uStack_6 = (uStack_10 + sStack_a) - sStack_8;
    }
    else {
      uStack_6 = ((short)(((uint)CONCAT11(uStack_17,uStack_16) + (uint)uStack_10) / 2) + sStack_a) -
                 sStack_8;
    }
  }
  else if (uVar1 - 8 < 2) {
    bStack_11 = pbStack_4[0x28] & 0x80;
    sStack_8 = CONCAT11(pbStack_4[0x2c],pbStack_4[0x2d]) * 10;
    sStack_a = sStack_c * 10 + CONCAT11(pbStack_4[0x30],pbStack_4[0x31]);
    uStack_6 = sStack_a + CONCAT11(pbStack_4[0x2c],pbStack_4[0x2d]) * -10;
  }
  else if (uVar1 - 0xc < 2) {
    bStack_11 = pbStack_4[0x1e] & 0x80;
    sVar2 = CONCAT11(pbStack_4[0x22],pbStack_4[0x23]);
    sStack_8 = sVar2 * 10;
    sStack_a = CONCAT11(pbStack_4[0x26],pbStack_4[0x27]);
    bStack_14 = g_opstate.ex010515_mark_frequency;
    bStack_15 = g_opstate.ex010516_shift_frequency;
    if (g_opstate.ex010515_mark_frequency == 0) {
      if (g_opstate.ex010516_shift_frequency == 1) {
        uStack_6 = sStack_a + 0x564 + sVar2 * -10;
      }
      else if (g_opstate.ex010516_shift_frequency == 2) {
        uStack_6 = sStack_a + 0x5d2 + sVar2 * -10;
      }
      else if (g_opstate.ex010516_shift_frequency == 3) {
        uStack_6 = sStack_a + 0x6a4 + sVar2 * -10;
      }
      else {
        uStack_6 = sStack_a + 0x550 + sVar2 * -10;
      }
    }
    else if (g_opstate.ex010516_shift_frequency == 1) {
      uStack_6 = sStack_a + 0x8b6 + sVar2 * -10;
    }
    else if (g_opstate.ex010516_shift_frequency == 2) {
      uStack_6 = sStack_a + 0x924 + sVar2 * -10;
    }
    else if (g_opstate.ex010516_shift_frequency == 3) {
      uStack_6 = sStack_a + 0x9f6 + sVar2 * -10;
    }
    else {
      uStack_6 = sStack_a + 0x8a2 + sVar2 * -10;
    }
  }
  else if (uVar1 < 2) {
    bStack_11 = pbStack_4[10] & 0x80;
    sStack_8 = CONCAT11(pbStack_4[0xe],pbStack_4[0xf]) * 10;
    sStack_a = CONCAT11(pbStack_4[0x12],pbStack_4[0x13]);
    uStack_6 = sStack_a + 0x5dc + CONCAT11(pbStack_4[0xe],pbStack_4[0xf]) * -10;
  }
  if ((uStack_6 & 0x8000) == 0) {
    uStack_6 = uStack_6 / 5;
  }
  else {
    uStack_6 = ~((ushort)(~uStack_6 + 1) / 5) + 1;
  }
  if ((((bStack_12 == 1) || (bStack_12 == 3)) || (bStack_12 == 9)) ||
     (bStack_12 == 0xd || bStack_12 == 0xe)) {
    uStack_6 = ~uStack_6 + 1;
  }
  if ((uStack_6 & 0x8000) != 0) {
    uStack_6 = uStack_6 & 0xfff;
  }
  if (bStack_11 == 0) {
    uStack_6 = 0;
  }
  else if (bStack_13 == 0) {
    uStack_6 = uStack_6 | 0x2000;
  }
  else {
    uStack_6 = uStack_6 | 0x1000;
  }
  if (DAT_0001b762 == uStack_6) {
    return;
  }
  DAT_0001b784 = 0x1d;
  DAT_0001b786 = uStack_6;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r1e_passband @ fffa2478 (599 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa2685) */
/* WARNING: Removing unreachable block (ram,0xfffa2575) */
/* WARNING: Removing unreachable block (ram,0xfffa2676) */
/* WARNING: Removing unreachable block (ram,0xfffa2500) */
/* WARNING: Removing unreachable block (ram,0xfffa253f) */
/* WARNING: Removing unreachable block (ram,0xfffa2499) */
/* WARNING: Removing unreachable block (ram,0xfffa2524) */
/* WARNING: Removing unreachable block (ram,0xfffa24de) */
/* WARNING: Removing unreachable block (ram,0xfffa258b) */
/* WARNING: Removing unreachable block (ram,0xfffa262c) */
/* Reg 0x1E = signed passband centre / 5 Hz (negated for the upper-side modes) [inference] */

void sdr_upd_r1e_passband(void)

{
  uint uVar1;
  short sVar2;
  undefined1 uStack_11;
  undefined1 uStack_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  short sStack_c;
  ushort uStack_a;
  ushort uStack_6;
  byte *pbStack_4;
  
  pbStack_4 = vfo_rec_ptr(0);
  bStack_f = vfo_mode(0);
  sStack_c = CONCAT11(g_opstate.ex010420_data_shift_ssb_be[0],
                      g_opstate.ex010420_data_shift_ssb_be[1]);
  uStack_6 = 0;
  uVar1 = (uint)bStack_f;
  if (uVar1 == 0xe) {
    sVar2 = CONCAT11(pbStack_4[0x30],pbStack_4[0x31]);
    if (g_opstate.ex010419_psk_tone == 1) {
      uStack_6 = sVar2 + 0x5dc;
    }
    else if (g_opstate.ex010419_psk_tone == 2) {
      uStack_6 = sVar2 + 2000;
    }
    else {
      uStack_6 = sVar2 + 1000;
    }
  }
  else if (uVar1 - 2 < 2) {
    uStack_6 = CONCAT11(pbStack_4[0x1c],pbStack_4[0x1d]);
    vfo_filter_width_hz(&uStack_11);
    uStack_a = (ushort)g_opstate.cw_pitch * 10 + 300;
    if (CONCAT11(uStack_11,uStack_10) < uStack_a) {
      uStack_6 = uStack_6 + uStack_a;
    }
    else {
      uStack_6 = (short)(((uint)CONCAT11(uStack_11,uStack_10) + (uint)uStack_a) / 2) + uStack_6;
    }
  }
  else if (uVar1 - 8 < 2) {
    uStack_6 = sStack_c * 10 + CONCAT11(pbStack_4[0x30],pbStack_4[0x31]);
  }
  else if (uVar1 - 0xc < 2) {
    sVar2 = CONCAT11(pbStack_4[0x26],pbStack_4[0x27]);
    bStack_d = g_opstate.ex010515_mark_frequency;
    bStack_e = g_opstate.ex010516_shift_frequency;
    if (g_opstate.ex010515_mark_frequency == 0) {
      if (g_opstate.ex010516_shift_frequency == 1) {
        uStack_6 = sVar2 + 0x564;
      }
      else if (g_opstate.ex010516_shift_frequency == 2) {
        uStack_6 = sVar2 + 0x5d2;
      }
      else if (g_opstate.ex010516_shift_frequency == 3) {
        uStack_6 = sVar2 + 0x6a4;
      }
      else {
        uStack_6 = sVar2 + 0x550;
      }
    }
    else if (g_opstate.ex010516_shift_frequency == 1) {
      uStack_6 = sVar2 + 0x8b6;
    }
    else if (g_opstate.ex010516_shift_frequency == 2) {
      uStack_6 = sVar2 + 0x924;
    }
    else if (g_opstate.ex010516_shift_frequency == 3) {
      uStack_6 = sVar2 + 0x9f6;
    }
    else {
      uStack_6 = sVar2 + 0x8a2;
    }
  }
  else if (uVar1 < 2) {
    uStack_6 = CONCAT11(pbStack_4[0x12],pbStack_4[0x13]) + 0x5dc;
  }
  if ((uStack_6 & 0x8000) == 0) {
    uStack_6 = uStack_6 / 5;
  }
  else {
    uStack_6 = ~((ushort)(~uStack_6 + 1) / 5) + 1;
  }
  if ((((bStack_f == 1) || (bStack_f == 3)) || (bStack_f == 9)) ||
     (bStack_f == 0xd || bStack_f == 0xe)) {
    uStack_6 = ~uStack_6 + 1;
  }
  if (DAT_0001b764 == uStack_6) {
    return;
  }
  DAT_0001b784 = 0x1e;
  DAT_0001b786 = uStack_6;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r1f_width @ fffa26cf (137 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa270f) */
/* Reg 0x1F = filter width in Hz (AM 9000, AM-N 6000, FM/DATA-FM 16000, FM-N 9000, else the selected
   width) */

void sdr_upd_r1f_width(void)

{
  byte bVar1;
  undefined1 uStack_4;
  undefined1 uStack_3;
  short local_2;
  uint uVar2;
  
  local_2 = 0;
  bVar1 = vfo_mode(0);
  uVar2 = (uint)bVar1;
  if (uVar2 < 4) goto LAB_fffa2703;
  if (uVar2 != 4) {
    if (uVar2 == 5) {
      local_2 = 6000;
      goto LAB_fffa272e;
    }
    if (uVar2 == 6) {
LAB_fffa2729:
      local_2 = 16000;
      goto LAB_fffa272e;
    }
    if (uVar2 != 7) {
      if (1 < uVar2 - 8) {
        if (uVar2 == 10) goto LAB_fffa2729;
        if (uVar2 == 0xb) goto LAB_fffa271c;
        if (2 < uVar2 - 0xc) goto LAB_fffa272e;
      }
LAB_fffa2703:
      vfo_filter_width_hz(&uStack_4);
      local_2 = CONCAT11(uStack_4,uStack_3);
      goto LAB_fffa272e;
    }
  }
LAB_fffa271c:
  local_2 = 9000;
LAB_fffa272e:
  if (DAT_0001b766 != local_2) {
    DAT_0001b784 = 0x1f;
    DAT_0001b786 = local_2;
    sdr_send_frame('w');
    return;
  }
  return;
}


// ===== sdr_upd_r20_scope_freq @ fffa2758 (402 bytes)

/* Regs 0x20/0x21 = 32-bit scope centre frequency (centre mode: RX freq + offset; fixed/cursor:
   start + half span); TX: |f - 62.5 MHz| */

void sdr_upd_r20_scope_freq(char param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 uStack_10;
  undefined *puStack_c;
  
  uVar3 = vfo_freq(param_1,2);
  bVar1 = g_opstate.scope_mode;
  puVar4 = (undefined1 *)scope_span_ptr(uVar3);
  if (param_1 == '\0') {
    uVar2 = vfo_display_offset();
    if (bVar1 == 0) {
      if ((uVar2 & 0x8000) == 0) {
        uStack_10 = (undefined *)(uVar3 + uVar2);
      }
      else {
        uStack_10 = (undefined *)(uVar3 - (ushort)(~uVar2 + 1));
      }
    }
    else {
      if (bVar1 == 2) {
        puStack_c = (undefined *)bandmem_get('\x02');
      }
      else {
        puStack_c = (undefined *)g_ui.scope_cursor_start;
      }
      switch(*puVar4) {
      case 0:
        puStack_c = (undefined *)((int)puStack_c + 500);
        break;
      case 1:
        puStack_c = (undefined *)((int)puStack_c + 1000);
        break;
      case 2:
        puStack_c = (undefined *)((int)puStack_c + 0x9c4);
        break;
      case 3:
        puStack_c = &DAT_00001388 + (int)puStack_c;
        break;
      case 4:
        puStack_c = &DAT_00002710 + (int)puStack_c;
        break;
      case 5:
        puStack_c = (undefined *)((int)puStack_c + 25000);
        break;
      case 6:
        puStack_c = &DAT_0000c350 + (int)puStack_c;
        break;
      case 7:
        puStack_c = &DAT_000186a0 + (int)puStack_c;
        break;
      case 8:
        puStack_c = &DAT_0003d090 + (int)puStack_c;
        break;
      default:
        puStack_c = (undefined *)((int)puStack_c + 500000);
      }
      if ((uVar2 & 0x8000) == 0) {
        uStack_10 = puStack_c + uVar2;
      }
      else {
        uStack_10 = puStack_c + -(uint)(ushort)(~uVar2 + 1);
      }
    }
  }
  else {
    uVar3 = tx_freq_repeater_shift(uVar3);
    if (uVar3 < 0x3b9aca1) {
      uStack_10 = (undefined *)(62500000 - uVar3);
    }
    else {
      uStack_10 = (undefined *)(uVar3 + 0xfc465360);
    }
  }
  if (uStack_10._2_2_ != DAT_0001b768) {
    DAT_0001b784 = 0x20;
    DAT_0001b786 = uStack_10._2_2_;
    sdr_send_frame('w');
    DAT_0001b76a = 0xffff;
    return;
  }
  if (((uint)uStack_10 & 0xffff) != (uint)DAT_0001b76a) {
    DAT_0001b784 = 0x21;
    DAT_0001b786 = (undefined2)uStack_10;
    sdr_send_frame('w');
    return;
  }
  return;
}


// ===== sdr_upd_r22_scope_span @ fffa28ea (168 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa2913) */
/* Reg 0x22 = scope span in kHz (1,2,5,10,20,50,100,200,500, default 1000) */

void sdr_upd_r22_scope_span(byte param_1)

{
  byte bVar1;
  byte bVar2;
  uint freq;
  undefined1 *puStack_10;
  short sStack_a;
  
  bVar1 = g_opstate.scope_mode;
  freq = vfo_freq(param_1,2);
  bVar2 = freq_range_index(freq);
  sStack_a = 1000;
  if (bVar1 == 2) {
    puStack_10 = (&PTR_g_opstate_scope_span_idx_b_0__fff885b0)[(uint)bVar2 * 2];
  }
  else {
    puStack_10 = (&PTR_g_opstate_scope_span_idx_a_0__fff885ac)[(uint)bVar2 * 2];
  }
  switch(*puStack_10) {
  case 0:
    sStack_a = 1;
    break;
  case 1:
    sStack_a = 2;
    break;
  case 2:
    sStack_a = 5;
    break;
  case 3:
    sStack_a = 10;
    break;
  case 4:
    sStack_a = 0x14;
    break;
  case 5:
    sStack_a = 0x32;
    break;
  case 6:
    sStack_a = 100;
    break;
  case 7:
    sStack_a = 200;
    break;
  case 8:
    sStack_a = 500;
  }
  if (DAT_0001b76c == sStack_a) {
    return;
  }
  DAT_0001b784 = 0x22;
  DAT_0001b786 = sStack_a;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r23 @ fffa2992 (83 bytes)

/* Reg 0x23 = 0x8000/0x7000/0x5000 from scope RBW 0x9B14 (EX040201) [fact]; scope RBW parameter
   [inference: only input] */

void sdr_upd_r23(void)

{
  undefined2 local_2;
  
  if (g_opstate.ex040201_rbw == 1) {
    local_2 = 0x7000;
  }
  else if (g_opstate.ex040201_rbw == 2) {
    local_2 = 0x5000;
  }
  else {
    local_2 = -0x8000;
  }
  if (DAT_0001b76e == local_2) {
    return;
  }
  DAT_0001b784 = 0x23;
  DAT_0001b786 = local_2;
  sdr_send_frame('w');
  return;
}


// ===== sdr_init_r24 @ fffa29e5 (49 bytes)

/* Reg 0x24 = 0x0317, sent once after the first full sync */

void sdr_init_r24(void)

{
  if (DAT_0001b770 == 0x317) {
    return;
  }
  DAT_0001b784 = 0x24;
  DAT_0001b786 = 0x317;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r25_tx_drive @ fffa2a16 (377 bytes)

/* Reg 0x25 = TX drive: power setting interpolated (5/10/20/50/100 W) in the per-band calibration in
   the 0x4659 (SPN) table, << 4 */

void sdr_upd_r25_tx_drive(byte param_1)

{
  undefined *puVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  float fVar5;
  uint uVar6;
  float fStack_28;
  float fStack_24;
  float fStack_1c;
  float fStack_18;
  
  uVar6 = (uint)SCARRY4((int)&stack0x00000000,-0x28) << 3;
  iVar4 = FUN_fffb4062();
  fVar5 = (float)iVar4;
  uVar6 = uVar6 & 0xfffffff9;
  bVar2 = tx_band_of_freq(g_ui.freq_tx);
  puVar1 = (&tx_row_ptrs)[bVar2];
  if (fVar5 - 100.0 == 0.0) {
    if (bVar2 < 10) {
      fStack_1c = (float)(byte)puVar1[2];
      fStack_24 = 100.0;
      fStack_28 = 101.0;
      fStack_18 = fStack_1c;
    }
    else {
      fStack_1c = (float)(byte)puVar1[5];
      fStack_24 = 50.0;
      fStack_28 = 51.0;
      fStack_18 = fStack_1c;
    }
  }
  else if (fVar5 - 50.0 < 0.0 == (bool)((byte)(uVar6 >> 3) & 1)) {
    fStack_18 = (float)(byte)puVar1[5];
    if (bVar2 < 10) {
      fStack_1c = (float)(byte)puVar1[2];
      fStack_24 = 50.0;
      fStack_28 = 100.0;
    }
    else {
      fStack_24 = 50.0;
      fStack_28 = 51.0;
      fStack_1c = fStack_18;
    }
  }
  else if (fVar5 - 20.0 < 0.0 == (bool)((byte)(uVar6 >> 3) & 1)) {
    fStack_18 = (float)(byte)puVar1[8];
    fStack_24 = 20.0;
    fStack_28 = 50.0;
    fStack_1c = (float)(byte)puVar1[5];
  }
  else if (fVar5 - 10.0 < 0.0 == (bool)((byte)(uVar6 >> 3) & 1)) {
    fStack_18 = (float)(byte)puVar1[0xb];
    fStack_24 = 10.0;
    fStack_28 = 20.0;
    fStack_1c = (float)(byte)puVar1[8];
  }
  else {
    fStack_18 = (float)(byte)puVar1[0xe];
    fStack_24 = 5.0;
    fStack_28 = 10.0;
    fStack_1c = (float)(byte)puVar1[0xb];
  }
  sVar3 = SUB42(ROUND(((fVar5 - fStack_24) * (fStack_1c - fStack_18)) / (fStack_28 - fStack_24) +
                      fStack_18),0) << 4;
  if (DAT_0001b772 == sVar3) {
    return;
  }
  DAT_0001b784 = 0x25;
  DAT_0001b786 = sVar3;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r26 @ fffa2b8f (116 bytes)

/* Reg 0x26 = 0x0610 in RX; in TX 0x0140/0x0610/0x0200/0xFF00 from 0x9C36/0x9B16/0x9B17 [meaning
   unknown] */

void sdr_upd_r26(char param_1)

{
  undefined2 local_4;
  
  if (param_1 == '\0') {
    local_4 = 0x610;
  }
  else if (g_opstate.scope_3dss == 0) {
    if (g_opstate.ex040203_2d_disp_sensitivity == 0) {
      local_4 = 0x610;
    }
    else {
      local_4 = 0x140;
    }
  }
  else if (g_opstate.ex040204_3dss_disp_sensitivity == 0) {
    local_4 = 0x200;
  }
  else {
    local_4 = -0x100;
  }
  if (DAT_0001b774 == local_4) {
    return;
  }
  DAT_0001b784 = 0x26;
  DAT_0001b786 = local_4;
  sdr_send_frame('w');
  return;
}


// ===== sdr_upd_r27_scope_level @ fffa2c03 (156 bytes)

/* Reg 0x27 = 0x8000 | -(scope ref level byte + offset) + 0/2/4 (setting 0x9B14) [inference] */

void sdr_upd_r27_scope_level(char param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  char *pcVar5;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  bVar2 = g_opstate.ex040201_rbw;
  bVar1 = g_cfg105.a049_rx_scope_sdr_ref;
  uVar4 = vfo_freq(param_1,2);
  pcVar5 = (char *)scope_level_ptr(uVar4,param_1);
  if (bVar2 == 1) {
    uStack_14 = '\x02';
  }
  else if (bVar2 == 2) {
    uStack_14 = '\x04';
  }
  else {
    uStack_14 = '\0';
  }
  if (param_1 == '\0') {
    uStack_13 = *pcVar5 + bVar1 + 0x44;
  }
  else {
    uStack_13 = *pcVar5 - 0x37;
  }
  uVar3 = (byte)(~uStack_13 + 1 + uStack_14) | 0x8000;
  if (DAT_0001b776 == uVar3) {
    return;
  }
  DAT_0001b784 = 0x27;
  DAT_0001b786 = uVar3;
  sdr_send_frame('w');
  return;
}


// ===== sdr_shadow_update @ fffa2c9f (856 bytes)

/* After an ACKed frame: copies 0x1B786 into the shadow slot of register 0x1B784 (0x1B736..0x1B780;
   0xFFFF -> 0x1B782) */

void sdr_shadow_update(void)

{
  if (DAT_0001b784 == -1) {
    DAT_0001b782 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 1) {
    DAT_0001b738 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 3) {
    DAT_0001b73a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 4) {
    DAT_0001b73c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 8) {
    DAT_0001b73e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 9) {
    DAT_0001b740 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 10) {
    sdr_mod_class_0001b742 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xb) {
    DAT_0001b744 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xc) {
    DAT_0001b746 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xd) {
    DAT_0001b748 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xe) {
    DAT_0001b74a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0xf) {
    DAT_0001b74c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x12) {
    DAT_0001b74e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x13) {
    DAT_0001b750 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x14) {
    DAT_0001b752 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x15) {
    DAT_0001b754 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x16) {
    DAT_0001b756 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x18) {
    DAT_0001b758 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x19) {
    DAT_0001b75a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1a) {
    DAT_0001b75c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1b) {
    DAT_0001b75e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1c) {
    DAT_0001b760 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1d) {
    DAT_0001b762 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1e) {
    DAT_0001b764 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x1f) {
    DAT_0001b766 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x20) {
    DAT_0001b768 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x21) {
    DAT_0001b76a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x22) {
    DAT_0001b76c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x23) {
    DAT_0001b76e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x24) {
    DAT_0001b770 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x25) {
    DAT_0001b772 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x26) {
    DAT_0001b774 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x27) {
    DAT_0001b776 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x30) {
    DAT_0001b778 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x31) {
    DAT_0001b77a = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x32) {
    DAT_0001b77c = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x33) {
    DAT_0001b77e = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 == 0x37) {
    DAT_0001b780 = DAT_0001b786;
    return;
  }
  if (DAT_0001b784 != 0) {
    return;
  }
  DAT_0001b736 = DAT_0001b786;
  return;
}


// ===== sdr_wait_reply @ fffa2ff7 (140 bytes)

/* Blocking wait for the reply of the pending frame; read -> 0x1B786=hex2word(reply+1); calls
   sdr_shadow_update (arg2=1: reg forced to 0xFFFF so the value lands in 0x1B782) */

byte sdr_wait_reply(char param_1,char param_2)

{
  byte bVar1;
  byte local_9;
  int iStack_8;
  char local_2;
  char local_1;
  
  local_9 = 0;
  local_2 = param_2;
  local_1 = param_1;
  while( true ) {
    while (local_1 != 'r') {
      if (DAT_00001c8b != '\x01') {
        return local_9;
      }
      bVar1 = sdr_poll_reply('w',&iStack_8);
      if (bVar1 == 1) {
        if (local_2 == '\x01') {
          DAT_0001b784 = 0xffff;
        }
        sdr_shadow_update();
        local_9 = 1;
      }
    }
    if (DAT_00001c8c != '\x01') break;
    bVar1 = sdr_poll_reply('r',&iStack_8);
    if (bVar1 == 1) {
      DAT_0001b786 = hex2word((char *)(iStack_8 + 1));
      if (local_2 == '\x01') {
        DAT_0001b784 = 0xffff;
      }
      sdr_shadow_update();
      return 1;
    }
  }
  return local_9;
}


// ===== sdr_poll_reply @ fffa3083 (118 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa30f6) */
/* Reply poll: if 0xA2B3, clears pending flags; 'r' -> checks 2-hex sum of bytes 0..4, 'w' -> byte 0
   must be ACK 0x06; on timer 2 timeout clears the flags and fails */

byte sdr_poll_reply(char param_1,void *param_2)

{
  byte bVar1;
  uint uVar2;
  undefined1 local_e;
  
  local_e = 0;
  bVar1 = sdr_rx_ready();
  if (bVar1 == 1) {
    uVar2 = sdr_rx_buf();
    *(uint *)param_2 = uVar2;
    DAT_00001c8b = 0;
    DAT_00001c8c = 0;
    if (param_1 == 'r') {
      bVar1 = sdr_check_hex_sum((int)*(char **)param_2,5);
      if (bVar1 == 1) {
        local_e = 1;
      }
    }
    else if (**(char **)param_2 == '\x06') {
      local_e = 1;
    }
  }
  else {
    bVar1 = swtimer_expired(2);
    if (bVar1 == 1) {
      DAT_00001c8b = 0;
      DAT_00001c8c = 0;
    }
  }
  return local_e;
}

