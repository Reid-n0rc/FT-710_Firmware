// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201322c8 @ 201322c8 (16 bytes)

/* WARNING: Removing unreachable block (ram,0x2015a584) */

void FUN_201322c8(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc,param_1);
  bVar1 = usbkbd_last_key();
  fwupdate_set_hotkey(bVar1);
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uVar2,4,400,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,DAT_20808540,4,400,0xf,0x20800cac);
  gui_update_layers();
  uStack_4c = fb_get_layer_addr(DAT_208085bc);
  iVar3 = sd_state_bit7();
  if (iVar3 == 0) {
    uStack_38 = 0;
    uStack_4c = 0x447;
    uStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    mainlink_send_ui_c3((void *)0x208f4d1c,(uint)&uStack_4c);
    return;
  }
  fwfile_check_versions(0x208f4bfc);
  iVar3 = 0;
  do {
    gui_draw_text(uStack_4c,iVar3 * 0x48 + 0x208f4bfd,iVar3 * 0x44 + 0x41U & 0xffff,0xc4);
    gui_draw_text(uStack_4c,&DAT_208f4c11 + iVar3 * 0x48,iVar3 * 0x44 + 0x43U & 0xffff,0x1dc);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  gui_update_layers();
  fb_get_layer_addr(DAT_208085bc);
  gui_scope_draw_hold_set(1);
  uVar2 = fwfile_status_text(0x208f4bfc,0);
  gui_update_layers();
  uStack_4c = fb_get_layer_addr(DAT_208085bc);
  FUN_20133620();
  gui_scope_draw_hold_set(0);
  itron_dly_tsk(0x32);
  iVar3 = sd_state_bit6();
  if (iVar3 == 0) {
    mainlink_send_ui_e2((void *)0x208f4d1c,(uint)&stack0xffffff88);
    return;
  }
  if (uVar2 == 1 || uVar2 == 3) {
    uStack_38 = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_4c = (uint)CONCAT11((char)uVar2,0x47);
    uStack_3c = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    mainlink_send_ui_c3((void *)0x208f4d1c,(uint)&uStack_4c);
    return;
  }
  iVar3 = 0x47;
  uStack_5c = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  if (uVar2 == 0) {
    iVar3 = 0;
  }
  uStack_64 = 0;
  uStack_70._0_2_ = CONCAT11((char)uVar2,0x47);
  uStack_70 = (uint)(ushort)uStack_70;
  uStack_60 = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  if (uVar2 == 0) {
    do {
      if ((&DAT_208f4bfc)[iVar3 * 0x48] == '\x01') {
        uStack_70._0_3_ =
             CONCAT12(uStack_70._2_1_ | (byte)(1 << (7U - iVar3 & 0xff)),(ushort)uStack_70);
        uStack_70 = (uint)(uint3)uStack_70;
      }
      if ((&DAT_208f4bfc)[iVar3 * 0x48] == '\x03') {
        uStack_6c = (uint)(byte)((byte)uStack_6c | (byte)(1 << (7U - iVar3 & 0xff)));
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
  }
  iVar3 = 0;
  do {
    sprintf(&stack0xffffff88,&DAT_2042813c,(&DAT_208f4bf4)[iVar3]);
    iVar4 = FUN_2014e208(iVar3 * 0x48 + 0x208f4c25,&stack0xffffff88);
    if (0 < iVar4) {
      uStack_70 = CONCAT13(uStack_70._3_1_ | (byte)(1 << (7U - iVar3 & 0xff)),(uint3)uStack_70);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  mainlink_send_ui_c3((void *)0x208f4d1c,(uint)&uStack_70);
  iVar3 = 0;
  do {
    uVar2 = iVar3 * 0x44 + 0x41;
    fb_fill_rect(uStack_4c,0x821,uVar2 & 0xffff,0x25c,800,0x1a);
    gui_draw_text(uStack_4c,iVar3 * 0x48 + 0x208f4bfd,uVar2 & 0xffff,0xc4);
    gui_draw_text(uStack_4c,&DAT_208f4c11 + iVar3 * 0x48,iVar3 * 0x44 + 0x43U & 0xffff,0x1dc);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  FUN_2015a4c8();
  return;
}


// ===== FUN_201322d8 @ 201322d8 (12 bytes)

void FUN_201322d8(undefined4 param_1)

{
  FUN_2015a8dc(&DAT_208f4bf4,param_1);
  return;
}


// ===== FUN_201322e4 @ 201322e4 (12 bytes)

void FUN_201322e4(undefined4 param_1)

{
  FUN_20159058(&DAT_208f4bf4,param_1);
  return;
}


// ===== FUN_201322f0 @ 201322f0 (12 bytes)

void FUN_201322f0(void)

{
  FUN_20159d98(&DAT_208f4bf4,"YAESU FT-710 FIRMWARE UPDATE");
  return;
}


// ===== vdc5_module_start @ 20132320 (120 bytes)

/* init_func passed to r_vdc5_initialize: STBCR9 clock on for ch0/ch1 */

void vdc5_module_start(char param_1)

{
  byte bVar1;
  
  bVar1 = CPG_STBCR9;
  if (param_1 != '\0') {
    CPG_STBCR9 = bVar1 & 0xfc;
    bVar1 = CPG_STBREQ2;
    CPG_STBREQ2 = bVar1 & 0xef;
    do {
      bVar1 = CPG_STBACK2;
    } while ((bVar1 & 0x10) != 0);
    return;
  }
  CPG_STBCR9 = bVar1 & 0xfd;
  bVar1 = CPG_STBREQ2;
  CPG_STBREQ2 = bVar1 & 0xdf;
  do {
    bVar1 = CPG_STBACK2;
  } while ((bVar1 & 0x20) != 0);
  return;
}


// ===== vdc5_module_stop @ 20132398 (100 bytes)

/* STBCR9 clock off for ch0/ch1 */

void vdc5_module_stop(char param_1)

{
  byte bVar1;
  
  bVar1 = CPG_STBREQ2;
  if (param_1 == '\0') {
    bVar1 = bVar1 | 0x20;
  }
  else {
    bVar1 = bVar1 | 0x10;
  }
  CPG_STBREQ2 = bVar1;
  if (param_1 == '\0') {
    do {
      bVar1 = CPG_STBACK2;
    } while ((bVar1 & 0x20) == 0);
    bVar1 = CPG_STBCR9;
    bVar1 = bVar1 | 2;
  }
  else {
    do {
      bVar1 = CPG_STBACK2;
    } while ((bVar1 & 0x10) == 0);
    bVar1 = CPG_STBCR9;
    bVar1 = bVar1 | 1;
  }
  CPG_STBCR9 = bVar1;
  return;
}


// ===== lcd_tcon_cfg_ch0 @ 201323fc (68 bytes)

/* TCON pin table for the parallel RGB TFT (ch0) */

void lcd_tcon_cfg_ch0(void *param_1)

{
  if (param_1 != (void *)0x0) {
    *(undefined **)param_1 = &DAT_203a6fd4;
    *(undefined **)((int)param_1 + 4) = &DAT_203a6fe8;
    *(undefined **)((int)param_1 + 8) = &DAT_203a6fde;
    *(undefined **)((int)param_1 + 0xc) = &DAT_203a6ff2;
    *(undefined4 *)((int)param_1 + 0x10) = 0;
    *(undefined4 *)((int)param_1 + 0x14) = 0;
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined **)((int)param_1 + 0x1c) = &DAT_203a6ffc;
  }
  return;
}


// ===== dvi_tcon_cfg_ch1 @ 20132440 (92 bytes)

/* TCON pin table for the LVDS/DVI channel (ch1), 800x480 or 800x600 */

void dvi_tcon_cfg_ch1(int param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    *(undefined **)param_2 = &UNK_203a7006 + param_1 * 10;
    *(undefined **)((int)param_2 + 4) = &UNK_203a702e + param_1 * 10;
    *(undefined **)((int)param_2 + 8) = &UNK_203a701a + param_1 * 10;
    *(undefined **)((int)param_2 + 0xc) = &UNK_203a7042 + param_1 * 10;
    *(undefined4 *)((int)param_2 + 0x10) = 0;
    *(undefined4 *)((int)param_2 + 0x14) = 0;
    *(undefined4 *)((int)param_2 + 0x18) = 0;
    *(undefined **)((int)param_2 + 0x1c) = &UNK_203a7056 + param_1 * 10;
  }
  return;
}


// ===== lvds_pll_cfg @ 2013249c (104 bytes)

/* LVDS PLL: 27 MHz in, FD 175 (800x480) or 207 (800x600), RD 4, OD 2, to ch1 */

void lvds_pll_cfg(undefined4 param_1,int param_2)

{
  DAT_208f4d44 = 0;
  DAT_208f4d45 = 0;
  DAT_208f4d46 = 0x10;
  DAT_208f4d48 = 2;
  DAT_208f4d49 = 1;
  if (param_2 != 0) {
    DAT_208f4d4a = 0xcf;
    DAT_208f4d4c = 4;
    DAT_208f4d4e = 2;
    return;
  }
  DAT_208f4d4a = 0xaf;
  DAT_208f4d4c = 4;
  DAT_208f4d4e = 2;
  return;
}


// ===== vdc5_sync_setup @ 20132504 (228 bytes)

/* timing: ch0 1016x525 (800x480); ch1 1088x517 (800x480) or 1056x628 (800x600) */

uint vdc5_sync_setup(int param_1,int param_2)

{
  uint uVar1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  
  if (param_1 == 0) {
    local_1e = 0x20c;
    local_1c = 0x3f7;
    local_18 = 0x20;
    local_14 = 0x58;
    local_16 = 0x1e0;
  }
  else if (param_2 == 0) {
    local_1e = 0x204;
    local_1c = 0x43f;
    local_18 = 0x1f;
    local_14 = 0xe0;
    local_16 = 0x1e0;
  }
  else {
    local_1e = 0x273;
    local_1c = 0x41f;
    local_18 = 0x1b;
    local_16 = 600;
    local_14 = 0xd8;
  }
  local_10 = 0;
  local_12 = 800;
  local_1a = 0;
  local_1f = 0;
  local_20 = 1;
  uVar1 = r_vdc5_sync_control(param_1,&local_20);
  return uVar1;
}


// ===== vdc5_output_setup @ 201325e8 (152 bytes)

/* r_vdc5_display_output wrapper per channel */

uint vdc5_output_setup(int param_1,int param_2)

{
  uint uVar1;
  undefined2 local_40;
  undefined2 local_3e;
  undefined1 auStack_3c [32];
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined4 local_14;
  
  if (param_1 == 0) {
    local_40 = 0x1fb;
    local_3e = 0;
    lcd_tcon_cfg_ch0(auStack_3c);
    local_1a = 1;
  }
  else {
    if (param_2 == 0) {
      local_40 = 0x21f;
    }
    else {
      local_40 = 0x20f;
    }
    local_3e = 0;
    dvi_tcon_cfg_ch1(param_2,auStack_3c);
    local_1a = 0;
  }
  local_1b = 0;
  local_1c = 0;
  local_18 = 0;
  local_17 = 0;
  local_19 = 0;
  local_16 = 0;
  local_14 = 0;
  uVar1 = r_vdc5_display_output(param_1,&local_40);
  return uVar1;
}


// ===== cursor_rect_calc @ 20132680 (124 bytes)

/* 12x21 mouse-cursor window for graphics 3 */

void cursor_rect_calc(short *param_1,int param_2,short param_3,short param_4)

{
  short sVar1;
  short sVar2;
  
  sVar1 = (short)DAT_20808574;
  sVar2 = (short)DAT_20808578;
  if (param_2 != 0) {
    sVar1 = (short)DAT_2080857c;
    sVar2 = (short)DAT_20808580;
  }
  *param_1 = sVar2 + param_4;
  param_1[1] = 0x15;
  param_1[2] = sVar1 + param_3;
  param_1[3] = 0xc;
  return;
}


// ===== fb_get_layer_addr @ 201326fc (88 bytes)

/* 800x480 RGB565 frame buffers at 0x60000000 + n*0xBB800 */

undefined * fb_get_layer_addr(undefined4 param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 0:
    iVar1 = 0xbb800;
    break;
  case 1:
    return &DAT_605048a0;
  case 2:
    iVar1 = 0x177000;
    break;
  case 3:
    return (undefined *)0x60000000;
  case 4:
    iVar1 = 0x232800;
    break;
  case 5:
    iVar1 = 0x2ee000;
    break;
  default:
    return (undefined *)0x0;
  }
  return (undefined *)(iVar1 + 0x60000000);
}


// ===== vdc5_layers_setup @ 2013276c (920 bytes)

/* graphics 0..3 read setup, chroma key, start; then enables the VLINE callback */

uint vdc5_layers_setup(uint param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined1 local_34 [8];
  uint local_2c;
  int iStack_28;
  
  if (param_1 == 0) {
    uVar4 = 0x1e00020;
    uVar5 = 0x3200058;
  }
  else if (param_2 == 0) {
    uVar4 = 0x1e0001f;
    uVar5 = 0x32000e0;
  }
  else {
    uVar4 = 0x1e00057;
    uVar5 = 0x32000d8;
  }
  local_44 = 0;
  local_4c = 0;
  local_48 = 0;
  local_2c = param_1;
  iStack_28 = param_2;
  uVar6 = fb_get_layer_addr(0);
  local_3c = fb_get_layer_addr(1,(int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
  local_40 = fb_get_layer_addr(3);
  uVar2 = fb_get_layer_addr(5);
  local_68 = 0x100;
  local_60 = 0x640;
  local_58 = 0x6000000;
  local_5c = 0;
  local_54 = uVar4;
  local_50 = uVar5;
  uVar3 = r_vdc5_read_data_control(local_2c,3,(uint)&local_68);
  if (((uVar3 == 0) && (uVar3 = r_vdc5_chromakey(local_2c,3,1,(uint)&local_4c), uVar3 == 0)) &&
     (uVar3 = layer_alpha_rect_reapply(local_2c,3), uVar3 == 0)) {
    local_68 = 0x100;
    local_64 = local_3c;
    local_58 = 0x6000000;
    local_5c = 0;
    local_60 = 0x640;
    local_54 = uVar4;
    local_50 = uVar5;
    uVar3 = r_vdc5_read_data_control(local_2c,4,(uint)&local_68);
    if ((uVar3 == 0) && (uVar3 = r_vdc5_chromakey(local_2c,4,1,(uint)&local_4c), uVar3 == 0)) {
      uVar3 = layer_alpha_rect_reapply(local_2c,4);
    }
    DAT_208f4d50 = local_64;
    if (uVar3 == 0) {
      local_68 = 0x100;
      local_58 = 0x6000000;
      local_64 = local_40;
      local_5c = 0;
      local_60 = 0x640;
      local_54 = uVar4;
      local_50 = uVar5;
      uVar3 = r_vdc5_read_data_control(local_2c,5,(uint)&local_68);
      if ((uVar3 == 0) && (uVar3 = r_vdc5_chromakey(local_2c,5,1,(uint)&local_4c), uVar3 == 0)) {
        uVar3 = layer_alpha_rect_reapply(local_2c,5);
      }
      DAT_208f4d60 = local_64;
      if (uVar3 == 0) {
        local_68 = 0x100;
        local_60 = 0x640;
        local_58 = 0x6000000;
        local_5c = 0;
        local_64 = uVar2;
        local_54 = uVar4;
        local_50 = uVar5;
        cursor_rect_calc((short *)&local_40,local_2c,400,0xf0);
        DAT_20808584 = (short)local_40;
        DAT_20808586 = local_40._2_2_;
        DAT_20808588 = (undefined2)local_3c;
        DAT_2080858a = local_3c._2_2_;
        local_54 = local_40;
        local_50 = local_3c;
        uVar3 = r_vdc5_read_data_control(local_2c,6,(uint)&local_68);
        if ((uVar3 == 0) && (uVar3 = r_vdc5_chromakey(local_2c,6,1,(uint)&local_4c), uVar3 == 0)) {
          uVar3 = layer_alpha_rect_reapply(local_2c,6);
        }
        DAT_208f4d78 = &DAT_20808584;
        DAT_208f4d74 = 0;
        DAT_208f4d7c = 0;
        DAT_208f4d70 = uVar2;
        if ((uVar3 == 0) && (uVar3 = vdc5_vline_cb_enable(local_2c), uVar3 == 0)) {
          local_34[0] = 2;
          local_38 = local_34;
          r_vdc5_start_process(local_2c,3,(uint)&local_38);
          local_34[0] = 3;
          local_38 = local_34;
          r_vdc5_start_process(local_2c,4,(uint)&local_38);
          bVar1 = r_vdc5_start_process(local_2c,5,(uint)&local_38);
          uVar3 = (uint)bVar1;
          if (uVar3 == 0) {
            local_40 = 0;
            do {
              DataMemoryBarrier(2);
              local_40 = local_40 + 1;
            } while (local_40 < 0x3458);
            vdc5_wait_frames(1);
          }
        }
      }
    }
  }
  return uVar3;
}


// ===== vdc5_layers_stop @ 20132b58 (136 bytes)

/* WARNING: Removing unreachable block (ram,0x20117f54) */
/* WARNING: Removing unreachable block (ram,0x20117f5c) */
/* WARNING: Removing unreachable block (ram,0x20117f60) */
/* stop all layers and release */

int vdc5_layers_stop(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  
  uVar2 = vdc5_vline_cb_disable(param_1);
  if (uVar2 == 0) {
    bVar1 = r_vdc5_stop_process(param_1,-1);
    uVar2 = (uint)bVar1;
    if (uVar2 == 0) {
      FUN_2011ba48(param_1,0xffffffff);
      FUN_2011d7f0(param_1,0xffffffff,0,extraout_r3,unaff_r4);
      return 0;
    }
  }
  return uVar2;
}


// ===== vdc5_channel_shutdown @ 20132b94 (152 bytes)

/* stop layers, terminate the channel, clock off */

int vdc5_channel_shutdown(uint param_1)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  
  iVar1 = vdc5_layers_stop(param_1);
  if (iVar1 != 0) {
    return iVar1;
  }
  FUN_2011d1e0();
  vdc5_int_callbacks_clear(param_1);
  FUN_201195e8(param_1);
  FUN_2011d7d8(param_1,0,0,extraout_r3,unaff_r4);
  iVar1 = FUN_2011d5a8();
  if (iVar1 == 0) {
    FUN_2011d7d8(param_1,4,0);
  }
  vdc5_module_stop((char)param_1);
  return 0;
}


// ===== dvi_set_resolution @ 20132bc0 (268 bytes)

/* re-initialises VDC5 ch1 for 800x480 (0) or 800x600 (1) */

byte dvi_set_resolution(int param_1)

{
  uint uVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined4 local_14;
  
  uVar1 = vdc5_channel_shutdown(1);
  DAT_20808574 = 0x58;
  DAT_20808578 = 0x20;
  if (uVar1 == 0) {
    local_18 = 6;
    local_17 = 0;
    if (param_1 == 0) {
      local_14 = lvds_pll_cfg(1);
    }
    else {
      local_14 = lvds_pll_cfg(1,param_1);
    }
    uVar1 = r_vdc5_initialize(1,(int)&local_18,vdc5_module_start,1);
    if ((uVar1 == 0) && (uVar1 = vdc5_sync_setup(1,param_1), uVar1 == 0)) {
      uVar1 = vdc5_output_setup(1,param_1);
      if (param_1 == 0) {
        gpio_dvr(0,1);
        DAT_2080857c = 0xe0;
        DAT_20808580 = 0x1f;
      }
      else {
        gpio_dvr(0,0);
        DAT_2080857c = 0xd8;
        DAT_20808580 = 0x57;
      }
      if (uVar1 == 0) {
        uVar1 = vdc5_layers_setup(1,param_1);
      }
    }
  }
  return (byte)uVar1;
}


// ===== gui_start @ 20132ccc (428 bytes)

/* VDC5 layers + GUI tasks */

void gui_start(void)

{
  int iVar1;
  uint uVar2;
  undefined1 local_20;
  undefined1 local_1f;
  undefined4 local_1c;
  
  FUN_201340a4();
  FUN_201342b4();
  FUN_20120d38();
  FUN_20133620();
  dmac8_m2m_init();
  sdr_dsp_link_init();
  iVar1 = vdc5_isr_create();
  if (iVar1 == 0) {
    local_20 = 4;
    local_1f = 1;
    local_1c = 0;
    uVar2 = r_vdc5_initialize(0,(int)&local_20,vdc5_module_start,0);
    if ((uVar2 == 0) && (uVar2 = vdc5_sync_setup(0,0), uVar2 == 0)) {
      uVar2 = vdc5_output_setup(0,0);
      DAT_20808574 = 0x58;
      DAT_20808578 = 0x20;
      if (uVar2 == 0) {
        uVar2 = vdc5_vline_int_setup(0);
      }
    }
  }
  else {
    uVar2 = 7;
  }
  iVar1 = vdc5_isr_create();
  if (iVar1 != 0) {
    uVar2 = 7;
  }
  DataMemoryBarrier(2);
  if (uVar2 == 0) {
    local_20 = 6;
    local_1f = 0;
    local_1c = lvds_pll_cfg(1,0);
    uVar2 = r_vdc5_initialize(1,(int)&local_20,vdc5_module_start,1);
    if ((uVar2 == 0) && (uVar2 = vdc5_sync_setup(1,0), uVar2 == 0)) {
      uVar2 = vdc5_output_setup(1,0);
      gpio_dvr(0,1);
      DAT_2080857c = 0x58;
      DAT_20808580 = 0x20;
      if ((uVar2 == 0) &&
         (((uVar2 = vdc5_vline_int_setup(1), uVar2 == 0 &&
           (iVar1 = vdc5_layers_setup(0), iVar1 == 0)) &&
          (iVar1 = vdc5_layers_setup(1,0), iVar1 == 0)))) {
        gui_main_loop();
        vdc5_layers_stop(0);
        vdc5_layers_stop(1);
      }
    }
  }
  vdc5_channel_shutdown(0);
  vdc5_channel_shutdown(1);
  return;
}


// ===== fb_get_front_addr @ 20132e78 (88 bytes)

/* frame buffer currently shown for a back-buffer index (1<->2, 3<->4) */

void * fb_get_front_addr(uint param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 0:
    iVar1 = 0xbb800;
    break;
  case 1:
    iVar1 = 0x177000;
    break;
  case 2:
    return &DAT_605048a0;
  case 3:
    iVar1 = 0x232800;
    break;
  case 4:
    return &DAT_60000000;
  case 5:
    iVar1 = 0x2ee000;
    break;
  default:
    return (void *)0x0;
  }
  return (void *)(iVar1 + 0x60000000);
}


// ===== FUN_20132ee8 @ 20132ee8 (16 bytes)

void FUN_20132ee8(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    dcache_clean_range(&DAT_600bb800,0xbb800);
    return;
  case 1:
    dcache_clean_range(&DAT_605048a0,0xbb800);
    return;
  case 2:
    dcache_clean_range(&DAT_60177000,0xbb800);
    return;
  case 3:
    dcache_clean_range(0x60000000,0xbb800);
    return;
  case 4:
    dcache_clean_range(&DAT_60232800,0xbb800);
    return;
  case 5:
    dcache_clean_range(&DAT_602ee000,0x11300);
    return;
  default:
    return;
  }
}


// ===== FUN_20132f10 @ 20132f10 (8 bytes)

void FUN_20132f10(void)

{
  dcache_clean_range(&DAT_600bb800);
  return;
}


// ===== FUN_20132f18 @ 20132f18 (8 bytes)

void FUN_20132f18(void)

{
  dcache_clean_range(&DAT_605048a0);
  return;
}


// ===== FUN_20132f20 @ 20132f20 (8 bytes)

void FUN_20132f20(void)

{
  dcache_clean_range(&DAT_60177000);
  return;
}


// ===== FUN_20132f28 @ 20132f28 (8 bytes)

void FUN_20132f28(void)

{
  dcache_clean_range(0x60000000);
  return;
}


// ===== FUN_20132f30 @ 20132f30 (8 bytes)

void FUN_20132f30(void)

{
  dcache_clean_range(&DAT_60232800);
  return;
}


// ===== FUN_20132f38 @ 20132f38 (12 bytes)

void FUN_20132f38(void)

{
  dcache_clean_range(&DAT_602ee000,0x11300);
  return;
}


// ===== gui_area_dirty_set @ 20132f44 (16 bytes)

/* (i): 0x208F4D80[i] = 1 [fact]; a redraw request per screen area (meter, scope) [inference] */

void gui_area_dirty_set(int param_1)

{
  *(undefined4 *)(&DAT_208f4d80 + param_1 * 4) = 1;
  return;
}


// ===== FUN_20132f54 @ 20132f54 (24 bytes)

undefined4 FUN_20132f54(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(&DAT_208f4d80 + param_1 * 4);
  *(undefined4 *)(&DAT_208f4d80 + param_1 * 4) = 0;
  return uVar1;
}


// ===== FUN_20132f6c @ 20132f6c (8 bytes)

undefined * FUN_20132f6c(void)

{
  return &DAT_605c0c60;
}


// ===== sdr_rx_buf @ 20132f74 (8 bytes)

/* 0x605C00A0 */

void * sdr_rx_buf(void)

{
  return &DAT_605c00a0;
}


// ===== dsp_hdr_buf @ 20132f7c (8 bytes)

/* 0x605C0780 */

void * dsp_hdr_buf(void)

{
  return &DAT_605c0780;
}


// ===== fb_clear_all @ 20132f84 (32 bytes)

/* clears 0x60000000..+0x2FF300 and the frame buffer at 0x605048A0 */

void fb_clear_all(void)

{
  __aeabi_memclr4(0x60000000,0x2ff300);
  __aeabi_memclr4_veneer(&DAT_605048a0,0xdc3c0);
  return;
}


// ===== FUN_20132fd8 @ 20132fd8 (8 bytes)

undefined4 FUN_20132fd8(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
}


// ===== cycle_delta_2 @ 20132fe0 (48 bytes)

/* PMCCNTR delta (copy) */

int cycle_delta_2(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== vdc5_vline_cb @ 20133014 (56 bytes)

/* frame counter 0x208085A4, counts down 0x2080859C */

void vdc5_vline_cb(void)

{
  cycle_delta_2(&DAT_208f4db8);
  DAT_208085a4 = DAT_208085a4 + 1;
  if (DAT_2080859c != 0) {
    DAT_2080859c = DAT_2080859c + -1;
  }
  return;
}


// ===== vdc5_vline_int_setup @ 2013304c (28 bytes)

/* VLINE interrupt, no callback */

uint vdc5_vline_int_setup(uint param_1)

{
  uint uVar1;
  
  DAT_20907f58 = 3;
  DAT_20907f5c = 0;
  DAT_20907f60 = 0;
  uVar1 = FUN_20117c14();
  return uVar1;
}


// ===== vdc5_vline_cb_enable @ 20133068 (20 bytes)

/* VLINE callback = vdc5_vline_cb */

uint vdc5_vline_cb_enable(uint param_1)

{
  uint uVar1;
  
  DAT_20907f5c = vdc5_vline_cb;
  uVar1 = FUN_20117c14(param_1,&DAT_20907f58);
  return uVar1;
}


// ===== vdc5_vline_cb_disable @ 2013307c (20 bytes)

uint vdc5_vline_cb_disable(uint param_1)

{
  uint uVar1;
  
  DAT_20907f5c = 0;
  uVar1 = FUN_20117c14(param_1,&DAT_20907f58);
  return uVar1;
}


// ===== vdc5_wait_frames @ 20133090 (24 bytes)

/* sets 0x2080859C and spins until the VLINE callback clears it */

void vdc5_wait_frames(int param_1)

{
  DAT_2080859c = param_1;
  do {
  } while (param_1 != 0);
  return;
}


// ===== vdc5_isr_create @ 201330a8 (44 bytes)

/* itron_acre_isr(GIC 78, VDC5 ch0 GR3_VLINE) + enable */

int vdc5_isr_create(void)

{
  uint uVar1;
  
  uVar1 = itron_acre_isr(0,0x203a706c);
  if (0 < (int)uVar1) {
    gic_enable_irq(0x4e);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== sdr_rx_done_cb @ 201330d4 (108 bytes)

void sdr_rx_done_cb(void)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = sdr_rx_buf();
  cycle_delta_2(&DAT_208f4dc0);
  DAT_208085a4 = DAT_208085a4 + 1;
  if ((((byte)DAT_20808a84 & 0x10) != 0) && (cVar1 = *pcVar2, cVar1 != '\0')) {
    pcVar2[0x1a8] = cVar1;
    pcVar2[0x1a9] = cVar1;
  }
  scope_store_frame((uint)pcVar2);
  dmac5_disable();
  rspi_stop(2);
  rspi_reset_buffers(2);
  dmac5_enable();
  return;
}


// ===== sdr_link_recover @ 20133140 (136 bytes)

/* unreferenced */

void sdr_link_recover(void)

{
  byte bVar1;
  
  dmac5_disable();
  rspi_stop(2);
  dmac5_enable();
  rspi_reset_buffers(2);
  bVar1 = RSPI_SPSR_2;
  if ((bVar1 & 1) != 0) {
    bVar1 = RSPI_SPSR_2;
    RSPI_SPSR_2 = bVar1 & 0xfe;
    DAT_208f4dac = DAT_208f4dac + 1;
    DAT_20808590 = DAT_20808590 + 1;
  }
  bVar1 = RSPI_SPSR_2;
  if ((bVar1 & 4) != 0) {
    bVar1 = RSPI_SPSR_2;
    RSPI_SPSR_2 = bVar1 & 0xfb;
    DAT_208f4da8 = DAT_208f4da8 + 1;
  }
  rspi_start(2);
  return;
}


// ===== dsp_set_audio_ptr @ 201331c8 (20 bytes)

void dsp_set_audio_ptr(int param_1)

{
  DAT_20808598 = param_1;
  DAT_2080858e = *(undefined2 *)(param_1 + 2);
  return;
}


// ===== dsp_rx_done_cb @ 201331dc (532 bytes)

/* REC/PLAY */

void dsp_rx_done_cb(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  cycle_delta_2(&DAT_208f4dc8);
  DAT_208f4da4 = DAT_208f4da4 + 1;
  DAT_208085a0 = DAT_208085a0 + 1;
  puVar3 = &DAT_60502000;
  if (DAT_2080858c == '\0') {
    afscope_store_frame(&DAT_60502000);
    puVar2 = dsp_hdr_buf();
    *puVar2 = DAT_60502000;
    puVar2[1] = DAT_60502001;
    puVar2[2] = DAT_60502002;
    puVar2[3] = DAT_60502003;
  }
  else {
    afscope_store_frame(&DAT_60503450);
    puVar3 = dsp_hdr_buf();
    *puVar3 = DAT_60503450;
    puVar3[1] = DAT_60503451;
    puVar3[2] = DAT_60503452;
    puVar3[3] = DAT_60503453;
    puVar3 = &DAT_60503450;
  }
  dsp_set_audio_ptr((int)(puVar3 + 600));
  dmac4_disable();
  rspi_stop(4);
  bVar1 = RSPI_SPSR_4;
  if ((bVar1 & 1) != 0) {
    DAT_20808594 = DAT_20808594 + 1;
    DAT_208f4db4 = DAT_208f4db4 + 1;
    bVar1 = RSPI_SPSR_4;
    RSPI_SPSR_4 = bVar1 & 0xfe;
  }
  bVar1 = RSPI_SPSR_4;
  if ((bVar1 & 4) != 0) {
    DAT_208f4db0 = DAT_208f4db0 + 1;
    bVar1 = RSPI_SPSR_4;
    RSPI_SPSR_4 = bVar1 & 0xfb;
  }
  dmac3_disable();
  rspi_reset_buffers(4);
  DAT_2080858c = DAT_2080858c == '\0';
  if ((bool)DAT_2080858c) {
    DMAC_N0SA_3 = 0x605036a8;
    DMAC_N0DA_4 = 0x60502000;
  }
  else {
    DMAC_N0SA_3 = 0x60502258;
    DMAC_N0DA_4 = 0x60503450;
  }
  if (DAT_208000b2 != '\0') {
    memcpy(&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8,DAT_20808598,4000);
    audio_codec_post(1,(uint)(&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8));
    DAT_208000b0 = DAT_208000b0 + 1;
    if (0xf < DAT_208000b0) {
      DAT_208000b0 = 0;
    }
  }
  if (DAT_208000b1 == '\0') {
    DMAC_N0SA_3 = &DAT_20906d60;
  }
  else {
    DMAC_N0SA_3 = &DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8;
    audio_codec_post(2,(uint)(&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8));
    itron_set_flg(DAT_208000c8,4);
  }
  dmac3_enable();
  dmac4_enable();
  return;
}


// ===== sdr_ss_isr @ 201333f0 (40 bytes)

/* entry fix (late start FUN_201333f4) */

void sdr_ss_isr(void)

{
  cycle_delta_2(&DAT_20907f68);
  DAT_208085a8 = DAT_208085a8 + 1;
  rspi_start(2);
  return;
}


// ===== dsp_ss_isr @ 20133418 (40 bytes)

/* entry fix (late start FUN_2013341c) */

void dsp_ss_isr(void)

{
  cycle_delta_2(&DAT_20907f70);
  DAT_208085ac = DAT_208085ac + 1;
  rspi_start(4);
  return;
}


// ===== link_ss_irq_init @ 20133440 (68 bytes)

/* GIC 535/449 */

void link_ss_irq_init(void)

{
  uint uVar1;
  
  uVar1 = itron_acre_isr(0,0x203a7080);
  if (0 < (int)uVar1) {
    gic_enable_irq(0x217);
    uVar1 = itron_acre_isr(0,0x203a7094);
    if (0 < (int)uVar1) {
      gic_enable_irq(0x1c1);
      return;
    }
  }
  return;
}


// ===== sdr_dsp_link_init @ 20133484 (200 bytes)

/* RSPI2+DMA5, RSPI4+DMA3/4 */

void sdr_dsp_link_init(void)

{
  void *pvVar1;
  
  pvVar1 = sdr_rx_buf();
  dmac5_rspi2_rx_setup(0xe800d804,(uint)pvVar1,0x6a4);
  __aeabi_memset(&DAT_60502000,0x1450,0xf0);
  __aeabi_memset(&DAT_208f4de0,0x11f80,0xf0);
  dmac4_rspi4_rx_setup(0xe800e804,0x60502000,0x11f8);
  dmac3_rspi4_tx_setup(0x208f4de0,0xe800e804,0x11f8);
  __aeabi_memset(&DAT_20906d60,0x11f8,0xf0);
  DAT_20906d60 = 0;
  DAT_20906d61 = 0;
  dmac5_set_callback(0x201330d4);
  dmac4_set_callback(0x201331dc);
  rspi_open(2);
  rspi_reset_buffers(2);
  dmac5_enable();
  rspi_start(2);
  rspi_open(4);
  rspi_reset_buffers(4);
  dmac4_enable();
  rspi_start(4);
  return;
}


// ===== scope3d_render_large_thunk @ 201335d8 (32 bytes)

/* -> scope3d_render_large (this = 0x20907F78) */

void scope3d_render_large_thunk(uint param_1,uint param_2,uint param_3,uint param_4)

{
  scope3d_render_large(&DAT_20907f78,param_1,param_2,(ushort *)param_3,param_4);
  return;
}


// ===== scope3d_render_small_thunk @ 201335f8 (32 bytes)

/* -> scope3d_render_small (this = 0x20907F78) */

void scope3d_render_small_thunk(uint param_1,uint param_2,uint param_3,uint param_4)

{
  scope3d_render_small(&DAT_20907f78,param_1,param_2,(ushort *)param_3,param_4);
  return;
}

