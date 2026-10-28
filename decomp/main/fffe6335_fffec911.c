// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== ex_read_string @ fffe6335 (198 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reply EXkkkkkk + 12-char text */

undefined1 ex_read_string(int param_1,undefined4 *param_2)

{
  bool bVar1;
  char cVar2;
  undefined1 local_18;
  undefined4 local_17;
  undefined4 local_13;
  undefined4 local_f;
  byte bStack_b;
  undefined4 *local_8;
  int local_4;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
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
    cVar2 = menu_string_get(param_1,&local_17,0xc);
    if (cVar2 == '\0') {
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

bool ex_write_string(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  byte local_c;
  char local_b;
  int local_8;
  undefined4 local_4;
  
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
      cVar1 = menu_string_set(local_4,&local_18,local_c);
      if (cVar1 == '\0') {
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

undefined1 ex_read_value(undefined4 param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 in_stack_0000000c;
  char in_stack_00000010;
  undefined1 uStack_15;
  bool bStack_12;
  short sStack_10;
  
  DAT_0001887c = param_2[1];
  _DAT_00018878 = *param_2;
  cVar1 = menu_value_get(param_1);
  if (cVar1 == '\0') {
    uStack_15 = 0;
  }
  else if (in_stack_00000010 == '\x02') {
    DAT_0001ff10 = ex_fmt_4digits(sStack_10 * 0x14 + 0x14);
    uStack_15 = 1;
  }
  else if (in_stack_00000010 == '\x01') {
    DAT_0001ff10 = ex_fmt_4digits(sStack_10 * 10);
    uStack_15 = 1;
  }
  else {
    if (in_stack_0000000c._1_1_ == '\0') {
      if (in_stack_0000000c._3_1_ == 1) {
        DAT_00018880._0_1_ = nib2hex((undefined1)sStack_10);
        DAT_00018880._1_1_ = 0x3b;
        DAT_0001ff10 = 10;
      }
      else {
        bStack_12 = 2 < in_stack_0000000c._3_1_;
        DAT_0001ff10 = ex_fmt_byte((undefined1)sStack_10,bStack_12,in_stack_0000000c._2_1_ != '\0');
      }
    }
    else {
      DAT_0001ff10 = ex_fmt_4digits(sStack_10);
    }
    uStack_15 = 1;
  }
  return uStack_15;
}


// ===== ex_write_value @ fffe6550 (314 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe6687) */
/* WARNING: Removing unreachable block (ram,0xfffe6664) */
/* WARNING: Removing unreachable block (ram,0xfffe6659) */
/* Check length/range, parse P4, unscale (/10 or /20-1), menu_value_set */

undefined1
ex_write_value(undefined4 param_1,int param_2,undefined2 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              char param_9)

{
  bool bVar1;
  char cVar2;
  undefined2 in_stack_ffffffd8;
  ushort uStack_1e;
  char local_1c;
  short local_1a;
  short local_18;
  undefined1 auStack_16 [3];
  byte bStack_13;
  byte bStack_12;
  undefined1 local_11;
  char cStack_10;
  undefined2 local_e;
  int local_c;
  undefined4 local_8;
  
  local_1c = param_8._3_1_ + 9;
  if (param_9 == '\x01') {
    local_18 = param_6._2_2_ * 10;
    local_1a = (short)param_6 * 10;
  }
  else if (param_9 == '\x02') {
    local_18 = param_6._2_2_ * 0x14 + 0x14;
    local_1a = (short)param_6 * 0x14 + 0x14;
  }
  else {
    local_18 = param_6._2_2_;
    local_1a = (short)param_6;
  }
  if ((param_8._1_1_ == '\0') && (param_8._3_1_ < 4)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  local_e = param_3;
  local_c = param_2;
  local_8 = param_1;
  if (bVar1) {
    local_11 = param_8._2_1_ != '\0';
    cStack_10 = ex_parse_byte(param_2 + 8,&bStack_12,param_8._3_1_,local_11,(undefined1)local_1a,
                              CONCAT31(CONCAT21(param_3,(undefined1)local_18),(undefined1)local_1a))
    ;
    if (cStack_10 == '\0') {
      return 0;
    }
    if (param_8._2_1_ == '\0') {
      uStack_1e = (ushort)bStack_12;
    }
    else {
      bStack_13 = bStack_12;
      uStack_1e = (ushort)(char)bStack_12;
    }
    cStack_10 = ex_value_allowed(local_8,(int)(short)uStack_1e);
    if (cStack_10 == '\0') {
      return 0;
    }
    cVar2 = menu_value_set(local_8);
    if (cVar2 == '\0') {
      return 0;
    }
  }
  else {
    cStack_10 = ex_parse_4digits(param_2 + 8,auStack_16,local_1a,local_18,param_5,
                                 CONCAT31((int3)(CONCAT22(param_3,in_stack_ffffffd8) >> 8),local_1c)
                                );
    if (cStack_10 == '\0') {
      return 0;
    }
    cVar2 = menu_value_set(local_8);
    if (cVar2 == '\0') {
      return 0;
    }
  }
  return 1;
}


// ===== ex_value_allowed @ fffe668a (88 bytes)

/* Rejects EX010113 (SSB TX BPF SEL) value 5 (50-4000Hz) */

undefined1 ex_value_allowed(char *param_1,short param_2)

{
  bool bVar1;
  undefined1 local_8;
  
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

short ex_fmt_byte(byte param_1,char param_2,int param_3)

{
  undefined1 uVar1;
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
      uVar1 = nib2hex(bVar2);
      *(undefined1 *)((int)&DAT_00018880 + (uint)local_c) = uVar1;
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
      uVar1 = nib2hex(bVar2);
      *(undefined1 *)((int)&DAT_00018880 + local_c + 1) = uVar1;
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
  undefined1 uVar1;
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
    if ((local_c & 0xff) != 0) {
      uVar3 = (ushort)((uint)local_6 / (local_c & 0xff));
    }
    local_6 = local_6 - (uVar3 * local_c & 0xff);
    local_c = local_c / 10;
    uVar1 = nib2hex(uVar2 & 0xff);
    *(undefined1 *)((int)&DAT_00018880 + (uint)local_a) = uVar1;
  }
  *(undefined1 *)((int)&DAT_00018880 + (uint)local_a) = 0x3b;
  return (byte)(local_a + 1) + 8;
}


// ===== ex_parse_4digits @ fffe6869 (210 bytes)

/* 4 decimal digits, range check [min,max] */

bool ex_parse_4digits(undefined1 *param_1,ushort *param_2,ushort param_3,ushort param_4,
                     undefined4 param_5,undefined4 param_6)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  bool local_17;
  byte local_16;
  
  if ((byte)param_6 == param_6._2_2_) {
    for (local_16 = 0; local_16 < 4; local_16 = local_16 + 1) {
      if (((byte)param_1[local_16] < 0x30) || (0x39 < (byte)param_1[local_16])) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return false;
      }
    }
    sVar2 = hex2nib(*param_1);
    sVar3 = hex2nib(param_1[1]);
    sVar4 = hex2nib(param_1[2]);
    sVar5 = hex2nib(param_1[3]);
    uVar6 = sVar5 + sVar4 * 10 + sVar3 * 100 + sVar2 * 1000;
    if ((uVar6 < param_3) || (param_4 < uVar6)) {
      local_17 = false;
    }
    else {
      local_17 = true;
    }
    if (local_17) {
      *param_2 = uVar6;
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

undefined1
ex_parse_byte(byte *param_1,byte *param_2,char param_3,char param_4,undefined4 param_5,
             undefined4 param_6,undefined4 param_7,char param_8)

{
  bool bVar1;
  char cVar2;
  undefined1 local_14;
  byte local_13;
  byte local_11;
  byte local_10;
  
  local_10 = 0;
  local_14 = 0;
  if (param_4 == '\x01') {
    local_11 = param_3 + 10;
  }
  else {
    local_11 = param_3 + 9;
  }
  if (local_11 != param_6._2_2_) {
    return 0;
  }
  if (param_3 == '\x01') {
    if (param_4 == '\0') {
      if ((*param_1 < 0x30) || (0x39 < *param_1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return 0;
      }
      local_10 = hex2nib(*param_1);
    }
    else {
      if ((param_1[1] < 0x30) || (0x39 < param_1[1])) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return 0;
      }
      local_10 = hex2nib(param_1[1]);
      if (*param_1 == 0x2d) {
        local_10 = ~local_10 + 1;
      }
      else if (*param_1 != 0x2b) {
        return 0;
      }
    }
  }
  else if (param_3 == '\x02') {
    if (param_4 == '\0') {
      for (local_13 = 0; local_13 < 2; local_13 = local_13 + 1) {
        if ((param_1[local_13] < 0x30) || (0x39 < param_1[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(param_1[local_13]);
        local_10 = cVar2 * param_8 + local_10;
      }
    }
    else {
      for (local_13 = 1; local_13 < 3; local_13 = local_13 + 1) {
        if ((param_1[local_13] < 0x30) || (0x39 < param_1[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(param_1[local_13]);
        local_10 = cVar2 * param_8 + local_10;
      }
      if (*param_1 == 0x2d) {
        local_10 = ~local_10 + 1;
      }
      else if (*param_1 != 0x2b) {
        return 0;
      }
    }
  }
  else if (param_3 == '\x03') {
    if (param_4 == '\0') {
      for (local_13 = 0; local_13 < 3; local_13 = local_13 + 1) {
        if ((param_1[local_13] < 0x30) || (0x39 < param_1[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(param_1[local_13]);
        local_10 = cVar2 * param_8 + local_10;
      }
    }
    else {
      for (local_13 = 1; local_13 < 4; local_13 = local_13 + 1) {
        if ((param_1[local_13] < 0x30) || (0x39 < param_1[local_13])) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          return 0;
        }
        cVar2 = hex2nib(param_1[local_13]);
        local_10 = cVar2 * param_8 + local_10;
      }
      if (*param_1 == 0x2d) {
        local_10 = ~local_10 + 1;
      }
      else if (*param_1 != 0x2b) {
        return 0;
      }
    }
  }
  if (param_4 == '\0') {
    if ((local_10 < (byte)param_6) || (param_6._1_1_ < local_10)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *param_2 = local_10;
      local_14 = 1;
    }
  }
  else {
    if (((char)local_10 < (char)(byte)param_6) || ((char)param_6._1_1_ < (char)local_10)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *param_2 = local_10;
      local_14 = 1;
    }
  }
  return local_14;
}


// ===== ex_parse_key @ fffe6c27 (339 bytes)

/* P1P1P2P2P3P3 (decimal) -> internal {P1-1, P2+base, P3-1}; CAT P1 05 and >06 rejected */

undefined1 ex_parse_key(char *param_1,byte *param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined1 local_15;
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

/* WARNING: Removing unreachable block (ram,0xfffe6da5) */
/* WARNING: Removing unreachable block (ram,0xfffe6dac) */
/* WARNING: Removing unreachable block (ram,0xfffe6dae) */
/* WARNING: Removing unreachable block (ram,0xfffe6dca) */
/* WARNING: Removing unreachable block (ram,0xfffe6daa) */
/* WARNING: Removing unreachable block (ram,0xfffe6dd0) */
/* WARNING: Removing unreachable block (ram,0xfffe6de0) */
/* WARNING: Removing unreachable block (ram,0xfffe6de2) */
/* WARNING: Removing unreachable block (ram,0xfffe6df2) */
/* WARNING: Removing unreachable block (ram,0xfffe6dfe) */
/* WARNING: Removing unreachable block (ram,0xfffe6e07) */
/* WARNING: Removing unreachable block (ram,0xfffe6e09) */
/* WARNING: Removing unreachable block (ram,0xfffe6dfc) */
/* WARNING: Removing unreachable block (ram,0xfffe6e17) */
/* WARNING: Removing unreachable block (ram,0xfffe6e1f) */

void FUN_fffe6d7a(void)

{
  do {
  } while( true );
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
  undefined1 uVar1;
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
      uVar1 = nib2hex(bVar2);
      (&DAT_0001b23d)[local_c] = uVar1;
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
      uVar1 = nib2hex(bVar2);
      (&DAT_0001b23e)[local_c] = uVar1;
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
  undefined1 uVar1;
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
    if ((local_c & 0xff) != 0) {
      uVar3 = (ushort)((uint)local_6 / (local_c & 0xff));
    }
    local_6 = local_6 - (uVar3 * local_c & 0xff);
    local_c = local_c / 10;
    uVar1 = nib2hex(uVar2 & 0xff);
    (&DAT_0001b23d)[local_a] = uVar1;
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
  int iVar1;
  
  iVar1 = vfo_rec_ptr(1);
  if (param_1 != '\0') {
    *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) | 4;
    return;
  }
  *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) & 0xfb;
  return;
}


// ===== FUN_fffec55a @ fffec55a (30 bytes)

bool FUN_fffec55a(void)

{
  int iVar1;
  
  iVar1 = vfo_rec_ptr(1);
  return (*(byte *)(iVar1 + 1) & 4) != 0;
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
  int iVar2;
  
  DAT_00020b71 = 0;
  if ((DAT_00020b3f == '\x02') || (DAT_00020b3f == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    DAT_00020b71 = 1;
    if ((DAT_00020b41 == '\x02') && (iVar2 = blink_phase(0), iVar2 == 0)) {
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


// ===== FUN_fffec70a @ fffec70a (30 bytes)

void FUN_fffec70a(void)

{
  DAT_00020b41 = 0;
  DAT_00020b3f = 0;
  DAT_0001b3ac = 1;
  return;
}


// ===== FUN_fffec728 @ fffec728 (209 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec7d5) */
/* WARNING: Removing unreachable block (ram,0xfffec7e2) */

void FUN_fffec728(void)

{
  uint uVar1;
  char cStack_5;
  
  uVar1 = DAT_00020f50;
  if (DAT_00020b41 == '\x01') {
    DAT_0001b3ac = 2;
  }
  else if (DAT_00020b3f == '\x03') {
    DAT_00020b3f = '\0';
  }
  else {
    if (DAT_00020b6b == '\0') {
      return;
    }
    if (DAT_00020b3f == '\x01') {
      cStack_5 = FUN_fffecfac(DAT_00020f50);
      if (cStack_5 == -1) {
        cStack_5 = FUN_fffed0ae(uVar1);
      }
      if (cStack_5 != -1) {
        DAT_00025d00 = uVar1;
        DAT_0001b3bb = FUN_fffb3371(uVar1);
        FUN_fffed12f();
        DAT_00020b3f = '\x02';
      }
    }
  }
  if ((DAT_00020b3f == '\x02') && (DAT_00025d00 / 10000 != (uVar1 / 10000 & 0xff))) {
    DAT_00020b3f = 1;
    return;
  }
  return;
}


// ===== FUN_fffec7f9 @ fffec7f9 (136 bytes)

void FUN_fffec7f9(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = DAT_00020f50;
  iVar2 = tx_freq_allowed(DAT_00020f50);
  if (iVar2 != 0) {
    DAT_00025d00 = uVar1;
    DAT_0001b3bb = FUN_fffb3371(uVar1);
    FUN_fffec493();
    DAT_00020b41 = 2;
    DAT_00020b2d = 1;
    DAT_0001b3ae = 0;
    DAT_0001b3b0 = 0;
    FUN_fffed12f();
    DAT_00020b3f = 0;
    swtimer_start(0x27,100);
    DAT_0001b3ac = 3;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffec881 @ fffec881 (32 bytes)

void FUN_fffec881(void)

{
  int iVar1;
  
  iVar1 = swtimer_expired(0x27);
  if (iVar1 == 0) {
    return;
  }
  swtimer_start(0x27,0xa0);
  DAT_0001b3ac = 4;
  return;
}


// ===== FUN_fffec8a1 @ fffec8a1 (112 bytes)

void FUN_fffec8a1(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = swtimer_expired(0x27);
  uVar2 = 0;
  if (iVar1 == 0) {
    return;
  }
  DAT_00025d04 = (float)FUN_fffb6e5c();
  if (DAT_00025d04 <= 4.3) {
    if (1.1 < DAT_00025d04 != (bool)((byte)(uVar2 >> 3) & 1)) {
      send_a_set(0);
      send_b_set(0);
      swtimer_start(0x27,5);
      DAT_0001b3ac = 5;
      return;
    }
    atu_mem_store();
    DAT_0001b3ac = 0xe;
    return;
  }
  DAT_0001b3ac = 0xf;
  return;
}


// ===== FUN_fffec911 @ fffec911 (163 bytes)

/* WARNING: Removing unreachable block (ram,0xfffec925) */
/* WARNING: Removing unreachable block (ram,0xfffec940) */
/* WARNING: Removing unreachable block (ram,0xfffec95b) */

void FUN_fffec911(void)

{
  int iVar1;
  
  iVar1 = swtimer_expired(0x27);
  if (iVar1 != 0) {
    DAT_0001b3b2 = (&DAT_fff87bfc)[(uint)DAT_0001b3bb * 4];
    DAT_0001b3ae = (&DAT_fff87bfd)[(uint)DAT_0001b3bb * 4];
    DAT_0001b3b4 = (&DAT_fff87bfe)[(uint)DAT_0001b3bb * 4];
    DAT_00020b3f = 2;
    DAT_0001b3b0 = DAT_0001b3ae;
    DAT_0001b3b3 = DAT_0001b3ae;
    swtimer_start(0x27,5);
    DAT_00025cfc = 0x437f0000;
    DAT_0001b3ac = 6;
    return;
  }
  return;
}

