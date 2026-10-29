// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc6595 @ fffc6595 (376 bytes)

void FUN_fffc6595(char param_1)

{
  if (PTR_DAT_00025d58[0x93] == '\x01') {
    if (PTR_DAT_00025d58[0x3fe] == '\x01') {
      PTR_DAT_00025d58[0x3f8] = 1;
      PTR_DAT_00025d58[0x3f9] = 4;
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (DAT_00009dc1 != 0)) {
          DAT_00009dc1 = DAT_00009dc1 - 1;
          return;
        }
      }
      else if (DAT_00009dc1 < 100) {
        DAT_00009dc1 = DAT_00009dc1 + 1;
        return;
      }
    }
    else {
      if (param_1 < '\0') {
        FUN_fffe3121();
        return;
      }
      if ('\0' < param_1) {
        FUN_fffe32fd();
        return;
      }
    }
  }
  else if (PTR_DAT_00025d58[0x94] == '\x01') {
    if (PTR_DAT_00025d58[0x1cf] == '\x01') {
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (DAT_00009dc1 != 0)) {
          DAT_00009dc1 = DAT_00009dc1 - 1;
          return;
        }
      }
      else if (DAT_00009dc1 < 100) {
        DAT_00009dc1 = DAT_00009dc1 + 1;
        return;
      }
    }
    else if (PTR_DAT_00025d58[0x1d0] == '\x01') {
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (DAT_00009dc2 != 0)) {
          DAT_00009dc2 = DAT_00009dc2 - 1;
          return;
        }
      }
      else if (DAT_00009dc2 < 100) {
        DAT_00009dc2 = DAT_00009dc2 + 1;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffc670d @ fffc670d (243 bytes)

void FUN_fffc670d(char param_1)

{
  byte bVar1;
  
  if (DAT_0001b4eb == '\x01') {
    bVar1 = swtimer_expired(0x47);
    if (bVar1 == 0) {
      return;
    }
    DAT_0001b4eb = '\0';
  }
  if (DAT_0001b4ea == '\0') {
    DAT_0001b4ea = 1;
    FUN_fff98727(DAT_0001b4e9,1);
    swtimer_start(0x47,100);
    DAT_0001b4eb = 1;
    return;
  }
  DAT_0001b4ea = 0;
  FUN_fff98727(DAT_0001b4e9,0);
  swtimer_start(0x47,100);
  DAT_0001b4eb = 1;
  if ('\0' < param_1) {
    if (DAT_0001b4e9 < DAT_0001b4e7) {
      DAT_0001b4e9 = DAT_0001b4e9 + 1;
      return;
    }
    DAT_0001b4e9 = DAT_0001b4e8;
    return;
  }
  if (DAT_0001b4e8 < DAT_0001b4e9) {
    DAT_0001b4e9 = DAT_0001b4e9 - 1;
    return;
  }
  DAT_0001b4e9 = DAT_0001b4e7;
  return;
}


// ===== FUN_fffc6800 @ fffc6800 (111 bytes)

void FUN_fffc6800(char param_1)

{
  char cVar1;
  
  if (PTR_DAT_00025d58[0x43c] == '\0') {
    if (PTR_DAT_00025d58[0x1d9] == '\0') {
      FUN_fffc686f((int)param_1);
      return;
    }
    if (PTR_DAT_00025d58[0x43b] == '\0') {
      FUN_fffc6bd8((int)param_1);
      return;
    }
  }
  cVar1 = PTR_DAT_00025d58[0x1da];
  if (cVar1 == '\x03') {
    FUN_fffc6b86((int)param_1);
    return;
  }
  if (cVar1 != '\x02') {
    if (cVar1 == '\x01') {
      FUN_fffc6ac4((int)param_1);
      return;
    }
    return;
  }
  FUN_fffc6b34((int)param_1);
  return;
}


// ===== FUN_fffc686f @ fffc686f (83 bytes)

void FUN_fffc686f(char param_1)

{
  if (param_1 < '\x01') {
    if (PTR_DAT_00025d58[0x1db] == 0) {
      FUN_fffc6a0a();
    }
    else {
      PTR_DAT_00025d58[0x1db] = PTR_DAT_00025d58[0x1db] + -1;
    }
  }
  else if ((byte)PTR_DAT_00025d58[0x1db] < 3) {
    PTR_DAT_00025d58[0x1db] = PTR_DAT_00025d58[0x1db] + '\x01';
  }
  else {
    FUN_fffc68c2();
  }
  FUN_fffc2b12();
  return;
}


// ===== FUN_fffc68c2 @ fffc68c2 (328 bytes)

void FUN_fffc68c2(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  
  if (PTR_DAT_00025d58[0x1db] != '\x03') {
    PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + '\x01';
    return;
  }
  bVar2 = PTR_DAT_00025d58[0x439] + PTR_DAT_00025d58[0x1db];
  if (bVar2 < 0x84) {
    bVar2 = bVar2 + 1;
    if (bVar2 < 0x75) {
      PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + '\x01';
      return;
    }
    uVar3 = dest_code_get();
    if ((uVar3 == 0x4380) || (uVar3 == 0x20b)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (uVar3 == 0x60e6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (uVar3 == 0x1cb9)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_00009af4 == '\x01') {
        PTR_DAT_00025d58[0x439] = 0x72;
        return;
      }
    }
    else {
      if ((uVar3 == 0x315b) || (uVar3 == 0x50e2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (bVar2 < 0x84) {
          PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + '\x01';
          return;
        }
        if (DAT_00009af4 == '\x01') {
          PTR_DAT_00025d58[0x439] = 0x81;
          return;
        }
      }
      else {
        if ((uVar3 == 0xd950) || (uVar3 == 0xa4c5)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if ((bVar1) && (bVar2 < 0x7c)) {
          PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + '\x01';
          return;
        }
      }
    }
  }
  return;
}


// ===== FUN_fffc6a0a @ fffc6a0a (186 bytes)

void FUN_fffc6a0a(void)

{
  bool bVar1;
  ushort uVar2;
  
  if ((byte)PTR_DAT_00025d58[0x439] < 0x84) {
    if (PTR_DAT_00025d58[0x439] != '\0') {
      PTR_DAT_00025d58[0x439] = PTR_DAT_00025d58[0x439] + -1;
      return;
    }
  }
  else {
    uVar2 = dest_code_get();
    if ((uVar2 == 0x315b) || (uVar2 == 0x50e2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d58[0x439] = 0x83;
      return;
    }
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
    if (bVar1) {
      PTR_DAT_00025d58[0x439] = 0x74;
      return;
    }
  }
  return;
}


// ===== FUN_fffc6ac4 @ fffc6ac4 (112 bytes)

void FUN_fffc6ac4(char param_1)

{
  byte *pbVar1;
  byte bStack_9;
  
  FUN_fffc8cbb(0x55);
  FUN_fffc8d8c();
  pbVar1 = &DAT_00006150 + (uint)(byte)PTR_DAT_00025d58[0x43a] * 0x5a;
  bStack_9 = *pbVar1 & 0xf;
  if (param_1 < '\x01') {
    if (bStack_9 != 0) {
      bStack_9 = bStack_9 - 1;
    }
  }
  else if (bStack_9 < 0xe) {
    bStack_9 = bStack_9 + 1;
  }
  *pbVar1 = *pbVar1 & 0xf0 | bStack_9;
  eeprom_save_memch(PTR_DAT_00025d58[0x43a]);
  return;
}


// ===== FUN_fffc6b34 @ fffc6b34 (82 bytes)

void FUN_fffc6b34(char param_1)

{
  byte *pbVar1;
  
  FUN_fffc8cbb(0x56);
  FUN_fffc8d8c();
  pbVar1 = &DAT_00006151 + (uint)(byte)PTR_DAT_00025d58[0x43a] * 0x5a;
  if (param_1 < '\x01') {
    *pbVar1 = *pbVar1 & 0x7f;
  }
  else {
    *pbVar1 = *pbVar1 | 0x80;
  }
  eeprom_save_memch(PTR_DAT_00025d58[0x43a]);
  return;
}


// ===== FUN_fffc6b86 @ fffc6b86 (82 bytes)

void FUN_fffc6b86(char param_1)

{
  byte *pbVar1;
  
  FUN_fffc8cbb(0x57);
  FUN_fffc8d8c();
  pbVar1 = &DAT_00006155 + (uint)(byte)PTR_DAT_00025d58[0x43a] * 0x5a;
  if (param_1 < '\x01') {
    *pbVar1 = *pbVar1 & 0x7f;
  }
  else {
    *pbVar1 = *pbVar1 | 0x80;
  }
  eeprom_save_memch(PTR_DAT_00025d58[0x43a]);
  return;
}


// ===== FUN_fffc6bd8 @ fffc6bd8 (72 bytes)

void FUN_fffc6bd8(char param_1)

{
  if (param_1 < '\x01') {
    if (PTR_DAT_00025d58[0x1da] != 0) {
      PTR_DAT_00025d58[0x1da] = PTR_DAT_00025d58[0x1da] + -1;
      return;
    }
  }
  else if ((byte)PTR_DAT_00025d58[0x1da] < 5) {
    PTR_DAT_00025d58[0x1da] = PTR_DAT_00025d58[0x1da] + '\x01';
    return;
  }
  return;
}


// ===== FUN_fffc6c20 @ fffc6c20 (132 bytes)

void FUN_fffc6c20(char param_1)

{
  if (PTR_DAT_00025d58[0x1c1] != '\x01') {
    FUN_fffc6f11(DAT_00009dc9,(int)param_1);
    return;
  }
  if ((byte)PTR_DAT_00025d58[0x1c2] < 0x1e) {
    FUN_fffc6ca4((int)param_1);
    return;
  }
  if (PTR_DAT_00025d58[0x41c] == '\x01') {
    FUN_fffc6f11(DAT_00009dc9,(int)param_1);
    return;
  }
  if ((byte)PTR_DAT_00025d58[0x1c2] < 0x1e) {
    return;
  }
  FUN_fffc6ddd(PTR_DAT_00025d58[0x1c2],(int)param_1);
  return;
}


// ===== FUN_fffc6ca4 @ fffc6ca4 (51 bytes)

void FUN_fffc6ca4(char param_1)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d58[0x1c2];
  if (cVar1 == '\f') {
    FUN_fffc6d8c((int)param_1);
    return;
  }
  if (cVar1 == '\v') {
    FUN_fffc6d28((int)param_1);
    return;
  }
  if (cVar1 != '\x05') {
    return;
  }
  FUN_fffc6cd7((int)param_1);
  return;
}


// ===== FUN_fffc6cd7 @ fffc6cd7 (81 bytes)

void FUN_fffc6cd7(char param_1)

{
  short local_4;
  
  local_4 = (ushort)(byte)PTR_DAT_00025d58[0x424] + (short)param_1;
  if (param_1 < '\x01') {
    if ((param_1 < '\0') && (local_4 < 0)) {
      local_4 = 0;
    }
  }
  else if (0xf < local_4) {
    local_4 = 0xf;
  }
  PTR_DAT_00025d58[0x424] = (undefined1)local_4;
  FUN_fffc8cbb(5);
  FUN_fffc8d8c();
  return;
}


// ===== FUN_fffc6d28 @ fffc6d28 (100 bytes)

void FUN_fffc6d28(char param_1)

{
  short sVar1;
  undefined1 local_4;
  
  sVar1 = (ushort)(byte)PTR_DAT_00025d58[0x424] + (short)param_1;
  local_4 = (undefined1)sVar1;
  if (param_1 < '\x01') {
    if (param_1 < '\0') {
      if (sVar1 < 0) {
        PTR_DAT_00025d58[0x424] = 0;
      }
      else {
        PTR_DAT_00025d58[0x424] = local_4;
      }
    }
  }
  else if (sVar1 < 0xc) {
    PTR_DAT_00025d58[0x424] = local_4;
  }
  else {
    PTR_DAT_00025d58[0x424] = 0xb;
  }
  FUN_fffc8cbb(0xb);
  FUN_fffc8d8c();
  return;
}


// ===== FUN_fffc6d8c @ fffc6d8c (81 bytes)

void FUN_fffc6d8c(char param_1)

{
  short local_4;
  
  local_4 = (ushort)(byte)PTR_DAT_00025d58[0x424] + (short)param_1;
  if (param_1 < '\x01') {
    if ((param_1 < '\0') && (local_4 < 0)) {
      local_4 = 0;
    }
  }
  else if (0xb < local_4) {
    local_4 = 0xb;
  }
  PTR_DAT_00025d58[0x424] = (undefined1)local_4;
  FUN_fffc8cbb(0xc);
  FUN_fffc8d8c();
  return;
}


// ===== FUN_fffc6ddd @ fffc6ddd (308 bytes)

void FUN_fffc6ddd(char param_1,char param_2)

{
  if (param_1 == 'X') {
    FUN_fffc7c15((int)param_2);
    return;
  }
  if (param_1 == '\x1f') {
    FUN_fffc706b((int)param_2);
    return;
  }
  if (param_1 == '\"') {
    FUN_fffc70f3((int)param_2);
    return;
  }
  if (param_1 == '#') {
    FUN_fffc715d((int)param_2);
    return;
  }
  if (param_1 == '$') {
    FUN_fffc71c7((int)param_2);
    return;
  }
  if (param_1 == '%') {
    FUN_fffc7506((int)param_2);
    return;
  }
  if (param_1 == '&') {
    FUN_fffc754b((int)param_2);
    return;
  }
  if (param_1 == '\'') {
    FUN_fffc75d4((int)param_2);
    return;
  }
  if (param_1 == '(') {
    FUN_fffc7631((int)param_2);
    return;
  }
  if (param_1 == ')') {
    FUN_fffc768c((int)param_2);
    return;
  }
  if (param_1 == '*') {
    FUN_fffc76e9((int)param_2);
    return;
  }
  if (param_1 == '+') {
    FUN_fffc7764((int)param_2);
    return;
  }
  if (param_1 == ',') {
    FUN_fffc77df(param_2);
    return;
  }
  if (param_1 == '-') {
    FUN_fffc7923((int)param_2);
    return;
  }
  if (param_1 == '/') {
    FUN_fffc79b8((int)param_2);
    return;
  }
  if (param_1 == '0') {
    FUN_fffc7aa7((int)param_2);
    return;
  }
  if (param_1 == '1') {
    FUN_fffc7b02((int)param_2);
    return;
  }
  if (param_1 == '2') {
    FUN_fffc7b5f((int)param_2);
    return;
  }
  if (param_1 == '3') {
    FUN_fffc7bbc((int)param_2);
    return;
  }
  if (param_1 == '8') {
    FUN_fffc7cfd((int)param_2);
    return;
  }
  if (param_1 == '9') {
    FUN_fffc7d41((int)param_2);
    return;
  }
  if (param_1 == 'F') {
    FUN_fffc7975((int)param_2);
    return;
  }
  if (param_1 != '\x1e') {
    return;
  }
  FUN_fffc7016((int)param_2);
  return;
}


// ===== FUN_fffc6f11 @ fffc6f11 (237 bytes)

void FUN_fffc6f11(char param_1,char param_2)

{
  PTR_DAT_00025d58[0x41c] = 0;
  if (param_1 == ':') {
    FUN_fffc7bfd((int)param_2);
    return;
  }
  if (param_1 == '\x01') {
    FUN_fffc7053((int)param_2);
    return;
  }
  if (param_1 == '\x03') {
    FUN_fffc70af();
    return;
  }
  if (param_1 == '\x04') {
    FUN_fffc70db((int)param_2);
    return;
  }
  if (param_1 == '\x05') {
    FUN_fffc7145((int)param_2);
    return;
  }
  if (param_1 == '\x06') {
    FUN_fffc71af((int)param_2);
    return;
  }
  if (param_1 == '\a') {
    FUN_fffc74ee((int)param_2);
    return;
  }
  if (param_1 == '\t') {
    FUN_fffc75bc((int)param_2);
    return;
  }
  if (param_1 == '\n') {
    FUN_fffc7619((int)param_2);
    return;
  }
  if (param_1 == '\v') {
    FUN_fffc7674((int)param_2);
    return;
  }
  if (param_1 == '\f') {
    FUN_fffc76d1((int)param_2);
    return;
  }
  if (param_1 == '\r') {
    FUN_fffc774c((int)param_2);
    return;
  }
  if (param_1 == '\x0e') {
    FUN_fffc77c7((int)param_2);
    return;
  }
  if (param_1 == '\x0f') {
    FUN_fffc790b((int)param_2);
    return;
  }
  if (param_1 == '\x12') {
    FUN_fffc7a8f((int)param_2);
    return;
  }
  if (param_1 == '\x13') {
    FUN_fffc7aea((int)param_2);
    return;
  }
  if (param_1 == '\x14') {
    FUN_fffc7b47((int)param_2);
    return;
  }
  if (param_1 == '\x15') {
    FUN_fffc7ba4((int)param_2);
    return;
  }
  if (param_1 != '\0') {
    return;
  }
  FUN_fffc6ffe((int)param_2);
  return;
}


// ===== FUN_fffc6ffe @ fffc6ffe (24 bytes)

void FUN_fffc6ffe(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x1e;
  FUN_fffc7016((int)param_1);
  return;
}


// ===== FUN_fffc7016 @ fffc7016 (61 bytes)

void FUN_fffc7016(char param_1)

{
  byte *pbVar1;
  undefined2 uStack_4;
  
  FUN_fffc8cbb(0x1e);
  FUN_fffc8d8c();
  pbVar1 = (byte *)FUN_fff9c6ab();
  uStack_4 = (ushort)*pbVar1 + (short)param_1;
  if (uStack_4 < 0x79) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 0x78;
  }
  *pbVar1 = (byte)uStack_4;
  return;
}


// ===== FUN_fffc7053 @ fffc7053 (24 bytes)

void FUN_fffc7053(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x1f;
  FUN_fffc706b((int)param_1);
  return;
}


// ===== FUN_fffc706b @ fffc706b (68 bytes)

void FUN_fffc706b(char param_1)

{
  undefined2 uStack_4;
  
  FUN_fffc8cbb(0x1f);
  FUN_fffc8d8c();
  uStack_4 = (ushort)DAT_00009be6 + (short)param_1;
  if (uStack_4 < 5) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 4;
  }
  DAT_00009be6 = (undefined1)uStack_4;
  return;
}


// ===== FUN_fffc70af @ fffc70af (44 bytes)

void FUN_fffc70af(void)

{
  FUN_fffc8cbb(0xb);
  FUN_fffc8d8c();
  PTR_DAT_00025d58[0x1c2] = 0xb;
  PTR_DAT_00025d58[0x424] = DAT_00009be8;
  return;
}


// ===== FUN_fffc70db @ fffc70db (24 bytes)

void FUN_fffc70db(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x22;
  FUN_fffc70f3((int)param_1);
  return;
}


// ===== FUN_fffc70f3 @ fffc70f3 (82 bytes)

void FUN_fffc70f3(char param_1)

{
  short sStack_4;
  
  FUN_fffc8cbb(0x22);
  FUN_fffc8d8c();
  sStack_4 = (ushort)DAT_00009be9 + (short)param_1;
  if (sStack_4 < 0x15) {
    if (sStack_4 < 0) {
      sStack_4 = 0;
    }
  }
  else {
    sStack_4 = 0x14;
  }
  DAT_00009be9 = (undefined1)sStack_4;
  PTR_DAT_00025d58[0x400] = 1;
  return;
}


// ===== FUN_fffc7145 @ fffc7145 (24 bytes)

void FUN_fffc7145(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x23;
  FUN_fffc715d((int)param_1);
  return;
}


// ===== FUN_fffc715d @ fffc715d (82 bytes)

void FUN_fffc715d(char param_1)

{
  short sStack_4;
  
  FUN_fffc8cbb(0x23);
  FUN_fffc8d8c();
  sStack_4 = (ushort)DAT_00009bea + (short)param_1;
  if (sStack_4 < 0x15) {
    if (sStack_4 < 0) {
      sStack_4 = 0;
    }
  }
  else {
    sStack_4 = 0x14;
  }
  DAT_00009bea = (undefined1)sStack_4;
  PTR_DAT_00025d58[0x400] = 1;
  return;
}


// ===== FUN_fffc71af @ fffc71af (24 bytes)

void FUN_fffc71af(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x24;
  FUN_fffc71c7((int)param_1);
  return;
}


// ===== FUN_fffc71c7 @ fffc71c7 (213 bytes)

void FUN_fffc71c7(char param_1)

{
  bool bVar1;
  byte bVar2;
  
  FUN_fffc8cbb(0x24);
  FUN_fffc8d8c();
  if ((DAT_00009ac2 == '\0') || (PTR_DAT_00025d58[0x67] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d58[0x408] != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d58[0x46b] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d58[0x40d] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    bVar1 = DAT_00009dbd != '\0';
    bVar2 = vfo_is_memory(bVar1);
    if (bVar2 != 0) {
      if (param_1 < '\x01') {
        if (param_1 < '\0') {
          FUN_fffc73df(bVar1);
        }
      }
      else {
        FUN_fffc729c(bVar1);
      }
      bVar2 = memch_current(bVar1);
      eeprom_save_memch(bVar2);
      return;
    }
  }
  return;
}


// ===== FUN_fffc729c @ fffc729c (246 bytes)

void FUN_fffc729c(byte param_1)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  byte *pbStack_c;
  byte bStack_6;
  char cStack_5;
  byte bStack_4;
  byte bStack_3;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  bStack_2 = memch_current(param_1);
  bStack_3 = FUN_fff9bfe1(bStack_2);
  while (bStack_3 = bStack_3 + 1, bStack_3 < 7) {
    if (bStack_3 == 6) {
      bStack_4 = 99;
      cStack_5 = '\x12';
    }
    else {
      bStack_4 = 0;
      for (bStack_6 = 0; (int)(uint)bStack_6 < (int)(bStack_3 - 1); bStack_6 = bStack_6 + 1) {
        cVar1 = FUN_fff9cb6b();
        bStack_4 = cVar1 + bStack_4;
      }
      cStack_5 = FUN_fff9cb6b();
    }
    do {
      bVar2 = memch_valid(bStack_4,&pbStack_c);
      if (bVar2) {
        FUN_fffc73bf(bStack_4,bStack_2,local_1);
        return;
      }
      bStack_4 = bStack_4 + 1;
      cStack_5 = cStack_5 + -1;
    } while (cStack_5 != '\0');
    cStack_5 = 0;
  }
  if (bStack_3 == 7) {
    uVar3 = dest_code_get();
    if ((((uVar3 == 0x315b) || (uVar3 == 0x50e2)) || (uVar3 == 0xa4c5)) || (uVar3 == 0xd950)) {
      bStack_4 = FUN_fffc7392();
      FUN_fffc73bf(bStack_4,bStack_2,local_1);
      return;
    }
    if (DAT_00009af4 == '\x01') {
      bStack_3 = 8;
    }
  }
  if ((bStack_3 == 8) && (bStack_4 = 0x84, DAT_00009af4 == '\x01')) {
    FUN_fffc73bf(0x84,bStack_2,local_1);
    return;
  }
  bStack_4 = 0;
  FUN_fffc73bf(0,bStack_2,local_1);
  return;
}


// ===== FUN_fffc7392 @ fffc7392 (45 bytes)

char FUN_fffc7392(void)

{
  byte bVar1;
  byte local_2;
  
  local_2 = 0;
  while ((local_2 < 0xf && (bVar1 = memch_dest_blocked(local_2 + 0x75), bVar1 != 0))) {
    local_2 = local_2 + 1;
  }
  return local_2 + 0x75;
}


// ===== FUN_fffc73bf @ fffc73bf (32 bytes)

void FUN_fffc73bf(char param_1,char param_2,undefined1 param_3)

{
  if (param_1 == param_2) {
    return;
  }
  FUN_fffc2cdf(param_3,param_1);
  FUN_fffc568a(param_3);
  return;
}


// ===== FUN_fffc73df @ fffc73df (271 bytes)

void FUN_fffc73df(byte param_1)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  byte *pbStack_c;
  byte bStack_6;
  char cStack_5;
  byte bStack_4;
  byte bStack_3;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  bStack_2 = memch_current(param_1);
  bStack_3 = FUN_fff9bfe1(bStack_2);
  while( true ) {
    while( true ) {
      bStack_3 = bStack_3 - 1;
      if ((((bStack_3 == 7) && (uVar3 = dest_code_get(), uVar3 != 0x315b)) && (uVar3 != 0x50e2)) &&
         ((uVar3 != 0xa4c5 && (uVar3 != 0xd950)))) {
        bStack_3 = 6;
      }
      if (bStack_3 == 0) break;
      if (bStack_3 == 7) {
        bStack_4 = FUN_fffc7392();
        FUN_fffc73bf(bStack_4,bStack_2,local_1);
        return;
      }
      if (bStack_3 == 6) {
        bStack_4 = 99;
        cStack_5 = '\x12';
      }
      else {
        bStack_4 = 0;
        for (bStack_6 = 0; (int)(uint)bStack_6 < (int)(bStack_3 - 1); bStack_6 = bStack_6 + 1) {
          cVar1 = FUN_fff9cb6b();
          bStack_4 = cVar1 + bStack_4;
        }
        cStack_5 = FUN_fff9cb6b();
      }
      do {
        bVar2 = memch_valid(bStack_4,&pbStack_c);
        if (bVar2) {
          FUN_fffc73bf(bStack_4,bStack_2,local_1);
          return;
        }
        bStack_4 = bStack_4 + 1;
        cStack_5 = cStack_5 + -1;
      } while (cStack_5 != '\0');
      cStack_5 = 0;
    }
    if (DAT_00009af4 == '\x01') {
      bStack_4 = 0x84;
      FUN_fffc73bf(0x84,bStack_2,local_1);
      return;
    }
    uVar3 = dest_code_get();
    if (((uVar3 == 0x315b) || (uVar3 == 0x50e2)) || ((uVar3 == 0xa4c5 || (uVar3 == 0xd950)))) break;
    bStack_3 = 7;
  }
  bStack_4 = FUN_fffc7392();
  FUN_fffc73bf(bStack_4,bStack_2,local_1);
  return;
}


// ===== FUN_fffc74ee @ fffc74ee (24 bytes)

void FUN_fffc74ee(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x25;
  FUN_fffc7506((int)param_1);
  return;
}


// ===== FUN_fffc7506 @ fffc7506 (69 bytes)

void FUN_fffc7506(char param_1)

{
  byte *pbVar1;
  short sStack_4;
  
  FUN_fffc8cbb(0x25);
  FUN_fffc8d8c();
  pbVar1 = (byte *)FUN_fff99877();
  if (pbVar1 != (byte *)0x0) {
    sStack_4 = (ushort)*pbVar1 + (short)param_1;
    if (sStack_4 < 0x65) {
      if (sStack_4 < 0) {
        sStack_4 = 0;
      }
    }
    else {
      sStack_4 = 100;
    }
    *pbVar1 = (byte)sStack_4;
    return;
  }
  return;
}


// ===== FUN_fffc754b @ fffc754b (113 bytes)

void FUN_fffc754b(char param_1)

{
  bool bVar1;
  
  bVar1 = false;
  FUN_fffc8cbb(0x26);
  FUN_fffc8d8c();
  if (param_1 < '\x01') {
    if ((param_1 < '\0') && (DAT_00009bf0 == '\x01')) {
      DAT_00009bf0 = '\0';
      bVar1 = true;
    }
  }
  else if (DAT_00009bf0 == '\0') {
    DAT_00009bf0 = '\x01';
    bVar1 = true;
  }
  if (bVar1) {
    PTR_DAT_00025d58[0x40b] = 1;
    return;
  }
  return;
}


// ===== FUN_fffc75bc @ fffc75bc (24 bytes)

void FUN_fffc75bc(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x27;
  FUN_fffc75d4((int)param_1);
  return;
}


// ===== FUN_fffc75d4 @ fffc75d4 (69 bytes)

void FUN_fffc75d4(char param_1)

{
  undefined2 uStack_4;
  
  FUN_fffc8cbb(0x27);
  FUN_fffc8d8c();
  uStack_4 = (ushort)DAT_00009bf1 + (short)param_1;
  if (uStack_4 < 0x65) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 100;
  }
  DAT_00009bf1 = (undefined1)uStack_4;
  return;
}


// ===== FUN_fffc7619 @ fffc7619 (24 bytes)

void FUN_fffc7619(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x28;
  FUN_fffc7631((int)param_1);
  return;
}


// ===== FUN_fffc7631 @ fffc7631 (67 bytes)

void FUN_fffc7631(char param_1)

{
  undefined2 uStack_4;
  
  FUN_fffc8cbb(0x28);
  FUN_fffc8d8c();
  uStack_4 = (ushort)DAT_00009bf2 + (short)param_1;
  if (uStack_4 < 0x65) {
    if (uStack_4 < 1) {
      uStack_4 = 1;
    }
  }
  else {
    uStack_4 = 100;
  }
  DAT_00009bf2 = (undefined1)uStack_4;
  return;
}


// ===== FUN_fffc7674 @ fffc7674 (24 bytes)

void FUN_fffc7674(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x29;
  FUN_fffc768c((int)param_1);
  return;
}


// ===== FUN_fffc768c @ fffc768c (69 bytes)

void FUN_fffc768c(char param_1)

{
  undefined2 uStack_4;
  
  FUN_fffc8cbb(0x29);
  FUN_fffc8d8c();
  uStack_4 = (ushort)DAT_00009bf3 + (short)param_1;
  if (uStack_4 < 0x65) {
    if (uStack_4 < 0) {
      uStack_4 = 0;
    }
  }
  else {
    uStack_4 = 100;
  }
  DAT_00009bf3 = (undefined1)uStack_4;
  return;
}


// ===== FUN_fffc76d1 @ fffc76d1 (24 bytes)

void FUN_fffc76d1(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x2a;
  FUN_fffc76e9((int)param_1);
  return;
}


// ===== FUN_fffc76e9 @ fffc76e9 (99 bytes)

void FUN_fffc76e9(char param_1)

{
  short sStack_a;
  byte *pbStack_8;
  
  FUN_fffc8cbb(0x2a);
  FUN_fffc8d8c();
  if (DAT_00009af3 == '\0') {
    pbStack_8 = &DAT_00009bf4;
  }
  else {
    pbStack_8 = &DAT_00009bf5;
  }
  sStack_a = (ushort)*pbStack_8 + (short)param_1;
  if (sStack_a < 0x22) {
    if (sStack_a < 0) {
      sStack_a = 0;
    }
  }
  else {
    sStack_a = 0x21;
  }
  *pbStack_8 = (byte)sStack_a;
  return;
}


// ===== FUN_fffc774c @ fffc774c (24 bytes)

void FUN_fffc774c(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x2b;
  FUN_fffc7764((int)param_1);
  return;
}


// ===== FUN_fffc7764 @ fffc7764 (99 bytes)

void FUN_fffc7764(char param_1)

{
  short sStack_a;
  byte *pbStack_8;
  
  FUN_fffc8cbb(0x2b);
  FUN_fffc8d8c();
  if (DAT_00009af3 == '\0') {
    pbStack_8 = &DAT_00009bf6;
  }
  else {
    pbStack_8 = &DAT_00009bf7;
  }
  sStack_a = (ushort)*pbStack_8 + (short)param_1;
  if (sStack_a < 0x65) {
    if (sStack_a < 0) {
      sStack_a = 0;
    }
  }
  else {
    sStack_a = 100;
  }
  *pbStack_8 = (byte)sStack_a;
  return;
}


// ===== FUN_fffc77c7 @ fffc77c7 (24 bytes)

void FUN_fffc77c7(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x2c;
  FUN_fffc77df(param_1);
  return;
}


// ===== FUN_fffc77df @ fffc77df (72 bytes)

void FUN_fffc77df(char param_1)

{
  byte *pbVar1;
  ushort uStack_c;
  byte bStack_a;
  byte abStack_9 [8];
  char local_1;
  
  local_1 = param_1;
  FUN_fffc8cbb(0x2c);
  FUN_fffc8d8c();
  pbVar1 = FUN_fffc7827(abStack_9,&bStack_a);
  uStack_c = (ushort)*pbVar1 + (short)local_1;
  if ((short)(ushort)bStack_a < (short)uStack_c) {
    uStack_c = (ushort)bStack_a;
  }
  else if ((short)uStack_c < (short)(ushort)abStack_9[0]) {
    uStack_c = (ushort)abStack_9[0];
  }
  *pbVar1 = (byte)uStack_c;
  return;
}


// ===== FUN_fffc7827 @ fffc7827 (228 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc7908) */

void * FUN_fffc7827(void *param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined1 *puStack_1c;
  undefined1 uStack_17;
  
  uVar5 = vfo_freq(1,2);
  bVar2 = vfo_mode(1);
  bVar3 = FUN_fffb3371(uVar5);
  if ((bVar2 == 4) || (bVar2 == 5)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *param_2 = DAT_00009af1;
    puStack_1c = &DAT_00009bfb;
    uStack_17 = 3;
    if ((bVar3 < 9) && (bVar2 = FUN_fffb3e6f(3), bVar2 < *param_2)) {
      *param_2 = bVar2;
    }
  }
  else if (bVar3 < 9) {
    *param_2 = DAT_00009aee;
    puStack_1c = &DAT_00009bf8;
    uStack_17 = 0;
  }
  else if (bVar3 < 10) {
    *param_2 = DAT_00009aef;
    puStack_1c = &DAT_00009bf9;
    uStack_17 = 1;
  }
  else {
    *param_2 = DAT_00009af0;
    puStack_1c = &DAT_00009bfa;
    uStack_17 = 2;
  }
  uVar4 = FUN_fffb3f0b(uStack_17);
  *(undefined1 *)param_1 = uVar4;
  return puStack_1c;
}


// ===== FUN_fffc790b @ fffc790b (24 bytes)

void FUN_fffc790b(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x2d;
  FUN_fffc7923((int)param_1);
  return;
}


// ===== FUN_fffc7923 @ fffc7923 (82 bytes)

void FUN_fffc7923(char param_1)

{
  byte *pbVar1;
  short sStack_4;
  
  FUN_fffc8cbb(0x2d);
  FUN_fffc8d8c();
  pbVar1 = (byte *)FUN_fff99669();
  if (pbVar1 != (byte *)0x0) {
    sStack_4 = (ushort)*pbVar1 + (short)param_1;
    if (sStack_4 < 0x65) {
      if (sStack_4 < 0) {
        sStack_4 = 0;
      }
    }
    else {
      sStack_4 = 100;
    }
    *pbVar1 = (byte)sStack_4;
    PTR_DAT_00025d58[0x40c] = 1;
    return;
  }
  return;
}

