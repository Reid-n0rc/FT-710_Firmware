// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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

undefined1 * FUN_fffc3fef(undefined1 *param_1)

{
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    FUN_fffbc638();
    FUN_fffc23b6();
    FUN_fffc4caa();
    PTR_DAT_00025d54[0x405] = 1;
    smovf(0x121c7,0x9d09,0x5a);
    smovf(0x9d09,0x9d63,0x5a);
    smovf(0x9d63,0x121c7,0x5a);
    PTR_DAT_00025d54[0x40b] = 1;
    return &DAT_00009dbd;
  }
  scan_stop();
  return param_1;
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

undefined * FUN_fffc40d7(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    return (&PTR_key_nop_fff8e0cc)[uVar1];
  }
  return (&key_press_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)];
}


// ===== FUN_fffc410a @ fffc410a (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc412a) */

undefined * FUN_fffc410a(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    return (&PTR_LAB_fff8e0ec)[uVar1];
  }
  return (&key_short_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)];
}


// ===== FUN_fffc413d @ fffc413d (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc415d) */

undefined * FUN_fffc413d(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    return (&PTR_LAB_fff8e10c)[uVar1];
  }
  return (&key_long_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)];
}


// ===== FUN_fffc4170 @ fffc4170 (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc4190) */

undefined * FUN_fffc4170(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    return (&PTR_LAB_fff8e12c)[uVar1];
  }
  return (&key_repeat_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)];
}


// ===== FUN_fffc41a3 @ fffc41a3 (51 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc41c3) */

undefined * FUN_fffc41a3(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xc < uVar1) {
    return (&PTR_LAB_fff8e14c)[uVar1];
  }
  return (&key_release_table)[*(ushort *)(BYTE_ARRAY_fff88514 + uVar1 * 2 + 0x20)];
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


// ===== key_nop @ fffc4a8d (1 bytes)

/* empty key handler (RTS) */

void key_nop(void)

{
  return;
}


// ===== FUN_fffc4a8e @ fffc4a8e (103 bytes)

void FUN_fffc4a8e(void)

{
  PTR_DAT_00025d54[0x443] = 1;
  PTR_DAT_00025d54[0x445] = 1;
  if (DAT_00009dbe == '\x05') {
    DAT_00009dbe = '\x01';
  }
  if (DAT_00009dbf == '\x05') {
    DAT_00009dbf = '\x01';
  }
  FUN_fffc4af5();
  vfo_reload(0);
  vfo_reload(1);
  PTR_DAT_00025d54[0x40b] = 1;
  return;
}


// ===== FUN_fffc4af5 @ fffc4af5 (72 bytes)

void FUN_fffc4af5(void)

{
  bool bVar1;
  byte local_1;
  
  local_1 = DAT_00009014;
  if ((DAT_00009ac0 == '\0') && (4 < DAT_00009014)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_1 = 5;
  }
  DAT_0000901f = local_1;
  DAT_00009021 = local_1;
  return;
}


// ===== FUN_fffc4b3d @ fffc4b3d (152 bytes)

void FUN_fffc4b3d(void)

{
  return;
}


// ===== FUN_fffc4bd5 @ fffc4bd5 (121 bytes)

void FUN_fffc4bd5(undefined1 param_1)

{
  switch(param_1) {
  case 0:
    FUN_fffc0d33(0);
    return;
  case 1:
    FUN_fffc0d33(1);
    return;
  case 2:
    FUN_fffc0d33(2);
    return;
  case 3:
    FUN_fffc0d33(3);
    return;
  case 4:
    FUN_fffc0e31();
    return;
  case 5:
    FUN_fffc0e3e();
    return;
  case 6:
    FUN_fffc0e4b();
    return;
  case 7:
    FUN_fffc0e58();
    return;
  case 8:
    FUN_fffc0d33(8);
    return;
  case 9:
    FUN_fffc0d33(9);
    return;
  case 10:
    FUN_fffc0e65();
    return;
  case 0xb:
    FUN_fffc0e72();
    return;
  case 0xc:
    FUN_fffc0d33(0xc);
    return;
  case 0xd:
    FUN_fffc0d33(0xd);
    return;
  case 0xe:
    FUN_fffc0d33(0xe);
    return;
  case 0xf:
    FUN_fffc0e7f();
    return;
  default:
    return;
  }
}


// ===== band_select_on @ fffc4c4e (61 bytes)

/* (band, side): band_select with 0x9DBD temporarily = side (CAT BS/BU/BD) */

void band_select_on(byte param_1,byte param_2)

{
  undefined1 uVar1;
  
  uVar1 = DAT_00009dbd;
  DAT_00009dbd = param_2;
  band_select(param_1);
  DAT_00009c5e = 0;
  DAT_00009dbd = uVar1;
  FUN_fffec578();
  return;
}


// ===== FUN_fffc4c8b @ fffc4c8b (11 bytes)

void FUN_fffc4c8b(undefined1 param_1)

{
  FUN_fffc1f2a(param_1);
  return;
}


// ===== FUN_fffc4c96 @ fffc4c96 (20 bytes)

void FUN_fffc4c96(void)

{
  swtimer_start(0x40,200);
  DAT_0001b4dc = 1;
  return;
}


// ===== FUN_fffc4caa @ fffc4caa (27 bytes)

void FUN_fffc4caa(void)

{
  PTR_DAT_00025d54[0x415] = 0;
  PTR_DAT_00025d54[0x423] = 0;
  return;
}


// ===== FUN_fffc4cc5 @ fffc4cc5 (206 bytes)

undefined1 FUN_fffc4cc5(short param_1,uint param_2)

{
  undefined *puVar1;
  undefined1 local_d;
  char *pcStack_c;
  byte bStack_8;
  byte bStack_6;
  
  local_d = 0;
  if (PTR_DAT_00025d54[0x437] == '\x01') {
    if (((byte)param_2 & 0xf) == 1) {
      FUN_fffc8beb();
      PTR_DAT_00025d54[0x1c2] = 0x5e;
      puVar1 = PTR_DAT_00025d54;
      bStack_8 = 0xff;
      if ((char)(param_2 >> 4) != '\x04') {
        for (bStack_6 = 0; bStack_6 < 0x1c; bStack_6 = bStack_6 + 1) {
          if (*(short *)(BYTE_ARRAY_fff88270 + (uint)bStack_6 * 0xc + 0x154) == param_1) {
            bStack_8 = bStack_6;
            break;
          }
        }
      }
      if (bStack_8 == 0xff) {
        pcStack_c = "  DISPLAY";
      }
      else {
        pcStack_c = " LOCK/PWR" + (uint)bStack_8 * 0xc;
      }
      PTR_DAT_00025d54[0x42f] = pcStack_c[8];
      *(undefined4 *)(puVar1 + 0x42b) = *(undefined4 *)(pcStack_c + 4);
      *(undefined4 *)(puVar1 + 0x427) = *(undefined4 *)pcStack_c;
      FUN_fffc8cbb(0x5e);
      FUN_fffc8d8c();
      beep_request(1);
    }
    local_d = 1;
  }
  return local_d;
}


// ===== FUN_fffc4d93 @ fffc4d93 (89 bytes)

void FUN_fffc4d93(void)

{
  int iVar1;
  int iVar2;
  byte local_2;
  
  local_2 = DAT_00009bc9;
  if (4 < DAT_00009bc9) {
    local_2 = 4;
  }
  iVar1 = (int)&DAT_00009b2e + (uint)local_2 * 0x1f;
  iVar2 = FUN_fffede1d(&DAT_00020b4c,iVar1,0x1f);
  if (iVar2 != 0) {
    smovf(0x20b4c,iVar1,0x1f);
    sci3_set_baud();
    return;
  }
  return;
}


// ===== FUN_fffc4dec @ fffc4dec (99 bytes)

void FUN_fffc4dec(void)

{
  bool bVar1;
  char cVar2;
  
  bVar1 = DAT_00009dbd != '\0';
  cVar2 = PTR_DAT_00025d54[0x73];
  if (cVar2 == '\x03') {
    if (PTR_DAT_00025d54[0x47a] != '\0') {
      FUN_fffc388d();
      return;
    }
    FUN_fffc3773(bVar1);
    return;
  }
  if (cVar2 == '\x01') {
    FUN_fffc3582(bVar1);
    return;
  }
  if (cVar2 == '\x02') {
    FUN_fffc3659(bVar1);
    return;
  }
  if (cVar2 != '\0') {
    return;
  }
  FUN_fffc3503(bVar1);
  return;
}


// ===== FUN_fffc4e4f @ fffc4e4f (320 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc4f7a) */

ushort FUN_fffc4e4f(void *param_1)

{
  uint uVar1;
  bool bVar2;
  undefined1 *local_10;
  ushort local_c;
  undefined1 local_9;
  byte local_8;
  byte local_7;
  
  bVar2 = false;
  if (DAT_00009dbd == '\0') {
    local_8 = DAT_00009d0d;
    local_10 = &DAT_00009d09;
    local_7 = DAT_00009d09;
  }
  else {
    local_8 = DAT_00009d67;
    local_10 = &DAT_00009d63;
    local_7 = DAT_00009d63;
  }
  local_7 = local_7 & 0xf;
  uVar1 = (uint)local_7;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      if ((local_8 & 0x20) == 0) {
        *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x1a);
      }
      else {
        local_9 = DAT_00009a9e;
        bVar2 = true;
      }
      goto LAB_fffc4f4c;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        if ((local_8 & 8) == 0) {
          *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x24);
        }
        else {
          local_9 = DAT_00009a8b;
          bVar2 = true;
        }
      }
      else {
        if (1 < uVar1) {
          return 0;
        }
        if ((local_8 & 0x80) == 0) {
          *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x10);
        }
        else {
          local_9 = DAT_00009a3b;
          bVar2 = true;
        }
      }
      goto LAB_fffc4f4c;
    }
  }
  if ((local_8 & 4) == 0) {
    *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x2e);
  }
  else {
    local_9 = DAT_00009a78;
    bVar2 = true;
  }
LAB_fffc4f4c:
  if (bVar2) {
    local_c = FUN_fffb3775(local_7,local_9);
    if (param_1 != (void *)0x0) {
      *(char *)param_1 = (char)(local_c >> 8);
      *(char *)((int)param_1 + 1) = (char)local_c;
    }
  }
  else {
    local_c = CONCAT11(*(undefined1 *)param_1,*(undefined1 *)((int)param_1 + 1));
  }
  return local_c;
}

