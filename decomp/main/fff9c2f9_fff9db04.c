// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff9c2f9 @ fff9c2f9 (305 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9c424) */
/* WARNING: Removing unreachable block (ram,0xfff9c32a) */
/* WARNING: Removing unreachable block (ram,0xfff9c331) */
/* WARNING: Removing unreachable block (ram,0xfff9c427) */

byte * FUN_fff9c2f9(byte *param_1,byte param_2)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = (uint)param_2 * 0x5a;
  DAT_00020888 = &DAT_00006150 + iVar1;
  DAT_0002088c = (uint)(byte)(&DAT_0000619a)[iVar1] << 0x18 | (uint)(byte)(&DAT_0000619d)[iVar1];
  DAT_0002088c = FUN_fff9cba4(DAT_0002088c,param_2);
  FUN_fff9c95c(DAT_0002088c,&DAT_00001a5a);
  *param_1 = DAT_00001a5a >> 4 | 0x30;
  param_1[1] = DAT_00001a5a & 0x3f | 0x30;
  param_1[2] = 0x2e;
  param_1[3] = DAT_00001a5b >> 4 | 0x30;
  param_1[4] = DAT_00001a5b & 0x3f | 0x30;
  param_1[5] = DAT_00001a5c >> 4 | 0x30;
  param_1[6] = 0x2e;
  param_1[7] = DAT_00001a5c & 0x3f | 0x30;
  param_1[8] = DAT_00001a5d >> 4 | 0x30;
  param_1[9] = DAT_00001a5d & 0x3f | 0x30;
  pbVar2 = param_1;
  if (*param_1 == 0x30) {
    *param_1 = 0x20;
    pbVar2 = (byte *)(uint)param_1[1];
    if ((byte *)(uint)param_1[1] == (byte *)0x30) {
      param_1[1] = 0x20;
      param_1[2] = 0x20;
      pbVar2 = (byte *)(uint)param_1[3];
      if ((byte *)(uint)param_1[3] == (byte *)0x30) {
        param_1[3] = 0x20;
        return param_1;
      }
    }
  }
  return pbVar2;
}


// ===== FUN_fff9c42a @ fff9c42a (42 bytes)

void FUN_fff9c42a(void)

{
  int iVar1;
  
  FUN_fff9c454();
  iVar1 = FUN_fff9c667(&DAT_000016a0,&DAT_00001456,0x98);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x99;
  FUN_fff9c5b2(0x99);
  return;
}


// ===== FUN_fff9c454 @ fff9c454 (25 bytes)

void FUN_fff9c454(void)

{
  FUN_fff9c655(0x98,&DAT_000016a0);
  DAT_000016a0 = 0x20;
  FUN_fff96455();
  return;
}


// ===== FUN_fff9c46d @ fff9c46d (45 bytes)

void FUN_fff9c46d(void)

{
  int iVar1;
  
  FUN_fff9c49a();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0x196);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x197;
  FUN_fff9c5b2(0x197);
  return;
}


// ===== FUN_fff9c49a @ fff9c49a (187 bytes)

void FUN_fff9c49a(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  ushort uStack_4;
  byte bStack_1;
  
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
  DAT_00001741 = 0x62;
  FUN_fff98cd3();
  DAT_000017d9 = PTR_DAT_00025d38[0x1dd];
  uStack_4 = *(short *)(PTR_DAT_00025d38 + 0x1de) - (ushort)(byte)PTR_DAT_00025d38[0x1dd];
  if (*(ushort *)(PTR_DAT_00025d38 + 0x1de) < (ushort)(byte)PTR_DAT_00025d38[0x1dd]) {
    uStack_4 = uStack_4 + 0x105;
  }
  for (bStack_1 = 0; bStack_1 < 9; bStack_1 = bStack_1 + 1) {
    pcVar2 = " 001 [GN] VDD MTR         002 [GN] FAN             003 [GN] REF FREQ        004 [GN] TX INH          005 [GN] --RESERVED--    006 [GN] --RESERVED--    007 [GN] --RESERVED--    008 [GN] DBG MODE ENABLE 009 [MT] PO MTR 100W POS 010 [MT] PO MTR  50W POS 011 [MT] PO MTR  20W POS 012 [MT] PO MTR  10W POS 013 [MT] PO MTR   5W POS 014 [MT] ALC MTR POS     015 [MT] VDD MTR POS     016 [MT] IDD MTR POS     017 [MT] SWR 1.5 MTR POS 018 [MT] SWR 2.0 MTR POS 019 [MT] SWR 3.0 MTR POS 020 [MT] --RESERVED--    021 [MT] --RESERVED--    022 [MT] --RESERVED--    023 [RX] RF-AGC  7       024 [RX] RF-AGC 14       025 [RX] RF-AGC 21       026 [RX] RF-AGC 28       027 [RX] RF-AGC 50       028 [RX] IF-AGC  7       029 [RX] IF-AGC 14       030 [RX] IF-AGC 21       031 [RX] IF-AGC 28       032 [RX] IF-AGC 50       033 [RX] S-MTR 0         034 [RX] S-MTR 2         035 [RX] S-MTR 5         036 [RX] S-MTR 7         037 [RX] S-MTR 9         038 [RX] S-MTR +10       039 [RX] S-MTR +20       040 [RX] S-MTR +30       041 [RX] S-MTR +40       042 [RX] S-MTR +50       043 [RX] S-MTR +60       044 [RX] --RESERVED--    045 [RX] --RESERVED--    046 [RX] FM SQL THW      047 [RX] FM SQL THN      048 [RX] FM SQL TI       049 [RX] SCOPE SDR REF   050 [TX] MF PREDR BIAS   051 [TX] MF DRIVE BIAS   052 [TX] MF FINAL BIAS   053 [TX] HF PREDR BIAS   054 [TX] HF DRIVE BIAS   055 [TX] HF FINAL BIAS   056 [TX] VHF PREDR BIAS  057 [TX] VHF DRIVE BIAS  058 [TX] VHF FINAL BIAS  059 [TX] I-ALC 1.8       060 [TX] I-ALC 3.5       061 [TX] I-ALC 7         062 [TX] I-ALC 10        063 [TX] I-ALC 14        064 [TX] I-ALC 18        065 [TX] I-ALC 21        066 [TX] I-ALC 24        067 [TX] I-ALC 28        068 [TX] I-ALC 50        069 [TX] I-ALC 70        070 [TX] 100W FALC 1.8   071 [TX] 100W MTR  1.8   072 [TX] 100W TXG  1.8   073 [TX]  50W FALC 1.8   074 [TX]  50W MTR  1.8   075 [TX]  50W TXG  1.8   076 [TX]  20W FALC 1.8   077 [TX]  20W MTR  1.8   078 [TX]  20W TXG  1.8   079 [TX]  10W FALC 1.8   080 [TX]  10W MTR  1.8   081 [TX]  10W TXG  1.8   082 [TX]   5W FALC 1.8..." /* TRUNCATED STRING LITERAL */
             + (uint)uStack_4 * 0x19;
    pcVar1 = &DAT_000017db + (uint)bStack_1 * 0x1c;
    for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar1 = *pcVar2;
      pcVar1 = pcVar1 + 1;
      pcVar2 = pcVar2 + 1;
    }
    FUN_fff9c555(uStack_4,*(undefined2 *)((uint)bStack_1 * 0x1c + 0xb3));
    uStack_4 = uStack_4 + 1;
    if (0x104 < uStack_4) {
      uStack_4 = 0;
    }
  }
  return;
}


// ===== FUN_fff9c555 @ fff9c555 (93 bytes)

void FUN_fff9c555(ushort param_1,ushort param_2)

{
  short sVar1;
  
  sVar1 = FUN_fff9cea1((&DAT_00004659)[param_1]);
  (&DAT_00001741)[param_2] = (byte)((ushort)sVar1 >> 8) & 0x3f | 0x30;
  (&DAT_00001742)[param_2] = (byte)((uint)(int)sVar1 >> 4) & 0x3f | 0x30;
  (&DAT_00001743)[param_2] = (byte)sVar1 & 0x3f | 0x30;
  return;
}


// ===== FUN_fff9c5b2 @ fff9c5b2 (38 bytes)

void FUN_fff9c5b2(undefined2 param_1)

{
  FUN_fff9c5d8(&DAT_00001456,param_1);
  DAT_0001b3cf = 0;
  DAT_0001b3ce = 1;
  FUN_fff96209();
  return;
}


// ===== FUN_fff9c5d8 @ fff9c5d8 (55 bytes)

void FUN_fff9c5d8(int param_1,short param_2)

{
  undefined2 local_a;
  undefined1 local_7;
  
  local_7 = '\0';
  for (local_a = 0; local_a < (ushort)(param_2 - 1U); local_a = local_a + 1) {
    local_7 = *(char *)((uint)local_a + param_1) + local_7;
  }
  *(char *)((uint)(ushort)(param_2 - 1U) + param_1) = local_7;
  return;
}


// ===== FUN_fff9c60f @ fff9c60f (70 bytes)

bool FUN_fff9c60f(int param_1,short param_2)

{
  ushort local_a;
  char local_8;
  
  local_8 = '\0';
  for (local_a = 0; local_a < (ushort)(param_2 - 1U); local_a = local_a + 1) {
    local_8 = *(char *)((uint)local_a + param_1) + local_8;
  }
  return *(char *)((uint)(ushort)(param_2 - 1U) + param_1) == local_8;
}


// ===== FUN_fff9c655 @ fff9c655 (18 bytes)

void FUN_fff9c655(ushort param_1,undefined4 *param_2)

{
  uint uVar1;
  
  for (uVar1 = (uint)param_1; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = 0;
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}


// ===== FUN_fff9c667 @ fff9c667 (68 bytes)

undefined1 FUN_fff9c667(undefined1 *param_1,undefined1 *param_2,ushort param_3)

{
  uint uVar1;
  ushort local_e;
  
  local_e = 0;
  while( true ) {
    if (param_3 <= local_e) {
      return 0;
    }
    if (param_2[local_e] != param_1[local_e]) break;
    local_e = local_e + 1;
  }
  for (uVar1 = (uint)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return 1;
}


// ===== FUN_fff9c6ab @ fff9c6ab (69 bytes)

void FUN_fff9c6ab(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_fffb357c(0,2);
  FUN_fffb3480(uVar1);
  return;
}


// ===== FUN_fff9c6f0 @ fff9c6f0 (151 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9c6ff) */
/* WARNING: Removing unreachable block (ram,0xfff9c72d) */

char FUN_fff9c6f0(byte param_1,byte *param_2)

{
  bool bVar1;
  byte local_a;
  byte local_1;
  
  local_a = param_1 / 100 != 0;
  local_1 = param_1;
  if ((bool)local_a) {
    *param_2 = param_1 / 100 | 0x30;
    local_1 = param_1 % 100;
  }
  if ((local_1 / 10 != 0) || ((bool)local_a)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    param_2[local_a] = local_1 / 10 | 0x30;
    local_a = local_a + 1;
    local_1 = local_1 % 10;
  }
  param_2[local_a] = local_1 | 0x30;
  return local_a + 1;
}


// ===== FUN_fff9c787 @ fff9c787 (188 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9c7bb) */
/* WARNING: Removing unreachable block (ram,0xfff9c7e9) */

char FUN_fff9c787(byte param_1,undefined1 *param_2)

{
  bool bVar1;
  byte bVar2;
  byte local_c;
  byte local_a;
  
  local_a = (char)param_1 < '\0';
  local_c = param_1;
  if ((bool)local_a) {
    *param_2 = 0x2d;
    local_c = ~param_1 + 1;
  }
  bVar2 = local_c / 100;
  if (bVar2 != 0) {
    param_2[local_a] = bVar2 | 0x30;
    local_a = local_a + 1;
    local_c = local_c % 100;
  }
  if ((local_c / 10 != 0) || (bVar2 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    param_2[local_a] = local_c / 10 | 0x30;
    local_a = local_a + 1;
    local_c = local_c % 10;
  }
  param_2[local_a] = local_c | 0x30;
  return local_a + 1;
}


// ===== FUN_fff9c843 @ fff9c843 (281 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9c8c3) */
/* WARNING: Removing unreachable block (ram,0xfff9c852) */
/* WARNING: Removing unreachable block (ram,0xfff9c882) */
/* WARNING: Removing unreachable block (ram,0xfff9c902) */

char FUN_fff9c843(ushort param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
  bool local_b;
  byte local_a;
  ushort local_2;
  
  bVar1 = param_1 / 10000 != 0;
  local_2 = param_1;
  if (bVar1) {
    bVar2 = (byte)(param_1 / 10000);
    *param_2 = bVar2 | 0x30;
    local_2 = param_1 - (byte)(bVar2 * '\x10');
  }
  if ((local_2 / 1000 != 0) || (bVar1)) {
    local_b = true;
  }
  else {
    local_b = false;
  }
  local_a = bVar1;
  if (local_b) {
    bVar2 = (byte)(local_2 / 1000);
    param_2[bVar1] = bVar2 | 0x30;
    local_2 = local_2 - (byte)(bVar2 * -0x18);
    local_a = bVar1 + 1;
  }
  local_b = local_b || bVar1;
  if ((local_2 / 100 != 0) || (local_b)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bVar2 = (byte)(local_2 / 100);
    param_2[local_a] = bVar2 | 0x30;
    local_a = local_a + 1;
    local_b = true;
    local_2 = local_2 - (byte)(bVar2 * 'd');
  }
  if ((local_2 / 10 != 0) || (local_b)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bVar2 = (byte)(local_2 / 10);
    param_2[local_a] = bVar2 | 0x30;
    local_a = local_a + 1;
    local_2 = local_2 - (byte)(bVar2 * '\n');
  }
  param_2[local_a] = (byte)local_2 | 0x30;
  return local_a + 1;
}


// ===== FUN_fff9c95c @ fff9c95c (230 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9c9eb) */
/* WARNING: Removing unreachable block (ram,0xfff9c9e2) */
/* WARNING: Removing unreachable block (ram,0xfff9c9c4) */
/* WARNING: Removing unreachable block (ram,0xfff9c96f) */
/* WARNING: Removing unreachable block (ram,0xfff9c964) */
/* WARNING: Removing unreachable block (ram,0xfff9c985) */
/* WARNING: Removing unreachable block (ram,0xfff9c9a5) */
/* WARNING: Removing unreachable block (ram,0xfff9c9af) */
/* WARNING: Removing unreachable block (ram,0xfff9c9ff) */
/* WARNING: Removing unreachable block (ram,0xfff9ca1b) */
/* WARNING: Removing unreachable block (ram,0xfff9ca23) */

void FUN_fff9c95c(uint param_1,byte *param_2)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = (char)(param_1 / 10000000);
  *param_2 = cVar1 << 4;
  param_1 = param_1 - (byte)(cVar1 * -0x80);
  bVar2 = (byte)(param_1 / 1000000);
  *param_2 = *param_2 | bVar2;
  param_1 = param_1 - (byte)(bVar2 * '@');
  cVar1 = (char)(param_1 / 100000);
  param_2[1] = cVar1 << 4;
  param_1 = param_1 - (byte)(cVar1 * -0x60);
  bVar2 = (byte)(param_1 / 10000);
  param_2[1] = param_2[1] | bVar2;
  param_1 = param_1 - (byte)(bVar2 * '\x10');
  cVar1 = (char)(param_1 / 1000);
  param_2[2] = cVar1 << 4;
  param_1 = param_1 - (byte)(cVar1 * -0x18);
  bVar2 = (byte)(param_1 / 100);
  param_2[2] = param_2[2] | bVar2;
  param_1 = param_1 - (byte)(bVar2 * 'd');
  cVar1 = (char)(param_1 / 10);
  param_2[3] = cVar1 << 4;
  param_2[3] = param_2[3] | (char)param_1 + cVar1 * -10;
  return;
}


// ===== FUN_fff9ca42 @ fff9ca42 (297 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9cb14) */
/* WARNING: Removing unreachable block (ram,0xfff9cb0b) */
/* WARNING: Removing unreachable block (ram,0xfff9caed) */
/* WARNING: Removing unreachable block (ram,0xfff9ca98) */
/* WARNING: Removing unreachable block (ram,0xfff9ca8d) */
/* WARNING: Removing unreachable block (ram,0xfff9ca6b) */
/* WARNING: Removing unreachable block (ram,0xfff9ca4a) */
/* WARNING: Removing unreachable block (ram,0xfff9ca55) */
/* WARNING: Removing unreachable block (ram,0xfff9caae) */
/* WARNING: Removing unreachable block (ram,0xfff9cace) */
/* WARNING: Removing unreachable block (ram,0xfff9cad8) */
/* WARNING: Removing unreachable block (ram,0xfff9cb28) */
/* WARNING: Removing unreachable block (ram,0xfff9cb44) */
/* WARNING: Removing unreachable block (ram,0xfff9cb4c) */

void FUN_fff9ca42(uint param_1,byte *param_2)

{
  char cVar1;
  byte bVar2;
  
  *param_2 = (char)(param_1 / 1000000000) << 4;
  *param_2 = *param_2 | (byte)(param_1 / 100000000);
  cVar1 = (char)(param_1 / 10000000);
  param_2[1] = cVar1 << 4;
  param_1 = param_1 - (byte)(cVar1 * -0x80);
  bVar2 = (byte)(param_1 / 1000000);
  param_2[1] = param_2[1] | bVar2;
  param_1 = param_1 - (byte)(bVar2 * '@');
  cVar1 = (char)(param_1 / 100000);
  param_2[2] = cVar1 << 4;
  param_1 = param_1 - (byte)(cVar1 * -0x60);
  bVar2 = (byte)(param_1 / 10000);
  param_2[2] = param_2[2] | bVar2;
  param_1 = param_1 - (byte)(bVar2 * '\x10');
  cVar1 = (char)(param_1 / 1000);
  param_2[3] = cVar1 << 4;
  param_1 = param_1 - (byte)(cVar1 * -0x18);
  bVar2 = (byte)(param_1 / 100);
  param_2[3] = param_2[3] | bVar2;
  param_1 = param_1 - (byte)(bVar2 * 'd');
  cVar1 = (char)(param_1 / 10);
  param_2[4] = cVar1 << 4;
  param_2[4] = param_2[4] | (char)param_1 + cVar1 * -10;
  return;
}


// ===== FUN_fff9cb6b @ fff9cb6b (35 bytes)

undefined1 FUN_fff9cb6b(byte param_1)

{
  undefined1 local_3;
  
  if (param_1 < 5) {
    local_3 = (&DAT_fff804d3)[param_1];
  }
  else {
    local_3 = 1;
  }
  return local_3;
}


// ===== FUN_fff9cb8e @ fff9cb8e (22 bytes)

void FUN_fff9cb8e(void)

{
  PTR_DAT_00025d38[0x98] = 1;
  DAT_0001b3d0 = 1;
  return;
}


// ===== FUN_fff9cba4 @ fff9cba4 (153 bytes)

void FUN_fff9cba4(void)

{
  dest_code_get();
  return;
}


// ===== FUN_fff9cc3d @ fff9cc3d (15 bytes)

undefined1 FUN_fff9cc3d(void)

{
  return DAT_0001b3d6;
}


// ===== FUN_fff9cc4c @ fff9cc4c (43 bytes)

void FUN_fff9cc4c(byte param_1)

{
  bool bVar1;
  
  if ((param_1 == 0) || (99 < param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    DAT_0001b3d6 = param_1;
    return;
  }
  return;
}


// ===== FUN_fff9cc77 @ fff9cc77 (92 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9ccb0) */
/* WARNING: Removing unreachable block (ram,0xfff9ccbb) */

void FUN_fff9cc77(char param_1,uint *param_2)

{
  byte *local_c;
  
  if (param_1 == '\0') {
    local_c = (byte *)&DAT_00009d53;
  }
  else {
    local_c = (byte *)&DAT_00009dad;
  }
  *param_2 = (uint)local_c[3] |
             (uint)local_c[2] << 8 | (uint)local_c[1] << 0x10 | (uint)*local_c << 0x18;
  return;
}


// ===== FUN_fff9ccd3 @ fff9ccd3 (221 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9cd32) */

undefined1 FUN_fff9ccd3(void)

{
  bool bVar1;
  undefined1 uVar2;
  byte bStack_3;
  
  uVar2 = 0;
  if (DAT_00009c5e != '\0') {
    if ((DAT_00009c5e == '\x01') && (PTR_DAT_00025d38[0x482] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      bVar1 = false;
      goto LAB_fff9cd2a;
    }
  }
  bVar1 = true;
LAB_fff9cd2a:
  if (bVar1) {
    FUN_fff9cc77();
  }
  else if (DAT_00009dbd == '\0') {
    FUN_fff9cc77(1);
  }
  else {
    FUN_fff9cc77(0);
  }
  for (bStack_3 = 1; bStack_3 < 0x14; bStack_3 = bStack_3 + 1) {
    if (DAT_00020824 != ((&DAT_00020824)[bStack_3] & 0xff)) {
      uVar2 = 1;
    }
  }
  DAT_0001b3d7 = DAT_0001b3d7 + '\x01';
  if (DAT_0001b3d7 == '\x14') {
    DAT_0001b3d7 = '\0';
  }
  return uVar2;
}


// ===== FUN_fff9cdb0 @ fff9cdb0 (85 bytes)

void FUN_fff9cdb0(char param_1)

{
  bool local_a;
  byte bStack_9;
  undefined4 uStack_8;
  
  local_a = DAT_00009dbd != '\0';
  if (param_1 == '\0') {
    FUN_fff9cc77(local_a);
  }
  else {
    FUN_fff9cc77(DAT_00009dbd == '\0');
  }
  for (bStack_9 = 0; bStack_9 < 0x14; bStack_9 = bStack_9 + 1) {
    (&DAT_00020824)[bStack_9] = uStack_8;
  }
  return;
}


// ===== FUN_fff9ce05 @ fff9ce05 (156 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9ce23) */
/* WARNING: Removing unreachable block (ram,0xfff9ce56) */

void FUN_fff9ce05(int param_1,byte param_2)

{
  bool local_a;
  byte local_9;
  ushort local_8;
  
  local_a = false;
  for (local_9 = 0; local_9 < 4; local_9 = local_9 + 1) {
    local_8 = (*(byte *)((3 - (uint)local_9) + param_1) & 0xf) +
              ((byte)(&DAT_fff8056c)[(uint)local_9 + (uint)param_2 * 4] & 0xf) + (ushort)local_a;
    if (9 < local_8) {
      local_8 = local_8 + 6;
    }
    local_8 = (*(byte *)((3 - (uint)local_9) + param_1) & 0xf0) +
              ((byte)(&DAT_fff8056c)[(uint)local_9 + (uint)param_2 * 4] & 0xf0) + local_8;
    local_a = 0x9f < local_8;
    if (local_a) {
      local_8 = local_8 + 0x60;
    }
    *(undefined1 *)((3 - (uint)local_9) + param_1) = (undefined1)local_8;
  }
  return;
}


// ===== FUN_fff9cea1 @ fff9cea1 (64 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9ced3) */

undefined1 FUN_fff9cea1(byte param_1)

{
  undefined4 local_9;
  byte local_5;
  byte local_1;
  
  local_9 = 0;
  local_1 = param_1;
  for (local_5 = 0; local_5 < 8; local_5 = local_5 + 1) {
    if ((local_1 & 1) == 1) {
      FUN_fff9ce05(&local_9,local_5);
    }
    local_1 = local_1 >> 1;
  }
  return local_9._3_1_;
}


// ===== FUN_fff9cee1 @ fff9cee1 (395 bytes)

void FUN_fff9cee1(void)

{
  bool bVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uStack_c;
  int iStack_8;
  byte *local_4;
  
  if ((PTR_DAT_00025d38[0x40b] == '\0') && (PTR_DAT_00025d38[0x40c] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (PTR_DAT_00025d38[0x7a] == '!') {
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
        PTR_DAT_00025d38[0x7a] = 0x20;
        PTR_DAT_00025d38[0x47a] = 0;
      }
    }
    uVar3 = FUN_fffb35d7(1,2);
    uVar3 = FUN_fffb4f52(uVar3);
    *(undefined4 *)(PTR_DAT_00025d38 + 0x44c) = uVar3;
    uVar3 = FUN_fffb35d7(0,0);
    *(undefined4 *)(PTR_DAT_00025d38 + 0x450) = uVar3;
    uVar3 = FUN_fffb35d7(0,1);
    *(undefined4 *)(PTR_DAT_00025d38 + 0x454) = uVar3;
    if (PTR_DAT_00025d38[0x67] == '\0') {
      if (DAT_00009dbd == '\0') {
        iStack_8 = *(int *)(PTR_DAT_00025d38 + 0x450);
      }
      else {
        iStack_8 = *(int *)(PTR_DAT_00025d38 + 0x454);
      }
      uVar2 = FUN_fffb4c45();
      uStack_c = (uint)uVar2;
      if ((uVar2 & 0x8000) != 0) {
        uStack_c = -(uint)(ushort)(~uVar2 + 1);
      }
      *(uint *)(PTR_DAT_00025d38 + 0x458) = iStack_8 + uStack_c;
    }
    PTR_DAT_00025d38[0x40b] = 0;
    PTR_DAT_00025d38[0x40c] = 0;
    return;
  }
  return;
}


// ===== FUN_fff9d06c @ fff9d06c (333 bytes)

void FUN_fff9d06c(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  local_7 = 0x56;
  local_6 = 0x2a;
  local_5 = 0x2a;
  local_4 = 0x2d;
  local_3 = 0x2a;
  local_2 = 0x2a;
  local_1 = 0;
  bVar1 = false;
  FUN_fffb7080(1);
  FUN_fffb237a(0x1f,100);
  do {
    iVar2 = FUN_fffb23f3(0x1f);
  } while (iVar2 != 1);
  FUN_fffb1ab4("i DB00\r",7);
  FUN_fffb237a(0x2e,2);
  do {
    iVar2 = FUN_fffb23f3(0x2e);
  } while (iVar2 != 1);
  puVar3 = (undefined4 *)&DAT_0001b634;
  for (iVar2 = 0xaa; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xff;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  DAT_00001c5e = 0;
  FUN_fff9d957();
  do {
    if (DAT_00001c5f != '\x01') goto LAB_fff9d11b;
    iVar2 = FUN_fffa0ad6(0x72);
  } while (iVar2 != 1);
  DAT_0001b6e0 = hex2word();
  FUN_fffa037a();
  bVar1 = true;
LAB_fff9d11b:
  if (!bVar1) {
    DAT_00020b36 = 2;
    return;
  }
  word2hex(&uStack_b,DAT_0001b634);
  local_6 = uStack_b;
  local_5 = uStack_a;
  local_3 = uStack_9;
  local_2 = uStack_8;
  FUN_fff94c39();
  bVar1 = false;
  FUN_fff9d967();
  do {
    do {
      if (DAT_00001c5f != '\x01') goto LAB_fff9d1a6;
      iVar2 = FUN_fffa0ad6(0x72);
    } while (iVar2 != 1);
    DAT_0001b6e0 = hex2word();
    FUN_fffa037a();
  } while ((DAT_0001b636 & 1) == 0);
  bVar1 = true;
  DAT_0001b636 = DAT_0001b636 & 0xffef;
LAB_fff9d1a6:
  if (!bVar1) {
    DAT_00020b36 = 2;
    return;
  }
  return;
}


// ===== FUN_fff9d1b9 @ fff9d1b9 (1591 bytes)

void FUN_fff9d1b9(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = DAT_00020b6b;
  cVar2 = DAT_00020b18;
  if (DAT_00001c5e == '\x01') {
    iVar4 = FUN_fffa0ad6(0x77);
    if (iVar4 != 1) {
      return;
    }
    FUN_fffa037a();
  }
  if (DAT_00001c5f == '\x01') {
    iVar4 = FUN_fffa0ad6(0x72);
    if (iVar4 != 1) {
      return;
    }
    DAT_0001b6e0 = hex2word();
    FUN_fffa037a();
  }
  if (DAT_00001c63 == '\x01') {
    FUN_fffa0c79();
  }
  if ((cVar2 == '\x03') || (cVar2 == '\b')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar4 = FUN_fffb23f3(0xb), iVar4 == 1)) {
    if (DAT_0001b3da == '\x02') {
      FUN_fff9d987();
      DAT_0001b3da = DAT_0001b3da + '\x01';
      return;
    }
    if (DAT_0001b3da == '\x01') {
      FUN_fff9d977();
      DAT_0001b3da = DAT_0001b3da + '\x01';
      return;
    }
    if (DAT_0001b3da != '\0') {
      FUN_fff9d997();
      DAT_0001b3da = 0;
      FUN_fffb237a(0xb,0x14);
      return;
    }
    FUN_fff9d967();
    DAT_0001b3da = DAT_0001b3da + '\x01';
    return;
  }
  if ((DAT_00020b49 == '\x01') && (DAT_0001b3d9 != cVar3)) {
    if ((cVar3 == '\x01') && (iVar4 = FUN_fffb721a(), iVar4 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    if ((cVar3 == '\0') && (iVar4 = FUN_fffb6fac(), iVar4 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    DAT_0001b3d9 = cVar3;
  }
  FUN_fff9da09(cVar3);
  if ((((((((DAT_00001c5e == '\0') && (FUN_fff9da3c(cVar3), DAT_00001c5e == '\0')) &&
          (FUN_fff9da6f(cVar3), DAT_00001c5e == '\0')) &&
         ((FUN_fff9dad1(cVar3), DAT_00001c5e == '\0' && (FUN_fff9db04(cVar3), DAT_00001c5e == '\0'))
         )) && (((FUN_fff9dbf7(), DAT_00001c5e == '\0' &&
                 ((FUN_fff9e750(cVar3), DAT_00001c5e == '\0' &&
                  (FUN_fff9e7c4(cVar3), DAT_00001c5e == '\0')))) &&
                (FUN_fff9e871(cVar3), DAT_00001c5e == '\0')))) &&
       ((((((FUN_fff9e9a4(), DAT_00001c5e == '\0' && (FUN_fff9e9fa(), DAT_00001c5e == '\0')) &&
           (FUN_fff9ea39(cVar3), DAT_00001c5e == '\0')) &&
          (((FUN_fff9f57b(), DAT_00001c5e == '\0' && (FUN_fff9f5c6(cVar3), DAT_00001c5e == '\0')) &&
           ((FUN_fff9f638(), DAT_00001c5e == '\0' &&
            ((FUN_fff9fcd0(cVar3), DAT_00001c5e == '\0' &&
             (FUN_fff9fd51(cVar3), DAT_00001c5e == '\0')))))))) &&
         ((FUN_fff9fe2a(cVar3), DAT_00001c5e == '\0' &&
          (((FUN_fff9feaf(cVar3), DAT_00001c5e == '\0' &&
            (FUN_fff9ff30(cVar3), DAT_00001c5e == '\0')) &&
           (FUN_fff9ffb1(cVar3), DAT_00001c5e == '\0')))))) &&
        ((((FUN_fff9fdd2(), DAT_00001c5e == '\0' && (FUN_fff9dc8a(), DAT_00001c5e == '\0')) &&
          ((FUN_fff9dce4(), DAT_00001c5e == '\0' &&
           ((FUN_fff9dd6a(0), DAT_00001c5e == '\0' && (FUN_fff9dd6a(1), DAT_00001c5e == '\0'))))))
         && (FUN_fff9dd6a(2), DAT_00001c5e == '\0')))))) &&
      (((((((FUN_fff9dee6(0), DAT_00001c5e == '\0' && (FUN_fff9dee6(1), DAT_00001c5e == '\0')) &&
           (FUN_fff9dee6(2), DAT_00001c5e == '\0')) &&
          ((FUN_fff9dfd5(0), DAT_00001c5e == '\0' && (FUN_fff9dfd5(1), DAT_00001c5e == '\0')))) &&
         ((FUN_fff9dfd5(2), DAT_00001c5e == '\0' &&
          ((FUN_fff9e0ad(), DAT_00001c5e == '\0' && (FUN_fff9e12b(), DAT_00001c5e == '\0')))))) &&
        (FUN_fff9e21f(), DAT_00001c5e == '\0')) &&
       ((((FUN_fff9e26b(), DAT_00001c5e == '\0' && (FUN_fff9e330(), DAT_00001c5e == '\0')) &&
         (FUN_fff9e3f5(), DAT_00001c5e == '\0')) &&
        (((FUN_fff9e480(), DAT_00001c5e == '\0' && (FUN_fff9e51c(), DAT_00001c5e == '\0')) &&
         ((FUN_fff9e644(cVar3), DAT_00001c5e == '\0' && (FUN_fff9e6b9(), DAT_00001c5e == '\0')))))))
       ))) && ((cVar3 != '\0' ||
               ((((FUN_fff9d9a7(), DAT_00001c5e == '\0' && (FUN_fff9eae7(), DAT_00001c5e == '\0'))
                 && (((FUN_fff9ed0e(), DAT_00001c5e == '\0' &&
                      (((FUN_fff9ef34(0), DAT_00001c5e == '\0' &&
                        (FUN_fff9ef34(1), DAT_00001c5e == '\0')) &&
                       (FUN_fff9ef34(2), DAT_00001c5e == '\0')))) &&
                     ((((FUN_fff9f0b1(0), DAT_00001c5e == '\0' &&
                        (FUN_fff9f0b1(1), DAT_00001c5e == '\0')) &&
                       (FUN_fff9f0b1(2), DAT_00001c5e == '\0')) &&
                      ((FUN_fff9f291(0), DAT_00001c5e == '\0' &&
                       (FUN_fff9f291(1), DAT_00001c5e == '\0')))))))) &&
                ((FUN_fff9f291(2), DAT_00001c5e == '\0' &&
                 (((((FUN_fff9f430(), DAT_00001c5e == '\0' && (FUN_fff9f4c8(), DAT_00001c5e == '\0')
                     ) && (FUN_fff9f54b(), DAT_00001c5e == '\0')) &&
                   ((FUN_fff9f681(), DAT_00001c5e == '\0' && (FUN_fff9fb6e(), DAT_00001c5e == '\0'))
                   )) && (FUN_fff9fc2a(), DAT_00001c5e == '\0')))))))))) {
    if (DAT_0001b3d8 == '\0') {
      FUN_fff9daa2();
      if (DAT_00001c5e != '\0') {
        return;
      }
      FUN_fff9db37();
      if (DAT_00001c5e != '\0') {
        return;
      }
      FUN_fff9db66();
      if (DAT_00001c5e != '\0') {
        return;
      }
      FUN_fff9db97();
      if (DAT_00001c5e != '\0') {
        return;
      }
      FUN_fff9dbc6();
      if (DAT_00001c5e != '\0') {
        return;
      }
      FUN_fff9e5b4();
      if (DAT_00001c5e != '\0') {
        return;
      }
      FUN_fff9e5e4();
      if (DAT_00001c5e != '\0') {
        return;
      }
      FUN_fff9e614();
      if (DAT_00001c5e != '\0') {
        return;
      }
      FUN_fff9f400();
      if (DAT_00001c5e != '\0') {
        return;
      }
      FUN_fff9fca0();
      if (DAT_00001c5e != '\0') {
        return;
      }
      DAT_0001b3d8 = '\x01';
    }
    if ((cVar2 == '\x01') || (cVar2 == '\a')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00020b1a = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fff9d7f0 @ fff9d7f0 (16 bytes)

undefined2 FUN_fff9d7f0(void)

{
  return DAT_0001b636;
}


// ===== FUN_fff9d800 @ fff9d800 (56 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9d817) */

byte FUN_fff9d800(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_fffb3196(0);
  if (((iVar2 == 7) || (bVar1 = DAT_00001c60, iVar2 == 0xb)) &&
     (bVar1 = DAT_00001c60 << 1, 0xff < (uint)DAT_00001c60 * 2)) {
    bVar1 = 0xff;
  }
  return bVar1;
}


// ===== FUN_fff9d838 @ fff9d838 (15 bytes)

undefined1 FUN_fff9d838(void)

{
  return DAT_00001c61;
}


// ===== FUN_fff9d857 @ fff9d857 (15 bytes)

undefined2 FUN_fff9d857(void)

{
  return DAT_0001b6e2;
}


// ===== FUN_fff9d866 @ fff9d866 (16 bytes)

undefined2 FUN_fff9d866(void)

{
  return DAT_0001b63a;
}


// ===== FUN_fff9d895 @ fff9d895 (15 bytes)

undefined2 FUN_fff9d895(void)

{
  return DAT_0001b6e4;
}


// ===== dev4_reg_access @ fff9d8a4 (169 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9d94a) */
/* Same register protocol over SCI4 (device unknown) */

undefined1 dev4_reg_access(undefined2 param_1,undefined2 *param_2,char param_3)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 local_15;
  int iStack_14;
  
  while( true ) {
    if ((DAT_00001c5e == '\x01') || (DAT_00001c5f == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) break;
    FUN_fff9d1b9();
  }
  DAT_0001b6de = param_1;
  if (param_3 == '\0') {
    FUN_fffa0b4c(0x72);
    do {
      if (DAT_00001c5f != '\x01') {
        return 0;
      }
      iVar3 = FUN_fffa0ad6(0x72);
    } while (iVar3 != 1);
    uVar2 = hex2word(iStack_14 + 1);
    *param_2 = uVar2;
    local_15 = 1;
  }
  else {
    DAT_0001b6e0 = *param_2;
    FUN_fffa0b4c(0x77);
    do {
      local_15 = FUN_fffa0ad6(0x77);
    } while (DAT_00001c5e != '\0');
  }
  return local_15;
}


// ===== FUN_fff9d94d @ fff9d94d (10 bytes)

void FUN_fff9d94d(void)

{
  DAT_00001c63 = 1;
  return;
}


// ===== FUN_fff9d957 @ fff9d957 (16 bytes)

void FUN_fff9d957(void)

{
  DAT_0001b6de = 0;
  FUN_fffa0b4c(0x72);
  return;
}


// ===== FUN_fff9d967 @ fff9d967 (16 bytes)

void FUN_fff9d967(void)

{
  DAT_0001b6de = 1;
  FUN_fffa0b4c(0x72);
  return;
}


// ===== FUN_fff9d977 @ fff9d977 (16 bytes)

void FUN_fff9d977(void)

{
  DAT_0001b6de = 2;
  FUN_fffa0b4c(0x72);
  return;
}


// ===== FUN_fff9d987 @ fff9d987 (16 bytes)

void FUN_fff9d987(void)

{
  DAT_0001b6de = 3;
  FUN_fffa0b4c(0x72);
  return;
}


// ===== FUN_fff9d997 @ fff9d997 (16 bytes)

void FUN_fff9d997(void)

{
  DAT_0001b6de = 4;
  FUN_fffa0b4c(0x72);
  return;
}


// ===== FUN_fff9d9a7 @ fff9d9a7 (98 bytes)

void FUN_fff9d9a7(void)

{
  undefined1 uVar1;
  short sStack_2;
  
  uVar1 = FUN_fffb3196(0);
  switch(uVar1) {
  case 0:
  case 8:
  case 0xc:
    sStack_2 = 3;
    break;
  case 1:
  case 9:
  case 0xd:
  case 0xe:
    sStack_2 = 2;
    break;
  case 2:
    sStack_2 = 1;
    break;
  default:
    sStack_2 = 0;
    break;
  case 4:
  case 5:
    sStack_2 = 8;
    break;
  case 6:
  case 7:
  case 10:
  case 0xb:
    sStack_2 = 9;
  }
  if (DAT_0001b63e == sStack_2) {
    return;
  }
  DAT_0001b6de = 6;
  DAT_0001b6e0 = sStack_2;
  FUN_fffa0b4c(0x77);
  return;
}


// ===== FUN_fff9da09 @ fff9da09 (51 bytes)

void FUN_fff9da09(void)

{
  short sVar1;
  
  sVar1 = FUN_fffa0e3a(8);
  if (DAT_0001b640 == sVar1) {
    return;
  }
  DAT_0001b6de = 8;
  DAT_0001b6e0 = sVar1;
  FUN_fffa0b4c(0x77);
  return;
}


// ===== FUN_fff9da3c @ fff9da3c (51 bytes)

void FUN_fff9da3c(void)

{
  short sVar1;
  
  sVar1 = FUN_fffa0e3a(9);
  if (DAT_0001b642 == sVar1) {
    return;
  }
  DAT_0001b6de = 9;
  DAT_0001b6e0 = sVar1;
  FUN_fffa0b4c(0x77);
  return;
}


// ===== FUN_fff9da6f @ fff9da6f (51 bytes)

void FUN_fff9da6f(void)

{
  short sVar1;
  
  sVar1 = FUN_fffa0e3a(10);
  if (DAT_0001b644 == sVar1) {
    return;
  }
  DAT_0001b6de = 10;
  DAT_0001b6e0 = sVar1;
  FUN_fffa0b4c(0x77);
  return;
}


// ===== FUN_fff9daa2 @ fff9daa2 (47 bytes)

void FUN_fff9daa2(void)

{
  if (DAT_0001b646 == 0) {
    return;
  }
  DAT_0001b6de = 0xc;
  DAT_0001b6e0 = 0;
  FUN_fffa0b4c(0x77);
  return;
}


// ===== FUN_fff9dad1 @ fff9dad1 (51 bytes)

void FUN_fff9dad1(void)

{
  short sVar1;
  
  sVar1 = FUN_fffa0e3a(0xd);
  if (DAT_0001b648 == sVar1) {
    return;
  }
  DAT_0001b6de = 0xd;
  DAT_0001b6e0 = sVar1;
  FUN_fffa0b4c(0x77);
  return;
}


// ===== FUN_fff9db04 @ fff9db04 (51 bytes)

void FUN_fff9db04(void)

{
  short sVar1;
  
  sVar1 = FUN_fffa0e3a(0xe);
  if (DAT_0001b64a == sVar1) {
    return;
  }
  DAT_0001b6de = 0xe;
  DAT_0001b6e0 = sVar1;
  FUN_fffa0b4c(0x77);
  return;
}

