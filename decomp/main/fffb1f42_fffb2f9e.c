// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

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

void sst2_write12(char param_1,byte param_2)

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
       *(uint *)(&DAT_000209bc + (uint)local_1 * 4) <= *(uint *)(&DAT_00020890 + (uint)local_1 * 4))
       ) {
      (&DAT_00011fed)[local_1] = 1;
    }
  }
  for (local_1 = 0; local_1 < 2; local_1 = local_1 + 1) {
    *(int *)(&DAT_00020ae8 + (uint)local_1 * 4) = *(int *)(&DAT_00020ae8 + (uint)local_1 * 4) + 1;
    iVar1 = (uint)local_1 * 8;
    if ((&DAT_00012038)[local_1] == '\0') {
      if (*(uint *)(&DAT_00020af4 + iVar1) <= *(uint *)(&DAT_00020ae8 + (uint)local_1 * 4)) {
        (&DAT_00012038)[local_1] = 1;
        *(undefined4 *)(&DAT_00020ae8 + (uint)local_1 * 4) = 0;
      }
    }
    else if (*(uint *)(&DAT_00020af0 + iVar1) <= *(uint *)(&DAT_00020ae8 + (uint)local_1 * 4)) {
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

byte swtimer_expired(int param_1)

{
  return (&DAT_00011fed)[param_1];
}


// ===== blink_phase @ fffb2406 (19 bytes)

/* returns 0x12038[id] */

byte blink_phase(int param_1)

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
  dac0_write(*(ushort *)(DAT_00020b00 + (uint)DAT_0001fa36 * 2));
  return;
}


// ===== tone_play @ fffb24a3 (39 bytes)

/* (table, n): start TPU1 playback */

void tone_play(uint param_1,ushort param_2)

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
  byte bVar2;
  
  bVar2 = swtimer_expired(0x2d);
  if (bVar2 != 0) {
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
          *(ushort *)(&DAT_0001fa24 + (uint)local_1 * 2))) {
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

byte tot_expired(void)

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


// ===== FUN_fffb27c1 @ fffb27c1 (15 bytes)

void FUN_fffb27c1(void)

{
  byte bVar1;
  
  bVar1 = DAT_00087211;
  DAT_00087211 = bVar1 & 0xbf;
  bVar1 = DAT_00088100;
  DAT_00088100 = bVar1 & 0xf7;
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

void r_tpu3_tgia_isr(void)

{
  slowtimer_tick();
  return;
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

byte adc_scan_done(void)

{
  byte bVar1;
  
  if ((DAT_0001203e == '\x01') && (DAT_0001203f == '\x01')) {
    bVar1 = 1;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}


// ===== dac_init_idle @ fffb28d1 (17 bytes)

/* DADR0 = table[0]; DA0 output on */

void dac_init_idle(void)

{
  dac0_write(DAT_0001ff1c);
  R_DA0_Start();
  return;
}


// ===== beep_task @ fffb28e2 (1220 bytes)

/* main loop: plays beep pattern 0x12041 (880 Hz / 1046.5 Hz) */

void beep_task(void)

{
  byte bVar1;
  float fVar2;
  float fStack_4;
  
  if (DAT_00012040 == '\x01') {
    tone_idle();
    DAT_0001b3e2 = 0;
    DAT_00012040 = 2;
    return;
  }
  if (DAT_00012040 == '\x02') {
    bVar1 = swtimer_expired(0x16);
    if (bVar1 == 1) {
      switch(DAT_00012041) {
      case 1:
        if (DAT_0001b3e2 == '\0') {
          tone_set(880.0,100);
          DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        }
        else {
          beep_stop();
        }
        break;
      case 2:
        if (DAT_0001b3e2 == '\x02') {
          tone_set(880.0,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0.0,10);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(880.0,100);
        }
        else {
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 3:
        if (DAT_0001b3e2 == '\x04') {
          tone_set(1046.502,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0.0,100);
        }
        else if (DAT_0001b3e2 == '\x02') {
          tone_set(1046.502,100);
        }
        else if (DAT_0001b3e2 == '\x03') {
          tone_set(0.0,100);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(1046.502,100);
        }
        else {
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 4:
        fVar2 = (float)DAT_00009c04 * 10.0 + 300.0;
        if (DAT_00025d40 == fVar2) {
          swtimer_start(0x16,100);
        }
        else {
          DAT_00025d40 = fVar2;
          tone_set(fVar2,100);
        }
        break;
      case 5:
        if (DAT_0001b3e2 == '\x04') {
          tone_set(1567.982,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0.0,10);
        }
        else if (DAT_0001b3e2 == '\x02') {
          tone_set(1318.51,100);
        }
        else if (DAT_0001b3e2 == '\x03') {
          tone_set(0.0,10);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(1046.502,100);
        }
        else {
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 6:
        if (DAT_0001b3e2 == '\x02') {
          tone_set(659.255,100);
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0.0,10);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(783.991,100);
        }
        else {
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 7:
        switch(DAT_0001b3e2) {
        case '\0':
          tone_set(1318.51,100);
          break;
        case '\x01':
          tone_set(0.0,0x28);
          break;
        case '\x02':
          tone_set(1318.51,100);
          break;
        case '\x03':
          tone_set(0.0,0x14);
          break;
        case '\x04':
          tone_set(1318.51,100);
          break;
        case '\x05':
          tone_set(0.0,0x14);
          break;
        case '\x06':
          tone_set(1318.51,100);
          break;
        case '\a':
          tone_set(0.0,0x14);
          break;
        case '\b':
          tone_set(1318.51,100);
          break;
        default:
          beep_stop();
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 8:
        if (DAT_0001b3e2 == '\x05') {
          tone_idle();
        }
        else if (DAT_0001b3e2 == '\x01') {
          tone_set(0.0,0x46);
        }
        else if (DAT_0001b3e2 == '\x02') {
          tone_set(1046.502,100);
        }
        else if (DAT_0001b3e2 == '\x03') {
          tone_set(0.0,0x46);
        }
        else if (DAT_0001b3e2 == '\x04') {
          tone_set(1046.502,100);
        }
        else if (DAT_0001b3e2 == '\0') {
          tone_set(1046.502,100);
        }
        else {
          beep_stop();
          DAT_00020f4b = 1;
        }
        DAT_0001b3e2 = DAT_0001b3e2 + '\x01';
        break;
      case 9:
        if (DAT_0001b3e3 == '\t') {
          swtimer_start(0x16,0xffff);
        }
        else {
          if (DAT_00009a8c == '\0') {
            fStack_4 = 1275.0;
          }
          else {
            fStack_4 = 2125.0;
          }
          tone_set(fStack_4,0xffff);
        }
        break;
      case 10:
        if (DAT_0001b3e3 == '\n') {
          swtimer_start(0x16,0xffff);
        }
        else {
          if (DAT_00009a8d == '\x01') {
            fStack_4 = 200.0;
          }
          else if (DAT_00009a8d == '\x02') {
            fStack_4 = 425.0;
          }
          else if (DAT_00009a8d == '\x03') {
            fStack_4 = 850.0;
          }
          else {
            fStack_4 = 170.0;
          }
          tone_set(fStack_4,0xffff);
        }
        break;
      case 0xb:
        if (DAT_0001b3e3 == '\v') {
          swtimer_start(0x16,0xffff);
        }
        else {
          if (DAT_00009a8c == '\0') {
            fStack_4 = 1275.0;
          }
          else {
            fStack_4 = 2125.0;
          }
          if (DAT_00009a8d == '\x01') {
            fStack_4 = fStack_4 + 200.0;
          }
          else if (DAT_00009a8d == '\x02') {
            fStack_4 = fStack_4 + 425.0;
          }
          else if (DAT_00009a8d == '\x03') {
            fStack_4 = fStack_4 + 850.0;
          }
          else {
            fStack_4 = fStack_4 + 170.0;
          }
          tone_set(fStack_4,0xffff);
        }
        break;
      default:
        beep_stop();
      }
      DAT_0001b3e3 = DAT_00012041;
      return;
    }
  }
  else if (DAT_00012040 == '\x03') {
    tone_idle();
    DAT_00012040 = 0;
    DAT_00012041 = 0;
    DAT_00025d40 = 0.0;
    DAT_0001b3e3 = 0;
    return;
  }
  return;
}


// ===== beep_request @ fffb2da6 (78 bytes)

/* (pattern) */

void beep_request(int param_1)

{
  if (param_1 != 8) {
    if (param_1 - 9U < 3) {
      if (DAT_00012041 == '\x04') {
        return;
      }
    }
    else if (DAT_00012041 != '\0') {
      return;
    }
  }
  DAT_00012041 = (char)param_1;
  DAT_00012040 = 1;
  return;
}


// ===== beep_stop @ fffb2df4 (10 bytes)

void beep_stop(void)

{
  DAT_00012040 = 3;
  return;
}


// ===== FUN_fffb2dfe @ fffb2dfe (15 bytes)

byte FUN_fffb2dfe(void)

{
  return DAT_00012041;
}


// ===== tone_idle @ fffb2e0d (17 bytes)

void tone_idle(void)

{
  tone_stop();
  dac0_write(DAT_0001ff1c);
  return;
}


// ===== tone_set @ fffb2e1e (126 bytes)

/* (freq_Hz float, ms): TPU1 TGRA = 60e6/(36*f)-1, 36-sample table 0x1FF1C */

void tone_set(float param_1,ushort param_2)

{
  bool bVar1;
  
  if (param_1 - 0.0 != 0.0) {
    if ((param_1 - 30.0 < 0.0) || (20000.0 < param_1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      return;
    }
    DAT_00088128 = SUB42(ROUND(1.0 / ((param_1 * 36.0) / 6e+07) + -1.0),0);
    tone_play(0x1ff1c,0x24);
  }
  swtimer_start(0x16,param_2);
  return;
}


// ===== nib2hex @ fffb2e9c (27 bytes)

/* Nibble -> ASCII hex digit */

char nib2hex(byte n)

{
  return "@0123456789ABCDEF"[(n & 0xf) + 1];
}


// ===== byte2hex @ fffb2eb7 (48 bytes)

/* Byte -> 2 ASCII hex chars */

void byte2hex(char *param_1,byte param_2)

{
  *param_1 = "@0123456789ABCDEF"[(param_2 >> 4) + 1];
  param_1[1] = "@0123456789ABCDEF"[(param_2 & 0xf) + 1];
  return;
}


// ===== word2hex @ fffb2ee7 (32 bytes)

/* u16 -> 4 ASCII hex chars */

void word2hex(int param_1,ushort param_2)

{
  byte2hex((char *)param_1,(byte)(param_2 >> 8));
  byte2hex((char *)(param_1 + 2),(byte)param_2);
  return;
}


// ===== hex2nib @ fffb2f07 (114 bytes)

/* ASCII hex digit -> value (0xFF if invalid) */

char hex2nib(byte param_1)

{
  bool bVar1;
  char local_3;
  
  local_3 = -1;
  if ((param_1 < 0x30) || (0x39 < param_1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    local_3 = param_1 - 0x30;
  }
  else {
    if ((param_1 < 0x41) || (0x46 < param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_3 = param_1 - 0x37;
    }
    else {
      if ((param_1 < 0x61) || (0x66 < param_1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        local_3 = param_1 + 0xa9;
      }
    }
  }
  return local_3;
}


// ===== hex2byte @ fffb2f79 (37 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2f86) */
/* 2 ASCII hex chars -> byte */

byte hex2byte(char *s)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = hex2nib(*s);
  bVar2 = hex2nib(s[1]);
  return bVar2 | cVar1 << 4;
}


// ===== hex2word @ fffb2f9e (34 bytes)

/* WARNING: Removing unreachable block (ram,0xfffb2fa9) */
/* 4 ASCII hex chars -> u16 */

ushort hex2word(char *s)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = hex2byte(s);
  bVar2 = hex2byte(s + 2);
  return CONCAT11(bVar1,bVar2);
}

