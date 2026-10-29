// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffbe4d8 @ fffbe4d8 (8 bytes)

void FUN_fffbe4d8(void)

{
  FUN_fffc0b2f(0x180);
  return;
}


// ===== FUN_fffbe4e0 @ fffbe4e0 (8 bytes)

void FUN_fffbe4e0(void)

{
  FUN_fffc0b2f(0x181);
  return;
}


// ===== FUN_fffbe4e8 @ fffbe4e8 (46 bytes)

void FUN_fffbe4e8(void)

{
  byte bVar1;
  
  bVar1 = FUN_fff9cc3d();
  if (1 < bVar1) {
    FUN_fff9cc4c(bVar1 - 1);
    PTR_DAT_00025d54[0x99] = 1;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbe516 @ fffbe516 (46 bytes)

void FUN_fffbe516(void)

{
  byte bVar1;
  
  bVar1 = FUN_fff9cc3d();
  if (bVar1 < 3) {
    FUN_fff9cc4c(bVar1 + 1);
    PTR_DAT_00025d54[0x99] = 1;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbe544 @ fffbe544 (62 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbe57f) */

undefined4 FUN_fffbe544(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  PTR_DAT_00025d54[0x9a] = 0;
  FUN_fff9cc4c(1);
  PTR_DAT_00025d54[0x3ff] = 2;
  beep_request(1);
  puVar1 = PTR_DAT_00025d54;
  uVar2 = FUN_fffc523a(0,1,0);
  puVar1[0xa3] = (char)uVar2;
  return uVar2;
}


// ===== key_lock_pwr_press @ fffbe582 (17 bytes)

/* Front-panel key 0x300 LOCK/PWR, press handler (key tables, display/input.md key codes) (#70) */

void key_lock_pwr_press(void)

{
  if (DAT_00020b9b != '\x01') {
    return;
  }
  FUN_fffc2794();
  return;
}


// ===== key_lock_pwr_short @ fffbe593 (170 bytes)

/* Front-panel key 0x300 LOCK/PWR, short handler (key tables, display/input.md key codes) (#70) */

void key_lock_pwr_short(void)

{
  PTR_DAT_00025d54[0x2c] = 1;
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00009c62 == '\0') {
    DAT_00009c62 = 1;
    PTR_DAT_00025d54[0x1c2] = 0x47;
    FUN_fffc8cbb(0x47);
    FUN_fffc8d8c();
  }
  else {
    DAT_00009c62 = 0;
    PTR_DAT_00025d54[0x1c2] = 0x48;
    FUN_fffc8cbb(0x48);
    FUN_fffc8d8c();
  }
  beep_request(1);
  return;
}


// ===== key_lock_pwr_long @ fffbe63d (67 bytes)

/* Front-panel key 0x300 LOCK/PWR, long handler (key tables, display/input.md key codes) (#70) */

void key_lock_pwr_long(void)

{
  if (DAT_0001fa40 == 0x300) {
    if (PTR_DAT_00025d54[0x92] == '\x01') {
      PTR_DAT_00025d54[0x92] = 0;
      PTR_DAT_00025d54[0x91] = 1;
    }
    PTR_DAT_00025d54[0x2c] = 2;
    return;
  }
  return;
}


// ===== key_tune_press @ fffbe680 (60 bytes)

/* Front-panel key 0x301 TUNE, press handler (key tables, display/input.md key codes) (#70) */

void key_tune_press(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    beep_request(1);
    FUN_fffc5290();
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== key_tune_short @ fffbe6bc (216 bytes)

/* Front-panel key 0x301 TUNE, short handler (key tables, display/input.md key codes) (#70) */

void key_tune_short(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = DAT_00009ab8;
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (bVar1 == 3) {
    if (PTR_DAT_00025d54[0x408] == '\0') {
      FUN_fffed206(1);
      return;
    }
    if (PTR_DAT_00025d54[0x408] == '\x01') {
      FUN_fffed206(0);
      return;
    }
  }
  else {
    if (bVar1 == 2) {
      iVar2 = FUN_fffed6f5();
      if (iVar2 != 1) {
        beep_request(3);
        return;
      }
      iVar2 = FUN_fffec55a();
      if (iVar2 == 0) {
        FUN_fffec537(1);
        DAT_00020b3f = 4;
        return;
      }
      FUN_fffec537(0);
      DAT_00020b3f = 6;
      return;
    }
    if (bVar1 < 2) {
      if (DAT_00020b41 != '\0') {
        FUN_fffec52d();
        return;
      }
      iVar2 = FUN_fffec55a();
      if (iVar2 == 0) {
        FUN_fffec537(1);
        DAT_00020b3f = 1;
        return;
      }
      FUN_fffec537(0);
      DAT_00020b3f = 3;
      return;
    }
  }
  return;
}


// ===== key_tune_long @ fffbe794 (83 bytes)

/* Front-panel key 0x301 TUNE, long handler (key tables, display/input.md key codes) (#70) */

void key_tune_long(void)

{
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00009ab8 < 2) {
    if (DAT_00020b3d != '\0') {
      beep_request(3);
      return;
    }
    DAT_00020b41 = 1;
  }
  else if (DAT_00009ab8 == 2) {
    DAT_00020b40 = 1;
  }
  beep_request(2);
  return;
}


// ===== key_mox_vox_press @ fffbe7e7 (88 bytes)

/* Front-panel key 0x302 MOX/VOX, press handler (key tables, display/input.md key codes) (#70) */

void key_mox_vox_press(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if ((DAT_0001b4d9 != '\0') && (DAT_0001b4d9 != '\x01')) {
    PTR_DAT_00025d54[0x28] = 0;
    return;
  }
  return;
}


// ===== key_mox_vox_short @ fffbe83f (147 bytes)

/* Front-panel key 0x302 MOX/VOX, short handler (key tables, display/input.md key codes) (#70) */

void key_mox_vox_short(void)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if ((DAT_0001b4d9 == '\0') || (DAT_0001b4d9 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    DAT_0001b4d9 = 0;
    return;
  }
  bVar2 = vfo_mode(1);
  uVar3 = (uint)bVar2;
  if ((1 < uVar3 - 2) && (uVar3 != 0xc && uVar3 != 0xd)) {
    DAT_00009c5d = DAT_00009c5d == '\0';
    beep_request(1);
    swtimer_start(0x2f,100);
    return;
  }
  beep_request(3);
  return;
}


// ===== key_mox_vox_long @ fffbe8d2 (93 bytes)

/* Front-panel key 0x302 MOX/VOX, long handler (key tables, display/input.md key codes) (#70) */

void key_mox_vox_long(void)

{
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_0001b4d9 == '\0') {
    DAT_0001b4d9 = 2;
    PTR_DAT_00025d54[0x28] = 1;
    return;
  }
  if (DAT_0001b4d9 == '\x01') {
    DAT_0001b4d9 = 2;
    PTR_DAT_00025d54[0x28] = 1;
    return;
  }
  DAT_0001b4d9 = 0;
  return;
}


// ===== key_nb_press @ fffbe92f (60 bytes)

/* Front-panel key 0x303 NB, press handler (key tables, display/input.md key codes) (#70) */

void key_nb_press(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    beep_request(1);
    FUN_fffc5290();
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== key_nb_short @ fffbe96b (107 bytes)

/* Front-panel key 0x303 NB, short handler (key tables, display/input.md key codes) (#70) */

void key_nb_short(void)

{
  byte bVar1;
  byte *pbStack_4;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (PTR_DAT_00025d54[0x96] == '\x01') {
    FUN_fffc3c85();
  }
  if (DAT_00009dbd == '\0') {
    pbStack_4 = &DAT_00009d0b;
  }
  else {
    pbStack_4 = &DAT_00009d65;
  }
  bVar1 = *pbStack_4;
  if ((bVar1 & 2) == 0) {
    *pbStack_4 = bVar1 | 2;
  }
  else {
    *pbStack_4 = bVar1 & 0xfd;
  }
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== key_nb_long @ fffbe9d6 (198 bytes)

/* Front-panel key 0x303 NB, long handler (key tables, display/input.md key codes) (#70) */

void key_nb_long(void)

{
  bool bVar1;
  byte *pbStack_4;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (PTR_DAT_00025d54[0x96] == '\x01') {
    FUN_fffc3c85();
  }
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '8')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_00009dc0 = 0;
    FUN_fffc8cbb(0x38);
    FUN_fffc8d8c();
    beep_request(1);
    return;
  }
  PTR_DAT_00025d54[0x1c2] = 0x38;
  FUN_fffc8cbb(0x38);
  FUN_fffc8d8c();
  if (DAT_00009dbd == '\0') {
    pbStack_4 = &DAT_00009d0b;
  }
  else {
    pbStack_4 = &DAT_00009d65;
  }
  *pbStack_4 = *pbStack_4 | 2;
  PTR_DAT_00025d54[0x40c] = 1;
  beep_request(2);
  return;
}


// ===== key_dnr_press @ fffbea9c (144 bytes)

/* Front-panel key 0x304 DNR, press handler (key tables, display/input.md key codes) (#70) */

void key_dnr_press(void)

{
  bool bVar1;
  byte bVar2;
  
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  bVar2 = vfo_mode(0);
  if ((bVar2 == 6) || (bVar2 == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar2 == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar2 == 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  beep_request(1);
  FUN_fffc5290();
  return;
}


// ===== key_dnr_short @ fffbeb2c (119 bytes)

/* Front-panel key 0x304 DNR, short handler (key tables, display/input.md key codes) (#70) */

void key_dnr_short(void)

{
  byte bVar1;
  bool bStack_5;
  byte *pbStack_4;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (PTR_DAT_00025d54[0x96] == '\x01') {
    FUN_fffc3c85();
  }
  if (DAT_00009dbd == '\0') {
    pbStack_4 = &DAT_00009d0f;
  }
  else {
    pbStack_4 = &DAT_00009d69;
  }
  bVar1 = *pbStack_4;
  bStack_5 = (bVar1 & 0x10) != 0;
  if (bStack_5) {
    *pbStack_4 = bVar1 & 0xef;
  }
  else {
    *pbStack_4 = bVar1 | 0x10;
  }
  bStack_5 = !bStack_5;
  FUN_fffc5127(bStack_5);
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== key_dnr_long @ fffbeba3 (201 bytes)

/* Front-panel key 0x304 DNR, long handler (key tables, display/input.md key codes) (#70) */

void key_dnr_long(void)

{
  bool bVar1;
  byte *pbStack_4;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (PTR_DAT_00025d54[0x96] == '\x01') {
    FUN_fffc3c85();
  }
  if (DAT_00009dbd == '\0') {
    pbStack_4 = &DAT_00009d0f;
  }
  else {
    pbStack_4 = &DAT_00009d69;
  }
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '9')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *pbStack_4 = *pbStack_4 & 0xf1 | 1;
    PTR_DAT_00025d54[0x40c] = 1;
  }
  else {
    PTR_DAT_00025d54[0x1c2] = 0x39;
    if ((*pbStack_4 & 0x10) == 0) {
      *pbStack_4 = *pbStack_4 | 0x10;
      PTR_DAT_00025d54[0x40c] = 1;
    }
  }
  FUN_fffc8cbb(0x39);
  FUN_fffc8d8c();
  beep_request(2);
  return;
}


// ===== key_split_press @ fffbec6c (57 bytes)

/* Front-panel key 0x305 SPLIT, press handler (key tables, display/input.md key codes) (#70) */

void key_split_press(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== split_toggle @ fffbeca5 (352 bytes)

/* FT/ST: toggle 0x9C5E, save/restore 0x9DBE/0x9DBF */

void split_toggle(void)

{
  char cVar1;
  char *pcStack_4;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  FUN_fffe3d24();
  if (DAT_00009c5e == '\x01') {
    DAT_00009c5e = 0;
    DAT_00009dbe = PTR_DAT_00025d54[0x484];
    DAT_00009dbf = PTR_DAT_00025d54[0x485];
    PTR_DAT_00025d54[0x483] = 0;
    DAT_00020f09 = 0;
    FUN_fff9cdb0('\0');
    goto LAB_fffbede9;
  }
  if (DAT_00009dbd == '\0') {
    pcStack_4 = &DAT_00009dbe;
  }
  else {
    pcStack_4 = &DAT_00009dbf;
  }
  cVar1 = *pcStack_4;
  if (cVar1 == '\x02') {
LAB_fffbed59:
    vm_toggle_core();
  }
  else if (cVar1 == '\x04') {
    *pcStack_4 = '\x01';
  }
  else if ((cVar1 == '\x05') || (cVar1 == '\a' || cVar1 == '\b')) goto LAB_fffbed59;
  DAT_00009c5e = 1;
  PTR_DAT_00025d54[0x484] = DAT_00009dbe;
  PTR_DAT_00025d54[0x485] = DAT_00009dbf;
  DAT_00009dc7 = DAT_00009dbe;
  DAT_00009dc8 = DAT_00009dbf;
  if (DAT_00009dbd == '\0') {
    PTR_DAT_00025d54[0x425] = 0;
  }
  else {
    PTR_DAT_00025d54[0x426] = 0;
  }
  if (PTR_DAT_00025d54[0x482] == '\x01') {
    FUN_fff9cdb0('\0');
  }
  else {
    FUN_fff9cdb0('\x01');
  }
LAB_fffbede9:
  PTR_DAT_00025d54[0x425] = 0;
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== key_split_long @ fffbee05 (77 bytes)

/* Front-panel key 0x305 SPLIT, long handler (key tables, display/input.md key codes) (#70) */

void key_split_long(void)

{
  if (DAT_00009c5e == '\x01') {
    if (DAT_00020b9b == '\x01') {
      FUN_fffc2794();
    }
    if (PTR_DAT_00025d54[0x482] == '\0') {
      PTR_DAT_00025d54[0x482] = 1;
      FUN_fff9cdb0('\0');
    }
    else {
      PTR_DAT_00025d54[0x482] = 0;
      FUN_fff9cdb0('\x01');
    }
    beep_request(2);
    return;
  }
  return;
}


// ===== key_clar_press @ fffbee52 (87 bytes)

/* Front-panel key 0x306 CLAR, press handler (key tables, display/input.md key codes) (#70) */

void key_clar_press(void)

{
  byte bVar1;
  
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  bVar1 = vfo_tune_locked('\x02');
  if (bVar1 != 1) {
    beep_request(1);
    return;
  }
  beep_request(3);
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== key_clar_short @ fffbeea9 (247 bytes)

/* Front-panel key 0x306 CLAR, short handler (key tables, display/input.md key codes) (#70) */

void key_clar_short(void)

{
  bool bVar1;
  byte bVar2;
  byte *pbStack_c;
  char *pcStack_8;
  char cStack_2;
  bool bStack_1;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00009dbd == '\0') {
    pcStack_8 = PTR_DAT_00025d54 + 0x425;
    pbStack_c = &DAT_00009d0a;
    cStack_2 = DAT_00009dbe;
  }
  else {
    pcStack_8 = PTR_DAT_00025d54 + 0x426;
    pbStack_c = &DAT_00009d64;
    cStack_2 = DAT_00009dbf;
  }
  bStack_1 = DAT_00009dbd != '\0';
  if ((cStack_2 == '\x02') && (bVar2 = memch_current_valid(bStack_1), bVar2 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    beep_request(3);
    return;
  }
  if (*pcStack_8 == '\0') {
    *pcStack_8 = '\x01';
    *pbStack_c = *pbStack_c | 0x10;
    FUN_fffc3502();
  }
  else if (*pcStack_8 == '\x01') {
    *pcStack_8 = *pcStack_8 + '\x01';
    *pbStack_c = *pbStack_c & 0xef | 8;
  }
  else if (*pcStack_8 == '\x02') {
    *pcStack_8 = *pcStack_8 + '\x01';
    *pbStack_c = *pbStack_c | 0x18;
  }
  else {
    *pcStack_8 = '\0';
    *pbStack_c = *pbStack_c & 0xe7;
  }
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== key_clar_long @ fffbefa0 (109 bytes)

/* Front-panel key 0x306 CLAR, long handler (key tables, display/input.md key codes) (#70) */

void key_clar_long(void)

{
  bool bStack_1;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00009dbd == '\0') {
    DAT_00009d51 = 0;
    DAT_00009d52 = 0;
  }
  else {
    DAT_00009dab = 0;
    DAT_00009dac = 0;
  }
  bStack_1 = DAT_00009dbd != '\0';
  vfo_mark_edited(bStack_1);
  PTR_DAT_00025d54[0x40c] = 1;
  beep_request(2);
  return;
}


// ===== key_zin_spot_press @ fffbf00d (169 bytes)

/* Front-panel key 0x307 ZIN/SPOT, press handler (key tables, display/input.md key codes) (#70) */

void key_zin_spot_press(void)

{
  bool bVar1;
  byte *pbVar2;
  
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  pbVar2 = vfo_rec_ptr(PTR_DAT_00025d54[0x67]);
  if (((*pbVar2 & 0xf) == 2) || ((*pbVar2 & 0xf) == 3)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    PTR_DAT_00025d54[0x409] = 1;
    if (DAT_00020b9b == '\x01') {
      FUN_fffc2794();
      beep_request(1);
      return;
    }
    beep_request(3);
    return;
  }
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  beep_request(1);
  return;
}


// ===== key_zin_spot_short @ fffbf0b6 (286 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbf119) */
/* WARNING: Removing unreachable block (ram,0xfffbf120) */
/* Front-panel key 0x307 ZIN/SPOT, short handler (key tables, display/input.md key codes) (#70) */

void key_zin_spot_short(void)

{
  int iVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  uint uStack_c;
  bool bStack_5;
  byte *pbStack_4;
  
  if (DAT_00009dbd == '\0') {
    pbStack_4 = &DAT_00009d09;
  }
  else {
    pbStack_4 = &DAT_00009d63;
  }
  bStack_5 = DAT_00009dbd != '\0';
  uVar3 = dsp_tune_offset();
  if (((short)uVar3 < -0x23) || (0x23 < (short)uVar3)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    iVar1 = (int)(short)(uVar3 * 10);
    if ((*pbStack_4 & 0xf) == 2) {
      iVar1 = -iVar1;
    }
    uStack_c = ((uint)pbStack_4[0x4a] << 0x18 | (uint)pbStack_4[0x4b] << 0x10 |
                (uint)pbStack_4[0x4c] << 8 | (uint)pbStack_4[0x4d]) + iVar1;
    DAT_0001b4e2 = 1;
    uVar4 = freq_clamp(bStack_5,uStack_c);
    DAT_0001b4e2 = 0;
    if (PTR_DAT_00025d54[0x469] != '\x01') {
      pbStack_4[0x4a] = (byte)(uVar4 >> 0x18);
      pbStack_4[0x4b] = (byte)(uVar4 >> 0x10);
      pbStack_4[0x4c] = (byte)(uVar4 >> 8);
      uStack_c._0_1_ = (byte)uVar4;
      pbStack_4[0x4d] = (byte)uStack_c;
      if (bStack_5) {
        if (DAT_00009dbf == '\x02') {
          FUN_fffc2efb(1);
        }
      }
      else if (DAT_00009dbe == '\x02') {
        FUN_fffc2efb(0);
      }
      vfo_mark_edited(bStack_5);
      vfo_store_back(bStack_5);
      PTR_DAT_00025d54[0x40c] = 1;
      return;
    }
  }
  return;
}


// ===== key_zin_spot_long @ fffbf1d4 (55 bytes)

/* Front-panel key 0x307 ZIN/SPOT, long handler (key tables, display/input.md key codes) (#70) */

void key_zin_spot_long(void)

{
  byte *pbVar1;
  int iVar2;
  
  PTR_DAT_00025d54[0x409] = 1;
  pbVar1 = vfo_rec_ptr(1);
  iVar2 = FUN_fffc3e3c(pbVar1);
  if (iVar2 == 0) {
    return;
  }
  PTR_DAT_00025d54[0x407] = 1;
  beep_request(4);
  return;
}


// ===== key_m_to_v_press @ fffbf20b (41 bytes)

/* Front-panel key 0x308 M>V, press handler (key tables, display/input.md key codes) (#70) */

void key_m_to_v_press(void)

{
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== key_m_to_v_short @ fffbf234 (26 bytes)

/* Front-panel key 0x308 M>V, short handler (key tables, display/input.md key codes) (#70) */

void key_m_to_v_short(void)

{
  char cVar1;
  
  FUN_fffe3d24();
  cVar1 = FUN_fffc2426();
  if (cVar1 == '\x01') {
    return;
  }
  beep_request(3);
  return;
}


// ===== key_m_to_v_long @ fffbf24e (424 bytes)

/* Front-panel key 0x308 M>V, long handler (key tables, display/input.md key codes) (#70) */

void key_m_to_v_long(void)

{
  bool bVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  byte *pbStack_c;
  undefined1 *puStack_8;
  byte bStack_2;
  char cStack_1;
  
  cStack_1 = DAT_00009dbd;
  if (DAT_00009dbd == '\0') {
    if (DAT_00009dbe == '\x05') {
      DAT_00009dbe = 1;
      vfo_reload(0);
      beep_request(2);
      return;
    }
  }
  else if (DAT_00009dbf == '\x05') {
    DAT_00009dbf = 1;
    vfo_reload(1);
    beep_request(2);
    return;
  }
  if (PTR_DAT_00025d54[0x97] == '\x01') {
    bStack_2 = PTR_DAT_00025d54[0x43a];
  }
  else if (DAT_00009dbd == '\0') {
    bStack_2 = DAT_000060ca;
  }
  else {
    bStack_2 = DAT_000060c9;
  }
  if (DAT_00009c5e == '\x01') {
    DAT_00009c5e = '\0';
    if (DAT_00009dbd == '\0') {
      DAT_00009dbe = DAT_00020f88;
      DAT_00009dbf = '\x01';
    }
    else {
      DAT_00009dbf = DAT_00020f89;
      DAT_00009dbe = '\x01';
    }
  }
  else if (DAT_00009dbd == '\0') {
    DAT_00009dbf = '\x01';
  }
  else {
    DAT_00009dbe = '\x01';
  }
  uVar2 = dest_code_get();
  if (uVar2 == 0x315b) {
    if ((bStack_2 < 0x75) || (0x83 < bStack_2)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      beep_request(3);
      return;
    }
  }
  bVar1 = memch_valid(bStack_2,&pbStack_c);
  if (!bVar1) {
    beep_request(3);
    return;
  }
  puStack_8 = &DAT_00006150 + (uint)bStack_2 * 0x5a;
  if (cStack_1 == '\0') {
    puVar3 = &DAT_00009d63;
    puVar4 = puStack_8;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    vfo_store_back(0);
  }
  else {
    puVar3 = &DAT_00009d09;
    puVar4 = puStack_8;
    for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    vfo_store_back(1);
  }
  FUN_fffc2794();
  beep_request(2);
  return;
}


// ===== key_vm_mw_press @ fffbf3f6 (41 bytes)

/* Front-panel key 0x309 V/M W, press handler (key tables, display/input.md key codes) (#70) */

void key_vm_mw_press(void)

{
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== vm_toggle @ fffbf41f (28 bytes)

/* V/M key */

void vm_toggle(void)

{
  if (DAT_00020b9b != '\x01') {
    FUN_fffe3d24();
    vm_toggle_core();
    FUN_fffec578();
    return;
  }
  FUN_fffc2794();
  return;
}


// ===== key_vm_mw_long @ fffbf43b (71 bytes)

/* Front-panel key 0x309 V/M W, long handler (key tables, display/input.md key codes) (#70) */

void key_vm_mw_long(void)

{
  if (PTR_DAT_00025d54[0x70] == '\x01') {
    PTR_DAT_00025d54[0x70] = 0;
  }
  if (PTR_DAT_00025d54[0x97] == '\0') {
    FUN_fffbc638();
    FUN_fffc3c85();
    FUN_fffc23b6();
    FUN_fffc4caa();
    FUN_fffc29f3();
    FUN_fffc2b12();
    beep_request(2);
    return;
  }
  FUN_fffc2b94();
  return;
}


// ===== key_a_b_press @ fffbf482 (57 bytes)

/* Front-panel key 0x30A A/B, press handler (key tables, display/input.md key codes) (#70) */

void key_a_b_press(void)

{
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    FUN_fffc8beb();
    FUN_fffbc638();
    FUN_fffc3c85();
    FUN_fffc23b6();
    FUN_fffc4caa();
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== vfo_ab_toggle @ fffbf4bb (283 bytes)

/* SV/VS: flip 0x9DBD in VFO state, else step toward VFO */

void vfo_ab_toggle(void)

{
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  FUN_fffe3d24();
  DAT_00009c5e = 0;
  if (DAT_00009dbd == '\0') {
    if (DAT_00009dbe == '\x03') {
      vm_toggle();
      vm_toggle();
    }
    else if (DAT_00009dbe == '\x05') {
      DAT_00009dbe = '\x01';
      vfo_reload(0);
    }
    else if (DAT_00009dbe == '\x01') {
      DAT_00009dbd = '\x01';
      PTR_DAT_00025d54[0x443] = 1;
      PTR_DAT_00025d54[0x445] = 1;
    }
    else {
      vm_toggle();
    }
  }
  else if (DAT_00009dbf == '\x03') {
    vm_toggle();
    vm_toggle();
  }
  else if (DAT_00009dbf == '\x05') {
    DAT_00009dbf = '\x01';
    vfo_reload(1);
  }
  else if (DAT_00009dbf == '\x01') {
    DAT_00009dbd = '\0';
    PTR_DAT_00025d54[0x443] = 1;
    PTR_DAT_00025d54[0x445] = 1;
  }
  else {
    vm_toggle();
  }
  FUN_fffec578();
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== key_a_b_long @ fffbf5d6 (42 bytes)

/* Front-panel key 0x30A A/B, long handler (key tables, display/input.md key codes) (#70) */

void key_a_b_long(void)

{
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00009dbd == '\0') {
    FUN_fffc2d05();
  }
  else {
    FUN_fffc2f50();
  }
  beep_request(2);
  return;
}


// ===== key_band_press @ fffbf600 (47 bytes)

/* Front-panel key 0x30B BAND, press handler (key tables, display/input.md key codes) (#70) */

void key_band_press(void)

{
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== key_band_short @ fffbf62f (146 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbf6be) */
/* Front-panel key 0x30B BAND, short handler (key tables, display/input.md key codes) (#70) */

void key_band_short(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined1 uVar3;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  FUN_fffe3d24();
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\f')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
  }
  else {
    PTR_DAT_00025d54[0x41e] = 0;
    FUN_fffc8cbb(0xc);
    FUN_fffc8d8c();
    PTR_DAT_00025d54[0x1c2] = 0xc;
    puVar2 = PTR_DAT_00025d54;
    uVar3 = FUN_fffc3006();
    puVar2[0x1dc] = uVar3;
    PTR_DAT_00025d54[0x424] = PTR_DAT_00025d54[0x1dc];
  }
  beep_request(1);
  return;
}


// ===== key_mode_press @ fffbf6c1 (7 bytes)

/* Front-panel key 0x30C MODE, press handler (key tables, display/input.md key codes) (#70) */

void key_mode_press(void)

{
  beep_request(1);
  return;
}


// ===== key_mode_short @ fffbf6c8 (223 bytes)

/* Front-panel key 0x30C MODE, short handler (key tables, display/input.md key codes) (#70) */

void key_mode_short(void)

{
  bool bVar1;
  byte *pbStack_4;
  
  if (DAT_00020b97 != '\0') {
    DAT_00020b97 = '\0';
  }
  FUN_fffe3d24();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x05')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
    return;
  }
  if (DAT_00009dbd == '\0') {
    pbStack_4 = &DAT_00009d09;
  }
  else {
    pbStack_4 = &DAT_00009d63;
  }
  PTR_DAT_00025d54[0x424] = *pbStack_4 & 0xf;
  FUN_fffc8cbb(5);
  FUN_fffc8d8c();
  PTR_DAT_00025d54[0x1c2] = 5;
  return;
}


// ===== key_mode_long @ fffbf7a7 (48 bytes)

/* Front-panel key 0x30C MODE, long handler (key tables, display/input.md key codes) (#70) */

void key_mode_long(void)

{
  if (PTR_DAT_00025d54[0xa6] != '\0') {
    PTR_DAT_00025d54[0x85] = 1;
    FUN_fffc8f8b(1000);
    beep_request(2);
    return;
  }
  beep_request(3);
  return;
}


// ===== key_nar_press @ fffbf7d7 (48 bytes)

/* Front-panel key 0x30D NAR, press handler (key tables, display/input.md key codes) (#70) */

void key_nar_press(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== key_nar_short @ fffbf807 (231 bytes)

/* Front-panel key 0x30D NAR, short handler (key tables, display/input.md key codes) (#70) */

void key_nar_short(void)

{
  bool bVar1;
  byte bStack_d;
  byte *pbStack_c;
  bool bStack_5;
  byte *pbStack_4;
  
  bVar1 = false;
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00009dbd == '\0') {
    pbStack_4 = &DAT_00009d09;
    pbStack_c = &DAT_00009d0d;
  }
  else {
    pbStack_4 = &DAT_00009d63;
    pbStack_c = &DAT_00009d67;
  }
  bStack_5 = DAT_00009dbd != '\0';
  switch(*pbStack_4 & 0xf) {
  case 0:
  case 1:
    bVar1 = true;
    bStack_d = 0x80;
    break;
  case 2:
  case 3:
    bVar1 = true;
    bStack_d = 0x20;
    break;
  case 4:
    FUN_fffc0e3e();
    break;
  case 5:
    FUN_fffc0e31();
    break;
  case 6:
    FUN_fffc0e58();
    break;
  case 7:
    FUN_fffc0e4b();
    break;
  case 8:
  case 9:
  case 0xe:
    bVar1 = true;
    bStack_d = 4;
    break;
  case 10:
    FUN_fffc0e72();
    break;
  case 0xb:
    FUN_fffc0e65();
    break;
  case 0xc:
  case 0xd:
    bVar1 = true;
    bStack_d = 8;
  }
  if (bVar1) {
    if ((bStack_d & *pbStack_c) == 0) {
      *pbStack_c = bStack_d | *pbStack_c;
    }
    else {
      *pbStack_c = ~bStack_d & *pbStack_c;
    }
    vfo_mark_edited(bStack_5);
    vfo_store_back(bStack_5);
    PTR_DAT_00025d54[0x40c] = 1;
  }
  beep_request(1);
  return;
}


// ===== key_qmb_press @ fffbf8ee (54 bytes)

/* Front-panel key 0x30E QMB, press handler (key tables, display/input.md key codes) (#70) */

void key_qmb_press(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    beep_request(1);
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== qmb_recall @ fffbf924 (416 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbf95a) */
/* QR: leave split, enter state 5, load slot */

void qmb_recall(void)

{
  int iVar1;
  byte bStack_3;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  if (DAT_00020b98 != '\0') {
    FUN_fffe3d24();
    DAT_00020b98 = '\0';
  }
  if ((CONCAT11(DAT_00009012,DAT_00009013) & 0x3ff) != 0) {
    if (DAT_00009c5e == '\x01') {
      DAT_00009c5e = '\0';
      DAT_00009dbe = PTR_DAT_00025d54[0x484];
      DAT_00009dbf = PTR_DAT_00025d54[0x485];
      PTR_DAT_00025d54[0x483] = 0;
      DAT_00020f09 = 0;
    }
    if (DAT_00009dbd == '\0') {
      bStack_3 = 0;
      if (DAT_00009dbe != '\x05') {
        FUN_fffc34d8(0);
      }
    }
    else {
      bStack_3 = 1;
      if (DAT_00009dbf != '\x05') {
        FUN_fffc34d8(1);
      }
    }
    iVar1 = FUN_fffc302b(bStack_3);
    if (iVar1 == 0) {
      if (bStack_3 == 0) {
        PTR_DAT_00025d54[0x443] = 0;
        PTR_DAT_00025d54[0x444] = 0;
      }
      else {
        PTR_DAT_00025d54[0x445] = 0;
        PTR_DAT_00025d54[0x446] = 0;
      }
    }
    vfo_enter_vfo_state(bStack_3);
    iVar1 = FUN_fffc30af(bStack_3);
    if (iVar1 == 1) {
      qmb_set_depth(bStack_3);
      vfo_store_back(bStack_3);
    }
    if (bStack_3 == 0) {
      if (DAT_0000901f != '\0') {
        qmb_enter(0);
        return;
      }
      DAT_00009dbe = '\x01';
    }
    else {
      if (DAT_00009021 != '\0') {
        qmb_enter(1);
        return;
      }
      DAT_00009dbf = '\x01';
    }
    qmb_set_depth(bStack_3);
    vfo_reload(bStack_3);
    PTR_DAT_00025d54[0x40b] = 1;
    FUN_fffec578();
    FUN_fffc8beb();
    return;
  }
  beep_request(3);
  return;
}


// ===== qmb_store @ fffbfac4 (371 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbfb0d) */
/* QI: operating record -> QMB slot (0x9023+n*0x5A), mask 0x9012 */

void qmb_store(void)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  undefined *puVar4;
  int iVar5;
  undefined1 *puStack_10;
  bool bStack_5;
  ushort uStack_4;
  byte bStack_2;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  bVar1 = DAT_00009dbd != '\0';
  bVar3 = vfo_is_memory(bVar1);
  if ((bVar3 == 1) && (bVar3 = memch_current_is_special(bVar1), bVar3 == 1)) {
    beep_request(3);
    return;
  }
  uStack_4 = CONCAT11(DAT_00009012,DAT_00009013) & 0x3ff;
  if (uStack_4 == 0x3ff) {
    bStack_2 = DAT_0000901e;
  }
  else {
    bStack_5 = false;
    for (; (bStack_5 < 10 && ((uStack_4 & 1) != 0)); uStack_4 = uStack_4 >> 1) {
      bStack_5 = (bool)(bStack_5 + 1);
    }
    bStack_2 = bStack_5;
  }
  for (bStack_5 = false; bStack_5 < 9; bStack_5 = (bool)(bStack_5 + 1)) {
    (&DAT_0000901e)[-(uint)bStack_5] = *(undefined1 *)(0x901d - (uint)bStack_5);
  }
  DAT_00009015 = bStack_2;
  puVar4 = &DAT_00009023 + (uint)bStack_2 * 0x5a;
  if (bVar1) {
    puStack_10 = &DAT_00009d63;
  }
  else {
    puStack_10 = &DAT_00009d09;
  }
  for (iVar5 = 0x5a; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = *puStack_10;
    puVar4 = puVar4 + 1;
    puStack_10 = puStack_10 + 1;
  }
  bVar2 = 7 < bStack_2;
  if (bVar2) {
    bStack_2 = bStack_2 - 8;
  }
  bStack_5 = !bVar2;
  (&DAT_00009012)[bStack_5] = (byte)(1 << (bStack_2 & 0x1f)) | (&DAT_00009012)[bStack_5];
  FUN_fffc3408(bVar1);
  if (DAT_00009014 < 10) {
    DAT_00009014 = DAT_00009014 + 1;
  }
  FUN_fffc34d8(bVar1);
  beep_request(5);
  FUN_fffc33ef();
  PTR_DAT_00025d54[0x47f] = DAT_00009015 + 1;
  return;
}


// ===== key_func_press @ fffbfc37 (224 bytes)

/* Front-panel key 0x30F FUNC, press handler (key tables, display/input.md key codes) (#70) */

void key_func_press(void)

{
  int iVar1;
  
  if (PTR_DAT_00025d54[0xba] == '\x01') {
    beep_request(1);
    return;
  }
  if (PTR_DAT_00025d54[0x86] == '\x01') {
    FUN_fffd00ac();
    beep_request(1);
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x95] == '\x01') {
    if (PTR_DAT_00025d54[0x88] == '\x01') {
      iVar1 = FUN_fffd1ba6();
      if (iVar1 == 1) {
        beep_request(1);
      }
    }
    else {
      iVar1 = FUN_fffd1abd();
      if (iVar1 == 1) {
        beep_request(1);
      }
    }
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if ((PTR_DAT_00025d54[0x93] != '\x01') && (PTR_DAT_00025d54[0x94] != '\x01')) {
    if (PTR_DAT_00025d54[0x97] == '\x01') {
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d54[0x418] == '\x01') {
      scan_stop();
      PTR_DAT_00025d54[0x409] = 1;
      return;
    }
    if (PTR_DAT_00025d54[0x96] == '\0') {
      beep_request(1);
      return;
    }
  }
  return;
}


// ===== key_func_short @ fffbfd17 (10 bytes)

/* Front-panel key 0x30F FUNC, short handler (key tables, display/input.md key codes) (#70) */

void key_func_short(void)

{
  DAT_0001b4dd = 1;
  return;
}

