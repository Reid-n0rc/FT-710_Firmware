// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffcdcfe @ fffcdcfe (17 bytes)

void FUN_fffcdcfe(void)

{
  FUN_fffcdbb8();
  PTR_DAT_00025d60[0x3ff] = 2;
  return;
}


// ===== FUN_fffcdd0f @ fffcdd0f (111 bytes)

undefined1 FUN_fffcdd0f(void)

{
  undefined1 uVar1;
  byte bVar2;
  char *pcVar3;
  undefined1 uStack_9;
  
  uVar1 = FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pcVar3 = (char *)FUN_fffd4ada(uVar1);
  if (pcVar3 == (char *)0x0) {
    uStack_9 = 0;
  }
  else {
    bVar2 = FUN_fffd4841(uVar1);
    if (bVar2 < 5) {
      uStack_9 = 0;
    }
    else if ((byte)pcVar3[1] < (byte)(bVar2 - 5)) {
      pcVar3[1] = pcVar3[1] + '\x01';
      if (*pcVar3 != '\0') {
        *pcVar3 = *pcVar3 + -1;
      }
      uStack_9 = FUN_fffcdce3();
    }
    else {
      uStack_9 = 0;
    }
  }
  return uStack_9;
}


// ===== FUN_fffcdd7e @ fffcdd7e (93 bytes)

void FUN_fffcdd7e(void)

{
  char *pcVar1;
  undefined1 uStack_4;
  undefined1 uStack_3;
  char cStack_2;
  undefined1 uStack_1;
  
  FUN_fffc8f30(3000);
  PTR_DAT_00025d60[0x40b] = 1;
  uStack_1 = FUN_fffd49f4(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  pcVar1 = (char *)FUN_fffd4ada(uStack_1);
  if (pcVar1 == (char *)0x0) {
    return;
  }
  uStack_4 = PTR_DAT_00025d60[0x41f];
  uStack_3 = uStack_1;
  cStack_2 = *pcVar1 + pcVar1[1];
  FUN_fffd49c0(&uStack_4);
  return;
}


// ===== FUN_fffcdddb @ fffcdddb (42 bytes)

void FUN_fffcdddb(undefined4 param_1)

{
  DAT_00015dfc = 1;
  FUN_fffd49c0(param_1);
  DAT_00015dfc = 0;
  PTR_DAT_00025d60[0x40b] = 1;
  return;
}


// ===== FUN_fffcde18 @ fffcde18 (74 bytes)

void FUN_fffcde18(char param_1,char param_2,char *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + '\x01';
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 + -1;
      return;
    }
  }
  return;
}


// ===== FUN_fffcdecf @ fffcdecf (72 bytes)

void FUN_fffcdecf(byte *param_1)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      *param_1 = *param_1 + 1;
      if (0x13 < *param_1) {
        *param_1 = 0x13;
        return;
      }
    }
    else if (*param_1 != 0) {
      *param_1 = *param_1 - 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffcdf37 @ fffcdf37 (92 bytes)

void FUN_fffcdf37(byte *param_1)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if ((*param_1 != 0) && (*param_1 = *param_1 + 1, 0x43 < *param_1)) {
        *param_1 = 0;
        return;
      }
    }
    else {
      if (*param_1 == 0) {
        *param_1 = 0x43;
        return;
      }
      if (*param_1 != 1) {
        *param_1 = *param_1 - 1;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffcdfb8 @ fffcdfb8 (72 bytes)

void FUN_fffcdfb8(byte param_1,byte param_2,byte *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + 1;
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 - 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffce3eb @ fffce3eb (38 bytes)

byte FUN_fffce3eb(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb324c(1);
  return *(byte *)(iVar1 + 2) >> 2 & 3;
}


// ===== FUN_fffce411 @ fffce411 (37 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce42c) */

void FUN_fffce411(byte param_1)

{
  int iVar1;
  
  iVar1 = FUN_fffb324c(1);
  *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 0xf3 | (param_1 & 3) << 2;
  return;
}


// ===== FUN_fffce495 @ fffce495 (74 bytes)

void FUN_fffce495(ushort param_1,ushort param_2,ushort *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if (*param_3 < param_2) {
        *param_3 = *param_3 + 1;
        return;
      }
    }
    else if (param_1 < *param_3) {
      *param_3 = *param_3 - 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffce53c @ fffce53c (38 bytes)

byte FUN_fffce53c(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb324c(1);
  return *(byte *)(iVar1 + 3) >> 3 & 7;
}


// ===== FUN_fffce562 @ fffce562 (38 bytes)

/* WARNING: Removing unreachable block (ram,0xfffce57d) */

void FUN_fffce562(byte param_1)

{
  int iVar1;
  
  iVar1 = FUN_fffb324c(1);
  *(byte *)(iVar1 + 3) = *(byte *)(iVar1 + 3) & 199 | (param_1 & 7) << 3;
  return;
}


// ===== FUN_fffce5be @ fffce5be (55 bytes)

undefined1 FUN_fffce5be(void)

{
  undefined1 *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d4f;
  }
  else {
    local_8 = &DAT_00009da9;
  }
  return *local_8;
}


// ===== FUN_fffce5f5 @ fffce5f5 (52 bytes)

void FUN_fffce5f5(undefined1 param_1)

{
  undefined1 *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d4f;
  }
  else {
    local_8 = &DAT_00009da9;
  }
  *local_8 = param_1;
  return;
}


// ===== FUN_fffcf38f @ fffcf38f (108 bytes)

void FUN_fffcf38f(byte param_1,byte param_2,byte *param_3)

{
  if (DAT_00015dfc != '\x01') {
    if (PTR_DAT_00025d60[0x421] == '\0') {
      if ((*param_3 < param_2) && (*param_3 = *param_3 + 1, 9 < (*param_3 & 0xf))) {
        *param_3 = *param_3 + 6;
        return;
      }
    }
    else if ((param_1 < *param_3) && (*param_3 = *param_3 - 1, 9 < (*param_3 & 0xf))) {
      *param_3 = *param_3 - 6;
      return;
    }
  }
  return;
}


// ===== FUN_fffcf45c @ fffcf45c (92 bytes)

void FUN_fffcf45c(void)

{
  if ((((PTR_DAT_00025d60[0xa5] == '\x01') && (PTR_DAT_00025d60[0xa7] != PTR_DAT_00025d60[0xa6])) &&
      (PTR_DAT_00025d60[0xa7] = PTR_DAT_00025d60[0xa6], PTR_DAT_00025d60[0xa6] == '\x01')) &&
     ((PTR_DAT_00025d60[0xba] == '\0' && (PTR_DAT_00025d60[0x95] == '\0')))) {
    FUN_fffcf4b8();
    return;
  }
  return;
}


// ===== FUN_fffcf4b8 @ fffcf4b8 (29 bytes)

void FUN_fffcf4b8(void)

{
  PTR_DAT_00025d60[0xbb] = 1;
  PTR_DAT_00025d60[0x448] = 1;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf4d5 @ fffcf4d5 (29 bytes)

void FUN_fffcf4d5(void)

{
  PTR_DAT_00025d60[0xbb] = 2;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf4f2 @ fffcf4f2 (29 bytes)

void FUN_fffcf4f2(void)

{
  PTR_DAT_00025d60[0xbb] = 3;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf50f @ fffcf50f (29 bytes)

void FUN_fffcf50f(void)

{
  PTR_DAT_00025d60[0xbb] = 5;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf52c @ fffcf52c (29 bytes)

void FUN_fffcf52c(void)

{
  PTR_DAT_00025d60[0xbb] = 6;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf549 @ fffcf549 (29 bytes)

void FUN_fffcf549(void)

{
  PTR_DAT_00025d60[0xbb] = 7;
  PTR_DAT_00025d60[0x448] = 1;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf566 @ fffcf566 (29 bytes)

void FUN_fffcf566(void)

{
  PTR_DAT_00025d60[0xbb] = 8;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf583 @ fffcf583 (29 bytes)

void FUN_fffcf583(void)

{
  PTR_DAT_00025d60[0xbb] = 0xd;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf5a0 @ fffcf5a0 (29 bytes)

void FUN_fffcf5a0(void)

{
  PTR_DAT_00025d60[0xbb] = 9;
  PTR_DAT_00025d60[0x448] = 1;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf5bd @ fffcf5bd (60 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcf5da) */

undefined2 FUN_fffcf5bd(void)

{
  undefined2 local_4;
  
  if (DAT_00015de5 == '\0') {
    local_4 = CONCAT11(DAT_00012274,DAT_00012273);
  }
  else {
    local_4 = FUN_fffb3b33();
  }
  return local_4;
}


// ===== FUN_fffcf5f9 @ fffcf5f9 (92 bytes)

/* WARNING: Removing unreachable block (ram,0xfffcf652) */

undefined4 FUN_fffcf5f9(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_fffb3b33();
  if (DAT_00015de5 == '\0') {
    uVar2 = FUN_fffcf5bd();
    if (uVar1 == (uVar2 & 0xff)) {
      PTR_DAT_00025d60[0xbb] = 10;
    }
    else {
      PTR_DAT_00025d60[0xbb] = 0xf;
    }
  }
  else {
    uVar2 = FUN_fffcf5bd();
    if (uVar1 == (uVar2 & 0xff)) {
      PTR_DAT_00025d60[0xbb] = 10;
    }
    else {
      PTR_DAT_00025d60[0xbb] = 0xf;
    }
  }
  PTR_DAT_00025d60[0x448] = 0;
  uVar3 = FUN_fffcf6ac();
  return uVar3;
}


// ===== FUN_fffcf655 @ fffcf655 (29 bytes)

void FUN_fffcf655(void)

{
  PTR_DAT_00025d60[0xbb] = 0xb;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf672 @ fffcf672 (29 bytes)

void FUN_fffcf672(void)

{
  PTR_DAT_00025d60[0xbb] = 0xc;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf68f @ fffcf68f (29 bytes)

void FUN_fffcf68f(void)

{
  PTR_DAT_00025d60[0xbb] = 4;
  PTR_DAT_00025d60[0x448] = 0;
  FUN_fffcf6ac();
  return;
}


// ===== FUN_fffcf6ac @ fffcf6ac (49 bytes)

void FUN_fffcf6ac(void)

{
  PTR_DAT_00025d60[0x86] = 1;
  PTR_DAT_00025d60[0xbd] = 0;
  if (DAT_00020b74 == '\0') {
    return;
  }
  DAT_00020b74 = 0;
  return;
}


// ===== FUN_fffcf6dd @ fffcf6dd (26 bytes)

void FUN_fffcf6dd(void)

{
  DAT_00015de5 = 1;
  PTR_DAT_00025d60[0x1e4] = 1;
  FUN_fffcf6f7();
  return;
}


// ===== FUN_fffcf6f7 @ fffcf6f7 (137 bytes)

void FUN_fffcf6f7(void)

{
  PTR_DAT_00025d60[0x88] = 1;
  DAT_00015de3 = 1;
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e5] = 0;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 1;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== FUN_fffcf78d @ fffcf78d (26 bytes)

void FUN_fffcf78d(void)

{
  DAT_00015de5 = 1;
  PTR_DAT_00025d60[0x1e4] = 2;
  FUN_fffcf7a7();
  return;
}


// ===== FUN_fffcf7a7 @ fffcf7a7 (137 bytes)

void FUN_fffcf7a7(void)

{
  PTR_DAT_00025d60[0x88] = 1;
  DAT_00015de3 = 2;
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e5] = 0;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 1;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== FUN_fffcf83d @ fffcf83d (26 bytes)

void FUN_fffcf83d(void)

{
  DAT_00015de5 = 0;
  PTR_DAT_00025d60[0x1e4] = 3;
  FUN_fffcf6f7();
  return;
}


// ===== FUN_fffcf864 @ fffcf864 (26 bytes)

void FUN_fffcf864(void)

{
  DAT_00015de5 = 0;
  PTR_DAT_00025d60[0x1e4] = 4;
  FUN_fffcf7a7();
  return;
}


// ===== FUN_fffcf88b @ fffcf88b (150 bytes)

void FUN_fffcf88b(void)

{
  PTR_DAT_00025d60[0x88] = 1;
  DAT_00015de3 = 3;
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e4] = 5;
  PTR_DAT_00025d60[0x1e5] = 1;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 1;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== FUN_fffcf92e @ fffcf92e (22 bytes)

void FUN_fffcf92e(void)

{
  PTR_DAT_00025d60[0x88] = 0;
  DAT_00015de3 = 0;
  return;
}


// ===== FUN_fffcf951 @ fffcf951 (150 bytes)

void FUN_fffcf951(void)

{
  PTR_DAT_00025d60[0x88] = 1;
  DAT_00015de3 = 4;
  PTR_DAT_00025d60[0x87] = 1;
  PTR_DAT_00025d60[0x1e4] = 8;
  PTR_DAT_00025d60[0x1e5] = 0;
  PTR_DAT_00025d60[0x1e6] = 0;
  PTR_DAT_00025d60[0x1e7] = 0;
  PTR_DAT_00025d60[0x1e8] = 0;
  *(undefined2 *)(PTR_DAT_00025d60 + 0x1e2) = 0x23;
  PTR_DAT_00025d60[0x3f6] = 0;
  PTR_DAT_00025d60[0x3f7] = 1;
  PTR_DAT_00025d60[0x1e0] = 0x43;
  return;
}


// ===== FUN_fffcfa26 @ fffcfa26 (23 bytes)

void FUN_fffcfa26(undefined1 param_1)

{
  PTR_DAT_00025d60[0xbb] = 0xe;
  FUN_fffcfa3d(param_1);
  return;
}


// ===== FUN_fffcfa3d @ fffcfa3d (55 bytes)

void FUN_fffcfa3d(undefined1 param_1)

{
  PTR_DAT_00025d60[0x86] = 1;
  PTR_DAT_00025d60[0x448] = 1;
  PTR_DAT_00025d60[0xbc] = param_1;
  PTR_DAT_00025d60[0xbd] = 0;
  return;
}


// ===== FUN_fffcfa92 @ fffcfa92 (23 bytes)

void FUN_fffcfa92(undefined1 param_1)

{
  PTR_DAT_00025d60[0xbb] = 0;
  FUN_fffcfa3d(param_1);
  return;
}


// ===== FUN_fffcfaa9 @ fffcfaa9 (86 bytes)

undefined1 FUN_fffcfaa9(undefined2 param_1)

{
  undefined1 local_4;
  
  if (DAT_00015de3 == '\x04') {
    local_4 = FUN_fffcffd6(param_1);
  }
  else if (DAT_00015de3 == '\x01') {
    local_4 = FUN_fffcfb26(param_1);
  }
  else if (DAT_00015de3 == '\x02') {
    local_4 = FUN_fffcfd45(param_1);
  }
  else if (DAT_00015de3 == '\x03') {
    local_4 = FUN_fffcff9b(param_1);
  }
  else if (DAT_00015de3 == '\0') {
    local_4 = FUN_fffcfaff(param_1);
  }
  else {
    local_4 = 2;
  }
  return local_4;
}


// ===== FUN_fffcfaff @ fffcfaff (39 bytes)

undefined1 FUN_fffcfaff(int param_1)

{
  undefined1 local_4;
  
  if (param_1 == 0x166) {
    PTR_DAT_00025d60[0x47b] = 1;
    local_4 = FUN_fffcfe77();
  }
  else {
    local_4 = 1;
  }
  return local_4;
}


// ===== FUN_fffcfb26 @ fffcfb26 (116 bytes)

undefined1 FUN_fffcfb26(ushort param_1)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  
  if ((param_1 < 0x150) || (0x159 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return 0;
  }
  bVar2 = (char)param_1 + 0xb0;
  if (5 < bVar2) {
    if (bVar2 == 6) {
      uVar3 = FUN_fffcfbee();
      return uVar3;
    }
    if (bVar2 == 7) {
      uVar3 = FUN_fffcfc02();
      return uVar3;
    }
    if (bVar2 != 9) {
      return 0;
    }
    DAT_00015de8 = 0xff;
    bVar2 = DAT_00015de8;
  }
  DAT_00015de8 = bVar2;
  uVar3 = FUN_fffcfb9a();
  return uVar3;
}


// ===== FUN_fffcfb9a @ fffcfb9a (84 bytes)

undefined1 FUN_fffcfb9a(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d60[0x3f7] == '\x02') {
    if (DAT_00015de8 == -1) {
      local_2 = FUN_fffcfe77();
    }
    else if (DAT_00015de6 < (byte)(DAT_00015de8 + 1U)) {
      local_2 = 0;
    }
    else {
      FUN_fffd0902();
      FUN_fffd06d4();
      local_2 = 1;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffcfbee @ fffcfbee (20 bytes)

undefined1 FUN_fffcfbee(void)

{
  FUN_fffcfc16(1);
  FUN_fffb2da6(1);
  return 0;
}


// ===== FUN_fffcfc02 @ fffcfc02 (20 bytes)

undefined1 FUN_fffcfc02(void)

{
  FUN_fffcfc16(0);
  FUN_fffb2da6(1);
  return 0;
}

