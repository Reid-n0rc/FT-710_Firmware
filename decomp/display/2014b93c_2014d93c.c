// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== dir_init_dot_entries @ 2014b93c (300 bytes)

/* Writes the "." and ".." entries (attribute 0x10) into a new directory cluster and zeroes the
   other sectors [fact] */

int dir_init_dot_entries(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_48 [32];
  undefined1 local_28;
  undefined1 local_27;
  
  iVar1 = fat_clust2sect();
  iVar4 = param_4 + 0xc0c;
  fs_memset(iVar4,0,0x200);
  fs_memset(&local_28,0x20,0xb,*(undefined4 *)(param_1 + 0x6c));
  local_28 = 0x2e;
  dirent_init(auStack_48,&local_28,0x10,param_2,param_1);
  fs_memmove(iVar4,auStack_48,0x20);
  local_27 = 0x2e;
  dirent_init(auStack_48,&local_28,0x10,param_3,param_1);
  fs_memmove(param_4 + 0xc2c,auStack_48,0x20);
  iVar2 = fs_dev_op2(param_1,iVar1,iVar4,1);
  if (iVar2 == 0) {
    fs_memset(iVar4,0,0x200);
    uVar3 = 1;
    if (1 < *(ushort *)(param_1 + 4)) {
      do {
        iVar2 = fs_dev_op2(param_1,iVar1 + uVar3,iVar4,1);
        if (iVar2 != 0) {
          return iVar2;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < *(ushort *)(param_1 + 4));
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ===== dir_create_core @ 2014ba68 (956 bytes)

/* Directory creation body behind fs_mkdir_work [inference: only caller] */

int dir_create_core(char *param_1,char *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_54;
  undefined1 auStack_50 [11];
  char local_45;
  uint local_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  
  local_54 = DAT_20808ba0;
  uVar2 = fs_toupper((int)*param_1);
  iVar3 = fs_find_drive(uVar2,&local_54);
  if (((iVar3 == 0) && (iVar3 = fs_drive_check_mounted(local_54), iVar3 == 0)) &&
     (iVar3 = fs_drive_check_writable(local_54), iVar3 == 0)) {
    param_1 = param_1 + 2;
    iVar3 = *(int *)(local_54 + 0x34);
    if (*(char *)(local_54 + 0x10) != ' ') {
      param_1 = (char *)path_next_component(param_1,param_2);
      if ((param_1 == (char *)0x0) || (*param_2 == '\0')) {
        return -1;
      }
      iVar3 = root_dir_find_locked(local_54,param_2,auStack_50,0,0,auStack_28,param_2);
      if (*param_1 == '\0') {
        if (iVar3 == 0) {
          return -2;
        }
      }
      else if ((iVar3 != 0) || (iVar3 = fs_attr_check((int)local_45,0x10), iVar3 != 0)) {
        return -4;
      }
      iVar3 = dirent_get_cluster(auStack_50,(int)*(char *)(local_54 + 0x10));
    }
    cVar1 = *param_1;
    iVar4 = 0;
    while (cVar1 != '\0') {
      param_1 = (char *)path_next_component(param_1,param_2);
      if (param_1 == (char *)0x0) {
        return -1;
      }
      if (*param_2 == '\0') {
        return -1;
      }
      iVar4 = subdir_find_locked(local_54,iVar3,param_2,auStack_50,0,0,auStack_28,auStack_24,param_2
                                );
      if (*param_1 == '\0') {
        if (iVar4 == 0) {
          return -2;
        }
      }
      else {
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = fs_attr_check((int)local_45,0x10);
        if (iVar4 != 0) {
          return -4;
        }
      }
      iVar5 = dirent_get_cluster(auStack_50,(int)*(char *)(local_54 + 0x10));
      iVar4 = iVar3;
      iVar3 = iVar5;
      cVar1 = *param_1;
    }
    fs_memset(auStack_50,0,0x20,*(undefined4 *)(local_54 + 0x6c));
    iVar3 = fat_alloc_cluster_locked(local_54,0,&local_30,param_2);
    if (iVar3 == 0) {
      if (local_30 == 0) {
        iVar3 = -0xb;
      }
      else {
        iVar3 = iVar4;
        if ((*(char *)(local_54 + 0x10) == ' ') && (*(int *)(local_54 + 0x34) == iVar4)) {
          iVar3 = 0;
        }
        iVar5 = dir_init_dot_entries(local_54,local_30,iVar3,param_2);
        if (iVar5 == 0) {
          dirent_set_cluster(auStack_50,local_30,(int)*(char *)(local_54 + 0x10));
          local_45 = 0x10;
          dirent_set_time(auStack_50,0,7);
          if (iVar4 == 0) {
            iVar5 = root_dir_find_locked(local_54,param_2,auStack_50,1,0,auStack_28,param_2);
          }
          else {
            iVar5 = subdir_find_locked(local_54,iVar4,param_2,auStack_50,1,0,auStack_28,auStack_24,
                                       param_2);
          }
          if (iVar5 == 0) {
            iVar3 = fat32_fsinfo_write_locked(local_54,param_2);
            return iVar3;
          }
          iVar3 = fat_entry_rw_locked(local_54,auStack_2c,local_30,0,0x77,param_2);
          if (iVar3 == 0) {
            if ((*(int *)(local_54 + 0x58) != 0) && (local_30 < *(uint *)(local_54 + 0x60))) {
              clmap_clear();
            }
            cVar1 = *(char *)(local_54 + 0x10);
            goto joined_r0x2014be00;
          }
        }
        else {
          iVar3 = fat_entry_rw_locked(local_54,auStack_2c,local_30,0,0x77,param_2);
          if (iVar3 == 0) {
            if ((*(int *)(local_54 + 0x58) != 0) && (local_30 < *(uint *)(local_54 + 0x60))) {
              clmap_clear();
            }
            cVar1 = *(char *)(local_54 + 0x10);
joined_r0x2014be00:
            if (cVar1 == ' ') {
              *(int *)(local_54 + 0x3c) = *(int *)(local_54 + 0x3c) + 1;
            }
            return iVar5;
          }
        }
      }
    }
  }
  return iVar3;
}


// ===== fs_mkdir_work @ 2014be24 (200 bytes)

/* Validates and normalises the path, creates the directory (0x2014BA68), fs_flush [fact] */

void fs_mkdir_work(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_10;
  
  local_10 = DAT_20808ba0;
  iVar2 = fs_check_ready();
  if (iVar2 == 0) {
    if (param_1 == 0) {
      uVar4 = 0xffffffff;
LAB_2014bee4:
      fs_set_error(uVar4,0);
      return;
    }
    iVar2 = fs_path_validate(param_1);
    if (iVar2 == 0) {
      iVar2 = fs_strlen(param_1);
      iVar3 = param_2 + 0x100c;
      fs_strncpy(iVar3,param_1,iVar2 + 1);
      sjis_map_ext_chars(iVar3);
      uVar1 = fs_toupper((int)*(char *)(param_2 + 0x100c));
      iVar2 = fs_find_drive(uVar1,&local_10);
      if ((iVar2 == 0) && (iVar2 = dir_create_core(iVar3,param_2), iVar2 == 0)) {
        uVar4 = fs_flush(local_10);
        goto LAB_2014bee4;
      }
    }
  }
  fs_set_error(iVar2,0);
  return;
}


// ===== fs_mkdir @ 2014beec (68 bytes)

/* (path): creates a directory; sd_make_dirs makes the FT-710 folders with it [fact] */

undefined4 fs_mkdir(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_mkdir_work(param_1,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== dir_open_core @ 2014bf30 (812 bytes)

/* Opens a directory by path for fs_opendir_work [inference: only caller] */

int * dir_open_core(char *param_1,int *param_2,char *param_3)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int local_54;
  undefined1 auStack_50 [11];
  byte local_45;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [8];
  
  local_54 = DAT_20808ba0;
  fs_set_error_ret(0);
  iVar2 = fs_sem2_wait();
  if (iVar2 != 0) {
    piVar3 = (int *)fs_set_error_ret(0xffffffd5,0);
    return piVar3;
  }
  if (param_2 == (int *)0x0) {
    iVar2 = 0;
    iVar5 = (int)DAT_20808b9c;
    param_2 = DAT_20808b98;
    if (0 < iVar5) {
      do {
        if ((char)param_2[1] == '\0') break;
        iVar2 = iVar2 + 1;
        param_2 = param_2 + 0x93;
      } while (iVar2 < iVar5);
    }
    if (iVar2 == iVar5) {
      fs_sem2_signal();
      iVar2 = -0xf;
      param_2 = (int *)0x0;
      goto LAB_2014c04c;
    }
  }
  *(undefined1 *)(param_2 + 1) = 0xff;
  fs_sem2_signal();
  fs_memset(auStack_50,0,0x20,*(undefined4 *)(local_54 + 0x6c));
  if (local_54 == 0) {
    *(undefined1 *)(param_2 + 1) = 0;
    param_2 = (int *)0x0;
    iVar2 = -0x11;
    goto LAB_2014c04c;
  }
  if (*param_1 == '/' || *param_1 == '\\') {
    *(undefined1 *)(param_2 + 1) = 1;
    iVar2 = 0;
    *(undefined1 *)((int)param_2 + 5) = 0;
    *param_2 = local_54;
    goto LAB_2014c04c;
  }
  uVar1 = fs_toupper();
  iVar2 = fs_find_drive(uVar1,&local_54);
  if ((iVar2 != 0) || (iVar2 = fs_drive_check_mounted(local_54), iVar2 != 0)) {
    *(undefined1 *)(param_2 + 1) = 0;
    param_2 = (int *)0x0;
    goto LAB_2014c04c;
  }
  uVar4 = fs_strlen(param_1);
  if (uVar4 < 4) {
    *(undefined1 *)(param_2 + 1) = 1;
    *(undefined2 *)((int)param_2 + 6) = 0;
    *param_2 = local_54;
    param_2[2] = *(int *)(local_54 + 0x34);
    *(undefined1 *)((int)param_2 + 5) = 1;
    if (*(char *)(local_54 + 0x10) == ' ') {
      iVar2 = fat_clust2sect();
      param_2[3] = iVar2;
      iVar2 = 0;
    }
    else {
      param_2[3] = *(int *)(local_54 + 0xc) * (uint)*(ushort *)(local_54 + 8) +
                   (uint)*(ushort *)(local_54 + 6);
      iVar2 = 0;
    }
    goto LAB_2014c04c;
  }
  param_1 = param_1 + 2;
  uVar6 = *(undefined4 *)(local_54 + 0x34);
  if (*(char *)(local_54 + 0x10) == ' ') {
LAB_2014c17c:
    if (*param_1 != '\0') {
      do {
        param_1 = (char *)path_next_component(param_1,param_3);
        if ((param_1 == (char *)0x0) || (*param_3 == '\0')) goto LAB_2014c158;
        iVar2 = subdir_find(local_54,uVar6,param_3,auStack_50,0,0,auStack_2c,auStack_30,param_3);
        if (iVar2 != 0) goto LAB_2014c24c;
        uVar6 = dirent_get_cluster(auStack_50,(int)*(char *)(local_54 + 0x10));
      } while (*param_1 != '\0');
    }
    iVar2 = dirent_get_cluster(auStack_50,(int)*(char *)(local_54 + 0x10));
    if ((local_45 & 0x10) != 0) {
      *(undefined1 *)((int)param_2 + 5) = 1;
      *(undefined1 *)(param_2 + 1) = 1;
      param_2[2] = iVar2;
      iVar2 = fat_clust2sect(local_54,iVar2);
      param_2[3] = iVar2;
      *(undefined2 *)((int)param_2 + 6) = 0;
      *param_2 = local_54;
      return param_2;
    }
  }
  else {
    param_1 = (char *)path_next_component(param_1,param_3);
    if ((param_1 == (char *)0x0) || (*param_3 == '\0')) {
LAB_2014c158:
      *(undefined1 *)(param_2 + 1) = 0;
      param_2 = (int *)0x0;
      iVar2 = -1;
      goto LAB_2014c04c;
    }
    iVar2 = root_dir_find(local_54,param_3,auStack_50,0,0,auStack_2c,param_3);
    if (iVar2 == 0) {
      uVar6 = dirent_get_cluster(auStack_50,(int)*(char *)(local_54 + 0x10));
      goto LAB_2014c17c;
    }
  }
LAB_2014c24c:
  *(undefined1 *)(param_2 + 1) = 0;
  param_2 = (int *)0x0;
  iVar2 = -4;
LAB_2014c04c:
  piVar3 = (int *)fs_set_error_ret(iVar2,param_2);
  return piVar3;
}


// ===== fs_opendir_work @ 2014c31c (424 bytes)

/* fs_opendir body: copies and normalises the path, opens the root or a subdirectory (0x2014BF30)
   [fact] */

void fs_opendir_work(int param_1,int param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 local_18 [2];
  
  iVar3 = fs_check_ready();
  if (iVar3 != 0) {
LAB_2014c394:
    fs_set_error_ret(iVar3,0);
    return;
  }
  if (param_1 == 0) {
LAB_2014c3ec:
    fs_set_error_ret(0xffffffff,0);
    return;
  }
  iVar3 = fs_strlen(param_1);
  pcVar4 = (char *)(param_2 + 0x100c);
  fs_strncpy(pcVar4,param_1,iVar3 + 1);
  sjis_map_ext_chars(pcVar4);
  iVar3 = fs_strlen(pcVar4);
  if (iVar3 == 1) {
    if (*(char *)(param_2 + 0x100c) != '/' && *(char *)(param_2 + 0x100c) != '\\') {
LAB_2014c3d0:
      fs_set_error_ret(0xfffffff4,0);
      return;
    }
  }
  else if (iVar3 == 2) {
    if ((0x19 < (int)*(char *)(param_2 + 0x100c) - 0x41U) &&
       (0x19 < (int)*(char *)(param_2 + 0x100c) - 0x61U)) goto LAB_2014c3d0;
    if (*(char *)(param_2 + 0x100d) != ':') goto LAB_2014c3ec;
  }
  else {
    iVar3 = fs_path_validate(pcVar4);
    if (iVar3 != 0) goto LAB_2014c394;
  }
  local_18[0] = DAT_20808ba0;
  if (*pcVar4 == '/' || *pcVar4 == '\\') {
    uVar5 = dir_open_core(pcVar4,0,param_2);
    uVar2 = fs_task_ctx_get();
  }
  else {
    uVar1 = fs_toupper();
    uVar6 = fs_find_drive(uVar1,local_18);
    uVar2 = (uint)uVar6;
    if (uVar2 == 0) {
      iVar3 = fs_lock_a(local_18[0],(int)((ulonglong)uVar6 >> 0x20));
      if (iVar3 == 0) {
        uVar5 = dir_open_core(pcVar4,0,param_2);
        uVar2 = fs_task_ctx_get();
        fs_unlock_a(local_18[0]);
      }
      else {
        uVar5 = 0;
        uVar2 = 0xffffffdb;
      }
    }
    else {
      uVar5 = 0;
    }
  }
  fs_set_error_ret(uVar2,uVar5);
  return;
}


// ===== fs_opendir @ 2014c410 (68 bytes)

/* (path): directory handle, 0 on error; wav_list_dir, fwfile_status_text, sdmenu_save_file,
   screen_capture_bmp [fact for callers] */

undefined4 fs_opendir(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_opendir_work(param_1,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error_ret(0xffffffe1,0);
  return uVar2;
}


// ===== dir_close @ 2014c454 (32 bytes)

/* Clears the handle's open flag +4, -13 when it was not open [fact] */

undefined4 dir_close(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 4) == '\0') {
    uVar1 = 0xfffffff3;
  }
  else {
    *(undefined1 *)(param_1 + 4) = 0;
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fs_closedir @ 2014c474 (68 bytes)

/* Checked dir_close [fact] */

void fs_closedir(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_check_ready();
  if ((iVar1 == 0) && (iVar1 = fs_dir_check(param_1), iVar1 == 0)) {
    uVar2 = dir_close(param_1);
    fs_set_error(uVar2,0);
    return;
  }
  fs_set_error(iVar1,0);
  return;
}


// ===== dirent_read @ 2014c4bc (80 bytes)

/* Copies 32-byte entry n of a directory sector (dir_sector_get) [fact] */

int dirent_read(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int local_10;
  
  local_10 = param_5 + 0xe0c;
  iVar1 = dir_sector_get(param_1,param_2,&local_10);
  if (iVar1 == 0) {
    fs_memcpy(param_4,local_10 + param_3 * 0x20,0x20);
    iVar1 = 0;
  }
  return iVar1;
}


// ===== dir_next_entry @ 2014c50c (380 bytes)

/* Advances a directory handle (+0xC sector, +6 index) to the next 32-byte entry, through the
   cluster chain [inference] */

void dir_next_entry(int *param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int extraout_r1;
  int iVar6;
  uint uVar7;
  int local_24 [2];
  
  iVar6 = *param_1;
  uVar7 = param_1[3];
  if ((char)param_1[1] == -2) {
    *(undefined1 *)(param_1 + 1) = 0xff;
    fs_set_error_ret(0);
    return;
  }
  if ((char)param_1[1] != '\x01') {
    piVar4 = (int *)0x0;
    iVar2 = -0xd;
    goto LAB_2014c574;
  }
  iVar2 = fs_drive_check_mounted(iVar6);
  if ((iVar2 != 0) ||
     (iVar2 = dirent_read(*param_1,uVar7,*(undefined2 *)((int)param_1 + 6),param_1 + 6,param_2),
     iVar2 != 0)) {
LAB_2014c5a0:
    piVar4 = (int *)0x0;
    goto LAB_2014c574;
  }
  piVar4 = param_1 + 6;
  if ((char)param_1[6] == '\0') {
    *(undefined1 *)(param_1 + 1) = 0xff;
    piVar4 = (int *)0x0;
  }
  else {
    *(short *)(param_1 + 4) = *(short *)((int)param_1 + 6);
    sVar1 = *(short *)((int)param_1 + 6) + 1;
    iVar2 = param_1[3];
    param_1[5] = iVar2;
    uVar5 = *(uint *)(iVar6 + 0x6c);
    *(short *)((int)param_1 + 6) = sVar1;
    __aeabi_uidivmod(sVar1,uVar5 >> 5);
    if (extraout_r1 == 0) {
      *(undefined2 *)((int)param_1 + 6) = 0;
      iVar3 = __aeabi_uidivmod((uint)*(ushort *)(iVar6 + 10) << 5,*(undefined4 *)(iVar6 + 0x6c));
      uVar5 = iVar3 + -1 +
              *(int *)(iVar6 + 0xc) * (uint)*(ushort *)(iVar6 + 8) + (uint)*(ushort *)(iVar6 + 6);
      if (uVar7 < uVar5) {
        param_1[3] = iVar2 + 1;
      }
      else {
        if (uVar5 != uVar7) {
          iVar2 = fat_next_sector(*param_1,uVar7,local_24,param_2);
          if (iVar2 != 0) goto LAB_2014c5a0;
          if (local_24[0] != 0) {
            param_1[3] = local_24[0];
            goto LAB_2014c678;
          }
        }
        *(undefined1 *)(param_1 + 1) = 0xfe;
      }
    }
  }
LAB_2014c678:
  iVar2 = 0;
LAB_2014c574:
  fs_set_error_ret(iVar2,piVar4);
  return;
}


// ===== dir_read_core @ 2014c688 (812 bytes)

/* readdir body: next used entry, long name (UTF-16 to 8-bit by 0x2014CC1C) [inference] */

int * dir_read_core(int *param_1,int param_2)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar10 = 0;
  iVar8 = *param_1;
  *(undefined1 *)((int)param_1 + 0x42) = 0;
  uVar11 = 0;
  fs_set_error_ret(0,0);
  uVar9 = 0;
  if (*(char *)((int)param_1 + 5) == '\0') {
    piVar3 = (int *)0x0;
    if (*param_1 != 0) {
      param_1[0xe] = (int)(param_1 + 6);
      *(undefined1 *)(param_1 + 6) = *(undefined1 *)(*param_1 + 0x11);
      *(undefined1 *)((int)param_1 + 0x42) = *(undefined1 *)(*param_1 + 0x11);
      fs_strcpy((int)param_1 + 0x19,&DWORD_2014c9b4);
      fs_strcpy((int)param_1 + 0x43,&DWORD_2014c9b4);
      *param_1 = *(int *)*param_1;
      piVar3 = param_1 + 0xe;
    }
  }
  else {
    while( true ) {
      pbVar4 = (byte *)dir_next_entry(param_1,param_2);
      piVar3 = (int *)0x0;
      if (pbVar4 == (byte *)0x0) break;
      uVar5 = (uint)*pbVar4;
      if (uVar5 == 0x2e || uVar5 == 0xe5) {
        uVar10 = 0;
        uVar9 = uVar10;
      }
      else {
        if (pbVar4[0xb] != 0xf) {
          param_1[0xe] = (int)pbVar4;
          if (uVar10 == 0) {
            dirent_name_to_str((int)param_1 + 0x42,pbVar4,(int)(char)pbVar4[0xc]);
            if ((param_1[2] == *(int *)(iVar8 + 0x34)) && (*(char *)(iVar8 + 0x10) != ' ')) {
              *(short *)(param_1 + 0x10) =
                   ((short)param_1[5] -
                   ((short)*(undefined4 *)(iVar8 + 0xc) * *(short *)(iVar8 + 8) +
                   *(short *)(iVar8 + 6))) * (short)(*(uint *)(iVar8 + 0x6c) >> 5) +
                   (short)param_1[4];
              iVar8 = 0;
            }
            else {
              uVar7 = fat_sect2clust(*param_1,param_1[5]);
              sVar2 = fat_clust2sect(*param_1,uVar7);
              *(short *)(param_1 + 0x10) =
                   ((short)param_1[5] - sVar2) * (short)(*(uint *)(iVar8 + 0x6c) >> 5) +
                   (short)param_1[4];
              iVar8 = fat_sect2clust(*param_1);
            }
            param_1[0xf] = iVar8;
          }
          cVar1 = (char)uVar10;
          do {
            if (uVar10 == 0) {
              return param_1 + 0xe;
            }
            cVar1 = cVar1 + -1;
            uVar10 = (uint)cVar1;
            uVar9 = 0;
            do {
              iVar8 = ucs2_to_ascii_char((int)param_1 + uVar11 + 0x42,
                                         param_2 + uVar10 * 0x1a + uVar9 + 0x1418);
              if ((iVar8 == 0) || (*(char *)((int)param_1 + uVar11 + 0x42) == '\0')) break;
              uVar11 = iVar8 + uVar11 & 0xffff;
              uVar9 = uVar9 + 2 & 0xff;
            } while (uVar9 < 0x19);
            *(undefined1 *)((int)param_1 + uVar11 + 0x42) = 0;
          } while( true );
        }
        if (uVar9 == 0) {
LAB_2014c78c:
          if (0x13 < (int)uVar10) goto LAB_2014c780;
          if (uVar10 == 0) goto LAB_2014c79c;
          goto LAB_2014c83c;
        }
        if ((uVar5 & 0xffffffbf) == uVar9 - 1) {
          uVar9 = uVar9 - 1 & 0xff;
          goto LAB_2014c78c;
        }
LAB_2014c780:
        uVar9 = 0;
        uVar10 = 0;
LAB_2014c79c:
        if ((*pbVar4 & 0x40) != 0) {
          uVar9 = uVar5 & 0xffffffbf;
          if ((param_1[2] == *(int *)(iVar8 + 0x34)) && (*(char *)(iVar8 + 0x10) != ' ')) {
            *(short *)(param_1 + 0x10) =
                 ((short)param_1[5] -
                 ((short)*(undefined4 *)(iVar8 + 0xc) * *(short *)(iVar8 + 8) +
                 *(short *)(iVar8 + 6))) * (short)(*(uint *)(iVar8 + 0x6c) >> 5) + (short)param_1[4]
            ;
            iVar6 = 0;
          }
          else {
            uVar7 = fat_sect2clust(*param_1,param_1[5]);
            sVar2 = fat_clust2sect(*param_1,uVar7);
            *(short *)(param_1 + 0x10) =
                 ((short)param_1[5] - sVar2) * (short)(*(uint *)(iVar8 + 0x6c) >> 5) +
                 (short)param_1[4];
            iVar6 = fat_sect2clust(*param_1);
          }
          param_1[0xf] = iVar6;
LAB_2014c83c:
          iVar6 = param_2 + uVar10 * 0x1a;
          fs_memcpy(iVar6 + 0x1418,pbVar4 + 1,10);
          fs_memcpy(iVar6 + 0x1422,pbVar4 + 0xe,0xc);
          fs_memcpy(iVar6 + 0x142e,pbVar4 + 0x1c,4);
          uVar10 = (uint)(char)((char)uVar10 + '\x01');
        }
      }
    }
  }
  return piVar3;
}


// ===== fs_readdir_work @ 2014ca08 (148 bytes)

/* Checked readdir under fs_lock_a [fact] */

undefined4 fs_readdir_work(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_lr;
  
  iVar2 = fs_check_ready();
  if ((iVar2 == 0) && (iVar2 = fs_dir_check(param_1), iVar2 == 0)) {
    uVar3 = *param_1;
    iVar2 = fs_lock_a(uVar3);
    if (iVar2 != 0) {
      uVar3 = fs_set_error_ret(0xffffffdb,0);
      return uVar3;
    }
    uVar1 = dir_read_core(param_1,param_2,extraout_r2,extraout_r3,unaff_r4,unaff_r5,unaff_r6,
                          unaff_lr);
    fs_unlock_a(uVar3);
    return uVar1;
  }
  uVar3 = fs_set_error_ret(iVar2,0);
  return uVar3;
}


// ===== fs_readdir @ 2014ca4c (68 bytes)

/* (dir): next directory entry or 0 at the end; callers read the attribute at entry +0x0B [fact] */

undefined4 fs_readdir(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_readdir_work(param_1,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error_ret(0xffffffe1,0);
  return uVar2;
}


// ===== sjis_is_lead @ 2014ca90 (40 bytes)

/* 1 for Shift-JIS lead bytes 0x81..0x9F and 0xE0..0xFC [fact] */

undefined4 sjis_is_lead(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 - 0x81U < 0x1f) || (param_1 - 0xe0U < 0x1d)) {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== sjis_to_ucs2_char @ 2014cab8 (204 bytes)

/* Shift-JIS character to UTF-16 (byte-swapped) via the tables 0x20420756 (0x81..0x9F) and
   0x204244D0 (0xE0..0xFC); ASCII and half-width kana directly [fact] */

uint sjis_to_ucs2_char(byte *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1;
  if (uVar1 - 0x20 < 0x5f) {
    if (uVar1 == 0x5c) {
      uVar1 = 0xa500;
    }
    else {
      uVar1 = uVar1 << 8;
    }
  }
  else {
    if (uVar1 - 0x81 < 0x1f) {
      return (uint)(ushort)(&DAT_20420756)[((uint)param_1[1] + uVar1 * 0x100) - 0x8140 & 0xffff] *
             0x100 + (uint)((ushort)(&DAT_20420756)
                                    [((uint)param_1[1] + uVar1 * 0x100) - 0x8140 & 0xffff] >> 8) &
             0xffff;
    }
    if (uVar1 - 0xa1 < 0x3f) {
      return (uVar1 + 0xfec0 & 0xff) * 0x100 + ((uVar1 + 0xfec0 & 0xffff) >> 8);
    }
    if (uVar1 - 0xe0 < 0x1d) {
      return (uint)(ushort)(&DAT_204244d0)[((uint)param_1[1] + uVar1 * 0x100) - 0xe040 & 0xffff] *
             0x100 + (uint)((ushort)(&DAT_204244d0)
                                    [((uint)param_1[1] + uVar1 * 0x100) - 0xe040 & 0xffff] >> 8) &
             0xffff;
    }
    uVar1 = 0xffff;
  }
  return uVar1;
}


// ===== sjis_to_ucs2_str @ 2014cb84 (152 bytes)

/* Shift-JIS string to UTF-16, returns the length, sets *flag when there is a double-byte character
   [fact] */

int sjis_to_ucs2_str(char *param_1,undefined1 *param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = *param_1;
  iVar3 = 0;
  while( true ) {
    if (cVar1 == '\0') {
      *param_2 = 0;
      param_2[1] = 0;
      return iVar3;
    }
    iVar2 = sjis_is_lead(*param_1);
    if (iVar2 == 0) {
      iVar2 = sjis_to_ucs2_char(param_1);
      param_1 = param_1 + 1;
    }
    else {
      iVar2 = sjis_to_ucs2_char(param_1);
      *param_3 = 1;
      param_1 = param_1 + 2;
    }
    *param_2 = (char)((uint)iVar2 >> 8);
    param_2[1] = (char)iVar2;
    param_2 = param_2 + 2;
    if (iVar2 == 0xffff) break;
    cVar1 = *param_1;
    iVar3 = iVar3 + 1;
  }
  return -99;
}


// ===== ucs2_to_ascii_char @ 2014cc1c (332 bytes)

/* One UTF-16 character to 8 bits, same mapping as fs_ucs2_to_ascii_upper without upper-casing
   [fact] */

undefined4 ucs2_to_ascii_char(byte *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = *param_2;
  uVar3 = (uint)bVar1;
  uVar2 = uVar3 + (uint)param_2[1] * 0x100;
  if (uVar2 == 0) {
    *param_1 = 0;
    return 1;
  }
  if (uVar2 == 0xa5) {
    *param_1 = 0x5c;
    return 1;
  }
  if (uVar2 == 0x203e) {
    *param_1 = 0x7e;
    return 1;
  }
  if (((param_2[1] == 0xff) && (0x60 < uVar3)) && (uVar3 < 0xa0)) {
    *param_1 = bVar1 + 0x40;
  }
  else {
    if (0x5e < uVar2 - 0x20) {
      uVar3 = 0;
      do {
        if ((ushort)(&DAT_20420756)[uVar3] == uVar2) {
          *param_1 = (byte)(uVar3 + 0x8140 >> 8);
          param_1[1] = (byte)(uVar3 + 0x8140);
          return 2;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < 0x1ebd);
      uVar3 = 0;
      do {
        if ((ushort)(&DAT_204244d0)[uVar3] == uVar2) {
          *param_1 = (byte)(uVar3 + 0xe040 >> 8);
          param_1[1] = (byte)(uVar3 + 0xe040);
          return 2;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < 0x1cbd);
      return 0;
    }
    *param_1 = bVar1;
  }
  return 1;
}


// ===== sjis_map_ext_chars @ 2014cd68 (652 bytes)

/* Rewrites NEC/IBM extension codes in a path (0xED40.., 0x8790..) to one form before a lookup
   [inference from the ranges] */

void sjis_map_ext_chars(byte *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *extraout_r3;
  undefined2 *puVar4;
  int extraout_r12;
  bool bVar5;
  
  bVar1 = *param_1;
joined_r0x2014cd78:
  if (bVar1 == 0) {
    return;
  }
  iVar2 = sjis_is_lead(*param_1);
  param_1 = extraout_r3;
  if (iVar2 != 0) {
    uVar3 = (uint)extraout_r3[1] + (uint)*extraout_r3 * 0x100;
    if (0xc < uVar3 - 0x8790) {
      if (uVar3 - 0xed40 < 0xbd) {
        if ((uVar3 - 0xed40 < 0x23) || (uVar3 - 0xed80 < 0x61)) {
          *extraout_r3 = (byte)(uVar3 + extraout_r12 >> 8);
          extraout_r3[1] = (byte)(uVar3 + extraout_r12);
        }
        else {
          if (0x81 < uVar3 - 0xede1) {
LAB_2014cea4:
            uVar3 = uVar3 + 0xd1d;
            *extraout_r3 = (byte)(uVar3 >> 8);
            goto LAB_2014ceb0;
          }
LAB_2014cec8:
          *extraout_r3 = (byte)(uVar3 + 0xd5f >> 8);
          extraout_r3[1] = (byte)(uVar3 + 0xd5f);
        }
        goto LAB_2014cfe0;
      }
      if (0xbc < uVar3 - 0xee40) {
        if (uVar3 - 0xfa4a < 0x12) {
          if (uVar3 - 0xfa4a < 10) {
            uVar3 = uVar3 - 0x72f6;
            *extraout_r3 = (byte)(uVar3 >> 8);
            goto LAB_2014ceb0;
          }
          puVar4 = &DAT_2042073e;
          iVar2 = 0;
          bVar5 = true;
          while (bVar5) {
            if ((ushort)(&DAT_2042073e)[iVar2 * 2] == uVar3) goto LAB_2014cf4c;
            iVar2 = iVar2 + 1;
            bVar5 = (&DAT_2042073e)[iVar2 * 2] != 0;
          }
        }
        goto LAB_2014cfe0;
      }
      if ((0x22 < uVar3 - 0xee40) && (0x60 < uVar3 - 0xee80)) {
        if (uVar3 - 0xee63 < 0x1c) goto LAB_2014cea4;
        if (uVar3 - 0xeee1 < 0xc) goto LAB_2014cec8;
        if (uVar3 - 0xeeef < 10) {
          *extraout_r3 = (byte)(uVar3 + 0xb51 >> 8);
          extraout_r3[1] = (byte)(uVar3 + 0xb51);
        }
        else if (((uVar3 != 0xee7f) && (uVar3 != 0xeeed)) && (uVar3 != 0xeeee)) {
          iVar2 = 0;
          puVar4 = &DAT_2042072a;
          do {
            if ((ushort)(&DAT_2042072a)[iVar2 * 2] == uVar3) goto LAB_2014cf4c;
            iVar2 = iVar2 + 1;
          } while ((&DAT_2042072a)[iVar2 * 2] != 0);
        }
        goto LAB_2014cfe0;
      }
      uVar3 = uVar3 + extraout_r12;
      *extraout_r3 = (byte)(uVar3 >> 8);
      goto LAB_2014ceb0;
    }
    iVar2 = 0;
    do {
      if ((ushort)(&DAT_20420702)[iVar2 * 2] == uVar3) {
        *extraout_r3 = (byte)((ushort)(&DAT_20420704)[iVar2 * 2] >> 8);
        uVar3 = (uint)*(byte *)(&DAT_20420704 + iVar2 * 2);
        goto LAB_2014ceb0;
      }
      iVar2 = iVar2 + 1;
    } while ((&DAT_20420702)[iVar2 * 2] != 0);
    goto LAB_2014cfe0;
  }
  goto LAB_2014cfe4;
LAB_2014cf4c:
  *extraout_r3 = (byte)((ushort)puVar4[iVar2 * 2 + 1] >> 8);
  uVar3 = (uint)*(byte *)(puVar4 + iVar2 * 2 + 1);
LAB_2014ceb0:
  extraout_r3[1] = (byte)uVar3;
LAB_2014cfe0:
  param_1 = extraout_r3 + 1;
LAB_2014cfe4:
  param_1 = param_1 + 1;
  bVar1 = *param_1;
  goto joined_r0x2014cd78;
}


// ===== fs_wstrcpy_len @ 2014cff4 (92 bytes)

/* Copies a 0-terminated UTF-16 string, returns its length in characters, sets *flag = 1 [fact] */

int fs_wstrcpy_len(char *param_1,char *param_2,undefined1 *param_3)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (*param_1 != '\0' || (param_1[1] != '\0')); param_1 = param_1 + 2) {
    iVar1 = iVar1 + 1;
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2 = param_2 + 2;
  }
  *param_2 = '\0';
  param_2[1] = '\0';
  *param_3 = 1;
  return iVar1;
}


// ===== fs_ucs2_to_ascii_upper @ 2014d050 (196 bytes)

/* UTF-16 name to 8-bit upper case: 0x00A5 -> '\\', 0x203E -> '~', U+FF61..FF9F -> half-width kana
   0xA1..0xDF, 0 for any other character outside 0x20..0x7E [fact] */

int fs_ucs2_to_ascii_upper(char *param_1,byte *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = 0;
  pcVar4 = param_1;
  do {
    uVar3 = (uint)*param_2;
    iVar2 = uVar3 + (uint)param_2[1] * 0x100;
    if (iVar2 == 0) {
      *pcVar4 = '\0';
      return iVar6;
    }
    if (iVar2 == 0xa5) {
      *pcVar4 = '\\';
    }
    else if (iVar2 == 0x203e) {
      *pcVar4 = '~';
    }
    else {
      if (((param_2[1] == 0xff) && (0x60 < uVar3)) && (uVar3 < 0xa0)) {
        cVar1 = *param_2 + 0x40;
      }
      else {
        if (0x5e < iVar2 - 0x20U) {
          *param_1 = '\0';
          return 0;
        }
        cVar1 = fs_toupper((int)(char)*param_2);
      }
      *pcVar4 = cVar1;
    }
    iVar5 = iVar5 + 1;
    pcVar4 = pcVar4 + 1;
    param_2 = param_2 + 2;
    iVar6 = iVar6 + 1;
  } while (iVar5 < 0xc);
  return iVar6;
}


// ===== fs_memcpy @ 2014d128 (32 bytes)

/* (dst, src, n): byte copy [fact] */

void fs_memcpy(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== fs_memset @ 2014d148 (124 bytes)

/* (dst, c, n): word fill for aligned 0x200-byte blocks, else bytes [fact] */

void fs_memset(undefined4 *param_1,undefined1 param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (((uint)param_1 & 3) == 0 && param_3 == param_4) {
    param_4 = param_4 >> 5;
    uVar1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    if (param_4 != 0) {
      do {
        param_4 = param_4 - 1;
        *param_1 = uVar1;
        param_1[1] = uVar1;
        param_1[2] = uVar1;
        param_1[3] = uVar1;
        param_1[4] = uVar1;
        param_1[5] = uVar1;
        param_1[6] = uVar1;
        param_1[7] = uVar1;
        param_1 = param_1 + 8;
      } while (param_4 != 0);
      return;
    }
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)param_1 = param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
  }
  return;
}


// ===== fs_memmove @ 2014d1c4 (92 bytes)

/* Byte copy that copies backwards when the areas overlap [fact] */

void fs_memmove(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = param_2 + param_3;
  puVar1 = param_1 + param_3;
  if (param_2 < param_1 && param_1 < puVar2) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      *puVar1 = *puVar2;
      puVar2 = puVar2 + -1;
      puVar1 = puVar1 + -1;
    }
  }
  else if (param_3 != 0) {
    do {
      param_3 = param_3 + -1;
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (param_3 != 0);
    return;
  }
  return;
}


// ===== fs_strlen @ 2014d220 (40 bytes)

/* Byte-wise string length [fact] */

int fs_strlen(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    cVar1 = *param_1;
  }
  return iVar2;
}


// ===== fs_wstrlen_bytes @ 2014d248 (40 bytes)

/* Length of a UTF-16 string in bytes [fact] */

int fs_wstrlen_bytes(short *param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  sVar1 = *param_1;
  while (sVar1 != 0) {
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    sVar1 = *param_1;
  }
  return iVar2 << 1;
}


// ===== fs_strcpy @ 2014d270 (24 bytes)

/* Byte string copy including the terminator [fact] */

void fs_strcpy(char *param_1,char *param_2)

{
  char cVar1;
  
  do {
    cVar1 = *param_2;
    *param_1 = cVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}


// ===== fs_strncpy @ 2014d288 (68 bytes)

/* Copies up to n bytes, pads with 0 after the terminator [fact] */

void fs_strncpy(char *param_1,char *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 == 0) {
    return;
  }
  do {
    uVar1 = uVar1 + 1;
    if (*param_2 == '\0') {
      *param_1 = '\0';
    }
    else {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
    }
    param_1 = param_1 + 1;
  } while (uVar1 < param_3);
  return;
}


// ===== fs_wstrncpy @ 2014d2cc (108 bytes)

/* UTF-16 version of fs_strncpy [fact] */

void fs_wstrncpy(char *param_1,char *param_2,uint param_3)

{
  char *pcVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      if ((*param_2 == '\0') && (param_2[1] == '\0')) {
        *param_1 = '\0';
        param_1[1] = '\0';
      }
      else {
        *param_1 = *param_2;
        pcVar1 = param_2 + 1;
        param_2 = param_2 + 2;
        param_1[1] = *pcVar1;
      }
      param_1 = param_1 + 2;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_3);
    return;
  }
  return;
}


// ===== fs_strchr @ 2014d338 (36 bytes)

/* First occurrence of a character, 0 when missing [fact] */

char * fs_strchr(char *param_1,char param_2)

{
  while( true ) {
    if (*param_1 == param_2) {
      return param_1;
    }
    if (*param_1 == '\0') break;
    param_1 = param_1 + 1;
  }
  return (char *)0x0;
}


// ===== fs_toupper @ 2014d35c (24 bytes)

/* 'a'..'z' -> 'A'..'Z' [fact] */

int fs_toupper(int param_1)

{
  if (param_1 - 0x61U < 0x1a) {
    param_1 = (int)(char)((char)param_1 + -0x20);
  }
  return param_1;
}


// ===== fs_tolower @ 2014d374 (24 bytes)

/* 'A'..'Z' -> 'a'..'z' (pair of fs_toupper) [fact] */

int fs_tolower(int param_1)

{
  if (param_1 - 0x41U < 0x1a) {
    param_1 = (int)(char)((char)param_1 + ' ');
  }
  return param_1;
}


// ===== fs_stricmp @ 2014d38c (108 bytes)

/* Case-insensitive string compare (fs_toupper on both) [fact] */

int fs_stricmp(byte *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  byte *extraout_r2;
  byte *extraout_r3;
  undefined4 extraout_r12;
  
  do {
    bVar1 = *param_1;
    iVar4 = (int)(char)(bVar1 | *param_2);
    if (iVar4 == 0) {
      return 0;
    }
    if ((char)bVar1 == 0) {
      return -1;
    }
    if (*param_2 == 0) {
      return 1;
    }
    cVar2 = fs_toupper((int)(char)bVar1,iVar4,param_2 + 1,param_1 + 1);
    cVar3 = fs_toupper(extraout_r12);
    param_2 = extraout_r2;
    param_1 = extraout_r3;
  } while ((char)(cVar2 - cVar3) == 0);
  return (int)(char)(cVar2 - cVar3);
}


// ===== fs_wstricmp @ 2014d3f8 (148 bytes)

/* Case-insensitive compare of UTF-16 strings (folds only characters < 0x100) [fact] */

int fs_wstricmp(ushort *param_1,ushort *param_2)

{
  char *pcVar1;
  char *pcVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  int extraout_r2;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *extraout_r12;
  undefined8 uVar11;
  
  puVar8 = param_1;
  puVar9 = param_2;
  do {
    uVar3 = *puVar8;
    puVar10 = puVar9 + 1;
    uVar4 = *puVar9;
    if (uVar3 == 0 && uVar4 == 0) {
      return 0;
    }
    if (uVar3 == 0) {
      return -1;
    }
    if (uVar4 == 0) {
      return 1;
    }
    pcVar1 = (char *)((int)param_1 + 1);
    pcVar2 = (char *)((int)param_2 + 1);
    uVar5 = *param_1;
    param_1 = param_1 + 1;
    uVar6 = *param_2;
    param_2 = param_2 + 1;
    if (*pcVar1 == '\0' && *pcVar2 == '\0') {
      uVar11 = fs_toupper((int)(char)uVar5);
      iVar7 = fs_toupper((int)(char)uVar6,(int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      iVar7 = extraout_r2 - iVar7;
      puVar10 = extraout_r12;
    }
    else {
      iVar7 = (uint)uVar3 - (uint)uVar4;
    }
    puVar8 = puVar8 + 1;
    puVar9 = puVar10;
  } while (iVar7 == 0);
  return iVar7;
}


// ===== fs_strnicmp @ 2014d48c (124 bytes)

/* Case-insensitive compare of at most n bytes [fact] */

int fs_strnicmp(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  uint extraout_r2;
  int extraout_r3;
  char *extraout_r12;
  
  if (param_3 != 0) {
    do {
      cVar2 = *param_2;
      if (*param_1 == '\0' && cVar2 == '\0') {
        return 0;
      }
      if (*param_1 == '\0') {
        return -1;
      }
      if (cVar2 == 0) {
        return 1;
      }
      cVar1 = fs_toupper();
      cVar2 = fs_toupper((int)cVar2);
      if ((char)(cVar1 - cVar2) != 0) {
        return (int)(char)(cVar1 - cVar2);
      }
      param_1 = param_1 + 1;
      param_2 = extraout_r12;
    } while (extraout_r3 + 1U < extraout_r2);
  }
  return 0;
}


// ===== fs_wstrnicmp @ 2014d508 (172 bytes)

/* UTF-16 version of fs_strnicmp [fact] */

int fs_wstrnicmp(ushort *param_1,ushort *param_2,uint param_3)

{
  char *pcVar1;
  char *pcVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  uint extraout_r2;
  int extraout_r3;
  ushort *puVar8;
  ushort *puVar9;
  uint uVar10;
  
  uVar10 = 0;
  puVar8 = param_2;
  puVar9 = param_1;
  if (param_3 != 0) {
    while( true ) {
      uVar3 = *puVar9;
      uVar4 = *puVar8;
      if (uVar3 == 0 && uVar4 == 0) break;
      if (uVar3 == 0) {
        return -1;
      }
      if (uVar4 == 0) {
        return 1;
      }
      pcVar1 = (char *)((int)param_1 + 1);
      pcVar2 = (char *)((int)param_2 + 1);
      uVar5 = *param_1;
      param_1 = param_1 + 1;
      uVar6 = *param_2;
      param_2 = param_2 + 1;
      if (*pcVar1 == '\0' && *pcVar2 == '\0') {
        fs_toupper((int)(char)uVar5);
        iVar7 = fs_toupper((int)(char)uVar6);
        iVar7 = extraout_r3 - iVar7;
        param_3 = extraout_r2;
      }
      else {
        iVar7 = (uint)uVar3 - (uint)uVar4;
      }
      if (iVar7 != 0) {
        return iVar7;
      }
      uVar10 = uVar10 + 1;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
      if (param_3 <= uVar10) {
        return 0;
      }
    }
  }
  return 0;
}


// ===== fs_strlwr_sjis @ 2014d5b4 (76 bytes)

/* Lower-cases a string in place, skipping Shift-JIS pairs [fact] */

byte * fs_strlwr_sjis(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = param_1;
  do {
    iVar1 = sjis_is_lead(*pbVar2);
    if (iVar1 == 0) {
      if (*pbVar2 - 0x41 < 0x1a) {
        *pbVar2 = *pbVar2 + 0x20;
      }
    }
    else {
      pbVar2 = pbVar2 + 1;
    }
    pbVar2 = pbVar2 + 1;
  } while (*pbVar2 != 0);
  return param_1;
}


// ===== fs_atoi @ 2014d600 (48 bytes)

/* Decimal digits to int (no sign, no checks) [fact] */

int fs_atoi(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != 0) {
    param_1 = param_1 + 1;
    iVar2 = (int)cVar1 + iVar2 * 10 + -0x30;
    cVar1 = *param_1;
  }
  return iVar2;
}


// ===== fs_utoa_digits @ 2014d630 (72 bytes)

/* Recursive digit writer for radix 2..36 ('a'.. for 10+), returns the end pointer [fact] */

char * fs_utoa_digits(uint param_1,char *param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  char extraout_r1;
  
  uVar2 = __aeabi_uidivmod(param_1,param_3);
  if (uVar2 != 0) {
    param_2 = fs_utoa_digits(uVar2,param_2,param_3);
  }
  if (extraout_r1 < '\n') {
    cVar1 = extraout_r1 + '0';
  }
  else {
    cVar1 = extraout_r1 + 'W';
  }
  *param_2 = cVar1;
  return param_2 + 1;
}


// ===== fs_itoa @ 2014d678 (80 bytes)

/* (value, buf, radix 2..36): '-' for negative decimal, 0-terminated; empty for a bad radix [fact]
    */

char * fs_itoa(uint param_1,char *param_2,uint param_3)

{
  char *pcVar1;
  
  if (param_3 - 2 < 0x23) {
    pcVar1 = param_2;
    if ((param_3 == 10) && ((int)param_1 < 0)) {
      *param_2 = '-';
      pcVar1 = param_2 + 1;
      param_1 = -param_1;
    }
    pcVar1 = fs_utoa_digits(param_1,pcVar1,param_3);
    *pcVar1 = '\0';
  }
  else {
    *param_2 = '\0';
  }
  return param_2;
}


// ===== fs_stricmp_sjis @ 2014d6c8 (168 bytes)

/* Case-insensitive compare that compares the trail byte of a Shift-JIS pair exactly (sjis_is_lead)
   [fact] */

int fs_stricmp_sjis(char *param_1,char *param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  char extraout_r2;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined8 uVar8;
  
  bVar1 = false;
  while( true ) {
    pcVar7 = param_1 + 1;
    iVar5 = (int)*param_1;
    pcVar6 = param_2 + 1;
    cVar2 = *param_2;
    iVar4 = (int)cVar2;
    if (*param_1 == '\0' && cVar2 == '\0') {
      return 0;
    }
    if (iVar5 == 0) break;
    if (iVar4 == 0) {
      return 1;
    }
    param_2 = pcVar6;
    param_1 = pcVar7;
    if (bVar1) {
      bVar1 = false;
      if (iVar5 != iVar4) {
        return -1;
      }
    }
    else {
      iVar3 = sjis_is_lead(cVar2);
      if (iVar3 == 0) {
        uVar8 = fs_toupper(iVar5);
        cVar2 = fs_toupper(iVar4,(int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        if ((char)(extraout_r2 - cVar2) != 0) {
          return (int)(char)(extraout_r2 - cVar2);
        }
      }
      else {
        bVar1 = true;
        if (iVar5 != iVar4) {
          return -1;
        }
      }
    }
  }
  return -1;
}


// ===== fs_strnicmp_sjis @ 2014d770 (196 bytes)

/* Length-limited version of fs_stricmp_sjis [fact] */

int fs_strnicmp_sjis(char *param_1,char *param_2,uint param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  char extraout_r2;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  
  bVar1 = false;
  uVar6 = 0;
  if (param_3 != 0) {
    do {
      iVar5 = (int)*param_1;
      cVar2 = *param_2;
      iVar4 = (int)cVar2;
      if (*param_1 == '\0' && cVar2 == '\0') {
        return 0;
      }
      if (iVar5 == 0) {
        return -1;
      }
      if (iVar4 == 0) {
        return 1;
      }
      if (bVar1) {
        bVar1 = false;
joined_r0x2014d7ec:
        if (iVar5 != iVar4) {
          return -1;
        }
      }
      else {
        iVar3 = sjis_is_lead(cVar2);
        if (iVar3 != 0) {
          bVar1 = true;
          goto joined_r0x2014d7ec;
        }
        uVar7 = fs_toupper(iVar5);
        cVar2 = fs_toupper(iVar4,(int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
        if ((char)(extraout_r2 - cVar2) != 0) {
          return (int)(char)(extraout_r2 - cVar2);
        }
      }
      uVar6 = uVar6 + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (uVar6 < param_3);
  }
  return 0;
}


// ===== fs_atoi_2 @ 2014d834 (48 bytes)

/* Second identical copy of fs_atoi [fact] */

int fs_atoi_2(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != 0) {
    param_1 = param_1 + 1;
    iVar2 = (int)cVar1 + iVar2 * 10 + -0x30;
    cVar1 = *param_1;
  }
  return iVar2;
}


// ===== fs_itoa_2 @ 2014d864 (80 bytes)

/* Second identical copy of fs_itoa [fact] */

char * fs_itoa_2(uint param_1,char *param_2,uint param_3)

{
  char *pcVar1;
  
  if (param_3 - 2 < 0x23) {
    pcVar1 = param_2;
    if ((param_3 == 10) && ((int)param_1 < 0)) {
      *param_2 = '-';
      pcVar1 = param_2 + 1;
      param_1 = -param_1;
    }
    pcVar1 = fs_utoa_digits(param_1,pcVar1,param_3);
    *pcVar1 = '\0';
  }
  else {
    *param_2 = '\0';
  }
  return param_2;
}


// ===== FUN_2014d8b4 @ 2014d8b4 (20 bytes)

int FUN_2014d8b4(undefined4 param_1)

{
  return (int)(char)((char)((uint)param_1 >> 8) + (char)param_1);
}


// ===== fs_wstr_store_le @ 2014d8c8 (36 bytes)

/* Copies a 0-terminated UTF-16 string to bytes, little-endian, including the terminator [fact] */

void fs_wstr_store_le(undefined1 *param_1,short *param_2)

{
  short sVar1;
  
  do {
    sVar1 = *param_2;
    *param_1 = (char)sVar1;
    param_1[1] = (char)((ushort)sVar1 >> 8);
    param_1 = param_1 + 2;
    sVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (sVar1 != 0);
  return;
}


// ===== fat_st_word @ 2014d8ec (20 bytes)

/* Stores a 16-bit value little-endian at an unaligned address (pair of fat_ld_word) [fact] */

void fat_st_word(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  return;
}


// ===== fat_ld_word @ 2014d900 (24 bytes)

/* 16-bit field read from an on-disk structure (fat_mount) [fact] */

undefined2 fat_ld_word(undefined2 *param_1)

{
  return *param_1;
}


// ===== fat_st_dword @ 2014d918 (36 bytes)

/* Stores a 32-bit value little-endian at an unaligned address (pair of fat_ld_dword) [fact] */

void fat_st_dword(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  param_1[2] = (char)((uint)param_2 >> 0x10);
  param_1[3] = (char)((uint)param_2 >> 0x18);
  return;
}


// ===== fat_ld_dword @ 2014d93c (32 bytes)

/* 32-bit field read from an on-disk structure (fat_mount) [fact] */

undefined4 fat_ld_dword(undefined4 *param_1)

{
  return *param_1;
}

