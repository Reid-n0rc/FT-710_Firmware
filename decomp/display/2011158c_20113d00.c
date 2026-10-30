// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== mainlink_trace_dump @ 2011158c (444 bytes)

/* writes the ring to I:\debug_1.log */

void mainlink_trace_dump(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_380 [68];
  uint local_33c;
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
      local_33c = fs_fopen((uint)auStack_380,0x2011177c);
      if (local_33c != 0) {
        iVar7 = 0;
        for (uVar6 = 0; uVar6 < uVar1; uVar6 = uVar6 + 1) {
          piVar5 = (int *)(DAT_208001d8 + uVar2 * 0x100);
          uVar2 = uVar2 + 1 & 0x7ff;
          iVar8 = *piVar5;
          sprintf(auStack_338,"%-6d: ",iVar8 - iVar7);
          uVar3 = strlen(auStack_338);
          uVar3 = fs_fwrite((uint)auStack_338,1,uVar3,local_33c);
          uVar4 = strlen(auStack_338);
          if (uVar4 != uVar3) break;
          for (uVar3 = 0; uVar3 < 0xfc; uVar3 = uVar3 + 1) {
            sprintf(auStack_338 + uVar3 * 3,"%02X ",*(undefined1 *)((int)piVar5 + uVar3 + 4));
          }
          uVar3 = fs_fwrite((uint)auStack_338,1,0x2f4,local_33c);
          if ((uVar3 != 0x2f4) || (uVar3 = fs_fwrite(0x20111790,1,2,local_33c), uVar3 != 2)) break;
          iVar7 = iVar8;
        }
        fs_fclose(local_33c);
      }
    }
    DAT_208001d6 = 0;
  }
  return;
}


// ===== task_keycode @ 20111794 (768 bytes)

void task_keycode(void)

{
  ushort uVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  byte *pbVar5;
  undefined1 auStack_14 [4];
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  byte *pbStack_c;
  undefined *puStack_8;
  uint uStack_4;
  
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          do {
            itron_twai_flg(DAT_208001d0,0xffff,5,&uStack_4,-1);
          } while (uStack_4 == 1);
          if (uStack_4 != 2) break;
          puStack_8 = &DAT_208d9960;
          puVar3 = (uint *)strtok_r(&DAT_208d9960," ",&puStack_8);
          if ((puVar3 != (uint *)0x0) && (uVar4 = strcmp(puVar3,(uint *)0x20111a9c), uVar4 == 0)) {
            pbVar5 = (byte *)strtok_r(puStack_8," ",&puStack_8);
            if (pbVar5 == (byte *)0x0) {
              rtc_get_date(&uStack_10,auStack_14,&stack0xffffffe8);
            }
            else {
              uVar1 = hex_parse(pbVar5,6,&pbStack_c);
              if (pbStack_c != pbVar5) {
                rtc_set_date(0,(byte)(uVar1 >> 8),(byte)uVar1);
              }
            }
          }
        }
        if (uStack_4 != 4) break;
        puStack_8 = &DAT_208d9960;
        puVar3 = (uint *)strtok_r(&DAT_208d9960," ",&puStack_8);
        if ((puVar3 != (uint *)0x0) && (uVar4 = strcmp(puVar3,(uint *)"time"), uVar4 == 0)) {
          pbVar5 = (byte *)strtok_r(puStack_8," ",&puStack_8);
          if (pbVar5 == (byte *)0x0) {
            rtc_get_time(&uStack_10,auStack_14,&stack0xffffffe8);
          }
          else {
            uVar1 = hex_parse(pbVar5,6,&pbStack_c);
            if (pbStack_c != pbVar5) {
              rtc_set_time(0,(byte)(uVar1 >> 8),(byte)uVar1);
            }
          }
        }
      }
      if (uStack_4 != 8) break;
      puStack_8 = &DAT_208d9960;
      puVar3 = (uint *)strtok_r(&DAT_208d9960," ",&puStack_8);
      if (((puVar3 != (uint *)0x0) && (uVar4 = strcmp(puVar3,(uint *)0x20111aac), uVar4 == 0)) &&
         (pbVar5 = (byte *)strtok_r(puStack_8," ",&puStack_8), pbVar5 != (byte *)0x0)) {
        uVar1 = hex_parse(pbVar5,2,&pbStack_c);
        if (((pbStack_c != pbVar5) &&
            (pbVar5 = (byte *)strtok_r(puStack_8," ",&puStack_8), pbVar5 != (byte *)0x0)) &&
           (uVar2 = hex_parse(pbVar5,4,&pbStack_c), pbStack_c != pbVar5)) {
          uStack_f = (undefined1)uVar2;
          uStack_e = (undefined1)(uVar2 >> 8);
          uStack_10 = (char)uVar1;
          uart4_send((uint)&uStack_10,3);
        }
      }
    }
    if ((uStack_4 & 0xe000) != 0) {
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
  } while( true );
}


// ===== keycode_line @ 20111ab0 (1368 bytes)

/* F1..F12 toggle debug bits 0x20808A84; date, time, dsp, reset, wdr, sndc */

void keycode_line(undefined4 param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  
  cVar1 = *(char *)(param_2 + 0xc);
  if ((cVar1 != '\0') || (*(char *)(param_2 + 5) != '\0')) {
    puVar3 = (uint *)hid_line_edit(&DAT_208d9980,param_1,param_2);
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
    else if ((puVar3 == (uint *)0x0) ||
            (iVar4 = strncmp((byte *)0x20112010,(byte *)puVar3,4), iVar4 != 0)) {
      if ((puVar3 == (uint *)0x0) || (iVar4 = strncmp((byte *)"time",(byte *)puVar3,4), iVar4 != 0))
      {
        if ((puVar3 == (uint *)0x0) ||
           (iVar4 = strncmp((byte *)0x20112020,(byte *)puVar3,4), iVar4 != 0)) {
          if ((puVar3 == (uint *)0x0) || (uVar5 = strcmp((uint *)"reset",puVar3), uVar5 != 0)) {
            if ((puVar3 == (uint *)0x0) || (uVar5 = strcmp((uint *)0x20112030,puVar3), uVar5 != 0))
            {
              if ((puVar3 != (uint *)0x0) &&
                 (iVar4 = strncmp((byte *)0x20112034,(byte *)puVar3,4), iVar4 == 0)) {
                bVar2 = test_disp_state();
                if (bVar2 == 2) {
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
          memcpy(&DAT_208d9960,puVar3,0x20);
          itron_set_flg(DAT_208001d0,8);
        }
      }
      else {
        memcpy(&DAT_208d9960,puVar3,0x20);
        itron_set_flg(DAT_208001d0,4);
      }
    }
    else {
      memcpy(&DAT_208d9960,puVar3,0x20);
      itron_set_flg(DAT_208001d0,2);
    }
  }
  return;
}


// ===== keycode_init @ 2011203c (120 bytes)

/* task "keycode" */

void * keycode_init(void)

{
  code *pcVar1;
  uint uVar2;
  
  DAT_208001d0 = itron_acre_flg(0,&cflg_keycode);
  if ((int)DAT_208001d0 < 1) {
    pcVar1 = (code *)0x0;
  }
  else {
    uVar2 = itron_acre_tsk(0,&ctsk_keycode);
    if ((int)uVar2 < 1) {
      pcVar1 = (code *)0x0;
    }
    else {
      uVar2 = itron_sta_tsk(uVar2,0);
      if (uVar2 == 0) {
        pcVar1 = keycode_line;
      }
      else {
        pcVar1 = (code *)0x0;
      }
    }
  }
  return pcVar1;
}


// ===== FUN_201120c0 @ 201120c0 (8 bytes)

undefined4 FUN_201120c0(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
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

void pclink_tx_set_status(uint param_1)

{
  memcpy(&DAT_60501b64,param_1,0x97);
  return;
}


// ===== pclink_tx_copy_afscope @ 2011210c (28 bytes)

/* 600 B */

void pclink_tx_copy_afscope(void)

{
  uint uVar1;
  
  uVar1 = afscope_buf_ptr();
  memcpy(&DAT_605016a4,uVar1,600);
  return;
}


// ===== pclink_tx_copy_scope @ 20112128 (28 bytes)

/* 850 B */

void pclink_tx_copy_scope(void)

{
  void *pvVar1;
  
  pvVar1 = scope_frame_buf();
  memcpy(&DAT_60501000,pvVar1,0x352);
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
  DMAC_N0SA_9 = &DAT_60501000;
  DMAC_N0DA_9 = 0xe800c804;
  DMAC_N0TB_9 = 0x1000;
  reg_rmw32(&DMAC_CHCTRL_9,1,0);
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

void pclink_set_testmode(uint param_1)

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
  iVar1 = memcmp(&DAT_60500000,&local_10,4);
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
  dmac9_rspi_tx_setup(1);
  dmac9_set_callback((uint)pclink_tx_done_cb);
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
        dmac10_set_callback((uint)pclink_rx_done_cb);
        dmac9_stop();
        dmac10_stop();
        rspi_stop(0);
        rspi_reset_buffers(0);
        dmac9_rspi_tx_setup(1);
        dmac10_rspi_rx_setup(1,0xe800c804,0x60500000,0x1000);
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
      dmac9_rspi_tx_setup(1);
      if (bVar2) {
        dmac10_rspi_rx_setup(1,0xe800c804,0x60500000,0x1000);
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
  uint uVar1;
  
  uVar1 = itron_acre_tsk(0,&ctsk_spi_slave_task);
  if (0 < (int)uVar1) {
    itron_sta_tsk(uVar1,0);
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

void pclink_stats_print(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_a0 [128];
  
  if (DAT_20450004 != 0) {
    iVar2 = 0x400;
    uVar1 = gpio_read_bit(2,0xd);
    if (DAT_20450008 != uVar1) {
      DAT_2045d4b0 = DAT_2045d4b0 + 1;
    }
    if ((((DAT_2045d4a8 == 0) || (DAT_2045d4ac != 0)) || (DAT_2045d4bc == 0)) ||
       ((DAT_2045d4c0 != 0 || (DAT_2045d4b0 == 0)))) {
      iVar2 = 0xc800;
    }
    DAT_20450008 = uVar1;
    fb_fill_rect(param_1,iVar2,0x104,600,200,0xaf);
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

void renc_rec_set(int param_1,byte param_2)

{
  (&DAT_208d99a4)[param_1 * 5] = (char)param_1;
  (&DAT_208d99a5)[param_1 * 5] = param_2;
  return;
}


// ===== task_renc @ 20112774 (96 bytes)

void task_renc(void)

{
  void *pvVar1;
  uint uStack_4;
  
  do {
    do {
      do {
        pvVar1 = itron_twai_flg(DAT_208001f8,1,5,&uStack_4,-1);
      } while (pvVar1 != (void *)0x0);
    } while (uStack_4 != 1);
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
  DAT_208001fc = MTU2_TCNT_1;
  if (DAT_208001fc != DAT_208001fe) {
    renc_rec_set(1,(char)DAT_208001fc - (char)DAT_208001fe);
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
  DAT_20800202 = MTU2_TCNT_2;
  if (DAT_20800202 != DAT_20800204) {
    renc_rec_set(2,(char)DAT_20800202 - (char)DAT_20800204);
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
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar2 = 0;
  iVar4 = 0;
  if (0 < (int)DAT_208001f4) {
    do {
      iVar1 = iVar4 * 2;
      iVar4 = iVar4 + 1;
      uVar2 = uVar2 + *(ushort *)(param_1 + iVar1);
    } while (iVar4 < (int)DAT_208001f4);
  }
  uVar6 = __aeabi_idivmod(uVar2,DAT_208001f4);
  uVar2 = (uint)uVar6;
  uVar5 = uVar2 & 0x80000000;
  if ((int)uVar5 < 0) {
    uVar2 = -uVar2;
  }
  uVar3 = uVar2 << LZCOUNT(uVar2);
  if (uVar3 == 0) {
    return 0;
  }
  return CONCAT44(uVar5 + (0x41d - LZCOUNT(uVar2)) * 0x100000 + (uVar3 >> 0xb),uVar3 << 0x15);
}


// ===== adc_hysteresis @ 201128d8 (28 bytes)

/* keep the old value unless it moved by more than 7 */

ushort adc_hysteresis(int param_1,int param_2,int param_3)

{
  if (0xe < (param_2 - param_1) + 7U) {
    param_3 = param_1;
  }
  return (ushort)param_3;
}


// ===== task_ad_renc @ 201128f4 (120 bytes)

void task_ad_renc(void)

{
  uint uVar1;
  uint uVar2;
  uint auStack_20 [8];
  
  uVar2 = 0;
  __aeabi_memclr(&DAT_208d9a08,0x20);
  __aeabi_memclr(&DAT_208d99c8,0x20);
  do {
    do {
      itron_tslp_tsk(0xffffffff);
      adc_read_all(auStack_20);
      uVar1 = auStack_20[0];
      adc_read_all(auStack_20);
      (&DAT_208d9a08)[uVar2] = (short)uVar1;
      (&DAT_208d99c8)[uVar2] = (short)auStack_20[1];
      uVar1 = uVar2 + 1;
      uVar2 = uVar1 & 0x1f;
    } while ((int)uVar1 <= (int)DAT_208001f4);
    DAT_208001f4 = uVar1;
  } while( true );
}


// ===== pot_detect @ 2011296c (360 bytes)

/* AN0/AN1 averages -> 8-bit pot values (ids 5/4) after 2 changed polls */

void pot_detect(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined8 uVar4;
  
  uVar4 = adc_ring_average(&DAT_208d9a08);
  __aeabi_dadd((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3fe00000);
  uVar1 = __aeabi_d2uiz();
  uVar4 = adc_ring_average(&DAT_208d99c8);
  __aeabi_dadd((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3fe00000);
  uVar2 = __aeabi_d2uiz();
  uVar3 = adc_hysteresis((uint)uVar1,(uint)DAT_208001ea,(uint)DAT_208001ee);
  DAT_208001f0 = adc_hysteresis((uint)uVar2,(uint)DAT_208001ec,(uint)DAT_208001f0);
  DAT_2080020e = uVar1 >> 4;
  DAT_20800208 = uVar2 >> 4;
  DAT_208001ea = uVar1;
  DAT_208001ec = uVar2;
  DAT_208001ee = uVar3;
  if ((DAT_20800208 != DAT_2080020a) &&
     (DAT_208001e5 = DAT_208001e5 + '\x01', DAT_208001e5 == '\x02')) {
    if ((DAT_208001e7 != '\0') && (renc_rec_set(4,(byte)DAT_20800208), DAT_20800495 != '\0')) {
      mainlink_renc_event(&DAT_208d99b8);
    }
    DAT_208001e7 = '\x01';
    DAT_2080020a = DAT_20800208;
    DAT_208001e5 = '\0';
  }
  if ((DAT_2080020e != DAT_20800210) &&
     (DAT_208001e6 = DAT_208001e6 + '\x01', DAT_208001e6 == '\x02')) {
    if ((DAT_208001e8 != '\0') && (renc_rec_set(5,(byte)DAT_2080020e), DAT_20800495 != '\0')) {
      mainlink_renc_event(&DAT_208d99bd);
    }
    DAT_208001e8 = '\x01';
    DAT_20800210 = DAT_2080020e;
    DAT_208001e6 = '\0';
  }
  return;
}


// ===== task_detect_renc @ 20112ad4 (24 bytes)

void task_detect_renc(void)

{
  do {
    itron_tslp_tsk(0xffffffff);
    pot_detect();
    renc_poll_mtu1();
    renc_poll_mtu2();
  } while( true );
}


// ===== renc_mtu2_init @ 20112aec (84 bytes)

/* MTU2 ch1 phase-count mode 1, ch2 mode 4, start CST1/CST2 */

void renc_mtu2_init(void)

{
  byte bVar1;
  
  bVar1 = MTU2_TSTR;
  MTU2_TSTR = bVar1 & 0xfd;
  bVar1 = MTU2_TSTR;
  MTU2_TSTR = bVar1 & 0xfb;
  MTU2_TMDR_1 = 4;
  MTU2_TCNT_1 = 0;
  MTU2_TMDR_2 = 7;
  bVar1 = MTU2_TSTR;
  MTU2_TSTR = bVar1 | 4;
  bVar1 = MTU2_TSTR;
  MTU2_TSTR = bVar1 | 2;
  return;
}


// ===== renc_irq4_isr @ 20112b40 (120 bytes)

/* IRQ4 (both edges): P3_3 vs P3_5 -> +-1, encoder id 3 */

void renc_irq4_isr(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  byte bVar4;
  undefined4 extraout_r2;
  
  gic_disable_irq(0x24);
  uVar1 = PORT_PPR3;
  uVar2 = PORT_PPR3;
  if ((uVar1 & 0xf) >> 3 == (uVar2 & 0x3f) >> 5) {
    bVar4 = 0xff;
  }
  else {
    bVar4 = 1;
  }
  DAT_208001e4 = DAT_208001e4 + bVar4;
  renc_rec_set(3,bVar4);
  uVar1 = INTC_IRQRR;
  if ((uVar1 & 0x10) != 0) {
    uVar1 = INTC_IRQRR;
    INTC_IRQRR = uVar1 & 0xffef;
  }
  uVar3 = INTC_IRQRR;
  itron_set_flg(DAT_208001f8,1,extraout_r2,uVar3);
  return;
}


// ===== renc_init @ 20112bb8 (268 bytes)

/* tasks "renc", "ad renc", "detect renc" */

void renc_init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_201637d8(&DAT_20800208,0xff,param_3,param_4,param_4);
  FUN_201637d8(&DAT_2080020e,0xff);
  DAT_208001f8 = itron_acre_flg(0,&cflg_renc);
  if (((0 < (int)DAT_208001f8) && (uVar2 = itron_acre_tsk(0,&ctsk_renc), 0 < (int)uVar2)) &&
     (uVar2 = itron_sta_tsk(uVar2,0), uVar2 == 0)) {
    renc_mtu2_init();
    uVar2 = itron_acre_tsk(0,&ctsk_ad_renc);
    if ((0 < (int)uVar2) && (uVar3 = itron_sta_tsk(uVar2,0), uVar3 == 0)) {
      periodic_wakeup_register(uVar2,1);
      uVar2 = itron_acre_tsk(0,&ctsk_detect_renc);
      if ((0 < (int)uVar2) && (uVar3 = itron_sta_tsk(uVar2,0), uVar3 == 0)) {
        periodic_wakeup_register(uVar2,2);
        uVar1 = INTC_ICR1;
        INTC_ICR1 = uVar1 & 0xfcff;
        uVar1 = INTC_ICR1;
        INTC_ICR1 = uVar1 | 0x300;
        uVar2 = itron_acre_isr(0,&cisr_renc_irq4_isr);
        if (0 < (int)uVar2) {
          gic_enable_irq(0x24);
          return;
        }
      }
    }
  }
  return;
}


// ===== pot_resend_all @ 20112cc4 (136 bytes)

/* re-send pot ids 4/5 when the GUI link comes up */

void pot_resend_all(void)

{
  int iVar1;
  
  iVar1 = FUN_201309b4();
  if (iVar1 == 0) {
    if ((DAT_208001e7 != '\0') || (DAT_208001e5 == '\x01')) {
      renc_rec_set(4,(byte)DAT_20800208);
      mainlink_renc_event(&DAT_208d99b8);
    }
    if ((DAT_208001e8 != '\0') || (DAT_208001e6 == '\x01')) {
      renc_rec_set(5,(byte)DAT_2080020e);
      mainlink_renc_event(&DAT_208d99bd);
      return;
    }
  }
  return;
}


// ===== hid_usage_to_ascii @ 20112da4 (184 bytes)

/* HID usage -> ASCII for the debug line editor (lowercase, JIS '=' on Shift+'-') */

int hid_usage_to_ascii(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (param_2 - 0x1eU < 9) {
    return param_2 + 0x13;
  }
  if (param_2 != 0x27) {
    if (param_2 - 4U < 0x1a) {
      return param_2 + 0x5d;
    }
    if (param_2 - 0x59U < 9) {
      return param_2 + -0x30;
    }
    if (param_2 != 0x62) {
      if (param_2 == 0x87) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x5c;
        }
        else {
          iVar1 = 0x5f;
        }
        return iVar1;
      }
      if (param_2 == 0x2d) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x2d;
        }
        else {
          iVar1 = 0x3d;
        }
        return iVar1;
      }
      if (param_2 == 0x37) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x2e;
        }
        else {
          iVar1 = 0x3e;
        }
        return iVar1;
      }
      if (param_2 == 0x38) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x2f;
        }
        else {
          iVar1 = 0x3f;
        }
        return iVar1;
      }
      if (param_2 == 0x2c) {
        iVar1 = 0x20;
      }
      else {
        iVar1 = -1;
      }
      return iVar1;
    }
  }
  return 0x30;
}


// ===== hid_line_edit @ 20112e5c (216 bytes)

/* HID-usage line editor: 0x28/0x58 Enter, 0x29 Esc, 0x2A Backspace, max 31 chars */

int * hid_line_edit(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *extraout_r3;
  
  iVar3 = 0;
  for (iVar2 = 0; (iVar2 < *(int *)(param_3 + 8) && (*(char *)(param_3 + iVar2 + 0xc) != '\0'));
      iVar2 = iVar2 + 1) {
    iVar3 = iVar3 + 1;
  }
  if (1 < iVar3) {
    return (int *)0x0;
  }
  cVar1 = *(char *)(param_3 + 0xc);
  if (cVar1 == '\0' && *(char *)(param_3 + 5) == '\0') {
    return (int *)0x0;
  }
  iVar2 = 0;
  if (cVar1 != '(' && cVar1 != 'X') {
    if (cVar1 != ')') {
      if (cVar1 != '*') {
        iVar2 = hid_usage_to_ascii(param_1);
        if (iVar2 < 0) {
          return (int *)0x0;
        }
        uVar4 = *extraout_r3;
        if (0x1e < uVar4) {
          return (int *)0x0;
        }
        *extraout_r3 = uVar4 + 1;
        *(char *)((int)extraout_r3 + uVar4 + 4) = (char)iVar2;
        return (int *)0x0;
      }
      if (*param_1 < 1) {
        return (int *)0x0;
      }
      iVar2 = *param_1 + -1;
    }
    *param_1 = iVar2;
    return (int *)0x0;
  }
  *(undefined1 *)((int)param_1 + *param_1 + 4) = 0;
  *param_1 = 0;
  return param_1 + 1;
}


// ===== FUN_20112f34 @ 20112f34 (8 bytes)

int FUN_20112f34(int param_1)

{
  return param_1 + 4;
}


// ===== key_held_list_update @ 20112f3c (164 bytes)

/* replace old code by new in the 4-entry held-key list 0x2080023C (0 = add/remove) */

void key_held_list_update(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = true;
  iVar3 = 0;
  if (param_2 == 0) {
    do {
      if ((ushort)(&DAT_2080023c)[iVar3] == param_1) {
        (&DAT_2080023c)[iVar3] = 0;
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    return;
  }
  iVar3 = 0;
  do {
    if ((ushort)(&DAT_2080023c)[iVar3] == param_1) {
      iVar2 = 0;
      do {
        if ((ushort)(&DAT_2080023c)[iVar2] == param_2) {
          bVar1 = false;
          goto LAB_20112fcc;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
      if (bVar1) {
        (&DAT_2080023c)[iVar3] = (ushort)param_2;
      }
    }
LAB_20112fcc:
    iVar3 = iVar3 + 1;
    if (3 < iVar3) {
      return;
    }
  } while( true );
}


// ===== key_combo_match @ 20112fe0 (200 bytes)

/* boot key combination n (table 0x20165678, 3 codes each) held? 2 or 3 keys */

bool key_combo_match(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  bVar6 = false;
  iVar3 = 0;
  switch(param_1) {
  default:
    iVar5 = 4;
    break;
  case 1:
  case 3:
  case 4:
  case 5:
  case 7:
    iVar5 = 3;
  }
  iVar4 = 0;
  if (iVar5 != 0) {
    iVar1 = param_1 * 6;
    do {
      sVar2 = (&DAT_2080023c)[iVar4];
      if (sVar2 == 0) break;
      if ((sVar2 == *(short *)(&DAT_20165678 + iVar1)) ||
         (sVar2 == *(short *)(&DAT_2016567a + iVar1))) {
        iVar3 = iVar3 + 1;
      }
      if ((param_1 == 2 || param_1 == 6) && (sVar2 == *(short *)(&DAT_2016567c + iVar1))) {
        iVar3 = iVar3 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  if (((param_1 == 2 || param_1 == 6) ||
      (bVar6 = iVar3 == 2, (param_1 == 0 || param_1 == 2) || param_1 == 6)) && (iVar3 == 3)) {
    bVar6 = true;
  }
  return bVar6;
}


// ===== key_scan_first @ 201130c8 (60 bytes)

/* first of 8 key lines that reads active (0..7) */

byte key_scan_first(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  do {
    bVar1 = key_combo_match(uVar2);
    uVar3 = uVar2;
    if (bVar1) break;
    uVar2 = uVar2 + 1 & 0xff;
    uVar3 = 0;
  } while (uVar2 < 8);
  return (byte)uVar3;
}


// ===== key_matrix_press_check @ 20113104 (164 bytes)

/* matrix press pass (subset of task_key) */

void key_matrix_press_check(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = 0;
    do {
      uVar1 = (&DAT_20165626)[iVar3 * 4 + iVar2];
      if (((&DAT_208d9a60)[iVar3 * 4 + iVar2] == 1) && ((&DAT_208d9b10)[iVar3 * 4 + iVar2] == 0)) {
        if (DAT_20800214 != '\0') {
          DAT_20800214 = '\0';
          (&DAT_208d9b68)[iVar3 * 4 + iVar2] = (&DAT_208d9b68)[iVar3 * 4 + iVar2] + 1;
          (&DAT_208d9ab8)[iVar3 * 4 + iVar2] = 1;
        }
        key_held_list_update(0,(uint)uVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}


// ===== key_set_power_level @ 201131a8 (12 bytes)

/* powon task stores the P2_0 level as direct key 0 (0x300 LOCK/PWR) */

void key_set_power_level(uint param_1)

{
  DAT_208d9af8 = param_1;
  return;
}


// ===== adc_key_level @ 201131b4 (52 bytes)

/* 8-bit ADC value -> level 0..5 (count of thresholds below it) */

uint adc_key_level(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if (param_1 < *(ushort *)(param_2 + uVar1 * 2)) {
      return uVar1;
    }
    iVar2 = iVar2 + 1;
    uVar1 = uVar1 + 1 & 0xff;
  } while (iVar2 < 5);
  return uVar1;
}


// ===== gpio_read_port_bit @ 201131e8 (136 bytes)

/* read PPRn bit for ports 2,3,7,8,9,10 */

uint gpio_read_port_bit(uint param_1,uint param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar1 = 1 << (param_2 & 0xff);
  switch(param_1) {
  case 2:
    uVar2 = PORT_PPR2;
    break;
  case 3:
    uVar2 = PORT_PPR3;
    break;
  default:
    goto switchD_20113204_caseD_4;
  case 7:
    uVar2 = PORT_PPR7;
    break;
  case 8:
    uVar2 = PORT_PPR8;
    break;
  case 9:
    uVar2 = PORT_PPR9;
    break;
  case 10:
    uVar2 = PORT_PPR10;
    if ((uVar2 & uVar1) != 0) {
      return 1;
    }
    return 0;
  }
  if ((uVar2 & uVar1) != 0) {
    return 1;
  }
switchD_20113204_caseD_4:
  return 0;
}


// ===== mainlink_send_key @ 20113294 (512 bytes)

/* E0 key event from the key task (or E4/E5 to leave a MAIN-driven screen) */

void mainlink_send_key(uint param_1,byte param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  puVar3 = &local_20;
  uStack_1c = 0;
  local_20 = CONCAT13((char)param_1,CONCAT12((char)(param_1 >> 8),CONCAT11(param_2,0xe0)));
  iVar2 = FUN_20116dac();
  if (iVar2 == 0) goto LAB_20113460;
  if (DAT_20800495 == '\0') {
    if (local_20._1_1_ == '\0') {
      if (local_20._2_1_ != '\x03') goto LAB_20113460;
LAB_2011343c:
      if (local_20._3_1_ != '\x0f') goto LAB_20113460;
    }
    else {
      if (local_20._2_1_ != '\x03') goto LAB_20113460;
      if (local_20._3_1_ != '\0') goto LAB_2011343c;
    }
    bVar1 = mainlink_got_frame60();
    if (bVar1 == 0) goto LAB_20113460;
    uVar4 = 5;
  }
  else {
    if ((gui_frame.cmd != 0x7b) || (gui_frame.byte1 == 0)) {
      if ((DAT_2080049f == '\0') || (g_ml.last_rx_cmd == 0x7c)) {
        if (DAT_20800219 == '\0') {
          if (local_20._1_1_ == '\0') {
            if ((local_20._2_1_ == '\x03') && (local_20._3_1_ == '\0')) {
              if (DAT_20800216 == '\0') {
                return;
              }
              DAT_20800216 = '\0';
            }
          }
          else if ((local_20._2_1_ == '\x03') && (local_20._3_1_ == '\0')) {
            DAT_20800216 = '\x01';
          }
        }
        else {
          if (local_20._1_1_ != '\x02') {
            DAT_20800219 = 0;
            return;
          }
          DAT_20800219 = '\x01';
          if (local_20._2_1_ != '\x03') {
            DAT_20800219 = 1;
            return;
          }
          if (local_20._3_1_ != '\0') {
            DAT_20800219 = 1;
            return;
          }
        }
        mainlink_queue_frame(&local_20,5);
      }
      else {
        local_18 = 0xe5;
        mainlink_queue_frame(&local_18,4);
        DAT_2080049f = '\0';
        DAT_20800219 = '\x01';
      }
      goto LAB_20113460;
    }
    local_18 = CONCAT31(local_18._1_3_,0xe4);
    if (DAT_20800218 == '\0') goto LAB_20113460;
    uVar4 = 4;
    DAT_20800218 = '\0';
    DAT_20800488 = 1;
    puVar3 = &local_18;
  }
  mainlink_queue_frame(puVar3,uVar4);
LAB_20113460:
  if (((local_20._1_1_ == '\x02') && (local_20._2_1_ == '\x03')) && (local_20._3_1_ == '\0')) {
    DAT_20800216 = 0;
    FUN_2011722c();
    return;
  }
  return;
}


// ===== key_matrix_drive_col @ 201134d0 (80 bytes)

/* drive one of P8_1/P8_2/P8_7/P8_8 low, the other three high */

void key_matrix_drive_col(int param_1)

{
  int iVar1;
  uint local_20 [4];
  
  iVar1 = 0;
  local_20[0] = 1;
  local_20[1] = 2;
  local_20[2] = 7;
  local_20[3] = 8;
  do {
    if (iVar1 == param_1) {
      gpio_cfg_out_low(8,local_20[iVar1]);
    }
    else {
      gpio_cfg_out_high(8,local_20[iVar1]);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  return;
}


// ===== key_sample_all @ 20113558 (188 bytes)

/* sample 5 direct keys, PTT, 4x4 matrix, ADC AN3/AN4 */

void key_sample_all(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint auStack_38 [3];
  int local_2c;
  int local_28;
  
  iVar2 = 1;
  do {
    uVar1 = gpio_read_port_bit(*(uint *)(&DAT_208002a4 + iVar2 * 0x10),
                               *(uint *)(iVar2 * 0x10 + 0x208002a8));
    (&DAT_208d9af8)[iVar2] = uVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  DAT_20800230 = gpio_read_port_bit(DAT_20800304,DAT_20800308);
  iVar2 = 0;
  do {
    key_matrix_drive_col(iVar2);
    iVar3 = 0;
    do {
      uVar1 = gpio_read_port_bit((&DAT_20800244)[iVar3 * 6],(&DAT_20800248)[iVar3 * 6]);
      iVar4 = iVar3 + 1;
      (&DAT_208d9b10)[iVar3 * 4 + iVar2] = uVar1;
      iVar3 = iVar4;
    } while (iVar4 < 4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  adc_read_all(auStack_38);
  DAT_2080021e = (undefined2)((uint)(local_2c << 0xc) >> 0x10);
  adc_read_all(auStack_38);
  DAT_20800220 = (short)((uint)(local_28 << 0xc) >> 0x10);
  return;
}


// ===== key_debounce_all @ 20113614 (540 bytes)

/* 3 equal samples -> changed flags; ADC pair -> code index 0x2080021A */

void key_debounce_all(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = 0;
  do {
    if ((0 < (int)(&DAT_208d9ba8)[iVar2]) && ((&DAT_208002ac)[iVar2 * 4] == (&DAT_208d9af8)[iVar2]))
    {
      (&DAT_208d9ba8)[iVar2] = (&DAT_208d9ba8)[iVar2] + 1;
    }
    if ((&DAT_208002ac)[iVar2 * 4] == (&DAT_208d9af8)[iVar2]) {
      if (2 < (int)(&DAT_208d9ba8)[iVar2]) {
        (&DAT_208d9a48)[iVar2] = 1;
        (&DAT_208d9ba8)[iVar2] = 0;
      }
    }
    else {
      (&DAT_208d9ba8)[iVar2] = 1;
      (&DAT_208002ac)[iVar2 * 4] = (&DAT_208d9af8)[iVar2];
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  if ((0 < DAT_20800238) && (DAT_2080030c == DAT_20800230)) {
    DAT_20800238 = DAT_20800238 + 1;
  }
  if (DAT_2080030c == DAT_20800230) {
    if (2 < DAT_20800238) {
      DAT_20800228 = 1;
      DAT_20800238 = 0;
    }
  }
  else {
    DAT_20800238 = 1;
    DAT_2080030c = DAT_20800230;
  }
  iVar2 = 0;
  do {
    iVar3 = 0;
    do {
      iVar6 = (&DAT_208d9bc0)[iVar2 * 4 + iVar3];
      if ((0 < iVar6) &&
         ((&DAT_208d9b10)[iVar2 * 4 + iVar3] == (&DAT_20800244)[iVar2 * 6 + iVar3 + 2])) {
        (&DAT_208d9bc0)[iVar2 * 4 + iVar3] = iVar6 + 1;
      }
      iVar6 = (&DAT_208d9b10)[iVar2 * 4 + iVar3];
      if (iVar6 == (&DAT_20800244)[iVar2 * 6 + iVar3 + 2]) {
        if (2 < (int)(&DAT_208d9bc0)[iVar2 * 4 + iVar3]) {
          (&DAT_208d9a60)[iVar2 * 4 + iVar3] = 1;
          (&DAT_208d9bc0)[iVar2 * 4 + iVar3] = 0;
        }
      }
      else {
        (&DAT_208d9bc0)[iVar2 * 4 + iVar3] = 1;
        (&DAT_20800244)[iVar2 * 6 + iVar3 + 2] = iVar6;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  uVar4 = adc_key_level((uint)(byte)DAT_2080021e,(int)&DAT_20800314);
  uVar5 = adc_key_level((uint)(byte)DAT_20800220,(int)&DAT_2080031e);
  iVar2 = 0;
  while (((byte)(&DAT_201655f4)[iVar2 * 2] != uVar4 || ((byte)(&DAT_201655f5)[iVar2 * 2] != uVar5)))
  {
    iVar2 = iVar2 + 1;
    if (0x18 < iVar2) {
      uVar4 = 0;
LAB_20113520:
      if (DAT_2080021b == uVar4) {
        bVar1 = (byte)uVar4;
        if (DAT_2080021c != '\x02') {
          DAT_2080021c = DAT_2080021c + '\x01';
          bVar1 = DAT_2080021a;
        }
      }
      else {
        DAT_2080021c = '\0';
        bVar1 = DAT_2080021a;
        DAT_2080021b = (byte)uVar4;
      }
      DAT_2080021a = bVar1;
      return;
    }
  }
  uVar4 = iVar2 + 1U & 0xff;
  goto LAB_20113520;
}


// ===== task_key @ 201137f8 (1140 bytes)

void task_key(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  do {
    do {
      itron_tslp_tsk(0xffffffff);
    } while (DAT_20800217 != '\0');
    if ((gui_frame.cmd == 0x7b) && (gui_frame.byte1 != 0)) {
      DAT_20800218 = 1;
    }
    key_sample_all();
    key_debounce_all();
    if (DAT_20800228 == 1) {
      if (DAT_20800230 == 0) {
        if (DAT_20800215 != '\0') {
          mainlink_send_key((uint)DAT_20800310,1);
          DAT_20800215 = '\0';
          DAT_20800234 = DAT_20800234 + 1;
          DAT_2080022c = 1;
        }
      }
      else {
        mainlink_send_key((uint)DAT_20800310,0);
        DAT_20800215 = '\x01';
        DAT_20800234 = 0;
        DAT_2080022c = 0;
      }
      DAT_20800228 = 0;
    }
    if (DAT_2080022c == 1) {
      if (DAT_20800234 < 1000) {
        DAT_20800234 = DAT_20800234 + 1;
        goto LAB_201138dc;
      }
LAB_201138e4:
      mainlink_send_key((uint)DAT_20800310,2);
      DAT_20800234 = 0;
      DAT_2080022c = 0;
    }
    else {
LAB_201138dc:
      if (999 < DAT_20800234) goto LAB_201138e4;
    }
    iVar3 = 0;
    do {
      if ((&DAT_208d9a48)[iVar3] == 1) {
        if ((&DAT_208d9af8)[iVar3] == 0) {
          if ((DAT_20800214 != '\0') && (uVar4 = mouse_middle_is_func(), uVar4 == 0)) {
            mainlink_send_key((uint)(ushort)(&DAT_208002b0)[iVar3 * 8],1);
            DAT_20800214 = '\0';
            (&DAT_208d9b50)[iVar3] = (&DAT_208d9b50)[iVar3] + 1;
            (&DAT_208d9aa0)[iVar3] = 1;
          }
          key_held_list_update(0,(uint)(ushort)(&DAT_208002b0)[iVar3 * 8]);
        }
        else {
          if (((uint)DAT_2080023c == (uint)(ushort)(&DAT_208002b0)[iVar3 * 8]) &&
             (DAT_20800214 == '\0')) {
            mainlink_send_key((uint)(ushort)(&DAT_208002b0)[iVar3 * 8],0);
            DAT_20800214 = '\x01';
          }
          key_held_list_update((uint)(ushort)(&DAT_208002b0)[iVar3 * 8],0);
          (&DAT_208d9b50)[iVar3] = 0;
          (&DAT_208d9aa0)[iVar3] = 0;
        }
        (&DAT_208d9a48)[iVar3] = 0;
      }
      iVar1 = (&DAT_208d9b50)[iVar3];
      if ((&DAT_208d9aa0)[iVar3] == 1) {
        if (iVar1 < 1000) {
          iVar1 = iVar1 + 1;
          (&DAT_208d9b50)[iVar3] = iVar1;
          goto LAB_201139f0;
        }
LAB_201139f8:
        mainlink_send_key((uint)(ushort)(&DAT_208002b0)[iVar3 * 8],2);
        (&DAT_208d9b50)[iVar3] = 0;
        (&DAT_208d9aa0)[iVar3] = 0;
      }
      else {
LAB_201139f0:
        if (999 < iVar1) goto LAB_201139f8;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
    iVar3 = FUN_20116dac();
    if ((iVar3 != 0) || (DAT_2080049b != '\0')) {
      iVar3 = 0;
      do {
        iVar1 = 0;
        do {
          uVar4 = (uint)(ushort)(&DAT_20165626)[iVar3 * 4 + iVar1];
          if ((&DAT_208d9a60)[iVar3 * 4 + iVar1] == 1) {
            if ((&DAT_208d9b10)[iVar3 * 4 + iVar1] == 0) {
              if (DAT_20800214 != '\0') {
                mainlink_send_key(uVar4,1);
                DAT_20800214 = '\0';
                (&DAT_208d9b68)[iVar3 * 4 + iVar1] = (&DAT_208d9b68)[iVar3 * 4 + iVar1] + 1;
                (&DAT_208d9ab8)[iVar3 * 4 + iVar1] = 1;
              }
              key_held_list_update(0,uVar4);
            }
            else {
              if (DAT_2080023c == uVar4) {
                mainlink_send_key(uVar4,0);
                DAT_20800214 = '\x01';
              }
              key_held_list_update(uVar4,0);
              (&DAT_208d9b68)[iVar3 * 4 + iVar1] = 0;
              (&DAT_208d9ab8)[iVar3 * 4 + iVar1] = 0;
            }
            (&DAT_208d9a60)[iVar3 * 4 + iVar1] = 0;
          }
          iVar2 = (&DAT_208d9b68)[iVar3 * 4 + iVar1];
          if ((&DAT_208d9ab8)[iVar3 * 4 + iVar1] == 1) {
            if (iVar2 < 1000) {
              iVar2 = iVar2 + 1;
              (&DAT_208d9b68)[iVar3 * 4 + iVar1] = iVar2;
              goto LAB_20113b38;
            }
LAB_20113b40:
            mainlink_send_key(uVar4,2);
            (&DAT_208d9b68)[iVar3 * 4 + iVar1] = 0;
            (&DAT_208d9ab8)[iVar3 * 4 + iVar1] = 0;
          }
          else {
LAB_20113b38:
            if (999 < iVar2) goto LAB_20113b40;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < 4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      if (DAT_2080021a != 0) {
        if (((uint)DAT_2080023c == (uint)(ushort)(&DAT_20165644)[DAT_2080021a]) &&
           (DAT_2080021c == '\0')) {
          mainlink_send_key((uint)(ushort)(&DAT_20165644)[DAT_2080021a],0);
          DAT_20800214 = '\x01';
          key_held_list_update((uint)(ushort)(&DAT_20165644)[DAT_2080021a],0);
          DAT_2080021a = 0;
          DAT_20800224 = 0;
        }
        if (DAT_2080021c == '\x02') {
          if ((DAT_20800214 != '\0') && (DAT_20800224 == 0)) {
            mainlink_send_key((uint)(ushort)(&DAT_20165644)[DAT_2080021a],1);
            DAT_20800214 = '\0';
            key_held_list_update(0,(uint)(ushort)(&DAT_20165644)[DAT_2080021a]);
          }
          if (((uint)DAT_2080023c == (uint)(ushort)(&DAT_20165644)[DAT_2080021a]) &&
             (DAT_20800224 < 1000)) {
            DAT_20800224 = DAT_20800224 + 1;
          }
          if (DAT_20800224 == 1000) {
            mainlink_send_key((uint)(ushort)(&DAT_20165644)[DAT_2080021a],2);
            DAT_20800224 = DAT_20800224 + 1;
          }
        }
      }
    }
  } while( true );
}


// ===== key_func_is_held @ 20113c6c (24 bytes)

/* direct key 3 (0x30F FUNC) is in its hold phase */

bool key_func_is_held(void)

{
  return DAT_208d9aac == 1;
}


// ===== key_init @ 20113c84 (68 bytes)

/* creates task "key" */

void key_init(void)

{
  uint uVar1;
  uint uVar2;
  
  key_set_power_level(1);
  uVar1 = itron_acre_tsk(0,&ctsk_key);
  if ((0 < (int)uVar1) && (uVar2 = itron_sta_tsk(uVar1,0), uVar2 == 0)) {
    periodic_wakeup_register(uVar1,4);
    return;
  }
  return;
}


// ===== key_task_pause @ 20113d00 (16 bytes)

/* sets 0x20800217: task_key skips scans */

void key_task_pause(void)

{
  DAT_20800217 = 1;
  return;
}

