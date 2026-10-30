// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== sfn_match_dotted @ 2014570c (88 bytes)

/* 0 when an 11-byte 8.3 name equals sfn_from_dotted of a dotted name, -99 otherwise [fact] */

undefined4 sfn_match_dotted(char *param_1)

{
  char *pcVar1;
  char local_18 [12];
  
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
  int iVar6;
  int iVar7;
  char local_28 [12];
  
  iVar7 = 0;
  iVar6 = 0;
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
      iVar6 = iVar6 + 1;
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
    if (iVar6 == 0) {
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
  if (iVar6 <= iVar3) {
    iVar3 = iVar3 - iVar6;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    param_1 = param_1 + 1;
    iVar7 = (int)*param_1 + iVar7 * 10 + -0x30;
  }
  return iVar7;
}


// ===== FUN_201458e4 @ 201458e4 (536 bytes)

undefined4 FUN_201458e4(byte *param_1,byte *param_2)

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
  uVar7 = __aeabi_uidivmod(param_2,uVar4);
  iVar6 = (int)uVar7;
  if ((param_2 != 0) && ((int)((ulonglong)uVar7 >> 0x20) == 0)) {
    iVar6 = __aeabi_uidivmod(param_2 + -1,uVar4);
  }
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
        iVar1 = lfn_entry_get_chars(pbVar5,local_4c);
        psVar3 = local_4c;
        while (iVar1 != 0) {
          iVar1 = iVar1 + -1;
          if ((*param_3 != *psVar3) && (iVar2 = FUN_201458e4(param_3,psVar3), iVar2 == 0)) {
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
  cVar2 = FUN_20145254(local_30,auStack_70,&local_60);
  if (cVar2 == '\x01') {
    uVar5 = (iVar3 + -1) / 0xd + 1U & 0xffff;
  }
  else if (cVar2 == '\0') goto LAB_20145edc;
  if ((local_40[0] == '\0') && (param_4 == 0 || param_4 == 2)) {
    fs_memcpy(auStack_54,local_30,0xd);
    fs_stricmp(auStack_70,auStack_54);
  }
LAB_20145edc:
  uVar7 = 0;
  uVar6 = uVar5 + 1 & 0xffff;
  local_58 = param_7 + 0x1600;
  uVar1 = (undefined2)(uVar5 + 1);
  if (*(short *)(local_34 + 10) != 0) {
    do {
      uVar12 = __aeabi_uidivmod(uVar7,*(uint *)(local_34 + 0x6c) >> 5);
      uVar13 = (undefined4)uVar12;
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
          cVar2 = FUN_20145254(local_30,auStack_70,&local_60);
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
                iVar3 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,0,uVar6,param_7);
                return iVar3;
              }
              iVar3 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,local_44,uVar6,param_7);
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
            uVar5 = fs_strlen(local_30);
            if (uVar5 < 0xd) {
              if (uVar9 != 0) {
                fs_utoa6(&local_60,uVar9);
              }
              FUN_20145254(local_30,auStack_70,&local_60);
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
      FUN_20145254(local_30,auStack_70,&local_60);
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
      iVar3 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,local_44,uVar6,param_7);
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
  
  iVar1 = fs_lock_a();
  if (iVar1 == 0) {
    uVar2 = root_dir_find(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    fs_unlock_a(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== FUN_201463a4 @ 201463a4 (204 bytes)

int FUN_201463a4(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_18;
  
  local_18 = param_4;
  iVar1 = fat_alloc_cluster_locked(param_1,param_2,&local_18,param_3);
  if (iVar1 == 0) {
    if (local_18 == 0) {
      fs_set_error(0xfffffff5,0);
      return 0;
    }
    iVar2 = fat_clust2sect(param_1);
    fs_memset(param_3 + 0x60c,0,0x200);
    iVar3 = 0;
    if (*(short *)(param_1 + 4) != 0) {
      do {
        iVar1 = fs_dev_op2(param_1,iVar2,param_3 + 0x60c,1);
        if (iVar1 != 0) goto LAB_20146424;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 1;
      } while (iVar3 < (int)(uint)*(ushort *)(param_1 + 4));
    }
    fs_set_error(0);
    return local_18;
  }
LAB_20146424:
  fs_set_error(iVar1,0);
  return 0;
}


// ===== FUN_20146470 @ 20146470 (176 bytes)

undefined4 FUN_20146470(undefined1 *param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = param_3;
  do {
    if (uVar2 == 0) {
      return 0;
    }
    while( true ) {
      if ((param_3 == uVar2) || (param_1[0xb] == '\x0f')) {
        *param_1 = 0xe5;
      }
      if (*(undefined1 **)(param_2 + iVar3 * 4) == param_1) break;
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
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    param_1 = (undefined1 *)
              (*(int *)(param_2 + iVar1 + 4) + (*(uint *)(param_4 + 0x6c) & 0xffffffe0) + -0x20);
  } while (iVar3 < 3);
  return 0xffffffbc;
}


// ===== FUN_20146520 @ 20146520 (140 bytes)

undefined4 FUN_20146520(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char local_18 [12];
  
  pcVar3 = local_18;
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


// ===== FUN_201465ac @ 201465ac (92 bytes)

undefined4 FUN_201465ac(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_18 [12];
  
  iVar1 = sfn_numtail_match();
  iVar2 = fs_atoi_2(param_3);
  if (iVar2 <= iVar1) {
    if (0x98967e < iVar1) {
      return 0xffffffbe;
    }
    fs_itoa_2(iVar1 + 1,auStack_18,10);
    fs_strcpy(param_3,auStack_18);
  }
  return 0;
}


// ===== FUN_20146608 @ 20146608 (228 bytes)

undefined4 FUN_20146608(int param_1,byte *param_2,short *param_3,int param_4)

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
    iVar3 = lfn_entry_get_chars(param_2,local_40);
    psVar6 = local_40;
    for (; 0 < iVar3; iVar3 = iVar3 + -1) {
      if ((*param_3 != *psVar6) && (iVar4 = FUN_201458e4(param_3,psVar6), iVar4 == 0))
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


// ===== FUN_201466ec @ 201466ec (408 bytes)

void FUN_201466ec(int param_1,undefined4 *param_2,int param_3,char *param_4,int param_5,int param_6,
                 int param_7)

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
  bVar1 = lfn_checksum(param_4);
  bVar6 = 1;
  do {
    pbVar4 = pbVar3 + -0x20;
    iVar2 = FUN_20144d5c(pbVar4,param_5,param_1);
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
        if ((param_5 == 0 || param_5 == 2) && (uVar3 = fs_strlen(local_2c), uVar3 < 0xd)) {
          fs_strcpy(local_a0,local_2c);
          fs_strlwr_sjis(local_a0);
        }
        if (local_a0[0] == '\0') {
          local_70 = FUN_20145254(local_2c,auStack_c8,&DWORD_20146dcc);
        }
        else {
          local_70 = FUN_20145254(local_a0,auStack_c8,&DWORD_20146dcc);
        }
        if (local_70 == 1) {
          uVar11 = (iVar4 + -1) / 0xd + 1U & 0xffff;
        }
        local_90 = uVar11 + 1 & 0xffff;
        if (((local_70 != 0) && (local_40[0] == '\0')) && (param_5 == 0 || param_5 == 2)) {
          fs_memcpy(auStack_60,local_a0,0xd);
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
                        uVar11 = FUN_201465ac(pcVar12,local_ac,&local_88);
                        if (uVar11 != 0) {
                          return uVar11;
                        }
                      }
                      iVar5 = FUN_20146608(local_b8,pcVar12,local_50,param_1);
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
                        uVar10 = FUN_20146470(pcVar12,local_b8,uVar9,param_1);
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
                        uVar11 = FUN_201465ac(pcVar12,local_ac,&local_88);
                        if (uVar11 != 0) {
                          return uVar11;
                        }
                        FUN_20145254(local_2c,auStack_c8,&local_88);
                        iVar5 = FUN_20146520(pcVar12,auStack_c8,param_1);
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
              FUN_20145254(local_2c,auStack_c8,&local_88);
              sfn_from_dotted(local_ac,auStack_c8,param_1);
              fs_memcpy(local_28,local_ac,0xb);
              if (-1 < (int)uVar14) {
                *(short *)(local_74 + 0x20) = (short)uVar14;
                *(short *)(local_74 + 0x22) = (short)local_90;
                fs_memcpy(local_48,auStack_80,0xc);
                if (param_5 == 3) {
                  return 0;
                }
                uVar10 = FUN_201466ec(param_1,auStack_80,uVar14 & 0xffff,local_28,local_50,local_90,
                                      param_9);
                return uVar10;
              }
              uVar15 = __aeabi_uidivmod(((local_90 + uVar3) - iVar13) + -1,
                                        *(uint *)(param_1 + 0x6c) >> 5);
              sVar7 = (short)((uint6)uVar15 >> 0x20);
              iVar13 = 0;
              if ((int)uVar15 < 1) goto LAB_20146d4c;
              goto LAB_20146cb4;
            }
            local_4c = FUN_201463a4(param_1,local_30,param_9);
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
    iVar4 = FUN_201463a4(param_1,local_30,param_9);
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
      iVar4 = FUN_201463a4(param_1,local_30,param_9);
      uVar10 = fs_task_ctx_get();
      if (uVar10 != 0) {
        return uVar10;
      }
      goto LAB_20146e24;
    }
  }
  else if (uVar10 - 1 == local_8c) {
    uVar6 = FUN_201463a4(param_1,local_30,param_9);
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
      uVar10 = FUN_201466ec(param_1,local_d4,sVar7,local_28,local_50,local_90,param_9);
      return uVar10;
    }
    uVar10 = FUN_201466ec(param_1,local_d4,sVar7,local_28,0,local_90,param_9);
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
  iVar1 = fs_lock_a(param_1);
  if (iVar1 == 0) {
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
  while (((cVar1 != '\0' &&
          (pcVar3 = (char *)path_next_component(pcVar3,local_218), local_218[0] != '\0')) &&
         (*pcVar3 != '\0'))) {
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
  int iVar4;
  char local_218 [520];
  
  iVar2 = (int)*param_1;
  if ((0x19 < iVar2 - 0x41U) && (0x19 < iVar2 - 0x61U)) {
    return -0xc;
  }
  if ((param_1[1] == ':') && (param_1[2] == '\\')) {
    iVar4 = 0;
    pcVar3 = param_1;
    if (iVar2 != 0) {
      do {
        iVar2 = sjis_is_lead(*pcVar3);
        iVar4 = iVar4 + 1;
        if (iVar2 != 0) {
          pcVar3 = pcVar3 + 1;
        }
        pcVar3 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      if (0x102 < iVar4) goto LAB_20147444;
    }
    cVar1 = param_1[2];
    param_1 = param_1 + 2;
    while( true ) {
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


// ===== FUN_20147850 @ 20147850 (248 bytes)

int FUN_20147850(char *param_1,char *param_2,uint param_3)

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


// ===== FUN_20147950 @ 20147950 (408 bytes)

void FUN_20147950(uint param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  if (0 < param_3 + -10) {
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


// ===== FUN_20147b14 @ 20147b14 (268 bytes)

undefined4 FUN_20147b14(undefined1 *param_1,int param_2,int param_3)

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
  
  iVar1 = FUN_20147b14(local_18);
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


// ===== FUN_20147c7c @ 20147c7c (972 bytes)

int FUN_20147c7c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                uint *param_6,int param_7)

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
      uVar11 = __aeabi_uidivmod(uVar7,*(uint *)(local_34 + 0x6c) >> 5);
      uVar12 = (undefined4)uVar11;
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
              FUN_20147950(*param_6,&puStack_68,8);
              fs_memcpy(local_2c,&puStack_68,0xb);
              if (local_38 != 0) {
                iVar2 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,iVar4,uVar6,param_7);
                return iVar2;
              }
              iVar2 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,0,uVar6,param_7);
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
            uVar3 = fs_wstrlen_bytes(iVar4);
            if (uVar3 < 0x19) {
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
      FUN_20147950(*param_6,&puStack_68,8);
      fs_memcpy(local_2c,&puStack_68,0xb);
      iVar2 = FUN_20144ef4(local_34,uVar8 & 0xffff,local_2c,iVar4,uVar6,param_7);
      return iVar2;
    }
    if (param_4 == 3) {
      return -0xb;
    }
  }
  return -0x47;
}


// ===== FUN_20148048 @ 20148048 (108 bytes)

undefined4
FUN_20148048(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = fs_lock_a();
  if (iVar1 == 0) {
    uVar2 = FUN_20147c7c(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    fs_unlock_a(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== FUN_201480b4 @ 201480b4 (156 bytes)

int FUN_201480b4(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char local_18 [12];
  
  pcVar3 = local_18;
  iVar1 = FUN_20147b14(local_18);
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


// ===== FUN_20148150 @ 20148150 (2048 bytes)

/* WARNING: Type propagation algorithm not settling */

uint FUN_20148150(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
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
                      iVar5 = FUN_20146608(local_a0,pcVar12,local_70,param_1);
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
                        uVar11 = FUN_20146470(pcVar12,local_a0,uVar10,param_1);
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
                      uVar7 = fs_wstrlen_bytes(local_70);
                      if (uVar7 < 0x19) {
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
                FUN_20147950(local_44 * (*(uint *)(param_1 + 0x6c) >> 5) + uVar14,local_a0 + 3,8);
                fs_memcpy(local_28,local_a0 + 3,0xb);
                uVar11 = FUN_201466ec(param_1,auStack_80,uVar14 & 0xffff,local_28,local_70,
                                      local_b4[3],param_9);
                return uVar11;
              }
              iVar13 = (local_b4[3] + uVar3) - iVar13;
              uVar15 = __aeabi_uidivmod(iVar13 + -1,*(uint *)(param_1 + 0x6c) >> 5);
              sVar8 = (short)((uint6)uVar15 >> 0x20);
              iVar5 = 0;
              if ((int)uVar15 < 1) goto LAB_20148520;
              goto LAB_20148488;
            }
            local_4c = FUN_201463a4(param_1,local_30,param_9);
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
    iVar4 = FUN_201463a4(param_1,local_30,param_9);
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
      iVar4 = FUN_201463a4(param_1,local_30,param_9);
      uVar11 = fs_task_ctx_get();
      if (uVar11 != 0) {
        return uVar11;
      }
      goto LAB_20148620;
    }
  }
  else if (uVar11 - 1 == local_84) {
    uVar6 = FUN_201463a4(param_1,local_30,param_9);
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
    FUN_20147950(local_50 * (*(uint *)(param_1 + 0x6c) >> 5) + iVar13 + -1,local_a0 + 3,8);
    fs_memcpy(local_28,local_a0 + 3,0xb);
    if (local_38 == 0) {
      uVar11 = FUN_201466ec(param_1,local_b4,sVar8,local_28,0,local_b4[3],param_9);
      return uVar11;
    }
    uVar11 = FUN_201466ec(param_1,local_b4,sVar8,local_28,local_70,local_b4[3],param_9);
    return uVar11;
  }
  goto LAB_20148488;
}


// ===== FUN_20148990 @ 20148990 (124 bytes)

undefined4
FUN_20148990(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  iVar1 = fs_lock_a(param_1);
  if (iVar1 == 0) {
    uVar2 = FUN_20148150(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                         param_1,uVar2,uVar3,uVar4);
    fs_unlock_a(param_1);
  }
  else {
    uVar2 = 0xffffffdb;
  }
  return uVar2;
}


// ===== FUN_20148a0c @ 20148a0c (124 bytes)

void FUN_20148a0c(char *param_1,char *param_2)

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


// ===== FUN_20148a88 @ 20148a88 (136 bytes)

int FUN_20148a88(int param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char local_218;
  char local_217;
  
  iVar3 = 0;
  pcVar2 = (char *)(param_1 + 4);
  while ((((*pcVar2 != '\0' || (pcVar2[1] != '\0')) &&
          ((pcVar2 = (char *)FUN_20148a0c(pcVar2,&local_218), local_218 != '\0' ||
           (local_217 != '\0')))) && ((*pcVar2 != '\0' || (pcVar2[1] != '\0'))))) {
    iVar1 = fs_wstrlen_bytes(&local_218);
    iVar3 = iVar1 + iVar3 + 2;
  }
  return iVar3 + 6;
}


// ===== FUN_20148b10 @ 20148b10 (160 bytes)

undefined4 FUN_20148b10(char *param_1)

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
           ((param_1 = (char *)FUN_20148a0c(param_1,&cStack_210), cStack_210 != '\0' ||
            (cStack_20f != '\0'))))) {
      iVar1 = FUN_20148b10(&cStack_210);
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
         ((pcVar2 = (char *)FUN_20148a0c(pcVar2,&local_210), local_210 != '\0' ||
          (local_20f != '\0'))))) {
    iVar1 = FUN_20148b10(&local_210);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}


// ===== FUN_20148c5c @ 20148c5c (56 bytes)

undefined4 FUN_20148c5c(short *param_1)

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


// ===== FUN_20148c94 @ 20148c94 (224 bytes)

uint FUN_20148c94(uint param_1)

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


// ===== FUN_20148d74 @ 20148d74 (120 bytes)

uint FUN_20148d74(short *param_1,short *param_2)

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
    iVar3 = FUN_20148c94();
    iVar4 = FUN_20148c94(sVar2);
    uVar1 = iVar3 - iVar4 & 0xffff;
    if (uVar1 != 0) break;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return uVar1;
}


// ===== FUN_20148dec @ 20148dec (144 bytes)

uint FUN_20148dec(short *param_1,short *param_2,uint param_3)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
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
      iVar3 = FUN_20148c94();
      iVar4 = FUN_20148c94(sVar2);
      uVar1 = iVar3 - iVar4 & 0xffff;
      if (uVar1 != 0) {
        return uVar1;
      }
      uVar5 = uVar5 + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (uVar5 < param_3);
  }
  return 0;
}


// ===== FUN_20148f40 @ 20148f40 (124 bytes)

undefined4 FUN_20148f40(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,"RRaA",4);
  if ((((iVar1 == 0) && (iVar1 = memcmp(param_2 + 0x1e4,"rrAa",4), iVar1 == 0)) &&
      (*(char *)(param_2 + 0x1fe) == 'U')) && (*(char *)(param_2 + 0x1ff) == -0x56)) {
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
  uVar2 = fat_ld_word(param_2 + 0xe);
  *(undefined2 *)(param_1 + 6) = uVar2;
  *(ushort *)(param_1 + 8) = (ushort)*(byte *)(param_2 + 0x10);
  uVar2 = fat_ld_word(param_2 + 0x11);
  *(undefined2 *)(param_1 + 10) = uVar2;
  iVar3 = fat_ld_word(param_2 + 0x13);
  *(int *)(param_1 + 0x14) = iVar3;
  if (iVar3 == 0) {
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


// ===== FUN_201490f8 @ 201490f8 (324 bytes)

undefined4 FUN_201490f8(int param_1,int param_2)

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
  ulonglong uVar3;
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
      uVar3 = __aeabi_idivmod((local_18 & 0xffff) - 1,(uint)*(ushort *)(param_1 + 0x4a));
      local_18 = CONCAT22(local_18._2_2_,(short)uVar3 + 1);
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
  ulonglong uVar4;
  
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
        uVar4 = __aeabi_idivmod(iVar2 - 1,(uint)*(ushort *)(param_1 + 0x4a));
        uVar3 = (int)uVar4 + 1U & 0xffff;
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

