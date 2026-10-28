// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== cat_ST @ fffaf3b5 (185 bytes)

void cat_ST(int param_1,char param_2)

{
  byte bVar1;
  
  if (param_2 == '\0') {
    if (DAT_00009c5e == '\0') {
      DAT_00001c90 = 0x30;
    }
    else {
      DAT_00001c90 = 0x31;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar1 = key_event_filter(0x305,0);
  if (bVar1 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00020b3d != '\0') {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    if (DAT_00009c5e == '\x01') {
      split_toggle();
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '1') {
      DAT_0000464a = 1;
      return;
    }
    if (DAT_00009c5e == '\0') {
      split_toggle();
      return;
    }
  }
  return;
}


// ===== cat_SV @ fffaf46e (345 bytes)

void cat_SV(uint param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  
  bVar2 = key_event_filter(0x30a,0);
  if (bVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
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
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  vfo_ab_toggle();
  return;
}


// ===== cat_TS @ fffaf5c7 (497 bytes)

void cat_TS(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  undefined1 auStack_5f [90];
  char local_5;
  int local_4;
  
  if (param_2 == '\0') {
    if (DAT_00020f09 == '\x01') {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x30;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if (*(char *)(param_1 + 2) != '1') {
    if (*(char *)(param_1 + 2) != '0') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020f87 = 0;
    if (DAT_00020f09 == '\x01') {
      DAT_00020f09 = 0;
      smovf(auStack_5f,0x9d09,0x5a);
      smovf(0x9d09,0x9d63,0x5a);
      smovf(0x9d63,auStack_5f,0x5a);
      DAT_00020f0f = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  local_5 = param_2;
  local_4 = param_1;
  bVar2 = key_event_filter(0xec,0);
  if (bVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00009c5e != '\x01') {
      DAT_0000464a = 1;
      return;
    }
    DAT_00020f87 = 1;
    if (DAT_00020f09 == '\0') {
      DAT_00020f09 = 1;
      smovf(auStack_5f,0x9d09,0x5a);
      smovf(0x9d09,0x9d63,0x5a);
      smovf(0x9d63,auStack_5f,0x5a);
      DAT_00020f0f = 1;
      return;
    }
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_TX @ fffaf7b8 (188 bytes)

void cat_TX(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  
  if (param_2 == '\0') {
    bVar2 = ptt_source_get();
    if (bVar2 == 0) {
      DAT_00001c90 = 0x30;
    }
    else if (bVar2 == 5) {
      DAT_00001c90 = 0x31;
    }
    else {
      DAT_00001c90 = 0x32;
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  cVar3 = hex2nib(*(byte *)(param_1 + 2));
  if (cVar3 == '\0') {
    DAT_00020b28 = 0;
    return;
  }
  if (cVar3 == '\x01') {
    DAT_00020b28 = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_VD @ fffaf874 (332 bytes)

/* WARNING: Removing unreachable block (ram,0xfffaf93d) */
/* WARNING: Removing unreachable block (ram,0xfffaf902) */
/* WARNING: Removing unreachable block (ram,0xfffaf9bd) */
/* WARNING: Removing unreachable block (ram,0xfffaf9ba) */
/* WARNING: Removing unreachable block (ram,0xfffaf953) */
/* WARNING: Removing unreachable block (ram,0xfffaf9ae) */
/* WARNING: Removing unreachable block (ram,0xfffaf8cd) */

void cat_VD(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    if (DAT_00009af3 == '\0') {
      local_d = DAT_00009bf4;
    }
    else {
      local_d = DAT_00009bf5;
    }
    local_b = 10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      n = local_d;
      if (local_b != 0) {
        n = local_d / local_b;
      }
      local_d = local_d - n * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(n);
      (&DAT_00001c90)[local_c] = cVar2;
    }
    DAT_00001c92 = 0x3b;
    DAT_0001b788 = 5;
    return;
  }
  local_d = 0;
  local_b = 10;
  for (local_c = 2; local_c < 4; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  if (0x21 < local_d) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009af3 == '\0') {
    DAT_00009bf4 = local_d;
  }
  else {
    DAT_00009bf5 = local_d;
  }
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x2a;
    FUN_fffc8cbb(0x2a);
    FUN_fffc8d8c();
    return;
  }
  return;
}


// ===== cat_VG @ fffaf9c0 (283 bytes)

/* WARNING: Removing unreachable block (ram,0xfffafa6b) */
/* WARNING: Removing unreachable block (ram,0xfffafa30) */
/* WARNING: Removing unreachable block (ram,0xfffafad8) */
/* WARNING: Removing unreachable block (ram,0xfffafad5) */
/* WARNING: Removing unreachable block (ram,0xfffafa81) */
/* WARNING: Removing unreachable block (ram,0xfffafac9) */
/* WARNING: Removing unreachable block (ram,0xfffaf9fb) */

void cat_VG(int param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  byte n;
  byte local_d;
  byte local_c;
  byte local_b;
  
  if (param_2 == '\0') {
    local_d = DAT_00009bf3;
    local_b = 100;
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      n = local_d;
      if (local_b != 0) {
        n = local_d / local_b;
      }
      local_d = local_d - n * local_b;
      local_b = local_b / 10;
      cVar2 = nib2hex(n);
      (&DAT_00001c90)[local_c] = cVar2;
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  local_d = 0;
  local_b = 100;
  for (local_c = 2; local_c < 5; local_c = local_c + 1) {
    if ((*(byte *)((uint)local_c + param_1) < 0x30) || (0x39 < *(byte *)((uint)local_c + param_1)))
    {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_0000464a = 1;
      return;
    }
    local_d = (*(byte *)((uint)local_c + param_1) & 0xf) * local_b + local_d;
    local_b = local_b / 10;
  }
  if (100 < local_d) {
    DAT_0000464a = 1;
    return;
  }
  DAT_00009bf3 = local_d;
  if (DAT_00009ace == '\0') {
    DAT_00020cc6 = 0x29;
    FUN_fffc8cbb(0x29);
    FUN_fffc8d8c();
    return;
  }
  return;
}


// ===== cat_VM @ fffafadb (738 bytes)

void cat_VM(int param_1,short param_2)

{
  bool bVar1;
  byte bVar2;
  byte local_8;
  char local_7;
  
  if ((param_2 == 3) || (*(char *)(param_1 + 2) == '0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (DAT_00009dbd == '\0') {
    local_7 = DAT_00009dbe;
    local_8 = DAT_000060c9;
  }
  else {
    local_7 = DAT_00009dbf;
    local_8 = DAT_000060ca;
  }
  if (param_2 == 4) {
    DAT_00001c90 = 0x30;
    if (local_7 == '\x02') {
      if (local_8 < 0x84) {
        if (local_8 < 0x75) {
          if (local_8 < 99) {
            byte2hex(&DAT_00001c91,0x11);
          }
          else {
            byte2hex(&DAT_00001c91,0x21);
          }
        }
        else {
          byte2hex(&DAT_00001c91,0x51);
        }
      }
      else {
        byte2hex(&DAT_00001c91,0x91);
      }
    }
    else if (local_7 == '\x03') {
      byte2hex(&DAT_00001c91,0x10);
    }
    else if (local_7 == '\x04') {
      byte2hex(&DAT_00001c91,0x20);
    }
    else {
      byte2hex(&DAT_00001c91,0);
    }
    DAT_00001c93._0_1_ = 0x3b;
    DAT_0001b788 = 6;
    return;
  }
  bVar2 = key_event_filter(0x309,0);
  if (bVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b8a == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b3d != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020cce == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f1b == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020ccd == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020b7c != '\0')) {
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
  if ((bVar1) || (DAT_00020f11 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (param_2 == 3) {
      vm_toggle();
      return;
    }
    if ((*(char *)(param_1 + 3) == '0') && (*(char *)(param_1 + 4) == '0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (local_7 != '\x01') {
        vm_toggle();
        if (DAT_00009dbd == '\0') {
          local_7 = DAT_00009dbe;
        }
        else {
          local_7 = DAT_00009dbf;
        }
        if (local_7 != '\x01') {
          vm_toggle();
          return;
        }
      }
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_VS @ fffafdbd (483 bytes)

void cat_VS(int param_1,char param_2)

{
  bool bVar1;
  byte bVar2;
  
  if (param_2 == '\0') {
    DAT_00001c90 = nib2hex(DAT_00009dbd);
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar2 = key_event_filter(0x30a,0);
  if (bVar2 != 0) {
    if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020f0c != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b8a == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b3d != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020cce == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020f1b == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020ccd == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b7c != '\0')) {
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
    if ((bVar1) || (DAT_00020f11 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      DAT_00009c5e = 0;
      if (*(char *)(param_1 + 2) == '0') {
        if (DAT_00009dbd == 1) {
          vfo_ab_toggle();
        }
      }
      else {
        if (*(char *)(param_1 + 2) != '1') {
          DAT_0000464a = 1;
          return;
        }
        if (DAT_00009dbd == 0) {
          vfo_ab_toggle();
        }
      }
      DAT_00020f10 = 1;
      return;
    }
    DAT_0000464a = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_VX @ fffaffa0 (206 bytes)

void cat_VX(int param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  
  vfo_rec_ptr(0);
  bVar2 = vfo_mode(1);
  if (param_2 == '\0') {
    uVar1 = (uint)bVar2;
    if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
      DAT_00001c90 = '0';
    }
    else {
      DAT_00001c90 = nib2hex(DAT_00009c5d);
    }
    DAT_00001c91 = 0x3b;
    DAT_0001b788 = 4;
    return;
  }
  bVar3 = key_event_filter(0x302,0);
  if (bVar3 == 0) {
    DAT_0000464a = 1;
    return;
  }
  uVar1 = (uint)bVar2;
  if ((uVar1 - 2 < 2) || (uVar1 == 0xc || uVar1 == 0xd)) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) == '0') {
    DAT_00009c5d = 0;
    return;
  }
  if (*(char *)(param_1 + 2) == '1') {
    DAT_00009c5d = 1;
    return;
  }
  DAT_0000464a = 1;
  return;
}


// ===== cat_ZI @ fffb006e (190 bytes)

void cat_ZI(int param_1)

{
  bool bVar1;
  byte bVar2;
  byte *pbVar3;
  
  bVar2 = key_event_filter(0x307,0);
  if (bVar2 == 0) {
    DAT_0000464a = 1;
    return;
  }
  if ((DAT_00020f1c == '\x01') || (DAT_00020f70 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (DAT_00020f0c != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  if (*(char *)(param_1 + 2) != '0') {
    DAT_0000464a = 1;
    return;
  }
  pbVar3 = vfo_rec_ptr(DAT_00020b6b);
  if (((*pbVar3 & 0xf) == 2) || ((*pbVar3 & 0xf) == 3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0000464a = 1;
    return;
  }
  FUN_fffbf0b6();
  return;
}


// ===== FUN_fffb012c @ fffb012c (58 bytes)

void FUN_fffb012c(int param_1,char param_2,ushort param_3)

{
  ushort local_e;
  
  for (local_e = 0; (local_e < param_3 && (*(char *)((uint)local_e + param_1) != param_2));
      local_e = local_e + 1) {
  }
  return;
}


// ===== cat_reply_error @ fffb0166 (28 bytes)

/* Builds the '?;' error reply (len 2) */

void cat_reply_error(void)

{
  DAT_00001c8e._0_1_ = 0x3f;
  DAT_00001c8e._1_1_ = 0x3b;
  DAT_0001b788 = 2;
  return;
}


// ===== cat_checksum_ok @ fffb0182 (45 bytes)

/* sum8(buf,n)==buf[n]; callers in cat_ext_SP pass n = len-2 (the earlier "n read from RAM[len-2]"
   was the MOVU decoder bug, T10e/T17) */

bool cat_checksum_ok(int param_1,ushort param_2)

{
  char cVar1;
  
  cVar1 = sum8(param_1,param_2);
  return cVar1 == *(char *)((uint)param_2 + param_1);
}


// ===== sum8 @ fffb01af (48 bytes)

/* 8-bit additive checksum of n bytes */

char sum8(int param_1,ushort param_2)

{
  undefined1 local_b;
  undefined2 local_a;
  
  local_b = '\0';
  for (local_a = 0; local_a < param_2; local_a = local_a + 1) {
    local_b = *(char *)((uint)local_a + param_1) + local_b;
  }
  return local_b;
}


// ===== FUN_fffb01df @ fffb01df (20 bytes)

void FUN_fffb01df(byte param_1)

{
  (&DAT_000060cb)[param_1] = 1;
  return;
}


// ===== eeprom_init @ fffb01f3 (54 bytes)

/* Boot: CS high, SCK low, P65 (/WP?) high, WRSR(0x01)=0x80 (SRWD=1, no block protect), P65 low */

void eeprom_init(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 | 1;
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xdf;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 | 0x20;
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xfe;
  eeprom_spi_tx(1);
  eeprom_spi_tx(0x80);
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 | 1;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0xdf;
  return;
}


// ===== eeprom_load_all @ fffb0229 (134 bytes)

/* Boot load: reads header; flag 1 -> mirror EEPROM 0..0x5836 to RAM 0x464F; 0 -> keep cal+dest,
   defaults; else factory init */

void eeprom_load_all(void)

{
  eeprom_read(0,(byte *)&DAT_0000464f,10);
  if (DAT_00004657._1_1_ == '\x01') {
    eeprom_read(0,(byte *)&DAT_0000464f,0x5837);
    return;
  }
  if (DAT_00004657._1_1_ == '\0') {
    eeprom_read(10,&DAT_00004659,0x105);
    eeprom_read(0x10f,&DAT_0000475e,3);
    settings_defaults(0);
  }
  else {
    DAT_00004657 = 0;
    DAT_00004653 = 0;
    DAT_0000464f = 0;
    settings_defaults(1);
    eeprom_save_cfg105();
    eeprom_save_dest();
  }
  DAT_00020b45 = 1;
  return;
}


// ===== eeprom_save_all @ fffb02af (32 bytes)

/* Writes EEPROM 0x0112..0x5836 (RAM 0x4761, 0x5725 bytes) between header updates: power-down and
   first-boot save */

void eeprom_save_all(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x112,&DAT_00004761,0x5725);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_opstate @ fffb02cf (52 bytes)

/* Writes 0x53DB (menu/VFO/state block 0x9A2A, 0x45C) and 0x1A62 (band-stack indices 0x60B1, 0x18)
    */

void eeprom_save_opstate(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x53db,&DAT_00009a2a,0x45c);
  eeprom_write(0x1a62,&DAT_000060b1,0x18);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_bandstack @ fffb0303 (83 bytes)

/* One band-stack entry to EEPROM 0x112/0xDBA + level*0x438 + band*0x5A */

void eeprom_save_bandstack(char param_1,byte param_2,byte param_3,uint param_4)

{
  char cVar1;
  short local_a;
  
  local_a = 0x112;
  cVar1 = supply_undervolt_check();
  if (cVar1 != '\x01') {
    if (param_1 != '\0') {
      local_a = 0xdba;
    }
    eeprom_hdr_update(0);
    eeprom_write((ushort)param_2 * 0x5a + (ushort)param_3 * 0x438 + local_a,(byte *)param_4,0x5a);
    eeprom_hdr_update(1);
    return;
  }
  return;
}


// ===== eeprom_save_image @ fffb0356 (32 bytes)

/* eeprom_write(0x1A7A, 0x60C9, 0x2F49) bracketed by header update */

void eeprom_save_image(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x1a7a,&DAT_000060c9,0x2f49);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_memch @ fffb0376 (75 bytes)

/* Writes the 0x87-byte block at 0x60C9 and one 0x5A-byte memory channel to EEPROM */

void eeprom_save_memch(byte param_1)

{
  char cVar1;
  
  cVar1 = supply_undervolt_check();
  if (cVar1 == '\x01') {
    return;
  }
  eeprom_hdr_update(0);
  eeprom_write(0x1a7a,&DAT_000060c9,0x87);
  eeprom_write((short)((uint)param_1 * 0x5a) + 0x1b01,&DAT_00006150 + (uint)param_1 * 0x5a,0x5a);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_qmb @ fffb03c1 (32 bytes)

/* EEPROM 0x49C3 <- 0x9012 (0x395) */

void eeprom_save_qmb(void)

{
  eeprom_hdr_update(0);
  eeprom_write(0x49c3,&DAT_00009012,0x395);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_qmb_slot @ fffb03e1 (111 bytes)

/* QMB header + one slot */

void eeprom_save_qmb_slot(byte param_1)

{
  char cVar1;
  
  cVar1 = supply_undervolt_check();
  if (cVar1 == '\x01') {
    return;
  }
  eeprom_hdr_update(0);
  eeprom_write(0x49c3,&DAT_00009012,0x11);
  eeprom_write((short)((uint)param_1 * 0x5a) + 0x49d4,&DAT_00009023 + (uint)param_1 * 0x5a,0x5a);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_msg @ fffb0450 (185 bytes)

/* (type, n=1..5): type 0 = 0x98-byte message 0x93A7, 1 = keyer text 0x969F (KM), 2 = text 0x979E
   (EM) */

void eeprom_save_msg(int param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  char cVar3;
  
  cVar3 = supply_undervolt_check();
  if ((cVar3 != '\x01') && (param_1 < 3)) {
    if ((param_2 < 1) || (5 < param_2)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (!bVar2) {
      sVar1 = (short)param_2 + -1;
      eeprom_hdr_update(0);
      if (param_1 == 0) {
        eeprom_write(sVar1 * 0x98 + 0x4d58,&DAT_000093a7 + (ushort)(sVar1 * 0x98),0x98);
      }
      else if (param_1 == 1) {
        eeprom_write(sVar1 * 0x33 + 0x5050,&DAT_0000969f + (ushort)(sVar1 * 0x33),0x33);
      }
      else {
        eeprom_write(sVar1 * 0x32 + 0x514f,
                     (byte *)((int)&DAT_0000979e + (uint)(ushort)(sVar1 * 0x32)),0x32);
      }
      eeprom_hdr_update(1);
      return;
    }
  }
  return;
}


// ===== eeprom_save_atu_mem @ fffb0509 (41 bytes)

/* Writes the 100-entry tuner memory 0x9898 (0x192 bytes) to EEPROM 0x5249 */

void eeprom_save_atu_mem(void)

{
  char cVar1;
  
  cVar1 = supply_undervolt_check();
  if (cVar1 == '\x01') {
    return;
  }
  eeprom_hdr_update(0);
  eeprom_write(0x5249,&DAT_00009898,0x192);
  eeprom_hdr_update(1);
  return;
}


// ===== eeprom_save_cfg105 @ fffb0532 (18 bytes)

/* eeprom_write(0x000A, 0x4659, 0x105) */

void eeprom_save_cfg105(void)

{
  eeprom_write(10,&DAT_00004659,0x105);
  return;
}


// ===== eeprom_save_dest @ fffb0544 (20 bytes)

/* eeprom_write(0x010F, 0x475E, 3): destination code */

void eeprom_save_dest(void)

{
  eeprom_write(0x10f,&DAT_0000475e,3);
  return;
}


// ===== settings_defaults @ fffb0558 (222 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reload settings RAM from ROM defaults; arg 1 also the 0x4659 table and destination 0x8043 */

void settings_defaults(byte param_1)

{
  if (param_1 == 1) {
    smovf(0x4659,0xfff8074f,0x105);
    DAT_00004760 = 0;
    _DAT_0000475e = 0x8043;
  }
  defaults_vfo();
  defaults_bandstack();
  defaults_qmb();
  defaults_memch();
  defaults_msg();
  sstr(0x9898,0,0x192);
  smovf(0x9c69,0xfff80d82,0xa0);
  smovf(0x9c35,0xfff80e22,0x28);
  menu_defaults_load();
  DAT_00009c65 = 0;
  _DAT_00009c61 = 0;
  _DAT_00009c5d = 0x1000000;
  sstr(0x9dbe,0,200);
  smovf(0x9dbe,0xfff80fc6,0x10);
  smovf(0x9c17,0xfff80fd6,0x1e);
  return;
}


// ===== reset_memch @ fffb0636 (4 bytes)

/* -> defaults_memch */

void reset_memch(void)

{
  defaults_memch();
  return;
}


// ===== reset_menu @ fffb063a (4 bytes)

/* -> defaults_menu */

void reset_menu(void)

{
  menu_defaults_load();
  return;
}


// ===== eeprom_read_raw @ fffb063e (19 bytes)

/* Wrapper eeprom_read(addr,buf,n); used by SPR */

void eeprom_read_raw(ushort addr,byte *buf,ushort n)

{
  eeprom_read(addr,buf,n);
  return;
}


// ===== eeprom_write_raw @ fffb0651 (19 bytes)

/* Wrapper eeprom_write(addr,buf,n); used by SPW */

void eeprom_write_raw(ushort param_1,uint param_2,ushort param_3)

{
  eeprom_write(param_1,(byte *)param_2,param_3);
  return;
}


// ===== FUN_fffb0664 @ fffb0664 (129 bytes)

void FUN_fffb0664(int param_1)

{
  *(undefined2 *)(param_1 + 0x12) = 0;
  *(undefined4 *)(param_1 + 0xe) = 0xb80b9600;
  *(undefined4 *)(param_1 + 10) = 0x96004004;
  *(undefined2 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf4019600;
  *(undefined4 *)(param_1 + 0x14) = 0x96004005;
  *(undefined2 *)(param_1 + 0x26) = 0;
  *(undefined4 *)(param_1 + 0x22) = 0xf4019600;
  *(undefined4 *)(param_1 + 0x1e) = 0x96004004;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0x800c9600;
  *(undefined4 *)(param_1 + 0x28) = 0x96004004;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 0x36) = 0x28239600;
  *(undefined4 *)(param_1 + 0x32) = 0x96007004;
  *(undefined2 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0x803e9600;
  *(undefined4 *)(param_1 + 0x3c) = 0x96004001;
  return;
}


// ===== defaults_vfo @ fffb06e5 (148 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Default VFO-A/B working records 0x9D09/0x9D63 (dest-dependent byte +0x46) */

void defaults_vfo(void)

{
  ushort uVar1;
  
  uVar1 = dest_code_get();
  uRam00009d11 = 0;
  _DAT_00009d0d = &DAT_00010200;
  _DAT_00009d09 = 0x80040040;
  smovf(0x9d4f,0xfff80947,0x14);
  FUN_fffb0664(&DAT_00009d09,0xfff8095b,0);
  uRam00009d6b = 0;
  _DAT_00009d67 = &DAT_00010200;
  _DAT_00009d63 = 0x80040040;
  smovf(0x9da9,0xfff80947,0x14);
  FUN_fffb0664(&DAT_00009d63,0xfff8095b,0);
  DAT_00009dbd = 0;
  if (((uVar1 != 0x20b) && (uVar1 != 0x4380)) && (uVar1 != 0x60e6)) {
    return;
  }
  DAT_00009d4f = 8;
  DAT_00009da9 = 8;
  return;
}


// ===== FUN_fffb0779 @ fffb0779 (687 bytes)

void FUN_fffb0779(undefined4 *param_1)

{
  ushort uVar1;
  
  uVar1 = dest_code_get();
  *(undefined2 *)(param_1 + 2) = 0;
  param_1[1] = &DAT_00010200;
  *param_1 = 0x80040042;
  smovf((int)param_1 + 0x46,0xfff8090b,0x14);
  FUN_fffb0664(param_1,0xfff8091f,0);
  *(undefined2 *)((int)param_1 + 0x62) = 0;
  *(undefined **)((int)param_1 + 0x5e) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x5a) = 0x80040040;
  smovf(param_1 + 0x28,0xfff8091f,0x14);
  FUN_fffb0664((int)param_1 + 0x5a,0xfff80933,0);
  *(undefined2 *)(param_1 + 0x2f) = 0;
  param_1[0x2e] = &DAT_00010200;
  param_1[0x2d] = 0x800400c1;
  smovf((int)param_1 + 0xfa,0xfff80933,0x14);
  FUN_fffb0664(param_1 + 0x2d,0xfff80947,0);
  *(undefined2 *)((int)param_1 + 0x116) = 0;
  *(undefined **)((int)param_1 + 0x112) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x10e) = 0x80040040;
  smovf(param_1 + 0x55,0xfff80947,0x14);
  FUN_fffb0664((int)param_1 + 0x10e,0xfff8095b,0);
  *(undefined2 *)(param_1 + 0x5c) = 0;
  param_1[0x5b] = &DAT_00010200;
  param_1[0x5a] = 0x80040042;
  smovf((int)param_1 + 0x1ae,0xfff8095b,0x14);
  FUN_fffb0664(param_1 + 0x5a,0xfff8096f,0);
  *(undefined2 *)((int)param_1 + 0x1ca) = 0;
  *(undefined **)((int)param_1 + 0x1c6) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x1c2) = 0x800400c1;
  smovf(param_1 + 0x82,0xfff8096f,0x14);
  FUN_fffb0664((int)param_1 + 0x1c2,0xfff80983,0);
  *(undefined2 *)(param_1 + 0x89) = 0;
  param_1[0x88] = &DAT_00010200;
  param_1[0x87] = 0x800400c1;
  smovf((int)param_1 + 0x262,0xfff80983,0x14);
  FUN_fffb0664(param_1 + 0x87,0xfff80997,0);
  *(undefined2 *)((int)param_1 + 0x27e) = 0;
  *(undefined **)((int)param_1 + 0x27a) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x276) = 0x800400c1;
  smovf(param_1 + 0xaf,0xfff80997,0x14);
  FUN_fffb0664((int)param_1 + 0x276,0xfff809ab,0);
  *(undefined2 *)(param_1 + 0xb6) = 0;
  param_1[0xb5] = &DAT_00010200;
  param_1[0xb4] = 0x800400c1;
  smovf((int)param_1 + 0x316,0xfff809ab,0x14);
  FUN_fffb0664(param_1 + 0xb4,0xfff809bf,0);
  *(undefined2 *)((int)param_1 + 0x332) = 0;
  *(undefined **)((int)param_1 + 0x32e) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x32a) = 0x800400c1;
  smovf(param_1 + 0xdc,0xfff809bf,0x14);
  FUN_fffb0664((int)param_1 + 0x32a,&LAB_fff809d3,0);
  *(undefined2 *)(param_1 + 0xe3) = 1;
  param_1[0xe2] = &DAT_00010200;
  param_1[0xe1] = 0x800400c1;
  smovf((int)param_1 + 0x3ca,0xfff809d3,0x14);
  FUN_fffb0664(param_1 + 0xe1,0xfff809e7,0);
  *(undefined2 *)((int)param_1 + 0x3e6) = 0;
  *(undefined **)((int)param_1 + 0x3e2) = &DAT_00010200;
  *(undefined4 *)((int)param_1 + 0x3de) = 0x800400c1;
  smovf(param_1 + 0x109,0xfff809e7,0x14);
  FUN_fffb0664((int)param_1 + 0x3de,&DAT_fff809fb,0);
  if (((uVar1 != 0x20b) && (uVar1 != 0x4380)) && (uVar1 != 0x60e6)) {
    return;
  }
  *(undefined1 *)((int)param_1 + 0x46) = 8;
  *(undefined1 *)(param_1 + 0x28) = 8;
  *(undefined1 *)((int)param_1 + 0xfa) = 8;
  *(undefined1 *)(param_1 + 0x55) = 8;
  *(undefined1 *)((int)param_1 + 0x1ae) = 8;
  *(undefined1 *)(param_1 + 0x82) = 8;
  *(undefined1 *)((int)param_1 + 0x262) = 8;
  *(undefined1 *)(param_1 + 0xaf) = 8;
  *(undefined1 *)((int)param_1 + 0x316) = 8;
  *(undefined1 *)(param_1 + 0xdc) = 8;
  *(undefined1 *)((int)param_1 + 0x3ca) = 8;
  *(undefined1 *)(param_1 + 0x109) = 8;
  return;
}


// ===== defaults_bandstack @ fffb0a28 (84 bytes)

/* Clears 0x4761..0x60C8 and fills 6 band-stack sets (FUN_fffb0779 per set) */

void defaults_bandstack(void)

{
  sstr(0x4761,0,0x1968);
  FUN_fffb0779(&DAT_00004761,0,0);
  FUN_fffb0779(0x4b99);
  FUN_fffb0779(0x4fd1);
  FUN_fffb0779(&DAT_00005409);
  FUN_fffb0779(0x5841);
  FUN_fffb0779(0x5c79);
  return;
}


// ===== defaults_qmb @ fffb0a7c (19 bytes)

/* Clears the QMB block 0x9012 (0x395) */

void defaults_qmb(void)

{
  sstr(0x9012,0,0x395);
  return;
}


// ===== defaults_memch @ fffb0a8f (1557 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clears 0x60C9 (0x2F49), default records for 117 channels, dest-specific 60 m channels */

void defaults_memch(void)

{
  ushort uVar1;
  int iVar2;
  byte bStack_b;
  
  uVar1 = dest_code_get();
  sstr(0x60c9,0,0x2f49);
  sstr(0x60c9,0,0x22);
  DAT_000060cb = 1;
  for (bStack_b = 0; bStack_b < 0x75; bStack_b = bStack_b + 1) {
    iVar2 = (uint)bStack_b * 0x5a;
    *(undefined2 *)(iVar2 + 0x6158) = 0;
    *(undefined **)(iVar2 + 0x6154) = &DAT_00010200;
    *(undefined4 *)(&DAT_00006150 + iVar2) = 0x80040040;
    smovf(iVar2 + 0x6196,0xfff80947,0x14);
    FUN_fffb0664(&DAT_00006150 + iVar2,0xfff8095b,0);
  }
  if (uVar1 == 0xd950) {
LAB_fffb0e99:
    uRam00008a7a = 0;
    puRam00008a76 = &DAT_00030200;
    _DAT_00008a72 = 0x80040101;
    smovf(0x8ab8,0xfff80b4f,0x14);
    FUN_fffb0664(&DAT_00008a72,0xfff80b63,0);
    uRam00008ad4 = 0;
    puRam00008ad0 = &DAT_00030200;
    uRam00008acc = 0x80040101;
    smovf(0x8b12,0xfff80b63,0x14);
    FUN_fffb0664(0x8acc,0xfff80b77,0);
    uRam00008b2e = 0;
    puRam00008b2a = &DAT_00030200;
    uRam00008b26 = 0x80040101;
    smovf(0x8b6c,0xfff80b77,0x14);
    FUN_fffb0664(0x8b26,0xfff80b8b,0);
    uRam00008b88 = 0;
    puRam00008b84 = &DAT_00030200;
    uRam00008b80 = 0x80040101;
    smovf(0x8bc6,0xfff80b8b,0x14);
    FUN_fffb0664(0x8b80,0xfff80b9f,0);
    uRam00008be2 = 0;
    puRam00008bde = &DAT_00030200;
    uRam00008bda = 0x80040101;
    smovf(0x8c20,0xfff80b9f,0x14);
    FUN_fffb0664(0x8bda,0xfff80bb3,0);
    uRam00008c3c = 0;
    puRam00008c38 = &DAT_00030200;
    uRam00008c34 = 0x80040101;
    smovf(0x8c7a,0xfff80bb3,0x14);
    FUN_fffb0664(0x8c34,0xfff80bc7,0);
    uRam00008c96 = 0;
    puRam00008c92 = &DAT_00030200;
    uRam00008c8e = 0x80040101;
    smovf(0x8cd4,0xfff80bc7,0x14);
    FUN_fffb0664(0x8c8e,0xfff80bdb,0);
    uRam00008cf0 = 0;
    puRam00008cec = &DAT_00030200;
    uRam00008ce8 = 0x80040101;
    smovf(0x8d2e,0xfff80bdb,0x14);
    FUN_fffb0664(0x8ce8,0xfff80bef,0);
    uRam00008d4a = 0;
    puRam00008d46 = &DAT_00030200;
    uRam00008d42 = 0x80040101;
    smovf(0x8d88,0xfff80bef,0x14);
    FUN_fffb0664(0x8d42,0xfff80c03,0);
    uRam00008da4 = 0;
    puRam00008da0 = &DAT_00030200;
    uRam00008d9c = 0x80040101;
    smovf(0x8de2,0xfff80c03,0x14);
    FUN_fffb0664(0x8d9c,&DAT_fff80c17,0);
    return;
  }
  if (uVar1 == 0x1cb9) {
    uRam00008fc0 = 0;
    puRam00008fbc = &DAT_00030200;
    uRam00008fb8 = 0x80040101;
    smovf(0x8ffe,0xfff80c21,0x14);
    FUN_fffb0664(0x8fb8,&DAT_fff80c35,0);
    return;
  }
  if (uVar1 != 0x315b) {
    if (uVar1 != 0x4380) {
      if (uVar1 == 0x50e2) goto LAB_fffb0b88;
      if (uVar1 != 0x60e6) {
        if (uVar1 == 0xa4c5) goto LAB_fffb0e99;
        if (uVar1 != 0x20b) {
          return;
        }
      }
    }
    uRam00006196 = 8;
    uRam00008fc0 = 0;
    puRam00008fbc = &DAT_00030200;
    uRam00008fb8 = 0x80040003;
    smovf(0x8ffe,0xfff80c3f,0x14);
    FUN_fffb0664(0x8fb8,"",0);
    return;
  }
LAB_fffb0b88:
  for (bStack_b = 0; bStack_b < 0xf; bStack_b = bStack_b + 1) {
    (&DAT_00006140)[bStack_b] = 1;
  }
  uRam00008a7a = 0;
  puRam00008a76 = &DAT_00030200;
  _DAT_00008a72 = 0x80040101;
  smovf(0x8ab8,0xfff80a19,0x14);
  FUN_fffb0664(&DAT_00008a72,0xfff80a2d,0);
  uRam00008ad4 = 0;
  puRam00008ad0 = &DAT_00030200;
  uRam00008acc = 0x80040101;
  smovf(0x8b12,0xfff80a2d,0x14);
  FUN_fffb0664(0x8acc,0xfff80a41,0);
  uRam00008b2e = 0;
  puRam00008b2a = &DAT_00030200;
  uRam00008b26 = 0x80040101;
  smovf(0x8b6c,0xfff80a41,0x14);
  FUN_fffb0664(0x8b26,0xfff80a55,0);
  uRam00008b88 = 0;
  puRam00008b84 = &DAT_00030200;
  uRam00008b80 = 0x80040101;
  smovf(0x8bc6,0xfff80a55,0x14);
  FUN_fffb0664(0x8b80,0xfff80a69,0);
  uRam00008be2 = 0;
  puRam00008bde = &DAT_00030200;
  uRam00008bda = 0x80040101;
  smovf(0x8c20,0xfff80a69,0x14);
  FUN_fffb0664(0x8bda,0xfff80a7d,0);
  uRam00008c3c = 0;
  puRam00008c38 = &DAT_00030200;
  uRam00008c34 = 0x80040103;
  smovf(0x8c7a,0xfff80a7d,0x14);
  FUN_fffb0664(0x8c34,0xfff80a91,0);
  uRam00008c96 = 0;
  puRam00008c92 = &DAT_00030200;
  uRam00008c8e = 0x80040103;
  smovf(0x8cd4,0xfff80a91,0x14);
  FUN_fffb0664(0x8c8e,0xfff80aa5,0);
  uRam00008cf0 = 0;
  puRam00008cec = &DAT_00030200;
  uRam00008ce8 = 0x80040103;
  smovf(0x8d2e,0xfff80aa5,0x14);
  FUN_fffb0664(0x8ce8,0xfff80ab9,0);
  uRam00008d4a = 0;
  puRam00008d46 = &DAT_00030200;
  uRam00008d42 = 0x80040103;
  smovf(0x8d88,0xfff80ab9,0x14);
  FUN_fffb0664(0x8d42,0xfff80acd,0);
  uRam00008da4 = 0;
  puRam00008da0 = &DAT_00030200;
  uRam00008d9c = 0x80040103;
  smovf(0x8de2,0xfff80acd,0x14);
  FUN_fffb0664(0x8d9c,0xfff80ae1,0);
  uRam00008dfe = 0;
  puRam00008dfa = &DAT_00030200;
  uRam00008df6 = 0x80040109;
  smovf(0x8e3c,0xfff80ae1,0x14);
  FUN_fffb0664(0x8df6,0xfff80af5,0);
  uRam00008e58 = 0;
  puRam00008e54 = &DAT_00030200;
  uRam00008e50 = 0x80040109;
  smovf(0x8e96,0xfff80af5,0x14);
  FUN_fffb0664(0x8e50,0xfff80b09,0);
  uRam00008eb2 = 0;
  puRam00008eae = &DAT_00030200;
  uRam00008eaa = 0x80040109;
  smovf(0x8ef0,0xfff80b09,0x14);
  FUN_fffb0664(0x8eaa,0xfff80b1d,0);
  uRam00008f0c = 0;
  puRam00008f08 = &DAT_00030200;
  uRam00008f04 = 0x80040109;
  smovf(0x8f4a,0xfff80b1d,0x14);
  FUN_fffb0664(0x8f04,0xfff80b31,0);
  uRam00008f66 = 0;
  puRam00008f62 = &DAT_00030200;
  uRam00008f5e = 0x80040109;
  smovf(0x8fa4,0xfff80b31,0x14);
  FUN_fffb0664(0x8f5e,&DAT_fff80b45,0);
  uRam00008fc0 = 0;
  puRam00008fbc = &DAT_00030200;
  uRam00008fb8 = 0x80040101;
  smovf(0x8ffe,0xfff80c21,0x14);
  FUN_fffb0664(0x8fb8,&DAT_fff80c35,0);
  return;
}


// ===== defaults_msg @ fffb10a4 (196 bytes)

/* Clears 0x93A7 (0x4F1), keyer texts from ROM 0xFFF80C53.. */

void defaults_msg(void)

{
  sstr(0x93a7,0,0x4f1);
  smovf(0x969f,0xfff80c53,0x33);
  smovf(0x96d2,0xfff80c53,0x33);
  smovf(0x9705,0xfff80c53,0x33);
  smovf(0x9738,0xfff80c86,0x33);
  smovf(0x976b,0xfff80cb9,0x33);
  smovf(0x979e,0xfff80cec,0x32);
  smovf(0x97d0,0xfff80cec,0x32);
  smovf(0x9802,0xfff80cec,0x32);
  smovf(0x9834,0xfff80d1e,0x32);
  smovf(0x9866,0xfff80d50,0x32);
  return;
}


// ===== menu_defaults_load @ fffb1168 (43 bytes)

/* Reset menu value block 0x9A2A.. from ROM 0xFFF80E4A.. (callees below) + 0x9C17<-0xFFF80FD6 */

void menu_defaults_load(void)

{
  menu_defaults_mode();
  menu_defaults_cw();
  menu_defaults_operation();
  menu_defaults_display();
  FUN_fffb1303();
  menu_defaults_presets();
  FUN_fffb13e2();
  smovf(0x9c17,0xfff80fd6,0x1e);
  return;
}


// ===== menu_defaults_mode @ fffb1193 (93 bytes)

/* RADIO SETTING mode groups 0x9A2A..0x9A90 <- ROM */

void menu_defaults_mode(void)

{
  smovf(0x9a2a,0xfff80e4a,0x15);
  smovf(0x9a3f,0xfff80e5f,0x13);
  smovf(0x9a52,0xfff80e72,0x15);
  smovf(0x9a67,0xfff80e87,0x17);
  smovf(0x9a7e,0xfff80e9e,0x13);
  return;
}


// ===== menu_defaults_cw @ fffb11f0 (29 bytes)

/* CW SETTING 0x9A91..0x9AB4 <- ROM 0xFFF80EB1 */

void menu_defaults_cw(void)

{
  smovf(0x9a91,0xfff80eb1,0x24);
  return;
}


// ===== menu_defaults_operation @ fffb120d (217 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb12c1) */
/* WARNING: Removing unreachable block (ram,0xfffb12e3) */
/* WARNING: Removing unreachable block (ram,0xfffb12c9) */
/* WARNING: Removing unreachable block (ram,0xfffb12d6) */
/* OPERATION SETTING 0x9AB5.. <- ROM 0xFFF80ED5, then dest-dependent MAX POWER, KEYBOARD LANGUAGE,
   TX TOT */

void menu_defaults_operation(void)

{
  ushort uVar1;
  
  uVar1 = dest_code_get();
  smovf(0x9ab5,0xfff80ed5,0x4c);
  DAT_00009aee = FUN_fffb3e6f(0,0xfff80f21,0);
  DAT_00009aef = FUN_fffb3e6f(1);
  DAT_00009af0 = FUN_fffb3e6f(2);
  if (uVar1 == 0x60e6) {
    DAT_00009af1 = FUN_fffb3e6f(4);
  }
  else {
    DAT_00009af1 = FUN_fffb3e6f(3);
  }
  if (uVar1 == 0xd950) {
    DAT_00009ac7 = 2;
    DAT_00009ac3 = 10;
    return;
  }
  if (((uVar1 != 0x1cb9) && (uVar1 != 0x306f)) && (uVar1 != 0x315b)) {
    if (uVar1 == 0x4380) {
      DAT_00009ac7 = 0;
      return;
    }
    if (uVar1 != 0x50e2) {
      if (uVar1 == 0x60e6) {
        DAT_00009ac7 = 0;
        return;
      }
      if ((uVar1 != 0x7753) && (uVar1 != 0x9cf7)) {
        if (uVar1 == 0xa4c5) {
          DAT_00009ac3 = 10;
          DAT_00009ac7 = 2;
          return;
        }
        if (uVar1 != 0xd32d) {
          if (uVar1 == 0x20b) {
            DAT_00009ac7 = 0;
            return;
          }
          DAT_00009ac7 = 5;
          DAT_00009ac3 = 10;
          return;
        }
      }
    }
  }
  DAT_00009ac7 = 1;
  return;
}


// ===== menu_defaults_display @ fffb12e6 (29 bytes)

/* DISPLAY SETTING 0x9B01.. <- ROM 0xFFF80F21 */

void menu_defaults_display(void)

{
  smovf(0x9b01,0xfff80f21,0x23);
  return;
}


// ===== FUN_fffb1303 @ fffb1303 (34 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffb1303(void)

{
  _DAT_00009b2c = 0;
  _DAT_00009b28 = 0;
  _DAT_00009b24 = 0;
  return;
}


// ===== menu_defaults_presets @ fffb1325 (189 bytes)

/* 5 x PRESET block 0x9B2E+0x1F*n <- ROM 0xFFF80F4E; names FT-8, PRESET2..5 */

void menu_defaults_presets(void)

{
  smovf(0x9b2e,0xfff80f4e,0x1f);
  smovf(0x9b4d,0xfff80f4e,0x1f);
  smovf(0x9b6c,0xfff80f4e,0x1f);
  smovf(0x9b8b,0xfff80f4e,0x1f);
  smovf(0x9baa,0xfff80f4e,0x1f);
  DAT_00009b2e = 0x382d5446;
  DAT_00009b51._2_1_ = 0x32;
  DAT_00009b51._0_2_ = 0x5445;
  DAT_00009b4d = 0x53455250;
  DAT_00009b70._0_2_ = 0x5445;
  DAT_00009b70._2_1_ = 0x33;
  DAT_00009b6c = 0x53455250;
  DAT_00009b8f._2_1_ = 0x34;
  DAT_00009b8f._0_2_ = 0x5445;
  DAT_00009b8b = 0x53455250;
  DAT_00009bae._2_1_ = 0x35;
  DAT_00009bae._0_2_ = 0x5445;
  DAT_00009baa = 0x53455250;
  DAT_00009bc9 = 0;
  return;
}


// ===== FUN_fffb13e2 @ fffb13e2 (73 bytes)

undefined4 FUN_fffb13e2(void)

{
  smovf(0x9bca,0xfff80f6d,0x4d);
  DAT_00009bf8 = DAT_00009aee;
  DAT_00009bf9 = DAT_00009aef;
  DAT_00009bfa = DAT_00009af0;
  DAT_00009bfb = DAT_00009af1;
  return 0;
}


// ===== eeprom_hdr_update @ fffb142b (121 bytes)

/* Increments the save counter in the EEPROM header mirror 0x464F and writes 10 bytes at EEPROM 0 */

void eeprom_hdr_update(byte param_1)

{
  uint local_8;
  byte local_2;
  
  local_8 = 0;
  for (local_2 = 0; local_2 < 4; local_2 = local_2 + 1) {
    local_8 = (uint)*(byte *)((int)&DAT_00004653 + local_2 + 1) << (3 - local_2 & 3) * 8 | local_8;
  }
  for (local_2 = 0; local_2 < 4; local_2 = local_2 + 1) {
    *(char *)((int)&DAT_00004653 + local_2 + 1) = (char)(local_8 + 1 >> ((3 - local_2 & 3) << 3));
  }
  DAT_00004657._1_1_ = param_1;
  eeprom_write(0,(byte *)&DAT_0000464f,10);
  return;
}


// ===== eeprom_read @ fffb14a4 (73 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb14a4) */
/* WARNING: Removing unreachable block (ram,0xfffb14ea) */
/* SPI READ (0x03) + 16-bit address, reads n bytes */

void eeprom_read(ushort addr,byte *buf,ushort n)

{
  byte bVar1;
  ushort local_10;
  byte bStack_6;
  
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 & 0xfe;
  eeprom_spi_tx(3);
  eeprom_spi_tx((byte)(addr >> 8));
  bStack_6 = (byte)addr;
  eeprom_spi_tx(bStack_6);
  for (local_10 = 0; local_10 < n; local_10 = local_10 + 1) {
    bVar1 = eeprom_spi_rx();
    buf[local_10] = bVar1;
  }
  bVar1 = DAT_0008c02e;
  DAT_0008c02e = bVar1 | 1;
  return;
}

