// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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


// ===== displink_tx_start @ fff9c5b2 (38 bytes)

/* put sum, mark outstanding, send */

void displink_tx_start(ushort param_1)

{
  displink_put_sum(0x1456,param_1);
  DAT_0001b3cf = 0;
  DAT_0001b3ce = 1;
  displink_tx_resend();
  return;
}


// ===== displink_put_sum @ fff9c5d8 (55 bytes)

/* 8-bit sum of bytes 0..len-2 into byte len-1 */

void displink_put_sum(int param_1,short param_2)

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


// ===== displink_check_sum @ fff9c60f (70 bytes)

/* verify 8-bit sum */

bool displink_check_sum(int param_1,short param_2)

{
  ushort local_a;
  char local_8;
  
  local_8 = '\0';
  for (local_a = 0; local_a < (ushort)(param_2 - 1U); local_a = local_a + 1) {
    local_8 = *(char *)((uint)local_a + param_1) + local_8;
  }
  return *(char *)((uint)(ushort)(param_2 - 1U) + param_1) == local_8;
}


// ===== mem_zero @ fff9c655 (18 bytes)

/* mem_zero(n, ptr) */

void mem_zero(ushort param_1,int param_2)

{
  uint uVar1;
  
  for (uVar1 = (uint)param_1; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)param_2 = 0;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== displink_copy_if_changed @ fff9c667 (68 bytes)

/* copy staging -> 0x1456 and return 1 only if different */

byte displink_copy_if_changed(int param_1,int param_2,ushort param_3)

{
  uint uVar1;
  ushort local_e;
  
  local_e = 0;
  while( true ) {
    if (param_3 <= local_e) {
      return 0;
    }
    if (*(char *)((uint)local_e + param_2) != *(char *)((uint)local_e + param_1)) break;
    local_e = local_e + 1;
  }
  for (uVar1 = (uint)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)param_1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return 1;
}


// ===== FUN_fff9c6ab @ fff9c6ab (69 bytes)

uint FUN_fff9c6ab(void)

{
  byte bVar1;
  uint freq;
  undefined1 *puStack_10;
  
  freq = vfo_freq(0,2);
  bVar1 = freq_range_index(freq);
  if (DAT_00020b6b == '\0') {
    puStack_10 = &DAT_00009bca;
  }
  else {
    puStack_10 = &DAT_00009bd8;
  }
  return (uint)(puStack_10 + bVar1);
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
  bool local_b;
  byte local_a;
  ushort local_2;
  
  bVar1 = param_1 / 10000 != 0;
  local_2 = param_1;
  if (bVar1) {
    *param_2 = (byte)(param_1 / 10000) | 0x30;
    local_2 = param_1 % 10000;
  }
  if ((local_2 / 1000 != 0) || (bVar1)) {
    local_b = true;
  }
  else {
    local_b = false;
  }
  local_a = bVar1;
  if (local_b) {
    param_2[bVar1] = (byte)(local_2 / 1000) | 0x30;
    local_2 = local_2 % 1000;
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
    param_2[local_a] = (byte)(local_2 / 100) | 0x30;
    local_a = local_a + 1;
    local_b = true;
    local_2 = local_2 % 100;
  }
  if ((local_2 / 10 != 0) || (local_b)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    param_2[local_a] = (byte)(local_2 / 10) | 0x30;
    local_a = local_a + 1;
    local_2 = local_2 % 10;
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
  uint uVar2;
  
  *param_2 = (char)(param_1 / 10000000) << 4;
  param_1 = param_1 + (param_1 / 10000000 & 0xff) * -10000000;
  uVar2 = param_1 / 1000000;
  *param_2 = *param_2 | (byte)uVar2;
  param_1 = param_1 + (uVar2 & 0xff) * -1000000;
  uVar2 = param_1 / 100000;
  param_2[1] = (char)uVar2 << 4;
  param_1 = param_1 + (uVar2 & 0xff) * -100000;
  uVar2 = param_1 / 10000;
  param_2[1] = param_2[1] | (byte)uVar2;
  param_1 = param_1 + (uVar2 & 0xff) * -10000;
  uVar2 = param_1 / 1000;
  param_2[2] = (char)uVar2 << 4;
  param_1 = param_1 + (uVar2 & 0xff) * -1000;
  uVar2 = param_1 / 100;
  param_2[2] = param_2[2] | (byte)uVar2;
  param_1 = param_1 + (uVar2 & 0xff) * -100;
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
  uint uVar2;
  
  *param_2 = (char)(param_1 / 1000000000) << 4;
  *param_2 = *param_2 | (byte)((param_1 % 1000000000) / 100000000);
  uVar2 = (param_1 % 1000000000) % 100000000;
  param_2[1] = (char)(uVar2 / 10000000) << 4;
  uVar2 = uVar2 % 10000000;
  param_2[1] = param_2[1] | (byte)(uVar2 / 1000000);
  uVar2 = uVar2 % 1000000;
  param_2[2] = (char)(uVar2 / 100000) << 4;
  uVar2 = uVar2 % 100000;
  param_2[2] = param_2[2] | (byte)(uVar2 / 10000);
  uVar2 = uVar2 % 10000;
  param_2[3] = (char)(uVar2 / 1000) << 4;
  uVar2 = uVar2 % 1000;
  param_2[3] = param_2[3] | (byte)(uVar2 / 100);
  uVar2 = uVar2 % 100;
  cVar1 = (char)(uVar2 / 10);
  param_2[4] = cVar1 << 4;
  param_2[4] = param_2[4] | (char)uVar2 + cVar1 * -10;
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


// ===== power_on_request @ fff9cb8e (22 bytes)

/* PS1: 0x20B9C=1, 0x1B3D0=1 (DISPLAY then confirms power-on) */

void power_on_request(void)

{
  PTR_DAT_00025d38[0x98] = 1;
  DAT_0001b3d0 = 1;
  return;
}


// ===== FUN_fff9cba4 @ fff9cba4 (153 bytes)

uint FUN_fff9cba4(uint param_1,byte param_2)

{
  bool bVar1;
  ushort uVar2;
  uint local_4;
  
  uVar2 = dest_code_get();
  if (uVar2 == 0xd950) {
LAB_fff9cc15:
    if ((param_2 < 0x75) || (0x7b < param_2)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return param_1;
    }
    return param_1 + 0x5dc;
  }
  if (uVar2 != 0x50e2) {
    if (uVar2 == 0xa4c5) goto LAB_fff9cc15;
    if (uVar2 != 0x315b) {
      return param_1;
    }
  }
  if ((param_2 < 0x75) || (0x79 < param_2)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if ((param_2 < 0x7f) || (0x83 < param_2)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      bVar1 = false;
      goto LAB_fff9cc05;
    }
  }
  bVar1 = true;
LAB_fff9cc05:
  local_4 = param_1;
  if (bVar1) {
    local_4 = param_1 + 0x5dc;
  }
  return local_4;
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
  uint *puVar3;
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
  puVar3 = (uint *)(&DAT_00020824 + DAT_0001b3d7);
  if (bVar1) {
    FUN_fff9cc77(DAT_00009dbd != '\0',puVar3);
  }
  else if (DAT_00009dbd != '\0') {
    FUN_fff9cc77('\0',puVar3);
  }
  else {
    FUN_fff9cc77('\x01',puVar3);
  }
  for (bStack_3 = 1; bStack_3 < 0x14; bStack_3 = bStack_3 + 1) {
    if (DAT_00020824 != (&DAT_00020824)[bStack_3]) {
      uVar2 = 1;
    }
  }
  DAT_0001b3d7 = DAT_0001b3d7 + 1;
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
  uint uStack_8;
  char local_1;
  
  local_a = DAT_00009dbd != '\0';
  local_1 = param_1;
  if (param_1 == '\0') {
    FUN_fff9cc77(local_a,&uStack_8);
  }
  else {
    FUN_fff9cc77(DAT_00009dbd == '\0',&uStack_8);
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
  undefined1 local_a;
  undefined1 local_9;
  undefined2 local_8;
  
  local_a = false;
  for (local_9 = 0; local_9 < 4; local_9 = local_9 + 1) {
    local_8 = (*(byte *)((3 - (uint)local_9) + param_1) & 0xf) +
              (*(byte *)((uint)local_9 + (uint)param_2 * 4 + -0x7fa94) & 0xf) + (ushort)local_a;
    if (9 < local_8) {
      local_8 = local_8 + 6;
    }
    local_8 = (*(byte *)((3 - (uint)local_9) + param_1) & 0xf0) +
              (*(byte *)((uint)local_9 + (uint)param_2 * 4 + -0x7fa94) & 0xf0) + local_8;
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


// ===== freq_cache_update @ fff9cee1 (395 bytes)

/* On 0x20F0F/0x20F10: recompute 0x20F50 TX, 0x20F54 A, 0x20F58 B, 0x20F5C dial */

void freq_cache_update(void)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
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
    uVar3 = vfo_freq_clar(1,2);
    uVar3 = tx_freq_repeater_shift(uVar3);
    *(uint *)(PTR_DAT_00025d38 + 0x44c) = uVar3;
    uVar3 = vfo_freq_clar(0,0);
    *(uint *)(PTR_DAT_00025d38 + 0x450) = uVar3;
    uVar3 = vfo_freq_clar(0,1);
    *(uint *)(PTR_DAT_00025d38 + 0x454) = uVar3;
    if (PTR_DAT_00025d38[0x67] == '\0') {
      if (DAT_00009dbd == '\0') {
        iStack_8 = *(int *)(PTR_DAT_00025d38 + 0x450);
      }
      else {
        iStack_8 = *(int *)(PTR_DAT_00025d38 + 0x454);
      }
      uVar2 = vfo_display_offset();
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


// ===== dsp_link_init @ fff9d06c (333 bytes)

/* Boot: P71=1, 100 ms, send "i DB00\r", 2 ms, shadows=0xFFFF, read reg0 (version -> 0x1444) and
   reg1 (bit0 ready); failure -> 0x20B36=2 */

void dsp_link_init(void)

{
  bool bVar1;
  byte bVar2;
  undefined2 *puVar3;
  int iVar4;
  int iStack_10;
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
  dsp_reset_set(1);
  swtimer_start(0x1f,100);
  do {
    bVar2 = swtimer_expired(0x1f);
  } while (bVar2 != 1);
  sci4_send(0xfff8f3cf,7);
  swtimer_start(0x2e,2);
  do {
    bVar2 = swtimer_expired(0x2e);
  } while (bVar2 != 1);
  puVar3 = &DAT_0001b634;
  for (iVar4 = 0xaa; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar3 = 0xff;
    puVar3 = (undefined2 *)((int)puVar3 + 1);
  }
  DAT_00001c5e = 0;
  dsp_read_version();
  do {
    if (DAT_00001c5f != '\x01') goto LAB_fff9d11b;
    bVar2 = dsp_check_reply('r',&iStack_10);
  } while (bVar2 != 1);
  DAT_0001b6e0 = hex2word((char *)(iStack_10 + 1));
  dsp_shadow_store();
  bVar1 = true;
LAB_fff9d11b:
  if (!bVar1) {
    DAT_00020b36 = 2;
    return;
  }
  word2hex((int)&uStack_b,DAT_0001b634);
  local_6 = uStack_b;
  local_5 = uStack_a;
  local_3 = uStack_9;
  local_2 = uStack_8;
  ver_dsp_set(&local_7);
  bVar1 = false;
  dsp_read_status1();
  do {
    do {
      if (DAT_00001c5f != '\x01') goto LAB_fff9d1a6;
      bVar2 = dsp_check_reply('r',&iStack_10);
    } while (bVar2 != 1);
    DAT_0001b6e0 = hex2word((char *)(iStack_10 + 1));
    dsp_shadow_store();
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


// ===== dsp_link_poll @ fff9d1b9 (1591 bytes)

/* main_loop task: finish pending r/w, DSP-update bridge, 20 ms status poll (regs 1-4), then setter
   chain (max one frame per pass) */

void dsp_link_poll(void)

{
  bool bVar1;
  byte bVar2;
  int iStack_8;
  char local_2;
  byte local_1;
  
  local_1 = DAT_00020b6b;
  local_2 = DAT_00020b18;
  if (DAT_00001c5e == '\x01') {
    bVar2 = dsp_check_reply('w',&iStack_8);
    if (bVar2 != 1) {
      return;
    }
    dsp_shadow_store();
  }
  if (DAT_00001c5f == '\x01') {
    bVar2 = dsp_check_reply('r',&iStack_8);
    if (bVar2 != 1) {
      return;
    }
    DAT_0001b6e0 = hex2word((char *)(iStack_8 + 1));
    dsp_shadow_store();
  }
  if (DAT_00001c63 == '\x01') {
    dsp_isp_bridge();
  }
  if ((local_2 == '\x03') || (local_2 == '\b')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar2 = swtimer_expired(0xb), bVar2 == 1)) {
    if (DAT_0001b3da == '\x02') {
      dsp_read_status3();
      DAT_0001b3da = DAT_0001b3da + '\x01';
      return;
    }
    if (DAT_0001b3da == '\x01') {
      dsp_read_status2();
      DAT_0001b3da = DAT_0001b3da + '\x01';
      return;
    }
    if (DAT_0001b3da != '\0') {
      dsp_read_status4();
      DAT_0001b3da = 0;
      swtimer_start(0xb,0x14);
      return;
    }
    dsp_read_status1();
    DAT_0001b3da = DAT_0001b3da + '\x01';
    return;
  }
  if ((DAT_00020b49 == '\x01') && (DAT_0001b3d9 != local_1)) {
    if ((local_1 == 1) && (bVar2 = rx_line_get(), bVar2 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    if ((local_1 == 0) && (bVar2 = tx_line_get(), bVar2 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    DAT_0001b3d9 = local_1;
  }
  dsp_set_r08(local_1);
  if ((((((((DAT_00001c5e == '\0') && (dsp_set_r09(local_1), DAT_00001c5e == '\0')) &&
          (dsp_set_r0a(local_1), DAT_00001c5e == '\0')) &&
         ((dsp_set_r0d(local_1), DAT_00001c5e == '\0' &&
          (dsp_set_r0e(local_1), DAT_00001c5e == '\0')))) &&
        (((dsp_set_tx_gain(), DAT_00001c5e == '\0' &&
          ((dsp_set_dnr_r40(local_1), DAT_00001c5e == '\0' &&
           (dsp_set_dnf(local_1), DAT_00001c5e == '\0')))) &&
         (dsp_set_contour(local_1), DAT_00001c5e == '\0')))) &&
       ((((((dsp_set_contour_level(), DAT_00001c5e == '\0' &&
            (dsp_set_contour_width(), DAT_00001c5e == '\0')) &&
           (dsp_set_apf(local_1), DAT_00001c5e == '\0')) &&
          (((dsp_set_affft_att(), DAT_00001c5e == '\0' &&
            (dsp_set_osc(local_1), DAT_00001c5e == '\0')) &&
           ((dsp_set_cw_pitch(), DAT_00001c5e == '\0' &&
            ((dsp_set_dnr_400b(local_1), DAT_00001c5e == '\0' &&
             (dsp_set_dnr_400d(local_1), DAT_00001c5e == '\0')))))))) &&
         ((dsp_set_dnr_4022(local_1), DAT_00001c5e == '\0' &&
          (((dsp_set_dnr_4023(local_1), DAT_00001c5e == '\0' &&
            (dsp_set_dnr_4025(local_1), DAT_00001c5e == '\0')) &&
           (dsp_set_dnr_4026(local_1), DAT_00001c5e == '\0')))))) &&
        ((((dsp_set_aess(), DAT_00001c5e == '\0' && (dsp_set_vox_gain(), DAT_00001c5e == '\0')) &&
          ((dsp_set_antivox(), DAT_00001c5e == '\0' &&
           ((dsp_set_peq_freq('\0'), DAT_00001c5e == '\0' &&
            (dsp_set_peq_freq('\x01'), DAT_00001c5e == '\0')))))) &&
         (dsp_set_peq_freq('\x02'), DAT_00001c5e == '\0')))))) &&
      (((((((dsp_set_peq_level('\0'), DAT_00001c5e == '\0' &&
            (dsp_set_peq_level('\x01'), DAT_00001c5e == '\0')) &&
           (dsp_set_peq_level('\x02'), DAT_00001c5e == '\0')) &&
          ((dsp_set_peq_bw('\0'), DAT_00001c5e == '\0' &&
           (dsp_set_peq_bw('\x01'), DAT_00001c5e == '\0')))) &&
         ((dsp_set_peq_bw('\x02'), DAT_00001c5e == '\0' &&
          ((dsp_set_proc(), DAT_00001c5e == '\0' && (dsp_set_tx_bpf(), DAT_00001c5e == '\0')))))) &&
        (dsp_set_r30(), DAT_00001c5e == '\0')) &&
       ((((dsp_set_r31(), DAT_00001c5e == '\0' && (dsp_set_r32(), DAT_00001c5e == '\0')) &&
         (dsp_set_amc_release(), DAT_00001c5e == '\0')) &&
        (((dsp_set_amc_level(), DAT_00001c5e == '\0' && (dsp_set_ctcss_enc(), DAT_00001c5e == '\0'))
         && ((dsp_set_fm_flag(local_1), DAT_00001c5e == '\0' &&
             (dsp_set_r3b(), DAT_00001c5e == '\0')))))))))) &&
     ((local_1 != 0 ||
      ((((dsp_set_demod(), DAT_00001c5e == '\0' && (dsp_set_hcut(), DAT_00001c5e == '\0')) &&
        (((dsp_set_lcut(), DAT_00001c5e == '\0' &&
          (((dsp_set_tone_freq('\0'), DAT_00001c5e == '\0' &&
            (dsp_set_tone_freq('\x01'), DAT_00001c5e == '\0')) &&
           (dsp_set_tone_freq('\x02'), DAT_00001c5e == '\0')))) &&
         ((((dsp_set_tone_gain('\0'), DAT_00001c5e == '\0' &&
            (dsp_set_tone_gain('\x01'), DAT_00001c5e == '\0')) &&
           (dsp_set_tone_gain('\x02'), DAT_00001c5e == '\0')) &&
          ((dsp_set_tone_type('\0'), DAT_00001c5e == '\0' &&
           (dsp_set_tone_type('\x01'), DAT_00001c5e == '\0')))))))) &&
       ((dsp_set_tone_type('\x02'), DAT_00001c5e == '\0' &&
        (((((dsp_set_am_notch(), DAT_00001c5e == '\0' && (dsp_set_ctcss_dec(), DAT_00001c5e == '\0')
            ) && (dsp_set_r56(), DAT_00001c5e == '\0')) &&
          ((dsp_set_agc(), DAT_00001c5e == '\0' &&
           (dsp_set_freq_range_param(), DAT_00001c5e == '\0')))) &&
         (dsp_set_rf_gain(), DAT_00001c5e == '\0')))))))))) {
    if (DAT_0001b3d8 == '\0') {
      dsp_set_r0c();
      if (DAT_00001c5e != '\0') {
        return;
      }
      dsp_set_r0f();
      if (DAT_00001c5e != '\0') {
        return;
      }
      dsp_set_r11();
      if (DAT_00001c5e != '\0') {
        return;
      }
      dsp_set_r12();
      if (DAT_00001c5e != '\0') {
        return;
      }
      dsp_set_r13();
      if (DAT_00001c5e != '\0') {
        return;
      }
      dsp_set_r36();
      if (DAT_00001c5e != '\0') {
        return;
      }
      dsp_set_r37();
      if (DAT_00001c5e != '\0') {
        return;
      }
      dsp_set_r38();
      if (DAT_00001c5e != '\0') {
        return;
      }
      dsp_set_r51();
      if (DAT_00001c5e != '\0') {
        return;
      }
      dsp_set_r68();
      if (DAT_00001c5e != '\0') {
        return;
      }
      DAT_0001b3d8 = '\x01';
    }
    if ((local_2 == '\x01') || (local_2 == '\a')) {
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


// ===== dsp_status1_raw @ fff9d7f0 (16 bytes)

/* Returns shadow of reg 1 (0x1B636) */

ushort dsp_status1_raw(void)

{
  return DAT_0001b636;
}


// ===== dsp_fm_noise @ fff9d800 (56 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9d817) */
/* Returns 0x1C60 (doubled in modes 7/11, FM-N) */

byte dsp_fm_noise(void)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = vfo_mode(0);
  if (((bVar1 == 7) || (bVar2 = DAT_00001c60, bVar1 == 0xb)) &&
     (bVar2 = DAT_00001c60 << 1, 0xff < (uint)DAT_00001c60 * 2)) {
    bVar2 = 0xff;
  }
  return bVar2;
}


// ===== dsp_tone_detect @ fff9d838 (15 bytes)

/* Returns 0x1C61 */

byte dsp_tone_detect(void)

{
  return DAT_00001c61;
}


// ===== FUN_fff9d847 @ fff9d847 (16 bytes)

undefined2 FUN_fff9d847(void)

{
  return DAT_0001b638;
}


// ===== dsp_comp_level @ fff9d857 (15 bytes)

/* Returns 0x1B6E2 */

ushort dsp_comp_level(void)

{
  return DAT_0001b6e2;
}


// ===== dsp_signal_level @ fff9d866 (16 bytes)

/* Returns shadow of reg 3 (0x1B63A) */

ushort dsp_signal_level(void)

{
  return DAT_0001b63a;
}


// ===== FUN_fff9d876 @ fff9d876 (15 bytes)

undefined1 FUN_fff9d876(void)

{
  return DAT_00001c62;
}


// ===== FUN_fff9d885 @ fff9d885 (16 bytes)

undefined2 FUN_fff9d885(void)

{
  return DAT_0001b63c;
}


// ===== dsp_tune_offset @ fff9d895 (15 bytes)

/* Returns 0x1B6E4 */

ushort dsp_tune_offset(void)

{
  return DAT_0001b6e4;
}


// ===== dsp_reg_access @ fff9d8a4 (169 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9d94a) */
/* Blocking read/write of any DSP register (used by CAT SPD); write does not update the shadow */

byte dsp_reg_access(ushort param_1,void *param_2,char param_3)

{
  bool bVar1;
  ushort *puVar2;
  byte bVar3;
  ushort uVar4;
  byte local_15;
  int iStack_14;
  char local_d;
  ushort *local_c;
  ushort local_6;
  
  local_d = param_3;
  local_c = param_2;
  local_6 = param_1;
  while( true ) {
    if ((DAT_00001c5e == '\x01') || (DAT_00001c5f == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) break;
    dsp_link_poll();
  }
  DAT_0001b6de = local_6;
  if (local_d == '\0') {
    dsp_send_frame('r');
    do {
      if (DAT_00001c5f != '\x01') {
        return 0;
      }
      bVar3 = dsp_check_reply('r',&iStack_14);
      puVar2 = local_c;
    } while (bVar3 != 1);
    uVar4 = hex2word((char *)(iStack_14 + 1));
    *puVar2 = uVar4;
    local_15 = 1;
  }
  else {
    DAT_0001b6e0 = *local_c;
    dsp_send_frame('w');
    do {
      local_15 = dsp_check_reply('w',&iStack_14);
    } while (DAT_00001c5e != '\0');
  }
  return local_15;
}


// ===== dsp_isp_request @ fff9d94d (10 bytes)

/* Sets 0x1C63=1 (DISPLAY link sub-command 2) so dsp_link_poll enters dsp_isp_bridge */

void dsp_isp_request(void)

{
  DAT_00001c63 = 1;
  return;
}


// ===== dsp_read_version @ fff9d957 (16 bytes)

/* Read reg 0 (version) */

void dsp_read_version(void)

{
  DAT_0001b6de = 0;
  dsp_send_frame('r');
  return;
}


// ===== dsp_read_status1 @ fff9d967 (16 bytes)

/* Read reg 1 (bit0 ready, bit4 VOX, bit6 tone decode, high byte FM noise) */

void dsp_read_status1(void)

{
  DAT_0001b6de = 1;
  dsp_send_frame('r');
  return;
}


// ===== dsp_read_status2 @ fff9d977 (16 bytes)

/* Read reg 2 (compression meter source) */

void dsp_read_status2(void)

{
  DAT_0001b6de = 2;
  dsp_send_frame('r');
  return;
}


// ===== dsp_read_status3 @ fff9d987 (16 bytes)

/* Read reg 3 (signal level -> S meter) */

void dsp_read_status3(void)

{
  DAT_0001b6de = 3;
  dsp_send_frame('r');
  return;
}


// ===== dsp_read_status4 @ fff9d997 (16 bytes)

/* Read reg 4 (signed tuning offset, ZIN) */

void dsp_read_status4(void)

{
  DAT_0001b6de = 4;
  dsp_send_frame('r');
  return;
}


// ===== dsp_set_demod @ fff9d9a7 (98 bytes)

/* reg 6: 3 LSB/DATA-L/RTTY-L, 2 USB/DATA-U/RTTY-U/PSK, 1 CW-L, 0 CW-U, 8 AM, 9 FM */

void dsp_set_demod(void)

{
  byte bVar1;
  short sStack_2;
  
  bVar1 = vfo_mode(0);
  switch(bVar1) {
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
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r08 @ fff9da09 (51 bytes)

/* reg 8: route word (0x2022 / 0x2222 / 0x20B34) */

void dsp_set_r08(byte param_1)

{
  ushort uVar1;
  
  uVar1 = dsp_route_param(8);
  if (DAT_0001b640 == uVar1) {
    return;
  }
  DAT_0001b6de = 8;
  DAT_0001b6e0 = uVar1;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r09 @ fff9da3c (51 bytes)

/* reg 9: route constant 0/2 */

void dsp_set_r09(byte param_1)

{
  ushort uVar1;
  
  uVar1 = dsp_route_param(9);
  if (DAT_0001b642 == uVar1) {
    return;
  }
  DAT_0001b6de = 9;
  DAT_0001b6e0 = uVar1;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r0a @ fff9da6f (51 bytes)

/* reg 10: route/input select */

void dsp_set_r0a(byte param_1)

{
  ushort uVar1;
  
  uVar1 = dsp_route_param(10);
  if (DAT_0001b644 == uVar1) {
    return;
  }
  DAT_0001b6de = 10;
  DAT_0001b6e0 = uVar1;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r0c @ fff9daa2 (47 bytes)

/* reg 0x0C = 0 (once) */

void dsp_set_r0c(void)

{
  if (DAT_0001b646 == 0) {
    return;
  }
  DAT_0001b6de = 0xc;
  DAT_0001b6e0 = 0;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r0d @ fff9dad1 (51 bytes)

/* reg 0x0D: 0xF000 in CW TX route, else 0 */

void dsp_set_r0d(byte param_1)

{
  ushort uVar1;
  
  uVar1 = dsp_route_param(0xd);
  if (DAT_0001b648 == uVar1) {
    return;
  }
  DAT_0001b6de = 0xd;
  DAT_0001b6e0 = uVar1;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r0e @ fff9db04 (51 bytes)

/* reg 0x0E: 0xF000 in CW TX route, else 0 */

void dsp_set_r0e(byte param_1)

{
  ushort uVar1;
  
  uVar1 = dsp_route_param(0xe);
  if (DAT_0001b64a == uVar1) {
    return;
  }
  DAT_0001b6de = 0xe;
  DAT_0001b6e0 = uVar1;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r0f @ fff9db37 (47 bytes)

/* reg 0x0F = 0x2B (once) */

void dsp_set_r0f(void)

{
  if (DAT_0001b64c == 0x2b) {
    return;
  }
  DAT_0001b6de = 0xf;
  DAT_0001b6e0 = 0x2b;
  dsp_send_frame('w');
  return;
}


// ===== dsp_set_r11 @ fff9db66 (49 bytes)

/* reg 0x11 = 0xFFA2 (once) */

void dsp_set_r11(void)

{
  if (DAT_0001b650 == -0x5e) {
    return;
  }
  DAT_0001b6de = 0x11;
  DAT_0001b6e0 = 0xffa2;
  dsp_send_frame('w');
  return;
}

