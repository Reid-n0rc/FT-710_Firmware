// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc0e72 @ fffc0e72 (13 bytes)

void FUN_fffc0e72(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(0xb);
  return;
}


// ===== FUN_fffc0e7f @ fffc0e7f (57 bytes)

void FUN_fffc0e7f(void)

{
  FUN_fffc8d8c(3000);
  DAT_00009dc6 = DAT_00009dc6 == '\0';
  sci3_set_baud();
  beep_request(1);
  return;
}


// ===== FUN_fffc0eb8 @ fffc0eb8 (88 bytes)

void FUN_fffc0eb8(byte param_1)

{
  byte bVar1;
  byte *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  bVar1 = *local_8;
  *local_8 = bVar1 & 0xf0 | param_1;
  FUN_fffc0f10(bVar1 & 0xf,param_1,local_8);
  PTR_DAT_00025d54[0x40b] = 1;
  return;
}


// ===== FUN_fffc0f10 @ fffc0f10 (188 bytes)

void FUN_fffc0f10(byte param_1,byte param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (DAT_00009aa2 != '\0') {
    uVar1 = (uint)param_1;
    if (uVar1 - 4 < 0xb) {
      if (param_2 == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,param_3);
        return;
      }
      if (param_2 == 0) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,param_3);
        return;
      }
    }
    else if (uVar1 == 1) {
      if (param_2 - 2 < 0xd) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,param_3);
        return;
      }
      if (param_2 == 0) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(iVar3 << 1,param_3);
        return;
      }
    }
    else if (uVar1 - 2 < 2) {
      if (param_2 == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,param_3);
        return;
      }
      if (param_2 == 0) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,param_3);
        return;
      }
    }
    else if (uVar1 == 0) {
      if (param_2 - 2 < 0xd) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,param_3);
        return;
      }
      if (param_2 == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(iVar3 * -2,param_3);
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffc0fcc @ fffc0fcc (225 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc0fe3) */
/* WARNING: Removing unreachable block (ram,0xfffc0fee) */

void FUN_fffc0fcc(int param_1,undefined1 *param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_c;
  
  if (param_1 != 0) {
    uVar2 = CONCAT31(CONCAT21(CONCAT11(param_2[0x4a],param_2[0x4b]),param_2[0x4c]),param_2[0x4d]);
    if ((uVar2 < 0x3b9ac9f7) && (param_1 < 0x3b9ac9f7)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (param_1 < -0x3b9ac9f6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_c = uVar2 + param_1;
      if (local_c < 0) {
        local_c = 0;
      }
      DAT_0001b4e1 = 1;
      uVar3 = freq_clamp(param_2 != &DAT_00009d09,local_c);
      DAT_0001b4e1 = 0;
      param_2[0x4a] = (char)((uint)uVar3 >> 0x18);
      param_2[0x4b] = (char)((uint)uVar3 >> 0x10);
      param_2[0x4c] = (char)((uint)uVar3 >> 8);
      local_c._0_1_ = (undefined1)uVar3;
      param_2[0x4d] = (undefined1)local_c;
      vfo_mark_tuned(param_2 != &DAT_00009d09);
      return;
    }
  }
  return;
}


// ===== FUN_fffc10ad @ fffc10ad (22 bytes)

void FUN_fffc10ad(void)

{
  return;
}


// ===== freq_clamp @ fffc10c3 (229 bytes)

/* (side, f): clamp/wrap to 30k..75M (0xFFF89D4C) or PMS limits 0x20F74/78; returns f */

void freq_clamp(char param_1,undefined4 param_2)

{
  bool bVar1;
  char cVar2;
  undefined4 local_10 [2];
  undefined4 local_8;
  char local_1;
  
  PTR_DAT_00025d54[0x469] = 0;
  local_10[0] = param_2;
  local_8 = param_2;
  local_1 = param_1;
  if (param_1 == '\0') {
    if (DAT_00009dbe == '\x04') {
      if ((DAT_00020f74 == 0) || (DAT_00020f78 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        pms_load_limits(0);
      }
      freq_clamp_pms(local_10[0]);
      return;
    }
  }
  else if (DAT_00009dbf == '\x04') {
    if ((DAT_00020f74 == 0) || (DAT_00020f78 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      pms_load_limits(param_1);
    }
    freq_clamp_pms(local_10[0]);
    return;
  }
  cVar2 = range_cmp3(local_10,&tune_limits);
  if (cVar2 == '\0') {
    freq_fix_below(local_10,&tune_limits);
  }
  else if (cVar2 == '\x01') {
    freq_fix_above(local_10,&tune_limits);
  }
  return;
}


// ===== freq_clamp_pms @ fffc11a8 (178 bytes)

/* PMS-limit variant of freq_clamp */

void freq_clamp_pms(undefined4 param_1)

{
  bool bVar1;
  undefined4 uStack_10;
  char cStack_9;
  undefined4 local_4;
  
  local_4 = param_1;
  cStack_9 = range_cmp3();
  uStack_10 = local_4;
  if (cStack_9 == '\0') {
    if ((PTR_DAT_00025d54[0x460] == '\x01') || (DAT_0001b4e2 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d54[0x469] = 1;
    }
    else {
      freq_fix_below(&uStack_10,PTR_DAT_00025d54 + 0x470);
    }
  }
  else if (cStack_9 == '\x01') {
    if ((PTR_DAT_00025d54[0x460] == '\x01') || (DAT_0001b4e2 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d54[0x469] = 1;
    }
    else {
      freq_fix_above(&uStack_10,PTR_DAT_00025d54 + 0x470);
    }
  }
  return;
}


// ===== vfo_mark_tuned @ fffc125a (33 bytes)

/* rt+0x444/0x446 = 1, QMB state -> VFO */

void vfo_mark_tuned(uint param_1)

{
  if (param_1 == 0) {
    PTR_DAT_00025d54[0x444] = 1;
  }
  else {
    PTR_DAT_00025d54[0x446] = 1;
  }
  qmb_exit_to_vfo(param_1 & 0xff);
  return;
}


// ===== qmb_exit_to_vfo @ fffc127b (144 bytes)

/* state 5 -> 1 */

void qmb_exit_to_vfo(int param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if ((DAT_00009dbe == '\x04') || (DAT_00009dbe != '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00009dbe == '\x05')) {
      DAT_00009dbe = 1;
      return;
    }
  }
  else {
    if ((DAT_00009dbf == '\x04') || (DAT_00009dbf != '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00009dbf == '\x05')) {
      DAT_00009dbf = 1;
      return;
    }
  }
  return;
}


// ===== freq_fix_below @ fffc130b (109 bytes)

/* Below-limit handling (clamp, or wrap while scanning) */

void freq_fix_below(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *param_1 = *param_2;
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    *param_1 = *param_2;
    return;
  }
  if (PTR_DAT_00025d54[0x46a] != '\x01') {
    if (PTR_DAT_00025d54[0x418] != '\x01') {
      *param_1 = *param_2;
      return;
    }
    *param_1 = param_2[1];
    return;
  }
  FUN_fffc142c(param_1,param_2);
  return;
}


// ===== freq_fix_above @ fffc1378 (111 bytes)

/* Above-limit handling (clamp, or wrap while scanning) */

void freq_fix_above(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *param_1 = param_2[1];
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    *param_1 = param_2[1];
    return;
  }
  if (PTR_DAT_00025d54[0x46a] != '\x01') {
    if (PTR_DAT_00025d54[0x418] != '\x01') {
      *param_1 = param_2[1];
      return;
    }
    *param_1 = *param_2;
    return;
  }
  FUN_fffc14c6(param_1,param_2);
  return;
}


// ===== FUN_fffc13e7 @ fffc13e7 (69 bytes)

undefined1 FUN_fffc13e7(void)

{
  undefined1 uVar1;
  
  PTR_DAT_00025d54[0x469] = 1;
  if ((PTR_DAT_00025d54[0x460] == '\x01') || (DAT_0001b4e2 == '\x01')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_fffc142c @ fffc142c (41 bytes)

void FUN_fffc142c(uint *param_1,int param_2)

{
  undefined4 uStack_c;
  
  uStack_c = FUN_fffc1455(param_1,*(undefined4 *)(param_2 + 4));
  if (*(uint *)(param_2 + 4) < uStack_c) {
    uStack_c = uStack_c - 100000;
  }
  *param_1 = uStack_c;
  return;
}


// ===== FUN_fffc1455 @ fffc1455 (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc1470) */
/* WARNING: Removing unreachable block (ram,0xfffc149c) */
/* WARNING: Removing unreachable block (ram,0xfffc14ab) */
/* WARNING: Removing unreachable block (ram,0xfffc147f) */

void FUN_fffc1455(void)

{
  return;
}


// ===== FUN_fffc14c6 @ fffc14c6 (75 bytes)

void FUN_fffc14c6(int *param_1,undefined4 *param_2)

{
  undefined *puStack_c;
  
  if (*param_1 < 0) {
    *param_1 = (int)(&DAT_000186a0 + *param_1);
    FUN_fffc142c(param_1,param_2);
    return;
  }
  puStack_c = (undefined *)FUN_fffc1455(param_1,*param_2);
  if (puStack_c < (undefined *)*param_2) {
    puStack_c = &DAT_000186a0 + (int)puStack_c;
  }
  *param_1 = (int)puStack_c;
  return;
}


// ===== FUN_fffc151d @ fffc151d (183 bytes)

void FUN_fffc151d(ushort param_1)

{
  bool bVar1;
  
  if ((param_1 < 0x6b) || (0x76 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    PTR_DAT_00025d54[0x41e] = 1;
    PTR_DAT_00025d54[0x1dc] = (char)param_1 + -0x6b;
    PTR_DAT_00025d54[0x424] = PTR_DAT_00025d54[0x1dc];
    if (DAT_00009c5e == '\x01') {
      DAT_00009c5e = '\0';
      DAT_00009dbe = PTR_DAT_00025d54[0x484];
      DAT_00009dbf = PTR_DAT_00025d54[0x485];
      PTR_DAT_00025d54[0x483] = 0;
      DAT_00020f09 = 0;
    }
    FUN_fffc8d8c(1000);
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc15d4 @ fffc15d4 (49 bytes)

void FUN_fffc15d4(void)

{
  if ((PTR_DAT_00025d54[0x41e] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\f')) {
    FUN_fffc1605(PTR_DAT_00025d54[0x424]);
    return;
  }
  return;
}


// ===== FUN_fffc1605 @ fffc1605 (32 bytes)

void FUN_fffc1605(byte param_1)

{
  PTR_DAT_00025d54[0x41e] = 1;
  if (0xb < param_1) {
    return;
  }
  FUN_fffc1625(param_1);
  return;
}


// ===== FUN_fffc1625 @ fffc1625 (62 bytes)

void FUN_fffc1625(undefined1 param_1)

{
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    FUN_fffbc638();
    FUN_fffc3c85();
    FUN_fffc23b6();
    FUN_fffc4caa();
    band_select(param_1);
    FUN_fffec578();
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== band_select @ fffc1663 (147 bytes)

/* Band key on the active side; 0x20F28 = min(band,11); dispatch by state */

void band_select(byte param_1)

{
  char local_3;
  bool local_2;
  
  if (param_1 < 0xb) {
    PTR_DAT_00025d54[0x424] = param_1;
  }
  else {
    PTR_DAT_00025d54[0x424] = 0xb;
  }
  if (DAT_00009dbd == '\0') {
    local_3 = DAT_00009dbe;
    DAT_00020f29 = 0;
  }
  else {
    local_3 = DAT_00009dbf;
    DAT_00020f2a = 0;
  }
  local_2 = DAT_00009dbd != '\0';
  vfo_store_back(local_2);
  if (local_3 == '\x04') {
    band_select_pms(local_2,param_1);
    return;
  }
  if (local_3 == '\x03') {
    band_select_memtune(local_2,param_1);
    return;
  }
  if (local_3 != '\x02') {
    band_select_vfo();
    return;
  }
  band_select_mem(local_2,param_1);
  return;
}


// ===== vfo_store_back @ fffc16f6 (233 bytes)

/* Store operating record back (band stack / memory-tune backup) according to state */

void vfo_store_back(int param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if (PTR_DAT_00025d54[0x443] == '\0') {
      FUN_fffc17df();
      return;
    }
    PTR_DAT_00025d54[0x443] = 0;
    if (PTR_DAT_00025d54[0x43d] == '\x01') {
      FUN_fffc18bf();
      return;
    }
    if ((DAT_00009dbe == '\x03') || (DAT_00009dbe == '\x04')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc18c3();
      return;
    }
    if (DAT_00009dbe != '\x02') {
      FUN_fffc18bf();
      return;
    }
  }
  else {
    if (PTR_DAT_00025d54[0x445] == '\0') {
      FUN_fffc184f();
      return;
    }
    PTR_DAT_00025d54[0x445] = 0;
    if (PTR_DAT_00025d54[0x43e] == '\x01') {
      FUN_fffc18bf();
      return;
    }
    if ((DAT_00009dbf == '\x03') || (DAT_00009dbf == '\x04')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc18e1();
      return;
    }
    if (DAT_00009dbf != '\x02') {
      FUN_fffc18bf();
      return;
    }
  }
  return;
}


// ===== FUN_fffc17df @ fffc17df (112 bytes)

void FUN_fffc17df(void)

{
  bool bVar1;
  
  PTR_DAT_00025d54[0x443] = 0;
  PTR_DAT_00025d54[0x444] = 0;
  if (PTR_DAT_00025d54[0x43d] == '\x01') {
    bandstack_save();
    return;
  }
  if ((DAT_00009dbe == '\x03') || (DAT_00009dbe == '\x04')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00009dbe != '\x02') {
      bandstack_save();
      return;
    }
    return;
  }
  FUN_fffc1a0d();
  return;
}


// ===== FUN_fffc184f @ fffc184f (112 bytes)

void FUN_fffc184f(void)

{
  bool bVar1;
  
  PTR_DAT_00025d54[0x445] = 0;
  PTR_DAT_00025d54[0x446] = 0;
  if (PTR_DAT_00025d54[0x43e] == '\x01') {
    bandstack_save();
    return;
  }
  if ((DAT_00009dbf == '\x03') || (DAT_00009dbf == '\x04')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00009dbf != '\x02') {
      bandstack_save();
      return;
    }
    return;
  }
  FUN_fffc1a35();
  return;
}


// ===== FUN_fffc18bf @ fffc18bf (4 bytes)

void FUN_fffc18bf(void)

{
  bandstack_save();
  return;
}


// ===== FUN_fffc18c3 @ fffc18c3 (30 bytes)

void FUN_fffc18c3(void)

{
  memtune_backup_a();
  PTR_DAT_00025d54[0x43f] = 1;
  PTR_DAT_00025d54[0x441] = 1;
  return;
}


// ===== FUN_fffc18e1 @ fffc18e1 (30 bytes)

void FUN_fffc18e1(void)

{
  memtune_backup_b();
  PTR_DAT_00025d54[0x440] = 1;
  PTR_DAT_00025d54[0x442] = 1;
  return;
}


// ===== memtune_backup_a @ fffc18ff (20 bytes)

/* 0x9D09 -> 0x9DCE */

void memtune_backup_a(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_00009d09;
  puVar1 = &DAT_00009dce;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== memtune_backup_b @ fffc1913 (20 bytes)

/* 0x9D63 -> 0x9E28 */

void memtune_backup_b(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_00009d63;
  puVar1 = &DAT_00009e28;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== bandstack_save @ fffc1927 (230 bytes)

/* Record -> band-stack slot 0x4761/0x5409 + level*0x438 + band*0x5A, EEPROM if changed */

void bandstack_save(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  bool local_13;
  byte bStack_12;
  byte bStack_11;
  undefined4 *puStack_c;
  undefined1 *puStack_4;
  
  local_13 = DAT_00009dbd == '\0';
  if (local_13) {
    uVar1 = vfo_freq(0,0);
    DAT_00009dc3 = band_of_freq(uVar1);
    puStack_4 = &DAT_00009d09;
    bStack_12 = (&DAT_000060b1)[DAT_00009dc3];
    puStack_c = &DAT_00004761 + (uint)bStack_12 * 0x10e;
    bStack_11 = DAT_00009dc3;
  }
  else {
    uVar1 = vfo_freq(0,1);
    DAT_00009dc4 = band_of_freq(uVar1);
    puStack_4 = &DAT_00009d63;
    bStack_12 = (&DAT_000060bd)[DAT_00009dc4];
    puStack_c = (undefined4 *)(&DAT_00005409 + (uint)bStack_12 * 0x438);
    bStack_11 = DAT_00009dc4;
  }
  local_13 = !local_13;
  puVar2 = (undefined1 *)((uint)bStack_11 * 0x5a + (int)puStack_c);
  iVar3 = FUN_fffede1d(puVar2,puStack_4,0x5a);
  if (iVar3 == 0) {
    return;
  }
  puVar4 = puVar2;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puStack_4;
    puVar4 = puVar4 + 1;
    puStack_4 = puStack_4 + 1;
  }
  eeprom_save_bandstack(local_13,bStack_11,bStack_12,puVar2);
  return;
}


// ===== FUN_fffc1a0d @ fffc1a0d (40 bytes)

void FUN_fffc1a0d(void)

{
  DAT_00009dce = DAT_00009d09;
  DAT_00009e18 = DAT_00009d53;
  PTR_DAT_00025d54[0x43f] = 1;
  return;
}


// ===== FUN_fffc1a35 @ fffc1a35 (42 bytes)

void FUN_fffc1a35(void)

{
  DAT_00009e28 = DAT_00009d63;
  DAT_00009e72 = DAT_00009dad;
  PTR_DAT_00025d54[0x43f] = 1;
  return;
}


// ===== band_select_pms @ fffc1a5f (73 bytes)

/* Band key in PMS state */

void band_select_pms(char param_1,undefined1 param_2)

{
  if (param_1 == '\0') {
    if (DAT_00009dbe == '\x04') {
      DAT_00009dbe = '\x01';
    }
  }
  else if (DAT_00009dbf == '\x04') {
    DAT_00009dbf = '\x01';
  }
  band_select_mem(param_1,param_2);
  return;
}


// ===== band_select_mem @ fffc1aa8 (39 bytes)

/* Band key in memory state */

void band_select_mem(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = memch_current_is_special(param_1);
  if (iVar1 != 0) {
    return;
  }
  vfo_clear_tag(param_1);
  vfo_enter_vfo_state(param_1);
  FUN_fffc18bf();
  band_select_stack(param_1,param_2);
  return;
}


// ===== band_select_memtune @ fffc1acf (23 bytes)

/* Band key in memory-tune state */

void band_select_memtune(undefined1 param_1,undefined1 param_2)

{
  vfo_enter_vfo_state(param_1);
  FUN_fffc18bf();
  band_select_stack(param_1,param_2);
  return;
}


// ===== band_select_vfo @ fffc1ae6 (73 bytes)

/* Band key in VFO/QMB state */

void band_select_vfo(char param_1,undefined1 param_2)

{
  if (param_1 == '\0') {
    if (DAT_00009dbe == '\x05') {
      DAT_00009dbe = '\x01';
    }
  }
  else if (DAT_00009dbf == '\x05') {
    DAT_00009dbf = '\x01';
  }
  band_select_stack(param_1,param_2);
  return;
}


// ===== band_select_stack @ fffc1b2f (213 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc1bcf) */
/* WARNING: Removing unreachable block (ram,0xfffc1b7d) */
/* (side, band): same band steps stack level mod 3 (if 0x9AC1), then vfo_reload */

void band_select_stack(char param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  byte local_3;
  
  if (param_1 == '\0') {
    bVar1 = param_2;
    bVar2 = DAT_00009dc4;
    if (DAT_00009dc3 == param_2) {
      local_3 = (&DAT_000060b1)[DAT_00009dc3];
      if (DAT_00009ac1 != '\0') {
        local_3 = (char)(local_3 + 1) + (char)((local_3 + 1) / 3) * -3;
      }
      (&DAT_000060b1)[DAT_00009dc3] = local_3;
      bVar1 = DAT_00009dc3;
      bVar2 = DAT_00009dc4;
    }
  }
  else {
    bVar1 = DAT_00009dc3;
    bVar2 = param_2;
    if (DAT_00009dc4 == param_2) {
      local_3 = (&DAT_000060bd)[DAT_00009dc4];
      if (DAT_00009ac1 != '\0') {
        local_3 = (char)(local_3 + 1) + (char)((local_3 + 1) / 3) * -3;
      }
      (&DAT_000060bd)[DAT_00009dc4] = local_3;
      bVar1 = DAT_00009dc3;
      bVar2 = DAT_00009dc4;
    }
  }
  DAT_00009dc4 = bVar2;
  DAT_00009dc3 = bVar1;
  vfo_reload(DAT_00009dbd);
  PTR_DAT_00025d54[0x40b] = 1;
  return;
}


// ===== vfo_reload @ fffc1c04 (186 bytes)

/* Reload operating record by state (band stack / memory / memory tune) */

void vfo_reload(int param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if (PTR_DAT_00025d54[0x43d] == '\x01') {
      vfo_reload_bandstack(0);
      return;
    }
    if ((DAT_00009dbe == '\x03') || (DAT_00009dbe == '\x04')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if (DAT_00009dbe == '\x02') {
        vfo_reload_memory(0);
        return;
      }
      vfo_reload_bandstack(0);
      return;
    }
    FUN_fffc1d95();
    return;
  }
  if (PTR_DAT_00025d54[0x43e] == '\x01') {
    vfo_reload_bandstack(1);
    return;
  }
  if ((DAT_00009dbf == '\x03') || (DAT_00009dbf == '\x04')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00009dbf == '\x02') {
      vfo_reload_memory(1);
      return;
    }
    vfo_reload_bandstack(1);
    return;
  }
  FUN_fffc1dca();
  return;
}


// ===== vfo_reload_bandstack @ fffc1cbe (27 bytes)

/* bandstack_load + vfo_retune, split off */

void vfo_reload_bandstack(undefined1 param_1)

{
  bandstack_load(param_1);
  vfo_retune(param_1);
  DAT_00009c5e = 0;
  return;
}


// ===== bandstack_load @ fffc1cd9 (188 bytes)

/* Band-stack slot -> operating record (QMB slot in state 5) */

void bandstack_load(uint param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  int iVar4;
  
  if (param_1 == 0) {
    if (DAT_00009dbe != '\x05') {
      puVar1 = &DAT_00009d09;
      puVar2 = (undefined1 *)
               ((int)&DAT_00004761 +
               (uint)DAT_00009dc3 * 0x5a + (uint)(byte)(&DAT_000060b1)[DAT_00009dc3] * 0x438);
      for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar1 = *puVar2;
        puVar1 = puVar1 + 1;
        puVar2 = puVar2 + 1;
      }
      return;
    }
    FUN_fffc31a7(0,1);
    FUN_fffc334c(0);
    return;
  }
  if (DAT_00009dbf != '\x05') {
    puVar1 = &DAT_00009d63;
    puVar3 = &DAT_00005409 +
             (uint)DAT_00009dc4 * 0x5a + (uint)(byte)(&DAT_000060bd)[DAT_00009dc4] * 0x438;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar1 = *puVar3;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  FUN_fffc31a7(param_1 & 0xff,1);
  FUN_fffc334c(param_1 & 0xff);
  return;
}


// ===== FUN_fffc1d95 @ fffc1d95 (49 bytes)

void FUN_fffc1d95(void)

{
  if (PTR_DAT_00025d54[0x43f] == '\0') {
    vfo_reload_memory(0);
    return;
  }
  if (PTR_DAT_00025d54[0x441] != '\x01') {
    memch_load_to_vfo(0);
    FUN_fffc1e37();
    return;
  }
  FUN_fffc1dc6();
  return;
}


// ===== FUN_fffc1dc6 @ fffc1dc6 (4 bytes)

void FUN_fffc1dc6(void)

{
  memtune_restore_a();
  return;
}


// ===== FUN_fffc1dca @ fffc1dca (49 bytes)

void FUN_fffc1dca(void)

{
  if (PTR_DAT_00025d54[0x440] == '\0') {
    vfo_reload_memory(1);
    return;
  }
  if (PTR_DAT_00025d54[0x442] != '\x01') {
    memch_load_to_vfo(1);
    FUN_fffc1e52();
    return;
  }
  FUN_fffc1dfb();
  return;
}


// ===== FUN_fffc1dfb @ fffc1dfb (4 bytes)

void FUN_fffc1dfb(void)

{
  memtune_restore_b();
  return;
}


// ===== vfo_reload_memory @ fffc1dff (16 bytes)

/* memch_load_to_vfo + vfo_retune */

void vfo_reload_memory(undefined1 param_1)

{
  memch_load_to_vfo(param_1);
  vfo_retune(param_1);
  return;
}


// ===== memtune_restore_a @ fffc1e0f (20 bytes)

/* 0x9DCE -> 0x9D09 */

void memtune_restore_a(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_00009dce;
  puVar1 = &DAT_00009d09;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== memtune_restore_b @ fffc1e23 (20 bytes)

/* 0x9E28 -> 0x9D63 */

void memtune_restore_b(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_00009e28;
  puVar1 = &DAT_00009d63;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== FUN_fffc1e37 @ fffc1e37 (27 bytes)

void FUN_fffc1e37(void)

{
  DAT_00009d09 = DAT_00009dce;
  DAT_00009d53 = DAT_00009e18;
  return;
}


// ===== FUN_fffc1e52 @ fffc1e52 (29 bytes)

void FUN_fffc1e52(void)

{
  DAT_00009d63 = DAT_00009e28;
  DAT_00009dad = DAT_00009e72;
  return;
}


// ===== FUN_fffc1e6f @ fffc1e6f (111 bytes)

void FUN_fffc1e6f(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (PTR_DAT_00025d54[0x405] != '\x01') {
    return;
  }
  PTR_DAT_00025d54[0x405] = 0;
  puVar2 = &DAT_00009d09;
  puVar1 = &DAT_0001216d;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00009d63;
  puVar1 = &DAT_00009d09;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar1 = &DAT_00009d63;
  puVar2 = &DAT_0001216d;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  PTR_DAT_00025d54[0x40b] = 1;
  beep_request(1);
  return;
}

