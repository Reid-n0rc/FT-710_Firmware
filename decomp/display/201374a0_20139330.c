// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== dmac5_isr @ 201374a0 (12 bytes)

/* stub -> [0x20808AA8] */

void dmac5_isr(void)

{
                    /* WARNING: Could not recover jumptable at 0x201374a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_20808aa8)();
  return;
}


// ===== dmac4_rspi4_rx_setup @ 201374ac (536 bytes)

/* DMARS 0x132, 0x11F8 B */

void dmac4_rspi4_rx_setup(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
                    /* Channel Control 4 [sfr] */
  uVar1 = DMAC_CHCTRL_4;
  DMAC_CHCTRL_4 = uVar1 | 2;
  uVar1 = DMAC_CHCTRL_4;
  DMAC_CHCTRL_4 = uVar1 | 8;
  gic_disable_irq(0x2d);
  DAT_20808a90 = 0;
                    /* DMA extended resource selector 2 [sfr] */
  uVar1 = DMAC_DMARS2;
  DMAC_DMARS2 = uVar1 | 0x132;
                    /* Channel Configuration 4 [sfr] */
  DMAC_CHCFG_4 = 0;
  reg_rmw32(&DMAC_CHCFG_4,1,0x10,0xf0000,uVar2);
  reg_rmw32(&DMAC_CHCFG_4,0,0xc,0xf000);
  reg_rmw32(&DMAC_CHCFG_4,0,0x15,0x200000);
  reg_rmw32(&DMAC_CHCFG_4,1,0x14,0x100000);
  reg_rmw32(&DMAC_CHCFG_4,0,0x1f,0x80000000);
  reg_rmw32(&DMAC_CHCFG_4,0,0x1c,0x10000000);
  reg_rmw32(&DMAC_CHCFG_4,1,0x1b,0x8000000);
  reg_rmw32(&DMAC_CHCFG_4,0,0x18,0x1000000);
  reg_rmw32(&DMAC_CHCFG_4,0,0x1e,0x40000000);
  reg_rmw32(&DMAC_CHCFG_4,0,0x1d,0x20000000);
  reg_rmw32(&DMAC_CHCFG_4,0,0x16,0x400000);
  reg_rmw32(&DMAC_CHCFG_4,2,8,0x700);
  reg_rmw32(&DMAC_CHCFG_4,1,6,0x40);
  reg_rmw32(&DMAC_CHCFG_4,1,5,0x20);
  reg_rmw32(&DMAC_CHCFG_4,0,4,0x10);
  reg_rmw32(&DMAC_CHCFG_4,0,3,8);
  reg_rmw32(&DMAC_CHCFG_4,4,0,7);
                    /* Channel Interval 4 [sfr] */
  DMAC_CHITVL_4 = 0;
                    /* Channel Extension 4 [sfr] */
  DMAC_CHEXT_4 = 0;
                    /* Next0 Source Address 4 [sfr] */
  DMAC_N0SA_4 = param_1;
                    /* Next0 Destination Address 4 [sfr] */
  DMAC_N0DA_4 = param_2;
                    /* Next0 Transaction Byte 4 [sfr] */
  DMAC_N0TB_4 = param_3;
  reg_rmw32(&DMAC_DCTRL_0_7,1,0);
  uVar1 = itron_acre_isr(0,0x204200c4);
  if (0 < (int)uVar1) {
    gic_enable_irq(0x2d);
    reg_rmw32(&DMAC_CHCTRL_4,1,0);
    return;
  }
  return;
}


// ===== dmac4_isr @ 201376c4 (12 bytes)

/* stub -> [0x20808AA4] */

void dmac4_isr(void)

{
                    /* WARNING: Could not recover jumptable at 0x201376cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_20808aa4)();
  return;
}


// ===== dmac8_m2m_init @ 201376d0 (436 bytes)

/* frame-buffer copy DMA */

void dmac8_m2m_init(void)

{
  uint uVar1;
  
                    /* Channel Control 8 [sfr] */
  uVar1 = DMAC_CHCTRL_8;
  DMAC_CHCTRL_8 = uVar1 | 2;
  uVar1 = DMAC_CHCTRL_8;
  DMAC_CHCTRL_8 = uVar1 | 8;
  uVar1 = DMAC_CHCTRL_8;
  DMAC_CHCTRL_8 = uVar1 | 4;
                    /* Channel Configuration 8 [sfr] */
  DMAC_CHCFG_8 = 0;
  reg_rmw32(&DMAC_CHCFG_8,7,0x10,0xf0000);
  reg_rmw32(&DMAC_CHCFG_8,7,0xc,0xf000);
  reg_rmw32(&DMAC_CHCFG_8,0,0x15,0x200000);
  reg_rmw32(&DMAC_CHCFG_8,0,0x14,0x100000);
  reg_rmw32(&DMAC_CHCFG_8,0,0x1f,0x80000000);
  reg_rmw32(&DMAC_CHCFG_8,0,0x1c,0x10000000);
  reg_rmw32(&DMAC_CHCFG_8,0,0x1b,0x8000000);
  reg_rmw32(&DMAC_CHCFG_8,1,0x18,0x1000000);
  reg_rmw32(&DMAC_CHCFG_8,0,0x1e,0x40000000);
  reg_rmw32(&DMAC_CHCFG_8,0,0x1d,0x20000000);
  reg_rmw32(&DMAC_CHCFG_8,1,0x16,0x400000);
  reg_rmw32(&DMAC_CHCFG_8,4,8,0x700);
  reg_rmw32(&DMAC_CHCFG_8,1,6,0x40);
  reg_rmw32(&DMAC_CHCFG_8,1,5,0x20);
  reg_rmw32(&DMAC_CHCFG_8,0,4,0x10);
  reg_rmw32(&DMAC_CHCFG_8,0,3,8);
  reg_rmw32(&DMAC_CHCFG_8,0,0,7);
                    /* Channel Interval 8 [sfr] */
  DMAC_CHITVL_8 = 0;
                    /* Channel Extension 8 [sfr] */
  DMAC_CHEXT_8 = 0;
  reg_rmw32(&DMAC_DCTRL_8_15,1,0);
  return;
}


// ===== dmac8_m2m_start @ 201378b0 (84 bytes)

/* DMAC ch8 (0xE8200400) memory-to-memory copy, 0xBB800 B (frame buffer copy-forward) */

void dmac8_m2m_start(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
                    /* Channel Control 8 [sfr] */
  uVar1 = DMAC_CHCTRL_8;
  DMAC_CHCTRL_8 = uVar1 | 2;
  uVar1 = DMAC_CHCTRL_8;
  DMAC_CHCTRL_8 = uVar1 | 8;
  uVar1 = DMAC_CHCTRL_8;
  DMAC_CHCTRL_8 = uVar1 | 4;
                    /* Next0 Source Address 8 [sfr] */
  DMAC_N0SA_8 = param_2;
                    /* Next0 Destination Address 8 [sfr] */
  DMAC_N0DA_8 = param_1;
                    /* Next0 Transaction Byte 8 [sfr] */
  DMAC_N0TB_8 = param_3;
  reg_rmw32(&DMAC_CHCTRL_8,1,0);
  return;
}


// ===== dmac9_register_isr @ 20137904 (12 bytes)

void dmac9_register_isr(void)

{
  itron_acre_isr(0,0x204200ec);
  return;
}


// ===== dmac9_rspi_tx_setup @ 20137910 (476 bytes)

/* arg 1 RSPI0 (0x121), 0 RSPI1 */

void dmac9_rspi_tx_setup(int param_1)

{
  uint uVar1;
  uint uVar2;
  
                    /* Channel Control 9 [sfr] */
  uVar1 = DMAC_CHCTRL_9;
  DMAC_CHCTRL_9 = uVar1 | 2;
  uVar1 = DMAC_CHCTRL_9;
  DMAC_CHCTRL_9 = uVar1 | 8;
  gic_disable_irq(0x32);
  DAT_20808a98 = 0;
                    /* DMA extended resource selector 4 [sfr] */
  uVar1 = DMAC_DMARS4;
  DMAC_DMARS4 = uVar1 & 0xffff;
  uVar1 = DMAC_DMARS4;
  if (param_1 == 0) {
    uVar2 = 0x1250000;
  }
  else {
    uVar2 = 0x1210000;
  }
  DMAC_DMARS4 = uVar1 | uVar2;
                    /* Channel Configuration 9 [sfr] */
  DMAC_CHCFG_9 = 0;
  reg_rmw32(&DMAC_CHCFG_9,0,0x10,0xf0000);
  reg_rmw32(&DMAC_CHCFG_9,0,0xc,0xf000);
  reg_rmw32(&DMAC_CHCFG_9,1,0x15,0x200000);
  reg_rmw32(&DMAC_CHCFG_9,0,0x14,0x100000);
  reg_rmw32(&DMAC_CHCFG_9,0,0x1f,0x80000000);
  reg_rmw32(&DMAC_CHCFG_9,0,0x1c,0x10000000);
  reg_rmw32(&DMAC_CHCFG_9,1,0x1b,0x8000000);
  reg_rmw32(&DMAC_CHCFG_9,0,0x18,0x1000000);
  reg_rmw32(&DMAC_CHCFG_9,0,0x1e,0x40000000);
  reg_rmw32(&DMAC_CHCFG_9,0,0x1d,0x20000000);
  reg_rmw32(&DMAC_CHCFG_9,0,0x16,0x400000);
  reg_rmw32(&DMAC_CHCFG_9,2,8,0x700);
  reg_rmw32(&DMAC_CHCFG_9,1,6,0x40);
  reg_rmw32(&DMAC_CHCFG_9,1,5,0x20);
  reg_rmw32(&DMAC_CHCFG_9,0,4,0x10);
  reg_rmw32(&DMAC_CHCFG_9,0,3,8);
  reg_rmw32(&DMAC_CHCFG_9,1,0,7);
                    /* Channel Interval 9 [sfr] */
  DMAC_CHITVL_9 = 0;
                    /* Channel Extension 9 [sfr] */
  DMAC_CHEXT_9 = 0;
  gic_enable_irq(0x32);
  return;
}


// ===== dmac9_isr @ 20137aec (12 bytes)

/* stub -> [0x20808AAC] */

void dmac9_isr(void)

{
                    /* WARNING: Could not recover jumptable at 0x20137af4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_20808aac)();
  return;
}


// ===== dmac10_register_isr @ 20137af8 (12 bytes)

void dmac10_register_isr(void)

{
  itron_acre_isr(0,0x20420100);
  return;
}


// ===== dmac10_rspi_rx_setup @ 20137b04 (536 bytes)

/* arg 1 RSPI0 (0x122) */

void dmac10_rspi_rx_setup(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
                    /* Channel Control 10 [sfr] */
  uVar1 = DMAC_CHCTRL_10;
  DMAC_CHCTRL_10 = uVar1 | 2;
  uVar1 = DMAC_CHCTRL_10;
  DMAC_CHCTRL_10 = uVar1 | 8;
  gic_disable_irq(0x33);
  DAT_20808a9c = 0;
                    /* DMA extended resource selector 5 [sfr] */
  uVar1 = DMAC_DMARS5;
  DMAC_DMARS5 = uVar1 & 0xffff0000;
  uVar1 = DMAC_DMARS5;
  if (param_1 == 0) {
    uVar2 = 0x126;
  }
  else {
    uVar2 = 0x122;
  }
  DMAC_DMARS5 = uVar1 | uVar2;
                    /* Channel Configuration 10 [sfr] */
  DMAC_CHCFG_10 = 0;
  reg_rmw32(&DMAC_CHCFG_10,0,0x10,0xf0000,uVar3);
  reg_rmw32(&DMAC_CHCFG_10,0,0xc,0xf000);
  reg_rmw32(&DMAC_CHCFG_10,0,0x15,0x200000);
  reg_rmw32(&DMAC_CHCFG_10,1,0x14,0x100000);
  reg_rmw32(&DMAC_CHCFG_10,0,0x1f,0x80000000);
  reg_rmw32(&DMAC_CHCFG_10,0,0x1c,0x10000000);
  reg_rmw32(&DMAC_CHCFG_10,1,0x1b,0x8000000);
  reg_rmw32(&DMAC_CHCFG_10,0,0x18,0x1000000);
  reg_rmw32(&DMAC_CHCFG_10,0,0x1e,0x40000000);
  reg_rmw32(&DMAC_CHCFG_10,0,0x1d,0x20000000);
  reg_rmw32(&DMAC_CHCFG_10,0,0x16,0x400000);
  reg_rmw32(&DMAC_CHCFG_10,2,8,0x700);
  reg_rmw32(&DMAC_CHCFG_10,1,6,0x40);
  reg_rmw32(&DMAC_CHCFG_10,1,5,0x20);
  reg_rmw32(&DMAC_CHCFG_10,0,4,0x10);
  reg_rmw32(&DMAC_CHCFG_10,0,3,8);
  reg_rmw32(&DMAC_CHCFG_10,2,0,7);
                    /* Channel Interval 10 [sfr] */
  DMAC_CHITVL_10 = 0;
                    /* Channel Extension 10 [sfr] */
  DMAC_CHEXT_10 = 0;
                    /* Next0 Source Address 10 [sfr] */
  DMAC_N0SA_10 = param_2;
                    /* Next0 Destination Address 10 [sfr] */
  DMAC_N0DA_10 = param_3;
                    /* Next0 Transaction Byte 10 [sfr] */
  DMAC_N0TB_10 = param_4;
  gic_enable_irq(0x33);
  reg_rmw32(&DMAC_CHCTRL_10,1,0);
  return;
}


// ===== dmac10_isr @ 20137d1c (12 bytes)

/* stub -> [0x20808AB0] */

void dmac10_isr(void)

{
                    /* WARNING: Could not recover jumptable at 0x20137d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_20808ab0)();
  return;
}


// ===== dmac3_enable @ 20137d50 (20 bytes)

void dmac3_enable(void)

{
  reg_rmw32(&DMAC_CHCTRL_3,1,0);
  return;
}


// ===== dmac3_disable @ 20137d64 (20 bytes)

/* writes 0 to SETEN (no-op?) */

void dmac3_disable(void)

{
  reg_rmw32(&DMAC_CHCTRL_3,0,0,1);
  return;
}


// ===== dmac3_set_callback @ 20137d78 (12 bytes)

/* [inference] stores r0 at 0x20808AA0, the first of the five DMA callback slots
   (dmac4/5/9/10_set_callback store at +4..+0x10), right after dmac3_disable; no caller; Ghidra
   FUN_20137d78 (T24 round 7) */

void dmac3_set_callback(undefined4 param_1)

{
  uRam20808aa0 = param_1;
  return;
}


// ===== dmac5_enable @ 20137d84 (20 bytes)

void dmac5_enable(void)

{
  reg_rmw32(&DMAC_CHCTRL_5,1,0);
  return;
}


// ===== dmac5_disable @ 20137d98 (20 bytes)

void dmac5_disable(void)

{
  reg_rmw32(&DMAC_CHCTRL_5,0,0,1);
  return;
}


// ===== dmac5_set_callback @ 20137dac (12 bytes)

void dmac5_set_callback(uint param_1)

{
  DAT_20808aa8 = param_1;
  return;
}


// ===== dmac4_enable @ 20137db8 (20 bytes)

void dmac4_enable(void)

{
  reg_rmw32(&DMAC_CHCTRL_4,1,0);
  return;
}


// ===== dmac4_disable @ 20137dcc (20 bytes)

void dmac4_disable(void)

{
  reg_rmw32(&DMAC_CHCTRL_4,0,0,1);
  return;
}


// ===== dmac4_set_callback @ 20137de0 (12 bytes)

void dmac4_set_callback(uint param_1)

{
  DAT_20808aa4 = param_1;
  return;
}


// ===== dmac9_enable @ 20137dec (20 bytes)

/* [fact] reg_rmw32(CHCTRL_9 0xE8200468, 1, 0, 1), like dmac10_enable for channel 10; new entry (T24
   round 7) */

void dmac9_enable(void)

{
  reg_rmw32(&DMAC_CHCTRL_9,1,0);
  return;
}


// ===== dmac9_stop @ 20137e00 (52 bytes)

/* CHCTRL.CLREN */

void dmac9_stop(void)

{
  reg_rmw32(&DMAC_CHCTRL_9,0,0,1);
  reg_rmw32(&DMAC_CHCTRL_9,1,1,2);
  return;
}


// ===== dmac9_set_callback @ 20137e34 (12 bytes)

void dmac9_set_callback(uint param_1)

{
  DAT_20808aac = param_1;
  return;
}


// ===== dmac10_enable @ 20137e40 (20 bytes)

void dmac10_enable(void)

{
  reg_rmw32(&DMAC_CHCTRL_10,1,0);
  return;
}


// ===== dmac10_stop @ 20137e54 (52 bytes)

void dmac10_stop(void)

{
  reg_rmw32(&DMAC_CHCTRL_10,0,0,1);
  reg_rmw32(&DMAC_CHCTRL_10,1,1,2);
  return;
}


// ===== dmac10_set_callback @ 20137e88 (12 bytes)

void dmac10_set_callback(uint param_1)

{
  DAT_20808ab0 = param_1;
  return;
}


// ===== FUN_20137eac @ 20137eac (256 bytes)

int FUN_20137eac(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                int param_7,int param_8,int param_9,int param_10)

{
  int i;
  int *piVar1;
  
  i = 0;
  if (0 < DAT_20808ab4) {
    do {
      piVar1 = (int *)(&DAT_2090a3f8)[i];
      if (((((((*piVar1 < 0) || (*piVar1 == param_2)) && ((piVar1[1] < 0 || (piVar1[1] == param_3)))
             ) && ((piVar1[2] < 0 || (piVar1[2] == param_4)))) &&
           ((piVar1[3] < 0 || (piVar1[3] == param_5)))) &&
          ((((piVar1[4] < 0 || (piVar1[4] == param_6)) &&
            ((piVar1[5] < 0 || (piVar1[5] == param_7)))) &&
           ((piVar1[6] < 0 || (piVar1[6] == param_8)))))) &&
         ((piVar1[7] < 0 || (piVar1[7] == param_9)))) {
        if (piVar1[8] < 0) {
          return i;
        }
        if (piVar1[8] == param_10) {
          return i;
        }
      }
      i = i + 1;
    } while (i < DAT_20808ab4);
  }
  return -1;
}


// ===== usbh_enumerate_config @ 20137fac (1124 bytes)

/* Reads the configuration descriptor (usbh_get_config_descriptor, 0x7FF bytes), sets the
   configuration and walks its interfaces and endpoints to set up pipes and the class driver
   (FUN_20137eac, usbh_open_endpoint_pipes) [fact for the calls] */

undefined4 usbh_enumerate_config(uint param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  code *pcVar14;
  int iVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint unaff_r7;
  int iVar21;
  int iVar22;
  
  if (((param_1 < 2) && (0 < param_2)) && (param_2 < 2)) {
    iVar10 = param_1 * 0x904 + 0x2090a458 + param_2 * 0x904;
    iVar20 = iVar10 + -0x904;
    iVar11 = 1;
    do {
      iVar21 = iVar11 * 4;
      iVar11 = iVar11 + 1;
      *(undefined4 *)(iVar20 + iVar21 + 0x8d8) = 0;
    } while (iVar11 < 10);
    *(undefined4 **)(iVar10 + -0x2c) = param_3;
    *(uint *)(iVar10 + -0x8fc) = param_1;
    *(int *)(iVar10 + -0x8f4) = param_2;
    *(undefined1 *)(iVar10 + -0x8e4) = *(undefined1 *)((int)param_3 + 0x1a);
    *(undefined1 *)(iVar10 + -0x8e3) = *(undefined1 *)((int)param_3 + 0x1b);
    *(undefined1 *)(iVar10 + -0x8e2) = *(undefined1 *)(param_3 + 7);
    *(undefined2 *)(iVar10 + -0x8e0) = *(undefined2 *)((int)param_3 + 0x1e);
    *(undefined2 *)(iVar10 + -0x8de) = *(undefined2 *)(param_3 + 8);
    *(undefined2 *)(iVar10 + -0x8dc) = *(undefined2 *)((int)param_3 + 0x22);
    *(undefined1 *)(iVar10 + -0x8da) = *(undefined1 *)(param_3 + 9);
    *(undefined1 *)(iVar10 + -0x8d9) = *(undefined1 *)((int)param_3 + 0x25);
    *(undefined1 *)(iVar10 + -0x8d8) = *(undefined1 *)((int)param_3 + 0x26);
    __aeabi_memclr4(iVar10 + -0xa4,0x78);
    *param_3 = 1;
                    /* SETUP 0x80, 6, wValue 0x0200 [doc] */
    uVar12 = usbh_get_config_descriptor(param_3,iVar10 + -0x8b6,0x7ff);
    if (-1 < (int)uVar12) {
      uVar17 = 0xffffffff;
      if ((int)(uint)*(ushort *)(iVar10 + -0x8b4) < (int)uVar12) {
        uVar12 = (uint)*(ushort *)(iVar10 + -0x8b4);
      }
      uVar19 = uVar12;
      for (pbVar13 = (byte *)(iVar10 + -0x8b6); (byte *)(iVar20 + uVar12 + 0x4e) != pbVar13;
          pbVar13 = pbVar13 + uVar18) {
        uVar18 = (uint)*pbVar13;
        if (uVar18 == 0) {
          return 0xffffffff;
        }
        if ((int)uVar19 < (int)uVar18) {
          return 0xffffffff;
        }
        if ((pbVar13[1] == 2) && ((int)uVar17 < 0)) {
          uVar17 = (uint)pbVar13[5];
        }
        uVar19 = uVar19 - uVar18;
      }
      *(undefined1 *)(iVar20 + uVar12 + 0x4e) = 0;
      if (-1 < (int)uVar17) {
        usbh_set_configuration(param_3);
        iVar11 = 0;
        if (0 < DAT_20808ab4) {
          do {
            if ((&DAT_2090a428)[iVar11] == 0) {
              *(int *)(iVar10 + -0x900) = iVar11;
              *(undefined4 *)(iVar10 + -4) = *(undefined4 *)((&DAT_2090a3f8)[iVar11] + 0x24);
              (**(code **)((&DAT_2090a3f8)[iVar11] + 0x24))(param_1,param_2,iVar20);
              if (-1 < *(int *)(iVar10 + -0x900)) {
                return 0;
              }
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < DAT_20808ab4);
        }
        cVar1 = *(char *)(param_3 + 9);
        sVar8 = *(short *)((int)param_3 + 0x1e);
        sVar9 = *(short *)(param_3 + 8);
        cVar2 = *(char *)((int)param_3 + 0x25);
        cVar3 = *(char *)((int)param_3 + 0x26);
        iVar11 = FUN_20137eac(param_1,*(undefined1 *)((int)param_3 + 0x1a),
                              *(undefined1 *)((int)param_3 + 0x1b),*(undefined1 *)(param_3 + 7),
                              sVar8,sVar9,*(undefined2 *)((int)param_3 + 0x22),cVar1,cVar2,cVar3);
        if (-1 < iVar11) {
          pcVar14 = *(code **)((&DAT_2090a3f8)[iVar11] + 0x24);
          *(code **)(iVar10 + -4) = pcVar14;
          if (pcVar14 != (code *)0x0) {
            iVar11 = 1;
            iVar21 = 0;
            pbVar13 = (byte *)(iVar10 + -0x8b6);
            do {
              if ((int)uVar12 < 1) {
                *(int *)(iVar10 + -0x8e8) = iVar11;
                (*pcVar14)(param_1,param_2,iVar20);
                return 0;
              }
              uVar17 = (uint)*pbVar13;
              if (pbVar13[1] == 4) {
                unaff_r7 = (uint)pbVar13[2];
              }
              else if (pbVar13[1] == 5) {
                bVar4 = pbVar13[5];
                iVar22 = iVar21 + 1;
                bVar5 = pbVar13[4];
                bVar6 = pbVar13[3];
                bVar7 = pbVar13[6];
                iVar15 = iVar20 + iVar22 * 0xc;
                *(byte *)(iVar15 + 0x860) = pbVar13[2];
                *(byte *)(iVar15 + 0x861) = bVar6;
                *(uint *)(iVar15 + 0x864) = (uint)bVar5 + (uint)bVar4 * 0x100;
                *(uint *)(iVar15 + 0x868) = (uint)bVar7;
                if (cVar1 == '\b') {
                  if (((cVar2 != '\x06') || (cVar3 != 'P')) || ((~bVar6 & 3) != 0))
                  goto LAB_20138360;
                }
                else if ((cVar1 != '\x03') ||
                        (((((iVar11 != 2 && ((sVar8 != 0x1ea7 || sVar9 != 0x66 || (unaff_r7 == 1))))
                           && ((sVar8 != 0x25a7 || ((sVar9 != -0x59f || (unaff_r7 == 1)))))) &&
                          ((sVar8 != 0x45e || ((sVar9 != 0x7b2 || (unaff_r7 == 1)))))) &&
                         ((sVar8 != 0x56e || sVar9 != 0x134 || (unaff_r7 == 1)))))) {
LAB_20138360:
                  *(uint *)(iVar10 + -0xb4) = unaff_r7;
                  puVar16 = (undefined4 *)usbh_open_endpoint_pipes(param_3,pbVar13);
                  if (puVar16 == (undefined4 *)0x0) {
                    iVar21 = 1;
                    if (1 < iVar11) {
                      do {
                        iVar15 = iVar20 + iVar21 * 4;
                        if (*(int *)(iVar15 + 0x8d8) != 0) {
                          FUN_2013ad24();
                          *(undefined4 *)(iVar15 + 0x8d8) = 0;
                        }
                        iVar21 = iVar21 + 1;
                      } while (iVar21 < iVar11);
                    }
                    *(undefined4 *)(iVar10 + -0x2c) = 0;
                    return 0xffffffff;
                  }
                  *puVar16 = 0;
                  iVar11 = iVar11 + 1;
                  *(undefined4 **)(iVar20 + iVar22 * 4 + 0x8d8) = puVar16;
                  iVar21 = iVar22;
                }
              }
              pbVar13 = pbVar13 + uVar17;
              uVar12 = uVar12 - uVar17;
            } while( true );
          }
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== FUN_20138410 @ 20138410 (40 bytes)

undefined4 FUN_20138410(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int i;
  int iVar2;
  int iVar3;
  
  if ((((param_1 < 2) && (0 < param_2)) && (param_2 < 2)) && (param_3 != 0)) {
    iVar1 = param_1 * 0x904 + 0x2090a458 + param_2 * 0x904;
    if (*(code **)(iVar1 + -4) != (code *)0x0) {
      (**(code **)(iVar1 + -4))(param_1,param_2,0);
    }
    iVar3 = *(int *)(iVar1 + -0x8e8);
    if (*(int *)(*(int *)(param_3 + 8) + 0x48) == param_3) {
      FUN_2013ad24(*(int *)(param_3 + 8) + 0x40);
    }
    i = 1;
    if (1 < iVar3) {
      do {
        iVar2 = iVar1 + -0x904 + i * 4;
        if (*(int *)(iVar2 + 0x8d8) != 0) {
          FUN_2013ad24();
          *(undefined4 *)(iVar2 + 0x8d8) = 0;
        }
        i = i + 1;
      } while (i < iVar3);
    }
    *(undefined4 *)(iVar1 + -0x2c) = 0;
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20138438 @ 20138438 (156 bytes)

undefined4 FUN_20138438(int param_1,int param_2,int param_3)

{
  int iVar1;
  int i;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1 * 0x904 + 0x2090a458 + param_2 * 0x904;
  if (*(code **)(iVar1 + -4) != (code *)0x0) {
    (**(code **)(iVar1 + -4))(param_1,param_2,0);
  }
  iVar3 = *(int *)(iVar1 + -0x8e8);
  if (*(int *)(*(int *)(param_3 + 8) + 0x48) == param_3) {
    FUN_2013ad24(*(int *)(param_3 + 8) + 0x40);
  }
  i = 1;
  if (1 < iVar3) {
    do {
      iVar2 = iVar1 + -0x904 + i * 4;
      if (*(int *)(iVar2 + 0x8d8) != 0) {
        FUN_2013ad24();
        *(undefined4 *)(iVar2 + 0x8d8) = 0;
      }
      i = i + 1;
    } while (i < iVar3);
  }
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  return 0;
}


// ===== FUN_201384d4 @ 201384d4 (164 bytes)

undefined4 FUN_201384d4(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = DAT_20808ab4;
  if (DAT_20808ab4 < 0xc) {
    uVar4 = (uint)(-1 < *param_1);
    if (-1 < param_1[1]) {
      uVar4 = 1;
    }
    if (-1 < param_1[2]) {
      uVar4 = 1;
    }
    if (-1 < param_1[3]) {
      uVar4 = 1;
    }
    if (-1 < param_1[4]) {
      uVar4 = 1;
    }
    if (-1 < param_1[5]) {
      uVar4 = 1;
    }
    if (-1 < param_1[6]) {
      uVar4 = 1;
    }
    if (-1 < param_1[7]) {
      uVar4 = 1;
    }
    if (-1 < param_1[8]) {
      uVar4 = 1;
    }
    piVar1 = &DAT_2090a3f8 + DAT_20808ab4;
    DAT_20808ab4 = DAT_20808ab4 + 1;
    *piVar1 = (int)param_1;
    (&DAT_2090a428)[iVar2] = uVar4;
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== FUN_2013857c @ 2013857c (40 bytes)

int FUN_2013857c(int param_1,int param_2)

{
  return param_1 * 0x904 + param_2 * 0x904 + 0x20909b54;
}


// ===== usbh_ports_init @ 201385b4 (172 bytes)

/* For USB ports 0/1: usbh_create_objects (0x2090B660 + 0x4D8*port), pipe buffers 0x20909FD0..,
   starts the two port tasks and FUN_2013b2b4 (boot-rtos.md init list) [fact] */

undefined4 usbh_ports_init(void)

{
  uint uVar1;
  uint usbh_create_objects_ret;
  int iVar2;
  int iVar3;
  int i;
  
  i = 0;
  DAT_20808ab8 = 0;
  do {
                    /* m596 / udevtsk%d names [doc, inference] */
    usbh_create_objects_ret = usbh_create_objects(i,(int)(&DAT_2090b660 + i * 0x4d8));
    uVar1 = DAT_20808ab8;
    if ((int)usbh_create_objects_ret < 0) {
      return 0xffffffff;
    }
    iVar2 = 1;
    do {
      iVar3 = iVar2 + 1;
      *(uint *)(&DAT_2090b660 + i * 0x4d8 + iVar2 * 0x70 + 0x88) =
           i * 0x8100 + iVar2 * 0x2040 + uVar1 + 0x20909fd0 & ~uVar1;
      iVar2 = iVar3;
    } while (iVar3 < 5);
    itron_act_tsk((&DAT_2090b684)[i * 0x136]);
    itron_act_tsk((&DAT_2090b688)[i * 0x136]);
    FUN_2013b2b4(i);
    i = i + 1;
  } while (i < 2);
  return 0;
}


// ===== FUN_20138660 @ 20138660 (8 bytes)

undefined4 FUN_20138660(void)

{
  return 0;
}


// ===== FUN_20138668 @ 20138668 (8 bytes)

undefined4 FUN_20138668(void)

{
  return 0;
}


// ===== FUN_20138670 @ 20138670 (36 bytes)

undefined4 FUN_20138670(int param_1)

{
  *(undefined2 *)(*(int *)(*(int *)(param_1 + 4) + 8) + (&DAT_20420144)[*(int *)(param_1 + 0xc)]) =
       0x100;
  return 0;
}


// ===== FUN_20138694 @ 20138694 (40 bytes)

uint FUN_20138694(undefined4 param_1,int *param_2)

{
  uint uVar1;
  
  if (*param_2 == 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if (param_2[6] != 0) {
      uVar1 = 0x80;
    }
    uVar1 = uVar1 | param_2[5];
  }
  return uVar1;
}


// ===== FUN_201386bc @ 201386bc (132 bytes)

undefined4 FUN_201386bc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int extraout_r3;
  int iVar3;
  int iVar4;
  undefined4 extraout_r12;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0xc);
  if (iVar3 != 0) {
    if (*(int *)(param_1 + 4) == 0) {
      return 0;
    }
    iVar2 = 1;
    do {
      iVar1 = iVar3 + iVar2 * 0x70;
      if ((((*(int *)(iVar1 + 0x50) != 0) && (*(int *)(iVar1 + 0x48) != 0)) &&
          (*(int *)(*(int *)(iVar1 + 0x48) + 0xc) == iVar4)) &&
         (iVar1 = FUN_20138694(0,iVar1 + 0x40), iVar2 = extraout_r3, iVar1 == param_2)) {
        return extraout_r12;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 10);
  }
  return 0;
}


// ===== reg_wait_bits27 @ 20138740 (52 bytes)

/* (base, off, val): cpu_delay_cycles4, then waits until (*(base->regs + off) & 0x27) == (val &
   0x27) [fact] */

void reg_wait_bits27(int param_1,int param_2,ushort param_3)

{
  cpu_delay_cycles4();
  do {
  } while ((*(ushort *)(*(int *)(param_1 + 8) + param_2) & 0x27) != (param_3 & 0x27));
  return;
}


// ===== FUN_20138774 @ 20138774 (676 bytes)

int FUN_20138774(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  uint local_3c [2];
  int iStack_34;
  int iStack_30;
  undefined1 *local_2c;
  int iStack_28;
  
  uVar2 = *(undefined4 *)(param_1 + 0x38);
  iVar6 = -0x3ec;
  uVar3 = *(uint *)(param_1 + 100);
  iStack_34 = param_1;
  iStack_30 = param_2;
  local_2c = param_3;
  iStack_28 = param_4;
  if (param_4 == 0) {
LAB_201388b0:
    if ((*(int *)(param_2 + 4) != 0) && (*(int *)(param_2 + 0x30) == 0)) {
      *(undefined4 *)(param_1 + 0x58) = 1;
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
      *(ushort *)(*(int *)(param_1 + 8) + 0x5c) = *(ushort *)(*(int *)(param_1 + 8) + 0x5c) & 0xffef
      ;
      itron_twai_sem(uVar2,0xffffffff);
      *(ushort *)(*(int *)(param_1 + 8) + 0x20) = *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xffd8
      ;
      reg_wait_bits27(param_1,0x20,0);
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x4000;
      itron_sig_sem(uVar2);
      itron_clr_flg(uVar3,0);
      *(undefined4 *)(param_1 + 0x84) = 0;
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0x81;
      pvVar4 = itron_twai_flg(uVar3,0x1b,1,local_3c,500);
      if (((pvVar4 == (void *)0x0) && ((local_3c[0] & 8) == 0 && (local_3c[0] & 0x10) == 0)) &&
         (((local_3c[0] & 2) != 0 || (iVar6 = param_4, (local_3c[0] & 1) != 0)))) goto LAB_20138994;
    }
  }
  else if ((*(int *)(param_2 + 4) != 0) && (*(int *)(param_2 + 0x30) == 0)) {
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
    *(ushort *)(*(int *)(param_1 + 8) + 0x5c) = *(ushort *)(*(int *)(param_1 + 8) + 0x5c) | 0x110;
    itron_twai_sem(uVar2,0xffffffff);
    *(ushort *)(*(int *)(param_1 + 8) + 0x20) =
         *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0x100 | 0x20;
    reg_wait_bits27(param_1,0x20);
    puVar1 = local_2c;
    for (iVar5 = param_4; 0 < iVar5; iVar5 = iVar5 + -1) {
      *(undefined1 *)(*(int *)(param_1 + 8) + 0x17) = *puVar1;
      puVar1 = puVar1 + 1;
    }
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x8000;
    itron_sig_sem(uVar2);
    itron_clr_flg(uVar3,0);
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0x81;
    pvVar4 = itron_twai_flg(uVar3,0x1b,1,local_3c,500);
    if ((pvVar4 == (void *)0x0) && ((local_3c[0] & 8) == 0 && (local_3c[0] & 0x10) == 0)) {
      if ((local_3c[0] & 2) != 0) goto LAB_20138994;
      if ((local_3c[0] & 1) != 0) goto LAB_201388b0;
    }
  }
  iVar6 = -1;
LAB_20138994:
  *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
  if (iVar6 < 0) {
    iVar5 = 0;
    do {
      if ((*(ushort *)(*(int *)(param_1 + 8) + 0x60) & 0x20) == 0) break;
      itron_dly_tsk(5);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x32);
    itron_twai_sem(uVar2,0xffffffff);
    *(ushort *)(*(int *)(param_1 + 8) + 0x20) =
         *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xfff8 | 0x20;
    reg_wait_bits27(param_1,0x20);
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x4000;
    itron_sig_sem(uVar2);
  }
  return iVar6;
}


// ===== FUN_20138a18 @ 20138a18 (620 bytes)

int FUN_20138a18(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_28;
  
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  uVar5 = *(uint *)(param_1 + 100);
  if ((*(int *)(param_2 + 4) != 0) && (*(int *)(param_2 + 0x30) == 0)) {
    *(undefined4 *)(param_1 + 0x58) = 1;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x70) = param_3;
    *(undefined4 *)(param_1 + 0x74) = param_4;
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
    *(ushort *)(*(int *)(param_1 + 8) + 0x5c) = *(ushort *)(*(int *)(param_1 + 8) + 0x5c) & 0xfeef;
    itron_twai_sem(uVar1,0xffffffff);
    *(ushort *)(*(int *)(param_1 + 8) + 0x20) = *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xffd8;
    reg_wait_bits27(param_1,0x20,0);
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x4000;
    itron_sig_sem(uVar1);
    itron_clr_flg(uVar5,0);
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(ushort *)(*(int *)(param_1 + 8) + 0x60) = *(ushort *)(*(int *)(param_1 + 8) + 0x60) | 0x81;
    pvVar2 = itron_twai_flg(uVar5,0x1b,1,&local_28,500);
    if ((pvVar2 == (void *)0x0) && ((local_28 & 8) == 0 && (local_28 & 0x10) == 0)) {
      iVar4 = -0x3ec;
      if ((local_28 & 2) != 0) goto LAB_20138c04;
      if ((((local_28 & 1) != 0) && (iVar3 = *(int *)(param_1 + 0x78), *(int *)(param_2 + 4) != 0))
         && (*(int *)(param_2 + 0x30) == 0)) {
        *(undefined4 *)(param_1 + 0x58) = 0;
        *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
        *(ushort *)(*(int *)(param_1 + 8) + 0x5c) = *(ushort *)(*(int *)(param_1 + 8) + 0x5c) | 0x10
        ;
        itron_twai_sem(uVar1,0xffffffff);
        *(ushort *)(*(int *)(param_1 + 8) + 0x20) =
             *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0x100 | 0x20;
        reg_wait_bits27(param_1,0x20);
        *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0xc000;
        itron_sig_sem(uVar1);
        itron_clr_flg(uVar5,0);
        *(undefined4 *)(param_1 + 0x84) = 0;
        *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0x81;
        pvVar2 = itron_twai_flg(uVar5,0x1b,1,&local_28,500);
        if (((pvVar2 == (void *)0x0) && ((local_28 & 8) == 0 && (local_28 & 0x10) == 0)) &&
           (((local_28 & 2) != 0 || (iVar4 = iVar3, (local_28 & 1) != 0)))) goto LAB_20138c04;
      }
    }
  }
  iVar4 = -1;
LAB_20138c04:
  *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
  if (iVar4 < 0) {
    iVar3 = 0;
    do {
      if ((*(ushort *)(*(int *)(param_1 + 8) + 0x60) & 0x20) == 0) break;
      itron_dly_tsk(5);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x32);
    itron_twai_sem(uVar1,0xffffffff);
    *(ushort *)(*(int *)(param_1 + 8) + 0x20) =
         *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xfff8 | 0x20;
    reg_wait_bits27(param_1,0x20);
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x4000;
    itron_sig_sem(uVar1);
  }
  return iVar4;
}


// ===== FUN_20138c84 @ 20138c84 (108 bytes)

undefined4 FUN_20138c84(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {
    *(ushort *)
     (*(int *)(*(int *)(param_1 + 8) + 8) + *(int *)(&DAT_20420184 + *(int *)(param_1 + 0xc) * 4)) =
         (ushort)*(byte *)(param_1 + 0x15) << 8 |
         *(short *)(&DAT_20420114 + (uint)*(byte *)(param_1 + 0x18) * 2) << 6 |
         (ushort)*(byte *)(param_1 + 0x19) | (ushort)*(byte *)(param_1 + 0x14) << 0xb;
    return 0;
  }
  return 0xffffffff;
}


// ===== usbh_control_transfer @ 20138cf0 (504 bytes)

/* Control transfer on a pipe object under its semaphore (+0x4A8, TMO_FEVR): SETUP, data and status
   stages [inference from the callers' SETUP packets] */

undefined4
usbh_control_transfer
          (undefined4 param_1,int param_2,byte *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  void *itron_twai_flg_ret;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_3c [2];
  undefined4 uStack_34;
  int iStack_30;
  byte *pbStack_2c;
  undefined4 local_28;
  
  iVar3 = 0;
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = *(int *)(param_2 + 8);
    uVar4 = *(undefined4 *)(iVar2 + 0x4a8);
    uStack_34 = param_1;
    iStack_30 = param_2;
    pbStack_2c = param_3;
    local_28 = param_4;
    itron_twai_sem(uVar4,0xffffffff);
    if ((*(int *)(param_2 + 4) != 0) && (*(int *)(param_2 + 0x30) == 0)) {
      *(undefined4 *)(iVar2 + 0x8c) = *(undefined4 *)(param_2 + 0x2c);
      *(undefined4 *)(iVar2 + 0x90) = *(undefined4 *)(param_2 + 0x30);
      *(int *)(iVar2 + 0x48) = param_2;
      FUN_20138c84(param_2);
      if ((*(char *)(param_2 + 0x16) == '\0') && (*(char *)(param_2 + 0x18) == '\x02')) {
        *(ushort *)(*(int *)(iVar2 + 8) + 0x3c) = *(ushort *)(*(int *)(iVar2 + 8) + 0x3c) | 0x100;
      }
      do {
        uVar1 = *(undefined4 *)(param_2 + 0x10);
        *(undefined4 *)(iVar2 + 0x6c) = uVar1;
        *(ushort *)(*(int *)(iVar2 + 8) + 0x5e) =
             (ushort)uVar1 | (ushort)*(byte *)(param_2 + 0xc) << 0xc;
        *(undefined2 *)(*(int *)(iVar2 + 8) + 0x54) = *(undefined2 *)param_3;
        *(undefined2 *)(*(int *)(iVar2 + 8) + 0x56) = *(undefined2 *)(param_3 + 2);
        *(undefined2 *)(*(int *)(iVar2 + 8) + 0x58) = *(undefined2 *)(param_3 + 4);
        *(undefined2 *)(*(int *)(iVar2 + 8) + 0x5a) = *(undefined2 *)(param_3 + 6);
        *(undefined2 *)(*(int *)(iVar2 + 8) + 0x5c) = 0;
        itron_clr_flg(*(undefined4 *)(iVar2 + 0x1c),0xfffffffc);
        *(undefined2 *)(*(int *)(iVar2 + 8) + 0x60) = 0x4000;
        itron_twai_flg_ret = itron_twai_flg(*(uint *)(iVar2 + 0x1c),3,1,local_3c,500);
        if (itron_twai_flg_ret != (void *)0x0) {
          uVar1 = 0xffffffff;
          *(ushort *)(*(int *)(iVar2 + 8) + 0x60) = *(ushort *)(*(int *)(iVar2 + 8) + 0x60) | 0x800;
          goto LAB_20138ea8;
        }
        if ((local_3c[0] & 2) == 0) {
          if ((*param_3 & 0x80) == 0) {
            uVar1 = FUN_20138774(iVar2,param_2,local_28,param_5);
          }
          else {
            uVar1 = FUN_20138a18();
          }
          if ((((*param_3 & 0xe0) != 0) || (param_3[1] != 1)) ||
             ((iVar3 = FUN_201386bc(param_2,*(undefined2 *)(param_3 + 4)), iVar3 != 0 &&
              (iVar3 = FUN_20138670(), iVar3 == 0)))) goto LAB_20138ea8;
          break;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 3);
    }
    uVar1 = 0xffffffff;
LAB_20138ea8:
    if ((*(char *)(param_2 + 0x16) == '\0') && (*(char *)(param_2 + 0x18) == '\x02')) {
      *(ushort *)(*(int *)(iVar2 + 8) + 0x3c) = *(ushort *)(*(int *)(iVar2 + 8) + 0x3c) & 0xfeff;
    }
    *(undefined4 *)(iVar2 + 0x48) = 0;
    itron_sig_sem(uVar4);
  }
  return uVar1;
}


// ===== usbh_control_req @ 20138f00 (20 bytes)

/* Thin wrapper of usbh_control_transfer used by every request helper [fact] */

void usbh_control_req(void)

{
                    /* Control transfer on a pipe object under its semaphore [doc, inference] */
  usbh_control_transfer();
  return;
}


// ===== FUN_20138f1c @ 20138f1c (28 bytes)

longlong FUN_20138f1c(int param_1,int param_2,uint param_3)

{
  *(undefined2 *)(*(int *)(param_1 + 8) + param_2) = 0;
  return (ulonglong)param_3 << 0x20;
}


// ===== FUN_20138f30 @ 20138f30 (40 bytes)

uint FUN_20138f30(int param_1,void *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x18;
  }
  else {
    if (param_1 != 1) {
      return 0xffffffff;
    }
    uVar1 = 0x1c;
  }
  *(undefined4 *)param_2 = uVar1;
  return 0;
}


// ===== FUN_20138f58 @ 20138f58 (132 bytes)

undefined4 FUN_20138f58(int param_1,undefined2 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar2 = param_3;
  if ((~(uint)param_2 & 1) != 0) {
    uVar2 = param_3 & 1;
    for (iVar1 = (int)param_3 / 2; 0 < iVar1; iVar1 = iVar1 + -1) {
      *(undefined2 *)(iVar3 + 0x16) = *param_2;
      param_2 = param_2 + 1;
    }
  }
  *(ushort *)(*(int *)(param_1 + 8) + 0x20) = *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xf3ff;
  for (; 0 < (int)uVar2; uVar2 = uVar2 - 1) {
    *(undefined1 *)(iVar3 + 0x17) = *(undefined1 *)param_2;
    param_2 = (undefined2 *)((int)param_2 + 1);
  }
  return 0;
}


// ===== FUN_20138fdc @ 20138fdc (672 bytes)

/* WARNING: Removing unreachable block (ram,0x201390f0) */

int FUN_20138fdc(int param_1,uint param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  void *itron_twai_flg_ret;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_44;
  undefined1 local_40 [4];
  int local_3c;
  int iStack_34;
  uint uStack_30;
  uint local_2c;
  int iStack_28;
  
  if (param_2 == 0) {
    iVar4 = 2;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x3c);
  }
  uVar1 = *(undefined4 *)(param_1 + iVar4 * 4 + 0x30);
  iVar3 = *(int *)(&DAT_2042016c + iVar4 * 4);
  iVar6 = *(int *)(&DAT_20420178 + iVar4 * 4);
  iVar5 = (&DAT_20420144)[param_2];
  local_3c = param_1 + param_2 * 0x70;
  uVar2 = *(uint *)(local_3c + 100);
  iStack_34 = param_1;
  uStack_30 = param_2;
  local_2c = param_3;
  iStack_28 = param_4;
  itron_twai_sem(uVar1,0xffffffff);
  param_2 = param_2 & 0xffff;
  if ((local_2c & 1) == 0) {
    param_2 = param_2 | 0x400;
  }
  if (iVar4 != 2 && param_4 != 0) {
    param_2 = param_2 | 0x1000;
  }
  *(ushort *)(*(int *)(param_1 + 8) + iVar3) =
       *(ushort *)(*(int *)(param_1 + 8) + iVar3) & 0x100 | (ushort)param_2;
  reg_wait_bits27(param_1,iVar3,param_2);
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar5) = 0;
  if (param_4 == 0) {
    *(undefined2 *)(*(int *)(param_1 + 8) + iVar6) = 0xc000;
  }
  else {
    if (iVar4 == 2) {
      FUN_20138f58(param_1,local_2c,param_4);
    }
    else {
      FUN_20138f30(iVar4,local_40);
    }
    *(undefined2 *)(*(int *)(param_1 + 8) + iVar6) = 0x8000;
  }
  if (iVar4 != 2 && param_4 != 0) {
    *(ushort *)(*(int *)(param_1 + 8) + iVar3) = *(ushort *)(*(int *)(param_1 + 8) + iVar3) & 0xeff8
    ;
  }
  itron_sig_sem(uVar1);
  itron_clr_flg(uVar2,0);
  *(undefined4 *)(local_3c + 0x84) = 0;
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar5) = 1;
  itron_twai_flg_ret = itron_twai_flg(uVar2,0x1b,1,&local_44,500);
  iVar4 = 0;
  if (itron_twai_flg_ret != (void *)0x0) {
    iVar4 = -1;
  }
  if ((local_44 & 8) != 0) {
    iVar4 = -1;
  }
  if ((local_44 & 0x10) != 0) {
    iVar4 = -1;
  }
  if ((local_44 & 2) != 0) {
    iVar4 = -0x3ec;
  }
  if ((local_44 & 1) == 0 && iVar4 == 0) {
    iVar4 = -1;
  }
  else if (iVar4 == 0) {
    return 0;
  }
  itron_twai_sem(uVar1,0xffffffff);
  *(ushort *)(*(int *)(param_1 + 8) + iVar3) =
       *(ushort *)(*(int *)(param_1 + 8) + iVar3) & 0x100 | (ushort)param_2;
  reg_wait_bits27(param_1,iVar3,param_2);
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar5) = 0;
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar6) = 0x4000;
  *(ushort *)(*(int *)(param_1 + 8) + iVar3) = *(ushort *)(*(int *)(param_1 + 8) + iVar3) & 0x100;
  itron_sig_sem(uVar1);
  iVar3 = 0;
  do {
    if ((*(ushort *)(*(int *)(param_1 + 8) + iVar5) & 0x20) == 0) break;
    itron_dly_tsk(5);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x32);
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar5) = 0x200;
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar5) = 0;
  return iVar4;
}


// ===== usbh_pipe_write_buf @ 2013927c (180 bytes)

/* (pipe, buf, len): sends the buffer packet by packet with FUN_20138fdc, then a zero-length packet
   when needed [fact for the calls] */

int usbh_pipe_write_buf(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 4);
  iVar5 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(*(int *)(iVar6 + 0x4d4) + iVar5 * 4 + -4);
  if ((*(int *)(*(int *)(param_1 + 8) + 4) == 0) || (*(int *)(*(int *)(param_1 + 8) + 0x30) != 0)) {
    return -1;
  }
  iVar1 = param_3;
  if (param_3 == 0) {
    iVar4 = FUN_20138fdc(iVar6,iVar5,0);
    if (iVar4 != 0) {
      return -1;
    }
  }
  else {
    for (; 0 < iVar1; iVar1 = iVar1 - iVar3) {
      iVar3 = iVar4;
      if (iVar1 <= iVar4) {
        iVar3 = iVar1;
      }
      iVar2 = FUN_20138fdc(iVar6,iVar5,param_2,iVar3);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_2 = param_2 + iVar3;
    }
  }
  return param_3;
}


// ===== usbh_buf_needs_bounce @ 20139330 (20 bytes)

/* (addr): -1 when addr has a bit of the mask 0x20808AB8 set (the buffer must be copied through the
   pipe buffer), else 0 [fact] */

undefined4 usbh_buf_needs_bounce(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 & DAT_20808ab8) != 0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

