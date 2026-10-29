// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  int iVar4;
  
  if (param_1 == 0) {
    if (DAT_00009dbe != '\x05') {
      puVar1 = &DAT_00009d09;
      puVar2 = &DAT_00004761 +
               (uint)DAT_00009dc3 * 0x5a + (uint)(byte)(&DAT_000060b1)[DAT_00009dc3] * 0x438;
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
  undefined1 *puVar3;
  int iVar4;
  byte *pbStack_4;
  
  bVar2 = memch_valid(PTR_DAT_00025d54[0x43a],&pbStack_4);
  if (bVar2) {
    PTR_DAT_00025d54[0x90] = 1;
    PTR_DAT_00025d54[0xbe] = 1;
    PTR_DAT_00025d54[0xc1] = 0;
    puVar3 = PTR_DAT_00025d54 + 0xc2;
    for (iVar4 = 0x32; puVar1 = PTR_DAT_00025d54, iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0x20;
      puVar3 = puVar3 + 1;
    }
    iVar4 = (uint)(byte)PTR_DAT_00025d54[0x43a] * 0x5a;
    *(undefined4 *)(PTR_DAT_00025d54 + 0xca) = *(undefined4 *)(&DAT_000061a6 + iVar4);
    *(undefined4 *)(puVar1 + 0xc6) = *(undefined4 *)(&DAT_000061a2 + iVar4);
    *(undefined4 *)(puVar1 + 0xc2) = *(undefined4 *)(&DAT_0000619e + iVar4);
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


// ===== FUN_fffc22de @ fffc22de (120 bytes)

void FUN_fffc22de(void)

{
  bool bVar1;
  byte *local_4;
  
  if (((byte)PTR_DAT_00025d54[0x43a] < 0x75) && (PTR_DAT_00025d54[0x43a] != '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    *local_4 = (byte)(1 << ((byte)PTR_DAT_00025d54[0x43a] & 7)) | *local_4;
    bVar1 = memch_valid(PTR_DAT_00025d54[0x43a],&local_4);
    if (bVar1) {
      *local_4 = 0;
    }
    else {
      *local_4 = 1;
    }
    beep_request(1);
    return;
  }
  FUN_fffc21c7();
  return;
}


// ===== FUN_fffc2356 @ fffc2356 (27 bytes)

void FUN_fffc2356(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = FUN_fffcd999(param_1);
  if (cVar1 != '\x01') {
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffc2371 @ fffc2371 (27 bytes)

void FUN_fffc2371(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = FUN_fffcda51(param_1);
  if (cVar1 != '\x01') {
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffc238c @ fffc238c (24 bytes)

void FUN_fffc238c(undefined1 param_1)

{
  PTR_DAT_00025d54[0x3ff] = param_1;
  beep_request(1);
  return;
}


// ===== FUN_fffc23a4 @ fffc23a4 (18 bytes)

void FUN_fffc23a4(void)

{
  PTR_DAT_00025d54[0x409] = 1;
  FUN_fffd1712();
  return;
}


// ===== FUN_fffc23b6 @ fffc23b6 (77 bytes)

void FUN_fffc23b6(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\b')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
  }
  PTR_DAT_00025d54[0x40d] = 0;
  PTR_DAT_00025d54[0x414] = 0;
  return;
}


// ===== FUN_fffc2403 @ fffc2403 (35 bytes)

void FUN_fffc2403(void)

{
  if (PTR_DAT_00025d54[0x407] != '\x01') {
    return;
  }
  PTR_DAT_00025d54[0x407] = 0;
  beep_stop();
  return;
}


// ===== FUN_fffc2426 @ fffc2426 (486 bytes)

undefined1 FUN_fffc2426(void)

{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  ushort uVar4;
  byte local_4;
  
  bVar1 = DAT_00009dbd != '\0';
  if (PTR_DAT_00025d54[0x97] == '\x01') {
    FUN_fffc2cdf(bVar1,PTR_DAT_00025d54[0x43a]);
    local_4 = PTR_DAT_00025d54[0x43a];
    if (DAT_00009c5e == '\x01') {
      DAT_00009c5e = '\0';
      DAT_00009dbe = '\x01';
      DAT_00009dbf = '\x01';
      PTR_DAT_00025d54[0x483] = 0;
      DAT_00020f09 = 0;
      PTR_DAT_00025d54[0x443] = 1;
      PTR_DAT_00025d54[0x445] = 1;
      PTR_DAT_00025d54[0x40c] = 1;
    }
  }
  else {
    if (DAT_00009c5e == '\x01') {
      DAT_00009c5e = 0;
      DAT_00009dbe = PTR_DAT_00025d54[0x484];
      DAT_00009dbf = PTR_DAT_00025d54[0x485];
      PTR_DAT_00025d54[0x483] = 0;
      DAT_00020f09 = 0;
      PTR_DAT_00025d54[0x443] = 1;
      PTR_DAT_00025d54[0x445] = 1;
      PTR_DAT_00025d54[0x40c] = 1;
      return 1;
    }
    if (bVar1) {
      if (DAT_00009dbf == '\x05') {
        DAT_00009dbf = 1;
        vfo_reload(1);
        return 1;
      }
    }
    else if (DAT_00009dbe == '\x05') {
      DAT_00009dbe = 1;
      vfo_reload(0);
      return 1;
    }
    if (bVar1) {
      local_4 = DAT_000060ca;
    }
    else {
      local_4 = DAT_000060c9;
    }
  }
  uVar4 = dest_code_get();
  if (uVar4 == 0x315b) {
    if ((local_4 < 0x75) || (0x83 < local_4)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      return 0;
    }
  }
  uVar3 = FUN_fffc260c(bVar1);
  return uVar3;
}


// ===== FUN_fffc260c @ fffc260c (117 bytes)

undefined1 FUN_fffc260c(byte param_1)

{
  byte bVar1;
  undefined1 uStack_3;
  
  bVar1 = memch_current_valid(param_1);
  if (bVar1 == 0) {
    uStack_3 = 0;
  }
  else {
    if (DAT_00009dbe == '\x05') {
      DAT_00009dbe = '\x01';
    }
    if (DAT_00009dbf == '\x05') {
      DAT_00009dbf = '\x01';
    }
    qmb_set_depth(param_1);
    memch_load_to_vfo(param_1);
    vfo_clear_tag(param_1);
    vfo_enter_vfo_state(param_1);
    FUN_fffc18bf();
    FUN_fffc2794();
    PTR_DAT_00025d54[0x40b] = 1;
    uStack_3 = 1;
  }
  return uStack_3;
}


// ===== memch_load_to_vfo @ fffc2681 (189 bytes)

/* 0x6150+ch*0x5A -> operating record, clar cleared */

void memch_load_to_vfo(char param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  bVar1 = memch_current_valid(param_1);
  if (bVar1 == 0) {
    return;
  }
  bVar1 = memch_current(param_1);
  if (param_1 == '\0') {
    puVar3 = &DAT_00006150 + (uint)bVar1 * 0x5a;
    puVar2 = &DAT_00009d09;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    puVar3 = &DAT_00006150 + (uint)bVar1 * 0x5a;
    puVar2 = &DAT_00009d63;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  if (param_1 == '\0') {
    PTR_DAT_00025d54[0x425] = 0;
    DAT_00009d0a = DAT_00009d0a & 0xe7;
    DAT_00009d51 = 0;
    DAT_00009d52 = 0;
    return;
  }
  PTR_DAT_00025d54[0x426] = 0;
  DAT_00009d64 = DAT_00009d64 & 0xe7;
  DAT_00009dab = 0;
  DAT_00009dac = 0;
  return;
}


// ===== vfo_clear_tag @ fffc273e (86 bytes)

/* Blank tag (+0x4E) and tag flag (+5 bit7) of the operating record */

void vfo_clear_tag(byte param_1)

{
  if (param_1 != 0) {
    DAT_00009d68 = DAT_00009d68 & 0x7f;
    DAT_00009db9 = 0x20202020;
    DAT_00009db5 = 0x20202020;
    DAT_00009db1 = 0x20202020;
    return;
  }
  DAT_00009d0e = DAT_00009d0e & 0x7f;
  DAT_00009d5f = 0x20202020;
  DAT_00009d5b = 0x20202020;
  DAT_00009d57 = 0x20202020;
  return;
}


// ===== FUN_fffc2794 @ fffc2794 (25 bytes)

void FUN_fffc2794(void)

{
  PTR_DAT_00025d54[0x97] = 0;
  PTR_DAT_00025d54[0x90] = 0;
  return;
}


// ===== vm_toggle_core @ fffc27ad (318 bytes)

/* VFO <-> memory state change and reload */

void vm_toggle_core(void)

{
  bool bVar1;
  char cStack_2;
  byte bStack_1;
  
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (DAT_00009dbd == '\0') {
    bStack_1 = 0;
    cStack_2 = DAT_00009dbe;
    if (DAT_00009dbe != '\x05') {
      vfo_store_back(0);
    }
  }
  else {
    bStack_1 = 1;
    cStack_2 = DAT_00009dbf;
    if (DAT_00009dbf != '\x05') {
      vfo_store_back(1);
    }
  }
  if ((cStack_2 == '\x04') || (cStack_2 == '\x03')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc28eb(bStack_1);
  }
  else if (cStack_2 == '\x02') {
    FUN_fffc296f(bStack_1);
    if (bStack_1 == 0) {
      PTR_DAT_00025d54[0x425] = 0;
      DAT_00009d0a = DAT_00009d0a & 0xe7;
    }
    else {
      PTR_DAT_00025d54[0x426] = 0;
      DAT_00009d64 = DAT_00009d64 & 0xe7;
    }
  }
  else {
    if (DAT_00009c5e == '\x01') {
      DAT_00009c5e = 0;
      DAT_00009dbe = PTR_DAT_00025d54[0x484];
      DAT_00009dbf = PTR_DAT_00025d54[0x485];
      PTR_DAT_00025d54[0x483] = 0;
      DAT_00020f09 = 0;
      return;
    }
    FUN_fffc2991(bStack_1);
  }
  vfo_reload(bStack_1);
  PTR_DAT_00025d54[0x40b] = 1;
  return;
}


// ===== FUN_fffc28eb @ fffc28eb (16 bytes)

void FUN_fffc28eb(byte param_1)

{
  vfo_enter_mem_state(param_1);
  FUN_fffc2937(param_1);
  return;
}


// ===== vfo_enter_mem_state @ fffc28fb (60 bytes)

/* state = 2 */

void vfo_enter_mem_state(byte param_1)

{
  if (param_1 != 0) {
    DAT_00009dbf = 2;
    PTR_DAT_00025d54[0x43e] = 0;
    return;
  }
  DAT_00009dbe = 2;
  PTR_DAT_00025d54[0x43d] = 0;
  return;
}


// ===== FUN_fffc2937 @ fffc2937 (56 bytes)

void FUN_fffc2937(int param_1)

{
  if (param_1 != 0) {
    PTR_DAT_00025d54[0x440] = 0;
    PTR_DAT_00025d54[0x442] = 0;
    return;
  }
  PTR_DAT_00025d54[0x43f] = 0;
  PTR_DAT_00025d54[0x441] = 0;
  return;
}


// ===== FUN_fffc296f @ fffc296f (34 bytes)

void FUN_fffc296f(int param_1)

{
  if (param_1 != 0) {
    DAT_00009dbf = 1;
    return;
  }
  DAT_00009dbe = 1;
  return;
}


// ===== FUN_fffc2991 @ fffc2991 (98 bytes)

void FUN_fffc2991(uint param_1)

{
  if (param_1 == 0) {
    if (DAT_00009dbe != '\x05') {
      FUN_fffc2937(0);
      DAT_00009dbe = 2;
      return;
    }
    DAT_00009dbe = 1;
    return;
  }
  if (DAT_00009dbf != '\x05') {
    FUN_fffc2937(param_1 & 0xff);
    DAT_00009dbf = 2;
    return;
  }
  DAT_00009dbf = 1;
  return;
}


// ===== FUN_fffc29f3 @ fffc29f3 (74 bytes)

void FUN_fffc29f3(void)

{
  byte bVar1;
  
  PTR_DAT_00025d54[0x97] = 1;
  PTR_DAT_00025d54[0x1d9] = 0;
  PTR_DAT_00025d54[0x43b] = 0;
  bVar1 = memch_current(DAT_00009dbd != '\0');
  FUN_fffc2a3d(bVar1);
  return;
}


// ===== FUN_fffc2a3d @ fffc2a3d (213 bytes)

void FUN_fffc2a3d(byte param_1)

{
  ushort uVar1;
  char cStack_3;
  byte bStack_2;
  
  uVar1 = dest_code_get();
  if ((uVar1 != 0x20b) && (uVar1 != 0x1cb9)) {
    if (uVar1 == 0xd950) {
LAB_fffc2aa2:
      cStack_3 = '\0';
      bStack_2 = 0x78;
      goto LAB_fffc2ad2;
    }
    if (uVar1 != 0x4380) {
      if (uVar1 != 0x50e2) {
        if (uVar1 == 0x60e6) goto LAB_fffc2aaa;
        if (((uVar1 == 0xa4c5) || (uVar1 == 0xa983)) || (uVar1 == 0xb5a7)) goto LAB_fffc2aa2;
        if (uVar1 != 0x315b) {
          cStack_3 = '\0';
          bStack_2 = 0x71;
          goto LAB_fffc2ad2;
        }
      }
      cStack_3 = '\0';
      bStack_2 = 0x80;
      if (DAT_00009af4 == '\x01') {
        bStack_2 = 0x81;
      }
      goto LAB_fffc2ad2;
    }
  }
LAB_fffc2aaa:
  cStack_3 = '\0';
  bStack_2 = 0x71;
  if ((DAT_00009af4 == '\x01') && (param_1 == 0x84)) {
    bStack_2 = 0x81;
    cStack_3 = '\x0f';
  }
LAB_fffc2ad2:
  if (bStack_2 <= param_1) {
    PTR_DAT_00025d54[0x439] = bStack_2 - cStack_3;
    PTR_DAT_00025d54[0x1db] = param_1 - bStack_2;
    return;
  }
  PTR_DAT_00025d54[0x439] = param_1;
  PTR_DAT_00025d54[0x1db] = 0;
  return;
}


// ===== FUN_fffc2b12 @ fffc2b12 (28 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc2b2b) */

undefined4 FUN_fffc2b12(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_00025d54;
  uVar2 = FUN_fffc2b2e(PTR_DAT_00025d54[0x439],PTR_DAT_00025d54[0x1db]);
  puVar1[0x43a] = (char)uVar2;
  return uVar2;
}


// ===== FUN_fffc2b2e @ fffc2b2e (102 bytes)

byte FUN_fffc2b2e(char param_1,char param_2)

{
  bool bVar1;
  ushort uVar2;
  byte local_4;
  
  local_4 = param_1 + param_2;
  uVar2 = dest_code_get();
  if ((uVar2 == 0x4380) || (uVar2 == 0x20b)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (uVar2 == 0x60e6)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (uVar2 == 0x1cb9)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (0x74 < local_4)) {
    local_4 = 0x84;
  }
  return local_4;
}


// ===== FUN_fffc2b94 @ fffc2b94 (187 bytes)

void FUN_fffc2b94(void)

{
  bool bVar1;
  bool bStack_5;
  char *pcStack_4;
  
  bVar1 = memch_is_special(PTR_DAT_00025d54[0x43a]);
  if (bVar1) {
    FUN_fffc2c4f();
    return;
  }
  if (DAT_00009dbd == '\0') {
    pcStack_4 = &DAT_00009dbe;
  }
  else {
    pcStack_4 = &DAT_00009dbf;
  }
  bStack_5 = DAT_00009dbd != '\0';
  vfo_store_back(bStack_5);
  if (*pcStack_4 == '\x04') {
    if (0x62 < (byte)PTR_DAT_00025d54[0x43a]) {
      FUN_fffc2c4f();
      return;
    }
    vfo_enter_mem_state(bStack_5);
    FUN_fffc2937(bStack_5);
  }
  vfo_clear_tag(bStack_5);
  FUN_fffc2c66(bStack_5);
  FUN_fffc2cc8(bStack_5);
  eeprom_save_memch(PTR_DAT_00025d54[0x43a]);
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  PTR_DAT_00025d54[0x40c] = 1;
  FUN_fffc2b12();
  beep_request(2);
  return;
}


// ===== FUN_fffc2c4f @ fffc2c4f (23 bytes)

void FUN_fffc2c4f(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  beep_request(3);
  return;
}

