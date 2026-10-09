// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
    FUN_fffc77df((int)param_2);
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
  undefined1 uVar2;
  int iVar3;
  
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
    iVar3 = FUN_fffc2d93(bVar1);
    if (iVar3 != 0) {
      if (param_1 < '\x01') {
        if (param_1 < '\0') {
          FUN_fffc73df(bVar1);
        }
      }
      else {
        FUN_fffc729c(bVar1);
      }
      uVar2 = FUN_fffc2e65(bVar1);
      FUN_fffb0376(uVar2);
      return;
    }
  }
  return;
}


// ===== FUN_fffc729c @ fffc729c (246 bytes)

void FUN_fffc729c(undefined1 param_1)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined1 auStack_c [6];
  byte bStack_6;
  char cStack_5;
  char cStack_4;
  byte bStack_3;
  undefined1 uStack_2;
  undefined1 local_1;
  
  local_1 = param_1;
  uStack_2 = FUN_fffc2e65(param_1);
  bStack_3 = FUN_fff9bfe1(uStack_2);
  while (bStack_3 = bStack_3 + 1, bStack_3 < 7) {
    if (bStack_3 == 6) {
      cStack_4 = 'c';
      cStack_5 = '\x12';
    }
    else {
      cStack_4 = '\0';
      for (bStack_6 = 0; bStack_6 < (byte)(bStack_3 - 1); bStack_6 = bStack_6 + 1) {
        cVar1 = FUN_fff9cb6b();
        cStack_4 = cVar1 + cStack_4;
      }
      cStack_5 = FUN_fff9cb6b();
    }
    do {
      iVar3 = FUN_fffc2e01(cStack_4,auStack_c);
      if (iVar3 == 1) {
        FUN_fffc73bf(cStack_4,uStack_2,local_1);
        return;
      }
      cStack_4 = cStack_4 + '\x01';
      cStack_5 = cStack_5 + -1;
    } while (cStack_5 != '\0');
    cStack_5 = 0;
  }
  if (bStack_3 == 7) {
    puVar2 = (undefined *)FUN_fffb3b33();
    if ((((puVar2 == &DAT_0000315b) || (puVar2 == &DAT_000050e2)) || (puVar2 == &DAT_0000a4c5)) ||
       (puVar2 == &DAT_0000d950)) {
      cStack_4 = FUN_fffc7392();
      FUN_fffc73bf(cStack_4,uStack_2,local_1);
      return;
    }
    if (DAT_00009af4 == '\x01') {
      bStack_3 = 8;
    }
  }
  if ((bStack_3 == 8) && (cStack_4 = 0x84, DAT_00009af4 == '\x01')) {
    FUN_fffc73bf(0x84,uStack_2,local_1);
    return;
  }
  cStack_4 = 0;
  FUN_fffc73bf(0,uStack_2,local_1);
  return;
}


// ===== FUN_fffc7392 @ fffc7392 (45 bytes)

char FUN_fffc7392(void)

{
  int iVar1;
  byte local_2;
  
  local_2 = 0;
  while ((local_2 < 0xf && (iVar1 = FUN_fffc2e8d(*(undefined1 *)(local_2 + 0x75)), iVar1 != 0))) {
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

void FUN_fffc73df(undefined1 param_1)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined1 auStack_c [6];
  byte bStack_6;
  char cStack_5;
  char cStack_4;
  char cStack_3;
  undefined1 uStack_2;
  undefined1 local_1;
  
  local_1 = param_1;
  uStack_2 = FUN_fffc2e65(param_1);
  cStack_3 = FUN_fff9bfe1(uStack_2);
  while( true ) {
    while( true ) {
      cStack_3 = cStack_3 + -1;
      if ((((cStack_3 == '\a') && (puVar2 = (undefined *)FUN_fffb3b33(), puVar2 != &DAT_0000315b))
          && (puVar2 != &DAT_000050e2)) && ((puVar2 != &DAT_0000a4c5 && (puVar2 != &DAT_0000d950))))
      {
        cStack_3 = '\x06';
      }
      if (cStack_3 == '\0') break;
      if (cStack_3 == '\a') {
        cStack_4 = FUN_fffc7392();
        FUN_fffc73bf(cStack_4,uStack_2,local_1);
        return;
      }
      if (cStack_3 == '\x06') {
        cStack_4 = 'c';
        cStack_5 = '\x12';
      }
      else {
        cStack_4 = '\0';
        for (bStack_6 = 0; bStack_6 < (byte)(cStack_3 - 1U); bStack_6 = bStack_6 + 1) {
          cVar1 = FUN_fff9cb6b();
          cStack_4 = cVar1 + cStack_4;
        }
        cStack_5 = FUN_fff9cb6b();
      }
      do {
        iVar3 = FUN_fffc2e01(cStack_4,auStack_c);
        if (iVar3 == 1) {
          FUN_fffc73bf(cStack_4,uStack_2,local_1);
          return;
        }
        cStack_4 = cStack_4 + '\x01';
        cStack_5 = cStack_5 + -1;
      } while (cStack_5 != '\0');
      cStack_5 = 0;
    }
    if (DAT_00009af4 == '\x01') {
      cStack_4 = 0x84;
      FUN_fffc73bf(0x84,uStack_2,local_1);
      return;
    }
    puVar2 = (undefined *)FUN_fffb3b33();
    if (((puVar2 == &DAT_0000315b) || (puVar2 == &DAT_000050e2)) ||
       ((puVar2 == &DAT_0000a4c5 || (puVar2 == &DAT_0000d950)))) break;
    cStack_3 = '\a';
  }
  cStack_4 = FUN_fffc7392();
  FUN_fffc73bf(cStack_4,uStack_2,local_1);
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
  FUN_fffc77df((int)param_1);
  return;
}


// ===== FUN_fffc77df @ fffc77df (72 bytes)

void FUN_fffc77df(char param_1)

{
  byte *pbVar1;
  undefined2 uStack_c;
  undefined1 uStack_a;
  undefined1 uStack_9;
  
  FUN_fffc8cbb(0x2c);
  FUN_fffc8d8c();
  pbVar1 = (byte *)FUN_fffc7827();
  uStack_c = (ushort)*pbVar1 + (short)param_1;
  if ((short)(ushort)uStack_a < (short)uStack_c) {
    uStack_c = (ushort)uStack_a;
  }
  else if ((short)uStack_c < (short)(ushort)uStack_9) {
    uStack_c = (ushort)uStack_9;
  }
  *pbVar1 = (byte)uStack_c;
  return;
}


// ===== FUN_fffc7827 @ fffc7827 (228 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc7908) */

undefined1 * FUN_fffc7827(undefined1 *param_1,byte *param_2)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined1 *puStack_1c;
  undefined1 uStack_17;
  
  uVar5 = FUN_fffb357c(1,2);
  cVar2 = FUN_fffb3196(1);
  bVar3 = FUN_fffb3371(uVar5);
  if ((cVar2 == '\x04') || (cVar2 == '\x05')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *param_2 = DAT_00009af1;
    puStack_1c = &DAT_00009bfb;
    uStack_17 = 3;
    if ((bVar3 < 9) && (bVar3 = FUN_fffb3e6f(3), bVar3 < *param_2)) {
      *param_2 = bVar3;
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
  *param_1 = uVar4;
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


// ===== FUN_fffc7975 @ fffc7975 (67 bytes)

void FUN_fffc7975(char param_1)

{
  FUN_fffc8cbb(0x46);
  FUN_fffc8d8c();
  if (param_1 < '\x01') {
    if (DAT_00009c02 == '\x01') {
      DAT_00009c02 = 0;
      return;
    }
  }
  else if (DAT_00009c02 == '\0') {
    DAT_00009c02 = 1;
    return;
  }
  return;
}


// ===== FUN_fffc79b8 @ fffc79b8 (215 bytes)

void FUN_fffc79b8(char param_1)

{
  uint uVar1;
  byte *pbStack_c;
  byte *pbStack_8;
  
  FUN_fffc8cbb(0x2f);
  FUN_fffc8d8c();
  if (DAT_00009dbd == '\0') {
    uRam00000000 = 1;
  }
  if (DAT_00009c5e == '\0') {
    if (DAT_00009dbd == '\0') {
      pbStack_8 = &DAT_00009d63;
    }
    else {
      pbStack_8 = &DAT_00009d09;
    }
  }
  else if (DAT_00009dbd == '\0') {
    pbStack_8 = &DAT_00009d09;
  }
  else {
    pbStack_8 = &DAT_00009d63;
  }
  uVar1 = (uint)(*pbStack_8 & 0xf);
  if (uVar1 - 6 < 2) {
    pbStack_c = pbStack_8 + 0x3c;
  }
  else if (uVar1 - 2 < 2) {
    pbStack_c = pbStack_8 + 0x14;
  }
  else if (uVar1 - 4 < 2) {
    pbStack_c = pbStack_8 + 0x32;
  }
  else {
    if (1 < uVar1) {
      return;
    }
    pbStack_c = pbStack_8 + 10;
  }
  if (param_1 < '\x01') {
    if ((*pbStack_c & 2) != 0) {
      *pbStack_c = *pbStack_c & 0xfd;
LAB_fffc7a7e:
      PTR_DAT_00025d58[0x40c] = 1;
      return;
    }
  }
  else if ((*pbStack_c & 2) == 0) {
    *pbStack_c = *pbStack_c | 2;
    goto LAB_fffc7a7e;
  }
  return;
}


// ===== FUN_fffc7a8f @ fffc7a8f (24 bytes)

void FUN_fffc7a8f(char param_1)

{
  PTR_DAT_00025d58[0x1c2] = 0x30;
  FUN_fffc7aa7((int)param_1);
  return;
}


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

