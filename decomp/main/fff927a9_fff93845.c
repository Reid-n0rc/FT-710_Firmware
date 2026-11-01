// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== R_IWDT_Create @ fff927a9 (37 bytes)

/* IWDTCR=0x3350, IWDTRCR=0 (underflow -> NMI), NMIER.IWDTEN */

void R_IWDT_Create(void)

{
  byte icu_nmier;
  
                    /* IWDT Control [sfr] */
  IWDT_IWDTCR = 0x3350;
                    /* IWDT Reset Control [sfr] */
  IWDT_IWDTRCR = 0;
                    /* IWDT Count Stop Control [sfr] */
  IWDT_IWDTCSTPR = 0x80;
  icu_nmier = ICU_NMIER;
                    /* Non-Maskable Interrupt Enable [sfr] */
  ICU_NMIER = icu_nmier | 8;
  R_IWDT_Create_UserInit();
  return;
}


// ===== iwdt_refresh @ fff927ce (17 bytes)

/* IWDTRR <- 0x00, 0xFF */

void iwdt_refresh(void)

{
                    /* IWDT Refresh [sfr] */
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


// ===== iwdt_error_nmi_cb @ fff927e0 (5 bytes)

/* BSP callback 7 (R_BSP_InterruptWrite(7, ...) at 0xFFF8F6DD), called by NMI 0xFFF9061B when
   NMISR.IWDTST (bit 3, IWDT underflow/refresh error; RX651 hardware manual 15.2.14) is set:
   sw_reset [fact] */

void iwdt_error_nmi_cb(void)

{
  sw_reset();
  return;
}


// ===== R_DA_Create @ fff927e5 (65 bytes)

/* DA0 on P03 (net DA_OUT -> TONE_BEEP) */

void R_DA_Create(void)

{
  byte bVar1;
  uint system_mstpcra;
  
                    /* Module Stop Control A [sfr] */
  system_mstpcra = SYSTEM_MSTPCRA;
  SYSTEM_MSTPCRA = system_mstpcra & 0xfff7ffff;
                    /* Data Format Select [sfr] */
  DA_DADPR = 0;
                    /* D/A A/D Synchronous Start Control [sfr] */
  DA_DAADSCR = 0;
  bVar1 = PORT0_PMR;
                    /* Port Mode [sfr] */
  PORT0_PMR = bVar1 & 0xf7;
                    /* Port Direction [sfr] */
  bVar1 = PORT0_PDR;
  PORT0_PDR = bVar1 & 0xf7;
  bVar1 = MPC_P03PFS;
                    /* P03 Pin Function Control [sfr] */
  MPC_P03PFS = bVar1 | 0x80;
  R_DA_Create_UserInit();
  return;
}


// ===== R_DA0_Start @ fff92826 (15 bytes)

/* DACR.DAOE0=1 */

void R_DA0_Start(void)

{
  byte bVar1;
  
  bVar1 = DA_DACR;
                    /* D/A Control [sfr] */
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
  byte da_dacr;
  
  da_dacr = DA_DACR;
                    /* D/A Control [sfr] */
  DA_DACR = da_dacr & 0xbf;
  return;
}


// ===== dac0_write @ fff9283d (19 bytes)

/* DADR0 = v & 0xFFF */

void dac0_write(ushort param_1)

{
                    /* D/A Data 0 [sfr] */
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
  byte bVar1;
  ushort uVar2;
  uint system_mstpcra;
  
                    /* Module Stop Control A [sfr] */
  system_mstpcra = SYSTEM_MSTPCRA;
  SYSTEM_MSTPCRA = system_mstpcra & 0xfffdffff;
                    /* A/D Control [sfr] */
  uVar2 = S12AD_ADCSR;
  S12AD_ADCSR = uVar2 & 0xefff;
                    /* A/D Comparison Function Control [sfr] */
  uVar2 = S12AD_ADCMPCR;
  S12AD_ADCMPCR = uVar2 & 0x7fff;
  uVar2 = S12AD_ADCMPCR;
  S12AD_ADCMPCR = uVar2 & 0xdfff;
  bVar1 = ICU_IER17;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER17 = bVar1 & 0xfb;
  S12AD_ADCSR = 0;
                    /* A/D Disconnection Detection Control [sfr] */
  S12AD_ADDISCR = 0;
                    /* A/D Sampling State 1 [sfr] */
  S12AD_ADSSTR1 = 0xb;
                    /* A/D Sampling State 2 [sfr] */
  S12AD_ADSSTR2 = 0xb;
                    /* A/D Sampling State 3 [sfr] */
  S12AD_ADSSTR3 = 0xb;
                    /* A/D Sampling State 5 [sfr] */
  S12AD_ADSSTR5 = 0xb;
                    /* A/D Sampling State 6 [sfr] */
  S12AD_ADSSTR6 = 0xb;
                    /* A/D Sampling State 7 [sfr] */
  S12AD_ADSSTR7 = 0xb;
                    /* A/D Channel Select A0 [sfr] */
  S12AD_ADANSA0 = 0xee;
                    /* A/D-Converted Value Addition/Average Function ... [sfr] */
  S12AD_ADADS0 = 0xe8;
                    /* A/D Sample-and-Hold Circuit Control [sfr] */
  S12AD_ADSHCR = 0x618;
                    /* A/D Control Extended [sfr] */
  S12AD_ADCER = 0;
  uVar2 = S12AD_ADCSR;
  S12AD_ADCSR = uVar2 | 0x1000;
                    /* A/D-Converted Value Addition/Average Count Select [sfr] */
  S12AD_ADADC = 0x83;
  S12AD_ADCMPCR = 0;
                    /* Software Configurable Interrupt B Source Select ... [sfr] */
  ICU_SLIBR186 = 0x40;
                    /* Interrupt Source Priority 000 [sfr] */
  bVar1 = ICU_IPR186;
  ICU_IPR186 = bVar1 & 0xf6 | 6;
  bVar1 = PORT4_PMR;
                    /* Port Mode [sfr] */
  PORT4_PMR = bVar1 & 0xfd;
  bVar1 = PORT4_PDR;
                    /* Port Direction [sfr] */
  PORT4_PDR = bVar1 & 0xfd;
                    /* P41 Pin Function Control [sfr] */
  MPC_P41PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0xfb;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0xfb;
                    /* P42 Pin Function Control [sfr] */
  MPC_P42PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0xf7;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0xf7;
                    /* P43 Pin Function Control [sfr] */
  MPC_P43PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0xdf;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0xdf;
                    /* P45 Pin Function Control [sfr] */
  MPC_P45PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0xbf;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0xbf;
                    /* P46 Pin Function Control [sfr] */
  MPC_P46PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0x7f;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0x7f;
                    /* P47 Pin Function Control [sfr] */
  MPC_P47PFS = 0x80;
  R_S12AD0_Create_UserInit();
  return;
}


// ===== R_S12AD0_Start @ fff929f7 (28 bytes)

/* ADCSR.ADST=1 */

void R_S12AD0_Start(void)

{
  byte bVar1;
  ushort s12ad_adcsr;
  
  bVar1 = ICU_IR186;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
  ICU_IR186 = bVar1 & 0xfe;
  bVar1 = ICU_IER17;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER17 = bVar1 | 4;
                    /* A/D Control [sfr] */
  s12ad_adcsr = S12AD_ADCSR;
  S12AD_ADCSR = s12ad_adcsr | 0x8000;
  return;
}


// ===== R_S12AD0_Stop @ fff92a13 (30 bytes)

void R_S12AD0_Stop(void)

{
  byte bVar1;
  ushort s12ad_adcsr;
  
                    /* A/D Control [sfr] */
  s12ad_adcsr = S12AD_ADCSR;
  S12AD_ADCSR = s12ad_adcsr & 0x7fff;
  bVar1 = ICU_IR186;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
  ICU_IR186 = bVar1 & 0xfe;
  bVar1 = ICU_IER17;
                    /* Interrupt Request Enable 02 [sfr] */
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
                    /* A/D Data 0 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 1) {
    uVar1 = S12AD_ADDR1;
                    /* A/D Data 1 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 2) {
    uVar1 = S12AD_ADDR2;
                    /* A/D Data 2 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 3) {
    uVar1 = S12AD_ADDR3;
                    /* A/D Data 3 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 4) {
    uVar1 = S12AD_ADDR4;
                    /* A/D Data 4 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 5) {
    uVar1 = S12AD_ADDR5;
                    /* A/D Data 5 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 6) {
    uVar1 = S12AD_ADDR6;
                    /* A/D Data 6 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 7) {
    uVar1 = S12AD_ADDR7;
                    /* A/D Data 7 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 0x1a) {
    uVar1 = S12AD_ADDBLDRB;
                    /* A/D Data Duplication B [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 0x18) {
    uVar1 = S12AD_ADDBLDR;
                    /* A/D Data Duplication [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 == 0x19) {
    uVar1 = S12AD_ADDBLDRA;
                    /* A/D Data Duplication A [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  }
  if (param_1 != 0x15) {
    return;
  }
  uVar1 = S12AD_ADRD;
                    /* A/D Self-Diagnosis Data [sfr] */
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
  byte bVar1;
  ushort uVar2;
  uint system_mstpcra;
  
                    /* Module Stop Control A [sfr] */
  system_mstpcra = SYSTEM_MSTPCRA;
  SYSTEM_MSTPCRA = system_mstpcra & 0xfffeffff;
                    /* A/D Control [sfr] */
  uVar2 = S12AD1_ADCSR;
  S12AD1_ADCSR = uVar2 & 0xefff;
                    /* A/D Comparison Function Control [sfr] */
  uVar2 = S12AD1_ADCMPCR;
  S12AD1_ADCMPCR = uVar2 & 0x7fff;
  uVar2 = S12AD1_ADCMPCR;
  S12AD1_ADCMPCR = uVar2 & 0xdfff;
  bVar1 = ICU_IER17;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER17 = bVar1 & 0xdf;
                    /* A/D Disconnection Detection Control [sfr] */
  S12AD1_ADDISCR = 0;
  S12AD1_ADCSR = 0x5000;
                    /* A/D Control Extended [sfr] */
  S12AD1_ADCER = 0;
                    /* A/D-Converted Value Addition/Average Count Select [sfr] */
  S12AD1_ADADC = 0x83;
                    /* A/D Channel Select A0 [sfr] */
  S12AD1_ADANSA0 = 0x8300;
                    /* A/D Channel Select A1 [sfr] */
  S12AD1_ADANSA1 = 2;
                    /* A/D-Converted Value Addition/Average Function ... [sfr] */
  S12AD1_ADADS0 = 0x8300;
                    /* A/D-Converted Value Addition/Average Function ... [sfr] */
  S12AD1_ADADS1 = 2;
                    /* A/D Sampling State 8 [sfr] */
  S12AD1_ADSSTR8 = 0xb;
                    /* A/D Sampling State 9 [sfr] */
  S12AD1_ADSSTR9 = 0xb;
                    /* A/D Sampling State 15 [sfr] */
  S12AD1_ADSSTR15 = 0xb;
                    /* A/D Sampling State L [sfr] */
  S12AD1_ADSSTRL = 0xb;
  S12AD1_ADCMPCR = 0;
                    /* Software Configurable Interrupt B Source Select ... [sfr] */
  ICU_SLIBR189 = 0x44;
                    /* Interrupt Source Priority 000 [sfr] */
  bVar1 = ICU_IPR189;
  ICU_IPR189 = bVar1 & 0xf6 | 6;
  bVar1 = PORTD_PMR;
                    /* Port Mode [sfr] */
  PORTD_PMR = bVar1 & 0xfe;
  bVar1 = PORTD_PDR;
                    /* Port Direction [sfr] */
  PORTD_PDR = bVar1 & 0xfe;
                    /* PD0 Pin Function Control [sfr] */
  MPC_PD0PFS = 0x80;
  bVar1 = PORTD_PMR;
  PORTD_PMR = bVar1 & 0xfd;
  bVar1 = PORTD_PDR;
  PORTD_PDR = bVar1 & 0xfd;
                    /* PD1 Pin Function Control [sfr] */
  MPC_PD1PFS = 0x80;
  bVar1 = PORT9_PMR;
                    /* Port Mode [sfr] */
  PORT9_PMR = bVar1 & 0xfd;
  bVar1 = PORT9_PDR;
                    /* Port Direction [sfr] */
  PORT9_PDR = bVar1 & 0xfd;
                    /* P91 Pin Function Control [sfr] */
  MPC_P91PFS = 0x80;
  bVar1 = PORT9_PMR;
  PORT9_PMR = bVar1 & 0xf7;
  bVar1 = PORT9_PDR;
  PORT9_PDR = bVar1 & 0xf7;
                    /* P93 Pin Function Control [sfr] */
  MPC_P93PFS = 0x80;
  R_S12AD1_Create_UserInit();
  return;
}


// ===== R_S12AD1_Start @ fff92c74 (28 bytes)

void R_S12AD1_Start(void)

{
  byte bVar1;
  ushort s12ad1_adcsr;
  
  bVar1 = ICU_IR189;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
  ICU_IR189 = bVar1 & 0xfe;
  bVar1 = ICU_IER17;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER17 = bVar1 | 0x20;
                    /* A/D Control [sfr] */
  s12ad1_adcsr = S12AD1_ADCSR;
  S12AD1_ADCSR = s12ad1_adcsr | 0x8000;
  return;
}


// ===== R_S12AD1_Stop @ fff92c90 (30 bytes)

void R_S12AD1_Stop(void)

{
  byte bVar1;
  ushort s12ad1_adcsr;
  
                    /* A/D Control [sfr] */
  s12ad1_adcsr = S12AD1_ADCSR;
  S12AD1_ADCSR = s12ad1_adcsr & 0x7fff;
  bVar1 = ICU_IER17;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER17 = bVar1 & 0xdf;
  bVar1 = ICU_IR189;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
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
                    /* A/D Data 0 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 1:
    uVar1 = S12AD1_ADDR1;
                    /* A/D Data 1 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 2:
    uVar1 = S12AD1_ADDR2;
                    /* A/D Data 2 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 3:
    uVar1 = S12AD1_ADDR3;
                    /* A/D Data 3 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 4:
    uVar1 = S12AD1_ADDR4;
                    /* A/D Data 4 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 5:
    uVar1 = S12AD1_ADDR5;
                    /* A/D Data 5 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 6:
    uVar1 = S12AD1_ADDR6;
                    /* A/D Data 6 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 7:
    uVar1 = S12AD1_ADDR7;
                    /* A/D Data 7 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 8:
    uVar1 = S12AD1_ADDR8;
                    /* A/D Data 8 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 9:
    uVar1 = S12AD1_ADDR9;
                    /* A/D Data 9 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 10:
    uVar1 = S12AD1_ADDR10;
                    /* A/D Data 10 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xb:
    uVar1 = S12AD1_ADDR11;
                    /* A/D Data 11 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xc:
    uVar1 = S12AD1_ADDR12;
                    /* A/D Data 12 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xd:
    uVar1 = S12AD1_ADDR13;
                    /* A/D Data 13 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xe:
    uVar1 = S12AD1_ADDR14;
                    /* A/D Data 14 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0xf:
    uVar1 = S12AD1_ADDR15;
                    /* A/D Data 15 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x10:
    uVar1 = S12AD1_ADDR16;
                    /* A/D Data 16 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x11:
    uVar1 = S12AD1_ADDR17;
                    /* A/D Data 17 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x12:
    uVar1 = S12AD1_ADDR18;
                    /* A/D Data 18 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x13:
    uVar1 = S12AD1_ADDR19;
                    /* A/D Data 19 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x14:
    uVar1 = S12AD1_ADDR20;
                    /* A/D Data 20 [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x15:
    uVar1 = S12AD1_ADRD;
                    /* A/D Self-Diagnosis Data [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x16:
    uVar1 = S12AD1_ADTSDR;
                    /* A/D Temperature Sensor Data [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x17:
    uVar1 = S12AD1_ADOCDR;
                    /* A/D Internal Reference Voltage Data [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x18:
    uVar1 = S12AD1_ADDBLDR;
                    /* A/D Data Duplication [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x19:
    uVar1 = S12AD1_ADDBLDRA;
                    /* A/D Data Duplication A [sfr] */
    *(undefined2 *)param_2 = uVar1;
    return;
  case 0x1a:
    uVar1 = S12AD1_ADDBLDRB;
                    /* A/D Data Duplication B [sfr] */
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
  
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER08 = 0;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER09 = 0;
  bVar1 = ICU_IER03;
                    /* Interrupt Request Enable 02 [sfr] */
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
                    /* Open-Drain Control 0 [sfr] */
  PORT0_ODR0 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORT0_PCR = 0xa4;
                    /* Drive Capacity Control [sfr] */
  PORT0_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORT0_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORT0_PMR = 0;
                    /* Port Direction [sfr] */
  PORT0_PDR = 0x50;
                    /* Open-Drain Control 0 [sfr] */
  PORT1_ODR0 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORT1_PCR = 0;
                    /* Drive Capacity Control [sfr] */
  PORT1_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORT1_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORT1_PMR = 0;
                    /* Port Direction [sfr] */
  PORT1_PDR = 3;
                    /* Port Output Data [sfr] */
  PORT2_PODR = 0;
                    /* Open-Drain Control 0 [sfr] */
  PORT2_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORT2_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORT2_PCR = 3;
                    /* Drive Capacity Control [sfr] */
  PORT2_DSCR = 0xc;
                    /* Drive Capacity Control 2 [sfr] */
  PORT2_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORT2_PMR = 0;
                    /* Port Direction [sfr] */
  PORT2_PDR = 0x14;
                    /* Open-Drain Control 0 [sfr] */
  PORT3_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORT3_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORT3_PCR = 0x12;
                    /* Drive Capacity Control 2 [sfr] */
  PORT3_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORT3_PMR = 0;
                    /* Port Direction [sfr] */
  PORT3_PDR = 0;
                    /* Open-Drain Control 0 [sfr] */
  PORT4_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORT4_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORT4_PCR = 0x11;
                    /* Port Mode [sfr] */
  PORT4_PMR = 0;
                    /* Port Direction [sfr] */
  PORT4_PDR = 0;
                    /* Port Output Data [sfr] */
  PORT5_PODR = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORT5_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORT5_PCR = 0x1e;
                    /* Drive Capacity Control [sfr] */
  PORT5_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORT5_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORT5_PMR = 0;
                    /* Port Direction [sfr] */
  PORT5_PDR = 0xc0;
                    /* Port Output Data [sfr] */
  PORT6_PODR = 0;
                    /* Open-Drain Control 0 [sfr] */
  PORT6_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORT6_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORT6_PCR = 0x17;
                    /* Port Mode [sfr] */
  PORT6_PMR = 0;
                    /* Port Direction [sfr] */
  PORT6_PDR = 0xe8;
                    /* Port Output Data [sfr] */
  PORT7_PODR = 0x40;
                    /* Open-Drain Control 0 [sfr] */
  PORT7_ODR0 = 4;
                    /* Open-Drain Control 1 [sfr] */
  PORT7_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORT7_PCR = 0;
                    /* Drive Capacity Control [sfr] */
  PORT7_DSCR = 9;
                    /* Drive Capacity Control 2 [sfr] */
  PORT7_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORT7_PMR = 0;
                    /* Port Direction [sfr] */
  PORT7_PDR = 0xdf;
                    /* Port Output Data [sfr] */
  PORT8_PODR = 0x40;
                    /* Open-Drain Control 0 [sfr] */
  PORT8_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORT8_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORT8_PCR = 0;
                    /* Drive Capacity Control [sfr] */
  PORT8_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORT8_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORT8_PMR = 0;
                    /* Port Direction [sfr] */
  PORT8_PDR = 0x7f;
                    /* Open-Drain Control 0 [sfr] */
  PORT9_ODR0 = 0;
                    /* Drive Capacity Control [sfr] */
  PORT9_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORT9_DSCR2 = 0;
                    /* Port Output Data [sfr] */
  PORTA_PODR = 0;
                    /* Open-Drain Control 0 [sfr] */
  PORTA_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORTA_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORTA_PCR = 8;
                    /* Drive Capacity Control [sfr] */
  PORTA_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORTA_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORTA_PMR = 0;
                    /* Port Direction [sfr] */
  PORTA_PDR = 0xf7;
                    /* Port Output Data [sfr] */
  PORTB_PODR = 0;
                    /* Open-Drain Control 0 [sfr] */
  PORTB_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORTB_ODR1 = 0;
                    /* Drive Capacity Control [sfr] */
  PORTB_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORTB_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORTB_PMR = 0;
                    /* Port Direction [sfr] */
  PORTB_PDR = 0xfc;
                    /* Port Output Data [sfr] */
  PORTC_PODR = 0x10;
                    /* Open-Drain Control 0 [sfr] */
  PORTC_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORTC_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORTC_PCR = 2;
                    /* Drive Capacity Control [sfr] */
  PORTC_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORTC_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORTC_PMR = 0;
                    /* Port Direction [sfr] */
  PORTC_PDR = 0x11;
                    /* Port Output Data [sfr] */
  PORTD_PODR = 0;
                    /* Open-Drain Control 0 [sfr] */
  PORTD_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORTD_ODR1 = 0;
                    /* Drive Capacity Control [sfr] */
  PORTD_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORTD_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORTD_PMR = 0;
                    /* Port Direction [sfr] */
  PORTD_PDR = 0xfc;
                    /* Port Output Data [sfr] */
  PORTE_PODR = 0;
                    /* Open-Drain Control 0 [sfr] */
  PORTE_ODR0 = 0;
                    /* Open-Drain Control 1 [sfr] */
  PORTE_ODR1 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORTE_PCR = 8;
                    /* Drive Capacity Control [sfr] */
  PORTE_DSCR = 0;
                    /* Drive Capacity Control 2 [sfr] */
  PORTE_DSCR2 = 0;
                    /* Port Mode [sfr] */
  PORTE_PMR = 0;
                    /* Port Direction [sfr] */
  PORTE_PDR = 0x77;
                    /* Pull-Up Resistor Control [sfr] */
  PORTF_PCR = 0x20;
                    /* Port Mode [sfr] */
  PORTF_PMR = 0;
                    /* Port Direction [sfr] */
  PORTF_PDR = 0xdf;
                    /* Port Output Data [sfr] */
  PORTJ_PODR = 0;
                    /* Open-Drain Control 0 [sfr] */
  PORTJ_ODR0 = 0;
                    /* Pull-Up Resistor Control [sfr] */
  PORTJ_PCR = 0x20;
                    /* Port Mode [sfr] */
  PORTJ_PMR = 0;
                    /* Port Direction [sfr] */
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
  byte bVar1;
  uint system_mstpcrb;
  
                    /* Module Stop Control B [sfr] */
  system_mstpcrb = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = system_mstpcrb & 0x7fffffff;
                    /* Interrupt Source Priority 000 [sfr] */
  bVar1 = ICU_IPR058;
  ICU_IPR058 = bVar1 & 0xf8 | 8;
                    /* Interrupt Source Priority 000 [sfr] */
  bVar1 = ICU_IPR059;
  ICU_IPR059 = bVar1 & 0xf8 | 8;
                    /* Serial Control [sfr] */
  SCI0_SCR = 0;
  SCI0_SCR = 0;
  bVar1 = SCI0_SIMR1;
                    /* I2C Mode 1 [sfr] */
  SCI0_SIMR1 = bVar1 & 0xfe;
                    /* SPI Mode [sfr] */
  SCI0_SPMR = 0;
                    /* Serial Mode [sfr] */
  SCI0_SMR = 1;
                    /* Smart Card Mode [sfr] */
  SCI0_SCMR = 0x72;
                    /* Serial Extended Mode [sfr] */
  SCI0_SEMR = 0x10;
                    /* Bit Rate [sfr] */
  SCI0_BRR = 0xc2;
                    /* P33 Pin Function Control [sfr] */
  MPC_P33PFS = 0xb;
                    /* Port Mode [sfr] */
  bVar1 = PORT3_PMR;
  PORT3_PMR = bVar1 | 8;
                    /* P32 Pin Function Control [sfr] */
  MPC_P32PFS = 0xb;
                    /* Port Output Data [sfr] */
  bVar1 = PORT3_PODR;
  PORT3_PODR = bVar1 | 4;
                    /* Port Direction [sfr] */
  bVar1 = PORT3_PDR;
  PORT3_PDR = bVar1 | 4;
  R_SCI0_Create_UserInit();
  return;
}


// ===== R_SCI0_Start @ fff932c2 (64 bytes)

void R_SCI0_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR059;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
  ICU_IR059 = bVar1 & 0xfe;
  bVar1 = ICU_IR058;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
  ICU_IR058 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER07 = bVar1 | 8;
                    /* Group BL0 Interrupt Request Enable [sfr] */
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
                    /* Port Mode [sfr] */
  PORT3_PMR = bVar1 & 0xfb;
  bVar1 = SCI0_SCR;
                    /* Serial Control [sfr] */
  SCI0_SCR = bVar1 & 0xdf;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0xef;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0x7f;
  bVar1 = SCI0_SCR;
  SCI0_SCR = bVar1 & 0xbf;
  bVar1 = ICU_IER07;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER07 = bVar1 & 0xf7;
                    /* Group BL0 Interrupt Request Enable [sfr] */
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffffe;
  bVar1 = ICU_IR059;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
  ICU_IR059 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 & 0xfb;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffffd;
  bVar1 = ICU_IR058;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
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
                    /* Serial Control [sfr] */
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
                    /* Interrupt Request Enable 02 [sfr] */
      ICU_IER07 = bVar1 & 0xf7;
      bVar1 = SCI0_SCR;
                    /* Serial Control [sfr] */
      SCI0_SCR = bVar1 | 0xa0;
                    /* Port Mode [sfr] */
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
                    /* Serial Control [sfr] */
    SCI0_SCR = bVar1 & 0x7f;
    bVar1 = SCI0_SCR;
    SCI0_SCR = bVar1 | 4;
    return;
  }
                    /* Transmit Data [sfr] */
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
                    /* Port Mode [sfr] */
  PORT3_PMR = bVar1 & 0xfb;
  bVar1 = SCI0_SCR;
                    /* Serial Control [sfr] */
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
  undefined1 sci0_rdr;
  
  if (DAT_0001b606 < DAT_0001b608) {
    sci0_rdr = SCI0_RDR;
                    /* Receive Data [sfr] */
    *DAT_000207f8 = sci0_rdr;
    r_sci0_rx_byte_hook();
    DAT_000207f8 = DAT_000207f8 + 1;
    DAT_0001b606 = DAT_0001b606 + 1;
  }
  if (DAT_0001b608 <= DAT_0001b606) {
    bVar1 = SCI0_SCR;
                    /* Serial Control [sfr] */
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
  byte sci0_ssr;
  
  r_sci0_callback_receiveerror();
                    /* Serial Status [sfr] */
  sci0_ssr = SCI0_SSR;
  SCI0_SSR = sci0_ssr & 199 | 0xc0;
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
  byte bVar1;
  uint system_mstpcrb;
  
                    /* Module Stop Control B [sfr] */
  system_mstpcrb = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = system_mstpcrb & 0xbfffffff;
                    /* Interrupt Source Priority 000 [sfr] */
  bVar1 = ICU_IPR060;
  ICU_IPR060 = bVar1 & 0xfa | 10;
                    /* Interrupt Source Priority 000 [sfr] */
  bVar1 = ICU_IPR061;
  ICU_IPR061 = bVar1 & 0xfa | 10;
                    /* Serial Control [sfr] */
  SCI1_SCR = 0;
  SCI1_SCR = 0;
  bVar1 = SCI1_SIMR1;
                    /* I2C Mode 1 [sfr] */
  SCI1_SIMR1 = bVar1 & 0xfe;
                    /* SPI Mode [sfr] */
  SCI1_SPMR = 0;
                    /* Serial Mode [sfr] */
  SCI1_SMR = 8;
                    /* Smart Card Mode [sfr] */
  SCI1_SCMR = 0x72;
                    /* Serial Extended Mode [sfr] */
  SCI1_SEMR = 0x10;
                    /* Bit Rate [sfr] */
  SCI1_BRR = 10;
                    /* P30 Pin Function Control [sfr] */
  MPC_P30PFS = 10;
                    /* Port Mode [sfr] */
  bVar1 = PORT3_PMR;
  PORT3_PMR = bVar1 | 1;
                    /* P26 Pin Function Control [sfr] */
  MPC_P26PFS = 10;
                    /* Port Output Data [sfr] */
  bVar1 = PORT2_PODR;
  PORT2_PODR = bVar1 | 0x40;
                    /* Port Direction [sfr] */
  bVar1 = PORT2_PDR;
  PORT2_PDR = bVar1 | 0x40;
  R_SCI1_Create_UserInit();
  return;
}


// ===== R_SCI1_Start @ fff935ef (64 bytes)

void R_SCI1_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR061;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
  ICU_IR061 = bVar1 & 0xfe;
  bVar1 = ICU_IR060;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
  ICU_IR060 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER07 = bVar1 | 0x20;
                    /* Group BL0 Interrupt Request Enable [sfr] */
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
                    /* Port Mode [sfr] */
  PORT2_PMR = bVar1 & 0xbf;
  bVar1 = SCI1_SCR;
                    /* Serial Control [sfr] */
  SCI1_SCR = bVar1 & 0xdf;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0xef;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0x7f;
  bVar1 = SCI1_SCR;
  SCI1_SCR = bVar1 & 0xbf;
  bVar1 = ICU_IER07;
                    /* Interrupt Request Enable 02 [sfr] */
  ICU_IER07 = bVar1 & 0xdf;
                    /* Group BL0 Interrupt Request Enable [sfr] */
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffffb;
  bVar1 = ICU_IR061;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
  ICU_IR061 = bVar1 & 0xfe;
  bVar1 = ICU_IER07;
  ICU_IER07 = bVar1 & 0xef;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xfffffff7;
  bVar1 = ICU_IR060;
                    /* Interrupt Request 016 to Interrupt Request 255 [sfr] */
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
                    /* Serial Control [sfr] */
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
                    /* Interrupt Request Enable 02 [sfr] */
      ICU_IER07 = bVar1 & 0xdf;
      bVar1 = SCI1_SCR;
                    /* Serial Control [sfr] */
      SCI1_SCR = bVar1 | 0xa0;
                    /* Port Mode [sfr] */
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
                    /* Serial Control [sfr] */
    SCI1_SCR = bVar1 & 0x7f;
    bVar1 = SCI1_SCR;
    SCI1_SCR = bVar1 | 4;
    return;
  }
                    /* Transmit Data [sfr] */
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
                    /* Port Mode [sfr] */
  PORT2_PMR = bVar1 & 0xbf;
  bVar1 = SCI1_SCR;
                    /* Serial Control [sfr] */
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
  undefined1 sci1_rdr;
  
  if (DAT_0001b60c < DAT_0001b60e) {
    sci1_rdr = SCI1_RDR;
                    /* Receive Data [sfr] */
    *DAT_00020800 = sci1_rdr;
    displink_rx_frame_len();
    DAT_00020800 = DAT_00020800 + 1;
    DAT_0001b60c = DAT_0001b60c + 1;
  }
  if (DAT_0001b60e <= DAT_0001b60c) {
    bVar1 = SCI1_SCR;
                    /* Serial Control [sfr] */
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
  byte sci1_ssr;
  
  r_sci1_callback_receiveerror();
                    /* Serial Status [sfr] */
  sci1_ssr = SCI1_SSR;
  SCI1_SSR = sci1_ssr & 199 | 0xc0;
  return;
}


// ===== r_sci1_callback_transmitend @ fff93845 (1 bytes)

/* empty */

void r_sci1_callback_transmitend(void)

{
  return;
}

