// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== R_DA0_Start @ fff92826 (15 bytes)

/* DACR.DAOE0=1 */

void R_DA0_Start(void)

{
  byte bVar1;
  
  bVar1 = DAT_00088044;
  DAT_00088044 = bVar1 & 0xdf;
  bVar1 = DAT_00088044;
  DAT_00088044 = bVar1 | 0x40;
  return;
}


// ===== FUN_fff92835 @ fff92835 (8 bytes)

void FUN_fff92835(void)

{
  byte bVar1;
  
  bVar1 = DAT_00088044;
  DAT_00088044 = bVar1 & 0xbf;
  return;
}


// ===== dac0_write @ fff9283d (19 bytes)

/* DADR0 = v & 0xFFF */

void dac0_write(ushort param_1)

{
  DAT_00088040 = param_1 & 0xfff;
  return;
}


// ===== FUN_fff92850 @ fff92850 (1 bytes)

void FUN_fff92850(void)

{
  return;
}


// ===== R_S12AD0_Create @ fff92851 (422 bytes)

/* Unit 0: AN001 AN002 AN003 AN005 AN006 AN007, 4x average on AN003/5/6/7, scan-end IRQ vec186 */

void R_S12AD0_Create(void)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xfffdffff;
  uVar3 = DAT_00089000;
  DAT_00089000 = uVar3 & 0xefff;
  uVar3 = DAT_00089090;
  DAT_00089090 = uVar3 & 0x7fff;
  uVar3 = DAT_00089090;
  DAT_00089090 = uVar3 & 0xdfff;
  bVar2 = DAT_00087217;
  DAT_00087217 = bVar2 & 0xfb;
  DAT_00089000 = 0;
  DAT_0008907a = 0;
  DAT_000890e1 = 0xb;
  DAT_000890e2 = 0xb;
  DAT_000890e3 = 0xb;
  DAT_000890e5 = 0xb;
  DAT_000890e6 = 0xb;
  DAT_000890e7 = 0xb;
  DAT_00089004 = 0xee;
  DAT_00089008 = 0xe8;
  DAT_00089066 = 0x618;
  DAT_0008900e = 0;
  uVar3 = DAT_00089000;
  DAT_00089000 = uVar3 | 0x1000;
  DAT_0008900c = 0x83;
  DAT_00089090 = 0;
  DAT_000877ba = 0x40;
  bVar2 = DAT_000873ba;
  DAT_000873ba = bVar2 & 0xf6 | 6;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xfd;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xfd;
  DAT_0008c161 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xfb;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xfb;
  DAT_0008c162 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xf7;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xf7;
  DAT_0008c163 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xdf;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xdf;
  DAT_0008c165 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0xbf;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0xbf;
  DAT_0008c166 = 0x80;
  bVar2 = DAT_0008c064;
  DAT_0008c064 = bVar2 & 0x7f;
  bVar2 = DAT_0008c004;
  DAT_0008c004 = bVar2 & 0x7f;
  DAT_0008c167 = 0x80;
  FUN_fff92b00();
  return;
}


// ===== R_S12AD0_Start @ fff929f7 (28 bytes)

/* ADCSR.ADST=1 */

void R_S12AD0_Start(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = DAT_000870ba;
  DAT_000870ba = bVar1 & 0xfe;
  bVar1 = DAT_00087217;
  DAT_00087217 = bVar1 | 4;
  uVar2 = DAT_00089000;
  DAT_00089000 = uVar2 | 0x8000;
  return;
}


// ===== R_S12AD0_Stop @ fff92a13 (30 bytes)

void R_S12AD0_Stop(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = DAT_00089000;
  DAT_00089000 = uVar2 & 0x7fff;
  bVar1 = DAT_000870ba;
  DAT_000870ba = bVar1 & 0xfe;
  bVar1 = DAT_00087217;
  DAT_00087217 = bVar1 & 0xfb;
  return;
}


// ===== R_S12AD0_Get_ValueResult @ fff92a31 (207 bytes)

/* (channel, *dst) */

void R_S12AD0_Get_ValueResult(int param_1,void *param_2)

{
  undefined2 uVar1;
  
  if (param_1 == 0) {
    uVar1 = DAT_00089020;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 1) {
    uVar1 = DAT_00089022;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 2) {
    uVar1 = DAT_00089024;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 3) {
    uVar1 = DAT_00089026;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 4) {
    uVar1 = DAT_00089028;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 5) {
    uVar1 = DAT_0008902a;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 6) {
    uVar1 = DAT_0008902c;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 7) {
    uVar1 = DAT_0008902e;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 0x1a) {
    uVar1 = DAT_00089086;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 0x18) {
    uVar1 = DAT_00089018;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 0x19) {
    uVar1 = DAT_00089084;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 != 0x15) {
    return;
  }
  uVar1 = DAT_0008901e;
  *(undefined2 *)param_2 = uVar1;
  return;
}


// ===== FUN_fff92b00 @ fff92b00 (1 bytes)

void FUN_fff92b00(void)

{
  return;
}


// ===== r_s12ad0_scan_end_isr @ fff92b01 (22 bytes)

/* WARNING: Removing unreachable block (ram,0xfff92b11) */
/* WARNING: Removing unreachable block (ram,0xfff92b01) */
/* WARNING: Removing unreachable block (ram,0xfff92b03) */
/* WARNING: Removing unreachable block (ram,0xfff92b13) */
/* vec186: stop unit 0, copy results to 0x20B04.., set 0x1203E */

void r_s12ad0_scan_end_isr(void)

{
  R_S12AD0_Stop();
  adc0_store();
  adc0_done();
  return;
}


// ===== R_S12AD1_Create @ fff92b17 (349 bytes)

/* Unit 1: AN108 AN109 AN115 AN117, 4x average, scan-end IRQ vec189 */

void R_S12AD1_Create(void)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xfffeffff;
  uVar3 = DAT_00089100;
  DAT_00089100 = uVar3 & 0xefff;
  uVar3 = DAT_00089190;
  DAT_00089190 = uVar3 & 0x7fff;
  uVar3 = DAT_00089190;
  DAT_00089190 = uVar3 & 0xdfff;
  bVar2 = DAT_00087217;
  DAT_00087217 = bVar2 & 0xdf;
  DAT_0008917a = 0;
  DAT_00089100 = 0x5000;
  DAT_0008910e = 0;
  DAT_0008910c = 0x83;
  DAT_00089104 = 0x8300;
  DAT_00089106 = 2;
  DAT_00089108 = 0x8300;
  DAT_0008910a = 2;
  DAT_000891e8 = 0xb;
  DAT_000891e9 = 0xb;
  DAT_000891ef = 0xb;
  DAT_000891dd = 0xb;
  DAT_00089190 = 0;
  DAT_000877bd = 0x44;
  bVar2 = DAT_000873bd;
  DAT_000873bd = bVar2 & 0xf6 | 6;
  bVar2 = DAT_0008c06d;
  DAT_0008c06d = bVar2 & 0xfe;
  bVar2 = DAT_0008c00d;
  DAT_0008c00d = bVar2 & 0xfe;
  DAT_0008c1a8 = 0x80;
  bVar2 = DAT_0008c06d;
  DAT_0008c06d = bVar2 & 0xfd;
  bVar2 = DAT_0008c00d;
  DAT_0008c00d = bVar2 & 0xfd;
  DAT_0008c1a9 = 0x80;
  bVar2 = DAT_0008c069;
  DAT_0008c069 = bVar2 & 0xfd;
  bVar2 = DAT_0008c009;
  DAT_0008c009 = bVar2 & 0xfd;
  DAT_0008c189 = 0x80;
  bVar2 = DAT_0008c069;
  DAT_0008c069 = bVar2 & 0xf7;
  bVar2 = DAT_0008c009;
  DAT_0008c009 = bVar2 & 0xf7;
  DAT_0008c18b = 0x80;
  FUN_fff92e0e();
  return;
}


// ===== R_S12AD1_Start @ fff92c74 (28 bytes)

void R_S12AD1_Start(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = DAT_000870bd;
  DAT_000870bd = bVar1 & 0xfe;
  bVar1 = DAT_00087217;
  DAT_00087217 = bVar1 | 0x20;
  uVar2 = DAT_00089100;
  DAT_00089100 = uVar2 | 0x8000;
  return;
}


// ===== R_S12AD1_Stop @ fff92c90 (30 bytes)

void R_S12AD1_Stop(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = DAT_00089100;
  DAT_00089100 = uVar2 & 0x7fff;
  bVar1 = DAT_00087217;
  DAT_00087217 = bVar1 & 0xdf;
  bVar1 = DAT_000870bd;
  DAT_000870bd = bVar1 & 0xfe;
  return;
}


// ===== R_S12AD1_Get_ValueResult @ fff92cae (352 bytes)

/* (channel, *dst) */

void R_S12AD1_Get_ValueResult(uint param_1,void *param_2)

{
  undefined2 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = DAT_00089120;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 1:
    uVar1 = DAT_00089122;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 2:
    uVar1 = DAT_00089124;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 3:
    uVar1 = DAT_00089126;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 4:
    uVar1 = DAT_00089128;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 5:
    uVar1 = DAT_0008912a;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 6:
    uVar1 = DAT_0008912c;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 7:
    uVar1 = DAT_0008912e;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 8:
    uVar1 = DAT_00089130;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 9:
    uVar1 = DAT_00089132;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 10:
    uVar1 = DAT_00089134;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xb:
    uVar1 = DAT_00089136;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xc:
    uVar1 = DAT_00089138;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xd:
    uVar1 = DAT_0008913a;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xe:
    uVar1 = DAT_0008913c;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xf:
    uVar1 = DAT_0008913e;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x10:
    uVar1 = DAT_00089140;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x11:
    uVar1 = DAT_00089142;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x12:
    uVar1 = DAT_00089144;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x13:
    uVar1 = DAT_00089146;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x14:
    uVar1 = DAT_00089148;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x15:
    uVar1 = DAT_0008911e;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x16:
    uVar1 = DAT_0008911a;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x17:
    uVar1 = DAT_0008911c;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x18:
    uVar1 = DAT_00089118;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x19:
    uVar1 = DAT_00089184;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x1a:
    uVar1 = DAT_00089186;
    *(undefined2 *)param_2 = uVar1;
    return;
  default:
    return;
  }
}


// ===== FUN_fff92e0e @ fff92e0e (1 bytes)

void FUN_fff92e0e(void)

{
  return;
}


// ===== r_s12ad1_scan_end_isr @ fff92e0f (22 bytes)

/* WARNING: Removing unreachable block (ram,0xfff92e1f) */
/* WARNING: Removing unreachable block (ram,0xfff92e0f) */
/* WARNING: Removing unreachable block (ram,0xfff92e11) */
/* WARNING: Removing unreachable block (ram,0xfff92e21) */
/* vec189: stop unit 1, copy results to 0x20B10.., set 0x1203F */

void r_s12ad1_scan_end_isr(void)

{
  R_S12AD1_Stop();
  adc1_store();
  adc1_done();
  return;
}


// ===== FUN_fff92e25 @ fff92e25 (35 bytes)

void FUN_fff92e25(void)

{
  byte bVar1;
  
  DAT_00087208 = 0;
  DAT_00087209 = 0;
  bVar1 = DAT_00087203;
  DAT_00087203 = bVar1 & 0xf7;
  bVar1 = DAT_00087203;
  DAT_00087203 = bVar1 & 0xfb;
  FUN_fff92e48();
  return;
}


// ===== FUN_fff92e48 @ fff92e48 (1 bytes)

void FUN_fff92e48(void)

{
  return;
}


// ===== R_Pins_Create @ fff92e49 (981 bytes)

/* Port init: PDR/PODR/PCR/DSCR/ODR for P0..PJ (see docs/code/main/peripherals.md GPIO map) */

void R_Pins_Create(void)

{
  DAT_0008c080 = 0;
  DAT_0008c0c0 = 0xa4;
  DAT_0008c0e0 = 0;
  DAT_0008c128 = 0;
  DAT_0008c060 = 0;
  DAT_0008c000 = 0x50;
  DAT_0008c082 = 0;
  DAT_0008c0c1 = 0;
  DAT_0008c0e1 = 0;
  DAT_0008c129 = 0;
  DAT_0008c061 = 0;
  DAT_0008c001 = 3;
  DAT_0008c022 = 0;
  DAT_0008c084 = 0;
  DAT_0008c085 = 0;
  DAT_0008c0c2 = 3;
  DAT_0008c0e2 = 0xc;
  DAT_0008c12a = 0;
  DAT_0008c062 = 0;
  DAT_0008c002 = 0x14;
  DAT_0008c086 = 0;
  DAT_0008c087 = 0;
  DAT_0008c0c3 = 0x12;
  DAT_0008c12b = 0;
  DAT_0008c063 = 0;
  DAT_0008c003 = 0;
  DAT_0008c088 = 0;
  DAT_0008c089 = 0;
  DAT_0008c0c4 = 0x11;
  DAT_0008c064 = 0;
  DAT_0008c004 = 0;
  DAT_0008c025 = 0;
  DAT_0008c08b = 0;
  DAT_0008c0c5 = 0x1e;
  DAT_0008c0e5 = 0;
  DAT_0008c12d = 0;
  DAT_0008c065 = 0;
  DAT_0008c005 = 0xc0;
  DAT_0008c026 = 0;
  DAT_0008c08c = 0;
  DAT_0008c08d = 0;
  DAT_0008c0c6 = 0x17;
  DAT_0008c066 = 0;
  DAT_0008c006 = 0xe8;
  DAT_0008c027 = 0x40;
  DAT_0008c08e = 4;
  DAT_0008c08f = 0;
  DAT_0008c0c7 = 0;
  DAT_0008c0e7 = 9;
  DAT_0008c12f = 0;
  DAT_0008c067 = 0;
  DAT_0008c007 = 0xdf;
  DAT_0008c028 = 0x40;
  DAT_0008c090 = 0;
  DAT_0008c091 = 0;
  DAT_0008c0c8 = 0;
  DAT_0008c0e8 = 0;
  DAT_0008c130 = 0;
  DAT_0008c068 = 0;
  DAT_0008c008 = 0x7f;
  DAT_0008c092 = 0;
  DAT_0008c0e9 = 0;
  DAT_0008c131 = 0;
  DAT_0008c02a = 0;
  DAT_0008c094 = 0;
  DAT_0008c095 = 0;
  DAT_0008c0ca = 8;
  DAT_0008c0ea = 0;
  DAT_0008c132 = 0;
  DAT_0008c06a = 0;
  DAT_0008c00a = 0xf7;
  DAT_0008c02b = 0;
  DAT_0008c096 = 0;
  DAT_0008c097 = 0;
  DAT_0008c0eb = 0;
  DAT_0008c133 = 0;
  DAT_0008c06b = 0;
  DAT_0008c00b = 0xfc;
  DAT_0008c02c = 0x10;
  DAT_0008c098 = 0;
  DAT_0008c099 = 0;
  DAT_0008c0cc = 2;
  DAT_0008c0ec = 0;
  DAT_0008c134 = 0;
  DAT_0008c06c = 0;
  DAT_0008c00c = 0x11;
  DAT_0008c02d = 0;
  DAT_0008c09a = 0;
  DAT_0008c09b = 0;
  DAT_0008c0ed = 0;
  DAT_0008c135 = 0;
  DAT_0008c06d = 0;
  DAT_0008c00d = 0xfc;
  DAT_0008c02e = 0;
  DAT_0008c09c = 0;
  DAT_0008c09d = 0;
  DAT_0008c0ce = 8;
  DAT_0008c0ee = 0;
  DAT_0008c136 = 0;
  DAT_0008c06e = 0;
  DAT_0008c00e = 0x77;
  DAT_0008c0cf = 0x20;
  DAT_0008c06f = 0;
  DAT_0008c00f = 0xdf;
  DAT_0008c032 = 0;
  DAT_0008c0a4 = 0;
  DAT_0008c0d2 = 0x20;
  DAT_0008c072 = 0;
  DAT_0008c012 = 0xdf;
  FUN_fff9321e();
  return;
}


// ===== FUN_fff9321e @ fff9321e (1 bytes)

void FUN_fff9321e(void)

{
  return;
}


// ===== R_SCI0_Create @ fff9321f (163 bytes)

/* SCI0 init (USB "Standard" CAT via CP2105) */

void R_SCI0_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0x7fffffff;
  bVar2 = DAT_0008733a;
  DAT_0008733a = bVar2 & 0xf8 | 8;
  bVar2 = DAT_0008733b;
  DAT_0008733b = bVar2 & 0xf8 | 8;
  DAT_0008a002 = 0;
  DAT_0008a002 = 0;
  bVar2 = DAT_0008a009;
  DAT_0008a009 = bVar2 & 0xfe;
  DAT_0008a00d = 0;
  DAT_0008a000 = 1;
  DAT_0008a006 = 0x72;
  DAT_0008a007 = 0x10;
  DAT_0008a001 = 0xc2;
  DAT_0008c15b = 0xb;
  bVar2 = DAT_0008c063;
  DAT_0008c063 = bVar2 | 8;
  DAT_0008c15a = 0xb;
  bVar2 = DAT_0008c023;
  DAT_0008c023 = bVar2 | 4;
  bVar2 = DAT_0008c003;
  DAT_0008c003 = bVar2 | 4;
  R_SCI0_Create_UserInit();
  return;
}


// ===== R_SCI0_Start @ fff932c2 (64 bytes)

void R_SCI0_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008703b;
  DAT_0008703b = bVar1 & 0xfe;
  bVar1 = DAT_0008703a;
  DAT_0008703a = bVar1 & 0xfe;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 | 8;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 1;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 | 4;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 2;
  return;
}


// ===== R_SCI0_Stop @ fff93302 (104 bytes)

void R_SCI0_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008c063;
  DAT_0008c063 = bVar1 & 0xfb;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0xdf;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0xef;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0x7f;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0xbf;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 & 0xf7;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffffe;
  bVar1 = DAT_0008703b;
  DAT_0008703b = bVar1 & 0xfe;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 & 0xfb;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffffd;
  bVar1 = DAT_0008703a;
  DAT_0008703a = bVar1 & 0xfe;
  return;
}


// ===== R_SCI0_Serial_Receive @ fff9336a (68 bytes)

ushort R_SCI0_Serial_Receive(uint param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    DAT_0001b606 = 0;
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 | 0x40;
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 | 0x10;
    DAT_0001b608 = param_2;
    DAT_000207f8 = param_1;
  }
  return local_a;
}


// ===== R_SCI0_Serial_Send @ fff933ae (95 bytes)

ushort R_SCI0_Serial_Send(uint param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    bVar1 = DAT_00087207;
    if ((bVar1 & 8) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = DAT_00087207;
      DAT_00087207 = bVar1 & 0xf7;
      bVar1 = DAT_0008a002;
      DAT_0008a002 = bVar1 | 0xa0;
      bVar1 = DAT_0008c063;
      DAT_0008c063 = bVar1 | 4;
      bVar1 = DAT_00087207;
      DAT_00087207 = bVar1 | 8;
      DAT_0001b604 = param_2;
      DAT_000207f4 = param_1;
    }
  }
  return local_a;
}


// ===== R_SCI0_Create_UserInit @ fff9340d (1 bytes)

/* empty */

void R_SCI0_Create_UserInit(void)

{
  return;
}


// ===== r_sci0_transmit_interrupt @ fff9340e (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93444) */
/* WARNING: Removing unreachable block (ram,0xfff9340e) */
/* WARNING: Removing unreachable block (ram,0xfff93456) */

void r_sci0_transmit_interrupt(void)

{
  byte bVar1;
  
  if (DAT_0001b604 == 0) {
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 & 0x7f;
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 | 4;
    return;
  }
  DAT_0008a003 = *DAT_000207f4;
  DAT_000207f4 = DAT_000207f4 + 1;
  DAT_0001b604 = DAT_0001b604 + -1;
  return;
}


// ===== r_sci0_transmitend_interrupt @ fff9345a (37 bytes)

/* TEI0 (GROUPBL0 cb 0x14): TXD pin to GPIO, clear TIE/TE/TEIE, transmit-end callback */

void r_sci0_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c063;
  DAT_0008c063 = bVar1 & 0xfb;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0x7f;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0xdf;
  bVar1 = DAT_0008a002;
  DAT_0008a002 = bVar1 & 0xfb;
  r_sci0_callback_transmitend();
  return;
}


// ===== r_sci0_receive_interrupt @ fff9347f (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff934e5) */
/* WARNING: Removing unreachable block (ram,0xfff934ed) */
/* WARNING: Removing unreachable block (ram,0xfff934eb) */
/* WARNING: Removing unreachable block (ram,0xfff9347f) */
/* WARNING: Removing unreachable block (ram,0xfff93481) */
/* WARNING: Removing unreachable block (ram,0xfff934e7) */

void r_sci0_receive_interrupt(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b606 < DAT_0001b608) {
    uVar2 = DAT_0008a005;
    *DAT_000207f8 = uVar2;
    r_sci0_rx_byte_hook();
    DAT_000207f8 = DAT_000207f8 + 1;
    DAT_0001b606 = DAT_0001b606 + 1;
  }
  if (DAT_0001b608 <= DAT_0001b606) {
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 & 0xbf;
    bVar1 = DAT_0008a002;
    DAT_0008a002 = bVar1 & 0xef;
    r_sci0_callback_receiveend();
    return;
  }
  return;
}


// ===== r_sci0_receiveerror_interrupt @ fff934f1 (39 bytes)

/* ERI0 (cb 0x15): error callback, clear ORER/FER/PER */

void r_sci0_receiveerror_interrupt(void)

{
  byte bVar1;
  
  r_sci0_callback_receiveerror();
  bVar1 = DAT_0008a004;
  DAT_0008a004 = bVar1 & 199 | 0xc0;
  return;
}


// ===== r_sci0_callback_transmitend @ fff93518 (5 bytes)

/* -> cat_tx_done_sci0 */

void r_sci0_callback_transmitend(void)

{
  cat_tx_done_sci0();
  return;
}


// ===== r_sci0_callback_receiveend @ fff9351d (15 bytes)

void r_sci0_callback_receiveend(void)

{
  cat_rx_complete(2,DAT_0001b608);
  return;
}


// ===== r_sci0_callback_receiveerror @ fff9352c (1 bytes)

/* empty */

void r_sci0_callback_receiveerror(void)

{
  return;
}


// ===== r_sci0_rx_byte_hook @ fff9352d (33 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9354b) */
/* cat_rx_byte_hook(&cnt,&len,ptr,timer 5) */

void r_sci0_rx_byte_hook(void)

{
  DAT_000207f8 = (char *)cat_rx_byte_hook(&DAT_0001b606,&DAT_0001b608,DAT_000207f8,5);
  return;
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
  R_SCI1_Create_UserInit();
  return;
}


// ===== R_SCI1_Start @ fff935ef (64 bytes)

void R_SCI1_Start(void)

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


// ===== FUN_fff9362f @ fff9362f (104 bytes)

void FUN_fff9362f(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008c062;
  DAT_0008c062 = bVar1 & 0xbf;
  bVar1 = DAT_0008a022;
  DAT_0008a022 = bVar1 & 0xdf;
  bVar1 = DAT_0008a022;
  DAT_0008a022 = bVar1 & 0xef;
  bVar1 = DAT_0008a022;
  DAT_0008a022 = bVar1 & 0x7f;
  bVar1 = DAT_0008a022;
  DAT_0008a022 = bVar1 & 0xbf;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 & 0xdf;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffffb;
  bVar1 = DAT_0008703d;
  DAT_0008703d = bVar1 & 0xfe;
  bVar1 = DAT_00087207;
  DAT_00087207 = bVar1 & 0xef;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xfffffff7;
  bVar1 = DAT_0008703c;
  DAT_0008703c = bVar1 & 0xfe;
  return;
}


// ===== R_SCI1_Serial_Receive @ fff93697 (68 bytes)

ushort R_SCI1_Serial_Receive(uint param_1,short param_2)

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

ushort R_SCI1_Serial_Send(uint param_1,short param_2)

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


// ===== R_SCI1_Create_UserInit @ fff9373a (1 bytes)

/* empty */

void R_SCI1_Create_UserInit(void)

{
  return;
}


// ===== r_sci1_transmit_interrupt @ fff9373b (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93771) */
/* WARNING: Removing unreachable block (ram,0xfff9373b) */
/* WARNING: Removing unreachable block (ram,0xfff93783) */

void r_sci1_transmit_interrupt(void)

{
  byte bVar1;
  
  if (DAT_0001b60a == 0) {
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 & 0x7f;
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 | 4;
    return;
  }
  DAT_0008a023 = *DAT_000207fc;
  DAT_000207fc = DAT_000207fc + 1;
  DAT_0001b60a = DAT_0001b60a + -1;
  return;
}


// ===== r_sci1_transmitend_interrupt @ fff93787 (37 bytes)

/* TEI1 (cb 0x16) */

void r_sci1_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c062;
  DAT_0008c062 = bVar1 & 0xbf;
  bVar1 = DAT_0008a022;
  DAT_0008a022 = bVar1 & 0x7f;
  bVar1 = DAT_0008a022;
  DAT_0008a022 = bVar1 & 0xdf;
  bVar1 = DAT_0008a022;
  DAT_0008a022 = bVar1 & 0xfb;
  r_sci1_callback_transmitend();
  return;
}


// ===== r_sci1_receive_interrupt @ fff937ac (114 bytes)

/* WARNING: Removing unreachable block (ram,0xfff93812) */
/* WARNING: Removing unreachable block (ram,0xfff9381a) */
/* WARNING: Removing unreachable block (ram,0xfff93818) */
/* WARNING: Removing unreachable block (ram,0xfff937ac) */
/* WARNING: Removing unreachable block (ram,0xfff937ae) */
/* WARNING: Removing unreachable block (ram,0xfff93814) */

void r_sci1_receive_interrupt(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001b60c < DAT_0001b60e) {
    uVar2 = DAT_0008a025;
    *DAT_00020800 = uVar2;
    displink_rx_frame_len();
    DAT_00020800 = DAT_00020800 + 1;
    DAT_0001b60c = DAT_0001b60c + 1;
  }
  if (DAT_0001b60e <= DAT_0001b60c) {
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 & 0xbf;
    bVar1 = DAT_0008a022;
    DAT_0008a022 = bVar1 & 0xef;
    r_sci1_callback_receiveend();
    return;
  }
  return;
}


// ===== r_sci1_receiveerror_interrupt @ fff9381e (39 bytes)

/* ERI1 (cb 0x17) */

void r_sci1_receiveerror_interrupt(void)

{
  byte bVar1;
  
  r_sci1_callback_receiveerror();
  bVar1 = DAT_0008a024;
  DAT_0008a024 = bVar1 & 199 | 0xc0;
  return;
}


// ===== r_sci1_callback_transmitend @ fff93845 (1 bytes)

/* empty */

void r_sci1_callback_transmitend(void)

{
  return;
}


// ===== r_sci1_callback_receiveend @ fff93846 (5 bytes)

/* -> displink_rx_done */

void r_sci1_callback_receiveend(void)

{
  displink_rx_done();
  return;
}


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
  R_SCI2_Create_UserInit();
  return;
}


// ===== R_SCI2_Start @ fff93b29 (64 bytes)

void R_SCI2_Start(void)

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

