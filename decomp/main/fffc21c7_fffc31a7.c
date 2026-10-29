// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
  
  bVar1 = memch_current_valid(param_1);
  if (bVar1 == 0) {
    return;
  }
  bVar1 = memch_current(param_1);
  if (param_1 != '\0') {
    smovf(0x9d63,&DAT_00006150 + (uint)bVar1 * 0x5a,0x5a);
    PTR_DAT_00025d54[0x426] = 0;
    DAT_00009d64 = DAT_00009d64 & 0xe7;
    DAT_00009dab = 0;
    DAT_00009dac = 0;
    return;
  }
  smovf(0x9d09,&DAT_00006150 + (uint)bVar1 * 0x5a,0x5a);
  PTR_DAT_00025d54[0x425] = 0;
  DAT_00009d0a = DAT_00009d0a & 0xe7;
  DAT_00009d51 = 0;
  DAT_00009d52 = 0;
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


// ===== FUN_fffc2c66 @ fffc2c66 (98 bytes)

void FUN_fffc2c66(int param_1)

{
  byte *apbStack_c [2];
  undefined1 local_1;
  
  local_1 = (undefined1)param_1;
  if (param_1 == 0) {
    smovf(&DAT_00006150 + (uint)(byte)PTR_DAT_00025d54[0x43a] * 0x5a,0x9d09,0x5a);
  }
  else {
    smovf(&DAT_00006150 + (uint)(byte)PTR_DAT_00025d54[0x43a] * 0x5a,0x9d63,0x5a);
  }
  memch_valid(PTR_DAT_00025d54[0x43a],apbStack_c);
  *apbStack_c[0] = 1;
  return;
}


// ===== FUN_fffc2cc8 @ fffc2cc8 (23 bytes)

void FUN_fffc2cc8(undefined1 param_1)

{
  FUN_fffc2cdf(param_1,PTR_DAT_00025d54[0x43a]);
  return;
}


// ===== FUN_fffc2cdf @ fffc2cdf (38 bytes)

void FUN_fffc2cdf(char param_1,undefined1 param_2)

{
  if (param_1 != '\0') {
    DAT_000060ca = param_2;
    return;
  }
  DAT_000060c9 = param_2;
  return;
}


// ===== FUN_fffc2d05 @ fffc2d05 (142 bytes)

undefined1 FUN_fffc2d05(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (DAT_00009dbe == '\x01') {
    smovf(0x9d63,0x9d09,0x5a);
  }
  else {
    smovf(0x9d63,&DAT_00004761 +
                 (uint)DAT_00009dc3 * 0x5a + (uint)(byte)(&DAT_000060b1)[DAT_00009dc3] * 0x438,0x5a)
    ;
  }
  DAT_00020f10 = 1;
  return 1;
}


// ===== vfo_is_memory @ fffc2d93 (86 bytes)

/* state 2, 7 or 8 */

byte vfo_is_memory(byte param_1)

{
  bool bVar1;
  byte bVar2;
  char local_3;
  
  if (param_1 == 0) {
    local_3 = DAT_00009dbe;
  }
  else {
    local_3 = DAT_00009dbf;
  }
  if ((local_3 == '\x02') || (local_3 == '\a')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (local_3 == '\b')) {
    bVar2 = 1;
  }
  else {
    bVar2 = 0;
  }
  return bVar2;
}


// ===== memch_current_valid @ fffc2de9 (24 bytes)

byte memch_current_valid(byte param_1)

{
  bool bVar1;
  byte *pbStack_8;
  byte bStack_3;
  byte local_1;
  
  local_1 = param_1;
  bStack_3 = memch_current(param_1);
  bVar1 = memch_valid(bStack_3,&pbStack_8);
  return bVar1;
}


// ===== memch_valid @ fffc2e01 (100 bytes)

/* ch<117: used flag 0x60CB[ch]; 133: valid; else !memch_dest_blocked */

bool memch_valid(byte ch,byte **rec)

{
  byte bVar1;
  bool local_11;
  
  if (ch == 0x85) {
    local_11 = true;
  }
  else if (ch < 0x75) {
    *rec = &DAT_000060cb + ch;
    if ((&DAT_000060cb)[ch] == '\x01') {
      local_11 = true;
    }
    else {
      local_11 = false;
    }
  }
  else {
    bVar1 = memch_dest_blocked(ch);
    local_11 = bVar1 == 0;
  }
  return local_11;
}


// ===== memch_current @ fffc2e65 (40 bytes)

/* 0x60C9 (A) / 0x60CA (B) */

byte memch_current(byte param_1)

{
  undefined1 local_3;
  
  if (param_1 == 0) {
    local_3 = DAT_000060c9;
  }
  else {
    local_3 = DAT_000060ca;
  }
  return local_3;
}


// ===== memch_dest_blocked @ fffc2e8d (62 bytes)

/* 5 MHz ch 508..515/EMG blocked for dest codes 0xA4C5 0xA983 0xB5A7 0xD950 */

byte memch_dest_blocked(byte param_1)

{
  ushort uVar1;
  byte bStack_5;
  
  uVar1 = dest_code_get();
  bStack_5 = 0;
  if (((((uVar1 == 0xa4c5) || (uVar1 == 0xa983)) || (uVar1 == 0xb5a7)) || (uVar1 == 0xd950)) &&
     (6 < (int)(param_1 - 0x75))) {
    bStack_5 = 1;
  }
  return bStack_5;
}


// ===== memch_current_is_special @ fffc2ecb (22 bytes)

byte memch_current_is_special(byte param_1)

{
  byte bVar1;
  bool bVar2;
  
  bVar1 = memch_current(param_1);
  bVar2 = memch_is_special(bVar1);
  return bVar2;
}


// ===== memch_is_special @ fffc2ee1 (26 bytes)

/* ch >= 117 (5 MHz / EMG) */

bool memch_is_special(byte param_1)

{
  return 0x74 < param_1;
}


// ===== FUN_fffc2efb @ fffc2efb (34 bytes)

void FUN_fffc2efb(int param_1)

{
  if (param_1 != 0) {
    DAT_00009dbf = 3;
    return;
  }
  DAT_00009dbe = 3;
  return;
}


// ===== FUN_fffc2f1d @ fffc2f1d (51 bytes)

bool FUN_fffc2f1d(int param_1)

{
  char local_3;
  
  if (param_1 == 0) {
    local_3 = DAT_00009dbe;
  }
  else {
    local_3 = DAT_00009dbf;
  }
  return local_3 == '\x03';
}


// ===== FUN_fffc2f50 @ fffc2f50 (142 bytes)

undefined1 FUN_fffc2f50(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (DAT_00009dbf == '\x01') {
    smovf(0x9d09,0x9d63,0x5a);
  }
  else {
    smovf(0x9d09,&DAT_00005409 +
                 (uint)DAT_00009dc4 * 0x5a + (uint)(byte)(&DAT_000060bd)[DAT_00009dc4] * 0x438,0x5a)
    ;
  }
  DAT_00020f10 = 1;
  return 1;
}


// ===== vfo_mark_edited @ fffc2fde (40 bytes)

/* rt+0x443/0x445 = 1, QMB state -> VFO */

void vfo_mark_edited(byte param_1)

{
  if (param_1 != 0) {
    PTR_DAT_00025d54[0x445] = 1;
    qmb_exit_to_vfo(1);
    return;
  }
  PTR_DAT_00025d54[0x443] = 1;
  qmb_exit_to_vfo(0);
  return;
}


// ===== FUN_fffc3006 @ fffc3006 (37 bytes)

byte FUN_fffc3006(void)

{
  uint freq;
  undefined1 uStack_9;
  
  freq = vfo_freq_clar(0,2);
  uStack_9 = band_of_freq(freq);
  if (uStack_9 == 0xff) {
    uStack_9 = 0xb;
  }
  return uStack_9;
}


// ===== FUN_fffc302b @ fffc302b (86 bytes)

bool FUN_fffc302b(int param_1)

{
  bool bVar1;
  bool local_4;
  char local_3;
  
  if (param_1 == 0) {
    local_3 = DAT_00009dbe;
  }
  else {
    local_3 = DAT_00009dbf;
  }
  if ((local_3 == '\x02') || (local_3 == '\x03')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (local_3 == '\x04')) {
    local_4 = true;
  }
  else {
    local_4 = false;
  }
  local_4 = !local_4;
  return local_4;
}


// ===== vfo_enter_vfo_state @ fffc3081 (46 bytes)

/* state = 1 */

void vfo_enter_vfo_state(char param_1)

{
  vfo_enter_mem_state(param_1);
  FUN_fffc2937(param_1);
  if (param_1 != '\0') {
    DAT_00009dbf = 1;
    return;
  }
  DAT_00009dbe = 1;
  return;
}


// ===== FUN_fffc30af @ fffc30af (107 bytes)

undefined1 FUN_fffc30af(int param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if ((PTR_DAT_00025d54[0x443] == '\x01') || (PTR_DAT_00025d54[0x444] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return 1;
    }
  }
  else {
    if ((PTR_DAT_00025d54[0x445] == '\x01') || (PTR_DAT_00025d54[0x446] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}


// ===== qmb_set_depth @ fffc311a (82 bytes)

/* 0x901F/0x9021 = stored count (max 5 if 0x9AC0==0) */

void qmb_set_depth(char param_1)

{
  bool bVar1;
  byte local_2;
  
  local_2 = DAT_00009014;
  if ((DAT_00009ac0 == '\0') && (4 < DAT_00009014)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_2 = 5;
  }
  if (param_1 == '\0') {
    DAT_0000901f = local_2;
    return;
  }
  DAT_00009021 = local_2;
  return;
}


// ===== qmb_enter @ fffc316c (59 bytes)

/* state = 5, load QMB slot, save header */

void qmb_enter(byte param_1)

{
  if (param_1 == 0) {
    DAT_00009dbe = 5;
  }
  else {
    DAT_00009dbf = 5;
  }
  FUN_fffc31a7(param_1,1);
  FUN_fffc334c(param_1);
  FUN_fffc33ef();
  eeprom_save_qmb_slot(0);
  FUN_fffec578();
  return;
}


// ===== FUN_fffc31a7 @ fffc31a7 (25 bytes)

void FUN_fffc31a7(byte param_1,char param_2)

{
  FUN_fffc31c0(param_1);
  if (param_2 != '\x01') {
    return;
  }
  vfo_retune(param_1);
  return;
}

