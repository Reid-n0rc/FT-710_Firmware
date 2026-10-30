// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== fat32_entry_get @ 2014933c (120 bytes)

/* FAT32 entry: FAT sector cluster/(bps/4) via fat_table_sector_get, fat_ld_dword [fact] */

undefined4 fat32_entry_get(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 local_18;
  int local_14;
  
  uVar3 = __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 2);
  iVar1 = fat_table_sector_get(param_1,(int)uVar3,&local_14,param_3);
  if (iVar1 == 0) {
    local_18 = *(undefined4 *)(local_14 + (int)((ulonglong)uVar3 >> 0x20) * 4);
    uVar2 = fat_ld_dword(&local_18);
    return uVar2;
  }
  if (*(char *)(param_1 + 0x10) == '@') {
    uVar2 = 0xfffffff7;
  }
  else {
    uVar2 = 0xffffff7;
  }
  return uVar2;
}


// ===== fat32_entry_set @ 201493b4 (108 bytes)

/* FAT32 entry store and fat_table_sector_dirty [fact] */

void fat32_entry_set(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  int local_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iStack_24 = param_1;
  uStack_20 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  uVar3 = __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 2);
  iVar1 = fat_table_sector_get(param_1,(int)uVar3,&local_28,param_4);
  if (iVar1 == 0) {
    uVar2 = fat_ld_dword(&uStack_1c);
    *(undefined4 *)(local_28 + (int)((ulonglong)uVar3 >> 0x20) * 4) = uVar2;
    fat_table_sector_dirty(param_1,(int)uVar3);
  }
  return;
}


// ===== fat_entry_rw @ 20149420 (636 bytes)

/* (vol, cluster, value, 'r'/'w'): reads or writes a FAT12 (packed 12-bit, may cross a sector),
   FAT16 or FAT32 entry; >= 0xFF8 / 0xFFF8 return 0x0FFFFFFF (end of chain) [fact] */

uint fat_entry_rw(int param_1,uint param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 local_30;
  undefined1 local_2f;
  int local_2c [2];
  
  if (*(char *)(param_1 + 0x10) == ' ') {
    if (param_4 != 0x77) {
      uVar3 = fat32_entry_get(param_1,param_2,param_5);
      return uVar3;
    }
    iVar4 = fat32_entry_set(param_1,param_2,param_3,param_5);
    if (iVar4 != 0) {
      return 0xffffff7;
    }
    return 0;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar5 = __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 1);
    iVar1 = (int)uVar5;
    iVar4 = (int)((ulonglong)uVar5 >> 0x20) << 1;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x6c);
    iVar1 = __aeabi_uidivmod(param_2 * 3,iVar4 << 1);
    iVar4 = (param_2 * 3 >> 1) - iVar4 * iVar1;
  }
  iVar2 = fat_table_sector_get(param_1,iVar1,local_2c,param_5);
  if (iVar2 != 0) {
    return 0xffffff7;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar3 = fat_ld_word(local_2c[0] + iVar4);
    if (param_4 == 0x77) {
      fat_st_word(local_2c[0] + iVar4,param_3 & 0xffff);
      iVar4 = fat_table_sector_dirty(param_1,iVar1,local_2c[0]);
      if (iVar4 != 0) {
        return 0xffffff7;
      }
    }
    goto LAB_20149684;
  }
  local_30 = *(undefined1 *)(local_2c[0] + iVar4);
  if (*(int *)(param_1 + 0x6c) + -1 == iVar4) {
    iVar1 = iVar1 + 1;
    iVar4 = -1;
    iVar2 = fat_table_sector_get(param_1,iVar1,local_2c,param_5);
    if (iVar2 != 0) {
      return 0xffffff7;
    }
  }
  local_2f = *(undefined1 *)(local_2c[0] + iVar4 + 1);
  uVar3 = fat_ld_word(&local_30);
  if ((param_2 & 1) == 0) {
    if (param_4 == 0x77) {
      fat_st_word(&local_30,uVar3 & 0xf000 | param_3 & 0xfff);
      goto LAB_201495e4;
    }
  }
  else {
    if (param_4 == 0x77) {
      fat_st_word(&local_30,uVar3 & 0xf | (param_3 & 0xfff) << 4);
    }
    uVar3 = uVar3 >> 4;
    if (param_4 == 0x77) {
LAB_201495e4:
      *(undefined1 *)(local_2c[0] + iVar4 + 1) = local_2f;
      if (iVar4 == -1) {
        iVar4 = fat_table_sector_dirty(param_1,iVar1);
        if (iVar4 != 0) {
          return 0xffffff7;
        }
        iVar1 = iVar1 + -1;
        iVar4 = fat_table_sector_get(param_1,iVar1,local_2c,param_5);
        if (iVar4 != 0) {
          return 0xffffff7;
        }
        *(undefined1 *)(*(int *)(param_1 + 0x6c) + local_2c[0] + -1) = local_30;
      }
      else {
        *(undefined1 *)(local_2c[0] + iVar4) = local_30;
      }
      iVar4 = fat_table_sector_dirty(param_1,iVar1,local_2c[0]);
      if (iVar4 != 0) {
        return 0xffffff7;
      }
    }
  }
  uVar3 = uVar3 & 0xffff0fff;
  if (0xff6 < uVar3) {
    uVar3 = uVar3 | 0xf000;
  }
LAB_20149684:
  if (0xfff7 < uVar3) {
    uVar3 = 0xfffffff;
  }
  return uVar3;
}


// ===== clmap_clear @ 2014969c (32 bytes)

/* Clears a cluster's bit in the volume's cluster-use bitmap +0x58 (bit masks 0x20808BAC) [fact] */

void clmap_clear(int param_1,uint param_2)

{
  *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) =
       *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) & ~(&DAT_20808bac)[param_2 & 7];
  return;
}


// ===== fat_chain_free @ 201496bc (204 bytes)

/* Frees a cluster chain: writes 0 to each entry, clears the cluster-map bit, FAT32 free count +0x3C
   ++, keeps the first freed cluster as hint +0x2C; -61 on a bad chain [fact] */

undefined4 fat_chain_free(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_2;
  while( true ) {
    uVar1 = fat_entry_rw(param_1,uVar3,0,0x72,param_3);
    if ((uVar1 == 0xffffff7) || (uVar3 < 2)) {
      return 0xffffffc3;
    }
    if ((*(int *)(param_1 + 0x58) != 0) && (uVar3 < *(uint *)(param_1 + 0x60))) {
      clmap_clear(param_1,uVar3);
    }
    iVar2 = fat_entry_rw(param_1,uVar3,0,0x77,param_3);
    if (iVar2 == 0xffffff7) break;
    if (*(char *)(param_1 + 0x10) == ' ') {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
    }
    uVar3 = uVar1;
    if (uVar1 + 0xf0000008 < 8) {
      if (*(int *)(param_1 + 0x2c) == 0) {
        *(uint *)(param_1 + 0x2c) = param_2;
      }
      return 0;
    }
  }
  return 0xffffffc3;
}


// ===== fat_chain_free_locked @ 20149788 (68 bytes)

/* fat_chain_free under fs_lock_b (-34 on lock failure) [fact] */

undefined4 fat_chain_free_locked(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_b();
  if (iVar1 == 0) {
    uVar2 = fat_chain_free(param_1,param_2,param_3);
    fs_unlock_b(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== fat_entry_rw_locked @ 201497cc (88 bytes)

/* fat_entry_rw under fs_lock_b, result to *out [fact] */

undefined4
fat_entry_rw_locked(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_b();
  if (iVar1 == 0) {
    uVar2 = fat_entry_rw(param_1,param_3,param_4,param_5,param_6);
    *param_2 = uVar2;
    fs_unlock_b(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== clmap_set @ 20149824 (32 bytes)

/* Sets a cluster's bit in the bitmap +0x58 [fact] */

void clmap_set(int param_1,uint param_2)

{
  *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) =
       *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) | (&DAT_20808bac)[param_2 & 7];
  return;
}


// ===== clmap_test @ 20149844 (28 bytes)

/* Tests a cluster's bit in the bitmap +0x58 [fact] */

byte clmap_test(int param_1,uint param_2)

{
  return *(byte *)(*(int *)(param_1 + 0x58) + (param_2 >> 3)) & (&DAT_20808bac)[param_2 & 7];
}


// ===== clmap_find_free @ 20149860 (224 bytes)

/* First clear bitmap bit from the hint +0x28 (or the freed hint +0x2C), wraps to cluster 2; sets
   the bit and the next hint; -99 when full [fact] */

undefined4 clmap_find_free(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  
LAB_20149870:
  uVar2 = *(uint *)(param_1 + 0x28);
  bVar4 = uVar2 <= *(uint *)(param_1 + 0x60);
  bVar3 = *(uint *)(param_1 + 0x60) == uVar2;
  if (bVar4 && !bVar3) {
    do {
      if (bVar4 && !bVar3) {
        iVar1 = clmap_test(param_1,uVar2);
        if (iVar1 == 0) goto LAB_20149908;
        if (*(int *)(param_1 + 0x2c) != 0) goto code_r0x201498a4;
      }
      uVar2 = uVar2 + 1;
      bVar4 = uVar2 <= *(uint *)(param_1 + 0x60);
      bVar3 = *(uint *)(param_1 + 0x60) == uVar2;
      if (!bVar4 || bVar3) break;
    } while( true );
  }
  goto LAB_201498c0;
code_r0x201498a4:
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  goto LAB_20149870;
LAB_201498c0:
  uVar2 = 2;
  if (*(uint *)(param_1 + 0x28) < 3) {
    return 0xffffff9d;
  }
  do {
    if (uVar2 < *(uint *)(param_1 + 0x60)) {
      iVar1 = clmap_test(param_1,uVar2);
      if (iVar1 == 0) {
LAB_20149908:
        *param_2 = uVar2;
        *(uint *)(param_1 + 0x28) = uVar2 + 1;
        clmap_set(param_1,uVar2);
        return 0;
      }
      if (*(int *)(param_1 + 0x2c) != 0) break;
    }
    uVar2 = uVar2 + 1;
    if (*(uint *)(param_1 + 0x28) <= uVar2) {
      return 0xffffff9d;
    }
  } while( true );
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  goto LAB_201498c0;
}


// ===== fat32_find_free @ 20149940 (320 bytes)

/* Scans the FAT32 table from hint +0x28 to the last cluster for a 0 entry [fact] */

int fat32_find_free(int param_1,uint *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  int local_38 [2];
  int iStack_30;
  uint *local_2c;
  undefined4 local_28;
  
  bVar1 = false;
  iVar7 = 0;
  local_38[0] = 0;
  iVar4 = *(int *)(param_1 + 0xc);
  uVar6 = (*(uint *)(param_1 + 0x6c) >> 2) * iVar4;
  iStack_30 = param_1;
  local_2c = param_2;
  local_28 = param_3;
  iVar2 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5);
  iVar2 = __aeabi_uidivmod(*(int *)(param_1 + 0x14) -
                           (iVar2 + iVar4 * (uint)*(ushort *)(param_1 + 8) +
                                    (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  if (iVar2 + 2U < uVar6) {
    uVar6 = iVar2 + 2U;
  }
LAB_201499a0:
  do {
    iVar2 = -1;
    for (uVar5 = *(uint *)(param_1 + 0x28); uVar5 < uVar6; uVar5 = uVar5 + 1) {
      uVar8 = __aeabi_uidivmod(uVar5,*(uint *)(param_1 + 0x6c) >> 2);
      iVar4 = (int)uVar8;
      if ((iVar2 != iVar4) &&
         (iVar3 = fat_table_sector_get(param_1,iVar4,local_38,local_28), iVar2 = iVar4, iVar3 != 0))
      {
        return iVar3;
      }
      if (local_38[0] != 0) {
        iVar7 = fat_ld_dword(local_38[0] + (int)((ulonglong)uVar8 >> 0x20) * 4);
      }
      if (iVar7 == 0) {
        *local_2c = uVar5;
        *(uint *)(param_1 + 0x28) = uVar5 + 1;
        return 0;
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
        *(undefined4 *)(param_1 + 0x2c) = 0;
        goto LAB_201499a0;
      }
    }
    if ((uVar5 != uVar6) || (bVar1)) {
      return -99;
    }
    uVar6 = *(uint *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 2;
    bVar1 = true;
  } while( true );
}


// ===== fat32_alloc_cluster @ 20149a80 (268 bytes)

/* Finds a free cluster (bitmap or FAT scan), marks it end-of-chain 0x0FFFFFFF, links it from the
   previous cluster, free count +0x3C -- [fact] */

uint fat32_alloc_cluster(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint local_18;
  
  local_18 = param_4;
  if ((*(int *)(param_1 + 0x58) == 0) || (*(char *)(param_1 + 0x54) == '\0')) {
    iVar1 = fat32_find_free(param_1,&local_18);
  }
  else {
    iVar1 = clmap_find_free(param_1,&local_18);
    if (iVar1 == 0) goto LAB_20149af8;
    if (*(int *)(param_1 + 0x60) == *(int *)(param_1 + 100)) {
      return 0;
    }
    iVar1 = fat32_find_free(param_1,&local_18,param_3);
  }
  if (iVar1 != 0) {
    return 0;
  }
LAB_20149af8:
  iVar1 = fat32_entry_set(param_1,local_18,0xfffffff,param_3);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0x58) != 0) && (local_18 < *(uint *)(param_1 + 0x60))) {
      clmap_set(param_1);
    }
    if (*(uint *)(param_1 + 0x2c) == local_18) {
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
    if (param_2 == 0) {
      return local_18;
    }
    iVar1 = fat32_entry_set(param_1,param_2,local_18,param_3);
    if (iVar1 == 0) {
      return local_18;
    }
  }
  return 0;
}


// ===== fat_alloc_cluster @ 20149b8c (608 bytes)

/* (vol, previous cluster): allocates a cluster on FAT12/16 (end mark 0xFFFF, links the previous
   one), FAT32 through fat32_alloc_cluster; 0 when the disk is full [fact] */

uint fat_alloc_cluster(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint local_24;
  
  bVar1 = false;
  if (*(char *)(param_1 + 0x10) == ' ') {
    uVar3 = fat32_alloc_cluster(param_1);
    return uVar3;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar3 = (*(uint *)(param_1 + 0x6c) >> 1) * *(int *)(param_1 + 0xc);
  }
  else {
    uVar3 = (*(uint *)(param_1 + 0x6c) * *(int *)(param_1 + 0xc) * 2) / 3;
  }
  iVar2 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  iVar2 = __aeabi_uidivmod(*(int *)(param_1 + 0x14) -
                           (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                                    (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  if ((iVar2 + 2U & 0xffff) < uVar3) {
    uVar3 = iVar2 + 2U & 0xffff;
  }
  if ((*(int *)(param_1 + 0x58) != 0) && (*(char *)(param_1 + 0x54) != '\0')) {
    iVar2 = clmap_find_free(param_1,&local_24);
    if (iVar2 == 0) {
      iVar2 = fat_entry_rw(param_1,local_24,0xffff,0x77,param_3);
      if (iVar2 == 0) {
        if (*(uint *)(param_1 + 0x2c) == local_24) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        if (param_2 != 0) {
          iVar2 = fat_entry_rw(param_1,param_2,local_24,0x77,param_3);
joined_r0x20149d18:
          if (iVar2 == 0xffffff7) {
            return 0;
          }
        }
        return local_24;
      }
    }
    else if (*(int *)(param_1 + 0x60) != *(int *)(param_1 + 100)) goto LAB_20149c58;
    return 0;
  }
LAB_20149c58:
  do {
    for (local_24 = *(uint *)(param_1 + 0x28); local_24 < uVar3; local_24 = local_24 + 1) {
      iVar2 = fat_entry_rw(param_1,local_24,0,0x72,param_3);
      if (iVar2 == 0) {
        *(uint *)(param_1 + 0x28) = local_24 + 1;
        iVar2 = fat_entry_rw(param_1,local_24,0xffff,0x77,param_3);
        if (iVar2 != 0) {
          return 0;
        }
        if (*(uint *)(param_1 + 0x2c) == local_24) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        if ((*(int *)(param_1 + 0x58) != 0) && (local_24 < *(uint *)(param_1 + 0x60))) {
          clmap_set(param_1);
        }
        if (param_2 == 0) {
          return local_24;
        }
        iVar2 = fat_entry_rw(param_1,param_2,local_24,0x77,param_3);
        goto joined_r0x20149d18;
      }
      if (iVar2 == 0xffffff7) {
        return 0;
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c);
        *(undefined4 *)(param_1 + 0x2c) = 0;
        goto LAB_20149c58;
      }
    }
    if (local_24 != uVar3) {
      return 0;
    }
    if (bVar1) {
      return 0;
    }
    uVar3 = *(uint *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = 2;
    bVar1 = true;
  } while( true );
}


// ===== fat_alloc_cluster_locked @ 20149dec (92 bytes)

/* fat_alloc_cluster under fs_lock_b [fact] */

uint fat_alloc_cluster_locked
               (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  fs_set_error(0);
  iVar1 = fs_lock_b(param_1);
  if (iVar1 == 0) {
    uVar2 = fat_alloc_cluster(param_1,param_2,param_4);
    *param_3 = uVar2;
    fs_unlock_b(param_1);
    uVar3 = fs_task_ctx_get();
    return uVar3;
  }
  return 0xffffffde;
}


// ===== fat_next_cluster @ 20149e48 (96 bytes)

/* fat_entry_rw(vol, cluster, 0, 'r') under fs_lock_b; end-of-chain values give 0 [fact] */

undefined4 fat_next_cluster(undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = fs_lock_b();
  if (iVar1 == 0) {
    uVar3 = fat_entry_rw(param_1,param_2,0,0x72,param_4);
    *param_3 = uVar3;
    if (0xffffff6 < uVar3) {
      *param_3 = 0;
    }
    fs_unlock_b(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== fat_next_sector_alloc @ 20149eb0 (184 bytes)

/* Like fat_next_sector, but at the end of the chain allocates and links a new cluster
   (fat_alloc_cluster_locked); used when writing [fact] */

int fat_next_sector_alloc(int param_1,int param_2,int *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  int local_20;
  
  uVar1 = *(ushort *)(param_1 + 4);
  local_20 = param_4;
  if (1 < uVar1) {
    iVar2 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    __aeabi_uidivmod((param_2 -
                     (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                              (uint)*(ushort *)(param_1 + 6))) + 1,uVar1);
    if (extraout_r1 != 0) {
      *param_3 = param_2 + 1;
      return 0;
    }
  }
  uVar3 = fat_sect2clust(param_1,param_2);
  iVar2 = fat_alloc_cluster_locked(param_1,uVar3,&local_20,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_20 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = fat_clust2sect(param_1);
  }
  *param_3 = iVar2;
  return 0;
}


// ===== fat_next_sector @ 20149f68 (184 bytes)

/* Next sector of a cluster chain: sector + 1 inside the cluster, else the first sector of the next
   cluster (0 at the end) [fact] */

int fat_next_sector(int param_1,int param_2,int *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  int local_20;
  
  uVar1 = *(ushort *)(param_1 + 4);
  local_20 = param_4;
  if (1 < uVar1) {
    iVar2 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
    __aeabi_uidivmod((param_2 -
                     (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                              (uint)*(ushort *)(param_1 + 6))) + 1,uVar1);
    if (extraout_r1 != 0) {
      *param_3 = param_2 + 1;
      return 0;
    }
  }
  uVar3 = fat_sect2clust(param_1,param_2);
  iVar2 = fat_next_cluster(param_1,uVar3,&local_20,param_4);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_20 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = fat_clust2sect(param_1);
  }
  *param_3 = iVar2;
  return 0;
}


// ===== fat32_fsinfo_write @ 2014a020 (132 bytes)

/* FAT32: reads the FSInfo sector (+0x3A), stores free count (+0x3C) at 0x1E8 and next-free hint
   (+0x28) at 0x1EC, writes it back [fact for the offsets; FSInfo layout from the FAT spec] */

int fat32_fsinfo_write(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = *(undefined2 *)(param_1 + 0x3a);
  if (*(char *)(param_1 + 0x10) == ' ') {
    iVar2 = fs_dev_op1(param_1,uVar1,param_2 + 0xc0c,1);
    if (iVar2 == 0) {
      fat_st_dword(param_2 + 0xdf4,*(undefined4 *)(param_1 + 0x3c));
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x28);
      fat_st_dword(param_2 + 0xdf8);
      iVar2 = fs_dev_op2(param_1,uVar1,param_2 + 0xc0c,1);
      return iVar2;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ===== fat32_fsinfo_write_locked @ 2014a0a4 (60 bytes)

/* fat32_fsinfo_write under fs_lock_b [fact] */

undefined4 fat32_fsinfo_write_locked(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_b();
  if (iVar1 == 0) {
    uVar2 = fat32_fsinfo_write(param_1,param_2);
    fs_unlock_b(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== fs_clmap_attach @ 2014a0e0 (548 bytes)

/* (drive, buffer, size, work, scan): gives a drive a cluster-use bitmap (+0x58/+0x5C, clusters
   covered +0x60, FAT entries +0x64) and optionally fills it from the FAT [fact] */

void fs_clmap_attach(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_28;
  int local_24 [2];
  
  local_28 = DAT_20808ba0;
  iVar4 = fs_check_ready();
  if (iVar4 != 0) goto LAB_2014a14c;
  if (param_2 == 0 || param_3 == 0) {
    iVar4 = -0xd;
    goto LAB_2014a14c;
  }
  uVar3 = fs_toupper(param_1);
  iVar4 = fs_find_drive(uVar3,&local_28);
  iVar2 = local_28;
  if (iVar4 != 0) goto LAB_2014a14c;
  cVar1 = *(char *)(local_28 + 0x10);
  if (cVar1 == '\f') {
    uVar5 = (uint)(*(int *)(local_28 + 0x6c) * *(int *)(local_28 + 0xc) * 2) / 3;
LAB_2014a1cc:
    *(uint *)(local_28 + 100) = uVar5;
  }
  else {
    if (cVar1 != '\x10') {
      if (cVar1 != ' ') {
        iVar4 = -0x10;
        goto LAB_2014a14c;
      }
      uVar5 = (*(uint *)(local_28 + 0x6c) >> 2) * *(int *)(local_28 + 0xc);
      goto LAB_2014a1cc;
    }
    *(uint *)(local_28 + 100) = (*(uint *)(local_28 + 0x6c) >> 1) * *(int *)(local_28 + 0xc);
  }
  uVar6 = *(undefined4 *)(local_28 + 0x6c);
  iVar4 = __aeabi_uidivmod((uint)*(ushort *)(local_28 + 10) << 5);
  iVar4 = __aeabi_uidivmod(*(int *)(iVar2 + 0x14) -
                           (iVar4 + *(int *)(iVar2 + 0xc) * (uint)*(ushort *)(iVar2 + 8) +
                                    (uint)*(ushort *)(iVar2 + 6)),*(undefined2 *)(iVar2 + 4));
  if (iVar4 + 2U < *(uint *)(iVar2 + 100)) {
    *(uint *)(iVar2 + 100) = iVar4 + 2U;
  }
  uVar5 = *(uint *)(iVar2 + 100);
  if (param_3 < (uint)((uVar5 & 7) != 0) + (uVar5 >> 3)) {
    *(uint *)(iVar2 + 0x60) = param_3 << 3;
  }
  else {
    *(uint *)(iVar2 + 0x60) = uVar5;
  }
  *(int *)(iVar2 + 0x58) = param_2;
  *(uint *)(iVar2 + 0x5c) = param_3;
  fs_memset(param_2,0,param_3,uVar6);
  if (param_5 == 0) {
    iVar4 = 0;
  }
  else {
    uVar5 = 0;
    if (*(int *)(local_28 + 0x60) != 0) {
      do {
        if ((*(byte *)(local_28 + 0x68) & 0x40) == 0) {
          iVar4 = -0x13;
          goto LAB_2014a14c;
        }
        iVar4 = fat_entry_rw_locked(local_28,local_24,uVar5,0,0x72,param_4);
        if (iVar4 != 0) goto LAB_2014a14c;
        if (local_24[0] != 0) {
          clmap_set(local_28,uVar5);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(local_28 + 0x60));
    }
    *(undefined1 *)(local_28 + 0x54) = 1;
    iVar4 = 0;
  }
LAB_2014a14c:
  fs_set_error(iVar4,0);
  return;
}


// ===== fs_clmap_attach_scan @ 2014a304 (92 bytes)

/* fs_clmap_attach with a work buffer and scan = 1 [fact] */

undefined4 fs_clmap_attach_scan(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_clmap_attach(param_1,param_2,param_3,iVar1,1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== fs_clmap_size @ 2014a360 (320 bytes)

/* Bytes a drive's cluster bitmap needs: (clusters + 7) / 8, clusters = min(FAT entries, data
   clusters + 2) [fact] */

void fs_clmap_size(undefined4 param_1,uint *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int local_18;
  
  local_18 = DAT_20808ba0;
  iVar4 = fs_check_ready();
  if (iVar4 != 0) {
    fs_set_error(iVar4,0);
    return;
  }
  if (param_2 == (uint *)0x0) {
    iVar4 = -0xd;
  }
  else {
    uVar3 = fs_toupper(param_1);
    iVar4 = fs_find_drive(uVar3,&local_18);
    iVar2 = local_18;
    if (iVar4 == 0) {
      cVar1 = *(char *)(local_18 + 0x10);
      if (cVar1 == '\f') {
        uVar5 = (uint)(*(int *)(local_18 + 0x6c) * *(int *)(local_18 + 0xc) * 2) / 3;
      }
      else if (cVar1 == '\x10') {
        uVar5 = (*(uint *)(local_18 + 0x6c) >> 1) * *(int *)(local_18 + 0xc);
      }
      else {
        if (cVar1 != ' ') {
          iVar4 = -0x10;
          goto LAB_2014a3b8;
        }
        uVar5 = (*(uint *)(local_18 + 0x6c) >> 2) * *(int *)(local_18 + 0xc);
      }
      iVar4 = __aeabi_uidivmod((uint)*(ushort *)(local_18 + 10) << 5,
                               *(undefined4 *)(local_18 + 0x6c));
      iVar4 = __aeabi_uidivmod(*(int *)(iVar2 + 0x14) -
                               (iVar4 + *(int *)(iVar2 + 0xc) * (uint)*(ushort *)(iVar2 + 8) +
                                        (uint)*(ushort *)(iVar2 + 6)),*(undefined2 *)(iVar2 + 4));
      if (iVar4 + 2U < uVar5) {
        uVar5 = iVar4 + 2U;
      }
      *param_2 = uVar5 >> 3;
      iVar4 = 0;
      *param_2 = (uVar5 >> 3) + (uint)((uVar5 & 7) != 0);
    }
  }
LAB_2014a3b8:
  fs_set_error(iVar4,0);
  return;
}


// ===== fs_check_ready @ 2014a4a4 (44 bytes)

/* -18 when the FS is not initialised (0x20808B90), -17 without a drive list (0x20808BA0), else 0
   [fact] */

undefined4 fs_check_ready(void)

{
  undefined4 uVar1;
  
  if (DAT_20808b90 == 0) {
    uVar1 = 0xffffffee;
  }
  else if (DAT_20808ba0 == 0) {
    uVar1 = 0xffffffef;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== fs_init @ 2014a4d0 (268 bytes)

/* (drive table, n, file table, m): clears the 0x450-byte drive and 0x24C-byte file tables
   (0x20808B90..9C), creates the pools and semaphores; errors -30/-36/-33/-39/-42 [fact] */

void fs_init(undefined4 param_1,short param_2,undefined4 param_3,short param_4)

{
  int iVar1;
  
  fs_memset(param_1,0,param_2 * 0x450);
  fs_memset(param_3,0,param_4 * 0x24c);
  DAT_20808ba0 = 0;
  DAT_20808b90 = param_1;
  DAT_20808b94 = param_2;
  DAT_20808b98 = param_3;
  DAT_20808b9c = param_4;
  fs_mpf_create();
  iVar1 = fs_work_pool_create();
  if (iVar1 < 0) {
    fs_set_error(0xffffffe2,0);
    return;
  }
  iVar1 = fs_sem_a_create();
  if (iVar1 != 0) {
    fs_set_error(0xffffffdc,0);
    return;
  }
  iVar1 = fs_sem_b_create();
  if (iVar1 != 0) {
    fs_set_error(0xffffffdf,0);
    return;
  }
  iVar1 = fs_sem1_create();
  if (iVar1 != 0) {
    fs_set_error(0xffffffd9,0);
    return;
  }
  iVar1 = fs_sem2_create();
  if (iVar1 != 0) {
    fs_set_error(0xffffffd6,0);
    return;
  }
  fs_set_error(0,0);
  return;
}


// ===== fs_drive_attach @ 2014a5dc (572 bytes)

/* (drv, letter, driver fn, ctx, no_mount, sector size): links a drive into the list 0x20808BA0,
   calls the driver (op 5 init, op 7 mount), sets up the caches [fact] */

void fs_drive_attach(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    int param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_24 [8];
  
  iVar4 = fs_check_ready();
  if (iVar4 == -0x12) {
    fs_set_error(0xffffffee,0);
    return;
  }
  fs_memset(param_1,0,0x74,param_6);
  uVar3 = fs_toupper(param_2);
  *(undefined1 *)((int)param_1 + 0x11) = uVar3;
  param_1[0x1b] = param_6;
  param_1[7] = param_4;
  param_1[6] = param_3;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  if (param_5 != 0) {
    *(undefined1 *)(param_1 + 0x1a) = 1;
  }
  param_1[0xd] = 0;
  param_1[10] = 2;
  puVar1 = param_1;
  if (DAT_20808ba0 != (undefined4 *)0x0) {
    puVar1 = DAT_20808ba0;
    for (puVar2 = (undefined4 *)*DAT_20808ba0; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      puVar1 = puVar2;
    }
    *puVar1 = param_1;
    puVar1 = DAT_20808ba0;
  }
  DAT_20808ba0 = puVar1;
  *param_1 = 0;
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined2 *)((int)param_1 + 0x4a) = 0;
  param_1[0x11] = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined2 *)((int)param_1 + 0x52) = 0;
  param_1[0x13] = 0;
  iVar4 = (*(code *)param_1[6])(param_1,5,0,0,1);
  if (iVar4 != 0) {
LAB_2014a734:
    fs_set_error_m2();
    return;
  }
  iVar4 = fs_drive_sem_create(param_1);
  if (iVar4 < 0) {
    iVar4 = -0x2d;
    goto LAB_2014a774;
  }
  if (param_5 != 0) goto LAB_2014a774;
  iVar4 = (*(code *)param_1[6])(param_1,7,0,0,1);
  if (iVar4 != 0) goto LAB_2014a734;
  iVar4 = 0;
  if (*(char *)(param_1 + 4) == '@') goto LAB_2014a774;
  if (param_1[0x1b] * (uint)*(ushort *)(param_1 + 1) < 0x20001) {
    if (*(char *)(param_1 + 4) != ' ') goto LAB_2014a774;
    if (param_1[0xf] == -1) {
      iVar5 = fs_work_alloc();
      if (iVar5 == 0) {
        iVar4 = fs_drive_sem_delete(param_1);
        if (iVar4 == 0) {
          iVar4 = -0x1f;
          goto LAB_2014a774;
        }
        goto LAB_2014a800;
      }
      iVar4 = fs_count_free((int)*(char *)((int)param_1 + 0x11),auStack_24,auStack_24,iVar5);
      fs_work_free(iVar5);
    }
    if (param_1[0x10] == -1) {
      param_1[0x10] = 2;
    }
    param_1[10] = param_1[0x10];
  }
  else {
    iVar4 = fs_drive_sem_delete(param_1);
    if (iVar4 == 0) {
      iVar4 = -0x10;
      goto LAB_2014a774;
    }
LAB_2014a800:
    iVar4 = -0x35;
  }
LAB_2014a774:
  fs_set_error(iVar4,0);
  return;
}


// ===== fs_drive_attach_thunk @ 2014a818 (36 bytes)

/* Tail call to fs_drive_attach [fact] */

void fs_drive_attach_thunk(void)

{
  fs_drive_attach();
  return;
}


// ===== fs_exit @ 2014a83c (352 bytes)

/* Reverse of fs_init: clears the tables, deletes the drive semaphores, pools and semaphores (errors
   -53..-48) [fact] */

void fs_exit(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_20808ba0;
  iVar2 = fs_check_ready();
  if (iVar2 != -0x12) {
    fs_memset(DAT_20808b90,0,DAT_20808b94 * 0x450);
    fs_memset(DAT_20808b98,0,DAT_20808b9c * 0x24c);
    DAT_20808b90 = 0;
    DAT_20808b94 = 0;
    DAT_20808b98 = 0;
    DAT_20808b9c = 0;
    piVar1 = (int *)iVar3;
    while (iVar3 != 0) {
      if ((0 < piVar1[0x1c]) && (iVar3 = fs_drive_sem_delete(piVar1), iVar3 != 0)) {
        fs_set_error(0xffffffcb,0);
        return;
      }
      iVar3 = *piVar1;
      piVar1 = (int *)*piVar1;
    }
    DAT_20808ba0 = 0;
    fs_mpf_delete();
    iVar3 = fs_work_pool_delete();
    if (iVar3 != 0) {
      fs_set_error(0xffffffd0,0);
      return;
    }
    iVar3 = fs_sem_a_delete();
    if (iVar3 != 0) {
      fs_set_error(0xffffffce,0);
      return;
    }
    iVar3 = fs_sem_b_delete();
    if (iVar3 != 0) {
      fs_set_error(0xffffffcf,0);
      return;
    }
    iVar3 = fs_sem1_delete();
    if (iVar3 != 0) {
      fs_set_error(0xffffffcd,0);
      return;
    }
    iVar3 = fs_sem2_delete();
    if (iVar3 != 0) {
      fs_set_error(0xffffffcc,0);
      return;
    }
  }
  fs_set_error(0);
  return;
}


// ===== fs_vol_clear_geometry @ 2014a99c (56 bytes)

/* Zeroes the BPB fields of a drive (type, sectors/cluster, reserved, FATs, root entries, sizes,
   root cluster, FSInfo) [fact] */

void fs_vol_clear_geometry(int param_1)

{
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}


// ===== fs_drive_mount @ 2014a9d4 (284 bytes)

/* Driver op 7 (mount) on a drive, re-reads the geometry, FAT32 free count via 0x2014B730 when
   unknown, sets mounted bit 0x80 of +0x68; -16 for clusters > 128 KB [fact] */

void fs_drive_mount(int param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_1c [8];
  
  uVar3 = fs_check_ready();
  iVar1 = (int)uVar3;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x28) = 2;
    fs_vol_clear_geometry(param_1,(int)((ulonglong)uVar3 >> 0x20));
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,7,0,0,1);
    if (iVar1 != 0) {
      fs_set_error_m2();
      return;
    }
    iVar1 = 0;
    if (*(char *)(param_1 + 0x10) != '@') {
      if (0x20000 < *(int *)(param_1 + 0x6c) * (uint)*(ushort *)(param_1 + 4)) {
        *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
        iVar1 = -0x10;
        goto LAB_2014aa68;
      }
      if (*(char *)(param_1 + 0x10) == ' ') {
        if (*(int *)(param_1 + 0x3c) == -1) {
          iVar2 = fs_work_alloc();
          if (iVar2 == 0) {
            iVar1 = -0x1f;
            goto LAB_2014aa68;
          }
          iVar1 = fs_count_free((int)*(char *)(param_1 + 0x11),auStack_1c,auStack_1c,iVar2);
          fs_work_free(iVar2);
        }
        if (*(int *)(param_1 + 0x40) == -1) {
          *(undefined4 *)(param_1 + 0x40) = 2;
        }
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x40);
      }
    }
    *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) | 0x80;
  }
LAB_2014aa68:
  fs_set_error(iVar1,0);
  return;
}


// ===== fs_drive_unmount @ 2014aaf0 (132 bytes)

/* Removable drive (+0x68 bit 0): driver op 8, clears the mounted bit; -16 when not removable [fact]
    */

void fs_drive_unmount(int param_1)

{
  int iVar1;
  
  iVar1 = fs_check_ready();
  if (iVar1 != 0) {
    fs_set_error(iVar1,0);
    return;
  }
  if ((*(byte *)(param_1 + 0x68) & 1) != 0) {
    iVar1 = (**(code **)(param_1 + 0x18))(param_1,8,0);
    if (iVar1 != 0) {
      fs_set_error_m2();
      return;
    }
    *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
    fs_set_error(0,0);
    return;
  }
  fs_set_error(0xfffffff0,0);
  return;
}


// ===== fs_drive_detach @ 2014ab74 (168 bytes)

/* Unlinks a removable drive from the drive list 0x20808BA0 and deletes its semaphore [fact] */

void fs_drive_detach(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
    fs_set_error(0xfffffff3,0);
    return;
  }
  if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
    fs_set_error(0xfffffff0,0);
    return;
  }
  iVar2 = fs_drive_sem_delete(param_1);
  if (iVar2 != 0) {
    fs_set_error(0xffffffcb,0);
    return;
  }
  if (DAT_20808ba0 == param_1) {
    DAT_20808ba0 = (int *)*param_1;
  }
  else {
    piVar1 = (int *)*DAT_20808ba0;
    piVar4 = DAT_20808ba0;
    while (piVar3 = piVar1, piVar3 != (int *)0x0) {
      if (param_1 == piVar3) {
        *piVar4 = *piVar3;
        break;
      }
      piVar4 = piVar3;
      piVar1 = (int *)*piVar3;
    }
  }
  fs_set_error(0);
  return;
}


// ===== fs_path_lookup @ 2014ac30 (492 bytes)

/* Resolves "X:\\dir\\..\\name" component by component from the root (FAT12/16 root area or FAT32
   root cluster +0x34) to its directory entry [fact] */

int fs_path_lookup(char *param_1,char *param_2,char *param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_4c;
  undefined1 auStack_48 [11];
  char local_3d;
  undefined2 local_32;
  undefined2 local_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  
  local_4c = DAT_20808ba0;
  uVar1 = fs_toupper((int)*param_1);
  iVar2 = fs_find_drive(uVar1,&local_4c);
  if ((iVar2 != 0) || (iVar2 = fs_drive_check_mounted(local_4c), iVar2 != 0)) {
    return iVar2;
  }
  param_1 = param_1 + 2;
  uVar3 = *(undefined4 *)(local_4c + 0x34);
  if (*(char *)(local_4c + 0x10) != ' ') {
    param_1 = (char *)path_next_component(param_1,param_3);
    if ((param_1 == (char *)0x0) || (*param_3 == '\0')) {
      return -1;
    }
    iVar2 = root_dir_find_locked(local_4c,param_3,auStack_48,0,0,auStack_28,param_3);
    if (iVar2 != 0) {
      if (*param_1 == '\0') {
        return -3;
      }
      return -4;
    }
    uVar3 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10));
  }
  if (*param_1 != '\0') {
    do {
      param_1 = (char *)path_next_component(param_1,param_3);
      if (param_1 == (char *)0x0) {
        return -1;
      }
      if (*param_3 == '\0') {
        return -1;
      }
      iVar2 = subdir_find_locked(local_4c,uVar3,param_3,auStack_48,0,0,auStack_28,auStack_24,param_3
                                );
      if (iVar2 != 0) {
        if (*param_1 == '\0' && iVar2 == -4) {
          return -3;
        }
        return iVar2;
      }
      uVar3 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10));
    } while (*param_1 != '\0');
  }
  fs_memcpy(param_2,auStack_48,0xb);
  if (*param_2 == '\x05') {
    *param_2 = -0x1b;
  }
  param_2[0xb] = local_3d;
  fat_time_to_tm(param_2 + 0xc,local_32,local_30);
  uVar3 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10));
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  uVar3 = fat_ld_dword(auStack_2c);
  *(undefined4 *)(param_2 + 0x34) = uVar3;
  return 0;
}


// ===== fs_stat_work @ 2014ae1c (172 bytes)

/* fs_stat with a caller work buffer: copies and normalises the path (0x2014CD68), fs_path_lookup
   [fact] */

void fs_stat_work(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = fs_check_ready();
  if (iVar1 == 0) {
    if (param_1 == 0) {
      fs_set_error(0xffffffff,0);
      return;
    }
    if (param_2 == 0) {
      fs_set_error(0xfffffff3,0);
      return;
    }
    iVar1 = fs_path_validate(param_1);
    if (iVar1 == 0) {
      iVar1 = fs_strlen(param_1);
      iVar2 = param_3 + 0x100c;
      fs_strncpy(iVar2,param_1,iVar1 + 1);
      sjis_map_ext_chars(iVar2);
      uVar3 = fs_path_lookup(iVar2,param_2,param_3);
      fs_set_error(uVar3,0);
      return;
    }
  }
  fs_set_error(iVar1,0);
  return;
}


// ===== fs_stat @ 2014aec8 (76 bytes)

/* (path, *entry): directory entry of a path, 0 when it exists; sdmenu_load_file checks a size there
   before fs_fopen, update_display_self waits for the loader file with it [fact for callers] */

undefined4 fs_stat(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_stat_work(param_1,param_2,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== fs_get_attr @ 2014af14 (48 bytes)

/* Attribute byte (entry byte 11) of a path from fs_stat; sdmenu_file_exists [fact] */

int fs_get_attr(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_40 [11];
  char local_35;
  
  iVar1 = fs_stat(param_1,auStack_40);
  if (iVar1 == 0) {
    fs_set_error(0);
    iVar1 = (int)local_35;
  }
  return iVar1;
}


// ===== fs_file_size_copy @ 2014af44 (32 bytes)

/* Copies the 4-byte size at file +0x2C [fact] */

undefined4 fs_file_size_copy(int param_1,undefined4 param_2)

{
  fs_memcpy(param_2,param_1 + 0x2c,4);
  return 0;
}


// ===== fs_fsize @ 2014af64 (100 bytes)

/* (fd, *size): file size; the firmware loaders compare it with image sizes (0x43075A in
   fwobj_sdr_run, < 0x242 in fwobj_display_run) [fact] */

void fs_fsize(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_check_ready();
  if ((iVar1 == 0) && (iVar1 = fs_file_check(param_1), iVar1 == 0)) {
    if (param_2 != 0) {
      uVar2 = fs_file_size_copy(param_1,param_2);
      fs_set_error(uVar2,param_1);
      return;
    }
    fs_set_error(0xfffffff3,param_1);
    return;
  }
  fs_set_error(iVar1,0);
  return;
}


// ===== fs_split_sectors @ 2014afcc (84 bytes)

/* Splits a sector count into whole 8 MB units and a byte remainder for a sector size [fact for the
   arithmetic] */

void fs_split_sectors(uint param_1,undefined4 *param_2,int *param_3,uint param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = __aeabi_uidivmod(0x800000,param_4 >> 9);
  if (param_1 < uVar1) {
    *param_2 = 0;
  }
  else {
    uVar2 = __aeabi_uidivmod(param_1,uVar1);
    param_1 = (uint)((ulonglong)uVar2 >> 0x20);
    *param_2 = (int)uVar2;
  }
  *param_3 = param_1 * param_4;
  return;
}


// ===== fs_disk_total_calc @ 2014b020 (288 bytes)

/* Total data size of a drive: (clusters - 2) * sectors per cluster, split by fs_split_sectors; -17
   for an unknown drive [fact] */

undefined4 fs_disk_total_calc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  piVar5 = DAT_20808ba0;
  iVar3 = fs_toupper(param_1);
  if (iVar3 != *(char *)((int)piVar5 + 0x11)) {
    do {
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) {
        return 0xffffffef;
      }
      iVar3 = fs_toupper(param_1);
    } while (iVar3 != *(char *)((int)piVar5 + 0x11));
  }
  cVar2 = (char)piVar5[4];
  if (cVar2 == '\f') {
    uVar6 = (uint)(piVar5[0x1b] * piVar5[3] * 2) / 3;
  }
  else if (cVar2 == '\x10') {
    uVar6 = ((uint)piVar5[0x1b] >> 1) * piVar5[3];
  }
  else {
    if (cVar2 != ' ') {
      return 0xfffffff3;
    }
    uVar6 = ((uint)piVar5[0x1b] >> 2) * piVar5[3];
  }
  iVar4 = piVar5[0x1b];
  iVar3 = __aeabi_uidivmod((uint)*(ushort *)((int)piVar5 + 10) << 5);
  uVar1 = *(ushort *)(piVar5 + 1);
  iVar3 = __aeabi_uidivmod(piVar5[5] -
                           (iVar3 + piVar5[3] * (uint)*(ushort *)(piVar5 + 2) +
                                    (uint)*(ushort *)((int)piVar5 + 6)));
  if (iVar3 + 2U < uVar6) {
    uVar6 = iVar3 + 2U;
  }
  fs_split_sectors((uint)uVar1 * (uVar6 - 2),param_2,param_3,iVar4);
  return 0;
}


// ===== fs_disk_size @ 2014b140 (156 bytes)

/* (letter, *hi, *lo): checked wrapper of fs_disk_total_calc; sd_info_screen [fact] */

void fs_disk_size(undefined4 param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  
  local_18 = DAT_20808ba0;
  iVar2 = fs_check_ready();
  if (iVar2 == 0) {
    if (param_2 == 0 || param_3 == 0) {
      uVar3 = 0xfffffff3;
    }
    else {
      uVar1 = fs_toupper(param_1);
      iVar2 = fs_find_drive(uVar1,&local_18);
      if ((iVar2 != 0) || (iVar2 = fs_drive_check_mounted(local_18), iVar2 != 0)) goto LAB_2014b1b0;
      uVar3 = fs_toupper(param_1);
      uVar3 = fs_disk_total_calc(uVar3,param_2,param_3);
    }
    fs_set_error(uVar3,0);
    return;
  }
LAB_2014b1b0:
  fs_set_error(iVar2,0);
  return;
}


// ===== fat32_count_free @ 2014b1e0 (436 bytes)

/* Counts the zero FAT32 entries (free clusters) [inference: same loop as fat16_count_free] */

int fat32_count_free(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int iStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar7 = 0;
  uVar3 = 0;
  uVar9 = 0;
  local_48 = 0;
  uVar6 = 0;
  local_44 = 0;
  uVar1 = *(ushort *)(param_1 + 4);
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  if ((param_5 != 0) && (*(int *)(param_1 + 0x3c) != -1)) {
    fs_split_sectors(*(int *)(param_1 + 0x3c) * (uint)uVar1,param_2,param_3,
                     *(uint *)(param_1 + 0x6c));
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0xc);
  uVar8 = (*(uint *)(param_1 + 0x6c) >> 2) * iVar4;
  iVar2 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5);
  iVar2 = __aeabi_uidivmod(*(int *)(param_1 + 0x14) -
                           (iVar2 + iVar4 * (uint)*(ushort *)(param_1 + 8) +
                                    (uint)*(ushort *)(param_1 + 6)),(uint)uVar1);
  uVar5 = 2;
  if (iVar2 + 2U < uVar8) {
    uVar8 = iVar2 + 2U;
  }
  local_40 = -1;
  if (2 < uVar8) {
    do {
      uVar11 = __aeabi_uidivmod(uVar5,*(uint *)(param_1 + 0x6c) >> 2);
      iVar2 = (int)uVar11;
      local_3c = (int)((ulonglong)uVar11 >> 0x20) << 2;
      if ((local_40 != iVar2) &&
         (iVar4 = fat_table_sector_get(param_1,iVar2,&local_44,local_28), local_40 = iVar2,
         iVar4 != 0)) {
        return iVar4;
      }
      if (local_44 == 0) {
        return -0xd;
      }
      iVar2 = fat_ld_dword(local_44 + local_3c);
      if (iVar2 == 0) {
        bVar10 = uVar3 == 0;
        uVar3 = uVar3 + 1;
        if (bVar10) {
          uVar6 = uVar5;
        }
        iVar7 = iVar7 + 1;
      }
      else {
        if (uVar9 < uVar3) {
          uVar9 = uVar3;
          local_48 = uVar6;
        }
        uVar3 = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar8);
    if (uVar3 < uVar9) {
      *(uint *)(param_1 + 0x40) = local_48;
      *(uint *)(param_1 + 0x28) = local_48;
      goto LAB_2014b36c;
    }
  }
  *(uint *)(param_1 + 0x40) = uVar6;
  *(uint *)(param_1 + 0x28) = uVar6;
LAB_2014b36c:
  *(int *)(param_1 + 0x3c) = iVar7;
  fs_split_sectors((uint)*(ushort *)(param_1 + 4) * iVar7,local_30,local_2c,
                   *(undefined4 *)(param_1 + 0x6c));
  return 0;
}


// ===== fat32_count_free_locked @ 2014b394 (84 bytes)

/* fat32_count_free under fs_lock_b [fact] */

undefined4
fat32_count_free_locked
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_b();
  if (iVar1 == 0) {
    uVar2 = fat32_count_free(param_1,param_2,param_3,param_4,param_5);
    fs_unlock_b(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== fat16_count_free @ 2014b3e8 (272 bytes)

/* Counts the zero FAT16 entries over the FAT sectors, split into size units [fact] */

int fat16_count_free(int param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  int local_38;
  int iStack_34;
  undefined4 *local_30;
  int *local_2c;
  undefined4 local_28;
  
  iVar6 = 0;
  local_38 = 0;
  iVar3 = *(int *)(param_1 + 0xc);
  uVar5 = (*(uint *)(param_1 + 0x6c) >> 1) * iVar3;
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5);
  iVar3 = __aeabi_uidivmod(*(int *)(param_1 + 0x14) -
                           (iVar1 + iVar3 * (uint)*(ushort *)(param_1 + 8) +
                                    (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  uVar4 = 2;
  iVar1 = -1;
  if (iVar3 + 2U < uVar5) {
    uVar5 = iVar3 + 2U;
  }
  if (2 < uVar5) {
    do {
      uVar7 = __aeabi_uidivmod(uVar4,*(uint *)(param_1 + 0x6c) >> 1);
      iVar3 = (int)uVar7;
      if ((iVar1 != iVar3) &&
         (iVar2 = fat_table_sector_get(param_1,iVar3,&local_38,local_28), iVar1 = iVar3, iVar2 != 0)
         ) {
        return iVar2;
      }
      if (local_38 == 0) {
        return -0xd;
      }
      iVar3 = fat_ld_word(local_38 + (int)((ulonglong)uVar7 >> 0x20) * 2);
      uVar4 = uVar4 + 1;
      if (iVar3 == 0) {
        iVar6 = iVar6 + 1;
      }
    } while (uVar4 < uVar5);
  }
  *local_30 = 0;
  *local_2c = (uint)*(ushort *)(param_1 + 4) * *(int *)(param_1 + 0x6c) * iVar6;
  return 0;
}


// ===== fat16_count_free_locked @ 2014b500 (76 bytes)

/* fat16_count_free under fs_lock_b [fact] */

undefined4
fat16_count_free_locked(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_b();
  if (iVar1 == 0) {
    uVar2 = fat16_count_free(param_1,param_2,param_3,param_4);
    fs_unlock_b(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== fat12_count_free @ 2014b54c (408 bytes)

/* FAT12 version of the free-cluster count [inference: dispatch in fs_count_free] */

int fat12_count_free(int param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  int iStack_34;
  undefined4 *local_30;
  int *local_2c;
  undefined4 local_28;
  
  iVar9 = 0;
  local_40 = 0;
  iVar5 = *(int *)(param_1 + 0xc);
  lVar1 = (ulonglong)(uint)(*(int *)(param_1 + 0x6c) * iVar5 * 2) * 0xaaaaaaab;
  uVar8 = ((uint)((ulonglong)lVar1 >> 0x20) & 0x1ffff) >> 1;
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  iVar2 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(int *)(param_1 + 0x6c),(int)lVar1)
  ;
  iVar5 = __aeabi_uidivmod(*(int *)(param_1 + 0x14) -
                           (iVar2 + iVar5 * (uint)*(ushort *)(param_1 + 8) +
                                    (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  uVar6 = 2;
  iVar2 = -1;
  if ((iVar5 + 2U & 0xffff) < uVar8) {
    uVar8 = iVar5 + 2U & 0xffff;
  }
  if (2 < uVar8) {
    do {
      iVar7 = *(int *)(param_1 + 0x6c);
      iVar5 = __aeabi_uidivmod(uVar6 * 3,iVar7 << 1);
      iVar7 = (uVar6 * 3 >> 1) - iVar7 * iVar5;
      if ((iVar2 != iVar5) &&
         (iVar3 = fat_table_sector_get(param_1,iVar5,&local_40,local_28), iVar2 = iVar5, iVar3 != 0)
         ) {
        return iVar3;
      }
      if (local_40 == 0) {
        return -0xd;
      }
      local_3c = *(undefined1 *)(local_40 + iVar7);
      if (*(int *)(param_1 + 0x6c) + -1 == iVar7) {
        iVar2 = iVar5 + 1;
        iVar7 = -1;
        iVar5 = fat_table_sector_get(param_1,iVar2,&local_40,local_28);
        if (iVar5 != 0) {
          return iVar5;
        }
      }
      local_3b = *(undefined1 *)(local_40 + iVar7 + 1);
      uVar4 = fat_ld_word(&local_3c);
      if ((uVar6 & 1) != 0) {
        uVar4 = uVar4 >> 4;
      }
      uVar4 = uVar4 & 0xffff0fff;
      if (0xff6 < uVar4) {
        uVar4 = uVar4 | 0xf000;
      }
      if (uVar4 == 0) {
        iVar9 = iVar9 + 1;
      }
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < uVar8);
  }
  *local_30 = 0;
  *local_2c = (uint)*(ushort *)(param_1 + 4) * *(int *)(param_1 + 0x6c) * iVar9;
  return 0;
}


// ===== fat12_count_free_locked @ 2014b6e4 (76 bytes)

/* fat12_count_free under fs_lock_b [fact] */

undefined4
fat12_count_free_locked(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_b();
  if (iVar1 == 0) {
    uVar2 = fat12_count_free(param_1,param_2,param_3,param_4);
    fs_unlock_b(param_1);
  }
  else {
    uVar2 = 0xffffffde;
  }
  return uVar2;
}


// ===== fs_count_free @ 2014b730 (172 bytes)

/* Free space of a drive by FAT type (FAT12/16/32 counters); fs_drive_mount uses it for an unknown
   FAT32 free count [fact] */

void fs_count_free(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int local_14;
  
  local_14 = DAT_20808ba0;
  uVar2 = fs_toupper();
  iVar3 = fs_find_drive(uVar2,&local_14);
  if (iVar3 == 0) {
    cVar1 = *(char *)(local_14 + 0x10);
    if (cVar1 == '\f') {
      fat12_count_free_locked(local_14,param_2,param_3,param_4);
      return;
    }
    if (cVar1 == '\x10') {
      fat16_count_free_locked(local_14,param_2,param_3,param_4);
      return;
    }
    if (cVar1 == ' ') {
      fat32_count_free_locked(local_14,param_2,param_3,param_4,1);
    }
  }
  return;
}


// ===== fs_disk_free_work @ 2014b7dc (164 bytes)

/* Checked wrapper of fs_count_free with a work buffer [fact] */

void fs_disk_free_work(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  
  local_18 = DAT_20808ba0;
  iVar2 = fs_check_ready();
  if (iVar2 == 0) {
    if (param_2 == 0 || param_3 == 0) {
      uVar3 = 0xfffffff3;
    }
    else {
      uVar1 = fs_toupper(param_1);
      iVar2 = fs_find_drive(uVar1,&local_18);
      if ((iVar2 != 0) || (iVar2 = fs_drive_check_mounted(local_18), iVar2 != 0)) goto LAB_2014b850;
      uVar3 = fs_toupper(param_1);
      uVar3 = fs_count_free(uVar3,param_2,param_3,param_4);
    }
    fs_set_error(uVar3,0);
    return;
  }
LAB_2014b850:
  fs_set_error(iVar2,0);
  return;
}


// ===== fs_disk_free @ 2014b880 (84 bytes)

/* (letter, *hi, *lo): free space; sd_is_full, sd_info_screen, screen_capture_bmp [fact] */

undefined4 fs_disk_free(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
    uVar2 = fs_disk_free_work(param_1,param_2,param_3,iVar1);
    fs_work_free(iVar1);
    return uVar2;
  }
  uVar2 = fs_set_error(0xffffffe1,0);
  return uVar2;
}


// ===== dirent_init @ 2014b8d4 (104 bytes)

/* Builds a 32-byte directory entry: 8.3 name, attribute, time stamps (dirent_set_time mask 7),
   first cluster, size 0 [fact] */

void dirent_init(int param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,int param_5)

{
  fs_memset(param_1,0,0x20,*(undefined4 *)(param_5 + 0x6c));
  fs_memcpy(param_1,param_2,0xb);
  *(undefined1 *)(param_1 + 0xb) = param_3;
  dirent_set_time(param_1,0,7);
  dirent_set_cluster(param_1,param_4,(int)*(char *)(param_5 + 0x10));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}

