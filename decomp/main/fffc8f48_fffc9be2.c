// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc8f48 @ fffc8f48 (67 bytes)

void FUN_fffc8f48(void)

{
  byte bVar1;
  
  if (((PTR_g_ui_00025d5c->dl_block_7a != 0) && (bVar1 = swtimer_expired(0x43), bVar1 == 1)) &&
     (PTR_g_ui_00025d5c->dl_block_7a = 0, PTR_g_ui_00025d5c->dl_req_50 == 1)) {
    PTR_g_ui_00025d5c->dl_req_sd = 1;
    return;
  }
  return;
}


// ===== FUN_fffc8f8b @ fffc8f8b (27 bytes)

void FUN_fffc8f8b(ushort param_1)

{
  PTR_g_ui_00025d5c->dl_block_7a = 1;
  swtimer_start(0x43,param_1);
  return;
}


// ===== FUN_fffc8fa6 @ fffc8fa6 (83 bytes)

void FUN_fffc8fa6(void)

{
  byte bVar1;
  
  if ((PTR_g_ui_00025d5c->func_panel_open != 0) && (bVar1 = swtimer_expired(0x44), bVar1 == 1)) {
    PTR_g_ui_00025d5c->func_panel_open = 0;
    PTR_g_ui_00025d5c->func_blink_en = 0;
    PTR_g_ui_00025d5c->func_blink_on = 1;
    DAT_0001b4f3 = 1;
    swtimer_start(0x49,200);
    return;
  }
  return;
}


// ===== FUN_fffc8ff9 @ fffc8ff9 (77 bytes)

void FUN_fffc8ff9(void)

{
  byte bVar1;
  
  if (((PTR_g_ui_00025d5c->func_panel_open != 0) && (PTR_g_ui_00025d5c->func_blink_en != 0)) &&
     (bVar1 = swtimer_expired(0x45), bVar1 == 1)) {
    if (PTR_g_ui_00025d5c->func_blink_on == 0) {
      PTR_g_ui_00025d5c->func_blink_on = 1;
    }
    else {
      PTR_g_ui_00025d5c->func_blink_on = 0;
    }
    swtimer_start(0x45,0x1c2);
    return;
  }
  return;
}


// ===== FUN_fffc9046 @ fffc9046 (62 bytes)

void FUN_fffc9046(void)

{
  byte bVar1;
  
  if ((PTR_g_ui_00025d5c->lamp_restore_req != 0) && (bVar1 = swtimer_expired(0x41), bVar1 == 1)) {
    PTR_g_ui_00025d5c->lamp_restore_req = 0;
    ui_lamp_set(DAT_00012233,DAT_00012234);
    return;
  }
  return;
}


// ===== FUN_fffc9084 @ fffc9084 (27 bytes)

void FUN_fffc9084(void)

{
  byte bVar1;
  
  if ((DAT_0001b4f2 != '\0') && (bVar1 = swtimer_expired(0x48), bVar1 == 1)) {
    popup_mark_clear();
    return;
  }
  return;
}


// ===== popup_mark_start @ fffc909f (21 bytes)

/* 0x1B4F2 = 1, soft timer 0x48 = 750 [fact]; what the mark shows [unknown] */

void popup_mark_start(void)

{
  DAT_0001b4f2 = 1;
  swtimer_start(0x48,0x2ee);
  return;
}


// ===== popup_mark_clear @ fffc90b4 (23 bytes)

/* 0x1B4F2 = 0, UI +0x1C3 = 0 [fact] */

void popup_mark_clear(void)

{
  DAT_0001b4f2 = 0;
  PTR_g_ui_00025d5c->popup_sel = 0;
  return;
}


// ===== FUN_fffc90cb @ fffc90cb (34 bytes)

void FUN_fffc90cb(void)

{
  byte bVar1;
  
  if ((DAT_0001b4f3 == '\x01') && (bVar1 = swtimer_expired(0x49), bVar1 == 1)) {
    DAT_0001b4f3 = 0;
    return;
  }
  return;
}


// ===== FUN_fffc90ed @ fffc90ed (15 bytes)

undefined1 FUN_fffc90ed(void)

{
  return DAT_0001b4f3;
}


// ===== FUN_fffc90fc @ fffc90fc (34 bytes)

void FUN_fffc90fc(void)

{
  byte bVar1;
  
  if ((DAT_0001b4f4 == '\x01') && (bVar1 = swtimer_expired(0x4a), bVar1 == 1)) {
    DAT_0001b4f4 = 0;
    return;
  }
  return;
}


// ===== FUN_fffc911e @ fffc911e (15 bytes)

undefined1 FUN_fffc911e(void)

{
  return DAT_0001b4f4;
}


// ===== FUN_fffc912d @ fffc912d (14 bytes)

void FUN_fffc912d(undefined1 param_1)

{
  DAT_0001b4f4 = param_1;
  return;
}


// ===== R_MTU2_Create @ fffc913b (103 bytes)

/* MTU2 PWM on P27/MTIOC2B (TGRA=11999); never started (no TSTR.CST2 write) */

void R_MTU2_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = SYSTEM_MSTPCRA;
  SYSTEM_MSTPCRA = uVar1 & 0xfffffdff;
  bVar2 = MTU_TSTRA;
  MTU_TSTRA = bVar2 & 0xfb;
  bVar2 = MTU_TSYRA;
  MTU_TSYRA = bVar2 & 0xfb;
  MTU2_TCR = 0x40;
  MTU2_TCR2 = 0;
  MTU2_TIER = 0;
  MTU2_TIOR = 0x30;
  MTU2_TGRA = 11999;
  MTU2_TGRB = 0x726;
  MPC_P27PFS = 1;
  bVar2 = PORT2_PMR;
  PORT2_PMR = bVar2 | 0x80;
  R_MTU2_Create_UserInit();
  return;
}


// ===== R_MTU2_Start @ fffc91a2 (8 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): MTU.TSTRA
   (0xC1280) CST2 (bit 2) on; after R_MTU2_Create [inference] */

void R_MTU2_Start(void)

{
  byte bVar1;
  
  bVar1 = MTU_TSTRA;
  MTU_TSTRA = bVar1 | 4;
  return;
}


// ===== R_MTU2_Stop @ fffc91aa (8 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): MTU.TSTRA
   CST2 off [inference] */

void R_MTU2_Stop(void)

{
  byte bVar1;
  
  bVar1 = MTU_TSTRA;
  MTU_TSTRA = bVar1 & 0xfb;
  return;
}


// ===== R_MTU2_Create_UserInit @ fffc91b2 (1 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): empty rts,
   called last by R_MTU2_Create [inference] */

void R_MTU2_Create_UserInit(void)

{
  return;
}


// ===== R_SCI6_Create_IIC @ fffc91b3 (213 bytes)

/* SCI6 in simple-I2C mode (SIMR3/SISR used) */

void R_SCI6_Create_IIC(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = uVar1 & 0xfdffffff;
  bVar2 = ICU_IPR086;
  ICU_IPR086 = bVar2 & 0xfa | 10;
  bVar2 = ICU_IPR087;
  ICU_IPR087 = bVar2 & 0xfa | 10;
  SCI6_SCR = 0;
  SCI6_SIMR3 = 0xf0;
  SCI6_SMR = 0;
  bVar2 = SCI6_SCMR;
  SCI6_SCMR = bVar2 & 0xfe;
  bVar2 = SCI6_SCMR;
  SCI6_SCMR = bVar2 & 0xfb;
  bVar2 = SCI6_SCMR;
  SCI6_SCMR = bVar2 | 8;
  SCI6_BRR = 0x12;
  SCI6_SEMR = 0;
  bVar2 = SCI6_SIMR1;
  SCI6_SIMR1 = bVar2 | 1;
  bVar2 = SCI6_SIMR2;
  SCI6_SIMR2 = bVar2 | 0x22;
  SCI6_SPMR = 0;
  SCI6_SCR = 0xf4;
  MPC_P01PFS = 10;
  bVar2 = PORT0_ODR0;
  PORT0_ODR0 = bVar2 | 4;
  bVar2 = PORT0_PMR;
  PORT0_PMR = bVar2 | 2;
  MPC_P00PFS = 10;
  bVar2 = PORT0_ODR0;
  PORT0_ODR0 = bVar2 | 1;
  bVar2 = PORT0_PMR;
  PORT0_PMR = bVar2 | 1;
  R_SCI6_Create_UserInit();
  return;
}


// ===== R_SCI6_Start @ fffc9288 (64 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): clears IR,
   sets IEN of SCI6 TXI/RXI (0x8720A bits 7/6) and ICU.GENBL0 bits 12/13; after R_SCI6_Create_IIC
   [inference] */

void R_SCI6_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR087;
  ICU_IR087 = bVar1 & 0xfe;
  bVar1 = ICU_IR086;
  ICU_IR086 = bVar1 & 0xfe;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 | 0x80;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x1000;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 | 0x40;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x2000;
  return;
}


// ===== R_SCI6_Stop @ fffc92c8 (64 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): reverse of
   R_SCI6_Start [inference] */

void R_SCI6_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR087;
  ICU_IR087 = bVar1 & 0xfe;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 & 0x7f;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xffffefff;
  bVar1 = ICU_IR086;
  ICU_IR086 = bVar1 & 0xfe;
  bVar1 = ICU_IER0A;
  ICU_IER0A = bVar1 & 0xbf;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xffffdfff;
  return;
}


// ===== R_SCI6_IIC_StartCondition @ fffc9308 (9 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): SCI6.SIMR3
   (0x8A0CB) = 0x51: IICSTAREQ with SDA/SCL as condition outputs [inference] */

void R_SCI6_IIC_StartCondition(void)

{
  SCI6_SIMR3 = 0x51;
  return;
}


// ===== R_SCI6_IIC_StopCondition @ fffc9311 (9 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): SCI6.SIMR3
   = 0x54: IICSTPREQ; was sci6_iic_condition [inference] */

void R_SCI6_IIC_StopCondition(void)

{
  SCI6_SIMR3 = 0x54;
  return;
}


// ===== R_SCI6_IIC_Master_Send @ fffc931a (64 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): (adr,
   tx_buf, tx_num): mode 0x80 (send) in 0x12235, address byte, count, buffer, then
   R_SCI6_IIC_StartCondition [inference] */

void R_SCI6_IIC_Master_Send(undefined1 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    return;
  }
  DAT_00012235 = 0x80;
  DAT_00012236 = 0x80;
  DAT_00012237 = param_1;
  DAT_0001fa42 = (short)param_3;
  DAT_0002104c = param_2;
  R_SCI6_IIC_StartCondition();
  return;
}


// ===== R_SCI6_IIC_Master_Receive @ fffc935a (73 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.900): (adr,
   rx_buf, rx_num): mode 0 (receive) in 0x12235, then R_SCI6_IIC_StartCondition [inference] */

void R_SCI6_IIC_Master_Receive(undefined1 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    return;
  }
  DAT_0001fa44 = 0;
  DAT_00012235 = 0;
  DAT_00012236 = 0x80;
  DAT_00012237 = param_1;
  DAT_0001fa46 = (short)param_3;
  DAT_00021050 = param_2;
  R_SCI6_IIC_StartCondition();
  return;
}


// ===== R_SCI6_Create_UserInit @ fffc93a3 (1 bytes)

/* empty */

void R_SCI6_Create_UserInit(void)

{
  return;
}


// ===== r_sci6_iic_txi @ fffc93a4 (75 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc93e9) */
/* WARNING: Removing unreachable block (ram,0xfffc93a4) */
/* WARNING: Removing unreachable block (ram,0xfffc93a6) */
/* WARNING: Removing unreachable block (ram,0xfffc93eb) */

void r_sci6_iic_txi(void)

{
  undefined1 uVar1;
  byte bVar2;
  
  bVar2 = SCI6_SISR;
  if ((bVar2 & 1) == 1) {
    uVar1 = SCI6_RDR;
    *DAT_00021050 = uVar1;
    DAT_00021050 = DAT_00021050 + 1;
    DAT_0001fa44 = DAT_0001fa44 + 1;
  }
  DAT_00012236 = 0;
  R_SCI6_IIC_StopCondition();
  return;
}


// ===== r_sci6_iic_tei @ fffc93ef (120 bytes)

/* TEI6 (cb 0x20), simple-I2C condition handling */

void r_sci6_iic_tei(void)

{
  byte bVar1;
  
  if (DAT_00012236 == -0x80) {
    bVar1 = SCI6_SIMR3;
    SCI6_SIMR3 = bVar1 & 0xf7;
    bVar1 = SCI6_SIMR3;
    SCI6_SIMR3 = bVar1 & 0x3f;
    bVar1 = SCI6_SIMR3;
    SCI6_SIMR3 = bVar1 & 0xcf;
    SCI6_TDR = DAT_00012237;
    return;
  }
  if (DAT_00012236 == '\0') {
    bVar1 = SCI6_SIMR3;
    SCI6_SIMR3 = bVar1 & 0xf7;
    bVar1 = SCI6_SIMR3;
    SCI6_SIMR3 = bVar1 | 0xf0;
    if (DAT_00012235 == -0x80) {
      r_sci6_callback_transmitend();
    }
    if (DAT_00012235 == '\0') {
      r_sci6_callback_receiveend();
      return;
    }
  }
  return;
}


// ===== r_sci6_iic_rxi @ fffc9467 (328 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc94bb) */
/* WARNING: Removing unreachable block (ram,0xfffc94d2) */
/* WARNING: Removing unreachable block (ram,0xfffc958c) */
/* WARNING: Removing unreachable block (ram,0xfffc95a9) */
/* WARNING: Removing unreachable block (ram,0xfffc95a3) */
/* WARNING: Removing unreachable block (ram,0xfffc9469) */
/* WARNING: Removing unreachable block (ram,0xfffc9467) */
/* WARNING: Removing unreachable block (ram,0xfffc95ab) */
/* WARNING: Removing unreachable block (ram,0xfffc958e) */
/* WARNING: Removing unreachable block (ram,0xfffc94d0) */
/* WARNING: Removing unreachable block (ram,0xfffc94bd) */
/* WARNING: Removing unreachable block (ram,0xfffc95a1) */

void r_sci6_iic_rxi(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  bVar1 = SCI6_SISR;
  if ((bVar1 & 1) != 0) {
    DAT_00012236 = 0;
    R_SCI6_IIC_StopCondition();
    return;
  }
  if (DAT_00012235 == -0x80) {
    if (DAT_0001fa42 != 0) {
      SCI6_TDR = *DAT_0002104c;
      DAT_0002104c = DAT_0002104c + 1;
      DAT_0001fa42 = DAT_0001fa42 + -1;
      return;
    }
    DAT_00012236 = 0;
    R_SCI6_IIC_StopCondition();
    return;
  }
  if (DAT_00012235 == '\0') {
    bVar1 = SCI6_SIMR2;
    if ((bVar1 & 0x20) == 0) {
      if (DAT_0001fa44 < DAT_0001fa46) {
        uVar2 = SCI6_RDR;
        *DAT_00021050 = uVar2;
        DAT_00021050 = DAT_00021050 + 1;
        DAT_0001fa44 = DAT_0001fa44 + 1;
      }
    }
    else {
      uVar2 = SCI6_RDR;
    }
    if (DAT_0001fa44 == 0) {
      if (DAT_0001fa46 == 1) {
        bVar1 = SCI6_SIMR2;
        SCI6_SIMR2 = bVar1 | 0x20;
      }
      else {
        bVar1 = SCI6_SIMR2;
        SCI6_SIMR2 = bVar1 & 0xdf;
        bVar1 = SCI6_SCR;
        SCI6_SCR = bVar1 | 0x40;
      }
    }
    else if ((uint)DAT_0001fa46 == DAT_0001fa44 + 1) {
      bVar1 = SCI6_SIMR2;
      SCI6_SIMR2 = bVar1 | 0x20;
    }
    SCI6_TDR = 0xff;
    return;
  }
  return;
}


// ===== r_sci6_callback_transmitend @ fffc95af (1 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.850): empty;
   called by r_sci6_iic_tei after the stop condition when the mode is send (0x80) [inference] */

void r_sci6_callback_transmitend(void)

{
  return;
}


// ===== r_sci6_callback_receiveend @ fffc95b0 (1 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.850): empty;
   called by r_sci6_iic_tei after the stop condition when the mode is receive (0) [inference] */

void r_sci6_callback_receiveend(void)

{
  return;
}


// ===== R_SCI7_Create @ fffc95b1 (163 bytes)

/* SCI7 init ("C4" peripheral link, probably the RT685 DSP) */

void R_SCI7_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = SYSTEM_MSTPCRB;
  SYSTEM_MSTPCRB = uVar1 & 0xfeffffff;
  bVar2 = ICU_IPR098;
  ICU_IPR098 = bVar2 & 0xfa | 10;
  bVar2 = ICU_IPR099;
  ICU_IPR099 = bVar2 & 0xfa | 10;
  SCI7_SCR = 0;
  SCI7_SCR = 0;
  bVar2 = SCI7_SIMR1;
  SCI7_SIMR1 = bVar2 & 0xfe;
  SCI7_SPMR = 0;
  SCI7_SMR = 0;
  SCI7_SCMR = 0x72;
  SCI7_SEMR = 0;
  SCI7_BRR = 0xc2;
  MPC_P92PFS = 10;
  bVar2 = PORT9_PMR;
  PORT9_PMR = bVar2 | 4;
  MPC_P90PFS = 10;
  bVar2 = PORT9_PODR;
  PORT9_PODR = bVar2 | 1;
  bVar2 = PORT9_PDR;
  PORT9_PDR = bVar2 | 1;
  R_SCI7_Create_UserInit();
  return;
}


// ===== R_SCI7_Start @ fffc9654 (64 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.950): clears IR,
   sets IEN of SCI7 TXI/RXI (0x8720C) and ICU.GENBL0 TEI/ERI bits 14/15 (0x87670); 64 B like
   R_SCIn_Start, after R_SCI7_Create [inference] */

void R_SCI7_Start(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = ICU_IR099;
  ICU_IR099 = bVar1 & 0xfe;
  bVar1 = ICU_IR098;
  ICU_IR098 = bVar1 & 0xfe;
  bVar1 = ICU_IER0C;
  ICU_IER0C = bVar1 | 8;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x4000;
  bVar1 = ICU_IER0C;
  ICU_IER0C = bVar1 | 4;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 | 0x8000;
  return;
}


// ===== R_SCI7_Stop @ fffc9694 (104 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.950): reverse of
   R_SCI7_Start plus SCI7.SCR (0x8A0E2); 104 B like the other R_SCIn_Stop [inference] */

void R_SCI7_Stop(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = PORT9_PMR;
  PORT9_PMR = bVar1 & 0xfe;
  bVar1 = SCI7_SCR;
  SCI7_SCR = bVar1 & 0xdf;
  bVar1 = SCI7_SCR;
  SCI7_SCR = bVar1 & 0xef;
  bVar1 = SCI7_SCR;
  SCI7_SCR = bVar1 & 0x7f;
  bVar1 = SCI7_SCR;
  SCI7_SCR = bVar1 & 0xbf;
  bVar1 = ICU_IER0C;
  ICU_IER0C = bVar1 & 0xf7;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xffffbfff;
  bVar1 = ICU_IR099;
  ICU_IR099 = bVar1 & 0xfe;
  bVar1 = ICU_IER0C;
  ICU_IER0C = bVar1 & 0xfb;
  uVar2 = ICU_GENBL0;
  ICU_GENBL0 = uVar2 & 0xffff7fff;
  bVar1 = ICU_IR098;
  ICU_IR098 = bVar1 & 0xfe;
  return;
}


// ===== R_SCI7_Serial_Receive @ fffc96fc (68 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.950): (buf, num):
   0x81 (MD_ARGERROR) when num == 0, sets SCR RIE|RE (0x8A0E2 |= 0x50); same 68 B shape as
   R_SCIn_Serial_Receive [inference] */

undefined2 R_SCI7_Serial_Receive(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    DAT_0001fa4a = 0;
    bVar1 = SCI7_SCR;
    SCI7_SCR = bVar1 | 0x40;
    bVar1 = SCI7_SCR;
    SCI7_SCR = bVar1 | 0x10;
    DAT_0001fa4c = param_2;
    DAT_00021058 = param_1;
  }
  return local_a;
}


// ===== R_SCI7_Serial_Send @ fffc9740 (95 bytes)

/* T23d Renesas Code Generator r_cg_* / Smart Configurator (RX651) (cg_registers 0.950): (buf, num):
   0x81 when num == 0, 0x80 when busy, SCR TIE|TE (|= 0xA0); same shape as R_SCIn_Serial_Send
   [inference] */

undefined2 R_SCI7_Serial_Send(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 local_a;
  
  local_a = 0;
  if (param_2 == 0) {
    local_a = 0x81;
  }
  else {
    bVar1 = ICU_IER0C;
    if ((bVar1 & 8) == 0) {
      local_a = 0x80;
    }
    else {
      bVar1 = ICU_IER0C;
      ICU_IER0C = bVar1 & 0xf7;
      bVar1 = SCI7_SCR;
      SCI7_SCR = bVar1 | 0xa0;
      bVar1 = PORT9_PMR;
      PORT9_PMR = bVar1 | 1;
      bVar1 = ICU_IER0C;
      ICU_IER0C = bVar1 | 8;
      DAT_0001fa48 = param_2;
      DAT_00021054 = param_1;
    }
  }
  return local_a;
}


// ===== R_SCI7_Create_UserInit @ fffc979f (1 bytes)

/* empty */

void R_SCI7_Create_UserInit(void)

{
  return;
}


// ===== r_sci7_transmit_interrupt @ fffc97a0 (76 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc97d6) */
/* WARNING: Removing unreachable block (ram,0xfffc97a0) */
/* WARNING: Removing unreachable block (ram,0xfffc97e8) */

void r_sci7_transmit_interrupt(void)

{
  byte bVar1;
  
  if (DAT_0001fa48 == 0) {
    bVar1 = SCI7_SCR;
    SCI7_SCR = bVar1 & 0x7f;
    bVar1 = SCI7_SCR;
    SCI7_SCR = bVar1 | 4;
    return;
  }
  SCI7_TDR = *DAT_00021054;
  DAT_00021054 = DAT_00021054 + 1;
  DAT_0001fa48 = DAT_0001fa48 + -1;
  return;
}


// ===== r_sci7_transmitend_interrupt @ fffc97ec (37 bytes)

/* TEI7 (cb 0x22) */

void r_sci7_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = PORT9_PMR;
  PORT9_PMR = bVar1 & 0xfe;
  bVar1 = SCI7_SCR;
  SCI7_SCR = bVar1 & 0x7f;
  bVar1 = SCI7_SCR;
  SCI7_SCR = bVar1 & 0xdf;
  bVar1 = SCI7_SCR;
  SCI7_SCR = bVar1 & 0xfb;
  r_sci7_callback_transmitend();
  return;
}


// ===== r_sci7_receive_interrupt @ fffc9811 (111 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc9874) */
/* WARNING: Removing unreachable block (ram,0xfffc987c) */
/* WARNING: Removing unreachable block (ram,0xfffc987a) */
/* WARNING: Removing unreachable block (ram,0xfffc9811) */
/* WARNING: Removing unreachable block (ram,0xfffc9813) */
/* WARNING: Removing unreachable block (ram,0xfffc9876) */

void r_sci7_receive_interrupt(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_0001fa4a < DAT_0001fa4c) {
    uVar2 = SCI7_RDR;
    *DAT_00021058 = uVar2;
    DAT_00021058 = DAT_00021058 + 1;
    DAT_0001fa4a = DAT_0001fa4a + 1;
  }
  if (DAT_0001fa4c <= DAT_0001fa4a) {
    bVar1 = SCI7_SCR;
    SCI7_SCR = bVar1 & 0xbf;
    bVar1 = SCI7_SCR;
    SCI7_SCR = bVar1 & 0xef;
    r_sci7_callback_receiveend();
    return;
  }
  return;
}


// ===== r_sci7_receiveerror_interrupt @ fffc9880 (39 bytes)

/* ERI7 (cb 0x23) */

void r_sci7_receiveerror_interrupt(void)

{
  byte bVar1;
  
  r_sci7_callback_receiveerror();
  bVar1 = SCI7_SSR;
  SCI7_SSR = bVar1 & 199 | 0xc0;
  return;
}


// ===== r_sci7_callback_transmitend @ fffc98a7 (1 bytes)

/* empty */

void r_sci7_callback_transmitend(void)

{
  return;
}


// ===== r_sci7_callback_receiveend @ fffc98a8 (1 bytes)

/* empty (SCI7 is never started) */

void r_sci7_callback_receiveend(void)

{
  return;
}


// ===== r_sci7_callback_receiveerror @ fffc98a9 (1 bytes)

/* empty */

void r_sci7_callback_receiveerror(void)

{
  return;
}


// ===== menu_subsys_init @ fffc98aa (9 bytes)

/* app_main init: FUN_fffd405e (menu UI state) then menu_init */

void menu_subsys_init(void)

{
  FUN_fffd405e();
  menu_init();
  return;
}


// ===== FUN_fffc98b3 @ fffc98b3 (14 bytes)

void FUN_fffc98b3(void)

{
  PTR_g_ui_00025d60->menu_state = 0;
  return;
}


// ===== FUN_fffc98c1 @ fffc98c1 (56 bytes)

undefined1 FUN_fffc98c1(void)

{
  undefined1 uVar1;
  
  if ((PTR_g_ui_00025d60->menu_p1 == 4) && (DAT_00015e04 == '\x02')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== menu_page_serialize @ fffc98f9 (626 bytes)

/* WARNING: Removing unreachable block (ram,0xfffc99cf) */
/* WARNING: Removing unreachable block (ram,0xfffc98f9) */
/* WARNING: Removing unreachable block (ram,0xfffc99f2) */
/* WARNING: Removing unreachable block (ram,0xfffc9b68) */
/* Build the menu page for the DISPLAY (P1 title, P2 tabs, 5 rows of name+value) into frame 0x1741
   at +0x98 */

void menu_page_serialize(int param_1,ushort param_2)

{
  undefined1 uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  byte bStack_1e;
  byte bStack_1d;
  byte *pbStack_1c;
  byte bStack_18;
  char cStack_17;
  byte bStack_16;
  byte bStack_15;
  ushort uStack_14;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  ushort local_e;
  byte bStack_b;
  ushort uStack_a;
  int iStack_8;
  
  uStack_a = param_2;
  iStack_8 = param_1;
  uVar1 = FUN_fffc98c1();
  *(undefined1 *)((uint)param_2 + param_1) = uVar1;
  uStack_a = uStack_a + 1;
  DAT_0001226e = (&DAT_00015e00)[PTR_g_ui_00025d60->menu_p1];
  PTR_g_ui_00025d60->menu_p2 = (&DAT_00015e00)[PTR_g_ui_00025d60->menu_p1];
  bStack_10 = menu_p2_global(PTR_g_ui_00025d60->menu_p1,PTR_g_ui_00025d60->menu_p2);
  bStack_b = menu_count_items(bStack_10);
  if (bStack_b != 0) {
    *(byte *)((uint)uStack_a + iStack_8) = bStack_b;
    uStack_a = uStack_a + 1;
    bStack_10 = menu_p2_global(PTR_g_ui_00025d60->menu_p1,PTR_g_ui_00025d60->menu_p2);
    pbStack_1c = (byte *)menu_cursor_of(bStack_10);
    DAT_0001226f = *pbStack_1c;
    DAT_00012270 = pbStack_1c[1];
    *(byte *)((uint)uStack_a + iStack_8) = DAT_00012270;
    if (5 < bStack_b) {
      bStack_b = 5;
    }
    *(byte *)((uint)(ushort)(uStack_a + 1) + iStack_8) =
         bStack_b << 4 | PTR_g_ui_00025d60->menu_state;
    *(byte *)((uint)(ushort)(uStack_a + 2) + iStack_8) = DAT_0001226e << 4 | DAT_0001226f;
    pcVar3 = "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
             + (uint)PTR_g_ui_00025d60->menu_p1 * 0x14;
    pcVar2 = (char *)(iStack_8 + (uint)(ushort)(uStack_a + 3));
    for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    uStack_a = uStack_a + 0x17;
    bStack_f = PTR_g_ui_00025d60->menu_p1;
    bStack_11 = 0;
    bStack_15 = menu_p1_range(bStack_f,&bStack_1d,&bStack_1e);
    if (bStack_15 != 0) {
      bStack_10 = bStack_1d;
      for (uStack_14 = (ushort)bStack_1d; uStack_14 <= bStack_1e; uStack_14 = uStack_14 + 1) {
        bStack_15 = menu_group_visible(bStack_f,bStack_10);
        if (bStack_15 == 1) {
          pcVar3 = "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
                   + (uint)bStack_10 * 0xd + 0x78;
          pcVar2 = (char *)(iStack_8 + (uint)uStack_a);
          for (iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
            *pcVar2 = *pcVar3;
            pcVar2 = pcVar2 + 1;
            pcVar3 = pcVar3 + 1;
          }
          uStack_a = uStack_a + 0xd;
          bStack_11 = bStack_11 + 1;
        }
        bStack_10 = bStack_10 + 1;
      }
      uStack_a = (8 - (ushort)bStack_11) * 0xd + uStack_a;
      bStack_10 = menu_p2_global(bStack_f,DAT_0001226e);
      for (local_e = 0; local_e < bStack_b; local_e = local_e + 1) {
        DAT_00012271 = 0;
        if ((PTR_g_ui_00025d60->menu_state == 3) && (local_e == DAT_0001226f)) {
          DAT_00012271 = 1;
        }
        bStack_18 = bStack_f;
        cStack_17 = bStack_10;
        bStack_16 = DAT_00012270;
        bStack_15 = menu_get_name((char *)&bStack_18,(char *)((uint)uStack_a + iStack_8 + 3));
        if (bStack_15 == 0) {
          return;
        }
        iVar4 = (uint)uStack_a + iStack_8;
        *(undefined4 *)(iVar4 + 0x28) = 0x20202020;
        *(undefined4 *)(iVar4 + 0x24) = 0x20202020;
        *(undefined4 *)(iVar4 + 0x20) = 0x20202020;
        *(undefined4 *)(iVar4 + 0x1c) = 0x20202020;
        *(undefined4 *)(iVar4 + 0x18) = 0x20202020;
        *(undefined1 *)(iVar4 + 0x2c) = 0x20;
        menu_call_draw((uint)&bStack_18,iStack_8 + (uint)uStack_a);
        uStack_a = uStack_a + 0x2d;
        DAT_00012270 = DAT_00012270 + 1;
      }
    }
  }
  return;
}


// ===== menu_ex010101_draw @ fffc9b6b (24 bytes)

/* Menu item ex010101 AF TREBLE GAIN: on_draw (#74) */

void menu_ex010101_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex010101_af_treble_gain);
  return;
}


// ===== menu_draw_flags @ fffc9b83 (95 bytes)

/* on_draw helper: row flag byte (bit7 if arg==0, bit6 if row being edited 0x12271) + value */

void menu_draw_flags(byte *param_1,char param_2)

{
  if (param_2 == '\0') {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 3;
  param_1[2] = 0;
  FUN_fff9c787((int)param_2,param_1 + 0x18);
  return;
}


// ===== menu_ex010102_draw @ fffc9be2 (24 bytes)

/* Menu item ex010102 AF MIDDLE TONE GAIN: on_draw (#74) */

void menu_ex010102_draw(byte *param_1)

{
  menu_draw_flags(param_1,g_opstate.ex010102_af_middle_tone_gain);
  return;
}

