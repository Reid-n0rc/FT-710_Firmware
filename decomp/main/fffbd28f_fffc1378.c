// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffbd28f @ fffbd28f (20 bytes)

void FUN_fffbd28f(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\x04') {
    return;
  }
  FUN_fffc078d();
  return;
}


// ===== FUN_fffbd326 @ fffbd326 (20 bytes)

void FUN_fffbd326(void)

{
  if (PTR_DAT_00025d54[0x1c2] != '\0') {
    return;
  }
  FUN_fffc078d();
  return;
}


// ===== FUN_fffbda47 @ fffbda47 (107 bytes)

void FUN_fffbda47(void)

{
  if (PTR_DAT_00025d54[0x74] == '\0') {
    PTR_DAT_00025d54[0x74] = 1;
    PTR_DAT_00025d54[0x7a] = 0x1d;
    PTR_DAT_00025d54[0x73] = 0;
    FUN_fffc89b0();
    PTR_DAT_00025d54[0x72] = 1;
    FUN_fffb237a(0x45,0x1c2);
  }
  else {
    PTR_DAT_00025d54[0x74] = 0;
    PTR_DAT_00025d54[0x72] = 0;
    PTR_DAT_00025d54[0x71] = 1;
  }
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffbdad5 @ fffbdad5 (107 bytes)

void FUN_fffbdad5(void)

{
  if (PTR_DAT_00025d54[0x74] == '\0') {
    PTR_DAT_00025d54[0x74] = 1;
    PTR_DAT_00025d54[0x7a] = 0x1e;
    PTR_DAT_00025d54[0x73] = 1;
    FUN_fffc89b0();
    PTR_DAT_00025d54[0x72] = 1;
    FUN_fffb237a(0x45,0x1c2);
  }
  else {
    PTR_DAT_00025d54[0x74] = 0;
    PTR_DAT_00025d54[0x72] = 0;
    PTR_DAT_00025d54[0x71] = 1;
  }
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffbdb63 @ fffbdb63 (298 bytes)

void FUN_fffbdb63(void)

{
  byte bVar1;
  uint uVar2;
  byte *local_8;
  byte *local_4;
  
  if (PTR_DAT_00025d54[0x74] != '\0') {
    PTR_DAT_00025d54[0x74] = 0;
    PTR_DAT_00025d54[0x72] = 0;
    PTR_DAT_00025d54[0x71] = 1;
    goto LAB_fffbdc83;
  }
  PTR_DAT_00025d54[0x74] = 1;
  PTR_DAT_00025d54[0x7a] = 0x1f;
  if (PTR_DAT_00025d54[0x73] == '\x02') {
    if (DAT_00009dbd == '\0') {
      local_4 = &DAT_00009d09;
    }
    else {
      local_4 = &DAT_00009d63;
    }
    uVar2 = *local_4 & 0xf;
    if (uVar2 == 0xe) {
LAB_fffbdc16:
      local_8 = local_4 + 0x28;
    }
    else if (uVar2 - 2 < 2) {
      local_8 = local_4 + 0x14;
    }
    else if (uVar2 - 4 < 2) {
      local_8 = local_4 + 0x32;
    }
    else {
      if (uVar2 - 8 < 2) goto LAB_fffbdc16;
      if (uVar2 - 0xc < 2) {
        local_8 = local_4 + 0x1e;
      }
      else {
        if ((*local_4 & 0xf) != 0 && uVar2 != 1) {
          return;
        }
        local_8 = local_4 + 10;
      }
    }
    bVar1 = *local_8;
    if ((bVar1 & 0x80) == 0) {
      *local_8 = bVar1 | 0x80;
    }
    else {
      *local_8 = bVar1 & 0x7f;
    }
  }
  else {
    PTR_DAT_00025d54[0x7a] = 0x1f;
    PTR_DAT_00025d54[0x73] = 2;
  }
  PTR_DAT_00025d54[0x72] = 1;
  FUN_fffb237a(0x45,0x1c2);
  FUN_fffc89b0();
LAB_fffbdc83:
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffbdcb0 @ fffbdcb0 (389 bytes)

void FUN_fffbdcb0(void)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  byte *local_8;
  byte *local_4;
  
  bVar2 = false;
  if (PTR_DAT_00025d54[0x74] != '\0') {
    PTR_DAT_00025d54[0x74] = 0;
    PTR_DAT_00025d54[0x72] = 0;
    PTR_DAT_00025d54[0x71] = 1;
    goto LAB_fffbde2b;
  }
  PTR_DAT_00025d54[0x74] = 1;
  PTR_DAT_00025d54[0x7a] = 0x20;
  if (PTR_DAT_00025d54[0x73] == '\x03') {
    if (DAT_00009dbd == '\0') {
      local_4 = &DAT_00009d09;
    }
    else {
      local_4 = &DAT_00009d63;
    }
    uVar3 = *local_4 & 0xf;
    if (uVar3 == 0xe) {
LAB_fffbdd86:
      local_8 = local_4 + 0x28;
    }
    else if (uVar3 - 2 < 2) {
      local_8 = local_4 + 0x14;
      bVar2 = true;
    }
    else if (uVar3 - 4 < 2) {
      local_8 = local_4 + 0x32;
    }
    else {
      if (1 < uVar3 - 6) {
        if (uVar3 - 8 < 2) goto LAB_fffbdd86;
        if (1 < uVar3 - 10) {
          if (uVar3 - 0xc < 2) {
            local_8 = local_4 + 0x1e;
          }
          else {
            if ((*local_4 & 0xf) != 0 && uVar3 != 1) {
              return;
            }
            local_8 = local_4 + 10;
          }
          goto LAB_fffbdd8f;
        }
      }
      local_8 = local_4 + 0x3c;
    }
LAB_fffbdd8f:
    bVar1 = *local_8;
    if (bVar2) {
      if ((bVar1 & 0x40) == 0) {
        *local_8 = bVar1 | 0x40;
      }
      else {
        *local_8 = bVar1 & 0xbf;
        PTR_DAT_00025d54[0x47a] = 1;
        PTR_DAT_00025d54[0x7a] = 0x21;
      }
    }
    else if ((bVar1 & 0x40) == 0) {
      *local_8 = bVar1 | 0x40;
    }
    else {
      *local_8 = bVar1 & 0xbf;
    }
  }
  else {
    PTR_DAT_00025d54[0x7a] = 0x20;
    PTR_DAT_00025d54[0x73] = 3;
  }
  PTR_DAT_00025d54[0x72] = 1;
  FUN_fffb237a(0x45,0x1c2);
  FUN_fffc89b0();
LAB_fffbde2b:
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffbde58 @ fffbde58 (285 bytes)

void FUN_fffbde58(void)

{
  bool bVar1;
  byte *local_4;
  
  if (PTR_DAT_00025d54[0x74] == '\0') {
    PTR_DAT_00025d54[0x74] = 1;
    PTR_DAT_00025d54[0x7a] = 0x21;
    if (PTR_DAT_00025d54[0x73] == '\x03') {
      if (DAT_00009dbd == '\0') {
        local_4 = &DAT_00009d09;
      }
      else {
        local_4 = &DAT_00009d63;
      }
      if (((*local_4 & 0xf) == 3) || ((*local_4 & 0xf) == 2)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        return;
      }
      if ((local_4[0x14] & 0x20) == 0) {
        local_4[0x14] = local_4[0x14] | 0x20;
      }
      else {
        local_4[0x14] = local_4[0x14] & 0xdf;
        local_4[0x14] = local_4[0x14] | 0x40;
        PTR_DAT_00025d54[0x47a] = 0;
        PTR_DAT_00025d54[0x7a] = 0x20;
      }
    }
    else {
      PTR_DAT_00025d54[0x7a] = 0x21;
      PTR_DAT_00025d54[0x73] = 3;
    }
    PTR_DAT_00025d54[0x72] = 1;
    FUN_fffb237a(0x45,0x1c2);
    FUN_fffc89b0();
  }
  else {
    PTR_DAT_00025d54[0x74] = 0;
    PTR_DAT_00025d54[0x72] = 0;
    PTR_DAT_00025d54[0x71] = 1;
  }
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffbe232 @ fffbe232 (7 bytes)

void FUN_fffbe232(void)

{
  FUN_fffc0b2f(0xff);
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
  FUN_fffb2da6(1);
  puVar1 = PTR_DAT_00025d54;
  uVar2 = FUN_fffc523a(0,1,0);
  puVar1[0xa3] = (char)uVar2;
  return uVar2;
}


// ===== FUN_fffbe7e7 @ fffbe7e7 (88 bytes)

void FUN_fffbe7e7(void)

{
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    FUN_fffe5ce0();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if ((DAT_0001b4d9 != '\0') && (DAT_0001b4d9 != '\x01')) {
    PTR_DAT_00025d54[0x28] = 0;
    return;
  }
  return;
}


// ===== FUN_fffbe83f @ fffbe83f (147 bytes)

void FUN_fffbe83f(void)

{
  bool bVar1;
  int iVar2;
  
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
  iVar2 = FUN_fffb3196(1);
  if ((1 < iVar2 - 2U) && (iVar2 != 0xc && iVar2 != 0xd)) {
    DAT_00009c5d = DAT_00009c5d == '\0';
    FUN_fffb2da6(1);
    FUN_fffb237a(0x2f,100);
    return;
  }
  FUN_fffb2da6(3);
  return;
}


// ===== FUN_fffbe8d2 @ fffbe8d2 (93 bytes)

void FUN_fffbe8d2(void)

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


// ===== FUN_fffbeca5 @ fffbeca5 (352 bytes)

void FUN_fffbeca5(void)

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
    FUN_fff9cdb0(0);
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
    FUN_fffc27ad();
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
    FUN_fff9cdb0(0);
  }
  else {
    FUN_fff9cdb0(1);
  }
LAB_fffbede9:
  PTR_DAT_00025d54[0x425] = 0;
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== FUN_fffbf0b6 @ fffbf0b6 (286 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbf119) */
/* WARNING: Removing unreachable block (ram,0xfffbf120) */

void FUN_fffbf0b6(void)

{
  uint uVar1;
  bool bVar2;
  short sVar3;
  undefined4 uVar4;
  int iStack_c;
  bool local_5;
  byte *local_4;
  
  if (DAT_00009dbd == '\0') {
    local_4 = &DAT_00009d09;
  }
  else {
    local_4 = &DAT_00009d63;
  }
  local_5 = DAT_00009dbd != '\0';
  sVar3 = FUN_fff9d895();
  if ((sVar3 < -0x23) || (0x23 < sVar3)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    uVar1 = (uint)(short)(sVar3 * 10);
    if ((*local_4 & 0xf) == 2) {
      uVar1 = -(uVar1 & 0xff);
    }
    iStack_c = ((uint)local_4[0x4a] << 0x18 | (uint)local_4[0x4d]) + uVar1;
    DAT_0001b4e2 = 1;
    uVar4 = FUN_fffc10c3(local_5,iStack_c);
    DAT_0001b4e2 = 0;
    if (PTR_DAT_00025d54[0x469] != '\x01') {
      local_4[0x4a] = (byte)((uint)uVar4 >> 0x18);
      local_4[0x4b] = (byte)((uint)uVar4 >> 0x10);
      local_4[0x4c] = (byte)((uint)uVar4 >> 8);
      iStack_c._0_1_ = (byte)uVar4;
      local_4[0x4d] = (byte)iStack_c;
      if (local_5) {
        if (DAT_00009dbf == '\x02') {
          FUN_fffc2efb(1);
        }
      }
      else if (DAT_00009dbe == '\x02') {
        FUN_fffc2efb(0);
      }
      FUN_fffc2fde(local_5);
      FUN_fffc16f6(local_5);
      PTR_DAT_00025d54[0x40c] = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffbf41f @ fffbf41f (28 bytes)

void FUN_fffbf41f(void)

{
  if (DAT_00020b9b != '\x01') {
    FUN_fffe3d24();
    FUN_fffc27ad();
    FUN_fffec578();
    return;
  }
  FUN_fffc2794();
  return;
}


// ===== FUN_fffbf4bb @ fffbf4bb (283 bytes)

void FUN_fffbf4bb(void)

{
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  FUN_fffe3d24();
  DAT_00009c5e = 0;
  if (DAT_00009dbd == '\0') {
    if (DAT_00009dbe == '\x03') {
      FUN_fffbf41f();
      FUN_fffbf41f();
    }
    else if (DAT_00009dbe == '\x05') {
      DAT_00009dbe = '\x01';
      FUN_fffc1c04(0);
    }
    else if (DAT_00009dbe == '\x01') {
      DAT_00009dbd = '\x01';
      PTR_DAT_00025d54[0x443] = 1;
      PTR_DAT_00025d54[0x445] = 1;
    }
    else {
      FUN_fffbf41f();
    }
  }
  else if (DAT_00009dbf == '\x03') {
    FUN_fffbf41f();
    FUN_fffbf41f();
  }
  else if (DAT_00009dbf == '\x05') {
    DAT_00009dbf = '\x01';
    FUN_fffc1c04(1);
  }
  else if (DAT_00009dbf == '\x01') {
    DAT_00009dbd = '\0';
    PTR_DAT_00025d54[0x443] = 1;
    PTR_DAT_00025d54[0x445] = 1;
  }
  else {
    FUN_fffbf41f();
  }
  FUN_fffec578();
  PTR_DAT_00025d54[0x40c] = 1;
  return;
}


// ===== FUN_fffbf6c8 @ fffbf6c8 (223 bytes)

void FUN_fffbf6c8(void)

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
    FUN_fffe5ce0();
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


// ===== FUN_fffbf924 @ fffbf924 (416 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbf95a) */

void FUN_fffbf924(void)

{
  int iVar1;
  char local_3;
  
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
      local_3 = '\0';
      if (DAT_00009dbe != '\x05') {
        FUN_fffc34d8(0);
      }
    }
    else {
      local_3 = '\x01';
      if (DAT_00009dbf != '\x05') {
        FUN_fffc34d8(1);
      }
    }
    iVar1 = FUN_fffc302b(local_3);
    if (iVar1 == 0) {
      if (local_3 == '\0') {
        PTR_DAT_00025d54[0x443] = 0;
        PTR_DAT_00025d54[0x444] = 0;
      }
      else {
        PTR_DAT_00025d54[0x445] = 0;
        PTR_DAT_00025d54[0x446] = 0;
      }
    }
    FUN_fffc3081(local_3);
    iVar1 = FUN_fffc30af(local_3);
    if (iVar1 == 1) {
      FUN_fffc311a(local_3);
      FUN_fffc16f6(local_3);
    }
    if (local_3 == '\0') {
      if (DAT_0000901f != '\0') {
        FUN_fffc316c(0);
        return;
      }
      DAT_00009dbe = '\x01';
    }
    else {
      if (DAT_00009021 != '\0') {
        FUN_fffc316c(1);
        return;
      }
      DAT_00009dbf = '\x01';
    }
    FUN_fffc311a(local_3);
    FUN_fffc1c04(local_3);
    PTR_DAT_00025d54[0x40b] = 1;
    FUN_fffec578();
    FUN_fffc8beb();
    return;
  }
  FUN_fffb2da6(3);
  return;
}


// ===== FUN_fffbfac4 @ fffbfac4 (371 bytes)

/* WARNING: Removing unreachable block (ram,0xfffbfb0d) */

void FUN_fffbfac4(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined *puVar4;
  undefined1 *puStack_10;
  bool bStack_5;
  ushort uStack_4;
  byte bStack_2;
  
  if (DAT_00020b9b == '\x01') {
    FUN_fffc2794();
  }
  bVar1 = DAT_00009dbd != '\0';
  iVar3 = FUN_fffc2d93(bVar1);
  if ((iVar3 == 1) && (iVar3 = FUN_fffc2ecb(bVar1), iVar3 == 1)) {
    FUN_fffb2da6(3);
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
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
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
  FUN_fffb2da6(5);
  FUN_fffc33ef();
  PTR_DAT_00025d54[0x47f] = DAT_00009015 + 1;
  return;
}


// ===== FUN_fffbff93 @ fffbff93 (112 bytes)

void FUN_fffbff93(void)

{
  int iVar1;
  
  FUN_fffc8beb();
  FUN_fffbc638();
  FUN_fffc3c85();
  FUN_fffc23b6();
  FUN_fffc4caa();
  if (PTR_DAT_00025d54[0x418] == '\x01') {
    FUN_fffe5ce0();
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0xba] == '\x01') {
    iVar1 = FUN_fffbba0f();
    if (iVar1 == 1) {
      FUN_fffb2da6(1);
    }
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x70] == '\x01') {
    FUN_fffc89b0();
    return;
  }
  return;
}


// ===== FUN_fffc0335 @ fffc0335 (14 bytes)

void FUN_fffc0335(void)

{
  FUN_fffc40d7(DAT_00009acc);
  return;
}


// ===== FUN_fffc037b @ fffc037b (14 bytes)

void FUN_fffc037b(void)

{
  FUN_fffc40d7(DAT_00009acd);
  return;
}


// ===== FUN_fffc052b @ fffc052b (108 bytes)

void FUN_fffc052b(undefined1 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  PTR_DAT_00025d54[0x40c] = 1;
  if (DAT_00009c35 == '\x02') {
    uVar2 = FUN_fffb357c(0,2);
    bVar1 = FUN_fffb3480(uVar2);
    (&DAT_00009c4c)[bVar1] = param_1;
    return;
  }
  uVar2 = FUN_fffb35d7(0,2);
  bVar1 = FUN_fffb3480(uVar2);
  if (bVar1 == 0xff) {
    return;
  }
  (&DAT_00009c3e)[bVar1] = param_1;
  return;
}


// ===== FUN_fffc06ab @ fffc06ab (18 bytes)

void FUN_fffc06ab(void)

{
  FUN_fffc90b4();
  PTR_DAT_00025d54[0x1c3] = 1;
  return;
}


// ===== FUN_fffc078d @ fffc078d (13 bytes)

void FUN_fffc078d(void)

{
  FUN_fffc909f();
  FUN_fffc8d8c(2000);
  return;
}


// ===== FUN_fffc0948 @ fffc0948 (132 bytes)

void FUN_fffc0948(byte *param_1,char param_2)

{
  uint uVar1;
  bool bVar2;
  byte *local_c;
  
  bVar2 = false;
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_c = param_1 + 0x15;
      goto LAB_fffc09ae;
    }
    if (uVar1 - 4 < 2) {
      local_c = param_1 + 0x33;
      goto LAB_fffc09ae;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        local_c = param_1 + 0x1f;
      }
      else if (uVar1 < 2) {
        local_c = param_1 + 0xb;
      }
      else {
        bVar2 = true;
      }
      goto LAB_fffc09ae;
    }
  }
  local_c = param_1 + 0x29;
LAB_fffc09ae:
  if (bVar2) {
    return;
  }
  if (param_2 == '\0') {
    *local_c = *local_c & 0x7f;
    return;
  }
  *local_c = *local_c & 0x7f | 0x80;
  return;
}


// ===== FUN_fffc0a49 @ fffc0a49 (139 bytes)

void FUN_fffc0a49(byte *param_1,undefined1 param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      FUN_fffc0ad4(param_1 + 0x15,param_2);
      return;
    }
    if (uVar1 - 4 < 2) {
      FUN_fffc0ad4(param_1 + 0x33,param_2);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc0ac6;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          FUN_fffc0ad4(param_1 + 0x1f,param_2);
          return;
        }
        if (uVar1 < 2) {
          FUN_fffc0ad4(param_1 + 0xb,param_2);
          return;
        }
        return;
      }
    }
    FUN_fffc0ad4(param_1 + 0x3d,param_2);
    return;
  }
LAB_fffc0ac6:
  FUN_fffc0ad4(param_1 + 0x29,param_2);
  return;
}


// ===== FUN_fffc0ad4 @ fffc0ad4 (91 bytes)

void FUN_fffc0ad4(byte *param_1,char param_2)

{
  if (param_2 == '\x04') {
    *param_1 = *param_1 | 0x70;
    return;
  }
  if (param_2 == '\x01') {
    *param_1 = *param_1 & 0xcf | 0x40;
    return;
  }
  if (param_2 == '\x02') {
    *param_1 = *param_1 & 0xdf | 0x50;
    return;
  }
  if (param_2 == '\x03') {
    *param_1 = *param_1 & 0xef | 0x60;
    return;
  }
  if (param_2 != '\0') {
    return;
  }
  *param_1 = *param_1 & 0xbf;
  return;
}


// ===== FUN_fffc0b2f @ fffc0b2f (352 bytes)

uint FUN_fffc0b2f(uint param_1)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  
  if (PTR_DAT_00025d54[0x86] == '\x01') {
    FUN_fffe5ce0();
    FUN_fffd0046(param_1 & 0xffff);
    uVar3 = FUN_fffb2da6(1);
    PTR_DAT_00025d54[0x409] = 1;
    return uVar3;
  }
  if (PTR_DAT_00025d54[0x88] == '\x01') {
    bVar2 = FUN_fffcfaa9(param_1 & 0xffff);
    if (bVar2 == 0) {
      PTR_DAT_00025d54[0x409] = 1;
      return 0;
    }
    if (bVar2 == 1) {
      uVar3 = FUN_fffb2da6(1);
      PTR_DAT_00025d54[0x409] = 1;
      return uVar3;
    }
    return (uint)bVar2;
  }
  if (PTR_DAT_00025d54[0x93] == '\x01') {
    uVar3 = FUN_fffb2da6(1);
    PTR_DAT_00025d54[0x409] = 1;
    return uVar3;
  }
  if (PTR_DAT_00025d54[0x94] == '\x01') {
    if (PTR_DAT_00025d54[0x1d1] == '\x01') {
      PTR_DAT_00025d54[0x1d1] = 0;
      param_1 = FUN_fffb2da6(1);
    }
    else {
      if (((param_1 & 0xffff) < 0x87) || (0x8b < (param_1 & 0xffff))) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        param_1 = FUN_fffb3196(0);
        if (((char)param_1 == '\x02') || ((char)param_1 == '\x03')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uVar3 = FUN_fffb2da6(1);
          return uVar3;
        }
      }
    }
    PTR_DAT_00025d54[0x409] = 1;
    return param_1;
  }
  if (PTR_DAT_00025d54[0x1c1] == '\0') {
    PTR_DAT_00025d54[0x409] = 1;
    return param_1;
  }
  if (0xd < (byte)PTR_DAT_00025d54[0x1c2]) {
    PTR_DAT_00025d54[0x409] = 1;
    return param_1;
  }
  return param_1 & 0xffff;
}


// ===== FUN_fffc0c8f @ fffc0c8f (164 bytes)

void FUN_fffc0c8f(ushort param_1)

{
  bool bVar1;
  
  if ((param_1 < 0x77) || (0x86 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    FUN_fffc8d8c(1000);
    switch(param_1) {
    case 0x77:
      FUN_fffc0d33(0);
      return;
    case 0x78:
      FUN_fffc0d33(1);
      return;
    case 0x79:
      FUN_fffc0d33(2);
      return;
    case 0x7a:
      FUN_fffc0d33(3);
      return;
    case 0x7b:
      FUN_fffc0e31();
      return;
    case 0x7c:
      FUN_fffc0e3e();
      return;
    case 0x7d:
      FUN_fffc0e4b();
      return;
    case 0x7e:
      FUN_fffc0e58();
      return;
    case 0x7f:
      FUN_fffc0d33(8);
      return;
    case 0x80:
      FUN_fffc0d33(9);
      return;
    case 0x81:
      FUN_fffc0e65();
      return;
    case 0x82:
      FUN_fffc0e72();
      return;
    case 0x83:
      FUN_fffc0d33(0xc);
      return;
    case 0x84:
      FUN_fffc0d33(0xd);
      return;
    case 0x85:
      FUN_fffc0d33(0xe);
      return;
    case 0x86:
      FUN_fffc0e7f();
      return;
    }
  }
  return;
}


// ===== FUN_fffc0d33 @ fffc0d33 (54 bytes)

void FUN_fffc0d33(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 == 1) {
    FUN_fffc0eb8(param_1);
    if (PTR_DAT_00025d54[0x1c1] == '\x01') {
      FUN_fffb2da6(1);
    }
    PTR_DAT_00025d54[0x424] = param_1;
    return;
  }
  return;
}


// ===== FUN_fffc0d69 @ fffc0d69 (142 bytes)

undefined1 FUN_fffc0d69(void)

{
  int iVar1;
  undefined1 local_4;
  bool local_3;
  char local_2;
  
  if (PTR_DAT_00025d54[0x417] == '\x01') {
    local_4 = 0;
  }
  else if (PTR_DAT_00025d54[0x418] == '\x01') {
    FUN_fffe5ce0();
    local_4 = 0;
  }
  else if (PTR_DAT_00025d54[0x67] == '\x01') {
    local_4 = 0;
  }
  else {
    if (DAT_00009dbd == '\0') {
      local_2 = DAT_00009dbe;
    }
    else {
      local_2 = DAT_00009dbf;
    }
    local_3 = DAT_00009dbd != '\0';
    if (local_2 == '\x02') {
      iVar1 = FUN_fffc2ecb(local_3);
      if (iVar1 == 1) {
        return 0;
      }
      FUN_fffc2efb(local_3);
    }
    local_4 = 1;
  }
  return local_4;
}


// ===== FUN_fffc0df7 @ fffc0df7 (58 bytes)

void FUN_fffc0df7(undefined1 param_1)

{
  PTR_DAT_00025d54[0x1d1] = 0;
  FUN_fffc0eb8(param_1);
  if (PTR_DAT_00025d54[0x1c1] == '\x01') {
    FUN_fffb2da6(1);
  }
  PTR_DAT_00025d54[0x424] = param_1;
  return;
}


// ===== FUN_fffc0e31 @ fffc0e31 (13 bytes)

void FUN_fffc0e31(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(4);
  return;
}


// ===== FUN_fffc0e3e @ fffc0e3e (13 bytes)

void FUN_fffc0e3e(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(5);
  return;
}


// ===== FUN_fffc0e4b @ fffc0e4b (13 bytes)

void FUN_fffc0e4b(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(6);
  return;
}


// ===== FUN_fffc0e58 @ fffc0e58 (13 bytes)

void FUN_fffc0e58(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(7);
  return;
}


// ===== FUN_fffc0e65 @ fffc0e65 (13 bytes)

void FUN_fffc0e65(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(10);
  return;
}


// ===== FUN_fffc0e72 @ fffc0e72 (13 bytes)

void FUN_fffc0e72(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(0xb);
  return;
}


// ===== FUN_fffc0e7f @ fffc0e7f (57 bytes)

void FUN_fffc0e7f(void)

{
  FUN_fffc8d8c(3000);
  DAT_00009dc6 = DAT_00009dc6 == '\0';
  sci3_set_baud();
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffc0eb8 @ fffc0eb8 (88 bytes)

void FUN_fffc0eb8(byte param_1)

{
  byte bVar1;
  byte *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  bVar1 = *local_8;
  *local_8 = bVar1 & 0xf0 | param_1;
  FUN_fffc0f10(bVar1 & 0xf,param_1,local_8);
  PTR_DAT_00025d54[0x40b] = 1;
  return;
}


// ===== FUN_fffc0f10 @ fffc0f10 (188 bytes)

void FUN_fffc0f10(byte param_1,byte param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (DAT_00009aa2 != '\0') {
    uVar1 = (uint)param_1;
    if (uVar1 - 4 < 0xb) {
      if (param_2 == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,param_3);
        return;
      }
      if (param_2 == 0) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,param_3);
        return;
      }
    }
    else if (uVar1 == 1) {
      if (param_2 - 2 < 0xd) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,param_3);
        return;
      }
      if (param_2 == 0) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(iVar3 << 1,param_3);
        return;
      }
    }
    else if (uVar1 - 2 < 2) {
      if (param_2 == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,param_3);
        return;
      }
      if (param_2 == 0) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,param_3);
        return;
      }
    }
    else if (uVar1 == 0) {
      if (param_2 - 2 < 0xd) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,param_3);
        return;
      }
      if (param_2 == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(iVar3 * -2,param_3);
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffc0fcc @ fffc0fcc (225 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc0fe3) */
/* WARNING: Removing unreachable block (ram,0xfffc0fee) */

void FUN_fffc0fcc(int param_1,undefined1 *param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_c;
  
  if (param_1 != 0) {
    uVar2 = CONCAT31(CONCAT21(CONCAT11(param_2[0x4a],param_2[0x4b]),param_2[0x4c]),param_2[0x4d]);
    if ((uVar2 < 0x3b9ac9f7) && (param_1 < 0x3b9ac9f7)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (param_1 < -0x3b9ac9f6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_c = uVar2 + param_1;
      if (local_c < 0) {
        local_c = 0;
      }
      DAT_0001b4e1 = 1;
      uVar3 = FUN_fffc10c3(param_2 != &DAT_00009d09,local_c);
      DAT_0001b4e1 = 0;
      param_2[0x4a] = (char)((uint)uVar3 >> 0x18);
      param_2[0x4b] = (char)((uint)uVar3 >> 0x10);
      param_2[0x4c] = (char)((uint)uVar3 >> 8);
      local_c._0_1_ = (undefined1)uVar3;
      param_2[0x4d] = (undefined1)local_c;
      FUN_fffc125a(param_2 != &DAT_00009d09);
      return;
    }
  }
  return;
}


// ===== FUN_fffc10ad @ fffc10ad (22 bytes)

void FUN_fffc10ad(void)

{
  return;
}


// ===== FUN_fffc10c3 @ fffc10c3 (229 bytes)

void FUN_fffc10c3(char param_1,undefined4 param_2)

{
  bool bVar1;
  char cVar2;
  undefined4 local_10 [2];
  undefined4 local_8;
  char local_1;
  
  PTR_DAT_00025d54[0x469] = 0;
  local_10[0] = param_2;
  local_8 = param_2;
  local_1 = param_1;
  if (param_1 == '\0') {
    if (DAT_00009dbe == '\x04') {
      if ((DAT_00020f74 == 0) || (DAT_00020f78 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_fffc5d13(0);
      }
      FUN_fffc11a8(local_10[0]);
      return;
    }
  }
  else if (DAT_00009dbf == '\x04') {
    if ((DAT_00020f74 == 0) || (DAT_00020f78 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc5d13(param_1);
    }
    FUN_fffc11a8(local_10[0]);
    return;
  }
  cVar2 = FUN_fff97784(local_10,&PTR_DAT_fff89d4c);
  if (cVar2 == '\0') {
    FUN_fffc130b(local_10,&PTR_DAT_fff89d4c);
  }
  else if (cVar2 == '\x01') {
    FUN_fffc1378(local_10,&PTR_DAT_fff89d4c);
  }
  return;
}


// ===== FUN_fffc11a8 @ fffc11a8 (178 bytes)

void FUN_fffc11a8(undefined4 param_1)

{
  bool bVar1;
  undefined4 uStack_10;
  char cStack_9;
  undefined4 local_4;
  
  local_4 = param_1;
  cStack_9 = FUN_fff97784();
  uStack_10 = local_4;
  if (cStack_9 == '\0') {
    if ((PTR_DAT_00025d54[0x460] == '\x01') || (DAT_0001b4e2 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d54[0x469] = 1;
    }
    else {
      FUN_fffc130b(&uStack_10,PTR_DAT_00025d54 + 0x470);
    }
  }
  else if (cStack_9 == '\x01') {
    if ((PTR_DAT_00025d54[0x460] == '\x01') || (DAT_0001b4e2 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d54[0x469] = 1;
    }
    else {
      FUN_fffc1378(&uStack_10,PTR_DAT_00025d54 + 0x470);
    }
  }
  return;
}


// ===== FUN_fffc125a @ fffc125a (33 bytes)

void FUN_fffc125a(uint param_1)

{
  if (param_1 == 0) {
    PTR_DAT_00025d54[0x444] = 1;
  }
  else {
    PTR_DAT_00025d54[0x446] = 1;
  }
  FUN_fffc127b(param_1 & 0xff);
  return;
}


// ===== FUN_fffc127b @ fffc127b (144 bytes)

void FUN_fffc127b(int param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if ((DAT_00009dbe == '\x04') || (DAT_00009dbe != '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00009dbe == '\x05')) {
      DAT_00009dbe = 1;
      return;
    }
  }
  else {
    if ((DAT_00009dbf == '\x04') || (DAT_00009dbf != '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00009dbf == '\x05')) {
      DAT_00009dbf = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffc130b @ fffc130b (109 bytes)

void FUN_fffc130b(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *param_1 = *param_2;
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    *param_1 = *param_2;
    return;
  }
  if (PTR_DAT_00025d54[0x46a] != '\x01') {
    if (PTR_DAT_00025d54[0x418] != '\x01') {
      *param_1 = *param_2;
      return;
    }
    *param_1 = param_2[1];
    return;
  }
  FUN_fffc142c(param_1,param_2);
  return;
}


// ===== FUN_fffc1378 @ fffc1378 (111 bytes)

void FUN_fffc1378(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *param_1 = param_2[1];
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    *param_1 = param_2[1];
    return;
  }
  if (PTR_DAT_00025d54[0x46a] != '\x01') {
    if (PTR_DAT_00025d54[0x418] != '\x01') {
      *param_1 = param_2[1];
      return;
    }
    *param_1 = *param_2;
    return;
  }
  FUN_fffc14c6(param_1,param_2);
  return;
}

