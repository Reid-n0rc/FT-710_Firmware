// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fff9340d @ fff9340d (1 bytes)

void FUN_fff9340d(void)

{
  return;
}


// ===== r_sci0_transmit_interrupt @ fff9340e (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93444) */
/* WARNING: Removing unreachable block (ram,0xfff9340e) */
/* WARNING: Removing unreachable block (ram,0xfff93456) */

undefined4 r_sci0_transmit_interrupt(undefined4 param_1)

{
  byte bVar1;
  
  if (DAT_0001b604 == 0) {
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 & 0x7f;
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 | 4;
    return param_1;
  }
  DAT_0008a003 = *DAT_000207f4;
  DAT_000207f4 = DAT_000207f4 + 1;
  DAT_0001b604 = DAT_0001b604 + -1;
  return param_1;
}


// ===== r_sci0_receive_interrupt @ fff9347f (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff934e5) */
/* WARNING: Removing unreachable block (ram,0xfff934ed) */
/* WARNING: Removing unreachable block (ram,0xfff934eb) */
/* WARNING: Removing unreachable block (ram,0xfff9347f) */
/* WARNING: Removing unreachable block (ram,0xfff93481) */
/* WARNING: Removing unreachable block (ram,0xfff934e7) */

undefined4 r_sci0_receive_interrupt(undefined4 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b606 < DAT_0001b608) {
    uVar2 = DAT_0008a005;
    *DAT_000207f8 = uVar2;
    FUN_fff9352d();
    DAT_000207f8 = DAT_000207f8 + 1;
    DAT_0001b606 = DAT_0001b606 + 1;
  }
  if (DAT_0001b608 <= DAT_0001b606) {
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 & 0xbf;
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 & 0xef;
    r_sci0_callback_receiveend();
    return param_1;
  }
  return param_1;
}


// ===== FUN_fff93518 @ fff93518 (5 bytes)

void FUN_fff93518(void)

{
  FUN_fffb1d5b();
  return;
}


// ===== r_sci0_callback_receiveend @ fff9351d (15 bytes)

void r_sci0_callback_receiveend(void)

{
  cat_rx_complete(2,DAT_0001b608);
  return;
}


// ===== FUN_fff9352c @ fff9352c (1 bytes)

void FUN_fff9352c(void)

{
  return;
}


// ===== FUN_fff9352d @ fff9352d (33 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9354b) */

undefined4 FUN_fff9352d(void)

{
  DAT_000207f8 = FUN_fffb1dad(&DAT_0001b606,&DAT_0001b608,DAT_000207f8,5);
  return DAT_000207f8;
}


// ===== R_SCI1_Create @ fff9354e (161 bytes)

/* SCI1 init (DISPLAY link / boot SCI) */

void R_SCI1_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0xbfffffff;
  bVar2 = DAT_0008733c;
  DAT_0008733c = bVar2 & 0xfa | 10;
  bVar2 = DAT_0008733d;
  DAT_0008733d = bVar2 & 0xfa | 10;
  DAT_0008a022 = 0;
  DAT_0008a022 = 0;
  bVar2 = DAT_0008a029;
  DAT_0008a029 = bVar2 & 0xfe;
  DAT_0008a02d = 0;
  DAT_0008a020 = 8;
  DAT_0008a026 = 0x72;
  DAT_0008a027 = 0x10;
  DAT_0008a021 = 10;
  DAT_0008c158 = 10;
  bVar2 = DAT_0008c063;
  DAT_0008c063 = bVar2 | 1;
  DAT_0008c156 = 10;
  bVar2 = DAT_0008c022;
  DAT_0008c022 = bVar2 | 0x40;
  bVar2 = DAT_0008c002;
  DAT_0008c002 = bVar2 | 0x40;
  FUN_fff9373a();
  return;
}


// ===== FUN_fff935ef @ fff935ef (64 bytes)

void FUN_fff935ef(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008703d;
  DAT_0008703d = bVar1 & 0xfe;
  bVar1 = DAT_0008703c;
  DAT_0008703c = bVar1 & 0xfe;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 | 0x20;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 4;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 | 0x10;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 8;
  return;
}


// ===== R_SCI1_Serial_Receive @ fff93697 (68 bytes)

undefined2 R_SCI1_Serial_Receive(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    DAT_0001b60c = 0;
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 | 0x40;
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 | 0x10;
    DAT_0001b60e = param_2;
    DAT_00020800 = param_1;
  }
  return local_a;
}


// ===== R_SCI1_Serial_Send @ fff936db (95 bytes)

undefined2 R_SCI1_Serial_Send(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    bVar1 = DAT_00087207;
    if ((bVar1 & 0x20) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = DAT_00087207;
      DAT_00087207 = bVar1 & 0xdf;
      bVar1 = DAT_0008a022;
      DAT_0008a022 = bVar1 | 0xa0;
      bVar1 = DAT_0008c062;
      DAT_0008c062 = bVar1 | 0x40;
      bVar1 = DAT_00087207;
      DAT_00087207 = bVar1 | 0x20;
      DAT_0001b60a = param_2;
      DAT_000207fc = param_1;
    }
  }
  return local_a;
}


// ===== FUN_fff9373a @ fff9373a (1 bytes)

void FUN_fff9373a(void)

{
  return;
}


// ===== r_sci1_transmit_interrupt @ fff9373b (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93771) */
/* WARNING: Removing unreachable block (ram,0xfff9373b) */
/* WARNING: Removing unreachable block (ram,0xfff93783) */

undefined4 r_sci1_transmit_interrupt(undefined4 param_1)

{
  byte bVar1;
  
  if (DAT_0001b60a == 0) {
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 & 0x7f;
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 | 4;
    return param_1;
  }
  DAT_0008a023 = *DAT_000207fc;
  DAT_000207fc = DAT_000207fc + 1;
  DAT_0001b60a = DAT_0001b60a + -1;
  return param_1;
}


// ===== r_sci1_receive_interrupt @ fff937ac (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93812) */
/* WARNING: Removing unreachable block (ram,0xfff9381a) */
/* WARNING: Removing unreachable block (ram,0xfff93818) */
/* WARNING: Removing unreachable block (ram,0xfff937ac) */
/* WARNING: Removing unreachable block (ram,0xfff937ae) */
/* WARNING: Removing unreachable block (ram,0xfff93814) */

undefined4 r_sci1_receive_interrupt(undefined4 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b60c < DAT_0001b60e) {
    uVar2 = DAT_0008a025;
    *DAT_00020800 = uVar2;
    FUN_fff9384c();
    DAT_00020800 = DAT_00020800 + 1;
    DAT_0001b60c = DAT_0001b60c + 1;
  }
  if (DAT_0001b60e <= DAT_0001b60c) {
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 & 0xbf;
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 & 0xef;
    FUN_fff93846();
    return param_1;
  }
  return param_1;
}


// ===== FUN_fff93845 @ fff93845 (1 bytes)

void FUN_fff93845(void)

{
  return;
}


// ===== FUN_fff93846 @ fff93846 (5 bytes)

void FUN_fff93846(void)

{
  FUN_fffb1745();
  return;
}


// ===== FUN_fff9384b @ fff9384b (1 bytes)

void FUN_fff9384b(void)

{
  return;
}


// ===== FUN_fff9384c @ fff9384c (570 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93a53) */

void FUN_fff9384c(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  if ((DAT_0001b60c == 0) || (iVar3 = FUN_fffb23f3(1), iVar3 != 1)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    cVar1 = *DAT_00020800;
    DAT_00020800 = DAT_00020800 + -(uint)DAT_0001b60c;
    *DAT_00020800 = cVar1;
    DAT_0001b60c = 0;
  }
  if (DAT_0001b60c == 0) {
    cVar1 = *DAT_00020800;
    if ((cVar1 == '\x06') || (cVar1 == '\x15')) {
      DAT_0001b60e = 1;
    }
    else if (cVar1 != 'Z') {
      if (cVar1 == 'e') {
        DAT_0001b60e = 9;
      }
      else if (cVar1 == -0x3d) {
        DAT_0001b60e = 0x23;
      }
      else if (cVar1 == -0x3c) {
        DAT_0001b60e = 0x107;
      }
      else if (cVar1 == -0x3b) {
        DAT_0001b60e = 7;
      }
      else if (cVar1 == -0x20) {
        DAT_0001b60e = 6;
      }
      else if (cVar1 == -0x1f) {
        DAT_0001b60e = 7;
      }
      else if (cVar1 == -0x1e) {
        DAT_0001b60e = 7;
      }
      else if (cVar1 == -0x1d) {
        DAT_0001b60e = 9;
      }
      else if (cVar1 == -0x1c) {
        DAT_0001b60e = 5;
      }
      else if (cVar1 == -0x1b) {
        DAT_0001b60e = 5;
      }
      else if (cVar1 == -0x1a) {
        DAT_0001b60e = 5;
      }
      else if (cVar1 == -0x19) {
        DAT_0001b60e = 10;
      }
      else if (cVar1 == -0x18) {
        DAT_0001b60e = 10;
      }
      else if (cVar1 == -2) {
        DAT_0001b60e = 7;
      }
      else if (cVar1 == -0xf) {
        DAT_0001b60e = 8;
      }
      else if (cVar1 == -3) {
        DAT_0001b60e = 0xb;
      }
      else if (cVar1 == -0x10) {
        DAT_0001b60e = 10;
      }
      else {
        DAT_00020800 = DAT_00020800 + -1;
        DAT_0001b60c = 0xffff;
      }
    }
  }
  if ((DAT_0001b60c == 2) && (DAT_00020800[-2] == 'Z')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    DAT_0001b60e = CONCAT11(*DAT_00020800,DAT_00020800[-1]) + 4;
  }
  FUN_fffb237a(1,10);
  return;
}


// ===== R_SCI2_Create @ fff93a86 (163 bytes)

/* SCI2 init (external tuner / ETUN port) */

void R_SCI2_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0xdfffffff;
  bVar2 = DAT_0008733e;
  DAT_0008733e = bVar2 & 0xf8 | 8;
  bVar2 = DAT_0008733f;
  DAT_0008733f = bVar2 & 0xf8 | 8;
  DAT_0008a042 = 0;
  DAT_0008a042 = 0;
  bVar2 = DAT_0008a049;
  DAT_0008a049 = bVar2 & 0xfe;
  DAT_0008a04d = 0;
  DAT_0008a040 = 1;
  DAT_0008a046 = 0x72;
  DAT_0008a047 = 0x10;
  DAT_0008a041 = 0xc2;
  DAT_0008c14a = 10;
  bVar2 = DAT_0008c061;
  DAT_0008c061 = bVar2 | 4;
  DAT_0008c14b = 10;
  bVar2 = DAT_0008c021;
  DAT_0008c021 = bVar2 | 8;
  bVar2 = DAT_0008c001;
  DAT_0008c001 = bVar2 | 8;
  FUN_fff93c7b();
  return;
}


// ===== FUN_fff93b29 @ fff93b29 (64 bytes)

void FUN_fff93b29(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008703f;
  DAT_0008703f = bVar1 & 0xfe;
  bVar1 = DAT_0008703e;
  DAT_0008703e = bVar1 & 0xfe;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 | 0x80;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x10;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 | 0x40;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x20;
  return;
}


// ===== R_SCI2_Stop @ fff93b69 (104 bytes)

void R_SCI2_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008c061;
  DAT_0008c061 = bVar1 & 0xf7;
  bVar1 = DAT_0008a042;
  DAT_0008a042 = bVar1 & 0xdf;
  bVar1 = DAT_0008a042;
  DAT_0008a042 = bVar1 & 0xef;
  bVar1 = DAT_0008a042;
  DAT_0008a042 = bVar1 & 0x7f;
  bVar1 = DAT_0008a042;
  DAT_0008a042 = bVar1 & 0xbf;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 & 0x7f;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xffffffef;
  bVar1 = DAT_0008703f;
  DAT_0008703f = bVar1 & 0xfe;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 & 0xbf;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xffffffdf;
  bVar1 = DAT_0008703e;
  DAT_0008703e = bVar1 & 0xfe;
  return;
}


// ===== R_SCI2_Serial_Receive @ fff93bd1 (68 bytes)

undefined2 R_SCI2_Serial_Receive(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    DAT_0001b612 = 0;
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 | 0x40;
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 | 0x10;
    DAT_0001b614 = param_2;
    DAT_00020808 = param_1;
  }
  return local_a;
}


// ===== R_SCI2_Serial_Send @ fff93c15 (102 bytes)

undefined2 R_SCI2_Serial_Send(undefined4 param_1,short param_2)

{
  char cVar1;
  byte bVar2;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    cVar1 = DAT_00087207;
    if (cVar1 < '\0') {
      bVar2 = DAT_00087207;
      DAT_00087207 = bVar2 & 0x7f;
      bVar2 = DAT_0008a042;
      DAT_0008a042 = bVar2 | 0xa0;
      bVar2 = DAT_0008c061;
      DAT_0008c061 = bVar2 | 8;
      bVar2 = DAT_00087207;
      DAT_00087207 = bVar2 | 0x80;
      DAT_0001b610 = param_2;
      DAT_00020804 = param_1;
    }
    else {
      local_a = 0x80;
    }
  }
  return local_a;
}


// ===== FUN_fff93c7b @ fff93c7b (1 bytes)

void FUN_fff93c7b(void)

{
  return;
}


// ===== r_sci2_transmit_interrupt @ fff93c7c (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93cb2) */
/* WARNING: Removing unreachable block (ram,0xfff93c7c) */
/* WARNING: Removing unreachable block (ram,0xfff93cc4) */

undefined4 r_sci2_transmit_interrupt(undefined4 param_1)

{
  byte bVar1;
  
  if (DAT_0001b610 == 0) {
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 & 0x7f;
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 | 4;
    return param_1;
  }
  DAT_0008a043 = *DAT_00020804;
  DAT_00020804 = DAT_00020804 + 1;
  DAT_0001b610 = DAT_0001b610 + -1;
  return param_1;
}


// ===== r_sci2_receive_interrupt @ fff93ced (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93d53) */
/* WARNING: Removing unreachable block (ram,0xfff93d5b) */
/* WARNING: Removing unreachable block (ram,0xfff93d59) */
/* WARNING: Removing unreachable block (ram,0xfff93ced) */
/* WARNING: Removing unreachable block (ram,0xfff93cef) */
/* WARNING: Removing unreachable block (ram,0xfff93d55) */

undefined4 r_sci2_receive_interrupt(undefined4 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b612 < DAT_0001b614) {
    uVar2 = DAT_0008a045;
    *DAT_00020808 = uVar2;
    FUN_fff93db4();
    DAT_00020808 = DAT_00020808 + 1;
    DAT_0001b612 = DAT_0001b612 + 1;
  }
  if (DAT_0001b614 <= DAT_0001b612) {
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 & 0xbf;
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 & 0xef;
    FUN_fff93d97();
    return param_1;
  }
  return param_1;
}


// ===== FUN_fff93d86 @ fff93d86 (17 bytes)

void FUN_fff93d86(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb1900();
  if (iVar1 != 2) {
    FUN_fffb1976();
    return;
  }
  FUN_fffb1d65();
  return;
}


// ===== FUN_fff93d97 @ fff93d97 (28 bytes)

void FUN_fff93d97(void)

{
  int iVar1;
  
  iVar1 = FUN_fffb1900();
  if (iVar1 != 2) {
    FUN_fffb1944();
    return;
  }
  cat_rx_complete(3,DAT_0001b614);
  return;
}


// ===== FUN_fff93db3 @ fff93db3 (1 bytes)

void FUN_fff93db3(void)

{
  return;
}


// ===== FUN_fff93db4 @ fff93db4 (345 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93ddc) */
/* WARNING: Removing unreachable block (ram,0xfff93f0a) */

undefined4 FUN_fff93db4(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_fffb1900();
  if (iVar3 != 2) {
    if ((DAT_0001b612 == 0) || (iVar3 = FUN_fffb23f3(8), iVar3 != 1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      cVar1 = *DAT_00020808;
      DAT_00020808 = DAT_00020808 + -(uint)DAT_0001b612;
      *DAT_00020808 = cVar1;
      DAT_0001b612 = 0;
    }
    if (DAT_0001b612 == 0) {
      cVar1 = *DAT_00020808;
      if (cVar1 == -0x50) {
        DAT_0001b614 = 1;
      }
      else if (cVar1 == -0x5f) {
        DAT_0001b614 = 1;
      }
      else if (cVar1 == -0x5e) {
        DAT_0001b614 = 1;
      }
      else if (cVar1 == -0x5d) {
        DAT_0001b614 = 1;
      }
      else if (cVar1 == -0x58) {
        DAT_0001b614 = 8;
      }
      else if (cVar1 == -0x55) {
        DAT_0001b614 = 0x11;
      }
      else if (cVar1 == -0x54) {
        DAT_0001b614 = 7;
      }
      else if (cVar1 == -0x53) {
        DAT_0001b614 = 10;
      }
      else if (cVar1 == -0x51) {
        DAT_0001b614 = 7;
      }
      else if (cVar1 == -0x60) {
        DAT_0001b614 = 1;
      }
      else {
        DAT_00020808 = DAT_00020808 + -1;
        DAT_0001b612 = 0xffff;
      }
    }
    uVar4 = FUN_fffb237a(8,10);
    return uVar4;
  }
  DAT_00020808 = (char *)FUN_fffb1dad(&DAT_0001b612,&DAT_0001b614,DAT_00020808,6);
  return DAT_00020808;
}


// ===== R_SCI3_Create @ fff93f0d (163 bytes)

/* SCI3 init (USB "Enhanced" CAT via CP2105) */

void R_SCI3_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0xefffffff;
  bVar2 = DAT_00087350;
  DAT_00087350 = bVar2 & 0xf8 | 8;
  bVar2 = DAT_00087351;
  DAT_00087351 = bVar2 & 0xf8 | 8;
  DAT_0008a062 = 0;
  DAT_0008a062 = 0;
  bVar2 = DAT_0008a069;
  DAT_0008a069 = bVar2 & 0xfe;
  DAT_0008a06d = 0;
  DAT_0008a060 = 0;
  DAT_0008a066 = 0x72;
  DAT_0008a067 = 0x50;
  DAT_0008a061 = 0xc2;
  DAT_0008c155 = 10;
  bVar2 = DAT_0008c062;
  DAT_0008c062 = bVar2 | 0x20;
  DAT_0008c153 = 10;
  bVar2 = DAT_0008c022;
  DAT_0008c022 = bVar2 | 8;
  bVar2 = DAT_0008c002;
  DAT_0008c002 = bVar2 | 8;
  FUN_fff940fb();
  return;
}


// ===== FUN_fff93fb0 @ fff93fb0 (64 bytes)

void FUN_fff93fb0(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_00087051;
  DAT_00087051 = bVar1 & 0xfe;
  bVar1 = DAT_00087050;
  DAT_00087050 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 2;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x40;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 1;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x80;
  return;
}


// ===== R_SCI3_Stop @ fff93ff0 (104 bytes)

void R_SCI3_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008c062;
  DAT_0008c062 = bVar1 & 0xf7;
  bVar1 = DAT_0008a062;
  DAT_0008a062 = bVar1 & 0xdf;
  bVar1 = DAT_0008a062;
  DAT_0008a062 = bVar1 & 0xef;
  bVar1 = DAT_0008a062;
  DAT_0008a062 = bVar1 & 0x7f;
  bVar1 = DAT_0008a062;
  DAT_0008a062 = bVar1 & 0xbf;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0xfd;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xffffffbf;
  bVar1 = DAT_00087051;
  DAT_00087051 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0xfe;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xffffff7f;
  bVar1 = DAT_00087050;
  DAT_00087050 = bVar1 & 0xfe;
  return;
}


// ===== R_SCI3_Serial_Receive @ fff94058 (68 bytes)

undefined2 R_SCI3_Serial_Receive(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    DAT_0001b618 = 0;
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 | 0x40;
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 | 0x10;
    DAT_0001b61a = param_2;
    DAT_00020810 = param_1;
  }
  return local_a;
}


// ===== R_SCI3_Serial_Send @ fff9409c (95 bytes)

undefined2 R_SCI3_Serial_Send(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    bVar1 = DAT_0008720a;
    if ((bVar1 & 2) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = DAT_0008720a;
      DAT_0008720a = bVar1 & 0xfd;
      bVar1 = DAT_0008a062;
      DAT_0008a062 = bVar1 | 0xa0;
      bVar1 = DAT_0008c062;
      DAT_0008c062 = bVar1 | 8;
      bVar1 = DAT_0008720a;
      DAT_0008720a = bVar1 | 2;
      DAT_0001b616 = param_2;
      DAT_0002080c = param_1;
    }
  }
  return local_a;
}


// ===== FUN_fff940fb @ fff940fb (1 bytes)

void FUN_fff940fb(void)

{
  return;
}


// ===== r_sci3_transmit_interrupt @ fff940fc (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94132) */
/* WARNING: Removing unreachable block (ram,0xfff940fc) */
/* WARNING: Removing unreachable block (ram,0xfff94144) */

undefined4 r_sci3_transmit_interrupt(undefined4 param_1)

{
  byte bVar1;
  
  if (DAT_0001b616 == 0) {
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 & 0x7f;
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 | 4;
    return param_1;
  }
  DAT_0008a063 = *DAT_0002080c;
  DAT_0002080c = DAT_0002080c + 1;
  DAT_0001b616 = DAT_0001b616 + -1;
  return param_1;
}


// ===== r_sci3_receive_interrupt @ fff9416d (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff941d3) */
/* WARNING: Removing unreachable block (ram,0xfff941db) */
/* WARNING: Removing unreachable block (ram,0xfff941d9) */
/* WARNING: Removing unreachable block (ram,0xfff9416d) */
/* WARNING: Removing unreachable block (ram,0xfff9416f) */
/* WARNING: Removing unreachable block (ram,0xfff941d5) */

undefined4 r_sci3_receive_interrupt(undefined4 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b618 < DAT_0001b61a) {
    uVar2 = DAT_0008a065;
    *DAT_00020810 = uVar2;
    FUN_fff9421b();
    DAT_00020810 = DAT_00020810 + 1;
    DAT_0001b618 = DAT_0001b618 + 1;
  }
  if (DAT_0001b61a <= DAT_0001b618) {
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 & 0xbf;
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 & 0xef;
    FUN_fff9420b();
    return param_1;
  }
  return param_1;
}


// ===== FUN_fff94206 @ fff94206 (5 bytes)

void FUN_fff94206(void)

{
  FUN_fffb1d6f();
  return;
}


// ===== FUN_fff9420b @ fff9420b (15 bytes)

void FUN_fff9420b(void)

{
  cat_rx_complete(1,DAT_0001b61a);
  return;
}


// ===== FUN_fff9421a @ fff9421a (1 bytes)

void FUN_fff9421a(void)

{
  return;
}


// ===== FUN_fff9421b @ fff9421b (33 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94239) */

undefined4 FUN_fff9421b(void)

{
  DAT_00020810 = FUN_fffb1dad(&DAT_0001b618,&DAT_0001b61a,DAT_00020810,4);
  return DAT_00020810;
}


// ===== R_SCI4_Create @ fff9423c (163 bytes)

void R_SCI4_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0xf7ffffff;
  bVar2 = DAT_00087352;
  DAT_00087352 = bVar2 & 0xfa | 10;
  bVar2 = DAT_00087353;
  DAT_00087353 = bVar2 & 0xfa | 10;
  DAT_0008a082 = 0;
  DAT_0008a082 = 0;
  bVar2 = DAT_0008a089;
  DAT_0008a089 = bVar2 & 0xfe;
  DAT_0008a08d = 0;
  DAT_0008a080 = 0;
  DAT_0008a086 = 0x72;
  DAT_0008a087 = 0x50;
  DAT_0008a081 = 0x40;
  DAT_0008c198 = 10;
  bVar2 = DAT_0008c06b;
  DAT_0008c06b = bVar2 | 1;
  DAT_0008c199 = 10;
  bVar2 = DAT_0008c02b;
  DAT_0008c02b = bVar2 | 2;
  bVar2 = DAT_0008c00b;
  DAT_0008c00b = bVar2 | 2;
  FUN_fff9442a();
  return;
}


// ===== FUN_fff942df @ fff942df (64 bytes)

void FUN_fff942df(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_00087053;
  DAT_00087053 = bVar1 & 0xfe;
  bVar1 = DAT_00087052;
  DAT_00087052 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 8;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x100;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 4;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x200;
  return;
}


// ===== R_SCI4_Serial_Receive @ fff94387 (68 bytes)

undefined2 R_SCI4_Serial_Receive(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    DAT_0001b61e = 0;
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 | 0x40;
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 | 0x10;
    DAT_0001b620 = param_2;
    DAT_00020818 = param_1;
  }
  return local_a;
}


// ===== R_SCI4_Serial_Send @ fff943cb (95 bytes)

undefined2 R_SCI4_Serial_Send(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    bVar1 = DAT_0008720a;
    if ((bVar1 & 8) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = DAT_0008720a;
      DAT_0008720a = bVar1 & 0xf7;
      bVar1 = DAT_0008a082;
      DAT_0008a082 = bVar1 | 0xa0;
      bVar1 = DAT_0008c06b;
      DAT_0008c06b = bVar1 | 2;
      bVar1 = DAT_0008720a;
      DAT_0008720a = bVar1 | 8;
      DAT_0001b61c = param_2;
      DAT_00020814 = param_1;
    }
  }
  return local_a;
}


// ===== FUN_fff9442a @ fff9442a (1 bytes)

void FUN_fff9442a(void)

{
  return;
}


// ===== r_sci4_transmit_interrupt @ fff9442b (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94461) */
/* WARNING: Removing unreachable block (ram,0xfff9442b) */
/* WARNING: Removing unreachable block (ram,0xfff94473) */

undefined4 r_sci4_transmit_interrupt(undefined4 param_1)

{
  byte bVar1;
  
  if (DAT_0001b61c == 0) {
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 & 0x7f;
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 | 4;
    return param_1;
  }
  DAT_0008a083 = *DAT_00020814;
  DAT_00020814 = DAT_00020814 + 1;
  DAT_0001b61c = DAT_0001b61c + -1;
  return param_1;
}


// ===== r_sci4_receive_interrupt @ fff9449c (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94502) */
/* WARNING: Removing unreachable block (ram,0xfff9450a) */
/* WARNING: Removing unreachable block (ram,0xfff94508) */
/* WARNING: Removing unreachable block (ram,0xfff9449c) */
/* WARNING: Removing unreachable block (ram,0xfff9449e) */
/* WARNING: Removing unreachable block (ram,0xfff94504) */

undefined4 r_sci4_receive_interrupt(undefined4 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b61e < DAT_0001b620) {
    uVar2 = DAT_0008a085;
    *DAT_00020818 = uVar2;
    FUN_fff94548();
    DAT_00020818 = DAT_00020818 + 1;
    DAT_0001b61e = DAT_0001b61e + 1;
  }
  if (DAT_0001b620 <= DAT_0001b61e) {
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 & 0xbf;
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 & 0xef;
    FUN_fff94536();
    return param_1;
  }
  return param_1;
}


// ===== FUN_fff94535 @ fff94535 (1 bytes)

void FUN_fff94535(void)

{
  return;
}

