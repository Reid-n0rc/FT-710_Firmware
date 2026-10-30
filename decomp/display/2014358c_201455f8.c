// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== fs_fwrite_work @ 2014358c (240 bytes)

/* fs_fwrite body: handle checks (fs_file_check, write-protect) then file_write_locked [inference:
   only caller fs_fwrite] */

undefined4
fs_fwrite_work(int param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = fs_check_ready();
  if ((iVar1 != 0) || (iVar1 = fs_file_check(param_4), iVar1 != 0)) {
    fs_set_error(iVar1,0);
    return 0;
  }
  if (param_1 != 0) {
    if (*(char *)((int)param_4 + 0x442) == '\x01') {
      fs_set_error(0xfffffffb,param_4);
      return 0;
    }
    if (param_2 == 0 || param_3 == 0) {
      fs_set_error(0,param_4);
      return 0;
    }
    uVar2 = __aeabi_uidivmod(0xffffffff,param_2);
    if (param_3 <= uVar2) {
      iVar1 = fs_drive_check_writable(*param_4);
      if (iVar1 != 0) {
        fs_set_error(iVar1,param_4);
        return 0;
      }
      uVar3 = file_write_locked(param_1,param_2,param_3,param_4,param_5);
      return uVar3;
    }
  }
  fs_set_error(0xfffffff3,param_4);
  return 0;
}


// ===== fs_fwrite @ 2014367c (96 bytes)

uint fs_fwrite(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fwrite_work(param_1,param_2,param_3,param_4,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  fs_set_error(0xffffffe1,0);
  return 0;
}


// ===== fs_fseek_work @ 201436dc (116 bytes)

/* fs_fseek body with the handle check [inference: only caller fs_fseek] */

void fs_fseek_work(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_check_ready();
  if ((iVar1 == 0) && (iVar1 = fs_file_check(param_1), iVar1 == 0)) {
    if (2 < param_3) {
      fs_set_error(0xfffffff3,param_1);
      return;
    }
    uVar2 = FUN_20140be8(param_1,param_2,param_3,param_4);
    fs_set_error(uVar2,param_1);
    return;
  }
  fs_set_error(iVar1,0);
  return;
}


// ===== fs_fseek @ 20143750 (84 bytes)

uint fs_fseek(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_fseek_work(param_1,param_2,param_3,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== file_remove_core @ 201437a4 (692 bytes)

/* Removes a directory entry and frees its clusters [inference: chain fs_remove -> fs_remove_work ->
   here] */

int file_remove_core(char *param_1,char *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4c;
  undefined1 auStack_48 [11];
  byte local_3d;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  
  iVar5 = 0;
  local_4c = DAT_20808ba0;
  iVar4 = DAT_20808b90;
  if (0 < DAT_20808b94) {
    do {
      iVar3 = fs_stricmp_sjis_fold(iVar4 + 0x23c,param_1);
      if (iVar3 == 0) {
        return -7;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x450;
    } while (iVar5 < DAT_20808b94);
  }
  uVar2 = fs_toupper((int)*param_1);
  iVar4 = fs_find_drive(uVar2,&local_4c);
  if (((iVar4 == 0) && (iVar4 = fs_drive_check_mounted(local_4c), iVar4 == 0)) &&
     (iVar4 = fs_drive_check_writable(local_4c), iVar4 == 0)) {
    fs_memset(auStack_48,0,0x20,*(undefined4 *)(local_4c + 0x6c));
    param_1 = param_1 + 2;
    iVar4 = *(int *)(local_4c + 0x34);
    if (*(char *)(local_4c + 0x10) != ' ') {
      param_1 = (char *)path_next_component(param_1,param_2);
      if ((param_1 == (char *)0x0) || (*param_2 == '\0')) {
        return -1;
      }
      iVar4 = root_dir_find_locked(local_4c,param_2,auStack_48,0,0,auStack_28,param_2);
      if (iVar4 != 0) {
        if (*param_1 == '\0') {
          return -3;
        }
        return -4;
      }
      iVar4 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10));
    }
    cVar1 = *param_1;
    iVar5 = 0;
    while (cVar1 != '\0') {
      param_1 = (char *)path_next_component(param_1,param_2);
      if (param_1 == (char *)0x0) {
        return -1;
      }
      if (*param_2 == '\0') {
        return -1;
      }
      iVar5 = subdir_find_locked(local_4c,iVar4,param_2,auStack_48,0,0,auStack_28,auStack_24,param_2
                                );
      if (iVar5 != 0) {
        if (*param_1 != '\0' || iVar5 != -4) {
          return iVar5;
        }
        return -3;
      }
      iVar3 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10));
      iVar5 = iVar4;
      iVar4 = iVar3;
      cVar1 = *param_1;
    }
    if ((local_3d & 0x10) != 0) {
      return -3;
    }
    if (iVar5 == 0) {
      iVar4 = root_dir_find_locked(local_4c,param_2,auStack_48,2,0,auStack_28,param_2);
    }
    else {
      iVar4 = subdir_find_locked(local_4c,iVar5,param_2,auStack_48,2,0,auStack_28,auStack_24,param_2
                                );
    }
    if ((iVar4 == 0) &&
       ((iVar4 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10)), iVar4 == 0 ||
        (iVar4 = fat_chain_free_locked(local_4c,iVar4,param_2), iVar4 == 0)))) {
      iVar4 = fat32_fsinfo_write_locked(local_4c,param_2);
      return iVar4;
    }
  }
  return iVar4;
}


// ===== fs_remove_work @ 20143a58 (200 bytes)

/* Validates and normalises the path, file_remove_core, fs_flush [fact] */

void fs_remove_work(int param_1,int param_2)

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
LAB_20143b18:
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
      if ((iVar2 == 0) && (iVar2 = file_remove_core(iVar3,param_2), iVar2 == 0)) {
        uVar4 = fs_flush(local_10);
        goto LAB_20143b18;
      }
    }
  }
  fs_set_error(iVar2,0);
  return;
}


// ===== fs_remove @ 20143b20 (68 bytes)

/* (path): deletes a file; wav_delete, rec_close_abort and rec_open_wav call it on WAV files [fact]
    */

undefined4 fs_remove(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_remove_work(param_1,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== fs_fatcache_setup @ 20143b70 (172 bytes)

/* (drive, buffer, size, sectors per slot): FAT cache in a caller buffer (0x206 bytes per sector
   slot, 4-byte aligned), -24 when too small [fact] */

int fs_fatcache_setup(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = fs_check_ready();
  if (iVar1 == 0) {
    if (param_3 < (uint)(param_4 * 0x206)) {
      return -0x18;
    }
    if ((param_2 & 1) != 0) {
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    }
    if ((param_2 & 2) != 0) {
      param_2 = param_2 + 2;
      param_3 = param_3 - 2;
    }
    uVar2 = __aeabi_uidivmod(param_3,param_4 * 0x206);
    if (uVar2 < 0x10000) {
      if (uVar2 == 0) {
        return -0x18;
      }
    }
    else {
      uVar2 = 0xffff;
    }
    *(short *)(param_1 + 0x48) = (short)uVar2;
    *(uint *)(param_1 + 0x44) = param_2;
    *(short *)(param_1 + 0x4a) = (short)param_4;
    fs_memset(param_2,0,uVar2 * param_4 * 0x206,*(undefined4 *)(param_1 + 0x6c));
    iVar1 = 0;
  }
  return iVar1;
}


// ===== fs_fatcache_setup_a @ 20143c1c (24 bytes)

/* fs_fatcache_setup and fs_set_error [fact] */

void fs_fatcache_setup_a(void)

{
  undefined4 uVar1;
  
  uVar1 = fs_fatcache_setup();
  fs_set_error(uVar1,0);
  return;
}


// ===== fs_fatcache_setup_b @ 20143c34 (20 bytes)

/* Second identical wrapper [fact] */

void fs_fatcache_setup_b(void)

{
  undefined4 uVar1;
  
  uVar1 = fs_fatcache_setup();
  fs_set_error(uVar1,0);
  return;
}


// ===== fatcache_lookup @ 20143c48 (116 bytes)

/* Slot number (1-based) of the FAT cache slot holding a sector, 0 for a miss [fact] */

uint fatcache_lookup(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = 0;
  puVar3 = *(uint **)(param_1 + 0x44);
  if (*(ushort *)(param_1 + 0x48) != 0) {
    do {
      uVar1 = *puVar3 & 0x7fffffff;
      if (((uVar1 != 0) && (uVar1 <= param_2)) && (param_2 < *(ushort *)(param_1 + 0x4a) + uVar1)) {
        return uVar2 * *(ushort *)(param_1 + 0x4a) + (param_2 - uVar1) + 1 & 0xffff;
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar2 < *(ushort *)(param_1 + 0x48));
  }
  return 0;
}


// ===== fatcache_load @ 20143cbc (340 bytes)

/* Evicts the oldest FAT cache slot (writes it back when dirty, also to the second FAT when there
   are two and a slot is one sector) and reads the slot's sectors (fs_dev_op1) [fact] */

int fatcache_load(int param_1,int param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  
  uVar8 = (uint)*(ushort *)(param_1 + 6);
  uVar7 = (uint)*(ushort *)(param_1 + 0x4a);
  iVar9 = *(int *)(param_1 + 0x44);
  iVar2 = __aeabi_uidivmod(param_2 - uVar8,uVar7);
  uVar11 = uVar7 * iVar2 + uVar8;
  uVar4 = (uint)*(ushort *)(param_1 + 0x48);
  puVar5 = (ushort *)((*(int *)(param_1 + 0x6c) * uVar7 + 4) * uVar4 + iVar9);
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      if (*puVar5 == uVar4 || *puVar5 == 0) break;
      puVar5 = puVar5 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < uVar4);
  }
  puVar10 = (uint *)(iVar9 + uVar3 * 4);
  iVar2 = uVar3 * uVar7 * *(int *)(param_1 + 0x6c) + iVar9 + uVar4 * 4;
  if ((*puVar10 & 0x80000000) != 0) {
    uVar4 = *puVar10 & 0x7fffffff;
    uVar3 = 0;
    sVar6 = 0;
    if (uVar7 != 0) {
      do {
        if (uVar4 + uVar3 < *(int *)(param_1 + 0xc) + uVar8) {
          sVar6 = sVar6 + 1;
        }
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < uVar7);
    }
    iVar9 = fs_dev_op2(param_1,uVar4,iVar2,sVar6);
    if (iVar9 != 0) {
      return iVar9;
    }
    if (((*(short *)(param_1 + 8) == 2) && (*(short *)(param_1 + 0x4a) == 1)) &&
       (iVar9 = fs_dev_op2(param_1,*(int *)(param_1 + 0xc) + (*puVar10 & 0x7fffffff),iVar2,1),
       iVar9 != 0)) {
      return iVar9;
    }
  }
  iVar2 = fs_dev_op1(param_1,uVar11,iVar2,*(undefined2 *)(param_1 + 0x4a));
  if (iVar2 == 0) {
    *puVar10 = uVar11;
    uVar1 = fatcache_lookup(param_1,param_2);
    *param_3 = uVar1;
    iVar2 = 0;
  }
  return iVar2;
}


// ===== fatcache_touch @ 20143e10 (156 bytes)

/* Ages the FAT cache slots and makes the given one the newest [fact] */

void fatcache_touch(int param_1,uint param_2)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort unaff_r5;
  ushort uVar4;
  uint uVar5;
  
  uVar5 = (uint)*(ushort *)(param_1 + 0x48);
  if (uVar5 != 0) {
    unaff_r5 = 1;
  }
  puVar2 = (ushort *)
           ((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x4a) + 4) * uVar5 +
           *(int *)(param_1 + 0x44));
  uVar1 = puVar2[param_2 - 1];
  uVar3 = 1;
  if (uVar5 != 0) {
    do {
      uVar4 = *puVar2;
      if ((uVar4 == 0 || uVar3 == param_2) || ((uVar1 <= uVar4 && (uVar1 != 0)))) {
        if (uVar3 != param_2) goto LAB_20143e80;
        *puVar2 = unaff_r5;
      }
      else {
        uVar4 = uVar4 + 1;
        *puVar2 = uVar4;
LAB_20143e80:
        if (uVar4 == 0) {
          return;
        }
      }
      puVar2 = puVar2 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 <= *(ushort *)(param_1 + 0x48));
  }
  return;
}


// ===== fs_dircache_setup @ 20143eac (204 bytes)

/* (drive, buffer, size, sectors per slot): directory cache (0x208 bytes per sector, at least 3
   slots), -28 otherwise [fact] */

void fs_dircache_setup(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = fs_check_ready();
  if (iVar1 != 0) {
    fs_set_error(iVar1,0);
    return;
  }
  if ((param_2 != 0 && param_4 != 0) && ((uint)(param_4 * 0x208) <= param_3)) {
    if ((param_2 & 1) != 0) {
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    }
    if ((param_2 & 2) != 0) {
      param_2 = param_2 + 2;
      param_3 = param_3 - 2;
    }
    uVar2 = __aeabi_uidivmod(param_3,param_4 * 0x208);
    bVar3 = 0x7fff < uVar2;
    if (bVar3) {
      uVar2 = 0x7fff;
    }
    if (bVar3 || 2 < uVar2) {
      *(short *)(param_1 + 0x50) = (short)uVar2;
      *(uint *)(param_1 + 0x4c) = param_2;
      *(short *)(param_1 + 0x52) = (short)param_4;
      fs_memset(param_2,0,uVar2 * param_4 * 0x208,*(undefined4 *)(param_1 + 0x6c));
      fs_set_error(0);
      return;
    }
  }
  fs_set_error(0xffffffe4,0);
  return;
}


// ===== dircache_lookup @ 20143f78 (136 bytes)

/* Slot number of the directory/data cache slot holding a sector, 0 for a miss [fact] */

uint dircache_lookup(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = (uint)*(ushort *)(param_1 + 0x50);
  puVar3 = *(uint **)(param_1 + 0x4c);
  puVar5 = (uint *)((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 4) * uVar4 +
                   (int)puVar3);
  uVar2 = 0;
  if (uVar4 != 0) {
    do {
      uVar1 = *puVar3;
      if (((uVar1 != 0) && (uVar1 <= param_2)) && (param_2 < (ushort)*puVar5 + uVar1)) {
        return uVar2 * *(ushort *)(param_1 + 0x52) + (param_2 - uVar1) + 1 & 0xffff;
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
      puVar5 = (uint *)((int)puVar5 + 2);
    } while (uVar2 < uVar4);
  }
  return 0;
}


// ===== dircache_load @ 20144000 (616 bytes)

/* Evicts the oldest directory cache slot (write back when dirty) and reads the sectors, clipped to
   the fixed root directory for FAT12/16 [fact] */

int dircache_load(int param_1,uint param_2,undefined2 *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  
  uVar5 = (uint)*(ushort *)(param_1 + 0x50);
  iVar12 = *(int *)(param_1 + 0x4c);
  iVar8 = *(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52);
  puVar7 = (ushort *)((iVar8 + 6) * uVar5 + iVar12);
  uVar3 = 0;
  if (uVar5 != 0) {
    do {
      if (uVar5 == (*puVar7 & 0xffff7fff) || (*puVar7 & 0x7fff) == 0) break;
      puVar7 = puVar7 + 1;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < uVar5);
  }
  piVar10 = (int *)(iVar12 + uVar3 * 4);
  iVar6 = uVar3 * (uint)*(ushort *)(param_1 + 0x52) * *(int *)(param_1 + 0x6c) + iVar12 + uVar5 * 4;
  puVar9 = (ushort *)((iVar8 + 4) * uVar5 + iVar12 + uVar3 * 2);
  if (((*puVar7 & 0x8000) != 0) && (iVar8 = fs_dev_op2(param_1,*piVar10,iVar6,*puVar9), iVar8 != 0))
  {
    return iVar8;
  }
  if (*(char *)(param_1 + 0x10) != ' ') {
    uVar3 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    iVar8 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
            (uint)*(ushort *)(param_1 + 6);
    if (param_2 < uVar3 + iVar8) {
      uVar5 = uVar3 & 0xffff;
      uVar1 = *(ushort *)(param_1 + 0x52);
      uVar11 = (uint)uVar1;
      if (uVar5 <= uVar11) {
        *puVar9 = (ushort)uVar3;
        iVar12 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                 (uint)*(ushort *)(param_1 + 6);
        iVar8 = fs_dev_op1(param_1,iVar12,iVar6,uVar5);
        if (iVar8 != 0) {
          return iVar8;
        }
        *piVar10 = iVar12;
        uVar2 = dircache_lookup(param_1,iVar12);
        *param_3 = uVar2;
        return 0;
      }
      iVar12 = __aeabi_uidivmod(param_2 - iVar8,uVar11);
      uVar5 = uVar5 - uVar11 * iVar12;
      iVar8 = iVar8 + uVar11 * iVar12;
      if (uVar5 < uVar11) {
        *puVar9 = (ushort)uVar5;
      }
      else {
        *puVar9 = uVar1;
      }
      iVar12 = fs_dev_op1(param_1,iVar8,iVar6,*puVar9);
      if (iVar12 != 0) {
        return iVar12;
      }
      goto LAB_201441cc;
    }
  }
  if (*(ushort *)(param_1 + 0x52) < *(ushort *)(param_1 + 4)) {
    uVar4 = fat_sect2clust(param_1,param_2);
    iVar8 = fat_clust2sect(param_1,uVar4);
    uVar1 = *(ushort *)(param_1 + 0x52);
    uVar5 = (uint)uVar1;
    iVar12 = __aeabi_uidivmod(param_2 - iVar8,uVar5);
    iVar8 = iVar8 + uVar5 * iVar12;
    uVar3 = (uint)*(ushort *)(param_1 + 4) - uVar5 * iVar12;
    if (uVar3 < uVar5) {
      *puVar9 = (ushort)uVar3;
    }
    else {
      *puVar9 = uVar1;
    }
    iVar12 = fs_dev_op1(param_1,iVar8,iVar6,*puVar9);
    if (iVar12 == 0) {
      *piVar10 = iVar8;
      uVar2 = dircache_lookup(param_1,param_2);
      *param_3 = uVar2;
      return 0;
    }
  }
  else {
    *puVar9 = *(ushort *)(param_1 + 4);
    uVar4 = fat_sect2clust(param_1,param_2);
    iVar8 = fat_clust2sect(param_1,uVar4);
    iVar12 = fs_dev_op1(param_1,iVar8,iVar6,*puVar9);
    if (iVar12 == 0) {
LAB_201441cc:
      *piVar10 = iVar8;
      uVar2 = dircache_lookup(param_1,param_2);
      *param_3 = uVar2;
      return 0;
    }
  }
  return iVar12;
}


// ===== dircache_touch @ 20144268 (420 bytes)

/* Ages the directory cache slots and makes the given one the newest [fact] */

void dircache_touch(int param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  
  uVar7 = (uint)*(ushort *)(param_1 + 0x50);
  puVar3 = (ushort *)
           ((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 6) * uVar7 +
           *(int *)(param_1 + 0x4c));
  uVar1 = *(ushort *)
           ((*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 6) * uVar7 +
            *(int *)(param_1 + 0x4c) + param_2 * 2 + -2);
  uVar4 = 1;
  if (*(char *)(param_1 + 0x10) == '@') {
    if (uVar7 != 0) {
      do {
        uVar2 = *puVar3;
        if (((uVar2 & 0x7fff) == 0 || uVar4 == param_2) ||
           (((uVar1 & 0x7fff) <= (uVar2 & 0x7fff) && ((uVar1 & 0x7fff) != 0)))) {
          if (uVar4 == param_2) {
            *puVar3 = uVar2 & 0x8000 | 1;
          }
          if ((uVar2 & 0x7fff) == 0) {
            return;
          }
        }
        else {
          uVar5 = uVar2 + 1;
          uVar6 = uVar2 + 1;
          *puVar3 = uVar5;
          if ((uVar2 & 0x8000) == 0) {
            if (uVar6 < 0x8000) goto LAB_20144364;
            uVar6 = uVar5 & 0x7fff;
          }
          else {
            if (0x7fff < uVar6) {
              uVar6 = uVar5 & 0x7fff;
              *puVar3 = uVar6;
            }
            uVar6 = uVar6 | 0x8000;
          }
          *puVar3 = uVar6;
        }
LAB_20144364:
        puVar3 = puVar3 + 1;
        uVar4 = uVar4 + 1 & 0xffff;
        if (*(ushort *)(param_1 + 0x50) < uVar4) {
          return;
        }
      } while( true );
    }
  }
  else if (uVar7 != 0) {
    do {
      uVar2 = *puVar3;
      if (((uVar2 & 0x7fff) == 0 || uVar4 == param_2) ||
         (((uVar1 & 0x7fff) <= (uVar2 & 0x7fff) && ((uVar1 & 0x7fff) != 0)))) {
        if (uVar4 == param_2) {
          *puVar3 = uVar2 & 0x8000 | 1;
        }
        if ((uVar2 & 0x7fff) == 0) {
          return;
        }
      }
      else {
        uVar5 = uVar2 + 1;
        uVar6 = uVar2 + 1;
        *puVar3 = uVar5;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar6 < 0x8000) goto LAB_20144300;
          uVar6 = uVar5 & 0x7fff;
        }
        else {
          if (0x7fff < uVar6) {
            uVar6 = uVar5 & 0x7fff;
            *puVar3 = uVar6;
          }
          uVar6 = uVar6 | 0x8000;
        }
        *puVar3 = uVar6;
      }
LAB_20144300:
      puVar3 = puVar3 + 1;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 <= *(ushort *)(param_1 + 0x50));
  }
  return;
}


// ===== dircache_flush @ 2014440c (284 bytes)

/* Writes every dirty directory cache slot back (fs_dev_op2) and clears the dirty bit [fact] */

int dircache_flush(int param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar4 = *(undefined4 **)(param_1 + 0x4c);
  if (puVar4 != (undefined4 *)0x0) {
    iVar6 = 0;
    iVar2 = *(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52);
    uVar1 = (uint)*(ushort *)(param_1 + 0x50);
    puVar3 = (ushort *)((iVar2 + 6) * uVar1 + (int)puVar4);
    puVar5 = (undefined4 *)((iVar2 + 4) * uVar1 + (int)puVar4);
    puVar7 = puVar4 + uVar1;
    if (*(char *)(param_1 + 0x10) == '@') {
      if (uVar1 != 0) {
        do {
          if ((*puVar3 & 0x8000) != 0) {
            iVar2 = fs_dev_op2(param_1,*puVar4,puVar7,*(undefined2 *)puVar5);
            if (iVar2 != 0) {
              return iVar2;
            }
            *puVar3 = *puVar3 & 0x7fff;
          }
          iVar6 = iVar6 + 1;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
          puVar5 = (undefined4 *)((int)puVar5 + 2);
          puVar7 = (undefined4 *)
                   (*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + (int)puVar7);
        } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x50));
      }
    }
    else if (uVar1 != 0) {
      do {
        if ((*puVar3 & 0x8000) != 0) {
          iVar2 = fs_dev_op2(param_1,*puVar4,puVar7,*(undefined2 *)puVar5);
          if (iVar2 != 0) {
            return iVar2;
          }
          *puVar3 = *puVar3 & 0x7fff;
        }
        iVar6 = iVar6 + 1;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
        puVar5 = (undefined4 *)((int)puVar5 + 2);
        puVar7 = (undefined4 *)
                 (*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + (int)puVar7);
      } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x50));
    }
  }
  return 0;
}


// ===== fatcache_flush @ 2014455c (248 bytes)

/* Writes every dirty FAT cache slot back, also to the second FAT for single-sector slots [fact] */

int fatcache_flush(int param_1)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  
  puVar4 = *(uint **)(param_1 + 0x44);
  if (puVar4 != (uint *)0x0) {
    puVar6 = puVar4 + *(ushort *)(param_1 + 0x48);
    puVar7 = puVar6;
    for (; puVar4 != puVar6; puVar4 = puVar4 + 1) {
      if ((*puVar4 & 0x80000000) != 0) {
        uVar5 = *puVar4 & 0x7fffffff;
        uVar1 = 0;
        sVar3 = 0;
        if (*(ushort *)(param_1 + 0x4a) != 0) {
          do {
            if (uVar5 + uVar1 < (uint)*(ushort *)(param_1 + 6) + *(int *)(param_1 + 0xc)) {
              sVar3 = sVar3 + 1;
            }
            uVar1 = uVar1 + 1 & 0xffff;
          } while (uVar1 < *(ushort *)(param_1 + 0x4a));
        }
        iVar2 = fs_dev_op2(param_1,uVar5,puVar7,sVar3);
        if (iVar2 != 0) {
          return iVar2;
        }
        if (((*(short *)(param_1 + 8) == 2) && (*(short *)(param_1 + 0x4a) == 1)) &&
           (iVar2 = fs_dev_op2(param_1,*(int *)(param_1 + 0xc) + uVar5,puVar7,1), iVar2 != 0)) {
          return iVar2;
        }
        *puVar4 = *puVar4 & 0x7fffffff;
      }
      puVar7 = (uint *)(*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x4a) + (int)puVar7);
    }
  }
  return 0;
}


// ===== fatcache_flush_locked @ 20144654 (52 bytes)

/* fatcache_flush under fs_lock_b [fact] */

undefined4 fatcache_flush_locked(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_b();
  if (iVar1 == 0) {
    uVar2 = fatcache_flush(param_1);
    fs_unlock_b(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== fs_flush @ 20144688 (104 bytes)

/* fatcache_flush, then dircache_flush under fs_lock_a; fclose, remove and mkdir end with it [fact]
    */

int fs_flush(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = fs_check_ready();
  if ((iVar1 == 0) && (iVar1 = fatcache_flush_locked(param_1), iVar1 == 0)) {
    iVar1 = fs_lock_a();
    if (iVar1 == 0) {
      iVar1 = dircache_flush(param_1);
      fs_unlock_a(param_1);
    }
    else {
      iVar1 = -0x25;
    }
    return iVar1;
  }
  return iVar1;
}


// ===== fs_sync @ 201446bc (20 bytes)

/* fs_flush with fs_set_error [fact] */

void fs_sync(void)

{
  undefined4 uVar1;
  
  uVar1 = fs_flush();
  fs_set_error(uVar1,0);
  return;
}


// ===== fs_cache_invalidate @ 201446d0 (292 bytes)

/* Clears the FAT cache, the cluster bitmap (clusters 0, 1 and the FAT32 root kept) and the
   directory cache of a drive [fact] */

void fs_cache_invalidate(int param_1)

{
  int iVar1;
  
  iVar1 = fs_check_ready();
  if (iVar1 != 0) {
    fs_set_error(iVar1,0);
    return;
  }
  iVar1 = fs_lock_b(param_1);
  if (iVar1 != 0) {
    fs_set_error(0xffffffde,0);
    return;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    fs_memset(*(int *)(param_1 + 0x44),0,
              (uint)*(ushort *)(param_1 + 0x48) * (uint)*(ushort *)(param_1 + 0x4a) * 0x206,
              *(undefined4 *)(param_1 + 0x6c));
  }
  if (*(int *)(param_1 + 0x58) != 0) {
    fs_memset(*(int *)(param_1 + 0x58),0,*(undefined4 *)(param_1 + 0x5c),
              *(undefined4 *)(param_1 + 0x6c));
    clmap_set(param_1,0);
    clmap_set(param_1,1);
    if (*(char *)(param_1 + 0x10) == ' ') {
      clmap_set(param_1,*(undefined4 *)(param_1 + 0x34));
    }
  }
  fs_unlock_b(param_1);
  iVar1 = fs_lock_a(param_1);
  if (iVar1 != 0) {
    fs_set_error(0xffffffdb,0);
    return;
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    fs_memset(*(int *)(param_1 + 0x4c),0,
              (uint)*(ushort *)(param_1 + 0x50) * (uint)*(ushort *)(param_1 + 0x52) * 0x208,
              *(undefined4 *)(param_1 + 0x6c));
  }
  fs_unlock_a(param_1);
  fs_set_error(0);
  return;
}


// ===== FUN_201447f4 @ 201447f4 (12 bytes)

undefined4 FUN_201447f4(void)

{
  return DAT_20808ba4;
}


// ===== fs_set_error @ 20144800 (52 bytes)

/* (err, file): last error 0x20808BA4 = err, FUN_2014d98c(err), file+0x10 = err; returns -1 for err
   < 0 [fact] */

undefined4 fs_set_error(int param_1,int param_2)

{
  undefined4 uVar1;
  
  DAT_20808ba4 = param_1;
  fs_task_err_set(param_1);
  if (param_2 != 0) {
    *(int *)(param_2 + 0x10) = param_1;
  }
  if (param_1 < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fs_set_error_m2 @ 20144834 (40 bytes)

/* Last error 0x20808BA4 and per-task error = err, returns -2 for err < 0 else 0 [fact] */

undefined4 fs_set_error_m2(int param_1)

{
  undefined4 uVar1;
  
  DAT_20808ba4 = param_1;
  fs_task_err_set(param_1);
  if (param_1 < 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fs_set_error_ret @ 2014485c (28 bytes)

/* (err, ret): last error 0x20808BA4 = err, returns ret [fact] */

undefined4 fs_set_error_ret(undefined4 param_1,undefined4 param_2)

{
  DAT_20808ba4 = param_1;
  fs_task_err_set();
  return param_2;
}


// ===== fs_file_check @ 20144878 (32 bytes)

/* -13 for a null file, -6 when the open flag +0x442 is clear, else 0; used by the file calls
   (fclose, fread, fwrite, fseek, fs_fsize) [fact] */

undefined4 fs_file_check(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffff3;
  }
  else if (*(char *)(param_1 + 0x442) == '\0') {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fs_dir_check @ 20144898 (32 bytes)

/* -13 for a null handle, -6 when its open flag +4 is clear (directory handles) [inference: callers
   0x2014C474 / 0x2014CA08] */

undefined4 fs_dir_check(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffff3;
  }
  else if (*(char *)(param_1 + 4) == '\0') {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fat_sector_is_cluster_first @ 201448b8 (96 bytes)

/* 1 when a data sector is the first sector of its cluster (sectors per cluster > 1) [fact] */

undefined4 fat_sector_is_cluster_first(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int extraout_r1;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if (1 < uVar1) {
    iVar2 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    __aeabi_uidivmod((param_2 -
                     (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                              (uint)*(ushort *)(param_1 + 6))) + 1,uVar1);
    if (extraout_r1 == 1) {
      return 1;
    }
  }
  return 0;
}


// ===== fs_find_drive @ 20144918 (56 bytes)

/* (letter, *drv): walks the drive list 0x20808BA0 for +0x11 == letter; -12 when missing [fact] */

undefined4 fs_find_drive(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = DAT_20808ba0;
  do {
    if (*(char *)((int)piVar1 + 0x11) == param_1) {
      if (param_2 != (int *)0x0) {
        *param_2 = (int)piVar1;
      }
      return 0;
    }
    piVar1 = (int *)*piVar1;
  } while (piVar1 != (int *)0x0);
  return 0xfffffff4;
}


// ===== fs_drive_check_mounted @ 20144950 (32 bytes)

/* -19 for a removable drive (+0x68 bit 0) that is not mounted (bit 7), else 0 [fact] */

undefined4 fs_drive_check_mounted(int param_1)

{
  undefined4 uVar1;
  
  if ((((int)*(char *)(param_1 + 0x68) & 1U) == 0) ||
     (((int)*(char *)(param_1 + 0x68) & 0x80U) != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffed;
  }
  return uVar1;
}


// ===== fs_drive_check_writable @ 20144970 (16 bytes)

/* -58 when the drive is write-protected (+0x68 bit 5) [fact] */

uint fs_drive_check_writable(int param_1)

{
  uint uVar1;
  
  uVar1 = *(byte *)(param_1 + 0x68) & 0x20;
  if ((*(byte *)(param_1 + 0x68) & 0x20) != 0) {
    uVar1 = 0xffffffc6;
  }
  return uVar1;
}


// ===== fat_clust2sect @ 20144980 (76 bytes)

/* (vol, cluster): 0 for cluster < 2, else data start + (cluster - 2) * sectors per cluster [fact]
    */

int fat_clust2sect(int param_1,uint param_2)

{
  int iVar1;
  
  if (1 < param_2) {
    iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    return *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) + iVar1 +
           (param_2 - 2) * (uint)*(ushort *)(param_1 + 4) + (uint)*(ushort *)(param_1 + 6);
  }
  return 0;
}


// ===== fat_sect2clust @ 201449cc (68 bytes)

/* Cluster number of a data sector: (sector - data start) / sectors per cluster + 2 (inverse of
   fat_clust2sect) [fact] */

int fat_sect2clust(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  iVar1 = __aeabi_uidivmod(param_2 - (iVar1 + *(int *)(param_1 + 0xc) *
                                              (uint)*(ushort *)(param_1 + 8) +
                                              (uint)*(ushort *)(param_1 + 6)),
                           *(undefined2 *)(param_1 + 4));
  return iVar1 + 2;
}


// ===== fs_dev_op1 @ 20144a10 (176 bytes)

/* (drv, ...): device op +0x18 with command 1 between the device locks of drv+0x70; -46 / -47 on
   lock errors [fact] */

undefined4 fs_dev_op1(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = fs_sem_wait_1s(*(undefined4 *)(param_1 + 0x70));
    if (iVar1 != 0) {
      fs_set_error(0xffffffd2,0);
      return 0xffffffd2;
    }
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,1,param_2,param_3,param_4);
    iVar2 = fs_sem_signal(*(undefined4 *)(param_1 + 0x70));
    if (iVar2 != 0) {
      fs_set_error(0xffffffd1,0);
      return 0xffffffd1;
    }
    if (iVar1 == 0) {
      fs_set_error(0);
      return 0;
    }
  }
  fs_set_error(0xfffffff8,0);
  return 0xfffffff8;
}


// ===== fs_dev_op2 @ 20144ac0 (176 bytes)

/* Same with command 2 [fact] */

undefined4 fs_dev_op2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = fs_sem_wait_1s(*(undefined4 *)(param_1 + 0x70));
    if (iVar1 != 0) {
      fs_set_error(0xffffffd2,0);
      return 0xffffffd2;
    }
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,2,param_2,param_3,param_4);
    iVar2 = fs_sem_signal(*(undefined4 *)(param_1 + 0x70));
    if (iVar2 != 0) {
      fs_set_error(0xffffffd1,0);
      return 0xffffffd1;
    }
    if (iVar1 == 0) {
      fs_set_error(0);
      return 0;
    }
  }
  fs_set_error(0xfffffff7,0);
  return 0xfffffff7;
}


// ===== dir_sector_dirty @ 20144b74 (144 bytes)

/* Marks a directory/data sector dirty in the directory cache, or writes it (fs_dev_op2) when there
   is none; -0x45 when not cached [fact] */

undefined4 dir_sector_dirty(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar2 = fs_dev_op2(param_1,param_2,param_3,1);
    return uVar2;
  }
  iVar1 = dircache_lookup(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffbb;
  }
  else {
    uVar4 = __aeabi_idivmod(iVar1 - 1,(uint)*(ushort *)(param_1 + 0x52));
    uVar3 = (int)uVar4 + 1U & 0xffff;
    dircache_touch(param_1,uVar3);
    iVar1 = (*(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 0x52) + 6) *
            (uint)*(ushort *)(param_1 + 0x50) + *(int *)(param_1 + 0x4c) + uVar3 * 2;
    *(ushort *)(iVar1 + -2) = *(ushort *)(iVar1 + -2) | 0x8000;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== root_sector_dirty @ 20144c04 (88 bytes)

/* dir_sector_dirty for sector n of the FAT12/16 root directory, -11 past its end [fact] */

undefined4 root_sector_dirty(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) + (uint)*(ushort *)(param_1 + 6);
  uVar4 = iVar3 + param_2;
  iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  if (uVar4 < (uint)(iVar1 + iVar3)) {
    uVar2 = dir_sector_dirty(param_1,uVar4,param_3);
    return uVar2;
  }
  return 0xfffffff5;
}


// ===== dir_sector_get @ 20144c5c (168 bytes)

/* (vol, sector, *ptr): pointer to a directory/data sector through the directory cache, direct read
   when there is none [fact] */

int dir_sector_get(int param_1,undefined4 param_2,int *param_3,uint param_4)

{
  int iVar1;
  ulonglong uVar2;
  uint local_18;
  
  local_18 = param_4;
  if (*(int *)(param_1 + 0x4c) == 0) {
    iVar1 = fs_dev_op1(param_1,param_2,*param_3,1);
    return iVar1;
  }
  iVar1 = dircache_lookup(param_1);
  if (iVar1 == 0) {
    iVar1 = dircache_load(param_1,param_2,&local_18);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else {
    local_18 = CONCAT22(local_18._2_2_,(short)iVar1);
  }
  *param_3 = ((local_18 & 0xffff) - 1) * *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x4c) +
             (uint)*(ushort *)(param_1 + 0x50) * 4;
  uVar2 = __aeabi_idivmod((local_18 & 0xffff) - 1,(uint)*(ushort *)(param_1 + 0x52));
  local_18 = CONCAT22(local_18._2_2_,(short)uVar2 + 1);
  dircache_touch(param_1);
  return 0;
}


// ===== root_sector_get @ 20144d04 (88 bytes)

/* (vol, n, *ptr): sector n of the fixed FAT12/16 root directory (after reserved + FATs), -11 past
   its end [fact] */

undefined4 root_sector_get(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) + (uint)*(ushort *)(param_1 + 6);
  uVar4 = iVar3 + param_2;
  iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  if (uVar4 < (uint)(iVar1 + iVar3)) {
    uVar2 = dir_sector_get(param_1,uVar4,param_3);
    return uVar2;
  }
  return 0xfffffff5;
}


// ===== FUN_20144d5c @ 20144d5c (348 bytes)

int FUN_20144d5c(int param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  fs_memset(param_1,0,0x20,*(undefined4 *)(param_3 + 0x6c));
  fs_memset(param_1 + 1,0xffffffff,10,*(undefined4 *)(param_3 + 0x6c));
  fs_memset(param_1 + 0xe,0xffffffff,0xc,*(undefined4 *)(param_3 + 0x6c));
  fs_memset(param_1 + 0x1c,0xffffffff,4,*(undefined4 *)(param_3 + 0x6c));
  iVar2 = 0;
  pcVar3 = (char *)(param_1 + 1);
  iVar1 = 0;
  do {
    if ((*param_2 == '\0') && (param_2[1] == '\0')) {
      *pcVar3 = '\0';
      pcVar3[1] = '\0';
      return iVar1;
    }
    iVar2 = iVar2 + 1;
    *pcVar3 = *param_2;
    iVar1 = iVar1 + 1;
    pcVar3[1] = param_2[1];
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
  } while (iVar2 < 5);
  pcVar3 = (char *)(param_1 + 0xe);
  iVar2 = 0;
  do {
    if ((*param_2 == '\0') && (param_2[1] == '\0')) goto LAB_20144eac;
    iVar2 = iVar2 + 1;
    *pcVar3 = *param_2;
    iVar1 = iVar1 + 1;
    pcVar3[1] = param_2[1];
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
  } while (iVar2 < 6);
  pcVar3 = (char *)(param_1 + 0x1c);
  iVar2 = 0;
  while ((*param_2 != '\0' || (param_2[1] != '\0'))) {
    iVar2 = iVar2 + 1;
    *pcVar3 = *param_2;
    iVar1 = iVar1 + 1;
    pcVar3[1] = param_2[1];
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
    if (1 < iVar2) {
      return iVar1;
    }
  }
LAB_20144eac:
  *pcVar3 = '\0';
  pcVar3[1] = '\0';
  return iVar1;
}


// ===== lfn_checksum @ 20144eb8 (60 bytes)

/* Checksum of an 11-byte 8.3 name (rotate right and add), the value long-name entries carry [fact]
    */

uint lfn_checksum(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  do {
    pbVar1 = (byte *)(param_1 + iVar2);
    iVar2 = iVar2 + 1;
    uVar3 = uVar3 + *pbVar1;
    uVar3 = (uVar3 & 1) << 7 | (uVar3 & 0xff) >> 1;
  } while (iVar2 < 10);
  return *(byte *)(param_1 + iVar2) + uVar3 & 0xff;
}


// ===== FUN_20144ef4 @ 20144ef4 (432 bytes)

int FUN_20144ef4(int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int extraout_r1;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  byte *local_28;
  
  *(undefined1 *)(param_3 + 0xc) = 0;
  local_28 = (byte *)(param_6 + 0xe0c);
  iVar2 = __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 5);
  iVar3 = root_sector_get(param_1,iVar2,&local_28);
  if (iVar3 != 0) {
    return iVar3;
  }
  bVar1 = lfn_checksum(param_3);
  __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 5);
  pbVar4 = local_28 + extraout_r1 * 0x20;
  fs_memcpy(pbVar4,param_3,0x20);
  if (pbVar4 == local_28) {
    iVar3 = root_sector_dirty(param_1,iVar2);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (iVar2 == 0 || param_5 == 1) {
      return 0;
    }
    iVar2 = iVar2 + -1;
    iVar3 = root_sector_get(param_1,iVar2,&local_28);
    if (iVar3 != 0) {
      return iVar3;
    }
    pbVar4 = local_28 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
  }
  uVar6 = 1;
  if (1 < param_5) {
    iVar3 = iVar2;
    do {
      pbVar5 = pbVar4 + -0x20;
      iVar2 = FUN_20144d5c(pbVar5,param_4,param_1);
      *pbVar5 = (byte)uVar6;
      param_4 = param_4 + iVar2 * 2;
      pbVar4[-0x15] = 0xf;
      pbVar4[-0x13] = bVar1;
      iVar2 = iVar3;
      if ((pbVar5 == local_28) && (uVar6 != param_5 - 1)) {
        iVar2 = iVar3 + -1;
        iVar3 = root_sector_dirty(param_1,iVar3);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = root_sector_get(param_1,iVar2,&local_28);
        if (iVar3 != 0) {
          return iVar3;
        }
        pbVar5 = local_28 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
      }
      uVar6 = uVar6 + 1 & 0xff;
      pbVar4 = pbVar5;
      iVar3 = iVar2;
    } while (uVar6 < param_5);
    if (1 < param_5) {
      *pbVar5 = *pbVar5 | 0x40;
    }
  }
  iVar2 = root_sector_dirty(param_1,iVar2,local_28);
  return iVar2;
}


// ===== sfn_from_dotted @ 201450a4 (124 bytes)

/* "NAME.EXT" to the 11-byte space-padded 8.3 form; -1 for a base longer than 8 [fact] */

undefined4 sfn_from_dotted(int param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  fs_memset(param_1,0x20,0xb,*(undefined4 *)(param_3 + 0x6c));
  uVar2 = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  uVar3 = 0;
  do {
    cVar1 = *(char *)(param_2 + uVar3);
    if (cVar1 == '\0') {
      return 0;
    }
    if (cVar1 == '.') {
      if (8 < uVar3) {
        return 0xffffffff;
      }
      uVar2 = 7;
    }
    else {
      *(char *)(param_1 + uVar2) = cVar1;
    }
    uVar3 = uVar3 + 1 & 0xff;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar3 < 0xc && uVar2 < 0xc);
  return 0;
}


// ===== fs_char_lfn_only @ 20145120 (100 bytes)

/* 1 for the characters "+,;=[]" that a long name may hold but an 8.3 name may not [fact] */

undefined4 fs_char_lfn_only(char *param_1)

{
  int iVar1;
  int iVar2;
  char local_8 [8];
  
  builtin_strncpy(local_8,"+,;=[]",7);
  local_8[7] = '\0';
  iVar2 = 0;
  do {
    if (*param_1 == local_8[iVar2]) {
      return 1;
    }
    iVar1 = iVar2 + 1;
    iVar2 = iVar2 + 1;
  } while (local_8[iVar1] != '\0');
  return 0;
}


// ===== sjis_fold_case_pair @ 2014518c (200 bytes)

/* Byte-pair version of sjis_fold_case [fact] */

void sjis_fold_case_pair(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = (uint)CONCAT11(uVar1,param_1[1]);
  if (uVar2 - 0x8281 < 0x1a) {
    *param_2 = uVar1;
    uVar2 = (byte)param_1[1] - 0x21;
  }
  else if (uVar2 - 0x83bf < 0x18) {
    *param_2 = uVar1;
    uVar2 = (byte)param_1[1] - 0x20;
  }
  else if (uVar2 - 0x8470 < 0xf) {
    *param_2 = uVar1;
    uVar2 = (byte)param_1[1] - 0x30;
  }
  else if (uVar2 - 0x8480 < 0x12) {
    *param_2 = uVar1;
    uVar2 = (byte)param_1[1] - 0x31;
  }
  else if (uVar2 - 0xfa40 < 10) {
    uVar2 = uVar2 - 0x72ec;
    *param_2 = (char)(uVar2 >> 8);
  }
  else {
    *param_2 = uVar1;
    uVar2 = (uint)(byte)param_1[1];
  }
  param_2[1] = (char)uVar2;
  return;
}


// ===== FUN_20145254 @ 20145254 (804 bytes)

undefined4 FUN_20145254(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  bool bVar10;
  
  bVar3 = false;
  uVar9 = 0;
  iVar8 = 0;
  cVar2 = *param_1;
  pcVar7 = param_1;
  cVar1 = cVar2;
  while (pcVar5 = param_1, cVar1 != '\0') {
    iVar8 = iVar8 + 1;
    pcVar7 = pcVar7 + 1;
    cVar1 = *pcVar7;
  }
  while (cVar2 != '\0') {
    iVar4 = fs_char_lfn_only(pcVar5);
    if (iVar4 != 0) {
      uVar9 = 1;
      bVar3 = true;
    }
    cVar2 = pcVar5[1];
    pcVar5 = pcVar5 + 1;
  }
  iVar4 = fs_strchr(param_1,0x20);
  if (iVar4 != 0) {
    uVar9 = 1;
    bVar3 = true;
  }
  pcVar5 = (char *)fs_strchr(param_1,0x2e);
  if (pcVar5 != (char *)0x0) {
    iVar4 = 0;
    cVar1 = *pcVar7;
    while (cVar1 != '.') {
      iVar4 = iVar4 + 1;
      pcVar7 = pcVar7 + -1;
      cVar1 = *pcVar7;
    }
    if ((pcVar7 != pcVar5) || (4 < iVar4)) {
      uVar9 = 1;
      bVar3 = true;
    }
    iVar4 = fs_strlen(pcVar7);
    iVar8 = iVar8 - iVar4;
  }
  bVar10 = iVar8 == 8;
  if (iVar8 < 9) {
    bVar10 = !bVar3;
  }
  else {
    uVar9 = 1;
  }
  if (bVar10) {
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      if ((int)*param_1 - 0x61U < 0x1a) {
        pcVar7 = param_2 + 1;
        *param_2 = *param_1 + -0x20;
        uVar9 = 1;
        pcVar5 = param_1 + 1;
      }
      else {
        iVar8 = sjis_is_lead(*param_1);
        if (iVar8 == 0) {
          iVar8 = fs_char_lfn_only(param_1);
          if (iVar8 == 0) {
            pcVar5 = param_1 + 1;
            pcVar7 = param_2 + 1;
            *param_2 = *param_1;
          }
          else {
            uVar9 = 1;
            pcVar7 = param_2 + 1;
            *param_2 = '_';
            pcVar5 = param_1 + 1;
          }
        }
        else {
          sjis_fold_case_pair(param_1,param_2);
          uVar9 = 1;
          pcVar7 = param_2 + 2;
          pcVar5 = param_1 + 2;
        }
      }
      param_1 = pcVar5;
      param_2 = pcVar7;
      cVar1 = *pcVar5;
    }
  }
  else {
    iVar8 = fs_strlen(param_3);
    iVar4 = 0;
    while ((iVar4 < 7 - iVar8 && (param_1 != pcVar7))) {
      if ((int)*param_1 - 0x61U < 0x1a) {
        *param_2 = *param_1 + -0x20;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      }
      else {
        iVar6 = sjis_is_lead(*param_1);
        if (iVar6 == 0) {
          iVar6 = fs_char_lfn_only(param_1);
          if (iVar6 == 0) {
            cVar1 = *param_1;
            if (cVar1 == '.' || cVar1 == ' ') {
              param_1 = param_1 + 1;
              iVar4 = iVar4 + -1;
              goto LAB_20145474;
            }
            *param_2 = cVar1;
          }
          else {
            *param_2 = '_';
          }
          param_2 = param_2 + 1;
          param_1 = param_1 + 1;
        }
        else {
          sjis_fold_case_pair(param_1,param_2);
          param_2 = param_2 + 2;
          param_1 = param_1 + 2;
          iVar4 = iVar4 + 1;
        }
      }
LAB_20145474:
      iVar4 = iVar4 + 1;
    }
    if (7 - iVar8 < iVar4) {
      param_2 = param_2 + -2;
    }
    *param_2 = '~';
    cVar1 = *param_3;
    while (param_2 = param_2 + 1, cVar1 != '\0') {
      *param_2 = cVar1;
      param_3 = param_3 + 1;
      cVar1 = *param_3;
    }
    iVar8 = 0;
    do {
      cVar1 = *pcVar7;
      if (cVar1 == 0) break;
      if ((int)cVar1 - 0x61U < 0x1a) {
        *param_2 = cVar1 + -0x20;
        pcVar7 = pcVar7 + 1;
        param_2 = param_2 + 1;
      }
      else {
        iVar4 = sjis_is_lead(*pcVar7);
        if (iVar4 == 0) {
          iVar4 = fs_char_lfn_only(pcVar7);
          if (iVar4 == 0) {
            if (*pcVar7 == ' ') {
              pcVar7 = pcVar7 + 1;
              iVar8 = iVar8 + -1;
              goto LAB_2014553c;
            }
            *param_2 = *pcVar7;
          }
          else {
            *param_2 = '_';
          }
          param_2 = param_2 + 1;
          pcVar7 = pcVar7 + 1;
        }
        else {
          sjis_fold_case_pair(pcVar7,param_2);
          param_2 = param_2 + 2;
          pcVar7 = pcVar7 + 2;
          iVar8 = iVar8 + 1;
        }
      }
LAB_2014553c:
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
    if (4 < iVar8) {
      param_2 = param_2 + -2;
    }
  }
  *param_2 = '\0';
  return uVar9;
}


// ===== fs_utoa6 @ 20145578 (128 bytes)

/* Decimal digits of a number <= 999999 without leading zeros (numeric tail "~N") [fact] */

void fs_utoa6(char *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  *param_1 = '\0';
  uVar5 = 100000;
  pcVar3 = param_1;
  if (999999 < param_2) {
    param_2 = 999999;
  }
  do {
    cVar1 = __aeabi_uidivmod(param_2,uVar5);
    iVar2 = (int)cVar1;
    if (iVar2 < 1) {
      pcVar4 = pcVar3;
      if ((iVar2 == 0) && (*param_1 != '\0')) {
        pcVar4 = pcVar3 + 1;
        *pcVar3 = '0';
      }
    }
    else {
      param_2 = param_2 - iVar2 * uVar5;
      *pcVar3 = cVar1 + '0';
      pcVar4 = pcVar3 + 1;
    }
    uVar5 = uVar5 / 10;
    pcVar3 = pcVar4;
  } while (uVar5 != 0);
  *pcVar4 = '\0';
  return;
}


// ===== root_dirent_delete @ 201455f8 (276 bytes)

/* Marks a root-directory entry and the long-name entries before it deleted (0xE5) [fact] */

int root_dirent_delete(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int extraout_r1;
  uint uVar6;
  bool bVar7;
  byte *local_20;
  
  local_20 = (byte *)(param_4 + 0xe0c);
  iVar3 = __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 5);
  iVar4 = root_sector_get(param_1,iVar3,&local_20);
  if (iVar4 == 0) {
    __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 5);
    if (param_3 == 1) {
      param_3 = 2;
    }
    uVar6 = 0;
    pbVar5 = local_20 + extraout_r1 * 0x20;
    do {
      bVar2 = *pbVar5;
      *pbVar5 = 0xe5;
      if (pbVar5 == local_20) {
        iVar4 = root_sector_dirty(param_1,iVar3);
        if (iVar4 != 0) {
          return iVar4;
        }
        if (iVar3 == 0) {
          return 0;
        }
        iVar3 = iVar3 + -1;
        iVar4 = root_sector_get(param_1,iVar3,&local_20);
        if (iVar4 != 0) {
          return iVar4;
        }
        pbVar5 = local_20 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
      }
      pbVar1 = pbVar5 + -0x15;
      pbVar5 = pbVar5 + -0x20;
      if (*pbVar1 != 0xf) break;
      uVar6 = uVar6 + 1 & 0xff;
      bVar7 = uVar6 == param_3;
      if (param_3 <= uVar6) {
        bVar7 = (bVar2 & 0x40) == 0x40;
      }
    } while (!bVar7);
    iVar4 = root_sector_dirty(param_1,iVar3,local_20);
  }
  return iVar4;
}

