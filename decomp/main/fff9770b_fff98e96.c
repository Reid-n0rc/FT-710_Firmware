// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff9770b @ fff9770b (36 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97719) */

byte FUN_fff9770b(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = DAT_00009c35 << 6;
  bVar2 = scope_span_index(param_1);
  return bVar2 | bVar1;
}


// ===== scope_span_index @ fff9772f (85 bytes)

/* Index into span table 0xFFF89D24 */

undefined1 scope_span_index(undefined1 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 uStack_9;
  
  uVar2 = vfo_freq_clar(0,param_1);
  bVar1 = freq_range_index(uVar2);
  if (bVar1 == 0xff) {
    uStack_9 = 0;
  }
  else if (DAT_00009c35 == '\x02') {
    uStack_9 = (&DAT_00009c4c)[bVar1];
  }
  else {
    uStack_9 = (&DAT_00009c3e)[bVar1];
  }
  return uStack_9;
}


// ===== range_cmp3 @ fff97784 (47 bytes)

/* 0 if v<lo, 1 if v>hi, else 2 */

undefined1 range_cmp3(uint *param_1,uint *param_2)

{
  undefined1 local_a;
  
  if (*param_1 < *param_2) {
    local_a = 0;
  }
  else if (param_2[1] < *param_1) {
    local_a = 1;
  }
  else {
    local_a = 2;
  }
  return local_a;
}


// ===== FUN_fff977b3 @ fff977b3 (120 bytes)

void FUN_fff977b3(undefined1 *param_1,byte *param_2)

{
  uint uVar1;
  undefined2 local_a;
  
  local_a = 0;
  uVar1 = *param_2 & 0xf;
  if (uVar1 == 0xe) {
LAB_fff97816:
    local_a = 0xc80;
  }
  else {
    if (uVar1 - 2 < 2) {
      local_a = 500;
      goto LAB_fff9781b;
    }
    if (uVar1 - 4 < 2) {
      local_a = 9000;
      goto LAB_fff9781b;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97816;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          local_a = 500;
        }
        else if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          local_a = 3000;
        }
        goto LAB_fff9781b;
      }
    }
    local_a = 16000;
  }
LAB_fff9781b:
  *param_1 = (char)((ushort)local_a >> 8);
  param_1[1] = (char)local_a;
  return;
}


// ===== FUN_fff9782b @ fff9782b (192 bytes)

void FUN_fff9782b(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = swtimer_expired(0x28);
  if (iVar1 == 1) {
    swtimer_start(0x28,100);
    if (PTR_DAT_00025d38[0x67] == '\x01') {
      DAT_0001ff1a = 0;
    }
    else {
      DAT_0001ff1a = dsp_tune_offset();
    }
    if (DAT_0001ff1a < -99) {
      DAT_0001ff1a = -99;
    }
    else if (99 < DAT_0001ff1a) {
      DAT_0001ff1a = 99;
    }
    DAT_0001ff1a = DAT_0001ff1a + 0xc;
    if (DAT_0001ff1a < 0x19) {
      if (DAT_0001ff1a < 0) {
        DAT_0001ff1a = 0;
      }
    }
    else {
      DAT_0001ff1a = 0;
    }
  }
  *param_1 = (&DAT_fff804de)[DAT_0001ff1a];
  return;
}


// ===== FUN_fff978eb @ fff978eb (116 bytes)

void FUN_fff978eb(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2 & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x16);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x34);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97954;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x20);
          return;
        }
        if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          *param_1 = *(undefined2 *)(param_2 + 0xc);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x3e);
    return;
  }
LAB_fff97954:
  *param_1 = *(undefined2 *)(param_2 + 0x2a);
  return;
}


// ===== FUN_fff9795f @ fff9795f (116 bytes)

void FUN_fff9795f(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2 & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x18);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x36);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff979c8;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x22);
          return;
        }
        if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          *param_1 = *(undefined2 *)(param_2 + 0xe);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x40);
    return;
  }
LAB_fff979c8:
  *param_1 = *(undefined2 *)(param_2 + 0x2c);
  return;
}


// ===== FUN_fff979d3 @ fff979d3 (113 bytes)

void FUN_fff979d3(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  undefined2 uStack_a;
  byte *local_8;
  undefined2 *local_4;
  
  uVar1 = (uint)(*param_2 & 0xf);
  if (3 < uVar1) {
    if (uVar1 == 4) {
      *param_1 = *(undefined2 *)(param_2 + 0x38);
      return;
    }
    if (uVar1 == 5) {
      *(undefined1 *)param_1 = 0x17;
      *(undefined1 *)((int)param_1 + 1) = 0x70;
      return;
    }
    if (uVar1 == 6) {
LAB_fff97a2d:
      *param_1 = *(undefined2 *)(param_2 + 0x42);
      return;
    }
    if (uVar1 == 7) {
LAB_fff97a36:
      *(undefined1 *)param_1 = 0x3e;
      *(undefined1 *)((int)param_1 + 1) = 0x80;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 == 10) goto LAB_fff97a2d;
      if (uVar1 == 0xb) goto LAB_fff97a36;
      if (2 < uVar1 - 0xc) {
        return;
      }
    }
  }
  local_8 = param_2;
  local_4 = param_1;
  FUN_fffc4e4f(&uStack_a);
  *local_4 = uStack_a;
  return;
}


// ===== FUN_fff97a44 @ fff97a44 (120 bytes)

void FUN_fff97a44(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(*param_2 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x1c);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x3a);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97ab1;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x26);
          return;
        }
        if (uVar1 < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x12);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x44);
    return;
  }
LAB_fff97ab1:
  *param_1 = *(undefined2 *)(param_2 + 0x30);
  return;
}


// ===== FUN_fff97abc @ fff97abc (191 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97af2) */
/* WARNING: Removing unreachable block (ram,0xfff97b1d) */

byte FUN_fff97abc(undefined4 param_1)

{
  int iVar1;
  undefined2 uStack_a;
  undefined1 auStack_8 [2];
  byte local_6;
  undefined4 local_4;
  
  if (PTR_DAT_00025d38[0x70] == '\0') {
    PTR_DAT_00025d38[0x71] = 1;
    PTR_DAT_00025d38[0x72] = 0;
  }
  local_6 = PTR_DAT_00025d38[0x70] << 7;
  if (PTR_DAT_00025d38[0x71] != '\0') {
    local_6 = local_6 | 0x40;
  }
  local_6 = PTR_DAT_00025d38[0x73] | PTR_DAT_00025d38[0x47a] << 2 | local_6;
  local_4 = param_1;
  FUN_fff979d3(auStack_8,param_1);
  FUN_fff977b3(&uStack_a,local_4);
  iVar1 = FUN_fffede1d(auStack_8,&uStack_a,2);
  if (iVar1 != 0) {
    local_6 = local_6 | 0x10;
  }
  FUN_fff97a44(auStack_8,local_4);
  uStack_a = 0;
  iVar1 = FUN_fffede1d(auStack_8,&uStack_a,2);
  if (iVar1 != 0) {
    local_6 = local_6 | 0x20;
  }
  return local_6;
}


// ===== FUN_fff97b7b @ fff97b7b (43 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97b88) */

byte FUN_fff97b7b(void)

{
  return PTR_DAT_00025d38[0x79] & 0xf | PTR_DAT_00025d38[0x78] << 4;
}


// ===== FUN_fff97ba6 @ fff97ba6 (206 bytes)

void FUN_fff97ba6(undefined4 *param_1)

{
  if (PTR_DAT_00025d38[0x41a] != '\x01') {
    if (PTR_DAT_00025d38[0x67] == '\x01') {
      *(undefined1 *)param_1 = 0;
    }
    else if (DAT_00009c35 == '\0') {
      *(undefined1 *)param_1 = 0;
    }
    else if (DAT_00009c35 == '\x01') {
      *(undefined1 *)param_1 = 1;
    }
    else {
      *(undefined1 *)param_1 = 2;
    }
    if (DAT_00009c36 == '\x01') {
      *(undefined1 *)((int)param_1 + 1) = 0x84;
    }
    else {
      *(undefined1 *)((int)param_1 + 1) = 3;
    }
    if (DAT_00009c37 == '\x01') {
      *(undefined1 *)((int)param_1 + 2) = 0x86;
    }
    else {
      *(undefined1 *)((int)param_1 + 2) = 5;
    }
    if (DAT_00009c3d == '\x01') {
      *(undefined1 *)((int)param_1 + 3) = 0x88;
    }
    else {
      *(undefined1 *)((int)param_1 + 3) = 7;
    }
    *(undefined1 *)(param_1 + 1) = 9;
    *(undefined1 *)((int)param_1 + 5) = 10;
    return;
  }
  *(undefined2 *)(param_1 + 1) = 0x7f7f;
  *param_1 = 0x7f7f0c0b;
  return;
}


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
  iVar3 = vfo_is_memory(param_1);
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
  
  dest_code_get();
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
  iVar2 = vfo_tune_locked(param_1);
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
  iVar1 = vfo_tune_locked(param_1);
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
    local_2 = meter_get_s();
  }
  else if (DAT_00009c5b == '\x05') {
    if (DAT_00020b41 == '\x02') {
      local_2 = meter_get_swr_raw();
    }
    else {
      local_2 = meter_get_swr();
    }
  }
  else if (DAT_00009c5b == '\x01') {
    local_2 = meter_get_comp();
  }
  else if (DAT_00009c5b == '\x02') {
    local_2 = meter_get_alc();
  }
  else if (DAT_00009c5b == '\x03') {
    local_2 = meter_get_vdd();
  }
  else if (DAT_00009c5b == '\x04') {
    local_2 = meter_get_idd();
  }
  else if (DAT_00009c5b == '\0') {
    local_2 = meter_get_po();
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


// ===== disp_put_op_freq @ fff98566 (95 bytes)

/* DISPLAY frame +0x1715: operating frequency */

void disp_put_op_freq(undefined1 *param_1)

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


// ===== disp_put_tx_freq @ fff985c5 (48 bytes)

/* DISPLAY frame +0x1719: TX frequency 0x20F50 */

void disp_put_tx_freq(undefined1 *param_1)

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


// ===== disp_put_dial_freq @ fff985f5 (116 bytes)

/* DISPLAY frame +0x171D: dial frequency */

void disp_put_dial_freq(undefined1 *param_1)

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


// ===== disp_put_scope_start @ fff98691 (79 bytes)

/* DISPLAY frame +0x1721: scope start (0x20F60 or FIX band memory) */

void disp_put_scope_start(int param_1)

{
  byte local_a;
  uint local_8;
  
  if (DAT_00009c35 == '\x02') {
    local_8 = bandmem_get(2);
  }
  else {
    local_8 = DAT_00020f60;
  }
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    *(char *)((uint)local_a + param_1) = (char)(local_8 >> ((3 - local_a & 3) << 3));
  }
  return;
}


// ===== displink_tx_64 @ fff986e0 (71 bytes)

/* 0x64 (3 bytes): +0xB8 when changed */

void displink_tx_64(void)

{
  if (PTR_DAT_00025d38[0xb8] == PTR_DAT_00025d38[0xb9]) {
    return;
  }
  PTR_DAT_00025d38[0xb9] = PTR_DAT_00025d38[0xb8];
  DAT_00001456 = 100;
  DAT_00001457 = PTR_DAT_00025d38[0xb8];
  DAT_0001b628 = 3;
  displink_tx_start(3);
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


// ===== power_down_save @ fff98797 (210 bytes)

/* Restart/power-off request: notifies DISPLAY; code 0x90 waits 2 s, else eeprom_save_all (0x9DC5=1
   if code 0x11); then mcu_software_reset */

void power_down_save(void)

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
  displink_tx_start(0xb);
  if (PTR_DAT_00025d38[0x35] == -0x70) {
    swtimer_start(0x14,2000);
    do {
      iVar1 = swtimer_expired(0x14);
    } while (iVar1 == 0);
  }
  else if (PTR_DAT_00025d38[0x35] == '\x11') {
    DAT_00009dc5 = 1;
    eeprom_save_all();
  }
  else {
    DAT_00009dc5 = 0;
    eeprom_save_all();
  }
  sw_reset();
  return;
}


// ===== displink_tx_7C @ fff98869 (51 bytes)

/* 0x7C (5 bytes) */

void displink_tx_7C(void)

{
  DAT_00001456 = 0x7c;
  DAT_00001457 = 0;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_7B @ fff9889c (86 bytes)

/* 0x7B (5 bytes), toggles +0x82 */

void displink_tx_7B(void)

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
  displink_tx_start(5);
  return;
}


// ===== displink_tx_7A @ fff988f2 (51 bytes)

/* 0x7A (5 bytes) */

void displink_tx_7A(void)

{
  DAT_00001456 = 0x7a;
  DAT_00001457 = 0;
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  DAT_0001b628 = 5;
  displink_tx_start(5);
  return;
}


// ===== displink_tx_70 @ fff98925 (42 bytes)

/* 0x70 (0xE3 bytes) */

void displink_tx_70(void)

{
  int iVar1;
  
  displink_build_70();
  iVar1 = displink_copy_if_changed(&DAT_00001741,&DAT_00001456,0xe2);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = 0xe3;
  displink_tx_start(0xe3);
  return;
}


// ===== displink_build_70 @ fff9894f (638 bytes)

void displink_build_70(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
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


// ===== displink_tx_req @ fff98bcd (82 bytes)

/* 0x43/0x44/0x45 request, type +0x1E0, length +0x1E2 */

void displink_tx_req(void)

{
  int iVar1;
  
  PTR_DAT_00025d38[0x87] = 0;
  displink_build_req();
  iVar1 = displink_copy_if_changed
                    (&DAT_00001741,&DAT_00001456,*(short *)(PTR_DAT_00025d38 + 0x1e2) + -1);
  if (iVar1 != 1) {
    return;
  }
  DAT_0001b628 = *(undefined2 *)(PTR_DAT_00025d38 + 0x1e2);
  displink_tx_start(*(undefined2 *)(PTR_DAT_00025d38 + 0x1e2));
  return;
}


// ===== displink_build_req @ fff98c1f (86 bytes)

void displink_build_req(void)

{
  mem_zero(0x98,&DAT_000016a0);
  mem_zero(0x24a,&DAT_00001741);
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
  
  displink_build_status();
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


// ===== displink_tx_23 @ fff98e39 (31 bytes)

/* 0x23 (0x37 bytes) */

void displink_tx_23(void)

{
  PTR_DAT_00025d38[0x89] = 0;
  displink_build_23();
  DAT_0001b628 = 0x37;
  displink_tx_start(0x37);
  return;
}


// ===== FUN_fff98e58 @ fff98e58 (31 bytes)

void FUN_fff98e58(void)

{
  PTR_DAT_00025d38[0x8a] = 0;
  FUN_fff98ec9();
  DAT_0001b628 = 0x37;
  displink_tx_start(0x37);
  return;
}


// ===== FUN_fff98e77 @ fff98e77 (31 bytes)

void FUN_fff98e77(void)

{
  PTR_DAT_00025d38[0x8b] = 0;
  FUN_fff98eca();
  DAT_0001b628 = 0x37;
  displink_tx_start(0x37);
  return;
}


// ===== displink_build_23 @ fff98e96 (51 bytes)

void displink_build_23(void)

{
  DAT_00001456 = 0x23;
  DAT_00001457 = (char)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x1be) >> 8) + '\x01';
  DAT_00001458 = 0;
  DAT_00001459 = 0;
  return;
}

