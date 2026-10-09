// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe47be @ fffe47be (10 bytes)

void FUN_fffe47be(void)

{
  FUN_fffe47c8();
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffe47c8 @ fffe47c8 (85 bytes)

void FUN_fffe47c8(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)PTR_DAT_00025d78[0xbe];
  if (uVar1 != 6) {
    if (uVar1 == 1) {
      FUN_fffe273a(0x85);
    }
    else if (uVar1 == 2) {
      FUN_fffe2811(0x85);
    }
    else if (1 < uVar1 - 3) {
      if (uVar1 == 5) {
        FUN_fffe291e(0x85);
      }
      else {
        if (uVar1 != 0) {
          return;
        }
        FUN_fffe2680(0x85);
      }
    }
  }
  PTR_DAT_00025d78[0x90] = 0;
  return;
}


// ===== FUN_fffe481d @ fffe481d (478 bytes)

void FUN_fffe481d(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  byte bStack_a;
  byte local_9;
  byte *pbStack_8;
  char *pcStack_4;
  
  local_9 = 1;
  pcVar2 = (char *)FUN_fffe52a1();
  cVar1 = PTR_DAT_00025d78[0xbf];
  if (cVar1 == '\x04') {
    pcStack_4 = &DAT_0000976c;
    pbStack_8 = &DAT_0000976b;
  }
  else if (cVar1 == '\x01') {
    pcStack_4 = &DAT_000096d3;
    pbStack_8 = &DAT_000096d2;
  }
  else if (cVar1 == '\x02') {
    pcStack_4 = &DAT_00009706;
    pbStack_8 = &DAT_00009705;
  }
  else if (cVar1 == '\x03') {
    pcStack_4 = &DAT_00009739;
    pbStack_8 = &DAT_00009738;
  }
  else if (cVar1 == '\0') {
    pcStack_4 = &DAT_000096a0;
    pbStack_8 = &DAT_0000969f;
  }
  for (bStack_a = 0; bStack_a < 0x32; bStack_a = bStack_a + 1) {
    if (pcVar2[bStack_a] == '}') {
      local_9 = bStack_a + 1;
      break;
    }
  }
  if (bStack_a == 0x32) {
    for (bStack_a = 0x31; bStack_a != 0; bStack_a = bStack_a - 1) {
      if (0x20 < (byte)pcVar2[bStack_a]) {
        local_9 = bStack_a + 1;
        break;
      }
    }
    if (bStack_a < 0x31) {
      if (bStack_a == 0) {
        if (*pcVar2 == ' ') {
          *pcVar2 = '}';
          local_9 = 1;
        }
        else {
          pcVar2[1] = '}';
          local_9 = 2;
        }
      }
      else if (pcVar2[0x31] == ' ') {
        pcVar2[local_9] = '}';
        local_9 = local_9 + 1;
      }
    }
  }
  for (bStack_a = local_9; bStack_a < 0x32; bStack_a = bStack_a + 1) {
    pcVar2[bStack_a] = ' ';
  }
  *pbStack_8 = local_9;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcStack_4 = *pcVar2;
    pcStack_4 = pcStack_4 + 1;
    pcVar2 = pcVar2 + 1;
  }
  if (PTR_DAT_00025d78[0xbf] == '\0') {
    FUN_fffb0450(1,1);
    return;
  }
  if (PTR_DAT_00025d78[0xbf] == '\x01') {
    FUN_fffb0450(1,2);
    return;
  }
  if (PTR_DAT_00025d78[0xbf] == '\x02') {
    FUN_fffb0450(1,3);
    return;
  }
  if (PTR_DAT_00025d78[0xbf] == '\x03') {
    FUN_fffb0450(1,4);
    return;
  }
  if (PTR_DAT_00025d78[0xbf] == '\x04') {
    FUN_fffb0450(1,5);
    return;
  }
  return;
}


// ===== FUN_fffe49fb @ fffe49fb (108 bytes)

void FUN_fffe49fb(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d78[0x90] == '\0') {
    if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (DAT_00020b99 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    FUN_fffb2da6(1);
    FUN_fffe52dd();
  }
  else {
    FUN_fffe4f82();
  }
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffe4a67 @ fffe4a67 (145 bytes)

void FUN_fffe4a67(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d78[0x92] == '\x01') || (PTR_DAT_00025d78[0x93] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (PTR_DAT_00025d78[0x90] != '\0') {
      FUN_fffe4f82();
      return;
    }
    if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (DAT_00020b99 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      FUN_fffb2da6(1);
      FUN_fffe52dd();
      return;
    }
  }
  return;
}


// ===== FUN_fffe4af8 @ fffe4af8 (123 bytes)

void FUN_fffe4af8(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b99 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00018872 == '\x01') {
      FUN_fffc809d(DAT_00009dbd);
      FUN_fffe40e5();
      FUN_fffb2da6(1);
      return;
    }
    FUN_fffe4ff2();
    FUN_fffe419a();
    FUN_fffb2da6(1);
    return;
  }
  return;
}


// ===== FUN_fffe4b73 @ fffe4b73 (64 bytes)

void FUN_fffe4b73(void)

{
  int iVar1;
  
  if (DAT_00018872 == '\x01') {
    iVar1 = FUN_fffe415d();
    if (iVar1 == 1) {
      if (PTR_DAT_00025d78[0x46b] == '\x01') {
        FUN_fffc809d(DAT_00009dbd);
      }
      FUN_fffe40e5();
      return;
    }
  }
  else {
    iVar1 = FUN_fffe419a();
    if (iVar1 == 1) {
      FUN_fffe4ff2();
      return;
    }
  }
  return;
}


// ===== FUN_fffe4bb3 @ fffe4bb3 (81 bytes)

void FUN_fffe4bb3(void)

{
  int iVar1;
  
  if ((((DAT_00018872 == '\x01') && (PTR_DAT_00025d78[0x39] == '\0')) &&
      (PTR_DAT_00025d78[0x46b] == '\x01')) && (iVar1 = FUN_fffe5aff(), iVar1 == 1)) {
    FUN_fffe5c7e();
  }
  PTR_DAT_00025d78[0x46b] = 0;
  PTR_DAT_00025d78[0x46c] = 0;
  return;
}


// ===== FUN_fffe4c04 @ fffe4c04 (81 bytes)

void FUN_fffe4c04(void)

{
  int iVar1;
  
  if ((((DAT_00018872 == '\x01') && (PTR_DAT_00025d78[0x39] == '\0')) &&
      (PTR_DAT_00025d78[0x46b] == '\x01')) && (iVar1 = FUN_fffe5aff(), iVar1 == 1)) {
    FUN_fffe5caf();
  }
  PTR_DAT_00025d78[0x46b] = 0;
  PTR_DAT_00025d78[0x46c] = 0;
  return;
}


// ===== FUN_fffe4c55 @ fffe4c55 (108 bytes)

void FUN_fffe4c55(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d78[0x90] == '\0') {
    if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (DAT_00020b99 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    FUN_fffb2da6(1);
    FUN_fffe506d();
  }
  else {
    FUN_fffe5092();
  }
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffe4cc1 @ fffe4cc1 (103 bytes)

void FUN_fffe4cc1(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d78[0x90] != '\0') {
    FUN_fffe5092();
    return;
  }
  if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b99 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    FUN_fffb2da6(1);
    FUN_fffe506d();
    return;
  }
  return;
}


// ===== FUN_fffe4d28 @ fffe4d28 (123 bytes)

void FUN_fffe4d28(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b99 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00018872 == '\x01') {
      FUN_fffc8141(DAT_00009dbd);
      FUN_fffe40e5();
      FUN_fffb2da6(1);
      return;
    }
    FUN_fffe5129();
    FUN_fffe419a();
    FUN_fffb2da6(1);
    return;
  }
  return;
}


// ===== FUN_fffe4da3 @ fffe4da3 (64 bytes)

void FUN_fffe4da3(void)

{
  int iVar1;
  
  if (DAT_00018872 == '\x01') {
    iVar1 = FUN_fffe415d();
    if (iVar1 == 1) {
      if (PTR_DAT_00025d78[0x46b] == '\x01') {
        FUN_fffc8141(DAT_00009dbd);
      }
      FUN_fffe40e5();
      return;
    }
  }
  else {
    iVar1 = FUN_fffe419a();
    if (iVar1 == 1) {
      FUN_fffe5129();
      return;
    }
  }
  return;
}


// ===== FUN_fffe4de3 @ fffe4de3 (1 bytes)

void FUN_fffe4de3(void)

{
  return;
}


// ===== FUN_fffe4de4 @ fffe4de4 (1 bytes)

void FUN_fffe4de4(void)

{
  return;
}


// ===== FUN_fffe4de5 @ fffe4de5 (137 bytes)

undefined1 FUN_fffe4de5(char param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 uStack_3;
  
  iVar2 = FUN_fffe5690();
  if (iVar2 == 0) {
    uStack_3 = 0;
  }
  else {
    if ((PTR_DAT_00025d78[0x1cc] == '\x01') || (PTR_DAT_00025d78[0x1cd] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (param_1 == PTR_DAT_00025d78[0x1c8])) {
      FUN_fffe53c0();
      uStack_3 = 0;
    }
    else {
      iVar2 = FUN_fffe5544(param_1);
      if (iVar2 == 0) {
        PTR_DAT_00025d78[0x1cc] = 1;
      }
      else {
        PTR_DAT_00025d78[0x1cd] = 1;
      }
      iVar2 = FUN_fffe55ab(param_1);
      if (iVar2 == 0) {
        uStack_3 = 0;
      }
      else {
        FUN_fffe538f(param_1);
        uStack_3 = 1;
      }
    }
  }
  return uStack_3;
}


// ===== FUN_fffe4e6e @ fffe4e6e (142 bytes)

void FUN_fffe4e6e(char param_1)

{
  int iVar1;
  
  if (PTR_DAT_00025d78[0x1c7] == '\0') {
    PTR_DAT_00025d78[0x79] = param_1 + -1;
    PTR_DAT_00025d78[0x1c8] = param_1;
    PTR_DAT_00025d78[0x1ca] = 1;
    FUN_fffe4efc();
    return;
  }
  if (PTR_DAT_00025d78[0x1c7] != '\x01') {
    return;
  }
  PTR_DAT_00025d78[0x417] = 0;
  PTR_DAT_00025d78[0x1cb] = 0;
  iVar1 = FUN_fffe5544(param_1);
  if (iVar1 != 1) {
    FUN_fffe5350(param_1);
    return;
  }
  PTR_DAT_00025d78[0x1c9] = 1;
  FUN_fffe538f(param_1);
  PTR_DAT_00025d78[0x2b] = 2;
  return;
}


// ===== FUN_fffe4efc @ fffe4efc (25 bytes)

void FUN_fffe4efc(void)

{
  FUN_fffb237a(0x37,&DAT_00002710);
  PTR_DAT_00025d78[0x1cb] = 1;
  return;
}


// ===== FUN_fffe4f15 @ fffe4f15 (109 bytes)

void FUN_fffe4f15(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d78[0x90] != '\0') {
    FUN_fffb2da6(1);
    FUN_fffe4f82();
    return;
  }
  FUN_fffb2da6(1);
  if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b99 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    FUN_fffe52dd();
    return;
  }
  return;
}


// ===== FUN_fffe4f82 @ fffe4f82 (39 bytes)

void FUN_fffe4f82(void)

{
  if (PTR_DAT_00025d78[0xc1] != '\0') {
    PTR_DAT_00025d78[0xc1] = PTR_DAT_00025d78[0xc1] + -1;
    return;
  }
  FUN_fffb2da6(3);
  return;
}


// ===== FUN_fffe4fa9 @ fffe4fa9 (73 bytes)

void FUN_fffe4fa9(void)

{
  DAT_00018872 = 0;
  if (DAT_00020b99 == '\x01') {
    FUN_fffb2da6(1);
    return;
  }
  if (PTR_DAT_00025d78[0x90] != '\0') {
    FUN_fffb2da6(1);
    FUN_fffe4ff2();
    return;
  }
  DAT_00018872 = 1;
  FUN_fffe60a6();
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffe4ff2 @ fffe4ff2 (14 bytes)

void FUN_fffe4ff2(void)

{
  int iVar1;
  
  iVar1 = FUN_fffe5211();
  if (iVar1 != 0) {
    return;
  }
  FUN_fffb2da6(3);
  return;
}


// ===== FUN_fffe5000 @ fffe5000 (109 bytes)

void FUN_fffe5000(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d78[0x90] != '\0') {
    FUN_fffb2da6(1);
    FUN_fffe5092();
    return;
  }
  FUN_fffb2da6(1);
  if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b99 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    FUN_fffe506d();
    return;
  }
  return;
}


// ===== FUN_fffe506d @ fffe506d (37 bytes)

void FUN_fffe506d(void)

{
  PTR_DAT_00025d78[0x47c] = 0;
  if (PTR_DAT_00025d78[0x418] != '\x01') {
    FUN_fffe5302();
    return;
  }
  FUN_fffe5d2a();
  return;
}


// ===== FUN_fffe5092 @ fffe5092 (78 bytes)

void FUN_fffe5092(void)

{
  byte bVar1;
  byte local_1;
  
  bVar1 = PTR_DAT_00025d78[0xbe];
  if (bVar1 == 5) {
    local_1 = 0xf;
  }
  else if (bVar1 == 2) {
    local_1 = 0x32;
  }
  else if (bVar1 < 2) {
    local_1 = 0xc;
  }
  if ((int)(local_1 - 1) <= (int)(uint)(byte)PTR_DAT_00025d78[0xc1]) {
    FUN_fffb2da6(3);
    return;
  }
  PTR_DAT_00025d78[0xc1] = PTR_DAT_00025d78[0xc1] + '\x01';
  return;
}


// ===== FUN_fffe50e0 @ fffe50e0 (73 bytes)

void FUN_fffe50e0(void)

{
  DAT_00018872 = 0;
  if (DAT_00020b99 == '\x01') {
    FUN_fffb2da6(1);
    return;
  }
  if (PTR_DAT_00025d78[0x90] != '\0') {
    FUN_fffb2da6(1);
    FUN_fffe5129();
    return;
  }
  DAT_00018872 = 1;
  FUN_fffe6138();
  FUN_fffb2da6(1);
  return;
}


// ===== FUN_fffe5129 @ fffe5129 (14 bytes)

void FUN_fffe5129(void)

{
  int iVar1;
  
  iVar1 = FUN_fffe5180();
  if (iVar1 != 0) {
    return;
  }
  FUN_fffb2da6(3);
  return;
}


// ===== FUN_fffe5137 @ fffe5137 (1 bytes)

void FUN_fffe5137(void)

{
  return;
}


// ===== FUN_fffe5138 @ fffe5138 (72 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe517d) */

undefined4 FUN_fffe5138(void)

{
  undefined *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  puVar1 = PTR_DAT_00025d78;
  uVar2 = FUN_fffba30c();
  *(undefined2 *)(puVar1 + 0x1d6) = uVar2;
  if (1 < *(ushort *)(PTR_DAT_00025d78 + 0x1d6)) {
    *(short *)(PTR_DAT_00025d78 + 0x1d6) = *(short *)(PTR_DAT_00025d78 + 0x1d6) + -1;
  }
  FUN_fffba336(*(undefined2 *)(PTR_DAT_00025d78 + 0x1d6));
  uVar3 = FUN_fffb2da6(1);
  return uVar3;
}


// ===== FUN_fffe5180 @ fffe5180 (145 bytes)

bool FUN_fffe5180(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  uVar2 = (uint)(byte)PTR_DAT_00025d78[0xbe];
  if (1 < uVar2) {
    if (uVar2 == 2) {
      iVar3 = FUN_fffe52a1();
      pbVar4 = (byte *)(iVar3 + (uint)(byte)PTR_DAT_00025d78[0xc1]);
      if (0x7c < *pbVar4) {
        return false;
      }
      *pbVar4 = *pbVar4 + 1;
      if (*pbVar4 == 0x60) {
        *pbVar4 = 0x7d;
      }
      return true;
    }
    if (uVar2 - 3 < 2) {
      return true;
    }
    if (uVar2 != 5) {
      return false;
    }
  }
  iVar3 = FUN_fffe52a1();
  pbVar4 = (byte *)(iVar3 + (uint)(byte)PTR_DAT_00025d78[0xc1]);
  bVar1 = *pbVar4;
  if (bVar1 < 0x70) {
    *pbVar4 = *pbVar4 + 1;
  }
  return bVar1 < 0x70;
}


// ===== FUN_fffe5211 @ fffe5211 (144 bytes)

bool FUN_fffe5211(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  bool local_9;
  
  bVar1 = PTR_DAT_00025d78[0xbe];
  if (1 < bVar1) {
    if (bVar1 == 2) {
      iVar2 = FUN_fffe52a1();
      pbVar3 = (byte *)(iVar2 + (uint)(byte)PTR_DAT_00025d78[0xc1]);
      if (0x20 < *pbVar3) {
        *pbVar3 = *pbVar3 - 1;
        if (*pbVar3 == 0x7c) {
          *pbVar3 = 0x5f;
        }
        return true;
      }
      *pbVar3 = 0x20;
      return false;
    }
    if (bVar1 == 4) {
      return true;
    }
    if (bVar1 != 5) {
      return false;
    }
  }
  iVar2 = FUN_fffe52a1();
  pbVar3 = (byte *)(iVar2 + (uint)(byte)PTR_DAT_00025d78[0xc1]);
  bVar1 = *pbVar3;
  if (bVar1 < 0x21) {
    *pbVar3 = 0x20;
  }
  else {
    *pbVar3 = *pbVar3 - 1;
  }
  local_9 = bVar1 >= 0x21;
  return local_9;
}


// ===== FUN_fffe52a1 @ fffe52a1 (60 bytes)

void FUN_fffe52a1(void)

{
  return;
}


// ===== FUN_fffe52dd @ fffe52dd (37 bytes)

void FUN_fffe52dd(void)

{
  PTR_DAT_00025d78[0x47c] = 1;
  if (PTR_DAT_00025d78[0x418] != '\x01') {
    FUN_fffe5302();
    return;
  }
  FUN_fffe5d2a();
  return;
}


// ===== FUN_fffe5302 @ fffe5302 (78 bytes)

void FUN_fffe5302(void)

{
  undefined1 uVar1;
  
  uVar1 = DAT_00009dbd;
  PTR_DAT_00025d78[0x46a] = 1;
  PTR_DAT_00025d78[0x479] = 1;
  FUN_fffc5c8f(uVar1,1);
  PTR_DAT_00025d78[0x46a] = 0;
  PTR_DAT_00025d78[0x479] = 0;
  return;
}


// ===== FUN_fffe5350 @ fffe5350 (63 bytes)

void FUN_fffe5350(undefined1 param_1)

{
  PTR_DAT_00025d78[0x90] = 1;
  PTR_DAT_00025d78[0xbe] = 2;
  PTR_DAT_00025d78[0xc0] = 0;
  PTR_DAT_00025d78[0xc1] = 0;
  FUN_fffe538f(param_1);
  FUN_fff9ba18();
  return;
}


// ===== FUN_fffe538f @ fffe538f (49 bytes)

void FUN_fffe538f(char param_1)

{
  PTR_DAT_00025d78[0x1c8] = param_1;
  PTR_DAT_00025d78[0xbf] = param_1 + -1;
  PTR_DAT_00025d78[0x1ce] = param_1 + -1;
  return;
}


// ===== FUN_fffe53c0 @ fffe53c0 (65 bytes)

void FUN_fffe53c0(void)

{
  PTR_DAT_00025d78[0x1cc] = 0;
  PTR_DAT_00025d78[0x1cd] = 0;
  PTR_DAT_00025d78[0x417] = 0;
  PTR_DAT_00025d78[0x1d1] = 0;
  PTR_DAT_00025d78[0x2b] = 7;
  return;
}


// ===== FUN_fffe5401 @ fffe5401 (323 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe551d) */
/* WARNING: Removing unreachable block (ram,0xfffe5477) */
/* WARNING: Removing unreachable block (ram,0xfffe54af) */
/* WARNING: Removing unreachable block (ram,0xfffe54e6) */
/* WARNING: Removing unreachable block (ram,0xfffe543f) */

ushort FUN_fffe5401(char param_1)

{
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined1 local_5;
  
  if (param_1 == '\x05') {
    local_5 = DAT_00009ab1;
    local_8 = (ushort)DAT_0000976b;
    local_a = CONCAT11(DAT_00009607,DAT_00009608);
  }
  else if (param_1 == '\x02') {
    local_5 = DAT_00009aae;
    local_8 = (ushort)DAT_000096d2;
    local_a = CONCAT11(DAT_0000943f,DAT_00009440);
  }
  else if (param_1 == '\x03') {
    local_5 = DAT_00009aaf;
    local_8 = (ushort)DAT_00009705;
    local_a = CONCAT11(DAT_000094d7,DAT_000094d8);
  }
  else if (param_1 == '\x04') {
    local_5 = DAT_00009ab0;
    local_8 = (ushort)DAT_00009738;
    local_a = CONCAT11(DAT_0000956f,DAT_00009570);
  }
  else if (param_1 == '\x01') {
    local_5 = DAT_00009aad;
    local_8 = (ushort)DAT_0000969f;
    local_a = CONCAT11((undefined1)DAT_000093a7,DAT_000093a7._1_1_);
  }
  if (local_5 == '\0') {
    local_c = local_8;
  }
  else {
    local_c = local_a;
  }
  return local_c;
}


// ===== FUN_fffe5544 @ fffe5544 (38 bytes)

undefined1 FUN_fffe5544(byte param_1)

{
  return (&DAT_00009aac)[param_1];
}


// ===== FUN_fffe556a @ fffe556a (65 bytes)

void FUN_fffe556a(void)

{
  PTR_DAT_00025d78[0x1c9] = 0;
  PTR_DAT_00025d78[0x1ca] = 0;
  PTR_DAT_00025d78[0x417] = 0;
  PTR_DAT_00025d78[0x78] = 0;
  PTR_DAT_00025d78[0x1cb] = 0;
  return;
}


// ===== FUN_fffe55ab @ fffe55ab (160 bytes)

undefined1 FUN_fffe55ab(undefined1 param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_fffe564b();
  if (iVar2 == 0) {
    PTR_DAT_00025d78[0x1cd] = 0;
    PTR_DAT_00025d78[0x1cc] = 0;
    return 0;
  }
  if ((PTR_DAT_00025d78[0x1cc] == '\x01') || (PTR_DAT_00025d78[0x1cd] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (PTR_DAT_00025d78[0x2b] != '\x01') {
      FUN_fffe53c0();
      return 0;
    }
    iVar2 = FUN_fffe5401(param_1);
    if (iVar2 == 0) {
      PTR_DAT_00025d78[0x1cd] = 0;
      PTR_DAT_00025d78[0x1cc] = 0;
      FUN_fffb2da6(3);
      return 0;
    }
    PTR_DAT_00025d78[0x2b] = 5;
  }
  return 1;
}


// ===== FUN_fffe564b @ fffe564b (69 bytes)

undefined1 FUN_fffe564b(void)

{
  uint uVar1;
  
  if (PTR_DAT_00025d78[0x407] == '\x01') {
    return 0;
  }
  uVar1 = (uint)(byte)PTR_DAT_00025d78[0x2b];
  if (1 < uVar1) {
    if (uVar1 - 2 < 3) {
      return 0;
    }
    if (2 < uVar1 - 5) {
      return 1;
    }
  }
  return 1;
}


// ===== FUN_fffe5690 @ fffe5690 (47 bytes)

bool FUN_fffe5690(void)

{
  char cVar1;
  bool bStack_3;
  
  cVar1 = FUN_fffb3196(1);
  if ((cVar1 == '\x03') || (cVar1 == '\x02')) {
    bStack_3 = false;
  }
  else {
    bStack_3 = true;
  }
  bStack_3 = !bStack_3;
  return bStack_3;
}


// ===== FUN_fffe56bf @ fffe56bf (37 bytes)

undefined1 FUN_fffe56bf(void)

{
  byte bVar1;
  undefined1 uStack_3;
  
  bVar1 = FUN_fffb3196(1);
  if ((bVar1 < 2) || (bVar1 - 4 < 4)) {
    uStack_3 = 1;
  }
  else {
    uStack_3 = 0;
  }
  return uStack_3;
}


// ===== FUN_fffe56e4 @ fffe56e4 (159 bytes)

void FUN_fffe56e4(byte param_1)

{
  undefined *puVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined1 local_84 [4];
  undefined4 *local_80;
  char acStack_79 [120];
  byte local_1;
  
  pcVar3 = "     RM 1";
  pcVar2 = acStack_79;
  local_1 = param_1;
  for (iVar4 = 0x78; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  if ((local_1 == 0) || (0xc < local_1)) {
    local_84 = (undefined1  [4])0x0;
  }
  else {
    local_84 = (undefined1  [4])0x1;
  }
  if ((local_84 != (undefined1  [4])0x0) &&
     (local_80 = (undefined4 *)(local_84 + (uint)local_1 * 10 + 1),
     PTR_DAT_00025d78[0x437] == '\x01')) {
    FUN_fffb2da6(1);
    FUN_fffc8beb();
    PTR_DAT_00025d78[0x1c2] = 0x5e;
    puVar1 = PTR_DAT_00025d78;
    *(undefined2 *)(PTR_DAT_00025d78 + 0x42f) = *(undefined2 *)(local_80 + 2);
    *(undefined4 *)(puVar1 + 0x42b) = local_80[1];
    *(undefined4 *)(puVar1 + 0x427) = *local_80;
    FUN_fffc8cbb(0x5e);
    FUN_fffc8d8c();
    PTR_DAT_00025d78[0x409] = 1;
    return;
  }
  return;
}


// ===== FUN_fffe5783 @ fffe5783 (203 bytes)

byte FUN_fffe5783(void)

{
  int iVar1;
  byte local_3;
  byte local_2;
  
  local_2 = 0;
  if (PTR_DAT_00025d78[0x1c7] == '\x01') {
    if ((DAT_00009aad == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
      local_2 = 1;
    }
    if ((DAT_00009aae == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
      local_2 = local_2 | 2;
    }
    if ((DAT_00009aaf == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
      local_2 = local_2 | 4;
    }
    if ((DAT_00009ab0 == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
      local_2 = local_2 | 8;
    }
    if ((DAT_00009ab1 == '\0') && (iVar1 = FUN_fffe584e(), iVar1 == 1)) {
      local_2 = local_2 | 0x10;
    }
    local_3 = local_2;
  }
  else {
    local_3 = 0;
  }
  return local_3;
}


// ===== FUN_fffe584e @ fffe584e (49 bytes)

undefined1 FUN_fffe584e(int param_1)

{
  byte local_6;
  
  local_6 = 0;
  while( true ) {
    if (0x31 < local_6) {
      return 0;
    }
    if (*(char *)((uint)local_6 + param_1) == '#') break;
    local_6 = local_6 + 1;
  }
  return 1;
}


// ===== FUN_fffe587f @ fffe587f (411 bytes)

void FUN_fffe587f(void)

{
  bool bVar1;
  int iVar2;
  
  FUN_fffe61ca();
  if ((PTR_DAT_00025d7c[0x418] == '\0') || (PTR_DAT_00025d7c[0xba] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    switch(DAT_00018877) {
    case 0:
      PTR_DAT_00025d7c[0x419] = 0;
      FUN_fffe5a1a();
      return;
    case 1:
      iVar2 = FUN_fffe5ee3();
      if (iVar2 == 1) {
        iVar2 = FUN_fffe5ab2();
        if (iVar2 == 0) {
          PTR_DAT_00025d7c[0x419] = 0;
          FUN_fffe5e67();
          DAT_00018877 = 2;
          return;
        }
        PTR_DAT_00025d7c[0x419] = 1;
        FUN_fffe5a1a();
        return;
      }
      break;
    case 2:
      iVar2 = FUN_fffe5ee3();
      if (iVar2 == 1) {
        iVar2 = FUN_fffe5acf();
        if (iVar2 == 0) {
          FUN_fffe5a47();
          return;
        }
        iVar2 = FUN_fffe5ab2();
        if (iVar2 == 0) {
          FUN_fffe5a2a();
          return;
        }
        iVar2 = FUN_fffe5fdd();
        if (iVar2 == 0) {
          FUN_fffe5a2a();
          return;
        }
        iVar2 = FUN_fffe600f();
        if (iVar2 != 1) {
          FUN_fffe5a2a();
          return;
        }
        DAT_00018873 = 1;
        FUN_fffb237a(0x33,500);
        DAT_00018877 = 3;
        return;
      }
      break;
    case 3:
      iVar2 = FUN_fffe5ee3();
      if (iVar2 == 1) {
        iVar2 = FUN_fffe5acf();
        if (iVar2 == 1) {
          FUN_fffe5a2a();
          return;
        }
        FUN_fffe5a47();
        return;
      }
      break;
    case 4:
      iVar2 = FUN_fffe5ae7();
      if (iVar2 == 1) {
        DAT_00018874 = 1;
        FUN_fffb237a(0x34,0x5dc);
        DAT_00018877 = 5;
        return;
      }
      break;
    case 5:
      iVar2 = FUN_fffe5f18();
      if (iVar2 == 1) {
        FUN_fffe5a2a();
        return;
      }
      iVar2 = FUN_fffe5ae7();
      if (iVar2 == 0) {
        DAT_00018877 = 4;
        return;
      }
      break;
    case 6:
      iVar2 = FUN_fffe5f4d();
      if (iVar2 == 1) {
        FUN_fffe5a2a();
        return;
      }
      iVar2 = FUN_fffe5ae7();
      if (iVar2 == 1) {
        DAT_00018874 = 1;
        FUN_fffb237a(0x34,0x5dc);
        DAT_00018877 = 7;
        return;
      }
      break;
    case 7:
      iVar2 = FUN_fffe5f4d();
      if (iVar2 == 1) {
        FUN_fffe5a2a();
        return;
      }
      iVar2 = FUN_fffe5f18();
      if (iVar2 == 1) {
        FUN_fffe5a2a();
        return;
      }
      iVar2 = FUN_fffe5ae7();
      if (iVar2 == 0) {
        DAT_00018877 = 6;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffe5a1a @ fffe5a1a (16 bytes)

void FUN_fffe5a1a(void)

{
  FUN_fffe5d7c();
  FUN_fffe5e67();
  DAT_00018877 = 1;
  return;
}


// ===== FUN_fffe5a2a @ fffe5a2a (29 bytes)

void FUN_fffe5a2a(void)

{
  PTR_DAT_00025d7c[0x419] = 0;
  FUN_fffe5d7c();
  FUN_fffe5e67();
  DAT_00018877 = 2;
  return;
}

