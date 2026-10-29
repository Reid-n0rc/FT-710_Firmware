// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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
    beep_request(1);
    FUN_fffe506d();
  }
  else {
    FUN_fffe5092();
  }
  beep_request(1);
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
    beep_request(1);
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
      beep_request(1);
      return;
    }
    FUN_fffe5129();
    FUN_fffe419a();
    beep_request(1);
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
  swtimer_start(0x37,10000);
  PTR_DAT_00025d78[0x1cb] = 1;
  return;
}


// ===== FUN_fffe4f15 @ fffe4f15 (109 bytes)

void FUN_fffe4f15(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d78[0x90] != '\0') {
    beep_request(1);
    FUN_fffe4f82();
    return;
  }
  beep_request(1);
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
  beep_request(3);
  return;
}


// ===== FUN_fffe4fa9 @ fffe4fa9 (73 bytes)

void FUN_fffe4fa9(void)

{
  DAT_00018872 = 0;
  if (DAT_00020b99 == '\x01') {
    beep_request(1);
    return;
  }
  if (PTR_DAT_00025d78[0x90] != '\0') {
    beep_request(1);
    FUN_fffe4ff2();
    return;
  }
  DAT_00018872 = 1;
  FUN_fffe60a6();
  beep_request(1);
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
  beep_request(3);
  return;
}


// ===== FUN_fffe5000 @ fffe5000 (109 bytes)

void FUN_fffe5000(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d78[0x90] != '\0') {
    beep_request(1);
    FUN_fffe5092();
    return;
  }
  beep_request(1);
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
    beep_request(3);
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
    beep_request(1);
    return;
  }
  if (PTR_DAT_00025d78[0x90] != '\0') {
    beep_request(1);
    FUN_fffe5129();
    return;
  }
  DAT_00018872 = 1;
  FUN_fffe6138();
  beep_request(1);
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
  beep_request(3);
  return;
}


// ===== FUN_fffe5137 @ fffe5137 (1 bytes)

void FUN_fffe5137(void)

{
  return;
}


// ===== FUN_fffe5138 @ fffe5138 (72 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe517d) */

void FUN_fffe5138(void)

{
  undefined *puVar1;
  undefined2 uVar2;
  
  puVar1 = PTR_DAT_00025d78;
  uVar2 = FUN_fffba30c();
  *(undefined2 *)(puVar1 + 0x1d6) = uVar2;
  if (1 < *(ushort *)(PTR_DAT_00025d78 + 0x1d6)) {
    *(short *)(PTR_DAT_00025d78 + 0x1d6) = *(short *)(PTR_DAT_00025d78 + 0x1d6) + -1;
  }
  FUN_fffba336(*(undefined2 *)(PTR_DAT_00025d78 + 0x1d6));
  beep_request(1);
  return;
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
    local_a = CONCAT11(DAT_000093a7,DAT_000093a8);
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
      beep_request(3);
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
  byte bVar1;
  bool bStack_3;
  
  bVar1 = vfo_mode(1);
  if ((bVar1 == 3) || (bVar1 == 2)) {
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
  
  bVar1 = vfo_mode(1);
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
    beep_request(1);
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
  byte bVar1;
  byte local_3;
  byte local_2;
  
  local_2 = 0;
  if (PTR_DAT_00025d78[0x1c7] == '\x01') {
    if ((DAT_00009aad == '\0') && (bVar1 = FUN_fffe584e(0x96a0), bVar1 == 1)) {
      local_2 = 1;
    }
    if ((DAT_00009aae == '\0') && (bVar1 = FUN_fffe584e(0x96d3), bVar1 == 1)) {
      local_2 = local_2 | 2;
    }
    if ((DAT_00009aaf == '\0') && (bVar1 = FUN_fffe584e(0x9706), bVar1 == 1)) {
      local_2 = local_2 | 4;
    }
    if ((DAT_00009ab0 == '\0') && (bVar1 = FUN_fffe584e(0x9739), bVar1 == 1)) {
      local_2 = local_2 | 8;
    }
    if ((DAT_00009ab1 == '\0') && (bVar1 = FUN_fffe584e(0x976c), bVar1 == 1)) {
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

byte FUN_fffe584e(int param_1)

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


// ===== scan_task @ fffe587f (411 bytes)

/* Main-loop scan state machine (0x18877), run flag 0x20F1C */

void scan_task(void)

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
        swtimer_start(0x33,500);
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
        swtimer_start(0x34,0x5dc);
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
        swtimer_start(0x34,0x5dc);
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
  scan_step();
  FUN_fffe5e67();
  DAT_00018877 = 1;
  return;
}


// ===== FUN_fffe5a2a @ fffe5a2a (29 bytes)

void FUN_fffe5a2a(void)

{
  PTR_DAT_00025d7c[0x419] = 0;
  scan_step();
  FUN_fffe5e67();
  DAT_00018877 = 2;
  return;
}


// ===== FUN_fffe5a47 @ fffe5a47 (107 bytes)

void FUN_fffe5a47(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = DAT_00009dbd;
  PTR_DAT_00025d7c[0x419] = 1;
  iVar3 = FUN_fffe5f82();
  if ((iVar3 == 0) || (bVar2 = vfo_is_memory(bVar2), bVar2 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    beep_request(6);
    if (DAT_00009ac5 == '\x01') {
      FUN_fffe5ece();
      DAT_00018877 = 6;
      return;
    }
    DAT_00018877 = 4;
    return;
  }
  scan_step();
  FUN_fffe5eba();
  return;
}


// ===== FUN_fffe5ab2 @ fffe5ab2 (29 bytes)

bool FUN_fffe5ab2(void)

{
  return DAT_00020b48 == '\x01';
}


// ===== FUN_fffe5acf @ fffe5acf (24 bytes)

bool FUN_fffe5acf(void)

{
  bool bVar1;
  
  bVar1 = af_mute_get();
  return bVar1;
}


// ===== FUN_fffe5ae7 @ fffe5ae7 (24 bytes)

bool FUN_fffe5ae7(void)

{
  bool bVar1;
  
  bVar1 = af_mute_get();
  return bVar1;
}


// ===== scan_allowed @ fffe5aff (82 bytes)

byte scan_allowed(void)

{
  undefined1 local_4;
  undefined1 local_3;
  
  if (DAT_00009ac4 == '\0') {
    local_4 = 0;
  }
  else {
    if (DAT_00009dbd == '\0') {
      local_3 = DAT_00009dbe;
    }
    else {
      local_3 = DAT_00009dbf;
    }
    if (local_3 == '\x02') {
      local_4 = FUN_fffe5b51();
    }
    else {
      local_4 = 1;
    }
  }
  return local_4;
}


// ===== FUN_fffe5b51 @ fffe5b51 (213 bytes)

byte FUN_fffe5b51(void)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  byte bStack_7;
  
  if (DAT_00009ac2 == '\0') {
    bStack_7 = FUN_fffe5c26('\0',99);
  }
  else {
    bVar2 = FUN_fff9bfb8();
    if (bVar2 < 8) {
      if (bVar2 == 7) {
        uVar3 = dest_code_get();
        if ((uVar3 == 0xd950) || (uVar3 == 0xa4c5)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          bStack_7 = FUN_fffe5c26('u',7);
        }
        else {
          if ((uVar3 == 0x315b) || (uVar3 == 0x50e2)) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            bStack_7 = FUN_fffe5c26('u',0xf);
          }
          else {
            bStack_7 = 0;
          }
        }
      }
      else if (bVar2 == 6) {
        bStack_7 = FUN_fffe5c26('c',0x12);
      }
      else {
        bStack_7 = FUN_fffe5c26("RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                                [bVar2 + 0x3d92],BYTE_ARRAY_fff872a8[bVar2 + 3]);
      }
    }
    else {
      bStack_7 = 0;
    }
  }
  return bStack_7;
}


// ===== FUN_fffe5c26 @ fffe5c26 (88 bytes)

byte FUN_fffe5c26(char param_1,byte param_2)

{
  bool bVar1;
  int iVar2;
  byte *pbStack_c;
  byte local_5;
  byte local_4;
  byte local_2;
  char local_1;
  
  local_5 = 0;
  local_4 = 0;
  local_2 = param_2;
  local_1 = param_1;
  while( true ) {
    if (local_2 <= local_4) {
      return 0;
    }
    bVar1 = memch_valid(local_1 + local_4,&pbStack_c);
    if (((bVar1) && (iVar2 = FUN_fffe5e3b(local_1 + local_4), iVar2 == 0)) &&
       (local_5 = local_5 + 1, 1 < local_5)) break;
    local_4 = local_4 + 1;
  }
  return 1;
}


// ===== scan_start_up @ fffe5c7e (49 bytes)

/* SC1 */

void scan_start_up(void)

{
  DAT_00018876 = 0;
  DAT_00018877 = 0;
  if (PTR_DAT_00025d7c[0x418] != '\0') {
    return;
  }
  PTR_DAT_00025d7c[0x418] = 1;
  return;
}


// ===== scan_start_down @ fffe5caf (49 bytes)

/* SC2 */

void scan_start_down(void)

{
  DAT_00018876 = 1;
  DAT_00018877 = 0;
  if (PTR_DAT_00025d7c[0x418] != '\0') {
    return;
  }
  PTR_DAT_00025d7c[0x418] = 1;
  return;
}

