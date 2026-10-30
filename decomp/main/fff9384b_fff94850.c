// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== r_sci1_callback_receiveerror @ fff9384b (1 bytes)

/* empty */

void r_sci1_callback_receiveerror(void)

{
  return;
}


// ===== displink_rx_frame_len @ fff9384c (570 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93a53) */
/* SCI1 rx byte hook: expected frame length by first byte (06/15=1, Z=len16+4, C3..C5, E0..E8, F0,
   F1, FD, FE, 'e'), resync on 10-unit gap (timer 1) */

void displink_rx_frame_len(void)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  
  if ((DAT_0001b60c == 0) || (bVar3 = swtimer_expired(1), bVar3 != 1)) {
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
  swtimer_start(1,10);
  return;
}


// ===== R_SCI2_Create @ fff93a86 (163 bytes)

/* SCI2 init (external tuner / ETUN port) */

void R_SCI2_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = uVar1 & 0xdfffffff;
  bVar2 = ICU_IPR062;
  ICU_IPR062 = bVar2 & 0xf8 | 8;
  bVar2 = ICU_IPR063;
  ICU_IPR063 = bVar2 & 0xf8 | 8;
  SCI2_SCR = 0;
  SCI2_SCR = 0;
  bVar2 = SCI2_SIMR1;
  SCI2_SIMR1 = bVar2 & 0xfe;
  SCI2_SPMR = 0;
  SCI2_SMR = 1;
  SCI2_SCMR = 0x72;
  SCI2_SEMR = 0x10;
  SCI2_BRR = 0xc2;
  MPC_P12PFS = 10;
  bVar2 = PORT1_PMR;
  PORT1_PMR = bVar2 | 4;
  MPC_P13PFS = 10;
  bVar2 = PORT1_PODR;
  PORT1_PODR = bVar2 | 8;
  bVar2 = PORT1_PDR;
  PORT1_PDR = bVar2 | 8;
  R_SCI2_Create_UserInit();
  return;
}


// ===== R_SCI2_Start @ fff93b29 (64 bytes)

void R_SCI2_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR063;
  ICU_IR063 = bVar1 & 0xfe;
  bVar1 = ICU_IR062;
  ICU_IR062 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 | 0x80;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x10;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 | 0x40;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x20;
  return;
}


// ===== R_SCI2_Stop @ fff93b69 (104 bytes)

void R_SCI2_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = PORT1_PMR;
  PORT1_PMR = bVar1 & 0xf7;
  bVar1 = SCI2_SCR;
  SCI2_SCR = bVar1 & 0xdf;
  bVar1 = SCI2_SCR;
  SCI2_SCR = bVar1 & 0xef;
  bVar1 = SCI2_SCR;
  SCI2_SCR = bVar1 & 0x7f;
  bVar1 = SCI2_SCR;
  SCI2_SCR = bVar1 & 0xbf;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 & 0x7f;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xffffffef;
  bVar1 = ICU_IR063;
  ICU_IR063 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 & 0xbf;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xffffffdf;
  bVar1 = ICU_IR062;
  ICU_IR062 = bVar1 & 0xfe;
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
    bVar1 = SCI2_SCR;
    SCI2_SCR = bVar1 | 0x40;
    bVar1 = SCI2_SCR;
    SCI2_SCR = bVar1 | 0x10;
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
    cVar1 = ICU_IER07;
    if (cVar1 < '\0') {
      bVar2 = ICU_IER07;
      ICU_IER07 = bVar2 & 0x7f;
      bVar2 = SCI2_SCR;
      SCI2_SCR = bVar2 | 0xa0;
      bVar2 = PORT1_PMR;
      PORT1_PMR = bVar2 | 8;
      bVar2 = ICU_IER07;
      ICU_IER07 = bVar2 | 0x80;
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
    bVar1 = SCI2_SCR;
    SCI2_SCR = bVar1 & 0x7f;
    bVar1 = SCI2_SCR;
    SCI2_SCR = bVar1 | 4;
    return;
  }
  SCI2_TDR = *DAT_00020804;
  DAT_00020804 = DAT_00020804 + 1;
  DAT_0001b610 = DAT_0001b610 + -1;
  return;
}


// ===== r_sci2_transmitend_interrupt @ fff93cc8 (37 bytes)

/* TEI2 (cb 0x18) */

void r_sci2_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = PORT1_PMR;
  PORT1_PMR = bVar1 & 0xf7;
  bVar1 = SCI2_SCR;
  SCI2_SCR = bVar1 & 0x7f;
  bVar1 = SCI2_SCR;
  SCI2_SCR = bVar1 & 0xdf;
  bVar1 = SCI2_SCR;
  SCI2_SCR = bVar1 & 0xfb;
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
    uVar2 = SCI2_RDR;
    *DAT_00020808 = uVar2;
    sci2_rx_byte_hook();
    DAT_00020808 = DAT_00020808 + 1;
    DAT_0001b612 = DAT_0001b612 + 1;
  }
  if (DAT_0001b614 <= DAT_0001b612) {
    bVar1 = SCI2_SCR;
    SCI2_SCR = bVar1 & 0xbf;
    bVar1 = SCI2_SCR;
    SCI2_SCR = bVar1 & 0xef;
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
  bVar1 = SCI2_SSR;
  SCI2_SSR = bVar1 & 199 | 0xc0;
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
  
  uVar1 = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = uVar1 & 0xefffffff;
  bVar2 = ICU_IPR080;
  ICU_IPR080 = bVar2 & 0xf8 | 8;
  bVar2 = ICU_IPR081;
  ICU_IPR081 = bVar2 & 0xf8 | 8;
  SCI3_SCR = 0;
  SCI3_SCR = 0;
  bVar2 = SCI3_SIMR1;
  SCI3_SIMR1 = bVar2 & 0xfe;
  SCI3_SPMR = 0;
  SCI3_SMR = 0;
  SCI3_SCMR = 0x72;
  SCI3_SEMR = 0x50;
  SCI3_BRR = 0xc2;
  MPC_P25PFS = 10;
  bVar2 = PORT2_PMR;
  PORT2_PMR = bVar2 | 0x20;
  MPC_P23PFS = 10;
  bVar2 = PORT2_PODR;
  PORT2_PODR = bVar2 | 8;
  bVar2 = PORT2_PDR;
  PORT2_PDR = bVar2 | 8;
  R_SCI3_Create_UserInit();
  return;
}


// ===== R_SCI3_Start @ fff93fb0 (64 bytes)

void R_SCI3_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR081;
  ICU_IR081 = bVar1 & 0xfe;
  bVar1 = ICU_IR080;
  ICU_IR080 = bVar1 & 0xfe;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 | 2;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x40;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 | 1;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x80;
  return;
}


// ===== R_SCI3_Stop @ fff93ff0 (104 bytes)

void R_SCI3_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = PORT2_PMR;
  PORT2_PMR = bVar1 & 0xf7;
  bVar1 = SCI3_SCR;
  SCI3_SCR = bVar1 & 0xdf;
  bVar1 = SCI3_SCR;
  SCI3_SCR = bVar1 & 0xef;
  bVar1 = SCI3_SCR;
  SCI3_SCR = bVar1 & 0x7f;
  bVar1 = SCI3_SCR;
  SCI3_SCR = bVar1 & 0xbf;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 & 0xfd;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xffffffbf;
  bVar1 = ICU_IR081;
  ICU_IR081 = bVar1 & 0xfe;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 & 0xfe;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xffffff7f;
  bVar1 = ICU_IR080;
  ICU_IR080 = bVar1 & 0xfe;
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
    bVar1 = SCI3_SCR;
    SCI3_SCR = bVar1 | 0x40;
    bVar1 = SCI3_SCR;
    SCI3_SCR = bVar1 | 0x10;
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
    bVar1 = ICU_IER0A;
    if ((bVar1 & 2) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = ICU_IER0A;
      ICU_IER0A = bVar1 & 0xfd;
      bVar1 = SCI3_SCR;
      SCI3_SCR = bVar1 | 0xa0;
      bVar1 = PORT2_PMR;
      PORT2_PMR = bVar1 | 8;
      bVar1 = ICU_IER0A;
      ICU_IER0A = bVar1 | 2;
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
    bVar1 = SCI3_SCR;
    SCI3_SCR = bVar1 & 0x7f;
    bVar1 = SCI3_SCR;
    SCI3_SCR = bVar1 | 4;
    return;
  }
  SCI3_TDR = *DAT_0002080c;
  DAT_0002080c = DAT_0002080c + 1;
  DAT_0001b616 = DAT_0001b616 + -1;
  return;
}


// ===== r_sci3_transmitend_interrupt @ fff94148 (37 bytes)

/* TEI3 (cb 0x1A) */

void r_sci3_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = PORT2_PMR;
  PORT2_PMR = bVar1 & 0xf7;
  bVar1 = SCI3_SCR;
  SCI3_SCR = bVar1 & 0x7f;
  bVar1 = SCI3_SCR;
  SCI3_SCR = bVar1 & 0xdf;
  bVar1 = SCI3_SCR;
  SCI3_SCR = bVar1 & 0xfb;
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
    uVar2 = SCI3_RDR;
    *DAT_00020810 = uVar2;
    sci3_rx_byte_hook();
    DAT_00020810 = DAT_00020810 + 1;
    DAT_0001b618 = DAT_0001b618 + 1;
  }
  if (DAT_0001b61a <= DAT_0001b618) {
    bVar1 = SCI3_SCR;
    SCI3_SCR = bVar1 & 0xbf;
    bVar1 = SCI3_SCR;
    SCI3_SCR = bVar1 & 0xef;
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
  bVar1 = SCI3_SSR;
  SCI3_SSR = bVar1 & 199 | 0xc0;
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
  
  uVar1 = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = uVar1 & 0xf7ffffff;
  bVar2 = ICU_IPR082;
  ICU_IPR082 = bVar2 & 0xfa | 10;
  bVar2 = ICU_IPR083;
  ICU_IPR083 = bVar2 & 0xfa | 10;
  SCI4_SCR = 0;
  SCI4_SCR = 0;
  bVar2 = SCI4_SIMR1;
  SCI4_SIMR1 = bVar2 & 0xfe;
  SCI4_SPMR = 0;
  SCI4_SMR = 0;
  SCI4_SCMR = 0x72;
  SCI4_SEMR = 0x50;
  SCI4_BRR = 0x40;
  MPC_PB0PFS = 10;
  bVar2 = PORTB_PMR;
  PORTB_PMR = bVar2 | 1;
  MPC_PB1PFS = 10;
  bVar2 = PORTB_PODR;
  PORTB_PODR = bVar2 | 2;
  bVar2 = PORTB_PDR;
  PORTB_PDR = bVar2 | 2;
  R_SCI4_Create_UserInit();
  return;
}


// ===== R_SCI4_Start @ fff942df (64 bytes)

void R_SCI4_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR083;
  ICU_IR083 = bVar1 & 0xfe;
  bVar1 = ICU_IR082;
  ICU_IR082 = bVar1 & 0xfe;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 | 8;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x100;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 | 4;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x200;
  return;
}


// ===== R_SCI4_Stop @ fff9431f (104 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.950): SCI4
   (0x8A082) and its IER/IR bits; 104 B like the other R_SCIn_Stop, after R_SCI4_Start [inference]
    */

void R_SCI4_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = PORTB_PMR;
  PORTB_PMR = bVar1 & 0xfd;
  bVar1 = SCI4_SCR;
  SCI4_SCR = bVar1 & 0xdf;
  bVar1 = SCI4_SCR;
  SCI4_SCR = bVar1 & 0xef;
  bVar1 = SCI4_SCR;
  SCI4_SCR = bVar1 & 0x7f;
  bVar1 = SCI4_SCR;
  SCI4_SCR = bVar1 & 0xbf;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 & 0xf7;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffeff;
  bVar1 = ICU_IR083;
  ICU_IR083 = bVar1 & 0xfe;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 & 0xfb;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffdff;
  bVar1 = ICU_IR082;
  ICU_IR082 = bVar1 & 0xfe;
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
    bVar1 = SCI4_SCR;
    SCI4_SCR = bVar1 | 0x40;
    bVar1 = SCI4_SCR;
    SCI4_SCR = bVar1 | 0x10;
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
    bVar1 = ICU_IER0A;
    if ((bVar1 & 8) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = ICU_IER0A;
      ICU_IER0A = bVar1 & 0xf7;
      bVar1 = SCI4_SCR;
      SCI4_SCR = bVar1 | 0xa0;
      bVar1 = PORTB_PMR;
      PORTB_PMR = bVar1 | 2;
      bVar1 = ICU_IER0A;
      ICU_IER0A = bVar1 | 8;
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
    bVar1 = SCI4_SCR;
    SCI4_SCR = bVar1 & 0x7f;
    bVar1 = SCI4_SCR;
    SCI4_SCR = bVar1 | 4;
    return;
  }
  SCI4_TDR = *DAT_00020814;
  DAT_00020814 = DAT_00020814 + 1;
  DAT_0001b61c = DAT_0001b61c + -1;
  return;
}


// ===== r_sci4_transmitend_interrupt @ fff94477 (37 bytes)

/* TEI4 (cb 0x1C) */

void r_sci4_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = PORTB_PMR;
  PORTB_PMR = bVar1 & 0xfd;
  bVar1 = SCI4_SCR;
  SCI4_SCR = bVar1 & 0x7f;
  bVar1 = SCI4_SCR;
  SCI4_SCR = bVar1 & 0xdf;
  bVar1 = SCI4_SCR;
  SCI4_SCR = bVar1 & 0xfb;
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
    uVar2 = SCI4_RDR;
    *DAT_00020818 = uVar2;
    sci4_rx_frame_len();
    DAT_00020818 = DAT_00020818 + 1;
    DAT_0001b61e = DAT_0001b61e + 1;
  }
  if (DAT_0001b620 <= DAT_0001b61e) {
    bVar1 = SCI4_SCR;
    SCI4_SCR = bVar1 & 0xbf;
    bVar1 = SCI4_SCR;
    SCI4_SCR = bVar1 & 0xef;
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
  bVar1 = SCI4_SSR;
  SCI4_SSR = bVar1 & 199 | 0xc0;
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
  
  uVar1 = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = uVar1 & 0xfbffffff;
  bVar2 = ICU_IPR084;
  ICU_IPR084 = bVar2 & 0xfa | 10;
  bVar2 = ICU_IPR085;
  ICU_IPR085 = bVar2 & 0xfa | 10;
  SCI5_SCR = 0;
  SCI5_SCR = 0;
  bVar2 = SCI5_SIMR1;
  SCI5_SIMR1 = bVar2 & 0xfe;
  SCI5_SPMR = 0;
  SCI5_SMR = 0;
  SCI5_SCMR = 0x72;
  SCI5_SEMR = 0x50;
  SCI5_BRR = 0x40;
  MPC_PC2PFS = 10;
  bVar2 = PORTC_PMR;
  PORTC_PMR = bVar2 | 4;
  MPC_PC3PFS = 10;
  bVar2 = PORTC_PODR;
  PORTC_PODR = bVar2 | 8;
  bVar2 = PORTC_PDR;
  PORTC_PDR = bVar2 | 8;
  R_SCI5_Create_UserInit();
  return;
}


// ===== R_SCI5_Start @ fff94705 (64 bytes)

/* SCI5 start: clears IR/sets IEN for RXI5/TXI5 and group TEI/ERI bits (Code Generator style) */

void R_SCI5_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR085;
  ICU_IR085 = bVar1 & 0xfe;
  bVar1 = ICU_IR084;
  ICU_IR084 = bVar1 & 0xfe;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 | 0x20;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x400;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 | 0x10;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x800;
  return;
}


// ===== R_SCI5_Stop @ fff94745 (104 bytes)

void R_SCI5_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = PORTC_PMR;
  PORTC_PMR = bVar1 & 0xf7;
  bVar1 = SCI5_SCR;
  SCI5_SCR = bVar1 & 0xdf;
  bVar1 = SCI5_SCR;
  SCI5_SCR = bVar1 & 0xef;
  bVar1 = SCI5_SCR;
  SCI5_SCR = bVar1 & 0x7f;
  bVar1 = SCI5_SCR;
  SCI5_SCR = bVar1 & 0xbf;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 & 0xdf;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffbff;
  bVar1 = ICU_IR085;
  ICU_IR085 = bVar1 & 0xfe;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 & 0xef;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffff7ff;
  bVar1 = ICU_IR084;
  ICU_IR084 = bVar1 & 0xfe;
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
    bVar1 = SCI5_SCR;
    SCI5_SCR = bVar1 | 0x40;
    bVar1 = SCI5_SCR;
    SCI5_SCR = bVar1 | 0x10;
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
    bVar1 = ICU_IER0A;
    if ((bVar1 & 0x20) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = ICU_IER0A;
      ICU_IER0A = bVar1 & 0xdf;
      bVar1 = SCI5_SCR;
      SCI5_SCR = bVar1 | 0xa0;
      bVar1 = PORTC_PMR;
      PORTC_PMR = bVar1 | 8;
      bVar1 = ICU_IER0A;
      ICU_IER0A = bVar1 | 0x20;
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

