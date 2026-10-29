// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc3c85 @ fffc3c85 (26 bytes)

void FUN_fffc3c85(void)

{
  PTR_DAT_00025d54[0x96] = 0;
  PTR_DAT_00025d54[0x1c5] = 0;
  return;
}


// ===== FUN_fffc3c9f @ fffc3c9f (58 bytes)

void FUN_fffc3c9f(void)

{
  DAT_00009be7 = DAT_00009be7 != '\x01';
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffc3cd9 @ fffc3cd9 (77 bytes)

void FUN_fffc3cd9(void)

{
  DAT_00009dc9 = 3;
  FUN_fffc8cbb(0xb);
  FUN_fffc8d8c();
  PTR_DAT_00025d54[0x1c2] = 0xb;
  PTR_DAT_00025d54[0x424] = DAT_00009be8;
  FUN_fffc3c85();
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffc3d26 @ fffc3d26 (79 bytes)

void FUN_fffc3d26(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc3d75();
  if (iVar1 == 0) {
    return;
  }
  DAT_00009bf0 = DAT_00009bf0 == '\0';
  PTR_DAT_00025d54[0x40b] = 1;
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffc3d75 @ fffc3d75 (115 bytes)

undefined1 FUN_fffc3d75(void)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  
  bVar3 = vfo_mode(0);
  if ((bVar3 == 0) || (bVar3 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 4)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 5)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 6)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 7)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_fffc3de8 @ fffc3de8 (84 bytes)

void FUN_fffc3de8(void)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = vfo_rec_ptr(1);
  iVar2 = FUN_fffc3e3c(pbVar1);
  if (iVar2 == 0) {
    return;
  }
  DAT_00009c02 = DAT_00009c02 != '\x01';
  keyer_init();
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffc3e3c @ fffc3e3c (110 bytes)

undefined1 FUN_fffc3e3c(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  undefined1 local_7;
  
  bVar2 = *param_1 & 0xf;
  if ((bVar2 == 2) || (bVar2 == 3)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_7 = 1;
  }
  else {
    if ((bVar2 == 0) || (bVar2 == 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_7 = 0;
    }
    else if (DAT_00009a3c == '\x02') {
      local_7 = 2;
    }
    else if (DAT_00009a3c == '\0') {
      local_7 = 0;
    }
    else {
      local_7 = 2;
    }
  }
  return local_7;
}


// ===== FUN_fffc3eaa @ fffc3eaa (113 bytes)

void FUN_fffc3eaa(void)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = vfo_rec_ptr(1);
  iVar3 = FUN_fffc3f1b(pbVar2);
  if ((iVar3 == 0) && (iVar3 = FUN_fffc3e3c(pbVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00020b3d != '\0') {
      PTR_DAT_00025d54[0x409] = 1;
      return;
    }
    FUN_fffc3f40(pbVar2);
    keyer_init();
    beep_request(1);
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffc3f1b @ fffc3f1b (37 bytes)

undefined1 FUN_fffc3f1b(byte *param_1)

{
  undefined1 local_7;
  
  if (((*param_1 & 0xf) < 2) || ((*param_1 & 0xf) - 4 < 4)) {
    local_7 = 1;
  }
  else {
    local_7 = 0;
  }
  return local_7;
}


// ===== FUN_fffc3f40 @ fffc3f40 (92 bytes)

void FUN_fffc3f40(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  byte *local_c;
  
  uVar2 = (uint)(*param_1 & 0xf);
  if (uVar2 - 6 < 2) {
    local_c = param_1 + 0x3c;
  }
  else if (uVar2 - 2 < 2) {
    local_c = param_1 + 0x14;
  }
  else if (uVar2 - 4 < 2) {
    local_c = param_1 + 0x32;
  }
  else {
    if (1 < uVar2) {
      return;
    }
    local_c = param_1 + 10;
  }
  bVar1 = *local_c;
  if ((bVar1 & 2) != 0) {
    *local_c = bVar1 & 0xfd;
    return;
  }
  *local_c = bVar1 | 2;
  return;
}


// ===== FUN_fffc3f9c @ fffc3f9c (83 bytes)

void FUN_fffc3f9c(void)

{
  if (DAT_00009c5e != '\x01') {
    return;
  }
  if (PTR_DAT_00025d54[0x483] == '\x01') {
    PTR_DAT_00025d54[0x483] = 0;
  }
  else {
    PTR_DAT_00025d54[0x483] = 1;
    PTR_DAT_00025d54[0x1c5] = 1;
    FUN_fffc8e0e(500);
    PTR_DAT_00025d54[0x409] = 1;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffc3fef @ fffc3fef (117 bytes)

void FUN_fffc3fef(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    FUN_fffbc638();
    FUN_fffc23b6();
    FUN_fffc4caa();
    PTR_DAT_00025d54[0x405] = 1;
    puVar2 = &DAT_00009d09;
    puVar1 = &DAT_000121c7;
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
    puVar2 = &DAT_000121c7;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    PTR_DAT_00025d54[0x40b] = 1;
    return;
  }
  scan_stop();
  return;
}


// ===== FUN_fffc4064 @ fffc4064 (115 bytes)

void FUN_fffc4064(void)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  byte *pbStack_4;
  
  bVar2 = memch_valid(PTR_DAT_00025d54[0x43a],&pbStack_4);
  bVar1 = DAT_00009dbd;
  if (!bVar2) {
    beep_request(3);
    return;
  }
  bVar3 = vfo_is_memory(DAT_00009dbd);
  if (bVar3 == 0) {
    vm_toggle_core();
  }
  FUN_fffc2cdf(bVar1,PTR_DAT_00025d54[0x43a]);
  eeprom_save_memch(PTR_DAT_00025d54[0x43a]);
  vfo_reload(bVar1);
  PTR_DAT_00025d54[0x40b] = 1;
  FUN_fffc2794();
  beep_request(1);
  return;
}


// ===== FUN_fffc40d7 @ fffc40d7 (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc40f7) */

void FUN_fffc40d7(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_key_nop_fff8e0cc)[uVar1])();
    return;
  }
  (*(code *)(&key_press_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== FUN_fffc410a @ fffc410a (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc412a) */

void FUN_fffc410a(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_FUN_fff8e0ec)[uVar1])();
    return;
  }
  (*(code *)(&key_short_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== FUN_fffc413d @ fffc413d (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc415d) */

void FUN_fffc413d(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_FUN_fff8e10c)[uVar1])();
    return;
  }
  (*(code *)(&key_long_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== FUN_fffc4170 @ fffc4170 (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc4190) */

void FUN_fffc4170(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_FUN_fff8e12c)[uVar1])();
    return;
  }
  (*(code *)(&key_repeat_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== FUN_fffc41a3 @ fffc41a3 (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc41c3) */

void FUN_fffc41a3(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    (*(code *)(&PTR_FUN_fff8e14c)[uVar1])();
    return;
  }
  (*(code *)(&key_release_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)])();
  return;
}


// ===== FUN_fffc41d6 @ fffc41d6 (98 bytes)

void FUN_fffc41d6(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
  }
  if (PTR_DAT_00025d54[0x39] == '\0') {
    if (DAT_00020b99 == '\x01') {
      beep_request(1);
      return;
    }
    FUN_fffe60a6();
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc4238 @ fffc4238 (81 bytes)

void FUN_fffc4238(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d54[0x39] != '\0') {
    if ((DAT_00009ab8 == '\x03') && (PTR_DAT_00025d54[0x408] != '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d54[0x3a] = 1;
      FUN_fffed206(2);
      return;
    }
  }
  return;
}


// ===== FUN_fffc4289 @ fffc4289 (66 bytes)

void FUN_fffc4289(void)

{
  if ((PTR_DAT_00025d54[0x39] == '\0') && (PTR_DAT_00025d54[0x46b] == '\x01')) {
    FUN_fffc809d(DAT_00009dbd);
    FUN_fffe602e();
    DAT_0001b4dc = 1;
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc42cb @ fffc42cb (36 bytes)

void FUN_fffc42cb(void)

{
  if (PTR_DAT_00025d54[0x46b] != '\x01') {
    return;
  }
  FUN_fffc809d(DAT_00009dbd);
  FUN_fffe602e();
  return;
}


// ===== FUN_fffc42ef @ fffc42ef (155 bytes)

void FUN_fffc42ef(void)

{
  bool bVar1;
  byte bVar2;
  
  if (PTR_DAT_00025d54[0x408] == '\x02') {
    PTR_DAT_00025d54[0x3a] = 3;
    swtimer_start(0x20,1000);
  }
  if (PTR_DAT_00025d54[0x39] == '\0') {
    if ((PTR_DAT_00025d54[0x46b] == '\x01') && (PTR_DAT_00025d54[0x46c] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar2 = scan_allowed();
      if (bVar2 == 1) {
        scan_start_up();
      }
    }
    else {
      bVar2 = FUN_fffb32aa(0);
      bVar2 = memch_current(bVar2);
      eeprom_save_memch(bVar2);
    }
  }
  PTR_DAT_00025d54[0x46c] = 0;
  PTR_DAT_00025d54[0x46b] = 0;
  return;
}


// ===== FUN_fffc438a @ fffc438a (98 bytes)

void FUN_fffc438a(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc8beb();
  }
  if (PTR_DAT_00025d54[0x39] == '\0') {
    if (DAT_00020b99 == '\x01') {
      beep_request(1);
      return;
    }
    FUN_fffe6138();
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc43ec @ fffc43ec (81 bytes)

void FUN_fffc43ec(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d54[0x39] != '\0') {
    if ((DAT_00009ab8 == '\x03') && (PTR_DAT_00025d54[0x408] != '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d54[0x3a] = 2;
      FUN_fffed206(2);
      return;
    }
  }
  return;
}


// ===== FUN_fffc443d @ fffc443d (66 bytes)

void FUN_fffc443d(void)

{
  if ((PTR_DAT_00025d54[0x39] == '\0') && (PTR_DAT_00025d54[0x46b] == '\x01')) {
    FUN_fffc8141(DAT_00009dbd);
    FUN_fffe602e();
    DAT_0001b4dc = 1;
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc447f @ fffc447f (36 bytes)

void FUN_fffc447f(void)

{
  if (PTR_DAT_00025d54[0x46b] != '\x01') {
    return;
  }
  FUN_fffc8141(DAT_00009dbd);
  FUN_fffe602e();
  return;
}


// ===== FUN_fffc44a3 @ fffc44a3 (155 bytes)

void FUN_fffc44a3(void)

{
  bool bVar1;
  byte bVar2;
  
  if (PTR_DAT_00025d54[0x408] == '\x02') {
    PTR_DAT_00025d54[0x3a] = 3;
    swtimer_start(0x20,1000);
  }
  if (PTR_DAT_00025d54[0x39] == '\0') {
    if ((PTR_DAT_00025d54[0x46b] == '\x01') && (PTR_DAT_00025d54[0x46c] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar2 = scan_allowed();
      if (bVar2 == 1) {
        scan_start_down();
      }
    }
    else {
      bVar2 = FUN_fffb32aa(0);
      bVar2 = memch_current(bVar2);
      eeprom_save_memch(bVar2);
    }
  }
  PTR_DAT_00025d54[0x46c] = 0;
  PTR_DAT_00025d54[0x46b] = 0;
  return;
}


// ===== FUN_fffc453e @ fffc453e (66 bytes)

void FUN_fffc453e(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffc4756();
  if (iVar2 != 0) {
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc8beb();
    }
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc4580 @ fffc4580 (11 bytes)

void FUN_fffc4580(void)

{
  cat_BU(-0x70bf0);
  return;
}


// ===== FUN_fffc458b @ fffc458b (36 bytes)

void FUN_fffc458b(void)

{
  cat_BU(-0x70bf0);
  swtimer_start(0x40,0xfa);
  DAT_0001b4dc = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc45af @ fffc45af (21 bytes)

void FUN_fffc45af(void)

{
  cat_BU(-0x70bf0);
  swtimer_start(0x40,0xfa);
  return;
}


// ===== FUN_fffc45c4 @ fffc45c4 (1 bytes)

void FUN_fffc45c4(void)

{
  return;
}


// ===== FUN_fffc45c5 @ fffc45c5 (66 bytes)

void FUN_fffc45c5(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffc4756();
  if (iVar2 != 0) {
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc8beb();
    }
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc4607 @ fffc4607 (11 bytes)

void FUN_fffc4607(void)

{
  cat_BD(-0x70bec);
  return;
}


// ===== FUN_fffc4612 @ fffc4612 (36 bytes)

void FUN_fffc4612(void)

{
  cat_BD(-0x70bec);
  swtimer_start(0x40,0xfa);
  DAT_0001b4dc = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc4636 @ fffc4636 (21 bytes)

void FUN_fffc4636(void)

{
  cat_BD(-0x70bec);
  swtimer_start(0x40,0xfa);
  return;
}


// ===== FUN_fffc464b @ fffc464b (1 bytes)

void FUN_fffc464b(void)

{
  return;
}


// ===== FUN_fffc464c @ fffc464c (60 bytes)

void FUN_fffc464c(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffc4756();
  if (iVar2 != 0) {
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc8beb();
      return;
    }
  }
  return;
}


// ===== FUN_fffc4688 @ fffc4688 (133 bytes)

void FUN_fffc4688(void)

{
  byte bVar1;
  undefined1 *local_4;
  
  if (DAT_00009dbd == '\0') {
    local_4 = &DAT_00009d09;
  }
  else {
    local_4 = &DAT_00009d63;
  }
  bVar1 = local_4[3] & 3;
  if (bVar1 == 3) {
    local_4[3] = local_4[3] & 0xfc;
  }
  else if (bVar1 == 1) {
    local_4[3] = local_4[3] & 0xfe | 2;
  }
  else if (bVar1 == 2) {
    local_4[3] = local_4[3] | 3;
  }
  else if ((local_4[3] & 3) == 0) {
    local_4[3] = local_4[3] & 0xfd | 1;
  }
  PTR_DAT_00025d54[0x40c] = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc470d @ fffc470d (73 bytes)

void FUN_fffc470d(void)

{
  undefined1 *local_4;
  
  if (DAT_00009dbd == '\0') {
    local_4 = &DAT_00009d09;
  }
  else {
    local_4 = &DAT_00009d63;
  }
  local_4[3] = local_4[3] & 0xfc;
  PTR_DAT_00025d54[0x40c] = 1;
  beep_request(2);
  return;
}


// ===== FUN_fffc4756 @ fffc4756 (75 bytes)

bool FUN_fffc4756(void)

{
  char cVar1;
  bool bStack_2;
  
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  PTR_DAT_00025d54[0x70] = 0;
  cVar1 = PTR_DAT_00025d54[0x418];
  if (cVar1 == '\x01') {
    scan_stop();
    PTR_DAT_00025d54[0x409] = 1;
  }
  bStack_2 = cVar1 != '\x01';
  return bStack_2;
}


// ===== FUN_fffc47a1 @ fffc47a1 (60 bytes)

void FUN_fffc47a1(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffc4756();
  if (iVar2 != 0) {
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x02')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc8beb();
      return;
    }
  }
  return;
}


// ===== FUN_fffc47dd @ fffc47dd (115 bytes)

void FUN_fffc47dd(void)

{
  byte bVar1;
  undefined1 *local_4;
  
  if (DAT_00009dbd == '\0') {
    local_4 = &DAT_00009d09;
  }
  else {
    local_4 = &DAT_00009d63;
  }
  bVar1 = local_4[5] & 3;
  if (bVar1 == 3) {
    local_4[5] = local_4[5] & 0xfc;
  }
  else if (bVar1 == 2) {
    local_4[5] = local_4[5] | 3;
  }
  else if ((local_4[5] & 3) == 0) {
    local_4[5] = local_4[5] & 0xfe | 2;
  }
  PTR_DAT_00025d54[0x40c] = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc4850 @ fffc4850 (73 bytes)

void FUN_fffc4850(void)

{
  undefined1 *local_4;
  
  if (DAT_00009dbd == '\0') {
    local_4 = &DAT_00009d09;
  }
  else {
    local_4 = &DAT_00009d63;
  }
  local_4[5] = local_4[5] & 0xfc;
  PTR_DAT_00025d54[0x40c] = 1;
  beep_request(2);
  return;
}


// ===== FUN_fffc4899 @ fffc4899 (139 bytes)

void FUN_fffc4899(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = FUN_fffc4756();
  if (iVar3 != 0) {
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
      beep_request(3);
      return;
    }
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc8beb();
      return;
    }
  }
  return;
}


// ===== FUN_fffc4924 @ fffc4924 (88 bytes)

void FUN_fffc4924(void)

{
  byte bVar1;
  undefined1 *local_4;
  
  if (DAT_00009dbd == '\0') {
    local_4 = &DAT_00009d09;
  }
  else {
    local_4 = &DAT_00009d63;
  }
  bVar1 = FUN_fff9921f(local_4);
  if ((bVar1 & 0x80) == 0) {
    FUN_fffc0948(local_4,1);
  }
  else {
    FUN_fffc0948(local_4,0);
  }
  PTR_DAT_00025d54[0x40c] = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc497c @ fffc497c (69 bytes)

void FUN_fffc497c(void)

{
  bool bVar1;
  int iVar2;
  
  FUN_fffbd074();
  iVar2 = FUN_fffc4756();
  if (iVar2 != 0) {
    if ((PTR_DAT_00025d54[0x1c1] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\x04')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc8beb();
    }
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc49c1 @ fffc49c1 (134 bytes)

void FUN_fffc49c1(void)

{
  byte *pbVar1;
  byte bVar2;
  
  pbVar1 = (byte *)FUN_fffc4b3d(DAT_00009dbd != '\0');
  if (pbVar1 == (byte *)0x0) {
    return;
  }
  if ((*pbVar1 & 0x40) == 0) {
    *pbVar1 = *pbVar1 | 0x40;
  }
  bVar2 = *pbVar1 & 0x30;
  if (bVar2 == 0x30) {
    *pbVar1 = *pbVar1 & 0xef | 0x20;
  }
  else if (bVar2 == 0x10) {
    *pbVar1 = *pbVar1 & 0xcf;
  }
  else if (bVar2 == 0x20) {
    *pbVar1 = *pbVar1 & 0xdf | 0x10;
  }
  else if ((*pbVar1 & 0x30) == 0) {
    *pbVar1 = *pbVar1 | 0x30;
  }
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== FUN_fffc4a47 @ fffc4a47 (70 bytes)

void FUN_fffc4a47(void)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)FUN_fffc4b3d(DAT_00009dbd != '\0');
  if (pbVar1 == (byte *)0x0) {
    return;
  }
  if ((*pbVar1 & 0x40) == 0) {
    *pbVar1 = *pbVar1 | 0x40;
  }
  *pbVar1 = *pbVar1 & 0xcf;
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}

