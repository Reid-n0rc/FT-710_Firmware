// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffe256f @ fffe256f (7 bytes)

void FUN_fffe256f(void)

{
  FUN_fffe2622(0x82);
  return;
}


// ===== FUN_fffe2576 @ fffe2576 (7 bytes)

void FUN_fffe2576(void)

{
  FUN_fffe2622(0x83);
  return;
}


// ===== FUN_fffe257d @ fffe257d (13 bytes)

void FUN_fffe257d(void)

{
  beep_request(1);
  FUN_fffe2622(0x84);
  return;
}


// ===== FUN_fffe258a @ fffe258a (7 bytes)

void FUN_fffe258a(void)

{
  FUN_fffe2622(0x85);
  return;
}


// ===== FUN_fffe2591 @ fffe2591 (13 bytes)

void FUN_fffe2591(void)

{
  beep_request(1);
  FUN_fffe2622(0x86);
  return;
}


// ===== FUN_fffe259e @ fffe259e (17 bytes)

void FUN_fffe259e(void)

{
  beep_request(1);
  FUN_fffe2622(0x86);
  FUN_fffc4c96();
  return;
}


// ===== FUN_fffe25af @ fffe25af (17 bytes)

void FUN_fffe25af(void)

{
  FUN_fffe2622(0x86);
  swtimer_start(0x40,200);
  return;
}


// ===== FUN_fffe25c0 @ fffe25c0 (13 bytes)

void FUN_fffe25c0(void)

{
  beep_request(1);
  FUN_fffe2622(0x87);
  return;
}


// ===== FUN_fffe25cd @ fffe25cd (17 bytes)

void FUN_fffe25cd(void)

{
  beep_request(1);
  FUN_fffe2622(0x87);
  FUN_fffc4c96();
  return;
}


// ===== FUN_fffe25de @ fffe25de (17 bytes)

void FUN_fffe25de(void)

{
  FUN_fffe2622(0x87);
  swtimer_start(0x40,200);
  return;
}


// ===== FUN_fffe25ef @ fffe25ef (7 bytes)

void FUN_fffe25ef(void)

{
  FUN_fffe2622(0x88);
  return;
}


// ===== FUN_fffe25f6 @ fffe25f6 (12 bytes)

void FUN_fffe25f6(void)

{
  beep_request(1);
  FUN_fffe2622(8);
  return;
}


// ===== FUN_fffe2602 @ fffe2602 (16 bytes)

void FUN_fffe2602(void)

{
  beep_request(1);
  FUN_fffe2622(8);
  FUN_fffc4c96();
  return;
}


// ===== FUN_fffe2612 @ fffe2612 (16 bytes)

void FUN_fffe2612(void)

{
  FUN_fffe2622(8);
  swtimer_start(0x40,200);
  return;
}


// ===== FUN_fffe2622 @ fffe2622 (94 bytes)

void FUN_fffe2622(undefined1 param_1)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d6c[0xbe];
  if (cVar1 == '\x06') {
    FUN_fffe2c33(param_1);
    return;
  }
  if (cVar1 == '\x01') {
    FUN_fffe273a(param_1);
    return;
  }
  if (cVar1 == '\x02') {
    FUN_fffe2811(param_1);
    return;
  }
  if (cVar1 == '\x03') {
    FUN_fffe2912(param_1);
    return;
  }
  if (cVar1 == '\x04') {
    FUN_fffe2918(param_1);
    return;
  }
  if (cVar1 == '\x05') {
    FUN_fffe291e(param_1);
    return;
  }
  if (cVar1 != '\0') {
    return;
  }
  FUN_fffe2680(param_1);
  return;
}


// ===== FUN_fffe2680 @ fffe2680 (186 bytes)

void FUN_fffe2680(char param_1)

{
  if (DAT_0001b54f == '\x01') {
    DAT_00018813 = DAT_00009b09;
    DAT_0001880f = DAT_00009b05;
    DAT_0001880b = DAT_00009b01;
    DAT_0001b54f = '\0';
  }
  FUN_fffe29b7(PTR_DAT_00025d6c + 0xc2,param_1);
  if (param_1 == -0x7c) {
    DAT_00009b09 = DAT_00018813;
    DAT_00009b05 = DAT_0001880f;
    DAT_00009b01 = DAT_0001880b;
    DAT_0001b54f = 1;
    return;
  }
  if (param_1 == -0x7b) {
    DAT_00009b09 = DAT_00020bce;
    DAT_00009b05 = DAT_00020bca;
    DAT_00009b01 = DAT_00020bc6;
    DAT_0001b54f = 1;
    return;
  }
  return;
}


// ===== FUN_fffe273a @ fffe273a (215 bytes)

void FUN_fffe273a(char param_1)

{
  int iVar1;
  
  if (DAT_0001b550 == '\x01') {
    DAT_0001881f = DAT_00020bce;
    DAT_0001881b = DAT_00020bca;
    DAT_00018817 = DAT_00020bc6;
    DAT_0001b550 = '\0';
  }
  FUN_fffe29b7(&DAT_00020bc6,param_1);
  if (param_1 == -0x7c) {
    DAT_00020bce = DAT_0001881f;
    DAT_00020bca = DAT_0001881b;
    DAT_00020bc6 = DAT_00018817;
    DAT_0001b550 = 1;
    return;
  }
  if (param_1 == -0x7b) {
    DAT_0001b550 = 1;
    iVar1 = (uint)(byte)PTR_DAT_00025d6c[0x43a] * 0x5a;
    *(undefined4 *)(&DAT_000061a6 + iVar1) = DAT_00020bce;
    *(undefined4 *)(&DAT_000061a2 + iVar1) = DAT_00020bca;
    *(undefined4 *)(&DAT_0000619e + iVar1) = DAT_00020bc6;
    eeprom_save_memch(PTR_DAT_00025d6c[0x43a]);
    return;
  }
  return;
}


// ===== FUN_fffe2811 @ fffe2811 (257 bytes)

void FUN_fffe2811(char param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puStack_c;
  
  puVar1 = (undefined1 *)((int)&DAT_00020bc6 + (uint)(byte)PTR_DAT_00025d6c[0xbf] * 0x32);
  if (DAT_0001b551 == '\x01') {
    puVar2 = &DAT_00018823;
    puVar3 = puVar1;
    for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    DAT_0001b551 = '\0';
  }
  FUN_fffe29b7(puVar1,param_1);
  if (param_1 == -0x7c) {
    if (PTR_DAT_00025d6c[0xbf] == '\0') {
      puStack_c = &DAT_000096a0;
    }
    else if (PTR_DAT_00025d6c[0xbf] == '\x01') {
      puStack_c = &DAT_000096d3;
    }
    else if (PTR_DAT_00025d6c[0xbf] == '\x02') {
      puStack_c = &DAT_00009706;
    }
    else if (PTR_DAT_00025d6c[0xbf] == '\x03') {
      puStack_c = &DAT_00009739;
    }
    else {
      puStack_c = &DAT_0000976c;
    }
    puVar1 = &DAT_00018823;
    for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puStack_c = *puVar1;
      puStack_c = puStack_c + 1;
      puVar1 = puVar1 + 1;
    }
    DAT_0001b551 = 1;
    return;
  }
  if (param_1 == -0x7b) {
    DAT_0001b551 = 1;
    FUN_fffe481d();
    return;
  }
  return;
}


// ===== FUN_fffe2912 @ fffe2912 (6 bytes)

void FUN_fffe2912(void)

{
  return;
}


// ===== FUN_fffe2918 @ fffe2918 (6 bytes)

void FUN_fffe2918(void)

{
  return;
}


// ===== FUN_fffe291e @ fffe291e (153 bytes)

void FUN_fffe291e(char param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bStack_2;
  
  if (DAT_0001b552 == '\x01') {
    puVar2 = &DAT_00020bc6;
    puVar1 = &DAT_00018855;
    for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar1 = *(undefined1 *)puVar2;
      puVar1 = puVar1 + 1;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    DAT_0001b552 = '\0';
  }
  FUN_fffe29b7(&DAT_00020bc6,param_1);
  if (param_1 != -0x7c) {
    if (param_1 == -0x7b) {
      DAT_0001b552 = 1;
      for (bStack_2 = 0xe;
          (bStack_2 != 0 && (*(char *)((int)&DAT_00020bc6 + (uint)bStack_2) == ' '));
          bStack_2 = bStack_2 - 1) {
        *(undefined1 *)((int)&DAT_00020bc6 + (uint)bStack_2) = 0;
      }
      FUN_fffd0e37();
      return;
    }
    return;
  }
  DAT_0001b552 = 1;
  FUN_fffd0c27();
  return;
}


// ===== FUN_fffe29b7 @ fffe29b7 (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe2a1e) */
/* WARNING: Removing unreachable block (ram,0xfffe2a9a) */
/* WARNING: Removing unreachable block (ram,0xfffe2a92) */
/* WARNING: Removing unreachable block (ram,0xfffe2ada) */
/* WARNING: Removing unreachable block (ram,0xfffe2a33) */
/* WARNING: Removing unreachable block (ram,0xfffe2a48) */
/* WARNING: Removing unreachable block (ram,0xfffe2a5d) */
/* WARNING: Removing unreachable block (ram,0xfffe2a72) */
/* WARNING: Removing unreachable block (ram,0xfffe2a82) */
/* WARNING: Removing unreachable block (ram,0xfffe2ad7) */
/* WARNING: Removing unreachable block (ram,0xfffe2a07) */

int FUN_fffe29b7(int param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  
  if (param_2 == '\b') {
    iVar2 = FUN_fffe2add(param_1);
    return iVar2;
  }
  if (param_2 == -0x79) {
    iVar2 = FUN_fffe2bfd();
    if (iVar2 == 0) {
      iVar2 = 3;
      beep_request(3);
      return iVar2;
    }
  }
  else {
    if (param_2 == -0x7e) {
      iVar2 = 1;
      beep_request(1);
      PTR_DAT_00025d6c[0xc0] = 0;
      return iVar2;
    }
    if (param_2 == -0x7d) {
      iVar2 = 1;
      beep_request(1);
      PTR_DAT_00025d6c[0xc0] = 2;
      return iVar2;
    }
    if (param_2 == -0x7c) {
      iVar2 = 1;
      beep_request(1);
      PTR_DAT_00025d6c[0x90] = 0;
      return iVar2;
    }
    if (param_2 == -0x7b) {
      iVar2 = 1;
      beep_request(1);
      PTR_DAT_00025d6c[0x90] = 0;
      return iVar2;
    }
    if (param_2 == -0x7a) {
      iVar2 = FUN_fffe2bcd();
      if (iVar2 == 0) {
        iVar2 = 3;
        beep_request(3);
        return iVar2;
      }
    }
    else if (param_2 == -0x7f) {
      iVar2 = 1;
      beep_request(1);
      if (PTR_DAT_00025d6c[0xc0] == '\0') {
        PTR_DAT_00025d6c[0xc0] = 1;
        return iVar2;
      }
      if (PTR_DAT_00025d6c[0xc0] == '\x01') {
        PTR_DAT_00025d6c[0xc0] = 0;
        return iVar2;
      }
    }
    else {
      beep_request(1);
      *(char *)((uint)(byte)PTR_DAT_00025d6c[0xc1] + param_1) = param_2;
      bVar1 = PTR_DAT_00025d6c[0xc1];
      iVar2 = FUN_fffe2b7a();
      if ((int)(uint)bVar1 < iVar2) {
        PTR_DAT_00025d6c[0xc1] = PTR_DAT_00025d6c[0xc1] + '\x01';
        return iVar2;
      }
    }
  }
  return iVar2;
}


// ===== FUN_fffe2add @ fffe2add (157 bytes)

void FUN_fffe2add(int param_1)

{
  char cVar1;
  int iVar2;
  char cStack_6;
  byte local_5;
  
  if (PTR_DAT_00025d6c[0xc1] == '\0') {
    beep_request(3);
    return;
  }
  local_5 = PTR_DAT_00025d6c[0xc1];
  cVar1 = FUN_fffe2b7a();
  if ((cVar1 == PTR_DAT_00025d6c[0xc1]) && (*(char *)((uint)local_5 + param_1) != ' ')) {
    *(undefined1 *)((uint)local_5 + param_1) = 0x20;
    return;
  }
  for (cStack_6 = (cVar1 + '\x01') - PTR_DAT_00025d6c[0xc1]; cStack_6 != '\0';
      cStack_6 = cStack_6 + -1) {
    *(undefined1 *)(param_1 + (local_5 - 1)) = *(undefined1 *)((uint)local_5 + param_1);
    local_5 = local_5 + 1;
  }
  *(undefined1 *)(param_1 + (local_5 - 1)) = 0x20;
  iVar2 = FUN_fffe2bcd();
  if (iVar2 == 0) {
    beep_request(3);
    return;
  }
  return;
}


// ===== FUN_fffe2b7a @ fffe2b7a (83 bytes)

undefined1 FUN_fffe2b7a(void)

{
  uint uVar1;
  undefined1 local_2;
  
  local_2 = 0xe;
  uVar1 = (uint)(byte)PTR_DAT_00025d6c[0xbe];
  if (uVar1 == 6) {
    local_2 = 0xb;
  }
  else if (uVar1 == 1) {
    local_2 = 0xb;
  }
  else if (uVar1 == 2) {
    local_2 = 0x31;
  }
  else if (1 < uVar1 - 3) {
    if (uVar1 == 5) {
      local_2 = 0xe;
    }
    else {
      if (uVar1 != 0) {
        return 0xe;
      }
      local_2 = 0xb;
    }
  }
  return local_2;
}


// ===== FUN_fffe2bcd @ fffe2bcd (48 bytes)

bool FUN_fffe2bcd(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d6c[0xc1];
  if (cVar1 != '\0') {
    PTR_DAT_00025d6c[0xc1] = PTR_DAT_00025d6c[0xc1] + -1;
  }
  return cVar1 != '\0';
}


// ===== FUN_fffe2bfd @ fffe2bfd (54 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe2c30) */

bool FUN_fffe2bfd(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = PTR_DAT_00025d6c[0xc1];
  iVar2 = FUN_fffe2b7a();
  if ((int)(uint)bVar1 < iVar2) {
    PTR_DAT_00025d6c[0xc1] = PTR_DAT_00025d6c[0xc1] + '\x01';
  }
  return (int)(uint)bVar1 < iVar2;
}


// ===== FUN_fffe2c33 @ fffe2c33 (157 bytes)

void FUN_fffe2c33(char param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_fffd30e8();
  if (puVar1 != (undefined4 *)0x0) {
    if (DAT_0001b553 == '\x01') {
      DAT_0001886c = puVar1[2];
      DAT_00018868 = puVar1[1];
      DAT_00018864 = *puVar1;
      DAT_0001b553 = '\0';
    }
    FUN_fffe29b7(PTR_DAT_00025d6c + 0xc2,param_1);
    if (param_1 == -0x7c) {
      puVar1[2] = DAT_0001886c;
      puVar1[1] = DAT_00018868;
      *puVar1 = DAT_00018864;
      DAT_0001b553 = 1;
      return;
    }
    if (param_1 == -0x7b) {
      puVar1[2] = DAT_00020bce;
      puVar1[1] = DAT_00020bca;
      *puVar1 = DAT_00020bc6;
      DAT_0001b553 = 1;
      return;
    }
  }
  return;
}


// ===== dispreq_e7_task @ fffe2cd0 (532 bytes)

/* main_loop task 11: runs command 0x20F8C posted by DISPLAY frame 0xE7 */

void dispreq_e7_task(void)

{
  if (*(int *)(PTR_DAT_00025d70 + 0x488) == 1) {
    *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
    if ((PTR_DAT_00025d70[0x3f9] == '\x03') && (PTR_DAT_00025d70[0x3fc] != '\0')) {
      PTR_DAT_00025d70[0x3fc] = PTR_DAT_00025d70[0x3fc] + -1;
    }
    PTR_DAT_00025d70[0x3f9] = 1;
    PTR_DAT_00025d70[0x3f8] = 1;
    return;
  }
  if (*(int *)(PTR_DAT_00025d70 + 0x488) == 2) {
    *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
    if (PTR_DAT_00025d70[0x93] == '\x01') {
      PTR_DAT_00025d70[0x3fe] = 0;
      if (PTR_DAT_00025d70[0x3fd] == '\x01') {
        PTR_DAT_00025d70[0x3fd] = 0;
        PTR_DAT_00025d70[0x3f8] = 1;
        PTR_DAT_00025d70[0x3f9] = 1;
        return;
      }
      if (PTR_DAT_00025d70[0x3fd] != '\0') {
        PTR_DAT_00025d70[0x3fd] = 0;
        PTR_DAT_00025d70[0x3f8] = 1;
        PTR_DAT_00025d70[0x3f9] = 1;
        return;
      }
    }
  }
  else {
    if (*(int *)(PTR_DAT_00025d70 + 0x488) == 3) {
      *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
      return;
    }
    if (*(int *)(PTR_DAT_00025d70 + 0x488) == 4) {
      *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
      return;
    }
    if (*(int *)(PTR_DAT_00025d70 + 0x488) == 5) {
      *(undefined4 *)(PTR_DAT_00025d70 + 0x488) = 0;
      PTR_DAT_00025d70[0x93] = 0;
      PTR_DAT_00025d70[0x3f8] = 0;
      PTR_DAT_00025d70[0x92] = 0;
      beep_request(3);
      if (PTR_DAT_00025d70[0xac] == '\0') {
        PTR_DAT_00025d70[0xbb] = 0x10;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x01') {
        PTR_DAT_00025d70[0xbb] = 0x11;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x02') {
        PTR_DAT_00025d70[0xbb] = 0x12;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x03') {
        PTR_DAT_00025d70[0xbb] = 0x13;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x04') {
        PTR_DAT_00025d70[0xbb] = 0x14;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x05') {
        PTR_DAT_00025d70[0xbb] = 0x15;
      }
      else if (PTR_DAT_00025d70[0xac] == '\x06') {
        PTR_DAT_00025d70[0xbb] = 0x18;
      }
      else if (PTR_DAT_00025d70[0xac] == '\a') {
        PTR_DAT_00025d70[0xbb] = 0x19;
      }
      else {
        PTR_DAT_00025d70[0xbb] = 0x1a;
      }
      PTR_DAT_00025d70[0x86] = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffe2ee4 @ fffe2ee4 (196 bytes)

void FUN_fffe2ee4(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d70[0x418] == '\x01') {
    scan_stop();
    return;
  }
  if (PTR_DAT_00025d70[0x46b] != '\x01') {
    if ((DAT_00020b7c == '\0') && (DAT_00020f1b != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (DAT_00020cce == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      if (PTR_DAT_00025d70[0x92] == '\0') {
        PTR_DAT_00025d70[0x92] = 1;
      }
      else {
        PTR_DAT_00025d70[0x92] = 0;
      }
      PTR_DAT_00025d70[0x91] = 1;
      PTR_DAT_00025d70[0x409] = 1;
      beep_request(1);
      return;
    }
    return;
  }
  PTR_DAT_00025d70[0x46b] = 0;
  PTR_DAT_00025d70[0x46c] = 0;
  beep_request(6);
  return;
}


// ===== FUN_fffe2fa8 @ fffe2fa8 (283 bytes)

void FUN_fffe2fa8(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d70[0x418] == '\x01') {
    scan_stop();
    return;
  }
  if (PTR_DAT_00025d70[0x46c] != '\x01') {
    beep_request(1);
    if (PTR_DAT_00025d70[0x417] == '\x01') {
      PTR_DAT_00025d70[0x417] = 0;
      return;
    }
    if (PTR_DAT_00025d70[0x92] != '\x01') {
      if ((DAT_00020ccd == '\x01') || (DAT_00020b7c != '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (DAT_00020cd0 == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((bVar1) || (DAT_00020cd1 == '\x01')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) {
        DAT_00020cd5 = 0;
        PTR_DAT_00025d70[0x93] = 1;
        PTR_DAT_00025d70[0x3f8] = 1;
        PTR_DAT_00025d70[0x3f9] = 0;
        PTR_DAT_00025d70[0x3fc] = 0;
        FUN_fffc3c85();
        PTR_DAT_00025d70[0x409] = 1;
        return;
      }
    }
    return;
  }
  PTR_DAT_00025d70[0x46b] = 0;
  PTR_DAT_00025d70[0x46c] = 0;
  beep_request(6);
  return;
}


// ===== FUN_fffe30c3 @ fffe30c3 (7 bytes)

void FUN_fffe30c3(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30ca @ fffe30ca (7 bytes)

void FUN_fffe30ca(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30d1 @ fffe30d1 (7 bytes)

void FUN_fffe30d1(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30d8 @ fffe30d8 (7 bytes)

void FUN_fffe30d8(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30df @ fffe30df (7 bytes)

void FUN_fffe30df(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30e6 @ fffe30e6 (7 bytes)

void FUN_fffe30e6(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30ed @ fffe30ed (7 bytes)

void FUN_fffe30ed(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30f4 @ fffe30f4 (7 bytes)

void FUN_fffe30f4(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe30fb @ fffe30fb (7 bytes)

void FUN_fffe30fb(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe3102 @ fffe3102 (7 bytes)

void FUN_fffe3102(void)

{
  beep_request(1);
  return;
}


// ===== FUN_fffe3109 @ fffe3109 (23 bytes)

void FUN_fffe3109(void)

{
  if (PTR_DAT_00025d70[0x3fc] == '\x04') {
    return;
  }
  beep_request(1);
  return;
}


// ===== FUN_fffe3120 @ fffe3120 (1 bytes)

void FUN_fffe3120(void)

{
  return;
}


// ===== FUN_fffe3121 @ fffe3121 (202 bytes)

void FUN_fffe3121(void)

{
  char cVar1;
  
  cVar1 = PTR_DAT_00025d70[0x3fc];
  if ((byte)PTR_DAT_00025d70[0xaa] < 4) {
    if (cVar1 == '\0') {
      return;
    }
    if ((int)((byte)PTR_DAT_00025d70[0xaa] - 1) < (int)(uint)(byte)(cVar1 - 1U)) {
      PTR_DAT_00025d70[0x3fc] = PTR_DAT_00025d70[0xaa] + -1;
    }
    else {
      PTR_DAT_00025d70[0x3fc] = cVar1 - 1U;
    }
  }
  else if (cVar1 == '\0') {
    if (*(short *)(PTR_DAT_00025d70 + 0x3fa) == 0) {
      return;
    }
    *(short *)(PTR_DAT_00025d70 + 0x3fa) = *(short *)(PTR_DAT_00025d70 + 0x3fa) + -1;
  }
  else {
    PTR_DAT_00025d70[0x3fc] = cVar1 + -1;
  }
  PTR_DAT_00025d70[0x3f8] = 1;
  PTR_DAT_00025d70[0x3f9] = 1;
  PTR_DAT_00025d70[0x409] = 1;
  return;
}


// ===== FUN_fffe31eb @ fffe31eb (75 bytes)

void FUN_fffe31eb(void)

{
  if (PTR_DAT_00025d70[0x3fd] != '\0') {
    PTR_DAT_00025d70[0x3f8] = 1;
    PTR_DAT_00025d70[0x3f9] = 2;
    PTR_DAT_00025d70[0x3fd] = 2;
    PTR_DAT_00025d70[0x409] = 1;
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffe3236 @ fffe3236 (124 bytes)

void FUN_fffe3236(void)

{
  if (PTR_DAT_00025d70[0x3fc] == '\x04') {
    return;
  }
  PTR_DAT_00025d70[0x3f8] = 1;
  if (PTR_DAT_00025d70[0x3fd] == '\0') {
    PTR_DAT_00025d70[0x3fd] = 1;
    PTR_DAT_00025d70[0x3f9] = 2;
    PTR_DAT_00025d70[0x3fe] = 1;
  }
  else {
    PTR_DAT_00025d70[0x3fd] = 0;
    PTR_DAT_00025d70[0x3f9] = 2;
    PTR_DAT_00025d70[0x3fe] = 0;
  }
  PTR_DAT_00025d70[0x409] = 1;
  return;
}


// ===== FUN_fffe32b2 @ fffe32b2 (75 bytes)

void FUN_fffe32b2(void)

{
  if (PTR_DAT_00025d70[0x3fd] != '\0') {
    PTR_DAT_00025d70[0x3f8] = 1;
    PTR_DAT_00025d70[0x3f9] = 2;
    PTR_DAT_00025d70[0x3fd] = 3;
    PTR_DAT_00025d70[0x409] = 1;
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffe32fd @ fffe32fd (211 bytes)

void FUN_fffe32fd(void)

{
  ushort local_4;
  byte local_1;
  
  local_1 = PTR_DAT_00025d70[0x3fc];
  local_4 = *(ushort *)(PTR_DAT_00025d70 + 0x3fa);
  if (local_1 < 3) {
    local_1 = local_1 + 1;
  }
  else {
    local_4 = local_4 + 1;
  }
  if ((byte)PTR_DAT_00025d70[0xaa] < 4) {
    local_4 = 0;
    if ((int)((byte)PTR_DAT_00025d70[0xaa] - 1) < (int)(uint)local_1) {
      PTR_DAT_00025d70[0x3fc] = 4;
    }
    else {
      PTR_DAT_00025d70[0x3fc] = local_1;
    }
  }
  else if ((int)((byte)PTR_DAT_00025d70[0xaa] - 4) < (int)(uint)local_4) {
    local_4 = (byte)PTR_DAT_00025d70[0xaa] - 4;
    PTR_DAT_00025d70[0x3fc] = 4;
  }
  else {
    PTR_DAT_00025d70[0x3fc] = local_1;
  }
  *(ushort *)(PTR_DAT_00025d70 + 0x3fa) = local_4;
  PTR_DAT_00025d70[0x3f8] = 1;
  PTR_DAT_00025d70[0x3f9] = 1;
  PTR_DAT_00025d70[0x409] = 1;
  return;
}


// ===== FUN_fffe33d0 @ fffe33d0 (83 bytes)

void FUN_fffe33d0(void)

{
  if (PTR_DAT_00025d70[0x3fd] == '\x01') {
    return;
  }
  PTR_DAT_00025d70[0x3f8] = 1;
  PTR_DAT_00025d70[0x3f9] = 1;
  PTR_DAT_00025d70[0x3fc] = 0;
  PTR_DAT_00025d70[0x3fe] = 0;
  PTR_DAT_00025d70[0x409] = 1;
  return;
}


// ===== FUN_fffe3423 @ fffe3423 (83 bytes)

void FUN_fffe3423(void)

{
  if (PTR_DAT_00025d70[0x3fd] == '\x01') {
    return;
  }
  PTR_DAT_00025d70[0x3f8] = 1;
  PTR_DAT_00025d70[0x3f9] = 1;
  PTR_DAT_00025d70[0x3fc] = 1;
  PTR_DAT_00025d70[0x3fe] = 0;
  PTR_DAT_00025d70[0x409] = 1;
  return;
}


// ===== FUN_fffe3476 @ fffe3476 (83 bytes)

void FUN_fffe3476(void)

{
  if (PTR_DAT_00025d70[0x3fd] == '\x01') {
    return;
  }
  PTR_DAT_00025d70[0x3f8] = 1;
  PTR_DAT_00025d70[0x3f9] = 1;
  PTR_DAT_00025d70[0x3fc] = 2;
  PTR_DAT_00025d70[0x3fe] = 0;
  PTR_DAT_00025d70[0x409] = 1;
  return;
}

