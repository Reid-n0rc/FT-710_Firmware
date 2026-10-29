// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201322d8 @ 201322d8 (12 bytes)

/* WARNING: Removing unreachable block (ram,0x2015b1d4) */
/* WARNING: Removing unreachable block (ram,0x2015b4d4) */

void FUN_201322d8(int param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint uVar8;
  bool bVar9;
  char acStack_270 [288];
  undefined1 auStack_150 [288];
  uint uStack_30;
  undefined *puStack_2c;
  uint uStack_28;
  
  cVar2 = *(char *)(param_1 + 2);
  if (cVar2 == '\x01') {
    uStack_28 = fb_get_layer_addr(DAT_208085bc);
    uVar8 = (uint)*(byte *)(param_1 + 5);
    uStack_30 = 0x1e0;
    fb_clear_rect(uStack_28,0,0,800);
    uStack_30 = 0x31a;
    puStack_2c = (undefined *)0x18;
    fb_fill_rect(uStack_28,0x3186,2);
    gui_draw_runs(uStack_28,4,400,&DAT_2016dc08);
    uStack_30 = 0xf;
    puStack_2c = &DAT_20800cac;
    gui_draw_text_centered(uStack_28,DAT_20808540,4,400);
    uVar6 = 0;
    do {
      uVar1 = 1 << (7 - uVar6 & 0xff);
      if ((*(byte *)(param_1 + 3) & uVar1) != 0) {
        uStack_30 = 0x43;
        iVar3 = uVar6 * 0x44 + 0x32;
        fb_clear_rect(uStack_28,iVar3,0x75,0x78);
        if ((*(byte *)(param_1 + 4) & uVar1) == 0) {
          puVar7 = (undefined2 *)&DAT_203a5684;
          (&DAT_208f4c30)[uVar6 * 0x12] = 0;
        }
        else {
          puVar7 = &DAT_203a5694;
          (&DAT_208f4c30)[uVar6 * 0x12] = 1;
        }
        gui_draw_runs(uStack_28,iVar3,0x75,puVar7);
        if (uVar6 == uVar8) {
          uStack_30 = (uint)(ushort)puVar7[1];
          puStack_2c = (undefined *)0x3;
          FUN_20136398(uStack_28,iVar3,0x75,*puVar7);
        }
      }
      uStack_30 = 0xf;
      puStack_2c = &DAT_20800b1c;
      gui_draw_text(uStack_28,uVar6 * 0x48 + 0x208f4bfd,uVar6 * 0x44 + 0x41,0xc4);
      uStack_30 = 0xf;
      puStack_2c = &DAT_20800b1c;
      gui_draw_text(uStack_28,&DAT_208f4c11 + uVar6 * 0x48,uVar6 * 0x44 + 0x43,0x1dc);
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < 4);
    FUN_20126914(uStack_28,0x19a,0xfa,2);
    if (*(char *)(param_1 + 4) == '\0') {
      gui_draw_runs(uStack_28,0x1a6,0x10f,&DAT_20255114);
    }
    else {
      gui_draw_runs(uStack_28,0x1a6,0x10f,&DAT_20254600);
    }
    if (uVar8 == 10) {
      uStack_30 = (uint)(ushort)DAT_20802294[1];
      puStack_2c = (undefined *)0x3;
      FUN_20136398(uStack_28,0x19a,0xfa,*DAT_20802294);
    }
    if (DAT_20800494 != '\0') {
      FUN_20126914(uStack_28,0x19a,0x1a4,2);
      gui_draw_runs(uStack_28,0x1a6,0x1b9,&DAT_20251ec8);
      if (uVar8 == 0xb) {
        uStack_30 = (uint)(ushort)DAT_20802294[1];
        puStack_2c = (undefined *)0x3;
        FUN_20136398(uStack_28,0x19a,0x1a4,*DAT_20802294);
      }
    }
    return;
  }
  if (cVar2 == '\x02') {
    uVar5 = fb_get_layer_addr(DAT_208085bc);
    cVar2 = *(char *)(param_1 + 5);
    uStack_28 = 0x1e0;
    fb_clear_rect(uVar5,0,0,800);
    uStack_28 = 0x31a;
    fb_fill_rect(uVar5,0x3186,2);
    gui_draw_runs(uVar5,4,400,&DAT_2016dc08);
    gui_draw_runs(uVar5,8,0x168,&DAT_203a56b4);
    uStack_28 = 0xf;
    gui_draw_text_centered(uVar5,"UPDATE?",0xf0,400);
    FUN_20126914(uVar5,0x19a,0xfa,2);
    gui_draw_runs(uVar5,0x1a6,0x10f,&DAT_20253aec);
    if (cVar2 == '\n') {
      uStack_28 = (uint)(ushort)DAT_20802294[1];
      FUN_20136398(uVar5,0x19a,0xfa,*DAT_20802294);
    }
    FUN_20126914(uVar5,0x19a,0x1a4,2);
    gui_draw_runs(uVar5,0x1a6,0x1b9,&DAT_20251ec8);
    if (cVar2 == '\v') {
      uStack_28 = (uint)(ushort)DAT_20802294[1];
      FUN_20136398(uVar5,0x19a,0x1a4,*DAT_20802294);
    }
    return;
  }
  if (cVar2 != '\x03') {
    return;
  }
  uStack_30 = fb_get_layer_addr(DAT_208085bc);
  mouse_detach_post();
  DAT_20800496 = 1;
  DAT_20800495 = 0;
  fb_clear_rect(uStack_30,0,0,800,0x1e0);
  fb_fill_rect(uStack_30,0x3186,2,2,0x31a,0x18);
  gui_draw_runs(uStack_30,4,400,&DAT_2016dc08);
  gui_draw_text_centered(uStack_30,DAT_20808540,4,400,0xf,&DAT_20800cac);
  gui_draw_text_centered(uStack_30,DAT_20808544,0x1a7,400,0xf,&DAT_20800cac);
  puStack_2c = (undefined *)0xff;
  FUN_20155310(acStack_270,&DAT_208f4bfc,0x120);
  FUN_20155310(auStack_150,&DAT_208f4bfc,0x120);
  FUN_20126160(1);
  while( true ) {
    iVar3 = fwupdate_poll(&DAT_208f4bfc);
    iVar4 = FUN_20103ba0();
    if (iVar4 == 0) break;
    bVar9 = puStack_2c != (undefined *)iVar3;
    puStack_2c = (undefined *)iVar3;
    if ((bVar9) || (iVar4 = FUN_2015507c(&DAT_208f4bfc,auStack_150,0x120), iVar4 != 0)) {
      FUN_20155310(auStack_150,&DAT_208f4bfc,0x120);
      uVar6 = 0;
      do {
        iVar4 = uVar6 * 0x48;
        gui_draw_text(uStack_30,iVar4 + 0x208f4bfd,uVar6 * 0x44 + 0x41,0xc4,0xf,&DAT_20800b1c);
        cVar2 = (&DAT_208f4bfc)[iVar4];
        if (cVar2 == '\x04') {
          if (acStack_270[uVar6 * 0x48] != '\x04') {
            fb_clear_rect(uStack_30,uVar6 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          FUN_201219b8(uStack_30,uVar6 * 0x44 + 0x42,0x1dc,(&DAT_208f4c34)[uVar6 * 0x12] & 0xffff,
                       (&DAT_208f4c34)[uVar6 * 0x12]);
        }
        else {
          if (cVar2 == '\x05') {
            if (acStack_270[uVar6 * 0x48] != '\x05') {
              fb_clear_rect(uStack_30,uVar6 * 0x44 + 0x42,0x1dc,0x144,0x19);
            }
            gui_draw_runs(uStack_30,uVar6 * 0x44 + 0x32,0x75,&DAT_203a56a4);
          }
          else if (cVar2 != acStack_270[uVar6 * 0x48]) {
            fb_clear_rect(uStack_30,uVar6 * 0x44 + 0x42,0x1dc,0x144,0x19);
          }
          gui_draw_text(uStack_30,&DAT_208f4c11 + iVar4,uVar6 * 0x44 + 0x43,0x1dc,0xf,&DAT_20800b1c)
          ;
        }
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < 4);
      FUN_20155310(acStack_270,&DAT_208f4bfc,0x120);
      if (iVar3 != 0) goto LAB_2015b360;
      gui_update_layers();
      uStack_30 = fb_get_layer_addr(DAT_208085bc);
    }
  }
  iVar3 = 2;
LAB_2015b360:
  FUN_2010e4a0();
  if (iVar3 != 1) {
    update_error_screen();
  }
  system_reboot();
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
  
  bVar1 = DAT_fcfe0438;
  if (param_1 != '\0') {
    DAT_fcfe0438 = bVar1 & 0xfc;
    bVar1 = DAT_fcfe0034;
    DAT_fcfe0034 = bVar1 & 0xef;
    do {
      bVar1 = DAT_fcfe0044;
    } while ((bVar1 & 0x10) != 0);
    return;
  }
  DAT_fcfe0438 = bVar1 & 0xfd;
  bVar1 = DAT_fcfe0034;
  DAT_fcfe0034 = bVar1 & 0xdf;
  do {
    bVar1 = DAT_fcfe0044;
  } while ((bVar1 & 0x20) != 0);
  return;
}


// ===== vdc5_module_stop @ 20132398 (100 bytes)

/* STBCR9 clock off for ch0/ch1 */

void vdc5_module_stop(char param_1)

{
  byte bVar1;
  
  bVar1 = DAT_fcfe0034;
  if (param_1 == '\0') {
    bVar1 = bVar1 | 0x20;
  }
  else {
    bVar1 = bVar1 | 0x10;
  }
  DAT_fcfe0034 = bVar1;
  if (param_1 == '\0') {
    do {
      bVar1 = DAT_fcfe0044;
    } while ((bVar1 & 0x20) == 0);
    bVar1 = DAT_fcfe0438;
    bVar1 = bVar1 | 2;
  }
  else {
    do {
      bVar1 = DAT_fcfe0044;
    } while ((bVar1 & 0x10) == 0);
    bVar1 = DAT_fcfe0438;
    bVar1 = bVar1 | 1;
  }
  DAT_fcfe0438 = bVar1;
  return;
}


// ===== lcd_tcon_cfg_ch0 @ 201323fc (68 bytes)

/* TCON pin table for the parallel RGB TFT (ch0) */

void lcd_tcon_cfg_ch0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = &DAT_203a6fd4;
    param_1[1] = &DAT_203a6fe8;
    param_1[2] = &DAT_203a6fde;
    param_1[3] = &DAT_203a6ff2;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = &DAT_203a6ffc;
  }
  return;
}


// ===== dvi_tcon_cfg_ch1 @ 20132440 (92 bytes)

/* TCON pin table for the LVDS/DVI channel (ch1), 800x480 or 800x600 */

void dvi_tcon_cfg_ch1(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = &UNK_203a7006 + param_1 * 10;
    param_2[1] = &UNK_203a702e + param_1 * 10;
    param_2[2] = &UNK_203a701a + param_1 * 10;
    param_2[3] = &UNK_203a7042 + param_1 * 10;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = &UNK_203a7056 + param_1 * 10;
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

void vdc5_sync_setup(int param_1,int param_2)

{
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
  r_vdc5_sync_control(param_1,&local_20);
  return;
}


// ===== vdc5_output_setup @ 201325e8 (152 bytes)

/* r_vdc5_display_output wrapper per channel */

void vdc5_output_setup(int param_1,int param_2)

{
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
  r_vdc5_display_output(param_1,&local_40);
  return;
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

int vdc5_layers_setup(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
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
  int local_2c;
  int iStack_28;
  
  if (param_1 == 0) {
    uVar3 = 0x1e00020;
    uVar4 = 0x3200058;
  }
  else if (param_2 == 0) {
    uVar3 = 0x1e0001f;
    uVar4 = 0x32000e0;
  }
  else {
    uVar3 = 0x1e00057;
    uVar4 = 0x32000d8;
  }
  local_44 = 0;
  local_4c = 0;
  local_48 = 0;
  local_2c = param_1;
  iStack_28 = param_2;
  uVar5 = fb_get_layer_addr(0);
  local_3c = fb_get_layer_addr(1,(int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
  local_40 = fb_get_layer_addr(3);
  uVar1 = fb_get_layer_addr(5);
  local_68 = 0x100;
  local_60 = 0x640;
  local_58 = 0x6000000;
  local_5c = 0;
  local_54 = uVar3;
  local_50 = uVar4;
  iVar2 = r_vdc5_read_data_control(local_2c,3,&local_68);
  if (((iVar2 == 0) && (iVar2 = r_vdc5_chromakey(local_2c,3,1,&local_4c), iVar2 == 0)) &&
     (iVar2 = layer_alpha_rect_reapply(local_2c,3), iVar2 == 0)) {
    local_68 = 0x100;
    local_64 = local_3c;
    local_58 = 0x6000000;
    local_5c = 0;
    local_60 = 0x640;
    local_54 = uVar3;
    local_50 = uVar4;
    iVar2 = r_vdc5_read_data_control(local_2c,4,&local_68);
    if ((iVar2 == 0) && (iVar2 = r_vdc5_chromakey(local_2c,4,1,&local_4c), iVar2 == 0)) {
      iVar2 = layer_alpha_rect_reapply(local_2c,4);
    }
    DAT_208f4d50 = local_64;
    if (iVar2 == 0) {
      local_68 = 0x100;
      local_58 = 0x6000000;
      local_64 = local_40;
      local_5c = 0;
      local_60 = 0x640;
      local_54 = uVar3;
      local_50 = uVar4;
      iVar2 = r_vdc5_read_data_control(local_2c,5,&local_68);
      if ((iVar2 == 0) && (iVar2 = r_vdc5_chromakey(local_2c,5,1,&local_4c), iVar2 == 0)) {
        iVar2 = layer_alpha_rect_reapply(local_2c,5);
      }
      DAT_208f4d60 = local_64;
      if (iVar2 == 0) {
        local_68 = 0x100;
        local_60 = 0x640;
        local_58 = 0x6000000;
        local_5c = 0;
        local_64 = uVar1;
        local_54 = uVar3;
        local_50 = uVar4;
        cursor_rect_calc(&local_40,local_2c,400,0xf0);
        DAT_20808584 = (undefined2)local_40;
        DAT_20808586 = local_40._2_2_;
        DAT_20808588 = (undefined2)local_3c;
        DAT_2080858a = local_3c._2_2_;
        local_54 = local_40;
        local_50 = local_3c;
        iVar2 = r_vdc5_read_data_control(local_2c,6,&local_68);
        if ((iVar2 == 0) && (iVar2 = r_vdc5_chromakey(local_2c,6,1,&local_4c), iVar2 == 0)) {
          iVar2 = layer_alpha_rect_reapply(local_2c,6);
        }
        DAT_208f4d78 = &DAT_20808584;
        DAT_208f4d74 = 0;
        DAT_208f4d7c = 0;
        DAT_208f4d70 = uVar1;
        if ((iVar2 == 0) && (iVar2 = vdc5_vline_cb_enable(local_2c), iVar2 == 0)) {
          local_34[0] = 2;
          local_38 = local_34;
          r_vdc5_start_process(local_2c,3,&local_38);
          local_34[0] = 3;
          local_38 = local_34;
          r_vdc5_start_process(local_2c,4,&local_38);
          iVar2 = r_vdc5_start_process(local_2c,5,&local_38);
          if (iVar2 == 0) {
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
  return iVar2;
}


// ===== vdc5_layers_stop @ 20132b58 (136 bytes)

/* WARNING: Removing unreachable block (ram,0x20117f54) */
/* WARNING: Removing unreachable block (ram,0x20117f5c) */
/* WARNING: Removing unreachable block (ram,0x20117f60) */
/* stop all layers and release */

int vdc5_layers_stop(undefined4 param_1)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  
  iVar1 = vdc5_vline_cb_disable();
  if ((iVar1 == 0) && (iVar1 = r_vdc5_stop_process(param_1,0xffffffff), iVar1 == 0)) {
    FUN_2011ba48(param_1,0xffffffff);
    FUN_2011d7f0(param_1,0xffffffff,0,extraout_r3,unaff_r4);
    return 0;
  }
  return iVar1;
}


// ===== vdc5_channel_shutdown @ 20132b94 (152 bytes)

/* stop layers, terminate the channel, clock off */

int vdc5_channel_shutdown(undefined4 param_1)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  
  iVar1 = vdc5_layers_stop();
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
  vdc5_module_stop(param_1);
  return 0;
}


// ===== dvi_set_resolution @ 20132bc0 (268 bytes)

/* re-initialises VDC5 ch1 for 800x480 (0) or 800x600 (1) */

int dvi_set_resolution(int param_1)

{
  int iVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined4 local_14;
  
  iVar1 = vdc5_channel_shutdown(1);
  DAT_20808574 = 0x58;
  DAT_20808578 = 0x20;
  if (iVar1 == 0) {
    local_18 = 6;
    local_17 = 0;
    if (param_1 == 0) {
      local_14 = lvds_pll_cfg(1);
    }
    else {
      local_14 = lvds_pll_cfg(1,param_1);
    }
    iVar1 = r_vdc5_initialize(1,&local_18,vdc5_module_start);
    if ((iVar1 == 0) && (iVar1 = vdc5_sync_setup(1,param_1), iVar1 == 0)) {
      iVar1 = vdc5_output_setup(1,param_1);
      if (param_1 == 0) {
        gpio_dvr(0,1);
        DAT_2080857c = 0xe0;
        DAT_20808580 = 0x1f;
      }
      else {
        gpio_dvr(0);
        DAT_2080857c = 0xd8;
        DAT_20808580 = 0x57;
      }
      if (iVar1 == 0) {
        iVar1 = vdc5_layers_setup(1,param_1);
      }
    }
  }
  return iVar1;
}


// ===== gui_start @ 20132ccc (428 bytes)

/* VDC5 layers + GUI tasks */

void gui_start(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_20;
  undefined1 local_1f;
  undefined4 local_1c;
  
  FUN_201340a4();
  FUN_201342b4();
  FUN_20120d38();
  FUN_20133620();
  dmac8_m2m_init();
  sdr_dsp_link_init();
  iVar1 = vdc5_isr_create(0);
  if (iVar1 == 0) {
    local_20 = 4;
    local_1f = 1;
    local_1c = 0;
    iVar1 = r_vdc5_initialize(0,&local_20,vdc5_module_start);
    if ((iVar1 == 0) && (iVar1 = vdc5_sync_setup(0), iVar1 == 0)) {
      iVar1 = vdc5_output_setup(0);
      DAT_20808574 = 0x58;
      DAT_20808578 = 0x20;
      if (iVar1 == 0) {
        iVar1 = vdc5_vline_int_setup(0);
      }
    }
  }
  else {
    iVar1 = 7;
  }
  iVar2 = vdc5_isr_create(1);
  if (iVar2 != 0) {
    iVar1 = 7;
  }
  DataMemoryBarrier(2);
  if (iVar1 == 0) {
    local_20 = 6;
    local_1f = 0;
    local_1c = lvds_pll_cfg(1,0);
    iVar1 = r_vdc5_initialize(1,&local_20,vdc5_module_start);
    if ((iVar1 == 0) && (iVar1 = vdc5_sync_setup(1,0), iVar1 == 0)) {
      iVar1 = vdc5_output_setup(1,0);
      gpio_dvr(0,1);
      DAT_2080857c = 0x58;
      DAT_20808580 = 0x20;
      if ((iVar1 == 0) &&
         (((iVar1 = vdc5_vline_int_setup(1), iVar1 == 0 &&
           (iVar1 = vdc5_layers_setup(0), iVar1 == 0)) &&
          (iVar1 = vdc5_layers_setup(1,0), iVar1 == 0)))) {
        gui_main_loop(0);
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

undefined * fb_get_front_addr(undefined4 param_1)

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
    return (undefined *)0x60000000;
  case 5:
    iVar1 = 0x2ee000;
    break;
  default:
    return (undefined *)0x0;
  }
  return (undefined *)(iVar1 + 0x60000000);
}


// ===== FUN_20132ee8 @ 20132ee8 (16 bytes)

void FUN_20132ee8(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    FUN_20101030(&DAT_600bb800,0xbb800);
    return;
  case 1:
    FUN_20101030(&DAT_605048a0,0xbb800);
    return;
  case 2:
    FUN_20101030(&DAT_60177000,0xbb800);
    return;
  case 3:
    FUN_20101030(0x60000000,0xbb800);
    return;
  case 4:
    FUN_20101030(&DAT_60232800,0xbb800);
    return;
  case 5:
    FUN_20101030(&DAT_602ee000,0x11300);
    return;
  default:
    return;
  }
}


// ===== FUN_20132f10 @ 20132f10 (8 bytes)

void FUN_20132f10(void)

{
  FUN_20101030(&DAT_600bb800);
  return;
}


// ===== FUN_20132f18 @ 20132f18 (8 bytes)

void FUN_20132f18(void)

{
  FUN_20101030(&DAT_605048a0);
  return;
}


// ===== FUN_20132f20 @ 20132f20 (8 bytes)

void FUN_20132f20(void)

{
  FUN_20101030(&DAT_60177000);
  return;
}


// ===== FUN_20132f28 @ 20132f28 (8 bytes)

void FUN_20132f28(void)

{
  FUN_20101030(0x60000000);
  return;
}


// ===== FUN_20132f30 @ 20132f30 (8 bytes)

void FUN_20132f30(void)

{
  FUN_20101030(&DAT_60232800);
  return;
}


// ===== FUN_20132f38 @ 20132f38 (12 bytes)

void FUN_20132f38(void)

{
  FUN_20101030(&DAT_602ee000,0x11300);
  return;
}


// ===== FUN_20132f44 @ 20132f44 (16 bytes)

void FUN_20132f44(int param_1)

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

undefined * sdr_rx_buf(void)

{
  return &DAT_605c00a0;
}


// ===== dsp_hdr_buf @ 20132f7c (8 bytes)

/* 0x605C0780 */

undefined * dsp_hdr_buf(void)

{
  return &DAT_605c0780;
}


// ===== fb_clear_all @ 20132f84 (32 bytes)

/* WARNING: Removing unreachable block (ram,0x201552fe) */
/* WARNING: Removing unreachable block (ram,0x201552f4) */
/* WARNING: Removing unreachable block (ram,0x201552e4) */
/* WARNING: Removing unreachable block (ram,0x201552ea) */
/* WARNING: Removing unreachable block (ram,0x201552fc) */
/* WARNING: Removing unreachable block (ram,0x20155302) */
/* WARNING: Removing unreachable block (ram,0x20155308) */
/* WARNING: Removing unreachable block (ram,0x2015530c) */
/* clears 0x60000000..+0x2FF300 and the frame buffer at 0x605048A0 */

undefined4 * fb_clear_all(void)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  
  memclr(0x60000000,0x2ff300);
  puVar1 = (undefined4 *)&DAT_605048a0;
  bVar3 = true;
  uVar2 = 0xdc3a0;
  do {
    if (bVar3) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1 = puVar1 + 8;
      bVar3 = 0x1f < uVar2;
      uVar2 = uVar2 - 0x20;
    }
  } while (bVar3);
  return puVar1;
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

undefined4 vdc5_vline_int_setup(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_20907f58 = 3;
  DAT_20907f5c = 0;
  DAT_20907f60 = 0;
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_2011d830(param_1,2);
    if (iVar1 == 1) {
      r_vdc5_callback_isr(param_1,&DAT_20907f58);
    }
    else {
      uVar2 = 10;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}


// ===== vdc5_vline_cb_enable @ 20133068 (20 bytes)

/* VLINE callback = vdc5_vline_cb */

undefined4 vdc5_vline_cb_enable(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_20907f5c = vdc5_vline_cb;
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_2011d830(param_1,2);
    if (iVar1 == 1) {
      r_vdc5_callback_isr(param_1,&DAT_20907f58);
    }
    else {
      uVar2 = 10;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}


// ===== vdc5_vline_cb_disable @ 2013307c (20 bytes)

undefined4 vdc5_vline_cb_disable(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_20907f5c = 0;
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_2011d830(param_1,2);
    if (iVar1 == 1) {
      r_vdc5_callback_isr(param_1,&DAT_20907f58);
    }
    else {
      uVar2 = 10;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
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
  int iVar1;
  
  iVar1 = itron_acre_isr(0,&DAT_203a706c);
  if (0 < iVar1) {
    gic_enable_irq(0x4e);
    iVar1 = 0;
  }
  return iVar1;
}


// ===== sdr_rx_done_cb @ 201330d4 (108 bytes)

void sdr_rx_done_cb(void)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)sdr_rx_buf();
  cycle_delta_2(&DAT_208f4dc0);
  DAT_208085a4 = DAT_208085a4 + 1;
  if ((((byte)DAT_20808a84 & 0x10) != 0) && (cVar1 = *pcVar2, cVar1 != '\0')) {
    pcVar2[0x1a8] = cVar1;
    pcVar2[0x1a9] = cVar1;
  }
  scope_store_frame(pcVar2);
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
  bVar1 = DAT_e800d803;
  if ((bVar1 & 1) != 0) {
    bVar1 = DAT_e800d803;
    DAT_e800d803 = bVar1 & 0xfe;
    DAT_208f4dac = DAT_208f4dac + 1;
    DAT_20808590 = DAT_20808590 + 1;
  }
  bVar1 = DAT_e800d803;
  if ((bVar1 & 4) != 0) {
    bVar1 = DAT_e800d803;
    DAT_e800d803 = bVar1 & 0xfb;
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
    puVar2 = (undefined1 *)dsp_hdr_buf();
    *puVar2 = DAT_60502000;
    puVar2[1] = DAT_60502001;
    puVar2[2] = DAT_60502002;
    puVar2[3] = DAT_60502003;
  }
  else {
    afscope_store_frame(&DAT_60503450);
    puVar3 = (undefined1 *)dsp_hdr_buf();
    *puVar3 = DAT_60503450;
    puVar3[1] = DAT_60503451;
    puVar3[2] = DAT_60503452;
    puVar3[3] = DAT_60503453;
    puVar3 = &DAT_60503450;
  }
  dsp_set_audio_ptr(puVar3 + 600);
  dmac4_disable();
  rspi_stop(4);
  bVar1 = DAT_e800e803;
  if ((bVar1 & 1) != 0) {
    DAT_20808594 = DAT_20808594 + 1;
    DAT_208f4db4 = DAT_208f4db4 + 1;
    bVar1 = DAT_e800e803;
    DAT_e800e803 = bVar1 & 0xfe;
  }
  bVar1 = DAT_e800e803;
  if ((bVar1 & 4) != 0) {
    DAT_208f4db0 = DAT_208f4db0 + 1;
    bVar1 = DAT_e800e803;
    DAT_e800e803 = bVar1 & 0xfb;
  }
  dmac3_disable();
  rspi_reset_buffers(4);
  DAT_2080858c = DAT_2080858c == '\0';
  if ((bool)DAT_2080858c) {
    DAT_e82000c0 = 0x605036a8;
    DAT_e8200104 = 0x60502000;
  }
  else {
    DAT_e82000c0 = 0x60502258;
    DAT_e8200104 = 0x60503450;
  }
  if (DAT_208000b2 != '\0') {
    memcpy(&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8,DAT_20808598,4000);
    audio_codec_post(1,&DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8);
    DAT_208000b0 = DAT_208000b0 + 1;
    if (0xf < DAT_208000b0) {
      DAT_208000b0 = 0;
    }
  }
  if (DAT_208000b1 == '\0') {
    DAT_e82000c0 = &DAT_20906d60;
  }
  else {
    DAT_e82000c0 = &DAT_208f4de0 + (uint)DAT_208000b0 * 0x11f8;
    audio_codec_post(2);
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
  int iVar1;
  
  iVar1 = itron_acre_isr(0,&DAT_203a7080);
  if (0 < iVar1) {
    gic_enable_irq(0x217);
    iVar1 = itron_acre_isr(0,&DAT_203a7094);
    if (0 < iVar1) {
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
  undefined4 uVar1;
  
  uVar1 = sdr_rx_buf();
  dmac5_rspi2_rx_setup(&DAT_e800d804,uVar1,0x6a4);
  FUN_2015525c(&DAT_60502000,0x1450,0xf0);
  FUN_2015525c(&DAT_208f4de0,0x11f80,0xf0);
  dmac4_rspi4_rx_setup(&DAT_e800e804,&DAT_60502000,0x11f8);
  dmac3_rspi4_tx_setup(&DAT_208f4de0,&DAT_e800e804,0x11f8);
  FUN_2015525c(&DAT_20906d60,0x11f8,0xf0);
  DAT_20906d60 = 0;
  DAT_20906d61 = 0;
  dmac5_set_callback(sdr_rx_done_cb);
  dmac4_set_callback(dsp_rx_done_cb);
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


// ===== FUN_201335d8 @ 201335d8 (32 bytes)

void FUN_201335d8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_2015b9cc(&DAT_20907f78,param_1,param_2,param_3,param_4);
  return;
}


// ===== FUN_201335f8 @ 201335f8 (32 bytes)

void FUN_201335f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_2015bb7c(&DAT_20907f78,param_1,param_2,param_3,param_4);
  return;
}


// ===== FUN_20133618 @ 20133618 (8 bytes)

void FUN_20133618(void)

{
  FUN_2015b9a8(&DAT_20907f78);
  return;
}

