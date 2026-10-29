// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== rspi_spe_set @ 2011f128 (16 bytes)

void rspi_spe_set(uint param_1)

{
  reg_rmw8(param_1,1,6,0x40);
  return;
}


// ===== rspi_start @ 2011f138 (80 bytes)

/* SPCR.SPE=1 */

undefined4 rspi_start(uint param_1)

{
  byte *pbVar1;
  
  if (4 < param_1) {
    return 0xffffffff;
  }
  switch(param_1) {
  case 0:
    pbVar1 = &RSPI_SPCR_0;
    break;
  case 1:
    pbVar1 = &RSPI_SPCR_1;
    break;
  case 2:
    pbVar1 = &RSPI_SPCR_2;
    break;
  case 3:
    pbVar1 = &RSPI_SPCR_3;
    break;
  case 4:
    rspi_spe_set(0xe800e800);
  default:
    goto switchD_2011f14c_default;
  }
  rspi_spe_set((uint)pbVar1);
switchD_2011f14c_default:
  return 0;
}


// ===== rspi_spe_clear @ 2011f19c (16 bytes)

void rspi_spe_clear(uint param_1)

{
  reg_rmw8(param_1,0,6,0x40);
  return;
}


// ===== rspi_stop @ 2011f1ac (112 bytes)

/* SPCR.SPE=0 + delay */

undefined4 rspi_stop(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  switch(param_1) {
  case 0:
    rspi_spe_clear(0xe800c800);
    rspi0_delay();
    break;
  case 1:
    rspi_spe_clear(0xe800d000);
    rspi1_delay();
    break;
  case 2:
    rspi_spe_clear(0xe800d800);
    rspi2_delay();
    break;
  case 3:
    rspi_spe_clear(0xe800e000);
    rspi3_delay();
    break;
  case 4:
    rspi_spe_clear(0xe800e800);
    rspi4_delay();
  }
  return 0;
}


// ===== rspi_base @ 2011f230 (52 bytes)

void * rspi_base(uint param_1)

{
  switch(param_1) {
  default:
    return &RSPI_SPCR_0;
  case 1:
    return &RSPI_SPCR_1;
  case 2:
    return &RSPI_SPCR_2;
  case 3:
    return &RSPI_SPCR_3;
  case 4:
    return &RSPI_SPCR_4;
  }
}


// ===== rspi_read @ 2011f278 (500 bytes)

/* PIO read; no callers */

undefined4 rspi_read(uint param_1,undefined4 *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  void *pvVar4;
  uint uVar5;
  int extraout_r1;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 local_3c;
  
  puVar10 = (undefined4 *)0x0;
  puVar9 = (undefined4 *)0x0;
  bVar1 = 0;
  pvVar4 = rspi_base(param_1);
  if (param_4 != 0xff) {
    bVar1 = reg_read8((byte *)((int)pvVar4 + 0x20),0,7);
    reg_rmw8((int)pvVar4 + 0x20,param_4,0,7);
  }
  bVar2 = reg_read8((byte *)((int)pvVar4 + 0xb),5,0x60);
  if (bVar2 == 3) {
    uVar8 = 4;
  }
  else if (bVar2 == 2) {
    uVar8 = 2;
    puVar10 = param_2;
    param_2 = (undefined4 *)0x0;
  }
  else {
    uVar8 = 1;
    puVar9 = param_2;
    param_2 = (undefined4 *)0x0;
  }
  bVar3 = reg_read8((byte *)((int)pvVar4 + 0x20),0,7);
  uVar5 = *(uint *)(&DAT_20800434 + (uint)bVar3 * 4);
  if ((uVar5 < uVar8) || (__aeabi_uidivmod(uVar5,uVar8), extraout_r1 != 0)) {
    local_3c = 0xffffffff;
  }
  else {
    local_3c = 0;
    while (param_3 != 0) {
      uVar6 = param_3 * uVar8;
      uVar7 = uVar6;
      if (uVar5 <= uVar6) {
        uVar7 = uVar5;
      }
      switch(param_1) {
      case 0:
        rspi0_read_burst(uVar7);
        break;
      case 1:
        rspi1_read_burst(uVar7);
        break;
      case 2:
        rspi2_read_burst(uVar7);
        break;
      case 3:
        rspi3_read_burst(uVar7);
        break;
      case 4:
        rspi4_read_burst(uVar7,uVar5 > uVar6);
      }
      for (; uVar8 <= uVar7; uVar7 = uVar7 - uVar8) {
        if (bVar2 == 3) {
          puVar11 = param_2 + 1;
          *param_2 = *(undefined4 *)((int)pvVar4 + 4);
        }
        else {
          puVar11 = param_2;
          if (bVar2 == 2) {
            *(undefined2 *)puVar10 = *(undefined2 *)((int)pvVar4 + 4);
            puVar10 = (undefined4 *)((int)puVar10 + 2);
          }
          else {
            *(undefined1 *)puVar9 = *(undefined1 *)((int)pvVar4 + 4);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
        }
        param_3 = param_3 + -1;
        param_2 = puVar11;
      }
      switch(param_1) {
      case 0:
        rspi0_clear_rx_flag();
        break;
      case 1:
        rspi1_clear_rx_flag();
        break;
      case 2:
        rspi2_clear_rx_flag();
        break;
      case 3:
        rspi3_clear_rx_flag();
        break;
      case 4:
        rspi4_clear_rx_flag();
      }
    }
  }
  if (param_4 != 0xff) {
    reg_rmw8((int)pvVar4 + 0x20,bVar1,0,7);
  }
  return local_3c;
}


// ===== FUN_2011f494 @ 2011f494 (64 bytes)

undefined4 FUN_2011f494(uint param_1,undefined4 *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 uVar6;
  int extraout_r1;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 uStack_3c;
  
  uVar6 = 0;
  if ((param_1 < 5) && (0xf6 < param_4 - 8U)) {
    if (param_3 != 0) {
      puVar11 = (undefined4 *)0x0;
      puVar10 = (undefined4 *)0x0;
      bVar1 = 0;
      pvVar4 = rspi_base(param_1);
      if (param_4 != 0xff) {
        bVar1 = reg_read8((byte *)((int)pvVar4 + 0x20),0,7);
        reg_rmw8((int)pvVar4 + 0x20,param_4,0,7);
      }
      bVar2 = reg_read8((byte *)((int)pvVar4 + 0xb),5,0x60);
      if (bVar2 == 3) {
        uVar9 = 4;
      }
      else if (bVar2 == 2) {
        uVar9 = 2;
        puVar11 = param_2;
        param_2 = (undefined4 *)0x0;
      }
      else {
        uVar9 = 1;
        puVar10 = param_2;
        param_2 = (undefined4 *)0x0;
      }
      bVar3 = reg_read8((byte *)((int)pvVar4 + 0x20),0,7);
      uVar5 = *(uint *)(&DAT_20800434 + (uint)bVar3 * 4);
      if ((uVar5 < uVar9) || (__aeabi_uidivmod(uVar5,uVar9), extraout_r1 != 0)) {
        uStack_3c = 0xffffffff;
      }
      else {
        uStack_3c = 0;
        while (param_3 != 0) {
          uVar7 = param_3 * uVar9;
          uVar8 = uVar7;
          if (uVar5 <= uVar7) {
            uVar8 = uVar5;
          }
          switch(param_1) {
          case 0:
            rspi0_read_burst(uVar8);
            break;
          case 1:
            rspi1_read_burst(uVar8);
            break;
          case 2:
            rspi2_read_burst(uVar8);
            break;
          case 3:
            rspi3_read_burst(uVar8);
            break;
          case 4:
            rspi4_read_burst(uVar8,uVar5 > uVar7);
          }
          for (; uVar9 <= uVar8; uVar8 = uVar8 - uVar9) {
            if (bVar2 == 3) {
              puVar12 = param_2 + 1;
              *param_2 = *(undefined4 *)((int)pvVar4 + 4);
            }
            else {
              puVar12 = param_2;
              if (bVar2 == 2) {
                *(undefined2 *)puVar11 = *(undefined2 *)((int)pvVar4 + 4);
                puVar11 = (undefined4 *)((int)puVar11 + 2);
              }
              else {
                *(undefined1 *)puVar10 = *(undefined1 *)((int)pvVar4 + 4);
                puVar10 = (undefined4 *)((int)puVar10 + 1);
              }
            }
            param_3 = param_3 + -1;
            param_2 = puVar12;
          }
          switch(param_1) {
          case 0:
            rspi0_clear_rx_flag();
            break;
          case 1:
            rspi1_clear_rx_flag();
            break;
          case 2:
            rspi2_clear_rx_flag();
            break;
          case 3:
            rspi3_clear_rx_flag();
            break;
          case 4:
            rspi4_clear_rx_flag();
          }
        }
      }
      if (param_4 != 0xff) {
        reg_rmw8((int)pvVar4 + 0x20,bVar1,0,7);
      }
      return uStack_3c;
    }
  }
  else {
    uVar6 = 0xffffffff;
  }
  return uVar6;
}


// ===== rspi_write @ 2011f718 (604 bytes)

/* PIO write by TX trigger level */

undefined4 rspi_write(uint param_1,undefined4 *param_2,int param_3,int param_4)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 uVar7;
  int extraout_r1;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 local_48;
  
  uVar7 = 0;
  if ((param_1 < 5) && (0xfa < param_4 - 4U)) {
    if (param_3 != 0) {
      puVar10 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)0x0;
      bVar2 = 0;
      pvVar5 = rspi_base(param_1);
      if (param_4 != 0xff) {
        bVar2 = reg_read8((byte *)((int)pvVar5 + 0x20),4,0x30);
        reg_rmw8((int)pvVar5 + 0x20,param_4,4,0x30);
      }
      bVar3 = reg_read8((byte *)((int)pvVar5 + 0xb),5,0x60);
      if (bVar3 == 3) {
        uVar8 = 4;
      }
      else if (bVar3 == 2) {
        uVar8 = 2;
        puVar10 = param_2;
        param_2 = (undefined4 *)0x0;
      }
      else {
        uVar8 = 1;
        puVar9 = param_2;
        param_2 = (undefined4 *)0x0;
      }
      bVar4 = reg_read8((byte *)((int)pvVar5 + 0x20),4,0x30);
      uVar6 = *(uint *)(&DAT_20800424 + (uint)bVar4 * 4);
      if ((uVar6 < uVar8) || (__aeabi_uidivmod(uVar6,uVar8), extraout_r1 != 0)) {
        local_48 = 0xffffffff;
      }
      else {
        local_48 = 0;
        while (param_3 != 0) {
          switch(param_1) {
          case 0:
            rspi0_tx_wait();
            break;
          case 1:
            rspi1_tx_wait();
            break;
          case 2:
            rspi2_tx_wait();
            break;
          case 3:
            rspi3_tx_wait();
            break;
          case 4:
            rspi4_tx_wait();
          }
          uVar1 = uVar6;
          if (param_3 * uVar8 < uVar6) {
            uVar1 = param_3 * uVar8;
          }
          for (; uVar8 <= uVar1; uVar1 = uVar1 - uVar8) {
            if (bVar3 == 3) {
              puVar11 = param_2 + 1;
              *(undefined4 *)((int)pvVar5 + 4) = *param_2;
            }
            else {
              puVar11 = param_2;
              if (bVar3 == 2) {
                *(undefined2 *)((int)pvVar5 + 4) = *(undefined2 *)puVar10;
                puVar10 = (undefined4 *)((int)puVar10 + 2);
              }
              else {
                *(undefined1 *)((int)pvVar5 + 4) = *(undefined1 *)puVar9;
                puVar9 = (undefined4 *)((int)puVar9 + 1);
              }
            }
            reg_read8((byte *)((int)pvVar5 + 3),7,0x80);
            param_3 = param_3 + -1;
            param_2 = puVar11;
          }
          switch(param_1) {
          case 0:
            rspi0_clear_tx_flag();
            break;
          case 1:
            rspi1_clear_tx_flag();
            break;
          case 2:
            rspi2_clear_tx_flag();
            break;
          case 3:
            rspi3_clear_tx_flag();
            break;
          case 4:
            rspi4_clear_tx_flag();
          }
        }
      }
      if (param_4 != 0xff) {
        reg_rmw8((int)pvVar5 + 0x20,bVar2,4,0x30);
      }
      return local_48;
    }
  }
  else {
    uVar7 = 0xffffffff;
  }
  return uVar7;
}


// ===== rspi_fifo_reset @ 2011f758 (92 bytes)

/* SPBFCR TXRST/RXRST pulse */

void rspi_fifo_reset(int param_1)

{
  reg_rmw8(param_1 + 0x20,1,6,0x40);
  reg_rmw8(param_1 + 0x20,1,7,0x80);
  reg_rmw8(param_1 + 0x20,0,6,0x40);
  reg_rmw8(param_1 + 0x20,0,7,0x80);
  return;
}


// ===== rspi_reset_buffers @ 2011f7b4 (120 bytes)

undefined4 rspi_reset_buffers(uint param_1)

{
  byte *pbVar1;
  
  if (4 < param_1) {
    return 0xffffffff;
  }
  switch(param_1) {
  case 0:
    rspi0_clear_rx_flag();
    rspi0_clear_tx_flag();
    pbVar1 = &RSPI_SPCR_0;
    break;
  case 1:
    rspi1_clear_rx_flag();
    rspi1_clear_tx_flag();
    pbVar1 = &RSPI_SPCR_1;
    break;
  case 2:
    rspi2_clear_rx_flag();
    rspi2_clear_tx_flag();
    pbVar1 = &RSPI_SPCR_2;
    break;
  case 3:
    rspi3_clear_rx_flag();
    rspi3_clear_tx_flag();
    pbVar1 = &RSPI_SPCR_3;
    break;
  case 4:
    rspi4_clear_rx_flag();
    rspi4_clear_tx_flag();
    rspi_fifo_reset(-0x17ff1800);
  default:
    goto switchD_2011f7c8_default;
  }
  rspi_fifo_reset((int)pbVar1);
switchD_2011f7c8_default:
  return 0;
}


// ===== rspi_rx_isr @ 2011f840 (72 bytes)

/* SPRI dispatch; entry fix (late start FUN_2011f84c) */

undefined4 rspi_rx_isr(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  switch(param_1) {
  case 0:
    rspi0_rx_isr();
    break;
  case 1:
    rspi1_rx_isr();
    break;
  case 2:
    rspi2_rx_isr();
    break;
  case 3:
    rspi3_rx_isr();
    break;
  case 4:
    rspi4_rx_isr();
  }
  return 0;
}


// ===== rspi_tx_isr @ 2011f89c (72 bytes)

/* SPTI dispatch; entry fix (late start FUN_2011f8a8) */

undefined4 rspi_tx_isr(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  switch(param_1) {
  case 0:
    rspi0_tx_isr();
    break;
  case 1:
    rspi1_tx_isr();
    break;
  case 2:
    rspi2_tx_isr();
    break;
  case 3:
    rspi3_tx_isr();
    break;
  case 4:
    rspi4_tx_isr();
  }
  return 0;
}


// ===== rspi_wait_tx_end @ 2011f8f8 (72 bytes)

undefined4 rspi_wait_tx_end(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  switch(param_1) {
  case 0:
    rspi0_wait_tend();
    break;
  case 1:
    rspi1_wait_tend();
    break;
  case 2:
    rspi2_wait_tend();
    break;
  case 3:
    rspi3_wait_tend();
    break;
  case 4:
    rspi4_wait_tend();
  }
  return 0;
}


// ===== FUN_2011f970 @ 2011f970 (288 bytes)

void FUN_2011f970(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (3 < param_1) {
    return;
  }
  iVar1 = param_1 * 0x24;
  puVar2 = (undefined4 *)(&DAT_20166d18 + iVar1);
  reg_rmw8(*puVar2,0,7,0x80);
  reg_rmw8(*puVar2,1,6,0x40);
  reg_rmw8(*puVar2,1,7,0x80);
  reg_rmw8(*(undefined4 *)(&DAT_20166d1c + iVar1),3,4,0x70);
  reg_rmw8(*(undefined4 *)(&DAT_20166d20 + iVar1),0xe,0,0x1f);
  reg_rmw8(*(undefined4 *)(&DAT_20166d24 + iVar1),0x10,0,0x1f);
  reg_rmw8(*(undefined4 *)(&DAT_20166d28 + iVar1),3,0);
  reg_rmw8(*(undefined4 *)(&DAT_20166d2c + iVar1),1,4,0x10);
  reg_rmw8(*(undefined4 *)(&DAT_20166d2c + iVar1),1,5,0x20);
  reg_rmw8((&PTR_RIIC_RIIC0IER_20166d30)[param_1 * 9],1,5,0x20);
  reg_rmw8((&PTR_RIIC_RIIC0IER_20166d30)[param_1 * 9],1,7,0x80);
  reg_rmw8((&PTR_RIIC_RIIC0IER_20166d30)[param_1 * 9],1,6,0x40);
  reg_rmw8(*puVar2,0,6,0x40);
  return;
}


// ===== FUN_2011fa90 @ 2011fa90 (508 bytes)

void FUN_2011fa90(uint param_1)

{
  if ((1 < param_1) && (param_1 != 2 && param_1 != 3)) {
    return;
  }
  reg_rmw16(&PORT_PIBC1,0,0,1);
  reg_rmw16(&PORT_PBDC1,0,0,1);
  reg_rmw16(&PORT_PM1,1,0);
  reg_rmw16(&PORT_PMC1,0,0,1);
  reg_rmw16(&PORT_PIPC1,0,0,1);
  reg_rmw16(&PORT_PBDC1,1,0);
  reg_rmw16(&PORT_PFC1,0,0,1);
  reg_rmw16(&PORT_PFCE1,0,0,1);
  reg_rmw16(&PORT_PFCAE1,0,0,1);
  reg_rmw16(&PORT_PIPC1,1,0);
  reg_rmw16(&PORT_PMC1,1,0);
  reg_rmw16(&PORT_PIBC1,0,1,2);
  reg_rmw16(&PORT_PBDC1,0,1,2);
  reg_rmw16(&PORT_PM1,1,1,2);
  reg_rmw16(&PORT_PMC1,0,1,2);
  reg_rmw16(&PORT_PIPC1,0,1,2);
  reg_rmw16(&PORT_PBDC1,1,1,2);
  reg_rmw16(&PORT_PFC1,0,1,2);
  reg_rmw16(&PORT_PFCE1,0,1,2);
  reg_rmw16(&PORT_PFCAE1,0,1,2);
  reg_rmw16(&PORT_PIPC1,1,1,2);
  reg_rmw16(&PORT_PMC1,1,1,2);
  return;
}


// ===== FUN_2011fc8c @ 2011fc8c (144 bytes)

void FUN_2011fc8c(void)

{
  uint uVar1;
  undefined4 in_r3;
  
  reg_rmw8(&CPG_STBCR9,0,7,0x80,in_r3);
  FUN_2011fa90(0);
  FUN_2011f970(0);
  uVar1 = itron_acre_isr(0,0x20166c28);
  if (((0 < (int)uVar1) && (uVar1 = itron_acre_isr(0,0x20166c3c), 0 < (int)uVar1)) &&
     (uVar1 = itron_acre_isr(0,0x20166c50), 0 < (int)uVar1)) {
    gic_enable_irq(0xbf);
    gic_enable_irq(0xbe);
    gic_enable_irq(0xbd);
    return;
  }
  return;
}


// ===== FUN_2011fd1c @ 2011fd1c (144 bytes)

void FUN_2011fd1c(void)

{
  uint uVar1;
  undefined4 in_r3;
  
  reg_rmw8(&CPG_STBCR9,0,6,0x40,in_r3);
  FUN_2011fa90(1);
  FUN_2011f970(1);
  uVar1 = itron_acre_isr(0,0x20166c64);
  if (((0 < (int)uVar1) && (uVar1 = itron_acre_isr(0,0x20166c78), 0 < (int)uVar1)) &&
     (uVar1 = itron_acre_isr(0,0x20166c8c), 0 < (int)uVar1)) {
    gic_enable_irq(199);
    gic_enable_irq(0xc6);
    gic_enable_irq(0xc5);
    return;
  }
  return;
}


// ===== FUN_2011fdac @ 2011fdac (136 bytes)

void FUN_2011fdac(void)

{
  uint uVar1;
  undefined4 in_r3;
  
  reg_rmw8(&CPG_STBCR9,0,5,0x20,in_r3);
  FUN_2011f970(2);
  uVar1 = itron_acre_isr(0,0x20166ca0);
  if (((0 < (int)uVar1) && (uVar1 = itron_acre_isr(0,0x20166cb4), 0 < (int)uVar1)) &&
     (uVar1 = itron_acre_isr(0,0x20166cc8), 0 < (int)uVar1)) {
    gic_enable_irq(0xcf);
    gic_enable_irq(0xce);
    gic_enable_irq(0xcd);
    return;
  }
  return;
}


// ===== FUN_2011fe34 @ 2011fe34 (136 bytes)

void FUN_2011fe34(void)

{
  uint uVar1;
  undefined4 in_r3;
  
  reg_rmw8(&CPG_STBCR9,0,4,0x10,in_r3);
  FUN_2011f970(3);
  uVar1 = itron_acre_isr(0,0x20166cdc);
  if (((0 < (int)uVar1) && (uVar1 = itron_acre_isr(0,0x20166cf0), 0 < (int)uVar1)) &&
     (uVar1 = itron_acre_isr(0,0x20166d04), 0 < (int)uVar1)) {
    gic_enable_irq(0xd7);
    gic_enable_irq(0xd6);
    gic_enable_irq(0xd5);
    return;
  }
  return;
}


// ===== FUN_2011febc @ 2011febc (16 bytes)

void FUN_2011febc(void)

{
  DAT_20800454 = 0;
  return;
}


// ===== FUN_2011fecc @ 2011fecc (16 bytes)

void FUN_2011fecc(void)

{
  DAT_20800455 = 0;
  return;
}


// ===== FUN_2011fedc @ 2011fedc (16 bytes)

void FUN_2011fedc(void)

{
  DAT_20800456 = 0;
  return;
}


// ===== FUN_2011feec @ 2011feec (16 bytes)

void FUN_2011feec(void)

{
  DAT_20800457 = 0;
  return;
}


// ===== FUN_2011fefc @ 2011fefc (16 bytes)

void FUN_2011fefc(void)

{
  DAT_20800458 = 0;
  return;
}


// ===== FUN_2011ff0c @ 2011ff0c (16 bytes)

void FUN_2011ff0c(void)

{
  DAT_20800459 = 0;
  return;
}


// ===== FUN_2011ff1c @ 2011ff1c (16 bytes)

void FUN_2011ff1c(void)

{
  DAT_2080045a = 0;
  return;
}


// ===== FUN_2011ff2c @ 2011ff2c (16 bytes)

void FUN_2011ff2c(void)

{
  DAT_2080045b = 0;
  return;
}


// ===== FUN_2011ff3c @ 2011ff3c (24 bytes)

void FUN_2011ff3c(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = &DAT_2080045c;
  }
  else {
    puVar1 = &DAT_20800454;
  }
  *puVar1 = 0;
  return;
}


// ===== FUN_2011ff54 @ 2011ff54 (24 bytes)

void FUN_2011ff54(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = &DAT_2080045c;
  }
  else {
    puVar1 = &DAT_20800454;
  }
  puVar1[1] = 0;
  return;
}


// ===== FUN_2011ff6c @ 2011ff6c (24 bytes)

void FUN_2011ff6c(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = &DAT_2080045c;
  }
  else {
    puVar1 = &DAT_20800454;
  }
  puVar1[2] = 0;
  return;
}


// ===== FUN_2011ff84 @ 2011ff84 (24 bytes)

void FUN_2011ff84(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = &DAT_2080045c;
  }
  else {
    puVar1 = &DAT_20800454;
  }
  puVar1[3] = 0;
  return;
}


// ===== FUN_2011ff9c @ 2011ff9c (16 bytes)

void FUN_2011ff9c(void)

{
  DAT_20800454 = 1;
  return;
}


// ===== FUN_2011ffac @ 2011ffac (16 bytes)

void FUN_2011ffac(void)

{
  DAT_20800455 = 1;
  return;
}


// ===== FUN_2011ffbc @ 2011ffbc (16 bytes)

void FUN_2011ffbc(void)

{
  DAT_20800456 = 1;
  return;
}


// ===== FUN_2011ffcc @ 2011ffcc (16 bytes)

void FUN_2011ffcc(void)

{
  DAT_20800457 = 1;
  return;
}


// ===== FUN_2011ffdc @ 2011ffdc (16 bytes)

void FUN_2011ffdc(void)

{
  DAT_20800458 = 1;
  return;
}


// ===== FUN_2011ffec @ 2011ffec (16 bytes)

void FUN_2011ffec(void)

{
  DAT_20800459 = 1;
  return;
}


// ===== FUN_2011fffc @ 2011fffc (32 bytes)

void FUN_2011fffc(void)

{
  DAT_2080045a = 1;
  DAT_20800462 = DAT_20800462 + '\x01';
  return;
}


// ===== FUN_2012001c @ 2012001c (12 bytes)

undefined1 FUN_2012001c(void)

{
  return DAT_20800462;
}


// ===== FUN_20120028 @ 20120028 (16 bytes)

void FUN_20120028(void)

{
  DAT_2080045b = 1;
  return;
}


// ===== FUN_20120038 @ 20120038 (16 bytes)

void FUN_20120038(void)

{
  DAT_2080045c = 1;
  return;
}


// ===== FUN_20120048 @ 20120048 (16 bytes)

void FUN_20120048(void)

{
  DAT_2080045d = 1;
  return;
}


// ===== FUN_20120058 @ 20120058 (16 bytes)

void FUN_20120058(void)

{
  DAT_2080045e = 1;
  return;
}


// ===== FUN_20120068 @ 20120068 (16 bytes)

void FUN_20120068(void)

{
  DAT_2080045f = 1;
  return;
}


// ===== FUN_20120078 @ 20120078 (20 bytes)

void FUN_20120078(void)

{
  do {
  } while (DAT_20800454 == '\0');
  return;
}


// ===== FUN_2012008c @ 2012008c (20 bytes)

void FUN_2012008c(void)

{
  do {
  } while (DAT_20800455 == '\0');
  return;
}


// ===== FUN_201200a0 @ 201200a0 (20 bytes)

void FUN_201200a0(void)

{
  do {
  } while (DAT_20800456 == '\0');
  return;
}


// ===== FUN_201200b4 @ 201200b4 (20 bytes)

void FUN_201200b4(void)

{
  do {
  } while (DAT_20800457 == '\0');
  return;
}


// ===== FUN_201200c8 @ 201200c8 (20 bytes)

void FUN_201200c8(void)

{
  do {
  } while (DAT_20800458 == '\0');
  return;
}


// ===== FUN_201200dc @ 201200dc (20 bytes)

void FUN_201200dc(void)

{
  do {
  } while (DAT_20800459 == '\0');
  return;
}

