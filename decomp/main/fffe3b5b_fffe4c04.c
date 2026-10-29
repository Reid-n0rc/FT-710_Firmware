// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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


// ===== FUN_fffe3b83 @ fffe3b83 (46 bytes)

void FUN_fffe3b83(void)

{
  beep_request(1);
  if (PTR_DAT_00025d74[0x1cf] == '\x01') {
    PTR_DAT_00025d74[0x1cf] = 0;
  }
  else {
    PTR_DAT_00025d74[0x1cf] = 1;
  }
  PTR_DAT_00025d74[0x1d0] = 0;
  return;
}


// ===== FUN_fffe3bb1 @ fffe3bb1 (46 bytes)

void FUN_fffe3bb1(void)

{
  beep_request(1);
  if (PTR_DAT_00025d74[0x1d0] == '\x01') {
    PTR_DAT_00025d74[0x1d0] = 0;
  }
  else {
    PTR_DAT_00025d74[0x1d0] = 1;
  }
  PTR_DAT_00025d74[0x1cf] = 0;
  return;
}


// ===== FUN_fffe3bdf @ fffe3bdf (5 bytes)

void FUN_fffe3bdf(void)

{
  FUN_fffe5138();
  return;
}


// ===== FUN_fffe3be4 @ fffe3be4 (320 bytes)

void FUN_fffe3be4(void)

{
  bool bVar1;
  
  beep_request(1);
  if (PTR_DAT_00025d74[0x1c7] == '\0') {
    if ((PTR_DAT_00025d74[0x78] == '\0') && (PTR_DAT_00025d74[0x417] != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (PTR_DAT_00025d74[0x1ca] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      PTR_DAT_00025d74[0x94] = 0;
      return;
    }
    PTR_DAT_00025d74[0x78] = 0;
    PTR_DAT_00025d74[0x417] = 0;
    PTR_DAT_00025d74[0x1ca] = 0;
    PTR_DAT_00025d74[0x1cb] = 0;
    if (DAT_00020b2e == '\x01') {
      DAT_00020b2e = 0;
      return;
    }
  }
  else if (PTR_DAT_00025d74[0x1c7] == '\x01') {
    if ((PTR_DAT_00025d74[0x1cc] == '\x01') || (PTR_DAT_00025d74[0x1cd] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_fffe53c0();
      return;
    }
    if (PTR_DAT_00025d74[0x1d1] == '\x01') {
      PTR_DAT_00025d74[0x1d1] = 0;
      return;
    }
    if (PTR_DAT_00025d74[0x1c9] == '\x01') {
      PTR_DAT_00025d74[0x2b] = 4;
      PTR_DAT_00025d74[0x1c9] = 0;
      return;
    }
    PTR_DAT_00025d74[0x94] = 0;
    PTR_DAT_00025d74[0x417] = 0;
    PTR_DAT_00025d74[0x1c9] = 0;
    return;
  }
  return;
}


// ===== FUN_fffe3d24 @ fffe3d24 (262 bytes)

void FUN_fffe3d24(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d74[0x94] == '\x01') || (PTR_DAT_00025d74[0x1cc] == '\x01')) {
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
  if ((bVar1) || (PTR_DAT_00025d74[0x1d1] == '\x01')) {
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
  if ((bVar1) || (PTR_DAT_00025d74[0x417] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d74[0x94] = 0;
    PTR_DAT_00025d74[0x1cc] = 0;
    PTR_DAT_00025d74[0x1cd] = 0;
    PTR_DAT_00025d74[0x417] = 0;
    PTR_DAT_00025d74[0x1d1] = 0;
    PTR_DAT_00025d74[0x2b] = 7;
    PTR_DAT_00025d74[0x1c9] = 0;
    PTR_DAT_00025d74[0x94] = 0;
    return;
  }
  return;
}


// ===== ladder_key_task @ fffe3e2a (699 bytes)

/* main_loop task 8: acts on ladder key code 0x1204C */

void ladder_key_task(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
  if (PTR_DAT_00025d78[0x86] != '\x01') {
    bVar2 = remote_key_get();
    if (DAT_0001b554 == bVar2) {
      if (bVar2 == 0xfa) {
        FUN_fffe4da3();
      }
      else if (bVar2 == 0xf8) {
        FUN_fffe4b73();
      }
      else if (bVar2 == 0xf9) {
        iVar4 = FUN_fffe419a();
        if (iVar4 == 1) {
          FUN_fffe4cc1();
        }
      }
      else if ((bVar2 == 0xf7) && (iVar4 = FUN_fffe419a(), iVar4 == 1)) {
        FUN_fffe4a67();
      }
    }
    else {
      if (DAT_00020f0b == '\x01') {
        DAT_00020f0b = 0;
        beep_stop();
        return;
      }
      if (PTR_DAT_00025d78[0x437] == '\x01') {
        FUN_fffe56e4();
        DAT_0001b554 = bVar2;
        return;
      }
      if ((bVar2 == 0) || (6 < bVar2)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) && (bVar3 = key_event_filter(bVar2 + 0x86,1), bVar3 == 0)) {
        return;
      }
      if (DAT_0001b554 == 0xfa) {
        FUN_fffe4c04();
      }
      else if (DAT_0001b554 == 1) {
        if (bVar2 == 0xf1) {
          FUN_fffe46f3();
        }
        else {
          FUN_fffe435a();
        }
      }
      else if (DAT_0001b554 == 2) {
        if (bVar2 == 0xf2) {
          FUN_fffe46f9();
        }
        else {
          FUN_fffe4360();
        }
      }
      else if (DAT_0001b554 == 3) {
        if (bVar2 == 0xf3) {
          FUN_fffe46ff();
        }
        else {
          FUN_fffe4366();
        }
      }
      else if (DAT_0001b554 == 4) {
        if (bVar2 == 0xf4) {
          FUN_fffe4705();
        }
        else {
          FUN_fffe436c();
        }
      }
      else if (DAT_0001b554 == 5) {
        if (bVar2 == 0xf5) {
          FUN_fffe470b();
        }
        else {
          FUN_fffe4372();
        }
      }
      else if (DAT_0001b554 == 6) {
        if (bVar2 == 0xf6) {
          FUN_fffe47be();
        }
        else {
          FUN_fffe46b0();
        }
      }
      else if (DAT_0001b554 == 7) {
        if (bVar2 == 0xf7) {
          FUN_fffe49fb();
        }
        else {
          FUN_fffe46d3();
        }
      }
      else if (DAT_0001b554 == 8) {
        if (bVar2 == 0xf8) {
          FUN_fffe4af8();
        }
        else {
          FUN_fffe46d4();
        }
      }
      else if (DAT_0001b554 == 9) {
        if (bVar2 == 0xf9) {
          FUN_fffe4c55();
        }
        else {
          FUN_fffe46e2();
        }
      }
      else if (DAT_0001b554 == 10) {
        if (bVar2 == 0xfa) {
          FUN_fffe4d28();
        }
        else {
          FUN_fffe46e3();
        }
      }
      else if (DAT_0001b554 == 0xb) {
        if (bVar2 == 0xfb) {
          FUN_fffe4de3();
        }
        else {
          FUN_fffe46f1();
        }
      }
      else if (DAT_0001b554 == 0xc) {
        if (bVar2 == 0xfc) {
          FUN_fffe4de4();
        }
        else {
          FUN_fffe46f2();
        }
      }
      else if (DAT_0001b554 == 0xf8) {
        FUN_fffe4bb3();
      }
      else if (DAT_0001b554 == 0) {
        switch(bVar2) {
        case 1:
          FUN_fffe41f3();
          break;
        case 2:
          FUN_fffe41f9();
          break;
        case 3:
          FUN_fffe41ff();
          break;
        case 4:
          FUN_fffe4205();
          break;
        case 5:
          FUN_fffe420b();
          break;
        case 6:
          FUN_fffe4407();
          break;
        case 7:
          FUN_fffe4f15();
          break;
        case 8:
          FUN_fffe4fa9();
          break;
        case 9:
          FUN_fffe5000();
          break;
        case 10:
          FUN_fffe50e0();
          break;
        case 0xb:
          FUN_fffe5137();
          break;
        case 0xc:
          FUN_fffe5138();
        }
      }
      DAT_00018871 = 0;
      DAT_0001b554 = bVar2;
    }
    if ((PTR_DAT_00025d78[0x1cb] == '\x01') && (bVar2 = swtimer_expired(0x37), bVar2 == 1)) {
      PTR_DAT_00025d78[0x1cb] = 0;
      PTR_DAT_00025d78[0x417] = 0;
      PTR_DAT_00025d78[0x1ca] = 0;
      PTR_DAT_00025d78[0x1c8] = 0;
      PTR_DAT_00025d78[0x2b] = 0;
      return;
    }
  }
  return;
}


// ===== FUN_fffe40e5 @ fffe40e5 (120 bytes)

void FUN_fffe40e5(void)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = DAT_00009dbd;
  bVar2 = vfo_mode(0);
  bVar3 = vfo_is_memory(bVar3);
  if (bVar3 == 1) {
    PTR_DAT_00025d78[0x46c] = 1;
    swtimer_start(0x38,0xfa);
    return;
  }
  uVar1 = (uint)bVar2;
  if ((3 < uVar1 - 4) && (uVar1 != 10 && uVar1 != 0xb)) {
    PTR_DAT_00025d78[0x46c] = 1;
    swtimer_start(0x38,5);
    return;
  }
  PTR_DAT_00025d78[0x46c] = 1;
  swtimer_start(0x38,0x32);
  return;
}


// ===== FUN_fffe415d @ fffe415d (61 bytes)

undefined1 FUN_fffe415d(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (PTR_DAT_00025d78[0x46c] == '\x01') {
    bVar1 = swtimer_expired(0x38);
    if (bVar1 == 1) {
      PTR_DAT_00025d78[0x46c] = 0;
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


// ===== FUN_fffe419a @ fffe419a (89 bytes)

undefined1 FUN_fffe419a(void)

{
  byte bVar1;
  undefined1 local_2;
  
  if (DAT_00018871 == '\0') {
    DAT_00018871 = '\x01';
    swtimer_start(0x38,200);
    local_2 = 0;
  }
  else if (DAT_00018871 == '\x01') {
    bVar1 = swtimer_expired(0x38);
    if (bVar1 == 1) {
      DAT_00018871 = '\0';
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


// ===== FUN_fffe41f3 @ fffe41f3 (6 bytes)

void FUN_fffe41f3(void)

{
  FUN_fffe4211(1);
  return;
}


// ===== FUN_fffe41f9 @ fffe41f9 (6 bytes)

void FUN_fffe41f9(void)

{
  FUN_fffe4211(2);
  return;
}


// ===== FUN_fffe41ff @ fffe41ff (6 bytes)

void FUN_fffe41ff(void)

{
  FUN_fffe4211(3);
  return;
}


// ===== FUN_fffe4205 @ fffe4205 (6 bytes)

void FUN_fffe4205(void)

{
  FUN_fffe4211(4);
  return;
}


// ===== FUN_fffe420b @ fffe420b (6 bytes)

void FUN_fffe420b(void)

{
  FUN_fffe4211(5);
  return;
}


// ===== FUN_fffe4211 @ fffe4211 (329 bytes)

void FUN_fffe4211(char param_1)

{
  bool bVar1;
  int iVar2;
  
  if (PTR_DAT_00025d78[0x90] != '\x01') {
    if (PTR_DAT_00025d78[0x93] == '\x01') {
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d78[0x417] == '\x01') {
      FUN_fffe4e6e(param_1);
      beep_request(1);
      return;
    }
    beep_request(1);
    iVar2 = FUN_fffe56bf();
    if (iVar2 == 1) {
      PTR_DAT_00025d78[0x1c7] = 0;
      if ((PTR_DAT_00025d78[0x78] == '\0') && (PTR_DAT_00025d78[0x417] == '\0')) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar1) || (PTR_DAT_00025d78[0x1ca] != '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        if (DAT_00020b2e == '\x01') {
          DAT_00020b2e = '\0';
        }
        PTR_DAT_00025d78[0x78] = 0;
        PTR_DAT_00025d78[0x417] = 0;
        PTR_DAT_00025d78[0x1ca] = 0;
        PTR_DAT_00025d78[0x1cb] = 0;
        return;
      }
      iVar2 = FUN_fffb521a();
      if (iVar2 == 1) {
        DAT_00020b2e = '\x01';
      }
      PTR_DAT_00025d78[0x78] = 1;
      PTR_DAT_00025d78[0x79] = param_1 + -1;
      PTR_DAT_00025d78[0x1c8] = param_1;
      return;
    }
    iVar2 = FUN_fffe5690();
    if (iVar2 == 1) {
      PTR_DAT_00025d78[0x1c7] = 1;
      return;
    }
  }
  return;
}


// ===== FUN_fffe435a @ fffe435a (6 bytes)

void FUN_fffe435a(void)

{
  FUN_fffe4378(1);
  return;
}


// ===== FUN_fffe4360 @ fffe4360 (6 bytes)

void FUN_fffe4360(void)

{
  FUN_fffe4378(2);
  return;
}


// ===== FUN_fffe4366 @ fffe4366 (6 bytes)

void FUN_fffe4366(void)

{
  FUN_fffe4378(3);
  return;
}


// ===== FUN_fffe436c @ fffe436c (6 bytes)

void FUN_fffe436c(void)

{
  FUN_fffe4378(4);
  return;
}


// ===== FUN_fffe4372 @ fffe4372 (6 bytes)

void FUN_fffe4372(void)

{
  FUN_fffe4378(5);
  return;
}


// ===== FUN_fffe4378 @ fffe4378 (143 bytes)

void FUN_fffe4378(undefined1 param_1)

{
  int iVar1;
  
  if ((PTR_DAT_00025d78[0x90] == '\x01') || (PTR_DAT_00025d78[0x93] == '\x01')) {
    return;
  }
  iVar1 = FUN_fffe56bf();
  if (iVar1 == 1) {
    return;
  }
  if (PTR_DAT_00025d78[0x1d1] != '\0') {
    PTR_DAT_00025d78[0x1d1] = 0;
    FUN_fffe53c0();
    return;
  }
  FUN_fffe4de5(param_1);
  return;
}


// ===== FUN_fffe4407 @ fffe4407 (681 bytes)

void FUN_fffe4407(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  
  bVar3 = vfo_mode(1);
  if (PTR_DAT_00025d78[0x90] == '\x01') {
    if ((PTR_DAT_00025d78[0xbe] == '\x02') || (PTR_DAT_00025d78[0xbe] == '\x03')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((bVar2) || (PTR_DAT_00025d78[0xbe] == '\x04')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (bVar2) {
      beep_request(1);
      return;
    }
  }
  else {
    if (PTR_DAT_00025d78[0x93] == '\x01') {
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d78[0x40d] == '\x01') {
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d78[0x39] != '\0') {
      if (PTR_DAT_00025d78[0x78] == '\x01') {
        PTR_DAT_00025d78[0x78] = 0;
        beep_request(1);
        if (DAT_00020b2e == '\x01') {
          DAT_00020b2e = '\0';
        }
      }
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d78[0x1c9] == '\x01') {
      PTR_DAT_00025d78[0x2b] = 4;
      PTR_DAT_00025d78[0x1c9] = 0;
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d78[0x78] == '\x02') {
      PTR_DAT_00025d78[0x78] = 0;
      DAT_00020ccc = 0;
      DAT_00020b2b = 0;
      beep_request(1);
      return;
    }
    if (PTR_DAT_00025d78[0x417] != '\0') {
      PTR_DAT_00025d78[0x417] = 0;
      PTR_DAT_00025d78[0x1ca] = 0;
      PTR_DAT_00025d78[0x1cf] = 0;
      PTR_DAT_00025d78[0x1d0] = 0;
      PTR_DAT_00025d78[0x1cb] = 0;
      PTR_DAT_00025d78[0x1c8] = 0;
      beep_request(1);
      return;
    }
    uVar1 = (uint)bVar3;
    if (uVar1 == 0xe) {
      PTR_DAT_00025d78[0x1c7] = 3;
      return;
    }
    if (uVar1 - 2 < 2) {
      if ((PTR_DAT_00025d78[0x1cc] == '\x01') || (PTR_DAT_00025d78[0x1cd] == '\x01')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (!bVar2) {
        if (PTR_DAT_00025d78[0x1d1] != '\x01') {
          PTR_DAT_00025d78[0x1c7] = 1;
          PTR_DAT_00025d78[0x417] = 1;
          FUN_fffe4efc();
          beep_request(1);
          return;
        }
        FUN_fffe53c0();
        return;
      }
    }
    else {
      if (3 < uVar1 - 4) {
        if (uVar1 - 0xc < 2) {
          PTR_DAT_00025d78[0x1c7] = 2;
          return;
        }
        if (1 < uVar1) {
          return;
        }
      }
      if (PTR_DAT_00025d78[0x78] != '\x01') {
        PTR_DAT_00025d78[0x1c7] = 0;
        PTR_DAT_00025d78[0x1c8] = 0;
        PTR_DAT_00025d78[0x1cf] = 0;
        PTR_DAT_00025d78[0x1d0] = 0;
        PTR_DAT_00025d78[0x417] = 1;
        FUN_fffe4efc();
        beep_request(1);
        return;
      }
      PTR_DAT_00025d78[0x78] = 0;
      beep_request(1);
      if (DAT_00020b2e == '\x01') {
        DAT_00020b2e = 0;
        return;
      }
    }
  }
  return;
}


// ===== FUN_fffe46b0 @ fffe46b0 (35 bytes)

void FUN_fffe46b0(void)

{
  PTR_DAT_00025d78[0x90] = 0;
  if (PTR_DAT_00025d78[0xbe] != '\x05') {
    return;
  }
  FUN_fffe291e(0x84);
  return;
}


// ===== FUN_fffe46d3 @ fffe46d3 (1 bytes)

void FUN_fffe46d3(void)

{
  return;
}


// ===== FUN_fffe46d4 @ fffe46d4 (14 bytes)

void FUN_fffe46d4(void)

{
  PTR_DAT_00025d78[0x46b] = 0;
  return;
}


// ===== FUN_fffe46e2 @ fffe46e2 (1 bytes)

void FUN_fffe46e2(void)

{
  return;
}


// ===== FUN_fffe46e3 @ fffe46e3 (14 bytes)

void FUN_fffe46e3(void)

{
  PTR_DAT_00025d78[0x46b] = 0;
  return;
}


// ===== FUN_fffe46f1 @ fffe46f1 (1 bytes)

void FUN_fffe46f1(void)

{
  return;
}


// ===== FUN_fffe46f2 @ fffe46f2 (1 bytes)

void FUN_fffe46f2(void)

{
  return;
}


// ===== FUN_fffe46f3 @ fffe46f3 (6 bytes)

void FUN_fffe46f3(void)

{
  FUN_fffe4711(1);
  return;
}


// ===== FUN_fffe46f9 @ fffe46f9 (6 bytes)

void FUN_fffe46f9(void)

{
  FUN_fffe4711(2);
  return;
}


// ===== FUN_fffe46ff @ fffe46ff (6 bytes)

void FUN_fffe46ff(void)

{
  FUN_fffe4711(3);
  return;
}


// ===== FUN_fffe4705 @ fffe4705 (6 bytes)

void FUN_fffe4705(void)

{
  FUN_fffe4711(4);
  return;
}


// ===== FUN_fffe470b @ fffe470b (6 bytes)

void FUN_fffe470b(void)

{
  FUN_fffe4711(5);
  return;
}


// ===== FUN_fffe4711 @ fffe4711 (173 bytes)

void FUN_fffe4711(undefined1 param_1)

{
  bool bVar1;
  int iVar2;
  
  if ((PTR_DAT_00025d78[0x92] == '\x01') || (PTR_DAT_00025d78[0x93] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return;
  }
  iVar2 = FUN_fffe56bf();
  if (iVar2 == 1) {
    return;
  }
  if (PTR_DAT_00025d78[0x1d1] == '\x01') {
    FUN_fffe53c0();
    beep_request(1);
    return;
  }
  iVar2 = FUN_fffe4de5(param_1);
  if (iVar2 != 0) {
    PTR_DAT_00025d78[0x1d1] = 1;
    return;
  }
  beep_request(3);
  return;
}


// ===== FUN_fffe47be @ fffe47be (10 bytes)

void FUN_fffe47be(void)

{
  FUN_fffe47c8();
  beep_request(1);
  return;
}


// ===== FUN_fffe47c8 @ fffe47c8 (85 bytes)

void FUN_fffe47c8(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)PTR_DAT_00025d78[0xbe];
  if (uVar1 != 6) {
    if (uVar1 == 1) {
      FUN_fffe273a(0x85);
    }
    else if (uVar1 == 2) {
      FUN_fffe2811(0x85);
    }
    else if (1 < uVar1 - 3) {
      if (uVar1 == 5) {
        FUN_fffe291e(0x85);
      }
      else {
        if (uVar1 != 0) {
          return;
        }
        FUN_fffe2680(0x85);
      }
    }
  }
  PTR_DAT_00025d78[0x90] = 0;
  return;
}


// ===== FUN_fffe481d @ fffe481d (478 bytes)

void FUN_fffe481d(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  byte bStack_a;
  byte local_9;
  byte *pbStack_8;
  char *pcStack_4;
  
  local_9 = 1;
  pcVar2 = (char *)FUN_fffe52a1();
  cVar1 = PTR_DAT_00025d78[0xbf];
  if (cVar1 == '\x04') {
    pcStack_4 = &DAT_0000976c;
    pbStack_8 = &DAT_0000976b;
  }
  else if (cVar1 == '\x01') {
    pcStack_4 = &DAT_000096d3;
    pbStack_8 = &DAT_000096d2;
  }
  else if (cVar1 == '\x02') {
    pcStack_4 = &DAT_00009706;
    pbStack_8 = &DAT_00009705;
  }
  else if (cVar1 == '\x03') {
    pcStack_4 = &DAT_00009739;
    pbStack_8 = &DAT_00009738;
  }
  else if (cVar1 == '\0') {
    pcStack_4 = &DAT_000096a0;
    pbStack_8 = &DAT_0000969f;
  }
  for (bStack_a = 0; bStack_a < 0x32; bStack_a = bStack_a + 1) {
    if (pcVar2[bStack_a] == '}') {
      local_9 = bStack_a + 1;
      break;
    }
  }
  if (bStack_a == 0x32) {
    for (bStack_a = 0x31; bStack_a != 0; bStack_a = bStack_a - 1) {
      if (0x20 < (byte)pcVar2[bStack_a]) {
        local_9 = bStack_a + 1;
        break;
      }
    }
    if (bStack_a < 0x31) {
      if (bStack_a == 0) {
        if (*pcVar2 == ' ') {
          *pcVar2 = '}';
          local_9 = 1;
        }
        else {
          pcVar2[1] = '}';
          local_9 = 2;
        }
      }
      else if (pcVar2[0x31] == ' ') {
        pcVar2[local_9] = '}';
        local_9 = local_9 + 1;
      }
    }
  }
  for (bStack_a = local_9; bStack_a < 0x32; bStack_a = bStack_a + 1) {
    pcVar2[bStack_a] = ' ';
  }
  *pbStack_8 = local_9;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pcStack_4 = *pcVar2;
    pcStack_4 = pcStack_4 + 1;
    pcVar2 = pcVar2 + 1;
  }
  if (PTR_DAT_00025d78[0xbf] == '\0') {
    eeprom_save_msg(1,1);
    return;
  }
  if (PTR_DAT_00025d78[0xbf] == '\x01') {
    eeprom_save_msg(1,2);
    return;
  }
  if (PTR_DAT_00025d78[0xbf] == '\x02') {
    eeprom_save_msg(1,3);
    return;
  }
  if (PTR_DAT_00025d78[0xbf] == '\x03') {
    eeprom_save_msg(1,4);
    return;
  }
  if (PTR_DAT_00025d78[0xbf] == '\x04') {
    eeprom_save_msg(1,5);
    return;
  }
  return;
}


// ===== FUN_fffe49fb @ fffe49fb (108 bytes)

void FUN_fffe49fb(void)

{
  bool bVar1;
  
  if (PTR_DAT_00025d78[0x90] == '\0') {
    if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (DAT_00020b99 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    beep_request(1);
    FUN_fffe52dd();
  }
  else {
    FUN_fffe4f82();
  }
  beep_request(1);
  return;
}


// ===== FUN_fffe4a67 @ fffe4a67 (145 bytes)

void FUN_fffe4a67(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d78[0x92] == '\x01') || (PTR_DAT_00025d78[0x93] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (PTR_DAT_00025d78[0x90] != '\0') {
      FUN_fffe4f82();
      return;
    }
    if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((bVar1) || (DAT_00020b99 == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      beep_request(1);
      FUN_fffe52dd();
      return;
    }
  }
  return;
}


// ===== FUN_fffe4af8 @ fffe4af8 (123 bytes)

void FUN_fffe4af8(void)

{
  bool bVar1;
  
  if ((PTR_DAT_00025d78[0x39] == '\0') && (PTR_DAT_00025d78[0x40d] != '\x01')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) || (DAT_00020b99 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    if (DAT_00018872 == '\x01') {
      FUN_fffc809d(DAT_00009dbd);
      FUN_fffe40e5();
      beep_request(1);
      return;
    }
    FUN_fffe4ff2();
    FUN_fffe419a();
    beep_request(1);
    return;
  }
  return;
}


// ===== FUN_fffe4b73 @ fffe4b73 (64 bytes)

void FUN_fffe4b73(void)

{
  int iVar1;
  
  if (DAT_00018872 == '\x01') {
    iVar1 = FUN_fffe415d();
    if (iVar1 == 1) {
      if (PTR_DAT_00025d78[0x46b] == '\x01') {
        FUN_fffc809d(DAT_00009dbd);
      }
      FUN_fffe40e5();
      return;
    }
  }
  else {
    iVar1 = FUN_fffe419a();
    if (iVar1 == 1) {
      FUN_fffe4ff2();
      return;
    }
  }
  return;
}


// ===== FUN_fffe4bb3 @ fffe4bb3 (81 bytes)

void FUN_fffe4bb3(void)

{
  byte bVar1;
  
  if ((((DAT_00018872 == '\x01') && (PTR_DAT_00025d78[0x39] == '\0')) &&
      (PTR_DAT_00025d78[0x46b] == '\x01')) && (bVar1 = scan_allowed(), bVar1 == 1)) {
    scan_start_up();
  }
  PTR_DAT_00025d78[0x46b] = 0;
  PTR_DAT_00025d78[0x46c] = 0;
  return;
}


// ===== FUN_fffe4c04 @ fffe4c04 (81 bytes)

void FUN_fffe4c04(void)

{
  byte bVar1;
  
  if ((((DAT_00018872 == '\x01') && (PTR_DAT_00025d78[0x39] == '\0')) &&
      (PTR_DAT_00025d78[0x46b] == '\x01')) && (bVar1 = scan_allowed(), bVar1 == 1)) {
    scan_start_down();
  }
  PTR_DAT_00025d78[0x46b] = 0;
  PTR_DAT_00025d78[0x46c] = 0;
  return;
}

