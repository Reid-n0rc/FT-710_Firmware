// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== sdmenu_select @ 2010f2e8 (24 bytes)

void sdmenu_select(undefined1 param_1,undefined4 param_2,undefined1 param_3)

{
  DAT_2080019d = param_1;
  DAT_2080019e = param_3;
  memcpy(&DAT_208193a6,param_2,0x10);
  return;
}


// ===== sdmenu_select_load @ 2010f300 (92 bytes)

void sdmenu_select_load(int param_1,int param_2,int param_3,undefined1 param_4)

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
sdmenu_write_dat(undefined4 param_1,int param_2,undefined4 param_3,int param_4,uint param_5,
                undefined4 param_6)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int extraout_r1;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 auStack_78 [62];
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined4 local_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  
  local_34 = param_1;
  iStack_30 = param_2;
  uStack_2c = param_3;
  iStack_28 = param_4;
  FUN_2015525c(auStack_78,0x40,0x20);
  local_39 = 10;
  local_3a = 0xd;
  iVar6 = 0;
  uVar9 = FUN_20164d54(param_5 + 0x240);
  uVar4 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar1 = (undefined4)uVar9;
  iVar7 = 0;
  do {
    iVar8 = iVar7;
    iVar7 = iVar8 + 0x40;
    uVar9 = FUN_20164d54(iVar7);
    uVar9 = FUN_201649d8((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar4);
    uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
    progress_scale(param_6,uVar3,(int)uVar9,uVar3);
    progress_set();
    FUN_20150dcc(0);
    uVar2 = fs_fwrite(auStack_78,1,0x40,local_34);
    if (uVar2 < 0x40) {
      return 1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  local_38 = 0x139eeca6;
  crc32_make_table();
  uVar3 = crc32_update(0xffffffff,param_5,param_4);
  uVar2 = crc32_update(uVar3,4,&local_38);
  if (param_2 == 0) {
    pcVar5 = "MemList";
  }
  else {
    pcVar5 = "Menu";
  }
  sprintf(auStack_78,"%s  %d  %08X",pcVar5,param_3,~uVar2);
  iVar7 = FUN_20155122(auStack_78);
  iVar8 = iVar8 + 0x80;
  auStack_78[iVar7] = 0x20;
  uVar9 = FUN_20164d54(iVar8);
  uVar9 = FUN_201649d8((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar4);
  uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
  progress_scale(param_6,uVar3,(int)uVar9,uVar3);
  progress_set();
  FUN_20150dcc(0);
  uVar2 = fs_fwrite(auStack_78,1,0x40,local_34);
  if (0x3f < uVar2) {
    FUN_20156260(param_5,0x100);
    iVar7 = 0;
    if (param_5 >> 8 != 0) {
      do {
        iVar8 = iVar8 + 0x100;
        uVar9 = FUN_20164d54(iVar8);
        uVar9 = FUN_201649d8((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar4);
        uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
        progress_scale(param_6,uVar3,(int)uVar9,uVar3);
        progress_set();
        FUN_20150dcc(0);
        iVar6 = fs_fwrite(param_4,1,0x100,local_34);
        if (iVar6 < 0x100) {
          return 2;
        }
        iVar7 = iVar7 + 1;
        param_4 = param_4 + 0x100;
      } while (iVar7 < (int)(param_5 >> 8));
    }
    if (extraout_r1 != 0) {
      uVar9 = FUN_20164d54(iVar8 + extraout_r1);
      uVar9 = FUN_201649d8((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar1,uVar4);
      uVar1 = (undefined4)((ulonglong)uVar9 >> 0x20);
      progress_scale(param_6,uVar1,(int)uVar9,uVar1);
      progress_set();
      FUN_20150dcc(0);
      iVar7 = fs_fwrite(param_4,1,extraout_r1,local_34);
      if (iVar7 < extraout_r1) {
        return 2;
      }
    }
    return 0;
  }
  return 2;
}


// ===== sdmenu_save_file @ 2010f60c (488 bytes)

/* <dir>\<name>.dat, sfl_encode, salted CRC-32 */

int sdmenu_save_file(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  undefined8 uVar4;
  undefined1 auStack_50 [40];
  undefined4 local_28;
  undefined4 local_24;
  undefined1 auStack_20 [12];
  
  progress_range_init(&local_28,1,5);
  progress_set(local_28);
  iVar1 = FUN_2013fba0();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_2014c410(*(undefined4 *)(&DAT_208001ac + param_1 * 4));
  if (iVar1 == 0) {
    iVar1 = FUN_2014c410("I:\\FT-710");
    if (iVar1 == 0) {
      iVar1 = FUN_2014beec("I:\\FT-710");
      if (iVar1 != 0) goto LAB_2010f7b8;
    }
    else {
      thunk_FUN_2014c474();
    }
    uVar4 = FUN_2014beec(*(undefined4 *)(&DAT_208001ac + param_1 * 4));
    uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
    if ((int)uVar4 != 0) goto LAB_2010f7b8;
  }
  else {
    thunk_FUN_2014c474();
    uVar3 = extraout_r1;
  }
  progress_scale(&local_28,uVar3,0,0x3fe00000);
  progress_set();
  sprintf(auStack_50,"%s\\%s.dat",*(undefined4 *)(&DAT_208001ac + param_1 * 4),param_2);
  iVar1 = fs_fopen(auStack_50,&DWORD_2010f804);
  if (iVar1 != 0) {
    FUN_20126160(1);
    iVar2 = FUN_20111174(0x8350);
    FUN_20155274(iVar2 + 0x640,0x7d10);
    *(char *)(iVar2 + 0x640) = (char)param_1;
    *(char *)(iVar2 + 0x641) = (char)((uint)param_1 >> 8);
    *(char *)(iVar2 + 0x642) = (char)((uint)param_1 >> 0x10);
    *(char *)(iVar2 + 0x643) = (char)((uint)param_1 >> 0x18);
    *(char *)(iVar2 + 0x644) = (char)param_3;
    *(char *)(iVar2 + 0x645) = (char)((uint)param_3 >> 8);
    *(char *)(iVar2 + 0x646) = (char)((uint)param_3 >> 0x10);
    *(char *)(iVar2 + 0x647) = (char)((uint)param_3 >> 0x18);
    memcpy(iVar2 + 0x650,&DAT_208116a6,32000);
    sfl_encode(0,iVar2 + 0x640,0x7d10);
    progress_scale(&local_28,extraout_r1_00,0,0x3ff00000);
    progress_set();
    progress_range_init(auStack_20,local_24,99);
    iVar2 = sdmenu_write_dat(iVar1,param_1,param_3,iVar2 + 0x640,0x7d10,auStack_20);
    FUN_20133620();
    FUN_20126160(0);
    if (iVar2 == 0) {
      FUN_2013fc4c(1);
      iVar2 = FUN_20141ff0(iVar1);
      FUN_2013fc4c(0);
      progress_set(100);
    }
    else {
      iVar2 = FUN_2014d95c();
      FUN_20141ff0(iVar1);
    }
    return iVar2;
  }
LAB_2010f7b8:
  iVar1 = FUN_2014d95c();
  return iVar1;
}


// ===== sdmenu_load_file @ 2010f81c (876 bytes)

/* WARNING: Type propagation algorithm not settling */
/* RENAME (was sfl_load_file): loads a MemList/Menu .dat (size 0x7F50), checks CRC, type and model
   word */

undefined4 sdmenu_load_file(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 auStack_1a8 [64];
  undefined1 local_168;
  undefined1 auStack_a8 [40];
  int local_80;
  undefined1 *local_7c;
  undefined1 auStack_78 [52];
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34 [3];
  undefined4 *local_28;
  
  local_28 = param_1;
  progress_set(*param_1);
  sprintf(auStack_a8,"%s\\%s.dat",*(undefined4 *)(&DAT_208001ac + (uint)DAT_2080019d * 4),
          &DAT_208193a6);
  if (DAT_2080019d < 2) {
    iVar1 = FUN_2014aec8(auStack_a8,auStack_78);
    if (iVar1 == 0) {
      if ((local_44 == 0x7f50) &&
         (local_80 = fs_fopen(auStack_a8,DWORD_ARRAY_2010fb88), local_80 != 0)) {
        iVar1 = 0;
        iVar6 = 0;
        local_7c = auStack_1a8;
        uVar7 = FUN_20164d82(0x7f50);
        uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
        do {
          iVar1 = iVar1 + 0x40;
          uVar8 = FUN_20164d54(iVar1);
          uVar8 = FUN_201649d8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,uVar4);
          uVar5 = (undefined4)((ulonglong)uVar8 >> 0x20);
          progress_scale(local_28,uVar5,(int)uVar8,uVar5);
          progress_set();
          iVar2 = fs_fread(auStack_1a8,1,0x40,local_80);
          if (iVar2 == 0) goto LAB_2010f9bc;
          FUN_20150dcc(0);
          iVar6 = iVar6 + 1;
        } while (iVar6 < 9);
        local_168 = 0;
        iVar6 = FUN_20155122(auStack_1a8);
        if ((((iVar6 == 0x40) &&
             (iVar6 = FUN_2014e320(auStack_1a8,0x2010fb8c,&local_7c), iVar6 != 0)) &&
            (iVar6 = FUN_2014e320(local_7c,0x2010fb8c,&local_7c), iVar6 != 0)) &&
           ((iVar6 = FUN_2014e320(local_7c,0x2010fb8c,&local_7c), iVar6 != 0 &&
            (local_34[2] = hex_parse(iVar6,8,local_34), local_34[0] != iVar6)))) {
          local_40 = 0xffffffff;
          local_34[1] = 0x139eeca6;
          crc32_make_table();
          FUN_20126160(1);
          iVar6 = FUN_20111174(0x8350);
          local_38 = 2;
          iVar2 = iVar6 + 0x640;
          local_3c = 0;
          while (iVar3 = fs_fread(auStack_1a8,1,0x100,local_80), iVar3 != 0) {
            iVar1 = iVar1 + iVar3;
            uVar8 = FUN_20164d54(iVar1);
            uVar8 = FUN_201649d8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,uVar4);
            uVar5 = (undefined4)((ulonglong)uVar8 >> 0x20);
            progress_scale(local_28,uVar5,(int)uVar8,uVar5);
            progress_set();
            FUN_20150dcc(0);
            local_40 = crc32_update(local_40,iVar3,auStack_1a8);
            local_3c = sfl_decode(local_3c,auStack_1a8,iVar3);
            memcpy(iVar2,auStack_1a8,iVar3);
            iVar2 = iVar2 + iVar3;
          }
          FUN_20141ff0(local_80);
          uVar7 = crc32_update(local_40,4,local_34 + 1);
          progress_scale(local_28,(int)((ulonglong)uVar7 >> 0x20),0,0x3ff00000);
          progress_set();
          if ((local_34[2] == ~(uint)uVar7) && (*(uint *)(iVar6 + 0x640) == (uint)DAT_2080019d)) {
            if (*(uint *)(iVar6 + 0x644) == (uint)DAT_2080019e) {
              memcpy(&DAT_208116a6,iVar6 + 0x650,32000);
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
          FUN_20133620();
          FUN_20126160(0);
          return local_38;
        }
LAB_2010f9bc:
        DAT_208001a1 = 1;
        FUN_20141ff0(local_80);
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

undefined4 sd_make_dirs(void)

{
  int iVar1;
  int iVar2;
  
  FUN_20103bc8(1);
  itron_dly_tsk(0x14);
  iVar1 = FUN_2013f984(0x49);
  if ((iVar1 != 0) && (iVar2 = sd_card_detect(), iVar2 != 0)) {
    iVar1 = -1;
    DAT_208001a2 = 5;
  }
  FUN_20103bc8(0);
  itron_dly_tsk(0x14);
  if (iVar1 == 0) {
    iVar1 = FUN_2014beec("I:\\FT-710");
    if (iVar1 == 0) {
      iVar1 = FUN_2014beec("I:\\FT-710\\Capture");
      if (iVar1 == 0) {
        iVar1 = FUN_2014beec("I:\\FT-710\\MemList");
        if (iVar1 == 0) {
          iVar1 = FUN_2014beec("I:\\FT-710\\Menu");
          if (iVar1 == 0) {
            iVar1 = FUN_2014beec("I:\\FT-710\\PlayList");
            if (iVar1 == 0) {
              DAT_208001a2 = 0;
              return 1;
            }
            iVar1 = sd_card_detect();
          }
          else {
            iVar1 = sd_card_detect();
          }
        }
        else {
          iVar1 = sd_card_detect();
        }
      }
      else {
        iVar1 = sd_card_detect();
      }
    }
    else {
      iVar1 = sd_card_detect();
    }
    if (iVar1 != 0) {
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
    uVar5 = FUN_20164d82(uVar1 * 0x400000 | uVar3 >> 10);
    uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
    sprintf(param_1,"%.2f KB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  }
  else {
    uVar4 = (uint)((ulonglong)param_3 * 10);
    uVar2 = param_4 * 10 + (int)((ulonglong)param_3 * 10 >> 0x20);
    if (param_4 == 0 && (0x18fff < param_3) <= param_4) {
      uVar5 = FUN_20164d82(uVar4 >> 10 | uVar2 * 0x400000);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f KB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 == 0 && (0xf9fff < param_3) <= param_4) {
      sprintf(param_1,"%d KB",param_3 >> 10 | param_4 << 0x16);
    }
    else if (param_4 == 0 && (0x9fffff < param_3) <= param_4) {
      uVar5 = FUN_20164d82(uVar1 * 0x1000 | uVar3 >> 0x14);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
      sprintf(param_1,"%.2f MB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 == 0 && (0x63fffff < param_3) <= param_4) {
      uVar5 = FUN_20164d82(uVar4 >> 0x14 | uVar2 * 0x1000);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f MB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 == 0 && (0x3e7fffff < param_3) <= param_4) {
      sprintf(param_1,"%d MB",param_3 >> 0x14 | param_4 << 0xc);
    }
    else if (param_4 < 3 && (uint)(0x7fffffff < param_3) <= param_4 - 2) {
      uVar5 = FUN_20164d82(uVar1 * 4 | uVar3 >> 0x1e);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
      sprintf(param_1,"%.2f GB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0x19) {
      uVar5 = FUN_20164d82(uVar4 >> 0x1e | uVar2 * 4);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
      sprintf(param_1,"%.1f GB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0xfa) {
      sprintf(param_1,"%d GB",param_3 >> 0x1e | param_4 << 2);
    }
    else if (param_4 < 0xa00) {
      uVar5 = FUN_20164d82(uVar1 >> 8);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40590000);
      sprintf(param_1,"%.2f TB",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    else if (param_4 < 0x6400) {
      uVar5 = FUN_20164d82(uVar2 >> 8);
      uVar5 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40240000);
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
  FUN_2015515c(param_1,auStack_38);
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
  
  iVar1 = FUN_2014b880(0x49,&local_18,auStack_14);
  if (iVar1 == 0) {
    fmt_size_str(auStack_58,auStack_14[0],auStack_14[0],local_18);
  }
  else {
    sprintf(auStack_58,"Unknown");
  }
  sprintf(param_1,"FREE SPACE : %s",auStack_58);
  iVar1 = thunk_FUN_2014b140(0x49,&local_18,auStack_14);
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
  int iVar1;
  undefined4 local_28 [2];
  int local_20;
  
LAB_2011012c:
  do {
    while( true ) {
      while( true ) {
        local_28[0] = 0xffffffff;
        iVar1 = itron_twai_flg(DAT_208001a8,0xffff,5,&local_20);
        if (iVar1 != 0) {
          return;
        }
        if (local_20 == 1) break;
        if (local_20 == 2) {
          progress_range_init(local_28,0,100);
          DAT_2080019f = sdmenu_load_file(local_28);
        }
        else if (local_20 == 3) {
          DAT_2080019f = sd_make_dirs();
        }
      }
      DAT_208001a4 = sdmenu_save_file(DAT_2080019d,&DAT_208193a6,DAT_2080019e);
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

char sdmenu_request(int param_1,undefined4 *param_2,uint *param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (DAT_2080019c != '\0') {
    FUN_20150dcc(0);
    uVar3 = progress_get();
    *param_2 = uVar3;
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
  *param_2 = uVar3;
  if (param_1 == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 1;
  }
  itron_set_flg(DAT_208001a8,uVar3);
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
      uVar4 = FUN_20164d82();
      uVar5 = FUN_20164d82(iVar1 - iVar3);
      uVar4 = FUN_201649d8((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar4,
                           (int)((ulonglong)uVar4 >> 0x20));
      FUN_20164da8((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x40590000);
      uVar2 = FUN_20164c90();
      *param_1 = uVar2;
    }
    if (DAT_2080019f != '\0') {
      FUN_2014e884(0);
      DAT_2080019c = '\0';
      *param_2 = (uint)DAT_208001a2;
    }
    return DAT_2080019f;
  }
  DAT_2080019c = 1;
  DAT_2080019f = 0;
  *param_1 = 0;
  FUN_20150aac(0,&local_28);
  local_28 = local_28 + -1;
  FUN_2014e884(0);
  itron_set_flg(DAT_208001a8,3);
  itron_dly_tsk(0x32);
  return '\0';
}


// ===== sd_format_done @ 20110368 (32 bytes)

void sd_format_done(void)

{
  FUN_2014e884(0);
  DAT_2080019c = 0;
  return;
}


// ===== sdmenu_init @ 20110388 (96 bytes)

/* task "sdmenu" */

void sdmenu_init(void)

{
  int iVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_10 = 2;
  uStack_c = 0;
  local_8 = 0;
  iVar1 = itron_acre_flg(0,&local_10);
  if (0 < iVar1) {
    DAT_208001a8 = iVar1;
    iVar1 = itron_acre_tsk(0,&DAT_201654f8);
    if (0 < iVar1) {
      itron_sta_tsk(iVar1,0);
    }
  }
  return;
}


// ===== hex_to_bin @ 201103f4 (96 bytes)

/* ASCII hex to bytes */

int hex_to_bin(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int local_28;
  
  iVar3 = 0;
  iVar4 = 0;
  local_28 = param_4;
  while( true ) {
    bVar5 = SBORROW4(iVar4,param_3);
    iVar1 = iVar4 - param_3;
    if (iVar4 < param_3) {
      bVar5 = SBORROW4(iVar3,param_4);
      iVar1 = iVar3 - param_4;
    }
    if ((iVar1 < 0 == bVar5) ||
       (uVar2 = hex_parse(param_1 + iVar4,2,&local_28), param_1 + iVar4 == local_28)) break;
    *(undefined1 *)(param_2 + iVar3) = uVar2;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 2;
  }
  return iVar3;
}


// ===== sdr_relay_xfer @ 20110548 (304 bytes)

/* binary register frame to MAIN, waits for 06 or a 7D reply */

undefined4 sdr_relay_xfer(int *param_1,char *param_2,undefined4 param_3)

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
  memclr(local_120,0x100);
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

uint sdr_reg_read(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  char cVar4;
  undefined1 auStack_140 [256];
  char local_40 [32];
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 *local_18 [2];
  
  memclr(local_40,0x20);
  cVar4 = '\0';
  local_20 = 0xfe;
  local_1c = 0;
  sprintf(local_40,"%04X",param_2);
  uVar2 = FUN_20155122(local_40);
  memcpy((int)&local_20 + 2,local_40,uVar2);
  uVar3 = 0;
  do {
    pcVar1 = local_40 + uVar3;
    uVar3 = uVar3 + 1;
    cVar4 = *pcVar1 + cVar4;
  } while (uVar3 < 6);
  local_1c._0_3_ = CONCAT12(cVar4,(undefined2)local_1c);
  uVar3 = sdr_relay_xfer(param_1,&local_20,auStack_140);
  if (uVar3 != 0xffffffff) {
    uVar3 = hex_parse(auStack_140,4,local_18);
    uVar3 = uVar3 & 0xffff;
    if (local_18[0] == auStack_140) {
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}


// ===== sdr_reg_write @ 2011064c (172 bytes)

/* FD 00 "%04X%04X" sum: FPGA register write via MAIN */

void sdr_reg_write(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  char cVar4;
  char local_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar4 = '\0';
  memclr(local_48,0x20);
  local_28 = 0xfd;
  local_24 = 0;
  local_20 = 0;
  sprintf(local_48,"%04X%04X",param_2,param_3);
  uVar2 = FUN_20155122(local_48);
  memcpy((int)&local_28 + 2,local_48,uVar2);
  uVar3 = 0;
  do {
    pcVar1 = local_48 + uVar3;
    uVar3 = uVar3 + 1;
    cVar4 = *pcVar1 + cVar4;
  } while (uVar3 < 10);
  local_20._0_3_ = CONCAT12(cVar4,(undefined2)local_20);
  sdr_relay_xfer(param_1,&local_28,param_4);
  return;
}


// ===== sdr_set_flash_addr @ 201106f8 (88 bytes)

/* regs 0x30 / 0x31 = flash address */

int sdr_set_flash_addr(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined1 auStack_110 [256];
  
  iVar1 = sdr_reg_write(param_1,param_2 | 0x30,param_3 >> 0x10,auStack_110);
  if ((iVar1 != -1) &&
     (iVar1 = sdr_reg_write(param_1,param_2 | 0x31,param_3 & 0xffff,auStack_110), iVar1 != -1)) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== sdr_wait_ready @ 20110750 (92 bytes)

/* polls reg 0x32 until the top nibble is 0 or 8 */

undefined4 sdr_wait_ready(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  while( true ) {
    bVar2 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar2) {
      return 0xffffffff;
    }
    iVar1 = sdr_reg_read(param_1,param_2 | 0x32);
    if (iVar1 == -1) break;
    if (iVar1 >> 0xc == 0 || iVar1 >> 0xc == 8) {
      return 0;
    }
    itron_dly_tsk(1);
  }
  return 0xffffffff;
}


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

