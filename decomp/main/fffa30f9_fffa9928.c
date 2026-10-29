// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== sdr_send_frame @ fffa30f9 (181 bytes)

/* Builds 'r'/'w' + 4-hex reg (0x1B784) [+ 4-hex value 0x1B786] + 2-hex sum8 + CR at 0x1C7F, sets
   pending flag 0x1C8C (r) / 0x1C8B (w), sends via sdr_send_cmd, arms timer 2 = 6 ms */

void sdr_send_frame(char param_1)

{
  byte bVar1;
  byte local_2;
  
  DAT_00001c7f = param_1;
  word2hex(0x1c80,DAT_0001b784);
  local_2 = 5;
  if (param_1 == 'w') {
    word2hex(0x1c84,DAT_0001b786);
    local_2 = 9;
    DAT_00001c8b = 1;
  }
  else {
    DAT_00001c8c = 1;
  }
  bVar1 = sdr_sum8(0x1c7f,local_2);
  byte2hex(&DAT_00001c7f + local_2,bVar1);
  (&DAT_00001c7f)[(byte)(local_2 + 2)] = 0xd;
  sdr_send_cmd(0x1c7f,(ushort)(byte)(local_2 + 3));
  swtimer_start(2,6);
  return;
}


// ===== sdr_sum8 @ fffa31ae (45 bytes)

/* 8-bit additive sum of n bytes (frame checksum) */

char sdr_sum8(int param_1,byte param_2)

{
  undefined1 local_8;
  undefined1 local_7;
  
  local_8 = '\0';
  for (local_7 = 0; local_7 < param_2; local_7 = local_7 + 1) {
    local_8 = *(char *)((uint)local_7 + param_1) + local_8;
  }
  return local_8;
}


// ===== sdr_check_hex_sum @ fffa31db (75 bytes)

/* 1 if the 2 hex chars after n bytes equal sum8 of those bytes */

byte sdr_check_hex_sum(int param_1,byte param_2)

{
  byte bVar1;
  char cStack_8;
  char cStack_7;
  byte local_5;
  int local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  bVar1 = sdr_sum8(param_1,param_2);
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


// ===== sdr_bridge_mode @ fffa3226 (598 bytes)

/* SDR maintenance bridge driven by DISPLAY link (ACK 0x06 / NAK 0x15), started via 0x1C8D */

void sdr_bridge_mode(void)

{
  bool bVar1;
  byte bVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 auStack_10 [4];
  char cStack_c;
  char acStack_b [6];
  char acStack_5 [5];
  
  DAT_00001c8d = 0;
  dsp_reset_set(0);
  sdr_reset_set('\0');
  sdr_update_set(0);
  swtimer_start(0x1e,100);
  do {
    bVar2 = swtimer_expired(0x1e);
  } while (bVar2 != 1);
  sdr_reset_set('\x01');
  swtimer_start(0x1e,2000);
  do {
    bVar2 = swtimer_expired(0x1e);
  } while (bVar2 != 1);
  DAT_0001b784 = 0x37;
  DAT_0001b786 = 0xbcc5;
  sdr_send_frame('w');
  bVar2 = sdr_wait_reply('w','\0');
  if (bVar2 == 1) {
    uStack_12 = 6;
    displink_uart_send((uint)&uStack_12,1);
    while( true ) {
      do {
        do {
          wdt_kick();
          bVar2 = displink_rx_ready();
        } while (bVar2 != 1);
        pcVar3 = (char *)displink_rx_buf();
        pcVar4 = acStack_b;
        for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
          *pcVar4 = *pcVar3;
          pcVar4 = pcVar4 + 1;
          pcVar3 = pcVar3 + 1;
        }
        displink_rx_rearm();
      } while (acStack_b[0] == '\x06');
      if ((acStack_b[0] == -0xf) && (acStack_b[1] == -0x7f)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) break;
      if ((acStack_b[0] == -3) && (acStack_b[1] == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0001b784 = hex2word(acStack_b + 2);
        DAT_0001b786 = hex2word(acStack_5);
        sdr_send_frame('w');
        bVar2 = sdr_wait_reply('w','\0');
        if (bVar2 == 1) {
          uStack_12 = 6;
          displink_uart_send((uint)&uStack_12,1);
        }
        else {
          uStack_12 = 0x15;
          displink_uart_send((uint)&uStack_12,1);
        }
      }
      else {
        if ((acStack_b[0] == -2) && (acStack_b[1] == '\0')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uStack_12 = 6;
          displink_uart_send((uint)&uStack_12,1);
          DAT_0001b784 = hex2word(acStack_b + 2);
          sdr_send_frame('r');
          bVar2 = sdr_wait_reply('r','\0');
          if (bVar2 == 1) {
            uStack_12 = 0x7d;
            uStack_11 = 0;
            if (DAT_0001b784 == 0x32) {
              word2hex((int)auStack_10,DAT_0001b77c);
              cStack_c = sdr_sum8((int)&uStack_12,6);
              displink_uart_send((uint)&uStack_12,7);
            }
            else if (DAT_0001b784 == 0x33) {
              word2hex((int)auStack_10,DAT_0001b77e);
              cStack_c = sdr_sum8((int)&uStack_12,6);
              displink_uart_send((uint)&uStack_12,7);
            }
            else {
              uStack_12 = 0x15;
              displink_uart_send((uint)&uStack_12,1);
            }
          }
          else {
            uStack_12 = 0x15;
            displink_uart_send((uint)&uStack_12,1);
          }
        }
        else {
          uStack_12 = 0x15;
          displink_uart_send((uint)&uStack_12,1);
        }
      }
    }
    uStack_12 = 6;
    displink_uart_send((uint)&uStack_12,1);
    sdr_reset_set('\0');
    sdr_update_set(1);
    swtimer_start(0x1e,100);
    do {
      bVar2 = swtimer_expired(0x1e);
    } while (bVar2 != 1);
    sdr_reset_set('\x01');
    dsp_reset_set(1);
    return;
  }
  uStack_12 = 0x15;
  displink_uart_send((uint)&uStack_12,1);
  return;
}


// ===== cat_parse @ fffa347c (630 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa350d) */
/* WARNING: Removing unreachable block (ram,0xfffa3588) */
/* WARNING: Removing unreachable block (ram,0xfffa365b) */
/* CAT command parser: looks up the 2-char mnemonic in cat_mnemonics (0xFFF805EC, 104 entries) then
   cat_ext_mnemonics (0xFFF806BC, 10 entries), calls cat_dispatch / cat_dispatch_ext */

void cat_parse(void)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  byte bVar4;
  byte bStack_f;
  byte bStack_e;
  undefined2 uStack_d;
  byte bStack_b;
  byte bStack_a;
  byte bStack_9;
  char *pcStack_8;
  byte *pbStack_4;
  
  bStack_9 = cat_ring_head();
  bStack_a = cat_ring_tail();
  DAT_0000464a = '\0';
  bStack_f = 0xff;
  DAT_0001b788 = 0;
  if (DAT_00020b46 == '\x01') {
    DAT_0001b788 = 0;
    DAT_0000464a = 0;
    return;
  }
  if (bStack_9 == bStack_a) {
    pcStack_8 = (char *)cat_e9_slot();
    if (*pcStack_8 == '\x01') {
      bStack_b = pcStack_8[1];
      uStack_d = *(undefined2 *)(pcStack_8 + 4);
      for (bStack_e = 0; bStack_e < 2; bStack_e = bStack_e + 1) {
        toupper_inplace((char *)((int)&uStack_d + (uint)bStack_e));
      }
      for (bStack_e = 0; bStack_e < 10; bStack_e = bStack_e + 1) {
        iVar2 = scmpu(&uStack_d,(uint)bStack_e * 2 + -0x7f944,2);
        if (-1 < iVar2 == iVar2 < 1) {
          bStack_f = bStack_e;
          break;
        }
      }
      if (bStack_f == 3) {
        cat_ext_E9((int)(pcStack_8 + 4));
      }
      if (DAT_0000464a != '\0') {
        cat_reply_error();
      }
      if (DAT_0001b788 != 0) {
        cat_send_reply((uint)bStack_b,0x1c8e,DAT_0001b788);
      }
      *pcStack_8 = '\0';
    }
  }
  else {
    cat_apo_reset();
    pbStack_4 = (byte *)cat_ring_pop();
    bStack_b = *pbStack_4;
    bVar4 = sci_tx_end((uint)bStack_b);
    if (bVar4 == 0) {
      cat_ring_unpop();
      return;
    }
    uStack_d = *(undefined2 *)(pbStack_4 + 4);
    uVar1 = *(ushort *)(pbStack_4 + 2);
    DAT_0000464c = bStack_b;
    for (bStack_e = 0; bStack_e < 2; bStack_e = bStack_e + 1) {
      toupper_inplace((char *)((int)&uStack_d + (uint)bStack_e));
    }
    for (bStack_e = 0; bStack_e < 0x68; bStack_e = bStack_e + 1) {
      iVar2 = scmpu(&uStack_d,(uint)bStack_e * 2 + -0x7fa14,2);
      if (-1 < iVar2 == iVar2 < 1) {
        bStack_f = bStack_e;
        break;
      }
    }
    if (DAT_00020b3a == '\0') {
      if ((bStack_f == 0x47) && (pbStack_4[6] == 0x31)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      if (!bVar3) {
        return;
      }
    }
    if (bStack_f == 0xff) {
      for (bStack_e = 0; bStack_e < 10; bStack_e = bStack_e + 1) {
        iVar2 = scmpu(&uStack_d,(uint)bStack_e * 2 + -0x7f944,2);
        if (-1 < iVar2 == iVar2 < 1) {
          bStack_f = bStack_e;
          break;
        }
      }
      if (bStack_f == 0xff) {
        DAT_0000464a = '\x01';
      }
      else if (bStack_f == 0) {
        cat_ext_SP((int)pbStack_4);
      }
      else {
        cat_dispatch_ext((int)pbStack_4,bStack_f,uVar1);
      }
    }
    else {
      cat_dispatch((int)pbStack_4,bStack_f,uVar1);
    }
    if (DAT_0000464a == '\0') {
      if (DAT_00020b8a == '\x01') {
        FUN_fffbe232();
      }
    }
    else {
      cat_reply_error();
    }
    if (DAT_0001b788 != 0) {
      cat_send_reply((uint)bStack_b,0x1c8e,DAT_0001b788);
    }
  }
  if ((DAT_0000464b == '\x01') && (bVar4 = swtimer_expired(0x32), bVar4 == 1)) {
    key_dsp_press();
    DAT_0000464b = '\0';
  }
  cat_ai_poll();
  return;
}


// ===== cat_ext_SP @ fffa36f2 (824 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Extended command SP (index 0 of 0xFFF806BC table) */

void cat_ext_SP(int param_1)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = *(char *)(param_1 + 6);
  if ((cVar1 == 'S') || (cVar1 == 's')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    cVar1 = *(char *)(param_1 + 7);
    if ((cVar1 == 'W') || (cVar1 == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_sdr_reg(param_1 + 4,'\x01');
      return;
    }
    if ((cVar1 == 'R') || (cVar1 == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_sdr_reg(param_1 + 4,'\0');
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'D') || (cVar1 == 'd')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    cVar1 = *(char *)(param_1 + 7);
    if ((cVar1 == 'W') || (cVar1 == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_dev4_reg(param_1 + 4,'\x01');
      return;
    }
    if ((cVar1 == 'R') || (cVar1 == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_dev4_reg(param_1 + 4,'\0');
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'I') || (cVar1 == 'i')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if ((*(char *)(param_1 + 7) == 'R') || (*(char *)(param_1 + 7) == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_adc_dump();
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'W') || (cVar1 == 'R')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    bVar2 = cat_checksum_ok(param_1 + 4,*(short *)(param_1 + 2) - 2);
    if (!bVar2) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00001c92 = *(undefined1 *)(param_1 + 8);
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (cVar1 == 'W') {
      cat_SP_eeprom_byte(param_1 + 4,'\x01');
      return;
    }
    cat_SP_eeprom_byte(param_1 + 4,'\0');
    return;
  }
  if ((cVar1 == 'M') || (cVar1 == 'm')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    bVar2 = cat_checksum_ok(param_1 + 4,*(short *)(param_1 + 2) - 2);
    if (!bVar2) {
      DAT_0000464a = 1;
      return;
    }
    _DAT_00001c8e =
         CONCAT22(CONCAT11(DAT_00001c91,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    cat_SP_meters();
    return;
  }
  if ((cVar1 == 'N') || (cVar1 == 'n')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    _DAT_00001c8e =
         CONCAT22(CONCAT11(DAT_00001c91,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    cVar1 = *(char *)(param_1 + 7);
    if ((cVar1 == 'W') || (cVar1 == 'w')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_table(param_1 + 4,'\x01',*(short *)(param_1 + 2));
      return;
    }
    if ((cVar1 == 'S') || (cVar1 == 's')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_table(param_1 + 4,'\x01',*(short *)(param_1 + 2));
      return;
    }
    if ((cVar1 == 'R') || (cVar1 == 'r')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      cat_SP_table(param_1 + 4,'\0',*(short *)(param_1 + 2));
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if ((cVar1 == 'A') || (cVar1 == 'a')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    return;
  }
  bVar2 = cat_checksum_ok(param_1 + 4,*(short *)(param_1 + 2) - 2);
  if (!bVar2) {
    DAT_0000464a = 1;
    return;
  }
  if ((*(char *)(param_1 + 7) == 'W') || (*(char *)(param_1 + 7) == 'w')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    if ((*(char *)(param_1 + 8) == 'E') || (*(char *)(param_1 + 8) == 'e')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      bVar2 = true;
      goto LAB_fffa3a12;
    }
  }
  bVar2 = false;
LAB_fffa3a12:
  if (bVar2) {
    eeprom_save_cfg105();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_dispatch_ext @ fffa3a2a (324 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Dispatch for the extended/hidden mnemonic table (EO E8 FD PE ZZ VE JP; E9/KT no case here) */

void cat_dispatch_ext(int param_1,char param_2,short param_3)

{
  char cVar1;
  
  if (param_2 == '\x01') {
    _DAT_00001c92 = CONCAT11((undefined1)DAT_00001c93,*(undefined1 *)(param_1 + 8));
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 != 10) {
      DAT_0000464a = 1;
      return;
    }
    cat_ext_EO(param_1 + 4,1);
    return;
  }
  if (param_2 == '\t') {
    _DAT_00001c92 = *(undefined2 *)(param_1 + 8);
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 7) {
      cat_ext_JP(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 0xf) {
      DAT_0000464a = 1;
      return;
    }
    cat_ext_JP(param_1 + 4,'\x01');
    return;
  }
  if (param_2 == '\x04') {
    _DAT_00001c92 = CONCAT11((undefined1)DAT_00001c93,*(undefined1 *)(param_1 + 8));
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 6) {
      cat_ext_FD(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 0xf) {
      DAT_0000464a = 1;
      return;
    }
    cat_ext_FD(param_1 + 4,'\x01');
    return;
  }
  if (param_2 != '\x06') {
    if (param_2 == '\a') {
      cat_ext_ZZ(param_1 + 4);
      return;
    }
    if (param_2 == '\b') {
      _DAT_00001c8e =
           CONCAT22(CONCAT11(DAT_00001c91,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4)
                   );
      cVar1 = hex2nib(*(byte *)(param_1 + 6));
      cat_ext_VE(cVar1);
      return;
    }
    if (param_2 != '\x02') {
      return;
    }
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    cat_ext_E8();
    return;
  }
  _DAT_00001c92 = CONCAT11((undefined1)DAT_00001c93,*(undefined1 *)(param_1 + 8));
  _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
  if (param_3 == 6) {
    cat_ext_PE(param_1 + 4,'\0');
    return;
  }
  if (param_3 != 9) {
    DAT_0000464a = 1;
    return;
  }
  cat_ext_PE(param_1 + 4,'\x01');
  return;
}


// ===== cat_dispatch @ fffa3b6e (4803 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAT dispatch switch: index -> case via 16-bit offset table 0xFFF8F014 (BRA.L at 0xFFFA3B8A); each
   case checks parameter length (query vs set) then calls cat_XX */

void cat_dispatch(int param_1,char param_2,ushort param_3)

{
  bool bVar1;
  undefined1 uVar2;
  
  uVar2 = DAT_00001c91;
  switch(param_2) {
  case '\0':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_AB();
    return;
  case '\x01':
    break;
  case '\x02':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_AG(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_AG(param_1 + 4,'\x01');
    return;
  case '\x03':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_AI(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_AI(param_1 + 4,'\x01');
    return;
  case '\x04':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_AM();
    return;
  case '\x05':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_AO(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_AO(param_1 + 4,'\x01');
    return;
  case '\x06':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_AS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_AS(param_1 + 4,'\x01');
    return;
  case '\a':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_AV(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_AV(param_1 + 4,'\x01');
    return;
  case '\b':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_BA();
    return;
  case '\t':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_BC(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_BC(param_1 + 4,'\x01');
    return;
  case '\n':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_BD(param_1 + 4);
    return;
  case '\v':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_BI(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_BI(param_1 + 4,'\x01');
    return;
  case '\f':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_BM();
    return;
  case '\r':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_BP(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 8) {
      DAT_0000464a = 1;
      return;
    }
    cat_BP(param_1 + 4,'\x01');
    return;
  case '\x0e':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_BS(param_1 + 4);
    return;
  case '\x0f':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_BU(param_1 + 4);
    return;
  default:
    DAT_0000464a = 1;
    return;
  case '\x11':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 6) {
      cat_CF(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 0xb) {
      DAT_0000464a = 1;
      return;
    }
    cat_CF(param_1 + 4,'\x01');
    return;
  case '\x12':
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_CH(param_1 + 4);
    return;
  case '\x13':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_CN(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 8) {
      DAT_0000464a = 1;
      return;
    }
    cat_CN(param_1 + 4,'\x01');
    return;
  case '\x14':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 5) {
      cat_CO(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 9) {
      DAT_0000464a = 1;
      return;
    }
    cat_CO(param_1 + 4,'\x01');
    return;
  case '\x15':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_CS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_CS(param_1 + 4,'\x01');
    return;
  case '\x16':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_CT(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_CT(param_1 + 4,'\x01');
    return;
  case '\x17':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_DA(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 0xb) {
      DAT_0000464a = 1;
      return;
    }
    cat_DA(param_1 + 4,'\x01');
    return;
  case '\x18':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_DN();
    return;
  case '\x19':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_DT(param_1 + 4,'\0');
      return;
    }
    if ((param_3 == 10) || (param_3 == 0xc)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_DT(param_1 + 4,'\x01');
    return;
  case '\x1c':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_EM(param_1 + 4,0);
      return;
    }
    if ((param_3 < 6) || (0x37 < param_3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_EM(param_1 + 4,1);
    return;
  case '\x1d':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_EN(param_1 + 4);
    return;
  case '\x1f':
    _DAT_00001c92 = *(undefined4 *)(param_1 + 8);
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 9) {
      cat_EX(param_1 + 4,'\0',9);
      return;
    }
    if (8 < param_3) {
      cat_EX(param_1 + 4,'\x01',param_3);
      return;
    }
    DAT_0000464a = 1;
    return;
  case ' ':
  case '!':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FA_FB(param_1 + 4,'\0',param_2 != ' ');
      return;
    }
    if (param_3 != 0xc) {
      DAT_0000464a = 1;
      return;
    }
    cat_FA_FB(param_1 + 4,'\x01',param_2 != ' ');
    return;
  case '\"':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FN(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_FN(param_1 + 4,'\x01');
    return;
  case '#':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FS(param_1 + 4,0);
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_FS(param_1 + 4,1);
    return;
  case '$':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_FT(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_FT(param_1 + 4,'\x01');
    return;
  case '%':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_GT(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_GT(param_1 + 4,'\x01');
    return;
  case '&':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_GP(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_GP(param_1 + 4,'\x01');
    return;
  case '\'':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_ID();
    return;
  case '(':
  case '@':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_IF_OI(param_2 != '(');
    return;
  case ')':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_IS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 10) {
      DAT_0000464a = 1;
      return;
    }
    cat_IS(param_1 + 4,'\x01');
    return;
  case '*':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_KM(param_1 + 4,'\0',4);
      return;
    }
    if ((param_3 < 5) || (0x36 < param_3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_KM(param_1 + 4,'\x01',param_3);
    return;
  case '+':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_KP(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_KP(param_1 + 4,'\x01');
    return;
  case ',':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_KR(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_KR(param_1 + 4,'\x01');
    return;
  case '-':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_KS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_KS(param_1 + 4,'\x01');
    return;
  case '.':
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_KY(param_1 + 4);
    return;
  case '/':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_LK(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_LK(param_1 + 4,'\x01');
    return;
  case '0':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_LM(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_LM(param_1 + 4,'\x01');
    return;
  case '1':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_MA();
    return;
  case '2':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_MB();
    return;
  case '3':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MC(param_1 + 4,0);
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_MC(param_1 + 4,1);
    return;
  case '4':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_MD(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_MD(param_1 + 4,'\x01');
    return;
  case '5':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MG(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_MG(param_1 + 4,'\x01');
    return;
  case '6':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_ML(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_ML(param_1 + 4,'\x01');
    return;
  case '7':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_MR(param_1 + 4,0);
    return;
  case '8':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_MS(param_1 + 4,'\x01');
    return;
  case '9':
    _DAT_00001c92 = CONCAT31((undefined3)DAT_00001c93,*(undefined1 *)(param_1 + 8));
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 6) {
      cat_MT(param_1 + 4,'\0',6);
      return;
    }
    if ((param_3 < 8) || (0x13 < param_3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_MT(param_1 + 4,'\x01',param_3);
    return;
  case ':':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 0x1c) {
      DAT_0000464a = 1;
      return;
    }
    cat_MW(param_1 + 4,1);
    return;
  case ';':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_MX(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_MX(param_1 + 4,'\x01');
    return;
  case '<':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NA(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_NA(param_1 + 4,'\x01');
    return;
  case '=':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NB(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_NB(param_1 + 4,'\x01');
    return;
  case '>':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NL(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_NL(param_1 + 4,'\x01');
    return;
  case '?':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_NR(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_NR(param_1 + 4,'\x01');
    return;
  case 'A':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_OS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_OS(param_1 + 4,'\x01');
    return;
  case 'B':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_PA(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_PA(param_1 + 4,'\x01');
    return;
  case 'C':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_PB(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_PB(param_1 + 4,'\x01');
    return;
  case 'D':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_PC(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_PC(param_1 + 4,'\x01');
    return;
  case 'E':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_PL(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_PL(param_1 + 4,'\x01');
    return;
  case 'F':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_PR(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_PR(param_1 + 4,'\x01');
    return;
  case 'G':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_PS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_PS(param_1 + 4,'\x01');
    return;
  case 'H':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_QI();
    return;
  case 'I':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_QR();
    return;
  case 'J':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_QS();
    return;
  case 'K':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_RA(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_RA(param_1 + 4,'\x01');
    return;
  case 'N':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_RG(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_RG(param_1 + 4,'\x01');
    return;
  case 'O':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_RI(param_1 + 4);
    return;
  case 'P':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_RL(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_RL(param_1 + 4,'\x01');
    return;
  case 'Q':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_RM(param_1 + 4);
    return;
  case 'U':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_SC(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_SC(param_1 + 4,'\x01');
    return;
  case 'V':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_SD(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_SD(param_1 + 4,'\x01');
    return;
  case 'W':
    _DAT_00001c8e =
         CONCAT22(CONCAT11(uVar2,*(undefined1 *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_SF(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_SF(param_1 + 4,'\x01');
    return;
  case 'X':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_SH(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_SH(param_1 + 4,'\x01');
    return;
  case 'Y':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_SM(param_1 + 4);
    return;
  case 'Z':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 4) {
      cat_SQ(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 7) {
      DAT_0000464a = 1;
      return;
    }
    cat_SQ(param_1 + 4,'\x01');
    return;
  case '[':
    _DAT_00001c8e = *(undefined4 *)(param_1 + 4);
    if (param_3 == 5) {
      cat_SS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 10) {
      DAT_0000464a = 1;
      return;
    }
    cat_SS(param_1 + 4,'\x01');
    return;
  case '\\':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_ST(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_ST(param_1 + 4,'\x01');
    return;
  case ']':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_SV(param_1 + 4,1);
    return;
  case '^':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_TS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_TS(param_1 + 4,'\x01');
    return;
  case '_':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_TX(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_TX(param_1 + 4,'\x01');
    return;
  case '`':
    if (param_3 != 3) {
      DAT_0000464a = 1;
      return;
    }
    cat_UP();
    return;
  case 'a':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VD(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 5) {
      DAT_0000464a = 1;
      return;
    }
    cat_VD(param_1 + 4,'\x01');
    return;
  case 'b':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VG(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 6) {
      DAT_0000464a = 1;
      return;
    }
    cat_VG(param_1 + 4,'\x01');
    return;
  case 'c':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if ((param_3 == 4) || (param_3 == 3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (param_3 == 6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      DAT_0000464a = 1;
      return;
    }
    cat_VM(param_1 + 4,param_3);
    return;
  case 'd':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VS(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_VS(param_1 + 4,'\x01');
    return;
  case 'e':
    _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
    if (param_3 == 3) {
      cat_VX(param_1 + 4,'\0');
      return;
    }
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_VX(param_1 + 4,'\x01');
    return;
  case 'g':
    if (param_3 != 4) {
      DAT_0000464a = 1;
      return;
    }
    cat_ZI(param_1 + 4);
    return;
  }
  _DAT_00001c8e = CONCAT22(_DAT_00001c90,*(undefined2 *)(param_1 + 4));
  if (param_3 == 3) {
    cat_AC(param_1 + 4,'\0');
    return;
  }
  if (param_3 != 6) {
    DAT_0000464a = 1;
    return;
  }
  cat_AC(param_1 + 4,'\x01');
  return;
}


// ===== cat_SP_sdr_reg @ fffa4e31 (94 bytes)

/* SPS R/W: SDR register read/write (4-hex addr at text+4, 4-hex value at text+8) */

void cat_SP_sdr_reg(uint param_1,char param_2)

{
  byte bVar1;
  ushort uStack_a;
  ushort uStack_8;
  char local_5;
  uint local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uStack_8 = hex2word((char *)(param_1 + 4));
  uStack_a = hex2word((char *)(local_4 + 8));
  bVar1 = sdr_reg_access(uStack_8,&uStack_a,local_5);
  if (bVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (local_5 != '\0') {
    return;
  }
  word2hex(0x1c92,uStack_a);
  DAT_00001c93._3_1_ = 0x3b;
  DAT_0001b788 = 9;
  return;
}


// ===== cat_SP_dev4_reg @ fffa4e8f (94 bytes)

/* SPD R/W: SCI4 device register read/write */

void cat_SP_dev4_reg(uint param_1,char param_2)

{
  byte bVar1;
  ushort uStack_a;
  ushort uStack_8;
  char local_5;
  uint local_4;
  
  local_5 = param_2;
  local_4 = param_1;
  uStack_8 = hex2word((char *)(param_1 + 4));
  uStack_a = hex2word((char *)(local_4 + 8));
  bVar1 = dsp_reg_access(uStack_8,&uStack_a,local_5);
  if (bVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (local_5 != '\0') {
    return;
  }
  word2hex(0x1c92,uStack_a);
  DAT_00001c93._3_1_ = 0x3b;
  DAT_0001b788 = 9;
  return;
}


// ===== cat_SP_adc_dump @ fffa4eed (524 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SPIR: 12 ADC results (0x20B04..0x20B16) as 3 hex digits each */

void cat_SP_adc_dump(void)

{
  undefined1 uStack_6;
  undefined2 uStack_5;
  undefined1 uStack_3;
  ushort local_2;
  
  local_2 = 0;
  word2hex((int)&uStack_6,0);
  DAT_00001c93._1_1_ = uStack_3;
  _DAT_00001c92 = uStack_5;
  local_2 = DAT_00020b04;
  word2hex((int)&uStack_6,DAT_00020b04);
  DAT_00001c97 = uStack_3;
  DAT_00001c93._2_2_ = uStack_5;
  local_2 = DAT_00020b06;
  word2hex((int)&uStack_6,DAT_00020b06);
  uRam00001c9a = uStack_3;
  _DAT_00001c98 = uStack_5;
  local_2 = DAT_00020b08;
  word2hex((int)&uStack_6,DAT_00020b08);
  DAT_00001c9d = uStack_3;
  uRam00001c9b = uStack_5;
  local_2 = 0;
  word2hex((int)&uStack_6,0);
  DAT_00001ca0 = uStack_3;
  uRam00001c9e = uStack_5;
  local_2 = DAT_00020b0c;
  word2hex((int)&uStack_6,DAT_00020b0c);
  DAT_00001ca3 = uStack_3;
  _DAT_00001ca1 = uStack_5;
  local_2 = 0;
  word2hex((int)&uStack_6,0);
  DAT_00001ca6 = uStack_3;
  _DAT_00001ca4 = uStack_5;
  local_2 = DAT_00020b0e;
  word2hex((int)&uStack_6,DAT_00020b0e);
  DAT_00001ca9 = uStack_3;
  _DAT_00001ca7 = uStack_5;
  local_2 = DAT_00020b14;
  word2hex((int)&uStack_6,DAT_00020b14);
  uRam00001cac = uStack_3;
  uRam00001caa = uStack_5;
  local_2 = DAT_00020b16;
  word2hex((int)&uStack_6,DAT_00020b16);
  uRam00001caf = uStack_3;
  uRam00001cad = uStack_5;
  local_2 = DAT_00020b10;
  word2hex((int)&uStack_6,DAT_00020b10);
  uRam00001cb2 = uStack_3;
  uRam00001cb0 = uStack_5;
  local_2 = DAT_00020b12;
  word2hex((int)&uStack_6,DAT_00020b12);
  uRam00001cb5 = uStack_3;
  uRam00001cb3 = uStack_5;
  uRam00001cb6 = 0x3b;
  DAT_0001b788 = 0x29;
  return;
}


// ===== cat_SP_table @ fffa50f9 (274 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa51a6) */
/* WARNING: Removing unreachable block (ram,0xfffa511d) */
/* WARNING: Removing unreachable block (ram,0xfffa5208) */
/* WARNING: Removing unreachable block (ram,0xfffa512e) */
/* WARNING: Removing unreachable block (ram,0xfffa5144) */
/* WARNING: Removing unreachable block (ram,0xfffa5158) */
/* WARNING: Removing unreachable block (ram,0xfffa5205) */
/* WARNING: Removing unreachable block (ram,0xfffa51d1) */
/* SPN R/W/S (binary): table 0x4659[1..0x105] */

void cat_SP_table(int param_1,char param_2,short param_3)

{
  bool bVar1;
  ushort uVar2;
  
  bVar1 = cat_checksum_ok(param_1,param_3 - 2);
  if (!bVar1) {
    DAT_0000464a = 1;
    return;
  }
  uVar2 = CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  if (uVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (0x105 < uVar2) {
    DAT_0000464a = 1;
    return;
  }
  uVar2 = uVar2 - 1;
  if (param_2 != '\0') {
    if ((*(char *)(param_1 + 3) == 'W') || (*(char *)(param_1 + 3) == 'w')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      (&DAT_00004659)[uVar2] = *(undefined1 *)(param_1 + 6);
      return;
    }
    if ((*(char *)(param_1 + 3) == 'S') || (*(char *)(param_1 + 3) == 's')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      return;
    }
    swtimer_start(0x32,500);
    DAT_0000464b = 1;
    return;
  }
  DAT_00020ce2 = uVar2;
  FUN_fffbb567();
  DAT_00001c91 = (&DAT_00004659)[uVar2];
  DAT_00001c92 = sum8(0x1c8e,4);
  DAT_00001c93._0_1_ = 0x3b;
  DAT_0001b788 = 6;
  return;
}


// ===== cat_SP_eeprom_byte @ fffa520b (121 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5268) */
/* WARNING: Removing unreachable block (ram,0xfffa5217) */
/* WARNING: Removing unreachable block (ram,0xfffa5281) */
/* SPR/SPW (binary): EEPROM byte read/write at 16-bit address */

void cat_SP_eeprom_byte(int param_1,char param_2)

{
  byte local_d;
  ushort local_c;
  char local_9;
  int local_8;
  
  local_c = CONCAT11(*(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
  local_d = *(byte *)(param_1 + 5);
  local_9 = param_2;
  local_8 = param_1;
  if (param_2 != '\0') {
    eeprom_write_raw(local_c,(uint)&local_d,1);
    *(byte *)((int)&DAT_0000464f + (uint)local_c) = local_d;
    return;
  }
  eeprom_read_raw(local_c,&local_d,1);
  DAT_00001c93._0_1_ = local_d;
  DAT_00001c93._1_1_ = sum8(0x1c8e,6);
  DAT_00001c93._2_1_ = 0x3b;
  DAT_0001b788 = 8;
  return;
}


// ===== cat_SP_meters @ fffa5284 (288 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5284) */
/* WARNING: Removing unreachable block (ram,0xfffa53a1) */
/* SPM (binary): 8 meter bytes + checksum */

void cat_SP_meters(void)

{
  DAT_00001c91 = meter_get_s();
  DAT_00001c92 = 0;
  DAT_00001c93._0_1_ = meter_get_po();
  DAT_00001c93._1_1_ = meter_get_swr();
  DAT_00001c93._2_1_ = meter_get_comp();
  DAT_00001c93._3_1_ = meter_get_alc();
  DAT_00001c97 = meter_get_vdd();
  DAT_00001c98 = meter_get_idd();
  DAT_00001c99 = 0;
  uRam00001c9a = 0;
  uRam00001c9b = 0;
  DAT_00001c9c = sum8(0x1c8e,0xe);
  DAT_00001c9d = 0x3b;
  DAT_0001b788 = 0x10;
  return;
}


// ===== cat_ext_E8 @ fffa53a4 (271 bytes)

void cat_ext_E8(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  char cStack_a;
  ushort uStack_8;
  
  cVar1 = cat_rand8();
  cStack_a = '\0';
  DAT_00001c91 = cVar1 + '\a';
  DAT_00001c92 = cVar1 + -0x70;
  puVar3 = &DAT_000060c9;
  puVar2 = (undefined1 *)((int)&DAT_00001c93 + 2);
  DAT_00001c90 = cVar1;
  DAT_00001c93._0_1_ = cVar1;
  DAT_00001c93._1_1_ = cVar1;
  for (puVar4 = &DAT_000029a9; puVar4 != (undefined *)0x0; puVar4 = puVar4 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uStack_8 = 0; uStack_8 < 0x29a9; uStack_8 = uStack_8 + 1) {
    cStack_a = *(char *)((int)&DAT_00001c93 + uStack_8 + 2) + cStack_a;
    *(char *)((int)&DAT_00001c93 + uStack_8 + 2) =
         *(char *)((int)&DAT_00001c93 + uStack_8 + 2) + cVar1;
  }
  cRam0000463e = cStack_a + cVar1;
  uRam0000463f = 0x3b;
  DAT_0001b788 = 0x29b2;
  return;
}


// ===== cat_ext_VE @ fffa54b3 (184 bytes)

void cat_ext_VE(char param_1)

{
  undefined4 uStack_8;
  
  if (param_1 == '\0') {
    uStack_8 = ver_main();
  }
  else if (param_1 == '\x01') {
    uStack_8 = ver_display();
  }
  else if (param_1 == '\x02') {
    uStack_8 = ver_sdr();
  }
  else {
    if (param_1 != '\x03') {
      DAT_0000464a = 1;
      return;
    }
    uStack_8 = ver_dsp();
  }
  DAT_00001c91 = *(undefined1 *)(uStack_8 + 1);
  DAT_00001c92 = *(undefined1 *)(uStack_8 + 2);
  DAT_00001c93._0_1_ = *(undefined1 *)(uStack_8 + 4);
  DAT_00001c93._1_1_ = *(undefined1 *)(uStack_8 + 5);
  DAT_00001c93._2_1_ = 0x3b;
  DAT_0001b788 = 8;
  return;
}


// ===== cat_ext_JP @ fffa556b (822 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5810) */

void cat_ext_JP(uint param_1,char param_2)

{
  bool bVar1;
  char cStack_14;
  undefined1 uStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  ushort uStack_e;
  byte *local_c;
  char local_5;
  uint local_4;
  
  local_c = (byte *)&DAT_0000464f;
  local_5 = param_2;
  local_4 = param_1;
  uStack_e = hex2word((char *)(param_1 + 2));
  if (uStack_e != 0x710) {
    DAT_0000464a = 1;
    return;
  }
  if (local_5 != '\0') {
    bStack_f = hex2byte((char *)(local_4 + 6));
    bStack_10 = hex2byte((char *)(local_4 + 8));
    bStack_11 = hex2byte((char *)(local_4 + 10));
    bStack_12 = hex2byte((char *)(local_4 + 0xc));
    bStack_11 = ~bStack_11;
    bStack_12 = ~bStack_12;
    if ((bStack_f == bStack_11) && (bStack_10 == bStack_12)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    uStack_e = CONCAT11(bStack_f,bStack_10);
    if (uStack_e == 0x306f) {
      uStack_e = 0xd32d;
    }
    else if (uStack_e == 0xb5a7) {
      uStack_e = 0xa983;
    }
    else if (uStack_e == 0x9cf7) {
      uStack_e = 0x7753;
    }
    else if (uStack_e == 0xa4c5) {
      uStack_e = 0xd950;
    }
    else if (uStack_e == 0x50e2) {
      uStack_e = 0x315b;
    }
    *local_c = DAT_00020bb1;
    local_c[1] = DAT_00020bb2;
    local_c[2] = DAT_00020bb3;
    local_c[3] = DAT_00020bb4;
    local_c[4] = DAT_00020bb5;
    dest_code_set(uStack_e);
    return;
  }
  uStack_e = dest_code_get();
  bStack_f = (byte)(uStack_e >> 8);
  bStack_10 = (byte)uStack_e;
  byte2hex(&cStack_14,bStack_f);
  DAT_00001c93._1_1_ = cStack_14;
  DAT_00001c93._2_1_ = uStack_13;
  byte2hex(&cStack_14,bStack_10);
  DAT_00001c93._3_1_ = cStack_14;
  DAT_00001c97 = uStack_13;
  byte2hex(&cStack_14,~bStack_f);
  DAT_00001c98 = cStack_14;
  DAT_00001c99 = uStack_13;
  byte2hex(&cStack_14,~bStack_10);
  cRam00001c9a = cStack_14;
  uRam00001c9b = uStack_13;
  byte2hex(&cStack_14,*local_c);
  DAT_00001c9c = cStack_14;
  DAT_00001c9d = uStack_13;
  byte2hex(&cStack_14,local_c[1]);
  cRam00001c9e = cStack_14;
  uRam00001c9f = uStack_13;
  byte2hex(&cStack_14,local_c[2]);
  DAT_00001ca0 = cStack_14;
  DAT_00001ca1 = uStack_13;
  byte2hex(&cStack_14,local_c[3]);
  DAT_00001ca2 = cStack_14;
  DAT_00001ca3 = uStack_13;
  byte2hex(&cStack_14,local_c[4]);
  DAT_00001ca4 = cStack_14;
  DAT_00001ca5 = uStack_13;
  DAT_00001ca6 = 0x3b;
  DAT_0001b788 = 0x19;
  return;
}


// ===== cat_ext_ZZ @ fffa58a1 (228 bytes)

void cat_ext_ZZ(int param_1)

{
  bool bVar1;
  byte bVar2;
  undefined2 local_9;
  byte local_7;
  ushort uStack_6;
  int local_4;
  
  local_9 = *(undefined2 *)(param_1 + 2);
  local_4 = param_1;
  for (local_7 = 0; local_7 < 2; local_7 = local_7 + 1) {
    toupper_inplace((char *)((int)&local_9 + (uint)local_7));
  }
  if (((char)local_9 == 'P') && (local_9._1_1_ == 'E')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  uStack_6 = hex2word((char *)(local_4 + 4));
  if (uStack_6 != 0x710) {
    DAT_0000464a = 1;
    return;
  }
  bVar2 = hex2byte((char *)(local_4 + 8));
  if (bVar2 != 0x99) {
    if (bVar2 == 1) {
      settings_defaults(0);
      DAT_00020f4b = 1;
      DAT_00020b39 = 0x11;
      return;
    }
    if (bVar2 == 0) {
      DAT_00020bbe = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  settings_defaults(1);
  eeprom_save_cfg105();
  eeprom_save_dest();
  DAT_00020f4b = 1;
  DAT_00020b39 = 0x11;
  return;
}


// ===== cat_ext_E9 @ fffa5985 (204 bytes)

/* Extended E9, reached only from the second input path in cat_parse */

void cat_ext_E9(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  char local_e;
  ushort local_c;
  
  bVar1 = *(byte *)(param_1 + 2);
  bVar2 = *(byte *)(param_1 + 3);
  bVar3 = *(byte *)(param_1 + 4);
  local_e = '\0';
  for (local_c = 0; local_c < 0x29a9; local_c = local_c + 1) {
    *(byte *)(local_c + 7 + param_1) = *(char *)(local_c + 7 + param_1) - bVar1;
    local_e = *(char *)(local_c + 7 + param_1) + local_e;
  }
  if ((ushort)((ushort)bVar3 - (ushort)bVar1 & 0xff | ((ushort)bVar2 - (ushort)bVar1) * 0x100) ==
      0x790) {
    if ((byte)((&DAT_000029b0)[param_1] - bVar1) == local_e) {
      puVar4 = &DAT_000060c9;
      puVar5 = (undefined1 *)(param_1 + 7);
      for (puVar6 = &DAT_000029a9; puVar6 != (undefined *)0x0; puVar6 = puVar6 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      eeprom_save_image();
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_ext_FD @ fffa5a51 (575 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5be8) */
/* WARNING: Removing unreachable block (ram,0xfffa5c39) */
/* WARNING: Removing unreachable block (ram,0xfffa5c76) */
/* WARNING: Removing unreachable block (ram,0xfffa5c51) */
/* WARNING: Removing unreachable block (ram,0xfffa5c81) */
/* WARNING: Removing unreachable block (ram,0xfffa5b46) */
/* WARNING: Removing unreachable block (ram,0xfffa5b0b) */
/* WARNING: Removing unreachable block (ram,0xfffa5ad6) */
/* WARNING: Removing unreachable block (ram,0xfffa5a94) */
/* WARNING: Removing unreachable block (ram,0xfffa5bb3) */
/* WARNING: Removing unreachable block (ram,0xfffa5c8d) */
/* WARNING: Removing unreachable block (ram,0xfffa5b7b) */
/* WARNING: Removing unreachable block (ram,0xfffa5bf4) */

void cat_ext_FD(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  uint freq;
  void *pvVar4;
  byte bStack_17;
  uint uStack_14;
  void *pvStack_10;
  
  freq = vfo_freq(0,2);
  band_of_freq(freq);
  cVar2 = *(char *)(param_1 + 4);
  if ((*(char *)(param_1 + 2) == '0') && (*(char *)(param_1 + 3) == '0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (param_2 != '\0') {
    if (cVar2 != '2') {
      DAT_0000464a = 1;
      return;
    }
    pvStack_10 = (void *)0x0;
    uStack_14 = 100000000;
    bStack_17 = 5;
    while( true ) {
      if (0xd < bStack_17) {
        bVar3 = freq_in_range(pvStack_10);
        if (bVar3 != 0) {
          bandmem_set('\x02',(uint)pvStack_10);
          return;
        }
        DAT_0000464a = 1;
        return;
      }
      if ((*(byte *)((uint)bStack_17 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_17 + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) break;
      pvStack_10 = (void *)((*(byte *)((uint)bStack_17 + param_1) & 0xf) * uStack_14 +
                           (int)pvStack_10);
      uStack_14 = uStack_14 / 10;
      bStack_17 = bStack_17 + 1;
    }
    DAT_0000464a = 1;
    return;
  }
  if (cVar2 == '0') {
    pvStack_10 = (void *)DAT_00020f5c;
    uStack_14 = 100000000;
    for (bStack_17 = 0; bStack_17 < 9; bStack_17 = bStack_17 + 1) {
      if (uStack_14 == 0) {
        bVar3 = (byte)pvStack_10;
        pvVar4 = pvStack_10;
      }
      else {
        bVar3 = (byte)((uint)pvStack_10 / uStack_14);
        pvVar4 = (void *)((uint)pvStack_10 / uStack_14);
      }
      pvStack_10 = (void *)((int)pvStack_10 - (int)pvVar4 * uStack_14);
      uStack_14 = uStack_14 / 10;
      cVar2 = nib2hex(bVar3);
      *(char *)((int)&DAT_00001c93 + (uint)bStack_17) = cVar2;
    }
    DAT_00001c9c = 0x3b;
    DAT_0001b788 = 0xf;
    return;
  }
  if (cVar2 == '1') {
    pvStack_10 = (void *)DAT_00020f60;
    uStack_14 = 100000000;
    for (bStack_17 = 0; bStack_17 < 9; bStack_17 = bStack_17 + 1) {
      if (uStack_14 == 0) {
        bVar3 = (byte)pvStack_10;
        pvVar4 = pvStack_10;
      }
      else {
        bVar3 = (byte)((uint)pvStack_10 / uStack_14);
        pvVar4 = (void *)((uint)pvStack_10 / uStack_14);
      }
      pvStack_10 = (void *)((int)pvStack_10 - (int)pvVar4 * uStack_14);
      uStack_14 = uStack_14 / 10;
      cVar2 = nib2hex(bVar3);
      *(char *)((int)&DAT_00001c93 + (uint)bStack_17) = cVar2;
    }
    DAT_00001c9c = 0x3b;
    DAT_0001b788 = 0xf;
    return;
  }
  if (cVar2 != '2') {
    DAT_0000464a = 1;
    return;
  }
  pvStack_10 = (void *)bandmem_get('\x02');
  uStack_14 = 100000000;
  for (bStack_17 = 0; bStack_17 < 9; bStack_17 = bStack_17 + 1) {
    if (uStack_14 == 0) {
      bVar3 = (byte)pvStack_10;
      pvVar4 = pvStack_10;
    }
    else {
      bVar3 = (byte)((uint)pvStack_10 / uStack_14);
      pvVar4 = (void *)((uint)pvStack_10 / uStack_14);
    }
    pvStack_10 = (void *)((int)pvStack_10 - (int)pvVar4 * uStack_14);
    uStack_14 = uStack_14 / 10;
    cVar2 = nib2hex(bVar3);
    *(char *)((int)&DAT_00001c93 + (uint)bStack_17) = cVar2;
  }
  DAT_00001c9c = 0x3b;
  DAT_0001b788 = 0xf;
  return;
}


// ===== cat_ext_EO @ fffa5c90 (847 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa5f4e) */
/* WARNING: Removing unreachable block (ram,0xfffa5e8a) */
/* WARNING: Removing unreachable block (ram,0xfffa5d68) */

void cat_ext_EO(int param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  byte *pbVar4;
  uint uVar5;
  undefined *puStack_18;
  uint uStack_14;
  ushort uStack_e;
  byte bStack_8;
  byte bStack_7;
  byte bStack_6;
  
  pbVar4 = vfo_rec_ptr(0);
  bVar2 = hex2nib(*(byte *)(param_1 + 2));
  if (2 < bVar2) {
    DAT_0000464a = 1;
    return;
  }
  DAT_00020f3b = 0;
  DAT_00020b8a = 0;
  DAT_00020b99 = 0;
  DAT_00020bbe = 0;
  DAT_00020b97 = 0;
  DAT_00020b98 = 0;
  DAT_00020b9a = 0;
  DAT_00020b9b = 0;
  if (*(char *)(param_1 + 3) == '0') {
    uVar5 = vfo_freq(0,2);
    uStack_e = 0;
    bStack_7 = 100;
    for (bStack_8 = 6; bStack_8 < 9; bStack_8 = bStack_8 + 1) {
      bVar2 = *(byte *)((uint)bStack_8 + param_1);
      if ((bVar2 < 0x30) || (0x39 < bVar2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      cVar3 = hex2nib(bVar2);
      uStack_e = (short)cVar3 * (ushort)bStack_7 + uStack_e;
      bStack_7 = bStack_7 / 10;
    }
    if (*(char *)(param_1 + 5) == '0') {
      uStack_14 = (uint)uStack_e;
    }
    else if (*(char *)(param_1 + 5) == '1') {
      uStack_14 = (uint)uStack_e * 1000;
    }
    else if (*(char *)(param_1 + 5) == '2') {
      uStack_14 = (uint)uStack_e * 1000000;
    }
    if (*(char *)(param_1 + 4) == '+') {
      puStack_18 = (undefined *)(uVar5 + uStack_14);
    }
    else {
      if (*(char *)(param_1 + 4) != '-') {
        DAT_0000464a = 1;
        return;
      }
      if (uVar5 < uStack_14) {
        puStack_18 = (undefined *)0x0;
      }
      else {
        puStack_18 = (undefined *)(uVar5 - uStack_14);
      }
    }
    if (puStack_18 < &DAT_00007530) {
      puStack_18 = &DAT_00007530;
    }
    else if ((undefined *)0x47868c0 < puStack_18) {
      puStack_18 = (undefined *)0x47868c0;
    }
    for (bStack_8 = 0; bStack_8 < 4; bStack_8 = bStack_8 + 1) {
      pbVar4[bStack_8 + 0x4a] = (byte)((uint)puStack_18 >> ((3 - bStack_8 & 3) << 3));
    }
  }
  else if (*(char *)(param_1 + 3) == '1') {
    bStack_6 = 0;
    bStack_7 = 100;
    for (bStack_8 = 6; bStack_8 < 9; bStack_8 = bStack_8 + 1) {
      if ((*(byte *)((uint)bStack_8 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_8 + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      cVar3 = hex2nib(*(byte *)((uint)bStack_8 + param_1));
      bStack_6 = cVar3 * bStack_7 + bStack_6;
      bStack_7 = bStack_7 / 10;
    }
    if (*(char *)(param_1 + 4) == '+') {
      if (0x7f < bStack_6) {
        DAT_0000464a = 1;
        return;
      }
      enc2_step(bStack_6);
    }
    else if (*(char *)(param_1 + 4) == '-') {
      if ('\0' < (char)(~bStack_6 + 1)) {
        DAT_0000464a = 1;
        return;
      }
      enc2_step(~bStack_6 + 1);
    }
  }
  else if (*(char *)(param_1 + 3) == '2') {
    bStack_6 = 0;
    bStack_7 = 100;
    for (bStack_8 = 6; bStack_8 < 9; bStack_8 = bStack_8 + 1) {
      if ((*(byte *)((uint)bStack_8 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_8 + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      cVar3 = hex2nib(*(byte *)((uint)bStack_8 + param_1));
      bStack_6 = cVar3 * bStack_7 + bStack_6;
      bStack_7 = bStack_7 / 10;
    }
    DAT_00020f3b = 0;
    DAT_00020bbe = 0;
    DAT_00020b74 = 1;
    if (*(char *)(param_1 + 4) == '+') {
      if (0x7f < bStack_6) {
        DAT_0000464a = 1;
        return;
      }
      enc3_step(bStack_6);
    }
    else if (*(char *)(param_1 + 4) == '-') {
      if ('\0' < (char)(~bStack_6 + 1)) {
        DAT_0000464a = 1;
        return;
      }
      enc3_step(~bStack_6 + 1);
    }
  }
  DAT_00020f10 = 1;
  return;
}


// ===== cat_ext_PE @ fffa5fdf (1166 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6276) */
/* WARNING: Removing unreachable block (ram,0xfffa63e8) */
/* WARNING: Removing unreachable block (ram,0xfffa6378) */
/* WARNING: Removing unreachable block (ram,0xfffa62d6) */
/* WARNING: Removing unreachable block (ram,0xfffa6390) */
/* WARNING: Removing unreachable block (ram,0xfffa6400) */
/* WARNING: Removing unreachable block (ram,0xfffa6467) */
/* WARNING: Removing unreachable block (ram,0xfffa6224) */
/* WARNING: Removing unreachable block (ram,0xfffa646a) */
/* WARNING: Removing unreachable block (ram,0xfffa6327) */

void cat_ext_PE(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte *local_14;
  byte local_e;
  byte local_b;
  byte local_a;
  
  if (*(char *)(param_1 + 2) == '0') {
    if (*(char *)(param_1 + 3) == '0') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ada;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009adb;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009adc;
      }
    }
    else if (*(char *)(param_1 + 3) == '1') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009add;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ade;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009adf;
      }
    }
    else if (*(char *)(param_1 + 3) == '2') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae0;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ae1;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009ae2;
      }
    }
  }
  if (*(char *)(param_1 + 2) == '2') {
    if (*(char *)(param_1 + 3) == '0') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae3;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ae4;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009ae5;
      }
    }
    else if (*(char *)(param_1 + 3) == '1') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae6;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009ae7;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009ae8;
      }
    }
    else if (*(char *)(param_1 + 3) == '2') {
      if (*(char *)(param_1 + 4) == '0') {
        local_14 = &DAT_00009ae9;
      }
      else if (*(char *)(param_1 + 4) == '1') {
        local_14 = &DAT_00009aea;
      }
      else if (*(char *)(param_1 + 4) == '2') {
        local_14 = &DAT_00009aeb;
      }
    }
  }
  bVar1 = *(char *)(param_1 + 4) == '0';
  if (param_2 == '\0') {
    if ((bVar1) || (*(char *)(param_1 + 4) == '2')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_a = 100;
      local_e = *local_14;
      for (local_b = 0; local_b < 3; local_b = local_b + 1) {
        bVar3 = local_e;
        if (local_a != 0) {
          bVar3 = local_e / local_a;
        }
        local_e = local_e - bVar3 * local_a;
        local_a = local_a / 10;
        cVar2 = nib2hex(bVar3);
        *(char *)((int)&DAT_00001c93 + (uint)local_b) = cVar2;
      }
      *(undefined1 *)((int)&DAT_00001c93 + (uint)local_b) = 0x3b;
      DAT_0001b788 = (byte)(local_b + 1) + 5;
      return;
    }
    if (*(char *)(param_1 + 4) == '1') {
      local_e = *local_14;
      if ((local_e & 0x80) == 0) {
        DAT_00001c93._0_1_ = 0x2b;
      }
      else {
        DAT_00001c93._0_1_ = 0x2d;
        local_e = ~local_e + 1;
      }
      local_a = 10;
      for (local_b = 0; local_b < 2; local_b = local_b + 1) {
        bVar3 = local_e;
        if (local_a != 0) {
          bVar3 = local_e / local_a;
        }
        local_e = local_e - bVar3 * local_a;
        local_a = local_a / 10;
        cVar2 = nib2hex(bVar3);
        *(char *)((int)&DAT_00001c93 + local_b + 1) = cVar2;
      }
      *(undefined1 *)((int)&DAT_00001c93 + local_b + 1) = 0x3b;
      DAT_0001b788 = (byte)(local_b + 1) + 6;
      return;
    }
  }
  else {
    if ((bVar1) || (*(char *)(param_1 + 4) == '2')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_a = 100;
      for (local_b = 5; local_b < 8; local_b = local_b + 1) {
        if ((*(byte *)((uint)local_b + param_1) < 0x30) ||
           (0x39 < *(byte *)((uint)local_b + param_1))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_0000464a = 1;
          return;
        }
        cVar2 = hex2nib(*(byte *)((uint)local_b + param_1));
        local_e = cVar2 * local_a + local_e;
        local_a = local_a / 10;
      }
      *local_14 = local_e;
    }
    else if (*(char *)(param_1 + 4) == '1') {
      local_a = 10;
      for (local_b = 6; local_b < 8; local_b = local_b + 1) {
        if ((*(byte *)((uint)local_b + param_1) < 0x30) ||
           (0x39 < *(byte *)((uint)local_b + param_1))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_0000464a = 1;
          return;
        }
        cVar2 = hex2nib(*(byte *)((uint)local_b + param_1));
        local_e = cVar2 * local_a + local_e;
        local_a = local_a / 10;
      }
      if (*(char *)(param_1 + 5) == '-') {
        local_e = ~local_e + 1;
      }
      *local_14 = local_e;
    }
    if ((DAT_00020b20 == '\x01') || (DAT_00020b21 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b22 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      cat_ai_holdoff();
      return;
    }
  }
  return;
}


// ===== cat_AB @ fffa646d (359 bytes)

void cat_AB(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    bVar2 = vfo_tune_locked('\x01');
    if (bVar2 == 1) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00009dbf = 1;
    puVar4 = &DAT_00009d09;
    puVar3 = &DAT_00009d63;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    vfo_mark_edited(1);
    vfo_store_back(1);
    DAT_00020f10 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AC @ fffa65d4 (659 bytes)

void cat_AC(int param_1,char param_2)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  
  vfo_rec_ptr(0);
  cVar3 = DAT_00009ab8;
  if (param_2 == '\0') {
    DAT_00001c90 = 0x30;
    if (DAT_00009ab8 == '\x03') {
      DAT_00001c91 = 0x32;
      if (DAT_00020f0c == '\0') {
        DAT_00001c92 = '0';
      }
      else if (DAT_00020f0c == '\x02') {
        if (DAT_00020b3c == '\x02') {
          DAT_00001c92 = '1';
        }
        else if (DAT_00020b3c == '\x03') {
          DAT_00001c92 = '2';
        }
      }
      else if (DAT_00020f0c == '\x01') {
        DAT_00001c92 = '3';
      }
    }
    else {
      DAT_00001c91 = 0x30;
      if (DAT_00020b41 == '\x02') {
        DAT_00001c92 = '3';
      }
      else {
        bVar4 = FUN_fffec55a();
        DAT_00001c92 = nib2hex(bVar4);
      }
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    bVar4 = key_event_filter(0x301,0);
    if (bVar4 == 0) {
      DAT_0000464a = 1;
      return;
    }
    cVar1 = *(char *)(param_1 + 3);
    if (cVar1 == '2') {
      if (cVar3 != '\x03') {
        DAT_0000464a = 1;
        return;
      }
      if (*(char *)(param_1 + 4) == '0') {
        FUN_fffed24e(0);
      }
      else if (*(char *)(param_1 + 4) == '1') {
        FUN_fffed206(2);
        FUN_fffed24e(1);
      }
      else if (*(char *)(param_1 + 4) == '2') {
        FUN_fffed206(2);
        FUN_fffed24e(2);
      }
      else {
        if (*(char *)(param_1 + 4) != '3') {
          DAT_0000464a = 1;
          return;
        }
        FUN_fffed206(1);
      }
    }
    else if (cVar1 != '1') {
      if (cVar1 == '0') {
        if ((cVar3 == '\0') || (cVar3 == '\x01')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          if (*(char *)(param_1 + 4) == '0') {
            FUN_fffec537(0);
            DAT_00020b3f = 3;
          }
          else if (*(char *)(param_1 + 4) == '1') {
            FUN_fffec537(1);
            DAT_00020b3f = 1;
          }
          else {
            if (*(char *)(param_1 + 4) != '3') {
              DAT_0000464a = 1;
              return;
            }
            if (DAT_00020b3d == '\0') {
              DAT_00020b41 = '\x01';
            }
          }
        }
        else {
          if (cVar3 != '\x02') {
            DAT_0000464a = 1;
            return;
          }
          if (*(char *)(param_1 + 4) == '0') {
            FUN_fffec537(0);
            DAT_00020b3f = 6;
          }
          else if (*(char *)(param_1 + 4) == '1') {
            FUN_fffec537(1);
            DAT_00020b3f = 4;
          }
          else {
            if (*(char *)(param_1 + 4) != '3') {
              DAT_0000464a = 1;
              return;
            }
            DAT_00020b40 = 1;
          }
        }
      }
      else {
        DAT_0000464a = 1;
      }
    }
    cat_ai_ex_holdoff();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AG @ fffa6867 (223 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa68d6) */
/* WARNING: Removing unreachable block (ram,0xfffa6927) */
/* WARNING: Removing unreachable block (ram,0xfffa6911) */
/* WARNING: Removing unreachable block (ram,0xfffa68a1) */
/* WARNING: Removing unreachable block (ram,0xfffa6943) */

void cat_AG(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_d = DAT_00020ba8;
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      n = local_d;
      if (local_b != 0) {
        n = local_d / local_b;
      }
      local_d = local_d - n * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(n);
      (&DAT_00001c91)[local_c] = cVar2;
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return;
  }
  local_d = '\0';
  local_b = 100;
  local_c = 3;
  while( true ) {
    if (5 < local_c) {
      DAT_00020ba8 = local_d;
      return;
    }
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) break;
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
    local_c = local_c + 1;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AI @ fffa6946 (224 bytes)

void cat_AI(int param_1,char param_2)

{
  if (param_2 == '\0') {
    if (DAT_0000464c == '\x03') {
      DAT_00001c90 = nib2hex(DAT_00020b22);
    }
    else if (DAT_0000464c == '\x02') {
      DAT_00001c90 = nib2hex(DAT_00020b21);
    }
    else if (DAT_0000464c == '\x01') {
      DAT_00001c90 = nib2hex(DAT_00020b20);
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (0x31 < *(byte *)(param_1 + 2)) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_0000464c == '\x03') {
    DAT_00020b22 = hex2nib(*(byte *)(param_1 + 2));
  }
  else if (DAT_0000464c == '\x02') {
    DAT_00020b21 = hex2nib(*(byte *)(param_1 + 2));
  }
  else if (DAT_0000464c == '\x01') {
    DAT_00020b20 = hex2nib(*(byte *)(param_1 + 2));
  }
  if (*(char *)(param_1 + 2) == '1') {
    cat_ai_holdoff();
    return;
  }
  return;
}


// ===== cat_AM @ fffa6a26 (329 bytes)

void cat_AM(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  
  bVar2 = DAT_000060c9;
  puVar4 = &DAT_00006150 + (uint)DAT_000060c9 * 0x5a;
  puVar3 = &DAT_00004761 +
           (uint)DAT_00009dc3 * 0x5a + (uint)(byte)(&DAT_000060b1)[DAT_00009dc3] * 0x438;
  if ((DAT_000060c9 < 0x75) || (0x84 < DAT_000060c9)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (DAT_00009dbe == '\x01') {
      puVar3 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else if (DAT_00009dbe == '\x04') {
      vm_toggle();
      puVar5 = puVar3;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else if (DAT_00009dbe == '\x03') {
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else {
      if (DAT_00009dbe == '\x05') {
        for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar4 = *puVar3;
          puVar4 = puVar4 + 1;
          puVar3 = puVar3 + 1;
        }
        eeprom_save_memch(bVar2);
        return;
      }
      puVar5 = puVar3;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar4 = &DAT_00009d09;
      for (iVar6 = 0x5a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    vfo_mark_edited(DAT_00009dbd);
    vfo_store_back(DAT_00009dbd);
    DAT_00020f10 = 1;
    eeprom_save_memch(bVar2);
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AO @ fffa6b6f (302 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6bdf) */
/* WARNING: Removing unreachable block (ram,0xfffa6c30) */
/* WARNING: Removing unreachable block (ram,0xfffa6c97) */
/* WARNING: Removing unreachable block (ram,0xfffa6c8b) */
/* WARNING: Removing unreachable block (ram,0xfffa6c1a) */
/* WARNING: Removing unreachable block (ram,0xfffa6baa) */
/* WARNING: Removing unreachable block (ram,0xfffa6c9a) */

void cat_AO(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_d = DAT_00009bf2;
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      n = local_d;
      if (local_b != 0) {
        n = local_d / local_b;
      }
      local_d = local_d - n * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(n);
      (&DAT_00001c90)[local_c] = cVar2;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  local_d = 0;
  local_b = 100;
  for (local_c = 2; local_c < 5; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  if ((local_d == 0) || (100 < local_d)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_00009bf2 = local_d;
    if (DAT_00009ace != '\0') {
      return;
    }
    DAT_00020cc6 = 0x28;
    FUN_fffc8cbb(0x28);
    FUN_fffc8d8c();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_AS @ fffa6c9d (575 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6d9c) */
/* WARNING: Removing unreachable block (ram,0xfffa6ddc) */
/* WARNING: Removing unreachable block (ram,0xfffa6e46) */
/* WARNING: Removing unreachable block (ram,0xfffa6e3a) */
/* WARNING: Removing unreachable block (ram,0xfffa6ed9) */
/* WARNING: Removing unreachable block (ram,0xfffa6df2) */
/* WARNING: Removing unreachable block (ram,0xfffa6e0d) */
/* WARNING: Removing unreachable block (ram,0xfffa6ea3) */
/* WARNING: Removing unreachable block (ram,0xfffa6eca) */
/* WARNING: Removing unreachable block (ram,0xfffa6e79) */
/* WARNING: Removing unreachable block (ram,0xfffa6ed6) */
/* WARNING: Removing unreachable block (ram,0xfffa6cf7) */
/* WARNING: Removing unreachable block (ram,0xfffa6d86) */

void cat_AS(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte *pbVar3;
  char *pcVar4;
  byte n;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  
  pbVar3 = (byte *)FUN_fffb54a0();
  pcVar4 = (char *)FUN_fffb552c();
  bVar1 = *(char *)(param_1 + 2) == '1';
  if (param_2 == '\0') {
    if (bVar1) {
      bStack_d = *pbVar3 * '\x05';
      bStack_b = 100;
      for (bStack_c = 0; bStack_c < 3; bStack_c = bStack_c + 1) {
        n = bStack_d;
        if (bStack_b != 0) {
          n = bStack_d / bStack_b;
        }
        bStack_d = bStack_d - n * bStack_b;
        bStack_b = bStack_b / 10;
        cVar2 = nib2hex(n);
        (&DAT_00001c91)[bStack_c] = cVar2;
      }
    }
    else {
      if (*(char *)(param_1 + 2) != '2') {
        DAT_0000464a = 1;
        return;
      }
      if (*pcVar4 == '\0') {
        DAT_00001c91 = 0x30;
        DAT_00001c92 = 0x30;
        DAT_00001c93._0_1_ = 0x31;
      }
      else if (*pcVar4 == '\x01') {
        DAT_00001c91 = 0x30;
        DAT_00001c92 = 0x30;
        DAT_00001c93._0_1_ = 0x32;
      }
    }
    DAT_00001c93._1_1_ = 0x3b;
    DAT_0001b788 = 7;
    return;
  }
  if (bVar1) {
    bStack_d = 0;
    bStack_b = 100;
    for (bStack_c = 3; bStack_c < 6; bStack_c = bStack_c + 1) {
      if ((*(byte *)((uint)bStack_c + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_c + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      bStack_d = (*(byte *)((uint)bStack_c + param_1) & 0xf) * bStack_b + bStack_d;
      bStack_b = bStack_b / 10;
    }
    if (100 < bStack_d) {
      DAT_0000464a = 1;
      return;
    }
    *pbVar3 = bStack_d / 5;
    if (DAT_00009ace == '\0') {
      DAT_00020cc6 = 0x33;
      FUN_fffc8cbb(0x33);
      FUN_fffc8d8c();
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '2') {
      DAT_0000464a = 1;
      return;
    }
    if ((*(char *)(param_1 + 3) == '0') && (*(char *)(param_1 + 4) == '0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    if (*(char *)(param_1 + 5) == '1') {
      *pcVar4 = '\0';
    }
    else {
      if (*(char *)(param_1 + 5) != '2') {
        DAT_0000464a = 1;
        return;
      }
      *pcVar4 = '\x01';
    }
    if (DAT_00009ace == '\0') {
      DAT_00020cc6 = 0x58;
      FUN_fffc8cbb(0x58);
      FUN_fffc8d8c();
      return;
    }
  }
  return;
}


// ===== cat_AV @ fffa6edc (316 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa6fa3) */
/* WARNING: Removing unreachable block (ram,0xfffa6f68) */
/* WARNING: Removing unreachable block (ram,0xfffa7015) */
/* WARNING: Removing unreachable block (ram,0xfffa7012) */
/* WARNING: Removing unreachable block (ram,0xfffa6fb9) */
/* WARNING: Removing unreachable block (ram,0xfffa7006) */
/* WARNING: Removing unreachable block (ram,0xfffa6f33) */

void cat_AV(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_15;
  byte local_14;
  byte local_13;
  
  if (param_2 == '\0') {
    if (DAT_00009af3 == '\0') {
      local_15 = DAT_00009bf6;
    }
    else {
      local_15 = DAT_00009bf7;
    }
    local_13 = 100;
    for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
      n = local_15;
      if (local_13 != 0) {
        n = local_15 / local_13;
      }
      local_15 = local_15 - n * local_13;
      local_13 = local_13 / 10;
      cVar2 = nib2hex(n);
      (&DAT_00001c90)[local_14] = cVar2;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  local_15 = 0;
  local_13 = 100;
  for (local_14 = 2; local_14 < 5; local_14 = local_14 + 1) {
    if ((*(byte *)((uint)local_14 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_14 + param_1))
       ) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    local_15 = (*(byte *)((uint)local_14 + param_1) & 0xf) * local_13 + local_15;
    local_13 = local_13 / 10;
  }
  if (100 < local_15) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009af3 == '\0') {
    DAT_00009bf6 = local_15;
  }
  else {
    DAT_00009bf7 = local_15;
  }
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x2b;
    FUN_fffc8cbb(0x2b);
    FUN_fffc8d8c();
    return;
  }
  return;
}


// ===== cat_BA @ fffa7018 (359 bytes)

void cat_BA(void)

{
  bool bVar1;
  byte bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    bVar2 = vfo_tune_locked('\0');
    if (bVar2 == 1) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00009dbe = 1;
    puVar4 = &DAT_00009d63;
    puVar3 = &DAT_00009d09;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    vfo_mark_edited(0);
    vfo_store_back(0);
    DAT_00020f10 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_BC @ fffa717f (346 bytes)

void cat_BC(int param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  byte *pbStack_14;
  byte bStack_e;
  
  pbStack_14 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  uVar1 = (uint)bVar2;
  if (param_2 == '\0') {
    if (uVar1 - 2 < 2) {
      bStack_e = pbStack_14[0x15];
    }
    else if (uVar1 - 4 < 2) {
      bStack_e = pbStack_14[0x33];
    }
    else {
      if (uVar1 - 6 < 2) {
        DAT_0000464a = 1;
        return;
      }
      if (1 < uVar1 - 8) {
        if (uVar1 - 10 < 2) {
          DAT_0000464a = 1;
          return;
        }
        if (uVar1 - 0xc < 2) {
          bStack_e = pbStack_14[0x1f];
          goto LAB_fffa7214;
        }
        if (uVar1 != 0xe) {
          bStack_e = pbStack_14[0xb];
          goto LAB_fffa7214;
        }
      }
      bStack_e = pbStack_14[0x29];
    }
LAB_fffa7214:
    DAT_00001c90 = 0x30;
    if ((bStack_e & 0x80) == 0) {
      DAT_00001c91 = 0x30;
    }
    else {
      DAT_00001c91 = 0x31;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  if (uVar1 - 2 < 2) {
    pbStack_14 = pbStack_14 + 0x15;
  }
  else if (uVar1 - 4 < 2) {
    pbStack_14 = pbStack_14 + 0x33;
  }
  else {
    if (uVar1 - 6 < 2) {
      DAT_0000464a = 1;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 10 < 2) {
        DAT_0000464a = 1;
        return;
      }
      if (uVar1 - 0xc < 2) {
        pbStack_14 = pbStack_14 + 0x1f;
        goto LAB_fffa72ae;
      }
      if (uVar1 != 0xe) {
        pbStack_14 = pbStack_14 + 0xb;
        goto LAB_fffa72ae;
      }
    }
    pbStack_14 = pbStack_14 + 0x29;
  }
LAB_fffa72ae:
  cVar3 = hex2nib(*(byte *)(param_1 + 3));
  if (cVar3 == '\0') {
    *pbStack_14 = *pbStack_14 & 0x7f;
    return;
  }
  if (cVar3 != '\x01') {
    DAT_0000464a = 1;
    return;
  }
  *pbStack_14 = *pbStack_14 | 0x80;
  return;
}


// ===== cat_BD @ fffa72d9 (659 bytes)

void cat_BD(int param_1)

{
  bool bVar1;
  byte bVar2;
  uint freq;
  byte local_d;
  byte bStack_5;
  
  bVar2 = DAT_00009dbd;
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  bVar1 = *(char *)(param_1 + 2) == '0';
  if (DAT_00009dbd == 0) {
    if (bVar1) {
      local_d = 0;
    }
    else {
      if (*(char *)(param_1 + 2) != '1') {
        DAT_0000464a = 1;
        return;
      }
      local_d = 1;
    }
  }
  else if (bVar1) {
    local_d = 1;
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    local_d = 0;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_00009c5e = '\0';
    if (*(char *)(param_1 + 2) == '0') {
      DAT_00009dbe = 1;
      DAT_00009dbf = 1;
    }
    else {
      DAT_00009dbe = DAT_00020f88;
      DAT_00009dbf = DAT_00020f89;
    }
  }
  else {
    if ((DAT_00009dbd == 0) && (*(char *)(param_1 + 2) == '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00009dbe = 1;
    }
    else {
      if ((DAT_00009dbd == 1) && (*(char *)(param_1 + 2) == '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00009dbf = 1;
      }
    }
  }
  freq = vfo_freq(0,local_d);
  bStack_5 = band_of_freq(freq);
  if (0xb < bStack_5) {
    bStack_5 = 0xb;
  }
  if (bStack_5 == 0) {
    bStack_5 = 0xb;
  }
  else if (bStack_5 < 0xc) {
    bStack_5 = bStack_5 - 1;
  }
  else {
    bStack_5 = 0xb;
  }
  if (*(char *)(param_1 + 2) == '0') {
    band_select_on(bStack_5,bVar2);
    return;
  }
  band_select_on(bStack_5,local_d);
  return;
}


// ===== cat_BU @ fffa756c (640 bytes)

void cat_BU(int param_1)

{
  bool bVar1;
  byte bVar2;
  uint freq;
  byte local_d;
  byte bStack_5;
  
  bVar2 = DAT_00009dbd;
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  bVar1 = *(char *)(param_1 + 2) == '0';
  if (DAT_00009dbd == 0) {
    if (bVar1) {
      local_d = 0;
    }
    else {
      if (*(char *)(param_1 + 2) != '1') {
        DAT_0000464a = 1;
        return;
      }
      local_d = 1;
    }
  }
  else if (bVar1) {
    local_d = 1;
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    local_d = 0;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_00009c5e = '\0';
    if (*(char *)(param_1 + 2) == '0') {
      DAT_00009dbe = 1;
      DAT_00009dbf = 1;
    }
    else {
      DAT_00009dbe = DAT_00020f88;
      DAT_00009dbf = DAT_00020f89;
    }
  }
  else {
    if ((DAT_00009dbd == 0) && (*(char *)(param_1 + 2) == '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00009dbe = 1;
    }
    else {
      if ((DAT_00009dbd == 1) && (*(char *)(param_1 + 2) == '0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00009dbf = 1;
      }
    }
  }
  freq = vfo_freq(0,local_d);
  bStack_5 = band_of_freq(freq);
  if (bStack_5 < 0xb) {
    bStack_5 = bStack_5 + 1;
  }
  else {
    bStack_5 = 0;
  }
  if (*(char *)(param_1 + 2) == '0') {
    band_select_on(bStack_5,bVar2);
    return;
  }
  band_select_on(bStack_5,local_d);
  return;
}


// ===== cat_BI @ fffa77ec (316 bytes)

void cat_BI(int param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  byte *pbStack_14;
  byte bStack_e;
  
  pbStack_14 = vfo_rec_ptr(1);
  bVar2 = vfo_mode(1);
  uVar1 = (uint)bVar2;
  if (param_2 == '\0') {
    if (uVar1 - 2 < 2) {
      bStack_e = pbStack_14[0x14];
    }
    else if (uVar1 - 4 < 2) {
      bStack_e = pbStack_14[0x32];
    }
    else {
      if (1 < uVar1 - 6) {
        if (uVar1 - 8 < 2) {
          DAT_0000464a = 1;
          return;
        }
        if (1 < uVar1 - 10) {
          if (uVar1 - 0xc < 2) {
            DAT_0000464a = 1;
            return;
          }
          if (uVar1 == 0xe) {
            DAT_0000464a = 1;
            return;
          }
          bStack_e = pbStack_14[10];
          goto LAB_fffa786d;
        }
      }
      bStack_e = pbStack_14[0x3c];
    }
LAB_fffa786d:
    if ((bStack_e & 2) == 0) {
      DAT_00001c90 = 0x30;
    }
    else {
      DAT_00001c90 = 0x31;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (uVar1 - 2 < 2) {
    pbStack_14 = pbStack_14 + 0x14;
  }
  else if (uVar1 - 4 < 2) {
    pbStack_14 = pbStack_14 + 0x32;
  }
  else {
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) {
        DAT_0000464a = 1;
        return;
      }
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          DAT_0000464a = 1;
          return;
        }
        if (uVar1 == 0xe) {
          DAT_0000464a = 1;
          return;
        }
        pbStack_14 = pbStack_14 + 10;
        goto LAB_fffa78fd;
      }
    }
    pbStack_14 = pbStack_14 + 0x3c;
  }
LAB_fffa78fd:
  cVar3 = hex2nib(*(byte *)(param_1 + 2));
  if (cVar3 == '\0') {
    *pbStack_14 = *pbStack_14 & 0xfd;
    return;
  }
  if (cVar3 != '\x01') {
    DAT_0000464a = 1;
    return;
  }
  *pbStack_14 = *pbStack_14 | 2;
  return;
}


// ===== cat_BM @ fffa7928 (329 bytes)

void cat_BM(void)

{
  bool bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined *puVar6;
  int iVar7;
  
  bVar2 = DAT_000060ca;
  puVar4 = &DAT_00006150 + (uint)DAT_000060ca * 0x5a;
  puVar3 = &DAT_00005409 +
           (uint)DAT_00009dc4 * 0x5a + (uint)(byte)(&DAT_000060bd)[DAT_00009dc4] * 0x438;
  if ((DAT_000060ca < 0x75) || (0x84 < DAT_000060ca)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (DAT_00009dbf == '\x01') {
      puVar5 = &DAT_00009d63;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar5;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    else if (DAT_00009dbf == '\x04') {
      vm_toggle();
      puVar6 = puVar3;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar4 = &DAT_00009d63;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else if (DAT_00009dbf == '\x03') {
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    else {
      if (DAT_00009dbf == '\x05') {
        for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar4 = *puVar3;
          puVar4 = puVar4 + 1;
          puVar3 = puVar3 + 1;
        }
        eeprom_save_memch(bVar2);
        return;
      }
      puVar6 = puVar3;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar4 = &DAT_00009d63;
      for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar4 = *puVar3;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    vfo_mark_edited(DAT_00009dbd);
    vfo_store_back(DAT_00009dbd);
    DAT_00020f10 = 1;
    eeprom_save_memch(bVar2);
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_BP @ fffa7a71 (836 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa7d1c) */
/* WARNING: Removing unreachable block (ram,0xfffa7b81) */
/* WARNING: Removing unreachable block (ram,0xfffa7ba9) */
/* WARNING: Removing unreachable block (ram,0xfffa7db2) */
/* WARNING: Removing unreachable block (ram,0xfffa7cd9) */
/* WARNING: Removing unreachable block (ram,0xfffa7d69) */
/* WARNING: Removing unreachable block (ram,0xfffa7daf) */
/* WARNING: Removing unreachable block (ram,0xfffa7d33) */
/* WARNING: Removing unreachable block (ram,0xfffa7a9d) */
/* WARNING: Removing unreachable block (ram,0xfffa7bde) */
/* WARNING: Removing unreachable block (ram,0xfffa7d85) */

void cat_BP(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  ushort uVar5;
  ushort uStack_26;
  byte *pbStack_24;
  byte *pbStack_20;
  byte *pbStack_1c;
  byte bStack_16;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  
  pbStack_20 = vfo_rec_ptr(0);
  bVar2 = vfo_mode(0);
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  uVar4 = (uint)bVar2;
  if (param_2 == '\0') {
    if (uVar4 - 2 < 2) {
      bStack_12 = pbStack_20[0x14];
      bStack_16 = pbStack_20[0x18];
      bStack_15 = pbStack_20[0x19];
      goto LAB_fffa7b4e;
    }
    if (uVar4 - 4 < 2) {
      bStack_12 = pbStack_20[0x32];
      bStack_16 = pbStack_20[0x36];
      bStack_15 = pbStack_20[0x37];
      goto LAB_fffa7b4e;
    }
    if (uVar4 - 6 < 2) {
LAB_fffa7b3c:
      bStack_12 = pbStack_20[0x3c];
      bStack_16 = pbStack_20[0x40];
      bStack_15 = pbStack_20[0x41];
    }
    else {
      if (1 < uVar4 - 8) {
        if (uVar4 - 10 < 2) goto LAB_fffa7b3c;
        if (uVar4 - 0xc < 2) {
          bStack_12 = pbStack_20[0x1e];
          bStack_16 = pbStack_20[0x22];
          bStack_15 = pbStack_20[0x23];
          goto LAB_fffa7b4e;
        }
        if (uVar4 != 0xe) {
          bStack_12 = pbStack_20[10];
          bStack_16 = pbStack_20[0xe];
          bStack_15 = pbStack_20[0xf];
          goto LAB_fffa7b4e;
        }
      }
      bStack_12 = pbStack_20[0x28];
      bStack_16 = pbStack_20[0x2c];
      bStack_15 = pbStack_20[0x2d];
    }
LAB_fffa7b4e:
    if (*(char *)(param_1 + 3) == '0') {
      DAT_00001c92 = 0x30;
      DAT_00001c93._0_1_ = 0x30;
      if ((bStack_12 & 0x80) == 0) {
        DAT_00001c93._1_1_ = 0x30;
      }
      else {
        DAT_00001c93._1_1_ = 0x31;
      }
    }
    else {
      uStack_26 = CONCAT11(bStack_16,bStack_15);
      bStack_13 = 100;
      for (bStack_14 = 0; bStack_14 < 3; bStack_14 = bStack_14 + 1) {
        uVar4 = (uint)uStack_26;
        if (bStack_13 != 0) {
          uVar4 = uVar4 / bStack_13;
        }
        uVar5 = uStack_26;
        if (bStack_13 != 0) {
          uVar5 = uStack_26 / bStack_13;
        }
        uStack_26 = uStack_26 - uVar5 * bStack_13;
        bStack_13 = bStack_13 / 10;
        cVar3 = nib2hex((byte)uVar4);
        (&DAT_00001c92)[bStack_14] = cVar3;
      }
    }
    DAT_00001c93._2_1_ = 0x3b;
    DAT_0001b788 = 8;
    return;
  }
  if (uVar4 - 2 < 2) {
    pbStack_1c = pbStack_20 + 0x14;
    pbStack_24 = pbStack_20 + 0x18;
    pbStack_20 = pbStack_20 + 0x19;
    goto LAB_fffa7c97;
  }
  if (uVar4 - 4 < 2) {
    pbStack_1c = pbStack_20 + 0x32;
    pbStack_24 = pbStack_20 + 0x36;
    pbStack_20 = pbStack_20 + 0x37;
    goto LAB_fffa7c97;
  }
  if (uVar4 - 6 < 2) {
LAB_fffa7c82:
    pbStack_1c = pbStack_20 + 0x3c;
    pbStack_24 = pbStack_20 + 0x40;
    pbStack_20 = pbStack_20 + 0x41;
  }
  else {
    if (1 < uVar4 - 8) {
      if (uVar4 - 10 < 2) goto LAB_fffa7c82;
      if (uVar4 - 0xc < 2) {
        pbStack_1c = pbStack_20 + 0x1e;
        pbStack_24 = pbStack_20 + 0x22;
        pbStack_20 = pbStack_20 + 0x23;
        goto LAB_fffa7c97;
      }
      if (uVar4 != 0xe) {
        pbStack_1c = pbStack_20 + 10;
        pbStack_24 = pbStack_20 + 0xe;
        pbStack_20 = pbStack_20 + 0xf;
        goto LAB_fffa7c97;
      }
    }
    pbStack_1c = pbStack_20 + 0x28;
    pbStack_24 = pbStack_20 + 0x2c;
    pbStack_20 = pbStack_20 + 0x2d;
  }
LAB_fffa7c97:
  if (*(char *)(param_1 + 3) == '0') {
    if ((*(char *)(param_1 + 4) != '0') || (*(char *)(param_1 + 5) != '0')) {
      return;
    }
    if (*(char *)(param_1 + 6) == '0') {
      *pbStack_1c = *pbStack_1c & 0x7f;
    }
    else {
      if (*(char *)(param_1 + 6) != '1') {
        DAT_0000464a = 1;
        return;
      }
      *pbStack_1c = *pbStack_1c | 0x80;
    }
  }
  else {
    if (*(char *)(param_1 + 3) != '1') {
      DAT_0000464a = 1;
      return;
    }
    uStack_26 = 0;
    bStack_13 = 100;
    for (bStack_14 = 4; bStack_14 < 7; bStack_14 = bStack_14 + 1) {
      if ((*(byte *)((uint)bStack_14 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)bStack_14 + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      uStack_26 = (*(byte *)((uint)bStack_14 + param_1) & 0xf) * (ushort)bStack_13 + uStack_26;
      bStack_13 = bStack_13 / 10;
    }
    if ((uStack_26 == 0) || (0x140 < uStack_26)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    *pbStack_24 = (byte)(uStack_26 >> 8);
    *pbStack_20 = (byte)uStack_26;
  }
  DAT_00020f10 = 1;
  vfo_mark_edited(DAT_00009dbd);
  vfo_store_back(DAT_00009dbd);
  return;
}


// ===== cat_BS @ fffa7db5 (492 bytes)

void cat_BS(int param_1)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  bVar2 = DAT_00009dbd;
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if ((*(byte *)(param_1 + 2) < 0x30) || (0x31 < *(byte *)(param_1 + 2))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      cVar3 = hex2nib(*(byte *)(param_1 + 2));
      if ((*(byte *)(param_1 + 3) < 0x30) || (0x39 < *(byte *)(param_1 + 3))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        cVar4 = hex2nib(*(byte *)(param_1 + 3));
        bVar5 = cVar4 + cVar3 * '\n';
        if (0xc < bVar5) {
          DAT_0000464a = 1;
          return;
        }
        band_select_on(bVar5,bVar2);
        DAT_00009c5e = 0;
        DAT_00009dbe = 1;
        DAT_00009dbf = 1;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CF @ fffa7fa1 (980 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa8071) */
/* WARNING: Removing unreachable block (ram,0xfffa808d) */
/* WARNING: Removing unreachable block (ram,0xfffa8303) */
/* WARNING: Removing unreachable block (ram,0xfffa82ac) */
/* WARNING: Removing unreachable block (ram,0xfffa8287) */
/* WARNING: Removing unreachable block (ram,0xfffa825c) */
/* WARNING: Removing unreachable block (ram,0xfffa8218) */
/* WARNING: Removing unreachable block (ram,0xfffa831d) */
/* WARNING: Removing unreachable block (ram,0xfffa8372) */
/* WARNING: Removing unreachable block (ram,0xfffa8354) */
/* WARNING: Removing unreachable block (ram,0xfffa81e0) */
/* WARNING: Removing unreachable block (ram,0xfffa8191) */
/* WARNING: Removing unreachable block (ram,0xfffa813d) */
/* WARNING: Removing unreachable block (ram,0xfffa81c6) */
/* WARNING: Removing unreachable block (ram,0xfffa81fa) */

void cat_CF(int param_1,char param_2)

{
  bool bVar1;
  byte n;
  char cVar2;
  byte bVar3;
  uint uVar4;
  ushort uVar5;
  byte bStack_1e;
  char local_1d;
  byte *local_1c;
  ushort uStack_18;
  ushort uStack_16;
  byte bStack_13;
  byte bStack_12;
  undefined1 *local_10;
  
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009dbd == '\0') {
      local_10 = &DAT_00009d09;
      local_1c = (byte *)&DAT_00020f29;
      local_1d = DAT_00020f29;
    }
    else {
      local_10 = &DAT_00009d63;
      local_1c = (byte *)&DAT_00020f2a;
      local_1d = DAT_00020f2a;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00009dbd == '\0') {
      local_10 = &DAT_00009d63;
      local_1c = (byte *)&DAT_00020f2a;
      local_1d = DAT_00020f2a;
    }
    else {
      local_10 = &DAT_00009d09;
      local_1c = (byte *)&DAT_00020f29;
      local_1d = DAT_00020f29;
    }
  }
  n = hex2nib(*(byte *)(param_1 + 4));
  if (1 < n) {
    DAT_0000464a = 1;
    return;
  }
  if (param_2 == '\0') {
    DAT_00001c91 = 0x30;
    DAT_00001c92 = nib2hex(n);
    if (n == 0) {
      if (local_1d == '\0') {
        DAT_00001c93._0_1_ = 0x30;
        DAT_00001c93._1_1_ = 0x30;
      }
      else if (local_1d == '\x01') {
        DAT_00001c93._0_1_ = 0x31;
        DAT_00001c93._1_1_ = 0x30;
      }
      else if (local_1d == '\x02') {
        DAT_00001c93._0_1_ = 0x30;
        DAT_00001c93._1_1_ = 0x31;
      }
      else if (local_1d == '\x03') {
        DAT_00001c93._0_1_ = 0x31;
        DAT_00001c93._1_1_ = 0x31;
      }
      DAT_00001c93._2_1_ = 0x30;
      DAT_00001c93._3_1_ = 0x30;
      DAT_00001c97 = 0x30;
    }
    else {
      uStack_16 = CONCAT11(local_10[0x48],local_10[0x49]);
      if ((local_10[0x48] & 0x80) == 0) {
        DAT_00001c93._0_1_ = 0x2b;
      }
      else {
        DAT_00001c93._0_1_ = 0x2d;
        uStack_16 = ~uStack_16 + 1;
      }
      uStack_18 = 1000;
      for (bStack_13 = 0; bStack_13 < 4; bStack_13 = bStack_13 + 1) {
        uVar4 = (uint)uStack_16;
        if (uStack_18 != 0) {
          uVar4 = uVar4 / uStack_18;
        }
        uVar5 = uStack_16;
        if (uStack_18 != 0) {
          uVar5 = uStack_16 / uStack_18;
        }
        uStack_16 = uStack_16 - uVar5 * uStack_18;
        uStack_18 = uStack_18 / 10;
        cVar2 = nib2hex((byte)uVar4);
        *(char *)((int)&DAT_00001c93 + bStack_13 + 1) = cVar2;
      }
    }
    DAT_00001c98 = 0x3b;
    DAT_0001b788 = 0xb;
    return;
  }
  bVar3 = key_event_filter(0x306,0);
  if (bVar3 != 0) {
    if (DAT_00009c5e == '\x01') {
      DAT_0000464a = 1;
      return;
    }
    bVar3 = vfo_tune_locked(DAT_00009dbd);
    if (bVar3 != 1) {
      if (n == 0) {
        if ((*(char *)(param_1 + 7) == '0') && (*(char *)(param_1 + 8) == '0')) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if ((bVar1) || (*(char *)(param_1 + 9) != '0')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_0000464a = 1;
          return;
        }
        bStack_12 = 0;
        bStack_1e = 0;
        if (*(char *)(param_1 + 5) == '1') {
          bStack_12 = 1;
          bStack_1e = 0x10;
        }
        else if (*(char *)(param_1 + 5) != '0') {
          DAT_0000464a = 1;
          return;
        }
        if (*(char *)(param_1 + 6) == '1') {
          bStack_12 = bStack_12 | 2;
          bStack_1e = bStack_1e | 8;
        }
        else if (*(char *)(param_1 + 6) != '0') {
          DAT_0000464a = 1;
          return;
        }
        *local_1c = bStack_12;
        local_10[1] = local_10[1] & 0xe7;
        local_10[1] = local_10[1] | bStack_1e;
      }
      else {
        uStack_16 = 0;
        uStack_18 = 1000;
        for (bStack_13 = 6; bStack_13 < 10; bStack_13 = bStack_13 + 1) {
          if ((*(byte *)((uint)bStack_13 + param_1) < 0x30) ||
             (0x39 < *(byte *)((uint)bStack_13 + param_1))) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            DAT_0000464a = 1;
            return;
          }
          uStack_16 = (*(byte *)((uint)bStack_13 + param_1) & 0xf) * uStack_18 + uStack_16;
          uStack_18 = uStack_18 / 10;
        }
        if (*(char *)(param_1 + 5) == '-') {
          uStack_16 = ~uStack_16 + 1;
        }
        else if (*(char *)(param_1 + 5) != '+') {
          DAT_0000464a = 1;
          return;
        }
        local_10[0x48] = (char)(uStack_16 >> 8);
        local_10[0x49] = (undefined1)uStack_16;
      }
      DAT_00020f10 = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CH @ fffa8375 (414 bytes)

void cat_CH(int param_1)

{
  bool bVar1;
  char local_6;
  
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b98 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009dbd == '\0') {
    local_6 = DAT_00009dbe;
  }
  else {
    local_6 = DAT_00009dbf;
  }
  if (local_6 != '\x02') {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    DAT_00020f80 = 0;
    FUN_fffc54cc(1,DAT_00009dbd);
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    DAT_00020f80 = 1;
    FUN_fffc54cc(1,DAT_00009dbd);
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CN @ fffa8513 (389 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa8603) */
/* WARNING: Removing unreachable block (ram,0xfffa863e) */
/* WARNING: Removing unreachable block (ram,0xfffa8695) */
/* WARNING: Removing unreachable block (ram,0xfffa8654) */
/* WARNING: Removing unreachable block (ram,0xfffa85ce) */
/* WARNING: Removing unreachable block (ram,0xfffa852e) */

void cat_CN(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_15;
  byte local_14;
  byte local_13;
  byte local_12;
  undefined1 *local_10;
  
  if (*(char *)(param_1 + 3) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009dbd == '\0') {
      local_10 = &DAT_00009d09;
      local_15 = 0;
    }
    else {
      local_10 = &DAT_00009d63;
      local_15 = 1;
    }
  }
  else if (*(char *)(param_1 + 2) == '1') {
    if (DAT_00009dbd == '\0') {
      local_10 = &DAT_00009d63;
      local_15 = 1;
    }
    else {
      local_10 = &DAT_00009d09;
      local_15 = 0;
    }
  }
  if (param_2 != '\0') {
    local_14 = 0;
    local_12 = 100;
    local_13 = 4;
    while( true ) {
      if (6 < local_13) {
        if (local_14 < 0x32) {
          local_10[0x46] = local_14;
        }
        else {
          DAT_0000464a = 1;
        }
        DAT_00020f10 = 1;
        vfo_mark_edited(local_15);
        vfo_store_back(local_15);
        return;
      }
      if ((*(byte *)((uint)local_13 + param_1) < 0x30) ||
         (0x39 < *(byte *)((uint)local_13 + param_1))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) break;
      local_14 = (*(byte *)((uint)local_13 + param_1) & 0xf) * local_12 + local_14;
      local_12 = local_12 / 10;
      local_13 = local_13 + 1;
    }
    DAT_0000464a = 1;
    return;
  }
  local_12 = 100;
  local_14 = local_10[0x46];
  for (local_13 = 0; local_13 < 3; local_13 = local_13 + 1) {
    n = local_14;
    if (local_12 != 0) {
      n = local_14 / local_12;
    }
    local_14 = local_14 - n * local_12;
    local_12 = local_12 / 10;
    cVar2 = nib2hex(n);
    (&DAT_00001c92)[local_13] = cVar2;
  }
  DAT_00001c93._2_1_ = 0x3b;
  DAT_0001b788 = 8;
  return;
}


// ===== cat_CO @ fffa8698 (1280 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa89a8) */
/* WARNING: Removing unreachable block (ram,0xfffa89f9) */
/* WARNING: Removing unreachable block (ram,0xfffa8b95) */
/* WARNING: Removing unreachable block (ram,0xfffa8b27) */
/* WARNING: Removing unreachable block (ram,0xfffa8b7d) */
/* WARNING: Removing unreachable block (ram,0xfffa8b3d) */
/* WARNING: Removing unreachable block (ram,0xfffa89b4) */
/* WARNING: Removing unreachable block (ram,0xfffa8999) */
/* WARNING: Removing unreachable block (ram,0xfffa8aad) */
/* WARNING: Removing unreachable block (ram,0xfffa8ab9) */
/* WARNING: Removing unreachable block (ram,0xfffa8a9e) */
/* WARNING: Removing unreachable block (ram,0xfffa8a8f) */
/* WARNING: Removing unreachable block (ram,0xfffa8a47) */
/* WARNING: Removing unreachable block (ram,0xfffa8a11) */
/* WARNING: Removing unreachable block (ram,0xfffa8a71) */
/* WARNING: Removing unreachable block (ram,0xfffa88d2) */
/* WARNING: Removing unreachable block (ram,0xfffa87dc) */
/* WARNING: Removing unreachable block (ram,0xfffa889d) */
/* WARNING: Removing unreachable block (ram,0xfffa871e) */
/* WARNING: Removing unreachable block (ram,0xfffa8732) */
/* WARNING: Removing unreachable block (ram,0xfffa875a) */
/* WARNING: Removing unreachable block (ram,0xfffa8746) */
/* WARNING: Removing unreachable block (ram,0xfffa870a) */
/* WARNING: Removing unreachable block (ram,0xfffa8a4c) */
/* WARNING: Removing unreachable block (ram,0xfffa8b89) */
/* WARNING: Removing unreachable block (ram,0xfffa8aec) */
/* WARNING: Removing unreachable block (ram,0xfffa86f7) */

void cat_CO(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  byte n;
  ushort uVar4;
  ushort uStack_2a;
  ushort uStack_28;
  byte bStack_25;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  byte *pbStack_20;
  byte *pbStack_1c;
  byte *pbStack_18;
  byte bStack_11;
  byte *pbStack_10;
  char local_9;
  int local_8;
  
  local_9 = param_2;
  local_8 = param_1;
  pbStack_10 = vfo_rec_ptr(0);
  bStack_11 = vfo_mode(0);
  bStack_21 = 0xff;
  uVar3 = (uint)bStack_11;
  if (local_9 != '\0') {
    if (uVar3 - 2 < 2) {
      pbStack_18 = pbStack_10 + 0x14;
      pbStack_1c = pbStack_10 + 0x14;
      pbStack_20 = pbStack_10 + 0x16;
      goto LAB_fffa8986;
    }
    if (uVar3 - 4 < 2) {
      pbStack_18 = pbStack_10 + 0x32;
      pbStack_1c = &bStack_21;
      pbStack_20 = pbStack_10 + 0x34;
      goto LAB_fffa8986;
    }
    if (uVar3 - 6 < 2) {
LAB_fffa8973:
      pbStack_18 = pbStack_10 + 0x3c;
      pbStack_1c = &bStack_21;
      pbStack_20 = pbStack_10 + 0x3e;
    }
    else {
      if (1 < uVar3 - 8) {
        if (uVar3 - 10 < 2) goto LAB_fffa8973;
        if (uVar3 - 0xc < 2) {
          pbStack_18 = pbStack_10 + 0x1e;
          pbStack_1c = pbStack_10 + 0x1e;
          pbStack_20 = pbStack_10 + 0x20;
          goto LAB_fffa8986;
        }
        if (uVar3 != 0xe) {
          pbStack_18 = pbStack_10 + 10;
          pbStack_1c = &bStack_21;
          pbStack_20 = pbStack_10 + 0xc;
          goto LAB_fffa8986;
        }
      }
      pbStack_18 = pbStack_10 + 0x28;
      pbStack_1c = pbStack_10 + 0x28;
      pbStack_20 = pbStack_10 + 0x2a;
    }
LAB_fffa8986:
    if (*(char *)(local_8 + 3) == '0') {
      if (*(char *)(local_8 + 7) == '0') {
        *pbStack_18 = *pbStack_18 & 0xbf;
        return;
      }
      if (*(char *)(local_8 + 7) == '1') {
        *pbStack_18 = *pbStack_18 | 0x40;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    if (*(char *)(local_8 + 3) == '1') {
      uStack_28 = 0;
      uStack_2a = 1000;
      for (bStack_24 = 4; bStack_24 < 8; bStack_24 = bStack_24 + 1) {
        if ((*(byte *)((uint)bStack_24 + local_8) < 0x30) ||
           (0x39 < *(byte *)((uint)bStack_24 + local_8))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_0000464a = 1;
          return;
        }
        uStack_28 = (*(byte *)((uint)bStack_24 + local_8) & 0xf) * uStack_2a + uStack_28;
        uStack_2a = uStack_2a / 10;
      }
      if ((uStack_28 < 10) || (0xc80 < uStack_28)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        *pbStack_20 = (byte)(uStack_28 / 10 >> 8);
        uStack_28._0_1_ = (byte)(uStack_28 / 10);
        pbStack_20[1] = (byte)uStack_28;
        DAT_00020f10 = 1;
        return;
      }
      DAT_0000464a = 1;
      return;
    }
    if (*(char *)(local_8 + 3) == '2') {
      if (*pbStack_1c == 0xff) {
        DAT_0000464a = 1;
        return;
      }
      if (*(char *)(local_8 + 7) != '0') {
        if (*(char *)(local_8 + 7) == '1') {
          *pbStack_1c = *pbStack_1c | 0x20;
          return;
        }
        DAT_0000464a = 1;
        return;
      }
      *pbStack_1c = *pbStack_1c & 0xdf;
      return;
    }
    if (*(char *)(local_8 + 3) != '3') {
      DAT_0000464a = 1;
      return;
    }
    if ((*(char *)(local_8 + 4) == '0') && (*(char *)(local_8 + 5) == '0')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      bStack_25 = 0;
      bStack_23 = 10;
      bStack_24 = 6;
      while( true ) {
        if (7 < bStack_24) {
          if (0x32 < bStack_25) {
            DAT_0000464a = 1;
            return;
          }
          DAT_00009c5f = bStack_25 - 0x19;
          DAT_00020f10 = 1;
          return;
        }
        if ((*(byte *)((uint)bStack_24 + local_8) < 0x30) ||
           (0x39 < *(byte *)((uint)bStack_24 + local_8))) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) break;
        bStack_25 = (*(byte *)((uint)bStack_24 + local_8) & 0xf) * bStack_23 + bStack_25;
        bStack_23 = bStack_23 / 10;
        bStack_24 = bStack_24 + 1;
      }
      DAT_0000464a = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (uVar3 - 2 < 2) {
    bStack_22 = pbStack_10[0x14];
    uStack_28 = CONCAT11(pbStack_10[0x16],pbStack_10[0x17]);
    goto LAB_fffa8761;
  }
  if (uVar3 - 4 < 2) {
    bStack_22 = pbStack_10[0x32];
    uStack_28 = CONCAT11(pbStack_10[0x34],pbStack_10[0x35]);
    goto LAB_fffa8761;
  }
  if (uVar3 - 6 < 2) {
LAB_fffa874f:
    bStack_22 = pbStack_10[0x3c];
    uStack_28 = CONCAT11(pbStack_10[0x3e],pbStack_10[0x3f]);
  }
  else {
    if (1 < uVar3 - 8) {
      if (uVar3 - 10 < 2) goto LAB_fffa874f;
      if (uVar3 - 0xc < 2) {
        bStack_22 = pbStack_10[0x1e];
        uStack_28 = CONCAT11(pbStack_10[0x20],pbStack_10[0x21]);
        goto LAB_fffa8761;
      }
      if (uVar3 != 0xe) {
        bStack_22 = pbStack_10[10];
        uStack_28 = CONCAT11(pbStack_10[0xc],pbStack_10[0xd]);
        goto LAB_fffa8761;
      }
    }
    bStack_22 = pbStack_10[0x28];
    uStack_28 = CONCAT11(pbStack_10[0x2a],pbStack_10[0x2b]);
  }
LAB_fffa8761:
  if (*(char *)(local_8 + 3) == '0') {
    DAT_00001c91 = 0x30;
    DAT_00001c92 = 0x30;
    DAT_00001c93._0_1_ = 0x30;
    DAT_00001c93._1_1_ = 0x30;
    if ((bStack_22 & 0x40) == 0) {
      DAT_00001c93._2_1_ = 0x30;
    }
    else {
      DAT_00001c93._2_1_ = 0x31;
    }
  }
  else if (*(char *)(local_8 + 3) == '1') {
    DAT_00001c91 = 0x31;
    uStack_2a = 1000;
    uStack_28 = uStack_28 * 10;
    for (bStack_24 = 0; bStack_24 < 4; bStack_24 = bStack_24 + 1) {
      uVar3 = (uint)uStack_28;
      if (uStack_2a != 0) {
        uVar3 = uVar3 / uStack_2a;
      }
      uVar4 = uStack_28;
      if (uStack_2a != 0) {
        uVar4 = uStack_28 / uStack_2a;
      }
      uStack_28 = uStack_28 - uVar4 * uStack_2a;
      uStack_2a = uStack_2a / 10;
      cVar2 = nib2hex((byte)uVar3);
      (&DAT_00001c92)[bStack_24] = cVar2;
    }
    DAT_00001c93._2_1_ = 0x30;
  }
  else if (*(char *)(local_8 + 3) == '2') {
    DAT_00001c91 = 0x32;
    DAT_00001c92 = 0x30;
    DAT_00001c93._0_1_ = 0x30;
    DAT_00001c93._1_1_ = 0x30;
    if ((bStack_22 & 0x20) == 0) {
      DAT_00001c93._2_1_ = 0x30;
    }
    else {
      DAT_00001c93._2_1_ = 0x31;
    }
  }
  else if (*(char *)(local_8 + 3) == '3') {
    DAT_00001c91 = 0x33;
    DAT_00001c92 = 0x30;
    DAT_00001c93._0_1_ = 0x30;
    bStack_23 = 10;
    bStack_25 = DAT_00009c5f + 0x19;
    for (bStack_24 = 0; bStack_24 < 2; bStack_24 = bStack_24 + 1) {
      n = bStack_25;
      if (bStack_23 != 0) {
        n = bStack_25 / bStack_23;
      }
      bStack_25 = bStack_25 - n * bStack_23;
      bStack_23 = bStack_23 / 10;
      cVar2 = nib2hex(n);
      *(char *)((int)&DAT_00001c93 + bStack_24 + 1) = cVar2;
    }
  }
  DAT_00001c93._3_1_ = 0x3b;
  DAT_0001b788 = 9;
  return;
}


// ===== cat_CS @ fffa8b98 (225 bytes)

void cat_CS(int param_1,char param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  if (param_2 == '\0') {
    if (DAT_00020f0b == '\x01') {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x30;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  pbVar2 = vfo_rec_ptr(1);
  bVar1 = key_event_filter(0x307,2);
  if (bVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_0000464a = 1;
    return;
  }
  iVar3 = FUN_fffc3e3c(pbVar2);
  if (iVar3 != 0) {
    if (*(char *)(param_1 + 2) == '1') {
      DAT_00020f0b = 1;
      beep_request(4);
      return;
    }
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00020f0b != '\x01') {
      return;
    }
    DAT_00020f0b = 0;
    beep_stop();
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_CT @ fffa8c79 (273 bytes)

void cat_CT(int param_1,char param_2)

{
  byte bVar1;
  undefined1 *local_c;
  
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009dbd == '\0') {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  if (param_2 != '\0') {
    if (*(char *)(param_1 + 3) == '0') {
      local_c[3] = local_c[3] & 199;
    }
    else if (*(char *)(param_1 + 3) == '2') {
      local_c[3] = local_c[3] & 199;
      local_c[3] = local_c[3] | 8;
    }
    else {
      if (*(char *)(param_1 + 3) != '1') {
        DAT_0000464a = 1;
        return;
      }
      local_c[3] = local_c[3] & 199;
      local_c[3] = local_c[3] | 0x10;
    }
    DAT_00020f10 = 1;
    return;
  }
  bVar1 = (local_c[3] & 0x38) >> 3;
  if (bVar1 == 0) {
    DAT_00001c91 = 0x30;
  }
  else if (bVar1 == 1) {
    DAT_00001c91 = 0x32;
  }
  else {
    if (bVar1 != 2) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00001c91 = 0x31;
  }
  DAT_00001c92 = 0x3b;
  DAT_0001b788 = 5;
  return;
}


// ===== cat_DA @ fffa8d8a (671 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa8eab) */
/* WARNING: Removing unreachable block (ram,0xfffa8e27) */
/* WARNING: Removing unreachable block (ram,0xfffa8ee6) */
/* WARNING: Removing unreachable block (ram,0xfffa8f41) */
/* WARNING: Removing unreachable block (ram,0xfffa9026) */
/* WARNING: Removing unreachable block (ram,0xfffa8ef7) */
/* WARNING: Removing unreachable block (ram,0xfffa8f52) */
/* WARNING: Removing unreachable block (ram,0xfffa8f9c) */
/* WARNING: Removing unreachable block (ram,0xfffa8dd8) */
/* WARNING: Removing unreachable block (ram,0xfffa8e76) */
/* WARNING: Removing unreachable block (ram,0xfffa8fad) */
/* WARNING: Removing unreachable block (ram,0xfffa901a) */

void cat_DA(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte local_f;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    DAT_00001c90 = 0x30;
    DAT_00001c91 = 0x30;
    local_b = 10;
    local_f = DAT_00009be9;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_f;
      if (local_b != 0) {
        bVar3 = local_f / local_b;
      }
      local_f = local_f - bVar3 * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(bVar3);
      (&DAT_00001c92)[local_c] = cVar2;
    }
    local_b = 10;
    local_d = DAT_00009bea;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_d;
      if (local_b != 0) {
        bVar3 = local_d / local_b;
      }
      local_d = local_d - bVar3 * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(bVar3);
      *(char *)((int)&DAT_00001c93 + local_c + 1) = cVar2;
    }
    local_b = 10;
    local_e = DAT_00009b10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar3 = local_e;
      if (local_b != 0) {
        bVar3 = local_e / local_b;
      }
      local_e = local_e - bVar3 * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(bVar3);
      *(char *)((int)&DAT_00001c93 + local_c + 3) = cVar2;
    }
    DAT_00001c98 = 0x3b;
    DAT_0001b788 = 0xb;
    return;
  }
  local_f = 0;
  local_b = 10;
  for (local_c = 4; local_c < 6; local_c = local_c + 1) {
    bVar3 = *(byte *)((uint)local_c + param_1);
    if ((bVar3 < 0x30) || (0x39 < bVar3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    local_f = (bVar3 & 0xf) * local_b + local_f;
    local_b = local_b / 10;
  }
  local_d = 0;
  local_b = 10;
  for (local_c = 6; local_c < 8; local_c = local_c + 1) {
    bVar3 = *(byte *)((uint)local_c + param_1);
    if ((bVar3 < 0x30) || (0x39 < bVar3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    local_d = (bVar3 & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  local_e = 0;
  local_b = 10;
  for (local_c = 8; local_c < 10; local_c = local_c + 1) {
    bVar3 = *(byte *)((uint)local_c + param_1);
    if ((bVar3 < 0x30) || (0x39 < bVar3)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    local_e = (bVar3 & 0xf) * local_b + local_e;
    local_b = local_b / 10;
  }
  if ((local_f < 0x15) && (local_d < 0x15)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (local_e < 0x15)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_00009be9 = local_f;
    DAT_00009bea = local_d;
    DAT_00009b10 = local_e;
    DAT_00020f04 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_DN @ fffa9029 (300 bytes)

void cat_DN(void)

{
  bool bVar1;
  byte bVar2;
  
  bVar2 = key_event_filter(0x34e,0);
  if (bVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  FUN_fffc037b();
  DAT_00020f6f = 0;
  return;
}


// ===== cat_UP @ fffa9155 (300 bytes)

void cat_UP(void)

{
  bool bVar1;
  byte bVar2;
  
  bVar2 = key_event_filter(0x348,0);
  if (bVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f0c == '\0') && (DAT_00020b8a != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd0 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cd1 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  FUN_fffc0335();
  DAT_00020f6f = 0;
  return;
}


// ===== cat_DT @ fffa9281 (967 bytes)

/* WARNING: Removing unreachable block (ram,0xfffa943d) */
/* WARNING: Removing unreachable block (ram,0xfffa93cb) */
/* WARNING: Removing unreachable block (ram,0xfffa940d) */
/* WARNING: Removing unreachable block (ram,0xfffa9491) */
/* WARNING: Removing unreachable block (ram,0xfffa95a3) */
/* WARNING: Removing unreachable block (ram,0xfffa95e5) */

void cat_DT(int param_1,char param_2)

{
  bool bVar1;
  byte local_b;
  byte local_a;
  byte local_9;
  byte local_8;
  byte local_7;
  byte local_6;
  
  bVar1 = *(char *)(param_1 + 2) == '0';
  if (param_2 == '\0') {
    if (bVar1) {
      DAT_00001c91 = 0x32;
      DAT_00001c92 = 0x30;
      FUN_fffb311d(&DAT_00001c93,DAT_00020bb1);
      FUN_fffb311d(0x1c95,DAT_00020bb2);
      FUN_fffb311d(&DAT_00001c97,DAT_00020bb3);
      DAT_00001c99 = 0x3b;
      DAT_0001b788 = 0xc;
      return;
    }
    if (*(char *)(param_1 + 2) == '1') {
      FUN_fffb311d(&DAT_00001c91,DAT_00020bb4);
      FUN_fffb311d(&DAT_00001c93,DAT_00020bb5);
      DAT_00001c93._3_1_ = 0x30;
      DAT_00001c93._2_1_ = 0x30;
      DAT_00001c97 = 0x3b;
      DAT_0001b788 = 10;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (bVar1) {
    for (local_6 = 3; local_6 < 0xb; local_6 = local_6 + 1) {
      if ((*(byte *)((uint)local_6 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_6 + param_1))
         ) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
    }
    local_9 = '\0';
    local_8 = 10;
    for (local_6 = 3; local_6 < 5; local_6 = local_6 + 1) {
      local_9 = (*(byte *)((uint)local_6 + param_1) & 0xf) * local_8 + local_9;
      local_8 = local_8 / 10;
    }
    if (local_9 != '\x14') {
      DAT_0000464a = 1;
      return;
    }
    local_9 = 0;
    local_8 = 10;
    for (local_6 = 5; local_6 < 7; local_6 = local_6 + 1) {
      local_9 = (*(byte *)((uint)local_6 + param_1) & 0xf) * local_8 + local_9;
      local_8 = local_8 / 10;
    }
    local_a = 0;
    local_8 = 10;
    for (local_6 = 7; local_6 < 9; local_6 = local_6 + 1) {
      local_a = (*(byte *)((uint)local_6 + param_1) & 0xf) * local_8 + local_a;
      local_8 = local_8 / 10;
    }
    if ((local_a == 0) || (0xc < local_a)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_b = 0;
      local_8 = 10;
      for (local_6 = 9; local_6 < 0xb; local_6 = local_6 + 1) {
        local_b = (*(byte *)((uint)local_6 + param_1) & 0xf) * local_8 + local_b;
        local_8 = local_8 / 10;
      }
      if (local_a == 2) {
        if ((local_9 & 3) == 0) {
          local_7 = 0x1d;
        }
        else {
          local_7 = 0x1c;
        }
      }
      else if ((((local_a == 4) || (local_a == 6)) || (local_a == 9)) || (local_a == 0xb)) {
        local_7 = 0x1e;
      }
      else {
        local_7 = 0x1f;
      }
      if ((local_b == 0) || (local_7 < local_b)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_0000464a = 1;
        return;
      }
      DAT_00020bb1 = FUN_fffb30b5(param_1 + 5);
      DAT_00020bb6 = DAT_00020bb1;
      DAT_00020bb2 = FUN_fffb30b5(param_1 + 7);
      DAT_00020bb7 = DAT_00020bb2;
      DAT_00020bb3 = FUN_fffb30b5(param_1 + 9);
      DAT_00020bb8 = DAT_00020bb3;
      DAT_00020b91 = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    DAT_0000464a = 1;
    return;
  }
  for (local_6 = 3; local_6 < 9; local_6 = local_6 + 1) {
    if ((*(byte *)((uint)local_6 + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_6 + param_1)))
    {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
  }
  local_7 = 0;
  local_8 = 10;
  for (local_6 = 3; local_6 < 5; local_6 = local_6 + 1) {
    local_7 = (*(byte *)((uint)local_6 + param_1) & 0xf) * local_8 + local_7;
    local_8 = local_8 / 10;
  }
  if (local_7 < 0x18) {
    local_7 = 0;
    local_8 = 10;
    for (local_6 = 5; local_6 < 7; local_6 = local_6 + 1) {
      local_7 = (*(byte *)((uint)local_6 + param_1) & 0xf) * local_8 + local_7;
      local_8 = local_8 / 10;
    }
    if (0x3b < local_7) {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020bb4 = FUN_fffb30b5(param_1 + 3);
    DAT_00020bb9 = DAT_00020bb4;
    DAT_00020bba = FUN_fffb30b5(param_1 + 5);
    DAT_00020bb5 = DAT_00020bba;
    DAT_00020b91 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_EM @ fffa9648 (736 bytes)

void cat_EM(int param_1,byte param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  byte bStack_d;
  
  if (param_2 == 0) {
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    if (*(char *)(param_1 + 3) == '1') {
      cVar2 = FUN_fffb012c(&DAT_0000979e,0xfe,0x32);
      bStack_d = cVar2 + 0x62;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_0000979e;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    else if (*(char *)(param_1 + 3) == '2') {
      cVar2 = FUN_fffb012c(&DAT_000097d0,0xfe,0x32);
      bStack_d = cVar2 + 0x30;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_000097d0;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    else if (*(char *)(param_1 + 3) == '3') {
      cVar2 = FUN_fffb012c(&DAT_00009802,0xfe,0x32);
      bStack_d = cVar2 - 2;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_00009802;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    else if (*(char *)(param_1 + 3) == '4') {
      cVar2 = FUN_fffb012c(&DAT_00009834,0xfe,0x32);
      bStack_d = cVar2 - 0x34;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_00009834;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    else {
      if (*(char *)(param_1 + 3) != '5') {
        DAT_0000464a = 1;
        return;
      }
      cVar2 = FUN_fffb012c(&DAT_00009866,0xfe,0x32);
      bStack_d = cVar2 + 0x9a;
      if ((bStack_d == 0) || (0x32 < bStack_d)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        puVar4 = &DAT_00009866;
        puVar5 = &DAT_00001c92;
        for (uVar6 = (uint)bStack_d; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
      }
    }
    (&DAT_00001c92)[bStack_d] = 0x3b;
    DAT_0001b788 = bStack_d + 5;
    return;
  }
  cVar2 = FUN_fffb012c(param_1,0x3b,0x32);
  bVar3 = (cVar2 - (char)param_1) - 4;
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 3) == '1') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_0000979e;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_0000979e + (uint)bVar3) = 0xfe;
    return;
  }
  if (*(char *)(param_1 + 3) == '2') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_000097d0;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_000097d0 + (uint)bVar3) = 0xfe;
    return;
  }
  if (*(char *)(param_1 + 3) == '3') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_00009802;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_00009802 + (uint)bVar3) = 0xfe;
    return;
  }
  if (*(char *)(param_1 + 3) == '4') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_00009834;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_00009834 + (uint)bVar3) = 0xfe;
    return;
  }
  if (*(char *)(param_1 + 3) == '5') {
    puVar5 = (undefined1 *)(param_1 + 4);
    puVar4 = &DAT_00009866;
    for (uVar6 = (uint)bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar4 = *puVar5;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = puVar5 + 1;
    }
    *(undefined1 *)((int)&DAT_00009866 + (uint)bVar3) = 0xfe;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_EN @ fffa9928 (15 bytes)

void cat_EN(uint param_1)

{
  DAT_0000464a = 1;
  return;
}

