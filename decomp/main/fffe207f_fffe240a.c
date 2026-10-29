// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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


// ===== FUN_fffe235b @ fffe235b (7 bytes)

void FUN_fffe235b(void)

{
  FUN_fffe2622(0x36);
  return;
}


// ===== FUN_fffe2362 @ fffe2362 (7 bytes)

void FUN_fffe2362(void)

{
  FUN_fffe2622(0x37);
  return;
}


// ===== FUN_fffe2369 @ fffe2369 (7 bytes)

void FUN_fffe2369(void)

{
  FUN_fffe2622(0x38);
  return;
}


// ===== FUN_fffe2370 @ fffe2370 (7 bytes)

void FUN_fffe2370(void)

{
  FUN_fffe2622(0x39);
  return;
}


// ===== FUN_fffe2377 @ fffe2377 (7 bytes)

void FUN_fffe2377(void)

{
  FUN_fffe2622(0x3a);
  return;
}


// ===== FUN_fffe237e @ fffe237e (7 bytes)

void FUN_fffe237e(void)

{
  FUN_fffe2622(0x3b);
  return;
}


// ===== FUN_fffe2385 @ fffe2385 (7 bytes)

void FUN_fffe2385(void)

{
  FUN_fffe2622(0x3c);
  return;
}


// ===== FUN_fffe238c @ fffe238c (7 bytes)

void FUN_fffe238c(void)

{
  FUN_fffe2622(0x3d);
  return;
}


// ===== FUN_fffe2393 @ fffe2393 (7 bytes)

void FUN_fffe2393(void)

{
  FUN_fffe2622(0x3e);
  return;
}


// ===== FUN_fffe239a @ fffe239a (7 bytes)

void FUN_fffe239a(void)

{
  FUN_fffe2622(0x3f);
  return;
}


// ===== FUN_fffe23a1 @ fffe23a1 (7 bytes)

void FUN_fffe23a1(void)

{
  FUN_fffe2622(0x40);
  return;
}


// ===== FUN_fffe23a8 @ fffe23a8 (7 bytes)

void FUN_fffe23a8(void)

{
  FUN_fffe2622(0x41);
  return;
}


// ===== FUN_fffe23af @ fffe23af (7 bytes)

void FUN_fffe23af(void)

{
  FUN_fffe2622(0x42);
  return;
}


// ===== FUN_fffe23b6 @ fffe23b6 (7 bytes)

void FUN_fffe23b6(void)

{
  FUN_fffe2622(0x43);
  return;
}


// ===== FUN_fffe23bd @ fffe23bd (7 bytes)

void FUN_fffe23bd(void)

{
  FUN_fffe2622(0x44);
  return;
}


// ===== FUN_fffe23c4 @ fffe23c4 (7 bytes)

void FUN_fffe23c4(void)

{
  FUN_fffe2622(0x45);
  return;
}


// ===== FUN_fffe23cb @ fffe23cb (7 bytes)

void FUN_fffe23cb(void)

{
  FUN_fffe2622(0x46);
  return;
}


// ===== FUN_fffe23d2 @ fffe23d2 (7 bytes)

void FUN_fffe23d2(void)

{
  FUN_fffe2622(0x47);
  return;
}


// ===== FUN_fffe23d9 @ fffe23d9 (7 bytes)

void FUN_fffe23d9(void)

{
  FUN_fffe2622(0x48);
  return;
}


// ===== FUN_fffe23e0 @ fffe23e0 (7 bytes)

void FUN_fffe23e0(void)

{
  FUN_fffe2622(0x49);
  return;
}


// ===== FUN_fffe23e7 @ fffe23e7 (7 bytes)

void FUN_fffe23e7(void)

{
  FUN_fffe2622(0x4a);
  return;
}


// ===== FUN_fffe23ee @ fffe23ee (7 bytes)

void FUN_fffe23ee(void)

{
  FUN_fffe2622(0x4b);
  return;
}


// ===== FUN_fffe23f5 @ fffe23f5 (7 bytes)

void FUN_fffe23f5(void)

{
  FUN_fffe2622(0x4c);
  return;
}


// ===== FUN_fffe23fc @ fffe23fc (7 bytes)

void FUN_fffe23fc(void)

{
  FUN_fffe2622(0x4d);
  return;
}


// ===== FUN_fffe2403 @ fffe2403 (7 bytes)

void FUN_fffe2403(void)

{
  FUN_fffe2622(0x4e);
  return;
}


// ===== FUN_fffe240a @ fffe240a (7 bytes)

void FUN_fffe240a(void)

{
  FUN_fffe2622(0x4f);
  return;
}

