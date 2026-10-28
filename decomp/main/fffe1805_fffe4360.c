// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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


// ===== FUN_fffe207f @ fffe207f (538 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe20c9) */
/* WARNING: Removing unreachable block (ram,0xfffe20f0) */
/* WARNING: Removing unreachable block (ram,0xfffe225e) */

void FUN_fffe207f(char param_1)

{
  bool bVar1;
  byte bVar2;
  byte local_1;
  
  beep_request(1);
  if (param_1 == '\n') {
    PTR_DAT_00025d6c[0x411] = 0xff;
    PTR_DAT_00025d6c[0x412] = 0xff;
    PTR_DAT_00025d6c[0x468] = 0;
    FUN_fffe1e70();
    return;
  }
  if (param_1 == '\v') {
    if ((PTR_DAT_00025d6c[0x411] & 0xf0) == 0xa0) {
      PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] | 0xf0;
    }
    else {
      PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] & 0xaf | 0xa0;
    }
    FUN_fffe1e70();
    return;
  }
  if (param_1 != '\f') {
    if (param_1 != '\r') {
      if (param_1 == '\x0e') {
        FUN_fffc23b6();
        FUN_fffe1f3d();
        return;
      }
      local_1 = param_1 + 1;
      if (local_1 == 10) {
        local_1 = 0;
      }
      if (PTR_DAT_00025d6c[0x468] == '\0') {
        PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] & 0xf0 | local_1;
      }
      else {
        PTR_DAT_00025d6c[0x412] = PTR_DAT_00025d6c[0x412] & 0xf | local_1 << 4;
      }
      if (PTR_DAT_00025d6c[0x468] != '\x01') {
        PTR_DAT_00025d6c[0x468] = PTR_DAT_00025d6c[0x468] + '\x01';
      }
      FUN_fffe1e70();
      return;
    }
    if (PTR_DAT_00025d6c[0x412] == -1) {
      PTR_DAT_00025d6c[0x412] = PTR_DAT_00025d6c[0x411] << 4 | 0xf;
      PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] & 0xf0;
    }
    bVar2 = PTR_DAT_00025d6c[0x411] << 4 | (byte)PTR_DAT_00025d6c[0x412] >> 4;
    if (0x20 < bVar2) {
      FUN_fffe2299();
      FUN_fffe1e70();
      return;
    }
    FUN_fffb2fc0(bVar2);
    FUN_fffc23b6();
    FUN_fffe1f3d();
    return;
  }
  if (PTR_DAT_00025d6c[0x468] == '\0') {
    FUN_fffe1e70();
    return;
  }
  if ((PTR_DAT_00025d6c[0x468] == '\x01') && ((PTR_DAT_00025d6c[0x412] & 0xf0) != 0xf0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d6c[0x412] = PTR_DAT_00025d6c[0x412] | 0xf0;
    FUN_fffe1e70();
    return;
  }
  PTR_DAT_00025d6c[0x468] = 0;
  PTR_DAT_00025d6c[0x411] = PTR_DAT_00025d6c[0x411] | 0xf;
  PTR_DAT_00025d6c[0x412] = 0xff;
  FUN_fffe1e70();
  return;
}


// ===== FUN_fffe2299 @ fffe2299 (40 bytes)

void FUN_fffe2299(void)

{
  PTR_DAT_00025d6c[0x411] = 0xff;
  PTR_DAT_00025d6c[0x412] = 0xff;
  PTR_DAT_00025d6c[0x468] = 0;
  return;
}


// ===== FUN_fffe2622 @ fffe2622 (94 bytes)

void FUN_fffe2622(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d6c[0xbe];
  if (cVar1 == '\x06') {
    FUN_fffe2c33(param_1);
    return;
  }
  if (cVar1 == '\x01') {
    FUN_fffe273a(param_1);
    return;
  }
  if (cVar1 == '\x02') {
    FUN_fffe2811(param_1);
    return;
  }
  if (cVar1 == '\x03') {
    FUN_fffe2912(param_1);
    return;
  }
  if (cVar1 == '\x04') {
    FUN_fffe2918(param_1);
    return;
  }
  if (cVar1 == '\x05') {
    FUN_fffe291e(param_1);
    return;
  }
  if (cVar1 != '\0') {
    return;
  }
  FUN_fffe2680(param_1);
  return;
}


// ===== FUN_fffe2680 @ fffe2680 (186 bytes)

void FUN_fffe2680(char param_1)

{
  if (DAT_0001b54f == '\x01') {
    DAT_00018813 = DAT_00009b09;
    DAT_0001880f = DAT_00009b05;
    DAT_0001880b = DAT_00009b01;
    DAT_0001b54f = '\0';
  }
  FUN_fffe29b7(PTR_DAT_00025d6c + 0xc2,param_1);
  if (param_1 == -0x7c) {
    DAT_00009b09 = DAT_00018813;
    DAT_00009b05 = DAT_0001880f;
    DAT_00009b01 = DAT_0001880b;
    DAT_0001b54f = 1;
    return;
  }
  if (param_1 == -0x7b) {
    DAT_00009b09 = DAT_00020bce;
    DAT_00009b05 = DAT_00020bca;
    DAT_00009b01 = DAT_00020bc6;
    DAT_0001b54f = 1;
    return;
  }
  return;
}


// ===== FUN_fffe273a @ fffe273a (215 bytes)

void FUN_fffe273a(char param_1)

{
  int iVar1;
  
  if (DAT_0001b550 == '\x01') {
    DAT_0001881f = DAT_00020bce;
    DAT_0001881b = DAT_00020bca;
    DAT_00018817 = DAT_00020bc6;
    DAT_0001b550 = '\0';
  }
  FUN_fffe29b7(&DAT_00020bc6,param_1);
  if (param_1 == -0x7c) {
    DAT_00020bce = DAT_0001881f;
    DAT_00020bca = DAT_0001881b;
    DAT_00020bc6 = DAT_00018817;
    DAT_0001b550 = 1;
    return;
  }
  if (param_1 == -0x7b) {
    DAT_0001b550 = 1;
    iVar1 = (uint)(byte)PTR_DAT_00025d6c[0x43a] * 0x5a;
    *(undefined4 *)(&DAT_000061a6 + iVar1) = DAT_00020bce;
    *(undefined4 *)(&DAT_000061a2 + iVar1) = DAT_00020bca;
    *(undefined4 *)(&DAT_0000619e + iVar1) = DAT_00020bc6;
    eeprom_save_memch(PTR_DAT_00025d6c[0x43a]);
    return;
  }
  return;
}


// ===== FUN_fffe2811 @ fffe2811 (257 bytes)

undefined * FUN_fffe2811(byte param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined *puStack_c;
  
  iVar1 = (int)&DAT_00020bc6 + (uint)(byte)PTR_DAT_00025d6c[0xbf] * 0x32;
  if (DAT_0001b551 == '\x01') {
    smovf(0x18823,iVar1,0x32);
    param_3 = 0;
    DAT_0001b551 = '\0';
  }
  FUN_fffe29b7(iVar1,param_1,param_3);
  if (param_1 == 0x84) {
    if (PTR_DAT_00025d6c[0xbf] == '\0') {
      puStack_c = &DAT_000096a0;
    }
    else if (PTR_DAT_00025d6c[0xbf] == '\x01') {
      puStack_c = &DAT_000096d3;
    }
    else if (PTR_DAT_00025d6c[0xbf] == '\x02') {
      puStack_c = &DAT_00009706;
    }
    else if (PTR_DAT_00025d6c[0xbf] == '\x03') {
      puStack_c = &DAT_00009739;
    }
    else {
      puStack_c = &DAT_0000976c;
    }
    smovf(puStack_c,0x18823,0x32);
    DAT_0001b551 = 1;
    return puStack_c + 0x32;
  }
  if ((undefined *)(uint)param_1 == (undefined *)0x85) {
    DAT_0001b551 = 1;
    puVar2 = (undefined *)FUN_fffe481d();
    return puVar2;
  }
  return (undefined *)(uint)param_1;
}


// ===== FUN_fffe2912 @ fffe2912 (6 bytes)

void FUN_fffe2912(void)

{
  return;
}


// ===== FUN_fffe2918 @ fffe2918 (6 bytes)

void FUN_fffe2918(void)

{
  return;
}


// ===== FUN_fffe291e @ fffe291e (153 bytes)

void FUN_fffe291e(char param_1,undefined4 param_2,undefined4 param_3)

{
  byte bStack_2;
  
  if (DAT_0001b552 == '\x01') {
    smovf(0x18855,0x20bc6,0xf);
    param_3 = 0;
    DAT_0001b552 = '\0';
  }
  FUN_fffe29b7(&DAT_00020bc6,param_1,param_3);
  if (param_1 != -0x7c) {
    if (param_1 == -0x7b) {
      DAT_0001b552 = 1;
      for (bStack_2 = 0xe;
          (bStack_2 != 0 && (*(char *)((int)&DAT_00020bc6 + (uint)bStack_2) == ' '));
          bStack_2 = bStack_2 - 1) {
        *(undefined1 *)((int)&DAT_00020bc6 + (uint)bStack_2) = 0;
      }
      FUN_fffd0e37();
      return;
    }
    return;
  }
  DAT_0001b552 = 1;
  FUN_fffd0c27();
  return;
}


// ===== FUN_fffe29b7 @ fffe29b7 (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe2a1e) */
/* WARNING: Removing unreachable block (ram,0xfffe2a9a) */
/* WARNING: Removing unreachable block (ram,0xfffe2a92) */
/* WARNING: Removing unreachable block (ram,0xfffe2ada) */
/* WARNING: Removing unreachable block (ram,0xfffe2a33) */
/* WARNING: Removing unreachable block (ram,0xfffe2a48) */
/* WARNING: Removing unreachable block (ram,0xfffe2a5d) */
/* WARNING: Removing unreachable block (ram,0xfffe2a72) */
/* WARNING: Removing unreachable block (ram,0xfffe2a82) */
/* WARNING: Removing unreachable block (ram,0xfffe2ad7) */
/* WARNING: Removing unreachable block (ram,0xfffe2a07) */

uint FUN_fffe29b7(int param_1,char param_2)

{
  byte bVar1;
  uint uVar2;
  
  if (param_2 == '\b') {
    uVar2 = FUN_fffe2add(param_1);
    return uVar2;
  }
  if (param_2 == -0x79) {
    uVar2 = FUN_fffe2bfd();
    if (uVar2 == 0) {
      uVar2 = 3;
      beep_request(3);
      return uVar2;
    }
  }
  else {
    if (param_2 == -0x7e) {
      uVar2 = 1;
      beep_request(1);
      PTR_DAT_00025d6c[0xc0] = 0;
      return uVar2;
    }
    if (param_2 == -0x7d) {
      uVar2 = 1;
      beep_request(1);
      PTR_DAT_00025d6c[0xc0] = 2;
      return uVar2;
    }
    if (param_2 == -0x7c) {
      uVar2 = 1;
      beep_request(1);
      PTR_DAT_00025d6c[0x90] = 0;
      return uVar2;
    }
    if (param_2 == -0x7b) {
      uVar2 = 1;
      beep_request(1);
      PTR_DAT_00025d6c[0x90] = 0;
      return uVar2;
    }
    if (param_2 == -0x7a) {
      uVar2 = FUN_fffe2bcd();
      if (uVar2 == 0) {
        uVar2 = 3;
        beep_request(3);
        return uVar2;
      }
    }
    else if (param_2 == -0x7f) {
      uVar2 = 1;
      beep_request(1);
      if (PTR_DAT_00025d6c[0xc0] == '\0') {
        PTR_DAT_00025d6c[0xc0] = 1;
        return uVar2;
      }
      if (PTR_DAT_00025d6c[0xc0] == '\x01') {
        PTR_DAT_00025d6c[0xc0] = 0;
        return uVar2;
      }
    }
    else {
      beep_request(1);
      *(char *)((uint)(byte)PTR_DAT_00025d6c[0xc1] + param_1) = param_2;
      bVar1 = PTR_DAT_00025d6c[0xc1];
      uVar2 = FUN_fffe2b7a();
      if ((uint)bVar1 < (uVar2 & 0xff)) {
        PTR_DAT_00025d6c[0xc1] = PTR_DAT_00025d6c[0xc1] + '\x01';
        return uVar2;
      }
    }
  }
  return uVar2;
}


// ===== FUN_fffe2add @ fffe2add (157 bytes)

void FUN_fffe2add(int param_1)

{
  char cVar1;
  int iVar2;
  char cStack_6;
  byte local_5;
  
  if (PTR_DAT_00025d6c[0xc1] == '\0') {
    beep_request(3);
    return;
  }
  local_5 = PTR_DAT_00025d6c[0xc1];
  cVar1 = FUN_fffe2b7a();
  if ((cVar1 == PTR_DAT_00025d6c[0xc1]) && (*(char *)((uint)local_5 + param_1) != ' ')) {
    *(undefined1 *)((uint)local_5 + param_1) = 0x20;
    return;
  }
  for (cStack_6 = (cVar1 + '\x01') - PTR_DAT_00025d6c[0xc1]; cStack_6 != '\0';
      cStack_6 = cStack_6 + -1) {
    *(undefined1 *)(param_1 + (local_5 - 1)) = *(undefined1 *)((uint)local_5 + param_1);
    local_5 = local_5 + 1;
  }
  *(undefined1 *)(param_1 + (local_5 - 1)) = 0x20;
  iVar2 = FUN_fffe2bcd();
  if (iVar2 == 0) {
    beep_request(3);
    return;
  }
  return;
}


// ===== FUN_fffe2b7a @ fffe2b7a (83 bytes)

undefined1 FUN_fffe2b7a(void)

{
  uint uVar1;
  undefined1 local_2;
  
  local_2 = 0xe;
  uVar1 = (uint)(byte)PTR_DAT_00025d6c[0xbe];
  if (uVar1 == 6) {
    local_2 = 0xb;
  }
  else if (uVar1 == 1) {
    local_2 = 0xb;
  }
  else if (uVar1 == 2) {
    local_2 = 0x31;
  }
  else if (1 < uVar1 - 3) {
    if (uVar1 == 5) {
      local_2 = 0xe;
    }
    else {
      if (uVar1 != 0) {
        return 0xe;
      }
      local_2 = 0xb;
    }
  }
  return local_2;
}


// ===== FUN_fffe2bcd @ fffe2bcd (48 bytes)

bool FUN_fffe2bcd(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d6c[0xc1];
  if (cVar1 != '\0') {
    PTR_DAT_00025d6c[0xc1] = PTR_DAT_00025d6c[0xc1] + -1;
  }
  return cVar1 != '\0';
}


// ===== FUN_fffe2bfd @ fffe2bfd (54 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe2c30) */

bool FUN_fffe2bfd(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = PTR_DAT_00025d6c[0xc1];
  bVar2 = FUN_fffe2b7a();
  if (bVar1 < bVar2) {
    PTR_DAT_00025d6c[0xc1] = PTR_DAT_00025d6c[0xc1] + '\x01';
  }
  return bVar1 < bVar2;
}


// ===== FUN_fffe2c33 @ fffe2c33 (157 bytes)

void FUN_fffe2c33(char param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_fffd30e8();
  if (puVar1 != (undefined4 *)0x0) {
    if (DAT_0001b553 == '\x01') {
      DAT_0001886c = puVar1[2];
      DAT_00018868 = puVar1[1];
      DAT_00018864 = *puVar1;
      DAT_0001b553 = '\0';
    }
    FUN_fffe29b7(PTR_DAT_00025d6c + 0xc2,param_1);
    if (param_1 == -0x7c) {
      puVar1[2] = DAT_0001886c;
      puVar1[1] = DAT_00018868;
      *puVar1 = DAT_00018864;
      DAT_0001b553 = 1;
      return;
    }
    if (param_1 == -0x7b) {
      puVar1[2] = DAT_00020bce;
      puVar1[1] = DAT_00020bca;
      *puVar1 = DAT_00020bc6;
      DAT_0001b553 = 1;
      return;
    }
  }
  return;
}


// ===== dispreq_e7_task @ fffe2cd0 (532 bytes)

/* main_loop task 11: runs command 0x20F8C posted by DISPLAY frame 0xE7 */

void dispreq_e7_task(void)

{
  if (*(int *)(PTR_DAT_00025d70 + 0x488) == 1) {
    *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
    if ((PTR_DAT_00025d70[0x3f9] == '\x03') && (PTR_DAT_00025d70[0x3fc] != '\0')) {
      PTR_DAT_00025d70[0x3fc] = PTR_DAT_00025d70[0x3fc] + -1;
    }
    PTR_DAT_00025d70[0x3f9] = 1;
    PTR_DAT_00025d70[0x3f8] = 1;
    return;
  }
  if (*(int *)(PTR_DAT_00025d70 + 0x488) == 2) {
    *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
    if (PTR_DAT_00025d70[0x93] == '\x01') {
      PTR_DAT_00025d70[0x3fe] = 0;
      if (PTR_DAT_00025d70[0x3fd] == '\x01') {
        PTR_DAT_00025d70[0x3fd] = 0;
        PTR_DAT_00025d70[0x3f8] = 1;
        PTR_DAT_00025d70[0x3f9] = 1;
        return;
      }
      if (PTR_DAT_00025d70[0x3fd] != '\0') {
        PTR_DAT_00025d70[0x3fd] = 0;
        PTR_DAT_00025d70[0x3f8] = 1;
        PTR_DAT_00025d70[0x3f9] = 1;
        return;
      }
    }
  }
  else {
    if (*(int *)(PTR_DAT_00025d70 + 0x488) == 3) {
      *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
      return;
    }
    if (*(int *)(PTR_DAT_00025d70 + 0x488) == 4) {
      *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
      return;
    }
    if (*(int *)(PTR_DAT_00025d70 + 0x488) == 5) {
      *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
      PTR_DAT_00025d70[0x93] = 0;
      PTR_DAT_00025d70[0x3f8] = 0;
      PTR_DAT_00025d70[0x92] = 0;
      beep_request(3);
      if (PTR_DAT_00025d70[0xac] == '\0') {
        PTR_DAT_00025d70[0xbb] = 0x10;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x01') {
        PTR_DAT_00025d70[0xbb] = 0x11;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x02') {
        PTR_DAT_00025d70[0xbb] = 0x12;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x03') {
        PTR_DAT_00025d70[0xbb] = 0x13;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x04') {
        PTR_DAT_00025d70[0xbb] = 0x14;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x05') {
        PTR_DAT_00025d70[0xbb] = 0x15;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x06') {
        PTR_DAT_00025d70[0xbb] = 0x18;
      }
      else if (PTR_DAT_00025d70[0xac] == '\a') {
        PTR_DAT_00025d70[0xbb] = 0x19;
      }
      else {
        PTR_DAT_00025d70[0xbb] = 0x1a;
      }
      PTR_DAT_00025d70[0x86] = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffe2ee4 @ fffe2ee4 (196 bytes)

void FUN_fffe2ee4(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d70[0x418] == '\x01') {
    scan_stop();
    return;
  }
  if (PTR_DAT_00025d70[0x46b] != '\x01') {
    if ((DAT_00020b7c == '\0') && (DAT_00020f1b != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (DAT_00020cce == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if (PTR_DAT_00025d70[0x92] == '\0') {
        PTR_DAT_00025d70[0x92] = 1;
      }
      else {
        PTR_DAT_00025d70[0x92] = 0;
      }
      PTR_DAT_00025d70[0x91] = 1;
      PTR_DAT_00025d70[0x409] = 1;
      beep_request(1);
      return;
    }
    return;
  }
  PTR_DAT_00025d70[0x46b] = 0;
  PTR_DAT_00025d70[0x46c] = 0;
  beep_request(6);
  return;
}


// ===== FUN_fffe2fa8 @ fffe2fa8 (283 bytes)

void FUN_fffe2fa8(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d70[0x418] == '\x01') {
    scan_stop();
    return;
  }
  if (PTR_DAT_00025d70[0x46c] != '\x01') {
    beep_request(1);
    if (PTR_DAT_00025d70[0x417] == '\x01') {
      PTR_DAT_00025d70[0x417] = 0;
      return;
    }
    if (PTR_DAT_00025d70[0x92] != '\x01') {
      if ((DAT_00020ccd == '\x01') || (DAT_00020b7c != '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (DAT_00020cd0 == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (DAT_00020cd1 == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        DAT_00020cd5 = 0;
        PTR_DAT_00025d70[0x93] = 1;
        PTR_DAT_00025d70[0x3f8] = 1;
        PTR_DAT_00025d70[0x3f9] = 0;
        PTR_DAT_00025d70[0x3fc] = 0;
        FUN_fffc3c85();
        PTR_DAT_00025d70[0x409] = 1;
        return;
      }
    }
    return;
  }
  PTR_DAT_00025d70[0x46b] = 0;
  PTR_DAT_00025d70[0x46c] = 0;
  beep_request(6);
  return;
}


// ===== FUN_fffe3121 @ fffe3121 (202 bytes)

void FUN_fffe3121(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d70[0x3fc];
  if ((byte)PTR_DAT_00025d70[0xaa] < 4) {
    if (cVar1 == '\0') {
      return;
    }
    if ((byte)(PTR_DAT_00025d70[0xaa] - 1) < (byte)(cVar1 - 1U)) {
      PTR_DAT_00025d70[0x3fc] = PTR_DAT_00025d70[0xaa] + -1;
    }
    else {
      PTR_DAT_00025d70[0x3fc] = cVar1 - 1U;
    }
  }
  else if (cVar1 == '\0') {
    if (*(short *)(PTR_DAT_00025d70 + 0x3fa) == 0) {
      return;
    }
    *(short *)(PTR_DAT_00025d70 + 0x3fa) = *(short *)(PTR_DAT_00025d70 + 0x3fa) + -1;
  }
  else {
    PTR_DAT_00025d70[0x3fc] = cVar1 + -1;
  }
  PTR_DAT_00025d70[0x3f8] = 1;
  PTR_DAT_00025d70[0x3f9] = 1;
  PTR_DAT_00025d70[0x409] = 1;
  return;
}


// ===== FUN_fffe32fd @ fffe32fd (211 bytes)

void FUN_fffe32fd(void)

{
  ushort local_4;
  byte local_1;
  
  local_1 = PTR_DAT_00025d70[0x3fc];
  local_4 = *(ushort *)(PTR_DAT_00025d70 + 0x3fa);
  if (local_1 < 3) {
    local_1 = local_1 + 1;
  }
  else {
    local_4 = local_4 + 1;
  }
  if ((byte)PTR_DAT_00025d70[0xaa] < 4) {
    local_4 = 0;
    if ((byte)(PTR_DAT_00025d70[0xaa] - 1) < local_1) {
      PTR_DAT_00025d70[0x3fc] = 4;
    }
    else {
      PTR_DAT_00025d70[0x3fc] = local_1;
    }
  }
  else if (((byte)PTR_DAT_00025d70[0xaa] - 4 & 0xff) < local_4) {
    local_4 = (byte)PTR_DAT_00025d70[0xaa] - 4;
    PTR_DAT_00025d70[0x3fc] = 4;
  }
  else {
    PTR_DAT_00025d70[0x3fc] = local_1;
  }
  *(ushort *)(PTR_DAT_00025d70 + 0x3fa) = local_4;
  PTR_DAT_00025d70[0x3f8] = 1;
  PTR_DAT_00025d70[0x3f9] = 1;
  PTR_DAT_00025d70[0x409] = 1;
  return;
}


// ===== FUN_fffe35c3 @ fffe35c3 (75 bytes)

void FUN_fffe35c3(void)

{
  if (PTR_DAT_00025d70[0x3fd] != '\0') {
    return;
  }
  PTR_DAT_00025d70[0x93] = 0;
  PTR_DAT_00025d70[0x3f8] = 0;
  PTR_DAT_00025d70[0x409] = 1;
  PTR_DAT_00025d70[0x3fe] = 0;
  beep_request(1);
  return;
}


// ===== dispreq_e8_task @ fffe360e (7 bytes)

/* main_loop task 10: runs command 0x20F90 posted by DISPLAY frame 0xE8 */

void dispreq_e8_task(void)

{
  FUN_fffe376a();
  FUN_fffe3615();
  return;
}


// ===== FUN_fffe3615 @ fffe3615 (341 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe3703) */
/* WARNING: Removing unreachable block (ram,0xfffe372f) */
/* WARNING: Removing unreachable block (ram,0xfffe3767) */
/* WARNING: Removing unreachable block (ram,0xfffe3764) */
/* WARNING: Removing unreachable block (ram,0xfffe375c) */
/* WARNING: Removing unreachable block (ram,0xfffe36ba) */

uint FUN_fffe3615(void)

{
  byte bVar1;
  undefined *puVar2;
  byte bVar3;
  uint uVar4;
  uint uStack_c;
  
  bVar1 = DAT_00020b2f;
  bVar3 = vfo_mode(1);
  if ((bVar3 == 3) || (bVar3 == 2)) {
    uStack_c = 0;
  }
  else {
    uStack_c = 1;
  }
  if (uStack_c != 0) {
    PTR_DAT_00025d74[0x1d1] = 0;
  }
  puVar2 = PTR_DAT_00025d74;
  if (DAT_00018870 != bVar1) {
    DAT_00018870 = bVar1;
    uStack_c = (uint)bVar1;
    if (uStack_c == 7) {
      uVar4 = FUN_fffba30c();
      *(short *)(puVar2 + 0x1d6) = (short)uVar4;
      PTR_DAT_00025d74[0x1cc] = 0;
      PTR_DAT_00025d74[0x1cd] = 0;
      return uVar4;
    }
    if (uStack_c == 5) {
      if (PTR_DAT_00025d74[0x1d1] == '\x01') {
        uVar4 = FUN_fffe5544(PTR_DAT_00025d74[0x1c8]);
        if (uVar4 != 0) {
          PTR_DAT_00025d74[0x1cd] = 1;
          return uVar4;
        }
        PTR_DAT_00025d74[0x1cc] = 1;
        return 0;
      }
    }
    else if (uStack_c == 1) {
      if (DAT_00020cd6 == '\x01') {
        DAT_00020cd6 = 0;
        uVar4 = FUN_fffe5544(PTR_DAT_00025d74[0x1c8]);
        if (uVar4 == 0) {
          PTR_DAT_00025d74[0x1cc] = 1;
        }
        else {
          PTR_DAT_00025d74[0x1cd] = 1;
        }
        DAT_00020b2f = 5;
        return uVar4;
      }
      uStack_c = FUN_fffba30c();
      *(short *)(puVar2 + 0x1d6) = (short)uStack_c;
      PTR_DAT_00025d74[0x1cc] = 0;
      PTR_DAT_00025d74[0x1cd] = 0;
      if (PTR_DAT_00025d74[0x1c9] == '\x01') {
        PTR_DAT_00025d74[0x1c9] = 0;
        return uStack_c;
      }
    }
  }
  return uStack_c;
}


// ===== FUN_fffe376a @ fffe376a (527 bytes)

void FUN_fffe376a(void)

{
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 1) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    return;
  }
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 2) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    if ((PTR_DAT_00025d74[0x78] == '\x01') && (DAT_00020b2e == '\x01')) {
      DAT_00020b2e = '\0';
    }
    PTR_DAT_00025d74[0x78] = 0;
    PTR_DAT_00025d74[0x1cf] = 0;
    PTR_DAT_00025d74[0x1d0] = 0;
    PTR_DAT_00025d74[0x1c8] = 0;
    return;
  }
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 3) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    PTR_DAT_00025d74[0x1cf] = 1;
    PTR_DAT_00025d74[0x1d0] = 0;
    return;
  }
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 4) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    return;
  }
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 5) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    FUN_fffe556a();
    PTR_DAT_00025d74[0x1c8] = 0;
    beep_request(3);
    if (DAT_00020b2e == '\x01') {
      DAT_00020b2e = '\0';
    }
    if (PTR_DAT_00025d74[0xac] == '\0') {
      PTR_DAT_00025d74[0xbb] = 0x10;
      PTR_DAT_00025d74[0x94] = 0;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x01') {
      PTR_DAT_00025d74[0xbb] = 0x11;
      PTR_DAT_00025d74[0x94] = 0;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x02') {
      PTR_DAT_00025d74[0xbb] = 0x12;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x03') {
      PTR_DAT_00025d74[0x78] = 0;
      PTR_DAT_00025d74[0x1cf] = 0;
      PTR_DAT_00025d74[0x1d0] = 0;
      PTR_DAT_00025d74[0x1c8] = 0;
      PTR_DAT_00025d74[0xbb] = 0x13;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x04') {
      PTR_DAT_00025d74[0xbb] = 0x14;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x05') {
      PTR_DAT_00025d74[0xbb] = 0x15;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x06') {
      PTR_DAT_00025d74[0xbb] = 0x18;
    }
    else if (PTR_DAT_00025d74[0xac] == '\a') {
      PTR_DAT_00025d74[0xbb] = 0x19;
    }
    else {
      PTR_DAT_00025d74[0xbb] = 0x1a;
    }
    PTR_DAT_00025d74[0x86] = 1;
    return;
  }
  return;
}


// ===== FUN_fffe3979 @ fffe3979 (412 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe3990) */
/* WARNING: Removing unreachable block (ram,0xfffe3b12) */
/* WARNING: Removing unreachable block (ram,0xfffe3b0f) */
/* WARNING: Removing unreachable block (ram,0xfffe39bb) */

int FUN_fffe3979(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined2 uVar3;
  int iVar4;
  int local_8;
  
  if (PTR_DAT_00025d74[0x418] == '\x01') {
    scan_stop();
    return param_1;
  }
  if (PTR_DAT_00025d74[0x46b] != '\x01') {
    if ((PTR_DAT_00025d74[0x417] == '\x01') || (PTR_DAT_00025d74[0x78] != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (PTR_DAT_00025d74[0x1cc] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (PTR_DAT_00025d74[0x1cd] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (PTR_DAT_00025d74[0x1c9] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b97 == '\x01')) {
      local_8 = 1;
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      iVar4 = FUN_fffe5690();
      if ((iVar4 == 0) && (DAT_00020b96 == '\x01')) {
        local_8 = 1;
      }
      else {
        local_8 = 0;
      }
      if (local_8 == 0) {
        iVar4 = FUN_fffe56bf();
        if (iVar4 == 1) {
          PTR_DAT_00025d74[0x1c7] = 0;
          PTR_DAT_00025d74[0x94] = 1;
          PTR_DAT_00025d74[0x1d0] = 0;
          PTR_DAT_00025d74[0x1cf] = 0;
          beep_request(1);
        }
        else {
          iVar4 = FUN_fffe5690();
          if (iVar4 == 1) {
            PTR_DAT_00025d74[0x1c7] = 1;
            PTR_DAT_00025d74[0x94] = 1;
            puVar2 = PTR_DAT_00025d74;
            uVar3 = FUN_fffba30c();
            *(undefined2 *)(puVar2 + 0x1d6) = uVar3;
            PTR_DAT_00025d74[0x1d0] = 0;
            PTR_DAT_00025d74[0x1cf] = 0;
            beep_request(1);
          }
          else {
            beep_request(3);
          }
        }
        iVar4 = FUN_fffc3c85();
        return iVar4;
      }
    }
    return local_8;
  }
  PTR_DAT_00025d74[0x46b] = 0;
  PTR_DAT_00025d74[0x46c] = 0;
  iVar4 = 6;
  beep_request(6);
  return iVar4;
}


// ===== FUN_fffe3d24 @ fffe3d24 (262 bytes)

void FUN_fffe3d24(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d74[0x94] == '\x01') || (PTR_DAT_00025d74[0x1cc] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d74[0x1cd] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d74[0x1d1] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d74[0x1c9] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d74[0x417] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d74[0x94] = 0;
    PTR_DAT_00025d74[0x1cc] = 0;
    PTR_DAT_00025d74[0x1cd] = 0;
    PTR_DAT_00025d74[0x417] = 0;
    PTR_DAT_00025d74[0x1d1] = 0;
    PTR_DAT_00025d74[0x2b] = 7;
    PTR_DAT_00025d74[0x1c9] = 0;
    PTR_DAT_00025d74[0x94] = 0;
    return;
  }
  return;
}


// ===== ladder_key_task @ fffe3e2a (699 bytes)

/* main_loop task 8: acts on ladder key code 0x1204C */

void ladder_key_task(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
  if (PTR_DAT_00025d78[0x86] != '\x01') {
    bVar2 = remote_key_get();
    if (DAT_0001b554 == bVar2) {
      if (bVar2 == 0xfa) {
        FUN_fffe4da3();
      }
      else if (bVar2 == 0xf8) {
        FUN_fffe4b73();
      }
      else if (bVar2 == 0xf9) {
        iVar4 = FUN_fffe419a();
        if (iVar4 == 1) {
          FUN_fffe4cc1();
        }
      }
      else if ((bVar2 == 0xf7) && (iVar4 = FUN_fffe419a(), iVar4 == 1)) {
        FUN_fffe4a67();
      }
    }
    else {
      if (DAT_00020f0b == '\x01') {
        DAT_00020f0b = 0;
        beep_stop();
        return;
      }
      if (PTR_DAT_00025d78[0x437] == '\x01') {
        FUN_fffe56e4();
        DAT_0001b554 = bVar2;
        return;
      }
      if ((bVar2 == 0) || (6 < bVar2)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (bVar3 = key_event_filter(bVar2 + 0x86,1), bVar3 == 0)) {
        return;
      }
      if (DAT_0001b554 == 0xfa) {
        FUN_fffe4c04();
      }
      else if (DAT_0001b554 == 1) {
        if (bVar2 == 0xf1) {
          FUN_fffe46f3();
        }
        else {
          FUN_fffe435a();
        }
      }
      else if (DAT_0001b554 == 2) {
        if (bVar2 == 0xf2) {
          FUN_fffe46f9();
        }
        else {
          FUN_fffe4360();
        }
      }
      else if (DAT_0001b554 == 3) {
        if (bVar2 == 0xf3) {
          FUN_fffe46ff();
        }
        else {
          FUN_fffe4366();
        }
      }
      else if (DAT_0001b554 == 4) {
        if (bVar2 == 0xf4) {
          FUN_fffe4705();
        }
        else {
          FUN_fffe436c();
        }
      }
      else if (DAT_0001b554 == 5) {
        if (bVar2 == 0xf5) {
          FUN_fffe470b();
        }
        else {
          FUN_fffe4372();
        }
      }
      else if (DAT_0001b554 == 6) {
        if (bVar2 == 0xf6) {
          FUN_fffe47be();
        }
        else {
          FUN_fffe46b0();
        }
      }
      else if (DAT_0001b554 == 7) {
        if (bVar2 == 0xf7) {
          FUN_fffe49fb();
        }
        else {
          FUN_fffe46d3();
        }
      }
      else if (DAT_0001b554 == 8) {
        if (bVar2 == 0xf8) {
          FUN_fffe4af8();
        }
        else {
          FUN_fffe46d4();
        }
      }
      else if (DAT_0001b554 == 9) {
        if (bVar2 == 0xf9) {
          FUN_fffe4c55();
        }
        else {
          FUN_fffe46e2();
        }
      }
      else if (DAT_0001b554 == 10) {
        if (bVar2 == 0xfa) {
          FUN_fffe4d28();
        }
        else {
          FUN_fffe46e3();
        }
      }
      else if (DAT_0001b554 == 0xb) {
        if (bVar2 == 0xfb) {
          FUN_fffe4de3();
        }
        else {
          FUN_fffe46f1();
        }
      }
      else if (DAT_0001b554 == 0xc) {
        if (bVar2 == 0xfc) {
          FUN_fffe4de4();
        }
        else {
          FUN_fffe46f2();
        }
      }
      else if (DAT_0001b554 == 0xf8) {
        FUN_fffe4bb3();
      }
      else if (DAT_0001b554 == 0) {
        switch(bVar2) {
        case 1:
          FUN_fffe41f3();
          break;
        case 2:
          FUN_fffe41f9();
          break;
        case 3:
          FUN_fffe41ff();
          break;
        case 4:
          FUN_fffe4205();
          break;
        case 5:
          FUN_fffe420b();
          break;
        case 6:
          FUN_fffe4407();
          break;
        case 7:
          FUN_fffe4f15();
          break;
        case 8:
          FUN_fffe4fa9();
          break;
        case 9:
          FUN_fffe5000();
          break;
        case 10:
          FUN_fffe50e0();
          break;
        case 0xb:
          FUN_fffe5137();
          break;
        case 0xc:
          FUN_fffe5138();
        }
      }
      DAT_00018871 = 0;
      DAT_0001b554 = bVar2;
    }
    if ((PTR_DAT_00025d78[0x1cb] == '\x01') && (bVar2 = swtimer_expired(0x37), bVar2 == 1)) {
      PTR_DAT_00025d78[0x1cb] = 0;
      PTR_DAT_00025d78[0x417] = 0;
      PTR_DAT_00025d78[0x1ca] = 0;
      PTR_DAT_00025d78[0x1c8] = 0;
      PTR_DAT_00025d78[0x2b] = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffe40e5 @ fffe40e5 (120 bytes)

void FUN_fffe40e5(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = DAT_00009dbd;
  bVar2 = vfo_mode(0);
  bVar3 = vfo_is_memory(bVar3);
  if (bVar3 == 1) {
    PTR_DAT_00025d78[0x46c] = 1;
    swtimer_start(0x38,0xfa);
    return;
  }
  uVar1 = (uint)bVar2;
  if ((3 < uVar1 - 4) && (uVar1 != 10 && uVar1 != 0xb)) {
    PTR_DAT_00025d78[0x46c] = 1;
    swtimer_start(0x38,5);
    return;
  }
  PTR_DAT_00025d78[0x46c] = 1;
  swtimer_start(0x38,0x32);
  return;
}


// ===== FUN_fffe415d @ fffe415d (61 bytes)

undefined1 FUN_fffe415d(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (PTR_DAT_00025d78[0x46c] == '\x01') {
    bVar1 = swtimer_expired(0x38);
    if (bVar1 == 1) {
      PTR_DAT_00025d78[0x46c] = 0;
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe419a @ fffe419a (89 bytes)

undefined1 FUN_fffe419a(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (DAT_00018871 == '\0') {
    DAT_00018871 = '\x01';
    swtimer_start(0x38,200);
    local_2 = 0;
  }
  else if (DAT_00018871 == '\x01') {
    bVar1 = swtimer_expired(0x38);
    if (bVar1 == 1) {
      DAT_00018871 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe41f3 @ fffe41f3 (6 bytes)

void FUN_fffe41f3(void)

{
  FUN_fffe4211(1);
  return;
}


// ===== FUN_fffe41f9 @ fffe41f9 (6 bytes)

void FUN_fffe41f9(void)

{
  FUN_fffe4211(2);
  return;
}


// ===== FUN_fffe41ff @ fffe41ff (6 bytes)

void FUN_fffe41ff(void)

{
  FUN_fffe4211(3);
  return;
}


// ===== FUN_fffe4205 @ fffe4205 (6 bytes)

void FUN_fffe4205(void)

{
  FUN_fffe4211(4);
  return;
}


// ===== FUN_fffe420b @ fffe420b (6 bytes)

void FUN_fffe420b(void)

{
  FUN_fffe4211(5);
  return;
}


// ===== FUN_fffe4211 @ fffe4211 (329 bytes)

void FUN_fffe4211(char param_1)

{
  bool bVar1;
  int iVar2;
  
  if (PTR_DAT_00025d78[0x90] != '\x01') {
    if (PTR_DAT_00025d78[0x93] == '\x01') {
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d78[0x417] == '\x01') {
      FUN_fffe4e6e(param_1);
      beep_request(1);
      return;
    }
    beep_request(1);
    iVar2 = FUN_fffe56bf();
    if (iVar2 == 1) {
      PTR_DAT_00025d78[0x1c7] = 0;
      if ((PTR_DAT_00025d78[0x78] == '\0') && (PTR_DAT_00025d78[0x417] == '\0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) || (PTR_DAT_00025d78[0x1ca] != '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (DAT_00020b2e == '\x01') {
          DAT_00020b2e = '\0';
        }
        PTR_DAT_00025d78[0x78] = 0;
        PTR_DAT_00025d78[0x417] = 0;
        PTR_DAT_00025d78[0x1ca] = 0;
        PTR_DAT_00025d78[0x1cb] = 0;
        return;
      }
      iVar2 = FUN_fffb521a();
      if (iVar2 == 1) {
        DAT_00020b2e = '\x01';
      }
      PTR_DAT_00025d78[0x78] = 1;
      PTR_DAT_00025d78[0x79] = param_1 + -1;
      PTR_DAT_00025d78[0x1c8] = param_1;
      return;
    }
    iVar2 = FUN_fffe5690();
    if (iVar2 == 1) {
      PTR_DAT_00025d78[0x1c7] = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffe435a @ fffe435a (6 bytes)

void FUN_fffe435a(void)

{
  FUN_fffe4378(1);
  return;
}


// ===== FUN_fffe4360 @ fffe4360 (6 bytes)

void FUN_fffe4360(void)

{
  FUN_fffe4378(2);
  return;
}

