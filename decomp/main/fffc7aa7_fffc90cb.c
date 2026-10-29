// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc7aa7 @ fffc7aa7 (67 bytes)

void FUN_fffc7aa7(char param_1)

{
  undefined2 uStack_4;
  
  FUN_fffc8cbb(0x30);
  FUN_fffc8d8c();
  uStack_4 = (ushort)DAT_00009c03 + (short)param_1;
  if (uStack_4 < 0x3d) {
    if (uStack_4 < 4) {
      uStack_4 = 4;
    }
  }
  else {
    uStack_4 = 0x3c;
  }
  DAT_00009c03 = (undefined1)uStack_4;
  return;
}


// ===== FUN_fffc7aea @ fffc7aea (24 bytes)

void FUN_fffc7aea(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x31;
  FUN_fffc7b02((int)param_1);
  return;
}


// ===== FUN_fffc7b02 @ fffc7b02 (69 bytes)

void FUN_fffc7b02(char param_1)

{
  undefined2 uStack_4;
  
  FUN_fffc8cbb(0x31);
  FUN_fffc8d8c();
  uStack_4 = (ushort)DAT_00009c04 + (short)param_1;
  if (uStack_4 < 0x4c) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 0x4b;
  }
  DAT_00009c04 = (undefined1)uStack_4;
  return;
}


// ===== FUN_fffc7b47 @ fffc7b47 (24 bytes)

void FUN_fffc7b47(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x32;
  FUN_fffc7b5f((int)param_1);
  return;
}


// ===== FUN_fffc7b5f @ fffc7b5f (69 bytes)

void FUN_fffc7b5f(char param_1)

{
  undefined2 uStack_4;
  
  FUN_fffc8cbb(0x32);
  FUN_fffc8d8c();
  uStack_4 = (ushort)DAT_00009c05 + (short)param_1;
  if (uStack_4 < 0x22) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 0x21;
  }
  DAT_00009c05 = (undefined1)uStack_4;
  return;
}


// ===== FUN_fffc7ba4 @ fffc7ba4 (24 bytes)

void FUN_fffc7ba4(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x33;
  FUN_fffc7bbc((int)param_1);
  return;
}


// ===== FUN_fffc7bbc @ fffc7bbc (65 bytes)

void FUN_fffc7bbc(char param_1)

{
  byte *pbVar1;
  undefined2 uStack_4;
  
  pbVar1 = (byte *)FUN_fffb54a0();
  FUN_fffc8cbb(0x33);
  FUN_fffc8d8c();
  uStack_4 = (ushort)*pbVar1 + (short)param_1;
  if (uStack_4 < 0x15) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 0x14;
  }
  *pbVar1 = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7bfd @ fffc7bfd (24 bytes)

void FUN_fffc7bfd(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x58;
  FUN_fffc7c15((int)param_1);
  return;
}


// ===== FUN_fffc7c15 @ fffc7c15 (64 bytes)

void FUN_fffc7c15(char param_1)

{
  byte *pbVar1;
  undefined2 uStack_4;
  
  pbVar1 = (byte *)FUN_fffb552c();
  FUN_fffc8cbb(0x58);
  FUN_fffc8d8c();
  uStack_4 = (ushort)*pbVar1 + (short)param_1;
  if (uStack_4 < 2) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 1;
  }
  *pbVar1 = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7c55 @ fffc7c55 (168 bytes)

void FUN_fffc7c55(char param_1)

{
  short sVar1;
  
  if (PTR_DAT_00025d58[0x490] != '\x01') {
    sVar1 = (ushort)DAT_00009c08 + (short)param_1;
    if ('\0' < param_1) {
      if (0x20 < sVar1) {
        DAT_00009c08 = 0x21;
        return;
      }
      if (sVar1 == 0x19) {
        DAT_00009c08 = 0x1a;
        return;
      }
      DAT_00009c08 = DAT_00009c08 + 1;
      return;
    }
    if (param_1 < '\0') {
      if (sVar1 < 1) {
        DAT_00009c08 = 0;
        return;
      }
      if (sVar1 == 0x19) {
        DAT_00009c08 = 0x18;
        return;
      }
      DAT_00009c08 = DAT_00009c08 - 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffc7cfd @ fffc7cfd (68 bytes)

void FUN_fffc7cfd(char param_1)

{
  undefined2 uStack_4;
  
  FUN_fffc8cbb(0x38);
  FUN_fffc8d8c();
  uStack_4 = (ushort)DAT_00009dc0 + (short)param_1;
  if (uStack_4 < 0xb) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 10;
  }
  DAT_00009dc0 = (undefined1)uStack_4;
  return;
}


// ===== FUN_fffc7d41 @ fffc7d41 (110 bytes)

void FUN_fffc7d41(char param_1)

{
  byte *pbStack_8;
  short sStack_4;
  
  FUN_fffc8cbb(0x39);
  FUN_fffc8d8c();
  if (DAT_00009dbd == '\0') {
    pbStack_8 = &DAT_00009d0f;
  }
  else {
    pbStack_8 = &DAT_00009d69;
  }
  sStack_4 = (*pbStack_8 & 0xf) + (short)param_1;
  if (sStack_4 < 0x10) {
    if (sStack_4 < 1) {
      sStack_4 = 1;
    }
  }
  else {
    sStack_4 = 0xf;
  }
  *pbStack_8 = *pbStack_8 & 0xf0 | (byte)sStack_4;
  FUN_fffc515d((byte)sStack_4);
  return;
}


// ===== enc3_step @ fffc7daf (316 bytes)

/* encoder id 3 by screen [inference: multi knob] */

void enc3_step(char param_1)

{
  byte bVar1;
  char local_2;
  
  if (PTR_DAT_00025d58[0x437] == '\x01') {
    FUN_fffc82b7((int)param_1);
    return;
  }
  if (PTR_DAT_00025d58[0xba] == '\x01') {
    FUN_fffbba04((int)param_1);
    return;
  }
  if ((DAT_00020b8a == '\x01') || (DAT_00020b99 == '\x01')) {
    return;
  }
  if (PTR_DAT_00025d58[0x70] == '\x01') {
    bVar1 = PTR_DAT_00025d58[0x73];
    if (PTR_DAT_00025d58[0x74] == '\x01') {
      FUN_fffc836a((int)param_1);
      return;
    }
    if (param_1 < '\0') {
      if (bVar1 < (byte)-param_1) {
        local_2 = '\0';
      }
      else {
        local_2 = bVar1 + param_1;
      }
    }
    else {
      local_2 = param_1 + bVar1;
    }
    if (local_2 == '\x02') {
      PTR_DAT_00025d58[0x7a] = 0x1f;
    }
    else if (local_2 == '\x01') {
      PTR_DAT_00025d58[0x7a] = 0x1e;
    }
    else if (local_2 == '\0') {
      PTR_DAT_00025d58[0x7a] = 0x1d;
    }
    else {
      if (PTR_DAT_00025d58[0x47a] == '\0') {
        PTR_DAT_00025d58[0x7a] = 0x20;
      }
      else {
        PTR_DAT_00025d58[0x7a] = 0x21;
      }
      local_2 = '\x03';
    }
    PTR_DAT_00025d58[0x73] = local_2;
    FUN_fffc89b0();
    return;
  }
  if (DAT_00009c62 == '\0') {
    FUN_fffc7eeb((int)param_1);
    return;
  }
  PTR_DAT_00025d58[0x1c2] = 0x47;
  FUN_fffc8cbb(0x47);
  FUN_fffc8d8c();
  return;
}


// ===== FUN_fffc7eeb @ fffc7eeb (225 bytes)

void FUN_fffc7eeb(byte param_1)

{
  bool bVar1;
  byte bVar2;
  byte local_5;
  
  if ((char)param_1 < '\0') {
    PTR_DAT_00025d58[0x47c] = 1;
    local_5 = ~param_1 + 1;
  }
  else {
    PTR_DAT_00025d58[0x47c] = 0;
    local_5 = param_1;
  }
  DAT_0001ff6c = DAT_0001ff6c + (char)param_1;
  FUN_fffc4caa();
  if (PTR_DAT_00025d58[0x97] != '\x01') {
    if (PTR_DAT_00025d58[0x405] == '\x01') {
      bVar1 = DAT_00009dbd == '\0';
      bVar2 = vfo_is_memory(bVar1);
      if ((bVar2 == 1) && (bVar2 = memch_current_is_special(bVar1), bVar2 == 1)) {
        return;
      }
    }
    if (PTR_DAT_00025d58[0x407] == '\x01') {
      FUN_fffc5bb9(local_5);
      return;
    }
    FUN_fffc81e5();
    return;
  }
  if (PTR_DAT_00025d58[0x1c1] != '\x01') {
    FUN_fffc6800((int)(char)param_1);
    return;
  }
  if ((1 < (byte)PTR_DAT_00025d58[0x1c2] - 0x44) && ((byte)PTR_DAT_00025d58[0x1c2] != 0x55)) {
    return;
  }
  FUN_fffc6800((int)(char)param_1);
  return;
}


// ===== FUN_fffc7fcc @ fffc7fcc (178 bytes)

void FUN_fffc7fcc(void)

{
  bool bVar1;
  char local_1;
  
  PTR_DAT_00025d58[0x478] = 1;
  if (DAT_00009c5e == '\0') {
    if (DAT_00009dbd == '\0') {
      local_1 = '\0';
    }
    else {
      local_1 = '\x01';
    }
  }
  else {
    if (DAT_00009dbd == '\0') {
      if (PTR_DAT_00025d58[0x405] == '\0') {
        local_1 = '\x01';
      }
      else {
        local_1 = '\0';
      }
    }
    else if (PTR_DAT_00025d58[0x405] == '\0') {
      local_1 = '\0';
    }
    else {
      local_1 = '\x01';
    }
    if ((PTR_DAT_00025d58[0x482] == '\x01') && (PTR_DAT_00025d58[0x405] == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (local_1 == '\0') {
        local_1 = '\x01';
      }
      else {
        local_1 = '\0';
      }
    }
  }
  FUN_fffc807e(local_1);
  PTR_DAT_00025d58[0x478] = 0;
  return;
}


// ===== FUN_fffc807e @ fffc807e (31 bytes)

void FUN_fffc807e(undefined1 param_1)

{
  if (PTR_DAT_00025d58[0x47c] != '\0') {
    FUN_fffc8141();
    return;
  }
  FUN_fffc809d(param_1);
  return;
}


// ===== FUN_fffc809d @ fffc809d (164 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc8107) */
/* WARNING: Removing unreachable block (ram,0xfffc810d) */

void FUN_fffc809d(uint param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte local_c;
  byte *local_8;
  char local_2;
  
  bVar1 = (byte)param_1;
  if (param_1 == 0) {
    local_2 = DAT_00009dbe;
    local_8 = (byte *)&DAT_00009d53;
  }
  else {
    local_2 = DAT_00009dbf;
    local_8 = (byte *)&DAT_00009dad;
  }
  if (local_2 == '\x02') {
    if (PTR_DAT_00025d58[0x46b] == '\x01') {
      FUN_fffc5541(bVar1);
      return;
    }
    bVar2 = memch_current_is_special(bVar1);
    if (bVar2 == 1) {
      return;
    }
    FUN_fffc2efb(param_1 & 0xff);
  }
  uVar3 = FUN_fffc5ec4(bVar1,(uint)*local_8 << 0x18 | (uint)local_8[1] << 0x10 |
                             (uint)local_8[2] << 8 | (uint)local_8[3]);
  *local_8 = (byte)(uVar3 >> 0x18);
  local_8[1] = (byte)(uVar3 >> 0x10);
  local_8[2] = (byte)(uVar3 >> 8);
  local_c = (byte)uVar3;
  local_8[3] = local_c;
  return;
}


// ===== FUN_fffc8141 @ fffc8141 (164 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc81ab) */
/* WARNING: Removing unreachable block (ram,0xfffc81b1) */

void FUN_fffc8141(uint param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte local_c;
  byte *local_8;
  char local_2;
  
  bVar1 = (byte)param_1;
  if (param_1 == 0) {
    local_2 = DAT_00009dbe;
    local_8 = (byte *)&DAT_00009d53;
  }
  else {
    local_2 = DAT_00009dbf;
    local_8 = (byte *)&DAT_00009dad;
  }
  if (local_2 == '\x02') {
    if (PTR_DAT_00025d58[0x46b] == '\x01') {
      FUN_fffc55d7(bVar1);
      return;
    }
    bVar2 = memch_current_is_special(bVar1);
    if (bVar2 == 1) {
      return;
    }
    FUN_fffc2efb(param_1 & 0xff);
  }
  uVar3 = FUN_fffc6073(bVar1,(uint)*local_8 << 0x18 | (uint)local_8[1] << 0x10 |
                             (uint)local_8[2] << 8 | (uint)local_8[3]);
  *local_8 = (byte)(uVar3 >> 0x18);
  local_8[1] = (byte)(uVar3 >> 0x10);
  local_8[2] = (byte)(uVar3 >> 8);
  local_c = (byte)uVar3;
  local_8[3] = local_c;
  return;
}


// ===== FUN_fffc81e5 @ fffc81e5 (210 bytes)

void FUN_fffc81e5(undefined1 param_1)

{
  bool bVar1;
  char local_3;
  bool local_2;
  
  if (DAT_00009dbd == '\0') {
    local_3 = DAT_00009dbe;
  }
  else {
    local_3 = DAT_00009dbf;
  }
  local_2 = DAT_00009dbd != '\0';
  if ((local_3 == '\a') || (local_3 == '\b')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc54cc(param_1,local_2);
    return;
  }
  if (DAT_00009c5e == '\x01') {
    FUN_fffc7fcc();
    return;
  }
  if ((local_3 == '\x01') || (local_3 == '\x04')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc7fcc();
    return;
  }
  if (local_3 == '\x02') {
    FUN_fffc54cc(param_1,local_2);
    return;
  }
  if (local_3 == '\x03') {
    vm_toggle();
    vfo_enter_mem_state(local_2);
    FUN_fffc2937(local_2);
    return;
  }
  if (local_3 != '\x05') {
    return;
  }
  if (DAT_00009dbd == '\0') {
    DAT_00009dbe = 1;
    return;
  }
  DAT_00009dbf = 1;
  return;
}


// ===== FUN_fffc82b7 @ fffc82b7 (179 bytes)

void FUN_fffc82b7(char param_1)

{
  if (param_1 < '\x01') {
    if (DAT_0001b4ed < DAT_0001b4ec) {
      DAT_0001b4ec = DAT_0001b4ec - 1;
    }
    else {
      DAT_0001b4ec = DAT_0001b4ee;
    }
  }
  else if (DAT_0001b4ec < DAT_0001b4ee) {
    DAT_0001b4ec = DAT_0001b4ec + 1;
  }
  else {
    DAT_0001b4ec = DAT_0001b4ed;
  }
  if (DAT_0001b4ec == DAT_0001b4ed) {
    PTR_DAT_00025d58[0xb7] = 0;
    PTR_DAT_00025d58[0xb8] = 0xff;
    PTR_DAT_00025d58[0xb9] = 0xff;
    return;
  }
  PTR_DAT_00025d58[0xb7] = 1;
  PTR_DAT_00025d58[0xb8] = DAT_0001b4ec - 1;
  return;
}


// ===== FUN_fffc836a @ fffc836a (199 bytes)

void FUN_fffc836a(char param_1)

{
  if (PTR_DAT_00025d58[0x70] == '\x01') {
    if (PTR_DAT_00025d58[0x7a] == '\x1d') {
      FUN_fffc8431((int)param_1);
      PTR_DAT_00025d58[0x73] = 0;
    }
    else if (PTR_DAT_00025d58[0x7a] == '\x1e') {
      FUN_fffc84f9(param_1);
      PTR_DAT_00025d58[0x73] = 1;
    }
    else if (PTR_DAT_00025d58[0x7a] == '\x1f') {
      FUN_fffc8685((int)param_1);
      PTR_DAT_00025d58[0x73] = 2;
    }
    else if (PTR_DAT_00025d58[0x7a] == ' ') {
      FUN_fffc87ab((int)param_1);
      PTR_DAT_00025d58[0x73] = 3;
    }
    else if (PTR_DAT_00025d58[0x7a] == '!') {
      FUN_fffc8930((int)param_1);
      PTR_DAT_00025d58[0x73] = 3;
    }
  }
  FUN_fffc89b0();
  return;
}


// ===== FUN_fffc8431 @ fffc8431 (200 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc84aa) */

void FUN_fffc8431(char param_1)

{
  uint uVar1;
  byte *local_10;
  short local_c;
  byte *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  uVar1 = *local_8 & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_10 = local_8 + 0x1c;
      goto LAB_fffc84a2;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        local_10 = local_8 + 0x26;
      }
      else {
        if ((*local_8 & 0xf) != 0 && uVar1 != 1) {
          return;
        }
        local_10 = local_8 + 0x12;
      }
      goto LAB_fffc84a2;
    }
  }
  local_10 = local_8 + 0x30;
LAB_fffc84a2:
  local_c = param_1 * 0x14 + CONCAT11(*local_10,local_10[1]);
  if (local_c < 0x4b1) {
    if (local_c < -0x4b0) {
      local_c = -0x4b0;
    }
  }
  else {
    local_c = 0x4b0;
  }
  *local_10 = (byte)((ushort)local_c >> 8);
  local_10[1] = (byte)local_c;
  PTR_DAT_00025d58[0x40c] = 1;
  return;
}


// ===== FUN_fffc84f9 @ fffc84f9 (396 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc860a) */

void FUN_fffc84f9(char param_1)

{
  uint uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uStack_18;
  short sStack_16;
  byte bStack_14;
  char cStack_13;
  undefined2 uStack_12;
  byte *pbStack_10;
  byte local_9;
  byte *local_8;
  char local_1;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  local_9 = *local_8 & 0xf;
  local_1 = param_1;
  uVar2 = FUN_fffc4e4f(&uStack_18);
  if (uVar2 == 0) {
    return;
  }
  uVar1 = (uint)local_9;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      if (local_8[4] != 0) {
        *(undefined2 *)(local_8 + 0x1a) = uStack_18;
        local_8[4] = local_8[4] & 0xdf;
      }
      pbStack_10 = local_8 + 0x1a;
      goto LAB_fffc8602;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        if (local_8[4] != 0) {
          *(undefined2 *)(local_8 + 0x24) = uStack_18;
          local_8[4] = local_8[4] & 0xf7;
        }
        pbStack_10 = local_8 + 0x24;
      }
      else {
        if (1 < uVar1) {
          return;
        }
        if (local_8[4] != 0) {
          *(undefined2 *)(local_8 + 0x10) = uStack_18;
          local_8[4] = local_8[4] & 0x7f;
        }
        pbStack_10 = local_8 + 0x10;
      }
      goto LAB_fffc8602;
    }
  }
  if (local_8[4] != 0) {
    *(undefined2 *)(local_8 + 0x2e) = uStack_18;
    local_8[4] = local_8[4] & 0xfb;
  }
  pbStack_10 = local_8 + 0x2e;
LAB_fffc8602:
  uStack_12 = CONCAT11(*pbStack_10,pbStack_10[1]);
  cStack_13 = FUN_fffb36ff(local_9,uStack_12);
  if ((cStack_13 != -1) && (bStack_14 = FUN_fffb37cd(local_9), bStack_14 != 0xff)) {
    sStack_16 = (short)cStack_13 + (short)local_1;
    if (sStack_16 < 0) {
      cStack_13 = '\0';
    }
    else if ((int)(bStack_14 - 1) < (int)sStack_16) {
      cStack_13 = bStack_14 - 1;
    }
    else {
      cStack_13 = (char)sStack_16;
    }
    uVar3 = FUN_fffb3775(local_9,cStack_13);
    *pbStack_10 = (byte)((ushort)uVar3 >> 8);
    pbStack_10[1] = (byte)uVar3;
    PTR_DAT_00025d58[0x40c] = 1;
    return;
  }
  return;
}


// ===== FUN_fffc8685 @ fffc8685 (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc875b) */

void FUN_fffc8685(char param_1)

{
  bool bVar1;
  uint uVar2;
  byte *local_14;
  byte *local_10;
  short local_c;
  byte *local_8;
  
  bVar1 = false;
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  uVar2 = *local_8 & 0xf;
  if (uVar2 == 0xe) {
LAB_fffc8745:
    local_10 = local_8 + 0x2c;
    local_14 = local_8 + 0x28;
  }
  else {
    if (uVar2 - 2 < 2) {
      local_10 = local_8 + 0x18;
      local_14 = local_8 + 0x14;
      goto LAB_fffc8753;
    }
    if (uVar2 - 4 < 2) {
      local_10 = local_8 + 0x36;
      local_14 = local_8 + 0x32;
      bVar1 = true;
      goto LAB_fffc8753;
    }
    if (1 < uVar2 - 6) {
      if (uVar2 - 8 < 2) goto LAB_fffc8745;
      if (1 < uVar2 - 10) {
        if (uVar2 - 0xc < 2) {
          local_10 = local_8 + 0x22;
          local_14 = local_8 + 0x1e;
        }
        else {
          if ((*local_8 & 0xf) != 0 && uVar2 != 1) {
            return;
          }
          local_10 = local_8 + 0xe;
          local_14 = local_8 + 10;
        }
        goto LAB_fffc8753;
      }
    }
    local_10 = local_8 + 0x40;
    local_14 = local_8 + 0x3c;
    bVar1 = true;
  }
LAB_fffc8753:
  local_c = CONCAT11(*local_10,local_10[1]) + (short)param_1;
  if (local_c < 0x141) {
    if (local_c < 1) {
      local_c = 1;
    }
  }
  else {
    local_c = 0x140;
  }
  *local_10 = (byte)((ushort)local_c >> 8);
  local_10[1] = (byte)local_c;
  if (!bVar1) {
    *local_14 = *local_14 | 0x80;
  }
  PTR_DAT_00025d58[0x40c] = 1;
  return;
}


// ===== FUN_fffc87ab @ fffc87ab (389 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc88b9) */
/* WARNING: Removing unreachable block (ram,0xfffc88ac) */

void FUN_fffc87ab(char param_1)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  byte local_2a [21];
  undefined1 local_15;
  byte *local_14;
  byte *local_10;
  short local_c;
  ushort local_a;
  byte *local_8;
  char local_1;
  
  local_1 = param_1;
  local_15 = 0;
  bVar2 = false;
  local_2a[0x12] = 3;
  local_2a[0x13] = 4;
  local_2a[0xe] = 4;
  local_2a[0xf] = 0;
  local_2a[0x10] = 1;
  local_2a[0x11] = 2;
  local_2a[10] = 0;
  local_2a[0xb] = 1;
  local_2a[0xc] = 2;
  local_2a[0xd] = 3;
  local_2a[8] = 2;
  local_2a[9] = 1;
  local_2a[4] = 1;
  local_2a[5] = 0;
  local_2a[6] = 4;
  local_2a[7] = 3;
  local_2a[0] = 0;
  local_2a[1] = 4;
  local_2a[2] = 3;
  local_2a[3] = 2;
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  uVar3 = *local_8 & 0xf;
  if (uVar3 == 0xe) {
LAB_fffc8896:
    local_10 = local_8 + 0x2a;
    local_14 = local_8 + 0x28;
  }
  else {
    if (uVar3 - 2 < 2) {
      local_10 = local_8 + 0x16;
      local_14 = local_8 + 0x14;
      goto LAB_fffc88a4;
    }
    if (uVar3 - 4 < 2) {
      local_10 = local_8 + 0x34;
      local_14 = local_8 + 0x32;
      local_15 = 1;
      bVar2 = true;
      goto LAB_fffc88a4;
    }
    if (1 < uVar3 - 6) {
      if (uVar3 - 8 < 2) goto LAB_fffc8896;
      if (1 < uVar3 - 10) {
        if (uVar3 - 0xc < 2) {
          local_10 = local_8 + 0x20;
          local_14 = local_8 + 0x1e;
        }
        else {
          if ((*local_8 & 0xf) != 0 && uVar3 != 1) {
            return;
          }
          local_10 = local_8 + 0xc;
          local_14 = local_8 + 10;
        }
        goto LAB_fffc88a4;
      }
    }
    local_10 = local_8 + 0x3e;
    local_14 = local_8 + 0x3c;
    local_15 = 1;
    bVar2 = true;
  }
LAB_fffc88a4:
  local_a = CONCAT11(*local_10,local_10[1]);
  local_2a[0x14] = local_10[1] + (char)(local_a / 10) * -10;
  if (param_1 < '\x01') {
    uVar1 = (ushort)local_2a[local_2a[0x14]];
  }
  else {
    uVar1 = -(ushort)local_2a[local_2a[0x14] + 10];
  }
  local_a = local_a + uVar1;
  local_c = param_1 * 5 + local_a;
  if (local_c < 0x141) {
    if (local_c < 5) {
      local_c = 5;
    }
  }
  else {
    local_c = 0x140;
  }
  *local_10 = (byte)((ushort)local_c >> 8);
  local_10[1] = (byte)local_c;
  if (!bVar2) {
    *local_14 = *local_14 | 0x40;
  }
  PTR_DAT_00025d58[0x40c] = 1;
  return;
}


// ===== FUN_fffc8930 @ fffc8930 (128 bytes)

void FUN_fffc8930(char param_1)

{
  undefined1 *local_8;
  short local_4;
  
  local_4 = (short)DAT_00009c5f + (short)param_1;
  if (local_4 < 0x1a) {
    if (local_4 < -0x19) {
      local_4 = -0x19;
    }
  }
  else {
    local_4 = 0x19;
  }
  DAT_00009c5f = (undefined1)local_4;
  PTR_DAT_00025d58[0x40c] = 1;
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  local_8[0x14] = local_8[0x14] | 0x20;
  PTR_DAT_00025d58[0x40c] = 1;
  return;
}


// ===== FUN_fffc89b0 @ fffc89b0 (63 bytes)

void FUN_fffc89b0(void)

{
  if (PTR_DAT_00025d58[0x70] == '\0') {
    FUN_fffc8beb();
    FUN_fffbc638();
    FUN_fffc3c85();
    PTR_DAT_00025d58[0x70] = 1;
    PTR_DAT_00025d58[0x74] = 0;
  }
  swtimer_start(0x44,5000);
  return;
}


// ===== FUN_fffc89ef @ fffc89ef (161 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc8a6e) */

void FUN_fffc89ef(byte param_1)

{
  undefined *puVar1;
  ushort local_4;
  
  PTR_DAT_00025d58[0x1c2] = 0x5e;
  DAT_00012229 = 0x20;
  DAT_00012225 = 0x20202020;
  DAT_00012221 = 0x204e4f43;
  if (param_1 < 10) {
    local_4 = 7;
  }
  else if (param_1 < 100) {
    local_4 = 6;
  }
  else {
    local_4 = 5;
  }
  FUN_fff9c6f0(param_1,(int)&DAT_00012221 + (uint)local_4);
  puVar1 = PTR_DAT_00025d58;
  PTR_DAT_00025d58[0x42f] = DAT_00012229;
  *(undefined4 *)(puVar1 + 0x42b) = DAT_00012225;
  *(undefined4 *)(puVar1 + 0x427) = DAT_00012221;
  FUN_fffc8cbb(0x5e);
  FUN_fffc8d8c();
  local_4._0_1_ = (undefined1)(((uint)param_1 * 0x14) / 0xff);
  PTR_DAT_00025d58[0x481] = (undefined1)local_4;
  PTR_DAT_00025d58[0x400] = 1;
  return;
}


// ===== FUN_fffc8a90 @ fffc8a90 (197 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc8b33) */

void FUN_fffc8a90(byte param_1)

{
  undefined *puVar1;
  undefined1 uStack_4;
  
  PTR_DAT_00025d58[0x1c2] = 0x5e;
  DAT_00012232 = 0x20;
  DAT_0001222e = 0x20202020;
  DAT_0001222a = 0x204d4944;
  if (param_1 == 0) {
    DAT_0001222e = 0x46464f20;
  }
  else if (param_1 < 10) {
    FUN_fff9c6f0(param_1,0x12231);
  }
  else if (param_1 < 100) {
    FUN_fff9c6f0(param_1,0x12230);
  }
  else {
    FUN_fff9c6f0(param_1,0x1222f);
  }
  puVar1 = PTR_DAT_00025d58;
  PTR_DAT_00025d58[0x42f] = DAT_00012232;
  *(undefined4 *)(puVar1 + 0x42b) = DAT_0001222e;
  *(undefined4 *)(puVar1 + 0x427) = DAT_0001222a;
  FUN_fffc8cbb(0x5e);
  FUN_fffc8d8c();
  uStack_4 = (undefined1)(((uint)param_1 * 0x14) / 0xff);
  PTR_DAT_00025d58[0x480] = uStack_4;
  PTR_DAT_00025d58[0x400] = 1;
  return;
}


// ===== FUN_fffc8b55 @ fffc8b55 (42 bytes)

void FUN_fffc8b55(void)

{
  FUN_fffc8b7f();
  FUN_fffc8dd8();
  FUN_fffc8e26();
  FUN_fffc8ee2();
  FUN_fffc9046();
  FUN_fffbba2e();
  FUN_fffc8fa6();
  FUN_fffc8f48();
  FUN_fffe1ee4();
  FUN_fffc9084();
  FUN_fffc90cb();
  FUN_fffc8ff9();
  FUN_fffc90fc();
  return;
}


// ===== FUN_fffc8b7f @ fffc8b7f (108 bytes)

void FUN_fffc8b7f(void)

{
  uint uVar1;
  byte bVar2;
  
  if ((((DAT_0001b4ef != '\0') && (PTR_DAT_00025d5c[0x1c1] == '\x01')) &&
      (uVar1 = (uint)(byte)PTR_DAT_00025d5c[0x1c2], 2 < uVar1 - 6)) &&
     (((uVar1 != 0xd && (uVar1 != 0x49)) &&
      (((byte)PTR_DAT_00025d5c[0x1c2] < 0x5f && (bVar2 = swtimer_expired(0x39), bVar2 == 1)))))) {
    FUN_fffc8beb();
    DAT_0001b4f3 = 1;
    swtimer_start(0x49,200);
    return;
  }
  return;
}


// ===== FUN_fffc8beb @ fffc8beb (189 bytes)

void FUN_fffc8beb(void)

{
  bool bVar1;
  
  FUN_fffc15d4();
  if ((PTR_DAT_00025d5c[0x1c2] == 'U') || (PTR_DAT_00025d5c[0x1c2] == 'D')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d5c[0x1c2] == 'E')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d5c[0x43c] = 0;
    PTR_DAT_00025d5c[0x43b] = 0;
  }
  PTR_DAT_00025d5c[0x1c1] = 0;
  PTR_DAT_00025d5c[0x8f] = 0;
  PTR_DAT_00025d5c[0x41c] = 0;
  FUN_fffe1f3d();
  PTR_DAT_00025d5c[0x1c0] = 1;
  PTR_DAT_00025d5c[0x1c2] = 0xff;
  DAT_0001b4ef = 0;
  FUN_fffc90b4();
  return;
}


// ===== FUN_fffc8ca8 @ fffc8ca8 (19 bytes)

undefined1 FUN_fffc8ca8(void)

{
  return PTR_DAT_00025d5c[0x1c1];
}


// ===== FUN_fffc8cbb @ fffc8cbb (209 bytes)

undefined2 FUN_fffc8cbb(byte param_1)

{
  bool bVar1;
  undefined2 local_a;
  char local_8;
  
  if (param_1 < 0xe) {
    local_8 = '\0';
  }
  else {
    if ((param_1 < 0x1e) || (0x58 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_8 = '\x01';
    }
    else {
      if (param_1 != 0x5e) {
        return 0;
      }
      local_8 = '\x02';
    }
  }
  if (local_8 == '\0') {
    if (0xd < param_1) {
      return 0;
    }
    local_a = *(undefined2 *)
               ((uint)BYTE_ARRAY_fff834be[param_1 + 0xd] * 6 + -0x77ab2 + (uint)DAT_00009b0e * 2);
  }
  else if (local_8 == '\x01') {
    if (0x3a < (byte)(param_1 - 0x1e)) {
      return 0;
    }
    local_a = *(undefined2 *)
               ((uint)BYTE_ARRAY_fff834d6[(byte)(param_1 - 0x1e) + 3] * 6 + -0x77a9a +
               (uint)DAT_00009b0e * 2);
  }
  else {
    local_a = *(undefined2 *)(BYTE_ARRAY_fff88514 + (uint)DAT_00009b0e * 2 + 100);
  }
  return local_a;
}


// ===== FUN_fffc8d8c @ fffc8d8c (76 bytes)

void FUN_fffc8d8c(int param_1)

{
  if (param_1 == 0) {
    DAT_0001b4ef = 0;
  }
  else {
    DAT_0001b4ef = 1;
    swtimer_start(0x39,(ushort)param_1);
  }
  PTR_DAT_00025d5c[0x1c1] = 1;
  PTR_DAT_00025d5c[0x1c0] = 1;
  PTR_DAT_00025d5c[0x70] = 0;
  return;
}


// ===== FUN_fffc8dd8 @ fffc8dd8 (54 bytes)

void FUN_fffc8dd8(void)

{
  byte bVar1;
  
  if ((DAT_0001b4f0 != '\0') && (bVar1 = swtimer_expired(0x3a), bVar1 == 1)) {
    DAT_0001b4f0 = 0;
    FUN_fffc3c85();
    FUN_fffc8beb();
    PTR_DAT_00025d5c[0x490] = 0;
    return;
  }
  return;
}


// ===== FUN_fffc8e0e @ fffc8e0e (24 bytes)

void FUN_fffc8e0e(ushort param_1)

{
  DAT_0001b4f0 = 1;
  swtimer_start(0x3a,param_1);
  return;
}


// ===== FUN_fffc8e26 @ fffc8e26 (150 bytes)

void FUN_fffc8e26(void)

{
  byte bVar1;
  
  if (PTR_DAT_00025d5c[0x415] != '\0') {
    bVar1 = blink_phase(0);
    if (bVar1 == 1) {
      if (DAT_0001b4f5 != '\x01') {
        PTR_DAT_00025d5c[0x423] = 0;
        DAT_0001b4f5 = '\x01';
        PTR_DAT_00025d5c[0x422] = PTR_DAT_00025d5c[0x422] + '\x01';
        if (5 < (byte)PTR_DAT_00025d5c[0x422]) {
          PTR_DAT_00025d5c[0x422] = 0;
          PTR_DAT_00025d5c[0x415] = 0;
          return;
        }
      }
    }
    else if (DAT_0001b4f5 != '\0') {
      PTR_DAT_00025d5c[0x423] = 1;
      DAT_0001b4f5 = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffc8ebc @ fffc8ebc (38 bytes)

void FUN_fffc8ebc(void)

{
  PTR_DAT_00025d5c[0x422] = 0;
  PTR_DAT_00025d5c[0x423] = 0;
  swtimer_start(0x3d,0x1c2);
  return;
}


// ===== FUN_fffc8ee2 @ fffc8ee2 (78 bytes)

void FUN_fffc8ee2(void)

{
  byte bVar1;
  
  if ((((DAT_0001b4f1 != '\0') && (bVar1 = swtimer_expired(0x3e), bVar1 == 1)) &&
      (DAT_0001b4f1 = '\0', PTR_DAT_00025d5c[0x95] == '\x01')) &&
     (PTR_DAT_00025d5c[0x3ff] == '\x03')) {
    PTR_DAT_00025d5c[0x3ff] = 2;
    return;
  }
  return;
}


// ===== FUN_fffc8f30 @ fffc8f30 (24 bytes)

void FUN_fffc8f30(ushort param_1)

{
  DAT_0001b4f1 = 1;
  swtimer_start(0x3e,param_1);
  return;
}


// ===== FUN_fffc8f48 @ fffc8f48 (67 bytes)

void FUN_fffc8f48(void)

{
  byte bVar1;
  
  if (((PTR_DAT_00025d5c[0x84] != '\0') && (bVar1 = swtimer_expired(0x43), bVar1 == 1)) &&
     (PTR_DAT_00025d5c[0x84] = 0, PTR_DAT_00025d5c[0x88] == '\x01')) {
    PTR_DAT_00025d5c[0x87] = 1;
    return;
  }
  return;
}


// ===== FUN_fffc8f8b @ fffc8f8b (27 bytes)

void FUN_fffc8f8b(ushort param_1)

{
  PTR_DAT_00025d5c[0x84] = 1;
  swtimer_start(0x43,param_1);
  return;
}


// ===== FUN_fffc8fa6 @ fffc8fa6 (83 bytes)

void FUN_fffc8fa6(void)

{
  byte bVar1;
  
  if ((PTR_DAT_00025d5c[0x70] != '\0') && (bVar1 = swtimer_expired(0x44), bVar1 == 1)) {
    PTR_DAT_00025d5c[0x70] = 0;
    PTR_DAT_00025d5c[0x72] = 0;
    PTR_DAT_00025d5c[0x71] = 1;
    DAT_0001b4f3 = 1;
    swtimer_start(0x49,200);
    return;
  }
  return;
}


// ===== FUN_fffc8ff9 @ fffc8ff9 (77 bytes)

void FUN_fffc8ff9(void)

{
  byte bVar1;
  
  if (((PTR_DAT_00025d5c[0x70] != '\0') && (PTR_DAT_00025d5c[0x72] != '\0')) &&
     (bVar1 = swtimer_expired(0x45), bVar1 == 1)) {
    if (PTR_DAT_00025d5c[0x71] == '\0') {
      PTR_DAT_00025d5c[0x71] = 1;
    }
    else {
      PTR_DAT_00025d5c[0x71] = 0;
    }
    swtimer_start(0x45,0x1c2);
    return;
  }
  return;
}


// ===== FUN_fffc9046 @ fffc9046 (62 bytes)

void FUN_fffc9046(void)

{
  byte bVar1;
  
  if ((PTR_DAT_00025d5c[0x438] != '\0') && (bVar1 = swtimer_expired(0x41), bVar1 == 1)) {
    PTR_DAT_00025d5c[0x438] = 0;
    FUN_fff98727(DAT_00012233,DAT_00012234);
    return;
  }
  return;
}


// ===== FUN_fffc9084 @ fffc9084 (27 bytes)

void FUN_fffc9084(void)

{
  byte bVar1;
  
  if ((DAT_0001b4f2 != '\0') && (bVar1 = swtimer_expired(0x48), bVar1 == 1)) {
    FUN_fffc90b4();
    return;
  }
  return;
}


// ===== FUN_fffc909f @ fffc909f (21 bytes)

void FUN_fffc909f(void)

{
  DAT_0001b4f2 = 1;
  swtimer_start(0x48,0x2ee);
  return;
}


// ===== FUN_fffc90b4 @ fffc90b4 (23 bytes)

void FUN_fffc90b4(void)

{
  DAT_0001b4f2 = 0;
  PTR_DAT_00025d5c[0x1c3] = 0;
  return;
}


// ===== FUN_fffc90cb @ fffc90cb (34 bytes)

void FUN_fffc90cb(void)

{
  byte bVar1;
  
  if ((DAT_0001b4f3 == '\x01') && (bVar1 = swtimer_expired(0x49), bVar1 == 1)) {
    DAT_0001b4f3 = 0;
    return;
  }
  return;
}

