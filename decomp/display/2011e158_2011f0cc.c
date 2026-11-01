// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

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
      RSPI_SPDR_0._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = reg_read16(&RSPI_SPBFDR_0,0,0x3f);
    } while (uVar3 < param_1);
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
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar1 = reg_read8(&RSPI_SPBFCR_1,4,0x30);
  bVar2 = reg_read8(&RSPI_SPDCR_1,5,0x60);
  if (bVar2 == 3) {
    reg_rmw8(&RSPI_SPBFCR_1,2,4,0x30);
  }
  else if (bVar2 == 2) {
    reg_rmw8(&RSPI_SPBFCR_1,1,4,0x30);
  }
  else {
    reg_rmw8(&RSPI_SPBFCR_1,0,4,0x30);
  }
  reg_rmw8(&RSPI_SPCR_1,1,7,0x80);
  uVar3 = param_1;
  while (uVar3 != 0) {
    rspi1_tx_wait();
    rspi1_clear_tx_flag();
    if (bVar2 == 3) {
      RSPI_SPDR_1 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (bVar2 == 2) {
      RSPI_SPDR_1._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
      RSPI_SPDR_1._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = reg_read16(&RSPI_SPBFDR_1,0,0x3f);
    } while (uVar3 < param_1);
    rspi1_rx_isr();
  }
  else {
    do {
    } while (DAT_20800419 == '\0');
  }
  reg_rmw8(&RSPI_SPBFCR_1,bVar1,4,0x30);
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
      RSPI_SPDR_2._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = reg_read16(&RSPI_SPBFDR_2,0,0x3f);
    } while (uVar3 < param_1);
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
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar1 = reg_read8(&RSPI_SPBFCR_3,4,0x30);
  bVar2 = reg_read8(&RSPI_SPDCR_3,5,0x60);
  if (bVar2 == 3) {
    reg_rmw8(&RSPI_SPBFCR_3,2,4,0x30);
  }
  else if (bVar2 == 2) {
    reg_rmw8(&RSPI_SPBFCR_3,1,4,0x30);
  }
  else {
    reg_rmw8(&RSPI_SPBFCR_3,0,4,0x30);
  }
  reg_rmw8(&RSPI_SPCR_3,1,7,0x80);
  uVar3 = param_1;
  while (uVar3 != 0) {
    rspi3_tx_wait();
    rspi3_clear_tx_flag();
    if (bVar2 == 3) {
      RSPI_SPDR_3 = 0xffffffff;
      uVar3 = uVar3 - 4;
    }
    else if (bVar2 == 2) {
      RSPI_SPDR_3._0_2_ = 0xffff;
      uVar3 = uVar3 - 2;
    }
    else {
      RSPI_SPDR_3._0_1_ = 0xff;
      uVar3 = uVar3 - 1;
    }
  }
  if (param_2 == 1) {
    do {
      uVar3 = reg_read16(&RSPI_SPBFDR_3,0,0x3f);
    } while (uVar3 < param_1);
    rspi3_rx_isr();
  }
  else {
    do {
    } while (DAT_2080041b == '\0');
  }
  reg_rmw8(&RSPI_SPBFCR_3,bVar1,4,0x30);
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
  byte bVar1;
  
  do {
    bVar1 = reg_read8(&RSPI_SPSR_0,6,0x40);
  } while (bVar1 == 0);
  return;
}


// ===== rspi1_wait_tend @ 2011eb7c (36 bytes)

void rspi1_wait_tend(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8(&RSPI_SPSR_1,6,0x40);
  } while (bVar1 == 0);
  return;
}


// ===== rspi2_wait_tend @ 2011eba0 (36 bytes)

void rspi2_wait_tend(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8(&RSPI_SPSR_2,6,0x40);
  } while (bVar1 == 0);
  return;
}


// ===== rspi3_wait_tend @ 2011ebc4 (36 bytes)

void rspi3_wait_tend(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8(&RSPI_SPSR_3,6,0x40);
  } while (bVar1 == 0);
  return;
}


// ===== rspi4_wait_tend @ 2011ebe8 (36 bytes)

void rspi4_wait_tend(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8(&RSPI_SPSR_4,6,0x40);
  } while (bVar1 == 0);
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


// ===== rspi_hw_config_master @ 2011ed24 (676 bytes)

/* (ch, spbr, brdv, loopback); no callers */

void rspi_hw_config_master(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_RSPI_SPCR_0_20166b4c + param_1 * 0xb;
  reg_rmw8(*ppuVar1,0,6,0x40);
  reg_rmw8((&PTR_RSPI_SPPCR_0_20166b50)[param_1 * 0xb],0,5,0x20);
  reg_rmw8((&PTR_RSPI_SPPCR_0_20166b50)[param_1 * 0xb],0,4,0x10);
  reg_rmw8((&PTR_RSPI_SPPCR_0_20166b50)[param_1 * 0xb],param_4,0,1);
  reg_rmw8((&PTR_RSPI_SPBR_0_20166b54)[param_1 * 0xb],param_2,0,0xff);
  reg_rmw8((&PTR_RSPI_SPDCR_0_20166b58)[param_1 * 0xb],0,7,0x80);
  reg_rmw8((&PTR_RSPI_SPDCR_0_20166b58)[param_1 * 0xb],1,5,0x60);
  reg_rmw8((&PTR_RSPI_SPCKD_0_20166b5c)[param_1 * 0xb],7,0);
  reg_rmw8((&PTR_RSPI_SSLND_0_20166b60)[param_1 * 0xb],0,0,7);
  reg_rmw8((&PTR_RSPI_SPND_0_20166b64)[param_1 * 0xb],0,0,7);
  reg_rmw8((&PTR_RSPI_SPSCR_0_20166b68)[param_1 * 0xb],0,0,3);
  reg_rmw16((&PTR_RSPI_SPCMD0_0_20166b6c)[param_1 * 0xb],1,0xf,0x8000);
  reg_rmw16((&PTR_RSPI_SPCMD0_0_20166b6c)[param_1 * 0xb],1,0xe,0x4000);
  reg_rmw16((&PTR_RSPI_SPCMD0_0_20166b6c)[param_1 * 0xb],1,0xd,0x2000);
  reg_rmw16((&PTR_RSPI_SPCMD0_0_20166b6c)[param_1 * 0xb],0,0xc,0x1000);
  reg_rmw16((&PTR_RSPI_SPCMD0_0_20166b6c)[param_1 * 0xb],7,8,0xf00);
  reg_rmw16((&PTR_RSPI_SPCMD0_0_20166b6c)[param_1 * 0xb],1,7,0x80);
  reg_rmw16((&PTR_RSPI_SPCMD0_0_20166b6c)[param_1 * 0xb],param_3,2,0xc);
  reg_rmw16((&PTR_RSPI_SPCMD0_0_20166b6c)[param_1 * 0xb],0,1,2);
  reg_rmw16((&PTR_RSPI_SPCMD0_0_20166b6c)[param_1 * 0xb],1,0);
  reg_rmw8((&PTR_RSPI_SPBFCR_0_20166b70)[param_1 * 0xb],1,7,0x80);
  reg_rmw8((&PTR_RSPI_SPBFCR_0_20166b70)[param_1 * 0xb],1,6,0x40);
  reg_rmw8((&PTR_RSPI_SPBFCR_0_20166b70)[param_1 * 0xb],3,4,0x30);
  reg_rmw8((&PTR_RSPI_SPBFCR_0_20166b70)[param_1 * 0xb],0,0,7);
  reg_rmw8((&PTR_RSPI_SPBFCR_0_20166b70)[param_1 * 0xb],0,7,0x80);
  reg_rmw8((&PTR_RSPI_SPBFCR_0_20166b70)[param_1 * 0xb],0,6,0x40);
  reg_rmw8((&PTR_RSPI_SSLP_0_20166b74)[param_1 * 0xb],0,0,1);
  reg_rmw8(*ppuVar1,1,7,0x80);
  reg_rmw8(*ppuVar1,0,6,0x40);
  reg_rmw8(*ppuVar1,1,5,0x20);
  reg_rmw8(*ppuVar1,1,3,8);
  reg_rmw8(*ppuVar1,0,2,4);
  return;
}


// ===== rspi0_open_irq_only @ 2011efc8 (120 bytes)

/* no callers */

undefined4 rspi0_open_irq_only(void)

{
  uint uVar1;
  undefined4 in_r3;
  
  reg_rmw8(&CPG_STBCR10,0,7,0x80,in_r3);
  uVar1 = itron_acre_isr(0,0x20166a84);
  if ((0 < (int)uVar1) && (uVar1 = itron_acre_isr(0,0x20166a98), 0 < (int)uVar1)) {
    gic_enable_irq(0x110);
    gic_enable_irq(0x10f);
    return 0;
  }
  return 0xff;
}


// ===== rspi1_open_irq_only @ 2011f040 (120 bytes)

/* no callers */

undefined4 rspi1_open_irq_only(void)

{
  uint uVar1;
  undefined4 in_r3;
  
  reg_rmw8(&CPG_STBCR10,0,6,0x40,in_r3);
  uVar1 = itron_acre_isr(0,0x20166aac);
  if ((0 < (int)uVar1) && (uVar1 = itron_acre_isr(0,0x20166ac0), 0 < (int)uVar1)) {
    gic_enable_irq(0x113);
    gic_enable_irq(0x112);
    return 0;
  }
  return 0xff;
}


// ===== rspi_open @ 2011f0cc (72 bytes)

/* jump table to rspiN_open */

undefined4 rspi_open(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  switch(param_1) {
  case 0:
    rspi0_open();
    break;
  case 1:
    rspi1_open();
    break;
  case 2:
    rspi2_open();
    break;
  case 3:
    rspi3_open();
    break;
  case 4:
    rspi4_open();
  }
  return 0;
}

