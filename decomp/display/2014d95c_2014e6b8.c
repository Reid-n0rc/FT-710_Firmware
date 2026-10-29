// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

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


// ===== FUN_2014d98c @ 2014d98c (48 bytes)

void FUN_2014d98c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_2091d4c4)[iVar2 * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4c0)[iVar2 * 2] == 0) {
        return -0x26;
      }
      itron_dis_dsp();
      iVar1 = itron_sig_sem((&DAT_2091d4c0)[iVar2 * 2]);
      if (iVar1 == 0) {
        (&DAT_2091d4c4)[iVar2 * 8] = 0;
      }
      itron_ena_dsp();
      return iVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return -0x26;
}


// ===== FUN_2014dad0 @ 2014dad0 (76 bytes)

void FUN_2014dad0(void)

{
  uint uVar1;
  int iVar2;
  
  fs_memset(&DAT_2091d4c0,0,0x28,0x200);
  iVar2 = 0;
  do {
    uVar1 = os_create_sem_named(&DAT_20427e4c,0x2014db20);
    if ((int)uVar1 < 1) {
      return;
    }
    (&DAT_2091d4c0)[iVar2 * 2] = uVar1;
    itron_sig_sem();
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}


// ===== FUN_2014db2c @ 2014db2c (64 bytes)

undefined4 FUN_2014db2c(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if ((&DAT_2091d4c0)[iVar2 * 2] != 0) {
      uVar1 = itron_del_sem();
      (&DAT_2091d4c0)[iVar2 * 2] = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
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
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_2091d4ec)[iVar2 * 8] == *(char *)(param_1 + 0x11)) {
      if ((&DAT_2091d4e8)[iVar2 * 2] == 0) {
        return -0x23;
      }
      itron_dis_dsp();
      iVar1 = itron_sig_sem((&DAT_2091d4e8)[iVar2 * 2]);
      if (iVar1 == 0) {
        (&DAT_2091d4ec)[iVar2 * 8] = 0;
      }
      itron_ena_dsp();
      return iVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return -0x23;
}


// ===== FUN_2014dc7c @ 2014dc7c (76 bytes)

void FUN_2014dc7c(void)

{
  uint uVar1;
  int iVar2;
  
  fs_memset(&DAT_2091d4e8,0,0x28,0x200);
  iVar2 = 0;
  do {
    uVar1 = os_create_sem_named(&DAT_20427e5c,0x2014dccc);
    if ((int)uVar1 < 1) {
      return;
    }
    (&DAT_2091d4e8)[iVar2 * 2] = uVar1;
    itron_sig_sem();
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}


// ===== FUN_2014dcd8 @ 2014dcd8 (64 bytes)

undefined4 FUN_2014dcd8(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if ((&DAT_2091d4e8)[iVar2 * 2] != 0) {
      uVar1 = itron_del_sem();
      (&DAT_2091d4e8)[iVar2 * 2] = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return uVar1;
}


// ===== FUN_2014dd18 @ 2014dd18 (28 bytes)

undefined4 FUN_2014dd18(int param_1)

{
  undefined4 uVar1;
  
  if (0 < param_1) {
    uVar1 = itron_twai_sem(param_1,1000);
    return uVar1;
  }
  return 0xffffffd6;
}


// ===== FUN_2014dd34 @ 2014dd34 (24 bytes)

undefined4 FUN_2014dd34(int param_1)

{
  undefined4 uVar1;
  
  if (0 < param_1) {
    uVar1 = itron_sig_sem(param_1);
    return uVar1;
  }
  return 0xffffffd6;
}


// ===== FUN_2014dd4c @ 2014dd4c (112 bytes)

uint FUN_2014dd4c(int *param_1)

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


// ===== FUN_2014ddd0 @ 2014ddd0 (96 bytes)

undefined4 FUN_2014ddd0(int *param_1)

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


// ===== FUN_2014de30 @ 2014de30 (44 bytes)

undefined4 FUN_2014de30(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb4) {
    uVar1 = itron_twai_sem(DAT_20808bb4,300);
  }
  return uVar1;
}


// ===== FUN_2014de5c @ 2014de5c (40 bytes)

undefined4 FUN_2014de5c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb4) {
    uVar1 = itron_sig_sem();
  }
  return uVar1;
}


// ===== FUN_2014de84 @ 2014de84 (52 bytes)

void FUN_2014de84(void)

{
  uint uVar1;
  
  DAT_20808bb4 = 0;
  uVar1 = os_create_sem_named(&DAT_20427e7c,0x2014debc);
  if (0 < (int)uVar1) {
    DAT_20808bb4 = uVar1;
    itron_sig_sem();
    return;
  }
  return;
}


// ===== FUN_2014decc @ 2014decc (40 bytes)

undefined4 FUN_2014decc(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb4) {
    uVar1 = itron_del_sem();
  }
  return uVar1;
}


// ===== FUN_2014def4 @ 2014def4 (44 bytes)

undefined4 FUN_2014def4(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb8) {
    uVar1 = itron_twai_sem(DAT_20808bb8,300);
  }
  return uVar1;
}


// ===== FUN_2014df20 @ 2014df20 (40 bytes)

undefined4 FUN_2014df20(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb8) {
    uVar1 = itron_sig_sem();
  }
  return uVar1;
}


// ===== FUN_2014df48 @ 2014df48 (52 bytes)

void FUN_2014df48(void)

{
  uint uVar1;
  
  DAT_20808bb8 = 0;
  uVar1 = os_create_sem_named(&DAT_20427e8c,0x2014df7c);
  if (0 < (int)uVar1) {
    DAT_20808bb8 = uVar1;
    itron_sig_sem();
    return;
  }
  return;
}


// ===== FUN_2014df8c @ 2014df8c (40 bytes)

undefined4 FUN_2014df8c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bb8) {
    uVar1 = itron_del_sem();
  }
  return uVar1;
}


// ===== FUN_2014dfb4 @ 2014dfb4 (40 bytes)

void FUN_2014dfb4(void)

{
  if (0 < DAT_20808bbc) {
    DAT_20808bc0 = itron_twai_sem(DAT_20808bbc,300);
  }
  return;
}


// ===== FUN_2014dfdc @ 2014dfdc (36 bytes)

void FUN_2014dfdc(void)

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
  uint uVar1;
  
  DAT_20808bbc = 0;
  uVar1 = os_create_sem_named(&DAT_20427e9c,0x2014e034);
  if (0 < (int)uVar1) {
    DAT_20808bbc = uVar1;
    itron_sig_sem();
    return;
  }
  return;
}


// ===== FUN_2014e044 @ 2014e044 (40 bytes)

undefined4 FUN_2014e044(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bbc) {
    uVar1 = itron_del_sem();
  }
  return uVar1;
}


// ===== FUN_2014e06c @ 2014e06c (64 bytes)

undefined4 FUN_2014e06c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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


// ===== FUN_2014e0ac @ 2014e0ac (28 bytes)

void FUN_2014e0ac(undefined4 param_1)

{
  if (0 < DAT_20808bc4) {
    itron_rel_mpf(DAT_20808bc4,param_1);
    return;
  }
  return;
}


// ===== FUN_2014e0c8 @ 2014e0c8 (36 bytes)

void FUN_2014e0c8(void)

{
  DAT_20808bc4 = os_create_mpf_named(&DAT_20427eac,"fsys_mpf");
  if (DAT_20808bc4 < 1) {
    DAT_20808bc4 = 0;
  }
  return;
}


// ===== FUN_2014e100 @ 2014e100 (24 bytes)

void FUN_2014e100(void)

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


// ===== FUN_2014e178 @ 2014e178 (44 bytes)

int FUN_2014e178(void)

{
  int iVar1;
  
  iVar1 = os_create_mpf_named(&DAT_20427ec0,"FSYS Work");
  if (iVar1 < 1) {
    DAT_20808bc8 = 0;
  }
  else {
    iVar1 = 0;
    DAT_20808bc8 = iVar1;
  }
  return iVar1;
}


// ===== FUN_2014e1b4 @ 2014e1b4 (40 bytes)

undefined4 FUN_2014e1b4(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0 < DAT_20808bc8) {
    uVar1 = itron_del_mpf();
  }
  return uVar1;
}


// ===== FUN_2014e1dc @ 2014e1dc (16 bytes)

undefined4 FUN_2014e1dc(int *param_1)

{
  rtc_get_tm(param_1);
  return 1;
}


// ===== FUN_2014e1ec @ 2014e1ec (28 bytes)

undefined4 FUN_2014e1ec(void)

{
  undefined1 auStack_10 [4];
  undefined4 local_c;
  
  itron_get_tim(auStack_10);
  return local_c;
}


// ===== FUN_2014e208 @ 2014e208 (72 bytes)

int FUN_2014e208(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    uVar1 = *param_2;
    uVar2 = tolower(*param_1);
    uVar2 = uVar2 & 0xff;
    uVar3 = tolower(uVar1);
    if (uVar2 != (uVar3 & 0xff)) {
      return uVar2 - (uVar3 & 0xff);
    }
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (uVar2 != 0);
  return 0;
}


// ===== FUN_2014e250 @ 2014e250 (84 bytes)

int FUN_2014e250(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  while( true ) {
    bVar4 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar4) {
      return 0;
    }
    uVar1 = *param_2;
    uVar2 = tolower(*param_1);
    uVar2 = uVar2 & 0xff;
    uVar3 = tolower(uVar1);
    if (uVar2 != (uVar3 & 0xff)) break;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    if (uVar2 == 0) {
      return 0;
    }
  }
  return uVar2 - (uVar3 & 0xff);
}


// ===== strncmp @ 2014e2a4 (64 bytes)

int strncmp(byte *param_1,byte *param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  
  while( true ) {
    bVar2 = param_3 == 0;
    param_3 = param_3 + -1;
    if (bVar2) {
      return 0;
    }
    uVar1 = (uint)*param_1;
    if (*param_2 != uVar1) break;
    if (uVar1 == 0) {
      return 0;
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return uVar1 - *param_2;
}


// ===== FUN_2014e2e4 @ 2014e2e4 (60 bytes)

char * FUN_2014e2e4(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
  pcVar4 = param_1;
  do {
    iVar6 = param_3;
    if (iVar6 == 0) {
      return param_1;
    }
    cVar1 = *param_2;
    pcVar5 = pcVar4 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar5;
    param_2 = param_2 + 1;
    param_3 = iVar6 + -1;
  } while (cVar1 != '\0');
  iVar3 = iVar6 + -2;
  iVar6 = iVar6 + -1;
  while (iVar2 = iVar3, iVar6 != 0) {
    *pcVar5 = '\0';
    pcVar5 = pcVar5 + 1;
    iVar3 = iVar2 + -1;
    iVar6 = iVar2;
  }
  return param_1;
}


// ===== FUN_2014e320 @ 2014e320 (164 bytes)

char * FUN_2014e320(char *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  
  if ((param_1 != (char *)0x0) || (param_1 = (char *)*param_3, param_1 != (char *)0x0)) {
    for (; cVar5 = *param_1, cVar5 != '\0'; param_1 = param_1 + 1) {
      cVar1 = *param_2;
      pcVar4 = param_2;
      while( true ) {
        pcVar3 = param_2;
        pcVar2 = param_1;
        if (cVar1 == '\0') {
          while( true ) {
            cVar1 = *pcVar3;
            if (cVar5 == cVar1) break;
            pcVar3 = pcVar3 + 1;
            if (cVar1 == '\0') {
              cVar5 = pcVar2[1];
              pcVar3 = param_2;
              pcVar2 = pcVar2 + 1;
            }
          }
          if (cVar5 == '\0') {
            *param_3 = 0;
          }
          else {
            *pcVar2 = '\0';
            *param_3 = pcVar2 + 1;
          }
          return param_1;
        }
        if (cVar5 == cVar1) break;
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar4;
      }
    }
    *param_3 = 0;
  }
  return (char *)0x0;
}


// ===== FUN_2014e3c4 @ 2014e3c4 (448 bytes)

/* WARNING: Removing unreachable block (ram,0x2014e53c) */

uint FUN_2014e3c4(byte *param_1,undefined4 *param_2,uint param_3)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  ulonglong uVar14;
  
  bVar3 = false;
  pbVar9 = param_1;
  if (((-1 < (int)param_3) && (param_3 != 1)) && ((int)param_3 < 0x25)) {
    uVar8 = (uint)*param_1;
    piVar6 = (int *)__rt_ctype_table();
    iVar11 = *piVar6;
    bVar1 = *(byte *)(iVar11 + uVar8);
    pbVar5 = param_1;
    while (pbVar4 = pbVar5 + 1, (bVar1 & 1) != 0) {
      uVar8 = (uint)*pbVar4;
      pbVar5 = pbVar4;
      bVar1 = *(byte *)(iVar11 + uVar8);
    }
    bVar12 = false;
    if ((uVar8 == 0x2b) || (bVar12 = uVar8 == 0x2d, pbVar9 = pbVar4, bVar12)) {
      pbVar9 = pbVar5 + 2;
      uVar8 = (uint)*pbVar4;
    }
    if (uVar8 != 0) {
      if (param_3 == 0 || param_3 == 0x10) {
        if ((uVar8 == 0x30) && (*pbVar9 == 0x78 || *pbVar9 == 0x58)) {
          param_3 = 0x10;
          uVar8 = (uint)pbVar9[1];
          pbVar9 = pbVar9 + 2;
        }
        else if (param_3 == 0) {
          if (uVar8 == 0x30) {
            param_3 = 8;
          }
          else {
            param_3 = 10;
          }
        }
      }
      uVar10 = 0;
      bVar2 = false;
      if (bVar12) {
        uVar14 = __aeabi_uidivmod(0x80000000);
      }
      else {
        uVar14 = __aeabi_idivmod(0x7fffffff,param_3);
      }
      do {
        if (*(byte *)(iVar11 + uVar8) == 0x20) {
          uVar8 = uVar8 - 0x30;
        }
        else {
          if ((*(byte *)(iVar11 + uVar8) & 0x98) == 0) goto LAB_2014e52c;
          if (uVar8 < 0x61) {
            uVar8 = uVar8 - 0x37;
          }
          else {
            uVar8 = uVar8 - 0x57;
          }
        }
        uVar7 = uVar8 & 0xff;
        if ((int)param_3 <= (int)uVar7) goto LAB_2014e52c;
        if (!bVar2) {
          bVar13 = (uint)uVar14 <= uVar10;
          if (uVar10 == (uint)uVar14) {
            bVar13 = (uint)(uVar14 >> 0x20) <= uVar7;
          }
          bVar3 = true;
          if (bVar13 && uVar14 != (CONCAT44(uVar8,uVar10) & 0xffffffffff)) {
            if (bVar12) {
              uVar10 = 0x80000000;
            }
            else {
              uVar10 = 0x7fffffff;
            }
            bVar2 = true;
            bVar12 = false;
          }
          else {
            uVar10 = uVar10 * param_3 + uVar7;
          }
        }
        uVar8 = (uint)*pbVar9;
        pbVar9 = pbVar9 + 1;
      } while( true );
    }
  }
LAB_2014e540:
  uVar10 = 0;
LAB_2014e558:
  if (param_2 != (undefined4 *)0x0) {
    if (bVar3) {
      *param_2 = pbVar9 + -1;
    }
    else {
      *param_2 = param_1;
    }
  }
  return uVar10;
LAB_2014e52c:
  if (bVar3) {
    if ((bVar12) && (!bVar2)) {
      uVar10 = -uVar10;
    }
    goto LAB_2014e558;
  }
  goto LAB_2014e540;
}


// ===== os_create_sem_named @ 2014e584 (44 bytes)

/* wrapper around itron_acre_sem with a name string */

uint os_create_sem_named(void *param_1,uint param_2)

{
  uint uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  uint uStack_c;
  
  local_18 = *(undefined4 *)param_1;
  uStack_14 = *(undefined4 *)((int)param_1 + 4);
  local_10 = *(undefined4 *)((int)param_1 + 8);
  uStack_c = param_2;
  uVar1 = itron_acre_sem(0,&local_18);
  return uVar1;
}


// ===== os_create_tsk_named @ 2014e5b0 (52 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (wrapper 0.850): copies a 6-word T_CTSK and appends
   the name, then itron_acre_tsk(0, ..); same shape as os_create_sem_named [inference] */

void os_create_tsk_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_28 = *param_1;
  uStack_24 = param_1[1];
  uStack_20 = param_1[2];
  uStack_1c = param_1[3];
  local_18 = param_1[4];
  local_14 = param_1[5];
  uStack_10 = param_2;
  itron_acre_tsk(0,(byte *)&local_28);
  return;
}


// ===== os_create_flg_named @ 2014e5e4 (44 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (wrapper 0.850): same wrapper around itron_acre_flg
   [inference] */

void os_create_flg_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  uStack_8 = param_2;
  itron_acre_flg(0,(byte *)&local_10);
  return;
}


// ===== os_create_mbf_named @ 2014e610 (40 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (wrapper 0.850): same wrapper around itron_acre_mbf
   [inference] */

void os_create_mbf_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  uStack_10 = param_1[2];
  uStack_c = param_1[3];
  local_8 = param_2;
  itron_acre_mbf(0,&local_18);
  return;
}


// ===== os_create_mbx_named @ 2014e638 (44 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (wrapper 0.850): same wrapper around itron_acre_mbx
   [inference] */

void os_create_mbx_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  local_10 = param_1[2];
  uStack_c = param_2;
  itron_acre_mbx(0,&local_18);
  return;
}


// ===== os_create_mtx_named @ 2014e664 (44 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (wrapper 0.850): same wrapper around itron_acre_mtx
   [inference] */

void os_create_mtx_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  uStack_8 = param_2;
  itron_acre_mtx(0,&local_10);
  return;
}


// ===== os_create_mpf_named @ 2014e690 (40 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (wrapper 0.850): same wrapper around itron_acre_mpf
   [inference] */

void os_create_mpf_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  uStack_10 = param_1[2];
  uStack_c = param_1[3];
  local_8 = param_2;
  itron_acre_mpf(0,&local_18);
  return;
}


// ===== os_create_mpl_named @ 2014e6b8 (44 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (wrapper 0.850): same wrapper around itron_acre_mpl
   [inference] */

void os_create_mpl_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  local_10 = param_1[2];
  uStack_c = param_2;
  itron_acre_mpl(0,&local_18);
  return;
}

