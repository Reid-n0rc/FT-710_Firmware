// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe5dd5 @ fffe5dd5 (70 bytes)

void FUN_fffe5dd5(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar1 = DAT_00009dbd;
  bVar2 = vfo_is_memory(DAT_00009dbd);
  if (bVar2 == 1) {
    do {
      PTR_DAT_00025d7c[0x47c] = 1;
      FUN_fffc54cc(1,DAT_00009dbd);
      iVar3 = FUN_fffe5e1b();
    } while (iVar3 == 1);
    return;
  }
  FUN_fffc8141(bVar1);
  return;
}


// ===== FUN_fffe5e1b @ fffe5e1b (32 bytes)

undefined1 FUN_fffe5e1b(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  bVar1 = memch_current(DAT_00009dbd);
  uVar2 = FUN_fffe5e3b(bVar1);
  return uVar2;
}


// ===== FUN_fffe5e3b @ fffe5e3b (44 bytes)

bool FUN_fffe5e3b(byte param_1)

{
  return ((&DAT_00006151)[(uint)param_1 * 0x5a] & 0x80) != 0;
}


// ===== FUN_fffe5e67 @ fffe5e67 (83 bytes)

void FUN_fffe5e67(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = vfo_is_memory(DAT_00009dbd);
  if (bVar1 == 1) {
    DAT_00018873 = 1;
    swtimer_start(0x33,0xfa);
    return;
  }
  iVar2 = FUN_fffe5fab();
  DAT_00018873 = 1;
  if (iVar2 != 1) {
    swtimer_start(0x33,5);
    return;
  }
  swtimer_start(0x33,0x32);
  return;
}


// ===== FUN_fffe5eba @ fffe5eba (20 bytes)

void FUN_fffe5eba(void)

{
  DAT_00018873 = 1;
  swtimer_start(0x33,0x19);
  return;
}


// ===== FUN_fffe5ece @ fffe5ece (21 bytes)

void FUN_fffe5ece(void)

{
  DAT_00018875 = 1;
  swtimer_start(0x35,5000);
  return;
}


// ===== FUN_fffe5ee3 @ fffe5ee3 (53 bytes)

undefined1 FUN_fffe5ee3(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (DAT_00018873 == '\x01') {
    bVar1 = swtimer_expired(0x33);
    if (bVar1 == 1) {
      DAT_00018873 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe5f18 @ fffe5f18 (53 bytes)

undefined1 FUN_fffe5f18(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (DAT_00018874 == '\x01') {
    bVar1 = swtimer_expired(0x34);
    if (bVar1 == 1) {
      DAT_00018874 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe5f4d @ fffe5f4d (53 bytes)

undefined1 FUN_fffe5f4d(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (DAT_00018875 == '\x01') {
    bVar1 = swtimer_expired(0x35);
    if (bVar1 == 1) {
      DAT_00018875 = '\0';
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fffe5f82 @ fffe5f82 (41 bytes)

bool FUN_fffe5f82(void)

{
  byte bVar1;
  
  bVar1 = vfo_mode(DAT_00009dbd);
  return bVar1 < 4;
}


// ===== FUN_fffe5fab @ fffe5fab (50 bytes)

undefined1 FUN_fffe5fab(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uStack_4;
  
  bVar2 = vfo_mode(DAT_00009dbd);
  uVar1 = (uint)bVar2;
  if ((uVar1 - 4 < 4) || (uVar1 == 10 || uVar1 == 0xb)) {
    uStack_4 = 1;
  }
  else {
    uStack_4 = 0;
  }
  return uStack_4;
}


// ===== FUN_fffe5fdd @ fffe5fdd (50 bytes)

undefined1 FUN_fffe5fdd(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uStack_4;
  
  bVar2 = vfo_mode(DAT_00009dbd);
  uVar1 = (uint)bVar2;
  if ((uVar1 - 6 < 2) || (uVar1 == 10 || uVar1 == 0xb)) {
    uStack_4 = 1;
  }
  else {
    uStack_4 = 0;
  }
  return uStack_4;
}


// ===== FUN_fffe600f @ fffe600f (31 bytes)

bool FUN_fffe600f(void)

{
  byte *pbVar1;
  
  pbVar1 = vfo_rec_ptr(0);
  return (pbVar1[3] & 8) != 0;
}


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


// ===== cat_ai_ex_scan @ fffe6d7a (172 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6dac) */
/* Calls the 296 detectors in 0xFFF8E1A0 until one sets the length 0x1FF12; builds "EXnnnnnn" +
   value at 0x1B235; held off while 0x1B299 = 1 and timer 0x32 runs */

ushort cat_ai_ex_scan(undefined1 *param_1)

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
    (*(code *)(&PTR_ai_ex010101_fff8e1a0)[local_8])();
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


// ===== cat_ai_ex_holdoff @ fffe6e26 (20 bytes)

/* After an EX set: timer 0x32 = 200, 0x1B299 = 1 (like cat_ai_holdoff, own flag) */

void cat_ai_ex_holdoff(void)

{
  swtimer_start(0x32,200);
  DAT_0001b299 = 1;
  return;
}


// ===== ai_ex010101 @ fffe6e3a (61 bytes)

/* AI change detector for menu item EX010101 (table 0xFFF8E1A0[0]) */

void ai_ex010101(void)

{
  if (DAT_0001b29a == DAT_00009a2a) {
    return;
  }
  DAT_0001b29a = DAT_00009a2a;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a2a,0,1);
  return;
}


// ===== ai_ex010102 @ fffe6e77 (61 bytes)

/* AI change detector for menu item EX010102 (table 0xFFF8E1A0[1]) */

void ai_ex010102(void)

{
  if (DAT_0001b29b == DAT_00009a2b) {
    return;
  }
  DAT_0001b29b = DAT_00009a2b;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a2b,0,1);
  return;
}


// ===== ai_ex010103 @ fffe6eb4 (61 bytes)

/* AI change detector for menu item EX010103 (table 0xFFF8E1A0[2]) */

void ai_ex010103(void)

{
  if (DAT_0001b29c == DAT_00009a2c) {
    return;
  }
  DAT_0001b29c = DAT_00009a2c;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a2c,0,1);
  return;
}


// ===== ai_ex010104 @ fffe6ef1 (72 bytes)

/* AI change detector for menu item EX010104 (table 0xFFF8E1A0[3]) */

void ai_ex010104(void)

{
  if (DAT_0001b29d == DAT_00009a2d) {
    return;
  }
  DAT_0001b29d = DAT_00009a2d;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a2d + 1) * 0x14);
  return;
}


// ===== ai_ex010105 @ fffe6f39 (72 bytes)

/* AI change detector for menu item EX010105 (table 0xFFF8E1A0[4]) */

void ai_ex010105(void)

{
  if (DAT_0001b29e == DAT_00009a2e) {
    return;
  }
  DAT_0001b29e = DAT_00009a2e;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a2e + 1) * 0x14);
  return;
}


// ===== ai_ex010106 @ fffe6f81 (72 bytes)

/* AI change detector for menu item EX010106 (table 0xFFF8E1A0[5]) */

void ai_ex010106(void)

{
  if (DAT_0001b29f == DAT_00009a2f) {
    return;
  }
  DAT_0001b29f = DAT_00009a2f;
  DAT_0001ff12 = FUN_fffec3f8((DAT_00009a2f + 1) * 0x14);
  return;
}


// ===== ai_ex010107 @ fffe6fc9 (61 bytes)

/* AI change detector for menu item EX010107 (table 0xFFF8E1A0[6]) */

void ai_ex010107(void)

{
  if (DAT_0001b2a0 == DAT_00009a30) {
    return;
  }
  DAT_0001b2a0 = DAT_00009a30;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a30,0,0);
  return;
}


// ===== ai_ex010108 @ fffe7006 (76 bytes)

/* AI change detector for menu item EX010108 (table 0xFFF8E1A0[7]) */

void ai_ex010108(void)

{
  if (DAT_0001b2a1 == DAT_00009a31) {
    return;
  }
  DAT_0001b2a1 = DAT_00009a31;
  DAT_0001b23d = nib2hex(DAT_00009a31);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010109 @ fffe7052 (61 bytes)

/* AI change detector for menu item EX010109 (table 0xFFF8E1A0[8]) */

void ai_ex010109(void)

{
  if (DAT_0001b2a2 == DAT_00009a32) {
    return;
  }
  DAT_0001b2a2 = DAT_00009a32;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a32,0,0);
  return;
}


// ===== ai_ex010110 @ fffe708f (76 bytes)

/* AI change detector for menu item EX010110 (table 0xFFF8E1A0[9]) */

void ai_ex010110(void)

{
  if (DAT_0001b2a3 == DAT_00009a33) {
    return;
  }
  DAT_0001b2a3 = DAT_00009a33;
  DAT_0001b23d = nib2hex(DAT_00009a33);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010111 @ fffe70db (61 bytes)

/* AI change detector for menu item EX010111 (table 0xFFF8E1A0[10]) */

void ai_ex010111(void)

{
  if (DAT_0001b2a4 == DAT_00009a34) {
    return;
  }
  DAT_0001b2a4 = DAT_00009a34;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a34,1,0);
  return;
}


// ===== ai_ex010112 @ fffe7118 (61 bytes)

/* AI change detector for menu item EX010112 (table 0xFFF8E1A0[11]) */

void ai_ex010112(void)

{
  if (DAT_0001b2a5 == DAT_00009a35) {
    return;
  }
  DAT_0001b2a5 = DAT_00009a35;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a35,1,0);
  return;
}


// ===== ai_ex010113 @ fffe7155 (76 bytes)

/* AI change detector for menu item EX010113 (table 0xFFF8E1A0[12]) */

void ai_ex010113(void)

{
  if (DAT_0001b2a6 == DAT_00009a36) {
    return;
  }
  DAT_0001b2a6 = DAT_00009a36;
  DAT_0001b23d = nib2hex(DAT_00009a36);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010114 @ fffe71a1 (76 bytes)

/* AI change detector for menu item EX010114 (table 0xFFF8E1A0[13]) */

void ai_ex010114(void)

{
  if (DAT_0001b2a7 == DAT_00009a37) {
    return;
  }
  DAT_0001b2a7 = DAT_00009a37;
  DAT_0001b23d = nib2hex(DAT_00009a37);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010115 @ fffe71ed (61 bytes)

/* AI change detector for menu item EX010115 (table 0xFFF8E1A0[14]) */

void ai_ex010115(void)

{
  if (DAT_0001b2a8 == DAT_00009a38) {
    return;
  }
  DAT_0001b2a8 = DAT_00009a38;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a38,1,0);
  return;
}


// ===== ai_ex010116 @ fffe722a (61 bytes)

/* AI change detector for menu item EX010116 (table 0xFFF8E1A0[15]) */

void ai_ex010116(void)

{
  if (DAT_0001b2a9 == DAT_00009a39) {
    return;
  }
  DAT_0001b2a9 = DAT_00009a39;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a39,1,0);
  return;
}


// ===== ai_ex010117 @ fffe7267 (76 bytes)

/* AI change detector for menu item EX010117 (table 0xFFF8E1A0[16]) */

void ai_ex010117(void)

{
  if (DAT_0001b2aa == DAT_00009a3a) {
    return;
  }
  DAT_0001b2aa = DAT_00009a3a;
  DAT_0001b23d = nib2hex(DAT_00009a3a);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}


// ===== ai_ex010118 @ fffe72b3 (61 bytes)

/* AI change detector for menu item EX010118 (table 0xFFF8E1A0[17]) */

void ai_ex010118(void)

{
  if (DAT_0001b2ab == DAT_00009a3b) {
    return;
  }
  DAT_0001b2ab = DAT_00009a3b;
  DAT_0001ff12 = FUN_fffec2e5(DAT_00009a3b,0,0);
  return;
}


// ===== ai_ex010119 @ fffe72f0 (76 bytes)

/* AI change detector for menu item EX010119 (table 0xFFF8E1A0[18]) */

void ai_ex010119(void)

{
  if (DAT_0001b2ac == DAT_00009a3c) {
    return;
  }
  DAT_0001b2ac = DAT_00009a3c;
  DAT_0001b23d = nib2hex(DAT_00009a3c);
  DAT_0001b23e = 0x3b;
  DAT_0001ff12 = 10;
  return;
}

