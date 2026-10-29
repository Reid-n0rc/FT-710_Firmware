// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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

/* main_loop task 11: acts on the E7 status (+0x488) of the DISPLAY's PlayList recorder/player
   (0x2080048E = 1) (#65) */

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
  ushort uStack_4;
  byte bStack_1;
  
  bStack_1 = PTR_DAT_00025d70[0x3fc];
  uStack_4 = *(ushort *)(PTR_DAT_00025d70 + 0x3fa);
  if (bStack_1 < 3) {
    bStack_1 = bStack_1 + 1;
  }
  else {
    uStack_4 = uStack_4 + 1;
  }
  if ((byte)PTR_DAT_00025d70[0xaa] < 4) {
    uStack_4 = 0;
    if ((int)((byte)PTR_DAT_00025d70[0xaa] - 1) < (int)(uint)bStack_1) {
      PTR_DAT_00025d70[0x3fc] = 4;
    }
    else {
      PTR_DAT_00025d70[0x3fc] = bStack_1;
    }
  }
  else if ((int)((byte)PTR_DAT_00025d70[0xaa] - 4) < (int)(uint)uStack_4) {
    uStack_4 = (byte)PTR_DAT_00025d70[0xaa] - 4;
    PTR_DAT_00025d70[0x3fc] = 4;
  }
  else {
    PTR_DAT_00025d70[0x3fc] = bStack_1;
  }
  *(ushort *)(PTR_DAT_00025d70 + 0x3fa) = uStack_4;
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


// ===== FUN_fffe34c9 @ fffe34c9 (83 bytes)

void FUN_fffe34c9(void)

{
  if (PTR_DAT_00025d70[0x3fd] == '\x01') {
    return;
  }
  PTR_DAT_00025d70[0x3f8] = 1;
  PTR_DAT_00025d70[0x3f9] = 1;
  PTR_DAT_00025d70[0x3fc] = 3;
  PTR_DAT_00025d70[0x3fe] = 0;
  PTR_DAT_00025d70[0x409] = 1;
  return;
}


// ===== FUN_fffe351c @ fffe351c (83 bytes)

void FUN_fffe351c(void)

{
  if (PTR_DAT_00025d70[0x3fd] == '\x01') {
    return;
  }
  PTR_DAT_00025d70[0x3f8] = 1;
  PTR_DAT_00025d70[0x3f9] = 4;
  if (PTR_DAT_00025d70[0x3fe] == '\0') {
    PTR_DAT_00025d70[0x3fe] = 1;
  }
  else {
    PTR_DAT_00025d70[0x3fe] = 0;
  }
  PTR_DAT_00025d70[0x409] = 1;
  return;
}


// ===== FUN_fffe356f @ fffe356f (84 bytes)

void FUN_fffe356f(void)

{
  if ((PTR_DAT_00025d70[0x3fd] != '\x01') && (PTR_DAT_00025d70[0x3fc] != '\x04')) {
    PTR_DAT_00025d70[0xbb] = 0x17;
    PTR_DAT_00025d70[0x448] = 1;
    PTR_DAT_00025d70[0x86] = 1;
    PTR_DAT_00025d70[0x409] = 1;
    return;
  }
  return;
}


// ===== FUN_fffe35c3 @ fffe35c3 (75 bytes)

void FUN_fffe35c3(void)

{
  if (PTR_DAT_00025d70[0x3fd] != '\0') {
    return;
  }
  PTR_DAT_00025d70[0x93] = 0;
  PTR_DAT_00025d70[0x3f8] = 0;
  PTR_DAT_00025d70[0x409] = 1;
  PTR_DAT_00025d70[0x3fe] = 0;
  beep_request(1);
  return;
}


// ===== dispreq_e8_task @ fffe360e (7 bytes)

/* main_loop task 10: acts on the E8 status (+0x48C) of the DISPLAY's non-PlayList audio screens
   (voice messages) [inference] (#65) */

void dispreq_e8_task(void)

{
  FUN_fffe376a();
  FUN_fffe3615();
  return;
}


// ===== FUN_fffe3615 @ fffe3615 (341 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe3703) */
/* WARNING: Removing unreachable block (ram,0xfffe372f) */
/* WARNING: Removing unreachable block (ram,0xfffe3767) */
/* WARNING: Removing unreachable block (ram,0xfffe3764) */
/* WARNING: Removing unreachable block (ram,0xfffe375c) */
/* WARNING: Removing unreachable block (ram,0xfffe36ba) */

uint FUN_fffe3615(void)

{
  byte bVar1;
  undefined *puVar2;
  byte bVar3;
  uint uVar4;
  uint uStack_c;
  
  bVar1 = DAT_00020b2f;
  bVar3 = vfo_mode(1);
  if ((bVar3 == 3) || (bVar3 == 2)) {
    uStack_c = 0;
  }
  else {
    uStack_c = 1;
  }
  if (uStack_c != 0) {
    PTR_DAT_00025d74[0x1d1] = 0;
  }
  puVar2 = PTR_DAT_00025d74;
  if (DAT_00018870 != bVar1) {
    DAT_00018870 = bVar1;
    uStack_c = (uint)bVar1;
    if (uStack_c == 7) {
      uVar4 = FUN_fffba30c();
      *(short *)(puVar2 + 0x1d6) = (short)uVar4;
      PTR_DAT_00025d74[0x1cc] = 0;
      PTR_DAT_00025d74[0x1cd] = 0;
      return uVar4;
    }
    if (uStack_c == 5) {
      if (PTR_DAT_00025d74[0x1d1] == '\x01') {
        uVar4 = FUN_fffe5544(PTR_DAT_00025d74[0x1c8]);
        if (uVar4 != 0) {
          PTR_DAT_00025d74[0x1cd] = 1;
          return uVar4;
        }
        PTR_DAT_00025d74[0x1cc] = 1;
        return 0;
      }
    }
    else if (uStack_c == 1) {
      if (DAT_00020cd6 == '\x01') {
        DAT_00020cd6 = 0;
        uVar4 = FUN_fffe5544(PTR_DAT_00025d74[0x1c8]);
        if (uVar4 == 0) {
          PTR_DAT_00025d74[0x1cc] = 1;
        }
        else {
          PTR_DAT_00025d74[0x1cd] = 1;
        }
        DAT_00020b2f = 5;
        return uVar4;
      }
      uStack_c = FUN_fffba30c();
      *(short *)(puVar2 + 0x1d6) = (short)uStack_c;
      PTR_DAT_00025d74[0x1cc] = 0;
      PTR_DAT_00025d74[0x1cd] = 0;
      if (PTR_DAT_00025d74[0x1c9] == '\x01') {
        PTR_DAT_00025d74[0x1c9] = 0;
        return uStack_c;
      }
    }
  }
  return uStack_c;
}


// ===== FUN_fffe376a @ fffe376a (527 bytes)

void FUN_fffe376a(void)

{
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 1) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    return;
  }
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 2) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    if ((PTR_DAT_00025d74[0x78] == '\x01') && (DAT_00020b2e == '\x01')) {
      DAT_00020b2e = '\0';
    }
    PTR_DAT_00025d74[0x78] = 0;
    PTR_DAT_00025d74[0x1cf] = 0;
    PTR_DAT_00025d74[0x1d0] = 0;
    PTR_DAT_00025d74[0x1c8] = 0;
    return;
  }
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 3) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    PTR_DAT_00025d74[0x1cf] = 1;
    PTR_DAT_00025d74[0x1d0] = 0;
    return;
  }
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 4) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    return;
  }
  if (*(int *)(PTR_DAT_00025d74 + 0x48c) == 5) {
    *(undefined4 *)(PTR_DAT_00025d74 + 0x48c) = 0;
    FUN_fffe556a();
    PTR_DAT_00025d74[0x1c8] = 0;
    beep_request(3);
    if (DAT_00020b2e == '\x01') {
      DAT_00020b2e = '\0';
    }
    if (PTR_DAT_00025d74[0xac] == '\0') {
      PTR_DAT_00025d74[0xbb] = 0x10;
      PTR_DAT_00025d74[0x94] = 0;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x01') {
      PTR_DAT_00025d74[0xbb] = 0x11;
      PTR_DAT_00025d74[0x94] = 0;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x02') {
      PTR_DAT_00025d74[0xbb] = 0x12;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x03') {
      PTR_DAT_00025d74[0x78] = 0;
      PTR_DAT_00025d74[0x1cf] = 0;
      PTR_DAT_00025d74[0x1d0] = 0;
      PTR_DAT_00025d74[0x1c8] = 0;
      PTR_DAT_00025d74[0xbb] = 0x13;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x04') {
      PTR_DAT_00025d74[0xbb] = 0x14;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x05') {
      PTR_DAT_00025d74[0xbb] = 0x15;
    }
    else if (PTR_DAT_00025d74[0xac] == '\x06') {
      PTR_DAT_00025d74[0xbb] = 0x18;
    }
    else if (PTR_DAT_00025d74[0xac] == '\a') {
      PTR_DAT_00025d74[0xbb] = 0x19;
    }
    else {
      PTR_DAT_00025d74[0xbb] = 0x1a;
    }
    PTR_DAT_00025d74[0x86] = 1;
    return;
  }
  return;
}


// ===== FUN_fffe3979 @ fffe3979 (412 bytes)

/* WARNING: Removing unreachable block (ram,0xfffe3990) */
/* WARNING: Removing unreachable block (ram,0xfffe3b12) */
/* WARNING: Removing unreachable block (ram,0xfffe3b0f) */
/* WARNING: Removing unreachable block (ram,0xfffe39bb) */

int FUN_fffe3979(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined2 uVar3;
  int iVar4;
  int local_8;
  
  if (PTR_DAT_00025d74[0x418] == '\x01') {
    scan_stop();
    return param_1;
  }
  if (PTR_DAT_00025d74[0x46b] != '\x01') {
    if ((PTR_DAT_00025d74[0x417] == '\x01') || (PTR_DAT_00025d74[0x78] != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (PTR_DAT_00025d74[0x1cc] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (PTR_DAT_00025d74[0x1cd] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (PTR_DAT_00025d74[0x1c9] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) || (DAT_00020b97 == '\x01')) {
      local_8 = 1;
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      iVar4 = FUN_fffe5690();
      if ((iVar4 == 0) && (DAT_00020b96 == '\x01')) {
        local_8 = 1;
      }
      else {
        local_8 = 0;
      }
      if (local_8 == 0) {
        iVar4 = FUN_fffe56bf();
        if (iVar4 == 1) {
          PTR_DAT_00025d74[0x1c7] = 0;
          PTR_DAT_00025d74[0x94] = 1;
          PTR_DAT_00025d74[0x1d0] = 0;
          PTR_DAT_00025d74[0x1cf] = 0;
          beep_request(1);
        }
        else {
          iVar4 = FUN_fffe5690();
          if (iVar4 == 1) {
            PTR_DAT_00025d74[0x1c7] = 1;
            PTR_DAT_00025d74[0x94] = 1;
            puVar2 = PTR_DAT_00025d74;
            uVar3 = FUN_fffba30c();
            *(undefined2 *)(puVar2 + 0x1d6) = uVar3;
            PTR_DAT_00025d74[0x1d0] = 0;
            PTR_DAT_00025d74[0x1cf] = 0;
            beep_request(1);
          }
          else {
            beep_request(3);
          }
        }
        iVar4 = FUN_fffc3c85();
        return iVar4;
      }
    }
    return local_8;
  }
  PTR_DAT_00025d74[0x46b] = 0;
  PTR_DAT_00025d74[0x46c] = 0;
  iVar4 = 6;
  beep_request(6);
  return iVar4;
}


// ===== FUN_fffe3b15 @ fffe3b15 (7 bytes)

void FUN_fffe3b15(void)

{
  FUN_fffe4211(1);
  return;
}


// ===== FUN_fffe3b1c @ fffe3b1c (7 bytes)

void FUN_fffe3b1c(void)

{
  FUN_fffe4211(2);
  return;
}


// ===== FUN_fffe3b23 @ fffe3b23 (7 bytes)

void FUN_fffe3b23(void)

{
  FUN_fffe4211(3);
  return;
}


// ===== FUN_fffe3b2a @ fffe3b2a (7 bytes)

void FUN_fffe3b2a(void)

{
  FUN_fffe4211(4);
  return;
}


// ===== FUN_fffe3b31 @ fffe3b31 (7 bytes)

void FUN_fffe3b31(void)

{
  FUN_fffe4211(5);
  return;
}


// ===== FUN_fffe3b38 @ fffe3b38 (7 bytes)

void FUN_fffe3b38(void)

{
  FUN_fffe4378(1);
  return;
}


// ===== FUN_fffe3b3f @ fffe3b3f (7 bytes)

void FUN_fffe3b3f(void)

{
  FUN_fffe4378(2);
  return;
}


// ===== FUN_fffe3b46 @ fffe3b46 (7 bytes)

void FUN_fffe3b46(void)

{
  FUN_fffe4378(3);
  return;
}


// ===== FUN_fffe3b4d @ fffe3b4d (7 bytes)

void FUN_fffe3b4d(void)

{
  FUN_fffe4378(4);
  return;
}


// ===== FUN_fffe3b54 @ fffe3b54 (7 bytes)

void FUN_fffe3b54(void)

{
  FUN_fffe4378(5);
  return;
}


// ===== FUN_fffe3b5b @ fffe3b5b (7 bytes)

void FUN_fffe3b5b(void)

{
  FUN_fffe4711(1);
  return;
}


// ===== FUN_fffe3b62 @ fffe3b62 (7 bytes)

void FUN_fffe3b62(void)

{
  FUN_fffe4711(2);
  return;
}


// ===== FUN_fffe3b69 @ fffe3b69 (7 bytes)

void FUN_fffe3b69(void)

{
  FUN_fffe4711(3);
  return;
}


// ===== FUN_fffe3b70 @ fffe3b70 (7 bytes)

void FUN_fffe3b70(void)

{
  FUN_fffe4711(4);
  return;
}


// ===== FUN_fffe3b77 @ fffe3b77 (7 bytes)

void FUN_fffe3b77(void)

{
  FUN_fffe4711(5);
  return;
}


// ===== FUN_fffe3b7e @ fffe3b7e (5 bytes)

void FUN_fffe3b7e(void)

{
  FUN_fffe4407();
  return;
}

