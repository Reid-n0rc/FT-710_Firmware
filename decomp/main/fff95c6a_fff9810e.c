// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== displink_rx_E4 @ fff95c6a (10 bytes)

/* E4: answer to 0x7B (clears +0x82, set by caller) */

void displink_rx_E4(void)

{
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E5 @ fff95c74 (22 bytes)

/* E5: clears +0x80 */

void displink_rx_E5(void)

{
  PTR_DAT_00025d38[0x80] = 0;
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E6_beep @ fff95c8a (50 bytes)

/* E6: beep_request(b1+1) */

void displink_rx_E6_beep(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == '\x02') {
    beep_request(3);
  }
  else if (cVar1 == '\x01') {
    beep_request(2);
  }
  else if (cVar1 == '\0') {
    beep_request(1);
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E7 @ fff95cbc (241 bytes)

/* E7: result code in +0x488 */

void displink_rx_E7(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == -1) {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xac] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 5;
    beep_stop();
    return;
  }
  if (cVar1 == '\x01') {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xab] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    if (*(char *)(param_1 + 5) == '\0') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 2;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x01') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 3;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x02') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 4;
      return;
    }
  }
  else if (cVar1 == '\0') {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xaa] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 1;
    return;
  }
  return;
}


// ===== displink_rx_E8 @ fff95dad (184 bytes)

/* E8: result code in +0x48C */

void displink_rx_E8(int param_1)

{
  if (*(char *)(param_1 + 1) == -1) {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xac] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 5;
    beep_stop();
    return;
  }
  if (*(char *)(param_1 + 1) == '\x01') {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xab] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    if (*(char *)(param_1 + 5) == '\0') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 2;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x01') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 3;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x02') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 4;
      return;
    }
  }
  return;
}


// ===== displink_rx_C3 @ fff95e65 (50 bytes)

/* C3 reply (to 0x43): payload -> +0x2ED, +0x3F6=1 */

void displink_rx_C3(int param_1)

{
  DAT_0001b3cc = 1;
  PTR_DAT_00025d38[0x3f6] = 1;
  smovf(PTR_DAT_00025d38 + 0x2ed,param_1 + 1,0x109);
  return;
}


// ===== displink_rx_C4_C5 @ fff95e97 (50 bytes)

/* C4/C5 replies (to 0x45/0x44): payload -> +0x2ED, +0x3F6=1 */

void displink_rx_C4_C5(int param_1)

{
  DAT_0001b3cc = 1;
  PTR_DAT_00025d38[0x3f6] = 1;
  smovf(PTR_DAT_00025d38 + 0x2ed,param_1 + 1,0x109);
  return;
}


// ===== FUN_fff95ec9 @ fff95ec9 (10 bytes)

void FUN_fff95ec9(void)

{
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E3_clock @ fff95ed3 (83 bytes)

/* E3: 5 bytes -> +0xAD..+0xB1 (DISPLAY RTC date/time [inference]) */

void displink_rx_E3_clock(int param_1)

{
  PTR_DAT_00025d38[0xad] = *(undefined1 *)(param_1 + 1);
  PTR_DAT_00025d38[0xae] = *(undefined1 *)(param_1 + 2);
  PTR_DAT_00025d38[0xaf] = *(undefined1 *)(param_1 + 3);
  PTR_DAT_00025d38[0xb0] = *(undefined1 *)(param_1 + 4);
  PTR_DAT_00025d38[0xb1] = *(undefined1 *)(param_1 + 5);
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_send_ack @ fff95f26 (25 bytes)

/* send 0x06 */

void displink_send_ack(void)

{
  undefined1 local_1;
  
  local_1 = 6;
  displink_uart_send((uint)&local_1,1);
  DAT_0001b3d2 = 1;
  return;
}


// ===== displink_send_nak @ fff95f3f (25 bytes)

/* send 0x15 */

void displink_send_nak(void)

{
  undefined1 local_1;
  
  local_1 = 0x15;
  displink_uart_send((uint)&local_1,1);
  DAT_0001b3d2 = 1;
  return;
}


// ===== displink_tx_schedule @ fff95f58 (689 bytes)

/* MAIN->DISPLAY frame scheduler (priority list in display-link.md) */

void displink_tx_schedule(void)

{
  bool bVar1;
  byte bVar2;
  
  if (DAT_0001b3d0 == '\x01') {
    displink_tx_60_hello();
    return;
  }
  if (PTR_DAT_00025d38[0xb7] == '\x01') {
    displink_tx_64();
    return;
  }
  if ((PTR_DAT_00025d38[0x400] == '\x01') && (PTR_DAT_00025d38[0x93] != '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d38[0x400] = 0;
    displink_tx_24();
    return;
  }
  if (PTR_DAT_00025d38[0x447] == '\x01') {
    power_down_save();
    return;
  }
  if (PTR_DAT_00025d38[0xba] != '\0') {
    if ((PTR_DAT_00025d38[0x1c0] == '\x01') || (PTR_DAT_00025d38[0x1c1] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      displink_tx_62();
      return;
    }
    displink_tx_30_31();
    return;
  }
  if (PTR_DAT_00025d38[0x81] == '\x01') {
    PTR_DAT_00025d38[0x81] = 0;
    displink_tx_7C();
    return;
  }
  if (PTR_DAT_00025d38[0x80] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x83] == '\x01') {
    PTR_DAT_00025d38[0x83] = 0;
    displink_tx_7B();
    return;
  }
  if (PTR_DAT_00025d38[0x82] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x85] == '\x01') {
    PTR_DAT_00025d38[0x85] = 0;
    displink_tx_7A();
    return;
  }
  if (PTR_DAT_00025d38[0x84] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x86] == '\x01') {
    displink_tx_70();
    return;
  }
  if (PTR_DAT_00025d38[0x87] == '\x01') {
    displink_tx_req();
    return;
  }
  if (PTR_DAT_00025d38[0x88] != '\0') {
    if (PTR_DAT_00025d38[0x90] != '\x01') {
      return;
    }
    displink_tx_50();
    return;
  }
  if (PTR_DAT_00025d38[0x89] == '\x01') {
    displink_tx_23();
    return;
  }
  if (PTR_DAT_00025d38[0x8a] == '\x01') {
    FUN_fff98e58();
    return;
  }
  if (PTR_DAT_00025d38[0x8b] == '\x01') {
    FUN_fff98e77();
    return;
  }
  if (PTR_DAT_00025d38[0x8c] == '\x01') {
    displink_tx_30_31();
    return;
  }
  if (PTR_DAT_00025d38[0x8d] == '\x01') {
    displink_tx_65_clock();
    return;
  }
  if (PTR_DAT_00025d38[0x99] == '\x01') {
    displink_tx_34();
    return;
  }
  if (PTR_DAT_00025d38[0x9a] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x8f] == '\0') {
    if ((PTR_DAT_00025d38[0x1c0] == '\x01') || (PTR_DAT_00025d38[0x1c1] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fff96124;
    }
  }
  bVar1 = false;
LAB_fff96124:
  if (bVar1) {
    displink_tx_30_31();
    return;
  }
  if (PTR_DAT_00025d38[0x90] == '\x01') {
    displink_tx_50();
    return;
  }
  if (PTR_DAT_00025d38[0x93] == '\x01') {
    displink_tx_3A();
    return;
  }
  if (PTR_DAT_00025d38[0x94] == '\x01') {
    displink_tx_39();
    return;
  }
  if (PTR_DAT_00025d38[0x91] == '\x01') {
    displink_tx_3F();
    return;
  }
  if (PTR_DAT_00025d38[0x95] == '\x01') {
    bVar2 = swtimer_expired(0x29);
    if (bVar2 != 1) {
      return;
    }
    swtimer_start(0x29,100);
    displink_tx_40();
    return;
  }
  if (PTR_DAT_00025d38[0x96] == '\x01') {
    displink_tx_37();
    return;
  }
  if (PTR_DAT_00025d38[0x97] != '\x01') {
    displink_tx_20_status();
    return;
  }
  displink_tx_41();
  return;
}


// ===== displink_tx_resend @ fff96209 (28 bytes)

/* resend frame 0x1456 (len 0x1B628) */

void displink_tx_resend(void)

{
  displink_uart_send(0x1456,DAT_0001b628);
  DAT_0001b3d2 = 1;
  return;
}


// ===== displink_tx_60_hello @ fff96225 (28 bytes)

/* 0x60 hello reply (0xB6 bytes) */

void displink_tx_60_hello(void)

{
  DAT_0001b3d1 = 1;
  displink_build_60();
  DAT_0001b628 = 0xb6;
  displink_tx_start(0xb6);
  return;
}


// ===== displink_build_60 @ fff96241 (532 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96241) */
/* WARNING: Removing unreachable block (ram,0xfff96452) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* versions (MAIN/DISPLAY/DSP/SDR) + status block */

void displink_build_60(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  
  mem_zero(0xb5,0x1456);
  DAT_00001456 = 0x60;
  puVar3 = (undefined4 *)ver_main();
  _DAT_000019c3 = *(undefined2 *)(puVar3 + 1);
  DAT_000019bf._1_1_ = (byte)((uint)*puVar3 >> 8);
  bVar2 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar3;
  cVar1 = hex2nib(bVar2);
  bVar2 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001457 = cVar1 << 4 | bVar2;
  cVar1 = hex2nib(DAT_000019c3);
  bVar2 = hex2nib(DAT_000019c4);
  DAT_00001458 = cVar1 << 4 | bVar2;
  puVar3 = (undefined4 *)ver_display();
  _DAT_000019c3 = *(undefined2 *)(puVar3 + 1);
  DAT_000019bf._1_1_ = (byte)((uint)*puVar3 >> 8);
  bVar2 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar3;
  cVar1 = hex2nib(bVar2);
  bVar2 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001459 = cVar1 << 4 | bVar2;
  cVar1 = hex2nib(DAT_000019c3);
  bVar2 = hex2nib(DAT_000019c4);
  DAT_0000145a = cVar1 << 4 | bVar2;
  puVar3 = (undefined4 *)ver_dsp();
  _DAT_000019c3 = *(undefined2 *)(puVar3 + 1);
  DAT_000019bf._1_1_ = (byte)((uint)*puVar3 >> 8);
  bVar2 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar3;
  cVar1 = hex2nib(bVar2);
  bVar2 = hex2nib(DAT_000019bf._2_1_);
  DAT_0000145b = cVar1 << 4 | bVar2;
  cVar1 = hex2nib(DAT_000019c3);
  bVar2 = hex2nib(DAT_000019c4);
  DAT_0000145c = cVar1 << 4 | bVar2;
  puVar3 = (undefined4 *)ver_sdr();
  _DAT_000019c3 = *(undefined2 *)(puVar3 + 1);
  DAT_000019bf._1_1_ = (byte)((uint)*puVar3 >> 8);
  bVar2 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar3;
  cVar1 = hex2nib(bVar2);
  bVar2 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001461 = cVar1 << 4 | bVar2;
  cVar1 = hex2nib(DAT_000019c3);
  bVar2 = hex2nib(DAT_000019c4);
  DAT_00001462 = cVar1 << 4 | bVar2;
  if ((*(short *)(PTR_DAT_00025d38 + 0x32) == 0) && (DAT_00004660 != '\0')) {
    *(undefined2 *)(PTR_DAT_00025d38 + 0x32) = 0xdb;
  }
  DAT_00001463 = (undefined1)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x32) >> 8);
  DAT_00001464 = (undefined1)*(undefined2 *)(PTR_DAT_00025d38 + 0x32);
  *(undefined2 *)(PTR_DAT_00025d38 + 0x32) = 0;
  displink_build_status();
  smovf(0x1465,0x16a1,0x97);
  DAT_000014fc = DAT_00009b0d;
  DAT_00001505 = DAT_00009b09;
  DAT_00001501 = DAT_00009b05;
  DAT_000014fd = DAT_00009b01;
  DAT_00001509 = DAT_00009dc5;
  return;
}


// ===== displink_build_status @ fff96455 (2367 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96d91) */
/* WARNING: Removing unreachable block (ram,0xfff96bd9) */
/* WARNING: Removing unreachable block (ram,0xfff96645) */
/* WARNING: Removing unreachable block (ram,0xfff96c0b) */
/* WARNING: Removing unreachable block (ram,0xfff96cbc) */
/* WARNING: Removing unreachable block (ram,0xfff96d02) */
/* 0x97-byte status block at 0x16A1 (used by 0x20 and 0x60) */

ushort displink_build_status(void)

{
  uint uVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  bool local_a;
  byte local_9;
  short sStack_8;
  ushort local_6;
  
  local_9 = 0;
  local_a = DAT_00009dbd == '\0';
  if (local_a) {
    DAT_00020874 = &DAT_00009d09;
    PTR_DAT_00025d38[0x40e] = 0;
  }
  else {
    DAT_00020874 = &DAT_00009d63;
    PTR_DAT_00025d38[0x40e] = 1;
  }
  local_a = !local_a;
  DAT_000016a1 = DAT_00009c37;
  local_6 = 2;
  DAT_000016a2 = FUN_fff96dde();
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff96f3e();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff96fb7();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9700b();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97049();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97075();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff970b8();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97105();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9716f(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  (&DAT_000016a0)[(ushort)(local_6 + 1)] = DAT_00009c5b & 7;
  local_6 = local_6 + 2;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff971fc(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9728c(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97430();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97567();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff976d2();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9770b(local_a);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  iVar6 = FUN_fffc4f8f();
  if (iVar6 == 0) {
    (&DAT_000016a0)[local_6] = DAT_00009c5a << 4 | DAT_00009be8 & 0xf;
  }
  else {
    (&DAT_000016a0)[local_6] = DAT_00009be8 & 0x5f | 0x50;
  }
  local_6 = local_6 + 1;
  FUN_fff977b3(&DAT_000016a0 + local_6,DAT_00020874);
  local_6 = local_6 + 2;
  local_9 = *DAT_00020874 & 0xf;
  if ((local_9 == 3) || (local_9 == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff9782b(&DAT_000016a0 + local_6);
  }
  local_6 = local_6 + 4;
  FUN_fff978eb(&DAT_000016a0 + local_6,DAT_00020874);
  if (DAT_00009ad5 < '\0') {
    (&DAT_000016a0)[local_6] = (&DAT_000016a0)[local_6] | 0x80;
  }
  local_6 = local_6 + 2;
  FUN_fff9795f(&DAT_000016a0 + local_6,DAT_00020874);
  local_6 = local_6 + 2;
  FUN_fff979d3(&DAT_000016a0 + local_6,DAT_00020874);
  local_6 = local_6 + 2;
  FUN_fff97a44(&DAT_000016a0 + local_6,DAT_00020874);
  (&DAT_000016a0)[(ushort)(local_6 + 2)] = DAT_00009c5f;
  (&DAT_000016a0)[(ushort)(local_6 + 3)] = DAT_00009c04 + '\x1e';
  local_6 = local_6 + 4;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97abc(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97b7b();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  FUN_fff97ba6(&DAT_000016a0 + local_6);
  (&DAT_000016a0)[(ushort)(local_6 + 6)] = 0xff;
  uVar5 = local_6 + 7;
  if (PTR_DAT_00025d38[0x483] == '\x01') {
    (&DAT_000016a0)[uVar5] = 0x2d;
    local_6 = local_6 + 8;
  }
  else {
    local_6 = uVar5;
    uVar3 = FUN_fff97c74();
    (&DAT_000016a0)[uVar5] = uVar3;
    local_6 = local_6 + 1;
  }
  DAT_0001b62a = local_6;
  (&DAT_000016a0)[local_6] = DAT_00009d09 & 0xf;
  DAT_0001b62e = local_6 + 1;
  uVar1 = (uint)DAT_0001b62e;
  local_6 = DAT_0001b62e;
  bVar4 = FUN_fff97cf7('\0',&local_9);
  (&DAT_000016a0)[uVar1] = bVar4;
  (&DAT_000016a0)[(ushort)(local_6 + 1)] = local_9;
  local_6 = local_6 + 2;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97e1d(0);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  if (PTR_DAT_00025d38[0x437] == '\0') {
    DAT_000019c9 = 0;
    DAT_000019c5 = 0;
    FUN_fff982aa(0,0x19c5,local_6 + 0x169f);
    (&DAT_000016a4)[local_6] = DAT_000019c9;
    *(undefined4 *)(&DAT_000016a0 + local_6) = DAT_000019c5;
    uVar5 = local_6;
  }
  else {
    ui_numentry_to_bcd();
    local_9 = 5;
    smovf(&DAT_000016a0 + local_6,PTR_DAT_00025d38 + 0x7b,5);
    uVar5 = local_6;
  }
  local_6 = uVar5 + 5;
  uVar1 = (uint)local_6;
  *(undefined4 *)(&DAT_000016a8 + uVar1) = DAT_00009d5f;
  *(undefined4 *)(&DAT_000016a4 + uVar1) = DAT_00009d5b;
  *(undefined4 *)(&DAT_000016a0 + uVar1) = DAT_00009d57;
  (&DAT_000016a0)[(ushort)(uVar5 + 0x11)] = PTR_DAT_00025d38[0x425];
  (&DAT_000016a0)[(ushort)(uVar5 + 0x12)] = DAT_00009d51;
  (&DAT_000016a0)[(ushort)(uVar5 + 0x13)] = DAT_00009d52;
  DAT_0001b62c = uVar5 + 0x15;
  (&DAT_000016a0)[DAT_0001b62c] = DAT_00009d63 & 0xf;
  DAT_0001b630 = uVar5 + 0x16;
  uVar1 = (uint)DAT_0001b630;
  local_6 = DAT_0001b630;
  bVar4 = FUN_fff97cf7('\x01',&local_9);
  (&DAT_000016a0)[uVar1] = bVar4;
  (&DAT_000016a0)[(ushort)(local_6 + 1)] = local_9;
  local_6 = local_6 + 2;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff97e1d(1);
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  DAT_000019c9 = 0;
  DAT_000019c5 = 0;
  FUN_fff982aa(1,0x19c5,local_6 + 0x169f);
  (&DAT_000016a4)[local_6] = DAT_000019c9;
  *(undefined4 *)(&DAT_000016a0 + local_6) = DAT_000019c5;
  uVar5 = local_6 + 5;
  *(undefined4 *)(&DAT_000016a8 + uVar5) = DAT_00009db9;
  *(undefined4 *)(&DAT_000016a4 + uVar5) = DAT_00009db5;
  *(undefined4 *)(&DAT_000016a0 + uVar5) = DAT_00009db1;
  (&DAT_000016a0)[(ushort)(local_6 + 0x11)] = PTR_DAT_00025d38[0x426];
  (&DAT_000016a0)[(ushort)(local_6 + 0x12)] = DAT_00009dab;
  (&DAT_000016a0)[(ushort)(local_6 + 0x13)] = DAT_00009dac;
  local_6 = local_6 + 0x15;
  if (DAT_00009dbd == '\x01') {
    DAT_00020878 = &DAT_000016a0 + DAT_0001b62a;
    DAT_0002087c = &DAT_000016a0 + DAT_0001b62c;
    for (sStack_8 = DAT_0001b62c - DAT_0001b62a; sStack_8 != 0; sStack_8 = sStack_8 + -1) {
      local_9 = *DAT_00020878;
      *DAT_00020878 = *DAT_0002087c;
      *DAT_0002087c = local_9;
      DAT_00020878 = DAT_00020878 + 1;
      DAT_0002087c = DAT_0002087c + 1;
    }
  }
  if (DAT_00009c5e == '\x01') {
    (&DAT_000016a0)[DAT_0001b62e] = 9;
    (&DAT_000016a0)[DAT_0001b630] = 10;
  }
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff9849e();
  (&DAT_000016a0)[uVar1] = uVar3;
  local_6 = local_6 + 1;
  uVar1 = (uint)local_6;
  uVar3 = FUN_fff98526(DAT_00020874);
  (&DAT_000016a0)[uVar1] = uVar3;
  (&DAT_000016a0)[(ushort)(local_6 + 7)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 8)] = DAT_00009a8d & 3 | DAT_00009a8c << 7;
  (&DAT_000016a0)[(ushort)(local_6 + 9)] = (DAT_00009a79 & 3) << 4;
  (&DAT_000016a0)[(ushort)(local_6 + 10)] = DAT_00009c03;
  (&DAT_000016a0)[(ushort)(local_6 + 0xb)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0xc)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0xd)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0xe)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0xf)] = 0;
  (&DAT_000016a0)[(ushort)(local_6 + 0x10)] = 0;
  local_9 = DAT_00009c3c & 7 | (DAT_00009c39 & 3) << 5 | 0x18;
  (&DAT_000016a0)[(ushort)(local_6 + 0x11)] = local_9;
  sStack_8 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10;
  (&DAT_000016a0)[(ushort)(local_6 + 0x13)] = (char)((ushort)sStack_8 >> 8);
  (&DAT_000016a0)[(ushort)(local_6 + 0x14)] = (char)sStack_8;
  local_6 = local_6 + 0x15;
  disp_put_op_freq(&DAT_000016a0 + local_6);
  local_6 = local_6 + 4;
  disp_put_tx_freq(&DAT_000016a0 + local_6);
  local_6 = local_6 + 4;
  disp_put_dial_freq(&DAT_000016a0 + local_6);
  local_6 = local_6 + 4;
  disp_put_scope_start((int)(&DAT_000016a0 + local_6));
  return local_6 + 0x17;
}


// ===== FUN_fff96d94 @ fff96d94 (74 bytes)

char FUN_fff96d94(byte param_1)

{
  byte bVar1;
  byte local_3;
  
  local_3 = DAT_00009014;
  if ((DAT_00009ac0 == '\0') && (4 < DAT_00009014)) {
    local_3 = 5;
  }
  bVar1 = param_1;
  if (param_1 < local_3) {
    bVar1 = local_3;
  }
  local_3 = bVar1;
  local_3 = local_3 - param_1;
  if (local_3 == '\0') {
    local_3 = '\x01';
  }
  return local_3;
}


// ===== FUN_fff96dde @ fff96dde (352 bytes)

undefined1 FUN_fff96dde(void)

{
  undefined1 local_2;
  
  if (DAT_00009c36 == '\0') {
    if (DAT_00009c35 == '\0') {
      if (DAT_00009c38 == '\0') {
        local_2 = 3;
      }
      else if (DAT_00009c38 == '\x01') {
        local_2 = 4;
      }
      else {
        local_2 = 5;
      }
    }
    else if (DAT_00009c35 == '\x01') {
      if (PTR_DAT_00025d38[0x67] == '\0') {
        if (DAT_00009c38 == '\0') {
          local_2 = 6;
        }
        else if (DAT_00009c38 == '\x01') {
          local_2 = 7;
        }
        else {
          local_2 = 8;
        }
      }
      else if (DAT_00009c38 == '\0') {
        local_2 = 3;
      }
      else if (DAT_00009c38 == '\x01') {
        local_2 = 4;
      }
      else {
        local_2 = 5;
      }
    }
    else if (PTR_DAT_00025d38[0x67] == '\0') {
      if (DAT_00009c38 == '\0') {
        local_2 = 9;
      }
      else if (DAT_00009c38 == '\x01') {
        local_2 = 10;
      }
      else {
        local_2 = 0xb;
      }
    }
    else if (DAT_00009c38 == '\0') {
      local_2 = 3;
    }
    else if (DAT_00009c38 == '\x01') {
      local_2 = 4;
    }
    else {
      local_2 = 5;
    }
  }
  else if (DAT_00009c35 == '\0') {
    local_2 = 0;
  }
  else if (DAT_00009c35 == '\x01') {
    if (PTR_DAT_00025d38[0x67] == '\0') {
      local_2 = 1;
    }
    else {
      local_2 = 0;
    }
  }
  else if (PTR_DAT_00025d38[0x67] == '\0') {
    local_2 = 2;
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fff96f3e @ fff96f3e (121 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96f69) */

byte FUN_fff96f3e(void)

{
  char local_3;
  byte local_2;
  
  local_2 = DAT_00009dbd;
  if (PTR_DAT_00025d38[0x405] == '\x01') {
    if (DAT_00009dbd == '\0') {
      local_2 = '\x01';
    }
    else {
      local_2 = '\0';
    }
  }
  local_2 = local_2 << 7;
  if (DAT_00009dbd == '\0') {
    local_3 = PTR_DAT_00025d38[0x425];
  }
  else {
    local_3 = PTR_DAT_00025d38[0x426];
  }
  if (DAT_00009c5e == '\x01') {
    local_2 = local_2 | 0x20;
  }
  else if (local_3 == '\0') {
    local_2 = local_2 | 0x10;
  }
  else {
    local_2 = local_2 | 0x40;
  }
  return local_2;
}


// ===== FUN_fff96fb7 @ fff96fb7 (84 bytes)

undefined1 FUN_fff96fb7(void)

{
  bool bVar1;
  undefined1 local_2;
  
  local_2 = 0;
  if ((PTR_DAT_00025d38[0x96] == '\x01') || (PTR_DAT_00025d38[0x97] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d38[0x95] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_2 = 0x20;
  }
  return local_2;
}


// ===== FUN_fff9700b @ fff9700b (62 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97017) */
/* WARNING: Removing unreachable block (ram,0xfff97028) */

byte FUN_fff9700b(void)

{
  return DAT_00009c5e | (DAT_00009c3d & 1) << 5 | (DAT_00009dc6 & 1) << 6;
}


// ===== FUN_fff97049 @ fff97049 (44 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97055) */
/* WARNING: Removing unreachable block (ram,0xfff97063) */

byte FUN_fff97049(void)

{
  return (DAT_00009b17 & 1) << 6 | DAT_00009b16 << 7;
}


// ===== FUN_fff97075 @ fff97075 (67 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97082) */
/* WARNING: Removing unreachable block (ram,0xfff97091) */
/* WARNING: Removing unreachable block (ram,0xfff970a6) */

byte FUN_fff97075(void)

{
  return (PTR_DAT_00025d38[0x69] & 3) << 4 |
         (PTR_DAT_00025d38[0x68] & 1) << 6 | PTR_DAT_00025d38[0x67] << 7;
}


// ===== FUN_fff970b8 @ fff970b8 (77 bytes)

byte FUN_fff970b8(void)

{
  byte local_3;
  char local_2;
  
  local_3 = PTR_DAT_00025d38[0x34];
  if (PTR_DAT_00025d38[0x437] == '\0') {
    local_2 = DAT_00009b10;
  }
  else {
    local_2 = PTR_DAT_00025d38[0x480];
  }
  if (local_2 == '\0') {
    local_3 = local_3 & 0xf0;
  }
  return local_3;
}


// ===== FUN_fff97105 @ fff97105 (106 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97135) */
/* WARNING: Removing unreachable block (ram,0xfff97111) */
/* WARNING: Removing unreachable block (ram,0xfff97120) */
/* WARNING: Removing unreachable block (ram,0xfff9714a) */
/* WARNING: Removing unreachable block (ram,0xfff9715e) */

byte FUN_fff97105(void)

{
  return (DAT_00009c5c & 1) << 3 |
         (PTR_DAT_00025d38[0x6c] & 1) << 4 |
         (PTR_DAT_00025d38[0x6b] & 1) << 5 | (PTR_DAT_00025d38[0x6a] & 1) << 6 | DAT_00009be7 << 7;
}


// ===== FUN_fff9716f @ fff9716f (141 bytes)

byte FUN_fff9716f(byte *param_1)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 4 < 2) {
      local_6 = DAT_00009a4b | 0x80;
      goto LAB_fff971e9;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 < 2) {
        local_6 = DAT_00009a36 | 0x80;
      }
      else {
        local_6 = 0;
      }
      goto LAB_fff971e9;
    }
  }
  local_6 = DAT_00009a73 | 0x80;
LAB_fff971e9:
  if ((local_6 & 0x7f) == 6) {
    local_6 = local_6 & 0x7f;
  }
  return local_6;
}


// ===== FUN_fff971fc @ fff971fc (144 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97257) */
/* WARNING: Removing unreachable block (ram,0xfff97270) */

byte FUN_fff971fc(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bStack_7;
  char cStack_6;
  
  bVar2 = FUN_fff9921f();
  bVar3 = *param_1 & 0xf;
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cStack_6 = '\x02';
  }
  else if ((bVar2 & 0x80) == 0) {
    cStack_6 = '\0';
  }
  else {
    cStack_6 = '\x01';
  }
  if ((param_1[5] & 3) == 0) {
    bStack_7 = 0;
  }
  else {
    bStack_7 = (param_1[5] & 3) - 1;
  }
  return param_1[3] & 3 | (bStack_7 & 3) << 2 | cStack_6 << 4;
}


// ===== FUN_fff9728c @ fff9728c (304 bytes)

byte FUN_fff9728c(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bStack_9;
  byte local_6;
  
  local_6 = 0;
  bVar3 = *param_1 & 0xf;
  if (DAT_00009aa4 == '\x01') {
    if ((bVar3 == 3) || (bVar3 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fff972c7;
    }
  }
  bVar1 = false;
LAB_fff972c7:
  if (bVar1) {
    local_6 = 0x80;
  }
  if ((bVar3 == 3) || (bVar3 == 2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && ((param_1[0x14] & 0x20) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | 0x40;
  }
  bVar2 = FUN_fff973bc(param_1);
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (bVar3 != 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar3 != 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | (byte)((bVar2 & 0x40) >> 1);
  }
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (bVar3 != 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar3 != 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | (byte)((bVar2 & 0x80) >> 3);
  }
  bVar3 = FUN_fff9921f(param_1);
  if ((bVar3 & 0x40) == 0) {
    bStack_9 = 0;
  }
  else {
    bStack_9 = (bVar3 >> 4 & 3) + 1;
  }
  return local_6 | bStack_9;
}


// ===== FUN_fff973bc @ fff973bc (116 bytes)

byte FUN_fff973bc(byte *param_1)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = *param_1 & 0xf;
  if (uVar1 == 0xe) {
LAB_fff97422:
    local_6 = param_1[0x28];
  }
  else {
    if (uVar1 - 2 < 2) {
      return param_1[0x14];
    }
    if (uVar1 - 4 < 2) {
      return param_1[0x32];
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97422;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return param_1[0x1e];
        }
        if ((*param_1 & 0xf) != 0 && uVar1 != 1) {
          return 0;
        }
        return param_1[10];
      }
    }
    local_6 = param_1[0x3c];
  }
  return local_6;
}


// ===== FUN_fff97430 @ fff97430 (251 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97487) */
/* WARNING: Removing unreachable block (ram,0xfff97454) */
/* WARNING: Removing unreachable block (ram,0xfff974b0) */
/* WARNING: Removing unreachable block (ram,0xfff974ce) */

byte FUN_fff97430(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  byte bStack_a;
  char cStack_9;
  
  pbVar5 = vfo_rec_ptr(1);
  bVar3 = *pbVar5 & 0xf;
  iVar6 = FUN_fff9752b(pbVar5);
  iVar7 = FUN_fffc3e3c(pbVar5);
  if ((iVar7 == 0) || (DAT_00009c02 != '\x01')) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  pcVar8 = (char *)FUN_fff99669();
  if (pcVar8 == (char *)0x0) {
    cStack_9 = '\0';
  }
  else if (*pcVar8 == '\0') {
    cStack_9 = '\0';
  }
  else {
    cStack_9 = '\x01';
  }
  bVar4 = FUN_fff973bc(pbVar5);
  bStack_a = ((bVar4 & 2) != 0) << 2 | cStack_9 << 4 | cVar2 << 5 | (iVar6 != 0) << 6;
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_a = bStack_a | (pbVar5[2] >> 2 & 3) + 1;
  }
  return bStack_a;
}


// ===== FUN_fff9752b @ fff9752b (60 bytes)

undefined1 FUN_fff9752b(byte *param_1)

{
  bool bVar1;
  undefined1 local_7;
  
  local_7 = 0;
  if (((*param_1 & 0xf) == 0) || ((*param_1 & 0xf) == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_00009bf1 != '\0')) {
    local_7 = 1;
  }
  return local_7;
}


// ===== FUN_fff97567 @ fff97567 (363 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9769f) */
/* WARNING: Removing unreachable block (ram,0xfff976ae) */

byte FUN_fff97567(void)

{
  bool bVar1;
  char local_3;
  
  if ((PTR_DAT_00025d38[0x1c9] == '\x01') || (PTR_DAT_00025d38[0x78] == '\x02')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_3 = '\x01';
  }
  else {
    if ((PTR_DAT_00025d38[0x417] == '\x01') && (PTR_DAT_00025d38[0x1bc] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_3 = '\x01';
    }
    else {
      if ((PTR_DAT_00025d38[0x417] == '\x01') && (PTR_DAT_00025d38[0x1bc] == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        local_3 = '\0';
      }
      else {
        if ((PTR_DAT_00025d38[0x1cc] == '\x01') || (PTR_DAT_00025d38[0x1cd] == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if ((bVar1) || (PTR_DAT_00025d38[0x78] == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          local_3 = '\x02';
        }
        else {
          if ((PTR_DAT_00025d38[0x92] == '\x01') && (PTR_DAT_00025d38[0x1bc] == '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            local_3 = '\x03';
          }
          else {
            local_3 = '\0';
          }
        }
      }
    }
  }
  return PTR_DAT_00025d38[0x6e] & 3 | (PTR_DAT_00025d38[0x6d] & 3) << 3 | local_3 << 6;
}


// ===== FUN_fff976d2 @ fff976d2 (57 bytes)

/* WARNING: Removing unreachable block (ram,0xfff976ee) */

byte FUN_fff976d2(void)

{
  byte bVar1;
  byte bStack_2;
  
  bVar1 = swtimer_expired(0x2a);
  if (bVar1 == 0) {
    bStack_2 = 0x40;
  }
  else {
    bStack_2 = PTR_DAT_00025d38[0x6f] << 4;
  }
  return DAT_00009be6 & 7 | bStack_2;
}


// ===== FUN_fff9770b @ fff9770b (36 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97719) */

byte FUN_fff9770b(byte param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = DAT_00009c35 << 6;
  bVar2 = scope_span_index(param_1);
  return bVar2 | bVar1;
}


// ===== scope_span_index @ fff9772f (85 bytes)

/* Index into span table 0xFFF89D24 */

byte scope_span_index(byte param_1)

{
  byte bVar1;
  uint freq;
  byte bStack_9;
  
  freq = vfo_freq_clar(0,param_1);
  bVar1 = freq_range_index(freq);
  if (bVar1 == 0xff) {
    bStack_9 = 0;
  }
  else if (DAT_00009c35 == '\x02') {
    bStack_9 = (&DAT_00009c4c)[bVar1];
  }
  else {
    bStack_9 = (&DAT_00009c3e)[bVar1];
  }
  return bStack_9;
}


// ===== range_cmp3 @ fff97784 (47 bytes)

/* 0 if v<lo, 1 if v>hi, else 2 */

byte range_cmp3(uint *v,uint *range)

{
  byte local_a;
  
  if (*v < *range) {
    local_a = 0;
  }
  else if (range[1] < *v) {
    local_a = 1;
  }
  else {
    local_a = 2;
  }
  return local_a;
}


// ===== FUN_fff977b3 @ fff977b3 (120 bytes)

void FUN_fff977b3(undefined1 *param_1,byte *param_2)

{
  uint uVar1;
  undefined2 local_a;
  
  local_a = 0;
  uVar1 = *param_2 & 0xf;
  if (uVar1 == 0xe) {
LAB_fff97816:
    local_a = 0xc80;
  }
  else {
    if (uVar1 - 2 < 2) {
      local_a = 500;
      goto LAB_fff9781b;
    }
    if (uVar1 - 4 < 2) {
      local_a = 9000;
      goto LAB_fff9781b;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97816;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          local_a = 500;
        }
        else if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          local_a = 3000;
        }
        goto LAB_fff9781b;
      }
    }
    local_a = 16000;
  }
LAB_fff9781b:
  *param_1 = (char)((ushort)local_a >> 8);
  param_1[1] = (char)local_a;
  return;
}


// ===== FUN_fff9782b @ fff9782b (192 bytes)

void FUN_fff9782b(void *param_1)

{
  byte bVar1;
  
  bVar1 = swtimer_expired(0x28);
  if (bVar1 == 1) {
    swtimer_start(0x28,100);
    if (PTR_DAT_00025d38[0x67] == '\x01') {
      DAT_0001ff1a = 0;
    }
    else {
      DAT_0001ff1a = dsp_tune_offset();
    }
    if ((short)DAT_0001ff1a < -99) {
      DAT_0001ff1a = 0xff9d;
    }
    else if (99 < (short)DAT_0001ff1a) {
      DAT_0001ff1a = 99;
    }
    DAT_0001ff1a = DAT_0001ff1a + 0xc;
    if ((short)DAT_0001ff1a < 0x19) {
      if ((short)DAT_0001ff1a < 0) {
        DAT_0001ff1a = 0;
      }
    }
    else {
      DAT_0001ff1a = 0;
    }
  }
  *(undefined4 *)param_1 = (&DAT_fff804de)[(short)DAT_0001ff1a];
  return;
}


// ===== FUN_fff978eb @ fff978eb (116 bytes)

void FUN_fff978eb(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2 & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x16);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x34);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97954;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x20);
          return;
        }
        if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          *param_1 = *(undefined2 *)(param_2 + 0xc);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x3e);
    return;
  }
LAB_fff97954:
  *param_1 = *(undefined2 *)(param_2 + 0x2a);
  return;
}


// ===== FUN_fff9795f @ fff9795f (116 bytes)

void FUN_fff9795f(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2 & 0xf;
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x18);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x36);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff979c8;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x22);
          return;
        }
        if ((*param_2 & 0xf) == 0 || uVar1 == 1) {
          *param_1 = *(undefined2 *)(param_2 + 0xe);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x40);
    return;
  }
LAB_fff979c8:
  *param_1 = *(undefined2 *)(param_2 + 0x2c);
  return;
}


// ===== FUN_fff979d3 @ fff979d3 (113 bytes)

void FUN_fff979d3(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  undefined2 uStack_a;
  byte *local_8;
  undefined2 *local_4;
  
  uVar1 = (uint)(*param_2 & 0xf);
  if (3 < uVar1) {
    if (uVar1 == 4) {
      *param_1 = *(undefined2 *)(param_2 + 0x38);
      return;
    }
    if (uVar1 == 5) {
      *(undefined1 *)param_1 = 0x17;
      *(undefined1 *)((int)param_1 + 1) = 0x70;
      return;
    }
    if (uVar1 == 6) {
LAB_fff97a2d:
      *param_1 = *(undefined2 *)(param_2 + 0x42);
      return;
    }
    if (uVar1 == 7) {
LAB_fff97a36:
      *(undefined1 *)param_1 = 0x3e;
      *(undefined1 *)((int)param_1 + 1) = 0x80;
      return;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 == 10) goto LAB_fff97a2d;
      if (uVar1 == 0xb) goto LAB_fff97a36;
      if (2 < uVar1 - 0xc) {
        return;
      }
    }
  }
  local_8 = param_2;
  local_4 = param_1;
  FUN_fffc4e4f(&uStack_a);
  *local_4 = uStack_a;
  return;
}


// ===== FUN_fff97a44 @ fff97a44 (120 bytes)

void FUN_fff97a44(undefined2 *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(*param_2 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 2 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x1c);
      return;
    }
    if (uVar1 - 4 < 2) {
      *param_1 = *(undefined2 *)(param_2 + 0x3a);
      return;
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97ab1;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x26);
          return;
        }
        if (uVar1 < 2) {
          *param_1 = *(undefined2 *)(param_2 + 0x12);
          return;
        }
        return;
      }
    }
    *param_1 = *(undefined2 *)(param_2 + 0x44);
    return;
  }
LAB_fff97ab1:
  *param_1 = *(undefined2 *)(param_2 + 0x30);
  return;
}


// ===== FUN_fff97abc @ fff97abc (191 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97af2) */
/* WARNING: Removing unreachable block (ram,0xfff97b1d) */

byte FUN_fff97abc(undefined4 param_1)

{
  int iVar1;
  undefined2 uStack_a;
  undefined1 auStack_8 [2];
  byte local_6;
  undefined4 local_4;
  
  if (PTR_DAT_00025d38[0x70] == '\0') {
    PTR_DAT_00025d38[0x71] = 1;
    PTR_DAT_00025d38[0x72] = 0;
  }
  local_6 = PTR_DAT_00025d38[0x70] << 7;
  if (PTR_DAT_00025d38[0x71] != '\0') {
    local_6 = local_6 | 0x40;
  }
  local_6 = PTR_DAT_00025d38[0x73] | PTR_DAT_00025d38[0x47a] << 2 | local_6;
  local_4 = param_1;
  FUN_fff979d3(auStack_8,param_1);
  FUN_fff977b3(&uStack_a,local_4);
  iVar1 = FUN_fffede1d(auStack_8,&uStack_a,2);
  if (iVar1 != 0) {
    local_6 = local_6 | 0x10;
  }
  FUN_fff97a44(auStack_8,local_4);
  uStack_a = 0;
  iVar1 = FUN_fffede1d(auStack_8,&uStack_a,2);
  if (iVar1 != 0) {
    local_6 = local_6 | 0x20;
  }
  return local_6;
}


// ===== FUN_fff97b7b @ fff97b7b (43 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97b88) */

byte FUN_fff97b7b(void)

{
  return PTR_DAT_00025d38[0x79] & 0xf | PTR_DAT_00025d38[0x78] << 4;
}


// ===== FUN_fff97ba6 @ fff97ba6 (206 bytes)

void FUN_fff97ba6(void *param_1)

{
  if (PTR_DAT_00025d38[0x41a] != '\x01') {
    if (PTR_DAT_00025d38[0x67] == '\x01') {
      *(undefined1 *)param_1 = 0;
    }
    else if (DAT_00009c35 == '\0') {
      *(undefined1 *)param_1 = 0;
    }
    else if (DAT_00009c35 == '\x01') {
      *(undefined1 *)param_1 = 1;
    }
    else {
      *(undefined1 *)param_1 = 2;
    }
    if (DAT_00009c36 == '\x01') {
      *(undefined1 *)((int)param_1 + 1) = 0x84;
    }
    else {
      *(undefined1 *)((int)param_1 + 1) = 3;
    }
    if (DAT_00009c37 == '\x01') {
      *(undefined1 *)((int)param_1 + 2) = 0x86;
    }
    else {
      *(undefined1 *)((int)param_1 + 2) = 5;
    }
    if (DAT_00009c3d == '\x01') {
      *(undefined1 *)((int)param_1 + 3) = 0x88;
    }
    else {
      *(undefined1 *)((int)param_1 + 3) = 7;
    }
    *(undefined1 *)((int)param_1 + 4) = 9;
    *(undefined1 *)((int)param_1 + 5) = 10;
    return;
  }
  *(undefined2 *)((int)param_1 + 4) = 0x7f7f;
  *(undefined4 *)param_1 = 0x7f7f0c0b;
  return;
}


// ===== FUN_fff97c74 @ fff97c74 (131 bytes)

undefined1 FUN_fff97c74(void)

{
  char cVar1;
  undefined1 local_2;
  
  if (PTR_DAT_00025d38[0x1c1] == '\0') {
    local_2 = DAT_00009dc9;
  }
  else {
    cVar1 = PTR_DAT_00025d38[0x1c2];
    if (cVar1 == '\v') {
      local_2 = 3;
    }
    else if (cVar1 == '&') {
      local_2 = 8;
    }
    else if (cVar1 == '/') {
      local_2 = 0x11;
    }
    else if (cVar1 == 'T') {
      local_2 = 0x36;
    }
    else if (cVar1 == '9') {
      local_2 = 0x1b;
    }
    else if (cVar1 == 'F') {
      local_2 = 0x10;
    }
    else if (cVar1 == '8') {
      local_2 = 0x1a;
    }
    else {
      local_2 = DAT_00009dc9;
    }
  }
  return local_2;
}


// ===== FUN_fff97cf7 @ fff97cf7 (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97e1a) */

byte FUN_fff97cf7(char param_1,byte *param_2)

{
  char cVar1;
  byte local_11;
  undefined1 local_10;
  char local_f;
  byte local_e;
  
  if (PTR_DAT_00025d38[0x405] == '\0') {
    if (param_1 == '\0') {
      *param_2 = DAT_000060c9;
      local_f = DAT_00009dbe;
      local_10 = DAT_0000901f;
    }
    else {
      *param_2 = DAT_000060ca;
      local_f = DAT_00009dbf;
      local_10 = DAT_00009021;
    }
  }
  else if (param_1 == '\0') {
    *param_2 = DAT_000060ca;
    local_f = DAT_00009dbf;
    local_10 = DAT_00009021;
  }
  else {
    *param_2 = DAT_000060c9;
    local_f = DAT_00009dbe;
    local_10 = DAT_0000901f;
  }
  if (local_f == '\x05') {
    cVar1 = FUN_fff96d94(local_10);
    *param_2 = cVar1 - 0x39;
    local_11 = 5;
  }
  else if (local_f == '\x02') {
    if (*param_2 < 0x84) {
      if (*param_2 < 0x75) {
        local_e = 2;
      }
      else {
        *param_2 = *param_2 + 0x21;
        local_e = 7;
      }
    }
    else {
      *param_2 = 199;
      local_e = 8;
    }
    local_11 = local_e;
  }
  else if (local_f == '\x03') {
    local_11 = 3;
  }
  else if (local_f == '\x04') {
    local_11 = 4;
  }
  else if (local_f == '\0') {
    local_11 = 0;
  }
  else {
    local_11 = 1;
  }
  return local_11;
}


// ===== FUN_fff97e1d @ fff97e1d (162 bytes)

byte FUN_fff97e1d(char param_1)

{
  int iVar1;
  byte local_3;
  
  local_3 = 0;
  if (PTR_DAT_00025d38[0x40d] == '\0') {
    if (param_1 == DAT_00009dbd) {
      iVar1 = FUN_fff9847e();
      if (iVar1 == 0) {
        local_3 = 0x20;
      }
      local_3 = FUN_fff97ebf(param_1,local_3);
    }
    else {
      if (PTR_DAT_00025d38[0x41d] == '\0') {
        local_3 = 0x20;
      }
      local_3 = FUN_fff97ebf(param_1,local_3);
    }
  }
  else if (param_1 == PTR_DAT_00025d38[0x40e]) {
    local_3 = FUN_fff97ebf(param_1,0);
  }
  else if (param_1 == DAT_00009dbd) {
    iVar1 = FUN_fff9847e();
    if (iVar1 == 0) {
      local_3 = 0x20;
    }
    local_3 = FUN_fff97ebf(param_1,local_3);
  }
  else {
    local_3 = FUN_fff97ebf(param_1,0x20);
  }
  return local_3;
}


// ===== FUN_fff97ebf @ fff97ebf (591 bytes)

byte FUN_fff97ebf(char param_1,byte param_2)

{
  bool bVar1;
  byte bVar2;
  undefined1 uStack_a;
  char cStack_9;
  byte bStack_5;
  byte local_4;
  byte local_2;
  byte local_1;
  
  bVar2 = param_2 & 0xf0;
  local_4 = bVar2 | 0xd4;
  if (DAT_00009c5e == '\0') {
    if (DAT_00009dbd == '\0') {
      if (param_1 == '\x01') {
        local_4 = bVar2 | 0xd7;
      }
    }
    else if (param_1 == '\0') {
      local_4 = bVar2 | 0xd7;
    }
  }
  local_2 = param_2;
  local_1 = param_1;
  if (PTR_DAT_00025d38[0x418] == '\x01') {
    if ((DAT_00009dbd == param_1) && (PTR_DAT_00025d38[0x419] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((bVar1) && (PTR_DAT_00025d38[0x1bc] == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_4 = local_4 & 0x3f;
    }
  }
  else {
    FUN_fff9810e(param_1,(uint)&uStack_a);
    if (cStack_9 == '\0') {
      local_4 = local_4 & 0x7f;
    }
    if (DAT_00009c5e == '\x01') {
      if (DAT_00009dbd == '\0') {
        if ((PTR_DAT_00025d38[0x482] != '\0') || (local_1 != 1)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_4 = local_4 & 0xf0 | 5;
        }
        if ((PTR_DAT_00025d38[0x482] == '\x01') && (local_1 == 0)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          local_4 = local_4 & 0xf0 | 6;
        }
      }
      else {
        if ((PTR_DAT_00025d38[0x482] != '\0') || (local_1 != 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_4 = local_4 & 0xf0 | 5;
        }
        if ((PTR_DAT_00025d38[0x482] == '\x01') && (local_1 == 1)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          local_4 = local_4 & 0xf0 | 6;
        }
      }
    }
    if (DAT_00009dbd == '\0') {
      if ((PTR_DAT_00025d38[0x425] != '\0') && (local_1 == 1)) {
        local_4 = local_4 & 0xf0 | 9;
      }
    }
    else if ((PTR_DAT_00025d38[0x426] != '\0') && (local_1 == 0)) {
      local_4 = local_4 & 0xf0 | 9;
    }
  }
  if (local_1 == 0) {
    bStack_5 = DAT_00009d0e;
  }
  else {
    bStack_5 = DAT_00009d68;
  }
  bVar2 = vfo_is_memory(local_1);
  if ((bVar2 == 1) && ((bStack_5 & 0x80) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_4 = local_4 & 0xf0 | 1;
  }
  return local_4;
}


// ===== FUN_fff9810e @ fff9810e (172 bytes)

void FUN_fff9810e(char param_1,uint param_2)

{
  char local_d;
  undefined1 *local_c;
  
  if (param_1 == '\0') {
    local_c = &DAT_00009d09;
    local_d = PTR_DAT_00025d38[0x425];
  }
  else {
    local_c = &DAT_00009d63;
    local_d = PTR_DAT_00025d38[0x426];
  }
  if (DAT_00020b3d == '\0') {
    FUN_fff981ba(param_1,(int)local_c,local_d,param_2);
    return;
  }
  if (param_1 == DAT_00009dbd) {
    if (DAT_00009c5e != '\x01') {
      FUN_fff98258(param_1,local_c,local_d,param_2);
      return;
    }
    FUN_fff981ba(param_1,(int)local_c,local_d,param_2);
    return;
  }
  if (DAT_00009c5e != '\x01') {
    FUN_fff981ba(param_1,(int)local_c,local_d,param_2);
    return;
  }
  FUN_fff98258(param_1,local_c,local_d,param_2);
  return;
}

