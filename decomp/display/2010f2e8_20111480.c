// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== sdmenu_select @ 2010f2e8 (24 bytes)

void sdmenu_select(byte param_1,uint param_2,byte param_3)

{
  DAT_2080019d = param_1;
  DAT_2080019e = param_3;
  memcpy(&DAT_208193a6,param_2,0x10);
  return;
}


// ===== sdmenu_select_load @ 2010f300 (92 bytes)

void sdmenu_select_load(int param_1,int param_2,int param_3,byte param_4)

{
  DAT_2080019d = (undefined1)param_1;
  DAT_2080019e = param_4;
  memcpy(&DAT_208193a6,param_2 + param_3 * 0x10,0x10);
  if (param_1 != 0) {
    if (param_1 == 1) {
      DAT_208116a0 = 0x44;
      DAT_208116a2 = 32000;
    }
    return;
  }
  DAT_208116a0 = 0x42;
  DAT_208116a2 = 32000;
  return;
}


// ===== sd_present @ 2010f35c (20 bytes)

bool sd_present(void)

{
  int iVar1;
  
  iVar1 = FUN_20103bc0();
  return iVar1 != 0;
}


// ===== sdmenu_write_dat @ 2010f370 (624 bytes)

/* 9 x 64-byte text lines ("MemList  n  CRC") + 0x7D10 encoded bytes */

undefined4
sdmenu_write_dat(uint param_1,int param_2,undefined4 param_3,uint param_4,uint param_5,
                undefined4 param_6)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint extraout_r1;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 auStack_78 [62];
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  uint local_34;
  int iStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  
  local_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  uStack_28 = param_4;
  __aeabi_memset(auStack_78,0x40,0x20);
  local_39 = 10;
  local_3a = 0xd;
  iVar6 = 0;
  uVar9 = __aeabi_i2d(param_5 + 0x240);
  uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar1 = (undefined4)uVar9;
  iVar7 = 0;
  do {
    iVar8 = iVar7;
    iVar7 = iVar8 + 0x40;
    uVar9 = __aeabi_i2d(iVar7);
    uVar9 = __aeabi_ddiv((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar3);
    uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
    uVar2 = progress_scale(param_6,uVar4,(int)uVar9,uVar4);
    progress_set(uVar2);
    itron_rot_rdq(0);
    uVar2 = fs_fwrite((uint)auStack_78,1,0x40,local_34);
    if (uVar2 < 0x40) {
      return 1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  local_38 = 0x139eeca6;
  crc32_make_table();
  uVar2 = crc32_update(0xffffffff,param_5,param_4);
  uVar2 = crc32_update(uVar2,4,(uint)&local_38);
  if (param_2 == 0) {
    pcVar5 = "MemList";
  }
  else {
    pcVar5 = "Menu";
  }
  sprintf(auStack_78,"%s  %d  %08X",pcVar5,param_3,~uVar2);
  iVar7 = strlen(auStack_78);
  iVar8 = iVar8 + 0x80;
  auStack_78[iVar7] = 0x20;
  uVar9 = __aeabi_i2d(iVar8);
  uVar9 = __aeabi_ddiv((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar3);
  uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar2 = progress_scale(param_6,uVar4,(int)uVar9,uVar4);
  progress_set(uVar2);
  itron_rot_rdq(0);
  uVar2 = fs_fwrite((uint)auStack_78,1,0x40,local_34);
  if (0x3f < uVar2) {
    __aeabi_uidivmod(param_5,0x100);
    iVar7 = 0;
    if (param_5 >> 8 != 0) {
      do {
        iVar8 = iVar8 + 0x100;
        uVar9 = __aeabi_i2d(iVar8);
        uVar9 = __aeabi_ddiv((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar3);
        uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
        uVar2 = progress_scale(param_6,uVar4,(int)uVar9,uVar4);
        progress_set(uVar2);
        itron_rot_rdq(0);
        uVar2 = fs_fwrite(param_4,1,0x100,local_34);
        if ((int)uVar2 < 0x100) {
          return 2;
        }
        iVar7 = iVar7 + 1;
        param_4 = param_4 + 0x100;
      } while (iVar7 < (int)(param_5 >> 8));
    }
    if (extraout_r1 != 0) {
      uVar9 = __aeabi_i2d(iVar8 + extraout_r1);
      uVar9 = __aeabi_ddiv((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar3);
      uVar1 = (undefined4)((ulonglong)uVar9 >> 0x20);
      uVar2 = progress_scale(param_6,uVar1,(int)uVar9,uVar1);
      progress_set(uVar2);
      itron_rot_rdq(0);
      uVar2 = fs_fwrite(param_4,1,extraout_r1,local_34);
      if ((int)uVar2 < (int)extraout_r1) {
        return 2;
      }
    }
    return 0;
  }
  return 2;
}


// ===== sdmenu_save_file @ 2010f60c (488 bytes)

/* <dir>\<name>.dat, sfl_encode, salted CRC-32 */

int sdmenu_save_file(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 extraout_r1;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 auStack_50 [40];
  uint local_28;
  uint local_24;
  undefined1 auStack_20 [12];
  
  progress_range_init(&local_28,1,5);
  progress_set(local_28);
  iVar1 = FUN_2013fba0();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = fs_opendir(*(undefined4 *)(&DAT_208001ac + param_1 * 4));
  if (iVar1 == 0) {
    iVar1 = fs_opendir("I:\\FT-710");
    if (iVar1 == 0) {
      iVar1 = fs_mkdir("I:\\FT-710");
      if (iVar1 != 0) goto LAB_2010f7b8;
    }
    else {
      fs_closedir();
    }
    uVar5 = fs_mkdir(*(undefined4 *)(&DAT_208001ac + param_1 * 4));
    uVar4 = (undefined4)((ulonglong)uVar5 >> 0x20);
    if ((int)uVar5 != 0) goto LAB_2010f7b8;
  }
  else {
    fs_closedir();
    uVar4 = extraout_r1;
  }
  uVar2 = progress_scale(&local_28,uVar4,0,0x3fe00000);
  progress_set(uVar2);
  sprintf(auStack_50,"%s\\%s.dat",*(undefined4 *)(&DAT_208001ac + param_1 * 4),param_2);
  uVar2 = fs_fopen((uint)auStack_50,0x2010f804);
  if (uVar2 != 0) {
    gui_scope_draw_hold_set(1);
    iVar1 = work_buf_get(0x8350);
    __aeabi_memclr(iVar1 + 0x640,0x7d10);
    *(char *)(iVar1 + 0x640) = (char)param_1;
    *(char *)(iVar1 + 0x641) = (char)((uint)param_1 >> 8);
    *(char *)(iVar1 + 0x642) = (char)((uint)param_1 >> 0x10);
    *(char *)(iVar1 + 0x643) = (char)((uint)param_1 >> 0x18);
    *(char *)(iVar1 + 0x644) = (char)param_3;
    *(char *)(iVar1 + 0x645) = (char)(param_3 >> 8);
    *(char *)(iVar1 + 0x646) = (char)(param_3 >> 0x10);
    *(char *)(iVar1 + 0x647) = (char)(param_3 >> 0x18);
    memcpy(iVar1 + 0x650,&DAT_208116a6,32000);
    sfl_encode(0,iVar1 + 0x640,0x7d10);
    uVar3 = progress_scale(&local_28);
    progress_set(uVar3);
    progress_range_init(auStack_20,local_24,99);
    iVar1 = sdmenu_write_dat(uVar2,param_1,param_3,iVar1 + 0x640,0x7d10,auStack_20);
    scope3d_tables_init();
    gui_scope_draw_hold_set(0);
    if (iVar1 == 0) {
      FUN_2013fc4c(1);
      uVar3 = fs_fclose(uVar2);
      FUN_2013fc4c(0);
      progress_set(100);
    }
    else {
      uVar3 = fs_task_ctx_get();
      fs_fclose(uVar2);
    }
    return uVar3;
  }
LAB_2010f7b8:
  uVar2 = fs_task_ctx_get();
  return uVar2;
}


// ===== sdmenu_load_file @ 2010f81c (876 bytes)

/* RENAME (was sfl_load_file): loads a MemList/Menu .dat (size 0x7F50), checks CRC, type and model
   word */

undefined4 sdmenu_load_file(uint *param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auStack_1a8 [64];
  undefined1 local_168;
  undefined1 auStack_a8 [40];
  uint local_80;
  undefined1 *local_7c;
  undefined1 auStack_78 [52];
  int local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  byte *local_34;
  undefined4 local_30;
  uint local_2c;
  uint *local_28;
  
  local_28 = param_1;
  progress_set(*param_1);
  sprintf(auStack_a8,"%s\\%s.dat",*(undefined4 *)(&DAT_208001ac + (uint)DAT_2080019d * 4),
          &DAT_208193a6);
  if (DAT_2080019d < 2) {
    iVar3 = fs_stat(auStack_a8,auStack_78);
    if (iVar3 == 0) {
      if ((local_44 == 0x7f50) && (local_80 = fs_fopen((uint)auStack_a8,0x2010fb88), local_80 != 0))
      {
        iVar3 = 0;
        iVar9 = 0;
        local_7c = auStack_1a8;
        uVar11 = __aeabi_ui2d(0x7f50);
        uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
        do {
          iVar3 = iVar3 + 0x40;
          uVar12 = __aeabi_i2d(iVar3);
          uVar12 = __aeabi_ddiv((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,uVar7);
          uVar8 = (undefined4)((ulonglong)uVar12 >> 0x20);
          uVar4 = progress_scale(local_28,uVar8,(int)uVar12,uVar8);
          progress_set(uVar4);
          uVar4 = fs_fread((uint)auStack_1a8,1,0x40,local_80);
          if (uVar4 == 0) goto LAB_2010f9bc;
          itron_rot_rdq(0);
          iVar9 = iVar9 + 1;
        } while (iVar9 < 9);
        local_168 = 0;
        iVar9 = strlen(auStack_1a8);
        if ((((iVar9 == 0x40) && (iVar9 = strtok_r(auStack_1a8,0x2010fb8c,&local_7c), iVar9 != 0))
            && (iVar9 = strtok_r(local_7c,0x2010fb8c,&local_7c), iVar9 != 0)) &&
           (pbVar5 = (byte *)strtok_r(local_7c,0x2010fb8c,&local_7c), pbVar5 != (byte *)0x0)) {
          uVar2 = hex_parse(pbVar5,8,&local_34);
          local_2c = (uint)uVar2;
          if (local_34 != pbVar5) {
            local_40 = 0xffffffff;
            local_30 = 0x139eeca6;
            crc32_make_table();
            gui_scope_draw_hold_set(1);
            iVar9 = work_buf_get(0x8350);
            local_38 = 2;
            iVar10 = iVar9 + 0x640;
            local_3c = 0;
            while (uVar4 = fs_fread((uint)auStack_1a8,1,0x100,local_80), uVar4 != 0) {
              iVar3 = iVar3 + uVar4;
              uVar12 = __aeabi_i2d(iVar3);
              uVar12 = __aeabi_ddiv((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,uVar7);
              uVar8 = (undefined4)((ulonglong)uVar12 >> 0x20);
              uVar6 = progress_scale(local_28,uVar8,(int)uVar12,uVar8);
              progress_set(uVar6);
              itron_rot_rdq(0);
              local_40 = crc32_update(local_40,uVar4,(uint)auStack_1a8);
              bVar1 = sfl_decode(local_3c,(int)auStack_1a8,uVar4);
              local_3c = (uint)bVar1;
              memcpy(iVar10,auStack_1a8,uVar4);
              iVar10 = iVar10 + uVar4;
            }
            fs_fclose(local_80);
            uVar4 = crc32_update(local_40,4,(uint)&local_30);
            uVar6 = progress_scale(local_28);
            progress_set(uVar6);
            if ((local_2c == ~uVar4) && (*(uint *)(iVar9 + 0x640) == (uint)DAT_2080019d)) {
              if (*(uint *)(iVar9 + 0x644) == (uint)DAT_2080019e) {
                memcpy(&DAT_208116a6,iVar9 + 0x650,32000);
                DAT_208001a1 = 0;
                local_38 = 1;
              }
              else {
                DAT_208001a1 = 2;
              }
            }
            else {
              DAT_208001a1 = 1;
            }
            scope3d_tables_init();
            gui_scope_draw_hold_set(0);
            return local_38;
          }
        }
LAB_2010f9bc:
        DAT_208001a1 = 1;
        fs_fclose(local_80);
      }
      else {
        DAT_208001a1 = 1;
      }
    }
    else {
      DAT_208001a1 = 4;
    }
  }
  else {
    DAT_208001a1 = 4;
  }
  return 2;
}


// ===== sd_make_dirs @ 2010fb90 (276 bytes)

/* I:\FT-710\Capture, MemList, Menu, PlayList */

byte sd_make_dirs(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  FUN_20103bc8(1);
  itron_dly_tsk(0x14);
  uVar1 = sd_format('I');
  if ((uVar1 != 0) && (uVar2 = sd_card_detect(), uVar2 != 0)) {
    uVar1 = 0xffffffff;
    DAT_208001a2 = 5;
  }
  FUN_20103bc8(0);
  itron_dly_tsk(0x14);
  if (uVar1 == 0) {
    iVar3 = fs_mkdir("I:\\FT-710");
    if (iVar3 == 0) {
      iVar3 = fs_mkdir("I:\\FT-710\\Capture");
      if (iVar3 == 0) {
        iVar3 = fs_mkdir("I:\\FT-710\\MemList");
        if (iVar3 == 0) {
          iVar3 = fs_mkdir("I:\\FT-710\\Menu");
          if (iVar3 == 0) {
            iVar3 = fs_mkdir("I:\\FT-710\\PlayList");
            if (iVar3 == 0) {
              DAT_208001a2 = 0;
              return 1;
            }
            uVar1 = sd_card_detect();
          }
          else {
            uVar1 = sd_card_detect();
          }
        }
        else {
          uVar1 = sd_card_detect();
        }
      }
      else {
        uVar1 = sd_card_detect();
      }
    }
    else {
      uVar1 = sd_card_detect();
    }
    if (uVar1 != 0) {
      DAT_208001a2 = 5;
    }
  }
  return 2;
}


// ===== fmt_size_str @ 2010fcf0 (712 bytes)

/* "%.2f KB" ... "%d TB" */

void fmt_size_str(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined1 auStack_38 [32];
  
  uVar3 = (uint)((ulonglong)param_3 * 100);
  uVar1 = param_4 * 100 + (int)((ulonglong)param_3 * 100 >> 0x20);
  if (param_4 == 0 && (0x27ff < param_3) <= param_4) {
    uVar5 = __aeabi_ui2d(uVar1 * 0x400000 | uVar3 >> 10);
    uVar5 = __aeabi_ddiv((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
    sprintf(param_1,"%.2f KB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  }
  else {
    uVar4 = (uint)((ulonglong)param_3 * 10);
    uVar2 = param_4 * 10 + (int)((ulonglong)param_3 * 10 >> 0x20);
    if (param_4 == 0 && (0x18fff < param_3) <= param_4) {
      uVar5 = __aeabi_ui2d(uVar4 >> 10 | uVar2 * 0x400000);
      uVar5 = __aeabi_ddiv((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f KB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 == 0 && (0xf9fff < param_3) <= param_4) {
      sprintf(param_1,"%d KB",param_3 >> 10 | param_4 << 0x16);
    }
    else if (param_4 == 0 && (0x9fffff < param_3) <= param_4) {
      uVar5 = __aeabi_ui2d(uVar1 * 0x1000 | uVar3 >> 0x14);
      uVar5 = __aeabi_ddiv((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
      sprintf(param_1,"%.2f MB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 == 0 && (0x63fffff < param_3) <= param_4) {
      uVar5 = __aeabi_ui2d(uVar4 >> 0x14 | uVar2 * 0x1000);
      uVar5 = __aeabi_ddiv((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f MB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 == 0 && (0x3e7fffff < param_3) <= param_4) {
      sprintf(param_1,"%d MB",param_3 >> 0x14 | param_4 << 0xc);
    }
    else if (param_4 < 3 && (uint)(0x7fffffff < param_3) <= param_4 - 2) {
      uVar5 = __aeabi_ui2d(uVar1 * 4 | uVar3 >> 0x1e);
      uVar5 = __aeabi_ddiv((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
      sprintf(param_1,"%.2f GB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0x19) {
      uVar5 = __aeabi_ui2d(uVar4 >> 0x1e | uVar2 * 4);
      uVar5 = __aeabi_ddiv((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f GB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0xfa) {
      sprintf(param_1,"%d GB",param_3 >> 0x1e | param_4 << 2);
    }
    else if (param_4 < 0xa00) {
      uVar5 = __aeabi_ui2d(uVar1 >> 8);
      uVar5 = __aeabi_ddiv((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
      sprintf(param_1,"%.2f TB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0x6400) {
      uVar5 = __aeabi_ui2d(uVar2 >> 8);
      uVar5 = __aeabi_ddiv((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f TB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0x3e800) {
      sprintf(param_1,"%d TB",param_4 >> 8);
    }
    else {
      sprintf(param_1,"1000 TB+");
    }
  }
  sprintf(auStack_38," (%llu)",param_3,param_4);
  strcat(param_1,auStack_38);
  return;
}


// ===== sd_info_screen @ 20110034 (176 bytes)

/* FREE SPACE / CAPACITY */

void sd_info_screen(int param_1)

{
  int iVar1;
  undefined1 auStack_58 [64];
  undefined4 local_18;
  undefined4 auStack_14 [2];
  
  iVar1 = fs_disk_free(0x49,&local_18,auStack_14);
  if (iVar1 == 0) {
    fmt_size_str(auStack_58,auStack_14[0],auStack_14[0],local_18);
  }
  else {
    sprintf(auStack_58,"Unknown");
  }
  sprintf(param_1,"FREE SPACE : %s",auStack_58);
  iVar1 = fs_disk_size(0x49,&local_18,auStack_14);
  if (iVar1 == 0) {
    fmt_size_str(auStack_58,auStack_14[0],auStack_14[0],local_18);
  }
  else {
    sprintf(auStack_58,"Unknown");
  }
  sprintf(param_1 + 0x40,"CAPACITY   : %s",auStack_58);
  return;
}


// ===== task_sdmenu @ 2011010c (220 bytes)

void task_sdmenu(void)

{
  void *pvVar1;
  uint local_20;
  
LAB_2011012c:
  do {
    while( true ) {
      while( true ) {
        pvVar1 = itron_twai_flg(DAT_208001a8,0xffff,5,&local_20,-1);
        if (pvVar1 != (void *)0x0) {
          return;
        }
        if (local_20 == 1) break;
        if (local_20 == 2) {
          progress_range_init(&stack0xffffffd8,0,100);
          DAT_2080019f = sdmenu_load_file(&stack0xffffffd8);
        }
        else if (local_20 == 3) {
          DAT_2080019f = sd_make_dirs();
        }
      }
      DAT_208001a4 = sdmenu_save_file((uint)DAT_2080019d,0x208193a6,(uint)DAT_2080019e);
      if (DAT_208001a4 != -0x3a) break;
      DAT_208001a0 = 2;
LAB_201101b0:
      DAT_2080019f = 2;
    }
    if (DAT_208001a4 != -0xb) {
      if (DAT_208001a4 != 0) {
        DAT_208001a0 = 4;
        goto LAB_201101b0;
      }
      DAT_208001a0 = 0;
      DAT_2080019f = 1;
      goto LAB_2011012c;
    }
    DAT_208001a0 = 1;
    DAT_2080019f = 2;
  } while( true );
}


// ===== sdmenu_request @ 201101e8 (144 bytes)

/* starts save (flag 1) or load (flag 2), polls result */

char sdmenu_request(int param_1,void *param_2,uint *param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (DAT_2080019c != '\0') {
    itron_rot_rdq(0);
    uVar3 = progress_get();
    *(uint *)param_2 = uVar3;
    cVar2 = DAT_2080019f;
    if (DAT_2080019f != '\0') {
      DAT_2080019c = '\0';
      bVar1 = DAT_208001a1;
      if (param_1 != 0) {
        bVar1 = DAT_208001a0;
      }
      *param_3 = (uint)bVar1;
    }
    return cVar2;
  }
  DAT_2080019c = 1;
  DAT_2080019f = 0;
  progress_set(0);
  uVar3 = progress_get();
  *(uint *)param_2 = uVar3;
  if (param_1 == 0) {
    uVar4 = 2;
  }
  else {
    uVar4 = 1;
  }
  itron_set_flg(DAT_208001a8,uVar4);
  return '\0';
}


// ===== sd_format_request @ 20110278 (240 bytes)

/* flag 3 (sd_make_dirs), progress percent */

char sd_format_request(undefined4 *param_1,uint *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int local_28;
  
  local_28 = param_4;
  if (DAT_2080019c != '\0') {
    itron_dly_tsk(0x14);
    iVar1 = *(int *)(DAT_20808b44 + 0x2f8);
    if (iVar1 != 0) {
      iVar3 = *(int *)(DAT_20808b44 + 0x2f4);
      uVar4 = __aeabi_ui2d();
      uVar5 = __aeabi_ui2d(iVar1 - iVar3);
      uVar4 = __aeabi_ddiv((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar4,
                           (int)((ulonglong)uVar4 >> 0x20));
      __aeabi_dmul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x40590000);
      uVar2 = __aeabi_d2iz();
      *param_1 = uVar2;
    }
    if (DAT_2080019f != '\0') {
      itron_chg_pri(0);
      DAT_2080019c = '\0';
      *param_2 = (uint)DAT_208001a2;
    }
    return DAT_2080019f;
  }
  DAT_2080019c = 1;
  DAT_2080019f = 0;
  *param_1 = 0;
  itron_get_pri(0,&local_28);
  local_28 = local_28 + -1;
  itron_chg_pri(0);
  itron_set_flg(DAT_208001a8,3);
  itron_dly_tsk(0x32);
  return '\0';
}


// ===== sd_format_done @ 20110368 (32 bytes)

void sd_format_done(void)

{
  itron_chg_pri(0);
  DAT_2080019c = 0;
  return;
}


// ===== sdmenu_init @ 20110388 (96 bytes)

/* task "sdmenu" */

void sdmenu_init(void)

{
  uint uVar1;
  t_cflg local_10;
  
  local_10.flgatr = 2;
  local_10.iflgptn = 0;
  local_10.name = (char *)0x0;
  uVar1 = itron_acre_flg(0,&local_10);
  if (0 < (int)uVar1) {
    DAT_208001a8 = uVar1;
    uVar1 = itron_acre_tsk(0,&ctsk_sdmenu);
    if (0 < (int)uVar1) {
      itron_sta_tsk(uVar1,0);
    }
  }
  return;
}


// ===== hex_to_bin @ 201103f4 (96 bytes)

/* ASCII hex to bytes */

int hex_to_bin(int param_1,int param_2,int param_3,byte *param_4)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  byte *local_28;
  
  iVar3 = 0;
  iVar4 = 0;
  local_28 = param_4;
  while( true ) {
    bVar5 = SBORROW4(iVar4,param_3);
    iVar1 = iVar4 - param_3;
    if (iVar4 < param_3) {
      bVar5 = SBORROW4(iVar3,(int)param_4);
      iVar1 = iVar3 - (int)param_4;
    }
    if (iVar1 < 0 == bVar5) break;
    uVar2 = hex_parse((byte *)(param_1 + iVar4),2,&local_28);
    if ((byte *)(param_1 + iVar4) == local_28) {
      return iVar3;
    }
    *(char *)(param_2 + iVar3) = (char)uVar2;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 2;
  }
  return iVar3;
}


// ===== sdr_relay_xfer @ 20110548 (304 bytes)

/* binary register frame to MAIN, waits for 06 or a 7D reply */

uint sdr_relay_xfer(int *param_1,char *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  char local_120 [256];
  undefined4 local_20;
  int local_1c;
  
  if (*param_2 == -3) {
    uVar1 = 0xb;
  }
  else {
    uVar1 = 7;
  }
  (**(code **)(*param_1 + 0x24))(param_1,param_2,uVar1);
  __aeabi_memclr4(local_120,0x100);
  uVar2 = 0;
  local_20 = 0;
  do {
    itron_dly_tsk(1);
    local_1c = (**(code **)(*param_1 + 0x10))(param_1,local_120 + uVar2,0x40);
    uVar2 = uVar2 + local_1c;
    if (0xff < uVar2) {
      return 0xffffffff;
    }
  } while (local_1c != 0);
  if (uVar2 == 1) {
    if (local_120[0] == '\x06') {
      memcpy(param_3,local_120,1);
      return 1;
    }
  }
  else {
    bVar3 = local_120[1] == '}';
    if (bVar3) {
      local_120[1] = local_120[2];
    }
    if (bVar3 && local_120[1] == '\0') {
      local_20 = CONCAT31(local_20._1_3_,6);
      (**(code **)(*param_1 + 0x24))(param_1,&local_20,1);
      itron_dly_tsk(1);
      memcpy(param_3,local_120 + 3,4);
      return 4;
    }
  }
  return 0xffffffff;
}


// ===== sdr_reg_read @ 20110584 (200 bytes)

/* FE 00 "%04X" sum: FPGA register read via MAIN */

uint sdr_reg_read(uint param_1,uint param_2)

{
  char *pcVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  byte abStack_140 [256];
  char local_40 [32];
  char local_20 [8];
  undefined1 *local_18 [2];
  
  __aeabi_memclr4(local_40,0x20);
  cVar5 = '\0';
  local_20[0] = -2;
  local_20[1] = '\0';
  local_20[2] = '\0';
  local_20[3] = '\0';
  local_20[4] = '\0';
  local_20[5] = '\0';
  local_20[6] = '\0';
  local_20[7] = '\0';
  sprintf(local_40,"%04X",param_2);
  uVar3 = strlen(local_40);
  memcpy(local_20 + 2,local_40,uVar3);
  uVar4 = 0;
  do {
    pcVar1 = local_40 + uVar4;
    uVar4 = uVar4 + 1;
    cVar5 = *pcVar1 + cVar5;
  } while (uVar4 < 6);
  local_20[6] = cVar5;
  uVar4 = sdr_relay_xfer((int *)param_1,local_20,(uint)abStack_140);
  if (uVar4 != 0xffffffff) {
    uVar2 = hex_parse(abStack_140,4,local_18);
    uVar4 = (uint)uVar2;
    if (local_18[0] == abStack_140) {
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}


// ===== sdr_reg_write @ 2011064c (172 bytes)

/* FD 00 "%04X%04X" sum: FPGA register write via MAIN */

uint sdr_reg_write(uint param_1,uint param_2,uint param_3,uint param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  char cVar4;
  char local_48 [32];
  char local_28 [16];
  
  cVar4 = '\0';
  __aeabi_memclr4(local_48,0x20);
  local_28[0] = -3;
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  sprintf(local_48,"%04X%04X",param_2,param_3);
  uVar2 = strlen(local_48);
  memcpy(local_28 + 2,local_48,uVar2);
  uVar3 = 0;
  do {
    pcVar1 = local_48 + uVar3;
    uVar3 = uVar3 + 1;
    cVar4 = *pcVar1 + cVar4;
  } while (uVar3 < 10);
  local_28[10] = cVar4;
  uVar3 = sdr_relay_xfer((int *)param_1,local_28,param_4);
  return uVar3;
}


// ===== sdr_set_flash_addr @ 201106f8 (88 bytes)

/* regs 0x30 / 0x31 = flash address */

int sdr_set_flash_addr(uint param_1,uint param_2,ushort param_3)

{
  uint uVar1;
  undefined1 auStack_110 [256];
  
  uVar1 = sdr_reg_write(param_1,param_2 | 0x30,0,(uint)auStack_110);
  if ((uVar1 != 0xffffffff) &&
     (uVar1 = sdr_reg_write(param_1,param_2 | 0x31,(uint)param_3,(uint)auStack_110),
     uVar1 != 0xffffffff)) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== sdr_wait_ready @ 20110750 (92 bytes)

/* polls reg 0x32 until the top nibble is 0 or 8 */

uint sdr_wait_ready(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  
  while( true ) {
    bVar2 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar2) {
      return 0xffffffff;
    }
    uVar1 = sdr_reg_read(param_1,param_2 | 0x32);
    if (uVar1 == 0xffffffff) break;
    if ((int)uVar1 >> 0xc == 0 || (int)uVar1 >> 0xc == 8) {
      return 0;
    }
    itron_dly_tsk(1);
  }
  return 0xffffffff;
}


// ===== sdr_spi_master_write @ 201107c0 (116 bytes)

/* RSPI2 master for SDR image */

void sdr_spi_master_write(uint param_1,uint param_2)

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

uint sdr_spi_xfer_block(uint param_1,uint param_2,int param_3,ushort param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  undefined1 auStack_128 [256];
  uint local_28;
  
  uVar4 = (uint)param_4;
  __aeabi_memclr4(auStack_128,0x100);
  uVar1 = work_buf_get(0);
  pbVar7 = (byte *)(uVar1 + 0x2000);
  local_28 = sfl_stream_read(uVar1,1,0x2000,param_2);
  if (local_28 != 0) {
    __aeabi_memset(pbVar7,0x1000,0xff);
    hex_to_bin(uVar1,pbVar7,local_28,0x1000);
    uVar1 = crc16_a001(0xffff,0x1000,pbVar7);
    iVar6 = 0;
    uVar5 = uVar4 | 0x32;
    do {
      iVar2 = sdr_set_flash_addr(param_1,uVar4,(short)param_3 * 0x1000);
      if ((((iVar2 != -1) &&
           (uVar3 = sdr_reg_write(param_1,uVar5,3,(uint)auStack_128), uVar3 != 0xffffffff)) &&
          (uVar3 = sdr_wait_ready(param_1,uVar4,1000), uVar3 != 0xffffffff)) &&
         (uVar3 = sdr_reg_write(param_1,uVar5,1,(uint)auStack_128), uVar3 != 0xffffffff)) {
        sdr_spi_master_write((uint)pbVar7,0x1000);
        uVar3 = sdr_wait_ready(param_1,uVar4,1000);
        if ((((uVar3 != 0xffffffff) &&
             (uVar3 = sdr_reg_write(param_1,uVar5,4,(uint)auStack_128), uVar3 != 0xffffffff)) &&
            ((uVar3 = sdr_wait_ready(param_1,uVar4,1000), uVar3 != 0xffffffff &&
             ((uVar3 = sdr_reg_write(param_1,uVar5,5,(uint)auStack_128), uVar3 != 0xffffffff &&
              (uVar3 = sdr_wait_ready(param_1,uVar4,1000), uVar3 != 0xffffffff)))))) &&
           (local_28 = sdr_reg_read(param_1,uVar4 | 0x33), local_28 == uVar1)) {
          return 1;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x1e);
  }
  return 0;
}


// ===== sdr_relay_mode_cmd @ 201109fc (188 bytes)

/* same F1 <code> frame (SDR 01/81) */

uint sdr_relay_mode_cmd(int *param_1,char param_2)

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

uint sdr_flash_write(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  scif_uart *psVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  ushort uVar6;
  undefined8 uVar7;
  undefined1 auStack_3c [24];
  undefined1 auStack_24 [8];
  
  progress_range_init(auStack_24,5,99);
  uVar1 = progress_scale(auStack_24);
  progress_set(uVar1);
  sfl_stream_init(auStack_3c,param_1,0,param_2);
  mainlink_rx_ctrl(1);
  psVar2 = scif5_get(0);
  (*(code *)psVar2->vtbl[1])(psVar2,0x54600,8,0,2);
  uVar3 = sdr_relay_mode_cmd((int *)psVar2,'\x01');
  uVar1 = 0;
  if (uVar3 != 0) {
    if (param_3 == 0) {
      uVar6 = 0x1000;
    }
    else {
      uVar6 = 0;
    }
    uVar1 = work_buf_get(0);
    iVar4 = sfl_stream_read(uVar1,1,0x2000,(int)auStack_3c);
    uVar1 = 0;
    if (iVar4 != 0) {
      crc16_a001_table_init();
      iVar4 = 0;
      do {
        uVar7 = __aeabi_i2d(iVar4);
        uVar7 = __aeabi_ddiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x4080c000);
        uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
        uVar1 = progress_scale(auStack_24,uVar5,(int)uVar7,uVar5);
        progress_set(uVar1);
        uVar1 = sdr_spi_xfer_block((uint)psVar2,(uint)auStack_3c,iVar4,uVar6);
        if (uVar1 == 0) {
          return 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x218);
      if (param_2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0x240;
      }
      uVar1 = fs_fseek(param_1,uVar1,0);
      if (uVar1 == 0) {
        progress_set(100);
        sfl_stream_init(auStack_3c,param_1,0,param_2);
        sdr_spi_xfer_block((uint)psVar2,(uint)auStack_3c,0x240,uVar6);
      }
      uVar1 = sdr_relay_mode_cmd((int *)psVar2,-0x7f);
    }
  }
  return uVar1;
}


// ===== sdr_debug_cmd @ 20110c3c (364 bytes)

/* sdrup/sdr1up/sdr2up/sdrchk*/sdrspi/sdrfile/delta */

void sdr_debug_cmd(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = (uint *)hid_line_edit(&DAT_208193d8,param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    return;
  }
  uVar2 = strcmp((uint *)"sdrup",puVar1);
  if ((((uVar2 == 0) || (uVar2 = strcmp((uint *)"sdr1up",puVar1), uVar2 == 0)) ||
      (uVar2 = strcmp((uint *)"sdr2up",puVar1), uVar2 == 0)) ||
     (uVar2 = strcmp((uint *)"sdrchk1",puVar1), uVar2 == 0)) {
    itron_set_flg(DAT_208001b8);
  }
  uVar2 = strcmp((uint *)"sdrup/g",puVar1);
  if (((uVar2 != 0) && (uVar2 = strcmp((uint *)"sdr1up/g",puVar1), uVar2 != 0)) &&
     ((uVar2 = strcmp((uint *)"sdr2up/g",puVar1), uVar2 != 0 &&
      ((uVar2 = strcmp((uint *)"sdrchk1/g",puVar1), uVar2 != 0 &&
       (uVar2 = strcmp((uint *)"sdrchk2/g",puVar1), uVar2 != 0)))))) {
    iVar3 = strncmp((byte *)"sdrspi",(byte *)puVar1,6);
    if (iVar3 == 0) {
      memcpy(&DAT_208193b8,puVar1,0x20);
    }
    else {
      uVar2 = strcmp((uint *)"sdrfile",puVar1);
      if ((uVar2 != 0) && (uVar2 = strcmp((uint *)"delta",puVar1), uVar2 != 0)) {
        return;
      }
    }
  }
  itron_set_flg(DAT_208001b8);
  return;
}


// ===== sdr_debug_init @ 20110da8 (52 bytes)

/* chain-1 handler 7: registers sdr_debug_cmd, flag 0x208001B8 (no task waits on it) */

uint sdr_debug_init(void)

{
  uint uVar1;
  code *pcVar2;
  t_cflg local_10;
  
  local_10.flgatr = 2;
  local_10.iflgptn = 0;
  local_10.name = (char *)0x0;
  uVar1 = itron_acre_flg(0,&local_10);
  if ((int)uVar1 < 1) {
    pcVar2 = (code *)0x0;
  }
  else {
    pcVar2 = sdr_debug_cmd;
    DAT_208001b8 = uVar1;
  }
  return (uint)pcVar2;
}


// ===== FUN_20110e68 @ 20110e68 (28 bytes)

undefined4 FUN_20110e68(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 in_cr9;
  undefined4 in_cr12;
  undefined4 in_cr13;
  
  coprocessor_moveto(0xf,0,1,0x80000000,in_cr9,in_cr12);
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr12);
  coprocessor_moveto(0xf,0,0,uVar1 | 0xd,in_cr9,in_cr12);
  uVar2 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar2;
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
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar1 = FLCTL_FLADR;
  if (iVar1 == -0x55443323) {
    uVar3 = spiflash_erase(0,0,0x340000);
    if (uVar3 == 0) {
      uVar3 = spiflash_erase(0,0x3e0000,0x14);
      if (uVar3 == 0) {
        uVar3 = spiflash_erase(0,0x3f0000,0x14);
        if (uVar3 == 0) {
          uVar3 = spiflash_write(0,0x20100000,0x340000);
          if (uVar3 == 0) {
            local_28 = 0;
            local_24 = 0;
            local_20 = 0;
            local_1c = 0;
            local_2c = &DAT_20182018;
            uVar3 = spiflash_write(0x3e0000,(uint)&local_2c,0x14);
            if (uVar3 == 0) {
              uVar3 = spiflash_write(0x3f0000,(uint)&local_2c,0x14);
              if (uVar3 == 0) {
                uVar2 = 0;
                FLCTL_FLADR = 0;
                software_bkpt(0);
              }
              else {
                software_bkpt(4);
                uVar2 = 4;
              }
            }
            else {
              software_bkpt(3);
              uVar2 = 3;
            }
          }
          else {
            software_bkpt(2);
            uVar2 = 2;
          }
        }
        else {
          software_bkpt(1);
          uVar2 = 1;
        }
      }
      else {
        software_bkpt(1);
        uVar2 = 1;
      }
    }
    else {
      software_bkpt(1);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== fwdbg_init @ 20111064 (20 bytes)

/* registers fwdbg_line (fw1up/fw1chk/up0/up1/up2) */

void * fwdbg_init(void)

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
  
  uVar1 = ADC_ADDRA;
  uVar2 = ADC_ADDRB;
  uVar3 = ADC_ADDRC;
  uVar4 = ADC_ADDRD;
  DAT_20819530 = (uint)(uVar4 >> 4);
  uVar4 = ADC_ADDRE;
  uVar5 = ADC_ADDRF;
  uVar6 = ADC_ADDRG;
  uVar7 = ADC_ADDRH;
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
  ADC_ADCSR = 0x20ff;
  return;
}


// ===== work_buf_get @ 20111174 (52 bytes)

/* (n): the shared 0xC0000-byte work buffer 0x20819560, n bytes cleared first (n < 0: all) [fact] */

undefined * work_buf_get(int param_1)

{
  if (param_1 < 0) {
    __aeabi_memclr4(&DAT_20819560,0xc0000);
  }
  else if (param_1 != 0) {
    __aeabi_memclr4(&DAT_20819560,param_1);
  }
  return &DAT_20819560;
}


// ===== FUN_201111ac @ 201111ac (28 bytes)

undefined4 FUN_201111ac(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 in_cr9;
  undefined4 in_cr12;
  undefined4 in_cr13;
  
  coprocessor_moveto(0xf,0,1,0x80000000,in_cr9,in_cr12);
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr12);
  coprocessor_moveto(0xf,0,0,uVar1 | 0xd,in_cr9,in_cr12);
  uVar2 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar2;
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

void kbd_set_current(uint param_1)

{
  DAT_208001c8 = param_1;
  return;
}


// ===== kbd_led_status @ 20111224 (76 bytes)

/* set the 3 keyboard LEDs (value, mask): debug progress display */

void kbd_led_status(byte param_1,byte param_2)

{
  DAT_2080010c = DAT_2080010c & ~(param_2 & 7) | param_1 & 7;
  usbkbd_set_leds(DAT_208001c8,0,&DAT_2080010c);
  itron_dly_tsk(1);
  return;
}


// ===== FUN_20111270 @ 20111270 (68 bytes)

void FUN_20111270(byte param_1,byte param_2)

{
  DAT_2080010c = DAT_2080010c & ~(param_2 & 7) | param_1 & 7;
  usbkbd_set_leds(DAT_208001c8,0,&DAT_2080010c);
  return;
}


// ===== hex_parse @ 201112b4 (192 bytes)

/* up to n hex digits */

ushort hex_parse(byte *param_1,int param_2,void *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  uVar1 = 0;
  *(byte **)param_3 = param_1;
  for (iVar3 = 0; pbVar4 = param_1, iVar3 < param_2; iVar3 = iVar3 + 1) {
    pbVar4 = param_1 + 1;
    uVar2 = (uint)*param_1;
    if (uVar2 == 0) break;
    if ((uVar2 < 0x30) || (0x39 < uVar2)) {
      if ((uVar2 < 0x41) || (0x46 < uVar2)) {
        if ((uVar2 < 0x61) || (0x66 < uVar2)) {
          *(byte **)param_3 = param_1;
          goto LAB_20111354;
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
  *(byte **)param_3 = pbVar4;
LAB_20111354:
  return (ushort)uVar1;
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


// ===== FUN_201113f8 @ 201113f8 (24 bytes)

void FUN_201113f8(void)

{
  DAT_208001cc = DAT_208001cc + 1;
  return;
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

void mainlink_trace(uint param_1,uint param_2)

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

