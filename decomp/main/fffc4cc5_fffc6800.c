// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc4cc5 @ fffc4cc5 (206 bytes)

undefined1 FUN_fffc4cc5(short param_1,uint param_2)

{
  undefined *puVar1;
  undefined1 local_d;
  char *pcStack_c;
  byte bStack_8;
  byte bStack_6;
  
  local_d = 0;
  if (PTR_DAT_00025d54[0x437] == '\x01') {
    if (((byte)param_2 & 0xf) == 1) {
      FUN_fffc8beb();
      PTR_DAT_00025d54[0x1c2] = 0x5e;
      puVar1 = PTR_DAT_00025d54;
      bStack_8 = 0xff;
      if ((char)(param_2 >> 4) != '\x04') {
        for (bStack_6 = 0; bStack_6 < 0x1c; bStack_6 = bStack_6 + 1) {
          if (*(short *)(BYTE_ARRAY_fff88270 + (uint)bStack_6 * 0xc + 0x154) == param_1) {
            bStack_8 = bStack_6;
            break;
          }
        }
      }
      if (bStack_8 == 0xff) {
        pcStack_c = "  DISPLAY";
      }
      else {
        pcStack_c = " LOCK/PWR" + (uint)bStack_8 * 0xc;
      }
      PTR_DAT_00025d54[0x42f] = pcStack_c[8];
      *(undefined4 *)(puVar1 + 0x42b) = *(undefined4 *)(pcStack_c + 4);
      *(undefined4 *)(puVar1 + 0x427) = *(undefined4 *)pcStack_c;
      FUN_fffc8cbb(0x5e);
      FUN_fffc8d8c();
      beep_request(1);
    }
    local_d = 1;
  }
  return local_d;
}


// ===== FUN_fffc4d93 @ fffc4d93 (89 bytes)

void FUN_fffc4d93(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined *puVar3;
  byte local_2;
  
  local_2 = DAT_00009bc9;
  if (4 < DAT_00009bc9) {
    local_2 = 4;
  }
  puVar1 = (undefined1 *)((int)&DAT_00009b2e + (uint)local_2 * 0x1f);
  iVar2 = FUN_fffede1d(&DAT_00020b4c,puVar1,0x1f);
  if (iVar2 != 0) {
    puVar3 = &DAT_00020b4c;
    for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar3 = puVar3 + 1;
      puVar1 = puVar1 + 1;
    }
    sci3_set_baud();
    return;
  }
  return;
}


// ===== FUN_fffc4dec @ fffc4dec (99 bytes)

void FUN_fffc4dec(void)

{
  bool bVar1;
  char cVar2;
  
  bVar1 = DAT_00009dbd != '\0';
  cVar2 = PTR_DAT_00025d54[0x73];
  if (cVar2 == '\x03') {
    if (PTR_DAT_00025d54[0x47a] != '\0') {
      FUN_fffc388d();
      return;
    }
    FUN_fffc3773(bVar1);
    return;
  }
  if (cVar2 == '\x01') {
    FUN_fffc3582(bVar1);
    return;
  }
  if (cVar2 == '\x02') {
    FUN_fffc3659(bVar1);
    return;
  }
  if (cVar2 != '\0') {
    return;
  }
  FUN_fffc3503(bVar1);
  return;
}


// ===== FUN_fffc4e4f @ fffc4e4f (320 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc4f7a) */

ushort FUN_fffc4e4f(void *param_1)

{
  uint uVar1;
  bool bVar2;
  undefined1 *local_10;
  ushort local_c;
  undefined1 local_9;
  byte local_8;
  byte local_7;
  
  bVar2 = false;
  if (DAT_00009dbd == '\0') {
    local_8 = DAT_00009d0d;
    local_10 = &DAT_00009d09;
    local_7 = DAT_00009d09;
  }
  else {
    local_8 = DAT_00009d67;
    local_10 = &DAT_00009d63;
    local_7 = DAT_00009d63;
  }
  local_7 = local_7 & 0xf;
  uVar1 = (uint)local_7;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      if ((local_8 & 0x20) == 0) {
        *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x1a);
      }
      else {
        local_9 = DAT_00009a9e;
        bVar2 = true;
      }
      goto LAB_fffc4f4c;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 0xc < 2) {
        if ((local_8 & 8) == 0) {
          *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x24);
        }
        else {
          local_9 = DAT_00009a8b;
          bVar2 = true;
        }
      }
      else {
        if (1 < uVar1) {
          return 0;
        }
        if ((local_8 & 0x80) == 0) {
          *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x10);
        }
        else {
          local_9 = DAT_00009a3b;
          bVar2 = true;
        }
      }
      goto LAB_fffc4f4c;
    }
  }
  if ((local_8 & 4) == 0) {
    *(undefined2 *)param_1 = *(undefined2 *)(local_10 + 0x2e);
  }
  else {
    local_9 = DAT_00009a78;
    bVar2 = true;
  }
LAB_fffc4f4c:
  if (bVar2) {
    local_c = FUN_fffb3775(local_7,local_9);
    if (param_1 != (void *)0x0) {
      *(char *)param_1 = (char)(local_c >> 8);
      *(char *)((int)param_1 + 1) = (char)local_c;
    }
  }
  else {
    local_c = CONCAT11(*(undefined1 *)param_1,*(undefined1 *)((int)param_1 + 1));
  }
  return local_c;
}


// ===== FUN_fffc4f8f @ fffc4f8f (15 bytes)

undefined1 FUN_fffc4f8f(void)

{
  return DAT_0001b4df;
}


// ===== FUN_fffc4f9e @ fffc4f9e (48 bytes)

void FUN_fffc4f9e(char param_1)

{
  if (param_1 != '\0') {
    DAT_0001b4df = 1;
    return;
  }
  DAT_0001b4e0 = DAT_00009c5a;
  DAT_0001b4df = 0;
  return;
}


// ===== FUN_fffc4fce @ fffc4fce (157 bytes)

uint FUN_fffc4fce(void *param_1)

{
  undefined *local_14;
  byte local_a;
  char local_9;
  
  if (DAT_00009dbd == '\0') {
    local_9 = DAT_00009dbe;
    local_a = DAT_00009020;
  }
  else {
    local_9 = DAT_00009dbf;
    local_a = DAT_00009022;
  }
  if (local_a == '\0') {
    if (DAT_00009ac0 == '\0') {
      local_a = 4;
    }
    else {
      local_a = 9;
    }
  }
  else {
    local_a = local_a - 1;
  }
  if (local_9 == '\x05') {
    local_14 = &DAT_00009023 + (uint)(byte)(&DAT_00009015)[local_a] * 0x5a;
    *(undefined1 *)param_1 = (&DAT_00009015)[local_a];
  }
  else {
    local_14 = (undefined *)0x0;
  }
  return (uint)local_14;
}


// ===== FUN_fffc506b @ fffc506b (53 bytes)

void FUN_fffc506b(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = FUN_fffc4fce(&bStack_2);
  if (uVar1 == 0) {
    return;
  }
  local_1 = local_1 & 3;
  *(byte *)(uVar1 + 3) = *(byte *)(uVar1 + 3) & 0xfc;
  *(byte *)(uVar1 + 3) = *(byte *)(uVar1 + 3) | local_1;
  eeprom_save_qmb_slot(bStack_2);
  return;
}


// ===== FUN_fffc50a0 @ fffc50a0 (53 bytes)

void FUN_fffc50a0(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = FUN_fffc4fce(&bStack_2);
  if (uVar1 == 0) {
    return;
  }
  local_1 = local_1 & 3;
  *(byte *)(uVar1 + 5) = *(byte *)(uVar1 + 5) & 0xfc;
  *(byte *)(uVar1 + 5) = *(byte *)(uVar1 + 5) | local_1;
  eeprom_save_qmb_slot(bStack_2);
  return;
}


// ===== FUN_fffc50d5 @ fffc50d5 (41 bytes)

void FUN_fffc50d5(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = FUN_fffc4fce(&bStack_2);
  if ((uVar1 != 0) && (local_1 < 2)) {
    FUN_fffc0948(uVar1,local_1);
    eeprom_save_qmb_slot(bStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc50fe @ fffc50fe (41 bytes)

void FUN_fffc50fe(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = FUN_fffc4fce(&bStack_2);
  if ((uVar1 != 0) && (local_1 < 5)) {
    FUN_fffc0a49(uVar1,local_1);
    eeprom_save_qmb_slot(bStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc5127 @ fffc5127 (54 bytes)

void FUN_fffc5127(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = FUN_fffc4fce(&bStack_2);
  if ((uVar1 != 0) && (local_1 < 2)) {
    if (local_1 == 0) {
      *(byte *)(uVar1 + 6) = *(byte *)(uVar1 + 6) & 0xef;
    }
    else {
      *(byte *)(uVar1 + 6) = *(byte *)(uVar1 + 6) | 0x10;
    }
    eeprom_save_qmb_slot(bStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc515d @ fffc515d (64 bytes)

void FUN_fffc515d(byte param_1)

{
  uint uVar1;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  uVar1 = FUN_fffc4fce(&bStack_2);
  if (uVar1 != 0) {
    if (0xf < local_1) {
      local_1 = 0xf;
    }
    if (local_1 == 0) {
      local_1 = 1;
    }
    *(byte *)(uVar1 + 6) = *(byte *)(uVar1 + 6) & 0xf0;
    *(byte *)(uVar1 + 6) = *(byte *)(uVar1 + 6) | local_1;
    eeprom_save_qmb_slot(bStack_2);
    return;
  }
  return;
}


// ===== FUN_fffc519d @ fffc519d (157 bytes)

bool FUN_fffc519d(ushort param_1,char param_2)

{
  bool bVar1;
  ushort uVar2;
  bool bStack_7;
  
  uVar2 = dest_code_get();
  if ((uVar2 == 0x315b) || (uVar2 == 0x50e2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return true;
  }
  if (PTR_DAT_00025d54[0x9a] == '\0') {
    return true;
  }
  if (param_2 != '\0') {
    return false;
  }
  if ((param_1 < 0x300) || (0x30e < param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if ((param_1 < 0x310) || (0x312 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      bStack_7 = false;
      goto LAB_fffc521d;
    }
  }
  bStack_7 = true;
LAB_fffc521d:
  bStack_7 = !bStack_7;
  return bStack_7;
}


// ===== FUN_fffc523a @ fffc523a (86 bytes)

undefined1 FUN_fffc523a(char param_1,char param_2,undefined1 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 local_5;
  
  uVar1 = DAT_0001b4e3;
  uVar2 = DAT_0001b4e4;
  local_5 = param_3;
  if (param_1 == '\0') {
    uVar1 = param_3;
    if (param_2 != '\0') {
      local_5 = DAT_0001b4e3;
      uVar1 = DAT_0001b4e3;
    }
  }
  else {
    uVar2 = param_3;
    if (param_2 != '\0') {
      local_5 = DAT_0001b4e4;
      uVar2 = DAT_0001b4e4;
    }
  }
  DAT_0001b4e4 = uVar2;
  DAT_0001b4e3 = uVar1;
  return local_5;
}


// ===== FUN_fffc5290 @ fffc5290 (71 bytes)

void FUN_fffc5290(void)

{
  if (DAT_00009dbd == '\0') {
    if (DAT_00009dbe == '\x01') {
      PTR_DAT_00025d54[0x443] = 1;
      return;
    }
  }
  else if (DAT_00009dbf == '\x01') {
    PTR_DAT_00025d54[0x445] = 1;
    return;
  }
  return;
}


// ===== enc_main_dial @ fffc52d7 (180 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc531a) */
/* main dial steps (encoder id 1/6) -> tuning */

void enc_main_dial(byte param_1)

{
  int iVar1;
  byte local_6;
  ushort local_4;
  byte local_1;
  
  if ((DAT_00020b8a == '\x01') || (PTR_DAT_00025d58[0x95] == '\x01')) {
    return;
  }
  local_1 = param_1;
  if (PTR_DAT_00025d58[0xa1] == '\x06') {
    if (PTR_DAT_00025d58[0x415] != '\x01') {
      return;
    }
    local_1 = param_1 << 2;
  }
  if ((char)local_1 < '\0') {
    PTR_DAT_00025d58[0x47c] = 1;
    local_6 = ~local_1 + 1;
  }
  else {
    PTR_DAT_00025d58[0x47c] = 0;
    local_6 = local_1;
  }
  DAT_0001ff6a = DAT_0001ff6a + (short)(char)local_1;
  local_4 = DAT_0001ff6a;
  if ((short)DAT_0001ff6a < 0) {
    local_4 = ~DAT_0001ff6a + 1;
  }
  iVar1 = FUN_fffc538b();
  if (iVar1 == 1) {
    FUN_fffc53dc(local_6,(int)(short)local_4);
    return;
  }
  FUN_fffc5a84(local_6,(int)(short)local_4);
  return;
}


// ===== FUN_fffc538b @ fffc538b (81 bytes)

undefined1 FUN_fffc538b(void)

{
  undefined1 local_2;
  
  if (DAT_00009c5e == '\x01') {
    local_2 = 1;
  }
  else if (DAT_00009dbd == '\0') {
    if (PTR_DAT_00025d58[0x425] == '\0') {
      local_2 = 0;
    }
    else {
      local_2 = 1;
    }
  }
  else if (PTR_DAT_00025d58[0x426] == '\0') {
    local_2 = 0;
  }
  else {
    local_2 = 1;
  }
  return local_2;
}


// ===== FUN_fffc53dc @ fffc53dc (240 bytes)

void FUN_fffc53dc(byte param_1,ushort param_2)

{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  bool local_5;
  byte local_1;
  
  bVar1 = DAT_00009dbd == '\0';
  local_5 = !bVar1;
  if (DAT_00009afe == '\0') {
    if ((param_2 & 0xfffc) == 0) {
      return;
    }
    uVar5 = (uint)(int)(short)(param_2 & 0xfffc) >> 2;
    uVar2 = uVar5 & 3;
    local_1 = (byte)uVar5 & 3;
  }
  else {
    local_1 = param_1;
    if (DAT_00009afe != '\x01') goto LAB_fffc5452;
    if ((param_2 & 0xfffe) == 0) {
      return;
    }
    uVar5 = (uint)(int)(short)(param_2 & 0xfffe) >> 1;
    uVar2 = uVar5 & 1;
    local_1 = (byte)uVar5 & 1;
  }
  if (uVar2 == 0) {
    return;
  }
LAB_fffc5452:
  FUN_fffc4caa();
  if (((PTR_DAT_00025d58[0x405] == '\x01') && (bVar4 = vfo_is_memory(bVar1), bVar4 == 1)) &&
     (bVar4 = memch_current_is_special(bVar1), bVar4 == 1)) {
    return;
  }
  if (DAT_00009c5e != '\x01') {
    FUN_fffc5767(local_5);
    return;
  }
  bVar4 = vfo_is_memory(bVar1);
  if ((bVar4 == 1) || (iVar6 = FUN_fffc2f1d(bVar1), iVar6 == 1)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar3) {
    vfo_enter_mem_state(bVar1);
    FUN_fffc2937(bVar1);
    FUN_fffc54cc(local_1,bVar1);
    return;
  }
  FUN_fffc56cd(local_1);
  return;
}


// ===== FUN_fffc54cc @ fffc54cc (117 bytes)

void FUN_fffc54cc(byte param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte local_3;
  
  local_3 = 0;
  if (PTR_DAT_00025d58[0x47c] == '\0') {
    for (; local_3 < param_1; local_3 = local_3 + 1) {
      FUN_fffc5541(param_2);
    }
  }
  else {
    for (; local_3 < param_1; local_3 = local_3 + 1) {
      FUN_fffc55d7(param_2);
    }
  }
  if ((DAT_00020f1c == '\x01') && (iVar3 = FUN_fffe5e1b(), iVar3 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    bVar2 = memch_current(param_2);
    eeprom_save_memch(bVar2);
    return;
  }
  return;
}


// ===== FUN_fffc5541 @ fffc5541 (150 bytes)

void FUN_fffc5541(byte param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bStack_5;
  byte bStack_3;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  FUN_fff9c1a1((char *)&bStack_2,(char *)&bStack_3);
  if (bStack_2 == bStack_3) {
    return;
  }
  bVar2 = memch_current(local_1);
  while( true ) {
    bStack_5 = memch_current(local_1);
    do {
      if (bStack_5 < bStack_3) {
        bStack_5 = bStack_5 + 1;
      }
      else {
        bStack_5 = bStack_2;
      }
      if ((bStack_5 < 0x84) && (0x74 < bStack_5)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    } while ((bVar1) &&
            ((iVar4 = FUN_fff9c2cd(), iVar4 == 0 ||
             (bVar3 = memch_dest_blocked(bStack_5), bVar3 == 1))));
    FUN_fffc2cdf(local_1,bStack_5);
    if (0x74 < bStack_5) break;
    bVar3 = memch_current_valid(local_1);
    if (bVar3 == 1) {
      FUN_fffc566d(local_1,bVar2);
      return;
    }
  }
  FUN_fffc566d(local_1,bVar2);
  return;
}


// ===== FUN_fffc55d7 @ fffc55d7 (150 bytes)

void FUN_fffc55d7(byte param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bStack_5;
  byte bStack_3;
  byte bStack_2;
  byte local_1;
  
  local_1 = param_1;
  FUN_fff9c1a1((char *)&bStack_2,(char *)&bStack_3);
  if (bStack_2 == bStack_3) {
    return;
  }
  bVar2 = memch_current(local_1);
  while( true ) {
    bStack_5 = memch_current(local_1);
    do {
      if (bStack_2 < bStack_5) {
        bStack_5 = bStack_5 - 1;
      }
      else {
        bStack_5 = bStack_3;
      }
      if ((bStack_5 < 0x84) && (0x74 < bStack_5)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    } while ((bVar1) &&
            ((iVar4 = FUN_fff9c2cd(), iVar4 == 0 ||
             (bVar3 = memch_dest_blocked(bStack_5), bVar3 == 1))));
    FUN_fffc2cdf(local_1,bStack_5);
    if (0x74 < bStack_5) break;
    bVar3 = memch_current_valid(local_1);
    if (bVar3 == 1) {
      FUN_fffc566d(local_1,bVar2);
      return;
    }
  }
  FUN_fffc566d(local_1,bVar2);
  return;
}


// ===== FUN_fffc566d @ fffc566d (29 bytes)

void FUN_fffc566d(byte param_1,byte param_2)

{
  byte bVar1;
  
  bVar1 = memch_current(param_1);
  if (bVar1 == param_2) {
    return;
  }
  FUN_fffc568a(param_1);
  return;
}


// ===== FUN_fffc568a @ fffc568a (67 bytes)

void FUN_fffc568a(byte param_1)

{
  vfo_store_back(param_1);
  if (param_1 == 0) {
    vfo_reload(0);
    PTR_DAT_00025d58[0x444] = 1;
  }
  else {
    vfo_reload(param_1);
    PTR_DAT_00025d58[0x444] = 1;
  }
  PTR_DAT_00025d58[0x40b] = 1;
  return;
}


// ===== FUN_fffc56cd @ fffc56cd (154 bytes)

void FUN_fffc56cd(undefined1 param_1)

{
  bool bVar1;
  char local_2;
  
  if (DAT_00009dbd == '\0') {
    if (PTR_DAT_00025d58[0x405] == '\0') {
      local_2 = '\x01';
    }
    else {
      local_2 = '\0';
    }
  }
  else if (PTR_DAT_00025d58[0x405] == '\0') {
    local_2 = '\0';
  }
  else {
    local_2 = '\x01';
  }
  if ((PTR_DAT_00025d58[0x482] == '\x01') && (PTR_DAT_00025d58[0x405] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (local_2 == '\0') {
      local_2 = '\x01';
    }
    else {
      local_2 = '\0';
    }
  }
  if (PTR_DAT_00025d58[0x3e] != '\0') {
    FUN_fffc5e0a(0,param_1);
    FUN_fffc5e0a(1,param_1);
    return;
  }
  FUN_fffc5e0a(local_2,param_1);
  return;
}


// ===== FUN_fffc5767 @ fffc5767 (49 bytes)

void FUN_fffc5767(byte param_1)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = vfo_is_memory(param_1);
  if ((bVar2 == 1) && (bVar2 = memch_current_is_special(param_1), bVar2 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((!bVar1) && (iVar3 = FUN_fffc59de(), iVar3 != 0)) {
    FUN_fffc5798();
    return;
  }
  return;
}


// ===== FUN_fffc5798 @ fffc5798 (184 bytes)

void FUN_fffc5798(void)

{
  undefined2 uVar1;
  bool local_f;
  bool local_d;
  byte *local_c;
  byte *local_8;
  byte local_3;
  
  local_f = DAT_00009dbd == '\0';
  if (local_f) {
    local_8 = &DAT_00009d09;
    local_c = &DAT_00009d63;
  }
  else {
    local_8 = &DAT_00009d63;
    local_c = &DAT_00009d09;
  }
  local_d = !local_f;
  if (PTR_DAT_00025d58[0x67] == '\0') {
    local_f = local_d;
    local_3 = *local_8 & 0xf;
  }
  else if (DAT_00009c5e == '\x01') {
    local_3 = *local_c & 0xf;
  }
  else {
    local_f = local_d;
    local_3 = *local_8 & 0xf;
  }
  uVar1 = FUN_fffc5850(local_3);
  if (PTR_DAT_00025d58[0x47c] != '\0') {
    FUN_fffc5955();
    return;
  }
  FUN_fffc58e1(uVar1,local_f);
  return;
}


// ===== FUN_fffc5850 @ fffc5850 (145 bytes)

undefined2 FUN_fffc5850(byte param_1)

{
  uint uVar1;
  undefined2 local_6;
  
  uVar1 = (uint)param_1;
  if (uVar1 - 0xc < 3) {
LAB_fffc58b3:
    if (DAT_00009afa == '\0') {
      local_6 = 5;
    }
    else if (DAT_00009afa == '\x01') {
      local_6 = 10;
    }
    else {
      local_6 = 0x14;
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      return 100;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc58b3;
      if (1 < uVar1 - 10) {
        if (3 < uVar1) {
          return 0;
        }
        if (DAT_00009af9 != '\0') {
          if (DAT_00009af9 != '\x01') {
            return 0x14;
          }
          return 10;
        }
        return 5;
      }
    }
    local_6 = 100;
  }
  return local_6;
}


// ===== FUN_fffc58e1 @ fffc58e1 (116 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc590a) */

void FUN_fffc58e1(short param_1,int param_2)

{
  short sVar1;
  undefined1 *local_c;
  undefined1 local_6;
  
  if (param_2 == 0) {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  sVar1 = CONCAT11(local_c[0x48],local_c[0x49]);
  if (param_1 != 0 && (sVar1 != -0x80000000 || param_1 != -1)) {
    sVar1 = sVar1 / param_1;
  }
  param_1 = sVar1 * param_1 + param_1;
  if (0x270e < param_1) {
    return;
  }
  local_c[0x48] = (char)((ushort)param_1 >> 8);
  local_6 = (undefined1)param_1;
  local_c[0x49] = local_6;
  vfo_mark_edited((byte)param_2);
  PTR_DAT_00025d58[0x40c] = 1;
  return;
}


// ===== FUN_fffc5955 @ fffc5955 (137 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc597e) */

void FUN_fffc5955(short param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  undefined1 *local_c;
  short local_6;
  
  if (param_2 == 0) {
    local_c = &DAT_00009d09;
  }
  else {
    local_c = &DAT_00009d63;
  }
  sVar3 = CONCAT11(local_c[0x48],local_c[0x49]);
  local_6 = sVar3;
  if (param_1 != 0 && (sVar3 != -0x80000000 || param_1 != -1)) {
    local_6 = sVar3 / param_1;
  }
  local_6 = local_6 * param_1;
  iVar1 = (int)sVar3;
  iVar2 = (int)param_1;
  iVar4 = iVar1;
  if (iVar2 != 0 && (iVar1 != -0x80000000 || iVar2 != -1)) {
    iVar4 = iVar1 / iVar2;
  }
  if ((iVar1 == iVar4 * iVar2) && (local_6 = local_6 - param_1, local_6 < -9999)) {
    return;
  }
  local_c[0x48] = (char)((ushort)local_6 >> 8);
  local_c[0x49] = (undefined1)local_6;
  vfo_mark_edited((byte)param_2);
  PTR_DAT_00025d58[0x40c] = 1;
  return;
}


// ===== FUN_fffc59de @ fffc59de (166 bytes)

undefined1 FUN_fffc59de(void)

{
  undefined1 local_9;
  undefined2 local_8;
  undefined1 local_5;
  undefined2 local_4;
  
  if (DAT_00009afe == '\0') {
    local_5 = 4;
    local_8 = 0xfff0;
  }
  else if (DAT_00009afe == '\x01') {
    local_5 = 3;
    local_8 = 0xfff8;
  }
  else {
    local_5 = 2;
    local_8 = 0xfffc;
  }
  local_4 = DAT_0001ff6a;
  if ((short)DAT_0001ff6a < 0) {
    local_4 = ~DAT_0001ff6a;
  }
  if ((local_4 & local_8) == 0) {
    local_9 = 0;
  }
  else if (((int)(short)(local_4 & local_8) >> local_5 & 1U) == 0) {
    local_9 = 0;
  }
  else {
    if ((short)DAT_0001ff6a < 0) {
      DAT_0001ff6a = local_8 | DAT_0001ff6a;
    }
    else {
      DAT_0001ff6a = ~local_8 & DAT_0001ff6a;
    }
    local_9 = 1;
  }
  return local_9;
}


// ===== FUN_fffc5a84 @ fffc5a84 (309 bytes)

void FUN_fffc5a84(undefined1 param_1,ushort param_2)

{
  undefined1 local_1;
  
  if (PTR_DAT_00025d58[0x415] == '\x01') {
    FUN_fffc8ebc();
    if ((param_2 & 0xfffc) != 0) {
      local_1 = (undefined1)((uint)(int)(short)(param_2 & 0xfffc) >> 2);
      if ((short)DAT_0001ff6a < 0) {
        DAT_0001ff6a = ~(~DAT_0001ff6a + 1 & 3) + 1;
      }
      else {
        DAT_0001ff6a = DAT_0001ff6a & 3;
      }
      goto LAB_fffc5bb0;
    }
  }
  else if (DAT_00009afe == '\0') {
    if ((param_2 & 0xfffc) != 0) {
      local_1 = (undefined1)((uint)(int)(short)(param_2 & 0xfffc) >> 2);
      if ((short)DAT_0001ff6a < 0) {
        DAT_0001ff6a = ~(~DAT_0001ff6a + 1 & 3) + 1;
      }
      else {
        DAT_0001ff6a = DAT_0001ff6a & 3;
      }
      goto LAB_fffc5bb0;
    }
  }
  else if (DAT_00009afe == '\x01') {
    if ((param_2 & 0xfffe) != 0) {
      local_1 = (undefined1)((uint)(int)(short)(param_2 & 0xfffe) >> 1);
      if ((short)DAT_0001ff6a < 0) {
        DAT_0001ff6a = ~(~DAT_0001ff6a + 1 & 1) + 1;
      }
      else {
        DAT_0001ff6a = DAT_0001ff6a & 1;
      }
      goto LAB_fffc5bb0;
    }
  }
  else if (param_2 != 0) {
    DAT_0001ff6a = 0;
    local_1 = param_1;
LAB_fffc5bb0:
    FUN_fffc5bb9(local_1);
    return;
  }
  return;
}


// ===== FUN_fffc5bb9 @ fffc5bb9 (214 bytes)

void FUN_fffc5bb9(undefined1 param_1)

{
  bool bVar1;
  byte bVar2;
  char local_3;
  bool local_2;
  
  local_2 = DAT_00009dbd != '\0';
  if (PTR_DAT_00025d58[0x418] == '\x01') {
    FUN_fffe5d2a();
    return;
  }
  if (PTR_DAT_00025d58[0x46b] != '\x01') {
    if ((PTR_DAT_00025d58[0x67] == '\x01') && (DAT_00009c5e == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if (PTR_DAT_00025d58[0x405] == '\x01') {
        if (local_2) {
          local_2 = false;
        }
        else {
          local_2 = true;
        }
      }
      if (local_2 == false) {
        local_3 = DAT_00009dbe;
      }
      else {
        local_3 = DAT_00009dbf;
      }
      if (local_3 == '\x02') {
        bVar2 = memch_current_is_special(local_2);
        if (bVar2 == 1) {
          return;
        }
        vfo_mem_to_memtune(local_2);
        PTR_DAT_00025d58[0x40b] = 1;
      }
      FUN_fffc5e0a(local_2,param_1);
      return;
    }
    FUN_fffc5c8f(local_2,param_1);
    return;
  }
  return;
}


// ===== FUN_fffc5c8f @ fffc5c8f (81 bytes)

void FUN_fffc5c8f(byte param_1,undefined1 param_2)

{
  byte bVar1;
  char local_3;
  
  if (param_1 == 0) {
    local_3 = DAT_00009dbe;
  }
  else {
    local_3 = DAT_00009dbf;
  }
  if (local_3 == '\x02') {
    bVar1 = memch_current_is_special(param_1);
    if (bVar1 == 1) {
      return;
    }
    vfo_mem_to_memtune(param_1);
    PTR_DAT_00025d58[0x40b] = 1;
  }
  FUN_fffc5e0a(param_1,param_2);
  return;
}


// ===== vfo_mem_to_memtune @ fffc5ce0 (51 bytes)

/* state 2 -> 4 (PMS pair) or 3 (memory tune) */

void vfo_mem_to_memtune(char param_1)

{
  byte bVar1;
  undefined1 uStack_2;
  
  bVar1 = pms_load_limits(param_1);
  if (bVar1 == 1) {
    uStack_2 = 4;
  }
  else {
    uStack_2 = 3;
  }
  if (param_1 != '\0') {
    DAT_00009dbf = uStack_2;
    return;
  }
  DAT_00009dbe = uStack_2;
  return;
}


// ===== pms_load_limits @ fffc5d13 (247 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc5d92) */
/* WARNING: Removing unreachable block (ram,0xfffc5d8c) */
/* WARNING: Removing unreachable block (ram,0xfffc5db6) */
/* WARNING: Removing unreachable block (ram,0xfffc5dbc) */
/* P-pair channel freqs -> 0x20F74/0x20F78 (sorted) */

byte pms_load_limits(byte param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbStack_8;
  byte bStack_3;
  byte local_1;
  
  local_1 = param_1;
  bStack_3 = memch_current(param_1);
  if ((bStack_3 < 99) || (0x74 < bStack_3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if ((bStack_3 & 1) == 0) {
      bStack_3 = bStack_3 - 1;
    }
    bVar1 = memch_valid(bStack_3,&pbStack_8);
    if ((bVar1) && (bVar1 = memch_valid(bStack_3 + 1,&pbStack_8), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      iVar2 = (uint)bStack_3 * 0x5a;
      uVar3 = (uint)(byte)(&DAT_0000619a)[iVar2] << 0x18 |
              (uint)(byte)(&DAT_0000619b)[iVar2] << 0x10 | (uint)(byte)(&DAT_0000619c)[iVar2] << 8 |
              (uint)(byte)(&DAT_0000619d)[iVar2];
      iVar2 = (uint)bStack_3 * 0x5a;
      uVar4 = (uint)(byte)(&DAT_000061f4)[iVar2] << 0x18 |
              (uint)(byte)(&DAT_000061f5)[iVar2] << 0x10 | (uint)(byte)(&DAT_000061f6)[iVar2] << 8 |
              (uint)(byte)(&DAT_000061f7)[iVar2];
      if (uVar4 < uVar3) {
        *(uint *)(PTR_DAT_00025d58 + 0x470) = uVar4;
        *(uint *)(PTR_DAT_00025d58 + 0x474) = uVar3;
      }
      else {
        *(uint *)(PTR_DAT_00025d58 + 0x470) = uVar3;
        *(uint *)(PTR_DAT_00025d58 + 0x474) = uVar4;
      }
      return 1;
    }
  }
  return 0;
}


// ===== FUN_fffc5e0a @ fffc5e0a (186 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc5e38) */
/* WARNING: Removing unreachable block (ram,0xfffc5e3e) */

void FUN_fffc5e0a(byte param_1,byte param_2)

{
  uint local_c;
  byte *local_8;
  byte local_3;
  
  if (param_1 == 0) {
    local_8 = (byte *)&DAT_00009d53;
  }
  else {
    local_8 = (byte *)&DAT_00009dad;
  }
  local_c = (uint)*local_8 << 0x18 | (uint)local_8[1] << 0x10 | (uint)local_8[2] << 8 |
            (uint)local_8[3];
  PTR_DAT_00025d58[0x46d] = 1;
  local_3 = 0;
  if (PTR_DAT_00025d58[0x47c] == '\0') {
    for (; local_3 < param_2; local_3 = local_3 + 1) {
      local_c = FUN_fffc5ec4(param_1,local_c);
    }
  }
  else {
    for (; local_3 < param_2; local_3 = local_3 + 1) {
      local_c = FUN_fffc6073(param_1,local_c);
    }
  }
  *local_8 = (byte)(local_c >> 0x18);
  local_8[1] = (byte)(local_c >> 0x10);
  local_8[2] = (byte)(local_c >> 8);
  local_8[3] = (byte)local_c;
  PTR_DAT_00025d58[0x46d] = 0;
  return;
}


// ===== FUN_fffc5ec4 @ fffc5ec4 (104 bytes)

uint FUN_fffc5ec4(byte param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uStack_14;
  uint local_10 [2];
  uint local_8;
  byte local_1;
  
  if ((PTR_DAT_00025d58[0x415] == '\0') && (PTR_DAT_00025d58[0x46a] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  uVar3 = param_2;
  local_8 = param_2;
  local_1 = param_1;
  if (bVar1) {
    FUN_fffc6103(param_1,&local_8,(int *)local_10);
    uVar3 = local_10[0];
  }
  local_10[0] = uVar3;
  uVar3 = FUN_fffc616e(local_1);
  local_10[0] = uVar3 + local_10[0];
  bVar2 = FUN_fffc5f2c(local_1,local_10);
  if (bVar2 == 1) {
    uStack_14 = local_10[0];
  }
  else {
    uStack_14 = local_8;
  }
  return uStack_14;
}


// ===== FUN_fffc5f2c @ fffc5f2c (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc5f9a) */

byte FUN_fffc5f2c(byte param_1,void *param_2)

{
  byte bVar1;
  uint uVar2;
  
  if (PTR_DAT_00025d58[0x67] == '\0') {
    uVar2 = freq_clamp(param_1,*(uint *)param_2);
    *(uint *)param_2 = uVar2;
  }
  else if (DAT_00009c5e == '\x01') {
    uVar2 = freq_clamp(param_1,*(uint *)param_2);
    *(uint *)param_2 = uVar2;
  }
  else {
    bVar1 = FUN_fffc5f9d(param_1,*(uint *)param_2);
    if (bVar1 == 0) {
      return 0;
    }
  }
  vfo_mark_tuned(param_1);
  PTR_DAT_00025d58[0x40c] = 1;
  return 1;
}


// ===== FUN_fffc5f9d @ fffc5f9d (214 bytes)

byte FUN_fffc5f9d(char param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  uint freq;
  bool bStack_11;
  uint local_10;
  char local_a;
  uint local_8;
  char local_1;
  
  if (param_1 == '\0') {
    local_a = DAT_00009dbe;
  }
  else {
    local_a = DAT_00009dbf;
  }
  if ((local_a == '\x02') || (local_a == '\a')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (local_a != '\b')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  local_8 = param_2;
  local_1 = param_1;
  if (bVar1) {
    if ((local_a == '\x04') &&
       (local_10 = param_2, bVar2 = range_cmp3(&local_10,(uint *)(PTR_DAT_00025d58 + 0x470)),
       bVar2 != 2)) {
      return 0;
    }
  }
  else {
    bVar2 = memch_current_is_special(param_1);
    if (bVar2 == 1) {
      return 0;
    }
  }
  if (PTR_DAT_00025d58[0xba] == '\x01') {
    if ((local_8 < 1800000) || (74999999 < local_8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      bStack_11 = true;
    }
    else {
      bStack_11 = false;
    }
  }
  else {
    freq = tx_freq_repeater_shift(local_8);
    bStack_11 = tx_freq_allowed(freq);
  }
  return bStack_11;
}


// ===== FUN_fffc6073 @ fffc6073 (144 bytes)

uint FUN_fffc6073(byte param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uStack_18;
  uint local_10 [2];
  uint local_8;
  byte local_1;
  
  if ((PTR_DAT_00025d58[0x415] == '\0') && (PTR_DAT_00025d58[0x46a] == '\0')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  local_10[0] = param_2;
  local_8 = param_2;
  local_1 = param_1;
  if ((!bVar1) || (bVar1 = FUN_fffc6103(param_1,&local_8,(int *)local_10), bVar1)) {
    uVar3 = FUN_fffc616e(local_1);
    if (local_10[0] < uVar3) {
      local_10[0] = 0;
    }
    else {
      local_10[0] = local_10[0] - uVar3;
    }
    bVar2 = FUN_fffc5f2c(local_1,local_10);
    if (bVar2 == 1) {
      uStack_18 = local_10[0];
    }
    else {
      uStack_18 = local_8;
    }
  }
  else {
    bVar2 = FUN_fffc5f2c(local_1,local_10);
    if (bVar2 == 1) {
      uStack_18 = local_10[0];
    }
    else {
      uStack_18 = local_8;
    }
  }
  return uStack_18;
}


// ===== FUN_fffc6103 @ fffc6103 (107 bytes)

bool FUN_fffc6103(byte param_1,uint *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uStack_14;
  
  DAT_0001b4e5 = 1;
  DAT_0001b4e6 = '\0';
  uStack_14 = FUN_fffc616e(param_1);
  DAT_0001b4e5 = 0;
  if (DAT_0001b4e6 == '\x01') {
    uStack_14 = uStack_14 * 10;
  }
  uVar1 = *param_2;
  uVar3 = uVar1;
  if (uStack_14 != 0) {
    uVar3 = uVar1 / uStack_14;
  }
  uVar2 = *param_2;
  if (uStack_14 != 0) {
    uVar2 = uVar2 / uStack_14;
  }
  *param_3 = uVar2 * uStack_14;
  return uVar1 == uVar3 * uStack_14;
}


// ===== FUN_fffc616e @ fffc616e (320 bytes)

uint FUN_fffc616e(byte param_1)

{
  bool bVar1;
  short sVar2;
  byte local_d;
  undefined *local_c;
  
  local_d = DAT_00009d09;
  if (param_1 != 0) {
    local_d = DAT_00009d63;
  }
  local_d = local_d & 0xf;
  if (PTR_DAT_00025d58[0x415] == '\x01') {
    if (PTR_DAT_00025d58[0x416] == '\0') {
      local_c = &DAT_000f4240;
    }
    else {
      local_c = (undefined *)0x3e8;
    }
  }
  else if (PTR_DAT_00025d58[0x46a] == '\x01') {
    if (PTR_DAT_00025d58[0x479] == '\x01') {
      local_c = &DAT_000186a0;
    }
    else {
      local_c = &DAT_000f4240;
    }
  }
  else {
    if ((PTR_DAT_00025d58[0x418] == '\x01') || (PTR_DAT_00025d58[0x46b] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if ((local_d == 6) || (local_d == 7)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 10)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 0xb)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 4)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (local_d == 5)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        local_c = (undefined *)FUN_fffc63e6(local_d);
      }
      else {
        sVar2 = FUN_fffc62ae(local_d);
        local_c = (undefined *)(int)sVar2;
      }
    }
    else if (PTR_DAT_00025d58[0x46d] == '\x01') {
      sVar2 = FUN_fffc62ae(local_d);
      local_c = (undefined *)(int)sVar2;
    }
    else if (PTR_DAT_00025d58[0x478] == '\x01') {
      local_c = (undefined *)FUN_fffc63e6(local_d);
    }
    else {
      sVar2 = FUN_fffc62ae(local_d);
      local_c = (undefined *)(int)sVar2;
    }
  }
  return (uint)local_c;
}


// ===== FUN_fffc62ae @ fffc62ae (312 bytes)

short FUN_fffc62ae(byte param_1)

{
  uint uVar1;
  short local_6;
  
  uVar1 = (uint)param_1;
  if (uVar1 - 0xc < 3) {
LAB_fffc6393:
    if (DAT_00009c61 == '\x01') {
      local_6 = 1;
    }
    else {
      if (DAT_00009afa == '\0') {
        local_6 = 5;
      }
      else if (DAT_00009afa == '\x01') {
        local_6 = 10;
      }
      else {
        local_6 = 0x14;
      }
      if (DAT_00009c61 == '\x02') {
        local_6 = local_6 * 10;
      }
    }
  }
  else {
    if (uVar1 - 4 < 2) {
      if (DAT_00009c61 == '\x01') {
        return 10;
      }
      if (DAT_00009c61 != '\x02') {
        return 100;
      }
      return 1000;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fffc6393;
      if (1 < uVar1 - 10) {
        if (3 < uVar1) {
          return local_6;
        }
        if (DAT_00009c61 != '\x01') {
          if (DAT_00009af9 == '\0') {
            local_6 = 5;
          }
          else if (DAT_00009af9 == '\x01') {
            local_6 = 10;
          }
          else {
            local_6 = 0x14;
          }
          if (DAT_00009c61 != '\x02') {
            return local_6;
          }
          return local_6 * 10;
        }
        return 1;
      }
    }
    if (DAT_00009c61 == '\x01') {
      local_6 = 10;
    }
    else {
      local_6 = 100;
      if (DAT_00009c61 == '\x02') {
        local_6 = 1000;
      }
    }
  }
  return local_6;
}


// ===== FUN_fffc63e6 @ fffc63e6 (166 bytes)

uint FUN_fffc63e6(byte param_1)

{
  uint uVar1;
  byte local_d;
  
  uVar1 = (uint)param_1;
  if (3 < uVar1) {
    if (uVar1 - 4 < 2) {
      local_d = DAT_00009afc;
      if (5 < DAT_00009afc) {
        local_d = 0;
      }
      uVar1 = FUN_fffc648c((uint)*(ushort *)(BYTE_ARRAY_fff88514 + (uint)local_d * 2 + 8));
      return uVar1;
    }
    if (uVar1 - 6 < 2) {
LAB_fffc6462:
      local_d = DAT_00009afd;
      if (5 < DAT_00009afd) {
        local_d = 0;
      }
      uVar1 = FUN_fffc648c((uint)*(ushort *)(BYTE_ARRAY_fff88514 + (uint)local_d * 2 + 0x14));
      return uVar1;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 - 10 < 2) goto LAB_fffc6462;
      if (2 < uVar1 - 0xc) {
        return 0;
      }
    }
  }
  local_d = DAT_00009afb;
  if (3 < DAT_00009afb) {
    local_d = 0;
  }
  uVar1 = FUN_fffc648c((uint)*(ushort *)(BYTE_ARRAY_fff88514 + (uint)local_d * 2));
  return uVar1;
}


// ===== FUN_fffc648c @ fffc648c (52 bytes)

uint FUN_fffc648c(uint param_1)

{
  undefined4 local_4;
  
  local_4 = param_1;
  if (DAT_00009c61 == '\x02') {
    if (DAT_0001b4e5 == '\x01') {
      DAT_0001b4e6 = 1;
    }
    else {
      local_4 = param_1 * 10;
    }
  }
  return local_4;
}


// ===== enc2_step @ fffc64c0 (213 bytes)

/* encoder id 2 by screen [inference: multi knob] */

void enc2_step(char param_1)

{
  bool bVar1;
  
  if (PTR_DAT_00025d58[0x437] == '\x01') {
    FUN_fffc670d((int)param_1);
    return;
  }
  FUN_fffc4caa();
  if (PTR_DAT_00025d58[0x9a] != '\x01') {
    if (PTR_DAT_00025d58[0x86] != '\x01') {
      if (PTR_DAT_00025d58[0x95] == '\x01') {
        FUN_fffd1790((int)param_1);
        return;
      }
      if (PTR_DAT_00025d58[0xba] != '\x01') {
        if ((PTR_DAT_00025d58[0x93] == '\x01') || (PTR_DAT_00025d58[0x94] == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (!bVar1) {
          if (PTR_DAT_00025d58[0x96] == '\x01') {
            FUN_fffc7c55((int)param_1);
            return;
          }
          FUN_fffc6c20((int)param_1);
          return;
        }
        FUN_fffc6595((int)param_1);
        return;
      }
      FUN_fffbb963((int)param_1);
      return;
    }
    if (PTR_DAT_00025d58[0x448] == '\x01') {
      if ('\0' < param_1) {
        PTR_DAT_00025d58[0xbd] = 1;
        return;
      }
      PTR_DAT_00025d58[0xbd] = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffc6595 @ fffc6595 (376 bytes)

void FUN_fffc6595(char param_1)

{
  if (PTR_DAT_00025d58[0x93] == '\x01') {
    if (PTR_DAT_00025d58[0x3fe] == '\x01') {
      PTR_DAT_00025d58[0x3f8] = 1;
      PTR_DAT_00025d58[0x3f9] = 4;
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (DAT_00009dc1 != 0)) {
          DAT_00009dc1 = DAT_00009dc1 - 1;
          return;
        }
      }
      else if (DAT_00009dc1 < 100) {
        DAT_00009dc1 = DAT_00009dc1 + 1;
        return;
      }
    }
    else {
      if (param_1 < '\0') {
        FUN_fffe3121();
        return;
      }
      if ('\0' < param_1) {
        FUN_fffe32fd();
        return;
      }
    }
  }
  else if (PTR_DAT_00025d58[0x94] == '\x01') {
    if (PTR_DAT_00025d58[0x1cf] == '\x01') {
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (DAT_00009dc1 != 0)) {
          DAT_00009dc1 = DAT_00009dc1 - 1;
          return;
        }
      }
      else if (DAT_00009dc1 < 100) {
        DAT_00009dc1 = DAT_00009dc1 + 1;
        return;
      }
    }
    else if (PTR_DAT_00025d58[0x1d0] == '\x01') {
      if (param_1 < '\x01') {
        if ((param_1 < '\0') && (DAT_00009dc2 != 0)) {
          DAT_00009dc2 = DAT_00009dc2 - 1;
          return;
        }
      }
      else if (DAT_00009dc2 < 100) {
        DAT_00009dc2 = DAT_00009dc2 + 1;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffc670d @ fffc670d (243 bytes)

void FUN_fffc670d(char param_1)

{
  byte bVar1;
  
  if (DAT_0001b4eb == '\x01') {
    bVar1 = swtimer_expired(0x47);
    if (bVar1 == 0) {
      return;
    }
    DAT_0001b4eb = '\0';
  }
  if (DAT_0001b4ea == '\0') {
    DAT_0001b4ea = 1;
    FUN_fff98727(DAT_0001b4e9,1);
    swtimer_start(0x47,100);
    DAT_0001b4eb = 1;
    return;
  }
  DAT_0001b4ea = 0;
  FUN_fff98727(DAT_0001b4e9,0);
  swtimer_start(0x47,100);
  DAT_0001b4eb = 1;
  if ('\0' < param_1) {
    if (DAT_0001b4e9 < DAT_0001b4e7) {
      DAT_0001b4e9 = DAT_0001b4e9 + 1;
      return;
    }
    DAT_0001b4e9 = DAT_0001b4e8;
    return;
  }
  if (DAT_0001b4e8 < DAT_0001b4e9) {
    DAT_0001b4e9 = DAT_0001b4e9 - 1;
    return;
  }
  DAT_0001b4e9 = DAT_0001b4e7;
  return;
}


// ===== FUN_fffc6800 @ fffc6800 (111 bytes)

void FUN_fffc6800(char param_1)

{
  char cVar1;
  
  if (PTR_DAT_00025d58[0x43c] == '\0') {
    if (PTR_DAT_00025d58[0x1d9] == '\0') {
      FUN_fffc686f((int)param_1);
      return;
    }
    if (PTR_DAT_00025d58[0x43b] == '\0') {
      FUN_fffc6bd8((int)param_1);
      return;
    }
  }
  cVar1 = PTR_DAT_00025d58[0x1da];
  if (cVar1 == '\x03') {
    FUN_fffc6b86((int)param_1);
    return;
  }
  if (cVar1 != '\x02') {
    if (cVar1 == '\x01') {
      FUN_fffc6ac4((int)param_1);
      return;
    }
    return;
  }
  FUN_fffc6b34((int)param_1);
  return;
}

