// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

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
  uint i;
  
  i = 0;
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
      i = i + 1;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
      if (param_3 <= i) {
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
  
                    /* Unsigned 32-bit divide returning quotient and remainder [doc] */
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
                    /* Recursive digit writer for radix 2..36 [doc] */
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
  uint i;
  undefined8 uVar6;
  
  bVar1 = false;
  i = 0;
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
        uVar6 = fs_toupper(iVar5);
        cVar2 = fs_toupper(iVar4,(int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if ((char)(extraout_r2 - cVar2) != 0) {
          return (int)(char)(extraout_r2 - cVar2);
        }
      }
      i = i + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (i < param_3);
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
                    /* Recursive digit writer for radix 2..36 [doc] */
    pcVar1 = fs_utoa_digits(param_1,pcVar1,param_3);
    *pcVar1 = '\0';
  }
  else {
    *param_2 = '\0';
  }
  return param_2;
}


// ===== fs_byte_pair_sum @ 2014d8b4 (20 bytes)

/* [fact] the signed byte sum of the two low bytes of its argument (sbfx, sxtab, sxtb); no caller
   found; Ghidra FUN_2014d8b4 (T24 round 9, fs/fs_string.c) */

int fs_byte_pair_sum(undefined4 param_1)

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


// ===== fs_task_ctx_get @ 2014d95c (48 bytes)

/* Per-task FS context 0x2091D0BC[tskid] (itron_get_tid), -72 for an ID out of range [fact] */

uint fs_task_ctx_get(void)

{
  uint uVar1;
  int in_r3;
  int local_8;
  
  local_8 = in_r3;
  itron_get_tid(&local_8);
  if (local_8 - 1U < 0x100) {
    uVar1 = *(uint *)(&DAT_2091d0bc + local_8 * 4);
  }
  else {
    uVar1 = 0xffffffb8;
  }
  return uVar1;
}


// ===== fs_task_err_set @ 2014d98c (48 bytes)

/* Stores the last error of the calling task in 0x2091D0BC[tskid] (itron_get_tid, ids 1..256);
   fs_set_error calls it [fact] */

void fs_task_err_set(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int local_10;
  
  local_10 = param_4;
  itron_get_tid(&local_10);
  if (local_10 - 1U < 0x100) {
    *(undefined4 *)(&DAT_2091d0bc + local_10 * 4) = param_1;
  }
  return;
}


// ===== fs_lock_a @ 2014d9c0 (164 bytes)

/* Locks the per-drive semaphore of table 0x2091D4C0 (itron_twai_sem, 300 ms); -37 without one
   [fact] */

int fs_lock_a(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_2091d4c4)[iVar2 * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4c0)[iVar2 * 2] == 0) {
        return -0x25;
      }
      iVar1 = itron_twai_sem((&DAT_2091d4c0)[iVar2 * 2],300);
      goto joined_r0x2014da50;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  iVar2 = 0;
  while ((&DAT_2091d4c4)[iVar2 * 8] != '\0') {
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return -0x25;
    }
  }
  if ((&DAT_2091d4c0)[iVar2 * 2] == 0) {
    return -0x25;
  }
  iVar1 = itron_twai_sem((&DAT_2091d4c0)[iVar2 * 2],300);
joined_r0x2014da50:
  if (iVar1 != 0) {
    return iVar1;
  }
  (&DAT_2091d4c4)[iVar2 * 8] = *(undefined1 *)(param_1 + 0x11);
  return 0;
}


// ===== fs_unlock_a @ 2014da64 (108 bytes)

/* Releases it (itron_sig_sem); -38 without one [fact] */

int fs_unlock_a(int param_1)

{
  int iVar1;
  int i;
  
  i = 0;
  do {
    if ((&DAT_2091d4c4)[i * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4c0)[i * 2] == 0) {
        return -0x26;
      }
      itron_dis_dsp();
      iVar1 = itron_sig_sem((&DAT_2091d4c0)[i * 2]);
      if (iVar1 == 0) {
        (&DAT_2091d4c4)[i * 8] = 0;
      }
      itron_ena_dsp();
      return iVar1;
    }
    i = i + 1;
  } while (i < 5);
  return -0x26;
}


// ===== fs_sem_a_create @ 2014dad0 (76 bytes)

/* Creates the five semaphores of table 0x2091D4C0 (os_create_sem_named, signalled once) used by
   fs_lock_a [fact] */

void fs_sem_a_create(void)

{
  uint os_create_sem_named_ret;
  int i;
  
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(&DAT_2091d4c0,0,0x28,0x200);
  i = 0;
  do {
    os_create_sem_named_ret = os_create_sem_named(&DAT_20427e4c,0x2014db20);
    if ((int)os_create_sem_named_ret < 1) {
      return;
    }
    (&DAT_2091d4c0)[i * 2] = os_create_sem_named_ret;
    itron_sig_sem();
    i = i + 1;
  } while (i < 5);
  return;
}


// ===== fs_sem_a_delete @ 2014db2c (64 bytes)

/* Deletes them (itron_del_sem) [fact] */

undefined4 fs_sem_a_delete(void)

{
  undefined4 uVar1;
  int i;
  
  uVar1 = 0;
  i = 0;
  do {
    if ((&DAT_2091d4c0)[i * 2] != 0) {
      uVar1 = itron_del_sem();
      (&DAT_2091d4c0)[i * 2] = 0;
    }
    i = i + 1;
  } while (i < 5);
  return uVar1;
}


// ===== fs_lock_b @ 2014db6c (164 bytes)

/* Same for the second table 0x2091D4E8 (-34) [fact] */

int fs_lock_b(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_2091d4ec)[iVar2 * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4e8)[iVar2 * 2] == 0) {
        return -0x22;
      }
      iVar1 = itron_twai_sem((&DAT_2091d4e8)[iVar2 * 2],300);
      goto joined_r0x2014dbfc;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  iVar2 = 0;
  while ((&DAT_2091d4ec)[iVar2 * 8] != '\0') {
    iVar2 = iVar2 + 1;
    if (4 < iVar2) {
      return -0x22;
    }
  }
  if ((&DAT_2091d4e8)[iVar2 * 2] == 0) {
    return -0x22;
  }
  iVar1 = itron_twai_sem((&DAT_2091d4e8)[iVar2 * 2],300);
joined_r0x2014dbfc:
  if (iVar1 != 0) {
    return iVar1;
  }
  (&DAT_2091d4ec)[iVar2 * 8] = *(undefined1 *)(param_1 + 0x11);
  return 0;
}


// ===== fs_unlock_b @ 2014dc10 (108 bytes)

/* Same release for 0x2091D4E8 (-35) [fact] */

int fs_unlock_b(int param_1)

{
  int iVar1;
  int i;
  
  i = 0;
  do {
    if ((&DAT_2091d4ec)[i * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4e8)[i * 2] == 0) {
        return -0x23;
      }
      itron_dis_dsp();
      iVar1 = itron_sig_sem((&DAT_2091d4e8)[i * 2]);
      if (iVar1 == 0) {
        (&DAT_2091d4ec)[i * 8] = 0;
      }
      itron_ena_dsp();
      return iVar1;
    }
    i = i + 1;
  } while (i < 5);
  return -0x23;
}


// ===== fs_sem_b_create @ 2014dc7c (76 bytes)

/* Same for table 0x2091D4E8 (fs_lock_b) [fact] */

void fs_sem_b_create(void)

{
  uint os_create_sem_named_ret;
  int i;
  
                    /* word fill for aligned 0x200-byte blocks, else bytes [doc] */
  fs_memset(&DAT_2091d4e8,0,0x28,0x200);
  i = 0;
  do {
    os_create_sem_named_ret = os_create_sem_named(&DAT_20427e5c,0x2014dccc);
    if ((int)os_create_sem_named_ret < 1) {
      return;
    }
    (&DAT_2091d4e8)[i * 2] = os_create_sem_named_ret;
    itron_sig_sem();
    i = i + 1;
  } while (i < 5);
  return;
}


// ===== fs_sem_b_delete @ 2014dcd8 (64 bytes)

/* Deletes them [fact] */

undefined4 fs_sem_b_delete(void)

{
  undefined4 uVar1;
  int i;
  
  uVar1 = 0;
  i = 0;
  do {
    if ((&DAT_2091d4e8)[i * 2] != 0) {
      uVar1 = itron_del_sem();
      (&DAT_2091d4e8)[i * 2] = 0;
    }
    i = i + 1;
  } while (i < 5);
  return uVar1;
}


// ===== fs_sem_wait_1s @ 2014dd18 (28 bytes)

/* itron_twai_sem(id, 1000), E_NOEXS (-42) for id <= 0 [fact] */

undefined4 fs_sem_wait_1s(int param_1)

{
  undefined4 uVar1;
  
  if (0 < param_1) {
    uVar1 = itron_twai_sem(param_1,1000);
    return uVar1;
  }
  return 0xffffffd6;
}


// ===== fs_sem_signal @ 2014dd34 (24 bytes)

/* itron_sig_sem(id), E_NOEXS (-42) for id <= 0 [fact] */

undefined4 fs_sem_signal(int param_1)

{
  undefined4 uVar1;
  
  if (0 < param_1) {
    uVar1 = itron_sig_sem(param_1);
    return uVar1;
  }
  return 0xffffffd6;
}


// ===== fs_drive_sem_create @ 2014dd4c (112 bytes)

/* Gives the drive (+0x70) the semaphore of another drive on the same device (+0x18) or creates one
   [fact] */

uint fs_drive_sem_create(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = DAT_20808ba0;
  while ((piVar3[6] != param_1[6] || (piVar3 == param_1))) {
    iVar1 = *piVar3;
    piVar3 = (int *)*piVar3;
    if (iVar1 == 0) {
      uVar2 = os_create_sem_named(&DAT_20427e6c,0x2014ddc0);
      if ((int)uVar2 < 1) {
        return uVar2;
      }
      param_1[0x1c] = uVar2;
      uVar2 = itron_sig_sem();
      return uVar2;
    }
  }
  param_1[0x1c] = piVar3[0x1c];
  return 0;
}


// ===== fs_drive_sem_delete @ 2014ddd0 (96 bytes)

/* Deletes the drive semaphore and clears it in the drives that share the device [fact] */

undefined4 fs_drive_sem_delete(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = 0;
  piVar3 = DAT_20808ba0;
  if (0 < param_1[0x1c]) {
    do {
      if ((piVar3[6] == param_1[6]) && (piVar3 != param_1)) {
        piVar3[0x1c] = 0;
      }
      iVar2 = *piVar3;
      piVar3 = (int *)*piVar3;
    } while (iVar2 != 0);
    uVar1 = itron_del_sem(param_1[0x1c]);
    param_1[0x1c] = 0;
  }
  return uVar1;
}


// ===== fs_sem1_wait @ 2014de30 (44 bytes)

/* itron_twai_sem(0x20808BB4, 300) [fact] */

undefined4 fs_sem1_wait(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb4) {
    uVar1 = itron_twai_sem(DAT_20808bb4,300);
  }
  return uVar1;
}


// ===== fs_sem1_signal @ 2014de5c (40 bytes)

/* itron_sig_sem(0x20808BB4) [fact] */

undefined4 fs_sem1_signal(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb4) {
    uVar1 = itron_sig_sem();
  }
  return uVar1;
}


// ===== fs_sem1_create @ 2014de84 (52 bytes)

/* Creates semaphore 0x20808BB4 (os_create_sem_named) [fact] */

void fs_sem1_create(void)

{
  uint os_create_sem_named_ret;
  
  DAT_20808bb4 = 0;
  os_create_sem_named_ret = os_create_sem_named(&DAT_20427e7c,0x2014debc);
  if (0 < (int)os_create_sem_named_ret) {
    DAT_20808bb4 = os_create_sem_named_ret;
    itron_sig_sem();
    return;
  }
  return;
}


// ===== fs_sem1_delete @ 2014decc (40 bytes)

/* itron_del_sem(0x20808BB4) [fact] */

undefined4 fs_sem1_delete(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb4) {
    uVar1 = itron_del_sem();
  }
  return uVar1;
}


// ===== fs_sem2_wait @ 2014def4 (44 bytes)

/* itron_twai_sem(0x20808BB8, 300) [fact] */

undefined4 fs_sem2_wait(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb8) {
    uVar1 = itron_twai_sem(DAT_20808bb8,300);
  }
  return uVar1;
}


// ===== fs_sem2_signal @ 2014df20 (40 bytes)

/* itron_sig_sem(0x20808BB8) [fact] */

undefined4 fs_sem2_signal(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb8) {
    uVar1 = itron_sig_sem();
  }
  return uVar1;
}


// ===== fs_sem2_create @ 2014df48 (52 bytes)

/* Creates semaphore 0x20808BB8 [fact] */

void fs_sem2_create(void)

{
  uint os_create_sem_named_ret;
  
  DAT_20808bb8 = 0;
  os_create_sem_named_ret = os_create_sem_named(&DAT_20427e8c,0x2014df7c);
  if (0 < (int)os_create_sem_named_ret) {
    DAT_20808bb8 = os_create_sem_named_ret;
    itron_sig_sem();
    return;
  }
  return;
}


// ===== fs_sem2_delete @ 2014df8c (40 bytes)

/* itron_del_sem(0x20808BB8) [fact] */

undefined4 fs_sem2_delete(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb8) {
    uVar1 = itron_del_sem();
  }
  return uVar1;
}


// ===== fsys_sem_wait @ 2014dfb4 (40 bytes)

/* itron_twai_sem on the fsys semaphore 0x20808BBC (fsys_init_sem), result in 0x20808BC0 [fact] */

void fsys_sem_wait(void)

{
  if (0 < DAT_20808bbc) {
    DAT_20808bc0 = itron_twai_sem(DAT_20808bbc,300);
  }
  return;
}


// ===== fsys_sem_signal @ 2014dfdc (36 bytes)

/* itron_sig_sem on 0x20808BBC, result in 0x20808BC0 [fact] */

void fsys_sem_signal(void)

{
  if (0 < DAT_20808bbc) {
    DAT_20808bc0 = itron_sig_sem(DAT_20808bbc);
  }
  return;
}


// ===== fsys_init_sem @ 2014e000 (52 bytes)

/* fsys_sem */

void fsys_init_sem(void)

{
  uint os_create_sem_named_ret;
  
  DAT_20808bbc = 0;
  os_create_sem_named_ret = os_create_sem_named(&DAT_20427e9c,0x2014e034);
  if (0 < (int)os_create_sem_named_ret) {
    DAT_20808bbc = os_create_sem_named_ret;
    itron_sig_sem();
    return;
  }
  return;
}


// ===== fsys_sem_delete @ 2014e044 (40 bytes)

/* itron_del_sem(0x20808BBC) [fact] */

undefined4 fsys_sem_delete(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bbc) {
    uVar1 = itron_del_sem();
  }
  return uVar1;
}


// ===== fs_mpf_alloc @ 2014e06c (64 bytes)

/* Block from pool 0x20808BC4 (itron_tget_mpf, no wait) for sizes <= 0x10000, 0 otherwise [fact] */

undefined4 fs_mpf_alloc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_8;
  
  if (0x10000 < param_1) {
    return 0;
  }
  if ((DAT_20808bc4 < 1) ||
     (local_8 = param_4, iVar1 = itron_tget_mpf(DAT_20808bc4,&local_8,0), iVar1 != 0)) {
    local_8 = 0;
  }
  return local_8;
}


// ===== fs_mpf_free @ 2014e0ac (28 bytes)

/* itron_rel_mpf to pool 0x20808BC4 [fact] */

void fs_mpf_free(undefined4 param_1)

{
  if (0 < DAT_20808bc4) {
    itron_rel_mpf(DAT_20808bc4,param_1);
    return;
  }
  return;
}


// ===== fs_mpf_create @ 2014e0c8 (36 bytes)

/* Creates the "fsys_mpf" fixed pool 0x20808BC4 [fact] */

void fs_mpf_create(void)

{
  DAT_20808bc4 = os_create_mpf_named(&DAT_20427eac,"fsys_mpf");
  if (DAT_20808bc4 < 1) {
    DAT_20808bc4 = 0;
  }
  return;
}


// ===== fs_mpf_delete @ 2014e100 (24 bytes)

/* itron_del_mpf of pool 0x20808BC4 [fact] */

void fs_mpf_delete(void)

{
  if (0 < DAT_20808bc4) {
    itron_del_mpf();
    return;
  }
  return;
}


// ===== fs_work_alloc @ 2014e118 (52 bytes)

/* itron_tget_mpf from pool 0x20808BC8, 0 on failure [fact] */

undefined4 fs_work_alloc(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 local_8;
  
  if ((DAT_20808bc8 < 1) ||
     (local_8 = in_r3, iVar1 = itron_tget_mpf(DAT_20808bc8,&local_8,0), iVar1 != 0)) {
    local_8 = 0;
  }
  return local_8;
}


// ===== fs_work_free @ 2014e14c (44 bytes)

/* itron_rel_mpf to pool 0x20808BC8 [fact] */

undefined4 fs_work_free(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bc8) {
    uVar1 = itron_rel_mpf(DAT_20808bc8,param_1);
  }
  return uVar1;
}

