// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== scope3d_vscale @ 20134358 (68 bytes)

/* (i, mode 8/9): entry i of the vertical scale table *0x20450278 (mode 8) or *0x2045027C (mode 9)
   (gui.md 3DSS step 4) [fact] */

undefined2 scope3d_vscale(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if (param_2 == 8) {
    return *(undefined2 *)(DAT_20450278 + param_1 * 2);
  }
  if (param_2 == 9) {
    uVar1 = *(undefined2 *)(DAT_2045027c + param_1 * 2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== scope3d_line_offset @ 20134368 (88 bytes)

/* (i, mode 8/9, variant): entry i of the ROM offset tables 0x203D99DC / 0x203D9A18 / 0x203D9A80 /
   0x203D9A9E [fact] */

undefined2 scope3d_line_offset(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  if (param_2 == 8) {
    if (param_3 == 0) {
      puVar2 = (undefined2 *)&DAT_203d99dc;
    }
    else {
      puVar2 = &DAT_203d9a18;
    }
    return puVar2[param_1];
  }
  if (param_2 == 9) {
    if (param_3 == 0) {
      puVar2 = (undefined2 *)&DAT_203d9a80;
    }
    else {
      puVar2 = &DAT_203d9a9e;
    }
    uVar1 = puVar2[param_1];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== scope_levels_get @ 2013437c (20 bytes)

/* (index, out): per-column levels of the scope object for layout index / mode (method 0x20157C50,
   gui.md) [fact] */

void scope_levels_get(undefined4 param_1,undefined4 param_2)

{
  scope_obj_levels_get(&DAT_2047963c,param_1,param_2,0);
  return;
}


// ===== scope_record_hold_copy @ 20134390 (8 bytes)

/* Copies the 850-byte scope record to the hold copy 0x2048360D (spi-links.md) [fact for the doc;
   the 8-byte body tail-calls into 0x20157C50] */

void scope_record_hold_copy(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  puVar1 = &DAT_204832d4;
  if (DAT_20800498 == '\0') {
    memcpy(&DAT_2048360d,&DAT_204832bb,0x352,param_4,param_4);
  }
  else {
    if (param_2 != 8 && param_2 != 9) goto LAB_20157cc4;
    puVar1 = (undefined *)0x20483626;
  }
  if (param_2 == 8) {
    FUN_201633a0(&DAT_2047963c,param_3,puVar1,param_4);
    FUN_20164674(0x20470330);
    return;
  }
  if (param_2 == 9) {
    FUN_201633a0(0x2047b43c,param_3,puVar1,param_4);
    FUN_20164654(0x20473b7c);
    return;
  }
LAB_20157cc4:
  FUN_201633a0(0x2047c33c,param_3,puVar1,param_4);
  FUN_2016466c(0x204702a4);
  return;
}


// ===== scope_ramp_get @ 20134398 (44 bytes)

/* (mode 8/9/other): second colour ramp from the objects 0x20474D04 / 0x20478550 / 0x20474C78
   (gui.md 3DSS front trace) [fact] */

void scope_ramp_get(int param_1)

{
  if (param_1 == 8) {
    FUN_20164674(0x20474d04);
    return;
  }
  if (param_1 != 9) {
    FUN_2016466c(0x20474c78);
    return;
  }
  FUN_20164654(0x20478550);
  return;
}


// ===== FUN_201343c4 @ 201343c4 (40 bytes)

void FUN_201343c4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_20163428(&DAT_2047963c,param_1,param_2,param_3,0);
  return;
}


// ===== FUN_201343ec @ 201343ec (28 bytes)

void FUN_201343ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_20163428(&DAT_2047963c,param_1,param_3,param_4,param_5);
  return;
}


// ===== scope3d_line_markers @ 20134408 (36 bytes)

/* (i): 0x20489720 + 0x54*i, the per-line marker record of the 3DSS (gui.md: 0x54 bytes per line)
   [fact] */

int scope3d_line_markers(int param_1)

{
  return param_1 * 0x54 + 0x20489720;
}


// ===== scope_wf_add_row @ 20134414 (16 bytes)

/* (record): adds a waterfall row to the scope object (method 0x20157D3C, gui.md 2D renderer step 2)
   [fact] */

void scope_wf_add_row(undefined4 param_1)

{
  scope_obj_wf_add_row(&DAT_2047963c,param_1,0);
  return;
}


// ===== scope_wf_add_row_mode @ 20134424 (16 bytes)

/* (record, mode): scope_obj_wf_add_row(0x2047963C, record, mode); scope_wf_add_row passes mode 0
   [fact] */

void scope_wf_add_row_mode(undefined4 param_1,undefined4 param_2)

{
  scope_obj_wf_add_row(&DAT_2047963c,param_1,param_2);
  return;
}


// ===== scope_wf_row_addr @ 20134434 (116 bytes)

/* (i): 0x2049476C + bank 0x20450280 * 0x33F40 + slot * 0x640, the i-th newest waterfall row
   (gui.md) [fact] */

int scope_wf_row_addr(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = ring133_offset(&DAT_204fc5f0,~param_1,param_2);
  if (DAT_20450280 == 1) {
    iVar1 = ring133_offset(&DAT_204fc5ec,~param_1);
  }
  return DAT_20450280 * 0x33f40 + iVar1 * 0x640 + 0x2049476c;
}


// ===== FUN_20134444 @ 20134444 (36 bytes)

void FUN_20134444(undefined4 param_1,undefined4 param_2)

{
  thunk_FUN_20162d48(&DAT_2047963c,param_1);
  FUN_201584f8(&DAT_2047963c,param_2);
  return;
}


// ===== FUN_20134468 @ 20134468 (12 bytes)

void FUN_20134468(undefined4 param_1)

{
  FUN_201584f8(&DAT_2047963c,param_1);
  return;
}


// ===== FUN_20134474 @ 20134474 (12 bytes)

void FUN_20134474(undefined4 param_1)

{
  FUN_20158544(&DAT_2047963c,param_1);
  return;
}


// ===== scope3d_layout_set @ 20134480 (120 bytes)

/* (expanded): stores the flag in four 3D sub-objects and selects the vertical scale tables
   0x203D9A18/0x203D9A9E (set) or 0x203D99DC/0x203D9A80 (clear) [fact] */

void scope3d_layout_set(int param_1)

{
  DAT_2047c848 = (undefined1)param_1;
  DAT_2047f400 = DAT_2047c848;
  DAT_2047fd80 = DAT_2047c848;
  DAT_20482938 = DAT_2047c848;
  if (param_1 != 0) {
    DAT_20450278 = &DAT_203d9a18;
  }
  else {
    DAT_20450278 = (undefined2 *)&DAT_203d99dc;
  }
  if (param_1 != 0) {
    DAT_2045027c = &DAT_203d9a9e;
  }
  else {
    DAT_2045027c = (undefined2 *)&DAT_203d9a80;
  }
  return;
}


// ===== scope_reset_bank0 @ 2013448c (12 bytes)

/* scope_obj_reset_bank0(0x2047963C) [fact] */

void scope_reset_bank0(undefined4 param_1)

{
  scope_obj_reset_bank0(&DAT_2047963c,param_1);
  return;
}


// ===== scope_reset_bank1 @ 20134498 (8 bytes)

/* scope_obj_reset_bank1(0x2047963C) [fact] */

void scope_reset_bank1(void)

{
  scope_obj_reset_bank1(&DAT_2047963c);
  return;
}


// ===== scope_frame_buf @ 201344a0 (8 bytes)

void * scope_frame_buf(void)

{
  return &DAT_204832bb;
}


// ===== scope_indices_clear @ 201344a8 (8 bytes)

/* scope_obj_indices_clear(0x2047963C) [fact] */

void scope_indices_clear(void)

{
  scope_obj_indices_clear(&DAT_2047963c);
  return;
}


// ===== capture_merge_row @ 201344c8 (88 bytes)

/* overlay one layer row; 0 = transparent unless inside an alpha window */

void capture_merge_row(ushort param_1,int param_2,int param_3,uint param_4)

{
  short sVar1;
  uint layer_alpha_rect_hit_ret;
  uint uVar2;
  
  uVar2 = 0;
  do {
    sVar1 = *(short *)(param_3 + uVar2 * 2);
                    /* pixel inside a layer's opaque alpha window [doc, inference] */
    if ((sVar1 != 0) ||
       (layer_alpha_rect_hit_ret = layer_alpha_rect_hit(param_4,uVar2 & 0xffff,(uint)param_1),
       layer_alpha_rect_hit_ret != 0)) {
      *(short *)(param_2 + uVar2 * 2) = sVar1;
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 800);
  return;
}


// ===== rgb565_row_to_bgr24 @ 20134520 (76 bytes)

void rgb565_row_to_bgr24(int param_1,int param_2)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int i;
  int iVar4;
  
  i = 0;
  do {
    iVar1 = i * 2;
    iVar3 = i * 3;
    iVar4 = iVar3 + param_2;
    i = i + 1;
    uVar2 = *(ushort *)(param_1 + iVar1);
    *(byte *)(iVar4 + 2) = (byte)(uVar2 >> 8) & 0xf8;
    *(byte *)(iVar4 + 1) = (byte)(uVar2 >> 3) & 0xfc;
    *(char *)(param_2 + iVar3) = (char)uVar2 << 3;
  } while (i < 800);
  return;
}


// ===== bmp_write_screen @ 2013456c (216 bytes)

/* 54-byte header + 480 bottom-up 24-bit rows, layers merged */

undefined4 bmp_write_screen(uint param_1)

{
  uint uVar1;
  int iVar2;
  void *fb_get_front_addr_ret;
  void *fb_get_front_addr_ret_2;
  int i;
  
  uVar1 = fs_fwrite(0x208085c4,1,0x36,param_1);
  if (uVar1 != 0) {
    iVar2 = fb_get_layer_addr(0);
    fb_get_front_addr_ret = fb_get_front_addr(DAT_208085b8);
    fb_get_front_addr_ret_2 = fb_get_front_addr(DAT_208085bc);
    i = 0x1df;
    while( true ) {
      memcpy(&DAT_20908710,iVar2 + i * 0x640,0x640);
                    /* overlay one layer row [doc, inference] */
      capture_merge_row((ushort)i,0x20908710,(int)((int)fb_get_front_addr_ret + i * 0x640),4);
      capture_merge_row((ushort)i,0x20908710,(int)((int)fb_get_front_addr_ret_2 + i * 0x640),5);
      rgb565_row_to_bgr24(0x20908710,0x20908d50);
      uVar1 = fs_fwrite(0x20908d50,1,0x960,param_1);
      if (uVar1 == 0) break;
      i = i + -1;
      if (i < 0) {
        return 0;
      }
    }
  }
  return 1;
}


// ===== screen_capture_bmp @ 20134644 (416 bytes)

/* I:\FT-710\Capture\20YYMMDD_HHMMSS.bmp */

void screen_capture_bmp(void)

{
  int iVar1;
  uint fs_fopen_ret;
  undefined1 auStack_68 [64];
  byte local_28 [4];
  byte local_24 [4];
  byte local_20 [4];
  byte local_1c [4];
  byte local_18 [4];
  byte local_14 [4];
  uint local_10;
  uint local_c;
  
  iVar1 = fs_disk_free(0x49,&local_10,&local_c);
  if ((iVar1 != 0) || (local_10 == 0 && (0x119435 < local_c) <= local_10)) goto LAB_20134794;
  if (gui_frame.cmd == 0x7a) {
    return;
  }
  screenshot_popup();
                    /* flip only graphics 1 [doc, inference] */
  gui_flip_one(0);
  itron_tslp_tsk(0xffffffff);
                    /* directory handle, 0 on error [doc] */
  iVar1 = fs_opendir("I:\\FT-710\\Capture");
  if (iVar1 == 0) {
    iVar1 = fs_opendir("I:\\FT-710");
    if (iVar1 == 0) {
      iVar1 = fs_mkdir("I:\\FT-710");
      if (iVar1 == 0) goto LAB_201347b8;
    }
    else {
      fs_closedir();
LAB_201347b8:
      iVar1 = fs_mkdir("I:\\FT-710\\Capture");
      if (iVar1 == 0) goto LAB_201346c0;
    }
                    /* Per-task FS context 0x2091D0BC[tskid] [doc] */
    fs_task_ctx_get();
  }
  else {
    fs_closedir();
LAB_201346c0:
    rtc_get_datetime(local_28,local_24,local_20,local_1c,local_18,local_14);
    sprintf(auStack_68,"I:\\FT-710\\Capture\\20%02d%02d%02d_%02d%02d%02d.bmp",
            (local_28[0] & 0xf) + (uint)(local_28[0] >> 4) * 10,
            (local_24[0] & 0xf) + (uint)(local_24[0] >> 4) * 10,
            (local_20[0] & 0xf) + (uint)(local_20[0] >> 4) * 10,
            (local_1c[0] & 0xf) + (uint)(local_1c[0] >> 4) * 10,
            (local_18[0] & 0xf) + (uint)(local_18[0] >> 4) * 10,
            (local_14[0] & 0xf) + (uint)(local_14[0] >> 4) * 10);
    fs_fopen_ret = fs_fopen((uint)auStack_68,0x20134844);
    if (fs_fopen_ret != 0) {
      bmp_write_screen();
      fs_fclose(fs_fopen_ret);
    }
  }
LAB_20134794:
  gui_flip_one(1);
  return;
}


// ===== debug_screenshot_root @ 20134854 (256 bytes)

/* F10 (debug): I:\20YYMMDD_HHMMSS.bmp */

void debug_screenshot_root(void)

{
  uint fs_fopen_ret;
  int i;
  bool bVar1;
  undefined1 auStack_68 [64];
  byte local_28 [4];
  byte local_24 [4];
  byte local_20 [4];
  byte local_1c [4];
  byte local_18 [4];
  byte local_14 [8];
  
  rtc_get_datetime(local_28,local_24,local_20,local_1c,local_18,local_14);
  sprintf(auStack_68,"I:\\20%02d%02d%02d_%02d%02d%02d.bmp",
          (local_28[0] & 0xf) + (uint)(local_28[0] >> 4) * 10,
          (local_24[0] & 0xf) + (uint)(local_24[0] >> 4) * 10,
          (local_20[0] & 0xf) + (uint)(local_20[0] >> 4) * 10,
          (local_1c[0] & 0xf) + (uint)(local_1c[0] >> 4) * 10,
          (local_18[0] & 0xf) + (uint)(local_18[0] >> 4) * 10,
          (local_14[0] & 0xf) + (uint)(local_14[0] >> 4) * 10);
  i = 2;
  do {
    fs_fopen_ret = fs_fopen((uint)auStack_68,0x20134844);
    if (fs_fopen_ret != 0) {
      bmp_write_screen();
      fs_fclose(fs_fopen_ret);
      return;
    }
    itron_dly_tsk(0x32);
    bVar1 = i != 0;
    i = i + -1;
  } while (bVar1);
  return;
}


// ===== sdmenu_scr_search_files @ 20134978 (860 bytes)

/* scr_sd_menu byte 1 = 1..4: title from 0x208085FC, "Searching files...", builds the file list
   (sdmenu_list_files -> 0x209096B0, count 0x20909CF0) and answers 0xC3 (byte 1 + 0x40);
   mainlink_send_sd_absent without a card [fact] */

void sdmenu_scr_search_files(int param_1)

{
  byte bVar1;
  bool sd_present_ret;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_64;
  undefined1 auStack_63 [35];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  uVar4 = (uint)bVar1;
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,*(int *)(&DAT_208085fc + uVar4 * 4),4,400,0xf,0x20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(uVar2,0x1e,3,&DAT_203e5e2c);
  gui_draw_text_centered(uVar2,0x2042824e,0xdc,400,0xc,0x20803bc0);
  gui_scrollbar_draw(uVar2,0x60,700,0x5e,0x13b,0,0,5,0x821);
  fb_fill_rect(uVar2,0x821,0x1f,0x2ba,0x62,0x3c);
  gui_draw_runs(uVar2,0x1f,0x2ba,&DAT_2016dc48);
  gui_draw_runs(uVar2,0x37,0x2dd,&DAT_2016dc58);
  fb_fill_rect(uVar2,0x821,0x1a0,0x2ba,0x62,0x3c);
  gui_draw_runs(uVar2,0x1a0,0x2ba,&DAT_2016dc48);
  gui_draw_runs(uVar2,0x1b6,0x2dd,&DAT_2016dc68);
  iVar3 = sd_state_bit7();
  if (iVar3 == 0) {
    local_2c = 0;
    local_40._0_2_ = (ushort)(byte)(bVar1 + 0x40);
    local_3c = 0;
    local_28 = 0;
    local_40._0_3_ = CONCAT12(4,(ushort)local_40);
    local_40 = (uint)(uint3)local_40;
    local_38 = 0;
    local_34 = 0;
    local_64 = 0xc3;
    local_30 = 0;
    local_24 = 0;
    local_20 = 0;
    memcpy(auStack_63,&local_40,0x21);
    mainlink_queue_frame(&local_64,0x22);
    return;
  }
  if ((uVar4 == 2 || uVar4 == 4) && (sd_present_ret = sd_present(), sd_present_ret)) {
    local_2c = 0;
    local_40._0_2_ = (ushort)(byte)(bVar1 + 0x40);
    local_3c = 0;
    local_28 = 0;
    local_40._0_3_ = CONCAT12(1,(ushort)local_40);
    local_40 = (uint)(uint3)local_40;
    local_38 = 0;
    local_34 = 0;
    local_64 = 0xc3;
    local_30 = 0;
    local_24 = 0;
    local_20 = 0;
    memcpy(auStack_63,&local_40,0x21);
    mainlink_queue_frame(&local_64,0x22);
    return;
  }
                    /* opens the SD folder for the kind [doc] */
  DAT_20909cf0 = sdmenu_list_files(uVar4 != 1 && uVar4 != 2,&DAT_209096b0,100);
  iVar3 = sd_state_bit7();
  if (iVar3 == 0) {
                    /* E2 frame with byte 1 = 0 [doc, inference] */
    mainlink_send_sd_absent();
    return;
  }
  local_2c = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_64 = 0xc3;
  local_40._0_3_ = (uint3)(byte)(bVar1 + 0x40);
  local_40 = CONCAT13((undefined1)DAT_20909cf0,(uint3)local_40);
  memcpy(auStack_63,&local_40,0x21);
  mainlink_queue_frame(&local_64,0x22);
  FUN_20161bb0();
  return;
}


// ===== sdmenu_scr_file_list @ 20134984 (944 bytes)

/* scr_sd_menu 0x41..0x44 step 1: draws the file rows (75-px pitch, highlight frame 0xF980 for the
   selected row, scroll bar gui_scrollbar_draw with count 0x20909CF0) [fact] */

void sdmenu_scr_file_list(int param_1)

{
  byte bVar1;
  uint uVar2;
  int i;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  uVar4 = (uint)*(byte *)(param_1 + 1);
  bVar1 = *(byte *)(param_1 + 3);
  uVar5 = (uint)*(byte *)(param_1 + 4);
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,*(int *)(&DAT_208084fc + uVar4 * 2),4,400,0xf,0x20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(uVar2,0x1e,3,&DAT_203e5e2c);
  i = 0;
  iVar3 = 5;
  if (DAT_20909cf0 < 5) {
    iVar3 = DAT_20909cf0;
  }
  if (0 < iVar3) {
    do {
      gui_draw_text(uVar2,&DAT_209096b0 + ((uint)bVar1 + i) * 0x10,i * 0x4b + 0x38U & 0xffff,0x127,
                    0xf,&DAT_20800b1c);
      fb_fill_box(uVar2,i * 0x4b + 0x67U & 0xffff,7,0x2ae,1,0x821);
      i = i + 1;
    } while (i < iVar3);
  }
  if (uVar4 == 0x42 || uVar4 == 0x44) {
    fb_fill_rect(uVar2,0x821,0x1a0,0x1d4,(uint)*DAT_20802290,(uint)DAT_20802290[1]);
    gui_draw_runs(uVar2,0x1a0,0x1d4,DAT_20802290);
    gui_draw_runs(uVar2,0x1b7,0x1dd,&DAT_203e5e4c);
  }
  fb_fill_rect(uVar2,0x821,0x1a0,0x247,(uint)*DAT_20802290,(uint)DAT_20802290[1]);
  gui_draw_runs(uVar2,0x1a0,0x247,DAT_20802290);
  gui_draw_runs(uVar2,0x1b7,0x250,&DAT_203e5e3c);
  if (uVar5 == 0xfe) {
    if (uVar4 == 0x42 || uVar4 == 0x44) {
      fb_draw_round_frame_wrap(uVar2,0x1a0,0x1d4,*DAT_20802290,DAT_20802290[1],3);
    }
  }
  else if (uVar5 == 0xff) {
    fb_draw_round_frame_wrap(uVar2,0x1a0,0x247,*DAT_20802290,DAT_20802290[1],3);
    goto LAB_20161e8c;
  }
  if ((int)uVar5 < iVar3) {
    fb_draw_round_frame(uVar2,uVar5 * 0x4b + 0x1e,3,0x2b2,0x4f,3,0xf980);
  }
LAB_20161e8c:
  gui_scrollbar_draw(uVar2,0x60,700,0x5e,0x13b,(uint)bVar1,DAT_20909cf0,5,0x821);
  fb_fill_rect(uVar2,0x821,0x1f,0x2ba,0x62,0x3c);
  gui_draw_runs(uVar2,0x1f,0x2ba,&DAT_2016dc48);
  gui_draw_runs(uVar2,0x37,0x2dd,&DAT_2016dc58);
  fb_fill_rect(uVar2,0x821,0x1a0,0x2ba,0x62,0x3c);
  gui_draw_runs(uVar2,0x1a0,0x2ba,&DAT_2016dc48);
  gui_draw_runs(uVar2,0x1b6,0x2dd,&DAT_2016dc68);
  return;
}


// ===== sdmenu_scr_loading @ 20134990 (692 bytes)

/* scr_sd_menu 0x41/0x43 step 0x10: "LOADING", sdmenu_select_load + sdmenu_request loop with
   progress bar, then sdmenu_req_save; returns non-zero when the transfer to MAIN follows [fact] */

bool sdmenu_scr_loading(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char sdmenu_request_ret;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c;
  undefined1 auStack_5b [35];
  uint local_38;
  uint local_34;
  uint local_30;
  undefined *local_2c;
  int iStack_28;
  
  local_2c = &DAT_209096b0;
  iStack_28 = param_1;
  local_38 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  uVar6 = (uint)bVar1;
  bVar2 = *(byte *)(param_1 + 3);
  bVar3 = *(byte *)(param_1 + 4);
  local_30 = 0;
  fb_clear_rect(local_38,0,0,800,0x1e0);
  fb_fill_rect(local_38,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(local_38,3,3,&DAT_2016dc08);
  gui_draw_text_centered(local_38,*(int *)(&DAT_208084fc + uVar6 * 2),4,400,0xf,0x20800b1c);
  fb_fill_rect(local_38,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(local_38,0x1e,3,&DAT_203e5e2c);
  gui_draw_text_centered(local_38,0x2042822c,0xdc,400,0xf,0x20800b1c);
  sdmenu_select_load((uint)(uVar6 != 0x41),(int)local_2c,(uint)bVar2,bVar3);
  while (sdmenu_request_ret = sdmenu_request(0,&local_30,&local_34), sdmenu_request_ret == '\0') {
    gui_draw_progress_bar(local_38,0xf0,0x129,local_30 & 0xffff);
    vdc5_wait_frames(1);
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
    local_38 = fb_get_layer_addr(DAT_208085bc);
  }
  if (sdmenu_request_ret == '\x01') {
    gui_draw_progress_bar(local_38,0xf0,0x129,100);
    vdc5_wait_frames(1);
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
    fb_get_layer_addr(DAT_208085bc);
  }
  else {
    iVar5 = sd_state_bit7();
    if (iVar5 == 0) {
                    /* E2 frame with byte 1 = 0 [doc, inference] */
      mainlink_send_sd_absent();
      return false;
    }
  }
  local_6c = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_80._0_2_ = CONCAT11(0x10,bVar1);
  local_70 = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  if (sdmenu_request_ret == '\x01') {
    local_80 = (uint)(ushort)local_80;
    be16_store(32000,(int)&local_80 + 3);
LAB_201615c8:
    if (local_34 == 0) {
                    /* MAIN transfer code 0x41 [doc, inference] */
      sdmenu_req_save((uint)(uVar6 != 0x41),32000);
    }
  }
  else {
    if (local_34 == 1) {
      uVar4 = 2;
    }
    else {
      if (local_34 != 2) {
        local_80._0_3_ = CONCAT12(0xff,(ushort)local_80);
        local_80 = (uint)(uint3)local_80;
        goto LAB_201615c8;
      }
      uVar4 = 3;
    }
    local_80._0_3_ = CONCAT12(uVar4,(ushort)local_80);
    local_80 = (uint)(uint3)local_80;
  }
  local_5c = 0xc3;
  memcpy(auStack_5b,&local_80,0x21);
  mainlink_queue_frame(&local_5c,0x22);
  FUN_20161bb0();
  return local_34 == 0;
}


// ===== sdmenu_scr_load_wait @ 2013499c (408 bytes)

/* scr_sd_menu step 0x10 after sdmenu_scr_loading: "PROCESSING", progress bar from sdmenu_xfer_len
   until all bytes went or MAIN's frame changes [fact] */

void sdmenu_scr_load_wait(int param_1)

{
  byte bVar1;
  bool mainlink_last_frame_differs_ret;
  uint uVar2;
  uint d;
  int iVar3;
  ulonglong __aeabi_idivmod_ret;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,*(int *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,0x20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(uVar2,0x1e,3,&DAT_203e5e2c);
  gui_draw_text_centered(uVar2,0x20428234,0xdc,400,0xf,0x20800b1c);
  d = sdmenu_xfer_len();
  while( true ) {
    iVar3 = sd_state_bit7();
    if (iVar3 == 0) {
                    /* E2 frame with byte 1 = 0 [doc, inference] */
      mainlink_send_sd_absent();
      return;
    }
    iVar3 = sdmenu_xfer_len();
    __aeabi_idivmod_ret = __aeabi_idivmod(iVar3 * 100,d);
    gui_draw_progress_bar(uVar2,0xf0,0x129,(uint)__aeabi_idivmod_ret & 0xffff);
    if (((int)d <= iVar3) ||
       (mainlink_last_frame_differs_ret = mainlink_last_frame_differs(param_1),
       mainlink_last_frame_differs_ret)) break;
    vdc5_wait_frames(1);
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
    uVar2 = fb_get_layer_addr(DAT_208085bc);
  }
  return;
}


// ===== sdmenu_scr_name_check @ 201349a8 (232 bytes)

/* scr_sd_menu 0x42/0x44 step 2: default file name (sdmenu_default_name) or sdmenu_file_exists for
   the chosen row, answer in a 0xC3 frame [fact] */

void sdmenu_scr_name_check(int param_1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint sdmenu_file_exists_ret;
  int unaff_r5;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34;
  undefined1 auStack_33 [39];
  
  cVar1 = *(char *)(param_1 + 1);
  bVar2 = *(byte *)(param_1 + 3);
  local_44 = 0;
  if (cVar1 == 'B') {
    unaff_r5 = 0;
  }
  local_58._0_2_ = CONCAT11(1,cVar1);
  uVar3 = (ushort)local_58;
  if (cVar1 != 'B') {
    unaff_r5 = 1;
  }
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_58 = (uint)(ushort)local_58;
  local_48 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  if (bVar2 == 0xff) {
    if (DAT_20909cf0 < 100) {
                    /* "20YY_MM_DD_NN" from the RTC date [doc, inference] */
      sdmenu_default_name(unaff_r5,&DAT_209096b0,DAT_20909cf0,(int)&local_58 + 3);
    }
    else {
      local_58._0_3_ = CONCAT12(1,uVar3);
      local_58 = (uint)(uint3)local_58;
    }
  }
  else {
                    /* word copy while aligned [doc, inference] */
    strcpy((int)&local_58 + 3);
    sdmenu_file_exists_ret = sdmenu_file_exists(unaff_r5,(uint)(&DAT_209096b0 + (uint)bVar2 * 0x10))
    ;
    if (sdmenu_file_exists_ret != 0) {
      local_58._0_3_ = CONCAT12(2,(ushort)local_58);
    }
  }
  local_34 = 0xc3;
  memcpy(auStack_33,&local_58,0x21);
  mainlink_queue_frame(&local_34,0x22);
  return;
}


// ===== sdmenu_scr_name_lookup @ 201349b4 (236 bytes)

/* scr_sd_menu 0x42/0x44 step 3: finds the typed name (strcasecmp over the 16-byte list 0x209096B0)
   and checks sdmenu_file_exists, answer in 0xC3 [fact] */

void sdmenu_scr_name_lookup(int param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint sdmenu_file_exists_ret;
  int i;
  undefined *puVar4;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 auStack_3b [35];
  
  cVar1 = *(char *)(param_1 + 1);
  puVar4 = (undefined *)0x0;
  i = 0;
  if (0 < DAT_20909cf0) {
    do {
                    /* Case-insensitive compare with tolower [doc] */
      iVar3 = strcasecmp(param_1 + 3,&DAT_209096b0 + i * 0x10);
      if (iVar3 == 0) {
        puVar4 = &DAT_209096b0 + i * 0x10;
        break;
      }
      i = i + 1;
    } while (i < DAT_20909cf0);
  }
  local_4c = 0;
  local_60._0_2_ = CONCAT11(2,cVar1);
  uVar2 = (ushort)local_60;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_60 = (uint)(ushort)local_60;
  local_50 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  if (puVar4 != (undefined *)0x0) {
    local_60._0_3_ = CONCAT12(1,uVar2);
    local_60 = (uint)(uint3)local_60;
    sdmenu_file_exists_ret = sdmenu_file_exists((uint)(cVar1 != 'B'),(uint)puVar4);
    if (sdmenu_file_exists_ret != 0) {
      local_60._0_3_ = CONCAT12(2,(ushort)local_60);
    }
  }
  local_3c = 0xc3;
  memcpy(auStack_3b,&local_60,0x21);
  mainlink_queue_frame(&local_3c,0x22);
  return;
}


// ===== sdmenu_scr_save_xfer @ 201349c0 (584 bytes)

/* scr_sd_menu 0x42/0x44 step 4: "PROCESSING", sdmenu_req_load, progress from sdmenu_xfer_len until
   done or MAIN's frame changes [fact] */

void sdmenu_scr_save_xfer(uint param_1)

{
  byte bVar1;
  bool mainlink_last_frame_differs_ret;
  ushort be16_load_ret;
  uint uVar2;
  uint d;
  int iVar3;
  uint uVar4;
  ulonglong __aeabi_idivmod_ret;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 auStack_4b [39];
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  be16_load_ret = be16_load((byte *)(param_1 + 3));
  fb_clear_rect(uVar2,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,*(int *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,0x20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(uVar2,0x1e,3,&DAT_203e5e2c);
  gui_draw_text_centered(uVar2,0x20428261,0xdc,400,0xf,0x20800b1c);
  uVar4 = (uint)(bVar1 != 0x42);
                    /* MAIN transfer code 0x42 [doc, inference] */
  sdmenu_req_load(uVar4,be16_load_ret);
  local_5c = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_70 = (uint)CONCAT11(3,bVar1);
  local_4c = 0xc3;
  memcpy(auStack_4b,&local_70,0x21);
  mainlink_queue_frame(&local_4c,0x22);
  d = sdmenu_xfer_len(uVar4,0);
  while( true ) {
    iVar3 = sd_state_bit7();
    if (iVar3 == 0) {
                    /* E2 frame with byte 1 = 0 [doc, inference] */
      mainlink_send_sd_absent();
      return;
    }
    iVar3 = sdmenu_xfer_len(uVar4,1);
    __aeabi_idivmod_ret = __aeabi_idivmod(iVar3 * 100,d);
    gui_draw_progress_bar(uVar2,0xf0,0x129,(uint)__aeabi_idivmod_ret & 0xffff);
    vdc5_wait_frames(1);
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
    uVar2 = fb_get_layer_addr(DAT_208085bc);
    if ((int)d <= iVar3) break;
    mainlink_last_frame_differs_ret = mainlink_last_frame_differs(param_1);
    if (mainlink_last_frame_differs_ret) {
      return;
    }
  }
  gui_draw_progress_bar(uVar2,0xf0,0x129,100);
  vdc5_wait_frames(1);
  gui_update_layers();
  itron_tslp_tsk(0xffffffff);
  fb_get_layer_addr(DAT_208085bc);
  return;
}


// ===== sdmenu_scr_saving @ 201349cc (708 bytes)

/* scr_sd_menu 0x42/0x44 step 0x10: "SAVING", blank name -> sdmenu_default_name, sdmenu_select +
   sdmenu_request loop with progress bar, answer 0xC3 [fact] */

void sdmenu_scr_saving(int param_1)

{
  byte bVar1;
  ushort uVar2;
  char sdmenu_request_ret;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  undefined1 auStack_57 [35];
  uint local_34;
  uint local_30;
  uint local_2c;
  
  local_6c = fb_get_layer_addr(DAT_208085bc);
  local_2c = (uint)*(byte *)(param_1 + 3);
  bVar1 = *(byte *)(param_1 + 1);
  uVar5 = (uint)bVar1;
  local_34 = 0;
  fb_fill_rect(local_6c,0x821,0,0,800,0x1e0);
  fb_fill_rect(local_6c,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(local_6c,3,3,&DAT_2016dc08);
  gui_draw_text_centered(local_6c,*(int *)(&DAT_208084fc + uVar5 * 2),4,400,0xf,0x20800b1c);
  fb_fill_rect(local_6c,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(local_6c,0x1e,3,&DAT_203e5e2c);
  gui_draw_text_centered(local_6c,0x20428215,0xdc,400,0xf,0x20800b1c);
  memcpy(&local_68,param_1 + 6,0x10);
  iVar4 = memcmp(&local_68,&PTR_DAT_2042821c,0xf);
  if ((iVar4 == 0) || ((char)local_68 == '\0')) {
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    local_5c = 0;
                    /* "20YY_MM_DD_NN" from the RTC date [doc, inference] */
    sdmenu_default_name(uVar5 != 0x42,&DAT_209096b0,DAT_20909cf0,&local_68);
  }
  sdmenu_select(uVar5 != 0x42,(uint)&local_68,(byte)local_2c);
  while (sdmenu_request_ret = sdmenu_request(1,&local_34,&local_30), sdmenu_request_ret == '\0') {
    gui_draw_progress_bar(local_6c,0xf0,0x129,local_34 & 0xffff);
    vdc5_wait_frames(1);
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
    local_6c = fb_get_layer_addr(DAT_208085bc);
  }
  if (sdmenu_request_ret == '\x01') {
    gui_draw_progress_bar(local_6c,0xf0,0x129,100);
    vdc5_wait_frames(1);
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
    fb_get_layer_addr(DAT_208085bc);
  }
  else {
    iVar4 = sd_state_bit7();
    if (iVar4 == 0) {
                    /* E2 frame with byte 1 = 0 [doc, inference] */
      mainlink_send_sd_absent();
      return;
    }
  }
  local_7c = 0;
  local_90._0_2_ = CONCAT11(0x10,bVar1);
  uVar2 = (ushort)local_90;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_90 = (uint)(ushort)local_90;
  local_80 = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  if (sdmenu_request_ret != '\x01') {
    if (local_30 == 1) {
      local_90._0_3_ = CONCAT12(2,uVar2);
      local_90 = (uint)(uint3)local_90;
    }
    else {
      if (local_30 == 2) {
        uVar3 = 3;
      }
      else {
        uVar3 = 0xff;
      }
      local_90._0_3_ = CONCAT12(uVar3,uVar2);
      local_90 = (uint)(uint3)local_90;
    }
  }
  local_58 = 0xc3;
  memcpy(auStack_57,&local_90,0x21);
  mainlink_queue_frame(&local_58,0x22);
  FUN_20161bb0();
  return;
}


// ===== sdmenu_scr_info @ 201349d8 (424 bytes)

/* scr_sd_menu byte 1 = 5: sd_info_screen(0x20909CF4) and a 0xC3 answer [fact] */

void sdmenu_scr_info(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,*(int *)(&DAT_208085fc + (uint)bVar1 * 4),4,400,0xf,0x20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(uVar2,0x1e,3,&DAT_203e5e2c);
  sd_info_screen(0x20909cf4);
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  iVar3 = sd_state_bit7();
  if (iVar3 != 0) {
    local_60._0_2_ = CONCAT11(bVar1 + 0x40,0xc3);
    mainlink_queue_frame(&local_60,0x22);
    FUN_20161bb0();
    return;
  }
  local_28 = 0;
  local_38 = 0;
  local_24 = 0;
  local_3c = (uint)CONCAT12(4,(ushort)(byte)(bVar1 + 0x40));
  local_60 = CONCAT31(local_60._1_3_,0xc3);
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_20 = 0;
  local_1c = 0;
  memcpy((int)&local_60 + 1,&local_3c,0x21);
  mainlink_queue_frame(&local_60,0x22);
  return;
}


// ===== sdmenu_scr_info_text @ 201349e4 (524 bytes)

/* scr_sd_menu 0x45: draws the two text lines 0x20909CF4 / 0x20909D34 that sd_info_screen filled,
   with separators [fact] */

void sdmenu_scr_info_text(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  cVar2 = *(char *)(param_1 + 4);
  fb_fill_rect(uVar3,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar3,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar3,3,3,&DAT_2016dc08);
  gui_draw_text_centered(uVar3,*(int *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,0x20800b1c);
  fb_fill_rect(uVar3,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(uVar3,0x1e,3,&DAT_203e5e2c);
  fb_fill_rect(uVar3,0x821,0x1a0,0x247,(uint)*DAT_20802290,(uint)DAT_20802290[1]);
  gui_draw_runs(uVar3,0x1a0,0x247,DAT_20802290);
  gui_draw_runs(uVar3,0x1b7,0x250,&DAT_203e5e3c);
  if (cVar2 == -1) {
    fb_draw_round_frame_wrap(uVar3,0x1a0,0x247,*DAT_20802290,DAT_20802290[1],3);
  }
  gui_draw_text_centered(uVar3,0x20909cf4,0x38,400,0xf,0x20800b1c);
  fb_fill_box(uVar3,0x67,7,0x312,1,0x821);
  gui_draw_text_centered(uVar3,0x20909d34,0x83,400,0xf,0x20800b1c);
  fb_fill_box(uVar3,0xb2,7,0x312,1,0x821);
  return;
}


// ===== sdmenu_scr_card_check @ 201349f0 (348 bytes)

/* scr_sd_menu byte 1 = 8: sd_present -> 0xC3 answer with status 1 (card) or 0 [fact] */

void sdmenu_scr_card_check(int param_1)

{
  byte bVar1;
  bool sd_present_ret;
  uint uVar2;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,*(int *)(&DAT_208085fc + (uint)bVar1 * 4),4,400,0xf,0x20800b1c);
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  sd_present_ret = sd_present();
  if (sd_present_ret) {
    local_20 = 0;
    local_30 = 0;
    local_1c = 0;
    local_34 = (uint)CONCAT12(1,(ushort)(byte)(bVar1 + 0x40));
    local_58 = CONCAT31(local_58._1_3_,0xc3);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_18 = 0;
    local_14 = 0;
    memcpy((int)&local_58 + 1,&local_34,0x21);
    mainlink_queue_frame(&local_58,0x22);
    return;
  }
  local_58._0_2_ = CONCAT11(bVar1 + 0x40,0xc3);
  mainlink_queue_frame(&local_58,0x22);
  return;
}


// ===== sdmenu_scr_format_confirm @ 201349fc (560 bytes)

/* scr_sd_menu 0x48 step 1: "FORMAT SD CARD" confirmation screen [fact] */

void sdmenu_scr_format_confirm(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  cVar2 = *(char *)(param_1 + 4);
  fb_fill_rect(uVar3,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar3,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar3,3,3,&DAT_2016dc08);
  gui_draw_text_centered(uVar3,*(int *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,0x20800b1c);
  fb_fill_rect(uVar3,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(uVar3,0x1e,3,&DAT_203e5e2c);
  gui_draw_text_centered(uVar3,0x2042823f,0xd5,400,0xf,0x20800b1c);
  fb_fill_rect(uVar3,0x821,0x1a0,0x1d4,(uint)*DAT_20802290,(uint)DAT_20802290[1]);
  gui_draw_runs(uVar3,0x1a0,0x1d4,DAT_20802290);
  gui_draw_runs(uVar3,0x1b7,0x1dd,&DAT_203e5e5c);
  fb_fill_rect(uVar3,0x821,0x1a0,0x247,(uint)*DAT_20802290,(uint)DAT_20802290[1]);
  gui_draw_runs(uVar3,0x1a0,0x247,DAT_20802290);
  gui_draw_runs(uVar3,0x1b7,0x250,&DAT_203e5e6c);
  if (cVar2 != -2) {
    if (cVar2 == -1) {
      fb_draw_round_frame_wrap(uVar3,0x1a0,0x247,*DAT_20802290,DAT_20802290[1],3);
    }
    return;
  }
  fb_draw_round_frame_wrap(uVar3,0x1a0,0x1d4,*DAT_20802290,DAT_20802290[1],3);
  return;
}


// ===== sdmenu_scr_format_run @ 20134a08 (496 bytes)

/* scr_sd_menu 0x48 step 0x10: "Now format in progress...", sd_format_request loop with progress
   bar, sd_format_done, answer 0xC3 [fact] */

void sdmenu_scr_format_run(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 auStack_4b [35];
  int local_28;
  uint local_24 [2];
  
  uVar2 = fb_get_layer_addr(DAT_208085bc);
  bVar1 = *(byte *)(param_1 + 1);
  fb_fill_rect(uVar2,0x821,0,0,800,0x1e0);
  fb_fill_rect(uVar2,0x3186,3,3,0x31a,0x18);
  gui_draw_runs(uVar2,3,3,&DAT_2016dc08);
  gui_draw_text_centered(uVar2,*(int *)(&DAT_208084fc + (uint)bVar1 * 2),4,400,0xf,0x20800b1c);
  fb_fill_rect(uVar2,0x4a69,0x1e,3,0x31a,0x1c0);
  gui_draw_runs32(uVar2,0x1e,3,&DAT_203e5e2c);
  gui_draw_text_centered(uVar2,0x2042826c,0xd2,400,0xf,0x20800b1c);
  local_24[0] = 0;
  local_28 = 0;
  while (iVar3 = sd_format_request(local_24,&local_28), iVar3 == 0) {
    gui_draw_progress_bar(uVar2,0xf0,0x129,local_24[0] & 0xffff);
    vdc5_wait_frames(1);
    gui_update_layers();
    itron_tslp_tsk(0xffffffff);
    uVar2 = fb_get_layer_addr(DAT_208085bc);
  }
  sd_format_done();
  if ((iVar3 != 1) && (local_28 == 5)) {
                    /* E2 frame with byte 1 = 0 [doc, inference] */
    mainlink_send_sd_absent();
    return;
  }
  local_5c = 0;
  local_70._0_2_ = CONCAT11(0x10,bVar1);
  if (iVar3 == 1) {
    local_70._0_3_ = (uint3)(ushort)local_70;
  }
  else {
    local_70._0_3_ = CONCAT12(0xff,(ushort)local_70);
  }
  local_70 = (uint)(uint3)local_70;
  local_60 = 0;
  local_4c = 0xc3;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  memcpy(auStack_4b,&local_70,0x21);
  mainlink_queue_frame(&local_4c,0x22);
  FUN_20161bb0();
  return;
}


// ===== FUN_20134a18 @ 20134a18 (104 bytes)

int FUN_20134a18(int param_1)

{
  longlong lVar1;
  uint div10_round_ret;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 < 5) {
    return 0;
  }
  if (param_1 < 0xf0) {
    lVar1 = (longlong)(param_1 + -4) * 10000000;
    uVar3 = __aeabi_ldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),0xec,0);
    div10_round_ret = div10_round((uint)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    iVar2 = __aeabi_ldivmod((int)((ulonglong)div10_round_ret * 0xb3),
                            ((int)div10_round_ret >> 0x1f) * 0xb3 +
                            (int)((ulonglong)div10_round_ret * 0xb3 >> 0x20),1000000,0);
    return iVar2 + 1;
  }
  return 0xb4;
}


// ===== FUN_20134a80 @ 20134a80 (60 bytes)

void FUN_20134a80(void)

{
  undefined2 local_28 [18];
  
  adc_read_all((uint *)local_28);
  *(undefined2 *)(&DAT_20909d74 + (uint)DAT_20808624 * 2) = local_28[0];
  DAT_20808624 = DAT_20808624 + 1 & 0x1f;
  return;
}


// ===== meter_draw @ 20134abc (616 bytes)

/* bar meter with peak hold, 181 sprites from 0x2080865C */

void meter_draw(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  
  iVar1 = fb_get_layer_addr(DAT_208085b8);
  if (gui_frame.cmd == 0x3a) {
LAB_20134b8c:
    uVar6 = (uint)gui_frame.meter;
  }
  else {
    uVar6 = DAT_20808640;
    if (0x3a < gui_frame.cmd) {
      if (gui_frame.cmd != 0x50) {
        if (gui_frame.cmd < 0x51) {
          if (gui_frame.cmd == 0x40 || gui_frame.cmd == 0x41) goto LAB_20134b8c;
        }
        else if (gui_frame.cmd == 0x62 || gui_frame.cmd == 0x70) goto LAB_20134b8c;
        goto LAB_20134b08;
      }
      goto LAB_20134b8c;
    }
    if (gui_frame.cmd == 0x31) goto LAB_20134b8c;
    if (gui_frame.cmd < 0x32) {
      if ((gui_frame.cmd == 0x20 || gui_frame.cmd == 0x24) || gui_frame.cmd == 0x30)
      goto LAB_20134b8c;
    }
    else if (gui_frame.cmd == 0x37 || gui_frame.cmd == 0x39) goto LAB_20134b8c;
  }
LAB_20134b08:
  iVar2 = FUN_20134a18(uVar6);
  if (iVar2 < DAT_20808638) {
    iVar4 = 0;
    if (DAT_20808638 - iVar2 == 1) {
      if (DAT_2080863c == 0) goto LAB_20134bac;
      DAT_2080863c = DAT_2080863c + -1;
    }
    else {
      DAT_2080863c = 1;
      iVar4 = (iVar2 - DAT_20808638) / 3;
      if (iVar4 == 0) {
LAB_20134bac:
        iVar4 = -1;
      }
    }
    DAT_20808638 = DAT_20808638 + iVar4;
    if (DAT_20808638 < iVar2) {
LAB_20134bbc:
      DAT_20808638 = iVar2;
    }
  }
  else if (DAT_20808638 < iVar2) {
    iVar4 = (iVar2 - DAT_20808638) / 3;
    if (iVar4 == 0) {
      DAT_20808638 = DAT_20808638 + 1;
    }
    else {
      DAT_20808638 = DAT_20808638 + iVar4;
    }
    if (iVar2 < DAT_20808638) goto LAB_20134bbc;
  }
  if (DAT_20808638 < 0xb4) {
    iVar2 = DAT_20808638;
    if (DAT_20808638 < 0) {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0xb4;
  }
  DAT_20808638 = iVar2;
  DAT_20808640 = uVar6;
  fb_clear_rect(iVar1,(uint)DAT_2080862c,(uint)DAT_2080862a,0x118,0x50);
  fb_clear_rect(iVar1,(uint)DAT_20808630,(uint)DAT_2080862e,0x40,0x11);
  gui_draw_runs(iVar1,(uint)DAT_2080862c,(uint)DAT_2080862a,(&PTR_DAT_2080865c)[iVar2]);
  if (DAT_20808634 < iVar2) {
    DAT_20808622 = DAT_20808620;
    DAT_20808634 = iVar2;
  }
  if (DAT_20808622 == 0) {
    DAT_20808634 = 0;
  }
  else {
    gui_draw_runs(iVar1,(uint)DAT_2080862c,(uint)DAT_2080862a,(&PTR_DAT_2080865c)[DAT_20808634]);
    if (DAT_20808622 < 0x21) {
      DAT_20808622 = 0;
    }
    else {
      DAT_20808622 = DAT_20808622 - 0x21;
    }
  }
  if ((gui_frame.tx_swr & 0x30) == 0x10) {
    puVar5 = &DAT_203eea9c;
  }
  else {
    if ((gui_frame.tx_swr & 0x30) != 0x20) goto LAB_20134cec;
    puVar5 = &DAT_203eeaac;
  }
  if (puVar5 != (undefined *)0x0) {
    gui_draw_runs(iVar1,(uint)DAT_20808630,(uint)DAT_2080862e,puVar5);
  }
LAB_20134cec:
  if (((byte)DAT_20808a84 & 1) != 0) {
    uVar3 = fb_get_layer_addr(DAT_208085bc);
    gui_draw_dec(uVar3,iVar2,3,0x46,100);
  }
  return;
}


// ===== meter_draw_scale @ 20134d24 (176 bytes)

/* meter scale + type label on graphics 0 */

void meter_draw_scale(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = fb_get_layer_addr(0);
  uVar2 = *(byte *)(param_1 + 0xb) & 7;
  if (param_3 != 0 || uVar2 != (*(byte *)(param_2 + 0xb) & 7)) {
    if (5 < uVar2) {
      uVar2 = 5;
    }
    fb_fill_rect(iVar1,0,10,0,0x118,0x50);
    gui_area_dirty_set(0);
    gui_draw_runs(iVar1,10,0,&DAT_203eea8c);
    gui_draw_runs(iVar1,(uint)DAT_20808628,(uint)DAT_20808626,(&PTR_DAT_20808644)[uVar2]);
    DAT_20808620 = 0;
  }
  return;
}


// ===== test_disp_init @ 20134e0c (100 bytes)

/* task "test_disp" */

void test_disp_init(void)

{
  uint uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  
  local_18 = 2;
  uStack_14 = 0;
  local_10 = 0;
  uVar1 = itron_acre_flg(0,(byte *)&local_18);
  if (0 < (int)uVar1) {
    DAT_20808934 = uVar1;
    uVar1 = itron_acre_tsk(0,(byte *)&ctsk_test_disp);
    if (0 < (int)uVar1) {
      DAT_20808938 = uVar1;
      itron_sta_tsk(uVar1,0);
    }
  }
  return;
}


// ===== debug_cmd_line_read @ 20134e70 (364 bytes)

/* parses "NNN:hh hh ...:DDDD" lines */

uint debug_cmd_line_read(short *param_1,uint param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 local_bf0 [2048];
  undefined1 auStack_3f0 [952];
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 auStack_34 [4];
  undefined1 local_30;
  undefined1 auStack_2c [3];
  undefined1 local_29;
  char local_28 [8];
  
  uVar4 = fs_fread((uint)auStack_2c,3,1,param_2);
  if ((int)uVar4 < 1) {
    uVar4 = 0xffffffff;
  }
  else {
    local_29 = 0;
    uVar2 = FUN_20154dd0(auStack_2c);
    uVar4 = (uint)uVar2;
    param_1[1] = uVar2;
    if (uVar4 != 0) {
      fs_fread((uint)local_28,1,1,param_2);
      fs_fread((uint)local_bf0,uVar4 * 3,1,param_2);
      puVar7 = auStack_34;
      fs_fread((uint)puVar7,4,1,param_2);
      local_30 = 0;
      sVar3 = FUN_20154dd0(puVar7);
      *param_1 = sVar3;
      if (sVar3 == 0) {
        *param_1 = 1000;
      }
      if (uVar4 != 0) {
        puVar7 = auStack_3f0;
      }
      local_36 = 0;
      if (uVar4 != 0) {
        iVar5 = 0;
        do {
          local_38 = local_bf0[iVar5 * 3];
          local_37 = local_bf0[iVar5 * 3 + 1];
          uVar1 = str_to_long(puVar7 + 0x3b8,0,0x10);
          iVar6 = iVar5 + 1;
          *(undefined1 *)((int)param_1 + iVar5 + 4) = uVar1;
          iVar5 = iVar6;
        } while (iVar6 < (int)uVar4);
      }
      fs_fread((uint)local_28,1,1,param_2);
      return 1;
    }
    do {
      fs_fread((uint)local_28,1,1,param_2);
    } while (local_28[0] != '\n');
    uVar4 = 0;
  }
  return uVar4;
}


// ===== debug_replay_send_cmd @ 20134fdc (268 bytes)

/* rename (was debug_recv_cmd_log): replays I:\FT-710\DEBUG_RECV_CMD\SEND_CMD.TXT into the GUI frame
   snapshot (task test_disp) */

undefined4 debug_replay_send_cmd(void)

{
  char cVar1;
  int iVar2;
  uint fs_fopen_ret;
  uint uVar3;
  undefined4 uVar4;
  ushort local_e5c;
  undefined2 local_e5a;
  char local_e58 [3000];
  char local_2a0 [576];
  undefined1 auStack_60 [64];
  
  iVar2 = sd_state_bit6();
  uVar4 = 0;
  if (iVar2 != 0) {
    snprintf(auStack_60,0x32,"%s\\%s","I:\\FT-710\\DEBUG_RECV_CMD","SEND_CMD.TXT");
    fs_fopen_ret = fs_fopen((uint)auStack_60,0x20135124);
    uVar4 = 0;
    if (fs_fopen_ret != 0) {
      do {
        __aeabi_memclr4(local_e58,3000);
        uVar3 = debug_cmd_line_read((short *)&local_e5c,fs_fopen_ret);
        cVar1 = local_e58[0];
        if (uVar3 == 0xffffffff) break;
        if (uVar3 == 1) {
          __aeabi_memclr4(local_2a0,0x240);
          uVar3 = 0;
          do {
            if ((&DAT_2080893c)[uVar3 * 0xc] == cVar1) {
              __aeabi_memcpy4(local_2a0,local_e58,local_e5a);
              break;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < 0x1a);
          if (local_2a0[0] != '\0') {
            mainlink_set_last_frame((uint)local_2a0);
          }
          itron_dly_tsk(local_e5c / 10);
        }
      } while (DAT_20808931 != '\x02');
      fs_fclose(fs_fopen_ret);
      uVar4 = 1;
    }
  }
  return uVar4;
}


// ===== task_test_disp @ 2013512c (96 bytes)

void task_test_disp(void)

{
  void *itron_twai_flg_ret;
  uint local_1c [2];
  
  DAT_20808931 = 2;
  while( true ) {
    itron_twai_flg_ret = itron_twai_flg(DAT_20808934,0xffff,5,local_1c,-1);
    if (itron_twai_flg_ret != (void *)0x0) break;
    if (local_1c[0] == 1) {
      DAT_20808931 = 1;
      debug_replay_send_cmd();
      DAT_20808931 = 2;
    }
  }
  return;
}


// ===== test_disp_start @ 2013518c (16 bytes)

/* set flag 1 -> task_test_disp runs the replay */

void test_disp_start(void)

{
  itron_set_flg(DAT_20808934,1);
  return;
}


// ===== test_disp_stop @ 2013519c (16 bytes)

void test_disp_stop(void)

{
  DAT_20808931 = 2;
  return;
}


// ===== test_disp_state @ 201351ac (12 bytes)

/* 1 = running, 2 = idle */

byte test_disp_state(void)

{
  return DAT_20808931;
}


// ===== debug_cmd_line_write @ 201351b8 (264 bytes)

/* writes one such line */

void debug_cmd_line_write(uint param_1,int param_2,int param_3)

{
  uint fs_fopen_ret;
  int i;
  undefined1 auStack_28 [12];
  
  fs_fopen_ret = fs_fopen(param_1,0x201352c0);
  if (fs_fopen_ret != 0) {
    snprintf(auStack_28,5,"%03d:",param_3);
    fs_fwrite((uint)auStack_28,4,1,fs_fopen_ret);
    i = 0;
    if (0 < param_3 + -1) {
      do {
        snprintf(auStack_28,4,"%02x ",*(undefined1 *)(param_2 + i));
        fs_fwrite((uint)auStack_28,3,1,fs_fopen_ret);
        i = i + 1;
      } while (i < param_3 + -1);
    }
    snprintf(auStack_28,4,0x201352d4,*(undefined1 *)(param_2 + param_3 + -1));
    fs_fwrite((uint)auStack_28,2,1,fs_fopen_ret);
    snprintf(auStack_28,6,":%04d",1000);
    fs_fwrite((uint)auStack_28,5,1,fs_fopen_ret);
    fs_fwrite(0x201352e4,1,1,fs_fopen_ret);
    fs_fclose(fs_fopen_ret);
  }
  return;
}


// ===== debug_log_recv_cmd @ 201352e8 (228 bytes)

/* appends a frame to RECV_CMD.TXT; no caller in V01-08 */

undefined4 debug_log_recv_cmd(undefined1 *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_44 [56];
  
  iVar1 = sd_state_bit6();
  uVar3 = 0;
  if (iVar1 != 0) {
    DAT_20808930 = *param_1;
    snprintf(auStack_44,0x32,"%s\\%s","I:\\FT-710\\DEBUG_RECV_CMD","dummy.txt");
    uVar2 = fs_fopen((uint)auStack_44,0x201353d8);
                    /* creates a directory [doc] */
    if ((uVar2 == 0) &&
       (((iVar1 = fs_mkdir("I:\\FT-710\\DEBUG_RECV_CMD"), iVar1 != 0 &&
         ((iVar1 = fs_mkdir("I:\\FT-710"), iVar1 != 0 ||
          (iVar1 = fs_mkdir("I:\\FT-710\\DEBUG_RECV_CMD"), iVar1 != 0)))) ||
        (uVar2 = fs_fopen((uint)auStack_44,0x201353d8), uVar2 == 0)))) {
                    /* Per-task FS context 0x2091D0BC[tskid] [doc] */
      fs_task_ctx_get();
      return 0xffffffff;
    }
    fs_fclose();
    snprintf(auStack_44,0x32,"%s\\%s","I:\\FT-710\\DEBUG_RECV_CMD","RECV_CMD.TXT");
    uVar3 = debug_cmd_line_write(auStack_44,param_1,param_2);
  }
  return uVar3;
}

