// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== sdhi_dma_read_start @ 2013ffec (68 bytes)

/* (dst, src): DMAC channel 0 for one 512-byte block (CHCFG 0x126260) and start [fact] */

void sdhi_dma_read_start(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
                    /* Next0 Source Address 0 [sfr] */
  DMAC_N0SA_0 = param_2;
                    /* Next0 Destination Address 0 [sfr] */
  DMAC_N0DA_0 = param_1;
                    /* Next0 Transaction Byte 0 [sfr] */
  DMAC_N0TB_0 = 0x200;
                    /* Channel Configuration 0 [sfr] */
  DMAC_CHCFG_0 = 0x126260;
                    /* Channel Interval 0 [sfr] */
  DMAC_CHITVL_0 = 0;
                    /* Channel Extension 0 [sfr] */
  DMAC_CHEXT_0 = 0;
                    /* Channel Control 0 [sfr] */
  uVar1 = DMAC_CHCTRL_0;
  DMAC_CHCTRL_0 = uVar1 | 8;
  uVar1 = DMAC_CHCTRL_0;
  DMAC_CHCTRL_0 = uVar1 | 1;
  return;
}


// ===== sdhi_dma_read_wait @ 20140030 (48 bytes)

/* Polls DMAC channel 0 CHSTAT until idle, then CHCTRL clear [fact] */

void sdhi_dma_read_wait(void)

{
  uint uVar1;
  uint dmac_chstat_0;
  
  uVar1 = 0;
  do {
                    /* Channel Status 0 [sfr] */
    dmac_chstat_0 = DMAC_CHSTAT_0;
    if ((dmac_chstat_0 & 5) == 0) break;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x900000);
                    /* Channel Control 0 [sfr] */
  uVar1 = DMAC_CHCTRL_0;
  DMAC_CHCTRL_0 = uVar1 | 8;
  return;
}


// ===== sdhi_dma_write_start @ 20140060 (68 bytes)

/* (dst, src): DMAC channel 1 for one 512-byte block (CHCFG 0x262269) and start [fact] */

void sdhi_dma_write_start(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
                    /* Next0 Source Address 1 [sfr] */
  DMAC_N0SA_1 = param_2;
                    /* Next0 Destination Address 1 [sfr] */
  DMAC_N0DA_1 = param_1;
                    /* Next0 Transaction Byte 1 [sfr] */
  DMAC_N0TB_1 = 0x200;
                    /* Channel Configuration 1 [sfr] */
  DMAC_CHCFG_1 = 0x262269;
                    /* Channel Interval 1 [sfr] */
  DMAC_CHITVL_1 = 0;
                    /* Channel Extension 1 [sfr] */
  DMAC_CHEXT_1 = 0;
                    /* Channel Control 1 [sfr] */
  uVar1 = DMAC_CHCTRL_1;
  DMAC_CHCTRL_1 = uVar1 | 8;
  uVar1 = DMAC_CHCTRL_1;
  DMAC_CHCTRL_1 = uVar1 | 1;
  return;
}


// ===== sdhi_dma_write_wait @ 201400a4 (48 bytes)

/* Polls DMAC channel 1 CHSTAT until idle, then CHCTRL clear [fact] */

void sdhi_dma_write_wait(void)

{
  uint uVar1;
  uint dmac_chstat_1;
  
  uVar1 = 0;
  do {
                    /* Channel Status 1 [sfr] */
    dmac_chstat_1 = DMAC_CHSTAT_1;
    if ((dmac_chstat_1 & 5) == 0) break;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x900000);
                    /* Channel Control 1 [sfr] */
  uVar1 = DMAC_CHCTRL_1;
  DMAC_CHCTRL_1 = uVar1 | 8;
  return;
}


// ===== sdhi_init @ 201400d4 (60 bytes)

/* SDINT_INI */

uint sdhi_init(void)

{
  int iVar1;
  
  iVar1 = DAT_20808b74;
  if ((DAT_20808b74 == 0) && (iVar1 = os_create_flg_named(&DAT_204205d8,"SDINT_INI"), iVar1 < 1)) {
    return 0xffffffff;
  }
  DAT_20808b74 = iVar1;
  return 0;
}


// ===== sdhi_flag_set @ 20140148 (16 bytes)

/* itron_set_flg on the SDHI event flag 0x20808B74 [fact] */

void sdhi_flag_set(undefined4 param_1)

{
  itron_set_flg(DAT_20808b74,param_1);
  return;
}


// ===== sdhi_flag_wait @ 20140158 (84 bytes)

/* (pattern, ms): itron_twai_flg on 0x20808B74 for ms/10 ticks, then clears the pattern [fact] */

void * sdhi_flag_wait(uint param_1,int param_2)

{
  void *itron_twai_flg_ret;
  uint uStack_14;
  
  itron_twai_flg_ret = itron_twai_flg(DAT_20808b74,param_1,0,&uStack_14,param_2 / 10);
  itron_clr_flg(DAT_20808b74,~param_1);
  return itron_twai_flg_ret;
}


// ===== sdhi_card_absent @ 201401ac (48 bytes)

/* Samples sd_card_detect (P11_4 SD_CD) 32 times; true when any sample is high [fact] */

bool sdhi_card_absent(void)

{
  uint uVar1;
  uint sd_card_detect_ret;
  uint i;
  
  i = 0;
  uVar1 = 0;
  do {
    sd_card_detect_ret = sd_card_detect();
    i = i + 1;
    uVar1 = sd_card_detect_ret | uVar1 << 1;
  } while (i < 0x20);
  return uVar1 != 0;
}


// ===== sdhi_write_protected @ 201401dc (44 bytes)

/* SD_INFO1 bit 7 (WP) clear [fact for the register]; -7 = write-protected in 0x2014040C [inference]
    */

bool sdhi_write_protected(void)

{
  ushort sdhi_sd_info1_0;
  
                    /* SD card interrupt flag 1_0 [sfr] */
  sdhi_sd_info1_0 = SDHI_SD_INFO1_0;
  return (sdhi_sd_info1_0 & 0x80) == 0;
}


// ===== sdhi_read_block @ 20140210 (136 bytes)

/* Reads one 512-byte block through a 32-byte aligned bounce buffer 0x2091CEC0 (cache maintenance
   around the transfer), waits for access end [fact] */

undefined4 sdhi_read_block(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  bool bVar4;
  
                    /* Swap control_0 [sfr] */
  SDHI_EXT_SWAP_0 = 0x100;
  puVar3 = param_1;
  if (((uint)param_1 & 0x1f) != 0) {
    puVar3 = &DAT_2091cec0;
  }
  dcache_invalidate_range(puVar3,0x200);
                    /* DMAC channel 0 for one 512-byte block [doc] */
  sdhi_dma_read_start(puVar3,&SDHI_SD_CMD_0);
                    /* itron_twai_flg on 0x20808B74 for ms/10 ticks [doc] */
  iVar1 = sdhi_flag_wait(4,500);
                    /* Polls DMAC channel 0 CHSTAT until idle [doc] */
  sdhi_dma_read_wait();
  dcache_invalidate_range(puVar3,0x200);
  if (iVar1 == 0) {
    if (((uint)param_1 & 0x1f) != 0) {
      iVar1 = 0x1ff;
      do {
        bVar4 = iVar1 != 0;
        iVar1 = iVar1 + -1;
        *param_1 = *puVar3;
        param_1 = param_1 + 1;
        puVar3 = puVar3 + 1;
      } while (bVar4);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff1;
  }
  return uVar2;
}


// ===== sdhi_write_block @ 20140298 (116 bytes)

/* Writes one 512-byte block through the bounce buffer (dcache_clean_range first), -16 on timeout
   [fact] */

undefined4 sdhi_write_block(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
                    /* Swap control_0 [sfr] */
  SDHI_EXT_SWAP_0 = 0x100;
  if (((uint)param_1 & 0x1f) != 0) {
    iVar2 = 0x1ff;
    puVar1 = &DAT_2091cec0;
    do {
      bVar4 = iVar2 != 0;
      iVar2 = iVar2 + -1;
      *puVar1 = *param_1;
      param_1 = param_1 + 1;
      puVar1 = puVar1 + 1;
    } while (bVar4);
    param_1 = &DAT_2091cec0;
  }
  dcache_clean_range(param_1,0x200);
                    /* DMAC channel 1 for one 512-byte block [doc] */
  sdhi_dma_write_start(&SDHI_SD_CMD_0,param_1);
                    /* itron_twai_flg on 0x20808B74 for ms/10 ticks [doc] */
  iVar2 = sdhi_flag_wait(4,500);
                    /* Polls DMAC channel 1 CHSTAT until idle [doc] */
  sdhi_dma_write_wait();
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = 0xfffffff0;
  }
  return uVar3;
}


// ===== sdhi_flag_set_4 @ 2014030c (20 bytes)

/* Sets event bit 4, the bit the sector transfers wait for (sdhi_flag_wait(4, 500)) [fact] */

void sdhi_flag_set_4(void)

{
                    /* itron_set_flg on the SDHI event flag 0x20808B74 [doc] */
  sdhi_flag_set(4);
  return;
}


// ===== sdhi_check_card @ 20140320 (20 bytes)

/* -6 when sdhi_card_absent, else 0 [fact] */

undefined4 sdhi_check_card(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sdhi_card_absent();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xfffffffa;
  }
  return uVar2;
}


// ===== sdhi_wait_idle @ 20140334 (164 bytes)

/* Polls SD_INFO2 until not CBSY (bit 14) and SCLKDIVEN (bit 13); -9 on an error bit, card check, -1
   after 0x900000 tries [fact] */

int sdhi_wait_idle(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint i;
  ushort sdhi_sd_info2_0;
  
  i = 0;
                    /* SD card interrupt flag 2_0 [sfr] */
  while ((sdhi_sd_info2_0 = SDHI_SD_INFO2_0, (sdhi_sd_info2_0 & 0x4000) != 0 ||
         ((sdhi_sd_info2_0 & 0x2000) == 0))) {
    if ((sdhi_sd_info2_0 & 0x807f) != 0) {
      return -9;
    }
    iVar2 = sdhi_check_card();
    if (iVar2 != 0) {
      return iVar2;
    }
    i = i + 1;
    if (0x8fffff < i) {
      return -1;
    }
  }
  if (0x8fffff < i) {
    return -1;
  }
  if (param_1 != -1) {
    if (param_1 == 0) {
      uVar1 = 0x140;
      goto LAB_201403cc;
    }
    if (param_1 != 1) {
      if (param_1 != 2) {
        return -8;
      }
      uVar1 = 0x100;
      goto LAB_201403cc;
    }
  }
  uVar1 = 0x101;
LAB_201403cc:
                    /* SD clock control_0 [sfr] */
  SDHI_SD_CLK_CTRL_0 = uVar1;
  return 0;
}


// ===== sdhi_clock_set_0x200 @ 201403d8 (16 bytes)

/* SD_CLK_CTRL = 0x200 [fact] */

void sdhi_clock_set_0x200(void)

{
                    /* SD clock control_0 [sfr] */
  SDHI_SD_CLK_CTRL_0 = 0x200;
  return;
}


// ===== sdhi_set_block_size @ 201403e8 (12 bytes)

/* SD_SIZE = n [fact] */

void sdhi_set_block_size(undefined2 param_1)

{
                    /* Transfer data length_0 [sfr] */
  SDHI_SD_SIZE_0 = param_1;
  return;
}


// ===== sdhi_set_sector_count @ 201403f4 (12 bytes)

/* SD_SECCNT = n [fact] */

void sdhi_set_sector_count(undefined2 param_1)

{
                    /* Block count_0 [sfr] */
  SDHI_SD_SECCNT_0 = param_1;
  return;
}


// ===== sdhi_set_stop @ 20140400 (12 bytes)

/* SD_STOP = value (0x100 = auto CMD12 for multi-block) [fact for the register] */

void sdhi_set_stop(undefined2 param_1)

{
                    /* Data stop_0 [sfr] */
  SDHI_SD_STOP_0 = param_1;
  return;
}


// ===== sdhi_check_wp @ 2014040c (20 bytes)

/* -7 when sdhi_write_protected (the sd_write_sectors error) [fact] */

undefined4 sdhi_check_wp(void)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* SD_INFO1 bit 7 [doc] */
  iVar1 = sdhi_write_protected();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xfffffff9;
  }
  return uVar2;
}


// ===== sdhi_op4 @ 20140420 (8 bytes)

/* slot 4 of the SDHI operation table 0x20420564: returns -9 [fact] (T24 round 4) */

undefined4 sdhi_op4(void)

{
  return 0xfffffff7;
}


// ===== sdhi_op5 @ 20140428 (8 bytes)

/* slot 5 of the SDHI operation table: returns -10 [fact] (T24 round 4) */

undefined4 sdhi_op5(void)

{
  return 0xfffffff6;
}


// ===== sdhi_op6 @ 20140430 (8 bytes)

/* slot 6 of the SDHI operation table: returns 4 [fact] (T24 round 4) */

undefined4 sdhi_op6(void)

{
  return 4;
}


// ===== sdhi_op7 @ 20140438 (8 bytes)

/* slot 7 of the SDHI operation table: returns 5 [fact] (T24 round 4) */

undefined4 sdhi_op7(void)

{
  return 5;
}


// ===== sdhi_soft_reset @ 20140440 (28 bytes)

/* SOFT_RST 0 then 1 [fact] */

undefined4 sdhi_soft_reset(void)

{
                    /* Software reset_0 [sfr] */
  SDHI_SOFT_RST_0 = 0;
  SDHI_SOFT_RST_0 = 1;
  return 0;
}


// ===== sdhi_power_on @ 2014045c (20 bytes)

/* sd_power(1) [fact] */

undefined4 sdhi_power_on(void)

{
  sd_power(1);
  return 0;
}


// ===== sdhi_set_bus_width @ 20140474 (24 bytes)

/* SD_OPTION = 0x40EE for 4-bit (mode 2), 0xC0EE for 1-bit (WIDTH bit 15) [fact for the register
   values] */

void sdhi_set_bus_width(int param_1)

{
  undefined2 uVar1;
  
  if (param_1 == 2) {
    uVar1 = 0x40ee;
  }
  else {
    uVar1 = 0xc0ee;
  }
                    /* SD card access control option_0 [sfr] */
  SDHI_SD_OPTION_0 = uVar1;
  return;
}


// ===== sdhi_op12 @ 2014048c (4 bytes)

/* slot 12 of the SDHI operation table: empty [fact] (T24 round 4) */

void sdhi_op12(void)

{
  return;
}


// ===== sdhi_op13 @ 20140490 (4 bytes)

/* slot 13 of the SDHI operation table: empty [fact] (T24 round 4) */

void sdhi_op13(void)

{
  return;
}


// ===== sdhi_op14 @ 20140494 (4 bytes)

/* slot 14 of the SDHI operation table: empty [fact] (T24 round 4) */

void sdhi_op14(void)

{
  return;
}


// ===== sdhi_op15 @ 20140498 (4 bytes)

/* slot 15 of the SDHI operation table: empty [fact] (T24 round 4) */

void sdhi_op15(void)

{
  return;
}


// ===== sdhi_op16 @ 2014049c (8 bytes)

/* slot 16 of the SDHI operation table: returns -9 [fact] (T24 round 4) */

undefined4 sdhi_op16(void)

{
  return 0xfffffff7;
}


// ===== sdhi_wait_info @ 201404a4 (148 bytes)

/* (1 response end, 2 access end, 3 buffer read ready, 4 buffer write ready): polls SD_INFO1 /
   SD_INFO2 for the bit [fact for the masks] */

int sdhi_wait_info(int param_1)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  uint i;
  ushort sdhi_sd_info2_0;
  
  puVar2 = &SDHI_SD_INFO1_0;
  if (param_1 == 1) {
    uVar3 = 1;
  }
  else if (param_1 == 2) {
    uVar3 = 4;
  }
  else {
    puVar2 = &SDHI_SD_INFO2_0;
    if (param_1 == 3) {
      uVar3 = 0x200;
    }
    else {
      if (param_1 != 4) {
        return -2;
      }
      uVar3 = 0x100;
    }
  }
  i = 0;
  do {
    if ((uVar3 & ~*puVar2) == 0) {
      *puVar2 = ~uVar3;
      return 0;
    }
    sdhi_sd_info2_0 = SDHI_SD_INFO2_0;
    if ((sdhi_sd_info2_0 & 0x48) != 0) {
      return -1;
    }
    iVar1 = sdhi_check_card();
    if (iVar1 != 0) {
      return iVar1;
    }
    i = i + 1;
  } while (i < 0x900000);
  return -1;
}


// ===== sdhi_send_cmd @ 20140538 (136 bytes)

/* Clears SD_INFO1/2, writes SD_ARG1/ARG0 and the command code (table 0x204205FC, CMD7 0x307/0x507)
   to SD_CMD [fact] */

undefined4 sdhi_send_cmd(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
                    /* SD card interrupt flag 1_0 [sfr] */
  uVar1 = SDHI_SD_INFO1_0;
  SDHI_SD_INFO1_0 = uVar1 & 0xfff8;
                    /* SD card interrupt flag 2_0 [sfr] */
  uVar1 = SDHI_SD_INFO2_0;
  SDHI_SD_INFO2_0 = uVar1 & 0x800;
                    /* SD command argument 1_0 [sfr] */
  SDHI_SD_ARG1_0 = (short)((uint)param_3 >> 0x10);
                    /* SD command argument 0_0 [sfr] */
  SDHI_SD_ARG0_0 = (short)param_3;
  uVar1 = SDHI_SD_INFO2_0;
  if ((uVar1 & 0x4000) == 0) {
    if (param_2 == 0) {
      if (param_1 == 7) {
        if (param_3 == 0) {
          uVar2 = 0x307;
        }
        else {
          uVar2 = 0x507;
        }
      }
      else {
        uVar2 = *(undefined2 *)(&UNK_204205fc + param_1 * 2);
      }
    }
    else {
      uVar2 = *(undefined2 *)(&DAT_2042067c + param_1 * 2);
    }
                    /* Command type_0 [sfr] */
    SDHI_SD_CMD_0 = uVar2;
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffff7;
  }
  return uVar3;
}


// ===== sdhi_cmd @ 201405e4 (52 bytes)

/* sdhi_send_cmd, waits for response end; returns the SD_INFO2 error bits (& 0x807F) or -1 [fact] */

uint sdhi_cmd(void)

{
  int iVar1;
  uint uVar2;
  ushort sdhi_sd_info2_0;
  
  sdhi_send_cmd();
                    /* polls SD_INFO1 / SD_INFO2 for the bit [doc] */
  iVar1 = sdhi_wait_info(1);
  if (iVar1 == 0) {
    sdhi_sd_info2_0 = SDHI_SD_INFO2_0;
                    /* SD card interrupt flag 2_0 [sfr] */
    uVar2 = sdhi_sd_info2_0 & 0xffff807f;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== sdhi_read_response @ 201405f4 (192 bytes)

/* Copies the response registers SD_RSP07..RSP00 into ctx +0x2B0 (long R2 for CMD2/9/10, else 32
   bits) [fact] */

void sdhi_read_response(int param_1,int param_2)

{
  undefined2 uVar1;
  int *piVar2;
  ushort sdhi_sd_rsp01_0;
  
  piVar2 = (int *)(param_2 + 0x2b0);
  if ((param_1 != 1 && param_1 != 6) && (param_1 != 7 && param_1 != 3)) {
                    /* SD card response 07_0 [sfr] */
    uVar1 = SDHI_SD_RSP07_0;
    *(char *)piVar2 = (char)uVar1;
                    /* SD card response 06_0 [sfr] */
    uVar1 = SDHI_SD_RSP06_0;
    *(char *)(param_2 + 0x2b1) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b2) = (char)uVar1;
                    /* SD card response 05_0 [sfr] */
    uVar1 = SDHI_SD_RSP05_0;
    *(char *)(param_2 + 0x2b3) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b4) = (char)uVar1;
                    /* SD card response 04_0 [sfr] */
    uVar1 = SDHI_SD_RSP04_0;
    *(char *)(param_2 + 0x2b5) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b6) = (char)uVar1;
                    /* SD card response 03_0 [sfr] */
    uVar1 = SDHI_SD_RSP03_0;
    *(char *)(param_2 + 0x2b7) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b8) = (char)uVar1;
                    /* SD card response 02_0 [sfr] */
    uVar1 = SDHI_SD_RSP02_0;
    *(char *)(param_2 + 0x2b9) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2ba) = (char)uVar1;
                    /* SD card response 01_0 [sfr] */
    uVar1 = SDHI_SD_RSP01_0;
    *(char *)(param_2 + 699) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 700) = (char)uVar1;
                    /* SD card response 00_0 [sfr] */
    uVar1 = SDHI_SD_RSP00_0;
    *(char *)(param_2 + 0x2bd) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2be) = (char)uVar1;
    return;
  }
  *piVar2 = 0;
  sdhi_sd_rsp01_0 = SDHI_SD_RSP01_0;
  *piVar2 = (uint)sdhi_sd_rsp01_0 << 0x10;
  uVar1 = SDHI_SD_RSP00_0;
  *piVar2 = CONCAT22(sdhi_sd_rsp01_0,uVar1);
  return;
}


// ===== sd_cmd16_set_blocklen @ 201406b4 (152 bytes)

/* Sets SD_SIZE/SECCNT/STOP and sends CMD16 (SET_BLOCKLEN), 3 tries, -9 on failure [inference from
   the command index] */

undefined4 sd_cmd16_set_blocklen(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int i;
  
  sdhi_set_block_size();
  sdhi_set_sector_count(param_2);
  if (param_2 == 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x100;
  }
  sdhi_set_stop(uVar1);
  i = 0;
  do {
                    /* sdhi_send_cmd, waits for response end [doc] */
    iVar2 = sdhi_cmd(0x10,0,param_1,param_3);
    if (iVar2 == 0) {
      if (2 < i) {
        return 0xfffffff7;
      }
      sdhi_read_response(1,param_3);
      uVar1 = 0;
      if ((*(uint *)(param_3 + 0x2b0) &
          *(uint *)(&DAT_2042023c + (uint)*(ushort *)(param_3 + 0x2c6) * 4)) != 0) {
        uVar1 = 0xffffffe9;
      }
      return uVar1;
    }
    i = i + 1;
  } while (i < 3);
  return 0xfffffff7;
}


// ===== sd_cmd12_stop @ 2014074c (112 bytes)

/* Sends CMD12 (STOP_TRANSMISSION), 3 tries, checks the R1 error bits with mask table 0x20420234
   [inference from the command index] */

undefined4 sd_cmd12_stop(int param_1)

{
  int iVar1;
  int i;
  
  i = 0;
                    /* sdhi_send_cmd, waits for response end [doc] */
  while (iVar1 = sdhi_cmd(0xc,0,0,param_1), iVar1 != 0) {
    i = i + 1;
    if (2 < i) {
      return 0xfffffff7;
    }
  }
  if (2 < i) {
    return 0xfffffff7;
  }
  sdhi_read_response(1,param_1);
  if ((*(uint *)(param_1 + 0x2b0) &
      *(uint *)(&DAT_20420234 + (uint)*(ushort *)(param_1 + 0x2c6) * 4)) != 0) {
    return 0xfffffff7;
  }
  return 0;
}


// ===== sdhi_error_reset @ 201407bc (36 bytes)

/* Soft reset of SDHI0 that keeps SD_CLK_CTRL and the option register (sdhi_soft_reset(2)) [fact] */

void sdhi_error_reset(undefined4 param_1,undefined4 param_2)

{
  int extraout_r2;
  undefined2 extraout_r3;
  undefined2 extraout_r12;
  undefined2 sdhi_sd_clk_ctrl_0;
  
                    /* SD clock control_0 [sfr] */
  sdhi_sd_clk_ctrl_0 = SDHI_SD_CLK_CTRL_0;
                    /* SOFT_RST 0 then 1 [doc] */
  sdhi_soft_reset(2,param_2,&SDHI_SD_CMD_0,sdhi_sd_clk_ctrl_0);
  *(undefined2 *)(extraout_r2 + 0x24) = extraout_r3;
  *(undefined2 *)(extraout_r2 + 0x28) = extraout_r12;
  return;
}


// ===== sdhi_read_sectors_cmd @ 201407e0 (316 bytes)

/* (addr, buf, n, ctx): CMD16 block length 512, then CMD17 (one block) or CMD18 (several, with
   stop), sdhi_read_block per block and access-end wait [fact] */

int sdhi_read_sectors_cmd(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
                    /* Sets SD_SIZE/SECCNT/STOP and sends CMD16 [doc, inference] */
  iVar2 = sd_cmd16_set_blocklen(0x200,param_3,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar1 = SDHI_CC_EXT_MODE_0;
  SDHI_CC_EXT_MODE_0 = uVar1 | 2;
  iVar2 = 0;
  if (param_3 == 1) {
    do {
                    /* sdhi_send_cmd, waits for response end [doc] */
      iVar3 = sdhi_cmd(0x11,0,param_1,param_4);
      if (iVar3 == 0) {
LAB_20140880:
        if (2 < iVar2) {
          return -9;
        }
        sdhi_read_response(1,param_4);
        if ((*(uint *)(param_4 + 0x2b0) &
            *(uint *)(&DAT_20420244 + (uint)*(ushort *)(param_4 + 0x2c6) * 4)) == 0) {
          uVar4 = 0;
          if (param_3 != 0) {
            do {
              iVar2 = sdhi_read_block(param_2);
              if (iVar2 != 0) {
                    /* DMA mode enable_0 [sfr] */
                uVar1 = SDHI_CC_EXT_MODE_0;
                SDHI_CC_EXT_MODE_0 = uVar1 & 0xfffd;
                return iVar2;
              }
              param_2 = param_2 + 0x200;
              uVar4 = uVar4 + 1 & 0xffff;
            } while (uVar4 < param_3);
          }
          uVar1 = SDHI_CC_EXT_MODE_0;
          SDHI_CC_EXT_MODE_0 = uVar1 & 0xfffd;
                    /* polls SD_INFO1 / SD_INFO2 for the bit [doc] */
          iVar3 = sdhi_wait_info(2);
          iVar2 = 0;
          if (iVar3 != 0) {
            iVar2 = -1;
          }
          return iVar2;
        }
        return -0x16;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  else {
    do {
      iVar3 = sdhi_cmd(0x12,0,param_1,param_4);
      if (iVar3 == 0) goto LAB_20140880;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  return -9;
}


// ===== sdhi_read_op @ 2014091c (124 bytes)

/* (addr, buf, n, ctx): read op of the SDHI op table: two blocks are read one at a time (block or
   byte address by card type +0x2C0), else sdhi_read_sectors_cmd; on error sdhi_error_reset [fact]
    */

int sdhi_read_op(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_3 == 2) {
    iVar1 = sdhi_read_sectors_cmd(param_1,param_2,1);
    if (iVar1 != 0) {
      sdhi_error_reset();
      return iVar1;
    }
    if (*(short *)(param_4 + 0x2c0) == 2) {
      param_1 = param_1 + 1;
    }
    else {
      param_1 = param_1 + 0x200;
    }
    iVar1 = sdhi_read_sectors_cmd(param_1,param_2 + 0x200,1,param_4);
  }
  else {
                    /* CMD16 block length 512 [doc] */
    iVar1 = sdhi_read_sectors_cmd();
  }
  if (iVar1 != 0) {
    sdhi_error_reset();
  }
  return iVar1;
}


// ===== sdhi_read_buf_pio @ 20140998 (84 bytes)

/* [fact] len / 4 reads of SD_BUF0 (0xE804E030) stored low byte first, returns 0; slot 23 of the
   SDHI operation table 0x20420564; Ghidra FUN_20140998 (T24 round 7) */

undefined4 sdhi_read_buf_pio(undefined1 *param_1,uint param_2)

{
  int i;
  undefined4 sdhi_sd_buf0_0;
  
  i = 0;
  if (param_2 >> 2 != 0) {
    do {
      sdhi_sd_buf0_0 = SDHI_SD_BUF0_0;
      i = i + 1;
      *param_1 = (char)sdhi_sd_buf0_0;
      param_1[1] = (char)((uint)sdhi_sd_buf0_0 >> 8);
      param_1[2] = (char)((uint)sdhi_sd_buf0_0 >> 0x10);
      param_1[3] = (char)((uint)sdhi_sd_buf0_0 >> 0x18);
      param_1 = param_1 + 4;
    } while (i < (int)(param_2 >> 2));
  }
  return 0;
}


// ===== sdhi_write_sectors_cmd @ 201409ec (316 bytes)

/* (addr, buf, n, ctx): CMD16, then CMD24 (one block) or CMD25 (several), sdhi_write_block per block
   and access-end wait [fact] */

int sdhi_write_sectors_cmd(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
                    /* Sets SD_SIZE/SECCNT/STOP and sends CMD16 [doc, inference] */
  iVar2 = sd_cmd16_set_blocklen(0x200,param_3,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar1 = SDHI_CC_EXT_MODE_0;
  SDHI_CC_EXT_MODE_0 = uVar1 | 2;
  iVar2 = 0;
  if (param_3 == 1) {
    do {
                    /* sdhi_send_cmd, waits for response end [doc] */
      iVar3 = sdhi_cmd(0x18,0,param_1,param_4);
      if (iVar3 == 0) {
LAB_20140a8c:
        if (2 < iVar2) {
          return -9;
        }
        sdhi_read_response(1,param_4);
        if ((*(uint *)(param_4 + 0x2b0) &
            *(uint *)(&DAT_2042024c + (uint)*(ushort *)(param_4 + 0x2c6) * 4)) == 0) {
          uVar4 = 0;
          if (param_3 != 0) {
            do {
                    /* Writes one 512-byte block through the bounce buffer [doc] */
              iVar2 = sdhi_write_block(param_2);
              if (iVar2 != 0) {
                    /* DMA mode enable_0 [sfr] */
                uVar1 = SDHI_CC_EXT_MODE_0;
                SDHI_CC_EXT_MODE_0 = uVar1 & 0xfffd;
                return iVar2;
              }
              param_2 = param_2 + 0x200;
              uVar4 = uVar4 + 1 & 0xffff;
            } while (uVar4 < param_3);
          }
          uVar1 = SDHI_CC_EXT_MODE_0;
          SDHI_CC_EXT_MODE_0 = uVar1 & 0xfffd;
                    /* polls SD_INFO1 / SD_INFO2 for the bit [doc] */
          iVar3 = sdhi_wait_info(2);
          iVar2 = 0;
          if (iVar3 != 0) {
            iVar2 = -1;
          }
          return iVar2;
        }
        return -0x15;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  else {
    do {
      iVar3 = sdhi_cmd(0x19,0,param_1,param_4);
      if (iVar3 == 0) goto LAB_20140a8c;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  return -9;
}


// ===== sdhi_write_op @ 20140b50 (24 bytes)

/* sdhi_write_sectors_cmd, on error sdhi_error_reset [fact] */

int sdhi_write_op(void)

{
  int iVar1;
  
  iVar1 = sdhi_write_sectors_cmd();
  if (iVar1 != 0) {
    sdhi_error_reset();
  }
  return iVar1;
}


// ===== sdhi_open @ 20140b68 (52 bytes)

/* SDHI0 open: clock on, soft reset, sdhi0_irq_enable, sdhi_init, registers the two extra handlers
   0x20808B78 / 0x20808B84 with gic_def_inh [fact] */

void sdhi_open(void)

{
  int iVar1;
  uint sdhi_init_ret;
  
  sdhi0_clock_on();
                    /* SOFT_RST 0 then 1 [doc] */
  sdhi_soft_reset(2);
                    /* Registers the SDHI0 handler for GIC id 303 [doc] */
  iVar1 = sdhi0_irq_enable();
  if ((iVar1 == 0) && (sdhi_init_ret = sdhi_init(), sdhi_init_ret == 0)) {
    sdhi_dma_open();
    return;
  }
  return;
}


// ===== sdhi0_buf_isr @ 20140b9c (76 bytes)

/* SDHI0 SDHI0_0 interrupt (GIC 303, peripherals.md): SD_INFO2 BRE (bit 8) -> sdhi_flag_set(1), BWE
   (bit 9) -> sdhi_flag_set(2), clearing the bit [fact] */

void sdhi0_buf_isr(void)

{
  ushort sdhi_sd_info2_0;
  
                    /* SD card interrupt flag 2_0 [sfr] */
  sdhi_sd_info2_0 = SDHI_SD_INFO2_0;
  if ((sdhi_sd_info2_0 & 0x100) != 0) {
    SDHI_SD_INFO2_0 = 0xfeff;
                    /* itron_set_flg on the SDHI event flag 0x20808B74 [doc] */
    sdhi_flag_set(1);
    return;
  }
  if ((sdhi_sd_info2_0 & 0x200) != 0) {
    SDHI_SD_INFO2_0 = 0xfdff;
    sdhi_flag_set(2);
    return;
  }
  return;
}


// ===== file_buf_sync @ 20140be8 (940 bytes)

/* (file): writes the file's dirty sector buffer back (fs_dev_op2) and reads the sector of the new
   position (fs_dev_op1), following the cluster chain (fat_next_sector, fat_clust2sect /
   fat_sect2clust); used by fs_fopen_work, file_write_core, file_write_locked and fs_fseek_work
   [fact for the calls] */

int file_buf_sync(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_r1;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int local_40;
  int local_3c;
  int local_38;
  int *piStack_34;
  uint uStack_30;
  int iStack_2c;
  undefined4 local_28;
  
  bVar1 = false;
  if (param_3 == 0) {
    if ((int)param_2 < 0) {
      return -0xd;
    }
    uVar6 = param_2;
    if ((uint)param_1[0xb] < param_2) {
      return -0xd;
    }
  }
  else {
    if (param_3 == 1) {
      if ((int)param_2 < 1) {
        if (((int)param_2 < 0) && ((uint)param_1[10] < -param_2)) {
          return -0xd;
        }
      }
      else if ((uint)(param_1[0xb] - param_1[10]) < param_2) {
        return -0xd;
      }
      iVar2 = param_1[10];
    }
    else {
      if (param_3 != 2) {
        return -0xe;
      }
      if (0 < (int)param_2) {
        return -0xd;
      }
      if (((int)param_2 < 0) && ((uint)param_1[0xb] < -param_2)) {
        return -0xd;
      }
      iVar2 = param_1[0xb];
    }
    uVar6 = iVar2 + param_2;
  }
  if (*(char *)((int)param_1 + 0x442) == '\0') {
    return -6;
  }
  if (param_1[10] == uVar6) {
    return 0;
  }
  iVar2 = *param_1;
  uVar8 = param_1[0x8e];
  piStack_34 = param_1;
  uStack_30 = param_2;
  iStack_2c = param_3;
  local_28 = param_4;
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  uVar3 = __aeabi_uidivmod(uVar8,*(undefined4 *)(iVar2 + 0x6c));
  if (uVar8 <= (uint)param_1[5]) {
    iVar2 = fat_sector_is_cluster_first(iVar2,param_1[8]);
    if (iVar2 == 0) {
      param_1[8] = (param_1[8] - uVar3) + 1;
    }
    if (param_1[2] != 0) {
      iVar2 = fs_dev_op2(*param_1,param_1[8],param_1[1],uVar3 & 0xffff);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_1[2] = 0;
      *(undefined1 *)(param_1 + 0x113) = 1;
    }
    if ((uint)param_1[10] < (uint)param_1[0xb]) {
      iVar2 = fat_next_sector(*param_1,(uVar3 - 1) + param_1[8],&local_40,local_28);
      if (iVar2 != 0) {
        return iVar2;
      }
      if ((local_40 != 0) &&
         (iVar2 = fs_dev_op1(*param_1,local_40,param_1[1],uVar3 & 0xffff), iVar2 != 0)) {
        return iVar2;
      }
      param_1[8] = local_40;
      param_1[5] = 0;
    }
  }
  local_38 = *param_1;
  local_3c = *(int *)(local_38 + 0x6c);
  iVar4 = __aeabi_uidivmod(uVar6,local_3c);
  uVar8 = param_1[10];
  iVar2 = __aeabi_uidivmod(uVar8,local_3c);
  iVar4 = iVar4 - iVar2;
  if ((iVar4 == 0) && (uVar8 != uVar6)) goto LAB_20140f18;
  local_3c = param_1[8];
  if (param_1[2] != 0) {
    iVar2 = fs_dev_op2(local_38,local_3c,param_1[1],uVar3 & 0xffff);
    if (iVar2 != 0) {
      return iVar2;
    }
    param_1[2] = 0;
    *(undefined1 *)(param_1 + 0x113) = 1;
  }
  if (iVar4 < 1) {
    iVar2 = *param_1;
    iVar4 = __aeabi_uidivmod(uVar6,*(undefined4 *)(iVar2 + 0x6c));
    iVar2 = fat_clust2sect(iVar2,param_1[7]);
    param_1[8] = iVar2;
  }
  else {
    iVar2 = __aeabi_uidivmod(param_1[5],*(undefined4 *)(*param_1 + 0x6c));
    iVar2 = iVar2 + param_1[8];
  }
  iVar7 = 0;
  if (0 < iVar4) {
    do {
      iVar2 = fat_next_sector(*param_1,iVar2,&local_40,local_28);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (local_40 == 0) {
        param_1[10] = param_1[0xb];
        param_1[5] = param_1[0x8e];
        if (param_1[0xb] != uVar6) {
          return -0xe;
        }
        iVar2 = param_1[8];
        bVar1 = false;
        break;
      }
      iVar7 = iVar7 + 1;
      bVar1 = true;
      param_1[8] = local_40;
      iVar2 = local_40;
    } while (iVar7 < iVar4);
  }
  if ((int)uVar3 < 2) {
LAB_20140ef0:
    iVar4 = fs_dev_op1(*param_1,iVar2,param_1[1],uVar3 & 0xffff);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  else {
                    /* Cluster number of a data sector [doc] */
    uVar5 = fat_sect2clust(*param_1,iVar2);
    iVar2 = fat_clust2sect(*param_1,uVar5);
    iVar4 = fat_sect2clust(*param_1,local_3c);
    iVar7 = fat_sect2clust(*param_1,iVar2);
    if (iVar4 != iVar7) goto LAB_20140ef0;
  }
  param_1[8] = iVar2;
LAB_20140f18:
  param_1[10] = uVar6;
  iVar2 = param_1[0x8e];
  __aeabi_uidivmod(uVar6);
  param_1[5] = extraout_r1;
  if ((((extraout_r1 == 0) && (param_1[0xb] == uVar6)) && (uVar6 != 0)) && (!bVar1)) {
    param_1[5] = iVar2;
  }
  return 0;
}


// ===== file_open_core @ 20140f94 (2180 bytes)

/* The open/create body behind fs_fopen: path lookup, directory entry creation, truncation for write
   modes (2180 bytes) [inference: only caller fs_fopen_locked] */

void file_open_core(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int local_6c;
  undefined1 auStack_68 [11];
  byte local_5d;
  undefined1 auStack_52 [2];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38 [2];
  char *local_30;
  char *pcStack_2c;
  char *pcStack_28;
  
  piVar7 = DAT_20808b90;
  bVar2 = false;
  local_3c = 0;
  local_38[0] = 0;
  iVar9 = 0;
  local_40 = 0;
  piVar10 = (int *)0x0;
  local_44 = 0;
  local_48 = DAT_20808ba0;
  local_30 = param_1;
  pcStack_2c = param_2;
  pcStack_28 = param_3;
  iVar5 = fs_sem1_wait();
  if (iVar5 != 0) {
    iVar5 = -0x28;
    piVar7 = (int *)0x0;
    goto LAB_20141070;
  }
  iVar5 = 0;
  if (0 < DAT_20808b94) {
    do {
      piVar11 = piVar7 + 0x100;
      if (*(char *)((int)piVar7 + 0x442) == '\0' && !bVar2) {
        bVar2 = true;
        piVar10 = piVar7;
      }
      else {
        iVar6 = fs_stricmp_sjis_fold(piVar7 + 0x8f,local_30);
        if ((iVar6 == 0) &&
           ((*param_2 != 'r' || ((param_2[1] == '+' && (*(char *)((int)piVar11 + 0x42) != '\x01'))))
           )) {
          fs_sem1_signal();
          piVar7 = (int *)0x0;
          iVar5 = -7;
          goto LAB_20141070;
        }
      }
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 0x114;
    } while (iVar5 < DAT_20808b94);
    if (bVar2) {
      if (piVar10 == (int *)0x0) {
        fs_sem1_signal();
        piVar7 = (int *)0x0;
        iVar5 = -0xd;
        goto LAB_20141070;
      }
      uVar3 = fs_toupper((int)*local_30);
                    /* walks the drive list 0x20808BA0 for +0x11 == letter [doc] */
      iVar5 = fs_find_drive(uVar3,&local_48);
      if (iVar5 != 0) {
        fs_sem1_signal();
        piVar7 = (int *)0x0;
        goto LAB_20141070;
      }
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
      fs_memset(piVar10,0,0x450,*(undefined4 *)(local_48 + 0x6c));
      *(undefined1 *)((int)piVar10 + 0x442) = 0xff;
      fs_sem1_signal();
      iVar5 = fs_drive_check_mounted(local_48);
      if ((iVar5 != 0) ||
         (((*param_2 != 'r' || (param_2[1] == '+')) &&
          (iVar5 = fs_drive_check_writable(local_48), iVar5 != 0)))) goto LAB_20141154;
      iVar5 = 0;
      fs_memset(auStack_68,0,0x20,*(undefined4 *)(local_48 + 0x6c));
      *piVar10 = local_48;
      pcVar8 = local_30 + 2;
      local_6c = *(int *)(local_48 + 0x34);
      if (*(char *)(local_48 + 0x10) == ' ') {
LAB_201412a0:
        cVar1 = *pcVar8;
        while (cVar1 != '\0') {
          pcVar8 = (char *)path_next_component(pcVar8,param_3);
          if ((pcVar8 == (char *)0x0) || (*param_3 == '\0')) goto LAB_20141208;
                    /* Searches a directory cluster chain for a name [doc, inference] */
          iVar5 = subdir_find(local_48,local_6c,param_3,auStack_68,0,0,&local_40,&local_44,param_3);
          if (*pcVar8 == '\0') {
            if ((iVar5 == 0) && (iVar9 = fs_attr_check((int)(char)local_5d,0x10), iVar9 == 0)) {
              cVar1 = *param_2;
              goto joined_r0x2014124c;
            }
            if ((*param_2 == 'r') && (iVar5 != 0)) goto LAB_2014125c;
          }
          else {
            if (iVar5 != 0) goto LAB_2014146c;
            iVar9 = fs_attr_check((int)(char)local_5d,0x10);
            if (iVar9 != 0) goto LAB_201411f8;
          }
          iVar6 = dirent_get_cluster(auStack_68,(int)*(char *)(local_48 + 0x10));
          iVar9 = local_6c;
          local_6c = iVar6;
          cVar1 = *pcVar8;
        }
      }
      else {
                    /* copies the "\\name" component at p [doc] */
        pcVar8 = (char *)path_next_component(pcVar8,param_3);
        if ((pcVar8 == (char *)0x0) || (*param_3 == '\0')) {
LAB_20141208:
          *(undefined1 *)((int)piVar10 + 0x442) = 0;
          piVar7 = (int *)0x0;
          iVar5 = -1;
          goto LAB_20141070;
        }
                    /* Searches the fixed FAT12/16 root directory for a name [doc, inference] */
        iVar5 = root_dir_find(local_48,param_3,auStack_68,0,0,&local_40,param_3);
        if (*pcVar8 == '\0') {
          if ((iVar5 == 0) && (iVar6 = fs_attr_check((int)(char)local_5d,0x10), iVar6 == 0)) {
            cVar1 = *param_2;
joined_r0x2014124c:
            if (cVar1 != 'r') {
              piVar7 = (int *)0x0;
              *(undefined1 *)((int)piVar10 + 0x442) = 0;
              iVar5 = -2;
              goto LAB_20141070;
            }
          }
          else if ((*param_2 != 'r') || (iVar5 == 0)) goto LAB_20141280;
LAB_2014125c:
          piVar7 = (int *)0x0;
          *(undefined1 *)((int)piVar10 + 0x442) = 0;
          iVar5 = -3;
          goto LAB_20141070;
        }
        if ((iVar5 != 0) || (iVar6 = fs_attr_check((int)(char)local_5d,0x10), iVar6 != 0)) {
LAB_201411f8:
          *(undefined1 *)((int)piVar10 + 0x442) = 0;
          iVar5 = -4;
          piVar7 = (int *)0x0;
          goto LAB_20141070;
        }
LAB_20141280:
        if (*pcVar8 != '\0') {
                    /* First cluster of an entry [doc] */
          local_6c = dirent_get_cluster(auStack_68,(int)*(char *)(local_48 + 0x10));
          goto LAB_201412a0;
        }
      }
      cVar1 = *param_2;
      if (cVar1 == 'a') {
        if (iVar5 != 0) {
          fs_memset(auStack_68,0,0x20,*(undefined4 *)(local_48 + 0x6c));
          local_5d = 0x20;
          dirent_set_time(auStack_68,piVar10,7);
          if (iVar9 == 0) {
            iVar5 = root_dir_find(local_48,param_3,auStack_68,1,0,&local_40,param_3);
            iVar6 = fat_clust2sect(local_48,0);
          }
          else {
            iVar5 = subdir_find(local_48,iVar9,param_3,auStack_68,1,0,&local_40,&local_44,param_3);
            iVar6 = local_44;
          }
          piVar10[9] = iVar6;
          if (iVar5 != 0) {
LAB_2014146c:
            *(undefined1 *)((int)piVar10 + 0x442) = 0;
            piVar7 = (int *)0x0;
            goto LAB_20141070;
          }
        }
        if ((local_5d & 1) == 0) {
          *(undefined1 *)((int)piVar10 + 0x442) = 0x20;
          if (param_2[1] == '+') {
            *(undefined1 *)((int)piVar10 + 0x442) = 0x21;
          }
          *(byte *)((int)piVar10 + 0x443) = local_5d;
                    /* 16-bit field read from an on-disk structure [doc] */
          uVar4 = fat_ld_word(auStack_52);
          *(undefined2 *)(piVar10 + 0x8d) = uVar4;
          uVar4 = fat_ld_word(auStack_50);
          *(undefined2 *)((int)piVar10 + 0x236) = uVar4;
                    /* 32-bit field read from an on-disk structure [doc] */
          iVar5 = fat_ld_dword(auStack_4c);
          piVar10[0xb] = iVar5;
          piVar10[0xc] = iVar5;
          iVar5 = dirent_get_cluster(auStack_68,(int)*(char *)(local_48 + 0x10));
          piVar10[7] = iVar5;
          iVar5 = fat_clust2sect(local_48,iVar5);
          piVar10[8] = iVar5;
          piVar10[6] = local_40;
          if (iVar9 == 0) {
            iVar9 = fat_clust2sect(local_48,0);
          }
          else {
            *(undefined1 *)(piVar10 + 0x111) = 1;
            iVar9 = local_44;
          }
          piVar10[9] = iVar9;
LAB_201417fc:
          fs_strncpy(piVar10 + 0x8f,local_30,0x102);
          iVar5 = 0;
          piVar7 = piVar10;
          goto LAB_20141070;
        }
      }
      else if (cVar1 == 'r') {
        if (((local_5d & 1) == 0) || (param_2[1] != '+')) {
          piVar10[6] = local_40;
          if (iVar9 == 0) {
            iVar9 = fat_clust2sect(local_48,0);
          }
          else {
            *(undefined1 *)(piVar10 + 0x111) = 1;
            iVar9 = local_44;
          }
          piVar10[9] = iVar9;
          *(undefined1 *)((int)piVar10 + 0x442) = 1;
          if (param_2[1] == '+') {
            *(undefined1 *)((int)piVar10 + 0x442) = 0x11;
          }
          iVar9 = fat_ld_dword(auStack_4c);
          piVar10[0xb] = iVar9;
          piVar10[0xc] = iVar9;
          iVar9 = dirent_get_cluster(auStack_68,(int)*(char *)(local_48 + 0x10));
          piVar10[7] = iVar9;
          iVar9 = fat_clust2sect(local_48,iVar9);
          piVar10[8] = iVar9;
          *(byte *)((int)piVar10 + 0x443) = local_5d;
          uVar4 = fat_ld_word(auStack_52);
          *(undefined2 *)(piVar10 + 0x8d) = uVar4;
          uVar4 = fat_ld_word(auStack_50);
          *(undefined2 *)((int)piVar10 + 0x236) = uVar4;
          goto LAB_201417fc;
        }
      }
      else if (cVar1 == 'w') {
        if (iVar5 != 0) {
LAB_20141700:
          fs_memset(auStack_68,0,0x20,*(undefined4 *)(local_48 + 0x6c));
          local_5d = 0x20;
          dirent_set_time(auStack_68,piVar10,7);
          if (iVar9 == 0) {
            iVar5 = root_dir_find(local_48,param_3,auStack_68,1,0,&local_40,param_3);
            iVar6 = fat_clust2sect(local_48,0);
          }
          else {
            iVar5 = subdir_find(local_48,iVar9,param_3,auStack_68,1,0,&local_40,&local_44,param_3);
            iVar6 = local_44;
          }
          piVar10[9] = iVar6;
          if (iVar5 != 0) goto LAB_2014146c;
          *(undefined1 *)((int)piVar10 + 0x442) = 0x10;
          if (param_2[1] == '+') {
            *(undefined1 *)((int)piVar10 + 0x442) = 0x11;
          }
          piVar10[6] = local_40;
          *(byte *)((int)piVar10 + 0x443) = local_5d;
          uVar4 = fat_ld_word(auStack_52);
          *(undefined2 *)(piVar10 + 0x8d) = uVar4;
          uVar4 = fat_ld_word(auStack_50);
          *(undefined2 *)((int)piVar10 + 0x236) = uVar4;
          piVar10[7] = 0;
          if (iVar9 != 0) {
            *(undefined1 *)(piVar10 + 0x111) = 1;
          }
          goto LAB_201417fc;
        }
        if ((local_5d & 1) == 0) {
          if (iVar9 == 0) {
            iVar5 = root_dir_find(local_48,param_3,auStack_68,3,0,&local_3c,param_3);
          }
          else {
            iVar5 = subdir_find(local_48,iVar9,param_3,auStack_68,3,0,&local_3c,local_38,param_3);
          }
          if (iVar5 == 0) {
            if (iVar9 == 0) {
              iVar5 = root_dir_find(local_48,param_3,auStack_68,2,0,&local_40,param_3);
            }
            else {
              iVar5 = subdir_find(local_48,iVar9,param_3,auStack_68,2,0,&local_40,&local_44,param_3)
              ;
            }
                    /* fat_chain_free under fs_lock_b [doc] */
            if ((iVar5 == 0) &&
               ((iVar5 = dirent_get_cluster(auStack_68,(int)*(char *)(local_48 + 0x10)), iVar5 == 0
                || (iVar5 = fat_chain_free_locked(local_48,iVar5,param_3), iVar5 == 0))))
            goto LAB_20141700;
          }
LAB_20141154:
          *(undefined1 *)((int)piVar10 + 0x442) = 0;
          piVar7 = (int *)0x0;
          goto LAB_20141070;
        }
      }
      *(undefined1 *)((int)piVar10 + 0x442) = 0;
      iVar5 = -5;
      piVar7 = (int *)0x0;
      goto LAB_20141070;
    }
  }
  fs_sem1_signal();
  piVar7 = (int *)0x0;
  iVar5 = -10;
LAB_20141070:
                    /* last error 0x20808BA4 = err, returns ret [doc] */
  fs_set_error_ret(iVar5,piVar7);
  return;
}


// ===== fs_fopen_locked @ 20141824 (148 bytes)

/* Opens/creates the file (0x20140F94) under the drive lock fs_lock_a; result and per-task error via
   fs_set_error_ret [fact] */

void fs_fopen_locked(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_18;
  
  local_18 = DAT_20808ba0;
  uVar1 = fs_toupper((int)*param_1);
                    /* walks the drive list 0x20808BA0 for +0x11 == letter [doc] */
  iVar2 = fs_find_drive(uVar1,&local_18);
  if (iVar2 != 0) {
                    /* last error 0x20808BA4 = err, returns ret [doc] */
    fs_set_error_ret(iVar2,0);
    return;
  }
                    /* Locks the per-drive semaphore of table 0x2091D4C0 [doc] */
  iVar2 = fs_lock_a(local_18);
  if (iVar2 == 0) {
                    /* The open/create body behind fs_fopen [doc, inference] */
    uVar4 = file_open_core(param_1,param_2,param_3);
                    /* Per-task FS context 0x2091D0BC[tskid] [doc] */
    uVar3 = fs_task_ctx_get();
    fs_unlock_a(local_18);
  }
  else {
    uVar4 = 0;
    uVar3 = 0xffffffdb;
  }
  fs_set_error_ret(uVar3,uVar4);
  return;
}


// ===== fs_fopen_work @ 201418b8 (516 bytes)

/* fs_fopen body with a work buffer: checks the path (fs_path_validate) and mode, finds the drive,
   opens through fs_fopen_locked [fact] */

void fs_fopen_work(char *param_1,char *param_2,int param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 local_20;
  
  local_20 = DAT_20808ba0;
  iVar3 = fs_check_ready();
  if (iVar3 != 0) {
                    /* last error 0x20808BA4 = err, returns ret [doc] */
    fs_set_error_ret(iVar3,0);
    return;
  }
  if (param_1 == (char *)0x0 || param_2 == (char *)0x0) {
    piVar7 = (int *)0x0;
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = fs_path_validate(param_1);
    if (uVar4 == 0) {
      uVar1 = fs_toupper((int)*param_1);
                    /* walks the drive list 0x20808BA0 for +0x11 == letter [doc] */
      uVar4 = fs_find_drive(uVar1,&local_20);
      if (uVar4 == 0) {
        iVar3 = fs_strlen(param_1);
        iVar5 = param_3 + 0x100c;
        fs_strncpy(iVar5,param_1,iVar3 + 1);
        sjis_map_ext_chars(iVar5);
        piVar7 = (int *)fs_fopen_locked(iVar5,param_2,param_3);
                    /* Per-task FS context 0x2091D0BC[tskid] [doc] */
        uVar4 = fs_task_ctx_get();
        if (piVar7 != (int *)0x0) {
                    /* Block from pool 0x20808BC4 [doc] */
          iVar3 = fs_mpf_alloc((uint)*(ushort *)(*piVar7 + 4) * *(int *)(*piVar7 + 0x6c));
          piVar7[1] = iVar3;
          iVar5 = *piVar7;
          piVar7[0x8e] = (uint)*(ushort *)(iVar5 + 4) * *(int *)(iVar5 + 0x6c);
          if (iVar3 == 0) {
            piVar7[1] = (int)(piVar7 + 0xd);
            piVar7[0x8e] = *(int *)(iVar5 + 0x6c);
          }
          if ((*param_2 == 'r' || *param_2 == 'a') && (piVar7[0xb] != 0)) {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
            uVar2 = __aeabi_uidivmod(piVar7[0x8e],*(undefined4 *)(iVar5 + 0x6c));
            uVar6 = fs_dev_op1(iVar5,piVar7[8],piVar7[1],uVar2);
            if (uVar6 != 0) {
              if ((int *)piVar7[1] != piVar7 + 0xd) {
                fs_mpf_free();
              }
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
              fs_memset(piVar7 + 0x8f,0,0x206,*(undefined4 *)(*piVar7 + 0x6c));
              *(undefined1 *)((int)piVar7 + 0x442) = 0;
              piVar7 = (int *)0x0;
              uVar4 = uVar6;
            }
                    /* writes the file's dirty sector buffer back [doc] */
            if (((*param_2 == 'a') && (piVar7 != (int *)0x0)) &&
               (uVar6 = file_buf_sync(piVar7,0,2,param_3), uVar6 != 0)) {
              if ((int *)piVar7[1] != piVar7 + 0xd) {
                fs_mpf_free();
              }
              fs_memset(piVar7 + 0x8f,0,0x206,*(undefined4 *)(*piVar7 + 0x6c));
              *(undefined1 *)((int)piVar7 + 0x442) = 0;
              piVar7 = (int *)0x0;
              uVar4 = uVar6;
            }
          }
        }
        goto LAB_20141914;
      }
    }
    piVar7 = (int *)0x0;
  }
LAB_20141914:
  fs_set_error_ret(uVar4,piVar7);
  return;
}


// ===== fs_fopen @ 20141abc (76 bytes)

uint fs_fopen(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
                    /* itron_tget_mpf from pool 0x20808BC8, 0 on failure [doc] */
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
                    /* fs_fopen body with a work buffer [doc] */
    uVar2 = fs_fopen_work(param_1,param_2,iVar1);
                    /* itron_rel_mpf to pool 0x20808BC8 [doc] */
    fs_work_free(iVar1);
    return uVar2;
  }
                    /* last error 0x20808BA4 = err, returns ret [doc] */
  uVar2 = fs_set_error_ret(0xffffffe1,0);
  return uVar2;
}

