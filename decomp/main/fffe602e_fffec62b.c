// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe602e @ fffe602e (120 bytes)

void FUN_fffe602e(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = DAT_00009dbd;
  bVar2 = vfo_mode(0);
  bVar3 = vfo_is_memory(bVar3);
  if (bVar3 == 1) {
    PTR_DAT_00025d7c[0x46c] = 1;
    swtimer_start(0x40,200);
    return;
  }
  uVar1 = (uint)bVar2;
  if ((3 < uVar1 - 4) && (uVar1 != 10 && uVar1 != 0xb)) {
    PTR_DAT_00025d7c[0x46c] = 1;
    swtimer_start(0x40,10);
    return;
  }
  PTR_DAT_00025d7c[0x46c] = 1;
  swtimer_start(0x40,100);
  return;
}


// ===== FUN_fffe60a6 @ fffe60a6 (146 bytes)

void FUN_fffe60a6(void)

{
  bool bVar1;
  int iVar2;
  
  if ((PTR_DAT_00025d7c[0x40d] == '\x01') || (PTR_DAT_00025d7c[0x86] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d7c[0x39] != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (PTR_DAT_00025d7c[0x418] == '\0') {
    PTR_DAT_00025d7c[0x46b] = 1;
    FUN_fffc809d(DAT_00009dbd);
    return;
  }
  iVar2 = FUN_fffe5d4f();
  if (iVar2 != 1) {
    iVar2 = FUN_fffe5d0e();
    if (iVar2 == 1) {
      scan_start_up();
      return;
    }
    scan_stop();
    return;
  }
  scan_start_up();
  return;
}


// ===== FUN_fffe6138 @ fffe6138 (146 bytes)

void FUN_fffe6138(void)

{
  bool bVar1;
  int iVar2;
  
  if ((PTR_DAT_00025d7c[0x40d] == '\x01') || (PTR_DAT_00025d7c[0x86] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d7c[0x39] != '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  if (PTR_DAT_00025d7c[0x418] == '\0') {
    PTR_DAT_00025d7c[0x46b] = 1;
    FUN_fffc8141(DAT_00009dbd);
    return;
  }
  iVar2 = FUN_fffe5d4f();
  if (iVar2 != 1) {
    iVar2 = FUN_fffe5d0e();
    if (iVar2 == 0) {
      scan_start_down();
      return;
    }
    scan_stop();
    return;
  }
  scan_start_down();
  return;
}


// ===== FUN_fffe61ca @ fffe61ca (29 bytes)

void FUN_fffe61ca(void)

{
  byte bVar1;
  
  bVar1 = blink_phase(0);
  if (bVar1 == 0) {
    PTR_DAT_00025d7c[0x1bc] = 0;
    return;
  }
  PTR_DAT_00025d7c[0x1bc] = 1;
  return;
}


// ===== ex_command @ fffe61e7 (178 bytes)

/* EX core: parse key, read or write, on set menu_apply_from_cat, copy reply 0x18878 -> 0x1C8E */

byte ex_command(char *text,byte is_set,ushort len,byte *reply,ushort *reply_len)

{
  byte *pbVar1;
  uint uVar2;
  byte bStack_1c;
  char acStack_1b [3];
  byte bStack_18;
  undefined4 local_17;
  undefined2 local_13;
  ushort *local_10;
  byte *local_c;
  ushort local_8;
  byte local_5;
  char *local_4;
  
  local_10 = reply_len;
  DAT_0001ff10 = 0;
  DAT_0001b234 = 0;
  local_13 = *(undefined2 *)(text + 6);
  local_17 = *(undefined4 *)(text + 2);
  local_c = reply;
  local_8 = len;
  local_5 = is_set;
  local_4 = text;
  bStack_18 = ex_parse_key(acStack_1b,(byte *)&local_17);
  if (bStack_18 == 0) {
    bStack_1c = 1;
  }
  else {
    bStack_18 = ex_read_or_write(acStack_1b,local_4,local_5,local_8);
    if ((bool)bStack_18) {
      if (local_5 == 1) {
        menu_apply_from_cat((uint)acStack_1b);
      }
      pbVar1 = &DAT_00018878;
      for (uVar2 = (uint)DAT_0001ff10; uVar2 != 0; uVar2 = uVar2 - 1) {
        *local_c = *pbVar1;
        local_c = local_c + 1;
        pbVar1 = pbVar1 + 1;
      }
      *local_10 = DAT_0001ff10;
      bStack_1c = DAT_0001b234;
    }
    else {
      bStack_1c = 1;
    }
  }
  DAT_0001b234 = bStack_1c;
  return bStack_1c;
}


// ===== ex_read_or_write @ fffe6299 (156 bytes)

/* Dispatch on is_set and desc string flag (+0x30) */

bool ex_read_or_write(char *key,char *text,byte is_set,ushort len)

{
  byte lim [16];
  byte lim_00 [16];
  ushort len_00;
  char *out;
  char *key_00;
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 in_stack_ffffffcc [12];
  undefined4 uVar4;
  byte abStack_20 [8];
  char cStack_18;
  byte bStack_e;
  ushort local_c;
  byte local_9;
  char *local_8;
  char *local_4;
  
  uVar4 = 0xfffe62ad;
  local_c = len;
  local_9 = is_set;
  local_8 = text;
  local_4 = key;
  bStack_e = menu_get_limits(key,abStack_20);
  key_00 = local_4;
  out = local_8;
  len_00 = local_c;
  pbVar2 = abStack_20;
  if (bStack_e == 1) {
    if (cStack_18 == '\0') {
      if (local_9 == 0) {
        pbVar1 = &stack0xffffffcc;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *pbVar1 = *pbVar2;
          pbVar1 = pbVar1 + 1;
          pbVar2 = pbVar2 + 1;
        }
        lim[0xc] = (char)uVar4;
        lim[0xd] = (char)((uint)uVar4 >> 8);
        lim[0xe] = (char)((uint)uVar4 >> 0x10);
        lim[0xf] = (char)((uint)uVar4 >> 0x18);
        lim[0] = in_stack_ffffffcc[0];
        lim[1] = in_stack_ffffffcc[1];
        lim[2] = in_stack_ffffffcc[2];
        lim[3] = in_stack_ffffffcc[3];
        lim[4] = in_stack_ffffffcc[4];
        lim[5] = in_stack_ffffffcc[5];
        lim[6] = in_stack_ffffffcc[6];
        lim[7] = in_stack_ffffffcc[7];
        lim[8] = in_stack_ffffffcc[8];
        lim[9] = in_stack_ffffffcc[9];
        lim[10] = in_stack_ffffffcc[10];
        lim[0xb] = in_stack_ffffffcc[0xb];
        bStack_e = ex_read_value(key_00,out,lim);
      }
      else {
        pbVar1 = &stack0xffffffcc;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *pbVar1 = *pbVar2;
          pbVar1 = pbVar1 + 1;
          pbVar2 = pbVar2 + 1;
        }
        lim_00[0xc] = (char)uVar4;
        lim_00[0xd] = (char)((uint)uVar4 >> 8);
        lim_00[0xe] = (char)((uint)uVar4 >> 0x10);
        lim_00[0xf] = (char)((uint)uVar4 >> 0x18);
        lim_00[0] = in_stack_ffffffcc[0];
        lim_00[1] = in_stack_ffffffcc[1];
        lim_00[2] = in_stack_ffffffcc[2];
        lim_00[3] = in_stack_ffffffcc[3];
        lim_00[4] = in_stack_ffffffcc[4];
        lim_00[5] = in_stack_ffffffcc[5];
        lim_00[6] = in_stack_ffffffcc[6];
        lim_00[7] = in_stack_ffffffcc[7];
        lim_00[8] = in_stack_ffffffcc[8];
        lim_00[9] = in_stack_ffffffcc[9];
        lim_00[10] = in_stack_ffffffcc[10];
        lim_00[0xb] = in_stack_ffffffcc[0xb];
        bStack_e = ex_write_value(key_00,out,len_00,lim_00);
      }
    }
    else if (local_9 == 0) {
      bStack_e = ex_read_string((int)local_4,local_8);
    }
    else {
      bStack_e = ex_write_string((uint)local_4,(int)local_8);
    }
  }
  return bStack_e != 0;
}


// ===== ex_read_string @ fffe6335 (198 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reply EXkkkkkk + 12-char text */

byte ex_read_string(int param_1,void *param_2)

{
  bool bVar1;
  byte bVar2;
  byte local_18;
  undefined4 local_17;
  undefined4 local_13;
  undefined4 local_f;
  byte bStack_b;
  undefined4 *local_8;
  int local_4;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_18 = 0;
  }
  else {
    local_f = 0;
    local_13 = 0;
    local_17 = 0;
    local_8 = param_2;
    local_4 = param_1;
    bVar2 = menu_string_get(param_1,(uint)&local_17,0xc);
    if (bVar2 == 0) {
      local_18 = 0;
    }
    else {
      DAT_0001887c = local_8[1];
      _DAT_00018878 = *local_8;
      DAT_00018888 = local_f;
      DAT_00018884 = local_13;
      DAT_00018880 = local_17;
      for (bStack_b = 0; bStack_b < 0xc; bStack_b = bStack_b + 1) {
        if (*(char *)((int)&DAT_00018880 + (uint)bStack_b) == '\0') {
          *(undefined1 *)((int)&DAT_00018880 + (uint)bStack_b) = 0x3b;
          break;
        }
      }
      if (bStack_b == 0xc) {
        uRam0001888c = 0x3b;
      }
      DAT_0001ff10 = bStack_b + 9;
      local_18 = 1;
    }
  }
  return local_18;
}


// ===== ex_write_string @ fffe63fb (113 bytes)

/* Copy P4 text up to ";" (max 12) into the item */

bool ex_write_string(uint param_1,int param_2)

{
  byte bVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  byte local_c;
  char local_b;
  int local_8;
  uint local_4;
  
  local_b = '\0';
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_c = 0;
  local_8 = param_2;
  local_4 = param_1;
  do {
    if (0xc < local_c) {
LAB_fffe6458:
      return local_b == '\x01';
    }
    if (*(char *)((uint)local_c + local_8 + 8) == ';') {
      bVar1 = menu_string_set(local_4,(uint)&local_18,local_c);
      if (bVar1 == 0) {
        return false;
      }
      local_b = '\x01';
      goto LAB_fffe6458;
    }
    *(undefined1 *)((int)&local_18 + (uint)local_c) = *(undefined1 *)((uint)local_c + local_8 + 8);
    local_c = local_c + 1;
  } while( true );
}


// ===== ex_read_value @ fffe646c (228 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe654d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Format value: 1 digit, 2/3 digits (+sign), or 4 digits (u16 or scaled x10 / x20+20) */

byte ex_read_value(char *key,char *out,byte lim [16])

{
  byte bVar1;
  byte bStack_15;
  bool bStack_12;
  ushort auStack_10 [2];
  char *local_c;
  char *local_8;
  
  DAT_0001887c = *(undefined4 *)(out + 4);
  _DAT_00018878 = *(undefined4 *)out;
  local_c = out;
  local_8 = key;
  bVar1 = menu_value_get(key,auStack_10);
  if (bVar1 == 0) {
    bStack_15 = 0;
  }
  else if ((lim._12_4_ & 0xff) == 2) {
    auStack_10[0] = auStack_10[0] * 0x14 + 0x14;
    DAT_0001ff10 = ex_fmt_4digits(auStack_10[0]);
    bStack_15 = 1;
  }
  else if ((lim._12_4_ & 0xff) == 1) {
    auStack_10[0] = auStack_10[0] * 10;
    DAT_0001ff10 = ex_fmt_4digits(auStack_10[0]);
    bStack_15 = 1;
  }
  else {
    if (lim[9] == 0) {
      if (lim[0xb] == 1) {
        DAT_00018880._0_1_ = nib2hex((byte)auStack_10[0]);
        DAT_00018880._1_1_ = 0x3b;
        DAT_0001ff10 = 10;
      }
      else {
        bStack_12 = 2 < lim[0xb];
        DAT_0001ff10 = ex_fmt_byte((byte)auStack_10[0],bStack_12,lim[10] != 0);
      }
    }
    else {
      DAT_0001ff10 = ex_fmt_4digits(auStack_10[0]);
    }
    bStack_15 = 1;
  }
  return bStack_15;
}


// ===== ex_write_value @ fffe6550 (314 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6687) */
/* WARNING: Removing unreachable block (ram,0xfffe6664) */
/* WARNING: Removing unreachable block (ram,0xfffe6659) */
/* Check length/range, parse P4, unscale (/10 or /20-1), menu_value_set */

byte ex_write_value(char *key,char *text,ushort len,byte lim [16])

{
  bool bVar1;
  byte bVar2;
  ushort uStack_1e;
  short local_1c;
  ushort local_1a;
  ushort local_18;
  ushort uStack_16;
  byte bStack_13;
  byte bStack_12;
  undefined1 local_11;
  byte bStack_10;
  ushort local_e;
  char *local_c;
  char *local_8;
  
  local_1c = lim[0xb] + 9;
  if ((lim._12_4_ & 0xff) == 1) {
    local_18 = lim._2_2_ * 10;
    local_1a = lim._0_2_ * 10;
  }
  else if ((lim._12_4_ & 0xff) == 2) {
    local_18 = lim._2_2_ * 0x14 + 0x14;
    local_1a = lim._0_2_ * 0x14 + 0x14;
  }
  else {
    local_18._0_1_ = lim[2];
    local_18._1_1_ = lim[3];
    local_1a._0_1_ = lim[0];
    local_1a._1_1_ = lim[1];
  }
  if ((lim[9] == 0) && (lim[0xb] < 4)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  local_e = len;
  local_c = text;
  local_8 = key;
  if (bVar1) {
    local_11 = lim[10] != 0;
    bStack_10 = ex_parse_byte(text + 8,&bStack_12,lim[0xb],local_11,(byte)local_1a,(byte)local_18,
                              len);
    if (bStack_10 == 0) {
      return 0;
    }
    if (lim[10] == 0) {
      uStack_1e = (ushort)bStack_12;
    }
    else {
      bStack_13 = bStack_12;
      uStack_1e = (ushort)(char)bStack_12;
    }
    bStack_10 = ex_value_allowed(local_8,uStack_1e);
    if (bStack_10 == 0) {
      return 0;
    }
    bVar2 = menu_value_set(local_8,&uStack_1e);
    if (bVar2 == 0) {
      return 0;
    }
  }
  else {
    bStack_10 = ex_parse_4digits(text + 8,&uStack_16,local_1a,local_18,(byte)local_1c,len);
    if (!(bool)bStack_10) {
      return 0;
    }
    uStack_1e = uStack_16;
    if ((lim._12_4_ & 0xff) == 1) {
      uStack_1e = (short)uStack_16 / 10;
    }
    else if ((lim._12_4_ & 0xff) == 2) {
      uStack_1e = (short)uStack_16 / 0x14 - 1;
    }
    bVar2 = menu_value_set(local_8,&uStack_1e);
    if (bVar2 == 0) {
      return 0;
    }
  }
  return 1;
}


// ===== ex_value_allowed @ fffe668a (88 bytes)

/* Rejects EX010113 (SSB TX BPF SEL) value 5 (50-4000Hz) */

byte ex_value_allowed(char *param_1,short param_2)

{
  bool bVar1;
  byte local_8;
  
  if (param_1 == (char *)0x0) {
    local_8 = 0;
  }
  else {
    if ((*param_1 == '\0') && (param_1[1] == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (param_1[2] == '\f')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (param_2 == 5) {
        local_8 = 0;
      }
      else {
        local_8 = 1;
      }
    }
    else {
      local_8 = 1;
    }
  }
  return local_8;
}


// ===== ex_fmt_byte @ fffe66e2 (275 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe67f2) */
/* WARNING: Removing unreachable block (ram,0xfffe67ac) */
/* WARNING: Removing unreachable block (ram,0xfffe6726) */
/* Byte -> 2/3 decimal digits, or sign + 2 digits */

short ex_fmt_byte(byte param_1,char param_2,byte param_3)

{
  char cVar1;
  byte bVar2;
  short sStack_10;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_5;
  
  local_5 = param_1;
  if (param_3 == 0) {
    if (param_2 == '\0') {
      local_d = 10;
      local_e = 2;
    }
    else if (param_2 == '\x01') {
      local_d = 100;
      local_e = 3;
    }
    for (local_c = 0; local_c < local_e; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      cVar1 = nib2hex(bVar2);
      *(char *)((int)&DAT_00018880 + (uint)local_c) = cVar1;
    }
    *(undefined1 *)((int)&DAT_00018880 + (uint)local_c) = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 8;
  }
  else {
    if ((param_1 & 0x80) == 0) {
      DAT_00018880._0_1_ = 0x2b;
    }
    else {
      DAT_00018880._0_1_ = 0x2d;
      local_5 = ~param_1 + 1;
    }
    local_d = 10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      cVar1 = nib2hex(bVar2);
      *(char *)((int)&DAT_00018880 + local_c + 1) = cVar1;
    }
    *(undefined1 *)((int)&DAT_00018880 + local_c + 1) = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 9;
  }
  return sStack_10;
}


// ===== ex_fmt_4digits @ fffe67f5 (116 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6866) */
/* WARNING: Removing unreachable block (ram,0xfffe681f) */
/* u16 -> 4 decimal digits */

short ex_fmt_4digits(ushort param_1)

{
  char cVar1;
  uint uVar2;
  ushort uVar3;
  ushort local_c;
  byte local_a;
  ushort local_6;
  
  local_c = 1000;
  local_6 = param_1;
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    uVar2 = (uint)local_6;
    if (local_c != 0) {
      uVar2 = uVar2 / local_c;
    }
    uVar3 = local_6;
    if (local_c != 0) {
      uVar3 = local_6 / local_c;
    }
    local_6 = local_6 - uVar3 * local_c;
    local_c = local_c / 10;
    cVar1 = nib2hex((byte)uVar2);
    *(char *)((int)&DAT_00018880 + (uint)local_a) = cVar1;
  }
  *(undefined1 *)((int)&DAT_00018880 + (uint)local_a) = 0x3b;
  return (byte)(local_a + 1) + 8;
}


// ===== ex_parse_4digits @ fffe6869 (210 bytes)

/* 4 decimal digits, range check [min,max] */

bool ex_parse_4digits(char *text,ushort *out,ushort min,ushort max,byte digits,ushort len)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  ushort uVar6;
  bool local_17;
  byte local_16;
  
  if (digits == len) {
    for (local_16 = 0; local_16 < 4; local_16 = local_16 + 1) {
      if (((byte)text[local_16] < 0x30) || (0x39 < (byte)text[local_16])) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return false;
      }
    }
    cVar2 = hex2nib(*text);
    cVar3 = hex2nib(text[1]);
    cVar4 = hex2nib(text[2]);
    cVar5 = hex2nib(text[3]);
    uVar6 = (short)cVar5 + cVar4 * 10 + cVar3 * 100 + cVar2 * 1000;
    if ((uVar6 < min) || (max < uVar6)) {
      local_17 = false;
    }
    else {
      local_17 = true;
    }
    if (local_17) {
      *out = uVar6;
    }
  }
  else {
    local_17 = false;
  }
  return local_17;
}


// ===== ex_parse_byte @ fffe693b (748 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6ab4) */
/* WARNING: Removing unreachable block (ram,0xfffe6b97) */
/* WARNING: Removing unreachable block (ram,0xfffe6a5c) */
/* WARNING: Removing unreachable block (ram,0xfffe6b40) */
/* 1-3 digits with optional sign, exact length, range check */

byte ex_parse_byte(char *text,byte *out,byte digits,byte is_signed,byte min,byte max,ushort len)

{
  bool bVar1;
  char cVar2;
  byte local_14;
  byte local_13;
  byte local_12;
  byte local_11;
  byte local_10;
  
  local_10 = 0;
  local_14 = 0;
  if (is_signed == 1) {
    local_11 = digits + 10;
  }
  else {
    local_11 = digits + 9;
  }
  if (local_11 != len) {
    return 0;
  }
  if (digits == 1) {
    if (is_signed == 0) {
      if (((byte)*text < 0x30) || (0x39 < (byte)*text)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return 0;
      }
      local_10 = hex2nib(*text);
    }
    else {
      if (((byte)text[1] < 0x30) || (0x39 < (byte)text[1])) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return 0;
      }
      local_10 = hex2nib(text[1]);
      if (*text == '-') {
        local_10 = ~local_10 + 1;
      }
      else if (*text != '+') {
        return 0;
      }
    }
  }
  else if (digits == 2) {
    local_12 = 10;
    if (is_signed == 0) {
      for (local_13 = 0; local_13 < 2; local_13 = local_13 + 1) {
        if (((byte)text[local_13] < 0x30) || (0x39 < (byte)text[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(text[local_13]);
        local_10 = cVar2 * local_12 + local_10;
        local_12 = local_12 / 10;
      }
    }
    else {
      for (local_13 = 1; local_13 < 3; local_13 = local_13 + 1) {
        if (((byte)text[local_13] < 0x30) || (0x39 < (byte)text[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(text[local_13]);
        local_10 = cVar2 * local_12 + local_10;
        local_12 = local_12 / 10;
      }
      if (*text == '-') {
        local_10 = ~local_10 + 1;
      }
      else if (*text != '+') {
        return 0;
      }
    }
  }
  else if (digits == 3) {
    local_12 = 100;
    if (is_signed == 0) {
      for (local_13 = 0; local_13 < 3; local_13 = local_13 + 1) {
        if (((byte)text[local_13] < 0x30) || (0x39 < (byte)text[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(text[local_13]);
        local_10 = cVar2 * local_12 + local_10;
        local_12 = local_12 / 10;
      }
    }
    else {
      for (local_13 = 1; local_13 < 4; local_13 = local_13 + 1) {
        if (((byte)text[local_13] < 0x30) || (0x39 < (byte)text[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(text[local_13]);
        local_10 = cVar2 * local_12 + local_10;
        local_12 = local_12 / 10;
      }
      if (*text == '-') {
        local_10 = ~local_10 + 1;
      }
      else if (*text != '+') {
        return 0;
      }
    }
  }
  if (is_signed == 0) {
    if ((local_10 < min) || (max < local_10)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *out = local_10;
      local_14 = 1;
    }
  }
  else {
    if (((char)local_10 < (char)min) || ((char)max < (char)local_10)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *out = local_10;
      local_14 = 1;
    }
  }
  return local_14;
}


// ===== ex_parse_key @ fffe6c27 (339 bytes)

/* P1P1P2P2P3P3 (decimal) -> internal {P1-1, P2+base, P3-1}; CAT P1 05 and >06 rejected */

byte ex_parse_key(char *param_1,byte *param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte local_15;
  byte *local_14;
  byte local_10;
  char cStack_e;
  
  local_10 = 0;
  local_14 = param_2;
  while( true ) {
    if (5 < local_10) {
      cVar2 = hex2nib(*param_2);
      if (cVar2 == -1) {
        local_15 = 0;
      }
      else {
        cVar3 = hex2nib(param_2[1]);
        if (cVar3 == -1) {
          local_15 = 0;
        }
        else {
          cVar5 = cVar2 * '\n' + cVar3;
          cVar4 = hex2nib(param_2[2]);
          if (cVar4 == -1) {
            local_15 = 0;
          }
          else {
            cStack_e = hex2nib(param_2[3]);
            if (cStack_e == -1) {
              local_15 = 0;
            }
            else {
              cStack_e = cVar4 * '\n' + cStack_e;
              if (cVar5 == '\x06') {
                cStack_e = cStack_e + '\x15';
              }
              else if (cVar5 == '\x02') {
                cStack_e = cStack_e + '\x04';
              }
              else if (cVar5 == '\x03') {
                cStack_e = cStack_e + '\x06';
              }
              else if (cVar5 == '\x04') {
                cStack_e = cStack_e + '\v';
              }
              else {
                if (cVar5 != '\x01') {
                  return 0;
                }
                cStack_e = cStack_e + -1;
              }
              cVar5 = hex2nib(param_2[4]);
              if (cVar5 == -1) {
                local_15 = 0;
              }
              else {
                cVar4 = hex2nib(param_2[5]);
                if (cVar4 == -1) {
                  local_15 = 0;
                }
                else {
                  *param_1 = cVar2 * '\n' + cVar3 + -1;
                  param_1[1] = cStack_e;
                  param_1[2] = cVar5 * '\n' + cVar4 + -1;
                  local_15 = 1;
                }
              }
            }
          }
        }
      }
      return local_15;
    }
    if ((*local_14 < 0x30) || (0x39 < *local_14)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) break;
    local_14 = local_14 + 1;
    local_10 = local_10 + 1;
  }
  return 0;
}


// ===== FUN_fffe6d7a @ fffe6d7a (172 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6dac) */

ushort FUN_fffe6d7a(undefined1 *param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  byte bStack_9;
  ushort local_8;
  
  DAT_0001ff12 = 0;
  local_8 = 0;
  while( true ) {
    if (0x127 < local_8) goto LAB_fffe6df2;
    (*(code *)(&PTR_LAB_fff8e1a0)[local_8])();
    if (DAT_0001ff12 != 0) break;
    local_8 = local_8 + 1;
  }
  for (bStack_9 = 0; bStack_9 < 8; bStack_9 = bStack_9 + 1) {
    (&DAT_0001b235)[bStack_9] =
         "EX010101EX010102EX010103EX010104EX010105EX010106EX010107EX010108EX010109EX010110EX010111EX010112EX010113EX010114EX010115EX010116EX010117EX010118EX010119EX010201EX010202EX010203EX010204EX010205EX010206EX010207EX010208EX010209EX010210EX010211EX010212EX010213EX010214EX010215EX010216EX010217EX010301EX010302EX010303EX010304EX010305EX010306EX010307EX010308EX010309EX010310EX010311EX010312EX010313EX010314EX010315EX010316EX010317EX010318EX010319EX010320EX010321EX010401EX010402EX010403EX010404EX010405EX010406EX010407EX010408EX010409EX010410EX010411EX010412EX010413EX010414EX010415EX010416EX010417EX010418EX010419EX010420EX010501EX010502EX010503EX010504EX010505EX010506EX010507EX010508EX010509EX010510EX010511EX010512EX010513EX010514EX010515EX010516EX010517EX020101EX020102EX020103EX020104EX020105EX020106EX020107EX020108EX020109EX020110EX020111EX020112EX020113EX020114EX020115EX020116EX020117EX020118EX020119EX020120EX020201EX020202EX020203EX020204EX020205EX020206EX020207EX020208EX020209EX020210EX020211EX030101EX030102EX030103EX030104EX030105EX030106EX030107EX030108EX030109EX030110EX030111EX030112EX030113EX030114EX030115EX030116EX030117EX030118EX030119EX030120EX030121EX030122EX030123EX030124EX030125EX030126EX030201EX030202EX030203EX030204EX030205EX030206EX030301EX030302EX030303EX030304EX030305EX030306EX030307EX030308EX030309EX030310EX030311EX030312EX030313EX030314EX030315EX030316EX030317EX030318EX030319EX030401EX030402EX030403EX030404EX030405EX030406EX030407EX030408EX030501EX030502EX030503EX030504EX030505EX030506EX040101EX040102EX040103EX040104EX040105EX040106EX040201EX040202EX040203EX040204EX040301EX040302EX040303EX040304EX040401EX040402EX060101EX060102EX060103EX060104EX060105EX060106EX060107EX060108EX060109EX060110EX060111EX060112EX060113EX060114EX060115EX060116EX060117EX060118EX060201EX060202EX060203EX060204EX060205EX060206EX060207EX060208EX060209EX060210EX060211EX060212EX060213EX060214EX060215EX060216EX060217EX060218EX060301EX060302EX060303EX060304EX060305EX060306EX060307EX060308EX060309EX060310EX060311EX060312EX060313EX060314..." /* TRUNCATED STRING LITERAL */
         [(uint)bStack_9 + (uint)local_8 * 8];
  }
  puVar2 = &DAT_0001b235;
  for (uVar3 = (uint)DAT_0001ff12; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_1 = *puVar2;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
LAB_fffe6df2:
  if (DAT_0001b299 == '\x01') {
    bVar1 = swtimer_expired(0x32);
    if (bVar1 != 1) {
      return 0;
    }
    DAT_0001b299 = '\0';
  }
  return DAT_0001ff12;
}


// ===== FUN_fffe6e26 @ fffe6e26 (20 bytes)

void FUN_fffe6e26(void)

{
  swtimer_start(0x32,200);
  DAT_0001b299 = 1;
  return;
}


// ===== FUN_fffea63a @ fffea63a (594 bytes)

void FUN_fffea63a(char param_1)

{
  int iVar1;
  undefined4 uStack_e;
  undefined4 uStack_a;
  undefined4 uStack_6;
  byte bStack_2;
  char local_1;
  
  local_1 = param_1;
  if (param_1 == '\x05') {
    iVar1 = FUN_fffede1d(&DAT_0001b3a0,&DAT_00009baa,0xc);
    if (iVar1 != 0) {
      DAT_0001b3a8 = DAT_00009bb2;
      DAT_0001b3a4 = DAT_00009bae;
      DAT_0001b3a0 = DAT_00009baa;
      uStack_6 = DAT_00009bb2;
      uStack_a = DAT_00009bae;
      uStack_e = DAT_00009baa;
      DAT_0001ff12 = 0x15;
    }
  }
  else if (param_1 == '\x02') {
    iVar1 = FUN_fffede1d(&DAT_0001b37c,&DAT_00009b4d,0xc);
    if (iVar1 != 0) {
      DAT_0001b384 = DAT_00009b55;
      DAT_0001b380 = DAT_00009b51;
      DAT_0001b37c = DAT_00009b4d;
      uStack_6 = DAT_00009b55;
      uStack_a = DAT_00009b51;
      uStack_e = DAT_00009b4d;
      DAT_0001ff12 = 0x15;
    }
  }
  else if (param_1 == '\x03') {
    iVar1 = FUN_fffede1d(&DAT_0001b388,&DAT_00009b6c,0xc);
    if (iVar1 != 0) {
      DAT_0001b390 = DAT_00009b74;
      DAT_0001b38c = DAT_00009b70;
      DAT_0001b388 = DAT_00009b6c;
      uStack_6 = DAT_00009b74;
      uStack_a = DAT_00009b70;
      uStack_e = DAT_00009b6c;
      DAT_0001ff12 = 0x15;
    }
  }
  else if (param_1 == '\x04') {
    iVar1 = FUN_fffede1d(&DAT_0001b394,&DAT_00009b8b,0xc);
    if (iVar1 != 0) {
      DAT_0001b39c = DAT_00009b93;
      DAT_0001b398 = DAT_00009b8f;
      DAT_0001b394 = DAT_00009b8b;
      uStack_6 = DAT_00009b93;
      uStack_a = DAT_00009b8f;
      uStack_e = DAT_00009b8b;
      DAT_0001ff12 = 0x15;
    }
  }
  else if ((param_1 == '\x01') &&
          (iVar1 = FUN_fffede1d(&DAT_0001b370,&DAT_00009b2e,0xc), iVar1 != 0)) {
    DAT_0001b378 = DAT_00009b36;
    DAT_0001b374 = DAT_00009b32;
    DAT_0001b370 = DAT_00009b2e;
    uStack_6 = DAT_00009b36;
    uStack_a = DAT_00009b32;
    uStack_e = DAT_00009b2e;
    DAT_0001ff12 = 0x15;
  }
  if (DAT_0001ff12 != 0) {
    for (bStack_2 = 0; bStack_2 < 0xc; bStack_2 = bStack_2 + 1) {
      (&DAT_0001b23d)[bStack_2] = *(undefined1 *)((int)&uStack_e + (uint)bStack_2);
    }
    DAT_0001b249 = 0x3b;
    return;
  }
  return;
}


// ===== FUN_fffea88c @ fffea88c (380 bytes)

void FUN_fffea88c(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b559 != DAT_00009bb6) {
      DAT_0001b559 = DAT_00009bb6;
      DAT_0001b23d = nib2hex(DAT_00009bb6);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b556 != DAT_00009b59) {
      DAT_0001b556 = DAT_00009b59;
      DAT_0001b23d = nib2hex(DAT_00009b59);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b557 != DAT_00009b78) {
      DAT_0001b557 = DAT_00009b78;
      DAT_0001b23d = nib2hex(DAT_00009b78);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b558 != DAT_00009b97) {
      DAT_0001b558 = DAT_00009b97;
      DAT_0001b23d = nib2hex(DAT_00009b97);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b555 != DAT_00009b3a)) {
    DAT_0001b555 = DAT_00009b3a;
    DAT_0001b23d = nib2hex(DAT_00009b3a);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeaa08 @ fffeaa08 (380 bytes)

void FUN_fffeaa08(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b55e != DAT_00009bb7) {
      DAT_0001b55e = DAT_00009bb7;
      DAT_0001b23d = nib2hex(DAT_00009bb7);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b55b != DAT_00009b5a) {
      DAT_0001b55b = DAT_00009b5a;
      DAT_0001b23d = nib2hex(DAT_00009b5a);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b55c != DAT_00009b79) {
      DAT_0001b55c = DAT_00009b79;
      DAT_0001b23d = nib2hex(DAT_00009b79);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b55d != DAT_00009b98) {
      DAT_0001b55d = DAT_00009b98;
      DAT_0001b23d = nib2hex(DAT_00009b98);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b55a != DAT_00009b3b)) {
    DAT_0001b55a = DAT_00009b3b;
    DAT_0001b23d = nib2hex(DAT_00009b3b);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeab84 @ fffeab84 (380 bytes)

void FUN_fffeab84(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b563 != DAT_00009bb8) {
      DAT_0001b563 = DAT_00009bb8;
      DAT_0001b23d = nib2hex(DAT_00009bb8);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b560 != DAT_00009b5b) {
      DAT_0001b560 = DAT_00009b5b;
      DAT_0001b23d = nib2hex(DAT_00009b5b);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b561 != DAT_00009b7a) {
      DAT_0001b561 = DAT_00009b7a;
      DAT_0001b23d = nib2hex(DAT_00009b7a);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b562 != DAT_00009b99) {
      DAT_0001b562 = DAT_00009b99;
      DAT_0001b23d = nib2hex(DAT_00009b99);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b55f != DAT_00009b3c)) {
    DAT_0001b55f = DAT_00009b3c;
    DAT_0001b23d = nib2hex(DAT_00009b3c);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffead00 @ fffead00 (375 bytes)

void FUN_fffead00(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b568 != DAT_00009bb9) {
      DAT_0001b568 = DAT_00009bb9;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009bb9 + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b565 != DAT_00009b5c) {
      DAT_0001b565 = DAT_00009b5c;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b5c + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b566 != DAT_00009b7b) {
      DAT_0001b566 = DAT_00009b7b;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b7b + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b567 != DAT_00009b9a) {
      DAT_0001b567 = DAT_00009b9a;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b9a + 1) * 0x14);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b564 != DAT_00009b3d)) {
    DAT_0001b564 = DAT_00009b3d;
    DAT_0001ff12 = FUN_fffec3f8((DAT_00009b3d + 1) * 0x14);
    return;
  }
  return;
}


// ===== FUN_fffeae77 @ fffeae77 (375 bytes)

void FUN_fffeae77(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b56d != DAT_00009bba) {
      DAT_0001b56d = DAT_00009bba;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009bba + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b56a != DAT_00009b5d) {
      DAT_0001b56a = DAT_00009b5d;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b5d + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b56b != DAT_00009b7c) {
      DAT_0001b56b = DAT_00009b7c;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b7c + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b56c != DAT_00009b9b) {
      DAT_0001b56c = DAT_00009b9b;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b9b + 1) * 0x14);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b569 != DAT_00009b3e)) {
    DAT_0001b569 = DAT_00009b3e;
    DAT_0001ff12 = FUN_fffec3f8((DAT_00009b3e + 1) * 0x14);
    return;
  }
  return;
}


// ===== FUN_fffeafee @ fffeafee (375 bytes)

void FUN_fffeafee(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b572 != DAT_00009bbb) {
      DAT_0001b572 = DAT_00009bbb;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009bbb + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b56f != DAT_00009b5e) {
      DAT_0001b56f = DAT_00009b5e;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b5e + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b570 != DAT_00009b7d) {
      DAT_0001b570 = DAT_00009b7d;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b7d + 1) * 0x14);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b571 != DAT_00009b9c) {
      DAT_0001b571 = DAT_00009b9c;
      DAT_0001ff12 = FUN_fffec3f8((DAT_00009b9c + 1) * 0x14);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b56e != DAT_00009b3f)) {
    DAT_0001b56e = DAT_00009b3f;
    DAT_0001ff12 = FUN_fffec3f8((DAT_00009b3f + 1) * 0x14);
    return;
  }
  return;
}


// ===== FUN_fffeb165 @ fffeb165 (340 bytes)

void FUN_fffeb165(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b577 != DAT_00009bbc) {
      DAT_0001b577 = DAT_00009bbc;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bbc,0,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b574 != DAT_00009b5f) {
      DAT_0001b574 = DAT_00009b5f;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b5f,0,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b575 != DAT_00009b7e) {
      DAT_0001b575 = DAT_00009b7e;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b7e,0,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b576 != DAT_00009b9d) {
      DAT_0001b576 = DAT_00009b9d;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b9d,0,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b573 != DAT_00009b40)) {
    DAT_0001b573 = DAT_00009b40;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b40,0,0);
    return;
  }
  return;
}


// ===== FUN_fffeb2b9 @ fffeb2b9 (380 bytes)

void FUN_fffeb2b9(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b57c != DAT_00009bbd) {
      DAT_0001b57c = DAT_00009bbd;
      DAT_0001b23d = nib2hex(DAT_00009bbd);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b579 != DAT_00009b60) {
      DAT_0001b579 = DAT_00009b60;
      DAT_0001b23d = nib2hex(DAT_00009b60);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b57a != DAT_00009b7f) {
      DAT_0001b57a = DAT_00009b7f;
      DAT_0001b23d = nib2hex(DAT_00009b7f);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b57b != DAT_00009b9e) {
      DAT_0001b57b = DAT_00009b9e;
      DAT_0001b23d = nib2hex(DAT_00009b9e);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b578 != DAT_00009b41)) {
    DAT_0001b578 = DAT_00009b41;
    DAT_0001b23d = nib2hex(DAT_00009b41);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeb435 @ fffeb435 (340 bytes)

void FUN_fffeb435(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b581 != DAT_00009bbe) {
      DAT_0001b581 = DAT_00009bbe;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bbe,0,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b57e != DAT_00009b61) {
      DAT_0001b57e = DAT_00009b61;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b61,0,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b57f != DAT_00009b80) {
      DAT_0001b57f = DAT_00009b80;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b80,0,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b580 != DAT_00009b9f) {
      DAT_0001b580 = DAT_00009b9f;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b9f,0,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b57d != DAT_00009b42)) {
    DAT_0001b57d = DAT_00009b42;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b42,0,0);
    return;
  }
  return;
}


// ===== FUN_fffeb589 @ fffeb589 (380 bytes)

void FUN_fffeb589(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b586 != DAT_00009bbf) {
      DAT_0001b586 = DAT_00009bbf;
      DAT_0001b23d = nib2hex(DAT_00009bbf);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b583 != DAT_00009b62) {
      DAT_0001b583 = DAT_00009b62;
      DAT_0001b23d = nib2hex(DAT_00009b62);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b584 != DAT_00009b81) {
      DAT_0001b584 = DAT_00009b81;
      DAT_0001b23d = nib2hex(DAT_00009b81);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b585 != DAT_00009ba0) {
      DAT_0001b585 = DAT_00009ba0;
      DAT_0001b23d = nib2hex(DAT_00009ba0);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b582 != DAT_00009b43)) {
    DAT_0001b582 = DAT_00009b43;
    DAT_0001b23d = nib2hex(DAT_00009b43);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffeb705 @ fffeb705 (340 bytes)

void FUN_fffeb705(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b58b != DAT_00009bc0) {
      DAT_0001b58b = DAT_00009bc0;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bc0,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b588 != DAT_00009b63) {
      DAT_0001b588 = DAT_00009b63;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b63,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b589 != DAT_00009b82) {
      DAT_0001b589 = DAT_00009b82;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b82,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b58a != DAT_00009ba1) {
      DAT_0001b58a = DAT_00009ba1;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009ba1,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b587 != DAT_00009b44)) {
    DAT_0001b587 = DAT_00009b44;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b44,1,0);
    return;
  }
  return;
}


// ===== FUN_fffeb859 @ fffeb859 (340 bytes)

void FUN_fffeb859(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b590 != DAT_00009bc1) {
      DAT_0001b590 = DAT_00009bc1;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bc1,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b58d != DAT_00009b64) {
      DAT_0001b58d = DAT_00009b64;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b64,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b58e != DAT_00009b83) {
      DAT_0001b58e = DAT_00009b83;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b83,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b58f != DAT_00009ba2) {
      DAT_0001b58f = DAT_00009ba2;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009ba2,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b58c != DAT_00009b45)) {
    DAT_0001b58c = DAT_00009b45;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b45,1,0);
    return;
  }
  return;
}


// ===== FUN_fffeb9ad @ fffeb9ad (380 bytes)

void FUN_fffeb9ad(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b595 != DAT_00009bc2) {
      DAT_0001b595 = DAT_00009bc2;
      DAT_0001b23d = nib2hex(DAT_00009bc2);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b592 != DAT_00009b65) {
      DAT_0001b592 = DAT_00009b65;
      DAT_0001b23d = nib2hex(DAT_00009b65);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b593 != DAT_00009b84) {
      DAT_0001b593 = DAT_00009b84;
      DAT_0001b23d = nib2hex(DAT_00009b84);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b594 != DAT_00009ba3) {
      DAT_0001b594 = DAT_00009ba3;
      DAT_0001b23d = nib2hex(DAT_00009ba3);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b591 != DAT_00009b46)) {
    DAT_0001b591 = DAT_00009b46;
    DAT_0001b23d = nib2hex(DAT_00009b46);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffebb29 @ fffebb29 (380 bytes)

void FUN_fffebb29(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b59a != DAT_00009bc3) {
      DAT_0001b59a = DAT_00009bc3;
      DAT_0001b23d = nib2hex(DAT_00009bc3);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b597 != DAT_00009b66) {
      DAT_0001b597 = DAT_00009b66;
      DAT_0001b23d = nib2hex(DAT_00009b66);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b598 != DAT_00009b85) {
      DAT_0001b598 = DAT_00009b85;
      DAT_0001b23d = nib2hex(DAT_00009b85);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b599 != DAT_00009ba4) {
      DAT_0001b599 = DAT_00009ba4;
      DAT_0001b23d = nib2hex(DAT_00009ba4);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b596 != DAT_00009b47)) {
    DAT_0001b596 = DAT_00009b47;
    DAT_0001b23d = nib2hex(DAT_00009b47);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffebca5 @ fffebca5 (340 bytes)

void FUN_fffebca5(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b59f != DAT_00009bc4) {
      DAT_0001b59f = DAT_00009bc4;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bc4,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b59c != DAT_00009b67) {
      DAT_0001b59c = DAT_00009b67;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b67,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b59d != DAT_00009b86) {
      DAT_0001b59d = DAT_00009b86;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b86,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b59e != DAT_00009ba5) {
      DAT_0001b59e = DAT_00009ba5;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009ba5,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b59b != DAT_00009b48)) {
    DAT_0001b59b = DAT_00009b48;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b48,1,0);
    return;
  }
  return;
}


// ===== FUN_fffebdf9 @ fffebdf9 (340 bytes)

void FUN_fffebdf9(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b5a4 != DAT_00009bc5) {
      DAT_0001b5a4 = DAT_00009bc5;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009bc5,1,0);
      return;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b5a1 != DAT_00009b68) {
      DAT_0001b5a1 = DAT_00009b68;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b68,1,0);
      return;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b5a2 != DAT_00009b87) {
      DAT_0001b5a2 = DAT_00009b87;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009b87,1,0);
      return;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b5a3 != DAT_00009ba6) {
      DAT_0001b5a3 = DAT_00009ba6;
      DAT_0001ff12 = FUN_fffec2e5(DAT_00009ba6,1,0);
      return;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b5a0 != DAT_00009b49)) {
    DAT_0001b5a0 = DAT_00009b49;
    DAT_0001ff12 = FUN_fffec2e5(DAT_00009b49,1,0);
    return;
  }
  return;
}


// ===== FUN_fffebf4d @ fffebf4d (380 bytes)

void FUN_fffebf4d(char param_1)

{
  if (param_1 == '\x05') {
    if (DAT_0001b5a9 != DAT_00009bc6) {
      DAT_0001b5a9 = DAT_00009bc6;
      DAT_0001b23d = nib2hex(DAT_00009bc6);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x02') {
    if (DAT_0001b5a6 != DAT_00009b69) {
      DAT_0001b5a6 = DAT_00009b69;
      DAT_0001b23d = nib2hex(DAT_00009b69);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x03') {
    if (DAT_0001b5a7 != DAT_00009b88) {
      DAT_0001b5a7 = DAT_00009b88;
      DAT_0001b23d = nib2hex(DAT_00009b88);
      DAT_0001ff12 = 10;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_0001b5a8 != DAT_00009ba7) {
      DAT_0001b5a8 = DAT_00009ba7;
      DAT_0001b23d = nib2hex(DAT_00009ba7);
      DAT_0001ff12 = 10;
    }
  }
  else if ((param_1 == '\x01') && (DAT_0001b5a5 != DAT_00009b4a)) {
    DAT_0001b5a5 = DAT_00009b4a;
    DAT_0001b23d = nib2hex(DAT_00009b4a);
    DAT_0001ff12 = 10;
  }
  DAT_0001b23e = 0x3b;
  return;
}


// ===== FUN_fffec2e5 @ fffec2e5 (275 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec3f5) */
/* WARNING: Removing unreachable block (ram,0xfffec3af) */
/* WARNING: Removing unreachable block (ram,0xfffec329) */

short FUN_fffec2e5(byte param_1,char param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  short sStack_10;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_5;
  
  local_5 = param_1;
  if (param_3 == 0) {
    if (param_2 == '\0') {
      local_d = 10;
      local_e = 2;
    }
    else if (param_2 == '\x01') {
      local_d = 100;
      local_e = 3;
    }
    for (local_c = 0; local_c < local_e; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      cVar1 = nib2hex(bVar2);
      (&DAT_0001b23d)[local_c] = cVar1;
    }
    (&DAT_0001b23d)[local_c] = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 8;
  }
  else {
    if ((param_1 & 0x80) == 0) {
      DAT_0001b23d = 0x2b;
    }
    else {
      DAT_0001b23d = 0x2d;
      local_5 = ~param_1 + 1;
    }
    local_d = 10;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      bVar2 = local_5;
      if (local_d != 0) {
        bVar2 = local_5 / local_d;
      }
      local_5 = local_5 - bVar2 * local_d;
      local_d = local_d / 10;
      cVar1 = nib2hex(bVar2);
      (&DAT_0001b23e)[local_c] = cVar1;
    }
    (&DAT_0001b23e)[local_c] = 0x3b;
    sStack_10 = (byte)(local_c + 1) + 9;
  }
  return sStack_10;
}


// ===== FUN_fffec3f8 @ fffec3f8 (116 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec469) */
/* WARNING: Removing unreachable block (ram,0xfffec422) */

short FUN_fffec3f8(ushort param_1)

{
  char cVar1;
  uint uVar2;
  ushort uVar3;
  ushort local_c;
  byte local_a;
  ushort local_6;
  
  local_c = 1000;
  local_6 = param_1;
  for (local_a = 0; local_a < 4; local_a = local_a + 1) {
    uVar2 = (uint)local_6;
    if (local_c != 0) {
      uVar2 = uVar2 / local_c;
    }
    uVar3 = local_6;
    if (local_c != 0) {
      uVar3 = local_6 / local_c;
    }
    local_6 = local_6 - uVar3 * local_c;
    local_c = local_c / 10;
    cVar1 = nib2hex((byte)uVar2);
    (&DAT_0001b23d)[local_a] = cVar1;
  }
  (&DAT_0001b23d)[local_a] = 0x3b;
  return (byte)(local_a + 1) + 8;
}


// ===== tuner_init @ fffec46c (7 bytes)

/* tuner_task once + FUN_fffec578 */

void tuner_init(void)

{
  tuner_task();
  FUN_fffec578();
  return;
}


// ===== tuner_task @ fffec473 (32 bytes)

/* main_loop task 16: antenna tuner, dispatch on tuner select 0x9AB8 [inference] */

void tuner_task(void)

{
  if (DAT_00009ab8 == 3) {
    FUN_fffed165();
    return;
  }
  if (1 < DAT_00009ab8) {
    FUN_fffed62a();
    return;
  }
  FUN_fffec62b();
  return;
}


// ===== FUN_fffec493 @ fffec493 (72 bytes)

void FUN_fffec493(void)

{
  DAT_0001b3bc = DAT_00009c5b;
  DAT_00009c5b = 5;
  DAT_0001b3bd = DAT_00009aa1;
  DAT_00009aa1 = 0;
  DAT_00020cc6 = 0x49;
  FUN_fffc8d8c(0);
  return;
}


// ===== FUN_fffec4db @ fffec4db (37 bytes)

void FUN_fffec4db(void)

{
  DAT_00009c5b = DAT_0001b3bc;
  DAT_00009aa1 = DAT_0001b3bd;
  FUN_fffc8beb();
  return;
}


// ===== FUN_fffec500 @ fffec500 (15 bytes)

undefined1 FUN_fffec500(void)

{
  return DAT_0001b3ad;
}


// ===== FUN_fffec50f @ fffec50f (15 bytes)

undefined1 FUN_fffec50f(void)

{
  return DAT_0001b3af;
}


// ===== FUN_fffec51e @ fffec51e (15 bytes)

undefined1 FUN_fffec51e(void)

{
  return DAT_0001b3b1;
}


// ===== FUN_fffec52d @ fffec52d (10 bytes)

void FUN_fffec52d(void)

{
  DAT_0001b3ac = 0x10;
  return;
}


// ===== FUN_fffec537 @ fffec537 (35 bytes)

void FUN_fffec537(char param_1)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  if (param_1 != '\0') {
    pbVar1[1] = pbVar1[1] | 4;
    return;
  }
  pbVar1[1] = pbVar1[1] & 0xfb;
  return;
}


// ===== FUN_fffec55a @ fffec55a (30 bytes)

bool FUN_fffec55a(void)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(1);
  return (pbVar1[1] & 4) != 0;
}


// ===== FUN_fffec578 @ fffec578 (179 bytes)

void FUN_fffec578(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_00009ab8 == 2) {
    iVar2 = FUN_fffed6f5();
    if (iVar2 == 1) {
      iVar2 = FUN_fffec55a();
      if (iVar2 == 0) {
        if ((DAT_00020b3f == '\x04') || (DAT_00020b3f == '\x05')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          DAT_00020b3f = 6;
          return;
        }
      }
      else if (DAT_00020b3f == '\0') {
        DAT_00020b3f = 4;
        return;
      }
    }
  }
  else if (DAT_00009ab8 < 2) {
    iVar2 = FUN_fffec55a();
    if (iVar2 == 0) {
      if ((DAT_00020b3f == '\x01') || (DAT_00020b3f == '\x02')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        DAT_00020b3f = 3;
        return;
      }
    }
    else if (DAT_00020b3f == '\0') {
      DAT_00020b3f = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffec62b @ fffec62b (223 bytes)

void FUN_fffec62b(void)

{
  bool bVar1;
  byte bVar2;
  
  DAT_00020b71 = 0;
  if ((DAT_00020b3f == '\x02') || (DAT_00020b3f == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_00020b71 = 1;
    if ((DAT_00020b41 == '\x02') && (bVar2 = blink_phase(0), bVar2 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      DAT_00020b71 = 0;
    }
  }
  switch(DAT_0001b3ac) {
  case 1:
    FUN_fffec728();
    return;
  case 2:
    FUN_fffec7f9();
    return;
  case 3:
    FUN_fffec881();
    return;
  case 4:
    FUN_fffec8a1();
    return;
  case 5:
    FUN_fffec911();
    return;
  case 6:
  case 10:
    FUN_fffec9b4();
    return;
  case 7:
  case 0xb:
    FUN_fffeca48();
    return;
  case 8:
    FUN_fffeca7e();
    return;
  case 9:
    FUN_fffecba2();
    return;
  case 0xc:
    FUN_fffecce7();
    return;
  case 0xd:
    FUN_fffecde6();
    return;
  case 0xe:
    FUN_fffece39();
    return;
  case 0xf:
    FUN_fffece69();
    return;
  case 0x10:
    FUN_fffece79();
    return;
  default:
    FUN_fffec70a();
    return;
  case 0x14:
  case 0x15:
    FUN_fffec9ed();
    return;
  }
}

