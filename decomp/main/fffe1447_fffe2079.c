// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe1447 @ fffe1447 (109 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe149b) */

undefined2 FUN_fffe1447(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 local_c;
  char local_a [7];
  char local_3;
  
  local_3 = DAT_00009c5e;
  local_a[0] = 'S';
  local_a[1] = 'T';
  local_a[3] = ';';
  if (DAT_00018802 == DAT_00009c5e) {
    local_c = 0;
  }
  else {
    DAT_00018802 = DAT_00009c5e;
    local_a[4] = '\x04';
    local_a[5] = '\0';
    if (DAT_00009c5e == '\0') {
      local_a[2] = 0x30;
    }
    else {
      local_a[2] = 0x31;
    }
    pcVar2 = local_a;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    local_c = 4;
  }
  return local_c;
}


// ===== FUN_fffe14b4 @ fffe14b4 (111 bytes)

ushort FUN_fffe14b4(void)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  ushort local_8;
  char local_6 [6];
  
  builtin_strncpy(local_6,"TS0;",4);
  local_8 = 0;
  if (DAT_0001b53d != DAT_00020f09) {
    DAT_0001b53d = DAT_00020f09;
    if (DAT_00020f09 == '\x01') {
      local_6[2] = 0x31;
    }
    else {
      local_6[2] = 0x30;
    }
    local_8 = 4;
  }
  if (local_8 != 0) {
    pcVar2 = local_6;
    pcVar1 = &DAT_00015e06;
    for (uVar3 = (uint)local_8; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  return local_8;
}


// ===== FUN_fffe1523 @ fffe1523 (115 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe157d) */

undefined2 FUN_fffe1523(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uStack_c;
  char acStack_7 [7];
  
  acStack_7[4] = ptt_source_get();
  acStack_7[0] = 'T';
  acStack_7[1] = 'X';
  acStack_7[3] = ';';
  if (DAT_00018803 == acStack_7[4]) {
    uStack_c = 0;
  }
  else {
    if (acStack_7[4] == 0) {
      acStack_7[2] = 0x30;
    }
    else if (acStack_7[4] == 5) {
      acStack_7[2] = 0x31;
    }
    else {
      acStack_7[2] = 0x32;
    }
    pcVar2 = acStack_7;
    pcVar1 = &DAT_00015e06;
    DAT_00018803 = acStack_7[4];
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    uStack_c = 4;
  }
  return uStack_c;
}


// ===== FUN_fffe1596 @ fffe1596 (199 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe165a) */
/* WARNING: Removing unreachable block (ram,0xfffe161f) */
/* WARNING: Removing unreachable block (ram,0xfffe1643) */

undefined2 FUN_fffe1596(void)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined2 local_14;
  char local_10 [6];
  byte local_a;
  byte local_9;
  byte local_8;
  byte local_7;
  
  local_10[5] = DAT_00009af3;
  builtin_strncpy(local_10,"VD00;",5);
  if (DAT_00009af3 == '\0') {
    local_a = DAT_00009bf4;
  }
  else {
    local_a = DAT_00009bf5;
  }
  if (DAT_00018804 == local_a) {
    local_14 = 0;
  }
  else {
    DAT_00018804 = local_a;
    local_8 = 10;
    for (local_9 = 0; local_9 < 2; local_9 = local_9 + 1) {
      local_7 = local_a;
      if (local_8 != 0) {
        local_7 = local_a / local_8;
      }
      local_a = local_a - local_7 * local_8;
      local_8 = local_8 / 10;
      uVar1 = (uint)local_9;
      cVar2 = nib2hex(local_7);
      local_10[uVar1 + 2] = cVar2;
    }
    pcVar4 = local_10;
    pcVar3 = &DAT_00015e06;
    for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pcVar3 = *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    }
    local_14 = 5;
  }
  return local_14;
}


// ===== FUN_fffe165d @ fffe165d (173 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1707) */
/* WARNING: Removing unreachable block (ram,0xfffe16cc) */
/* WARNING: Removing unreachable block (ram,0xfffe16f0) */

undefined2 FUN_fffe165d(void)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined2 local_14;
  char local_10 [7];
  byte local_9;
  byte local_8;
  byte local_7;
  
  builtin_strncpy(local_10,"VG000;",6);
  local_10[6] = DAT_00009bf3;
  if (DAT_00018805 == DAT_00009bf3) {
    local_14 = 0;
  }
  else {
    DAT_00018805 = DAT_00009bf3;
    local_8 = 100;
    for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
      local_7 = local_10[6];
      if (local_8 != 0) {
        local_7 = (byte)local_10[6] / local_8;
      }
      local_10[6] = local_10[6] - local_7 * local_8;
      local_8 = local_8 / 10;
      uVar1 = (uint)local_9;
      cVar2 = nib2hex(local_7);
      local_10[uVar1 + 2] = cVar2;
    }
    pcVar4 = local_10;
    pcVar3 = &DAT_00015e06;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pcVar3 = *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    }
    local_14 = 6;
  }
  return local_14;
}


// ===== FUN_fffe170a @ fffe170a (106 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1756) */

ushort FUN_fffe170a(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  ushort local_c;
  char local_7 [7];
  
  builtin_strncpy(local_7,"VS0;",4);
  local_7[4] = DAT_00009dbd;
  if (DAT_00018806 == DAT_00009dbd) {
    local_c = 0;
  }
  else {
    DAT_00018806 = DAT_00009dbd;
    local_7[2] = nib2hex(DAT_00009dbd);
    pcVar2 = local_7;
    pcVar1 = &DAT_00015e06;
    for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    local_c = 4;
  }
  return local_c;
}


// ===== FUN_fffe1774 @ fffe1774 (145 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe17e5) */

ushort FUN_fffe1774(void)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  ushort uStack_12;
  char acStack_e [6];
  byte *pbStack_8;
  
  pbStack_8 = vfo_rec_ptr(0);
  acStack_e[5] = vfo_mode(1);
  builtin_strncpy(acStack_e,"VX0;",4);
  uVar1 = (uint)(byte)acStack_e[5];
  if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
    acStack_e[4] = 0;
  }
  else {
    acStack_e[4] = DAT_00009c5d;
  }
  if (DAT_00018807 == acStack_e[4]) {
    uStack_12 = 0;
  }
  else {
    DAT_00018807 = acStack_e[4];
    acStack_e[2] = nib2hex(acStack_e[4]);
    pcVar3 = acStack_e;
    pcVar2 = &DAT_00015e06;
    for (iVar4 = 4; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    uStack_12 = 4;
  }
  return uStack_12;
}


// ===== FUN_fffe1805 @ fffe1805 (52 bytes)

byte FUN_fffe1805(byte *param_1)

{
  byte local_7;
  byte local_6;
  
  local_6 = *param_1;
  for (local_7 = 0; local_7 < 4; local_7 = local_7 + 1) {
    if (local_6 < param_1[local_7]) {
      local_6 = param_1[local_7];
    }
  }
  return local_6;
}


// ===== FUN_fffe1839 @ fffe1839 (52 bytes)

byte FUN_fffe1839(byte *param_1)

{
  byte local_7;
  byte local_6;
  
  local_6 = *param_1;
  for (local_7 = 0; local_7 < 4; local_7 = local_7 + 1) {
    if (param_1[local_7] < local_6) {
      local_6 = param_1[local_7];
    }
  }
  return local_6;
}


// ===== FUN_fffe186d @ fffe186d (313 bytes)

void FUN_fffe186d(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d6c[0x418] == '\x01') {
    scan_stop();
    return;
  }
  if (PTR_DAT_00025d6c[0x46b] == '\x01') {
    beep_request(1);
    return;
  }
  if (DAT_00009dbd == '\0') {
    if ((DAT_00009dbe == '\x02') && (((&DAT_00006155)[(uint)DAT_000060c9 * 0x5a] & 0x80) != 0)) {
      beep_request(1);
      return;
    }
  }
  else if ((DAT_00009dbf == '\x02') && (((&DAT_00006155)[(uint)DAT_000060ca * 0x5a] & 0x80) != 0)) {
    beep_request(1);
    return;
  }
  if (DAT_00009c5e == '\x01') {
    beep_request(1);
    return;
  }
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc4caa();
  beep_request(1);
  if ((PTR_DAT_00025d6c[0x1c2] == '\b') && (PTR_DAT_00025d6c[0x1c1] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc23b6();
    return;
  }
  PTR_DAT_00025d6c[0x1c2] = 8;
  PTR_DAT_00025d6c[0x1c1] = 1;
  PTR_DAT_00025d6c[0x1c0] = 1;
  FUN_fffe1e85();
  return;
}


// ===== FUN_fffe19a6 @ fffe19a6 (6 bytes)

void FUN_fffe19a6(void)

{
  FUN_fffe1a00(0);
  return;
}


// ===== FUN_fffe19ac @ fffe19ac (6 bytes)

void FUN_fffe19ac(void)

{
  FUN_fffe1a00(1);
  return;
}


// ===== FUN_fffe19b2 @ fffe19b2 (6 bytes)

void FUN_fffe19b2(void)

{
  FUN_fffe1a00(2);
  return;
}


// ===== FUN_fffe19b8 @ fffe19b8 (6 bytes)

void FUN_fffe19b8(void)

{
  FUN_fffe1a00(3);
  return;
}


// ===== FUN_fffe19be @ fffe19be (6 bytes)

void FUN_fffe19be(void)

{
  FUN_fffe1a00(4);
  return;
}


// ===== FUN_fffe19c4 @ fffe19c4 (6 bytes)

void FUN_fffe19c4(void)

{
  FUN_fffe1a00(5);
  return;
}


// ===== FUN_fffe19ca @ fffe19ca (6 bytes)

void FUN_fffe19ca(void)

{
  FUN_fffe1a00(6);
  return;
}


// ===== FUN_fffe19d0 @ fffe19d0 (6 bytes)

void FUN_fffe19d0(void)

{
  FUN_fffe1a00(7);
  return;
}


// ===== FUN_fffe19d6 @ fffe19d6 (6 bytes)

void FUN_fffe19d6(void)

{
  FUN_fffe1a00(8);
  return;
}


// ===== FUN_fffe19dc @ fffe19dc (6 bytes)

void FUN_fffe19dc(void)

{
  FUN_fffe1a00(9);
  return;
}


// ===== FUN_fffe19e2 @ fffe19e2 (6 bytes)

void FUN_fffe19e2(void)

{
  FUN_fffe1a00(10);
  return;
}


// ===== FUN_fffe19e8 @ fffe19e8 (6 bytes)

void FUN_fffe19e8(void)

{
  FUN_fffe1a00(0xb);
  return;
}


// ===== FUN_fffe19ee @ fffe19ee (6 bytes)

void FUN_fffe19ee(void)

{
  FUN_fffe1a00(0xc);
  return;
}


// ===== FUN_fffe19f4 @ fffe19f4 (6 bytes)

void FUN_fffe19f4(void)

{
  FUN_fffe1a00(0xd);
  return;
}


// ===== FUN_fffe19fa @ fffe19fa (6 bytes)

void FUN_fffe19fa(void)

{
  FUN_fffe1a00(0xe);
  return;
}


// ===== FUN_fffe1a00 @ fffe1a00 (904 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1d52) */

void FUN_fffe1a00(char param_1)

{
  undefined4 uVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  byte local_9;
  byte local_1;
  
  if (DAT_0001b54e == '\x01') {
    DAT_00018809 = DAT_00009dbe;
    DAT_0001880a = DAT_00009dbf;
    DAT_0001b54e = '\0';
  }
  if ((byte)PTR_DAT_00025d6c[0x468] < 2) {
    PTR_DAT_00025d6c[0x468] = 2;
  }
  if (param_1 == '\n') {
    FUN_fffe1e85();
    beep_request(1);
    return;
  }
  if (param_1 == '\v') {
    if (PTR_DAT_00025d6c[0x468] == '\x03') {
      PTR_DAT_00025d6c[0x410] = (byte)PTR_DAT_00025d6c[0x410] >> 4;
      PTR_DAT_00025d6c[0x468] = 4;
      FUN_fffe1e70();
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d6c[0x468] != '\x02') {
      FUN_fffe1e70();
      beep_request(1);
      return;
    }
    PTR_DAT_00025d6c[0x410] = 0;
    PTR_DAT_00025d6c[0x468] = 4;
    FUN_fffe1e70();
    beep_request(1);
    return;
  }
  if (param_1 != '\f') {
    if (param_1 != '\r') {
      if (param_1 != '\x0e') {
        local_1 = param_1 + 1;
        if (local_1 == 10) {
          local_1 = 0;
        }
        uVar8 = (uint)((byte)PTR_DAT_00025d6c[0x468] >> 1);
        if ((PTR_DAT_00025d6c[0x468] & 1) == 0) {
          PTR_DAT_00025d6c[uVar8 + 0x40f] = PTR_DAT_00025d6c[uVar8 + 0x40f] & 0xf | local_1 << 4;
        }
        else {
          PTR_DAT_00025d6c[uVar8 + 0x40f] = PTR_DAT_00025d6c[uVar8 + 0x40f] & 0xf0 | local_1;
        }
        if ((byte)PTR_DAT_00025d6c[0x468] < 9) {
          PTR_DAT_00025d6c[0x468] = PTR_DAT_00025d6c[0x468] + '\x01';
        }
        FUN_fffe1e70();
        beep_request(1);
        return;
      }
      DAT_00009dbe = DAT_00018809;
      DAT_00009dbf = DAT_0001880a;
      DAT_0001b54e = 1;
      FUN_fffc23b6();
      FUN_fffe1e70();
      beep_request(1);
      return;
    }
    for (local_9 = 1; local_9 < 5; local_9 = local_9 + 1) {
      if (0x90 < (PTR_DAT_00025d6c[local_9 + 0x40f] & 0xf0)) {
        PTR_DAT_00025d6c[local_9 + 0x40f] = PTR_DAT_00025d6c[local_9 + 0x40f] & 0xf;
      }
      if (9 < (PTR_DAT_00025d6c[local_9 + 0x40f] & 0xf)) {
        PTR_DAT_00025d6c[local_9 + 0x40f] = PTR_DAT_00025d6c[local_9 + 0x40f] & 0xf0;
      }
    }
    cVar3 = FUN_fffb2fc0(PTR_DAT_00025d6c[0x410]);
    cVar4 = FUN_fffb2fc0(PTR_DAT_00025d6c[0x411]);
    cVar5 = FUN_fffb2fc0(PTR_DAT_00025d6c[0x412]);
    cVar6 = FUN_fffb2fc0(PTR_DAT_00025d6c[0x413]);
    iVar7 = FUN_fffe1dd7((int)cVar6 + cVar5 * 100 + cVar4 * 10000 + cVar3 * 1000000);
    if (iVar7 != 0) {
      uVar1 = *(undefined4 *)(PTR_DAT_00025d6c + 0x464);
      FUN_fffe1da4(uVar1);
      if (PTR_DAT_00025d6c[0x414] == '\x01') {
        FUN_fffe1d96(uVar1);
      }
      PTR_DAT_00025d6c[0x40c] = 1;
      FUN_fffe1d88(uVar1);
      FUN_fffc23b6();
      vfo_mark_edited(DAT_00009dbd);
      vfo_store_back(DAT_00009dbd);
      FUN_fffe1e70();
      DAT_0001b54e = 1;
      beep_request(1);
      return;
    }
    FUN_fffe1e85();
    beep_request(3);
    return;
  }
  if (PTR_DAT_00025d6c[0x468] == '\x02') {
    FUN_fffe1e70();
    beep_request(3);
    return;
  }
  if ((PTR_DAT_00025d6c[0x468] == '\t') && ((PTR_DAT_00025d6c[0x413] & 0xf) != 0xf)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    uVar8 = (uint)((byte)PTR_DAT_00025d6c[0x468] >> 1);
    if ((PTR_DAT_00025d6c[0x468] & 1) == 0) {
      PTR_DAT_00025d6c[uVar8 + 0x40e] = PTR_DAT_00025d6c[uVar8 + 0x40e] | 0xf;
    }
    else {
      PTR_DAT_00025d6c[uVar8 + 0x40f] = 0xff;
    }
    PTR_DAT_00025d6c[0x468] = PTR_DAT_00025d6c[0x468] + -1;
    FUN_fffe1e70();
    beep_request(1);
    return;
  }
  PTR_DAT_00025d6c[0x413] = PTR_DAT_00025d6c[0x413] | 0xf;
  FUN_fffe1e70();
  beep_request(1);
  return;
}


// ===== FUN_fffe1d88 @ fffe1d88 (14 bytes)

void FUN_fffe1d88(uint param_1)

{
  bandmem_set('\x01',param_1);
  return;
}


// ===== FUN_fffe1d96 @ fffe1d96 (14 bytes)

void FUN_fffe1d96(uint param_1)

{
  bandmem_set('\x02',param_1);
  return;
}


// ===== FUN_fffe1da4 @ fffe1da4 (51 bytes)

void FUN_fffe1da4(uint param_1)

{
  byte *pbVar1;
  byte bStack_9;
  
  pbVar1 = vfo_rec_ptr(0);
  for (bStack_9 = 0; bStack_9 < 4; bStack_9 = bStack_9 + 1) {
    pbVar1[bStack_9 + 0x4a] = (byte)(param_1 >> ((3 - bStack_9 & 3) << 3));
  }
  return;
}


// ===== FUN_fffe1dd7 @ fffe1dd7 (153 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe1e6d) */

bool FUN_fffe1dd7(uint param_1)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  
  *(uint *)(PTR_DAT_00025d6c + 0x464) = param_1;
  cVar1 = DAT_00009dbd;
  if (DAT_00009dbd == '\0') {
    if (DAT_00009dbe == '\x02') {
      vfo_mem_to_memtune('\0');
    }
  }
  else if (DAT_00009dbf == '\x02') {
    vfo_mem_to_memtune(DAT_00009dbd);
  }
  PTR_DAT_00025d6c[0x460] = 1;
  puVar2 = PTR_DAT_00025d6c;
  uVar3 = freq_clamp(cVar1,param_1);
  *(uint *)(puVar2 + 0x464) = uVar3;
  PTR_DAT_00025d6c[0x460] = 0;
  return PTR_DAT_00025d6c[0x469] != '\x01';
}


// ===== FUN_fffe1e70 @ fffe1e70 (21 bytes)

void FUN_fffe1e70(void)

{
  DAT_00018808 = 1;
  swtimer_start(0x46,10000);
  return;
}


// ===== FUN_fffe1e85 @ fffe1e85 (95 bytes)

void FUN_fffe1e85(void)

{
  PTR_DAT_00025d6c[0x40f] = 0xff;
  PTR_DAT_00025d6c[0x410] = 0xff;
  PTR_DAT_00025d6c[0x411] = 0xff;
  PTR_DAT_00025d6c[0x412] = 0xff;
  PTR_DAT_00025d6c[0x413] = 0xff;
  PTR_DAT_00025d6c[0x40d] = 1;
  FUN_fffe1e70();
  PTR_DAT_00025d6c[0x468] = 0;
  return;
}


// ===== FUN_fffe1ee4 @ fffe1ee4 (89 bytes)

void FUN_fffe1ee4(void)

{
  bool bVar1;
  byte bVar2;
  
  if (DAT_00018808 != '\0') {
    if ((PTR_DAT_00025d6c[0x40d] == '\x01') || (PTR_DAT_00025d6c[0x41d] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (bVar2 = swtimer_expired(0x46), bVar2 == 1)) {
      DAT_00018808 = 0;
      FUN_fffc23b6();
      FUN_fffe1f3d();
      return;
    }
  }
  return;
}


// ===== FUN_fffe1f3d @ fffe1f3d (35 bytes)

void FUN_fffe1f3d(void)

{
  if (PTR_DAT_00025d6c[0x41d] != '\x01') {
    return;
  }
  PTR_DAT_00025d6c[0x41d] = 0;
  FUN_fffc8beb();
  return;
}


// ===== FUN_fffe1f60 @ fffe1f60 (197 bytes)

void FUN_fffe1f60(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d6c[0x41d] == '\x01') {
    FUN_fffc23b6();
    FUN_fffe1f3d();
    beep_request(1);
    return;
  }
  if ((PTR_DAT_00025d6c[0x1c1] == '\x01') && (PTR_DAT_00025d6c[0x1c2] == '\a')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    beep_request(1);
    return;
  }
  PTR_DAT_00025d6c[0x1c2] = 7;
  PTR_DAT_00025d6c[0x1c1] = 1;
  PTR_DAT_00025d6c[0x1c0] = 1;
  DAT_00009c5e = 1;
  PTR_DAT_00025d6c[0x41d] = 1;
  *(undefined4 *)(PTR_DAT_00025d6c + 0x40f) = 0xffffffff;
  swtimer_start(0x46,10000);
  DAT_00018808 = 1;
  PTR_DAT_00025d6c[0x468] = 0;
  return;
}


// ===== FUN_fffe2025 @ fffe2025 (6 bytes)

void FUN_fffe2025(void)

{
  FUN_fffe207f('\0');
  return;
}


// ===== FUN_fffe202b @ fffe202b (6 bytes)

void FUN_fffe202b(void)

{
  FUN_fffe207f('\x01');
  return;
}


// ===== FUN_fffe2031 @ fffe2031 (6 bytes)

void FUN_fffe2031(void)

{
  FUN_fffe207f('\x02');
  return;
}


// ===== FUN_fffe2037 @ fffe2037 (6 bytes)

void FUN_fffe2037(void)

{
  FUN_fffe207f('\x03');
  return;
}


// ===== FUN_fffe203d @ fffe203d (6 bytes)

void FUN_fffe203d(void)

{
  FUN_fffe207f('\x04');
  return;
}


// ===== FUN_fffe2043 @ fffe2043 (6 bytes)

void FUN_fffe2043(void)

{
  FUN_fffe207f('\x05');
  return;
}


// ===== FUN_fffe2049 @ fffe2049 (6 bytes)

void FUN_fffe2049(void)

{
  FUN_fffe207f('\x06');
  return;
}


// ===== FUN_fffe204f @ fffe204f (6 bytes)

void FUN_fffe204f(void)

{
  FUN_fffe207f('\a');
  return;
}


// ===== FUN_fffe2055 @ fffe2055 (6 bytes)

void FUN_fffe2055(void)

{
  FUN_fffe207f('\b');
  return;
}


// ===== FUN_fffe205b @ fffe205b (6 bytes)

void FUN_fffe205b(void)

{
  FUN_fffe207f('\t');
  return;
}


// ===== FUN_fffe2061 @ fffe2061 (6 bytes)

void FUN_fffe2061(void)

{
  FUN_fffe207f('\n');
  return;
}


// ===== FUN_fffe2067 @ fffe2067 (6 bytes)

void FUN_fffe2067(void)

{
  FUN_fffe207f('\v');
  return;
}


// ===== FUN_fffe206d @ fffe206d (6 bytes)

void FUN_fffe206d(void)

{
  FUN_fffe207f('\f');
  return;
}


// ===== FUN_fffe2073 @ fffe2073 (6 bytes)

void FUN_fffe2073(void)

{
  FUN_fffe207f('\r');
  return;
}


// ===== FUN_fffe2079 @ fffe2079 (6 bytes)

void FUN_fffe2079(void)

{
  FUN_fffe207f('\x0e');
  return;
}

