// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc2371 @ fffc2371 (27 bytes)

void FUN_fffc2371(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = FUN_fffcda51(param_1);
  if (cVar1 != '\x01') {
    return;
  }
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffc238c @ fffc238c (24 bytes)

void FUN_fffc238c(undefined1 param_1)

{
  PTR_DAT_00025d54[0x3ff] = param_1;
  FUN_fffb2da6(1);
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
  FUN_fffb2df4();
  return;
}


// ===== FUN_fffc2426 @ fffc2426 (486 bytes)

undefined1 FUN_fffc2426(void)

{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined *puVar4;
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
        FUN_fffc1c04(1);
        return 1;
      }
    }
    else if (DAT_00009dbe == '\x05') {
      DAT_00009dbe = 1;
      FUN_fffc1c04(0);
      return 1;
    }
    if (bVar1) {
      local_4 = DAT_000060ca;
    }
    else {
      local_4 = DAT_000060c9;
    }
  }
  puVar4 = (undefined *)dest_code_get();
  if (puVar4 == &DAT_0000315b) {
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

undefined1 FUN_fffc260c(undefined1 param_1)

{
  int iVar1;
  undefined1 uStack_3;
  
  iVar1 = FUN_fffc2de9(param_1);
  if (iVar1 == 0) {
    uStack_3 = 0;
  }
  else {
    if (DAT_00009dbe == '\x05') {
      DAT_00009dbe = '\x01';
    }
    if (DAT_00009dbf == '\x05') {
      DAT_00009dbf = '\x01';
    }
    FUN_fffc311a(param_1);
    FUN_fffc2681(param_1);
    FUN_fffc273e(param_1);
    FUN_fffc3081(param_1);
    FUN_fffc18bf();
    FUN_fffc2794();
    PTR_DAT_00025d54[0x40b] = 1;
    uStack_3 = 1;
  }
  return uStack_3;
}


// ===== FUN_fffc2681 @ fffc2681 (189 bytes)

void FUN_fffc2681(char param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  iVar2 = FUN_fffc2de9(param_1);
  if (iVar2 == 0) {
    return;
  }
  bVar1 = FUN_fffc2e65(param_1);
  if (param_1 == '\0') {
    puVar4 = &DAT_00006150 + (uint)bVar1 * 0x5a;
    puVar3 = &DAT_00009d09;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  else {
    puVar4 = &DAT_00006150 + (uint)bVar1 * 0x5a;
    puVar3 = &DAT_00009d63;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  if (param_1 == '\0') {
    PTR_DAT_00025d54[0x425] = 0;
    DAT_00009d0a = DAT_00009d0a & 0xe7;
    DAT_00009d51 = 0;
    DAT_00009d52 = 0;
    return;
  }
  PTR_DAT_00025d54[0x426] = 0;
  DAT_00009d64 = DAT_00009d64 & 0xe7;
  DAT_00009dab = 0;
  DAT_00009dac = 0;
  return;
}


// ===== FUN_fffc273e @ fffc273e (86 bytes)

void FUN_fffc273e(int param_1)

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


// ===== FUN_fffc27ad @ fffc27ad (318 bytes)

void FUN_fffc27ad(void)

{
  bool bVar1;
  char cStack_2;
  char cStack_1;
  
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (DAT_00009dbd == '\0') {
    cStack_1 = '\0';
    cStack_2 = DAT_00009dbe;
    if (DAT_00009dbe != '\x05') {
      FUN_fffc16f6(0);
    }
  }
  else {
    cStack_1 = '\x01';
    cStack_2 = DAT_00009dbf;
    if (DAT_00009dbf != '\x05') {
      FUN_fffc16f6(1);
    }
  }
  if ((cStack_2 == '\x04') || (cStack_2 == '\x03')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fffc28eb(cStack_1);
  }
  else if (cStack_2 == '\x02') {
    FUN_fffc296f(cStack_1);
    if (cStack_1 == '\0') {
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
    FUN_fffc2991(cStack_1);
  }
  FUN_fffc1c04(cStack_1);
  PTR_DAT_00025d54[0x40b] = 1;
  return;
}


// ===== FUN_fffc28eb @ fffc28eb (16 bytes)

void FUN_fffc28eb(undefined1 param_1)

{
  FUN_fffc28fb(param_1);
  FUN_fffc2937(param_1);
  return;
}


// ===== FUN_fffc28fb @ fffc28fb (60 bytes)

void FUN_fffc28fb(int param_1)

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
  undefined1 uVar1;
  
  PTR_DAT_00025d54[0x97] = 1;
  PTR_DAT_00025d54[0x1d9] = 0;
  PTR_DAT_00025d54[0x43b] = 0;
  uVar1 = FUN_fffc2e65(DAT_00009dbd != '\0');
  FUN_fffc2a3d(uVar1);
  return;
}


// ===== FUN_fffc2a3d @ fffc2a3d (213 bytes)

void FUN_fffc2a3d(byte param_1)

{
  short sVar1;
  char cStack_3;
  byte bStack_2;
  
  sVar1 = dest_code_get();
  if ((sVar1 != 0x20b) && (sVar1 != 0x1cb9)) {
    if (sVar1 == -0x26b0) {
LAB_fffc2aa2:
      cStack_3 = '\0';
      bStack_2 = 0x78;
      goto LAB_fffc2ad2;
    }
    if (sVar1 != 0x4380) {
      if (sVar1 != 0x50e2) {
        if (sVar1 == 0x60e6) goto LAB_fffc2aaa;
        if (((sVar1 == -0x5b3b) || (sVar1 == -0x567d)) || (sVar1 == -0x4a59)) goto LAB_fffc2aa2;
        if (sVar1 != 0x315b) {
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
  short sVar2;
  byte local_4;
  
  local_4 = param_1 + param_2;
  sVar2 = dest_code_get();
  if ((sVar2 == 0x4380) || (sVar2 == 0x20b)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (sVar2 == 0x60e6)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (sVar2 == 0x1cb9)) {
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
  int iVar1;
  bool bStack_5;
  char *pcStack_4;
  
  iVar1 = FUN_fffc2ee1(PTR_DAT_00025d54[0x43a]);
  if (iVar1 == 1) {
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
  FUN_fffc16f6(bStack_5);
  if (*pcStack_4 == '\x04') {
    if (0x62 < (byte)PTR_DAT_00025d54[0x43a]) {
      FUN_fffc2c4f();
      return;
    }
    FUN_fffc28fb(bStack_5);
    FUN_fffc2937(bStack_5);
  }
  FUN_fffc273e(bStack_5);
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
  FUN_fffb2da6(2);
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
  FUN_fffb2da6(3);
  return;
}


// ===== FUN_fffc2c66 @ fffc2c66 (98 bytes)

void FUN_fffc2c66(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *apuStack_c [2];
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
  FUN_fffc2e01(PTR_DAT_00025d54[0x43a],apuStack_c);
  *apuStack_c[0] = 1;
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
  puVar1 = (undefined1 *)
           ((int)&DAT_00004761 +
           (uint)DAT_00009dc3 * 0x5a + (uint)(byte)(&DAT_000060b1)[DAT_00009dc3] * 0x438);
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


// ===== FUN_fffc2d93 @ fffc2d93 (86 bytes)

undefined1 FUN_fffc2d93(int param_1)

{
  bool bVar1;
  undefined1 uVar2;
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
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_fffc2de9 @ fffc2de9 (24 bytes)

undefined1 FUN_fffc2de9(undefined1 param_1)

{
  undefined1 uVar1;
  undefined1 auStack_8 [5];
  undefined1 uStack_3;
  undefined1 local_1;
  
  local_1 = param_1;
  uStack_3 = FUN_fffc2e65(param_1);
  uVar1 = FUN_fffc2e01(uStack_3,auStack_8);
  return uVar1;
}


// ===== FUN_fffc2e01 @ fffc2e01 (100 bytes)

bool FUN_fffc2e01(byte param_1,undefined4 *param_2)

{
  int iVar1;
  bool local_11;
  
  if (param_1 == 0x85) {
    local_11 = true;
  }
  else if (param_1 < 0x75) {
    *param_2 = &DAT_000060cb + param_1;
    if ((&DAT_000060cb)[param_1] == '\x01') {
      local_11 = true;
    }
    else {
      local_11 = false;
    }
  }
  else {
    iVar1 = FUN_fffc2e8d(param_1);
    local_11 = iVar1 == 0;
  }
  return local_11;
}


// ===== FUN_fffc2e65 @ fffc2e65 (40 bytes)

undefined1 FUN_fffc2e65(int param_1)

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


// ===== FUN_fffc2e8d @ fffc2e8d (62 bytes)

undefined1 FUN_fffc2e8d(byte param_1)

{
  short sVar1;
  undefined1 uStack_5;
  
  sVar1 = dest_code_get();
  uStack_5 = 0;
  if (((((sVar1 == -0x5b3b) || (sVar1 == -0x567d)) || (sVar1 == -0x4a59)) || (sVar1 == -0x26b0)) &&
     (6 < (int)(param_1 - 0x75))) {
    uStack_5 = 1;
  }
  return uStack_5;
}


// ===== FUN_fffc2ecb @ fffc2ecb (22 bytes)

undefined1 FUN_fffc2ecb(undefined1 param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_fffc2e65(param_1);
  uVar1 = FUN_fffc2ee1(uVar1);
  return uVar1;
}


// ===== FUN_fffc2ee1 @ fffc2ee1 (26 bytes)

bool FUN_fffc2ee1(byte param_1)

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


// ===== FUN_fffc2fde @ fffc2fde (40 bytes)

void FUN_fffc2fde(int param_1)

{
  if (param_1 != 0) {
    PTR_DAT_00025d54[0x445] = 1;
    FUN_fffc127b(1);
    return;
  }
  PTR_DAT_00025d54[0x443] = 1;
  FUN_fffc127b(0);
  return;
}


// ===== FUN_fffc3006 @ fffc3006 (37 bytes)

char FUN_fffc3006(void)

{
  undefined4 uVar1;
  undefined1 uStack_9;
  
  uVar1 = FUN_fffb35d7(0,2);
  uStack_9 = band_of_freq(uVar1);
  if (uStack_9 == -1) {
    uStack_9 = '\v';
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


// ===== FUN_fffc3081 @ fffc3081 (46 bytes)

void FUN_fffc3081(char param_1)

{
  FUN_fffc28fb(param_1);
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


// ===== FUN_fffc311a @ fffc311a (82 bytes)

void FUN_fffc311a(char param_1)

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


// ===== FUN_fffc316c @ fffc316c (59 bytes)

void FUN_fffc316c(uint param_1)

{
  if (param_1 == 0) {
    DAT_00009dbe = 5;
  }
  else {
    DAT_00009dbf = 5;
  }
  FUN_fffc31a7(param_1 & 0xff,1);
  FUN_fffc334c(param_1 & 0xff);
  FUN_fffc33ef();
  FUN_fffb03e1(0);
  FUN_fffec578();
  return;
}


// ===== FUN_fffc31a7 @ fffc31a7 (25 bytes)

void FUN_fffc31a7(undefined1 param_1,char param_2)

{
  FUN_fffc31c0(param_1);
  if (param_2 != '\x01') {
    return;
  }
  FUN_fffc3287(param_1);
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

void FUN_fffc3240(byte param_1,uint param_2)

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
  FUN_fffc3287(param_2 & 0xff);
  return;
}


// ===== FUN_fffc3287 @ fffc3287 (197 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc32ca) */
/* WARNING: Removing unreachable block (ram,0xfffc32d1) */

void FUN_fffc3287(uint param_1)

{
  bool bVar1;
  undefined4 uVar2;
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
  uVar2 = FUN_fffc10c3(param_1 & 0xff,(uint)(byte)local_c[0x4a] << 0x18 | (uint)(byte)local_c[0x4d])
  ;
  DAT_0001b4e2 = 0;
  local_c[0x4a] = (char)((uint)uVar2 >> 0x18);
  local_c[0x4b] = (char)((uint)uVar2 >> 0x10);
  local_c[0x4c] = (char)((uint)uVar2 >> 8);
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
      FUN_fffc2fde(param_1 & 0xff);
      FUN_fffc16f6(param_1 & 0xff);
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
    FUN_fffc1c04(1);
    PTR_DAT_00025d54[0x40b] = 1;
    FUN_fffc311a(0);
    DAT_00009022 = 0;
    return;
  }
  if (DAT_0000901f != '\0') {
    DAT_0000901f = DAT_0000901f + -1;
    return;
  }
  DAT_00009dbe = 1;
  FUN_fffc1c04(0);
  PTR_DAT_00025d54[0x40b] = 1;
  FUN_fffc311a(0);
  DAT_00009020 = 0;
  return;
}

