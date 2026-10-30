// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== sdhi_set_stop @ 20140400 (12 bytes)

/* SD_STOP = value (0x100 = auto CMD12 for multi-block) [fact for the register] */

void sdhi_set_stop(undefined2 param_1)

{
  SDHI_SD_STOP_0 = param_1;
  return;
}


// ===== sdhi_check_wp @ 2014040c (20 bytes)

/* -7 when sdhi_write_protected (the sd_write_sectors error) [fact] */

undefined4 sdhi_check_wp(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sdhi_write_protected();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xfffffff9;
  }
  return uVar2;
}


// ===== FUN_20140420 @ 20140420 (8 bytes)

undefined4 FUN_20140420(void)

{
  return 0xfffffff7;
}


// ===== FUN_20140428 @ 20140428 (8 bytes)

undefined4 FUN_20140428(void)

{
  return 0xfffffff6;
}


// ===== FUN_20140430 @ 20140430 (8 bytes)

undefined4 FUN_20140430(void)

{
  return 4;
}


// ===== FUN_20140438 @ 20140438 (8 bytes)

undefined4 FUN_20140438(void)

{
  return 5;
}


// ===== sdhi_soft_reset @ 20140440 (28 bytes)

/* SOFT_RST 0 then 1 [fact] */

undefined4 sdhi_soft_reset(void)

{
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
  SDHI_SD_OPTION_0 = uVar1;
  return;
}


// ===== FUN_2014048c @ 2014048c (4 bytes)

void FUN_2014048c(void)

{
  return;
}


// ===== FUN_20140490 @ 20140490 (4 bytes)

void FUN_20140490(void)

{
  return;
}


// ===== FUN_20140494 @ 20140494 (4 bytes)

void FUN_20140494(void)

{
  return;
}


// ===== FUN_20140498 @ 20140498 (4 bytes)

void FUN_20140498(void)

{
  return;
}


// ===== FUN_2014049c @ 2014049c (8 bytes)

undefined4 FUN_2014049c(void)

{
  return 0xfffffff7;
}


// ===== sdhi_wait_info @ 201404a4 (148 bytes)

/* (1 response end, 2 access end, 3 buffer read ready, 4 buffer write ready): polls SD_INFO1 /
   SD_INFO2 for the bit [fact for the masks] */

int sdhi_wait_info(int param_1)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort uVar4;
  uint uVar5;
  
  puVar3 = &SDHI_SD_INFO1_0;
  if (param_1 == 1) {
    uVar4 = 1;
  }
  else if (param_1 == 2) {
    uVar4 = 4;
  }
  else {
    puVar3 = &SDHI_SD_INFO2_0;
    if (param_1 == 3) {
      uVar4 = 0x200;
    }
    else {
      if (param_1 != 4) {
        return -2;
      }
      uVar4 = 0x100;
    }
  }
  uVar5 = 0;
  do {
    if ((uVar4 & ~*puVar3) == 0) {
      *puVar3 = ~uVar4;
      return 0;
    }
    uVar1 = SDHI_SD_INFO2_0;
    if ((uVar1 & 0x48) != 0) {
      return -1;
    }
    iVar2 = sdhi_check_card();
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x900000);
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
  
  uVar1 = SDHI_SD_INFO1_0;
  SDHI_SD_INFO1_0 = uVar1 & 0xfff8;
  uVar1 = SDHI_SD_INFO2_0;
  SDHI_SD_INFO2_0 = uVar1 & 0x800;
  SDHI_SD_ARG1_0 = (short)((uint)param_3 >> 0x10);
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
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  sdhi_send_cmd();
  iVar2 = sdhi_wait_info(1);
  if (iVar2 == 0) {
    uVar1 = SDHI_SD_INFO2_0;
    uVar3 = uVar1 & 0xffff807f;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== sdhi_read_response @ 201405f4 (192 bytes)

/* Copies the response registers SD_RSP07..RSP00 into ctx +0x2B0 (long R2 for CMD2/9/10, else 32
   bits) [fact] */

void sdhi_read_response(int param_1,int param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_2 + 0x2b0);
  if ((param_1 != 1 && param_1 != 6) && (param_1 != 7 && param_1 != 3)) {
    uVar1 = SDHI_SD_RSP07_0;
    *(char *)piVar3 = (char)uVar1;
    uVar1 = SDHI_SD_RSP06_0;
    *(char *)(param_2 + 0x2b1) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b2) = (char)uVar1;
    uVar1 = SDHI_SD_RSP05_0;
    *(char *)(param_2 + 0x2b3) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b4) = (char)uVar1;
    uVar1 = SDHI_SD_RSP04_0;
    *(char *)(param_2 + 0x2b5) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b6) = (char)uVar1;
    uVar1 = SDHI_SD_RSP03_0;
    *(char *)(param_2 + 0x2b7) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2b8) = (char)uVar1;
    uVar1 = SDHI_SD_RSP02_0;
    *(char *)(param_2 + 0x2b9) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2ba) = (char)uVar1;
    uVar1 = SDHI_SD_RSP01_0;
    *(char *)(param_2 + 699) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 700) = (char)uVar1;
    uVar1 = SDHI_SD_RSP00_0;
    *(char *)(param_2 + 0x2bd) = (char)((ushort)uVar1 >> 8);
    *(char *)(param_2 + 0x2be) = (char)uVar1;
    return;
  }
  *piVar3 = 0;
  uVar2 = SDHI_SD_RSP01_0;
  *piVar3 = (uint)uVar2 << 0x10;
  uVar1 = SDHI_SD_RSP00_0;
  *piVar3 = CONCAT22(uVar2,uVar1);
  return;
}


// ===== sd_cmd16_set_blocklen @ 201406b4 (152 bytes)

/* Sets SD_SIZE/SECCNT/STOP and sends CMD16 (SET_BLOCKLEN), 3 tries, -9 on failure [inference from
   the command index] */

undefined4 sd_cmd16_set_blocklen(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  sdhi_set_block_size();
  sdhi_set_sector_count(param_2);
  if (param_2 == 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x100;
  }
  sdhi_set_stop(uVar1);
  iVar3 = 0;
  do {
    iVar2 = sdhi_cmd(0x10,0,param_1,param_3);
    if (iVar2 == 0) {
      if (2 < iVar3) {
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
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return 0xfffffff7;
}


// ===== sd_cmd12_stop @ 2014074c (112 bytes)

/* Sends CMD12 (STOP_TRANSMISSION), 3 tries, checks the R1 error bits with mask table 0x20420234
   [inference from the command index] */

undefined4 sd_cmd12_stop(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while (iVar1 = sdhi_cmd(0xc,0,0,param_1), iVar1 != 0) {
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 0xfffffff7;
    }
  }
  if (2 < iVar2) {
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
  undefined2 uVar1;
  int extraout_r2;
  undefined2 extraout_r3;
  undefined2 extraout_r12;
  
  uVar1 = SDHI_SD_CLK_CTRL_0;
  sdhi_soft_reset(2,param_2,&SDHI_SD_CMD_0,uVar1);
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
  
  iVar2 = sd_cmd16_set_blocklen(0x200,param_3,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar1 = SDHI_CC_EXT_MODE_0;
  SDHI_CC_EXT_MODE_0 = uVar1 | 2;
  iVar2 = 0;
  if (param_3 == 1) {
    do {
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
    iVar1 = sdhi_read_sectors_cmd();
  }
  if (iVar1 != 0) {
    sdhi_error_reset();
  }
  return iVar1;
}


// ===== FUN_20140998 @ 20140998 (84 bytes)

undefined4 FUN_20140998(undefined1 *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 >> 2 != 0) {
    do {
      uVar1 = SDHI_SD_BUF0_0;
      iVar2 = iVar2 + 1;
      *param_1 = (char)uVar1;
      param_1[1] = (char)((uint)uVar1 >> 8);
      param_1[2] = (char)((uint)uVar1 >> 0x10);
      param_1[3] = (char)((uint)uVar1 >> 0x18);
      param_1 = param_1 + 4;
    } while (iVar2 < (int)(param_2 >> 2));
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
  
  iVar2 = sd_cmd16_set_blocklen(0x200,param_3,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar1 = SDHI_CC_EXT_MODE_0;
  SDHI_CC_EXT_MODE_0 = uVar1 | 2;
  iVar2 = 0;
  if (param_3 == 1) {
    do {
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
              iVar2 = sdhi_write_block(param_2);
              if (iVar2 != 0) {
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


// ===== sdhi_open @ 20140b68 (424 bytes)

/* SDHI0 open: clock on, soft reset, sdhi0_irq_enable, sdhi_init, registers the two extra handlers
   0x20808B78 / 0x20808B84 with gic_def_inh [fact] */

uint sdhi_open(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  sdhi0_clock_on();
  sdhi_soft_reset(2);
  uVar2 = sdhi0_irq_enable();
  if ((uVar2 == 0) && (uVar2 = sdhi_init(), uVar2 == 0)) {
    DAT_20808b82 = 0;
    DAT_20808b8e = 0;
    uVar2 = DMAC_DMARS0;
    DMAC_DMARS0 = uVar2 & 0xffffff00;
    uVar2 = DMAC_DMARS0;
    DMAC_DMARS0 = uVar2 | 0xc2;
    uVar2 = DMAC_DMARS0;
    DMAC_DMARS0 = uVar2 & 0xff00ffff;
    uVar2 = DMAC_DMARS0;
    DMAC_DMARS0 = uVar2 | 0xc10000;
    uVar3 = *(uint *)((int)&INTC_ICDIPR0 + (DAT_20808b7c & 0xfffffffc));
    uVar2 = DAT_20808b7c & 3;
    if (DAT_20808b80 == -1) {
      uVar1 = gic_def_inh(DAT_20808b7c,DAT_20808b78);
      if ((int)uVar1 < 0) {
        return 0xffffffff;
      }
      DAT_20808b80 = '\x01';
    }
    *(uint *)((int)&INTC_ICDIPR0 + (DAT_20808b7c & 0xfffffffc)) =
         uVar3 & ~(0xff << (uVar2 << 3)) | 7 << (DAT_20808b7c & 3) * 8 + 3;
    uVar3 = *(uint *)((int)&INTC_ICDIPR0 + (DAT_20808b88 & 0xfffffffc));
    uVar2 = DAT_20808b88 & 3;
    if (DAT_20808b8c == -1) {
      uVar1 = gic_def_inh(DAT_20808b88,DAT_20808b84);
      if ((int)uVar1 < 0) {
        return 0xffffffff;
      }
      DAT_20808b8c = '\x01';
    }
    *(uint *)((int)&INTC_ICDIPR0 + (DAT_20808b88 & 0xfffffffc)) =
         uVar3 & ~(0xff << (uVar2 << 3)) | 7 << (DAT_20808b88 & 3) * 8 + 3;
    uVar2 = DMAC_CHCTRL_0;
    DMAC_CHCTRL_0 = uVar2 | 8;
    uVar2 = DMAC_CHCTRL_1;
    DMAC_CHCTRL_1 = uVar2 | 8;
    knl_int_disable();
    (&INTC_ICDISER0)[DAT_20808b7c >> 5] = 1 << (DAT_20808b7c & 0x1f);
    (&INTC_ICDISER0)[DAT_20808b88 >> 5] = 1 << (DAT_20808b88 & 0x1f);
    knl_int_restore();
    return 0;
  }
  return uVar2;
}


// ===== sdhi0_buf_isr @ 20140b9c (76 bytes)

/* SDHI0 SDHI0_0 interrupt (GIC 303, peripherals.md): SD_INFO2 BRE (bit 8) -> sdhi_flag_set(1), BWE
   (bit 9) -> sdhi_flag_set(2), clearing the bit [fact] */

void sdhi0_buf_isr(void)

{
  ushort uVar1;
  
  uVar1 = SDHI_SD_INFO2_0;
  if ((uVar1 & 0x100) != 0) {
    SDHI_SD_INFO2_0 = 0xfeff;
    sdhi_flag_set(1);
    return;
  }
  if ((uVar1 & 0x200) != 0) {
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
      iVar5 = fs_find_drive(uVar3,&local_48);
      if (iVar5 != 0) {
        fs_sem1_signal();
        piVar7 = (int *)0x0;
        goto LAB_20141070;
      }
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
        pcVar8 = (char *)path_next_component(pcVar8,param_3);
        if ((pcVar8 == (char *)0x0) || (*param_3 == '\0')) {
LAB_20141208:
          *(undefined1 *)((int)piVar10 + 0x442) = 0;
          piVar7 = (int *)0x0;
          iVar5 = -1;
          goto LAB_20141070;
        }
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
          uVar4 = fat_ld_word(auStack_52);
          *(undefined2 *)(piVar10 + 0x8d) = uVar4;
          uVar4 = fat_ld_word(auStack_50);
          *(undefined2 *)((int)piVar10 + 0x236) = uVar4;
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
  iVar2 = fs_find_drive(uVar1,&local_18);
  if (iVar2 != 0) {
    fs_set_error_ret(iVar2,0);
    return;
  }
  iVar2 = fs_lock_a(local_18);
  if (iVar2 == 0) {
    uVar4 = file_open_core(param_1,param_2,param_3);
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
      uVar4 = fs_find_drive(uVar1,&local_20);
      if (uVar4 == 0) {
        iVar3 = fs_strlen(param_1);
        iVar5 = param_3 + 0x100c;
        fs_strncpy(iVar5,param_1,iVar3 + 1);
        sjis_map_ext_chars(iVar5);
        piVar7 = (int *)fs_fopen_locked(iVar5,param_2,param_3);
        uVar4 = fs_task_ctx_get();
        if (piVar7 != (int *)0x0) {
          iVar3 = fs_mpf_alloc((uint)*(ushort *)(*piVar7 + 4) * *(int *)(*piVar7 + 0x6c));
          piVar7[1] = iVar3;
          iVar5 = *piVar7;
          piVar7[0x8e] = (uint)*(ushort *)(iVar5 + 4) * *(int *)(iVar5 + 0x6c);
          if (iVar3 == 0) {
            piVar7[1] = (int)(piVar7 + 0xd);
            piVar7[0x8e] = *(int *)(iVar5 + 0x6c);
          }
          if ((*param_2 == 'r' || *param_2 == 'a') && (piVar7[0xb] != 0)) {
            uVar2 = __aeabi_uidivmod(piVar7[0x8e],*(undefined4 *)(iVar5 + 0x6c));
            uVar6 = fs_dev_op1(iVar5,piVar7[8],piVar7[1],uVar2);
            if (uVar6 != 0) {
              if ((int *)piVar7[1] != piVar7 + 0xd) {
                fs_mpf_free();
              }
              fs_memset(piVar7 + 0x8f,0,0x206,*(undefined4 *)(*piVar7 + 0x6c));
              *(undefined1 *)((int)piVar7 + 0x442) = 0;
              piVar7 = (int *)0x0;
              uVar4 = uVar6;
            }
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
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fopen_work(param_1,param_2,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error_ret(0xffffffe1,0);
  return uVar2;
}


// ===== file_sync_shared @ 20141b08 (356 bytes)

/* When a file is open more than once, copies the first cluster and dirty state of this handle to
   the other open handles of the same entry [fact] */

undefined4 file_sync_shared(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (*(char *)((int)param_1 + 0x442) != '\x01') {
    iVar5 = 0;
    puVar4 = DAT_20808b90;
    if (0 < DAT_20808b94) {
      do {
        if (*(char *)((int)param_1 + 0x44d) == '\x01') {
          if ((((*(short *)(puVar4 + 0x8f) != 0) &&
               (iVar2 = fs_wstricmp_ucs2(param_1 + 0x8f,puVar4 + 0x8f), iVar2 == 0)) &&
              (param_1 != puVar4)) && (*(char *)((int)puVar4 + 0x442) == '\x01')) {
            if (puVar4[7] != param_1[7]) {
              puVar4[7] = param_1[7];
              uVar3 = fat_clust2sect(*puVar4);
              puVar4[8] = uVar3;
              *(undefined2 *)((int)puVar4 + 0x44e) = 1;
            }
            if (*(short *)((int)param_1 + 0x44e) != 0) {
              *(undefined2 *)((int)puVar4 + 0x44e) = 1;
            }
            sVar1 = *(short *)((int)puVar4 + 0x44e);
            goto joined_r0x20141be8;
          }
        }
        else if (((*(char *)(puVar4 + 0x8f) != '\0') &&
                 (iVar2 = fs_stricmp_sjis_fold(param_1 + 0x8f,puVar4 + 0x8f), iVar2 == 0)) &&
                ((param_1 != puVar4 && (*(char *)((int)puVar4 + 0x442) == '\x01')))) {
          if (puVar4[7] != param_1[7]) {
            puVar4[7] = param_1[7];
            uVar3 = fat_clust2sect(*puVar4);
            puVar4[8] = uVar3;
            *(undefined2 *)((int)puVar4 + 0x44e) = 1;
          }
          if (*(short *)((int)param_1 + 0x44e) != 0) {
            *(undefined2 *)((int)puVar4 + 0x44e) = 1;
          }
          sVar1 = *(short *)((int)puVar4 + 0x44e);
joined_r0x20141be8:
          if (sVar1 != 0) {
            puVar4[0xb] = param_1[0xb];
          }
        }
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 0x114;
      } while (iVar5 < DAT_20808b94);
    }
    *(undefined2 *)((int)param_1 + 0x44e) = 0;
  }
  return 0;
}


// ===== file_dirent_update @ 20141c6c (396 bytes)

/* Writes size, attribute, write time and first cluster of an open file back to its directory entry
   (root or subdirectory sector) and marks it dirty [fact] */

void file_dirent_update(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_r1;
  int extraout_r1_00;
  int local_20;
  
  local_20 = param_2 + 0xe0c;
  if ((char)param_1[0x111] == '\0') {
    iVar1 = *param_1;
    uVar2 = __aeabi_uidivmod(param_1[6],*(uint *)(iVar1 + 0x6c) >> 5);
    iVar1 = root_sector_get(iVar1,uVar2,&local_20);
    if (iVar1 == 0) {
      __aeabi_uidivmod(param_1[6],*(uint *)(*param_1 + 0x6c) >> 5);
      iVar1 = local_20 + extraout_r1_00 * 0x20;
      fat_st_dword(iVar1 + 0x1c,param_1[0xb]);
      *(undefined1 *)(iVar1 + 0xb) = *(undefined1 *)((int)param_1 + 0x443);
      if ((char)param_1[0x113] == '\x01') {
        dirent_set_time(iVar1,param_1,6);
      }
      fat_st_word(iVar1 + 0x16,(short)param_1[0x8d]);
      fat_st_word(iVar1 + 0x18,*(undefined2 *)((int)param_1 + 0x236));
      dirent_set_cluster(iVar1,param_1[7],(int)*(char *)(*param_1 + 0x10));
      root_sector_dirty(*param_1,uVar2,local_20);
    }
  }
  else {
    iVar1 = dir_sector_get(*param_1,param_1[9],&local_20);
    if (iVar1 == 0) {
      __aeabi_uidivmod(param_1[6],*(uint *)(*param_1 + 0x6c) >> 5);
      iVar1 = local_20 + extraout_r1 * 0x20;
      fat_st_dword(iVar1 + 0x1c,param_1[0xb]);
      *(undefined1 *)(iVar1 + 0xb) = *(undefined1 *)((int)param_1 + 0x443);
      if ((char)param_1[0x113] == '\x01') {
        dirent_set_time(iVar1,param_1,6);
      }
      fat_st_word(iVar1 + 0x16,(short)param_1[0x8d]);
      fat_st_word(iVar1 + 0x18,*(undefined2 *)((int)param_1 + 0x236));
      dirent_set_cluster(iVar1,param_1[7],(int)*(char *)(*param_1 + 0x10));
      dir_sector_dirty(*param_1,param_1[9],local_20);
      return;
    }
  }
  return;
}


// ===== file_dirent_update_locked @ 20141df8 (64 bytes)

/* file_dirent_update under fs_lock_a [fact] */

undefined4 file_dirent_update_locked(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_a(*param_1);
  if (iVar1 == 0) {
    uVar2 = file_dirent_update(param_1,param_2);
    fs_unlock_a(*param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== file_flush @ 20141e38 (268 bytes)

/* Writes the file's dirty sector buffer (fs_dev_op2), updates the directory entry for write modes
   and the other handles (file_sync_shared) [fact] */

int file_flush(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = fs_drive_check_mounted(*param_1);
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = *param_1;
  uVar2 = __aeabi_uidivmod(param_1[0x8e],*(undefined4 *)(iVar3 + 0x6c));
  if ((param_1[2] != 0) && (param_1[8] != 0)) {
    iVar3 = fs_dev_op2(iVar3,param_1[8],param_1[1],uVar2);
    if (iVar3 != 0) {
      fs_memset(param_1 + 0x8f,0,0x206,*(undefined4 *)(*param_1 + 0x6c));
      return iVar3;
    }
    *(undefined1 *)(param_1 + 0x113) = 1;
  }
  cVar1 = *(char *)((int)param_1 + 0x442);
  if ((cVar1 == '\x10' || cVar1 == '\x11') || (cVar1 == ' ' || cVar1 == '!')) {
    iVar3 = file_dirent_update_locked(param_1,param_2);
    if (iVar3 != 0) {
      fs_memset(param_1 + 0x8f,0,0x206,*(undefined4 *)(*param_1 + 0x6c));
      return iVar3;
    }
    *(undefined1 *)(param_1 + 0x113) = 0;
  }
  file_sync_shared(param_1);
  param_1[2] = 0;
  fs_memset(param_1 + 0x8f,0,0x206,*(undefined4 *)(*param_1 + 0x6c));
  return 0;
}


// ===== fs_fclose_work @ 20141f44 (172 bytes)

/* fs_fclose body: file_flush, FAT32 FSInfo update and fs_flush for write modes, frees the buffer,
   clears the open mode [fact] */

void fs_fclose_work(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = fs_check_ready();
  if ((iVar2 == 0) && (iVar2 = fs_file_check(param_1), iVar2 == 0)) {
    cVar1 = *(char *)((int)param_1 + 0x442);
    iVar2 = file_flush(param_1,param_2);
    if ((iVar2 == 0) && (cVar1 != '\x01')) {
      iVar2 = fat32_fsinfo_write_locked(*param_1,param_2);
    }
    if ((undefined4 *)param_1[1] != param_1 + 0xd) {
      fs_mpf_free();
    }
    if ((iVar2 == 0) && (cVar1 != '\x01')) {
      iVar2 = fs_flush(*param_1);
    }
    *(undefined1 *)((int)param_1 + 0x442) = 0;
    fs_set_error(iVar2,0);
    return;
  }
  fs_set_error(iVar2,0);
  return;
}


// ===== fs_fclose @ 20141ff0 (68 bytes)

/* (fd): work buffer, FUN_20141f44(fd, buf), free; error -31 without a buffer [fact]; close
   (update.md) [fact] */

undefined4 fs_fclose(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fclose_work(param_1,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== file_getc @ 20142034 (396 bytes)

/* Next byte of a file, reloading the sector buffer and following the cluster chain
   (fat_next_sector); -1 at the end [fact] */

uint file_getc(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int local_20;
  
  iVar3 = *param_1;
  local_20 = param_4;
  uVar2 = __aeabi_uidivmod(param_1[0x8e],*(undefined4 *)(iVar3 + 0x6c));
  iVar3 = fs_drive_check_mounted(iVar3);
  if (iVar3 != 0) {
LAB_201420d4:
    uVar2 = fs_set_error(iVar3,param_1);
    return uVar2;
  }
  if (((param_1[8] != 0) && (*(short *)((int)param_1 + 0x44e) != 0)) &&
     (*(char *)((int)param_1 + 0x442) == '\x01')) {
    iVar3 = fs_dev_op1(*param_1,param_1[8],param_1[1],uVar2 & 0xffff);
    if (iVar3 != 0) goto LAB_201420d4;
    *(undefined2 *)((int)param_1 + 0x44e) = 0;
  }
  if ((uint)param_1[0x8e] <= (uint)param_1[5]) {
    if (param_1[7] != 0) {
      if (param_1[2] != 0) {
        iVar3 = fs_dev_op2(*param_1,param_1[8],param_1[1],uVar2 & 0xffff);
        if (iVar3 != 0) goto LAB_201420d4;
        param_1[2] = 0;
        *(undefined1 *)(param_1 + 0x113) = 1;
      }
      iVar3 = fat_next_sector(*param_1,(uVar2 - 1) + param_1[8],&local_20,param_2);
      if (iVar3 != 0) goto LAB_20142164;
      if (local_20 == 0) {
        iVar3 = -0x3d;
        goto LAB_20142164;
      }
      iVar3 = fs_dev_op1(*param_1,local_20,param_1[1],uVar2 & 0xffff);
      if (iVar3 != 0) goto LAB_20142164;
      param_1[8] = local_20;
    }
    param_1[5] = 0;
  }
  if ((uint)param_1[10] < (uint)param_1[0xb]) {
    param_1[10] = param_1[10] + 1;
    iVar3 = param_1[5];
    param_1[5] = iVar3 + 1;
    bVar1 = *(byte *)(param_1[1] + iVar3);
    fs_set_error(0,param_1);
    return (uint)bVar1;
  }
  iVar3 = -0xe;
LAB_20142164:
  uVar2 = fs_set_error(iVar3,param_1);
  return uVar2;
}


// ===== fs_fgetc_work @ 201421c0 (104 bytes)

/* Checked file_getc (-5 for a write-only handle) [fact] */

void fs_fgetc_work(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = fs_check_ready();
  if ((iVar1 == 0) && (iVar1 = fs_file_check(param_1), iVar1 == 0)) {
    if (*(char *)(param_1 + 0x442) != '\x10' && *(char *)(param_1 + 0x442) != ' ') {
      file_getc(param_1,param_2);
      return;
    }
    fs_set_error(0xfffffffb,param_1);
    return;
  }
  fs_set_error(iVar1,0);
  return;
}


// ===== fs_fgetc @ 20142228 (68 bytes)

/* fs_fgetc_work with a work buffer [fact] */

undefined4 fs_fgetc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fgetc_work(param_1,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== fs_fgets_work @ 20142300 (292 bytes)

/* Reads up to n-1 bytes or through '\\n' with file_getc and 0-terminates [fact] */

int fs_fgets_work(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar3 = fs_check_ready();
  if ((iVar3 != 0) || (iVar3 = fs_file_check(param_3), iVar3 != 0)) {
    iVar3 = fs_set_error_ret(iVar3,0);
    return iVar3;
  }
  if (param_1 == 0) {
    iVar3 = fs_set_error_ret(0xfffffff3,0);
    return iVar3;
  }
  if (*(char *)(param_3 + 0x442) == '\x10' || *(char *)(param_3 + 0x442) == ' ') {
    iVar3 = fs_set_error_ret(0xfffffffb,0);
    return iVar3;
  }
  if (param_2 < 1) {
    iVar3 = fs_set_error_ret(0);
    return iVar3;
  }
  iVar4 = param_2 + -1;
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      iVar2 = file_getc(param_3,param_4);
      if (iVar2 == -1) break;
      bVar5 = SBORROW4(iVar2,10);
      iVar1 = iVar2 + -10;
      *(char *)(param_1 + iVar3) = (char)iVar2;
      iVar3 = iVar3 + 1;
      if (iVar2 != 10) {
        bVar5 = SBORROW4(iVar3,iVar4);
        iVar1 = iVar3 - iVar4;
      }
    } while (iVar1 < 0 != bVar5);
  }
  *(undefined1 *)(param_1 + iVar3) = 0;
  if ((iVar3 == 0) && (1 < param_2)) {
    iVar3 = fs_set_error_ret(0xfffffff2,0);
    return iVar3;
  }
  return param_1;
}


// ===== fs_fgets @ 20142390 (84 bytes)

/* (buf, n, fd): fgets; sfl_stream_gets, sfl_read_header and cli_run_file read text lines with it
   [fact] */

undefined4 fs_fgets(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fgets_work(param_1,param_2,param_3,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error_ret(0xffffffe1,0);
  return uVar2;
}


// ===== file_read_core @ 201423e4 (480 bytes)

/* Sector-wise read body behind fs_fread [inference: chain fs_fread -> 0x20142980 -> 0x201425C4 ->
   here] */

int file_read_core(uint param_1,int param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_40;
  int local_3c;
  uint uStack_34;
  int iStack_30;
  int *piStack_2c;
  undefined4 local_28;
  
  local_3c = param_3[10];
  uStack_34 = param_1;
  iStack_30 = param_2;
  piStack_2c = param_3;
  local_28 = param_4;
  uVar1 = __aeabi_uidivmod(param_3[0x8e],*(undefined4 *)(*param_3 + 0x6c));
  do {
    if (param_1 == 0) goto LAB_20142500;
    if ((uint)param_3[0x8e] <= (uint)param_3[5]) {
      if (param_3[7] != 0) {
        if (param_3[2] != 0) {
          iVar2 = fs_dev_op2(*param_3,param_3[8],param_3[1],uVar1 & 0xffff);
          if (iVar2 != 0) goto LAB_201424fc;
          param_3[2] = 0;
          *(undefined1 *)(param_3 + 0x113) = 1;
        }
        iVar2 = fat_sector_is_cluster_first(*param_3,param_3[8]);
        if (iVar2 != 0) {
          param_3[8] = param_3[8] + (uVar1 - 1);
        }
        iVar2 = fat_next_sector(*param_3,param_3[8],&local_40,local_28);
        if (iVar2 != 0) goto LAB_201424fc;
        if (local_40 == 0) goto LAB_20142500;
        iVar2 = fs_dev_op1(*param_3,local_40,param_3[1],uVar1 & 0xffff);
        if (iVar2 != 0) goto LAB_201424fc;
        param_3[8] = local_40;
      }
      param_3[5] = 0;
    }
    if ((uint)param_3[0xb] <= (uint)param_3[10]) break;
    uVar3 = param_3[0x8e] - param_3[5];
    uVar4 = param_1;
    if (uVar3 < param_1) {
      uVar4 = uVar3;
    }
    fs_memcpy(param_2,param_3[1] + param_3[5],uVar4);
    iVar2 = param_3[5];
    param_1 = param_1 - uVar4;
    param_2 = param_2 + uVar4;
    param_3[5] = iVar2 + uVar4;
    param_3[10] = param_3[10] + uVar4;
    if (((uint)param_3[0x8e] <= iVar2 + uVar4) && (param_3[2] != 0)) {
      iVar2 = fs_dev_op2(*param_3,param_3[8],param_3[1],uVar1 & 0xffff);
      if (iVar2 != 0) goto LAB_201424fc;
      param_3[2] = 0;
      *(undefined1 *)(param_3 + 0x113) = 1;
    }
  } while ((uint)param_3[10] < (uint)param_3[0xb]);
  iVar2 = -0xe;
LAB_201424fc:
  fs_set_error(iVar2,param_3);
LAB_20142500:
  if ((uint)param_3[0xb] <= (uint)param_3[10]) {
    fs_set_error(0xfffffff2,param_3);
  }
  return param_3[10] - local_3c;
}


// ===== file_read_locked @ 201425c4 (956 bytes)

/* Read under the drive lock [inference: same chain] */

int file_read_locked(int param_1,int param_2,int param_3,int *param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int extraout_r1;
  uint extraout_r1_00;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_50;
  int local_4c;
  int local_40;
  uint local_3c;
  int iStack_34;
  int local_30;
  int iStack_2c;
  int *piStack_28;
  
  local_4c = 0;
  iVar7 = *param_4;
  iVar8 = *(int *)(iVar7 + 0x6c);
  iStack_34 = param_1;
  local_30 = param_2;
  iStack_2c = param_3;
  piStack_28 = param_4;
  uVar1 = __aeabi_uidivmod(param_4[0x8e],iVar8);
  uVar9 = (uint)*(ushort *)(iVar7 + 4) * iVar8;
  fs_set_error(0,param_4);
  uVar2 = param_4[0xb] - param_4[10];
  uVar10 = param_2 * param_3;
  if (uVar2 < (uint)(param_2 * param_3)) {
    uVar10 = uVar2;
  }
  if (uVar10 == 0) {
    if ((uint)param_4[0xb] <= (uint)param_4[10]) {
      fs_set_error(0xfffffff2,param_4);
    }
    return 0;
  }
  iVar7 = fs_drive_check_mounted(*param_4);
  if (iVar7 != 0) {
LAB_201426a4:
    fs_set_error(iVar7,param_4);
    return 0;
  }
  if (((param_4[8] != 0) && (*(short *)((int)param_4 + 0x44e) != 0)) &&
     (*(char *)((int)param_4 + 0x442) == '\x01')) {
    iVar7 = fs_dev_op1(*param_4,param_4[8],param_4[1],uVar1 & 0xffff);
    if (iVar7 != 0) goto LAB_201426a4;
    *(undefined2 *)((int)param_4 + 0x44e) = 0;
  }
  iVar7 = param_4[10];
  __aeabi_uidivmod(iVar7,uVar9);
  if (extraout_r1 + uVar10 < uVar9) {
    uVar3 = file_read_core(uVar10,param_1,param_4,param_5);
    iVar7 = __aeabi_uidivmod(uVar3,local_30);
    return iVar7;
  }
  uVar2 = uVar9 - extraout_r1;
  __aeabi_uidivmod(iVar7 + uVar10,uVar9);
  iVar7 = (uVar10 - uVar2) - extraout_r1_00;
  local_50 = extraout_r1_00;
  if ((iVar7 != 0) && (local_50 = extraout_r1_00, extraout_r1_00 == 0)) {
    iVar7 = (uVar10 - uVar2) - uVar9;
    local_50 = uVar9;
  }
  uVar4 = file_read_core(uVar2,param_1,param_4,param_5);
  if (uVar2 <= uVar4) {
    param_1 = param_1 + uVar4;
    param_4[8] = (uVar1 - 1) + param_4[8];
    iVar8 = __aeabi_uidivmod(uVar2,local_30);
    uVar4 = 0;
    uVar2 = __aeabi_uidivmod(iVar7,uVar9);
    uVar11 = 0;
    if (uVar2 != 0) {
      do {
        iVar5 = fat_next_sector(*param_4,param_4[8],&local_40,param_5);
        iVar7 = local_40;
        if (iVar5 != 0) goto LAB_201428cc;
        if (local_40 == 0) {
          return iVar8;
        }
        if (uVar4 == 0) {
          local_4c = local_40;
          uVar4 = 1;
          param_4[8] = (uint)*(ushort *)(*param_4 + 4) + local_40 + -1;
        }
        else {
          if (param_4[8] + 1 == local_40) {
            local_3c = (uint)*(ushort *)(*param_4 + 4);
            uVar6 = __aeabi_uidivmod(0x100);
            if (uVar4 < uVar6) {
              uVar4 = uVar4 + 1;
              param_4[8] = local_3c + iVar7 + -1;
              goto LAB_20142890;
            }
          }
          iVar5 = fs_dev_op1(*param_4,local_4c,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
          iVar7 = local_40;
          local_4c = local_40;
          if (iVar5 != 0) goto LAB_201428cc;
          param_1 = uVar9 * uVar4 + param_1;
          iVar5 = __aeabi_uidivmod(uVar9 * uVar4,local_30);
          iVar8 = iVar8 + iVar5;
          uVar4 = 1;
          param_4[8] = (uint)*(ushort *)(*param_4 + 4) + iVar7 + -1;
        }
LAB_20142890:
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar2);
      if (uVar4 != 0) {
        iVar5 = fs_dev_op1(*param_4,local_4c,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
        if (iVar5 != 0) {
LAB_201428cc:
          fs_set_error(iVar5,param_4);
          return iVar8;
        }
        param_1 = uVar9 * uVar4 + param_1;
        param_4[8] = *(ushort *)(*param_4 + 4) * uVar4 + local_4c + -1;
        iVar7 = __aeabi_uidivmod(uVar9 * uVar4,local_30);
        iVar8 = iVar8 + iVar7;
      }
    }
    param_4[10] = uVar9 * uVar2 + param_4[10];
    if (uVar2 != 0) {
      param_4[8] = (param_4[8] - uVar1) + 1;
    }
    uVar1 = file_read_core(local_50,param_1,param_4,param_5);
    uVar4 = uVar10;
    if (uVar1 < local_50) {
      iVar7 = __aeabi_uidivmod(uVar1,local_30);
      return iVar7 + iVar8;
    }
  }
  iVar7 = __aeabi_uidivmod(uVar4,local_30);
  return iVar7;
}


// ===== fs_fread_work @ 20142980 (216 bytes)

/* fs_fread body: handle checks, then file_read_locked [inference: only caller fs_fread] */

undefined4 fs_fread_work(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = fs_check_ready();
  if ((iVar1 != 0) || (iVar1 = fs_file_check(param_4), iVar1 != 0)) {
    fs_set_error(iVar1,0);
    return 0;
  }
  if (param_1 != 0) {
    if (*(char *)(param_4 + 0x442) == '\x10' || *(char *)(param_4 + 0x442) == ' ') {
      fs_set_error(0xfffffffb,param_4);
      return 0;
    }
    if (param_2 == 0 || param_3 == 0) {
      fs_set_error(0,param_4);
      return 0;
    }
    uVar2 = __aeabi_uidivmod(0xffffffff,param_2);
    if (param_3 <= uVar2) {
      uVar3 = file_read_locked(param_1,param_2,param_3,param_4,param_5);
      return uVar3;
    }
  }
  fs_set_error(0xfffffff3,param_4);
  return 0;
}


// ===== fs_fread @ 20142a58 (96 bytes)

uint fs_fread(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fread_work(param_1,param_2,param_3,param_4,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  fs_set_error(0xffffffe1,0);
  return 0;
}


// ===== file_write_core @ 20142ab8 (2496 bytes)

/* Sector-wise write body behind fs_fwrite (allocates clusters, 2496 bytes) [inference: chain
   fs_fwrite -> 0x2014358C -> 0x20143478 -> here] */

int file_write_core(int param_1,int param_2,int param_3,uint *param_4,undefined4 param_5)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int extraout_r1;
  int extraout_r1_00;
  uint extraout_r1_01;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  uint *local_40;
  int local_3c;
  int iStack_34;
  int local_30;
  int local_2c;
  uint *puStack_28;
  
  uVar9 = 0;
  iVar7 = 0;
  uVar8 = 0;
  uVar4 = param_2 * param_3;
  local_5c = *param_4;
  iVar5 = *(int *)(local_5c + 0x6c);
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  puStack_28 = param_4;
  local_58 = __aeabi_uidivmod(param_4[0x8e],iVar5);
  uVar6 = (uint)*(ushort *)(local_5c + 4) * iVar5;
  fs_set_error(0,param_4);
  if (uVar4 == 0) {
    return 0;
  }
  if (param_4[10] == 0xffffffff) {
    fs_set_error(0xffffffc5,param_4);
    return 0;
  }
  uVar2 = ~param_4[10];
  if (uVar2 < uVar4) {
    local_2c = __aeabi_uidivmod(uVar2,local_30);
    uVar4 = uVar2;
  }
  iVar5 = fs_drive_check_mounted(*param_4);
  if (iVar5 != 0) {
LAB_20142d60:
    fs_set_error(iVar5,param_4);
    return 0;
  }
  __aeabi_uidivmod(param_4[10],uVar6);
  local_40 = param_4 + 0x100;
  if (extraout_r1 + uVar4 < uVar6) {
    iVar5 = local_58 - 1;
    do {
      if (param_4[0x8e] <= param_4[5]) {
        if (param_4[2] != 0) {
          uVar8 = *param_4;
          uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(uVar8 + 0x6c));
          iVar7 = fs_dev_op2(uVar8,param_4[8],param_4[1],uVar1);
          if (iVar7 != 0) goto LAB_20142cec;
          param_4[2] = 0;
          *(undefined1 *)(param_4 + 0x113) = 1;
        }
        iVar7 = fat_sector_is_cluster_first(*param_4,param_4[8]);
        if (iVar7 != 0) {
          param_4[8] = param_4[8] + iVar5;
        }
        iVar7 = fat_next_sector(*param_4,param_4[8],&local_60,param_5);
        uVar8 = local_60;
        if (iVar7 != 0) goto LAB_20142cec;
        if (local_60 == 0) {
          iVar7 = fat_next_sector_alloc(*param_4,param_4[8],&local_60,param_5);
          if (iVar7 != 0) goto LAB_20142cec;
          if (local_60 == 0) {
            iVar7 = -0xb;
            goto LAB_20142cec;
          }
        }
        else {
          uVar9 = *param_4;
          uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(uVar9 + 0x6c));
          iVar7 = fs_dev_op1(uVar9,uVar8,param_4[1],uVar1);
          if (iVar7 != 0) goto LAB_20142cec;
        }
        param_4[8] = local_60;
        param_4[5] = 0;
      }
      uVar9 = param_4[0x8e] - param_4[5];
      uVar8 = uVar4;
      if (uVar9 < uVar4) {
        uVar8 = uVar9;
      }
      fs_memcpy(param_4[1] + param_4[5],param_1,uVar8);
      uVar4 = uVar4 - uVar8;
      param_1 = param_1 + uVar8;
      param_4[5] = param_4[5] + uVar8;
      uVar8 = param_4[10] + uVar8;
      param_4[10] = uVar8;
      if (param_4[0xb] <= uVar8) {
        param_4[0xb] = uVar8;
      }
      param_4[2] = 1;
      *(undefined2 *)((int)local_40 + 0x4e) = 1;
    } while (uVar4 != 0);
    iVar7 = 0;
LAB_20142cec:
    fs_set_error(iVar7,param_4);
    uVar9 = local_30 * local_2c - uVar4;
    goto LAB_20143008;
  }
  if ((*(char *)((int)param_4 + 0x442) == ' ' || *(char *)((int)param_4 + 0x442) == '!') &&
     (iVar5 = file_buf_sync(param_4,0,2,param_5), iVar5 != 0)) goto LAB_20142d60;
  local_50 = param_4[10];
  __aeabi_uidivmod(local_50,uVar6);
  local_5c = uVar6 - extraout_r1_00;
  __aeabi_uidivmod(local_50 + uVar4,uVar6);
  local_3c = (uVar4 - local_5c) - extraout_r1_01;
  local_50 = extraout_r1_01;
  if ((local_3c != 0) && (local_50 = extraout_r1_01, extraout_r1_01 == 0)) {
    local_3c = (uVar4 - local_5c) - uVar6;
    local_50 = uVar6;
  }
  param_4[3] = 1;
  local_44 = local_58 - 1;
  uVar4 = local_5c;
  while (uVar4 != 0) {
    if (param_4[0x8e] <= param_4[5]) {
      if (param_4[2] != 0) {
        local_4c = *param_4;
        uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(local_4c + 0x6c));
        iVar5 = fs_dev_op2(local_4c,param_4[8],param_4[1],uVar1);
        if (iVar5 != 0) goto LAB_20142f50;
        param_4[2] = 0;
        *(undefined1 *)(param_4 + 0x113) = 1;
      }
      iVar5 = fat_sector_is_cluster_first(*param_4,param_4[8]);
      if (iVar5 != 0) {
        param_4[8] = local_44 + param_4[8];
      }
      iVar5 = fat_next_sector(*param_4,param_4[8],&local_60,param_5);
      if (iVar5 != 0) {
LAB_20142f50:
        fs_set_error(iVar5,param_4);
        iVar5 = __aeabi_uidivmod(uVar9,local_30);
        return iVar5;
      }
      local_4c = local_60;
      if (local_60 == 0) {
        iVar5 = fat_next_sector_alloc(*param_4,param_4[8],&local_60,param_5);
        if (iVar5 != 0) goto LAB_20142f50;
        if (local_60 == 0) {
          fs_set_error(0xfffffff5,param_4);
          goto LAB_20143008;
        }
      }
      else {
        local_48 = *param_4;
        uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(local_48 + 0x6c));
        iVar5 = fs_dev_op1(local_48,local_4c,param_4[1],uVar1);
        if (iVar5 != 0) {
          fs_set_error(iVar5,param_4);
          goto LAB_20143008;
        }
      }
      param_4[8] = local_60;
      param_4[5] = 0;
    }
    uVar2 = param_4[0x8e] - param_4[5];
    uVar9 = uVar4;
    if (uVar2 < uVar4) {
      uVar9 = uVar2;
    }
    fs_memcpy(param_4[1] + param_4[5],param_1,uVar9);
    uVar4 = uVar4 - uVar9;
    param_1 = param_1 + uVar9;
    param_4[5] = param_4[5] + uVar9;
    uVar2 = param_4[10] + uVar9;
    param_4[10] = uVar2;
    if (param_4[0xb] <= uVar2) {
      param_4[0xb] = uVar2;
    }
    param_4[2] = 1;
    *(undefined2 *)((int)local_40 + 0x4e) = 1;
  }
  fs_set_error(0,param_4);
  uVar9 = 0;
  if (local_5c != 0) {
    uVar9 = local_5c;
  }
  if (param_4[2] == 0) {
LAB_20143048:
    uVar4 = 0;
    local_5c = __aeabi_uidivmod(local_3c,uVar6);
    uVar2 = 0;
    if (local_5c != 0) {
      do {
        iVar5 = fat_next_sector(*param_4,param_4[8],&local_54,param_5);
        if (iVar5 != 0) goto LAB_20142e7c;
        if (local_54 == 0) {
          local_58 = fat_next_sector_alloc(*param_4,param_4[8],&local_54,param_5);
          if (local_58 != 0) {
            fs_set_error(local_58,param_4);
          }
          if (local_54 == 0) {
            fs_set_error(0xfffffff5,param_4);
          }
          if ((local_58 != 0) || (local_54 == 0)) {
            if (uVar4 == 0) {
              uVar9 = uVar9 + iVar7;
            }
            else {
              iVar5 = fs_dev_op2(*param_4,uVar8,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
              uVar9 = uVar6 * uVar4 + uVar9 + iVar7;
              uVar4 = uVar6 * uVar4 + param_4[10] + iVar7;
              param_4[10] = uVar4;
              if (param_4[0xb] < uVar4) {
                param_4[0xb] = uVar4;
              }
              if (iVar5 == 0) {
                *(undefined1 *)(param_4 + 0x113) = 1;
                fs_set_error(0xfffffff5,param_4);
              }
              else {
                fs_set_error(iVar5,param_4);
              }
            }
            goto LAB_20143008;
          }
        }
        if (uVar4 == 0) {
          uVar4 = 1;
          param_4[8] = (uint)*(ushort *)(*param_4 + 4) + (local_54 - 1);
          uVar8 = local_54;
        }
        else {
          local_48 = local_54;
          if (param_4[8] + 1 == local_54) {
            local_4c = (uint)*(ushort *)(*param_4 + 4);
            uVar3 = __aeabi_uidivmod(0x100);
            if (uVar4 < uVar3) {
              uVar4 = uVar4 + 1;
              param_4[8] = local_4c + (local_48 - 1);
              goto LAB_20143258;
            }
          }
          iVar5 = fs_dev_op2(*param_4,uVar8,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
          if (iVar5 != 0) {
            uVar9 = uVar9 + iVar7;
            fs_set_error(iVar5,param_4);
            goto LAB_20143008;
          }
          param_1 = uVar6 * uVar4 + param_1;
          iVar7 = uVar6 * uVar4 + iVar7;
          uVar4 = 1;
          param_4[8] = (local_54 - 1) + (uint)*(ushort *)(*param_4 + 4);
          *(undefined1 *)(param_4 + 0x113) = 1;
          uVar8 = local_54;
        }
LAB_20143258:
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_5c);
      if (uVar4 != 0) {
        iVar5 = fs_dev_op2(*param_4,uVar8,param_1,*(ushort *)(*param_4 + 4) * uVar4 & 0xffff);
        if (iVar5 != 0) goto LAB_20142e7c;
        param_1 = uVar6 * uVar4 + param_1;
        param_4[8] = *(ushort *)(*param_4 + 4) * uVar4 + (uVar8 - 1);
        *(undefined1 *)(param_4 + 0x113) = 1;
      }
    }
    uVar4 = 0;
    iVar5 = uVar6 * local_5c + uVar9;
    uVar9 = uVar6 * local_5c + param_4[10];
    param_4[10] = uVar9;
    uVar8 = local_50;
    if (param_4[0xb] < uVar9) {
      param_4[0xb] = uVar9;
    }
    while( true ) {
      if (uVar8 == 0) {
        fs_set_error(0,param_4);
        return local_2c;
      }
      if (param_4[0x8e] <= param_4[5]) break;
LAB_20143400:
      uVar9 = param_4[0x8e] - param_4[5];
      uVar4 = uVar8;
      if (uVar9 < uVar8) {
        uVar4 = uVar9;
      }
      fs_memcpy(param_4[1] + param_4[5],param_1,uVar4);
      param_1 = param_1 + uVar4;
      param_4[5] = param_4[5] + uVar4;
      uVar9 = param_4[10] + uVar4;
      param_4[10] = uVar9;
      if (param_4[0xb] <= uVar9) {
        param_4[0xb] = uVar9;
      }
      param_4[2] = 1;
      uVar8 = uVar8 - uVar4;
    }
    if (param_4[2] == 0) {
LAB_20143364:
      iVar7 = fat_next_sector(*param_4,param_4[8],&local_60,param_5);
      if (iVar7 == 0) {
        local_5c = local_60;
        if (local_60 == 0) {
          iVar7 = fat_next_sector_alloc(*param_4,param_4[8],&local_60,param_5);
          if (iVar7 == 0) {
            if (local_60 != 0) goto LAB_201433f4;
            fs_set_error(0xfffffff5,param_4);
            uVar9 = uVar4 + iVar5;
            goto LAB_20143008;
          }
        }
        else {
          uVar9 = *param_4;
          uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(uVar9 + 0x6c));
          iVar7 = fs_dev_op1(uVar9,local_5c,param_4[1],uVar1);
          if (iVar7 == 0) {
LAB_201433f4:
            param_4[8] = local_60;
            param_4[5] = 0;
            goto LAB_20143400;
          }
        }
      }
    }
    else {
      uVar9 = *param_4;
      uVar1 = __aeabi_uidivmod(param_4[0x8e],*(undefined4 *)(uVar9 + 0x6c));
      iVar7 = fs_dev_op2(uVar9,param_4[8],param_4[1],uVar1);
      if (iVar7 == 0) {
        param_4[8] = local_44 + param_4[8];
        param_4[2] = 0;
        *(undefined1 *)(param_4 + 0x113) = 1;
        goto LAB_20143364;
      }
    }
    fs_set_error(iVar7,param_4);
    uVar9 = uVar4 + iVar5;
  }
  else {
    iVar5 = fs_dev_op2(*param_4,param_4[8],param_4[1],local_58 & 0xffff);
    if (iVar5 == 0) {
      iVar5 = fat_sector_is_cluster_first(*param_4,param_4[8]);
      if (iVar5 != 0) {
        param_4[8] = local_44 + param_4[8];
      }
      param_4[2] = 0;
      *(undefined1 *)(param_4 + 0x113) = 1;
      goto LAB_20143048;
    }
LAB_20142e7c:
    fs_set_error(iVar5,param_4);
  }
LAB_20143008:
  iVar5 = __aeabi_uidivmod(uVar9,local_30);
  return iVar5;
}


// ===== file_write_locked @ 20143478 (276 bytes)

/* Write under the drive lock [inference: same chain] */

undefined4
file_write_locked(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                 undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_1c;
  
  if (((*(char *)((int)param_4 + 0x442) == ' ' || *(char *)((int)param_4 + 0x442) == '!') &&
      (param_4[10] != param_4[0xb])) && (iVar1 = file_buf_sync(param_4,0,2,param_5), iVar1 != 0)) {
LAB_201434f8:
    fs_set_error(iVar1,param_4);
    return 0;
  }
  if (param_4[0xb] == 0) {
    iVar1 = fat_alloc_cluster_locked(*param_4,0,&local_1c,param_5);
    if (iVar1 != 0) goto LAB_201434f8;
    param_4[7] = local_1c;
    if (local_1c == 0) {
      fs_set_error(0xfffffff5,param_4);
      return 0;
    }
    iVar1 = fat_clust2sect(*param_4);
    param_4[8] = iVar1;
    fs_memset(param_4[1],0,param_4[0x8e],*(undefined4 *)(*param_4 + 0x6c));
  }
  uVar2 = file_write_core(param_1,param_2,param_3,param_4,param_5);
  uVar3 = fs_task_ctx_get();
  fs_set_error(uVar3,param_4);
  return uVar2;
}

