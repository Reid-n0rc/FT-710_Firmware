// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff97c74 @ fff97c74 (131 bytes)

undefined1 FUN_fff97c74(void)

{
  char cVar1;
  undefined1 local_2;
  
  if (PTR_DAT_00025d38[0x1c1] == '\0') {
    local_2 = DAT_00009dc9;
  }
  else {
    cVar1 = PTR_DAT_00025d38[0x1c2];
    if (cVar1 == '\v') {
      local_2 = 3;
    }
    else if (cVar1 == '&') {
      local_2 = 8;
    }
    else if (cVar1 == '/') {
      local_2 = 0x11;
    }
    else if (cVar1 == 'T') {
      local_2 = 0x36;
    }
    else if (cVar1 == '9') {
      local_2 = 0x1b;
    }
    else if (cVar1 == 'F') {
      local_2 = 0x10;
    }
    else if (cVar1 == '8') {
      local_2 = 0x1a;
    }
    else {
      local_2 = DAT_00009dc9;
    }
  }
  return local_2;
}


// ===== FUN_fff97cf7 @ fff97cf7 (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97e1a) */

undefined1 FUN_fff97cf7(char param_1,byte *param_2)

{
  char cVar1;
  undefined4 *in_R14;
  undefined1 local_11;
  undefined1 local_10;
  char local_f;
  undefined1 local_e;
  
  if (param_1 == '\0') {
    *in_R14 = 1;
  }
  if (PTR_DAT_00025d38[0x405] == '\0') {
    if (in_R14 == (undefined4 *)0x0) {
      *param_2 = DAT_000060ca;
      local_f = DAT_00009dbf;
      local_10 = DAT_00009021;
    }
    else {
      *param_2 = DAT_000060c9;
      local_f = DAT_00009dbe;
      local_10 = DAT_0000901f;
    }
  }
  else if (in_R14 == (undefined4 *)0x0) {
    *param_2 = DAT_000060c9;
    local_f = DAT_00009dbe;
    local_10 = DAT_0000901f;
  }
  else {
    *param_2 = DAT_000060ca;
    local_f = DAT_00009dbf;
    local_10 = DAT_00009021;
  }
  if (local_f == '\x05') {
    cVar1 = FUN_fff96d94(local_10);
    *param_2 = cVar1 - 0x39;
    local_11 = 5;
  }
  else if (local_f == '\x02') {
    if (*param_2 < 0x84) {
      if (*param_2 < 0x75) {
        local_e = 2;
      }
      else {
        *param_2 = *param_2 + 0x21;
        local_e = 7;
      }
    }
    else {
      *param_2 = 199;
      local_e = 8;
    }
    local_11 = local_e;
  }
  else if (local_f == '\x03') {
    local_11 = 3;
  }
  else if (local_f == '\x04') {
    local_11 = 4;
  }
  else if (local_f == '\0') {
    local_11 = 0;
  }
  else {
    local_11 = 1;
  }
  return local_11;
}


// ===== FUN_fff97e1d @ fff97e1d (162 bytes)

undefined1 FUN_fff97e1d(char param_1)

{
  int iVar1;
  undefined1 local_3;
  
  local_3 = 0;
  if (PTR_DAT_00025d38[0x40d] == '\0') {
    if (param_1 == DAT_00009dbd) {
      iVar1 = FUN_fff9847e();
      if (iVar1 == 0) {
        local_3 = 0x20;
      }
      local_3 = FUN_fff97ebf(param_1,local_3);
    }
    else {
      if (PTR_DAT_00025d38[0x41d] == '\0') {
        local_3 = 0x20;
      }
      local_3 = FUN_fff97ebf(param_1,local_3);
    }
  }
  else if (param_1 == PTR_DAT_00025d38[0x40e]) {
    local_3 = FUN_fff97ebf(param_1,0);
  }
  else if (param_1 == DAT_00009dbd) {
    iVar1 = FUN_fff9847e();
    if (iVar1 == 0) {
      local_3 = 0x20;
    }
    local_3 = FUN_fff97ebf(param_1,local_3);
  }
  else {
    local_3 = FUN_fff97ebf(param_1,0x20);
  }
  return local_3;
}


// ===== FUN_fff97ebf @ fff97ebf (591 bytes)

byte FUN_fff97ebf(char param_1,byte param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char cStack_9;
  byte bStack_5;
  byte local_4;
  
  param_2 = param_2 & 0xf0;
  local_4 = param_2 | 0xd4;
  if (DAT_00009c5e == '\0') {
    if (DAT_00009dbd == '\0') {
      if (param_1 == '\x01') {
        local_4 = param_2 | 0xd7;
      }
    }
    else if (param_1 == '\0') {
      local_4 = param_2 | 0xd7;
    }
  }
  if (PTR_DAT_00025d38[0x418] == '\x01') {
    if ((DAT_00009dbd == param_1) && (PTR_DAT_00025d38[0x419] == '\x01')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) && (PTR_DAT_00025d38[0x1bc] == '\0')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      local_4 = local_4 & 0x3f;
    }
  }
  else {
    FUN_fff9810e(param_1);
    if (cStack_9 == '\0') {
      local_4 = local_4 & 0x7f;
    }
    if (DAT_00009c5e == '\x01') {
      cVar1 = PTR_DAT_00025d38[0x482];
      if (cVar1 == '\0') {
        uRam00000000 = 1;
      }
      if (DAT_00009dbd == '\0') {
        if ((cVar1 == '\0') || (param_1 != '\x01')) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_4 = local_4 & 0xf0 | 5;
        }
        if ((PTR_DAT_00025d38[0x482] == '\x01') && (param_1 == '\0')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          local_4 = local_4 & 0xf0 | 6;
        }
      }
      else {
        if ((cVar1 == '\0') || (param_1 != '\0')) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_4 = local_4 & 0xf0 | 5;
        }
        if ((PTR_DAT_00025d38[0x482] == '\x01') && (param_1 == '\x01')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          local_4 = local_4 & 0xf0 | 6;
        }
      }
    }
    if (DAT_00009dbd == '\0') {
      if ((PTR_DAT_00025d38[0x425] != '\0') && (param_1 == '\x01')) {
        local_4 = local_4 & 0xf0 | 9;
      }
    }
    else if ((PTR_DAT_00025d38[0x426] != '\0') && (param_1 == '\0')) {
      local_4 = local_4 & 0xf0 | 9;
    }
  }
  if (param_1 == '\0') {
    bStack_5 = DAT_00009d0e;
  }
  else {
    bStack_5 = DAT_00009d68;
  }
  iVar3 = FUN_fffc2d93(param_1);
  if ((iVar3 == 1) && ((bStack_5 & 0x80) != 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    local_4 = local_4 & 0xf0 | 1;
  }
  return local_4;
}


// ===== FUN_fff9810e @ fff9810e (172 bytes)

void FUN_fff9810e(char param_1,undefined4 param_2)

{
  undefined1 local_d;
  undefined1 *local_c;
  
  if (param_1 == '\0') {
    local_c = &DAT_00009d09;
    local_d = PTR_DAT_00025d38[0x425];
  }
  else {
    local_c = &DAT_00009d63;
    local_d = PTR_DAT_00025d38[0x426];
  }
  if (DAT_00020b3d == '\0') {
    FUN_fff981ba(param_1,local_c,local_d,param_2);
    return;
  }
  if (DAT_00009c5e == '\x01') {
    uRam00000001 = 1;
  }
  if (param_1 != DAT_00009dbd) {
    if (DAT_00009c5e == '\0') {
      FUN_fff981ba(param_1,local_c,local_d,param_2);
      return;
    }
    FUN_fff98258(param_1,local_c,local_d,param_2);
    return;
  }
  if (DAT_00009c5e == '\0') {
    FUN_fff98258(param_1,local_c,local_d,param_2);
    return;
  }
  FUN_fff981ba(param_1,local_c,local_d,param_2);
  return;
}


// ===== FUN_fff981ba @ fff981ba (158 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9820f) */
/* WARNING: Removing unreachable block (ram,0xfff981d4) */
/* WARNING: Removing unreachable block (ram,0xfff981df) */

void FUN_fff981ba(char param_1,int param_2,char param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined1 uStack_19;
  int iStack_14;
  
  FUN_fffb3b33();
  iStack_14 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                         *(undefined1 *)(param_2 + 0x4b)),
                                *(undefined1 *)(param_2 + 0x4c)),*(undefined1 *)(param_2 + 0x4d));
  if ((param_3 == '\x01') || (param_3 == '\x03')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    iStack_14 = iStack_14 +
                CONCAT11(*(undefined1 *)(param_2 + 0x48),*(undefined1 *)(param_2 + 0x49));
  }
  iVar2 = FUN_fffb4bba(param_1);
  if (iVar2 == 1) {
    if (param_1 == '\0') {
      uStack_19 = DAT_000060c9;
    }
    else {
      uStack_19 = DAT_000060ca;
    }
    iStack_14 = FUN_fff9cba4(iStack_14,uStack_19);
  }
  FUN_fff9ca42(iStack_14,param_4);
  return;
}


// ===== FUN_fff98258 @ fff98258 (82 bytes)

void FUN_fff98258(char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 uStack_15;
  undefined4 local_14;
  
  local_14 = *(undefined4 *)(PTR_DAT_00025d38 + 0x44c);
  iVar1 = FUN_fffb4bba(param_1);
  if (iVar1 == 1) {
    if (param_1 == '\0') {
      uStack_15 = DAT_000060c9;
    }
    else {
      uStack_15 = DAT_000060ca;
    }
    local_14 = FUN_fff9cba4(local_14,uStack_15);
  }
  FUN_fff9ca42(local_14,param_4);
  return;
}


// ===== FUN_fff982aa @ fff982aa (17 bytes)

void FUN_fff982aa(undefined1 param_1,undefined4 param_2)

{
  FUN_fff982bb(param_1,param_2);
  return;
}


// ===== FUN_fff982bb @ fff982bb (72 bytes)

void FUN_fff982bb(char param_1,undefined4 param_2)

{
  if (param_1 == DAT_00009dbd) {
    FUN_fff98303(param_1,param_2);
    return;
  }
  if (PTR_DAT_00025d38[0x41d] != '\x01') {
    FUN_fff98303(param_1,param_2);
    return;
  }
  FUN_fff98363(param_1,PTR_DAT_00025d38 + 0x40f,param_2);
  return;
}


// ===== FUN_fff98303 @ fff98303 (96 bytes)

void FUN_fff98303(char param_1,undefined4 param_2)

{
  undefined1 auStack_d [5];
  undefined4 local_8;
  char local_1;
  
  local_8 = param_2;
  local_1 = param_1;
  if (PTR_DAT_00025d38[0x40d] == '\0') {
    FUN_fff9810e(param_1,auStack_d);
    FUN_fff98363(local_1,auStack_d,local_8);
    return;
  }
  if (param_1 == PTR_DAT_00025d38[0x40e]) {
    FUN_fff98363(param_1,PTR_DAT_00025d38 + 0x40f,param_2);
    return;
  }
  FUN_fff9810e(param_1,auStack_d);
  FUN_fff98363(local_1,auStack_d,local_8);
  return;
}


// ===== FUN_fff98363 @ fff98363 (283 bytes)

void FUN_fff98363(char param_1,byte *param_2,byte *param_3)

{
  bool bVar1;
  int iVar2;
  byte bStack_d;
  
  if (param_1 == DAT_00009dbd) {
    iVar2 = FUN_fff9847e();
    if (iVar2 == 1) {
      if (PTR_DAT_00025d38[0x416] == '\x01') {
        bVar1 = (*param_2 & 0xf) != 0;
        if (bVar1) {
          bStack_d = *param_2 | 0xf0;
        }
        else {
          bStack_d = 0xff;
        }
        *param_3 = bStack_d;
        if ((param_2[1] & 0xf0) == 0) {
          bStack_d = param_2[1];
          if (!bVar1) {
            if ((bStack_d & 0xf) == 0) {
              bStack_d = 0xff;
            }
            else {
              bStack_d = param_2[1] | 0xf0;
            }
          }
        }
        else {
          bStack_d = param_2[1];
        }
        param_3[1] = bStack_d;
        param_3[2] = 0xff;
        param_3[3] = param_2[3] | 0xf0;
      }
      else {
        *param_3 = 0xff;
        param_3[1] = 0xff;
        param_3[2] = param_2[2];
        param_3[3] = param_2[3];
      }
    }
    else {
      *param_3 = *param_2;
      param_3[1] = param_2[1];
      param_3[2] = param_2[2];
      param_3[3] = param_2[3];
    }
    param_3[4] = param_2[4];
    return;
  }
  *param_3 = *param_2;
  param_3[1] = param_2[1];
  param_3[2] = param_2[2];
  param_3[3] = param_2[3];
  param_3[4] = param_2[4];
  return;
}


// ===== FUN_fff9847e @ fff9847e (32 bytes)

bool FUN_fff9847e(void)

{
  return PTR_DAT_00025d38[0x423] != '\0';
}


// ===== FUN_fff9849e @ fff9849e (136 bytes)

undefined1 FUN_fff9849e(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d38[0x67] == '\0') {
    local_2 = FUN_fffb6ea7();
  }
  else if (DAT_00009c5b == '\x05') {
    if (DAT_00020b41 == '\x02') {
      local_2 = FUN_fffb6e3f();
    }
    else {
      local_2 = FUN_fffb6e30();
    }
  }
  else if (DAT_00009c5b == '\x01') {
    local_2 = FUN_fffb6e98();
  }
  else if (DAT_00009c5b == '\x02') {
    local_2 = FUN_fffb6e21();
  }
  else if (DAT_00009c5b == '\x03') {
    local_2 = FUN_fffb6e03();
  }
  else if (DAT_00009c5b == '\x04') {
    local_2 = FUN_fffb6e12();
  }
  else if (DAT_00009c5b == '\0') {
    local_2 = FUN_fffb6e6a();
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fff98526 @ fff98526 (64 bytes)

byte FUN_fff98526(int param_1)

{
  undefined1 local_6;
  
  local_6 = 0;
  if ((*(byte *)(param_1 + 6) & 0x10) != 0) {
    local_6 = 0x10;
  }
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    local_6 = local_6 | 8;
  }
  if (DAT_00009c62 == '\x01') {
    local_6 = local_6 | 4;
  }
  return DAT_00009c61 | local_6;
}


// ===== FUN_fff98566 @ fff98566 (95 bytes)

void FUN_fff98566(undefined1 *param_1)

{
  undefined4 local_8;
  
  if (PTR_DAT_00025d38[0x67] == '\x01') {
    local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x458);
  }
  else if (DAT_00009dbd == '\0') {
    local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x450);
  }
  else {
    local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x454);
  }
  *param_1 = (char)((uint)local_8 >> 0x18);
  param_1[1] = (char)((uint)local_8 >> 0x10);
  param_1[2] = (char)((uint)local_8 >> 8);
  param_1[3] = (undefined1)local_8;
  return;
}


// ===== FUN_fff985c5 @ fff985c5 (48 bytes)

void FUN_fff985c5(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 local_8;
  
  uVar1 = *(undefined4 *)(PTR_DAT_00025d38 + 0x44c);
  *param_1 = (char)((uint)uVar1 >> 0x18);
  param_1[1] = (char)((uint)uVar1 >> 0x10);
  param_1[2] = (char)((uint)uVar1 >> 8);
  local_8 = (undefined1)uVar1;
  param_1[3] = local_8;
  return;
}


// ===== FUN_fff985f5 @ fff985f5 (116 bytes)

void FUN_fff985f5(undefined1 *param_1)

{
  int iVar1;
  undefined4 local_8;
  
  if (PTR_DAT_00025d38[0x67] == '\x01') {
    local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x44c);
  }
  else {
    iVar1 = FUN_fff98669();
    if (iVar1 == 0) {
      local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x458);
    }
    else if (DAT_00009dbd == '\0') {
      local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x450);
    }
    else {
      local_8 = *(undefined4 *)(PTR_DAT_00025d38 + 0x454);
    }
  }
  *param_1 = (char)((uint)local_8 >> 0x18);
  param_1[1] = (char)((uint)local_8 >> 0x10);
  param_1[2] = (char)((uint)local_8 >> 8);
  param_1[3] = (undefined1)local_8;
  return;
}


// ===== FUN_fff98669 @ fff98669 (40 bytes)

undefined1 FUN_fff98669(void)

{
  undefined1 local_2;
  
  if (PTR_DAT_00025d38[0x67] == '\x01') {
    local_2 = 1;
  }
  else {
    local_2 = DAT_00009b15;
  }
  return local_2;
}


// ===== FUN_fff98691 @ fff98691 (79 bytes)

void FUN_fff98691(int param_1)

{
  byte local_a;
  uint local_8;
  
  if (DAT_00009c35 == '\x02') {
    local_8 = FUN_fffb4ebe(2);
  }
  else {
    local_8 = DAT_00020f60;
  }
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    *(char *)((uint)local_a + param_1) = (char)(local_8 >> ((3 - local_a & 3) << 3));
  }
  return;
}


// ===== FUN_fff986e0 @ fff986e0 (71 bytes)

void FUN_fff986e0(void)

{
  if (PTR_DAT_00025d38[0xb8] == PTR_DAT_00025d38[0xb9]) {
    return;
  }
  PTR_DAT_00025d38[0xb9] = PTR_DAT_00025d38[0xb8];
  DAT_00001456 = 100;
  DAT_00001457 = PTR_DAT_00025d38[0xb8];
  DAT_0001b628 = 3;
  FUN_fff9c5b2(3);
  return;
}


// ===== FUN_fff98727 @ fff98727 (112 bytes)

void FUN_fff98727(char param_1,char param_2)

{
  byte local_3;
  
  if (param_1 == '\b') {
    local_3 = 0x20;
  }
  else if (param_1 == '\x02') {
    local_3 = 0x40;
  }
  else if (param_1 == '\x03') {
    local_3 = 0x10;
  }
  else if (param_1 == '\x04') {
    local_3 = 8;
  }
  else if (param_1 == '\x05') {
    local_3 = 4;
  }
  else if (param_1 == '\x06') {
    local_3 = 2;
  }
  else if (param_1 == '\a') {
    local_3 = 1;
  }
  else {
    if (param_1 != '\x01') {
      return;
    }
    local_3 = 0x80;
  }
  if (param_2 != '\0') {
    PTR_DAT_00025d38[0x34] = local_3 | PTR_DAT_00025d38[0x34];
    return;
  }
  PTR_DAT_00025d38[0x34] = ~local_3 & PTR_DAT_00025d38[0x34];
  return;
}


// ===== FUN_fff98797 @ fff98797 (210 bytes)

void FUN_fff98797(void)

{
  int iVar1;
  
  DAT_00001456 = 0x7f;
  DAT_00001457 = PTR_DAT_00025d38[0x35] & 0x7f;
  DAT_00001458 = 0x9b;
  DAT_00001459 = 0xba;
  DAT_0000145a = 0xf6;
  DAT_0000145b = 0x38;
  DAT_0000145c = 0xff;
  DAT_0000145d = 0x25;
  DAT_0000145e = 0x73;
  DAT_0000145f = 0x1f;
  DAT_0001b628 = 0xb;
  FUN_fff9c5b2(0xb);
  if (PTR_DAT_00025d38[0x35] == -0x70) {
    FUN_fffb237a(0x14,2000);
    do {
      iVar1 = FUN_fffb23f3(0x14);
    } while (iVar1 == 0);
  }
  else if (PTR_DAT_00025d38[0x35] == '\x11') {
    DAT_00009dc5 = 1;
    FUN_fffb02af();
  }
  else {
    DAT_00009dc5 = 0;
    FUN_fffb02af();
  }
  FUN_fffb3e55();
  return;
}


// ===== FUN_fff98869 @ fff98869 (51 bytes)

void FUN_fff98869(void)

{
  DAT_00001456 = 0x7c;
  DAT_00001457 = 0;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  FUN_fff9c5b2(5);
  return;
}


// ===== FUN_fff9889c @ fff9889c (86 bytes)

void FUN_fff9889c(void)

{
  char cVar1;
  
  DAT_00001456 = 0x7b;
  cVar1 = PTR_DAT_00025d38[0x82];
  if (cVar1 == '\x01') {
    PTR_DAT_00025d38[0x82] = 0;
  }
  else {
    PTR_DAT_00025d38[0x82] = 1;
  }
  DAT_00001457 = cVar1 != '\x01';
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  FUN_fff9c5b2(5);
  return;
}


// ===== FUN_fff988f2 @ fff988f2 (51 bytes)

void FUN_fff988f2(void)

{
  DAT_00001456 = 0x7a;
  DAT_00001457 = 0;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  FUN_fff9c5b2(5);
  return;
}


// ===== FUN_fff98925 @ fff98925 (42 bytes)

void FUN_fff98925(void)

{
  int iVar1;
  
  FUN_fff9894f();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0xe2);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xe3;
  FUN_fff9c5b2(0xe3);
  return;
}


// ===== FUN_fff9894f @ fff9894f (638 bytes)

void FUN_fff9894f(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
  DAT_00001741 = 0x70;
  FUN_fff98cd3();
  switch(PTR_DAT_00025d38[0xbb]) {
  case 0:
    FUN_fff98cec(0xfff80000);
    return;
  case 1:
    DAT_000017d9 = 3;
    DAT_000017da = 2;
    DAT_000017db = PTR_DAT_00025d38[0xbd];
    DAT_000017dc = 0;
    DAT_000017dd = 0;
    DAT_000017de = 0xe6;
    DAT_000017df = 0;
    DAT_000017e0 = 0xb7;
    puVar1 = &DAT_000017e1;
    puVar2 = &DAT_fff80016;
    for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    return;
  case 2:
    FUN_fff98d5b(&DAT_fff8002c);
    return;
  case 3:
    FUN_fff98dca(&DAT_fff80058);
    return;
  case 4:
    FUN_fff98dca(&DAT_fff8006e);
    return;
  case 5:
    FUN_fff98d5b(&DAT_fff80084);
    return;
  case 6:
    FUN_fff98dca(&DAT_fff800b0);
    return;
  case 7:
    DAT_000017d9 = 3;
    DAT_000017da = 0;
    DAT_000017db = PTR_DAT_00025d38[0xbd];
    DAT_000017dc = 0;
    DAT_000017dd = 0;
    DAT_000017de = 0xe6;
    DAT_000017df = 0;
    DAT_000017e0 = 0xb7;
    puVar1 = &DAT_000017e1;
    puVar2 = &DAT_fff800c6;
    for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    return;
  case 8:
    FUN_fff98dca(&DAT_fff800dc);
    return;
  case 9:
    DAT_000017d9 = 3;
    DAT_000017da = 0;
    DAT_000017db = PTR_DAT_00025d38[0xbd];
    DAT_000017dc = 0;
    DAT_000017dd = 0;
    DAT_000017de = 0xe6;
    DAT_000017df = 0;
    DAT_000017e0 = 0xb7;
    puVar1 = &DAT_000017e1;
    puVar2 = &DAT_fff800f2;
    for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = puVar2 + 1;
    }
    return;
  case 10:
    FUN_fff98dca(&DAT_fff80108);
    return;
  case 0xb:
    FUN_fff98dca(&DAT_fff8011e);
    return;
  case 0xc:
    FUN_fff98dca(&DAT_fff80134);
    return;
  case 0xd:
    FUN_fff98dca(&DAT_fff8014a);
    return;
  case 0xe:
    FUN_fff98cec(&DAT_fff80160);
    return;
  case 0xf:
    FUN_fff98dca(&DAT_fff80176);
    return;
  case 0x10:
    FUN_fff98dca(&DAT_fff8018c);
    return;
  case 0x11:
    FUN_fff98dca(&DAT_fff801a2);
    return;
  case 0x12:
    FUN_fff98dca(&DAT_fff801b8);
    return;
  case 0x13:
    FUN_fff98dca(&DAT_fff801ce);
    return;
  case 0x14:
    FUN_fff98dca(&DAT_fff801e4);
    return;
  case 0x15:
    FUN_fff98dca(&DAT_fff801fa);
    return;
  case 0x16:
    FUN_fff98dca(&DAT_fff80210);
    return;
  case 0x17:
    FUN_fff98cec(&DAT_fff80252);
    return;
  case 0x18:
    FUN_fff98dca(&DAT_fff80176);
    return;
  case 0x19:
    FUN_fff98dca(&DAT_fff80226);
    return;
  case 0x1a:
    FUN_fff98dca(&DAT_fff8023c);
    return;
  default:
    return;
  }
}


// ===== FUN_fff98bcd @ fff98bcd (82 bytes)

void FUN_fff98bcd(void)

{
  int iVar1;
  
  PTR_DAT_00025d38[0x87] = 0;
  FUN_fff98c1f();
  iVar1 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,
                       *(undefined2 *)(*(ushort *)(PTR_DAT_00025d38 + 0x1e2) - 1));
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = *(undefined2 *)(PTR_DAT_00025d38 + 0x1e2);
  FUN_fff9c5b2(*(undefined2 *)(PTR_DAT_00025d38 + 0x1e2));
  return;
}


// ===== FUN_fff98c1f @ fff98c1f (86 bytes)

void FUN_fff98c1f(void)

{
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
  DAT_00001741 = PTR_DAT_00025d38[0x1e0];
  DAT_00001742 = PTR_DAT_00025d38[0x1e4];
  if ((PTR_DAT_00025d38[0x1e4] & 0xf0) == 0) {
    return;
  }
  FUN_fff98c75(2);
  return;
}


// ===== FUN_fff98c75 @ fff98c75 (94 bytes)

void FUN_fff98c75(ushort param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = (byte)PTR_DAT_00025d38[0x1e4] - 1 & 0xf;
  if ((1 < uVar3 - 6) && (uVar3 != 4)) {
    if (uVar3 < 4) {
      uVar3 = (uint)*(ushort *)(PTR_DAT_00025d38 + 0x1e2);
      puVar2 = PTR_DAT_00025d38 + 0x1e5;
      puVar1 = &DAT_00001741 + param_1;
      while (uVar3 = uVar3 - 1, uVar3 != 0) {
        *puVar1 = *puVar2;
        puVar1 = puVar1 + 1;
        puVar2 = puVar2 + 1;
      }
      return;
    }
    return;
  }
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(PTR_DAT_00025d38 + 0x1e5);
  return;
}


// ===== FUN_fff98cd3 @ fff98cd3 (25 bytes)

void FUN_fff98cd3(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  FUN_fff96455();
  puVar2 = &DAT_000016a1;
  puVar1 = &DAT_00001742;
  for (iVar3 = 0x97; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ===== FUN_fff98cec @ fff98cec (111 bytes)

void FUN_fff98cec(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_000017d9 = 3;
  DAT_000017da = 0;
  DAT_000017db = PTR_DAT_00025d38[0xbd];
  DAT_000017dc = 0;
  DAT_000017dd = 0;
  DAT_000017de = 0xe6;
  DAT_000017df = 0;
  DAT_000017e0 = 0xb7;
  puVar1 = &DAT_000017e1;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_fff98d5b @ fff98d5b (111 bytes)

void FUN_fff98d5b(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_000017d9 = 1;
  DAT_000017da = 4;
  DAT_000017db = PTR_DAT_00025d38[0xbd];
  DAT_000017dc = 0;
  DAT_000017dd = 0;
  DAT_000017de = 0xe6;
  DAT_000017df = 0;
  DAT_000017e0 = 0xb7;
  puVar1 = &DAT_000017e1;
  for (iVar2 = 0x2c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_fff98dca @ fff98dca (111 bytes)

void FUN_fff98dca(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_000017d9 = 3;
  DAT_000017da = 4;
  DAT_000017db = PTR_DAT_00025d38[0xbd];
  DAT_000017dc = 0;
  DAT_000017dd = 0;
  DAT_000017de = 0xe6;
  DAT_000017df = 0;
  DAT_000017e0 = 0xb7;
  puVar1 = &DAT_000017e1;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_fff98e39 @ fff98e39 (31 bytes)

void FUN_fff98e39(void)

{
  PTR_DAT_00025d38[0x89] = 0;
  FUN_fff98e96();
  DAT_0001b628 = 0x37;
  FUN_fff9c5b2(0x37);
  return;
}


// ===== FUN_fff98e58 @ fff98e58 (31 bytes)

void FUN_fff98e58(void)

{
  PTR_DAT_00025d38[0x8a] = 0;
  FUN_fff98ec9();
  DAT_0001b628 = 0x37;
  FUN_fff9c5b2(0x37);
  return;
}


// ===== FUN_fff98e77 @ fff98e77 (31 bytes)

void FUN_fff98e77(void)

{
  PTR_DAT_00025d38[0x8b] = 0;
  FUN_fff98eca();
  DAT_0001b628 = 0x37;
  FUN_fff9c5b2(0x37);
  return;
}


// ===== FUN_fff98e96 @ fff98e96 (51 bytes)

void FUN_fff98e96(void)

{
  DAT_00001456 = 0x23;
  DAT_00001457 = (char)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x1be) >> 8) + '\x01';
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  return;
}


// ===== FUN_fff98ec9 @ fff98ec9 (1 bytes)

void FUN_fff98ec9(void)

{
  return;
}


// ===== FUN_fff98eca @ fff98eca (1 bytes)

void FUN_fff98eca(void)

{
  return;
}


// ===== FUN_fff98ecb @ fff98ecb (177 bytes)

void FUN_fff98ecb(void)

{
  bool bVar1;
  int iVar2;
  
  PTR_DAT_00025d38[0x8c] = 0;
  PTR_DAT_00025d38[0x1c0] = 0;
  if ((PTR_DAT_00025d38[0x1c2] == -1) || ((byte)PTR_DAT_00025d38[0x1c2] < 0x1e)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_fff98fb1();
    iVar2 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0x9f);
    if (iVar2 == 1) {
      DAT_0001b628 = 0xa0;
      FUN_fff9c5b2(0xa0);
      return;
    }
  }
  else if ((byte)PTR_DAT_00025d38[0x1c2] < 0x5f) {
    FUN_fff99297();
    iVar2 = FUN_fff9c667(&DAT_00001741,&DAT_00001456,0xa2);
    if (iVar2 == 1) {
      DAT_0001b628 = 0xa3;
      FUN_fff9c5b2(0xa3);
      return;
    }
  }
  return;
}


// ===== FUN_fff98f7c @ fff98f7c (53 bytes)

void FUN_fff98f7c(void)

{
  FUN_fff9a06e(1,DAT_0001b3d6);
  DAT_0001b628 = 0xa3;
  FUN_fff9c5b2(0xa3);
  PTR_DAT_00025d38[0x99] = 0;
  PTR_DAT_00025d38[0x9a] = 1;
  return;
}


// ===== FUN_fff98fb1 @ fff98fb1 (622 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99181) */
/* WARNING: Removing unreachable block (ram,0xfff9917b) */

void FUN_fff98fb1(void)

{
  byte bVar1;
  int iVar2;
  bool bStack_9;
  byte *pbStack_8;
  char cStack_1;
  
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
  DAT_00001741 = 0x30;
  FUN_fff98cd3();
  DAT_000017d9 = PTR_DAT_00025d38[0x1c2];
  if (PTR_DAT_00025d38[0x1c2] != -1) {
    if (DAT_00009dbd == '\0') {
      pbStack_8 = &DAT_00009d09;
    }
    else {
      pbStack_8 = &DAT_00009d63;
    }
    bStack_9 = DAT_00009dbd != '\0';
    switch(PTR_DAT_00025d38[0x1c2]) {
    case 0:
      DAT_000017da = DAT_00009c5b;
      return;
    case 1:
      DAT_000017da = pbStack_8[3] & 3;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 2:
      if ((pbStack_8[5] & 3) == 0) {
        cStack_1 = '\0';
      }
      else {
        cStack_1 = (pbStack_8[5] & 3) - 1;
      }
      DAT_000017da = cStack_1;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 3:
      bVar1 = FUN_fff9921f(pbStack_8);
      DAT_000017da = bVar1 >> 7;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 4:
      bVar1 = FUN_fff9921f(pbStack_8);
      if ((bVar1 & 0x40) == 0) {
        cStack_1 = '\0';
      }
      else {
        cStack_1 = (bVar1 >> 4 & 3) + 1;
      }
      DAT_000017da = cStack_1;
      DAT_000017db = PTR_DAT_00025d38[0x1c3];
      return;
    case 5:
      DAT_000017da = *pbStack_8 & 0xf;
      DAT_000017db = 0;
      DAT_000017dc = PTR_DAT_00025d38[0x424];
      return;
    case 6:
      DAT_000017da = FUN_fff9772f(bStack_9);
      return;
    case 7:
    case 8:
      DAT_000017da = 0;
      return;
    case 9:
      DAT_000017da = DAT_00009c39;
      return;
    case 10:
      DAT_000017da = DAT_00009c3a << 6 | DAT_00009c3b << 4 | DAT_00009c3c;
      return;
    case 0xb:
      DAT_000017da = DAT_00009be8;
      DAT_000017db = 0;
      DAT_000017dc = PTR_DAT_00025d38[0x424];
      return;
    case 0xc:
      DAT_000017da = PTR_DAT_00025d38[0x1dc];
      DAT_000017db = 0;
      DAT_000017dc = PTR_DAT_00025d38[0x424];
      return;
    case 0xd:
      iVar2 = FUN_fffc4f8f();
      if (iVar2 == 0) {
        DAT_000017da = DAT_00009c5a;
        return;
      }
      DAT_000017da = 5;
      return;
    }
  }
  return;
}


// ===== FUN_fff9921f @ fff9921f (120 bytes)

byte FUN_fff9921f(byte *param_1)

{
  uint uVar1;
  byte local_7;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 == 0xe) {
LAB_fff99289:
    local_7 = param_1[0x29];
  }
  else {
    if (uVar1 - 2 < 2) {
      return param_1[0x15];
    }
    if (uVar1 - 4 < 2) {
      return param_1[0x33];
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff99289;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return param_1[0x1f];
        }
        if (1 < uVar1) {
          return 0;
        }
        return param_1[0xb];
      }
    }
    local_7 = param_1[0x3d];
  }
  return local_7;
}


// ===== FUN_fff99297 @ fff99297 (478 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fff99297(void)

{
  char cVar1;
  
  FUN_fff9c655(0x98,&DAT_000016a0);
  FUN_fff9c655(0x24a,&DAT_00001741);
  DAT_00001741 = 0x31;
  FUN_fff98cd3();
  DAT_000017d9 = PTR_DAT_00025d38[0x1c2] + -0x1e;
  DAT_000017e2 = 0x20;
  _DAT_000017de = 0x20202020;
  _DAT_000017da = 0x20202020;
  cVar1 = PTR_DAT_00025d38[0x1c2];
  if (cVar1 == '^') {
    FUN_fff9a044(0x99);
    return;
  }
  if (cVar1 == '\x1f') {
    FUN_fff9959f(0x99);
    return;
  }
  if (cVar1 == '\"') {
    FUN_fff99e15(0x99);
    return;
  }
  if (cVar1 == '#') {
    FUN_fff9a00f(0x99);
    return;
  }
  if (cVar1 == '$') {
    FUN_fff99abf(0x99);
    return;
  }
  if (cVar1 == '%') {
    FUN_fff99837(0x99);
    return;
  }
  if (cVar1 == '&') {
    FUN_fff99ddb(0x99);
    return;
  }
  if (cVar1 == '\'') {
    FUN_fff997df(0x99);
    return;
  }
  if (cVar1 == '(') {
    FUN_fff99a8a(0x99);
    return;
  }
  if (cVar1 == ')') {
    FUN_fff996e2(0x99);
    return;
  }
  if (cVar1 == '*') {
    FUN_fff99717(0x99);
    return;
  }
  if (cVar1 == '+') {
    FUN_fff9978c(0x99);
    return;
  }
  if (cVar1 == ',') {
    FUN_fff995cc(0x99);
    return;
  }
  if (cVar1 == '-') {
    FUN_fff9960e(0x99);
    return;
  }
  if (cVar1 == '/') {
    FUN_fff99d82(0x99);
    return;
  }
  if (cVar1 == '0') {
    FUN_fff998e2(0x99);
    return;
  }
  if (cVar1 == '1') {
    FUN_fff9992a(0x99);
    return;
  }
  if (cVar1 == '2') {
    FUN_fff99989(0x99);
    return;
  }
  if (cVar1 == '3') {
    FUN_fff999e3(0x99);
    return;
  }
  if (cVar1 == '8') {
    FUN_fff99b70(0x99);
    return;
  }
  if (cVar1 == '9') {
    FUN_fff99ba5(0x99);
    return;
  }
  if (cVar1 == ':') {
    FUN_fff99d42(0x99);
    return;
  }
  if (cVar1 == 'C') {
    FUN_fff99bfe(0x99);
    return;
  }
  if (cVar1 == 'D') {
    FUN_fff99ca2(0x99);
    return;
  }
  if (cVar1 == 'E') {
    FUN_fff99cf2(0x99);
    return;
  }
  if (cVar1 == 'F') {
    FUN_fff99d48(0x99);
    return;
  }
  if (cVar1 == 'U') {
    FUN_fff99c58(0x99);
    return;
  }
  if (cVar1 == 'X') {
    FUN_fff99a29(0x99);
    return;
  }
  if (cVar1 != '\x1e') {
    return;
  }
  FUN_fff99475(0x99);
  return;
}


// ===== FUN_fff99475 @ fff99475 (298 bytes)

/* WARNING: Removing unreachable block (ram,0xfff99588) */
/* WARNING: Removing unreachable block (ram,0xfff994d7) */
/* WARNING: Removing unreachable block (ram,0xfff99568) */
/* WARNING: Removing unreachable block (ram,0xfff9953b) */

void FUN_fff99475(ushort param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  ushort uStack_6;
  undefined1 uStack_4;
  
  *(undefined4 *)(&DAT_00001745 + param_1) = 0x4264302e;
  *(undefined4 *)(&DAT_00001741 + param_1) = 0x20202020;
  pbVar3 = (byte *)FUN_fff9c6ab();
  bVar1 = *pbVar3;
  if (bVar1 == 0x3c) {
    (&DAT_00001744)[param_1] = 0x30;
    return;
  }
  if (bVar1 < 0x3d) {
    uStack_4 = 0x2d;
  }
  else {
    uStack_4 = 0x2b;
  }
  uStack_6 = (ushort)bVar1 * 5 - 300;
  if (bVar1 < 0x3c) {
    uStack_6 = ~uStack_6 + 1;
  }
  if ((uint)uStack_6 == ((uStack_6 / 10) * 10 & 0xff)) {
    (&DAT_00001746)[param_1] = 0x30;
  }
  else {
    (&DAT_00001746)[param_1] = 0x35;
  }
  if (uStack_6 < 10) {
    (&DAT_00001743)[param_1] = uStack_4;
    (&DAT_00001744)[param_1] = 0x30;
    return;
  }
  if (uStack_6 < 100) {
    (&DAT_00001743)[param_1] = uStack_4;
    (&DAT_00001744)[param_1] = (char)(uStack_6 / 10) + '0';
    return;
  }
  if (999 < uStack_6) {
    return;
  }
  (&DAT_00001742)[param_1] = uStack_4;
  cVar2 = (char)(uStack_6 / 100);
  (&DAT_00001743)[param_1] = cVar2 + '0';
  (&DAT_00001744)[param_1] = (char)((int)((uint)uStack_6 - (uint)(byte)(cVar2 * 'd')) / 10) + '0';
  return;
}


// ===== FUN_fff9959f @ fff9959f (45 bytes)

/* WARNING: Removing unreachable block (ram,0xfff995b0) */

void FUN_fff9959f(ushort param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_00009be6;
  *(undefined4 *)(&DAT_00001745 + param_1) = *(undefined4 *)(&DAT_fff80328 + uVar1 * 8);
  *(undefined4 *)(&DAT_00001741 + param_1) = *(undefined4 *)(&DAT_fff80324 + uVar1 * 8);
  return;
}


// ===== FUN_fff995cc @ fff995cc (66 bytes)

void FUN_fff995cc(ushort param_1)

{
  undefined1 uVar1;
  byte bVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  uVar1 = FUN_fffb4062();
  bVar2 = FUN_fff99e4a(uVar1,3,&DAT_000019ca);
  (&DAT_00001748)[param_1] = 0x57;
  uVar5 = (uint)bVar2;
  puVar3 = &DAT_00001748 + (param_1 - uVar5);
  puVar4 = &DAT_000019ca;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = *puVar4;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ===== FUN_fff9960e @ fff9960e (91 bytes)

void FUN_fff9960e(ushort param_1)

{
  byte bVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  char cStack_3;
  
  pcVar2 = (char *)FUN_fff99669();
  if (pcVar2 == (char *)0x0) {
    cStack_3 = '\0';
  }
  else {
    cStack_3 = *pcVar2;
  }
  if (cStack_3 != '\0') {
    bVar1 = FUN_fff99e4a(cStack_3,3,&DAT_000019d2);
    uVar5 = (uint)bVar1;
    puVar3 = &DAT_00001749 + (param_1 - uVar5);
    puVar4 = &DAT_000019d2;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar3 = *puVar4;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    return;
  }
  (&DAT_00001748)[param_1] = 0x46;
  *(undefined2 *)(&DAT_00001746 + param_1) = 17999;
  return;
}


// ===== FUN_fff99669 @ fff99669 (121 bytes)

void FUN_fff99669(void)

{
  FUN_fffb3196(1);
  return;
}

