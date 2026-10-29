// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== R_IWDT_Create @ fff927a9 (37 bytes)

/* IWDTCR=0x3350, IWDTRCR=0 (underflow -> NMI), NMIER.IWDTEN */

void R_IWDT_Create(void)

{
  byte bVar1;
  
  IWDT_IWDTCR = 0x3350;
  IWDT_IWDTRCR = 0;
  IWDT_IWDTCSTPR = 0x80;
  bVar1 = ICU_NMIER;
  ICU_NMIER = bVar1 | 8;
  R_IWDT_Create_UserInit();
  return;
}


// ===== iwdt_refresh @ fff927ce (17 bytes)

/* IWDTRR <- 0x00, 0xFF */

void iwdt_refresh(void)

{
  IWDT_IWDTRR = 0;
  IWDT_IWDTRR = 0xff;
  return;
}


// ===== R_IWDT_Create_UserInit @ fff927df (1 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): empty rts,
   called last by R_IWDT_Create [inference] */

void R_IWDT_Create_UserInit(void)

{
  return;
}


// ===== R_DA_Create @ fff927e5 (65 bytes)

/* DA0 on P03 (net DA_OUT -> TONE_BEEP) */

void R_DA_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = SYSTEM_MSTPCRA;
  SYSTEM_MSTPCRA = uVar1 & 0xfff7ffff;
  DA_DADPR = 0;
  DA_DAADSCR = 0;
  bVar2 = PORT0_PMR;
  PORT0_PMR = bVar2 & 0xf7;
  bVar2 = PORT0_PDR;
  PORT0_PDR = bVar2 & 0xf7;
  bVar2 = MPC_P03PFS;
  MPC_P03PFS = bVar2 | 0x80;
  R_DA_Create_UserInit();
  return;
}


// ===== R_DA0_Start @ fff92826 (15 bytes)

/* DACR.DAOE0=1 */

void R_DA0_Start(void)

{
  byte bVar1;
  
  bVar1 = DA_DACR;
  DA_DACR = bVar1 & 0xdf;
  bVar1 = DA_DACR;
  DA_DACR = bVar1 | 0x40;
  return;
}


// ===== R_DA0_Stop @ fff92835 (8 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.950): DA.DACR
   (0x88044) DAOE0 (bit 6) off; after R_DA0_Start [inference] */

void R_DA0_Stop(void)

{
  byte bVar1;
  
  bVar1 = DA_DACR;
  DA_DACR = bVar1 & 0xbf;
  return;
}


// ===== dac0_write @ fff9283d (19 bytes)

/* DADR0 = v & 0xFFF */

void dac0_write(ushort param_1)

{
  DA_DADR0 = param_1 & 0xfff;
  return;
}


// ===== R_DA_Create_UserInit @ fff92850 (1 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): empty rts,
   called last by R_DA_Create [inference] */

void R_DA_Create_UserInit(void)

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
  
  uVar1 = SYSTEM_MSTPCRA;
  SYSTEM_MSTPCRA = uVar1 & 0xfffdffff;
  uVar3 = S12AD_ADCSR;
  S12AD_ADCSR = uVar3 & 0xefff;
  uVar3 = S12AD_ADCMPCR;
  S12AD_ADCMPCR = uVar3 & 0x7fff;
  uVar3 = S12AD_ADCMPCR;
  S12AD_ADCMPCR = uVar3 & 0xdfff;
  bVar2 = ICU_IER17;
  ICU_IER17 = bVar2 & 0xfb;
  S12AD_ADCSR = 0;
  S12AD_ADDISCR = 0;
  S12AD_ADSSTR1 = 0xb;
  S12AD_ADSSTR2 = 0xb;
  S12AD_ADSSTR3 = 0xb;
  S12AD_ADSSTR5 = 0xb;
  S12AD_ADSSTR6 = 0xb;
  S12AD_ADSSTR7 = 0xb;
  S12AD_ADANSA0 = 0xee;
  S12AD_ADADS0 = 0xe8;
  S12AD_ADSHCR = 0x618;
  S12AD_ADCER = 0;
  uVar3 = S12AD_ADCSR;
  S12AD_ADCSR = uVar3 | 0x1000;
  S12AD_ADADC = 0x83;
  S12AD_ADCMPCR = 0;
  ICU_SLIBR186 = 0x40;
  bVar2 = ICU_IPR186;
  ICU_IPR186 = bVar2 & 0xf6 | 6;
  bVar2 = PORT4_PMR;
  PORT4_PMR = bVar2 & 0xfd;
  bVar2 = PORT4_PDR;
  PORT4_PDR = bVar2 & 0xfd;
  MPC_P41PFS = 0x80;
  bVar2 = PORT4_PMR;
  PORT4_PMR = bVar2 & 0xfb;
  bVar2 = PORT4_PDR;
  PORT4_PDR = bVar2 & 0xfb;
  MPC_P42PFS = 0x80;
  bVar2 = PORT4_PMR;
  PORT4_PMR = bVar2 & 0xf7;
  bVar2 = PORT4_PDR;
  PORT4_PDR = bVar2 & 0xf7;
  MPC_P43PFS = 0x80;
  bVar2 = PORT4_PMR;
  PORT4_PMR = bVar2 & 0xdf;
  bVar2 = PORT4_PDR;
  PORT4_PDR = bVar2 & 0xdf;
  MPC_P45PFS = 0x80;
  bVar2 = PORT4_PMR;
  PORT4_PMR = bVar2 & 0xbf;
  bVar2 = PORT4_PDR;
  PORT4_PDR = bVar2 & 0xbf;
  MPC_P46PFS = 0x80;
  bVar2 = PORT4_PMR;
  PORT4_PMR = bVar2 & 0x7f;
  bVar2 = PORT4_PDR;
  PORT4_PDR = bVar2 & 0x7f;
  MPC_P47PFS = 0x80;
  R_S12AD0_Create_UserInit();
  return;
}


// ===== R_S12AD0_Start @ fff929f7 (28 bytes)

/* ADCSR.ADST=1 */

void R_S12AD0_Start(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = ICU_IR186;
  ICU_IR186 = bVar1 & 0xfe;
  bVar1 = ICU_IER17;
  ICU_IER17 = bVar1 | 4;
  uVar2 = S12AD_ADCSR;
  S12AD_ADCSR = uVar2 | 0x8000;
  return;
}


// ===== R_S12AD0_Stop @ fff92a13 (30 bytes)

void R_S12AD0_Stop(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = S12AD_ADCSR;
  S12AD_ADCSR = uVar2 & 0x7fff;
  bVar1 = ICU_IR186;
  ICU_IR186 = bVar1 & 0xfe;
  bVar1 = ICU_IER17;
  ICU_IER17 = bVar1 & 0xfb;
  return;
}


// ===== R_S12AD0_Get_ValueResult @ fff92a31 (207 bytes)

/* (channel, *dst) */

void R_S12AD0_Get_ValueResult(int param_1,void *param_2)

{
  undefined2 uVar1;
  
  if (param_1 == 0) {
    uVar1 = S12AD_ADDR0;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 1) {
    uVar1 = S12AD_ADDR1;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 2) {
    uVar1 = S12AD_ADDR2;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 3) {
    uVar1 = S12AD_ADDR3;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 4) {
    uVar1 = S12AD_ADDR4;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 5) {
    uVar1 = S12AD_ADDR5;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 6) {
    uVar1 = S12AD_ADDR6;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 7) {
    uVar1 = S12AD_ADDR7;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 0x1a) {
    uVar1 = S12AD_ADDBLDRB;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 0x18) {
    uVar1 = S12AD_ADDBLDR;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 0x19) {
    uVar1 = S12AD_ADDBLDRA;
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 != 0x15) {
    return;
  }
  uVar1 = S12AD_ADRD;
  *(undefined2 *)param_2 = uVar1;
  return;
}


// ===== R_S12AD0_Create_UserInit @ fff92b00 (1 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): empty rts,
   called last by R_S12AD0_Create [inference] */

void R_S12AD0_Create_UserInit(void)

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
  
  uVar1 = SYSTEM_MSTPCRA;
  SYSTEM_MSTPCRA = uVar1 & 0xfffeffff;
  uVar3 = S12AD1_ADCSR;
  S12AD1_ADCSR = uVar3 & 0xefff;
  uVar3 = S12AD1_ADCMPCR;
  S12AD1_ADCMPCR = uVar3 & 0x7fff;
  uVar3 = S12AD1_ADCMPCR;
  S12AD1_ADCMPCR = uVar3 & 0xdfff;
  bVar2 = ICU_IER17;
  ICU_IER17 = bVar2 & 0xdf;
  S12AD1_ADDISCR = 0;
  S12AD1_ADCSR = 0x5000;
  S12AD1_ADCER = 0;
  S12AD1_ADADC = 0x83;
  S12AD1_ADANSA0 = 0x8300;
  S12AD1_ADANSA1 = 2;
  S12AD1_ADADS0 = 0x8300;
  S12AD1_ADADS1 = 2;
  S12AD1_ADSSTR8 = 0xb;
  S12AD1_ADSSTR9 = 0xb;
  S12AD1_ADSSTR15 = 0xb;
  S12AD1_ADSSTRL = 0xb;
  S12AD1_ADCMPCR = 0;
  ICU_SLIBR189 = 0x44;
  bVar2 = ICU_IPR189;
  ICU_IPR189 = bVar2 & 0xf6 | 6;
  bVar2 = PORTD_PMR;
  PORTD_PMR = bVar2 & 0xfe;
  bVar2 = PORTD_PDR;
  PORTD_PDR = bVar2 & 0xfe;
  MPC_PD0PFS = 0x80;
  bVar2 = PORTD_PMR;
  PORTD_PMR = bVar2 & 0xfd;
  bVar2 = PORTD_PDR;
  PORTD_PDR = bVar2 & 0xfd;
  MPC_PD1PFS = 0x80;
  bVar2 = PORT9_PMR;
  PORT9_PMR = bVar2 & 0xfd;
  bVar2 = PORT9_PDR;
  PORT9_PDR = bVar2 & 0xfd;
  MPC_P91PFS = 0x80;
  bVar2 = PORT9_PMR;
  PORT9_PMR = bVar2 & 0xf7;
  bVar2 = PORT9_PDR;
  PORT9_PDR = bVar2 & 0xf7;
  MPC_P93PFS = 0x80;
  R_S12AD1_Create_UserInit();
  return;
}


// ===== R_S12AD1_Start @ fff92c74 (28 bytes)

void R_S12AD1_Start(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = ICU_IR189;
  ICU_IR189 = bVar1 & 0xfe;
  bVar1 = ICU_IER17;
  ICU_IER17 = bVar1 | 0x20;
  uVar2 = S12AD1_ADCSR;
  S12AD1_ADCSR = uVar2 | 0x8000;
  return;
}


// ===== R_S12AD1_Stop @ fff92c90 (30 bytes)

void R_S12AD1_Stop(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = S12AD1_ADCSR;
  S12AD1_ADCSR = uVar2 & 0x7fff;
  bVar1 = ICU_IER17;
  ICU_IER17 = bVar1 & 0xdf;
  bVar1 = ICU_IR189;
  ICU_IR189 = bVar1 & 0xfe;
  return;
}


// ===== R_S12AD1_Get_ValueResult @ fff92cae (352 bytes)

/* (channel, *dst) */

void R_S12AD1_Get_ValueResult(uint param_1,void *param_2)

{
  undefined2 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = S12AD1_ADDR0;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 1:
    uVar1 = S12AD1_ADDR1;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 2:
    uVar1 = S12AD1_ADDR2;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 3:
    uVar1 = S12AD1_ADDR3;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 4:
    uVar1 = S12AD1_ADDR4;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 5:
    uVar1 = S12AD1_ADDR5;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 6:
    uVar1 = S12AD1_ADDR6;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 7:
    uVar1 = S12AD1_ADDR7;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 8:
    uVar1 = S12AD1_ADDR8;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 9:
    uVar1 = S12AD1_ADDR9;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 10:
    uVar1 = S12AD1_ADDR10;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xb:
    uVar1 = S12AD1_ADDR11;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xc:
    uVar1 = S12AD1_ADDR12;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xd:
    uVar1 = S12AD1_ADDR13;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xe:
    uVar1 = S12AD1_ADDR14;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xf:
    uVar1 = S12AD1_ADDR15;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x10:
    uVar1 = S12AD1_ADDR16;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x11:
    uVar1 = S12AD1_ADDR17;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x12:
    uVar1 = S12AD1_ADDR18;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x13:
    uVar1 = S12AD1_ADDR19;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x14:
    uVar1 = S12AD1_ADDR20;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x15:
    uVar1 = S12AD1_ADRD;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x16:
    uVar1 = S12AD1_ADTSDR;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x17:
    uVar1 = S12AD1_ADOCDR;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x18:
    uVar1 = S12AD1_ADDBLDR;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x19:
    uVar1 = S12AD1_ADDBLDRA;
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x1a:
    uVar1 = S12AD1_ADDBLDRB;
    *(undefined2 *)param_2 = uVar1;
    return;
  default:
    return;
  }
}


// ===== R_S12AD1_Create_UserInit @ fff92e0e (1 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): empty rts,
   called last by R_S12AD1_Create [inference] */

void R_S12AD1_Create_UserInit(void)

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
  
  ICU_IER08 = 0;
  ICU_IER09 = 0;
  bVar1 = ICU_IER03;
  ICU_IER03 = bVar1 & 0xf7;
  bVar1 = ICU_IER03;
  ICU_IER03 = bVar1 & 0xfb;
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
  PORT0_ODR0 = 0;
  PORT0_PCR = 0xa4;
  PORT0_DSCR = 0;
  PORT0_DSCR2 = 0;
  PORT0_PMR = 0;
  PORT0_PDR = 0x50;
  PORT1_ODR0 = 0;
  PORT1_PCR = 0;
  PORT1_DSCR = 0;
  PORT1_DSCR2 = 0;
  PORT1_PMR = 0;
  PORT1_PDR = 3;
  PORT2_PODR = 0;
  PORT2_ODR0 = 0;
  PORT2_ODR1 = 0;
  PORT2_PCR = 3;
  PORT2_DSCR = 0xc;
  PORT2_DSCR2 = 0;
  PORT2_PMR = 0;
  PORT2_PDR = 0x14;
  PORT3_ODR0 = 0;
  PORT3_ODR1 = 0;
  PORT3_PCR = 0x12;
  PORT3_DSCR2 = 0;
  PORT3_PMR = 0;
  PORT3_PDR = 0;
  PORT4_ODR0 = 0;
  PORT4_ODR1 = 0;
  PORT4_PCR = 0x11;
  PORT4_PMR = 0;
  PORT4_PDR = 0;
  PORT5_PODR = 0;
  PORT5_ODR1 = 0;
  PORT5_PCR = 0x1e;
  PORT5_DSCR = 0;
  PORT5_DSCR2 = 0;
  PORT5_PMR = 0;
  PORT5_PDR = 0xc0;
  PORT6_PODR = 0;
  PORT6_ODR0 = 0;
  PORT6_ODR1 = 0;
  PORT6_PCR = 0x17;
  PORT6_PMR = 0;
  PORT6_PDR = 0xe8;
  PORT7_PODR = 0x40;
  PORT7_ODR0 = 4;
  PORT7_ODR1 = 0;
  PORT7_PCR = 0;
  PORT7_DSCR = 9;
  PORT7_DSCR2 = 0;
  PORT7_PMR = 0;
  PORT7_PDR = 0xdf;
  PORT8_PODR = 0x40;
  PORT8_ODR0 = 0;
  PORT8_ODR1 = 0;
  PORT8_PCR = 0;
  PORT8_DSCR = 0;
  PORT8_DSCR2 = 0;
  PORT8_PMR = 0;
  PORT8_PDR = 0x7f;
  PORT9_ODR0 = 0;
  PORT9_DSCR = 0;
  PORT9_DSCR2 = 0;
  PORTA_PODR = 0;
  PORTA_ODR0 = 0;
  PORTA_ODR1 = 0;
  PORTA_PCR = 8;
  PORTA_DSCR = 0;
  PORTA_DSCR2 = 0;
  PORTA_PMR = 0;
  PORTA_PDR = 0xf7;
  PORTB_PODR = 0;
  PORTB_ODR0 = 0;
  PORTB_ODR1 = 0;
  PORTB_DSCR = 0;
  PORTB_DSCR2 = 0;
  PORTB_PMR = 0;
  PORTB_PDR = 0xfc;
  PORTC_PODR = 0x10;
  PORTC_ODR0 = 0;
  PORTC_ODR1 = 0;
  PORTC_PCR = 2;
  PORTC_DSCR = 0;
  PORTC_DSCR2 = 0;
  PORTC_PMR = 0;
  PORTC_PDR = 0x11;
  PORTD_PODR = 0;
  PORTD_ODR0 = 0;
  PORTD_ODR1 = 0;
  PORTD_DSCR = 0;
  PORTD_DSCR2 = 0;
  PORTD_PMR = 0;
  PORTD_PDR = 0xfc;
  PORTE_PODR = 0;
  PORTE_ODR0 = 0;
  PORTE_ODR1 = 0;
  PORTE_PCR = 8;
  PORTE_DSCR = 0;
  PORTE_DSCR2 = 0;
  PORTE_PMR = 0;
  PORTE_PDR = 0x77;
  PORTF_PCR = 0x20;
  PORTF_PMR = 0;
  PORTF_PDR = 0xdf;
  PORTJ_PODR = 0;
  PORTJ_ODR0 = 0;
  PORTJ_PCR = 0x20;
  PORTJ_PMR = 0;
  PORTJ_PDR = 0xdf;
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
  
  uVar1 = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = uVar1 & 0x7fffffff;
  bVar2 = ICU_IPR058;
  ICU_IPR058 = bVar2 & 0xf8 | 8;
  bVar2 = ICU_IPR059;
  ICU_IPR059 = bVar2 & 0xf8 | 8;
  SCI0_SCR = 0;
  SCI0_SCR = 0;
  bVar2 = SCI0_SIMR1;
  SCI0_SIMR1 = bVar2 & 0xfe;
  SCI0_SPMR = 0;
  SCI0_SMR = 1;
  SCI0_SCMR = 0x72;
  SCI0_SEMR = 0x10;
  SCI0_BRR = 0xc2;
  MPC_P33PFS = 0xb;
  bVar2 = PORT3_PMR;
  PORT3_PMR = bVar2 | 8;
  MPC_P32PFS = 0xb;
  bVar2 = PORT3_PODR;
  PORT3_PODR = bVar2 | 4;
  bVar2 = PORT3_PDR;
  PORT3_PDR = bVar2 | 4;
  R_SCI0_Create_UserInit();
  return;
}


// ===== R_SCI0_Start @ fff932c2 (64 bytes)

void R_SCI0_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR059;
  ICU_IR059 = bVar1 & 0xfe;
  bVar1 = ICU_IR058;
  ICU_IR058 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 | 8;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 1;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 | 4;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 2;
  return;
}


// ===== R_SCI0_Stop @ fff93302 (104 bytes)

void R_SCI0_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = PORT3_PMR;
  PORT3_PMR = bVar1 & 0xfb;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0xdf;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0xef;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0x7f;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0xbf;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 & 0xf7;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffffe;
  bVar1 = ICU_IR059;
  ICU_IR059 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 & 0xfb;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffffd;
  bVar1 = ICU_IR058;
  ICU_IR058 = bVar1 & 0xfe;
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
    bVar1 = SCI0_SCR;
    SCI0_SCR = bVar1 | 0x40;
    bVar1 = SCI0_SCR;
    SCI0_SCR = bVar1 | 0x10;
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
    bVar1 = ICU_IER07;
    if ((bVar1 & 8) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = ICU_IER07;
      ICU_IER07 = bVar1 & 0xf7;
      bVar1 = SCI0_SCR;
      SCI0_SCR = bVar1 | 0xa0;
      bVar1 = PORT3_PMR;
      PORT3_PMR = bVar1 | 4;
      bVar1 = ICU_IER07;
      ICU_IER07 = bVar1 | 8;
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
    bVar1 = SCI0_SCR;
    SCI0_SCR = bVar1 & 0x7f;
    bVar1 = SCI0_SCR;
    SCI0_SCR = bVar1 | 4;
    return;
  }
  SCI0_TDR = *DAT_000207f4;
  DAT_000207f4 = DAT_000207f4 + 1;
  DAT_0001b604 = DAT_0001b604 + -1;
  return;
}


// ===== r_sci0_transmitend_interrupt @ fff9345a (37 bytes)

/* TEI0 (GROUPBL0 cb 0x14): TXD pin to GPIO, clear TIE/TE/TEIE, transmit-end callback */

void r_sci0_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = PORT3_PMR;
  PORT3_PMR = bVar1 & 0xfb;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0x7f;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0xdf;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0xfb;
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
    uVar2 = SCI0_RDR;
    *DAT_000207f8 = uVar2;
    r_sci0_rx_byte_hook();
    DAT_000207f8 = DAT_000207f8 + 1;
    DAT_0001b606 = DAT_0001b606 + 1;
  }
  if (DAT_0001b608 <= DAT_0001b606) {
    bVar1 = SCI0_SCR;
    SCI0_SCR = bVar1 & 0xbf;
    bVar1 = SCI0_SCR;
    SCI0_SCR = bVar1 & 0xef;
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
  bVar1 = SCI0_SSR;
  SCI0_SSR = bVar1 & 199 | 0xc0;
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
  
  uVar1 = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = uVar1 & 0xbfffffff;
  bVar2 = ICU_IPR060;
  ICU_IPR060 = bVar2 & 0xfa | 10;
  bVar2 = ICU_IPR061;
  ICU_IPR061 = bVar2 & 0xfa | 10;
  SCI1_SCR = 0;
  SCI1_SCR = 0;
  bVar2 = SCI1_SIMR1;
  SCI1_SIMR1 = bVar2 & 0xfe;
  SCI1_SPMR = 0;
  SCI1_SMR = 8;
  SCI1_SCMR = 0x72;
  SCI1_SEMR = 0x10;
  SCI1_BRR = 10;
  MPC_P30PFS = 10;
  bVar2 = PORT3_PMR;
  PORT3_PMR = bVar2 | 1;
  MPC_P26PFS = 10;
  bVar2 = PORT2_PODR;
  PORT2_PODR = bVar2 | 0x40;
  bVar2 = PORT2_PDR;
  PORT2_PDR = bVar2 | 0x40;
  R_SCI1_Create_UserInit();
  return;
}


// ===== R_SCI1_Start @ fff935ef (64 bytes)

void R_SCI1_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR061;
  ICU_IR061 = bVar1 & 0xfe;
  bVar1 = ICU_IR060;
  ICU_IR060 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 | 0x20;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 4;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 | 0x10;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 8;
  return;
}


// ===== R_SCI1_Stop @ fff9362f (104 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.950): clears
   SCI1.SCR (0x8A022) TE/RE/TIE/RIE, IEN/IR of SCI1 TXI/RXI/TEI (0x87207, 0x8703C..D, ICU.GENBL0
   0x87670); 104 B like R_SCI0/2/3/5_Stop, sits after R_SCI1_Start [inference] */

void R_SCI1_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = PORT2_PMR;
  PORT2_PMR = bVar1 & 0xbf;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0xdf;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0xef;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0x7f;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0xbf;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 & 0xdf;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffffb;
  bVar1 = ICU_IR061;
  ICU_IR061 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 & 0xef;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffff7;
  bVar1 = ICU_IR060;
  ICU_IR060 = bVar1 & 0xfe;
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
    bVar1 = SCI1_SCR;
    SCI1_SCR = bVar1 | 0x40;
    bVar1 = SCI1_SCR;
    SCI1_SCR = bVar1 | 0x10;
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
    bVar1 = ICU_IER07;
    if ((bVar1 & 0x20) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = ICU_IER07;
      ICU_IER07 = bVar1 & 0xdf;
      bVar1 = SCI1_SCR;
      SCI1_SCR = bVar1 | 0xa0;
      bVar1 = PORT2_PMR;
      PORT2_PMR = bVar1 | 0x40;
      bVar1 = ICU_IER07;
      ICU_IER07 = bVar1 | 0x20;
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
    bVar1 = SCI1_SCR;
    SCI1_SCR = bVar1 & 0x7f;
    bVar1 = SCI1_SCR;
    SCI1_SCR = bVar1 | 4;
    return;
  }
  SCI1_TDR = *DAT_000207fc;
  DAT_000207fc = DAT_000207fc + 1;
  DAT_0001b60a = DAT_0001b60a + -1;
  return;
}


// ===== r_sci1_transmitend_interrupt @ fff93787 (37 bytes)

/* TEI1 (cb 0x16) */

void r_sci1_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = PORT2_PMR;
  PORT2_PMR = bVar1 & 0xbf;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0x7f;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0xdf;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0xfb;
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
    uVar2 = SCI1_RDR;
    *DAT_00020800 = uVar2;
    displink_rx_frame_len();
    DAT_00020800 = DAT_00020800 + 1;
    DAT_0001b60c = DAT_0001b60c + 1;
  }
  if (DAT_0001b60e <= DAT_0001b60c) {
    bVar1 = SCI1_SCR;
    SCI1_SCR = bVar1 & 0xbf;
    bVar1 = SCI1_SCR;
    SCI1_SCR = bVar1 & 0xef;
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
  bVar1 = SCI1_SSR;
  SCI1_SSR = bVar1 & 199 | 0xc0;
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

