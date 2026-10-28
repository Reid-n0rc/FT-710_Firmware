// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== sdr_spi_master_write @ 201107c0 (116 bytes)

/* RSPI2 master for SDR image */

void sdr_spi_master_write(undefined4 param_1,undefined4 param_2)

{
  if (DAT_208001b4 == '\0') {
    dmac5_disable();
    rspi_stop(2);
    rspi_hw_config(2,0);
    DAT_208001b4 = '\x01';
  }
  rspi_reset_buffers(2);
  rspi_start(2);
  rspi_write(2,param_1,param_2,0xff);
  rspi_wait_tx_end(2);
  rspi_stop(2);
  return;
}


// ===== sdr_spi_xfer_block @ 20110834 (456 bytes)

undefined4 sdr_spi_xfer_block(undefined4 param_1,undefined4 param_2,int param_3,ushort param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_128 [256];
  int local_28;
  
  memclr(auStack_128,0x100);
  iVar1 = FUN_20111174(0);
  iVar4 = iVar1 + 0x2000;
  local_28 = sfl_stream_read(iVar1,1,0x2000,param_2);
  if (local_28 != 0) {
    FUN_2015525c(iVar4,0x1000,0xff);
    hex_to_bin(iVar1,iVar4,local_28,0x1000);
    iVar1 = crc16_a001(0xffff,0x1000,iVar4);
    iVar3 = 0;
    do {
      iVar2 = sdr_set_flash_addr(param_1,param_4,param_3 * 0x1000 + 0x240000);
      if ((((iVar2 != -1) &&
           (iVar2 = sdr_reg_write(param_1,param_4 | 0x32,3,auStack_128), iVar2 != -1)) &&
          (iVar2 = sdr_wait_ready(param_1,param_4,1000), iVar2 != -1)) &&
         (iVar2 = sdr_reg_write(param_1,param_4 | 0x32,1,auStack_128), iVar2 != -1)) {
        sdr_spi_master_write(iVar4,0x1000);
        iVar2 = sdr_wait_ready(param_1,param_4,1000);
        if ((((iVar2 != -1) &&
             (iVar2 = sdr_reg_write(param_1,param_4 | 0x32,4,auStack_128), iVar2 != -1)) &&
            ((iVar2 = sdr_wait_ready(param_1,param_4,1000), iVar2 != -1 &&
             ((iVar2 = sdr_reg_write(param_1,param_4 | 0x32,5,auStack_128), iVar2 != -1 &&
              (iVar2 = sdr_wait_ready(param_1,param_4,1000), iVar2 != -1)))))) &&
           (local_28 = sdr_reg_read(param_1,param_4 | 0x33), local_28 == iVar1)) {
          return 1;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x1e);
  }
  return 0;
}


// ===== sdr_relay_mode_cmd @ 201109fc (188 bytes)

/* same F1 <code> frame (SDR 01/81) */

undefined4 sdr_relay_mode_cmd(int *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  
  iVar2 = 0;
  local_1c = (uint)CONCAT11(param_2,0xf1);
  local_18 = (uint)(byte)(param_2 - 0xf) << 0x18;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  while( true ) {
    itron_dly_tsk(1);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,&local_1c,8);
    if (iVar1 != 8) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_28,1,0xdc);
    if ((iVar1 != -1) && ((char)local_28 == '\x06')) break;
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return 0;
    }
  }
  return 1;
}


// ===== sdr_flash_write @ 20110ab8 (388 bytes)

/* streams the SDR image over SPI in 0x2000-byte blocks */

void sdr_flash_write(undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined1 auStack_3c [24];
  undefined1 auStack_24 [8];
  
  progress_range_init(auStack_24,5,99);
  progress_scale(auStack_24,extraout_r1,0,0);
  progress_set();
  sfl_stream_init(auStack_3c,param_1,0,param_2);
  mainlink_rx_ctrl(1);
  piVar1 = (int *)scif5_get(0);
  (**(code **)(*piVar1 + 4))(piVar1,0x54600,8,0,2);
  iVar2 = sdr_relay_mode_cmd(piVar1,1);
  if (iVar2 != 0) {
    if (param_3 == 0) {
      uVar5 = 0x1000;
    }
    else {
      uVar5 = 0;
    }
    uVar3 = FUN_20111174(0);
    iVar2 = sfl_stream_read(uVar3,1,0x2000,auStack_3c);
    if (iVar2 != 0) {
      crc16_a001_table_init();
      iVar2 = 0;
      do {
        uVar6 = FUN_20164d54(iVar2);
        uVar6 = FUN_201649d8((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x4080c000);
        uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
        progress_scale(auStack_24,uVar3,(int)uVar6,uVar3);
        progress_set();
        iVar4 = sdr_spi_xfer_block(piVar1,auStack_3c,iVar2,uVar5);
        if (iVar4 == 0) {
          return;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x218);
      if (param_2 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0x240;
      }
      iVar2 = fs_fseek(param_1,uVar3,0);
      if (iVar2 == 0) {
        progress_set(100);
        sfl_stream_init(auStack_3c,param_1,0,param_2);
        sdr_spi_xfer_block(piVar1,auStack_3c,0x240,uVar5);
      }
      sdr_relay_mode_cmd(piVar1,0x81);
    }
  }
  return;
}


// ===== sdr_debug_cmd @ 20110c3c (364 bytes)

/* sdrup/sdr1up/sdr2up/sdrchk*/sdrspi/sdrfile/delta */

void sdr_debug_cmd(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = hid_line_edit(&DAT_208193d8,param_1,param_2);
  if (iVar1 == 0) {
    return;
  }
  iVar2 = strcmp("sdrup",iVar1);
  if (iVar2 == 0) {
    uVar3 = 3;
LAB_20110cbc:
    itron_set_flg(DAT_208001b8,uVar3);
  }
  else {
    iVar2 = strcmp("sdr1up",iVar1);
    if (iVar2 == 0) {
      uVar3 = 1;
      goto LAB_20110cbc;
    }
    iVar2 = strcmp("sdr2up",iVar1);
    if (iVar2 == 0) {
      uVar3 = 2;
      goto LAB_20110cbc;
    }
    iVar2 = strcmp("sdrchk1",iVar1);
    if (iVar2 == 0) {
      uVar3 = 0x1001;
      goto LAB_20110cbc;
    }
  }
  iVar2 = strcmp("sdrup/g",iVar1);
  if (iVar2 == 0) {
    uVar3 = 0x103;
  }
  else {
    iVar2 = strcmp("sdr1up/g",iVar1);
    if (iVar2 == 0) {
      uVar3 = 0x101;
    }
    else {
      iVar2 = strcmp("sdr2up/g",iVar1);
      if (iVar2 == 0) {
        uVar3 = 0x102;
      }
      else {
        iVar2 = strcmp("sdrchk1/g",iVar1);
        if (iVar2 != 0) {
          iVar2 = strcmp("sdrchk2/g",iVar1);
          if (iVar2 == 0) {
            uVar3 = 0x3101;
            goto LAB_20110d7c;
          }
          iVar2 = strncmp("sdrspi",iVar1,6);
          if (iVar2 == 0) {
            memcpy(&DAT_208193b8,iVar1,0x20);
            uVar3 = 0x8000;
            goto LAB_20110d7c;
          }
          iVar2 = strcmp("sdrfile",iVar1);
          if (iVar2 != 0) {
            iVar1 = strcmp("delta",iVar1);
            if (iVar1 != 0) {
              return;
            }
            uVar3 = 0x10000;
            goto LAB_20110d7c;
          }
        }
        uVar3 = 0x1101;
      }
    }
  }
LAB_20110d7c:
  itron_set_flg(DAT_208001b8,uVar3);
  return;
}


// ===== sdr_debug_init @ 20110da8 (52 bytes)

/* chain-1 handler 7: registers sdr_debug_cmd, flag 0x208001B8 (no task waits on it) */

undefined8 sdr_debug_init(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10 = 2;
  uStack_c = 0;
  uStack_8 = 0;
  iVar1 = itron_acre_flg(0,&local_10);
  if (iVar1 < 1) {
    pcVar2 = (code *)0x0;
  }
  else {
    pcVar2 = sdr_debug_cmd;
    DAT_208001b8 = iVar1;
  }
  return CONCAT44(local_10,pcVar2);
}


// ===== FUN_20110e84 @ 20110e84 (12 bytes)

undefined4 FUN_20110e84(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
}


// ===== FUN_20110e90 @ 20110e90 (48 bytes)

int FUN_20110e90(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_20110e84();
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== FUN_20110ec0 @ 20110ec0 (20 bytes)

void FUN_20110ec0(undefined4 param_1)

{
  FUN_20110e90(param_1);
  return;
}


// ===== fwdbg_line @ 20110ed4 (56 bytes)

void fwdbg_line(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = hid_line_edit(&DAT_20819500,param_1,param_2);
  if (iVar1 != 0) {
    fwdbg_cmd(&DAT_208193fc,iVar1);
  }
  return;
}


// ===== loader_selfinstall @ 20110f0c (344 bytes)

/* if 0xFCFF400C == 0xAABBCCDD: writes this image (0x340000 B) to flash 0 and resets the bank flags
    */

undefined4 loader_selfinstall(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = DAT_fcff400c;
  if (iVar2 == -0x55443323) {
    iVar2 = spiflash_erase(0,0,0x340000);
    if (iVar2 == 0) {
      iVar2 = spiflash_erase(0,0x3e0000,0x14);
      if (iVar2 == 0) {
        iVar2 = spiflash_erase(0,0x3f0000,0x14);
        if (iVar2 == 0) {
          iVar2 = spiflash_write(0,vec_reset,0x340000);
          if (iVar2 == 0) {
            local_28 = 0;
            local_24 = 0;
            local_20 = 0;
            local_1c = 0;
            local_2c = &DAT_20182018;
            iVar2 = spiflash_write(0x3e0000,&local_2c,0x14);
            if (iVar2 == 0) {
              iVar2 = spiflash_write(0x3f0000,&local_2c,0x14);
              if (iVar2 == 0) {
                uVar1 = 0;
                DAT_fcff400c = 0;
                software_bkpt(0);
              }
              else {
                software_bkpt(4);
                uVar1 = 4;
              }
            }
            else {
              software_bkpt(3);
              uVar1 = 3;
            }
          }
          else {
            software_bkpt(2);
            uVar1 = 2;
          }
        }
        else {
          software_bkpt(1);
          uVar1 = 1;
        }
      }
      else {
        software_bkpt(1);
        uVar1 = 1;
      }
    }
    else {
      software_bkpt(1);
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fwdbg_init @ 20111064 (20 bytes)

/* registers fwdbg_line (fw1up/fw1chk/up0/up1/up2) */

code * fwdbg_init(void)

{
  fwdbg_task_create(&DAT_208193fc);
  return fwdbg_line;
}


// ===== debug_enabled @ 20111098 (28 bytes)

/* 0x20450000 == 0xA0B9C8E7 (0 in the shipped .data) */

bool debug_enabled(void)

{
  return DAT_20450000 == -0x5f463719;
}


// ===== adc_read_all @ 201110cc (144 bytes)

/* ADDRA..ADDRH (AN0..AN7) >> 4 */

void adc_read_all(uint *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar1 = DAT_e8005800;
  uVar2 = DAT_e8005802;
  uVar3 = DAT_e8005804;
  uVar4 = DAT_e8005806;
  DAT_20819530 = (uint)(uVar4 >> 4);
  uVar4 = DAT_e8005808;
  uVar5 = DAT_e800580a;
  uVar6 = DAT_e800580c;
  uVar7 = DAT_e800580e;
  DAT_20819524 = (uint)(uVar1 >> 4);
  DAT_20819528 = (uint)(uVar2 >> 4);
  DAT_2081952c = (uint)(uVar3 >> 4);
  DAT_20819534 = (uint)(uVar4 >> 4);
  DAT_20819538 = (uint)(uVar5 >> 4);
  DAT_2081953c = (uint)(uVar6 >> 4);
  DAT_20819540 = (uint)(uVar7 >> 4);
  param_1[3] = DAT_20819530;
  param_1[4] = (uint)(uVar4 >> 4);
  param_1[6] = (uint)(uVar6 >> 4);
  param_1[7] = (uint)(uVar7 >> 4);
  param_1[5] = (uint)(uVar5 >> 4);
  param_1[2] = (uint)(uVar3 >> 4);
  *param_1 = (uint)(uVar1 >> 4);
  param_1[1] = (uint)(uVar2 >> 4);
  return;
}


// ===== adc_start_scan @ 2011115c (16 bytes)

/* ADCSR = 0x20FF (start, continuous scan) */

void adc_start_scan(void)

{
  DAT_e8005860 = 0x20ff;
  return;
}


// ===== FUN_20111174 @ 20111174 (52 bytes)

undefined * FUN_20111174(int param_1)

{
  if (param_1 < 0) {
    memclr(&DAT_20819560,0xc0000);
  }
  else if (param_1 != 0) {
    memclr(&DAT_20819560,param_1);
  }
  return &DAT_20819560;
}


// ===== FUN_201111c8 @ 201111c8 (12 bytes)

undefined4 FUN_201111c8(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
}


// ===== FUN_201111d4 @ 201111d4 (48 bytes)

int FUN_201111d4(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_201111c8();
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== FUN_20111204 @ 20111204 (20 bytes)

void FUN_20111204(undefined4 param_1)

{
  FUN_201111d4(param_1);
  return;
}


// ===== kbd_set_current @ 20111218 (12 bytes)

/* keyboard device used for the LED status */

void kbd_set_current(undefined4 param_1)

{
  DAT_208001c8 = param_1;
  return;
}


// ===== kbd_led_status @ 20111224 (76 bytes)

/* set the 3 keyboard LEDs (value, mask): debug progress display */

void kbd_led_status(byte param_1,byte param_2)

{
  DAT_2080010c = DAT_2080010c & ~(param_2 & 7) | param_1 & 7;
  FUN_2013baac(DAT_208001c8,0,&DAT_2080010c);
  itron_dly_tsk(1);
  return;
}


// ===== FUN_20111270 @ 20111270 (68 bytes)

void FUN_20111270(byte param_1,byte param_2)

{
  DAT_2080010c = DAT_2080010c & ~(param_2 & 7) | param_1 & 7;
  FUN_2013baac(DAT_208001c8,0,&DAT_2080010c);
  return;
}


// ===== hex_parse @ 201112b4 (192 bytes)

/* up to n hex digits */

uint hex_parse(byte *param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  uVar1 = 0;
  *param_3 = param_1;
  for (iVar3 = 0; pbVar4 = param_1, iVar3 < param_2; iVar3 = iVar3 + 1) {
    pbVar4 = param_1 + 1;
    uVar2 = (uint)*param_1;
    if (uVar2 == 0) break;
    if ((uVar2 < 0x30) || (0x39 < uVar2)) {
      if ((uVar2 < 0x41) || (0x46 < uVar2)) {
        if ((uVar2 < 0x61) || (0x66 < uVar2)) {
          *param_3 = param_1;
          return uVar1;
        }
        uVar1 = uVar1 << 4 | uVar2 - 0x57;
      }
      else {
        uVar1 = uVar1 << 4 | uVar2 - 0x37;
      }
    }
    else {
      uVar1 = uVar1 << 4 | uVar2 - 0x30;
    }
    param_1 = pbVar4;
  }
  *param_3 = pbVar4;
  return uVar1;
}


// ===== FUN_20111374 @ 20111374 (132 bytes)

int FUN_20111374(byte *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar1 = 0;
  *param_3 = param_1;
  for (iVar3 = 0; pbVar4 = param_1, iVar3 < param_2; iVar3 = iVar3 + 1) {
    pbVar4 = param_1 + 1;
    uVar2 = (uint)*param_1;
    if (uVar2 == 0) break;
    if ((uVar2 < 0x30) || (0x39 < uVar2)) {
      *param_3 = param_1;
      return iVar1;
    }
    iVar1 = iVar1 * 10 + (uVar2 - 0x30);
    param_1 = pbVar4;
  }
  *param_3 = pbVar4;
  return iVar1;
}


// ===== mainlink_trace_toggle @ 20111410 (88 bytes)

/* USB-keyboard key: trace on/off, buffer = frame-buffer layer 4 */

void mainlink_trace_toggle(void)

{
  DAT_208001d4 = DAT_208001d4 ^ 1;
  if (DAT_208001d4 == 0) {
    DAT_208001d5 = 0;
    DAT_208001dc = 0;
    DAT_208001e0 = 0;
  }
  DAT_208001d8 = fb_get_layer_addr(4);
  return;
}


// ===== mainlink_trace_pause @ 20111468 (24 bytes)

/* F7: toggle recording */

void mainlink_trace_pause(void)

{
  DAT_208001d5 = DAT_208001d5 ^ 1;
  return;
}


// ===== mainlink_trace @ 20111480 (268 bytes)

/* ring log (2048 x 256 B at *0x208001D8) of every frame sent and received, with timestamp */

void mainlink_trace(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  
  uVar1 = DAT_208001cc;
  if (((DAT_208001d8 != 0) && (DAT_208001d5 != '\0')) && (DAT_208001d6 == '\0')) {
    if (0xfb < param_2) {
      param_2 = 0xfc;
    }
    puVar2 = (undefined1 *)(DAT_208001d8 + DAT_208001dc * 0x100);
    local_18 = (undefined1)DAT_208001cc;
    *puVar2 = local_18;
    uStack_17 = (undefined1)((uint)uVar1 >> 8);
    puVar2[1] = uStack_17;
    uStack_16 = (undefined1)((uint)uVar1 >> 0x10);
    puVar2[2] = uStack_16;
    uStack_15 = (undefined1)((uint)uVar1 >> 0x18);
    puVar2[3] = uStack_15;
    memcpy(DAT_208001d8 + DAT_208001dc * 0x100 + 4,param_1,param_2);
    DAT_208001dc = DAT_208001dc + 1 & 0x7ff;
    if (DAT_208001e0 < 0x800) {
      DAT_208001e0 = DAT_208001e0 + 1;
    }
  }
  return;
}


// ===== mainlink_trace_dump @ 2011158c (444 bytes)

/* writes the ring to I:\debug_1.log */

void mainlink_trace_dump(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 auStack_380 [68];
  int local_33c;
  undefined1 auStack_338 [788];
  
  uVar1 = DAT_208001e0;
  if (DAT_208001d8 != 0) {
    DAT_208001d6 = 1;
    if (DAT_208001e0 != 0) {
      uVar2 = DAT_208001dc;
      if (DAT_208001e0 < 0x800) {
        uVar2 = 0;
      }
      sprintf(auStack_380,"I:\\debug_1.log");
      local_33c = fs_fopen(auStack_380,&DAT_2011177c);
      if (local_33c != 0) {
        iVar4 = 0;
        for (uVar8 = 0; uVar8 < uVar1; uVar8 = uVar8 + 1) {
          uVar10 = 0x2f4;
          piVar7 = (int *)(DAT_208001d8 + uVar2 * 0x100);
          uVar2 = uVar2 + 1 & 0x7ff;
          iVar9 = *piVar7;
          sprintf(auStack_338,"%-6d: ",iVar9 - iVar4);
          uVar3 = FUN_20155122(auStack_338);
          iVar4 = fs_fwrite(auStack_338,1,uVar3,local_33c,uVar10);
          iVar5 = FUN_20155122(auStack_338);
          if (iVar5 != iVar4) break;
          for (uVar6 = 0; uVar6 < 0xfc; uVar6 = uVar6 + 1) {
            sprintf(auStack_338 + uVar6 * 3,"%02X ",*(undefined1 *)((int)piVar7 + uVar6 + 4));
          }
          iVar4 = fs_fwrite(auStack_338,1,0x2f4,local_33c);
          if ((iVar4 != 0x2f4) || (iVar4 = fs_fwrite(&DAT_20111790,1,2,local_33c), iVar4 != 2))
          break;
          iVar4 = iVar9;
        }
        FUN_20141ff0(local_33c);
      }
    }
    DAT_208001d6 = 0;
  }
  return;
}


// ===== task_keycode @ 20111794 (768 bytes)

void task_keycode(void)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uStack_18;
  undefined1 auStack_14 [4];
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  int iStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  do {
    do {
      while( true ) {
        do {
          uStack_18 = 0xffffffff;
          itron_twai_flg(DAT_208001d0,0xffff,5,&uStack_4);
        } while (uStack_4 == 1);
        if (uStack_4 == 2) break;
        if (uStack_4 == 4) {
          puStack_8 = &DAT_208d9960;
          iVar2 = FUN_2014e320(&DAT_208d9960," ",&puStack_8);
          if ((iVar2 != 0) && (iVar2 = strcmp(iVar2,&DAT_20111aa4), iVar2 == 0)) {
            iVar2 = FUN_2014e320(puStack_8," ",&puStack_8);
            if (iVar2 == 0) {
              rtc_get_time(&uStack_10,auStack_14,&uStack_18);
            }
            else {
              uVar3 = hex_parse(iVar2,6,&iStack_c);
              if (iStack_c != iVar2) {
                rtc_set_time((uVar3 & 0xffffff) >> 0x10,(uVar3 & 0xffff) >> 8,uVar3 & 0xff);
              }
            }
          }
        }
        else if (uStack_4 == 8) {
          puStack_8 = &DAT_208d9960;
          iVar2 = FUN_2014e320(&DAT_208d9960," ",&puStack_8);
          if ((((iVar2 != 0) && (iVar2 = strcmp(iVar2,&DAT_20111aac), iVar2 == 0)) &&
              (iVar2 = FUN_2014e320(puStack_8," ",&puStack_8), iVar2 != 0)) &&
             ((uVar1 = hex_parse(iVar2,2,&iStack_c), iStack_c != iVar2 &&
              (iVar2 = FUN_2014e320(puStack_8," ",&puStack_8), iVar2 != 0)))) {
            uVar3 = hex_parse(iVar2,4,&iStack_c);
            if (iStack_c != iVar2) {
              uStack_f = (undefined1)(uVar3 & 0xffff);
              uStack_e = (undefined1)((uVar3 & 0xffff) >> 8);
              uStack_10 = uVar1;
              uart4_send(&uStack_10,3);
            }
          }
        }
        else if ((uStack_4 & 0xe000) != 0) {
          if ((uStack_4 & 0x2000) != 0) {
            mainlink_trace_toggle();
          }
          if (uStack_4 == 0x4000) {
            mainlink_trace_pause();
          }
          if (uStack_4 == 0x8000) {
            mainlink_trace_dump();
          }
        }
      }
      puStack_8 = &DAT_208d9960;
      iVar2 = FUN_2014e320(&DAT_208d9960," ",&puStack_8);
    } while ((iVar2 == 0) || (iVar2 = strcmp(iVar2,"date"), iVar2 != 0));
    iVar2 = FUN_2014e320(puStack_8," ",&puStack_8);
    if (iVar2 == 0) {
      rtc_get_date(&uStack_10,auStack_14,&uStack_18);
    }
    else {
      uVar3 = hex_parse(iVar2,6,&iStack_c);
      if (iStack_c != iVar2) {
        rtc_set_date((uVar3 & 0xffffff) >> 0x10,(uVar3 & 0xffff) >> 8,uVar3 & 0xff);
      }
    }
  } while( true );
}


// ===== keycode_line @ 20111ab0 (1368 bytes)

/* F1..F12 toggle debug bits 0x20808A84; date, time, dsp, reset, wdr, sndc */

void keycode_line(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_2 + 0xc);
  if ((cVar1 != '\0') || (*(char *)(param_2 + 5) != '\0')) {
    iVar2 = hid_line_edit(&DAT_208d9980,param_1,param_2);
    if (cVar1 == ':') {
      if ((DAT_20808a84 & 1) == 0) {
        DAT_20808a84 = DAT_20808a84 | 1;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffffe;
      }
    }
    else if (cVar1 == ';') {
      if ((DAT_20808a84 & 2) == 0) {
        DAT_20808a84 = DAT_20808a84 | 2;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffffd;
      }
    }
    else if (cVar1 == '<') {
      if ((DAT_20808a84 & 4) == 0) {
        DAT_20808a84 = DAT_20808a84 | 4;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffffb;
      }
    }
    else if (cVar1 == '=') {
      if ((DAT_20808a84 & 8) == 0) {
        DAT_20808a84 = DAT_20808a84 | 8;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffff7;
      }
    }
    else if (cVar1 == '>') {
      if ((DAT_20808a84 & 0x10) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x10;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xffffffef;
      }
    }
    else if (cVar1 == '?') {
      if ((DAT_20808a84 & 0x20) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x20;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xffffffdf;
      }
      itron_set_flg(DAT_208001d0,0x2000);
    }
    else if (cVar1 == '@') {
      if ((DAT_20808a84 & 0x40) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x40;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xffffffbf;
      }
      itron_set_flg(DAT_208001d0,0x4000);
    }
    else if (cVar1 == 'A') {
      if ((DAT_20808a84 & 0x80) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x80;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xffffff7f;
      }
      itron_set_flg(DAT_208001d0,0x8000);
    }
    else if (cVar1 == 'B') {
      if ((DAT_20808a84 & 0x100) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x100;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffeff;
      }
    }
    else if (cVar1 == 'C') {
      if ((DAT_20808a84 & 0x200) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x200;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffdff;
      }
    }
    else if (cVar1 == 'D') {
      if ((DAT_20808a84 & 0x400) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x400;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffbff;
      }
    }
    else if (cVar1 == 'E') {
      if ((DAT_20808a84 & 0x800) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x800;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffff7ff;
      }
    }
    else if ((iVar2 == 0) || (iVar3 = strncmp("date",iVar2,4), iVar3 != 0)) {
      if ((iVar2 == 0) || (iVar3 = strncmp(&DAT_20112018,iVar2,4), iVar3 != 0)) {
        if ((iVar2 == 0) || (iVar3 = strncmp(&DAT_20112020,iVar2,4), iVar3 != 0)) {
          if ((iVar2 == 0) || (iVar3 = strcmp("reset",iVar2), iVar3 != 0)) {
            if ((iVar2 == 0) || (iVar3 = strcmp(&DAT_20112030,iVar2), iVar3 != 0)) {
              if ((iVar2 != 0) && (iVar2 = strncmp(&DAT_20112034,iVar2,4), iVar2 == 0)) {
                iVar2 = test_disp_state();
                if (iVar2 == 2) {
                  test_disp_start();
                }
                else {
                  test_disp_stop();
                }
              }
            }
            else {
              wdt_system_reset();
            }
          }
          else {
            system_reboot();
          }
        }
        else {
          memcpy(&DAT_208d9960,iVar2,0x20);
          itron_set_flg(DAT_208001d0,8);
        }
      }
      else {
        memcpy(&DAT_208d9960,iVar2,0x20);
        itron_set_flg(DAT_208001d0,4);
      }
    }
    else {
      memcpy(&DAT_208d9960,iVar2,0x20);
      itron_set_flg(DAT_208001d0,2);
    }
  }
  return;
}


// ===== keycode_init @ 2011203c (120 bytes)

/* task "keycode" */

code * keycode_init(void)

{
  code *pcVar1;
  int iVar2;
  
  DAT_208001d0 = itron_acre_flg(0,&DAT_20165548);
  if (DAT_208001d0 < 1) {
    pcVar1 = (code *)0x0;
  }
  else {
    iVar2 = itron_acre_tsk(0,&DAT_2016552c);
    if (iVar2 < 1) {
      pcVar1 = (code *)0x0;
    }
    else {
      iVar2 = itron_sta_tsk(iVar2,0);
      if (iVar2 == 0) {
        pcVar1 = keycode_line;
      }
      else {
        pcVar1 = (code *)0x0;
      }
    }
  }
  return pcVar1;
}


// ===== cycle_delta @ 201120c8 (48 bytes)

/* PMCCNTR delta */

int cycle_delta(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== pclink_tx_set_status @ 201120fc (16 bytes)

/* 151 B MAIN status */

void pclink_tx_set_status(undefined4 param_1)

{
  memcpy(&DAT_60501b64,param_1,0x97);
  return;
}


// ===== pclink_tx_copy_afscope @ 2011210c (28 bytes)

/* 600 B */

void pclink_tx_copy_afscope(void)

{
  undefined4 uVar1;
  
  uVar1 = afscope_buf_ptr();
  memcpy(&DAT_605016a4,uVar1,600);
  return;
}


// ===== pclink_tx_copy_scope @ 20112128 (28 bytes)

/* 850 B */

void pclink_tx_copy_scope(void)

{
  undefined4 uVar1;
  
  uVar1 = scope_frame_buf();
  memcpy(&DAT_60501000,uVar1,0x352);
  return;
}


// ===== pclink_tx_trailer_init @ 20112144 (20 bytes)

/* 0x01EE01FF x4 */

void pclink_tx_trailer_init(void)

{
  DAT_60501ff0 = 0x1ee01ff;
  DAT_60501ff4 = 0x1ee01ff;
  DAT_60501ff8 = 0x1ee01ff;
  DAT_60501ffc = 0x1ee01ff;
  return;
}


// ===== pclink_tx_dma_start @ 20112158 (60 bytes)

/* DMA ch9 0x60501000 -> SPDR0, 0x1000 */

void pclink_tx_dma_start(void)

{
  DAT_e8200440 = &DAT_60501000;
  DAT_e8200444 = 0xe800c804;
  DAT_e8200448 = 0x1000;
  FUN_20157160(&DAT_e8200468,1,0);
  return;
}


// ===== pclink_tx_done_cb @ 20112180 (40 bytes)

void pclink_tx_done_cb(void)

{
  cycle_delta(&DAT_2045d490);
  DAT_20450014 = DAT_20450014 + 1;
  dmac9_stop();
  pclink_tx_dma_start();
  return;
}


// ===== pclink_set_testmode @ 201121a8 (12 bytes)

/* 0x20450004: SDR SPI test overlay (key combo 4 at power-on) */

void pclink_set_testmode(undefined4 param_1)

{
  DAT_20450004 = param_1;
  return;
}


// ===== pclink_rx_parse @ 201121b4 (128 bytes)

/* magic 0xEEAFCCBA */

void pclink_rx_parse(void)

{
  int iVar1;
  undefined4 local_10;
  
  local_10 = 0xeeafccba;
  iVar1 = FUN_2015507c(&DAT_60500000,&local_10,4);
  if (iVar1 != 0) {
    DAT_2045d4ac = DAT_2045d4ac + 1;
    return;
  }
  DAT_2045d4a8 = DAT_2045d4a8 + 1;
  DAT_2045d4b4 = DAT_60500000;
  DAT_2045d4b8 = DAT_60500004;
  DAT_2045d4bc = DAT_60500008;
  DAT_2045d4c0 = DAT_6050000c;
  DAT_2045d4c4 = DAT_60500010;
  DAT_2045d4c8 = DAT_60500014;
  DAT_2045d4cc = DAT_60500018;
  DAT_2045d4d0 = DAT_6050001c;
  DAT_2045d4dc = DAT_60500028;
  DAT_2045d4d4 = DAT_60500020;
  DAT_2045d4d8 = DAT_60500024;
  return;
}


// ===== pclink_rx_done_cb @ 20112264 (36 bytes)

void pclink_rx_done_cb(void)

{
  pclink_rx_parse();
  DAT_20450018 = DAT_20450018 + 1;
  dmac10_stop();
  dmac10_enable();
  return;
}


// ===== task_spi_slave @ 20112288 (456 bytes)

void task_spi_slave(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  dmac9_register_isr();
  dmac9_stop();
  dmac9_rspi_tx_setup(1,0,0);
  dmac9_set_callback(pclink_tx_done_cb);
  rspi_hw_config(0,1);
  rspi_reset_buffers(0);
  rspi_start(0);
  pclink_tx_dma_start();
  iVar6 = DAT_20450014;
  iVar5 = 0;
  bVar1 = true;
  iVar4 = 0;
  bVar2 = false;
  pclink_tx_trailer_init();
  do {
    do {
      itron_dly_tsk(1);
      if ((!bVar2) && (DAT_20450004 != 0)) {
        bVar2 = true;
        dmac10_register_isr();
        dmac10_set_callback(pclink_rx_done_cb);
        dmac9_stop();
        dmac10_stop();
        rspi_stop(0);
        rspi_reset_buffers(0);
        dmac9_rspi_tx_setup(1,0,0);
        dmac10_rspi_rx_setup(1,&DAT_e800c804,&DAT_60500000,0x1000);
        DAT_2045d4a8 = 0;
        DAT_2045d4ac = 0;
        DAT_2045d4b0 = 0;
        dmac10_enable();
        pclink_tx_dma_start();
        itron_dly_tsk(0x32);
        rspi_start(0);
      }
      iVar4 = iVar4 + 1;
      if (iVar4 == 4) {
        cycle_delta(&DAT_2045d498);
        iVar4 = 0;
        pclink_tx_copy_afscope();
        pclink_tx_copy_scope();
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x32);
    cycle_delta(&DAT_2045d4a0);
    iVar3 = DAT_20450014;
    iVar5 = 0;
    bVar7 = iVar6 != DAT_20450014;
    if (bVar7) {
      bVar1 = false;
    }
    iVar6 = iVar3;
    if (!bVar7 && !bVar1) {
      bVar1 = true;
      dmac9_stop();
      if (bVar2) {
        dmac10_stop();
      }
      rspi_stop(0);
      rspi_reset_buffers(0);
      dmac9_rspi_tx_setup(1,0,0);
      if (bVar2) {
        dmac10_rspi_rx_setup(1,&DAT_e800c804,&DAT_60500000,0x1000);
        DAT_2045d4a8 = 0;
        DAT_2045d4ac = 0;
        DAT_2045d4b0 = 0;
        dmac10_enable();
      }
      pclink_tx_dma_start();
      rspi_start(0);
    }
  } while( true );
}


// ===== spi_slave_init @ 20112450 (40 bytes)

/* task "spi_slave_task" */

void spi_slave_init(void)

{
  int iVar1;
  
  iVar1 = itron_acre_tsk(0,&DAT_20165554);
  if (0 < iVar1) {
    itron_sta_tsk(iVar1,0);
    return;
  }
  return;
}


// ===== FUN_20112478 @ 20112478 (36 bytes)

void FUN_20112478(void)

{
  gui_draw_text();
  return;
}


// ===== pclink_stats_print @ 2011249c (572 bytes)

/* replaces sdr_spi_stats_print: FT4222H link test-mode box */

void pclink_stats_print(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_a0 [128];
  
  if (DAT_20450004 != 0) {
    uVar2 = 0x400;
    iVar1 = gpio_read_bit(2,0xd);
    if (DAT_20450008 != iVar1) {
      DAT_2045d4b0 = DAT_2045d4b0 + 1;
    }
    if ((((DAT_2045d4a8 == 0) || (DAT_2045d4ac != 0)) || (DAT_2045d4bc == 0)) ||
       ((DAT_2045d4c0 != 0 || (DAT_2045d4b0 == 0)))) {
      uVar2 = 0xc800;
    }
    DAT_20450008 = iVar1;
    fb_fill_rect(param_1,uVar2,0x104,600,200,0xaf);
    DAT_20450010 = DAT_20450010 + 1;
    if (DAT_20450010 == 0x14) {
      DAT_20450010 = 0;
      DAT_2045000c = DAT_2045d490;
    }
    sprintf(auStack_a0,"testmode");
    FUN_20112478(param_1,auStack_a0,0x109,0x25d);
    sprintf(auStack_a0," CS_POLL=%u\n",DAT_2045d4b0);
    FUN_20112478(param_1,auStack_a0,0x11d,0x25d);
    sprintf(auStack_a0," MOSI_OK=%u",DAT_2045d4a8);
    FUN_20112478(param_1,auStack_a0,0x131,0x25d);
    sprintf(auStack_a0," MOSI_NG=%u",DAT_2045d4ac);
    FUN_20112478(param_1,auStack_a0,0x145,0x25d);
    sprintf(auStack_a0," FRAMES =%u",DAT_2045d4b8);
    FUN_20112478(param_1,auStack_a0,0x163,0x25d);
    sprintf(auStack_a0," MISO_OK=%u",DAT_2045d4bc);
    FUN_20112478(param_1,auStack_a0,0x177,0x25d);
    sprintf(auStack_a0," MISO_NG=%u",DAT_2045d4c0);
    FUN_20112478(param_1,auStack_a0,0x18b,0x25d);
    sprintf(auStack_a0," msec=%u",(uint)(DAT_2045000c * 1000) / 6000000);
    FUN_20112478(param_1,auStack_a0,0x19f,0x25d);
  }
  return;
}


// ===== renc_rec_set @ 2011275c (24 bytes)

/* record 0x208D99A4 + id*5 = {id, delta/value} */

void renc_rec_set(int param_1,undefined1 param_2)

{
  (&DAT_208d99a4)[param_1 * 5] = (char)param_1;
  (&DAT_208d99a5)[param_1 * 5] = param_2;
  return;
}


// ===== task_renc @ 20112774 (96 bytes)

void task_renc(void)

{
  int iVar1;
  int iStack_4;
  
  do {
    do {
      do {
        iVar1 = itron_twai_flg(DAT_208001f8,1,5,&iStack_4,0xffffffff);
      } while (iVar1 != 0);
    } while (iStack_4 != 1);
    if (DAT_20800495 != '\0') {
      mainlink_renc_event(&DAT_208d99b3);
    }
    gic_enable_irq(0x24);
  } while( true );
}


// ===== renc_poll_mtu1 @ 201127d4 (92 bytes)

/* MTU2 ch1 TCNT (0xFCFF0386) delta -> encoder id 1 */

void renc_poll_mtu1(void)

{
  DAT_208001fc = DAT_fcff0386;
  if (DAT_208001fc != DAT_208001fe) {
    renc_rec_set(1,(int)(char)((char)DAT_208001fc - (char)DAT_208001fe));
    DAT_208001fe = DAT_208001fc;
    if (DAT_20800495 != '\0') {
      mainlink_renc_event(&DAT_208d99a9);
      return;
    }
  }
  return;
}


// ===== renc_poll_mtu2 @ 20112830 (100 bytes)

/* MTU2 ch2 TCNT (0xFCFF0006) delta -> encoder id 2 */

void renc_poll_mtu2(void)

{
  DAT_20800202 = Ramfcff0006;
  if (DAT_20800202 != DAT_20800204) {
    renc_rec_set(2,(int)(char)((char)DAT_20800202 - (char)DAT_20800204));
    DAT_20800204 = DAT_20800202;
    DAT_20808536 = DAT_20800202;
    if (DAT_20800495 != '\0') {
      mainlink_renc_event(&DAT_208d99ae);
      return;
    }
  }
  return;
}


// ===== adc_ring_average @ 20112894 (76 bytes)

/* average of the ad renc ring buffer (returns double) */

undefined8 adc_ring_average(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = 0;
  iVar5 = 0;
  if (0 < DAT_208001f4) {
    do {
      iVar1 = iVar5 * 2;
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + (uint)*(ushort *)(param_1 + iVar1);
    } while (iVar5 < DAT_208001f4);
  }
  uVar3 = __aeabi_uidivmod(iVar2);
  uVar6 = uVar3 & 0x80000000;
  if ((int)uVar6 < 0) {
    uVar3 = -uVar3;
  }
  uVar4 = uVar3 << LZCOUNT(uVar3);
  if (uVar4 == 0) {
    return 0;
  }
  return CONCAT44(uVar6 + (0x41d - LZCOUNT(uVar3)) * 0x100000 + (uVar4 >> 0xb),uVar4 << 0x15);
}

