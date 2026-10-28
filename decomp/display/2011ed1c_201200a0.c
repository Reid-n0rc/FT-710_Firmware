// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== rspi4_spri_isr @ 2011ed1c (8 bytes)

/* WARNING: Removing unreachable block (ram,0x2011f844) */
/* WARNING: Removing unreachable block (ram,0x2011f848) */
/* WARNING: Removing unreachable block (ram,0x2011f858) */
/* stub */

undefined4 rspi4_spri_isr(void)

{
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch((undefined *)0x2011f890) {
  case (undefined *)0x0:
                    /* WARNING: This code block may not be properly labeled as switch case */
    rspi0_rx_isr();
    break;
  case (undefined *)0x1:
                    /* WARNING: This code block may not be properly labeled as switch case */
    rspi1_rx_isr();
    break;
  case (undefined *)0x2:
                    /* WARNING: This code block may not be properly labeled as switch case */
    rspi2_rx_isr();
    break;
  case (undefined *)0x3:
                    /* WARNING: This code block may not be properly labeled as switch case */
    rspi3_rx_isr();
    break;
  case (undefined *)0x4:
                    /* WARNING: This code block may not be properly labeled as switch case */
    rspi4_rx_isr();
  }
  return 0;
}


// ===== rspi_hw_config_master @ 2011ed24 (676 bytes)

/* (ch, spbr, brdv, loopback); no callers */

void rspi_hw_config_master(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_DAT_20166b4c + param_1 * 0xb;
  FUN_20157138(*ppuVar1,0,6,0x40);
  FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,5,0x20);
  FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],0,4,0x10);
  FUN_20157138((&PTR_DAT_20166b50)[param_1 * 0xb],param_4,0,1);
  FUN_20157138((&PTR_DAT_20166b54)[param_1 * 0xb],param_2,0,0xff);
  FUN_20157138((&PTR_DAT_20166b58)[param_1 * 0xb],0,7,0x80);
  FUN_20157138((&PTR_DAT_20166b58)[param_1 * 0xb],1,5,0x60);
  FUN_20157138((&PTR_DAT_20166b5c)[param_1 * 0xb],7,0);
  FUN_20157138((&PTR_DAT_20166b60)[param_1 * 0xb],0,0,7);
  FUN_20157138((&PTR_DAT_20166b64)[param_1 * 0xb],0,0,7);
  FUN_20157138((&PTR_DAT_20166b68)[param_1 * 0xb],0,0,3);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0xf,0x8000);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0xe,0x4000);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0xd,0x2000);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,0xc,0x1000);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],7,8,0xf00);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,7,0x80);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],param_3,2,0xc);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],0,1,2);
  FUN_2015714c((&PTR_DAT_20166b6c)[param_1 * 0xb],1,0);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],1,7,0x80);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],1,6,0x40);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],3,4,0x30);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,0,7);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,7,0x80);
  FUN_20157138((&PTR_DAT_20166b70)[param_1 * 0xb],0,6,0x40);
  FUN_20157138((&PTR_DAT_20166b74)[param_1 * 0xb],0,0,1);
  FUN_20157138(*ppuVar1,1,7,0x80);
  FUN_20157138(*ppuVar1,0,6,0x40);
  FUN_20157138(*ppuVar1,1,5,0x20);
  FUN_20157138(*ppuVar1,1,3,8);
  FUN_20157138(*ppuVar1,0,2,4);
  return;
}


// ===== rspi0_open_irq_only @ 2011efc8 (120 bytes)

/* no callers */

undefined4 rspi0_open_irq_only(void)

{
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe043c,0,7,0x80,in_r3);
  iVar1 = itron_acre_isr(0,&DAT_20166a84);
  if ((0 < iVar1) && (iVar1 = itron_acre_isr(0,&DAT_20166a98), 0 < iVar1)) {
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
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe043c,0,6,0x40,in_r3);
  iVar1 = itron_acre_isr(0,&DAT_20166aac);
  if ((0 < iVar1) && (iVar1 = itron_acre_isr(0,&DAT_20166ac0), 0 < iVar1)) {
    gic_enable_irq(0x113);
    gic_enable_irq(0x112);
    return 0;
  }
  return 0xff;
}


// ===== rspi_open @ 2011f0cc (72 bytes)

/* jump table to rspiN_open */

uint rspi_open(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
}


// ===== rspi_spe_set @ 2011f128 (16 bytes)

void rspi_spe_set(undefined4 param_1)

{
  FUN_20157138(param_1,1,6,0x40);
  return;
}


// ===== rspi_start @ 2011f138 (80 bytes)

/* SPCR.SPE=1 */

uint rspi_start(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
}


// ===== rspi_spe_clear @ 2011f19c (16 bytes)

void rspi_spe_clear(undefined4 param_1)

{
  FUN_20157138(param_1,0,6,0x40);
  return;
}


// ===== rspi_stop @ 2011f1ac (112 bytes)

/* SPCR.SPE=0 + delay */

uint rspi_stop(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
}


// ===== rspi_base @ 2011f230 (52 bytes)

undefined * rspi_base(undefined4 param_1)

{
  switch(param_1) {
  default:
    return &DAT_e800c800;
  case 1:
    return &DAT_e800d000;
  case 2:
    return &DAT_e800d800;
  case 3:
    return &DAT_e800e000;
  case 4:
    return &DAT_e800e800;
  }
}


// ===== rspi_read @ 2011f278 (500 bytes)

/* PIO read; no callers */

undefined4 rspi_read(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int extraout_r1;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 local_3c;
  undefined4 local_38;
  
  puVar9 = (undefined4 *)0x0;
  puVar8 = (undefined4 *)0x0;
  local_38 = 0;
  iVar1 = rspi_base(param_1);
  if (param_4 != 0xff) {
    local_38 = FUN_20157174(iVar1 + 0x20,0,7);
    FUN_20157138(iVar1 + 0x20,param_4,0,7);
  }
  iVar2 = FUN_20157174(iVar1 + 0xb,5,0x60);
  if (iVar2 == 3) {
    uVar7 = 4;
  }
  else if (iVar2 == 2) {
    uVar7 = 2;
    puVar9 = param_2;
    param_2 = (undefined4 *)0x0;
  }
  else {
    uVar7 = 1;
    puVar8 = param_2;
    param_2 = (undefined4 *)0x0;
  }
  iVar3 = FUN_20157174(iVar1 + 0x20,0,7);
  uVar4 = *(uint *)(&DAT_20800434 + iVar3 * 4);
  if ((uVar4 < uVar7) || (FUN_20156260(uVar4,uVar7), extraout_r1 != 0)) {
    local_3c = 0xffffffff;
  }
  else {
    local_3c = 0;
    while (param_3 != 0) {
      uVar5 = param_3 * uVar7;
      uVar6 = uVar5;
      if (uVar4 <= uVar5) {
        uVar6 = uVar4;
      }
      switch(param_1) {
      case 0:
        rspi0_read_burst(uVar6);
        break;
      case 1:
        rspi1_read_burst(uVar6);
        break;
      case 2:
        rspi2_read_burst(uVar6);
        break;
      case 3:
        rspi3_read_burst(uVar6);
        break;
      case 4:
        rspi4_read_burst(uVar6,uVar4 > uVar5);
      }
      for (; uVar7 <= uVar6; uVar6 = uVar6 - uVar7) {
        if (iVar2 == 3) {
          puVar10 = param_2 + 1;
          *param_2 = *(undefined4 *)(iVar1 + 4);
        }
        else {
          puVar10 = param_2;
          if (iVar2 == 2) {
            *(undefined2 *)puVar9 = *(undefined2 *)(iVar1 + 4);
            puVar9 = (undefined4 *)((int)puVar9 + 2);
          }
          else {
            *(undefined1 *)puVar8 = *(undefined1 *)(iVar1 + 4);
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          }
        }
        param_3 = param_3 + -1;
        param_2 = puVar10;
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
    FUN_20157138(iVar1 + 0x20,local_38,0,7);
  }
  return local_3c;
}


// ===== rspi_write @ 2011f718 (604 bytes)

/* PIO write by TX trigger level */

undefined4 rspi_write(uint param_1,undefined4 *param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int extraout_r1;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 local_48;
  undefined4 local_40;
  
  uVar6 = 0;
  if ((param_1 < 5) && (0xfa < param_4 - 4U)) {
    if (param_3 != 0) {
      puVar9 = (undefined4 *)0x0;
      puVar8 = (undefined4 *)0x0;
      local_40 = 0;
      iVar2 = rspi_base(param_1);
      if (param_4 != 0xff) {
        local_40 = FUN_20157174(iVar2 + 0x20,4,0x30);
        FUN_20157138(iVar2 + 0x20,param_4,4,0x30);
      }
      iVar3 = FUN_20157174(iVar2 + 0xb,5,0x60);
      if (iVar3 == 3) {
        uVar7 = 4;
      }
      else if (iVar3 == 2) {
        uVar7 = 2;
        puVar9 = param_2;
        param_2 = (undefined4 *)0x0;
      }
      else {
        uVar7 = 1;
        puVar8 = param_2;
        param_2 = (undefined4 *)0x0;
      }
      iVar4 = FUN_20157174(iVar2 + 0x20,4,0x30);
      uVar5 = *(uint *)(&DAT_20800424 + iVar4 * 4);
      if ((uVar5 < uVar7) || (FUN_20156260(uVar5,uVar7), extraout_r1 != 0)) {
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
          uVar1 = uVar5;
          if (param_3 * uVar7 < uVar5) {
            uVar1 = param_3 * uVar7;
          }
          for (; uVar7 <= uVar1; uVar1 = uVar1 - uVar7) {
            if (iVar3 == 3) {
              puVar10 = param_2 + 1;
              *(undefined4 *)(iVar2 + 4) = *param_2;
            }
            else {
              puVar10 = param_2;
              if (iVar3 == 2) {
                *(undefined2 *)(iVar2 + 4) = *(undefined2 *)puVar9;
                puVar9 = (undefined4 *)((int)puVar9 + 2);
              }
              else {
                *(undefined1 *)(iVar2 + 4) = *(undefined1 *)puVar8;
                puVar8 = (undefined4 *)((int)puVar8 + 1);
              }
            }
            FUN_20157174(iVar2 + 3,7,0x80);
            param_3 = param_3 + -1;
            param_2 = puVar10;
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
        FUN_20157138(iVar2 + 0x20,local_40,4,0x30);
      }
      return local_48;
    }
  }
  else {
    uVar6 = 0xffffffff;
  }
  return uVar6;
}


// ===== rspi_fifo_reset @ 2011f758 (92 bytes)

/* SPBFCR TXRST/RXRST pulse */

void rspi_fifo_reset(int param_1)

{
  FUN_20157138(param_1 + 0x20,1,6,0x40);
  FUN_20157138(param_1 + 0x20,1,7,0x80);
  FUN_20157138(param_1 + 0x20,0,6,0x40);
  FUN_20157138(param_1 + 0x20,0,7,0x80);
  return;
}


// ===== rspi_reset_buffers @ 2011f7b4 (120 bytes)

uint rspi_reset_buffers(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
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

uint rspi_wait_tx_end(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (4 < param_1) {
    return 0;
  }
  return param_1;
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
  FUN_20157138(*puVar2,0,7,0x80);
  FUN_20157138(*puVar2,1,6,0x40);
  FUN_20157138(*puVar2,1,7,0x80);
  FUN_20157138(*(undefined4 *)(&DAT_20166d1c + iVar1),3,4,0x70);
  FUN_20157138(*(undefined4 *)(&DAT_20166d20 + iVar1),0xe,0,0x1f);
  FUN_20157138(*(undefined4 *)(&DAT_20166d24 + iVar1),0x10,0,0x1f);
  FUN_20157138(*(undefined4 *)(&DAT_20166d28 + iVar1),3,0);
  FUN_20157138(*(undefined4 *)(&DAT_20166d2c + iVar1),1,4,0x10);
  FUN_20157138(*(undefined4 *)(&DAT_20166d2c + iVar1),1,5,0x20);
  FUN_20157138((&PTR_DAT_20166d30)[param_1 * 9],1,5,0x20);
  FUN_20157138((&PTR_DAT_20166d30)[param_1 * 9],1,7,0x80);
  FUN_20157138((&PTR_DAT_20166d30)[param_1 * 9],1,6,0x40);
  FUN_20157138(*puVar2,0,6,0x40);
  return;
}


// ===== FUN_2011fa90 @ 2011fa90 (508 bytes)

void FUN_2011fa90(uint param_1)

{
  if ((1 < param_1) && (param_1 != 2 && param_1 != 3)) {
    return;
  }
  FUN_2015714c(&DAT_fcfe7004,0,0,1);
  FUN_2015714c(&DAT_fcfe7104,0,0,1);
  FUN_2015714c(&DAT_fcfe3304,1,0);
  FUN_2015714c(&DAT_fcfe3404,0,0,1);
  FUN_2015714c(&DAT_fcfe7204,0,0,1);
  FUN_2015714c(&DAT_fcfe7104,1,0);
  FUN_2015714c(&DAT_fcfe3504,0,0,1);
  FUN_2015714c(&DAT_fcfe3604,0,0,1);
  FUN_2015714c(&DAT_fcfe3a04,0,0,1);
  FUN_2015714c(&DAT_fcfe7204,1,0);
  FUN_2015714c(&DAT_fcfe3404,1,0);
  FUN_2015714c(&DAT_fcfe7004,0,1,2);
  FUN_2015714c(&DAT_fcfe7104,0,1,2);
  FUN_2015714c(&DAT_fcfe3304,1,1,2);
  FUN_2015714c(&DAT_fcfe3404,0,1,2);
  FUN_2015714c(&DAT_fcfe7204,0,1,2);
  FUN_2015714c(&DAT_fcfe7104,1,1,2);
  FUN_2015714c(&DAT_fcfe3504,0,1,2);
  FUN_2015714c(&DAT_fcfe3604,0,1,2);
  FUN_2015714c(&DAT_fcfe3a04,0,1,2);
  FUN_2015714c(&DAT_fcfe7204,1,1,2);
  FUN_2015714c(&DAT_fcfe3404,1,1,2);
  return;
}


// ===== FUN_2011fc8c @ 2011fc8c (144 bytes)

void FUN_2011fc8c(void)

{
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe0438,0,7,0x80,in_r3);
  FUN_2011fa90(0);
  FUN_2011f970(0);
  iVar1 = itron_acre_isr(0,&DAT_20166c28);
  if (((0 < iVar1) && (iVar1 = itron_acre_isr(0,&DAT_20166c3c), 0 < iVar1)) &&
     (iVar1 = itron_acre_isr(0,&DAT_20166c50), 0 < iVar1)) {
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
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe0438,0,6,0x40,in_r3);
  FUN_2011fa90(1);
  FUN_2011f970(1);
  iVar1 = itron_acre_isr(0,&DAT_20166c64);
  if (((0 < iVar1) && (iVar1 = itron_acre_isr(0,&DAT_20166c78), 0 < iVar1)) &&
     (iVar1 = itron_acre_isr(0,&DAT_20166c8c), 0 < iVar1)) {
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
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe0438,0,5,0x20,in_r3);
  FUN_2011f970(2);
  iVar1 = itron_acre_isr(0,&DAT_20166ca0);
  if (((0 < iVar1) && (iVar1 = itron_acre_isr(0,&DAT_20166cb4), 0 < iVar1)) &&
     (iVar1 = itron_acre_isr(0,&DAT_20166cc8), 0 < iVar1)) {
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
  int iVar1;
  undefined4 in_r3;
  
  FUN_20157138(&DAT_fcfe0438,0,4,0x10,in_r3);
  FUN_2011f970(3);
  iVar1 = itron_acre_isr(0,&DAT_20166cdc);
  if (((0 < iVar1) && (iVar1 = itron_acre_isr(0,&DAT_20166cf0), 0 < iVar1)) &&
     (iVar1 = itron_acre_isr(0,&DAT_20166d04), 0 < iVar1)) {
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

