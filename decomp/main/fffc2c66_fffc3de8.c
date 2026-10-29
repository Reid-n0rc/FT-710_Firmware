// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc2c66 @ fffc2c66 (98 bytes)

void FUN_fffc2c66(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  byte *apbStack_c [2];
  undefined1 local_1;
  
  local_1 = (undefined1)param_1;
  puVar3 = &DAT_00006150 + (uint)(byte)PTR_DAT_00025d54[0x43a] * 0x5a;
  if (param_1 == 0) {
    puVar1 = &DAT_00009d09;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar3 = puVar3 + 1;
      puVar1 = puVar1 + 1;
    }
  }
  else {
    puVar1 = &DAT_00009d63;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar3 = puVar3 + 1;
      puVar1 = puVar1 + 1;
    }
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
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  puVar1 = &DAT_00004761 +
           (uint)DAT_00009dc3 * 0x5a + (uint)(byte)(&DAT_000060b1)[DAT_00009dc3] * 0x438;
  if (DAT_00009dbe == '\x01') {
    puVar2 = &DAT_00009d09;
    puVar1 = &DAT_00009d63;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  else {
    puVar2 = &DAT_00009d63;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar1;
      puVar2 = puVar2 + 1;
      puVar1 = puVar1 + 1;
    }
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
  undefined *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  puVar1 = &DAT_00005409 +
           (uint)DAT_00009dc4 * 0x5a + (uint)(byte)(&DAT_000060bd)[DAT_00009dc4] * 0x438;
  if (DAT_00009dbf == '\x01') {
    puVar3 = &DAT_00009d63;
    puVar2 = &DAT_00009d09;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    puVar2 = &DAT_00009d09;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar1;
      puVar2 = puVar2 + 1;
      puVar1 = puVar1 + 1;
    }
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


// ===== FUN_fffc31c0 @ fffc31c0 (128 bytes)

void FUN_fffc31c0(uint param_1)

{
  byte local_4;
  byte local_3;
  byte local_2;
  
  if (param_1 == 0) {
    local_2 = DAT_00009020;
  }
  else {
    local_2 = DAT_00009022;
  }
  if (DAT_00009014 <= local_2) {
    local_2 = 0;
  }
  local_3 = (&DAT_00009015)[local_2];
  if (local_3 < 8) {
    local_4 = DAT_00009013;
  }
  else {
    local_3 = local_3 - 8;
    local_4 = DAT_00009012;
  }
  if (((uint)local_4 & 1 << (local_3 & 0x1f)) != 0) {
    FUN_fffc3240((&DAT_00009015)[local_2],param_1 & 0xff);
    return;
  }
  return;
}


// ===== FUN_fffc3240 @ fffc3240 (71 bytes)

void FUN_fffc3240(byte param_1,int param_2)

{
  undefined1 *puVar1;
  undefined *puVar2;
  int iVar3;
  
  if (param_2 == 0) {
    puVar2 = &DAT_00009023 + (uint)param_1 * 0x5a;
    puVar1 = &DAT_00009d09;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  else {
    puVar2 = &DAT_00009023 + (uint)param_1 * 0x5a;
    puVar1 = &DAT_00009d63;
    for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  vfo_retune((byte)param_2);
  return;
}


// ===== vfo_retune @ fffc3287 (197 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc32ca) */
/* WARNING: Removing unreachable block (ram,0xfffc32d1) */
/* freq_clamp the record frequency and apply */

void vfo_retune(byte param_1)

{
  bool bVar1;
  uint uVar2;
  char local_d;
  undefined1 *local_c;
  undefined1 local_8;
  
  if (param_1 == 0) {
    local_c = &DAT_00009d09;
    local_d = DAT_00009dbe;
  }
  else {
    local_c = &DAT_00009d63;
    local_d = DAT_00009dbf;
  }
  DAT_0001b4e2 = 1;
  uVar2 = freq_clamp(param_1,(uint)(byte)local_c[0x4a] << 0x18 | (uint)(byte)local_c[0x4b] << 0x10 |
                             (uint)(byte)local_c[0x4c] << 8 | (uint)(byte)local_c[0x4d]);
  DAT_0001b4e2 = 0;
  local_c[0x4a] = (char)(uVar2 >> 0x18);
  local_c[0x4b] = (char)(uVar2 >> 0x10);
  local_c[0x4c] = (char)(uVar2 >> 8);
  local_8 = (undefined1)uVar2;
  local_c[0x4d] = local_8;
  if (PTR_DAT_00025d54[0x469] != '\0') {
    if ((local_d == '\x04') || (local_d == '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      vfo_mark_edited(param_1);
      vfo_store_back(param_1);
      return;
    }
  }
  return;
}


// ===== FUN_fffc334c @ fffc334c (163 bytes)

void FUN_fffc334c(int param_1)

{
  byte *local_c;
  char *local_8;
  
  if (param_1 == 0) {
    local_8 = &DAT_0000901f;
    local_c = &DAT_00009020;
  }
  else {
    local_8 = &DAT_00009021;
    local_c = &DAT_00009022;
  }
  if (*local_8 != '\0') {
    *local_8 = *local_8 + -1;
  }
  *local_c = *local_c + 1;
  if (DAT_00009ac0 == '\0') {
    if (*local_c < 5) {
      if (DAT_00009014 <= *local_c) {
        *local_c = 0;
      }
    }
    else {
      *local_c = 0;
    }
  }
  else if (DAT_00009014 <= *local_c) {
    *local_c = 0;
  }
  PTR_DAT_00025d54[0x40b] = 1;
  return;
}


// ===== FUN_fffc33ef @ fffc33ef (25 bytes)

void FUN_fffc33ef(void)

{
  FUN_fffc8cbb(0x43);
  FUN_fffc8d8c();
  PTR_DAT_00025d54[0x1c2] = 0x43;
  return;
}


// ===== FUN_fffc3408 @ fffc3408 (208 bytes)

void FUN_fffc3408(char param_1)

{
  byte local_2;
  
  if (DAT_00009ac0 == '\0') {
    local_2 = 5;
  }
  else {
    local_2 = 10;
  }
  if (DAT_00009014 < local_2) {
    return;
  }
  if (param_1 == '\0') {
    if (DAT_00009021 != '\0') {
      DAT_00009021 = DAT_00009021 + -1;
      return;
    }
    DAT_00009dbf = 1;
    vfo_reload(1);
    PTR_DAT_00025d54[0x40b] = 1;
    qmb_set_depth('\0');
    DAT_00009022 = 0;
    return;
  }
  if (DAT_0000901f != '\0') {
    DAT_0000901f = DAT_0000901f + -1;
    return;
  }
  DAT_00009dbe = 1;
  vfo_reload(0);
  PTR_DAT_00025d54[0x40b] = 1;
  qmb_set_depth('\0');
  DAT_00009020 = 0;
  return;
}


// ===== FUN_fffc34d8 @ fffc34d8 (41 bytes)

void FUN_fffc34d8(char param_1)

{
  qmb_set_depth(param_1);
  if (param_1 != '\0') {
    DAT_00009022 = 0;
    return;
  }
  DAT_00009020 = 0;
  return;
}


// ===== FUN_fffc3501 @ fffc3501 (1 bytes)

void FUN_fffc3501(void)

{
  return;
}


// ===== FUN_fffc3502 @ fffc3502 (1 bytes)

void FUN_fffc3502(void)

{
  return;
}


// ===== FUN_fffc3503 @ fffc3503 (127 bytes)

void FUN_fffc3503(int param_1)

{
  uint uVar1;
  byte *local_8;
  
  if (param_1 == 0) {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  uVar1 = (uint)(*local_8 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_8[0x1c] = 0;
      local_8[0x1d] = 0;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        local_8[0x26] = 0;
        local_8[0x27] = 0;
        return;
      }
      if (uVar1 < 2) {
        local_8[0x12] = 0;
        local_8[0x13] = 0;
        return;
      }
      return;
    }
  }
  local_8[0x30] = 0;
  local_8[0x31] = 0;
  return;
}


// ===== FUN_fffc3582 @ fffc3582 (215 bytes)

void FUN_fffc3582(int param_1)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  byte bStack_c;
  byte *local_8;
  
  if (param_1 == 0) {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  bVar2 = *local_8 & 0xf;
  uVar1 = (uint)bVar2;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      sVar3 = FUN_fffc38cb(500,bVar2);
      if (sVar3 == 0) {
        return;
      }
      local_8[0x1a] = (byte)((ushort)sVar3 >> 8);
      bStack_c = (byte)sVar3;
      local_8[0x1b] = bStack_c;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        sVar3 = FUN_fffc38cb(500,bVar2);
        if (sVar3 == 0) {
          return;
        }
        local_8[0x24] = (byte)((ushort)sVar3 >> 8);
        bStack_c = (byte)sVar3;
        local_8[0x25] = bStack_c;
        return;
      }
      if (1 < uVar1) {
        return;
      }
      sVar3 = FUN_fffc38cb(3000,bVar2);
      if (sVar3 == 0) {
        return;
      }
      local_8[0x10] = (byte)((ushort)sVar3 >> 8);
      bStack_c = (byte)sVar3;
      local_8[0x11] = bStack_c;
      return;
    }
  }
  sVar3 = FUN_fffc38cb(0xc80,bVar2);
  if (sVar3 == 0) {
    return;
  }
  local_8[0x2e] = (byte)((ushort)sVar3 >> 8);
  bStack_c = (byte)sVar3;
  local_8[0x2f] = bStack_c;
  return;
}


// ===== FUN_fffc3659 @ fffc3659 (282 bytes)

void FUN_fffc3659(int param_1)

{
  uint uVar1;
  byte *local_8;
  
  if (param_1 == 0) {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  uVar1 = (uint)(*local_8 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_8[0x18] = 0;
      local_8[0x19] = 0x96;
      local_8[0x14] = local_8[0x14] & 0x7f;
      return;
    }
    if (uVar1 - 4 < 2) {
      local_8[0x36] = 0;
      local_8[0x37] = 0x96;
      local_8[0x32] = local_8[0x32] & 0x7f;
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc3717;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          local_8[0x22] = 0;
          local_8[0x23] = 0x96;
          local_8[0x1e] = local_8[0x1e] & 0x7f;
          return;
        }
        if (1 < uVar1) {
          return;
        }
        local_8[0xe] = 0;
        local_8[0xf] = 0x96;
        local_8[10] = local_8[10] & 0x7f;
        return;
      }
    }
    local_8[0x40] = 0;
    local_8[0x41] = 0x96;
    local_8[0x3c] = local_8[0x3c] & 0x7f;
    return;
  }
LAB_fffc3717:
  local_8[0x2c] = 0;
  local_8[0x2d] = 0x96;
  local_8[0x28] = local_8[0x28] & 0x7f;
  return;
}


// ===== FUN_fffc3773 @ fffc3773 (282 bytes)

void FUN_fffc3773(int param_1)

{
  uint uVar1;
  byte *local_8;
  
  if (param_1 == 0) {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  uVar1 = (uint)(*local_8 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_8[0x16] = 0;
      local_8[0x17] = 0x96;
      local_8[0x14] = local_8[0x14] & 0xbf;
      return;
    }
    if (uVar1 - 4 < 2) {
      local_8[0x34] = 0;
      local_8[0x35] = 0x96;
      local_8[0x32] = local_8[0x32] & 0xbf;
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc3831;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          local_8[0x20] = 0;
          local_8[0x21] = 0x96;
          local_8[0x1e] = local_8[0x1e] & 0xbf;
          return;
        }
        if (1 < uVar1) {
          return;
        }
        local_8[0xc] = 0;
        local_8[0xd] = 0x96;
        local_8[10] = local_8[10] & 0xbf;
        return;
      }
    }
    local_8[0x3e] = 0;
    local_8[0x3f] = 0x96;
    local_8[0x3c] = local_8[0x3c] & 0xbf;
    return;
  }
LAB_fffc3831:
  local_8[0x2a] = 0;
  local_8[0x2b] = 0x96;
  local_8[0x28] = local_8[0x28] & 0xbf;
  return;
}


// ===== FUN_fffc388d @ fffc388d (62 bytes)

void FUN_fffc388d(int param_1)

{
  undefined1 *local_8;
  
  if (param_1 == 0) {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  DAT_00009c5f = 0;
  local_8[0x14] = local_8[0x14] & 0xdf;
  return;
}


// ===== FUN_fffc38cb @ fffc38cb (47 bytes)

undefined2 FUN_fffc38cb(undefined2 param_1,undefined1 param_2)

{
  char cVar1;
  undefined2 uStack_c;
  
  cVar1 = FUN_fffb36ff(param_2,param_1);
  if (cVar1 == -1) {
    uStack_c = 0;
  }
  else {
    uStack_c = FUN_fffb3775(param_2,cVar1);
  }
  return uStack_c;
}


// ===== FUN_fffc38fa @ fffc38fa (115 bytes)

void FUN_fffc38fa(void)

{
  PTR_DAT_00025d54[0x43c] = 0;
  if (PTR_DAT_00025d54[0x1d9] == '\0') {
    PTR_DAT_00025d54[0x1d9] = 1;
    FUN_fffc2b12();
    PTR_DAT_00025d54[0x409] = 1;
    beep_request(2);
    return;
  }
  if (PTR_DAT_00025d54[0x43b] != '\0') {
    PTR_DAT_00025d54[0x43b] = 0;
    PTR_DAT_00025d54[0x409] = 1;
    beep_request(1);
    return;
  }
  FUN_fffc20dd();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffc396d @ fffc396d (139 bytes)

void FUN_fffc396d(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d54[0x1c2];
  if (cVar1 == '\f') {
    FUN_fffc151d((byte)PTR_DAT_00025d54[0x424] + 0x6b);
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (cVar1 != '\v') {
    if (cVar1 == '\x05') {
      FUN_fffc0c8f((byte)PTR_DAT_00025d54[0x424] + 0x77);
      PTR_DAT_00025d54[0x409] = 1;
      beep_request(1);
      return;
    }
    return;
  }
  if ((byte)PTR_DAT_00025d54[0x424] < 0xb) {
    DAT_00009be8 = PTR_DAT_00025d54[0x424];
  }
  FUN_fffc39f8();
  return;
}


// ===== FUN_fffc39f8 @ fffc39f8 (24 bytes)

void FUN_fffc39f8(void)

{
  FUN_fffc8beb();
  PTR_DAT_00025d54[0x409] = 1;
  beep_request(1);
  return;
}


// ===== FUN_fffc3a10 @ fffc3a10 (245 bytes)

void FUN_fffc3a10(void)

{
  if (PTR_DAT_00025d54[0x96] == '\x01') {
    FUN_fffc3b05(DAT_00009c08);
    if (DAT_00009c08 != '\x18') {
      beep_request(1);
      return;
    }
  }
  else if (PTR_DAT_00025d54[0xba] != '\x01') {
    if (PTR_DAT_00025d54[0x93] == '\x01') {
      if (PTR_DAT_00025d54[0x3fc] == '\x04') {
        FUN_fffe35c3();
        return;
      }
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d54[0x97] == '\x01') {
      FUN_fffc2794();
    }
    if (PTR_DAT_00025d54[0x1c1] == '\x01') {
      if ((byte)PTR_DAT_00025d54[0x1c2] < 0x1e) {
        FUN_fffc396d();
      }
      FUN_fffc8beb();
      PTR_DAT_00025d54[0x409] = 1;
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d54[0x70] == '\x01') {
      PTR_DAT_00025d54[0x72] = 0;
      PTR_DAT_00025d54[0x71] = 1;
    }
    FUN_fffc8beb();
    PTR_DAT_00025d54[0x70] = 0;
    FUN_fffbc638();
    FUN_fffc4caa();
    FUN_fffc2794();
    PTR_DAT_00025d54[0x96] = 1;
    PTR_DAT_00025d54[0x1c5] = 0;
    return;
  }
  return;
}


// ===== FUN_fffc3b05 @ fffc3b05 (29 bytes)

void FUN_fffc3b05(undefined1 param_1)

{
  DAT_0001b4da = 1;
  FUN_fffc3b22(param_1);
  DAT_0001b4da = 0;
  return;
}


// ===== FUN_fffc3b22 @ fffc3b22 (257 bytes)

void FUN_fffc3b22(undefined1 param_1)

{
  switch(param_1) {
  case 0:
    FUN_fffc3c23(0);
    return;
  case 1:
    FUN_fffc3c23(1);
    return;
  case 2:
    FUN_fffc3c9f();
    return;
  case 3:
    FUN_fffc3cd9();
    return;
  case 4:
    FUN_fffc3c23(4);
    return;
  case 5:
    FUN_fffc3c23(5);
    return;
  case 6:
    FUN_fffc3c23(6);
    return;
  case 7:
    FUN_fffc3c23(7);
    return;
  case 8:
    FUN_fffc3d26();
    return;
  case 9:
    FUN_fffc3c23(9);
    return;
  case 10:
    FUN_fffc3c23(10);
    return;
  case 0xb:
    FUN_fffc3c23(0xb);
    return;
  case 0xc:
    FUN_fffc3c23(0xc);
    return;
  case 0xd:
    FUN_fffc3c23(0xd);
    return;
  case 0xe:
    FUN_fffc3c23(0xe);
    return;
  case 0xf:
    FUN_fffc3c23(0xf);
    return;
  case 0x10:
    FUN_fffc3de8();
    return;
  case 0x11:
    FUN_fffc3eaa();
    return;
  case 0x12:
    FUN_fffc3c23(0x12);
    return;
  case 0x13:
    FUN_fffc3c23(0x13);
    return;
  case 0x14:
    FUN_fffc3c23(0x14);
    return;
  case 0x15:
    FUN_fffe3979();
    return;
  case 0x16:
    FUN_fffe2ee4();
    return;
  case 0x17:
    FUN_fffe2fa8();
    return;
  case 0x18:
    FUN_fffc3f9c();
    return;
  case 0x1a:
    FUN_fffc3c23(0x15);
    return;
  case 0x1b:
    FUN_fffc3c23(0x3a);
    return;
  case 0x1c:
    FUN_fffc1f2a(0);
    return;
  case 0x1d:
    FUN_fffc1f2a(1);
    return;
  case 0x1e:
    FUN_fffc1f2a(2);
    return;
  case 0x1f:
    FUN_fffc1f2a(3);
    return;
  case 0x20:
    FUN_fffc1f2a(4);
    return;
  case 0x21:
  case 0x22:
    FUN_fffc1f94();
  }
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== FUN_fffc3c23 @ fffc3c23 (98 bytes)

void FUN_fffc3c23(undefined1 param_1)

{
  DAT_00009dc9 = param_1;
  PTR_DAT_00025d54[0x1c5] = 1;
  FUN_fffc8e0e(500);
  PTR_DAT_00025d54[0x490] = 1;
  if (PTR_DAT_00025d54[0x483] == '\x01') {
    PTR_DAT_00025d54[0x483] = 0;
  }
  beep_request(1);
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


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

