// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== freq_fix_below @ fffc130b (109 bytes)

/* Below-limit handling (clamp, or wrap while scanning) */

void freq_fix_below(void *param_1,void *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return;
  }
  if (PTR_DAT_00025d54[0x46a] != '\x01') {
    if (PTR_DAT_00025d54[0x418] != '\x01') {
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
      return;
    }
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
    return;
  }
  FUN_fffc142c(param_1,param_2);
  return;
}


// ===== freq_fix_above @ fffc1378 (111 bytes)

/* Above-limit handling (clamp, or wrap while scanning) */

void freq_fix_above(void *param_1,void *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
    return;
  }
  if (PTR_DAT_00025d54[0x46a] != '\x01') {
    if (PTR_DAT_00025d54[0x418] != '\x01') {
      *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
      return;
    }
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
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

void FUN_fffc1625(byte param_1)

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
    band_select_vfo(local_2,param_1);
    return;
  }
  band_select_mem(local_2,param_1);
  return;
}


// ===== vfo_store_back @ fffc16f6 (233 bytes)

/* Store operating record back (band stack / memory-tune backup) according to state */

void vfo_store_back(byte param_1)

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
  smovf(0x9dce,0x9d09,0x5a);
  return;
}


// ===== memtune_backup_b @ fffc1913 (20 bytes)

/* 0x9D63 -> 0x9E28 */

void memtune_backup_b(void)

{
  smovf(0x9e28,0x9d63,0x5a);
  return;
}


// ===== bandstack_save @ fffc1927 (230 bytes)

/* Record -> band-stack slot 0x4761/0x5409 + level*0x438 + band*0x5A, EEPROM if changed */

void bandstack_save(void)

{
  uint uVar1;
  int iVar2;
  bool local_13;
  byte bStack_12;
  byte bStack_11;
  undefined *puStack_c;
  undefined1 *puStack_4;
  
  local_13 = DAT_00009dbd == '\0';
  if (local_13) {
    uVar1 = vfo_freq(0,0);
    DAT_00009dc3 = band_of_freq(uVar1);
    puStack_4 = &DAT_00009d09;
    bStack_12 = (&DAT_000060b1)[DAT_00009dc3];
    puStack_c = &DAT_00004761 + (uint)bStack_12 * 0x438;
    bStack_11 = DAT_00009dc3;
  }
  else {
    uVar1 = vfo_freq(0,1);
    DAT_00009dc4 = band_of_freq(uVar1);
    puStack_4 = &DAT_00009d63;
    bStack_12 = (&DAT_000060bd)[DAT_00009dc4];
    puStack_c = &DAT_00005409 + (uint)bStack_12 * 0x438;
    bStack_11 = DAT_00009dc4;
  }
  local_13 = !local_13;
  puStack_c = puStack_c + (uint)bStack_11 * 0x5a;
  iVar2 = FUN_fffede1d(puStack_c,puStack_4,0x5a);
  if (iVar2 == 0) {
    return;
  }
  smovf(puStack_c,puStack_4,0x5a);
  eeprom_save_bandstack(local_13,bStack_11,bStack_12,(uint)puStack_c);
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

void band_select_pms(char param_1,byte param_2)

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

void band_select_mem(byte param_1,byte param_2)

{
  byte bVar1;
  
  bVar1 = memch_current_is_special(param_1);
  if (bVar1 != 0) {
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

void band_select_memtune(byte param_1,byte param_2)

{
  vfo_enter_vfo_state(param_1);
  FUN_fffc18bf();
  band_select_stack(param_1,param_2);
  return;
}


// ===== band_select_vfo @ fffc1ae6 (73 bytes)

/* Band key in VFO/QMB state */

void band_select_vfo(char param_1,byte param_2)

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

void vfo_reload(byte param_1)

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

void vfo_reload_bandstack(byte param_1)

{
  bandstack_load(param_1);
  vfo_retune(param_1);
  DAT_00009c5e = 0;
  return;
}


// ===== bandstack_load @ fffc1cd9 (188 bytes)

/* Band-stack slot -> operating record (QMB slot in state 5) */

void bandstack_load(byte param_1)

{
  if (param_1 == 0) {
    if (DAT_00009dbe != '\x05') {
      smovf(0x9d09,&DAT_00004761 +
                   (uint)DAT_00009dc3 * 0x5a + (uint)(byte)(&DAT_000060b1)[DAT_00009dc3] * 0x438,
            0x5a);
      return;
    }
    FUN_fffc31a7(0,1);
    FUN_fffc334c(0);
    return;
  }
  if (DAT_00009dbf != '\x05') {
    smovf(0x9d63,&DAT_00005409 +
                 (uint)DAT_00009dc4 * 0x5a + (uint)(byte)(&DAT_000060bd)[DAT_00009dc4] * 0x438,0x5a)
    ;
    return;
  }
  FUN_fffc31a7(param_1,1);
  FUN_fffc334c(param_1);
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
    memch_load_to_vfo('\0');
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
    memch_load_to_vfo('\x01');
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

void vfo_reload_memory(byte param_1)

{
  memch_load_to_vfo(param_1);
  vfo_retune(param_1);
  return;
}


// ===== memtune_restore_a @ fffc1e0f (20 bytes)

/* 0x9DCE -> 0x9D09 */

void memtune_restore_a(void)

{
  smovf(0x9d09,0x9dce,0x5a);
  return;
}


// ===== memtune_restore_b @ fffc1e23 (20 bytes)

/* 0x9E28 -> 0x9D63 */

void memtune_restore_b(void)

{
  smovf(0x9d63,0x9e28,0x5a);
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
  if (PTR_DAT_00025d54[0x405] != '\x01') {
    return;
  }
  PTR_DAT_00025d54[0x405] = 0;
  smovf(0x1216d,0x9d09,0x5a);
  smovf(0x9d09,0x9d63,0x5a);
  smovf(0x9d63,0x1216d,0x5a);
  PTR_DAT_00025d54[0x40b] = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc1ede @ fffc1ede (76 bytes)

void FUN_fffc1ede(short param_1)

{
  ushort local_4;
  
  local_4 = param_1 - 0xd0;
  if (0x23 < local_4) {
    local_4 = 0;
  }
  if (" 001 [GN] VDD MTR         002 [GN] FAN             003 [GN] REF FREQ        004 [GN] TX INH          005 [GN] --RESERVED--    006 [GN] --RESERVED--    007 [GN] --RESERVED--    008 [GN] DBG MODE ENABLE 009 [MT] PO MTR 100W POS 010 [MT] PO MTR  50W POS 011 [MT] PO MTR  20W POS 012 [MT] PO MTR  10W POS 013 [MT] PO MTR   5W POS 014 [MT] ALC MTR POS     015 [MT] VDD MTR POS     016 [MT] IDD MTR POS     017 [MT] SWR 1.5 MTR POS 018 [MT] SWR 2.0 MTR POS 019 [MT] SWR 3.0 MTR POS 020 [MT] --RESERVED--    021 [MT] --RESERVED--    022 [MT] --RESERVED--    023 [RX] RF-AGC  7       024 [RX] RF-AGC 14       025 [RX] RF-AGC 21       026 [RX] RF-AGC 28       027 [RX] RF-AGC 50       028 [RX] IF-AGC  7       029 [RX] IF-AGC 14       030 [RX] IF-AGC 21       031 [RX] IF-AGC 28       032 [RX] IF-AGC 50       033 [RX] S-MTR 0         034 [RX] S-MTR 2         035 [RX] S-MTR 5         036 [RX] S-MTR 7         037 [RX] S-MTR 9         038 [RX] S-MTR +10       039 [RX] S-MTR +20       040 [RX] S-MTR +30       041 [RX] S-MTR +40       042 [RX] S-MTR +50       043 [RX] S-MTR +60       044 [RX] --RESERVED--    045 [RX] --RESERVED--    046 [RX] FM SQL THW      047 [RX] FM SQL THN      048 [RX] FM SQL TI       049 [RX] SCOPE SDR REF   050 [TX] MF PREDR BIAS   051 [TX] MF DRIVE BIAS   052 [TX] MF FINAL BIAS   053 [TX] HF PREDR BIAS   054 [TX] HF DRIVE BIAS   055 [TX] HF FINAL BIAS   056 [TX] VHF PREDR BIAS  057 [TX] VHF DRIVE BIAS  058 [TX] VHF FINAL BIAS  059 [TX] I-ALC 1.8       060 [TX] I-ALC 3.5       061 [TX] I-ALC 7         062 [TX] I-ALC 10        063 [TX] I-ALC 14        064 [TX] I-ALC 18        065 [TX] I-ALC 21        066 [TX] I-ALC 24        067 [TX] I-ALC 28        068 [TX] I-ALC 50        069 [TX] I-ALC 70        070 [TX] 100W FALC 1.8   071 [TX] 100W MTR  1.8   072 [TX] 100W TXG  1.8   073 [TX]  50W FALC 1.8   074 [TX]  50W MTR  1.8   075 [TX]  50W TXG  1.8   076 [TX]  20W FALC 1.8   077 [TX]  20W MTR  1.8   078 [TX]  20W TXG  1.8   079 [TX]  10W FALC 1.8   080 [TX]  10W MTR  1.8   081 [TX]  10W TXG  1.8   082 [TX]   5W FALC 1.8..." /* TRUNCATED STRING LITERAL */
      [local_4 + 0x197d] != -1) {
    DAT_00009c08 = " 001 [GN] VDD MTR         002 [GN] FAN             003 [GN] REF FREQ        004 [GN] TX INH          005 [GN] --RESERVED--    006 [GN] --RESERVED--    007 [GN] --RESERVED--    008 [GN] DBG MODE ENABLE 009 [MT] PO MTR 100W POS 010 [MT] PO MTR  50W POS 011 [MT] PO MTR  20W POS 012 [MT] PO MTR  10W POS 013 [MT] PO MTR   5W POS 014 [MT] ALC MTR POS     015 [MT] VDD MTR POS     016 [MT] IDD MTR POS     017 [MT] SWR 1.5 MTR POS 018 [MT] SWR 2.0 MTR POS 019 [MT] SWR 3.0 MTR POS 020 [MT] --RESERVED--    021 [MT] --RESERVED--    022 [MT] --RESERVED--    023 [RX] RF-AGC  7       024 [RX] RF-AGC 14       025 [RX] RF-AGC 21       026 [RX] RF-AGC 28       027 [RX] RF-AGC 50       028 [RX] IF-AGC  7       029 [RX] IF-AGC 14       030 [RX] IF-AGC 21       031 [RX] IF-AGC 28       032 [RX] IF-AGC 50       033 [RX] S-MTR 0         034 [RX] S-MTR 2         035 [RX] S-MTR 5         036 [RX] S-MTR 7         037 [RX] S-MTR 9         038 [RX] S-MTR +10       039 [RX] S-MTR +20       040 [RX] S-MTR +30       041 [RX] S-MTR +40       042 [RX] S-MTR +50       043 [RX] S-MTR +60       044 [RX] --RESERVED--    045 [RX] --RESERVED--    046 [RX] FM SQL THW      047 [RX] FM SQL THN      048 [RX] FM SQL TI       049 [RX] SCOPE SDR REF   050 [TX] MF PREDR BIAS   051 [TX] MF DRIVE BIAS   052 [TX] MF FINAL BIAS   053 [TX] HF PREDR BIAS   054 [TX] HF DRIVE BIAS   055 [TX] HF FINAL BIAS   056 [TX] VHF PREDR BIAS  057 [TX] VHF DRIVE BIAS  058 [TX] VHF FINAL BIAS  059 [TX] I-ALC 1.8       060 [TX] I-ALC 3.5       061 [TX] I-ALC 7         062 [TX] I-ALC 10        063 [TX] I-ALC 14        064 [TX] I-ALC 18        065 [TX] I-ALC 21        066 [TX] I-ALC 24        067 [TX] I-ALC 28        068 [TX] I-ALC 50        069 [TX] I-ALC 70        070 [TX] 100W FALC 1.8   071 [TX] 100W MTR  1.8   072 [TX] 100W TXG  1.8   073 [TX]  50W FALC 1.8   074 [TX]  50W MTR  1.8   075 [TX]  50W TXG  1.8   076 [TX]  20W FALC 1.8   077 [TX]  20W MTR  1.8   078 [TX]  20W TXG  1.8   079 [TX]  10W FALC 1.8   080 [TX]  10W MTR  1.8   081 [TX]  10W TXG  1.8   082 [TX]   5W FALC 1.8..." /* TRUNCATED STRING LITERAL */
                   [local_4 + 0x197d];
    FUN_fffc3b22(DAT_00009c08);
    return;
  }
  return;
}


// ===== FUN_fffc1f2a @ fffc1f2a (106 bytes)

void FUN_fffc1f2a(char param_1)

{
  PTR_DAT_00025d54[0x41f] = param_1;
  FUN_fffc98b3();
  PTR_DAT_00025d54[0x95] = 1;
  if (PTR_DAT_00025d54[0x3ff] == '\x03') {
    PTR_DAT_00025d54[0x3ff] = 2;
  }
  FUN_fffc3c85();
  if (param_1 != '\x05') {
    beep_request(1);
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffc1f94 @ fffc1f94 (34 bytes)

void FUN_fffc1f94(void)

{
  FUN_fffc3c85();
  if (DAT_0001b4da == '\0') {
    beep_request(1);
  }
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffc1fb6 @ fffc1fb6 (295 bytes)

void FUN_fffc1fb6(byte param_1)

{
  uint uVar1;
  bool bVar2;
  
  if (PTR_DAT_00025d54[0x97] != '\0') {
    PTR_DAT_00025d54[0x43c] = 0;
    uVar1 = (uint)param_1;
    if (uVar1 == 9) {
      if (PTR_DAT_00025d54[0x1d9] == '\x01') {
        PTR_DAT_00025d54[0x1da] = param_1 - 4;
        FUN_fffc20dd();
        return;
      }
      FUN_fffc2794();
      beep_request(1);
      return;
    }
    if (uVar1 - 4 < 4) {
      if (param_1 != 4) {
        PTR_DAT_00025d54[0x43c] = 1;
      }
      if ((PTR_DAT_00025d54[0x1d9] == '\x01') && (PTR_DAT_00025d54[0x43b] == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        PTR_DAT_00025d54[0x43b] = 0;
        beep_request(1);
        return;
      }
      PTR_DAT_00025d54[0x1da] = param_1 - 4;
      if (PTR_DAT_00025d54[0x1d9] == '\0') {
        FUN_fffc2b12();
      }
      FUN_fffc20dd();
      return;
    }
    if (uVar1 == 8) {
      FUN_fffc22de();
      eeprom_save_memch(PTR_DAT_00025d54[0x43a]);
      return;
    }
    if (uVar1 < 4) {
      PTR_DAT_00025d54[0x1db] = param_1;
      PTR_DAT_00025d54[0x1d9] = 0;
      PTR_DAT_00025d54[0x43b] = 0;
      FUN_fffc2b12();
      beep_request(1);
      return;
    }
  }
  return;
}


// ===== FUN_fffc20dd @ fffc20dd (90 bytes)

void FUN_fffc20dd(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d54[0x1da];
  if (cVar1 == '\x05') {
    PTR_DAT_00025d54[0x1d9] = 0;
    PTR_DAT_00025d54[0x409] = 1;
    beep_request(1);
    return;
  }
  if (cVar1 == '\x01') {
    FUN_fffc21e8();
    return;
  }
  if (cVar1 == '\x02') {
    FUN_fffc224e();
    return;
  }
  if (cVar1 == '\x03') {
    FUN_fffc2296();
    return;
  }
  if (cVar1 == '\x04') {
    FUN_fffc22de();
    return;
  }
  if (cVar1 != '\0') {
    return;
  }
  FUN_fffc2137();
  return;
}


// ===== FUN_fffc2137 @ fffc2137 (144 bytes)

void FUN_fffc2137(void)

{
  undefined *puVar1;
  bool bVar2;
  int iVar3;
  byte *pbStack_4;
  
  bVar2 = memch_valid(PTR_DAT_00025d54[0x43a],&pbStack_4);
  if (bVar2) {
    PTR_DAT_00025d54[0x90] = 1;
    PTR_DAT_00025d54[0xbe] = 1;
    PTR_DAT_00025d54[0xc1] = 0;
    puVar1 = PTR_DAT_00025d54;
    sstr(PTR_DAT_00025d54 + 0xc2,0x20,0x32);
    iVar3 = (uint)(byte)PTR_DAT_00025d54[0x43a] * 0x5a;
    *(undefined4 *)(PTR_DAT_00025d54 + 0xca) = *(undefined4 *)(&DAT_000061a6 + iVar3);
    *(undefined4 *)(puVar1 + 0xc6) = *(undefined4 *)(&DAT_000061a2 + iVar3);
    *(undefined4 *)(puVar1 + 0xc2) = *(undefined4 *)(&DAT_0000619e + iVar3);
    beep_request(1);
    return;
  }
  FUN_fffc21c7();
  return;
}


// ===== FUN_fffc21c7 @ fffc21c7 (33 bytes)

void FUN_fffc21c7(void)

{
  PTR_DAT_00025d54[0x43c] = 0;
  PTR_DAT_00025d54[0x409] = 1;
  beep_request(3);
  return;
}


// ===== FUN_fffc21e8 @ fffc21e8 (102 bytes)

void FUN_fffc21e8(void)

{
  bool bVar1;
  byte *pbStack_4;
  
  if (((byte)PTR_DAT_00025d54[0x43a] < 0x75) &&
     (bVar1 = memch_valid(PTR_DAT_00025d54[0x43a],&pbStack_4), bVar1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_fffc21c7();
    return;
  }
  PTR_DAT_00025d54[0x43b] = 1;
  PTR_DAT_00025d54[0x1c2] = 0x55;
  FUN_fffc8cbb(0x55);
  FUN_fffc8d8c();
  beep_request(1);
  return;
}


// ===== FUN_fffc224e @ fffc224e (72 bytes)

void FUN_fffc224e(void)

{
  bool bVar1;
  byte *pbStack_4;
  
  bVar1 = memch_valid(PTR_DAT_00025d54[0x43a],&pbStack_4);
  if (bVar1) {
    PTR_DAT_00025d54[0x43b] = 1;
    PTR_DAT_00025d54[0x1c2] = 0x44;
    FUN_fffc8cbb(0x44);
    FUN_fffc8d8c();
    beep_request(1);
    return;
  }
  FUN_fffc21c7();
  return;
}


// ===== FUN_fffc2296 @ fffc2296 (72 bytes)

void FUN_fffc2296(void)

{
  bool bVar1;
  byte *pbStack_4;
  
  bVar1 = memch_valid(PTR_DAT_00025d54[0x43a],&pbStack_4);
  if (bVar1) {
    PTR_DAT_00025d54[0x43b] = 1;
    PTR_DAT_00025d54[0x1c2] = 0x45;
    FUN_fffc8cbb(0x45);
    FUN_fffc8d8c();
    beep_request(1);
    return;
  }
  FUN_fffc21c7();
  return;
}

