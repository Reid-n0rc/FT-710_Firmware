// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc04a0 @ fffc04a0 (14 bytes)

void FUN_fffc04a0(void)

{
  FUN_fffc41a3(DAT_00009aca);
  return;
}


// ===== FUN_fffc04ae @ fffc04ae (14 bytes)

void FUN_fffc04ae(void)

{
  FUN_fffc40d7(DAT_00009acb);
  return;
}


// ===== FUN_fffc04bc @ fffc04bc (14 bytes)

void FUN_fffc04bc(void)

{
  FUN_fffc410a(DAT_00009acb);
  return;
}


// ===== FUN_fffc04ca @ fffc04ca (14 bytes)

void FUN_fffc04ca(void)

{
  FUN_fffc413d(DAT_00009acb);
  return;
}


// ===== FUN_fffc04d8 @ fffc04d8 (14 bytes)

void FUN_fffc04d8(void)

{
  FUN_fffc4170(DAT_00009acb);
  return;
}


// ===== FUN_fffc04e6 @ fffc04e6 (14 bytes)

void FUN_fffc04e6(void)

{
  FUN_fffc41a3(DAT_00009acb);
  return;
}


// ===== FUN_fffc052b @ fffc052b (108 bytes)

void FUN_fffc052b(undefined1 param_1)

{
  byte bVar1;
  uint uVar2;
  
  PTR_DAT_00025d54[0x40c] = 1;
  if (DAT_00009c35 == '\x02') {
    uVar2 = vfo_freq(0,2);
    bVar1 = freq_range_index(uVar2);
    (&DAT_00009c4c)[bVar1] = param_1;
    return;
  }
  uVar2 = vfo_freq_clar(0,2);
  bVar1 = freq_range_index(uVar2);
  if (bVar1 == 0xff) {
    return;
  }
  (&DAT_00009c3e)[bVar1] = param_1;
  return;
}


// ===== FUN_fffc06ab @ fffc06ab (18 bytes)

void FUN_fffc06ab(void)

{
  FUN_fffc90b4();
  PTR_DAT_00025d54[0x1c3] = 1;
  return;
}


// ===== FUN_fffc078d @ fffc078d (13 bytes)

void FUN_fffc078d(void)

{
  FUN_fffc909f();
  FUN_fffc8d8c(2000);
  return;
}


// ===== FUN_fffc0948 @ fffc0948 (132 bytes)

void FUN_fffc0948(byte *param_1,char param_2)

{
  uint uVar1;
  bool bVar2;
  byte *local_c;
  
  bVar2 = false;
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      local_c = param_1 + 0x15;
      goto LAB_fffc09ae;
    }
    if (uVar1 - 4 < 2) {
      local_c = param_1 + 0x33;
      goto LAB_fffc09ae;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        local_c = param_1 + 0x1f;
      }
      else if (uVar1 < 2) {
        local_c = param_1 + 0xb;
      }
      else {
        bVar2 = true;
      }
      goto LAB_fffc09ae;
    }
  }
  local_c = param_1 + 0x29;
LAB_fffc09ae:
  if (bVar2) {
    return;
  }
  if (param_2 == '\0') {
    *local_c = *local_c & 0x7f;
    return;
  }
  *local_c = *local_c & 0x7f | 0x80;
  return;
}


// ===== FUN_fffc0a49 @ fffc0a49 (139 bytes)

void FUN_fffc0a49(byte *param_1,undefined1 param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      FUN_fffc0ad4(param_1 + 0x15,param_2);
      return;
    }
    if (uVar1 - 4 < 2) {
      FUN_fffc0ad4(param_1 + 0x33,param_2);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc0ac6;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          FUN_fffc0ad4(param_1 + 0x1f,param_2);
          return;
        }
        if (uVar1 < 2) {
          FUN_fffc0ad4(param_1 + 0xb,param_2);
          return;
        }
        return;
      }
    }
    FUN_fffc0ad4(param_1 + 0x3d,param_2);
    return;
  }
LAB_fffc0ac6:
  FUN_fffc0ad4(param_1 + 0x29,param_2);
  return;
}


// ===== FUN_fffc0ad4 @ fffc0ad4 (91 bytes)

void FUN_fffc0ad4(byte *param_1,char param_2)

{
  if (param_2 == '\x04') {
    *param_1 = *param_1 | 0x70;
    return;
  }
  if (param_2 == '\x01') {
    *param_1 = *param_1 & 0xcf | 0x40;
    return;
  }
  if (param_2 == '\x02') {
    *param_1 = *param_1 & 0xdf | 0x50;
    return;
  }
  if (param_2 == '\x03') {
    *param_1 = *param_1 & 0xef | 0x60;
    return;
  }
  if (param_2 != '\0') {
    return;
  }
  *param_1 = *param_1 & 0xbf;
  return;
}


// ===== FUN_fffc0b2f @ fffc0b2f (352 bytes)

void FUN_fffc0b2f(ushort param_1)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  
  if (PTR_DAT_00025d54[0x86] == '\x01') {
    scan_stop();
    FUN_fffd0046(param_1);
    beep_request(1);
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x88] == '\x01') {
    cVar2 = FUN_fffcfaa9(param_1);
    if (cVar2 == '\0') {
      PTR_DAT_00025d54[0x409] = 1;
      return;
    }
    if (cVar2 == '\x01') {
      beep_request(1);
      PTR_DAT_00025d54[0x409] = 1;
      return;
    }
    return;
  }
  if (PTR_DAT_00025d54[0x93] == '\x01') {
    beep_request(1);
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x94] == '\x01') {
    if (PTR_DAT_00025d54[0x1d1] == '\x01') {
      PTR_DAT_00025d54[0x1d1] = 0;
      beep_request(1);
    }
    else {
      if ((param_1 < 0x87) || (0x8b < param_1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        bVar3 = vfo_mode(0);
        if ((bVar3 == 2) || (bVar3 == 3)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          beep_request(1);
          return;
        }
      }
    }
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (PTR_DAT_00025d54[0x1c1] == '\0') {
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  if (0xd < (byte)PTR_DAT_00025d54[0x1c2]) {
    PTR_DAT_00025d54[0x409] = 1;
    return;
  }
  (*(code *)(&PTR_LAB_fff89d54)[(byte)PTR_DAT_00025d54[0x1c2]])(param_1);
  return;
}


// ===== FUN_fffc0c8f @ fffc0c8f (164 bytes)

void FUN_fffc0c8f(ushort param_1)

{
  bool bVar1;
  
  if ((param_1 < 0x77) || (0x86 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    FUN_fffc8d8c(1000);
    switch(param_1) {
    case 0x77:
      FUN_fffc0d33(0);
      return;
    case 0x78:
      FUN_fffc0d33(1);
      return;
    case 0x79:
      FUN_fffc0d33(2);
      return;
    case 0x7a:
      FUN_fffc0d33(3);
      return;
    case 0x7b:
      FUN_fffc0e31();
      return;
    case 0x7c:
      FUN_fffc0e3e();
      return;
    case 0x7d:
      FUN_fffc0e4b();
      return;
    case 0x7e:
      FUN_fffc0e58();
      return;
    case 0x7f:
      FUN_fffc0d33(8);
      return;
    case 0x80:
      FUN_fffc0d33(9);
      return;
    case 0x81:
      FUN_fffc0e65();
      return;
    case 0x82:
      FUN_fffc0e72();
      return;
    case 0x83:
      FUN_fffc0d33(0xc);
      return;
    case 0x84:
      FUN_fffc0d33(0xd);
      return;
    case 0x85:
      FUN_fffc0d33(0xe);
      return;
    case 0x86:
      FUN_fffc0e7f();
      return;
    }
  }
  return;
}


// ===== FUN_fffc0d33 @ fffc0d33 (54 bytes)

void FUN_fffc0d33(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 == 1) {
    FUN_fffc0eb8(param_1);
    if (PTR_DAT_00025d54[0x1c1] == '\x01') {
      beep_request(1);
    }
    PTR_DAT_00025d54[0x424] = param_1;
    return;
  }
  return;
}


// ===== FUN_fffc0d69 @ fffc0d69 (142 bytes)

undefined1 FUN_fffc0d69(void)

{
  byte bVar1;
  undefined1 local_4;
  bool local_3;
  char local_2;
  
  if (PTR_DAT_00025d54[0x417] == '\x01') {
    local_4 = 0;
  }
  else if (PTR_DAT_00025d54[0x418] == '\x01') {
    scan_stop();
    local_4 = 0;
  }
  else if (PTR_DAT_00025d54[0x67] == '\x01') {
    local_4 = 0;
  }
  else {
    if (DAT_00009dbd == '\0') {
      local_2 = DAT_00009dbe;
    }
    else {
      local_2 = DAT_00009dbf;
    }
    local_3 = DAT_00009dbd != '\0';
    if (local_2 == '\x02') {
      bVar1 = memch_current_is_special(local_3);
      if (bVar1 == 1) {
        return 0;
      }
      FUN_fffc2efb(local_3);
    }
    local_4 = 1;
  }
  return local_4;
}


// ===== FUN_fffc0df7 @ fffc0df7 (58 bytes)

void FUN_fffc0df7(undefined1 param_1)

{
  PTR_DAT_00025d54[0x1d1] = 0;
  FUN_fffc0eb8(param_1);
  if (PTR_DAT_00025d54[0x1c1] == '\x01') {
    beep_request(1);
  }
  PTR_DAT_00025d54[0x424] = param_1;
  return;
}


// ===== FUN_fffc0e31 @ fffc0e31 (13 bytes)

void FUN_fffc0e31(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(4);
  return;
}


// ===== FUN_fffc0e3e @ fffc0e3e (13 bytes)

void FUN_fffc0e3e(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(5);
  return;
}


// ===== FUN_fffc0e4b @ fffc0e4b (13 bytes)

void FUN_fffc0e4b(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(6);
  return;
}


// ===== FUN_fffc0e58 @ fffc0e58 (13 bytes)

void FUN_fffc0e58(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(7);
  return;
}


// ===== FUN_fffc0e65 @ fffc0e65 (13 bytes)

void FUN_fffc0e65(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(10);
  return;
}


// ===== FUN_fffc0e72 @ fffc0e72 (13 bytes)

void FUN_fffc0e72(void)

{
  int iVar1;
  
  iVar1 = FUN_fffc0d69();
  if (iVar1 != 1) {
    return;
  }
  FUN_fffc0df7(0xb);
  return;
}


// ===== FUN_fffc0e7f @ fffc0e7f (57 bytes)

void FUN_fffc0e7f(void)

{
  FUN_fffc8d8c(3000);
  DAT_00009dc6 = DAT_00009dc6 == '\0';
  sci3_set_baud();
  beep_request(1);
  return;
}


// ===== FUN_fffc0eb8 @ fffc0eb8 (88 bytes)

void FUN_fffc0eb8(byte param_1)

{
  byte bVar1;
  byte *local_8;
  
  if (DAT_00009dbd == '\0') {
    local_8 = &DAT_00009d09;
  }
  else {
    local_8 = &DAT_00009d63;
  }
  bVar1 = *local_8;
  *local_8 = bVar1 & 0xf0 | param_1;
  FUN_fffc0f10(bVar1 & 0xf,param_1,local_8);
  PTR_DAT_00025d54[0x40b] = 1;
  return;
}


// ===== FUN_fffc0f10 @ fffc0f10 (188 bytes)

void FUN_fffc0f10(byte param_1,byte param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (DAT_00009aa2 != '\0') {
    uVar1 = (uint)param_1;
    if (uVar1 - 4 < 0xb) {
      if (param_2 == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,param_3);
        return;
      }
      if (param_2 == 0) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,param_3);
        return;
      }
    }
    else if (uVar1 == 1) {
      if (param_2 - 2 < 0xd) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,param_3);
        return;
      }
      if (param_2 == 0) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(iVar3 << 1,param_3);
        return;
      }
    }
    else if (uVar1 - 2 < 2) {
      if (param_2 == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,param_3);
        return;
      }
      if (param_2 == 0) {
        uVar2 = FUN_fffc10ad();
        FUN_fffc0fcc(uVar2,param_3);
        return;
      }
    }
    else if (uVar1 == 0) {
      if (param_2 - 2 < 0xd) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(-iVar3,param_3);
        return;
      }
      if (param_2 == 1) {
        iVar3 = FUN_fffc10ad();
        FUN_fffc0fcc(iVar3 * -2,param_3);
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffc0fcc @ fffc0fcc (225 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc0fe3) */
/* WARNING: Removing unreachable block (ram,0xfffc0fee) */

void FUN_fffc0fcc(int param_1,undefined1 *param_2)

{
  bool bVar1;
  uint uVar2;
  uint local_c;
  
  if (param_1 != 0) {
    local_c = CONCAT31(CONCAT21(CONCAT11(param_2[0x4a],param_2[0x4b]),param_2[0x4c]),param_2[0x4d]);
    if ((local_c < 0x3b9ac9f7) && (param_1 < 0x3b9ac9f7)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (param_1 < -0x3b9ac9f6)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      local_c = local_c + param_1;
      if ((int)local_c < 0) {
        local_c = 0;
      }
      DAT_0001b4e1 = 1;
      uVar2 = freq_clamp(param_2 != &DAT_00009d09,local_c);
      DAT_0001b4e1 = 0;
      param_2[0x4a] = (char)(uVar2 >> 0x18);
      param_2[0x4b] = (char)(uVar2 >> 0x10);
      param_2[0x4c] = (char)(uVar2 >> 8);
      local_c._0_1_ = (undefined1)uVar2;
      param_2[0x4d] = (undefined1)local_c;
      vfo_mark_tuned(param_2 != &DAT_00009d09);
      return;
    }
  }
  return;
}


// ===== FUN_fffc10ad @ fffc10ad (22 bytes)

void FUN_fffc10ad(void)

{
  return;
}


// ===== freq_clamp @ fffc10c3 (229 bytes)

/* (side, f): clamp/wrap to 30k..75M (0xFFF89D4C) or PMS limits 0x20F74/78; returns f */

uint freq_clamp(char param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint local_10 [2];
  uint local_8;
  char local_1;
  
  PTR_DAT_00025d54[0x469] = 0;
  local_10[0] = param_2;
  local_8 = param_2;
  local_1 = param_1;
  if (param_1 == '\0') {
    if (DAT_00009dbe == '\x04') {
      if ((DAT_00020f74 == 0) || (DAT_00020f78 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        pms_load_limits(0);
      }
      uVar3 = freq_clamp_pms(local_10[0]);
      return uVar3;
    }
  }
  else if (DAT_00009dbf == '\x04') {
    if ((DAT_00020f74 == 0) || (DAT_00020f78 == 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      pms_load_limits(param_1);
    }
    uVar3 = freq_clamp_pms(local_10[0]);
    return uVar3;
  }
  bVar2 = range_cmp3(local_10,(uint *)&tune_limits);
  if (bVar2 == 0) {
    freq_fix_below(local_10,&tune_limits);
  }
  else if (bVar2 == 1) {
    freq_fix_above(local_10,&tune_limits);
  }
  return local_10[0];
}


// ===== freq_clamp_pms @ fffc11a8 (178 bytes)

/* PMS-limit variant of freq_clamp */

uint freq_clamp_pms(uint param_1)

{
  bool bVar1;
  uint uStack_10;
  byte bStack_9;
  uint local_4;
  
  local_4 = param_1;
  bStack_9 = range_cmp3(&local_4,(uint *)(PTR_DAT_00025d54 + 0x470));
  uStack_10 = local_4;
  if (bStack_9 == 0) {
    if ((PTR_DAT_00025d54[0x460] == '\x01') || (DAT_0001b4e2 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d54[0x469] = 1;
    }
    else {
      freq_fix_below(&uStack_10,PTR_DAT_00025d54 + 0x470);
    }
  }
  else if (bStack_9 == 1) {
    if ((PTR_DAT_00025d54[0x460] == '\x01') || (DAT_0001b4e2 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      PTR_DAT_00025d54[0x469] = 1;
    }
    else {
      freq_fix_above(&uStack_10,PTR_DAT_00025d54 + 0x470);
    }
  }
  return uStack_10;
}


// ===== vfo_mark_tuned @ fffc125a (33 bytes)

/* rt+0x444/0x446 = 1, QMB state -> VFO */

void vfo_mark_tuned(byte param_1)

{
  if (param_1 == 0) {
    PTR_DAT_00025d54[0x444] = 1;
  }
  else {
    PTR_DAT_00025d54[0x446] = 1;
  }
  qmb_exit_to_vfo(param_1);
  return;
}


// ===== qmb_exit_to_vfo @ fffc127b (144 bytes)

/* state 5 -> 1 */

void qmb_exit_to_vfo(byte param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if ((DAT_00009dbe == '\x04') || (DAT_00009dbe != '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00009dbe == '\x05')) {
      DAT_00009dbe = 1;
      return;
    }
  }
  else {
    if ((DAT_00009dbf == '\x04') || (DAT_00009dbf != '\x03')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (DAT_00009dbf == '\x05')) {
      DAT_00009dbf = 1;
      return;
    }
  }
  return;
}


// ===== freq_fix_below @ fffc130b (109 bytes)

/* Below-limit handling (clamp, or wrap while scanning) */

void freq_fix_below(void *param_1,void *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return;
  }
  if (PTR_DAT_00025d54[0x46a] != '\x01') {
    if (PTR_DAT_00025d54[0x418] != '\x01') {
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
      return;
    }
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
    return;
  }
  FUN_fffc142c(param_1,param_2);
  return;
}


// ===== freq_fix_above @ fffc1378 (111 bytes)

/* Above-limit handling (clamp, or wrap while scanning) */

void freq_fix_above(void *param_1,void *param_2)

{
  int iVar1;
  
  if (DAT_0001b4e1 == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
    return;
  }
  iVar1 = FUN_fffc13e7();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_DAT_00025d54[0x415] == '\x01') {
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
    return;
  }
  if (PTR_DAT_00025d54[0x46a] != '\x01') {
    if (PTR_DAT_00025d54[0x418] != '\x01') {
      *(undefined4 *)param_1 = *(undefined4 *)((int)param_2 + 4);
      return;
    }
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    return;
  }
  FUN_fffc14c6(param_1,param_2);
  return;
}


// ===== FUN_fffc13e7 @ fffc13e7 (69 bytes)

undefined1 FUN_fffc13e7(void)

{
  undefined1 uVar1;
  
  PTR_DAT_00025d54[0x469] = 1;
  if ((PTR_DAT_00025d54[0x460] == '\x01') || (DAT_0001b4e2 == '\x01')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_fffc142c @ fffc142c (41 bytes)

void FUN_fffc142c(uint *param_1,int param_2)

{
  undefined4 uStack_c;
  
  uStack_c = FUN_fffc1455(param_1,*(undefined4 *)(param_2 + 4));
  if (*(uint *)(param_2 + 4) < uStack_c) {
    uStack_c = uStack_c - 100000;
  }
  *param_1 = uStack_c;
  return;
}


// ===== FUN_fffc1455 @ fffc1455 (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc1470) */
/* WARNING: Removing unreachable block (ram,0xfffc149c) */
/* WARNING: Removing unreachable block (ram,0xfffc14ab) */
/* WARNING: Removing unreachable block (ram,0xfffc147f) */

void FUN_fffc1455(void)

{
  return;
}


// ===== FUN_fffc14c6 @ fffc14c6 (75 bytes)

void FUN_fffc14c6(int *param_1,undefined4 *param_2)

{
  undefined *puStack_c;
  
  if (*param_1 < 0) {
    *param_1 = (int)(&DAT_000186a0 + *param_1);
    FUN_fffc142c(param_1,param_2);
    return;
  }
  puStack_c = (undefined *)FUN_fffc1455(param_1,*param_2);
  if (puStack_c < (undefined *)*param_2) {
    puStack_c = &DAT_000186a0 + (int)puStack_c;
  }
  *param_1 = (int)puStack_c;
  return;
}


// ===== FUN_fffc151d @ fffc151d (183 bytes)

void FUN_fffc151d(ushort param_1)

{
  bool bVar1;
  
  if ((param_1 < 0x6b) || (0x76 < param_1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    PTR_DAT_00025d54[0x41e] = 1;
    PTR_DAT_00025d54[0x1dc] = (char)param_1 + -0x6b;
    PTR_DAT_00025d54[0x424] = PTR_DAT_00025d54[0x1dc];
    if (DAT_00009c5e == '\x01') {
      DAT_00009c5e = '\0';
      DAT_00009dbe = PTR_DAT_00025d54[0x484];
      DAT_00009dbf = PTR_DAT_00025d54[0x485];
      PTR_DAT_00025d54[0x483] = 0;
      DAT_00020f09 = 0;
    }
    FUN_fffc8d8c(1000);
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffc15d4 @ fffc15d4 (49 bytes)

void FUN_fffc15d4(void)

{
  if ((PTR_DAT_00025d54[0x41e] == '\x01') && (PTR_DAT_00025d54[0x1c2] == '\f')) {
    FUN_fffc1605(PTR_DAT_00025d54[0x424]);
    return;
  }
  return;
}


// ===== FUN_fffc1605 @ fffc1605 (32 bytes)

void FUN_fffc1605(byte param_1)

{
  PTR_DAT_00025d54[0x41e] = 1;
  if (0xb < param_1) {
    return;
  }
  FUN_fffc1625(param_1);
  return;
}


// ===== FUN_fffc1625 @ fffc1625 (62 bytes)

void FUN_fffc1625(byte param_1)

{
  if (PTR_DAT_00025d54[0x418] != '\x01') {
    FUN_fffbc638();
    FUN_fffc3c85();
    FUN_fffc23b6();
    FUN_fffc4caa();
    band_select(param_1);
    FUN_fffec578();
    return;
  }
  scan_stop();
  PTR_DAT_00025d54[0x409] = 1;
  return;
}


// ===== band_select @ fffc1663 (147 bytes)

/* Band key on the active side; 0x20F28 = min(band,11); dispatch by state */

void band_select(byte param_1)

{
  char local_3;
  bool local_2;
  
  if (param_1 < 0xb) {
    PTR_DAT_00025d54[0x424] = param_1;
  }
  else {
    PTR_DAT_00025d54[0x424] = 0xb;
  }
  if (DAT_00009dbd == '\0') {
    local_3 = DAT_00009dbe;
    DAT_00020f29 = 0;
  }
  else {
    local_3 = DAT_00009dbf;
    DAT_00020f2a = 0;
  }
  local_2 = DAT_00009dbd != '\0';
  vfo_store_back(local_2);
  if (local_3 == '\x04') {
    band_select_pms(local_2,param_1);
    return;
  }
  if (local_3 == '\x03') {
    band_select_memtune(local_2,param_1);
    return;
  }
  if (local_3 != '\x02') {
    band_select_vfo(local_2,param_1);
    return;
  }
  band_select_mem(local_2,param_1);
  return;
}


// ===== vfo_store_back @ fffc16f6 (233 bytes)

/* Store operating record back (band stack / memory-tune backup) according to state */

void vfo_store_back(byte param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    if (PTR_DAT_00025d54[0x443] == '\0') {
      FUN_fffc17df();
      return;
    }
    PTR_DAT_00025d54[0x443] = 0;
    if (PTR_DAT_00025d54[0x43d] == '\x01') {
      FUN_fffc18bf();
      return;
    }
    if ((DAT_00009dbe == '\x03') || (DAT_00009dbe == '\x04')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc18c3();
      return;
    }
    if (DAT_00009dbe != '\x02') {
      FUN_fffc18bf();
      return;
    }
  }
  else {
    if (PTR_DAT_00025d54[0x445] == '\0') {
      FUN_fffc184f();
      return;
    }
    PTR_DAT_00025d54[0x445] = 0;
    if (PTR_DAT_00025d54[0x43e] == '\x01') {
      FUN_fffc18bf();
      return;
    }
    if ((DAT_00009dbf == '\x03') || (DAT_00009dbf == '\x04')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffc18e1();
      return;
    }
    if (DAT_00009dbf != '\x02') {
      FUN_fffc18bf();
      return;
    }
  }
  return;
}


// ===== FUN_fffc17df @ fffc17df (112 bytes)

void FUN_fffc17df(void)

{
  bool bVar1;
  
  PTR_DAT_00025d54[0x443] = 0;
  PTR_DAT_00025d54[0x444] = 0;
  if (PTR_DAT_00025d54[0x43d] == '\x01') {
    bandstack_save();
    return;
  }
  if ((DAT_00009dbe == '\x03') || (DAT_00009dbe == '\x04')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00009dbe != '\x02') {
      bandstack_save();
      return;
    }
    return;
  }
  FUN_fffc1a0d();
  return;
}


// ===== FUN_fffc184f @ fffc184f (112 bytes)

void FUN_fffc184f(void)

{
  bool bVar1;
  
  PTR_DAT_00025d54[0x445] = 0;
  PTR_DAT_00025d54[0x446] = 0;
  if (PTR_DAT_00025d54[0x43e] == '\x01') {
    bandstack_save();
    return;
  }
  if ((DAT_00009dbf == '\x03') || (DAT_00009dbf == '\x04')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00009dbf != '\x02') {
      bandstack_save();
      return;
    }
    return;
  }
  FUN_fffc1a35();
  return;
}


// ===== FUN_fffc18bf @ fffc18bf (4 bytes)

void FUN_fffc18bf(void)

{
  bandstack_save();
  return;
}


// ===== FUN_fffc18c3 @ fffc18c3 (30 bytes)

void FUN_fffc18c3(void)

{
  memtune_backup_a();
  PTR_DAT_00025d54[0x43f] = 1;
  PTR_DAT_00025d54[0x441] = 1;
  return;
}


// ===== FUN_fffc18e1 @ fffc18e1 (30 bytes)

void FUN_fffc18e1(void)

{
  memtune_backup_b();
  PTR_DAT_00025d54[0x440] = 1;
  PTR_DAT_00025d54[0x442] = 1;
  return;
}


// ===== memtune_backup_a @ fffc18ff (20 bytes)

/* 0x9D09 -> 0x9DCE */

void memtune_backup_a(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_00009d09;
  puVar1 = &DAT_00009dce;
  for (iVar3 = 0x5a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar2;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}

