// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== sdr_send_cmd @ fffb1b2b (37 bytes)

/* R_SCI5_Serial_Send(buf,len) then arm a 7-byte reply receive into 0xA2AC */

void sdr_send_cmd(undefined4 param_1,undefined2 param_2)

{
  R_SCI5_Serial_Send(param_1,param_2);
  DAT_0000a2b3 = 0;
  R_SCI5_Serial_Receive(&DAT_0000a2ac,7);
  return;
}


// ===== cat_rx_complete @ fffb1b50 (321 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb1c58) */
/* Receive-complete callback from SCI ISRs (arg1=port id, arg2=len) */

void cat_rx_complete(int param_1,ushort param_2)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  char *local_c;
  
  if (param_1 == 1) {
    local_c = &DAT_0000f62c;
  }
  else if (param_1 == 2) {
    local_c = &DAT_0000a2b4;
  }
  else {
    local_c = &DAT_0000cc70;
  }
  if ((*local_c == 'E') || (*local_c == 'e')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if ((local_c[1] == '1') || (local_c[1] == '9')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fffb1bbd;
    }
  }
  bVar1 = false;
LAB_fffb1bbd:
  if (bVar1) {
    if (DAT_0001b78c == '\0') {
      pcVar2 = &DAT_0001b790;
      pcVar3 = local_c;
      DAT_0001b78d = (char)param_1;
      DAT_0001b78e = param_2;
      for (uVar4 = (uint)param_2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar2 = *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      }
      DAT_0001b78c = '\x01';
    }
  }
  else if (param_2 < 0x67) {
    (&DAT_0001e14c)[(uint)DAT_00011fec * 0x6a] = (char)param_1;
    *(ushort *)(&DAT_0001e14e + (uint)DAT_00011fec * 0x6a) = param_2;
    pcVar2 = &DAT_0001e150 + (uint)DAT_00011fec * 0x6a;
    pcVar3 = local_c;
    for (uVar4 = (uint)param_2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    DAT_00011fec = (char)(DAT_00011fec + 1) + (char)((DAT_00011fec + 1) / 0x3c) * -0x3c;
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      R_SCI2_Serial_Receive(local_c,&DAT_000029bc);
      return;
    }
    R_SCI0_Serial_Receive(local_c,&DAT_000029bc);
    return;
  }
  R_SCI3_Serial_Receive(local_c,&DAT_000029bc);
  return;
}


// ===== cat_ring_head @ fffb1c91 (15 bytes)

/* Returns CAT ring head index 0x11FEC (60 slots of 0x6A at 0x1E14C) */

undefined1 cat_ring_head(void)

{
  return DAT_00011fec;
}


// ===== cat_ring_tail @ fffb1ca0 (15 bytes)

/* Returns CAT ring tail index 0x11FEB */

undefined1 cat_ring_tail(void)

{
  return DAT_00011feb;
}


// ===== cat_ring_unpop @ fffb1caf (35 bytes)

/* Steps the CAT ring tail back (port TX busy: retry later) */

void cat_ring_unpop(void)

{
  if (DAT_00011feb != '\0') {
    DAT_00011feb = DAT_00011feb + -1;
    return;
  }
  DAT_00011feb = 0x3b;
  return;
}


// ===== cat_ring_pop @ fffb1cd2 (52 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb1cf5) */
/* Advances the CAT ring tail (mod 60) and returns the slot pointer */

void cat_ring_pop(void)

{
  DAT_00011feb = (char)(DAT_00011feb + 1) + (char)((DAT_00011feb + 1) / 0x3c) * -0x3c;
  return;
}


// ===== cat_e9_slot @ fffb1d06 (12 bytes)

/* Returns 0x1B78C: single-slot buffer for frames starting E1/E9 (flag, port, len, data) */

void cat_e9_slot(void)

{
  return;
}


// ===== cat_send_reply @ fffb1d12 (73 bytes)

/* Send buffer on CAT port (1=SCI3, 2=SCI0, else SCI2), sets per-port busy flag */

void cat_send_reply(int param_1,undefined4 param_2,undefined2 param_3)

{
  if (param_1 == 1) {
    R_SCI3_Serial_Send(param_2,param_3);
    DAT_00011fea = 1;
    return;
  }
  if (param_1 != 2) {
    R_SCI2_Serial_Send();
    DAT_00011fe9 = 1;
    return;
  }
  R_SCI0_Serial_Send(param_2,param_3);
  DAT_00011fe8 = 1;
  return;
}


// ===== cat_tx_done_sci0 @ fffb1d5b (10 bytes)

/* 0x11FE8 = 0 */

void cat_tx_done_sci0(void)

{
  DAT_00011fe8 = 0;
  return;
}


// ===== cat_tx_done_sci2 @ fffb1d65 (10 bytes)

/* 0x11FE9 = 0 */

void cat_tx_done_sci2(void)

{
  DAT_00011fe9 = 0;
  return;
}


// ===== cat_tx_done_sci3 @ fffb1d6f (10 bytes)

/* 0x11FEA = 0 */

void cat_tx_done_sci3(void)

{
  DAT_00011fea = 0;
  return;
}


// ===== FUN_fffb1d79 @ fffb1d79 (52 bytes)

undefined1 FUN_fffb1d79(int param_1)

{
  undefined1 local_6;
  
  if (param_1 == 1) {
    local_6 = DAT_00011fea;
  }
  else if (param_1 == 2) {
    local_6 = DAT_00011fe8;
  }
  else {
    local_6 = DAT_00011fe9;
  }
  return local_6;
}


// ===== cat_rx_byte_hook @ fffb1dad (405 bytes)

/* CAT framing: ';' end, SPR/SPW/SPNW fixed lengths, E9 bulk, inter-byte timeout from CAT TOT
   setting */

void cat_rx_byte_hook(ushort *param_1,short *param_2,char *param_3,int param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  undefined2 local_1a;
  char *local_c;
  
  if ((*param_1 == 0) || (iVar6 = swtimer_expired(param_4), iVar6 != 1)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  local_c = param_3;
  if (bVar5) {
    local_c = param_3 + -(uint)*param_1;
    *local_c = *param_3;
    *param_1 = 0;
    *param_2 = 0x29bc;
  }
  if (*param_1 == 3) {
    cVar2 = local_c[-3];
    cVar3 = local_c[-2];
    cVar4 = local_c[-1];
    cVar1 = *local_c;
    toupper_inplace();
    toupper_inplace();
    toupper_inplace();
    if ((cVar2 == 'S') && (cVar3 == 'P')) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    if (bVar5) {
      if (cVar4 != 'N') {
        if (cVar4 == 'R') {
          *param_2 = 7;
          goto LAB_fffb1ea5;
        }
        if (cVar4 != 'n') {
          if (cVar4 == 'W') {
            *param_2 = 8;
          }
          goto LAB_fffb1ea5;
        }
      }
      if (cVar1 == 'W') {
        *param_2 = 9;
      }
      else {
        *param_2 = 8;
      }
    }
    else {
      if ((cVar2 == 'E') && (cVar3 == '9')) {
        bVar5 = true;
      }
      else {
        bVar5 = false;
      }
      if (bVar5) {
        *param_2 = 0x29b2;
      }
    }
  }
LAB_fffb1ea5:
  if ((*param_2 == 0x29bc) && (*local_c == ';')) {
    *param_2 = *param_1 + 1;
  }
  if (param_4 == 4) {
    cVar1 = DAT_00009aba;
    if (DAT_00009dc6 != '\0') {
      cVar1 = DAT_00020b59;
    }
  }
  else {
    cVar1 = DAT_00009abd;
    if (param_4 != 5) {
      cVar1 = DAT_00009abf;
    }
  }
  if (cVar1 == '\x01') {
    local_1a = 100;
  }
  else if (cVar1 == '\x02') {
    local_1a = 1000;
  }
  else if (cVar1 == '\x03') {
    local_1a = 3000;
  }
  else {
    local_1a = 10;
  }
  swtimer_start(param_4,local_1a);
  return;
}


// ===== sci_tx_end @ fffb1f42 (65 bytes)

/* Returns SSR.TEND for CAT port id (1=SCI3, 2=SCI0, other=SCI2) */

byte sci_tx_end(int param_1)

{
  byte bVar1;
  undefined1 local_6;
  
  if (param_1 == 1) {
    bVar1 = DAT_0008a064;
    local_6 = bVar1 >> 2 & 1;
  }
  else if (param_1 == 2) {
    bVar1 = DAT_0008a004;
    local_6 = bVar1 >> 2 & 1;
  }
  else {
    bVar1 = DAT_0008a044;
    local_6 = bVar1 >> 2 & 1;
  }
  return local_6;
}


// ===== shreg_bus_init @ fffb1f83 (108 bytes)

/* idle levels of SDAT0/SCLK0/strobes, PA_PON=1, AF_RESET pulse */

void shreg_bus_init(void)

{
  byte bVar1;
  
  pa_pon_set(1);
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xdf;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0xbf;
  bVar1 = DAT_0008c025;
  DAT_0008c025 = bVar1 & 0xbf;
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 | 0x80;
  af_reset_set(0);
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 | 1;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 0x20;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xbf;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 | 0x80;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 | 0x40;
  bVar1 = DAT_0008c020;
  DAT_0008c020 = bVar1 & 0xfb;
  bVar1 = DAT_0008c000;
  DAT_0008c000 = bVar1 | 1;
  bVar1 = DAT_0008c025;
  DAT_0008c025 = bVar1 | 0x40;
  af_reset_set(1);
  return;
}


// ===== bu2505_write @ fffb1fef (158 bytes)

/* (dev 0:Q1005 via SST1 | 4:PA Q4041 via SST5, ch, 10-bit) 14 bits LSB first */

void bu2505_write(int param_1,byte param_2,short param_3)

{
  byte bVar1;
  bool bVar2;
  byte local_9;
  ushort local_8;
  
  if ((param_1 == 0) || (param_1 == 4)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    return;
  }
  local_8 = param_2 & 0xf | param_3 << 4;
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xdf;
  for (local_9 = 0; local_9 < 0xe; local_9 = local_9 + 1) {
    if ((local_8 & 1) == 0) {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xef;
    }
    else {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 | 0x10;
    }
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 | 0x20;
    local_8 = local_8 >> 1;
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 & 0xdf;
  }
  if (param_1 == 0) {
    bVar1 = DAT_0008c026;
    DAT_0008c026 = bVar1 | 0x40;
    bVar1 = DAT_0008c026;
    DAT_0008c026 = bVar1 & 0xbf;
    return;
  }
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 | 0x40;
  bVar1 = DAT_0008c02b;
  DAT_0008c02b = bVar1 & 0xbf;
  return;
}


// ===== sst2_write12 @ fffb208d (191 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb20eb) */
/* /SST2 (P67): 12 bits MSB first, high nibble = band code */

void sst2_write12(char param_1,undefined1 param_2)

{
  byte bVar1;
  byte local_5;
  ushort local_4;
  undefined1 local_1;
  
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 & 0x7f;
  if (param_1 == '\b') {
    local_1 = 1;
  }
  else if (param_1 == '\x02') {
    local_1 = 4;
  }
  else if (param_1 == '\x03') {
    local_1 = 0xc;
  }
  else if (param_1 == '\x04') {
    local_1 = 2;
  }
  else if (param_1 == '\x05') {
    local_1 = 10;
  }
  else if (param_1 == '\x06') {
    local_1 = 6;
  }
  else if (param_1 == '\a') {
    local_1 = 0xe;
  }
  else if (param_1 == '\x01') {
    local_1 = 8;
  }
  else {
    local_1 = 0;
  }
  local_4 = CONCAT11(local_1,param_2);
  bVar1 = DAT_0008c02a;
  DAT_0008c02a = bVar1 & 0xdf;
  for (local_5 = 0; local_5 < 0xc; local_5 = local_5 + 1) {
    if ((local_4 & 0x800) == 0) {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xef;
    }
    else {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 | 0x10;
    }
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 | 0x20;
    local_4 = local_4 << 1;
    FUN_fffb2210(0);
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 & 0xdf;
  }
  bVar1 = DAT_0008c026;
  DAT_0008c026 = bVar1 | 0x80;
  FUN_fffb2210(0);
  return;
}


// ===== shreg_write24 @ fffb214c (196 bytes)

/* (dev 2:/SST3 PA0 | 3:/SST4 PB5 | 5:/SST6 PA7, 24 bits MSB first) */

void shreg_write24(int param_1,uint param_2)

{
  byte bVar1;
  bool bVar2;
  byte local_9;
  uint local_8;
  
  if ((param_1 == 2) || (param_1 == 3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((bVar2) && (param_1 != 5)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 & 0xdf;
    local_8 = param_2;
    for (local_9 = 0; local_9 < 0x18; local_9 = local_9 + 1) {
      if ((local_8 & 0x800000) == 0) {
        bVar1 = DAT_0008c02a;
        DAT_0008c02a = bVar1 & 0xef;
      }
      else {
        bVar1 = DAT_0008c02a;
        DAT_0008c02a = bVar1 | 0x10;
      }
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 | 0x20;
      local_8 = local_8 << 1;
      FUN_fffb2210(0);
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xdf;
    }
    if (param_1 == 2) {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0xfe;
    }
    else if (param_1 == 3) {
      bVar1 = DAT_0008c02b;
      DAT_0008c02b = bVar1 & 0xdf;
    }
    else {
      bVar1 = DAT_0008c02a;
      DAT_0008c02a = bVar1 & 0x7f;
    }
    FUN_fffb2210(0);
    if (param_1 != 2) {
      if (param_1 != 3) {
        bVar1 = DAT_0008c02a;
        DAT_0008c02a = bVar1 | 0x80;
        return;
      }
      bVar1 = DAT_0008c02b;
      DAT_0008c02b = bVar1 | 0x20;
      return;
    }
    bVar1 = DAT_0008c02a;
    DAT_0008c02a = bVar1 | 1;
    return;
  }
  return;
}


// ===== FUN_fffb2210 @ fffb2210 (24 bytes)

void FUN_fffb2210(uint param_1)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < param_1; local_8 = local_8 + 1) {
  }
  return;
}


// ===== timers_init @ fffb2228 (96 bytes)

/* Marks all timers expired, sets blink timers, starts TPU0 and TPU3 */

void timers_init(void)

{
  byte local_1;
  
  for (local_1 = 0; local_1 < 0x4b; local_1 = local_1 + 1) {
    (&DAT_00011fed)[local_1] = 1;
  }
  for (local_1 = 0; local_1 < 4; local_1 = local_1 + 1) {
    (&DAT_0001203a)[local_1] = 1;
  }
  blink_set(0,0x1c2,0xfa);
  blink_set(1,1000,1000);
  R_TPU0_Start();
  R_TPU3_Start();
  return;
}


// ===== swtimer_tick @ fffb2288 (242 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2303) */
/* TPU0 ISR body: 75 one-shot timers (flags 0x11FED) + 2 blink timers (0x12038) */

void swtimer_tick(void)

{
  int iVar1;
  byte local_1;
  
  for (local_1 = 0; local_1 < 0x4b; local_1 = local_1 + 1) {
    if (((&DAT_00011fed)[local_1] == '\0') &&
       (*(int *)(&DAT_00020890 + (uint)local_1 * 4) =
             *(int *)(&DAT_00020890 + (uint)local_1 * 4) + 1,
       *(uint *)(&DAT_000209bc + (uint)local_1 * 4) <=
       (*(uint *)(&DAT_00020890 + (uint)local_1 * 4) & 0xff))) {
      (&DAT_00011fed)[local_1] = 1;
    }
  }
  for (local_1 = 0; local_1 < 2; local_1 = local_1 + 1) {
    *(int *)(&DAT_00020ae8 + (uint)local_1 * 4) = *(int *)(&DAT_00020ae8 + (uint)local_1 * 4) + 1;
    iVar1 = (uint)local_1 * 8;
    if ((&DAT_00012038)[local_1] == '\0') {
      if (*(uint *)(&DAT_00020af4 + iVar1) <= (*(uint *)(&DAT_00020ae8 + (uint)local_1 * 4) & 0xff))
      {
        (&DAT_00012038)[local_1] = 1;
        *(undefined4 *)(&DAT_00020ae8 + (uint)local_1 * 4) = 0;
      }
    }
    else if (*(uint *)(&DAT_00020af0 + iVar1) <=
             (*(uint *)(&DAT_00020ae8 + (uint)local_1 * 4) & 0xff)) {
      (&DAT_00012038)[local_1] = 0;
      *(undefined4 *)(&DAT_00020ae8 + (uint)local_1 * 4) = 0;
    }
  }
  return;
}


// ===== swtimer_start @ fffb237a (58 bytes)

/* (id, ms): limit = ms*10 ticks of 0.1 ms */

void swtimer_start(int param_1,ushort param_2)

{
  if (0x4a < param_1) {
    return;
  }
  *(undefined4 *)(&DAT_00020890 + param_1 * 4) = 0;
  *(uint *)(&DAT_000209bc + param_1 * 4) = (uint)param_2 * 10;
  (&DAT_00011fed)[param_1] = 0;
  return;
}


// ===== timer_start_us @ fffb23b4 (63 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb23d3) */
/* Soft timer id: count = (us+50)/100 ticks */

void timer_start_us(int param_1,int param_2)

{
  if (param_1 < 0x4b) {
    *(undefined4 *)(&DAT_00020890 + param_1 * 4) = 0;
    *(uint *)(&DAT_000209bc + param_1 * 4) = (param_2 + 0x32U) / 100;
    (&DAT_00011fed)[param_1] = 0;
    return;
  }
  return;
}


// ===== swtimer_expired @ fffb23f3 (19 bytes)

/* returns flag 0x11FED[id] */

undefined1 swtimer_expired(int param_1)

{
  return (&DAT_00011fed)[param_1];
}


// ===== blink_phase @ fffb2406 (19 bytes)

/* returns 0x12038[id] */

undefined1 blink_phase(int param_1)

{
  return (&DAT_00012038)[param_1];
}


// ===== blink_set @ fffb2419 (80 bytes)

/* (id, on_ms, off_ms) [inference] */

void blink_set(int param_1,ushort param_2,ushort param_3)

{
  if (1 < param_1) {
    return;
  }
  *(undefined4 *)(&DAT_00020ae8 + param_1 * 4) = 0;
  *(uint *)(&DAT_00020af0 + param_1 * 8) = (uint)param_2 * 10;
  *(uint *)(&DAT_00020af4 + param_1 * 8) = (uint)param_3 * 10;
  (&DAT_00012038)[param_1] = 0;
  return;
}


// ===== tone_sample_isr @ fffb2469 (58 bytes)

/* TPU1 ISR body: next sample of the table at *0x20B00 -> DADR0 */

void tone_sample_isr(void)

{
  DAT_0001fa36 = DAT_0001fa36 + 1;
  if (DAT_0001fa34 <= DAT_0001fa36) {
    DAT_0001fa36 = 0;
  }
  dac0_write(*(undefined2 *)(DAT_00020b00 + (uint)DAT_0001fa36 * 2));
  return;
}


// ===== tone_play @ fffb24a3 (39 bytes)

/* (table, n): start TPU1 playback */

void tone_play(undefined4 param_1,undefined2 param_2)

{
  DAT_0001fa36 = 0;
  DAT_0001fa34 = param_2;
  DAT_00020b00 = param_1;
  R_TPU1_Start();
  return;
}


// ===== tone_stop @ fffb24ca (14 bytes)

/* [inference] */

void tone_stop(void)

{
  R_TPU1_Stop();
  DAT_00012003 = 1;
  return;
}


// ===== spk_softstart_isr @ fffb24d8 (196 bytes)

/* TPU2 ISR body: pulses the selected speaker switch with a shrinking duty cycle [inference: pop
   suppression] */

void spk_softstart_isr(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = swtimer_expired(0x2d);
  if (iVar2 != 0) {
    speaker_switch_set(1);
    R_TPU2_Stop();
    DAT_0001b3df = 9;
    DAT_0001b3e0 = 0;
    DAT_0001b3e1 = 0;
    return;
  }
  DAT_0001b3e0 = DAT_0001b3e0 + 1;
  if (DAT_0001b3e0 == 1) {
    speaker_switch_set(1);
    bVar1 = false;
    while (!bVar1) {
      bVar1 = true;
    }
    speaker_switch_set(0);
  }
  if (DAT_0001b3df <= DAT_0001b3e0) {
    DAT_0001b3e0 = 0;
    DAT_0001b3e1 = DAT_0001b3e1 + 1;
    if (10 < DAT_0001b3e1) {
      DAT_0001b3e1 = 0;
      if (DAT_0001b3df != 0) {
        DAT_0001b3df = DAT_0001b3df - 1;
        return;
      }
      return;
    }
  }
  return;
}


// ===== slowtimer_tick @ fffb259c (104 bytes)

/* TPU3 ISR body: 4 timers in 100 ms units (flags 0x1203A) */

void slowtimer_tick(void)

{
  byte local_1;
  
  for (local_1 = 0; local_1 < 4; local_1 = local_1 + 1) {
    if ((((&DAT_0001203a)[local_1] == '\0') && (*(short *)(&DAT_0001fa2c + (uint)local_1 * 2) != 0))
       && (*(short *)(&DAT_0001fa24 + (uint)local_1 * 2) =
                *(short *)(&DAT_0001fa24 + (uint)local_1 * 2) + 1,
          *(ushort *)(&DAT_0001fa2c + (uint)local_1 * 2) <=
          (*(ushort *)(&DAT_0001fa24 + (uint)local_1 * 2) & 0xff))) {
      (&DAT_0001203a)[local_1] = 1;
    }
  }
  return;
}


// ===== FUN_fffb2604 @ fffb2604 (57 bytes)

void FUN_fffb2604(int param_1,short param_2)

{
  if (3 < param_1) {
    return;
  }
  *(undefined2 *)(&DAT_0001fa24 + param_1 * 2) = 0;
  *(short *)(&DAT_0001fa2c + param_1 * 2) = param_2 * 10;
  (&DAT_0001203a)[param_1] = 0;
  return;
}


// ===== cat_apo_reset @ fffb263d (66 bytes)

/* Restarts the auto-power-off timer from setting 0x9B0F (called per received command) */

void cat_apo_reset(void)

{
  undefined1 local_3;
  undefined2 local_2;
  
  local_2 = 0;
  local_3 = DAT_00009b0f;
  if (3 < DAT_00009b0f) {
    local_3 = 3;
  }
  if (local_3 == 3) {
    local_2 = 0xe10;
  }
  else if (local_3 == 2) {
    local_2 = 0x708;
  }
  else if (local_3 == 1) {
    local_2 = 900;
  }
  FUN_fffb2604(0,local_2);
  return;
}


// ===== FUN_fffb267f @ fffb267f (15 bytes)

undefined1 FUN_fffb267f(void)

{
  return DAT_0001203a;
}


// ===== tot_start @ fffb268e (49 bytes)

/* TX time-out timer from setting 0x9AC3 (minutes) [inference for units] */

void tot_start(void)

{
  short sVar1;
  
  if (DAT_00009ac3 == 0) {
    return;
  }
  sVar1 = (ushort)DAT_00009ac3 * 0x3c;
  FUN_fffb2604(1,sVar1);
  FUN_fffb2604(2,sVar1 + -10);
  return;
}


// ===== tot_expired @ fffb26bf (38 bytes)

undefined1 tot_expired(void)

{
  undefined1 local_2;
  
  if (DAT_00009ac3 == '\0') {
    local_2 = 0;
  }
  else {
    local_2 = DAT_0001203b;
  }
  return local_2;
}


// ===== tot_prewarn @ fffb26e5 (51 bytes)

char tot_prewarn(void)

{
  undefined1 local_2;
  
  if (DAT_00009ac3 == '\0') {
    local_2 = '\0';
  }
  else {
    local_2 = DAT_0001203c;
    if (DAT_0001203c == '\x01') {
      FUN_fffb2604(2,0);
    }
  }
  return local_2;
}


// ===== cat_rand8 @ fffb2718 (28 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2723) */
/* Pseudo-random byte from timer counter 0x88116 (E8 obfuscation key) */

char cat_rand8(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00088116;
  return (char)uVar1 + (char)(uVar1 / 0xff);
}


// ===== R_TPU3_Create @ fffb2734 (126 bytes)

/* TPU3 PCLKB/256, TGRA=23437: 100 ms tick, vec142 */

void R_TPU3_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xffffdfff;
  bVar2 = DAT_00088100;
  DAT_00088100 = bVar2 & 0xf7;
  DAT_0008778e = 0x1c;
  bVar2 = DAT_0008738e;
  DAT_0008738e = bVar2 & 0xf2 | 2;
  bVar2 = DAT_00088101;
  DAT_00088101 = bVar2 & 0xf7;
  DAT_00088140 = 0x2e;
  bVar2 = DAT_00088144;
  DAT_00088144 = bVar2 | 0x41;
  DAT_00088142 = 0;
  DAT_00088143 = 0;
  DAT_00088148 = 0x5b8d;
  DAT_0008814a = 0x16;
  DAT_0008814c = 0x16;
  DAT_0008814e = 0x16;
  FUN_fffb27d0();
  return;
}


// ===== R_TPU3_Start @ fffb27b2 (15 bytes)

/* Enable vector 142 and TSTR bit 3 */

void R_TPU3_Start(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087211;
  DAT_00087211 = bVar1 | 0x40;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 | 8;
  return;
}


// ===== FUN_fffb27d0 @ fffb27d0 (1 bytes)

void FUN_fffb27d0(void)

{
  return;
}


// ===== r_tpu3_tgia_isr @ fffb27d1 (14 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb27d9) */
/* WARNING: Removing unreachable block (ram,0xfffb27d1) */
/* WARNING: Removing unreachable block (ram,0xfffb27d3) */
/* WARNING: Removing unreachable block (ram,0xfffb27db) */
/* vec142 -> slowtimer_tick */

undefined4 r_tpu3_tgia_isr(undefined4 param_1)

{
  slowtimer_tick();
  return param_1;
}


// ===== FUN_fffb27df @ fffb27df (1 bytes)

void FUN_fffb27df(void)

{
  return;
}


// ===== adc_scan_start @ fffb27e0 (27 bytes)

/* start both units */

void adc_scan_start(void)

{
  DAT_0001203e = 0;
  DAT_0001203f = 0;
  R_S12AD0_Start();
  R_S12AD1_Start();
  return;
}


// ===== adc0_store @ fffb27fb (83 bytes)

/* AN001->0x20B04 AN002->0x20B06 AN003->0x20B08 AN005->0x20B0C AN006->0x20B0A AN007->0x20B0E */

void adc0_store(void)

{
  R_S12AD0_Get_ValueResult(1,&DAT_00020b04);
  R_S12AD0_Get_ValueResult(2,&DAT_00020b06);
  R_S12AD0_Get_ValueResult(3,&DAT_00020b08);
  R_S12AD0_Get_ValueResult(5,&DAT_00020b0c);
  R_S12AD0_Get_ValueResult(6,&DAT_00020b0a);
  R_S12AD0_Get_ValueResult(7,&DAT_00020b0e);
  return;
}


// ===== adc0_done @ fffb284e (10 bytes)

void adc0_done(void)

{
  DAT_0001203e = 1;
  return;
}


// ===== adc1_store @ fffb2858 (60 bytes)

/* AN108->0x20B10 AN109->0x20B12 AN115->0x20B14 AN117->0x20B16 */

void adc1_store(void)

{
  R_S12AD1_Get_ValueResult(8,&DAT_00020b10);
  R_S12AD1_Get_ValueResult(9,&DAT_00020b12);
  R_S12AD1_Get_ValueResult(0xf,&DAT_00020b14);
  R_S12AD1_Get_ValueResult(0x11,&DAT_00020b16);
  return;
}


// ===== adc1_done @ fffb2894 (10 bytes)

void adc1_done(void)

{
  DAT_0001203f = 1;
  return;
}


// ===== adc_scan_done @ fffb289e (51 bytes)

undefined1 adc_scan_done(void)

{
  undefined1 uVar1;
  
  if ((DAT_0001203e == '\x01') && (DAT_0001203f == '\x01')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== dac_init_idle @ fffb28d1 (17 bytes)

/* DADR0 = table[0]; DA0 output on */

void dac_init_idle(void)

{
  dac0_write(DAT_0001ff1c);
  R_DA0_Start();
  return;
}

