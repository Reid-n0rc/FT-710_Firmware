// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== scif5_rxi_isr @ 201148a4 (8 bytes)

void scif5_rxi_isr(void)

{
  scif5_uart.rxi_count = scif5_uart.rxi_count + 1;
  if (((scif5_uart.regs)->scfsr & 0xff9d) != 0) {
    scif5_uart.rx_errors = scif5_uart.rx_errors + 1;
  }
  if (((scif5_uart.regs)->scfsr & 2) != 0) {
    if (((scif5_uart.rx_wr < scif5_uart.rx_rd) ||
        (0x3fe < (int)((uint)scif5_uart.rx_wr - (uint)scif5_uart.rx_rd))) &&
       ((scif5_uart.rx_rd <= scif5_uart.rx_wr ||
        ((int)((uint)scif5_uart.rx_rd - (uint)scif5_uart.rx_wr) < 2)))) {
      (scif5_uart.regs)->scfsr = (scif5_uart.regs)->scfsr & 0xfffd;
      scif5_uart.rx_count = scif5_uart.rx_count + 1;
      scif5_uart.rx_overflow = scif5_uart.rx_overflow + 1;
      return;
    }
    scif5_uart.rx_buf[scif5_uart.rx_wr] = (scif5_uart.regs)->scfrdr;
    DataMemoryBarrier(2);
    scif5_uart.rx_wr = scif5_uart.rx_wr + 1 & 0x3ff;
    (scif5_uart.regs)->scfsr = (scif5_uart.regs)->scfsr & 0xfffd;
    if (scif5_uart.rx_flg != 0) {
      gic_disable_irq((scif5_uart.rxi_isr)->intno);
    }
    itron_set_flg(scif5_uart.rx_flg,1);
    scif5_uart.rx_count = scif5_uart.rx_count + 1;
    pmu_cycle_stamp(0x208dbac0);
    return;
  }
  scif5_uart.rxi_no_data = scif5_uart.rxi_no_data + 1;
  return;
}


// ===== scif5_txi_isr @ 201148ac (8 bytes)

void scif5_txi_isr(void)

{
  scif_txi_isr(&scif5_uart);
  return;
}


// ===== scif5_get @ 201148b4 (36 bytes)

/* UART object @0x208DB280 on SCIF5 (0xE8009800), MAIN link */

void * scif5_get(uint flg)

{
  uart_obj_init(&scif5_uart,(scif_regs *)&SCIF_SCSMR_5,&cisr_scif5_rxi_isr,&cisr_scif5_txi_isr,flg);
  return &scif5_uart;
}


// ===== scif4_get @ 201148d8 (36 bytes)

/* UART object on SCIF4 (0xE8009000) */

void * scif4_get(uint flg)

{
  uart_obj_init(&scif4_uart,(scif_regs *)&SCIF_SCSMR_4,&cisr_scif4_rxi_isr,&cisr_scif4_txi_isr,flg);
  return &scif4_uart;
}


// ===== scif3_get @ 201148fc (36 bytes)

/* UART object on SCIF3 (0xE8008800) */

scif_uart * scif3_get(uint flg)

{
  uart_obj_init(&scif3_uart,(scif_regs *)&SCIF_SCSMR_3,&cisr_scif3_rxi_isr,&cisr_scif3_txi_isr,flg);
  return &scif3_uart;
}


// ===== scif5_rxi_count_get @ 20114920 (12 bytes)

/* Returns scif5_uart.rxi_count; debug_overlay_draw shows it [fact] */

uint scif5_rxi_count_get(void)

{
  return scif5_uart.rxi_count;
}


// ===== scif4_rxi_count_get @ 2011492c (12 bytes)

/* Returns scif4_uart.rxi_count; debug_overlay_draw shows it [fact] */

uint scif4_rxi_count_get(void)

{
  return scif4_uart.rxi_count;
}


// ===== scif_uarts_ctor @ 20114938 (32 bytes)

/* Static constructor: uart_obj_ctor for scif3_uart, scif4_uart and scif5_uart; no direct caller
   (run from the init table) [fact for the calls] */

void scif_uarts_ctor(void)

{
                    /* sets the vtable pointer 0x2042803C [doc] */
  uart_obj_ctor(&scif3_uart);
  uart_obj_ctor(&scif4_uart);
  uart_obj_ctor(&scif5_uart);
  return;
}


// ===== sfl_decode @ 2011497c (100 bytes)

/* byte-wise key subtraction, see docs/sfl-format.md */

byte sfl_decode(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int i;
  
  i = 0;
  if (0 < param_3) {
    do {
      uVar1 = param_1 % 0x2b;
      param_1 = uVar1 + 1;
      *(byte *)(param_2 + i) = *(char *)(param_2 + i) - BYTE_ARRAY_204286f8[uVar1 + 0x148];
      i = i + 1;
    } while (i < param_3);
  }
  return (char)(param_1 / 0x2b) * -0x2b + (char)param_1;
}


// ===== sfl_encode @ 201149e0 (100 bytes)

/* inverse of sfl_decode (adds the 43-byte key) */

byte sfl_encode(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int i;
  
  i = 0;
  if (0 < param_3) {
    do {
      uVar1 = param_1 % 0x2b;
      param_1 = uVar1 + 1;
      *(byte *)(param_2 + i) = *(char *)(param_2 + i) + BYTE_ARRAY_204286f8[uVar1 + 0x148];
      i = i + 1;
    } while (i < param_3);
  }
  return (char)(param_1 / 0x2b) * -0x2b + (char)param_1;
}


// ===== sfl_stream_init @ 20114a44 (32 bytes)

void sfl_stream_init(void *param_1,uint param_2,uint param_3,uint param_4)

{
  *(uint *)param_1 = param_2;
  *(undefined4 *)((int)param_1 + 8) = 0;
  *(uint *)((int)param_1 + 0xc) = param_4;
  *(undefined4 *)((int)param_1 + 0x10) = 0;
  *(uint *)((int)param_1 + 4) = param_3;
  *(undefined1 *)((int)param_1 + 0x14) = 0;
  return;
}


// ===== sfl_crc @ 20114a64 (112 bytes)

/* salted CRC-32 over the file */

uint sfl_crc(uint param_1)

{
  uint fs_fread_ret;
  uint uVar1;
  undefined1 auStack_110 [256];
  undefined4 local_10;
  
  uVar1 = 0xffffffff;
  local_10 = 0x139eeca6;
                    /* reflected poly 0xEDB88320 [doc, inference] */
  crc32_make_table();
  while (fs_fread_ret = fs_fread((uint)auStack_110,1,0x100,param_1), fs_fread_ret != 0) {
    uVar1 = crc32_update(uVar1,fs_fread_ret,(uint)auStack_110);
  }
  uVar1 = crc32_update(uVar1,4,(uint)&local_10);
  return ~uVar1;
}


// ===== sfl_stream_getc @ 20114ae0 (92 bytes)

/* one decoded byte */

uint sfl_stream_getc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte sfl_decode_ret;
  uint local_c;
  
  if (0 < *(int *)(param_1 + 0x10)) {
    if (*(int *)(param_1 + 8) < *(int *)(param_1 + 0x10)) {
      local_c = CONCAT31((int3)((uint)param_4 >> 8),
                         *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8)));
      sfl_decode_ret = sfl_decode((uint)*(byte *)(param_1 + 0x14),(int)&local_c,1);
      *(byte *)(param_1 + 0x14) = sfl_decode_ret;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      local_c = local_c & 0xff;
    }
    else {
      local_c = 0xffffffff;
    }
    return local_c;
  }
  return 0xffffffff;
}


// ===== sfl_stream_gets @ 20114b3c (192 bytes)

/* line read with decode */

int sfl_stream_gets(int param_1,int param_2,void *param_3)

{
  int iVar1;
  uint fs_fread_ret;
  int iVar2;
  
  if (*(int *)((int)param_3 + 0xc) == 0) {
    iVar2 = fs_fgets(param_1,param_2,*(undefined4 *)param_3);
    return iVar2;
  }
  if (0 < param_2) {
    iVar2 = 0;
    if (0 < param_2 + -1) {
      do {
        iVar1 = sfl_stream_getc(param_3);
        if (iVar1 == -1) {
          fs_fread_ret = fs_fread(*(uint *)((int)param_3 + 4),1,*(uint *)((int)param_3 + 0xc),
                                  *(uint *)param_3);
          if (fs_fread_ret == 0) break;
          *(uint *)((int)param_3 + 0x10) = fs_fread_ret;
          *(undefined4 *)((int)param_3 + 8) = 0;
        }
        else {
          *(char *)(param_1 + iVar2) = (char)iVar1;
          iVar2 = iVar2 + 1;
          if (iVar1 == 10) break;
        }
      } while (iVar2 < param_2 + -1);
    }
    *(undefined1 *)(param_1 + iVar2) = 0;
    if ((iVar2 != 0) || (param_2 < 2)) {
      return param_1;
    }
  }
  return 0;
}


// ===== sfl_stream_read @ 20114bfc (72 bytes)

/* fread + decode */

int sfl_stream_read(uint param_1,uint param_2,uint param_3,int param_4)

{
  byte sfl_decode_ret;
  uint fs_fread_ret;
  
  fs_fread_ret = fs_fread(param_1,param_2,param_3,*(uint *)param_4);
  if ((fs_fread_ret != 0) && (*(int *)(param_4 + 0xc) != 0)) {
    sfl_decode_ret = sfl_decode((uint)*(byte *)(param_4 + 0x14),param_1,fs_fread_ret);
    *(byte *)(param_4 + 0x14) = sfl_decode_ret;
  }
  return fs_fread_ret;
}


// ===== FUN_20114c44 @ 20114c44 (92 bytes)

void FUN_20114c44(uint param_1,uint param_2,uint param_3,uint *param_4)

{
  byte sfl_encode_ret;
  
  if (param_4[3] != 0) {
    sfl_encode_ret = sfl_encode((uint)(byte)param_4[5],param_1,param_2 * param_3);
    *(byte *)(param_4 + 5) = sfl_encode_ret;
    fs_fwrite(param_1,param_2,param_3,*param_4);
    return;
  }
  fs_fwrite(param_1,param_2,param_3,*param_4);
  return;
}


// ===== sfl_read_header @ 20114ca0 (336 bytes)

/* reads the 0x40-byte header block */

uint sfl_read_header(uint param_1,int param_2)

{
  ushort hex_parse_ret;
  uint uVar1;
  uint fs_fread_ret;
  byte *pbVar2;
  int iVar3;
  undefined1 auStack_118 [64];
  undefined1 local_d8;
  undefined1 *local_18;
  byte *local_14;
  
  local_18 = auStack_118;
  iVar3 = 0;
  do {
    uVar1 = fs_fread((uint)auStack_118,1,0x40,param_1);
    if (uVar1 == 0) {
      return 1;
    }
    if ((param_2 != 0) && (iVar3 == 3)) {
      memcpy(param_2,auStack_118,0x40);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  local_d8 = 0;
                    /* Word-at-a-time string length [doc] */
  iVar3 = strlen(auStack_118);
  if (iVar3 == 0x40) {
    uVar1 = sfl_crc(param_1);
    fs_fseek(param_1,0,0);
    iVar3 = 0;
    do {
      fs_fread_ret = fs_fread((uint)auStack_118,1,0x40,param_1);
      if (fs_fread_ret == 0) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    iVar3 = fs_fgets(auStack_118,0x100,param_1);
                    /* next token, 0 at the end [doc] */
    if ((((iVar3 != 0) && (iVar3 = strtok_r(local_18,&DWORD_20114df0,&local_18), iVar3 != 0)) &&
        (iVar3 = strtok_r(local_18,&DWORD_20114df0,&local_18), iVar3 != 0)) &&
       (pbVar2 = (byte *)strtok_r(local_18,&DWORD_20114df0,&local_18), pbVar2 != (byte *)0x0)) {
      hex_parse_ret = hex_parse(pbVar2,8,&local_14);
      if ((local_14 != pbVar2) && (hex_parse_ret == uVar1)) {
        return 0;
      }
    }
  }
  return 1;
}


// ===== system_reboot @ 20114df4 (148 bytes)

/* FS off, LCD/LVDS off, MAIN reset pulse, flash reset, wdt_system_reset */

void system_reboot(void)

{
  itron_chg_pri(0,1);
                    /* P2_4, P2_5 and P10_1 low [doc, inference] */
  gpio_p2_4_5_clear();
  backlight_enable(0);
  lvds_pins_enable(0);
  gpio_rx_update_off(1);
  itron_dly_tsk(5);
  itron_dly_tsk(0x96);
  gpio_rx_update_off(0);
  gpio_p7_9_11(1);
  itron_dly_tsk(4);
  gpio_rx_update(0);
                    /* Drive the MAIN reset and boot pins [fact: mainlink.md] */
  gpio_rx_reset(1);
  itron_dly_tsk(1);
  gpio_p8_5(1);
  gpio_rx_reset(0);
  itron_dly_tsk(0xe);
  gpio_qf_reset(1);
                    /* Then reset the DISPLAY by the watchdog [fact: 0x20100268] */
  wdt_system_reset();
  return;
}


// ===== uart4_send @ 20114e88 (84 bytes)

/* used by task_keycode, FUN_20130c90, FUN_20131638 */

void uart4_send(uint param_1,uint param_2)

{
  uint uart4_tx_alloc_ret;
  
  uart4_tx_alloc_ret = uart4_tx_alloc(DAT_20450020 + 0x938);
  *(undefined2 *)(uart4_tx_alloc_ret + 4) = 0xaa;
  *(short *)(uart4_tx_alloc_ret + 6) = (short)param_2;
  memcpy(uart4_tx_alloc_ret + 8,param_1,param_2);
  uart4_tx_post(DAT_20450020 + 0x938,uart4_tx_alloc_ret);
  return;
}


// ===== uart4_wait_ready @ 20114edc (112 bytes)

/* waits for 0x2045001C; no caller */

undefined4 uart4_wait_ready(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 100;
  while( true ) {
    if (DAT_2045001c != '\0') {
      return 1;
    }
    if ((param_1 != 0) && (iVar1 = iVar1 + -1, iVar1 == 0)) break;
    itron_dly_tsk(1);
    if (((byte)DAT_20808a84 & 1) != 0) {
      return 1;
    }
  }
  DAT_2045001d = 1;
  return 0;
}


// ===== uart4_link_init @ 20114f4c (120 bytes)

/* creates the SCIF4 object 0x2045D4E0 and task "uart4"; no caller */

void uart4_link_init(void)

{
  uint itron_acre_tsk_ret;
  uint uVar1;
  void *scif4_get_ret;
  
  __aeabi_memclr4(&DAT_2045d4e0,0x1ae0);
  DAT_20450020 = uart4_obj_ctor(&DAT_2045d4e0);
  itron_acre_tsk_ret = itron_acre_tsk(0,(byte *)&ctsk_uart4_57dc);
  if ((0 < (int)itron_acre_tsk_ret) &&
     (uVar1 = itron_acre_flg(0,(byte *)&cflg_uart4), 0 < (int)uVar1)) {
    *(uint *)(DAT_20450020 + 0x14) = uVar1;
                    /* UART object on SCIF4 [doc, inference] */
    scif4_get_ret = scif4_get(uVar1);
    uVar1 = DAT_20450020;
    *(void **)(DAT_20450020 + 0x10) = scif4_get_ret;
    itron_sta_tsk(itron_acre_tsk_ret,uVar1);
    return;
  }
  return;
}


// ===== FUN_20114fc4 @ 20114fc4 (40 bytes)

code * FUN_20114fc4(code *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *extraout_r2;
  knl_tcb *p_knl_tcb;
  knl_flg *p_knl_flg;
  byte *pbVar10;
  bool bVar11;
  
  if (DAT_20450020 == 0) {
    return param_1;
  }
  uVar4 = *(uint *)(DAT_20450020 + 0x14);
  if (param_1 == (code *)0x0) {
    uVar7 = 0x4000;
  }
  else {
    uVar7 = 0x8000;
  }
  if (uVar7 == 0) {
    knl_sys.last_ercd = 0;
  }
  else {
    if ((uVar4 != 0) && (uVar4 < 0x41)) {
      software_interrupt(0);
      p_knl_flg = knl_flg_tab[uVar4];
      if (p_knl_flg == (knl_flg *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      for (pbVar10 = p_knl_flg->wq; uVar4 = (uint)*pbVar10, uVar4 == 0; pbVar10 = pbVar10 + 1) {
      }
      if (0xfd < uVar4) {
        p_knl_flg->flgptn = p_knl_flg->flgptn | uVar7;
        software_interrupt(0);
        return knl_svc_return;
      }
      p_knl_tcb = knl_tsk_tab[uVar4];
      uVar8 = (uint)p_knl_tcb->q_prev;
      bVar11 = uVar8 == uVar4;
      if (bVar11) {
        uVar8 = (uint)p_knl_flg->flgatr;
      }
      if (!bVar11 || (uVar8 & 2) != 0) {
        bVar11 = false;
        uVar7 = uVar7 | p_knl_flg->flgptn;
LAB_20150fa4:
        p_knl_tcb = knl_tsk_tab[*pbVar10];
        bVar1 = p_knl_tcb->q_prev;
        uVar4 = (uint)*pbVar10;
        do {
          bVar2 = p_knl_tcb->state;
          bVar3 = p_knl_tcb->q_next;
          uVar8 = *(uint *)(p_knl_tcb->sp + 8);
          if ((bVar2 & 1) == 0) {
            if ((uVar8 & ~uVar7) == 0) goto LAB_2015109c;
          }
          else if ((uVar8 & uVar7) != 0) {
LAB_2015109c:
            **(uint **)(p_knl_tcb->sp + 0xc) = uVar7;
            if ((bVar2 & 2) != 0) {
              knl_timeout_remove(p_knl_tcb,uVar4);
            }
            p_knl_tcb->state = 0x10;
            if (p_knl_tcb->f_0x09_u8 == 0) {
              iVar6 = (int)p_knl_tcb->pri;
              if (iVar6 < knl_sys.run_pri) {
                bVar11 = (bool)(bVar11 | iVar6 < knl_sys.run_pri);
              }
              knl_queue_move(knl_rdq + iVar6,p_knl_tcb,uVar4);
            }
            else {
              knl_queue_remove(p_knl_tcb,uVar4);
            }
            if ((bVar2 & 4) != 0) {
              p_knl_flg->flgptn = 0;
              if (!bVar11) {
                software_interrupt(0);
                return knl_svc_return;
              }
              software_interrupt(0);
              return knl_dispatch;
            }
          }
          if (bVar1 == uVar4) goto LAB_2015116c;
          p_knl_tcb = knl_tsk_tab[bVar3];
          uVar4 = (uint)bVar3;
        } while( true );
      }
      bVar1 = p_knl_tcb->state;
      if ((bVar1 & 1) == 0) {
        uVar7 = p_knl_flg->flgptn | uVar7;
        if ((*(uint *)(p_knl_tcb->sp + 8) & ~uVar7) != 0) goto LAB_20151030;
      }
      else {
        uVar7 = p_knl_flg->flgptn | uVar7;
        if ((*(uint *)(p_knl_tcb->sp + 8) & uVar7) == 0) {
LAB_20151030:
          p_knl_flg->flgptn = uVar7;
          software_interrupt(0);
          return knl_svc_return;
        }
      }
      puVar9 = *(uint **)(p_knl_tcb->sp + 0xc);
      *puVar9 = uVar7;
      if ((bVar1 & 4) != 0) {
        uVar7 = 0;
      }
      p_knl_flg->flgptn = uVar7;
      if ((bVar1 & 2) != 0) {
        knl_timeout_remove(p_knl_tcb,uVar4);
        puVar9 = extraout_r2;
      }
      p_knl_tcb->state = 0x10;
      if (p_knl_tcb->f_0x09_u8 == 0) {
        pcVar5 = (code *)knl_make_ready(p_knl_tcb,uVar4,puVar9,param_4);
        return pcVar5;
      }
      pcVar5 = (code *)knl_release_suspended();
      return pcVar5;
    }
    knl_sys.last_ercd = -0x12;
  }
  return (code *)knl_sys.last_ercd;
LAB_2015116c:
  do {
    pbVar10 = pbVar10 + 1;
  } while (*pbVar10 == 0);
  if (0xfd < *pbVar10) {
    p_knl_flg->flgptn = uVar7;
    if (!bVar11) {
      software_interrupt(0);
      return knl_svc_return;
    }
    software_interrupt(0);
    return knl_dispatch;
  }
  goto LAB_20150fa4;
}


// ===== mainlink_get_last_frame @ 20115000 (12 bytes)

/* copy of the newest MAIN frame (0x2045F8C0, 0x240 B) */

void mainlink_get_last_frame(uint param_1)

{
  memcpy(param_1,&ml_gui_snapshot,0x240);
  return;
}


// ===== mainlink_get_frame60 @ 2011500c (12 bytes)

/* copy of the newest 0x60 frame (0x2045FB00) */

void mainlink_get_frame60(uint param_1)

{
  memcpy(param_1,&DAT_2045fb00,0x240);
  return;
}


// ===== mainlink_got_frame60 @ 20115018 (12 bytes)

/* flag 0x20450026 */

byte mainlink_got_frame60(void)

{
  return g_ml.got60;
}


// ===== mainlink_get_settings24 @ 20115024 (24 bytes)

/* copies the 0x24 frame tail (0x2045006D) and returns flag 0x20450024 */

byte mainlink_get_settings24(uint param_1)

{
  FUN_201636f8(param_1,0x2045006d);
  return g_ml.got24;
}


// ===== mainlink_get_last21 @ 2011503c (36 bytes)

/* (out): copies the last 0x21 frame payload and its two following bytes (g_ml.last21, +0x12, +0x13)
   to out, returns the got21 flag [fact] */

byte mainlink_get_last21(byte *param_1)

{
  *param_1 = g_ml.last21;
  param_1[1] = g_ml.f_0x12_u8;
  param_1[2] = g_ml.f_0x13_u8;
  return g_ml.got21;
}


// ===== mainlink_got_esc @ 20115060 (12 bytes)

/* flag 0x2045005C, set by a 0x1B frame */

uint mainlink_got_esc(void)

{
  return g_ml.got_esc;
}


// ===== mainlink_last_frame_differs @ 2011506c (32 bytes)

bool mainlink_last_frame_differs(uint param_1)

{
  int iVar1;
  
  iVar1 = memcmp(&ml_gui_snapshot,param_1,0x240);
  return iVar1 != 0;
}


// ===== mainlink_set_last_frame @ 2011508c (16 bytes)

/* writes the 0x2045F8C0 snapshot (debug replay, GUI) */

void mainlink_set_last_frame(uint param_1)

{
  memcpy(&ml_gui_snapshot,param_1,0x240);
  return;
}


// ===== task_cmd_interval @ 2011509c (68 bytes)

void task_cmd_interval(void)

{
  g_ml.pace_count = 0;
  do {
    do {
      itron_tslp_tsk(0xffffffff);
    } while ((int)g_ml.pace_count < 1);
    itron_twai_sem(g_ml.pace_sem,0xffffffff);
    g_ml.pace_count = g_ml.pace_count - 1;
    itron_sig_sem(g_ml.pace_sem);
  } while( true );
}


// ===== mainlink_set_wait_cmd @ 201150e0 (12 bytes)

/* cmd byte of the frame waiting for ACK (0x2045002D) */

void mainlink_set_wait_cmd(byte param_1)

{
  g_ml.wait_cmd = param_1;
  return;
}


// ===== mainlink_get_wait_cmd @ 201150ec (12 bytes)

byte mainlink_get_wait_cmd(void)

{
  return g_ml.wait_cmd;
}


// ===== mainlink_submit @ 201150f8 (924 bytes)

/* adds checksum; F0/F1 go out at once; other frames go out if no ACK is pending, else are parked in
   per-type slots 0x2045F240..4B */

void mainlink_submit(uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = mainlink_tx_alloc((int)(g_ml.link_obj + 0x8218));
                    /* Mailbox header: tag 0xAA, length [fact: mainlink.md] */
  *(undefined2 *)(uVar2 + 4) = 0xaa;
  *(short *)(uVar2 + 6) = (short)param_2 + 1;
  memcpy(uVar2 + 8,param_1,param_2);
  bVar1 = *(byte *)(uVar2 + 8);
  if (bVar1 == 0xf0 || bVar1 == 0xf1) {
    cVar4 = '\0';
    iVar3 = 0;
    iVar5 = *(ushort *)(uVar2 + 6) - 1;
    if (0 < iVar5) {
      do {
        iVar6 = uVar2 + iVar3;
        iVar3 = iVar3 + 1;
        cVar4 = cVar4 + *(char *)(iVar6 + 8);
      } while (iVar3 < iVar5);
    }
    *(char *)((uint)*(ushort *)(uVar2 + 6) + uVar2 + 7) = cVar4;
                    /* F0/F1: send at once, no ACK wait [fact: mainlink.md] */
    mainlink_tx_post((int)(g_ml.link_obj + 0x8218),uVar2);
    return;
  }
  if (DAT_2080049c == '\0') {
    if (g_ml.ack_pending == 0) {
      __aeabi_memclr4(&DAT_2045efc0,0x105);
                    /* Keep a copy for a resend [fact: mainlink.md] */
      memcpy(&DAT_2045efc0,param_1,param_2);
      g_ml.resend_len = param_2;
      mainlink_set_wait_cmd(*(byte *)(uVar2 + 8));
      cVar4 = '\0';
      iVar3 = 0;
      iVar5 = *(ushort *)(uVar2 + 6) - 1;
      if (0 < iVar5) {
        do {
          iVar6 = uVar2 + iVar3;
          iVar3 = iVar3 + 1;
          cVar4 = cVar4 + *(char *)(iVar6 + 8);
        } while (iVar3 < iVar5);
      }
      *(char *)((uint)*(ushort *)(uVar2 + 6) + uVar2 + 7) = cVar4;
      mainlink_tx_post((int)(g_ml.link_obj + 0x8218),uVar2);
                    /* Wait for ACK: start the ACK timeout handler [fact: mainlink.md] */
      g_ml.ack_pending = 1;
      g_ml.retry_count = 0;
      itron_sta_cyc(g_ml.ack_tmo_cyc);
      return;
    }
    if (bVar1 == 0xe4) {
      DAT_20470108 = 0;
                    /* ACK pending: park the frame, one slot per type [fact: mainlink.md] */
      memcpy(&DAT_20470108,param_1,param_2);
      DAT_2045f241 = 1;
      return;
    }
    if (bVar1 < 0xe5) {
      if (bVar1 == 0xe0) {
        uVar2 = g_ml.e0_wr + 1 & 0xff;
        g_ml.e0_wr = (byte)(uVar2 % 10);
        iVar3 = (uVar2 % 10) * 5;
        FUN_20163668(iVar3 + 0x20470117,(uVar2 / 10) * -5,uVar2 * -0x33333333);
                    /* E0 keys park in a 10-entry ring [fact: mainlink.md] */
        memcpy(iVar3 + 0x20470117,param_1,param_2);
        DAT_2045f244 = 1;
        return;
      }
      if (bVar1 < 0xe1) {
        if (bVar1 == 0xc3) {
          __aeabi_memclr(&DAT_20470165,0x22);
          memcpy(&DAT_20470165,param_1,param_2);
          DAT_2045f249 = 1;
          return;
        }
        if (bVar1 == 0xc4) {
          __aeabi_memclr(&DAT_20470187,0x106);
          memcpy(&DAT_20470187,param_1,param_2);
          DAT_2045f24a = 1;
          return;
        }
        if (bVar1 == 0xc5) {
          FUN_20163684();
          memcpy(&DAT_2047028d,param_1,param_2);
          DAT_2045f24b = 1;
        }
      }
      else {
        if (bVar1 == 0xe2) {
          FUN_20163684(&DAT_20470149);
          memcpy(&DAT_20470149,param_1,param_2);
          DAT_2045f245 = 1;
          return;
        }
        if (bVar1 == 0xe3) {
          DAT_20470100 = 0;
          DAT_20470104 = 0;
          memcpy(&DAT_20470100,param_1,param_2);
          DAT_2045f240 = 1;
          return;
        }
      }
    }
    else {
      if (bVar1 == 0xe7) {
                    /* zero fill with alignment fix-up, 32-byte blocks [doc] */
        __aeabi_memclr(&DAT_20470153,9);
        memcpy(&DAT_20470153,param_1,param_2);
        DAT_2045f247 = 1;
        return;
      }
      if (bVar1 < 0xe8) {
        if (bVar1 == 0xe5) {
          DAT_2047010c = 0;
          memcpy(&DAT_2047010c,param_1,param_2);
          DAT_2045f242 = 1;
          return;
        }
        if (bVar1 == 0xe6) {
          DAT_2047014f = 0;
          DAT_20470150 = 0;
          DAT_20470151 = 0;
          DAT_20470152 = 0;
          memcpy(&DAT_2047014f,param_1,param_2);
          DAT_2045f246 = 1;
          return;
        }
      }
      else {
        if (bVar1 == 0xe8) {
          FUN_201636b8(&DAT_2047015c);
          memcpy(&DAT_2047015c,param_1,param_2);
          DAT_2045f248 = 1;
          return;
        }
        if (bVar1 == 0xf1) {
          __aeabi_memclr4(&DAT_20470110,7);
          memcpy(&DAT_20470110,param_1,param_2);
          DAT_2045f243 = 1;
          return;
        }
      }
    }
  }
  return;
}


// ===== mainlink_queue_frame @ 20115494 (644 bytes)

/* WARNING: Type propagation algorithm not settling */

void mainlink_queue_frame(uint param_1,uint param_2)

{
  int iVar1;
  undefined1 local_30 [4];
  uint local_2c;
  uint uStack_28;
  
  local_2c = param_1;
  uStack_28 = param_2;
  memcpy(&DAT_2045f4a0,param_1,param_2);
  if (DAT_20800496 != '\0' || DAT_20800494 != '\0') {
    if (DAT_2045f4a0 != -0x1a) {
      if ((gui_frame.cmd == 0x40) && (DAT_20800494 != '\0')) {
        if ((DAT_2045f4a0 == -0x20) &&
           (((DAT_2045f4a1 == 1 && (DAT_2045f4a2 == '\x03')) && (DAT_2045f4a3 == '\x0f')))) {
          DAT_20808533 = 1;
          return;
        }
        if (DAT_20800496 == '\0') goto LAB_20115704;
      }
      if (DAT_2045f4a0 != -0x20) {
        return;
      }
      if (2 < DAT_2045f4a1) {
        return;
      }
      if (DAT_2045f4a2 != '\x03') {
        return;
      }
      if (DAT_2045f4a3 != '\0') {
        return;
      }
    }
    goto LAB_20115704;
  }
  if (gui_frame.cmd == 0x7b) {
                    /* On the '{' screen a key frame becomes E4 [fact: mainlink.md] */
    if ((gui_frame.byte1 != 0) && (DAT_2045f4a0 == -0x1e)) {
      local_30[0] = 0xe4;
      DAT_20800488 = 1;
      mainlink_submit((uint)local_30,4);
      goto LAB_2011553c;
    }
  }
  else {
LAB_2011553c:
    if (((((gui_frame.cmd == 0x40) && (DAT_2045f4a0 == -0x20)) &&
         ((DAT_2045f4a1 == 1 &&
          ((((DAT_2045f4a2 == '\x03' && (DAT_2045f4a3 == '\x0f')) && (gui_frame.payload[0] == 0)) &&
           (((gui_frame.payload[4] & 0x10) != 0 && ((gui_frame.payload[3] & 2) != 0)))))))) &&
        (((uint)gui_frame.payload[2] + (gui_frame.payload[4] & 0xf) == 5 &&
         ((iVar1 = memcmp((gui_frame.payload[4] & 0xf) * 0x2d + 0x208f0c46,"FIRMWARE UPDATE      ",
                          0x15), iVar1 == 0 && (DAT_208000b2 == '\0')))))) &&
       (iVar1 = sd_state_bit6(), iVar1 != 0)) {
      g_ml.fwupdate_armed = 1;
      DAT_20800494 = 1;
      DAT_20808533 = 0;
      return;
    }
  }
  if (DAT_20800494 != '\0') {
                    /* FIRMWARE UPDATE entry + power key: arm update mode [fact: mainlink.md] */
    return;
  }
  if ((((g_ml.fwupdate_armed != 0) && (DAT_2045f4a0 == -0x20)) && (DAT_2045f4a1 == 0)) &&
     ((DAT_2045f4a2 == '\x03' && (DAT_2045f4a3 == '\x0f')))) {
    g_ml.fwupdate_armed = 0;
    return;
  }
LAB_20115704:
                    /* Pass the filtered frame on [fact: 0x201150F8] */
  mainlink_submit(local_2c,param_2);
  return;
}


// ===== mainlink_send_enc @ 20115780 (420 bytes)

/* E1 encoder frame: sent now, or merged into a 7x10 per-encoder queue (0x2045F0C5) while an ACK is
   pending */

void mainlink_send_enc(byte *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (DAT_20800495 == '\0') {
    return;
  }
  if (g_ml.ack_pending != 0) {
    itron_twai_sem(g_ml.enc_sem,0xffffffff);
    uVar3 = (uint)*param_1;
                    /* ACK pending: queue the encoder event [fact: mainlink.md] */
    g_ml.enc_queue_mask = g_ml.enc_queue_mask | (byte)(1 << uVar3);
    iVar4 = (&DAT_2045f224)[uVar3];
    if (iVar4 < 10) {
      copy5(&DAT_2045f0c5 + iVar4 * 5 + uVar3 * 0x32,param_1);
      (&DAT_2045f224)[uVar3] = iVar4 + 1;
    }
    else {
      iVar4 = iVar4 * 5 + uVar3 * 0x32;
      cVar1 = (&DAT_2045f0c5)[iVar4 + -4];
                    /* Copies 5 bytes [doc] */
      copy5(&DAT_2045f0c5 + iVar4 + -5,param_1);
      switch(uVar3) {
      case 1:
      case 2:
      case 3:
        iVar2 = (int)(char)param_1[1] + (int)cVar1;
        if (iVar2 < 0) {
          if (iVar2 < -0x7f) {
            iVar2 = -0x7f;
          }
          iVar2 = iVar2 + 0x100;
        }
        else if (0x7f < iVar2) {
          iVar2 = 0x7f;
        }
                    /* Queue full: sum the deltas, clamped to +-127 [fact: mainlink.md] */
        (&DAT_2045f0c5)[iVar4 + -4] = (char)iVar2;
        break;
      case 4:
      case 5:
        (&DAT_2045f0c5)[iVar4 + -4] = param_1[1];
      }
    }
    itron_sig_sem(g_ml.enc_sem);
    return;
  }
  uVar3 = mainlink_tx_alloc((int)(g_ml.link_obj + 0x8218));
  *(undefined2 *)(uVar3 + 4) = 0xaa;
  *(undefined2 *)(uVar3 + 6) = 7;
                    /* Send an E1 encoder frame now [fact: mainlink.md] */
  *(undefined1 *)(uVar3 + 8) = 0xe1;
  copy5(uVar3 + 9,param_1);
  FUN_201636a8(0x20450068);
  copy5(0x20450068,param_1);
  mainlink_set_wait_cmd(*(byte *)(uVar3 + 8));
  cVar1 = '\0';
  iVar4 = 0;
  iVar2 = *(ushort *)(uVar3 + 6) - 1;
  if (0 < iVar2) {
    do {
      iVar5 = uVar3 + iVar4;
      iVar4 = iVar4 + 1;
      cVar1 = cVar1 + *(char *)(iVar5 + 8);
    } while (iVar4 < iVar2);
  }
  *(char *)((uint)*(ushort *)(uVar3 + 6) + uVar3 + 7) = cVar1;
  mainlink_tx_post((int)(g_ml.link_obj + 0x8218),uVar3);
  g_ml.ack_pending = 1;
  g_ml.retry_count = 0;
  itron_sta_cyc(g_ml.ack_tmo_cyc);
  return;
}


// ===== minmax4 @ 2011593c (80 bytes)

/* min or max of 4 bytes */

uint minmax4(int param_1,byte *param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 1;
  uVar2 = (uint)*param_2;
  if (param_1 != 0) {
    do {
      pbVar1 = param_2 + uVar3;
      uVar3 = uVar3 + 1 & 0xff;
      if (uVar2 < *pbVar1) {
        uVar2 = (uint)*pbVar1;
      }
    } while (uVar3 < 4);
    return uVar2;
  }
  do {
    pbVar1 = param_2 + uVar3;
    uVar3 = uVar3 + 1 & 0xff;
    if (*pbVar1 < uVar2) {
      uVar2 = (uint)*pbVar1;
    }
  } while (uVar3 < 4);
  return uVar2;
}


// ===== pot5_filter @ 2011598c (188 bytes)

/* pot id 5 jitter filter (last 4 values span > 2, value 3..252) */

uint pot5_filter(uint param_1)

{
  uint minmax4_ret;
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (g_ml.pot5_last[0] != param_1) {
    if (g_ml.pot5_sum == 1) {
      uVar1 = param_1 | param_1 << 8;
      g_ml.pot5_sum = 0;
      g_ml.pot5_hist = (byte  [4])(uVar1 | uVar1 << 0x10);
    }
    g_ml.pot5_last[0] = (byte)param_1;
    g_ml.pot5_last[1] = g_ml.pot5_last[1] + 1;
    if (3 < g_ml.pot5_last[1]) {
      g_ml.pot5_last[1] = 0;
    }
    g_ml.pot5_hist[g_ml.pot5_last[1]] = g_ml.pot5_last[0];
    if (((param_1 - 3 < 0xfa) && (g_ml.pot5_hist[0] != g_ml.pot5_hist[2])) &&
       (g_ml.pot5_hist[1] != g_ml.pot5_hist[3])) {
                    /* min or max of 4 bytes [doc, inference] */
      uVar1 = minmax4(1,g_ml.pot5_hist);
      minmax4_ret = minmax4(0,g_ml.pot5_hist);
      if (2 < (int)(uVar1 - minmax4_ret)) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


// ===== pot4_filter @ 20115a48 (188 bytes)

/* pot id 4 jitter filter */

uint pot4_filter(uint param_1)

{
  uint minmax4_ret;
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (g_ml.pot4_last[0] != param_1) {
    if (g_ml.pot4_sum == 1) {
      uVar1 = param_1 | param_1 << 8;
      g_ml.pot4_sum = 0;
      g_ml.pot4_hist = (byte  [4])(uVar1 | uVar1 << 0x10);
    }
    g_ml.pot4_last[0] = (byte)param_1;
    g_ml.pot4_last[1] = g_ml.pot4_last[1] + 1;
    if (3 < g_ml.pot4_last[1]) {
      g_ml.pot4_last[1] = 0;
    }
    g_ml.pot4_hist[g_ml.pot4_last[1]] = g_ml.pot4_last[0];
    if (((param_1 - 3 < 0xfa) && (g_ml.pot4_hist[0] != g_ml.pot4_hist[2])) &&
       (g_ml.pot4_hist[1] != g_ml.pot4_hist[3])) {
                    /* min or max of 4 bytes [doc, inference] */
      uVar1 = minmax4(1,g_ml.pot4_hist);
      minmax4_ret = minmax4(0,g_ml.pot4_hist);
      if (2 < (int)(uVar1 - minmax4_ret)) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


// ===== mainlink_renc_event @ 20115b04 (220 bytes)

/* encoder event from the renc tasks -> E4 (leave screen saver) and/or E1 */

void mainlink_renc_event(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_10;
  
  if (DAT_20800496 != '\0') {
    return;
  }
  local_10 = param_4;
                    /* Returns the full-mode flag 0x208003A4 [doc] */
  iVar2 = full_mode_get();
  if (iVar2 == 0) {
    return;
  }
  if (*param_1 == 4) {
    uVar3 = pot4_filter((uint)param_1[1]);
    if (uVar3 == 0) {
      bVar1 = false;
      goto LAB_20115b68;
    }
  }
  else if (*param_1 == 5) {
    uVar3 = pot5_filter((uint)param_1[1]);
    bVar1 = false;
    if (uVar3 == 0) goto LAB_20115b68;
  }
  bVar1 = true;
LAB_20115b68:
  if ((gui_frame.cmd == 0x7b) && (gui_frame.byte1 != 0)) {
    if (bVar1) {
      gui_frame.byte1 = 0;
      local_10 = 0xe4;
      DAT_20800488 = 1;
      mainlink_queue_frame(&local_10,4);
      if (*param_1 == 4 || *param_1 == 5) {
        mainlink_send_enc(param_1);
      }
    }
    return;
  }
  mainlink_send_enc(param_1);
  return;
}


// ===== mainlink_tx_raw @ 20115be0 (148 bytes)

/* frame = 0xAA tag, length, payload, sum8; posts to the TX task (used for resends) */

void mainlink_tx_raw(uint param_1,uint param_2)

{
  uint mainlink_tx_alloc_ret;
  int i;
  char cVar1;
  int iVar2;
  int iVar3;
  
  mainlink_tx_alloc_ret = mainlink_tx_alloc((int)(g_ml.link_obj + 0x8218));
  *(undefined2 *)(mainlink_tx_alloc_ret + 4) = 0xaa;
  *(short *)(mainlink_tx_alloc_ret + 6) = (short)param_2 + 1;
  memcpy(mainlink_tx_alloc_ret + 8,param_1,param_2);
  cVar1 = '\0';
  i = 0;
  iVar2 = *(ushort *)(mainlink_tx_alloc_ret + 6) - 1;
  if (0 < iVar2) {
    do {
      iVar3 = mainlink_tx_alloc_ret + i;
      i = i + 1;
      cVar1 = cVar1 + *(char *)(iVar3 + 8);
    } while (i < iVar2);
  }
  *(char *)((uint)*(ushort *)(mainlink_tx_alloc_ret + 6) + mainlink_tx_alloc_ret + 7) = cVar1;
  mainlink_tx_post((int)(g_ml.link_obj + 0x8218),mainlink_tx_alloc_ret);
  return;
}


// ===== mainlink_tx_e1_raw @ 20115c74 (136 bytes)

/* resend of the last E1 (encoder) frame kept at 0x20450068 */

void mainlink_tx_e1_raw(uint param_1)

{
  uint mainlink_tx_alloc_ret;
  uint i;
  char cVar1;
  int iVar2;
  
  mainlink_tx_alloc_ret = mainlink_tx_alloc((int)(g_ml.link_obj + 0x8218));
  *(undefined2 *)(mainlink_tx_alloc_ret + 4) = 0xaa;
  *(undefined2 *)(mainlink_tx_alloc_ret + 6) = 7;
  *(undefined1 *)(mainlink_tx_alloc_ret + 8) = 0xe1;
                    /* Copies 5 bytes [doc] */
  copy5(mainlink_tx_alloc_ret + 9,param_1);
  cVar1 = '\0';
  i = 0;
  do {
    iVar2 = mainlink_tx_alloc_ret + i;
    i = i + 1;
    cVar1 = cVar1 + *(char *)(iVar2 + 8);
  } while (i < 6);
  *(char *)((uint)*(ushort *)(mainlink_tx_alloc_ret + 6) + mainlink_tx_alloc_ret + 7) = cVar1;
  mainlink_tx_post((int)(g_ml.link_obj + 0x8218),mainlink_tx_alloc_ret);
  return;
}


// ===== mainlink_flush_parked @ 20115cfc (608 bytes)

/* after an ACK: sends the next parked frame (E3,E4,E5,F1,E0 ring,E2,E6,E7,E8,C3,C4,C5 order) */

void mainlink_flush_parked(void)

{
  uint uVar1;
  
  if (DAT_2045f240 == '\x01') {
    mainlink_submit(0x20470100,8);
    DAT_20470100 = 0;
    DAT_20470104 = 0;
    DAT_2045f240 = 0;
    return;
  }
  if (DAT_2045f241 == '\x01') {
    mainlink_submit(0x20470108,4);
    DAT_20470108 = 0;
    DAT_2045f241 = 0;
    return;
  }
  if (DAT_2045f242 == '\x01') {
    mainlink_submit(0x2047010c,4);
    DAT_2047010c = 0;
    DAT_2045f242 = 0;
    return;
  }
  if (DAT_2045f243 == '\x01') {
    mainlink_submit(0x20470110,7);
    __aeabi_memclr4(&DAT_20470110,7);
    DAT_2045f243 = 0;
    return;
  }
  if (DAT_2045f244 == '\x01') {
    uVar1 = (g_ml.e0_rd + 1 & 0xff) % 10;
    g_ml.e0_rd = (byte)uVar1;
    mainlink_submit(uVar1 * 5 + 0x20470117,5);
    uVar1 = (uint)g_ml.e0_rd;
    FUN_20163668(uVar1 * 5 + 0x20470117);
    if (g_ml.e0_wr == uVar1) {
      DAT_2045f244 = '\0';
    }
    return;
  }
  if (DAT_2045f245 == '\x01') {
    mainlink_submit(0x20470149,6);
    FUN_20163684(&DAT_20470149);
    DAT_2045f245 = 0;
    return;
  }
  if (DAT_2045f246 == '\x01') {
    mainlink_submit(0x2047014f,4);
    DAT_2047014f = 0;
    DAT_20470150 = 0;
    DAT_20470151 = 0;
    DAT_20470152 = 0;
    DAT_2045f246 = 0;
    return;
  }
  if (DAT_2045f247 != '\x01') {
    if (DAT_2045f248 == '\x01') {
      mainlink_submit(0x2047015c,9);
      FUN_201636b8(&DAT_2047015c);
      DAT_2045f248 = 0;
      return;
    }
    if (DAT_2045f249 != '\x01') {
      if (DAT_2045f24a != '\x01') {
        if (DAT_2045f24b == '\x01') {
          mainlink_submit(0x2047028d,6);
          FUN_20163684(&DAT_2047028d);
          DAT_2045f24b = '\0';
        }
        return;
      }
      mainlink_submit(0x20470187,0x106);
      __aeabi_memclr(&DAT_20470187,0x106);
      DAT_2045f24a = 0;
      return;
    }
    mainlink_submit(0x20470165,0x22);
    __aeabi_memclr(&DAT_20470165,0x22);
    DAT_2045f249 = 0;
    return;
  }
  mainlink_submit(0x20470153,9);
                    /* zero fill with alignment fix-up, 32-byte blocks [doc] */
  __aeabi_memclr(&DAT_20470153,9);
  DAT_2045f247 = 0;
  return;
}


// ===== mainlink_flush_enc @ 20115f5c (248 bytes)

/* after an ACK: sends the oldest queued encoder event */

void mainlink_flush_enc(void)

{
  uint uVar1;
  int i;
  uint uVar2;
  int iVar3;
  byte abStack_28 [12];
  
  uVar2 = 8;
  itron_twai_sem(g_ml.enc_sem,0xffffffff);
  uVar1 = 0;
  do {
    if (((uint)g_ml.enc_queue_mask & 1 << (uVar1 & 0xff)) != 0) {
      uVar2 = uVar1;
      if ((int)(&DAT_2045f224)[uVar1] < 2) {
        g_ml.enc_queue_mask = g_ml.enc_queue_mask & ~(byte)(1 << (uVar1 & 0xff));
      }
      break;
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 7);
  if (7 < (int)uVar2) {
    g_ml.enc_queue_mask = 0;
    FUN_20163668(&DAT_2045f0c5 + (&DAT_2045f224)[uVar2] * 5 + uVar2 * 0x32);
    return;
  }
                    /* Copies 5 bytes [doc] */
  copy5(abStack_28);
  iVar3 = (&DAT_2045f224)[uVar2];
  i = 0;
  if (0 < iVar3) {
    do {
      copy5(&DAT_2045f0c5 + i * 5 + uVar2 * 0x32,&DAT_2045f0c5 + i * 5 + uVar2 * 0x32 + 5);
      i = i + 1;
    } while (i < iVar3);
  }
  (&DAT_2045f224)[uVar2] = iVar3 + -1;
  itron_sig_sem(g_ml.enc_sem);
  mainlink_send_enc(abStack_28);
  return;
}


// ===== mainlink_on_ack @ 2011606c (72 bytes)

/* 0x06 from MAIN: stop timeout, clear wait flag, flush parked frames */

void mainlink_on_ack(void)

{
  if (g_ml.ack_pending != 0) {
    itron_clr_flg(g_ml.retry_flg,0);
                    /* ACK: stop the timeout, clear pending [fact: mainlink.md] */
    itron_stp_cyc(g_ml.ack_tmo_cyc);
    g_ml.ack_pending = 0;
                    /* Send the next parked frame, then a queued encoder [fact: mainlink.md] */
    mainlink_flush_parked();
    if (g_ml.enc_queue_mask != 0) {
      mainlink_flush_enc();
    }
    g_ml.retry_count = 0;
  }
  return;
}


// ===== mainlink_on_nak @ 201160b4 (140 bytes)

/* 0x15 from MAIN: resend at once (max 3), then give up */

void mainlink_on_nak(void)

{
  byte bVar1;
  
  if (g_ml.ack_pending != 0) {
    itron_stp_cyc(g_ml.ack_tmo_cyc);
    if (2 < g_ml.retry_count) {
      if (g_ml.err_box_on_fail != 0) {
        bVar1 = mainlink_get_wait_cmd();
                    /* 3 failures after a 0xDB hello: show the command in hex [fact: mainlink.md] */
        gui_link_error_popup(0,bVar1);
        return;
      }
                    /* 3 failures: reset MAIN and the DISPLAY [fact: 0x20114DF4] */
      system_reboot();
      return;
    }
    bVar1 = mainlink_get_wait_cmd();
    if (bVar1 == 0xe1) {
      mainlink_tx_e1_raw(0x20450068);
    }
    else {
                    /* NAK: resend the kept frame at once [fact: mainlink.md] */
      mainlink_tx_raw(0x2045efc0,g_ml.resend_len);
    }
    itron_sta_cyc(g_ml.ack_tmo_cyc);
    g_ml.retry_count = g_ml.retry_count + 1;
  }
  return;
}


// ===== mainlink_tx_reset @ 20116140 (124 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* drops the pending/parked state and the encoder queue (0x7F maintenance key, retry task) */

void mainlink_tx_reset(void)

{
  int j;
  int i;
  
  itron_clr_flg(g_ml.retry_flg,0);
  itron_stp_cyc(g_ml.ack_tmo_cyc);
  g_ml.ack_pending = 0;
  i = 0;
  g_ml.enc_queue_mask = 0;
  g_ml.retry_count = 0;
  _DAT_2045f240 = 0;
  _DAT_2045f244 = 0;
  _DAT_2045f248 = 0;
  do {
    j = 0;
    do {
      FUN_20163668(&DAT_2045f0c5 + j * 5 + i * 0x32);
      j = j + 1;
    } while (j < 10);
    i = i + 1;
  } while (i < 7);
  return;
}


// ===== task_mainlink_retry @ 201161bc (232 bytes)

void task_mainlink_retry(void)

{
  byte bVar1;
  void *itron_twai_flg_ret;
  uint uStack_4;
  
  do {
    while( true ) {
      do {
        do {
          itron_twai_flg_ret = itron_twai_flg(g_ml.retry_flg,1,5,&uStack_4,-1);
          itron_stp_cyc(g_ml.ack_tmo_cyc);
        } while (itron_twai_flg_ret != (void *)0x0);
      } while (uStack_4 != 1);
      if (DAT_2080049c == '\0') break;
      mainlink_tx_reset();
    }
    if (g_ml.ack_pending == 0) {
      itron_clr_flg(g_ml.retry_flg,0);
    }
    else if (g_ml.retry_count < 3) {
      bVar1 = mainlink_get_wait_cmd();
      if (bVar1 == 0xe1) {
        mainlink_tx_e1_raw(0x20450068);
      }
      else {
        mainlink_tx_raw(0x2045efc0,g_ml.resend_len);
      }
      itron_sta_cyc(g_ml.ack_tmo_cyc);
      g_ml.retry_count = g_ml.retry_count + 1;
    }
    else if (g_ml.err_box_on_fail == 0) {
      system_reboot();
    }
    else {
      bVar1 = mainlink_get_wait_cmd();
      gui_link_error_popup(1,bVar1);
    }
  } while( true );
}


// ===== mainlink_send_hello @ 201162a4 (116 bytes)

/* F0 frame: version 01-08, date 2023-06-29, power-up key code */

void mainlink_send_hello(byte param_1)

{
  undefined4 local_10;
  undefined3 local_c;
  byte local_9;
  undefined4 local_8;
  
  local_8 = 0;
  local_10 = 0x200801f0;
  _local_c = CONCAT13(param_1,0x290623);
  mainlink_queue_frame(&local_10,9);
  return;
}


// ===== mainlink_send_f1 @ 20116334 (52 bytes)

/* F1 frame with one sub-command byte; no caller in V01-08 */

void mainlink_send_f1(undefined1 param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = (uint)CONCAT11(param_1,0xf1);
  mainlink_queue_frame(&local_10,7);
  return;
}

