// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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

undefined4 r_sci4_receive_interrupt(undefined4 param_1)

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
    return param_1;
  }
  return param_1;
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

undefined2 R_SCI5_Serial_Receive(undefined4 param_1,short param_2)

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

undefined2 R_SCI5_Serial_Send(undefined4 param_1,short param_2)

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

undefined4 r_sci5_transmit_interrupt(undefined4 param_1)

{
  byte bVar1;
  
  if (DAT_0001b622 == 0) {
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 & 0x7f;
    bVar1 = DAT_0008a0a2;
    DAT_0008a0a2 = bVar1 | 4;
    return param_1;
  }
  DAT_0008a0a3 = *DAT_0002081c;
  DAT_0002081c = DAT_0002081c + 1;
  DAT_0001b622 = DAT_0001b622 + -1;
  return param_1;
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

undefined4 r_sci5_receive_interrupt(undefined4 param_1)

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
    return param_1;
  }
  return param_1;
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


// ===== r_sci5_callback_transmitend @ fff9495b (1 bytes)

/* empty */

void r_sci5_callback_transmitend(void)

{
  return;
}


// ===== r_sci5_callback_receiveend @ fff9495c (5 bytes)

/* SCI5 receive-end callback: calls sdr_rx_done_cb (0xA2B3=1) */

void r_sci5_callback_receiveend(void)

{
  sdr_rx_done_cb();
  return;
}


// ===== r_sci5_callback_receiveerror @ fff94961 (1 bytes)

/* empty */

void r_sci5_callback_receiveerror(void)

{
  return;
}


// ===== sci5_rx_byte_hook @ fff94962 (82 bytes)

/* 06/'?' = 1 byte, 'r' = 7 bytes */

void sci5_rx_byte_hook(void)

{
  char cVar1;
  
  if (DAT_0001b624 != 0) {
    return;
  }
  cVar1 = *DAT_00020820;
  if ((cVar1 != '\x06') && (cVar1 != '?')) {
    if (cVar1 == 'r') {
      DAT_0001b626 = 7;
      return;
    }
    DAT_00020820 = DAT_00020820 + -1;
    DAT_0001b624 = 0xffff;
    return;
  }
  DAT_0001b626 = 1;
  return;
}


// ===== R_TPU0_Create @ fff949b4 (132 bytes)

/* TPU0 PCLKB/16, TGRA=374: 10 kHz (0.1 ms) tick, vec130 */

void R_TPU0_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xfe;
  DAT_00087782 = 0xf;
  bVar2 = DAT_00087382;
  DAT_00087382 = bVar2 & 0xf4 | 4;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xfe;
  DAT_00088110 = 0x2a;
  bVar2 = DAT_00088114;
  DAT_00088114 = bVar2 | 0x41;
  DAT_00088112 = 0;
  DAT_00088113 = 0;
  DAT_00088118 = 0x176;
  DAT_0008811a = 0x176;
  DAT_0008811c = 0x176;
  DAT_0008811e = 0x176;
  FUN_fff94a56();
  return;
}


// ===== R_TPU0_Start @ fff94a38 (15 bytes)

/* Enable vector 130 and TSTR bit 0 */

void R_TPU0_Start(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087210;
  DAT_00087210 = bVar1 | 4;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 1;
  return;
}


// ===== FUN_fff94a56 @ fff94a56 (1 bytes)

void FUN_fff94a56(void)

{
  return;
}


// ===== r_tpu0_tgia_isr @ fff94a57 (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94a5f) */
/* WARNING: Removing unreachable block (ram,0xfff94a57) */
/* WARNING: Removing unreachable block (ram,0xfff94a59) */
/* WARNING: Removing unreachable block (ram,0xfff94a61) */
/* vec130 -> swtimer_tick */

undefined4 r_tpu0_tgia_isr(undefined4 param_1)

{
  swtimer_tick();
  return param_1;
}


// ===== R_TPU1_Create @ fff94a65 (104 bytes)

/* TPU1 PCLKB/1, TGRA set by tone_set: tone sample clock, vec144 */

void R_TPU1_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xfd;
  DAT_00087790 = 0x14;
  bVar2 = DAT_00087390;
  DAT_00087390 = bVar2 & 0xfe | 0xe;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xfd;
  DAT_00088120 = 0x20;
  bVar2 = DAT_00088124;
  DAT_00088124 = bVar2 | 0x41;
  DAT_00088122 = 0;
  DAT_00088128 = 0x270;
  DAT_0008812a = 5999;
  FUN_fff94aeb();
  return;
}


// ===== R_TPU1_Start @ fff94acd (15 bytes)

/* TSTR bit 1 */

void R_TPU1_Start(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087212;
  DAT_00087212 = bVar1 | 1;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 2;
  return;
}


// ===== R_TPU1_Stop @ fff94adc (15 bytes)

/* Stop TPU1 */

void R_TPU1_Stop(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087212;
  DAT_00087212 = bVar1 & 0xfe;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 & 0xfd;
  return;
}


// ===== FUN_fff94aeb @ fff94aeb (1 bytes)

void FUN_fff94aeb(void)

{
  return;
}


// ===== r_tpu1_tgia_isr @ fff94aec (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfff94af4) */
/* WARNING: Removing unreachable block (ram,0xfff94aec) */
/* WARNING: Removing unreachable block (ram,0xfff94aee) */
/* WARNING: Removing unreachable block (ram,0xfff94af6) */
/* vec144 -> tone_sample_isr */

undefined4 r_tpu1_tgia_isr(undefined4 param_1)

{
  tone_sample_isr();
  return param_1;
}


// ===== app_main @ fff94afa (145 bytes)

/* Init sequence, waits for power-on (flag 0x20B3A) while still serving cat_parse (so PS works when
   off), then subsystem init and main_loop */

void app_main(void)

{
  wdt_kick();
  timers_init();
  FUN_fffb27df();
  eeprom_init();
  eeprom_load_all();
  key_task_init();
  sci_start_all();
  qmb_boot_init();
  while (DAT_00020b3a == '\0') {
    displink_task();
    cat_parse();
    wdt_kick();
  }
  if (DAT_00020b45 == '\x01') {
    DAT_00020b45 = '\0';
    eeprom_save_all();
    DAT_00020f10 = 1;
    wdt_kick();
  }
  shreg_bus_init();
  trx_init();
  sdr_init();
  dsp_link_init();
  portctl_init();
  dac_init_idle();
  keyer_init();
  tuner_init();
  menu_subsys_init();
  cat_apo_reset();
  main_loop();
  return;
}


// ===== main_loop @ fff94b8b (66 bytes)

/* Super-loop (no RTOS): polls ~16 tasks incl. cat_parse each pass */

void main_loop(void)

{
  do {
    wdt_kick();
    io_task();
    sdr_task();
    dsp_link_poll();
    rf_ctrl_task();
    beep_task();
    cat_parse();
    ladder_key_task();
    scan_task();
    dispreq_e8_task();
    dispreq_e7_task();
    keyer_task();
    FUN_fffd0582();
    displink_task();
    key_task();
    tuner_task();
  } while( true );
}


// ===== ver_main @ fff94bcd (12 bytes)

/* Returns pointer to MAIN version string 0xFFFFFF00 (VE0) */

undefined4 ver_main(void)

{
  return 0xffffff00;
}


// ===== FUN_fff94bd9 @ fff94bd9 (12 bytes)

undefined4 FUN_fff94bd9(void)

{
  return 0xffffff10;
}


// ===== FUN_fff94be5 @ fff94be5 (12 bytes)

undefined4 FUN_fff94be5(void)

{
  return 0xffffff20;
}


// ===== ver_display @ fff94bf1 (12 bytes)

/* Returns pointer to DISPLAY version 0x1436 (VE1) */

void ver_display(void)

{
  return;
}


// ===== FUN_fff94bfd @ fff94bfd (18 bytes)

void FUN_fff94bfd(undefined4 *param_1)

{
  DAT_0000143a = *(undefined2 *)(param_1 + 1);
  DAT_00001436 = *param_1;
  return;
}


// ===== FUN_fff94c0f @ fff94c0f (12 bytes)

void FUN_fff94c0f(void)

{
  return;
}


// ===== FUN_fff94c1b @ fff94c1b (18 bytes)

void FUN_fff94c1b(undefined4 *param_1)

{
  DAT_00001440 = param_1[1];
  DAT_0000143c = *param_1;
  return;
}


// ===== ver_dsp @ fff94c2d (12 bytes)

/* Returns pointer to DSP version 0x1444 (VE3) */

void ver_dsp(void)

{
  return;
}


// ===== ver_dsp_set @ fff94c39 (18 bytes)

/* Copies the 6-char "V01-01" DSP version text to 0x1444 (read by ver_dsp / VE3) */

void ver_dsp_set(undefined4 *param_1)

{
  DAT_00001448 = *(undefined2 *)(param_1 + 1);
  DAT_00001444 = *param_1;
  return;
}


// ===== ver_sdr @ fff94c4b (12 bytes)

/* Returns pointer to SDR version 0x144A (VE2) */

void ver_sdr(void)

{
  return;
}


// ===== FUN_fff94c57 @ fff94c57 (18 bytes)

void FUN_fff94c57(undefined4 *param_1)

{
  DAT_0000144e = *(undefined2 *)(param_1 + 1);
  DAT_0000144a = *param_1;
  return;
}


// ===== FUN_fff94c75 @ fff94c75 (54 bytes)

void FUN_fff94c75(undefined1 *param_1)

{
  byte2hex(&DAT_00001451,*param_1);
  byte2hex(&DAT_00001454,param_1[1]);
  DAT_00001450 = 0x56;
  DAT_00001453 = 0x2d;
  return;
}

