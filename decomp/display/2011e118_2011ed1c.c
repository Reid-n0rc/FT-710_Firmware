// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== rspi0_clear_rx_flag @ 2011e118 (16 bytes)

void rspi0_clear_rx_flag(void)

{
  DAT_20800418 = 0;
  return;
}


// ===== rspi1_clear_rx_flag @ 2011e128 (16 bytes)

void rspi1_clear_rx_flag(void)

{
  DAT_20800419 = 0;
  return;
}


// ===== rspi2_clear_rx_flag @ 2011e138 (16 bytes)

void rspi2_clear_rx_flag(void)

{
  DAT_2080041a = 0;
  return;
}


// ===== rspi3_clear_rx_flag @ 2011e148 (16 bytes)

void rspi3_clear_rx_flag(void)

{
  DAT_2080041b = 0;
  return;
}


// ===== rspi4_clear_rx_flag @ 2011e158 (16 bytes)

void rspi4_clear_rx_flag(void)

{
  DAT_2080041c = 0;
  return;
}


// ===== rspi0_clear_tx_flag @ 2011e168 (16 bytes)

void rspi0_clear_tx_flag(void)

{
  DAT_2080041d = 0;
  return;
}


// ===== rspi1_clear_tx_flag @ 2011e178 (16 bytes)

void rspi1_clear_tx_flag(void)

{
  DAT_2080041e = 0;
  return;
}


// ===== rspi2_clear_tx_flag @ 2011e188 (16 bytes)

void rspi2_clear_tx_flag(void)

{
  DAT_2080041f = 0;
  return;
}


// ===== rspi3_clear_tx_flag @ 2011e198 (16 bytes)

void rspi3_clear_tx_flag(void)

{
  DAT_20800420 = 0;
  return;
}


// ===== rspi4_clear_tx_flag @ 2011e1e0 (16 bytes)

void rspi4_clear_tx_flag(void)

{
  DAT_20800421 = 0;
  return;
}


// ===== rspi0_rx_isr @ 2011e1f0 (80 bytes)

/* SPBFCR RXRST pulse, count 0x208DCE28, flag 0x20800418 */

void rspi0_rx_isr(void)

{
  reg_rmw8(&RSPI_SPBFCR_0,1,6,0x40);
  reg_rmw8(&RSPI_SPBFCR_0,0,6,0x40);
  DAT_208dce28 = DAT_208dce28 + 1;
  DAT_20800418 = 1;
  return;
}


// ===== rspi1_rx_isr @ 2011e240 (80 bytes)

void rspi1_rx_isr(void)

{
  reg_rmw8(&RSPI_SPBFCR_1,1,6,0x40);
  reg_rmw8(&RSPI_SPBFCR_1,0,6,0x40);
  DAT_208dce2c = DAT_208dce2c + 1;
  DAT_20800419 = 1;
  return;
}


// ===== rspi2_rx_isr @ 2011e290 (40 bytes)

/* clear SPRIE, flag */

void rspi2_rx_isr(void)

{
  reg_rmw8(&RSPI_SPCR_2,0,7,0x80);
  DAT_2080041a = 1;
  return;
}


// ===== rspi3_rx_isr @ 2011e2b8 (40 bytes)

void rspi3_rx_isr(void)

{
  reg_rmw8(&RSPI_SPCR_3,0,7,0x80);
  DAT_2080041b = 1;
  return;
}


// ===== rspi4_rx_isr @ 2011e2e0 (40 bytes)

void rspi4_rx_isr(void)

{
  reg_rmw8(&RSPI_SPCR_4,0,7,0x80);
  DAT_2080041c = 1;
  return;
}


// ===== rspi0_tx_isr @ 2011e308 (40 bytes)

/* clear SPTIE, flag 0x2080041D */

void rspi0_tx_isr(void)

{
  reg_rmw8(&RSPI_SPCR_0,0,5,0x20);
  DAT_2080041d = 1;
  return;
}


// ===== rspi1_tx_isr @ 2011e330 (40 bytes)

void rspi1_tx_isr(void)

{
  reg_rmw8(&RSPI_SPCR_1,0,5,0x20);
  DAT_2080041e = 1;
  return;
}


// ===== rspi2_tx_isr @ 2011e358 (40 bytes)

void rspi2_tx_isr(void)

{
  reg_rmw8(&RSPI_SPCR_2,0,5,0x20);
  DAT_2080041f = 1;
  return;
}


// ===== rspi3_tx_isr @ 2011e380 (40 bytes)

void rspi3_tx_isr(void)

{
  reg_rmw8(&RSPI_SPCR_3,0,5,0x20);
  DAT_20800420 = 1;
  return;
}


// ===== rspi4_tx_isr @ 2011e3a8 (40 bytes)

void rspi4_tx_isr(void)

{
  reg_rmw8(&RSPI_SPCR_4,0,5,0x20);
  DAT_20800421 = 1;
  return;
}


// ===== rspi0_tx_wait @ 2011e3d0 (44 bytes)

void rspi0_tx_wait(void)

{
  reg_rmw8(&RSPI_SPCR_0,1,5,0x20);
  do {
  } while (DAT_2080041d == '\0');
  return;
}


// ===== rspi0_read_burst @ 2011e3fc (328 bytes)

/* dummy 0xFF writes, wait RX */

void rspi0_read_burst(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar3;
  uint uVar2;
  
  uVar3 = param_1;
  bVar1 = reg_read8(&RSPI_SPBFCR_0,4,0x30);
  uVar2 = (uint)bVar1;
  bVar1 = reg_read8(&RSPI_SPDCR_0,5,0x60);
  if (bVar1 == 3) {
    reg_rmw8(&RSPI_SPBFCR_0,2,4,0x30,uVar2,uVar3);
  }
  else if (bVar1 == 2) {
    reg_rmw8(&RSPI_SPBFCR_0,1,4,0x30,uVar2,uVar3);
  }
  else {
    reg_rmw8(&RSPI_SPBFCR_0,0,4,0x30,uVar2,uVar3);
  }
  reg_rmw8(&RSPI_SPCR_0,1,7,0x80,uVar2,uVar3);
  uVar3 = param_1;
  while (uVar3 != 0) {
    rspi0_tx_wait();
    rspi0_clear_tx_flag();
    if (bVar1 == 3) {
      RSPI_SPDR_0 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (bVar1 == 2) {
      RSPI_SPDR_0._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
                    /* Data_0 [sfr] */
      RSPI_SPDR_0._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = reg_read16(&RSPI_SPBFDR_0,0,0x3f);
    } while (uVar3 < param_1);
                    /* SPBFCR RXRST pulse, count 0x208DCE28, flag 0x20800418 [doc, inference] */
    rspi0_rx_isr();
  }
  else {
    do {
    } while (DAT_20800418 == '\0');
  }
  reg_rmw8(&RSPI_SPBFCR_0,uVar2,4,0x30);
  return;
}


// ===== rspi1_tx_wait @ 2011e544 (44 bytes)

void rspi1_tx_wait(void)

{
  reg_rmw8(&RSPI_SPCR_1,1,5,0x20);
  do {
  } while (DAT_2080041e == '\0');
  return;
}


// ===== rspi1_read_burst @ 2011e570 (320 bytes)

void rspi1_read_burst(uint param_1,int param_2)

{
  byte reg_read8_ret;
  byte reg_read8_ret_2;
  uint uVar1;
  
  reg_read8_ret = reg_read8(&RSPI_SPBFCR_1,4,0x30);
  reg_read8_ret_2 = reg_read8(&RSPI_SPDCR_1,5,0x60);
  if (reg_read8_ret_2 == 3) {
    reg_rmw8(&RSPI_SPBFCR_1,2,4,0x30);
  }
  else if (reg_read8_ret_2 == 2) {
    reg_rmw8(&RSPI_SPBFCR_1,1,4,0x30);
  }
  else {
    reg_rmw8(&RSPI_SPBFCR_1,0,4,0x30);
  }
  reg_rmw8(&RSPI_SPCR_1,1,7,0x80);
  uVar1 = param_1;
  while (uVar1 != 0) {
    rspi1_tx_wait();
    rspi1_clear_tx_flag();
    if (reg_read8_ret_2 == 3) {
      RSPI_SPDR_1 = 0xffffffff;
      uVar1 = uVar1 - 4;
    }
    else if (reg_read8_ret_2 == 2) {
      RSPI_SPDR_1._0_2_ = 0xffff;
      uVar1 = uVar1 - 2;
    }
    else {
                    /* Data_1 [sfr] */
      RSPI_SPDR_1._0_1_ = 0xff;
      uVar1 = uVar1 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar1 = reg_read16(&RSPI_SPBFDR_1,0,0x3f);
    } while (uVar1 < param_1);
    rspi1_rx_isr();
  }
  else {
    do {
    } while (DAT_20800419 == '\0');
  }
  reg_rmw8(&RSPI_SPBFCR_1,reg_read8_ret,4,0x30);
  return;
}


// ===== rspi2_tx_wait @ 2011e6b0 (44 bytes)

void rspi2_tx_wait(void)

{
  reg_rmw8(&RSPI_SPCR_2,1,5,0x20);
  do {
  } while (DAT_2080041f == '\0');
  return;
}


// ===== rspi2_read_burst @ 2011e6dc (328 bytes)

void rspi2_read_burst(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar3;
  uint uVar2;
  
  uVar3 = param_1;
  bVar1 = reg_read8(&RSPI_SPBFCR_2,4,0x30);
  uVar2 = (uint)bVar1;
  bVar1 = reg_read8(&RSPI_SPDCR_2,5,0x60);
  if (bVar1 == 3) {
    reg_rmw8(&RSPI_SPBFCR_2,2,4,0x30,uVar2,uVar3);
  }
  else if (bVar1 == 2) {
    reg_rmw8(&RSPI_SPBFCR_2,1,4,0x30,uVar2,uVar3);
  }
  else {
    reg_rmw8(&RSPI_SPBFCR_2,0,4,0x30,uVar2,uVar3);
  }
  reg_rmw8(&RSPI_SPCR_2,1,7,0x80,uVar2,uVar3);
  uVar3 = param_1;
  while (uVar3 != 0) {
    rspi2_tx_wait();
    rspi2_clear_tx_flag();
    if (bVar1 == 3) {
      RSPI_SPDR_2 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (bVar1 == 2) {
      RSPI_SPDR_2._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
                    /* Data_2 [sfr] */
      RSPI_SPDR_2._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = reg_read16(&RSPI_SPBFDR_2,0,0x3f);
    } while (uVar3 < param_1);
                    /* clear SPRIE, flag [doc, inference] */
    rspi2_rx_isr();
  }
  else {
    do {
    } while (DAT_2080041a == '\0');
  }
  reg_rmw8(&RSPI_SPBFCR_2,uVar2,4,0x30);
  return;
}


// ===== rspi3_tx_wait @ 2011e824 (44 bytes)

void rspi3_tx_wait(void)

{
  reg_rmw8(&RSPI_SPCR_3,1,5,0x20);
  do {
  } while (DAT_20800420 == '\0');
  return;
}


// ===== rspi3_read_burst @ 2011e850 (320 bytes)

void rspi3_read_burst(uint param_1,int param_2)

{
  byte reg_read8_ret;
  byte reg_read8_ret_2;
  uint uVar1;
  
  reg_read8_ret = reg_read8(&RSPI_SPBFCR_3,4,0x30);
  reg_read8_ret_2 = reg_read8(&RSPI_SPDCR_3,5,0x60);
  if (reg_read8_ret_2 == 3) {
    reg_rmw8(&RSPI_SPBFCR_3,2,4,0x30);
  }
  else if (reg_read8_ret_2 == 2) {
    reg_rmw8(&RSPI_SPBFCR_3,1,4,0x30);
  }
  else {
    reg_rmw8(&RSPI_SPBFCR_3,0,4,0x30);
  }
  reg_rmw8(&RSPI_SPCR_3,1,7,0x80);
  uVar1 = param_1;
  while (uVar1 != 0) {
    rspi3_tx_wait();
    rspi3_clear_tx_flag();
    if (reg_read8_ret_2 == 3) {
      RSPI_SPDR_3 = 0xffffffff;
      uVar1 = uVar1 - 4;
    }
    else if (reg_read8_ret_2 == 2) {
      RSPI_SPDR_3._0_2_ = 0xffff;
      uVar1 = uVar1 - 2;
    }
    else {
                    /* Data_3 [sfr] */
      RSPI_SPDR_3._0_1_ = 0xff;
      uVar1 = uVar1 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar1 = reg_read16(&RSPI_SPBFDR_3,0,0x3f);
    } while (uVar1 < param_1);
    rspi3_rx_isr();
  }
  else {
    do {
    } while (DAT_2080041b == '\0');
  }
  reg_rmw8(&RSPI_SPBFCR_3,reg_read8_ret,4,0x30);
  return;
}


// ===== rspi4_tx_wait @ 2011e990 (44 bytes)

void rspi4_tx_wait(void)

{
  reg_rmw8(&RSPI_SPCR_4,1,5,0x20);
  do {
  } while (DAT_20800421 == '\0');
  return;
}


// ===== rspi4_read_burst @ 2011e9bc (328 bytes)

void rspi4_read_burst(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar3;
  uint uVar2;
  
  uVar3 = param_1;
  bVar1 = reg_read8(&RSPI_SPBFCR_4,4,0x30);
  uVar2 = (uint)bVar1;
  bVar1 = reg_read8(&RSPI_SPDCR_4,5,0x60);
  if (bVar1 == 3) {
    reg_rmw8(&RSPI_SPBFCR_4,2,4,0x30,uVar2,uVar3);
  }
  else if (bVar1 == 2) {
    reg_rmw8(&RSPI_SPBFCR_4,1,4,0x30,uVar2,uVar3);
  }
  else {
    reg_rmw8(&RSPI_SPBFCR_4,0,4,0x30,uVar2,uVar3);
  }
  reg_rmw8(&RSPI_SPCR_4,1,7,0x80,uVar2,uVar3);
  uVar3 = param_1;
  while (uVar3 != 0) {
    rspi4_tx_wait();
    rspi4_clear_tx_flag();
    if (bVar1 == 3) {
      RSPI_SPDR_4 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (bVar1 == 2) {
      RSPI_SPDR_4._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
                    /* Data_4 [sfr] */
      RSPI_SPDR_4._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = reg_read16(&RSPI_SPBFDR_4,0,0x3f);
    } while (uVar3 < param_1);
    rspi4_rx_isr();
  }
  else {
    do {
    } while (DAT_2080041c == '\0');
  }
  reg_rmw8(&RSPI_SPBFCR_4,uVar2,4,0x30);
  return;
}


// ===== rspi0_wait_tend @ 2011eb58 (36 bytes)

/* SPSR.TEND */

void rspi0_wait_tend(void)

{
  byte reg_read8_ret;
  
  do {
    reg_read8_ret = reg_read8(&RSPI_SPSR_0,6,0x40);
  } while (reg_read8_ret == 0);
  return;
}


// ===== rspi1_wait_tend @ 2011eb7c (36 bytes)

void rspi1_wait_tend(void)

{
  byte reg_read8_ret;
  
  do {
    reg_read8_ret = reg_read8(&RSPI_SPSR_1,6,0x40);
  } while (reg_read8_ret == 0);
  return;
}


// ===== rspi2_wait_tend @ 2011eba0 (36 bytes)

void rspi2_wait_tend(void)

{
  byte reg_read8_ret;
  
  do {
    reg_read8_ret = reg_read8(&RSPI_SPSR_2,6,0x40);
  } while (reg_read8_ret == 0);
  return;
}


// ===== rspi3_wait_tend @ 2011ebc4 (36 bytes)

void rspi3_wait_tend(void)

{
  byte reg_read8_ret;
  
  do {
    reg_read8_ret = reg_read8(&RSPI_SPSR_3,6,0x40);
  } while (reg_read8_ret == 0);
  return;
}


// ===== rspi4_wait_tend @ 2011ebe8 (36 bytes)

void rspi4_wait_tend(void)

{
  byte reg_read8_ret;
  
  do {
    reg_read8_ret = reg_read8(&RSPI_SPSR_4,6,0x40);
  } while (reg_read8_ret == 0);
  return;
}


// ===== rspi0_delay @ 2011ec0c (40 bytes)

void rspi0_delay(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== rspi1_delay @ 2011ec34 (40 bytes)

void rspi1_delay(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== rspi2_delay @ 2011ec5c (40 bytes)

void rspi2_delay(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== rspi3_delay @ 2011ec84 (40 bytes)

void rspi3_delay(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== rspi4_delay @ 2011ecac (40 bytes)

void rspi4_delay(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10;
  do {
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}


// ===== rspi0_spti_isr @ 2011ecd4 (8 bytes)

/* stub, needs entries_display.T11d.tsv */

void rspi0_spti_isr(void)

{
  rspi_tx_isr(0);
  return;
}


// ===== rspi0_spri_isr @ 2011ecdc (8 bytes)

/* stub */

void rspi0_spri_isr(void)

{
  rspi_rx_isr(0);
  return;
}


// ===== rspi1_spti_isr @ 2011ece4 (8 bytes)

/* stub */

void rspi1_spti_isr(void)

{
  rspi_tx_isr(1);
  return;
}


// ===== rspi1_spri_isr @ 2011ecec (8 bytes)

/* stub */

void rspi1_spri_isr(void)

{
  rspi_rx_isr(1);
  return;
}


// ===== rspi2_spti_isr @ 2011ecf4 (8 bytes)

/* stub */

void rspi2_spti_isr(void)

{
  rspi_tx_isr(2);
  return;
}


// ===== rspi2_spri_isr @ 2011ecfc (8 bytes)

/* stub */

void rspi2_spri_isr(void)

{
  rspi_rx_isr(2);
  return;
}


// ===== rspi3_spti_isr @ 2011ed04 (8 bytes)

/* stub */

void rspi3_spti_isr(void)

{
  rspi_tx_isr(3);
  return;
}


// ===== rspi3_spri_isr @ 2011ed0c (8 bytes)

/* stub */

void rspi3_spri_isr(void)

{
  rspi_rx_isr(3);
  return;
}


// ===== rspi4_spti_isr @ 2011ed14 (8 bytes)

/* stub */

void rspi4_spti_isr(void)

{
  rspi_tx_isr(4);
  return;
}


// ===== rspi4_spri_isr @ 2011ed1c (8 bytes)

/* stub */

void rspi4_spri_isr(void)

{
  rspi_rx_isr(4);
  return;
}

