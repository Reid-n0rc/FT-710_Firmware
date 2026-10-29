// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== FUN_fffc909f @ fffc909f (21 bytes)

void FUN_fffc909f(void)

{
  DAT_0001b4f2 = 1;
  swtimer_start(0x48,0x2ee);
  return;
}


// ===== FUN_fffc90b4 @ fffc90b4 (23 bytes)

void FUN_fffc90b4(void)

{
  DAT_0001b4f2 = 0;
  PTR_DAT_00025d5c[0x1c3] = 0;
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
  
  uVar1 = DAT_00080010;
  DAT_00080010 = uVar1 & 0xfffffdff;
  bVar2 = DAT_000c1280;
  DAT_000c1280 = bVar2 & 0xfb;
  bVar2 = DAT_000c1281;
  DAT_000c1281 = bVar2 & 0xfb;
  DAT_000c1400 = 0x40;
  DAT_000c140c = 0;
  DAT_000c1404 = 0;
  DAT_000c1402 = 0x30;
  DAT_000c1408 = 11999;
  DAT_000c140a = 0x726;
  DAT_0008c157 = 1;
  bVar2 = DAT_0008c062;
  DAT_0008c062 = bVar2 | 0x80;
  FUN_fffc91b2();
  return;
}


// ===== FUN_fffc91a2 @ fffc91a2 (8 bytes)

void FUN_fffc91a2(void)

{
  byte bVar1;
  
  bVar1 = DAT_000c1280;
  DAT_000c1280 = bVar1 | 4;
  return;
}


// ===== FUN_fffc91aa @ fffc91aa (8 bytes)

void FUN_fffc91aa(void)

{
  byte bVar1;
  
  bVar1 = DAT_000c1280;
  DAT_000c1280 = bVar1 & 0xfb;
  return;
}


// ===== FUN_fffc91b2 @ fffc91b2 (1 bytes)

void FUN_fffc91b2(void)

{
  return;
}


// ===== R_SCI6_Create_IIC @ fffc91b3 (213 bytes)

/* SCI6 in simple-I2C mode (SIMR3/SISR used) */

void R_SCI6_Create_IIC(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0xfdffffff;
  bVar2 = DAT_00087356;
  DAT_00087356 = bVar2 & 0xfa | 10;
  bVar2 = DAT_00087357;
  DAT_00087357 = bVar2 & 0xfa | 10;
  DAT_0008a0c2 = 0;
  DAT_0008a0cb = 0xf0;
  DAT_0008a0c0 = 0;
  bVar2 = DAT_0008a0c6;
  DAT_0008a0c6 = bVar2 & 0xfe;
  bVar2 = DAT_0008a0c6;
  DAT_0008a0c6 = bVar2 & 0xfb;
  bVar2 = DAT_0008a0c6;
  DAT_0008a0c6 = bVar2 | 8;
  DAT_0008a0c1 = 0x12;
  DAT_0008a0c7 = 0;
  bVar2 = DAT_0008a0c9;
  DAT_0008a0c9 = bVar2 | 1;
  bVar2 = DAT_0008a0ca;
  DAT_0008a0ca = bVar2 | 0x22;
  DAT_0008a0cd = 0;
  DAT_0008a0c2 = 0xf4;
  DAT_0008c141 = 10;
  bVar2 = DAT_0008c080;
  DAT_0008c080 = bVar2 | 4;
  bVar2 = DAT_0008c060;
  DAT_0008c060 = bVar2 | 2;
  DAT_0008c140 = 10;
  bVar2 = DAT_0008c080;
  DAT_0008c080 = bVar2 | 1;
  bVar2 = DAT_0008c060;
  DAT_0008c060 = bVar2 | 1;
  R_SCI6_Create_UserInit();
  return;
}


// ===== FUN_fffc9288 @ fffc9288 (64 bytes)

void FUN_fffc9288(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = UNK_00087057;
  UNK_00087057 = bVar1 & 0xfe;
  bVar1 = UNK_00087056;
  UNK_00087056 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 0x80;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x1000;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 | 0x40;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x2000;
  return;
}


// ===== FUN_fffc92c8 @ fffc92c8 (64 bytes)

void FUN_fffc92c8(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = UNK_00087057;
  UNK_00087057 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0x7f;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xffffefff;
  bVar1 = UNK_00087056;
  UNK_00087056 = bVar1 & 0xfe;
  bVar1 = DAT_0008720a;
  DAT_0008720a = bVar1 & 0xbf;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xffffdfff;
  return;
}


// ===== FUN_fffc9308 @ fffc9308 (9 bytes)

void FUN_fffc9308(void)

{
  DAT_0008a0cb = 0x51;
  return;
}


// ===== sci6_iic_condition @ fffc9311 (9 bytes)

/* Writes SIMR3 (start/stop condition generation) */

void sci6_iic_condition(void)

{
  DAT_0008a0cb = 0x54;
  return;
}


// ===== FUN_fffc931a @ fffc931a (64 bytes)

void FUN_fffc931a(undefined1 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    return;
  }
  DAT_00012235 = 0x80;
  DAT_00012236 = 0x80;
  DAT_00012237 = param_1;
  DAT_0001fa42 = (short)param_3;
  DAT_0002104c = param_2;
  FUN_fffc9308();
  return;
}


// ===== FUN_fffc935a @ fffc935a (73 bytes)

void FUN_fffc935a(undefined1 param_1,undefined4 param_2,int param_3)

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
  FUN_fffc9308();
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
  
  bVar2 = DAT_0008a0cc;
  if ((bVar2 & 1) == 1) {
    uVar1 = DAT_0008a0c5;
    *DAT_00021050 = uVar1;
    DAT_00021050 = DAT_00021050 + 1;
    DAT_0001fa44 = DAT_0001fa44 + 1;
  }
  DAT_00012236 = 0;
  sci6_iic_condition();
  return;
}


// ===== r_sci6_iic_tei @ fffc93ef (120 bytes)

/* TEI6 (cb 0x20), simple-I2C condition handling */

void r_sci6_iic_tei(void)

{
  byte bVar1;
  
  if (DAT_00012236 == -0x80) {
    bVar1 = DAT_0008a0cb;
    DAT_0008a0cb = bVar1 & 0xf7;
    bVar1 = DAT_0008a0cb;
    DAT_0008a0cb = bVar1 & 0x3f;
    bVar1 = DAT_0008a0cb;
    DAT_0008a0cb = bVar1 & 0xcf;
    DAT_0008a0c3 = DAT_00012237;
    return;
  }
  if (DAT_00012236 == '\0') {
    bVar1 = DAT_0008a0cb;
    DAT_0008a0cb = bVar1 & 0xf7;
    bVar1 = DAT_0008a0cb;
    DAT_0008a0cb = bVar1 | 0xf0;
    if (DAT_00012235 == -0x80) {
      FUN_fffc95af();
    }
    if (DAT_00012235 == '\0') {
      FUN_fffc95b0();
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
  
  bVar1 = DAT_0008a0cc;
  if ((bVar1 & 1) != 0) {
    DAT_00012236 = 0;
    sci6_iic_condition();
    return;
  }
  if (DAT_00012235 == -0x80) {
    if (DAT_0001fa42 != 0) {
      DAT_0008a0c3 = *DAT_0002104c;
      DAT_0002104c = DAT_0002104c + 1;
      DAT_0001fa42 = DAT_0001fa42 + -1;
      return;
    }
    DAT_00012236 = 0;
    sci6_iic_condition();
    return;
  }
  if (DAT_00012235 == '\0') {
    bVar1 = DAT_0008a0ca;
    if ((bVar1 & 0x20) == 0) {
      if (DAT_0001fa44 < DAT_0001fa46) {
        uVar2 = DAT_0008a0c5;
        *DAT_00021050 = uVar2;
        DAT_00021050 = DAT_00021050 + 1;
        DAT_0001fa44 = DAT_0001fa44 + 1;
      }
    }
    else {
      uVar2 = DAT_0008a0c5;
    }
    if (DAT_0001fa44 == 0) {
      if (DAT_0001fa46 == 1) {
        bVar1 = DAT_0008a0ca;
        DAT_0008a0ca = bVar1 | 0x20;
      }
      else {
        bVar1 = DAT_0008a0ca;
        DAT_0008a0ca = bVar1 & 0xdf;
        bVar1 = DAT_0008a0c2;
        DAT_0008a0c2 = bVar1 | 0x40;
      }
    }
    else if ((uint)DAT_0001fa46 == DAT_0001fa44 + 1) {
      bVar1 = DAT_0008a0ca;
      DAT_0008a0ca = bVar1 | 0x20;
    }
    DAT_0008a0c3 = 0xff;
    return;
  }
  return;
}


// ===== FUN_fffc95af @ fffc95af (1 bytes)

void FUN_fffc95af(void)

{
  return;
}


// ===== FUN_fffc95b0 @ fffc95b0 (1 bytes)

void FUN_fffc95b0(void)

{
  return;
}


// ===== R_SCI7_Create @ fffc95b1 (163 bytes)

/* SCI7 init ("C4" peripheral link, probably the RT685 DSP) */

void R_SCI7_Create(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = DAT_00080014;
  DAT_00080014 = uVar1 & 0xfeffffff;
  bVar2 = DAT_00087362;
  DAT_00087362 = bVar2 & 0xfa | 10;
  bVar2 = DAT_00087363;
  DAT_00087363 = bVar2 & 0xfa | 10;
  DAT_0008a0e2 = 0;
  DAT_0008a0e2 = 0;
  bVar2 = DAT_0008a0e9;
  DAT_0008a0e9 = bVar2 & 0xfe;
  DAT_0008a0ed = 0;
  DAT_0008a0e0 = 0;
  DAT_0008a0e6 = 0x72;
  DAT_0008a0e7 = 0;
  DAT_0008a0e1 = 0xc2;
  DAT_0008c18a = 10;
  bVar2 = DAT_0008c069;
  DAT_0008c069 = bVar2 | 4;
  DAT_0008c188 = 10;
  bVar2 = DAT_0008c029;
  DAT_0008c029 = bVar2 | 1;
  bVar2 = DAT_0008c009;
  DAT_0008c009 = bVar2 | 1;
  R_SCI7_Create_UserInit();
  return;
}


// ===== FUN_fffc9654 @ fffc9654 (64 bytes)

void FUN_fffc9654(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = UNK_00087063;
  UNK_00087063 = bVar1 & 0xfe;
  bVar1 = UNK_00087062;
  UNK_00087062 = bVar1 & 0xfe;
  bVar1 = UNK_0008720c;
  UNK_0008720c = bVar1 | 8;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x4000;
  bVar1 = UNK_0008720c;
  UNK_0008720c = bVar1 | 4;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 | 0x8000;
  return;
}


// ===== FUN_fffc9694 @ fffc9694 (104 bytes)

void FUN_fffc9694(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_0008c069;
  DAT_0008c069 = bVar1 & 0xfe;
  bVar1 = DAT_0008a0e2;
  DAT_0008a0e2 = bVar1 & 0xdf;
  bVar1 = DAT_0008a0e2;
  DAT_0008a0e2 = bVar1 & 0xef;
  bVar1 = DAT_0008a0e2;
  DAT_0008a0e2 = bVar1 & 0x7f;
  bVar1 = DAT_0008a0e2;
  DAT_0008a0e2 = bVar1 & 0xbf;
  bVar1 = UNK_0008720c;
  UNK_0008720c = bVar1 & 0xf7;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xffffbfff;
  bVar1 = UNK_00087063;
  UNK_00087063 = bVar1 & 0xfe;
  bVar1 = UNK_0008720c;
  UNK_0008720c = bVar1 & 0xfb;
  uVar2 = DAT_00087670;
  DAT_00087670 = uVar2 & 0xffff7fff;
  bVar1 = UNK_00087062;
  UNK_00087062 = bVar1 & 0xfe;
  return;
}


// ===== FUN_fffc96fc @ fffc96fc (68 bytes)

undefined2 FUN_fffc96fc(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 uStack_a;
  
  uStack_a = 0;
  if (param_2 == 0) {
    uStack_a = 0x81;
  }
  else {
    DAT_0001fa4a = 0;
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 | 0x40;
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 | 0x10;
    DAT_0001fa4c = param_2;
    DAT_00021058 = param_1;
  }
  return uStack_a;
}


// ===== FUN_fffc9740 @ fffc9740 (95 bytes)

undefined2 FUN_fffc9740(undefined4 param_1,short param_2)

{
  byte bVar1;
  undefined2 uStack_a;
  
  uStack_a = 0;
  if (param_2 == 0) {
    uStack_a = 0x81;
  }
  else {
    bVar1 = UNK_0008720c;
    if ((bVar1 & 8) == 0) {
      uStack_a = 0x80;
    }
    else {
      bVar1 = UNK_0008720c;
      UNK_0008720c = bVar1 & 0xf7;
      bVar1 = DAT_0008a0e2;
      DAT_0008a0e2 = bVar1 | 0xa0;
      bVar1 = DAT_0008c069;
      DAT_0008c069 = bVar1 | 1;
      bVar1 = UNK_0008720c;
      UNK_0008720c = bVar1 | 8;
      DAT_0001fa48 = param_2;
      DAT_00021054 = param_1;
    }
  }
  return uStack_a;
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
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 & 0x7f;
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 | 4;
    return;
  }
  DAT_0008a0e3 = *DAT_00021054;
  DAT_00021054 = DAT_00021054 + 1;
  DAT_0001fa48 = DAT_0001fa48 + -1;
  return;
}


// ===== r_sci7_transmitend_interrupt @ fffc97ec (37 bytes)

/* TEI7 (cb 0x22) */

void r_sci7_transmitend_interrupt(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008c069;
  DAT_0008c069 = bVar1 & 0xfe;
  bVar1 = DAT_0008a0e2;
  DAT_0008a0e2 = bVar1 & 0x7f;
  bVar1 = DAT_0008a0e2;
  DAT_0008a0e2 = bVar1 & 0xdf;
  bVar1 = DAT_0008a0e2;
  DAT_0008a0e2 = bVar1 & 0xfb;
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
    uVar2 = DAT_0008a0e5;
    *DAT_00021058 = uVar2;
    DAT_00021058 = DAT_00021058 + 1;
    DAT_0001fa4a = DAT_0001fa4a + 1;
  }
  if (DAT_0001fa4c <= DAT_0001fa4a) {
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 & 0xbf;
    bVar1 = DAT_0008a0e2;
    DAT_0008a0e2 = bVar1 & 0xef;
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
  bVar1 = DAT_0008a0e4;
  DAT_0008a0e4 = bVar1 & 199 | 0xc0;
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
  PTR_DAT_00025d60[0x3ff] = 0;
  return;
}


// ===== FUN_fffc98c1 @ fffc98c1 (56 bytes)

undefined1 FUN_fffc98c1(void)

{
  undefined1 uVar1;
  
  if ((PTR_DAT_00025d60[0x41f] == '\x04') && (DAT_00015e04 == '\x02')) {
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
  char cStack_18;
  char cStack_17;
  byte bStack_16;
  byte bStack_15;
  ushort uStack_14;
  byte bStack_11;
  byte bStack_10;
  char cStack_f;
  ushort local_e;
  byte bStack_b;
  ushort uStack_a;
  int iStack_8;
  
  uStack_a = param_2;
  iStack_8 = param_1;
  uVar1 = FUN_fffc98c1();
  *(undefined1 *)((uint)param_2 + param_1) = uVar1;
  uStack_a = uStack_a + 1;
  DAT_0001226e = (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]];
  PTR_DAT_00025d60[0x420] = (&DAT_00015e00)[(byte)PTR_DAT_00025d60[0x41f]];
  bStack_10 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
  bStack_b = menu_count_items(bStack_10);
  if (bStack_b != 0) {
    *(byte *)((uint)uStack_a + iStack_8) = bStack_b;
    uStack_a = uStack_a + 1;
    bStack_10 = menu_p2_global(PTR_DAT_00025d60[0x41f],PTR_DAT_00025d60[0x420]);
    pbStack_1c = (byte *)menu_cursor_of(bStack_10);
    DAT_0001226f = *pbStack_1c;
    DAT_00012270 = pbStack_1c[1];
    *(byte *)((uint)uStack_a + iStack_8) = DAT_00012270;
    if (5 < bStack_b) {
      bStack_b = 5;
    }
    *(byte *)((uint)(ushort)(uStack_a + 1) + iStack_8) = bStack_b << 4 | PTR_DAT_00025d60[0x3ff];
    *(byte *)((uint)(ushort)(uStack_a + 2) + iStack_8) = DAT_0001226e << 4 | DAT_0001226f;
    pcVar3 = "RADIO SETTING       CW SETTING          OPERATION SETTING   DISPLAY SETTING     EXTENSION SETTING   PRESET              MODE SSB     MODE AM      MODE FM      MODE PSK/DATAMODE RTTY    MODE CW      KEYER        GENERAL      RX DSP       TX AUDIO     TX GENERAL   TUNING       DISPLAY      SCOPE        VFO IND COLOREXT MONITOR  DATE&TIME    SD CARD      SOFT VERSION CALIBRATION  RESET        CERTIFICATIONPRESET1      PRESET2      PRESET3      PRESET4      PRESET5      6dB/oct              18dB/oct              50-3050Hz           100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz            50-4000Hz           TTBF                 100-2900Hz           200-2800Hz           300-2700Hz           400-2600Hz           MIC                  USB                  REAR                 AUTO                 OFF                  RTS                  DTR                  DAKY                 300Hz                400Hz                600Hz                850Hz                1100Hz               1200Hz               1500Hz               1650Hz               1800Hz               1950Hz               2100Hz               2250Hz               2400Hz               2450Hz               2500Hz               2600Hz               2700Hz               2800Hz               2900Hz               3000Hz               3200Hz               3500Hz               4000Hz               50Hz                 100Hz                150Hz                200Hz                250Hz                300Hz                350Hz                400Hz                450Hz                500Hz                600Hz                800Hz                1200Hz               1400Hz               1700Hz               2000Hz               2400Hz               3000Hz               3200Hz               3500Hz               4000Hz               OFF                  50M                  ON                   -                    SIMP                 +                    OFF                  ENC                  TSQ                  67.0                 69..." /* TRUNCATED STRING LITERAL */
             + (uint)(byte)PTR_DAT_00025d60[0x41f] * 0x14;
    pcVar2 = (char *)(iStack_8 + (uint)(ushort)(uStack_a + 3));
    for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    uStack_a = uStack_a + 0x17;
    cStack_f = PTR_DAT_00025d60[0x41f];
    bStack_11 = 0;
    bStack_15 = menu_p1_range(cStack_f,&bStack_1d,&bStack_1e);
    if (bStack_15 != 0) {
      bStack_10 = bStack_1d;
      for (uStack_14 = (ushort)bStack_1d; uStack_14 <= bStack_1e; uStack_14 = uStack_14 + 1) {
        bStack_15 = menu_group_visible(cStack_f,bStack_10);
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
      bStack_10 = menu_p2_global(cStack_f,DAT_0001226e);
      for (local_e = 0; local_e < bStack_b; local_e = local_e + 1) {
        DAT_00012271 = 0;
        if ((PTR_DAT_00025d60[0x3ff] == '\x03') && (local_e == DAT_0001226f)) {
          DAT_00012271 = 1;
        }
        cStack_18 = cStack_f;
        cStack_17 = bStack_10;
        bStack_16 = DAT_00012270;
        bStack_15 = menu_get_name(&cStack_18,(char *)((uint)uStack_a + iStack_8 + 3));
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
        menu_call_draw((uint)&cStack_18,iStack_8 + (uint)uStack_a);
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
  menu_draw_flags(param_1,DAT_00009a2a);
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
  menu_draw_flags(param_1,DAT_00009a2b);
  return;
}


// ===== menu_ex010103_draw @ fffc9bfa (24 bytes)

/* Menu item ex010103 AF BASS GAIN: on_draw (#74) */

void menu_ex010103_draw(byte *param_1)

{
  menu_draw_flags(param_1,DAT_00009a2c);
  return;
}


// ===== menu_ex010104_draw @ fffc9c12 (23 bytes)

/* Menu item ex010104 AGC FAST DELAY: on_draw (#74) */

void menu_ex010104_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a2d,300,param_4,param_5,param_1);
  return;
}


// ===== FUN_fffc9c29 @ fffc9c29 (130 bytes)

void FUN_fffc9c29(byte *param_1,byte param_2,short param_3)

{
  byte bVar1;
  short sVar2;
  
  sVar2 = (ushort)param_2 * 0x14 + 0x14;
  if (sVar2 == param_3) {
    *param_1 = *param_1 | 0x80;
  }
  if (DAT_00012271 == '\x01') {
    *param_1 = *param_1 | 0x40;
  }
  param_1[1] = 8;
  param_1[2] = 0;
  bVar1 = FUN_fff9c843(sVar2,param_1 + 0x18);
  param_1 = param_1 + bVar1 + 0x18;
  param_1[0] = 0x6d;
  param_1[1] = 0x73;
  param_1[2] = 0x65;
  param_1[3] = 99;
  return;
}


// ===== menu_ex010105_draw @ fffc9cab (23 bytes)

/* Menu item ex010105 AGC MID DELAY: on_draw (#74) */

void menu_ex010105_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a2e,1000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010106_draw @ fffc9cc2 (23 bytes)

/* Menu item ex010106 AGC SLOW DELY: on_draw (#74) */

void menu_ex010106_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9c29(param_1,DAT_00009a2f,3000,param_4,param_5,param_1);
  return;
}


// ===== menu_ex010107_draw @ fffc9cd9 (21 bytes)

/* Menu item ex010107 LCUT FREQ: on_draw (#74) */

void menu_ex010107_draw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  FUN_fffc9cee(param_1,DAT_00009a30,1,param_4,param_5,param_1);
  return;
}

