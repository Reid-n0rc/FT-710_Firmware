// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffb12e6 @ fffb12e6 (29 bytes)

void FUN_fffb12e6(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_fff80f21;
  puVar1 = &DAT_00009b01;
  for (iVar3 = 0x23; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== FUN_fffb1303 @ fffb1303 (34 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffb1303(void)

{
  _DAT_00009b2c = 0;
  _DAT_00009b28 = 0;
  _DAT_00009b24 = 0;
  return;
}


// ===== FUN_fffb1325 @ fffb1325 (189 bytes)

void FUN_fffb1325(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_fff80f4e;
  puVar1 = &DAT_00009b2e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009b4d;
  puVar2 = &DAT_fff80f4e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009b6c;
  puVar2 = &DAT_fff80f4e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009b8b;
  puVar2 = &DAT_fff80f4e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009baa;
  puVar2 = &DAT_fff80f4e;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = *puVar2;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar2 = puVar2 + 1;
  }
  DAT_00009b2e = 0x382d5446;
  DAT_00009b51._2_1_ = 0x32;
  DAT_00009b51._0_2_ = 0x5445;
  DAT_00009b4d = 0x53455250;
  DAT_00009b70._0_2_ = 0x5445;
  DAT_00009b70._2_1_ = 0x33;
  DAT_00009b6c = 0x53455250;
  DAT_00009b8f._2_1_ = 0x34;
  DAT_00009b8f._0_2_ = 0x5445;
  DAT_00009b8b = 0x53455250;
  DAT_00009bae._2_1_ = 0x35;
  DAT_00009bae._0_2_ = 0x5445;
  DAT_00009baa = 0x53455250;
  DAT_00009bc9 = 0;
  return;
}


// ===== FUN_fffb13e2 @ fffb13e2 (73 bytes)

void FUN_fffb13e2(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = "2222222222222222222222222222";
  pcVar1 = &DAT_00009bca;
  for (iVar3 = 0x4d; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcVar1 = *pcVar2;
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
  }
  DAT_00009bf8 = DAT_00009aee;
  DAT_00009bf9 = DAT_00009aef;
  DAT_00009bfa = DAT_00009af0;
  DAT_00009bfb = DAT_00009af1;
  return;
}


// ===== eeprom_hdr_update @ fffb142b (121 bytes)

/* Increments the save counter in the EEPROM header mirror 0x464F and writes 10 bytes at EEPROM 0 */

void eeprom_hdr_update(undefined1 param_1)

{
  uint local_8;
  byte local_2;
  
  local_8 = 0;
  for (local_2 = 0; local_2 < 4; local_2 = local_2 + 1) {
    local_8 = (uint)*(byte *)((int)&DAT_00004653 + local_2 + 1) << (3 - local_2 & 3) * 8 | local_8;
  }
  for (local_2 = 0; local_2 < 4; local_2 = local_2 + 1) {
    *(char *)((int)&DAT_00004653 + local_2 + 1) = (char)(local_8 + 1 >> ((3 - local_2 & 3) << 3));
  }
  DAT_00004657._1_1_ = param_1;
  eeprom_write(0,&DAT_0000464f,10);
  return;
}


// ===== eeprom_read @ fffb14a4 (73 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfffb14a4) */
/* WARNING: Removing unreachable block (ram,0xfffb14ea) */
/* SPI READ (0x03) + 16-bit address, reads n bytes */

ushort eeprom_read(undefined1 param_1,int param_2,ushort param_3)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 local_10;
  
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xfe;
  eeprom_spi_tx(3);
  eeprom_spi_tx();
  eeprom_spi_tx(param_1);
  for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
    uVar2 = eeprom_spi_rx();
    *(undefined1 *)((uint)local_10 + param_2) = uVar2;
  }
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 | 1;
  return local_10;
}


// ===== eeprom_write @ fffb14ed (189 bytes)

/* 64-byte page writes: RDSR(0x05) poll WIP, WREN(0x06), WRITE(0x02)+addr+data */

void eeprom_write(byte param_1,undefined1 *param_2,ushort param_3)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte local_c;
  byte bStack_b;
  ushort local_a;
  undefined1 *local_8;
  
  local_a = param_3;
  local_8 = param_2;
  while (local_a != 0) {
    local_c = 0x40 - (param_1 & 0x3f);
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
    eeprom_spi_tx();
    eeprom_spi_tx(param_1);
    for (bStack_b = 0; bStack_b < local_c; bStack_b = bStack_b + 1) {
      eeprom_spi_tx(*local_8);
      local_8 = local_8 + 1;
    }
    bVar1 = DAT_0008c02e;
    DAT_0008c02e = bVar1 | 1;
    param_1 = param_1 + local_c;
  }
  return;
}


// ===== eeprom_spi_tx @ fffb15aa (69 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb15d6) */
/* Shift one byte out MSB first on PE6, clock PE5 */

void eeprom_spi_tx(byte param_1)

{
  byte bVar1;
  undefined1 local_2;
  undefined1 local_1;
  
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xdf;
  local_1 = param_1;
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


// ===== FUN_fffb1632 @ fffb1632 (19 bytes)

void FUN_fffb1632(void)

{
  sci0_set_baud();
  FUN_fffb1702();
  sci2_configure();
  sci3_set_baud();
  FUN_fffb1a81();
  FUN_fffb1af8();
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
  DAT_0008a000 = (&DAT_fff80ff6)[(uint)local_1 * 4] | bVar1 & 0xfc;
  DAT_0008a001 = (&DAT_fff80ff7)[(uint)local_1 * 4];
  bVar1 = DAT_0008a007;
  DAT_0008a007 = bVar1 & 0xbf | ((&sci_baud_table)[(uint)local_1 * 4] & 1) << 6;
  bVar1 = DAT_0008a007;
  DAT_0008a007 = bVar1 & 0xef | ((&DAT_fff80ff5)[(uint)local_1 * 4] & 1) << 4;
  R_SCI0_Start();
  R_SCI0_Serial_Receive(&DAT_0000a2b4,&DAT_000029bc);
  return;
}


// ===== FUN_fffb1702 @ fffb1702 (28 bytes)

void FUN_fffb1702(void)

{
  DAT_0000a08a = 0;
  FUN_fff935ef();
  R_SCI1_Serial_Receive(&DAT_00009e86,0x204);
  return;
}


// ===== FUN_fffb171e @ fffb171e (15 bytes)

undefined1 FUN_fffb171e(void)

{
  return DAT_0000a08a;
}


// ===== FUN_fffb172d @ fffb172d (24 bytes)

void FUN_fffb172d(void)

{
  DAT_0000a08a = 0;
  R_SCI1_Serial_Receive(&DAT_00009e86,0x204);
  return;
}


// ===== FUN_fffb1745 @ fffb1745 (10 bytes)

void FUN_fffb1745(void)

{
  DAT_0000a08a = 1;
  return;
}


// ===== FUN_fffb174f @ fffb174f (12 bytes)

void FUN_fffb174f(void)

{
  return;
}


// ===== FUN_fffb175b @ fffb175b (16 bytes)

void FUN_fffb175b(undefined4 param_1,undefined2 param_2)

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
  char cVar3;
  byte bStack_3;
  byte bStack_1;
  
  cVar3 = FUN_fffb1900();
  R_SCI2_Stop();
  do {
  } while (DAT_00011fe9 != '\0');
  if (cVar3 != '\x01') {
    FUN_fffb714d(0);
    FUN_fffb7165(0);
    FUN_fffb717d(0);
    FUN_fffb7193(0);
  }
  if ((cVar3 == '\x03') || (cVar3 == '\x01')) {
    uVar1 = DAT_00080014;
    DAT_00080014 = uVar1 | 0x20000000;
    DAT_0008c14a = 0;
    bVar2 = DAT_0008c061;
    DAT_0008c061 = bVar2 & 0xfb;
    DAT_0008c14b = 0;
    FUN_fffb7110();
    FUN_fffb711c();
    FUN_fffb7128(1);
    FUN_fffb70df(0);
    FUN_fffb70f7(1);
    return;
  }
  if (cVar3 == '\x02') {
    R_SCI2_Create();
    bStack_1 = DAT_00009abe;
    if (4 < DAT_00009abe) {
      bStack_1 = 3;
    }
    bVar2 = DAT_0008a040;
    bStack_3 = (&DAT_fff80ff6)[(uint)bStack_1 * 4] | bVar2 & 0xf4;
    if (DAT_00009abb != '\0') {
      bStack_3 = bStack_3 | 8;
    }
    DAT_0008a040 = bStack_3;
    DAT_0008a041 = (&DAT_fff80ff7)[(uint)bStack_1 * 4];
    bVar2 = DAT_0008a047;
    DAT_0008a047 = bVar2 & 0xbf | ((&sci_baud_table)[(uint)bStack_1 * 4] & 1) << 6;
    bVar2 = DAT_0008a047;
    DAT_0008a047 = bVar2 & 0xef | ((&DAT_fff80ff5)[(uint)bStack_1 * 4] & 1) << 4;
    FUN_fff93b29();
    R_SCI2_Serial_Receive(&DAT_0000cc70,&DAT_000029bc);
    FUN_fffb7128(1);
    FUN_fffb70df(1);
    FUN_fffb70f7(0);
    return;
  }
  if (cVar3 == '\0') {
    R_SCI2_Create();
    FUN_fff93b29();
    FUN_fffb7128(0);
    FUN_fffb70df(1);
    FUN_fffb70f7(0);
    FUN_fffb71ff(0);
    return;
  }
  return;
}


// ===== FUN_fffb1900 @ fffb1900 (30 bytes)

byte FUN_fffb1900(void)

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

void FUN_fffb192d(void)

{
  DAT_0000a0a9 = 0;
  R_SCI2_Serial_Receive(&DAT_0000a08b,0x1e);
  return;
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

void FUN_fffb195a(undefined4 param_1,undefined2 param_2)

{
  R_SCI2_Serial_Send(param_1,param_2);
  FUN_fffb192d();
  DAT_0000a0aa = 1;
  return;
}


// ===== FUN_fffb1976 @ fffb1976 (10 bytes)

void FUN_fffb1976(void)

{
  DAT_0000a0aa = 0;
  return;
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
  bStack_3 = (&DAT_fff80ff6)[(uint)local_1 * 4] | bVar1 & 0xf4;
  if (local_4 != '\0') {
    bStack_3 = bStack_3 | 8;
  }
  DAT_0008a060 = bStack_3;
  DAT_0008a061 = (&DAT_fff80ff7)[(uint)local_1 * 4];
  bVar1 = DAT_0008a067;
  DAT_0008a067 = bVar1 & 0xbf | ((&sci_baud_table)[(uint)local_1 * 4] & 1) << 6;
  bVar1 = DAT_0008a067;
  DAT_0008a067 = bVar1 & 0xef | ((&DAT_fff80ff5)[(uint)local_1 * 4] & 1) << 4;
  FUN_fff93fb0();
  R_SCI3_Serial_Receive(&DAT_0000f62c,&DAT_000029bc);
  return;
}


// ===== FUN_fffb1a81 @ fffb1a81 (14 bytes)

void FUN_fffb1a81(void)

{
  DAT_0000a2ab = 0;
  FUN_fff942df();
  return;
}


// ===== FUN_fffb1a8f @ fffb1a8f (15 bytes)

undefined1 FUN_fffb1a8f(void)

{
  return DAT_0000a2ab;
}


// ===== FUN_fffb1a9e @ fffb1a9e (10 bytes)

void FUN_fffb1a9e(void)

{
  DAT_0000a2ab = 1;
  return;
}


// ===== FUN_fffb1aa8 @ fffb1aa8 (12 bytes)

void FUN_fffb1aa8(void)

{
  return;
}


// ===== FUN_fffb1ab4 @ fffb1ab4 (39 bytes)

void FUN_fffb1ab4(undefined4 param_1,undefined2 param_2)

{
  R_SCI4_Serial_Send(param_1,param_2);
  DAT_0000a2ab = 0;
  R_SCI4_Serial_Receive(&DAT_0000a0ab,0x200);
  return;
}


// ===== FUN_fffb1adb @ fffb1adb (14 bytes)

void FUN_fffb1adb(undefined2 param_1)

{
  DAT_0001b78a = param_1;
  return;
}


// ===== FUN_fffb1ae9 @ fffb1ae9 (15 bytes)

undefined2 FUN_fffb1ae9(void)

{
  return DAT_0001b78a;
}


// ===== FUN_fffb1af8 @ fffb1af8 (14 bytes)

void FUN_fffb1af8(void)

{
  DAT_0000a2b3 = 0;
  FUN_fff94705();
  return;
}


// ===== FUN_fffb1b06 @ fffb1b06 (15 bytes)

undefined1 FUN_fffb1b06(void)

{
  return DAT_0000a2b3;
}


// ===== FUN_fffb1b15 @ fffb1b15 (10 bytes)

void FUN_fffb1b15(void)

{
  DAT_0000a2b3 = 1;
  return;
}


// ===== FUN_fffb1b1f @ fffb1b1f (12 bytes)

void FUN_fffb1b1f(void)

{
  return;
}


// ===== sdr_send_cmd @ fffb1b2b (37 bytes)

/* R_SCI5_Serial_Send(buf,len) then arm a 7-byte reply receive into 0xA2AC */

void sdr_send_cmd(undefined4 param_1,undefined2 param_2)

{
  R_SCI5_Serial_Send(param_1,param_2);
  DAT_0000a2b3 = 0;
  R_SCI5_Serial_Receive(&DAT_0000a2ac,7);
  return;
}


// ===== cat_rx_complete @ fffb1b50 (321 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb1c58) */
/* Receive-complete callback from SCI ISRs (arg1=port id, arg2=len) */

void cat_rx_complete(int param_1,ushort param_2)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
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
      pcVar2 = &DAT_0001b790;
      pcVar3 = local_c;
      DAT_0001b78d = (char)param_1;
      DAT_0001b78e = param_2;
      for (uVar4 = (uint)param_2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar2 = *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      }
      DAT_0001b78c = '\x01';
    }
  }
  else if (param_2 < 0x67) {
    (&DAT_0001e14c)[(uint)DAT_00011fec * 0x6a] = (char)param_1;
    *(ushort *)(&DAT_0001e14e + (uint)DAT_00011fec * 0x6a) = param_2;
    pcVar2 = &DAT_0001e150 + (uint)DAT_00011fec * 0x6a;
    pcVar3 = local_c;
    for (uVar4 = (uint)param_2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    DAT_00011fec = (char)(DAT_00011fec + 1) + (char)((DAT_00011fec + 1) / 0x3c) * -0x3c;
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      R_SCI2_Serial_Receive(local_c,&DAT_000029bc);
      return;
    }
    R_SCI0_Serial_Receive(local_c,&DAT_000029bc);
    return;
  }
  R_SCI3_Serial_Receive(local_c,&DAT_000029bc);
  return;
}


// ===== cat_ring_head @ fffb1c91 (15 bytes)

/* Returns CAT ring head index 0x11FEC (60 slots of 0x6A at 0x1E14C) */

undefined1 cat_ring_head(void)

{
  return DAT_00011fec;
}


// ===== cat_ring_tail @ fffb1ca0 (15 bytes)

/* Returns CAT ring tail index 0x11FEB */

undefined1 cat_ring_tail(void)

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

void cat_ring_pop(void)

{
  DAT_00011feb = (char)(DAT_00011feb + 1) + (char)((DAT_00011feb + 1) / 0x3c) * -0x3c;
  return;
}


// ===== cat_e9_slot @ fffb1d06 (12 bytes)

/* Returns 0x1B78C: single-slot buffer for frames starting E1/E9 (flag, port, len, data) */

void cat_e9_slot(void)

{
  return;
}


// ===== cat_send_reply @ fffb1d12 (73 bytes)

/* Send buffer on CAT port (1=SCI3, 2=SCI0, else SCI2), sets per-port busy flag */

void cat_send_reply(int param_1,undefined4 param_2,undefined2 param_3)

{
  if (param_1 == 1) {
    R_SCI3_Serial_Send(param_2,param_3);
    DAT_00011fea = 1;
    return;
  }
  if (param_1 != 2) {
    R_SCI2_Serial_Send();
    DAT_00011fe9 = 1;
    return;
  }
  R_SCI0_Serial_Send(param_2,param_3);
  DAT_00011fe8 = 1;
  return;
}


// ===== FUN_fffb1d5b @ fffb1d5b (10 bytes)

void FUN_fffb1d5b(void)

{
  DAT_00011fe8 = 0;
  return;
}


// ===== FUN_fffb1d65 @ fffb1d65 (10 bytes)

void FUN_fffb1d65(void)

{
  DAT_00011fe9 = 0;
  return;
}


// ===== FUN_fffb1d6f @ fffb1d6f (10 bytes)

void FUN_fffb1d6f(void)

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

