// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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

ushort R_SCI2_Serial_Receive(uint param_1,short param_2)

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

ushort R_SCI2_Serial_Send(uint param_1,short param_2)

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


// ===== R_SCI2_Create_UserInit @ fff93c7b (1 bytes)

/* empty */

void R_SCI2_Create_UserInit(void)

{
  return;
}


// ===== r_sci2_transmit_interrupt @ fff93c7c (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93cb2) */
/* WARNING: Removing unreachable block (ram,0xfff93c7c) */
/* WARNING: Removing unreachable block (ram,0xfff93cc4) */

void r_sci2_transmit_interrupt(void)

{
  byte bVar1;
  
  if (DAT_0001b610 == 0) {
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 & 0x7f;
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 | 4;
    return;
  }
  DAT_0008a043 = *DAT_00020804;
  DAT_00020804 = DAT_00020804 + 1;
  DAT_0001b610 = DAT_0001b610 + -1;
  return;
}


// ===== r_sci2_transmitend_interrupt @ fff93cc8 (37 bytes)

/* TEI2 (cb 0x18) */

void r_sci2_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c061;
  DAT_0008c061 = bVar1 & 0xf7;
  bVar1 = DAT_0008a042;
  DAT_0008a042 = bVar1 & 0x7f;
  bVar1 = DAT_0008a042;
  DAT_0008a042 = bVar1 & 0xdf;
  bVar1 = DAT_0008a042;
  DAT_0008a042 = bVar1 & 0xfb;
  r_sci2_callback_transmitend();
  return;
}


// ===== r_sci2_receive_interrupt @ fff93ced (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93d53) */
/* WARNING: Removing unreachable block (ram,0xfff93d5b) */
/* WARNING: Removing unreachable block (ram,0xfff93d59) */
/* WARNING: Removing unreachable block (ram,0xfff93ced) */
/* WARNING: Removing unreachable block (ram,0xfff93cef) */
/* WARNING: Removing unreachable block (ram,0xfff93d55) */

void r_sci2_receive_interrupt(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b612 < DAT_0001b614) {
    uVar2 = DAT_0008a045;
    *DAT_00020808 = uVar2;
    sci2_rx_byte_hook();
    DAT_00020808 = DAT_00020808 + 1;
    DAT_0001b612 = DAT_0001b612 + 1;
  }
  if (DAT_0001b614 <= DAT_0001b612) {
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 & 0xbf;
    bVar1 = DAT_0008a042;
    DAT_0008a042 = bVar1 & 0xef;
    r_sci2_callback_receiveend();
    return;
  }
  return;
}


// ===== r_sci2_receiveerror_interrupt @ fff93d5f (39 bytes)

/* ERI2 (cb 0x19) */

void r_sci2_receiveerror_interrupt(void)

{
  byte bVar1;
  
  r_sci2_callback_receiveerror();
  bVar1 = DAT_0008a044;
  DAT_0008a044 = bVar1 & 199 | 0xc0;
  return;
}


// ===== r_sci2_callback_transmitend @ fff93d86 (17 bytes)

/* CAT mode: 0x11FE9=0, else tuner */

void r_sci2_callback_transmitend(void)

{
  byte bVar1;
  
  bVar1 = tunlin_port_mode();
  if (bVar1 != 2) {
    FUN_fffb1976();
    return;
  }
  cat_tx_done_sci2();
  return;
}


// ===== r_sci2_callback_receiveend @ fff93d97 (28 bytes)

/* CAT mode: cat_rx_complete(3,len), else tuner flag 0xA0A9 */

void r_sci2_callback_receiveend(void)

{
  byte bVar1;
  
  bVar1 = tunlin_port_mode();
  if (bVar1 != 2) {
    FUN_fffb1944();
    return;
  }
  cat_rx_complete(3,DAT_0001b614);
  return;
}


// ===== r_sci2_callback_receiveerror @ fff93db3 (1 bytes)

/* empty */

void r_sci2_callback_receiveerror(void)

{
  return;
}


// ===== sci2_rx_byte_hook @ fff93db4 (345 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93ddc) */
/* WARNING: Removing unreachable block (ram,0xfff93f0a) */
/* CAT framing or tuner framing (first byte 0xA0..0xAF), by sci2_port_mode */

void sci2_rx_byte_hook(void)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  
  bVar3 = tunlin_port_mode();
  if (bVar3 != 2) {
    if ((DAT_0001b612 == 0) || (bVar3 = swtimer_expired(8), bVar3 != 1)) {
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
    swtimer_start(8,10);
    return;
  }
  DAT_00020808 = (char *)cat_rx_byte_hook(&DAT_0001b612,&DAT_0001b614,DAT_00020808,6);
  return;
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
  R_SCI3_Create_UserInit();
  return;
}


// ===== R_SCI3_Start @ fff93fb0 (64 bytes)

void R_SCI3_Start(void)

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

ushort R_SCI3_Serial_Receive(uint param_1,short param_2)

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

ushort R_SCI3_Serial_Send(uint param_1,short param_2)

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


// ===== R_SCI3_Create_UserInit @ fff940fb (1 bytes)

/* empty */

void R_SCI3_Create_UserInit(void)

{
  return;
}


// ===== r_sci3_transmit_interrupt @ fff940fc (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94132) */
/* WARNING: Removing unreachable block (ram,0xfff940fc) */
/* WARNING: Removing unreachable block (ram,0xfff94144) */

void r_sci3_transmit_interrupt(void)

{
  byte bVar1;
  
  if (DAT_0001b616 == 0) {
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 & 0x7f;
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 | 4;
    return;
  }
  DAT_0008a063 = *DAT_0002080c;
  DAT_0002080c = DAT_0002080c + 1;
  DAT_0001b616 = DAT_0001b616 + -1;
  return;
}


// ===== r_sci3_transmitend_interrupt @ fff94148 (37 bytes)

/* TEI3 (cb 0x1A) */

void r_sci3_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c062;
  DAT_0008c062 = bVar1 & 0xf7;
  bVar1 = DAT_0008a062;
  DAT_0008a062 = bVar1 & 0x7f;
  bVar1 = DAT_0008a062;
  DAT_0008a062 = bVar1 & 0xdf;
  bVar1 = DAT_0008a062;
  DAT_0008a062 = bVar1 & 0xfb;
  r_sci3_callback_transmitend();
  return;
}


// ===== r_sci3_receive_interrupt @ fff9416d (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff941d3) */
/* WARNING: Removing unreachable block (ram,0xfff941db) */
/* WARNING: Removing unreachable block (ram,0xfff941d9) */
/* WARNING: Removing unreachable block (ram,0xfff9416d) */
/* WARNING: Removing unreachable block (ram,0xfff9416f) */
/* WARNING: Removing unreachable block (ram,0xfff941d5) */

void r_sci3_receive_interrupt(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b618 < DAT_0001b61a) {
    uVar2 = DAT_0008a065;
    *DAT_00020810 = uVar2;
    sci3_rx_byte_hook();
    DAT_00020810 = DAT_00020810 + 1;
    DAT_0001b618 = DAT_0001b618 + 1;
  }
  if (DAT_0001b61a <= DAT_0001b618) {
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 & 0xbf;
    bVar1 = DAT_0008a062;
    DAT_0008a062 = bVar1 & 0xef;
    r_sci3_callback_receiveend();
    return;
  }
  return;
}


// ===== r_sci3_receiveerror_interrupt @ fff941df (39 bytes)

/* ERI3 (cb 0x1B) */

void r_sci3_receiveerror_interrupt(void)

{
  byte bVar1;
  
  r_sci3_callback_receiveerror();
  bVar1 = DAT_0008a064;
  DAT_0008a064 = bVar1 & 199 | 0xc0;
  return;
}


// ===== r_sci3_callback_transmitend @ fff94206 (5 bytes)

/* -> cat_tx_done_sci3 */

void r_sci3_callback_transmitend(void)

{
  cat_tx_done_sci3();
  return;
}


// ===== r_sci3_callback_receiveend @ fff9420b (15 bytes)

/* cat_rx_complete(1,len) */

void r_sci3_callback_receiveend(void)

{
  cat_rx_complete(1,DAT_0001b61a);
  return;
}


// ===== r_sci3_callback_receiveerror @ fff9421a (1 bytes)

/* empty */

void r_sci3_callback_receiveerror(void)

{
  return;
}


// ===== sci3_rx_byte_hook @ fff9421b (33 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94239) */
/* cat_rx_byte_hook(...,timer 4) */

void sci3_rx_byte_hook(void)

{
  DAT_00020810 = (char *)cat_rx_byte_hook(&DAT_0001b618,&DAT_0001b61a,DAT_00020810,4);
  return;
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
  R_SCI4_Create_UserInit();
  return;
}


// ===== R_SCI4_Start @ fff942df (64 bytes)

void R_SCI4_Start(void)

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


// ===== FUN_fff9431f @ fff9431f (104 bytes)

void FUN_fff9431f(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008c06b;
  DAT_0008c06b = bVar1 & 0xfd;
  bVar1 = DAT_0008a082;
  DAT_0008a082 = bVar1 & 0xdf;
  bVar1 = DAT_0008a082;
  DAT_0008a082 = bVar1 & 0xef;
  bVar1 = DAT_0008a082;
  DAT_0008a082 = bVar1 & 0x7f;
  bVar1 = DAT_0008a082;
  DAT_0008a082 = bVar1 & 0xbf;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0xf7;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffeff;
  bVar1 = DAT_00087053;
  DAT_00087053 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0xfb;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffdff;
  bVar1 = DAT_00087052;
  DAT_00087052 = bVar1 & 0xfe;
  return;
}


// ===== R_SCI4_Serial_Receive @ fff94387 (68 bytes)

ushort R_SCI4_Serial_Receive(uint param_1,short param_2)

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

ushort R_SCI4_Serial_Send(uint param_1,short param_2)

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


// ===== R_SCI4_Create_UserInit @ fff9442a (1 bytes)

/* empty */

void R_SCI4_Create_UserInit(void)

{
  return;
}


// ===== r_sci4_transmit_interrupt @ fff9442b (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94461) */
/* WARNING: Removing unreachable block (ram,0xfff9442b) */
/* WARNING: Removing unreachable block (ram,0xfff94473) */

void r_sci4_transmit_interrupt(void)

{
  byte bVar1;
  
  if (DAT_0001b61c == 0) {
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 & 0x7f;
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 | 4;
    return;
  }
  DAT_0008a083 = *DAT_00020814;
  DAT_00020814 = DAT_00020814 + 1;
  DAT_0001b61c = DAT_0001b61c + -1;
  return;
}


// ===== r_sci4_transmitend_interrupt @ fff94477 (37 bytes)

/* TEI4 (cb 0x1C) */

void r_sci4_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c06b;
  DAT_0008c06b = bVar1 & 0xfd;
  bVar1 = DAT_0008a082;
  DAT_0008a082 = bVar1 & 0x7f;
  bVar1 = DAT_0008a082;
  DAT_0008a082 = bVar1 & 0xdf;
  bVar1 = DAT_0008a082;
  DAT_0008a082 = bVar1 & 0xfb;
  r_sci4_callback_transmitend();
  return;
}


// ===== r_sci4_receive_interrupt @ fff9449c (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94502) */
/* WARNING: Removing unreachable block (ram,0xfff9450a) */
/* WARNING: Removing unreachable block (ram,0xfff94508) */
/* WARNING: Removing unreachable block (ram,0xfff9449c) */
/* WARNING: Removing unreachable block (ram,0xfff9449e) */
/* WARNING: Removing unreachable block (ram,0xfff94504) */

void r_sci4_receive_interrupt(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b61e < DAT_0001b620) {
    uVar2 = DAT_0008a085;
    *DAT_00020818 = uVar2;
    sci4_rx_frame_len();
    DAT_00020818 = DAT_00020818 + 1;
    DAT_0001b61e = DAT_0001b61e + 1;
  }
  if (DAT_0001b620 <= DAT_0001b61e) {
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 & 0xbf;
    bVar1 = DAT_0008a082;
    DAT_0008a082 = bVar1 & 0xef;
    sci4_rx_frame_done();
    return;
  }
  return;
}


// ===== r_sci4_receiveerror_interrupt @ fff9450e (39 bytes)

/* ERI4 (cb 0x1D) */

void r_sci4_receiveerror_interrupt(void)

{
  byte bVar1;
  
  r_sci4_callback_receiveerror();
  bVar1 = DAT_0008a084;
  DAT_0008a084 = bVar1 & 199 | 0xc0;
  return;
}


// ===== r_sci4_callback_transmitend @ fff94535 (1 bytes)

/* empty */

void r_sci4_callback_transmitend(void)

{
  return;
}


// ===== sci4_rx_frame_done @ fff94536 (17 bytes)

/* SCI4 receive end: 0xA2AB=1 and length -> 0x1B78A */

void sci4_rx_frame_done(void)

{
  sci4_rx_set_ready();
  sci4_rx_set_len(DAT_0001b620);
  return;
}


// ===== r_sci4_callback_receiveerror @ fff94547 (1 bytes)

/* empty */

void r_sci4_callback_receiveerror(void)

{
  return;
}


// ===== sci4_rx_frame_len @ fff94548 (282 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94637) */
/* SCI4 per-byte callback: sets expected length from first byte (06/? ->1, r ->7, 5A xx -> MCUBoot
   packet length); drops other lead bytes */

void sci4_rx_frame_len(void)

{
  uint uVar1;
  
  if (DAT_0001b61e == 0) {
    DAT_00001434 = *DAT_00020818;
    if ((DAT_00001434 == 6) || (DAT_00001434 == 0x3f)) {
      DAT_0001b620 = 1;
      return;
    }
    if (DAT_00001434 != 0x5a) {
      if (DAT_00001434 == 0x72) {
        DAT_0001b620 = 7;
        return;
      }
      DAT_00020818 = DAT_00020818 + -1;
      DAT_0001b61e = 0xffff;
      return;
    }
    DAT_00001434 = 'Z';
  }
  else if (DAT_00001434 == 'Z') {
    if (DAT_0001b61e == 1) {
      DAT_00001435 = *DAT_00020818;
      uVar1 = (uint)DAT_00001435;
      if (uVar1 == 0xa7) {
        DAT_0001b620 = 10;
        return;
      }
      if ((uVar1 == 0xa6) || (uVar1 - 0xa1 < 3)) {
        DAT_0001b620 = 2;
        return;
      }
    }
    else if ((DAT_0001b61e == 3) && (DAT_00001435 != 0xa7)) {
      DAT_0001b620 = CONCAT11(*DAT_00020818,DAT_00020818[-1]) + 6;
      return;
    }
  }
  return;
}


// ===== R_SCI5_Create @ fff94662 (163 bytes)

/* SCI5 init (SDR module FPGA link) */

void R_SCI5_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0xfbffffff;
  bVar2 = DAT_00087354;
  DAT_00087354 = bVar2 & 0xfa | 10;
  bVar2 = DAT_00087355;
  DAT_00087355 = bVar2 & 0xfa | 10;
  DAT_0008a0a2 = 0;
  DAT_0008a0a2 = 0;
  bVar2 = DAT_0008a0a9;
  DAT_0008a0a9 = bVar2 & 0xfe;
  DAT_0008a0ad = 0;
  DAT_0008a0a0 = 0;
  DAT_0008a0a6 = 0x72;
  DAT_0008a0a7 = 0x50;
  DAT_0008a0a1 = 0x40;
  DAT_0008c1a2 = 10;
  bVar2 = DAT_0008c06c;
  DAT_0008c06c = bVar2 | 4;
  DAT_0008c1a3 = 10;
  bVar2 = DAT_0008c02c;
  DAT_0008c02c = bVar2 | 8;
  bVar2 = DAT_0008c00c;
  DAT_0008c00c = bVar2 | 8;
  R_SCI5_Create_UserInit();
  return;
}


// ===== R_SCI5_Start @ fff94705 (64 bytes)

/* SCI5 start: clears IR/sets IEN for RXI5/TXI5 and group TEI/ERI bits (Code Generator style) */

void R_SCI5_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_00087055;
  DAT_00087055 = bVar1 & 0xfe;
  bVar1 = DAT_00087054;
  DAT_00087054 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 0x20;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x400;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 0x10;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x800;
  return;
}


// ===== R_SCI5_Stop @ fff94745 (104 bytes)

void R_SCI5_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008c06c;
  DAT_0008c06c = bVar1 & 0xf7;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xdf;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xef;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0x7f;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xbf;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0xdf;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffbff;
  bVar1 = DAT_00087055;
  DAT_00087055 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0xef;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffff7ff;
  bVar1 = DAT_00087054;
  DAT_00087054 = bVar1 & 0xfe;
  return;
}


// ===== R_SCI5_Serial_Receive @ fff947ad (68 bytes)

ushort R_SCI5_Serial_Receive(uint param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    DAT_0001b624 = 0;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 | 0x40;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 | 0x10;
    DAT_0001b626 = param_2;
    DAT_00020820 = param_1;
  }
  return local_a;
}


// ===== R_SCI5_Serial_Send @ fff947f1 (95 bytes)

ushort R_SCI5_Serial_Send(uint param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    bVar1 = DAT_0008720a;
    if ((bVar1 & 0x20) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = DAT_0008720a;
      DAT_0008720a = bVar1 & 0xdf;
      bVar1 = DAT_0008a0a2;
      DAT_0008a0a2 = bVar1 | 0xa0;
      bVar1 = DAT_0008c06c;
      DAT_0008c06c = bVar1 | 8;
      bVar1 = DAT_0008720a;
      DAT_0008720a = bVar1 | 0x20;
      DAT_0001b622 = param_2;
      DAT_0002081c = param_1;
    }
  }
  return local_a;
}


// ===== R_SCI5_Create_UserInit @ fff94850 (1 bytes)

/* empty */

void R_SCI5_Create_UserInit(void)

{
  return;
}


// ===== r_sci5_transmit_interrupt @ fff94851 (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94887) */
/* WARNING: Removing unreachable block (ram,0xfff94851) */
/* WARNING: Removing unreachable block (ram,0xfff94899) */

void r_sci5_transmit_interrupt(void)

{
  byte bVar1;
  
  if (DAT_0001b622 == 0) {
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0x7f;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 | 4;
    return;
  }
  DAT_0008a0a3 = *DAT_0002081c;
  DAT_0002081c = DAT_0002081c + 1;
  DAT_0001b622 = DAT_0001b622 + -1;
  return;
}


// ===== r_sci5_transmitend_interrupt @ fff9489d (37 bytes)

/* TEI5 (cb 0x1E) */

void r_sci5_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c06c;
  DAT_0008c06c = bVar1 & 0xf7;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0x7f;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xdf;
  bVar1 = DAT_0008a0a2;
  DAT_0008a0a2 = bVar1 & 0xfb;
  r_sci5_callback_transmitend();
  return;
}


// ===== r_sci5_receive_interrupt @ fff948c2 (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94928) */
/* WARNING: Removing unreachable block (ram,0xfff94930) */
/* WARNING: Removing unreachable block (ram,0xfff9492e) */
/* WARNING: Removing unreachable block (ram,0xfff948c2) */
/* WARNING: Removing unreachable block (ram,0xfff948c4) */
/* WARNING: Removing unreachable block (ram,0xfff9492a) */

void r_sci5_receive_interrupt(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b624 < DAT_0001b626) {
    uVar2 = DAT_0008a0a5;
    *DAT_00020820 = uVar2;
    sci5_rx_byte_hook();
    DAT_00020820 = DAT_00020820 + 1;
    DAT_0001b624 = DAT_0001b624 + 1;
  }
  if (DAT_0001b626 <= DAT_0001b624) {
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0xbf;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0xef;
    r_sci5_callback_receiveend();
    return;
  }
  return;
}


// ===== r_sci5_receiveerror_interrupt @ fff94934 (39 bytes)

/* ERI5 (cb 0x1F) */

void r_sci5_receiveerror_interrupt(void)

{
  byte bVar1;
  
  r_sci5_callback_receiveerror();
  bVar1 = DAT_0008a0a4;
  DAT_0008a0a4 = bVar1 & 199 | 0xc0;
  return;
}

