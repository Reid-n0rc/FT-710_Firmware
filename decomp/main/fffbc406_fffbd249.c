// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== key_call_repeat @ fffbc406 (47 bytes)

/* JSR key_repeat_table[code] */

void key_call_repeat(void)

{
  char cVar1;
  
  cVar1 = FUN_fffc519d(DAT_0001fa40,0);
  if (cVar1 == '\0') {
    return;
  }
  (*(code *)(&key_repeat_table)[DAT_0001fa40])();
  return;
}


// ===== key_call_release @ fffbc435 (47 bytes)

/* JSR key_release_table[code] */

void key_call_release(void)

{
  char cVar1;
  
  cVar1 = FUN_fffc519d(DAT_0001fa40,0);
  if (cVar1 == '\0') {
    return;
  }
  (*(code *)(&key_release_table)[DAT_0001fa40])();
  return;
}


// ===== key_touch_scope_tune @ fffbc464 (405 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbc507) */
/* WARNING: Removing unreachable block (ram,0xfffbc500) */
/* WARNING: Removing unreachable block (ram,0xfffbc55d) */
/* Touch (source 4) x position (0..0x316) -> VFO frequency in the scope span */

void key_touch_scope_tune(ushort param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  void *pvVar4;
  bool bStack_15;
  uint uStack_10;
  undefined1 *puStack_8;
  
  iVar3 = FUN_fffc8ca8();
  if (iVar3 == 1) {
    if (PTR_DAT_00025d54[0x1c2] == '\b') {
      FUN_fffc23b6();
      return;
    }
    FUN_fffc8beb();
    return;
  }
  iVar3 = FUN_fffc90ed();
  if (iVar3 != 1) {
    FUN_fffbc638();
    FUN_fffc3c85();
    FUN_fffc4caa();
    if (PTR_DAT_00025d54[0x418] == '\x01') {
      scan_stop();
    }
    if (DAT_00009dbd == 0) {
      puStack_8 = &DAT_00009d09;
    }
    else {
      puStack_8 = &DAT_00009d63;
    }
    bStack_15 = DAT_00009dbd != 0;
    bVar2 = scope_span_index(bStack_15);
    uVar1 = *(uint *)(scope_span_table + (uint)bVar2 * 4);
    if (DAT_00009c35 == '\0') {
      uStack_10 = ((uint)(byte)puStack_8[0x4a] << 0x18 | (uint)(byte)puStack_8[0x4b] << 0x10 |
                   (uint)(byte)puStack_8[0x4c] << 8 | (uint)(byte)puStack_8[0x4d]) - (uVar1 >> 1);
    }
    else if (DAT_00009c35 == '\x01') {
      uStack_10 = DAT_00020f60;
    }
    else {
      uStack_10 = bandmem_get('\x02');
    }
    if (param_1 < 0x317) {
      pvVar4 = (void *)((uVar1 * param_1) / 0x316 + uStack_10);
      bVar2 = freq_in_range(pvVar4);
      if (bVar2 != 0) {
        puStack_8[0x4a] = (char)((uint)pvVar4 >> 0x18);
        puStack_8[0x4b] = (char)((uint)pvVar4 >> 0x10);
        puStack_8[0x4c] = (char)((uint)pvVar4 >> 8);
        uStack_10._0_1_ = SUB41(pvVar4,0);
        puStack_8[0x4d] = (undefined1)uStack_10;
        vfo_store_back(DAT_00009dbd);
        bVar2 = vfo_is_memory(DAT_00009dbd);
        if (bVar2 == 1) {
          if (DAT_00009dbd == 0) {
            DAT_00009dbe = 3;
          }
          else {
            DAT_00009dbf = 3;
          }
        }
        PTR_DAT_00025d54[0x40c] = 1;
        beep_request(1);
        return;
      }
      beep_request(3);
      return;
    }
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffbc5f9 @ fffbc5f9 (4 bytes)

void FUN_fffbc5f9(void)

{
  FUN_fffbc605();
  return;
}


// ===== FUN_fffbc5fd @ fffbc5fd (4 bytes)

void FUN_fffbc5fd(void)

{
  FUN_fffbc605();
  return;
}


// ===== FUN_fffbc601 @ fffbc601 (4 bytes)

void FUN_fffbc601(void)

{
  FUN_fffbc605();
  return;
}


// ===== FUN_fffbc605 @ fffbc605 (51 bytes)

void FUN_fffbc605(void)

{
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    FUN_fffbc65b();
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffbc638 @ fffbc638 (35 bytes)

bool FUN_fffbc638(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d54[0x95];
  if (cVar1 != '\0') {
    FUN_fffd1712();
  }
  return cVar1 != '\0';
}


// ===== FUN_fffbc65b @ fffbc65b (28 bytes)

void FUN_fffbc65b(void)

{
  FUN_fffc8beb();
  beep_request(1);
  if (DAT_00009c35 == '\x02') {
    return;
  }
  FUN_fffbc677();
  return;
}


// ===== FUN_fffbc677 @ fffbc677 (114 bytes)

void FUN_fffbc677(void)

{
  PTR_DAT_00025d54[0x409] = 1;
  if (DAT_00009c35 == '\x02') {
    DAT_00009c35 = 0;
    PTR_DAT_00025d54[0x40c] = 1;
    return;
  }
  if (DAT_00009c35 == '\x01') {
    DAT_00009c35 = 2;
    PTR_DAT_00025d54[0x40c] = 1;
    return;
  }
  if (DAT_00009c35 != '\0') {
    return;
  }
  scope_cursor_center();
  DAT_00009c35 = 1;
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== scope_cursor_center @ fffbc6e9 (149 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbc778) */
/* WARNING: Removing unreachable block (ram,0xfffbc77b) */
/* CURSOR start = dial - span/2 */

void scope_cursor_center(void)

{
  byte bVar1;
  bool local_b;
  byte bStack_a;
  uint local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = *(uint *)(PTR_DAT_00025d54 + 0x450);
  }
  else {
    local_8 = *(uint *)(PTR_DAT_00025d54 + 0x454);
  }
  local_b = DAT_00009dbd != '\0';
  bVar1 = band_of_freq(local_8);
  if (bVar1 == 0xff) {
    return;
  }
  bVar1 = scope_span_index(local_b);
  local_8 = local_8 - (*(uint *)(scope_span_table + (uint)bVar1 * 4) >> 1);
  *(uint *)(PTR_DAT_00025d54 + 0x45c) = local_8;
  for (bStack_a = 0; bStack_a < 4; bStack_a = bStack_a + 1) {
    (&DAT_00009e82)[bStack_a] = (char)(local_8 >> ((3 - bStack_a & 3) << 3));
  }
  bandmem_set('\x01',local_8);
  return;
}


// ===== FUN_fffbc77e @ fffbc77e (4 bytes)

void FUN_fffbc77e(void)

{
  FUN_fffbc677();
  return;
}


// ===== FUN_fffbc782 @ fffbc782 (192 bytes)

void FUN_fffbc782(void)

{
  bool bVar1;
  undefined *puVar2;
  
  if (PTR_DAT_00025d54[0x46b] == '\x01') {
    beep_request(1);
    return;
  }
  if (DAT_00009c5e != '\x01') {
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\b')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc23b6();
    }
    else {
      FUN_fffc4caa();
      puVar2 = PTR_DAT_00025d54;
      PTR_DAT_00025d54[0x413] = 0xff;
      *(undefined4 *)(puVar2 + 0x40f) = 0xffffffff;
      PTR_DAT_00025d54[0x40d] = 1;
      FUN_fffe1e70();
      PTR_DAT_00025d54[0x468] = 0;
      PTR_DAT_00025d54[0x414] = 1;
      FUN_fffc8cbb(8);
      FUN_fffc8d8c();
      PTR_DAT_00025d54[0x1c2] = 8;
    }
    beep_request(2);
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbc842 @ fffbc842 (108 bytes)

void FUN_fffbc842(void)

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
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  if (DAT_00009c36 != '\0') {
    DAT_00009c36 = 0;
    return;
  }
  DAT_00009c36 = 1;
  return;
}


// ===== FUN_fffbc8ae @ fffbc8ae (108 bytes)

void FUN_fffbc8ae(void)

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
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  if (DAT_00009c37 != '\0') {
    DAT_00009c37 = 0;
    return;
  }
  DAT_00009c37 = 1;
  return;
}


// ===== FUN_fffbc91a @ fffbc91a (130 bytes)

void FUN_fffbc91a(void)

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
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  if (DAT_00009c3d != '\0') {
    DAT_00009c3d = 0;
    DAT_00009c38 = 1;
    return;
  }
  DAT_00009c3d = 1;
  DAT_00009c38 = 2;
  return;
}


// ===== FUN_fffbc99c @ fffbc99c (143 bytes)

void FUN_fffbc99c(void)

{
  bool bVar1;
  
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x06')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
    return;
  }
  FUN_fffc8cbb(6);
  FUN_fffc8d8c();
  PTR_DAT_00025d54[0x1c2] = 6;
  return;
}


// ===== FUN_fffbca2b @ fffbca2b (143 bytes)

void FUN_fffbca2b(void)

{
  bool bVar1;
  
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\r')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
    return;
  }
  FUN_fffc8cbb(0xd);
  FUN_fffc8d8c();
  PTR_DAT_00025d54[0x1c2] = 0xd;
  return;
}


// ===== FUN_fffbcaba @ fffbcaba (95 bytes)

void FUN_fffbcaba(void)

{
  bool bVar1;
  
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
  }
  else {
    FUN_fffc8cbb(0);
    FUN_fffc8d8c();
    PTR_DAT_00025d54[0x1c2] = 0;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbcb19 @ fffbcb19 (94 bytes)

void FUN_fffbcb19(void)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar1 = false;
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x97] == '\x01') {
    bVar1 = true;
  }
  else {
    bVar2 = vfo_mode(0);
    uVar3 = (uint)bVar2;
    if ((uVar3 - 6 < 2) || (uVar3 == 10 || uVar3 == 0xb)) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    beep_request(3);
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbcb77 @ fffbcb77 (70 bytes)

void FUN_fffbcb77(void)

{
  if (PTR_DAT_00025d54[0x97] != '\x01') {
    if (PTR_DAT_00025d54[0x70] == '\x01') {
      PTR_DAT_00025d54[0x70] = 0;
    }
    else {
      PTR_DAT_00025d54[0x70] = 1;
    }
    if (PTR_DAT_00025d54[0x70] == '\x01') {
      FUN_fffc8beb();
      swtimer_start(0x44,2000);
      return;
    }
  }
  return;
}


// ===== FUN_fffbcbbd @ fffbcbbd (45 bytes)

void FUN_fffbcbbd(void)

{
  DAT_00009c5c = DAT_00009c5c != '\x01';
  beep_request(2);
  return;
}


// ===== FUN_fffbcbea @ fffbcbea (133 bytes)

void FUN_fffbcbea(void)

{
  FUN_fffbc638();
  FUN_fffc3c85();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (DAT_00009c5e == '\x01') {
    beep_request(1);
    return;
  }
  PTR_DAT_00025d54[0x416] = 0;
  if (PTR_DAT_00025d54[0x415] == '\0') {
    PTR_DAT_00025d54[0x415] = 1;
  }
  else {
    FUN_fffc4caa();
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    FUN_fffc8ebc();
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbcc6f @ fffbcc6f (133 bytes)

void FUN_fffbcc6f(void)

{
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  FUN_fffbc638();
  FUN_fffc3c85();
  if (DAT_00009c5e == '\x01') {
    beep_request(1);
    return;
  }
  PTR_DAT_00025d54[0x416] = 1;
  if (PTR_DAT_00025d54[0x415] == '\0') {
    PTR_DAT_00025d54[0x415] = 1;
  }
  else {
    FUN_fffc4caa();
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    FUN_fffc8ebc();
  }
  beep_request(1);
  return;
}


// ===== FUN_fffbccf4 @ fffbccf4 (23 bytes)

void FUN_fffbccf4(void)

{
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  key_mode_short();
  return;
}


// ===== FUN_fffbcd0b @ fffbcd0b (61 bytes)

void FUN_fffbcd0b(void)

{
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffbcd48 @ fffbcd48 (143 bytes)

void FUN_fffbcd48(void)

{
  bool bVar1;
  
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\n')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
    return;
  }
  FUN_fffc8cbb(10);
  FUN_fffc8d8c();
  PTR_DAT_00025d54[0x1c2] = 10;
  return;
}


// ===== FUN_fffbcdd7 @ fffbcdd7 (143 bytes)

void FUN_fffbcdd7(void)

{
  bool bVar1;
  
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\t')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
    return;
  }
  FUN_fffc8cbb(9);
  FUN_fffc8d8c();
  PTR_DAT_00025d54[0x1c2] = 9;
  return;
}


// ===== FUN_fffbce66 @ fffbce66 (150 bytes)

void FUN_fffbce66(void)

{
  bool bVar1;
  
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  PTR_DAT_00025d54[0x70] = 0;
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc8beb();
    }
    else {
      FUN_fffc8cbb(1);
      FUN_fffc8d8c();
      PTR_DAT_00025d54[0x1c2] = 1;
      FUN_fffc90b4();
    }
    beep_request(1);
    FUN_fffc5290();
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffbcefc @ fffbcefc (149 bytes)

void FUN_fffbcefc(void)

{
  bool bVar1;
  
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  PTR_DAT_00025d54[0x70] = 0;
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x02')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc8beb();
    }
    else {
      FUN_fffc8cbb(2);
      FUN_fffc8d8c();
      PTR_DAT_00025d54[0x1c2] = 2;
      FUN_fffc90b4();
    }
    beep_request(1);
    FUN_fffc5290();
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffbcf91 @ fffbcf91 (227 bytes)

void FUN_fffbcf91(void)

{
  bool bVar1;
  byte bVar2;
  
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  PTR_DAT_00025d54[0x70] = 0;
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
  if (!bVar1) {
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc8beb();
    }
    else {
      FUN_fffc8cbb(3);
      FUN_fffc8d8c();
      PTR_DAT_00025d54[0x1c2] = 3;
      FUN_fffc90b4();
    }
    beep_request(1);
    FUN_fffc5290();
    return;
  }
  PTR_DAT_00025d54[0x409] = 1;
  beep_request(3);
  return;
}


// ===== FUN_fffbd074 @ fffbd074 (69 bytes)

void FUN_fffbd074(void)

{
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  PTR_DAT_00025d54[0x70] = 0;
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    beep_request(1);
    FUN_fffc5290();
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffbd0b9 @ fffbd0b9 (80 bytes)

void FUN_fffbd0b9(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x04')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
    return;
  }
  FUN_fffc8cbb(4);
  FUN_fffc8d8c();
  PTR_DAT_00025d54[0x1c2] = 4;
  FUN_fffc90b4();
  return;
}


// ===== FUN_fffbd109 @ fffbd109 (76 bytes)

void FUN_fffbd109(void)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)FUN_fffc4b3d(DAT_00009dbd != '\0');
  if (pbVar2 == (byte *)0x0) {
    return;
  }
  bVar1 = *pbVar2;
  if ((bVar1 & 0x40) == 0) {
    *pbVar2 = bVar1 | 0x40;
  }
  else {
    *pbVar2 = bVar1 & 0xbf;
  }
  PTR_DAT_00025d54[0x40c] = 1;
  beep_request(2);
  return;
}


// ===== FUN_fffbd155 @ fffbd155 (23 bytes)

void FUN_fffbd155(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x01') {
    return;
  }
  FUN_fffc0b2f(0x20);
  return;
}


// ===== FUN_fffbd16c @ fffbd16c (20 bytes)

void FUN_fffbd16c(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x01') {
    return;
  }
  FUN_fffc078d();
  return;
}


// ===== FUN_fffbd180 @ fffbd180 (23 bytes)

void FUN_fffbd180(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x01') {
    return;
  }
  FUN_fffc0b2f(0x21);
  return;
}


// ===== FUN_fffbd197 @ fffbd197 (4 bytes)

void FUN_fffbd197(void)

{
  FUN_fffbd16c();
  return;
}


// ===== FUN_fffbd19b @ fffbd19b (23 bytes)

void FUN_fffbd19b(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x01') {
    return;
  }
  FUN_fffc0b2f(0x22);
  return;
}


// ===== FUN_fffbd1b2 @ fffbd1b2 (4 bytes)

void FUN_fffbd1b2(void)

{
  FUN_fffbd16c();
  return;
}


// ===== FUN_fffbd1b6 @ fffbd1b6 (23 bytes)

void FUN_fffbd1b6(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x01') {
    return;
  }
  FUN_fffc0b2f(0x23);
  return;
}


// ===== FUN_fffbd1cd @ fffbd1cd (4 bytes)

void FUN_fffbd1cd(void)

{
  FUN_fffbd16c();
  return;
}


// ===== FUN_fffbd1d1 @ fffbd1d1 (23 bytes)

void FUN_fffbd1d1(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x02') {
    return;
  }
  FUN_fffc0b2f(0x24);
  return;
}


// ===== FUN_fffbd1e8 @ fffbd1e8 (20 bytes)

void FUN_fffbd1e8(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x02') {
    return;
  }
  FUN_fffc078d();
  return;
}


// ===== FUN_fffbd1fc @ fffbd1fc (23 bytes)

void FUN_fffbd1fc(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x02') {
    return;
  }
  FUN_fffc0b2f(0x25);
  return;
}


// ===== FUN_fffbd213 @ fffbd213 (4 bytes)

void FUN_fffbd213(void)

{
  FUN_fffbd1e8();
  return;
}


// ===== FUN_fffbd217 @ fffbd217 (23 bytes)

void FUN_fffbd217(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x02') {
    return;
  }
  FUN_fffc0b2f(0x26);
  return;
}


// ===== FUN_fffbd22e @ fffbd22e (4 bytes)

void FUN_fffbd22e(void)

{
  FUN_fffbd1e8();
  return;
}


// ===== FUN_fffbd232 @ fffbd232 (23 bytes)

void FUN_fffbd232(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x03') {
    return;
  }
  FUN_fffc0b2f(0x27);
  return;
}


// ===== FUN_fffbd249 @ fffbd249 (20 bytes)

void FUN_fffbd249(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x03') {
    return;
  }
  FUN_fffc078d();
  return;
}

