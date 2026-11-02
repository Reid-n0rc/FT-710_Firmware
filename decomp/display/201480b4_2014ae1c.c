// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201480b4 @ 201480b4 (156 bytes)

int FUN_201480b4(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char local_18 [12];
  
  pcVar3 = local_18;
                    /* 11-byte space-padded 8.3 form of a name [doc] */
  iVar1 = sfn_pack(local_18);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_18[0] == '\0') {
    return -99;
  }
  if (local_18[0] == -0x1b) {
    local_18[0] = '\x05';
  }
  else {
    pcVar3 = local_18;
    if (local_18[0] == '\0') {
      return 0;
    }
  }
  while( true ) {
    iVar1 = sjis_is_lead(*pcVar3);
    pcVar2 = pcVar3;
    pcVar4 = param_1;
    if (iVar1 != 0) {
      pcVar2 = pcVar3 + 1;
      pcVar4 = param_1 + 1;
      if (*pcVar3 != *param_1) {
        return -99;
      }
    }
    pcVar3 = pcVar2 + 1;
    param_1 = pcVar4 + 1;
    if (*pcVar2 != *pcVar4) break;
    if (*pcVar3 == '\0') {
      return 0;
    }
  }
  return -99;
}


// ===== subdir_add_entry @ 20148150 (2048 bytes)

/* WARNING: Type propagation algorithm not settling */
/* Sub-directory counterpart of root_dir_add_entry: checks the '.' entry, then scans the cluster
   chain for a run of free entries (0xE5 / end) for the long-name count, allocates a cluster if
   needed (dir_cluster_alloc_zeroed) and writes the entries (subdir_write_lfn) [inference: the calls
   and the free-slot scan] */

uint subdir_add_entry(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                     undefined4 param_6,uint *param_7,int *param_8,int param_9)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  short sVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  uint uVar14;
  undefined6 uVar15;
  int local_b4 [4];
  int local_a4;
  char *local_a0 [4];
  undefined *puStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  int local_84;
  undefined1 auStack_80 [12];
  int local_74;
  int local_70;
  undefined1 local_6c [12];
  undefined1 auStack_60 [16];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined1 local_3c [4];
  int local_38;
  int iStack_34;
  int local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  
  local_a0[3] = &DAT_20202020;
  puStack_90 = &DAT_20202020;
  uStack_8c = 0x4e4543;
  uStack_88 = 0x87900000;
  local_a4 = 1;
  iStack_34 = param_1;
  local_30 = param_2;
  uStack_2c = param_3;
  local_28 = param_4;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(local_6c,0x20,0xb,*(undefined4 *)(param_1 + 0x6c));
  local_6c[0] = 0x2e;
  local_a0[0] = (char *)(param_9 + 0x60c);
  local_a0[1] = (char *)(param_9 + 0x80c);
  local_a0[2] = (char *)(param_9 + 0xa0c);
  fs_memset(local_a0[1],0,0x200,*(undefined4 *)(param_1 + 0x6c));
  fs_memset((char *)(param_9 + 0xa0c),0,0x200,*(undefined4 *)(param_1 + 0x6c));
  fs_memset(local_b4,0,0xc,*(undefined4 *)(param_1 + 0x6c));
  fs_memset(auStack_80,0,0xc,*(undefined4 *)(param_1 + 0x6c));
  iVar13 = 0;
  local_44 = 0;
  local_3c[0] = 0;
  uVar14 = 0xffffffff;
  uVar10 = 0;
  uVar11 = 0;
  local_50 = 0;
                    /* fat_entry_rw under fs_lock_b, result to out [doc] */
  uVar3 = fat_entry_rw_locked(param_1,&local_40,local_30,0,0x72,param_9);
  if (uVar3 == 0) {
    if (local_40 == 0) {
LAB_2014836c:
      uVar3 = 0xffffffb9;
    }
    else {
      local_70 = param_9 + 0x40c;
      iVar4 = fs_wstrcpy_len(param_3,local_70,local_3c);
      if (iVar4 != -99) {
        local_38 = 1;
        uVar3 = 0;
        local_b4[3] = (iVar4 + -1) / 0xd + 2U & 0xffff;
        local_48 = param_9 + 0x1624;
        local_74 = param_9 + 0x1600;
        do {
          iVar4 = fat_clust2sect(param_1,local_30);
          local_84 = 0;
          if (*(short *)(param_1 + 4) != 0) {
            do {
              uVar3 = dir_sector_get(param_1,iVar4,local_a0);
              pcVar12 = local_a0[0];
              if (uVar3 != 0) {
                return uVar3;
              }
              local_b4[0] = iVar4;
              if (local_a4 == 1) {
                    /* Case-insensitive compare of at most n bytes [doc] */
                    /* First cluster of an entry [doc] */
                if ((*(int *)(param_1 + 0x34) != local_30) &&
                   ((iVar5 = fs_strnicmp(local_a0[0],local_6c,0xb), iVar5 != 0 ||
                    (iVar5 = dirent_get_cluster(pcVar12,(int)*(char *)(param_1 + 0x10)),
                    iVar5 != local_30)))) goto LAB_2014836c;
                local_a4 = 0;
              }
              uVar3 = 0;
              if (*(uint *)(param_1 + 0x6c) >> 5 != 0) {
                do {
                  if (*pcVar12 == '\0') {
                    if (param_5 == 0 || param_5 == 2) {
                      return 0xfffffffc;
                    }
                    goto LAB_201483cc;
                  }
                  if ((*pcVar12 == -0x1b) && (param_5 == 1 || param_5 == 3)) {
                    if ((local_b4[3] == iVar13 + 1U) && ((int)uVar14 < 0)) {
                      uVar14 = (uint)(short)uVar3;
                      fs_memcpy(auStack_80,local_b4,0xc);
                      *param_8 = iVar4;
                      *param_7 = uVar14;
                      local_44 = local_50;
                    }
                    iVar13 = iVar13 + 1;
                  }
                  else {
                    iVar13 = 0;
                    bVar1 = pcVar12[0xb];
                    if (((bVar1 & 0x30) == 0) && ((~bVar1 & 0xf) == 0)) {
                      if (uVar11 == 0) {
                        uVar10 = 1;
                        uVar11 = uVar10;
                      }
                      else {
                        uVar10 = uVar10 + 1 & 0xffff;
                      }
                    }
                    else if (uVar11 == 0) {
                      uVar10 = 1;
                    }
                    else {
                      uVar10 = uVar10 + 1 & 0xffff;
                      uVar11 = 0;
                    }
                    if (((bVar1 & 8) == 0) && (param_5 != 3)) {
                      iVar5 = subdir_lfn_match(local_a0,pcVar12,local_70,param_1);
                      if (iVar5 == 0) {
LAB_20148840:
                        fs_memcpy(local_28,pcVar12,0x20);
                        if (param_5 == 0) {
                          *param_8 = iVar4;
                          *param_7 = uVar3;
                          *(short *)(local_74 + 0x20) = (short)uVar3;
                          *(short *)(local_74 + 0x22) = (short)local_b4[3];
                          fs_memcpy(local_48,local_b4,0xc);
                          return 0;
                        }
                        if (param_5 != 2) {
                          return 0xfffffff3;
                        }
                        uVar11 = dir_entries_mark_deleted(pcVar12,local_a0,uVar10,param_1);
                        if (uVar11 != 0) {
                          return uVar11;
                        }
                        iVar13 = (uVar10 - uVar3) + -1;
                        iVar4 = 1;
                        if (0 < iVar13) {
                          do {
                            iVar4 = iVar4 + 1;
                            iVar13 = iVar13 - (*(uint *)(param_1 + 0x6c) >> 5);
                          } while (0 < iVar13);
                        }
                        iVar13 = 0;
                        if (0 < iVar4) {
                          while( true ) {
                            if (local_b4[iVar13] == 0) {
                              return 0;
                            }
                            uVar11 = dir_sector_dirty(param_1,local_b4[iVar13],local_a0[iVar13]);
                            if (uVar11 != 0) break;
                            iVar13 = iVar13 + 1;
                            if (iVar4 <= iVar13) {
                              return 0;
                            }
                          }
                          return uVar11;
                        }
                        return 0;
                      }
                    /* Length of a UTF-16 string in bytes [doc] */
                      uVar7 = fs_wstrlen_bytes(local_70);
                      if (uVar7 < 0x19) {
                    /* UTF-16 name to 8-bit upper case [doc] */
                        fs_ucs2_to_ascii_upper(auStack_60,local_70);
                        iVar5 = FUN_201480b4(pcVar12,auStack_60,param_1);
                        if (iVar5 == 0) goto LAB_20148840;
                      }
                    }
                  }
                  uVar3 = uVar3 + 1;
                  pcVar12 = pcVar12 + 0x20;
                } while (uVar3 < *(uint *)(param_1 + 0x6c) >> 5);
              }
              pcVar2 = local_a0[1];
              pcVar12 = local_a0[0];
              pcVar9 = local_a0[2];
              iVar4 = iVar4 + 1;
              local_a0[0] = local_a0[2];
              local_a0[2] = local_a0[1];
              local_a0[1] = pcVar12;
              local_b4[2] = local_b4[1];
              local_b4[1] = local_b4[0];
              local_84 = local_84 + 1;
              local_50 = local_50 + 1;
            } while (local_84 < (int)(uint)*(ushort *)(param_1 + 4));
          }
          fat_entry_rw_locked(param_1,&local_4c,local_30,0,0x72,param_9);
          if (local_4c == 0xffffff7) {
            return 0xffffffc3;
          }
          if (local_4c + 0xf0000008U < 8) {
            if (param_5 == 0 || param_5 == 2) {
              return 0xfffffffc;
            }
            if (-1 < (int)uVar14) {
LAB_201483cc:
              if (-1 < (int)uVar14) {
                *(short *)(local_74 + 0x20) = (short)uVar14;
                *(short *)(local_74 + 0x22) = (short)local_b4[3];
                fs_memcpy(local_48,auStack_80,0xc);
                if (param_5 == 3) {
                  return 0;
                }
                    /* decimal digits of value, zero-padded to width [doc] */
                fs_utoa_zeropad(local_44 * (*(uint *)(param_1 + 0x6c) >> 5) + uVar14,local_a0 + 3,8)
                ;
                fs_memcpy(local_28,local_a0 + 3,0xb);
                uVar11 = subdir_write_lfn(param_1,auStack_80,uVar14 & 0xffff,local_28,local_70,
                                          local_b4[3],param_9);
                return uVar11;
              }
              iVar13 = (local_b4[3] + uVar3) - iVar13;
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
              uVar15 = __aeabi_uidivmod(iVar13 + -1,*(uint *)(param_1 + 0x6c) >> 5);
              sVar8 = (short)((uint6)uVar15 >> 0x20);
              iVar5 = 0;
              if ((int)uVar15 < 1) goto LAB_20148520;
              goto LAB_20148488;
            }
            local_4c = dir_cluster_alloc_zeroed(param_1,local_30,param_9);
            uVar7 = fs_task_ctx_get();
            if (uVar7 != 0) {
              return uVar7;
            }
          }
          local_30 = local_4c;
        } while( true );
      }
      uVar3 = 0xffffffba;
    }
  }
  return uVar3;
LAB_20148488:
  iVar4 = iVar4 + 1;
  uVar11 = (uint)*(ushort *)(param_1 + 4);
  if (uVar11 == 1) {
    iVar4 = dir_cluster_alloc_zeroed(param_1,local_30,param_9);
    local_30 = iVar4;
    uVar11 = fs_task_ctx_get();
    if (uVar11 != 0) {
      return uVar11;
    }
LAB_20148620:
    iVar4 = fat_clust2sect(param_1,iVar4);
  }
  else if (uVar11 == 2) {
    if (local_84 == 1) {
      iVar4 = dir_cluster_alloc_zeroed(param_1,local_30,param_9);
      uVar11 = fs_task_ctx_get();
      if (uVar11 != 0) {
        return uVar11;
      }
      goto LAB_20148620;
    }
  }
  else if (uVar11 - 1 == local_84) {
    uVar6 = dir_cluster_alloc_zeroed(param_1,local_30,param_9);
                    /* Per-task FS context 0x2091D0BC[tskid] [doc] */
    uVar11 = fs_task_ctx_get();
    if (uVar11 != 0) {
      return uVar11;
    }
    iVar4 = fat_clust2sect(param_1,uVar6);
    local_84 = 0;
  }
  iVar5 = iVar5 + 1;
  local_b4[2] = local_b4[1];
  local_b4[1] = local_b4[0];
  local_84 = local_84 + 1;
  local_b4[0] = iVar4;
  if ((int)uVar15 <= iVar5) {
LAB_20148520:
    *param_8 = iVar4;
    *param_7 = (int)sVar8;
    *(short *)(local_74 + 0x20) = sVar8;
    *(short *)(local_74 + 0x22) = (short)local_b4[3];
    fs_memcpy(local_48,local_b4,0xc);
    if (param_5 == 3) {
      return 0;
    }
    fs_utoa_zeropad(local_50 * (*(uint *)(param_1 + 0x6c) >> 5) + iVar13 + -1,local_a0 + 3,8);
    fs_memcpy(local_28,local_a0 + 3,0xb);
    if (local_38 == 0) {
      uVar11 = subdir_write_lfn(param_1,local_b4,sVar8,local_28,0,local_b4[3],param_9);
      return uVar11;
    }
    uVar11 = subdir_write_lfn(param_1,local_b4,sVar8,local_28,local_70,local_b4[3],param_9);
    return uVar11;
  }
  goto LAB_20148488;
}


// ===== subdir_add_entry_locked @ 20148990 (124 bytes)

/* fs_lock_a, subdir_add_entry, fs_unlock_a [fact] */

undefined4
subdir_add_entry_locked
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = param_2;
  uVar3 = param_3;
  uVar4 = param_4;
                    /* Locks the per-drive semaphore of table 0x2091D4C0 [doc] */
  iVar1 = fs_lock_a(param_1);
  if (iVar1 == 0) {
                    /* Sub-directory counterpart of root_dir_add_entry [doc, inference] */
    uVar2 = subdir_add_entry(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9
                             ,param_1,uVar2,uVar3,uVar4);
    fs_unlock_a(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== wpath_next_component @ 20148a0c (124 bytes)

/* (path, out): copies the next UCS-2 path component up to '\' or the end [fact] */

void wpath_next_component(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  
  if ((*param_1 != '\\') && (param_1[1] != '\0')) {
    return;
  }
  do {
    cVar2 = param_1[2];
    if (cVar2 == '\0') {
      cVar1 = param_1[3];
joined_r0x20148a4c:
      if (cVar1 == '\0') {
        *param_2 = '\0';
        param_2[1] = '\0';
        return;
      }
    }
    else if (cVar2 == '\\') {
      cVar1 = param_1[3];
      goto joined_r0x20148a4c;
    }
    *param_2 = cVar2;
    param_2[1] = param_1[3];
    param_2 = param_2 + 2;
    param_1 = param_1 + 2;
  } while( true );
}


// ===== wpath_dir_len @ 20148a88 (136 bytes)

/* (path record): byte length of the UCS-2 directory part of the path at +4 (all components but the
   last, with separators) plus 6 [fact for the loop] */

int wpath_dir_len(int param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char local_218;
  char local_217;
  
  iVar3 = 0;
  pcVar2 = (char *)(param_1 + 4);
  while ((((*pcVar2 != '\0' || (pcVar2[1] != '\0')) &&
          ((pcVar2 = (char *)wpath_next_component(pcVar2,&local_218), local_218 != '\0' ||
           (local_217 != '\0')))) && ((*pcVar2 != '\0' || (pcVar2[1] != '\0'))))) {
                    /* Length of a UTF-16 string in bytes [doc] */
    iVar1 = fs_wstrlen_bytes(&local_218);
    iVar3 = iVar1 + iVar3 + 2;
  }
  return iVar3 + 6;
}


// ===== lfn_name_valid @ 20148b10 (160 bytes)

/* (UCS-2 name): rejects characters of the invalid set *0x20808BA8 and a trailing '.' or ' ' [fact
   for the checks] */

undefined4 lfn_name_valid(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  for (; (*param_1 != '\0' || (param_1[1] != '\0')); param_1 = param_1 + 2) {
    cVar1 = *DAT_20808ba8;
    pcVar2 = DAT_20808ba8;
    while (cVar1 != '\0') {
      if ((*pcVar2 == *param_1) && (param_1[1] == '\0')) {
        return 0xffffffff;
      }
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
    }
  }
  if (param_1[-2] == '.') {
    cVar1 = param_1[-1];
  }
  else {
    if (param_1[-2] != ' ') {
      return 0;
    }
    cVar1 = param_1[-1];
  }
  if (cVar1 != '\0') {
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20148bb0 @ 20148bb0 (64 bytes)

int FUN_20148bb0(char *param_1)

{
  int iVar1;
  char cStack_210;
  char cStack_20f;
  
  if ((0x19 < (int)*param_1 - 0x41U) && (0x19 < (int)*param_1 - 0x61U)) {
    return -0xc;
  }
  if ((param_1[2] == ':') && (param_1[4] == '\\')) {
    param_1 = param_1 + 4;
    while (((*param_1 != '\0' || (param_1[1] != '\0')) &&
           ((param_1 = (char *)wpath_next_component(param_1,&cStack_210), cStack_210 != '\0' ||
            (cStack_20f != '\0'))))) {
      iVar1 = lfn_name_valid(&cStack_210);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    return 0;
  }
  return -1;
}


// ===== FUN_20148bf0 @ 20148bf0 (108 bytes)

int FUN_20148bf0(int param_1)

{
  int iVar1;
  char *pcVar2;
  char local_210;
  char local_20f;
  
  pcVar2 = (char *)(param_1 + 4);
  while (((*pcVar2 != '\0' || (pcVar2[1] != '\0')) &&
         ((pcVar2 = (char *)wpath_next_component(pcVar2,&local_210), local_210 != '\0' ||
          (local_20f != '\0'))))) {
    iVar1 = lfn_name_valid(&local_210);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}


// ===== fs_wstrlen_max @ 20148c5c (56 bytes)

/* (UCS-2 string): length in bytes, at most 0x204 [fact] */

undefined4 fs_wstrlen_max(short *param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *param_1;
  iVar2 = 0;
  while( true ) {
    if (sVar1 == 0) {
      return 0;
    }
    iVar2 = iVar2 + 2;
    if (0x204 < iVar2) break;
    param_1 = param_1 + 1;
    sVar1 = *param_1;
  }
  return 0xffffffff;
}


// ===== ucs2_to_upper @ 20148c94 (224 bytes)

/* (code): upper-case of a UCS-2 code for ASCII, full-width, Greek and Cyrillic letters (the pages
   of ucs2_eq_nocase) [fact] */

uint ucs2_to_upper(uint param_1)

{
  uint uVar1;
  
  if ((param_1 & 0xff) == 0) {
    if (0x1900 < param_1 - 0x6100) {
      return param_1;
    }
  }
  else if ((~param_1 & 0xff) == 0) {
    if (0x1900 < param_1 - 0x41ff) {
      return param_1;
    }
  }
  else {
    uVar1 = param_1 & 0xff;
    if (uVar1 == 3) {
      if ((0x1000 < param_1 - 0xb103) && (0x600 < param_1 - 0xc303)) {
        return param_1;
      }
    }
    else {
      if (uVar1 != 4) {
        if (uVar1 != 0x21) {
          return param_1;
        }
        if (0x900 < param_1 - 0x7021) {
          return param_1;
        }
        param_1 = param_1 - 0x1000;
LAB_20148cdc:
        return param_1 & 0xffff;
      }
      if (0x500 < param_1 - 0x3004) {
        if (param_1 == 0x5104) {
          param_1 = 0x104;
          goto LAB_20148cdc;
        }
        if ((0x700 < param_1 - 0x3604) && (0x1100 < param_1 - 0x3e04)) {
          return param_1;
        }
      }
    }
  }
  return param_1 - 0x2000 & 0xffff;
}


// ===== fs_wstricmp_ucs2 @ 20148d74 (120 bytes)

/* (a, b): case-insensitive UCS-2 string compare through ucs2_to_upper (also Greek, Cyrillic,
   full-width; fs_wstricmp 0x2014D3F8 folds only < 0x100); file_sync_shared uses it [fact] */

uint fs_wstricmp_ucs2(short *param_1,short *param_2)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  while( true ) {
    sVar2 = *param_2;
    if (*param_1 == 0 && sVar2 == 0) {
      return 0;
    }
    if (*param_1 == 0) {
      return 0xffffffff;
    }
    if (sVar2 == 0) {
      return 1;
    }
    iVar3 = ucs2_to_upper();
    iVar4 = ucs2_to_upper(sVar2);
    uVar1 = iVar3 - iVar4 & 0xffff;
    if (uVar1 != 0) break;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return uVar1;
}


// ===== fs_wstrnicmp_ucs2 @ 20148dec (144 bytes)

/* (a, b, n): bounded variant of fs_wstricmp_ucs2 [fact] */

uint fs_wstrnicmp_ucs2(short *param_1,short *param_2,uint param_3)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint i;
  
  i = 0;
  if (param_3 != 0) {
    do {
      sVar2 = *param_2;
      if (*param_1 == 0 && sVar2 == 0) {
        return 0;
      }
      if (*param_1 == 0) {
        return 0xffffffff;
      }
      if (sVar2 == 0) {
        return 1;
      }
      iVar3 = ucs2_to_upper();
      iVar4 = ucs2_to_upper(sVar2);
      uVar1 = iVar3 - iVar4 & 0xffff;
      if (uVar1 != 0) {
        return uVar1;
      }
      i = i + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (i < param_3);
  }
  return 0;
}


// ===== fat32_fsinfo_read @ 20148f40 (124 bytes)

/* (vol, sector): checks the FSInfo signatures "RRaA" / "rrAa" and takes the free count and
   next-free cluster [fact] */

undefined4 fat32_fsinfo_read(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,"RRaA",4);
  if ((((iVar1 == 0) && (iVar1 = memcmp(param_2 + 0x1e4,"rrAa",4), iVar1 == 0)) &&
      (*(char *)(param_2 + 0x1fe) == 'U')) && (*(char *)(param_2 + 0x1ff) == -0x56)) {
                    /* 32-bit field read from an on-disk structure [doc] */
    uVar2 = fat_ld_dword(param_2 + 0x1e8);
    *(undefined4 *)(param_1 + 0x3c) = uVar2;
    uVar2 = fat_ld_dword(param_2 + 0x1ec);
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    return 0;
  }
  return 0xffffffff;
}


// ===== fat_mount @ 20148fcc (300 bytes)

/* FAT12/16/32/EXFAT detection */

uint fat_mount(int param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = memcmp(param_2 + 3,"EXFAT",5);
  if (iVar3 == 0) {
    cVar1 = '@';
  }
  else {
    iVar3 = memcmp(param_2 + 0x52,"FAT32",5);
    if (iVar3 == 0) {
      cVar1 = ' ';
    }
    else {
      iVar3 = memcmp(param_2 + 0x36,"FAT12",5);
      if (iVar3 == 0) {
        cVar1 = '\f';
      }
      else {
        iVar3 = memcmp(param_2 + 0x36,"FAT16",5);
        if (iVar3 != 0) {
          return 0xffffffff;
        }
        cVar1 = '\x10';
      }
    }
  }
  *(char *)(param_1 + 0x10) = cVar1;
  if (cVar1 == '@') {
    return 0xffffffff;
  }
  *(ushort *)(param_1 + 4) = (ushort)*(byte *)(param_2 + 0xd);
                    /* 16-bit field read from an on-disk structure [doc] */
  uVar2 = fat_ld_word(param_2 + 0xe);
  *(undefined2 *)(param_1 + 6) = uVar2;
  *(ushort *)(param_1 + 8) = (ushort)*(byte *)(param_2 + 0x10);
  uVar2 = fat_ld_word(param_2 + 0x11);
  *(undefined2 *)(param_1 + 10) = uVar2;
  iVar3 = fat_ld_word(param_2 + 0x13);
  *(int *)(param_1 + 0x14) = iVar3;
  if (iVar3 == 0) {
                    /* 32-bit field read from an on-disk structure [doc] */
    uVar4 = fat_ld_dword(param_2 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = uVar4;
  }
  iVar3 = fat_ld_word(param_2 + 0x16);
  *(int *)(param_1 + 0xc) = iVar3;
  if (*(char *)(param_1 + 0x10) == ' ') {
    if (iVar3 == 0) {
      uVar4 = fat_ld_dword(param_2 + 0x24);
      *(undefined4 *)(param_1 + 0xc) = uVar4;
    }
    uVar4 = fat_ld_dword(param_2 + 0x2c);
    *(undefined4 *)(param_1 + 0x34) = uVar4;
    uVar2 = fat_ld_word(param_2 + 0x30);
    *(undefined2 *)(param_1 + 0x3a) = uVar2;
  }
  return 0;
}


// ===== fat_find_volume @ 201490f8 (324 bytes)

/* (vol, sector 0): partition start from the MBR (+0x1C6) or a boot sector at 0; rejects "EXFAT",
   identifies "FAT32" / "FAT12" / "FAT16" by the type strings [fact] */

undefined4 fat_find_volume(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_lr;
  
  if ((*(char *)(param_2 + 0x1fe) != 'U') || (*(char *)(param_2 + 0x1ff) != -0x56)) {
    return 0xffffffff;
  }
  iVar3 = fat_ld_dword(param_2 + 0x1c6);
  *(int *)(param_1 + 0x30) = iVar3;
  if (iVar3 == 0) {
LAB_20148e80:
    *(undefined4 *)(param_1 + 0x30) = 0;
    iVar3 = memcmp(param_2 + 3,"EXFAT",5,extraout_r3_02,unaff_r4,unaff_r5,unaff_r6,unaff_lr);
    if (iVar3 == 0) {
      cVar1 = '@';
    }
    else {
      iVar3 = memcmp(param_2 + 0x52,"FAT32",5,extraout_r3,unaff_r4,unaff_r5,unaff_r6,unaff_lr);
      if (iVar3 == 0) {
        cVar1 = ' ';
      }
      else {
        iVar3 = memcmp(param_2 + 0x36,"FAT12",5,extraout_r3_00,unaff_r4,unaff_r5,unaff_r6,unaff_lr);
        if (iVar3 == 0) {
          cVar1 = '\f';
        }
        else {
          iVar3 = memcmp(param_2 + 0x36,"FAT16",5,extraout_r3_01,unaff_r4,unaff_r5,unaff_r6,unaff_lr
                        );
          if (iVar3 != 0) {
            return 0xffffffff;
          }
          cVar1 = '\x10';
        }
      }
    }
    *(char *)(param_1 + 0x10) = cVar1;
    if (cVar1 == '@') {
      return 0xffffffff;
    }
    return 0;
  }
  cVar1 = *(char *)(param_2 + 0x1c2);
  if (cVar1 == '\a') {
    uVar2 = 0x40;
  }
  else if (cVar1 == '\x01') {
    uVar2 = 0xc;
  }
  else if ((cVar1 == '\x04' || cVar1 == '\x06') || cVar1 == '\x0e') {
    uVar2 = 0x10;
  }
  else {
    if (cVar1 != '\v' && cVar1 != '\f') goto LAB_20148e80;
    uVar2 = 0x20;
  }
  *(undefined1 *)(param_1 + 0x10) = uVar2;
  return 0;
}


// ===== fat_table_sector_get @ 2014919c (220 bytes)

/* (vol, FAT sector, *ptr): pointer to a sector of the FAT through the FAT cache (or a direct read
   without cache), -11 beyond the FAT size [fact] */

int fat_table_sector_get(int param_1,uint param_2,int *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  ulonglong __aeabi_idivmod_ret;
  uint local_18;
  
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    iVar1 = *(ushort *)(param_1 + 6) + param_2;
    local_18 = param_4;
    if (*(int *)(param_1 + 0x44) == 0) {
      iVar1 = fs_dev_op1(param_1,iVar1,param_4 + 0xc0c,1);
      if (iVar1 != 0) {
        return iVar1;
      }
      *param_3 = param_4 + 0xc0c;
    }
    else {
      iVar2 = fatcache_lookup(param_1,iVar1);
      if (iVar2 == 0) {
                    /* Evicts the oldest FAT cache slot [doc] */
        iVar1 = fatcache_load(param_1,iVar1,&local_18);
        if (iVar1 != 0) {
          return iVar1;
        }
      }
      else {
        local_18 = CONCAT22(local_18._2_2_,(short)iVar2);
      }
      *param_3 = ((local_18 & 0xffff) - 1) * *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x44) +
                 (uint)*(ushort *)(param_1 + 0x48) * 4;
      __aeabi_idivmod_ret =
           __aeabi_idivmod((local_18 & 0xffff) - 1,(uint)*(ushort *)(param_1 + 0x4a));
      local_18 = CONCAT22(local_18._2_2_,(short)__aeabi_idivmod_ret + 1);
      fatcache_touch(param_1);
    }
    iVar1 = 0;
  }
  else {
    iVar1 = -0xb;
  }
  return iVar1;
}


// ===== fat_table_sector_dirty @ 20149278 (196 bytes)

/* After a FAT change: sets the dirty bit of the FAT cache slot, or without cache writes the sector
   (fs_dev_op2) to the first and, with two FATs, the second FAT; -0x45 when the sector is not cached
   [fact] */

int fat_table_sector_dirty(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulonglong __aeabi_idivmod_ret;
  
  iVar1 = *(int *)(param_1 + 0x44);
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    iVar2 = *(ushort *)(param_1 + 6) + param_2;
    if (iVar1 == 0) {
      iVar1 = fs_dev_op2(param_1,iVar2,param_3,1);
      if (iVar1 == 0) {
        if (*(short *)(param_1 + 8) != 1) {
          iVar1 = fs_dev_op2(param_1,*(int *)(param_1 + 0xc) + iVar2,param_3,1);
          return iVar1;
        }
        iVar1 = 0;
      }
    }
    else {
      iVar2 = fatcache_lookup(param_1,iVar2);
      if (iVar2 == 0) {
        iVar1 = -0x45;
      }
      else {
        __aeabi_idivmod_ret = __aeabi_idivmod(iVar2 - 1,(uint)*(ushort *)(param_1 + 0x4a));
        uVar3 = (int)__aeabi_idivmod_ret + 1U & 0xffff;
        fatcache_touch(param_1,uVar3);
        iVar1 = iVar1 + uVar3 * 4;
        *(uint *)(iVar1 + -4) = *(uint *)(iVar1 + -4) | 0x80000000;
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = -0xb;
  }
  return iVar1;
}


// ===== fat32_entry_get @ 2014933c (120 bytes)

/* FAT32 entry: FAT sector cluster/(bps/4) via fat_table_sector_get, fat_ld_dword [fact] */

undefined4 fat32_entry_get(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 local_18;
  int local_14;
  
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  uVar3 = __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 2);
  iVar1 = fat_table_sector_get(param_1,(int)uVar3,&local_14,param_3);
  if (iVar1 == 0) {
    local_18 = *(undefined4 *)(local_14 + (int)((ulonglong)uVar3 >> 0x20) * 4);
                    /* 32-bit field read from an on-disk structure [doc] */
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  uVar3 = __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 2);
  iVar1 = fat_table_sector_get(param_1,(int)uVar3,&local_28,param_4);
  if (iVar1 == 0) {
                    /* 32-bit field read from an on-disk structure [doc] */
    uVar2 = fat_ld_dword(&uStack_1c);
    *(undefined4 *)(local_28 + (int)((ulonglong)uVar3 >> 0x20) * 4) = uVar2;
                    /* After a FAT change [doc] */
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
    iVar1 = __aeabi_uidivmod(param_2 * 3,iVar4 << 1);
    iVar4 = (param_2 * 3 >> 1) - iVar4 * iVar1;
  }
  iVar2 = fat_table_sector_get(param_1,iVar1,local_2c,param_5);
  if (iVar2 != 0) {
    return 0xffffff7;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
                    /* 16-bit field read from an on-disk structure [doc] */
    uVar3 = fat_ld_word(local_2c[0] + iVar4);
    if (param_4 == 0x77) {
      fat_st_word(local_2c[0] + iVar4,param_3 & 0xffff);
                    /* After a FAT change [doc] */
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
                    /* reads or writes a FAT12 [doc] */
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
                    /* reads or writes a FAT12 [doc] */
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
                    /* Tests a cluster's bit in the bitmap +0x58 [doc] */
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
                    /* Sets a cluster's bit in the bitmap +0x58 [doc] */
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
                    /* 32-bit field read from an on-disk structure [doc] */
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
                    /* First clear bitmap bit from the hint +0x28 [doc] */
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
                    /* Sets a cluster's bit in the bitmap +0x58 [doc] */
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
                    /* Finds a free cluster [doc] */
    uVar3 = fat32_alloc_cluster(param_1);
    return uVar3;
  }
  if (*(char *)(param_1 + 0x10) == '\x10') {
    uVar3 = (*(uint *)(param_1 + 0x6c) >> 1) * *(int *)(param_1 + 0xc);
  }
  else {
    uVar3 = (*(uint *)(param_1 + 0x6c) * *(int *)(param_1 + 0xc) * 2) / 3;
  }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  iVar2 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  iVar2 = __aeabi_uidivmod(*(int *)(param_1 + 0x14) -
                           (iVar2 + *(int *)(param_1 + 0xc) * (uint)*(ushort *)(param_1 + 8) +
                                    (uint)*(ushort *)(param_1 + 6)),*(undefined2 *)(param_1 + 4));
  if ((iVar2 + 2U & 0xffff) < uVar3) {
    uVar3 = iVar2 + 2U & 0xffff;
  }
  if ((*(int *)(param_1 + 0x58) != 0) && (*(char *)(param_1 + 0x54) != '\0')) {
                    /* First clear bitmap bit from the hint +0x28 [doc] */
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
                    /* reads or writes a FAT12 [doc] */
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
                    /* Sets a cluster's bit in the bitmap +0x58 [doc] */
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
  uint fs_task_ctx_get_ret;
  
  fs_set_error(0);
  iVar1 = fs_lock_b(param_1);
  if (iVar1 == 0) {
                    /* allocates a cluster on FAT12/16 [doc] */
    uVar2 = fat_alloc_cluster(param_1,param_2,param_4);
    *param_3 = uVar2;
    fs_unlock_b(param_1);
                    /* Per-task FS context 0x2091D0BC[tskid] [doc] */
    fs_task_ctx_get_ret = fs_task_ctx_get();
    return fs_task_ctx_get_ret;
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
                    /* reads or writes a FAT12 [doc] */
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
                    /* fat_alloc_cluster under fs_lock_b [doc] */
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
                    /* reads the FSInfo sector [doc] */
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
                    /* walks the drive list 0x20808BA0 for +0x11 == letter [doc] */
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
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
                    /* fat_entry_rw under fs_lock_b, result to out [doc] */
        iVar4 = fat_entry_rw_locked(local_28,local_24,uVar5,0,0x72,param_4);
        if (iVar4 != 0) goto LAB_2014a14c;
        if (local_24[0] != 0) {
                    /* Sets a cluster's bit in the bitmap +0x58 [doc] */
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
  
                    /* itron_tget_mpf from pool 0x20808BC8, 0 on failure [doc] */
  iVar1 = fs_work_alloc();
  if (iVar1 != 0) {
                    /* gives a drive a cluster-use bitmap [doc] */
    uVar2 = fs_clmap_attach(param_1,param_2,param_3,iVar1,1);
                    /* itron_rel_mpf to pool 0x20808BC8 [doc] */
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
                    /* walks the drive list 0x20808BA0 for +0x11 == letter [doc] */
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
  
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(param_1,0,param_2 * 0x450);
  fs_memset(param_3,0,param_4 * 0x24c);
  DAT_20808ba0 = 0;
  DAT_20808b90 = param_1;
  DAT_20808b94 = param_2;
  DAT_20808b98 = param_3;
  DAT_20808b9c = param_4;
                    /* Creates the "fsys_mpf" fixed pool 0x20808BC4 [doc] */
  fs_mpf_create();
  iVar1 = fs_work_pool_create();
  if (iVar1 < 0) {
    fs_set_error(0xffffffe2,0);
    return;
  }
                    /* Creates the five semaphores of table 0x2091D4C0 [doc] */
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
                    /* Creates semaphore 0x20808BB4 [doc] */
  iVar1 = fs_sem1_create();
  if (iVar1 != 0) {
    fs_set_error(0xffffffd9,0);
    return;
  }
                    /* Creates semaphore 0x20808BB8 [doc] */
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
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
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
                    /* itron_tget_mpf from pool 0x20808BC8, 0 on failure [doc] */
      iVar5 = fs_work_alloc();
      if (iVar5 == 0) {
        iVar4 = fs_drive_sem_delete(param_1);
        if (iVar4 == 0) {
          iVar4 = -0x1f;
          goto LAB_2014a774;
        }
        goto LAB_2014a800;
      }
                    /* Free space of a drive by FAT type [doc] */
      iVar4 = fs_count_free((int)*(char *)((int)param_1 + 0x11),auStack_24,auStack_24,iVar5);
                    /* itron_rel_mpf to pool 0x20808BC8 [doc] */
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
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
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
                    /* itron_del_mpf of pool 0x20808BC4 [doc] */
    fs_mpf_delete();
                    /* itron_del_mpf of pool 0x20808BC8 [doc] */
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
                    /* Zeroes the BPB fields of a drive [doc] */
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
                    /* itron_tget_mpf from pool 0x20808BC8, 0 on failure [doc] */
          iVar2 = fs_work_alloc();
          if (iVar2 == 0) {
            iVar1 = -0x1f;
            goto LAB_2014aa68;
          }
                    /* Free space of a drive by FAT type [doc] */
          iVar1 = fs_count_free((int)*(char *)(param_1 + 0x11),auStack_1c,auStack_1c,iVar2);
                    /* itron_rel_mpf to pool 0x20808BC8 [doc] */
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
                    /* walks the drive list 0x20808BA0 for +0x11 == letter [doc] */
  iVar2 = fs_find_drive(uVar1,&local_4c);
  if ((iVar2 != 0) || (iVar2 = fs_drive_check_mounted(local_4c), iVar2 != 0)) {
    return iVar2;
  }
  param_1 = param_1 + 2;
  uVar3 = *(undefined4 *)(local_4c + 0x34);
  if (*(char *)(local_4c + 0x10) != ' ') {
                    /* copies the "\\name" component at p [doc] */
    param_1 = (char *)path_next_component(param_1,param_3);
    if ((param_1 == (char *)0x0) || (*param_3 == '\0')) {
      return -1;
    }
                    /* root_dir_find under fs_lock_a [doc] */
    iVar2 = root_dir_find_locked(local_4c,param_3,auStack_48,0,0,auStack_28,param_3);
    if (iVar2 != 0) {
      if (*param_1 == '\0') {
        return -3;
      }
      return -4;
    }
                    /* First cluster of an entry [doc] */
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
                    /* subdir_find under fs_lock_a [doc] */
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
                    /* FAT date/time words to struct tm [doc] */
  fat_time_to_tm(param_2 + 0xc,local_32,local_30);
  uVar3 = dirent_get_cluster(auStack_48,(int)*(char *)(local_4c + 0x10));
  *(undefined4 *)(param_2 + 0x30) = uVar3;
                    /* 32-bit field read from an on-disk structure [doc] */
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
                    /* Byte-wise string length [doc] */
      iVar1 = fs_strlen(param_1);
      iVar2 = param_3 + 0x100c;
      fs_strncpy(iVar2,param_1,iVar1 + 1);
                    /* Rewrites NEC/IBM extension codes in a path [doc, inference] */
      sjis_map_ext_chars(iVar2);
      uVar3 = fs_path_lookup(iVar2,param_2,param_3);
      fs_set_error(uVar3,0);
      return;
    }
  }
  fs_set_error(iVar1,0);
  return;
}

