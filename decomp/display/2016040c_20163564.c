// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2016040c @ 2016040c (12 bytes)

void FUN_2016040c(int param_1)

{
  *(undefined1 *)(param_1 + 0x57) = 0;
  return;
}


// ===== fwobj_match_name @ 20160418 (132 bytes)

/* keeps the highest matching file name per object */

uint fwobj_match_name(int param_1,uint param_2,uint param_3)

{
  uint fwname_pattern_match_ret;
  int iVar1;
  uint uVar2;
  undefined1 auStack_30 [36];
  
  fwname_pattern_match_ret = fwname_pattern_match((int *)(param_1 + 0x14),param_2,param_3);
  uVar2 = 0;
  if (fwname_pattern_match_ret != 0) {
                    /* memcpy of 0x20 bytes, returns dst [doc] */
    copy32(auStack_30,param_2);
    if (*(char *)(param_1 + 0x57) == '\0') {
      memcpy(param_1 + 0x37,auStack_30,0x20);
      *(undefined1 *)(param_1 + 0x57) = 1;
    }
    else {
      iVar1 = strcasecmp(param_1 + 0x37,auStack_30);
      if (iVar1 < 1) {
        memcpy(param_1 + 0x37,auStack_30,0x20);
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


// ===== fwobj_set_status @ 2016049c (44 bytes)

/* status text (Ready, failed, ...) */

void fwobj_set_status(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 auStack_28 [32];
  
                    /* memcpy of 0x20 bytes, returns dst [doc] */
  uVar1 = copy32(auStack_28);
  memcpy(param_1 + 0x89,uVar1,0x20);
  return;
}


// ===== fwobj_version_from_name @ 201604c8 (20 bytes)

/* "0108" in the name -> "01-08" */

void fwobj_version_from_name(int param_1)

{
  FUN_20160c28(param_1 + 0xe,*(int *)(param_1 + 0x20) + param_1 + 0x37);
  return;
}


// ===== fwobj_select @ 201604dc (24 bytes)

/* marks the object selected for update */

void fwobj_select(int param_1,byte param_2)

{
  *(undefined1 *)(param_1 + 0xaa) = 0;
  *(byte *)(param_1 + 0x88) = param_2;
  *(undefined1 *)(param_1 + 0xa9) = 1;
  return;
}


// ===== fwobj_base_ctor @ 201604f4 (88 bytes)

/* base update-object constructor, vtable 0x2042807C */

int fwobj_base_ctor(void *param_1)

{
  int iVar1;
  
  *(undefined **)param_1 = &DAT_2042807c;
                    /* memcpy of 10 bytes, returns dst [doc] */
  iVar1 = copy10((int)param_1 + 4,&DAT_20428430);
  iVar1 = FUN_20160c5c(iVar1 + 10,"-----");
  iVar1 = copy10(iVar1 + 0x1e,&DAT_20428430);
                    /* memcpy of 0x20 bytes, returns dst [doc] */
  iVar1 = copy32(iVar1 + 0xb,&DAT_20428430);
                    /* memcpy of 0x30 bytes, returns dst [doc] */
  iVar1 = copy48(iVar1 + 0x21,&DAT_20428430);
  iVar1 = copy32(iVar1 + 0x31,&DAT_20428430);
  return iVar1 + -0x89;
}


// ===== fwname_pattern_init @ 20160558 (80 bytes)

/* builds the name pattern (prefix, "NNNN", suffix) */

void fwname_pattern_init(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  param_1[1] = param_2;
  param_1[2] = param_3;
                    /* Word-at-a-time string length [doc] */
  iVar1 = strlen(param_2);
  param_1[3] = iVar1;
  iVar1 = strlen(param_3);
  param_1[5] = iVar1;
  iVar1 = strlen(&DAT_204281f5);
  param_1[4] = iVar1 + param_1[3];
  *param_1 = iVar1 + param_1[3] + param_1[5];
  return;
}


// ===== fwobj_main_run @ 201605ac (244 bytes)

/* vtbl[0]: CRC check, then RX boot mode entry + rx_boot_program */

undefined4 fwobj_main_run(int param_1,uint param_2,int param_3,int param_4)

{
  uint fs_fopen_ret;
  undefined4 uVar1;
  uint sfl_read_header_ret;
  int iVar2;
  int local_18;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  local_18 = param_4;
  fs_fopen_ret = fs_fopen(param_2,0x204281fa);
  if (fs_fopen_ret == 0) {
    uVar1 = 1;
  }
  else {
                    /* progress percent 0x20800364 [doc, inference] */
    progress_set(5);
    itron_rot_rdq(0);
    itron_get_pri(0,&local_18);
    local_18 = local_18 + -1;
    itron_chg_pri(0);
    sfl_read_header_ret = sfl_read_header(fs_fopen_ret,0);
    itron_chg_pri(0);
    if (param_3 == 0) {
      fs_fclose(fs_fopen_ret);
      if (sfl_read_header_ret != 0) {
        return 2;
      }
    }
    else {
      mainlink_rx_ctrl(1);
      gpio_rx_reset(0);
      gpio_rx_update_b(1);
      itron_dly_tsk(5);
      gpio_rx_reset(1);
      itron_dly_tsk(0x28);
      iVar2 = rx_boot_program(fs_fopen_ret,1);
      fs_fclose(fs_fopen_ret);
      if (iVar2 == 0) {
        return 3;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fwobj_main_ctor @ 201606a4 (20 bytes)

/* MAIN object, vtable 0x20428088 */

uint fwobj_main_ctor(uint param_1)

{
  undefined4 *fwobj_base_ctor_ret;
  
                    /* base update-object constructor, vtable 0x2042807C [doc, inference] */
  fwobj_base_ctor_ret = (undefined4 *)fwobj_base_ctor((void *)param_1);
  *fwobj_base_ctor_ret = &DAT_20428088;
  return (uint)fwobj_base_ctor_ret;
}


// ===== fwobj_ifdsp_run @ 201606bc (264 bytes)

/* vtbl[0]: CRC check, then dsp_isp_program */

undefined4 fwobj_ifdsp_run(int param_1,uint param_2,int param_3)

{
  uint fs_fopen_ret;
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  fs_fopen_ret = fs_fopen(param_2,0x204281fd);
  if (fs_fopen_ret == 0) {
    uVar1 = 1;
  }
  else {
                    /* progress percent 0x20800364 [doc, inference] */
    progress_set(5);
    itron_rot_rdq(0);
    itron_get_pri(0,&stack0xffffffd8);
    itron_chg_pri(0);
    uVar2 = sfl_read_header(fs_fopen_ret,0);
    itron_chg_pri(0);
    if (param_3 == 0) {
      fs_fclose(fs_fopen_ret);
      if (uVar2 != 0) {
        return 2;
      }
    }
    else {
      gpio_p7_9_11(1);
      gpio_rx_reset(1);
      uVar2 = dsp_isp_program(fs_fopen_ret,1,0,0,(uint)*(byte *)(param_1 + 0xab));
      fs_fclose(fs_fopen_ret);
      if (uVar2 == 0) {
        return 3;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fwobj_ifdsp_ctor @ 201607c8 (28 bytes)

/* IFDSP object, vtable 0x20428094, +0xAB flag */

uint fwobj_ifdsp_ctor(uint param_1,byte param_2)

{
  undefined4 *fwobj_base_ctor_ret;
  
                    /* base update-object constructor, vtable 0x2042807C [doc, inference] */
  fwobj_base_ctor_ret = (undefined4 *)fwobj_base_ctor((void *)param_1);
  *fwobj_base_ctor_ret = &DAT_20428094;
  *(byte *)((int)fwobj_base_ctor_ret + 0xab) = param_2;
  return (uint)fwobj_base_ctor_ret;
}


// ===== fwobj_display_run @ 201607e8 (1032 bytes)

/* vtbl[0]: CRC check, then decoded write to the other bank (or loader) + flag */

undefined4 fwobj_display_run(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint spiflash_write_ret;
  uint *puVar7;
  uint uVar8;
  uint *unaff_r10;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 auStack_d0 [68];
  undefined4 local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  undefined1 auStack_70 [4];
  uint local_6c;
  undefined1 auStack_68 [24];
  uint local_50;
  uint local_4c;
  undefined1 auStack_48 [8];
  uint local_40;
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [12];
  
  bVar1 = false;
  __aeabi_memclr4(auStack_d0,0x44);
  if (param_2 == 0) {
    param_2 = param_1 + 0x58;
  }
  local_78 = fs_fopen(param_2,0x20428200);
  if (local_78 == 0) {
    return 1;
  }
  itron_get_pri(0,&local_74);
  local_74 = local_74 + -1;
  itron_chg_pri(0);
  uVar2 = sfl_read_header(local_78,(int)auStack_d0);
  itron_chg_pri(0);
  if (DAT_20800181 == ':') {
    unaff_r10 = (uint *)&DAT_20428203;
    iVar3 = strstr(auStack_d0,&DAT_20428203);
    if (iVar3 != 0) {
                    /* Word-at-a-time string length [doc] */
      iVar4 = strlen(&DAT_20428203);
      iVar3 = iVar3 + iVar4;
      *(undefined1 *)(iVar3 + 8) = 0;
      iVar4 = memcmp("#UP0    ",iVar3,8);
      if (iVar4 == 0) {
                    /* memcpy of 10 bytes, returns dst [doc] */
        uVar5 = copy10(auStack_3c,iVar3);
        memcpy(param_1 + 4,uVar5,10);
        uVar5 = copy10(auStack_30,&DAT_20428210);
        memcpy(param_1 + 0x2c,uVar5,10);
        bVar1 = true;
      }
    }
  }
  if (param_3 == 0) {
    fs_fclose(local_78);
    if (uVar2 == 0) {
      return 0;
    }
    return 2;
  }
  uVar2 = mainlink_fw_mode_cmd('\x03');
  if (uVar2 == 0) {
    return 3;
  }
  gpio_p7_9_11(1);
  gpio_rx_reset(1);
  gpio_rx_update_off(1);
  local_50 = work_buf_get(0x100);
  progress_range_init(auStack_70,5,0x1e);
  uVar2 = 0;
  iVar3 = 0;
  fs_fsize(local_78,&local_40);
  if (local_40 < 0x242) {
    return 3;
  }
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_74 = local_40 - 0x240;
  if (g_bootinfo.bank == 1) {
    puVar7 = &g_bootinfo.bank2_flag;
    unaff_r10 = &g_bootinfo.bank1_flag;
  }
  else {
    puVar7 = &g_bootinfo.bank1_flag;
  }
  uVar8 = puVar7[1];
  if (g_bootinfo.bank != 1) {
    unaff_r10 = &g_bootinfo.bank2_flag;
  }
  sfl_stream_init(auStack_68,local_78,0,1);
                    /* maps a fraction into the range [doc, inference] */
  uVar6 = progress_scale(auStack_70);
                    /* progress percent 0x20800364 [doc, inference] */
  progress_set(uVar6);
  if (g_bootinfo.mode == 2) {
    bVar1 = true;
LAB_201609ec:
    uVar8 = 0;
    uVar6 = spiflash_erase(0,0x3c0000,0x14);
    if (uVar6 != 0) goto LAB_20160ac8;
    uVar6 = spiflash_erase((int)auStack_70,0,local_74);
  }
  else {
    if (bVar1) goto LAB_201609ec;
    uVar6 = spiflash_erase(0,*puVar7,0x14);
    if (uVar6 != 0) goto LAB_20160ac8;
    uVar6 = spiflash_erase((int)auStack_70,puVar7[1],local_74);
  }
  if (uVar6 == 0) {
    progress_range_init(auStack_48,local_6c,99);
    local_4c = 0xffffffff;
                    /* reflected poly 0xEDB88320 [doc, inference] */
    crc32_make_table();
    while( true ) {
      uVar6 = sfl_stream_read(local_50,1,0x100,(int)auStack_68);
      if (uVar6 == 0) {
        progress_set(100);
        fs_fclose(local_78);
        if (local_74 != iVar3) {
          return 3;
        }
        local_8c = 0x11111111;
        local_7c = ~local_4c;
        local_88 = local_74;
        if (bVar1) {
          uVar2 = spiflash_write(0x3c0000,(uint)&local_8c,0x14);
        }
        else {
          uVar2 = spiflash_write(*puVar7,(uint)&local_8c,0x14);
          if (uVar2 != 0) {
            return 3;
          }
          uVar2 = spiflash_erase(0,*unaff_r10,0x14);
        }
        if (uVar2 == 0) {
          uVar2 = mainlink_fw_mode_cmd(-0x7d);
          if (uVar2 != 0) {
            return 0;
          }
          return 3;
        }
        return 3;
      }
      spiflash_write_ret = spiflash_write(uVar8,local_50,uVar6);
      if (spiflash_write_ret != 0) break;
      local_4c = crc32_update(local_4c,uVar6,local_50);
      iVar3 = iVar3 + uVar6;
      uVar8 = uVar8 + 0x100;
      uVar9 = __aeabi_ui2d(local_74);
      uVar10 = __aeabi_ui2d(iVar3);
      uVar9 = __aeabi_ddiv((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar9,
                           (int)((ulonglong)uVar9 >> 0x20));
      uVar5 = (undefined4)((ulonglong)uVar9 >> 0x20);
      uVar6 = progress_scale(auStack_48,uVar5,(int)uVar9,uVar5);
      progress_set(uVar6);
      if ((uVar2 & 0xf) == 0) {
        itron_rot_rdq(0);
      }
      uVar2 = uVar2 + 1;
    }
  }
LAB_20160ac8:
  fs_fclose(local_78);
  return 3;
}


// ===== fwobj_display_ctor @ 20160c10 (20 bytes)

/* DISPLAY object, vtable 0x204280A0 */

uint fwobj_display_ctor(uint param_1)

{
  undefined4 *fwobj_base_ctor_ret;
  
                    /* base update-object constructor, vtable 0x2042807C [doc, inference] */
  fwobj_base_ctor_ret = (undefined4 *)fwobj_base_ctor((void *)param_1);
  *fwobj_base_ctor_ret = &DAT_204280a0;
  return (uint)fwobj_base_ctor_ret;
}


// ===== FUN_20160c28 @ 20160c28 (52 bytes)

void FUN_20160c28(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = 0x2d;
  param_1[3] = param_2[2];
  param_1[4] = param_2[3];
  param_1[5] = 0;
  return;
}


// ===== FUN_20160c5c @ 20160c5c (20 bytes)

undefined4 FUN_20160c5c(undefined4 param_1)

{
  FUN_20160c28();
  return param_1;
}


// ===== afscope_map0_init @ 20160c70 (124 bytes)

/* Map 0 (obj +0x000): levels 0x81..0xFA -> (i - 0x81) * 0.3223 + 0.99 pixels, below 0, from 0xFB on
   0x27 (39, the AF-FFT spectrum height of gui.md) [fact] */

void afscope_map0_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    *(undefined1 *)(param_1 + iVar1) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  iVar1 = 0x81;
  do {
    if (iVar1 + -0x81 < 1) {
      *(undefined1 *)(param_1 + iVar1) = 0;
    }
    else {
      iVar2 = (iVar1 + -0x81) * 0xc97 + 0x26ac;
      *(char *)(param_1 + iVar1) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xfb);
  iVar1 = 0xfb;
  do {
    *(undefined1 *)(param_1 + iVar1) = 0x27;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return;
}


// ===== afscope_map2_init @ 20160cf0 (92 bytes)

/* Map 2 (obj +0x200): level i -> i * 0.3098 + 0.85 for 1..255 [fact] */

void afscope_map2_init(int param_1)

{
  int i;
  int iVar1;
  
  i = 0;
  do {
    *(undefined1 *)(param_1 + i + 0x200) = 0;
    while( true ) {
      i = i + 1;
      if (0xff < i) {
        return;
      }
      if (i < 1) break;
      iVar1 = i * 0xc1a + 0x2134;
      *(char *)(param_1 + i + 0x200) =
           ((char)(iVar1 / 10000) + (char)(iVar1 >> 0x1f)) -
           (char)((longlong)iVar1 * 0x68db8bad >> 0x3f);
    }
  } while( true );
}


// ===== afscope_map1_init @ 20160d50 (144 bytes)

/* Map 1 (obj +0x100): the same curve as map 0 [fact] */

void afscope_map1_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x100) = 0;
  } while (iVar1 < 0x100);
  iVar1 = 0x81;
  do {
    if (iVar1 + -0x81 < 1) {
      *(undefined1 *)(param_1 + iVar1 + 0x100) = 0;
    }
    else {
      iVar2 = (iVar1 + -0x81) * 0xc97 + 0x26ac;
      *(char *)(param_1 + iVar1 + 0x100) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xfb);
  iVar1 = 0xfb;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x100) = 0x27;
  } while (iVar1 < 0x100);
  return;
}


// ===== afscope_map3_init @ 20160de4 (92 bytes)

/* Map 3 (obj +0x300): the same curve as map 2 [fact] */

void afscope_map3_init(int param_1)

{
  int i;
  int iVar1;
  
  i = 0;
  do {
    *(undefined1 *)(param_1 + i + 0x300) = 0;
    while( true ) {
      i = i + 1;
      if (0xff < i) {
        return;
      }
      if (i < 1) break;
      iVar1 = i * 0xc1a + 0x2134;
      *(char *)(param_1 + i + 0x300) =
           ((char)(iVar1 / 10000) + (char)(iVar1 >> 0x1f)) -
           (char)((longlong)iVar1 * 0x68db8bad >> 0x3f);
    }
  } while( true );
}


// ===== afscope_map4_init @ 20160e44 (144 bytes)

/* Map 4 (obj +0x400): levels 0x81..0xFA -> (i - 0x81) * 0.3636 + 0.99, from 0xFB on 0x2C (44, the
   bar height affft_bins_get returns) [fact] */

void afscope_map4_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x400) = 0;
  } while (iVar1 < 0x100);
  iVar1 = 0x81;
  do {
    if (iVar1 + -0x81 < 1) {
      *(undefined1 *)(param_1 + iVar1 + 0x400) = 0;
    }
    else {
      iVar2 = (iVar1 + -0x81) * 0xe34 + 0x26ac;
      *(char *)(param_1 + iVar1 + 0x400) =
           ((char)(iVar2 / 10000) + (char)(iVar2 >> 0x1f)) -
           (char)((longlong)iVar2 * 0x68db8bad >> 0x3f);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xfb);
  iVar1 = 0xfb;
  do {
    iVar2 = param_1 + iVar1;
    iVar1 = iVar1 + 1;
    *(undefined1 *)(iVar2 + 0x400) = 0x2c;
  } while (iVar1 < 0x100);
  return;
}


// ===== mainlink_send_sd_absent @ 20160ed8 (52 bytes)

/* E2 frame with byte 1 = 0 (SD card not present, mainlink.md); the SD menu screens send it when
   sd_state_bit7 reads 0 [inference] */

void mainlink_send_sd_absent(void)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  local_10 = 0xe2;
  mainlink_queue_frame(&local_10,6);
  return;
}


// ===== FUN_20161bb0 @ 20161bb0 (52 bytes)

void FUN_20161bb0(void)

{
  undefined1 auStack_10 [12];
  
  touch_set_up();
  mouse_set_up();
  mainlink_send_touch_key(0,0xffff);
  pointer_get_event(auStack_10,1);
  return;
}


// ===== FUN_20162b50 @ 20162b50 (176 bytes)

void FUN_20162b50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0xf;
  } while (iVar2 < 0x100);
  iVar2 = 0x81;
  do {
    if (iVar2 + -0x81 < 1) {
      *(undefined2 *)(param_1 + iVar2 * 2) = 0xf;
    }
    else {
      *(undefined2 *)(param_1 + iVar2 * 2) =
           *(undefined2 *)(&UNK_20166da8 + (0x20 - ((iVar2 + -0x81) * 0xa54 + 0x26ac) / 10000) * 2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xfb);
  iVar2 = 0xfb;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0xffff;
  } while (iVar2 < 0x100);
  return;
}


// ===== FUN_20162c10 @ 20162c10 (16 bytes)

void FUN_20162c10(undefined2 *param_1)

{
  *param_1 = 0;
  return;
}


// ===== FUN_20162c18 @ 20162c18 (8 bytes)

void FUN_20162c18(undefined4 param_1)

{
  FUN_2016440c(param_1,0);
  return;
}


// ===== FUN_20162c20 @ 20162c20 (8 bytes)

void FUN_20162c20(undefined4 param_1)

{
  FUN_2016440c(param_1,0);
  return;
}


// ===== FUN_20162c28 @ 20162c28 (212 bytes)

void FUN_20162c28(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulonglong __aeabi_idivmod_ret;
  
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)(param_1 + iVar1) = 0;
  } while (iVar3 < 0x100);
  uVar6 = (uint)*(byte *)(param_1 + 0x200);
  uVar4 = (uint)*(byte *)(param_1 + 0x201);
  iVar3 = *(int *)(param_2 + 4);
  if (uVar6 <= uVar4) {
    do {
      bVar2 = *(byte *)(param_1 + 0x200);
      __aeabi_idivmod_ret = __aeabi_idivmod(640000,(uVar4 - bVar2) + 1);
      iVar5 = uVar6 - bVar2;
      iVar1 = uVar6 * 2;
      uVar6 = uVar6 + 1;
      *(undefined2 *)(param_1 + iVar1) =
           *(undefined2 *)
            (iVar3 + ((uint)*(ushort *)(param_2 + 2) -
                     ((int)__aeabi_idivmod_ret * (iVar5 + 1) + 0x26ac) / 10000) * 2);
      uVar4 = (uint)*(byte *)(param_1 + 0x201);
    } while ((int)uVar6 <= (int)uVar4);
  }
  uVar4 = uVar4 + 1;
  if (uVar4 < 0x100) {
    do {
      iVar1 = uVar4 * 2;
      uVar4 = uVar4 + 1;
      *(undefined2 *)(param_1 + iVar1) =
           *(undefined2 *)(iVar3 + (uint)*(ushort *)(param_2 + 2) * 2 + -0x80);
    } while ((int)uVar4 < 0x100);
  }
  return;
}


// ===== cpp_task_thunk @ 20162d04 (12 bytes)

/* task entry for C++ objects: exinf = object, calls obj->vtbl[0] */

void cpp_task_thunk(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x20162d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)**(undefined4 **)param_1)();
  return;
}


// ===== os_mbx_create_fifo @ 20162d10 (40 bytes)

/* itron_acre_mbx with a zeroed T_CMBX (mbxatr 0, maxmpri 1); used by mainlink_tx_init,
   uart4_tx_init, mainlink_disp_init, mouse_cursor_obj_init [fact] */

void os_mbx_create_fifo(void)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = 0;
  uStack_14 = 1;
  uStack_10 = 0;
  uStack_c = 0;
  itron_acre_mbx(0,&local_18);
  return;
}


// ===== os_mbx_send @ 20162d3c (12 bytes)

/* (this, mbxid, msg): itron_snd_mbx(mbxid, msg) [fact] */

void os_mbx_send(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  itron_snd_mbx(param_2,param_3);
  return;
}


// ===== scope_obj_set_2e04 @ 20162d48 (12 bytes)

/* [fact] (obj, v): strb r1, [r0, #0x2E04]; Ghidra FUN_20162d48 (T24 USB track) */

void scope_obj_set_2e04(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x2e04) = param_2;
  return;
}


// ===== scope_obj_apply_2e00 @ 20162d54 (20 bytes)

/* [fact] (obj): FUN_20157634(obj + 0x2D00, byte +0x2E04, obj + 0x2E00); tail call of
   scope_obj_set_2e00; new entry (T24 USB track) */

void scope_obj_apply_2e00(int param_1)

{
  FUN_20157634(param_1 + 0x2d00,*(undefined1 *)(param_1 + 0x2e04),param_1 + 0x2e00);
  return;
}


// ===== scope_obj_apply_2e02 @ 20162d68 (108 bytes)

/* [fact] (obj, v): tail call of scope_obj_set_2e02 with the halfword it stored at +0x2E02; new
   entry (T24 USB track) */

void scope_obj_apply_2e02(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_20157634(param_1 + iVar1 * 0x100,*(undefined2 *)(DAT_20450278 + iVar1 * 2),param_1 + 0x2e02)
    ;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1e);
  iVar1 = 0;
  do {
    FUN_20157634(param_1 + iVar1 * 0x100 + 0x1e00,*(undefined2 *)(DAT_2045027c + iVar1 * 2),
                 param_1 + 0x2e02);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xf);
  return;
}


// ===== scif_rxi_isr @ 20162dd8 (312 bytes)

/* 1 byte -> RX ring, set_flg(obj+0x818, 1) */

void scif_rxi_isr(scif_uart *uart)

{
  scif_regs *p_scif_regs;
  
  uart->rxi_count = uart->rxi_count + 1;
  p_scif_regs = uart->regs;
  if ((p_scif_regs->scfsr & 0xff9d) != 0) {
    uart->rx_errors = uart->rx_errors + 1;
  }
  if ((p_scif_regs->scfsr & 2) != 0) {
    if (((uart->rx_wr < uart->rx_rd) || (0x3fe < (int)((uint)uart->rx_wr - (uint)uart->rx_rd))) &&
       ((uart->rx_rd <= uart->rx_wr || ((int)((uint)uart->rx_rd - (uint)uart->rx_wr) < 2)))) {
      p_scif_regs->scfsr = p_scif_regs->scfsr & 0xfffd;
      uart->rx_count = uart->rx_count + 1;
      uart->rx_overflow = uart->rx_overflow + 1;
      return;
    }
    uart->rx_buf[uart->rx_wr] = p_scif_regs->scfrdr;
    DataMemoryBarrier(2);
    uart->rx_wr = uart->rx_wr + 1 & 0x3ff;
    uart->regs->scfsr = uart->regs->scfsr & 0xfffd;
    if (uart->rx_flg != 0) {
      gic_disable_irq(uart->rxi_isr->intno);
    }
    itron_set_flg(uart->rx_flg,1);
    uart->rx_count = uart->rx_count + 1;
    pmu_cycle_stamp(&uart->rx_time);
    return;
  }
  uart->rxi_no_data = uart->rxi_no_data + 1;
  return;
}


// ===== scif_txi_isr @ 20162f10 (156 bytes)

/* TX ring -> SCFTDR */

void scif_txi_isr(scif_uart *uart)

{
  scif_regs *p_scif_regs;
  
  uart->txi_count = uart->txi_count + 1;
  p_scif_regs = uart->regs;
  if ((p_scif_regs->scfsr & 0x20) == 0) {
    uart->txi_not_ready = uart->txi_not_ready + 1;
    return;
  }
  if (uart->tx_rd != uart->tx_wr) {
    p_scif_regs->scftdr = uart->tx_buf[uart->tx_rd];
    DataMemoryBarrier(2);
    uart->tx_rd = uart->tx_rd + 1 & 0x3ff;
    uart->regs->scfsr = uart->regs->scfsr & 0xff9f;
    uart->tx_count = uart->tx_count + 1;
    pmu_cycle_stamp(&uart->tx_time);
    return;
  }
  p_scif_regs->scscr = p_scif_regs->scscr & 0xff7f;
  return;
}


// ===== uart_obj_init @ 20162fac (104 bytes)

uint uart_obj_init(scif_uart *uart,scif_regs *regs,t_cisr *rxi,t_cisr *txi,uint flg)

{
  uint uVar1;
  
  if (uart->regs == (scif_regs *)0x0) {
    uart->regs = regs;
    uart->rx_flg = flg;
    uart->rxi_isr = rxi;
    uart->txi_isr = txi;
    uVar1 = itron_acre_isr(0,(int)txi);
    if (((int)uVar1 < 1) || (uVar1 = itron_acre_isr(0,(int)uart->rxi_isr), (int)uVar1 < 1)) {
      return 0xffffffff;
    }
  }
  else {
    uart->rx_flg = flg;
  }
  return 0;
}


// ===== scif_irq_off @ 20163014 (36 bytes)

void scif_irq_off(scif_uart *uart)

{
  gic_disable_irq(uart->txi_isr->intno);
  gic_disable_irq(uart->rxi_isr->intno);
  return;
}


// ===== scif_read @ 20163038 (96 bytes)

/* non-blocking read from the 1 KB RX ring */

int scif_read(scif_uart *uart,byte *buf,int n)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0;
  while ((bVar2 = n != 0, n = n + -1, bVar2 && (uart->rx_wr != uart->rx_rd))) {
    *buf = uart->rx_buf[uart->rx_rd];
    DataMemoryBarrier(2);
    uart->rx_rd = uart->rx_rd + 1 & 0x3ff;
    iVar1 = iVar1 + 1;
    buf = buf + 1;
  }
  gic_enable_irq(uart->rxi_isr->intno);
  return iVar1;
}


// ===== scif_start @ 20163098 (52 bytes)

/* scif_open + enable RXI/TXI in the GIC */

void scif_start(scif_uart *uart,uint baud,int bits,int parity,uint stop)

{
  scif_open((int)uart,baud,bits,parity,stop);
  gic_enable_irq(uart->txi_isr->intno);
  gic_enable_irq(uart->rxi_isr->intno);
  return;
}


// ===== scif_open @ 201630cc (324 bytes)

/* (baud, bits, parity, stop): SCSMR, SCBRR (0x16 + SEMR 0x81 for 345600), FIFO reset */

void scif_open(int param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  char cVar1;
  ushort uVar2;
  
  uVar2 = 0;
  if (param_3 == 7) {
    uVar2 = 0x40;
  }
  if (param_4 != 0) {
    if (param_4 == 1) {
      uVar2 = uVar2 | 0x20;
    }
    else if (param_4 == 2) {
      uVar2 = uVar2 | 0x30;
    }
  }
  if (param_5 != 1) {
    uVar2 = uVar2 | 8;
  }
  if (param_2 < 0x54600) {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
    cVar1 = __aeabi_uidivmod(64000000,param_2 << 5);
    cVar1 = cVar1 + -1;
  }
  else {
    cVar1 = '\x16';
  }
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 0x40e) = 0;
  *(undefined2 *)(param_1 + 0x40c) = 0;
  *(undefined4 *)(param_1 + 0x81c) = 0;
  *(undefined4 *)(param_1 + 0x820) = 0;
  *(undefined4 *)(param_1 + 0x828) = 0;
  *(undefined4 *)(param_1 + 0x82c) = 0;
  *(undefined4 *)(param_1 + 0x830) = 0;
  *(undefined4 *)(param_1 + 0x834) = 0;
  *(undefined4 *)(param_1 + 0x838) = 0;
  *(undefined2 *)(*(int *)(param_1 + 4) + 8) = 0;
  *(ushort *)(*(int *)(param_1 + 4) + 0x18) = *(ushort *)(*(int *)(param_1 + 4) + 0x18) | 6;
  *(ushort *)(*(int *)(param_1 + 4) + 0x10) = *(ushort *)(*(int *)(param_1 + 4) + 0x10) & 0xff6e;
  *(undefined2 *)(*(int *)(param_1 + 4) + 0x24) = 0;
  *(undefined2 *)(*(int *)(param_1 + 4) + 8) = 0;
  **(ushort **)(param_1 + 4) = uVar2;
  *(char *)(*(int *)(param_1 + 4) + 4) = cVar1;
  if (param_2 < 0x54600) {
    *(undefined2 *)(*(int *)(param_1 + 4) + 0x28) = 0;
  }
  else {
    *(ushort *)(*(int *)(param_1 + 4) + 0x28) = *(ushort *)(*(int *)(param_1 + 4) + 0x28) | 0x81;
  }
  if ((param_5 & 0x80) != 0) {
    *(ushort *)(*(int *)(param_1 + 4) + 0x18) = *(ushort *)(*(int *)(param_1 + 4) + 0x18) | 1;
  }
  *(ushort *)(*(int *)(param_1 + 4) + 0x18) = *(ushort *)(*(int *)(param_1 + 4) + 0x18) & 0xfff9;
  *(ushort *)(*(int *)(param_1 + 4) + 8) = *(ushort *)(*(int *)(param_1 + 4) + 8) | 0xf8;
  return;
}


// ===== scif_read_timeout @ 20163218 (104 bytes)

/* retries every 1 ms up to n times */

int scif_read_timeout(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int i;
  
  iVar2 = 0;
  i = 0;
  while( true ) {
    i = i + 1;
    iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_2 + iVar2,param_3 - iVar2);
    iVar2 = iVar2 + iVar1;
    if (iVar2 == param_3) {
      return param_3;
    }
    if (param_4 < i) break;
    itron_dly_tsk(1);
  }
  return -1;
}


// ===== scif_flush @ 20163280 (88 bytes)

uint scif_flush(scif_uart *uart)

{
  gic_disable_irq(uart->txi_isr->intno);
  gic_disable_irq(uart->rxi_isr->intno);
  uart->rx_wr = 0;
  uart->rx_rd = 0;
  uart->tx_wr = 0;
  uart->tx_rd = 0;
  gic_enable_irq(uart->txi_isr->intno);
  gic_enable_irq(uart->rxi_isr->intno);
  return 0;
}


// ===== scif_write @ 201632d8 (136 bytes)

/* copy into the 1 KB TX ring, enable TIE */

uint scif_write(scif_uart *uart,byte *buf,uint n)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)uart->tx_wr;
  uVar3 = (uint)uart->tx_rd;
  if (uVar2 < uVar3) {
    uVar3 = (uVar3 - uVar2) - 1;
  }
  else {
    uVar3 = 0x3ff - (uVar2 - uVar3);
  }
  uVar1 = n;
  if (uVar3 < n) {
    n = 0;
  }
  else {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      uart->tx_buf[uVar2] = *buf;
      uVar2 = uVar2 + 1 & 0x3ff;
      buf = buf + 1;
    }
    uart->tx_wr = (ushort)uVar2;
    DataMemoryBarrier(2);
    uart->regs->scscr = uart->regs->scscr | 0x80;
  }
  return n;
}


// ===== uart_obj_ctor @ 20163360 (12 bytes)

/* (obj): sets the vtable pointer 0x2042803C (first method uart_obj_init) [fact] */

void uart_obj_ctor(undefined4 *param_1)

{
  *param_1 = &PTR_uart_obj_init_2042803c;
  return;
}


// ===== FUN_201633a0 @ 201633a0 (108 bytes)

void FUN_201633a0(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_4 == 0) {
    iVar2 = 0;
    do {
      *(undefined1 *)(param_2 + iVar2) =
           *(undefined1 *)(param_1 + (*(byte *)(param_3 + iVar2) ^ param_5));
      iVar2 = iVar2 + 1;
    } while (iVar2 < 800);
    return;
  }
  iVar2 = 0;
  do {
    iVar1 = clamp_add_u8(*(byte *)(param_3 + iVar2) ^ param_5,param_4);
    *(undefined1 *)(param_2 + iVar2) = *(undefined1 *)(param_1 + iVar1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 800);
  return;
}


// ===== scope_obj_line_markers @ 2016340c (24 bytes)

/* [fact] (obj, i): obj + 0x100E4 + 0x54 * i; tail call of scope3d_line_markers; new entry (T24 USB
   track) */

int scope_obj_line_markers(int param_1,int param_2)

{
  return param_1 + param_2 * 0x54 + 0x100e4;
}


// ===== FUN_20163428 @ 20163428 (136 bytes)

undefined4 FUN_20163428(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1 + param_2 * 800 + 0xa323;
  param_1 = param_1 + param_2 * 0x100;
  if (param_3 == 8) {
    FUN_201633a0(param_1,param_4,iVar2,param_5);
    uVar1 = FUN_20164674(0x20470330);
    return uVar1;
  }
  if (param_3 == 9) {
    FUN_201633a0(param_1 + 0x1e00,param_4,iVar2,param_5);
    uVar1 = FUN_20164654(0x20473b7c);
    return uVar1;
  }
  iVar2 = 0;
  do {
    iVar2 = iVar2 + 1;
  } while (iVar2 < 800);
  return 0;
}


// ===== scope_obj_vscale @ 201634b8 (52 bytes)

/* [fact] (obj, i, mode): halfword i of *0x20450278 (mode 8) or *0x2045027C (mode 9), else 0; tail
   call of scope3d_vscale; new entry (T24 USB track) */

undefined2 scope_obj_vscale(undefined4 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  
  if (param_3 == 8) {
    return *(undefined2 *)(DAT_20450278 + param_2 * 2);
  }
  if (param_3 == 9) {
    uVar1 = *(undefined2 *)(DAT_2045027c + param_2 * 2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== scope_obj_wf_row_addr @ 201634f0 (100 bytes)

/* [fact] (obj, i): obj + 0x1B130 + bank * 0x33F40 + 0x640 * ring133_offset(index of the selected
   bank, ~i); tail call of scope_wf_row_addr; new entry (T24 USB track) */

int scope_obj_wf_row_addr(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = ring133_offset(param_1 + 0x82fb4,~param_2);
  if (DAT_20450280 == 1) {
    iVar1 = ring133_offset(param_1 + 0x82fb0,~param_2);
  }
  return param_1 + DAT_20450280 * 0x33f40 + iVar1 * 0x640 + 0x1b130;
}


// ===== scope_obj_line_offset @ 20163564 (68 bytes)

/* [fact] (obj, i, mode, expanded): halfword i of the ROM scale table of mode 8 / 9 for the layout,
   else 0; tail call of scope3d_line_offset; new entry (T24 USB track) */

undefined2 scope_obj_line_offset(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  if (param_3 == 8) {
    if (param_4 == 0) {
      puVar2 = (undefined2 *)&DAT_203d99dc;
    }
    else {
      puVar2 = &DAT_203d9a18;
    }
    return puVar2[param_2];
  }
  if (param_3 == 9) {
    if (param_4 == 0) {
      puVar2 = (undefined2 *)&DAT_203d9a80;
    }
    else {
      puVar2 = &DAT_203d9a9e;
    }
    uVar1 = puVar2[param_2];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

