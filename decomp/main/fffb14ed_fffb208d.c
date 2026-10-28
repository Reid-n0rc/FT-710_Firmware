// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== eeprom_write @ fffb14ed (189 bytes)

/* 64-byte page writes: RDSR(0x05) poll WIP, WREN(0x06), WRITE(0x02)+addr+data */

void eeprom_write(ushort addr,byte *buf,ushort n)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte local_c;
  byte bStack_b;
  ushort local_a;
  byte *local_8;
  ushort local_2;
  
  local_a = n;
  local_8 = buf;
  local_2 = addr;
  while (local_a != 0) {
    local_c = 0x40 - ((byte)local_2 & 0x3f);
    if (local_a <= local_c) {
      local_c = (byte)local_a;
    }
    local_a = local_a - local_c;
    bVar2 = true;
    while (bVar2) {
      bVar1 = DAT_0008c02e;
      DAT_0008c02e = bVar1 & 0xfe;
      eeprom_spi_tx(5);
      bVar3 = eeprom_spi_rx();
      bVar1 = DAT_0008c02e;
      DAT_0008c02e = bVar1 | 1;
      if ((bVar3 & 1) == 0) {
        bVar2 = false;
      }
    }
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 & 0xfe;
    eeprom_spi_tx(6);
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 | 1;
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 & 0xfe;
    eeprom_spi_tx(2);
    eeprom_spi_tx((byte)(local_2 >> 8));
    eeprom_spi_tx((byte)local_2);
    for (bStack_b = 0; bStack_b < local_c; bStack_b = bStack_b + 1) {
      eeprom_spi_tx(*local_8);
      local_8 = local_8 + 1;
    }
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 | 1;
    local_2 = local_2 + local_c;
  }
  return;
}


// ===== eeprom_spi_tx @ fffb15aa (69 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb15d6) */
/* Shift one byte out MSB first on PE6, clock PE5 */

void eeprom_spi_tx(byte b)

{
  byte bVar1;
  undefined1 local_2;
  undefined1 local_1;
  
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xdf;
  local_1 = b;
  for (local_2 = 0; local_2 < 8; local_2 = local_2 + 1) {
    if ((local_1 & 0x80) == 0) {
      bVar1 = DAT_0008c02e;
      DAT_0008c02e = bVar1 & 0xbf;
    }
    else {
      bVar1 = DAT_0008c02e;
      DAT_0008c02e = bVar1 | 0x40;
    }
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 | 0x20;
    local_1 = local_1 << 1;
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 & 0xdf;
  }
  return;
}


// ===== eeprom_spi_rx @ fffb15ef (67 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb15f9) */
/* Shift one byte in from PE7 (PIDR bit 7) */

byte eeprom_spi_rx(void)

{
  byte bVar1;
  char cVar2;
  undefined1 local_3;
  undefined1 local_2;
  
  local_3 = 0;
  for (local_2 = 0; local_2 < 8; local_2 = local_2 + 1) {
    local_3 = local_3 << 1;
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 | 0x20;
    cVar2 = DAT_0008c04e;
    if (cVar2 < '\0') {
      local_3 = local_3 | 1;
    }
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 & 0xdf;
  }
  return local_3;
}


// ===== sci_start_all @ fffb1632 (19 bytes)

/* From app_main: sci0_set_baud, displink_uart_start, sci2_configure, sci3_set_baud, SCI4/SCI5 start
    */

void sci_start_all(void)

{
  sci0_set_baud();
  displink_uart_start();
  sci2_configure();
  sci3_set_baud();
  FUN_fffb1a81();
  sdr_link_start();
  return;
}


// ===== sci0_set_baud @ fffb1645 (189 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb16c3) */
/* WARNING: Removing unreachable block (ram,0xfffb1689) */
/* WARNING: Removing unreachable block (ram,0xfffb166d) */
/* WARNING: Removing unreachable block (ram,0xfffb16ad) */
/* WARNING: Removing unreachable block (ram,0xfffb16ce) */
/* WARNING: Removing unreachable block (ram,0xfffb16e5) */
/* Re-configures SCI0 SMR/BRR/SEMR from table 0xFFF80FF4 (4 bytes x 5) by CAT RATE setting */

void sci0_set_baud(void)

{
  byte bVar1;
  byte local_1;
  
  bVar1 = DAT_00009abc;
  local_1 = DAT_00009abc;
  do {
  } while (DAT_00011fe8 != '\0');
  R_SCI0_Stop();
  if (4 < bVar1) {
    local_1 = 0;
  }
  bVar1 = DAT_0008a000;
  DAT_0008a000 = BYTE_ARRAY_fff80ff5[(uint)local_1 * 4 + 1] | bVar1 & 0xfc;
  DAT_0008a001 = BYTE_ARRAY_fff80ff5[(uint)local_1 * 4 + 2];
  bVar1 = DAT_0008a007;
  DAT_0008a007 = bVar1 & 0xbf | (BYTE_ARRAY_fff80fd1[(uint)local_1 * 4 + 0x23] & 1) << 6;
  bVar1 = DAT_0008a007;
  DAT_0008a007 = bVar1 & 0xef | (BYTE_ARRAY_fff80ff5[(uint)local_1 * 4] & 1) << 4;
  R_SCI0_Start();
  R_SCI0_Serial_Receive(0xa2b4,0x29bc);
  return;
}


// ===== displink_uart_start @ fffb1702 (28 bytes)

/* R_SCI1_Start + arm receive 0x9E86/0x204 */

void displink_uart_start(void)

{
  DAT_0000a08a = 0;
  R_SCI1_Start();
  R_SCI1_Serial_Receive(0x9e86,0x204);
  return;
}


// ===== displink_rx_ready @ fffb171e (15 bytes)

/* returns 0xA08A */

byte displink_rx_ready(void)

{
  return DAT_0000a08a;
}


// ===== displink_rx_rearm @ fffb172d (24 bytes)

/* 0xA08A=0, arm receive again */

void displink_rx_rearm(void)

{
  DAT_0000a08a = 0;
  R_SCI1_Serial_Receive(0x9e86,0x204);
  return;
}


// ===== displink_rx_done @ fffb1745 (10 bytes)

/* 0xA08A=1 */

void displink_rx_done(void)

{
  DAT_0000a08a = 1;
  return;
}


// ===== displink_rx_buf @ fffb174f (12 bytes)

/* returns 0x9E86 */

uint displink_rx_buf(void)

{
  return 0x9e86;
}


// ===== displink_uart_send @ fffb175b (16 bytes)

/* R_SCI1_Serial_Send(buf,len) */

void displink_uart_send(uint param_1,ushort param_2)

{
  R_SCI1_Serial_Send(param_1,param_2);
  return;
}


// ===== sci1_tx_end @ fffb176b (19 bytes)

byte sci1_tx_end(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008a024;
  return bVar1 >> 2 & 1;
}


// ===== sci2_configure @ fffb177e (386 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb186a) */
/* WARNING: Removing unreachable block (ram,0xfffb1820) */
/* WARNING: Removing unreachable block (ram,0xfffb1854) */
/* WARNING: Removing unreachable block (ram,0xfffb1875) */
/* WARNING: Removing unreachable block (ram,0xfffb188c) */
/* WARNING: Removing unreachable block (ram,0xfffb1804) */
/* Selects SCI2 mode/pins by tuner/port setting and re-creates SCI2 */

void sci2_configure(void)

{
  uint uVar1;
  byte bVar2;
  byte bStack_3;
  byte bStack_1;
  
  bVar2 = tunlin_port_mode();
  R_SCI2_Stop();
  do {
  } while (DAT_00011fe9 != '\0');
  if (bVar2 != 1) {
    gpo_a_set(0);
    gpo_b_set(0);
    gpo_c_set(0);
    gpo_d_set(0);
  }
  if ((bVar2 == 3) || (bVar2 == 1)) {
    uVar1 = DAT_00080014;
    DAT_00080014 = uVar1 | 0x20000000;
    DAT_0008c14a = 0;
    bVar2 = DAT_0008c061;
    DAT_0008c061 = bVar2 & 0xfb;
    DAT_0008c14b = 0;
    gpo_a_dir_out();
    gpo_b_dir_out();
    gpo_c_dir('\x01');
    tun_lin_sel_set(0);
    rem_key_sel_set(1);
    return;
  }
  if (bVar2 == 2) {
    R_SCI2_Create();
    bStack_1 = DAT_00009abe;
    if (4 < DAT_00009abe) {
      bStack_1 = 3;
    }
    bVar2 = DAT_0008a040;
    bStack_3 = BYTE_ARRAY_fff80ff5[(uint)bStack_1 * 4 + 1] | bVar2 & 0xf4;
    if (DAT_00009abb != '\0') {
      bStack_3 = bStack_3 | 8;
    }
    DAT_0008a040 = bStack_3;
    DAT_0008a041 = BYTE_ARRAY_fff80ff5[(uint)bStack_1 * 4 + 2];
    bVar2 = DAT_0008a047;
    DAT_0008a047 = bVar2 & 0xbf | (BYTE_ARRAY_fff80fd1[(uint)bStack_1 * 4 + 0x23] & 1) << 6;
    bVar2 = DAT_0008a047;
    DAT_0008a047 = bVar2 & 0xef | (BYTE_ARRAY_fff80ff5[(uint)bStack_1 * 4] & 1) << 4;
    R_SCI2_Start();
    R_SCI2_Serial_Receive(0xcc70,0x29bc);
    gpo_c_dir('\x01');
    tun_lin_sel_set(1);
    rem_key_sel_set(0);
    return;
  }
  if (bVar2 == 0) {
    R_SCI2_Create();
    R_SCI2_Start();
    gpo_c_dir('\0');
    tun_lin_sel_set(1);
    rem_key_sel_set(0);
    etun_reset_set('\0');
    return;
  }
  return;
}


// ===== tunlin_port_mode @ fffb1900 (30 bytes)

/* setting 0x9AB7: 0 EXT-TUNER 1 LINEAR 2 CAT-3 3 GPO */

byte tunlin_port_mode(void)

{
  undefined1 local_2;
  
  local_2 = DAT_00009ab7;
  if (3 < DAT_00009ab7) {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffb191e @ fffb191e (15 bytes)

undefined1 FUN_fffb191e(void)

{
  return DAT_0000a0a9;
}


// ===== FUN_fffb192d @ fffb192d (23 bytes)

ushort FUN_fffb192d(void)

{
  ushort uVar1;
  
  DAT_0000a0a9 = 0;
  uVar1 = R_SCI2_Serial_Receive(0xa08b,0x1e);
  return uVar1;
}


// ===== FUN_fffb1944 @ fffb1944 (10 bytes)

void FUN_fffb1944(void)

{
  DAT_0000a0a9 = 1;
  return;
}


// ===== FUN_fffb194e @ fffb194e (12 bytes)

void FUN_fffb194e(void)

{
  return;
}


// ===== FUN_fffb195a @ fffb195a (28 bytes)

void FUN_fffb195a(uint param_1,short param_2)

{
  ushort uVar1;
  
  uVar1 = R_SCI2_Serial_Send(param_1,param_2);
  FUN_fffb192d(uVar1);
  DAT_0000a0aa = 1;
  return;
}


// ===== FUN_fffb1976 @ fffb1976 (10 bytes)

void FUN_fffb1976(void)

{
  DAT_0000a0aa = 0;
  return;
}


// ===== FUN_fffb1980 @ fffb1980 (15 bytes)

undefined1 FUN_fffb1980(void)

{
  return DAT_0000a0aa;
}


// ===== sci3_set_baud @ fffb198f (242 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb1a42) */
/* WARNING: Removing unreachable block (ram,0xfffb1a00) */
/* WARNING: Removing unreachable block (ram,0xfffb19e4) */
/* WARNING: Removing unreachable block (ram,0xfffb1a2c) */
/* WARNING: Removing unreachable block (ram,0xfffb1a4d) */
/* WARNING: Removing unreachable block (ram,0xfffb1a64) */
/* Re-configures SCI3 baud from table 0xFFF80FF4 */

void sci3_set_baud(void)

{
  byte bVar1;
  char local_4;
  byte bStack_3;
  byte local_1;
  
  do {
  } while (DAT_00011fea != '\0');
  if (DAT_00009dc6 == '\0') {
    local_1 = DAT_00009ab9;
    local_4 = DAT_00009abb;
  }
  else {
    local_1 = DAT_00020b58;
    local_4 = DAT_00020b5a;
  }
  R_SCI3_Stop();
  if (4 < local_1) {
    local_1 = 3;
  }
  bVar1 = DAT_0008a060;
  bStack_3 = BYTE_ARRAY_fff80ff5[(uint)local_1 * 4 + 1] | bVar1 & 0xf4;
  if (local_4 != '\0') {
    bStack_3 = bStack_3 | 8;
  }
  DAT_0008a060 = bStack_3;
  DAT_0008a061 = BYTE_ARRAY_fff80ff5[(uint)local_1 * 4 + 2];
  bVar1 = DAT_0008a067;
  DAT_0008a067 = bVar1 & 0xbf | (BYTE_ARRAY_fff80fd1[(uint)local_1 * 4 + 0x23] & 1) << 6;
  bVar1 = DAT_0008a067;
  DAT_0008a067 = bVar1 & 0xef | (BYTE_ARRAY_fff80ff5[(uint)local_1 * 4] & 1) << 4;
  R_SCI3_Start();
  R_SCI3_Serial_Receive(0xf62c,0x29bc);
  return;
}


// ===== FUN_fffb1a81 @ fffb1a81 (14 bytes)

void FUN_fffb1a81(void)

{
  DAT_0000a2ab = 0;
  R_SCI4_Start();
  return;
}


// ===== sci4_rx_ready @ fffb1a8f (15 bytes)

/* Returns 0xA2AB (SCI4 frame complete) */

byte sci4_rx_ready(void)

{
  return DAT_0000a2ab;
}


// ===== sci4_rx_set_ready @ fffb1a9e (10 bytes)

/* 0xA2AB=1 */

void sci4_rx_set_ready(void)

{
  DAT_0000a2ab = 1;
  return;
}


// ===== sci4_rx_buf @ fffb1aa8 (12 bytes)

/* Returns the SCI4 receive buffer (0xA0AB) [decompiler lost the return value] */

uint sci4_rx_buf(void)

{
  return 0xa0ab;
}


// ===== sci4_send @ fffb1ab4 (39 bytes)

/* R_SCI4_Serial_Send then re-arm R_SCI4_Serial_Receive(0xA0AB, 0x200) */

void sci4_send(uint param_1,ushort param_2)

{
  R_SCI4_Serial_Send(param_1,param_2);
  DAT_0000a2ab = 0;
  R_SCI4_Serial_Receive(0xa0ab,0x200);
  return;
}


// ===== sci4_rx_set_len @ fffb1adb (14 bytes)

/* 0x1B78A=len */

void sci4_rx_set_len(ushort param_1)

{
  DAT_0001b78a = param_1;
  return;
}


// ===== sci4_rx_len @ fffb1ae9 (15 bytes)

/* Returns 0x1B78A */

ushort sci4_rx_len(void)

{
  return DAT_0001b78a;
}


// ===== sdr_link_start @ fffb1af8 (14 bytes)

/* Clears the SDR reply-ready flag 0xA2B3 and starts SCI5 (called from the SCI start-up chain
   FUN_fffb1632) */

void sdr_link_start(void)

{
  DAT_0000a2b3 = 0;
  R_SCI5_Start();
  return;
}


// ===== sdr_rx_ready @ fffb1b06 (15 bytes)

/* Returns 0xA2B3: 1 when the 7-byte SDR reply has arrived in 0xA2AC */

byte sdr_rx_ready(void)

{
  return DAT_0000a2b3;
}


// ===== sdr_rx_done_cb @ fffb1b15 (10 bytes)

/* Sets 0xA2B3=1 (SCI5 receive end) */

void sdr_rx_done_cb(void)

{
  DAT_0000a2b3 = 1;
  return;
}


// ===== sdr_rx_buf @ fffb1b1f (12 bytes)

/* Returns 0xA2AC, the 7-byte SDR reply buffer (MOV.L #0xA2AC,R1; decompile lost the return) */

uint sdr_rx_buf(void)

{
  return 0xa2ac;
}


// ===== sdr_send_cmd @ fffb1b2b (37 bytes)

/* R_SCI5_Serial_Send(buf,len) then arm a 7-byte reply receive into 0xA2AC */

void sdr_send_cmd(uint param_1,ushort param_2)

{
  R_SCI5_Serial_Send(param_1,param_2);
  DAT_0000a2b3 = 0;
  R_SCI5_Serial_Receive(0xa2ac,7);
  return;
}


// ===== cat_rx_complete @ fffb1b50 (321 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb1c58) */
/* Receive-complete callback from SCI ISRs (arg1=port id, arg2=len) */

void cat_rx_complete(int param_1,ushort param_2)

{
  bool bVar1;
  char *local_c;
  
  if (param_1 == 1) {
    local_c = &DAT_0000f62c;
  }
  else if (param_1 == 2) {
    local_c = &DAT_0000a2b4;
  }
  else {
    local_c = &DAT_0000cc70;
  }
  if ((*local_c == 'E') || (*local_c == 'e')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if ((local_c[1] == '1') || (local_c[1] == '9')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fffb1bbd;
    }
  }
  bVar1 = false;
LAB_fffb1bbd:
  if (bVar1) {
    if (DAT_0001b78c == '\0') {
      smovf(0x1b790,local_c,(uint)param_2);
      DAT_0001b78c = '\x01';
      DAT_0001b78d = (char)param_1;
      DAT_0001b78e = param_2;
    }
  }
  else if (param_2 < 0x67) {
    (&DAT_0001e14c)[(uint)DAT_00011fec * 0x6a] = (char)param_1;
    *(ushort *)(&DAT_0001e14e + (uint)DAT_00011fec * 0x6a) = param_2;
    smovf((uint)DAT_00011fec * 0x6a + 0x1e150,local_c,(uint)param_2);
    DAT_00011fec = (char)(DAT_00011fec + 1) + (char)((DAT_00011fec + 1) / 0x3c) * -0x3c;
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      R_SCI2_Serial_Receive((uint)local_c,0x29bc);
      return;
    }
    R_SCI0_Serial_Receive((uint)local_c,0x29bc);
    return;
  }
  R_SCI3_Serial_Receive((uint)local_c,0x29bc);
  return;
}


// ===== cat_ring_head @ fffb1c91 (15 bytes)

/* Returns CAT ring head index 0x11FEC (60 slots of 0x6A at 0x1E14C) */

byte cat_ring_head(void)

{
  return DAT_00011fec;
}


// ===== cat_ring_tail @ fffb1ca0 (15 bytes)

/* Returns CAT ring tail index 0x11FEB */

byte cat_ring_tail(void)

{
  return DAT_00011feb;
}


// ===== cat_ring_unpop @ fffb1caf (35 bytes)

/* Steps the CAT ring tail back (port TX busy: retry later) */

void cat_ring_unpop(void)

{
  if (DAT_00011feb != '\0') {
    DAT_00011feb = DAT_00011feb + -1;
    return;
  }
  DAT_00011feb = 0x3b;
  return;
}


// ===== cat_ring_pop @ fffb1cd2 (52 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb1cf5) */
/* Advances the CAT ring tail (mod 60) and returns the slot pointer */

uint cat_ring_pop(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_00011feb;
  DAT_00011feb = (char)(DAT_00011feb + 1) + (char)((DAT_00011feb + 1) / 0x3c) * -0x3c;
  return (uint)(&DAT_0001e14c + uVar1 * 0x6a);
}


// ===== cat_e9_slot @ fffb1d06 (12 bytes)

/* Returns 0x1B78C: single-slot buffer for frames starting E1/E9 (flag, port, len, data) */

uint cat_e9_slot(void)

{
  return 0x1b78c;
}


// ===== cat_send_reply @ fffb1d12 (73 bytes)

/* Send buffer on CAT port (1=SCI3, 2=SCI0, else SCI2), sets per-port busy flag */

void cat_send_reply(int param_1,uint param_2,ushort param_3)

{
  if (param_1 == 1) {
    R_SCI3_Serial_Send(param_2,param_3);
    DAT_00011fea = 1;
    return;
  }
  if (param_1 != 2) {
    R_SCI2_Serial_Send(param_2,param_3);
    DAT_00011fe9 = 1;
    return;
  }
  R_SCI0_Serial_Send(param_2,param_3);
  DAT_00011fe8 = 1;
  return;
}


// ===== cat_tx_done_sci0 @ fffb1d5b (10 bytes)

/* 0x11FE8 = 0 */

void cat_tx_done_sci0(void)

{
  DAT_00011fe8 = 0;
  return;
}


// ===== cat_tx_done_sci2 @ fffb1d65 (10 bytes)

/* 0x11FE9 = 0 */

void cat_tx_done_sci2(void)

{
  DAT_00011fe9 = 0;
  return;
}


// ===== cat_tx_done_sci3 @ fffb1d6f (10 bytes)

/* 0x11FEA = 0 */

void cat_tx_done_sci3(void)

{
  DAT_00011fea = 0;
  return;
}


// ===== FUN_fffb1d79 @ fffb1d79 (52 bytes)

undefined1 FUN_fffb1d79(int param_1)

{
  undefined1 local_6;
  
  if (param_1 == 1) {
    local_6 = DAT_00011fea;
  }
  else if (param_1 == 2) {
    local_6 = DAT_00011fe8;
  }
  else {
    local_6 = DAT_00011fe9;
  }
  return local_6;
}


// ===== cat_rx_byte_hook @ fffb1dad (405 bytes)

/* CAT framing: ';' end, SPR/SPW/SPNW fixed lengths, E9 bulk, inter-byte timeout from CAT TOT
   setting */

uint cat_rx_byte_hook(ushort *param_1,short *param_2,char *param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  ushort local_1a;
  char local_18;
  char local_17;
  char local_16;
  char local_15 [5];
  int local_10;
  char *local_c;
  short *local_8;
  ushort *local_4;
  
  local_10 = param_4;
  local_c = param_3;
  local_8 = param_2;
  local_4 = param_1;
  if ((*param_1 == 0) || (bVar3 = swtimer_expired(param_4), bVar3 != 1)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    cVar1 = *local_c;
    local_c = local_c + -(uint)*local_4;
    *local_c = cVar1;
    *local_4 = 0;
    *local_8 = 0x29bc;
  }
  if (*local_4 == 3) {
    local_18 = local_c[-3];
    local_17 = local_c[-2];
    local_16 = local_c[-1];
    local_15[0] = *local_c;
    toupper_inplace(&local_18);
    toupper_inplace(&local_17);
    toupper_inplace(local_15);
    if ((local_18 == 'S') && (local_17 == 'P')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      if (local_16 != 'N') {
        if (local_16 == 'R') {
          *local_8 = 7;
          goto LAB_fffb1ea5;
        }
        if (local_16 != 'n') {
          if (local_16 == 'W') {
            *local_8 = 8;
          }
          goto LAB_fffb1ea5;
        }
      }
      if (local_15[0] == 'W') {
        *local_8 = 9;
      }
      else {
        *local_8 = 8;
      }
    }
    else {
      if ((local_18 == 'E') && (local_17 == '9')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        *local_8 = 0x29b2;
      }
    }
  }
LAB_fffb1ea5:
  if ((*local_8 == 0x29bc) && (*local_c == ';')) {
    *local_8 = *local_4 + 1;
  }
  if (local_10 == 4) {
    cVar1 = DAT_00009aba;
    if (DAT_00009dc6 != '\0') {
      cVar1 = DAT_00020b59;
    }
  }
  else {
    cVar1 = DAT_00009abd;
    if (local_10 != 5) {
      cVar1 = DAT_00009abf;
    }
  }
  if (cVar1 == '\x01') {
    local_1a = 100;
  }
  else if (cVar1 == '\x02') {
    local_1a = 1000;
  }
  else if (cVar1 == '\x03') {
    local_1a = 3000;
  }
  else {
    local_1a = 10;
  }
  swtimer_start(local_10,local_1a);
  return (uint)local_c;
}


// ===== sci_tx_end @ fffb1f42 (65 bytes)

/* Returns SSR.TEND for CAT port id (1=SCI3, 2=SCI0, other=SCI2) */

byte sci_tx_end(int param_1)

{
  byte bVar1;
  undefined1 local_6;
  
  if (param_1 == 1) {
    bVar1 = DAT_0008a064;
    local_6 = bVar1 >> 2 & 1;
  }
  else if (param_1 == 2) {
    bVar1 = DAT_0008a004;
    local_6 = bVar1 >> 2 & 1;
  }
  else {
    bVar1 = DAT_0008a044;
    local_6 = bVar1 >> 2 & 1;
  }
  return local_6;
}


// ===== shreg_bus_init @ fffb1f83 (108 bytes)

/* idle levels of SDAT0/SCLK0/strobes, PA_PON=1, AF_RESET pulse */

void shreg_bus_init(void)

{
  byte bVar1;
  
  pa_pon_set(1);
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xdf;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0xbf;
  bVar1 = DAT_0008c025;
  DAT_0008c025 = bVar1 & 0xbf;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 | 0x80;
  af_reset_set(0);
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 | 1;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 0x20;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xbf;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 | 0x80;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 | 0x40;
  bVar1 = DAT_0008c020;
  DAT_0008c020 = bVar1 & 0xfb;
  bVar1 = DAT_0008c000;
  DAT_0008c000 = bVar1 | 1;
  bVar1 = DAT_0008c025;
  DAT_0008c025 = bVar1 | 0x40;
  af_reset_set(1);
  return;
}


// ===== bu2505_write @ fffb1fef (158 bytes)

/* (dev 0:Q1005 via SST1 | 4:PA Q4041 via SST5, ch, 10-bit) 14 bits LSB first */

void bu2505_write(int param_1,byte param_2,short param_3)

{
  byte bVar1;
  bool bVar2;
  byte local_9;
  ushort local_8;
  
  if ((param_1 == 0) || (param_1 == 4)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    return;
  }
  local_8 = param_2 & 0xf | param_3 << 4;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xdf;
  for (local_9 = 0; local_9 < 0xe; local_9 = local_9 + 1) {
    if ((local_8 & 1) == 0) {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xef;
    }
    else {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 | 0x10;
    }
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 | 0x20;
    local_8 = local_8 >> 1;
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 & 0xdf;
  }
  if (param_1 == 0) {
    bVar1 = DAT_0008c026;
    DAT_0008c026 = bVar1 | 0x40;
    bVar1 = DAT_0008c026;
    DAT_0008c026 = bVar1 & 0xbf;
    return;
  }
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 0x40;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xbf;
  return;
}


// ===== sst2_write12 @ fffb208d (191 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb20eb) */
/* /SST2 (P67): 12 bits MSB first, high nibble = band code */

void sst2_write12(char param_1,byte param_2)

{
  byte bVar1;
  byte local_5;
  ushort local_4;
  undefined1 local_1;
  
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0x7f;
  if (param_1 == '\b') {
    local_1 = 1;
  }
  else if (param_1 == '\x02') {
    local_1 = 4;
  }
  else if (param_1 == '\x03') {
    local_1 = 0xc;
  }
  else if (param_1 == '\x04') {
    local_1 = 2;
  }
  else if (param_1 == '\x05') {
    local_1 = 10;
  }
  else if (param_1 == '\x06') {
    local_1 = 6;
  }
  else if (param_1 == '\a') {
    local_1 = 0xe;
  }
  else if (param_1 == '\x01') {
    local_1 = 8;
  }
  else {
    local_1 = 0;
  }
  local_4 = CONCAT11(local_1,param_2);
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xdf;
  for (local_5 = 0; local_5 < 0xc; local_5 = local_5 + 1) {
    if ((local_4 & 0x800) == 0) {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xef;
    }
    else {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 | 0x10;
    }
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 | 0x20;
    local_4 = local_4 << 1;
    FUN_fffb2210(0);
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 & 0xdf;
  }
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 | 0x80;
  FUN_fffb2210(0);
  return;
}

