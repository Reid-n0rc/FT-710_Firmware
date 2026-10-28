// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff9ba18 @ fff9ba18 (136 bytes)

void FUN_fff9ba18(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_000096a0;
  puVar1 = PTR_DAT_00025d38 + 0xc2;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_000096d3;
  puVar1 = PTR_DAT_00025d38 + 0xf4;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00009706;
  puVar1 = PTR_DAT_00025d38 + 0x126;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00009739;
  puVar1 = PTR_DAT_00025d38 + 0x158;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_0000976c;
  puVar1 = PTR_DAT_00025d38 + 0x18a;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== FUN_fff9baa0 @ fff9baa0 (131 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fff9baa0(void)

{
  ram0x00001805 = DAT_000097a2;
  ram0x00001801 = DAT_0000979e;
  ram0x0000180d = DAT_000097d4;
  ram0x00001809 = DAT_000097d0;
  DAT_00001815 = DAT_00009806;
  ram0x00001811 = DAT_00009802;
  DAT_0000181d = DAT_00009838;
  DAT_00001819 = DAT_00009834;
  DAT_00001825 = DAT_0000986a;
  DAT_00001821 = DAT_00009866;
  return;
}


// ===== displink_tx_41 @ fff9bb23 (45 bytes)

/* 0x41 (0x146 bytes) */

void displink_tx_41(void)

{
  int iVar1;
  
  displink_build_41();
  iVar1 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0x145);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x146;
  displink_tx_start(0x146);
  return;
}


// ===== displink_build_41 @ fff9bb50 (1128 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9bc1f) */
/* WARNING: Removing unreachable block (ram,0xfff9bbf2) */
/* WARNING: Removing unreachable block (ram,0xfff9bbf8) */
/* WARNING: Removing unreachable block (ram,0xfff9be3f) */

void displink_build_41(void)

{
  uint uVar1;
  bool bVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  ushort uVar9;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  byte bStack_3;
  byte bStack_1;
  
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
  DAT_00001741 = 0x41;
  FUN_fff98cd3();
  bVar4 = FUN_fffc2b2e(PTR_DAT_00025d38[0x439],PTR_DAT_00025d38[0x1db]);
  bVar5 = FUN_fff9c04a();
  if ((bVar5 == 0) || (bVar4 < bVar5)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    PTR_DAT_00025d38[0x1d8] = 0;
  }
  else {
    iVar6 = memch_valid(bVar4,&DAT_00020880);
    if (iVar6 == 1) {
      PTR_DAT_00025d38[0x1d8] = 0;
    }
    else {
      PTR_DAT_00025d38[0x1d8] = 1;
    }
  }
  DAT_000017d9 = PTR_DAT_00025d38[0x1d8] << 7 | PTR_DAT_00025d38[0x1d9] << 6;
  DAT_000017da = PTR_DAT_00025d38[0x1da] << 4 | PTR_DAT_00025d38[0x1db];
  DAT_0001b632 = 0x9c;
  puVar7 = &DAT_000017dd;
  puVar8 = &DAT_fff804c4;
  for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = *puVar8;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  uVar9 = DAT_0001b632 + 0xf;
  DAT_0001b632 = uVar9;
  if (DAT_00009ac2 == '\x01') {
    bVar4 = FUN_fff9bfe1(bVar4);
    uVar1 = (uint)DAT_0001b632;
    *(undefined2 *)(&DAT_00001745 + uVar1) = 0x2050;
    *(undefined4 *)(&DAT_00001741 + uVar1) = 0x554f5247;
    DAT_0001b632 = DAT_0001b632 + 6;
    if (bVar4 < 6) {
      (&DAT_00001741)[DAT_0001b632] = 0x20;
      DAT_0001b632 = DAT_0001b632 + 1;
      (&DAT_00001741)[DAT_0001b632] = 0x20;
      DAT_0001b632 = DAT_0001b632 + 1;
      (&DAT_00001741)[DAT_0001b632] = bVar4 + 0x30;
      DAT_0001b632 = DAT_0001b632 + 1;
      (&DAT_00001741)[DAT_0001b632] = 0x20;
      DAT_0001b632 = DAT_0001b632 + 1;
    }
    else {
      *(undefined4 *)(&DAT_00001741 + DAT_0001b632) =
           *(undefined4 *)(&DAT_fff80370 + (uint)(byte)(bVar4 - 6) * 4);
      DAT_0001b632 = DAT_0001b632 + 4;
    }
  }
  else {
    *(undefined4 *)(&DAT_00001745 + uVar9) = 0x20202020;
    *(undefined4 *)(&DAT_00001741 + uVar9) = 0x20202020;
    *(undefined2 *)(&DAT_00001749 + uVar9) = 0x2020;
    DAT_0001b632 = DAT_0001b632 + 10;
  }
  bStack_4 = PTR_DAT_00025d38[0x439];
  for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
    DAT_00020884 = &DAT_00006150 + (uint)bStack_4 * 0x5a;
    iVar6 = memch_valid(bStack_4,&DAT_00020880);
    if (iVar6 == 1) {
      (&DAT_00001741)[DAT_0001b632] = DAT_00020884[5] >> 7 | DAT_00020884[1] >> 6 & 2;
      DAT_0001b632 = DAT_0001b632 + 1;
      FUN_fff9c089(&DAT_00001741 + DAT_0001b632,bStack_4);
      DAT_0001b632 = DAT_0001b632 + 5;
      FUN_fff9c2f9(&DAT_00001741 + DAT_0001b632,bStack_4);
      DAT_0001b632 = DAT_0001b632 + 10;
      bStack_1 = *DAT_00020884 & 0xf;
      if (0xd < bStack_1) {
        bStack_1 = 0xe;
      }
      uVar1 = (uint)DAT_0001b632;
      *(undefined4 *)(&DAT_00001745 + DAT_0001b632) =
           *(undefined4 *)(&DAT_fff80380 + (uint)bStack_1 * 8);
      *(undefined4 *)(&DAT_00001741 + uVar1) = *(undefined4 *)(&DAT_fff8037c + (uint)bStack_1 * 8);
      pbVar3 = DAT_00020884;
      uVar9 = DAT_0001b632 + 8;
      DAT_0001b632 = uVar9;
      *(undefined4 *)(&DAT_00001749 + uVar9) = *(undefined4 *)(DAT_00020884 + 0x56);
      *(undefined4 *)(&DAT_00001745 + uVar9) = *(undefined4 *)(pbVar3 + 0x52);
      *(undefined4 *)(&DAT_00001741 + uVar9) = *(undefined4 *)(pbVar3 + 0x4e);
    }
    else {
      (&DAT_00001741)[DAT_0001b632] = 0;
      DAT_0001b632 = DAT_0001b632 + 1;
      FUN_fff9c089(&DAT_00001741 + DAT_0001b632,bStack_4);
      uVar9 = DAT_0001b632 + 5;
      DAT_0001b632 = uVar9;
      *(undefined4 *)(&DAT_00001745 + uVar9) = 0x2d2e2d2d;
      *(undefined4 *)(&DAT_00001741 + uVar9) = 0x2d2e2d2d;
      *(undefined2 *)(&DAT_00001749 + uVar9) = 0x2d2d;
      DAT_0001b632 = DAT_0001b632 + 10;
      uVar1 = (uint)DAT_0001b632;
      *(undefined4 *)(&DAT_00001745 + DAT_0001b632) = 0x2d2d2d2d;
      *(undefined4 *)(&DAT_00001741 + uVar1) = 0x2d2d2d2d;
      uVar9 = DAT_0001b632 + 8;
      DAT_0001b632 = uVar9;
      *(undefined4 *)(&DAT_00001749 + uVar9) = 0x2d2d2d2d;
      *(undefined4 *)(&DAT_00001745 + uVar9) = 0x2d2d2d2d;
      *(undefined4 *)(&DAT_00001741 + uVar9) = 0x2d2d2d2d;
    }
    DAT_0001b632 = DAT_0001b632 + 0xc;
    FUN_fff9c1a1();
    if (bStack_6 != bStack_5) {
      bStack_6 = bStack_6 + 1;
      do {
        bStack_4 = bStack_4 + 1;
        if (bStack_6 <= bStack_4) {
          bStack_4 = bStack_5;
        }
        if ((bStack_4 < 0x84) && (0x74 < bStack_4)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
      } while ((bVar2) &&
              ((iVar6 = FUN_fff9c2cd(), iVar6 != 1 ||
               (iVar6 = memch_dest_blocked(bStack_4), iVar6 != 0))));
    }
  }
  return;
}


// ===== FUN_fff9bfb8 @ fff9bfb8 (41 bytes)

undefined1 FUN_fff9bfb8(void)

{
  undefined1 uVar1;
  
  uVar1 = memch_current(DAT_00009dbd != '\0');
  uVar1 = FUN_fff9bfe1(uVar1);
  return uVar1;
}


// ===== FUN_fff9bfe1 @ fff9bfe1 (105 bytes)

char FUN_fff9bfe1(byte param_1)

{
  byte local_5;
  byte local_4;
  char local_3;
  
  if (param_1 < 0x84) {
    if (param_1 < 0x75) {
      if (param_1 < 99) {
        local_5 = 0;
        local_4 = 0;
        while ((local_4 < 5 && (local_5 = (&DAT_fff804d3)[local_4] + local_5, local_5 <= param_1)))
        {
          local_4 = local_4 + 1;
        }
        if (local_4 == 5) {
          local_4 = 0;
        }
        local_3 = local_4 + 1;
      }
      else {
        local_3 = '\x06';
      }
    }
    else {
      local_3 = '\a';
    }
  }
  else {
    local_3 = '\b';
  }
  return local_3;
}


// ===== FUN_fff9c04a @ fff9c04a (63 bytes)

undefined1 FUN_fff9c04a(void)

{
  short sVar1;
  
  sVar1 = dest_code_get();
  if ((sVar1 != 0x20b) && (sVar1 != 0x1cb9)) {
    if (sVar1 == 0x315b) {
      return 0x84;
    }
    if (sVar1 != 0x4380) {
      if (sVar1 == 0x50e2) {
        return 0x84;
      }
      if (sVar1 != 0x60e6) {
        return 0;
      }
    }
  }
  return 0x75;
}


// ===== FUN_fff9c089 @ fff9c089 (217 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9c0ec) */
/* WARNING: Removing unreachable block (ram,0xfff9c0a3) */
/* WARNING: Removing unreachable block (ram,0xfff9c0f7) */
/* WARNING: Removing unreachable block (ram,0xfff9c0cf) */
/* WARNING: Removing unreachable block (ram,0xfff9c12f) */
/* WARNING: Removing unreachable block (ram,0xfff9c15f) */

undefined4 * FUN_fff9c089(undefined4 *param_1,byte param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  
  if (0x83 < param_2) {
    *(undefined1 *)(param_1 + 1) = 0x20;
    *param_1 = 0x20474d45;
    return param_1;
  }
  if (param_2 < 0x75) {
    if (0x62 < param_2) {
      *(undefined1 *)((int)param_1 + 2) = 0x50;
      *(undefined2 *)param_1 = 0x2d4d;
      if ((param_2 + 0x9d & 1) == 0) {
        *(undefined1 *)(param_1 + 1) = 0x4c;
      }
      else {
        *(undefined1 *)(param_1 + 1) = 0x55;
      }
      puVar2 = (undefined4 *)((byte)(((byte)(param_2 + 0x9d) >> 1) + 1) + 0x30);
      *(char *)((int)param_1 + 3) = (char)puVar2;
      return puVar2;
    }
    *(undefined2 *)param_1 = 0x2d4d;
    if ((byte)(param_2 + 1) < 10) {
      *(undefined1 *)((int)param_1 + 2) = 0x30;
      *(byte *)((int)param_1 + 3) = param_2 + 0x31;
    }
    else {
      FUN_fff9c6f0(param_2 + 1,(undefined2 *)((int)param_1 + 2));
    }
    *(undefined1 *)(param_1 + 1) = 0x20;
    return param_1;
  }
  *(undefined2 *)param_1 = 0x2d35;
  bVar1 = FUN_fff9c162(param_2);
  if (bVar1 < 10) {
    *(undefined1 *)((int)param_1 + 2) = 0x30;
    puVar2 = (undefined4 *)nib2hex(bVar1);
    *(char *)((int)param_1 + 3) = (char)puVar2;
    return puVar2;
  }
  if (bVar1 < 0x14) {
    *(undefined1 *)((int)param_1 + 2) = 0x31;
    puVar2 = (undefined4 *)nib2hex(bVar1 - 10);
    *(char *)((int)param_1 + 3) = (char)puVar2;
    return puVar2;
  }
  *(undefined1 *)((int)param_1 + 2) = 0x2a;
  *(undefined1 *)((int)param_1 + 3) = 0x2a;
  return param_1;
}


// ===== FUN_fff9c162 @ fff9c162 (63 bytes)

char FUN_fff9c162(char param_1)

{
  int iVar1;
  byte local_4;
  char local_3;
  
  local_3 = '\0';
  local_4 = 0;
  while( true ) {
    if (0xe < local_4) {
      return local_3;
    }
    iVar1 = memch_dest_blocked(local_4 + 0x75);
    if (iVar1 == 0) {
      local_3 = local_3 + '\x01';
    }
    if (param_1 == (byte)(local_4 + 0x75)) break;
    local_4 = local_4 + 1;
  }
  return local_3;
}


// ===== FUN_fff9c1a1 @ fff9c1a1 (241 bytes)

void FUN_fff9c1a1(char *param_1,char *param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte bStack_a;
  
  if ((DAT_00009ac2 == '\x01') && (PTR_DAT_00025d38[0x97] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    *param_1 = '\0';
    iVar3 = FUN_fff9c292();
    if ((iVar3 == 1) && (DAT_00009af4 == '\x01')) {
      *param_2 = -0x7c;
      return;
    }
    iVar3 = FUN_fff9c2cd();
    if (iVar3 == 1) {
      *param_2 = -0x7d;
      return;
    }
    *param_2 = 't';
    return;
  }
  bVar2 = FUN_fff9bfb8();
  if (bVar2 == 6) {
    *param_1 = 'c';
    *param_2 = 't';
    return;
  }
  if (bVar2 < 8) {
    if (bVar2 < 7) {
      *param_1 = '\0';
      *param_2 = '\x12';
      for (bStack_a = 0; (bStack_a < 5 && (bVar2 != (byte)(bStack_a + 1))); bStack_a = bStack_a + 1)
      {
        *param_1 = (&DAT_fff804d3)[bStack_a] + *param_1;
        *param_2 = *param_2 + (&DAT_fff804d4)[bStack_a];
      }
      return;
    }
    *param_1 = 'u';
    *param_2 = -0x7d;
    return;
  }
  *param_1 = -0x7c;
  *param_2 = -0x7c;
  return;
}


// ===== FUN_fff9c292 @ fff9c292 (59 bytes)

undefined1 FUN_fff9c292(void)

{
  undefined *puVar1;
  undefined1 local_2;
  
  local_2 = 1;
  puVar1 = (undefined *)dest_code_get();
  if ((((puVar1 == &DAT_0000306f) || (puVar1 == &DAT_0000a4c5)) || (puVar1 == &DAT_0000a983)) ||
     (((puVar1 == &DAT_0000b5a7 || (puVar1 == &DAT_0000d32d)) || (puVar1 == &DAT_0000d950)))) {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fff9c2cd @ fff9c2cd (44 bytes)

undefined1 FUN_fff9c2cd(void)

{
  undefined *puVar1;
  undefined1 local_2;
  
  local_2 = 0;
  puVar1 = (undefined *)dest_code_get();
  if ((((puVar1 == &DAT_0000315b) || (puVar1 == &DAT_000050e2)) || (puVar1 == &DAT_0000a4c5)) ||
     (puVar1 == &DAT_0000d950)) {
    local_2 = 1;
  }
  return local_2;
}


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


// ===== displink_tx_20_status @ fff9c42a (42 bytes)

/* 0x20 (0x99 bytes) status, default frame, sent only when changed */

void displink_tx_20_status(void)

{
  int iVar1;
  
  displink_build_20();
  iVar1 = displink_copy_if_changed(&DAT_000016a0,&DAT_00001456,0x98);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x99;
  displink_tx_start(0x99);
  return;
}


// ===== displink_build_20 @ fff9c454 (25 bytes)

void displink_build_20(void)

{
  mem_zero(0x98,&DAT_000016a0);
  DAT_000016a0 = 0x20;
  displink_build_status();
  return;
}


// ===== displink_tx_62 @ fff9c46d (45 bytes)

/* 0x62 (0x197 bytes) */

void displink_tx_62(void)

{
  int iVar1;
  
  displink_build_62();
  iVar1 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0x196);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0x197;
  displink_tx_start(0x197);
  return;
}


// ===== displink_build_62 @ fff9c49a (187 bytes)

void displink_build_62(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  ushort uStack_4;
  byte bStack_1;
  
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
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
    FUN_fff9c555(uStack_4,(uint)bStack_1 * 0x1c + 0xb3);
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


// ===== displink_tx_start @ fff9c5b2 (38 bytes)

/* put sum, mark outstanding, send */

void displink_tx_start(undefined2 param_1)

{
  displink_put_sum(&DAT_00001456,param_1);
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

void mem_zero(ushort param_1,undefined4 *param_2)

{
  uint uVar1;
  
  for (uVar1 = (uint)param_1; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = 0;
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}


// ===== displink_copy_if_changed @ fff9c667 (68 bytes)

/* copy staging -> 0x1456 and return 1 only if different */

undefined1 displink_copy_if_changed(undefined1 *param_1,undefined1 *param_2,ushort param_3)

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
  
  uVar1 = vfo_freq(0,2);
  freq_range_index(uVar1);
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


// ===== power_on_request @ fff9cb8e (22 bytes)

/* PS1: 0x20B9C=1, 0x1B3D0=1 (DISPLAY then confirms power-on) */

void power_on_request(void)

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


// ===== freq_cache_update @ fff9cee1 (395 bytes)

/* On 0x20F0F/0x20F10: recompute 0x20F50 TX, 0x20F54 A, 0x20F58 B, 0x20F5C dial */

void freq_cache_update(void)

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
    uVar3 = vfo_freq_clar(1,2);
    uVar3 = tx_freq_repeater_shift(uVar3);
    *(undefined4 *)(PTR_DAT_00025d38 + 0x44c) = uVar3;
    uVar3 = vfo_freq_clar(0,0);
    *(undefined4 *)(PTR_DAT_00025d38 + 0x450) = uVar3;
    uVar3 = vfo_freq_clar(0,1);
    *(undefined4 *)(PTR_DAT_00025d38 + 0x454) = uVar3;
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
  dsp_reset_set(1);
  swtimer_start(0x1f,100);
  do {
    iVar2 = swtimer_expired(0x1f);
  } while (iVar2 != 1);
  sci4_send("i DB00\r",7);
  swtimer_start(0x2e,2);
  do {
    iVar2 = swtimer_expired(0x2e);
  } while (iVar2 != 1);
  puVar3 = (undefined4 *)&DAT_0001b634;
  for (iVar2 = 0xaa; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xff;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  DAT_00001c5e = 0;
  dsp_read_version();
  do {
    if (DAT_00001c5f != '\x01') goto LAB_fff9d11b;
    iVar2 = dsp_check_reply(0x72);
  } while (iVar2 != 1);
  DAT_0001b6e0 = hex2word();
  dsp_shadow_store();
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
  ver_dsp_set();
  bVar1 = false;
  dsp_read_status1();
  do {
    do {
      if (DAT_00001c5f != '\x01') goto LAB_fff9d1a6;
      iVar2 = dsp_check_reply(0x72);
    } while (iVar2 != 1);
    DAT_0001b6e0 = hex2word();
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
  char cVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = DAT_00020b6b;
  cVar2 = DAT_00020b18;
  if (DAT_00001c5e == '\x01') {
    iVar4 = dsp_check_reply(0x77);
    if (iVar4 != 1) {
      return;
    }
    dsp_shadow_store();
  }
  if (DAT_00001c5f == '\x01') {
    iVar4 = dsp_check_reply(0x72);
    if (iVar4 != 1) {
      return;
    }
    DAT_0001b6e0 = hex2word();
    dsp_shadow_store();
  }
  if (DAT_00001c63 == '\x01') {
    dsp_isp_bridge();
  }
  if ((cVar2 == '\x03') || (cVar2 == '\b')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (iVar4 = swtimer_expired(0xb), iVar4 == 1)) {
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
  if ((DAT_00020b49 == '\x01') && (DAT_0001b3d9 != cVar3)) {
    if ((cVar3 == '\x01') && (iVar4 = rx_line_get(), iVar4 != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    if ((cVar3 == '\0') && (iVar4 = tx_line_get(), iVar4 != 0)) {
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
  dsp_set_r08(cVar3);
  if ((((((((DAT_00001c5e == '\0') && (dsp_set_r09(cVar3), DAT_00001c5e == '\0')) &&
          (dsp_set_r0a(cVar3), DAT_00001c5e == '\0')) &&
         ((dsp_set_r0d(cVar3), DAT_00001c5e == '\0' && (dsp_set_r0e(cVar3), DAT_00001c5e == '\0'))))
        && (((dsp_set_tx_gain(), DAT_00001c5e == '\0' &&
             ((dsp_set_dnr_r40(cVar3), DAT_00001c5e == '\0' &&
              (dsp_set_dnf(cVar3), DAT_00001c5e == '\0')))) &&
            (dsp_set_contour(cVar3), DAT_00001c5e == '\0')))) &&
       ((((((dsp_set_contour_level(), DAT_00001c5e == '\0' &&
            (dsp_set_contour_width(), DAT_00001c5e == '\0')) &&
           (dsp_set_apf(cVar3), DAT_00001c5e == '\0')) &&
          (((dsp_set_affft_att(), DAT_00001c5e == '\0' && (dsp_set_osc(cVar3), DAT_00001c5e == '\0')
            ) && ((dsp_set_cw_pitch(), DAT_00001c5e == '\0' &&
                  ((dsp_set_dnr_400b(cVar3), DAT_00001c5e == '\0' &&
                   (dsp_set_dnr_400d(cVar3), DAT_00001c5e == '\0')))))))) &&
         ((dsp_set_dnr_4022(cVar3), DAT_00001c5e == '\0' &&
          (((dsp_set_dnr_4023(cVar3), DAT_00001c5e == '\0' &&
            (dsp_set_dnr_4025(cVar3), DAT_00001c5e == '\0')) &&
           (dsp_set_dnr_4026(cVar3), DAT_00001c5e == '\0')))))) &&
        ((((dsp_set_aess(), DAT_00001c5e == '\0' && (dsp_set_vox_gain(), DAT_00001c5e == '\0')) &&
          ((dsp_set_antivox(), DAT_00001c5e == '\0' &&
           ((dsp_set_peq_freq(0), DAT_00001c5e == '\0' &&
            (dsp_set_peq_freq(1), DAT_00001c5e == '\0')))))) &&
         (dsp_set_peq_freq(2), DAT_00001c5e == '\0')))))) &&
      (((((((dsp_set_peq_level(0), DAT_00001c5e == '\0' &&
            (dsp_set_peq_level(1), DAT_00001c5e == '\0')) &&
           (dsp_set_peq_level(2), DAT_00001c5e == '\0')) &&
          ((dsp_set_peq_bw(0), DAT_00001c5e == '\0' && (dsp_set_peq_bw(1), DAT_00001c5e == '\0'))))
         && ((dsp_set_peq_bw(2), DAT_00001c5e == '\0' &&
             ((dsp_set_proc(), DAT_00001c5e == '\0' && (dsp_set_tx_bpf(), DAT_00001c5e == '\0'))))))
        && (dsp_set_r30(), DAT_00001c5e == '\0')) &&
       ((((dsp_set_r31(), DAT_00001c5e == '\0' && (dsp_set_r32(), DAT_00001c5e == '\0')) &&
         (dsp_set_amc_release(), DAT_00001c5e == '\0')) &&
        (((dsp_set_amc_level(), DAT_00001c5e == '\0' && (dsp_set_ctcss_enc(), DAT_00001c5e == '\0'))
         && ((dsp_set_fm_flag(cVar3), DAT_00001c5e == '\0' && (dsp_set_r3b(), DAT_00001c5e == '\0'))
            )))))))) &&
     ((cVar3 != '\0' ||
      ((((dsp_set_demod(), DAT_00001c5e == '\0' && (dsp_set_hcut(), DAT_00001c5e == '\0')) &&
        (((dsp_set_lcut(), DAT_00001c5e == '\0' &&
          (((dsp_set_tone_freq(0), DAT_00001c5e == '\0' &&
            (dsp_set_tone_freq(1), DAT_00001c5e == '\0')) &&
           (dsp_set_tone_freq(2), DAT_00001c5e == '\0')))) &&
         ((((dsp_set_tone_gain(0), DAT_00001c5e == '\0' &&
            (dsp_set_tone_gain(1), DAT_00001c5e == '\0')) &&
           (dsp_set_tone_gain(2), DAT_00001c5e == '\0')) &&
          ((dsp_set_tone_type(0), DAT_00001c5e == '\0' &&
           (dsp_set_tone_type(1), DAT_00001c5e == '\0')))))))) &&
       ((dsp_set_tone_type(2), DAT_00001c5e == '\0' &&
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


// ===== dsp_status1_raw @ fff9d7f0 (16 bytes)

/* Returns shadow of reg 1 (0x1B636) */

undefined2 dsp_status1_raw(void)

{
  return DAT_0001b636;
}


// ===== dsp_fm_noise @ fff9d800 (56 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9d817) */
/* Returns 0x1C60 (doubled in modes 7/11, FM-N) */

byte dsp_fm_noise(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = vfo_mode(0);
  if (((iVar2 == 7) || (bVar1 = DAT_00001c60, iVar2 == 0xb)) &&
     (bVar1 = DAT_00001c60 << 1, 0xff < (uint)DAT_00001c60 * 2)) {
    bVar1 = 0xff;
  }
  return bVar1;
}


// ===== dsp_tone_detect @ fff9d838 (15 bytes)

/* Returns 0x1C61 */

undefined1 dsp_tone_detect(void)

{
  return DAT_00001c61;
}


// ===== dsp_comp_level @ fff9d857 (15 bytes)

/* Returns 0x1B6E2 */

undefined2 dsp_comp_level(void)

{
  return DAT_0001b6e2;
}


// ===== dsp_signal_level @ fff9d866 (16 bytes)

/* Returns shadow of reg 3 (0x1B63A) */

undefined2 dsp_signal_level(void)

{
  return DAT_0001b63a;
}


// ===== dsp_tune_offset @ fff9d895 (15 bytes)

/* Returns 0x1B6E4 */

undefined2 dsp_tune_offset(void)

{
  return DAT_0001b6e4;
}


// ===== dsp_reg_access @ fff9d8a4 (169 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9d94a) */
/* Blocking read/write of any DSP register (used by CAT SPD); write does not update the shadow */

undefined1 dsp_reg_access(undefined2 param_1,undefined2 *param_2,char param_3)

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
    dsp_link_poll();
  }
  DAT_0001b6de = param_1;
  if (param_3 == '\0') {
    dsp_send_frame(0x72);
    do {
      if (DAT_00001c5f != '\x01') {
        return 0;
      }
      iVar3 = dsp_check_reply(0x72);
    } while (iVar3 != 1);
    uVar2 = hex2word(iStack_14 + 1);
    *param_2 = uVar2;
    local_15 = 1;
  }
  else {
    DAT_0001b6e0 = *param_2;
    dsp_send_frame(0x77);
    do {
      local_15 = dsp_check_reply(0x77);
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

