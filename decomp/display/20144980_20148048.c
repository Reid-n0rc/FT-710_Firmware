// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== fat_clust2sect @ 20144980 (76 bytes)

/* (vol, cluster): 0 for cluster < 2, else data start + (cluster - 2) * sectors per cluster [fact]
    */

int fat_clust2sect(int param_1,uint param_2)

{
  int iVar1;
  
  if (1 < param_2) {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
  
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
  ulonglong __aeabi_idivmod_ret;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    uVar2 = fs_dev_op2(param_1,param_2,param_3,1);
    return uVar2;
  }
  iVar1 = dircache_lookup(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffbb;
  }
  else {
    __aeabi_idivmod_ret = __aeabi_idivmod(iVar1 - 1,(uint)*(ushort *)(param_1 + 0x52));
    uVar3 = (int)__aeabi_idivmod_ret + 1U & 0xffff;
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
  ulonglong __aeabi_idivmod_ret;
  uint local_18;
  
  local_18 = param_4;
  if (*(int *)(param_1 + 0x4c) == 0) {
    iVar1 = fs_dev_op1(param_1,param_2,*param_3,1);
    return iVar1;
  }
  iVar1 = dircache_lookup(param_1);
  if (iVar1 == 0) {
                    /* Evicts the oldest directory cache slot [doc] */
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
  __aeabi_idivmod_ret = __aeabi_idivmod((local_18 & 0xffff) - 1,(uint)*(ushort *)(param_1 + 0x52));
  local_18 = CONCAT22(local_18._2_2_,(short)__aeabi_idivmod_ret + 1);
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  iVar1 = __aeabi_uidivmod((uint)*(ushort *)(param_1 + 10) << 5,*(undefined4 *)(param_1 + 0x6c));
  if (uVar4 < (uint)(iVar1 + iVar3)) {
    uVar2 = dir_sector_get(param_1,uVar4,param_3);
    return uVar2;
  }
  return 0xfffffff5;
}


// ===== lfn_entry_fill @ 20144d5c (348 bytes)

/* (entry, name part, vol): fills one 32-byte long-name directory entry: zeroed, 0xFF padding in the
   three name fields, then the UCS-2 characters [fact for the fills] */

int lfn_entry_fill(int param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
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
  int i;
  uint uVar2;
  
  uVar2 = 0;
  i = 0;
  do {
    pbVar1 = (byte *)(param_1 + i);
    i = i + 1;
    uVar2 = uVar2 + *pbVar1;
    uVar2 = (uVar2 & 1) << 7 | (uVar2 & 0xff) >> 1;
  } while (i < 10);
  return *(byte *)(param_1 + i) + uVar2 & 0xff;
}


// ===== root_dir_write_lfn @ 20144ef4 (432 bytes)

/* (vol, slot, sfn entry, long name, n, ...): writes the 8.3 entry and the n long-name entries
   before it (lfn_checksum, lfn_entry_fill) into the root directory sectors, marking each sector
   dirty [fact] */

int root_dir_write_lfn(int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,
                      int param_6)

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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  iVar2 = __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 5);
                    /* sector n of the fixed FAT12/16 root directory [doc] */
  iVar3 = root_sector_get(param_1,iVar2,&local_28);
  if (iVar3 != 0) {
    return iVar3;
  }
                    /* Checksum of an 11-byte 8.3 name [doc] */
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
                    /* fills one 32-byte long-name directory entry [doc] */
      iVar2 = lfn_entry_fill(pbVar5,param_4,param_1);
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
  
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
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


// ===== sfn_matches_long @ 20145254 (804 bytes)

/* (long name, entry, ...): compares a dotted 8.3 candidate with a name using Shift-JIS lead bytes
   and case folding (fs_char_lfn_only, sjis_fold_case_pair) [fact for the calls] */

undefined4 sfn_matches_long(char *param_1,char *param_2,char *param_3)

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
                    /* First occurrence of a character, 0 when missing [doc] */
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
                    /* Byte-wise string length [doc] */
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
                    /* Byte-pair version of sjis_fold_case [doc] */
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  iVar3 = __aeabi_uidivmod(param_2,*(uint *)(param_1 + 0x6c) >> 5);
                    /* sector n of the fixed FAT12/16 root directory [doc] */
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


// ===== sfn_match_dotted @ 2014570c (88 bytes)

/* 0 when an 11-byte 8.3 name equals sfn_from_dotted of a dotted name, -99 otherwise [fact] */

undefined4 sfn_match_dotted(char *param_1)

{
  char *pcVar1;
  char local_18 [12];
  
                    /* "NAME.EXT" to the 11-byte space-padded 8.3 form [doc] */
  sfn_from_dotted(local_18);
  pcVar1 = local_18;
  while( true ) {
    if (local_18[0] == '\0') {
      return 0;
    }
    if (*pcVar1 != *param_1) break;
    local_18[0] = pcVar1[1];
    param_1 = param_1 + 1;
    pcVar1 = pcVar1 + 1;
  }
  return 0xffffff9d;
}


// ===== sfn_numtail_match @ 20145764 (384 bytes)

/* Compares two 8.3 names whose base ends in a "~N" tail (same extension, same base before '~')
   [fact for the compare] */

int sfn_numtail_match(char *param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int i;
  int iVar6;
  char local_28 [12];
  
  iVar6 = 0;
  i = 0;
  iVar3 = 0;
  do {
    if (param_1[iVar3 + 8] != param_2[iVar3 + 8]) {
      return 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  local_28[8] = 0;
  iVar3 = 7;
  bVar2 = false;
  do {
    cVar1 = param_1[iVar3];
    if (cVar1 == ' ') {
      local_28[iVar3] = '\0';
    }
    else {
      local_28[iVar3] = cVar1;
    }
    if (cVar1 == '~' && !bVar2) {
      bVar2 = true;
      local_28[iVar3] = '\0';
    }
    if (cVar1 == ' ') {
      i = i + 1;
    }
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  iVar3 = 0;
  iVar5 = 0;
  do {
    cVar1 = local_28[iVar3];
    if (cVar1 == '\0') break;
    if (cVar1 == '~') {
      iVar5 = iVar5 + 1;
    }
    if (cVar1 != param_2[iVar3]) {
      return 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  iVar3 = 7;
  do {
    cVar1 = *param_1;
    if (i == 0) {
      if (cVar1 == '~') {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
      }
      if (cVar1 != *param_2) {
        return 0;
      }
    }
    else {
      if ((cVar1 != *param_2) && (iVar4 = sjis_is_lead(*param_2), iVar4 == 0)) {
        return 0;
      }
      if (*param_1 == '~') {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
      }
    }
    iVar3 = iVar3 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (0 < iVar3);
  if (i <= iVar3) {
    iVar3 = iVar3 - i;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    param_1 = param_1 + 1;
    iVar6 = (int)*param_1 + iVar6 * 10 + -0x30;
  }
  return iVar6;
}


// ===== ucs2_eq_nocase @ 201458e4 (536 bytes)

/* (a, b): case-insensitive equality of two UCS-2 code units for ASCII, full-width (page 0xFF),
   Greek (page 3) and Cyrillic (page 4) letters [fact] */

undefined4 ucs2_eq_nocase(byte *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = param_1[1];
  if (bVar1 == 0) {
    if ((param_2[1] == 0) &&
       (((uVar2 = (uint)*param_1, uVar2 - 0x41 < 0x1a && (uVar2 + 0x20 == (uint)*param_2)) ||
        ((uVar2 - 0x61 < 0x1a && (uVar2 - 0x20 == (uint)*param_2)))))) {
      return 1;
    }
  }
  else if (bVar1 == 0xff) {
    if (param_2[1] == 0xff) {
      uVar2 = (uint)*param_1;
      if ((uVar2 - 0x21 < 0x1a) && (uVar2 + 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 - 0x41 < 0x1a) && (uVar2 - 0x20 == (uint)*param_2)) {
        return 1;
      }
    }
  }
  else if (bVar1 == 3) {
    if (param_2[1] == 3) {
      uVar2 = (uint)*param_1;
      if ((uVar2 - 0x91 < 0x11) && (uVar2 + 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 - 0xa3 < 7) && (uVar2 + 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 - 0xb1 < 0x11) && (uVar2 - 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 - 0xc3 < 7) && (uVar2 - 0x20 == (uint)*param_2)) {
        return 1;
      }
    }
  }
  else if (bVar1 == 4) {
    if (param_2[1] == 4) {
      uVar2 = (uint)*param_1;
      if ((uVar2 - 0x10 < 0x20) && (uVar2 + 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 == 1) && (*param_2 == 0x51)) {
        return 1;
      }
      if ((uVar2 - 0x30 < 0x20) && (uVar2 - 0x20 == (uint)*param_2)) {
        return 1;
      }
      if ((uVar2 == 0x51) && (*param_2 == 1)) {
        return 1;
      }
    }
  }
  else if ((bVar1 == 0x21) && (param_2[1] == 0x21)) {
    uVar2 = (uint)*param_1;
    if ((uVar2 - 0x60 < 10) && (uVar2 + 0x10 == (uint)*param_2)) {
      return 1;
    }
    if ((uVar2 - 0x70 < 10) && (uVar2 - 0x10 == (uint)*param_2)) {
      return 1;
    }
  }
  return 0;
}


// ===== lfn_entry_get_chars @ 20145afc (232 bytes)

/* Copies the 13 UTF-16 characters of a long-name entry (offsets 1, 0x0E, 0x1C) until a 0 [fact] */

int lfn_entry_get_chars(int param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  pcVar3 = (char *)(param_1 + 1);
  iVar2 = 0;
  do {
    if ((*pcVar3 == '\0') && (pcVar3[1] == '\0')) goto LAB_20145bd8;
    iVar4 = iVar4 + 1;
    *param_2 = *pcVar3;
    pcVar1 = pcVar3 + 1;
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 2;
    param_2[1] = *pcVar1;
    param_2 = param_2 + 2;
  } while (iVar4 < 5);
  pcVar3 = (char *)(param_1 + 0xe);
  iVar4 = 0;
  do {
    if ((*pcVar3 == '\0') && (pcVar3[1] == '\0')) goto LAB_20145bd8;
    iVar4 = iVar4 + 1;
    *param_2 = *pcVar3;
    pcVar1 = pcVar3 + 1;
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 2;
    param_2[1] = *pcVar1;
    param_2 = param_2 + 2;
  } while (iVar4 < 6);
  pcVar3 = (char *)(param_1 + 0x1c);
  iVar4 = 0;
  do {
    if ((*pcVar3 == '\0') && (pcVar3[1] == '\0')) break;
    iVar4 = iVar4 + 1;
    *param_2 = *pcVar3;
    pcVar1 = pcVar3 + 1;
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 2;
    param_2[1] = *pcVar1;
    param_2 = param_2 + 2;
  } while (iVar4 < 2);
LAB_20145bd8:
  *param_2 = '\0';
  return iVar2;
}


// ===== root_lfn_collect @ 20145be4 (512 bytes)

/* Gathers the long name stored before a root-directory entry [inference] */

int root_lfn_collect(int param_1,int param_2,short *param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int extraout_r1;
  short *psVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  undefined8 uVar7;
  byte *local_50;
  short local_4c [14];
  int local_30;
  uint local_2c;
  
  local_30 = -1;
  local_50 = (byte *)(param_6 + 0xe0c);
  uVar4 = *(uint *)(param_1 + 0x6c) >> 5;
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
  uVar7 = __aeabi_uidivmod(param_2,uVar4);
  iVar6 = (int)uVar7;
  if ((param_2 != 0) && ((int)((ulonglong)uVar7 >> 0x20) == 0)) {
    iVar6 = __aeabi_uidivmod(param_2 + -1,uVar4);
  }
                    /* sector n of the fixed FAT12/16 root directory [doc] */
  iVar1 = root_sector_get(param_1,iVar6,&local_50);
  if (iVar1 == 0) {
    uVar4 = *(uint *)(param_1 + 0x6c);
    __aeabi_uidivmod(param_2,uVar4 >> 5);
    if (extraout_r1 == 0) {
      uVar4 = uVar4 & 0xffffffe0;
    }
    else {
      uVar4 = extraout_r1 * 0x20;
    }
    pbVar5 = local_50 + uVar4;
    if (param_2 == 0) {
      pbVar5 = local_50 + 0x20;
    }
    uVar4 = 1;
    if (1 < param_4) {
      local_2c = param_4 - 1;
      do {
        pbVar5 = pbVar5 + -0x20;
                    /* Copies the 13 UTF-16 characters of a long-name entry [doc] */
        iVar1 = lfn_entry_get_chars(pbVar5,local_4c);
        psVar3 = local_4c;
        while (iVar1 != 0) {
          iVar1 = iVar1 + -1;
          if ((*param_3 != *psVar3) && (iVar2 = ucs2_eq_nocase(param_3,psVar3), iVar2 == 0)) {
            if ((iVar6 != param_5) &&
               (iVar6 = root_sector_get(param_1,param_5,&local_50), iVar6 != 0)) {
              return iVar6;
            }
            goto LAB_20145dac;
          }
          param_3 = param_3 + 1;
          psVar3 = psVar3 + 1;
        }
        if ((pbVar5 == local_50) && (uVar4 != local_2c)) {
          iVar6 = iVar6 + -1;
          iVar1 = root_sector_get(param_1,iVar6,&local_50);
          if (iVar1 != 0) {
            return iVar1;
          }
          pbVar5 = local_50 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < param_4);
    }
    if ((*pbVar5 & 0x40) != 0) {
      local_30 = 0;
    }
    if (((iVar6 == param_5) || (iVar1 = root_sector_get(param_1,param_5,&local_50), iVar1 == 0)) &&
       (iVar1 = local_30, (char)*param_3 != '\0')) {
LAB_20145dac:
      iVar1 = -99;
    }
  }
  return iVar1;
}


// ===== root_dir_find @ 20145df0 (1340 bytes)

/* Searches the fixed FAT12/16 root directory for a name (long or 8.3) [inference: called by
   root_dir_find_locked, first step of fs_path_lookup on FAT12/16] */

int root_dir_find(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 uint *param_6,int param_7)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  char local_80 [16];
  undefined1 auStack_70 [16];
  undefined4 local_60;
  undefined4 uStack_5c;
  int local_58;
  undefined1 auStack_54 [16];
  int local_44;
  char local_40 [4];
  char *local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int iStack_28;
  
  uVar8 = 0xffffffff;
  uVar10 = 0;
  local_38 = 0xffffffff;
  uVar5 = 0;
  uVar9 = 0;
  pcVar4 = (char *)0x0;
  local_40[0] = '\0';
  local_60 = 0x31;
  uStack_5c = 0;
  local_3c = (char *)(param_7 + 0xe0c);
  local_44 = param_7 + 0x40c;
  local_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  iStack_28 = param_4;
  iVar3 = sjis_to_ucs2_str(param_2,local_44,local_40);
  if (iVar3 == -99) {
    return -0x46;
  }
  cVar2 = sfn_matches_long(local_30,auStack_70,&local_60);
  if (cVar2 == '\x01') {
    uVar5 = (iVar3 + -1) / 0xd + 1U & 0xffff;
  }
  else if (cVar2 == '\0') goto LAB_20145edc;
  if ((local_40[0] == '\0') && (param_4 == 0 || param_4 == 2)) {
    fs_memcpy(auStack_54,local_30,0xd);
                    /* Case-insensitive string compare [doc] */
    fs_stricmp(auStack_70,auStack_54);
  }
LAB_20145edc:
  uVar7 = 0;
  uVar6 = uVar5 + 1 & 0xffff;
  local_58 = param_7 + 0x1600;
  uVar1 = (undefined2)(uVar5 + 1);
  if (*(short *)(local_34 + 10) != 0) {
    do {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
      uVar12 = __aeabi_uidivmod(uVar7,*(uint *)(local_34 + 0x6c) >> 5);
      uVar13 = (undefined4)uVar12;
                    /* sector n of the fixed FAT12/16 root directory [doc] */
      if (((int)((ulonglong)uVar12 >> 0x20) == 0) &&
         (iVar3 = root_sector_get(local_34,uVar13,&local_3c), pcVar4 = local_3c, local_38 = uVar13,
         iVar3 != 0)) {
        return iVar3;
      }
      if (pcVar4 == (char *)0x0) {
        return -0xd;
      }
      if (*pcVar4 == -0x1b) {
        if (param_4 != 0 && param_4 != 2) {
          uVar10 = uVar10 + 1 & 0xffff;
          bVar11 = uVar10 == uVar6;
          if (uVar6 <= uVar10) {
            bVar11 = uVar8 == 0xffffffff;
          }
          if (bVar11) {
            uVar8 = (uint)(short)uVar7;
          }
        }
      }
      else {
        if (*pcVar4 == '\0') {
          if (param_4 == 0 || param_4 == 2) {
            return -0x47;
          }
          if (999999 < uVar9) {
            return -0x42;
          }
          if (uVar9 != 0) {
            fs_utoa6(&local_60,uVar9);
          }
          cVar2 = sfn_matches_long(local_30,auStack_70,&local_60);
                    /* "NAME.EXT" to the 11-byte space-padded 8.3 form [doc] */
          sfn_from_dotted(local_80,auStack_70,local_34);
          if (local_80[0] == -0x1b) {
            local_80[0] = '\x05';
          }
          fs_memcpy(local_2c,local_80,0xb);
          if ((int)uVar8 < 0) {
            if (((*(ushort *)(local_34 + 10) - uVar7) + uVar10 & 0xffff) < uVar6) {
              return -0x42;
            }
            uVar8 = ((uVar7 + uVar6) - uVar10) - 1;
            *param_6 = uVar8;
            *(short *)(local_58 + 0x20) = (short)uVar8;
            *(undefined2 *)(local_58 + 0x22) = uVar1;
            if (param_4 != 3) {
              if (cVar2 != '\x01') {
                iVar3 = root_dir_write_lfn(local_34,uVar8 & 0xffff,local_2c,0,uVar6,param_7);
                return iVar3;
              }
              iVar3 = root_dir_write_lfn(local_34,uVar8 & 0xffff,local_2c,local_44,uVar6,param_7);
              return iVar3;
            }
            return 0;
          }
          *param_6 = uVar8;
          *(short *)(local_58 + 0x20) = (short)uVar8;
          *(undefined2 *)(local_58 + 0x22) = uVar1;
          goto joined_r0x20146034;
        }
        uVar10 = 0;
        if (((pcVar4[0xb] & 8U) == 0) && (param_4 != 3)) {
          iVar3 = root_lfn_collect(local_34,uVar7,local_44,uVar6,local_38,param_7);
          sfn_from_dotted(local_80,auStack_70,local_34);
          if (local_80[0] == -0x1b) {
            local_80[0] = '\x05';
          }
          uVar5 = sfn_numtail_match(pcVar4,local_80);
          if (uVar9 <= uVar5) {
            uVar9 = uVar5 + 1;
          }
          if (iVar3 == 0) {
LAB_201461a8:
            if (param_4 == 1) {
              return -0xd;
            }
            fs_memcpy(local_2c,pcVar4,0x20);
            if (param_4 == 2) {
              iVar3 = root_dirent_delete(local_34,uVar7,uVar6,param_7);
              return iVar3;
            }
            if (param_4 == 0) {
              *param_6 = uVar7;
              *(short *)(local_58 + 0x20) = (short)uVar7;
              *(undefined2 *)(local_58 + 0x22) = uVar1;
              return 0;
            }
          }
          else {
                    /* Byte-wise string length [doc] */
            uVar5 = fs_strlen(local_30);
            if (uVar5 < 0xd) {
              if (uVar9 != 0) {
                fs_utoa6(&local_60,uVar9);
              }
              sfn_matches_long(local_30,auStack_70,&local_60);
              sfn_from_dotted(local_80,auStack_70,local_34);
              if (local_80[0] == -0x1b) {
                local_80[0] = '\x05';
              }
              iVar3 = sfn_match_dotted(pcVar4,local_80,local_34);
              if (iVar3 == 0) goto LAB_201461a8;
            }
          }
        }
      }
      pcVar4 = pcVar4 + 0x20;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *(ushort *)(local_34 + 10));
  }
  if (param_4 == 1 || param_4 == 3) {
    if (-1 < (int)uVar8) {
      if (999999 < uVar9) {
        return -0x42;
      }
      if (uVar9 != 0) {
        fs_utoa6(&local_60,uVar9);
      }
      sfn_matches_long(local_30,auStack_70,&local_60);
      sfn_from_dotted(local_80,auStack_70,local_34);
      if (local_80[0] == -0x1b) {
        local_80[0] = '\x05';
      }
      fs_memcpy(local_2c,local_80,0xb);
      *param_6 = uVar8;
      *(short *)(local_58 + 0x20) = (short)uVar8;
      *(undefined2 *)(local_58 + 0x22) = uVar1;
joined_r0x20146034:
      if (param_4 == 3) {
        return 0;
      }
      iVar3 = root_dir_write_lfn(local_34,uVar8 & 0xffff,local_2c,local_44,uVar6,param_7);
      return iVar3;
    }
    if (param_4 == 3) {
      return -0xb;
    }
  }
  return -0x47;
}


// ===== root_dir_find_locked @ 20146338 (108 bytes)

/* root_dir_find under fs_lock_a (-37 on lock failure) [fact] */

undefined4
root_dir_find_locked
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* Locks the per-drive semaphore of table 0x2091D4C0 [doc] */
  iVar1 = fs_lock_a();
  if (iVar1 == 0) {
                    /* Searches the fixed FAT12/16 root directory for a name [doc, inference] */
    uVar2 = root_dir_find(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    fs_unlock_a(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== dir_cluster_alloc_zeroed @ 201463a4 (204 bytes)

/* (vol, cluster, work): allocates a cluster for a directory (fat_alloc_cluster_locked) and writes
   zero sectors to it (fs_dev_op2); errors to fs_set_error [fact] */

int dir_cluster_alloc_zeroed(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int i;
  int local_18;
  
  local_18 = param_4;
                    /* fat_alloc_cluster under fs_lock_b [doc] */
  iVar1 = fat_alloc_cluster_locked(param_1,param_2,&local_18,param_3);
  if (iVar1 == 0) {
    if (local_18 == 0) {
      fs_set_error(0xfffffff5,0);
      return 0;
    }
    iVar2 = fat_clust2sect(param_1);
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
    fs_memset(param_3 + 0x60c,0,0x200);
    i = 0;
    if (*(short *)(param_1 + 4) != 0) {
      do {
        iVar1 = fs_dev_op2(param_1,iVar2,param_3 + 0x60c,1);
        if (iVar1 != 0) goto LAB_20146424;
        i = i + 1;
        iVar2 = iVar2 + 1;
      } while (i < (int)(uint)*(ushort *)(param_1 + 4));
    }
    fs_set_error(0);
    return local_18;
  }
LAB_20146424:
  fs_set_error(iVar1,0);
  return 0;
}


// ===== dir_entries_mark_deleted @ 20146470 (176 bytes)

/* (entry, sector list, count, vol): writes 0xE5 into the 8.3 entry and its long-name entries,
   walking back over up to three directory sectors [fact] */

undefined4 dir_entries_mark_deleted(undefined1 *param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int i;
  
  i = 0;
  uVar2 = param_3;
  do {
    if (uVar2 == 0) {
      return 0;
    }
    while( true ) {
      if ((param_3 == uVar2) || (param_1[0xb] == '\x0f')) {
        *param_1 = 0xe5;
      }
      if (*(undefined1 **)(param_2 + i * 4) == param_1) break;
      if ((uVar2 != 0) && (param_1[-0x15] != '\x0f')) {
        return 0;
      }
      uVar2 = uVar2 - 1 & 0xffff;
      param_1 = param_1 + -0x20;
      if (uVar2 == 0) {
        return 0;
      }
    }
    uVar2 = uVar2 - 1 & 0xffff;
    if (uVar2 == 0) {
      return 0;
    }
    iVar1 = i * 4;
    i = i + 1;
    param_1 = (undefined1 *)
              (*(int *)(param_2 + iVar1 + 4) + (*(uint *)(param_4 + 0x6c) & 0xffffffe0) + -0x20);
  } while (i < 3);
  return 0xffffffbc;
}


// ===== sfn_equals @ 20146520 (140 bytes)

/* (entry name, dotted name): converts the dotted name to 8.3 (sfn_from_dotted, leading 0xE5 ->
   0x05) and compares, Shift-JIS aware [fact] */

undefined4 sfn_equals(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char local_18 [12];
  
  pcVar3 = local_18;
                    /* "NAME.EXT" to the 11-byte space-padded 8.3 form [doc] */
  sfn_from_dotted(local_18);
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
        return 0xffffff9d;
      }
    }
    pcVar3 = pcVar2 + 1;
    param_1 = pcVar4 + 1;
    if (*pcVar2 != *pcVar4) break;
    if (*pcVar3 == '\0') {
      return 0;
    }
  }
  return 0xffffff9d;
}


// ===== sfn_numtail_next @ 201465ac (92 bytes)

/* (..., tail string): keeps the next free numeric tail: when the entry's tail (sfn_numtail_match)
   is >= the current one, stores tail + 1 as a decimal string; -66 above 9999998 [fact] */

undefined4 sfn_numtail_next(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_18 [12];
  
  iVar1 = sfn_numtail_match();
                    /* Second identical copy of fs_atoi [doc] */
  iVar2 = fs_atoi_2(param_3);
  if (iVar2 <= iVar1) {
    if (0x98967e < iVar1) {
      return 0xffffffbe;
    }
                    /* Second identical copy of fs_itoa [doc] */
    fs_itoa_2(iVar1 + 1,auStack_18,10);
                    /* Byte string copy including the terminator [doc] */
    fs_strcpy(param_3,auStack_18);
  }
  return 0;
}


// ===== subdir_lfn_match @ 20146608 (228 bytes)

/* (vol, entry, long name): checksum and long-name characters of an entry chain compared with
   ucs2_eq_nocase [fact for the calls] */

undefined4 subdir_lfn_match(int param_1,byte *param_2,short *param_3,int param_4)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  short local_40 [14];
  
  iVar7 = 0;
                    /* Checksum of an 11-byte 8.3 name [doc] */
  uVar2 = lfn_checksum(param_2);
  do {
    pbVar1 = param_2;
    if (*(byte **)(param_1 + iVar7 * 4) == param_2) {
      iVar7 = iVar7 + 1;
      iVar3 = *(int *)(param_1 + iVar7 * 4);
      if (iVar3 == 0) goto LAB_201466e0;
      pbVar1 = (byte *)(iVar3 + (*(uint *)(param_4 + 0x6c) & 0xffffffe0));
    }
    param_2 = pbVar1 + -0x20;
    if ((pbVar1[-0x15] != 0xf) || (pbVar1[-0x13] != uVar2)) goto LAB_201466e0;
                    /* Copies the 13 UTF-16 characters of a long-name entry [doc] */
    iVar3 = lfn_entry_get_chars(param_2,local_40);
    psVar6 = local_40;
    for (; 0 < iVar3; iVar3 = iVar3 + -1) {
      if ((*param_3 != *psVar6) && (iVar4 = ucs2_eq_nocase(param_3,psVar6), iVar4 == 0))
      goto LAB_201466e0;
      param_3 = param_3 + 1;
      psVar6 = psVar6 + 1;
    }
  } while ((*param_2 & 0x40) == 0);
  uVar5 = 0;
  if (*param_3 != 0) {
LAB_201466e0:
    uVar5 = 0xffffff9d;
  }
  return uVar5;
}


// ===== subdir_write_lfn @ 201466ec (408 bytes)

/* (vol, sector list, slot, sfn entry, long name, ...): the same for a sub-directory, across up to
   three sectors (dir_sector_get / dir_sector_dirty) [fact] */

void subdir_write_lfn(int param_1,undefined4 *param_2,int param_3,char *param_4,int param_5,
                     int param_6,int param_7)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte bVar6;
  byte *local_28;
  
  iVar5 = 0;
  param_4[0xc] = '\0';
  local_28 = (byte *)(param_7 + 0x60c);
  iVar2 = dir_sector_get(param_1,*param_2,&local_28);
  if (iVar2 != 0) {
    return;
  }
  pbVar3 = local_28 + param_3 * 0x20;
  if (*param_4 == -0x1b) {
    *param_4 = '\x05';
  }
  fs_memcpy(pbVar3,param_4,0x20);
  param_6 = param_6 + -1;
  if (param_6 == 0) {
    dir_sector_dirty(param_1,*param_2,local_28);
    return;
  }
  if (pbVar3 == local_28) {
    iVar2 = dir_sector_dirty(param_1,*param_2);
    if (iVar2 != 0) {
      return;
    }
    iVar5 = 1;
    iVar2 = dir_sector_get(param_1,param_2[1],&local_28);
    if (iVar2 != 0) {
      return;
    }
    pbVar3 = local_28 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
  }
                    /* Checksum of an 11-byte 8.3 name [doc] */
  bVar1 = lfn_checksum(param_4);
  bVar6 = 1;
  do {
    pbVar4 = pbVar3 + -0x20;
                    /* fills one 32-byte long-name directory entry [doc] */
    iVar2 = lfn_entry_fill(pbVar4,param_5,param_1);
    *pbVar4 = bVar6;
    param_5 = param_5 + iVar2 * 2;
    pbVar3[-0x15] = 0xf;
    pbVar3[-0x13] = bVar1;
    if ((pbVar4 == local_28) && (param_6 != 1)) {
      iVar2 = dir_sector_dirty(param_1,param_2[iVar5]);
      if (iVar2 != 0) {
        return;
      }
      iVar5 = iVar5 + 1;
      iVar2 = dir_sector_get(param_1,param_2[iVar5],&local_28);
      if (iVar2 != 0) {
        return;
      }
      pbVar4 = local_28 + (*(uint *)(param_1 + 0x6c) & 0xffffffe0);
    }
    param_6 = param_6 + -1;
    bVar6 = bVar6 + 1;
    pbVar3 = pbVar4;
    if (param_6 == 0) {
      *pbVar4 = *pbVar4 | 0x40;
      dir_sector_dirty(param_1,param_2[iVar5],local_28);
      return;
    }
  } while( true );
}


// ===== dirent_get_cluster @ 20146884 (60 bytes)

/* First cluster of an entry (+0x1A, | +0x14 << 16 except FAT12/16) [fact] */

int dirent_get_cluster(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0xc && param_2 != 0x10) {
                    /* 16-bit field read from an on-disk structure [doc] */
    iVar1 = fat_ld_word(param_1 + 0x1a);
    iVar2 = fat_ld_word(param_1 + 0x14);
    return iVar1 + iVar2 * 0x10000;
  }
  iVar1 = fat_ld_word(param_1 + 0x1a);
  return iVar1;
}


// ===== subdir_find @ 201468c0 (2308 bytes)

/* WARNING: Type propagation algorithm not settling */
/* Searches a directory cluster chain for a name: builds the 8.3 form, compares long-name entries
   (lfn checksum), follows the FAT (fat_entry_rw_locked), returns the entry and its position
   [inference] */

uint subdir_find(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                undefined4 param_6,uint *param_7,int *param_8,int param_9)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  uint uVar14;
  undefined6 uVar15;
  int local_d4 [3];
  undefined1 auStack_c8 [16];
  char *local_b8 [3];
  char local_ac [12];
  char local_a0 [16];
  uint local_90;
  int local_8c;
  undefined1 local_88;
  undefined1 local_87;
  undefined1 auStack_80 [12];
  int local_74;
  int local_70;
  undefined1 local_6c [12];
  undefined1 auStack_60 [16];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  char local_40 [4];
  int local_3c [2];
  int iStack_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_44 = 1;
  iStack_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(local_6c,0x20,0xb,*(undefined4 *)(param_1 + 0x6c));
  local_6c[0] = 0x2e;
  local_b8[0] = (char *)(param_9 + 0x60c);
  local_b8[1] = (char *)(param_9 + 0x80c);
  local_a0[0] = '\0';
  local_b8[2] = (char *)(param_9 + 0xa0c);
  fs_memset(local_b8[1],0,0x200,*(undefined4 *)(param_1 + 0x6c));
  fs_memset((char *)(param_9 + 0xa0c),0,0x200,*(undefined4 *)(param_1 + 0x6c));
  fs_memset(local_d4,0,0xc,*(undefined4 *)(param_1 + 0x6c));
  fs_memset(auStack_80,0,0xc,*(undefined4 *)(param_1 + 0x6c));
  local_40[0] = '\0';
  iVar13 = 0;
  local_88 = 0x31;
  uVar14 = 0xffffffff;
  uVar11 = 0;
  local_87 = 0;
  uVar9 = 0;
  uVar10 = 0;
                    /* fat_entry_rw under fs_lock_b, result to out [doc] */
  uVar3 = fat_entry_rw_locked(param_1,local_3c,local_30,0,0x72,param_9);
  if (uVar3 == 0) {
    if (local_3c[0] == 0) {
LAB_20146b94:
      uVar3 = 0xffffffb9;
    }
    else {
      local_50 = param_9 + 0x40c;
      iVar4 = sjis_to_ucs2_str(local_2c,local_50,local_40);
      if (iVar4 != -99) {
                    /* Byte-wise string length [doc] */
        if ((param_5 == 0 || param_5 == 2) && (uVar3 = fs_strlen(local_2c), uVar3 < 0xd)) {
                    /* Byte string copy including the terminator [doc] */
          fs_strcpy(local_a0,local_2c);
                    /* Lower-cases a string in place, skipping Shift-JIS pairs [doc] */
          fs_strlwr_sjis(local_a0);
        }
        if (local_a0[0] == '\0') {
          local_70 = sfn_matches_long(local_2c,auStack_c8,&DWORD_20146dcc);
        }
        else {
          local_70 = sfn_matches_long(local_a0,auStack_c8,&DWORD_20146dcc);
        }
        if (local_70 == 1) {
          uVar11 = (iVar4 + -1) / 0xd + 1U & 0xffff;
        }
        local_90 = uVar11 + 1 & 0xffff;
        if (((local_70 != 0) && (local_40[0] == '\0')) && (param_5 == 0 || param_5 == 2)) {
          fs_memcpy(auStack_60,local_a0,0xd);
                    /* Case-insensitive string compare [doc] */
          iVar4 = fs_stricmp(auStack_c8,auStack_60);
          if (iVar4 == 0) {
            local_70 = 0;
          }
        }
        uVar3 = 0;
        local_48 = param_9 + 0x1624;
        local_74 = param_9 + 0x1600;
        do {
          iVar4 = fat_clust2sect(param_1,local_30);
          local_8c = 0;
          if (*(short *)(param_1 + 4) != 0) {
            do {
              uVar3 = dir_sector_get(param_1,iVar4,local_b8);
              pcVar12 = local_b8[0];
              if (uVar3 != 0) {
                return uVar3;
              }
              local_d4[0] = iVar4;
              if (local_44 == 1) {
                    /* Case-insensitive compare of at most n bytes [doc] */
                    /* First cluster of an entry [doc] */
                if ((*(int *)(param_1 + 0x34) != local_30) &&
                   ((iVar5 = fs_strnicmp(local_b8[0],local_6c,0xb), iVar5 != 0 ||
                    (iVar5 = dirent_get_cluster(pcVar12,(int)*(char *)(param_1 + 0x10)),
                    iVar5 != local_30)))) goto LAB_20146b94;
                local_44 = 0;
              }
              uVar3 = 0;
              if (*(uint *)(param_1 + 0x6c) >> 5 != 0) {
                do {
                  if (*pcVar12 == '\0') {
                    if (param_5 == 0 || param_5 == 2) {
                      return 0xfffffffc;
                    }
                    goto LAB_20146bf4;
                  }
                  if ((*pcVar12 == -0x1b) && (param_5 == 1 || param_5 == 3)) {
                    if ((local_90 == iVar13 + 1U) && ((int)uVar14 < 0)) {
                      uVar14 = (uint)(short)uVar3;
                      fs_memcpy(auStack_80,local_d4,0xc);
                      *param_8 = iVar4;
                      *param_7 = uVar14;
                    }
                    iVar13 = iVar13 + 1;
                  }
                  else {
                    iVar13 = 0;
                    bVar1 = pcVar12[0xb];
                    if (((bVar1 & 0x30) == 0) && ((~bVar1 & 0xf) == 0)) {
                      if (uVar10 == 0) {
                        uVar9 = 1;
                        uVar10 = uVar9;
                      }
                      else {
                        uVar9 = uVar9 + 1 & 0xffff;
                      }
                    }
                    else if (uVar10 == 0) {
                      uVar9 = 1;
                    }
                    else {
                      uVar9 = uVar9 + 1 & 0xffff;
                      uVar10 = 0;
                    }
                    if (((bVar1 & 8) == 0) && (param_5 != 3)) {
                      if ((param_5 == 1) && (local_70 == 1)) {
                        sfn_from_dotted(local_ac,auStack_c8,param_1);
                        if (local_ac[0] == -0x1b) {
                          local_ac[0] = '\x05';
                        }
                    /* keeps the next free numeric tail [doc] */
                        uVar11 = sfn_numtail_next(pcVar12,local_ac,&local_88);
                        if (uVar11 != 0) {
                          return uVar11;
                        }
                      }
                      iVar5 = subdir_lfn_match(local_b8,pcVar12,local_50,param_1);
                      if (iVar5 == 0) {
LAB_201470bc:
                        fs_memcpy(local_28,pcVar12,0x20);
                        if (param_5 == 0) {
                          *param_8 = iVar4;
                          *param_7 = uVar3;
                          *(short *)(local_74 + 0x20) = (short)uVar3;
                          *(short *)(local_74 + 0x22) = (short)local_90;
                          fs_memcpy(local_48,local_d4,0xc);
                          return 0;
                        }
                        if (param_5 != 2) {
                          return 0xfffffff3;
                        }
                        uVar10 = dir_entries_mark_deleted(pcVar12,local_b8,uVar9,param_1);
                        if (uVar10 != 0) {
                          return uVar10;
                        }
                        iVar13 = (uVar9 - uVar3) + -1;
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
                            if (local_d4[iVar13] == 0) {
                              return 0;
                            }
                            uVar10 = dir_sector_dirty(param_1,local_d4[iVar13],local_b8[iVar13]);
                            if (uVar10 != 0) break;
                            iVar13 = iVar13 + 1;
                            if (iVar4 <= iVar13) {
                              return 0;
                            }
                          }
                          return uVar10;
                        }
                        return 0;
                      }
                      uVar11 = fs_strlen(local_2c);
                      if (uVar11 < 0xd) {
                        sfn_from_dotted(local_ac,auStack_c8,param_1);
                        if (local_ac[0] == -0x1b) {
                          local_ac[0] = '\x05';
                        }
                        uVar11 = sfn_numtail_next(pcVar12,local_ac,&local_88);
                        if (uVar11 != 0) {
                          return uVar11;
                        }
                        sfn_matches_long(local_2c,auStack_c8,&local_88);
                    /* converts the dotted name to 8.3 [doc] */
                        iVar5 = sfn_equals(pcVar12,auStack_c8,param_1);
                        if (iVar5 == 0) goto LAB_201470bc;
                      }
                    }
                  }
                  uVar3 = uVar3 + 1;
                  pcVar12 = pcVar12 + 0x20;
                } while (uVar3 < *(uint *)(param_1 + 0x6c) >> 5);
              }
              pcVar2 = local_b8[1];
              pcVar12 = local_b8[0];
              iVar4 = iVar4 + 1;
              pcVar8 = local_b8[2];
              local_b8[0] = local_b8[2];
              local_b8[2] = local_b8[1];
              local_b8[1] = pcVar12;
              local_d4[2] = local_d4[1];
              local_d4[1] = local_d4[0];
              local_8c = local_8c + 1;
            } while (local_8c < (int)(uint)*(ushort *)(param_1 + 4));
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
LAB_20146bf4:
              sfn_matches_long(local_2c,auStack_c8,&local_88);
                    /* "NAME.EXT" to the 11-byte space-padded 8.3 form [doc] */
              sfn_from_dotted(local_ac,auStack_c8,param_1);
              fs_memcpy(local_28,local_ac,0xb);
              if (-1 < (int)uVar14) {
                *(short *)(local_74 + 0x20) = (short)uVar14;
                *(short *)(local_74 + 0x22) = (short)local_90;
                fs_memcpy(local_48,auStack_80,0xc);
                if (param_5 == 3) {
                  return 0;
                }
                uVar10 = subdir_write_lfn(param_1,auStack_80,uVar14 & 0xffff,local_28,local_50,
                                          local_90,param_9);
                return uVar10;
              }
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
              uVar15 = __aeabi_uidivmod(((local_90 + uVar3) - iVar13) + -1,
                                        *(uint *)(param_1 + 0x6c) >> 5);
              sVar7 = (short)((uint6)uVar15 >> 0x20);
              iVar13 = 0;
              if ((int)uVar15 < 1) goto LAB_20146d4c;
              goto LAB_20146cb4;
            }
            local_4c = dir_cluster_alloc_zeroed(param_1,local_30,param_9);
            uVar11 = fs_task_ctx_get();
            if (uVar11 != 0) {
              return uVar11;
            }
          }
          local_30 = local_4c;
        } while( true );
      }
      uVar3 = 0xffffffba;
    }
  }
  return uVar3;
LAB_20146cb4:
  iVar4 = iVar4 + 1;
  uVar10 = (uint)*(ushort *)(param_1 + 4);
  if (uVar10 == 1) {
    iVar4 = dir_cluster_alloc_zeroed(param_1,local_30,param_9);
    local_30 = iVar4;
    uVar10 = fs_task_ctx_get();
    if (uVar10 != 0) {
      return uVar10;
    }
LAB_20146e24:
    iVar4 = fat_clust2sect(param_1,iVar4);
  }
  else if (uVar10 == 2) {
    if (local_8c == 1) {
      iVar4 = dir_cluster_alloc_zeroed(param_1,local_30,param_9);
      uVar10 = fs_task_ctx_get();
      if (uVar10 != 0) {
        return uVar10;
      }
      goto LAB_20146e24;
    }
  }
  else if (uVar10 - 1 == local_8c) {
    uVar6 = dir_cluster_alloc_zeroed(param_1,local_30,param_9);
                    /* Per-task FS context 0x2091D0BC[tskid] [doc] */
    uVar10 = fs_task_ctx_get();
    if (uVar10 != 0) {
      return uVar10;
    }
    iVar4 = fat_clust2sect(param_1,uVar6);
    local_8c = 0;
  }
  iVar13 = iVar13 + 1;
  local_d4[2] = local_d4[1];
  local_d4[1] = local_d4[0];
  local_8c = local_8c + 1;
  local_d4[0] = iVar4;
  if ((int)uVar15 <= iVar13) {
LAB_20146d4c:
    *param_8 = iVar4;
    *param_7 = (int)sVar7;
    *(short *)(local_74 + 0x20) = sVar7;
    *(short *)(local_74 + 0x22) = (short)local_90;
    fs_memcpy(local_48,local_d4,0xc);
    if (param_5 == 3) {
      return 0;
    }
    if (local_70 == 1) {
      uVar10 = subdir_write_lfn(param_1,local_d4,sVar7,local_28,local_50,local_90,param_9);
      return uVar10;
    }
    uVar10 = subdir_write_lfn(param_1,local_d4,sVar7,local_28,0,local_90,param_9);
    return uVar10;
  }
  goto LAB_20146cb4;
}


// ===== subdir_find_locked @ 201471cc (124 bytes)

/* subdir_find under fs_lock_a [fact] */

undefined4
subdir_find_locked(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                    /* Searches a directory cluster chain for a name [doc, inference] */
    uVar2 = subdir_find(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                        param_1,uVar2,uVar3,uVar4);
    fs_unlock_a(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== path_next_component @ 20147248 (96 bytes)

/* (p, out): copies the "\\name" component at p (Shift-JIS aware) to out and returns the pointer
   after it, 0 when p does not start with '\\' [fact] */

char * path_next_component(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (*param_1 == '\\') {
    while (pcVar2 = param_1 + 1, *pcVar2 != '\0' && *pcVar2 != '\\') {
      iVar1 = sjis_is_lead(*pcVar2);
      pcVar3 = pcVar2;
      pcVar4 = param_2;
      if (iVar1 != 0) {
        pcVar3 = param_1 + 2;
        pcVar4 = param_2 + 1;
        *param_2 = *pcVar2;
      }
      param_2 = pcVar4 + 1;
      *pcVar4 = *pcVar3;
      param_1 = pcVar3;
    }
    *param_2 = '\0';
  }
  else {
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}


// ===== path_components_len @ 201472a8 (108 bytes)

/* Length of a path rebuilt from its components plus separators and the 3-byte "X:\\" [fact] */

int path_components_len(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char local_218 [524];
  
  pcVar3 = (char *)(param_1 + 2);
  cVar1 = *(char *)(param_1 + 2);
  iVar4 = 0;
                    /* copies the "\\name" component at p [doc] */
  while (((cVar1 != '\0' &&
          (pcVar3 = (char *)path_next_component(pcVar3,local_218), local_218[0] != '\0')) &&
         (*pcVar3 != '\0'))) {
                    /* Byte-wise string length [doc] */
    iVar2 = fs_strlen(local_218);
    iVar4 = iVar2 + iVar4 + 1;
    cVar1 = *pcVar3;
  }
  return iVar4 + 3;
}


// ===== fs_name_check @ 20147314 (176 bytes)

/* -1 when a path component has a character of the invalid list 0x20808BA8 (outside Shift-JIS
   pairs), is all spaces, or ends in '.' or ' ' [fact] */

undefined4 fs_name_check(char *param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = 0;
  bVar1 = true;
  if (*param_1 != '\0') {
    do {
      pcVar4 = param_1;
      if (*pcVar4 != ' ') {
        bVar1 = false;
      }
      if (iVar5 == 0) {
        iVar2 = sjis_is_lead(*pcVar4);
        if (iVar2 == 0) {
          if (*DAT_20808ba8 != '\0') {
            pcVar3 = DAT_20808ba8;
            do {
              if (*pcVar3 == *pcVar4) {
                return 0xffffffff;
              }
              pcVar3 = pcVar3 + 1;
            } while (*pcVar3 != '\0');
          }
        }
        else {
          iVar5 = 1;
        }
      }
      else {
        iVar5 = iVar5 + -1;
      }
      param_1 = pcVar4 + 1;
    } while (pcVar4[1] != '\0');
    if ((!bVar1) && (*pcVar4 != '.' && *pcVar4 != ' ')) {
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== fs_path_validate @ 201473c4 (224 bytes)

/* -12 without a drive letter, -1 without ":\\", for more than 0x102 characters or a bad component
   (fs_name_check) [fact] */

int fs_path_validate(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int i;
  char local_218 [520];
  
  iVar2 = (int)*param_1;
  if ((0x19 < iVar2 - 0x41U) && (0x19 < iVar2 - 0x61U)) {
    return -0xc;
  }
  if ((param_1[1] == ':') && (param_1[2] == '\\')) {
    i = 0;
    pcVar3 = param_1;
    if (iVar2 != 0) {
      do {
        iVar2 = sjis_is_lead(*pcVar3);
        i = i + 1;
        if (iVar2 != 0) {
          pcVar3 = pcVar3 + 1;
        }
        pcVar3 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      if (0x102 < i) goto LAB_20147444;
    }
    cVar1 = param_1[2];
    param_1 = param_1 + 2;
    while( true ) {
                    /* copies the "\\name" component at p [doc] */
      if ((cVar1 == '\0') ||
         (param_1 = (char *)path_next_component(param_1,local_218), local_218[0] == '\0')) {
        return 0;
      }
      iVar2 = fs_name_check(local_218);
      if (iVar2 != 0) break;
      cVar1 = *param_1;
    }
  }
  else {
LAB_20147444:
    iVar2 = -1;
  }
  return iVar2;
}


// ===== dirent_set_time @ 201474a4 (228 bytes)

/* Writes the FAT date/time from fs_get_time_tm into an entry: mask 1 = created (+0xE/+0x10), 2 =
   written (+0x16/+0x18, also file +0x234), 4 = accessed date (+0x12) [fact] */

void dirent_set_time(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int iStack_30;
  int local_2c;
  
                    /* rtc_get_tm into the caller's struct tm, returns 1 [doc] */
  iVar1 = fs_get_time_tm(&local_40);
  if (iVar1 == 0) {
    uVar2 = 0;
    uVar3 = 0;
  }
  else {
    uVar3 = local_40 / 2 | local_3c << 5 | local_38 << 0xb;
    uVar2 = iStack_30 * 0x20 + 0x20U | local_34;
    if (0x4f < local_2c) {
      uVar2 = uVar2 | local_2c * 0x200 - 0xa000U;
    }
  }
  if ((param_3 & 1) != 0) {
    fat_st_word(param_1 + 0xe,uVar3 & 0xffff);
    fat_st_word(param_1 + 0x10,uVar2 & 0xffff);
  }
  if ((param_3 & 2) != 0) {
    fat_st_word(param_1 + 0x16,uVar3 & 0xffff);
    fat_st_word(param_1 + 0x18,uVar2 & 0xffff);
    if (param_2 != 0) {
      *(short *)(param_2 + 0x234) = (short)uVar3;
      *(short *)(param_2 + 0x236) = (short)uVar2;
    }
  }
  if ((param_3 & 4) != 0) {
    fat_st_word(param_1 + 0x12,uVar2 & 0xffff);
  }
  return;
}


// ===== dirent_set_cluster @ 20147588 (72 bytes)

/* Stores the first cluster in an entry (+0x1A, high word +0x14 except FAT12/16) [fact] */

void dirent_set_cluster(int param_1,uint param_2,int param_3)

{
  if (param_3 != 0xc && param_3 != 0x10) {
    fat_st_word(param_1 + 0x1a,param_2 & 0xffff);
    fat_st_word(param_1 + 0x14,param_2 >> 0x10);
    return;
  }
  fat_st_word(param_1 + 0x1a,param_2 & 0xffff);
  return;
}


// ===== fat_time_to_tm @ 201475d0 (112 bytes)

/* FAT date/time words to struct tm (sec*2, min, hour, mday, mon-1, year+80) [fact] */

void fat_time_to_tm(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_2;
  uStack_10 = param_3;
                    /* 16-bit field read from an on-disk structure [doc] */
  uVar1 = fat_ld_word(&uStack_14);
  uVar2 = fat_ld_word(&uStack_10);
  *param_1 = (uVar1 & 0x1f) << 1;
  param_1[1] = (uVar1 & 0x7ff) >> 5;
  param_1[2] = uVar1 >> 0xb;
  param_1[3] = uVar2 & 0x1f;
  param_1[4] = ((uVar2 & 0x1ff) >> 5) - 1;
  param_1[5] = (uVar2 >> 9) + 0x50;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}


// ===== dirent_name_to_str @ 20147640 (176 bytes)

/* 8.3 name of an entry to "NAME.EXT"; NT case flags 0x08 / 0x10 lower-case base / extension [fact]
    */

undefined4 dirent_name_to_str(char *param_1,int param_2,uint param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    if (*(char *)(param_2 + iVar3) == ' ') break;
    if ((param_3 & 8) == 0) {
      *param_1 = *(char *)(param_2 + iVar3);
    }
    else {
      cVar1 = fs_tolower((int)*(char *)(param_2 + iVar3));
      *param_1 = cVar1;
    }
    param_1 = param_1 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  iVar3 = 8;
  do {
    if (*(char *)(param_2 + iVar3) == ' ') {
      pcVar2 = param_1;
      if (iVar3 == 8) {
        pcVar2 = param_1 + 1;
        *param_1 = '\0';
      }
      break;
    }
    pcVar2 = param_1;
    if (iVar3 == 8) {
      *param_1 = '.';
      pcVar2 = param_1 + 1;
    }
    if ((param_3 & 0x10) == 0) {
      cVar1 = *(char *)(param_2 + iVar3);
    }
    else {
      cVar1 = fs_tolower((int)*(char *)(param_2 + iVar3));
    }
    iVar3 = iVar3 + 1;
    param_1 = pcVar2 + 1;
    *pcVar2 = cVar1;
    pcVar2 = param_1;
  } while (iVar3 < 0xb);
  *pcVar2 = '\0';
  return 0;
}


// ===== fs_attr_check @ 201476f0 (12 bytes)

/* -99 when the attribute mask has bits outside the allowed set [fact] */

undefined4 fs_attr_check(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & ~param_1) != 0) {
    uVar1 = 0xffffff9d;
  }
  return uVar1;
}


// ===== sjis_fold_case @ 201476fc (120 bytes)

/* Full-width Shift-JIS lower-case Latin/Greek/Cyrillic to upper case, and 0xFA40.. to the 0x8754..
   range [fact] */

uint sjis_fold_case(uint param_1)

{
  if (param_1 - 0x8281 < 0x1a) {
    param_1 = param_1 - 0x21;
  }
  else if (param_1 - 0x83bf < 0x18) {
    param_1 = param_1 - 0x20;
  }
  else if (param_1 - 0x8470 < 0xf) {
    param_1 = param_1 - 0x30;
  }
  else {
    if (0x11 < param_1 - 0x8480) {
      if (9 < param_1 - 0xfa40) {
        return param_1;
      }
      return param_1 - 0x72ec & 0xffff;
    }
    param_1 = param_1 - 0x31;
  }
  return param_1 & 0xffff;
}


// ===== fs_stricmp_sjis_fold @ 20147774 (220 bytes)

/* Case-insensitive compare that also folds full-width Shift-JIS letters (sjis_fold_case) [fact] */

int fs_stricmp_sjis_fold(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  
  while( true ) {
    cVar1 = *param_1;
    cVar2 = *param_2;
    if (cVar1 == '\0' && cVar2 == '\0') {
      return 0;
    }
    if (cVar1 == 0) break;
    if (cVar2 == 0) {
      return 1;
    }
    iVar5 = sjis_is_lead(cVar2);
    if (iVar5 == 0) {
      cVar1 = fs_toupper((int)cVar1);
      cVar2 = fs_toupper((int)cVar2);
      if ((char)(cVar1 - cVar2) != 0) {
        return (int)(char)(cVar1 - cVar2);
      }
    }
    else {
      cVar1 = param_2[1];
      cVar2 = *param_2;
      sVar3 = sjis_fold_case(CONCAT11(*param_1,param_1[1]));
      sVar4 = sjis_fold_case(CONCAT11(cVar2,cVar1));
      if (sVar3 != sVar4) {
        return -1;
      }
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return -1;
}


// ===== fs_strnicmp_sjis_b @ 20147850 (248 bytes)

/* (a, b, n): case-insensitive compare of n bytes, Shift-JIS aware (two-byte characters folded with
   sjis_fold_case, single bytes with fs_toupper); no caller in the image; a second copy next to
   fs_strnicmp_sjis 0x2014D770 [fact] */

int fs_strnicmp_sjis_b(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (param_3 != 0) {
    do {
      cVar1 = *param_1;
      cVar2 = *param_2;
      if (cVar1 == '\0' && cVar2 == '\0') {
        return 0;
      }
      if (cVar1 == 0) {
        return -1;
      }
      if (cVar2 == 0) {
        return 1;
      }
      iVar5 = sjis_is_lead(cVar2);
      if (iVar5 == 0) {
        cVar1 = fs_toupper((int)cVar1);
        cVar2 = fs_toupper((int)cVar2);
        if ((char)(cVar1 - cVar2) != 0) {
          return (int)(char)(cVar1 - cVar2);
        }
      }
      else {
        cVar1 = param_2[1];
        cVar2 = *param_2;
        sVar3 = sjis_fold_case(CONCAT11(*param_1,param_1[1]));
        sVar4 = sjis_fold_case(CONCAT11(cVar2,cVar1));
        if (sVar3 != sVar4) {
          return -1;
        }
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
        uVar6 = uVar6 + 1;
      }
      uVar6 = uVar6 + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (uVar6 < param_3);
  }
  return 0;
}


// ===== fs_utoa_zeropad @ 20147950 (408 bytes)

/* (value, buf, width): decimal digits of value, zero-padded to width (max 10 digits) [fact] */

void fs_utoa_zeropad(uint param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  if (0 < param_3 + -10) {
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
    fs_memset(param_2,0x30,param_3,0x200);
    param_2 = param_2 + param_3 + -10;
    param_3 = 10;
  }
  pcVar2 = param_2;
  pcVar1 = param_2;
  switch(param_3) {
  default:
    return;
  case 10:
    pcVar1 = param_2 + 1;
    *param_2 = (byte)((ulonglong)param_1 * 0x89705f41 + 0x89705f41 >> 0x3d) + 0x30;
    param_1 = param_1 + (uint)((ulonglong)param_1 * 0x89705f41 + 0x89705f41 >> 0x3d) * -1000000000;
  case 9:
    pcVar2 = pcVar1 + 1;
    *pcVar1 = (char)(param_1 / 100000000) + '0';
    param_1 = param_1 % 100000000;
  case 8:
    param_2 = pcVar2 + 1;
    *pcVar2 = (char)(param_1 / 10000000) + '0';
    param_1 = param_1 % 10000000;
  case 7:
    pcVar2 = param_2 + 1;
    *param_2 = (char)(param_1 / 1000000) + '0';
    param_1 = param_1 + (short)(param_1 / 1000000) * -1000000;
  case 6:
    param_2 = pcVar2 + 1;
    *pcVar2 = (char)((ulonglong)param_1 * 0xa7c5ac47 + 0xa7c5ac47 >> 0x30) + '0';
    param_1 = param_1 + (uint)((ulonglong)param_1 * 0xa7c5ac47 + 0xa7c5ac47 >> 0x30) * -100000;
  case 5:
    pcVar2 = param_2 + 1;
    *param_2 = (char)(param_1 / 10000) + '0';
    param_1 = param_1 % 10000;
  case 4:
    param_2 = pcVar2 + 1;
    *pcVar2 = (char)(param_1 / 1000) + '0';
    param_1 = param_1 % 1000;
  case 3:
    pcVar2 = param_2 + 1;
    *param_2 = (char)(param_1 / 100) + '0';
    param_1 = param_1 % 100;
  case 2:
    param_2 = pcVar2 + 1;
    *pcVar2 = (char)(param_1 / 10) + '0';
    param_1 = param_1 % 10;
  case 1:
    *param_2 = (char)param_1 + '0';
    return;
  }
}


// ===== sfn_pack @ 20147b14 (268 bytes)

/* (out, name, vol): 11-byte space-padded 8.3 form of a name [fact for the 0x20 fill; inference for
   the rest] */

undefined4 sfn_pack(undefined1 *param_1,int param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  bVar2 = false;
  uVar3 = 0;
  uVar4 = 0;
  do {
    cVar1 = *(char *)(param_2 + uVar3);
    if (cVar1 == '\0') {
      if (uVar3 == 0) {
        return 0xffffff9d;
      }
      break;
    }
    if (cVar1 == ' ') {
      return 0xffffff9d;
    }
    if (cVar1 == '.') {
      if (8 < uVar3) {
        return 0xffffff9d;
      }
      if (uVar3 == 0) {
        return 0xffffff9d;
      }
      bVar5 = uVar4 != 0;
      uVar4 = uVar3;
      if (bVar5) {
        return 0xffffff9d;
      }
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0xc);
  if ((uVar4 != 0) && (4 < (int)(uVar3 - uVar4))) {
    return 0xffffff9d;
  }
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(param_1,0x20,0xb,*(undefined4 *)(param_3 + 0x6c));
  uVar4 = 0;
  param_1[0xb] = 0;
  uVar3 = 0;
  while( true ) {
    cVar1 = *(char *)(param_2 + uVar4);
    if (cVar1 == '\0') {
      return 0;
    }
    if (cVar1 == '.') {
      bVar2 = true;
      uVar3 = 7;
    }
    else {
      param_1[uVar3] = cVar1;
    }
    if (uVar4 == 8 && !bVar2) break;
    uVar4 = uVar4 + 1 & 0xff;
    uVar3 = uVar3 + 1 & 0xff;
    if (0xb < uVar4 || 0xb < uVar3) {
      return 0;
    }
  }
  *param_1 = 0;
  return 0;
}


// ===== FUN_20147c20 @ 20147c20 (92 bytes)

int FUN_20147c20(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char local_18 [12];
  char *pcVar3;
  
                    /* 11-byte space-padded 8.3 form of a name [doc] */
  iVar1 = sfn_pack(local_18);
  if (iVar1 == 0) {
    pcVar3 = local_18;
    if (local_18[0] != '\0') {
      while( true ) {
        pcVar2 = pcVar3 + 1;
        if (*pcVar3 != *param_1) break;
        pcVar3 = pcVar2;
        param_1 = param_1 + 1;
        if (*pcVar2 == '\0') {
          return 0;
        }
      }
    }
    iVar1 = -99;
  }
  return iVar1;
}


// ===== root_dir_add_entry @ 20147c7c (972 bytes)

/* Creates a directory entry with long name in the root directory: counts the needed long-name
   entries, scans the root sectors for a free run, builds the numeric-tail alias (fs_utoa_zeropad)
   and writes it with root_dir_write_lfn; an existing name is replaced (root_dirent_delete)
   [inference: the calls and the free-slot scan] */

int root_dir_add_entry(int param_1,undefined4 param_2,undefined4 param_3,int param_4,
                      undefined4 param_5,uint *param_6,int param_7)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined *puStack_68;
  undefined *puStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int local_58;
  undefined1 auStack_54 [16];
  char *local_44;
  undefined4 local_40;
  undefined1 local_3c [4];
  int local_38;
  int local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  int iStack_28;
  
  uVar9 = 0;
  uVar8 = 0xffffffff;
  puStack_68 = &DAT_20202020;
  puStack_64 = &DAT_20202020;
  uStack_60 = 0x4e4543;
  uStack_5c = 0;
  local_44 = (char *)(param_7 + 0xe0c);
  pcVar5 = (char *)0x0;
  iVar4 = param_7 + 0x40c;
  local_3c[0] = 0;
  local_40 = 0xffffffff;
  local_34 = param_1;
  uStack_30 = param_2;
  local_2c = param_3;
  iStack_28 = param_4;
  iVar2 = fs_wstrcpy_len(param_2,iVar4,local_3c);
  if (iVar2 == -99) {
    return -0x46;
  }
  local_38 = 1;
  uVar7 = 0;
  uVar3 = (iVar2 + -1) / 0xd + 2;
  uVar6 = uVar3 & 0xffff;
  local_58 = param_7 + 0x1600;
  uVar1 = (undefined2)uVar3;
  if (*(short *)(local_34 + 10) != 0) {
    do {
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
      uVar11 = __aeabi_uidivmod(uVar7,*(uint *)(local_34 + 0x6c) >> 5);
      uVar12 = (undefined4)uVar11;
                    /* sector n of the fixed FAT12/16 root directory [doc] */
      if (((int)((ulonglong)uVar11 >> 0x20) == 0) &&
         (iVar2 = root_sector_get(local_34,uVar12,&local_44), pcVar5 = local_44, local_40 = uVar12,
         iVar2 != 0)) {
        return iVar2;
      }
      if (pcVar5 == (char *)0x0) {
        return -0xd;
      }
      if (*pcVar5 == -0x1b) {
        if (param_4 != 0 && param_4 != 2) {
          uVar9 = uVar9 + 1 & 0xffff;
          bVar10 = uVar9 == uVar6;
          if (uVar6 <= uVar9) {
            bVar10 = uVar8 == 0xffffffff;
          }
          if (bVar10) {
            uVar8 = (uint)(short)uVar7;
          }
        }
      }
      else {
        if (*pcVar5 == '\0') {
          if (param_4 == 0 || param_4 == 2) {
            return -0x47;
          }
          if ((int)uVar8 < 0) {
            if (((*(ushort *)(local_34 + 10) - uVar7) + uVar9 & 0xffff) < uVar6) {
              return -0x42;
            }
            uVar8 = ((uVar7 + uVar6) - uVar9) - 1;
            *param_6 = uVar8;
            *(short *)(local_58 + 0x20) = (short)uVar8;
            *(undefined2 *)(local_58 + 0x22) = uVar1;
            if (param_4 != 3) {
                    /* decimal digits of value, zero-padded to width [doc] */
              fs_utoa_zeropad(*param_6,&puStack_68,8);
              fs_memcpy(local_2c,&puStack_68,0xb);
              if (local_38 != 0) {
                iVar2 = root_dir_write_lfn(local_34,uVar8 & 0xffff,local_2c,iVar4,uVar6,param_7);
                return iVar2;
              }
              iVar2 = root_dir_write_lfn(local_34,uVar8 & 0xffff,local_2c,0,uVar6,param_7);
              return iVar2;
            }
            return 0;
          }
          *param_6 = uVar8;
          *(short *)(local_58 + 0x20) = (short)uVar8;
          *(undefined2 *)(local_58 + 0x22) = uVar1;
          goto joined_r0x20147df0;
        }
        uVar9 = 0;
        if (((pcVar5[0xb] & 8U) == 0) && (param_4 != 3)) {
          iVar2 = root_lfn_collect(local_34,uVar7,iVar4,uVar6,local_40,param_7);
          if (iVar2 == 0) {
LAB_20147f14:
            if (param_4 == 1) {
              return -0xd;
            }
            fs_memcpy(local_2c,pcVar5,0x20);
            if (param_4 == 2) {
              iVar2 = root_dirent_delete(local_34,uVar7,uVar6,param_7);
              return iVar2;
            }
            if (param_4 == 0) {
              *param_6 = uVar7;
              *(short *)(local_58 + 0x20) = (short)uVar7;
              *(undefined2 *)(local_58 + 0x22) = uVar1;
              return 0;
            }
          }
          else {
                    /* Length of a UTF-16 string in bytes [doc] */
            uVar3 = fs_wstrlen_bytes(iVar4);
            if (uVar3 < 0x19) {
                    /* UTF-16 name to 8-bit upper case [doc] */
              fs_ucs2_to_ascii_upper(auStack_54,iVar4);
              iVar2 = FUN_20147c20(pcVar5,auStack_54,local_34);
              if (iVar2 == 0) goto LAB_20147f14;
            }
          }
        }
      }
      pcVar5 = pcVar5 + 0x20;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *(ushort *)(local_34 + 10));
  }
  if (param_4 == 1 || param_4 == 3) {
    if (-1 < (int)uVar8) {
      *param_6 = uVar8;
      *(short *)(local_58 + 0x20) = (short)uVar8;
      *(undefined2 *)(local_58 + 0x22) = uVar1;
joined_r0x20147df0:
      if (param_4 == 3) {
        return 0;
      }
      fs_utoa_zeropad(*param_6,&puStack_68,8);
      fs_memcpy(local_2c,&puStack_68,0xb);
      iVar2 = root_dir_write_lfn(local_34,uVar8 & 0xffff,local_2c,iVar4,uVar6,param_7);
      return iVar2;
    }
    if (param_4 == 3) {
      return -0xb;
    }
  }
  return -0x47;
}


// ===== root_dir_add_entry_locked @ 20148048 (108 bytes)

/* fs_lock_a, root_dir_add_entry, fs_unlock_a [fact] */

undefined4
root_dir_add_entry_locked
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* Locks the per-drive semaphore of table 0x2091D4C0 [doc] */
  iVar1 = fs_lock_a();
  if (iVar1 == 0) {
    uVar2 = root_dir_add_entry(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    fs_unlock_a(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}

