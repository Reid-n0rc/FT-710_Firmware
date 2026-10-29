// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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


// ===== FUN_fffe22c1 @ fffe22c1 (7 bytes)

void FUN_fffe22c1(void)

{
  FUN_fffe2622(0x20);
  return;
}


// ===== FUN_fffe22c8 @ fffe22c8 (7 bytes)

void FUN_fffe22c8(void)

{
  FUN_fffe2622(0x21);
  return;
}


// ===== FUN_fffe22cf @ fffe22cf (7 bytes)

void FUN_fffe22cf(void)

{
  FUN_fffe2622(0x22);
  return;
}


// ===== FUN_fffe22d6 @ fffe22d6 (7 bytes)

void FUN_fffe22d6(void)

{
  FUN_fffe2622(0x23);
  return;
}


// ===== FUN_fffe22dd @ fffe22dd (7 bytes)

void FUN_fffe22dd(void)

{
  FUN_fffe2622(0x24);
  return;
}


// ===== FUN_fffe22e4 @ fffe22e4 (7 bytes)

void FUN_fffe22e4(void)

{
  FUN_fffe2622(0x25);
  return;
}


// ===== FUN_fffe22eb @ fffe22eb (7 bytes)

void FUN_fffe22eb(void)

{
  FUN_fffe2622(0x26);
  return;
}


// ===== FUN_fffe22f2 @ fffe22f2 (7 bytes)

void FUN_fffe22f2(void)

{
  FUN_fffe2622(0x27);
  return;
}


// ===== FUN_fffe22f9 @ fffe22f9 (7 bytes)

void FUN_fffe22f9(void)

{
  FUN_fffe2622(0x28);
  return;
}


// ===== FUN_fffe2300 @ fffe2300 (7 bytes)

void FUN_fffe2300(void)

{
  FUN_fffe2622(0x29);
  return;
}


// ===== FUN_fffe2307 @ fffe2307 (7 bytes)

void FUN_fffe2307(void)

{
  FUN_fffe2622(0x2a);
  return;
}


// ===== FUN_fffe230e @ fffe230e (7 bytes)

void FUN_fffe230e(void)

{
  FUN_fffe2622(0x2b);
  return;
}


// ===== FUN_fffe2315 @ fffe2315 (7 bytes)

void FUN_fffe2315(void)

{
  FUN_fffe2622(0x2c);
  return;
}


// ===== FUN_fffe231c @ fffe231c (7 bytes)

void FUN_fffe231c(void)

{
  FUN_fffe2622(0x2d);
  return;
}


// ===== FUN_fffe2323 @ fffe2323 (7 bytes)

void FUN_fffe2323(void)

{
  FUN_fffe2622(0x2e);
  return;
}


// ===== FUN_fffe232a @ fffe232a (7 bytes)

void FUN_fffe232a(void)

{
  FUN_fffe2622(0x2f);
  return;
}


// ===== FUN_fffe2331 @ fffe2331 (7 bytes)

void FUN_fffe2331(void)

{
  FUN_fffe2622(0x30);
  return;
}


// ===== FUN_fffe2338 @ fffe2338 (7 bytes)

void FUN_fffe2338(void)

{
  FUN_fffe2622(0x31);
  return;
}


// ===== FUN_fffe233f @ fffe233f (7 bytes)

void FUN_fffe233f(void)

{
  FUN_fffe2622(0x32);
  return;
}


// ===== FUN_fffe2346 @ fffe2346 (7 bytes)

void FUN_fffe2346(void)

{
  FUN_fffe2622(0x33);
  return;
}


// ===== FUN_fffe234d @ fffe234d (7 bytes)

void FUN_fffe234d(void)

{
  FUN_fffe2622(0x34);
  return;
}


// ===== FUN_fffe2354 @ fffe2354 (7 bytes)

void FUN_fffe2354(void)

{
  FUN_fffe2622(0x35);
  return;
}

